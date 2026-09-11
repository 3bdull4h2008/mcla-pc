#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_824CAF00) {
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
	// bl 0x824c7c48
	ctx.lr = 0x824CAF20;
	sub_824C7C48(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824caf38
	if (cr6.eq) goto loc_824CAF38;
	// bl 0x82130588
	ctx.lr = 0x824CAF34;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CAF38:
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

PPC_WEAK_FUNC(sub_824CAF00) {
	__imp__sub_824CAF00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CAF50) {
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
	ctx.lr = 0x824CAF58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r29,-1
	r29.s64 = -1;
	// addi r8,r10,14364
	ctx.r8.s64 = ctx.r10.s64 + 14364;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// stb r6,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r6.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// bl 0x824e71c8
	ctx.lr = 0x824CAFB0;
	sub_824E71C8(ctx, base);
	// stw r29,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r29.u32);
	// stw r29,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r29.u32);
	// addi r3,r31,156
	ctx.r3.s64 = r31.s64 + 156;
	// stw r29,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r29.u32);
	// stw r30,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r30.u32);
	// stw r30,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r30.u32);
	// bl 0x824e8de8
	ctx.lr = 0x824CAFCC;
	sub_824E8DE8(ctx, base);
	// stw r30,672(r31)
	PPC_STORE_U32(r31.u32 + 672, r30.u32);
	// stw r30,676(r31)
	PPC_STORE_U32(r31.u32 + 676, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CAF50) {
	__imp__sub_824CAF50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CAFE0) {
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
	// addi r10,r11,14364
	ctx.r10.s64 = r11.s64 + 14364;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82482008
	ctx.lr = 0x824CB00C;
	sub_82482008(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cb024
	if (cr6.eq) goto loc_824CB024;
	// bl 0x82130588
	ctx.lr = 0x824CB020;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CB024:
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

PPC_WEAK_FUNC(sub_824CAFE0) {
	__imp__sub_824CAFE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB03C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB03C) {
	__imp__sub_824CB03C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB040) {
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
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// addi r10,r11,14420
	ctx.r10.s64 = r11.s64 + 14420;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x824c7c48
	ctx.lr = 0x824CB070;
	sub_824C7C48(ctx, base);
	// addi r3,r31,1184
	ctx.r3.s64 = r31.s64 + 1184;
	// bl 0x82130000
	ctx.lr = 0x824CB078;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82482008
	ctx.lr = 0x824CB080;
	sub_82482008(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cb098
	if (cr6.eq) goto loc_824CB098;
	// bl 0x82130588
	ctx.lr = 0x824CB094;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CB098:
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

PPC_WEAK_FUNC(sub_824CB040) {
	__imp__sub_824CB040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB0B0) {
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
	ctx.lr = 0x824CB0B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// addi r7,r9,14556
	ctx.r7.s64 = ctx.r9.s64 + 14556;
	// lbz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r8,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r8.u8);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lbz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// stb r5,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r5.u8);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// bl 0x8252ad00
	ctx.lr = 0x824CB108;
	sub_8252AD00(ctx, base);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// addi r29,r11,4
	r29.s64 = r11.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6310
	ctx.lr = 0x824CB118;
	sub_824E6310(ctx, base);
	// li r30,-1
	r30.s64 = -1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// bl 0x824e6310
	ctx.lr = 0x824CB128;
	sub_824E6310(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r4.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CB0B0) {
	__imp__sub_824CB0B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB140) {
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
	// bl 0x82482008
	ctx.lr = 0x824CB160;
	sub_82482008(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb178
	if (cr6.eq) goto loc_824CB178;
	// bl 0x82130588
	ctx.lr = 0x824CB174;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CB178:
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

PPC_WEAK_FUNC(sub_824CB140) {
	__imp__sub_824CB140(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	ctx.lr = 0x824CB198;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r26,1
	r26.s64 = 1;
	// li r27,2
	r27.s64 = 2;
	// li r29,3
	r29.s64 = 3;
loc_824CB1B0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x824cb2d4
	if (cr6.gt) goto loc_824CB2D4;
	// lis r12,-32179
	r12.s64 = -2108882944;
	// addi r12,r12,-20012
	r12.s64 = r12.s64 + -20012;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-19996(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -19996);
	// lwz r18,-19960(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -19960);
	// lwz r18,-19884(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -19884);
	// lwz r18,-19820(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -19820);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252d388
	ctx.lr = 0x824CB1F4;
	sub_8252D388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb24c
	if (cr6.eq) goto loc_824CB24C;
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// b 0x824cb2d4
	goto loc_824CB2D4;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cb244
	if (!cr6.eq) goto loc_824CB244;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481588
	ctx.lr = 0x824CB21C;
	sub_82481588(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb2bc
	if (cr6.eq) goto loc_824CB2BC;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481590
	ctx.lr = 0x824CB230;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cb2bc
	if (!cr6.eq) goto loc_824CB2BC;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// b 0x824cb2d4
	goto loc_824CB2D4;
loc_824CB244:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cb2d4
	if (cr6.eq) goto loc_824CB2D4;
loc_824CB24C:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x824cb2c0
	goto loc_824CB2C0;
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824c9310
	ctx.lr = 0x824CB26C;
	sub_824C9310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb2bc
	if (cr6.eq) goto loc_824CB2BC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CB28C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// b 0x824cb2d4
	goto loc_824CB2D4;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cb2bc
	if (!cr6.eq) goto loc_824CB2BC;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CB2B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cb2d4
	goto loc_824CB2D4;
loc_824CB2BC:
	// li r4,1
	ctx.r4.s64 = 1;
loc_824CB2C0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CB2D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CB2D4:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cb2f4
	if (cr6.eq) goto loc_824CB2F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CB2E8;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cb1b0
	if (!cr6.eq) goto loc_824CB1B0;
loc_824CB2F4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CB190) {
	__imp__sub_824CB190(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB2FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB2FC) {
	__imp__sub_824CB2FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB300) {
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
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// addi r8,r10,14580
	ctx.r8.s64 = ctx.r10.s64 + 14580;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stb r6,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r6.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x824e8de8
	ctx.lr = 0x824CB358;
	sub_824E8DE8(ctx, base);
	// stw r30,544(r31)
	PPC_STORE_U32(r31.u32 + 544, r30.u32);
	// stw r30,548(r31)
	PPC_STORE_U32(r31.u32 + 548, r30.u32);
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

PPC_WEAK_FUNC(sub_824CB300) {
	__imp__sub_824CB300(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB37C) {
	__imp__sub_824CB37C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB380) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// addi r7,r9,14488
	ctx.r7.s64 = ctx.r9.s64 + 14488;
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// lbz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// stb r5,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r5.u8);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824CB380) {
	__imp__sub_824CB380(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB3CC) {
	__imp__sub_824CB3CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB3D0) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,14488
	ctx.r10.s64 = r11.s64 + 14488;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824cb41c
	if (cr6.eq) goto loc_824CB41C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824CB41C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CB41C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82482008
	ctx.lr = 0x824CB424;
	sub_82482008(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb43c
	if (cr6.eq) goto loc_824CB43C;
	// bl 0x82130588
	ctx.lr = 0x824CB438;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CB43C:
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

PPC_WEAK_FUNC(sub_824CB3D0) {
	__imp__sub_824CB3D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB454) {
	__imp__sub_824CB454(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB458) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// addi r7,r9,14604
	ctx.r7.s64 = ctx.r9.s64 + 14604;
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// lbz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// stb r5,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r5.u8);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// lbz r4,36(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 36);
	// ori r11,r4,192
	r11.u64 = ctx.r4.u64 | 192;
	// stb r11,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824CB458) {
	__imp__sub_824CB458(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB4A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// addi r7,r9,14628
	ctx.r7.s64 = ctx.r9.s64 + 14628;
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// lbz r6,24(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// stb r5,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r5.u8);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// lbz r4,44(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 44);
	// ori r10,r4,128
	ctx.r10.u64 = ctx.r4.u64 | 128;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stb r10,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824CB4A8) {
	__imp__sub_824CB4A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB500) {
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
	ctx.lr = 0x824CB508;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82618c90
	ctx.lr = 0x824CB51C;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb538
	if (cr6.eq) goto loc_824CB538;
	// ld r11,0(r31)
	r11.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cb53c
	if (!cr6.eq) goto loc_824CB53C;
loc_824CB538:
	// li r11,0
	r11.s64 = 0;
loc_824CB53C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb634
	if (cr6.eq) goto loc_824CB634;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,8
	ctx.r4.s64 = r31.s64 + 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x824CB558;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb634
	if (cr6.eq) goto loc_824CB634;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r31,12
	ctx.r4.s64 = r31.s64 + 12;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x824CB574;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb634
	if (cr6.eq) goto loc_824CB634;
	// addi r29,r31,16
	r29.s64 = r31.s64 + 16;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x824CB594;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb634
	if (cr6.eq) goto loc_824CB634;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,512
	cr6.compare<uint32_t>(r11.u32, 512, xer);
	// bgt cr6,0x824cb634
	if (cr6.gt) goto loc_824CB634;
	// addi r28,r31,20
	r28.s64 = r31.s64 + 20;
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257568
	ctx.lr = 0x824CB5C0;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb634
	if (cr6.eq) goto loc_824CB634;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,512
	cr6.compare<uint32_t>(r11.u32, 512, xer);
	// bgt cr6,0x824cb634
	if (cr6.gt) goto loc_824CB634;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824cb5f4
	if (cr6.eq) goto loc_824CB5F4;
	// addi r4,r31,24
	ctx.r4.s64 = r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x824CB5F0;
	sub_82618F80(ctx, base);
	// b 0x824cb5f8
	goto loc_824CB5F8;
loc_824CB5F4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_824CB5F8:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb634
	if (cr6.eq) goto loc_824CB634;
	// lwz r5,0(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824cb620
	if (cr6.eq) goto loc_824CB620;
	// addi r4,r31,536
	ctx.r4.s64 = r31.s64 + 536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f80
	ctx.lr = 0x824CB61C;
	sub_82618F80(ctx, base);
	// b 0x824cb624
	goto loc_824CB624;
loc_824CB620:
	// li r3,1
	ctx.r3.s64 = 1;
loc_824CB624:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cb638
	if (!cr6.eq) goto loc_824CB638;
loc_824CB634:
	// li r11,0
	r11.s64 = 0;
loc_824CB638:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CB500) {
	__imp__sub_824CB500(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB644) {
	__imp__sub_824CB644(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB648) {
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
	ctx.lr = 0x824CB650;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82618c90
	ctx.lr = 0x824CB664;
	sub_82618C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb680
	if (cr6.eq) goto loc_824CB680;
	// ld r11,0(r30)
	r11.u64 = PPC_LOAD_U64(r30.u32 + 0);
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cb684
	if (!cr6.eq) goto loc_824CB684;
loc_824CB680:
	// li r11,0
	r11.s64 = 0;
loc_824CB684:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb6ac
	if (cr6.eq) goto loc_824CB6AC;
	// addi r4,r30,44
	ctx.r4.s64 = r30.s64 + 44;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618f10
	ctx.lr = 0x824CB69C;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cb6b0
	if (!cr6.eq) goto loc_824CB6B0;
loc_824CB6AC:
	// li r11,0
	r11.s64 = 0;
loc_824CB6B0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cb71c
	if (cr6.eq) goto loc_824CB71C;
	// lbz r11,44(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb71c
	if (cr6.eq) goto loc_824CB71C;
	// addi r29,r30,40
	r29.s64 = r30.s64 + 40;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82257568
	ctx.lr = 0x824CB6DC;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb71c
	if (cr6.eq) goto loc_824CB71C;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
loc_824CB6F0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x824cb71c
	if (!cr6.lt) goto loc_824CB71C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824fa278
	ctx.lr = 0x824CB708;
	sub_824FA278(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cb6f0
	if (!cr6.eq) goto loc_824CB6F0;
loc_824CB71C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CB648) {
	__imp__sub_824CB648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB724) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB724) {
	__imp__sub_824CB724(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB728) {
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
	ctx.lr = 0x824CB730;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22380
	ctx.r10.s64 = r11.s64 + 22380;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// bl 0x824c6830
	ctx.lr = 0x824CB76C;
	sub_824C6830(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cb7ac
	if (cr6.eq) goto loc_824CB7AC;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c5f10
	ctx.lr = 0x824CB79C;
	sub_824C5F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cb7b0
	if (!cr6.eq) goto loc_824CB7B0;
loc_824CB7AC:
	// li r11,0
	r11.s64 = 0;
loc_824CB7B0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CB728) {
	__imp__sub_824CB728(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB7BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB7BC) {
	__imp__sub_824CB7BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB7C0) {
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
	ctx.lr = 0x824CB7C8;
	// stwu r1,-1152(r1)
	ea = -1152 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22380
	ctx.r10.s64 = r11.s64 + 22380;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r26,r9
	r26.u64 = ctx.r9.u64;
	// bl 0x824c6830
	ctx.lr = 0x824CB804;
	sub_824C6830(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cb844
	if (cr6.eq) goto loc_824CB844;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c5e48
	ctx.lr = 0x824CB834;
	sub_824C5E48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cb848
	if (!cr6.eq) goto loc_824CB848;
loc_824CB844:
	// li r11,0
	r11.s64 = 0;
loc_824CB848:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1152
	ctx.r1.s64 = ctx.r1.s64 + 1152;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CB7C0) {
	__imp__sub_824CB7C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB854) {
	__imp__sub_824CB854(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB858) {
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
	ctx.lr = 0x824CB860;
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
	ctx.lr = 0x824CB884;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x824CB890;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x824CB8A0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824cb8c4
	if (cr6.eq) goto loc_824CB8C4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82483018
	ctx.lr = 0x824CB8B4;
	sub_82483018(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cb8c8
	if (!cr6.eq) goto loc_824CB8C8;
loc_824CB8C4:
	// li r30,0
	r30.s64 = 0;
loc_824CB8C8:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824cb900
	if (cr6.eq) goto loc_824CB900;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb8f8
	if (cr6.eq) goto loc_824CB8F8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x824CB8E4;
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
loc_824CB8F8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_824CB900:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CB858) {
	__imp__sub_824CB858(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB90C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CB90C) {
	__imp__sub_824CB90C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB910) {
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
	ctx.lr = 0x824CB918;
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
	ctx.lr = 0x824CB948;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824CB954;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824CB964;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824cb994
	if (cr6.eq) goto loc_824CB994;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824cb994
	if (!cr6.eq) goto loc_824CB994;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824cb500
	ctx.lr = 0x824CB984;
	sub_824CB500(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cb998
	if (!cr6.eq) goto loc_824CB998;
loc_824CB994:
	// li r31,0
	r31.s64 = 0;
loc_824CB998:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824cb9c4
	if (cr6.eq) goto loc_824CB9C4;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb9bc
	if (cr6.eq) goto loc_824CB9BC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824CB9B4;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824cb9c0
	goto loc_824CB9C0;
loc_824CB9BC:
	// li r11,0
	r11.s64 = 0;
loc_824CB9C0:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824CB9C4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cb9e8
	if (cr6.eq) goto loc_824CB9E8;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824CB9D8;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824cb9ec
	if (cr6.eq) goto loc_824CB9EC;
loc_824CB9E8:
	// li r11,0
	r11.s64 = 0;
loc_824CB9EC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CB910) {
	__imp__sub_824CB910(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CB9F8) {
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
	ctx.lr = 0x824CBA00;
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
	ctx.lr = 0x824CBA30;
	sub_82257678(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x824CBA3C;
	sub_82618750(ctx, base);
	// subf r5,r30,r29
	ctx.r5.s64 = r29.s64 - r30.s64;
	// add r4,r30,r31
	ctx.r4.u64 = r30.u64 + r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x824CBA4C;
	sub_826185E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824cba7c
	if (cr6.eq) goto loc_824CBA7C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// bne cr6,0x824cba7c
	if (!cr6.eq) goto loc_824CBA7C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824cb648
	ctx.lr = 0x824CBA6C;
	sub_824CB648(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cba80
	if (!cr6.eq) goto loc_824CBA80;
loc_824CBA7C:
	// li r31,0
	r31.s64 = 0;
loc_824CBA80:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824cbaac
	if (cr6.eq) goto loc_824CBAAC;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cbaa4
	if (cr6.eq) goto loc_824CBAA4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824CBA9C;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// b 0x824cbaa8
	goto loc_824CBAA8;
loc_824CBAA4:
	// li r11,0
	r11.s64 = 0;
loc_824CBAA8:
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_824CBAAC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cbad0
	if (cr6.eq) goto loc_824CBAD0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x824CBAC0;
	sub_826186B0(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824cbad4
	if (cr6.eq) goto loc_824CBAD4;
loc_824CBAD0:
	// li r11,0
	r11.s64 = 0;
loc_824CBAD4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CB9F8) {
	__imp__sub_824CB9F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CBAE0) {
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
	ctx.lr = 0x824CBAE8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r29,r11,22584
	r29.s64 = r11.s64 + 22584;
	// li r28,0
	r28.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_824CBB04:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82501a88
	ctx.lr = 0x824CBB10;
	sub_82501A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cbb34
	if (!cr6.eq) goto loc_824CBB34;
	// addi r31,r31,112
	r31.s64 = r31.s64 + 112;
	// addi r11,r29,7168
	r11.s64 = r29.s64 + 7168;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x824cbb04
	if (cr6.lt) goto loc_824CBB04;
	// b 0x824cbbe8
	goto loc_824CBBE8;
loc_824CBB34:
	// cmpwi cr6,r30,63
	cr6.compare<int32_t>(r30.s32, 63, xer);
	// bge cr6,0x824cbbe4
	if (!cr6.lt) goto loc_824CBBE4;
	// mulli r11,r30,112
	r11.s64 = r30.s64 * 112;
	// addi r10,r29,44
	ctx.r10.s64 = r29.s64 + 44;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_824CBB48:
	// addi r10,r11,68
	ctx.r10.s64 = r11.s64 + 68;
	// addi r9,r11,-44
	ctx.r9.s64 = r11.s64 + -44;
	// li r8,9
	ctx.r8.s64 = 9;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_824CBB58:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x824cbb58
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CBB58;
	// lwz r8,104(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// addi r10,r11,116
	ctx.r10.s64 = r11.s64 + 116;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// stw r8,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r8.u32);
	// li r8,9
	ctx.r8.s64 = 9;
	// lwz r6,108(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// stw r6,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r6.u32);
	// lwz r5,112(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_824CBB98:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x824cbb98
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CBB98;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// addi r9,r29,7100
	ctx.r9.s64 = r29.s64 + 7100;
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// lwz r8,156(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 156);
	// stw r8,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r8.u32);
	// lwz r6,160(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// stw r6,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r6.u32);
	// lwz r5,172(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// stw r5,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r5.u32);
	// lwz r4,176(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// stw r4,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r4.u32);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// blt cr6,0x824cbb48
	if (cr6.lt) goto loc_824CBB48;
loc_824CBBE4:
	// li r28,1
	r28.s64 = 1;
loc_824CBBE8:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cbc94
	if (!cr6.eq) goto loc_824CBC94;
	// addi r11,r29,44
	r11.s64 = r29.s64 + 44;
loc_824CBBF8:
	// addi r10,r11,68
	ctx.r10.s64 = r11.s64 + 68;
	// addi r9,r11,-44
	ctx.r9.s64 = r11.s64 + -44;
	// li r8,9
	ctx.r8.s64 = 9;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_824CBC08:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x824cbc08
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CBC08;
	// lwz r8,104(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// addi r10,r11,116
	ctx.r10.s64 = r11.s64 + 116;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// stw r8,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r8.u32);
	// li r8,9
	ctx.r8.s64 = 9;
	// lwz r6,108(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// stw r6,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r6.u32);
	// lwz r5,112(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// stw r5,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r5.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_824CBC48:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x824cbc48
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CBC48;
	// lwz r10,152(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 152);
	// addi r9,r29,7100
	ctx.r9.s64 = r29.s64 + 7100;
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// stw r10,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r10.u32);
	// lwz r8,156(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 156);
	// stw r8,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r8.u32);
	// lwz r6,160(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// stw r6,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r6.u32);
	// lwz r5,172(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// stw r5,60(r11)
	PPC_STORE_U32(r11.u32 + 60, ctx.r5.u32);
	// lwz r4,176(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// stw r4,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r4.u32);
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// blt cr6,0x824cbbf8
	if (cr6.lt) goto loc_824CBBF8;
loc_824CBC94:
	// addi r10,r29,7056
	ctx.r10.s64 = r29.s64 + 7056;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r9,9
	ctx.r9.s64 = 9;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824CBCA4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824cbca4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CBCA4;
	// ld r9,36(r27)
	ctx.r9.u64 = PPC_LOAD_U64(r27.u32 + 36);
	// addi r7,r29,7104
	ctx.r7.s64 = r29.s64 + 7104;
	// addi r11,r27,36
	r11.s64 = r27.s64 + 36;
	// li r8,9
	ctx.r8.s64 = 9;
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
	// std r9,7092(r29)
	PPC_STORE_U64(r29.u32 + 7092, ctx.r9.u64);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// lwz r7,44(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// stw r7,7100(r29)
	PPC_STORE_U32(r29.u32 + 7100, ctx.r7.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_824CBCE0:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x824cbce0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CBCE0;
	// ld r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U64(r11.u32 + 48);
	// std r10,7140(r29)
	PPC_STORE_U64(r29.u32 + 7140, ctx.r10.u64);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// stw r10,7148(r29)
	PPC_STORE_U32(r29.u32 + 7148, ctx.r10.u32);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// stw r10,7160(r29)
	PPC_STORE_U32(r29.u32 + 7160, ctx.r10.u32);
	// lwz r11,72(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// stw r11,7164(r29)
	PPC_STORE_U32(r29.u32 + 7164, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CBAE0) {
	__imp__sub_824CBAE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CBD1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CBD1C) {
	__imp__sub_824CBD1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CBD20) {
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
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// addi r8,r10,13952
	ctx.r8.s64 = ctx.r10.s64 + 13952;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stb r6,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r6.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x824e1c10
	ctx.lr = 0x824CBD78;
	sub_824E1C10(ctx, base);
	// addi r3,r31,592
	ctx.r3.s64 = r31.s64 + 592;
	// bl 0x824f99c0
	ctx.lr = 0x824CBD80;
	sub_824F99C0(ctx, base);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// bl 0x824e6400
	ctx.lr = 0x824CBD88;
	sub_824E6400(ctx, base);
	// addi r3,r31,700
	ctx.r3.s64 = r31.s64 + 700;
	// bl 0x8252f1a8
	ctx.lr = 0x824CBD90;
	sub_8252F1A8(ctx, base);
	// li r5,-1
	ctx.r5.s64 = -1;
	// stw r30,780(r31)
	PPC_STORE_U32(r31.u32 + 780, r30.u32);
	// addi r3,r31,784
	ctx.r3.s64 = r31.s64 + 784;
	// stw r5,776(r31)
	PPC_STORE_U32(r31.u32 + 776, ctx.r5.u32);
	// bl 0x824e6310
	ctx.lr = 0x824CBDA4;
	sub_824E6310(ctx, base);
	// lis r4,-32179
	ctx.r4.s64 = -2108882944;
	// stw r30,700(r31)
	PPC_STORE_U32(r31.u32 + 700, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r11,r4,-23144
	r11.s64 = ctx.r4.s64 + -23144;
	// stw r11,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r11.u32);
	// bl 0x82130000
	ctx.lr = 0x824CBDBC;
	sub_82130000(ctx, base);
	// stw r3,700(r31)
	PPC_STORE_U32(r31.u32 + 700, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_824CBD20) {
	__imp__sub_824CBD20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CBDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CBDDC) {
	__imp__sub_824CBDDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CBDE0) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6400
	ctx.lr = 0x824CBDFC;
	sub_824E6400(ctx, base);
	// addi r4,r31,640
	ctx.r4.s64 = r31.s64 + 640;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824CBE0C;
	sub_823DA950(ctx, base);
	// lwz r11,780(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 780);
	// addi r9,r31,700
	ctx.r9.s64 = r31.s64 + 700;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r8,1250
	ctx.r8.s64 = 1250;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,784
	ctx.r4.s64 = r31.s64 + 784;
	// addi r3,r11,4552
	ctx.r3.s64 = r11.s64 + 4552;
	// lwz r5,11580(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 11580);
	// beq cr6,0x824cbe40
	if (cr6.eq) goto loc_824CBE40;
	// lwz r6,776(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 776);
	// bl 0x824cb728
	ctx.lr = 0x824CBE3C;
	sub_824CB728(ctx, base);
	// b 0x824cbe48
	goto loc_824CBE48;
loc_824CBE40:
	// addi r6,r31,776
	ctx.r6.s64 = r31.s64 + 776;
	// bl 0x824cb7c0
	ctx.lr = 0x824CBE48;
	sub_824CB7C0(ctx, base);
loc_824CBE48:
	// lwz r11,780(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 780);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,780(r31)
	PPC_STORE_U32(r31.u32 + 780, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824CBDE0) {
	__imp__sub_824CBDE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CBE68) {
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
	// bl 0x824ca690
	ctx.lr = 0x824CBE88;
	sub_824CA690(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cbea0
	if (cr6.eq) goto loc_824CBEA0;
	// bl 0x82130588
	ctx.lr = 0x824CBE9C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CBEA0:
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

PPC_WEAK_FUNC(sub_824CBE68) {
	__imp__sub_824CBE68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CBEB8) {
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
	ctx.lr = 0x824CBEC0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824cbef8
	if (cr6.eq) goto loc_824CBEF8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x824cbef8
	if (cr6.eq) goto loc_824CBEF8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x824cbef8
	if (cr6.eq) goto loc_824CBEF8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// bne cr6,0x824cbefc
	if (!cr6.eq) goto loc_824CBEFC;
loc_824CBEF8:
	// li r10,1
	ctx.r10.s64 = 1;
loc_824CBEFC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cbfa8
	if (cr6.eq) goto loc_824CBFA8;
	// mr r31,r28
	r31.u64 = r28.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x824cbf70
	if (!cr6.eq) goto loc_824CBF70;
	// std r28,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r28.u64);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8252ad10
	ctx.lr = 0x824CBF20;
	sub_8252AD10(ctx, base);
	// stb r28,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r28.u8);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22124
	ctx.r10.s64 = r11.s64 + 22124;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824c9fa8
	ctx.lr = 0x824CBF44;
	sub_824C9FA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cbf70
	if (cr6.eq) goto loc_824CBF70;
	// lbz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cbf70
	if (cr6.eq) goto loc_824CBF70;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252d198
	ctx.lr = 0x824CBF6C;
	sub_8252D198(ctx, base);
	// li r31,1
	r31.s64 = 1;
loc_824CBF70:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// addi r3,r29,1040
	ctx.r3.s64 = r29.s64 + 1040;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// beq cr6,0x824cbf98
	if (cr6.eq) goto loc_824CBF98;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824CBF8C;
	sub_821CE0A0(ctx, base);
	// stw r28,1044(r29)
	PPC_STORE_U32(r29.u32 + 1044, r28.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
loc_824CBF98:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824CBFA0;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,1044(r29)
	PPC_STORE_U32(r29.u32 + 1044, r11.u32);
loc_824CBFA8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CBEB8) {
	__imp__sub_824CBEB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CBFB0) {
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
	ctx.lr = 0x824CBFB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,32512
	r11.s64 = 2130706432;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,1
	r28.s64 = 1;
	// ori r29,r11,16
	r29.u64 = r11.u64 | 16;
	// lis r30,-32115
	r30.s64 = -2104688640;
loc_824CBFD0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x824cc038
	if (cr6.lt) goto loc_824CC038;
	// bne cr6,0x824cc080
	if (!cr6.eq) goto loc_824CC080;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// lwz r5,11580(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 11580);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824efbf8
	ctx.lr = 0x824CC000;
	sub_824EFBF8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// blt cr6,0x824cc028
	if (cr6.lt) goto loc_824CC028;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CC024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cc080
	goto loc_824CC080;
loc_824CC028:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CC034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cc080
	goto loc_824CC080;
loc_824CC038:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cc050
	if (!cr6.eq) goto loc_824CC050;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x824cbae0
	ctx.lr = 0x824CC04C;
	sub_824CBAE0(ctx, base);
	// b 0x824cc07c
	goto loc_824CC07C;
loc_824CC050:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cc080
	if (cr6.eq) goto loc_824CC080;
	// lwz r11,22576(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 22576);
	// li r5,-1
	ctx.r5.s64 = -1;
	// addi r3,r31,68
	ctx.r3.s64 = r31.s64 + 68;
	// clrlwi r10,r11,8
	ctx.r10.u64 = r11.u32 & 0xFFFFFF;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rlwinm r10,r10,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r11,22576(r30)
	PPC_STORE_U32(r30.u32 + 22576, r11.u32);
	// or r4,r10,r29
	ctx.r4.u64 = ctx.r10.u64 | r29.u64;
	// bl 0x824e6330
	ctx.lr = 0x824CC07C;
	sub_824E6330(ctx, base);
loc_824CC07C:
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
loc_824CC080:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cc0a0
	if (cr6.eq) goto loc_824CC0A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CC094;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cbfd0
	if (!cr6.eq) goto loc_824CBFD0;
loc_824CC0A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CBFB0) {
	__imp__sub_824CBFB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC0A8) {
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
	ctx.lr = 0x824CC0B0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824cc0e8
	if (cr6.eq) goto loc_824CC0E8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x824cc0e8
	if (cr6.eq) goto loc_824CC0E8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x824cc0e8
	if (cr6.eq) goto loc_824CC0E8;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x824cc0ec
	if (!cr6.eq) goto loc_824CC0EC;
loc_824CC0E8:
	// li r11,1
	r11.s64 = 1;
loc_824CC0EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cc198
	if (cr6.eq) goto loc_824CC198;
	// lwz r11,2464(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2464);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,2464(r31)
	PPC_STORE_U32(r31.u32 + 2464, r11.u32);
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x824cc174
	if (!cr6.eq) goto loc_824CC174;
	// std r29,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r29.u64);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8252ad10
	ctx.lr = 0x824CC11C;
	sub_8252AD10(ctx, base);
	// stb r29,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r29.u8);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22060
	ctx.r10.s64 = r11.s64 + 22060;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824ca220
	ctx.lr = 0x824CC140;
	sub_824CA220(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cc174
	if (cr6.eq) goto loc_824CC174;
	// lbz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cc174
	if (cr6.eq) goto loc_824CC174;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252d198
	ctx.lr = 0x824CC168;
	sub_8252D198(ctx, base);
	// lwz r11,2468(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2468);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,2468(r31)
	PPC_STORE_U32(r31.u32 + 2468, r11.u32);
loc_824CC174:
	// lwz r11,2464(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2464);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824cc198
	if (!cr6.eq) goto loc_824CC198;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CC198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CC198:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CC0A8) {
	__imp__sub_824CC0A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC1A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
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
	ctx.lr = 0x824CC1A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,1
	r27.s64 = 1;
	// li r29,3
	r29.s64 = 3;
	// li r28,4
	r28.s64 = 4;
loc_824CC1BC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x824cc318
	if (cr6.gt) goto loc_824CC318;
	// lis r12,-32179
	r12.s64 = -2108882944;
	// addi r12,r12,-15904
	r12.s64 = r12.s64 + -15904;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-15884(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -15884);
	// lwz r18,-15848(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -15848);
	// lwz r18,-15692(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -15692);
	// lwz r18,-15664(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -15664);
	// lwz r18,-15628(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -15628);
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cc208
	if (!cr6.eq) goto loc_824CC208;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// b 0x824cc318
	goto loc_824CC318;
loc_824CC208:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cc318
	if (cr6.eq) goto loc_824CC318;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// b 0x824cc318
	goto loc_824CC318;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824cc234
	if (cr6.eq) goto loc_824CC234;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x824cc234
	if (cr6.eq) goto loc_824CC234;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cc304
	goto loc_824CC304;
loc_824CC234:
	// addi r30,r31,136
	r30.s64 = r31.s64 + 136;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825006a0
	ctx.lr = 0x824CC240;
	sub_825006A0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r31,208
	ctx.r10.s64 = r31.s64 + 208;
	// li r9,9
	ctx.r9.s64 = 9;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824CC250:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x824cc250
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CC250;
	// lwz r26,196(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r25,r31,32
	r25.s64 = r31.s64 + 32;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r24,r31,244
	r24.s64 = r31.s64 + 244;
	// bl 0x823eaef8
	ctx.lr = 0x824CC278;
	sub_823EAEF8(ctx, base);
	// bl 0x824ea838
	ctx.lr = 0x824CC27C;
	sub_824EA838(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,11592
	ctx.r3.s64 = r11.s64 + 11592;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r8,r25
	ctx.r8.u64 = r25.u64;
	// bl 0x8252f8d0
	ctx.lr = 0x824CC29C;
	sub_8252F8D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// b 0x824cc318
	goto loc_824CC318;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cc208
	if (!cr6.eq) goto loc_824CC208;
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// bl 0x824cbae0
	ctx.lr = 0x824CC2C8;
	sub_824CBAE0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cc304
	goto loc_824CC304;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r11,2264
	ctx.r3.s64 = r11.s64 + 2264;
	// bl 0x824e46a8
	ctx.lr = 0x824CC2E0;
	sub_824E46A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cc300
	if (cr6.eq) goto loc_824CC300;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// b 0x824cc318
	goto loc_824CC318;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cc318
	if (cr6.eq) goto loc_824CC318;
loc_824CC300:
	// li r4,0
	ctx.r4.s64 = 0;
loc_824CC304:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CC318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CC318:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cc338
	if (cr6.eq) goto loc_824CC338;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CC32C;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cc1bc
	if (!cr6.eq) goto loc_824CC1BC;
loc_824CC338:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_824CC1A0) {
	__imp__sub_824CC1A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC340) {
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
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r6,r9,14316
	ctx.r6.s64 = ctx.r9.s64 + 14316;
	// lbz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r8,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r8.u8);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lbz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r4,r5,128
	ctx.r4.u64 = ctx.r5.u64 | 128;
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// stb r4,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r4.u8);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// bl 0x824e6400
	ctx.lr = 0x824CC3A4;
	sub_824E6400(ctx, base);
	// addi r3,r31,104
	ctx.r3.s64 = r31.s64 + 104;
	// bl 0x824cae00
	ctx.lr = 0x824CC3AC;
	sub_824CAE00(ctx, base);
	// addi r3,r31,424
	ctx.r3.s64 = r31.s64 + 424;
	// bl 0x824cbd20
	ctx.lr = 0x824CC3B4;
	sub_824CBD20(ctx, base);
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

PPC_WEAK_FUNC(sub_824CC340) {
	__imp__sub_824CC340(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CC3CC) {
	__imp__sub_824CC3CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC3D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// bl 0x823d91d4
	ctx.lr = 0x824CC3D8;
	// stwu r1,-1456(r1)
	ea = -1456 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// li r23,1
	r23.s64 = 1;
	// li r20,2
	r20.s64 = 2;
	// li r28,0
	r28.s64 = 0;
	// li r24,-1
	r24.s64 = -1;
	// li r25,3
	r25.s64 = 3;
	// li r26,6
	r26.s64 = 6;
	// li r21,4
	r21.s64 = 4;
	// li r22,7
	r22.s64 = 7;
	// addi r27,r11,22476
	r27.s64 = r11.s64 + 22476;
loc_824CC40C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x824cc664
	if (cr6.gt) goto loc_824CC664;
	// lis r12,-32179
	r12.s64 = -2108882944;
	// addi r12,r12,-15312
	r12.s64 = r12.s64 + -15312;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-15280(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -15280);
	// lwz r18,-15232(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -15232);
	// lwz r18,-15176(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -15176);
	// lwz r18,-14936(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -14936);
	// lwz r18,-14900(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -14900);
	// lwz r18,-14840(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -14840);
	// lwz r18,-14820(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -14820);
	// lwz r18,-14784(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -14784);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,4400
	ctx.r3.s64 = r11.s64 + 4400;
	// bl 0x82481330
	ctx.lr = 0x824CC45C;
	sub_82481330(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481910
	ctx.lr = 0x824CC464;
	sub_82481910(ctx, base);
	// lwz r11,1216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// stw r23,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r23.u32);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CC47C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cc664
	goto loc_824CC664;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cc4a8
	if (!cr6.eq) goto loc_824CC4A8;
	// lwz r11,1216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CC4A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cc664
	goto loc_824CC664;
loc_824CC4A8:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cc64c
	if (!cr6.eq) goto loc_824CC64C;
	// stw r20,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r20.u32);
	// b 0x824cc664
	goto loc_824CC664;
	// std r28,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r28.u64);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824e71c8
	ctx.lr = 0x824CC4C4;
	sub_824E71C8(ctx, base);
	// stw r24,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r24.u32);
	// stw r28,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r28.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r30,144(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r29,1180(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1180);
	// bl 0x82481680
	ctx.lr = 0x824CC4DC;
	sub_82481680(ctx, base);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// li r5,96
	ctx.r5.s64 = 96;
	// bl 0x823da950
	ctx.lr = 0x824CC4F0;
	sub_823DA950(ctx, base);
	// stw r30,204(r1)
	PPC_STORE_U32(ctx.r1.u32 + 204, r30.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824cc50c
	if (cr6.eq) goto loc_824CC50C;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r31,668
	ctx.r4.s64 = r31.s64 + 668;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8244d5c0
	ctx.lr = 0x824CC50C;
	sub_8244D5C0(ctx, base);
loc_824CC50C:
	// stw r29,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r29.u32);
	// addi r4,r31,1184
	ctx.r4.s64 = r31.s64 + 1184;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r30,r31,2232
	r30.s64 = r31.s64 + 2232;
	// lwz r5,11580(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 11580);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824ec120
	ctx.lr = 0x824CC528;
	sub_824EC120(ctx, base);
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r6,624
	ctx.r6.s64 = 624;
	// lwz r4,8(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// addi r5,r1,720
	ctx.r5.s64 = ctx.r1.s64 + 720;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824cb858
	ctx.lr = 0x824CC540;
	sub_824CB858(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cc5c4
	if (cr6.eq) goto loc_824CC5C4;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r7,r1,720
	ctx.r7.s64 = ctx.r1.s64 + 720;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r5,r31,1564
	ctx.r5.s64 = r31.s64 + 1564;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824880f8
	ctx.lr = 0x824CC56C;
	sub_824880F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cc5c4
	if (cr6.eq) goto loc_824CC5C4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f97c0
	ctx.lr = 0x824CC57C;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481b70
	ctx.lr = 0x824CC588;
	sub_82481B70(ctx, base);
	// bl 0x82618670
	ctx.lr = 0x824CC58C;
	sub_82618670(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ce080
	ctx.lr = 0x824CC59C;
	sub_821CE080(ctx, base);
	// stw r28,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r28.u32);
	// stw r25,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r25.u32);
	// b 0x824cc664
	goto loc_824CC664;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cc5bc
	if (!cr6.eq) goto loc_824CC5BC;
	// stw r21,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r21.u32);
	// b 0x824cc664
	goto loc_824CC664;
loc_824CC5BC:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cc664
	if (cr6.eq) goto loc_824CC664;
loc_824CC5C4:
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// b 0x824cc664
	goto loc_824CC664;
	// addi r10,r31,48
	ctx.r10.s64 = r31.s64 + 48;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r7,r31,32
	ctx.r7.s64 = r31.s64 + 32;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,1180
	ctx.r5.s64 = r31.s64 + 1180;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,2264
	ctx.r3.s64 = r11.s64 + 2264;
	// bl 0x824e4828
	ctx.lr = 0x824CC5F0;
	sub_824E4828(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r7,r11,5
	ctx.r7.s64 = r11.s64 + 5;
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// b 0x824cc664
	goto loc_824CC664;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cc5bc
	if (!cr6.eq) goto loc_824CC5BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cc650
	goto loc_824CC650;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r11,2264
	ctx.r3.s64 = r11.s64 + 2264;
	// bl 0x824e46a8
	ctx.lr = 0x824CC62C;
	sub_824E46A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cc64c
	if (cr6.eq) goto loc_824CC64C;
	// stw r22,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r22.u32);
	// b 0x824cc664
	goto loc_824CC664;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cc664
	if (cr6.eq) goto loc_824CC664;
loc_824CC64C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_824CC650:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CC664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CC664:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cc684
	if (cr6.eq) goto loc_824CC684;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CC678;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cc40c
	if (!cr6.eq) goto loc_824CC40C;
loc_824CC684:
	// addi r1,r1,1456
	ctx.r1.s64 = ctx.r1.s64 + 1456;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_824CC3D0) {
	__imp__sub_824CC3D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CC68C) {
	__imp__sub_824CC68C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC690) {
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
	ctx.lr = 0x824CC698;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824cc6d4
	if (cr6.eq) goto loc_824CC6D4;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x824cc6d4
	if (cr6.eq) goto loc_824CC6D4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x824cc6d4
	if (cr6.eq) goto loc_824CC6D4;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x824cc6d8
	if (!cr6.eq) goto loc_824CC6D8;
loc_824CC6D4:
	// li r11,1
	r11.s64 = 1;
loc_824CC6D8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cc798
	if (cr6.eq) goto loc_824CC798;
	// lbz r11,88(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 88);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stb r10,88(r29)
	PPC_STORE_U8(r29.u32 + 88, ctx.r10.u8);
	// lwz r11,3116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3116);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r9,3116(r31)
	PPC_STORE_U32(r31.u32 + 3116, ctx.r9.u32);
	// lwz r8,28(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// bne cr6,0x824cc778
	if (!cr6.eq) goto loc_824CC778;
	// std r28,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r28.u64);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8252ad10
	ctx.lr = 0x824CC714;
	sub_8252AD10(ctx, base);
	// stb r28,128(r1)
	PPC_STORE_U8(ctx.r1.u32 + 128, r28.u8);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,22124
	ctx.r10.s64 = r11.s64 + 22124;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824c9fa8
	ctx.lr = 0x824CC738;
	sub_824C9FA8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cc778
	if (cr6.eq) goto loc_824CC778;
	// lbz r10,128(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cc778
	if (cr6.eq) goto loc_824CC778;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252d198
	ctx.lr = 0x824CC760;
	sub_8252D198(ctx, base);
	// lbz r11,88(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 88);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,88(r29)
	PPC_STORE_U8(r29.u32 + 88, ctx.r10.u8);
	// lwz r11,3120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3120);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,3120(r31)
	PPC_STORE_U32(r31.u32 + 3120, ctx.r9.u32);
loc_824CC778:
	// lwz r11,3116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3116);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824cc798
	if (!cr6.eq) goto loc_824CC798;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824CC794;
	sub_821CE0A0(ctx, base);
	// stw r28,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r28.u32);
loc_824CC798:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CC690) {
	__imp__sub_824CC690(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC7A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// addi r10,r3,40
	ctx.r10.s64 = ctx.r3.s64 + 40;
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// addi r6,r9,14652
	ctx.r6.s64 = ctx.r9.s64 + 14652;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// lbz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 24);
	// ori r10,r4,128
	ctx.r10.u64 = ctx.r4.u64 | 128;
	// stw r7,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r7.u32);
	// addi r9,r5,14604
	ctx.r9.s64 = ctx.r5.s64 + 14604;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stb r10,24(r3)
	PPC_STORE_U8(ctx.r3.u32 + 24, ctx.r10.u8);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// lbz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// clrlwi r7,r8,27
	ctx.r7.u64 = ctx.r8.u32 & 0x1F;
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r11,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, r11.u32);
	// stb r7,48(r3)
	PPC_STORE_U8(ctx.r3.u32 + 48, ctx.r7.u8);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// lbz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// stb r5,64(r3)
	PPC_STORE_U8(ctx.r3.u32 + 64, ctx.r5.u8);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// stw r11,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r11.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// lbz r4,76(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 76);
	// ori r11,r4,192
	r11.u64 = ctx.r4.u64 | 192;
	// stb r11,76(r3)
	PPC_STORE_U8(ctx.r3.u32 + 76, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824CC7A0) {
	__imp__sub_824CC7A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC838) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,14672
	ctx.r3.s64 = r11.s64 + 14672;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824CC838) {
	__imp__sub_824CC838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CC844) {
	__imp__sub_824CC844(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC848) {
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
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x82482008
	ctx.lr = 0x824CC86C;
	sub_82482008(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82482008
	ctx.lr = 0x824CC874;
	sub_82482008(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cc88c
	if (cr6.eq) goto loc_824CC88C;
	// bl 0x82130588
	ctx.lr = 0x824CC888;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CC88C:
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

PPC_WEAK_FUNC(sub_824CC848) {
	__imp__sub_824CC848(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC8A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CC8A4) {
	__imp__sub_824CC8A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC8A8) {
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
	ctx.lr = 0x824CC8B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r28,-1
	r28.s64 = -1;
	// addi r8,r10,14688
	ctx.r8.s64 = ctx.r10.s64 + 14688;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// stb r6,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r6.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x824e6400
	ctx.lr = 0x824CC900;
	sub_824E6400(ctx, base);
	// stw r28,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r28.u32);
	// addi r29,r31,96
	r29.s64 = r31.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82501b00
	ctx.lr = 0x824CC910;
	sub_82501B00(ctx, base);
	// addi r3,r29,36
	ctx.r3.s64 = r29.s64 + 36;
	// bl 0x8252fa48
	ctx.lr = 0x824CC918;
	sub_8252FA48(ctx, base);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// bl 0x824cbd20
	ctx.lr = 0x824CC920;
	sub_824CBD20(ctx, base);
	// stw r30,1000(r31)
	PPC_STORE_U32(r31.u32 + 1000, r30.u32);
	// stw r30,1004(r31)
	PPC_STORE_U32(r31.u32 + 1004, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,1008(r31)
	PPC_STORE_U32(r31.u32 + 1008, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CC8A8) {
	__imp__sub_824CC8A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC938) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,14708
	ctx.r3.s64 = r11.s64 + 14708;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824CC938) {
	__imp__sub_824CC938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CC944) {
	__imp__sub_824CC944(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC948) {
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
	ctx.lr = 0x824CC950;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r30,r31,208
	r30.s64 = r31.s64 + 208;
	// addi r10,r11,13952
	ctx.r10.s64 = r11.s64 + 13952;
	// addi r3,r30,700
	ctx.r3.s64 = r30.s64 + 700;
	// stw r10,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r10.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x8252eca8
	ctx.lr = 0x824CC974;
	sub_8252ECA8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82482008
	ctx.lr = 0x824CC97C;
	sub_82482008(ctx, base);
	// addi r3,r31,132
	ctx.r3.s64 = r31.s64 + 132;
	// bl 0x8252f840
	ctx.lr = 0x824CC984;
	sub_8252F840(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82482008
	ctx.lr = 0x824CC98C;
	sub_82482008(ctx, base);
	// clrlwi r9,r29,31
	ctx.r9.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cc9a4
	if (cr6.eq) goto loc_824CC9A4;
	// bl 0x82130588
	ctx.lr = 0x824CC9A0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CC9A4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CC948) {
	__imp__sub_824CC948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CC9AC) {
	__imp__sub_824CC9AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CC9B0) {
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
	ctx.lr = 0x824CC9B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r28,3
	r28.s64 = 3;
	// li r29,2
	r29.s64 = 2;
	// li r26,1
	r26.s64 = 1;
loc_824CC9D0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x824cca7c
	if (cr6.lt) goto loc_824CCA7C;
	// beq cr6,0x824cca30
	if (cr6.eq) goto loc_824CCA30;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x824ccab8
	if (!cr6.lt) goto loc_824CCAB8;
	// lwz r11,1004(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cca10
	if (!cr6.eq) goto loc_824CCA10;
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CCA0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824ccab8
	goto loc_824CCAB8;
loc_824CCA10:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r28,r11
	ctx.r9.s64 = r11.s64 - r28.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// b 0x824ccab4
	goto loc_824CCAB4;
loc_824CCA30:
	// addi r30,r31,208
	r30.s64 = r31.s64 + 208;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r7,r31,1004
	ctx.r7.s64 = r31.s64 + 1004;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// addi r5,r31,132
	ctx.r5.s64 = r31.s64 + 132;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824c6a30
	ctx.lr = 0x824CCA4C;
	sub_824C6A30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ccaa0
	if (cr6.eq) goto loc_824CCAA0;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481910
	ctx.lr = 0x824CCA64;
	sub_82481910(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CCA78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824ccab8
	goto loc_824CCAB8;
loc_824CCA7C:
	// lwz r11,1004(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cca98
	if (!cr6.eq) goto loc_824CCA98;
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x824cbae0
	ctx.lr = 0x824CCA90;
	sub_824CBAE0(ctx, base);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// b 0x824ccab8
	goto loc_824CCAB8;
loc_824CCA98:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824ccab8
	if (cr6.eq) goto loc_824CCAB8;
loc_824CCAA0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824CCAB4:
	// bctrl 
	ctx.lr = 0x824CCAB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CCAB8:
	// lwz r11,1004(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1004);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824ccad8
	if (cr6.eq) goto loc_824CCAD8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CCACC;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cc9d0
	if (!cr6.eq) goto loc_824CC9D0;
loc_824CCAD8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CC9B0) {
	__imp__sub_824CC9B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCAE0) {
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
	ctx.lr = 0x824CCAE8;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22028
	ctx.r10.s64 = r11.s64 + 22028;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824ca090
	ctx.lr = 0x824CCB1C;
	sub_824CA090(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ccb54
	if (cr6.eq) goto loc_824CCB54;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481188
	ctx.lr = 0x824CCB44;
	sub_82481188(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824ccb58
	if (!cr6.eq) goto loc_824CCB58;
loc_824CCB54:
	// li r11,0
	r11.s64 = 0;
loc_824CCB58:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CCAE0) {
	__imp__sub_824CCAE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCB64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CCB64) {
	__imp__sub_824CCB64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCB68) {
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
	ctx.lr = 0x824CCB70;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22348
	ctx.r10.s64 = r11.s64 + 22348;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824ca168
	ctx.lr = 0x824CCBA4;
	sub_824CA168(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ccbdc
	if (cr6.eq) goto loc_824CCBDC;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481188
	ctx.lr = 0x824CCBCC;
	sub_82481188(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824ccbe0
	if (!cr6.eq) goto loc_824CCBE0;
loc_824CCBDC:
	// li r11,0
	r11.s64 = 0;
loc_824CCBE0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CCB68) {
	__imp__sub_824CCB68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCBEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CCBEC) {
	__imp__sub_824CCBEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCBF0) {
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
	ctx.lr = 0x824CCBF8;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22252
	ctx.r10.s64 = r11.s64 + 22252;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824ca168
	ctx.lr = 0x824CCC2C;
	sub_824CA168(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ccc64
	if (cr6.eq) goto loc_824CCC64;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481188
	ctx.lr = 0x824CCC54;
	sub_82481188(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824ccc68
	if (!cr6.eq) goto loc_824CCC68;
loc_824CCC64:
	// li r11,0
	r11.s64 = 0;
loc_824CCC68:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CCBF0) {
	__imp__sub_824CCBF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCC74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CCC74) {
	__imp__sub_824CCC74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCC78) {
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
	// stwu r1,-1120(r1)
	ea = -1120 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22124
	ctx.r10.s64 = r11.s64 + 22124;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824c9ef0
	ctx.lr = 0x824CCCB4;
	sub_824C9EF0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ccce4
	if (cr6.eq) goto loc_824CCCE4;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481238
	ctx.lr = 0x824CCCD4;
	sub_82481238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824ccce8
	if (!cr6.eq) goto loc_824CCCE8;
loc_824CCCE4:
	// li r11,0
	r11.s64 = 0;
loc_824CCCE8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1120
	ctx.r1.s64 = ctx.r1.s64 + 1120;
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

PPC_WEAK_FUNC(sub_824CCC78) {
	__imp__sub_824CCC78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCD04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CCD04) {
	__imp__sub_824CCD04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCD08) {
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
	ctx.lr = 0x824CCD10;
	// stwu r1,-2192(r1)
	ea = -2192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824cce08
	if (!cr6.gt) goto loc_824CCE08;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r29,11396
	r28.s64 = r29.s64 + 11396;
	// addi r26,r11,22028
	r26.s64 = r11.s64 + 22028;
loc_824CCD3C:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618670
	ctx.lr = 0x824CCD48;
	sub_82618670(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824ccdf4
	if (cr6.lt) goto loc_824CCDF4;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824ccd70
	if (cr6.eq) goto loc_824CCD70;
	// addi r4,r24,8
	ctx.r4.s64 = r24.s64 + 8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824f9950
	ctx.lr = 0x824CCD64;
	sub_824F9950(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ccdf4
	if (!cr6.eq) goto loc_824CCDF4;
loc_824CCD70:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r6,999
	ctx.r6.s64 = 999;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ca090
	ctx.lr = 0x824CCD8C;
	sub_824CA090(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ccdf4
	if (cr6.eq) goto loc_824CCDF4;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1006
	ctx.r4.s64 = 1006;
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// bl 0x8252e178
	ctx.lr = 0x824CCDA8;
	sub_8252E178(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ccdf4
	if (cr6.eq) goto loc_824CCDF4;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r31,r3,r5
	r31.u64 = ctx.r3.u64 + ctx.r5.u64;
	// cmplwi cr6,r31,1006
	cr6.compare<uint32_t>(r31.u32, 1006, xer);
	// bgt cr6,0x824ccdf4
	if (cr6.gt) goto loc_824CCDF4;
	// addi r11,r1,1104
	r11.s64 = ctx.r1.s64 + 1104;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824CCDD0;
	sub_8244D5C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824ccdf4
	if (cr6.eq) goto loc_824CCDF4;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,1104
	ctx.r5.s64 = ctx.r1.s64 + 1104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r29,4552
	ctx.r3.s64 = r29.s64 + 4552;
	// bl 0x8252eaa0
	ctx.lr = 0x824CCDF4;
	sub_8252EAA0(ctx, base);
loc_824CCDF4:
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x824ccd3c
	if (cr6.lt) goto loc_824CCD3C;
loc_824CCE08:
	// addi r1,r1,2192
	ctx.r1.s64 = ctx.r1.s64 + 2192;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_824CCD08) {
	__imp__sub_824CCD08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCE10) {
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
	ctx.lr = 0x824CCE18;
	// stwu r1,-1136(r1)
	ea = -1136 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22188
	ctx.r10.s64 = r11.s64 + 22188;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824c9c98
	ctx.lr = 0x824CCE4C;
	sub_824C9C98(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cce84
	if (cr6.eq) goto loc_824CCE84;
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481188
	ctx.lr = 0x824CCE74;
	sub_82481188(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cce88
	if (!cr6.eq) goto loc_824CCE88;
loc_824CCE84:
	// li r11,0
	r11.s64 = 0;
loc_824CCE88:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1136
	ctx.r1.s64 = ctx.r1.s64 + 1136;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CCE10) {
	__imp__sub_824CCE10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCE94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CCE94) {
	__imp__sub_824CCE94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCE98) {
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
	// stwu r1,-1120(r1)
	ea = -1120 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,22540
	ctx.r10.s64 = r11.s64 + 22540;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824c9e38
	ctx.lr = 0x824CCED4;
	sub_824C9E38(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ccf04
	if (cr6.eq) goto loc_824CCF04;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481238
	ctx.lr = 0x824CCEF4;
	sub_82481238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824ccf08
	if (!cr6.eq) goto loc_824CCF08;
loc_824CCF04:
	// li r11,0
	r11.s64 = 0;
loc_824CCF08:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,1120
	ctx.r1.s64 = ctx.r1.s64 + 1120;
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

PPC_WEAK_FUNC(sub_824CCE98) {
	__imp__sub_824CCE98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCF24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CCF24) {
	__imp__sub_824CCF24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCF28) {
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
	// addi r3,r31,700
	ctx.r3.s64 = r31.s64 + 700;
	// bl 0x8252ded8
	ctx.lr = 0x824CCF44;
	sub_8252DED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ccf88
	if (!cr6.eq) goto loc_824CCF88;
	// lwz r11,780(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 780);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bge cr6,0x824ccf70
	if (!cr6.lt) goto loc_824CCF70;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824cbde0
	ctx.lr = 0x824CCF64;
	sub_824CBDE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ccf88
	if (!cr6.eq) goto loc_824CCF88;
loc_824CCF70:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CCF88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CCF88:
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

PPC_WEAK_FUNC(sub_824CCF28) {
	__imp__sub_824CCF28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCF9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CCF9C) {
	__imp__sub_824CCF9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CCFA0) {
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
	ctx.lr = 0x824CCFA8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r29,-1
	r29.s64 = -1;
	// addi r8,r10,14532
	ctx.r8.s64 = ctx.r10.s64 + 14532;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// stb r6,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r6.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// std r30,32(r31)
	PPC_STORE_U64(r31.u32 + 32, r30.u64);
	// bl 0x824e71c8
	ctx.lr = 0x824CD000;
	sub_824E71C8(ctx, base);
	// stw r29,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r29.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
	// addi r3,r31,660
	ctx.r3.s64 = r31.s64 + 660;
	// stw r29,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r29.u32);
	// bl 0x8252f1a8
	ctx.lr = 0x824CD014;
	sub_8252F1A8(ctx, base);
	// addi r3,r31,736
	ctx.r3.s64 = r31.s64 + 736;
	// bl 0x824cab68
	ctx.lr = 0x824CD01C;
	sub_824CAB68(ctx, base);
	// lis r5,-32179
	ctx.r5.s64 = -2108882944;
	// stw r30,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-16712
	ctx.r4.s64 = ctx.r5.s64 + -16712;
	// stw r30,1044(r31)
	PPC_STORE_U32(r31.u32 + 1044, r30.u32);
	// stw r30,660(r31)
	PPC_STORE_U32(r31.u32 + 660, r30.u32);
	// stw r4,664(r31)
	PPC_STORE_U32(r31.u32 + 664, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x824CD03C;
	sub_82130000(ctx, base);
	// stw r3,660(r31)
	PPC_STORE_U32(r31.u32 + 660, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CCFA0) {
	__imp__sub_824CCFA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CD04C) {
	__imp__sub_824CD04C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD050) {
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
	ctx.lr = 0x824CD058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,660
	r30.s64 = r31.s64 + 660;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8252ded8
	ctx.lr = 0x824CD070;
	sub_8252DED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd084
	if (cr6.eq) goto loc_824CD084;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8252e880
	ctx.lr = 0x824CD084;
	sub_8252E880(ctx, base);
loc_824CD084:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd174
	if (cr6.eq) goto loc_824CD174;
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82502300
	ctx.lr = 0x824CD09C;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824825c0
	ctx.lr = 0x824CD0A8;
	sub_824825C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd174
	if (cr6.eq) goto loc_824CD174;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x824CD0BC;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x824CD0C0;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481b70
	ctx.lr = 0x824CD0CC;
	sub_82481B70(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x824cd120
	if (cr6.eq) goto loc_824CD120;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481580
	ctx.lr = 0x824CD0E0;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd120
	if (cr6.eq) goto loc_824CD120;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CD0F4;
	sub_82481680(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x82618670
	ctx.lr = 0x824CD104;
	sub_82618670(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,4552
	ctx.r3.s64 = r11.s64 + 4552;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x824ccae0
	ctx.lr = 0x824CD120;
	sub_824CCAE0(ctx, base);
loc_824CD120:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82502300
	ctx.lr = 0x824CD128;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481af0
	ctx.lr = 0x824CD134;
	sub_82481AF0(ctx, base);
	// lbz r11,108(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 108);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,108(r3)
	PPC_STORE_U8(ctx.r3.u32 + 108, ctx.r10.u8);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82486dd0
	ctx.lr = 0x824CD14C;
	sub_82486DD0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824870c8
	ctx.lr = 0x824CD158;
	sub_824870C8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CD164;
	sub_824810C8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_824CD174:
	// lbz r11,744(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 744);
	// addi r3,r31,736
	ctx.r3.s64 = r31.s64 + 736;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cd198
	if (cr6.eq) goto loc_824CD198;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824cd19c
	if (cr6.eq) goto loc_824CD19C;
loc_824CD198:
	// li r11,0
	r11.s64 = 0;
loc_824CD19C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd1bc
	if (cr6.eq) goto loc_824CD1BC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CD1BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CD1BC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CD1C8;
	sub_824810C8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CD050) {
	__imp__sub_824CD050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD1D8) {
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
	ctx.lr = 0x824CD1E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r29,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r29.u64);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// mr r30,r29
	r30.u64 = r29.u64;
	// bl 0x8252ad00
	ctx.lr = 0x824CD1FC;
	sub_8252AD00(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8252ad00
	ctx.lr = 0x824CD204;
	sub_8252AD00(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252af10
	ctx.lr = 0x824CD214;
	sub_8252AF10(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CD21C;
	sub_82481680(ctx, base);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
	// bl 0x82130000
	ctx.lr = 0x824CD230;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x824CD234;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481b70
	ctx.lr = 0x824CD240;
	sub_82481B70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cd274
	if (cr6.eq) goto loc_824CD274;
	// addi r30,r31,660
	r30.s64 = r31.s64 + 660;
	// addi r28,r1,96
	r28.s64 = ctx.r1.s64 + 96;
	// bl 0x82618670
	ctx.lr = 0x824CD254;
	sub_82618670(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r11,4552
	ctx.r3.s64 = r11.s64 + 4552;
	// li r6,10000
	ctx.r6.s64 = 10000;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// bl 0x824ccb68
	ctx.lr = 0x824CD270;
	sub_824CCB68(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_824CD274:
	// addi r31,r31,1040
	r31.s64 = r31.s64 + 1040;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce080
	ctx.lr = 0x824CD284;
	sub_821CE080(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cd2ac
	if (!cr6.eq) goto loc_824CD2AC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824CD2A4;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_824CD2AC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CD1D8) {
	__imp__sub_824CD1D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD2B8) {
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
	ctx.lr = 0x824CD2C0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// li r5,632
	ctx.r5.s64 = 632;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// bl 0x823da950
	ctx.lr = 0x824CD2E4;
	sub_823DA950(ctx, base);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// li r27,0
	r27.s64 = 0;
	// bl 0x82130000
	ctx.lr = 0x824CD2F0;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x824CD2F4;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82482640
	ctx.lr = 0x824CD300;
	sub_82482640(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd318
	if (cr6.eq) goto loc_824CD318;
	// li r11,1
	r11.s64 = 1;
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// b 0x824cd384
	goto loc_824CD384;
loc_824CD318:
	// addi r3,r28,8
	ctx.r3.s64 = r28.s64 + 8;
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// addi r25,r31,664
	r25.s64 = r31.s64 + 664;
	// addi r28,r28,624
	r28.s64 = r28.s64 + 624;
	// bl 0x82130000
	ctx.lr = 0x824CD32C;
	sub_82130000(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x824CD330;
	sub_82130000(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x824c6cf0
	ctx.lr = 0x824CD348;
	sub_824C6CF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd388
	if (cr6.eq) goto loc_824CD388;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CD368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r29,11560
	ctx.r4.s64 = r29.s64 + 11560;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824828f0
	ctx.lr = 0x824CD37C;
	sub_824828F0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
loc_824CD384:
	// li r27,1
	r27.s64 = 1;
loc_824CD388:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd3b4
	if (cr6.eq) goto loc_824CD3B4;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c8758
	ctx.lr = 0x824CD3A4;
	sub_824C8758(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cd3b8
	if (!cr6.eq) goto loc_824CD3B8;
loc_824CD3B4:
	// li r11,0
	r11.s64 = 0;
loc_824CD3B8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_824CD2B8) {
	__imp__sub_824CD2B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD3C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CD3C4) {
	__imp__sub_824CD3C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD3C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x824CD3D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r30,r31,28
	r30.s64 = r31.s64 + 28;
	// addi r8,r10,14068
	ctx.r8.s64 = ctx.r10.s64 + 14068;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// mr r27,r30
	r27.u64 = r30.u64;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// li r28,31
	r28.s64 = 31;
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stb r6,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r6.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
loc_824CD41C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8252f1a8
	ctx.lr = 0x824CD424;
	sub_8252F1A8(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,76
	r27.s64 = r27.s64 + 76;
	// bge 0x824cd41c
	if (!cr0.lt) goto loc_824CD41C;
	// stw r29,2460(r31)
	PPC_STORE_U32(r31.u32 + 2460, r29.u32);
	// li r28,32
	r28.s64 = 32;
	// stw r29,2464(r31)
	PPC_STORE_U32(r31.u32 + 2464, r29.u32);
	// stw r29,2468(r31)
	PPC_STORE_U32(r31.u32 + 2468, r29.u32);
loc_824CD440:
	// lis r11,-32179
	r11.s64 = -2108882944;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-16216
	ctx.r10.s64 = r11.s64 + -16216;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x824CD458;
	sub_82130000(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,76
	r30.s64 = r30.s64 + 76;
	// bne 0x824cd440
	if (!cr0.eq) goto loc_824CD440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CD3C8) {
	__imp__sub_824CD3C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CD474) {
	__imp__sub_824CD474(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD478) {
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
	ctx.lr = 0x824CD480;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cd4bc
	if (!cr6.eq) goto loc_824CD4BC;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x824c5d60
	ctx.lr = 0x824CD4AC;
	sub_824C5D60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cd4c0
	if (!cr6.eq) goto loc_824CD4C0;
loc_824CD4BC:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_824CD4C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd4d0
	if (cr6.eq) goto loc_824CD4D0;
	// stw r27,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r27.u32);
loc_824CD4D0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CD4E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,2468(r31)
	PPC_STORE_U32(r31.u32 + 2468, r30.u32);
	// stw r30,2464(r31)
	PPC_STORE_U32(r31.u32 + 2464, r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r30,2460(r31)
	PPC_STORE_U32(r31.u32 + 2460, r30.u32);
	// std r30,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r30.u64);
	// bl 0x824f0498
	ctx.lr = 0x824CD4FC;
	sub_824F0498(ctx, base);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x824cd5e0
	if (!cr6.gt) goto loc_824CD5E0;
loc_824CD504:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x824CD50C;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x824CD510;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481b70
	ctx.lr = 0x824CD51C;
	sub_82481B70(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824cd5d4
	if (cr6.eq) goto loc_824CD5D4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,4400
	ctx.r3.s64 = r11.s64 + 4400;
	// bl 0x82481448
	ctx.lr = 0x824CD534;
	sub_82481448(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481448
	ctx.lr = 0x824CD540;
	sub_82481448(ctx, base);
	// cmpld cr6,r3,r27
	cr6.compare<uint64_t>(ctx.r3.u64, r27.u64, xer);
	// beq cr6,0x824cd5d4
	if (cr6.eq) goto loc_824CD5D4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82502300
	ctx.lr = 0x824CD550;
	sub_82502300(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CD55C;
	sub_82481680(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ld r11,0(r27)
	r11.u64 = PPC_LOAD_U64(r27.u32 + 0);
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// bl 0x82618670
	ctx.lr = 0x824CD570;
	sub_82618670(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824cd5d4
	if (cr6.lt) goto loc_824CD5D4;
	// lwz r11,2460(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2460);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// mulli r11,r11,76
	r11.s64 = r11.s64 * 76;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r27,r11,28
	r27.s64 = r11.s64 + 28;
	// bl 0x82618670
	ctx.lr = 0x824CD594;
	sub_82618670(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,4552
	ctx.r3.s64 = r11.s64 + 4552;
	// li r6,10000
	ctx.r6.s64 = 10000;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// bl 0x824ccbf0
	ctx.lr = 0x824CD5B0;
	sub_824CCBF0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cd5d4
	if (cr6.eq) goto loc_824CD5D4;
	// lwz r10,2460(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2460);
	// lwz r11,2464(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2464);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r10,2460(r31)
	PPC_STORE_U32(r31.u32 + 2460, ctx.r10.u32);
	// stw r9,2464(r31)
	PPC_STORE_U32(r31.u32 + 2464, ctx.r9.u32);
loc_824CD5D4:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,96
	r28.s64 = r28.s64 + 96;
	// bne 0x824cd504
	if (!cr0.eq) goto loc_824CD504;
loc_824CD5E0:
	// lwz r11,2464(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2464);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824cd604
	if (!cr6.eq) goto loc_824CD604;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CD604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CD604:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CD478) {
	__imp__sub_824CD478(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD610) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x824CD618;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r10,14128
	ctx.r7.s64 = ctx.r10.s64 + 14128;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// addi r28,r31,40
	r28.s64 = r31.s64 + 40;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r29,31
	r29.s64 = 31;
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// stb r5,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r5.u8);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
loc_824CD670:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824CD678;
	sub_824E71C8(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,96
	r28.s64 = r28.s64 + 96;
	// bge 0x824cd670
	if (!cr0.lt) goto loc_824CD670;
	// stw r30,3368(r31)
	PPC_STORE_U32(r31.u32 + 3368, r30.u32);
	// addi r3,r31,3372
	ctx.r3.s64 = r31.s64 + 3372;
	// bl 0x824cd3c8
	ctx.lr = 0x824CD690;
	sub_824CD3C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CD610) {
	__imp__sub_824CD610(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CD69C) {
	__imp__sub_824CD69C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD6A0) {
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
	ctx.lr = 0x824CD6A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r27,3
	r27.s64 = 3;
	// li r28,1
	r28.s64 = 1;
loc_824CD6BC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x824cd714
	if (cr6.lt) goto loc_824CD714;
	// bne cr6,0x824cd780
	if (!cr6.eq) goto loc_824CD780;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cd6f4
	if (!cr6.eq) goto loc_824CD6F4;
	// lwz r11,3372(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3372);
	// addi r3,r31,3372
	ctx.r3.s64 = r31.s64 + 3372;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CD6F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cd780
	goto loc_824CD780;
loc_824CD6F4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// subf r9,r27,r11
	ctx.r9.s64 = r11.s64 - r27.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r7,16(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// b 0x824cd77c
	goto loc_824CD77C;
loc_824CD714:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cd760
	if (!cr6.eq) goto loc_824CD760;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481580
	ctx.lr = 0x824CD72C;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd758
	if (cr6.eq) goto loc_824CD758;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lwz r6,3368(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3368);
	// addi r5,r31,40
	ctx.r5.s64 = r31.s64 + 40;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r31,3372
	ctx.r3.s64 = r31.s64 + 3372;
	// bl 0x824cd478
	ctx.lr = 0x824CD750;
	sub_824CD478(ctx, base);
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// b 0x824cd780
	goto loc_824CD780;
loc_824CD758:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cd76c
	goto loc_824CD76C;
loc_824CD760:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cd780
	if (cr6.eq) goto loc_824CD780;
	// li r4,0
	ctx.r4.s64 = 0;
loc_824CD76C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_824CD77C:
	// bctrl 
	ctx.lr = 0x824CD780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CD780:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cd7a0
	if (cr6.eq) goto loc_824CD7A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CD794;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cd6bc
	if (!cr6.eq) goto loc_824CD6BC;
loc_824CD7A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CD6A0) {
	__imp__sub_824CD6A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD7A8) {
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
	ctx.lr = 0x824CD7B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82488238
	ctx.lr = 0x824CD7C4;
	sub_82488238(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r4,12(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r9,r11,-8452
	ctx.r9.s64 = r11.s64 + -8452;
	// li r31,0
	r31.s64 = 0;
	// addi r8,r10,13940
	ctx.r8.s64 = ctx.r10.s64 + 13940;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x824e7db8
	ctx.lr = 0x824CD800;
	sub_824E7DB8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CD80C;
	sub_824810C8(ctx, base);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CD7A8) {
	__imp__sub_824CD7A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD818) {
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
	ctx.lr = 0x824CD820;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CD834;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd8ec
	if (cr6.eq) goto loc_824CD8EC;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd8e4
	if (cr6.eq) goto loc_824CD8E4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,4400
	ctx.r3.s64 = r11.s64 + 4400;
	// bl 0x82481448
	ctx.lr = 0x824CD85C;
	sub_82481448(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r3,4496(r11)
	PPC_STORE_U64(r11.u32 + 4496, ctx.r3.u64);
	// lwz r10,140(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// beq cr6,0x824cd87c
	if (cr6.eq) goto loc_824CD87C;
	// li r4,1
	ctx.r4.s64 = 1;
loc_824CD87C:
	// bl 0x824819e8
	ctx.lr = 0x824CD880;
	sub_824819E8(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// addi r30,r11,-8452
	r30.s64 = r11.s64 + -8452;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r9,r10,14408
	ctx.r9.s64 = ctx.r10.s64 + 14408;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x824CD8B8;
	sub_824E7DB8(ctx, base);
	// lwz r7,676(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 676);
	// addi r6,r31,680
	ctx.r6.s64 = r31.s64 + 680;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824cd8cc
	if (!cr6.eq) goto loc_824CD8CC;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
loc_824CD8CC:
	// addi r4,r31,40
	ctx.r4.s64 = r31.s64 + 40;
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82485668
	ctx.lr = 0x824CD8DC;
	sub_82485668(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// b 0x824cd8ec
	goto loc_824CD8EC;
loc_824CD8E4:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481990
	ctx.lr = 0x824CD8EC;
	sub_82481990(ctx, base);
loc_824CD8EC:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CD8F8;
	sub_824810C8(ctx, base);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CD818) {
	__imp__sub_824CD818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CD904) {
	__imp__sub_824CD904(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CD908) {
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
	ctx.lr = 0x824CD910;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r30,r31,1184
	r30.s64 = r31.s64 + 1184;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8252ded8
	ctx.lr = 0x824CD928;
	sub_8252DED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd944
	if (cr6.eq) goto loc_824CD944;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824ebcc8
	ctx.lr = 0x824CD944;
	sub_824EBCC8(ctx, base);
loc_824CD944:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cda70
	if (!cr6.eq) goto loc_824CDA70;
	// addi r30,r31,2232
	r30.s64 = r31.s64 + 2232;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f97c0
	ctx.lr = 0x824CD95C;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82482640
	ctx.lr = 0x824CD968;
	sub_82482640(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd988
	if (cr6.eq) goto loc_824CD988;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f97c0
	ctx.lr = 0x824CD97C;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824878d8
	ctx.lr = 0x824CD988;
	sub_824878D8(ctx, base);
loc_824CD988:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481990
	ctx.lr = 0x824CD990;
	sub_82481990(ctx, base);
	// lbz r11,1224(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1224);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// li r29,0
	r29.s64 = 0;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cd9b8
	if (cr6.eq) goto loc_824CD9B8;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824cd9bc
	if (cr6.eq) goto loc_824CD9BC;
loc_824CD9B8:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_824CD9BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cd9dc
	if (cr6.eq) goto loc_824CD9DC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CD9DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CD9DC:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cda04
	if (!cr6.eq) goto loc_824CDA04;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824CD9FC;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_824CDA04:
	// lwz r10,664(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// addi r11,r31,152
	r11.s64 = r31.s64 + 152;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824cda18
	if (!cr6.eq) goto loc_824CDA18;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_824CDA18:
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// addi r30,r9,-8452
	r30.s64 = ctx.r9.s64 + -8452;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// addi r4,r6,13904
	ctx.r4.s64 = ctx.r6.s64 + 13904;
	// stw r29,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r29.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// stw r7,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// stw r29,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r29.u32);
	// ld r8,1564(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 1564);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// std r8,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// bl 0x824e7db8
	ctx.lr = 0x824CDA68;
	sub_824E7DB8(ctx, base);
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// b 0x824cdaf8
	goto loc_824CDAF8;
loc_824CDA70:
	// lwz r9,664(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// li r29,0
	r29.s64 = 0;
	// addi r10,r31,152
	ctx.r10.s64 = r31.s64 + 152;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x824cda88
	if (!cr6.eq) goto loc_824CDA88;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_824CDA88:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// stw r9,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// addi r30,r11,-8452
	r30.s64 = r11.s64 + -8452;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// addi r6,r7,13892
	ctx.r6.s64 = ctx.r7.s64 + 13892;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// ld r8,1564(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 1564);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// std r8,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// bl 0x824e7db8
	ctx.lr = 0x824CDAD0;
	sub_824E7DB8(ctx, base);
	// lwz r7,144(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// addi r6,r31,668
	ctx.r6.s64 = r31.s64 + 668;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x824cdae4
	if (!cr6.eq) goto loc_824CDAE4;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
loc_824CDAE4:
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// lwz r5,1180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1180);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82485668
	ctx.lr = 0x824CDAF4;
	sub_82485668(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
loc_824CDAF8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CDB04;
	sub_824810C8(ctx, base);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CD908) {
	__imp__sub_824CD908(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CDB10) {
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
	ctx.lr = 0x824CDB18;
	// stwu r1,-2256(r1)
	ea = -2256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CDB38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x824cdc78
	if (!cr6.eq) goto loc_824CDC78;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x824cdd40
	if (!cr6.eq) goto loc_824CDD40;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,40(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// lwz r4,44(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// bl 0x82257678
	ctx.lr = 0x824CDB64;
	sub_82257678(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cdd40
	if (cr6.eq) goto loc_824CDD40;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r28,r11,22412
	r28.s64 = r11.s64 + 22412;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x824cdd40
	if (!cr6.eq) goto loc_824CDD40;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,1184
	ctx.r4.s64 = r31.s64 + 1184;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824ebcc8
	ctx.lr = 0x824CDB94;
	sub_824EBCC8(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r26,-1
	r26.s64 = -1;
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// std r30,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r30.u64);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// mr r27,r30
	r27.u64 = r30.u64;
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// lwz r6,40(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// lwz r5,44(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// bl 0x824cb910
	ctx.lr = 0x824CDBD0;
	sub_824CB910(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cdc50
	if (cr6.eq) goto loc_824CDC50;
	// lwz r5,116(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r5,664(r31)
	PPC_STORE_U32(r31.u32 + 664, ctx.r5.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// beq cr6,0x824cdc08
	if (cr6.eq) goto loc_824CDC08;
	// cmplwi cr6,r5,512
	cr6.compare<uint32_t>(ctx.r5.u32, 512, xer);
	// bgt cr6,0x824cdc08
	if (cr6.gt) goto loc_824CDC08;
	// addi r4,r1,632
	ctx.r4.s64 = ctx.r1.s64 + 632;
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// bl 0x8244d5c0
	ctx.lr = 0x824CDC08;
	sub_8244D5C0(ctx, base);
loc_824CDC08:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x824cdc40
	if (!cr6.eq) goto loc_824CDC40;
	// lwz r5,112(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r5,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r5.u32);
	// stw r11,1180(r31)
	PPC_STORE_U32(r31.u32 + 1180, r11.u32);
	// beq cr6,0x824cdc40
	if (cr6.eq) goto loc_824CDC40;
	// cmplwi cr6,r5,512
	cr6.compare<uint32_t>(ctx.r5.u32, 512, xer);
	// bgt cr6,0x824cdc40
	if (cr6.gt) goto loc_824CDC40;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// addi r3,r31,668
	ctx.r3.s64 = r31.s64 + 668;
	// bl 0x8244d5c0
	ctx.lr = 0x824CDC40;
	sub_8244D5C0(ctx, base);
loc_824CDC40:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r10,r11,-3
	ctx.r10.s64 = r11.s64 + -3;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r27,r9,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
loc_824CDC50:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// beq cr6,0x824cdd34
	if (cr6.eq) goto loc_824CDD34;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824CDC6C;
	sub_821CE0A0(ctx, base);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// addi r1,r1,2256
	ctx.r1.s64 = ctx.r1.s64 + 2256;
	// b 0x823d9240
	return;
loc_824CDC78:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CDC8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x824cdd40
	if (!cr6.eq) goto loc_824CDD40;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x824cdd40
	if (!cr6.eq) goto loc_824CDD40;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,1184
	ctx.r4.s64 = r31.s64 + 1184;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x824ebcc8
	ctx.lr = 0x824CDCB4;
	sub_824EBCC8(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r26,-1
	r26.s64 = -1;
	// std r30,1152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1152, r30.u64);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r26,1160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1160, r26.u32);
	// addi r5,r11,36
	ctx.r5.s64 = r11.s64 + 36;
	// stw r30,1164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1164, r30.u32);
	// addi r9,r10,22412
	ctx.r9.s64 = ctx.r10.s64 + 22412;
	// stw r30,1168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1168, r30.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r30,1172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1172, r30.u32);
	// addi r3,r1,1152
	ctx.r3.s64 = ctx.r1.s64 + 1152;
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r6,164(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// bl 0x824cb910
	ctx.lr = 0x824CDCF4;
	sub_824CB910(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x824cdd2c
	if (cr6.eq) goto loc_824CDD2C;
	// lwz r5,1172(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1172);
	// lwz r11,1164(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1164);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stw r5,664(r31)
	PPC_STORE_U32(r31.u32 + 664, ctx.r5.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
	// beq cr6,0x824cdd2c
	if (cr6.eq) goto loc_824CDD2C;
	// cmplwi cr6,r5,512
	cr6.compare<uint32_t>(ctx.r5.u32, 512, xer);
	// bgt cr6,0x824cdd2c
	if (cr6.gt) goto loc_824CDD2C;
	// addi r4,r1,1688
	ctx.r4.s64 = ctx.r1.s64 + 1688;
	// addi r3,r31,152
	ctx.r3.s64 = r31.s64 + 152;
	// bl 0x8244d5c0
	ctx.lr = 0x824CDD2C;
	sub_8244D5C0(ctx, base);
loc_824CDD2C:
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// li r5,1
	ctx.r5.s64 = 1;
loc_824CDD34:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824CDD3C;
	sub_821CE0A0(ctx, base);
	// stw r26,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r26.u32);
loc_824CDD40:
	// addi r1,r1,2256
	ctx.r1.s64 = ctx.r1.s64 + 2256;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CDB10) {
	__imp__sub_824CDB10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CDD48) {
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
	ctx.lr = 0x824CDD50;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,0
	r29.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r29,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r29.u64);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8252ad10
	ctx.lr = 0x824CDD6C;
	sub_8252AD10(ctx, base);
	// stb r29,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r29.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8252ad10
	ctx.lr = 0x824CDD78;
	sub_8252AD10(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cdd94
	if (cr6.eq) goto loc_824CDD94;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252af40
	ctx.lr = 0x824CDD94;
	sub_8252AF40(ctx, base);
loc_824CDD94:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CDD9C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cddf0
	if (cr6.eq) goto loc_824CDDF0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CDDB0;
	sub_82481680(ctx, base);
	// std r3,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r3.u64);
	// addi r10,r1,136
	ctx.r10.s64 = ctx.r1.s64 + 136;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824CDDC4:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824cddc4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CDDC4;
	// stb r30,176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 176, r30.u8);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,48
	ctx.r4.s64 = r31.s64 + 48;
	// addi r3,r11,4552
	ctx.r3.s64 = r11.s64 + 4552;
	// bl 0x824ccc78
	ctx.lr = 0x824CDDF0;
	sub_824CCC78(ctx, base);
loc_824CDDF0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CDDFC;
	sub_824810C8(ctx, base);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CDD48) {
	__imp__sub_824CDD48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CDE08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x824CDE10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r7,r10,14732
	ctx.r7.s64 = ctx.r10.s64 + 14732;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// addi r29,r31,40
	r29.s64 = r31.s64 + 40;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r27,31
	r27.s64 = 31;
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// mr r28,r29
	r28.u64 = r29.u64;
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// stb r5,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r5.u8);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
loc_824CDE6C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8252f1a8
	ctx.lr = 0x824CDE74;
	sub_8252F1A8(ctx, base);
	// addi r3,r28,80
	ctx.r3.s64 = r28.s64 + 80;
	// bl 0x824f0498
	ctx.lr = 0x824CDE7C;
	sub_824F0498(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r28,r28,96
	r28.s64 = r28.s64 + 96;
	// bge 0x824cde6c
	if (!cr0.lt) goto loc_824CDE6C;
	// stw r30,3112(r31)
	PPC_STORE_U32(r31.u32 + 3112, r30.u32);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r30,3116(r31)
	PPC_STORE_U32(r31.u32 + 3116, r30.u32);
	// addi r3,r31,3168
	ctx.r3.s64 = r31.s64 + 3168;
	// stw r30,3120(r31)
	PPC_STORE_U32(r31.u32 + 3120, r30.u32);
	// addi r10,r11,14604
	ctx.r10.s64 = r11.s64 + 14604;
	// lbz r9,3132(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 3132);
	// clrlwi r8,r9,27
	ctx.r8.u64 = ctx.r9.u32 & 0x1F;
	// stw r30,3128(r31)
	PPC_STORE_U32(r31.u32 + 3128, r30.u32);
	// addi r11,r31,3124
	r11.s64 = r31.s64 + 3124;
	// stb r8,3132(r31)
	PPC_STORE_U8(r31.u32 + 3132, ctx.r8.u8);
	// stw r30,3136(r31)
	PPC_STORE_U32(r31.u32 + 3136, r30.u32);
	// stw r30,3140(r31)
	PPC_STORE_U32(r31.u32 + 3140, r30.u32);
	// stw r30,3144(r31)
	PPC_STORE_U32(r31.u32 + 3144, r30.u32);
	// lbz r7,3148(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 3148);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stb r6,3148(r31)
	PPC_STORE_U8(r31.u32 + 3148, ctx.r6.u8);
	// stw r10,3124(r31)
	PPC_STORE_U32(r31.u32 + 3124, ctx.r10.u32);
	// stw r30,3152(r31)
	PPC_STORE_U32(r31.u32 + 3152, r30.u32);
	// stw r30,3156(r31)
	PPC_STORE_U32(r31.u32 + 3156, r30.u32);
	// lbz r5,3160(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 3160);
	// ori r4,r5,192
	ctx.r4.u64 = ctx.r5.u64 | 192;
	// stb r4,3160(r31)
	PPC_STORE_U8(r31.u32 + 3160, ctx.r4.u8);
	// bl 0x824cab68
	ctx.lr = 0x824CDEE8;
	sub_824CAB68(ctx, base);
	// lbz r3,3472(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 3472);
	// li r28,32
	r28.s64 = 32;
	// clrlwi r11,r3,25
	r11.u64 = ctx.r3.u32 & 0x7F;
	// stb r11,3472(r31)
	PPC_STORE_U8(r31.u32 + 3472, r11.u8);
loc_824CDEF8:
	// lis r11,-32179
	r11.s64 = -2108882944;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-14704
	ctx.r10.s64 = r11.s64 + -14704;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x824CDF10;
	sub_82130000(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bne 0x824cdef8
	if (!cr0.eq) goto loc_824CDEF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CDE08) {
	__imp__sub_824CDE08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CDF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CDF2C) {
	__imp__sub_824CDF2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CDF30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r3,r11,-8472
	ctx.r3.s64 = r11.s64 + -8472;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824CDF30) {
	__imp__sub_824CDF30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CDF3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CDF3C) {
	__imp__sub_824CDF3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CDF40) {
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
	ctx.lr = 0x824CDF48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r31,r29,3168
	r31.s64 = r29.s64 + 3168;
	// addi r10,r11,14152
	ctx.r10.s64 = r11.s64 + 14152;
	// lwz r4,3464(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 3464);
	// stw r10,3168(r29)
	PPC_STORE_U32(r29.u32 + 3168, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x824cdf84
	if (cr6.eq) goto loc_824CDF84;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824CDF84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CDF84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82482008
	ctx.lr = 0x824CDF8C;
	sub_82482008(ctx, base);
	// addi r3,r29,3124
	ctx.r3.s64 = r29.s64 + 3124;
	// bl 0x82482008
	ctx.lr = 0x824CDF94;
	sub_82482008(ctx, base);
	// addi r31,r29,3112
	r31.s64 = r29.s64 + 3112;
	// li r30,31
	r30.s64 = 31;
loc_824CDF9C:
	// addi r31,r31,-96
	r31.s64 = r31.s64 + -96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8252eca8
	ctx.lr = 0x824CDFA8;
	sub_8252ECA8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x824cdf9c
	if (!cr0.lt) goto loc_824CDF9C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82482008
	ctx.lr = 0x824CDFB8;
	sub_82482008(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CDF40) {
	__imp__sub_824CDF40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CDFC0) {
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
	// bl 0x824cdf40
	ctx.lr = 0x824CDFE0;
	sub_824CDF40(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cdff8
	if (cr6.eq) goto loc_824CDFF8;
	// bl 0x82130588
	ctx.lr = 0x824CDFF4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824CDFF8:
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

PPC_WEAK_FUNC(sub_824CDFC0) {
	__imp__sub_824CDFC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE010) {
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
	ctx.lr = 0x824CE018;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r27
	r29.u64 = r27.u64;
	// lwz r11,3112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3112);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824ce06c
	if (!cr6.gt) goto loc_824CE06C;
	// addi r30,r31,40
	r30.s64 = r31.s64 + 40;
loc_824CE03C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8252ded8
	ctx.lr = 0x824CE044;
	sub_8252DED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce058
	if (cr6.eq) goto loc_824CE058;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8252e880
	ctx.lr = 0x824CE058;
	sub_8252E880(ctx, base);
loc_824CE058:
	// lwz r11,3112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3112);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x824ce03c
	if (cr6.lt) goto loc_824CE03C;
loc_824CE06C:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CE074;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce0f4
	if (cr6.eq) goto loc_824CE0F4;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce0f4
	if (cr6.eq) goto loc_824CE0F4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,11588(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11588);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,11588(r11)
	PPC_STORE_U32(r11.u32 + 11588, ctx.r10.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CE0A4;
	sub_82481680(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x824ccd08
	ctx.lr = 0x824CE0B8;
	sub_824CCD08(ctx, base);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// addi r30,r9,-8452
	r30.s64 = ctx.r9.s64 + -8452;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// addi r7,r8,14464
	ctx.r7.s64 = ctx.r8.s64 + 14464;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x824CE0F0;
	sub_824E7DB8(ctx, base);
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
loc_824CE0F4:
	// clrlwi r29,r28,24
	r29.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x824ce19c
	if (!cr6.eq) goto loc_824CE19C;
	// lbz r11,3132(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3132);
	// addi r3,r31,3124
	ctx.r3.s64 = r31.s64 + 3124;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ce124
	if (cr6.eq) goto loc_824CE124;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ce128
	if (cr6.eq) goto loc_824CE128;
loc_824CE124:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824CE128:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce148
	if (cr6.eq) goto loc_824CE148;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CE148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CE148:
	// lbz r11,3176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3176);
	// addi r3,r31,3168
	ctx.r3.s64 = r31.s64 + 3168;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ce16c
	if (cr6.eq) goto loc_824CE16C;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ce170
	if (cr6.eq) goto loc_824CE170;
loc_824CE16C:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824CE170:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce190
	if (cr6.eq) goto loc_824CE190;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CE190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CE190:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252cfa8
	ctx.lr = 0x824CE19C;
	sub_8252CFA8(ctx, base);
loc_824CE19C:
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ce1d8
	if (cr6.eq) goto loc_824CE1D8;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x824ce1c8
	if (cr6.eq) goto loc_824CE1C8;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824CE1C0;
	sub_821CE0A0(ctx, base);
	// stw r27,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r27.u32);
	// b 0x824ce1d8
	goto loc_824CE1D8;
loc_824CE1C8:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824CE1D0;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_824CE1D8:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r27,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r27.u32);
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CE010) {
	__imp__sub_824CE010(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE1FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CE1FC) {
	__imp__sub_824CE1FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE200) {
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
	ctx.lr = 0x824CE208;
	// stwu r1,-3248(r1)
	ea = -3248 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// std r27,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r27.u64);
	// stw r27,3120(r31)
	PPC_STORE_U32(r31.u32 + 3120, r27.u32);
	// stw r27,3116(r31)
	PPC_STORE_U32(r31.u32 + 3116, r27.u32);
	// stw r27,3112(r31)
	PPC_STORE_U32(r31.u32 + 3112, r27.u32);
	// bl 0x8252ad00
	ctx.lr = 0x824CE22C;
	sub_8252AD00(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8252ad00
	ctx.lr = 0x824CE234;
	sub_8252AD00(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252af10
	ctx.lr = 0x824CE244;
	sub_8252AF10(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CE24C;
	sub_82481680(ctx, base);
	// ld r11,80(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
	// li r30,31
	r30.s64 = 31;
	// std r11,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, r11.u64);
loc_824CE260:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824CE268;
	sub_824E71C8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bge 0x824ce260
	if (!cr0.lt) goto loc_824CE260;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// bl 0x824817c8
	ctx.lr = 0x824CE284;
	sub_824817C8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824ce3a0
	if (!cr6.gt) goto loc_824CE3A0;
	// addi r29,r1,112
	r29.s64 = ctx.r1.s64 + 112;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_824CE294:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x824CE29C;
	sub_82130000(ctx, base);
	// bl 0x824f97c0
	ctx.lr = 0x824CE2A0;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481b70
	ctx.lr = 0x824CE2AC;
	sub_82481B70(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ce394
	if (cr6.eq) goto loc_824CE394;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,4400
	ctx.r3.s64 = r11.s64 + 4400;
	// bl 0x82481448
	ctx.lr = 0x824CE2C4;
	sub_82481448(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481448
	ctx.lr = 0x824CE2D0;
	sub_82481448(ctx, base);
	// cmpld cr6,r3,r26
	cr6.compare<uint64_t>(ctx.r3.u64, r26.u64, xer);
	// beq cr6,0x824ce394
	if (cr6.eq) goto loc_824CE394;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618670
	ctx.lr = 0x824CE2E0;
	sub_82618670(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824ce340
	if (cr6.lt) goto loc_824CE340;
	// lwz r11,3112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3112);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r30,r1,96
	r30.s64 = ctx.r1.s64 + 96;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r26,r11,40
	r26.s64 = r11.s64 + 40;
	// bl 0x82618670
	ctx.lr = 0x824CE30C;
	sub_82618670(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,4552
	ctx.r3.s64 = r11.s64 + 4552;
	// li r6,10000
	ctx.r6.s64 = 10000;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// bl 0x824ccb68
	ctx.lr = 0x824CE328;
	sub_824CCB68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ce340
	if (cr6.eq) goto loc_824CE340;
	// lwz r11,3116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3116);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,3116(r31)
	PPC_STORE_U32(r31.u32 + 3116, r11.u32);
loc_824CE340:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82502300
	ctx.lr = 0x824CE348;
	sub_82502300(ctx, base);
	// lwz r11,3112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3112);
	// ld r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// std r9,120(r7)
	PPC_STORE_U64(ctx.r7.u32 + 120, ctx.r9.u64);
	// lwz r11,3112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3112);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// lbz r5,128(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + 128);
	// clrlwi r4,r5,25
	ctx.r4.u64 = ctx.r5.u32 & 0x7F;
	// stb r4,128(r11)
	PPC_STORE_U8(r11.u32 + 128, ctx.r4.u8);
	// lwz r11,3112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3112);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// stw r3,3112(r31)
	PPC_STORE_U32(r31.u32 + 3112, ctx.r3.u32);
loc_824CE394:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bne 0x824ce294
	if (!cr0.eq) goto loc_824CE294;
loc_824CE3A0:
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824CE3B0;
	sub_821CE080(ctx, base);
	// stw r27,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r27.u32);
	// lwz r11,3116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3116);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824ce3d4
	if (!cr6.eq) goto loc_824CE3D4;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824CE3D0;
	sub_821CE0A0(ctx, base);
	// stw r27,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r27.u32);
loc_824CE3D4:
	// addi r1,r1,3248
	ctx.r1.s64 = ctx.r1.s64 + 3248;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CE200) {
	__imp__sub_824CE200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE3DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CE3DC) {
	__imp__sub_824CE3DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE3E0) {
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
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r7,-1
	ctx.r7.s64 = -1;
	// addi r6,r9,14756
	ctx.r6.s64 = ctx.r9.s64 + 14756;
	// lbz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// clrlwi r8,r10,27
	ctx.r8.u64 = ctx.r10.u32 & 0x1F;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r8,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r8.u8);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// lbz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r4,r5,128
	ctx.r4.u64 = ctx.r5.u64 | 128;
	// stw r7,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r7.u32);
	// stb r4,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r4.u8);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// bl 0x824cd3c8
	ctx.lr = 0x824CE444;
	sub_824CD3C8(ctx, base);
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

PPC_WEAK_FUNC(sub_824CE3E0) {
	__imp__sub_824CE3E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CE45C) {
	__imp__sub_824CE45C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE460) {
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
	ctx.lr = 0x824CE468;
	// stwu r1,-3184(r1)
	ea = -3184 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r11,8(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 8);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ce49c
	if (!cr6.eq) goto loc_824CE49C;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ce49c
	if (cr6.eq) goto loc_824CE49C;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r11,r11,0,27,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF9F;
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stb r10,8(r29)
	PPC_STORE_U8(r29.u32 + 8, ctx.r10.u8);
loc_824CE49C:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CE4A4;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce51c
	if (cr6.eq) goto loc_824CE51C;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// li r31,31
	r31.s64 = 31;
loc_824CE4B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824CE4C0;
	sub_824E71C8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bge 0x824ce4b8
	if (!cr0.lt) goto loc_824CE4B8;
	// li r5,32
	ctx.r5.s64 = 32;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x824817c8
	ctx.lr = 0x824CE4DC;
	sub_824817C8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x824ce50c
	if (cr6.eq) goto loc_824CE50C;
	// addi r7,r29,32
	ctx.r7.s64 = r29.s64 + 32;
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,40
	ctx.r3.s64 = r29.s64 + 40;
	// bl 0x824cd478
	ctx.lr = 0x824CE4FC;
	sub_824CD478(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,28(r29)
	PPC_STORE_U32(r29.u32 + 28, r11.u32);
	// addi r1,r1,3184
	ctx.r1.s64 = ctx.r1.s64 + 3184;
	// b 0x823d924c
	return;
loc_824CE50C:
	// li r11,1
	r11.s64 = 1;
	// stw r11,28(r29)
	PPC_STORE_U32(r29.u32 + 28, r11.u32);
	// addi r1,r1,3184
	ctx.r1.s64 = ctx.r1.s64 + 3184;
	// b 0x823d924c
	return;
loc_824CE51C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CE534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,3184
	ctx.r1.s64 = ctx.r1.s64 + 3184;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CE460) {
	__imp__sub_824CE460(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE53C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CE53C) {
	__imp__sub_824CE53C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE540) {
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
	ctx.lr = 0x824CE548;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CE55C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce5c4
	if (cr6.eq) goto loc_824CE5C4;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce5c4
	if (cr6.eq) goto loc_824CE5C4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r28,r10,-8452
	r28.s64 = ctx.r10.s64 + -8452;
	// addi r8,r9,14464
	ctx.r8.s64 = ctx.r9.s64 + 14464;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r10,11588(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11588);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// stw r6,11588(r11)
	PPC_STORE_U32(r11.u32 + 11588, ctx.r6.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x824CE5C0;
	sub_824E7DB8(ctx, base);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_824CE5C4:
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ce5e8
	if (cr6.eq) goto loc_824CE5E8;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ce5ec
	if (cr6.eq) goto loc_824CE5EC;
loc_824CE5E8:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_824CE5EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce60c
	if (cr6.eq) goto loc_824CE60C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CE60C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CE60C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ce624
	if (!cr6.eq) goto loc_824CE624;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252cfa8
	ctx.lr = 0x824CE624;
	sub_8252CFA8(ctx, base);
loc_824CE624:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CE630;
	sub_824810C8(ctx, base);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CE540) {
	__imp__sub_824CE540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CE63C) {
	__imp__sub_824CE63C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE640) {
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
	ctx.lr = 0x824CE648;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CE65C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce700
	if (cr6.eq) goto loc_824CE700;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce6b8
	if (cr6.eq) goto loc_824CE6B8;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r28,r11,-8452
	r28.s64 = r11.s64 + -8452;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r10,14476
	ctx.r9.s64 = ctx.r10.s64 + 14476;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x824CE6B0;
	sub_824E7DB8(ctx, base);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// b 0x824ce700
	goto loc_824CE700;
loc_824CE6B8:
	// lbz r11,48(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 48);
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824ce6dc
	if (cr6.eq) goto loc_824CE6DC;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x824ce6e0
	if (cr6.eq) goto loc_824CE6E0;
loc_824CE6DC:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_824CE6E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce700
	if (cr6.eq) goto loc_824CE700;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CE700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CE700:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CE70C;
	sub_824810C8(ctx, base);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CE640) {
	__imp__sub_824CE640(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE718) {
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
	ctx.lr = 0x824CE720;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r4,r31,4780
	ctx.r4.s64 = r31.s64 + 4780;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,4552
	ctx.r3.s64 = r11.s64 + 4552;
	// bl 0x8252e698
	ctx.lr = 0x824CE73C;
	sub_8252E698(ctx, base);
	// lwz r11,4768(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4768);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mr r29,r28
	r29.u64 = r28.u64;
	// ble cr6,0x824ce784
	if (!cr6.gt) goto loc_824CE784;
	// addi r30,r31,1696
	r30.s64 = r31.s64 + 1696;
loc_824CE754:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8252ded8
	ctx.lr = 0x824CE75C;
	sub_8252DED8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce770
	if (cr6.eq) goto loc_824CE770;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8252e880
	ctx.lr = 0x824CE770;
	sub_8252E880(ctx, base);
loc_824CE770:
	// lwz r11,4768(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4768);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x824ce754
	if (cr6.lt) goto loc_824CE754;
loc_824CE784:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CE78C;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce8dc
	if (cr6.eq) goto loc_824CE8DC;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481688
	ctx.lr = 0x824CE7A0;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce7e4
	if (cr6.eq) goto loc_824CE7E4;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481580
	ctx.lr = 0x824CE7B4;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce7d8
	if (cr6.eq) goto loc_824CE7D8;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481588
	ctx.lr = 0x824CE7C8;
	sub_82481588(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824ce7dc
	if (!cr6.eq) goto loc_824CE7DC;
loc_824CE7D8:
	// li r4,1
	ctx.r4.s64 = 1;
loc_824CE7DC:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824819e8
	ctx.lr = 0x824CE7E4;
	sub_824819E8(ctx, base);
loc_824CE7E4:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ce870
	if (cr6.eq) goto loc_824CE870;
	// lwz r11,1628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1628);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// addi r30,r10,-8452
	r30.s64 = ctx.r10.s64 + -8452;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// addi r6,r8,13916
	ctx.r6.s64 = ctx.r8.s64 + 13916;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// addi r11,r11,40
	r11.s64 = r11.s64 + 40;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824CE83C:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824ce83c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CE83C;
	// li r11,1
	r11.s64 = 1;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stb r11,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r11.u8);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x824CE868;
	sub_824E7DB8(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// b 0x824ce8dc
	goto loc_824CE8DC;
loc_824CE870:
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x824f99c0
	ctx.lr = 0x824CE878;
	sub_824F99C0(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r28,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r28.u32);
	// addi r30,r11,-8452
	r30.s64 = r11.s64 + -8452;
	// stw r28,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r28.u32);
	// addi r9,r10,13916
	ctx.r9.s64 = ctx.r10.s64 + 13916;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// stw r9,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stw r8,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_824CE8B0:
	// ld r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// bdnz 0x824ce8b0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824CE8B0;
	// stb r28,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r28.u8);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x824CE8D8;
	sub_824E7DB8(ctx, base);
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
loc_824CE8DC:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// li r29,-1
	r29.s64 = -1;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824ce904
	if (!cr6.eq) goto loc_824CE904;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824CE900;
	sub_821CE0A0(ctx, base);
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
loc_824CE904:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lbz r10,11608(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 11608);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r9,11608(r11)
	PPC_STORE_U8(r11.u32 + 11608, ctx.r9.u8);
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824ce954
	if (cr6.eq) goto loc_824CE954;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x824ce948
	if (cr6.eq) goto loc_824CE948;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824CE940;
	sub_821CE0A0(ctx, base);
	// stw r28,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r28.u32);
	// b 0x824ce954
	goto loc_824CE954;
loc_824CE948:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824CE950;
	sub_821CE0A0(ctx, base);
	// stw r29,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r29.u32);
loc_824CE954:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CE718) {
	__imp__sub_824CE718(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CE978) {
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
	ctx.lr = 0x824CE980;
	// stwu r1,-1264(r1)
	ea = -1264 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// std r24,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r24.u64);
	// stw r24,4776(r31)
	PPC_STORE_U32(r31.u32 + 4776, r24.u32);
	// stw r24,4772(r31)
	PPC_STORE_U32(r31.u32 + 4772, r24.u32);
	// stw r24,4768(r31)
	PPC_STORE_U32(r31.u32 + 4768, r24.u32);
	// bl 0x824e6400
	ctx.lr = 0x824CE9A4;
	sub_824E6400(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481618
	ctx.lr = 0x824CE9AC;
	sub_82481618(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CE9B8;
	sub_82481680(ctx, base);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x823da950
	ctx.lr = 0x824CE9CC;
	sub_823DA950(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r23,r24
	r23.u64 = r24.u64;
	// lwz r10,11524(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11524);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4768(r31)
	PPC_STORE_U32(r31.u32 + 4768, ctx.r10.u32);
	// ble cr6,0x824ceac4
	if (!cr6.gt) goto loc_824CEAC4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r26,11396
	r26.s64 = 11396;
	// addi r29,r31,1788
	r29.s64 = r31.s64 + 1788;
	// addi r25,r11,22188
	r25.s64 = r11.s64 + 22188;
loc_824CE9F4:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r30,r11,r26
	r30.u64 = PPC_LOAD_U32(r11.u32 + r26.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481448
	ctx.lr = 0x824CEA04;
	sub_82481448(ctx, base);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// std r3,-12(r29)
	PPC_STORE_U64(r29.u32 + -12, ctx.r3.u64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stw r24,-4(r29)
	PPC_STORE_U32(r29.u32 + -4, r24.u32);
	// stb r9,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r9.u8);
	// bl 0x82618670
	ctx.lr = 0x824CEA20;
	sub_82618670(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824ceaac
	if (cr6.lt) goto loc_824CEAAC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,4828(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4828);
	// bl 0x82618670
	ctx.lr = 0x824CEA34;
	sub_82618670(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r4,8(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,999
	ctx.r6.s64 = 999;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r27,r11,4552
	r27.s64 = r11.s64 + 4552;
	// bl 0x824c9c98
	ctx.lr = 0x824CEA58;
	sub_824C9C98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cea90
	if (cr6.eq) goto loc_824CEA90;
	// addi r8,r29,-92
	ctx.r8.s64 = r29.s64 + -92;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82481188
	ctx.lr = 0x824CEA80;
	sub_82481188(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x824cea94
	if (!cr6.eq) goto loc_824CEA94;
loc_824CEA90:
	// mr r11,r24
	r11.u64 = r24.u64;
loc_824CEA94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824ceaac
	if (cr6.eq) goto loc_824CEAAC;
	// lwz r11,4772(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4772);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4772(r31)
	PPC_STORE_U32(r31.u32 + 4772, r11.u32);
loc_824CEAAC:
	// lwz r11,4768(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4768);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// cmpw cr6,r23,r11
	cr6.compare<int32_t>(r23.s32, r11.s32, xer);
	// blt cr6,0x824ce9f4
	if (cr6.lt) goto loc_824CE9F4;
loc_824CEAC4:
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce080
	ctx.lr = 0x824CEAD4;
	sub_821CE080(ctx, base);
	// stw r24,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r24.u32);
	// lwz r11,4772(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4772);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824ceaf8
	if (!cr6.eq) goto loc_824CEAF8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824CEAF4;
	sub_821CE0A0(ctx, base);
	// stw r24,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r24.u32);
loc_824CEAF8:
	// addi r1,r1,1264
	ctx.r1.s64 = ctx.r1.s64 + 1264;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_824CE978) {
	__imp__sub_824CE978(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CEB00) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x824CEB08;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	r26.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r26,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r26.u64);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x824e6400
	ctx.lr = 0x824CEB2C;
	sub_824E6400(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x824cecb4
	if (!cr6.eq) goto loc_824CECB4;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r25,r31,32
	r25.s64 = r31.s64 + 32;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cecb4
	if (!cr6.eq) goto loc_824CECB4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r6,24(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r5,20(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// addi r10,r11,22188
	ctx.r10.s64 = r11.s64 + 22188;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824c9d50
	ctx.lr = 0x824CEB68;
	sub_824C9D50(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824cecb4
	if (cr6.eq) goto loc_824CECB4;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CEB7C;
	sub_82481680(ctx, base);
	// ld r11,128(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// cmpld cr6,r11,r3
	cr6.compare<uint64_t>(r11.u64, ctx.r3.u64, xer);
	// bne cr6,0x824cecb4
	if (!cr6.eq) goto loc_824CECB4;
	// lwz r4,16(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481c00
	ctx.lr = 0x824CEB94;
	sub_82481C00(ctx, base);
	// lwz r11,1628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1628);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r29,r11,40
	r29.s64 = r11.s64 + 40;
	// bl 0x824c5df8
	ctx.lr = 0x824CEBB8;
	sub_824C5DF8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824cec94
	if (cr6.eq) goto loc_824CEC94;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824f97c0
	ctx.lr = 0x824CEBC8;
	sub_824F97C0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481448
	ctx.lr = 0x824CEBD4;
	sub_82481448(ctx, base);
	// cmpld cr6,r29,r3
	cr6.compare<uint64_t>(r29.u64, ctx.r3.u64, xer);
	// bne cr6,0x824cec94
	if (!cr6.eq) goto loc_824CEC94;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CEBE4;
	sub_82481680(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// addi r29,r1,208
	r29.s64 = ctx.r1.s64 + 208;
	// stb r11,124(r1)
	PPC_STORE_U8(ctx.r1.u32 + 124, r11.u8);
	// li r30,3
	r30.s64 = 3;
loc_824CEBF8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824CEC00;
	sub_824E71C8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bge 0x824cebf8
	if (!cr0.lt) goto loc_824CEBF8;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r11,4400
	ctx.r3.s64 = r11.s64 + 4400;
	// bl 0x82481378
	ctx.lr = 0x824CEC20;
	sub_82481378(ctx, base);
	// mr r30,r26
	r30.u64 = r26.u64;
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x824cec60
	if (!cr6.gt) goto loc_824CEC60;
	// addi r28,r1,88
	r28.s64 = ctx.r1.s64 + 88;
	// addi r29,r1,208
	r29.s64 = ctx.r1.s64 + 208;
loc_824CEC38:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82502300
	ctx.lr = 0x824CEC40;
	sub_82502300(ctx, base);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// std r11,0(r28)
	PPC_STORE_U64(r28.u32 + 0, r11.u64);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// lwz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x824cec38
	if (cr6.lt) goto loc_824CEC38;
loc_824CEC60:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8252e698
	ctx.lr = 0x824CEC6C;
	sub_8252E698(ctx, base);
	// addi r3,r31,1632
	ctx.r3.s64 = r31.s64 + 1632;
	// addi r4,r1,136
	ctx.r4.s64 = ctx.r1.s64 + 136;
	// li r5,60
	ctx.r5.s64 = 60;
	// bl 0x823da950
	ctx.lr = 0x824CEC7C;
	sub_823DA950(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824CEC8C;
	sub_821CE0A0(ctx, base);
	// stw r26,4(r25)
	PPC_STORE_U32(r25.u32 + 4, r26.u32);
	// b 0x824ceca4
	goto loc_824CECA4;
loc_824CEC94:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CEC9C;
	sub_82481680(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// stb r26,124(r1)
	PPC_STORE_U8(ctx.r1.u32 + 124, r26.u8);
loc_824CECA4:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x824cce98
	ctx.lr = 0x824CECB4;
	sub_824CCE98(ctx, base);
loc_824CECB4:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_824CEB00) {
	__imp__sub_824CEB00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CECBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CECBC) {
	__imp__sub_824CECBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CECC0) {
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
	ctx.lr = 0x824CECC8;
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// li r20,0
	r20.s64 = 0;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x824ced04
	if (cr6.eq) goto loc_824CED04;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x824ced04
	if (cr6.eq) goto loc_824CED04;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x824ced04
	if (cr6.eq) goto loc_824CED04;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r11,r20
	r11.u64 = r20.u64;
	// bne cr6,0x824ced08
	if (!cr6.eq) goto loc_824CED08;
loc_824CED04:
	// li r11,1
	r11.s64 = 1;
loc_824CED08:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cef90
	if (cr6.eq) goto loc_824CEF90;
	// lwz r11,4772(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4772);
	// mr r21,r20
	r21.u64 = r20.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,4772(r24)
	PPC_STORE_U32(r24.u32 + 4772, r11.u32);
	// ld r4,80(r23)
	ctx.r4.u64 = PPC_LOAD_U64(r23.u32 + 80);
	// lbz r10,92(r23)
	ctx.r10.u64 = PPC_LOAD_U8(r23.u32 + 92);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,92(r23)
	PPC_STORE_U8(r23.u32 + 92, ctx.r9.u8);
	// lwz r3,12(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// bl 0x82481b70
	ctx.lr = 0x824CED3C;
	sub_82481B70(ctx, base);
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x824ced54
	if (!cr6.eq) goto loc_824CED54;
	// li r21,1
	r21.s64 = 1;
	// b 0x824ceec0
	goto loc_824CEEC0;
loc_824CED54:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x824ceec0
	if (!cr6.eq) goto loc_824CEEC0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824c5df8
	ctx.lr = 0x824CED64;
	sub_824C5DF8(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r10,r11,22540
	ctx.r10.s64 = r11.s64 + 22540;
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x824cb9f8
	ctx.lr = 0x824CED84;
	sub_824CB9F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824ceec0
	if (cr6.eq) goto loc_824CEEC0;
	// lbz r10,124(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 124);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824ceda4
	if (!cr6.eq) goto loc_824CEDA4;
	// li r21,1
	r21.s64 = 1;
	// b 0x824ceec0
	goto loc_824CEEC0;
loc_824CEDA4:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824ceec0
	if (cr6.eq) goto loc_824CEEC0;
	// lbz r11,92(r23)
	r11.u64 = PPC_LOAD_U8(r23.u32 + 92);
	// addi r30,r1,240
	r30.s64 = ctx.r1.s64 + 240;
	// li r31,3
	r31.s64 = 3;
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,92(r23)
	PPC_STORE_U8(r23.u32 + 92, ctx.r10.u8);
loc_824CEDC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e71c8
	ctx.lr = 0x824CEDC8;
	sub_824E71C8(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,96
	r30.s64 = r30.s64 + 96;
	// bge 0x824cedc0
	if (!cr0.lt) goto loc_824CEDC0;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82481378
	ctx.lr = 0x824CEDE4;
	sub_82481378(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// li r31,3
	r31.s64 = 3;
loc_824CEDF0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x824CEDF8;
	sub_824F0498(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x824cedf0
	if (!cr0.lt) goto loc_824CEDF0;
	// mr r25,r20
	r25.u64 = r20.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x824ceec0
	if (!cr6.gt) goto loc_824CEEC0;
	// addi r26,r1,128
	r26.s64 = ctx.r1.s64 + 128;
	// addi r28,r1,240
	r28.s64 = ctx.r1.s64 + 240;
loc_824CEE18:
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r27,r20
	r27.u64 = r20.u64;
	// mr r31,r20
	r31.u64 = r20.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824cee68
	if (!cr6.gt) goto loc_824CEE68;
	// addi r30,r1,88
	r30.s64 = ctx.r1.s64 + 88;
loc_824CEE30:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82502300
	ctx.lr = 0x824CEE38;
	sub_82502300(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824f0550
	ctx.lr = 0x824CEE40;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cee64
	if (!cr6.eq) goto loc_824CEE64;
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x824cee30
	if (cr6.lt) goto loc_824CEE30;
	// b 0x824cee68
	goto loc_824CEE68;
loc_824CEE64:
	// li r27,1
	r27.s64 = 1;
loc_824CEE68:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cee8c
	if (!cr6.eq) goto loc_824CEE8C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82502300
	ctx.lr = 0x824CEE7C;
	sub_82502300(ctx, base);
	// ld r11,0(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// std r11,0(r26)
	PPC_STORE_U64(r26.u32 + 0, r11.u64);
	// addi r26,r26,8
	r26.s64 = r26.s64 + 8;
loc_824CEE8C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,96
	r28.s64 = r28.s64 + 96;
	// bne 0x824cee18
	if (!cr0.eq) goto loc_824CEE18;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// beq cr6,0x824ceec0
	if (cr6.eq) goto loc_824CEEC0;
	// lwz r3,12(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r4,r3,4400
	ctx.r4.s64 = ctx.r3.s64 + 4400;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// bl 0x82487da0
	ctx.lr = 0x824CEEC0;
	sub_82487DA0(ctx, base);
loc_824CEEC0:
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cef70
	if (cr6.eq) goto loc_824CEF70;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x824cef70
	if (cr6.eq) goto loc_824CEF70;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82618670
	ctx.lr = 0x824CEEDC;
	sub_82618670(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824cef70
	if (cr6.lt) goto loc_824CEF70;
	// lwz r11,88(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 88);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,88(r23)
	PPC_STORE_U32(r23.u32 + 88, r11.u32);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bge cr6,0x824cef70
	if (!cr6.lt) goto loc_824CEF70;
	// std r20,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, r20.u64);
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// bl 0x824e6400
	ctx.lr = 0x824CEF04;
	sub_824E6400(ctx, base);
	// lwz r3,12(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// bl 0x82481618
	ctx.lr = 0x824CEF0C;
	sub_82481618(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,12(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CEF18;
	sub_82481680(ctx, base);
	// std r3,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.r3.u64);
	// addi r3,r1,168
	ctx.r3.s64 = ctx.r1.s64 + 168;
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x823da950
	ctx.lr = 0x824CEF2C;
	sub_823DA950(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r31,4828(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 4828);
	// addi r30,r1,160
	r30.s64 = ctx.r1.s64 + 160;
	// bl 0x82618670
	ctx.lr = 0x824CEF3C;
	sub_82618670(ctx, base);
	// lwz r11,12(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 12);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,4552
	ctx.r3.s64 = r11.s64 + 4552;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// bl 0x824cce10
	ctx.lr = 0x824CEF58;
	sub_824CCE10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cef70
	if (cr6.eq) goto loc_824CEF70;
	// lwz r11,4772(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4772);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4772(r24)
	PPC_STORE_U32(r24.u32 + 4772, r11.u32);
loc_824CEF70:
	// lwz r11,4772(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 4772);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824cef90
	if (!cr6.eq) goto loc_824CEF90;
	// addi r3,r24,32
	ctx.r3.s64 = r24.s64 + 32;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824CEF8C;
	sub_821CE0A0(ctx, base);
	// stw r20,36(r24)
	PPC_STORE_U32(r24.u32 + 36, r20.u32);
loc_824CEF90:
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_824CECC0) {
	__imp__sub_824CECC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CEF98) {
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
	ctx.lr = 0x824CEFA0;
	// stwu r1,-2192(r1)
	ea = -2192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824cf098
	if (!cr6.gt) goto loc_824CF098;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r29,11396
	r28.s64 = r29.s64 + 11396;
	// addi r26,r11,22444
	r26.s64 = r11.s64 + 22444;
loc_824CEFCC:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618670
	ctx.lr = 0x824CEFD8;
	sub_82618670(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824cf084
	if (cr6.lt) goto loc_824CF084;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824cf000
	if (cr6.eq) goto loc_824CF000;
	// addi r4,r24,8
	ctx.r4.s64 = r24.s64 + 8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824f9950
	ctx.lr = 0x824CEFF4;
	sub_824F9950(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cf084
	if (!cr6.eq) goto loc_824CF084;
loc_824CF000:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r6,999
	ctx.r6.s64 = 999;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ca308
	ctx.lr = 0x824CF01C;
	sub_824CA308(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf084
	if (cr6.eq) goto loc_824CF084;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1006
	ctx.r4.s64 = 1006;
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// bl 0x8252e178
	ctx.lr = 0x824CF038;
	sub_8252E178(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cf084
	if (cr6.eq) goto loc_824CF084;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r31,r3,r5
	r31.u64 = ctx.r3.u64 + ctx.r5.u64;
	// cmplwi cr6,r31,1006
	cr6.compare<uint32_t>(r31.u32, 1006, xer);
	// bgt cr6,0x824cf084
	if (cr6.gt) goto loc_824CF084;
	// addi r11,r1,1104
	r11.s64 = ctx.r1.s64 + 1104;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824CF060;
	sub_8244D5C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cf084
	if (cr6.eq) goto loc_824CF084;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,1104
	ctx.r5.s64 = ctx.r1.s64 + 1104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r29,4552
	ctx.r3.s64 = r29.s64 + 4552;
	// bl 0x8252eaa0
	ctx.lr = 0x824CF084;
	sub_8252EAA0(ctx, base);
loc_824CF084:
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x824cefcc
	if (cr6.lt) goto loc_824CEFCC;
loc_824CF098:
	// addi r1,r1,2192
	ctx.r1.s64 = ctx.r1.s64 + 2192;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_824CEF98) {
	__imp__sub_824CEF98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF0A0) {
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
	ctx.lr = 0x824CF0A8;
	// stwu r1,-2192(r1)
	ea = -2192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824cf1a0
	if (!cr6.gt) goto loc_824CF1A0;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r29,11396
	r28.s64 = r29.s64 + 11396;
	// addi r26,r11,22284
	r26.s64 = r11.s64 + 22284;
loc_824CF0D4:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618670
	ctx.lr = 0x824CF0E0;
	sub_82618670(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824cf18c
	if (cr6.lt) goto loc_824CF18C;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824cf108
	if (cr6.eq) goto loc_824CF108;
	// addi r4,r24,8
	ctx.r4.s64 = r24.s64 + 8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824f9950
	ctx.lr = 0x824CF0FC;
	sub_824F9950(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cf18c
	if (!cr6.eq) goto loc_824CF18C;
loc_824CF108:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r6,999
	ctx.r6.s64 = 999;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ca3c0
	ctx.lr = 0x824CF124;
	sub_824CA3C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf18c
	if (cr6.eq) goto loc_824CF18C;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1006
	ctx.r4.s64 = 1006;
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// bl 0x8252e178
	ctx.lr = 0x824CF140;
	sub_8252E178(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cf18c
	if (cr6.eq) goto loc_824CF18C;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r31,r3,r5
	r31.u64 = ctx.r3.u64 + ctx.r5.u64;
	// cmplwi cr6,r31,1006
	cr6.compare<uint32_t>(r31.u32, 1006, xer);
	// bgt cr6,0x824cf18c
	if (cr6.gt) goto loc_824CF18C;
	// addi r11,r1,1104
	r11.s64 = ctx.r1.s64 + 1104;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824CF168;
	sub_8244D5C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cf18c
	if (cr6.eq) goto loc_824CF18C;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,1104
	ctx.r5.s64 = ctx.r1.s64 + 1104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r29,4552
	ctx.r3.s64 = r29.s64 + 4552;
	// bl 0x8252eaa0
	ctx.lr = 0x824CF18C;
	sub_8252EAA0(ctx, base);
loc_824CF18C:
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x824cf0d4
	if (cr6.lt) goto loc_824CF0D4;
loc_824CF1A0:
	// addi r1,r1,2192
	ctx.r1.s64 = ctx.r1.s64 + 2192;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_824CF0A0) {
	__imp__sub_824CF0A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF1A8) {
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
	ctx.lr = 0x824CF1B0;
	// stwu r1,-2192(r1)
	ea = -2192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x824cf2a8
	if (!cr6.gt) goto loc_824CF2A8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r28,r29,11396
	r28.s64 = r29.s64 + 11396;
	// addi r26,r11,22220
	r26.s64 = r11.s64 + 22220;
loc_824CF1DC:
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618670
	ctx.lr = 0x824CF1E8;
	sub_82618670(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x824cf294
	if (cr6.lt) goto loc_824CF294;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824cf210
	if (cr6.eq) goto loc_824CF210;
	// addi r4,r24,8
	ctx.r4.s64 = r24.s64 + 8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x824f9950
	ctx.lr = 0x824CF204;
	sub_824F9950(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cf294
	if (!cr6.eq) goto loc_824CF294;
loc_824CF210:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,8(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r6,999
	ctx.r6.s64 = 999;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824ca478
	ctx.lr = 0x824CF22C;
	sub_824CA478(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf294
	if (cr6.eq) goto loc_824CF294;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1006
	ctx.r4.s64 = 1006;
	// addi r3,r1,1104
	ctx.r3.s64 = ctx.r1.s64 + 1104;
	// bl 0x8252e178
	ctx.lr = 0x824CF248;
	sub_8252E178(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cf294
	if (cr6.eq) goto loc_824CF294;
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// add r31,r3,r5
	r31.u64 = ctx.r3.u64 + ctx.r5.u64;
	// cmplwi cr6,r31,1006
	cr6.compare<uint32_t>(r31.u32, 1006, xer);
	// bgt cr6,0x824cf294
	if (cr6.gt) goto loc_824CF294;
	// addi r11,r1,1104
	r11.s64 = ctx.r1.s64 + 1104;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// add r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 + r11.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x824CF270;
	sub_8244D5C0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cf294
	if (cr6.eq) goto loc_824CF294;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r1,1104
	ctx.r5.s64 = ctx.r1.s64 + 1104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r29,4552
	ctx.r3.s64 = r29.s64 + 4552;
	// bl 0x8252eaa0
	ctx.lr = 0x824CF294;
	sub_8252EAA0(ctx, base);
loc_824CF294:
	// lwz r11,11524(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11524);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// blt cr6,0x824cf1dc
	if (cr6.lt) goto loc_824CF1DC;
loc_824CF2A8:
	// addi r1,r1,2192
	ctx.r1.s64 = ctx.r1.s64 + 2192;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_824CF1A8) {
	__imp__sub_824CF1A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF2B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	ctx.lr = 0x824CF2B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r27,1
	r27.s64 = 1;
	// li r30,3
	r30.s64 = 3;
	// li r28,4
	r28.s64 = 4;
loc_824CF2D0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x824cf3f8
	if (cr6.gt) goto loc_824CF3F8;
	// lis r12,-32179
	r12.s64 = -2108882944;
	// addi r12,r12,-3340
	r12.s64 = r12.s64 + -3340;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-3320(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -3320);
	// lwz r18,-3284(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -3284);
	// lwz r18,-3192(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -3192);
	// lwz r18,-3172(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -3172);
	// lwz r18,-3144(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -3144);
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cf31c
	if (!cr6.eq) goto loc_824CF31C;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// b 0x824cf3f8
	goto loc_824CF3F8;
loc_824CF31C:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cf3f8
	if (cr6.eq) goto loc_824CF3F8;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// b 0x824cf3f8
	goto loc_824CF3F8;
	// addi r3,r31,40
	ctx.r3.s64 = r31.s64 + 40;
	// bl 0x82502300
	ctx.lr = 0x824CF334;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824825c0
	ctx.lr = 0x824CF340;
	sub_824825C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf3e0
	if (cr6.eq) goto loc_824CF3E0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481580
	ctx.lr = 0x824CF354;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cf368
	if (!cr6.eq) goto loc_824CF368;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cf3e4
	goto loc_824CF3E4;
loc_824CF368:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824cd1d8
	ctx.lr = 0x824CF370;
	sub_824CD1D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// b 0x824cf3f8
	goto loc_824CF3F8;
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cf31c
	if (!cr6.eq) goto loc_824CF31C;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cf3e4
	goto loc_824CF3E4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ca718
	ctx.lr = 0x824CF3A4;
	sub_824CA718(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf3e0
	if (cr6.eq) goto loc_824CF3E0;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// b 0x824cf3f8
	goto loc_824CF3F8;
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cf3e0
	if (!cr6.eq) goto loc_824CF3E0;
	// lwz r11,736(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 736);
	// addi r3,r31,736
	ctx.r3.s64 = r31.s64 + 736;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF3DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cf3f8
	goto loc_824CF3F8;
loc_824CF3E0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_824CF3E4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF3F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CF3F8:
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cf418
	if (cr6.eq) goto loc_824CF418;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CF40C;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cf2d0
	if (!cr6.eq) goto loc_824CF2D0;
loc_824CF418:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CF2B0) {
	__imp__sub_824CF2B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF420) {
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
	ctx.lr = 0x824CF428;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r11,8(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 8);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824cf45c
	if (!cr6.eq) goto loc_824CF45C;
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cf45c
	if (cr6.eq) goto loc_824CF45C;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// rlwinm r11,r11,0,27,24
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFF9F;
	// ori r10,r11,64
	ctx.r10.u64 = r11.u64 | 64;
	// stb r10,8(r29)
	PPC_STORE_U8(r29.u32 + 8, ctx.r10.u8);
loc_824CF45C:
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CF464;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf4fc
	if (cr6.eq) goto loc_824CF4FC;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x82481688
	ctx.lr = 0x824CF478;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf4e4
	if (cr6.eq) goto loc_824CF4E4;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r1,88
	r30.s64 = ctx.r1.s64 + 88;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// li r31,31
	r31.s64 = 31;
loc_824CF494:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f0498
	ctx.lr = 0x824CF49C;
	sub_824F0498(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bge 0x824cf494
	if (!cr0.lt) goto loc_824CF494;
	// addi r3,r29,40
	ctx.r3.s64 = r29.s64 + 40;
	// bl 0x82502300
	ctx.lr = 0x824CF4B0;
	sub_82502300(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CF4BC;
	sub_82481680(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r11.u32);
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x82485e80
	ctx.lr = 0x824CF4E0;
	sub_82485E80(ctx, base);
	// b 0x824cf4fc
	goto loc_824CF4FC;
loc_824CF4E4:
	// addi r4,r29,40
	ctx.r4.s64 = r29.s64 + 40;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x824825f0
	ctx.lr = 0x824CF4F0;
	sub_824825F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf514
	if (cr6.eq) goto loc_824CF514;
loc_824CF4FC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CF514:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CF420) {
	__imp__sub_824CF420(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF51C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CF51C) {
	__imp__sub_824CF51C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF520) {
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
	ctx.lr = 0x824CF528;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r29,-1
	r29.s64 = -1;
	// addi r8,r10,14420
	ctx.r8.s64 = ctx.r10.s64 + 14420;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// stb r6,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r6.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// bl 0x824e71c8
	ctx.lr = 0x824CF584;
	sub_824E71C8(ctx, base);
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// stw r30,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r30.u32);
	// addi r3,r31,1184
	ctx.r3.s64 = r31.s64 + 1184;
	// stw r30,664(r31)
	PPC_STORE_U32(r31.u32 + 664, r30.u32);
	// stw r29,1180(r31)
	PPC_STORE_U32(r31.u32 + 1180, r29.u32);
	// bl 0x824ebf78
	ctx.lr = 0x824CF59C;
	sub_824EBF78(ctx, base);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// bl 0x824cc340
	ctx.lr = 0x824CF5A4;
	sub_824CC340(ctx, base);
	// lis r5,-32179
	ctx.r5.s64 = -2108882944;
	// stw r30,1184(r31)
	PPC_STORE_U32(r31.u32 + 1184, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,-9456
	ctx.r4.s64 = ctx.r5.s64 + -9456;
	// stw r4,1188(r31)
	PPC_STORE_U32(r31.u32 + 1188, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x824CF5BC;
	sub_82130000(ctx, base);
	// stw r3,1184(r31)
	PPC_STORE_U32(r31.u32 + 1184, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CF520) {
	__imp__sub_824CF520(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF5CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CF5CC) {
	__imp__sub_824CF5CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF5D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	ctx.lr = 0x824CF5D8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481688
	ctx.lr = 0x824CF5EC;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cf618
	if (!cr6.eq) goto loc_824CF618;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
loc_824CF618:
	// li r27,2
	r27.s64 = 2;
	// li r25,1
	r25.s64 = 1;
	// li r29,10
	r29.s64 = 10;
	// li r22,3
	r22.s64 = 3;
	// li r23,4
	r23.s64 = 4;
	// li r24,5
	r24.s64 = 5;
	// li r26,11
	r26.s64 = 11;
loc_824CF634:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// bgt cr6,0x824cf974
	if (cr6.gt) goto loc_824CF974;
	// lis r12,-32179
	r12.s64 = -2108882944;
	// addi r12,r12,-2472
	r12.s64 = r12.s64 + -2472;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-2424(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -2424);
	// lwz r18,-2328(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -2328);
	// lwz r18,-2272(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -2272);
	// lwz r18,-2196(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -2196);
	// lwz r18,-2152(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -2152);
	// lwz r18,-2008(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -2008);
	// lwz r18,-1964(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -1964);
	// lwz r18,-2064(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -2064);
	// lwz r18,-1916(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -1916);
	// lwz r18,-1828(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -1828);
	// lwz r18,-1808(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -1808);
	// lwz r18,-1740(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -1740);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824817c0
	ctx.lr = 0x824CF690;
	sub_824817C0(ctx, base);
	// lwz r11,532(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 532);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cf6a8
	if (cr6.eq) goto loc_824CF6A8;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// b 0x824cf974
	goto loc_824CF974;
loc_824CF6A8:
	// addi r30,r31,3124
	r30.s64 = r31.s64 + 3124;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824c9310
	ctx.lr = 0x824CF6C0;
	sub_824C9310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf790
	if (cr6.eq) goto loc_824CF790;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r25,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r25.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cf6fc
	if (!cr6.eq) goto loc_824CF6FC;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// b 0x824cf974
	goto loc_824CF974;
loc_824CF6FC:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cf790
	if (!cr6.eq) goto loc_824CF790;
	// lwz r11,3124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3124);
	// addi r3,r31,3124
	ctx.r3.s64 = r31.s64 + 3124;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF71C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252cfa8
	ctx.lr = 0x824CF72C;
	sub_8252CFA8(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,2264
	ctx.r4.s64 = r11.s64 + 2264;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252d800
	ctx.lr = 0x824CF73C;
	sub_8252D800(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf790
	if (cr6.eq) goto loc_824CF790;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252d8a8
	ctx.lr = 0x824CF758;
	sub_8252D8A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf790
	if (cr6.eq) goto loc_824CF790;
	// stw r22,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r22.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cf788
	if (!cr6.eq) goto loc_824CF788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ce200
	ctx.lr = 0x824CF780;
	sub_824CE200(ctx, base);
	// stw r23,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r23.u32);
	// b 0x824cf974
	goto loc_824CF974;
loc_824CF788:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cf974
	if (cr6.eq) goto loc_824CF974;
loc_824CF790:
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cf974
	if (cr6.eq) goto loc_824CF974;
	// lwz r11,3120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3120);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824cf7cc
	if (!cr6.eq) goto loc_824CF7CC;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481588
	ctx.lr = 0x824CF7B8;
	sub_82481588(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cf7cc
	if (cr6.eq) goto loc_824CF7CC;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// b 0x824cf974
	goto loc_824CF974;
loc_824CF7CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c64a8
	ctx.lr = 0x824CF7D4;
	sub_824C64A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,31,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// addi r8,r11,10
	ctx.r8.s64 = r11.s64 + 10;
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cf818
	if (!cr6.eq) goto loc_824CF818;
	// lwz r11,3168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3168);
	// addi r3,r31,3168
	ctx.r3.s64 = r31.s64 + 3168;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF814;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cf974
	goto loc_824CF974;
loc_824CF818:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cf790
	if (!cr6.eq) goto loc_824CF790;
	// stw r24,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r24.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252d240
	ctx.lr = 0x824CF838;
	sub_8252D240(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFC;
	// addi r8,r11,10
	ctx.r8.s64 = r11.s64 + 10;
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cf788
	if (!cr6.eq) goto loc_824CF788;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c64a8
	ctx.lr = 0x824CF868;
	sub_824C64A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r8,r11,10
	ctx.r8.s64 = r11.s64 + 10;
	// stw r8,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r8.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cf8b0
	if (!cr6.eq) goto loc_824CF8B0;
	// lwz r11,3168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3168);
	// addi r3,r31,3168
	ctx.r3.s64 = r31.s64 + 3168;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF8AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cf974
	goto loc_824CF974;
loc_824CF8B0:
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cf790
	if (!cr6.eq) goto loc_824CF790;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x8252dcd8
	ctx.lr = 0x824CF8C4;
	sub_8252DCD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r9,r11,9
	ctx.r9.s64 = r11.s64 + 9;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cf788
	if (!cr6.eq) goto loc_824CF788;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cf960
	goto loc_824CF960;
	// lbz r11,3472(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3472);
	// addi r30,r31,3124
	r30.s64 = r31.s64 + 3124;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r5,r11,25,7,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824c9310
	ctx.lr = 0x824CF90C;
	sub_824C9310(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cf95c
	if (cr6.eq) goto loc_824CF95C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF92C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// b 0x824cf974
	goto loc_824CF974;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cf95c
	if (!cr6.eq) goto loc_824CF95C;
	// lwz r11,3124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3124);
	// addi r3,r31,3124
	ctx.r3.s64 = r31.s64 + 3124;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824cf974
	goto loc_824CF974;
loc_824CF95C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_824CF960:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CF974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CF974:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cf994
	if (cr6.eq) goto loc_824CF994;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CF988;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cf634
	if (!cr6.eq) goto loc_824CF634;
loc_824CF994:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_824CF5D0) {
	__imp__sub_824CF5D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF99C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CF99C) {
	__imp__sub_824CF99C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CF9A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x824CF9A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r27,-1
	r27.s64 = -1;
	// addi r8,r10,14780
	ctx.r8.s64 = ctx.r10.s64 + 14780;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// addi r28,r31,40
	r28.s64 = r31.s64 + 40;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r29,32
	r29.s64 = 32;
	// clrlwi r9,r11,27
	ctx.r9.u64 = r11.u32 & 0x1F;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lbz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 24);
	// ori r6,r7,128
	ctx.r6.u64 = ctx.r7.u64 | 128;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// stb r6,24(r31)
	PPC_STORE_U8(r31.u32 + 24, ctx.r6.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r30,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r30.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
loc_824CFA00:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x824f99c0
	ctx.lr = 0x824CFA08;
	sub_824F99C0(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,48
	r28.s64 = r28.s64 + 48;
	// bge 0x824cfa00
	if (!cr0.lt) goto loc_824CFA00;
	// stw r30,1624(r31)
	PPC_STORE_U32(r31.u32 + 1624, r30.u32);
	// addi r3,r31,1632
	ctx.r3.s64 = r31.s64 + 1632;
	// stw r27,1628(r31)
	PPC_STORE_U32(r31.u32 + 1628, r27.u32);
	// bl 0x824e6400
	ctx.lr = 0x824CFA24;
	sub_824E6400(ctx, base);
	// addi r27,r31,1696
	r27.s64 = r31.s64 + 1696;
	// li r28,31
	r28.s64 = 31;
	// mr r29,r27
	r29.u64 = r27.u64;
loc_824CFA30:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8252f1a8
	ctx.lr = 0x824CFA38;
	sub_8252F1A8(ctx, base);
	// lbz r11,92(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 92);
	// std r30,80(r29)
	PPC_STORE_U64(r29.u32 + 80, r30.u64);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r30,88(r29)
	PPC_STORE_U32(r29.u32 + 88, r30.u32);
	// stb r10,92(r29)
	PPC_STORE_U8(r29.u32 + 92, ctx.r10.u8);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bge 0x824cfa30
	if (!cr0.lt) goto loc_824CFA30;
	// stw r30,4768(r31)
	PPC_STORE_U32(r31.u32 + 4768, r30.u32);
	// addi r3,r31,4780
	ctx.r3.s64 = r31.s64 + 4780;
	// stw r30,4772(r31)
	PPC_STORE_U32(r31.u32 + 4772, r30.u32);
	// stw r30,4776(r31)
	PPC_STORE_U32(r31.u32 + 4776, r30.u32);
	// bl 0x8252e7a8
	ctx.lr = 0x824CFA6C;
	sub_8252E7A8(ctx, base);
	// lis r11,-32179
	r11.s64 = -2108882944;
	// stw r30,4828(r31)
	PPC_STORE_U32(r31.u32 + 4828, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-5376
	ctx.r10.s64 = r11.s64 + -5376;
	// stw r30,4832(r31)
	PPC_STORE_U32(r31.u32 + 4832, r30.u32);
	// stw r30,4780(r31)
	PPC_STORE_U32(r31.u32 + 4780, r30.u32);
	// stw r10,4784(r31)
	PPC_STORE_U32(r31.u32 + 4784, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x824CFA8C;
	sub_82130000(ctx, base);
	// stw r3,4780(r31)
	PPC_STORE_U32(r31.u32 + 4780, ctx.r3.u32);
	// mr r29,r27
	r29.u64 = r27.u64;
	// li r28,32
	r28.s64 = 32;
loc_824CFA98:
	// lis r11,-32179
	r11.s64 = -2108882944;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-4928
	ctx.r10.s64 = r11.s64 + -4928;
	// stw r10,4(r29)
	PPC_STORE_U32(r29.u32 + 4, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x824CFAB0;
	sub_82130000(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bne 0x824cfa98
	if (!cr0.eq) goto loc_824CFA98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824CF9A0) {
	__imp__sub_824CF9A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CFACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CFACC) {
	__imp__sub_824CFACC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CFAD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r18{};
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
	ctx.lr = 0x824CFAD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// li r26,2
	r26.s64 = 2;
	// li r27,1
	r27.s64 = 1;
loc_824CFAF0:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x824cfb60
	if (cr6.gt) goto loc_824CFB60;
	// lis r12,-32179
	r12.s64 = -2108882944;
	// addi r12,r12,-1260
	r12.s64 = r12.s64 + -1260;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r18,-1244(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -1244);
	// lwz r18,-1144(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -1144);
	// lwz r18,-1004(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -1004);
	// lwz r18,-976(r12)
	r18.u64 = PPC_LOAD_U32(r12.u32 + -976);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c8b40
	ctx.lr = 0x824CFB2C;
	sub_824C8B40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cfb60
	if (!cr6.eq) goto loc_824CFB60;
	// lwz r11,1628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1628);
	// lwz r10,1624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1624);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x824cfb60
	if (cr6.lt) goto loc_824CFB60;
loc_824CFB48:
	// li r4,0
	ctx.r4.s64 = 0;
loc_824CFB4C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824CFB60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824CFB60:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cfb80
	if (cr6.eq) goto loc_824CFB80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481098
	ctx.lr = 0x824CFB74;
	sub_82481098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cfaf0
	if (!cr6.eq) goto loc_824CFAF0;
loc_824CFB80:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cfc04
	if (!cr6.eq) goto loc_824CFC04;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481688
	ctx.lr = 0x824CFB9C;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824cfbe4
	if (!cr6.eq) goto loc_824CFBE4;
	// lwz r11,1628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1628);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x824f97c0
	ctx.lr = 0x824CFBC4;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82483b28
	ctx.lr = 0x824CFBD0;
	sub_82483B28(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cfc0c
	if (cr6.eq) goto loc_824CFC0C;
loc_824CFBDC:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cfb4c
	goto loc_824CFB4C;
loc_824CFBE4:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481908
	ctx.lr = 0x824CFBEC;
	sub_82481908(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824cfbdc
	if (cr6.eq) goto loc_824CFBDC;
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824ce978
	ctx.lr = 0x824CFC00;
	sub_824CE978(ctx, base);
	// b 0x824cfb60
	goto loc_824CFB60;
loc_824CFC04:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cfb60
	if (cr6.eq) goto loc_824CFB60;
loc_824CFC0C:
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// b 0x824cfb60
	goto loc_824CFB60;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x824cfb60
	if (cr6.eq) goto loc_824CFB60;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824c66e0
	ctx.lr = 0x824CFC28;
	sub_824C66E0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x824cfb4c
	goto loc_824CFB4C;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r29,r31,32
	r29.s64 = r31.s64 + 32;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x824cfca0
	if (!cr6.eq) goto loc_824CFCA0;
	// lwz r11,1628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1628);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r30,r11,40
	r30.s64 = r11.s64 + 40;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82481628
	ctx.lr = 0x824CFC64;
	sub_82481628(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,2264
	ctx.r3.s64 = r11.s64 + 2264;
	// li r5,0
	ctx.r5.s64 = 0;
	// bne cr6,0x824cfc88
	if (!cr6.eq) goto loc_824CFC88;
	// addi r5,r31,1632
	ctx.r5.s64 = r31.s64 + 1632;
loc_824CFC88:
	// bl 0x824e2930
	ctx.lr = 0x824CFC8C;
	sub_824E2930(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cfb48
	if (cr6.eq) goto loc_824CFB48;
	// stw r27,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r27.u32);
	// b 0x824cfb60
	goto loc_824CFB60;
loc_824CFCA0:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x824cfb48
	if (!cr6.eq) goto loc_824CFB48;
	// lwz r11,1628(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1628);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,40
	ctx.r3.s64 = r11.s64 + 40;
	// bl 0x824f97c0
	ctx.lr = 0x824CFCC4;
	sub_824F97C0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82483b28
	ctx.lr = 0x824CFCD0;
	sub_82483B28(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824cfcf8
	if (!cr6.eq) goto loc_824CFCF8;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824CFCEC;
	sub_821CE0A0(ctx, base);
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// b 0x824cfb60
	goto loc_824CFB60;
loc_824CFCF8:
	// lwz r11,4832(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4832);
	// subf. r10,r25,r11
	ctx.r10.s64 = r11.s64 - r25.s64;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,4832(r31)
	PPC_STORE_U32(r31.u32 + 4832, ctx.r10.u32);
	// bgt 0x824cfb60
	if (cr0.gt) goto loc_824CFB60;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ce0a0
	ctx.lr = 0x824CFD18;
	sub_821CE0A0(ctx, base);
	// stw r28,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r28.u32);
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// b 0x824cfb60
	goto loc_824CFB60;
}

PPC_WEAK_FUNC(sub_824CFAD0) {
	__imp__sub_824CFAD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CFD24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CFD24) {
	__imp__sub_824CFD24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CFD28) {
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
	ctx.lr = 0x824CFD30;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cfdf0
	if (cr6.eq) goto loc_824CFDF0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CFD54;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cfdf0
	if (cr6.eq) goto loc_824CFDF0;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481688
	ctx.lr = 0x824CFD68;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cfdb4
	if (cr6.eq) goto loc_824CFDB4;
	// std r30,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r30.u64);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824e8de8
	ctx.lr = 0x824CFD80;
	sub_824E8DE8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824817c0
	ctx.lr = 0x824CFD88;
	sub_824817C0(ctx, base);
	// addi r28,r3,12
	r28.s64 = ctx.r3.s64 + 12;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CFD94;
	sub_82481680(ctx, base);
	// std r3,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r3.u64);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x824ea350
	ctx.lr = 0x824CFDA4;
	sub_824EA350(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824cef98
	ctx.lr = 0x824CFDB4;
	sub_824CEF98(ctx, base);
loc_824CFDB4:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r28,r11,-8452
	r28.s64 = r11.s64 + -8452;
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r10,13928
	ctx.r9.s64 = ctx.r10.s64 + 13928;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r3,r4,11532
	ctx.r3.s64 = ctx.r4.s64 + 11532;
	// bl 0x824e7db8
	ctx.lr = 0x824CFDEC;
	sub_824E7DB8(ctx, base);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
loc_824CFDF0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CFDFC;
	sub_824810C8(ctx, base);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824CFD28) {
	__imp__sub_824CFD28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CFE08) {
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
	ctx.lr = 0x824CFE10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cfe84
	if (cr6.eq) goto loc_824CFE84;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CFE30;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cfe84
	if (cr6.eq) goto loc_824CFE84;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481688
	ctx.lr = 0x824CFE44;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cfe84
	if (cr6.eq) goto loc_824CFE84;
	// lbz r11,36(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cfe84
	if (cr6.eq) goto loc_824CFE84;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rlwinm r29,r11,25,31,31
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1;
	// bl 0x82481680
	ctx.lr = 0x824CFE6C;
	sub_82481680(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// stb r29,88(r1)
	PPC_STORE_U8(ctx.r1.u32 + 88, r29.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824cf0a0
	ctx.lr = 0x824CFE84;
	sub_824CF0A0(ctx, base);
loc_824CFE84:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824810c8
	ctx.lr = 0x824CFE90;
	sub_824810C8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824CFE08) {
	__imp__sub_824CFE08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CFEA0) {
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
	ctx.lr = 0x824CFEA8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r28,r4,24
	r28.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x824cff74
	if (cr6.eq) goto loc_824CFF74;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481578
	ctx.lr = 0x824CFEC8;
	sub_82481578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cff74
	if (cr6.eq) goto loc_824CFF74;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481688
	ctx.lr = 0x824CFEDC;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824cff24
	if (cr6.eq) goto loc_824CFF24;
	// lbz r11,44(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 44);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824cff24
	if (cr6.eq) goto loc_824CFF24;
	// lwz r30,40(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r29,36(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82481680
	ctx.lr = 0x824CFF08;
	sub_82481680(ctx, base);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824cf1a8
	ctx.lr = 0x824CFF24;
	sub_824CF1A8(ctx, base);
loc_824CFF24:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r30,r27
	r30.u64 = r27.u64;
	// lwz r10,8308(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8308);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x824cff74
	if (!cr6.gt) goto loc_824CFF74;
	// li r29,8180
	r29.s64 = 8180;
loc_824CFF3C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r26,r11,r29
	r26.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82502300
	ctx.lr = 0x824CFF4C;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82482520
	ctx.lr = 0x824CFF58;
	sub_82482520(ctx, base);
	// stw r3,96(r26)
	PPC_STORE_U32(r26.u32 + 96, ctx.r3.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// lwz r9,8308(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8308);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x824cff3c
	if (cr6.lt) goto loc_824CFF3C;
loc_824CFF74:
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824cffb0
	if (cr6.eq) goto loc_824CFFB0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x824cffa0
	if (cr6.eq) goto loc_824CFFA0;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x821ce0a0
	ctx.lr = 0x824CFF98;
	sub_821CE0A0(ctx, base);
	// stw r27,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r27.u32);
	// b 0x824cffb0
	goto loc_824CFFB0;
loc_824CFFA0:
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x821ce0a0
	ctx.lr = 0x824CFFA8;
	sub_821CE0A0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
loc_824CFFB0:
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// stw r27,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r27.u32);
	// clrlwi r10,r11,25
	ctx.r10.u64 = r11.u32 & 0x7F;
	// stw r27,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r27.u32);
	// rlwinm r10,r10,0,27,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,8(r31)
	PPC_STORE_U8(r31.u32 + 8, ctx.r9.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824CFEA0) {
	__imp__sub_824CFEA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CFFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824CFFD4) {
	__imp__sub_824CFFD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824CFFD8) {
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
	// bl 0x821a5cc0
	ctx.lr = 0x824CFFF0;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d0000
	if (cr6.eq) goto loc_824D0000;
	// bl 0x821bbea8
	ctx.lr = 0x824D0000;
	sub_821BBEA8(ctx, base);
loc_824D0000:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29868
	ctx.r4.s64 = r11.s64 + 29868;
	// bl 0x824a5e10
	ctx.lr = 0x824D0010;
	sub_824A5E10(ctx, base);
	// bl 0x821a5cc0
	ctx.lr = 0x824D0014;
	sub_821A5CC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d0024
	if (cr6.eq) goto loc_824D0024;
	// bl 0x821bbf00
	ctx.lr = 0x824D0024;
	sub_821BBF00(ctx, base);
loc_824D0024:
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

PPC_WEAK_FUNC(sub_824CFFD8) {
	__imp__sub_824CFFD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0038) {
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
	// bl 0x821a5cc0
	ctx.lr = 0x824D0050;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d0060
	if (cr6.eq) goto loc_824D0060;
	// bl 0x821bbea8
	ctx.lr = 0x824D0060;
	sub_821BBEA8(ctx, base);
loc_824D0060:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29848
	ctx.r4.s64 = r11.s64 + 29848;
	// bl 0x824a5e10
	ctx.lr = 0x824D0070;
	sub_824A5E10(ctx, base);
	// bl 0x821a5cc0
	ctx.lr = 0x824D0074;
	sub_821A5CC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d0084
	if (cr6.eq) goto loc_824D0084;
	// bl 0x821bbf00
	ctx.lr = 0x824D0084;
	sub_821BBF00(ctx, base);
loc_824D0084:
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

PPC_WEAK_FUNC(sub_824D0038) {
	__imp__sub_824D0038(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0098) {
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
	// bl 0x821a5cc0
	ctx.lr = 0x824D00B0;
	sub_821A5CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d00c0
	if (cr6.eq) goto loc_824D00C0;
	// bl 0x821bbea8
	ctx.lr = 0x824D00C0;
	sub_821BBEA8(ctx, base);
loc_824D00C0:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,29888
	ctx.r4.s64 = r11.s64 + 29888;
	// bl 0x824a5e10
	ctx.lr = 0x824D00D0;
	sub_824A5E10(ctx, base);
	// bl 0x821a5cc0
	ctx.lr = 0x824D00D4;
	sub_821A5CC0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d00e4
	if (cr6.eq) goto loc_824D00E4;
	// bl 0x821bbf00
	ctx.lr = 0x824D00E4;
	sub_821BBF00(ctx, base);
loc_824D00E4:
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

PPC_WEAK_FUNC(sub_824D0098) {
	__imp__sub_824D0098(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D00F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,29868
	ctx.r3.s64 = r11.s64 + 29868;
	// b 0x823d75f8
	sub_823D75F8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_824D00F8) {
	__imp__sub_824D00F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D0104) {
	__imp__sub_824D0104(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0108) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,29848
	ctx.r3.s64 = r11.s64 + 29848;
	// b 0x823d75f8
	sub_823D75F8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_824D0108) {
	__imp__sub_824D0108(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D0114) {
	__imp__sub_824D0114(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0118) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r3,r11,29888
	ctx.r3.s64 = r11.s64 + 29888;
	// b 0x823d75f8
	sub_823D75F8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_824D0118) {
	__imp__sub_824D0118(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0124) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D0124) {
	__imp__sub_824D0124(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0128) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x824D0130;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d0190
	if (!cr6.eq) goto loc_824D0190;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r29,128
	r29.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d016c
	if (!cr6.eq) goto loc_824D016C;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x82130528
	ctx.lr = 0x824D0168;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_824D016C:
	// li r11,0
	r11.s64 = 0;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
loc_824D0178:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,3040(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// blt cr6,0x824d0178
	if (cr6.lt) goto loc_824D0178;
loc_824D0190:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,-27428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5338
	ctx.lr = 0x824D01A4;
	sub_824A5338(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r4,16
	ctx.r4.s64 = 16;
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// bl 0x824a4e18
	ctx.lr = 0x824D01C4;
	sub_824A4E18(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824d01f0
	if (cr6.eq) goto loc_824D01F0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,16
	ctx.r9.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_824D01F0:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821b5a60
	ctx.lr = 0x824D01F8;
	sub_821B5A60(ctx, base);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x824D0200;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d022c
	if (cr6.eq) goto loc_824D022C;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r9,-6900
	ctx.r7.s64 = ctx.r9.s64 + -6900;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824d0230
	goto loc_824D0230;
loc_824D022C:
	// li r11,0
	r11.s64 = 0;
loc_824D0230:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0254
	if (cr6.eq) goto loc_824D0254;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D0254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D0254:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824D0128) {
	__imp__sub_824D0128(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0260) {
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
	ctx.lr = 0x824D0268;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d02cc
	if (!cr6.eq) goto loc_824D02CC;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r29,128
	r29.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d02a8
	if (!cr6.eq) goto loc_824D02A8;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x82130528
	ctx.lr = 0x824D02A4;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_824D02A8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
loc_824D02B4:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,3040(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// blt cr6,0x824d02b4
	if (cr6.lt) goto loc_824D02B4;
loc_824D02CC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,-27428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5338
	ctx.lr = 0x824D02E0;
	sub_824A5338(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r4,16
	ctx.r4.s64 = 16;
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// bl 0x824a4e18
	ctx.lr = 0x824D0300;
	sub_824A4E18(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824d0320
	if (cr6.eq) goto loc_824D0320;
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824D0320:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821b5a60
	ctx.lr = 0x824D0328;
	sub_821B5A60(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x824D0330;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0350
	if (cr6.eq) goto loc_824D0350;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r10,-6852
	ctx.r9.s64 = ctx.r10.s64 + -6852;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x824d0354
	goto loc_824D0354;
loc_824D0350:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824D0354:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0378
	if (cr6.eq) goto loc_824D0378;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D0378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D0378:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824D0260) {
	__imp__sub_824D0260(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D0384) {
	__imp__sub_824D0384(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0388) {
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
	ctx.lr = 0x824D0390;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d03f4
	if (!cr6.eq) goto loc_824D03F4;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r29,128
	r29.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d03d0
	if (!cr6.eq) goto loc_824D03D0;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x82130528
	ctx.lr = 0x824D03CC;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_824D03D0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
loc_824D03DC:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,3040(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// blt cr6,0x824d03dc
	if (cr6.lt) goto loc_824D03DC;
loc_824D03F4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,-27428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5338
	ctx.lr = 0x824D0408;
	sub_824A5338(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r4,16
	ctx.r4.s64 = 16;
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// bl 0x824a4e18
	ctx.lr = 0x824D0428;
	sub_824A4E18(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824d0448
	if (cr6.eq) goto loc_824D0448;
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824D0448:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821b5a60
	ctx.lr = 0x824D0450;
	sub_821B5A60(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x824D0458;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0478
	if (cr6.eq) goto loc_824D0478;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r10,-6868
	ctx.r9.s64 = ctx.r10.s64 + -6868;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x824d047c
	goto loc_824D047C;
loc_824D0478:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824D047C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d04a0
	if (cr6.eq) goto loc_824D04A0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D04A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D04A0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824D0388) {
	__imp__sub_824D0388(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D04AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D04AC) {
	__imp__sub_824D04AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D04B0) {
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
	ctx.lr = 0x824D04B8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d051c
	if (!cr6.eq) goto loc_824D051C;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r29,128
	r29.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d04f8
	if (!cr6.eq) goto loc_824D04F8;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x82130528
	ctx.lr = 0x824D04F4;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_824D04F8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
loc_824D0504:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,3040(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// blt cr6,0x824d0504
	if (cr6.lt) goto loc_824D0504;
loc_824D051C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,-27428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5338
	ctx.lr = 0x824D0530;
	sub_824A5338(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r4,16
	ctx.r4.s64 = 16;
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// bl 0x824a4e18
	ctx.lr = 0x824D0550;
	sub_824A4E18(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824d0570
	if (cr6.eq) goto loc_824D0570;
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824D0570:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821b5a60
	ctx.lr = 0x824D0578;
	sub_821B5A60(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x824D0580;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d05a0
	if (cr6.eq) goto loc_824D05A0;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r10,-6836
	ctx.r9.s64 = ctx.r10.s64 + -6836;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x824d05a4
	goto loc_824D05A4;
loc_824D05A0:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824D05A4:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d05c8
	if (cr6.eq) goto loc_824D05C8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D05C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D05C8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824D04B0) {
	__imp__sub_824D04B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D05D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D05D4) {
	__imp__sub_824D05D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D05D8) {
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
	ctx.lr = 0x824D05E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d0644
	if (!cr6.eq) goto loc_824D0644;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r29,128
	r29.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d0620
	if (!cr6.eq) goto loc_824D0620;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x82130528
	ctx.lr = 0x824D061C;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_824D0620:
	// mr r11,r28
	r11.u64 = r28.u64;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
loc_824D062C:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,3040(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stwx r10,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// blt cr6,0x824d062c
	if (cr6.lt) goto loc_824D062C;
loc_824D0644:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,-27428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5338
	ctx.lr = 0x824D0658;
	sub_824A5338(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r8,r31,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// bl 0x824a4e18
	ctx.lr = 0x824D068C;
	sub_824A4E18(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8248e370
	ctx.lr = 0x824D0694;
	sub_8248E370(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824D05D8) {
	__imp__sub_824D05D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D06A0) {
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
	ctx.lr = 0x824D06A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// lhz r11,18(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 18);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d070c
	if (!cr6.eq) goto loc_824D070C;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r31,r30,12
	r31.s64 = r30.s64 + 12;
	// li r29,128
	r29.s64 = 128;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d06e8
	if (!cr6.eq) goto loc_824D06E8;
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// li r3,512
	ctx.r3.s64 = 512;
	// bl 0x82130528
	ctx.lr = 0x824D06E4;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_824D06E8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
loc_824D06F4:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,3040(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3040);
	// stwx r10,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r11,512
	cr6.compare<int32_t>(r11.s32, 512, xer);
	// blt cr6,0x824d06f4
	if (cr6.lt) goto loc_824D06F4;
loc_824D070C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,-27428(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27428);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x824a5338
	ctx.lr = 0x824D0720;
	sub_824A5338(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lhz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// li r4,16
	ctx.r4.s64 = 16;
	// rlwinm r8,r29,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r10.u32);
	// bl 0x824a4e18
	ctx.lr = 0x824D0740;
	sub_824A4E18(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x824d0760
	if (cr6.eq) goto loc_824D0760;
	// stw r27,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824D0760:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821b5a60
	ctx.lr = 0x824D0768;
	sub_821B5A60(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x824D0770;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0790
	if (cr6.eq) goto loc_824D0790;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r9,r10,-6804
	ctx.r9.s64 = ctx.r10.s64 + -6804;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x824d0794
	goto loc_824D0794;
loc_824D0790:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_824D0794:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d07b8
	if (cr6.eq) goto loc_824D07B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D07B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D07B8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824D06A0) {
	__imp__sub_824D06A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D07C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D07C4) {
	__imp__sub_824D07C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D07C8) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r31,r11,29868
	r31.s64 = r11.s64 + 29868;
	// addi r4,r10,-18184
	ctx.r4.s64 = ctx.r10.s64 + -18184;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824d0128
	ctx.lr = 0x824D07F0;
	sub_824D0128(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,-18172
	ctx.r4.s64 = ctx.r8.s64 + -18172;
	// stw r11,29784(r9)
	PPC_STORE_U32(ctx.r9.u32 + 29784, r11.u32);
	// bl 0x824d0128
	ctx.lr = 0x824D080C;
	sub_824D0128(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,15260
	ctx.r4.s64 = ctx.r6.s64 + 15260;
	// stw r11,29780(r7)
	PPC_STORE_U32(ctx.r7.u32 + 29780, r11.u32);
	// bl 0x824d0128
	ctx.lr = 0x824D0828;
	sub_824D0128(ctx, base);
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r4,-32249
	ctx.r4.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,15244
	ctx.r4.s64 = ctx.r4.s64 + 15244;
	// stw r11,29752(r5)
	PPC_STORE_U32(ctx.r5.u32 + 29752, r11.u32);
	// bl 0x824a5510
	ctx.lr = 0x824D0844;
	sub_824A5510(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,15236
	ctx.r4.s64 = ctx.r9.s64 + 15236;
	// stw r11,29816(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29816, r11.u32);
	// bl 0x824a5510
	ctx.lr = 0x824D0860;
	sub_824A5510(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,15220
	ctx.r4.s64 = ctx.r7.s64 + 15220;
	// stw r11,29760(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29760, r11.u32);
	// bl 0x824a5510
	ctx.lr = 0x824D087C;
	sub_824A5510(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,15208
	ctx.r4.s64 = ctx.r5.s64 + 15208;
	// stw r11,29820(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29820, r11.u32);
	// bl 0x824a5510
	ctx.lr = 0x824D0898;
	sub_824A5510(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,15188
	ctx.r4.s64 = ctx.r9.s64 + 15188;
	// stw r11,29792(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29792, r11.u32);
	// bl 0x824d0260
	ctx.lr = 0x824D08B4;
	sub_824D0260(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,15160
	ctx.r4.s64 = ctx.r7.s64 + 15160;
	// stw r11,29776(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29776, r11.u32);
	// bl 0x824d0388
	ctx.lr = 0x824D08D0;
	sub_824D0388(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,15148
	ctx.r4.s64 = ctx.r5.s64 + 15148;
	// stw r11,29824(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29824, r11.u32);
	// bl 0x824d04b0
	ctx.lr = 0x824D08EC;
	sub_824D04B0(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,15140
	ctx.r4.s64 = ctx.r9.s64 + 15140;
	// stw r11,29796(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29796, r11.u32);
	// bl 0x824d04b0
	ctx.lr = 0x824D0908;
	sub_824D04B0(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// addi r4,r7,15116
	ctx.r4.s64 = ctx.r7.s64 + 15116;
	// stw r3,29768(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29768, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824d0260
	ctx.lr = 0x824D0920;
	sub_824D0260(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r5,15100
	ctx.r4.s64 = ctx.r5.s64 + 15100;
	// stw r11,29800(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29800, r11.u32);
	// bl 0x824d04b0
	ctx.lr = 0x824D093C;
	sub_824D04B0(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,15088
	ctx.r4.s64 = ctx.r9.s64 + 15088;
	// stw r11,29840(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29840, r11.u32);
	// bl 0x824d04b0
	ctx.lr = 0x824D0958;
	sub_824D04B0(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,15072
	ctx.r4.s64 = ctx.r7.s64 + 15072;
	// stw r11,29804(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29804, r11.u32);
	// bl 0x824d05d8
	ctx.lr = 0x824D0974;
	sub_824D05D8(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// stw r3,29812(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29812, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_824D07C8) {
	__imp__sub_824D07C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0990) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r31,r11,29848
	r31.s64 = r11.s64 + 29848;
	// addi r4,r10,-18184
	ctx.r4.s64 = ctx.r10.s64 + -18184;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824d0128
	ctx.lr = 0x824D09B8;
	sub_824D0128(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,15280
	ctx.r4.s64 = ctx.r8.s64 + 15280;
	// stw r11,29756(r9)
	PPC_STORE_U32(ctx.r9.u32 + 29756, r11.u32);
	// bl 0x824d06a0
	ctx.lr = 0x824D09D4;
	sub_824D06A0(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,15188
	ctx.r4.s64 = ctx.r6.s64 + 15188;
	// stw r11,29844(r7)
	PPC_STORE_U32(ctx.r7.u32 + 29844, r11.u32);
	// bl 0x824d0260
	ctx.lr = 0x824D09F0;
	sub_824D0260(ctx, base);
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r4,-32249
	ctx.r4.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,15160
	ctx.r4.s64 = ctx.r4.s64 + 15160;
	// stw r11,29832(r5)
	PPC_STORE_U32(ctx.r5.u32 + 29832, r11.u32);
	// bl 0x824d0388
	ctx.lr = 0x824D0A0C;
	sub_824D0388(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,15148
	ctx.r4.s64 = ctx.r9.s64 + 15148;
	// stw r11,29808(r10)
	PPC_STORE_U32(ctx.r10.u32 + 29808, r11.u32);
	// bl 0x824d04b0
	ctx.lr = 0x824D0A28;
	sub_824D04B0(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,15116
	ctx.r4.s64 = ctx.r7.s64 + 15116;
	// stw r11,29764(r8)
	PPC_STORE_U32(ctx.r8.u32 + 29764, r11.u32);
	// bl 0x824d0260
	ctx.lr = 0x824D0A44;
	sub_824D0260(ctx, base);
	// lis r6,-32115
	ctx.r6.s64 = -2104688640;
	// stw r3,29836(r6)
	PPC_STORE_U32(ctx.r6.u32 + 29836, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_824D0990) {
	__imp__sub_824D0990(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0A60) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// addi r31,r11,29888
	r31.s64 = r11.s64 + 29888;
	// addi r4,r10,15280
	ctx.r4.s64 = ctx.r10.s64 + 15280;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824d06a0
	ctx.lr = 0x824D0A88;
	sub_824D06A0(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,15188
	ctx.r4.s64 = ctx.r8.s64 + 15188;
	// stw r11,29828(r9)
	PPC_STORE_U32(ctx.r9.u32 + 29828, r11.u32);
	// bl 0x824d0260
	ctx.lr = 0x824D0AA4;
	sub_824D0260(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,15160
	ctx.r4.s64 = ctx.r6.s64 + 15160;
	// stw r11,29772(r7)
	PPC_STORE_U32(ctx.r7.u32 + 29772, r11.u32);
	// bl 0x824d0388
	ctx.lr = 0x824D0AC0;
	sub_824D0388(ctx, base);
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// stw r3,29788(r5)
	PPC_STORE_U32(ctx.r5.u32 + 29788, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_824D0A60) {
	__imp__sub_824D0A60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D0ADC) {
	__imp__sub_824D0ADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0AE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r8,71(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 71);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// beq cr6,0x824d0b24
	if (cr6.eq) goto loc_824D0B24;
	// lbz r10,70(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 70);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,212(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 212);
loc_824D0B00:
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// lwzx r4,r5,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// lfs f13,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 + f0.f64));
	// blt cr6,0x824d0b00
	if (cr6.lt) goto loc_824D0B00;
loc_824D0B24:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f1,f12,f13,f0
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f0.f64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D0AE0) {
	__imp__sub_824D0AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// stfd f30,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f30.u64);
	// stfd f31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, f31.u64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,167(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 167);
	// lbz r8,159(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 159);
	// li r11,0
	r11.s64 = 0;
	// lbz r7,151(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 151);
	// lfs f31,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	f31.f64 = double(temp.f32);
	// lbz r6,135(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 135);
	// lfs f30,188(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 188);
	f30.f64 = double(temp.f32);
	// lbz r5,143(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 143);
	// lbz r4,175(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 175);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stfs f1,8(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f2,12(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r9,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, ctx.r9.u8);
	// stfs f3,16(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r8,69(r3)
	PPC_STORE_U8(ctx.r3.u32 + 69, ctx.r8.u8);
	// stfs f4,20(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stb r7,70(r3)
	PPC_STORE_U8(ctx.r3.u32 + 70, ctx.r7.u8);
	// stfs f6,24(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stb r6,71(r3)
	PPC_STORE_U8(ctx.r3.u32 + 71, ctx.r6.u8);
	// stfs f5,28(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stb r5,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, ctx.r5.u8);
	// stfs f7,32(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stb r4,75(r3)
	PPC_STORE_U8(ctx.r3.u32 + 75, ctx.r4.u8);
	// stfs f8,36(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f9,40(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f10,44(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f11,48(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f12,52(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f13,56(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f0,60(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f31,76(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f30,80(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lfd f30,-16(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lfd f31,-8(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D0B38) {
	__imp__sub_824D0B38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D0BDC) {
	__imp__sub_824D0BDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0BE0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// lfs f13,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lfs f12,16(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,16(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lfs f11,20(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,20(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// lfs f10,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,24(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// lfs f9,28(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,28(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// lfs f8,32(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// stfs f8,32(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lfs f7,36(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// stfs f7,36(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// lfs f6,40(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,40(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// lfs f5,44(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 44);
	ctx.f5.f64 = double(temp.f32);
	// stfs f5,44(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// lfs f4,48(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	ctx.f4.f64 = double(temp.f32);
	// stfs f4,48(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lfs f3,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f3.f64 = double(temp.f32);
	// stfs f3,52(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// lfs f2,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f2.f64 = double(temp.f32);
	// stfs f2,56(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// lbz r11,75(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 75);
	// stb r11,75(r31)
	PPC_STORE_U8(r31.u32 + 75, r11.u8);
	// lfs f1,76(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,76(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// lfs f0,80(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x824d0cf4
	if (cr6.eq) goto loc_824D0CF4;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x824d0ce8
	if (!cr6.eq) goto loc_824D0CE8;
	// li r3,364
	ctx.r3.s64 = 364;
	// bl 0x82130528
	ctx.lr = 0x824D0C9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0cac
	if (cr6.eq) goto loc_824D0CAC;
	// bl 0x823d69a8
	ctx.lr = 0x824D0CA8;
	sub_823D69A8(ctx, base);
	// b 0x824d0cb0
	goto loc_824D0CB0;
loc_824D0CAC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824D0CB0:
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x824cffd8
	ctx.lr = 0x824D0CBC;
	sub_824CFFD8(ctx, base);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82130528
	ctx.lr = 0x824D0CC4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0cd8
	if (cr6.eq) goto loc_824D0CD8;
	// bl 0x824d6450
	ctx.lr = 0x824D0CD0;
	sub_824D6450(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x824d0cdc
	goto loc_824D0CDC;
loc_824D0CD8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_824D0CDC:
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x824a5490
	ctx.lr = 0x824D0CE8;
	sub_824A5490(ctx, base);
loc_824D0CE8:
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824d6798
	ctx.lr = 0x824D0CF4;
	sub_824D6798(ctx, base);
loc_824D0CF4:
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

PPC_WEAK_FUNC(sub_824D0BE0) {
	__imp__sub_824D0BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D0D0C) {
	__imp__sub_824D0D0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0D10) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x824d0ae0
	ctx.lr = 0x824D0D28;
	sub_824D0AE0(ctx, base);
	// stfs f1,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
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

PPC_WEAK_FUNC(sub_824D0D10) {
	__imp__sub_824D0D10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0D40) {
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
	// bl 0x823d91d8
	ctx.lr = 0x824D0D48;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824d0f34
	if (cr6.eq) goto loc_824D0F34;
	// rlwinm r20,r3,2,0,29
	r20.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r20,r23
	r11.u64 = PPC_LOAD_U32(r20.u32 + r23.u32);
	// lwz r24,144(r11)
	r24.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x824d0f34
	if (cr6.eq) goto loc_824D0F34;
	// lwz r27,148(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 148);
	// lhz r22,208(r24)
	r22.u64 = PPC_LOAD_U16(r24.u32 + 208);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824d0d94
	if (cr6.eq) goto loc_824D0D94;
	// lhz r11,208(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 208);
	// cmpw cr6,r22,r11
	cr6.compare<int32_t>(r22.s32, r11.s32, xer);
	// bgt cr6,0x824d0d94
	if (cr6.gt) goto loc_824D0D94;
	// mr r22,r11
	r22.u64 = r11.u64;
loc_824D0D94:
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// ble cr6,0x824d0f34
	if (!cr6.gt) goto loc_824D0F34;
	// li r25,0
	r25.s64 = 0;
	// li r28,16
	r28.s64 = 16;
	// mr r31,r25
	r31.u64 = r25.u64;
	// li r29,32
	r29.s64 = 32;
	// li r30,48
	r30.s64 = 48;
loc_824D0DB0:
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x824D0DB8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0dec
	if (cr6.eq) goto loc_824D0DEC;
	// lwzx r11,r20,r23
	r11.u64 = PPC_LOAD_U32(r20.u32 + r23.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r10,14(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// lfs f2,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lbz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 12);
	// lfs f1,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824d9798
	ctx.lr = 0x824D0DE4;
	sub_824D9798(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x824d0df0
	goto loc_824D0DF0;
loc_824D0DEC:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_824D0DF0:
	// lbz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// li r3,240
	ctx.r3.s64 = 240;
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stwx r11,r9,r23
	PPC_STORE_U32(ctx.r9.u32 + r23.u32, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x824D0E04;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0e14
	if (cr6.eq) goto loc_824D0E14;
	// bl 0x824d9240
	ctx.lr = 0x824D0E10;
	sub_824D9240(ctx, base);
	// b 0x824d0e18
	goto loc_824D0E18;
loc_824D0E14:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824D0E18:
	// lbz r11,0(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r9,r10,r23
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r23.u32);
	// stw r3,144(r9)
	PPC_STORE_U32(ctx.r9.u32 + 144, ctx.r3.u32);
	// lhz r8,208(r24)
	ctx.r8.u64 = PPC_LOAD_U16(r24.u32 + 208);
	// cmplw cr6,r31,r8
	cr6.compare<uint32_t>(r31.u32, ctx.r8.u32, xer);
	// bge cr6,0x824d0e80
	if (!cr6.lt) goto loc_824D0E80;
	// lwz r10,196(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 196);
	// rlwinm r8,r31,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r31,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r3,128
	r11.s64 = ctx.r3.s64 + 128;
	// lwzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, ctx.r7.u32);
	// lwz r6,196(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 196);
	// stwx r25,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, r25.u32);
	// lwz r10,204(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 204);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824d0e84
	goto loc_824D0E84;
loc_824D0E80:
	// stw r25,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, r25.u32);
loc_824D0E84:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x824d0f0c
	if (cr6.eq) goto loc_824D0F0C;
	// lhz r11,208(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 208);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// bge cr6,0x824d0f0c
	if (!cr6.lt) goto loc_824D0F0C;
	// li r3,240
	ctx.r3.s64 = 240;
	// bl 0x82130528
	ctx.lr = 0x824D0EA0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0eb0
	if (cr6.eq) goto loc_824D0EB0;
	// bl 0x824d9240
	ctx.lr = 0x824D0EAC;
	sub_824D9240(ctx, base);
	// b 0x824d0eb4
	goto loc_824D0EB4;
loc_824D0EB0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_824D0EB4:
	// lwz r10,196(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// rlwinm r8,r31,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r31,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r3,128
	r11.s64 = ctx.r3.s64 + 128;
	// lwzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// stw r7,192(r3)
	PPC_STORE_U32(ctx.r3.u32 + 192, ctx.r7.u32);
	// lwz r6,196(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// stwx r25,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, r25.u32);
	// lwz r10,204(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 204);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r10,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r10,r29
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r10,r30
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r5,0(r26)
	ctx.r5.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// rotlwi r4,r5,2
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// lwzx r11,r4,r23
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + r23.u32);
	// stw r3,148(r11)
	PPC_STORE_U32(r11.u32 + 148, ctx.r3.u32);
loc_824D0F0C:
	// lbz r11,0(r26)
	r11.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// clrlwi r31,r10,24
	r31.u64 = ctx.r10.u32 & 0xFF;
	// stb r9,0(r26)
	PPC_STORE_U8(r26.u32 + 0, ctx.r9.u8);
	// lbz r11,0(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 0);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// cmpw cr6,r31,r22
	cr6.compare<int32_t>(r31.s32, r22.s32, xer);
	// stb r7,0(r21)
	PPC_STORE_U8(r21.u32 + 0, ctx.r7.u8);
	// blt cr6,0x824d0db0
	if (cr6.lt) goto loc_824D0DB0;
loc_824D0F34:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_824D0D40) {
	__imp__sub_824D0D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0F3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D0F3C) {
	__imp__sub_824D0F3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0F40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824d0f90
	if (cr6.eq) goto loc_824D0F90;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824a5038
	ctx.lr = 0x824D0F74;
	sub_824A5038(ctx, base);
	// lwz r31,4(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d0f90
	if (cr6.eq) goto loc_824D0F90;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824a53f8
	ctx.lr = 0x824D0F88;
	sub_824A53F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x824D0F90;
	sub_82130588(ctx, base);
loc_824D0F90:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d0fb0
	if (cr6.eq) goto loc_824D0FB0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D0FB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D0FB0:
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

PPC_WEAK_FUNC(sub_824D0F40) {
	__imp__sub_824D0F40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D0FC8) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824d1014
	if (cr6.eq) goto loc_824D1014;
	// bl 0x8249e3c8
	ctx.lr = 0x824D0FEC;
	sub_8249E3C8(ctx, base);
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8249e448
	ctx.lr = 0x824D0FF8;
	sub_8249E448(ctx, base);
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824d1014
	if (cr6.eq) goto loc_824D1014;
	// bl 0x824cffd8
	ctx.lr = 0x824D1008;
	sub_824CFFD8(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x824a5490
	ctx.lr = 0x824D1014;
	sub_824A5490(ctx, base);
loc_824D1014:
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

PPC_WEAK_FUNC(sub_824D0FC8) {
	__imp__sub_824D0FC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D102C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D102C) {
	__imp__sub_824D102C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1030) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824D1038;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9a4
	ctx.lr = 0x824D1040;
	// stwu r1,-1200(r1)
	ea = -1200 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stb r10,1279(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1279, ctx.r10.u8);
	// li r27,0
	r27.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r5,1236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1236, ctx.r5.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r4,1228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1228, ctx.r4.u32);
	// mr r11,r27
	r11.u64 = r27.u64;
	// stb r27,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r27.u8);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// stb r27,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, r27.u8);
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// stb r27,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, r27.u8);
	// stb r11,29988(r10)
	PPC_STORE_U8(ctx.r10.u32 + 29988, r11.u8);
	// mr r16,r8
	r16.u64 = ctx.r8.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r14,r9
	r14.u64 = ctx.r9.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r28,1244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1244, r28.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r26,1252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1252, r26.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stb r27,144(r1)
	PPC_STORE_U8(ctx.r1.u32 + 144, r27.u8);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r29,255
	r29.s64 = 255;
	// lfs f0,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// fmr f18,f31
	f18.f64 = f31.f64;
	// lfs f30,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fmr f19,f31
	f19.f64 = f31.f64;
	// lfs f29,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f29.f64 = double(temp.f32);
	// fmr f20,f31
	f20.f64 = f31.f64;
	// lfs f24,11364(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11364);
	f24.f64 = double(temp.f32);
	// fmr f21,f31
	f21.f64 = f31.f64;
	// fmr f15,f0
	f15.f64 = f0.f64;
	// stb r29,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r29.u8);
	// fmr f16,f13
	f16.f64 = ctx.f13.f64;
	// li r5,512
	ctx.r5.s64 = 512;
	// fmr f26,f30
	f26.f64 = f30.f64;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// fmr f27,f30
	f27.f64 = f30.f64;
	// fmr f22,f31
	f22.f64 = f31.f64;
	// fmr f17,f13
	f17.f64 = ctx.f13.f64;
	// fmr f25,f29
	f25.f64 = f29.f64;
	// fmr f28,f30
	f28.f64 = f30.f64;
	// fmr f23,f0
	f23.f64 = f0.f64;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824D1110;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// li r3,128
	ctx.r3.s64 = 128;
	// mr r30,r11
	r30.u64 = r11.u64;
	// addi r10,r30,1
	ctx.r10.s64 = r30.s64 + 1;
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// stb r10,0(r28)
	PPC_STORE_U8(r28.u32 + 0, ctx.r10.u8);
	// bl 0x82130528
	ctx.lr = 0x824D112C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d11b4
	if (cr6.eq) goto loc_824D11B4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stfs f31,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f30,24(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stb r29,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, r29.u8);
	// stfs f29,28(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stb r29,69(r3)
	PPC_STORE_U8(ctx.r3.u32 + 69, r29.u8);
	// lfs f13,30712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// stb r29,70(r3)
	PPC_STORE_U8(ctx.r3.u32 + 70, r29.u8);
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// stb r9,71(r3)
	PPC_STORE_U8(ctx.r3.u32 + 71, ctx.r9.u8);
	// stfs f13,8(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stb r27,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, r27.u8);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r27,75(r3)
	PPC_STORE_U8(ctx.r3.u32 + 75, r27.u8);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// stfs f30,32(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f30,36(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f31,40(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f31,44(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f31,48(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f31,52(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f31,56(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f31,60(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f31,64(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f31,76(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f31,80(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// b 0x824d11b8
	goto loc_824D11B8;
loc_824D11B4:
	// mr r17,r27
	r17.u64 = r27.u64;
loc_824D11B8:
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r17,84
	ctx.r3.s64 = r17.s64 + 84;
	// stwx r17,r11,r26
	PPC_STORE_U32(r11.u32 + r26.u32, r17.u32);
	// bl 0x823db670
	ctx.lr = 0x824D11D0;
	sub_823DB670(ctx, base);
	// stb r27,127(r17)
	PPC_STORE_U8(r17.u32 + 127, r27.u8);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r27,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r27.u8);
	// addi r4,r11,-29624
	ctx.r4.s64 = r11.s64 + -29624;
	// stb r9,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r9.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// bl 0x821cff40
	ctx.lr = 0x824D1200;
	sub_821CFF40(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,-29628
	r30.s64 = r11.s64 + -29628;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// bl 0x821cff40
	ctx.lr = 0x824D121C;
	sub_821CFF40(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x824d1aac
	if (!cr6.eq) goto loc_824D1AAC;
	// lis r27,-32249
	r27.s64 = -2113470464;
	// lis r29,-32249
	r29.s64 = -2113470464;
	// lis r26,-32249
	r26.s64 = -2113470464;
	// addi r3,r27,15892
	ctx.r3.s64 = r27.s64 + 15892;
	// lis r4,-32249
	ctx.r4.s64 = -2113470464;
	// addi r11,r29,15876
	r11.s64 = r29.s64 + 15876;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// lis r28,-32249
	r28.s64 = -2113470464;
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// lis r21,-32249
	r21.s64 = -2113470464;
	// addi r27,r26,15860
	r27.s64 = r26.s64 + 15860;
	// addi r26,r4,15844
	r26.s64 = ctx.r4.s64 + 15844;
	// lis r19,-32249
	r19.s64 = -2113470464;
	// addi r3,r28,15828
	ctx.r3.s64 = r28.s64 + 15828;
	// stw r26,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r26.u32);
	// addi r4,r6,15812
	ctx.r4.s64 = ctx.r6.s64 + 15812;
	// lis r30,-32249
	r30.s64 = -2113470464;
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// addi r5,r5,15796
	ctx.r5.s64 = ctx.r5.s64 + 15796;
	// stw r4,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// lis r22,-32251
	r22.s64 = -2113601536;
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// stw r5,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r5.u32);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r29,r21,15784
	r29.s64 = r21.s64 + 15784;
	// lis r20,-32249
	r20.s64 = -2113470464;
	// addi r21,r19,15764
	r21.s64 = r19.s64 + 15764;
	// lis r18,-32249
	r18.s64 = -2113470464;
	// addi r19,r30,15744
	r19.s64 = r30.s64 + 15744;
	// lis r25,-32249
	r25.s64 = -2113470464;
	// lis r24,-32249
	r24.s64 = -2113470464;
	// lis r23,-32249
	r23.s64 = -2113470464;
	// lis r3,-32249
	ctx.r3.s64 = -2113470464;
	// addi r28,r22,11856
	r28.s64 = r22.s64 + 11856;
	// addi r7,r7,15728
	ctx.r7.s64 = ctx.r7.s64 + 15728;
	// addi r6,r8,15712
	ctx.r6.s64 = ctx.r8.s64 + 15712;
	// addi r5,r9,15684
	ctx.r5.s64 = ctx.r9.s64 + 15684;
	// stw r7,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r7.u32);
	// addi r4,r10,15656
	ctx.r4.s64 = ctx.r10.s64 + 15656;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// addi r30,r11,15644
	r30.s64 = r11.s64 + 15644;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// addi r22,r20,15628
	r22.s64 = r20.s64 + 15628;
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// addi r20,r18,15608
	r20.s64 = r18.s64 + 15608;
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// lis r15,-32125
	r15.s64 = -2105344000;
	// addi r25,r25,1576
	r25.s64 = r25.s64 + 1576;
	// addi r24,r24,15592
	r24.s64 = r24.s64 + 15592;
	// addi r23,r23,1552
	r23.s64 = r23.s64 + 1552;
	// addi r18,r3,15576
	r18.s64 = ctx.r3.s64 + 15576;
	// b 0x824d1310
	goto loc_824D1310;
loc_824D130C:
	// lwz r30,128(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
loc_824D1310:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D1320;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d135c
	if (cr6.eq) goto loc_824D135C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D133C;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f15,f1
	ctx.fpscr.disableFlushMode();
	f15.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D135C:
	// lwz r30,104(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D136C;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d13a8
	if (cr6.eq) goto loc_824D13A8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D1388;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D13A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f16,f1
	ctx.fpscr.disableFlushMode();
	f16.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D13A8:
	// lwz r30,96(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D13B8;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d13f4
	if (cr6.eq) goto loc_824D13F4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D13D4;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D13EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f17,f1
	ctx.fpscr.disableFlushMode();
	f17.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D13F4:
	// lwz r30,112(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D1404;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1440
	if (cr6.eq) goto loc_824D1440;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D1420;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1438;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f18,f1
	ctx.fpscr.disableFlushMode();
	f18.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1440:
	// lwz r30,140(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D1450;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1498
	if (cr6.eq) goto loc_824D1498;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D146C;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1484;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fsubs f0,f29,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 - ctx.f1.f64));
	// fsel f13,f0,f29,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? f29.f64 : ctx.f1.f64;
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(f30.f64 - ctx.f13.f64));
	// fsel f25,f12,f13,f30
	f25.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f30.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1498:
	// lwz r30,120(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D14A8;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d14f0
	if (cr6.eq) goto loc_824D14F0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D14C4;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D14DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fsubs f0,f29,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 - ctx.f1.f64));
	// fsel f13,f0,f29,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? f29.f64 : ctx.f1.f64;
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(f30.f64 - ctx.f13.f64));
	// fsel f26,f12,f13,f30
	f26.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f30.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D14F0:
	// lwz r30,136(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D1500;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1548
	if (cr6.eq) goto loc_824D1548;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D151C;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fsubs f0,f29,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 - ctx.f1.f64));
	// fsel f13,f0,f29,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? f29.f64 : ctx.f1.f64;
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(f30.f64 - ctx.f13.f64));
	// fsel f27,f12,f13,f30
	f27.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f30.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1548:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D1554;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d159c
	if (cr6.eq) goto loc_824D159C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D1570;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1588;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fsubs f0,f29,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 - ctx.f1.f64));
	// fsel f13,f0,f29,f1
	ctx.f13.f64 = f0.f64 >= 0.0 ? f29.f64 : ctx.f1.f64;
	// fsubs f12,f30,f13
	ctx.f12.f64 = double(float(f30.f64 - ctx.f13.f64));
	// fsel f28,f12,f13,f30
	f28.f64 = ctx.f12.f64 >= 0.0 ? ctx.f13.f64 : f30.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D159C:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D15A8;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d15e4
	if (cr6.eq) goto loc_824D15E4;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D15C4;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D15DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f19,f1
	ctx.fpscr.disableFlushMode();
	f19.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D15E4:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D15F0;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d162c
	if (cr6.eq) goto loc_824D162C;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D160C;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f20,f1
	ctx.fpscr.disableFlushMode();
	f20.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D162C:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D1638;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1674
	if (cr6.eq) goto loc_824D1674;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D1654;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D166C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f21,f1
	ctx.fpscr.disableFlushMode();
	f21.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1674:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D1680;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d16bc
	if (cr6.eq) goto loc_824D16BC;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D169C;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D16B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D16BC:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D16C8;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1704
	if (cr6.eq) goto loc_824D1704;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D16E4;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D16FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1704:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D1710;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d17a4
	if (cr6.eq) goto loc_824D17A4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D172C;
	sub_821CFF40(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x824D173C;
	sub_821CFE80(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x821cfe80
	ctx.lr = 0x824D174C;
	sub_821CFE80(ctx, base);
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// lwz r3,2828(r15)
	ctx.r3.u64 = PPC_LOAD_U32(r15.u32 + 2828);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x824a02f0
	ctx.lr = 0x824D175C;
	sub_824A02F0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x824D176C;
	sub_821CFE80(ctx, base);
	// li r3,364
	ctx.r3.s64 = 364;
	// bl 0x82130528
	ctx.lr = 0x824D1774;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d1784
	if (cr6.eq) goto loc_824D1784;
	// bl 0x823d69a8
	ctx.lr = 0x824D1780;
	sub_823D69A8(ctx, base);
	// b 0x824d1788
	goto loc_824D1788;
loc_824D1784:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824D1788:
	// stw r3,4(r17)
	PPC_STORE_U32(r17.u32 + 4, ctx.r3.u32);
	// rotlwi r3,r3,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// bl 0x824cffd8
	ctx.lr = 0x824D1794;
	sub_824CFFD8(ctx, base);
	// lwz r4,0(r17)
	ctx.r4.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lwz r3,4(r17)
	ctx.r3.u64 = PPC_LOAD_U32(r17.u32 + 4);
	// bl 0x824a5490
	ctx.lr = 0x824D17A0;
	sub_824A5490(ctx, base);
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D17A4:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D17B0;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1828
	if (cr6.eq) goto loc_824D1828;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D17CC;
	sub_821CFF40(ctx, base);
	// lbz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824d17f4
	if (!cr6.eq) goto loc_824D17F4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// bl 0x824d0d40
	ctx.lr = 0x824D17EC;
	sub_824D0D40(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r11.u8);
loc_824D17F4:
	// mr r9,r14
	ctx.r9.u64 = r14.u64;
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// mr r8,r16
	ctx.r8.u64 = r16.u64;
	// lwz r7,1252(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,1244(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1244);
	// lwz r5,1236(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1236);
	// lwz r4,1228(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1228);
	// bl 0x824d1030
	ctx.lr = 0x824D1818;
	sub_824D1030(ctx, base);
	// lbz r11,82(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stb r10,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r10.u8);
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1828:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D1834;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d186c
	if (cr6.eq) goto loc_824D186C;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D1850;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D186C:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D1878;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1958
	if (cr6.eq) goto loc_824D1958;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D1894;
	sub_821CFF40(ctx, base);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// bne cr6,0x824d18a8
	if (!cr6.eq) goto loc_824D18A8;
	// lbz r11,0(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + 0);
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
loc_824D18A8:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x824d18bc
	if (!cr6.eq) goto loc_824D18BC;
	// lbz r11,0(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + 0);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
loc_824D18BC:
	// lwz r26,1228(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1228);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x824d1914
	if (cr6.eq) goto loc_824D1914;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821b84b8
	ctx.lr = 0x824D18D8;
	sub_821B84B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x824d1910
	if (!cr6.eq) goto loc_824D1910;
	// li r4,95
	ctx.r4.s64 = 95;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823dd850
	ctx.lr = 0x824D18EC;
	sub_823DD850(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d18fc
	if (cr6.eq) goto loc_824D18FC;
	// li r11,58
	r11.s64 = 58;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
loc_824D18FC:
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821b84b8
	ctx.lr = 0x824D1908;
	sub_821B84B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d1914
	if (cr6.eq) goto loc_824D1914;
loc_824D1910:
	// lhz r30,20(r3)
	r30.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
loc_824D1914:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lbz r5,85(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,1236(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1236);
	// bl 0x824da360
	ctx.lr = 0x824D1928;
	sub_824DA360(ctx, base);
	// lbz r11,0(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + 0);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r26,108(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stwx r3,r9,r14
	PPC_STORE_U32(ctx.r9.u32 + r14.u32, ctx.r3.u32);
	// lbz r11,0(r16)
	r11.u64 = PPC_LOAD_U8(r16.u32 + 0);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// stb r6,0(r16)
	PPC_STORE_U8(r16.u32 + 0, ctx.r6.u8);
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1958:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821cff40
	ctx.lr = 0x824D1964;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d199c
	if (cr6.eq) goto loc_824D199C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D1980;
	sub_821CFF40(ctx, base);
	// lbz r11,81(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r5,1236(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1236);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwzx r3,r10,r14
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r14.u32);
	// bl 0x824d9cb8
	ctx.lr = 0x824D1998;
	sub_824D9CB8(ctx, base);
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D199C:
	// lwz r30,116(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D19AC;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d19d8
	if (cr6.eq) goto loc_824D19D8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D19C8;
	sub_821CFF40(ctx, base);
	// lbz r10,83(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// ori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 | 1;
	// stb r9,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D19D8:
	// lwz r30,124(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D19E8;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1a24
	if (cr6.eq) goto loc_824D1A24;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x821cff40
	ctx.lr = 0x824D1A04;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f23,f1
	ctx.fpscr.disableFlushMode();
	f23.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1A24:
	// lwz r30,132(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D1A34;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1a70
	if (cr6.eq) goto loc_824D1A70;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D1A50;
	sub_821CFF40(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1A68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f24,f1
	ctx.fpscr.disableFlushMode();
	f24.f64 = ctx.f1.f64;
	// b 0x824d1a8c
	goto loc_824D1A8C;
loc_824D1A70:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,656
	ctx.r4.s64 = ctx.r1.s64 + 656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D1A8C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D1A9C;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d130c
	if (cr6.eq) goto loc_824D130C;
	// lwz r30,92(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_824D1AAC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821cff40
	ctx.lr = 0x824D1ABC;
	sub_821CFF40(ctx, base);
	// lbz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824d1adc
	if (!cr6.eq) goto loc_824D1ADC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// mr r4,r14
	ctx.r4.u64 = r14.u64;
	// bl 0x824d0d40
	ctx.lr = 0x824D1ADC;
	sub_824D0D40(ctx, base);
loc_824D1ADC:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lbz r7,83(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r8,82(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r6,81(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r5,1279(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1279);
	// lbz r3,29988(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 29988);
	// stfs f15,8(r17)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f15.f64);
	PPC_STORE_U32(r17.u32 + 8, temp.u32);
	// lbz r4,86(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// stfs f16,12(r17)
	temp.f32 = float(f16.f64);
	PPC_STORE_U32(r17.u32 + 12, temp.u32);
	// or r11,r3,r7
	r11.u64 = ctx.r3.u64 | ctx.r7.u64;
	// stfs f17,16(r17)
	temp.f32 = float(f17.f64);
	PPC_STORE_U32(r17.u32 + 16, temp.u32);
	// stfs f18,20(r17)
	temp.f32 = float(f18.f64);
	PPC_STORE_U32(r17.u32 + 20, temp.u32);
	// stb r9,71(r17)
	PPC_STORE_U8(r17.u32 + 71, ctx.r9.u8);
	// stfs f25,24(r17)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r17.u32 + 24, temp.u32);
	// stb r8,72(r17)
	PPC_STORE_U8(r17.u32 + 72, ctx.r8.u8);
	// stfs f26,28(r17)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r17.u32 + 28, temp.u32);
	// stb r6,70(r17)
	PPC_STORE_U8(r17.u32 + 70, ctx.r6.u8);
	// stfs f27,32(r17)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r17.u32 + 32, temp.u32);
	// stb r5,69(r17)
	PPC_STORE_U8(r17.u32 + 69, ctx.r5.u8);
	// stfs f28,36(r17)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r17.u32 + 36, temp.u32);
	// stb r4,68(r17)
	PPC_STORE_U8(r17.u32 + 68, ctx.r4.u8);
	// stfs f19,40(r17)
	temp.f32 = float(f19.f64);
	PPC_STORE_U32(r17.u32 + 40, temp.u32);
	// stb r11,75(r17)
	PPC_STORE_U8(r17.u32 + 75, r11.u8);
	// stfs f20,44(r17)
	temp.f32 = float(f20.f64);
	PPC_STORE_U32(r17.u32 + 44, temp.u32);
	// stfs f21,48(r17)
	temp.f32 = float(f21.f64);
	PPC_STORE_U32(r17.u32 + 48, temp.u32);
	// stfs f22,52(r17)
	temp.f32 = float(f22.f64);
	PPC_STORE_U32(r17.u32 + 52, temp.u32);
	// stfs f31,56(r17)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r17.u32 + 56, temp.u32);
	// stfs f23,76(r17)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(r17.u32 + 76, temp.u32);
	// stfs f24,80(r17)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r17.u32 + 80, temp.u32);
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9f0
	ctx.lr = 0x824D1B60;
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_824D1030) {
	__imp__sub_824D1030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D1B64) {
	__imp__sub_824D1B64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1B68) {
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
	PPCRegister f0{};
	PPCRegister f31{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x824D1B70;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r5,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r5.u32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r8,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, ctx.r8.u32);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r15,r4
	r15.u64 = ctx.r4.u64;
	// stw r28,316(r1)
	PPC_STORE_U32(ctx.r1.u32 + 316, r28.u32);
	// lbz r9,71(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 71);
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lfs f31,-31400(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f31.f64 = double(temp.f32);
	// lbz r11,70(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 70);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// beq cr6,0x824d1dec
	if (cr6.eq) goto loc_824D1DEC;
	// rlwinm r11,r11,2,22,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0x3FC;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r19,48
	r19.s64 = 48;
	// lis r25,-32115
	r25.s64 = -2104688640;
	// li r16,32
	r16.s64 = 32;
	// li r14,16
	r14.s64 = 16;
	// lis r24,-32115
	r24.s64 = -2104688640;
	// lis r23,-32115
	r23.s64 = -2104688640;
	// lis r22,-32115
	r22.s64 = -2104688640;
	// lis r21,-32115
	r21.s64 = -2104688640;
	// lis r20,-32115
	r20.s64 = -2104688640;
	// addi r18,r11,2352
	r18.s64 = r11.s64 + 2352;
	// addi r17,r10,2384
	r17.s64 = ctx.r10.s64 + 2384;
loc_824D1BFC:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,212(r15)
	ctx.r10.u64 = PPC_LOAD_U32(r15.u32 + 212);
	// lwzx r27,r11,r10
	r27.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r11,164(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1dc4
	if (cr6.eq) goto loc_824D1DC4;
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1dc4
	if (cr6.eq) goto loc_824D1DC4;
	// lbz r11,69(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 69);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,255
	cr6.compare<int32_t>(r11.s32, 255, xer);
	// beq cr6,0x824d1c88
	if (cr6.eq) goto loc_824D1C88;
	// lwz r9,208(r15)
	ctx.r9.u64 = PPC_LOAD_U32(r15.u32 + 208);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lbz r6,70(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 70);
	// rotlwi r5,r6,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// lwzx r4,r5,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lhz r3,14(r4)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r4.u32 + 14);
	// extsh r30,r3
	r30.s64 = ctx.r3.s16;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x824d1c9c
	if (cr6.eq) goto loc_824D1C9C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D1C6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r30,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v63,r31,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824d1c9c
	goto loc_824D1C9C;
loc_824D1C88:
	// li r11,64
	r11.s64 = 64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r31,r28,16
	r31.s64 = r28.s64 + 16;
	// lvx128 v62,r28,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824D1C9C:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x824d1d14
	if (!cr6.eq) goto loc_824D1D14;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// addi r11,r26,16
	r11.s64 = r26.s64 + 16;
	// lvx128 v63,r0,r17
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r18
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r18.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r16
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r19
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v58,v61,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v57,r11,r14
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v56,v61,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v55,v57,v59
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// lvx128 v54,r8,r16
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v53,v57,v59
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vand128 v52,v54,v63
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v51,v58,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v50,v56,v53
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vor128 v49,v62,v52
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v52.u8)));
	// vmrghw128 v48,v58,v55
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmsum4fp128 v47,v49,v51
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// vmsum4fp128 v46,v49,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmsum4fp128 v45,v49,v48
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32), 0xFF));
	// vmrghw128 v44,v47,v49
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v43,v45,v46
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v43,v44
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// stvx128 v42,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824D1D14:
	// lwz r30,176(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 176);
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// lwz r4,29756(r20)
	ctx.r4.u64 = PPC_LOAD_U32(r20.u32 + 29756);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a5b00
	ctx.lr = 0x824D1D28;
	sub_824A5B00(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8248e0f0
	ctx.lr = 0x824D1D30;
	sub_8248E0F0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// addi r31,r1,88
	r31.s64 = ctx.r1.s64 + 88;
	// lwz r4,29844(r21)
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + 29844);
	// bl 0x824a5b00
	ctx.lr = 0x824D1D44;
	sub_824A5B00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8248e408
	ctx.lr = 0x824D1D4C;
	sub_8248E408(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,29832(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + 29832);
	// addi r31,r1,88
	r31.s64 = ctx.r1.s64 + 88;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// bl 0x824a5b00
	ctx.lr = 0x824D1D60;
	sub_824A5B00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8248e270
	ctx.lr = 0x824D1D68;
	sub_8248E270(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,29808(r23)
	ctx.r4.u64 = PPC_LOAD_U32(r23.u32 + 29808);
	// addi r31,r1,316
	r31.s64 = ctx.r1.s64 + 316;
	// bl 0x824a5b00
	ctx.lr = 0x824D1D78;
	sub_824A5B00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8248e1f0
	ctx.lr = 0x824D1D80;
	sub_8248E1F0(ctx, base);
	// lbz r11,70(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 70);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,29764(r24)
	ctx.r4.u64 = PPC_LOAD_U32(r24.u32 + 29764);
	// addi r31,r1,88
	r31.s64 = ctx.r1.s64 + 88;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// bl 0x824a5b00
	ctx.lr = 0x824D1D98;
	sub_824A5B00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8248e2f0
	ctx.lr = 0x824D1DA0;
	sub_8248E2F0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,29836(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 29836);
	// addi r31,r1,88
	r31.s64 = ctx.r1.s64 + 88;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// bl 0x824a5b00
	ctx.lr = 0x824D1DB4;
	sub_824A5B00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8248e270
	ctx.lr = 0x824D1DBC;
	sub_8248E270(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824a41c8
	ctx.lr = 0x824D1DC4;
	sub_824A41C8(ctx, base);
loc_824D1DC4:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lbz r9,71(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 71);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// blt cr6,0x824d1bfc
	if (cr6.lt) goto loc_824D1BFC;
	// lwz r8,332(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
loc_824D1DEC:
	// lbz r11,72(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 72);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d1e60
	if (cr6.eq) goto loc_824D1E60;
	// li r30,1
	r30.s64 = 1;
	// b 0x824d1e08
	goto loc_824D1E08;
loc_824D1E04:
	// lwz r8,332(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 332);
loc_824D1E08:
	// lbz r11,68(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 68);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// rlwinm r9,r11,29,3,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 29) & 0x1FFFFFFC;
	// clrlwi r7,r11,27
	ctx.r7.u64 = r11.u32 & 0x1F;
	// slw r6,r30,r7
	ctx.r6.u64 = ctx.r7.u8 & 0x20 ? 0 : (r30.u32 << (ctx.r7.u8 & 0x3F));
	// lwzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// and r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 & ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x824d1e50
	if (!cr6.eq) goto loc_824D1E50;
	// lwz r10,208(r15)
	ctx.r10.u64 = PPC_LOAD_U32(r15.u32 + 208);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// lwz r5,308(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r15
	ctx.r4.u64 = r15.u64;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x824d1b68
	ctx.lr = 0x824D1E50;
	sub_824D1B68(ctx, base);
loc_824D1E50:
	// lbz r11,72(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 72);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x824d1e04
	if (cr6.lt) goto loc_824D1E04;
loc_824D1E60:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_824D1B68) {
	__imp__sub_824D1B68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1E6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D1E6C) {
	__imp__sub_824D1E6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1E70) {
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
	// bl 0x8218fe20
	ctx.lr = 0x824D1E88;
	sub_8218FE20(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r31,44
	r11.s64 = r31.s64 + 44;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r9,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r9.u32);
	// addi r8,r31,56
	ctx.r8.s64 = r31.s64 + 56;
	// stw r9,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r9.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r9.u32);
loc_824D1EAC:
	// stw r9,-12(r11)
	PPC_STORE_U32(r11.u32 + -12, ctx.r9.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stbx r7,r8,r10
	PPC_STORE_U8(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// blt cr6,0x824d1eac
	if (cr6.lt) goto loc_824D1EAC;
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

PPC_WEAK_FUNC(sub_824D1E70) {
	__imp__sub_824D1E70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1EE0) {
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
	ctx.lr = 0x824D1EE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821902b0
	ctx.lr = 0x824D1F08;
	sub_821902B0(ctx, base);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// stw r11,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D1EE0) {
	__imp__sub_824D1EE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D1F24) {
	__imp__sub_824D1F24(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1F28) {
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
	ctx.lr = 0x824D1F30;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82190640
	ctx.lr = 0x824D1F4C;
	sub_82190640(ctx, base);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r30.u32);
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r29,r8,r31
	PPC_STORE_U32(ctx.r8.u32 + r31.u32, r29.u32);
	// lwz r10,60(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r6,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r6.u32);
	// stw r7,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r7.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D1F28) {
	__imp__sub_824D1F28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D1F8C) {
	__imp__sub_824D1F8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D1F90) {
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
	ctx.lr = 0x824D1F98;
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-4384(r1)
	ea = -4384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82187150
	ctx.lr = 0x824D1FC8;
	sub_82187150(ctx, base);
	// li r24,288
	r24.s64 = 288;
	// lis r10,1023
	ctx.r10.s64 = 67043328;
	// stw r3,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r3.u32);
	// divw r11,r23,r24
	r11.s32 = r23.s32 / r24.s32;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// stw r31,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r31.u32);
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bgt cr6,0x824d2000
	if (cr6.gt) goto loc_824D2000;
	// rlwinm r11,r31,6,0,25
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 6) & 0xFFFFFFC0;
	// li r10,-17
	ctx.r10.s64 = -17;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x824d2004
	if (!cr6.gt) goto loc_824D2004;
loc_824D2000:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_824D2004:
	// bl 0x82130528
	ctx.lr = 0x824D2008;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2064
	if (cr6.eq) goto loc_824D2064;
	// addi r8,r3,16
	ctx.r8.s64 = ctx.r3.s64 + 16;
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
	// addic. r10,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r10.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// blt 0x824d205c
	if (cr0.lt) goto loc_824D205C;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r11,r9,24
	r11.s64 = ctx.r9.s64 + 24;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_824D2030:
	// stfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f0,-20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -20, temp.u32);
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// stfs f0,-16(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -16, temp.u32);
	// stfs f0,-8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// stfs f0,-4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bge 0x824d2030
	if (!cr0.lt) goto loc_824D2030;
loc_824D205C:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// b 0x824d2068
	goto loc_824D2068;
loc_824D2064:
	// li r11,0
	r11.s64 = 0;
loc_824D2068:
	// stw r11,24(r28)
	PPC_STORE_U32(r28.u32 + 24, r11.u32);
	// srawi r11,r23,1
	xer.ca = (r23.s32 < 0) & ((r23.u32 & 0x1) != 0);
	r11.s64 = r23.s32 >> 1;
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r9,20(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// li r4,1
	ctx.r4.s64 = 1;
	// addze r3,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r3.s64 = temp.s64;
	// divw r19,r9,r10
	r19.s32 = ctx.r9.s32 / ctx.r10.s32;
	// bl 0x821b3250
	ctx.lr = 0x824D2088;
	sub_821B3250(ctx, base);
	// stw r3,16(r28)
	PPC_STORE_U32(r28.u32 + 16, ctx.r3.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x824D209C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r20,0
	r20.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x824d21d8
	if (!cr6.gt) goto loc_824D21D8;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r23,-1
	ctx.r8.s64 = r23.s64 + -1;
	// li r29,0
	r29.s64 = 0;
	// divwu r11,r8,r24
	r11.u32 = ctx.r8.u32 / r24.u32;
	// lfs f0,-31400(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31400);
	f0.f64 = double(temp.f32);
	// mr r22,r27
	r22.u64 = r27.u64;
	// lfs f13,-31068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31068);
	ctx.f13.f64 = double(temp.f32);
	// addi r20,r11,1
	r20.s64 = r11.s64 + 1;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r21,16
	r21.s64 = 16;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_824D20E0:
	// addi r24,r30,288
	r24.s64 = r30.s64 + 288;
	// cmpw cr6,r24,r23
	cr6.compare<int32_t>(r24.s32, r23.s32, xer);
	// mr r27,r24
	r27.u64 = r24.u64;
	// blt cr6,0x824d20f4
	if (cr6.lt) goto loc_824D20F4;
	// mr r27,r23
	r27.u64 = r23.u64;
loc_824D20F4:
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// srawi r10,r30,1
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1) != 0);
	ctx.r10.s64 = r30.s32 >> 1;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// add r8,r29,r11
	ctx.r8.u64 = r29.u64 + r11.u64;
	// addze r7,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r7.s64 = temp.s64;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// srawi r5,r27,1
	xer.ca = (r27.s32 < 0) & ((r27.u32 & 0x1) != 0);
	ctx.r5.s64 = r27.s32 >> 1;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// stw r7,48(r8)
	PPC_STORE_U32(ctx.r8.u32 + 48, ctx.r7.u32);
	// addze r4,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r4.s64 = temp.s64;
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// add r3,r29,r11
	ctx.r3.u64 = r29.u64 + r11.u64;
	// lvlx128 v62,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stw r4,52(r3)
	PPC_STORE_U32(ctx.r3.u32 + 52, ctx.r4.u32);
	// vspltw128 v61,v63,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bge cr6,0x824d21c4
	if (!cr6.lt) goto loc_824D21C4;
	// mr r31,r22
	r31.u64 = r22.u64;
loc_824D2150:
	// srawi r11,r30,1
	xer.ca = (r30.s32 < 0) & ((r30.u32 & 0x1) != 0);
	r11.s64 = r30.s32 >> 1;
	// lhz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addze r6,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r6.s64 = temp.s64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r10,r5,r25
	PPC_STORE_U16(ctx.r5.u32 + r25.u32, ctx.r10.u16);
	// lwz r9,16(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// lwz r8,24(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// lhz r6,2(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lhz r11,0(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 0);
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 1);
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r29,r8
	ctx.r3.u64 = r29.u64 + ctx.r8.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// stwx r6,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r6.u32);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// bl 0x825f8aa0
	ctx.lr = 0x824D21B4;
	sub_825F8AA0(ctx, base);
	// addi r30,r30,2
	r30.s64 = r30.s64 + 2;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x824d2150
	if (cr6.lt) goto loc_824D2150;
loc_824D21C4:
	// addi r29,r29,64
	r29.s64 = r29.s64 + 64;
	// mr r30,r24
	r30.u64 = r24.u64;
	// addi r22,r22,576
	r22.s64 = r22.s64 + 576;
	// cmpw cr6,r24,r23
	cr6.compare<int32_t>(r24.s32, r23.s32, xer);
	// blt cr6,0x824d20e0
	if (cr6.lt) goto loc_824D20E0;
loc_824D21D8:
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// stw r20,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r20.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D21F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x821b4838
	ctx.lr = 0x824D2204;
	sub_821B4838(ctx, base);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// rotlwi r4,r3,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r3.u32, 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821b34f0
	ctx.lr = 0x824D221C;
	sub_821B34F0(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// ble cr6,0x824d2310
	if (!cr6.gt) goto loc_824D2310;
	// li r27,0
	r27.s64 = 0;
	// addi r25,r1,176
	r25.s64 = ctx.r1.s64 + 176;
loc_824D2230:
	// lwz r11,16(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// bl 0x821b3cc0
	ctx.lr = 0x824D2260;
	sub_821B3CC0(ctx, base);
	// lwz r11,24(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d229c
	if (cr6.eq) goto loc_824D229C;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// bl 0x821b3de8
	ctx.lr = 0x824D229C;
	sub_821B3DE8(ctx, base);
loc_824D229C:
	// lwz r11,60(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 60);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x824d22fc
	if (!cr6.gt) goto loc_824D22FC;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// addi r30,r26,32
	r30.s64 = r26.s64 + 32;
	// rlwinm r28,r11,3,0,28
	r28.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
loc_824D22B8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x821b3f08
	ctx.lr = 0x824D22E8;
	sub_821B3F08(ctx, base);
	// lwz r11,60(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 60);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x824d22b8
	if (cr6.lt) goto loc_824D22B8;
loc_824D22FC:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,12
	r27.s64 = r27.s64 + 12;
	// addi r25,r25,4
	r25.s64 = r25.s64 + 4;
	// cmpw cr6,r29,r19
	cr6.compare<int32_t>(r29.s32, r19.s32, xer);
	// blt cr6,0x824d2230
	if (cr6.lt) goto loc_824D2230;
loc_824D2310:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r10,r11,-9216
	ctx.r10.s64 = r11.s64 + -9216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// beq cr6,0x824d2350
	if (cr6.eq) goto loc_824D2350;
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d2350
	if (cr6.eq) goto loc_824D2350;
	// lbz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 108);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824d2350
	if (!cr6.eq) goto loc_824D2350;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D2350:
	// addi r1,r1,4384
	ctx.r1.s64 = ctx.r1.s64 + 4384;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_824D1F90) {
	__imp__sub_824D1F90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2358) {
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
	ctx.lr = 0x824D2360;
	// stwu r1,-848(r1)
	ea = -848 + ctx.r1.u32;
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
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x82475e28
	ctx.lr = 0x824D237C;
	sub_82475E28(ctx, base);
	// addi r5,r30,64
	ctx.r5.s64 = r30.s64 + 64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825f7cf8
	ctx.lr = 0x824D238C;
	sub_825F7CF8(ctx, base);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187f40
	ctx.lr = 0x824D23A0;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x824d2404
	if (cr6.eq) goto loc_824D2404;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82187b88
	ctx.lr = 0x824D23B4;
	sub_82187B88(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82178430
	ctx.lr = 0x824D23BC;
	sub_82178430(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x82177bf8
	ctx.lr = 0x824D23D0;
	sub_82177BF8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82177ca0
	ctx.lr = 0x824D23D8;
	sub_82177CA0(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r5,-1
	cr6.compare<int32_t>(ctx.r5.s32, -1, xer);
	// beq cr6,0x824d23f4
	if (cr6.eq) goto loc_824D23F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82179588
	ctx.lr = 0x824D23F4;
	sub_82179588(ctx, base);
loc_824D23F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82177c50
	ctx.lr = 0x824D23FC;
	sub_82177C50(ctx, base);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82187ba8
	ctx.lr = 0x824D2404;
	sub_82187BA8(ctx, base);
loc_824D2404:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82187bd0
	ctx.lr = 0x824D240C;
	sub_82187BD0(ctx, base);
	// addi r1,r1,848
	ctx.r1.s64 = ctx.r1.s64 + 848;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_824D2358) {
	__imp__sub_824D2358(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D2414) {
	__imp__sub_824D2414(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2418) {
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
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x821870b8
	ctx.lr = 0x824D2434;
	sub_821870B8(ctx, base);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2454
	if (cr6.eq) goto loc_824D2454;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2454;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D2454:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2474
	if (cr6.eq) goto loc_824D2474;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D2474:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2494
	if (cr6.eq) goto loc_824D2494;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D2494:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d24a8
	if (cr6.eq) goto loc_824D24A8;
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bl 0x82130588
	ctx.lr = 0x824D24A8;
	sub_82130588(ctx, base);
loc_824D24A8:
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

PPC_WEAK_FUNC(sub_824D2418) {
	__imp__sub_824D2418(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D24BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D24BC) {
	__imp__sub_824D24BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D24C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29908(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29908);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D24C0) {
	__imp__sub_824D24C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D24CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D24CC) {
	__imp__sub_824D24CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D24D0) {
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
	// addi r9,r11,16836
	ctx.r9.s64 = r11.s64 + 16836;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x824d2504
	if (cr6.eq) goto loc_824D2504;
	// bl 0x82130588
	ctx.lr = 0x824D2500;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824D2504:
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

PPC_WEAK_FUNC(sub_824D24D0) {
	__imp__sub_824D24D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2518) {
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
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,16836
	ctx.r9.s64 = r11.s64 + 16836;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r7,640
	ctx.r7.s64 = 640;
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
	// li r6,480
	ctx.r6.s64 = 480;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r7,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r7.u32);
	// stw r6,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r6.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// stb r30,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r5,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r5.u32);
	// bl 0x82180430
	ctx.lr = 0x824D2578;
	sub_82180430(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
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

PPC_WEAK_FUNC(sub_824D2518) {
	__imp__sub_824D2518(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2598) {
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
	// li r3,136
	ctx.r3.s64 = 136;
	// bl 0x82130528
	ctx.lr = 0x824D25AC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d25c8
	if (cr6.eq) goto loc_824D25C8;
	// bl 0x824d2518
	ctx.lr = 0x824D25B8;
	sub_824D2518(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824D25C8:
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

PPC_WEAK_FUNC(sub_824D2598) {
	__imp__sub_824D2598(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D25DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D25DC) {
	__imp__sub_824D25DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D25E0) {
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
	ctx.lr = 0x824D25E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r10,192(r1)
	PPC_STORE_U64(ctx.r1.u32 + 192, ctx.r10.u64);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r10,r11,16836
	ctx.r10.s64 = r11.s64 + 16836;
	// li r30,0
	r30.s64 = 0;
	// stw r5,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r5.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stw r6,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r6.u32);
	// li r5,44
	ctx.r5.s64 = 44;
	// stw r7,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r7.u32);
	// stw r8,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r8.u32);
	// stw r9,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r9.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stb r30,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r30.u8);
	// bl 0x823da950
	ctx.lr = 0x824D2630;
	sub_823DA950(ctx, base);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// li r10,31
	ctx.r10.s64 = 31;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r11,r29
	ctx.r9.s64 = r29.s64 - r11.s64;
loc_824D2640:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d2658
	if (cr6.eq) goto loc_824D2658;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824d2640
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824D2640;
loc_824D2658:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D25E0) {
	__imp__sub_824D25E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2668) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,24(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x824d2684
	if (!cr6.lt) goto loc_824D2684;
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
loc_824D2684:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D2668) {
	__imp__sub_824D2668(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D268C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D268C) {
	__imp__sub_824D268C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2690) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bl 0x8262e420
	ctx.lr = 0x824D26B0;
	sub_8262E420(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
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

PPC_WEAK_FUNC(sub_824D2690) {
	__imp__sub_824D2690(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D26C8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// bl 0x8262e420
	ctx.lr = 0x824D26E8;
	sub_8262E420(ctx, base);
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r31.u32);
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

PPC_WEAK_FUNC(sub_824D26C8) {
	__imp__sub_824D26C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2700) {
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
	ctx.lr = 0x824D2708;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r10,r11,16836
	ctx.r10.s64 = r11.s64 + 16836;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x824D2730;
	sub_823DA950(ctx, base);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r3,r1,172
	ctx.r3.s64 = ctx.r1.s64 + 172;
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r5,44
	ctx.r5.s64 = 44;
	// lwz r6,84(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r4,r31,92
	ctx.r4.s64 = r31.s64 + 92;
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r9,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// stw r8,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r8.u32);
	// stw r7,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r7.u32);
	// stw r6,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r6.u32);
	// stw r30,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r30.u32);
	// stb r11,168(r1)
	PPC_STORE_U8(ctx.r1.u32 + 168, r11.u8);
	// bl 0x823da950
	ctx.lr = 0x824D2770;
	sub_823DA950(ctx, base);
	// lbz r9,168(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 168);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// stw r10,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r10.u32);
	// stb r9,190(r1)
	PPC_STORE_U8(ctx.r1.u32 + 190, ctx.r9.u8);
	// ble cr6,0x824d27b4
	if (!cr6.gt) goto loc_824D27B4;
	// lhz r11,24(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 24);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x824d27b4
	if (!cr6.lt) goto loc_824D27B4;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d27b4
	if (cr6.eq) goto loc_824D27B4;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, r11.u32);
	// stb r10,190(r1)
	PPC_STORE_U8(ctx.r1.u32 + 190, ctx.r10.u8);
loc_824D27B4:
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lwz r8,164(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r7,160(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// addi r9,r1,172
	ctx.r9.s64 = ctx.r1.s64 + 172;
	// lwz r6,156(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r5,152(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D27E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x824d27f8
	if (!cr6.eq) goto loc_824D27F8;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d924c
	return;
loc_824D27F8:
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,20
	ctx.r3.s64 = r29.s64 + 20;
	// bl 0x8262e420
	ctx.lr = 0x824D2804;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,-25232(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824D2824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82182150
	ctx.lr = 0x824D2834;
	sub_82182150(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D2700) {
	__imp__sub_824D2700(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2840) {
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
	ctx.lr = 0x824D2848;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r28,r31,4
	r28.s64 = r31.s64 + 4;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824D287C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x824d2894
	if (!cr6.eq) goto loc_824D2894;
loc_824D2888:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_824D2894:
	// addi r31,r31,68
	r31.s64 = r31.s64 + 68;
	// li r29,0
	r29.s64 = 0;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_824D28A0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x824d28a0
	if (!cr6.eq) goto loc_824D28A0;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d28f4
	if (cr6.eq) goto loc_824D28F4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82195a98
	ctx.lr = 0x824D28CC;
	sub_82195A98(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x824d28e0
	if (cr6.eq) goto loc_824D28E0;
	// bl 0x82195720
	ctx.lr = 0x824D28D8;
	sub_82195720(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x824d28f4
	goto loc_824D28F4;
loc_824D28E0:
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r11,16844
	ctx.r3.s64 = r11.s64 + 16844;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x824D28F4;
	sub_82130000(ctx, base);
loc_824D28F4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x824D2928;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d2888
	if (cr6.eq) goto loc_824D2888;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r27,28
	ctx.r3.s64 = r27.s64 + 28;
	// bl 0x8262e420
	ctx.lr = 0x824D2940;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824D2840) {
	__imp__sub_824D2840(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2954) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D2954) {
	__imp__sub_824D2954(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2958) {
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
	// li r3,40
	ctx.r3.s64 = 40;
	// bl 0x82130528
	ctx.lr = 0x824D296C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d29c8
	if (cr6.eq) goto loc_824D29C8;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-1380
	ctx.r9.s64 = ctx.r10.s64 + -1380;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
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
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// sth r11,32(r3)
	PPC_STORE_U16(ctx.r3.u32 + 32, r11.u16);
	// sth r11,34(r3)
	PPC_STORE_U16(ctx.r3.u32 + 34, r11.u16);
	// stb r11,36(r3)
	PPC_STORE_U8(ctx.r3.u32 + 36, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824D29C8:
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

PPC_WEAK_FUNC(sub_824D2958) {
	__imp__sub_824D2958(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D29DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D29DC) {
	__imp__sub_824D29DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D29E0) {
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
	ctx.lr = 0x824D29E8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r29,0
	r29.s64 = 0;
	// addi r9,r11,-1380
	ctx.r9.s64 = r11.s64 + -1380;
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d2a48
	if (cr6.eq) goto loc_824D2A48;
	// li r30,0
	r30.s64 = 0;
loc_824D2A10:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2a34
	if (cr6.eq) goto loc_824D2A34;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2A34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D2A34:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x824d2a10
	if (cr6.lt) goto loc_824D2A10;
loc_824D2A48:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r26,r31,4
	r26.s64 = r31.s64 + 4;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x824d2a80
	if (cr6.eq) goto loc_824D2A80;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_824D2A6C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824d2a6c
	if (!cr6.eq) goto loc_824D2A6C;
loc_824D2A80:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U16(r26.u32 + 4);
	// li r28,0
	r28.s64 = 0;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r26)
	PPC_STORE_U16(r26.u32 + 4, ctx.r8.u16);
	// lhz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x824d2af4
	if (cr6.eq) goto loc_824D2AF4;
	// li r29,0
	r29.s64 = 0;
loc_824D2AA8:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwzx r30,r29,r11
	r30.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x824D2AB8;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824d2ae0
	if (!cr6.eq) goto loc_824D2AE0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x824d2ae0
	if (cr6.eq) goto loc_824D2AE0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D2AE0:
	// lhz r11,24(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x824d2aa8
	if (cr6.lt) goto loc_824D2AA8;
loc_824D2AF4:
	// lhz r11,24(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 24);
	// addi r27,r31,20
	r27.s64 = r31.s64 + 20;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x824d2b2c
	if (cr6.eq) goto loc_824D2B2C;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_824D2B18:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824d2b18
	if (!cr6.eq) goto loc_824D2B18;
loc_824D2B2C:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r8.u16);
	// lhz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x824d2b8c
	if (cr6.eq) goto loc_824D2B8C;
	// li r30,0
	r30.s64 = 0;
loc_824D2B54:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2b78
	if (cr6.eq) goto loc_824D2B78;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2B78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D2B78:
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x824d2b54
	if (cr6.lt) goto loc_824D2B54;
loc_824D2B8C:
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// addi r28,r31,12
	r28.s64 = r31.s64 + 12;
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x824d2bc4
	if (cr6.eq) goto loc_824D2BC4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_824D2BB0:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824d2bb0
	if (!cr6.eq) goto loc_824D2BB0;
loc_824D2BC4:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// li r29,0
	r29.s64 = 0;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// lhz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x824d2c24
	if (cr6.eq) goto loc_824D2C24;
	// li r30,0
	r30.s64 = 0;
loc_824D2BEC:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2c10
	if (cr6.eq) goto loc_824D2C10;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2C10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D2C10:
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x824d2bec
	if (cr6.lt) goto loc_824D2BEC;
loc_824D2C24:
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r9,r31,28
	ctx.r9.s64 = r31.s64 + 28;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x824d2c5c
	if (cr6.eq) goto loc_824D2C5C;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_824D2C48:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x824d2c48
	if (!cr6.eq) goto loc_824D2C48;
loc_824D2C5C:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r7.u16);
	// lhz r5,6(r9)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824d2c84
	if (cr6.eq) goto loc_824D2C84;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824D2C84;
	sub_82130588(ctx, base);
loc_824D2C84:
	// lhz r11,6(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d2c98
	if (cr6.eq) goto loc_824D2C98;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824D2C98;
	sub_82130588(ctx, base);
loc_824D2C98:
	// lhz r11,6(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d2cac
	if (cr6.eq) goto loc_824D2CAC;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824D2CAC;
	sub_82130588(ctx, base);
loc_824D2CAC:
	// lhz r11,6(r26)
	r11.u64 = PPC_LOAD_U16(r26.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d2cc0
	if (cr6.eq) goto loc_824D2CC0;
	// lwz r3,0(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x824D2CC0;
	sub_82130588(ctx, base);
loc_824D2CC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x824D2CC8;
	sub_821D2028(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824D29E0) {
	__imp__sub_824D29E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2CD0) {
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
	ctx.lr = 0x824D2CD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d2d18
	if (cr6.eq) goto loc_824D2D18;
	// li r30,0
	r30.s64 = 0;
loc_824D2CF4:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r11,r30
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x824d2700
	ctx.lr = 0x824D2D04;
	sub_824D2700(ctx, base);
	// lhz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x824d2cf4
	if (cr6.lt) goto loc_824D2CF4;
loc_824D2D18:
	// lhz r11,16(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d2d50
	if (cr6.eq) goto loc_824D2D50;
	// li r30,0
	r30.s64 = 0;
loc_824D2D2C:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r11,r30
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x824d2840
	ctx.lr = 0x824D2D3C;
	sub_824D2840(ctx, base);
	// lhz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x824d2d2c
	if (cr6.lt) goto loc_824D2D2C;
loc_824D2D50:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x824D2D64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r9.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D2CD0) {
	__imp__sub_824D2CD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D2D74) {
	__imp__sub_824D2D74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2D78) {
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
	ctx.lr = 0x824D2D80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,29908
	r31.s64 = r11.s64 + 29908;
	// lwz r11,29908(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 29908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d2ed0
	if (!cr6.eq) goto loc_824D2ED0;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824D2DA0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2db4
	if (cr6.eq) goto loc_824D2DB4;
	// bl 0x821d5408
	ctx.lr = 0x824D2DB0;
	sub_821D5408(ctx, base);
	// b 0x824d2db8
	goto loc_824D2DB8;
loc_824D2DB4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824D2DB8:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,16892
	ctx.r7.s64 = ctx.r10.s64 + 16892;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,136
	ctx.r5.s64 = 136;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32179
	ctx.r8.s64 = -2108882944;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// addi r4,r8,9624
	ctx.r4.s64 = ctx.r8.s64 + 9624;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r7,r3,27088
	ctx.r7.s64 = ctx.r3.s64 + 27088;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r5,-32128
	ctx.r5.s64 = -2105540608;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// addi r11,r9,27136
	r11.s64 = ctx.r9.s64 + 27136;
	// lis r4,-32128
	ctx.r4.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r10,27112
	r30.s64 = ctx.r10.s64 + 27112;
	// addi r29,r8,27160
	r29.s64 = ctx.r8.s64 + 27160;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r8,72
	ctx.r8.s64 = 72;
	// addi r5,r5,27184
	ctx.r5.s64 = ctx.r5.s64 + 27184;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// addi r4,r4,27208
	ctx.r4.s64 = ctx.r4.s64 + 27208;
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// li r9,68
	ctx.r9.s64 = 68;
	// li r7,76
	ctx.r7.s64 = 76;
	// li r6,80
	ctx.r6.s64 = 80;
	// stw r9,8(r30)
	PPC_STORE_U32(r30.u32 + 8, ctx.r9.u32);
	// li r11,84
	r11.s64 = 84;
	// stw r7,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r7.u32);
	// stw r6,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r6.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821d4458
	ctx.lr = 0x824D2E7C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824D2E8C;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824D2EA8;
	sub_821D41D0(ctx, base);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,27232
	ctx.r4.s64 = ctx.r8.s64 + 27232;
	// bl 0x821d4b00
	ctx.lr = 0x824D2EB8;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x824D2ED0;
	sub_821C0548(ctx, base);
loc_824D2ED0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D2D78) {
	__imp__sub_824D2D78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2ED8) {
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
	ctx.lr = 0x824D2EE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x824d2f24
	if (!cr6.gt) goto loc_824D2F24;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_824D2EF8:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x824d2f18
	if (cr6.eq) goto loc_824D2F18;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d2f18
	if (cr6.eq) goto loc_824D2F18;
	// bl 0x82130588
	ctx.lr = 0x824D2F18;
	sub_82130588(ctx, base);
loc_824D2F18:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x824d2ef8
	if (!cr0.eq) goto loc_824D2EF8;
loc_824D2F24:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x824D2F2C;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D2ED8) {
	__imp__sub_824D2ED8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D2F34) {
	__imp__sub_824D2F34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2F38) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x824D2F68;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x824d2fa8
	if (!cr6.gt) goto loc_824D2FA8;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
loc_824D2F74:
	// addic. r10,r11,-16
	xer.ca = r11.u32 > 15;
	ctx.r10.s64 = r11.s64 + -16;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq 0x824d2f8c
	if (cr0.eq) goto loc_824D2F8C;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// ori r30,r30,1
	r30.u64 = r30.u64 | 1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r11,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r11.u32);
loc_824D2F8C:
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x824d2f9c
	if (cr6.eq) goto loc_824D2F9C;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
loc_824D2F9C:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// bne 0x824d2f74
	if (!cr0.eq) goto loc_824D2F74;
loc_824D2FA8:
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

PPC_WEAK_FUNC(sub_824D2F38) {
	__imp__sub_824D2F38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D2FC0) {
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
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d3004
	if (!cr6.eq) goto loc_824D3004;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x824d2ffc
	if (cr6.eq) goto loc_824D2FFC;
	// bl 0x824d2f38
	ctx.lr = 0x824D2FF8;
	sub_824D2F38(ctx, base);
	// b 0x824d3000
	goto loc_824D3000;
loc_824D2FFC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824D3000:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_824D3004:
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

PPC_WEAK_FUNC(sub_824D2FC0) {
	__imp__sub_824D2FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29912(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29912);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D3020) {
	__imp__sub_824D3020(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D302C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D302C) {
	__imp__sub_824D302C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3030) {
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
	// addi r10,r11,16936
	ctx.r10.s64 = r11.s64 + 16936;
	// addi r3,r31,200
	ctx.r3.s64 = r31.s64 + 200;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r5,206(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 206);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x824d3070
	if (cr6.eq) goto loc_824D3070;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x824d2ed8
	ctx.lr = 0x824D3070;
	sub_824D2ED8(ctx, base);
loc_824D3070:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d3088
	if (cr6.eq) goto loc_824D3088;
	// bl 0x82130588
	ctx.lr = 0x824D3084;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824D3088:
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

PPC_WEAK_FUNC(sub_824D3030) {
	__imp__sub_824D3030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D30A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32249
	r11.s64 = -2113470464;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r9,r11,16936
	ctx.r9.s64 = r11.s64 + 16936;
	// stw r7,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r7.u32);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// stw r7,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r7.u32);
	// li r8,63
	ctx.r8.s64 = 63;
	// sth r7,204(r3)
	PPC_STORE_U16(ctx.r3.u32 + 204, ctx.r7.u16);
	// sth r7,206(r3)
	PPC_STORE_U16(ctx.r3.u32 + 206, ctx.r7.u16);
loc_824D30CC:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824d3124
	if (cr6.eq) goto loc_824D3124;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824d3118
	if (cr6.eq) goto loc_824D3118;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x824d3120
	if (cr6.eq) goto loc_824D3120;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x824d30cc
	if (cr0.gt) goto loc_824D30CC;
	// b 0x824d3124
	goto loc_824D3124;
loc_824D3118:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x824d3124
	goto loc_824D3124;
loc_824D3120:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_824D3124:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// beq cr6,0x824d3160
	if (cr6.eq) goto loc_824D3160;
	// addi r11,r3,68
	r11.s64 = ctx.r3.s64 + 68;
	// li r10,127
	ctx.r10.s64 = 127;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r11,r5
	ctx.r9.s64 = ctx.r5.s64 - r11.s64;
loc_824D3140:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d3158
	if (cr6.eq) goto loc_824D3158;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x824d3140
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_824D3140;
loc_824D3158:
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// blr 
	return;
loc_824D3160:
	// stb r7,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, ctx.r7.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D30A0) {
	__imp__sub_824D30A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3168) {
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
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x824D317C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d31bc
	if (cr6.eq) goto loc_824D31BC;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,16936
	ctx.r9.s64 = ctx.r10.s64 + 16936;
	// stw r11,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, r11.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, r11.u32);
	// sth r11,204(r3)
	PPC_STORE_U16(ctx.r3.u32 + 204, r11.u16);
	// sth r11,206(r3)
	PPC_STORE_U16(ctx.r3.u32 + 206, r11.u16);
	// stb r11,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, r11.u8);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824D31BC:
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

PPC_WEAK_FUNC(sub_824D3168) {
	__imp__sub_824D3168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D31D0) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,29912
	r31.s64 = r11.s64 + 29912;
	// lwz r11,29912(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 29912);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d3300
	if (!cr6.eq) goto loc_824D3300;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824D3200;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d3214
	if (cr6.eq) goto loc_824D3214;
	// bl 0x821d5408
	ctx.lr = 0x824D3210;
	sub_821D5408(ctx, base);
	// b 0x824d3218
	goto loc_824D3218;
loc_824D3214:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824D3218:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,16944
	ctx.r7.s64 = ctx.r10.s64 + 16944;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,208
	ctx.r5.s64 = 208;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32179
	ctx.r8.s64 = -2108882944;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// addi r4,r8,12648
	ctx.r4.s64 = ctx.r8.s64 + 12648;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r3,27260
	ctx.r7.s64 = ctx.r3.s64 + 27260;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// addi r4,r10,27284
	ctx.r4.s64 = ctx.r10.s64 + 27284;
	// addi r3,r9,27432
	ctx.r3.s64 = ctx.r9.s64 + 27432;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,68
	ctx.r9.s64 = 68;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// li r8,200
	ctx.r8.s64 = 200;
	// stw r9,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x824D32AC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824D32BC;
	sub_821D4100(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824D32D8;
	sub_821D41D0(ctx, base);
	// lis r8,-32128
	ctx.r8.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,27332
	ctx.r4.s64 = ctx.r8.s64 + 27332;
	// bl 0x821d4b00
	ctx.lr = 0x824D32E8;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x824D3300;
	sub_821C0548(ctx, base);
loc_824D3300:
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

PPC_WEAK_FUNC(sub_824D31D0) {
	__imp__sub_824D31D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3318) {
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
	// lis r11,-32115
	r11.s64 = -2104688640;
	// addi r31,r11,29916
	r31.s64 = r11.s64 + 29916;
	// lwz r11,29916(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 29916);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x824d3480
	if (!cr6.eq) goto loc_824D3480;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x824D3348;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d335c
	if (cr6.eq) goto loc_824D335C;
	// bl 0x821d5408
	ctx.lr = 0x824D3358;
	sub_821D5408(ctx, base);
	// b 0x824d3360
	goto loc_824D3360;
loc_824D335C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_824D3360:
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,16980
	ctx.r7.s64 = ctx.r10.s64 + 16980;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25704
	ctx.r9.s64 = r11.s64 + 25704;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,40
	ctx.r5.s64 = 40;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32179
	ctx.r8.s64 = -2108882944;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32128
	ctx.r3.s64 = -2105540608;
	// addi r4,r8,10584
	ctx.r4.s64 = ctx.r8.s64 + 10584;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32115
	r30.s64 = -2104688640;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,27480
	ctx.r9.s64 = ctx.r3.s64 + 27480;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r10,4
	ctx.r10.s64 = 4;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,29908(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x824d33dc
	if (!cr6.eq) goto loc_824D33DC;
	// bl 0x824d2d78
	ctx.lr = 0x824D33D8;
	sub_824D2D78(ctx, base);
	// lwz r11,29908(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29908);
loc_824D33DC:
	// lis r10,-32128
	ctx.r10.s64 = -2105540608;
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// addi r8,r10,27348
	ctx.r8.s64 = ctx.r10.s64 + 27348;
	// addi r7,r9,27528
	ctx.r7.s64 = ctx.r9.s64 + 27528;
	// li r9,12
	ctx.r9.s64 = 12;
	// lwz r10,29912(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 29912);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// bne cr6,0x824d3410
	if (!cr6.eq) goto loc_824D3410;
	// bl 0x824d31d0
	ctx.lr = 0x824D340C;
	sub_824D31D0(ctx, base);
	// lwz r10,29912(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 29912);
loc_824D3410:
	// lis r11,-32128
	r11.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,27384
	ctx.r9.s64 = r11.s64 + 27384;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// bl 0x821d4458
	ctx.lr = 0x824D342C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x824D343C;
	sub_821D4100(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x821d41d0
	ctx.lr = 0x824D3458;
	sub_821D41D0(ctx, base);
	// lis r6,-32128
	ctx.r6.s64 = -2105540608;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,27420
	ctx.r4.s64 = ctx.r6.s64 + 27420;
	// bl 0x821d4b00
	ctx.lr = 0x824D3468;
	sub_821D4B00(ctx, base);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,2828(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 2828);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821c0548
	ctx.lr = 0x824D3480;
	sub_821C0548(ctx, base);
loc_824D3480:
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

PPC_WEAK_FUNC(sub_824D3318) {
	__imp__sub_824D3318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3498) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// addi r7,r11,17648
	ctx.r7.s64 = r11.s64 + 17648;
	// addi r6,r10,17632
	ctx.r6.s64 = ctx.r10.s64 + 17632;
	// addi r5,r9,17616
	ctx.r5.s64 = ctx.r9.s64 + 17616;
	// addi r11,r8,17600
	r11.s64 = ctx.r8.s64 + 17600;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824d350c
	if (cr6.eq) goto loc_824D350C;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// addi r7,r11,17584
	ctx.r7.s64 = r11.s64 + 17584;
	// addi r6,r10,17568
	ctx.r6.s64 = ctx.r10.s64 + 17568;
	// addi r5,r9,17552
	ctx.r5.s64 = ctx.r9.s64 + 17552;
	// addi r4,r8,17536
	ctx.r4.s64 = ctx.r8.s64 + 17536;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824D350C:
	// vmrglw128 v59,v63,v61
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// vmrglw128 v58,v62,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// li r7,48
	ctx.r7.s64 = 48;
	// vmrghw128 v57,v63,v61
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// li r8,32
	ctx.r8.s64 = 32;
	// vmrghw128 v56,v62,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// vmrglw128 v55,v59,v58
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// li r4,16
	ctx.r4.s64 = 16;
	// vmrghw128 v54,v59,v58
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lis r31,-32254
	r31.s64 = -2113798144;
	// vmrglw128 v53,v57,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// addi r30,r1,-32
	r30.s64 = ctx.r1.s64 + -32;
	// vmrghw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,15000(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 15000);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v55,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stw r10,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// stfs f0,-24(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// stw r10,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r10.u32);
	// lvx128 v51,r0,r30
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r9,121(r3)
	PPC_STORE_U8(ctx.r3.u32 + 121, ctx.r9.u8);
	// stfs f12,112(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// stb r9,120(r3)
	PPC_STORE_U8(ctx.r3.u32 + 120, ctx.r9.u8);
	// stfs f13,116(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stb r10,122(r3)
	PPC_STORE_U8(ctx.r3.u32 + 122, ctx.r10.u8);
	// stvx128 v51,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D3498) {
	__imp__sub_824D3498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D35B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D35B4) {
	__imp__sub_824D35B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D35B8) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,17664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17664);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f1,f0,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// lfs f0,18204(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 18204);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dbae8
	ctx.lr = 0x824D35E8;
	sub_823DBAE8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,-31376(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31376);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f11,f13,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + f0.f64));
	// fsel f9,f10,f10,f12
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : ctx.f12.f64;
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsel f7,f8,f0,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// fsubs f1,f0,f7
	ctx.f1.f64 = double(float(f0.f64 - ctx.f7.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D35B8) {
	__imp__sub_824D35B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3628) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,17664(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17664);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f1,f0,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f13.f64));
	// lfs f0,18204(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 18204);
	f0.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x824D3668;
	sub_823DBBC8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// stfs f12,0(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x823dbae8
	ctx.lr = 0x824D3678;
	sub_823DBAE8(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// stfs f11,4(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D3628) {
	__imp__sub_824D3628(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D36A8) {
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
	ctx.lr = 0x824D36B0;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r28,r30,16
	r28.s64 = r30.s64 + 16;
	// li r9,2
	ctx.r9.s64 = 2;
	// lfs f0,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,4(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x824D36F4;
	sub_8218A6E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	f0.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lfs f12,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f11,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// fdivs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 / f0.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r5,8(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x824D373C;
	sub_8218A6E0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// stfs f31,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,12(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// rlwinm r27,r11,24,24,31
	r27.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f0,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f0.f64 = double(temp.f32);
	// rlwinm r10,r11,16,24,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// li r7,16
	ctx.r7.s64 = 16;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r27,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r27.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// fcfid f5,f10
	ctx.f5.f64 = double(ctx.f10.s64);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fcfid f6,f9
	ctx.f6.f64 = double(ctx.f9.s64);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// fmuls f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 * f0.f64));
	// stfs f1,120(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmuls f12,f2,f0
	ctx.f12.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fmuls f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x824D37C0;
	sub_8218A6E0(ctx, base);
loc_824D37C0:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d37c0
	if (cr6.eq) goto loc_824D37C0;
	// ld r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lfs f13,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// subf r8,r10,r11
	ctx.r8.s64 = r11.s64 - ctx.r10.s64;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,17668(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17668);
	f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f30,f10,f0
	f30.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmuls f1,f13,f30
	ctx.f1.f64 = double(float(ctx.f13.f64 * f30.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x824D3800;
	sub_823DBBC8(ctx, base);
	// frsp f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f1.f64));
	// lfs f8,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f30
	ctx.f7.f64 = double(float(ctx.f8.f64 * f30.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f7,144(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f0,31308(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31308);
	f0.f64 = double(temp.f32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lfs f13,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// fadds f6,f9,f31
	ctx.f6.f64 = double(float(ctx.f9.f64 + f31.f64));
	// fmuls f5,f7,f0
	ctx.f5.f64 = double(float(ctx.f7.f64 * f0.f64));
	// stfs f5,152(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmuls f4,f6,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// stfs f4,148(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x824D3854;
	sub_8218A6E0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r5,20(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x824D3868;
	sub_82189CE0(ctx, base);
	// lfs f3,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f2,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	ctx.f2.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f1,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f1.f64 = double(temp.f32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f0,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	f0.f64 = double(temp.f32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f3,128(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stfs f2,132(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r5,24(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// stfs f1,136(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// stfs f0,140(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// bl 0x8218a6e0
	ctx.lr = 0x824D38A8;
	sub_8218A6E0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lbz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r5,28(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a758
	ctx.lr = 0x824D38BC;
	sub_8218A758(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824D36A8) {
	__imp__sub_824D36A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D38CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D38CC) {
	__imp__sub_824D38CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D38D0) {
	PPC_FUNC_PROLOGUE();
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x824D38D8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// li r9,2
	ctx.r9.s64 = 2;
	// lfs f0,16(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	f0.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,4(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x824D3914;
	sub_8218A6E0(ctx, base);
	// lfs f13,24(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,8(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// bl 0x8218a6e0
	ctx.lr = 0x824D393C;
	sub_8218A6E0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f12,32(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,36(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// lfs f10,40(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// addi r26,r1,96
	r26.s64 = ctx.r1.s64 + 96;
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f0,15364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15364);
	f0.f64 = double(temp.f32);
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r5,12(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// rlwinm r25,r11,16,24,31
	r25.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// rlwinm r24,r11,24,24,31
	r24.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// std r25,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r25.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r24,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r24.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// fcfid f4,f9
	ctx.f4.f64 = double(ctx.f9.s64);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// fcfid f5,f8
	ctx.f5.f64 = double(ctx.f8.s64);
	// frsp f1,f4
	ctx.f1.f64 = double(float(ctx.f4.f64));
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// fmuls f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f13,f3,f0
	ctx.f13.f64 = double(float(ctx.f3.f64 * f0.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f12,f2,f0
	ctx.f12.f64 = double(float(ctx.f2.f64 * f0.f64));
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8218a6e0
	ctx.lr = 0x824D39F4;
	sub_8218A6E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lbz r6,28(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 28);
	// lwz r5,16(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218a758
	ctx.lr = 0x824D3A08;
	sub_8218A758(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_824D38D0) {
	__imp__sub_824D38D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3A10) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824D3A40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_824D3A10) {
	__imp__sub_824D3A10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3A58) {
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
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x824D3A88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_824D3A58) {
	__imp__sub_824D3A58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3AA0) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,17704
	ctx.r4.s64 = r11.s64 + 17704;
	// bl 0x8218a568
	ctx.lr = 0x824D3AC0;
	sub_8218A568(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D3AA0) {
	__imp__sub_824D3AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D3ADC) {
	__imp__sub_824D3ADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29920(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29920);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D3AE0) {
	__imp__sub_824D3AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D3AEC) {
	__imp__sub_824D3AEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3AF0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
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
	PPCRegister temp{};
	// li r11,32
	r11.s64 = 32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lvx128 v62,r4,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x824d3b58
	if (cr6.eq) goto loc_824D3B58;
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// addi r7,r9,-31664
	ctx.r7.s64 = ctx.r9.s64 + -31664;
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v61,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vrefp128 v0,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v60.f32)));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// lvx128 v13,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v59,v63,v9
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_824D3B58:
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v57,r5,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v56,v58,v57
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// vmrglw128 v55,v58,v57
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// stfs f0,-12(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// stfs f1,8(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// lvx128 v54,r5,r10
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r5,r9
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v52,v53,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v51,v53,v54
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vmrghw128 v50,v56,v52
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v49,v55,v51
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrglw128 v48,v56,v52
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum3fp128 v47,v63,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vmsum3fp128 v46,v63,v49
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// vmsum3fp128 v45,v63,v48
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vmrghw128 v44,v47,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v43,v45,v44
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vmrghw128 v42,v44,v43
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stvx128 v42,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	f0.f64 = double(temp.f32);
	// lfs f13,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D3AF0) {
	__imp__sub_824D3AF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3BD0) {
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
	ctx.lr = 0x824D3BD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,17928
	ctx.r4.s64 = r11.s64 + 17928;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D3C0C;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,17896
	ctx.r4.s64 = ctx.r7.s64 + 17896;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D3C34;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r10,17704
	ctx.r4.s64 = ctx.r10.s64 + 17704;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D3C5C;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// addi r4,r6,17860
	ctx.r4.s64 = ctx.r6.s64 + 17860;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D3C84;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r4,r9,17844
	ctx.r4.s64 = ctx.r9.s64 + 17844;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D3CAC;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r4,r11
	ctx.r4.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// addi r4,r5,17832
	ctx.r4.s64 = ctx.r5.s64 + 17832;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D3CD4;
	sub_8218A568(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r4,r9,17812
	ctx.r4.s64 = ctx.r9.s64 + 17812;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D3CFC;
	sub_8218A568(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r4,-32249
	ctx.r4.s64 = -2113470464;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,17800
	ctx.r4.s64 = ctx.r4.s64 + 17800;
	// bl 0x8218a568
	ctx.lr = 0x824D3D14;
	sub_8218A568(ctx, base);
	// lis r11,-32249
	r11.s64 = -2113470464;
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// addi r4,r11,17792
	ctx.r4.s64 = r11.s64 + 17792;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x824D3D2C;
	sub_8218A568(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,17772
	ctx.r4.s64 = ctx.r10.s64 + 17772;
	// bl 0x8218a568
	ctx.lr = 0x824D3D44;
	sub_8218A568(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,17752
	ctx.r4.s64 = ctx.r9.s64 + 17752;
	// bl 0x8218a568
	ctx.lr = 0x824D3D5C;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D3BD0) {
	__imp__sub_824D3BD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3D68) {
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
	// li r3,48
	ctx.r3.s64 = 48;
	// bl 0x82130528
	ctx.lr = 0x824D3D7C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d3da0
	if (cr6.eq) goto loc_824D3DA0;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,17744
	ctx.r10.s64 = r11.s64 + 17744;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824D3DA0:
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

PPC_WEAK_FUNC(sub_824D3D68) {
	__imp__sub_824D3D68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D3DB4) {
	__imp__sub_824D3DB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3DB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f4
	ctx.lr = 0x824D3DC0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,16
	r11.s64 = 16;
	// addi r28,r29,48
	r28.s64 = r29.s64 + 48;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r28,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r28,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v60,r28,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x824d3af0
	ctx.lr = 0x824D3E28;
	sub_824D3AF0(ctx, base);
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,4(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r9,4
	ctx.r9.s64 = 4;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// bl 0x8218a6e0
	ctx.lr = 0x824D3E4C;
	sub_8218A6E0(ctx, base);
	// lfs f0,112(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 112);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r5,8(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// bl 0x8218a6e0
	ctx.lr = 0x824D3E74;
	sub_8218A6E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,12(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x824D3E94;
	sub_8218A6E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,16(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r29,64
	ctx.r6.s64 = r29.s64 + 64;
	// bl 0x8218a6e0
	ctx.lr = 0x824D3EB4;
	sub_8218A6E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,20(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r5,20(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x824D3EC8;
	sub_82189CE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,16(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r5,24(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x824D3EDC;
	sub_82189CE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,24(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r5,28(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 28);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x824D3EF0;
	sub_82189CE0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,28(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwz r5,32(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x824D3F04;
	sub_82189CE0(ctx, base);
	// lbz r6,121(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 121);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,36(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218a758
	ctx.lr = 0x824D3F18;
	sub_8218A758(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lbz r6,120(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 120);
	// lwz r5,40(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8218a758
	ctx.lr = 0x824D3F2C;
	sub_8218A758(ctx, base);
	// lfs f13,116(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// lwz r5,44(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8218a6e0
	ctx.lr = 0x824D3F54;
	sub_8218A6E0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_824D3DB8) {
	__imp__sub_824D3DB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D3F5C) {
	__imp__sub_824D3F5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D3F60) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,17676
	ctx.r10.s64 = r11.s64 + 17676;
	// lwz r31,16(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d3fc0
	if (cr6.eq) goto loc_824D3FC0;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x824D3F98;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824d3fc0
	if (!cr6.eq) goto loc_824D3FC0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d3fc0
	if (cr6.eq) goto loc_824D3FC0;
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
	ctx.lr = 0x824D3FC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D3FC0:
	// lwz r31,20(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d3ffc
	if (cr6.eq) goto loc_824D3FFC;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x824D3FD4;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824d3ffc
	if (!cr6.eq) goto loc_824D3FFC;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d3ffc
	if (cr6.eq) goto loc_824D3FFC;
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
	ctx.lr = 0x824D3FFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D3FFC:
	// lwz r31,24(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d4038
	if (cr6.eq) goto loc_824D4038;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x824D4010;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824d4038
	if (!cr6.eq) goto loc_824D4038;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d4038
	if (cr6.eq) goto loc_824D4038;
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
	ctx.lr = 0x824D4038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D4038:
	// lwz r31,28(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d4074
	if (cr6.eq) goto loc_824D4074;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x824D404C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824d4074
	if (!cr6.eq) goto loc_824D4074;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d4074
	if (cr6.eq) goto loc_824D4074;
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
	ctx.lr = 0x824D4074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D4074:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822dda48
	ctx.lr = 0x824D407C;
	sub_822DDA48(ctx, base);
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

PPC_WEAK_FUNC(sub_824D3F60) {
	__imp__sub_824D3F60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D4094) {
	__imp__sub_824D4094(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4098) {
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
	// bl 0x824d3f60
	ctx.lr = 0x824D40B8;
	sub_824D3F60(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d40d0
	if (cr6.eq) goto loc_824D40D0;
	// bl 0x82130588
	ctx.lr = 0x824D40CC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824D40D0:
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

PPC_WEAK_FUNC(sub_824D4098) {
	__imp__sub_824D4098(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D40E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// addi r7,r8,17976
	ctx.r7.s64 = ctx.r8.s64 + 17976;
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// ld r6,-16(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
loc_824D4114:
	// mftb r11
	r11.u64 = __rdtsc();
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x824d4114
	if (cr6.eq) goto loc_824D4114;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, r11.u64);
	// lis r9,-100
	ctx.r9.s64 = -6553600;
	// li r8,1
	ctx.r8.s64 = 1;
	// ori r7,r9,40092
	ctx.r7.u64 = ctx.r9.u64 | 40092;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stw r7,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r7.u32);
	// stb r8,64(r3)
	PPC_STORE_U8(ctx.r3.u32 + 64, ctx.r8.u8);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lfs f13,30712(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 30712);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lfs f0,-12084(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -12084);
	f0.f64 = double(temp.f32);
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// stfs f13,32(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lfs f12,31296(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31296);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,17968(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17968);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,17964(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17964);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,17960(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17960);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,17956(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17956);
	ctx.f8.f64 = double(temp.f32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f12,44(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f11,48(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f10,52(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f9,56(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f8,60(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D40E8) {
	__imp__sub_824D40E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D41A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D41A4) {
	__imp__sub_824D41A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D41A8) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,18004
	ctx.r4.s64 = r11.s64 + 18004;
	// bl 0x8218a568
	ctx.lr = 0x824D41C8;
	sub_8218A568(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D41A8) {
	__imp__sub_824D41A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D41E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D41E4) {
	__imp__sub_824D41E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D41E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29928(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29928);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D41E8) {
	__imp__sub_824D41E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D41F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D41F4) {
	__imp__sub_824D41F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D41F8) {
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
	ctx.lr = 0x824D4200;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,18096
	ctx.r4.s64 = r11.s64 + 18096;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D4234;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,18084
	ctx.r4.s64 = ctx.r7.s64 + 18084;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D425C;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r10,18072
	ctx.r4.s64 = ctx.r10.s64 + 18072;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D4284;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// addi r4,r6,18060
	ctx.r4.s64 = ctx.r6.s64 + 18060;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D42AC;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r4,r9,18040
	ctx.r4.s64 = ctx.r9.s64 + 18040;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D42D4;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r5,-32249
	ctx.r5.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r4,r11
	ctx.r4.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// addi r4,r5,18004
	ctx.r4.s64 = ctx.r5.s64 + 18004;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D42FC;
	sub_8218A568(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,18028
	ctx.r4.s64 = ctx.r9.s64 + 18028;
	// bl 0x8218a568
	ctx.lr = 0x824D4314;
	sub_8218A568(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D41F8) {
	__imp__sub_824D41F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4320) {
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
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x824D4334;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d4358
	if (cr6.eq) goto loc_824D4358;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,18020
	ctx.r10.s64 = r11.s64 + 18020;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824D4358:
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

PPC_WEAK_FUNC(sub_824D4320) {
	__imp__sub_824D4320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D436C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D436C) {
	__imp__sub_824D436C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4370) {
	PPC_FUNC_PROLOGUE();
	// b 0x824d36a8
	sub_824D36A8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_824D4370) {
	__imp__sub_824D4370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D4374) {
	__imp__sub_824D4374(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4378) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,17976
	ctx.r10.s64 = r11.s64 + 17976;
	// lwz r31,68(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d43d8
	if (cr6.eq) goto loc_824D43D8;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x824D43B0;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x824d43d8
	if (!cr6.eq) goto loc_824D43D8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x824d43d8
	if (cr6.eq) goto loc_824D43D8;
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
	ctx.lr = 0x824D43D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_824D43D8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822dda48
	ctx.lr = 0x824D43E0;
	sub_822DDA48(ctx, base);
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

PPC_WEAK_FUNC(sub_824D4378) {
	__imp__sub_824D4378(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D43F8) {
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
	// bl 0x824d4378
	ctx.lr = 0x824D4418;
	sub_824D4378(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x824d4430
	if (cr6.eq) goto loc_824D4430;
	// bl 0x82130588
	ctx.lr = 0x824D442C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_824D4430:
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

PPC_WEAK_FUNC(sub_824D43F8) {
	__imp__sub_824D43F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4448) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,18144
	ctx.r4.s64 = r11.s64 + 18144;
	// bl 0x8218a568
	ctx.lr = 0x824D4468;
	sub_8218A568(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D4448) {
	__imp__sub_824D4448(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4484) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D4484) {
	__imp__sub_824D4484(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4488) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29932(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29932);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D4488) {
	__imp__sub_824D4488(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D4494) {
	__imp__sub_824D4494(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4498) {
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
	ctx.lr = 0x824D44A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32131
	r29.s64 = -2105737216;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,18200
	ctx.r4.s64 = r11.s64 + 18200;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r5,r8,1
	ctx.r5.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D44D4;
	sub_8218A568(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r7,-32249
	ctx.r7.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r6,r11
	ctx.r6.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,18184
	ctx.r4.s64 = ctx.r7.s64 + 18184;
	// rlwinm r11,r5,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r11,1
	ctx.r5.u64 = r11.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D44FC;
	sub_8218A568(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// lwz r11,30516(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 30516);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r10,18144
	ctx.r4.s64 = ctx.r10.s64 + 18144;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r5,r7,1
	ctx.r5.u64 = ctx.r7.u64 ^ 1;
	// bl 0x8218a568
	ctx.lr = 0x824D4524;
	sub_8218A568(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r6,-32249
	ctx.r6.s64 = -2113470464;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,18172
	ctx.r4.s64 = ctx.r6.s64 + 18172;
	// bl 0x8218a568
	ctx.lr = 0x824D453C;
	sub_8218A568(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_824D4498) {
	__imp__sub_824D4498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4548) {
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
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x824D455C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x824d4580
	if (cr6.eq) goto loc_824D4580;
	// lis r11,-32249
	r11.s64 = -2113470464;
	// addi r10,r11,18164
	ctx.r10.s64 = r11.s64 + 18164;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_824D4580:
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

PPC_WEAK_FUNC(sub_824D4548) {
	__imp__sub_824D4548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D4594) {
	__imp__sub_824D4594(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4598) {
	PPC_FUNC_PROLOGUE();
	// b 0x824d38d0
	sub_824D38D0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_824D4598) {
	__imp__sub_824D4598(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D459C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D459C) {
	__imp__sub_824D459C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D45A0) {
	PPC_FUNC_PROLOGUE();
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
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x824D45A8;
	// addi r11,r1,-64
	r11.s64 = ctx.r1.s64 + -64;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r8,-32249
	ctx.r8.s64 = -2113470464;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// std r10,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r10.u64);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,-332(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -332);
	ctx.f13.f64 = double(temp.f32);
	// lis r31,-32255
	r31.s64 = -2113863680;
	// addi r7,r8,18220
	ctx.r7.s64 = ctx.r8.s64 + 18220;
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// addi r8,r3,228
	ctx.r8.s64 = ctx.r3.s64 + 228;
	// lfs f12,32680(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32680);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,17032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r3,80
	r11.s64 = ctx.r3.s64 + 80;
	// lfs f10,-32032(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -32032);
	ctx.f10.f64 = double(temp.f32);
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,48
	ctx.r4.s64 = 48;
	// li r31,64
	r31.s64 = 64;
	// li r30,80
	r30.s64 = 80;
	// li r29,96
	r29.s64 = 96;
	// li r28,112
	r28.s64 = 112;
	// li r27,128
	r27.s64 = 128;
	// li r26,1
	r26.s64 = 1;
	// ld r8,-64(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// std r8,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r8.u64);
	// stw r9,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f12,32(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f12,36(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f11,48(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f10,52(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f11,56(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stb r26,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, r26.u8);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, ctx.r10.u32);
	// stw r10,228(r3)
	PPC_STORE_U32(ctx.r3.u32 + 228, ctx.r10.u32);
	// stw r10,232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 232, ctx.r10.u32);
	// stw r10,236(r3)
	PPC_STORE_U32(ctx.r3.u32 + 236, ctx.r10.u32);
	// stw r10,240(r3)
	PPC_STORE_U32(ctx.r3.u32 + 240, ctx.r10.u32);
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_824D45A0) {
	__imp__sub_824D45A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D4694) {
	__imp__sub_824D4694(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D4698) {
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
	// lis r11,-32249
	r11.s64 = -2113470464;
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,18248
	ctx.r4.s64 = r11.s64 + 18248;
	// bl 0x8218a568
	ctx.lr = 0x824D46B8;
	sub_8218A568(ctx, base);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D4698) {
	__imp__sub_824D4698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D46D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_824D46D4) {
	__imp__sub_824D46D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_824D46D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r3,29936(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 29936);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_824D46D8) {
	__imp__sub_824D46D8(ctx, base);
}

