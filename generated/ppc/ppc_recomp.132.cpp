#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_8264CFB8) {
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
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-32368
	ctx.r4.s64 = ctx.r9.s64 + -32368;
	// addi r6,r31,2784
	ctx.r6.s64 = r31.s64 + 2784;
	// addi r8,r11,28356
	ctx.r8.s64 = r11.s64 + 28356;
	// addi r5,r10,-32392
	ctx.r5.s64 = ctx.r10.s64 + -32392;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x826543a0
	ctx.lr = 0x8264CFF4;
	sub_826543A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264D008;
	sub_82634B60(ctx, base);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r4,32332
	ctx.r10.s64 = ctx.r4.s64 + 32332;
	// addi r9,r3,7428
	ctx.r9.s64 = ctx.r3.s64 + 7428;
	// addi r8,r11,26516
	ctx.r8.s64 = r11.s64 + 26516;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r7,5
	ctx.r7.s64 = 5;
	// stw r9,2784(r31)
	PPC_STORE_U32(r31.u32 + 2784, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,2788(r31)
	PPC_STORE_U32(r31.u32 + 2788, ctx.r8.u32);
	// stw r7,2792(r31)
	PPC_STORE_U32(r31.u32 + 2792, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,2796(r31)
	PPC_STORE_U32(r31.u32 + 2796, ctx.r6.u32);
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

PPC_WEAK_FUNC(sub_8264CFB8) {
	__imp__sub_8264CFB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264D06C) {
	__imp__sub_8264D06C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D070) {
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
	ctx.lr = 0x8264D078;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387b90
	ctx.lr = 0x8264D088;
	sub_82387B90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a4ae0
	ctx.lr = 0x8264D094;
	sub_822A4AE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// extsh r5,r30
	ctx.r5.s64 = r30.s16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x8264d0b4
	if (!cr6.eq) goto loc_8264D0B4;
	// bl 0x8238af98
	ctx.lr = 0x8264D0B0;
	sub_8238AF98(ctx, base);
	// b 0x8264d0b8
	goto loc_8264D0B8;
loc_8264D0B4:
	// bl 0x8238afc8
	ctx.lr = 0x8264D0B8;
	sub_8238AFC8(ctx, base);
loc_8264D0B8:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8238b128
	ctx.lr = 0x8264D0C4;
	sub_8238B128(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8264c4d0
	ctx.lr = 0x8264D0CC;
	sub_8264C4D0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8264D070) {
	__imp__sub_8264D070(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D0D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264D0D4) {
	__imp__sub_8264D0D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D0D8) {
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
	ctx.lr = 0x8264D0E0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8264d204
	if (cr6.eq) goto loc_8264D204;
	// cmpwi cr6,r4,62
	cr6.compare<int32_t>(ctx.r4.s32, 62, xer);
	// beq cr6,0x8264d2b4
	if (cr6.eq) goto loc_8264D2B4;
	// cmpwi cr6,r4,63
	cr6.compare<int32_t>(ctx.r4.s32, 63, xer);
	// beq cr6,0x8264d10c
	if (cr6.eq) goto loc_8264D10C;
	// bl 0x8264b668
	ctx.lr = 0x8264D104;
	sub_8264B668(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8264D10C:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x8264D114;
	sub_82203240(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mulli r11,r29,240
	r11.s64 = r29.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r30,r11,2784
	r30.s64 = r11.s64 + 2784;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,2784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2784);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D138;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264d2a8
	if (cr6.eq) goto loc_8264D2A8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264D150;
	sub_821E6800(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264D164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264d2b4
	if (cr6.eq) goto loc_8264D2B4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8264D18C;
	sub_82641CB0(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// extsh r4,r29
	ctx.r4.s64 = r29.s16;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-12052(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12052);
	// bl 0x82397ba8
	ctx.lr = 0x8264D1A0;
	sub_82397BA8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r7,0
	ctx.r4.s64 = ctx.r7.s64 + 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lbz r6,604(r8)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r8.u32 + 604);
	// stw r29,5156(r28)
	PPC_STORE_U32(r28.u32 + 5156, r29.u32);
	// cntlzw r11,r6
	r11.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stb r10,5152(r28)
	PPC_STORE_U8(r28.u32 + 5152, ctx.r10.u8);
	// bl 0x821c2f90
	ctx.lr = 0x8264D1D0;
	sub_821C2F90(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,728(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 728);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// ld r6,8(r9)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// rldicr r7,r7,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264D1F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8264D204:
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8264D210;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8264d220
	if (cr6.lt) goto loc_8264D220;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8264D220:
	// mulli r11,r11,240
	r11.s64 = r11.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,2784
	ctx.r3.s64 = r11.s64 + 2784;
	// lwz r11,2784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2784);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D23C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264d2a8
	if (cr6.eq) goto loc_8264D2A8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8264D250;
	sub_82203240(ctx, base);
	// mulli r11,r3,240
	r11.s64 = ctx.r3.s64 * 240;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r10,r11,2784
	ctx.r10.s64 = r11.s64 + 2784;
	// lbz r11,2992(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 2992);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264d2a8
	if (!cr6.eq) goto loc_8264D2A8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8264D274;
	sub_821E6800(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203240
	ctx.lr = 0x8264D27C;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8264d070
	ctx.lr = 0x8264D288;
	sub_8264D070(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264D29C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
loc_8264D2A8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8264D2B4;
	sub_821E6800(ctx, base);
loc_8264D2B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8264D0D8) {
	__imp__sub_8264D0D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D2C0) {
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
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-31520
	ctx.r4.s64 = ctx.r9.s64 + -31520;
	// addi r6,r31,2784
	ctx.r6.s64 = r31.s64 + 2784;
	// addi r8,r11,28356
	ctx.r8.s64 = r11.s64 + 28356;
	// addi r5,r10,-31536
	ctx.r5.s64 = ctx.r10.s64 + -31536;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x826543a0
	ctx.lr = 0x8264D2FC;
	sub_826543A0(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264D310;
	sub_82634B60(ctx, base);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r10,r4,-32348
	ctx.r10.s64 = ctx.r4.s64 + -32348;
	// addi r9,r3,7428
	ctx.r9.s64 = ctx.r3.s64 + 7428;
	// addi r8,r11,26508
	ctx.r8.s64 = r11.s64 + 26508;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r9,2784(r31)
	PPC_STORE_U32(r31.u32 + 2784, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,2788(r31)
	PPC_STORE_U32(r31.u32 + 2788, ctx.r8.u32);
	// stw r7,2792(r31)
	PPC_STORE_U32(r31.u32 + 2792, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,2796(r31)
	PPC_STORE_U32(r31.u32 + 2796, ctx.r6.u32);
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

PPC_WEAK_FUNC(sub_8264D2C0) {
	__imp__sub_8264D2C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264D374) {
	__imp__sub_8264D374(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8264D380;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-30628
	ctx.r4.s64 = ctx.r9.s64 + -30628;
	// addi r8,r11,28356
	ctx.r8.s64 = r11.s64 + 28356;
	// addi r5,r10,-30640
	ctx.r5.s64 = ctx.r10.s64 + -30640;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264D3B0;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264D3C4;
	sub_82634B60(ctx, base);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D3DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// addi r8,r4,-31452
	ctx.r8.s64 = ctx.r4.s64 + -31452;
	// addi r7,r3,7428
	ctx.r7.s64 = ctx.r3.s64 + 7428;
	// addi r6,r10,-28004
	ctx.r6.s64 = ctx.r10.s64 + -28004;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r11,1
	r11.s64 = 1;
	// stw r7,2784(r31)
	PPC_STORE_U32(r31.u32 + 2784, ctx.r7.u32);
	// li r5,5
	ctx.r5.s64 = 5;
	// stw r6,2788(r31)
	PPC_STORE_U32(r31.u32 + 2788, ctx.r6.u32);
	// addi r4,r9,26464
	ctx.r4.s64 = ctx.r9.s64 + 26464;
	// stw r11,2796(r31)
	PPC_STORE_U32(r31.u32 + 2796, r11.u32);
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r5,2792(r31)
	PPC_STORE_U32(r31.u32 + 2792, ctx.r5.u32);
	// stw r4,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, ctx.r4.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r3,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, ctx.r3.u32);
	// addi r29,r31,2816
	r29.s64 = r31.s64 + 2816;
	// stw r7,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, ctx.r7.u32);
	// addi r5,r31,2784
	ctx.r5.s64 = r31.s64 + 2784;
	// stw r11,2812(r31)
	PPC_STORE_U32(r31.u32 + 2812, r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-31472
	ctx.r4.s64 = ctx.r10.s64 + -31472;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r30,r31,2800
	r30.s64 = r31.s64 + 2800;
	// bl 0x826349f0
	ctx.lr = 0x8264D44C;
	sub_826349F0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r28,r31,3056
	r28.s64 = r31.s64 + 3056;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r9,-31484
	ctx.r4.s64 = ctx.r9.s64 + -31484;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826349f0
	ctx.lr = 0x8264D468;
	sub_826349F0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r27,r31,3296
	r27.s64 = r31.s64 + 3296;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-31500
	ctx.r4.s64 = ctx.r8.s64 + -31500;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826349f0
	ctx.lr = 0x8264D484;
	sub_826349F0(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r7.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r6,672(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r5,648(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 648);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8264D378) {
	__imp__sub_8264D378(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264D4F4) {
	__imp__sub_8264D4F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D4F8) {
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
	ctx.lr = 0x8264D500;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-29760
	ctx.r4.s64 = ctx.r9.s64 + -29760;
	// addi r8,r11,29180
	ctx.r8.s64 = r11.s64 + 29180;
	// addi r5,r10,-29776
	ctx.r5.s64 = ctx.r10.s64 + -29776;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264D530;
	sub_82654318(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r7,r8,-21868
	ctx.r7.s64 = ctx.r8.s64 + -21868;
	// addi r26,r29,992
	r26.s64 = r29.s64 + 992;
	// stw r7,992(r29)
	PPC_STORE_U32(r29.u32 + 992, ctx.r7.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r6,-29788
	ctx.r4.s64 = ctx.r6.s64 + -29788;
	// addi r3,r26,4
	ctx.r3.s64 = r26.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x8264D554;
	sub_823DB670(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r11,r4,-29796
	r11.s64 = ctx.r4.s64 + -29796;
	// addi r3,r5,-30604
	ctx.r3.s64 = ctx.r5.s64 + -30604;
	// stw r11,992(r29)
	PPC_STORE_U32(r29.u32 + 992, r11.u32);
	// addi r31,r29,1040
	r31.s64 = r29.s64 + 1040;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// li r30,5
	r30.s64 = 5;
	// mr r28,r31
	r28.u64 = r31.u64;
	// addi r27,r11,3998
	r27.s64 = r11.s64 + 3998;
loc_8264D580:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264D590;
	sub_82633D40(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r28,r28,208
	r28.s64 = r28.s64 + 208;
	// bge 0x8264d580
	if (!cr0.lt) goto loc_8264D580;
	// addi r3,r29,2288
	ctx.r3.s64 = r29.s64 + 2288;
	// bl 0x82634b60
	ctx.lr = 0x8264D5A4;
	sub_82634B60(ctx, base);
	// addi r3,r29,4080
	ctx.r3.s64 = r29.s64 + 4080;
	// bl 0x8238c960
	ctx.lr = 0x8264D5AC;
	sub_8238C960(ctx, base);
	// lwz r10,496(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 496);
	// li r11,2
	r11.s64 = 2;
	// addi r3,r29,496
	ctx.r3.s64 = r29.s64 + 496;
	// stw r11,952(r29)
	PPC_STORE_U32(r29.u32 + 952, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264D5CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r28,r29,848
	r28.s64 = r29.s64 + 848;
	// addi r27,r11,26492
	r27.s64 = r11.s64 + 26492;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_8264D5DC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D5F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r6,r27,16
	ctx.r6.s64 = r27.s64 + 16;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// cmpw cr6,r30,r6
	cr6.compare<int32_t>(r30.s32, ctx.r6.s32, xer);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
	// addi r31,r31,208
	r31.s64 = r31.s64 + 208;
	// blt cr6,0x8264d5dc
	if (cr6.lt) goto loc_8264D5DC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r10,-20020
	ctx.r5.s64 = ctx.r10.s64 + -20020;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x8264D63C;
	sub_8268B960(ctx, base);
	// stw r3,5424(r29)
	PPC_STORE_U32(r29.u32 + 5424, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8264D4F8) {
	__imp__sub_8264D4F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D64C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264D64C) {
	__imp__sub_8264D64C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D650) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D67C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264d6a8
	if (cr6.eq) goto loc_8264D6A8;
	// lwz r11,5424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5424);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8264d6a8
	if (!cr6.eq) goto loc_8264D6A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D6A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264D6A8:
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

PPC_WEAK_FUNC(sub_8264D650) {
	__imp__sub_8264D650(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D6C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264D6C4) {
	__imp__sub_8264D6C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D6C8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-992
	ctx.r3.s64 = ctx.r3.s64 + -992;
	// b 0x8264e200
	sub_8264E200(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8264D6C8) {
	__imp__sub_8264D6C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D6D0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-992
	ctx.r3.s64 = ctx.r3.s64 + -992;
	// b 0x8264d650
	sub_8264D650(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8264D6D0) {
	__imp__sub_8264D6D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D6D8) {
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
	ctx.lr = 0x8264D6E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,-30604
	ctx.r9.s64 = r11.s64 + -30604;
	// addi r8,r10,-29796
	ctx.r8.s64 = ctx.r10.s64 + -29796;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stw r8,992(r31)
	PPC_STORE_U32(r31.u32 + 992, ctx.r8.u32);
	// addi r28,r31,992
	r28.s64 = r31.s64 + 992;
	// lwz r5,5424(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 5424);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10224(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x8264D718;
	sub_8268B6D0(ctx, base);
	// addi r30,r31,2288
	r30.s64 = r31.s64 + 2288;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fbc8
	ctx.lr = 0x8264D724;
	sub_8221FBC8(ctx, base);
	// li r29,5
	r29.s64 = 5;
loc_8264D728:
	// addi r30,r30,-208
	r30.s64 = r30.s64 + -208;
	// lhz r11,194(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264d740
	if (cr6.eq) goto loc_8264D740;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8264D740;
	sub_82130588(ctx, base);
loc_8264D740:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8264D748;
	sub_82633B00(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// bge 0x8264d728
	if (!cr0.lt) goto loc_8264D728;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// bl 0x8221fcc8
	ctx.lr = 0x8264D764;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8264D6D8) {
	__imp__sub_8264D6D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D76C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264D76C) {
	__imp__sub_8264D76C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D770) {
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
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8264d7a4
	if (cr6.eq) goto loc_8264D7A4;
	// bl 0x826537d0
	ctx.lr = 0x8264D790;
	sub_826537D0(ctx, base);
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
loc_8264D7A4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8264D7B0;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8264c950
	ctx.lr = 0x8264D7B8;
	sub_8264C950(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264d80c
	if (cr6.eq) goto loc_8264D80C;
	// lis r10,-32155
	ctx.r10.s64 = -2107310080;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r10,-14608
	ctx.r10.s64 = ctx.r10.s64 + -14608;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bl 0x82130000
	ctx.lr = 0x8264D7DC;
	sub_82130000(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r6,r11,-29728
	ctx.r6.s64 = r11.s64 + -29728;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r5,r10,-29752
	ctx.r5.s64 = ctx.r10.s64 + -29752;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r31,2288
	ctx.r3.s64 = r31.s64 + 2288;
	// bl 0x82634fd8
	ctx.lr = 0x8264D808;
	sub_82634FD8(ctx, base);
	// b 0x8264d820
	goto loc_8264D820;
loc_8264D80C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264D820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264D820:
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

PPC_WEAK_FUNC(sub_8264D770) {
	__imp__sub_8264D770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D838) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,216(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 216);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264D838) {
	__imp__sub_8264D838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D840) {
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
	// lhz r11,194(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264d870
	if (cr6.eq) goto loc_8264D870;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8264D870;
	sub_82130588(ctx, base);
loc_8264D870:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8264D878;
	sub_82633B00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264d890
	if (cr6.eq) goto loc_8264D890;
	// bl 0x82130588
	ctx.lr = 0x8264D88C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264D890:
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

PPC_WEAK_FUNC(sub_8264D840) {
	__imp__sub_8264D840(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D8A8) {
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
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x8264D8CC;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8264D8D4;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264d8ec
	if (cr6.eq) goto loc_8264D8EC;
	// bl 0x82130588
	ctx.lr = 0x8264D8E8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264D8EC:
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

PPC_WEAK_FUNC(sub_8264D8A8) {
	__imp__sub_8264D8A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D904) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264D904) {
	__imp__sub_8264D904(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264D908) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8264D910;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-28112
	ctx.r4.s64 = ctx.r9.s64 + -28112;
	// addi r8,r11,28356
	ctx.r8.s64 = r11.s64 + 28356;
	// addi r5,r10,-28136
	ctx.r5.s64 = ctx.r10.s64 + -28136;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,6
	ctx.r6.s64 = 6;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264D940;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264D954;
	sub_82634B60(ctx, base);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264D96C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r9,r4,-28948
	ctx.r9.s64 = ctx.r4.s64 + -28948;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// addi r7,r3,7428
	ctx.r7.s64 = ctx.r3.s64 + 7428;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r6,r10,26464
	ctx.r6.s64 = ctx.r10.s64 + 26464;
	// li r30,1
	r30.s64 = 1;
	// stw r7,2784(r31)
	PPC_STORE_U32(r31.u32 + 2784, ctx.r7.u32);
	// li r11,2
	r11.s64 = 2;
	// stw r6,2788(r31)
	PPC_STORE_U32(r31.u32 + 2788, ctx.r6.u32);
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// stw r30,2796(r31)
	PPC_STORE_U32(r31.u32 + 2796, r30.u32);
	// addi r4,r8,26480
	ctx.r4.s64 = ctx.r8.s64 + 26480;
	// stw r11,2792(r31)
	PPC_STORE_U32(r31.u32 + 2792, r11.u32);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r6,2804(r31)
	PPC_STORE_U32(r31.u32 + 2804, ctx.r6.u32);
	// addi r10,r5,26472
	ctx.r10.s64 = ctx.r5.s64 + 26472;
	// stw r7,2800(r31)
	PPC_STORE_U32(r31.u32 + 2800, ctx.r7.u32);
	// stw r11,2808(r31)
	PPC_STORE_U32(r31.u32 + 2808, r11.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stw r30,2812(r31)
	PPC_STORE_U32(r31.u32 + 2812, r30.u32);
	// addi r25,r31,2848
	r25.s64 = r31.s64 + 2848;
	// stw r4,2820(r31)
	PPC_STORE_U32(r31.u32 + 2820, ctx.r4.u32);
	// addi r5,r31,2784
	ctx.r5.s64 = r31.s64 + 2784;
	// stw r3,2824(r31)
	PPC_STORE_U32(r31.u32 + 2824, ctx.r3.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r7,2816(r31)
	PPC_STORE_U32(r31.u32 + 2816, ctx.r7.u32);
	// addi r4,r9,-28976
	ctx.r4.s64 = ctx.r9.s64 + -28976;
	// stw r30,2828(r31)
	PPC_STORE_U32(r31.u32 + 2828, r30.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r7,2832(r31)
	PPC_STORE_U32(r31.u32 + 2832, ctx.r7.u32);
	// addi r29,r31,2800
	r29.s64 = r31.s64 + 2800;
	// stw r10,2836(r31)
	PPC_STORE_U32(r31.u32 + 2836, ctx.r10.u32);
	// addi r27,r31,2816
	r27.s64 = r31.s64 + 2816;
	// stw r11,2840(r31)
	PPC_STORE_U32(r31.u32 + 2840, r11.u32);
	// addi r26,r31,2832
	r26.s64 = r31.s64 + 2832;
	// stw r30,2844(r31)
	PPC_STORE_U32(r31.u32 + 2844, r30.u32);
	// bl 0x826349f0
	ctx.lr = 0x8264DA0C;
	sub_826349F0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r28,r31,3088
	r28.s64 = r31.s64 + 3088;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,-28992
	ctx.r4.s64 = ctx.r8.s64 + -28992;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826349f0
	ctx.lr = 0x8264DA28;
	sub_826349F0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r24,r31,3328
	r24.s64 = r31.s64 + 3328;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r7,-29008
	ctx.r4.s64 = ctx.r7.s64 + -29008;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826349f0
	ctx.lr = 0x8264DA44;
	sub_826349F0(ctx, base);
	// addi r29,r31,3568
	r29.s64 = r31.s64 + 3568;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-29028
	ctx.r4.s64 = ctx.r6.s64 + -29028;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264DA5C;
	sub_82633D40(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// li r4,-10
	ctx.r4.s64 = -10;
	// stw r30,3788(r31)
	PPC_STORE_U32(r31.u32 + 3788, r30.u32);
	// addi r3,r5,-29700
	ctx.r3.s64 = ctx.r5.s64 + -29700;
	// stb r30,3792(r31)
	PPC_STORE_U8(r31.u32 + 3792, r30.u8);
	// li r11,10
	r11.s64 = 10;
	// stw r4,3776(r31)
	PPC_STORE_U32(r31.u32 + 3776, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,3568(r31)
	PPC_STORE_U32(r31.u32 + 3568, ctx.r3.u32);
	// stw r11,3780(r31)
	PPC_STORE_U32(r31.u32 + 3780, r11.u32);
	// addi r3,r29,228
	ctx.r3.s64 = r29.s64 + 228;
	// stw r10,3784(r31)
	PPC_STORE_U32(r31.u32 + 3784, ctx.r10.u32);
	// bl 0x821c2f70
	ctx.lr = 0x8264DA90;
	sub_821C2F70(ctx, base);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r30,r31,3824
	r30.s64 = r31.s64 + 3824;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r11,24600(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24600);
	// addi r4,r7,-29048
	ctx.r4.s64 = ctx.r7.s64 + -29048;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,3816(r31)
	PPC_STORE_U32(r31.u32 + 3816, r11.u32);
	// lwz r11,24596(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24596);
	// stw r11,3820(r31)
	PPC_STORE_U32(r31.u32 + 3820, r11.u32);
	// bl 0x826349f0
	ctx.lr = 0x8264DAC4;
	sub_826349F0(ctx, base);
	// addi r3,r31,4064
	ctx.r3.s64 = r31.s64 + 4064;
	// bl 0x82634b60
	ctx.lr = 0x8264DACC;
	sub_82634B60(ctx, base);
	// addi r3,r31,5856
	ctx.r3.s64 = r31.s64 + 5856;
	// bl 0x821c2f70
	ctx.lr = 0x8264DAD4;
	sub_821C2F70(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r4,r31,672
	ctx.r4.s64 = r31.s64 + 672;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r3.u16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r24.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r29,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lwz r6,3088(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 3088);
	// lwz r5,548(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 548);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264DB68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8264D908) {
	__imp__sub_8264D908(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264DB74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264DB74) {
	__imp__sub_8264DB74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264DB78) {
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
	// bl 0x826483e0
	ctx.lr = 0x8264DB98;
	sub_826483E0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264dbb0
	if (cr6.eq) goto loc_8264DBB0;
	// bl 0x82130588
	ctx.lr = 0x8264DBAC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264DBB0:
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

PPC_WEAK_FUNC(sub_8264DB78) {
	__imp__sub_8264DB78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264DBC8) {
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
	ctx.lr = 0x8264DBD0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-27172
	ctx.r4.s64 = ctx.r9.s64 + -27172;
	// addi r8,r11,28356
	ctx.r8.s64 = r11.s64 + 28356;
	// addi r5,r10,-27184
	ctx.r5.s64 = ctx.r10.s64 + -27184;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264DC00;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264DC14;
	sub_82634B60(ctx, base);
	// lwz r6,496(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264DC2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r4,-27996
	ctx.r3.s64 = ctx.r4.s64 + -27996;
	// addi r28,r31,2784
	r28.s64 = r31.s64 + 2784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-28016
	ctx.r4.s64 = r11.s64 + -28016;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264DC50;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r29,0
	r29.s64 = 0;
	// li r30,1
	r30.s64 = 1;
	// addi r22,r10,-29700
	r22.s64 = ctx.r10.s64 + -29700;
	// stw r29,2992(r31)
	PPC_STORE_U32(r31.u32 + 2992, r29.u32);
	// li r23,10
	r23.s64 = 10;
	// stw r29,3000(r31)
	PPC_STORE_U32(r31.u32 + 3000, r29.u32);
	// stw r22,2784(r31)
	PPC_STORE_U32(r31.u32 + 2784, r22.u32);
	// addi r3,r28,228
	ctx.r3.s64 = r28.s64 + 228;
	// stw r23,2996(r31)
	PPC_STORE_U32(r31.u32 + 2996, r23.u32);
	// stw r30,3004(r31)
	PPC_STORE_U32(r31.u32 + 3004, r30.u32);
	// stb r30,3008(r31)
	PPC_STORE_U8(r31.u32 + 3008, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8264DC84;
	sub_821C2F70(ctx, base);
	// lis r21,-32126
	r21.s64 = -2105409536;
	// lis r20,-32126
	r20.s64 = -2105409536;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r27,r31,3040
	r27.s64 = r31.s64 + 3040;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,24600(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 24600);
	// addi r4,r9,-28032
	ctx.r4.s64 = ctx.r9.s64 + -28032;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r11,3032(r31)
	PPC_STORE_U32(r31.u32 + 3032, r11.u32);
	// lwz r11,24596(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 24596);
	// stw r11,3036(r31)
	PPC_STORE_U32(r31.u32 + 3036, r11.u32);
	// bl 0x82633d40
	ctx.lr = 0x8264DCB4;
	sub_82633D40(ctx, base);
	// stw r22,3040(r31)
	PPC_STORE_U32(r31.u32 + 3040, r22.u32);
	// stw r29,3248(r31)
	PPC_STORE_U32(r31.u32 + 3248, r29.u32);
	// addi r3,r27,228
	ctx.r3.s64 = r27.s64 + 228;
	// stw r23,3252(r31)
	PPC_STORE_U32(r31.u32 + 3252, r23.u32);
	// stw r29,3256(r31)
	PPC_STORE_U32(r31.u32 + 3256, r29.u32);
	// stw r30,3260(r31)
	PPC_STORE_U32(r31.u32 + 3260, r30.u32);
	// stb r30,3264(r31)
	PPC_STORE_U8(r31.u32 + 3264, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8264DCD4;
	sub_821C2F70(ctx, base);
	// lwz r11,24600(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 24600);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r26,r31,3296
	r26.s64 = r31.s64 + 3296;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-28048
	ctx.r4.s64 = ctx.r8.s64 + -28048;
	// stw r11,3288(r31)
	PPC_STORE_U32(r31.u32 + 3288, r11.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,24596(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 24596);
	// stw r11,3292(r31)
	PPC_STORE_U32(r31.u32 + 3292, r11.u32);
	// bl 0x82633d40
	ctx.lr = 0x8264DCFC;
	sub_82633D40(ctx, base);
	// stw r22,3296(r31)
	PPC_STORE_U32(r31.u32 + 3296, r22.u32);
	// stw r29,3504(r31)
	PPC_STORE_U32(r31.u32 + 3504, r29.u32);
	// addi r3,r26,228
	ctx.r3.s64 = r26.s64 + 228;
	// stw r23,3508(r31)
	PPC_STORE_U32(r31.u32 + 3508, r23.u32);
	// stw r29,3512(r31)
	PPC_STORE_U32(r31.u32 + 3512, r29.u32);
	// stw r30,3516(r31)
	PPC_STORE_U32(r31.u32 + 3516, r30.u32);
	// stb r30,3520(r31)
	PPC_STORE_U8(r31.u32 + 3520, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8264DD1C;
	sub_821C2F70(ctx, base);
	// lwz r11,24600(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 24600);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r25,r31,3552
	r25.s64 = r31.s64 + 3552;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-28072
	ctx.r4.s64 = ctx.r7.s64 + -28072;
	// stw r11,3544(r31)
	PPC_STORE_U32(r31.u32 + 3544, r11.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r11,24596(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 24596);
	// stw r11,3548(r31)
	PPC_STORE_U32(r31.u32 + 3548, r11.u32);
	// bl 0x82633d40
	ctx.lr = 0x8264DD44;
	sub_82633D40(ctx, base);
	// stw r22,3552(r31)
	PPC_STORE_U32(r31.u32 + 3552, r22.u32);
	// stw r29,3760(r31)
	PPC_STORE_U32(r31.u32 + 3760, r29.u32);
	// addi r3,r25,228
	ctx.r3.s64 = r25.s64 + 228;
	// stw r23,3764(r31)
	PPC_STORE_U32(r31.u32 + 3764, r23.u32);
	// stw r29,3768(r31)
	PPC_STORE_U32(r31.u32 + 3768, r29.u32);
	// stw r30,3772(r31)
	PPC_STORE_U32(r31.u32 + 3772, r30.u32);
	// stb r30,3776(r31)
	PPC_STORE_U8(r31.u32 + 3776, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8264DD64;
	sub_821C2F70(ctx, base);
	// lwz r11,24600(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 24600);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r24,r31,3808
	r24.s64 = r31.s64 + 3808;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-28088
	ctx.r4.s64 = ctx.r6.s64 + -28088;
	// stw r11,3800(r31)
	PPC_STORE_U32(r31.u32 + 3800, r11.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r11,24596(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 24596);
	// stw r11,3804(r31)
	PPC_STORE_U32(r31.u32 + 3804, r11.u32);
	// bl 0x82633d40
	ctx.lr = 0x8264DD8C;
	sub_82633D40(ctx, base);
	// stw r22,3808(r31)
	PPC_STORE_U32(r31.u32 + 3808, r22.u32);
	// stw r29,4016(r31)
	PPC_STORE_U32(r31.u32 + 4016, r29.u32);
	// addi r3,r24,228
	ctx.r3.s64 = r24.s64 + 228;
	// stw r23,4020(r31)
	PPC_STORE_U32(r31.u32 + 4020, r23.u32);
	// stw r29,4024(r31)
	PPC_STORE_U32(r31.u32 + 4024, r29.u32);
	// stw r30,4028(r31)
	PPC_STORE_U32(r31.u32 + 4028, r30.u32);
	// stb r30,4032(r31)
	PPC_STORE_U8(r31.u32 + 4032, r30.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8264DDAC;
	sub_821C2F70(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// li r29,5
	r29.s64 = 5;
	// lwz r11,24600(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 24600);
	// stw r11,4056(r31)
	PPC_STORE_U32(r31.u32 + 4056, r11.u32);
	// lwz r11,24596(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 24596);
	// stw r11,4060(r31)
	PPC_STORE_U32(r31.u32 + 4060, r11.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r28,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r28.u32);
	// subfic r28,r5,1240
	xer.ca = ctx.r5.u32 <= 1240;
	r28.s64 = 1240 - ctx.r5.s64;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r11,848(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r25,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, r25.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r24.u32);
loc_8264DE48:
	// bl 0x82387b90
	ctx.lr = 0x8264DE4C;
	sub_82387B90(ctx, base);
	// add r11,r28,r30
	r11.u64 = r28.u64 + r30.u64;
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// lfsx f0,r11,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8264de48
	if (!cr0.eq) goto loc_8264DE48;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e6980
	ctx.lr = 0x8264DE6C;
	sub_821E6980(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x8264de8c
	if (!cr6.eq) goto loc_8264DE8C;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// bl 0x821ef7a8
	ctx.lr = 0x8264DE8C;
	sub_821EF7A8(ctx, base);
loc_8264DE8C:
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lwz r11,-12216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,26460(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stfs f0,32(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// stw r10,3032(r31)
	PPC_STORE_U32(r31.u32 + 3032, ctx.r10.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,3036(r31)
	PPC_STORE_U32(r31.u32 + 3036, r11.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,3288(r31)
	PPC_STORE_U32(r31.u32 + 3288, r11.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,3292(r31)
	PPC_STORE_U32(r31.u32 + 3292, r11.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,3544(r31)
	PPC_STORE_U32(r31.u32 + 3544, r11.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,3548(r31)
	PPC_STORE_U32(r31.u32 + 3548, r11.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,3800(r31)
	PPC_STORE_U32(r31.u32 + 3800, r11.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,3804(r31)
	PPC_STORE_U32(r31.u32 + 3804, r11.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,4056(r31)
	PPC_STORE_U32(r31.u32 + 4056, r11.u32);
	// lwz r11,26460(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 26460);
	// stw r11,4060(r31)
	PPC_STORE_U32(r31.u32 + 4060, r11.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_8264DBC8) {
	__imp__sub_8264DBC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264DEF8) {
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
	// bl 0x826484e8
	ctx.lr = 0x8264DF18;
	sub_826484E8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264df30
	if (cr6.eq) goto loc_8264DF30;
	// bl 0x82130588
	ctx.lr = 0x8264DF2C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264DF30:
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

PPC_WEAK_FUNC(sub_8264DEF8) {
	__imp__sub_8264DEF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264DF48) {
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
	ctx.lr = 0x8264DF50;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r9,-26324
	ctx.r4.s64 = ctx.r9.s64 + -26324;
	// addi r8,r11,28932
	ctx.r8.s64 = r11.s64 + 28932;
	// addi r5,r10,-26336
	ctx.r5.s64 = ctx.r10.s64 + -26336;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,11
	ctx.r6.s64 = 11;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264DF80;
	sub_82654318(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r24,992
	ctx.r3.s64 = r24.s64 + 992;
	// addi r7,r8,31516
	ctx.r7.s64 = ctx.r8.s64 + 31516;
	// stw r7,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r7.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264DF94;
	sub_82634B60(ctx, base);
	// lwz r6,496(r24)
	ctx.r6.u64 = PPC_LOAD_U32(r24.u32 + 496);
	// addi r3,r24,496
	ctx.r3.s64 = r24.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264DFAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r23,r24,2784
	r23.s64 = r24.s64 + 2784;
	// addi r3,r4,-27148
	ctx.r3.s64 = ctx.r4.s64 + -27148;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r3,0(r24)
	PPC_STORE_U32(r24.u32 + 0, ctx.r3.u32);
	// mr r31,r23
	r31.u64 = r23.u64;
	// li r29,10
	r29.s64 = 10;
	// li r30,0
	r30.s64 = 0;
	// li r26,1
	r26.s64 = 1;
	// li r25,-1
	r25.s64 = -1;
	// addi r28,r11,30860
	r28.s64 = r11.s64 + 30860;
	// addi r27,r10,3998
	r27.s64 = ctx.r10.s64 + 3998;
loc_8264DFE0:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264DFF0;
	sub_82633D40(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// stb r30,208(r31)
	PPC_STORE_U8(r31.u32 + 208, r30.u8);
	// addi r3,r31,220
	ctx.r3.s64 = r31.s64 + 220;
	// stb r30,210(r31)
	PPC_STORE_U8(r31.u32 + 210, r30.u8);
	// stw r26,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r26.u32);
	// stw r25,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r25.u32);
	// bl 0x821c2f70
	ctx.lr = 0x8264E00C;
	sub_821C2F70(ctx, base);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,240
	r31.s64 = r31.s64 + 240;
	// bge 0x8264dfe0
	if (!cr0.lt) goto loc_8264DFE0;
	// addi r3,r24,5424
	ctx.r3.s64 = r24.s64 + 5424;
	// bl 0x82634b60
	ctx.lr = 0x8264E020;
	sub_82634B60(ctx, base);
	// lis r25,-32115
	r25.s64 = -2104688640;
	// lwz r3,-12052(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12052);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addic. r27,r11,-1
	xer.ca = r11.u32 > 0;
	r27.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// ble 0x8264e090
	if (!cr0.gt) goto loc_8264E090;
	// addi r29,r24,848
	r29.s64 = r24.s64 + 848;
	// mr r31,r23
	r31.u64 = r23.u64;
	// b 0x8264e044
	goto loc_8264E044;
loc_8264E040:
	// lwz r3,-12052(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -12052);
loc_8264E044:
	// extsh r4,r30
	ctx.r4.s64 = r30.s16;
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82397b90
	ctx.lr = 0x8264E050;
	sub_82397B90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,340(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 340);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8264E064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// sth r8,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r8.u16);
	// stwx r31,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r31.u32);
	// stw r26,212(r31)
	PPC_STORE_U32(r31.u32 + 212, r26.u32);
	// addi r31,r31,240
	r31.s64 = r31.s64 + 240;
	// blt cr6,0x8264e040
	if (cr6.lt) goto loc_8264E040;
loc_8264E090:
	// lis r11,-32155
	r11.s64 = -2107310080;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// addi r4,r11,-20552
	ctx.r4.s64 = r11.s64 + -20552;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x8264E0A4;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264E0B4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264e0b4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264E0B4;
	// addi r10,r24,888
	ctx.r10.s64 = r24.s64 + 888;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8264E0D8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8264e0d8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8264E0D8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_8264DF48) {
	__imp__sub_8264DF48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E0F8) {
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
	// bl 0x826482d0
	ctx.lr = 0x8264E118;
	sub_826482D0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e130
	if (cr6.eq) goto loc_8264E130;
	// bl 0x82130588
	ctx.lr = 0x8264E12C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264E130:
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

PPC_WEAK_FUNC(sub_8264E0F8) {
	__imp__sub_8264E0F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E148) {
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
	// addi r3,r31,2784
	ctx.r3.s64 = r31.s64 + 2784;
	// bl 0x821d2028
	ctx.lr = 0x8264E16C;
	sub_821D2028(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x8221fbc8
	ctx.lr = 0x8264E174;
	sub_8221FBC8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8264E17C;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e194
	if (cr6.eq) goto loc_8264E194;
	// bl 0x82130588
	ctx.lr = 0x8264E190;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264E194:
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

PPC_WEAK_FUNC(sub_8264E148) {
	__imp__sub_8264E148(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E1AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E1AC) {
	__imp__sub_8264E1AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E1B0) {
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
	// bl 0x82648330
	ctx.lr = 0x8264E1D0;
	sub_82648330(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e1e8
	if (cr6.eq) goto loc_8264E1E8;
	// bl 0x82130588
	ctx.lr = 0x8264E1E4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264E1E8:
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

PPC_WEAK_FUNC(sub_8264E1B0) {
	__imp__sub_8264E1B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E200) {
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
	// bl 0x8264d6d8
	ctx.lr = 0x8264E220;
	sub_8264D6D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e238
	if (cr6.eq) goto loc_8264E238;
	// bl 0x82130588
	ctx.lr = 0x8264E234;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264E238:
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

PPC_WEAK_FUNC(sub_8264E200) {
	__imp__sub_8264E200(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E250) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8264E258;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r25,r11,3998
	r25.s64 = r11.s64 + 3998;
	// addi r4,r9,-25304
	ctx.r4.s64 = ctx.r9.s64 + -25304;
	// addi r8,r10,29492
	ctx.r8.s64 = ctx.r10.s64 + 29492;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8264E28C;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r26,r31,992
	r26.s64 = r31.s64 + 992;
	// addi r7,r8,-26108
	ctx.r7.s64 = ctx.r8.s64 + -26108;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r26
	r30.u64 = r26.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r27,5
	r27.s64 = 5;
	// li r28,0
	r28.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// li r23,-1
	r23.s64 = -1;
	// addi r24,r11,30860
	r24.s64 = r11.s64 + 30860;
loc_8264E2B8:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264E2C8;
	sub_82633D40(ctx, base);
	// stw r24,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r24.u32);
	// stb r28,208(r30)
	PPC_STORE_U8(r30.u32 + 208, r28.u8);
	// addi r3,r30,220
	ctx.r3.s64 = r30.s64 + 220;
	// stb r28,210(r30)
	PPC_STORE_U8(r30.u32 + 210, r28.u8);
	// stw r29,212(r30)
	PPC_STORE_U32(r30.u32 + 212, r29.u32);
	// stw r23,216(r30)
	PPC_STORE_U32(r30.u32 + 216, r23.u32);
	// bl 0x821c2f70
	ctx.lr = 0x8264E2E4;
	sub_821C2F70(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r30,r30,240
	r30.s64 = r30.s64 + 240;
	// bge 0x8264e2b8
	if (!cr0.lt) goto loc_8264E2B8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r31,2432
	r30.s64 = r31.s64 + 2432;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-26132
	ctx.r4.s64 = r11.s64 + -26132;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8264E308;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r9,10
	ctx.r9.s64 = 10;
	// stw r28,2640(r31)
	PPC_STORE_U32(r31.u32 + 2640, r28.u32);
	// addi r8,r10,-29700
	ctx.r8.s64 = ctx.r10.s64 + -29700;
	// stw r29,2652(r31)
	PPC_STORE_U32(r31.u32 + 2652, r29.u32);
	// li r7,4
	ctx.r7.s64 = 4;
	// stw r9,2644(r31)
	PPC_STORE_U32(r31.u32 + 2644, ctx.r9.u32);
	// stw r8,2432(r31)
	PPC_STORE_U32(r31.u32 + 2432, ctx.r8.u32);
	// addi r3,r30,228
	ctx.r3.s64 = r30.s64 + 228;
	// stw r7,2648(r31)
	PPC_STORE_U32(r31.u32 + 2648, ctx.r7.u32);
	// stb r29,2656(r31)
	PPC_STORE_U8(r31.u32 + 2656, r29.u8);
	// bl 0x821c2f70
	ctx.lr = 0x8264E338;
	sub_821C2F70(ctx, base);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// addi r3,r31,2688
	ctx.r3.s64 = r31.s64 + 2688;
	// lwz r11,24600(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24600);
	// stw r11,2680(r31)
	PPC_STORE_U32(r31.u32 + 2680, r11.u32);
	// lwz r11,24596(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24596);
	// stw r11,2684(r31)
	PPC_STORE_U32(r31.u32 + 2684, r11.u32);
	// bl 0x82634b60
	ctx.lr = 0x8264E358;
	sub_82634B60(ctx, base);
	// lwz r11,496(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264E370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r9,-26164
	ctx.r4.s64 = ctx.r9.s64 + -26164;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264E38C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1232(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1232);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r3,r31,1232
	ctx.r3.s64 = r31.s64 + 1232;
	// addi r4,r6,-26196
	ctx.r4.s64 = ctx.r6.s64 + -26196;
	// lwz r11,340(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 340);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8264E3A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1472(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1472);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r31,1472
	ctx.r3.s64 = r31.s64 + 1472;
	// addi r4,r10,-26228
	ctx.r4.s64 = ctx.r10.s64 + -26228;
	// lwz r8,340(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 340);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264E3C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1712(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1712);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r3,r31,1712
	ctx.r3.s64 = r31.s64 + 1712;
	// addi r4,r7,-26256
	ctx.r4.s64 = ctx.r7.s64 + -26256;
	// lwz r5,340(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 340);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264E3E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,1952(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1952);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r31,1952
	ctx.r3.s64 = r31.s64 + 1952;
	// addi r4,r4,-26280
	ctx.r4.s64 = ctx.r4.s64 + -26280;
	// lwz r10,340(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264E3FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,2192(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// addi r4,r9,-26304
	ctx.r4.s64 = ctx.r9.s64 + -26304;
	// lwz r7,340(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 340);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264E418;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r31,848
	ctx.r9.s64 = r31.s64 + 848;
	// addi r11,r31,1201
	r11.s64 = r31.s64 + 1201;
	// li r10,6
	ctx.r10.s64 = 6;
loc_8264E424:
	// stw r29,3(r11)
	PPC_STORE_U32(r11.u32 + 3, r29.u32);
	// addi r5,r11,-209
	ctx.r5.s64 = r11.s64 + -209;
	// stb r28,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r28.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,240
	r11.s64 = r11.s64 + 240;
	// lhz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// rotlwi r6,r4,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// addi r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 1;
	// sth r3,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r3.u16);
	// stwx r5,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r5.u32);
	// bne 0x8264e424
	if (!cr0.eq) goto loc_8264E424;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_8264E250) {
	__imp__sub_8264E250(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E464) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E464) {
	__imp__sub_8264E464(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E468) {
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
	// bl 0x82646bc8
	ctx.lr = 0x8264E488;
	sub_82646BC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e4a0
	if (cr6.eq) goto loc_8264E4A0;
	// bl 0x82130588
	ctx.lr = 0x8264E49C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264E4A0:
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

PPC_WEAK_FUNC(sub_8264E468) {
	__imp__sub_8264E468(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E4B8) {
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
	// clrlwi r30,r5,24
	r30.u64 = ctx.r5.u32 & 0xFF;
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// rlwinm r10,r11,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// cmplw cr6,r10,r30
	cr6.compare<uint32_t>(ctx.r10.u32, r30.u32, xer);
	// beq cr6,0x8264e4f4
	if (cr6.eq) goto loc_8264E4F4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264E4F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264E4F4:
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// rlwimi r11,r30,7,0,24
	r11.u64 = (__builtin_rotateleft32(r30.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,192(r31)
	PPC_STORE_U8(r31.u32 + 192, r11.u8);
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

PPC_WEAK_FUNC(sub_8264E4B8) {
	__imp__sub_8264E4B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E518) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lbz r11,192(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 192);
	// rlwinm r10,r11,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// stb r10,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264E518) {
	__imp__sub_8264E518(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E528) {
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
	// clrlwi r30,r4,24
	r30.u64 = ctx.r4.u32 & 0xFF;
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// rlwinm r10,r11,26,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// beq cr6,0x8264e564
	if (cr6.eq) goto loc_8264E564;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264E564;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264E564:
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// rlwimi r11,r30,6,25,25
	r11.u64 = (__builtin_rotateleft32(r30.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r11,192(r31)
	PPC_STORE_U8(r31.u32 + 192, r11.u8);
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

PPC_WEAK_FUNC(sub_8264E528) {
	__imp__sub_8264E528(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,192(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264E588) {
	__imp__sub_8264E588(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E594) {
	__imp__sub_8264E594(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E598) {
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
	// bl 0x823bbf80
	ctx.lr = 0x8264E5A8;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e600
	if (cr6.eq) goto loc_8264E600;
	// bl 0x82256058
	ctx.lr = 0x8264E5B8;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8264e5ec
	if (cr6.eq) goto loc_8264E5EC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lwz r10,2608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2608);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8264e5ec
	if (cr6.eq) goto loc_8264E5EC;
	// lbz r11,3764(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3764);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e600
	if (cr6.eq) goto loc_8264E600;
	// bl 0x82256028
	ctx.lr = 0x8264E5E4;
	sub_82256028(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x8264e600
	if (!cr6.lt) goto loc_8264E600;
loc_8264E5EC:
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
loc_8264E600:
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

PPC_WEAK_FUNC(sub_8264E598) {
	__imp__sub_8264E598(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E614) {
	__imp__sub_8264E614(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,792(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 792);
	f0.f64 = double(temp.f32);
	// lbz r11,768(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 768);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// stfs f13,792(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 792, temp.u32);
	// beq cr6,0x8264e6bc
	if (cr6.eq) goto loc_8264E6BC;
	// addi r30,r31,468
	r30.s64 = r31.s64 + 468;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82726160
	ctx.lr = 0x8264E65C;
	sub_82726160(ctx, base);
	// lwz r11,468(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 468);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8264e674
	if (cr6.eq) goto loc_8264E674;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8264e678
	if (!cr6.eq) goto loc_8264E678;
loc_8264E674:
	// li r11,0
	r11.s64 = 0;
loc_8264E678:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264e6bc
	if (!cr6.eq) goto loc_8264E6BC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r8,r11,-3
	ctx.r8.s64 = r11.s64 + -3;
	// stb r10,768(r31)
	PPC_STORE_U8(r31.u32 + 768, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r6,64(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// addi r5,r11,30
	ctx.r5.s64 = r11.s64 + 30;
	// stw r5,772(r31)
	PPC_STORE_U32(r31.u32 + 772, ctx.r5.u32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8264E6BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264E6BC:
	// lbz r11,790(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 790);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e6d4
	if (cr6.eq) goto loc_8264E6D4;
	// lfs f0,796(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 796);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,796(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 796, temp.u32);
loc_8264E6D4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264E6E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264e76c
	if (cr6.eq) goto loc_8264E76C;
	// bl 0x82387a18
	ctx.lr = 0x8264E6F8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e76c
	if (cr6.eq) goto loc_8264E76C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-3624(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x8264E710;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e76c
	if (cr6.eq) goto loc_8264E76C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,-3624(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x8264E72C;
	sub_82293F60(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x8264E73C;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x8264E740;
	sub_82293F60(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8264e76c
	if (!cr6.lt) goto loc_8264E76C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264E76C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264E76C:
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

PPC_WEAK_FUNC(sub_8264E618) {
	__imp__sub_8264E618(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E788) {
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
	ctx.lr = 0x8264E790;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,14
	cr6.compare<int32_t>(r30.s32, 14, xer);
	// beq cr6,0x8264e828
	if (cr6.eq) goto loc_8264E828;
	// cmpwi cr6,r30,59
	cr6.compare<int32_t>(r30.s32, 59, xer);
	// bne cr6,0x8264e810
	if (!cr6.eq) goto loc_8264E810;
	// bl 0x82387a18
	ctx.lr = 0x8264E7B4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264e804
	if (cr6.eq) goto loc_8264E804;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,21
	ctx.r4.s64 = 21;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8264E7E0;
	sub_8268EE10(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264E7F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8264E804:
	// lwz r11,804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 804);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8264e86c
	if (!cr6.eq) goto loc_8264E86C;
loc_8264E810:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826309e0
	ctx.lr = 0x8264E820;
	sub_826309E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8264E828:
	// lwz r11,804(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 804);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8264e86c
	if (!cr6.eq) goto loc_8264E86C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x822043c8
	ctx.lr = 0x8264E840;
	sub_822043C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r3,-12012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12012);
	// lwz r11,-27288(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27288);
	// lwz r8,2252(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// bne cr6,0x8264e86c
	if (!cr6.eq) goto loc_8264E86C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x8264E86C;
	sub_821F1498(ctx, base);
loc_8264E86C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8264E788) {
	__imp__sub_8264E788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,792(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 792, temp.u32);
	// beq cr6,0x8264e8ac
	if (cr6.eq) goto loc_8264E8AC;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x8264e8a4
	if (cr6.eq) goto loc_8264E8A4;
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// stw r5,784(r3)
	PPC_STORE_U32(ctx.r3.u32 + 784, ctx.r5.u32);
	// blr 
	return;
loc_8264E8A4:
	// stw r5,776(r3)
	PPC_STORE_U32(ctx.r3.u32 + 776, ctx.r5.u32);
	// blr 
	return;
loc_8264E8AC:
	// stw r5,780(r3)
	PPC_STORE_U32(ctx.r3.u32 + 780, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264E878) {
	__imp__sub_8264E878(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E8B4) {
	__imp__sub_8264E8B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E8B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8264e8e8
	if (cr6.eq) goto loc_8264E8E8;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x8264e8dc
	if (cr6.eq) goto loc_8264E8DC;
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,784(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 784);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
loc_8264E8DC:
	// lwz r11,776(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 776);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
loc_8264E8E8:
	// lwz r11,780(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 780);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264E8B8) {
	__imp__sub_8264E8B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E8F4) {
	__imp__sub_8264E8F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E8F8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8262fd60
	sub_8262FD60(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8264E8F8) {
	__imp__sub_8264E8F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E8FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E8FC) {
	__imp__sub_8264E8FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8264e920
	if (cr6.eq) goto loc_8264E920;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x8264e92c
	if (!cr6.eq) goto loc_8264E92C;
	// lbz r11,204(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 204);
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// rlwimi r11,r10,6,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// b 0x8264e928
	goto loc_8264E928;
loc_8264E920:
	// lbz r11,204(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 204);
	// rlwimi r11,r5,7,17,24
	r11.u64 = (__builtin_rotateleft32(ctx.r5.u32, 7) & 0x7F80) | (r11.u64 & 0xFFFFFFFFFFFF807F);
loc_8264E928:
	// stb r11,204(r3)
	PPC_STORE_U8(ctx.r3.u32 + 204, r11.u8);
loc_8264E92C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8264E900) {
	__imp__sub_8264E900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E93C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E93C) {
	__imp__sub_8264E93C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E940) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq cr6,0x8264e960
	if (cr6.eq) goto loc_8264E960;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r11,204(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 204);
	// rlwinm r10,r11,26,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// stb r10,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// blr 
	return;
loc_8264E960:
	// lbz r11,204(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 204);
	// rlwinm r10,r11,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 25) & 0x1FFFFFF;
	// stb r10,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264E940) {
	__imp__sub_8264E940(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E970) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r5,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r5.u32);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8264E970) {
	__imp__sub_8264E970(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E984) {
	__imp__sub_8264E984(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264E988) {
	__imp__sub_8264E988(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E994) {
	__imp__sub_8264E994(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r4,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r4.u32);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8264E998) {
	__imp__sub_8264E998(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E9AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E9AC) {
	__imp__sub_8264E9AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E9B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82630980
	sub_82630980(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8264E9B0) {
	__imp__sub_8264E9B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E9B4) {
	__imp__sub_8264E9B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E9B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x8264e9c4
	if (!cr6.eq) goto loc_8264E9C4;
	// stb r5,204(r3)
	PPC_STORE_U8(ctx.r3.u32 + 204, ctx.r5.u8);
loc_8264E9C4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8264E9B8) {
	__imp__sub_8264E9B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E9D4) {
	__imp__sub_8264E9D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E9D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lbz r11,204(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 204);
	// stb r11,0(r5)
	PPC_STORE_U8(ctx.r5.u32 + 0, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264E9D8) {
	__imp__sub_8264E9D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E9EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264E9EC) {
	__imp__sub_8264E9EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264E9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8264ea14
	if (cr6.lt) goto loc_8264EA14;
	// beq cr6,0x8264ea0c
	if (cr6.eq) goto loc_8264EA0C;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bne cr6,0x8264ea18
	if (!cr6.eq) goto loc_8264EA18;
	// stfs f1,200(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// b 0x8264ea18
	goto loc_8264EA18;
loc_8264EA0C:
	// stfs f1,196(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// b 0x8264ea18
	goto loc_8264EA18;
loc_8264EA14:
	// stfs f1,192(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
loc_8264EA18:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8264E9F0) {
	__imp__sub_8264E9F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EA28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmplwi cr6,r4,1
	cr6.compare<uint32_t>(ctx.r4.u32, 1, xer);
	// blt cr6,0x8264ea54
	if (cr6.lt) goto loc_8264EA54;
	// beq cr6,0x8264ea48
	if (cr6.eq) goto loc_8264EA48;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lfs f0,200(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
loc_8264EA48:
	// lfs f0,196(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
loc_8264EA54:
	// lfs f0,192(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264EA28) {
	__imp__sub_8264EA28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EA60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8264EA60) {
	__imp__sub_8264EA60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EA70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8264ea98
	if (cr6.eq) goto loc_8264EA98;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// beq cr6,0x8264ea90
	if (cr6.eq) goto loc_8264EA90;
	// cmpwi cr6,r4,5
	cr6.compare<int32_t>(ctx.r4.s32, 5, xer);
	// bne cr6,0x8264ea9c
	if (!cr6.eq) goto loc_8264EA9C;
	// stw r5,208(r3)
	PPC_STORE_U32(ctx.r3.u32 + 208, ctx.r5.u32);
	// b 0x8264ea9c
	goto loc_8264EA9C;
loc_8264EA90:
	// stw r5,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r5.u32);
	// b 0x8264ea9c
	goto loc_8264EA9C;
loc_8264EA98:
	// stw r5,196(r3)
	PPC_STORE_U32(ctx.r3.u32 + 196, ctx.r5.u32);
loc_8264EA9C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8264EA70) {
	__imp__sub_8264EA70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264EAAC) {
	__imp__sub_8264EAAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EAB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8264eacc
	if (cr6.eq) goto loc_8264EACC;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
loc_8264EACC:
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264EAB0) {
	__imp__sub_8264EAB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EAD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// bne cr6,0x8264eae4
	if (!cr6.eq) goto loc_8264EAE4;
	// stfs f1,204(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
loc_8264EAE4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8264EAD8) {
	__imp__sub_8264EAD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264EAF4) {
	__imp__sub_8264EAF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EAF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister f0{};
	PPCRegister temp{};
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lfs f0,204(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 204);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264EAF8) {
	__imp__sub_8264EAF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264EB0C) {
	__imp__sub_8264EB0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EB10) {
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
	// bl 0x82630980
	ctx.lr = 0x8264EB2C;
	sub_82630980(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264EB40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264EB58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8264eb8c
	if (cr6.eq) goto loc_8264EB8C;
	// lbz r11,176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// rlwinm r9,r11,0,0,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// addi r4,r10,-21604
	ctx.r4.s64 = ctx.r10.s64 + -21604;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// b 0x8264eb98
	goto loc_8264EB98;
loc_8264EB8C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-21604
	ctx.r4.s64 = r11.s64 + -21604;
loc_8264EB98:
	// bl 0x825ee0e0
	ctx.lr = 0x8264EB9C;
	sub_825EE0E0(ctx, base);
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

PPC_WEAK_FUNC(sub_8264EB10) {
	__imp__sub_8264EB10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EBB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264EBB4) {
	__imp__sub_8264EBB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EBB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// stfs f31,192(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// addi r31,r10,-21584
	r31.s64 = ctx.r10.s64 + -21584;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264EBEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825ee188
	ctx.lr = 0x8264EBF8;
	sub_825EE188(ctx, base);
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

PPC_WEAK_FUNC(sub_8264EBB8) {
	__imp__sub_8264EBB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EC10) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,17268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264ec94
	if (cr6.eq) goto loc_8264EC94;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264ec58
	if (cr6.eq) goto loc_8264EC58;
	// lwz r11,260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8264ec74
	if (!cr6.gt) goto loc_8264EC74;
	// lwz r11,136(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// b 0x8264ec68
	goto loc_8264EC68;
loc_8264EC58:
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8264ec74
	if (!cr6.gt) goto loc_8264EC74;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
loc_8264EC68:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8264ec78
	if (!cr6.eq) goto loc_8264EC78;
loc_8264EC74:
	// li r11,0
	r11.s64 = 0;
loc_8264EC78:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264ec94
	if (cr6.eq) goto loc_8264EC94;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x822a3998
	ctx.lr = 0x8264EC90;
	sub_822A3998(ctx, base);
	// lwz r3,48(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
loc_8264EC94:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264EC10) {
	__imp__sub_8264EC10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264ECA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264ECA4) {
	__imp__sub_8264ECA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264ECA8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264eda0
	if (cr6.eq) goto loc_8264EDA0;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264ecf8
	if (cr6.eq) goto loc_8264ECF8;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8264ed14
	if (!cr6.gt) goto loc_8264ED14;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8264ed08
	goto loc_8264ED08;
loc_8264ECF8:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8264ed14
	if (!cr6.gt) goto loc_8264ED14;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8264ED08:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x8264ed18
	if (!cr6.eq) goto loc_8264ED18;
loc_8264ED14:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8264ED18:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264eda0
	if (cr6.eq) goto loc_8264EDA0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x8264ED30;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// lwz r10,880(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 880);
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// lwz r30,784(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 784);
	// bl 0x822a3998
	ctx.lr = 0x8264ED4C;
	sub_822A3998(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,880(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 880);
	// lwz r6,84(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// lwz r31,784(r6)
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + 784);
	// bl 0x822a3998
	ctx.lr = 0x8264ED68;
	sub_822A3998(ctx, base);
	// lwz r5,880(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// addi r4,r31,-12
	ctx.r4.s64 = r31.s64 + -12;
	// addi r3,r30,-13
	ctx.r3.s64 = r30.s64 + -13;
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// lwz r8,84(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r11,784(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 784);
	// addi r6,r11,-11
	ctx.r6.s64 = r11.s64 + -11;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// or r3,r4,r9
	ctx.r3.u64 = ctx.r4.u64 | ctx.r9.u64;
	// or r3,r3,r7
	ctx.r3.u64 = ctx.r3.u64 | ctx.r7.u64;
loc_8264EDA0:
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

PPC_WEAK_FUNC(sub_8264ECA8) {
	__imp__sub_8264ECA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EDB8) {
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
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8264EDE0;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264EDFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,640(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264EE14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,2000(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264EE2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// addi r3,r31,448
	ctx.r3.s64 = r31.s64 + 448;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264EE44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,832(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264EE5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1408(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1408);
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8264EE74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8264EE8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,3648(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3648);
	// addi r3,r31,3648
	ctx.r3.s64 = r31.s64 + 3648;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264EEA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1808(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264EEBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1600(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264EED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,1024(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264EEEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_8264EDB8) {
	__imp__sub_8264EDB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EF00) {
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
	// bl 0x82633b00
	ctx.lr = 0x8264EF20;
	sub_82633B00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264ef38
	if (cr6.eq) goto loc_8264EF38;
	// bl 0x82130588
	ctx.lr = 0x8264EF34;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8264EF38:
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

PPC_WEAK_FUNC(sub_8264EF00) {
	__imp__sub_8264EF00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EF50) {
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
	// bl 0x8262fe68
	ctx.lr = 0x8264EF68;
	sub_8262FE68(ctx, base);
	// lwz r11,4048(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4048);
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264EF7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_8264EF50) {
	__imp__sub_8264EF50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264EF90) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82630420
	ctx.lr = 0x8264EFAC;
	sub_82630420(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6432);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264EFC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r31,692(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// clrlwi r30,r30,24
	r30.u64 = r30.u32 & 0xFF;
	// lbz r8,240(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 240);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// cmplw cr6,r30,r7
	cr6.compare<uint32_t>(r30.u32, ctx.r7.u32, xer);
	// beq cr6,0x8264f000
	if (cr6.eq) goto loc_8264F000;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264EFF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,240(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 240);
	// rlwimi r9,r30,5,26,26
	ctx.r9.u64 = (__builtin_rotateleft32(r30.u32, 5) & 0x20) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFDF);
	// stb r9,240(r31)
	PPC_STORE_U8(r31.u32 + 240, ctx.r9.u8);
loc_8264F000:
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

PPC_WEAK_FUNC(sub_8264EF90) {
	__imp__sub_8264EF90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F018) {
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
	ctx.lr = 0x8264F020;
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
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f0e4
	if (cr6.eq) goto loc_8264F0E4;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264f068
	if (cr6.eq) goto loc_8264F068;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8264f084
	if (!cr6.gt) goto loc_8264F084;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8264f078
	goto loc_8264F078;
loc_8264F068:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8264f084
	if (!cr6.gt) goto loc_8264F084;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8264F078:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8264f088
	if (!cr6.eq) goto loc_8264F088;
loc_8264F084:
	// li r11,0
	r11.s64 = 0;
loc_8264F088:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f0e4
	if (cr6.eq) goto loc_8264F0E4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264F0A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264f0e4
	if (cr6.eq) goto loc_8264F0E4;
	// cmpwi cr6,r30,20
	cr6.compare<int32_t>(r30.s32, 20, xer);
	// bne cr6,0x8264f0e4
	if (!cr6.eq) goto loc_8264F0E4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,5704(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 5704);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x8264f0e4
	if (cr6.eq) goto loc_8264F0E4;
	// stfs f0,5704(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 5704, temp.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-12216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12216);
	// bl 0x821f0400
	ctx.lr = 0x8264F0E4;
	sub_821F0400(ctx, base);
loc_8264F0E4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630b70
	ctx.lr = 0x8264F0F4;
	sub_82630B70(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8264F018) {
	__imp__sub_8264F018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F0FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264F0FC) {
	__imp__sub_8264F0FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F100) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x82130000
	ctx.lr = 0x8264F120;
	sub_82130000(ctx, base);
	// lwz r11,2832(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// addi r3,r31,2832
	ctx.r3.s64 = r31.s64 + 2832;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264F138;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,4048(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4048);
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r8,188(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 188);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264F150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -6432);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8264F16C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,188(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 188);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8264F184;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_8264F100) {
	__imp__sub_8264F100(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F19C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264F19C) {
	__imp__sub_8264F19C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F1A0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82630748
	ctx.lr = 0x8264F1C0;
	sub_82630748(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-13616
	ctx.r5.s64 = r11.s64 + -13616;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3632
	ctx.r6.s64 = r31.s64 + 3632;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8264F1E0;
	sub_824DF200(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -6432);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264F1FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8264F214;
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

PPC_WEAK_FUNC(sub_8264F1A0) {
	__imp__sub_8264F1A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F22C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264F22C) {
	__imp__sub_8264F22C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F230) {
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
	ctx.lr = 0x8264F238;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x8263b730
	ctx.lr = 0x8264F240;
	sub_8263B730(ctx, base);
	// lis r11,1
	r11.s64 = 65536;
	// li r31,76
	r31.s64 = 76;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// ori r30,r11,16256
	r30.u64 = r11.u64 | 16256;
loc_8264F250:
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8264F260;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264F270;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,105
	cr6.compare<int32_t>(r31.s32, 105, xer);
	// blt cr6,0x8264f250
	if (cr6.lt) goto loc_8264F250;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8264F230) {
	__imp__sub_8264F230(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264F284) {
	__imp__sub_8264F284(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F288) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f29c
	if (cr6.eq) goto loc_8264F29C;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// blr 
	return;
loc_8264F29C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264F288) {
	__imp__sub_8264F288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F2A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264F2A4) {
	__imp__sub_8264F2A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F2A8) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264f2e4
	if (!cr6.eq) goto loc_8264F2E4;
	// bl 0x82387a18
	ctx.lr = 0x8264F2C4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264f2e4
	if (!cr6.eq) goto loc_8264F2E4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,0
	ctx.r3.s64 = 0;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264f2e8
	if (cr6.eq) goto loc_8264F2E8;
loc_8264F2E4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8264F2E8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264F2A8) {
	__imp__sub_8264F2A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F2F8) {
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
	ctx.lr = 0x8264F300;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264F328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r25,r9,-13532
	r25.s64 = ctx.r9.s64 + -13532;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9790
	ctx.lr = 0x8264F340;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x8264F350;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x8264F354;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264F36C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8264f390
	if (cr6.eq) goto loc_8264F390;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264F390;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264F390:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x824e7118
	ctx.lr = 0x8264F398;
	sub_824E7118(ctx, base);
	// addi r11,r30,448
	r11.s64 = r30.s64 + 448;
	// li r8,15
	ctx.r8.s64 = 15;
loc_8264F3A0:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264f430
	if (cr6.eq) goto loc_8264F430;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264f414
	if (cr6.eq) goto loc_8264F414;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264f41c
	if (cr6.eq) goto loc_8264F41C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264f424
	if (cr6.eq) goto loc_8264F424;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264f42c
	if (cr6.eq) goto loc_8264F42C;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// addic. r8,r8,-5
	xer.ca = ctx.r8.u32 > 4;
	ctx.r8.s64 = ctx.r8.s64 + -5;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
	// bgt 0x8264f3a0
	if (cr0.gt) goto loc_8264F3A0;
	// b 0x8264f430
	goto loc_8264F430;
loc_8264F414:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8264f430
	goto loc_8264F430;
loc_8264F41C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x8264f430
	goto loc_8264F430;
loc_8264F424:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x8264f430
	goto loc_8264F430;
loc_8264F42C:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
loc_8264F430:
	// li r8,0
	ctx.r8.s64 = 0;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r7,r10,-22384
	ctx.r7.s64 = ctx.r10.s64 + -22384;
	// addi r6,r9,3998
	ctx.r6.s64 = ctx.r9.s64 + 3998;
	// beq cr6,0x8264f45c
	if (cr6.eq) goto loc_8264F45C;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x8264f464
	goto loc_8264F464;
loc_8264F45C:
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
loc_8264F464:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8264f474
	if (cr6.eq) goto loc_8264F474;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// b 0x8264f47c
	goto loc_8264F47C;
loc_8264F474:
	// mr r8,r6
	ctx.r8.u64 = ctx.r6.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
loc_8264F47C:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8264f488
	if (cr6.eq) goto loc_8264F488;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
loc_8264F488:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r31,r30,192
	r31.s64 = r30.s64 + 192;
	// addi r5,r11,-13544
	ctx.r5.s64 = r11.s64 + -13544;
	// li r4,256
	ctx.r4.s64 = 256;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x8264F4A0;
	sub_82137A08(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8264f528
	if (cr6.eq) goto loc_8264F528;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r10,-13564
	ctx.r5.s64 = ctx.r10.s64 + -13564;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,616(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 616);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264F4C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,344(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 344);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264F4E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r30,468
	ctx.r3.s64 = r30.s64 + 468;
	// bl 0x82726320
	ctx.lr = 0x8264F4EC;
	sub_82726320(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8264f508
	if (cr6.eq) goto loc_8264F508;
	// li r11,1
	r11.s64 = 1;
	// stb r11,768(r30)
	PPC_STORE_U8(r30.u32 + 768, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8264F508:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,31
	ctx.r10.s64 = 31;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r10,772(r30)
	PPC_STORE_U32(r30.u32 + 772, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264F528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264F528:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8264F2F8) {
	__imp__sub_8264F2F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F530) {
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
	ctx.lr = 0x8264F538;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387a18
	ctx.lr = 0x8264F548;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f5f4
	if (cr6.eq) goto loc_8264F5F4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8264F55C;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8264F56C;
	sub_82270170(ctx, base);
	// bl 0x82203310
	ctx.lr = 0x8264F570;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f5f4
	if (cr6.eq) goto loc_8264F5F4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8264F584;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8264F594;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8264F59C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// beq cr6,0x8264f5b0
	if (cr6.eq) goto loc_8264F5B0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8264F5B0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x8264f5d4
	if (!cr6.eq) goto loc_8264F5D4;
	// li r3,2
	ctx.r3.s64 = 2;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8264F5D4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8264f5f4
	if (cr6.eq) goto loc_8264F5F4;
	// lwz r11,3148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3148);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8264f5f4
	if (!cr6.gt) goto loc_8264F5F4;
	// li r3,3
	ctx.r3.s64 = 3;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8264F5F4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264F608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8264F530) {
	__imp__sub_8264F530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F620) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8264F628;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x8264F634;
	sub_82630980(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x8264F638;
	sub_82256058(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r28,r27,8
	r28.s64 = r27.s64 + 8;
	// bne cr6,0x8264f64c
	if (!cr6.eq) goto loc_8264F64C;
	// li r28,0
	r28.s64 = 0;
loc_8264F64C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264F66C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,120(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 120);
	// bl 0x8264f530
	ctx.lr = 0x8264F680;
	sub_8264F530(ctx, base);
	// lbz r7,204(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 204);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// rlwinm r6,r7,0,26,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8264f69c
	if (!cr6.eq) goto loc_8264F69C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
loc_8264F69C:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// srawi r10,r11,31
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = r11.s32 >> 31;
	// xor r9,r11,r10
	ctx.r9.u64 = r11.u64 ^ ctx.r10.u64;
	// subf r5,r10,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r10.s64;
	// bl 0x8223e000
	ctx.lr = 0x8264F6B4;
	sub_8223E000(ctx, base);
	// cmplwi cr6,r29,3
	cr6.compare<uint32_t>(r29.u32, 3, xer);
	// bgt cr6,0x8264f824
	if (cr6.gt) goto loc_8264F824;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,-2348
	r12.s64 = r12.s64 + -2348;
	// rlwinm r0,r29,2,0,29
	r0.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-2036(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -2036);
	// lwz r19,-2180(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -2180);
	// lwz r19,-2332(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -2332);
	// lwz r19,-2244(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -2244);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x8264F6F0;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f824
	if (cr6.eq) goto loc_8264F824;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r31,36(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// bl 0x8226b2f0
	ctx.lr = 0x8264F70C;
	sub_8226B2F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,15900
	ctx.r4.s64 = r11.s64 + 15900;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82294028
	ctx.lr = 0x8264F720;
	sub_82294028(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x8264F724;
	sub_82293F60(ctx, base);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fdivs f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 / f0.f64));
	// bl 0x8223dfd0
	ctx.lr = 0x8264F734;
	sub_8223DFD0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82256028
	ctx.lr = 0x8264F744;
	sub_82256028(ctx, base);
	// lwz r11,3148(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3148);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// subf r9,r3,r11
	ctx.r9.s64 = r11.s64 - ctx.r3.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,-13524(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13524);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x8223dfd0
	ctx.lr = 0x8264F774;
	sub_8223DFD0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
	// lbz r11,204(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 204);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8264f7bc
	if (!cr6.eq) goto loc_8264F7BC;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264f7bc
	if (!cr6.eq) goto loc_8264F7BC;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8223dfd0
	ctx.lr = 0x8264F7A8;
	sub_8223DFD0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8223dfe0
	ctx.lr = 0x8264F7B4;
	sub_8223DFE0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_8264F7BC:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// extsw r9,r11
	ctx.r9.s64 = r11.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,18612(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 18612);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x8223dfd0
	ctx.lr = 0x8264F7E8;
	sub_8223DFD0(ctx, base);
	// lbz r8,204(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 204);
	// rlwinm r7,r8,0,25,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8264f824
	if (cr6.eq) goto loc_8264F824;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8223dfe0
	ctx.lr = 0x8264F804;
	sub_8223DFE0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264F824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8264F824:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8264F620) {
	__imp__sub_8264F620(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F82C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264F82C) {
	__imp__sub_8264F82C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F830) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x8264F84C;
	sub_82256058(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r31,r10,1
	r31.u64 = ctx.r10.u64 ^ 1;
	// bl 0x82387a18
	ctx.lr = 0x8264F85C;
	sub_82387A18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264f898
	if (cr6.eq) goto loc_8264F898;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8264F870;
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
	ctx.lr = 0x8264F884;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8264F88C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// beq cr6,0x8264f898
	if (cr6.eq) goto loc_8264F898;
	// li r31,0
	r31.s64 = 0;
loc_8264F898:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f978
	if (cr6.eq) goto loc_8264F978;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5052(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5052);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f8bc
	if (cr6.eq) goto loc_8264F8BC;
	// li r3,17
	ctx.r3.s64 = 17;
	// b 0x8264f8c8
	goto loc_8264F8C8;
loc_8264F8BC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82204018
	ctx.lr = 0x8264F8C8;
	sub_82204018(ctx, base);
loc_8264F8C8:
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r11,18
	cr6.compare<uint32_t>(r11.u32, 18, xer);
	// bgt cr6,0x8264f970
	if (cr6.gt) goto loc_8264F970;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,-1812
	r12.s64 = r12.s64 + -1812;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-1672(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1672);
	// lwz r19,-1672(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1672);
	// lwz r19,-1680(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1680);
	// lwz r19,-1680(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1680);
	// lwz r19,-1680(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1680);
	// lwz r19,-1680(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1680);
	// lwz r19,-1712(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1712);
	// lwz r19,-1728(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1728);
	// lwz r19,-1720(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1720);
	// lwz r19,-1680(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1680);
	// lwz r19,-1704(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1704);
	// lwz r19,-1680(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1680);
	// lwz r19,-1736(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1736);
	// lwz r19,-1680(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1680);
	// lwz r19,-1696(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1696);
	// lwz r19,-1696(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1696);
	// lwz r19,-1680(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1680);
	// lwz r19,-1688(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1688);
	// lwz r19,-1688(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1688);
	// addi r3,r30,5676
	ctx.r3.s64 = r30.s64 + 5676;
	// b 0x8264f97c
	goto loc_8264F97C;
	// addi r3,r30,5680
	ctx.r3.s64 = r30.s64 + 5680;
	// b 0x8264f97c
	goto loc_8264F97C;
	// addi r3,r30,5688
	ctx.r3.s64 = r30.s64 + 5688;
	// b 0x8264f97c
	goto loc_8264F97C;
	// addi r3,r30,5692
	ctx.r3.s64 = r30.s64 + 5692;
	// b 0x8264f97c
	goto loc_8264F97C;
	// addi r3,r30,5696
	ctx.r3.s64 = r30.s64 + 5696;
	// b 0x8264f97c
	goto loc_8264F97C;
	// addi r3,r30,5700
	ctx.r3.s64 = r30.s64 + 5700;
	// b 0x8264f97c
	goto loc_8264F97C;
	// addi r3,r30,5672
	ctx.r3.s64 = r30.s64 + 5672;
	// b 0x8264f97c
	goto loc_8264F97C;
loc_8264F970:
	// addi r3,r30,5668
	ctx.r3.s64 = r30.s64 + 5668;
	// b 0x8264f97c
	goto loc_8264F97C;
loc_8264F978:
	// addi r3,r30,5664
	ctx.r3.s64 = r30.s64 + 5664;
loc_8264F97C:
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

PPC_WEAK_FUNC(sub_8264F830) {
	__imp__sub_8264F830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F994) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264F994) {
	__imp__sub_8264F994(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264F998) {
	__imp__sub_8264F998(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264F9A8) {
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
	ctx.lr = 0x8264F9B0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,102(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 102);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264f9cc
	if (cr6.eq) goto loc_8264F9CC;
loc_8264F9C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8264F9CC:
	// lhz r11,72(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 72);
	// addi r29,r3,68
	r29.s64 = ctx.r3.s64 + 68;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fa1c
	if (cr6.eq) goto loc_8264FA1C;
	// li r31,0
	r31.s64 = 0;
loc_8264F9E4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,612(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 612);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264F9FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8264f9c0
	if (!cr6.eq) goto loc_8264F9C0;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8264f9e4
	if (cr6.lt) goto loc_8264F9E4;
loc_8264FA1C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6432);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8264FA38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,612(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 612);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8264FA4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r3,r4,1
	ctx.r3.u64 = ctx.r4.u64 ^ 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8264F9A8) {
	__imp__sub_8264F9A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264FA64) {
	__imp__sub_8264FA64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FA68) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8264FA70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fc14
	if (cr6.eq) goto loc_8264FC14;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264fab8
	if (cr6.eq) goto loc_8264FAB8;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8264fad4
	if (!cr6.gt) goto loc_8264FAD4;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8264fac8
	goto loc_8264FAC8;
loc_8264FAB8:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8264fad4
	if (!cr6.gt) goto loc_8264FAD4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8264FAC8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8264fad8
	if (!cr6.eq) goto loc_8264FAD8;
loc_8264FAD4:
	// li r11,0
	r11.s64 = 0;
loc_8264FAD8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fc14
	if (cr6.eq) goto loc_8264FC14;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264FAF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8264fb4c
	if (!cr6.eq) goto loc_8264FB4C;
	// lwz r11,2832(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// addi r31,r30,2832
	r31.s64 = r30.s64 + 2832;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264FB1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264fb4c
	if (cr6.eq) goto loc_8264FB4C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264FB44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8264FB4C:
	// lbz r11,5708(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5708);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8264fd88
	if (cr6.eq) goto loc_8264FD88;
	// addi r11,r29,-14
	r11.s64 = r29.s64 + -14;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x8264fd88
	if (cr6.gt) goto loc_8264FD88;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,-1152
	r12.s64 = r12.s64 + -1152;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-724(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -724);
	// lwz r19,-632(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -632);
	// lwz r19,-632(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -632);
	// lwz r19,-632(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -632);
	// lwz r19,-632(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -632);
	// lwz r19,-992(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -992);
	// lwz r19,-1120(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -1120);
	// lwz r19,-880(r4)
	r19.u64 = PPC_LOAD_U32(ctx.r4.u32 + -880);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,2104
	ctx.r10.s64 = r11.s64 + 2104;
	// lwz r3,-12216(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12216);
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8264fbd8
	if (!cr6.eq) goto loc_8264FBD8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fbd0
	if (cr6.eq) goto loc_8264FBD0;
	// lwz r11,380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8264fbd8
	if (!cr6.eq) goto loc_8264FBD8;
loc_8264FBD0:
	// li r11,1
	r11.s64 = 1;
	// b 0x8264fbdc
	goto loc_8264FBDC;
loc_8264FBD8:
	// li r11,0
	r11.s64 = 0;
loc_8264FBDC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264fc08
	if (!cr6.eq) goto loc_8264FC08;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f0108
	ctx.lr = 0x8264FBF0;
	sub_821F0108(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,5704(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 5704, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8264FC08:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,5704(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 5704, temp.u32);
loc_8264FC14:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,2104
	ctx.r10.s64 = r11.s64 + 2104;
	// lwz r3,-12216(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12216);
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8264fc58
	if (!cr6.eq) goto loc_8264FC58;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fc50
	if (cr6.eq) goto loc_8264FC50;
	// lwz r11,380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8264fc58
	if (!cr6.eq) goto loc_8264FC58;
loc_8264FC50:
	// li r11,1
	r11.s64 = 1;
	// b 0x8264fc5c
	goto loc_8264FC5C;
loc_8264FC58:
	// li r11,0
	r11.s64 = 0;
loc_8264FC5C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8264fc7c
	if (!cr6.eq) goto loc_8264FC7C;
loc_8264FC68:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f0108
	ctx.lr = 0x8264FC70;
	sub_821F0108(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8264FC7C:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821f0270
	ctx.lr = 0x8264FC84;
	sub_821F0270(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32225
	r11.s64 = -2111897600;
	// addi r10,r11,2104
	ctx.r10.s64 = r11.s64 + 2104;
	// lwz r3,-12216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12216);
	// lwz r11,376(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x8264fcc8
	if (!cr6.eq) goto loc_8264FCC8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fcc0
	if (cr6.eq) goto loc_8264FCC0;
	// lwz r11,380(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8264fcc8
	if (!cr6.eq) goto loc_8264FCC8;
loc_8264FCC0:
	// li r11,1
	r11.s64 = 1;
	// b 0x8264fccc
	goto loc_8264FCCC;
loc_8264FCC8:
	// li r11,0
	r11.s64 = 0;
loc_8264FCCC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fc68
	if (cr6.eq) goto loc_8264FC68;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-13372
	ctx.r4.s64 = ctx.r9.s64 + -13372;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// lwz r30,48(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82218310
	ctx.lr = 0x8264FCF8;
	sub_82218310(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f1,30712(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82208930
	ctx.lr = 0x8264FD14;
	sub_82208930(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-12216(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -12216);
	// bl 0x821ef878
	ctx.lr = 0x8264FD20;
	sub_821EF878(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
	// lbz r11,2816(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 2816);
	// addi r3,r30,2624
	ctx.r3.s64 = r30.s64 + 2624;
	// rlwinm r10,r11,26,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 26) & 0x1;
	// xori r4,r10,1
	ctx.r4.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8264e528
	ctx.lr = 0x8264FD40;
	sub_8264E528(ctx, base);
	// lwz r9,2832(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 2832);
	// addi r3,r30,2832
	ctx.r3.s64 = r30.s64 + 2832;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8264FD54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8264fd88
	if (!cr6.eq) goto loc_8264FD88;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// ori r8,r10,3600
	ctx.r8.u64 = ctx.r10.u64 | 3600;
	// addi r4,r9,-13392
	ctx.r4.s64 = ctx.r9.s64 + -13392;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// lwzx r3,r11,r8
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// bl 0x82696c88
	ctx.lr = 0x8264FD80;
	sub_82696C88(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8264FD88:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264FD9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8264fdb4
	if (!cr6.eq) goto loc_8264FDB4;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8264FDB4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826309e0
	ctx.lr = 0x8264FDC4;
	sub_826309E0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8264FA68) {
	__imp__sub_8264FA68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264FDCC) {
	__imp__sub_8264FDCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FDD0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8264FDD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fefc
	if (cr6.eq) goto loc_8264FEFC;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8264fe20
	if (cr6.eq) goto loc_8264FE20;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8264fe3c
	if (!cr6.gt) goto loc_8264FE3C;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8264fe30
	goto loc_8264FE30;
loc_8264FE20:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8264fe3c
	if (!cr6.gt) goto loc_8264FE3C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8264FE30:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8264fe40
	if (!cr6.eq) goto loc_8264FE40;
loc_8264FE3C:
	// li r11,0
	r11.s64 = 0;
loc_8264FE40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8264fefc
	if (cr6.eq) goto loc_8264FEFC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264FE60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8264fefc
	if (cr6.eq) goto loc_8264FEFC;
	// cmpwi cr6,r30,20
	cr6.compare<int32_t>(r30.s32, 20, xer);
	// bne cr6,0x8264fefc
	if (!cr6.eq) goto loc_8264FEFC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,5704(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 5704);
	f0.f64 = double(temp.f32);
	// lfs f11,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// beq cr6,0x8264fefc
	if (cr6.eq) goto loc_8264FEFC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f12,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f0,5704(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 5704, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// blt cr6,0x8264fefc
	if (cr6.lt) goto loc_8264FEFC;
	// stfs f11,5704(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 5704, temp.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-13372
	ctx.r4.s64 = ctx.r9.s64 + -13372;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// lwz r28,48(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82218310
	ctx.lr = 0x8264FED0;
	sub_82218310(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lfs f1,30712(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r6,-1
	ctx.r6.s64 = -1;
	// bl 0x82208930
	ctx.lr = 0x8264FEEC;
	sub_82208930(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-12216(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12216);
	// bl 0x821ef878
	ctx.lr = 0x8264FEFC;
	sub_821EF878(ctx, base);
loc_8264FEFC:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630aa8
	ctx.lr = 0x8264FF0C;
	sub_82630AA8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8264FDD0) {
	__imp__sub_8264FDD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264FF14) {
	__imp__sub_8264FF14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FF18) {
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
	// bl 0x8264f830
	ctx.lr = 0x8264FF28;
	sub_8264F830(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264FF38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264FF18) {
	__imp__sub_8264FF18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FF48) {
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
	// bl 0x8263ad60
	ctx.lr = 0x8264FF60;
	sub_8263AD60(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-13340
	ctx.r9.s64 = r11.s64 + -13340;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r10,56(r31)
	PPC_STORE_U8(r31.u32 + 56, ctx.r10.u8);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stw r8,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r8.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r9,r5,-14596
	ctx.r9.s64 = ctx.r5.s64 + -14596;
	// lwz r3,2832(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2832);
	// addi r8,r4,-14960
	ctx.r8.s64 = ctx.r4.s64 + -14960;
	// addi r6,r31,56
	ctx.r6.s64 = r31.s64 + 56;
	// addi r5,r11,-13360
	ctx.r5.s64 = r11.s64 + -13360;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82202b98
	ctx.lr = 0x8264FFAC;
	sub_82202B98(ctx, base);
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

PPC_WEAK_FUNC(sub_8264FF48) {
	__imp__sub_8264FF48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264FFC4) {
	__imp__sub_8264FFC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FFC8) {
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
	// bl 0x8263b288
	ctx.lr = 0x8264FFD8;
	sub_8263B288(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// stfs f0,10660(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 10660, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8264FFC8) {
	__imp__sub_8264FFC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8264FFFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8264FFFC) {
	__imp__sub_8264FFFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650000) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-21704
	ctx.r3.s64 = r11.s64 + -21704;
	// bl 0x821fa230
	ctx.lr = 0x82650020;
	sub_821FA230(ctx, base);
	// stb r31,56(r3)
	PPC_STORE_U8(ctx.r3.u32 + 56, r31.u8);
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

PPC_WEAK_FUNC(sub_82650000) {
	__imp__sub_82650000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82650040;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r21,-32121
	r21.s64 = -2105081856;
	// lwz r3,-6148(r21)
	ctx.r3.u64 = PPC_LOAD_U32(r21.u32 + -6148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82650078
	if (cr6.eq) goto loc_82650078;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82650078
	if (cr6.eq) goto loc_82650078;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82252e10
	ctx.lr = 0x8265006C;
	sub_82252E10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_82650078:
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// lis r8,1
	ctx.r8.s64 = 65536;
	// ori r7,r9,6108
	ctx.r7.u64 = ctx.r9.u64 | 6108;
	// lwz r11,-10236(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10236);
	// ori r30,r8,16256
	r30.u64 = ctx.r8.u64 | 16256;
	// lwz r10,-10028(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// li r4,109
	ctx.r4.s64 = 109;
	// li r25,0
	r25.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// li r26,0
	r26.s64 = 0;
	// lwzx r28,r10,r7
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// add r3,r6,r30
	ctx.r3.u64 = ctx.r6.u64 + r30.u64;
	// lwz r22,52(r11)
	r22.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82641cb0
	ctx.lr = 0x826500C0;
	sub_82641CB0(ctx, base);
	// addi r31,r3,2832
	r31.s64 = ctx.r3.s64 + 2832;
	// bl 0x82387a18
	ctx.lr = 0x826500C8;
	sub_82387A18(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82650100
	if (cr6.eq) goto loc_82650100;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826500E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82650100
	if (cr6.eq) goto loc_82650100;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_82650100:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826501c0
	if (cr6.eq) goto loc_826501C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265011C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826501c0
	if (cr6.eq) goto loc_826501C0;
	// addic. r11,r28,538
	xer.ca = r28.u32 > 4294966757;
	r11.s64 = r28.s64 + 538;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x82650140
	if (cr0.eq) goto loc_82650140;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82650144
	if (!cr6.eq) goto loc_82650144;
loc_82650140:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82650144:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// clrlwi r26,r10,24
	r26.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x826501c0
	if (cr6.gt) goto loc_826501C0;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,364
	r12.s64 = r12.s64 + 364;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,380(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 380);
	// lwz r19,436(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 436);
	// lwz r19,436(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 436);
	// lwz r19,444(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 444);
	// lbz r11,789(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 789);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82650190
	if (!cr6.eq) goto loc_82650190;
	// li r25,1
	r25.s64 = 1;
	// b 0x826501c0
	goto loc_826501C0;
loc_82650190:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,616(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 616);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826501B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x826501c0
	goto loc_826501C0;
	// li r24,1
	r24.s64 = 1;
	// b 0x826501c0
	goto loc_826501C0;
	// li r23,1
	r23.s64 = 1;
loc_826501C0:
	// bl 0x82387a18
	ctx.lr = 0x826501C4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r31,r22,4
	r31.s64 = r22.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x826501e4
	if (cr6.eq) goto loc_826501E4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2012
	ctx.r4.s64 = r11.s64 + -2012;
	// b 0x826503ac
	goto loc_826503AC;
loc_826501E4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r11,-18800
	r29.s64 = r11.s64 + -18800;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82691650
	ctx.lr = 0x826501F4;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265021c
	if (cr6.eq) goto loc_8265021C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-18820
	ctx.r4.s64 = r11.s64 + -18820;
	// b 0x826503a8
	goto loc_826503A8;
loc_8265021C:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82650260
	if (cr6.eq) goto loc_82650260;
	// lwz r11,-10236(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10236);
	// li r4,17
	ctx.r4.s64 = 17;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8265023C;
	sub_82641CB0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stb r10,8532(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8532, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-12776
	ctx.r4.s64 = ctx.r9.s64 + -12776;
	// bl 0x82691650
	ctx.lr = 0x82650254;
	sub_82691650(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82204450
	ctx.lr = 0x8265025C;
	sub_82204450(ctx, base);
	// b 0x826503b4
	goto loc_826503B4;
loc_82650260:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826502c0
	if (cr6.eq) goto loc_826502C0;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826503f4
	if (cr6.eq) goto loc_826503F4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82650284;
	sub_821E6800(ctx, base);
	// bl 0x822166e8
	ctx.lr = 0x82650288;
	sub_822166E8(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x8265028C;
	sub_82215A60(ctx, base);
	// addi r3,r28,26
	ctx.r3.s64 = r28.s64 + 26;
	// bl 0x826c5850
	ctx.lr = 0x82650294;
	sub_826C5850(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82204450
	ctx.lr = 0x8265029C;
	sub_82204450(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,-19924
	ctx.r4.s64 = ctx.r9.s64 + -19924;
	// lwz r3,-10224(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826502B4;
	sub_8268B770(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_826502C0:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82650320
	if (cr6.eq) goto loc_82650320;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826503f4
	if (cr6.eq) goto loc_826503F4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826502E4;
	sub_821E6800(ctx, base);
	// bl 0x822166e8
	ctx.lr = 0x826502E8;
	sub_822166E8(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x826502EC;
	sub_82215A60(ctx, base);
	// bl 0x82204450
	ctx.lr = 0x826502F0;
	sub_82204450(ctx, base);
	// lwz r11,-10236(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10236);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18792
	ctx.r4.s64 = ctx.r10.s64 + -18792;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r31,12(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8265030C;
	sub_82691650(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8262ce00
	ctx.lr = 0x82650314;
	sub_8262CE00(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
loc_82650320:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-12796
	ctx.r3.s64 = r11.s64 + -12796;
	// bl 0x821fa230
	ctx.lr = 0x8265032C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265033C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82650354
	if (cr6.eq) goto loc_82650354;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,-12820
	ctx.r4.s64 = r11.s64 + -12820;
	// b 0x826503a8
	goto loc_826503A8;
loc_82650354:
	// bl 0x82256058
	ctx.lr = 0x82650358;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82650384
	if (cr6.eq) goto loc_82650384;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821fa230
	ctx.lr = 0x82650368;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82650394
	if (!cr6.eq) goto loc_82650394;
loc_82650384:
	// lwz r11,-6148(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + -6148);
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826503a0
	if (cr6.eq) goto loc_826503A0;
loc_82650394:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-18820
	ctx.r4.s64 = r11.s64 + -18820;
	// b 0x826503a8
	goto loc_826503A8;
loc_826503A0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-18844
	ctx.r4.s64 = r11.s64 + -18844;
loc_826503A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826503AC:
	// bl 0x82691650
	ctx.lr = 0x826503B0;
	sub_82691650(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_826503B4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826503f4
	if (cr6.eq) goto loc_826503F4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826503C8;
	sub_821E6800(ctx, base);
	// bl 0x822166e8
	ctx.lr = 0x826503CC;
	sub_822166E8(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x826503D0;
	sub_82215A60(ctx, base);
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bne cr6,0x826503e0
	if (!cr6.eq) goto loc_826503E0;
	// li r4,0
	ctx.r4.s64 = 0;
loc_826503E0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,348(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 348);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826503F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826503F4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_82650038) {
	__imp__sub_82650038(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650400) {
	PPC_FUNC_PROLOGUE();
	// b 0x8264edb8
	sub_8264EDB8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82650400) {
	__imp__sub_82650400(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82650404) {
	__imp__sub_82650404(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650408) {
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
	// bl 0x82630980
	ctx.lr = 0x82650420;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650440;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r31,76(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265045C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r4,-24980
	ctx.r4.s64 = ctx.r4.s64 + -24980;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82650480;
	sub_825EE0E0(ctx, base);
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

PPC_WEAK_FUNC(sub_82650408) {
	__imp__sub_82650408(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82650494) {
	__imp__sub_82650494(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650498) {
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
	// bl 0x82630980
	ctx.lr = 0x826504B0;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826504D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r31,84(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826504EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r4,-24948
	ctx.r4.s64 = ctx.r4.s64 + -24948;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82650510;
	sub_825EE0E0(ctx, base);
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

PPC_WEAK_FUNC(sub_82650498) {
	__imp__sub_82650498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82650524) {
	__imp__sub_82650524(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650528) {
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
	// bl 0x82630980
	ctx.lr = 0x82650540;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r31,80(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265057C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r4,-24964
	ctx.r4.s64 = ctx.r4.s64 + -24964;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x826505A0;
	sub_825EE0E0(ctx, base);
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

PPC_WEAK_FUNC(sub_82650528) {
	__imp__sub_82650528(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826505B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826505B4) {
	__imp__sub_826505B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826505B8) {
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
	// bl 0x82630980
	ctx.lr = 0x826505D0;
	sub_82630980(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826505E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82650604
	if (cr6.eq) goto loc_82650604;
	// lbz r11,176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// li r31,1
	r31.s64 = 1;
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82650608
	if (cr6.eq) goto loc_82650608;
loc_82650604:
	// li r31,0
	r31.s64 = 0;
loc_82650608:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r31,24
	ctx.r8.u64 = r31.u32 & 0xFF;
	// lwz r7,116(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// cntlzw r5,r8
	ctx.r5.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addi r4,r6,-24900
	ctx.r4.s64 = ctx.r6.s64 + -24900;
	// rlwinm r3,r5,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r5,r3,1
	ctx.r5.u64 = ctx.r3.u64 ^ 1;
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x825ee0e0
	ctx.lr = 0x8265064C;
	sub_825EE0E0(ctx, base);
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

PPC_WEAK_FUNC(sub_826505B8) {
	__imp__sub_826505B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650660) {
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
	// bl 0x82630980
	ctx.lr = 0x82650678;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650698;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r31,96(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826506B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r4,-24932
	ctx.r4.s64 = ctx.r4.s64 + -24932;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x826506D8;
	sub_825EE0E0(ctx, base);
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

PPC_WEAK_FUNC(sub_82650660) {
	__imp__sub_82650660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826506EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826506EC) {
	__imp__sub_826506EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826506F0) {
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
	// bl 0x82630980
	ctx.lr = 0x82650708;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,796(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 796);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82650748
	if (cr6.eq) goto loc_82650748;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650738;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8265074c
	if (!cr6.eq) goto loc_8265074C;
loc_82650748:
	// li r31,0
	r31.s64 = 0;
loc_8265074C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-19636
	ctx.r4.s64 = ctx.r10.s64 + -19636;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82650760;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,-12724
	ctx.r4.s64 = ctx.r9.s64 + -12724;
	// bl 0x825ee0e0
	ctx.lr = 0x82650774;
	sub_825EE0E0(ctx, base);
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

PPC_WEAK_FUNC(sub_826506F0) {
	__imp__sub_826506F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650788) {
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
	ctx.lr = 0x82650790;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x8265079C;
	sub_82630980(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-19636
	ctx.r4.s64 = r11.s64 + -19636;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826507B0;
	sub_821F9FB8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-18780
	ctx.r4.s64 = ctx.r9.s64 + -18780;
	// lwz r26,56(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x821f9fb8
	ctx.lr = 0x826507C8;
	sub_821F9FB8(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lwz r29,-5052(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + -5052);
	// bl 0x82256058
	ctx.lr = 0x826507D8;
	sub_82256058(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r31,r7,5996
	r31.s64 = ctx.r7.s64 + 5996;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x826507F0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x82650800;
	sub_825ED480(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82650ba4
	if (cr6.eq) goto loc_82650BA4;
	// bl 0x825ef9f0
	ctx.lr = 0x8265080C;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82650b2c
	if (cr6.eq) goto loc_82650B2C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82650b2c
	if (cr6.eq) goto loc_82650B2C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82650b2c
	if (cr6.eq) goto loc_82650B2C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,676(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 676);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650860;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82650b2c
	if (!cr6.eq) goto loc_82650B2C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e0b0
	ctx.lr = 0x8265087C;
	sub_8227E0B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82257160
	ctx.lr = 0x8265088C;
	sub_82257160(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82257160
	ctx.lr = 0x8265089C;
	sub_82257160(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r29,0
	r29.s64 = 0;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x826508b4
	if (!cr6.lt) goto loc_826508B4;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
loc_826508B4:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x826508c0
	if (!cr6.lt) goto loc_826508C0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
loc_826508C0:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826509e4
	if (cr6.eq) goto loc_826509E4;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r25,1
	r25.s64 = 1;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r29,r11,2520
	r29.s64 = r11.s64 + 2520;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82202fb8
	ctx.lr = 0x826508F0;
	sub_82202FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8265090C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82650ba4
	if (cr6.eq) goto loc_82650BA4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef808
	ctx.lr = 0x82650920;
	sub_825EF808(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r3,-2
	ctx.r10.s64 = ctx.r3.s64 + -2;
	// addi r27,r11,2544
	r27.s64 = r11.s64 + 2544;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x825ee0e0
	ctx.lr = 0x82650944;
	sub_825EE0E0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef808
	ctx.lr = 0x8265094C;
	sub_825EF808(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8265095C;
	sub_825EE0E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// bne cr6,0x8265096c
	if (!cr6.eq) goto loc_8265096C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
loc_8265096C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-12608
	ctx.r4.s64 = ctx.r10.s64 + -12608;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650988;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bne cr6,0x82650998
	if (!cr6.eq) goto loc_82650998;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
loc_82650998:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-12624
	ctx.r4.s64 = ctx.r10.s64 + -12624;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826509B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r25,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r25.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826509D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-24900
	ctx.r4.s64 = ctx.r6.s64 + -24900;
	// b 0x82650b88
	goto loc_82650B88;
loc_826509E4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,2544
	r30.s64 = r11.s64 + 2544;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826509FC;
	sub_825EE0E0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2520
	ctx.r4.s64 = r11.s64 + 2520;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650A10;
	sub_825EE0E0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82650A1C;
	sub_822A39C8(ctx, base);
	// bl 0x822a5df8
	ctx.lr = 0x82650A20;
	sub_822A5DF8(ctx, base);
	// lwz r9,3100(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 3100);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r9,13
	cr6.compare<int32_t>(ctx.r9.s32, 13, xer);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// bne cr6,0x82650a64
	if (!cr6.eq) goto loc_82650A64;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r27,r11,27816
	r27.s64 = r11.s64 + 27816;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8223de50
	ctx.lr = 0x82650A44;
	sub_8223DE50(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r10,-12632
	ctx.r4.s64 = ctx.r10.s64 + -12632;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x82650A58;
	sub_825EE2D8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-12652
	ctx.r4.s64 = ctx.r9.s64 + -12652;
	// b 0x82650ae8
	goto loc_82650AE8;
loc_82650A64:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r4,r10,-12660
	ctx.r4.s64 = ctx.r10.s64 + -12660;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82650A7C;
	sub_82218310(ctx, base);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r25,r9,27816
	r25.s64 = ctx.r9.s64 + 27816;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r5,r8,2460
	ctx.r5.s64 = ctx.r8.s64 + 2460;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// bl 0x82137a08
	ctx.lr = 0x82650AA0;
	sub_82137A08(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r7,-12672
	ctx.r4.s64 = ctx.r7.s64 + -12672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,52(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82650AC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r10,-12608
	ctx.r4.s64 = ctx.r10.s64 + -12608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82650AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r4,r7,-12688
	ctx.r4.s64 = ctx.r7.s64 + -12688;
loc_82650AE8:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650AF4;
	sub_825EE0E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82650B24;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
loc_82650B2C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r30,r10,2544
	r30.s64 = ctx.r10.s64 + 2544;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,44(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82650B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650B68;
	sub_825EE0E0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-12652
	ctx.r4.s64 = ctx.r7.s64 + -12652;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650B7C;
	sub_825EE0E0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-12712
	ctx.r4.s64 = ctx.r6.s64 + -12712;
loc_82650B88:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82650B90;
	sub_825EE0E0(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r4,r4,-12688
	ctx.r4.s64 = ctx.r4.s64 + -12688;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82650BA4;
	sub_825EE0E0(ctx, base);
loc_82650BA4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82650788) {
	__imp__sub_82650788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650BAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82650BAC) {
	__imp__sub_82650BAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650BB0) {
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
	ctx.lr = 0x82650BB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x82650BC4;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-11876
	ctx.r4.s64 = ctx.r10.s64 + -11876;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82650BD8;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r9,-13532
	r31.s64 = ctx.r9.s64 + -13532;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r28,56(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82650BF4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x82650C04;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x82650C08;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82650C20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82650d44
	if (cr6.eq) goto loc_82650D44;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82720e28
	ctx.lr = 0x82650C38;
	sub_82720E28(ctx, base);
	// lbz r10,100(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 100);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// addi r4,r11,-12556
	ctx.r4.s64 = r11.s64 + -12556;
	// rlwinm r5,r9,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x825ee230
	ctx.lr = 0x82650C54;
	sub_825EE230(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r5,r30,772
	ctx.r5.s64 = r30.s64 + 772;
	// addi r4,r8,-12564
	ctx.r4.s64 = ctx.r8.s64 + -12564;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,44(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82650C74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82387a18
	ctx.lr = 0x82650C78;
	sub_82387A18(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82650c90
	if (cr6.eq) goto loc_82650C90;
	// addi r5,r30,448
	ctx.r5.s64 = r30.s64 + 448;
	// b 0x82650ca0
	goto loc_82650CA0;
loc_82650C90:
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// lwz r4,780(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 780);
	// bl 0x82218310
	ctx.lr = 0x82650C9C;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_82650CA0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-2948
	ctx.r4.s64 = ctx.r10.s64 + -2948;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82650CBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// lwz r4,776(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 776);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82218310
	ctx.lr = 0x82650CCC;
	sub_82218310(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lwz r7,52(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 52);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,-12576
	ctx.r4.s64 = ctx.r8.s64 + -12576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82650CE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-10244(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10244);
	// lwz r4,784(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 784);
	// lwz r28,0(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82218310
	ctx.lr = 0x82650CF8;
	sub_82218310(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lwz r11,52(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 52);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-10292
	ctx.r4.s64 = ctx.r6.s64 + -10292;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82650D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,784(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 784);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r10,-12592
	ctx.r4.s64 = ctx.r10.s64 + -12592;
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// extsb r7,r8
	ctx.r7.s64 = ctx.r8.s8;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// bl 0x825ee230
	ctx.lr = 0x82650D3C;
	sub_825EE230(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82650D44:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r11,3998
	ctx.r9.s64 = r11.s64 + 3998;
	// addi r4,r10,-2948
	ctx.r4.s64 = ctx.r10.s64 + -2948;
	// stw r9,780(r30)
	PPC_STORE_U32(r30.u32 + 780, ctx.r9.u32);
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// stw r9,776(r30)
	PPC_STORE_U32(r30.u32 + 776, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,784(r30)
	PPC_STORE_U32(r30.u32 + 784, ctx.r9.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82650D78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lwz r5,776(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 776);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r6,-12576
	ctx.r4.s64 = ctx.r6.s64 + -12576;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650D98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r5,784(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 784);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r9,-10292
	ctx.r4.s64 = ctx.r9.s64 + -10292;
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82650DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r6,-12556
	ctx.r4.s64 = ctx.r6.s64 + -12556;
	// bl 0x825ee230
	ctx.lr = 0x82650DCC;
	sub_825EE230(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82720560
	ctx.lr = 0x82650DD4;
	sub_82720560(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82650BB0) {
	__imp__sub_82650BB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82650DDC) {
	__imp__sub_82650DDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650DE0) {
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
	ctx.lr = 0x82650DE8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826337a8
	ctx.lr = 0x82650DF4;
	sub_826337A8(ctx, base);
	// lbz r9,176(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-12516
	ctx.r10.s64 = r11.s64 + -12516;
	// clrlwi r8,r9,26
	ctx.r8.u64 = ctx.r9.u32 & 0x3F;
	// stw r30,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r30.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// li r4,64
	ctx.r4.s64 = 64;
	// stb r8,176(r31)
	PPC_STORE_U8(r31.u32 + 176, ctx.r8.u8);
	// addi r3,r31,468
	ctx.r3.s64 = r31.s64 + 468;
	// bl 0x827264f8
	ctx.lr = 0x82650E20;
	sub_827264F8(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stb r30,768(r31)
	PPC_STORE_U8(r31.u32 + 768, r30.u8);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r30,772(r31)
	PPC_STORE_U32(r31.u32 + 772, r30.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r30,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r30.u32);
	// addi r3,r5,3998
	ctx.r3.s64 = ctx.r5.s64 + 3998;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r4,788(r31)
	PPC_STORE_U8(r31.u32 + 788, ctx.r4.u8);
	// lfs f13,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// stw r3,776(r31)
	PPC_STORE_U32(r31.u32 + 776, ctx.r3.u32);
	// stfs f0,792(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 792, temp.u32);
	// stw r3,780(r31)
	PPC_STORE_U32(r31.u32 + 780, ctx.r3.u32);
	// stfs f13,800(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 800, temp.u32);
	// stw r3,784(r31)
	PPC_STORE_U32(r31.u32 + 784, ctx.r3.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-11876
	ctx.r4.s64 = ctx.r10.s64 + -11876;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82650E74;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82650e8c
	if (cr6.eq) goto loc_82650E8C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,56(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82630c38
	ctx.lr = 0x82650E8C;
	sub_82630C38(ctx, base);
loc_82650E8C:
	// stb r30,192(r31)
	PPC_STORE_U8(r31.u32 + 192, r30.u8);
	// li r3,32
	ctx.r3.s64 = 32;
	// stb r30,448(r31)
	PPC_STORE_U8(r31.u32 + 448, r30.u8);
	// bl 0x82130528
	ctx.lr = 0x82650E9C;
	sub_82130528(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r29,r11,-12536
	r29.s64 = r11.s64 + -12536;
	// beq cr6,0x82650ec0
	if (cr6.eq) goto loc_82650EC0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r5,472(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 472);
	// bl 0x8218fad0
	ctx.lr = 0x82650EB8;
	sub_8218FAD0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x82650ec4
	goto loc_82650EC4;
loc_82650EC0:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
loc_82650EC4:
	// stw r5,464(r31)
	PPC_STORE_U32(r31.u32 + 464, ctx.r5.u32);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x82650ED8;
	sub_82182150(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262fd60
	ctx.lr = 0x82650EE4;
	sub_8262FD60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82650DE0) {
	__imp__sub_82650DE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650EF0) {
	PPC_FUNC_PROLOGUE();
	// stw r5,772(r3)
	PPC_STORE_U32(ctx.r3.u32 + 772, ctx.r5.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82650EF0) {
	__imp__sub_82650EF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650EF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,772(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 772);
	// stw r11,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82650EF8) {
	__imp__sub_82650EF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650F04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82650F04) {
	__imp__sub_82650F04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650F08) {
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
	// addi r3,r31,468
	ctx.r3.s64 = r31.s64 + 468;
	// bl 0x82726128
	ctx.lr = 0x82650F2C;
	sub_82726128(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82650F34;
	sub_82633B00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82650f4c
	if (cr6.eq) goto loc_82650F4C;
	// bl 0x82130588
	ctx.lr = 0x82650F48;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82650F4C:
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

PPC_WEAK_FUNC(sub_82650F08) {
	__imp__sub_82650F08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82650F64) {
	__imp__sub_82650F64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650F68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82650F70;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r4,r9,-11876
	ctx.r4.s64 = ctx.r9.s64 + -11876;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,792(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 792, temp.u32);
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82650F98;
	sub_821F9FB8(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r30,r8,-13532
	r30.s64 = ctx.r8.s64 + -13532;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r7)
	r29.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82650FB4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x82650FC4;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x82650FC8;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r6,-11112
	ctx.r4.s64 = ctx.r6.s64 + -11112;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82650FE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82650F68) {
	__imp__sub_82650F68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82650FEC) {
	__imp__sub_82650FEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82650FF0) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,-10244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826510d4
	if (cr6.eq) goto loc_826510D4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-19636
	ctx.r4.s64 = ctx.r10.s64 + -19636;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8265102C;
	sub_821F9FB8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,3
	cr6.compare<uint32_t>(r30.u32, 3, xer);
	// bgt cr6,0x826510d4
	if (cr6.gt) goto loc_826510D4;
	// lis r12,-32155
	r12.s64 = -2107310080;
	// addi r12,r12,4176
	r12.s64 = r12.s64 + 4176;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,4192(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4192);
	// lwz r19,4224(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4224);
	// lwz r19,4256(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4256);
	// lwz r19,4268(r5)
	r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4268);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// lwz r31,56(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r4,r10,-11800
	ctx.r4.s64 = ctx.r10.s64 + -11800;
	// bl 0x82218310
	ctx.lr = 0x82651074;
	sub_82218310(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-11820
	ctx.r4.s64 = ctx.r9.s64 + -11820;
	// b 0x826510c8
	goto loc_826510C8;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// lwz r31,56(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// addi r4,r10,-11840
	ctx.r4.s64 = ctx.r10.s64 + -11840;
	// bl 0x82218310
	ctx.lr = 0x82651094;
	sub_82218310(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-11820
	ctx.r4.s64 = ctx.r9.s64 + -11820;
	// b 0x826510c8
	goto loc_826510C8;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,-11868
	ctx.r4.s64 = ctx.r10.s64 + -11868;
	// b 0x826510b4
	goto loc_826510B4;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-11900
	ctx.r4.s64 = ctx.r10.s64 + -11900;
loc_826510B4:
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// lwz r31,56(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82218310
	ctx.lr = 0x826510C0;
	sub_82218310(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-11916
	ctx.r4.s64 = ctx.r9.s64 + -11916;
loc_826510C8:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x826510D4;
	sub_825EE2D8(ctx, base);
loc_826510D4:
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

PPC_WEAK_FUNC(sub_82650FF0) {
	__imp__sub_82650FF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826510EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826510EC) {
	__imp__sub_826510EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826510F0) {
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
	ctx.lr = 0x826510F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x82651104;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18780
	ctx.r4.s64 = ctx.r10.s64 + -18780;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82651118;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651130;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82651230
	if (cr6.eq) goto loc_82651230;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82651230
	if (!cr6.eq) goto loc_82651230;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720e28
	ctx.lr = 0x82651168;
	sub_82720E28(ctx, base);
	// lbz r11,192(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 192);
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826511e8
	if (cr6.eq) goto loc_826511E8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r4,r11,-11728
	ctx.r4.s64 = r11.s64 + -11728;
	// bl 0x825ee0e0
	ctx.lr = 0x8265118C;
	sub_825EE0E0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r4,r10,-11744
	ctx.r4.s64 = ctx.r10.s64 + -11744;
	// bl 0x825ee0e0
	ctx.lr = 0x826511A0;
	sub_825EE0E0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,332(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 332);
	// lwz r29,56(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826511B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-11760
	ctx.r4.s64 = ctx.r7.s64 + -11760;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x826511CC;
	sub_825EE2D8(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lwz r5,200(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// addi r4,r6,-11776
	ctx.r4.s64 = ctx.r6.s64 + -11776;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x825ee2d8
	ctx.lr = 0x826511E0;
	sub_825EE2D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826511E8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-11744
	ctx.r4.s64 = r11.s64 + -11744;
	// bl 0x825ee0e0
	ctx.lr = 0x826511F8;
	sub_825EE0E0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r31,r10,3998
	r31.s64 = ctx.r10.s64 + 3998;
	// addi r4,r9,-11760
	ctx.r4.s64 = ctx.r9.s64 + -11760;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x82651214;
	sub_825EE2D8(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r4,r8,-11776
	ctx.r4.s64 = ctx.r8.s64 + -11776;
	// bl 0x825ee2d8
	ctx.lr = 0x82651228;
	sub_825EE2D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82651230:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720560
	ctx.lr = 0x82651238;
	sub_82720560(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826510F0) {
	__imp__sub_826510F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x82630980
	ctx.lr = 0x8265125C;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265127C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r30,56(r7)
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651298;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r4,r4,-11640
	ctx.r4.s64 = ctx.r4.s64 + -11640;
	// xori r5,r10,1
	ctx.r5.u64 = ctx.r10.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x826512B8;
	sub_825EE0E0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,192(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r9,-11656
	ctx.r4.s64 = ctx.r9.s64 + -11656;
	// bl 0x825ee188
	ctx.lr = 0x826512CC;
	sub_825EE188(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r8,-11676
	ctx.r4.s64 = ctx.r8.s64 + -11676;
	// bl 0x825ee188
	ctx.lr = 0x826512E0;
	sub_825EE188(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r4,r6,-11700
	ctx.r4.s64 = ctx.r6.s64 + -11700;
	// lwz r3,-10244(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826512F4;
	sub_82218310(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-11712
	ctx.r4.s64 = ctx.r4.s64 + -11712;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x82651308;
	sub_825EE2D8(ctx, base);
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

PPC_WEAK_FUNC(sub_82651240) {
	__imp__sub_82651240(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651320) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x82630980
	ctx.lr = 0x8265133C;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265135C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,56(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lwz r5,208(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,-11552
	ctx.r4.s64 = ctx.r8.s64 + -11552;
	// bl 0x825ee0e0
	ctx.lr = 0x82651374;
	sub_825EE0E0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,192(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r7,-11568
	ctx.r4.s64 = ctx.r7.s64 + -11568;
	// bl 0x825ee188
	ctx.lr = 0x82651388;
	sub_825EE188(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// addi r4,r6,-11584
	ctx.r4.s64 = ctx.r6.s64 + -11584;
	// bl 0x825ee0e0
	ctx.lr = 0x8265139C;
	sub_825EE0E0(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,200(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// addi r4,r4,-11600
	ctx.r4.s64 = ctx.r4.s64 + -11600;
	// bl 0x825ee0e0
	ctx.lr = 0x826513B0;
	sub_825EE0E0(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,204(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 204);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r11,-11620
	ctx.r4.s64 = r11.s64 + -11620;
	// bl 0x825ee188
	ctx.lr = 0x826513C4;
	sub_825EE188(ctx, base);
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

PPC_WEAK_FUNC(sub_82651320) {
	__imp__sub_82651320(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826513DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826513DC) {
	__imp__sub_826513DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826513E0) {
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
	// bl 0x82630980
	ctx.lr = 0x826513F8;
	sub_82630980(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651418;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,60(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// lwz r31,92(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// addi r4,r4,-24916
	ctx.r4.s64 = ctx.r4.s64 + -24916;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r5,r9,1
	ctx.r5.u64 = ctx.r9.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82651458;
	sub_825EE0E0(ctx, base);
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

PPC_WEAK_FUNC(sub_826513E0) {
	__imp__sub_826513E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265146C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265146C) {
	__imp__sub_8265146C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651470) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82651478;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265149C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r9,-18780
	ctx.r4.s64 = ctx.r9.s64 + -18780;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x826514B4;
	sub_821F9FB8(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-24916
	ctx.r4.s64 = ctx.r8.s64 + -24916;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x826514CC;
	sub_825EE0E0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r27,r7,-24900
	r27.s64 = ctx.r7.s64 + -24900;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x826514E4;
	sub_825EE0E0(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r6,-27060
	ctx.r4.s64 = ctx.r6.s64 + -27060;
	// bl 0x825ee0e0
	ctx.lr = 0x826514F8;
	sub_825EE0E0(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r4,-11532
	ctx.r4.s64 = ctx.r4.s64 + -11532;
	// bl 0x825ee0e0
	ctx.lr = 0x8265150C;
	sub_825EE0E0(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r11,-11552
	ctx.r4.s64 = r11.s64 + -11552;
	// bl 0x825ee230
	ctx.lr = 0x82651520;
	sub_825EE230(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// addi r4,r10,-25148
	ctx.r4.s64 = ctx.r10.s64 + -25148;
	// bl 0x825ee0e0
	ctx.lr = 0x82651534;
	sub_825EE0E0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// addi r26,r9,2544
	r26.s64 = ctx.r9.s64 + 2544;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8265154C;
	sub_825EE0E0(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 56);
	// addi r4,r8,2520
	ctx.r4.s64 = ctx.r8.s64 + 2520;
	// bl 0x825ee0e0
	ctx.lr = 0x82651560;
	sub_825EE0E0(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r25,r7,5996
	r25.s64 = ctx.r7.s64 + 5996;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r31,56(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82651578;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x82651588;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x8265158C;
	sub_825EF9F0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,44(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826515AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r10,-12652
	ctx.r4.s64 = ctx.r10.s64 + -12652;
	// bl 0x825ee0e0
	ctx.lr = 0x826515C0;
	sub_825EE0E0(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-12712
	ctx.r4.s64 = ctx.r9.s64 + -12712;
	// bl 0x825ee0e0
	ctx.lr = 0x826515D4;
	sub_825EE0E0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r8,-12688
	ctx.r4.s64 = ctx.r8.s64 + -12688;
	// bl 0x825ee0e0
	ctx.lr = 0x826515E8;
	sub_825EE0E0(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r7,-21684
	ctx.r4.s64 = ctx.r7.s64 + -21684;
	// bl 0x825ee0e0
	ctx.lr = 0x826515FC;
	sub_825EE0E0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,24(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82651618;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-24980
	ctx.r4.s64 = r11.s64 + -24980;
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x825ee0e0
	ctx.lr = 0x82651630;
	sub_825EE0E0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265164C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,116(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x825ee0e0
	ctx.lr = 0x82651660;
	sub_825EE0E0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,24(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265167C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,120(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// bl 0x8223dfb0
	ctx.lr = 0x82651688;
	sub_8223DFB0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r5,1
	ctx.r3.s64 = ctx.r5.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x826516A0;
	sub_82641CB0(ctx, base);
	// addi r3,r3,1024
	ctx.r3.s64 = ctx.r3.s64 + 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826516B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,56(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x826516C8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x826516D8;
	sub_825ED480(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r27,r9,-13284
	r27.s64 = ctx.r9.s64 + -13284;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82722678
	ctx.lr = 0x826516F4;
	sub_82722678(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x82651708;
	sub_82722678(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r31,r7,20304
	r31.s64 = ctx.r7.s64 + 20304;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82651728;
	sub_82722678(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x82651738;
	sub_825EE0E0(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r4,r6,-11640
	ctx.r4.s64 = ctx.r6.s64 + -11640;
	// bl 0x825ee0e0
	ctx.lr = 0x8265174C;
	sub_825EE0E0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82720560
	ctx.lr = 0x82651754;
	sub_82720560(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82651470) {
	__imp__sub_82651470(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265175C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265175C) {
	__imp__sub_8265175C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651760) {
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
	ctx.lr = 0x82651768;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-20092
	ctx.r3.s64 = r11.s64 + -20092;
	// bl 0x821fa210
	ctx.lr = 0x8265177C;
	sub_821FA210(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10028(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x8265178C;
	sub_822040F8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826947e0
	ctx.lr = 0x82651798;
	sub_826947E0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cntlzw r8,r3
	ctx.r8.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// xori r28,r7,1
	r28.u64 = ctx.r7.u64 ^ 1;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826517B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826517f8
	if (!cr6.eq) goto loc_826517F8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826517D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826517f8
	if (!cr6.eq) goto loc_826517F8;
	// bl 0x8265eb48
	ctx.lr = 0x826517E8;
	sub_8265EB48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x826517fc
	if (cr6.eq) goto loc_826517FC;
loc_826517F8:
	// li r11,1
	r11.s64 = 1;
loc_826517FC:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// li r31,0
	r31.s64 = 0;
	// bl 0x82256058
	ctx.lr = 0x82651808;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82651838
	if (cr6.eq) goto loc_82651838;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651838
	if (!cr6.eq) goto loc_82651838;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651838
	if (!cr6.eq) goto loc_82651838;
	// bl 0x82387b90
	ctx.lr = 0x8265182C;
	sub_82387B90(ctx, base);
	// lwz r11,1204(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1204);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8265184c
	if (!cr6.eq) goto loc_8265184C;
loc_82651838:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lbz r10,628(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 628);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82651850
	if (cr6.eq) goto loc_82651850;
loc_8265184C:
	// li r31,1
	r31.s64 = 1;
loc_82651850:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651874
	if (!cr6.eq) goto loc_82651874;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651874
	if (!cr6.eq) goto loc_82651874;
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82651880
	if (cr6.eq) goto loc_82651880;
loc_82651874:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82651880:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82651760) {
	__imp__sub_82651760(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265188C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265188C) {
	__imp__sub_8265188C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651890) {
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
	ctx.lr = 0x82651898;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r11,-18780
	ctx.r4.s64 = r11.s64 + -18780;
	// lwz r3,-10236(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826518B4;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826518D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// addis r29,r11,1
	r29.s64 = r11.s64 + 65536;
	// addi r29,r29,16256
	r29.s64 = r29.s64 + 16256;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826518F4;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,72
	ctx.r4.s64 = 72;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82651904;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8264ec10
	ctx.lr = 0x82651910;
	sub_8264EC10(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82720e28
	ctx.lr = 0x82651920;
	sub_82720E28(ctx, base);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8265194C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r10,-20132
	ctx.r4.s64 = ctx.r10.s64 + -20132;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82651968;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,312(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651978;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,2816(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 2816);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// rlwinm r6,r7,0,26,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8265199c
	if (cr6.eq) goto loc_8265199C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720e28
	ctx.lr = 0x82651998;
	sub_82720E28(ctx, base);
	// b 0x826519d8
	goto loc_826519D8;
loc_8265199C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826519d0
	if (!cr6.eq) goto loc_826519D0;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826519d0
	if (!cr6.eq) goto loc_826519D0;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826519d0
	if (!cr6.eq) goto loc_826519D0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720e28
	ctx.lr = 0x826519CC;
	sub_82720E28(ctx, base);
	// b 0x826519d8
	goto loc_826519D8;
loc_826519D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720560
	ctx.lr = 0x826519D8;
	sub_82720560(ctx, base);
loc_826519D8:
	// clrlwi r29,r29,24
	r29.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x826519f4
	if (!cr6.eq) goto loc_826519F4;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826519f8
	if (cr6.eq) goto loc_826519F8;
loc_826519F4:
	// li r30,1
	r30.s64 = 1;
loc_826519F8:
	// lbz r11,896(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 896);
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x82651a1c
	if (cr6.eq) goto loc_82651A1C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82651A1C:
	// stb r30,896(r28)
	PPC_STORE_U8(r28.u32 + 896, r30.u8);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82651a38
	if (!cr6.eq) goto loc_82651A38;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82651a3c
	if (cr6.eq) goto loc_82651A3C;
loc_82651A38:
	// li r11,0
	r11.s64 = 0;
loc_82651A3C:
	// lbz r10,5708(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5708);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// rlwimi r10,r11,7,17,24
	ctx.r10.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0x7F80) | (ctx.r10.u64 & 0xFFFFFFFFFFFF807F);
	// stb r10,5708(r31)
	PPC_STORE_U8(r31.u32 + 5708, ctx.r10.u8);
	// bne cr6,0x82651a6c
	if (!cr6.eq) goto loc_82651A6C;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82651a6c
	if (!cr6.eq) goto loc_82651A6C;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82651a70
	if (cr6.eq) goto loc_82651A70;
loc_82651A6C:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82651A70:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651A84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82651a9c
	if (!cr6.eq) goto loc_82651A9C;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82651aa0
	if (cr6.eq) goto loc_82651AA0;
loc_82651A9C:
	// li r4,1
	ctx.r4.s64 = 1;
loc_82651AA0:
	// lwz r11,2832(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2832);
	// addi r3,r31,2832
	ctx.r3.s64 = r31.s64 + 2832;
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651ACC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,640(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// addi r3,r31,640
	ctx.r3.s64 = r31.s64 + 640;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651AE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,2000(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651AFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,448(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// addi r3,r31,448
	ctx.r3.s64 = r31.s64 + 448;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82651B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,1408(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1408);
	// addi r3,r31,1408
	ctx.r3.s64 = r31.s64 + 1408;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651B2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1216(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1216);
	// addi r3,r31,1216
	ctx.r3.s64 = r31.s64 + 1216;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82651B44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82651b60
	if (cr6.eq) goto loc_82651B60;
	// lwz r11,8(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82651b64
	if (!cr6.eq) goto loc_82651B64;
loc_82651B60:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82651B64:
	// lwz r11,3648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3648);
	// addi r3,r31,3648
	ctx.r3.s64 = r31.s64 + 3648;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651B78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,1024(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651B90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 692);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651BA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lwz r11,-3624(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -3624);
	// lwz r4,700(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r11,796(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 796);
	// addi r3,r31,5472
	ctx.r3.s64 = r31.s64 + 5472;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,5472(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5472);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// bne cr6,0x82651bd4
	if (!cr6.eq) goto loc_82651BD4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82651BD4:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651BDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82651890) {
	__imp__sub_82651890(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82651BE4) {
	__imp__sub_82651BE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651BE8) {
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
	ctx.lr = 0x82651BF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x82651890
	ctx.lr = 0x82651BFC;
	sub_82651890(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651C14;
	sub_82641CB0(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82203f98
	ctx.lr = 0x82651C24;
	sub_82203F98(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82204018
	ctx.lr = 0x82651C34;
	sub_82204018(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82203fd8
	ctx.lr = 0x82651C44;
	sub_82203FD8(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82651c64
	if (cr6.eq) goto loc_82651C64;
	// lwz r11,1808(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651C64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82651C64:
	// lwz r11,2192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651C7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,2400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2400);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651C94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1600(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651CAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,2000(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82651CC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r29,3
	cr6.compare<int32_t>(r29.s32, 3, xer);
	// beq cr6,0x82651cd8
	if (cr6.eq) goto loc_82651CD8;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bne cr6,0x82651cdc
	if (!cr6.eq) goto loc_82651CDC;
loc_82651CD8:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82651CDC:
	// addi r31,r31,832
	r31.s64 = r31.s64 + 832;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82651CFC;
	sub_822040F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82651d1c
	if (cr6.eq) goto loc_82651D1C;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651D1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82651D1C:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82651D24;
	sub_822040F8(ctx, base);
	// lbz r11,176(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 176);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// rlwimi r11,r10,6,25,25
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 6) & 0x40) | (r11.u64 & 0xFFFFFFFFFFFFFFBF);
	// stb r11,176(r31)
	PPC_STORE_U8(r31.u32 + 176, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82651BE8) {
	__imp__sub_82651BE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82651D3C) {
	__imp__sub_82651D3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651D40) {
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
	// bl 0x82651890
	ctx.lr = 0x82651D54;
	sub_82651890(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651D6C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// lwz r10,832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651D88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,5280(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 5280);
	// addi r3,r31,5280
	ctx.r3.s64 = r31.s64 + 5280;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82651DA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1808(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82651DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,2192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82651DD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,2400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2400);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82651DE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,1600(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651E00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1024(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82651E18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_82651D40) {
	__imp__sub_82651D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651E2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82651E2C) {
	__imp__sub_82651E2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651E30) {
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
	// bl 0x82651be8
	ctx.lr = 0x82651E44;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651E5C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// lwz r10,832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651E78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1024(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1024);
	// addi r3,r31,1024
	ctx.r3.s64 = r31.s64 + 1024;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82651E90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_82651E30) {
	__imp__sub_82651E30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82651EA4) {
	__imp__sub_82651EA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651EA8) {
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
	// bl 0x82651be8
	ctx.lr = 0x82651EBC;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651ED4;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// lwz r10,1600(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651EF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,832(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82651F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_82651EA8) {
	__imp__sub_82651EA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82651F1C) {
	__imp__sub_82651F1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651F20) {
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
	ctx.lr = 0x82651F28;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82651be8
	ctx.lr = 0x82651F30;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651F48;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r31,1600
	r30.s64 = r31.s64 + 1600;
	// lwz r29,1600(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// bl 0x8264e598
	ctx.lr = 0x82651F58;
	sub_8264E598(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r9,64(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r8,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651F74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,832(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82651F8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,1808(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82651FA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,2192(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82651FBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82651F20) {
	__imp__sub_82651F20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651FC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82651FC4) {
	__imp__sub_82651FC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82651FC8) {
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
	// bl 0x82651890
	ctx.lr = 0x82651FD8;
	sub_82651890(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82651FF0;
	sub_82641CB0(ctx, base);
	// addi r3,r3,832
	ctx.r3.s64 = ctx.r3.s64 + 832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652008;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82651FC8) {
	__imp__sub_82651FC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652018) {
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
	// bl 0x82651be8
	ctx.lr = 0x8265202C;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82652044;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// lwz r10,832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1600(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1600);
	// addi r3,r31,1600
	ctx.r3.s64 = r31.s64 + 1600;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82652078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_82652018) {
	__imp__sub_82652018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265208C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265208C) {
	__imp__sub_8265208C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652090) {
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
	// bl 0x82651be8
	ctx.lr = 0x826520A0;
	sub_82651BE8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x826520B8;
	sub_82641CB0(ctx, base);
	// addi r3,r3,832
	ctx.r3.s64 = ctx.r3.s64 + 832;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826520D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82652090) {
	__imp__sub_82652090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826520E0) {
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
	// bl 0x82651890
	ctx.lr = 0x826520F4;
	sub_82651890(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8265210C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,832
	ctx.r3.s64 = r31.s64 + 832;
	// lwz r10,832(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 832);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,1808(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 1808);
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82652140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,2000(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2000);
	// addi r3,r31,2000
	ctx.r3.s64 = r31.s64 + 2000;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82652158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,2192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2192);
	// addi r3,r31,2192
	ctx.r3.s64 = r31.s64 + 2192;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,2400(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 2400);
	// addi r3,r31,2400
	ctx.r3.s64 = r31.s64 + 2400;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82652188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_826520E0) {
	__imp__sub_826520E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265219C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265219C) {
	__imp__sub_8265219C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826521A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x826521A8;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,19
	ctx.r5.s64 = 19;
	// addi r4,r11,-10740
	ctx.r4.s64 = r11.s64 + -10740;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633e80
	ctx.lr = 0x826521C4;
	sub_82633E80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r27,r31,256
	r27.s64 = r31.s64 + 256;
	// addi r9,r10,-11508
	ctx.r9.s64 = ctx.r10.s64 + -11508;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x826337a8
	ctx.lr = 0x826521DC;
	sub_826337A8(ctx, base);
	// lbz r6,432(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 432);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// clrlwi r5,r6,26
	ctx.r5.u64 = ctx.r6.u32 & 0x3F;
	// addi r7,r8,-21564
	ctx.r7.s64 = ctx.r8.s64 + -21564;
	// stb r5,432(r31)
	PPC_STORE_U8(r31.u32 + 432, ctx.r5.u8);
	// addi r26,r31,448
	r26.s64 = r31.s64 + 448;
	// stw r7,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r7.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652200;
	sub_826337A8(ctx, base);
	// lbz r10,624(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 624);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// addi r11,r4,-20908
	r11.s64 = ctx.r4.s64 + -20908;
	// stb r9,624(r31)
	PPC_STORE_U8(r31.u32 + 624, ctx.r9.u8);
	// addi r25,r31,640
	r25.s64 = r31.s64 + 640;
	// stw r11,448(r31)
	PPC_STORE_U32(r31.u32 + 448, r11.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652224;
	sub_826337A8(ctx, base);
	// lbz r6,816(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 816);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// clrlwi r5,r6,26
	ctx.r5.u64 = ctx.r6.u32 & 0x3F;
	// addi r7,r8,-20252
	ctx.r7.s64 = ctx.r8.s64 + -20252;
	// stb r5,816(r31)
	PPC_STORE_U8(r31.u32 + 816, ctx.r5.u8);
	// addi r24,r31,832
	r24.s64 = r31.s64 + 832;
	// stw r7,640(r31)
	PPC_STORE_U32(r31.u32 + 640, ctx.r7.u32);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652248;
	sub_826337A8(ctx, base);
	// lbz r10,1008(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1008);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// addi r11,r4,-19596
	r11.s64 = ctx.r4.s64 + -19596;
	// stb r9,1008(r31)
	PPC_STORE_U8(r31.u32 + 1008, ctx.r9.u8);
	// addi r23,r31,1024
	r23.s64 = r31.s64 + 1024;
	// stw r11,832(r31)
	PPC_STORE_U32(r31.u32 + 832, r11.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x826337a8
	ctx.lr = 0x8265226C;
	sub_826337A8(ctx, base);
	// lbz r6,1200(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 1200);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// clrlwi r5,r6,26
	ctx.r5.u64 = ctx.r6.u32 & 0x3F;
	// addi r7,r8,-18940
	ctx.r7.s64 = ctx.r8.s64 + -18940;
	// stb r5,1200(r31)
	PPC_STORE_U8(r31.u32 + 1200, ctx.r5.u8);
	// addi r22,r31,1216
	r22.s64 = r31.s64 + 1216;
	// stw r7,1024(r31)
	PPC_STORE_U32(r31.u32 + 1024, ctx.r7.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652290;
	sub_826337A8(ctx, base);
	// lbz r10,1392(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1392);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// clrlwi r9,r10,26
	ctx.r9.u64 = ctx.r10.u32 & 0x3F;
	// addi r11,r4,-18284
	r11.s64 = ctx.r4.s64 + -18284;
	// stb r9,1392(r31)
	PPC_STORE_U8(r31.u32 + 1392, ctx.r9.u8);
	// addi r21,r31,1408
	r21.s64 = r31.s64 + 1408;
	// stw r11,1216(r31)
	PPC_STORE_U32(r31.u32 + 1216, r11.u32);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x826337a8
	ctx.lr = 0x826522B4;
	sub_826337A8(ctx, base);
	// lbz r6,1584(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 1584);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// clrlwi r5,r6,26
	ctx.r5.u64 = ctx.r6.u32 & 0x3F;
	// addi r7,r8,-17628
	ctx.r7.s64 = ctx.r8.s64 + -17628;
	// stb r5,1584(r31)
	PPC_STORE_U8(r31.u32 + 1584, ctx.r5.u8);
	// addi r20,r31,1600
	r20.s64 = r31.s64 + 1600;
	// stw r7,1408(r31)
	PPC_STORE_U32(r31.u32 + 1408, ctx.r7.u32);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x826337a8
	ctx.lr = 0x826522D8;
	sub_826337A8(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r19,r31,1808
	r19.s64 = r31.s64 + 1808;
	// lbz r10,1776(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1776);
	// addi r11,r4,-22908
	r11.s64 = ctx.r4.s64 + -22908;
	// lbz r9,1804(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 1804);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stw r11,1600(r31)
	PPC_STORE_U32(r31.u32 + 1600, r11.u32);
	// clrlwi r8,r10,26
	ctx.r8.u64 = ctx.r10.u32 & 0x3F;
	// clrlwi r7,r9,27
	ctx.r7.u64 = ctx.r9.u32 & 0x1F;
	// stb r8,1776(r31)
	PPC_STORE_U8(r31.u32 + 1776, ctx.r8.u8);
	// stb r7,1804(r31)
	PPC_STORE_U8(r31.u32 + 1804, ctx.r7.u8);
	// bl 0x826337a8
	ctx.lr = 0x82652308;
	sub_826337A8(ctx, base);
	// lbz r4,1984(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1984);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// clrlwi r11,r4,26
	r11.u64 = ctx.r4.u32 & 0x3F;
	// addi r5,r6,-16972
	ctx.r5.s64 = ctx.r6.s64 + -16972;
	// stb r11,1984(r31)
	PPC_STORE_U8(r31.u32 + 1984, r11.u8);
	// addi r18,r31,2000
	r18.s64 = r31.s64 + 2000;
	// stw r5,1808(r31)
	PPC_STORE_U32(r31.u32 + 1808, ctx.r5.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x826337a8
	ctx.lr = 0x8265232C;
	sub_826337A8(ctx, base);
	// lbz r8,2176(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 2176);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// clrlwi r7,r8,26
	ctx.r7.u64 = ctx.r8.u32 & 0x3F;
	// addi r9,r10,-16316
	ctx.r9.s64 = ctx.r10.s64 + -16316;
	// stb r7,2176(r31)
	PPC_STORE_U8(r31.u32 + 2176, ctx.r7.u8);
	// addi r17,r31,2192
	r17.s64 = r31.s64 + 2192;
	// stw r9,2000(r31)
	PPC_STORE_U32(r31.u32 + 2000, ctx.r9.u32);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652350;
	sub_826337A8(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lbz r11,2368(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 2368);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r5,-24876
	ctx.r3.s64 = ctx.r5.s64 + -24876;
	// clrlwi r10,r11,26
	ctx.r10.u64 = r11.u32 & 0x3F;
	// stb r4,2396(r31)
	PPC_STORE_U8(r31.u32 + 2396, ctx.r4.u8);
	// lfs f31,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r3,2192(r31)
	PPC_STORE_U32(r31.u32 + 2192, ctx.r3.u32);
	// stfs f31,2384(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 2384, temp.u32);
	// stb r10,2368(r31)
	PPC_STORE_U8(r31.u32 + 2368, ctx.r10.u8);
	// stfs f31,2388(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 2388, temp.u32);
	// addi r30,r31,2400
	r30.s64 = r31.s64 + 2400;
	// stfs f31,2392(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 2392, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652390;
	sub_826337A8(ctx, base);
	// lbz r7,2576(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 2576);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// stfs f31,2592(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 2592, temp.u32);
	// li r28,0
	r28.s64 = 0;
	// addi r8,r9,-22252
	ctx.r8.s64 = ctx.r9.s64 + -22252;
	// clrlwi r6,r7,26
	ctx.r6.u64 = ctx.r7.u32 & 0x3F;
	// stw r28,2596(r31)
	PPC_STORE_U32(r31.u32 + 2596, r28.u32);
	// stw r8,2400(r31)
	PPC_STORE_U32(r31.u32 + 2400, ctx.r8.u32);
	// addi r16,r31,2624
	r16.s64 = r31.s64 + 2624;
	// stw r28,2600(r31)
	PPC_STORE_U32(r31.u32 + 2600, r28.u32);
	// stb r6,2576(r31)
	PPC_STORE_U8(r31.u32 + 2576, ctx.r6.u8);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x826337a8
	ctx.lr = 0x826523C4;
	sub_826337A8(ctx, base);
	// lbz r9,2816(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 2816);
	// lbz r10,2800(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 2800);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// clrlwi r7,r9,25
	ctx.r7.u64 = ctx.r9.u32 & 0x7F;
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r11,r5,-24220
	r11.s64 = ctx.r5.s64 + -24220;
	// clrlwi r8,r10,26
	ctx.r8.u64 = ctx.r10.u32 & 0x3F;
	// stw r4,2820(r31)
	PPC_STORE_U32(r31.u32 + 2820, ctx.r4.u32);
	// rlwinm r7,r7,0,27,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFDF;
	// stw r11,2624(r31)
	PPC_STORE_U32(r31.u32 + 2624, r11.u32);
	// stb r8,2800(r31)
	PPC_STORE_U8(r31.u32 + 2800, ctx.r8.u8);
	// addi r3,r31,2832
	ctx.r3.s64 = r31.s64 + 2832;
	// stb r7,2816(r31)
	PPC_STORE_U8(r31.u32 + 2816, ctx.r7.u8);
	// bl 0x82650de0
	ctx.lr = 0x826523FC;
	sub_82650DE0(ctx, base);
	// addi r29,r31,3648
	r29.s64 = r31.s64 + 3648;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826337a8
	ctx.lr = 0x82652408;
	sub_826337A8(ctx, base);
	// lbz r4,3824(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 3824);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// clrlwi r11,r4,26
	r11.u64 = ctx.r4.u32 & 0x3F;
	// addi r5,r6,-15660
	ctx.r5.s64 = ctx.r6.s64 + -15660;
	// stb r11,3824(r31)
	PPC_STORE_U8(r31.u32 + 3824, r11.u8);
	// addi r15,r31,3840
	r15.s64 = r31.s64 + 3840;
	// stw r5,3648(r31)
	PPC_STORE_U32(r31.u32 + 3648, ctx.r5.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x826337a8
	ctx.lr = 0x8265242C;
	sub_826337A8(ctx, base);
	// stfs f31,4032(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 4032, temp.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// lbz r8,4016(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4016);
	// addi r9,r10,-23564
	ctx.r9.s64 = ctx.r10.s64 + -23564;
	// clrlwi r7,r8,26
	ctx.r7.u64 = ctx.r8.u32 & 0x3F;
	// stw r9,3840(r31)
	PPC_STORE_U32(r31.u32 + 3840, ctx.r9.u32);
	// stb r7,4016(r31)
	PPC_STORE_U8(r31.u32 + 4016, ctx.r7.u8);
	// bl 0x82233a60
	ctx.lr = 0x82652450;
	sub_82233A60(ctx, base);
	// addi r3,r31,5280
	ctx.r3.s64 = r31.s64 + 5280;
	// bl 0x826337a8
	ctx.lr = 0x82652458;
	sub_826337A8(ctx, base);
	// lbz r4,5456(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 5456);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// clrlwi r11,r4,26
	r11.u64 = ctx.r4.u32 & 0x3F;
	// addi r5,r6,-15004
	ctx.r5.s64 = ctx.r6.s64 + -15004;
	// stb r11,5456(r31)
	PPC_STORE_U8(r31.u32 + 5456, r11.u8);
	// addi r3,r31,5472
	ctx.r3.s64 = r31.s64 + 5472;
	// stw r5,5280(r31)
	PPC_STORE_U32(r31.u32 + 5280, ctx.r5.u32);
	// bl 0x826337a8
	ctx.lr = 0x82652478;
	sub_826337A8(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r7,r10,-14348
	ctx.r7.s64 = ctx.r10.s64 + -14348;
	// addi r10,r6,-13516
	ctx.r10.s64 = ctx.r6.s64 + -13516;
	// addi r6,r11,-12752
	ctx.r6.s64 = r11.s64 + -12752;
	// stw r7,5472(r31)
	PPC_STORE_U32(r31.u32 + 5472, ctx.r7.u32);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r14,r11,-13640
	r14.s64 = r11.s64 + -13640;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r5,r9,-13696
	ctx.r5.s64 = ctx.r9.s64 + -13696;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r8,-13592
	ctx.r3.s64 = ctx.r8.s64 + -13592;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r8,r4,-13484
	ctx.r8.s64 = ctx.r4.s64 + -13484;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r9,r9,-13668
	ctx.r9.s64 = ctx.r9.s64 + -13668;
	// addi r7,r7,-13452
	ctx.r7.s64 = ctx.r7.s64 + -13452;
	// addi r4,r4,-13420
	ctx.r4.s64 = ctx.r4.s64 + -13420;
	// lbz r11,5648(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5648);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// clrlwi r11,r11,26
	r11.u64 = r11.u32 & 0x3F;
	// stb r11,5648(r31)
	PPC_STORE_U8(r31.u32 + 5648, r11.u8);
	// stw r5,5664(r31)
	PPC_STORE_U32(r31.u32 + 5664, ctx.r5.u32);
	// stw r3,5668(r31)
	PPC_STORE_U32(r31.u32 + 5668, ctx.r3.u32);
	// stw r10,5672(r31)
	PPC_STORE_U32(r31.u32 + 5672, ctx.r10.u32);
	// stw r8,5676(r31)
	PPC_STORE_U32(r31.u32 + 5676, ctx.r8.u32);
	// stw r6,5680(r31)
	PPC_STORE_U32(r31.u32 + 5680, ctx.r6.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stb r28,5684(r31)
	PPC_STORE_U8(r31.u32 + 5684, r28.u8);
	// stw r9,5688(r31)
	PPC_STORE_U32(r31.u32 + 5688, ctx.r9.u32);
	// stw r7,5692(r31)
	PPC_STORE_U32(r31.u32 + 5692, ctx.r7.u32);
	// stw r4,5696(r31)
	PPC_STORE_U32(r31.u32 + 5696, ctx.r4.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r14,5700(r31)
	PPC_STORE_U32(r31.u32 + 5700, r14.u32);
	// lbz r10,5708(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 5708);
	// clrlwi r9,r10,25
	ctx.r9.u64 = ctx.r10.u32 & 0x7F;
	// stb r9,5708(r31)
	PPC_STORE_U8(r31.u32 + 5708, ctx.r9.u8);
	// stw r28,204(r31)
	PPC_STORE_U32(r31.u32 + 204, r28.u32);
	// stw r28,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r28.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r27,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r27.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r24.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r22,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r22.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r21,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r21.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r20,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r20.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r19,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r19.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r18,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r18.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// stwx r17,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r17.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stwx r16,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r16.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r11,r31,2832
	r11.s64 = r31.s64 + 2832;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r9.u16);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stwx r15,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, r15.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// addi r11,r31,4048
	r11.s64 = r31.s64 + 4048;
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r11,r31,5280
	r11.s64 = r31.s64 + 5280;
	// sth r3,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r3.u16);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// sth r9,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r9.u16);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stwx r23,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, r23.u32);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// addi r11,r31,5472
	r11.s64 = r31.s64 + 5472;
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,-10236(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10236);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652718;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,3648(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 3648);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82652734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,2400(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 2400);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8265274C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14192(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,5704(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 5704, temp.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

PPC_WEAK_FUNC(sub_826521A0) {
	__imp__sub_826521A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652768) {
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
	// bl 0x826438b8
	ctx.lr = 0x82652788;
	sub_826438B8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826527a0
	if (cr6.eq) goto loc_826527A0;
	// bl 0x82130588
	ctx.lr = 0x8265279C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826527A0:
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

PPC_WEAK_FUNC(sub_82652768) {
	__imp__sub_82652768(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826527B8) {
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
	ctx.lr = 0x826527C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r31,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r31.u32);
	// addi r4,r11,-19636
	ctx.r4.s64 = r11.s64 + -19636;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826527E4;
	sub_821F9FB8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r29,56(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// addi r4,r9,-18780
	ctx.r4.s64 = ctx.r9.s64 + -18780;
	// bl 0x821f9fb8
	ctx.lr = 0x826527FC;
	sub_821F9FB8(ctx, base);
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
loc_82652800:
	// cmpwi cr6,r31,11
	cr6.compare<int32_t>(r31.s32, 11, xer);
	// beq cr6,0x82652830
	if (cr6.eq) goto loc_82652830;
	// cmpwi cr6,r31,12
	cr6.compare<int32_t>(r31.s32, 12, xer);
	// beq cr6,0x8265284c
	if (cr6.eq) goto loc_8265284C;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,196(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x82652848
	goto loc_82652848;
loc_82652830:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82652848:
	// bctrl 
	ctx.lr = 0x8265284C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8265284C:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,19
	cr6.compare<int32_t>(r31.s32, 19, xer);
	// blt cr6,0x82652800
	if (cr6.lt) goto loc_82652800;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826527B8) {
	__imp__sub_826527B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652860) {
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
	// bl 0x82630980
	ctx.lr = 0x82652878;
	sub_82630980(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265288C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,4048(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4048);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r31,4048
	ctx.r3.s64 = r31.s64 + 4048;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// bne cr6,0x826528bc
	if (!cr6.eq) goto loc_826528BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826528B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r31,5664
	ctx.r3.s64 = r31.s64 + 5664;
	// bl 0x82651470
	ctx.lr = 0x826528B8;
	sub_82651470(ctx, base);
	// b 0x826528c8
	goto loc_826528C8;
loc_826528BC:
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826528C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826528C8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -6432);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826528E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 692);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826528F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_82652860) {
	__imp__sub_82652860(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265290C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265290C) {
	__imp__sub_8265290C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652910) {
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
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82652948
	if (!cr6.eq) goto loc_82652948;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-19636
	ctx.r4.s64 = ctx.r10.s64 + -19636;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82652944;
	sub_821F9FB8(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
loc_82652948:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,-12456(r10)
	PPC_STORE_U8(ctx.r10.u32 + -12456, r11.u8);
	// bl 0x821e6828
	ctx.lr = 0x82652960;
	sub_821E6828(ctx, base);
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

PPC_WEAK_FUNC(sub_82652910) {
	__imp__sub_82652910(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82652974) {
	__imp__sub_82652974(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652978) {
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
	ctx.lr = 0x82652980;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x8264e598
	ctx.lr = 0x8265298C;
	sub_8264E598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826529f8
	if (!cr6.eq) goto loc_826529F8;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826529c8
	if (cr6.eq) goto loc_826529C8;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826529e4
	if (!cr6.gt) goto loc_826529E4;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x826529d8
	goto loc_826529D8;
loc_826529C8:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826529e4
	if (!cr6.gt) goto loc_826529E4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_826529D8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x826529e8
	if (!cr6.eq) goto loc_826529E8;
loc_826529E4:
	// li r11,0
	r11.s64 = 0;
loc_826529E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x826529fc
	if (!cr6.eq) goto loc_826529FC;
loc_826529F8:
	// li r11,1
	r11.s64 = 1;
loc_826529FC:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// clrlwi r27,r11,24
	r27.u64 = r11.u32 & 0xFF;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-10116
	ctx.r3.s64 = ctx.r10.s64 + -10116;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r29,r11,1
	r29.s64 = r11.s64 + 65536;
	// addi r29,r29,16256
	r29.s64 = r29.s64 + 16256;
	// bl 0x821fa230
	ctx.lr = 0x82652A1C;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,312(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 312);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82652A2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10132
	ctx.r3.s64 = r11.s64 + -10132;
	// bl 0x821fa230
	ctx.lr = 0x82652A44;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652A54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-13240
	ctx.r3.s64 = r11.s64 + -13240;
	// bl 0x821fa230
	ctx.lr = 0x82652A6C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652A7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652AA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82652AB4;
	sub_822040F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652acc
	if (cr6.eq) goto loc_82652ACC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_82652ACC:
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// ori r9,r10,4944
	ctx.r9.u64 = ctx.r10.u64 | 4944;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r10,4994
	ctx.r9.u64 = ctx.r10.u64 | 4994;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r31,1
	r31.s64 = 1;
	// addi r4,r10,-10144
	ctx.r4.s64 = ctx.r10.s64 + -10144;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x82652B30;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652b48
	if (cr6.eq) goto loc_82652B48;
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r31,r9,1
	r31.u64 = ctx.r9.u64 ^ 1;
loc_82652B48:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-21664
	ctx.r4.s64 = ctx.r10.s64 + -21664;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82652B68;
	sub_821F9FB8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r9,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r9.u8);
	// beq cr6,0x82652b8c
	if (cr6.eq) goto loc_82652B8C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-19772
	ctx.r4.s64 = r11.s64 + -19772;
	// bl 0x825ee270
	ctx.lr = 0x82652B8C;
	sub_825EE270(ctx, base);
loc_82652B8C:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8264ec10
	ctx.lr = 0x82652BA0;
	sub_8264EC10(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82652bd8
	if (cr6.eq) goto loc_82652BD8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82652bd8
	if (cr6.eq) goto loc_82652BD8;
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
loc_82652BD8:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207068
	ctx.lr = 0x82652BE0;
	sub_82207068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652bf8
	if (cr6.eq) goto loc_82652BF8;
	// bl 0x82256058
	ctx.lr = 0x82652BF0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
loc_82652BF8:
	// bl 0x8264e598
	ctx.lr = 0x82652BFC;
	sub_8264E598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82652c34
	if (cr6.eq) goto loc_82652C34;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82652c50
	if (!cr6.gt) goto loc_82652C50;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x82652c44
	goto loc_82652C44;
loc_82652C34:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82652c50
	if (!cr6.gt) goto loc_82652C50;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82652C44:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82652c54
	if (!cr6.eq) goto loc_82652C54;
loc_82652C50:
	// li r11,0
	r11.s64 = 0;
loc_82652C54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,676(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652C74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82652cd4
	if (!cr6.eq) goto loc_82652CD4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82652C88;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82652ca4
	if (!cr6.eq) goto loc_82652CA4;
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x822090b8
	ctx.lr = 0x82652C98;
	sub_822090B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
loc_82652CA4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10732
	ctx.r3.s64 = r11.s64 + -10732;
	// bl 0x821fa210
	ctx.lr = 0x82652CB0;
	sub_821FA210(ctx, base);
	// bl 0x826947e0
	ctx.lr = 0x82652CB4;
	sub_826947E0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x82652cd4
	if (cr6.eq) goto loc_82652CD4;
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
loc_82652CD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82652978) {
	__imp__sub_82652978(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652CE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652cf4
	if (cr6.eq) goto loc_82652CF4;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82652CF4:
	// b 0x82652978
	sub_82652978(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82652CE0) {
	__imp__sub_82652CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82652CF8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82652D00;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// lbz r10,900(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 900);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,108
	ctx.r4.s64 = 108;
	// ori r30,r11,16256
	r30.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82652D38;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,17268(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652db8
	if (cr6.eq) goto loc_82652DB8;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82652d8c
	if (cr6.eq) goto loc_82652D8C;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82652da8
	if (!cr6.gt) goto loc_82652DA8;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x82652d9c
	goto loc_82652D9C;
loc_82652D8C:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82652da8
	if (!cr6.gt) goto loc_82652DA8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_82652D9C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82652dac
	if (!cr6.eq) goto loc_82652DAC;
loc_82652DA8:
	// li r11,0
	r11.s64 = 0;
loc_82652DAC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653044
	if (cr6.eq) goto loc_82653044;
loc_82652DB8:
	// lwz r3,-10028(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82652DC0;
	sub_822040F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r10,-29347(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -29347);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// bl 0x82256058
	ctx.lr = 0x82652DE0;
	sub_82256058(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82652e30
	if (cr6.eq) goto loc_82652E30;
	// bl 0x82256138
	ctx.lr = 0x82652DF4;
	sub_82256138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652e10
	if (cr6.eq) goto loc_82652E10;
	// bl 0x82387a18
	ctx.lr = 0x82652E04;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653044
	if (cr6.eq) goto loc_82653044;
loc_82652E10:
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f1,32(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82256090
	ctx.lr = 0x82652E24;
	sub_82256090(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653044
	if (cr6.eq) goto loc_82653044;
loc_82652E30:
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82652E3C;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652e6c
	if (cr6.eq) goto loc_82652E6C;
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82652E50;
	sub_82641CC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,672(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 672);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82652E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653044
	if (cr6.eq) goto loc_82653044;
loc_82652E6C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,22440
	ctx.r4.s64 = ctx.r10.s64 + 22440;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x82652E80;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652e94
	if (cr6.eq) goto loc_82652E94;
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
loc_82652E94:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10116
	ctx.r3.s64 = r11.s64 + -10116;
	// bl 0x821fa230
	ctx.lr = 0x82652EA0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652EB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-10132
	ctx.r3.s64 = r11.s64 + -10132;
	// bl 0x821fa230
	ctx.lr = 0x82652EC8;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82652ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82652f2c
	if (cr6.eq) goto loc_82652F2C;
	// bl 0x822a39c0
	ctx.lr = 0x82652EF8;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652f2c
	if (cr6.eq) goto loc_82652F2C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,-10016(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82652f2c
	if (cr6.eq) goto loc_82652F2C;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82652F1C;
	sub_822A39C8(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
loc_82652F2C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701bd8
	ctx.lr = 0x82652F34;
	sub_82701BD8(ctx, base);
	// cmpwi cr6,r3,100
	cr6.compare<int32_t>(ctx.r3.s32, 100, xer);
	// beq cr6,0x82652f50
	if (cr6.eq) goto loc_82652F50;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82701bd8
	ctx.lr = 0x82652F44;
	sub_82701BD8(ctx, base);
	// cmpwi cr6,r3,100
	cr6.compare<int32_t>(ctx.r3.s32, 100, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82652f54
	if (!cr6.eq) goto loc_82652F54;
loc_82652F50:
	// li r11,1
	r11.s64 = 1;
loc_82652F54:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// or r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 | r11.u64;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// bl 0x823bb3f0
	ctx.lr = 0x82652F6C;
	sub_823BB3F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// bl 0x823bbf80
	ctx.lr = 0x82652F7C;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82652fb0
	if (cr6.eq) goto loc_82652FB0;
	// bl 0x823bc1c0
	ctx.lr = 0x82652F8C;
	sub_823BC1C0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82653044
	if (!cr6.gt) goto loc_82653044;
	// bl 0x823bc1c0
	ctx.lr = 0x82652FA0;
	sub_823BC1C0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82653044
	if (cr6.gt) goto loc_82653044;
loc_82652FB0:
	// lwz r3,-10028(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// bl 0x82204160
	ctx.lr = 0x82652FB8;
	sub_82204160(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// ori r9,r10,4944
	ctx.r9.u64 = ctx.r10.u64 | 4944;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82653044
	if (!cr6.eq) goto loc_82653044;
	// bl 0x82387a18
	ctx.lr = 0x82652FE0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653034
	if (cr6.eq) goto loc_82653034;
	// lwz r31,-3624(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82653034
	if (!cr6.eq) goto loc_82653034;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x8265300C;
	sub_82293F60(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x8265301C;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82653020;
	sub_82293F60(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f0,-12736(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12736);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82653044
	if (cr6.lt) goto loc_82653044;
loc_82653034:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82653044:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82652CF8) {
	__imp__sub_82652CF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653054) {
	__imp__sub_82653054(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653058) {
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
	ctx.lr = 0x82653060;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// mr r24,r8
	r24.u64 = ctx.r8.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bne cr6,0x82653218
	if (!cr6.eq) goto loc_82653218;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r11,76
	cr6.compare<int32_t>(r11.s32, 76, xer);
	// beq cr6,0x8265310c
	if (cr6.eq) goto loc_8265310C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-12896
	ctx.r4.s64 = r11.s64 + -12896;
	// bl 0x82691650
	ctx.lr = 0x826530B4;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826530C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r8,-2016
	ctx.r4.s64 = ctx.r8.s64 + -2016;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82691650
	ctx.lr = 0x826530D8;
	sub_82691650(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,312(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 312);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826530E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r30,24
	ctx.r5.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82653100
	if (!cr6.eq) goto loc_82653100;
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8265310c
	if (cr6.eq) goto loc_8265310C;
loc_82653100:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8265310C:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x8265313c
	if (cr6.eq) goto loc_8265313C;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82653158
	if (!cr6.gt) goto loc_82653158;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8265314c
	goto loc_8265314C;
loc_8265313C:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82653158
	if (!cr6.gt) goto loc_82653158;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8265314C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8265315c
	if (!cr6.eq) goto loc_8265315C;
loc_82653158:
	// li r11,0
	r11.s64 = 0;
loc_8265315C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826532f0
	if (cr6.eq) goto loc_826532F0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x822040f8
	ctx.lr = 0x82653174;
	sub_822040F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826532f0
	if (!cr6.eq) goto loc_826532F0;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r11,54
	cr6.compare<int32_t>(r11.s32, 54, xer);
	// beq cr6,0x826532c0
	if (cr6.eq) goto loc_826532C0;
	// cmpwi cr6,r11,55
	cr6.compare<int32_t>(r11.s32, 55, xer);
	// beq cr6,0x8265319c
	if (cr6.eq) goto loc_8265319C;
	// cmpwi cr6,r11,76
	cr6.compare<int32_t>(r11.s32, 76, xer);
	// bne cr6,0x82653218
	if (!cr6.eq) goto loc_82653218;
loc_8265319C:
	// bl 0x82652cf8
	ctx.lr = 0x826531A0;
	sub_82652CF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653100
	if (cr6.eq) goto loc_82653100;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// lwz r3,24588(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24588);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x821e6800
	ctx.lr = 0x826531C0;
	sub_821E6800(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r4,r9,-12796
	ctx.r4.s64 = ctx.r9.s64 + -12796;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x826531D4;
	sub_82691650(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,312(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 312);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826531E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8265323c
	if (cr6.eq) goto loc_8265323C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-10648
	ctx.r4.s64 = r11.s64 + -10648;
loc_82653200:
	// bl 0x82691650
	ctx.lr = 0x82653204;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,32(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82653218:
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8268ea68
	ctx.lr = 0x82653234;
	sub_8268EA68(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8265323C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-3752
	ctx.r4.s64 = r11.s64 + -3752;
	// bl 0x82691650
	ctx.lr = 0x82653248;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82653258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82653278
	if (cr6.eq) goto loc_82653278;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r11,-10672
	ctx.r4.s64 = r11.s64 + -10672;
	// b 0x82653200
	goto loc_82653200;
loc_82653278:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,-10684
	ctx.r4.s64 = r11.s64 + -10684;
	// bl 0x82691650
	ctx.lr = 0x82653284;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82653294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826532b4
	if (cr6.eq) goto loc_826532B4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,-10708
	ctx.r4.s64 = r11.s64 + -10708;
	// b 0x82653200
	goto loc_82653200;
loc_826532B4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,-10720
	ctx.r4.s64 = r11.s64 + -10720;
	// b 0x82653200
	goto loc_82653200;
loc_826532C0:
	// bl 0x82652cf8
	ctx.lr = 0x826532C4;
	sub_82652CF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653100
	if (cr6.eq) goto loc_82653100;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8264f2a8
	ctx.lr = 0x826532D8;
	sub_8264F2A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653100
	if (cr6.eq) goto loc_82653100;
	// bl 0x82650038
	ctx.lr = 0x826532E8;
	sub_82650038(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_826532F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82653058) {
	__imp__sub_82653058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826532FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826532FC) {
	__imp__sub_826532FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653300) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8265332C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82653370
	if (!cr6.eq) goto loc_82653370;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653370
	if (cr6.eq) goto loc_82653370;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10604
	ctx.r3.s64 = r11.s64 + -10604;
	// bl 0x821e6800
	ctx.lr = 0x82653350;
	sub_821E6800(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r9,100(r31)
	PPC_STORE_U8(r31.u32 + 100, ctx.r9.u8);
	// stb r8,790(r31)
	PPC_STORE_U8(r31.u32 + 790, ctx.r8.u8);
	// lfs f0,-28872(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28872);
	f0.f64 = double(temp.f32);
	// stfs f0,796(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 796, temp.u32);
	// b 0x826533c0
	goto loc_826533C0;
loc_82653370:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826533c0
	if (cr6.eq) goto loc_826533C0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826533c0
	if (!cr6.eq) goto loc_826533C0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10624
	ctx.r3.s64 = r11.s64 + -10624;
	// bl 0x821e6800
	ctx.lr = 0x826533A8;
	sub_821E6800(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-11460
	ctx.r3.s64 = ctx.r10.s64 + -11460;
	// bl 0x82255cf8
	ctx.lr = 0x826533B8;
	sub_82255CF8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,790(r31)
	PPC_STORE_U8(r31.u32 + 790, ctx.r9.u8);
loc_826533C0:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262fd60
	ctx.lr = 0x826533CC;
	sub_8262FD60(ctx, base);
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

PPC_WEAK_FUNC(sub_82653300) {
	__imp__sub_82653300(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826533E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826533E4) {
	__imp__sub_826533E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826533E8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f1,960(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 960, temp.u32);
	// stfs f2,964(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 964, temp.u32);
	// stb r6,968(r3)
	PPC_STORE_U8(ctx.r3.u32 + 968, ctx.r6.u8);
	// stfs f3,972(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 972, temp.u32);
	// stb r7,969(r3)
	PPC_STORE_U8(ctx.r3.u32 + 969, ctx.r7.u8);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f0,976(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 976, temp.u32);
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// bne cr6,0x82653418
	if (!cr6.eq) goto loc_82653418;
	// stfs f1,980(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 980, temp.u32);
loc_82653418:
	// lfs f0,7220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7220);
	f0.f64 = double(temp.f32);
	// stfs f0,984(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 984, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826533E8) {
	__imp__sub_826533E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653424) {
	__imp__sub_82653424(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r3,944
	ctx.r5.s64 = ctx.r3.s64 + 944;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-12548(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12548);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r6,-12560(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -12560);
	// li r7,0
	ctx.r7.s64 = 0;
	// b 0x821f51a0
	sub_821F51A0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82653428) {
	__imp__sub_82653428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653450) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82653458;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r30,r11,-12264
	r30.s64 = r11.s64 + -12264;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 304);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lbz r28,68(r10)
	r28.u64 = PPC_LOAD_U8(ctx.r10.u32 + 68);
	// bl 0x821c9790
	ctx.lr = 0x8265348C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8265349C;
	sub_825ED480(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826535e4
	if (cr6.eq) goto loc_826535E4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,21416
	ctx.r4.s64 = r11.s64 + 21416;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee120
	ctx.lr = 0x826534C0;
	sub_825EE120(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bge cr6,0x826534d0
	if (!cr6.lt) goto loc_826534D0;
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
loc_826534D0:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826535e4
	if (cr6.eq) goto loc_826535E4;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826535e4
	if (!cr6.eq) goto loc_826535E4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x826534F0;
	sub_825EF9F0(ctx, base);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r27
	r28.u64 = r27.u64;
	// cmpw cr6,r4,r29
	cr6.compare<int32_t>(ctx.r4.s32, r29.s32, xer);
	// beq cr6,0x826535c4
	if (cr6.eq) goto loc_826535C4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82653518;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82653534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82653538;
	sub_825EF9F0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r31,6
	r31.s64 = 6;
	// lfs f31,8884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f31.f64 = double(temp.f32);
loc_82653548:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef8c8
	ctx.lr = 0x82653564;
	sub_825EF8C8(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82653580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x825ef8c8
	ctx.lr = 0x82653584;
	sub_825EF8C8(ctx, base);
	// fsubs f0,f30,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - ctx.f1.f64));
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x826535a4
	if (cr6.gt) goto loc_826535A4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,9
	cr6.compare<int32_t>(r31.s32, 9, xer);
	// ble cr6,0x82653548
	if (!cr6.gt) goto loc_82653548;
	// b 0x826535a8
	goto loc_826535A8;
loc_826535A4:
	// li r28,1
	r28.s64 = 1;
loc_826535A8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12448);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826535c4
	if (cr6.eq) goto loc_826535C4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-10248
	ctx.r3.s64 = r11.s64 + -10248;
	// bl 0x821e6800
	ctx.lr = 0x826535C4;
	sub_821E6800(ctx, base);
loc_826535C4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826535e4
	if (!cr6.eq) goto loc_826535E4;
	// bl 0x82387a18
	ctx.lr = 0x826535D4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,2
	ctx.r3.s64 = 2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826535e8
	if (cr6.eq) goto loc_826535E8;
loc_826535E4:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
loc_826535E8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82653450) {
	__imp__sub_82653450(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826535F8) {
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
	ctx.lr = 0x82653600;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82632f78
	ctx.lr = 0x8265360C;
	sub_82632F78(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r11,-12592
	r30.s64 = r11.s64 + -12592;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// lwz r29,208(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265362C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82653638;
	sub_825EE0E0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r8,21416
	r30.s64 = ctx.r8.s64 + 21416;
	// lwz r6,468(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 468);
	// lwz r29,956(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82653658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82653664;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826535F8) {
	__imp__sub_826535F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265366C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265366C) {
	__imp__sub_8265366C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653670) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,948(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 948);
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

PPC_WEAK_FUNC(sub_82653670) {
	__imp__sub_82653670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653684) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82653684) {
	__imp__sub_82653684(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653688) {
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
	ctx.lr = 0x82653690;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826536B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826536e8
	if (cr6.eq) goto loc_826536E8;
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// beq cr6,0x826536dc
	if (cr6.eq) goto loc_826536DC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630aa8
	ctx.lr = 0x826536D4;
	sub_82630AA8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826536DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826536E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82653688) {
	__imp__sub_82653688(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826536F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826536F4) {
	__imp__sub_826536F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826536F8) {
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
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// lwz r30,864(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// bl 0x82631f88
	ctx.lr = 0x8265371C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8265372c
	if (cr6.lt) goto loc_8265372C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8265372C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82653748;
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

PPC_WEAK_FUNC(sub_826536F8) {
	__imp__sub_826536F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653760) {
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
	// bl 0x82630748
	ctx.lr = 0x82653780;
	sub_82630748(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,8044
	ctx.r5.s64 = r11.s64 + 8044;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,860
	ctx.r6.s64 = r31.s64 + 860;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826537A0;
	sub_824DF200(ctx, base);
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

PPC_WEAK_FUNC(sub_82653760) {
	__imp__sub_82653760(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826537B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,672(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 672);
	// addi r3,r3,672
	ctx.r3.s64 = ctx.r3.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_826537B8) {
	__imp__sub_826537B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826537D0) {
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
	ctx.lr = 0x826537D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826537F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8265389c
	if (cr6.eq) goto loc_8265389C;
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// beq cr6,0x82653864
	if (cr6.eq) goto loc_82653864;
	// cmpwi cr6,r30,56
	cr6.compare<int32_t>(r30.s32, 56, xer);
	// beq cr6,0x8265382c
	if (cr6.eq) goto loc_8265382C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826309e0
	ctx.lr = 0x82653824;
	sub_826309E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265382C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,772(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 772);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653858
	if (cr6.eq) goto loc_82653858;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x82653858;
	sub_821E6800(ctx, base);
loc_82653858:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82653864:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,768(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 768);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653890
	if (cr6.eq) goto loc_82653890;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82653890;
	sub_821E6800(ctx, base);
loc_82653890:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8265389C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826537D0) {
	__imp__sub_826537D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826538A8) {
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
	// bl 0x82630748
	ctx.lr = 0x826538C8;
	sub_82630748(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,8044
	ctx.r5.s64 = r11.s64 + 8044;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,860
	ctx.r6.s64 = r31.s64 + 860;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x826538E8;
	sub_824DF200(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-10260
	ctx.r5.s64 = ctx.r10.s64 + -10260;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,952
	ctx.r6.s64 = r31.s64 + 952;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82653908;
	sub_824DF200(ctx, base);
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

PPC_WEAK_FUNC(sub_826538A8) {
	__imp__sub_826538A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653948;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
	// bne cr6,0x82653968
	if (!cr6.eq) goto loc_82653968;
	// lfs f0,976(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 976);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x82653a68
	if (!cr6.lt) goto loc_82653A68;
loc_82653968:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f10,980(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 980);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,960(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 960);
	ctx.f9.f64 = double(temp.f32);
	// fcmpu cr6,f10,f9
	cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// lfs f11,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// bne cr6,0x82653988
	if (!cr6.eq) goto loc_82653988;
	// stfs f31,976(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
	// b 0x826539b4
	goto loc_826539B4;
loc_82653988:
	// lfs f12,964(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 964);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// beq cr6,0x826539b4
	if (cr6.eq) goto loc_826539B4;
	// lfs f0,976(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 976);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x826539b4
	if (!cr6.lt) goto loc_826539B4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f13,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f13,f0
	f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + f0.f64));
	// stfs f0,976(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
loc_826539B4:
	// lfs f0,964(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 964);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// beq cr6,0x82653a60
	if (cr6.eq) goto loc_82653A60;
	// lfs f1,976(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 976);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82653a50
	if (!cr6.lt) goto loc_82653A50;
	// lbz r11,968(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 968);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653a0c
	if (cr6.eq) goto loc_82653A0C;
	// lbz r10,969(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 969);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826539fc
	if (cr6.eq) goto loc_826539FC;
	// bl 0x82227ce8
	ctx.lr = 0x826539E8;
	sub_82227CE8(ctx, base);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// b 0x82653a1c
	goto loc_82653A1C;
loc_826539FC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653a0c
	if (cr6.eq) goto loc_82653A0C;
	// bl 0x82227c70
	ctx.lr = 0x82653A08;
	sub_82227C70(ctx, base);
	// b 0x82653a1c
	goto loc_82653A1C;
loc_82653A0C:
	// lbz r11,969(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 969);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82653a1c
	if (cr6.eq) goto loc_82653A1C;
	// bl 0x82227c18
	ctx.lr = 0x82653A1C;
	sub_82227C18(ctx, base);
loc_82653A1C:
	// lfs f2,972(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 972);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	cr6.compare(ctx.f2.f64, f31.f64);
	// beq cr6,0x82653a30
	if (cr6.eq) goto loc_82653A30;
	// bl 0x823dc480
	ctx.lr = 0x82653A2C;
	sub_823DC480(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
loc_82653A30:
	// lfs f0,984(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 984);
	f0.f64 = double(temp.f32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f13,960(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 960);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f0,f12,f1,f0
	f0.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + f0.f64));
	// stfs f0,980(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stfs f0,7220(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 7220, temp.u32);
	// b 0x82653a68
	goto loc_82653A68;
loc_82653A50:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f9,980(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stfs f9,7220(r11)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r11.u32 + 7220, temp.u32);
	// b 0x82653a68
	goto loc_82653A68;
loc_82653A60:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f10,7220(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 7220, temp.u32);
loc_82653A68:
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

PPC_WEAK_FUNC(sub_82653920) {
	__imp__sub_82653920(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653A80) {
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
	ctx.lr = 0x82653A88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x82653aa4
	if (!cr6.eq) goto loc_82653AA4;
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82653b20
	if (cr6.eq) goto loc_82653B20;
loc_82653AA4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r10,-10224
	r29.s64 = ctx.r10.s64 + -10224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82653AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee270
	ctx.lr = 0x82653AD0;
	sub_825EE270(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,60(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 60);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82653AE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82653b20
	if (cr6.eq) goto loc_82653B20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,956(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// lbz r30,80(r1)
	r30.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82653450
	ctx.lr = 0x82653B18;
	sub_82653450(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82653B20:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82653A80) {
	__imp__sub_82653A80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653B2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653B2C) {
	__imp__sub_82653B2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653B30) {
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
	// bl 0x8228fbf8
	ctx.lr = 0x82653B48;
	sub_8228FBF8(ctx, base);
	// lwz r3,944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82653ba8
	if (cr6.eq) goto loc_82653BA8;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82653ba4
	if (!cr6.eq) goto loc_82653BA4;
	// bl 0x821f4b28
	ctx.lr = 0x82653B64;
	sub_821F4B28(ctx, base);
	// lwz r11,948(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 948);
	// addi r5,r31,948
	ctx.r5.s64 = r31.s64 + 948;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82653ba8
	if (!cr6.eq) goto loc_82653BA8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r4,r9,-10212
	ctx.r4.s64 = ctx.r9.s64 + -10212;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821ee720
	ctx.lr = 0x82653B90;
	sub_821EE720(ctx, base);
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
loc_82653BA4:
	// bl 0x821f4c98
	ctx.lr = 0x82653BA8;
	sub_821F4C98(ctx, base);
loc_82653BA8:
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

PPC_WEAK_FUNC(sub_82653B30) {
	__imp__sub_82653B30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653BBC) {
	__imp__sub_82653BBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653BC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82653bdc
	if (cr6.eq) goto loc_82653BDC;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// ble cr6,0x82653bd8
	if (!cr6.gt) goto loc_82653BD8;
	// cmpwi cr6,r4,58
	cr6.compare<int32_t>(ctx.r4.s32, 58, xer);
	// ble cr6,0x82653bdc
	if (!cr6.gt) goto loc_82653BDC;
loc_82653BD8:
	// b 0x826537d0
	sub_826537D0(ctx, base);
	return;
loc_82653BDC:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82653BC0) {
	__imp__sub_82653BC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653BE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653BE4) {
	__imp__sub_82653BE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653BE8) {
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
	ctx.lr = 0x82653BF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x82633e80
	ctx.lr = 0x82653C08;
	sub_82633E80(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r10,r11,-10180
	ctx.r10.s64 = r11.s64 + -10180;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826337a8
	ctx.lr = 0x82653C20;
	sub_826337A8(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r29,0
	r29.s64 = 0;
	// addi r8,r9,-14100
	ctx.r8.s64 = ctx.r9.s64 + -14100;
	// stw r29,432(r31)
	PPC_STORE_U32(r31.u32 + 432, r29.u32);
	// addi r3,r30,184
	ctx.r3.s64 = r30.s64 + 184;
	// stw r8,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r8.u32);
	// stw r29,436(r31)
	PPC_STORE_U32(r31.u32 + 436, r29.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82653C40;
	sub_821C2F70(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r29,464(r31)
	PPC_STORE_U32(r31.u32 + 464, r29.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stb r7,460(r31)
	PPC_STORE_U8(r31.u32 + 460, ctx.r7.u8);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r29,480(r31)
	PPC_STORE_U8(r31.u32 + 480, r29.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262ffe0
	ctx.lr = 0x82653C60;
	sub_8262FFE0(ctx, base);
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82653BE8) {
	__imp__sub_82653BE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653C88) {
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
	ctx.lr = 0x82653C90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653CB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653d38
	if (cr6.eq) goto loc_82653D38;
	// cmpwi cr6,r30,-2
	cr6.compare<int32_t>(r30.s32, -2, xer);
	// bne cr6,0x82653d20
	if (!cr6.eq) goto loc_82653D20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,780(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 780);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653CD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82653d20
	if (cr6.eq) goto loc_82653D20;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82653D00;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82653D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82653D20:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630aa8
	ctx.lr = 0x82653D30;
	sub_82630AA8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82653D38:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82653C88) {
	__imp__sub_82653C88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653D44) {
	__imp__sub_82653D44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653D48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// lwz r10,-10028(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,6132
	ctx.r9.s64 = ctx.r9.s64 + 6132;
	// lwz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653d98
	if (cr6.eq) goto loc_82653D98;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82653d84
	if (cr6.eq) goto loc_82653D84;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
loc_82653D84:
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stb r8,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r8.u8);
	// blr 
	return;
loc_82653D98:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stb r10,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82653D48) {
	__imp__sub_82653D48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653DAC) {
	__imp__sub_82653DAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653DB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// lwz r10,-10028(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// addi r9,r9,6132
	ctx.r9.s64 = ctx.r9.s64 + 6132;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653e00
	if (cr6.eq) goto loc_82653E00;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r8,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r8.u32);
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82653dec
	if (cr6.eq) goto loc_82653DEC;
	// stw r11,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, r11.u32);
loc_82653DEC:
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r11.u32);
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stb r8,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r8.u8);
	// blr 
	return;
loc_82653E00:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// stw r11,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r11.u32);
	// stb r10,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82653DB0) {
	__imp__sub_82653DB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653E14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653E14) {
	__imp__sub_82653E14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653E18) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,16(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// lwz r10,-10028(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// addis r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 65536;
	// addi r10,r10,6132
	ctx.r10.s64 = ctx.r10.s64 + 6132;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82653e4c
	if (!cr6.eq) goto loc_82653E4C;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
loc_82653E4C:
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82653e60
	if (!cr6.eq) goto loc_82653E60;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_82653E60:
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653e74
	if (cr6.eq) goto loc_82653E74;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
loc_82653E74:
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82653e88
	if (cr6.eq) goto loc_82653E88;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
loc_82653E88:
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stb r10,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82653E18) {
	__imp__sub_82653E18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82653E9C) {
	__imp__sub_82653E9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653EA0) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r5,r11,27904
	ctx.r5.s64 = r11.s64 + 27904;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82653be8
	ctx.lr = 0x82653ECC;
	sub_82653BE8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r9,-8716
	ctx.r7.s64 = ctx.r9.s64 + -8716;
	// stw r8,204(r31)
	PPC_STORE_U32(r31.u32 + 204, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
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

PPC_WEAK_FUNC(sub_82653EA0) {
	__imp__sub_82653EA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653EF8) {
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
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653F14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

PPC_WEAK_FUNC(sub_82653EF8) {
	__imp__sub_82653EF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82653F28) {
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
	ctx.lr = 0x82653F30;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82653F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826540a8
	if (cr6.eq) goto loc_826540A8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r5,956(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 956);
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r11,21416
	ctx.r4.s64 = r11.s64 + 21416;
	// bl 0x825ee0e0
	ctx.lr = 0x82653F68;
	sub_825EE0E0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,992(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 992);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82653F80;
	sub_82691650(ctx, base);
	// lwz r30,56(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,304(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 304);
	// bl 0x82720e28
	ctx.lr = 0x82653F94;
	sub_82720E28(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r28,r9,2612
	r28.s64 = ctx.r9.s64 + 2612;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r27,56(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82653FAC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825ed480
	ctx.lr = 0x82653FBC;
	sub_825ED480(ctx, base);
	// lbz r8,65(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-13268
	ctx.r4.s64 = ctx.r7.s64 + -13268;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x82653FD8;
	sub_82722678(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-11044
	ctx.r4.s64 = ctx.r6.s64 + -11044;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82653FEC;
	sub_825EE0E0(ctx, base);
	// lis r5,-32138
	ctx.r5.s64 = -2106195968;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r9,r5,9352
	ctx.r9.s64 = ctx.r5.s64 + 9352;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// bl 0x82220308
	ctx.lr = 0x82654014;
	sub_82220308(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r4,r8,-10224
	ctx.r4.s64 = ctx.r8.s64 + -10224;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82654028;
	sub_825EE0E0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,332(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 332);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8265403C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r4,-13276
	ctx.r4.s64 = ctx.r4.s64 + -13276;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827227b8
	ctx.lr = 0x82654050;
	sub_827227B8(ctx, base);
	// lwz r11,496(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 496);
	// addi r3,r31,496
	ctx.r3.s64 = r31.s64 + 496;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654064;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r8,176(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 176);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82654078;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82635840
	ctx.lr = 0x82654084;
	sub_82635840(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r4,r7,620
	ctx.r4.s64 = ctx.r7.s64 + 620;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82722678
	ctx.lr = 0x826540A0;
	sub_82722678(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_826540A8:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 304);
	// bl 0x82720560
	ctx.lr = 0x826540B4;
	sub_82720560(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82653F28) {
	__imp__sub_82653F28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826540BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826540BC) {
	__imp__sub_826540BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826540C0) {
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
	ctx.lr = 0x826540C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r9
	r27.u64 = ctx.r9.u64;
	// bl 0x82653be8
	ctx.lr = 0x826540E8;
	sub_82653BE8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r31,496
	r30.s64 = r31.s64 + 496;
	// addi r10,r11,-7924
	ctx.r10.s64 = r11.s64 + -7924;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633a10
	ctx.lr = 0x82654108;
	sub_82633A10(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r29,r31,672
	r29.s64 = r31.s64 + 672;
	// addi r8,r9,4916
	ctx.r8.s64 = ctx.r9.s64 + 4916;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r8,496(r31)
	PPC_STORE_U32(r31.u32 + 496, ctx.r8.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82634738
	ctx.lr = 0x82654128;
	sub_82634738(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// addi r6,r7,-9388
	ctx.r6.s64 = ctx.r7.s64 + -9388;
	// stw r6,672(r31)
	PPC_STORE_U32(r31.u32 + 672, ctx.r6.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r5.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r3.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826540C0) {
	__imp__sub_826540C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654174) {
	__imp__sub_82654174(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654178) {
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
	// lhz r11,214(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 214);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826541a8
	if (cr6.eq) goto loc_826541A8;
	// lwz r3,208(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// bl 0x82130588
	ctx.lr = 0x826541A8;
	sub_82130588(ctx, base);
loc_826541A8:
	// lhz r11,182(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 182);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826541bc
	if (cr6.eq) goto loc_826541BC;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x826541BC;
	sub_82130588(ctx, base);
loc_826541BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x826541C4;
	sub_82633B00(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826541dc
	if (cr6.eq) goto loc_826541DC;
	// bl 0x82130588
	ctx.lr = 0x826541D8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826541DC:
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

PPC_WEAK_FUNC(sub_82654178) {
	__imp__sub_82654178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826541F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826541F4) {
	__imp__sub_826541F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826541F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82654200;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// bl 0x82653be8
	ctx.lr = 0x82654220;
	sub_82653BE8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r29,r31,496
	r29.s64 = r31.s64 + 496;
	// addi r10,r11,7236
	ctx.r10.s64 = r11.s64 + 7236;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633a10
	ctx.lr = 0x82654240;
	sub_82633A10(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// addi r8,r9,4916
	ctx.r8.s64 = ctx.r9.s64 + 4916;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// stw r8,496(r31)
	PPC_STORE_U32(r31.u32 + 496, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82634738
	ctx.lr = 0x82654260;
	sub_82634738(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,6524
	ctx.r6.s64 = ctx.r7.s64 + 6524;
	// stw r11,928(r31)
	PPC_STORE_U32(r31.u32 + 928, r11.u32);
	// lis r5,-32215
	ctx.r5.s64 = -2111242240;
	// stw r6,672(r31)
	PPC_STORE_U32(r31.u32 + 672, ctx.r6.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,932(r31)
	PPC_STORE_U32(r31.u32 + 932, r11.u32);
	// addi r4,r5,-26040
	ctx.r4.s64 = ctx.r5.s64 + -26040;
	// stw r28,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r28.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x821c2f90
	ctx.lr = 0x82654290;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826542A0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826542a0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826542A0;
	// addi r10,r31,908
	ctx.r10.s64 = r31.s64 + 908;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826542C4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826542c4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826542C4;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r8.u16);
	// stwx r30,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r30.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r6.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826541F8) {
	__imp__sub_826541F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654318) {
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
	// bl 0x8228f920
	ctx.lr = 0x82654330;
	sub_8228F920(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// addi r6,r7,-7124
	ctx.r6.s64 = ctx.r7.s64 + -7124;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r5,4
	ctx.r5.s64 = 4;
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f0,960(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 960, temp.u32);
	// stfs f13,964(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 964, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,972(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 972, temp.u32);
	// stw r10,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r10.u32);
	// stfs f0,976(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
	// stw r10,948(r31)
	PPC_STORE_U32(r31.u32 + 948, ctx.r10.u32);
	// stfs f0,980(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stw r5,952(r31)
	PPC_STORE_U32(r31.u32 + 952, ctx.r5.u32);
	// stw r4,956(r31)
	PPC_STORE_U32(r31.u32 + 956, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,968(r31)
	PPC_STORE_U8(r31.u32 + 968, r11.u8);
	// stb r11,969(r31)
	PPC_STORE_U8(r31.u32 + 969, r11.u8);
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

PPC_WEAK_FUNC(sub_82654318) {
	__imp__sub_82654318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826543A0) {
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
	// bl 0x826541f8
	ctx.lr = 0x826543B8;
	sub_826541F8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// addi r6,r7,-7124
	ctx.r6.s64 = ctx.r7.s64 + -7124;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r5,4
	ctx.r5.s64 = 4;
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f0,960(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 960, temp.u32);
	// stfs f13,964(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 964, temp.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,972(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 972, temp.u32);
	// stw r10,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r10.u32);
	// stfs f0,976(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 976, temp.u32);
	// stw r10,948(r31)
	PPC_STORE_U32(r31.u32 + 948, ctx.r10.u32);
	// stfs f0,980(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 980, temp.u32);
	// stw r5,952(r31)
	PPC_STORE_U32(r31.u32 + 952, ctx.r5.u32);
	// stw r4,956(r31)
	PPC_STORE_U32(r31.u32 + 956, ctx.r4.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,968(r31)
	PPC_STORE_U8(r31.u32 + 968, r11.u8);
	// stb r11,969(r31)
	PPC_STORE_U8(r31.u32 + 969, r11.u8);
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

PPC_WEAK_FUNC(sub_826543A0) {
	__imp__sub_826543A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654428) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82654318
	ctx.lr = 0x82654460;
	sub_82654318(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-6316
	ctx.r9.s64 = ctx.r10.s64 + -6316;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_82654428) {
	__imp__sub_82654428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265448C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265448C) {
	__imp__sub_8265448C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654490) {
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
	// bl 0x8221fcc8
	ctx.lr = 0x826544B0;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826544c8
	if (cr6.eq) goto loc_826544C8;
	// bl 0x82130588
	ctx.lr = 0x826544C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826544C8:
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

PPC_WEAK_FUNC(sub_82654490) {
	__imp__sub_82654490(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826544E0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82654318
	ctx.lr = 0x82654518;
	sub_82654318(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-6316
	ctx.r9.s64 = ctx.r10.s64 + -6316;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_826544E0) {
	__imp__sub_826544E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654544) {
	__imp__sub_82654544(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654548) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-2800(r1)
	ea = -2800 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// li r4,14
	ctx.r4.s64 = 14;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9248
	ctx.lr = 0x8265457C;
	sub_821F9248(ctx, base);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r10,2384
	ctx.r8.s64 = ctx.r10.s64 + 2384;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r6,16
	ctx.r6.s64 = 16;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// addi r11,r5,2352
	r11.s64 = ctx.r5.s64 + 2352;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v126,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v58,r3,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v62,v61
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v56,v58,v60
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// addi r10,r4,2256
	ctx.r10.s64 = ctx.r4.s64 + 2256;
	// vmrglw128 v55,v62,v61
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vmrglw128 v54,v58,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v53,v63,v59
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vmrglw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// vmrghw128 v51,v57,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// li r11,0
	r11.s64 = 0;
	// vmrghw128 v50,v55,v54
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// vmsum4fp128 v49,v53,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// vmsum4fp128 v48,v53,v51
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// vmsum4fp128 v47,v53,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r10,156(r1)
	PPC_STORE_U16(ctx.r1.u32 + 156, ctx.r10.u16);
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r11,158(r1)
	PPC_STORE_U16(ctx.r1.u32 + 158, r11.u16);
	// stb r11,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r11.u8);
	// sth r11,162(r1)
	PPC_STORE_U16(ctx.r1.u32 + 162, r11.u16);
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// vmrghw128 v46,v49,v53
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v45,v48,v47
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v45,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// stvx128 v44,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8220edb0
	ctx.lr = 0x82654658;
	sub_8220EDB0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// lfs f1,12424(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8257df18
	ctx.lr = 0x82654674;
	sub_8257DF18(ctx, base);
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r6,r7,-20564
	ctx.r6.s64 = ctx.r7.s64 + -20564;
	// addi r5,r5,-20524
	ctx.r5.s64 = ctx.r5.s64 + -20524;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-23464(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -23464);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82654698;
	sub_823DEDD8(ctx, base);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r3,512
	ctx.r3.s64 = 512;
	// slw r11,r3,r4
	r11.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r4.u8 & 0x3F));
	// stw r11,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,7
	ctx.r7.s64 = 7;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,6174
	ctx.r5.s64 = 6174;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8220dbd8
	ctx.lr = 0x826546CC;
	sub_8220DBD8(ctx, base);
	// lbz r10,666(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 666);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826546f8
	if (!cr6.gt) goto loc_826546F8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826546e8
	if (cr6.eq) goto loc_826546E8;
	// lwz r3,532(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// bl 0x82130588
	ctx.lr = 0x826546E8;
	sub_82130588(ctx, base);
loc_826546E8:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x826546F0;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82654714
	goto loc_82654714;
loc_826546F8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82654708
	if (cr6.eq) goto loc_82654708;
	// lwz r3,532(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// bl 0x82130588
	ctx.lr = 0x82654708;
	sub_82130588(ctx, base);
loc_82654708:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x82654710;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82654714:
	// addi r1,r1,2800
	ctx.r1.s64 = ctx.r1.s64 + 2800;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82654548) {
	__imp__sub_82654548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654734) {
	__imp__sub_82654734(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654738) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dd524
	ctx.lr = 0x8265474C;
	// stwu r1,-2864(r1)
	ea = -2864 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// li r4,14
	ctx.r4.s64 = 14;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9248
	ctx.lr = 0x82654768;
	sub_821F9248(ctx, base);
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r10,2384
	ctx.r8.s64 = ctx.r10.s64 + 2384;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r6,16
	ctx.r6.s64 = 16;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r5,2352
	ctx.r10.s64 = ctx.r5.s64 + 2352;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v127,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v58,r3,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v57,v126,v63
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrglw128 v56,v62,v61
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// li r4,0
	ctx.r4.s64 = 0;
	// vmrglw128 v55,v58,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v127,v62,v61
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vor128 v126,v63,v59
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vmrghw128 v124,v58,v60
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vor128 v125,v63,v57
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v57.u8)));
	// vmrghw128 v54,v56,v55
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v123,v126,v54
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v123.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v54.f32), 0xFF));
	// vmsum4fp128 v122,v125,v54
	simde_mm_store_ps(v122.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v54.f32), 0xFF));
	// bl 0x822a3998
	ctx.lr = 0x826547D8;
	sub_822A3998(ctx, base);
	// vmrglw128 v53,v127,v124
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// vmrghw128 v52,v127,v124
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// vmrglw128 v51,v127,v124
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// addi r7,r9,2256
	ctx.r7.s64 = ctx.r9.s64 + 2256;
	// vmrghw128 v50,v127,v124
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// vmsum4fp128 v49,v126,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v53.f32), 0xFF));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// vmsum4fp128 v48,v126,v52
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vmsum4fp128 v47,v125,v51
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v51.f32), 0xFF));
	// li r11,0
	r11.s64 = 0;
	// vmsum4fp128 v46,v125,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// lwz r31,28(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r7,156(r1)
	PPC_STORE_U16(ctx.r1.u32 + 156, ctx.r7.u16);
	// sth r11,158(r1)
	PPC_STORE_U16(ctx.r1.u32 + 158, r11.u16);
	// stb r11,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r11.u8);
	// sth r11,162(r1)
	PPC_STORE_U16(ctx.r1.u32 + 162, r11.u16);
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r11.u32);
	// vmrghw128 v45,v49,v126
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v126.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v44,v48,v123
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v43,v47,v125
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v42,v46,v122
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v122.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v41,v44,v45
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// vmrghw128 v40,v42,v43
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// stvx128 v41,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8220edb0
	ctx.lr = 0x82654884;
	sub_8220EDB0(ctx, base);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f1,-29232(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8257df18
	ctx.lr = 0x826548A0;
	sub_8257DF18(ctx, base);
	// lis r4,-32114
	ctx.r4.s64 = -2104623104;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r6,r3,-20564
	ctx.r6.s64 = ctx.r3.s64 + -20564;
	// addi r5,r11,-20524
	ctx.r5.s64 = r11.s64 + -20524;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-23464(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -23464);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x826548C4;
	sub_823DEDD8(ctx, base);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r8,512
	ctx.r8.s64 = 512;
	// li r10,1
	ctx.r10.s64 = 1;
	// slw r7,r8,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// stw r7,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r7.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,7
	ctx.r7.s64 = 7;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,6166
	ctx.r5.s64 = 6166;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x8220dbd8
	ctx.lr = 0x826548F8;
	sub_8220DBD8(ctx, base);
	// lbz r10,666(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 666);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82654924
	if (!cr6.gt) goto loc_82654924;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82654914
	if (cr6.eq) goto loc_82654914;
	// lwz r3,532(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// bl 0x82130588
	ctx.lr = 0x82654914;
	sub_82130588(ctx, base);
loc_82654914:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x8265491C;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82654940
	goto loc_82654940;
loc_82654924:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82654934
	if (cr6.eq) goto loc_82654934;
	// lwz r3,532(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// bl 0x82130588
	ctx.lr = 0x82654934;
	sub_82130588(ctx, base);
loc_82654934:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x82130000
	ctx.lr = 0x8265493C;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82654940:
	// addi r1,r1,2864
	ctx.r1.s64 = ctx.r1.s64 + 2864;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dd7bc
	ctx.lr = 0x8265494C;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82654738) {
	__imp__sub_82654738(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8265495C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8265495C) {
	__imp__sub_8265495C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654960) {
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
	ctx.lr = 0x82654968;
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
	ctx.lr = 0x82654980;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822a5680
	ctx.lr = 0x82654988;
	sub_822A5680(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r29,r8,1
	r29.u64 = ctx.r8.u64 ^ 1;
	// beq cr6,0x826549bc
	if (cr6.eq) goto loc_826549BC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82562740
	ctx.lr = 0x826549B0;
	sub_82562740(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82654a9c
	if (!cr6.eq) goto loc_82654A9C;
loc_826549BC:
	// bl 0x82387a18
	ctx.lr = 0x826549C0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654a9c
	if (!cr6.eq) goto loc_82654A9C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r10,r11,4897
	ctx.r10.s64 = r11.s64 + 4897;
	// addi r9,r11,4947
	ctx.r9.s64 = r11.s64 + 4947;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v2,r8,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r7,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82654738
	ctx.lr = 0x826549F4;
	sub_82654738(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82654a0c
	if (!cr6.eq) goto loc_82654A0C;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654aa4
	if (!cr6.eq) goto loc_82654AA4;
loc_82654A0C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822082b0
	ctx.lr = 0x82654A14;
	sub_822082B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82654aa4
	if (!cr6.eq) goto loc_82654AA4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,-10028(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addi r11,r11,10
	r11.s64 = r11.s64 + 10;
	// addi r9,r11,4897
	ctx.r9.s64 = r11.s64 + 4897;
	// addi r8,r11,4947
	ctx.r8.s64 = r11.s64 + 4947;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r6,r8,4,0,27
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v2,r7,r10
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r6,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82654738
	ctx.lr = 0x82654A50;
	sub_82654738(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x82654a68
	if (!cr6.eq) goto loc_82654A68;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654a88
	if (!cr6.eq) goto loc_82654A88;
loc_82654A68:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,10
	ctx.r3.s64 = r11.s64 + 10;
	// bl 0x822082b0
	ctx.lr = 0x82654A74;
	sub_822082B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82654a9c
	if (cr6.eq) goto loc_82654A9C;
loc_82654A88:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,10
	r11.s64 = r11.s64 + 10;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82654A9C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_82654AA4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82654960) {
	__imp__sub_82654960(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654AAC) {
	__imp__sub_82654AAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654AB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r11,956
	ctx.r3.s64 = r11.s64 + 956;
	// lwz r10,952(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 952);
	// stw r10,956(r11)
	PPC_STORE_U32(r11.u32 + 956, ctx.r10.u32);
	// b 0x82654960
	sub_82654960(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82654AB0) {
	__imp__sub_82654AB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654AC4) {
	__imp__sub_82654AC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654AC8) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654AEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82654b40
	if (cr6.eq) goto loc_82654B40;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r11,6512
	r31.s64 = r11.s64 + 6512;
	// lwz r9,784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82654B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82654B10:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x82654b34
	if (cr6.eq) goto loc_82654B34;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82654b10
	if (cr6.eq) goto loc_82654B10;
loc_82654B34:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82654b44
	if (cr6.eq) goto loc_82654B44;
loc_82654B40:
	// li r11,0
	r11.s64 = 0;
loc_82654B44:
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

PPC_WEAK_FUNC(sub_82654AC8) {
	__imp__sub_82654AC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654B5C) {
	__imp__sub_82654B5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654B60) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654B84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82654bd8
	if (cr6.eq) goto loc_82654BD8;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r11,8860
	r31.s64 = r11.s64 + 8860;
	// lwz r9,784(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82654BA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82654BA8:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x82654bcc
	if (cr6.eq) goto loc_82654BCC;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82654ba8
	if (cr6.eq) goto loc_82654BA8;
loc_82654BCC:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82654bdc
	if (cr6.eq) goto loc_82654BDC;
loc_82654BD8:
	// li r11,0
	r11.s64 = 0;
loc_82654BDC:
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

PPC_WEAK_FUNC(sub_82654B60) {
	__imp__sub_82654B60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654BF4) {
	__imp__sub_82654BF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654BF8) {
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
	// bl 0x82654ac8
	ctx.lr = 0x82654C10;
	sub_82654AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654c40
	if (!cr6.eq) goto loc_82654C40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654b60
	ctx.lr = 0x82654C24;
	sub_82654B60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82654c40
	if (!cr6.eq) goto loc_82654C40;
	// lbz r11,960(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82654c44
	if (cr6.eq) goto loc_82654C44;
loc_82654C40:
	// li r11,0
	r11.s64 = 0;
loc_82654C44:
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

PPC_WEAK_FUNC(sub_82654BF8) {
	__imp__sub_82654BF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654C5C) {
	__imp__sub_82654C5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654C60) {
	PPC_FUNC_PROLOGUE();
	// li r3,36
	ctx.r3.s64 = 36;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82654C60) {
	__imp__sub_82654C60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654C68) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r31,928
	r11.s64 = r31.s64 + 928;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r10,28572
	ctx.r4.s64 = ctx.r10.s64 + 28572;
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82654C98;
	sub_8262FFE0(ctx, base);
	// addi r9,r31,1376
	ctx.r9.s64 = r31.s64 + 1376;
	// stw r9,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_82654C68) {
	__imp__sub_82654C68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654CB4) {
	__imp__sub_82654CB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654CB8) {
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
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r11,r31,952
	r11.s64 = r31.s64 + 952;
	// addi r3,r10,-5016
	ctx.r3.s64 = ctx.r10.s64 + -5016;
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// bl 0x821fa230
	ctx.lr = 0x82654CE0;
	sub_821FA230(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82654CF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82654d10
	if (cr6.eq) goto loc_82654D10;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,28860
	ctx.r4.s64 = r11.s64 + 28860;
	// b 0x82654d1c
	goto loc_82654D1C;
loc_82654D10:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r11,28500
	ctx.r4.s64 = r11.s64 + 28500;
loc_82654D1C:
	// bl 0x8262ffe0
	ctx.lr = 0x82654D20;
	sub_8262FFE0(ctx, base);
	// addi r10,r31,1376
	ctx.r10.s64 = r31.s64 + 1376;
	// stw r10,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, ctx.r10.u32);
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

PPC_WEAK_FUNC(sub_82654CB8) {
	__imp__sub_82654CB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654D3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654D3C) {
	__imp__sub_82654D3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654D40) {
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
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r31,976
	r11.s64 = r31.s64 + 976;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r10,28500
	ctx.r4.s64 = ctx.r10.s64 + 28500;
	// stw r11,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r11.u32);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82654D70;
	sub_8262FFE0(ctx, base);
	// addi r9,r31,1360
	ctx.r9.s64 = r31.s64 + 1360;
	// stw r9,1388(r31)
	PPC_STORE_U32(r31.u32 + 1388, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_82654D40) {
	__imp__sub_82654D40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654D8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82654D8C) {
	__imp__sub_82654D8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654D90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,864(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 864);
	// addi r10,r3,976
	ctx.r10.s64 = ctx.r3.s64 + 976;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - r11.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82654D90) {
	__imp__sub_82654D90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82654DA8) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82654DD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82654dec
	if (cr6.eq) goto loc_82654DEC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82130000
	ctx.lr = 0x82654DEC;
	sub_82130000(ctx, base);
loc_82654DEC:
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

PPC_WEAK_FUNC(sub_82654DA8) {
	__imp__sub_82654DA8(ctx, base);
}

