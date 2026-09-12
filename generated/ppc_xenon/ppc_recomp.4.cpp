#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_821540E0"))) PPC_WEAK_FUNC(sub_821540E0);
PPC_FUNC_IMPL(__imp__sub_821540E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82154038
	sub_82154038(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821540E4"))) PPC_WEAK_FUNC(sub_821540E4);
PPC_FUNC_IMPL(__imp__sub_821540E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821540E8"))) PPC_WEAK_FUNC(sub_821540E8);
PPC_FUNC_IMPL(__imp__sub_821540E8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82153b50
	sub_82153B50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821540EC"))) PPC_WEAK_FUNC(sub_821540EC);
PPC_FUNC_IMPL(__imp__sub_821540EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821540F0"))) PPC_WEAK_FUNC(sub_821540F0);
PPC_FUNC_IMPL(__imp__sub_821540F0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82153f10
	sub_82153F10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821540F4"))) PPC_WEAK_FUNC(sub_821540F4);
PPC_FUNC_IMPL(__imp__sub_821540F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821540F8"))) PPC_WEAK_FUNC(sub_821540F8);
PPC_FUNC_IMPL(__imp__sub_821540F8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82154130
	if (cr6.eq) goto loc_82154130;
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
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154134
	goto loc_82154134;
loc_82154130:
	// li r11,0
	r11.s64 = 0;
loc_82154134:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82154148
	if (cr6.eq) goto loc_82154148;
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r9.u8);
loc_82154148:
	// lwz r3,212(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 212);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82154150"))) PPC_WEAK_FUNC(sub_82154150);
PPC_FUNC_IMPL(__imp__sub_82154150) {
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
	// bl 0x82153848
	ctx.lr = 0x82154170;
	sub_82153848(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82154198
	if (cr6.eq) goto loc_82154198;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82154198
	if (cr6.eq) goto loc_82154198;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82154198;
	sub_8213F7A8(ctx, base);
loc_82154198:
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

__attribute__((alias("__imp__sub_821541B4"))) PPC_WEAK_FUNC(sub_821541B4);
PPC_FUNC_IMPL(__imp__sub_821541B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821541B8"))) PPC_WEAK_FUNC(sub_821541B8);
PPC_FUNC_IMPL(__imp__sub_821541B8) {
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
	// bl 0x8213b968
	ctx.lr = 0x821541D0;
	sub_8213B968(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,255
	r11.s64 = 255;
	// addi r9,r10,23008
	ctx.r9.s64 = ctx.r10.s64 + 23008;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
	// stb r11,74(r31)
	PPC_STORE_U8(r31.u32 + 74, r11.u8);
	// stb r11,75(r31)
	PPC_STORE_U8(r31.u32 + 75, r11.u8);
	// stb r11,76(r31)
	PPC_STORE_U8(r31.u32 + 76, r11.u8);
	// stb r11,77(r31)
	PPC_STORE_U8(r31.u32 + 77, r11.u8);
	// stb r11,78(r31)
	PPC_STORE_U8(r31.u32 + 78, r11.u8);
	// stb r11,79(r31)
	PPC_STORE_U8(r31.u32 + 79, r11.u8);
	// stw r10,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r10.u32);
	// stw r10,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r10.u32);
	// stw r10,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r10.u32);
	// stb r11,192(r31)
	PPC_STORE_U8(r31.u32 + 192, r11.u8);
	// stb r8,193(r31)
	PPC_STORE_U8(r31.u32 + 193, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_82154234"))) PPC_WEAK_FUNC(sub_82154234);
PPC_FUNC_IMPL(__imp__sub_82154234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82154238"))) PPC_WEAK_FUNC(sub_82154238);
PPC_FUNC_IMPL(__imp__sub_82154238) {
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
	ctx.lr = 0x82154240;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r11,23008
	ctx.r10.s64 = r11.s64 + 23008;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r30,72
	r28.s64 = r30.s64 + 72;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_82154264:
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821542a4
	if (cr6.eq) goto loc_821542A4;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821542a4
	if (cr6.eq) goto loc_821542A4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x821542A4;
	sub_8214E5B8(ctx, base);
loc_821542A4:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,8
	cr6.compare<uint32_t>(r29.u32, 8, xer);
	// blt cr6,0x82154264
	if (cr6.lt) goto loc_82154264;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213ba48
	ctx.lr = 0x821542B8;
	sub_8213BA48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821542C0"))) PPC_WEAK_FUNC(sub_821542C0);
PPC_FUNC_IMPL(__imp__sub_821542C0) {
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
	ctx.lr = 0x821542C8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x821542DC;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821542f4
	if (!cr6.eq) goto loc_821542F4;
loc_821542E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
loc_821542F4:
	// lwz r25,148(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82154308:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82154308
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82154308;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r28,r11,19856
	r28.s64 = r11.s64 + 19856;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r28,608
	ctx.r3.s64 = r28.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8215433C;
	sub_82144720(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// beq cr6,0x82154378
	if (cr6.eq) goto loc_82154378;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x8215437c
	goto loc_8215437C;
loc_82154378:
	// li r11,255
	r11.s64 = 255;
loc_8215437C:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r26,r31,72
	r26.s64 = r31.s64 + 72;
	// stb r10,72(r31)
	PPC_STORE_U8(r31.u32 + 72, ctx.r10.u8);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82154398:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82154398
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82154398;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r4,4(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r28,608
	ctx.r3.s64 = r28.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x821543C4;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821543f8
	if (cr6.eq) goto loc_821543F8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x821543fc
	goto loc_821543FC;
loc_821543F8:
	// li r11,255
	r11.s64 = 255;
loc_821543FC:
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stb r9,73(r31)
	PPC_STORE_U8(r31.u32 + 73, ctx.r9.u8);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82154414:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82154414
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82154414;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r28,608
	ctx.r3.s64 = r28.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x82154440;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82154474
	if (cr6.eq) goto loc_82154474;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x82154478
	goto loc_82154478;
loc_82154474:
	// li r11,255
	r11.s64 = 255;
loc_82154478:
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stb r10,74(r31)
	PPC_STORE_U8(r31.u32 + 74, ctx.r10.u8);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82154490:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82154490
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82154490;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r4,4(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r28,608
	ctx.r3.s64 = r28.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x821544BC;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821544f0
	if (cr6.eq) goto loc_821544F0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x821544f4
	goto loc_821544F4;
loc_821544F0:
	// li r11,255
	r11.s64 = 255;
loc_821544F4:
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r11,75(r31)
	PPC_STORE_U8(r31.u32 + 75, r11.u8);
loc_821544FC:
	// lbzx r9,r26,r8
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + ctx.r8.u32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821542e8
	if (cr6.eq) goto loc_821542E8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r7,196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r7,r9
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add. r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq 0x821542e8
	if (cr0.eq) goto loc_821542E8;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r8,4
	cr6.compare<int32_t>(ctx.r8.s32, 4, xer);
	// blt cr6,0x821544fc
	if (cr6.lt) goto loc_821544FC;
	// lwz r4,16(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8215455c
	if (cr6.eq) goto loc_8215455C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82154558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r3.u32);
loc_8215455C:
	// lwz r4,20(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82154580
	if (cr6.eq) goto loc_82154580;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8215457C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
loc_82154580:
	// lwz r4,24(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821545a4
	if (cr6.eq) goto loc_821545A4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821545A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
loc_821545A4:
	// lwz r4,28(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 28);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821545c8
	if (cr6.eq) goto loc_821545C8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821545C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
loc_821545C8:
	// lwz r4,32(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821545ec
	if (cr6.eq) goto loc_821545EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821545E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
loc_821545EC:
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82154698
	if (cr6.eq) goto loc_82154698;
	// lwz r8,184(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154698
	if (cr6.eq) goto loc_82154698;
	// lbz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154634
	if (cr6.eq) goto loc_82154634;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r7,196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// mullw r10,r7,r9
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154638
	goto loc_82154638;
loc_82154634:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154638:
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8213b778
	ctx.lr = 0x8215464C;
	sub_8213B778(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215467c
	if (cr6.eq) goto loc_8215467C;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154680
	goto loc_82154680;
loc_8215467C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154680:
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x8215470c
	goto loc_8215470C;
loc_82154698:
	// lbz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821546c8
	if (cr6.eq) goto loc_821546C8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
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
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821546cc
	goto loc_821546CC;
loc_821546C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821546CC:
	// li r4,270
	ctx.r4.s64 = 270;
	// bl 0x8213b778
	ctx.lr = 0x821546D4;
	sub_8213B778(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82154704
	if (cr6.eq) goto loc_82154704;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154708
	goto loc_82154708;
loc_82154704:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154708:
	// li r4,90
	ctx.r4.s64 = 90;
loc_8215470C:
	// bl 0x8213b778
	ctx.lr = 0x82154710;
	sub_8213B778(ctx, base);
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// lwz r10,12(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// lbz r9,36(r25)
	ctx.r9.u64 = PPC_LOAD_U8(r25.u32 + 36);
	// stb r9,193(r31)
	PPC_STORE_U8(r31.u32 + 193, ctx.r9.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82154744"))) PPC_WEAK_FUNC(sub_82154744);
PPC_FUNC_IMPL(__imp__sub_82154744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82154748"))) PPC_WEAK_FUNC(sub_82154748);
PPC_FUNC_IMPL(__imp__sub_82154748) {
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
	ctx.lr = 0x82154750;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r26,1
	r26.s64 = 1;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// subfic r25,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r25.s64 = -72 - r30.s64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_82154774:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215482c
	if (cr6.eq) goto loc_8215482C;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r10,11440(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8215482c
	if (cr6.eq) goto loc_8215482C;
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821547c4
	if (cr6.eq) goto loc_821547C4;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821547c8
	goto loc_821547C8;
loc_821547C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821547C8:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x821547D0;
	sub_8213B7B0(ctx, base);
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// lbz r10,57(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x82154808
	if (cr6.eq) goto loc_82154808;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215480c
	goto loc_8215480C;
loc_82154808:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215480C:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213da88
	ctx.lr = 0x82154818;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82154854
	if (cr6.eq) goto loc_82154854;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8215482c
	if (!cr6.eq) goto loc_8215482C;
	// li r26,0
	r26.s64 = 0;
loc_8215482C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r25,r29
	r11.u64 = r25.u64 + r29.u64;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x82154774
	if (cr6.lt) goto loc_82154774;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82154854:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82154860"))) PPC_WEAK_FUNC(sub_82154860);
PPC_FUNC_IMPL(__imp__sub_82154860) {
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
	ctx.lr = 0x82154868;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// li r28,4
	r28.s64 = 4;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82154884:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821548d4
	if (cr6.eq) goto loc_821548D4;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821548d4
	if (cr6.eq) goto loc_821548D4;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821548c8
	if (cr6.eq) goto loc_821548C8;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821548cc
	goto loc_821548CC;
loc_821548C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821548CC:
	// bl 0x8213b5c0
	ctx.lr = 0x821548D0;
	sub_8213B5C0(ctx, base);
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_821548D4:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x82154884
	if (!cr0.eq) goto loc_82154884;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821548E8"))) PPC_WEAK_FUNC(sub_821548E8);
PPC_FUNC_IMPL(__imp__sub_821548E8) {
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
	ctx.lr = 0x821548F0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// mr r28,r25
	r28.u64 = r25.u64;
	// li r27,4
	r27.s64 = 4;
	// li r24,1
	r24.s64 = 1;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_82154918:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215499c
	if (cr6.eq) goto loc_8215499C;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mullw r9,r8,r10
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r8,11440(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8215499c
	if (cr6.eq) goto loc_8215499C;
	// stb r25,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r25.u8);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215496c
	if (cr6.eq) goto loc_8215496C;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r9,11440(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// mullw r11,r8,r10
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82154970
	goto loc_82154970;
loc_8215496C:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_82154970:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x82154978;
	sub_8213C758(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82154990
	if (cr6.eq) goto loc_82154990;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82154990
	if (cr6.eq) goto loc_82154990;
	// stb r24,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r24.u8);
loc_82154990:
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// ble cr6,0x8215499c
	if (!cr6.gt) goto loc_8215499C;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8215499C:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x82154918
	if (!cr0.eq) goto loc_82154918;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821549B4"))) PPC_WEAK_FUNC(sub_821549B4);
PPC_FUNC_IMPL(__imp__sub_821549B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821549B8"))) PPC_WEAK_FUNC(sub_821549B8);
PPC_FUNC_IMPL(__imp__sub_821549B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// stfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f29.u64);
	// stfd f30,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,164(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f30,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x82154a10
	if (!cr6.lt) goto loc_82154A10;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82154a10
	if (!cr6.eq) goto loc_82154A10;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82154a10
	if (!cr6.eq) goto loc_82154A10;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// b 0x82154d30
	goto loc_82154D30;
loc_82154A10:
	// lbz r11,193(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 193);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82154a34
	if (!cr6.eq) goto loc_82154A34;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82154a34
	if (!cr6.eq) goto loc_82154A34;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82154d30
	goto loc_82154D30;
loc_82154A34:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// lfs f29,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f29.f64 = double(temp.f32);
	// beq cr6,0x82154a74
	if (cr6.eq) goto loc_82154A74;
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bgt cr6,0x82154a64
	if (cr6.gt) goto loc_82154A64;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// b 0x82154b54
	goto loc_82154B54;
loc_82154A64:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// blt cr6,0x82154b54
	if (cr6.lt) goto loc_82154B54;
	// fmr f31,f29
	f31.f64 = f29.f64;
	// b 0x82154b54
	goto loc_82154B54;
loc_82154A74:
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,200(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lbz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// mullw r11,r6,r10
	r11.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r8,26644
	ctx.r10.s64 = ctx.r8.s64 + 26644;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// lbz r9,199(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// rlwinm r8,r9,30,2,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFF8;
	// lwz r4,26660(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 26660);
	// lwzx r10,r8,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v63,r9,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215f0a8
	ctx.lr = 0x82154ADC;
	sub_8215F0A8(ctx, base);
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,172(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsqrts f13,f10
	ctx.f13.f64 = double(float(sqrt(ctx.f10.f64)));
	// beq cr6,0x82154b0c
	if (cr6.eq) goto loc_82154B0C;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// b 0x82154b10
	goto loc_82154B10;
loc_82154B0C:
	// lfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	f0.f64 = double(temp.f32);
loc_82154B10:
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82154b24
	if (cr6.eq) goto loc_82154B24;
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// b 0x82154b28
	goto loc_82154B28;
loc_82154B24:
	// lfs f12,168(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
loc_82154B28:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82154b38
	if (cr6.gt) goto loc_82154B38;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// b 0x82154b54
	goto loc_82154B54;
loc_82154B38:
	// fcmpu cr6,f13,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// blt cr6,0x82154b48
	if (cr6.lt) goto loc_82154B48;
	// fmr f31,f29
	f31.f64 = f29.f64;
	// b 0x82154b54
	goto loc_82154B54;
loc_82154B48:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fdivs f31,f13,f12
	f31.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
loc_82154B54:
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// fsubs f12,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f29.f64 - f31.f64));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f30,84(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f30,88(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f30,100(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r7,22720
	ctx.r5.s64 = ctx.r7.s64 + 22720;
	// stfs f30,104(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v59,v62
	ctx.fpscr.enableFlushModeUnconditional();
	v59.f32[0] = log2f(v62.f32[0]);
	v59.f32[1] = log2f(v62.f32[1]);
	v59.f32[2] = log2f(v62.f32[2]);
	v59.f32[3] = log2f(v62.f32[3]);
	// vlogefp128 v60,v61
	v60.f32[0] = log2f(v61.f32[0]);
	v60.f32[1] = log2f(v61.f32[1]);
	v60.f32[2] = log2f(v61.f32[2]);
	v60.f32[3] = log2f(v61.f32[3]);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v59,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,-24(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -24);
	f0.f64 = double(temp.f32);
	// lfs f13,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 - f0.f64));
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,-28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -28);
	f0.f64 = double(temp.f32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// vmulfp128 v58,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f29,f11,f6,f0
	f29.f64 = ctx.f11.f64 >= 0.0 ? ctx.f6.f64 : f0.f64;
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fsel f30,f10,f8,f0
	f30.f64 = ctx.f10.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// beq cr6,0x82154c30
	if (cr6.eq) goto loc_82154C30;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154c34
	if (cr6.eq) goto loc_82154C34;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154c24
	if (cr6.eq) goto loc_82154C24;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154c28
	goto loc_82154C28;
loc_82154C24:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154C28:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8213b768
	ctx.lr = 0x82154C30;
	sub_8213B768(ctx, base);
loc_82154C30:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82154C34:
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154c88
	if (cr6.eq) goto loc_82154C88;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154c88
	if (cr6.eq) goto loc_82154C88;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154c78
	if (cr6.eq) goto loc_82154C78;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154c7c
	goto loc_82154C7C;
loc_82154C78:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154C7C:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8213b768
	ctx.lr = 0x82154C84;
	sub_8213B768(ctx, base);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82154C88:
	// lbz r9,74(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 74);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154cdc
	if (cr6.eq) goto loc_82154CDC;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154cdc
	if (cr6.eq) goto loc_82154CDC;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154ccc
	if (cr6.eq) goto loc_82154CCC;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154cd0
	goto loc_82154CD0;
loc_82154CCC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154CD0:
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x8213b768
	ctx.lr = 0x82154CD8;
	sub_8213B768(ctx, base);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82154CDC:
	// lbz r9,75(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 75);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154d2c
	if (cr6.eq) goto loc_82154D2C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154d2c
	if (cr6.eq) goto loc_82154D2C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154d20
	if (cr6.eq) goto loc_82154D20;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154d24
	goto loc_82154D24;
loc_82154D20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154D24:
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x8213b768
	ctx.lr = 0x82154D2C;
	sub_8213B768(ctx, base);
loc_82154D2C:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_82154D30:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
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

__attribute__((alias("__imp__sub_82154D54"))) PPC_WEAK_FUNC(sub_82154D54);
PPC_FUNC_IMPL(__imp__sub_82154D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82154D58"))) PPC_WEAK_FUNC(sub_82154D58);
PPC_FUNC_IMPL(__imp__sub_82154D58) {
	PPC_FUNC_PROLOGUE();
	// b 0x82154860
	sub_82154860(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82154D5C"))) PPC_WEAK_FUNC(sub_82154D5C);
PPC_FUNC_IMPL(__imp__sub_82154D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82154D60"))) PPC_WEAK_FUNC(sub_82154D60);
PPC_FUNC_IMPL(__imp__sub_82154D60) {
	PPC_FUNC_PROLOGUE();
	// b 0x82154748
	sub_82154748(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82154D64"))) PPC_WEAK_FUNC(sub_82154D64);
PPC_FUNC_IMPL(__imp__sub_82154D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82154D68"))) PPC_WEAK_FUNC(sub_82154D68);
PPC_FUNC_IMPL(__imp__sub_82154D68) {
	PPC_FUNC_PROLOGUE();
	// b 0x821548e8
	sub_821548E8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82154D6C"))) PPC_WEAK_FUNC(sub_82154D6C);
PPC_FUNC_IMPL(__imp__sub_82154D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82154D70"))) PPC_WEAK_FUNC(sub_82154D70);
PPC_FUNC_IMPL(__imp__sub_82154D70) {
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
	// bl 0x82154238
	ctx.lr = 0x82154D90;
	sub_82154238(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82154db8
	if (cr6.eq) goto loc_82154DB8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82154db8
	if (cr6.eq) goto loc_82154DB8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82154DB8;
	sub_8213F7A8(ctx, base);
loc_82154DB8:
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

__attribute__((alias("__imp__sub_82154DD4"))) PPC_WEAK_FUNC(sub_82154DD4);
PPC_FUNC_IMPL(__imp__sub_82154DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82154DD8"))) PPC_WEAK_FUNC(sub_82154DD8);
PPC_FUNC_IMPL(__imp__sub_82154DD8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82154DE0;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x8213d168
	ctx.lr = 0x82154DF4;
	sub_8213D168(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lbz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r26,84(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// addi r28,r30,72
	r28.s64 = r30.s64 + 72;
	// stb r3,192(r30)
	PPC_STORE_U8(r30.u32 + 192, ctx.r3.u8);
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82154e64
	if (cr6.eq) goto loc_82154E64;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154e68
	if (cr6.eq) goto loc_82154E68;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82154e58
	if (cr6.eq) goto loc_82154E58;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82154e5c
	goto loc_82154E5C;
loc_82154E58:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154E5C:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213b768
	ctx.lr = 0x82154E64;
	sub_8213B768(ctx, base);
loc_82154E64:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82154E68:
	// lbz r9,73(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154ebc
	if (cr6.eq) goto loc_82154EBC;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154ebc
	if (cr6.eq) goto loc_82154EBC;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154eac
	if (cr6.eq) goto loc_82154EAC;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154eb0
	goto loc_82154EB0;
loc_82154EAC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154EB0:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213b768
	ctx.lr = 0x82154EB8;
	sub_8213B768(ctx, base);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82154EBC:
	// lbz r9,74(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 74);
	// lis r29,-32256
	r29.s64 = -2113929216;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154f14
	if (cr6.eq) goto loc_82154F14;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154f14
	if (cr6.eq) goto loc_82154F14;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154f04
	if (cr6.eq) goto loc_82154F04;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154f08
	goto loc_82154F08;
loc_82154F04:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154F08:
	// lfs f1,22692(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 22692);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213b768
	ctx.lr = 0x82154F10;
	sub_8213B768(ctx, base);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82154F14:
	// lbz r9,75(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 75);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154f68
	if (cr6.eq) goto loc_82154F68;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82154f68
	if (cr6.eq) goto loc_82154F68;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82154f58
	if (cr6.eq) goto loc_82154F58;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154f5c
	goto loc_82154F5C;
loc_82154F58:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154F5C:
	// lfs f1,22692(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 22692);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213b768
	ctx.lr = 0x82154F64;
	sub_8213B768(ctx, base);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82154F68:
	// lwz r10,188(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82155010
	if (cr6.eq) goto loc_82155010;
	// lwz r8,184(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82155010
	if (cr6.eq) goto loc_82155010;
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82154fac
	if (cr6.eq) goto loc_82154FAC;
	// lbz r7,64(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r7,11488
	r11.s64 = ctx.r7.s64 * 11488;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82154fb0
	goto loc_82154FB0;
loc_82154FAC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154FB0:
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8213b778
	ctx.lr = 0x82154FC4;
	sub_8213B778(ctx, base);
	// lbz r8,73(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82154ff4
	if (cr6.eq) goto loc_82154FF4;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x82154ff8
	goto loc_82154FF8;
loc_82154FF4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82154FF8:
	// lwz r11,188(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8213b778
	ctx.lr = 0x82155010;
	sub_8213B778(ctx, base);
loc_82155010:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821549b8
	ctx.lr = 0x8215501C;
	sub_821549B8(ctx, base);
	// lbz r11,193(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 193);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821551b4
	if (!cr6.eq) goto loc_821551B4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bne cr6,0x821550f4
	if (!cr6.eq) goto loc_821550F4;
	// lbz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155094
	if (cr6.eq) goto loc_82155094;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r11,11488
	ctx.r10.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82155098
	if (cr6.eq) goto loc_82155098;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155080
	if (cr6.eq) goto loc_82155080;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82155084
	goto loc_82155084;
loc_82155080:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82155084:
	// bl 0x8213b5c0
	ctx.lr = 0x82155088;
	sub_8213B5C0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82155094;
	sub_8214E5B8(ctx, base);
loc_82155094:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82155098:
	// lbz r9,73(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821551b8
	if (cr6.eq) goto loc_821551B8;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821551b8
	if (cr6.eq) goto loc_821551B8;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821550e4
	if (cr6.eq) goto loc_821550E4;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213b5c0
	ctx.lr = 0x821550DC;
	sub_8213B5C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821551ac
	goto loc_821551AC;
loc_821550E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8213b5c0
	ctx.lr = 0x821550EC;
	sub_8213B5C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x821551ac
	goto loc_821551AC;
loc_821550F4:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bne cr6,0x821551b4
	if (!cr6.eq) goto loc_821551B4;
	// lbz r9,74(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 74);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155158
	if (cr6.eq) goto loc_82155158;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r11,11488
	ctx.r10.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8215515c
	if (cr6.eq) goto loc_8215515C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155144
	if (cr6.eq) goto loc_82155144;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82155148
	goto loc_82155148;
loc_82155144:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82155148:
	// bl 0x8213b5c0
	ctx.lr = 0x8215514C;
	sub_8213B5C0(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82155158;
	sub_8214E5B8(ctx, base);
loc_82155158:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_8215515C:
	// lbz r9,75(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 75);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821551b8
	if (cr6.eq) goto loc_821551B8;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821551b8
	if (cr6.eq) goto loc_821551B8;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821551a0
	if (cr6.eq) goto loc_821551A0;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821551a4
	goto loc_821551A4;
loc_821551A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821551A4:
	// bl 0x8213b5c0
	ctx.lr = 0x821551A8;
	sub_8213B5C0(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
loc_821551AC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x821551B4;
	sub_8214E5B8(ctx, base);
loc_821551B4:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_821551B8:
	// mr r29,r28
	r29.u64 = r28.u64;
	// li r28,4
	r28.s64 = 4;
loc_821551C0:
	// lbz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155254
	if (cr6.eq) goto loc_82155254;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82155254
	if (cr6.eq) goto loc_82155254;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155204
	if (cr6.eq) goto loc_82155204;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82155208
	goto loc_82155208;
loc_82155204:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82155208:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x82155214;
	sub_8213B7B0(ctx, base);
	// lbz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82155244
	if (cr6.eq) goto loc_82155244;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x82155248
	goto loc_82155248;
loc_82155244:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82155248:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213d890
	ctx.lr = 0x82155250;
	sub_8213D890(ctx, base);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82155254:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x821551c0
	if (!cr0.eq) goto loc_821551C0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8215526C"))) PPC_WEAK_FUNC(sub_8215526C);
PPC_FUNC_IMPL(__imp__sub_8215526C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82155270"))) PPC_WEAK_FUNC(sub_82155270);
PPC_FUNC_IMPL(__imp__sub_82155270) {
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
	ctx.lr = 0x82155278;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// bl 0x821549b8
	ctx.lr = 0x82155290;
	sub_821549B8(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// lwz r11,188(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82155344
	if (cr6.eq) goto loc_82155344;
	// lwz r7,184(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82155344
	if (cr6.eq) goto loc_82155344;
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821552e0
	if (cr6.eq) goto loc_821552E0;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x821552e4
	goto loc_821552E4;
loc_821552E0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821552E4:
	// lfs f0,0(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8213b778
	ctx.lr = 0x821552F8;
	sub_8213B778(ctx, base);
	// lbz r8,73(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82155328
	if (cr6.eq) goto loc_82155328;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x8215532c
	goto loc_8215532C;
loc_82155328:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215532C:
	// lwz r11,188(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8213b778
	ctx.lr = 0x82155344;
	sub_8213B778(ctx, base);
loc_82155344:
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// li r28,4
	r28.s64 = 4;
loc_82155350:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821553d8
	if (cr6.eq) goto loc_821553D8;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821553d8
	if (cr6.eq) goto loc_821553D8;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82155394
	if (cr6.eq) goto loc_82155394;
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// b 0x82155398
	goto loc_82155398;
loc_82155394:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82155398:
	// lhz r9,6(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x821553d8
	if (!cr6.eq) goto loc_821553D8;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821553b8
	if (cr6.eq) goto loc_821553B8;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821553bc
	goto loc_821553BC;
loc_821553B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821553BC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213e040
	ctx.lr = 0x821553C4;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821553d8
	if (cr6.eq) goto loc_821553D8;
	// li r27,1
	r27.s64 = 1;
loc_821553D8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x82155350
	if (!cr0.eq) goto loc_82155350;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821553FC"))) PPC_WEAK_FUNC(sub_821553FC);
PPC_FUNC_IMPL(__imp__sub_821553FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82155400"))) PPC_WEAK_FUNC(sub_82155400);
PPC_FUNC_IMPL(__imp__sub_82155400) {
	PPC_FUNC_PROLOGUE();
	// b 0x82155270
	sub_82155270(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82155404"))) PPC_WEAK_FUNC(sub_82155404);
PPC_FUNC_IMPL(__imp__sub_82155404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82155408"))) PPC_WEAK_FUNC(sub_82155408);
PPC_FUNC_IMPL(__imp__sub_82155408) {
	PPC_FUNC_PROLOGUE();
	// b 0x82154dd8
	sub_82154DD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215540C"))) PPC_WEAK_FUNC(sub_8215540C);
PPC_FUNC_IMPL(__imp__sub_8215540C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82155410"))) PPC_WEAK_FUNC(sub_82155410);
PPC_FUNC_IMPL(__imp__sub_82155410) {
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
	// bl 0x82163ee8
	ctx.lr = 0x82155428;
	sub_82163EE8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
	// lfs f0,23060(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 23060);
	f0.f64 = double(temp.f32);
	// stw r10,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r10.u32);
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// lfs f12,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// stb r11,60(r31)
	PPC_STORE_U8(r31.u32 + 60, r11.u8);
	// addi r10,r31,40
	ctx.r10.s64 = r31.s64 + 40;
	// stb r11,61(r31)
	PPC_STORE_U8(r31.u32 + 61, r11.u8);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stb r5,114(r31)
	PPC_STORE_U8(r31.u32 + 114, ctx.r5.u8);
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stb r11,115(r31)
	PPC_STORE_U8(r31.u32 + 115, r11.u8);
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stb r11,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r11.u8);
	// stfs f12,80(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// stw r11,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// sth r4,112(r31)
	PPC_STORE_U16(r31.u32 + 112, ctx.r4.u16);
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

__attribute__((alias("__imp__sub_821554C4"))) PPC_WEAK_FUNC(sub_821554C4);
PPC_FUNC_IMPL(__imp__sub_821554C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821554C8"))) PPC_WEAK_FUNC(sub_821554C8);
PPC_FUNC_IMPL(__imp__sub_821554C8) {
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
	// bl 0x8213b968
	ctx.lr = 0x821554E0;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,255
	ctx.r10.s64 = 255;
	// addi r9,r11,23376
	ctx.r9.s64 = r11.s64 + 23376;
	// stb r10,164(r31)
	PPC_STORE_U8(r31.u32 + 164, ctx.r10.u8);
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

__attribute__((alias("__imp__sub_8215550C"))) PPC_WEAK_FUNC(sub_8215550C);
PPC_FUNC_IMPL(__imp__sub_8215550C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82155510"))) PPC_WEAK_FUNC(sub_82155510);
PPC_FUNC_IMPL(__imp__sub_82155510) {
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
	ctx.lr = 0x82155518;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,23376
	ctx.r10.s64 = r11.s64 + 23376;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r28,r31,72
	r28.s64 = r31.s64 + 72;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82155544:
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82155584
	if (cr6.eq) goto loc_82155584;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82155584
	if (cr6.eq) goto loc_82155584;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x8215557C;
	sub_8214E5B8(ctx, base);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82155584:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r29,8
	cr6.compare<uint32_t>(r29.u32, 8, xer);
	// blt cr6,0x82155544
	if (cr6.lt) goto loc_82155544;
	// lbz r11,164(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 164);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821555c4
	if (cr6.eq) goto loc_821555C4;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// mulli r11,r5,11488
	r11.s64 = ctx.r5.s64 * 11488;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,11440(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213f7a8
	ctx.lr = 0x821555BC;
	sub_8213F7A8(ctx, base);
	// li r10,255
	ctx.r10.s64 = 255;
	// stb r10,164(r31)
	PPC_STORE_U8(r31.u32 + 164, ctx.r10.u8);
loc_821555C4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x821555CC;
	sub_8213BA48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821555D4"))) PPC_WEAK_FUNC(sub_821555D4);
PPC_FUNC_IMPL(__imp__sub_821555D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821555D8"))) PPC_WEAK_FUNC(sub_821555D8);
PPC_FUNC_IMPL(__imp__sub_821555D8) {
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
	ctx.lr = 0x821555E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x821555F4;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821558b0
	if (cr6.eq) goto loc_821558B0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// li r4,120
	ctx.r4.s64 = 120;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213e928
	ctx.lr = 0x8215561C;
	sub_8213E928(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x821558b0
	if (cr6.eq) goto loc_821558B0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// twllei r10,0
	// lwz r8,11440(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// subf r7,r8,r26
	ctx.r7.s64 = r26.s64 - ctx.r8.s64;
	// divwu r6,r7,r10
	ctx.r6.u32 = ctx.r7.u32 / ctx.r10.u32;
	// stb r6,164(r31)
	PPC_STORE_U8(r31.u32 + 164, ctx.r6.u8);
	// bl 0x82155410
	ctx.lr = 0x82155654;
	sub_82155410(ctx, base);
	// addi r28,r26,40
	r28.s64 = r26.s64 + 40;
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82155668:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82155668
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82155668;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r25,148(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r27,r11,19856
	r27.s64 = r11.s64 + 19856;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r27,608
	ctx.r3.s64 = r27.s64 + 608;
	// lwz r4,0(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// bl 0x82144720
	ctx.lr = 0x821556A0;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821556d4
	if (cr6.eq) goto loc_821556D4;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x821556d8
	goto loc_821556D8;
loc_821556D4:
	// li r11,255
	r11.s64 = 255;
loc_821556D8:
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,23416
	ctx.r3.s64 = ctx.r10.s64 + 23416;
	// bl 0x821c9790
	ctx.lr = 0x821556EC;
	sub_821C9790(ctx, base);
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// mr r11,r28
	r11.u64 = r28.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82155700:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82155700
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82155700;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r4,4(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r27,608
	ctx.r3.s64 = r27.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8215572C;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82155760
	if (cr6.eq) goto loc_82155760;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x82155764
	goto loc_82155764;
loc_82155760:
	// li r11,255
	r11.s64 = 255;
loc_82155764:
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,23412
	ctx.r3.s64 = ctx.r10.s64 + 23412;
	// bl 0x821c9790
	ctx.lr = 0x82155778;
	sub_821C9790(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821558b0
	if (cr6.eq) goto loc_821558B0;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r9,r11,r8
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821558b0
	if (cr6.eq) goto loc_821558B0;
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821558b0
	if (cr6.eq) goto loc_821558B0;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821558b0
	if (cr6.eq) goto loc_821558B0;
	// lbz r11,8(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 8);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stb r11,114(r26)
	PPC_STORE_U8(r26.u32 + 114, r11.u8);
	// lwz r10,9(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 9);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stfs f0,72(r26)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r26.u32 + 72, temp.u32);
	// lwz r8,13(r25)
	ctx.r8.u64 = PPC_LOAD_U32(r25.u32 + 13);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,76(r26)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r26.u32 + 76, temp.u32);
	// lwz r7,17(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 17);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,80(r26)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r26.u32 + 80, temp.u32);
	// lwz r6,0(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// stw r6,100(r26)
	PPC_STORE_U32(r26.u32 + 100, ctx.r6.u32);
	// lwz r5,4(r25)
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// stw r5,104(r26)
	PPC_STORE_U32(r26.u32 + 104, ctx.r5.u32);
	// beq cr6,0x8215582c
	if (cr6.eq) goto loc_8215582C;
	// lbz r11,58(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 58);
	// ori r10,r11,32
	ctx.r10.u64 = r11.u64 | 32;
	// stb r10,58(r31)
	PPC_STORE_U8(r31.u32 + 58, ctx.r10.u8);
loc_8215582C:
	// lwz r4,21(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 21);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82155850
	if (cr6.eq) goto loc_82155850;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8215584C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,84(r26)
	PPC_STORE_U32(r26.u32 + 84, ctx.r3.u32);
loc_82155850:
	// lwz r4,25(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 25);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82155874
	if (cr6.eq) goto loc_82155874;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82155870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,88(r26)
	PPC_STORE_U32(r26.u32 + 88, ctx.r3.u32);
loc_82155874:
	// lwz r4,33(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 33);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82155898
	if (cr6.eq) goto loc_82155898;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82155894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,96(r26)
	PPC_STORE_U32(r26.u32 + 96, ctx.r3.u32);
loc_82155898:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,37(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 37);
	// bl 0x82164840
	ctx.lr = 0x821558A4;
	sub_82164840(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_821558B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_821558BC"))) PPC_WEAK_FUNC(sub_821558BC);
PPC_FUNC_IMPL(__imp__sub_821558BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821558C0"))) PPC_WEAK_FUNC(sub_821558C0);
PPC_FUNC_IMPL(__imp__sub_821558C0) {
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
	ctx.lr = 0x821558C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r26,1
	r26.s64 = 1;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// subfic r25,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r25.s64 = -72 - r30.s64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_821558EC:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821559a4
	if (cr6.eq) goto loc_821559A4;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r10,11440(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821559a4
	if (cr6.eq) goto loc_821559A4;
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215593c
	if (cr6.eq) goto loc_8215593C;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82155940
	goto loc_82155940;
loc_8215593C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82155940:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82155948;
	sub_8213B7B0(ctx, base);
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// lbz r10,57(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x82155980
	if (cr6.eq) goto loc_82155980;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82155984
	goto loc_82155984;
loc_82155980:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82155984:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213da88
	ctx.lr = 0x82155990;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x821559cc
	if (cr6.eq) goto loc_821559CC;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821559a4
	if (!cr6.eq) goto loc_821559A4;
	// li r26,0
	r26.s64 = 0;
loc_821559A4:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r25,r29
	r11.u64 = r25.u64 + r29.u64;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x821558ec
	if (cr6.lt) goto loc_821558EC;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_821559CC:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_821559D8"))) PPC_WEAK_FUNC(sub_821559D8);
PPC_FUNC_IMPL(__imp__sub_821559D8) {
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
	ctx.lr = 0x821559E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// li r28,2
	r28.s64 = 2;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_821559FC:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82155a4c
	if (cr6.eq) goto loc_82155A4C;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82155a4c
	if (cr6.eq) goto loc_82155A4C;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82155a40
	if (cr6.eq) goto loc_82155A40;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82155a44
	goto loc_82155A44;
loc_82155A40:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82155A44:
	// bl 0x8213b5c0
	ctx.lr = 0x82155A48;
	sub_8213B5C0(ctx, base);
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82155A4C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x821559fc
	if (!cr0.eq) goto loc_821559FC;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82155A60"))) PPC_WEAK_FUNC(sub_82155A60);
PPC_FUNC_IMPL(__imp__sub_82155A60) {
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
	ctx.lr = 0x82155A68;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// mr r28,r25
	r28.u64 = r25.u64;
	// li r27,2
	r27.s64 = 2;
	// li r24,1
	r24.s64 = 1;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_82155A90:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82155b14
	if (cr6.eq) goto loc_82155B14;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mullw r9,r8,r10
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r8,11440(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82155b14
	if (cr6.eq) goto loc_82155B14;
	// stb r25,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r25.u8);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82155ae4
	if (cr6.eq) goto loc_82155AE4;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r9,11440(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// mullw r11,r8,r10
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82155ae8
	goto loc_82155AE8;
loc_82155AE4:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
loc_82155AE8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x82155AF0;
	sub_8213C758(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82155b08
	if (cr6.eq) goto loc_82155B08;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82155b08
	if (cr6.eq) goto loc_82155B08;
	// stb r24,0(r26)
	PPC_STORE_U8(r26.u32 + 0, r24.u8);
loc_82155B08:
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// ble cr6,0x82155b14
	if (!cr6.gt) goto loc_82155B14;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_82155B14:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x82155a90
	if (!cr0.eq) goto loc_82155A90;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82155B2C"))) PPC_WEAK_FUNC(sub_82155B2C);
PPC_FUNC_IMPL(__imp__sub_82155B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82155B30"))) PPC_WEAK_FUNC(sub_82155B30);
PPC_FUNC_IMPL(__imp__sub_82155B30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d4
	ctx.lr = 0x82155B44;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lfs f30,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmr f28,f30
	f28.f64 = f30.f64;
	// beq cr6,0x82155b6c
	if (cr6.eq) goto loc_82155B6C;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
loc_82155B6C:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82155b80
	if (cr6.eq) goto loc_82155B80;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
loc_82155B80:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f29,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
	// beq cr6,0x82155bb8
	if (cr6.eq) goto loc_82155BB8;
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bgt cr6,0x82155ba8
	if (cr6.gt) goto loc_82155BA8;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// b 0x82155c64
	goto loc_82155C64;
loc_82155BA8:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// blt cr6,0x82155c64
	if (cr6.lt) goto loc_82155C64;
	// fmr f31,f29
	f31.f64 = f29.f64;
	// b 0x82155c64
	goto loc_82155C64;
loc_82155BB8:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// lhz r8,112(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 112);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
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
	// mullw r11,r8,r10
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r7,26644
	ctx.r10.s64 = ctx.r7.s64 + 26644;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r10,4
	ctx.r8.s64 = ctx.r10.s64 + 4;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lbz r6,199(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 199);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// rlwinm r5,r6,30,2,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFF8;
	// lwz r3,26660(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 26660);
	// lwzx r10,r5,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r8.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v63,r8,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8215f1d8
	ctx.lr = 0x82155C20;
	sub_8215F1D8(ctx, base);
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	f0.f64 = double(temp.f32);
	// lfs f13,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82155c38
	if (cr6.gt) goto loc_82155C38;
	// fmr f31,f30
	f31.f64 = f30.f64;
	// b 0x82155c54
	goto loc_82155C54;
loc_82155C38:
	// fcmpu cr6,f1,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, ctx.f13.f64);
	// blt cr6,0x82155c48
	if (cr6.lt) goto loc_82155C48;
	// fmr f31,f29
	f31.f64 = f29.f64;
	// b 0x82155c54
	goto loc_82155C54;
loc_82155C48:
	// fsubs f12,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fdivs f31,f12,f11
	f31.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
loc_82155C54:
	// fsubs f13,f1,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fsubs f12,f0,f1
	ctx.f12.f64 = double(float(f0.f64 - ctx.f1.f64));
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f28,f11,f12,f13
	f28.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
loc_82155C64:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82164db8
	ctx.lr = 0x82155C70;
	sub_82164DB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f1.f64;
	// fsubs f1,f29,f31
	ctx.f1.f64 = double(float(f29.f64 - f31.f64));
	// bl 0x82164db8
	ctx.lr = 0x82155C80;
	sub_82164DB8(ctx, base);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f30,84(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f30,88(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f27,96(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f30,100(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f30,104(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r7,23088
	ctx.r5.s64 = ctx.r7.s64 + 23088;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v59,v62
	ctx.fpscr.enableFlushModeUnconditional();
	v59.f32[0] = log2f(v62.f32[0]);
	v59.f32[1] = log2f(v62.f32[1]);
	v59.f32[2] = log2f(v62.f32[2]);
	v59.f32[3] = log2f(v62.f32[3]);
	// vlogefp128 v60,v61
	v60.f32[0] = log2f(v61.f32[0]);
	v60.f32[1] = log2f(v61.f32[1]);
	v60.f32[2] = log2f(v61.f32[2]);
	v60.f32[3] = log2f(v61.f32[3]);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v57,v59,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,-24(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -24);
	f0.f64 = double(temp.f32);
	// lfs f13,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f27,f0
	ctx.f12.f64 = double(float(f27.f64 - f0.f64));
	// fsubs f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f0,-28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -28);
	f0.f64 = double(temp.f32);
	// lbz r11,114(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 114);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// stb r10,115(r31)
	PPC_STORE_U8(r31.u32 + 115, ctx.r10.u8);
	// stb r10,116(r31)
	PPC_STORE_U8(r31.u32 + 116, ctx.r10.u8);
	// vmulfp128 v58,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f5,f12,f6,f0
	ctx.f5.f64 = ctx.f12.f64 >= 0.0 ? ctx.f6.f64 : f0.f64;
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fsel f8,f11,f9,f0
	ctx.f8.f64 = ctx.f11.f64 >= 0.0 ? ctx.f9.f64 : f0.f64;
	// stfs f5,64(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f8,68(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// bne cr6,0x82155d50
	if (!cr6.eq) goto loc_82155D50;
	// fcmpu cr6,f31,f30
	cr6.compare(f31.f64, f30.f64);
	// bne cr6,0x82155d38
	if (!cr6.eq) goto loc_82155D38;
	// lfs f0,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// bgt cr6,0x82155d60
	if (cr6.gt) goto loc_82155D60;
loc_82155D38:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bne cr6,0x82155d7c
	if (!cr6.eq) goto loc_82155D7C;
	// lfs f0,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// ble cr6,0x82155d7c
	if (!cr6.gt) goto loc_82155D7C;
	// b 0x82155d74
	goto loc_82155D74;
loc_82155D50:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82155d7c
	if (!cr6.eq) goto loc_82155D7C;
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// bne cr6,0x82155d6c
	if (!cr6.eq) goto loc_82155D6C;
loc_82155D60:
	// li r11,0
	r11.s64 = 0;
	// stb r11,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r11.u8);
	// b 0x82155d7c
	goto loc_82155D7C;
loc_82155D6C:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bne cr6,0x82155d7c
	if (!cr6.eq) goto loc_82155D7C;
loc_82155D74:
	// li r11,0
	r11.s64 = 0;
	// stb r11,115(r31)
	PPC_STORE_U8(r31.u32 + 115, r11.u8);
loc_82155D7C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba20
	ctx.lr = 0x82155D88;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82155D98"))) PPC_WEAK_FUNC(sub_82155D98);
PPC_FUNC_IMPL(__imp__sub_82155D98) {
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
	ctx.lr = 0x82155DA0;
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
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155e58
	if (cr6.eq) goto loc_82155E58;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r11,r9
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,11440(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82155e30
	if (cr6.eq) goto loc_82155E30;
	// lbz r7,115(r29)
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + 115);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82155e30
	if (!cr6.eq) goto loc_82155E30;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155e18
	if (cr6.eq) goto loc_82155E18;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// bl 0x8213b5c0
	ctx.lr = 0x82155E08;
	sub_8213B5C0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82155E14;
	sub_8214E5B8(ctx, base);
	// b 0x82155e78
	goto loc_82155E78;
loc_82155E18:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8213b5c0
	ctx.lr = 0x82155E20;
	sub_8213B5C0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82155E2C;
	sub_8214E5B8(ctx, base);
	// b 0x82155e78
	goto loc_82155E78;
loc_82155E30:
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155e58
	if (cr6.eq) goto loc_82155E58;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// mulli r9,r7,11488
	ctx.r9.s64 = ctx.r7.s64 * 11488;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,11440(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82155e80
	if (!cr6.eq) goto loc_82155E80;
loc_82155E58:
	// lbz r9,115(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 115);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82155e80
	if (cr6.eq) goto loc_82155E80;
	// addi r6,r29,40
	ctx.r6.s64 = r29.s64 + 40;
	// lwz r4,100(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 100);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b7d0
	ctx.lr = 0x82155E78;
	sub_8213B7D0(ctx, base);
loc_82155E78:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
loc_82155E80:
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155f1c
	if (cr6.eq) goto loc_82155F1C;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r11,r9
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,11440(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82155ef4
	if (cr6.eq) goto loc_82155EF4;
	// lbz r7,116(r29)
	ctx.r7.u64 = PPC_LOAD_U8(r29.u32 + 116);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82155ef4
	if (!cr6.eq) goto loc_82155EF4;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155edc
	if (cr6.eq) goto loc_82155EDC;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// bl 0x8213b5c0
	ctx.lr = 0x82155ECC;
	sub_8213B5C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82155ED8;
	sub_8214E5B8(ctx, base);
	// b 0x82155f3c
	goto loc_82155F3C;
loc_82155EDC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8213b5c0
	ctx.lr = 0x82155EE4;
	sub_8213B5C0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82155EF0;
	sub_8214E5B8(ctx, base);
	// b 0x82155f3c
	goto loc_82155F3C;
loc_82155EF4:
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155f1c
	if (cr6.eq) goto loc_82155F1C;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// mulli r9,r7,11488
	ctx.r9.s64 = ctx.r7.s64 * 11488;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,11440(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82155f44
	if (!cr6.eq) goto loc_82155F44;
loc_82155F1C:
	// lbz r9,116(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 116);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82155f44
	if (cr6.eq) goto loc_82155F44;
	// addi r6,r29,40
	ctx.r6.s64 = r29.s64 + 40;
	// lwz r4,104(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b7d0
	ctx.lr = 0x82155F3C;
	sub_8213B7D0(ctx, base);
loc_82155F3C:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
loc_82155F44:
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82155f98
	if (cr6.eq) goto loc_82155F98;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r11,r8
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,11440(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82155f98
	if (cr6.eq) goto loc_82155F98;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82155f84
	if (cr6.eq) goto loc_82155F84;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82155f88
	goto loc_82155F88;
loc_82155F84:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82155F88:
	// lfs f1,64(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 64);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213b768
	ctx.lr = 0x82155F90;
	sub_8213B768(ctx, base);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82155F98:
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155ff0
	if (cr6.eq) goto loc_82155FF0;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// mulli r7,r7,11488
	ctx.r7.s64 = ctx.r7.s64 * 11488;
	// add r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82155ff0
	if (cr6.eq) goto loc_82155FF0;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82155fe4
	if (cr6.eq) goto loc_82155FE4;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lfs f1,68(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213b768
	ctx.lr = 0x82155FDC;
	sub_8213B768(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82155FE4:
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f1,68(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 68);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213b768
	ctx.lr = 0x82155FF0;
	sub_8213B768(ctx, base);
loc_82155FF0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82155FF8"))) PPC_WEAK_FUNC(sub_82155FF8);
PPC_FUNC_IMPL(__imp__sub_82155FF8) {
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
	ctx.lr = 0x82156000;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// add r28,r27,r30
	r28.u64 = r27.u64 + r30.u64;
	// lbz r9,72(r28)
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156144
	if (cr6.eq) goto loc_82156144;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r10,r11,r9
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82156144
	if (cr6.eq) goto loc_82156144;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// lbz r10,57(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x82156064;
	sub_821374B0(ctx, base);
	// lbz r11,72(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 72);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82156098
	if (cr6.eq) goto loc_82156098;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215609c
	goto loc_8215609C;
loc_82156098:
	// li r11,0
	r11.s64 = 0;
loc_8215609C:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x821560AC;
	sub_8213DA88(ctx, base);
	// lbz r8,72(r28)
	ctx.r8.u64 = PPC_LOAD_U8(r28.u32 + 72);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82156104
	if (!cr6.eq) goto loc_82156104;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821560f0
	if (cr6.eq) goto loc_821560F0;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
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
	// bl 0x8213d890
	ctx.lr = 0x821560E8;
	sub_8213D890(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_821560F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213d890
	ctx.lr = 0x821560FC;
	sub_8213D890(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82156104:
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82156130
	if (cr6.eq) goto loc_82156130;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x82156134
	goto loc_82156134;
loc_82156130:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82156134:
	// bl 0x8213b630
	ctx.lr = 0x82156138;
	sub_8213B630(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82156144;
	sub_8214E5B8(ctx, base);
loc_82156144:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8215614C"))) PPC_WEAK_FUNC(sub_8215614C);
PPC_FUNC_IMPL(__imp__sub_8215614C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156150"))) PPC_WEAK_FUNC(sub_82156150);
PPC_FUNC_IMPL(__imp__sub_82156150) {
	PPC_FUNC_PROLOGUE();
	// b 0x821559d8
	sub_821559D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82156154"))) PPC_WEAK_FUNC(sub_82156154);
PPC_FUNC_IMPL(__imp__sub_82156154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156158"))) PPC_WEAK_FUNC(sub_82156158);
PPC_FUNC_IMPL(__imp__sub_82156158) {
	PPC_FUNC_PROLOGUE();
	// b 0x821558c0
	sub_821558C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215615C"))) PPC_WEAK_FUNC(sub_8215615C);
PPC_FUNC_IMPL(__imp__sub_8215615C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156160"))) PPC_WEAK_FUNC(sub_82156160);
PPC_FUNC_IMPL(__imp__sub_82156160) {
	PPC_FUNC_PROLOGUE();
	// b 0x82155a60
	sub_82155A60(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82156164"))) PPC_WEAK_FUNC(sub_82156164);
PPC_FUNC_IMPL(__imp__sub_82156164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156168"))) PPC_WEAK_FUNC(sub_82156168);
PPC_FUNC_IMPL(__imp__sub_82156168) {
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
	// bl 0x82155510
	ctx.lr = 0x82156188;
	sub_82155510(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821561b0
	if (cr6.eq) goto loc_821561B0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821561b0
	if (cr6.eq) goto loc_821561B0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x821561B0;
	sub_8213F7A8(ctx, base);
loc_821561B0:
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

__attribute__((alias("__imp__sub_821561CC"))) PPC_WEAK_FUNC(sub_821561CC);
PPC_FUNC_IMPL(__imp__sub_821561CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821561D0"))) PPC_WEAK_FUNC(sub_821561D0);
PPC_FUNC_IMPL(__imp__sub_821561D0) {
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
	ctx.lr = 0x821561D8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lbz r8,164(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 164);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r29,r11,r10
	r29.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213d168
	ctx.lr = 0x82156214;
	sub_8213D168(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// sth r6,112(r29)
	PPC_STORE_U16(r29.u32 + 112, ctx.r6.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r26,84(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82155b30
	ctx.lr = 0x8215622C;
	sub_82155B30(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82155d98
	ctx.lr = 0x82156238;
	sub_82155D98(ctx, base);
	// lwz r7,196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// addi r29,r31,72
	r29.s64 = r31.s64 + 72;
	// li r28,2
	r28.s64 = 2;
loc_82156244:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821562d8
	if (cr6.eq) goto loc_821562D8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821562d8
	if (cr6.eq) goto loc_821562D8;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156288
	if (cr6.eq) goto loc_82156288;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8215628c
	goto loc_8215628C;
loc_82156288:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215628C:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x82156298;
	sub_8213B7B0(ctx, base);
	// lbz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821562c8
	if (cr6.eq) goto loc_821562C8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821562cc
	goto loc_821562CC;
loc_821562C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821562CC:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213d890
	ctx.lr = 0x821562D4;
	sub_8213D890(ctx, base);
	// lwz r7,196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_821562D8:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x82156244
	if (!cr0.eq) goto loc_82156244;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_821562EC"))) PPC_WEAK_FUNC(sub_821562EC);
PPC_FUNC_IMPL(__imp__sub_821562EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821562F0"))) PPC_WEAK_FUNC(sub_821562F0);
PPC_FUNC_IMPL(__imp__sub_821562F0) {
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
	ctx.lr = 0x821562F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// li r28,0
	r28.s64 = 0;
	// lbz r10,64(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 64);
	// lbz r8,164(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 164);
	// mulli r11,r10,11488
	r11.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// mullw r9,r8,r10
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// lbz r6,114(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 114);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82156358
	if (cr6.eq) goto loc_82156358;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82155b30
	ctx.lr = 0x82156348;
	sub_82155B30(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82155d98
	ctx.lr = 0x82156354;
	sub_82155D98(ctx, base);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82156358:
	// addi r31,r29,72
	r31.s64 = r29.s64 + 72;
	// li r27,2
	r27.s64 = 2;
loc_82156360:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82156410
	if (cr6.eq) goto loc_82156410;
	// lbz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 64);
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82156410
	if (cr6.eq) goto loc_82156410;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821563a4
	if (cr6.eq) goto loc_821563A4;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// b 0x821563a8
	goto loc_821563A8;
loc_821563A4:
	// li r8,0
	ctx.r8.s64 = 0;
loc_821563A8:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x821563e8
	if (!cr6.eq) goto loc_821563E8;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821563c8
	if (cr6.eq) goto loc_821563C8;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821563cc
	goto loc_821563CC;
loc_821563C8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821563CC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213e040
	ctx.lr = 0x821563D4;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82156410
	if (cr6.eq) goto loc_82156410;
	// b 0x8215640c
	goto loc_8215640C;
loc_821563E8:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821563fc
	if (cr6.eq) goto loc_821563FC;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82156400
	goto loc_82156400;
loc_821563FC:
	// li r11,0
	r11.s64 = 0;
loc_82156400:
	// lhz r11,6(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x82156410
	if (!cr6.eq) goto loc_82156410;
loc_8215640C:
	// li r28,1
	r28.s64 = 1;
loc_82156410:
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bne 0x82156360
	if (!cr0.eq) goto loc_82156360;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82156434"))) PPC_WEAK_FUNC(sub_82156434);
PPC_FUNC_IMPL(__imp__sub_82156434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156438"))) PPC_WEAK_FUNC(sub_82156438);
PPC_FUNC_IMPL(__imp__sub_82156438) {
	PPC_FUNC_PROLOGUE();
	// b 0x821562f0
	sub_821562F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215643C"))) PPC_WEAK_FUNC(sub_8215643C);
PPC_FUNC_IMPL(__imp__sub_8215643C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156440"))) PPC_WEAK_FUNC(sub_82156440);
PPC_FUNC_IMPL(__imp__sub_82156440) {
	PPC_FUNC_PROLOGUE();
	// b 0x821561d0
	sub_821561D0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82156444"))) PPC_WEAK_FUNC(sub_82156444);
PPC_FUNC_IMPL(__imp__sub_82156444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156448"))) PPC_WEAK_FUNC(sub_82156448);
PPC_FUNC_IMPL(__imp__sub_82156448) {
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
	// bl 0x8213b968
	ctx.lr = 0x82156460;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,23744
	ctx.r8.s64 = r11.s64 + 23744;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r10,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r10.u32);
	// stw r10,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r10.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stb r11,184(r31)
	PPC_STORE_U8(r31.u32 + 184, r11.u8);
	// stb r11,185(r31)
	PPC_STORE_U8(r31.u32 + 185, r11.u8);
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// stb r11,213(r31)
	PPC_STORE_U8(r31.u32 + 213, r11.u8);
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// stb r11,214(r31)
	PPC_STORE_U8(r31.u32 + 214, r11.u8);
	// stb r11,215(r31)
	PPC_STORE_U8(r31.u32 + 215, r11.u8);
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

__attribute__((alias("__imp__sub_821564C8"))) PPC_WEAK_FUNC(sub_821564C8);
PPC_FUNC_IMPL(__imp__sub_821564C8) {
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
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r8,r9,23744
	ctx.r8.s64 = ctx.r9.s64 + 23744;
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82156530
	if (cr6.eq) goto loc_82156530;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82156530
	if (cr6.eq) goto loc_82156530;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x82156530;
	sub_8214E5B8(ctx, base);
loc_82156530:
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156570
	if (cr6.eq) goto loc_82156570;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
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
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82156570
	if (cr6.eq) goto loc_82156570;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82156570;
	sub_8214E5B8(ctx, base);
loc_82156570:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x82156578;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_82156590"))) PPC_WEAK_FUNC(sub_82156590);
PPC_FUNC_IMPL(__imp__sub_82156590) {
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
	ctx.lr = 0x82156598;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x821565AC;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821565c4
	if (!cr6.eq) goto loc_821565C4;
loc_821565B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821565C4:
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_821565D4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x821565d4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821565D4;
	// lbz r11,58(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 58);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r29,148(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// ori r9,r11,32
	ctx.r9.u64 = r11.u64 | 32;
	// addi r11,r10,19856
	r11.s64 = ctx.r10.s64 + 19856;
	// stb r9,58(r31)
	PPC_STORE_U8(r31.u32 + 58, ctx.r9.u8);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// bl 0x82144720
	ctx.lr = 0x82156618;
	sub_82144720(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// beq cr6,0x82156654
	if (cr6.eq) goto loc_82156654;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x82156658
	goto loc_82156658;
loc_82156654:
	// li r11,255
	r11.s64 = 255;
loc_82156658:
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// stw r8,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r8.u32);
	// lhz r7,2(r29)
	ctx.r7.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// stw r7,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r7.u32);
	// lwz r6,12(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r6,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r6.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r5,20(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82156690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x821566AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// rlwinm r10,r9,0,20,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xC00;
	// stw r3,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r3.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// addi r8,r10,-1024
	ctx.r8.s64 = ctx.r10.s64 + -1024;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r6,212(r31)
	PPC_STORE_U8(r31.u32 + 212, ctx.r6.u8);
	// beq cr6,0x821565b8
	if (cr6.eq) goto loc_821565B8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821565b8
	if (cr6.eq) goto loc_821565B8;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82156708"))) PPC_WEAK_FUNC(sub_82156708);
PPC_FUNC_IMPL(__imp__sub_82156708) {
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
	ctx.lr = 0x82156710;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82156738
	if (cr6.eq) goto loc_82156738;
	// li r10,196
	ctx.r10.s64 = 196;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfiwx f13,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.f13.u32);
loc_82156738:
	// lwz r11,204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82156760
	if (cr6.eq) goto loc_82156760;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r9,192
	ctx.r9.s64 = 192;
	// lfs f0,11364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, ctx.f11.u32);
loc_82156760:
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x82156774;
	sub_821374B0(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821567b0
	if (cr6.eq) goto loc_821567B0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821567b4
	goto loc_821567B4;
loc_821567B0:
	// li r11,0
	r11.s64 = 0;
loc_821567B4:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x821567C4;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82156810
	if (!cr6.eq) goto loc_82156810;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821567fc
	if (cr6.eq) goto loc_821567FC;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82156800
	goto loc_82156800;
loc_821567FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82156800:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x82156808;
	sub_8213D890(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
loc_82156810:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82156818"))) PPC_WEAK_FUNC(sub_82156818);
PPC_FUNC_IMPL(__imp__sub_82156818) {
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
	// add r11,r30,r31
	r11.u64 = r30.u64 + r31.u64;
	// lbz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215689c
	if (cr6.eq) goto loc_8215689C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8215689c
	if (cr6.eq) goto loc_8215689C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156888
	if (cr6.eq) goto loc_82156888;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215688c
	goto loc_8215688C;
loc_82156888:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215688C:
	// bl 0x8213b630
	ctx.lr = 0x82156890;
	sub_8213B630(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x8215689C;
	sub_8214E5B8(ctx, base);
loc_8215689C:
	// addi r6,r31,164
	ctx.r6.s64 = r31.s64 + 164;
	// lwz r4,200(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b7d0
	ctx.lr = 0x821568B0;
	sub_8213B7D0(ctx, base);
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

__attribute__((alias("__imp__sub_821568C8"))) PPC_WEAK_FUNC(sub_821568C8);
PPC_FUNC_IMPL(__imp__sub_821568C8) {
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
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// lbz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156938
	if (cr6.eq) goto loc_82156938;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8215693c
	if (cr6.eq) goto loc_8215693C;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156930
	if (cr6.eq) goto loc_82156930;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82156934
	goto loc_82156934;
loc_82156930:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82156934:
	// bl 0x8213b5c0
	ctx.lr = 0x82156938;
	sub_8213B5C0(ctx, base);
loc_82156938:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_8215693C:
	// lbz r9,73(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156988
	if (cr6.eq) goto loc_82156988;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82156988
	if (cr6.eq) goto loc_82156988;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156980
	if (cr6.eq) goto loc_82156980;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82156984
	goto loc_82156984;
loc_82156980:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82156984:
	// bl 0x8213b5c0
	ctx.lr = 0x82156988;
	sub_8213B5C0(ctx, base);
loc_82156988:
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

__attribute__((alias("__imp__sub_821569A0"))) PPC_WEAK_FUNC(sub_821569A0);
PPC_FUNC_IMPL(__imp__sub_821569A0) {
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
	ctx.lr = 0x821569A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r10,192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// mullw r30,r9,r10
	r30.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// bne cr6,0x821569d0
	if (!cr6.eq) goto loc_821569D0;
	// li r30,0
	r30.s64 = 0;
loc_821569D0:
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156a38
	if (cr6.eq) goto loc_82156A38;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,232(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82156a38
	if (cr6.eq) goto loc_82156A38;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156a20
	if (cr6.eq) goto loc_82156A20;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82156a24
	goto loc_82156A24;
loc_82156A20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82156A24:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c758
	ctx.lr = 0x82156A2C;
	sub_8213C758(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82156a38
	if (cr6.eq) goto loc_82156A38;
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
loc_82156A38:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x82156a58
	if (cr6.eq) goto loc_82156A58;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r9.u8);
loc_82156A58:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82156A60"))) PPC_WEAK_FUNC(sub_82156A60);
PPC_FUNC_IMPL(__imp__sub_82156A60) {
	PPC_FUNC_PROLOGUE();
	// b 0x821568c8
	sub_821568C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82156A64"))) PPC_WEAK_FUNC(sub_82156A64);
PPC_FUNC_IMPL(__imp__sub_82156A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156A68"))) PPC_WEAK_FUNC(sub_82156A68);
PPC_FUNC_IMPL(__imp__sub_82156A68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// lbz r11,72(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lbz r8,64(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 64);
	// addi r5,r9,7216
	ctx.r5.s64 = ctx.r9.s64 + 7216;
	// mulli r7,r8,11488
	ctx.r7.s64 = ctx.r8.s64 * 11488;
	// lwz r8,232(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 232);
	// lwz r9,196(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 196);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r8,11440(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lbz r10,57(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r10,r10,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x82156acc
	if (cr6.eq) goto loc_82156ACC;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r8
	ctx.r3.u64 = r11.u64 + ctx.r8.u64;
	// b 0x82156ad0
	goto loc_82156AD0;
loc_82156ACC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82156AD0:
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// b 0x8213da88
	sub_8213DA88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82156AD8"))) PPC_WEAK_FUNC(sub_82156AD8);
PPC_FUNC_IMPL(__imp__sub_82156AD8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82156ADC"))) PPC_WEAK_FUNC(sub_82156ADC);
PPC_FUNC_IMPL(__imp__sub_82156ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156AE0"))) PPC_WEAK_FUNC(sub_82156AE0);
PPC_FUNC_IMPL(__imp__sub_82156AE0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82156708
	sub_82156708(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82156AE4"))) PPC_WEAK_FUNC(sub_82156AE4);
PPC_FUNC_IMPL(__imp__sub_82156AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156AE8"))) PPC_WEAK_FUNC(sub_82156AE8);
PPC_FUNC_IMPL(__imp__sub_82156AE8) {
	PPC_FUNC_PROLOGUE();
	// b 0x821569a0
	sub_821569A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82156AEC"))) PPC_WEAK_FUNC(sub_82156AEC);
PPC_FUNC_IMPL(__imp__sub_82156AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156AF0"))) PPC_WEAK_FUNC(sub_82156AF0);
PPC_FUNC_IMPL(__imp__sub_82156AF0) {
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
	// bl 0x821564c8
	ctx.lr = 0x82156B10;
	sub_821564C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82156b38
	if (cr6.eq) goto loc_82156B38;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82156b38
	if (cr6.eq) goto loc_82156B38;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82156B38;
	sub_8213F7A8(ctx, base);
loc_82156B38:
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

__attribute__((alias("__imp__sub_82156B54"))) PPC_WEAK_FUNC(sub_82156B54);
PPC_FUNC_IMPL(__imp__sub_82156B54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82156B58"))) PPC_WEAK_FUNC(sub_82156B58);
PPC_FUNC_IMPL(__imp__sub_82156B58) {
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
	ctx.lr = 0x82156B60;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r27,0
	r27.s64 = 0;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156c08
	if (cr6.eq) goto loc_82156C08;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82156c0c
	if (cr6.eq) goto loc_82156C0C;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156bc0
	if (cr6.eq) goto loc_82156BC0;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// b 0x82156bc4
	goto loc_82156BC4;
loc_82156BC0:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_82156BC4:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82156c0c
	if (!cr6.eq) goto loc_82156C0C;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156be4
	if (cr6.eq) goto loc_82156BE4;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82156be8
	goto loc_82156BE8;
loc_82156BE4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82156BE8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213e040
	ctx.lr = 0x82156BF0;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82156c08
	if (!cr6.eq) goto loc_82156C08;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82156C08;
	sub_8214E5B8(ctx, base);
loc_82156C08:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82156C0C:
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156c9c
	if (cr6.eq) goto loc_82156C9C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82156c9c
	if (cr6.eq) goto loc_82156C9C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156c50
	if (cr6.eq) goto loc_82156C50;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82156c54
	goto loc_82156C54;
loc_82156C50:
	// mr r8,r27
	ctx.r8.u64 = r27.u64;
loc_82156C54:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82156c9c
	if (!cr6.eq) goto loc_82156C9C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156c74
	if (cr6.eq) goto loc_82156C74;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82156c78
	goto loc_82156C78;
loc_82156C74:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82156C78:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213e040
	ctx.lr = 0x82156C80;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82156c98
	if (!cr6.eq) goto loc_82156C98;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82156C98;
	sub_8214E5B8(ctx, base);
loc_82156C98:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82156C9C:
	// lwz r9,208(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82156cbc
	if (cr6.eq) goto loc_82156CBC;
	// li r11,196
	r11.s64 = 196;
	// lfs f0,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfiwx f13,r31,r11
	PPC_STORE_U32(r31.u32 + r11.u32, ctx.f13.u32);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82156CBC:
	// lwz r10,204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82156ce8
	if (cr6.eq) goto loc_82156CE8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r10,192
	ctx.r10.s64 = 192;
	// lfs f0,11364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfiwx f11,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.f11.u32);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82156CE8:
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// subf r10,r10,r28
	ctx.r10.s64 = r28.s64 - ctx.r10.s64;
	// bge cr6,0x82156cfc
	if (!cr6.lt) goto loc_82156CFC;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82156CFC:
	// lwz r8,188(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r7,192(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// blt cr6,0x82156e8c
	if (cr6.lt) goto loc_82156E8C;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x82156d24
	if (cr6.eq) goto loc_82156D24;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x82156f10
	if (!cr6.gt) goto loc_82156F10;
loc_82156D24:
	// lbz r8,57(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r7,r8,0,27,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82156f10
	if (!cr6.eq) goto loc_82156F10;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x82156d68
	if (cr6.eq) goto loc_82156D68;
	// addi r11,r10,-1
	r11.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// beq cr6,0x82156d64
	if (cr6.eq) goto loc_82156D64;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,0(r9)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
loc_82156D64:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82156D68:
	// lbz r10,213(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 213);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lbz r10,212(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// beq cr6,0x82156df8
	if (cr6.eq) goto loc_82156DF8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82156dcc
	if (cr6.eq) goto loc_82156DCC;
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156dcc
	if (cr6.eq) goto loc_82156DCC;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82156dcc
	if (cr6.eq) goto loc_82156DCC;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156dc4
	if (cr6.eq) goto loc_82156DC4;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82156dc8
	goto loc_82156DC8;
loc_82156DC4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82156DC8:
	// bl 0x8213b5a0
	ctx.lr = 0x82156DCC;
	sub_8213B5A0(ctx, base);
loc_82156DCC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82156818
	ctx.lr = 0x82156DD8;
	sub_82156818(ctx, base);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r11,r28
	r11.s64 = r28.s64 - r11.s64;
	// bge cr6,0x82156dec
	if (!cr6.lt) goto loc_82156DEC;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82156DEC:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,214(r31)
	PPC_STORE_U8(r31.u32 + 214, ctx.r10.u8);
	// b 0x82156e74
	goto loc_82156E74;
loc_82156DF8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82156e4c
	if (cr6.eq) goto loc_82156E4C;
	// lbz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156e4c
	if (cr6.eq) goto loc_82156E4C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82156e4c
	if (cr6.eq) goto loc_82156E4C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82156e44
	if (cr6.eq) goto loc_82156E44;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82156e48
	goto loc_82156E48;
loc_82156E44:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82156E48:
	// bl 0x8213b5a0
	ctx.lr = 0x82156E4C;
	sub_8213B5A0(ctx, base);
loc_82156E4C:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82156818
	ctx.lr = 0x82156E58;
	sub_82156818(ctx, base);
	// lwz r11,132(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r11,r28
	r11.s64 = r28.s64 - r11.s64;
	// bge cr6,0x82156e6c
	if (!cr6.lt) goto loc_82156E6C;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82156E6C:
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,215(r31)
	PPC_STORE_U8(r31.u32 + 215, ctx.r10.u8);
loc_82156E74:
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
	// lbz r11,213(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 213);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,213(r31)
	PPC_STORE_U8(r31.u32 + 213, ctx.r9.u8);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82156E8C:
	// lbz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156fdc
	if (cr6.eq) goto loc_82156FDC;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r7,11488
	ctx.r10.s64 = ctx.r7.s64 * 11488;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82156fdc
	if (cr6.eq) goto loc_82156FDC;
	// lbz r10,214(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 214);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82156fdc
	if (cr6.eq) goto loc_82156FDC;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x82156EDC;
	sub_821374B0(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82156f7c
	if (cr6.eq) goto loc_82156F7C;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82156f80
	goto loc_82156F80;
loc_82156F10:
	// lbz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156f40
	if (cr6.eq) goto loc_82156F40;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r7,11488
	ctx.r10.s64 = ctx.r7.s64 * 11488;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82156e8c
	if (!cr6.eq) goto loc_82156E8C;
loc_82156F40:
	// lbz r10,73(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82156f70
	if (cr6.eq) goto loc_82156F70;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r11,r10
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r7,11488
	ctx.r10.s64 = ctx.r7.s64 * 11488;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82156e8c
	if (!cr6.eq) goto loc_82156E8C;
loc_82156F70:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82156F7C:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82156F80:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x82156F90;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82156fd8
	if (!cr6.eq) goto loc_82156FD8;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82156fc8
	if (cr6.eq) goto loc_82156FC8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82156fcc
	goto loc_82156FCC;
loc_82156FC8:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82156FCC:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x82156FD4;
	sub_8213D890(ctx, base);
	// stb r27,214(r31)
	PPC_STORE_U8(r31.u32 + 214, r27.u8);
loc_82156FD8:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82156FDC:
	// lbz r10,73(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821570bc
	if (cr6.eq) goto loc_821570BC;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821570bc
	if (cr6.eq) goto loc_821570BC;
	// lbz r11,215(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 215);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821570bc
	if (cr6.eq) goto loc_821570BC;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x8215702C;
	sub_821374B0(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82157060
	if (cr6.eq) goto loc_82157060;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82157064
	goto loc_82157064;
loc_82157060:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82157064:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x82157074;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x821570bc
	if (!cr6.eq) goto loc_821570BC;
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821570ac
	if (cr6.eq) goto loc_821570AC;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821570b0
	goto loc_821570B0;
loc_821570AC:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_821570B0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x821570B8;
	sub_8213D890(ctx, base);
	// stb r27,215(r31)
	PPC_STORE_U8(r31.u32 + 215, r27.u8);
loc_821570BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821570C8"))) PPC_WEAK_FUNC(sub_821570C8);
PPC_FUNC_IMPL(__imp__sub_821570C8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82156b58
	sub_82156B58(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821570CC"))) PPC_WEAK_FUNC(sub_821570CC);
PPC_FUNC_IMPL(__imp__sub_821570CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821570D0"))) PPC_WEAK_FUNC(sub_821570D0);
PPC_FUNC_IMPL(__imp__sub_821570D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,213(r3)
	PPC_STORE_U8(ctx.r3.u32 + 213, r11.u8);
	// b 0x8213d9d8
	sub_8213D9D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821570DC"))) PPC_WEAK_FUNC(sub_821570DC);
PPC_FUNC_IMPL(__imp__sub_821570DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821570E0"))) PPC_WEAK_FUNC(sub_821570E0);
PPC_FUNC_IMPL(__imp__sub_821570E0) {
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
	// bl 0x8213b968
	ctx.lr = 0x821570F8;
	sub_8213B968(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r10,24112
	ctx.r8.s64 = ctx.r10.s64 + 24112;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r11.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// li r10,255
	ctx.r10.s64 = 255;
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
	// stb r11,211(r31)
	PPC_STORE_U8(r31.u32 + 211, r11.u8);
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// stb r11,213(r31)
	PPC_STORE_U8(r31.u32 + 213, r11.u8);
	// stb r11,214(r31)
	PPC_STORE_U8(r31.u32 + 214, r11.u8);
	// stb r11,215(r31)
	PPC_STORE_U8(r31.u32 + 215, r11.u8);
	// stb r11,210(r31)
	PPC_STORE_U8(r31.u32 + 210, r11.u8);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stb r9,212(r31)
	PPC_STORE_U8(r31.u32 + 212, ctx.r9.u8);
	// sth r7,208(r31)
	PPC_STORE_U16(r31.u32 + 208, ctx.r7.u16);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
loc_82157148:
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// stb r10,164(r8)
	PPC_STORE_U8(ctx.r8.u32 + 164, ctx.r10.u8);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// blt cr6,0x82157148
	if (cr6.lt) goto loc_82157148;
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

__attribute__((alias("__imp__sub_82157178"))) PPC_WEAK_FUNC(sub_82157178);
PPC_FUNC_IMPL(__imp__sub_82157178) {
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
	ctx.lr = 0x82157180;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r31,-1
	r31.s64 = -1;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821571a4
	if (cr6.eq) goto loc_821571A4;
	// mr r31,r11
	r31.u64 = r11.u64;
	// b 0x82157200
	goto loc_82157200;
loc_821571A4:
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x821571B0;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82157200
	if (cr6.eq) goto loc_82157200;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157200
	if (cr6.eq) goto loc_82157200;
	// lbz r11,56(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 56);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82157200
	if (cr6.eq) goto loc_82157200;
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x821571E0;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821571f4
	if (cr6.eq) goto loc_821571F4;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821571f8
	if (!cr6.eq) goto loc_821571F8;
loc_821571F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821571F8:
	// bl 0x821457e0
	ctx.lr = 0x821571FC;
	sub_821457E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82157200:
	// lbz r11,217(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 217);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157228
	if (cr6.eq) goto loc_82157228;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82157238
	if (cr6.eq) goto loc_82157238;
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82157228:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82157238
	if (cr6.eq) goto loc_82157238;
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r11.u8);
loc_82157238:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82157240"))) PPC_WEAK_FUNC(sub_82157240);
PPC_FUNC_IMPL(__imp__sub_82157240) {
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
	ctx.lr = 0x82157248;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r29,1
	r29.s64 = 1;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,16
	ctx.r10.s64 = 16;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82157260:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82157260
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82157260;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,15
	ctx.r4.s64 = 15;
	// bl 0x8213d058
	ctx.lr = 0x82157280;
	sub_8213D058(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
loc_82157288:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x821572a4
	if (cr6.eq) goto loc_821572A4;
	// bl 0x8214a750
	ctx.lr = 0x82157298;
	sub_8214A750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821572c0
	if (cr6.eq) goto loc_821572C0;
loc_821572A4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmplwi cr6,r30,16
	cr6.compare<uint32_t>(r30.u32, 16, xer);
	// blt cr6,0x82157288
	if (cr6.lt) goto loc_82157288;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_821572C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821572CC"))) PPC_WEAK_FUNC(sub_821572CC);
PPC_FUNC_IMPL(__imp__sub_821572CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821572D0"))) PPC_WEAK_FUNC(sub_821572D0);
PPC_FUNC_IMPL(__imp__sub_821572D0) {
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
	ctx.lr = 0x821572D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x8213bb28
	ctx.lr = 0x821572E8;
	sub_8213BB28(ctx, base);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82157370
	if (!cr6.gt) goto loc_82157370;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
loc_82157300:
	// add r11,r29,r31
	r11.u64 = r29.u64 + r31.u64;
	// lbz r10,164(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 164);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82157358
	if (cr6.eq) goto loc_82157358;
	// cmplwi cr6,r29,8
	cr6.compare<uint32_t>(r29.u32, 8, xer);
	// bge cr6,0x8215734c
	if (!cr6.lt) goto loc_8215734C;
	// add r11,r29,r31
	r11.u64 = r29.u64 + r31.u64;
	// lbz r8,164(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 164);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215734c
	if (cr6.eq) goto loc_8215734C;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82157350
	goto loc_82157350;
loc_8215734C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82157350:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82148a10
	ctx.lr = 0x82157358;
	sub_82148A10(ctx, base);
loc_82157358:
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x82157300
	if (cr6.lt) goto loc_82157300;
loc_82157370:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82157378"))) PPC_WEAK_FUNC(sub_82157378);
PPC_FUNC_IMPL(__imp__sub_82157378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,213(r3)
	PPC_STORE_U8(ctx.r3.u32 + 213, ctx.r10.u8);
	// stw r11,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, r11.u32);
	// stw r11,172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 172, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82157390"))) PPC_WEAK_FUNC(sub_82157390);
PPC_FUNC_IMPL(__imp__sub_82157390) {
	PPC_FUNC_PROLOGUE();
	// b 0x82157178
	sub_82157178(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82157394"))) PPC_WEAK_FUNC(sub_82157394);
PPC_FUNC_IMPL(__imp__sub_82157394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82157398"))) PPC_WEAK_FUNC(sub_82157398);
PPC_FUNC_IMPL(__imp__sub_82157398) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x821573b8
	if (cr6.eq) goto loc_821573B8;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,192(r11)
	PPC_STORE_U32(r11.u32 + 192, ctx.r10.u32);
	// blr 
	return;
loc_821573B8:
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,188(r11)
	PPC_STORE_U32(r11.u32 + 188, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_821573CC"))) PPC_WEAK_FUNC(sub_821573CC);
PPC_FUNC_IMPL(__imp__sub_821573CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821573D0"))) PPC_WEAK_FUNC(sub_821573D0);
PPC_FUNC_IMPL(__imp__sub_821573D0) {
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
	ctx.lr = 0x821573D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r9,r11,24112
	ctx.r9.s64 = r11.s64 + 24112;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// ble cr6,0x821574b8
	if (!cr6.gt) goto loc_821574B8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r30,164
	r29.s64 = r30.s64 + 164;
	// subfic r28,r30,-164
	xer.ca = r30.u32 <= 4294967132;
	r28.s64 = -164 - r30.s64;
	// li r27,255
	r27.s64 = 255;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_8215740C:
	// lbz r9,-92(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + -92);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215744c
	if (cr6.eq) goto loc_8215744C;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215744c
	if (cr6.eq) goto loc_8215744C;
	// add r4,r28,r29
	ctx.r4.u64 = r28.u64 + r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x8215744C;
	sub_8214E5B8(ctx, base);
loc_8215744C:
	// lbz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821574a4
	if (cr6.eq) goto loc_821574A4;
	// add r11,r28,r29
	r11.u64 = r28.u64 + r29.u64;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bge cr6,0x82157488
	if (!cr6.lt) goto loc_82157488;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r11,11488
	ctx.r10.s64 = r11.s64 * 11488;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215748c
	goto loc_8215748C;
loc_82157488:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215748C:
	// bl 0x82130000
	ctx.lr = 0x82157490;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// lbz r4,64(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// bl 0x8213ec58
	ctx.lr = 0x821574A0;
	sub_8213EC58(ctx, base);
	// stb r27,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r27.u8);
loc_821574A4:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r28,r29
	ctx.r10.u64 = r28.u64 + r29.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x8215740c
	if (cr6.lt) goto loc_8215740C;
loc_821574B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213ba48
	ctx.lr = 0x821574C0;
	sub_8213BA48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821574C8"))) PPC_WEAK_FUNC(sub_821574C8);
PPC_FUNC_IMPL(__imp__sub_821574C8) {
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
	ctx.lr = 0x821574D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r25,1
	r25.s64 = 1;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821575f0
	if (!cr6.gt) goto loc_821575F0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r28,r30,72
	r28.s64 = r30.s64 + 72;
	// subfic r26,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r26.s64 = -72 - r30.s64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_821574FC:
	// lbz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821575dc
	if (cr6.eq) goto loc_821575DC;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// mullw r9,r9,r10
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x821575dc
	if (cr6.eq) goto loc_821575DC;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82157548
	if (cr6.eq) goto loc_82157548;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8215754c
	goto loc_8215754C;
loc_82157548:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215754C:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x82157558;
	sub_8213B7B0(ctx, base);
	// lhz r11,60(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 60);
	// lbz r10,57(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x8215756C;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82157584
	if (cr6.eq) goto loc_82157584;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82157588
	if (!cr6.eq) goto loc_82157588;
loc_82157584:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82157588:
	// lbz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821575b8
	if (cr6.eq) goto loc_821575B8;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x821575bc
	goto loc_821575BC;
loc_821575B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821575BC:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8213da88
	ctx.lr = 0x821575C8;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x821575fc
	if (cr6.eq) goto loc_821575FC;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x821575dc
	if (!cr6.eq) goto loc_821575DC;
	// li r25,0
	r25.s64 = 0;
loc_821575DC:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r26,r28
	ctx.r10.u64 = r26.u64 + r28.u64;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// blt cr6,0x821574fc
	if (cr6.lt) goto loc_821574FC;
loc_821575F0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_821575FC:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82157608"))) PPC_WEAK_FUNC(sub_82157608);
PPC_FUNC_IMPL(__imp__sub_82157608) {
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
	ctx.lr = 0x82157610;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r29,r27
	r29.u64 = r27.u64;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x821576a8
	if (!cr6.gt) goto loc_821576A8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r28,r31,72
	r28.s64 = r31.s64 + 72;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lwz r7,196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_8215763C:
	// lbzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82157698
	if (cr6.eq) goto loc_82157698;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82157698
	if (cr6.eq) goto loc_82157698;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82157680
	if (cr6.eq) goto loc_82157680;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82157684
	goto loc_82157684;
loc_82157680:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_82157684:
	// bl 0x8213b5c0
	ctx.lr = 0x82157688;
	sub_8213B5C0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82157694;
	sub_8214E5B8(ctx, base);
	// lwz r7,196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82157698:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x8215763c
	if (cr6.lt) goto loc_8215763C;
loc_821576A8:
	// stb r27,213(r31)
	PPC_STORE_U8(r31.u32 + 213, r27.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821576B4"))) PPC_WEAK_FUNC(sub_821576B4);
PPC_FUNC_IMPL(__imp__sub_821576B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821576B8"))) PPC_WEAK_FUNC(sub_821576B8);
PPC_FUNC_IMPL(__imp__sub_821576B8) {
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
	ctx.lr = 0x821576C0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r28,32767
	r28.s64 = 2147418112;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// ori r28,r28,65535
	r28.u64 = r28.u64 | 65535;
	// lwz r11,196(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// lwz r26,172(r27)
	r26.u64 = PPC_LOAD_U32(r27.u32 + 172);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82157834
	if (!cr6.gt) goto loc_82157834;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r25,r27,72
	r25.s64 = r27.s64 + 72;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// subfic r23,r27,-72
	xer.ca = r27.u32 <= 4294967224;
	r23.s64 = -72 - r27.s64;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_821576F8:
	// lbz r7,0(r25)
	ctx.r7.u64 = PPC_LOAD_U8(r25.u32 + 0);
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// beq cr6,0x82157820
	if (cr6.eq) goto loc_82157820;
	// lbz r9,64(r27)
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + 64);
	// mullw r11,r10,r7
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// lwz r9,11440(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157820
	if (cr6.eq) goto loc_82157820;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r9,16
	ctx.r9.s64 = 16;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82157738:
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82157738
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82157738;
	// cmplwi cr6,r7,255
	cr6.compare<uint32_t>(ctx.r7.u32, 255, xer);
	// beq cr6,0x8215775c
	if (cr6.eq) goto loc_8215775C;
	// lwz r9,11440(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// mullw r11,r10,r7
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r7.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82157760
	goto loc_82157760;
loc_8215775C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82157760:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x8213d058
	ctx.lr = 0x82157774;
	sub_8213D058(ctx, base);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// li r29,16
	r29.s64 = 16;
loc_82157780:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157814
	if (cr6.eq) goto loc_82157814;
	// lhz r9,6(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r9,2
	cr6.compare<uint32_t>(ctx.r9.u32, 2, xer);
	// bne cr6,0x82157814
	if (!cr6.eq) goto loc_82157814;
	// lbz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82157814
	if (cr6.eq) goto loc_82157814;
	// lbz r6,64(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r9,r6,11488
	ctx.r9.s64 = ctx.r6.s64 * 11488;
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwz r9,11440(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82157814
	if (cr6.eq) goto loc_82157814;
	// lbz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821577f4
	if (cr6.eq) goto loc_821577F4;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// rotlwi r9,r7,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821577f8
	goto loc_821577F8;
loc_821577F4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821577F8:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x8214a6a8
	ctx.lr = 0x82157800;
	sub_8214A6A8(ctx, base);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// bge cr6,0x82157814
	if (!cr6.lt) goto loc_82157814;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_82157814:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82157780
	if (!cr0.eq) goto loc_82157780;
loc_82157820:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// lwz r11,196(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// add r9,r23,r25
	ctx.r9.u64 = r23.u64 + r25.u64;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// blt cr6,0x821576f8
	if (cr6.lt) goto loc_821576F8;
loc_82157834:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82157840"))) PPC_WEAK_FUNC(sub_82157840);
PPC_FUNC_IMPL(__imp__sub_82157840) {
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
	ctx.lr = 0x82157848;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r27
	r11.u64 = r27.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82157868:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82157868
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82157868;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x8215799c
	if (cr6.gt) goto loc_8215799C;
	// li r22,1
	r22.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157998
	if (cr6.eq) goto loc_82157998;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r24,r31,60
	r24.s64 = r31.s64 + 60;
	// addi r26,r31,156
	r26.s64 = r31.s64 + 156;
	// addi r29,r5,9
	r29.s64 = ctx.r5.s64 + 9;
	// addi r23,r31,72
	r23.s64 = r31.s64 + 72;
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// addi r25,r11,19856
	r25.s64 = r11.s64 + 19856;
loc_821578B8:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lwz r4,-4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -4);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r25,608
	ctx.r3.s64 = r25.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x821578D0;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82157904
	if (cr6.eq) goto loc_82157904;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x82157908
	goto loc_82157908;
loc_82157904:
	// li r11,255
	r11.s64 = 255;
loc_82157908:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stbx r11,r23,r28
	PPC_STORE_U8(r23.u32 + r28.u32, r11.u8);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82157944
	if (cr6.eq) goto loc_82157944;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215794c
	if (!cr6.eq) goto loc_8215794C;
loc_82157944:
	// li r22,0
	r22.s64 = 0;
	// b 0x82157980
	goto loc_82157980;
loc_8215794C:
	// cmplwi cr6,r28,2
	cr6.compare<uint32_t>(r28.u32, 2, xer);
	// bge cr6,0x8215795c
	if (!cr6.lt) goto loc_8215795C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r11,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r11.u32);
loc_8215795C:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8215796C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8215796c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8215796C;
loc_82157980:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r26,r26,4
	r26.s64 = r26.s64 + 4;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// cmplw cr6,r28,r11
	cr6.compare<uint32_t>(r28.u32, r11.u32, xer);
	// blt cr6,0x821578b8
	if (cr6.lt) goto loc_821578B8;
loc_82157998:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
loc_8215799C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_821579A4"))) PPC_WEAK_FUNC(sub_821579A4);
PPC_FUNC_IMPL(__imp__sub_821579A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821579A8"))) PPC_WEAK_FUNC(sub_821579A8);
PPC_FUNC_IMPL(__imp__sub_821579A8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82157608
	sub_82157608(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821579AC"))) PPC_WEAK_FUNC(sub_821579AC);
PPC_FUNC_IMPL(__imp__sub_821579AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821579B0"))) PPC_WEAK_FUNC(sub_821579B0);
PPC_FUNC_IMPL(__imp__sub_821579B0) {
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
	// bl 0x821573d0
	ctx.lr = 0x821579D0;
	sub_821573D0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821579f8
	if (cr6.eq) goto loc_821579F8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821579f8
	if (cr6.eq) goto loc_821579F8;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x821579F8;
	sub_8213F7A8(ctx, base);
loc_821579F8:
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

__attribute__((alias("__imp__sub_82157A14"))) PPC_WEAK_FUNC(sub_82157A14);
PPC_FUNC_IMPL(__imp__sub_82157A14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82157A18"))) PPC_WEAK_FUNC(sub_82157A18);
PPC_FUNC_IMPL(__imp__sub_82157A18) {
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
	ctx.lr = 0x82157A20;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// li r29,0
	r29.s64 = 0;
	// bl 0x8213e680
	ctx.lr = 0x82157A34;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157aac
	if (cr6.eq) goto loc_82157AAC;
	// lwz r10,112(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lbz r9,57(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r11,r10,0,20,21
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xC00;
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// rlwinm r10,r10,0,18,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3000;
	// lbz r8,65(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// addi r7,r11,-1024
	ctx.r7.s64 = r11.s64 + -1024;
	// addi r6,r10,-4096
	ctx.r6.s64 = ctx.r10.s64 + -4096;
	// cntlzw r11,r7
	r11.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// cntlzw r10,r6
	ctx.r10.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r9,r9,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// rlwinm r7,r11,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// rlwinm r6,r10,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r9.u8);
	// rlwinm r8,r8,0,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFE;
	// lbz r11,4(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 4);
	// stw r11,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r11.u32);
	// stb r8,65(r31)
	PPC_STORE_U8(r31.u32 + 65, ctx.r8.u8);
	// stb r7,216(r31)
	PPC_STORE_U8(r31.u32 + 216, ctx.r7.u8);
	// stb r6,217(r31)
	PPC_STORE_U8(r31.u32 + 217, ctx.r6.u8);
	// lwz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r10,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r10.u32);
	// bl 0x82157840
	ctx.lr = 0x82157AA4;
	sub_82157840(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82157AAC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82157AB8"))) PPC_WEAK_FUNC(sub_82157AB8);
PPC_FUNC_IMPL(__imp__sub_82157AB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r21{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82157AC0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157ae0
	if (cr6.eq) goto loc_82157AE0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82157AE0:
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82157AEC;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82157b44
	if (cr6.eq) goto loc_82157B44;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157b44
	if (cr6.eq) goto loc_82157B44;
	// lhz r11,208(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 208);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x82157b58
	if (!cr6.eq) goto loc_82157B58;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d058
	ctx.lr = 0x82157B2C;
	sub_8213D058(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82157b50
	if (!cr6.eq) goto loc_82157B50;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r11,24148
	ctx.r3.s64 = r11.s64 + 24148;
	// bl 0x82130000
	ctx.lr = 0x82157B44;
	sub_82130000(ctx, base);
loc_82157B44:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82157B50:
	// lhz r11,172(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 172);
	// sth r11,208(r31)
	PPC_STORE_U16(r31.u32 + 208, r11.u16);
loc_82157B58:
	// lhz r11,208(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 208);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x82157b44
	if (cr6.eq) goto loc_82157B44;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213cbd8
	ctx.lr = 0x82157B6C;
	sub_8213CBD8(ctx, base);
	// lbz r11,210(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 210);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r30,84(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bne cr6,0x82157b8c
	if (!cr6.eq) goto loc_82157B8C;
	// li r11,1
	r11.s64 = 1;
	// stw r30,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r30.u32);
	// stb r11,210(r31)
	PPC_STORE_U8(r31.u32 + 210, r11.u8);
	// b 0x82157b90
	goto loc_82157B90;
loc_82157B8C:
	// lwz r30,172(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 172);
loc_82157B90:
	// lbz r11,212(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157bd0
	if (cr6.eq) goto loc_82157BD0;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82157BA8;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82157bbc
	if (cr6.eq) goto loc_82157BBC;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82157bc0
	if (!cr6.eq) goto loc_82157BC0;
loc_82157BBC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82157BC0:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lhz r4,208(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 208);
	// bl 0x821455b0
	ctx.lr = 0x82157BCC;
	sub_821455B0(ctx, base);
	// stb r29,212(r31)
	PPC_STORE_U8(r31.u32 + 212, r29.u8);
loc_82157BD0:
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82157BDC;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82157bf0
	if (cr6.eq) goto loc_82157BF0;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82157bf4
	if (!cr6.eq) goto loc_82157BF4;
loc_82157BF0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82157BF4:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lhz r4,208(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 208);
	// bl 0x82146770
	ctx.lr = 0x82157C00;
	sub_82146770(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x82157c5c
	if (cr6.gt) goto loc_82157C5C;
	// lis r12,-32235
	r12.s64 = -2112552960;
	// addi r12,r12,31776
	r12.s64 = r12.s64 + 31776;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_82157C30;
	case 1:
		goto loc_82157CA4;
	case 2:
		goto loc_82157C50;
	case 3:
		goto loc_82157C74;
	default:
		__builtin_unreachable();
	}
	// lwz r16,31792(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + 31792);
	// lwz r16,31908(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + 31908);
	// lwz r16,31824(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + 31824);
	// lwz r16,31860(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + 31860);
loc_82157C30:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821574c8
	ctx.lr = 0x82157C3C;
	sub_821574C8(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82157c60
	if (!cr6.eq) goto loc_82157C60;
	// stw r30,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82157C50:
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r10.u8);
loc_82157C5C:
	// li r3,2
	ctx.r3.s64 = 2;
loc_82157C60:
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,56(r31)
	PPC_STORE_U8(r31.u32 + 56, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82157C74:
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82157C80;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82157c94
	if (cr6.eq) goto loc_82157C94;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82157c98
	if (!cr6.eq) goto loc_82157C98;
loc_82157C94:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_82157C98:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lhz r4,208(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 208);
	// bl 0x821455b0
	ctx.lr = 0x82157CA4;
	sub_821455B0(ctx, base);
loc_82157CA4:
	// lbz r11,56(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 56);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stb r10,56(r31)
	PPC_STORE_U8(r31.u32 + 56, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82157CBC"))) PPC_WEAK_FUNC(sub_82157CBC);
PPC_FUNC_IMPL(__imp__sub_82157CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82157CC0"))) PPC_WEAK_FUNC(sub_82157CC0);
PPC_FUNC_IMPL(__imp__sub_82157CC0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82157CC8;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// lhz r11,60(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82157CE0;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82157d58
	if (cr6.eq) goto loc_82157D58;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157d58
	if (cr6.eq) goto loc_82157D58;
	// lbz r11,213(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 213);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157e24
	if (cr6.eq) goto loc_82157E24;
	// lwz r11,180(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 180);
	// lwz r10,184(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 184);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82157d64
	if (cr6.eq) goto loc_82157D64;
	// lbz r11,56(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 56);
	// lhz r10,60(r21)
	ctx.r10.u64 = PPC_LOAD_U16(r21.u32 + 60);
	// rlwinm r9,r11,0,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// extsh r3,r10
	ctx.r3.s64 = ctx.r10.s16;
	// stb r9,56(r21)
	PPC_STORE_U8(r21.u32 + 56, ctx.r9.u8);
	// bl 0x821374b0
	ctx.lr = 0x82157D28;
	sub_821374B0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82157ab8
	ctx.lr = 0x82157D38;
	sub_82157AB8(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x82158588
	if (cr6.lt) goto loc_82158588;
	// beq cr6,0x82157d64
	if (cr6.eq) goto loc_82157D64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r5,184(r21)
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + 184);
	// lhz r4,208(r21)
	ctx.r4.u64 = PPC_LOAD_U16(r21.u32 + 208);
	// addi r3,r11,24288
	ctx.r3.s64 = r11.s64 + 24288;
	// bl 0x82130000
	ctx.lr = 0x82157D58;
	sub_82130000(ctx, base);
loc_82157D58:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9224
	return;
loc_82157D64:
	// lwz r11,196(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 196);
	// li r20,0
	r20.s64 = 0;
	// mr r29,r20
	r29.u64 = r20.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82157e14
	if (!cr6.gt) goto loc_82157E14;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r28,r21,72
	r28.s64 = r21.s64 + 72;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
loc_82157D84:
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82157e04
	if (cr6.eq) goto loc_82157E04;
	// lbz r10,64(r21)
	ctx.r10.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// mullw r11,r8,r9
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82157e04
	if (cr6.eq) goto loc_82157E04;
	// add r11,r29,r21
	r11.u64 = r29.u64 + r21.u64;
	// lbz r11,164(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 164);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82157de8
	if (cr6.eq) goto loc_82157DE8;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// bne cr6,0x82157de8
	if (!cr6.eq) goto loc_82157DE8;
	// lbz r10,58(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 58);
	// stb r11,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r11.u8);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,26,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// stb r9,58(r31)
	PPC_STORE_U8(r31.u32 + 58, ctx.r9.u8);
loc_82157DE8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,184(r21)
	ctx.r4.u64 = PPC_LOAD_U32(r21.u32 + 184);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x82157DF8;
	sub_8213B7B0(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d890
	ctx.lr = 0x82157E04;
	sub_8213D890(ctx, base);
loc_82157E04:
	// lwz r11,196(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 196);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// blt cr6,0x82157d84
	if (cr6.lt) goto loc_82157D84;
loc_82157E14:
	// stb r20,213(r21)
	PPC_STORE_U8(r21.u32 + 213, r20.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9224
	return;
loc_82157E24:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,196(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 196);
	// li r20,0
	r20.s64 = 0;
	// addi r28,r11,7216
	r28.s64 = r11.s64 + 7216;
	// stw r20,188(r21)
	PPC_STORE_U32(r21.u32 + 188, r20.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r19,1
	r19.s64 = 1;
	// mr r25,r20
	r25.u64 = r20.u64;
	// mr r24,r20
	r24.u64 = r20.u64;
	// lwz r10,196(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// mr r23,r20
	r23.u64 = r20.u64;
	// ble cr6,0x8215802c
	if (!cr6.gt) goto loc_8215802C;
	// addi r27,r21,72
	r27.s64 = r21.s64 + 72;
	// subfic r26,r21,-72
	xer.ca = r21.u32 <= 4294967224;
	r26.s64 = -72 - r21.s64;
loc_82157E5C:
	// lbz r11,0(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82158018
	if (cr6.eq) goto loc_82158018;
	// lbz r8,64(r21)
	ctx.r8.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// mullw r7,r10,r11
	ctx.r7.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r9,11440(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r7,r9
	ctx.r8.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82158018
	if (cr6.eq) goto loc_82158018;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82157ea0
	if (cr6.eq) goto loc_82157EA0;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// b 0x82157ea4
	goto loc_82157EA4;
loc_82157EA0:
	// mr r8,r20
	ctx.r8.u64 = r20.u64;
loc_82157EA4:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82157ff0
	if (!cr6.eq) goto loc_82157FF0;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82157ec4
	if (cr6.eq) goto loc_82157EC4;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82157ec8
	goto loc_82157EC8;
loc_82157EC4:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
loc_82157EC8:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x8213e040
	ctx.lr = 0x82157ED0;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157ee0
	if (cr6.eq) goto loc_82157EE0;
	// mr r25,r19
	r25.u64 = r19.u64;
loc_82157EE0:
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
	// li r10,16
	ctx.r10.s64 = 16;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82157EF0:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82157ef0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82157EF0;
	// lbz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + 0);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82157f2c
	if (cr6.eq) goto loc_82157F2C;
	// lbz r11,64(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// lwz r10,232(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82157f30
	goto loc_82157F30;
loc_82157F2C:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
loc_82157F30:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x8213d058
	ctx.lr = 0x82157F44;
	sub_8213D058(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r23,2,0,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r1,144
	r30.s64 = ctx.r1.s64 + 144;
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// li r29,16
	r29.s64 = 16;
	// lwz r10,196(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 196);
loc_82157F5C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82157fe0
	if (cr6.eq) goto loc_82157FE0;
	// lbz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82157fe0
	if (cr6.eq) goto loc_82157FE0;
	// lbz r6,64(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// mulli r9,r6,11488
	ctx.r9.s64 = ctx.r6.s64 * 11488;
	// add r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwz r9,11440(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82157fe0
	if (cr6.eq) goto loc_82157FE0;
	// lbz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82157fc4
	if (cr6.eq) goto loc_82157FC4;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// rotlwi r9,r7,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82157fc8
	goto loc_82157FC8;
loc_82157FC4:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
loc_82157FC8:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214a6a8
	ctx.lr = 0x82157FD0;
	sub_8214A6A8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lwz r10,196(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 196);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
loc_82157FE0:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82157f5c
	if (!cr0.eq) goto loc_82157F5C;
	// b 0x82158018
	goto loc_82158018;
loc_82157FF0:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82158004
	if (cr6.eq) goto loc_82158004;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82158008
	goto loc_82158008;
loc_82158004:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_82158008:
	// lhz r11,6(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x82158018
	if (!cr6.eq) goto loc_82158018;
	// mr r24,r19
	r24.u64 = r19.u64;
loc_82158018:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// lwz r11,196(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 196);
	// add r9,r26,r27
	ctx.r9.u64 = r26.u64 + r27.u64;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// blt cr6,0x82157e5c
	if (cr6.lt) goto loc_82157E5C;
loc_8215802C:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215804c
	if (!cr6.eq) goto loc_8215804C;
	// li r11,3
	r11.s64 = 3;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,210(r21)
	PPC_STORE_U8(r21.u32 + 210, r11.u8);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9224
	return;
loc_8215804C:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158118
	if (cr6.eq) goto loc_82158118;
	// lbz r11,216(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158118
	if (cr6.eq) goto loc_82158118;
	// lbz r11,211(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 211);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82158118
	if (!cr6.eq) goto loc_82158118;
	// lwz r11,196(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x82158114
	if (!cr6.gt) goto loc_82158114;
	// addi r6,r21,72
	ctx.r6.s64 = r21.s64 + 72;
	// subfic r5,r21,-72
	xer.ca = r21.u32 <= 4294967224;
	ctx.r5.s64 = -72 - r21.s64;
loc_82158084:
	// lbz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82158100
	if (cr6.eq) goto loc_82158100;
	// lbz r11,64(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 64);
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// lwz r7,232(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 232);
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
	// beq cr6,0x82158100
	if (cr6.eq) goto loc_82158100;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821580c8
	if (cr6.eq) goto loc_821580C8;
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + r11.u64;
	// b 0x821580cc
	goto loc_821580CC;
loc_821580C8:
	// mr r8,r20
	ctx.r8.u64 = r20.u64;
loc_821580CC:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82158100
	if (!cr6.eq) goto loc_82158100;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821580ec
	if (cr6.eq) goto loc_821580EC;
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x821580f0
	goto loc_821580F0;
loc_821580EC:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_821580F0:
	// lbz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 56);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,56(r11)
	PPC_STORE_U8(r11.u32 + 56, ctx.r9.u8);
	// lwz r10,196(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 196);
loc_82158100:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lwz r11,196(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 196);
	// add r9,r6,r5
	ctx.r9.u64 = ctx.r6.u64 + ctx.r5.u64;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// blt cr6,0x82158084
	if (cr6.lt) goto loc_82158084;
loc_82158114:
	// stb r19,211(r21)
	PPC_STORE_U8(r21.u32 + 211, r19.u8);
loc_82158118:
	// lbz r11,214(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 214);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82158510
	if (!cr6.eq) goto loc_82158510;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82157240
	ctx.lr = 0x8215812C;
	sub_82157240(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158588
	if (cr6.eq) goto loc_82158588;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
	// li r10,16
	ctx.r10.s64 = 16;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82158148:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82158148
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82158148;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,15
	ctx.r4.s64 = 15;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8213d058
	ctx.lr = 0x8215816C;
	sub_8213D058(ctx, base);
	// lhz r11,60(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82158178;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8215818c
	if (cr6.eq) goto loc_8215818C;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82158190
	if (!cr6.eq) goto loc_82158190;
loc_8215818C:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
loc_82158190:
	// lwz r11,204(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 204);
	// lbz r6,217(r21)
	ctx.r6.u64 = PPC_LOAD_U8(r21.u32 + 217);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lhz r4,208(r21)
	ctx.r4.u64 = PPC_LOAD_U16(r21.u32 + 208);
	// rlwinm r5,r10,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x82145ca8
	ctx.lr = 0x821581A8;
	sub_82145CA8(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x821581e0
	if (cr6.lt) goto loc_821581E0;
	// beq cr6,0x82158588
	if (cr6.eq) goto loc_82158588;
	// lwz r11,204(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82158364
	if (!cr6.eq) goto loc_82158364;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r5,184(r21)
	ctx.r5.u64 = PPC_LOAD_U32(r21.u32 + 184);
	// lhz r4,208(r21)
	ctx.r4.u64 = PPC_LOAD_U16(r21.u32 + 208);
	// addi r3,r11,24200
	ctx.r3.s64 = r11.s64 + 24200;
	// bl 0x82130000
	ctx.lr = 0x821581D4;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9224
	return;
loc_821581E0:
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r6,4
	ctx.r6.s64 = 4;
loc_821581E8:
	// lwz r11,-4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158244
	if (cr6.eq) goto loc_82158244;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lbz r11,220(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82158234
	if (cr6.eq) goto loc_82158234;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x82158238
	goto loc_82158238;
loc_82158234:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_82158238:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_82158244:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821582a0
	if (cr6.eq) goto loc_821582A0;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lbz r11,220(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82158290
	if (cr6.eq) goto loc_82158290;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x82158294
	goto loc_82158294;
loc_82158290:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_82158294:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_821582A0:
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821582fc
	if (cr6.eq) goto loc_821582FC;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lbz r11,220(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821582ec
	if (cr6.eq) goto loc_821582EC;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x821582f0
	goto loc_821582F0;
loc_821582EC:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_821582F0:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_821582FC:
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158358
	if (cr6.eq) goto loc_82158358;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lbz r11,220(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82158348
	if (cr6.eq) goto loc_82158348;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8215834c
	goto loc_8215834C;
loc_82158348:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_8215834C:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_82158358:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// bne 0x821581e8
	if (!cr0.eq) goto loc_821581E8;
loc_82158364:
	// lwz r11,204(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 204);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,204(r21)
	PPC_STORE_U32(r21.u32 + 204, r11.u32);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x82158588
	if (!cr6.eq) goto loc_82158588;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r6,4
	ctx.r6.s64 = 4;
loc_82158380:
	// lwz r11,-4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821583dc
	if (cr6.eq) goto loc_821583DC;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lbz r11,220(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821583cc
	if (cr6.eq) goto loc_821583CC;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x821583d0
	goto loc_821583D0;
loc_821583CC:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_821583D0:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_821583DC:
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158438
	if (cr6.eq) goto loc_82158438;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lbz r11,220(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82158428
	if (cr6.eq) goto loc_82158428;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x8215842c
	goto loc_8215842C;
loc_82158428:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_8215842C:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_82158438:
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158494
	if (cr6.eq) goto loc_82158494;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lbz r11,220(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82158484
	if (cr6.eq) goto loc_82158484;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x82158488
	goto loc_82158488;
loc_82158484:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_82158488:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_82158494:
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821584f0
	if (cr6.eq) goto loc_821584F0;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lbz r11,220(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 220);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r9,232(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 232);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lbzx r5,r8,r9
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// clrlwi r4,r5,31
	ctx.r4.u64 = ctx.r5.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x821584e0
	if (cr6.eq) goto loc_821584E0;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// b 0x821584e4
	goto loc_821584E4;
loc_821584E0:
	// mr r11,r20
	r11.u64 = r20.u64;
loc_821584E4:
	// lbz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 24);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,24(r11)
	PPC_STORE_U8(r11.u32 + 24, ctx.r9.u8);
loc_821584F0:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// bne 0x82158380
	if (!cr0.eq) goto loc_82158380;
	// stb r19,214(r21)
	PPC_STORE_U8(r21.u32 + 214, r19.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r20,204(r21)
	PPC_STORE_U32(r21.u32 + 204, r20.u32);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9224
	return;
loc_82158510:
	// lbz r11,215(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 215);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82158588
	if (!cr6.eq) goto loc_82158588;
	// lwz r11,188(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 188);
	// cmplw cr6,r11,r23
	cr6.compare<uint32_t>(r11.u32, r23.u32, xer);
	// bne cr6,0x82158588
	if (!cr6.eq) goto loc_82158588;
	// lhz r11,60(r21)
	r11.u64 = PPC_LOAD_U16(r21.u32 + 60);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// bl 0x821374b0
	ctx.lr = 0x82158534;
	sub_821374B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82158548
	if (cr6.eq) goto loc_82158548;
	// lbz r11,72(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215854c
	if (!cr6.eq) goto loc_8215854C;
loc_82158548:
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
loc_8215854C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r6,217(r21)
	ctx.r6.u64 = PPC_LOAD_U8(r21.u32 + 217);
	// lhz r4,208(r21)
	ctx.r4.u64 = PPC_LOAD_U16(r21.u32 + 208);
	// bl 0x82145ca8
	ctx.lr = 0x8215855C;
	sub_82145CA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82158584
	if (cr6.eq) goto loc_82158584;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82157d58
	if (cr6.eq) goto loc_82157D58;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82158588
	if (!cr6.eq) goto loc_82158588;
	// stb r19,215(r21)
	PPC_STORE_U8(r21.u32 + 215, r19.u8);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9224
	return;
loc_82158584:
	// stw r23,192(r21)
	PPC_STORE_U32(r21.u32 + 192, r23.u32);
loc_82158588:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82158594"))) PPC_WEAK_FUNC(sub_82158594);
PPC_FUNC_IMPL(__imp__sub_82158594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82158598"))) PPC_WEAK_FUNC(sub_82158598);
PPC_FUNC_IMPL(__imp__sub_82158598) {
	PPC_FUNC_PROLOGUE();
	// b 0x82157ab8
	sub_82157AB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215859C"))) PPC_WEAK_FUNC(sub_8215859C);
PPC_FUNC_IMPL(__imp__sub_8215859C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821585A0"))) PPC_WEAK_FUNC(sub_821585A0);
PPC_FUNC_IMPL(__imp__sub_821585A0) {
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
	ctx.lr = 0x821585A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lbz r11,210(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 210);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82158628
	if (cr6.lt) goto loc_82158628;
	// beq cr6,0x821585fc
	if (cr6.eq) goto loc_821585FC;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x82158628
	if (!cr6.lt) goto loc_82158628;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82157cc0
	ctx.lr = 0x821585D8;
	sub_82157CC0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821576b8
	ctx.lr = 0x821585E8;
	sub_821576B8(ctx, base);
	// stw r3,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_821585FC:
	// lwz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// li r11,0
	r11.s64 = 0;
	// li r9,2
	ctx.r9.s64 = 2;
	// stb r3,213(r31)
	PPC_STORE_U8(r31.u32 + 213, ctx.r3.u8);
	// stb r11,214(r31)
	PPC_STORE_U8(r31.u32 + 214, r11.u8);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// stb r9,210(r31)
	PPC_STORE_U8(r31.u32 + 210, ctx.r9.u8);
	// stw r10,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r10.u32);
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82158628:
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82158638"))) PPC_WEAK_FUNC(sub_82158638);
PPC_FUNC_IMPL(__imp__sub_82158638) {
	PPC_FUNC_PROLOGUE();
	// b 0x821585a0
	sub_821585A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215863C"))) PPC_WEAK_FUNC(sub_8215863C);
PPC_FUNC_IMPL(__imp__sub_8215863C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82158640"))) PPC_WEAK_FUNC(sub_82158640);
PPC_FUNC_IMPL(__imp__sub_82158640) {
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
	// bl 0x8213b968
	ctx.lr = 0x82158658;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,24688
	ctx.r7.s64 = r11.s64 + 24688;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r9,255
	ctx.r9.s64 = 255;
	// stw r10,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r10.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,164(r31)
	PPC_STORE_U32(r31.u32 + 164, r11.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stb r10,184(r31)
	PPC_STORE_U8(r31.u32 + 184, ctx.r10.u8);
	// addi r11,r31,164
	r11.s64 = r31.s64 + 164;
	// stb r10,185(r31)
	PPC_STORE_U8(r31.u32 + 185, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r6.u32);
	// stb r9,197(r31)
	PPC_STORE_U8(r31.u32 + 197, ctx.r9.u8);
	// stb r9,196(r31)
	PPC_STORE_U8(r31.u32 + 196, ctx.r9.u8);
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

__attribute__((alias("__imp__sub_821586C0"))) PPC_WEAK_FUNC(sub_821586C0);
PPC_FUNC_IMPL(__imp__sub_821586C0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lbz r11,198(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158758
	if (cr6.eq) goto loc_82158758;
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// addic. r11,r11,1
	xer.ca = r11.u32 > 4294967294;
	r11.s64 = r11.s64 + 1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82158758
	if (!cr0.gt) goto loc_82158758;
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82158758
	if (!cr6.lt) goto loc_82158758;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r7,197(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 197);
	// addi r6,r10,7216
	ctx.r6.s64 = ctx.r10.s64 + 7216;
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r11,232(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 232);
	// lwz r10,196(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 196);
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11440(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// addi r6,r31,164
	ctx.r6.s64 = r31.s64 + 164;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// bl 0x8213b7d0
	ctx.lr = 0x82158740;
	sub_8213B7D0(ctx, base);
	// cmplwi cr6,r30,2
	cr6.compare<uint32_t>(r30.u32, 2, xer);
	// bge cr6,0x82158758
	if (!cr6.lt) goto loc_82158758;
	// addi r11,r30,39
	r11.s64 = r30.s64 + 39;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r31
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, ctx.r10.u32);
loc_82158758:
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

__attribute__((alias("__imp__sub_82158770"))) PPC_WEAK_FUNC(sub_82158770);
PPC_FUNC_IMPL(__imp__sub_82158770) {
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
	ctx.lr = 0x82158778;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,24688
	ctx.r10.s64 = r11.s64 + 24688;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r28,r31,72
	r28.s64 = r31.s64 + 72;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_821587A4:
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821587e4
	if (cr6.eq) goto loc_821587E4;
	// lbz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 64);
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821587e4
	if (cr6.eq) goto loc_821587E4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x821587DC;
	sub_8214E5B8(ctx, base);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_821587E4:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,8
	cr6.compare<int32_t>(r29.s32, 8, xer);
	// blt cr6,0x821587a4
	if (cr6.lt) goto loc_821587A4;
	// lbz r11,197(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 197);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82158824
	if (cr6.eq) goto loc_82158824;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// mulli r11,r5,11488
	r11.s64 = ctx.r5.s64 * 11488;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,11440(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213f7a8
	ctx.lr = 0x8215881C;
	sub_8213F7A8(ctx, base);
	// li r10,255
	ctx.r10.s64 = 255;
	// stb r10,197(r31)
	PPC_STORE_U8(r31.u32 + 197, ctx.r10.u8);
loc_82158824:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x8215882C;
	sub_8213BA48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82158834"))) PPC_WEAK_FUNC(sub_82158834);
PPC_FUNC_IMPL(__imp__sub_82158834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82158838"))) PPC_WEAK_FUNC(sub_82158838);
PPC_FUNC_IMPL(__imp__sub_82158838) {
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
	ctx.lr = 0x82158840;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x82158854;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215886c
	if (!cr6.eq) goto loc_8215886C;
loc_82158860:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_8215886C:
	// lwz r29,148(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lwz r11,112(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r10,r11,0,20,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xC00;
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,1024
	cr6.compare<uint32_t>(ctx.r10.u32, 1024, xer);
	// stw r11,188(r31)
	PPC_STORE_U32(r31.u32 + 188, r11.u32);
	// beq cr6,0x82158894
	if (cr6.eq) goto loc_82158894;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// li r11,0
	r11.s64 = 0;
	// ble cr6,0x82158898
	if (!cr6.gt) goto loc_82158898;
loc_82158894:
	// li r11,1
	r11.s64 = 1;
loc_82158898:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,198(r31)
	PPC_STORE_U8(r31.u32 + 198, ctx.r10.u8);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// beq cr6,0x82158964
	if (cr6.eq) goto loc_82158964;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82158860
	if (cr6.gt) goto loc_82158860;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// li r6,1
	ctx.r6.s64 = 1;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x8213e928
	ctx.lr = 0x821588D8;
	sub_8213E928(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82158860
	if (cr6.eq) goto loc_82158860;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// li r11,0
	r11.s64 = 0;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r7,r8,11488
	ctx.r7.s64 = ctx.r8.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// lwz r6,188(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// add r5,r7,r10
	ctx.r5.u64 = ctx.r7.u64 + ctx.r10.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// twllei r8,0
	// lwz r4,11440(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11440);
	// subf r3,r4,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r4.s64;
	// divwu r10,r3,r8
	ctx.r10.u32 = ctx.r3.u32 / ctx.r8.u32;
	// stb r10,197(r31)
	PPC_STORE_U8(r31.u32 + 197, ctx.r10.u8);
	// ble cr6,0x82158940
	if (!cr6.gt) goto loc_82158940;
	// addi r10,r29,1
	ctx.r10.s64 = r29.s64 + 1;
loc_82158920:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lwz r7,188(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x82158920
	if (cr6.lt) goto loc_82158920;
loc_82158940:
	// addi r10,r31,164
	ctx.r10.s64 = r31.s64 + 164;
	// mr r11,r25
	r11.u64 = r25.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82158950:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82158950
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82158950;
loc_82158964:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r25
	r11.u64 = r25.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82158974:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82158974
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82158974;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r28,0
	r28.s64 = 0;
	// addi r27,r31,156
	r27.s64 = r31.s64 + 156;
	// addi r29,r29,5
	r29.s64 = r29.s64 + 5;
	// addi r26,r11,19856
	r26.s64 = r11.s64 + 19856;
loc_8215899C:
	// lbz r11,198(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,2
	r11.s64 = 2;
	// bne cr6,0x821589b0
	if (!cr6.eq) goto loc_821589B0;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
loc_821589B0:
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x82158a84
	if (!cr6.lt) goto loc_82158A84;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r25
	ctx.r10.u64 = r25.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_821589C8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x821589c8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_821589C8;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// lwz r4,-4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -4);
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r26,608
	ctx.r3.s64 = r26.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x821589F4;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82158a28
	if (cr6.eq) goto loc_82158A28;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x82158a2c
	goto loc_82158A2C;
loc_82158A28:
	// li r11,255
	r11.s64 = 255;
loc_82158A2C:
	// add r10,r28,r31
	ctx.r10.u64 = r28.u64 + r31.u64;
	// cmplwi cr6,r28,2
	cr6.compare<uint32_t>(r28.u32, 2, xer);
	// stb r11,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, r11.u8);
	// bge cr6,0x82158a44
	if (!cr6.lt) goto loc_82158A44;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
loc_82158A44:
	// lbz r8,72(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82158860
	if (cr6.eq) goto loc_82158860;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add. r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x82158860
	if (cr0.eq) goto loc_82158860;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// addi r29,r29,8
	r29.s64 = r29.s64 + 8;
	// b 0x8215899c
	goto loc_8215899C;
loc_82158A84:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82158A90"))) PPC_WEAK_FUNC(sub_82158A90);
PPC_FUNC_IMPL(__imp__sub_82158A90) {
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
	ctx.lr = 0x82158A98;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// li r25,1
	r25.s64 = 1;
	// li r26,0
	r26.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
loc_82158ABC:
	// lbz r11,198(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,2
	r11.s64 = 2;
	// bne cr6,0x82158ad0
	if (!cr6.eq) goto loc_82158AD0;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
loc_82158AD0:
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x82158b68
	if (!cr6.lt) goto loc_82158B68;
	// add r11,r29,r31
	r11.u64 = r29.u64 + r31.u64;
	// lbz r11,72(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82158b60
	if (cr6.eq) goto loc_82158B60;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r8,r11
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82158b60
	if (cr6.eq) goto loc_82158B60;
	// lbz r9,57(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r9,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x1;
	// beq cr6,0x82158b30
	if (cr6.eq) goto loc_82158B30;
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82158b34
	goto loc_82158B34;
loc_82158B30:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82158B34:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213da88
	ctx.lr = 0x82158B40;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82158b54
	if (!cr6.eq) goto loc_82158B54;
	// li r26,1
	r26.s64 = 1;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// b 0x82158abc
	goto loc_82158ABC;
loc_82158B54:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82158b60
	if (!cr6.eq) goto loc_82158B60;
	// li r25,0
	r25.s64 = 0;
loc_82158B60:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// b 0x82158abc
	goto loc_82158ABC;
loc_82158B68:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158b80
	if (cr6.eq) goto loc_82158B80;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82158B80:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82158B98"))) PPC_WEAK_FUNC(sub_82158B98);
PPC_FUNC_IMPL(__imp__sub_82158B98) {
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
	ctx.lr = 0x82158BA0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r28,0
	r28.s64 = 0;
	// lbz r11,198(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158bd0
	if (cr6.eq) goto loc_82158BD0;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// stw r28,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r28.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82158BD0:
	// lwz r26,84(r31)
	r26.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r27,r28
	r27.u64 = r28.u64;
	// stw r28,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r28.u32);
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82158c90
	if (!cr6.gt) goto loc_82158C90;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
loc_82158BF4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// stb r28,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r28.u8);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lbz r11,72(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82158c30
	if (cr6.eq) goto loc_82158C30;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82158c34
	goto loc_82158C34;
loc_82158C30:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_82158C34:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x82158C3C;
	sub_8213C758(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82158c7c
	if (cr6.eq) goto loc_82158C7C;
	// add r27,r3,r27
	r27.u64 = ctx.r3.u64 + r27.u64;
	// cmplw cr6,r27,r26
	cr6.compare<uint32_t>(r27.u32, r26.u32, xer);
	// bge cr6,0x82158c84
	if (!cr6.lt) goto loc_82158C84;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82158c84
	if (!cr6.eq) goto loc_82158C84;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x82158bf4
	if (cr6.lt) goto loc_82158BF4;
	// b 0x82158c90
	goto loc_82158C90;
loc_82158C7C:
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// b 0x82158c90
	goto loc_82158C90;
loc_82158C84:
	// subf r11,r27,r3
	r11.s64 = ctx.r3.s64 - r27.s64;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// stw r11,0(r25)
	PPC_STORE_U32(r25.u32 + 0, r11.u32);
loc_82158C90:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82158ca8
	if (cr6.lt) goto loc_82158CA8;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
loc_82158CA8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82158CB0"))) PPC_WEAK_FUNC(sub_82158CB0);
PPC_FUNC_IMPL(__imp__sub_82158CB0) {
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
	ctx.lr = 0x82158CB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82158b98
	ctx.lr = 0x82158CD0;
	sub_82158B98(ctx, base);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x82158d68
	if (cr6.lt) goto loc_82158D68;
	// stw r29,192(r30)
	PPC_STORE_U32(r30.u32 + 192, r29.u32);
	// li r31,0
	r31.s64 = 0;
	// ble cr6,0x82158d0c
	if (!cr6.gt) goto loc_82158D0C;
loc_82158CE8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82158CF4;
	sub_8214E5B8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821586c0
	ctx.lr = 0x82158D00;
	sub_821586C0(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82158ce8
	if (cr6.lt) goto loc_82158CE8;
loc_82158D0C:
	// add r11,r29,r30
	r11.u64 = r29.u64 + r30.u64;
	// lbz r8,72(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82158d68
	if (cr6.eq) goto loc_82158D68;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82158d68
	if (cr6.eq) goto loc_82158D68;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x82158D5C;
	sub_8213B7B0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d890
	ctx.lr = 0x82158D68;
	sub_8213D890(ctx, base);
loc_82158D68:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82158D70"))) PPC_WEAK_FUNC(sub_82158D70);
PPC_FUNC_IMPL(__imp__sub_82158D70) {
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
	ctx.lr = 0x82158D78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 196);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82158e18
	if (cr6.eq) goto loc_82158E18;
	// lhz r11,60(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// extsh r3,r11
	ctx.r3.s64 = r11.s16;
	// rlwinm r29,r10,30,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// bl 0x821374b0
	ctx.lr = 0x82158DAC;
	sub_821374B0(ctx, base);
	// lbz r11,196(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 196);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// lbz r11,72(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82158de8
	if (cr6.eq) goto loc_82158DE8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82158dec
	goto loc_82158DEC;
loc_82158DE8:
	// li r11,0
	r11.s64 = 0;
loc_82158DEC:
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8213da88
	ctx.lr = 0x82158DFC;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x82158e10
	if (cr6.eq) goto loc_82158E10;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,196(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 196);
	// bl 0x8214e5b8
	ctx.lr = 0x82158E10;
	sub_8214E5B8(ctx, base);
loc_82158E10:
	// li r11,255
	r11.s64 = 255;
	// stb r11,196(r31)
	PPC_STORE_U8(r31.u32 + 196, r11.u8);
loc_82158E18:
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82158fcc
	if (cr6.lt) goto loc_82158FCC;
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x82158fcc
	if (!cr6.lt) goto loc_82158FCC;
	// lbz r10,198(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82158e50
	if (cr6.eq) goto loc_82158E50;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r29,r8,r11
	r29.s64 = r11.s64 - ctx.r8.s64;
	// b 0x82158e54
	goto loc_82158E54;
loc_82158E50:
	// mr r29,r11
	r29.u64 = r11.u64;
loc_82158E54:
	// add r11,r29,r31
	r11.u64 = r29.u64 + r31.u64;
	// lbz r9,72(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82158eb8
	if (cr6.eq) goto loc_82158EB8;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82158eb8
	if (cr6.eq) goto loc_82158EB8;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82158ea0
	if (cr6.eq) goto loc_82158EA0;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82158ea4
	goto loc_82158EA4;
loc_82158EA0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82158EA4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213e040
	ctx.lr = 0x82158EAC;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82158fc0
	if (!cr6.eq) goto loc_82158FC0;
loc_82158EB8:
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82158fcc
	if (!cr6.eq) goto loc_82158FCC;
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// lbz r10,198(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 198);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,192(r31)
	PPC_STORE_U32(r31.u32 + 192, r11.u32);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// beq cr6,0x82158ef4
	if (cr6.eq) goto loc_82158EF4;
	// srawi r9,r10,1
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// addze r8,r9
	temp.s64 = ctx.r9.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r8.s64 = temp.s64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r7,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r7.s64;
loc_82158EF4:
	// lwz r9,188(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// cmpw cr6,r9,r11
	cr6.compare<int32_t>(ctx.r9.s32, r11.s32, xer);
	// ble cr6,0x82158fcc
	if (!cr6.gt) goto loc_82158FCC;
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// lbz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82158fcc
	if (cr6.eq) goto loc_82158FCC;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82158fcc
	if (cr6.eq) goto loc_82158FCC;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82158f78
	if (cr6.eq) goto loc_82158F78;
	// mullw r7,r11,r10
	ctx.r7.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82158f78
	if (cr6.eq) goto loc_82158F78;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82158f64
	if (cr6.eq) goto loc_82158F64;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82158f68
	goto loc_82158F68;
loc_82158F64:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82158F68:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x82158F70;
	sub_8213D890(ctx, base);
	// lwz r8,232(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_82158F78:
	// add r10,r29,r31
	ctx.r10.u64 = r29.u64 + r31.u64;
	// lbz r10,72(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 72);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82158fc0
	if (cr6.eq) goto loc_82158FC0;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// mulli r11,r9,11488
	r11.s64 = ctx.r9.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82158fc0
	if (cr6.eq) goto loc_82158FC0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x82158FB4;
	sub_8214E5B8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821586c0
	ctx.lr = 0x82158FC0;
	sub_821586C0(ctx, base);
loc_82158FC0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82158FCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82158FD8"))) PPC_WEAK_FUNC(sub_82158FD8);
PPC_FUNC_IMPL(__imp__sub_82158FD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,192(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r10,188(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lbz r10,198(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 198);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8215900c
	if (cr6.eq) goto loc_8215900C;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
loc_8215900C:
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lbz r8,72(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82159048
	if (cr6.eq) goto loc_82159048;
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
	// b 0x8215904c
	goto loc_8215904C;
loc_82159048:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215904C:
	// b 0x8213b5c0
	sub_8213B5C0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82159050"))) PPC_WEAK_FUNC(sub_82159050);
PPC_FUNC_IMPL(__imp__sub_82159050) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82159054"))) PPC_WEAK_FUNC(sub_82159054);
PPC_FUNC_IMPL(__imp__sub_82159054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159058"))) PPC_WEAK_FUNC(sub_82159058);
PPC_FUNC_IMPL(__imp__sub_82159058) {
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
	ctx.lr = 0x82159060;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// li r28,-1
	r28.s64 = -1;
	// lbz r11,198(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 198);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82159138
	if (!cr6.eq) goto loc_82159138;
	// lwz r11,188(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82159138
	if (!cr6.gt) goto loc_82159138;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// subfic r26,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r26.s64 = -72 - r30.s64;
	// li r27,0
	r27.s64 = 0;
	// li r25,1
	r25.s64 = 1;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_821590A4:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82159124
	if (cr6.eq) goto loc_82159124;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// lwz r8,11440(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82159124
	if (cr6.eq) goto loc_82159124;
	// stb r27,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r27.u8);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821590f0
	if (cr6.eq) goto loc_821590F0;
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// mullw r11,r7,r10
	r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x821590f4
	goto loc_821590F4;
loc_821590F0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_821590F4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x821590FC;
	sub_8213C758(ctx, base);
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82159114
	if (cr6.eq) goto loc_82159114;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82159114
	if (cr6.eq) goto loc_82159114;
	// stb r25,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r25.u8);
loc_82159114:
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x82159144
	if (cr6.eq) goto loc_82159144;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r28,r3,r28
	r28.u64 = ctx.r3.u64 + r28.u64;
loc_82159124:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lwz r11,188(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// add r10,r26,r29
	ctx.r10.u64 = r26.u64 + r29.u64;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x821590a4
	if (cr6.lt) goto loc_821590A4;
loc_82159138:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82159144:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82159150"))) PPC_WEAK_FUNC(sub_82159150);
PPC_FUNC_IMPL(__imp__sub_82159150) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// add r11,r5,r3
	r11.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lbz r8,72(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beqlr cr6
	if (cr6.eq) return;
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
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r5,196(r3)
	PPC_STORE_U8(ctx.r3.u32 + 196, ctx.r5.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82159198"))) PPC_WEAK_FUNC(sub_82159198);
PPC_FUNC_IMPL(__imp__sub_82159198) {
	PPC_FUNC_PROLOGUE();
	// b 0x82158d70
	sub_82158D70(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215919C"))) PPC_WEAK_FUNC(sub_8215919C);
PPC_FUNC_IMPL(__imp__sub_8215919C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821591A0"))) PPC_WEAK_FUNC(sub_821591A0);
PPC_FUNC_IMPL(__imp__sub_821591A0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82158fd8
	sub_82158FD8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821591A4"))) PPC_WEAK_FUNC(sub_821591A4);
PPC_FUNC_IMPL(__imp__sub_821591A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821591A8"))) PPC_WEAK_FUNC(sub_821591A8);
PPC_FUNC_IMPL(__imp__sub_821591A8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82158a90
	sub_82158A90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821591AC"))) PPC_WEAK_FUNC(sub_821591AC);
PPC_FUNC_IMPL(__imp__sub_821591AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821591B0"))) PPC_WEAK_FUNC(sub_821591B0);
PPC_FUNC_IMPL(__imp__sub_821591B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82158cb0
	sub_82158CB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821591B4"))) PPC_WEAK_FUNC(sub_821591B4);
PPC_FUNC_IMPL(__imp__sub_821591B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821591B8"))) PPC_WEAK_FUNC(sub_821591B8);
PPC_FUNC_IMPL(__imp__sub_821591B8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82159058
	sub_82159058(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821591BC"))) PPC_WEAK_FUNC(sub_821591BC);
PPC_FUNC_IMPL(__imp__sub_821591BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821591C0"))) PPC_WEAK_FUNC(sub_821591C0);
PPC_FUNC_IMPL(__imp__sub_821591C0) {
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
	// bl 0x82158770
	ctx.lr = 0x821591E0;
	sub_82158770(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82159208
	if (cr6.eq) goto loc_82159208;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82159208
	if (cr6.eq) goto loc_82159208;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x82159208;
	sub_8213F7A8(ctx, base);
loc_82159208:
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

__attribute__((alias("__imp__sub_82159224"))) PPC_WEAK_FUNC(sub_82159224);
PPC_FUNC_IMPL(__imp__sub_82159224) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159228"))) PPC_WEAK_FUNC(sub_82159228);
PPC_FUNC_IMPL(__imp__sub_82159228) {
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
	// bl 0x8213b968
	ctx.lr = 0x82159240;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,25056
	ctx.r10.s64 = r11.s64 + 25056;
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

__attribute__((alias("__imp__sub_82159264"))) PPC_WEAK_FUNC(sub_82159264);
PPC_FUNC_IMPL(__imp__sub_82159264) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159268"))) PPC_WEAK_FUNC(sub_82159268);
PPC_FUNC_IMPL(__imp__sub_82159268) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r10,25056
	ctx.r9.s64 = ctx.r10.s64 + 25056;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x821592dc
	if (!cr6.eq) goto loc_821592DC;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x821592dc
	if (cr6.eq) goto loc_821592DC;
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
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821592dc
	if (cr6.eq) goto loc_821592DC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x821592DC;
	sub_8214E5B8(ctx, base);
loc_821592DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x821592E4;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_821592F8"))) PPC_WEAK_FUNC(sub_821592F8);
PPC_FUNC_IMPL(__imp__sub_821592F8) {
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
	ctx.lr = 0x82159300;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x82159314;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215932c
	if (!cr6.eq) goto loc_8215932C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8215932C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// addi r11,r11,19856
	r11.s64 = r11.s64 + 19856;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,608
	ctx.r3.s64 = r11.s64 + 608;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x82144720
	ctx.lr = 0x82159350;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82159398
	if (cr6.eq) goto loc_82159398;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
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
	// subf r5,r6,r3
	ctx.r5.s64 = ctx.r3.s64 - ctx.r6.s64;
	// li r3,1
	ctx.r3.s64 = 1;
	// divwu r4,r5,r10
	ctx.r4.u32 = ctx.r5.u32 / ctx.r10.u32;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82159398:
	// li r11,255
	r11.s64 = 255;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_821593AC"))) PPC_WEAK_FUNC(sub_821593AC);
PPC_FUNC_IMPL(__imp__sub_821593AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821593B0"))) PPC_WEAK_FUNC(sub_821593B0);
PPC_FUNC_IMPL(__imp__sub_821593B0) {
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
	ctx.lr = 0x821593B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,72(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82159468
	if (cr6.eq) goto loc_82159468;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159468
	if (cr6.eq) goto loc_82159468;
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82159418
	if (cr6.eq) goto loc_82159418;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8215941c
	goto loc_8215941C;
loc_82159418:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215941C:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82159424;
	sub_8213B7B0(ctx, base);
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82159454
	if (cr6.eq) goto loc_82159454;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x82159458
	goto loc_82159458;
loc_82159454:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159458:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x82159460;
	sub_8213D890(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213e4d8
	ctx.lr = 0x82159468;
	sub_8213E4D8(ctx, base);
loc_82159468:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82159470"))) PPC_WEAK_FUNC(sub_82159470);
PPC_FUNC_IMPL(__imp__sub_82159470) {
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
	// lbz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821594f4
	if (cr6.eq) goto loc_821594F4;
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
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821594f4
	if (cr6.eq) goto loc_821594F4;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x821594cc
	if (cr6.eq) goto loc_821594CC;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x821594d0
	goto loc_821594D0;
loc_821594CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_821594D0:
	// bl 0x8213e040
	ctx.lr = 0x821594D4;
	sub_8213E040(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
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
loc_821594F4:
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

__attribute__((alias("__imp__sub_82159508"))) PPC_WEAK_FUNC(sub_82159508);
PPC_FUNC_IMPL(__imp__sub_82159508) {
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
	ctx.lr = 0x82159510;
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
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x821595e0
	if (cr6.eq) goto loc_821595E0;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x821595e0
	if (cr6.eq) goto loc_821595E0;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82159574
	if (cr6.eq) goto loc_82159574;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82159578
	goto loc_82159578;
loc_82159574:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159578:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82159580;
	sub_8213B7B0(ctx, base);
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x821595c8
	if (cr6.eq) goto loc_821595C8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x8213da88
	ctx.lr = 0x821595C0;
	sub_8213DA88(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821595C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213da88
	ctx.lr = 0x821595D8;
	sub_8213DA88(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_821595E0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821595EC"))) PPC_WEAK_FUNC(sub_821595EC);
PPC_FUNC_IMPL(__imp__sub_821595EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821595F0"))) PPC_WEAK_FUNC(sub_821595F0);
PPC_FUNC_IMPL(__imp__sub_821595F0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82159470
	sub_82159470(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821595F4"))) PPC_WEAK_FUNC(sub_821595F4);
PPC_FUNC_IMPL(__imp__sub_821595F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821595F8"))) PPC_WEAK_FUNC(sub_821595F8);
PPC_FUNC_IMPL(__imp__sub_821595F8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82159508
	sub_82159508(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_821595FC"))) PPC_WEAK_FUNC(sub_821595FC);
PPC_FUNC_IMPL(__imp__sub_821595FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159600"))) PPC_WEAK_FUNC(sub_82159600);
PPC_FUNC_IMPL(__imp__sub_82159600) {
	PPC_FUNC_PROLOGUE();
	// b 0x821593b0
	sub_821593B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82159604"))) PPC_WEAK_FUNC(sub_82159604);
PPC_FUNC_IMPL(__imp__sub_82159604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159608"))) PPC_WEAK_FUNC(sub_82159608);
PPC_FUNC_IMPL(__imp__sub_82159608) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159660
	if (cr6.eq) goto loc_82159660;
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
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159660
	if (cr6.eq) goto loc_82159660;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159658
	if (cr6.eq) goto loc_82159658;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215965c
	goto loc_8215965C;
loc_82159658:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215965C:
	// b 0x8213c758
	sub_8213C758(ctx, base);
	return;
loc_82159660:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r3,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82159674"))) PPC_WEAK_FUNC(sub_82159674);
PPC_FUNC_IMPL(__imp__sub_82159674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159678"))) PPC_WEAK_FUNC(sub_82159678);
PPC_FUNC_IMPL(__imp__sub_82159678) {
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
	// bl 0x82159268
	ctx.lr = 0x82159698;
	sub_82159268(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821596c0
	if (cr6.eq) goto loc_821596C0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x821596c0
	if (cr6.eq) goto loc_821596C0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x821596C0;
	sub_8213F7A8(ctx, base);
loc_821596C0:
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

__attribute__((alias("__imp__sub_821596DC"))) PPC_WEAK_FUNC(sub_821596DC);
PPC_FUNC_IMPL(__imp__sub_821596DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_821596E0"))) PPC_WEAK_FUNC(sub_821596E0);
PPC_FUNC_IMPL(__imp__sub_821596E0) {
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
	// bl 0x8213b968
	ctx.lr = 0x821596F8;
	sub_8213B968(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,25424
	ctx.r9.s64 = ctx.r10.s64 + 25424;
	// stb r11,164(r31)
	PPC_STORE_U8(r31.u32 + 164, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,165(r31)
	PPC_STORE_U8(r31.u32 + 165, r11.u8);
	// stb r11,166(r31)
	PPC_STORE_U8(r31.u32 + 166, r11.u8);
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

__attribute__((alias("__imp__sub_8215972C"))) PPC_WEAK_FUNC(sub_8215972C);
PPC_FUNC_IMPL(__imp__sub_8215972C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159730"))) PPC_WEAK_FUNC(sub_82159730);
PPC_FUNC_IMPL(__imp__sub_82159730) {
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
	ctx.lr = 0x82159738;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r10,r11,25424
	ctx.r10.s64 = r11.s64 + 25424;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r30,72
	r28.s64 = r30.s64 + 72;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
loc_8215975C:
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215979c
	if (cr6.eq) goto loc_8215979C;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// mullw r10,r8,r9
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215979c
	if (cr6.eq) goto loc_8215979C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x8215979C;
	sub_8214E5B8(ctx, base);
loc_8215979C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// blt cr6,0x8215975c
	if (cr6.lt) goto loc_8215975C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213ba48
	ctx.lr = 0x821597B0;
	sub_8213BA48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_821597B8"))) PPC_WEAK_FUNC(sub_821597B8);
PPC_FUNC_IMPL(__imp__sub_821597B8) {
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
	ctx.lr = 0x821597C0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x821597D4;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x821597ec
	if (!cr6.eq) goto loc_821597EC;
loc_821597E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_821597EC:
	// lbz r11,58(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 58);
	// lwz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lwz r28,148(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// rlwinm r9,r9,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stb r9,58(r31)
	PPC_STORE_U8(r31.u32 + 58, ctx.r9.u8);
	// beq cr6,0x82159814
	if (cr6.eq) goto loc_82159814;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r11.u32);
loc_82159814:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82159824:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82159824
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82159824;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r29,608
	ctx.r3.s64 = r29.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x82159858;
	sub_82144720(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r11,7216
	r11.s64 = r11.s64 + 7216;
	// beq cr6,0x82159894
	if (cr6.eq) goto loc_82159894;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,196(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// twllei r9,0
	// lwz r7,11440(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// subf r6,r7,r3
	ctx.r6.s64 = ctx.r3.s64 - ctx.r7.s64;
	// divwu r5,r6,r9
	ctx.r5.u32 = ctx.r6.u32 / ctx.r9.u32;
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// b 0x82159898
	goto loc_82159898;
loc_82159894:
	// li r10,255
	ctx.r10.s64 = 255;
loc_82159898:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stb r10,72(r31)
	PPC_STORE_U8(r31.u32 + 72, ctx.r10.u8);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x821597e0
	if (cr6.eq) goto loc_821597E0;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x821597e0
	if (cr6.eq) goto loc_821597E0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,25480
	ctx.r3.s64 = r11.s64 + 25480;
	// bl 0x821c9790
	ctx.lr = 0x821598E4;
	sub_821C9790(ctx, base);
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82159954
	if (cr6.eq) goto loc_82159954;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82159904:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82159904
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82159904;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r29,608
	ctx.r3.s64 = r29.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x82159930;
	sub_82144720(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b910
	ctx.lr = 0x82159940;
	sub_8213B910(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,25472
	ctx.r3.s64 = r11.s64 + 25472;
	// bl 0x821c9790
	ctx.lr = 0x82159950;
	sub_821C9790(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
loc_82159954:
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x821599bc
	if (cr6.eq) goto loc_821599BC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82159970:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82159970
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82159970;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// lwz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r29,608
	ctx.r3.s64 = r29.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8215999C;
	sub_82144720(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b910
	ctx.lr = 0x821599AC;
	sub_8213B910(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,25460
	ctx.r3.s64 = r11.s64 + 25460;
	// bl 0x821c9790
	ctx.lr = 0x821599BC;
	sub_821C9790(ctx, base);
loc_821599BC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_821599C8"))) PPC_WEAK_FUNC(sub_821599C8);
PPC_FUNC_IMPL(__imp__sub_821599C8) {
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
	ctx.lr = 0x821599D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// lbz r11,72(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82159a20
	if (cr6.eq) goto loc_82159A20;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82159a2c
	if (!cr6.eq) goto loc_82159A2C;
loc_82159A20:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82159A2C:
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82159a44
	if (cr6.eq) goto loc_82159A44;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82159a48
	goto loc_82159A48;
loc_82159A44:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159A48:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82159A50;
	sub_8213B7B0(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// subfic r27,r30,-72
	xer.ca = r30.u32 <= 4294967224;
	r27.s64 = -72 - r30.s64;
loc_82159A58:
	// lbz r11,0(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82159ad0
	if (cr6.eq) goto loc_82159AD0;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// lwz r8,196(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mullw r9,r8,r11
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82159ad0
	if (cr6.eq) goto loc_82159AD0;
	// lbz r9,57(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r9,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x1;
	// beq cr6,0x82159aac
	if (cr6.eq) goto loc_82159AAC;
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82159ab0
	goto loc_82159AB0;
loc_82159AAC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159AB0:
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x8213da88
	ctx.lr = 0x82159ABC;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82159a20
	if (cr6.eq) goto loc_82159A20;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82159ad0
	if (!cr6.eq) goto loc_82159AD0;
	// li r28,0
	r28.s64 = 0;
loc_82159AD0:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r27,r29
	r11.u64 = r27.u64 + r29.u64;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// blt cr6,0x82159a58
	if (cr6.lt) goto loc_82159A58;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82159AF8"))) PPC_WEAK_FUNC(sub_82159AF8);
PPC_FUNC_IMPL(__imp__sub_82159AF8) {
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
	ctx.lr = 0x82159B00;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r11,72(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82159bb4
	if (cr6.eq) goto loc_82159BB4;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,64(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// mulli r8,r9,11488
	ctx.r8.s64 = ctx.r9.s64 * 11488;
	// lwz r9,232(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r9,11440(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159bb4
	if (cr6.eq) goto loc_82159BB4;
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x82159b60
	if (cr6.eq) goto loc_82159B60;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x82159b64
	goto loc_82159B64;
loc_82159B60:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159B64:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x82159B6C;
	sub_8213B7B0(ctx, base);
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82159ba8
	if (cr6.eq) goto loc_82159BA8;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
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
	// bl 0x8213d890
	ctx.lr = 0x82159BA0;
	sub_8213D890(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82159BA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x82159BB4;
	sub_8213D890(ctx, base);
loc_82159BB4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82159BBC"))) PPC_WEAK_FUNC(sub_82159BBC);
PPC_FUNC_IMPL(__imp__sub_82159BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159BC0"))) PPC_WEAK_FUNC(sub_82159BC0);
PPC_FUNC_IMPL(__imp__sub_82159BC0) {
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
	ctx.lr = 0x82159BC8;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,1
	r29.s64 = 1;
	// li r25,0
	r25.s64 = 0;
	// lbz r10,57(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// li r27,0
	r27.s64 = 0;
	// li r26,0
	r26.s64 = 0;
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82159c68
	if (cr6.eq) goto loc_82159C68;
	// lbz r11,164(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 164);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82159c68
	if (!cr6.eq) goto loc_82159C68;
	// lbz r9,73(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// stb r29,164(r30)
	PPC_STORE_U8(r30.u32 + 164, r29.u8);
	// stb r29,165(r30)
	PPC_STORE_U8(r30.u32 + 165, r29.u8);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159c68
	if (cr6.eq) goto loc_82159C68;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r11,11488
	ctx.r10.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159c6c
	if (cr6.eq) goto loc_82159C6C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159c5c
	if (cr6.eq) goto loc_82159C5C;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82159c60
	goto loc_82159C60;
loc_82159C5C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159C60:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x82159C68;
	sub_8213D890(ctx, base);
loc_82159C68:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82159C6C:
	// lbz r9,72(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159d4c
	if (cr6.eq) goto loc_82159D4C;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159d4c
	if (cr6.eq) goto loc_82159D4C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159cb0
	if (cr6.eq) goto loc_82159CB0;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82159cb4
	goto loc_82159CB4;
loc_82159CB0:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82159CB4:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82159d4c
	if (!cr6.eq) goto loc_82159D4C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159cd4
	if (cr6.eq) goto loc_82159CD4;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82159cd8
	goto loc_82159CD8;
loc_82159CD4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159CD8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213e040
	ctx.lr = 0x82159CE0;
	sub_8213E040(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82159d48
	if (!cr6.eq) goto loc_82159D48;
	// lbz r9,74(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 74);
	// stb r29,166(r30)
	PPC_STORE_U8(r30.u32 + 166, r29.u8);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159d48
	if (cr6.eq) goto loc_82159D48;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r11,11488
	ctx.r10.s64 = r11.s64 * 11488;
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159d4c
	if (cr6.eq) goto loc_82159D4C;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159d3c
	if (cr6.eq) goto loc_82159D3C;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82159d40
	goto loc_82159D40;
loc_82159D3C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159D40:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213d890
	ctx.lr = 0x82159D48;
	sub_8213D890(ctx, base);
loc_82159D48:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82159D4C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,73(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// lfs f31,25488(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 25488);
	f31.f64 = double(temp.f32);
	// beq cr6,0x82159e18
	if (cr6.eq) goto loc_82159E18;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159e18
	if (cr6.eq) goto loc_82159E18;
	// lbz r8,165(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 165);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159e18
	if (cr6.eq) goto loc_82159E18;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159da4
	if (cr6.eq) goto loc_82159DA4;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82159da8
	goto loc_82159DA8;
loc_82159DA4:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82159DA8:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82159e18
	if (!cr6.eq) goto loc_82159E18;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159dc8
	if (cr6.eq) goto loc_82159DC8;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82159dcc
	goto loc_82159DCC;
loc_82159DC8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159DCC:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213b768
	ctx.lr = 0x82159DD4;
	sub_8213B768(ctx, base);
	// lbz r8,73(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82159e04
	if (cr6.eq) goto loc_82159E04;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x82159e08
	goto loc_82159E08;
loc_82159E04:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159E08:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213e040
	ctx.lr = 0x82159E10;
	sub_8213E040(ctx, base);
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_82159E18:
	// lbz r9,74(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 74);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159ed8
	if (cr6.eq) goto loc_82159ED8;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r7,232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159ed8
	if (cr6.eq) goto loc_82159ED8;
	// lbz r8,166(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 166);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82159ed8
	if (cr6.eq) goto loc_82159ED8;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159e68
	if (cr6.eq) goto loc_82159E68;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x82159e6c
	goto loc_82159E6C;
loc_82159E68:
	// li r8,0
	ctx.r8.s64 = 0;
loc_82159E6C:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x82159ed8
	if (!cr6.eq) goto loc_82159ED8;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x82159e8c
	if (cr6.eq) goto loc_82159E8C;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x82159e90
	goto loc_82159E90;
loc_82159E8C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159E90:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213b768
	ctx.lr = 0x82159E98;
	sub_8213B768(ctx, base);
	// lbz r8,74(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 74);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82159ec8
	if (cr6.eq) goto loc_82159EC8;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x82159ecc
	goto loc_82159ECC;
loc_82159EC8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159ECC:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213e040
	ctx.lr = 0x82159ED4;
	sub_8213E040(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_82159ED8:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82159f14
	if (!cr6.eq) goto loc_82159F14;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82159f14
	if (!cr6.eq) goto loc_82159F14;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82159f14
	if (!cr6.eq) goto loc_82159F14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213b5c0
	ctx.lr = 0x82159F04;
	sub_8213B5C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82159F14:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82159F24"))) PPC_WEAK_FUNC(sub_82159F24);
PPC_FUNC_IMPL(__imp__sub_82159F24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159F28"))) PPC_WEAK_FUNC(sub_82159F28);
PPC_FUNC_IMPL(__imp__sub_82159F28) {
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
	ctx.lr = 0x82159F30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// addi r29,r30,72
	r29.s64 = r30.s64 + 72;
	// li r28,3
	r28.s64 = 3;
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82159F4C:
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82159f9c
	if (cr6.eq) goto loc_82159F9C;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mullw r9,r7,r10
	ctx.r9.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// lwz r8,232(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// mulli r11,r11,11488
	r11.s64 = r11.s64 * 11488;
	// add r8,r11,r8
	ctx.r8.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,11440(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11440);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82159f9c
	if (cr6.eq) goto loc_82159F9C;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x82159f90
	if (cr6.eq) goto loc_82159F90;
	// mullw r10,r7,r10
	ctx.r10.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82159f94
	goto loc_82159F94;
loc_82159F90:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82159F94:
	// bl 0x8213b5c0
	ctx.lr = 0x82159F98;
	sub_8213B5C0(ctx, base);
	// lwz r7,196(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 196);
loc_82159F9C:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// bne 0x82159f4c
	if (!cr0.eq) goto loc_82159F4C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82159FB0"))) PPC_WEAK_FUNC(sub_82159FB0);
PPC_FUNC_IMPL(__imp__sub_82159FB0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82159bc0
	sub_82159BC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82159FB4"))) PPC_WEAK_FUNC(sub_82159FB4);
PPC_FUNC_IMPL(__imp__sub_82159FB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159FB8"))) PPC_WEAK_FUNC(sub_82159FB8);
PPC_FUNC_IMPL(__imp__sub_82159FB8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82159f28
	sub_82159F28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82159FBC"))) PPC_WEAK_FUNC(sub_82159FBC);
PPC_FUNC_IMPL(__imp__sub_82159FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159FC0"))) PPC_WEAK_FUNC(sub_82159FC0);
PPC_FUNC_IMPL(__imp__sub_82159FC0) {
	PPC_FUNC_PROLOGUE();
	// b 0x821599c8
	sub_821599C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82159FC4"))) PPC_WEAK_FUNC(sub_82159FC4);
PPC_FUNC_IMPL(__imp__sub_82159FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159FC8"))) PPC_WEAK_FUNC(sub_82159FC8);
PPC_FUNC_IMPL(__imp__sub_82159FC8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82159af8
	sub_82159AF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82159FCC"))) PPC_WEAK_FUNC(sub_82159FCC);
PPC_FUNC_IMPL(__imp__sub_82159FCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82159FD0"))) PPC_WEAK_FUNC(sub_82159FD0);
PPC_FUNC_IMPL(__imp__sub_82159FD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r9,72(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215a028
	if (cr6.eq) goto loc_8215A028;
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
	// lwz r11,196(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// add r6,r8,r10
	ctx.r6.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r11,r9
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// lwz r10,11440(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8215a028
	if (cr6.eq) goto loc_8215A028;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215a020
	if (cr6.eq) goto loc_8215A020;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215a024
	goto loc_8215A024;
loc_8215A020:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215A024:
	// b 0x8213c758
	sub_8213C758(ctx, base);
	return;
loc_8215A028:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215A030"))) PPC_WEAK_FUNC(sub_8215A030);
PPC_FUNC_IMPL(__imp__sub_8215A030) {
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
	// bl 0x82159730
	ctx.lr = 0x8215A050;
	sub_82159730(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215a078
	if (cr6.eq) goto loc_8215A078;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215a078
	if (cr6.eq) goto loc_8215A078;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x8215A078;
	sub_8213F7A8(ctx, base);
loc_8215A078:
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

__attribute__((alias("__imp__sub_8215A094"))) PPC_WEAK_FUNC(sub_8215A094);
PPC_FUNC_IMPL(__imp__sub_8215A094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215A098"))) PPC_WEAK_FUNC(sub_8215A098);
PPC_FUNC_IMPL(__imp__sub_8215A098) {
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
	// bl 0x8213b968
	ctx.lr = 0x8215A0B0;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,25824
	ctx.r9.s64 = r11.s64 + 25824;
	// li r8,255
	ctx.r8.s64 = 255;
	// stw r10,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r8,168(r31)
	PPC_STORE_U8(r31.u32 + 168, ctx.r8.u8);
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

__attribute__((alias("__imp__sub_8215A0E4"))) PPC_WEAK_FUNC(sub_8215A0E4);
PPC_FUNC_IMPL(__imp__sub_8215A0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215A0E8"))) PPC_WEAK_FUNC(sub_8215A0E8);
PPC_FUNC_IMPL(__imp__sub_8215A0E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,26716(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 26716);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// b 0x82144a78
	sub_82144A78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215A104"))) PPC_WEAK_FUNC(sub_8215A104);
PPC_FUNC_IMPL(__imp__sub_8215A104) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215A108"))) PPC_WEAK_FUNC(sub_8215A108);
PPC_FUNC_IMPL(__imp__sub_8215A108) {
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
	ctx.lr = 0x8215A110;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32125
	r29.s64 = -2105344000;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// lwz r5,26736(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 26736);
	// lwz r4,26732(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 26732);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x823da950
	ctx.lr = 0x8215A140;
	sub_823DA950(ctx, base);
	// lwz r11,26736(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 26736);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// add r3,r11,r27
	ctx.r3.u64 = r11.u64 + r27.u64;
	// bl 0x823da950
	ctx.lr = 0x8215A154;
	sub_823DA950(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215a1d0
	if (cr6.eq) goto loc_8215A1D0;
	// addi r6,r30,8
	ctx.r6.s64 = r30.s64 + 8;
loc_8215A160:
	// lhz r11,0(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215a1c4
	if (cr6.eq) goto loc_8215A1C4;
	// li r9,0
	ctx.r9.s64 = 0;
loc_8215A174:
	// lwz r7,-8(r6)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8);
	// lwz r10,26732(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 26732);
	// lwz r8,26736(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 26736);
	// lwzx r11,r7,r9
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8215a1a0
	if (cr6.lt) goto loc_8215A1A0;
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bge cr6,0x8215a1a0
	if (!cr6.lt) goto loc_8215A1A0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// b 0x8215a1a8
	goto loc_8215A1A8;
loc_8215A1A0:
	// subf r11,r26,r11
	r11.s64 = r11.s64 - r26.s64;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
loc_8215A1A8:
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// stwx r11,r7,r9
	PPC_STORE_U32(ctx.r7.u32 + ctx.r9.u32, r11.u32);
	// addi r9,r9,14
	ctx.r9.s64 = ctx.r9.s64 + 14;
	// lhz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// cmplw cr6,r5,r10
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, xer);
	// blt cr6,0x8215a174
	if (cr6.lt) goto loc_8215A174;
loc_8215A1C4:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r6,r6,10
	ctx.r6.s64 = ctx.r6.s64 + 10;
	// bne 0x8215a160
	if (!cr0.eq) goto loc_8215A160;
loc_8215A1D0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8215A1D8"))) PPC_WEAK_FUNC(sub_8215A1D8);
PPC_FUNC_IMPL(__imp__sub_8215A1D8) {
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
	ctx.lr = 0x8215A1E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32125
	r26.s64 = -2105344000;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r5,26744(r26)
	ctx.r5.u64 = PPC_LOAD_U32(r26.u32 + 26744);
	// lwz r4,26740(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 26740);
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x823da950
	ctx.lr = 0x8215A210;
	sub_823DA950(ctx, base);
	// lwz r11,26744(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 26744);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x823da950
	ctx.lr = 0x8215A224;
	sub_823DA950(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215a2ac
	if (cr6.eq) goto loc_8215A2AC;
	// addi r6,r30,8
	ctx.r6.s64 = r30.s64 + 8;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
loc_8215A234:
	// lhz r11,0(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215a2a0
	if (cr6.eq) goto loc_8215A2A0;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8215A248:
	// lwz r11,-8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8);
	// lwz r10,26740(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 26740);
	// add r7,r11,r8
	ctx.r7.u64 = r11.u64 + ctx.r8.u64;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// blt cr6,0x8215a278
	if (cr6.lt) goto loc_8215A278;
	// lwz r9,26744(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 26744);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bge cr6,0x8215a278
	if (!cr6.lt) goto loc_8215A278;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// b 0x8215a284
	goto loc_8215A284;
loc_8215A278:
	// lwz r10,26736(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 26736);
	// subf r11,r27,r11
	r11.s64 = r11.s64 - r27.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
loc_8215A284:
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// addi r8,r8,14
	ctx.r8.s64 = ctx.r8.s64 + 14;
	// lhz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r6.u32 + 0);
	// cmplw cr6,r5,r10
	cr6.compare<uint32_t>(ctx.r5.u32, ctx.r10.u32, xer);
	// blt cr6,0x8215a248
	if (cr6.lt) goto loc_8215A248;
loc_8215A2A0:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r6,r6,10
	ctx.r6.s64 = ctx.r6.s64 + 10;
	// bne 0x8215a234
	if (!cr0.eq) goto loc_8215A234;
loc_8215A2AC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8215A2B4"))) PPC_WEAK_FUNC(sub_8215A2B4);
PPC_FUNC_IMPL(__imp__sub_8215A2B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215A2B8"))) PPC_WEAK_FUNC(sub_8215A2B8);
PPC_FUNC_IMPL(__imp__sub_8215A2B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
loc_8215A2D0:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r10,r4
	ctx.r5.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lwz r10,4(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// ble cr6,0x8215a300
	if (!cr6.gt) goto loc_8215A300;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x8215a308
	goto loc_8215A308;
loc_8215A300:
	// bge cr6,0x8215a314
	if (!cr6.lt) goto loc_8215A314;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_8215A308:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x8215a2d0
	if (!cr6.gt) goto loc_8215A2D0;
	// blr 
	return;
loc_8215A314:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,1,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r11,r4
	ctx.r3.u64 = r11.u64 + ctx.r4.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215A328"))) PPC_WEAK_FUNC(sub_8215A328);
PPC_FUNC_IMPL(__imp__sub_8215A328) {
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
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r8,r9,25824
	ctx.r8.s64 = ctx.r9.s64 + 25824;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// rlwinm r7,r10,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8215a3a0
	if (!cr6.eq) goto loc_8215A3A0;
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215a3a0
	if (cr6.eq) goto loc_8215A3A0;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215a3a0
	if (cr6.eq) goto loc_8215A3A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x8215A3A0;
	sub_8214E5B8(ctx, base);
loc_8215A3A0:
	// lbz r5,168(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 168);
	// cmplwi cr6,r5,255
	cr6.compare<uint32_t>(ctx.r5.u32, 255, xer);
	// beq cr6,0x8215a3c0
	if (cr6.eq) goto loc_8215A3C0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// bl 0x8213ec58
	ctx.lr = 0x8215A3B8;
	sub_8213EC58(ctx, base);
	// li r11,255
	r11.s64 = 255;
	// stb r11,168(r31)
	PPC_STORE_U8(r31.u32 + 168, r11.u8);
loc_8215A3C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x8215A3C8;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_8215A3E0"))) PPC_WEAK_FUNC(sub_8215A3E0);
PPC_FUNC_IMPL(__imp__sub_8215A3E0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8215A3E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lis r23,-32125
	r23.s64 = -2105344000;
	// lis r21,-32125
	r21.s64 = -2105344000;
loc_8215A414:
	// lwz r30,26728(r23)
	r30.u64 = PPC_LOAD_U32(r23.u32 + 26728);
loc_8215A418:
	// lwz r11,26724(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 26724);
	// cmplw cr6,r24,r11
	cr6.compare<uint32_t>(r24.u32, r11.u32, xer);
	// blt cr6,0x8215a42c
	if (cr6.lt) goto loc_8215A42C;
	// cmplw cr6,r25,r22
	cr6.compare<uint32_t>(r25.u32, r22.u32, xer);
	// bge cr6,0x8215a4b0
	if (!cr6.lt) goto loc_8215A4B0;
loc_8215A42C:
	// cmplw cr6,r25,r22
	cr6.compare<uint32_t>(r25.u32, r22.u32, xer);
	// beq cr6,0x8215a458
	if (cr6.eq) goto loc_8215A458;
	// add r11,r28,r30
	r11.u64 = r28.u64 + r30.u64;
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// ble cr6,0x8215a458
	if (!cr6.gt) goto loc_8215A458;
	// mr r31,r26
	r31.u64 = r26.u64;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r26,r26,10
	r26.s64 = r26.s64 + 10;
	// b 0x8215a464
	goto loc_8215A464;
loc_8215A458:
	// add r31,r28,r30
	r31.u64 = r28.u64 + r30.u64;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r28,r28,10
	r28.s64 = r28.s64 + 10;
loc_8215A464:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8215a480
	if (cr6.eq) goto loc_8215A480;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8215a2b8
	ctx.lr = 0x8215A478;
	sub_8215A2B8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8215a418
	if (!cr6.eq) goto loc_8215A418;
loc_8215A480:
	// mr r11,r31
	r11.u64 = r31.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8215A490:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8215a490
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8215A490;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// addi r29,r29,10
	r29.s64 = r29.s64 + 10;
	// b 0x8215a414
	goto loc_8215A414;
loc_8215A4B0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8215A4BC"))) PPC_WEAK_FUNC(sub_8215A4BC);
PPC_FUNC_IMPL(__imp__sub_8215A4BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215A4C0"))) PPC_WEAK_FUNC(sub_8215A4C0);
PPC_FUNC_IMPL(__imp__sub_8215A4C0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c8
	ctx.lr = 0x8215A4C8;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r20,r6
	r20.u64 = ctx.r6.u64;
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// li r16,0
	r16.s64 = 0;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8215a56c
	if (cr6.eq) goto loc_8215A56C;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r17,r4
	r17.u64 = ctx.r4.u64;
	// lis r18,-32125
	r18.s64 = -2105344000;
	// lis r19,-32125
	r19.s64 = -2105344000;
loc_8215A4F4:
	// lwz r30,4(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lwz r5,26724(r19)
	ctx.r5.u64 = PPC_LOAD_U32(r19.u32 + 26724);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,26728(r18)
	ctx.r4.u64 = PPC_LOAD_U32(r18.u32 + 26728);
	// bl 0x8215a2b8
	ctx.lr = 0x8215A508;
	sub_8215A2B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8215a2b8
	ctx.lr = 0x8215A51C;
	sub_8215A2B8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r22,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r22.u32);
	// li r23,0
	r23.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8215a578
	if (!cr6.eq) goto loc_8215A578;
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mulli r5,r11,14
	ctx.r5.s64 = r11.s64 * 14;
	// bl 0x823da950
	ctx.lr = 0x8215A54C;
	sub_823DA950(ctx, base);
	// lhz r29,8(r28)
	r29.u64 = PPC_LOAD_U16(r28.u32 + 8);
loc_8215A550:
	// mulli r11,r29,14
	r11.s64 = r29.s64 * 14;
	// sth r29,8(r27)
	PPC_STORE_U16(r27.u32 + 8, r29.u16);
	// addic. r17,r17,-1
	xer.ca = r17.u32 > 0;
	r17.s64 = r17.s64 + -1;
	cr0.compare<int32_t>(r17.s32, 0, xer);
	// add r22,r11,r22
	r22.u64 = r11.u64 + r22.u64;
	// add r16,r29,r16
	r16.u64 = r29.u64 + r16.u64;
	// addi r27,r27,10
	r27.s64 = r27.s64 + 10;
	// bne 0x8215a4f4
	if (!cr0.eq) goto loc_8215A4F4;
loc_8215A56C:
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9218
	return;
loc_8215A578:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// bne cr6,0x8215a59c
	if (!cr6.eq) goto loc_8215A59C;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mulli r5,r11,14
	ctx.r5.s64 = r11.s64 * 14;
	// bl 0x823da950
	ctx.lr = 0x8215A594;
	sub_823DA950(ctx, base);
	// lhz r29,8(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// b 0x8215a550
	goto loc_8215A550;
loc_8215A59C:
	// li r25,0
	r25.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// li r26,0
	r26.s64 = 0;
loc_8215A5A8:
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplw cr6,r23,r11
	cr6.compare<uint32_t>(r23.u32, r11.u32, xer);
	// blt cr6,0x8215a5c0
	if (cr6.lt) goto loc_8215A5C0;
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// cmplw cr6,r24,r11
	cr6.compare<uint32_t>(r24.u32, r11.u32, xer);
	// bge cr6,0x8215a550
	if (!cr6.lt) goto loc_8215A550;
loc_8215A5C0:
	// lhz r11,8(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 8);
	// cmplw cr6,r24,r11
	cr6.compare<uint32_t>(r24.u32, r11.u32, xer);
	// beq cr6,0x8215a5f8
	if (cr6.eq) goto loc_8215A5F8;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + r30.u64;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// ble cr6,0x8215a5f8
	if (!cr6.gt) goto loc_8215A5F8;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r26,r26,14
	r26.s64 = r26.s64 + 14;
	// b 0x8215a608
	goto loc_8215A608;
loc_8215A5F8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r30,r30,14
	r30.s64 = r30.s64 + 14;
loc_8215A608:
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r5,14
	ctx.r5.s64 = 14;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// add r3,r10,r25
	ctx.r3.u64 = ctx.r10.u64 + r25.u64;
	// bl 0x823da950
	ctx.lr = 0x8215A61C;
	sub_823DA950(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r25,r25,14
	r25.s64 = r25.s64 + 14;
	// b 0x8215a5a8
	goto loc_8215A5A8;
}

__attribute__((alias("__imp__sub_8215A628"))) PPC_WEAK_FUNC(sub_8215A628);
PPC_FUNC_IMPL(__imp__sub_8215A628) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
loc_8215A644:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r11.s64 = temp.s64;
	// mulli r10,r11,14
	ctx.r10.s64 = r11.s64 * 14;
	// add r6,r10,r7
	ctx.r6.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,8(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x8215a66c
	if (!cr6.gt) goto loc_8215A66C;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x8215a674
	goto loc_8215A674;
loc_8215A66C:
	// bge cr6,0x8215a680
	if (!cr6.lt) goto loc_8215A680;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_8215A674:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x8215a644
	if (!cr6.gt) goto loc_8215A644;
	// blr 
	return;
loc_8215A680:
	// mulli r11,r11,14
	r11.s64 = r11.s64 * 14;
	// add. r3,r11,r7
	ctx.r3.u64 = r11.u64 + ctx.r7.u64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beqlr 
	if (cr0.eq) return;
loc_8215A68C:
	// addi r11,r3,-14
	r11.s64 = ctx.r3.s64 + -14;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x8215a68c
	goto loc_8215A68C;
}

__attribute__((alias("__imp__sub_8215A6B0"))) PPC_WEAK_FUNC(sub_8215A6B0);
PPC_FUNC_IMPL(__imp__sub_8215A6B0) {
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
	ctx.lr = 0x8215A6B8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 64);
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lbz r8,168(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 168);
	// addi r7,r11,7216
	ctx.r7.s64 = r11.s64 + 7216;
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r11,232(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 232);
	// lwz r10,200(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 200);
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// add r6,r9,r11
	ctx.r6.u64 = ctx.r9.u64 + r11.u64;
	// mullw r11,r8,r10
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// add. r28,r10,r11
	r28.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// beq 0x8215a850
	if (cr0.eq) goto loc_8215A850;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// bne cr6,0x8215a720
	if (!cr6.eq) goto loc_8215A720;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r11,25976
	ctx.r3.s64 = r11.s64 + 25976;
	// bl 0x82130000
	ctx.lr = 0x8215A714;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
loc_8215A720:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,26724(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 26724);
	// lwz r4,26728(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26728);
	// bl 0x8215a2b8
	ctx.lr = 0x8215A738;
	sub_8215A2B8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8215a81c
	if (cr6.eq) goto loc_8215A81C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9790
	ctx.lr = 0x8215A750;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8215a628
	ctx.lr = 0x8215A75C;
	sub_8215A628(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8215a850
	if (cr6.eq) goto loc_8215A850;
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8215A768:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215a77c
	if (cr6.eq) goto loc_8215A77C;
	// lbz r11,13(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// ble cr6,0x8215a7b8
	if (!cr6.gt) goto loc_8215A7B8;
loc_8215A77C:
	// lhz r9,8(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 8);
	// addi r11,r3,14
	r11.s64 = ctx.r3.s64 + 14;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r9,r9,14
	ctx.r9.s64 = ctx.r9.s64 * 14;
	// lbz r8,13(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 13);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r31,r8,r31
	r31.s64 = r31.s64 - ctx.r8.s64;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bge cr6,0x8215a7fc
	if (!cr6.lt) goto loc_8215A7FC;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8215a7fc
	if (!cr6.eq) goto loc_8215A7FC;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// b 0x8215a768
	goto loc_8215A768;
loc_8215A7B8:
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x821372f0
	ctx.lr = 0x8215A7C0;
	sub_821372F0(ctx, base);
	// clrlwi r11,r3,16
	r11.u64 = ctx.r3.u32 & 0xFFFF;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,4(r28)
	PPC_STORE_U32(r28.u32 + 4, r11.u32);
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r4,r10,25964
	ctx.r4.s64 = ctx.r10.s64 + 25964;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8215A7E0;
	sub_823DC018(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x8215A7EC;
	sub_821C9790(ctx, base);
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
loc_8215A7FC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r3,r11,25920
	ctx.r3.s64 = r11.s64 + 25920;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82130000
	ctx.lr = 0x8215A810;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
loc_8215A81C:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8215a840
	if (cr6.eq) goto loc_8215A840;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,25896
	ctx.r3.s64 = r11.s64 + 25896;
	// bl 0x82130000
	ctx.lr = 0x8215A834;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
loc_8215A840:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,25860
	ctx.r3.s64 = r11.s64 + 25860;
	// bl 0x82130000
	ctx.lr = 0x8215A850;
	sub_82130000(ctx, base);
loc_8215A850:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8215A85C"))) PPC_WEAK_FUNC(sub_8215A85C);
PPC_FUNC_IMPL(__imp__sub_8215A85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215A860"))) PPC_WEAK_FUNC(sub_8215A860);
PPC_FUNC_IMPL(__imp__sub_8215A860) {
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
	ctx.lr = 0x8215A868;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x8215A87C;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215a894
	if (!cr6.eq) goto loc_8215A894;
loc_8215A888:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8215A894:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// li r4,8
	ctx.r4.s64 = 8;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213eb00
	ctx.lr = 0x8215A8AC;
	sub_8213EB00(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215a888
	if (cr6.eq) goto loc_8215A888;
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r8,r10,65535
	ctx.r8.u64 = ctx.r10.u64 | 65535;
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// addi r8,r7,19856
	ctx.r8.s64 = ctx.r7.s64 + 19856;
	// lwz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lbz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mulli r7,r4,11488
	ctx.r7.s64 = ctx.r4.s64 * 11488;
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// addi r3,r8,608
	ctx.r3.s64 = ctx.r8.s64 + 608;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// twllei r9,0
	// lwz r8,11444(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// divwu r11,r7,r9
	r11.u32 = ctx.r7.u32 / ctx.r9.u32;
	// stb r11,168(r31)
	PPC_STORE_U8(r31.u32 + 168, r11.u8);
	// bl 0x82143580
	ctx.lr = 0x8215A910;
	sub_82143580(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8215a944
	if (cr6.eq) goto loc_8215A944;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x8215a948
	goto loc_8215A948;
loc_8215A944:
	// li r11,255
	r11.s64 = 255;
loc_8215A948:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215a888
	if (cr6.eq) goto loc_8215A888;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215a888
	if (cr6.eq) goto loc_8215A888;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8215A990"))) PPC_WEAK_FUNC(sub_8215A990);
PPC_FUNC_IMPL(__imp__sub_8215A990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r21{};
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
	ctx.lr = 0x8215A998;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82137488
	ctx.lr = 0x8215A9B0;
	sub_82137488(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r31,r11,7216
	r31.s64 = r11.s64 + 7216;
	// lbz r8,168(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 168);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r11,232(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 232);
	// lwz r10,200(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// mullw r9,r8,r10
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 11444);
	// add. r29,r9,r10
	r29.u64 = ctx.r9.u64 + ctx.r10.u64;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x8215abe0
	if (cr0.eq) goto loc_8215ABE0;
	// cmpwi cr6,r25,-1
	cr6.compare<int32_t>(r25.s32, -1, xer);
	// beq cr6,0x8215abe0
	if (cr6.eq) goto loc_8215ABE0;
	// lbz r9,72(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215aa0c
	if (cr6.eq) goto loc_8215AA0C;
	// lwz r10,196(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r11,11440(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 11440);
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r26,r10,r11
	r26.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8215aa10
	goto loc_8215AA10;
loc_8215AA0C:
	// li r26,0
	r26.s64 = 0;
loc_8215AA10:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8215abe0
	if (cr6.eq) goto loc_8215ABE0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8215abe0
	if (cr6.eq) goto loc_8215ABE0;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821382d0
	ctx.lr = 0x8215AA34;
	sub_821382D0(ctx, base);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215aa60
	if (cr6.eq) goto loc_8215AA60;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8215aba4
	if (cr6.eq) goto loc_8215ABA4;
	// addi r11,r28,-2
	r11.s64 = r28.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,28,30,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x2;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_8215AA60:
	// stw r25,164(r30)
	PPC_STORE_U32(r30.u32 + 164, r25.u32);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8214aa70
	ctx.lr = 0x8215AA74;
	sub_8214AA70(ctx, base);
	// cmplwi cr6,r28,3
	cr6.compare<uint32_t>(r28.u32, 3, xer);
	// bgt cr6,0x8215abe0
	if (cr6.gt) goto loc_8215ABE0;
	// lis r12,-32234
	r12.s64 = -2112487424;
	// addi r12,r12,-21868
	r12.s64 = r12.s64 + -21868;
	// rlwinm r0,r28,2,0,29
	r0.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r28.u64) {
	case 0:
		goto loc_8215AAA4;
	case 1:
		goto loc_8215ABD4;
	case 2:
		goto loc_8215ABE0;
	case 3:
		goto loc_8215ABB0;
	default:
		__builtin_unreachable();
	}
	// lwz r16,-21852(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + -21852);
	// lwz r16,-21548(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + -21548);
	// lwz r16,-21536(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + -21536);
	// lwz r16,-21584(r21)
	r16.u64 = PPC_LOAD_U32(r21.u32 + -21584);
loc_8215AAA4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821380c8
	ctx.lr = 0x8215AAB0;
	sub_821380C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8215abe0
	if (cr6.eq) goto loc_8215ABE0;
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215aae8
	if (cr6.eq) goto loc_8215AAE8;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215aaec
	goto loc_8215AAEC;
loc_8215AAE8:
	// li r11,0
	r11.s64 = 0;
loc_8215AAEC:
	// lhz r10,26(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 26);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,212
	ctx.r5.s64 = 212;
	// sth r10,216(r11)
	PPC_STORE_U16(r11.u32 + 216, ctx.r10.u16);
	// lfs f0,8884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f13,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lfs f12,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// lfs f11,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f9,f0
	ctx.f6.f64 = double(float(ctx.f9.f64 * f0.f64));
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fdivs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// fsel f4,f5,f13,f12
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fadds f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// fsubs f1,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fsubs f0,f2,f11
	f0.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// fsel f13,f1,f2,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.f12.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x8215ab94
	if (cr6.lt) goto loc_8215AB94;
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// li r3,1
	ctx.r3.s64 = 1;
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_8215AB94:
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
loc_8215ABA4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_8215ABB0:
	// lbz r11,57(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 57);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8215abe0
	if (cr6.eq) goto loc_8215ABE0;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// bl 0x821381e0
	ctx.lr = 0x8215ABD4;
	sub_821381E0(ctx, base);
loc_8215ABD4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_8215ABE0:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8215ABEC"))) PPC_WEAK_FUNC(sub_8215ABEC);
PPC_FUNC_IMPL(__imp__sub_8215ABEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215ABF0"))) PPC_WEAK_FUNC(sub_8215ABF0);
PPC_FUNC_IMPL(__imp__sub_8215ABF0) {
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
	ctx.lr = 0x8215ABF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lhz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 60);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lbz r7,168(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 168);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// extsh r3,r8
	ctx.r3.s64 = ctx.r8.s16;
	// mullw r29,r7,r11
	r29.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// lwz r28,11444(r6)
	r28.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11444);
	// bl 0x821374b0
	ctx.lr = 0x8215AC34;
	sub_821374B0(ctx, base);
	// lwzx r4,r28,r29
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + r29.u32);
	// bl 0x821380c8
	ctx.lr = 0x8215AC3C;
	sub_821380C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8215ac58
	if (!cr6.eq) goto loc_8215AC58;
	// lbz r11,57(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// ori r10,r11,128
	ctx.r10.u64 = r11.u64 | 128;
	// stb r10,57(r31)
	PPC_STORE_U8(r31.u32 + 57, ctx.r10.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8215AC58:
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215ac88
	if (cr6.eq) goto loc_8215AC88;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8215ac8c
	goto loc_8215AC8C;
loc_8215AC88:
	// li r11,0
	r11.s64 = 0;
loc_8215AC8C:
	// lhz r10,26(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 26);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,212
	ctx.r5.s64 = 212;
	// sth r10,216(r11)
	PPC_STORE_U16(r11.u32 + 216, ctx.r10.u16);
	// lfs f0,8884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lfs f13,8880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8880);
	ctx.f13.f64 = double(temp.f32);
	// lhz r10,24(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 24);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// lfs f12,8876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8876);
	ctx.f12.f64 = double(temp.f32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// lfs f11,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f6,f8,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * f0.f64));
	// frsp f7,f9
	ctx.f7.f64 = double(float(ctx.f9.f64));
	// fdivs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 / ctx.f6.f64));
	// fsel f4,f5,f13,f12
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f13.f64 : ctx.f12.f64;
	// fsubs f3,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f4.f64));
	// fadds f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 + ctx.f4.f64));
	// fsubs f1,f5,f2
	ctx.f1.f64 = double(float(ctx.f5.f64 - ctx.f2.f64));
	// fsubs f0,f2,f11
	f0.f64 = double(float(ctx.f2.f64 - ctx.f11.f64));
	// fsel f13,f1,f2,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f2.f64 : f0.f64;
	// fctidz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfiwx f12,r11,r5
	PPC_STORE_U32(r11.u32 + ctx.r5.u32, ctx.f12.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x8215ad30
	if (cr6.lt) goto loc_8215AD30;
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8215AD30:
	// lbz r10,227(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 227);
	// clrlwi r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	// rlwinm r9,r9,0,27,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stb r9,227(r11)
	PPC_STORE_U8(r11.u32 + 227, ctx.r9.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8215AD48"))) PPC_WEAK_FUNC(sub_8215AD48);
PPC_FUNC_IMPL(__imp__sub_8215AD48) {
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
	ctx.lr = 0x8215AD50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215adbc
	if (cr6.eq) goto loc_8215ADBC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215adbc
	if (cr6.eq) goto loc_8215ADBC;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b7b0
	ctx.lr = 0x8215ADA8;
	sub_8213B7B0(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213d890
	ctx.lr = 0x8215ADB4;
	sub_8213D890(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8213e4d8
	ctx.lr = 0x8215ADBC;
	sub_8213E4D8(ctx, base);
loc_8215ADBC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8215ADC4"))) PPC_WEAK_FUNC(sub_8215ADC4);
PPC_FUNC_IMPL(__imp__sub_8215ADC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215ADC8"))) PPC_WEAK_FUNC(sub_8215ADC8);
PPC_FUNC_IMPL(__imp__sub_8215ADC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r8,72(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215ae04
	if (cr6.eq) goto loc_8215AE04;
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
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8215ae0c
	if (!cr6.eq) goto loc_8215AE0C;
loc_8215AE04:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8215AE0C:
	// b 0x8213e040
	sub_8213E040(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215AE10"))) PPC_WEAK_FUNC(sub_8215AE10);
PPC_FUNC_IMPL(__imp__sub_8215AE10) {
	PPC_FUNC_PROLOGUE();
	// b 0x8215a990
	sub_8215A990(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215AE14"))) PPC_WEAK_FUNC(sub_8215AE14);
PPC_FUNC_IMPL(__imp__sub_8215AE14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215AE18"))) PPC_WEAK_FUNC(sub_8215AE18);
PPC_FUNC_IMPL(__imp__sub_8215AE18) {
	PPC_FUNC_PROLOGUE();
	// b 0x8215ad48
	sub_8215AD48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215AE1C"))) PPC_WEAK_FUNC(sub_8215AE1C);
PPC_FUNC_IMPL(__imp__sub_8215AE1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215AE20"))) PPC_WEAK_FUNC(sub_8215AE20);
PPC_FUNC_IMPL(__imp__sub_8215AE20) {
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
	// bl 0x8215a328
	ctx.lr = 0x8215AE40;
	sub_8215A328(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215ae68
	if (cr6.eq) goto loc_8215AE68;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215ae68
	if (cr6.eq) goto loc_8215AE68;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x8215AE68;
	sub_8213F7A8(ctx, base);
loc_8215AE68:
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

__attribute__((alias("__imp__sub_8215AE84"))) PPC_WEAK_FUNC(sub_8215AE84);
PPC_FUNC_IMPL(__imp__sub_8215AE84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215AE88"))) PPC_WEAK_FUNC(sub_8215AE88);
PPC_FUNC_IMPL(__imp__sub_8215AE88) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8215AE90;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r23,-32125
	r23.s64 = -2105344000;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r22,r11,19856
	r22.s64 = r11.s64 + 19856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,26720(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 26720);
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// stw r4,26720(r23)
	PPC_STORE_U32(r23.u32 + 26720, ctx.r4.u32);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// bl 0x82144a60
	ctx.lr = 0x8215AED0;
	sub_82144A60(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8215a3e0
	ctx.lr = 0x8215AEE4;
	sub_8215A3E0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// add r10,r30,r11
	ctx.r10.u64 = r30.u64 + r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r29,r11,r31
	r29.u64 = r11.u64 + r31.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// bl 0x8215a4c0
	ctx.lr = 0x8215AF10;
	sub_8215A4C0(ctx, base);
	// mulli r11,r3,14
	r11.s64 = ctx.r3.s64 * 14;
	// add r29,r11,r29
	r29.u64 = r11.u64 + r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8215a108
	ctx.lr = 0x8215AF30;
	sub_8215A108(ctx, base);
	// lis r25,-32125
	r25.s64 = -2105344000;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,26736(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 26736);
	// add r27,r11,r28
	r27.u64 = r11.u64 + r28.u64;
	// add r28,r27,r29
	r28.u64 = r27.u64 + r29.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x8215a1d8
	ctx.lr = 0x8215AF58;
	sub_8215A1D8(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r27,26736(r25)
	PPC_STORE_U32(r25.u32 + 26736, r27.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r11,26744(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26744);
	// lis r27,-32125
	r27.s64 = -2105344000;
	// stw r30,26724(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26724, r30.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// add r11,r11,r26
	r11.u64 = r11.u64 + r26.u64;
	// stw r31,26728(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26728, r31.u32);
	// stw r29,26732(r6)
	PPC_STORE_U32(ctx.r6.u32 + 26732, r29.u32);
	// subf r10,r31,r11
	ctx.r10.s64 = r11.s64 - r31.s64;
	// stw r28,26740(r5)
	PPC_STORE_U32(ctx.r5.u32 + 26740, r28.u32);
	// stw r11,26744(r9)
	PPC_STORE_U32(ctx.r9.u32 + 26744, r11.u32);
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// lwz r4,26716(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 26716);
	// stw r10,26720(r23)
	PPC_STORE_U32(r23.u32 + 26720, ctx.r10.u32);
	// bl 0x82144a78
	ctx.lr = 0x8215AFA8;
	sub_82144A78(ctx, base);
	// stw r31,26716(r27)
	PPC_STORE_U32(r27.u32 + 26716, r31.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8215AFB4"))) PPC_WEAK_FUNC(sub_8215AFB4);
PPC_FUNC_IMPL(__imp__sub_8215AFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215AFB8"))) PPC_WEAK_FUNC(sub_8215AFB8);
PPC_FUNC_IMPL(__imp__sub_8215AFB8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8215AFC0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lwz r4,26728(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 26728);
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// lwz r5,26724(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26724);
	// bl 0x8215a2b8
	ctx.lr = 0x8215AFF4;
	sub_8215A2B8(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8215b0f4
	if (cr6.eq) goto loc_8215B0F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9790
	ctx.lr = 0x8215B00C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8215a628
	ctx.lr = 0x8215B018;
	sub_8215A628(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8215b0f4
	if (cr6.eq) goto loc_8215B0F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r25,r11,26052
	r25.s64 = r11.s64 + 26052;
loc_8215B02C:
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x8215b050
	if (cr6.eq) goto loc_8215B050;
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8215b050
	if (cr6.eq) goto loc_8215B050;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r5,13(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 13);
	// add r3,r11,r23
	ctx.r3.u64 = r11.u64 + r23.u64;
	// bl 0x823da950
	ctx.lr = 0x8215B050;
	sub_823DA950(ctx, base);
loc_8215B050:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8215b0b0
	if (cr6.eq) goto loc_8215B0B0;
	// lbz r11,13(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 13);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215b0b0
	if (cr6.eq) goto loc_8215B0B0;
loc_8215B068:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dc018
	ctx.lr = 0x8215B084;
	sub_823DC018(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x8215B090;
	sub_821C9790(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r10,r26
	PPC_STORE_U32(ctx.r10.u32 + r26.u32, ctx.r3.u32);
	// lbz r9,13(r29)
	ctx.r9.u64 = PPC_LOAD_U8(r29.u32 + 13);
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// blt cr6,0x8215b068
	if (cr6.lt) goto loc_8215B068;
loc_8215B0B0:
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r29,14
	r11.s64 = r29.s64 + 14;
	// lbz r10,13(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 13);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lhz r8,8(r24)
	ctx.r8.u64 = PPC_LOAD_U16(r24.u32 + 8);
	// mulli r10,r8,14
	ctx.r10.s64 = ctx.r8.s64 * 14;
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplw cr6,r11,r7
	cr6.compare<uint32_t>(r11.u32, ctx.r7.u32, xer);
	// bge cr6,0x8215b0f4
	if (!cr6.lt) goto loc_8215B0F4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8215b0f4
	if (!cr6.eq) goto loc_8215B0F4;
	// mr r29,r11
	r29.u64 = r11.u64;
	// b 0x8215b02c
	goto loc_8215B02C;
loc_8215B0F4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r9,31
	ctx.r3.u64 = ctx.r9.u32 & 0x1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8215B10C"))) PPC_WEAK_FUNC(sub_8215B10C);
PPC_FUNC_IMPL(__imp__sub_8215B10C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215B110"))) PPC_WEAK_FUNC(sub_8215B110);
PPC_FUNC_IMPL(__imp__sub_8215B110) {
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
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r5,26724(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 26724);
	// lwz r4,26728(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 26728);
	// bl 0x8215a2b8
	ctx.lr = 0x8215B13C;
	sub_8215A2B8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215b174
	if (cr6.eq) goto loc_8215B174;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x8215B154;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8215a628
	ctx.lr = 0x8215B160;
	sub_8215A628(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8215b174
	if (cr6.eq) goto loc_8215B174;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x821372f0
	ctx.lr = 0x8215B170;
	sub_821372F0(ctx, base);
	// b 0x8215b178
	goto loc_8215B178;
loc_8215B174:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8215B178:
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

__attribute__((alias("__imp__sub_8215B190"))) PPC_WEAK_FUNC(sub_8215B190);
PPC_FUNC_IMPL(__imp__sub_8215B190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8215B198;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// bl 0x821c9790
	ctx.lr = 0x8215B1B8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// bl 0x8215a6b0
	ctx.lr = 0x8215B1D0;
	sub_8215A6B0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8215B1D8"))) PPC_WEAK_FUNC(sub_8215B1D8);
PPC_FUNC_IMPL(__imp__sub_8215B1D8) {
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
	ctx.lr = 0x8215B1E0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r26,r11,3998
	r26.s64 = r11.s64 + 3998;
	// addi r25,r10,30576
	r25.s64 = ctx.r10.s64 + 30576;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x8215B20C;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215b25c
	if (cr6.eq) goto loc_8215B25C;
	// bl 0x821bdd08
	ctx.lr = 0x8215B21C;
	sub_821BDD08(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r19,r11,19856
	r19.s64 = r11.s64 + 19856;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82144a60
	ctx.lr = 0x8215B238;
	sub_82144A60(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be250
	ctx.lr = 0x8215B24C;
	sub_821BE250(ctx, base);
	// cmpw cr6,r3,r22
	cr6.compare<int32_t>(ctx.r3.s32, r22.s32, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8215b268
	if (cr6.eq) goto loc_8215B268;
	// bl 0x821be610
	ctx.lr = 0x8215B25C;
	sub_821BE610(ctx, base);
loc_8215B25C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9220
	return;
loc_8215B268:
	// bl 0x821be610
	ctx.lr = 0x8215B26C;
	sub_821BE610(ctx, base);
	// addi r24,r28,4
	r24.s64 = r28.s64 + 4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r11,26068
	ctx.r8.s64 = r11.s64 + 26068;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r23,0(r28)
	r23.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r11,r24,r23
	r11.u64 = r24.u64 + r23.u64;
	// addi r20,r11,4
	r20.s64 = r11.s64 + 4;
	// lwzx r10,r24,r23
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + r23.u32);
	// mulli r11,r10,14
	r11.s64 = ctx.r10.s64 * 14;
	// add r11,r11,r20
	r11.u64 = r11.u64 + r20.u64;
	// addi r21,r11,4
	r21.s64 = r11.s64 + 4;
	// lwz r27,0(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r11,r27,2,0,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r27,r11
	ctx.r9.u64 = r27.u64 + r11.u64;
	// rlwinm r11,r9,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r21
	ctx.r5.u64 = r11.u64 + r21.u64;
	// addi r30,r5,4
	r30.s64 = ctx.r5.s64 + 4;
	// subf r11,r30,r28
	r11.s64 = r28.s64 - r30.s64;
	// lwz r6,0(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// add r11,r11,r22
	r11.u64 = r11.u64 + r22.u64;
	// rlwinm r10,r6,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// add r29,r10,r30
	r29.u64 = ctx.r10.u64 + r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// subf r11,r29,r28
	r11.s64 = r28.s64 - r29.s64;
	// add r18,r11,r22
	r18.u64 = r11.u64 + r22.u64;
	// bl 0x821cb740
	ctx.lr = 0x8215B2E0;
	sub_821CB740(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x821ca6a8
	ctx.lr = 0x8215B2F8;
	sub_821CA6A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r19,608
	ctx.r3.s64 = r19.s64 + 608;
	// bl 0x8214df08
	ctx.lr = 0x8215B30C;
	sub_8214DF08(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821be610
	ctx.lr = 0x8215B314;
	sub_821BE610(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8215b3a4
	if (cr6.eq) goto loc_8215B3A4;
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
loc_8215B328:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lhz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// add r8,r11,r20
	ctx.r8.u64 = r11.u64 + r20.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// beq cr6,0x8215b398
	if (cr6.eq) goto loc_8215B398;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
loc_8215B348:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r4,r8,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r4,r30
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + r30.u32);
	// add r3,r8,r29
	ctx.r3.u64 = ctx.r8.u64 + r29.u64;
	// stwx r3,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r3.u32);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// blt cr6,0x8215b380
	if (cr6.lt) goto loc_8215B380;
	// add r8,r8,r24
	ctx.r8.u64 = ctx.r8.u64 + r24.u64;
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// b 0x8215b384
	goto loc_8215B384;
loc_8215B380:
	// stw r6,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r6.u32);
loc_8215B384:
	// lhz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,14
	r11.s64 = r11.s64 + 14;
	// cmplw cr6,r7,r10
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r10.u32, xer);
	// blt cr6,0x8215b348
	if (cr6.lt) goto loc_8215B348;
loc_8215B398:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r9,r9,10
	ctx.r9.s64 = ctx.r9.s64 + 10;
	// bne 0x8215b328
	if (!cr0.eq) goto loc_8215B328;
loc_8215B3A4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,26716(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 26716);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8215b3ec
	if (cr6.eq) goto loc_8215B3EC;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// mr r8,r23
	ctx.r8.u64 = r23.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8215ae88
	ctx.lr = 0x8215B3D4;
	sub_8215AE88(ctx, base);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82144a78
	ctx.lr = 0x8215B3E0;
	sub_82144A78(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9220
	return;
loc_8215B3EC:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stw r28,26716(r11)
	PPC_STORE_U32(r11.u32 + 26716, r28.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// stw r22,26720(r10)
	PPC_STORE_U32(ctx.r10.u32 + 26720, r22.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stw r27,26724(r9)
	PPC_STORE_U32(ctx.r9.u32 + 26724, r27.u32);
	// stw r21,26728(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26728, r21.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r29,26732(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26732, r29.u32);
	// stw r18,26736(r6)
	PPC_STORE_U32(ctx.r6.u32 + 26736, r18.u32);
	// stw r24,26740(r5)
	PPC_STORE_U32(ctx.r5.u32 + 26740, r24.u32);
	// stw r23,26744(r4)
	PPC_STORE_U32(ctx.r4.u32 + 26744, r23.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8215B434"))) PPC_WEAK_FUNC(sub_8215B434);
PPC_FUNC_IMPL(__imp__sub_8215B434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215B438"))) PPC_WEAK_FUNC(sub_8215B438);
PPC_FUNC_IMPL(__imp__sub_8215B438) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8215B454;
	sub_821C9790(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8215b110
	ctx.lr = 0x8215B45C;
	sub_8215B110(ctx, base);
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

__attribute__((alias("__imp__sub_8215B470"))) PPC_WEAK_FUNC(sub_8215B470);
PPC_FUNC_IMPL(__imp__sub_8215B470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// li r11,0
	r11.s64 = 0;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// stw r11,26716(r9)
	PPC_STORE_U32(ctx.r9.u32 + 26716, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,26724(r7)
	PPC_STORE_U32(ctx.r7.u32 + 26724, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,26720(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26720, ctx.r10.u32);
	// stw r11,26728(r6)
	PPC_STORE_U32(ctx.r6.u32 + 26728, r11.u32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r6,r7,19856
	ctx.r6.s64 = ctx.r7.s64 + 19856;
	// stw r11,26740(r3)
	PPC_STORE_U32(ctx.r3.u32 + 26740, r11.u32);
	// stw r10,26732(r5)
	PPC_STORE_U32(ctx.r5.u32 + 26732, ctx.r10.u32);
	// stw r9,26736(r4)
	PPC_STORE_U32(ctx.r4.u32 + 26736, ctx.r9.u32);
	// stw r10,26744(r8)
	PPC_STORE_U32(ctx.r8.u32 + 26744, ctx.r10.u32);
	// lwz r3,1280(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 1280);
	// b 0x8215b1d8
	sub_8215B1D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215B4CC"))) PPC_WEAK_FUNC(sub_8215B4CC);
PPC_FUNC_IMPL(__imp__sub_8215B4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215B4D0"))) PPC_WEAK_FUNC(sub_8215B4D0);
PPC_FUNC_IMPL(__imp__sub_8215B4D0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8215B4EC;
	sub_821C9790(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8215afb8
	ctx.lr = 0x8215B500;
	sub_8215AFB8(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
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

__attribute__((alias("__imp__sub_8215B518"))) PPC_WEAK_FUNC(sub_8215B518);
PPC_FUNC_IMPL(__imp__sub_8215B518) {
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
	// bl 0x8213b968
	ctx.lr = 0x8215B530;
	sub_8213B968(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// addi r10,r11,26400
	ctx.r10.s64 = r11.s64 + 26400;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821627f8
	ctx.lr = 0x8215B544;
	sub_821627F8(ctx, base);
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

__attribute__((alias("__imp__sub_8215B55C"))) PPC_WEAK_FUNC(sub_8215B55C);
PPC_FUNC_IMPL(__imp__sub_8215B55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215B560"))) PPC_WEAK_FUNC(sub_8215B560);
PPC_FUNC_IMPL(__imp__sub_8215B560) {
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
	// lwz r9,168(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// lwz r11,184(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// beq cr6,0x8215b594
	if (cr6.eq) goto loc_8215B594;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fadds f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 + ctx.f1.f64));
loc_8215B594:
	// lwz r9,172(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// lwz r11,188(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 188);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f2,f13
	ctx.f2.f64 = double(float(ctx.f13.f64));
	// beq cr6,0x8215b5bc
	if (cr6.eq) goto loc_8215B5BC;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fadds f2,f0,f2
	ctx.f2.f64 = double(float(f0.f64 + ctx.f2.f64));
loc_8215B5BC:
	// bl 0x82145080
	ctx.lr = 0x8215B5C0;
	sub_82145080(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8215b5e4
	if (!cr6.gt) goto loc_8215B5E4;
	// fdivs f1,f0,f1
	ctx.f1.f64 = double(float(f0.f64 / ctx.f1.f64));
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8215B5E4:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8215B5F8"))) PPC_WEAK_FUNC(sub_8215B5F8);
PPC_FUNC_IMPL(__imp__sub_8215B5F8) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 192);
	// lwz r3,176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8215b634
	if (cr6.eq) goto loc_8215B634;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lhz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
loc_8215B634:
	// lwz r10,196(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// lwz r4,180(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8215b658
	if (cr6.eq) goto loc_8215B658;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lhz r11,86(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// add r4,r11,r4
	ctx.r4.u64 = r11.u64 + ctx.r4.u64;
loc_8215B658:
	// bl 0x82145020
	ctx.lr = 0x8215B65C;
	sub_82145020(ctx, base);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
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

__attribute__((alias("__imp__sub_8215B674"))) PPC_WEAK_FUNC(sub_8215B674);
PPC_FUNC_IMPL(__imp__sub_8215B674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215B678"))) PPC_WEAK_FUNC(sub_8215B678);
PPC_FUNC_IMPL(__imp__sub_8215B678) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x8215b560
	ctx.lr = 0x8215B698;
	sub_8215B560(ctx, base);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// bl 0x82162870
	ctx.lr = 0x8215B6A4;
	sub_82162870(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,200(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f12,200(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// bl 0x8215b5f8
	ctx.lr = 0x8215B6C4;
	sub_8215B5F8(ctx, base);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8215B6E0"))) PPC_WEAK_FUNC(sub_8215B6E0);
PPC_FUNC_IMPL(__imp__sub_8215B6E0) {
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
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r8,r9,26400
	ctx.r8.s64 = ctx.r9.s64 + 26400;
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215b748
	if (cr6.eq) goto loc_8215B748;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// lwz r8,196(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11440(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215b748
	if (cr6.eq) goto loc_8215B748;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8214e5b8
	ctx.lr = 0x8215B748;
	sub_8214E5B8(ctx, base);
loc_8215B748:
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215b788
	if (cr6.eq) goto loc_8215B788;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
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
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215b788
	if (cr6.eq) goto loc_8215B788;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8214e5b8
	ctx.lr = 0x8215B788;
	sub_8214E5B8(ctx, base);
loc_8215B788:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213ba48
	ctx.lr = 0x8215B790;
	sub_8213BA48(ctx, base);
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

__attribute__((alias("__imp__sub_8215B7A8"))) PPC_WEAK_FUNC(sub_8215B7A8);
PPC_FUNC_IMPL(__imp__sub_8215B7A8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8215B7B0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x8213e680
	ctx.lr = 0x8215B7C4;
	sub_8213E680(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215ba74
	if (cr6.eq) goto loc_8215BA74;
	// lwz r29,148(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r9,6
	ctx.r9.s64 = 6;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8215B7E4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8215b7e4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8215B7E4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,29(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 29);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// addi r28,r11,19856
	r28.s64 = r11.s64 + 19856;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r28,608
	ctx.r3.s64 = r28.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8215B818;
	sub_82144720(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// beq cr6,0x8215b854
	if (cr6.eq) goto loc_8215B854;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x8215b858
	goto loc_8215B858;
loc_8215B854:
	// li r11,255
	r11.s64 = 255;
loc_8215B858:
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r4,37(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 37);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r28,608
	ctx.r3.s64 = r28.s64 + 608;
	// bl 0x82144720
	ctx.lr = 0x8215B874;
	sub_82144720(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8215b8a8
	if (cr6.eq) goto loc_8215B8A8;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r11,232(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r10,11488
	ctx.r9.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
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
	// b 0x8215b8ac
	goto loc_8215B8AC;
loc_8215B8A8:
	// li r11,255
	r11.s64 = 255;
loc_8215B8AC:
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// clrlwi r7,r11,24
	ctx.r7.u64 = r11.u32 & 0xFF;
	// stb r7,73(r31)
	PPC_STORE_U8(r31.u32 + 73, ctx.r7.u8);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215ba74
	if (cr6.eq) goto loc_8215BA74;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r9,r11,r8
	ctx.r9.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8215ba74
	if (cr6.eq) goto loc_8215BA74;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215ba74
	if (cr6.eq) goto loc_8215BA74;
	// mullw r11,r11,r9
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r9.s32);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215ba74
	if (cr6.eq) goto loc_8215BA74;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// lwz r6,20(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// lhz r9,6(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// stw r9,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r9.u32);
	// lhz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 0);
	// stw r8,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r8.u32);
	// lhz r7,2(r29)
	ctx.r7.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// stw r7,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r7.u32);
	// lwz r4,12(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8215B93C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,16(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r11,20(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 20);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8215B958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,20(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8215B974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8215B990;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r30,r31,208
	r30.s64 = r31.s64 + 208;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f4,7444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f3.f64 = double(temp.f32);
	// fmr f2,f4
	ctx.f2.f64 = ctx.f4.f64;
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// bl 0x82162850
	ctx.lr = 0x8215B9B8;
	sub_82162850(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8215b560
	ctx.lr = 0x8215B9C0;
	sub_8215B560(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// bl 0x82162870
	ctx.lr = 0x8215B9CC;
	sub_82162870(ctx, base);
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lis r27,-32125
	r27.s64 = -2105344000;
	// lwz r11,26756(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 26756);
	// clrlwi r4,r11,31
	ctx.r4.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8215ba00
	if (!cr6.eq) goto loc_8215BA00;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,26756(r30)
	PPC_STORE_U32(r30.u32 + 26756, r11.u32);
	// addi r3,r10,26448
	ctx.r3.s64 = ctx.r10.s64 + 26448;
	// bl 0x821c9790
	ctx.lr = 0x8215B9F8;
	sub_821C9790(ctx, base);
	// lwz r11,26756(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 26756);
	// stw r3,26752(r27)
	PPC_STORE_U32(r27.u32 + 26752, ctx.r3.u32);
loc_8215BA00:
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8215ba30
	if (!cr6.eq) goto loc_8215BA30;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,26756(r30)
	PPC_STORE_U32(r30.u32 + 26756, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,26436
	ctx.r3.s64 = ctx.r10.s64 + 26436;
	// bl 0x821c9790
	ctx.lr = 0x8215BA28;
	sub_821C9790(ctx, base);
	// stw r3,26748(r28)
	PPC_STORE_U32(r28.u32 + 26748, ctx.r3.u32);
	// b 0x8215ba34
	goto loc_8215BA34;
loc_8215BA30:
	// lwz r3,26748(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 26748);
loc_8215BA34:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r10,26752(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 26752);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8215ba58
	if (!cr6.eq) goto loc_8215BA58;
	// li r11,0
	r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_8215BA58:
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bne cr6,0x8215ba74
	if (!cr6.eq) goto loc_8215BA74;
	// li r11,1
	r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_8215BA74:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8215BA80"))) PPC_WEAK_FUNC(sub_8215BA80);
PPC_FUNC_IMPL(__imp__sub_8215BA80) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8215BA88;
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lfs f29,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f29.f64 = double(temp.f32);
	// stfs f29,200(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x82162918
	ctx.lr = 0x8215BABC;
	sub_82162918(ctx, base);
	// lwz r10,204(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8215baf4
	if (!cr6.eq) goto loc_8215BAF4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	f30.f64 = double(temp.f32);
	// fmuls f1,f31,f30
	ctx.f1.f64 = double(float(f31.f64 * f30.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8215BADC;
	sub_823DBAE8(ctx, base);
	// fsubs f0,f29,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f29.f64 - f31.f64));
	// frsp f31,f1
	f31.f64 = double(float(ctx.f1.f64));
	// fmuls f1,f0,f30
	ctx.f1.f64 = double(float(f0.f64 * f30.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8215BAEC;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// b 0x8215baf8
	goto loc_8215BAF8;
loc_8215BAF4:
	// fsubs f13,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f29.f64 - f31.f64));
loc_8215BAF8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r5,26112
	ctx.r3.s64 = ctx.r5.s64 + 26112;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	v60.f32[0] = log2f(v63.f32[0]);
	v60.f32[1] = log2f(v63.f32[1]);
	v60.f32[2] = log2f(v63.f32[2]);
	v60.f32[3] = log2f(v63.f32[3]);
	// vlogefp128 v61,v62
	v61.f32[0] = log2f(v62.f32[0]);
	v61.f32[1] = log2f(v62.f32[1]);
	v61.f32[2] = log2f(v62.f32[2]);
	v61.f32[3] = log2f(v62.f32[3]);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v60,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,-24(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -24);
	f0.f64 = double(temp.f32);
	// lfs f12,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 - f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,-28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -28);
	f0.f64 = double(temp.f32);
	// vmulfp128 v59,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f1,f11,f6,f0
	ctx.f1.f64 = ctx.f11.f64 >= 0.0 ? ctx.f6.f64 : f0.f64;
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fsel f31,f10,f8,f0
	f31.f64 = ctx.f10.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// beq cr6,0x8215bbbc
	if (cr6.eq) goto loc_8215BBBC;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,11440(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8215bbc0
	goto loc_8215BBC0;
loc_8215BBBC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215BBC0:
	// bl 0x8213b768
	ctx.lr = 0x8215BBC4;
	sub_8213B768(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215bbf4
	if (cr6.eq) goto loc_8215BBF4;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r11,r8
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r10,11440(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11440);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8215bbf8
	goto loc_8215BBF8;
loc_8215BBF4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215BBF8:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213b768
	ctx.lr = 0x8215BC00;
	sub_8213B768(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215bc34
	if (cr6.eq) goto loc_8215BC34;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215bc38
	goto loc_8215BC38;
loc_8215BC34:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215BC38:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x8215BC40;
	sub_8213B7B0(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215bc70
	if (cr6.eq) goto loc_8215BC70;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215bc74
	goto loc_8215BC74;
loc_8215BC70:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215BC74:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x8215BC7C;
	sub_8213D890(ctx, base);
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215bcb0
	if (cr6.eq) goto loc_8215BCB0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215bcb4
	goto loc_8215BCB4;
loc_8215BCB0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215BCB4:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x8215BCBC;
	sub_8213B7B0(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215bcec
	if (cr6.eq) goto loc_8215BCEC;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215bcf0
	goto loc_8215BCF0;
loc_8215BCEC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215BCF0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8213d890
	ctx.lr = 0x8215BCF8;
	sub_8213D890(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8215b5f8
	ctx.lr = 0x8215BD04;
	sub_8215B5F8(ctx, base);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8215BD1C"))) PPC_WEAK_FUNC(sub_8215BD1C);
PPC_FUNC_IMPL(__imp__sub_8215BD1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215BD20"))) PPC_WEAK_FUNC(sub_8215BD20);
PPC_FUNC_IMPL(__imp__sub_8215BD20) {
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
	// bl 0x823d91f4
	ctx.lr = 0x8215BD28;
	// stfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f29.u64);
	// stfd f30,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215bda0
	if (cr6.eq) goto loc_8215BDA0;
	// lbz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// mulli r9,r9,11488
	ctx.r9.s64 = ctx.r9.s64 * 11488;
	// add r6,r9,r7
	ctx.r6.u64 = ctx.r9.u64 + ctx.r7.u64;
	// lwz r9,11440(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8215bda0
	if (cr6.eq) goto loc_8215BDA0;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215bd90
	if (cr6.eq) goto loc_8215BD90;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8215bd94
	goto loc_8215BD94;
loc_8215BD90:
	// li r11,0
	r11.s64 = 0;
loc_8215BD94:
	// lhz r11,6(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x8215bdf0
	if (cr6.eq) goto loc_8215BDF0;
loc_8215BDA0:
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215c098
	if (cr6.eq) goto loc_8215C098;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r10,r9
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
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
	// beq cr6,0x8215c098
	if (cr6.eq) goto loc_8215C098;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215bde0
	if (cr6.eq) goto loc_8215BDE0;
	// mullw r10,r10,r9
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r9.s32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8215bde4
	goto loc_8215BDE4;
loc_8215BDE0:
	// li r11,0
	r11.s64 = 0;
loc_8215BDE4:
	// lhz r11,6(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8215c098
	if (!cr6.eq) goto loc_8215C098;
loc_8215BDF0:
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// ble cr6,0x8215be08
	if (!cr6.gt) goto loc_8215BE08;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8215b678
	ctx.lr = 0x8215BE08;
	sub_8215B678(ctx, base);
loc_8215BE08:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lfs f1,200(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// addi r3,r31,208
	ctx.r3.s64 = r31.s64 + 208;
	// bl 0x82162918
	ctx.lr = 0x8215BE18;
	sub_82162918(ctx, base);
	// lwz r11,204(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 204);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8215be58
	if (!cr6.eq) goto loc_8215BE58;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f29,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	f29.f64 = double(temp.f32);
	// fmuls f1,f30,f29
	ctx.f1.f64 = double(float(f30.f64 * f29.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8215BE38;
	sub_823DBAE8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// fmuls f1,f0,f29
	ctx.f1.f64 = double(float(f0.f64 * f29.f64));
	// bl 0x823dbae8
	ctx.lr = 0x8215BE50;
	sub_823DBAE8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// b 0x8215be68
	goto loc_8215BE68;
loc_8215BE58:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = f30.f64;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 - f30.f64));
loc_8215BE68:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lbz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r5,26112
	ctx.r3.s64 = ctx.r5.s64 + 26112;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,0
	r29.s64 = 0;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r28,0
	r28.s64 = 0;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	v60.f32[0] = log2f(v63.f32[0]);
	v60.f32[1] = log2f(v63.f32[1]);
	v60.f32[2] = log2f(v63.f32[2]);
	v60.f32[3] = log2f(v63.f32[3]);
	// vlogefp128 v61,v62
	v61.f32[0] = log2f(v62.f32[0]);
	v61.f32[1] = log2f(v62.f32[1]);
	v61.f32[2] = log2f(v62.f32[2]);
	v61.f32[3] = log2f(v62.f32[3]);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v58,v60,v63
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,-24(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -24);
	f0.f64 = double(temp.f32);
	// lfs f12,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 - f0.f64));
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,-28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -28);
	f0.f64 = double(temp.f32);
	// vmulfp128 v59,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f1,f11,f6,f0
	ctx.f1.f64 = ctx.f11.f64 >= 0.0 ? ctx.f6.f64 : f0.f64;
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// fsel f31,f10,f8,f0
	f31.f64 = ctx.f10.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// beq cr6,0x8215bfb0
	if (cr6.eq) goto loc_8215BFB0;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r9,11440(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8215bfb4
	if (cr6.eq) goto loc_8215BFB4;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215bf44
	if (cr6.eq) goto loc_8215BF44;
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// b 0x8215bf48
	goto loc_8215BF48;
loc_8215BF44:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8215BF48:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x8215bfb4
	if (!cr6.eq) goto loc_8215BFB4;
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// beq cr6,0x8215bf68
	if (cr6.eq) goto loc_8215BF68;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x8215bf6c
	goto loc_8215BF6C;
loc_8215BF68:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215BF6C:
	// bl 0x8213b768
	ctx.lr = 0x8215BF70;
	sub_8213B768(ctx, base);
	// lbz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215bfa0
	if (cr6.eq) goto loc_8215BFA0;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r11,r8
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r8.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215bfa4
	goto loc_8215BFA4;
loc_8215BFA0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215BFA4:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213e040
	ctx.lr = 0x8215BFAC;
	sub_8213E040(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_8215BFB0:
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
loc_8215BFB4:
	// lbz r9,73(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215c068
	if (cr6.eq) goto loc_8215C068;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// lwz r7,232(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r10,r10,11488
	ctx.r10.s64 = ctx.r10.s64 * 11488;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lwz r10,11440(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11440);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8215c068
	if (cr6.eq) goto loc_8215C068;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215bff8
	if (cr6.eq) goto loc_8215BFF8;
	// mullw r8,r9,r11
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// b 0x8215bffc
	goto loc_8215BFFC;
loc_8215BFF8:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8215BFFC:
	// lhz r8,6(r8)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + 6);
	// cmplwi cr6,r8,2
	cr6.compare<uint32_t>(ctx.r8.u32, 2, xer);
	// bne cr6,0x8215c068
	if (!cr6.eq) goto loc_8215C068;
	// cmplwi cr6,r9,255
	cr6.compare<uint32_t>(ctx.r9.u32, 255, xer);
	// beq cr6,0x8215c01c
	if (cr6.eq) goto loc_8215C01C;
	// mullw r11,r9,r11
	r11.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215c020
	goto loc_8215C020;
loc_8215C01C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215C020:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8213b768
	ctx.lr = 0x8215C028;
	sub_8213B768(ctx, base);
	// lbz r8,73(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215c058
	if (cr6.eq) goto loc_8215C058;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r10,r8,r11
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215c05c
	goto loc_8215C05C;
loc_8215C058:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215C05C:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x8213e040
	ctx.lr = 0x8215C064;
	sub_8213E040(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8215C068:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8215c080
	if (!cr6.eq) goto loc_8215C080;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215c098
	if (cr6.eq) goto loc_8215C098;
loc_8215C080:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8215C098:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-72(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f30,-64(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8215C0B0"))) PPC_WEAK_FUNC(sub_8215C0B0);
PPC_FUNC_IMPL(__imp__sub_8215C0B0) {
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
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// lbz r11,72(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215c100
	if (cr6.eq) goto loc_8215C100;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215c104
	goto loc_8215C104;
loc_8215C100:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215C104:
	// bl 0x8213b5c0
	ctx.lr = 0x8215C108;
	sub_8213B5C0(ctx, base);
	// lbz r8,73(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215c138
	if (cr6.eq) goto loc_8215C138;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x8215c13c
	goto loc_8215C13C;
loc_8215C138:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215C13C:
	// bl 0x8213b5c0
	ctx.lr = 0x8215C140;
	sub_8213B5C0(ctx, base);
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

__attribute__((alias("__imp__sub_8215C158"))) PPC_WEAK_FUNC(sub_8215C158);
PPC_FUNC_IMPL(__imp__sub_8215C158) {
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
	ctx.lr = 0x8215C160;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215c1ac
	if (cr6.eq) goto loc_8215C1AC;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215c1b0
	goto loc_8215C1B0;
loc_8215C1AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215C1B0:
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8213b7b0
	ctx.lr = 0x8215C1B8;
	sub_8213B7B0(ctx, base);
	// lbz r11,72(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 72);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// beq cr6,0x8215c1f0
	if (cr6.eq) goto loc_8215C1F0;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215c1f4
	goto loc_8215C1F4;
loc_8215C1F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215C1F4:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213da88
	ctx.lr = 0x8215C200;
	sub_8213DA88(ctx, base);
	// lbz r10,57(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 57);
	// lbz r11,73(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 73);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// rlwinm r5,r10,30,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215c23c
	if (cr6.eq) goto loc_8215C23C;
	// lbz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r10,11488
	ctx.r8.s64 = ctx.r10.s64 * 11488;
	// lwz r10,196(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r10,r11
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r11,11440(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11440);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215c240
	goto loc_8215C240;
loc_8215C23C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8215C240:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8213da88
	ctx.lr = 0x8215C24C;
	sub_8213DA88(ctx, base);
	// cmpwi cr6,r29,2
	cr6.compare<int32_t>(r29.s32, 2, xer);
	// beq cr6,0x8215c284
	if (cr6.eq) goto loc_8215C284;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x8215c284
	if (cr6.eq) goto loc_8215C284;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x8215c278
	if (cr6.eq) goto loc_8215C278;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8215c278
	if (cr6.eq) goto loc_8215C278;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8215C278:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8215C284:
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8215C290"))) PPC_WEAK_FUNC(sub_8215C290);
PPC_FUNC_IMPL(__imp__sub_8215C290) {
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
	ctx.lr = 0x8215C298;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// stb r29,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r29.u8);
	// stb r29,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r29.u8);
	// addi r31,r10,7216
	r31.s64 = ctx.r10.s64 + 7216;
	// lbz r11,72(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 72);
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x8215c2e8
	if (cr6.eq) goto loc_8215C2E8;
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8215c2ec
	goto loc_8215C2EC;
loc_8215C2E8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8215C2EC:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8213c758
	ctx.lr = 0x8215C2F4;
	sub_8213C758(ctx, base);
	// lbz r8,73(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 73);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8215c328
	if (cr6.eq) goto loc_8215C328;
	// lbz r11,64(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 64);
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
	// b 0x8215c32c
	goto loc_8215C32C;
loc_8215C328:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8215C32C:
	// addi r4,r1,81
	ctx.r4.s64 = ctx.r1.s64 + 81;
	// bl 0x8213c758
	ctx.lr = 0x8215C334;
	sub_8213C758(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8215c35c
	if (cr6.eq) goto loc_8215C35C;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8215c354
	if (!cr6.eq) goto loc_8215C354;
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8215c35c
	if (cr6.eq) goto loc_8215C35C;
loc_8215C354:
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r27)
	PPC_STORE_U8(r27.u32 + 0, r11.u8);
loc_8215C35C:
	// cmpw cr6,r28,r3
	cr6.compare<int32_t>(r28.s32, ctx.r3.s32, xer);
	// ble cr6,0x8215c368
	if (!cr6.gt) goto loc_8215C368;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_8215C368:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8215C370"))) PPC_WEAK_FUNC(sub_8215C370);
PPC_FUNC_IMPL(__imp__sub_8215C370) {
	PPC_FUNC_PROLOGUE();
	// b 0x8215bd20
	sub_8215BD20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215C374"))) PPC_WEAK_FUNC(sub_8215C374);
PPC_FUNC_IMPL(__imp__sub_8215C374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215C378"))) PPC_WEAK_FUNC(sub_8215C378);
PPC_FUNC_IMPL(__imp__sub_8215C378) {
	PPC_FUNC_PROLOGUE();
	// b 0x8215c0b0
	sub_8215C0B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215C37C"))) PPC_WEAK_FUNC(sub_8215C37C);
PPC_FUNC_IMPL(__imp__sub_8215C37C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215C380"))) PPC_WEAK_FUNC(sub_8215C380);
PPC_FUNC_IMPL(__imp__sub_8215C380) {
	PPC_FUNC_PROLOGUE();
	// b 0x8215c158
	sub_8215C158(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215C384"))) PPC_WEAK_FUNC(sub_8215C384);
PPC_FUNC_IMPL(__imp__sub_8215C384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215C388"))) PPC_WEAK_FUNC(sub_8215C388);
PPC_FUNC_IMPL(__imp__sub_8215C388) {
	PPC_FUNC_PROLOGUE();
	// b 0x8215ba80
	sub_8215BA80(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215C38C"))) PPC_WEAK_FUNC(sub_8215C38C);
PPC_FUNC_IMPL(__imp__sub_8215C38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215C390"))) PPC_WEAK_FUNC(sub_8215C390);
PPC_FUNC_IMPL(__imp__sub_8215C390) {
	PPC_FUNC_PROLOGUE();
	// b 0x8215c290
	sub_8215C290(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8215C394"))) PPC_WEAK_FUNC(sub_8215C394);
PPC_FUNC_IMPL(__imp__sub_8215C394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215C398"))) PPC_WEAK_FUNC(sub_8215C398);
PPC_FUNC_IMPL(__imp__sub_8215C398) {
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
	// bl 0x8215b6e0
	ctx.lr = 0x8215C3B8;
	sub_8215B6E0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8215c3e0
	if (cr6.eq) goto loc_8215C3E0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8215c3e0
	if (cr6.eq) goto loc_8215C3E0;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lbz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,7216
	ctx.r3.s64 = r11.s64 + 7216;
	// bl 0x8213f7a8
	ctx.lr = 0x8215C3E0;
	sub_8213F7A8(ctx, base);
loc_8215C3E0:
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

__attribute__((alias("__imp__sub_8215C3FC"))) PPC_WEAK_FUNC(sub_8215C3FC);
PPC_FUNC_IMPL(__imp__sub_8215C3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8215C400"))) PPC_WEAK_FUNC(sub_8215C400);
PPC_FUNC_IMPL(__imp__sub_8215C400) {
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
	// bl 0x8213b968
	ctx.lr = 0x8215C418;
	sub_8213B968(ctx, base);
	// lbz r5,236(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 236);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r4,r5,24
	ctx.r4.u64 = ctx.r5.u32 & 0xFF;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r7,r8,26800
	ctx.r7.s64 = ctx.r8.s64 + 26800;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r6,255
	ctx.r6.s64 = 255;
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// rlwinm r4,r4,0,28,24
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFFFFFFFF8F;
	// stfs f0,168(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f0,172(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stb r11,233(r31)
	PPC_STORE_U8(r31.u32 + 233, r11.u8);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,234(r31)
	PPC_STORE_U8(r31.u32 + 234, r11.u8);
	// stw r11,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r11.u32);
	// stw r11,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r11.u32);
	// stw r11,184(r31)
	PPC_STORE_U32(r31.u32 + 184, r11.u32);
	// stw r10,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r10.u32);
	// stw r10,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r10.u32);
	// stw r10,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r10.u32);
	// stw r11,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r11.u32);
	// stw r11,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r11.u32);
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
	// stw r11,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r11.u32);
	// stw r11,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r11.u32);
	// stb r6,235(r31)
	PPC_STORE_U8(r31.u32 + 235, ctx.r6.u8);
	// stb r4,236(r31)
	PPC_STORE_U8(r31.u32 + 236, ctx.r4.u8);
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

__attribute__((alias("__imp__sub_8215C4A4"))) PPC_WEAK_FUNC(sub_8215C4A4);
PPC_FUNC_IMPL(__imp__sub_8215C4A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

