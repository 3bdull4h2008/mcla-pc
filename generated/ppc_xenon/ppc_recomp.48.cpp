#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822E9118"))) PPC_WEAK_FUNC(sub_822E9118);
PPC_FUNC_IMPL(__imp__sub_822E9118) {
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
	// lis r11,-32209
	r11.s64 = -2110849024;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-28520
	ctx.r4.s64 = r11.s64 + -28520;
	// addi r3,r10,-4656
	ctx.r3.s64 = ctx.r10.s64 + -4656;
	// bl 0x82554798
	ctx.lr = 0x822E9138;
	sub_82554798(ctx, base);
	// lis r9,-32209
	ctx.r9.s64 = -2110849024;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-28464
	ctx.r4.s64 = ctx.r9.s64 + -28464;
	// addi r3,r8,-4684
	ctx.r3.s64 = ctx.r8.s64 + -4684;
	// bl 0x82554798
	ctx.lr = 0x822E914C;
	sub_82554798(ctx, base);
	// lis r7,-32209
	ctx.r7.s64 = -2110849024;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-28440
	ctx.r4.s64 = ctx.r7.s64 + -28440;
	// addi r3,r6,-4720
	ctx.r3.s64 = ctx.r6.s64 + -4720;
	// bl 0x82554798
	ctx.lr = 0x822E9160;
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

__attribute__((alias("__imp__sub_822E9170"))) PPC_WEAK_FUNC(sub_822E9170);
PPC_FUNC_IMPL(__imp__sub_822E9170) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32209
	r11.s64 = -2110849024;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,2304
	ctx.r5.s64 = r11.s64 + 2304;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822E9198;
	sub_821D4268(ctx, base);
	// lis r10,-32182
	ctx.r10.s64 = -2109079552;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r10,-30160
	ctx.r8.s64 = ctx.r10.s64 + -30160;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r11,-4916(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -4916);
	// addi r4,r11,28
	ctx.r4.s64 = r11.s64 + 28;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// stw r3,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r3.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r8,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r8.u32);
	// lwz r3,0(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r9,8(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r4,12(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r4,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r4.u32);
	// stw r9,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r9.u32);
	// stw r10,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r10.u32);
	// stw r3,28(r11)
	PPC_STORE_U32(r11.u32 + 28, ctx.r3.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E920C"))) PPC_WEAK_FUNC(sub_822E920C);
PPC_FUNC_IMPL(__imp__sub_822E920C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9210"))) PPC_WEAK_FUNC(sub_822E9210);
PPC_FUNC_IMPL(__imp__sub_822E9210) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,-7856
	ctx.r8.s64 = r11.s64 + -7856;
	// addi r10,r8,4
	ctx.r10.s64 = ctx.r8.s64 + 4;
loc_822E9220:
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9248
	if (cr6.eq) goto loc_822E9248;
	// lbz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e9248
	if (cr6.eq) goto loc_822E9248;
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// bne cr6,0x822e9248
	if (!cr6.eq) goto loc_822E9248;
	// stw r9,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r9.u32);
loc_822E9248:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9270
	if (cr6.eq) goto loc_822E9270;
	// lbz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e9270
	if (cr6.eq) goto loc_822E9270;
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// bne cr6,0x822e9270
	if (!cr6.eq) goto loc_822E9270;
	// stw r9,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r9.u32);
loc_822E9270:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9298
	if (cr6.eq) goto loc_822E9298;
	// lbz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e9298
	if (cr6.eq) goto loc_822E9298;
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// bne cr6,0x822e9298
	if (!cr6.eq) goto loc_822E9298;
	// stw r9,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r9.u32);
loc_822E9298:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e92c0
	if (cr6.eq) goto loc_822E92C0;
	// lbz r7,92(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e92c0
	if (cr6.eq) goto loc_822E92C0;
	// lwz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmplw cr6,r7,r3
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r3.u32, xer);
	// bne cr6,0x822e92c0
	if (!cr6.eq) goto loc_822E92C0;
	// stw r9,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r9.u32);
loc_822E92C0:
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r8,36
	r11.s64 = ctx.r8.s64 + 36;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x822e9220
	if (cr6.lt) goto loc_822E9220;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E92D4"))) PPC_WEAK_FUNC(sub_822E92D4);
PPC_FUNC_IMPL(__imp__sub_822E92D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E92D8"))) PPC_WEAK_FUNC(sub_822E92D8);
PPC_FUNC_IMPL(__imp__sub_822E92D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,-7856
	ctx.r10.s64 = r11.s64 + -7856;
	// lwz r11,-7856(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7856);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e92f4
	if (cr6.eq) goto loc_822E92F4;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E92F4:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9304
	if (cr6.eq) goto loc_822E9304;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9304:
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9314
	if (cr6.eq) goto loc_822E9314;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9314:
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9324
	if (cr6.eq) goto loc_822E9324;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9324:
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9334
	if (cr6.eq) goto loc_822E9334;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9334:
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9344
	if (cr6.eq) goto loc_822E9344;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9344:
	// lwz r11,24(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9354
	if (cr6.eq) goto loc_822E9354;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
loc_822E9354:
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r9,92(r11)
	PPC_STORE_U8(r11.u32 + 92, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9368"))) PPC_WEAK_FUNC(sub_822E9368);
PPC_FUNC_IMPL(__imp__sub_822E9368) {
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
	// bl 0x822e92d8
	ctx.lr = 0x822E9378;
	sub_822E92D8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7820(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7820);
	// bl 0x82741860
	ctx.lr = 0x822E9384;
	sub_82741860(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9394"))) PPC_WEAK_FUNC(sub_822E9394);
PPC_FUNC_IMPL(__imp__sub_822E9394) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9398"))) PPC_WEAK_FUNC(sub_822E9398);
PPC_FUNC_IMPL(__imp__sub_822E9398) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-7860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7860);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822e94b4
	if (!cr6.eq) goto loc_822E94B4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-7816
	ctx.r10.s64 = r11.s64 + -7816;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x822e93e8
	if (cr6.eq) goto loc_822E93E8;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-4208
	ctx.r4.s64 = ctx.r10.s64 + -4208;
	// b 0x822e93f0
	goto loc_822E93F0;
loc_822E93E8:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-4256
	ctx.r4.s64 = ctx.r10.s64 + -4256;
loc_822E93F0:
	// bl 0x821ca540
	ctx.lr = 0x822E93F4;
	sub_821CA540(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x822E93FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e940c
	if (cr6.eq) goto loc_822E940C;
	// bl 0x82611298
	ctx.lr = 0x822E9408;
	sub_82611298(ctx, base);
	// b 0x822e9410
	goto loc_822E9410;
loc_822E940C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822E9410:
	// stw r3,-7860(r31)
	PPC_STORE_U32(r31.u32 + -7860, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-5792
	ctx.r4.s64 = ctx.r10.s64 + -5792;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822E9434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822E943C;
	sub_821C9A90(ctx, base);
	// lwz r11,-7860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7860);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r8,-4272
	ctx.r4.s64 = ctx.r8.s64 + -4272;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x82192680
	ctx.lr = 0x822E9450;
	sub_82192680(ctx, base);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-4288
	ctx.r4.s64 = ctx.r7.s64 + -4288;
	// stw r3,-7864(r31)
	PPC_STORE_U32(r31.u32 + -7864, ctx.r3.u32);
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E946C;
	sub_8218A568(ctx, base);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// stw r3,-7876(r6)
	PPC_STORE_U32(ctx.r6.u32 + -7876, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r11,-7864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7864);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-4308
	ctx.r4.s64 = ctx.r4.s64 + -4308;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E948C;
	sub_8218A568(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// stw r3,-7872(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7872, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r11,-7864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7864);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-4324
	ctx.r4.s64 = ctx.r9.s64 + -4324;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822E94AC;
	sub_8218A568(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// stw r3,-7868(r8)
	PPC_STORE_U32(ctx.r8.u32 + -7868, ctx.r3.u32);
loc_822E94B4:
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

__attribute__((alias("__imp__sub_822E94CC"))) PPC_WEAK_FUNC(sub_822E94CC);
PPC_FUNC_IMPL(__imp__sub_822E94CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E94D0"))) PPC_WEAK_FUNC(sub_822E94D0);
PPC_FUNC_IMPL(__imp__sub_822E94D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	ctx.lr = 0x822E94D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r29,r5,48
	r29.s64 = ctx.r5.s64 + 48;
	// li r8,48
	ctx.r8.s64 = 48;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r5,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r5,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,32(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,64(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e9648
	if (cr6.eq) goto loc_822E9648;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e9648
	if (cr6.eq) goto loc_822E9648;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// beq cr6,0x822e958c
	if (cr6.eq) goto loc_822E958C;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-4096
	ctx.r4.s64 = ctx.r10.s64 + -4096;
	// bl 0x824804d0
	ctx.lr = 0x822E9558;
	sub_824804D0(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-4100(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4100);
	f0.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,-4104(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4108(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -4108);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,-30580(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30580);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f8.f64 = double(temp.f32);
	// b 0x822e95c8
	goto loc_822E95C8;
loc_822E958C:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-4120
	ctx.r4.s64 = ctx.r10.s64 + -4120;
	// bl 0x824804d0
	ctx.lr = 0x822E9598;
	sub_824804D0(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,-4124(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4124);
	f0.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f13,-4128(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4132(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -4132);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,-4136(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4136);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,-4140(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4140);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-4144(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -4144);
	ctx.f8.f64 = double(temp.f32);
loc_822E95C8:
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r5,r9,7040
	ctx.r5.s64 = ctx.r9.s64 + 7040;
	// lfs f11,12428(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12428);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r8,7056
	ctx.r4.s64 = ctx.r8.s64 + 7056;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stfs f10,7056(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + 7056, temp.u32);
	// stfs f0,7040(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 7040, temp.u32);
	// lfs f7,-4148(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -4148);
	ctx.f7.f64 = double(temp.f32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stfs f11,12(r5)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r5.u32 + 12, temp.u32);
	// stfs f7,12(r4)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r4.u32 + 12, temp.u32);
	// stfs f8,8(r4)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// stfs f9,4(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f12,8(r5)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// stfs f13,4(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// beq cr6,0x822e9648
	if (cr6.eq) goto loc_822E9648;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r10,272
	ctx.r10.s64 = 272;
	// li r9,416
	ctx.r9.s64 = 416;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r5,128(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 128);
	// lvx128 v59,r5,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r30,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8247a020
	ctx.lr = 0x822E9640;
	sub_8247A020(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8247a838
	ctx.lr = 0x822E9648;
	sub_8247A838(ctx, base);
loc_822E9648:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822E9650"))) PPC_WEAK_FUNC(sub_822E9650);
PPC_FUNC_IMPL(__imp__sub_822E9650) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,88(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 88);
	f0.f64 = double(temp.f32);
	// lfs f13,7016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7016);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x822e9750
	if (cr6.gt) goto loc_822E9750;
	// fdivs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f12,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r11,7056
	r11.s64 = r11.s64 + 7056;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lfs f12,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fneg f9,f12
	ctx.f9.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// fsel f8,f10,f10,f0
	ctx.f8.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsel f7,f10,f10,f0
	ctx.f7.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f0.f64;
	// fsubs f6,f8,f13
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// fsel f5,f6,f13,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f13.f64 : ctx.f7.f64;
	// fmadds f1,f5,f9,f12
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f9.f64 + ctx.f12.f64));
	// beq cr6,0x822e9750
	if (cr6.eq) goto loc_822E9750;
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822e9750
	if (cr6.eq) goto loc_822E9750;
	// lwz r9,0(r13)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r9.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822e96ec
	if (cr6.eq) goto loc_822E96EC;
	// addi r10,r10,272
	ctx.r10.s64 = ctx.r10.s64 + 272;
	// b 0x822e96f4
	goto loc_822E96F4;
loc_822E96EC:
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_822E96F4:
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// li r8,48
	ctx.r8.s64 = 48;
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r9,7072
	ctx.r7.s64 = ctx.r9.s64 + 7072;
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stfs f12,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-7436(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7436);
	// stfs f10,88(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f79c0
	ctx.lr = 0x822E9750;
	sub_822F79C0(ctx, base);
loc_822E9750:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9760"))) PPC_WEAK_FUNC(sub_822E9760);
PPC_FUNC_IMPL(__imp__sub_822E9760) {
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
	// bl 0x823d91ec
	ctx.lr = 0x822E9768;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// addi r30,r11,-7856
	r30.s64 = r11.s64 + -7856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_822E979C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e97b4
	if (cr6.eq) goto loc_822E97B4;
	// lbz r10,92(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e97dc
	if (cr6.eq) goto loc_822E97DC;
loc_822E97B4:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r30,32
	ctx.r10.s64 = r30.s64 + 32;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x822e979c
	if (cr6.lt) goto loc_822E979C;
loc_822E97C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_822E97DC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-7820(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7820);
	// bl 0x827419e0
	ctx.lr = 0x822E97F0;
	sub_827419E0(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822e980c
	if (cr6.eq) goto loc_822E980C;
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e980c
	if (cr6.eq) goto loc_822E980C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x822e9810
	goto loc_822E9810;
loc_822E980C:
	// li r11,0
	r11.s64 = 0;
loc_822E9810:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// rlwinm r31,r28,2,0,29
	r31.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,-16385
	ctx.r7.s64 = -16385;
	// li r6,1
	ctx.r6.s64 = 1;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r8,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r8.u32);
	// li r10,32
	ctx.r10.s64 = 32;
	// stw r7,20(r4)
	PPC_STORE_U32(ctx.r4.u32 + 20, ctx.r7.u32);
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwzx r8,r31,r30
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r11,48
	r11.s64 = 48;
	// stw r3,68(r8)
	PPC_STORE_U32(ctx.r8.u32 + 68, ctx.r3.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwzx r7,r31,r30
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// stw r25,80(r7)
	PPC_STORE_U32(ctx.r7.u32 + 80, r25.u32);
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stb r6,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, ctx.r6.u8);
	// lwzx r8,r31,r30
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stfs f0,88(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 88, temp.u32);
	// lwzx r7,r31,r30
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r29,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r29,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r29,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r6,r31,r30
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stfs f31,76(r6)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r6.u32 + 76, temp.u32);
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stfs f30,72(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// lwzx r11,r31,r30
	r11.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// stw r27,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r27.u32);
	// lwzx r10,r31,r30
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// lwz r3,96(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// bl 0x822e94d0
	ctx.lr = 0x822E98B8;
	sub_822E94D0(ctx, base);
	// cmpwi cr6,r28,8
	cr6.compare<int32_t>(r28.s32, 8, xer);
	// bge cr6,0x822e97c8
	if (!cr6.lt) goto loc_822E97C8;
	// lwzx r3,r31,r30
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822E98D4"))) PPC_WEAK_FUNC(sub_822E98D4);
PPC_FUNC_IMPL(__imp__sub_822E98D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E98D8"))) PPC_WEAK_FUNC(sub_822E98D8);
PPC_FUNC_IMPL(__imp__sub_822E98D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e99d8
	if (cr6.eq) goto loc_822E99D8;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,88(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,72(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f10,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,12428(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12428);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fmadds f8,f11,f0,f12
	ctx.f8.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// stfs f8,88(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// fcmpu cr6,f8,f9
	cr6.compare(ctx.f8.f64, ctx.f9.f64);
	// ble cr6,0x822e993c
	if (!cr6.gt) goto loc_822E993C;
	// li r11,0
	r11.s64 = 0;
	// stb r11,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, r11.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822E993C:
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e99c0
	if (cr6.eq) goto loc_822E99C0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822e99c0
	if (cr6.eq) goto loc_822E99C0;
	// lwz r10,68(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822e99c0
	if (cr6.eq) goto loc_822E99C0;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lwz r10,4(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lfs f0,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822E99C0:
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822e99d8
	if (cr6.eq) goto loc_822E99D8;
	// lwz r3,96(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	// bl 0x822e9650
	ctx.lr = 0x822E99D8;
	sub_822E9650(ctx, base);
loc_822E99D8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E99E8"))) PPC_WEAK_FUNC(sub_822E99E8);
PPC_FUNC_IMPL(__imp__sub_822E99E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stw r31,32(r11)
	PPC_STORE_U32(r11.u32 + 32, r31.u32);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x822e9398
	ctx.lr = 0x822E9A0C;
	sub_822E9398(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r6,32
	ctx.r6.s64 = 32;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// li r10,0
	ctx.r10.s64 = 0;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// stb r10,92(r31)
	PPC_STORE_U8(r31.u32 + 92, ctx.r10.u8);
	// stfs f13,84(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,12424(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12424);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12428(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 12428);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f0,52(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,56(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
	// stfs f13,76(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f12,72(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
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

__attribute__((alias("__imp__sub_822E9A98"))) PPC_WEAK_FUNC(sub_822E9A98);
PPC_FUNC_IMPL(__imp__sub_822E9A98) {
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
	ctx.lr = 0x822E9AA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r28,0
	r28.s64 = 0;
	// addi r29,r11,-7856
	r29.s64 = r11.s64 + -7856;
	// mr r30,r29
	r30.u64 = r29.u64;
loc_822E9AB4:
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x822E9ABC;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822e9ae4
	if (cr6.eq) goto loc_822E9AE4;
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x822E9AD0;
	sub_82130528(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r28,92(r31)
	PPC_STORE_U8(r31.u32 + 92, r28.u8);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// b 0x822e9ae8
	goto loc_822E9AE8;
loc_822E9AE4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822E9AE8:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// bl 0x822e99e8
	ctx.lr = 0x822E9AF0;
	sub_822E99E8(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r11,r29,32
	r11.s64 = r29.s64 + 32;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822e9ab4
	if (cr6.lt) goto loc_822E9AB4;
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x822E9B08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9b18
	if (cr6.eq) goto loc_822E9B18;
	// bl 0x82741848
	ctx.lr = 0x822E9B14;
	sub_82741848(ctx, base);
	// b 0x822e9b1c
	goto loc_822E9B1C;
loc_822E9B18:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
loc_822E9B1C:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r11,r11,-7820
	r11.s64 = r11.s64 + -7820;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// bl 0x82741b18
	ctx.lr = 0x822E9B30;
	sub_82741B18(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E9B38"))) PPC_WEAK_FUNC(sub_822E9B38);
PPC_FUNC_IMPL(__imp__sub_822E9B38) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7820(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7820);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9b60
	if (cr6.eq) goto loc_822E9B60;
	// bl 0x82741920
	ctx.lr = 0x822E9B60;
	sub_82741920(ctx, base);
loc_822E9B60:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r30,r11,-7856
	r30.s64 = r11.s64 + -7856;
	// mr r31,r30
	r31.u64 = r30.u64;
loc_822E9B6C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9b88
	if (cr6.eq) goto loc_822E9B88;
	// lbz r11,92(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822e9b88
	if (cr6.eq) goto loc_822E9B88;
	// bl 0x822e98d8
	ctx.lr = 0x822E9B88;
	sub_822E98D8(ctx, base);
loc_822E9B88:
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r30,32
	r11.s64 = r30.s64 + 32;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822e9b6c
	if (cr6.lt) goto loc_822E9B6C;
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

__attribute__((alias("__imp__sub_822E9BB0"))) PPC_WEAK_FUNC(sub_822E9BB0);
PPC_FUNC_IMPL(__imp__sub_822E9BB0) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7796(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7796);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9be4
	if (cr6.eq) goto loc_822E9BE4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E9BE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E9BE4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7796(r31)
	PPC_STORE_U32(r31.u32 + -7796, r11.u32);
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

__attribute__((alias("__imp__sub_822E9C00"))) PPC_WEAK_FUNC(sub_822E9C00);
PPC_FUNC_IMPL(__imp__sub_822E9C00) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,20
	ctx.r10.s64 = ctx.r3.s64 + 20;
loc_822E9C08:
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e9c28
	if (cr6.eq) goto loc_822E9C28;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,28
	cr6.compare<int32_t>(r11.s32, 28, xer);
	// blt cr6,0x822e9c08
	if (cr6.lt) goto loc_822E9C08;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822E9C28:
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,20(r9)
	PPC_STORE_U8(ctx.r9.u32 + 20, ctx.r7.u8);
	// lwzx r3,r8,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9C44"))) PPC_WEAK_FUNC(sub_822E9C44);
PPC_FUNC_IMPL(__imp__sub_822E9C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9C48"))) PPC_WEAK_FUNC(sub_822E9C48);
PPC_FUNC_IMPL(__imp__sub_822E9C48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_822E9C5C:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x822e9ca0
	if (cr6.eq) goto loc_822E9CA0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,28
	cr6.compare<int32_t>(ctx.r10.s32, 28, xer);
	// blt cr6,0x822e9c5c
	if (cr6.lt) goto loc_822E9C5C;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// addi r11,r3,164
	r11.s64 = ctx.r3.s64 + 164;
loc_822E9C80:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x822e9cac
	if (cr6.eq) goto loc_822E9CAC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// blt cr6,0x822e9c80
	if (cr6.lt) goto loc_822E9C80;
	// blr 
	return;
loc_822E9CA0:
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stb r9,20(r11)
	PPC_STORE_U8(r11.u32 + 20, ctx.r9.u8);
	// blr 
	return;
loc_822E9CAC:
	// add r11,r10,r3
	r11.u64 = ctx.r10.u64 + ctx.r3.u64;
	// stb r9,160(r11)
	PPC_STORE_U8(r11.u32 + 160, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9CB8"))) PPC_WEAK_FUNC(sub_822E9CB8);
PPC_FUNC_IMPL(__imp__sub_822E9CB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,160
	ctx.r10.s64 = ctx.r3.s64 + 160;
loc_822E9CC0:
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822e9ce0
	if (cr6.eq) goto loc_822E9CE0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x822e9cc0
	if (cr6.lt) goto loc_822E9CC0;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822E9CE0:
	// addi r10,r11,41
	ctx.r10.s64 = r11.s64 + 41;
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,160(r9)
	PPC_STORE_U8(ctx.r9.u32 + 160, ctx.r7.u8);
	// lwzx r3,r8,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9CFC"))) PPC_WEAK_FUNC(sub_822E9CFC);
PPC_FUNC_IMPL(__imp__sub_822E9CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9D00"))) PPC_WEAK_FUNC(sub_822E9D00);
PPC_FUNC_IMPL(__imp__sub_822E9D00) {
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
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// bl 0x82130588
	ctx.lr = 0x822E9D20;
	sub_82130588(ctx, base);
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x82130588
	ctx.lr = 0x822E9D28;
	sub_82130588(ctx, base);
	// addi r31,r31,128
	r31.s64 = r31.s64 + 128;
	// li r30,3
	r30.s64 = 3;
loc_822E9D30:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822e9d50
	if (cr6.eq) goto loc_822E9D50;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822E9D50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822E9D50:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822e9d30
	if (!cr0.eq) goto loc_822E9D30;
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

__attribute__((alias("__imp__sub_822E9D74"))) PPC_WEAK_FUNC(sub_822E9D74);
PPC_FUNC_IMPL(__imp__sub_822E9D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822E9D78"))) PPC_WEAK_FUNC(sub_822E9D78);
PPC_FUNC_IMPL(__imp__sub_822E9D78) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
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
	// lwz r11,100(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// stfs f1,52(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 52, temp.u32);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x822e9d94
	if (!cr6.eq) goto loc_822E9D94;
	// lwz r11,104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
loc_822E9D94:
	// lwz r9,120(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// rlwinm r11,r10,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,52
	ctx.r8.s64 = ctx.r1.s64 + 52;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,48
	ctx.r4.s64 = 48;
	// lvlx128 v61,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vupkd3d128 v60,v62,4
	temp.f32 = 3.0f;
	temp.s32 += v62.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v62.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v60 = vTemp;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vrlimi128 v63,v59,1,0
	simde_mm_store_ps(v63.f32, simde_mm_blend_ps(simde_mm_load_ps(v63.f32), simde_mm_permute_ps(simde_mm_load_ps(v59.f32), 228), 1));
	// li r8,255
	ctx.r8.s64 = 255;
	// vspltw128 v57,v60,3
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0x0));
	// vmrghw128 v56,v62,v58
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// lvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// vor128 v54,v56,v56
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vmrghw128 v53,v57,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vrlimi128 v54,v56,3,2
	simde_mm_store_ps(v54.f32, simde_mm_blend_ps(simde_mm_load_ps(v54.f32), simde_mm_permute_ps(simde_mm_load_ps(v56.f32), 78), 3));
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v55,v52,1,0
	simde_mm_store_ps(v55.f32, simde_mm_blend_ps(simde_mm_load_ps(v55.f32), simde_mm_permute_ps(simde_mm_load_ps(v52.f32), 228), 1));
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// vor128 v51,v53,v53
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// stvx128 v54,r6,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 120);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// vrlimi128 v51,v53,3,2
	simde_mm_store_ps(v51.f32, simde_mm_blend_ps(simde_mm_load_ps(v51.f32), simde_mm_permute_ps(simde_mm_load_ps(v53.f32), 78), 3));
	// stvx128 v51,r5,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,124(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// stwx r8,r4,r7
	PPC_STORE_U32(ctx.r4.u32 + ctx.r7.u32, ctx.r8.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822E9E30"))) PPC_WEAK_FUNC(sub_822E9E30);
PPC_FUNC_IMPL(__imp__sub_822E9E30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	ctx.lr = 0x822E9E38;
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
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r30,100(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// ble cr6,0x822e9e60
	if (!cr6.gt) goto loc_822E9E60;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_822E9E60:
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2470
	ctx.lr = 0x822E9E6C;
	sub_821D2470(ctx, base);
	// lvlx128 v63,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r11,r30,6,0,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// li r8,32
	ctx.r8.s64 = 32;
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// vrlimi128 v62,v63,1,1
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// li r9,255
	ctx.r9.s64 = 255;
	// stvx128 v62,r10,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lvx128 v61,r0,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// vrlimi128 v61,v63,1,1
	simde_mm_store_ps(v61.f32, simde_mm_blend_ps(simde_mm_load_ps(v61.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// stvx128 v61,r6,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,124(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stwx r9,r7,r5
	PPC_STORE_U32(ctx.r7.u32 + ctx.r5.u32, ctx.r9.u32);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x822e9ecc
	if (!cr6.gt) goto loc_822E9ECC;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_822E9ECC:
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r8,r10
	r11.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v60,v63,1,1
	simde_mm_store_ps(v60.f32, simde_mm_blend_ps(simde_mm_load_ps(v60.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrlimi128 v59,v63,1,1
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v63.f32), 147), 1));
	// stvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,124(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stwx r9,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822E9F10"))) PPC_WEAK_FUNC(sub_822E9F10);
PPC_FUNC_IMPL(__imp__sub_822E9F10) {
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
	// bl 0x823d91f0
	ctx.lr = 0x822E9F18;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stfs f1,228(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// mr r30,r8
	r30.u64 = ctx.r8.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x822e9f50
	if (cr6.lt) goto loc_822E9F50;
	// li r11,0
	r11.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// stw r11,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r11.u32);
loc_822E9F50:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,208
	ctx.r10.s64 = 208;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,-7796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7796);
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f3
	ctx.f13.f64 = double(float(f0.f64 * ctx.f3.f64));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// bl 0x821d2470
	ctx.lr = 0x822E9F80;
	sub_821D2470(ctx, base);
	// lvlx128 v62,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lwz r8,100(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,120(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r6,r8,6,0,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// li r3,32
	ctx.r3.s64 = 32;
	// vrlimi128 v60,v61,1,1
	simde_mm_store_ps(v60.f32, simde_mm_blend_ps(simde_mm_load_ps(v60.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 147), 1));
	// addi r9,r1,228
	ctx.r9.s64 = ctx.r1.s64 + 228;
	// li r8,16
	ctx.r8.s64 = 16;
	// vupkd3d128 v58,v59,4
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v59.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v58 = vTemp;
	// li r27,48
	r27.s64 = 48;
	// li r26,255
	r26.s64 = 255;
	// stvx128 v60,r6,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lvx128 v57,r0,r29
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,100(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r7,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// lvlx128 v56,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// vrlimi128 v57,v61,1,1
	simde_mm_store_ps(v57.f32, simde_mm_blend_ps(simde_mm_load_ps(v57.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 147), 1));
	// vspltw128 v55,v56,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// vspltw128 v54,v58,3
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x0));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stvx128 v57,r11,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// vmrghw128 v53,v59,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// lwz r7,100(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r7,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// vmrghw128 v52,v54,v55
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vor128 v51,v53,v53
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// vor128 v50,v52,v52
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vrlimi128 v51,v53,3,2
	simde_mm_store_ps(v51.f32, simde_mm_blend_ps(simde_mm_load_ps(v51.f32), simde_mm_permute_ps(simde_mm_load_ps(v53.f32), 78), 3));
	// vrlimi128 v50,v52,3,2
	simde_mm_store_ps(v50.f32, simde_mm_blend_ps(simde_mm_load_ps(v50.f32), simde_mm_permute_ps(simde_mm_load_ps(v52.f32), 78), 3));
	// stvx128 v51,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// stvx128 v50,r9,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,124(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwz r7,100(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r26,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, r26.u32);
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stw r10,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r10.u32);
	// bl 0x822e9e30
	ctx.lr = 0x822EA078;
	sub_822E9E30(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822EA084"))) PPC_WEAK_FUNC(sub_822EA084);
PPC_FUNC_IMPL(__imp__sub_822EA084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA088"))) PPC_WEAK_FUNC(sub_822EA088);
PPC_FUNC_IMPL(__imp__sub_822EA088) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-3756
	ctx.r9.s64 = r11.s64 + -3756;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822EA0C0;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-7792(r8)
	PPC_STORE_U32(ctx.r8.u32 + -7792, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822EA0D4;
	sub_822E6940(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822ea0ec
	if (cr6.eq) goto loc_822EA0EC;
	// bl 0x82130588
	ctx.lr = 0x822EA0E8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822EA0EC:
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

__attribute__((alias("__imp__sub_822EA104"))) PPC_WEAK_FUNC(sub_822EA104);
PPC_FUNC_IMPL(__imp__sub_822EA104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA108"))) PPC_WEAK_FUNC(sub_822EA108);
PPC_FUNC_IMPL(__imp__sub_822EA108) {
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
	// bl 0x822e6b38
	ctx.lr = 0x822EA120;
	sub_822E6B38(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-3756
	ctx.r9.s64 = r11.s64 + -3756;
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// lwz r3,-8092(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// bl 0x822e5138
	ctx.lr = 0x822EA150;
	sub_822E5138(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r6,-3732
	ctx.r4.s64 = ctx.r6.s64 + -3732;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// lfs f0,7444(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// stfs f0,216(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f0,252(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 252, temp.u32);
	// stfs f0,248(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stfs f0,244(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 244, temp.u32);
	// stfs f0,240(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// stfs f0,284(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 284, temp.u32);
	// stfs f0,280(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// stfs f0,276(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 276, temp.u32);
	// stfs f0,272(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 272, temp.u32);
	// stfs f0,316(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 316, temp.u32);
	// stfs f0,312(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 312, temp.u32);
	// stfs f0,308(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 308, temp.u32);
	// stfs f0,304(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 304, temp.u32);
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

__attribute__((alias("__imp__sub_822EA1BC"))) PPC_WEAK_FUNC(sub_822EA1BC);
PPC_FUNC_IMPL(__imp__sub_822EA1BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA1C0"))) PPC_WEAK_FUNC(sub_822EA1C0);
PPC_FUNC_IMPL(__imp__sub_822EA1C0) {
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
	PPCRegister f0{};
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
	ctx.lr = 0x822EA1C8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r24,32
	r24.s64 = 32;
	// lvlx128 v61,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r25,48
	r25.s64 = 48;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// li r6,64
	ctx.r6.s64 = 64;
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r5,80
	ctx.r5.s64 = 80;
	// lvlx128 v60,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r29,0
	r29.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// addi r28,r31,128
	r28.s64 = r31.s64 + 128;
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// li r26,3
	r26.s64 = 3;
	// stw r4,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r4.u32);
	// stb r29,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r29.u8);
	// stvx128 v58,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r29,118(r31)
	PPC_STORE_U8(r31.u32 + 118, r29.u8);
	// stvx128 v57,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
	// lis r23,-32120
	r23.s64 = -2105016320;
	// stvx128 v59,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822EA268:
	// lwz r30,0(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r27,r29
	r27.u64 = r29.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea298
	if (cr6.eq) goto loc_822EA298;
	// lbz r27,6(r30)
	r27.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x822ea298
	if (!cr6.eq) goto loc_822EA298;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EA298;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA298:
	// lwz r11,-7796(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -7796);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,336(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// lhz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r7,4(r9)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r9.u32 + 4);
	// mullw r5,r7,r8
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// bl 0x8244d150
	ctx.lr = 0x822EA2BC;
	sub_8244D150(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea2f0
	if (cr6.eq) goto loc_822EA2F0;
	// lbz r11,6(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ea2f0
	if (cr6.eq) goto loc_822EA2F0;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ea2f0
	if (!cr6.eq) goto loc_822EA2F0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EA2F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA2F0:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x822ea268
	if (!cr0.eq) goto loc_822EA268;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// vupkd3d128 v55,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v55 = vTemp;
	// vspltw128 v62,v55,3
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0x0));
	// ble cr6,0x822ea37c
	if (!cr6.gt) goto loc_822EA37C;
	// vmrghw128 v54,v63,v63
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// vmrghw128 v53,v62,v63
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// mr r11,r29
	r11.u64 = r29.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// vmrghw128 v62,v53,v54
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
loc_822EA330:
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// add r6,r11,r8
	ctx.r6.u64 = r11.u64 + ctx.r8.u64;
	// stvx128 v63,r6,r24
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// add r5,r11,r8
	ctx.r5.u64 = r11.u64 + ctx.r8.u64;
	// stvx128 v63,r5,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,120(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// add r4,r11,r8
	ctx.r4.u64 = r11.u64 + ctx.r8.u64;
	// stvx128 v62,r4,r25
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// stwx r29,r10,r3
	PPC_STORE_U32(ctx.r10.u32 + ctx.r3.u32, r29.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// lwz r8,104(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x822ea330
	if (cr6.lt) goto loc_822EA330;
loc_822EA37C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822EA384"))) PPC_WEAK_FUNC(sub_822EA384);
PPC_FUNC_IMPL(__imp__sub_822EA384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA388"))) PPC_WEAK_FUNC(sub_822EA388);
PPC_FUNC_IMPL(__imp__sub_822EA388) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822EA390;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,32(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f31,20(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f31,24(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// lwz r30,464(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 464);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea490
	if (cr6.eq) goto loc_822EA490;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82564e28
	ctx.lr = 0x822EA3D4;
	sub_82564E28(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x822ea3e4
	if (!cr6.lt) goto loc_822EA3E4;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
	// b 0x822ea3f8
	goto loc_822EA3F8;
loc_822EA3E4:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f31,84(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	f31.f64 = double(temp.f32);
	// bl 0x82564e28
	ctx.lr = 0x822EA3F4;
	sub_82564E28(ctx, base);
	// fdivs f13,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 / f31.f64));
loc_822EA3F8:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r10,r11,-3776
	ctx.r10.s64 = r11.s64 + -3776;
	// lfs f12,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// blt cr6,0x822ea44c
	if (cr6.lt) goto loc_822EA44C;
	// lhz r11,46(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 46);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822ea430
	if (!cr6.eq) goto loc_822EA430;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// b 0x822ea43c
	goto loc_822EA43C;
loc_822EA430:
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
loc_822EA43C:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fdivs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// stfs f10,32(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
loc_822EA44C:
	// lfs f0,48(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	f0.f64 = double(temp.f32);
	// lfs f13,520(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 520);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822ea490
	if (cr6.lt) goto loc_822EA490;
	// lhz r11,44(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 44);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822ea474
	if (!cr6.eq) goto loc_822EA474;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// b 0x822ea480
	goto loc_822EA480;
loc_822EA474:
	// lbzx r11,r11,r10
	r11.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// extsb r10,r11
	ctx.r10.s64 = r11.s8;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_822EA480:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsubs f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// stfs f11,32(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
loc_822EA490:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822EA4A0"))) PPC_WEAK_FUNC(sub_822EA4A0);
PPC_FUNC_IMPL(__imp__sub_822EA4A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// bl 0x823d91f0
	ctx.lr = 0x822EA4A8;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9d8
	ctx.lr = 0x822EA4B0;
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
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r11,r5,320
	r11.s64 = ctx.r5.s64 + 320;
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// li r7,16
	ctx.r7.s64 = 16;
	// lfs f0,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r28,48
	r28.s64 = 48;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vspltw128 v126,v63,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f0,-6176(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -6176);
	f0.f64 = double(temp.f32);
	// lfs f12,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lvx128 v127,r11,r7
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v0,r11,r28
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f30,f12,f0
	f30.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lfs f13,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// vmaddcfp128 v126,v127,v126,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v126.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v126.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stfs f30,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fdivs f28,f13,f12
	f28.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// bl 0x822ea388
	ctx.lr = 0x822EA52C;
	sub_822EA388(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f29,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lwz r26,144(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// beq cr6,0x822ea78c
	if (cr6.eq) goto loc_822EA78C;
	// lfs f3,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f3.f64 = double(temp.f32);
	// fcmpu cr6,f3,f29
	cr6.compare(ctx.f3.f64, f29.f64);
	// beq cr6,0x822ea78c
	if (cr6.eq) goto loc_822EA78C;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r27,1
	r27.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// cmpw cr6,r11,r26
	cr6.compare<int32_t>(r11.s32, r26.s32, xer);
	// beq cr6,0x822ea574
	if (cr6.eq) goto loc_822EA574;
	// lbz r11,116(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ea574
	if (!cr6.eq) goto loc_822EA574;
	// stb r27,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r27.u8);
	// stw r29,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r29.u32);
loc_822EA574:
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v126,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v62.f32)));
	// lfs f12,-3708(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -3708);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f31,f9
	f31.f64 = double(float(sqrt(ctx.f9.f64)));
	// fcmpu cr6,f31,f12
	cr6.compare(f31.f64, ctx.f12.f64);
	// blt cr6,0x822ea7a0
	if (cr6.lt) goto loc_822EA7A0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vpermwi128 v61,v127,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// vpermwi128 v0,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fneg f0,f30
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vor128 v60,v126,v126
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// vor128 v59,v126,v126
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// fdivs f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 / f31.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvlx128 v54,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// vmulfp128 v127,v63,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v53.f32)));
	// lvlx128 v58,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v57,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v58,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vspltw128 v55,v57,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// vpermwi128 v52,v127,99
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vpermwi128 v13,v127,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// lbz r4,116(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 116);
	// lfs f12,96(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// fmuls f30,f12,f28
	f30.f64 = double(float(ctx.f12.f64 * f28.f64));
	// vmulfp128 v12,v61,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v52.f32)));
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp128 v60,v0,v55,v60
	simde_mm_store_ps(v60.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v55.f32)), simde_mm_load_ps(v60.f32)));
	// vmaddfp128 v59,v0,v56,v59
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v56.f32)), simde_mm_load_ps(v59.f32)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822ea6f0
	if (cr6.eq) goto loc_822EA6F0;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stvx128 v127,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r31,64
	ctx.r8.s64 = r31.s64 + 64;
	// addi r9,r31,80
	ctx.r9.s64 = r31.s64 + 80;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lvlx128 v50,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// lvlx128 v51,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v51,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vspltw128 v11,v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// vmaddfp v10,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v9,v0,v11,v13
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v10,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822ea698
	if (cr6.eq) goto loc_822EA698;
	// extsb r4,r11
	ctx.r4.s64 = r11.s8;
loc_822EA698:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f29.f64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x822e9f10
	ctx.lr = 0x822EA6AC;
	sub_822E9F10(ctx, base);
	// stw r26,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r26.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stb r29,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r29.u8);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = f29.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x822e9f10
	ctx.lr = 0x822EA6D4;
	sub_822E9F10(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r11,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r11.u32);
	// stvx128 v126,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// b 0x822ea7a0
	goto loc_822EA7A0;
loc_822EA6F0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// lfs f0,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bgt cr6,0x822ea754
	if (cr6.gt) goto loc_822EA754;
	// lfs f0,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,-3712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -3712);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f8,f9,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// blt cr6,0x822ea754
	if (cr6.lt) goto loc_822EA754;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e9d78
	ctx.lr = 0x822EA750;
	sub_822E9D78(ctx, base);
	// b 0x822ea7a0
	goto loc_822EA7A0;
loc_822EA754:
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f29.f64;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822e9f10
	ctx.lr = 0x822EA770;
	sub_822E9F10(ctx, base);
	// stvx128 v127,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v126,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r27,118(r31)
	PPC_STORE_U8(r31.u32 + 118, r27.u8);
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// b 0x822ea7a0
	goto loc_822EA7A0;
loc_822EA78C:
	// li r11,0
	r11.s64 = 0;
	// stfs f29,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r11,116(r31)
	PPC_STORE_U8(r31.u32 + 116, r11.u8);
	// stw r10,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r10.u32);
loc_822EA7A0:
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
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba24
	ctx.lr = 0x822EA7BC;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822EA7C0"))) PPC_WEAK_FUNC(sub_822EA7C0);
PPC_FUNC_IMPL(__imp__sub_822EA7C0) {
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
	ctx.lr = 0x822EA7C8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r25,-32131
	r25.s64 = -2105737216;
	// lis r11,-21846
	r11.s64 = -1431699456;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r28,r11,43691
	r28.u64 = r11.u64 | 43691;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,11724(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 11724);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mulhwu r8,r9,r28
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(r28.u32)) >> 32;
	// rlwinm r11,r8,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r7,r9
	r11.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r6,r11,32
	ctx.r6.s64 = r11.s64 + 32;
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r4,r31
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + r31.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x821b3478
	ctx.lr = 0x822EA810;
	sub_821B3478(ctx, base);
	// lwz r10,11724(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 11724);
	// lwz r6,104(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// li r26,0
	r26.s64 = 0;
	// mulhwu r7,r8,r28
	ctx.r7.u64 = (uint64_t(ctx.r8.u32) * uint64_t(r28.u32)) >> 32;
	// rlwinm r11,r7,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r24,8(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r11,r9
	ctx.r5.u64 = r11.u64 + ctx.r9.u64;
	// subf r4,r5,r8
	ctx.r4.s64 = ctx.r8.s64 - ctx.r5.s64;
	// slw r27,r3,r4
	r27.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r3.u32 << (ctx.r4.u8 & 0x3F));
	// ble cr6,0x822ea8a4
	if (!cr6.gt) goto loc_822EA8A4;
	// li r30,0
	r30.s64 = 0;
	// li r29,0
	r29.s64 = 0;
loc_822EA850:
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// and r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & r27.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ea888
	if (cr6.eq) goto loc_822EA888;
	// lwz r11,120(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// li r5,64
	ctx.r5.s64 = 64;
	// add r3,r29,r24
	ctx.r3.u64 = r29.u64 + r24.u64;
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// bl 0x8244d5c0
	ctx.lr = 0x822EA878;
	sub_8244D5C0(ctx, base);
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// andc r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & ~r27.u64;
	// stwx r9,r11,r30
	PPC_STORE_U32(r11.u32 + r30.u32, ctx.r9.u32);
loc_822EA888:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,64
	r29.s64 = r29.s64 + 64;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x822ea850
	if (cr6.lt) goto loc_822EA850;
	// lwz r10,11724(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 11724);
loc_822EA8A4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r6,108(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// addi r9,r10,2
	ctx.r9.s64 = ctx.r10.s64 + 2;
	// li r3,4
	ctx.r3.s64 = 4;
	// mulhwu r8,r9,r28
	ctx.r8.u64 = (uint64_t(ctx.r9.u32) * uint64_t(r28.u32)) >> 32;
	// lwz r11,-7796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7796);
	// lwz r4,340(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 340);
	// rlwinm r11,r8,31,1,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r7,r9
	r11.s64 = ctx.r9.s64 - ctx.r7.s64;
	// addi r5,r11,32
	ctx.r5.s64 = r11.s64 + 32;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r11,r31
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x821793e0
	ctx.lr = 0x822EA8E0;
	sub_821793E0(ctx, base);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ea914
	if (cr6.eq) goto loc_822EA914;
	// lbz r11,6(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ea914
	if (cr6.eq) goto loc_822EA914;
	// lbz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822ea914
	if (!cr6.eq) goto loc_822EA914;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EA914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA914:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822EA91C"))) PPC_WEAK_FUNC(sub_822EA91C);
PPC_FUNC_IMPL(__imp__sub_822EA91C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EA920"))) PPC_WEAK_FUNC(sub_822EA920);
PPC_FUNC_IMPL(__imp__sub_822EA920) {
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
	ctx.lr = 0x822EA928;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r31,r29,48
	r31.s64 = r29.s64 + 48;
	// addi r10,r11,-3732
	ctx.r10.s64 = r11.s64 + -3732;
	// li r28,28
	r28.s64 = 28;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
loc_822EA944:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea960
	if (cr6.eq) goto loc_822EA960;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e9d00
	ctx.lr = 0x822EA958;
	sub_822E9D00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822EA960;
	sub_82130588(ctx, base);
loc_822EA960:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822ea944
	if (!cr0.eq) goto loc_822EA944;
	// addi r31,r29,164
	r31.s64 = r29.s64 + 164;
	// li r28,4
	r28.s64 = 4;
loc_822EA974:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ea990
	if (cr6.eq) goto loc_822EA990;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822e9d00
	ctx.lr = 0x822EA988;
	sub_822E9D00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822EA990;
	sub_82130588(ctx, base);
loc_822EA990:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822ea974
	if (!cr0.eq) goto loc_822EA974;
	// lwz r3,180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// bl 0x82130588
	ctx.lr = 0x822EA9A4;
	sub_82130588(ctx, base);
	// lwz r31,184(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 184);
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EA9B0;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ea9d8
	if (!cr6.eq) goto loc_822EA9D8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ea9d8
	if (cr6.eq) goto loc_822EA9D8;
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
	ctx.lr = 0x822EA9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA9D8:
	// lwz r3,188(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ea9f8
	if (cr6.eq) goto loc_822EA9F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EA9F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EA9F8:
	// lwz r3,336(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 336);
	// bl 0x82130588
	ctx.lr = 0x822EAA00;
	sub_82130588(ctx, base);
	// lwz r3,340(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 340);
	// bl 0x821870b8
	ctx.lr = 0x822EAA08;
	sub_821870B8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-3756
	ctx.r9.s64 = r11.s64 + -3756;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// bl 0x822e5148
	ctx.lr = 0x822EAA24;
	sub_822E5148(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,-7792(r8)
	PPC_STORE_U32(ctx.r8.u32 + -7792, r11.u32);
	// bl 0x822e6940
	ctx.lr = 0x822EAA38;
	sub_822E6940(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822EAA40"))) PPC_WEAK_FUNC(sub_822EAA40);
PPC_FUNC_IMPL(__imp__sub_822EAA40) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822EAA48;
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r9,1023
	ctx.r9.s64 = 67043328;
	// addi r8,r30,-1
	ctx.r8.s64 = r30.s64 + -1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r7,r30,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// ori r6,r9,65535
	ctx.r6.u64 = ctx.r9.u64 | 65535;
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// li r29,-1
	r29.s64 = -1;
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// cmplw cr6,r30,r6
	cr6.compare<uint32_t>(r30.u32, ctx.r6.u32, xer);
	// stw r7,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r7.u32);
	// rlwinm r3,r30,6,0,25
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// ble cr6,0x822eaaa4
	if (!cr6.gt) goto loc_822EAAA4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822EAAA4:
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82130550
	ctx.lr = 0x822EAAAC;
	sub_82130550(ctx, base);
	// lis r11,16383
	r11.s64 = 1073676288;
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmplw cr6,r30,r10
	cr6.compare<uint32_t>(r30.u32, ctx.r10.u32, xer);
	// ble cr6,0x822eaac8
	if (!cr6.gt) goto loc_822EAAC8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822EAAC8:
	// bl 0x82130528
	ctx.lr = 0x822EAACC;
	sub_82130528(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
	// addi r29,r31,128
	r29.s64 = r31.s64 + 128;
	// li r30,3
	r30.s64 = 3;
	// lwz r11,-7796(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7796);
	// lwz r28,336(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 336);
loc_822EAAE4:
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,108(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x821b4838
	ctx.lr = 0x822EAAF8;
	sub_821B4838(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822eaae4
	if (!cr0.eq) goto loc_822EAAE4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ea1c0
	ctx.lr = 0x822EAB10;
	sub_822EA1C0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822EAB18"))) PPC_WEAK_FUNC(sub_822EAB18);
PPC_FUNC_IMPL(__imp__sub_822EAB18) {
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
	// bl 0x822ea920
	ctx.lr = 0x822EAB38;
	sub_822EA920(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eab50
	if (cr6.eq) goto loc_822EAB50;
	// bl 0x82130588
	ctx.lr = 0x822EAB4C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822EAB50:
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

__attribute__((alias("__imp__sub_822EAB68"))) PPC_WEAK_FUNC(sub_822EAB68);
PPC_FUNC_IMPL(__imp__sub_822EAB68) {
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
	ctx.lr = 0x822EAB70;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r3,32
	ctx.r3.s64 = 32;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x822EAB8C;
	sub_82130528(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32131
	ctx.r6.s64 = -2105737216;
	// lfs f0,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// stfs f13,0(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// addi r29,r6,30576
	r29.s64 = ctx.r6.s64 + 30576;
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f31,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f31.f64 = double(temp.f32);
	// addi r4,r5,-3680
	ctx.r4.s64 = ctx.r5.s64 + -3680;
	// stfs f31,12(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// stfs f31,16(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// lfs f13,-13148(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// lfs f12,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,24(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// stfs f12,28(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// bl 0x821ca540
	ctx.lr = 0x822EABFC;
	sub_821CA540(ctx, base);
	// lis r3,-32124
	ctx.r3.s64 = -2105278464;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-3692
	ctx.r4.s64 = r11.s64 + -3692;
	// lwz r3,-25232(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -25232);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822EAC20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822EAC2C;
	sub_821C9A90(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r29,r7,-3704
	r29.s64 = ctx.r7.s64 + -3704;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24728);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EAC58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EAC8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,188(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-27772
	ctx.r4.s64 = ctx.r10.s64 + -27772;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822EACA4;
	sub_8218B688(ctx, base);
	// lwz r7,188(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-27840
	ctx.r4.s64 = ctx.r8.s64 + -27840;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EACC0;
	sub_8218A568(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r3,196(r31)
	PPC_STORE_U32(r31.u32 + 196, ctx.r3.u32);
	// stfs f31,220(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// li r3,16
	ctx.r3.s64 = 16;
	// lfs f0,11360(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11360);
	f0.f64 = double(temp.f32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f0,212(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f0,216(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x822EACE4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eacf4
	if (cr6.eq) goto loc_822EACF4;
	// bl 0x8218fe20
	ctx.lr = 0x822EACF0;
	sub_8218FE20(ctx, base);
	// b 0x822eacf8
	goto loc_822EACF8;
loc_822EACF4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822EACF8:
	// stw r3,336(r31)
	PPC_STORE_U32(r31.u32 + 336, ctx.r3.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,6
	ctx.r5.s64 = 6;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821902b0
	ctx.lr = 0x822EAD0C;
	sub_821902B0(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// bl 0x82190540
	ctx.lr = 0x822EAD1C;
	sub_82190540(ctx, base);
	// li r6,7
	ctx.r6.s64 = 7;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82190640
	ctx.lr = 0x822EAD30;
	sub_82190640(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,336(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 336);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187150
	ctx.lr = 0x822EAD48;
	sub_82187150(ctx, base);
	// stw r3,340(r31)
	PPC_STORE_U32(r31.u32 + 340, ctx.r3.u32);
	// mr r29,r30
	r29.u64 = r30.u64;
	// addi r28,r31,48
	r28.s64 = r31.s64 + 48;
	// addi r27,r31,20
	r27.s64 = r31.s64 + 20;
loc_822EAD58:
	// stbx r30,r27,r29
	PPC_STORE_U8(r27.u32 + r29.u32, r30.u8);
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x822EAD64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ead74
	if (cr6.eq) goto loc_822EAD74;
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// b 0x822ead78
	goto loc_822EAD78;
loc_822EAD74:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822EAD78:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x822eaa40
	ctx.lr = 0x822EAD84;
	sub_822EAA40(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r29,28
	cr6.compare<int32_t>(r29.s32, 28, xer);
	// blt cr6,0x822ead58
	if (cr6.lt) goto loc_822EAD58;
	// addi r28,r31,164
	r28.s64 = r31.s64 + 164;
	// mr r29,r30
	r29.u64 = r30.u64;
	// addi r31,r31,160
	r31.s64 = r31.s64 + 160;
loc_822EADA0:
	// li r3,144
	ctx.r3.s64 = 144;
	// bl 0x82130528
	ctx.lr = 0x822EADA8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eadb8
	if (cr6.eq) goto loc_822EADB8;
	// stw r30,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r30.u32);
	// b 0x822eadbc
	goto loc_822EADBC;
loc_822EADB8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822EADBC:
	// stw r3,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r3.u32);
	// li r4,1024
	ctx.r4.s64 = 1024;
	// bl 0x822eaa40
	ctx.lr = 0x822EADC8;
	sub_822EAA40(ctx, base);
	// stbx r30,r31,r29
	PPC_STORE_U8(r31.u32 + r29.u32, r30.u8);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r29,4
	cr6.compare<int32_t>(r29.s32, 4, xer);
	// blt cr6,0x822eada0
	if (cr6.lt) goto loc_822EADA0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822EADE8"))) PPC_WEAK_FUNC(sub_822EADE8);
PPC_FUNC_IMPL(__imp__sub_822EADE8) {
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
	// li r3,352
	ctx.r3.s64 = 352;
	// bl 0x82130528
	ctx.lr = 0x822EADFC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eae0c
	if (cr6.eq) goto loc_822EAE0C;
	// bl 0x822ea108
	ctx.lr = 0x822EAE08;
	sub_822EA108(ctx, base);
	// b 0x822eae10
	goto loc_822EAE10;
loc_822EAE0C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822EAE10:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-7796
	r11.s64 = r11.s64 + -7796;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// bl 0x822eab68
	ctx.lr = 0x822EAE20;
	sub_822EAB68(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EAE30"))) PPC_WEAK_FUNC(sub_822EAE30);
PPC_FUNC_IMPL(__imp__sub_822EAE30) {
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
	ctx.lr = 0x822EAE38;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,20
	r11.s64 = 20;
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822EAE50;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r9,100(r1)
	PPC_STORE_U64(ctx.r1.u32 + 100, ctx.r9.u64);
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// bl 0x8217f768
	ctx.lr = 0x822EAE70;
	sub_8217F768(ctx, base);
	// lis r8,-32124
	ctx.r8.s64 = -2105278464;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r4,r7,-31280
	ctx.r4.s64 = ctx.r7.s64 + -31280;
	// lwz r3,-26876(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822EAE84;
	sub_8217C088(ctx, base);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r6,184(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,196(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822EAE9C;
	sub_82189CE0(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r6,192(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82187f40
	ctx.lr = 0x822EAEB0;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822eaf34
	if (cr6.eq) goto loc_822EAF34;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82187b88
	ctx.lr = 0x822EAEC4;
	sub_82187B88(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// addi r28,r31,20
	r28.s64 = r31.s64 + 20;
loc_822EAED0:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eaee4
	if (cr6.eq) goto loc_822EAEE4;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822ea7c0
	ctx.lr = 0x822EAEE4;
	sub_822EA7C0(ctx, base);
loc_822EAEE4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,28
	cr6.compare<int32_t>(r30.s32, 28, xer);
	// blt cr6,0x822eaed0
	if (cr6.lt) goto loc_822EAED0;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r31,164
	r29.s64 = r31.s64 + 164;
	// addi r28,r31,160
	r28.s64 = r31.s64 + 160;
loc_822EAF00:
	// lbzx r11,r28,r30
	r11.u64 = PPC_LOAD_U8(r28.u32 + r30.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eaf14
	if (cr6.eq) goto loc_822EAF14;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822ea7c0
	ctx.lr = 0x822EAF14;
	sub_822EA7C0(ctx, base);
loc_822EAF14:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// blt cr6,0x822eaf00
	if (cr6.lt) goto loc_822EAF00;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82187ba8
	ctx.lr = 0x822EAF2C;
	sub_82187BA8(ctx, base);
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82187bd0
	ctx.lr = 0x822EAF34;
	sub_82187BD0(ctx, base);
loc_822EAF34:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x822EAF40;
	sub_8217F768(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x822EAF4C;
	sub_8217F768(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82491668
	ctx.lr = 0x822EAF54;
	sub_82491668(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822EAF5C"))) PPC_WEAK_FUNC(sub_822EAF5C);
PPC_FUNC_IMPL(__imp__sub_822EAF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EAF60"))) PPC_WEAK_FUNC(sub_822EAF60);
PPC_FUNC_IMPL(__imp__sub_822EAF60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,2
	ctx.r7.s64 = 2;
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stb r8,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r8.u8);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stw r11,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, r11.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f13,28(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EAFAC"))) PPC_WEAK_FUNC(sub_822EAFAC);
PPC_FUNC_IMPL(__imp__sub_822EAFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EAFB0"))) PPC_WEAK_FUNC(sub_822EAFB0);
PPC_FUNC_IMPL(__imp__sub_822EAFB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,2
	ctx.r8.s64 = 2;
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r3,40(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// stfs f0,16(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stfs f0,20(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// stfs f0,24(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821ec060
	sub_821EC060(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822EAFF8"))) PPC_WEAK_FUNC(sub_822EAFF8);
PPC_FUNC_IMPL(__imp__sub_822EAFF8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EAFFC"))) PPC_WEAK_FUNC(sub_822EAFFC);
PPC_FUNC_IMPL(__imp__sub_822EAFFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB000"))) PPC_WEAK_FUNC(sub_822EB000);
PPC_FUNC_IMPL(__imp__sub_822EB000) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r11,19856
	ctx.r3.s64 = r11.s64 + 19856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82144a20
	ctx.lr = 0x822EB028;
	sub_82144A20(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eb044
	if (cr6.eq) goto loc_822EB044;
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,23
	cr6.compare<uint32_t>(r11.u32, 23, xer);
	// bne cr6,0x822eb044
	if (!cr6.eq) goto loc_822EB044;
	// stw r3,44(r30)
	PPC_STORE_U32(r30.u32 + 44, ctx.r3.u32);
	// b 0x822eb05c
	goto loc_822EB05C;
loc_822EB044:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r11,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r10,-3328
	ctx.r3.s64 = ctx.r10.s64 + -3328;
	// bl 0x82130000
	ctx.lr = 0x822EB05C;
	sub_82130000(ctx, base);
loc_822EB05C:
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

__attribute__((alias("__imp__sub_822EB074"))) PPC_WEAK_FUNC(sub_822EB074);
PPC_FUNC_IMPL(__imp__sub_822EB074) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB078"))) PPC_WEAK_FUNC(sub_822EB078);
PPC_FUNC_IMPL(__imp__sub_822EB078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822eb090
	if (!cr6.eq) goto loc_822EB090;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_822EB090:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lfs f0,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,36(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lfs f0,7220(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7220);
	f0.f64 = double(temp.f32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lfs f12,24(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// stfs f12,32(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// bgt cr6,0x822eb0d8
	if (cr6.gt) goto loc_822EB0D8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_822EB0D8:
	// stfs f0,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
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

__attribute__((alias("__imp__sub_822EB0F0"))) PPC_WEAK_FUNC(sub_822EB0F0);
PPC_FUNC_IMPL(__imp__sub_822EB0F0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EB0F4"))) PPC_WEAK_FUNC(sub_822EB0F4);
PPC_FUNC_IMPL(__imp__sub_822EB0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB0F8"))) PPC_WEAK_FUNC(sub_822EB0F8);
PPC_FUNC_IMPL(__imp__sub_822EB0F8) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f0,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822eb144
	if (!cr6.gt) goto loc_822EB144;
	// lfs f13,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822eb144
	if (!cr6.gt) goto loc_822EB144;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822eb144
	if (!cr6.eq) goto loc_822EB144;
	// bl 0x822eb078
	ctx.lr = 0x822EB144;
	sub_822EB078(ctx, base);
loc_822EB144:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822eb180
	if (cr6.lt) goto loc_822EB180;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x822eb174
	if (cr6.lt) goto loc_822EB174;
	// bne cr6,0x822eb17c
	if (!cr6.eq) goto loc_822EB17C;
	// stfs f31,28(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// li r11,2
	r11.s64 = 2;
	// b 0x822eb178
	goto loc_822EB178;
loc_822EB174:
	// li r11,3
	r11.s64 = 3;
loc_822EB178:
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_822EB17C:
	// stfs f31,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
loc_822EB180:
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

__attribute__((alias("__imp__sub_822EB198"))) PPC_WEAK_FUNC(sub_822EB198);
PPC_FUNC_IMPL(__imp__sub_822EB198) {
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
	// bl 0x824e0648
	ctx.lr = 0x822EB1B0;
	sub_824E0648(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-3252
	ctx.r6.s64 = ctx.r7.s64 + -3252;
	// lfs f13,-3212(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -3212);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3216(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -3216);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-3220(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -3220);
	ctx.f11.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f13,16(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f11,24(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
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

__attribute__((alias("__imp__sub_822EB204"))) PPC_WEAK_FUNC(sub_822EB204);
PPC_FUNC_IMPL(__imp__sub_822EB204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB208"))) PPC_WEAK_FUNC(sub_822EB208);
PPC_FUNC_IMPL(__imp__sub_822EB208) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-3208
	ctx.r3.s64 = r11.s64 + -3208;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EB214"))) PPC_WEAK_FUNC(sub_822EB214);
PPC_FUNC_IMPL(__imp__sub_822EB214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB218"))) PPC_WEAK_FUNC(sub_822EB218);
PPC_FUNC_IMPL(__imp__sub_822EB218) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-3124
	ctx.r5.s64 = r11.s64 + -3124;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EB254;
	sub_824DF200(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-3148
	ctx.r5.s64 = ctx.r10.s64 + -3148;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EB274;
	sub_824DF200(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-3172
	ctx.r5.s64 = ctx.r9.s64 + -3172;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EB294;
	sub_824DF200(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-3196
	ctx.r5.s64 = ctx.r7.s64 + -3196;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x822EB2B4;
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

__attribute__((alias("__imp__sub_822EB2CC"))) PPC_WEAK_FUNC(sub_822EB2CC);
PPC_FUNC_IMPL(__imp__sub_822EB2CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB2D0"))) PPC_WEAK_FUNC(sub_822EB2D0);
PPC_FUNC_IMPL(__imp__sub_822EB2D0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822eb2f8
	if (cr6.eq) goto loc_822EB2F8;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822eb390
	if (!cr6.eq) goto loc_822EB390;
loc_822EB2F8:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmadds f0,f11,f0,f12
	f0.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822eb340
	if (cr6.lt) goto loc_822EB340;
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
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
loc_822EB340:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// ble cr6,0x822eb378
	if (!cr6.gt) goto loc_822EB378;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822eb370
	if (!cr6.lt) goto loc_822EB370;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x822EB368;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// b 0x822eb37c
	goto loc_822EB37C;
loc_822EB370:
	// fmr f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f13.f64;
	// b 0x822eb37c
	goto loc_822EB37C;
loc_822EB378:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_822EB37C:
	// lfs f13,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f10,20(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
loc_822EB390:
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

__attribute__((alias("__imp__sub_822EB3A4"))) PPC_WEAK_FUNC(sub_822EB3A4);
PPC_FUNC_IMPL(__imp__sub_822EB3A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB3A8"))) PPC_WEAK_FUNC(sub_822EB3A8);
PPC_FUNC_IMPL(__imp__sub_822EB3A8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eb3ec
	if (cr6.eq) goto loc_822EB3EC;
	// bl 0x822eb2d0
	ctx.lr = 0x822EB3CC;
	sub_822EB2D0(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,28(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// bl 0x822eb0f8
	ctx.lr = 0x822EB3EC;
	sub_822EB0F8(ctx, base);
loc_822EB3EC:
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

__attribute__((alias("__imp__sub_822EB400"))) PPC_WEAK_FUNC(sub_822EB400);
PPC_FUNC_IMPL(__imp__sub_822EB400) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// lfs f13,7220(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7220);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// lfs f13,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// lfs f1,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// bgt cr6,0x822eb458
	if (cr6.gt) goto loc_822EB458;
	// stfs f1,24(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// b 0x822eb45c
	goto loc_822EB45C;
loc_822EB458:
	// stfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
loc_822EB45C:
	// lwz r4,44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822eb490
	if (cr6.eq) goto loc_822EB490;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r5,r31,40
	ctx.r5.s64 = r31.s64 + 40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822eb490
	if (!cr6.eq) goto loc_822EB490;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// bl 0x821ee370
	ctx.lr = 0x822EB490;
	sub_821EE370(ctx, base);
loc_822EB490:
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eb4c4
	if (cr6.eq) goto loc_822EB4C4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822eb2d0
	ctx.lr = 0x822EB4A4;
	sub_822EB2D0(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,88(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 88);
	f0.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,28(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// bl 0x822eb0f8
	ctx.lr = 0x822EB4C4;
	sub_822EB0F8(ctx, base);
loc_822EB4C4:
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

__attribute__((alias("__imp__sub_822EB4D8"))) PPC_WEAK_FUNC(sub_822EB4D8);
PPC_FUNC_IMPL(__imp__sub_822EB4D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x822EB4E0;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r11,-2756
	ctx.r8.s64 = r11.s64 + -2756;
	// li r30,0
	r30.s64 = 0;
	// lis r7,-32124
	ctx.r7.s64 = -2105278464;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stb r30,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r30.u8);
	// lfs f0,-15956(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -15956);
	f0.f64 = double(temp.f32);
	// stb r30,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r30.u8);
	// stfs f31,16(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// addi r11,r31,28
	r11.s64 = r31.s64 + 28;
	// stfs f31,24(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stb r30,32(r31)
	PPC_STORE_U8(r31.u32 + 32, r30.u8);
	// stfs f31,36(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stb r30,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r30.u8);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// addi r29,r6,-2772
	r29.s64 = ctx.r6.s64 + -2772;
	// stfs f31,44(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stb r30,52(r31)
	PPC_STORE_U8(r31.u32 + 52, r30.u8);
	// stfs f31,56(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stb r30,60(r31)
	PPC_STORE_U8(r31.u32 + 60, r30.u8);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// stfs f31,64(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// lwz r3,-24728(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -24728);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EB57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EB5B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,144(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-27772
	ctx.r4.s64 = ctx.r10.s64 + -27772;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822EB5C8;
	sub_8218B688(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stfs f31,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// stfs f31,92(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lfs f0,32688(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32688);
	f0.f64 = double(temp.f32);
	// lfs f13,-32032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -32032);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f0,-2776(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -2776);
	f0.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stfs f13,88(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f12,-2780(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -2780);
	ctx.f12.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f0,-2784(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -2784);
	f0.f64 = double(temp.f32);
	// lfs f13,-2788(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -2788);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,96(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// addi r4,r7,-2808
	ctx.r4.s64 = ctx.r7.s64 + -2808;
	// stfs f13,108(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// lfs f0,-2792(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2792);
	f0.f64 = double(temp.f32);
	// lfs f13,-2796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -2796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f31,116(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f31,120(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// lfs f0,-2800(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -2800);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f31,132(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f31,136(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f13,140(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// lwz r6,144(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EB674;
	sub_8218A568(ctx, base);
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-2816
	ctx.r4.s64 = r11.s64 + -2816;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EB690;
	sub_8218A568(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,30712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822EB6B4"))) PPC_WEAK_FUNC(sub_822EB6B4);
PPC_FUNC_IMPL(__imp__sub_822EB6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB6B8"))) PPC_WEAK_FUNC(sub_822EB6B8);
PPC_FUNC_IMPL(__imp__sub_822EB6B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7788(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7788);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822EB6DC"))) PPC_WEAK_FUNC(sub_822EB6DC);
PPC_FUNC_IMPL(__imp__sub_822EB6DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EB6E0"))) PPC_WEAK_FUNC(sub_822EB6E0);
PPC_FUNC_IMPL(__imp__sub_822EB6E0) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-2704
	ctx.r5.s64 = r11.s64 + -2704;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,80
	ctx.r6.s64 = r31.s64 + 80;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822EB71C;
	sub_824DF200(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-2720
	ctx.r5.s64 = ctx.r10.s64 + -2720;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,96
	ctx.r6.s64 = r31.s64 + 96;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822EB73C;
	sub_824DF200(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-2736
	ctx.r5.s64 = ctx.r9.s64 + -2736;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x822EB75C;
	sub_824DF200(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-2752
	ctx.r5.s64 = ctx.r7.s64 + -2752;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x822EB77C;
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

__attribute__((alias("__imp__sub_822EB794"))) PPC_WEAK_FUNC(sub_822EB794);
PPC_FUNC_IMPL(__imp__sub_822EB794) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB798"))) PPC_WEAK_FUNC(sub_822EB798);
PPC_FUNC_IMPL(__imp__sub_822EB798) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// bl 0x82375c98
	ctx.lr = 0x822EB7B4;
	sub_82375C98(ctx, base);
	// addi r3,r31,28
	ctx.r3.s64 = r31.s64 + 28;
	// bl 0x82375c98
	ctx.lr = 0x822EB7BC;
	sub_82375C98(ctx, base);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bl 0x82375c98
	ctx.lr = 0x822EB7C4;
	sub_82375C98(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,36(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822eb7f8
	if (cr6.gt) goto loc_822EB7F8;
	// lfs f11,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgt cr6,0x822eb7f0
	if (cr6.gt) goto loc_822EB7F0;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822eb900
	if (!cr6.gt) goto loc_822EB900;
loc_822EB7F0:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822eb82c
	if (!cr6.gt) goto loc_822EB82C;
loc_822EB7F8:
	// li r9,80
	ctx.r9.s64 = 80;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r11,96
	r11.s64 = 96;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r31,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	f0.f64 = double(temp.f32);
	// fmuls f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// b 0x822eb864
	goto loc_822EB864;
loc_822EB82C:
	// fcmpu cr6,f12,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822eb86c
	if (!cr6.gt) goto loc_822EB86C;
	// li r11,128
	r11.s64 = 128;
	// li r9,112
	ctx.r9.s64 = 112;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r31,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,140(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	f0.f64 = double(temp.f32);
	// lfs f13,124(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
loc_822EB864:
	// stfs f10,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_822EB86C:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822EB890;
	sub_8218A6E0(ctx, base);
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822EB8B4;
	sub_8218A6E0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r7,148(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lis r11,257
	r11.s64 = 16842752;
	// ori r11,r11,257
	r11.u64 = r11.u64 | 257;
	// lfs f9,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f7.f64 = double(temp.f32);
	// fmr f8,f9
	ctx.f8.f64 = ctx.f9.f64;
	// lfs f2,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	ctx.f2.f64 = double(temp.f32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// fmr f6,f7
	ctx.f6.f64 = ctx.f7.f64;
	// stw r7,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// fmr f4,f9
	ctx.f4.f64 = ctx.f9.f64;
	// fmr f5,f7
	ctx.f5.f64 = ctx.f7.f64;
	// fmr f3,f9
	ctx.f3.f64 = ctx.f9.f64;
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x82194b58
	ctx.lr = 0x822EB900;
	sub_82194B58(ctx, base);
loc_822EB900:
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

__attribute__((alias("__imp__sub_822EB914"))) PPC_WEAK_FUNC(sub_822EB914);
PPC_FUNC_IMPL(__imp__sub_822EB914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EB918"))) PPC_WEAK_FUNC(sub_822EB918);
PPC_FUNC_IMPL(__imp__sub_822EB918) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-2756
	ctx.r10.s64 = r11.s64 + -2756;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eb960
	if (cr6.eq) goto loc_822EB960;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EB960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EB960:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822EB968;
	sub_821D2028(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eb980
	if (cr6.eq) goto loc_822EB980;
	// bl 0x82130588
	ctx.lr = 0x822EB97C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822EB980:
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

__attribute__((alias("__imp__sub_822EB998"))) PPC_WEAK_FUNC(sub_822EB998);
PPC_FUNC_IMPL(__imp__sub_822EB998) {
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
	// ld r12,-4096(r1)
	r12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-5840(r1)
	ea = -5840 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,-2660
	r30.s64 = r11.s64 + -2660;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824df990
	ctx.lr = 0x822EB9C8;
	sub_824DF990(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822eb6e0
	ctx.lr = 0x822EB9D4;
	sub_822EB6E0(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r31,r10,30576
	r31.s64 = ctx.r10.s64 + 30576;
	// addi r4,r9,-2648
	ctx.r4.s64 = ctx.r9.s64 + -2648;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x822EB9EC;
	sub_821CA540(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r8,-2688
	ctx.r4.s64 = ctx.r8.s64 + -2688;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e0288
	ctx.lr = 0x822EBA00;
	sub_824E0288(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822EBA08;
	sub_821C9A90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824dfa38
	ctx.lr = 0x822EBA10;
	sub_824DFA38(ctx, base);
	// addi r1,r1,5840
	ctx.r1.s64 = ctx.r1.s64 + 5840;
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

__attribute__((alias("__imp__sub_822EBA28"))) PPC_WEAK_FUNC(sub_822EBA28);
PPC_FUNC_IMPL(__imp__sub_822EBA28) {
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
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x822EBA3C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eba4c
	if (cr6.eq) goto loc_822EBA4C;
	// bl 0x822eb4d8
	ctx.lr = 0x822EBA48;
	sub_822EB4D8(ctx, base);
	// b 0x822eba50
	goto loc_822EBA50;
loc_822EBA4C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822EBA50:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r11,r11,-7788
	r11.s64 = r11.s64 + -7788;
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// bl 0x822eb998
	ctx.lr = 0x822EBA60;
	sub_822EB998(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EBA70"))) PPC_WEAK_FUNC(sub_822EBA70);
PPC_FUNC_IMPL(__imp__sub_822EBA70) {
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
	// bl 0x824e0648
	ctx.lr = 0x822EBA88;
	sub_824E0648(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f0,-11624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r6,-2628
	ctx.r5.s64 = ctx.r6.s64 + -2628;
	// lfs f12,-6172(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -6172);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-31384(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31384);
	ctx.f10.f64 = double(temp.f32);
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f11,28(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f10,32(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
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

__attribute__((alias("__imp__sub_822EBAEC"))) PPC_WEAK_FUNC(sub_822EBAEC);
PPC_FUNC_IMPL(__imp__sub_822EBAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EBAF0"))) PPC_WEAK_FUNC(sub_822EBAF0);
PPC_FUNC_IMPL(__imp__sub_822EBAF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r11,-2596
	ctx.r3.s64 = r11.s64 + -2596;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EBAFC"))) PPC_WEAK_FUNC(sub_822EBAFC);
PPC_FUNC_IMPL(__imp__sub_822EBAFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EBB00"))) PPC_WEAK_FUNC(sub_822EBB00);
PPC_FUNC_IMPL(__imp__sub_822EBB00) {
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
	// bl 0x824e06e0
	ctx.lr = 0x822EBB18;
	sub_824E06E0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EBB2C;
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

__attribute__((alias("__imp__sub_822EBB40"))) PPC_WEAK_FUNC(sub_822EBB40);
PPC_FUNC_IMPL(__imp__sub_822EBB40) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-2508
	ctx.r5.s64 = r11.s64 + -2508;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EBB7C;
	sub_824DF200(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-2520
	ctx.r5.s64 = ctx.r10.s64 + -2520;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EBB9C;
	sub_824DF200(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-2540
	ctx.r5.s64 = ctx.r9.s64 + -2540;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EBBBC;
	sub_824DF200(ctx, base);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-2552
	ctx.r5.s64 = ctx.r8.s64 + -2552;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EBBDC;
	sub_824DF200(ctx, base);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-2564
	ctx.r5.s64 = ctx.r7.s64 + -2564;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,28
	ctx.r6.s64 = r31.s64 + 28;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x822EBBFC;
	sub_824DF200(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r6,-2580
	ctx.r5.s64 = ctx.r6.s64 + -2580;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,32
	ctx.r6.s64 = r31.s64 + 32;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x822EBC1C;
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

__attribute__((alias("__imp__sub_822EBC34"))) PPC_WEAK_FUNC(sub_822EBC34);
PPC_FUNC_IMPL(__imp__sub_822EBC34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EBC38"))) PPC_WEAK_FUNC(sub_822EBC38);
PPC_FUNC_IMPL(__imp__sub_822EBC38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8247a1b0
	ctx.lr = 0x822EBC54;
	sub_8247A1B0(ctx, base);
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r10,r10,176
	ctx.r10.s64 = ctx.r10.s64 + 176;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ebcf4
	if (cr6.eq) goto loc_822EBCF4;
	// lwz r11,100(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r9,26(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 26);
	// lwz r8,30(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 30);
	// lwz r7,34(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,88(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// stfs f13,84(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lwz r6,10(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// lwz r11,-32452(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32452);
	// subf r4,r6,r11
	ctx.r4.s64 = r11.s64 - ctx.r6.s64;
	// cntlzw r11,r4
	r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r4,r10,1
	ctx.r4.u64 = ctx.r10.u64 ^ 1;
	// bl 0x821f7208
	ctx.lr = 0x822EBCF4;
	sub_821F7208(ctx, base);
loc_822EBCF4:
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

__attribute__((alias("__imp__sub_822EBD08"))) PPC_WEAK_FUNC(sub_822EBD08);
PPC_FUNC_IMPL(__imp__sub_822EBD08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lwz r11,44(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EBD1C"))) PPC_WEAK_FUNC(sub_822EBD1C);
PPC_FUNC_IMPL(__imp__sub_822EBD1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EBD20"))) PPC_WEAK_FUNC(sub_822EBD20);
PPC_FUNC_IMPL(__imp__sub_822EBD20) {
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
	// li r30,64
	r30.s64 = 64;
loc_822EBD3C:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ebd5c
	if (cr6.eq) goto loc_822EBD5C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EBD5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EBD5C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822ebd3c
	if (!cr0.eq) goto loc_822EBD3C;
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

__attribute__((alias("__imp__sub_822EBD80"))) PPC_WEAK_FUNC(sub_822EBD80);
PPC_FUNC_IMPL(__imp__sub_822EBD80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,104(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// lwz r10,104(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// ble cr6,0x822ebda0
	if (!cr6.gt) goto loc_822EBDA0;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_822EBDA0:
	// subfc r11,r10,r11
	xer.ca = r11.u32 >= ctx.r10.u32;
	r11.s64 = r11.s64 - ctx.r10.s64;
	// subfe r3,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r3.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EBDAC"))) PPC_WEAK_FUNC(sub_822EBDAC);
PPC_FUNC_IMPL(__imp__sub_822EBDAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EBDB0"))) PPC_WEAK_FUNC(sub_822EBDB0);
PPC_FUNC_IMPL(__imp__sub_822EBDB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,256(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822ebdf8
	if (cr6.eq) goto loc_822EBDF8;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,63
	ctx.r9.s64 = 63;
loc_822EBDC4:
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r11,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	r11.s64 = r11.s32 >> 1;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r10,r3
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// lwz r10,104(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// cmplw cr6,r4,r10
	cr6.compare<uint32_t>(ctx.r4.u32, ctx.r10.u32, xer);
	// ble cr6,0x822ebde8
	if (!cr6.gt) goto loc_822EBDE8;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// b 0x822ebdf0
	goto loc_822EBDF0;
loc_822EBDE8:
	// bge cr6,0x822ebe00
	if (!cr6.lt) goto loc_822EBE00;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
loc_822EBDF0:
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// ble cr6,0x822ebdc4
	if (!cr6.gt) goto loc_822EBDC4;
loc_822EBDF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822EBE00:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EBE0C"))) PPC_WEAK_FUNC(sub_822EBE0C);
PPC_FUNC_IMPL(__imp__sub_822EBE0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EBE10"))) PPC_WEAK_FUNC(sub_822EBE10);
PPC_FUNC_IMPL(__imp__sub_822EBE10) {
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
	// bl 0x8271e4c8
	ctx.lr = 0x822EBE2C;
	sub_8271E4C8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-2160
	ctx.r10.s64 = r11.s64 + -2160;
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// bl 0x82548ba8
	ctx.lr = 0x822EBE4C;
	sub_82548BA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8271e618
	ctx.lr = 0x822EBE54;
	sub_8271E618(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r30,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r30.u32);
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r30,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r30.u32);
	// stb r30,112(r31)
	PPC_STORE_U8(r31.u32 + 112, r30.u8);
	// stb r30,113(r31)
	PPC_STORE_U8(r31.u32 + 113, r30.u8);
	// stb r30,114(r31)
	PPC_STORE_U8(r31.u32 + 114, r30.u8);
	// stb r30,115(r31)
	PPC_STORE_U8(r31.u32 + 115, r30.u8);
	// beq cr6,0x822ebe8c
	if (cr6.eq) goto loc_822EBE8C;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ebe8c
	if (!cr6.eq) goto loc_822EBE8C;
	// bl 0x821f6c50
	ctx.lr = 0x822EBE8C;
	sub_821F6C50(ctx, base);
loc_822EBE8C:
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

__attribute__((alias("__imp__sub_822EBEA8"))) PPC_WEAK_FUNC(sub_822EBEA8);
PPC_FUNC_IMPL(__imp__sub_822EBEA8) {
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
	// bl 0x8271e550
	ctx.lr = 0x822EBEC8;
	sub_8271E550(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ebee0
	if (cr6.eq) goto loc_822EBEE0;
	// bl 0x82130588
	ctx.lr = 0x822EBEDC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822EBEE0:
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

__attribute__((alias("__imp__sub_822EBEF8"))) PPC_WEAK_FUNC(sub_822EBEF8);
PPC_FUNC_IMPL(__imp__sub_822EBEF8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r5,r10,-2132
	ctx.r5.s64 = ctx.r10.s64 + -2132;
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,248(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 248);
	// bl 0x82137a08
	ctx.lr = 0x822EBF30;
	sub_82137A08(ctx, base);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r9,19856
	ctx.r3.s64 = ctx.r9.s64 + 19856;
	// bl 0x82144a20
	ctx.lr = 0x822EBF40;
	sub_82144A20(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ebf88
	if (cr6.eq) goto loc_822EBF88;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// li r8,56
	ctx.r8.s64 = 56;
	// stw r30,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r30.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,-23520(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23520);
	// lwzx r6,r8,r10
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// subf r5,r6,r11
	ctx.r5.s64 = r11.s64 - ctx.r6.s64;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// stb r7,112(r31)
	PPC_STORE_U8(r31.u32 + 112, ctx.r7.u8);
	// rlwinm r11,r4,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// xori r10,r11,1
	ctx.r10.u64 = r11.u64 ^ 1;
	// stb r10,114(r31)
	PPC_STORE_U8(r31.u32 + 114, ctx.r10.u8);
	// b 0x822ebf8c
	goto loc_822EBF8C;
loc_822EBF88:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822EBF8C:
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

__attribute__((alias("__imp__sub_822EBFA4"))) PPC_WEAK_FUNC(sub_822EBFA4);
PPC_FUNC_IMPL(__imp__sub_822EBFA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EBFA8"))) PPC_WEAK_FUNC(sub_822EBFA8);
PPC_FUNC_IMPL(__imp__sub_822EBFA8) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r4,r31,64
	ctx.r4.s64 = r31.s64 + 64;
	// bl 0x8213b860
	ctx.lr = 0x822EBFC8;
	sub_8213B860(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lwz r11,44(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
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

__attribute__((alias("__imp__sub_822EBFEC"))) PPC_WEAK_FUNC(sub_822EBFEC);
PPC_FUNC_IMPL(__imp__sub_822EBFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EBFF0"))) PPC_WEAK_FUNC(sub_822EBFF0);
PPC_FUNC_IMPL(__imp__sub_822EBFF0) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r7,80(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,44(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// stw r10,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r10.u32);
	// beq cr6,0x822ec044
	if (cr6.eq) goto loc_822EC044;
	// lfs f0,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x822ec038
	if (cr6.eq) goto loc_822EC038;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822EC038:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822ec13c
	if (!cr6.eq) goto loc_822EC13C;
loc_822EC044:
	// lwz r10,104(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r9,100(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 100);
	// addi r10,r10,224
	ctx.r10.s64 = ctx.r10.s64 + 224;
	// addi r6,r8,-12352
	ctx.r6.s64 = ctx.r8.s64 + -12352;
	// lwz r5,22(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 22);
	// lfs f12,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,52(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	f0.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,56(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 56);
	f0.f64 = double(temp.f32);
	// lfs f10,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f8,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,48(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	f0.f64 = double(temp.f32);
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f6,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f6
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f9,f9,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f4.f64));
	// fmadds f2,f7,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fcmpu cr6,f2,f5
	cr6.compare(ctx.f2.f64, ctx.f5.f64);
	// bgt cr6,0x822ec13c
	if (cr6.gt) goto loc_822EC13C;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822ec0c8
	if (cr6.eq) goto loc_822EC0C8;
	// lfs f0,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x822ec0bc
	if (cr6.eq) goto loc_822EC0BC;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_822EC0BC:
	// clrlwi r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822ec13c
	if (!cr6.eq) goto loc_822EC13C;
loc_822EC0C8:
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
	// stw r7,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// stfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r10,255
	ctx.r10.s64 = 255;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r7,36
	ctx.r7.s64 = 36;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// lfs f0,-2464(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -2464);
	f0.f64 = double(temp.f32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stfs f0,156(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// stw r11,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r11.u32);
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// stw r6,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r6.u32);
	// stw r4,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r4.u32);
	// stb r10,164(r1)
	PPC_STORE_U8(ctx.r1.u32 + 164, ctx.r10.u8);
	// stb r11,165(r1)
	PPC_STORE_U8(ctx.r1.u32 + 165, r11.u8);
	// stb r7,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r7.u8);
	// lwz r4,10(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 10);
	// bl 0x82549118
	ctx.lr = 0x822EC13C;
	sub_82549118(ctx, base);
loc_822EC13C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EC14C"))) PPC_WEAK_FUNC(sub_822EC14C);
PPC_FUNC_IMPL(__imp__sub_822EC14C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EC150"))) PPC_WEAK_FUNC(sub_822EC150);
PPC_FUNC_IMPL(__imp__sub_822EC150) {
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
	ctx.lr = 0x822EC158;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r11,44(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// beq cr6,0x822ec188
	if (cr6.eq) goto loc_822EC188;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822EC188;
	sub_8213C218(ctx, base);
loc_822EC188:
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// li r29,0
	r29.s64 = 0;
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x822ec1d8
	if (cr6.eq) goto loc_822EC1D8;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r29,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r29.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r29,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r29.u32);
	// stw r29,100(r31)
	PPC_STORE_U32(r31.u32 + 100, r29.u32);
	// stb r29,112(r31)
	PPC_STORE_U8(r31.u32 + 112, r29.u8);
	// stb r29,113(r31)
	PPC_STORE_U8(r31.u32 + 113, r29.u8);
	// stb r29,114(r31)
	PPC_STORE_U8(r31.u32 + 114, r29.u8);
	// stb r29,115(r31)
	PPC_STORE_U8(r31.u32 + 115, r29.u8);
	// beq cr6,0x822ec290
	if (cr6.eq) goto loc_822EC290;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ec290
	if (!cr6.eq) goto loc_822EC290;
	// bl 0x821f6c50
	ctx.lr = 0x822EC1D0;
	sub_821F6C50(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_822EC1D8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lfs f13,228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// lwz r28,100(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// addi r9,r10,-12352
	ctx.r9.s64 = ctx.r10.s64 + -12352;
	// lfs f11,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f11.f64 = double(temp.f32);
	// addi r30,r11,224
	r30.s64 = r11.s64 + 224;
	// lwz r8,22(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 22);
	// lfs f0,52(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	f0.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	f0.f64 = double(temp.f32);
	// fsubs f9,f12,f0
	ctx.f9.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f0,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f8,f11,f0
	ctx.f8.f64 = double(float(ctx.f11.f64 - f0.f64));
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f7
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f6
	cr6.compare(ctx.f3.f64, ctx.f6.f64);
	// bgt cr6,0x822ec284
	if (cr6.gt) goto loc_822EC284;
	// lwz r27,80(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x822ec264
	if (cr6.eq) goto loc_822EC264;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x822ec258
	if (cr6.eq) goto loc_822EC258;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822EC258:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ec284
	if (!cr6.eq) goto loc_822EC284;
loc_822EC264:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821e8080
	ctx.lr = 0x822EC26C;
	sub_821E8080(ctx, base);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// stw r27,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r27.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,18(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 18);
	// bl 0x82549118
	ctx.lr = 0x822EC284;
	sub_82549118(ctx, base);
loc_822EC284:
	// stb r29,113(r31)
	PPC_STORE_U8(r31.u32 + 113, r29.u8);
	// stb r29,115(r31)
	PPC_STORE_U8(r31.u32 + 115, r29.u8);
	// stb r29,112(r31)
	PPC_STORE_U8(r31.u32 + 112, r29.u8);
loc_822EC290:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822EC298"))) PPC_WEAK_FUNC(sub_822EC298);
PPC_FUNC_IMPL(__imp__sub_822EC298) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,56
	ctx.r10.s64 = 56;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r11,-23520(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23520);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// bne cr6,0x822ec2b8
	if (!cr6.eq) goto loc_822EC2B8;
	// b 0x822ec150
	sub_822EC150(ctx, base);
	return;
loc_822EC2B8:
	// li r11,1
	r11.s64 = 1;
	// stb r11,115(r3)
	PPC_STORE_U8(ctx.r3.u32 + 115, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EC2C4"))) PPC_WEAK_FUNC(sub_822EC2C4);
PPC_FUNC_IMPL(__imp__sub_822EC2C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EC2C8"))) PPC_WEAK_FUNC(sub_822EC2C8);
PPC_FUNC_IMPL(__imp__sub_822EC2C8) {
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
	ctx.lr = 0x822EC2D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r30,r29
	r30.u64 = r29.u64;
	// li r31,64
	r31.s64 = 64;
	// stw r11,256(r29)
	PPC_STORE_U32(r29.u32 + 256, r11.u32);
loc_822EC2E8:
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x822EC2F0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ec300
	if (cr6.eq) goto loc_822EC300;
	// bl 0x822ebe10
	ctx.lr = 0x822EC2FC;
	sub_822EBE10(ctx, base);
	// b 0x822ec304
	goto loc_822EC304;
loc_822EC300:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822EC304:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x822ec2e8
	if (!cr0.eq) goto loc_822EC2E8;
	// lis r11,-32209
	r11.s64 = -2110849024;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r11,-17024
	ctx.r6.s64 = r11.s64 + -17024;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823dcf08
	ctx.lr = 0x822EC32C;
	sub_823DCF08(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822EC338"))) PPC_WEAK_FUNC(sub_822EC338);
PPC_FUNC_IMPL(__imp__sub_822EC338) {
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
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82130528
	ctx.lr = 0x822EC34C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ec370
	if (cr6.eq) goto loc_822EC370;
	// bl 0x822ec2c8
	ctx.lr = 0x822EC358;
	sub_822EC2C8(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r3,-7784(r11)
	PPC_STORE_U32(r11.u32 + -7784, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822EC370:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7784(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7784, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EC38C"))) PPC_WEAK_FUNC(sub_822EC38C);
PPC_FUNC_IMPL(__imp__sub_822EC38C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EC390"))) PPC_WEAK_FUNC(sub_822EC390);
PPC_FUNC_IMPL(__imp__sub_822EC390) {
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
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bne cr6,0x822ec3bc
	if (!cr6.eq) goto loc_822EC3BC;
loc_822EC3B4:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822ec410
	goto loc_822EC410;
loc_822EC3BC:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ebef8
	ctx.lr = 0x822EC3C8;
	sub_822EBEF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ec3b4
	if (cr6.eq) goto loc_822EC3B4;
	// lbz r11,114(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 114);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ec3e8
	if (!cr6.eq) goto loc_822EC3E8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ebc38
	ctx.lr = 0x822EC3E8;
	sub_822EBC38(ctx, base);
loc_822EC3E8:
	// lis r11,-32209
	r11.s64 = -2110849024;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r11,-17024
	ctx.r6.s64 = r11.s64 + -17024;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dcf08
	ctx.lr = 0x822EC400;
	sub_823DCF08(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r10.u32);
loc_822EC410:
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

__attribute__((alias("__imp__sub_822EC428"))) PPC_WEAK_FUNC(sub_822EC428);
PPC_FUNC_IMPL(__imp__sub_822EC428) {
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
	ctx.lr = 0x822EC430;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r11,29952
	r29.s64 = r11.s64 + 29952;
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lwz r11,44(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// lwz r11,-32452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -32452);
	// lwz r9,10(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x822ec468
	if (cr6.eq) goto loc_822EC468;
	// bl 0x822ebff0
	ctx.lr = 0x822EC464;
	sub_822EBFF0(ctx, base);
	// lwz r11,-32452(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -32452);
loc_822EC468:
	// lwz r10,100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r30,1
	r30.s64 = 1;
	// lwz r9,14(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 14);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x822ec508
	if (cr6.eq) goto loc_822EC508;
	// lwz r11,44(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lis r10,-32209
	ctx.r10.s64 = -2110849024;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r9,r10,-17144
	ctx.r9.s64 = ctx.r10.s64 + -17144;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821d4268
	ctx.lr = 0x822EC4A8;
	sub_821D4268(ctx, base);
	// lis r8,-32184
	ctx.r8.s64 = -2109210624;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r8,-10648
	ctx.r6.s64 = ctx.r8.s64 + -10648;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// lwz r10,12(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r3,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r3.u32);
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// stw r10,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r10.u32);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r6,4(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r4,8(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// stw r8,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r8.u32);
	// stw r4,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r4.u32);
	// stw r6,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r6.u32);
	// stw r7,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r7.u32);
	// stb r30,113(r31)
	PPC_STORE_U8(r31.u32 + 113, r30.u8);
loc_822EC508:
	// lis r11,-32209
	r11.s64 = -2110849024;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r10,r11,-15720
	ctx.r10.s64 = r11.s64 + -15720;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821d4268
	ctx.lr = 0x822EC52C;
	sub_821D4268(ctx, base);
	// lis r9,-32184
	ctx.r9.s64 = -2109210624;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r7,r9,-10648
	ctx.r7.s64 = ctx.r9.s64 + -10648;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stw r7,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r11,32
	ctx.r4.s64 = r11.s64 + 32;
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r10,8(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r9,12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// lwz r8,0(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r8,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// stw r3,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r3.u32);
	// stw r10,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r10.u32);
	// stw r9,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r9.u32);
	// lwz r3,12(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stw r4,40(r11)
	PPC_STORE_U32(r11.u32 + 40, ctx.r4.u32);
	// lwz r6,0(r5)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r7,4(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stw r7,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r7.u32);
	// stw r6,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r6.u32);
	// stw r3,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r3.u32);
	// stb r30,113(r31)
	PPC_STORE_U8(r31.u32 + 113, r30.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822EC598"))) PPC_WEAK_FUNC(sub_822EC598);
PPC_FUNC_IMPL(__imp__sub_822EC598) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r5,r10,-2132
	ctx.r5.s64 = ctx.r10.s64 + -2132;
	// lwz r11,136(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,248(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 248);
	// bl 0x82137a08
	ctx.lr = 0x822EC5D0;
	sub_82137A08(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ebdb0
	ctx.lr = 0x822EC5DC;
	sub_822EBDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822ec5f4
	if (!cr6.eq) goto loc_822EC5F4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822ec390
	ctx.lr = 0x822EC5EC;
	sub_822EC390(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ec604
	if (cr6.eq) goto loc_822EC604;
loc_822EC5F4:
	// lbz r11,114(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 114);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ec604
	if (!cr6.eq) goto loc_822EC604;
	// bl 0x822ec428
	ctx.lr = 0x822EC604;
	sub_822EC428(ctx, base);
loc_822EC604:
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

__attribute__((alias("__imp__sub_822EC61C"))) PPC_WEAK_FUNC(sub_822EC61C);
PPC_FUNC_IMPL(__imp__sub_822EC61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EC620"))) PPC_WEAK_FUNC(sub_822EC620);
PPC_FUNC_IMPL(__imp__sub_822EC620) {
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
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822EC628;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lwz r10,104(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r10,r10,176
	ctx.r10.s64 = ctx.r10.s64 + 176;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,112(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ec7bc
	if (cr6.eq) goto loc_822EC7BC;
	// lbz r11,114(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 114);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ec694
	if (cr6.eq) goto loc_822EC694;
	// bl 0x822ebc38
	ctx.lr = 0x822EC684;
	sub_822EBC38(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ec428
	ctx.lr = 0x822EC68C;
	sub_822EC428(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,114(r31)
	PPC_STORE_U8(r31.u32 + 114, r11.u8);
loc_822EC694:
	// lbz r11,115(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 115);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ec6b4
	if (cr6.eq) goto loc_822EC6B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,104(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x822ec150
	ctx.lr = 0x822EC6AC;
	sub_822EC150(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_822EC6B4:
	// lwz r29,100(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// lis r11,-32114
	r11.s64 = -2104623104;
	// lwz r11,-32452(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -32452);
	// lwz r10,14(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 14);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x822ec7bc
	if (cr6.eq) goto loc_822EC7BC;
	// lwz r27,80(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// beq cr6,0x822ec700
	if (cr6.eq) goto loc_822EC700;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x822ec6f4
	if (cr6.eq) goto loc_822EC6F4;
	// li r11,0
	r11.s64 = 0;
loc_822EC6F4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ec7bc
	if (!cr6.eq) goto loc_822EC7BC;
loc_822EC700:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r28,r31,96
	r28.s64 = r31.s64 + 96;
	// addi r8,r10,-12352
	ctx.r8.s64 = ctx.r10.s64 + -12352;
	// lwz r9,22(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 22);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f13,228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,52(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	f0.f64 = double(temp.f32);
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f0,56(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	f0.f64 = double(temp.f32);
	// fsubs f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 - f0.f64));
	// lfs f9,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,48(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	f0.f64 = double(temp.f32);
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fmuls f5,f11,f11
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f4,f10,f10,f5
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f5.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// beq cr6,0x822ec774
	if (cr6.eq) goto loc_822EC774;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f7
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fcmpu cr6,f3,f6
	cr6.compare(ctx.f3.f64, ctx.f6.f64);
	// ble cr6,0x822ec7bc
	if (!cr6.gt) goto loc_822EC7BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822EC76C;
	sub_8213C218(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
loc_822EC774:
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f7,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f7
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// addi r30,r11,224
	r30.s64 = r11.s64 + 224;
	// fcmpu cr6,f3,f6
	cr6.compare(ctx.f3.f64, ctx.f6.f64);
	// bgt cr6,0x822ec7bc
	if (cr6.gt) goto loc_822EC7BC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821e8080
	ctx.lr = 0x822EC794;
	sub_821E8080(ctx, base);
	// lbz r10,166(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 166);
	// stw r30,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r30.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stw r27,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r27.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stb r9,166(r1)
	PPC_STORE_U8(ctx.r1.u32 + 166, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,14(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 14);
	// bl 0x825491f0
	ctx.lr = 0x822EC7BC;
	sub_825491F0(ctx, base);
loc_822EC7BC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822EC7C4"))) PPC_WEAK_FUNC(sub_822EC7C4);
PPC_FUNC_IMPL(__imp__sub_822EC7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EC7C8"))) PPC_WEAK_FUNC(sub_822EC7C8);
PPC_FUNC_IMPL(__imp__sub_822EC7C8) {
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
	ctx.lr = 0x822EC7D0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r31
	r29.u64 = r31.u64;
	// lwz r11,256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// subfic r11,r11,64
	xer.ca = r11.u32 <= 64;
	r11.s64 = 64 - r11.s64;
	// cmpwi cr6,r11,64
	cr6.compare<int32_t>(r11.s32, 64, xer);
	// bge cr6,0x822ec8b8
	if (!cr6.lt) goto loc_822EC8B8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subfic r26,r11,64
	xer.ca = r11.u32 <= 64;
	r26.s64 = 64 - r11.s64;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// add r28,r10,r30
	r28.u64 = ctx.r10.u64 + r30.u64;
	// addi r27,r11,29952
	r27.s64 = r11.s64 + 29952;
loc_822EC804:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ec848
	if (cr6.eq) goto loc_822EC848;
	// lwz r9,108(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// lwz r10,44(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// ble cr6,0x822ec840
	if (!cr6.gt) goto loc_822EC840;
	// lbz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 112);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822ec840
	if (!cr6.eq) goto loc_822EC840;
	// lbz r10,114(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 114);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ec848
	if (cr6.eq) goto loc_822EC848;
loc_822EC840:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// b 0x822ec84c
	goto loc_822EC84C;
loc_822EC848:
	// li r10,1
	ctx.r10.s64 = 1;
loc_822EC84C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ec8a4
	if (cr6.eq) goto loc_822EC8A4;
	// lwz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// stw r31,108(r11)
	PPC_STORE_U32(r11.u32 + 108, r31.u32);
	// stw r31,104(r11)
	PPC_STORE_U32(r11.u32 + 104, r31.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// stw r31,100(r11)
	PPC_STORE_U32(r11.u32 + 100, r31.u32);
	// stb r31,112(r11)
	PPC_STORE_U8(r11.u32 + 112, r31.u8);
	// stb r31,113(r11)
	PPC_STORE_U8(r11.u32 + 113, r31.u8);
	// stb r31,114(r11)
	PPC_STORE_U8(r11.u32 + 114, r31.u8);
	// stb r31,115(r11)
	PPC_STORE_U8(r11.u32 + 115, r31.u8);
	// beq cr6,0x822ec890
	if (cr6.eq) goto loc_822EC890;
	// lbz r11,119(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 119);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ec890
	if (!cr6.eq) goto loc_822EC890;
	// bl 0x821f6c50
	ctx.lr = 0x822EC890;
	sub_821F6C50(ctx, base);
loc_822EC890:
	// lwz r11,256(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// li r29,1
	r29.s64 = 1;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,256(r30)
	PPC_STORE_U32(r30.u32 + 256, r11.u32);
	// b 0x822ec8ac
	goto loc_822EC8AC;
loc_822EC8A4:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822ec620
	ctx.lr = 0x822EC8AC;
	sub_822EC620(ctx, base);
loc_822EC8AC:
	// addic. r26,r26,-1
	xer.ca = r26.u32 > 0;
	r26.s64 = r26.s64 + -1;
	cr0.compare<int32_t>(r26.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bne 0x822ec804
	if (!cr0.eq) goto loc_822EC804;
loc_822EC8B8:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ec8dc
	if (cr6.eq) goto loc_822EC8DC;
	// lis r11,-32209
	r11.s64 = -2110849024;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r11,-17024
	ctx.r6.s64 = r11.s64 + -17024;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dcf08
	ctx.lr = 0x822EC8DC;
	sub_823DCF08(ctx, base);
loc_822EC8DC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822EC8E4"))) PPC_WEAK_FUNC(sub_822EC8E4);
PPC_FUNC_IMPL(__imp__sub_822EC8E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EC8E8"))) PPC_WEAK_FUNC(sub_822EC8E8);
PPC_FUNC_IMPL(__imp__sub_822EC8E8) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,-1712
	ctx.r3.s64 = r11.s64 + -1712;
	// bl 0x8218a4e8
	ctx.lr = 0x822EC90C;
	sub_8218A4E8(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r10,-1732
	ctx.r3.s64 = ctx.r10.s64 + -1732;
	// bl 0x8218a4e8
	ctx.lr = 0x822EC920;
	sub_8218A4E8(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r9,-1752
	ctx.r3.s64 = ctx.r9.s64 + -1752;
	// bl 0x8218a4e8
	ctx.lr = 0x822EC934;
	sub_8218A4E8(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r8,-1772
	ctx.r3.s64 = ctx.r8.s64 + -1772;
	// bl 0x8218a4e8
	ctx.lr = 0x822EC948;
	sub_8218A4E8(ctx, base);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r7,-1800
	ctx.r3.s64 = ctx.r7.s64 + -1800;
	// bl 0x8218a4e8
	ctx.lr = 0x822EC95C;
	sub_8218A4E8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822EC978"))) PPC_WEAK_FUNC(sub_822EC978);
PPC_FUNC_IMPL(__imp__sub_822EC978) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// lis r30,-32112
	r30.s64 = -2104492032;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eca5c
	if (cr6.eq) goto loc_822ECA5C;
	// li r6,5
	ctx.r6.s64 = 5;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,368
	ctx.r4.s64 = r11.s64 + 368;
	// bl 0x8218aef8
	ctx.lr = 0x822EC9BC;
	sub_8218AEF8(ctx, base);
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// li r6,5
	ctx.r6.s64 = 5;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,384
	ctx.r4.s64 = r11.s64 + 384;
	// bl 0x8218aef8
	ctx.lr = 0x822EC9D4;
	sub_8218AEF8(ctx, base);
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// li r6,5
	ctx.r6.s64 = 5;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,400
	ctx.r4.s64 = r11.s64 + 400;
	// bl 0x8218aef8
	ctx.lr = 0x822EC9EC;
	sub_8218AEF8(ctx, base);
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// li r10,400
	ctx.r10.s64 = 400;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f10.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f8,f11,f13
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fdivs f5,f13,f8
	ctx.f5.f64 = double(float(ctx.f13.f64 / ctx.f8.f64));
	// fdivs f4,f0,f8
	ctx.f4.f64 = double(float(f0.f64 / ctx.f8.f64));
	// stfs f4,112(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// fdivs f7,f12,f9
	ctx.f7.f64 = double(float(ctx.f12.f64 / ctx.f9.f64));
	// fdivs f6,f0,f9
	ctx.f6.f64 = double(float(f0.f64 / ctx.f9.f64));
	// stfs f6,120(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fneg f2,f5
	ctx.f2.u64 = ctx.f5.u64 ^ 0x8000000000000000;
	// stfs f2,116(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fneg f3,f7
	ctx.f3.u64 = ctx.f7.u64 ^ 0x8000000000000000;
	// stfs f3,124(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x8218aef8
	ctx.lr = 0x822ECA5C;
	sub_8218AEF8(ctx, base);
loc_822ECA5C:
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r6,2
	ctx.r6.s64 = 2;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8218aef8
	ctx.lr = 0x822ECA74;
	sub_8218AEF8(ctx, base);
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

__attribute__((alias("__imp__sub_822ECA90"))) PPC_WEAK_FUNC(sub_822ECA90);
PPC_FUNC_IMPL(__imp__sub_822ECA90) {
	PPC_FUNC_PROLOGUE();
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
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r31,r11,-7676
	r31.s64 = r11.s64 + -7676;
	// lwz r11,-7656(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7656);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822ecad4
	if (!cr6.eq) goto loc_822ECAD4;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,-7656(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7656, r11.u32);
	// bl 0x822ec8e8
	ctx.lr = 0x822ECAD4;
	sub_822EC8E8(ctx, base);
loc_822ECAD4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822ec978
	ctx.lr = 0x822ECAE0;
	sub_822EC978(ctx, base);
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

__attribute__((alias("__imp__sub_822ECAF8"))) PPC_WEAK_FUNC(sub_822ECAF8);
PPC_FUNC_IMPL(__imp__sub_822ECAF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-7784(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7784);
	// b 0x822ec598
	sub_822EC598(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ECB08"))) PPC_WEAK_FUNC(sub_822ECB08);
PPC_FUNC_IMPL(__imp__sub_822ECB08) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r11,-7748(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7748);
	// stfs f1,-7760(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + -7760, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7752(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7752);
	// b 0x821c9108
	sub_821C9108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ECB2C"))) PPC_WEAK_FUNC(sub_822ECB2C);
PPC_FUNC_IMPL(__imp__sub_822ECB2C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ECB30"))) PPC_WEAK_FUNC(sub_822ECB30);
PPC_FUNC_IMPL(__imp__sub_822ECB30) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-7748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7748);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ecb70
	if (cr6.eq) goto loc_822ECB70;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// stb r10,-7744(r11)
	PPC_STORE_U8(r11.u32 + -7744, ctx.r10.u8);
	// lwz r3,-7752(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7752);
	// bl 0x821c9108
	ctx.lr = 0x822ECB68;
	sub_821C9108(ctx, base);
	// lwz r3,-7748(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7748);
	// bl 0x821c9168
	ctx.lr = 0x822ECB70;
	sub_821C9168(ctx, base);
loc_822ECB70:
	// bl 0x8247eca8
	ctx.lr = 0x822ECB74;
	sub_8247ECA8(ctx, base);
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

__attribute__((alias("__imp__sub_822ECB88"))) PPC_WEAK_FUNC(sub_822ECB88);
PPC_FUNC_IMPL(__imp__sub_822ECB88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822ECB98"))) PPC_WEAK_FUNC(sub_822ECB98);
PPC_FUNC_IMPL(__imp__sub_822ECB98) {
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
	// bl 0x82619428
	ctx.lr = 0x822ECBB8;
	sub_82619428(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r10,r11,-1688
	ctx.r10.s64 = r11.s64 + -1688;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821c9790
	ctx.lr = 0x822ECBD0;
	sub_821C9790(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_822ECBF0"))) PPC_WEAK_FUNC(sub_822ECBF0);
PPC_FUNC_IMPL(__imp__sub_822ECBF0) {
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
	ctx.lr = 0x822ECBF8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x82311450
	ctx.lr = 0x822ECC10;
	sub_82311450(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r31,-7572(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lbz r11,14546(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ecc5c
	if (!cr6.eq) goto loc_822ECC5C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822ECC2C;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822ecc4c
	if (cr6.gt) goto loc_822ECC4C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f10d0
	ctx.lr = 0x822ECC40;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822ecc58
	if (!cr6.lt) goto loc_822ECC58;
loc_822ECC4C:
	// lwz r31,-7572(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// li r11,1
	r11.s64 = 1;
	// b 0x822ecc60
	goto loc_822ECC60;
loc_822ECC58:
	// lwz r31,-7572(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -7572);
loc_822ECC5C:
	// li r11,0
	r11.s64 = 0;
loc_822ECC60:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eccc8
	if (cr6.eq) goto loc_822ECCC8;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// vaddfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r28,r1,96
	r28.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,14884(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lvlx128 v60,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v58,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v58,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f5d98
	ctx.lr = 0x822ECCBC;
	sub_822F5D98(ctx, base);
	// lwz r3,-7572(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -7572);
	// lfs f1,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f1688
	ctx.lr = 0x822ECCC8;
	sub_822F1688(ctx, base);
loc_822ECCC8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822ECCD4"))) PPC_WEAK_FUNC(sub_822ECCD4);
PPC_FUNC_IMPL(__imp__sub_822ECCD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ECCD8"))) PPC_WEAK_FUNC(sub_822ECCD8);
PPC_FUNC_IMPL(__imp__sub_822ECCD8) {
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
	// bl 0x82619418
	ctx.lr = 0x822ECCF8;
	sub_82619418(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ecd10
	if (cr6.eq) goto loc_822ECD10;
	// bl 0x82130588
	ctx.lr = 0x822ECD0C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822ECD10:
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

__attribute__((alias("__imp__sub_822ECD28"))) PPC_WEAK_FUNC(sub_822ECD28);
PPC_FUNC_IMPL(__imp__sub_822ECD28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x8247e500
	sub_8247E500(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ECD3C"))) PPC_WEAK_FUNC(sub_822ECD3C);
PPC_FUNC_IMPL(__imp__sub_822ECD3C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822ECD40"))) PPC_WEAK_FUNC(sub_822ECD40);
PPC_FUNC_IMPL(__imp__sub_822ECD40) {
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
	// lwz r11,-4916(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ecd74
	if (cr6.eq) goto loc_822ECD74;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7756(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7756);
	// bl 0x821c90c0
	ctx.lr = 0x822ECD6C;
	sub_821C90C0(ctx, base);
	// lwz r3,-4916(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// bl 0x8247d878
	ctx.lr = 0x822ECD74;
	sub_8247D878(ctx, base);
loc_822ECD74:
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

__attribute__((alias("__imp__sub_822ECD88"))) PPC_WEAK_FUNC(sub_822ECD88);
PPC_FUNC_IMPL(__imp__sub_822ECD88) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822ECD90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ece80
	if (!cr6.eq) goto loc_822ECE80;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x822f2300
	ctx.lr = 0x822ECDB0;
	sub_822F2300(ctx, base);
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x822ECDB8;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ecde8
	if (!cr6.eq) goto loc_822ECDE8;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r4,r11,2272
	ctx.r4.s64 = r11.s64 + 2272;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x822f5d98
	ctx.lr = 0x822ECDE8;
	sub_822F5D98(ctx, base);
loc_822ECDE8:
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// li r11,13952
	r11.s64 = 13952;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f6,f12,f0
	ctx.f6.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// lfs f13,7452(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7452);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f5,f11,f0
	ctx.f5.f64 = double(float(ctx.f11.f64 - f0.f64));
	// fmadds f2,f6,f13,f0
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f13.f64 + f0.f64));
	// stfs f2,88(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f4,f8,f13,f0
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + f0.f64));
	// stfs f4,84(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f3,f7,f13,f0
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + f0.f64));
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f1,f5,f13,f0
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + f0.f64));
	// stfs f1,92(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bl 0x822f0f28
	ctx.lr = 0x822ECE54;
	sub_822F0F28(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-4916(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4916);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ece80
	if (cr6.eq) goto loc_822ECE80;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// bl 0x822f1730
	ctx.lr = 0x822ECE6C;
	sub_822F1730(ctx, base);
	// bl 0x822eca90
	ctx.lr = 0x822ECE70;
	sub_822ECA90(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-4916(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4916);
	// bl 0x82481008
	ctx.lr = 0x822ECE80;
	sub_82481008(ctx, base);
loc_822ECE80:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822ECE88"))) PPC_WEAK_FUNC(sub_822ECE88);
PPC_FUNC_IMPL(__imp__sub_822ECE88) {
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
	ctx.lr = 0x822ECE90;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32120
	r27.s64 = -2105016320;
	// lbz r11,-7744(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + -7744);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ecee4
	if (cr6.eq) goto loc_822ECEE4;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// lis r28,-32120
	r28.s64 = -2105016320;
	// lis r31,-32120
	r31.s64 = -2105016320;
loc_822ECEB4:
	// lwz r3,-7752(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7752);
	// bl 0x821c90c0
	ctx.lr = 0x822ECEBC;
	sub_821C90C0(ctx, base);
	// lwz r3,-4916(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4916);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822eced0
	if (cr6.eq) goto loc_822ECED0;
	// lfs f1,-7760(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + -7760);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8247ff38
	ctx.lr = 0x822ECED0;
	sub_8247FF38(ctx, base);
loc_822ECED0:
	// lwz r3,-7756(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -7756);
	// bl 0x821c9108
	ctx.lr = 0x822ECED8;
	sub_821C9108(ctx, base);
	// lbz r11,-7744(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + -7744);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822eceb4
	if (!cr6.eq) goto loc_822ECEB4;
loc_822ECEE4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822ECEEC"))) PPC_WEAK_FUNC(sub_822ECEEC);
PPC_FUNC_IMPL(__imp__sub_822ECEEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ECEF0"))) PPC_WEAK_FUNC(sub_822ECEF0);
PPC_FUNC_IMPL(__imp__sub_822ECEF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// rlwinm r3,r31,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x822ECF0C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x822ecf34
	if (!cr6.gt) goto loc_822ECF34;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822ECF1C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ecf28
	if (cr6.eq) goto loc_822ECF28;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
loc_822ECF28:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x822ecf1c
	if (!cr0.eq) goto loc_822ECF1C;
loc_822ECF34:
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

__attribute__((alias("__imp__sub_822ECF48"))) PPC_WEAK_FUNC(sub_822ECF48);
PPC_FUNC_IMPL(__imp__sub_822ECF48) {
	PPC_FUNC_PROLOGUE();
	// b 0x822ece88
	sub_822ECE88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822ECF4C"))) PPC_WEAK_FUNC(sub_822ECF4C);
PPC_FUNC_IMPL(__imp__sub_822ECF4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ECF50"))) PPC_WEAK_FUNC(sub_822ECF50);
PPC_FUNC_IMPL(__imp__sub_822ECF50) {
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
	ctx.lr = 0x822ECF58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r10,r11,-7700
	ctx.r10.s64 = r11.s64 + -7700;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ed01c
	if (cr6.eq) goto loc_822ED01C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32128
	ctx.r9.s64 = -2105540608;
	// addi r6,r11,-1624
	ctx.r6.s64 = r11.s64 + -1624;
	// addi r5,r10,9572
	ctx.r5.s64 = ctx.r10.s64 + 9572;
	// addi r3,r9,-32120
	ctx.r3.s64 = ctx.r9.s64 + -32120;
	// bl 0x82137a08
	ctx.lr = 0x822ECF90;
	sub_82137A08(ctx, base);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r7,r8,-7720
	ctx.r7.s64 = ctx.r8.s64 + -7720;
	// lis r29,-32124
	r29.s64 = -2105278464;
	// li r31,0
	r31.s64 = 0;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822ecfe8
	if (cr6.eq) goto loc_822ECFE8;
	// lis r28,-32115
	r28.s64 = -2104688640;
	// lwz r3,-4916(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4916);
	// li r11,1
	r11.s64 = 1;
	// stb r11,19734(r28)
	PPC_STORE_U8(r28.u32 + 19734, r11.u8);
	// bl 0x8247e2e0
	ctx.lr = 0x822ECFC4;
	sub_8247E2E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stb r11,19734(r28)
	PPC_STORE_U8(r28.u32 + 19734, r11.u8);
	// beq cr6,0x822ecfe8
	if (cr6.eq) goto loc_822ECFE8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,-24880(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -24880);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r11,-24880(r29)
	PPC_STORE_U32(r29.u32 + -24880, r11.u32);
loc_822ECFE8:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lwz r3,-4916(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4916);
	// addi r4,r11,-1636
	ctx.r4.s64 = r11.s64 + -1636;
	// bl 0x8247e2e0
	ctx.lr = 0x822ECFF8;
	sub_8247E2E0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822ed058
	if (cr6.eq) goto loc_822ED058;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stw r11,-24880(r29)
	PPC_STORE_U32(r29.u32 + -24880, r11.u32);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822ED01C:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,1
	r11.s64 = 1;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32128
	ctx.r7.s64 = -2105540608;
	// stb r11,19734(r10)
	PPC_STORE_U8(ctx.r10.u32 + 19734, r11.u8);
	// addi r6,r9,-1656
	ctx.r6.s64 = ctx.r9.s64 + -1656;
	// addi r5,r8,9572
	ctx.r5.s64 = ctx.r8.s64 + 9572;
	// addi r3,r7,-32120
	ctx.r3.s64 = ctx.r7.s64 + -32120;
	// bl 0x82137a08
	ctx.lr = 0x822ED044;
	sub_82137A08(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// addi r4,r5,-1668
	ctx.r4.s64 = ctx.r5.s64 + -1668;
	// lwz r3,-4916(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -4916);
	// bl 0x8247e2e0
	ctx.lr = 0x822ED058;
	sub_8247E2E0(ctx, base);
loc_822ED058:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822ED060"))) PPC_WEAK_FUNC(sub_822ED060);
PPC_FUNC_IMPL(__imp__sub_822ED060) {
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
	ctx.lr = 0x822ED068;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// bne cr6,0x822ed110
	if (!cr6.eq) goto loc_822ED110;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x822ecef0
	ctx.lr = 0x822ED090;
	sub_822ECEF0(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ed0dc
	if (cr6.eq) goto loc_822ED0DC;
	// li r30,0
	r30.s64 = 0;
loc_822ED0A4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// addi r3,r9,4
	ctx.r3.s64 = ctx.r9.s64 + 4;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r9,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r9.u32);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x821d2a58
	ctx.lr = 0x822ED0C8;
	sub_821D2A58(ctx, base);
	// addi r8,r30,1
	ctx.r8.s64 = r30.s64 + 1;
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r30,r8,16
	r30.u64 = ctx.r8.u32 & 0xFFFF;
	// cmplw cr6,r30,r7
	cr6.compare<uint32_t>(r30.u32, ctx.r7.u32, xer);
	// blt cr6,0x822ed0a4
	if (cr6.lt) goto loc_822ED0A4;
loc_822ED0DC:
	// lhz r30,4(r31)
	r30.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822ed104
	if (!cr6.gt) goto loc_822ED104;
	// addi r28,r27,4
	r28.s64 = r27.s64 + 4;
loc_822ED0F0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x822ED0F8;
	sub_821D2AA0(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// bne 0x822ed0f0
	if (!cr0.eq) goto loc_822ED0F0;
loc_822ED104:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x822ED10C;
	sub_82130588(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
loc_822ED110:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,3
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 3);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822ED130"))) PPC_WEAK_FUNC(sub_822ED130);
PPC_FUNC_IMPL(__imp__sub_822ED130) {
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
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x821d4268
	ctx.lr = 0x822ED158;
	sub_821D4268(ctx, base);
	// lis r11,-32209
	r11.s64 = -2110849024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-13432
	ctx.r10.s64 = r11.s64 + -13432;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_822ED17C"))) PPC_WEAK_FUNC(sub_822ED17C);
PPC_FUNC_IMPL(__imp__sub_822ED17C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822ED180"))) PPC_WEAK_FUNC(sub_822ED180);
PPC_FUNC_IMPL(__imp__sub_822ED180) {
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x822ED1A0;
	sub_82205248(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// li r3,38
	ctx.r3.s64 = 38;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8217f768
	ctx.lr = 0x822ED1BC;
	sub_8217F768(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// lwz r3,-8092(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// lwz r31,21664(r6)
	r31.u64 = PPC_LOAD_U32(ctx.r6.u32 + 21664);
	// bl 0x822e51e0
	ctx.lr = 0x822ED1D0;
	sub_822E51E0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// clrlwi r6,r30,24
	ctx.r6.u64 = r30.u32 & 0xFF;
	// bl 0x826109a8
	ctx.lr = 0x822ED1E4;
	sub_826109A8(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r5,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822ED1F4;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r11,1
	r11.s64 = 1;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r10,100(r1)
	PPC_STORE_U64(ctx.r1.u32 + 100, ctx.r10.u64);
	// li r3,20
	ctx.r3.s64 = 20;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// bl 0x8217f768
	ctx.lr = 0x822ED214;
	sub_8217F768(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r3,-7436(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7436);
	// bl 0x822f73b8
	ctx.lr = 0x822ED220;
	sub_822F73B8(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82491668
	ctx.lr = 0x822ED228;
	sub_82491668(ctx, base);
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

__attribute__((alias("__imp__sub_822ED240"))) PPC_WEAK_FUNC(sub_822ED240);
PPC_FUNC_IMPL(__imp__sub_822ED240) {
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
	ctx.lr = 0x822ED248;
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
	// ble cr6,0x822ed278
	if (!cr6.gt) goto loc_822ED278;
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
loc_822ED264:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x822ED26C;
	sub_821D2AA0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,8
	r30.s64 = r30.s64 + 8;
	// bne 0x822ed264
	if (!cr0.eq) goto loc_822ED264;
loc_822ED278:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130588
	ctx.lr = 0x822ED280;
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

__attribute__((alias("__imp__sub_822ED298"))) PPC_WEAK_FUNC(sub_822ED298);
PPC_FUNC_IMPL(__imp__sub_822ED298) {
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
	ctx.lr = 0x822ED2A0;
	// stwu r1,-1200(r1)
	ea = -1200 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r31,r11,7456
	r31.s64 = r11.s64 + 7456;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x822ed240
	ctx.lr = 0x822ED2B4;
	sub_822ED240(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r28,r10,30576
	r28.s64 = ctx.r10.s64 + 30576;
	// addi r4,r11,-1584
	ctx.r4.s64 = r11.s64 + -1584;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821ca540
	ctx.lr = 0x822ED2D4;
	sub_821CA540(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r30,r10,-1596
	r30.s64 = ctx.r10.s64 + -1596;
	// addi r5,r9,-6232
	ctx.r5.s64 = ctx.r9.s64 + -6232;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x822ED2F8;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// bl 0x821d1ce8
	ctx.lr = 0x822ED30C;
	sub_821D1CE8(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822ed3c8
	if (cr6.eq) goto loc_822ED3C8;
loc_822ED314:
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// bl 0x821cfaa8
	ctx.lr = 0x822ED324;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822ed3c8
	if (cr6.eq) goto loc_822ED3C8;
	// li r5,256
	ctx.r5.s64 = 256;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// bl 0x821cfaa8
	ctx.lr = 0x822ED33C;
	sub_821CFAA8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822ed3c8
	if (cr6.eq) goto loc_822ED3C8;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_822ED34C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822ed34c
	if (!cr6.eq) goto loc_822ED34C;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r30,r11,1
	r30.s64 = r11.s64 + 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130528
	ctx.lr = 0x822ED374;
	sub_82130528(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x823da950
	ctx.lr = 0x822ED380;
	sub_823DA950(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,352
	ctx.r3.s64 = ctx.r1.s64 + 352;
	// bl 0x821c9790
	ctx.lr = 0x822ED390;
	sub_821C9790(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x822ed060
	ctx.lr = 0x822ED3A8;
	sub_822ED060(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// stw r30,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r30.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821d2a58
	ctx.lr = 0x822ED3BC;
	sub_821D2A58(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x822ED3C4;
	sub_821D2AA0(ctx, base);
	// b 0x822ed314
	goto loc_822ED314;
loc_822ED3C8:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ed3fc
	if (!cr6.eq) goto loc_822ED3FC;
	// lhz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822ed3f4
	if (cr6.eq) goto loc_822ED3F4;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r6,r11,10896
	ctx.r6.s64 = r11.s64 + 10896;
	// bl 0x823dcf08
	ctx.lr = 0x822ED3F4;
	sub_823DCF08(ctx, base);
loc_822ED3F4:
	// li r11,1
	r11.s64 = 1;
	// stb r11,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r11.u8);
loc_822ED3FC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822ED404;
	sub_821C9A90(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r10,r11,-30140
	ctx.r10.s64 = r11.s64 + -30140;
	// stw r10,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, ctx.r10.u32);
	// beq cr6,0x822ed420
	if (cr6.eq) goto loc_822ED420;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x822ED420;
	sub_821BE610(ctx, base);
loc_822ED420:
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822ED428"))) PPC_WEAK_FUNC(sub_822ED428);
PPC_FUNC_IMPL(__imp__sub_822ED428) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82480a98
	ctx.lr = 0x822ED440;
	sub_82480A98(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-7740
	ctx.r10.s64 = r11.s64 + -7740;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ed604
	if (!cr6.eq) goto loc_822ED604;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,2500
	ctx.r4.s64 = 2500;
	// lwz r3,-4916(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// bl 0x82480460
	ctx.lr = 0x822ED464;
	sub_82480460(ctx, base);
	// li r5,20
	ctx.r5.s64 = 20;
	// lwz r3,-4916(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// li r4,250
	ctx.r4.s64 = 250;
	// bl 0x8247f520
	ctx.lr = 0x822ED474;
	sub_8247F520(ctx, base);
	// li r4,1000
	ctx.r4.s64 = 1000;
	// lwz r3,-4916(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// bl 0x8247edb8
	ctx.lr = 0x822ED480;
	sub_8247EDB8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-4916(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// bl 0x8247de10
	ctx.lr = 0x822ED48C;
	sub_8247DE10(ctx, base);
	// lwz r11,-4916(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,12
	ctx.r3.s64 = 12;
	// lwz r9,636(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 636);
	// stb r10,80(r9)
	PPC_STORE_U8(ctx.r9.u32 + 80, ctx.r10.u8);
	// bl 0x82130528
	ctx.lr = 0x822ED4A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ed4c0
	if (cr6.eq) goto loc_822ED4C0;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r4,r11,-1536
	ctx.r4.s64 = r11.s64 + -1536;
	// bl 0x822ecb98
	ctx.lr = 0x822ED4B8;
	sub_822ECB98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// b 0x822ed4c4
	goto loc_822ED4C4;
loc_822ED4C0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_822ED4C4:
	// lis r30,-32120
	r30.s64 = -2105016320;
	// addi r3,r30,-7680
	ctx.r3.s64 = r30.s64 + -7680;
	// bl 0x82265100
	ctx.lr = 0x822ED4D0;
	sub_82265100(ctx, base);
	// lwz r30,-7680(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -7680);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ed4f0
	if (cr6.eq) goto loc_822ED4F0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822ED4F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822ED4F0:
	// lwz r11,-4916(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,676
	ctx.r3.s64 = r11.s64 + 676;
	// bl 0x82265100
	ctx.lr = 0x822ED500;
	sub_82265100(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ed51c
	if (cr6.eq) goto loc_822ED51C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822ED51C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822ED51C:
	// bl 0x822ecf50
	ctx.lr = 0x822ED520;
	sub_822ECF50(ctx, base);
	// bl 0x822ed298
	ctx.lr = 0x822ED524;
	sub_822ED298(ctx, base);
	// lis r11,-32209
	r11.s64 = -2110849024;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r11,-13576
	ctx.r5.s64 = r11.s64 + -13576;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d4268
	ctx.lr = 0x822ED540;
	sub_821D4268(ctx, base);
	// lis r10,-32209
	ctx.r10.s64 = -2110849024;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r11,-4916(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4916);
	// addi r8,r10,-13432
	ctx.r8.s64 = ctx.r10.s64 + -13432;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r11,44
	ctx.r5.s64 = r11.s64 + 44;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r5,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// stw r4,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r4.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r8,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r8.u32);
	// lwz r10,0(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r9,4(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r8,8(r6)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r4,12(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r4,56(r11)
	PPC_STORE_U32(r11.u32 + 56, ctx.r4.u32);
	// stw r8,52(r11)
	PPC_STORE_U32(r11.u32 + 52, ctx.r8.u32);
	// stw r9,48(r11)
	PPC_STORE_U32(r11.u32 + 48, ctx.r9.u32);
	// stw r10,44(r11)
	PPC_STORE_U32(r11.u32 + 44, ctx.r10.u32);
	// bl 0x821c9060
	ctx.lr = 0x822ED5A8;
	sub_821C9060(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-7752(r7)
	PPC_STORE_U32(ctx.r7.u32 + -7752, r11.u32);
	// bl 0x821c9060
	ctx.lr = 0x822ED5BC;
	sub_821C9060(ctx, base);
	// lis r6,-32120
	ctx.r6.s64 = -2105016320;
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// li r4,1
	ctx.r4.s64 = 1;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32209
	ctx.r10.s64 = -2110849024;
	// stb r4,-7744(r6)
	PPC_STORE_U8(ctx.r6.u32 + -7744, ctx.r4.u8);
	// addi r7,r11,-1560
	ctx.r7.s64 = r11.s64 + -1560;
	// stw r3,-7756(r5)
	PPC_STORE_U32(ctx.r5.u32 + -7756, ctx.r3.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-12472
	ctx.r3.s64 = ctx.r10.s64 + -12472;
	// bl 0x821c9308
	ctx.lr = 0x822ED5F8;
	sub_821C9308(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// stw r3,-7748(r9)
	PPC_STORE_U32(ctx.r9.u32 + -7748, ctx.r3.u32);
	// b 0x822ed610
	goto loc_822ED610;
loc_822ED604:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7748(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7748, r11.u32);
loc_822ED610:
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

__attribute__((alias("__imp__sub_822ED628"))) PPC_WEAK_FUNC(sub_822ED628);
PPC_FUNC_IMPL(__imp__sub_822ED628) {
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
	ctx.lr = 0x822ED630;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r11,-7536
	ctx.r10.s64 = r11.s64 + -7536;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x822ed660
	if (cr6.eq) goto loc_822ED660;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-1112
	ctx.r4.s64 = ctx.r10.s64 + -1112;
	// b 0x822ed668
	goto loc_822ED668;
loc_822ED660:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r10,-1136
	ctx.r4.s64 = ctx.r10.s64 + -1136;
loc_822ED668:
	// bl 0x821ca540
	ctx.lr = 0x822ED66C;
	sub_821CA540(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r11,-7652(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7652);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822ed6a4
	if (!cr6.eq) goto loc_822ED6A4;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-1152
	ctx.r4.s64 = ctx.r10.s64 + -1152;
	// lwz r3,-25232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -25232);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822ED6A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,-7652(r30)
	PPC_STORE_U32(r30.u32 + -7652, ctx.r3.u32);
loc_822ED6A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822ED6AC;
	sub_821C9A90(ctx, base);
	// lis r11,-32124
	r11.s64 = -2105278464;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r29,r10,-1164
	r29.s64 = ctx.r10.s64 + -1164;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822ED6D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r31,-32120
	r31.s64 = -2105016320;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,-7648(r31)
	PPC_STORE_U32(r31.u32 + -7648, ctx.r3.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822ED710;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-7648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7648);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-1184
	ctx.r4.s64 = ctx.r10.s64 + -1184;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822ED728;
	sub_8218A568(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822ed748
	if (cr6.eq) goto loc_822ED748;
	// lwz r11,-7648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7648);
	// lwz r6,-7652(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + -7652);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822ED748;
	sub_82189CE0(ctx, base);
loc_822ED748:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822ED750"))) PPC_WEAK_FUNC(sub_822ED750);
PPC_FUNC_IMPL(__imp__sub_822ED750) {
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
	PPCRegister f0{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822ED758;
	// addi r31,r1,-160
	r31.s64 = ctx.r1.s64 + -160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// stfs f1,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// neg r10,r11
	ctx.r10.s64 = -r11.s64;
	// rlwinm r12,r10,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF0;
	// bl 0x823dbff4
	ctx.lr = 0x822ED774;
	sub_823DBFF4(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stwux r8,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r8.u32);
	ctx.r1.u32 = ea;
	// fsubs f0,f0,f1
	f0.f64 = double(float(f0.f64 - ctx.f1.f64));
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// ble cr6,0x822ed7b8
	if (!cr6.gt) goto loc_822ED7B8;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// subf r9,r4,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r4.s64;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_822ED7A4:
	// lvx128 v63,r9,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x822ed7a4
	if (!cr0.eq) goto loc_822ED7A4;
loc_822ED7B8:
	// cmpwi cr6,r7,1
	cr6.compare<int32_t>(ctx.r7.s32, 1, xer);
	// ble cr6,0x822ed938
	if (!cr6.gt) goto loc_822ED938;
	// addi r5,r7,-1
	ctx.r5.s64 = ctx.r7.s64 + -1;
	// addi r29,r7,-1
	r29.s64 = ctx.r7.s64 + -1;
	// li r30,32
	r30.s64 = 32;
loc_822ED7CC:
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r5,4
	cr6.compare<int32_t>(ctx.r5.s32, 4, xer);
	// blt cr6,0x822ed8d4
	if (cr6.lt) goto loc_822ED8D4;
	// addi r10,r5,-4
	ctx.r10.s64 = ctx.r5.s64 + -4;
	// addi r11,r4,32
	r11.s64 = ctx.r4.s64 + 32;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
loc_822ED7EC:
	// addi r9,r31,80
	ctx.r9.s64 = r31.s64 + 80;
	// addi r8,r11,-32
	ctx.r8.s64 = r11.s64 + -32;
	// addi r28,r31,196
	r28.s64 = r31.s64 + 196;
	// addi r10,r11,-16
	ctx.r10.s64 = r11.s64 + -16;
	// addi r27,r31,80
	r27.s64 = r31.s64 + 80;
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r26,r31,196
	r26.s64 = r31.s64 + 196;
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v59,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r28,r31,80
	r28.s64 = r31.s64 + 80;
	// vspltw128 v0,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// addi r25,r31,196
	r25.s64 = r31.s64 + 196;
	// lvlx128 v58,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// vmulfp128 v57,v60,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32)));
	// vspltw128 v56,v58,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvlx128 v55,r0,r26
	temp.u32 = r26.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r27,r31,80
	r27.s64 = r31.s64 + 80;
	// vspltw128 v13,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvlx128 v54,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v54,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lvlx128 v52,r0,r25
	temp.u32 = r25.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v52,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// addi r28,r31,196
	r28.s64 = r31.s64 + 196;
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// lvlx128 v51,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lvlx128 v49,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v49,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// vor128 v10,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v8,v9,v0,v10
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// stvx128 v8,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r10
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v47,v48,v56
	simde_mm_store_ps(v47.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v56.f32)));
	// vor128 v6,v47,v47
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// stvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v7,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v5,v7,v13,v6
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v5,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v45,v46,v53
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v53.f32)));
	// vor128 v4,v45,v45
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v45.u8));
	// stvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v3,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v2,v3,v12,v4
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// stvx128 v2,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r9
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v43,v44,v50
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v50.f32)));
	// vor128 v31,v43,v43
	simde_mm_store_si128((simde__m128i*)v31.u8, simde_mm_load_si128((simde__m128i*)v43.u8));
	// stvx128 v43,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r11,r30
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// vmaddfp v30,v1,v11,v31
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(v31.f32)));
	// stvx128 v30,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne 0x822ed7ec
	if (!cr0.eq) goto loc_822ED7EC;
loc_822ED8D4:
	// cmpw cr6,r6,r5
	cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, xer);
	// bge cr6,0x822ed92c
	if (!cr6.lt) goto loc_822ED92C;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r10,r6,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r6.s64;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
loc_822ED8E8:
	// addi r8,r31,80
	ctx.r8.s64 = r31.s64 + 80;
	// lvx128 v42,r0,r11
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r31,196
	ctx.r7.s64 = r31.s64 + 196;
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvlx128 v41,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v40,v41,0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xFF));
	// lvlx128 v39,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v39,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xFF));
	// vmulfp128 v38,v42,v40
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v40.f32)));
	// vor128 v13,v38,v38
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v38.u8));
	// stvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v0,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// bne 0x822ed8e8
	if (!cr0.eq) goto loc_822ED8E8;
loc_822ED92C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// bne 0x822ed7cc
	if (!cr0.eq) goto loc_822ED7CC;
loc_822ED938:
	// lvx128 v37,r0,r4
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r31,160
	ctx.r1.s64 = r31.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822ED948"))) PPC_WEAK_FUNC(sub_822ED948);
PPC_FUNC_IMPL(__imp__sub_822ED948) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// stw r4,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, ctx.r4.u32);
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// lfs f12,48(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r8,2176
	ctx.r6.s64 = ctx.r8.s64 + 2176;
	// lfs f11,52(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// ori r11,r7,64167
	r11.u64 = ctx.r7.u64 | 64167;
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r4,2176(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// mulld r9,r4,r11
	ctx.r9.s64 = ctx.r4.s64 * r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f0,14348(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// clrlwi r4,r10,9
	ctx.r4.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f9,-16(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
	// stw r9,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, ctx.r9.u32);
	// lfs f13,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lwz r5,56(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// fmuls f6,f10,f7
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f7.f64));
	// fmadds f5,f6,f0,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64 + ctx.f12.f64));
	// stfs f5,16(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r7,2176(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// mulld r9,r7,r11
	ctx.r9.s64 = ctx.r7.s64 * r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f4,56(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,60(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 60);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f12,f3,f4
	ctx.f12.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// clrlwi r7,r10,9
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f2,-16(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f11,f1
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
	// stw r9,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, ctx.r9.u32);
	// lwz r5,56(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// fmuls f10,f12,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmadds f9,f10,f0,f4
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f4.f64));
	// fdivs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 / ctx.f9.f64));
	// stfs f8,20(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r7,2176(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// mulld r9,r7,r11
	ctx.r9.s64 = ctx.r7.s64 * r11.s64;
	// lfs f7,80(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lfs f6,84(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	ctx.f6.f64 = double(temp.f32);
	// clrlwi r7,r10,9
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r7,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r7.u64);
	// lfd f5,-16(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// fsubs f3,f6,f7
	ctx.f3.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// stw r9,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, ctx.r9.u32);
	// lwz r5,56(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmuls f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f2.f64));
	// fmadds f12,f1,f0,f7
	ctx.f12.f64 = double(float(ctx.f1.f64 * f0.f64 + ctx.f7.f64));
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// stfs f11,28(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r10,2176(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// mulld r10,r10,r4
	ctx.r10.s64 = ctx.r10.s64 * ctx.r4.s64;
	// lfs f10,64(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	ctx.f10.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lfs f9,68(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// stw r11,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, r11.u32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// stw r11,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, r11.u32);
	// lfd f7,-16(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// fmuls f4,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f5.f64));
	// fmadds f3,f4,f0,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64 + ctx.f10.f64));
	// stfs f3,24(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lwz r11,2176(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// mulld r11,r11,r7
	r11.s64 = r11.s64 * ctx.r7.s64;
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, r11.u32);
	// clrldi r7,r11,33
	ctx.r7.u64 = r11.u64 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// stfs f13,48(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// std r7,40(r3)
	PPC_STORE_U64(ctx.r3.u32 + 40, ctx.r7.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EDAEC"))) PPC_WEAK_FUNC(sub_822EDAEC);
PPC_FUNC_IMPL(__imp__sub_822EDAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EDAF0"))) PPC_WEAK_FUNC(sub_822EDAF0);
PPC_FUNC_IMPL(__imp__sub_822EDAF0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lfs f0,48(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	f0.f64 = double(temp.f32);
	// lwz r9,56(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lfs f13,20(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fmadds f11,f1,f13,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 + f0.f64));
	// lfs f10,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,28(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fmadds f8,f1,f9,f10
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f9.f64 + ctx.f10.f64));
	// lfs f7,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// lis r5,23772
	ctx.r5.s64 = 1557921792;
	// stfs f11,48(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stfs f8,52(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// ori r10,r5,64167
	ctx.r10.u64 = ctx.r5.u64 | 64167;
	// lfs f6,92(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f6,f1,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f7.f64));
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r11,r11,2176
	r11.s64 = r11.s64 + 2176;
	// lfs f12,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// lfs f13,14348(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14348);
	ctx.f13.f64 = double(temp.f32);
	// stfs f5,32(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// ble cr6,0x822edbf8
	if (!cr6.gt) goto loc_822EDBF8;
	// stfs f12,48(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f11,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f10,52(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// mulld r9,r6,r10
	ctx.r9.s64 = ctx.r6.s64 * ctx.r10.s64;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// clrlwi r4,r9,9
	ctx.r4.u64 = ctx.r9.u32 & 0x7FFFFF;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// std r4,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r4.u64);
	// lfd f8,-32(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// rldicl r9,r9,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r7,56(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// fmuls f5,f9,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f6.f64));
	// fmadds f4,f5,f13,f11
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stfs f4,16(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r8,r6,r10
	ctx.r8.s64 = ctx.r6.s64 * ctx.r10.s64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lfs f3,56(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,60(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 60);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f9,f2,f3
	ctx.f9.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// clrlwi r4,r9,9
	ctx.r4.u64 = ctx.r9.u32 & 0x7FFFFF;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// std r4,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r4.u64);
	// lfd f11,-32(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// rldicl r9,r9,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// fmuls f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// fmadds f6,f7,f13,f3
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f3.f64));
	// fdivs f5,f0,f6
	ctx.f5.f64 = double(float(f0.f64 / ctx.f6.f64));
	// stfs f5,20(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
loc_822EDBF8:
	// lfs f11,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x822edcd8
	if (!cr6.gt) goto loc_822EDCD8;
	// stfs f12,52(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// lfs f10,80(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f11,84(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// mulld r9,r7,r10
	ctx.r9.s64 = ctx.r7.s64 * ctx.r10.s64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// clrlwi r5,r9,9
	ctx.r5.u64 = ctx.r9.u32 & 0x7FFFFF;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// std r5,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f8,-32(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// rldicl r9,r9,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// lwz r4,56(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// fmuls f5,f9,f6
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f6.f64));
	// fmadds f4,f5,f13,f10
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fdivs f3,f0,f4
	ctx.f3.f64 = double(float(f0.f64 / ctx.f4.f64));
	// stfs f3,28(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lfs f2,64(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 64);
	ctx.f2.f64 = double(temp.f32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,68(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	f0.f64 = double(temp.f32);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r8,r7,r10
	ctx.r8.s64 = ctx.r7.s64 * ctx.r10.s64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// fsubs f11,f0,f2
	ctx.f11.f64 = double(float(f0.f64 - ctx.f2.f64));
	// clrlwi r5,r9,9
	ctx.r5.u64 = ctx.r9.u32 & 0x7FFFFF;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// std r5,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r5.u64);
	// lfd f10,-32(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// rldicl r9,r9,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmadds f6,f7,f13,f2
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f2.f64));
	// stfs f6,24(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mulld r8,r4,r10
	ctx.r8.s64 = ctx.r4.s64 * ctx.r10.s64;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// rldicl r7,r9,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// clrldi r9,r9,33
	ctx.r9.u64 = ctx.r9.u64 & 0x7FFFFFFF;
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r7,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r7.u32);
	// std r9,40(r3)
	PPC_STORE_U64(ctx.r3.u32 + 40, ctx.r9.u64);
loc_822EDCD8:
	// fcmpu cr6,f1,f12
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lwz r5,56(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r7,16
	ctx.r7.s64 = 16;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mulld r9,r6,r8
	ctx.r9.s64 = ctx.r6.s64 * ctx.r8.s64;
	// lvx128 v62,r5,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r4,r1,-16
	ctx.r4.s64 = ctx.r1.s64 + -16;
	// clrlwi r7,r10,9
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFF;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// std r7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// lfs f11,-8(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	ctx.f11.f64 = double(temp.f32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// lfs f12,-16(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f12.f64 = double(temp.f32);
	// lfd f9,-32(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// lfs f0,-12(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	f0.f64 = double(temp.f32);
	// lfs f10,-4(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// fmuls f5,f10,f6
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f6.f64));
	// stfs f5,-4(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// fmuls f4,f12,f6
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f6.f64));
	// stfs f4,-16(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// fmuls f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f3,-12(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// fmuls f2,f11,f6
	ctx.f2.f64 = double(float(ctx.f11.f64 * ctx.f6.f64));
	// stfs f2,-8(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v63,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v59,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822EDD7C"))) PPC_WEAK_FUNC(sub_822EDD7C);
PPC_FUNC_IMPL(__imp__sub_822EDD7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EDD80"))) PPC_WEAK_FUNC(sub_822EDD80);
PPC_FUNC_IMPL(__imp__sub_822EDD80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v16{};
	PPCVRegister v17{};
	PPCVRegister v18{};
	PPCVRegister v19{};
	PPCVRegister v20{};
	PPCVRegister v21{};
	PPCVRegister v22{};
	PPCVRegister v23{};
	PPCVRegister v24{};
	PPCVRegister v25{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x822EDD88;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9d0
	ctx.lr = 0x822EDD90;
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v125,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-192
	r12.s64 = -192;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,-416
	r31.s64 = ctx.r1.s64 + -416;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// lwz r11,56(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 56);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// lfd f0,-1072(r10)
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + -1072);
	// lfs f13,88(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x822ee468
	if (cr6.lt) goto loc_822EE468;
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// lwz r20,96(r11)
	r20.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// rlwinm r10,r21,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r21.u32 | (r21.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v127,r0,r22
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r29,-16
	r29.s64 = -16;
	// add r8,r10,r22
	ctx.r8.u64 = ctx.r10.u64 + r22.u64;
	// li r7,112
	ctx.r7.s64 = 112;
	// lwz r11,-26876(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -26876);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lvx128 v126,r8,r29
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,2240
	ctx.r3.s64 = ctx.r5.s64 + 2240;
	// vsubfp128 v60,v126,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// vsubfp128 v58,v127,v59
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v59.f32)));
	// addi r8,r10,-31648
	ctx.r8.s64 = ctx.r10.s64 + -31648;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r9,-31664
	ctx.r7.s64 = ctx.r9.s64 + -31664;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r30,r20,4,0,27
	r30.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 4) & 0xFFFFFFF0;
	// vor128 v0,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// neg r6,r30
	ctx.r6.s64 = -r30.s64;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v10,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v63.u8));
	// lvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r12,r6,0,0,27
	r12.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFF0;
	// vmsum3fp128 v57,v60,v60
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmsum3fp128 v56,v58,v58
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// vrsqrtefp128 v55,v57
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v57.f32))));
	// vor128 v9,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// vrsqrtefp128 v54,v56
	simde_mm_store_ps(v54.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// vor128 v8,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vcmpeqfp128 v7,v55,v62
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v6,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// vcmpeqfp128 v5,v54,v62
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v4,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v54.u8));
	// vsel v13,v6,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vsel v0,v4,v11,v5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vmulfp128 v3,v13,v13
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v2,v61,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v1,v0,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v31,v61,v0
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v30,v9,v3,v12
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v29,v8,v1,v12
	simde_mm_store_ps(v29.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v28,v30,v2,v13
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v27,v29,v31,v0
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v53,v60,v28
	simde_mm_store_ps(v53.f32, simde_mm_mul_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v28.f32)));
	// vmulfp128 v52,v58,v27
	simde_mm_store_ps(v52.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v27.f32)));
	// vpermwi128 v51,v53,99
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x9C));
	// vpermwi128 v26,v53,135
	simde_mm_store_si128((simde__m128i*)v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0x78));
	// vpermwi128 v50,v52,135
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0x78));
	// vpermwi128 v25,v52,99
	simde_mm_store_si128((simde__m128i*)v25.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0x9C));
	// vmulfp128 v24,v50,v51
	simde_mm_store_ps(v24.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// vnmsubfp v23,v25,v26,v24
	simde_mm_store_ps(v23.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v25.f32), simde_mm_load_ps(v26.f32)), simde_mm_load_ps(v24.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmsum3fp128 v49,v23,v23
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v23.f32), simde_mm_load_ps(v23.f32), 0xEF));
	// vrsqrtefp128 v48,v49
	simde_mm_store_ps(v48.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v49.f32))));
	// vor128 v22,v49,v49
	simde_mm_store_si128((simde__m128i*)v22.u8, simde_mm_load_si128((simde__m128i*)v49.u8));
	// vcmpeqfp128 v21,v48,v62
	simde_mm_store_ps(v21.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v20,v48,v48
	simde_mm_store_si128((simde__m128i*)v20.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// vsel v0,v20,v10,v21
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)v20.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vmulfp128 v19,v0,v0
	simde_mm_store_ps(v19.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v18,v61,v0
	simde_mm_store_ps(v18.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v17,v22,v19,v12
	simde_mm_store_ps(v17.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v22.f32), simde_mm_load_ps(v19.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v16,v17,v18,v0
	simde_mm_store_ps(v16.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v17.f32), simde_mm_load_ps(v18.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v125,v23,v16
	simde_mm_store_ps(v125.f32, simde_mm_mul_ps(simde_mm_load_ps(v23.f32), simde_mm_load_ps(v16.f32)));
	// bl 0x823dbff4
	ctx.lr = 0x822EDEF8;
	sub_823DBFF4(ctx, base);
	// lwz r5,0(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// stwux r5,r1,r12
	ea = ctx.r1.u32 + r12.u32;
	PPC_STORE_U32(ea, ctx.r5.u32);
	ctx.r1.u32 = ea;
	// addi r19,r1,96
	r19.s64 = ctx.r1.s64 + 96;
	// ble cr6,0x822edf2c
	if (!cr6.gt) goto loc_822EDF2C;
	// vspltisw128 v47,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_set1_epi32(int(0x0)));
	// rlwinm r11,r20,4,0,27
	r11.u64 = __builtin_rotateleft64(r20.u32 | (r20.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// addi r11,r11,-9
	r11.s64 = r11.s64 + -9;
	// addi r3,r19,16
	ctx.r3.s64 = r19.s64 + 16;
	// rlwinm r5,r11,0,0,28
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFF8;
	// stvx128 v47,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dadd8
	ctx.lr = 0x822EDF2C;
	sub_823DADD8(ctx, base);
loc_822EDF2C:
	// add r11,r30,r19
	r11.u64 = r30.u64 + r19.u64;
	// stvx128 v127,r0,r19
	simde_mm_store_si128((simde__m128i*)(base + ((r19.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r20,-1
	r23.s64 = r20.s64 + -1;
	// li r28,1
	r28.s64 = 1;
	// cmpwi cr6,r23,1
	cr6.compare<int32_t>(r23.s32, 1, xer);
	// stvx128 v126,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,56(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 56);
	// lfs f0,52(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,48(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,68(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,76(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,52(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f9,96(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * f0.f64));
	// ble cr6,0x822ee1b4
	if (!cr6.gt) goto loc_822EE1B4;
	// extsw r11,r23
	r11.s64 = r23.s32;
	// fneg f11,f10
	ctx.f11.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fneg f13,f9
	ctx.f13.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,104(r31)
	PPC_STORE_U64(r31.u32 + 104, r11.u64);
	// lfd f0,104(r31)
	f0.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// fcfid f12,f0
	ctx.f12.f64 = double(f0.s64);
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// lfs f12,14348(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14348);
	ctx.f12.f64 = double(temp.f32);
	// addi r26,r19,16
	r26.s64 = r19.s64 + 16;
	// fsubs f7,f10,f11
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// ori r29,r9,64167
	r29.u64 = ctx.r9.u64 | 64167;
	// fsubs f6,f9,f13
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// addi r30,r11,2176
	r30.s64 = r11.s64 + 2176;
loc_822EDFB0:
	// extsw r11,r28
	r11.s64 = r28.s32;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// std r11,104(r31)
	PPC_STORE_U64(r31.u32 + 104, r11.u64);
	// lfd f0,104(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 104);
	// fcfid f5,f0
	ctx.f5.f64 = double(f0.s64);
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r31,192
	ctx.r3.s64 = r31.s64 + 192;
	// fdivs f1,f4,f8
	ctx.f1.f64 = double(float(ctx.f4.f64 / ctx.f8.f64));
	// bl 0x822ed750
	ctx.lr = 0x822EDFDC;
	sub_822ED750(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r8,r31,192
	ctx.r8.s64 = r31.s64 + 192;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r9,r31,96
	ctx.r9.s64 = r31.s64 + 96;
	// mulld r10,r7,r29
	ctx.r10.s64 = ctx.r7.s64 * r29.s64;
	// lvx128 v13,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f3,f10,f11
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fsubs f2,f10,f11
	ctx.f2.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f1,f9,f13
	ctx.f1.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lvlx128 v46,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fsubs f0,f9,f13
	f0.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// vspltw128 v0,v46,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// vmaddfp v11,v13,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r6,r31,192
	ctx.r6.s64 = r31.s64 + 192;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r8,r10,r29
	ctx.r8.s64 = ctx.r10.s64 * r29.s64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lfs f5,0(r25)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// stvx128 v11,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f4.f64 = double(temp.f32);
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r4,r11,9
	ctx.r4.u64 = r11.u32 & 0x7FFFFF;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// rldicl r9,r10,32,32
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// std r4,112(r31)
	PPC_STORE_U64(r31.u32 + 112, ctx.r4.u64);
	// mulld r8,r11,r29
	ctx.r8.s64 = r11.s64 * r29.s64;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lfd f30,112(r31)
	f30.u64 = PPC_LOAD_U64(r31.u32 + 112);
	// fcfid f30,f30
	f30.f64 = double(f30.s64);
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// frsp f30,f30
	f30.f64 = double(float(f30.f64));
	// clrlwi r9,r10,9
	ctx.r9.u64 = ctx.r10.u32 & 0x7FFFFF;
	// std r9,120(r31)
	PPC_STORE_U64(r31.u32 + 120, ctx.r9.u64);
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// std r8,128(r31)
	PPC_STORE_U64(r31.u32 + 128, ctx.r8.u64);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lfs f29,4(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 4);
	f29.f64 = double(temp.f32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// mulld r9,r10,r29
	ctx.r9.s64 = ctx.r10.s64 * r29.s64;
	// fmuls f3,f3,f30
	ctx.f3.f64 = double(float(ctx.f3.f64 * f30.f64));
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// fmadds f3,f3,f12,f11
	ctx.f3.f64 = double(float(ctx.f3.f64 * ctx.f12.f64 + ctx.f11.f64));
	// lfd f28,120(r31)
	f28.u64 = PPC_LOAD_U64(r31.u32 + 120);
	// lfd f27,128(r31)
	f27.u64 = PPC_LOAD_U64(r31.u32 + 128);
	// fcfid f28,f28
	f28.f64 = double(f28.s64);
	// fcfid f27,f27
	f27.f64 = double(f27.s64);
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// lfs f30,8(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8);
	f30.f64 = double(temp.f32);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// mulld r10,r10,r29
	ctx.r10.s64 = ctx.r10.s64 * r29.s64;
	// stw r11,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r11.u32);
	// std r6,144(r31)
	PPC_STORE_U64(r31.u32 + 144, ctx.r6.u64);
	// fmadds f5,f3,f5,f4
	ctx.f5.f64 = double(float(ctx.f3.f64 * ctx.f5.f64 + ctx.f4.f64));
	// frsp f28,f28
	f28.f64 = double(float(f28.f64));
	// frsp f27,f27
	f27.f64 = double(float(f27.f64));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// fmuls f2,f2,f28
	ctx.f2.f64 = double(float(ctx.f2.f64 * f28.f64));
	// fmuls f28,f27,f7
	f28.f64 = double(float(f27.f64 * ctx.f7.f64));
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// fmadds f3,f2,f12,f11
	ctx.f3.f64 = double(float(ctx.f2.f64 * ctx.f12.f64 + ctx.f11.f64));
	// fmadds f4,f28,f12,f11
	ctx.f4.f64 = double(float(f28.f64 * ctx.f12.f64 + ctx.f11.f64));
	// lfs f2,200(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	ctx.f2.f64 = double(temp.f32);
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// fmadds f4,f4,f30,f2
	ctx.f4.f64 = double(float(ctx.f4.f64 * f30.f64 + ctx.f2.f64));
	// mulld r8,r10,r29
	ctx.r8.s64 = ctx.r10.s64 * r29.s64;
	// lfs f2,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lfs f28,196(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	f28.f64 = double(temp.f32);
	// stw r9,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r9.u32);
	// lfd f30,144(r31)
	f30.u64 = PPC_LOAD_U64(r31.u32 + 144);
	// fmadds f3,f3,f29,f28
	ctx.f3.f64 = double(float(ctx.f3.f64 * f29.f64 + f28.f64));
	// fcfid f30,f30
	f30.f64 = double(f30.s64);
	// frsp f30,f30
	f30.f64 = double(float(f30.f64));
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r3,r11,9
	ctx.r3.u64 = r11.u32 & 0x7FFFFF;
	// clrlwi r11,r10,9
	r11.u64 = ctx.r10.u32 & 0x7FFFFF;
	// std r3,160(r31)
	PPC_STORE_U64(r31.u32 + 160, ctx.r3.u64);
	// lfd f28,160(r31)
	f28.u64 = PPC_LOAD_U64(r31.u32 + 160);
	// std r11,176(r31)
	PPC_STORE_U64(r31.u32 + 176, r11.u64);
	// lfd f27,176(r31)
	f27.u64 = PPC_LOAD_U64(r31.u32 + 176);
	// fcfid f28,f28
	f28.f64 = double(f28.s64);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// fcfid f27,f27
	f27.f64 = double(f27.s64);
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// frsp f28,f28
	f28.f64 = double(float(f28.f64));
	// addi r9,r31,192
	ctx.r9.s64 = r31.s64 + 192;
	// fmuls f1,f1,f30
	ctx.f1.f64 = double(float(ctx.f1.f64 * f30.f64));
	// lfs f29,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	f29.f64 = double(temp.f32);
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// stw r10,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r10.u32);
	// lfs f26,8(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f26.f64 = double(temp.f32);
	// cmpw cr6,r28,r23
	cr6.compare<int32_t>(r28.s32, r23.s32, xer);
	// frsp f27,f27
	f27.f64 = double(float(f27.f64));
	// fmuls f0,f0,f28
	f0.f64 = double(float(f0.f64 * f28.f64));
	// fmadds f1,f1,f12,f13
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmuls f30,f27,f6
	f30.f64 = double(float(f27.f64 * ctx.f6.f64));
	// fmadds f0,f0,f12,f13
	f0.f64 = double(float(f0.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f5,f1,f2,f5
	ctx.f5.f64 = double(float(ctx.f1.f64 * ctx.f2.f64 + ctx.f5.f64));
	// stfs f5,192(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// fmadds f30,f30,f12,f13
	f30.f64 = double(float(f30.f64 * ctx.f12.f64 + ctx.f13.f64));
	// fmadds f0,f0,f29,f3
	f0.f64 = double(float(f0.f64 * f29.f64 + ctx.f3.f64));
	// stfs f0,196(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// fmadds f4,f30,f26,f4
	ctx.f4.f64 = double(float(f30.f64 * f26.f64 + ctx.f4.f64));
	// stfs f4,200(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// lvx128 v45,r0,r9
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r0,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r26,16
	r26.s64 = r26.s64 + 16;
	// blt cr6,0x822edfb0
	if (cr6.lt) goto loc_822EDFB0;
loc_822EE1B4:
	// bl 0x8217fff8
	ctx.lr = 0x822EE1B8;
	sub_8217FFF8(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,17320(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822ee1d0
	if (!cr6.lt) goto loc_822EE1D0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_822EE1D0:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822EE1D8;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x822EE1E4;
	sub_8217F768(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x822EE1F0;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x822EE1FC;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x822EE208;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x822EE214;
	sub_8217F768(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7652(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7652);
	// bl 0x8217d9a0
	ctx.lr = 0x822EE220;
	sub_8217D9A0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,56(r24)
	ctx.r8.u64 = PPC_LOAD_U32(r24.u32 + 56);
	// lfs f13,4(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lfs f11,8(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f7,0(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f9,12(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 12);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,15360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f8,f9,f31
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64));
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f5,32(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f3,36(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// lfs f1,40(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// lwz r3,-7648(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7648);
	// fmuls f2,f3,f0
	ctx.f2.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmuls f3,f8,f0
	ctx.f3.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fctiwz f7,f12
	ctx.f7.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f7,176(r31)
	PPC_STORE_U64(r31.u32 + 176, ctx.f7.u64);
	// lwz r7,180(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// fctiwz f5,f10
	ctx.f5.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f5,176(r31)
	PPC_STORE_U64(r31.u32 + 176, ctx.f5.u64);
	// lwz r29,180(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// fctiwz f12,f4
	ctx.f12.s64 = (ctx.f4.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f12,176(r31)
	PPC_STORE_U64(r31.u32 + 176, ctx.f12.u64);
	// lfs f11,44(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// fctiwz f1,f6
	ctx.f1.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// fmuls f9,f11,f31
	ctx.f9.f64 = double(float(ctx.f11.f64 * f31.f64));
	// stfd f1,160(r31)
	PPC_STORE_U64(r31.u32 + 160, ctx.f1.u64);
	// fctiwz f11,f2
	ctx.f11.s64 = (ctx.f2.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// fctiwz f10,f13
	ctx.f10.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// fctiwz f8,f3
	ctx.f8.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// fmuls f9,f9,f0
	ctx.f9.f64 = double(float(ctx.f9.f64 * f0.f64));
	// lwz r6,180(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// stfd f11,176(r31)
	PPC_STORE_U64(r31.u32 + 176, ctx.f11.u64);
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// stfd f10,176(r31)
	PPC_STORE_U64(r31.u32 + 176, ctx.f10.u64);
	// lwz r28,180(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// stfd f8,176(r31)
	PPC_STORE_U64(r31.u32 + 176, ctx.f8.u64);
	// fctiwz f7,f9
	ctx.f7.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// stfd f7,176(r31)
	PPC_STORE_U64(r31.u32 + 176, ctx.f7.u64);
	// lwz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// rlwimi r4,r11,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft32(r11.u32, 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r9,r4,16
	ctx.r9.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwimi r7,r9,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft32(ctx.r9.u32, 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r29,r7,8,0,23
	r29.u64 = (__builtin_rotateleft32(ctx.r7.u32, 8) & 0xFFFFFF00) | (r29.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r6,r10,8,16,23
	ctx.r6.u64 = (__builtin_rotateleft32(ctx.r10.u32, 8) & 0xFF00) | (ctx.r6.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r8,r6,16
	ctx.r8.u64 = ctx.r6.u32 & 0xFFFF;
	// rlwimi r5,r8,8,0,23
	ctx.r5.u64 = (__builtin_rotateleft32(ctx.r8.u32, 8) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r28,r5,8,0,23
	r28.u64 = (__builtin_rotateleft32(ctx.r5.u32, 8) & 0xFFFFFF00) | (r28.u64 & 0xFFFFFFFF000000FF);
	// bl 0x82190870
	ctx.lr = 0x822EE300;
	sub_82190870(ctx, base);
	// addi r7,r20,1
	ctx.r7.s64 = r20.s64 + 1;
	// li r3,4
	ctx.r3.s64 = 4;
	// rlwinm r4,r7,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// bl 0x8217bb68
	ctx.lr = 0x822EE310;
	sub_8217BB68(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// blt cr6,0x822ee45c
	if (cr6.lt) goto loc_822EE45C;
	// extsw r11,r20
	r11.s64 = r20.s32;
	// vspltisw128 v44,0
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,176(r31)
	PPC_STORE_U64(r31.u32 + 176, r11.u64);
	// lfd f0,176(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 176);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f29,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f29.f64 = double(temp.f32);
	// frsp f28,f13
	f28.f64 = double(float(ctx.f13.f64));
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// vsubfp128 v127,v44,v125
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v125.f32)));
loc_822EE348:
	// extsw r11,r30
	r11.s64 = r30.s32;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// std r11,176(r31)
	PPC_STORE_U64(r31.u32 + 176, r11.u64);
	// mr r6,r19
	ctx.r6.u64 = r19.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// lfd f0,176(r31)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(r31.u32 + 176);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fdivs f30,f12,f28
	f30.f64 = double(float(ctx.f12.f64 / f28.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x822ed750
	ctx.lr = 0x822EE378;
	sub_822ED750(ctx, base);
	// lwz r11,56(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 56);
	// addi r10,r31,144
	ctx.r10.s64 = r31.s64 + 144;
	// addi r9,r31,192
	ctx.r9.s64 = r31.s64 + 192;
	// addi r11,r11,88
	r11.s64 = r11.s64 + 88;
	// addi r8,r31,160
	ctx.r8.s64 = r31.s64 + 160;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// lvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v43,v0,v0
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// lvlx128 v42,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v41,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v40,v42,0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xFF));
	// vspltw128 v39,v41,0
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xFF));
	// vmaddfp128 v43,v127,v40,v43
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v43.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v40.f32)), simde_mm_load_ps(v43.f32)));
	// vmaddfp128 v0,v125,v39,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v39.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v43,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822ee3f8
	if (cr6.eq) goto loc_822EE3F8;
	// cmpw cr6,r30,r20
	cr6.compare<int32_t>(r30.s32, r20.s32, xer);
	// beq cr6,0x822ee3f8
	if (cr6.eq) goto loc_822EE3F8;
	// lfs f0,32(r24)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 32);
	f0.f64 = double(temp.f32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// lfs f3,200(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	ctx.f3.f64 = double(temp.f32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// lfs f2,196(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f7,f30,f0
	ctx.f7.f64 = double(float(f30.f64 - f0.f64));
	// lfs f1,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x822EE3F0;
	sub_8217BC28(ctx, base);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// b 0x822ee428
	goto loc_822EE428;
loc_822EE3F8:
	// lfs f0,32(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 32);
	f0.f64 = double(temp.f32);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// lfs f3,200(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	ctx.f3.f64 = double(temp.f32);
	// fmr f8,f31
	ctx.f8.f64 = f31.f64;
	// lfs f2,196(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f7,f30,f0
	ctx.f7.f64 = double(float(f30.f64 - f0.f64));
	// lfs f1,192(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x822EE424;
	sub_8217BC28(ctx, base);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
loc_822EE428:
	// lfs f13,32(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// fmr f5,f31
	ctx.f5.f64 = f31.f64;
	// lfs f3,168(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 168);
	ctx.f3.f64 = double(temp.f32);
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// lfs f2,164(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f2.f64 = double(temp.f32);
	// fmr f8,f29
	ctx.f8.f64 = f29.f64;
	// lfs f1,160(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f7,f30,f13
	ctx.f7.f64 = double(float(f30.f64 - ctx.f13.f64));
	// fmr f4,f31
	ctx.f4.f64 = f31.f64;
	// bl 0x8217bc28
	ctx.lr = 0x822EE450;
	sub_8217BC28(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r20
	cr6.compare<int32_t>(r30.s32, r20.s32, xer);
	// ble cr6,0x822ee348
	if (!cr6.gt) goto loc_822EE348;
loc_822EE45C:
	// bl 0x8217bc98
	ctx.lr = 0x822EE460;
	sub_8217BC98(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x822EE468;
	sub_82190870(ctx, base);
loc_822EE468:
	// addi r1,r31,416
	ctx.r1.s64 = r31.s64 + 416;
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v125,r1,r0
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-192
	r0.s64 = -192;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba1c
	ctx.lr = 0x822EE48C;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822EE490"))) PPC_WEAK_FUNC(sub_822EE490);
PPC_FUNC_IMPL(__imp__sub_822EE490) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822EE498;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r26,r11,2176
	r26.s64 = r11.s64 + 2176;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,2176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2176);
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// ld r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U64(r31.u32 + 40);
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r25,4(r26)
	r25.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// rldimi r25,r10,32,0
	r25.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (r25.u64 & 0xFFFFFFFF);
	// bl 0x821ce288
	ctx.lr = 0x822EE4D8;
	sub_821CE288(ctx, base);
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822edd80
	ctx.lr = 0x822EE4F4;
	sub_822EDD80(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x821ce288
	ctx.lr = 0x822EE500;
	sub_821CE288(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822EE50C"))) PPC_WEAK_FUNC(sub_822EE50C);
PPC_FUNC_IMPL(__imp__sub_822EE50C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EE510"))) PPC_WEAK_FUNC(sub_822EE510);
PPC_FUNC_IMPL(__imp__sub_822EE510) {
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
	// lwz r3,648(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 648);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ee548
	if (cr6.eq) goto loc_822EE548;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EE548;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE548:
	// lwz r3,624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// bl 0x82177a68
	ctx.lr = 0x822EE550;
	sub_82177A68(ctx, base);
	// lwz r3,628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 628);
	// bl 0x82177a68
	ctx.lr = 0x822EE558;
	sub_82177A68(ctx, base);
	// lwz r30,84(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EE564;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ee58c
	if (!cr6.eq) goto loc_822EE58C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ee58c
	if (cr6.eq) goto loc_822EE58C;
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
	ctx.lr = 0x822EE58C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE58C:
	// lwz r30,92(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EE598;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ee5c0
	if (!cr6.eq) goto loc_822EE5C0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ee5c0
	if (cr6.eq) goto loc_822EE5C0;
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
	ctx.lr = 0x822EE5C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE5C0:
	// lwz r30,88(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EE5CC;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ee5f4
	if (!cr6.eq) goto loc_822EE5F4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ee5f4
	if (cr6.eq) goto loc_822EE5F4;
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
	ctx.lr = 0x822EE5F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE5F4:
	// lwz r30,96(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EE600;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ee628
	if (!cr6.eq) goto loc_822EE628;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ee628
	if (cr6.eq) goto loc_822EE628;
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
	ctx.lr = 0x822EE628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE628:
	// lwz r30,76(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EE634;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ee65c
	if (!cr6.eq) goto loc_822EE65C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ee65c
	if (cr6.eq) goto loc_822EE65C;
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
	ctx.lr = 0x822EE65C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE65C:
	// lwz r30,80(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EE668;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ee690
	if (!cr6.eq) goto loc_822EE690;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ee690
	if (cr6.eq) goto loc_822EE690;
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
	ctx.lr = 0x822EE690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE690:
	// lwz r30,72(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r3,r30,8
	ctx.r3.s64 = r30.s64 + 8;
	// bl 0x821ce100
	ctx.lr = 0x822EE69C;
	sub_821CE100(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822ee6c4
	if (!cr6.eq) goto loc_822EE6C4;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ee6c4
	if (cr6.eq) goto loc_822EE6C4;
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
	ctx.lr = 0x822EE6C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE6C4:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822ee6e4
	if (cr6.eq) goto loc_822EE6E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EE6E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EE6E4:
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

__attribute__((alias("__imp__sub_822EE6FC"))) PPC_WEAK_FUNC(sub_822EE6FC);
PPC_FUNC_IMPL(__imp__sub_822EE6FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EE700"))) PPC_WEAK_FUNC(sub_822EE700);
PPC_FUNC_IMPL(__imp__sub_822EE700) {
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
	ctx.lr = 0x822EE708;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lfs f13,732(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 732);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x822ee93c
	if (cr6.eq) goto loc_822EE93C;
	// lbz r11,5(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ee93c
	if (cr6.eq) goto loc_822EE93C;
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// addi r10,r31,240
	ctx.r10.s64 = r31.s64 + 240;
	// li r28,16
	r28.s64 = 16;
	// li r29,32
	r29.s64 = 32;
	// li r30,48
	r30.s64 = 48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r26,-32124
	r26.s64 = -2105278464;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lvx128 v62,r11,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r9,-31280
	ctx.r4.s64 = ctx.r9.s64 + -31280;
	// lvx128 v61,r11,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,-26876(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -26876);
	// addi r10,r10,64
	ctx.r10.s64 = ctx.r10.s64 + 64;
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
	// lwz r3,-26876(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x822EE7A4;
	sub_8217C088(ctx, base);
	// lwz r10,-26876(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + -26876);
	// addi r11,r31,304
	r11.s64 = r31.s64 + 304;
	// addi r10,r10,256
	ctx.r10.s64 = ctx.r10.s64 + 256;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r10,r28
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r10,r29
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r10,r30
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r10,21664(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 21664);
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r6,44(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// bl 0x82189ce0
	ctx.lr = 0x822EE7F0;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,76(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822EE808;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,80(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822EE820;
	sub_82189CE0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187f40
	ctx.lr = 0x822EE834;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822ee8cc
	if (cr6.eq) goto loc_822EE8CC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187b88
	ctx.lr = 0x822EE848;
	sub_82187B88(ctx, base);
	// lwz r3,628(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 628);
	// bl 0x82178430
	ctx.lr = 0x822EE850;
	sub_82178430(ctx, base);
	// lwz r4,632(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 632);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x82177bf8
	ctx.lr = 0x822EE864;
	sub_82177BF8(ctx, base);
	// lwz r4,636(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 636);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x82177bf8
	ctx.lr = 0x822EE878;
	sub_82177BF8(ctx, base);
	// lwz r4,640(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 640);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,2
	ctx.r3.s64 = 2;
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x82177bf8
	ctx.lr = 0x822EE88C;
	sub_82177BF8(ctx, base);
	// lwz r4,644(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 644);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,3
	ctx.r3.s64 = 3;
	// lwz r6,12(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// bl 0x82177bf8
	ctx.lr = 0x822EE8A0;
	sub_82177BF8(ctx, base);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x822ee8ac
	if (!cr6.eq) goto loc_822EE8AC;
	// lwz r27,656(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 656);
loc_822EE8AC:
	// rlwinm r5,r27,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x821795f8
	ctx.lr = 0x822EE8BC;
	sub_821795F8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187ba8
	ctx.lr = 0x822EE8C4;
	sub_82187BA8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187bd0
	ctx.lr = 0x822EE8CC;
	sub_82187BD0(ctx, base);
loc_822EE8CC:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822EE8E4;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822EE8FC;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822EE914;
	sub_82189CE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82177c50
	ctx.lr = 0x822EE91C;
	sub_82177C50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82177c50
	ctx.lr = 0x822EE924;
	sub_82177C50(ctx, base);
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82177c50
	ctx.lr = 0x822EE92C;
	sub_82177C50(ctx, base);
	// li r3,3
	ctx.r3.s64 = 3;
	// bl 0x82177c50
	ctx.lr = 0x822EE934;
	sub_82177C50(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178430
	ctx.lr = 0x822EE93C;
	sub_82178430(ctx, base);
loc_822EE93C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822EE944"))) PPC_WEAK_FUNC(sub_822EE944);
PPC_FUNC_IMPL(__imp__sub_822EE944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EE948"))) PPC_WEAK_FUNC(sub_822EE948);
PPC_FUNC_IMPL(__imp__sub_822EE948) {
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
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822EE99C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_822EE9BC"))) PPC_WEAK_FUNC(sub_822EE9BC);
PPC_FUNC_IMPL(__imp__sub_822EE9BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822EE9C0"))) PPC_WEAK_FUNC(sub_822EE9C0);
PPC_FUNC_IMPL(__imp__sub_822EE9C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f8
	ctx.lr = 0x822EE9C8;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r28,r11,30576
	r28.s64 = r11.s64 + 30576;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// addi r4,r8,-232
	ctx.r4.s64 = ctx.r8.s64 + -232;
	// lfs f31,31016(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	f31.f64 = double(temp.f32);
	// bl 0x821ca540
	ctx.lr = 0x822EEA00;
	sub_821CA540(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r5,r7,5276
	ctx.r5.s64 = ctx.r7.s64 + 5276;
	// addi r4,r6,-244
	ctx.r4.s64 = ctx.r6.s64 + -244;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x822EEA20;
	sub_821CA6A8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822ef0c0
	if (cr6.eq) goto loc_822EF0C0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d1cd0
	ctx.lr = 0x822EEA34;
	sub_821D1CD0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r11,-256
	ctx.r4.s64 = r11.s64 + -256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821cf7b8
	ctx.lr = 0x822EEA48;
	sub_821CF7B8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-268
	r31.s64 = r11.s64 + -268;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEA60;
	sub_821CFE80(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822eea7c
	if (cr6.eq) goto loc_822EEA7C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEA78;
	sub_821D0938(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
loc_822EEA7C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-280
	r31.s64 = r11.s64 + -280;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEA94;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eeab0
	if (cr6.eq) goto loc_822EEAB0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEAAC;
	sub_821D0938(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
loc_822EEAB0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-296
	r31.s64 = r11.s64 + -296;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEAC8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eeae4
	if (cr6.eq) goto loc_822EEAE4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEAE0;
	sub_821D0938(ctx, base);
	// stfs f1,568(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 568, temp.u32);
loc_822EEAE4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-308
	r31.s64 = r11.s64 + -308;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEAFC;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eeb18
	if (cr6.eq) goto loc_822EEB18;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEB14;
	sub_821D0938(ctx, base);
	// stfs f1,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
loc_822EEB18:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-324
	r31.s64 = r11.s64 + -324;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEB30;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eeb4c
	if (cr6.eq) goto loc_822EEB4C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEB48;
	sub_821D0938(ctx, base);
	// stfs f1,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 16, temp.u32);
loc_822EEB4C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-332
	r31.s64 = r11.s64 + -332;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEB64;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eeb80
	if (cr6.eq) goto loc_822EEB80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEB7C;
	sub_821D0938(ctx, base);
	// stfs f1,720(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 720, temp.u32);
loc_822EEB80:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-340
	r31.s64 = r11.s64 + -340;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEB98;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eebb4
	if (cr6.eq) goto loc_822EEBB4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEBB0;
	sub_821D0938(ctx, base);
	// stfs f1,724(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 724, temp.u32);
loc_822EEBB4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-348
	r31.s64 = r11.s64 + -348;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEBCC;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eebe8
	if (cr6.eq) goto loc_822EEBE8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEBE4;
	sub_821D0938(ctx, base);
	// stfs f1,728(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 728, temp.u32);
loc_822EEBE8:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-368
	r31.s64 = r11.s64 + -368;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEC00;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eec1c
	if (cr6.eq) goto loc_822EEC1C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEC18;
	sub_821D0938(ctx, base);
	// stfs f1,736(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 736, temp.u32);
loc_822EEC1C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-388
	r31.s64 = r11.s64 + -388;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEC34;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eec50
	if (cr6.eq) goto loc_822EEC50;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEC4C;
	sub_821D0938(ctx, base);
	// stfs f1,740(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 740, temp.u32);
loc_822EEC50:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-408
	r31.s64 = r11.s64 + -408;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEC68;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eec84
	if (cr6.eq) goto loc_822EEC84;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEC80;
	sub_821D0938(ctx, base);
	// stfs f1,744(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 744, temp.u32);
loc_822EEC84:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-424
	r31.s64 = r11.s64 + -424;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEC9C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eecb8
	if (cr6.eq) goto loc_822EECB8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EECB4;
	sub_821D0938(ctx, base);
	// stfs f1,596(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 596, temp.u32);
loc_822EECB8:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-440
	r31.s64 = r11.s64 + -440;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EECD0;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eecec
	if (cr6.eq) goto loc_822EECEC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EECE8;
	sub_821D0938(ctx, base);
	// stfs f1,564(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 564, temp.u32);
loc_822EECEC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-456
	r31.s64 = r11.s64 + -456;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EED04;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eed20
	if (cr6.eq) goto loc_822EED20;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EED1C;
	sub_821D0938(ctx, base);
	// stfs f1,600(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 600, temp.u32);
loc_822EED20:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-472
	r31.s64 = r11.s64 + -472;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EED38;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eed54
	if (cr6.eq) goto loc_822EED54;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EED50;
	sub_821D0938(ctx, base);
	// stfs f1,604(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 604, temp.u32);
loc_822EED54:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-492
	r31.s64 = r11.s64 + -492;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EED6C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eed88
	if (cr6.eq) goto loc_822EED88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EED84;
	sub_821D0938(ctx, base);
	// stfs f1,684(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 684, temp.u32);
loc_822EED88:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-504
	r31.s64 = r11.s64 + -504;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEDA0;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eedbc
	if (cr6.eq) goto loc_822EEDBC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEDB8;
	sub_821D0938(ctx, base);
	// stfs f1,672(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 672, temp.u32);
loc_822EEDBC:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-516
	r31.s64 = r11.s64 + -516;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEDD4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eedf0
	if (cr6.eq) goto loc_822EEDF0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEDEC;
	sub_821D0938(ctx, base);
	// stfs f1,676(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 676, temp.u32);
loc_822EEDF0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-528
	r31.s64 = r11.s64 + -528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEE08;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eee24
	if (cr6.eq) goto loc_822EEE24;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEE20;
	sub_821D0938(ctx, base);
	// stfs f1,680(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 680, temp.u32);
loc_822EEE24:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-548
	r31.s64 = r11.s64 + -548;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEE3C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eee58
	if (cr6.eq) goto loc_822EEE58;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEE54;
	sub_821D0938(ctx, base);
	// stfs f1,688(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 688, temp.u32);
loc_822EEE58:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-568
	r31.s64 = r11.s64 + -568;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEE70;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eee8c
	if (cr6.eq) goto loc_822EEE8C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEE88;
	sub_821D0938(ctx, base);
	// stfs f1,692(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 692, temp.u32);
loc_822EEE8C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-588
	r31.s64 = r11.s64 + -588;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEEA4;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eeec0
	if (cr6.eq) goto loc_822EEEC0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEEBC;
	sub_821D0938(ctx, base);
	// stfs f1,696(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 696, temp.u32);
loc_822EEEC0:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-608
	r31.s64 = r11.s64 + -608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEED8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eeef4
	if (cr6.eq) goto loc_822EEEF4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEEF0;
	sub_821D0938(ctx, base);
	// stfs f1,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 12, temp.u32);
loc_822EEEF4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-628
	r31.s64 = r11.s64 + -628;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEF0C;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eef28
	if (cr6.eq) goto loc_822EEF28;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEF24;
	sub_821D0938(ctx, base);
	// stfs f1,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 20, temp.u32);
loc_822EEF28:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-644
	r31.s64 = r11.s64 + -644;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEF40;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eef5c
	if (cr6.eq) goto loc_822EEF5C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEF58;
	sub_821D0938(ctx, base);
	// stfs f1,592(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 592, temp.u32);
loc_822EEF5C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-660
	r31.s64 = r11.s64 + -660;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEF74;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eef90
	if (cr6.eq) goto loc_822EEF90;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEF8C;
	sub_821D0938(ctx, base);
	// stfs f1,608(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 608, temp.u32);
loc_822EEF90:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-680
	r31.s64 = r11.s64 + -680;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEFA8;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eefc4
	if (cr6.eq) goto loc_822EEFC4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEFC0;
	sub_821D0938(ctx, base);
	// stfs f1,612(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 612, temp.u32);
loc_822EEFC4:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-696
	r31.s64 = r11.s64 + -696;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EEFDC;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822eeff8
	if (cr6.eq) goto loc_822EEFF8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EEFF4;
	sub_821D0938(ctx, base);
	// stfs f1,616(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 616, temp.u32);
loc_822EEFF8:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-716
	r31.s64 = r11.s64 + -716;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EF010;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ef02c
	if (cr6.eq) goto loc_822EF02C;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EF028;
	sub_821D0938(ctx, base);
	// stfs f1,528(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 528, temp.u32);
loc_822EF02C:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-736
	r31.s64 = r11.s64 + -736;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EF044;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ef060
	if (cr6.eq) goto loc_822EF060;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EF05C;
	sub_821D0938(ctx, base);
	// stfs f1,532(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 532, temp.u32);
loc_822EF060:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-756
	r31.s64 = r11.s64 + -756;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821cfe80
	ctx.lr = 0x822EF078;
	sub_821CFE80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ef094
	if (cr6.eq) goto loc_822EF094;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d0938
	ctx.lr = 0x822EF090;
	sub_821D0938(ctx, base);
	// stfs f1,536(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r30.u32 + 536, temp.u32);
loc_822EF094:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821be610
	ctx.lr = 0x822EF09C;
	sub_821BE610(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r10,-30140
	ctx.r9.s64 = ctx.r10.s64 + -30140;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// stfs f30,76(r7)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r7.u32 + 76, temp.u32);
	// stfs f31,80(r7)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 80, temp.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
loc_822EF0C0:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822EF0C8;
	sub_821C9A90(ctx, base);
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822EF0D8"))) PPC_WEAK_FUNC(sub_822EF0D8);
PPC_FUNC_IMPL(__imp__sub_822EF0D8) {
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
	PPCRegister f24{};
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
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
	// bl 0x823d91ec
	ctx.lr = 0x822EF0E0;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9c8
	ctx.lr = 0x822EF0E8;
	// stwu r1,-784(r1)
	ea = -784 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32124
	r11.s64 = -2105278464;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r29,r10,488
	r29.s64 = ctx.r10.s64 + 488;
	// lwz r3,-24728(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24728);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822EF120;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EF158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,472
	ctx.r4.s64 = ctx.r10.s64 + 472;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822EF170;
	sub_8218B688(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,456
	ctx.r4.s64 = ctx.r8.s64 + 456;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218b688
	ctx.lr = 0x822EF18C;
	sub_8218B688(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,440
	ctx.r4.s64 = ctx.r4.s64 + 440;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF1A8;
	sub_8218A568(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r3,424
	ctx.r4.s64 = ctx.r3.s64 + 424;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF1C4;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,408
	ctx.r4.s64 = ctx.r9.s64 + 408;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF1E0;
	sub_8218A568(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,392
	ctx.r4.s64 = ctx.r8.s64 + 392;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF1FC;
	sub_8218A568(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,372
	ctx.r4.s64 = ctx.r4.s64 + 372;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF218;
	sub_8218A568(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r3,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r3.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,360
	ctx.r4.s64 = r11.s64 + 360;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF234;
	sub_8218A568(ctx, base);
	// stw r3,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r3.u32);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,344
	ctx.r4.s64 = ctx.r9.s64 + 344;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF250;
	sub_8218A568(ctx, base);
	// stw r3,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r3.u32);
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,324
	ctx.r4.s64 = ctx.r6.s64 + 324;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF26C;
	sub_8218A568(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,308
	ctx.r4.s64 = ctx.r4.s64 + 308;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF288;
	sub_8218A568(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,296
	ctx.r4.s64 = ctx.r10.s64 + 296;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF2A4;
	sub_8218A568(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,284
	ctx.r4.s64 = ctx.r9.s64 + 284;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF2C0;
	sub_8218A568(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,264
	ctx.r4.s64 = ctx.r6.s64 + 264;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF2DC;
	sub_8218A568(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,248
	ctx.r4.s64 = ctx.r4.s64 + 248;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF2F8;
	sub_8218A568(ctx, base);
	// stw r3,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r3.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,224
	ctx.r4.s64 = ctx.r10.s64 + 224;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF314;
	sub_8218A568(ctx, base);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,200
	ctx.r4.s64 = ctx.r9.s64 + 200;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF330;
	sub_8218A568(ctx, base);
	// stw r3,120(r31)
	PPC_STORE_U32(r31.u32 + 120, ctx.r3.u32);
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,180
	ctx.r4.s64 = ctx.r6.s64 + 180;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF34C;
	sub_8218A568(ctx, base);
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,152
	ctx.r4.s64 = ctx.r4.s64 + 152;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF368;
	sub_8218A568(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r3,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r10,132
	ctx.r4.s64 = ctx.r10.s64 + 132;
	// bl 0x8218a568
	ctx.lr = 0x822EF384;
	sub_8218A568(ctx, base);
	// stw r3,164(r31)
	PPC_STORE_U32(r31.u32 + 164, ctx.r3.u32);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,120
	ctx.r4.s64 = ctx.r8.s64 + 120;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF3A0;
	sub_8218A568(ctx, base);
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,104
	ctx.r4.s64 = ctx.r6.s64 + 104;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF3BC;
	sub_8218A568(ctx, base);
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,84
	ctx.r4.s64 = ctx.r4.s64 + 84;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF3D8;
	sub_8218A568(ctx, base);
	// stw r3,152(r31)
	PPC_STORE_U32(r31.u32 + 152, ctx.r3.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,68
	ctx.r4.s64 = ctx.r10.s64 + 68;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF3F4;
	sub_8218A568(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,52
	ctx.r4.s64 = ctx.r9.s64 + 52;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF410;
	sub_8218A568(ctx, base);
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,36
	ctx.r4.s64 = ctx.r6.s64 + 36;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF42C;
	sub_8218A568(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,24
	ctx.r4.s64 = ctx.r4.s64 + 24;
	// lwz r3,20(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF448;
	sub_8218A568(ctx, base);
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,4
	ctx.r4.s64 = ctx.r10.s64 + 4;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF464;
	sub_8218A568(ctx, base);
	// stw r3,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r3.u32);
	// lwz r8,24(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-12
	ctx.r4.s64 = ctx.r9.s64 + -12;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x822EF480;
	sub_8218A568(ctx, base);
	// srawi r7,r28,7
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x7F) != 0);
	ctx.r7.s64 = r28.s32 >> 7;
	// stw r3,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r3.u32);
	// li r5,128
	ctx.r5.s64 = 128;
	// stw r28,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r28.u32);
	// addze r6,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r6.s64 = temp.s64;
	// stw r5,660(r31)
	PPC_STORE_U32(r31.u32 + 660, ctx.r5.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r6,664(r31)
	PPC_STORE_U32(r31.u32 + 664, ctx.r6.u32);
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x82180430
	ctx.lr = 0x822EF4A8;
	sub_82180430(ctx, base);
	// lis r29,-32124
	r29.s64 = -2105278464;
	// li r27,1
	r27.s64 = 1;
	// stb r30,450(r1)
	PPC_STORE_U8(ctx.r1.u32 + 450, r30.u8);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// stb r27,432(r1)
	PPC_STORE_U8(ctx.r1.u32 + 432, r27.u8);
	// li r11,17
	r11.s64 = 17;
	// stw r30,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, r30.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stw r30,436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 436, r30.u32);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// stw r11,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, r11.u32);
	// addi r4,r10,-28
	ctx.r4.s64 = ctx.r10.s64 + -28;
	// stb r30,449(r1)
	PPC_STORE_U8(ctx.r1.u32 + 449, r30.u8);
	// li r8,64
	ctx.r8.s64 = 64;
	// lwz r7,664(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r6,660(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EF4FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,664(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// addi r4,r8,-44
	ctx.r4.s64 = ctx.r8.s64 + -44;
	// lwz r6,660(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// li r8,64
	ctx.r8.s64 = 64;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// li r5,3
	ctx.r5.s64 = 3;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EF530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// addi r4,r10,-60
	ctx.r4.s64 = ctx.r10.s64 + -60;
	// lwz r7,664(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// lwz r6,660(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// li r8,64
	ctx.r8.s64 = 64;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EF564;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,664(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// addi r4,r8,-76
	ctx.r4.s64 = ctx.r8.s64 + -76;
	// lwz r6,660(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// li r8,64
	ctx.r8.s64 = 64;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	// li r5,3
	ctx.r5.s64 = 3;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EF598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r26,r10,30576
	r26.s64 = ctx.r10.s64 + 30576;
	// addi r4,r9,-96
	ctx.r4.s64 = ctx.r9.s64 + -96;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821ca540
	ctx.lr = 0x822EF5B4;
	sub_821CA540(ctx, base);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-104
	ctx.r4.s64 = ctx.r8.s64 + -104;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,12(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822EF5D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
	// lwz r3,-25232(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-116
	ctx.r4.s64 = ctx.r4.s64 + -116;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EF5F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822EF604;
	sub_821C9A90(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,128
	ctx.r4.s64 = 128;
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x8218de38
	ctx.lr = 0x822EF628;
	sub_8218DE38(ctx, base);
	// stw r30,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r30.u32);
	// stw r30,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, r30.u32);
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// lwz r11,-25232(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -25232);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, r30.u32);
	// stw r30,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822EF65C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822ef688
	if (cr6.eq) goto loc_822EF688;
	// lwz r11,32(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,32(r29)
	PPC_STORE_U32(r29.u32 + 32, r11.u32);
	// bne 0x822ef688
	if (!cr0.eq) goto loc_822EF688;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8218cd10
	ctx.lr = 0x822EF680;
	sub_8218CD10(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x822EF688;
	sub_82130588(ctx, base);
loc_822EF688:
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x822ee948
	ctx.lr = 0x822EF694;
	sub_822EE948(ctx, base);
loc_822EF694:
	// lwz r11,232(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// lwz r10,208(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x822ef6dc
	if (cr6.lt) goto loc_822EF6DC;
	// lwz r11,236(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// lwz r9,228(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// lwz r10,200(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r8,212(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// add r7,r10,r9
	ctx.r7.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stw r11,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, r11.u32);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// stw r30,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r30.u32);
	// stw r7,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r7.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bge cr6,0x822ef6e0
	if (!cr6.lt) goto loc_822EF6E0;
loc_822EF6DC:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822EF6E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ef744
	if (cr6.eq) goto loc_822EF744;
	// bl 0x823df0a0
	ctx.lr = 0x822EF6F0;
	sub_823DF0A0(ctx, base);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// bl 0x823df0a0
	ctx.lr = 0x822EF6F8;
	sub_823DF0A0(ctx, base);
	// clrlwi r26,r3,24
	r26.u64 = ctx.r3.u32 & 0xFF;
	// bl 0x823df0a0
	ctx.lr = 0x822EF700;
	sub_823DF0A0(ctx, base);
	// clrlwi r25,r3,24
	r25.u64 = ctx.r3.u32 & 0xFF;
	// bl 0x823df0a0
	ctx.lr = 0x822EF708;
	sub_823DF0A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// rlwinm r10,r29,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 8) & 0xFF00;
	// lwz r9,204(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 204);
	// lwz r8,232(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// or r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 | r11.u64;
	// lwz r6,228(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	// srawi r5,r9,3
	xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r5.s64 = ctx.r9.s32 >> 3;
	// rlwinm r4,r7,8,0,23
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 8) & 0xFFFFFF00;
	// addze r3,r5
	temp.s64 = ctx.r5.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r3.s64 = temp.s64;
	// or r11,r4,r25
	r11.u64 = ctx.r4.u64 | r25.u64;
	// mullw r10,r3,r8
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// rlwinm r9,r11,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFFFFFF00;
	// or r8,r9,r26
	ctx.r8.u64 = ctx.r9.u64 | r26.u64;
	// stwx r8,r10,r6
	PPC_STORE_U32(ctx.r10.u32 + ctx.r6.u32, ctx.r8.u32);
	// b 0x822ef694
	goto loc_822EF694;
loc_822EF744:
	// lwz r3,224(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EF75C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x8218fe20
	ctx.lr = 0x822EF764;
	sub_8218FE20(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82190640
	ctx.lr = 0x822EF778;
	sub_82190640(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821902b0
	ctx.lr = 0x822EF78C;
	sub_821902B0(ctx, base);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r6,r1,480
	ctx.r6.s64 = ctx.r1.s64 + 480;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822EF7AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r6,484(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 484);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821b4838
	ctx.lr = 0x822EF7C0;
	sub_821B4838(ctx, base);
	// lwz r7,84(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stw r3,632(r31)
	PPC_STORE_U32(r31.u32 + 632, ctx.r3.u32);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r5,116(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 116);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822EF7DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r6,r1,480
	ctx.r6.s64 = ctx.r1.s64 + 480;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EF7FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r6,484(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 484);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821b4838
	ctx.lr = 0x822EF810;
	sub_821B4838(ctx, base);
	// lwz r9,92(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// stw r3,640(r31)
	PPC_STORE_U32(r31.u32 + 640, ctx.r3.u32);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,116(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 116);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822EF82C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r6,r1,480
	ctx.r6.s64 = ctx.r1.s64 + 480;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EF84C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r6,484(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 484);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821b4838
	ctx.lr = 0x822EF860;
	sub_821B4838(ctx, base);
	// stw r3,636(r31)
	PPC_STORE_U32(r31.u32 + 636, ctx.r3.u32);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,116(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822EF878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r6,r1,480
	ctx.r6.s64 = ctx.r1.s64 + 480;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,76(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EF898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r6,484(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 484);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821b4838
	ctx.lr = 0x822EF8AC;
	sub_821B4838(ctx, base);
	// lwz r10,92(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// stw r3,644(r31)
	PPC_STORE_U32(r31.u32 + 644, ctx.r3.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r8,116(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822EF8C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// lfs f24,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f24.f64 = double(temp.f32);
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f24,528(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// stfs f0,532(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// stfs f31,536(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// stfs f31,540(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// stfs f0,544(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// stfs f0,548(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// stfs f0,552(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// stfs f31,556(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 556, temp.u32);
	// stfs f0,560(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// stfs f24,564(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// stfs f0,568(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// stfs f0,572(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// stfs f24,576(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// stfs f24,580(r1)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// stfs f31,584(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 584, temp.u32);
	// stfs f0,588(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 588, temp.u32);
	// bl 0x8218fe20
	ctx.lr = 0x822EF928;
	sub_8218FE20(ctx, base);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// bl 0x82190640
	ctx.lr = 0x822EF93C;
	sub_82190640(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,512
	ctx.r3.s64 = ctx.r1.s64 + 512;
	// bl 0x821902b0
	ctx.lr = 0x822EF950;
	sub_821902B0(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,512
	ctx.r4.s64 = ctx.r1.s64 + 512;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x821b4838
	ctx.lr = 0x822EF964;
	sub_821B4838(ctx, base);
	// stw r3,648(r31)
	PPC_STORE_U32(r31.u32 + 648, ctx.r3.u32);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822EF978;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,648(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 648);
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822ef990
	if (cr6.eq) goto loc_822EF990;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// b 0x822ef994
	goto loc_822EF994;
loc_822EF990:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822EF994:
	// addi r4,r1,528
	ctx.r4.s64 = ctx.r1.s64 + 528;
	// li r5,64
	ctx.r5.s64 = 64;
	// bl 0x823da950
	ctx.lr = 0x822EF9A0;
	sub_823DA950(ctx, base);
	// lwz r3,648(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 648);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EF9B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r29,5
	r29.s64 = 5;
	// stw r30,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, r30.u32);
	// addi r28,r9,-16224
	r28.s64 = ctx.r9.s64 + -16224;
	// stw r30,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, r30.u32);
	// stw r30,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r30.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r29,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r29.u32);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// stw r30,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, r30.u32);
	// sth r30,280(r1)
	PPC_STORE_U16(ctx.r1.u32 + 280, r30.u16);
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// stw r30,284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 284, r30.u32);
	// stw r29,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r29.u32);
	// stw r30,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, r30.u32);
	// stw r29,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, r29.u32);
	// stw r30,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, r30.u32);
	// sth r30,308(r1)
	PPC_STORE_U16(ctx.r1.u32 + 308, r30.u16);
	// stw r11,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, r11.u32);
	// stw r11,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r11.u32);
	// bl 0x8217aac0
	ctx.lr = 0x822EFA08;
	sub_8217AAC0(ctx, base);
	// stw r3,624(r31)
	PPC_STORE_U32(r31.u32 + 624, ctx.r3.u32);
	// li r11,2
	r11.s64 = 2;
	// stw r30,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, r30.u32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r29,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, r29.u32);
	// stw r11,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, r11.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// stw r11,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, r11.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stw r30,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, r30.u32);
	// stw r29,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r29.u32);
	// stw r30,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, r30.u32);
	// sth r30,344(r1)
	PPC_STORE_U16(ctx.r1.u32 + 344, r30.u16);
	// stw r27,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, r27.u32);
	// stw r29,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r29.u32);
	// stw r27,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r27.u32);
	// stw r29,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, r29.u32);
	// stw r30,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, r30.u32);
	// sth r30,372(r1)
	PPC_STORE_U16(ctx.r1.u32 + 372, r30.u16);
	// stw r29,380(r1)
	PPC_STORE_U32(ctx.r1.u32 + 380, r29.u32);
	// stw r29,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, r29.u32);
	// stw r30,396(r1)
	PPC_STORE_U32(ctx.r1.u32 + 396, r30.u32);
	// sth r30,400(r1)
	PPC_STORE_U16(ctx.r1.u32 + 400, r30.u16);
	// stw r10,404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 404, ctx.r10.u32);
	// lwz r11,20(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// stw r30,652(r31)
	PPC_STORE_U32(r31.u32 + 652, r30.u32);
	// stw r29,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, r29.u32);
	// stw r10,412(r1)
	PPC_STORE_U32(ctx.r1.u32 + 412, ctx.r10.u32);
	// stw r29,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, r29.u32);
	// stw r11,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, r11.u32);
	// stw r11,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, r11.u32);
	// stw r11,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, r11.u32);
	// stw r11,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, r11.u32);
	// stw r30,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, r30.u32);
	// sth r30,428(r1)
	PPC_STORE_U16(ctx.r1.u32 + 428, r30.u16);
	// bl 0x8217aac0
	ctx.lr = 0x822EFA98;
	sub_8217AAC0(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// stw r3,628(r31)
	PPC_STORE_U32(r31.u32 + 628, ctx.r3.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// li r8,32
	ctx.r8.s64 = 32;
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r10,r31,240
	ctx.r10.s64 = r31.s64 + 240;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r30.u32);
	// stvx128 v59,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,528
	r28.s64 = ctx.r1.s64 + 528;
	// stvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r30.u32);
	// stvx128 v57,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r29,r30
	r29.u64 = r30.u64;
	// stvx128 v56,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,92(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stw r6,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r6.u32);
	// lwz r7,88(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// stw r8,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r8.u32);
	// stw r5,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, ctx.r5.u32);
	// stw r7,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r7.u32);
loc_822EFB28:
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// lwzx r3,r29,r11
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822efb60
	if (cr6.eq) goto loc_822EFB60;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EFB54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,532(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stwx r8,r29,r9
	PPC_STORE_U32(r29.u32 + ctx.r9.u32, ctx.r8.u32);
loc_822EFB60:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r28,r28,32
	r28.s64 = r28.s64 + 32;
	// cmpwi cr6,r29,16
	cr6.compare<int32_t>(r29.s32, 16, xer);
	// blt cr6,0x822efb28
	if (cr6.lt) goto loc_822EFB28;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r25,100(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// lfs f29,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f29.f64 = double(temp.f32);
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// beq cr6,0x822efcd4
	if (cr6.eq) goto loc_822EFCD4;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822efe18
	if (!cr6.gt) goto loc_822EFE18;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r26,108(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r27,104(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r29,96(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f25,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f25.f64 = double(temp.f32);
	// lfs f26,-120(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -120);
	f26.f64 = double(temp.f32);
	// lfs f27,-10992(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -10992);
	f27.f64 = double(temp.f32);
	// lfs f30,-124(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -124);
	f30.f64 = double(temp.f32);
	// lfs f28,-128(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -128);
	f28.f64 = double(temp.f32);
loc_822EFBC4:
	// bl 0x823df0a0
	ctx.lr = 0x822EFBC8;
	sub_823DF0A0(ctx, base);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// std r11,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, r11.u64);
	// lfd f0,136(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f28
	ctx.f11.f64 = double(float(ctx.f12.f64 * f28.f64));
	// stfs f11,0(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFBEC;
	sub_823DF0A0(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r10,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// lfd f10,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmsubs f7,f8,f30,f27
	ctx.f7.f64 = double(float(ctx.f8.f64 * f30.f64 - f27.f64));
	// stfs f7,0(r29)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFC10;
	sub_823DF0A0(ctx, base);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// addi r28,r25,4
	r28.s64 = r25.s64 + 4;
	// std r9,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r9.u64);
	// lfd f6,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f28
	ctx.f3.f64 = double(float(ctx.f4.f64 * f28.f64));
	// stfs f3,0(r25)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r25.u32 + 0, temp.u32);
	// bl 0x823df0a0
	ctx.lr = 0x822EFC34;
	sub_823DF0A0(ctx, base);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f2,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// fmuls f13,f0,f26
	ctx.f13.f64 = double(float(f0.f64 * f26.f64));
	// stfs f13,4(r25)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r25.u32 + 4, temp.u32);
	// addi r25,r28,4
	r25.s64 = r28.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFC58;
	sub_823DF0A0(ctx, base);
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// addi r28,r27,4
	r28.s64 = r27.s64 + 4;
	// std r7,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r7.u64);
	// lfd f12,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmsubs f9,f10,f30,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 * f30.f64 - f29.f64));
	// stfs f9,0(r27)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// bl 0x823df0a0
	ctx.lr = 0x822EFC7C;
	sub_823DF0A0(ctx, base);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// std r6,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r6.u64);
	// lfd f8,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmadds f5,f6,f30,f25
	ctx.f5.f64 = double(float(ctx.f6.f64 * f30.f64 + f25.f64));
	// stfs f5,4(r27)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r27.u32 + 4, temp.u32);
	// addi r27,r28,4
	r27.s64 = r28.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFCA0;
	sub_823DF0A0(ctx, base);
	// extsw r5,r3
	ctx.r5.s64 = ctx.r3.s32;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// std r5,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r5.u64);
	// lfd f4,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmsubs f1,f2,f30,f29
	ctx.f1.f64 = double(float(ctx.f2.f64 * f30.f64 - f29.f64));
	// stfs f1,0(r26)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r26.u32 + 0, temp.u32);
	// lwz r4,656(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// addi r26,r26,8
	r26.s64 = r26.s64 + 8;
	// cmpw cr6,r30,r4
	cr6.compare<int32_t>(r30.s32, ctx.r4.s32, xer);
	// blt cr6,0x822efbc4
	if (cr6.lt) goto loc_822EFBC4;
	// b 0x822efe18
	goto loc_822EFE18;
loc_822EFCD4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822efe18
	if (!cr6.gt) goto loc_822EFE18;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r28,104(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r29,96(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f25,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f25.f64 = double(temp.f32);
	// lfs f26,-120(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -120);
	f26.f64 = double(temp.f32);
	// lfs f27,-10992(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -10992);
	f27.f64 = double(temp.f32);
	// lfs f30,-124(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -124);
	f30.f64 = double(temp.f32);
	// lfs f28,-128(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -128);
	f28.f64 = double(temp.f32);
loc_822EFD0C:
	// bl 0x823df0a0
	ctx.lr = 0x822EFD10;
	sub_823DF0A0(ctx, base);
	// extsw r11,r3
	r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f28
	ctx.f11.f64 = double(float(ctx.f12.f64 * f28.f64));
	// stfs f11,0(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFD34;
	sub_823DF0A0(ctx, base);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// std r10,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lfd f10,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmsubs f7,f8,f30,f27
	ctx.f7.f64 = double(float(ctx.f8.f64 * f30.f64 - f27.f64));
	// stfs f7,0(r29)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFD58;
	sub_823DF0A0(ctx, base);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// std r9,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r9.u64);
	// lfd f6,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fmuls f3,f4,f28
	ctx.f3.f64 = double(float(ctx.f4.f64 * f28.f64));
	// stfs f3,0(r29)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFD7C;
	sub_823DF0A0(ctx, base);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// std r8,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfd f2,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// fmuls f13,f0,f26
	ctx.f13.f64 = double(float(f0.f64 * f26.f64));
	// stfs f13,0(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFDA0;
	sub_823DF0A0(ctx, base);
	// extsw r7,r3
	ctx.r7.s64 = ctx.r3.s32;
	// std r7,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, ctx.r7.u64);
	// lfd f12,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmsubs f9,f10,f30,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 * f30.f64 - f29.f64));
	// stfs f9,0(r28)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFDC4;
	sub_823DF0A0(ctx, base);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// std r6,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// lfd f8,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fmadds f5,f6,f30,f25
	ctx.f5.f64 = double(float(ctx.f6.f64 * f30.f64 + f25.f64));
	// stfs f5,0(r28)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// bl 0x823df0a0
	ctx.lr = 0x822EFDE8;
	sub_823DF0A0(ctx, base);
	// extsw r5,r3
	ctx.r5.s64 = ctx.r3.s32;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// lfd f4,136(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmsubs f1,f2,f30,f29
	ctx.f1.f64 = double(float(ctx.f2.f64 * f30.f64 - f29.f64));
	// stfs f1,0(r28)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r28.u32 + 0, temp.u32);
	// lwz r4,656(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmpw cr6,r30,r4
	cr6.compare<int32_t>(r30.s32, ctx.r4.s32, xer);
	// blt cr6,0x822efd0c
	if (cr6.lt) goto loc_822EFD0C;
loc_822EFE18:
	// addi r29,r1,176
	r29.s64 = ctx.r1.s64 + 176;
	// addi r30,r1,528
	r30.s64 = ctx.r1.s64 + 528;
	// li r28,4
	r28.s64 = 4;
loc_822EFE24:
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822efe44
	if (cr6.eq) goto loc_822EFE44;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822EFE44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822EFE44:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,32
	r30.s64 = r30.s64 + 32;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822efe24
	if (!cr0.eq) goto loc_822EFE24;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stfs f31,564(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 564, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f31,720(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 720, temp.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stfs f31,728(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 728, temp.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stfs f24,732(r31)
	temp.f32 = float(f24.f64);
	PPC_STORE_U32(r31.u32 + 732, temp.u32);
	// addi r7,r11,-144
	ctx.r7.s64 = r11.s64 + -144;
	// stfs f31,576(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 576, temp.u32);
	// addi r5,r10,-160
	ctx.r5.s64 = ctx.r10.s64 + -160;
	// stfs f31,584(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// addi r4,r9,-176
	ctx.r4.s64 = ctx.r9.s64 + -176;
	// stfs f29,596(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// addi r11,r8,-192
	r11.s64 = ctx.r8.s64 + -192;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r0,r4
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f12,-332(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -332);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lfs f0,31308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f11,-208(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -208);
	ctx.f11.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r4,672
	ctx.r4.s64 = 672;
	// lfs f13,17032(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// li r11,688
	r11.s64 = 688;
	// lfs f10,-212(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -212);
	ctx.f10.f64 = double(temp.f32);
	// li r10,704
	ctx.r10.s64 = 704;
	// lfs f9,25088(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 25088);
	ctx.f9.f64 = double(temp.f32);
	// li r9,736
	ctx.r9.s64 = 736;
	// lfs f8,-216(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -216);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,31288(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31288);
	ctx.f7.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f12,560(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 560, temp.u32);
	// stfs f13,568(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 568, temp.u32);
	// stfs f0,572(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 572, temp.u32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
	// stfs f11,724(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 724, temp.u32);
	// stfs f10,580(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// stfs f9,588(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// stfs f13,592(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 592, temp.u32);
	// stfs f8,600(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// stfs f7,604(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 604, temp.u32);
	// stvx128 v55,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,608(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 608, temp.u32);
	// stfs f31,612(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 612, temp.u32);
	// stfs f31,616(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 616, temp.u32);
	// stfs f31,620(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 620, temp.u32);
	// stfs f31,528(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// stfs f31,532(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// stfs f31,536(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// stfs f31,540(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 540, temp.u32);
	// bl 0x822ee9c0
	ctx.lr = 0x822EFF5C;
	sub_822EE9C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba14
	ctx.lr = 0x822EFF6C;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822EFF70"))) PPC_WEAK_FUNC(sub_822EFF70);
PPC_FUNC_IMPL(__imp__sub_822EFF70) {
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
	// bl 0x823d91e4
	ctx.lr = 0x822EFF78;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// li r25,1
	r25.s64 = 1;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822effb0
	if (cr6.eq) goto loc_822EFFB0;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r25
	r11.u64 = r25.u64;
	// beq cr6,0x822effb4
	if (cr6.eq) goto loc_822EFFB4;
loc_822EFFB0:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822EFFB4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f08f0
	if (!cr6.eq) goto loc_822F08F0;
	// lbz r11,6(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f08f0
	if (cr6.eq) goto loc_822F08F0;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// lbzx r11,r28,r29
	r11.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822effec
	if (cr6.eq) goto loc_822EFFEC;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// b 0x822efff4
	goto loc_822EFFF4;
loc_822EFFEC:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
loc_822EFFF4:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,596(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r10,6928
	r11.s64 = ctx.r10.s64 + 6928;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f31,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfsx f13,r9,r7
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27640(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27640);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822f0044
	if (!cr6.gt) goto loc_822F0044;
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fsubs f11,f31,f0
	ctx.f11.f64 = double(float(f31.f64 - f0.f64));
	// lfs f0,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	f0.f64 = double(temp.f32);
	// fdivs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// fsubs f9,f31,f10
	ctx.f9.f64 = double(float(f31.f64 - ctx.f10.f64));
	// fmuls f0,f9,f0
	f0.f64 = double(float(ctx.f9.f64 * f0.f64));
	// b 0x822f0048
	goto loc_822F0048;
loc_822F0044:
	// fmr f0,f12
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f12.f64;
loc_822F0048:
	// stfs f0,732(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 732, temp.u32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// beq cr6,0x822f08f0
	if (cr6.eq) goto loc_822F08F0;
	// lis r26,-32120
	r26.s64 = -2105016320;
	// lwz r3,-7572(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// bl 0x82205248
	ctx.lr = 0x822F0060;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// addi r30,r31,560
	r30.s64 = r31.s64 + 560;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f007c
	if (cr6.eq) goto loc_822F007C;
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822f0084
	goto loc_822F0084;
loc_822F007C:
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
loc_822F0084:
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// stfs f13,560(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 560, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,572(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 572, temp.u32);
	// lbzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32121
	r11.s64 = -2105081856;
	// vxor128 v63,v63,v63
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_setzero_si128());
	// addi r11,r11,17268
	r11.s64 = r11.s64 + 17268;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x822f00cc
	if (cr6.eq) goto loc_822F00CC;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822f00e8
	if (!cr6.gt) goto loc_822F00E8;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x822f00dc
	goto loc_822F00DC;
loc_822F00CC:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822f00e8
	if (!cr6.gt) goto loc_822F00E8;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_822F00DC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r25
	r11.u64 = r25.u64;
	// bne cr6,0x822f00ec
	if (!cr6.eq) goto loc_822F00EC;
loc_822F00E8:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822F00EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0138
	if (cr6.eq) goto loc_822F0138;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3998
	ctx.lr = 0x822F0100;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0138
	if (cr6.eq) goto loc_822F0138;
	// lbzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822f0120
	if (cr6.eq) goto loc_822F0120;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822f0128
	goto loc_822F0128;
loc_822F0120:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822F0128:
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r11,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822F0138:
	// li r11,8
	r11.s64 = 8;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822F0148;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,8
	ctx.r3.s64 = 8;
	// std r10,196(r1)
	PPC_STORE_U64(ctx.r1.u32 + 196, ctx.r10.u64);
	// bl 0x8217f768
	ctx.lr = 0x822F0160;
	sub_8217F768(ctx, base);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822F0170;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r3,7
	ctx.r3.s64 = 7;
	// std r8,204(r1)
	PPC_STORE_U64(ctx.r1.u32 + 204, ctx.r8.u64);
	// bl 0x8217f768
	ctx.lr = 0x822F0188;
	sub_8217F768(ctx, base);
	// li r7,14
	ctx.r7.s64 = 14;
	// li r3,14
	ctx.r3.s64 = 14;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x8217fed0
	ctx.lr = 0x822F0198;
	sub_8217FED0(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r6,3
	ctx.r6.s64 = 3;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// std r5,212(r1)
	PPC_STORE_U64(ctx.r1.u32 + 212, ctx.r5.u64);
	// li r3,14
	ctx.r3.s64 = 14;
	// stw r6,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r6.u32);
	// bl 0x8217f768
	ctx.lr = 0x822F01B8;
	sub_8217F768(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,168(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lfs f0,7512(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7512);
	f0.f64 = double(temp.f32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stfs f0,172(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F01E8;
	sub_8218A6E0(ctx, base);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f13,228(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f12,288(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 288);
	ctx.f12.f64 = double(temp.f32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lfs f11,224(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 224);
	ctx.f11.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f10,292(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 292);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// lfs f8,296(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 296);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f10,f13
	ctx.f7.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f6,232(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 232);
	ctx.f6.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f0,14992(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14992);
	f0.f64 = double(temp.f32);
	// fsubs f5,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 - ctx.f6.f64));
	// stfs f0,588(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f9,544(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 544, temp.u32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stfs f7,548(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 548, temp.u32);
	// lwz r5,104(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// stfs f5,552(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 552, temp.u32);
	// addi r30,r31,544
	r30.s64 = r31.s64 + 544;
	// stfs f13,556(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 556, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F0250;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,100(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x822F0274;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r6,r31,576
	ctx.r6.s64 = r31.s64 + 576;
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,108(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x822F0298;
	sub_8218A6E0(ctx, base);
	// li r10,672
	ctx.r10.s64 = 672;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f3,576(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 576);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,584(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 584);
	ctx.f2.f64 = double(temp.f32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,112(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// li r8,1
	ctx.r8.s64 = 1;
	// lvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f1,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lfs f4,136(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f13,f4,f2
	ctx.f13.f64 = double(float(ctx.f4.f64 - ctx.f2.f64));
	// fsubs f0,f1,f3
	f0.f64 = double(float(ctx.f1.f64 - ctx.f3.f64));
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F02EC;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,116(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,688
	ctx.r6.s64 = r31.s64 + 688;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x822F0310;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,704
	ctx.r6.s64 = r31.s64 + 704;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F0334;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,124(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,720
	ctx.r6.s64 = r31.s64 + 720;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F0358;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,128(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,736
	ctx.r6.s64 = r31.s64 + 736;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F037C;
	sub_8218A6E0(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,9
	ctx.r9.s64 = 9;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,132(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,-18004(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18004);
	// lwz r6,32(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r29,4(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// addi r6,r29,96
	ctx.r6.s64 = r29.s64 + 96;
	// bl 0x8218a6e0
	ctx.lr = 0x822F03B0;
	sub_8218A6E0(ctx, base);
	// lwz r5,120(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822f0404
	if (cr6.eq) goto loc_822F0404;
	// lfs f0,164(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 164);
	f0.f64 = double(temp.f32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f13,160(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// li r9,5
	ctx.r9.s64 = 5;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,180(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 180);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,152(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// fdivs f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 / ctx.f12.f64));
	// stfs f10,156(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F0404;
	sub_8218A6E0(ctx, base);
loc_822F0404:
	// lwz r11,-7572(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -7572);
	// li r8,13952
	ctx.r8.s64 = 13952;
	// li r7,13968
	ctx.r7.s64 = 13968;
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,608
	ctx.r6.s64 = 608;
	// lwz r5,164(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// li r9,5
	ctx.r9.s64 = 5;
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,1
	ctx.r8.s64 = 1;
	// lvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// vaddfp128 v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v57,r31,r6
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// vaddfp128 v56,v58,v57
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F0454;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,592
	ctx.r6.s64 = r31.s64 + 592;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F0478;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,136(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,496
	ctx.r6.s64 = r31.s64 + 496;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F049C;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,140(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,512
	ctx.r6.s64 = r31.s64 + 512;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F04C0;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,5
	ctx.r9.s64 = 5;
	// lwz r5,144(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r31,528
	ctx.r6.s64 = r31.s64 + 528;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F04E4;
	sub_8218A6E0(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r11,3568
	r11.s64 = r11.s64 + 3568;
	// addi r6,r31,368
	ctx.r6.s64 = r31.s64 + 368;
	// li r9,64
	ctx.r9.s64 = 64;
	// li r8,384
	ctx.r8.s64 = 384;
	// li r7,112
	ctx.r7.s64 = 112;
	// li r5,400
	ctx.r5.s64 = 400;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,160
	ctx.r4.s64 = 160;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,416
	ctx.r3.s64 = 416;
	// li r28,32
	r28.s64 = 32;
	// addi r30,r31,432
	r30.s64 = r31.s64 + 432;
	// li r26,448
	r26.s64 = 448;
	// li r24,464
	r24.s64 = 464;
	// li r23,480
	r23.s64 = 480;
	// addi r10,r11,28
	ctx.r10.s64 = r11.s64 + 28;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,80
	ctx.r9.s64 = 80;
	// li r8,128
	ctx.r8.s64 = 128;
	// li r7,176
	ctx.r7.s64 = 176;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stvx128 v63,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stvx128 v63,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-13032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13032);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r31,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822F0580:
	// stfs f0,-28(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -28, temp.u32);
	// addi r9,r11,220
	ctx.r9.s64 = r11.s64 + 220;
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x822f0580
	if (cr6.lt) goto loc_822F0580;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,9
	ctx.r9.s64 = 9;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,156(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F05B8;
	sub_8218A6E0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r9,9
	ctx.r9.s64 = 9;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r7,64
	ctx.r7.s64 = 64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x822F05DC;
	sub_8218A6E0(ctx, base);
	// lis r30,-32124
	r30.s64 = -2105278464;
	// lwz r5,84(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822F0610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lwz r5,88(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822F0640;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lwz r5,92(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822F0670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822F06A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,88(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F06B8;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,96(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F06D0;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,84(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F06E8;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,92(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F0700;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,1252(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 1252);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F0718;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F0730;
	sub_82189CE0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,28(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187f40
	ctx.lr = 0x822F0744;
	sub_82187F40(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822f079c
	if (cr6.eq) goto loc_822F079C;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187b88
	ctx.lr = 0x822F0758;
	sub_82187B88(ctx, base);
	// lwz r3,624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 624);
	// bl 0x82178430
	ctx.lr = 0x822F0760;
	sub_82178430(ctx, base);
	// li r6,16
	ctx.r6.s64 = 16;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,648(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 648);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82177bf8
	ctx.lr = 0x822F0774;
	sub_82177BF8(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x821795f8
	ctx.lr = 0x822F0784;
	sub_821795F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82177c50
	ctx.lr = 0x822F078C;
	sub_82177C50(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187ba8
	ctx.lr = 0x822F0794;
	sub_82187BA8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82187bd0
	ctx.lr = 0x822F079C;
	sub_82187BD0(ctx, base);
loc_822F079C:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F07B4;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,44(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F07CC;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F07E4;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,48(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F07FC;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,52(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F0814;
	sub_82189CE0(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,56(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x822F082C;
	sub_82189CE0(ctx, base);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// lis r11,-256
	r11.s64 = -16777216;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// stb r27,118(r1)
	PPC_STORE_U8(ctx.r1.u32 + 118, r27.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stb r25,119(r1)
	PPC_STORE_U8(ctx.r1.u32 + 119, r25.u8);
	// li r4,3
	ctx.r4.s64 = 3;
	// stb r25,120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 120, r25.u8);
	// stb r27,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r27.u8);
	// stb r27,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r27.u8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822F0878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822F0898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822F08B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-25232(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -25232);
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822F08D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82177c50
	ctx.lr = 0x822F08E0;
	sub_82177C50(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82178430
	ctx.lr = 0x822F08E8;
	sub_82178430(ctx, base);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82491668
	ctx.lr = 0x822F08F0;
	sub_82491668(ctx, base);
loc_822F08F0:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822F08FC"))) PPC_WEAK_FUNC(sub_822F08FC);
PPC_FUNC_IMPL(__imp__sub_822F08FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F0900"))) PPC_WEAK_FUNC(sub_822F0900);
PPC_FUNC_IMPL(__imp__sub_822F0900) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lfs f12,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r6,2256
	ctx.r4.s64 = ctx.r6.s64 + 2256;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// lfs f13,-31384(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -31384);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// fsubs f10,f0,f13
	ctx.f10.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lis r4,-32114
	ctx.r4.s64 = -2104623104;
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,1
	ctx.r10.s64 = 1;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r5,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r5.u16);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r11,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r11.u16);
	// lwz r3,-23452(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -23452);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,4
	ctx.r9.s64 = 4;
	// stb r11,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r11.u8);
	// li r8,-1
	ctx.r8.s64 = -1;
	// sth r11,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r11.u16);
	// li r7,2048
	ctx.r7.s64 = 2048;
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82574418
	ctx.lr = 0x822F09F0;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822f0a18
	if (cr6.eq) goto loc_822F0A18;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14992(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14992);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,4(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// lvx128 v60,r0,r31
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822f0a20
	goto loc_822F0A20;
loc_822F0A18:
	// lvx128 v59,r0,r31
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822F0A20:
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

__attribute__((alias("__imp__sub_822F0A38"))) PPC_WEAK_FUNC(sub_822F0A38);
PPC_FUNC_IMPL(__imp__sub_822F0A38) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822F0A40;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x822F0A54;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0c0c
	if (cr6.eq) goto loc_822F0C0C;
	// lwz r11,104(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// addi r29,r31,96
	r29.s64 = r31.s64 + 96;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0c0c
	if (cr6.eq) goto loc_822F0C0C;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822F0A78;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0c0c
	if (cr6.eq) goto loc_822F0C0C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0c0c
	if (cr6.eq) goto loc_822F0C0C;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0c0c
	if (cr6.eq) goto loc_822F0C0C;
	// lwz r26,7188(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 7188);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822f0c0c
	if (cr6.eq) goto loc_822F0C0C;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822f0ac8
	if (cr6.eq) goto loc_822F0AC8;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// b 0x822f0ad0
	goto loc_822F0AD0;
loc_822F0AC8:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
loc_822F0AD0:
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// rlwinm r9,r11,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r10,6928
	r11.s64 = ctx.r10.s64 + 6928;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r11,8
	ctx.r7.s64 = r11.s64 + 8;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfsx f13,r9,r7
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x822f0c04
	if (!cr6.eq) goto loc_822F0C04;
	// bl 0x82387a18
	ctx.lr = 0x822F0AF8;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0b18
	if (cr6.eq) goto loc_822F0B18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lbz r10,756(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 756);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822f0c04
	if (!cr6.eq) goto loc_822F0C04;
loc_822F0B18:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-8892
	ctx.r10.s64 = r11.s64 + -8892;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f0c04
	if (!cr6.eq) goto loc_822F0C04;
	// lwz r9,8(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lis r31,-32114
	r31.s64 = -2104623104;
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lwz r11,44(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// lwz r28,-22860(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + -22860);
	// lwz r27,-22856(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + -22856);
	// stw r11,-22860(r31)
	PPC_STORE_U32(r31.u32 + -22860, r11.u32);
	// lwz r8,8(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// stw r11,-22856(r30)
	PPC_STORE_U32(r30.u32 + -22856, r11.u32);
	// bl 0x822a39c8
	ctx.lr = 0x822F0B5C;
	sub_822A39C8(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x822F0B60;
	sub_822A8108(ctx, base);
	// li r7,48
	ctx.r7.s64 = 48;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r3,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f0,11368(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11368);
	f0.f64 = double(temp.f32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8224a4f8
	ctx.lr = 0x822F0B9C;
	sub_8224A4F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f0bec
	if (cr6.eq) goto loc_822F0BEC;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-14224
	ctx.r6.s64 = r11.s64 + -14224;
	// addi r5,r10,-14512
	ctx.r5.s64 = ctx.r10.s64 + -14512;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x822F0BC4;
	sub_823DEDD8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0bec
	if (cr6.eq) goto loc_822F0BEC;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r4,144(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// bl 0x823765c0
	ctx.lr = 0x822F0BDC;
	sub_823765C0(ctx, base);
	// stw r28,-22860(r31)
	PPC_STORE_U32(r31.u32 + -22860, r28.u32);
	// stw r27,-22856(r30)
	PPC_STORE_U32(r30.u32 + -22856, r27.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_822F0BEC:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82375e00
	ctx.lr = 0x822F0BF4;
	sub_82375E00(ctx, base);
	// stw r28,-22860(r31)
	PPC_STORE_U32(r31.u32 + -22860, r28.u32);
	// stw r27,-22856(r30)
	PPC_STORE_U32(r30.u32 + -22856, r27.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
loc_822F0C04:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82375e00
	ctx.lr = 0x822F0C0C;
	sub_82375E00(ctx, base);
loc_822F0C0C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822F0C14"))) PPC_WEAK_FUNC(sub_822F0C14);
PPC_FUNC_IMPL(__imp__sub_822F0C14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F0C18"))) PPC_WEAK_FUNC(sub_822F0C18);
PPC_FUNC_IMPL(__imp__sub_822F0C18) {
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
	ctx.lr = 0x822F0C20;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r29,-32114
	r29.s64 = -2104623104;
	// addi r10,r11,-6208
	ctx.r10.s64 = r11.s64 + -6208;
	// lis r28,-32114
	r28.s64 = -2104623104;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r27,-22860(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + -22860);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r26,-22856(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + -22856);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f0c58
	if (cr6.eq) goto loc_822F0C58;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,832
	ctx.r5.s64 = r11.s64 + 832;
	// b 0x822f0c60
	goto loc_822F0C60;
loc_822F0C58:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r5,r11,812
	ctx.r5.s64 = r11.s64 + 812;
loc_822F0C60:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r6,-27856(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x82137a08
	ctx.lr = 0x822F0C74;
	sub_82137A08(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r25,r10,30576
	r25.s64 = ctx.r10.s64 + 30576;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821ca540
	ctx.lr = 0x822F0C88;
	sub_821CA540(ctx, base);
	// lwz r9,96(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// addi r31,r30,96
	r31.s64 = r30.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822F0CA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r7,-19388
	ctx.r4.s64 = ctx.r7.s64 + -19388;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8224c378
	ctx.lr = 0x822F0CB8;
	sub_8224C378(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822F0CC0;
	sub_821C9A90(ctx, base);
	// stw r27,-22860(r29)
	PPC_STORE_U32(r29.u32 + -22860, r27.u32);
	// stw r26,-22856(r28)
	PPC_STORE_U32(r28.u32 + -22856, r26.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822F0CD0"))) PPC_WEAK_FUNC(sub_822F0CD0);
PPC_FUNC_IMPL(__imp__sub_822F0CD0) {
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
	// addi r3,r31,96
	ctx.r3.s64 = r31.s64 + 96;
	// bl 0x8224c100
	ctx.lr = 0x822F0CF0;
	sub_8224C100(ctx, base);
	// li r5,96
	ctx.r5.s64 = 96;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8244d150
	ctx.lr = 0x822F0D00;
	sub_8244D150(ctx, base);
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r11,-7632(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7632);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f0d3c
	if (!cr6.eq) goto loc_822F0D3C;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x822F0D18;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f0d34
	if (cr6.eq) goto loc_822F0D34;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x821ce460
	ctx.lr = 0x822F0D2C;
	sub_821CE460(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822f0d38
	goto loc_822F0D38;
loc_822F0D34:
	// li r11,0
	r11.s64 = 0;
loc_822F0D38:
	// stw r11,-7632(r30)
	PPC_STORE_U32(r30.u32 + -7632, r11.u32);
loc_822F0D3C:
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

__attribute__((alias("__imp__sub_822F0D58"))) PPC_WEAK_FUNC(sub_822F0D58);
PPC_FUNC_IMPL(__imp__sub_822F0D58) {
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
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// std r6,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// lwz r11,144(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822f0dd4
	if (cr6.eq) goto loc_822F0DD4;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f0db0
	if (!cr6.eq) goto loc_822F0DB0;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x822F0D98;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f0da8
	if (cr6.eq) goto loc_822F0DA8;
	// bl 0x821c2f70
	ctx.lr = 0x822F0DA4;
	sub_821C2F70(ctx, base);
	// b 0x822f0dac
	goto loc_822F0DAC;
loc_822F0DA8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822F0DAC:
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
loc_822F0DB0:
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822F0DC0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822f0dc0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822F0DC0;
loc_822F0DD4:
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

__attribute__((alias("__imp__sub_822F0DE8"))) PPC_WEAK_FUNC(sub_822F0DE8);
PPC_FUNC_IMPL(__imp__sub_822F0DE8) {
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
	// std r4,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// std r5,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r5.u64);
	// std r6,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r6.u64);
	// lwz r11,144(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822f0e64
	if (cr6.eq) goto loc_822F0E64;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f0e40
	if (!cr6.eq) goto loc_822F0E40;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x822F0E28;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f0e38
	if (cr6.eq) goto loc_822F0E38;
	// bl 0x821c2f70
	ctx.lr = 0x822F0E34;
	sub_821C2F70(ctx, base);
	// b 0x822f0e3c
	goto loc_822F0E3C;
loc_822F0E38:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822F0E3C:
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
loc_822F0E40:
	// lwz r10,80(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822F0E50:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x822f0e50
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822F0E50;
loc_822F0E64:
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

__attribute__((alias("__imp__sub_822F0E78"))) PPC_WEAK_FUNC(sub_822F0E78);
PPC_FUNC_IMPL(__imp__sub_822F0E78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,-1
	r11.s64 = -1;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f0,4(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f0,56(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f0,72(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stw r11,84(r3)
	PPC_STORE_U32(ctx.r3.u32 + 84, r11.u32);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stfs f0,100(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F0ED4"))) PPC_WEAK_FUNC(sub_822F0ED4);
PPC_FUNC_IMPL(__imp__sub_822F0ED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F0ED8"))) PPC_WEAK_FUNC(sub_822F0ED8);
PPC_FUNC_IMPL(__imp__sub_822F0ED8) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7572(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7572);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f0f0c
	if (cr6.eq) goto loc_822F0F0C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822F0F0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822F0F0C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7572(r31)
	PPC_STORE_U32(r31.u32 + -7572, r11.u32);
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

__attribute__((alias("__imp__sub_822F0F28"))) PPC_WEAK_FUNC(sub_822F0F28);
PPC_FUNC_IMPL(__imp__sub_822F0F28) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,14692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14692);
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8218aef8
	sub_8218AEF8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822F0F38"))) PPC_WEAK_FUNC(sub_822F0F38);
PPC_FUNC_IMPL(__imp__sub_822F0F38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// addi r11,r3,224
	r11.s64 = ctx.r3.s64 + 224;
	// stfs f1,14708(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 14708, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r3,14692(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14692);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r6,5
	ctx.r6.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,92(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8218aef8
	ctx.lr = 0x822F0F7C;
	sub_8218AEF8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F0F8C"))) PPC_WEAK_FUNC(sub_822F0F8C);
PPC_FUNC_IMPL(__imp__sub_822F0F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F0F90"))) PPC_WEAK_FUNC(sub_822F0F90);
PPC_FUNC_IMPL(__imp__sub_822F0F90) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x823bc5e0
	ctx.lr = 0x822F0FB0;
	sub_823BC5E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f1070
	if (cr6.eq) goto loc_822F1070;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-8092(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lbz r10,393(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 393);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822f1070
	if (cr6.eq) goto loc_822F1070;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,14512
	ctx.r8.s64 = 14512;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f0,-9160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -9160);
	f0.f64 = double(temp.f32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lfs f12,17032(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r11,2240
	ctx.r9.s64 = r11.s64 + 2240;
	// lvx128 v63,r30,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r5,-31664
	ctx.r3.s64 = ctx.r5.s64 + -31664;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r10,-31648
	ctx.r8.s64 = ctx.r10.s64 + -31648;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_add_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// vmsum3fp128 v60,v61,v61
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2528
	ctx.r4.s64 = ctx.r6.s64 + 2528;
	// lvx128 v13,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v12,v60,v60
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v11,v59,v62
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v10,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
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
	// vmulfp128 v58,v61,v6
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822f107c
	goto loc_822F107C;
loc_822F1070:
	// li r11,14512
	r11.s64 = 14512;
	// lvx128 v57,r30,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822F107C:
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

__attribute__((alias("__imp__sub_822F1094"))) PPC_WEAK_FUNC(sub_822F1094);
PPC_FUNC_IMPL(__imp__sub_822F1094) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1098"))) PPC_WEAK_FUNC(sub_822F1098);
PPC_FUNC_IMPL(__imp__sub_822F1098) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7ce0
	ctx.lr = 0x822F10B4;
	sub_822F7CE0(ctx, base);
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7190
	ctx.lr = 0x822F10BC;
	sub_822F7190(ctx, base);
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

__attribute__((alias("__imp__sub_822F10D0"))) PPC_WEAK_FUNC(sub_822F10D0);
PPC_FUNC_IMPL(__imp__sub_822F10D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,14546(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f1120
	if (cr6.eq) goto loc_822F1120;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f1104
	if (cr6.eq) goto loc_822F1104;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 608);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x822f1108
	if (!cr6.eq) goto loc_822F1108;
loc_822F1104:
	// li r11,0
	r11.s64 = 0;
loc_822F1108:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r11.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// blr 
	return;
loc_822F1120:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822f114c
	if (cr6.eq) goto loc_822F114C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// addi r11,r11,3633
	r11.s64 = r11.s64 + 3633;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r10,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822F114C:
	// li r11,2
	r11.s64 = 2;
	// addi r11,r11,3633
	r11.s64 = r11.s64 + 3633;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f1,r10,r3
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1160"))) PPC_WEAK_FUNC(sub_822F1160);
PPC_FUNC_IMPL(__imp__sub_822F1160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lfs f0,496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 496);
	f0.f64 = double(temp.f32);
	// lfs f13,500(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 500);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F117C"))) PPC_WEAK_FUNC(sub_822F117C);
PPC_FUNC_IMPL(__imp__sub_822F117C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1180"))) PPC_WEAK_FUNC(sub_822F1180);
PPC_FUNC_IMPL(__imp__sub_822F1180) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lfs f1,504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 504);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1190"))) PPC_WEAK_FUNC(sub_822F1190);
PPC_FUNC_IMPL(__imp__sub_822F1190) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lfs f1,508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 508);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F11A0"))) PPC_WEAK_FUNC(sub_822F11A0);
PPC_FUNC_IMPL(__imp__sub_822F11A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,528
	ctx.r10.s64 = 528;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F11B8"))) PPC_WEAK_FUNC(sub_822F11B8);
PPC_FUNC_IMPL(__imp__sub_822F11B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lfs f1,544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 544);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F11C8"))) PPC_WEAK_FUNC(sub_822F11C8);
PPC_FUNC_IMPL(__imp__sub_822F11C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,560
	ctx.r10.s64 = 560;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F11E0"))) PPC_WEAK_FUNC(sub_822F11E0);
PPC_FUNC_IMPL(__imp__sub_822F11E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lfs f1,576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 576);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F11F0"))) PPC_WEAK_FUNC(sub_822F11F0);
PPC_FUNC_IMPL(__imp__sub_822F11F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,592
	ctx.r10.s64 = 592;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1208"))) PPC_WEAK_FUNC(sub_822F1208);
PPC_FUNC_IMPL(__imp__sub_822F1208) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	// bl 0x823d91f0
	ctx.lr = 0x822F1210;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stfs f1,276(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,14608(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 14608);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// beq cr6,0x822f1258
	if (cr6.eq) goto loc_822F1258;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f13,-9152(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -9152);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822f125c
	goto loc_822F125C;
loc_822F1258:
	// fmr f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f0.f64;
loc_822F125C:
	// lfs f12,14612(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 14612);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// fmuls f30,f12,f13
	f30.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// beq cr6,0x822f1288
	if (cr6.eq) goto loc_822F1288;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f127c
	if (cr6.eq) goto loc_822F127C;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
loc_822F127C:
	// lfs f13,14620(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 14620);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 * f0.f64));
	// b 0x822f1298
	goto loc_822F1298;
loc_822F1288:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,30284(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30284);
	f30.f64 = double(temp.f32);
loc_822F1298:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x822f131c
	if (!cr6.gt) goto loc_822F131C;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r31,r4,48
	r31.s64 = ctx.r4.s64 + 48;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r27,-16
	r27.s64 = -16;
	// lis r28,-32120
	r28.s64 = -2105016320;
loc_822F12B4:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,276
	ctx.r10.s64 = ctx.r1.s64 + 276;
	// lvx128 v62,r31,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v127,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r3,-7436(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -7436);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lfs f3,14616(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 14616);
	ctx.f3.f64 = double(temp.f32);
	// lvlx128 v60,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvlx128 v58,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// vmulfp128 v56,v63,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v55,v56,v57
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f78a8
	ctx.lr = 0x822F1310;
	sub_822F78A8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// bne 0x822f12b4
	if (!cr0.eq) goto loc_822F12B4;
loc_822F131C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822F1334"))) PPC_WEAK_FUNC(sub_822F1334);
PPC_FUNC_IMPL(__imp__sub_822F1334) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1338"))) PPC_WEAK_FUNC(sub_822F1338);
PPC_FUNC_IMPL(__imp__sub_822F1338) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// b 0x822f7ac0
	sub_822F7AC0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822F1344"))) PPC_WEAK_FUNC(sub_822F1344);
PPC_FUNC_IMPL(__imp__sub_822F1344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1348"))) PPC_WEAK_FUNC(sub_822F1348);
PPC_FUNC_IMPL(__imp__sub_822F1348) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// b 0x822f72a0
	sub_822F72A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822F1354"))) PPC_WEAK_FUNC(sub_822F1354);
PPC_FUNC_IMPL(__imp__sub_822F1354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1358"))) PPC_WEAK_FUNC(sub_822F1358);
PPC_FUNC_IMPL(__imp__sub_822F1358) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// b 0x822f7c78
	sub_822F7C78(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822F1364"))) PPC_WEAK_FUNC(sub_822F1364);
PPC_FUNC_IMPL(__imp__sub_822F1364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1368"))) PPC_WEAK_FUNC(sub_822F1368);
PPC_FUNC_IMPL(__imp__sub_822F1368) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822F1370;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r30,r31,14640
	r30.s64 = r31.s64 + 14640;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lfs f31,14624(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14624);
	f31.f64 = double(temp.f32);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821c9788
	ctx.lr = 0x822F139C;
	sub_821C9788(ctx, base);
	// lwz r10,14680(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 14680);
	// clrldi r9,r3,32
	ctx.r9.u64 = ctx.r3.u64 & 0xFFFFFFFF;
	// lfs f0,14676(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14676);
	f0.f64 = double(temp.f32);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// lfs f13,14672(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14672);
	ctx.f13.f64 = double(temp.f32);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fadds f8,f13,f0
	ctx.f8.f64 = double(float(ctx.f13.f64 + f0.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// lfs f0,11360(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	f0.f64 = double(temp.f32);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// lfs f13,3732(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f1,f7,f0
	ctx.f1.f64 = double(float(ctx.f7.f64 * f0.f64));
	// fmuls f30,f8,f6
	f30.f64 = double(float(ctx.f8.f64 * ctx.f6.f64));
	// fmuls f2,f30,f13
	ctx.f2.f64 = double(float(f30.f64 * ctx.f13.f64));
	// bl 0x823dc100
	ctx.lr = 0x822F13F4;
	sub_823DC100(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
	// fcmpu cr6,f1,f30
	cr6.compare(ctx.f1.f64, f30.f64);
	// ble cr6,0x822f1414
	if (!cr6.gt) goto loc_822F1414;
	// li r11,14656
	r11.s64 = 14656;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r31,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822f1420
	goto loc_822F1420;
loc_822F1414:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822F1420:
	// lfs f0,14672(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14672);
	f0.f64 = double(temp.f32);
	// lfs f13,14676(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14676);
	ctx.f13.f64 = double(temp.f32);
	// fadds f2,f0,f13
	ctx.f2.f64 = double(float(f0.f64 + ctx.f13.f64));
	// bl 0x823dc100
	ctx.lr = 0x822F1430;
	sub_823DC100(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,14672(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14672);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// ble cr6,0x822f1448
	if (!cr6.gt) goto loc_822F1448;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_822F1448:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r29,32
	ctx.r5.s64 = r29.s64 + 32;
	// addi r4,r29,48
	ctx.r4.s64 = r29.s64 + 48;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f79c0
	ctx.lr = 0x822F1464;
	sub_822F79C0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822F1474"))) PPC_WEAK_FUNC(sub_822F1474);
PPC_FUNC_IMPL(__imp__sub_822F1474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1478"))) PPC_WEAK_FUNC(sub_822F1478);
PPC_FUNC_IMPL(__imp__sub_822F1478) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,9712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 9712);
	f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r3,-7436(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7436);
	// bl 0x822f72d0
	ctx.lr = 0x822F14B4;
	sub_822F72D0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F14C4"))) PPC_WEAK_FUNC(sub_822F14C4);
PPC_FUNC_IMPL(__imp__sub_822F14C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F14C8"))) PPC_WEAK_FUNC(sub_822F14C8);
PPC_FUNC_IMPL(__imp__sub_822F14C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,9716
	ctx.r9.s64 = r11.s64 + 9716;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lwz r3,-7436(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7436);
	// vmulfp128 v60,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f72b8
	ctx.lr = 0x822F1504;
	sub_822F72B8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1514"))) PPC_WEAK_FUNC(sub_822F1514);
PPC_FUNC_IMPL(__imp__sub_822F1514) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1518"))) PPC_WEAK_FUNC(sub_822F1518);
PPC_FUNC_IMPL(__imp__sub_822F1518) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,14540(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14540);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beqlr cr6
	if (cr6.eq) return;
	// li r11,1
	r11.s64 = 1;
	// stfs f2,14548(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 14548, temp.u32);
	// stfs f1,14556(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 14556, temp.u32);
	// stb r11,14552(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14552, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1538"))) PPC_WEAK_FUNC(sub_822F1538);
PPC_FUNC_IMPL(__imp__sub_822F1538) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// li r10,16
	ctx.r10.s64 = 16;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,32
	r11.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r4,91
	ctx.r8.s64 = ctx.r4.s64 + 91;
	// addi r7,r3,91
	ctx.r7.s64 = ctx.r3.s64 + 91;
	// lvx128 v62,r4,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// lvx128 v61,r4,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// lvx128 v60,r4,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,5
	ctx.r9.s64 = 5;
	// lfs f0,64(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 64);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f13,68(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,68(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lfs f12,72(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,72(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// lfs f11,76(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 76);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,76(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// lfs f10,80(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,80(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lfs f9,84(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 84);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,84(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// lbz r6,88(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 88);
	// stb r6,88(r3)
	PPC_STORE_U8(ctx.r3.u32 + 88, ctx.r6.u8);
	// lbz r5,89(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 89);
	// stb r5,89(r3)
	PPC_STORE_U8(ctx.r3.u32 + 89, ctx.r5.u8);
	// lbz r4,90(r4)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r4.u32 + 90);
	// stb r4,90(r3)
	PPC_STORE_U8(ctx.r3.u32 + 90, ctx.r4.u8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_822F15C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x822f15c4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822F15C4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F15DC"))) PPC_WEAK_FUNC(sub_822F15DC);
PPC_FUNC_IMPL(__imp__sub_822F15DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F15E0"))) PPC_WEAK_FUNC(sub_822F15E0);
PPC_FUNC_IMPL(__imp__sub_822F15E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x822F15E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,3
	r30.s64 = 3;
	// mr r29,r31
	r29.u64 = r31.u64;
loc_822F15F8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822fe3a8
	ctx.lr = 0x822F1600;
	sub_822FE3A8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bge 0x822f15f8
	if (!cr0.lt) goto loc_822F15F8;
	// addi r29,r31,400
	r29.s64 = r31.s64 + 400;
	// li r30,3
	r30.s64 = 3;
loc_822F1614:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822fe3a8
	ctx.lr = 0x822F161C;
	sub_822FE3A8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// bge 0x822f1614
	if (!cr0.lt) goto loc_822F1614;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,-1
	r11.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,800(r31)
	PPC_STORE_U32(r31.u32 + 800, r11.u32);
	// stw r11,804(r31)
	PPC_STORE_U32(r31.u32 + 804, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,808(r31)
	PPC_STORE_U32(r31.u32 + 808, r11.u32);
	// stw r11,812(r31)
	PPC_STORE_U32(r31.u32 + 812, r11.u32);
	// stfs f0,384(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 384, temp.u32);
	// stfs f0,388(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 388, temp.u32);
	// stfs f0,392(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 392, temp.u32);
	// stfs f0,784(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 784, temp.u32);
	// stfs f0,788(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 788, temp.u32);
	// stfs f0,792(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 792, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822F1668"))) PPC_WEAK_FUNC(sub_822F1668);
PPC_FUNC_IMPL(__imp__sub_822F1668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// b 0x822f7198
	sub_822F7198(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822F1674"))) PPC_WEAK_FUNC(sub_822F1674);
PPC_FUNC_IMPL(__imp__sub_822F1674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1678"))) PPC_WEAK_FUNC(sub_822F1678);
PPC_FUNC_IMPL(__imp__sub_822F1678) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// b 0x822f71a0
	sub_822F71A0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822F1684"))) PPC_WEAK_FUNC(sub_822F1684);
PPC_FUNC_IMPL(__imp__sub_822F1684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1688"))) PPC_WEAK_FUNC(sub_822F1688);
PPC_FUNC_IMPL(__imp__sub_822F1688) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f71a8
	ctx.lr = 0x822F16A4;
	sub_822F71A8(ctx, base);
	// lwz r3,-7436(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7436);
	// bl 0x822f7198
	ctx.lr = 0x822F16AC;
	sub_822F7198(ctx, base);
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

__attribute__((alias("__imp__sub_822F16C0"))) PPC_WEAK_FUNC(sub_822F16C0);
PPC_FUNC_IMPL(__imp__sub_822F16C0) {
	PPC_FUNC_PROLOGUE();
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82377f10
	ctx.lr = 0x822F16E8;
	sub_82377F10(ctx, base);
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lfs f1,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82377f10
	ctx.lr = 0x822F16F8;
	sub_82377F10(ctx, base);
	// addi r4,r31,32
	ctx.r4.s64 = r31.s64 + 32;
	// li r3,2
	ctx.r3.s64 = 2;
	// lfs f1,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82377f10
	ctx.lr = 0x822F1708;
	sub_82377F10(ctx, base);
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

__attribute__((alias("__imp__sub_822F1720"))) PPC_WEAK_FUNC(sub_822F1720);
PPC_FUNC_IMPL(__imp__sub_822F1720) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stb r3,-7588(r11)
	PPC_STORE_U8(r11.u32 + -7588, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F172C"))) PPC_WEAK_FUNC(sub_822F172C);
PPC_FUNC_IMPL(__imp__sub_822F172C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1730"))) PPC_WEAK_FUNC(sub_822F1730);
PPC_FUNC_IMPL(__imp__sub_822F1730) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lfs f1,516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 516);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1740"))) PPC_WEAK_FUNC(sub_822F1740);
PPC_FUNC_IMPL(__imp__sub_822F1740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r11,r3,12912
	r11.s64 = ctx.r3.s64 + 12912;
	// li r9,1056
	ctx.r9.s64 = 1056;
	// addi r10,r3,14464
	ctx.r10.s64 = ctx.r3.s64 + 14464;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,1040
	ctx.r7.s64 = 1040;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,14456(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14456);
	f0.f64 = double(temp.f32);
	// stfs f0,14496(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 14496, temp.u32);
	// lfs f13,14460(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14460);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,14500(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 14500, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1778"))) PPC_WEAK_FUNC(sub_822F1778);
PPC_FUNC_IMPL(__imp__sub_822F1778) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bne cr6,0x822f17cc
	if (!cr6.eq) goto loc_822F17CC;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,16
	r11.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// vupkd3d128 v62,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v62 = vTemp;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822F17CC:
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x822f1834
	if (!cr6.eq) goto loc_822F1834;
	// lfs f13,4(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x822f1808
	if (!cr6.eq) goto loc_822F1808;
	// lfs f13,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822f17f4
	if (cr6.gt) goto loc_822F17F4;
	// fneg f1,f1
	ctx.f1.u64 = ctx.f1.u64 ^ 0x8000000000000000;
loc_822F17F4:
	// bl 0x82234fc0
	ctx.lr = 0x822F17F8;
	sub_82234FC0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822F1808:
	// lfs f12,8(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bne cr6,0x822f186c
	if (!cr6.eq) goto loc_822F186C;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822f1820
	if (cr6.gt) goto loc_822F1820;
	// fneg f1,f1
	ctx.f1.u64 = ctx.f1.u64 ^ 0x8000000000000000;
loc_822F1820:
	// bl 0x82202e38
	ctx.lr = 0x822F1824;
	sub_82202E38(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822F1834:
	// lfs f12,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bne cr6,0x822f186c
	if (!cr6.eq) goto loc_822F186C;
	// lfs f12,8(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bne cr6,0x822f186c
	if (!cr6.eq) goto loc_822F186C;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822f1858
	if (cr6.gt) goto loc_822F1858;
	// fneg f1,f1
	ctx.f1.u64 = ctx.f1.u64 ^ 0x8000000000000000;
loc_822F1858:
	// bl 0x82224a40
	ctx.lr = 0x822F185C;
	sub_82224A40(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822F186C:
	// lvx128 v58,r0,r4
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32122
	r11.s64 = -2105147392;
	// vmsum3fp128 v57,v58,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v58.f32), 0xEF));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r9,r11,2528
	ctx.r9.s64 = r11.s64 + 2528;
	// addi r8,r10,2240
	ctx.r8.s64 = ctx.r10.s64 + 2240;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r5,r7,-31648
	ctx.r5.s64 = ctx.r7.s64 + -31648;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r6,-31664
	r11.s64 = ctx.r6.s64 + -31664;
	// lvx128 v0,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v56,v57
	simde_mm_store_ps(v56.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v57.f32))));
	// vor128 v12,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
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
	// vmulfp128 v55,v58,v6
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(ctx.v6.f32)));
	// stvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82227f50
	ctx.lr = 0x822F18DC;
	sub_82227F50(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F18EC"))) PPC_WEAK_FUNC(sub_822F18EC);
PPC_FUNC_IMPL(__imp__sub_822F18EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F18F0"))) PPC_WEAK_FUNC(sub_822F18F0);
PPC_FUNC_IMPL(__imp__sub_822F18F0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822F18F8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// li r12,-64
	r12.s64 = -64;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r29,r11,-31600
	r29.s64 = r11.s64 + -31600;
	// addi r30,r31,32
	r30.s64 = r31.s64 + 32;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f31,31292(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31292);
	f31.f64 = double(temp.f32);
	// lvx128 v1,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82165300
	ctx.lr = 0x822F1930;
	sub_82165300(ctx, base);
	// addi r28,r31,16
	r28.s64 = r31.s64 + 16;
	// lvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v62,v63,99
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lvx128 v127,r0,r30
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v127,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// vpermwi128 v13,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// vmulfp128 v12,v61,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// vnmsubfp v0,v13,v0,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v0,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f12
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f0,f13,f13,f10
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822f19dc
	if (!cr6.gt) goto loc_822F19DC;
	// frsqrte f10,f0
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fneg f9,f0
	ctx.f9.u64 = f0.u64 ^ 0x8000000000000000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfd f13,32224(r11)
	ctx.f13.u64 = PPC_LOAD_U64(r11.u32 + 32224);
	// lfd f12,21560(r10)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r10.u32 + 21560);
	// lfs f11,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// fmul f8,f10,f10
	ctx.f8.f64 = ctx.f10.f64 * ctx.f10.f64;
	// fmul f7,f10,f13
	ctx.f7.f64 = ctx.f10.f64 * ctx.f13.f64;
	// fnmsub f6,f8,f0,f12
	ctx.f6.f64 = -(ctx.f8.f64 * f0.f64 - ctx.f12.f64);
	// fmadd f5,f6,f7,f10
	ctx.f5.f64 = ctx.f6.f64 * ctx.f7.f64 + ctx.f10.f64;
	// fmul f4,f5,f5
	ctx.f4.f64 = ctx.f5.f64 * ctx.f5.f64;
	// fmul f3,f5,f13
	ctx.f3.f64 = ctx.f5.f64 * ctx.f13.f64;
	// fnmsub f2,f4,f0,f12
	ctx.f2.f64 = -(ctx.f4.f64 * f0.f64 - ctx.f12.f64);
	// fmadd f1,f2,f3,f5
	ctx.f1.f64 = ctx.f2.f64 * ctx.f3.f64 + ctx.f5.f64;
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// fsel f13,f9,f11,f0
	ctx.f13.f64 = ctx.f9.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v60,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v58,v0,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v58,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822f1ad0
	goto loc_822F1AD0;
loc_822F19DC:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// vpermwi128 v57,v127,135
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// vpermwi128 v0,v127,99
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r11,-31616
	ctx.r9.s64 = r11.s64 + -31616;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v56,v62,99
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// vpermwi128 v13,v62,135
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// vmulfp128 v12,v57,v56
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v56.f32)));
	// vnmsubfp v0,v0,v13,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f0,f13,f13,f11
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822f1a88
	if (!cr6.gt) goto loc_822F1A88;
	// frsqrte f10,f0
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fneg f9,f0
	ctx.f9.u64 = f0.u64 ^ 0x8000000000000000;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfd f13,32224(r11)
	ctx.f13.u64 = PPC_LOAD_U64(r11.u32 + 32224);
	// lfd f12,21560(r10)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r10.u32 + 21560);
	// lfs f11,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f11.f64 = double(temp.f32);
	// fmul f8,f10,f10
	ctx.f8.f64 = ctx.f10.f64 * ctx.f10.f64;
	// fmul f7,f10,f13
	ctx.f7.f64 = ctx.f10.f64 * ctx.f13.f64;
	// fnmsub f6,f8,f0,f12
	ctx.f6.f64 = -(ctx.f8.f64 * f0.f64 - ctx.f12.f64);
	// fmadd f5,f6,f7,f10
	ctx.f5.f64 = ctx.f6.f64 * ctx.f7.f64 + ctx.f10.f64;
	// fmul f4,f5,f5
	ctx.f4.f64 = ctx.f5.f64 * ctx.f5.f64;
	// fmul f3,f5,f13
	ctx.f3.f64 = ctx.f5.f64 * ctx.f13.f64;
	// fnmsub f2,f4,f0,f12
	ctx.f2.f64 = -(ctx.f4.f64 * f0.f64 - ctx.f12.f64);
	// fmadd f1,f2,f3,f5
	ctx.f1.f64 = ctx.f2.f64 * ctx.f3.f64 + ctx.f5.f64;
	// frsp f0,f1
	f0.f64 = double(float(ctx.f1.f64));
	// fsel f13,f9,f11,f0
	ctx.f13.f64 = ctx.f9.f64 >= 0.0 ? ctx.f11.f64 : f0.f64;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v55,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmulfp128 v63,v0,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v54.f32)));
	// b 0x822f1acc
	goto loc_822F1ACC;
loc_822F1A88:
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v53,v63,99
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// vpermwi128 v52,v62,135
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vpermwi128 v0,v63,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// vpermwi128 v13,v62,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r9,r10,-31632
	ctx.r9.s64 = ctx.r10.s64 + -31632;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// vmulfp128 v12,v52,v53
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32)));
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x822F1AC4;
	sub_82165300(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822F1ACC:
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822F1AD0:
	// lvx128 v51,r0,r31
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v50,v127,99
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x9C));
	// vpermwi128 v49,v51,135
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x78));
	// vpermwi128 v0,v127,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v127.u32), 0x78));
	// vpermwi128 v13,v51,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x9C));
	// vmulfp128 v12,v49,v50
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// li r0,-64
	r0.s64 = -64;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822F1B04"))) PPC_WEAK_FUNC(sub_822F1B04);
PPC_FUNC_IMPL(__imp__sub_822F1B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1B08"))) PPC_WEAK_FUNC(sub_822F1B08);
PPC_FUNC_IMPL(__imp__sub_822F1B08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r9,8
	ctx.r9.s64 = 8;
	// li r10,-8
	ctx.r10.s64 = -8;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lhz r11,20(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// lhz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 16);
	// lvrx128 v63,r9,r31
	temp.u32 = ctx.r9.u32 + r31.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// lvlx128 v62,r10,r31
	temp.u32 = ctx.r10.u32 + r31.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// lbz r3,22(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 22);
	// extsw r5,r8
	ctx.r5.s64 = ctx.r8.s32;
	// vor128 v61,v62,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lhz r4,18(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 18);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lvrx128 v59,r9,r11
	temp.u32 = ctx.r9.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// extsw r8,r4
	ctx.r8.s64 = ctx.r4.s32;
	// lvlx128 v58,r10,r11
	temp.u32 = ctx.r10.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// vor128 v56,v58,v59
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)v59.u8)));
	// vupkd3d128 v57,v61,20
	__builtin_debugtrap();
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// fcfid f8,f0
	ctx.f8.f64 = double(f0.s64);
	// lis r5,-32119
	ctx.r5.s64 = -2104950784;
	// vupkd3d128 v55,v56,20
	__builtin_debugtrap();
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// lis r4,-32119
	ctx.r4.s64 = -2104950784;
	// stvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lfs f2,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f2.f64 = double(temp.f32);
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r5,-18480
	ctx.r3.s64 = ctx.r5.s64 + -18480;
	// addi r8,r4,-18448
	ctx.r8.s64 = ctx.r4.s64 + -18448;
	// lfs f1,92(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f1.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// lvrx128 v53,r9,r11
	temp.u32 = ctx.r9.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// lvlx128 v51,r10,r11
	temp.u32 = ctx.r10.u32 + r11.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvrx128 v60,r9,r31
	temp.u32 = ctx.r9.u32 + r31.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// fcfid f6,f12
	ctx.f6.f64 = double(ctx.f12.s64);
	// lvlx128 v54,r10,r31
	temp.u32 = ctx.r10.u32 + r31.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v50,v51,v53
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// lvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v52,v54,v60
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v60.u8)));
	// lvx128 v13,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f7,84(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vupkd3d128 v48,v50,20
	__builtin_debugtrap();
	// stfs f4,88(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// vupkd3d128 v49,v52,20
	__builtin_debugtrap();
	// lvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// frsp f3,f6
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// stvx128 v49,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f0,15364(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15364);
	f0.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f13,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmsubs f13,f3,f0,f13
	ctx.f13.f64 = double(float(ctx.f3.f64 * f0.f64 - ctx.f13.f64));
	// lfs f0,15360(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 15360);
	f0.f64 = double(temp.f32);
	// fmuls f3,f13,f0
	ctx.f3.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x822fd4e0
	ctx.lr = 0x822F1C60;
	sub_822FD4E0(ctx, base);
	// lbz r6,23(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 23);
	// rlwinm r5,r6,26,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 26) & 0x1;
	// stb r5,89(r30)
	PPC_STORE_U8(r30.u32 + 89, ctx.r5.u8);
	// lbz r4,23(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 23);
	// rlwinm r3,r4,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stb r3,90(r30)
	PPC_STORE_U8(r30.u32 + 90, ctx.r3.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_822F1C90"))) PPC_WEAK_FUNC(sub_822F1C90);
PPC_FUNC_IMPL(__imp__sub_822F1C90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r10,1476
	ctx.r7.s64 = ctx.r10.s64 + 1476;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stfs f0,512(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 512, temp.u32);
	// stfs f0,516(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 516, temp.u32);
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stfs f13,528(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 528, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// stfs f13,532(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 532, temp.u32);
	// stfs f13,536(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 536, temp.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,544(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 544, temp.u32);
	// stfs f0,560(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 560, temp.u32);
	// stfs f0,564(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 564, temp.u32);
	// lfs f13,1468(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 1468);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,568(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 568, temp.u32);
	// lfs f0,-31384(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31384);
	f0.f64 = double(temp.f32);
	// lfs f13,1464(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 1464);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1460(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1460);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,1456(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 1456);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,576(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 576, temp.u32);
	// lfs f0,1452(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 1452);
	f0.f64 = double(temp.f32);
	// stfs f13,592(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 592, temp.u32);
	// stfs f12,596(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 596, temp.u32);
	// stfs f11,600(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 600, temp.u32);
	// stfs f0,608(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 608, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1D20"))) PPC_WEAK_FUNC(sub_822F1D20);
PPC_FUNC_IMPL(__imp__sub_822F1D20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7580(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7580);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F1D2C"))) PPC_WEAK_FUNC(sub_822F1D2C);
PPC_FUNC_IMPL(__imp__sub_822F1D2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1D30"))) PPC_WEAK_FUNC(sub_822F1D30);
PPC_FUNC_IMPL(__imp__sub_822F1D30) {
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
	ctx.lr = 0x822F1D38;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// addi r10,r11,1488
	ctx.r10.s64 = r11.s64 + 1488;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,-7568(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -7568);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f1d70
	if (cr6.eq) goto loc_822F1D70;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822F1D70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822F1D70:
	// li r11,0
	r11.s64 = 0;
	// addi r3,r29,12912
	ctx.r3.s64 = r29.s64 + 12912;
	// stw r11,-7568(r31)
	PPC_STORE_U32(r31.u32 + -7568, r11.u32);
	// bl 0x82300330
	ctx.lr = 0x822F1D80;
	sub_82300330(ctx, base);
	// addi r31,r29,12912
	r31.s64 = r29.s64 + 12912;
	// li r30,7
	r30.s64 = 7;
loc_822F1D88:
	// addi r31,r31,-1552
	r31.s64 = r31.s64 + -1552;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82300330
	ctx.lr = 0x822F1D94;
	sub_82300330(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x822f1d88
	if (!cr0.lt) goto loc_822F1D88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821d2028
	ctx.lr = 0x822F1DA4;
	sub_821D2028(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822F1DAC"))) PPC_WEAK_FUNC(sub_822F1DAC);
PPC_FUNC_IMPL(__imp__sub_822F1DAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1DB0"))) PPC_WEAK_FUNC(sub_822F1DB0);
PPC_FUNC_IMPL(__imp__sub_822F1DB0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// li r7,0
	ctx.r7.s64 = 0;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lbz r8,14545(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 14545);
	// lfs f3,29504(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29504);
	ctx.f3.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r8,r11,29952
	ctx.r8.s64 = r11.s64 + 29952;
	// beq cr6,0x822f1eac
	if (cr6.eq) goto loc_822F1EAC;
	// lbz r11,14552(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14552);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f1eac
	if (!cr6.eq) goto loc_822F1EAC;
	// lwz r11,-12640(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822f1e14
	if (cr6.eq) goto loc_822F1E14;
	// lbz r10,10(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822f1e18
	if (cr6.eq) goto loc_822F1E18;
loc_822F1E14:
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
loc_822F1E18:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822f1eb0
	if (!cr6.eq) goto loc_822F1EB0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,14540(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14540);
	f0.f64 = double(temp.f32);
	// lfs f13,6088(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6088);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822f1e80
	if (!cr6.gt) goto loc_822F1E80;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,1452(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1452);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822f1e80
	if (!cr6.lt) goto loc_822F1E80;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,-12736(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12736);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822f1e64
	if (!cr6.lt) goto loc_822F1E64;
loc_822F1E58:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,1500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1500);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822f1e88
	goto loc_822F1E88;
loc_822F1E64:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,15000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15000);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822f1e58
	if (!cr6.lt) goto loc_822F1E58;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,1496(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1496);
	ctx.f13.f64 = double(temp.f32);
	// b 0x822f1e88
	goto loc_822F1E88;
loc_822F1E80:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,1492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1492);
	ctx.f13.f64 = double(temp.f32);
loc_822F1E88:
	// stfs f13,14548(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 14548, temp.u32);
	// lfs f13,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14548(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14548);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f12,f13,f0
	f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + f0.f64));
	// stfs f0,14540(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14540, temp.u32);
	// fcmpu cr6,f0,f3
	cr6.compare(f0.f64, ctx.f3.f64);
	// blt cr6,0x822f1eac
	if (cr6.lt) goto loc_822F1EAC;
	// fsubs f0,f0,f3
	f0.f64 = double(float(f0.f64 - ctx.f3.f64));
	// stfs f0,14540(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14540, temp.u32);
loc_822F1EAC:
	// lwz r11,-12640(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12640);
loc_822F1EB0:
	// lbz r10,14552(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 14552);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822f1fb0
	if (cr6.eq) goto loc_822F1FB0;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822f1ed8
	if (cr6.eq) goto loc_822F1ED8;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822f1edc
	if (cr6.eq) goto loc_822F1EDC;
loc_822F1ED8:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_822F1EDC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f1f20
	if (cr6.eq) goto loc_822F1F20;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r11,76(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822f1f10
	if (!cr6.eq) goto loc_822F1F10;
	// rlwinm r11,r11,0,25,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822f1f14
	if (cr6.eq) goto loc_822F1F14;
loc_822F1F10:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_822F1F14:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f1fb0
	if (cr6.eq) goto loc_822F1FB0;
loc_822F1F20:
	// lfs f0,14556(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14556);
	f0.f64 = double(temp.f32);
	// lfs f13,14540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14540);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822f1f38
	if (!cr6.lt) goto loc_822F1F38;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// b 0x822f1f3c
	goto loc_822F1F3C;
loc_822F1F38:
	// fadds f12,f0,f3
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 + ctx.f3.f64));
loc_822F1F3C:
	// fsubs f11,f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822f1f4c
	if (!cr6.lt) goto loc_822F1F4C;
	// fsubs f0,f0,f3
	f0.f64 = double(float(f0.f64 - ctx.f3.f64));
loc_822F1F4C:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// lfs f11,14548(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14548);
	ctx.f11.f64 = double(temp.f32);
	// bge cr6,0x822f1f7c
	if (!cr6.lt) goto loc_822F1F7C;
	// lfs f13,14540(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14540);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f10,14540(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 14540, temp.u32);
	// fcmpu cr6,f10,f12
	cr6.compare(ctx.f10.f64, ctx.f12.f64);
	// blt cr6,0x822f1f9c
	if (cr6.lt) goto loc_822F1F9C;
	// stfs f12,14540(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 14540, temp.u32);
	// b 0x822f1f98
	goto loc_822F1F98;
loc_822F1F7C:
	// lfs f12,14540(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14540);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f10,f11,f13,f12
	ctx.f10.f64 = double(float(-(ctx.f11.f64 * ctx.f13.f64 - ctx.f12.f64)));
	// stfs f10,14540(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 14540, temp.u32);
	// fcmpu cr6,f10,f0
	cr6.compare(ctx.f10.f64, f0.f64);
	// bgt cr6,0x822f1f9c
	if (cr6.gt) goto loc_822F1F9C;
	// stfs f0,14540(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14540, temp.u32);
loc_822F1F98:
	// stb r7,14552(r31)
	PPC_STORE_U8(r31.u32 + 14552, ctx.r7.u8);
loc_822F1F9C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,14540(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14540);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x82151fe0
	ctx.lr = 0x822F1FAC;
	sub_82151FE0(ctx, base);
	// stfs f1,14540(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 14540, temp.u32);
loc_822F1FB0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lfs f0,14540(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14540);
	f0.f64 = double(temp.f32);
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// addi r10,r11,3633
	ctx.r10.s64 = r11.s64 + 3633;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stfsx f0,r9,r31
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + r31.u32, temp.u32);
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

__attribute__((alias("__imp__sub_822F1FDC"))) PPC_WEAK_FUNC(sub_822F1FDC);
PPC_FUNC_IMPL(__imp__sub_822F1FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F1FE0"))) PPC_WEAK_FUNC(sub_822F1FE0);
PPC_FUNC_IMPL(__imp__sub_822F1FE0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfs f0,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x822f2010
	if (cr6.lt) goto loc_822F2010;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// b 0x822f2044
	goto loc_822F2044;
loc_822F2010:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82205248
	ctx.lr = 0x822F2018;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f2034
	if (cr6.eq) goto loc_822F2034;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lfs f0,512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 512);
	f0.f64 = double(temp.f32);
	// b 0x822f203c
	goto loc_822F203C;
loc_822F2034:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_822F203C:
	// lfs f13,14372(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 14372);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
loc_822F2044:
	// lwz r11,14572(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 14572);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r6,5
	ctx.r6.s64 = 5;
	// rlwinm r7,r11,16,24,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// lwz r3,14696(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 14696);
	// rlwinm r5,r11,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// fcfid f7,f12
	ctx.f7.f64 = double(ctx.f12.s64);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f11
	ctx.f8.f64 = double(ctx.f11.s64);
	// lfs f13,15364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	ctx.f13.f64 = double(temp.f32);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// li r5,1
	ctx.r5.s64 = 1;
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// fmuls f3,f6,f13
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f13.f64));
	// fmuls f2,f5,f13
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// fmuls f1,f4,f13
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f13.f64));
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
	// fmuls f11,f1,f0
	ctx.f11.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x8218aef8
	ctx.lr = 0x822F20C8;
	sub_8218AEF8(ctx, base);
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

__attribute__((alias("__imp__sub_822F20DC"))) PPC_WEAK_FUNC(sub_822F20DC);
PPC_FUNC_IMPL(__imp__sub_822F20DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F20E0"))) PPC_WEAK_FUNC(sub_822F20E0);
PPC_FUNC_IMPL(__imp__sub_822F20E0) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lbz r11,14546(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r8,14572(r3)
	PPC_STORE_U32(ctx.r3.u32 + 14572, ctx.r8.u32);
	// bne cr6,0x822f2128
	if (!cr6.eq) goto loc_822F2128;
	// bl 0x822f10d0
	ctx.lr = 0x822F2104;
	sub_822F10D0(ctx, base);
	// lfs f0,14568(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822f2120
	if (cr6.gt) goto loc_822F2120;
	// bl 0x822f10d0
	ctx.lr = 0x822F2114;
	sub_822F10D0(ctx, base);
	// lfs f0,14564(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14564);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822f2128
	if (!cr6.lt) goto loc_822F2128;
loc_822F2120:
	// li r11,1
	r11.s64 = 1;
	// b 0x822f212c
	goto loc_822F212C;
loc_822F2128:
	// li r11,0
	r11.s64 = 0;
loc_822F212C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f2148
	if (cr6.eq) goto loc_822F2148;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r11,-7568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7568);
	// lfs f0,512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 512);
	f0.f64 = double(temp.f32);
	// b 0x822f2150
	goto loc_822F2150;
loc_822F2148:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_822F2150:
	// rlwinm r9,r8,16,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFF;
	// lfs f13,14372(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14372);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r7,r8,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 24) & 0xFF;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// frsp f5,f8
	ctx.f5.f64 = double(float(ctx.f8.f64));
	// lfs f0,15364(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 15364);
	f0.f64 = double(temp.f32);
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// li r6,5
	ctx.r6.s64 = 5;
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,14700(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14700);
	// fmuls f2,f5,f0
	ctx.f2.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmuls f1,f4,f0
	ctx.f1.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fmuls f0,f3,f0
	f0.f64 = double(float(ctx.f3.f64 * f0.f64));
	// fmuls f13,f2,f12
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmuls f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmuls f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 * ctx.f12.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x8218aef8
	ctx.lr = 0x822F21D8;
	sub_8218AEF8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F21E8"))) PPC_WEAK_FUNC(sub_822F21E8);
PPC_FUNC_IMPL(__imp__sub_822F21E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// li r11,32
	r11.s64 = 32;
	// lbz r10,92(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 92);
	// li r9,48
	ctx.r9.s64 = 48;
	// lbz r8,156(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 156);
	// li r7,256
	ctx.r7.s64 = 256;
	// lbz r5,93(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 93);
	// li r6,272
	ctx.r6.s64 = 272;
	// lfs f0,80(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	f0.f64 = double(temp.f32);
	// li r4,64
	ctx.r4.s64 = 64;
	// lfs f13,84(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r10,316(r3)
	PPC_STORE_U8(ctx.r3.u32 + 316, ctx.r10.u8);
	// lvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r8,380(r3)
	PPC_STORE_U8(ctx.r3.u32 + 380, ctx.r8.u8);
	// stvx128 v63,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,94(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 94);
	// stvx128 v62,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,157(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 157);
	// lvx128 v61,r3,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r6,r10
	ctx.r6.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lbz r9,158(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 158);
	// li r4,96
	ctx.r4.s64 = 96;
	// lfs f12,88(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// li r11,112
	r11.s64 = 112;
	// lfs f11,144(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// li r10,128
	ctx.r10.s64 = 128;
	// lfs f10,148(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// cntlzw r8,r5
	ctx.r8.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// lfs f9,152(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// cntlzw r5,r9
	ctx.r5.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stfs f0,304(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 304, temp.u32);
	// lvx128 v60,r3,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,320
	ctx.r4.s64 = 320;
	// lvx128 v59,r3,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,336
	r11.s64 = 336;
	// lvx128 v58,r3,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,288
	ctx.r9.s64 = 288;
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stfs f13,308(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 308, temp.u32);
	// rlwinm r7,r7,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stfs f12,312(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 312, temp.u32);
	// li r10,352
	ctx.r10.s64 = 352;
	// stvx128 v60,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r6,r6,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// stfs f11,368(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 368, temp.u32);
	// rlwinm r5,r5,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stfs f10,372(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 372, temp.u32);
	// li r31,224
	r31.s64 = 224;
	// stfs f9,376(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 376, temp.u32);
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// stvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// xori r7,r7,1
	ctx.r7.u64 = ctx.r7.u64 ^ 1;
	// stvx128 v59,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// xori r6,r6,1
	ctx.r6.u64 = ctx.r6.u64 ^ 1;
	// stb r8,317(r3)
	PPC_STORE_U8(ctx.r3.u32 + 317, ctx.r8.u8);
	// xori r5,r5,1
	ctx.r5.u64 = ctx.r5.u64 ^ 1;
	// stb r7,318(r3)
	PPC_STORE_U8(ctx.r3.u32 + 318, ctx.r7.u8);
	// stb r6,381(r3)
	PPC_STORE_U8(ctx.r3.u32 + 381, ctx.r6.u8);
	// stvx128 v58,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r5,382(r3)
	PPC_STORE_U8(ctx.r3.u32 + 382, ctx.r5.u8);
	// lvx128 v57,r3,r31
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,448
	ctx.r4.s64 = 448;
	// lhz r11,240(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 240);
	// sth r11,464(r3)
	PPC_STORE_U16(ctx.r3.u32 + 464, r11.u16);
	// stvx128 v57,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F22FC"))) PPC_WEAK_FUNC(sub_822F22FC);
PPC_FUNC_IMPL(__imp__sub_822F22FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F2300"))) PPC_WEAK_FUNC(sub_822F2300);
PPC_FUNC_IMPL(__imp__sub_822F2300) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,317(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 317);
	// li r10,272
	ctx.r10.s64 = 272;
	// li r9,288
	ctx.r9.s64 = 288;
	// lbz r8,316(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 316);
	// cntlzw r7,r11
	ctx.r7.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// lbz r6,380(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 380);
	// li r5,48
	ctx.r5.s64 = 48;
	// lfs f0,304(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 304);
	f0.f64 = double(temp.f32);
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lfs f13,308(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// li r11,64
	r11.s64 = 64;
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// lvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r8,92(r3)
	PPC_STORE_U8(ctx.r3.u32 + 92, ctx.r8.u8);
	// li r7,256
	ctx.r7.s64 = 256;
	// stb r6,156(r3)
	PPC_STORE_U8(ctx.r3.u32 + 156, ctx.r6.u8);
	// stvx128 v63,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r10,93(r3)
	PPC_STORE_U8(ctx.r3.u32 + 93, ctx.r10.u8);
	// li r10,320
	ctx.r10.s64 = 320;
	// stvx128 v62,r3,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,318(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 318);
	// lbz r8,381(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 381);
	// addi r30,r3,32
	r30.s64 = ctx.r3.s64 + 32;
	// cntlzw r5,r9
	ctx.r5.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lbz r6,382(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 382);
	// cntlzw r4,r8
	ctx.r4.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lvx128 v61,r3,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,336
	ctx.r9.s64 = 336;
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,352
	ctx.r8.s64 = 352;
	// lfs f12,312(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 312);
	ctx.f12.f64 = double(temp.f32);
	// cntlzw r11,r6
	r11.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// lfs f11,368(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	ctx.f11.f64 = double(temp.f32);
	// rlwinm r7,r5,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// lfs f10,372(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	ctx.f10.f64 = double(temp.f32);
	// li r6,96
	ctx.r6.s64 = 96;
	// lfs f9,376(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	ctx.f9.f64 = double(temp.f32);
	// lvx128 v59,r3,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,112
	ctx.r5.s64 = 112;
	// lvx128 v58,r3,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r10,128
	ctx.r10.s64 = 128;
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// rlwinm r9,r4,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stfs f13,84(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// li r4,448
	ctx.r4.s64 = 448;
	// stvx128 v60,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// stvx128 v59,r3,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// xori r9,r9,1
	ctx.r9.u64 = ctx.r9.u64 ^ 1;
	// stfs f12,88(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// xori r8,r8,1
	ctx.r8.u64 = ctx.r8.u64 ^ 1;
	// stb r11,94(r3)
	PPC_STORE_U8(ctx.r3.u32 + 94, r11.u8);
	// stfs f11,144(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// stb r9,157(r3)
	PPC_STORE_U8(ctx.r3.u32 + 157, ctx.r9.u8);
	// stfs f10,148(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 148, temp.u32);
	// stb r8,158(r3)
	PPC_STORE_U8(ctx.r3.u32 + 158, ctx.r8.u8);
	// stfs f9,152(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// li r6,224
	ctx.r6.s64 = 224;
	// stvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// stvx128 v58,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lhz r7,464(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 464);
	// lvx128 v57,r3,r4
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r7,240(r3)
	PPC_STORE_U16(ctx.r3.u32 + 240, ctx.r7.u16);
	// lis r31,-32131
	r31.s64 = -2105737216;
	// stvx128 v57,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,3
	r11.s64 = 3;
	// lwz r10,-25604(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -25604);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// stw r11,17320(r31)
	PPC_STORE_U32(r31.u32 + 17320, r11.u32);
	// ble cr6,0x822f2448
	if (!cr6.gt) goto loc_822F2448;
	// li r4,3
	ctx.r4.s64 = 3;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822F2444;
	sub_8217F768(ctx, base);
	// lwz r11,17320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17320);
loc_822F2448:
	// li r4,3
	ctx.r4.s64 = 3;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bge cr6,0x822f2458
	if (!cr6.lt) goto loc_822F2458;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_822F2458:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822F2460;
	sub_8217F768(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821800a0
	ctx.lr = 0x822F2468;
	sub_821800A0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,3528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f2488
	if (cr6.eq) goto loc_822F2488;
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822f2488
	if (cr6.eq) goto loc_822F2488;
	// bl 0x822dbd70
	ctx.lr = 0x822F2488;
	sub_822DBD70(ctx, base);
loc_822F2488:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7436(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// bl 0x822f7ce0
	ctx.lr = 0x822F2494;
	sub_822F7CE0(ctx, base);
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

__attribute__((alias("__imp__sub_822F24AC"))) PPC_WEAK_FUNC(sub_822F24AC);
PPC_FUNC_IMPL(__imp__sub_822F24AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F24B0"))) PPC_WEAK_FUNC(sub_822F24B0);
PPC_FUNC_IMPL(__imp__sub_822F24B0) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f13,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,224(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,228(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// stfs f13,232(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// stfs f13,236(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 236, temp.u32);
	// stfs f0,64(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f0,132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f0,136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f0,192(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stfs f0,196(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f0,200(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// lwz r11,17320(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17320);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822f2520
	if (!cr6.lt) goto loc_822F2520;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_822F2520:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822F2528;
	sub_8217F768(ctx, base);
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x821800a0
	ctx.lr = 0x822F2530;
	sub_821800A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217d928
	ctx.lr = 0x822F2538;
	sub_8217D928(ctx, base);
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

__attribute__((alias("__imp__sub_822F254C"))) PPC_WEAK_FUNC(sub_822F254C);
PPC_FUNC_IMPL(__imp__sub_822F254C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F2550"))) PPC_WEAK_FUNC(sub_822F2550);
PPC_FUNC_IMPL(__imp__sub_822F2550) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r15{};
	PPCRegister r17{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v50{};
	PPCVRegister v51{};
	PPCVRegister v53{};
	PPCVRegister v54{};
	PPCVRegister v55{};
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
	ctx.lr = 0x822F2558;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
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
	// bl 0x822fe3a8
	ctx.lr = 0x822F2578;
	sub_822FE3A8(ctx, base);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// addi r10,r11,8512
	ctx.r10.s64 = r11.s64 + 8512;
	// lwz r29,-7436(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + -7436);
	// lwz r7,8(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bne cr6,0x822f25a0
	if (!cr6.eq) goto loc_822F25A0;
	// li r8,3
	ctx.r8.s64 = 3;
	// b 0x822f25dc
	goto loc_822F25DC;
loc_822F25A0:
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
loc_822F25A8:
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpw cr6,r30,r6
	cr6.compare<int32_t>(r30.s32, ctx.r6.s32, xer);
	// blt cr6,0x822f25c0
	if (cr6.lt) goto loc_822F25C0;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r30,r6
	cr6.compare<int32_t>(r30.s32, ctx.r6.s32, xer);
	// blt cr6,0x822f25d8
	if (cr6.lt) goto loc_822F25D8;
loc_822F25C0:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x822f25a8
	if (cr6.lt) goto loc_822F25A8;
	// b 0x822f25dc
	goto loc_822F25DC;
loc_822F25D8:
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
loc_822F25DC:
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r8,3
	cr6.compare<uint32_t>(ctx.r8.u32, 3, xer);
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// subf r30,r10,r30
	r30.s64 = r30.s64 - ctx.r10.s64;
	// bgt cr6,0x822f2800
	if (cr6.gt) goto loc_822F2800;
	// lis r12,-32209
	r12.s64 = -2110849024;
	// addi r12,r12,9736
	r12.s64 = r12.s64 + 9736;
	// rlwinm r0,r8,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r8.u64) {
	case 0:
		goto loc_822F2618;
	case 1:
		goto loc_822F269C;
	case 2:
		goto loc_822F277C;
	case 3:
		goto loc_822F27F8;
	default:
		__builtin_unreachable();
	}
	// lwz r17,9752(r15)
	r17.u64 = PPC_LOAD_U32(r15.u32 + 9752);
	// lwz r17,9884(r15)
	r17.u64 = PPC_LOAD_U32(r15.u32 + 9884);
	// lwz r17,10108(r15)
	r17.u64 = PPC_LOAD_U32(r15.u32 + 10108);
	// lwz r17,10232(r15)
	r17.u64 = PPC_LOAD_U32(r15.u32 + 10232);
loc_822F2618:
	// lwz r11,48(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x822f1b08
	ctx.lr = 0x822F262C;
	sub_822F1B08(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// lvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lvx128 v62,r31,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	f31.f64 = double(temp.f32);
	// lfs f30,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f30.f64 = double(temp.f32);
	// bl 0x822fd198
	ctx.lr = 0x822F266C;
	sub_822FD198(ctx, base);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822fd4e0
	ctx.lr = 0x822F2688;
	sub_822FD4E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_822F269C:
	// li r28,16
	r28.s64 = 16;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x822f26ec
	if (!cr6.eq) goto loc_822F26EC;
	// lwz r11,576(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 576);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// addi r8,r9,9696
	ctx.r8.s64 = ctx.r9.s64 + 9696;
	// lvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,8(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f11,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f0,4(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	f0.f64 = double(temp.f32);
	// fmadds f9,f13,f0,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f10.f64));
	// lfs f0,9696(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 9696);
	f0.f64 = double(temp.f32);
	// fmadds f1,f12,f0,f9
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f9.f64));
	// b 0x822f2708
	goto loc_822F2708;
loc_822F26EC:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,576(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 576);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x822fd198
	ctx.lr = 0x822F2708;
	sub_822FD198(ctx, base);
loc_822F2708:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lfs f3,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f3.f64 = double(temp.f32);
	// li r10,32
	ctx.r10.s64 = 32;
	// lfs f2,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v59,r31,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,576(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 576);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lvx128 v58,r10,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,576(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 576);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd4e0
	ctx.lr = 0x822F2768;
	sub_822FD4E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_822F277C:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lvx128 v50,r0,r27
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f3,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r11,r30,6,0,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// lfs f2,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	ctx.f2.f64 = double(temp.f32);
	// li r10,32
	ctx.r10.s64 = 32;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lfs f0,3800(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3800);
	f0.f64 = double(temp.f32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// lvlx128 v55,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v55,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v53,r11,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vmaddfp128 v50,v53,v54,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v54.f32)), simde_mm_load_ps(v50.f32)));
	// lvx128 v51,r31,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r5,r11,64
	ctx.r5.s64 = r11.s64 + 64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,7444(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd4e0
	ctx.lr = 0x822F27E4;
	sub_822FD4E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_822F27F8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822fde80
	ctx.lr = 0x822F2800;
	sub_822FDE80(ctx, base);
loc_822F2800:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822F2814"))) PPC_WEAK_FUNC(sub_822F2814);
PPC_FUNC_IMPL(__imp__sub_822F2814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F2818"))) PPC_WEAK_FUNC(sub_822F2818);
PPC_FUNC_IMPL(__imp__sub_822F2818) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v62,99
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x9C));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vpermwi128 v0,v62,135
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x78));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vpermwi128 v61,v63,135
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x78));
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// vpermwi128 v13,v63,99
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x9C));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v59,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v59,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vmulfp128 v12,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v58,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// vnmsubfp v11,v13,v0,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stvx128 v11,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f1778
	ctx.lr = 0x822F2888;
	sub_822F1778(ctx, base);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v50,r0,r31
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r8,2240
	ctx.r6.s64 = ctx.r8.s64 + 2240;
	// lvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v63,v62
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v56,v63,v62
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmrghw128 v55,v61,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// vmrglw128 v54,v61,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// addi r9,r11,-31664
	ctx.r9.s64 = r11.s64 + -31664;
	// addi r5,r7,-31648
	ctx.r5.s64 = ctx.r7.s64 + -31648;
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// vmrghw128 v53,v57,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v52,v56,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// addi r10,r3,2528
	ctx.r10.s64 = ctx.r3.s64 + 2528;
	// vmrglw128 v51,v57,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmsum3fp128 v49,v50,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v48,v50,v52
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v47,v50,v51
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmrghw128 v46,v49,v48
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v45,v47,v46
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v44,v46,v45
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmsum3fp128 v43,v44,v44
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v44.f32), 0xEF));
	// stvx128 v44,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v42,v43
	simde_mm_store_ps(v42.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v43.f32))));
	// vor128 v9,v43,v43
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v43.u8));
	// vcmpeqfp128 v8,v42,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v62.f32)));
	// vor128 v7,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// vsel v0,v7,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vmulfp128 v6,v0,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v5,v63,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v4,v9,v6,v13
	simde_mm_store_ps(ctx.v4.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v3,v4,v5,v0
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v41,v44,v3
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(ctx.v3.f32)));
	// stvx128 v41,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_822F295C"))) PPC_WEAK_FUNC(sub_822F295C);
PPC_FUNC_IMPL(__imp__sub_822F295C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F2960"))) PPC_WEAK_FUNC(sub_822F2960);
PPC_FUNC_IMPL(__imp__sub_822F2960) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f0,f9,f8,f7
	f0.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fabs f6,f0
	ctx.f6.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f6,f13
	cr6.compare(ctx.f6.f64, ctx.f13.f64);
	// bge cr6,0x822f29c8
	if (!cr6.lt) goto loc_822F29C8;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x822f2a14
	goto loc_822F2A14;
loc_822F29C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f12,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// fsel f10,f11,f0,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// fsubs f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsel f1,f9,f12,f10
	ctx.f1.f64 = ctx.f9.f64 >= 0.0 ? ctx.f12.f64 : ctx.f10.f64;
	// bl 0x823dcb30
	ctx.lr = 0x822F29EC;
	sub_823DCB30(ctx, base);
	// frsp f8,f1
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// fmuls f1,f7,f31
	ctx.f1.f64 = double(float(ctx.f7.f64 * f31.f64));
	// bl 0x822f2818
	ctx.lr = 0x822F2A08;
	sub_822F2818(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822F2A14:
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

__attribute__((alias("__imp__sub_822F2A30"))) PPC_WEAK_FUNC(sub_822F2A30);
PPC_FUNC_IMPL(__imp__sub_822F2A30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v26{};
	PPCVRegister v27{};
	PPCVRegister v28{};
	PPCVRegister v29{};
	PPCVRegister v30{};
	PPCVRegister v31{};
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
	// bl 0x823d91d4
	ctx.lr = 0x822F2A38;
	// stfd f30,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f30.u64);
	// stfd f31,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r31,r19,72
	r31.s64 = r19.s64 + 72;
	// li r28,4
	r28.s64 = 4;
	// li r20,328
	r20.s64 = 328;
	// li r21,360
	r21.s64 = 360;
	// li r22,-40
	r22.s64 = -40;
	// li r23,344
	r23.s64 = 344;
	// li r24,-56
	r24.s64 = -56;
	// lis r25,-32130
	r25.s64 = -2105671680;
	// addi r26,r11,-31664
	r26.s64 = r11.s64 + -31664;
	// addi r30,r10,9796
	r30.s64 = ctx.r10.s64 + 9796;
loc_822F2A7C:
	// addi r29,r31,-72
	r29.s64 = r31.s64 + -72;
	// lvx128 v63,r0,r27
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r31,r20
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v62,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v13,r0,r26
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f1,9792(r25)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 9792);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f10,f0,f0
	ctx.f10.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// fmuls f9,f0,f0
	ctx.f9.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// fmadds f8,f13,f13,f10
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f7,f12,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fsqrts f31,f7
	f31.f64 = double(float(sqrt(ctx.f7.f64)));
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v60,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vrefp128 v0,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v59.f32)));
	// vor128 v12,v59,v59
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vnmsubfp v10,v0,v12,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v9,v0,v10,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v63,v9
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f6,f0,f0,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.f64 = double(float(f0.f64 * f0.f64 + ctx.f9.f64));
	// fmadds f5,f11,f11,f6
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f6.f64));
	// fsqrts f30,f5
	f30.f64 = double(float(sqrt(ctx.f5.f64)));
	// stfs f30,80(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v57,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vrefp128 v0,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v56.f32)));
	// vor128 v8,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// vnmsubfp v6,v0,v8,v13
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v5,v0,v6,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v55,v62,v5
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(ctx.v5.f32)));
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822f2960
	ctx.lr = 0x822F2B48;
	sub_822F2960(ctx, base);
	// fsubs f4,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(f30.f64 - f31.f64));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// lvx128 v0,r31,r22
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r31,r24
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lfs f2,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lfs f1,-4(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lfs f13,-8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,400(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 400);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,396(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f12,f2
	ctx.f10.f64 = double(float(ctx.f12.f64 - ctx.f2.f64));
	// lfs f9,392(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 392);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f11,f1
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f1.f64));
	// lvx128 v53,r31,r21
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f3,f4,f0,f31
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64 + f31.f64));
	// lvx128 v52,r31,r23
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lvlx128 v51,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsubfp128 v4,v53,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v4.f32, simde_mm_sub_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v50,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vsubfp128 v3,v52,v13
	simde_mm_store_ps(ctx.v3.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stfs f3,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vspltw128 v2,v51,0
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lvlx128 v54,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v31,v50,0
	simde_mm_store_si128((simde__m128i*)v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// lvx128 v1,r0,r27
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v29,v54,0
	simde_mm_store_si128((simde__m128i*)v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lvx128 v30,r0,r11
	simde_mm_store_si128((simde__m128i*)v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v28,v4,v2,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// vmaddfp v27,v3,v31,v13
	simde_mm_store_ps(v27.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// fmadds f3,f10,f0,f2
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f3.f64 = double(float(ctx.f10.f64 * f0.f64 + ctx.f2.f64));
	// vmaddfp v26,v30,v29,v1
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v26.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(v29.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmadds f2,f8,f0,f1
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f2.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f1.f64));
	// fmadds f1,f7,f0,f13
	ctx.f1.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stvx128 v28,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v27,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v26,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd4e0
	ctx.lr = 0x822F2C00;
	sub_822FD4E0(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// bne 0x822f2a7c
	if (!cr0.eq) goto loc_822F2A7C;
	// addi r11,r19,384
	r11.s64 = r19.s64 + 384;
	// li r10,784
	ctx.r10.s64 = 784;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r8,r9,9788
	ctx.r8.s64 = ctx.r9.s64 + 9788;
	// lvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r19,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v13,v49,v0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(ctx.v0.f32)));
	// lvlx128 v48,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v48,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f31,-120(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822F2C48"))) PPC_WEAK_FUNC(sub_822F2C48);
PPC_FUNC_IMPL(__imp__sub_822F2C48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x822F2C50;
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823db9d8
	ctx.lr = 0x822F2C58;
	// li r12,-176
	r12.s64 = -176;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r22,-32120
	r22.s64 = -2105016320;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lwz r11,-7436(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -7436);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r24,8(r11)
	r24.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8218f308
	ctx.lr = 0x822F2C94;
	sub_8218F308(ctx, base);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r31,-32131
	r31.s64 = -2105737216;
	// li r20,1
	r20.s64 = 1;
	// li r11,2
	r11.s64 = 2;
	// stb r20,476(r1)
	PPC_STORE_U8(ctx.r1.u32 + 476, r20.u8);
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,464(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// stw r11,17320(r31)
	PPC_STORE_U32(r31.u32 + 17320, r11.u32);
	// stfs f31,448(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// stfs f31,452(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f31,456(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// lwz r10,-25604(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25604);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// ble cr6,0x822f2ce0
	if (!cr6.gt) goto loc_822F2CE0;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822F2CDC;
	sub_8217F768(ctx, base);
	// lwz r11,17320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17320);
loc_822F2CE0:
	// li r4,2
	ctx.r4.s64 = 2;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bge cr6,0x822f2cf0
	if (!cr6.lt) goto loc_822F2CF0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
loc_822F2CF0:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8217f768
	ctx.lr = 0x822F2CF8;
	sub_8217F768(ctx, base);
	// addi r31,r21,32
	r31.s64 = r21.s64 + 32;
	// addi r11,r1,480
	r11.s64 = ctx.r1.s64 + 480;
	// addi r23,r31,192
	r23.s64 = r31.s64 + 192;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v63,r0,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f28,15364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15364);
	f28.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822f30b0
	if (cr6.eq) goto loc_822F30B0;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82205248
	ctx.lr = 0x822F2D28;
	sub_82205248(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f2f64
	if (!cr6.eq) goto loc_822F2F64;
	// lbz r11,14546(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 14546);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f2f64
	if (!cr6.eq) goto loc_822F2F64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,336(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lvx128 v0,r0,r25
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r31,64
	r29.s64 = r31.s64 + 64;
	// lfs f13,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,11412(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11412);
	f0.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r28,r31,32
	r28.s64 = r31.s64 + 32;
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v11,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lfs f29,3800(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3800);
	f29.f64 = double(temp.f32);
	// vmaddfp v8,v13,v11,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r27,r31,96
	r27.s64 = r31.s64 + 96;
	// lvlx128 v61,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvx128 v10,r0,r29
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,320
	ctx.r6.s64 = ctx.r1.s64 + 320;
	// vmaddfp v9,v10,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r5,r1,384
	ctx.r5.s64 = ctx.r1.s64 + 384;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// lfs f0,11364(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11364);
	f0.f64 = double(temp.f32);
	// addi r11,r1,368
	r11.s64 = ctx.r1.s64 + 368;
	// lvx128 v60,r0,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r27
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r20,348(r1)
	PPC_STORE_U8(ctx.r1.u32 + 348, r20.u8);
	// stfs f13,400(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// stfs f0,340(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f0,404(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v8,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821800a0
	ctx.lr = 0x822F2DE4;
	sub_821800A0(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vspltisw128 v126,0
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v56,r0,r31
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lvx128 v54,r0,r25
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f1,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f1.f64 = double(temp.f32);
	// lvlx128 v58,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v55,v56,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v55.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// lfs f30,30284(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30284);
	f30.f64 = double(temp.f32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// addi r3,r30,400
	ctx.r3.s64 = r30.s64 + 400;
	// vsubfp128 v53,v126,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v55.f32)));
	// vaddfp128 v52,v54,v55
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v53,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd4e0
	ctx.lr = 0x822F2E44;
	sub_822FD4E0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f29,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v49,r0,r29
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lfs f1,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// lvx128 v48,r0,r25
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// lvlx128 v51,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// vmulfp128 v63,v49,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v50.f32)));
	// fmr f2,f30
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f2.f64 = f30.f64;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r30,496
	ctx.r3.s64 = r30.s64 + 496;
	// vsubfp128 v47,v126,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v63.f32)));
	// vaddfp128 v46,v48,v63
	simde_mm_store_ps(v46.f32, simde_mm_add_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v63.f32)));
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd4e0
	ctx.lr = 0x822F2EA0;
	sub_822FD4E0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v45,r0,r25
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f31,128(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v44,v45,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v44.f32, simde_mm_add_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v127.f32)));
	// vsubfp128 v126,v126,v127
	simde_mm_store_ps(v126.f32, simde_mm_sub_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v127.f32)));
	// stfs f31,132(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r30,592
	ctx.r3.s64 = r30.s64 + 592;
	// stvx128 v44,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd4e0
	ctx.lr = 0x822F2F04;
	sub_822FD4E0(ctx, base);
	// lvx128 v43,r0,r25
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v42,v43,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v42.f32, simde_mm_add_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v127.f32)));
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stfs f31,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// stvx128 v126,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r30,688
	ctx.r3.s64 = r30.s64 + 688;
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stvx128 v42,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822fd4e0
	ctx.lr = 0x822F2F48;
	sub_822FD4E0(ctx, base);
	// lfs f12,232(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 232);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,228(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 228);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,224(r21)
	temp.u32 = PPC_LOAD_U32(r21.u32 + 224);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,784(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 784, temp.u32);
	// stfs f11,788(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 788, temp.u32);
	// stfs f12,792(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 792, temp.u32);
	// b 0x822f30b0
	goto loc_822F30B0;
loc_822F2F64:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r3,-7436(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -7436);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822f7590
	ctx.lr = 0x822F2F74;
	sub_822F7590(ctx, base);
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// addi r28,r30,800
	r28.s64 = r30.s64 + 800;
	// addi r26,r30,400
	r26.s64 = r30.s64 + 400;
	// li r29,4
	r29.s64 = 4;
loc_822F2F84:
	// lhz r19,0(r27)
	r19.u64 = PPC_LOAD_U16(r27.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r11,48(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 48);
	// rotlwi r10,r19,2
	ctx.r10.u64 = __builtin_rotateleft32(r19.u32, 2);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x822f1b08
	ctx.lr = 0x822F2F9C;
	sub_822F1B08(ctx, base);
	// stw r19,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r19.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// addi r27,r27,2
	r27.s64 = r27.s64 + 2;
	// addi r26,r26,96
	r26.s64 = r26.s64 + 96;
	// bne 0x822f2f84
	if (!cr0.eq) goto loc_822F2F84;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-17600(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -17600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f30b0
	if (cr6.eq) goto loc_822F30B0;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-17596(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -17596);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822f30b0
	if (cr6.eq) goto loc_822F30B0;
	// addi r5,r1,124
	ctx.r5.s64 = ctx.r1.s64 + 124;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82689ee8
	ctx.lr = 0x822F2FE0;
	sub_82689EE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f30b0
	if (cr6.eq) goto loc_822F30B0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lwz r11,124(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// rlwinm r5,r11,24,24,31
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// rlwinm r3,r11,16,24,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// lfs f0,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	f0.f64 = double(temp.f32);
	// std r4,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r4.u64);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfd f0,112(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// std r3,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r3.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r30,784
	r11.s64 = r30.s64 + 784;
	// lfd f12,112(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// lvlx128 v41,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v40,v41,0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), 0xFF));
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// li r9,14372
	ctx.r9.s64 = 14372;
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// lvlx128 v39,r21,r9
	temp.u32 = r21.u32 + ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v38,v39,0
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), 0xFF));
	// frsp f8,f11
	ctx.f8.f64 = double(float(ctx.f11.f64));
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f5,f8,f28
	ctx.f5.f64 = double(float(ctx.f8.f64 * f28.f64));
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f4,f7,f28
	ctx.f4.f64 = double(float(ctx.f7.f64 * f28.f64));
	// stfs f4,100(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmuls f3,f6,f28
	ctx.f3.f64 = double(float(ctx.f6.f64 * f28.f64));
	// stfs f3,104(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v37,r0,r10
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v36,v37,v40
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v40.f32)));
	// vmulfp128 v35,v36,v38
	simde_mm_store_ps(v35.f32, simde_mm_mul_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v38.f32)));
	// stvx128 v35,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,788(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 788);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,792(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 792);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,784(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 784);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,784(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 784, temp.u32);
	// lfs f11,196(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 196);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f2
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f2.f64));
	// stfs f10,788(r30)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r30.u32 + 788, temp.u32);
	// lfs f9,200(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 200);
	ctx.f9.f64 = double(temp.f32);
	// fadds f8,f9,f1
	ctx.f8.f64 = double(float(ctx.f9.f64 + ctx.f1.f64));
	// stfs f8,792(r30)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r30.u32 + 792, temp.u32);
loc_822F30B0:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822f2a30
	ctx.lr = 0x822F30BC;
	sub_822F2A30(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// mr r29,r30
	r29.u64 = r30.u64;
loc_822F30C4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-7436(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -7436);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822f7478
	ctx.lr = 0x822F30D4;
	sub_822F7478(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,96
	r29.s64 = r29.s64 + 96;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// blt cr6,0x822f30c4
	if (cr6.lt) goto loc_822F30C4;
	// lwz r11,-7436(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -7436);
	// li r28,3
	r28.s64 = 3;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r11,576
	r29.s64 = r11.s64 + 576;
	// lhz r11,580(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 580);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f31b0
	if (cr6.eq) goto loc_822F31B0;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r26,208
	r26.s64 = 208;
	// addi r27,r11,9696
	r27.s64 = r11.s64 + 9696;
loc_822F310C:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bne cr6,0x822f314c
	if (!cr6.eq) goto loc_822F314C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,8(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v34,r11,r26
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmadds f7,f11,f13,f9
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f9.f64));
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f1,f8,f12,f7
	ctx.f1.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// b 0x822f3168
	goto loc_822F3168;
loc_822F314C:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x822fd198
	ctx.lr = 0x822F3168;
	sub_822FD198(ctx, base);
loc_822F3168:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x822f31a0
	if (!cr6.gt) goto loc_822F31A0;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x822f31a0
	if (!cr6.gt) goto loc_822F31A0;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-7436(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -7436);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x822f7478
	ctx.lr = 0x822F319C;
	sub_822F7478(ctx, base);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
loc_822F31A0:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x822f310c
	if (cr6.lt) goto loc_822F310C;
loc_822F31B0:
	// addi r4,r30,384
	ctx.r4.s64 = r30.s64 + 384;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// bl 0x821d2398
	ctx.lr = 0x822F31BC;
	sub_821D2398(ctx, base);
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lbz r8,14546(r21)
	ctx.r8.u64 = PPC_LOAD_U8(r21.u32 + 14546);
	// rlwinm r7,r11,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 24) & 0xFF;
	// clrlwi r6,r11,24
	ctx.r6.u64 = r11.u32 & 0xFF;
	// std r7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// rlwinm r3,r11,8,24,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 8) & 0xFF;
	// rlwinm r11,r11,16,24,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0xFF;
	// std r3,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r3.u64);
	// lfd f10,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfd f0,96(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// fcfid f9,f13
	ctx.f9.f64 = double(ctx.f13.s64);
	// lfd f12,96(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f8,f0
	ctx.f8.f64 = double(f0.s64);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f6,f11
	ctx.f6.f64 = double(float(ctx.f11.f64));
	// fmuls f1,f5,f28
	ctx.f1.f64 = double(float(ctx.f5.f64 * f28.f64));
	// stfs f1,488(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// fmuls f13,f3,f28
	ctx.f13.f64 = double(float(ctx.f3.f64 * f28.f64));
	// stfs f13,492(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// fmuls f0,f4,f28
	f0.f64 = double(float(ctx.f4.f64 * f28.f64));
	// stfs f0,484(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// fmuls f2,f6,f28
	ctx.f2.f64 = double(float(ctx.f6.f64 * f28.f64));
	// stfs f2,480(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// bne cr6,0x822f32a4
	if (!cr6.eq) goto loc_822F32A4;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,22080(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 22080);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// bne cr6,0x822f3260
	if (!cr6.eq) goto loc_822F3260;
	// li r10,2
	ctx.r10.s64 = 2;
loc_822F3260:
	// addi r10,r10,3633
	ctx.r10.s64 = ctx.r10.s64 + 3633;
	// lfs f0,14568(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 14568);
	f0.f64 = double(temp.f32);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r7,r21
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r21.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x822f329c
	if (cr6.gt) goto loc_822F329C;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822f3284
	if (!cr6.eq) goto loc_822F3284;
	// li r11,2
	r11.s64 = 2;
loc_822F3284:
	// addi r11,r11,3633
	r11.s64 = r11.s64 + 3633;
	// lfs f0,14564(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r21.u32 + 14564);
	f0.f64 = double(temp.f32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r10,r21
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r21.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822f32a4
	if (!cr6.lt) goto loc_822F32A4;
loc_822F329C:
	// mr r11,r20
	r11.u64 = r20.u64;
	// b 0x822f32a8
	goto loc_822F32A8;
loc_822F32A4:
	// li r11,0
	r11.s64 = 0;
loc_822F32A8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f32bc
	if (!cr6.eq) goto loc_822F32BC;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822f32c4
	if (cr6.eq) goto loc_822F32C4;
loc_822F32BC:
	// lwz r3,-7436(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -7436);
	// bl 0x822f7198
	ctx.lr = 0x822F32C4;
	sub_822F7198(ctx, base);
loc_822F32C4:
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x821800a0
	ctx.lr = 0x822F32CC;
	sub_821800A0(ctx, base);
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// li r0,-176
	r0.s64 = -176;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-112
	r12.s64 = ctx.r1.s64 + -112;
	// bl 0x823dba24
	ctx.lr = 0x822F32E8;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_822F32EC"))) PPC_WEAK_FUNC(sub_822F32EC);
PPC_FUNC_IMPL(__imp__sub_822F32EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F32F0"))) PPC_WEAK_FUNC(sub_822F32F0);
PPC_FUNC_IMPL(__imp__sub_822F32F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r10,208
	ctx.r10.s64 = 208;
	// lwz r11,-7436(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7436);
	// lwz r9,576(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lvx128 v63,r9,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F330C"))) PPC_WEAK_FUNC(sub_822F330C);
PPC_FUNC_IMPL(__imp__sub_822F330C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F3310"))) PPC_WEAK_FUNC(sub_822F3310);
PPC_FUNC_IMPL(__imp__sub_822F3310) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// stb r6,-7588(r10)
	PPC_STORE_U8(ctx.r10.u32 + -7588, ctx.r6.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822F3330"))) PPC_WEAK_FUNC(sub_822F3330);
PPC_FUNC_IMPL(__imp__sub_822F3330) {
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
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lwz r11,-7568(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7568);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f3438
	if (cr6.eq) goto loc_822F3438;
	// lis r30,-32120
	r30.s64 = -2105016320;
	// lwz r11,-7372(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7372);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f3438
	if (cr6.eq) goto loc_822F3438;
	// li r5,1024
	ctx.r5.s64 = 1024;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dbe0
	ctx.lr = 0x822F3374;
	sub_8261DBE0(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,1608
	ctx.r10.s64 = r11.s64 + 1608;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lwz r31,-7568(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -7568);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822F3398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,1588
	ctx.r4.s64 = ctx.r7.s64 + 1588;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dde8
	ctx.lr = 0x822F33AC;
	sub_8261DDE8(ctx, base);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r31,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, r31.u32);
	// lwz r31,-7372(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -7372);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x822F33CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,1572
	ctx.r4.s64 = r11.s64 + 1572;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dde8
	ctx.lr = 0x822F33E0;
	sub_8261DDE8(ctx, base);
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r8,r10,-7536
	ctx.r8.s64 = ctx.r10.s64 + -7536;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r10,5276
	ctx.r5.s64 = ctx.r10.s64 + 5276;
	// stw r31,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r31.u32);
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,2828(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// beq cr6,0x822f3424
	if (cr6.eq) goto loc_822F3424;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r4,r9,1532
	ctx.r4.s64 = ctx.r9.s64 + 1532;
	// b 0x822f342c
	goto loc_822F342C;
loc_822F3424:
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r4,r9,1504
	ctx.r4.s64 = ctx.r9.s64 + 1504;
loc_822F342C:
	// bl 0x821c04b0
	ctx.lr = 0x822F3430;
	sub_821C04B0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8261dca8
	ctx.lr = 0x822F3438;
	sub_8261DCA8(ctx, base);
loc_822F3438:
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

__attribute__((alias("__imp__sub_822F3450"))) PPC_WEAK_FUNC(sub_822F3450);
PPC_FUNC_IMPL(__imp__sub_822F3450) {
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
	// li r3,624
	ctx.r3.s64 = 624;
	// bl 0x82130528
	ctx.lr = 0x822F3464;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f3480
	if (cr6.eq) goto loc_822F3480;
	// bl 0x822f1c90
	ctx.lr = 0x822F3470;
	sub_822F1C90(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822F3480:
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

__attribute__((alias("__imp__sub_822F3494"))) PPC_WEAK_FUNC(sub_822F3494);
PPC_FUNC_IMPL(__imp__sub_822F3494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822F3498"))) PPC_WEAK_FUNC(sub_822F3498);
PPC_FUNC_IMPL(__imp__sub_822F3498) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822F34A0;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r10,r11,1488
	ctx.r10.s64 = r11.s64 + 1488;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8218f308
	ctx.lr = 0x822F34CC;
	sub_8218F308(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8218f308
	ctx.lr = 0x822F34D8;
	sub_8218F308(ctx, base);
	// addi r29,r31,496
	r29.s64 = r31.s64 + 496;
	// li r30,7
	r30.s64 = 7;
loc_822F34E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82300420
	ctx.lr = 0x822F34E8;
	sub_82300420(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,1552
	r29.s64 = r29.s64 + 1552;
	// bge 0x822f34e0
	if (!cr0.lt) goto loc_822F34E0;
	// addi r3,r31,12912
	ctx.r3.s64 = r31.s64 + 12912;
	// bl 0x82300420
	ctx.lr = 0x822F34FC;
	sub_82300420(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// addi r11,r31,14464
	r11.s64 = r31.s64 + 14464;
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_822F3510:
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bdnz 0x822f3510
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822F3510;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,14528(r31)
	PPC_STORE_U32(r31.u32 + 14528, r30.u32);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r4,r31,14540
	ctx.r4.s64 = r31.s64 + 14540;
	// addi r29,r11,-7516
	r29.s64 = r11.s64 + -7516;
	// lfs f0,32668(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32668);
	f0.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stfs f0,14540(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14540, temp.u32);
	// stfs f0,14536(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14536, temp.u32);
	// stfs f0,14532(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14532, temp.u32);
	// bl 0x821c07c0
	ctx.lr = 0x822F3548;
	sub_821C07C0(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r9,-13452
	ctx.r3.s64 = ctx.r9.s64 + -13452;
	// bl 0x821c0750
	ctx.lr = 0x822F355C;
	sub_821C0750(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// stw r11,-7884(r8)
	PPC_STORE_U32(ctx.r8.u32 + -7884, r11.u32);
	// bl 0x822e8a78
	ctx.lr = 0x822F356C;
	sub_822E8A78(ctx, base);
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r30,14546(r31)
	PPC_STORE_U8(r31.u32 + 14546, r30.u8);
	// addi r6,r7,-7496
	ctx.r6.s64 = ctx.r7.s64 + -7496;
	// stb r10,14545(r31)
	PPC_STORE_U8(r31.u32 + 14545, ctx.r10.u8);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822f359c
	if (!cr6.eq) goto loc_822F359C;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// beq cr6,0x822f35a0
	if (cr6.eq) goto loc_822F35A0;
loc_822F359C:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_822F35A0:
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// stb r11,14545(r31)
	PPC_STORE_U8(r31.u32 + 14545, r11.u8);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stb r10,14544(r31)
	PPC_STORE_U8(r31.u32 + 14544, ctx.r10.u8);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r30,14552(r31)
	PPC_STORE_U8(r31.u32 + 14552, r30.u8);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stb r30,14584(r31)
	PPC_STORE_U8(r31.u32 + 14584, r30.u8);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,12196(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12196);
	f0.f64 = double(temp.f32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// lfs f13,1752(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 1752);
	ctx.f13.f64 = double(temp.f32);
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,-31376(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31376);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f29,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	f29.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f0,14548(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14548, temp.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stfs f13,14568(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 14568, temp.u32);
	// lis r29,-32255
	r29.s64 = -2113863680;
	// stfs f12,14564(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 14564, temp.u32);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// stfs f31,14556(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 14556, temp.u32);
	// stfs f29,4(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// li r27,3
	r27.s64 = 3;
	// lfs f0,1748(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 1748);
	f0.f64 = double(temp.f32);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lfs f13,-26228(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -26228);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// stfs f0,14596(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14596, temp.u32);
	// li r3,624
	ctx.r3.s64 = 624;
	// stfs f13,14600(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 14600, temp.u32);
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// stfs f30,14592(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 14592, temp.u32);
	// lfs f0,30712(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	f0.f64 = double(temp.f32);
	// lfs f13,-26872(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -26872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1744(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 1744);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,12880(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 12880);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,31020(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 31020);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,14608(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14608, temp.u32);
	// stfs f13,14612(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 14612, temp.u32);
	// stfs f12,14616(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 14616, temp.u32);
	// stfs f11,14620(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 14620, temp.u32);
	// stfs f10,14624(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 14624, temp.u32);
	// stfs f31,14640(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 14640, temp.u32);
	// stfs f31,14644(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 14644, temp.u32);
	// stfs f30,14648(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 14648, temp.u32);
	// lfs f0,14884(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f30,14656(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 14656, temp.u32);
	// stfs f31,14660(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 14660, temp.u32);
	// stfs f31,14664(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 14664, temp.u32);
	// stw r27,14680(r31)
	PPC_STORE_U32(r31.u32 + 14680, r27.u32);
	// stfs f0,14672(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14672, temp.u32);
	// stfs f0,14676(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14676, temp.u32);
	// stb r11,-7588(r4)
	PPC_STORE_U8(ctx.r4.u32 + -7588, r11.u8);
	// stfs f30,14708(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 14708, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x822F3694;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f36ac
	if (cr6.eq) goto loc_822F36AC;
	// bl 0x822f1c90
	ctx.lr = 0x822F36A0;
	sub_822F1C90(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r3,-7568(r11)
	PPC_STORE_U32(r11.u32 + -7568, ctx.r3.u32);
	// b 0x822f36b4
	goto loc_822F36B4;
loc_822F36AC:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r30,-7568(r11)
	PPC_STORE_U32(r11.u32 + -7568, r30.u32);
loc_822F36B4:
	// lis r30,-32125
	r30.s64 = -2105344000;
	// lwz r11,2828(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f36d4
	if (cr6.eq) goto loc_822F36D4;
	// bl 0x821bbea8
	ctx.lr = 0x822F36D4;
	sub_821BBEA8(ctx, base);
loc_822F36D4:
	// bl 0x82301a80
	ctx.lr = 0x822F36D8;
	sub_82301A80(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822f36e4
	if (cr6.eq) goto loc_822F36E4;
	// bl 0x821bbf00
	ctx.lr = 0x822F36E4;
	sub_821BBF00(ctx, base);
loc_822F36E4:
	// lwz r11,2828(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f3700
	if (cr6.eq) goto loc_822F3700;
	// bl 0x821bbea8
	ctx.lr = 0x822F3700;
	sub_821BBEA8(ctx, base);
loc_822F3700:
	// bl 0x824970b0
	ctx.lr = 0x822F3704;
	sub_824970B0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822f3710
	if (cr6.eq) goto loc_822F3710;
	// bl 0x821bbf00
	ctx.lr = 0x822F3710;
	sub_821BBF00(ctx, base);
loc_822F3710:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stfs f30,224(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// stfs f30,228(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r27,r11,6912
	r27.s64 = r11.s64 + 6912;
	// stfs f30,232(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// stfs f30,236(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 236, temp.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stfs f31,64(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// addi r29,r31,6704
	r29.s64 = r31.s64 + 6704;
	// stfs f31,68(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// mr r30,r27
	r30.u64 = r27.u64;
	// stfs f31,72(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// addi r26,r11,1720
	r26.s64 = r11.s64 + 1720;
	// stfs f31,128(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// addi r25,r10,1732
	r25.s64 = ctx.r10.s64 + 1732;
	// stfs f31,132(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f31,136(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// stfs f31,192(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stfs f31,196(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f31,200(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
loc_822F3764:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x822F3774;
	sub_823DC018(ctx, base);
	// addi r28,r29,-6208
	r28.s64 = r29.s64 + -6208;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823008d8
	ctx.lr = 0x822F3784;
	sub_823008D8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82300928
	ctx.lr = 0x822F378C;
	sub_82300928(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x823dc018
	ctx.lr = 0x822F379C;
	sub_823DC018(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823008d8
	ctx.lr = 0x822F37A8;
	sub_823008D8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82300928
	ctx.lr = 0x822F37B0;
	sub_82300928(ctx, base);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// addi r11,r27,16
	r11.s64 = r27.s64 + 16;
	// addi r29,r29,1552
	r29.s64 = r29.s64 + 1552;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822f3764
	if (cr6.lt) goto loc_822F3764;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stfs f29,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f31,14576(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 14576, temp.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r10,1704
	ctx.r3.s64 = ctx.r10.s64 + 1704;
	// lfs f0,-6172(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6172);
	f0.f64 = double(temp.f32);
	// stfs f0,14580(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 14580, temp.u32);
	// bl 0x8218a4e8
	ctx.lr = 0x822F37E8;
	sub_8218A4E8(ctx, base);
	// stw r3,14684(r31)
	PPC_STORE_U32(r31.u32 + 14684, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r9,1684
	ctx.r3.s64 = ctx.r9.s64 + 1684;
	// bl 0x8218a4e8
	ctx.lr = 0x822F37FC;
	sub_8218A4E8(ctx, base);
	// stw r3,14688(r31)
	PPC_STORE_U32(r31.u32 + 14688, ctx.r3.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r8,1668
	ctx.r3.s64 = ctx.r8.s64 + 1668;
	// bl 0x8218a4e8
	ctx.lr = 0x822F3810;
	sub_8218A4E8(ctx, base);
	// stw r3,14692(r31)
	PPC_STORE_U32(r31.u32 + 14692, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r7,1652
	ctx.r3.s64 = ctx.r7.s64 + 1652;
	// bl 0x8218a4e8
	ctx.lr = 0x822F3824;
	sub_8218A4E8(ctx, base);
	// stw r3,14696(r31)
	PPC_STORE_U32(r31.u32 + 14696, ctx.r3.u32);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r6,1636
	ctx.r3.s64 = ctx.r6.s64 + 1636;
	// bl 0x8218a4e8
	ctx.lr = 0x822F3838;
	sub_8218A4E8(ctx, base);
	// stw r3,14704(r31)
	PPC_STORE_U32(r31.u32 + 14704, ctx.r3.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r5,1620
	ctx.r3.s64 = ctx.r5.s64 + 1620;
	// bl 0x8218a4e8
	ctx.lr = 0x822F384C;
	sub_8218A4E8(ctx, base);
	// stw r3,14700(r31)
	PPC_STORE_U32(r31.u32 + 14700, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822f3330
	ctx.lr = 0x822F3858;
	sub_822F3330(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
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

__attribute__((alias("__imp__sub_822F3870"))) PPC_WEAK_FUNC(sub_822F3870);
PPC_FUNC_IMPL(__imp__sub_822F3870) {
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
	// bl 0x822f1d30
	ctx.lr = 0x822F3890;
	sub_822F1D30(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822f38a8
	if (cr6.eq) goto loc_822F38A8;
	// bl 0x82130588
	ctx.lr = 0x822F38A4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822F38A8:
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

__attribute__((alias("__imp__sub_822F38C0"))) PPC_WEAK_FUNC(sub_822F38C0);
PPC_FUNC_IMPL(__imp__sub_822F38C0) {
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
	// li r3,14720
	ctx.r3.s64 = 14720;
	// bl 0x82130528
	ctx.lr = 0x822F38D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822f38f8
	if (cr6.eq) goto loc_822F38F8;
	// bl 0x822f3498
	ctx.lr = 0x822F38E0;
	sub_822F3498(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r3,-7572(r11)
	PPC_STORE_U32(r11.u32 + -7572, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822F38F8:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-7572(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7572, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

