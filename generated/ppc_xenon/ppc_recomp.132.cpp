#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_826661A0"))) PPC_WEAK_FUNC(sub_826661A0);
PPC_FUNC_IMPL(__imp__sub_826661A0) {
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
	ctx.lr = 0x826661A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r29,r11,-4776
	r29.s64 = r11.s64 + -4776;
	// addi r4,r10,2516
	ctx.r4.s64 = ctx.r10.s64 + 2516;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x826661CC;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x826661E0;
	sub_823DB670(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-9136
	ctx.r4.s64 = ctx.r8.s64 + -9136;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x826661FC;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stw r7,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r7.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,32684
	ctx.r4.s64 = ctx.r6.s64 + 32684;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x8266621C;
	sub_823DC018(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r5,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r5.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266622C"))) PPC_WEAK_FUNC(sub_8266622C);
PPC_FUNC_IMPL(__imp__sub_8266622C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82666230"))) PPC_WEAK_FUNC(sub_82666230);
PPC_FUNC_IMPL(__imp__sub_82666230) {
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
	ctx.lr = 0x82666238;
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
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666254;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x826663bc
	if (!cr6.eq) goto loc_826663BC;
	// bl 0x826661a0
	ctx.lr = 0x82666260;
	sub_826661A0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r29,0
	r29.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-3624(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stb r29,796(r8)
	PPC_STORE_U8(ctx.r8.u32 + 796, r29.u8);
	// lwz r11,-3624(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lwz r7,700(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stb r29,797(r6)
	PPC_STORE_U8(ctx.r6.u32 + 797, r29.u8);
	// bl 0x82388680
	ctx.lr = 0x82666290;
	sub_82388680(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r4,r4,12080
	ctx.r4.s64 = ctx.r4.s64 + 12080;
	// lwz r11,-10236(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10236);
	// lwz r30,52(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x826662B0;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826662C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82666304
	if (cr6.eq) goto loc_82666304;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826662d8
	if (cr6.eq) goto loc_826662D8;
	// mr r29,r31
	r29.u64 = r31.u64;
loc_826662D8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,12064
	ctx.r4.s64 = r11.s64 + 12064;
	// bl 0x82691650
	ctx.lr = 0x826662E8;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,348(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 348);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826662FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82666304:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,12064
	ctx.r4.s64 = r11.s64 + 12064;
	// bl 0x82691650
	ctx.lr = 0x82666314;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82666324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82666368
	if (cr6.eq) goto loc_82666368;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8266633c
	if (cr6.eq) goto loc_8266633C;
	// mr r29,r31
	r29.u64 = r31.u64;
loc_8266633C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-2032
	ctx.r4.s64 = r11.s64 + -2032;
	// bl 0x82691650
	ctx.lr = 0x8266634C;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,348(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 348);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82666360;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82666368:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266637C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826663b8
	if (cr6.eq) goto loc_826663B8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82666394
	if (cr6.eq) goto loc_82666394;
	// mr r29,r31
	r29.u64 = r31.u64;
loc_82666394:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,-15108
	ctx.r4.s64 = r11.s64 + -15108;
	// bl 0x82691650
	ctx.lr = 0x826663A4;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r9,348(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 348);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826663B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826663B8:
	// bl 0x8265f428
	ctx.lr = 0x826663BC;
	sub_8265F428(ctx, base);
loc_826663BC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826663C4"))) PPC_WEAK_FUNC(sub_826663C4);
PPC_FUNC_IMPL(__imp__sub_826663C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826663C8"))) PPC_WEAK_FUNC(sub_826663C8);
PPC_FUNC_IMPL(__imp__sub_826663C8) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826663E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x826663f4
	if (!cr6.eq) goto loc_826663F4;
	// bl 0x82665ed0
	ctx.lr = 0x826663F4;
	sub_82665ED0(ctx, base);
loc_826663F4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82666404"))) PPC_WEAK_FUNC(sub_82666404);
PPC_FUNC_IMPL(__imp__sub_82666404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82666408"))) PPC_WEAK_FUNC(sub_82666408);
PPC_FUNC_IMPL(__imp__sub_82666408) {
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
	ctx.lr = 0x82666410;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r30
	r31.u64 = r30.u64;
	// bl 0x82256058
	ctx.lr = 0x82666420;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266643c
	if (cr6.eq) goto loc_8266643C;
	// bl 0x82256058
	ctx.lr = 0x8266642C;
	sub_82256058(ctx, base);
	// lwz r11,3104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3104);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bne cr6,0x8266643c
	if (!cr6.eq) goto loc_8266643C;
	// li r31,1
	r31.s64 = 1;
loc_8266643C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826664f0
	if (!cr6.eq) goto loc_826664F0;
	// mr r31,r30
	r31.u64 = r30.u64;
	// bl 0x82256058
	ctx.lr = 0x82666450;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266646c
	if (cr6.eq) goto loc_8266646C;
	// bl 0x82256058
	ctx.lr = 0x8266645C;
	sub_82256058(ctx, base);
	// lwz r11,3104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3104);
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// bne cr6,0x8266646c
	if (!cr6.eq) goto loc_8266646C;
	// li r31,1
	r31.s64 = 1;
loc_8266646C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826664f0
	if (!cr6.eq) goto loc_826664F0;
	// bl 0x82256058
	ctx.lr = 0x8266647C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826664e0
	if (cr6.eq) goto loc_826664E0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r28,r11,2532
	r28.s64 = r11.s64 + 2532;
	// addi r4,r10,2516
	ctx.r4.s64 = ctx.r10.s64 + 2516;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x826664A4;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x826664B8;
	sub_823DB670(ctx, base);
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-9136
	ctx.r4.s64 = ctx.r9.s64 + -9136;
	// bl 0x821fde78
	ctx.lr = 0x826664D0;
	sub_821FDE78(ctx, base);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r3,-29340(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -29340);
	// bl 0x826ab070
	ctx.lr = 0x826664DC;
	sub_826AB070(ctx, base);
	// b 0x82666568
	goto loc_82666568;
loc_826664E0:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-29340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// bl 0x826ab070
	ctx.lr = 0x826664EC;
	sub_826AB070(ctx, base);
	// b 0x82666568
	goto loc_82666568;
loc_826664F0:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r28,r11,12100
	r28.s64 = r11.s64 + 12100;
	// addi r4,r10,2516
	ctx.r4.s64 = ctx.r10.s64 + 2516;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x82666510;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x82666524;
	sub_823DB670(ctx, base);
	// stw r30,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r30.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-9136
	ctx.r4.s64 = ctx.r9.s64 + -9136;
	// bl 0x821fd980
	ctx.lr = 0x8266653C;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r8.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,32684
	ctx.r4.s64 = ctx.r7.s64 + 32684;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x8266655C;
	sub_823DC018(ctx, base);
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r6,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r6.u32);
	// bl 0x8265f428
	ctx.lr = 0x82666568;
	sub_8265F428(ctx, base);
loc_82666568:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r11,-27288(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27288);
	// lwz r9,2252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x82666594
	if (!cr6.eq) goto loc_82666594;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821f1498
	ctx.lr = 0x82666594;
	sub_821F1498(ctx, base);
loc_82666594:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-3624(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// stb r30,796(r8)
	PPC_STORE_U8(ctx.r8.u32 + 796, r30.u8);
	// lwz r11,-3624(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lwz r7,700(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stb r30,797(r6)
	PPC_STORE_U8(ctx.r6.u32 + 797, r30.u8);
	// bl 0x82388680
	ctx.lr = 0x826665C0;
	sub_82388680(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lwz r11,-10236(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826665d8
	if (cr6.eq) goto loc_826665D8;
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
loc_826665D8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-15108
	ctx.r4.s64 = ctx.r10.s64 + -15108;
	// bl 0x82691650
	ctx.lr = 0x826665E8;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r8,348(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 348);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826665FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82666614;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,736(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 736);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82666624;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266662C"))) PPC_WEAK_FUNC(sub_8266662C);
PPC_FUNC_IMPL(__imp__sub_8266662C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82666630"))) PPC_WEAK_FUNC(sub_82666630);
PPC_FUNC_IMPL(__imp__sub_82666630) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8266665c
	if (!cr6.eq) goto loc_8266665C;
	// bl 0x82666408
	ctx.lr = 0x8266665C;
	sub_82666408(ctx, base);
loc_8266665C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266666C"))) PPC_WEAK_FUNC(sub_8266666C);
PPC_FUNC_IMPL(__imp__sub_8266666C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82666670"))) PPC_WEAK_FUNC(sub_82666670);
PPC_FUNC_IMPL(__imp__sub_82666670) {
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
	ctx.lr = 0x82666678;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666754
	if (!cr6.eq) goto loc_82666754;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-9136
	ctx.r4.s64 = r11.s64 + -9136;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x826666B0;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,32684
	ctx.r4.s64 = ctx.r9.s64 + 32684;
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x826666D0;
	sub_823DC018(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r8.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r29,r7,3998
	r29.s64 = ctx.r7.s64 + 3998;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// addi r4,r6,2516
	ctx.r4.s64 = ctx.r6.s64 + 2516;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8220ef00
	ctx.lr = 0x826666F4;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x82666708;
	sub_823DB670(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r4,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r4.u32);
	// lwz r11,-10236(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bne cr6,0x8266672c
	if (!cr6.eq) goto loc_8266672C;
	// li r31,0
	r31.s64 = 0;
loc_8266672C:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r4,r10,-15108
	ctx.r4.s64 = ctx.r10.s64 + -15108;
	// bl 0x82691650
	ctx.lr = 0x8266673C;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r8,348(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 348);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82666750;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x8265f428
	ctx.lr = 0x82666754;
	sub_8265F428(ctx, base);
loc_82666754:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266675C"))) PPC_WEAK_FUNC(sub_8266675C);
PPC_FUNC_IMPL(__imp__sub_8266675C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82666760"))) PPC_WEAK_FUNC(sub_82666760);
PPC_FUNC_IMPL(__imp__sub_82666760) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x826667c0
	if (!cr6.eq) goto loc_826667C0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stb r10,796(r7)
	PPC_STORE_U8(ctx.r7.u32 + 796, ctx.r10.u8);
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r6,700(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stb r10,797(r5)
	PPC_STORE_U8(ctx.r5.u32 + 797, ctx.r10.u8);
	// bl 0x82665c18
	ctx.lr = 0x826667B4;
	sub_82665C18(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,-12776
	ctx.r3.s64 = ctx.r4.s64 + -12776;
	// bl 0x8265f3c8
	ctx.lr = 0x826667C0;
	sub_8265F3C8(ctx, base);
loc_826667C0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826667D0"))) PPC_WEAK_FUNC(sub_826667D0);
PPC_FUNC_IMPL(__imp__sub_826667D0) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826667F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666840
	if (!cr6.eq) goto loc_82666840;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stb r10,796(r7)
	PPC_STORE_U8(ctx.r7.u32 + 796, ctx.r10.u8);
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r6,700(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stb r10,797(r5)
	PPC_STORE_U8(ctx.r5.u32 + 797, ctx.r10.u8);
	// bl 0x82665c18
	ctx.lr = 0x82666824;
	sub_82665C18(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,12116
	ctx.r3.s64 = ctx.r4.s64 + 12116;
	// bl 0x821fa230
	ctx.lr = 0x82666830;
	sub_821FA230(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,304(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 304);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82666840:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82666850"))) PPC_WEAK_FUNC(sub_82666850);
PPC_FUNC_IMPL(__imp__sub_82666850) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r9,656(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// lwz r30,52(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82666888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x826668f8
	if (cr6.eq) goto loc_826668F8;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x826669a4
	if (!cr6.eq) goto loc_826669A4;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -6148);
	// bl 0x82250da8
	ctx.lr = 0x826668A8;
	sub_82250DA8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -6148);
	// bl 0x82253298
	ctx.lr = 0x826668B4;
	sub_82253298(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,-15384
	ctx.r4.s64 = ctx.r9.s64 + -15384;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x821fde10
	ctx.lr = 0x826668D0;
	sub_821FDE10(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r3,r8,-15924
	ctx.r3.s64 = ctx.r8.s64 + -15924;
	// bl 0x821e6800
	ctx.lr = 0x826668DC;
	sub_821E6800(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// bne cr6,0x826668ec
	if (!cr6.eq) goto loc_826668EC;
	// li r31,0
	r31.s64 = 0;
loc_826668EC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,12164
	ctx.r4.s64 = r11.s64 + 12164;
	// b 0x82666988
	goto loc_82666988;
loc_826668F8:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-6148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -6148);
	// bl 0x82250da8
	ctx.lr = 0x82666908;
	sub_82250DA8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-6148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -6148);
	// bl 0x82253298
	ctx.lr = 0x82666914;
	sub_82253298(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,-15384
	ctx.r4.s64 = ctx.r9.s64 + -15384;
	// lfs f31,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x821fd878
	ctx.lr = 0x82666934;
	sub_821FD878(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r7,9792
	ctx.r4.s64 = ctx.r7.s64 + 9792;
	// lfd f1,21560(r8)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r8.u32 + 21560);
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x823dc018
	ctx.lr = 0x82666958;
	sub_823DC018(ctx, base);
	// li r6,4
	ctx.r6.s64 = 4;
	// stfs f31,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// stw r6,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r6.u32);
	// addi r3,r5,-15924
	ctx.r3.s64 = ctx.r5.s64 + -15924;
	// bl 0x821e6800
	ctx.lr = 0x82666970;
	sub_821E6800(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r31,r30,4
	r31.s64 = r30.s64 + 4;
	// bne cr6,0x82666980
	if (!cr6.eq) goto loc_82666980;
	// li r31,0
	r31.s64 = 0;
loc_82666980:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r4,r11,12140
	ctx.r4.s64 = r11.s64 + 12140;
loc_82666988:
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82666990;
	sub_82691650(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,348(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 348);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826669A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826669A4:
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

__attribute__((alias("__imp__sub_826669C0"))) PPC_WEAK_FUNC(sub_826669C0);
PPC_FUNC_IMPL(__imp__sub_826669C0) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826669E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666a24
	if (!cr6.eq) goto loc_82666A24;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,-3624(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lwz r7,700(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stb r9,796(r6)
	PPC_STORE_U8(ctx.r6.u32 + 796, ctx.r9.u8);
	// lwz r11,-3624(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lwz r5,700(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stb r8,797(r4)
	PPC_STORE_U8(ctx.r4.u32 + 797, ctx.r8.u8);
	// bl 0x82665c18
	ctx.lr = 0x82666A18;
	sub_82665C18(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r3,r3,-5016
	ctx.r3.s64 = ctx.r3.s64 + -5016;
	// bl 0x8265f3c8
	ctx.lr = 0x82666A24;
	sub_8265F3C8(ctx, base);
loc_82666A24:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82666A34"))) PPC_WEAK_FUNC(sub_82666A34);
PPC_FUNC_IMPL(__imp__sub_82666A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82666A38"))) PPC_WEAK_FUNC(sub_82666A38);
PPC_FUNC_IMPL(__imp__sub_82666A38) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666A58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666a98
	if (!cr6.eq) goto loc_82666A98;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stb r10,796(r7)
	PPC_STORE_U8(ctx.r7.u32 + 796, ctx.r10.u8);
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r6,700(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stb r10,797(r5)
	PPC_STORE_U8(ctx.r5.u32 + 797, ctx.r10.u8);
	// bl 0x82665c18
	ctx.lr = 0x82666A8C;
	sub_82665C18(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r3,r4,5696
	ctx.r3.s64 = ctx.r4.s64 + 5696;
	// bl 0x8265f3c8
	ctx.lr = 0x82666A98;
	sub_8265F3C8(ctx, base);
loc_82666A98:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82666AA8"))) PPC_WEAK_FUNC(sub_82666AA8);
PPC_FUNC_IMPL(__imp__sub_82666AA8) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666AC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666b08
	if (!cr6.eq) goto loc_82666B08;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stb r10,796(r7)
	PPC_STORE_U8(ctx.r7.u32 + 796, ctx.r10.u8);
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r6,700(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stb r10,797(r5)
	PPC_STORE_U8(ctx.r5.u32 + 797, ctx.r10.u8);
	// bl 0x82665c18
	ctx.lr = 0x82666AFC;
	sub_82665C18(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r3,r4,14304
	ctx.r3.s64 = ctx.r4.s64 + 14304;
	// bl 0x8265f3c8
	ctx.lr = 0x82666B08;
	sub_8265F3C8(ctx, base);
loc_82666B08:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82666B18"))) PPC_WEAK_FUNC(sub_82666B18);
PPC_FUNC_IMPL(__imp__sub_82666B18) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666b78
	if (!cr6.eq) goto loc_82666B78;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stb r10,796(r7)
	PPC_STORE_U8(ctx.r7.u32 + 796, ctx.r10.u8);
	// lwz r11,-3624(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// lwz r6,700(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stb r10,797(r5)
	PPC_STORE_U8(ctx.r5.u32 + 797, ctx.r10.u8);
	// bl 0x82665c18
	ctx.lr = 0x82666B6C;
	sub_82665C18(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r3,r4,12188
	ctx.r3.s64 = ctx.r4.s64 + 12188;
	// bl 0x8265f3c8
	ctx.lr = 0x82666B78;
	sub_8265F3C8(ctx, base);
loc_82666B78:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82666B88"))) PPC_WEAK_FUNC(sub_82666B88);
PPC_FUNC_IMPL(__imp__sub_82666B88) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666BA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666bb4
	if (!cr6.eq) goto loc_82666BB4;
	// bl 0x82665ce0
	ctx.lr = 0x82666BB4;
	sub_82665CE0(ctx, base);
loc_82666BB4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82666BC4"))) PPC_WEAK_FUNC(sub_82666BC4);
PPC_FUNC_IMPL(__imp__sub_82666BC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82666BC8"))) PPC_WEAK_FUNC(sub_82666BC8);
PPC_FUNC_IMPL(__imp__sub_82666BC8) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666BEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666c38
	if (!cr6.eq) goto loc_82666C38;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// bl 0x82212200
	ctx.lr = 0x82666C04;
	sub_82212200(ctx, base);
	// bl 0x8265f568
	ctx.lr = 0x82666C08;
	sub_8265F568(ctx, base);
	// lwz r11,-10028(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// li r4,71
	ctx.r4.s64 = 71;
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82666C1C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82665940
	ctx.lr = 0x82666C24;
	sub_82665940(ctx, base);
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// addi r3,r31,656
	ctx.r3.s64 = r31.s64 + 656;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666C38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82666C38:
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

__attribute__((alias("__imp__sub_82666C4C"))) PPC_WEAK_FUNC(sub_82666C4C);
PPC_FUNC_IMPL(__imp__sub_82666C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82666C50"))) PPC_WEAK_FUNC(sub_82666C50);
PPC_FUNC_IMPL(__imp__sub_82666C50) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666C78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666cd0
	if (!cr6.eq) goto loc_82666CD0;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r10,9120
	r30.s64 = ctx.r10.s64 + 9120;
	// addi r4,r9,2516
	ctx.r4.s64 = ctx.r9.s64 + 2516;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x82666CA0;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x82666CB4;
	sub_823DB670(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stw r8,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r8.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r7,-9136
	ctx.r3.s64 = ctx.r7.s64 + -9136;
	// bl 0x82255cf8
	ctx.lr = 0x82666CCC;
	sub_82255CF8(ctx, base);
	// bl 0x8265f428
	ctx.lr = 0x82666CD0;
	sub_8265F428(ctx, base);
loc_82666CD0:
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

__attribute__((alias("__imp__sub_82666CE8"))) PPC_WEAK_FUNC(sub_82666CE8);
PPC_FUNC_IMPL(__imp__sub_82666CE8) {
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
	ctx.lr = 0x82666CF0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666D08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82666db0
	if (!cr6.eq) goto loc_82666DB0;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-9136
	ctx.r4.s64 = r11.s64 + -9136;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x82666D28;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,32684
	ctx.r4.s64 = ctx.r9.s64 + 32684;
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x82666D48;
	sub_823DC018(ctx, base);
	// li r8,3
	ctx.r8.s64 = 3;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r8,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r8.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r29,r7,3998
	r29.s64 = ctx.r7.s64 + 3998;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// addi r4,r6,2516
	ctx.r4.s64 = ctx.r6.s64 + 2516;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x8220ef00
	ctx.lr = 0x82666D6C;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x82666D80;
	sub_823DB670(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// stw r5,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r5.u32);
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82666DA0;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82666DB0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82666DB8"))) PPC_WEAK_FUNC(sub_82666DB8);
PPC_FUNC_IMPL(__imp__sub_82666DB8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// lwz r10,1888(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1888);
	// lwz r9,1892(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 1892);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x82666df4
	if (cr6.lt) goto loc_82666DF4;
	// lfs f0,4992(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4992);
	f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f13,4992(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4992, temp.u32);
loc_82666DF4:
	// lfs f0,4996(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4996);
	f0.f64 = double(temp.f32);
	// lfs f13,4992(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4992);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82666e14
	if (!cr6.gt) goto loc_82666E14;
	// bl 0x82665ce0
	ctx.lr = 0x82666E08;
	sub_82665CE0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,20160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20160);
	f0.f64 = double(temp.f32);
	// stfs f0,4992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4992, temp.u32);
loc_82666E14:
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

__attribute__((alias("__imp__sub_82666E28"))) PPC_WEAK_FUNC(sub_82666E28);
PPC_FUNC_IMPL(__imp__sub_82666E28) {
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
	ctx.lr = 0x82666E30;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,72
	ctx.r4.s64 = 72;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82666E50;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,736(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 736);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82666E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-9136
	ctx.r4.s64 = ctx.r7.s64 + -9136;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x82666E78;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,32684
	ctx.r4.s64 = ctx.r4.s64 + 32684;
	// stw r6,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r6.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x82666E98;
	sub_823DC018(ctx, base);
	// li r3,3
	ctx.r3.s64 = 3;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r29,r11,12212
	r29.s64 = r11.s64 + 12212;
	// addi r4,r10,2516
	ctx.r4.s64 = ctx.r10.s64 + 2516;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x82666EBC;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x82666ED0;
	sub_823DB670(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82666EE8;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b34b0
	ctx.lr = 0x82666EF0;
	sub_822B34B0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82666EF8"))) PPC_WEAK_FUNC(sub_82666EF8);
PPC_FUNC_IMPL(__imp__sub_82666EF8) {
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
	ctx.lr = 0x82666F00;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82666F20;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666F38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82666f4c
	if (cr6.eq) goto loc_82666F4C;
	// li r11,1
	r11.s64 = 1;
	// b 0x82666f60
	goto loc_82666F60;
loc_82666F4C:
	// bl 0x82660230
	ctx.lr = 0x82666F50;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
loc_82666F60:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826670d8
	if (cr6.eq) goto loc_826670D8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666F80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,27192
	ctx.r4.s64 = r11.s64 + 27192;
	// beq cr6,0x8266704c
	if (cr6.eq) goto loc_8266704C;
	// bl 0x821c2fb0
	ctx.lr = 0x82666FA8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82666FB8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82666fb8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82666FB8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82666FE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82666FF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82667010;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x82667044;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_8266704C:
	// bl 0x821c2fb0
	ctx.lr = 0x82667050;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82667064:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82667064
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82667064;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266708C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826670A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x826670D0;
	sub_82634EC8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_826670D8:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826670E0;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266714c
	if (cr6.eq) goto loc_8266714C;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,27192
	ctx.r4.s64 = r11.s64 + 27192;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c2fb0
	ctx.lr = 0x82667108;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r10,11976
	ctx.r6.s64 = ctx.r10.s64 + 11976;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r5,r9,12232
	ctx.r5.s64 = ctx.r9.s64 + 12232;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x82667144;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_8266714C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,5696
	ctx.r3.s64 = r11.s64 + 5696;
	// bl 0x8265f3c8
	ctx.lr = 0x82667158;
	sub_8265F3C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82667160"))) PPC_WEAK_FUNC(sub_82667160);
PPC_FUNC_IMPL(__imp__sub_82667160) {
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
	ctx.lr = 0x82667168;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82667188;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826671A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826671b4
	if (cr6.eq) goto loc_826671B4;
	// li r11,1
	r11.s64 = 1;
	// b 0x826671c8
	goto loc_826671C8;
loc_826671B4:
	// bl 0x82660230
	ctx.lr = 0x826671B8;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
loc_826671C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82667340
	if (cr6.eq) goto loc_82667340;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826671E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,26464
	ctx.r4.s64 = r11.s64 + 26464;
	// beq cr6,0x826672b4
	if (cr6.eq) goto loc_826672B4;
	// bl 0x821c2fb0
	ctx.lr = 0x82667210;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82667220:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82667220
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82667220;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82667260;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82667278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x826672AC;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_826672B4:
	// bl 0x821c2fb0
	ctx.lr = 0x826672B8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826672CC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826672cc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826672CC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826672F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266730C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82667338;
	sub_82634EC8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_82667340:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82667348;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826673b4
	if (cr6.eq) goto loc_826673B4;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,26464
	ctx.r4.s64 = r11.s64 + 26464;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c2fb0
	ctx.lr = 0x82667370;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r10,11976
	ctx.r6.s64 = ctx.r10.s64 + 11976;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r5,r9,12232
	ctx.r5.s64 = ctx.r9.s64 + 12232;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x826673AC;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_826673B4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-12776
	ctx.r3.s64 = r11.s64 + -12776;
	// bl 0x8265f3c8
	ctx.lr = 0x826673C0;
	sub_8265F3C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826673C8"))) PPC_WEAK_FUNC(sub_826673C8);
PPC_FUNC_IMPL(__imp__sub_826673C8) {
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
	ctx.lr = 0x826673D0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x826673F0;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667408;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266741c
	if (cr6.eq) goto loc_8266741C;
	// li r11,1
	r11.s64 = 1;
	// b 0x82667430
	goto loc_82667430;
loc_8266741C:
	// bl 0x82660230
	ctx.lr = 0x82667420;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
loc_82667430:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826675a8
	if (cr6.eq) goto loc_826675A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,27072
	ctx.r4.s64 = r11.s64 + 27072;
	// beq cr6,0x8266751c
	if (cr6.eq) goto loc_8266751C;
	// bl 0x821c2fb0
	ctx.lr = 0x82667478;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82667488:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82667488
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82667488;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826674B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826674C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826674E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x82667514;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_8266751C:
	// bl 0x821c2fb0
	ctx.lr = 0x82667520;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82667534:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82667534
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82667534;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266755C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82667574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x826675A0;
	sub_82634EC8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_826675A8:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826675B0;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266761c
	if (cr6.eq) goto loc_8266761C;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,27072
	ctx.r4.s64 = r11.s64 + 27072;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c2fb0
	ctx.lr = 0x826675D8;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r10,11976
	ctx.r6.s64 = ctx.r10.s64 + 11976;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r5,r9,12232
	ctx.r5.s64 = ctx.r9.s64 + 12232;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x82667614;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_8266761C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,-5016
	ctx.r3.s64 = r11.s64 + -5016;
	// bl 0x8265f3c8
	ctx.lr = 0x82667628;
	sub_8265F3C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82667630"))) PPC_WEAK_FUNC(sub_82667630);
PPC_FUNC_IMPL(__imp__sub_82667630) {
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
	ctx.lr = 0x82667638;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82667658;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82667684
	if (cr6.eq) goto loc_82667684;
	// li r11,1
	r11.s64 = 1;
	// b 0x82667698
	goto loc_82667698;
loc_82667684:
	// bl 0x82660230
	ctx.lr = 0x82667688;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
loc_82667698:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82667810
	if (cr6.eq) goto loc_82667810;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826676B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,27304
	ctx.r4.s64 = r11.s64 + 27304;
	// beq cr6,0x82667784
	if (cr6.eq) goto loc_82667784;
	// bl 0x821c2fb0
	ctx.lr = 0x826676E0;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826676F0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826676f0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826676F0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667718;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82667730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82667748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x8266777C;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_82667784:
	// bl 0x821c2fb0
	ctx.lr = 0x82667788;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266779C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8266779c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266779C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826677C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826677DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82667808;
	sub_82634EC8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_82667810:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82667818;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82667884
	if (cr6.eq) goto loc_82667884;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,27304
	ctx.r4.s64 = r11.s64 + 27304;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c2fb0
	ctx.lr = 0x82667840;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r10,11976
	ctx.r6.s64 = ctx.r10.s64 + 11976;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r5,r9,12232
	ctx.r5.s64 = ctx.r9.s64 + 12232;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x8266787C;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_82667884:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,14304
	ctx.r3.s64 = r11.s64 + 14304;
	// bl 0x8265f3c8
	ctx.lr = 0x82667890;
	sub_8265F3C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82667898"))) PPC_WEAK_FUNC(sub_82667898);
PPC_FUNC_IMPL(__imp__sub_82667898) {
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
	ctx.lr = 0x826678A0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x826678C0;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826678D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826678ec
	if (cr6.eq) goto loc_826678EC;
	// li r11,1
	r11.s64 = 1;
	// b 0x82667900
	goto loc_82667900;
loc_826678EC:
	// bl 0x82660230
	ctx.lr = 0x826678F0;
	sub_82660230(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
loc_82667900:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82667a78
	if (cr6.eq) goto loc_82667A78;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,27416
	ctx.r4.s64 = r11.s64 + 27416;
	// beq cr6,0x826679ec
	if (cr6.eq) goto loc_826679EC;
	// bl 0x821c2fb0
	ctx.lr = 0x82667948;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82667958:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82667958
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82667958;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82667998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826679B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x826679E4;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_826679EC:
	// bl 0x821c2fb0
	ctx.lr = 0x826679F0;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82667A04:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82667a04
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82667A04;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667A2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82667A44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82667A70;
	sub_82634EC8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_82667A78:
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82667A80;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82667aec
	if (cr6.eq) goto loc_82667AEC;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,27416
	ctx.r4.s64 = r11.s64 + 27416;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c2fb0
	ctx.lr = 0x82667AA8;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r6,r10,11976
	ctx.r6.s64 = ctx.r10.s64 + 11976;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r5,r9,12232
	ctx.r5.s64 = ctx.r9.s64 + 12232;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x82667AE4;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_82667AEC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r11,12188
	ctx.r3.s64 = r11.s64 + 12188;
	// bl 0x8265f3c8
	ctx.lr = 0x82667AF8;
	sub_8265F3C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82667B00"))) PPC_WEAK_FUNC(sub_82667B00);
PPC_FUNC_IMPL(__imp__sub_82667B00) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667B28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82667b38
	if (!cr6.eq) goto loc_82667B38;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82667160
	ctx.lr = 0x82667B38;
	sub_82667160(ctx, base);
loc_82667B38:
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

__attribute__((alias("__imp__sub_82667B4C"))) PPC_WEAK_FUNC(sub_82667B4C);
PPC_FUNC_IMPL(__imp__sub_82667B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82667B50"))) PPC_WEAK_FUNC(sub_82667B50);
PPC_FUNC_IMPL(__imp__sub_82667B50) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667B78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82667b88
	if (!cr6.eq) goto loc_82667B88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826673c8
	ctx.lr = 0x82667B88;
	sub_826673C8(ctx, base);
loc_82667B88:
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

__attribute__((alias("__imp__sub_82667B9C"))) PPC_WEAK_FUNC(sub_82667B9C);
PPC_FUNC_IMPL(__imp__sub_82667B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82667BA0"))) PPC_WEAK_FUNC(sub_82667BA0);
PPC_FUNC_IMPL(__imp__sub_82667BA0) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82667bd8
	if (!cr6.eq) goto loc_82667BD8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82666ef8
	ctx.lr = 0x82667BD8;
	sub_82666EF8(ctx, base);
loc_82667BD8:
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

__attribute__((alias("__imp__sub_82667BEC"))) PPC_WEAK_FUNC(sub_82667BEC);
PPC_FUNC_IMPL(__imp__sub_82667BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82667BF0"))) PPC_WEAK_FUNC(sub_82667BF0);
PPC_FUNC_IMPL(__imp__sub_82667BF0) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667C18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82667c28
	if (!cr6.eq) goto loc_82667C28;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82667630
	ctx.lr = 0x82667C28;
	sub_82667630(ctx, base);
loc_82667C28:
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

__attribute__((alias("__imp__sub_82667C3C"))) PPC_WEAK_FUNC(sub_82667C3C);
PPC_FUNC_IMPL(__imp__sub_82667C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82667C40"))) PPC_WEAK_FUNC(sub_82667C40);
PPC_FUNC_IMPL(__imp__sub_82667C40) {
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
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667C68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x82667c78
	if (!cr6.eq) goto loc_82667C78;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82667898
	ctx.lr = 0x82667C78;
	sub_82667898(ctx, base);
loc_82667C78:
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

__attribute__((alias("__imp__sub_82667C8C"))) PPC_WEAK_FUNC(sub_82667C8C);
PPC_FUNC_IMPL(__imp__sub_82667C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82667C90"))) PPC_WEAK_FUNC(sub_82667C90);
PPC_FUNC_IMPL(__imp__sub_82667C90) {
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
	ctx.lr = 0x82667C98;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8268e6b8
	ctx.lr = 0x82667CA4;
	sub_8268E6B8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667CBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// li r4,71
	ctx.r4.s64 = 71;
	// ori r31,r9,16256
	r31.u64 = ctx.r9.u64 | 16256;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82667CD8;
	sub_82641CB0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82665940
	ctx.lr = 0x82667CE0;
	sub_82665940(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82667CF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r29,17268(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + 17268);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82667D0C;
	sub_821E80F8(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82667d2c
	if (cr6.eq) goto loc_82667D2C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a3998
	ctx.lr = 0x82667D24;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a93a8
	ctx.lr = 0x82667D2C;
	sub_822A93A8(ctx, base);
loc_82667D2C:
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82667D38;
	sub_82641CC8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82667d70
	if (cr6.eq) goto loc_82667D70;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cc8
	ctx.lr = 0x82667D4C;
	sub_82641CC8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82667D5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-12456(r9)
	PPC_STORE_U8(ctx.r9.u32 + -12456, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82667D70:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-12456(r10)
	PPC_STORE_U8(ctx.r10.u32 + -12456, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82667D84"))) PPC_WEAK_FUNC(sub_82667D84);
PPC_FUNC_IMPL(__imp__sub_82667D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82667D88"))) PPC_WEAK_FUNC(sub_82667D88);
PPC_FUNC_IMPL(__imp__sub_82667D88) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82667D90;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633930
	ctx.lr = 0x82667DA0;
	sub_82633930(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r19,r31,176
	r19.s64 = r31.s64 + 176;
	// addi r10,r11,8284
	ctx.r10.s64 = r11.s64 + 8284;
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82633ca8
	ctx.lr = 0x82667DBC;
	sub_82633CA8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r26,r31,384
	r26.s64 = r31.s64 + 384;
	// addi r30,r9,3988
	r30.s64 = ctx.r9.s64 + 3988;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633a10
	ctx.lr = 0x82667DD8;
	sub_82633A10(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// li r29,0
	r29.s64 = 0;
	// addi r28,r8,4324
	r28.s64 = ctx.r8.s64 + 4324;
	// stw r29,560(r31)
	PPC_STORE_U32(r31.u32 + 560, r29.u32);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// stw r28,384(r31)
	PPC_STORE_U32(r31.u32 + 384, r28.u32);
	// addi r25,r31,576
	r25.s64 = r31.s64 + 576;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,3968
	ctx.r4.s64 = ctx.r7.s64 + 3968;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82633a10
	ctx.lr = 0x82667E04;
	sub_82633A10(ctx, base);
	// stw r28,576(r31)
	PPC_STORE_U32(r31.u32 + 576, r28.u32);
	// stw r29,752(r31)
	PPC_STORE_U32(r31.u32 + 752, r29.u32);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r24,r31,768
	r24.s64 = r31.s64 + 768;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,3948
	ctx.r4.s64 = ctx.r6.s64 + 3948;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82633a10
	ctx.lr = 0x82667E24;
	sub_82633A10(ctx, base);
	// stw r28,768(r31)
	PPC_STORE_U32(r31.u32 + 768, r28.u32);
	// stw r29,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r29.u32);
	// addi r3,r31,960
	ctx.r3.s64 = r31.s64 + 960;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82633a10
	ctx.lr = 0x82667E3C;
	sub_82633A10(ctx, base);
	// stw r28,960(r31)
	PPC_STORE_U32(r31.u32 + 960, r28.u32);
	// stw r29,1136(r31)
	PPC_STORE_U32(r31.u32 + 1136, r29.u32);
	// addi r23,r31,1152
	r23.s64 = r31.s64 + 1152;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82634738
	ctx.lr = 0x82667E58;
	sub_82634738(ctx, base);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r22,r31,1408
	r22.s64 = r31.s64 + 1408;
	// addi r30,r5,6612
	r30.s64 = ctx.r5.s64 + 6612;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r30,1152(r31)
	PPC_STORE_U32(r31.u32 + 1152, r30.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82634738
	ctx.lr = 0x82667E78;
	sub_82634738(ctx, base);
	// stw r30,1408(r31)
	PPC_STORE_U32(r31.u32 + 1408, r30.u32);
	// addi r21,r31,1664
	r21.s64 = r31.s64 + 1664;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82634738
	ctx.lr = 0x82667E90;
	sub_82634738(ctx, base);
	// stw r30,1664(r31)
	PPC_STORE_U32(r31.u32 + 1664, r30.u32);
	// addi r20,r31,1920
	r20.s64 = r31.s64 + 1920;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82634738
	ctx.lr = 0x82667EA8;
	sub_82634738(ctx, base);
	// stw r30,1920(r31)
	PPC_STORE_U32(r31.u32 + 1920, r30.u32);
	// addi r30,r31,2192
	r30.s64 = r31.s64 + 2192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826337a8
	ctx.lr = 0x82667EB8;
	sub_826337A8(ctx, base);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// stw r29,2368(r31)
	PPC_STORE_U32(r31.u32 + 2368, r29.u32);
	// addi r3,r30,184
	ctx.r3.s64 = r30.s64 + 184;
	// addi r11,r4,-14100
	r11.s64 = ctx.r4.s64 + -14100;
	// stw r29,2372(r31)
	PPC_STORE_U32(r31.u32 + 2372, r29.u32);
	// stw r11,2192(r31)
	PPC_STORE_U32(r31.u32 + 2192, r11.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82667ED4;
	sub_821C2F70(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r18,1
	r18.s64 = 1;
	// stw r29,2400(r31)
	PPC_STORE_U32(r31.u32 + 2400, r29.u32);
	// addi r17,r10,8108
	r17.s64 = ctx.r10.s64 + 8108;
	// stb r18,2396(r31)
	PPC_STORE_U8(r31.u32 + 2396, r18.u8);
	// addi r28,r31,2416
	r28.s64 = r31.s64 + 2416;
	// stw r17,2416(r31)
	PPC_STORE_U32(r31.u32 + 2416, r17.u32);
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x82634b60
	ctx.lr = 0x82667EF8;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82667F00;
	sub_82634B60(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// addi r16,r9,-3372
	r16.s64 = ctx.r9.s64 + -3372;
	// stw r16,4224(r31)
	PPC_STORE_U32(r31.u32 + 4224, r16.u32);
	// bl 0x82662738
	ctx.lr = 0x82667F14;
	sub_82662738(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r28,r31,7408
	r28.s64 = r31.s64 + 7408;
	// addi r7,r8,9764
	ctx.r7.s64 = ctx.r8.s64 + 9764;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r7,2416(r31)
	PPC_STORE_U32(r31.u32 + 2416, ctx.r7.u32);
	// stw r17,7408(r31)
	PPC_STORE_U32(r31.u32 + 7408, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82667F30;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82667F38;
	sub_82634B60(ctx, base);
	// stw r16,9216(r31)
	PPC_STORE_U32(r31.u32 + 9216, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82667F44;
	sub_82662738(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r28,r31,12400
	r28.s64 = r31.s64 + 12400;
	// addi r5,r6,9884
	ctx.r5.s64 = ctx.r6.s64 + 9884;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r5,7408(r31)
	PPC_STORE_U32(r31.u32 + 7408, ctx.r5.u32);
	// stw r17,12400(r31)
	PPC_STORE_U32(r31.u32 + 12400, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82667F60;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82667F68;
	sub_82634B60(ctx, base);
	// stw r16,14208(r31)
	PPC_STORE_U32(r31.u32 + 14208, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82667F74;
	sub_82662738(ctx, base);
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r28,r31,17392
	r28.s64 = r31.s64 + 17392;
	// addi r11,r4,10036
	r11.s64 = ctx.r4.s64 + 10036;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r11,12400(r31)
	PPC_STORE_U32(r31.u32 + 12400, r11.u32);
	// stw r17,17392(r31)
	PPC_STORE_U32(r31.u32 + 17392, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82667F90;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82667F98;
	sub_82634B60(ctx, base);
	// stw r16,19200(r31)
	PPC_STORE_U32(r31.u32 + 19200, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82667FA4;
	sub_82662738(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r28,r31,22384
	r28.s64 = r31.s64 + 22384;
	// addi r9,r10,10276
	ctx.r9.s64 = ctx.r10.s64 + 10276;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r9,17392(r31)
	PPC_STORE_U32(r31.u32 + 17392, ctx.r9.u32);
	// stw r17,22384(r31)
	PPC_STORE_U32(r31.u32 + 22384, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82667FC0;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82667FC8;
	sub_82634B60(ctx, base);
	// stw r16,24192(r31)
	PPC_STORE_U32(r31.u32 + 24192, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82667FD4;
	sub_82662738(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r28,r31,27376
	r28.s64 = r31.s64 + 27376;
	// addi r7,r8,10452
	ctx.r7.s64 = ctx.r8.s64 + 10452;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r7,22384(r31)
	PPC_STORE_U32(r31.u32 + 22384, ctx.r7.u32);
	// stw r17,27376(r31)
	PPC_STORE_U32(r31.u32 + 27376, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82667FF0;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82667FF8;
	sub_82634B60(ctx, base);
	// stw r16,29184(r31)
	PPC_STORE_U32(r31.u32 + 29184, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82668004;
	sub_82662738(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r28,r31,32368
	r28.s64 = r31.s64 + 32368;
	// addi r5,r6,10700
	ctx.r5.s64 = ctx.r6.s64 + 10700;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r5,27376(r31)
	PPC_STORE_U32(r31.u32 + 27376, ctx.r5.u32);
	// stw r17,32368(r31)
	PPC_STORE_U32(r31.u32 + 32368, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82668020;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82668028;
	sub_82634B60(ctx, base);
	// stw r16,1808(r28)
	PPC_STORE_U32(r28.u32 + 1808, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82668034;
	sub_82662738(ctx, base);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r28,r28,-28176
	r28.s64 = r28.s64 + -28176;
	// addi r11,r4,10980
	r11.s64 = ctx.r4.s64 + 10980;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r11,32368(r31)
	PPC_STORE_U32(r31.u32 + 32368, r11.u32);
	// stw r17,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82668054;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x8266805C;
	sub_82634B60(ctx, base);
	// stw r16,1808(r28)
	PPC_STORE_U32(r28.u32 + 1808, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82668068;
	sub_82662738(ctx, base);
	// addis r27,r31,1
	r27.s64 = r31.s64 + 65536;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r27,r27,-23184
	r27.s64 = r27.s64 + -23184;
	// addi r9,r10,11180
	ctx.r9.s64 = ctx.r10.s64 + 11180;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82668088;
	sub_82634B60(ctx, base);
	// addi r3,r27,1808
	ctx.r3.s64 = r27.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82668090;
	sub_82634B60(ctx, base);
	// stw r16,1808(r27)
	PPC_STORE_U32(r27.u32 + 1808, r16.u32);
	// addi r3,r27,3600
	ctx.r3.s64 = r27.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x8266809C;
	sub_82662738(ctx, base);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r28,r28,-18192
	r28.s64 = r28.s64 + -18192;
	// addi r7,r8,11380
	ctx.r7.s64 = ctx.r8.s64 + 11380;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r7,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r7.u32);
	// stw r17,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x826680BC;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x826680C4;
	sub_82634B60(ctx, base);
	// stw r16,1808(r28)
	PPC_STORE_U32(r28.u32 + 1808, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x826680D0;
	sub_82662738(ctx, base);
	// addis r27,r31,1
	r27.s64 = r31.s64 + 65536;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r27,r27,-13200
	r27.s64 = r27.s64 + -13200;
	// addi r5,r6,11500
	ctx.r5.s64 = ctx.r6.s64 + 11500;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// stw r5,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r5.u32);
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x826680F0;
	sub_82634B60(ctx, base);
	// addi r3,r27,1808
	ctx.r3.s64 = r27.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x826680F8;
	sub_82634B60(ctx, base);
	// stw r16,1808(r27)
	PPC_STORE_U32(r27.u32 + 1808, r16.u32);
	// addi r3,r27,3600
	ctx.r3.s64 = r27.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82668104;
	sub_82662738(ctx, base);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// addi r28,r28,-8208
	r28.s64 = r28.s64 + -8208;
	// addi r11,r4,11620
	r11.s64 = ctx.r4.s64 + 11620;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// stw r17,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82668124;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x8266812C;
	sub_82634B60(ctx, base);
	// stw r16,1808(r28)
	PPC_STORE_U32(r28.u32 + 1808, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x82668138;
	sub_82662738(ctx, base);
	// addis r27,r31,1
	r27.s64 = r31.s64 + 65536;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r27,r27,-3200
	r27.s64 = r27.s64 + -3200;
	// addi r9,r10,11740
	ctx.r9.s64 = ctx.r10.s64 + 11740;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// stw r9,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r9.u32);
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x82668158;
	sub_82634B60(ctx, base);
	// addi r3,r27,1808
	ctx.r3.s64 = r27.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82668160;
	sub_82634B60(ctx, base);
	// stw r16,1808(r27)
	PPC_STORE_U32(r27.u32 + 1808, r16.u32);
	// addi r3,r27,3600
	ctx.r3.s64 = r27.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x8266816C;
	sub_82662738(ctx, base);
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r28,r28,1792
	r28.s64 = r28.s64 + 1792;
	// addi r7,r8,11860
	ctx.r7.s64 = ctx.r8.s64 + 11860;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// stw r7,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r7.u32);
	// stw r17,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r17.u32);
	// bl 0x82634b60
	ctx.lr = 0x8266818C;
	sub_82634B60(ctx, base);
	// addi r3,r28,1808
	ctx.r3.s64 = r28.s64 + 1808;
	// bl 0x82634b60
	ctx.lr = 0x82668194;
	sub_82634B60(ctx, base);
	// stw r16,1808(r28)
	PPC_STORE_U32(r28.u32 + 1808, r16.u32);
	// addi r3,r28,3600
	ctx.r3.s64 = r28.s64 + 3600;
	// bl 0x82662738
	ctx.lr = 0x826681A0;
	sub_82662738(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,6784
	ctx.r3.s64 = ctx.r3.s64 + 6784;
	// bl 0x82634b60
	ctx.lr = 0x826681AC;
	sub_82634B60(ctx, base);
	// addis r3,r31,1
	ctx.r3.s64 = r31.s64 + 65536;
	// addi r3,r3,8576
	ctx.r3.s64 = ctx.r3.s64 + 8576;
	// bl 0x82662738
	ctx.lr = 0x826681B8;
	sub_82662738(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r17,r31,2176
	r17.s64 = r31.s64 + 2176;
	// li r27,4
	r27.s64 = 4;
	// li r14,32
	r14.s64 = 32;
	// addi r16,r11,-4092
	r16.s64 = r11.s64 + -4092;
	// addi r15,r10,6560
	r15.s64 = ctx.r10.s64 + 6560;
loc_826681D4:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826681DC;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82668214
	if (cr6.eq) goto loc_82668214;
	// stw r16,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r16.u32);
	// li r3,128
	ctx.r3.s64 = 128;
	// sth r29,8(r28)
	PPC_STORE_U16(r28.u32 + 8, r29.u16);
	// sth r14,10(r28)
	PPC_STORE_U16(r28.u32 + 10, r14.u16);
	// bl 0x82130528
	ctx.lr = 0x826681FC;
	sub_82130528(ctx, base);
	// stw r3,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r3.u32);
	// stw r29,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r29.u32);
	// mr r11,r28
	r11.u64 = r28.u64;
	// stw r15,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r15.u32);
	// stw r18,16(r28)
	PPC_STORE_U32(r28.u32 + 16, r18.u32);
	// b 0x82668218
	goto loc_82668218;
loc_82668214:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82668218:
	// stw r11,0(r17)
	PPC_STORE_U32(r17.u32 + 0, r11.u32);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// addi r17,r17,4
	r17.s64 = r17.s64 + 4;
	// bne 0x826681d4
	if (!cr0.eq) goto loc_826681D4;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r10,r31,68
	ctx.r10.s64 = r31.s64 + 68;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r8,2
	ctx.r8.s64 = 2;
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// addi r11,r31,356
	r11.s64 = r31.s64 + 356;
	// sth r7,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r7.u16);
	// li r5,3
	ctx.r5.s64 = 3;
	// stwx r30,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r30.u32);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,72(r31)
	PPC_STORE_U16(r31.u32 + 72, ctx.r4.u16);
	// stwx r19,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r19.u32);
	// lwz r10,356(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// lhz r11,360(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 360);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,360(r31)
	PPC_STORE_U16(r31.u32 + 360, ctx.r7.u16);
	// stwx r26,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r26.u32);
	// lwz r10,356(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// lhz r11,360(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 360);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,360(r31)
	PPC_STORE_U16(r31.u32 + 360, ctx.r4.u16);
	// stwx r25,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r25.u32);
	// lwz r10,356(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 356);
	// lhz r11,360(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 360);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,360(r31)
	PPC_STORE_U16(r31.u32 + 360, ctx.r7.u16);
	// stwx r24,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r24.u32);
	// lwz r10,452(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 452);
	// lhz r11,456(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 456);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r4,456(r31)
	PPC_STORE_U16(r31.u32 + 456, ctx.r4.u16);
	// stwx r23,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r23.u32);
	// lwz r10,644(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 644);
	// lhz r11,648(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 648);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,648(r31)
	PPC_STORE_U16(r31.u32 + 648, ctx.r9.u16);
	// stwx r22,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r22.u32);
	// lwz r10,836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 836);
	// lhz r11,840(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 840);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r6,840(r31)
	PPC_STORE_U16(r31.u32 + 840, ctx.r6.u16);
	// stwx r21,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r21.u32);
	// lwz r10,1028(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1028);
	// lhz r11,1032(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1032);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// sth r3,1032(r31)
	PPC_STORE_U16(r31.u32 + 1032, ctx.r3.u16);
	// stwx r20,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r20.u32);
	// stw r18,560(r31)
	PPC_STORE_U32(r31.u32 + 560, r18.u32);
	// stw r18,1136(r31)
	PPC_STORE_U32(r31.u32 + 1136, r18.u32);
	// stw r8,752(r31)
	PPC_STORE_U32(r31.u32 + 752, ctx.r8.u32);
	// stw r5,944(r31)
	PPC_STORE_U32(r31.u32 + 944, ctx.r5.u32);
	// lwz r10,176(r19)
	ctx.r10.u64 = PPC_LOAD_U32(r19.u32 + 176);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r29,176(r19)
	PPC_STORE_U32(r19.u32 + 176, r29.u32);
	// beq cr6,0x8266833c
	if (cr6.eq) goto loc_8266833C;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r19,188
	ctx.r3.s64 = r19.s64 + 188;
	// bl 0x821c3048
	ctx.lr = 0x8266833C;
	sub_821C3048(ctx, base);
loc_8266833C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82668348"))) PPC_WEAK_FUNC(sub_82668348);
PPC_FUNC_IMPL(__imp__sub_82668348) {
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
	ctx.lr = 0x82668350;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-13208
	ctx.r4.s64 = r11.s64 + -13208;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633e80
	ctx.lr = 0x82668368;
	sub_82633E80(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r9,r10,12268
	ctx.r9.s64 = ctx.r10.s64 + 12268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x82634078
	ctx.lr = 0x82668384;
	sub_82634078(ctx, base);
	// addi r29,r31,480
	r29.s64 = r31.s64 + 480;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82667d88
	ctx.lr = 0x82668390;
	sub_82667D88(ctx, base);
	// addi r11,r31,68
	r11.s64 = r31.s64 + 68;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
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
	// lwz r9,324(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 324);
	// lhz r11,328(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 328);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,328(r31)
	PPC_STORE_U16(r31.u32 + 328, ctx.r6.u16);
	// stwx r29,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r29.u32);
	// bl 0x82632e98
	ctx.lr = 0x826683D0;
	sub_82632E98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826683DC"))) PPC_WEAK_FUNC(sub_826683DC);
PPC_FUNC_IMPL(__imp__sub_826683DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826683E0"))) PPC_WEAK_FUNC(sub_826683E0);
PPC_FUNC_IMPL(__imp__sub_826683E0) {
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
	ctx.lr = 0x826683E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,480
	ctx.r3.s64 = r31.s64 + 480;
	// bl 0x826628b0
	ctx.lr = 0x826683FC;
	sub_826628B0(ctx, base);
	// lhz r11,438(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 438);
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82668414
	if (cr6.eq) goto loc_82668414;
	// lwz r3,176(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// bl 0x82130588
	ctx.lr = 0x82668414;
	sub_82130588(ctx, base);
loc_82668414:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266841C;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x82668424;
	sub_82633B00(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266843c
	if (cr6.eq) goto loc_8266843C;
	// bl 0x82130588
	ctx.lr = 0x82668438;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8266843C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82668444"))) PPC_WEAK_FUNC(sub_82668444);
PPC_FUNC_IMPL(__imp__sub_82668444) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82668448"))) PPC_WEAK_FUNC(sub_82668448);
PPC_FUNC_IMPL(__imp__sub_82668448) {
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
	// bl 0x82665940
	ctx.lr = 0x82668460;
	sub_82665940(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826302b8
	ctx.lr = 0x82668468;
	sub_826302B8(ctx, base);
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

__attribute__((alias("__imp__sub_8266847C"))) PPC_WEAK_FUNC(sub_8266847C);
PPC_FUNC_IMPL(__imp__sub_8266847C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82668480"))) PPC_WEAK_FUNC(sub_82668480);
PPC_FUNC_IMPL(__imp__sub_82668480) {
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
	ctx.lr = 0x82668488;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826684A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826684d0
	if (!cr6.eq) goto loc_826684D0;
	// lwz r3,-10028(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x826684B8;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826684d0
	if (!cr6.eq) goto loc_826684D0;
	// bl 0x8265f428
	ctx.lr = 0x826684C8;
	sub_8265F428(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_826684D0:
	// bl 0x8265e5e8
	ctx.lr = 0x826684D4;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826684ec
	if (cr6.eq) goto loc_826684EC;
	// bl 0x82665ed0
	ctx.lr = 0x826684E4;
	sub_82665ED0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_826684EC:
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// li r4,71
	ctx.r4.s64 = 71;
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82668500;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668518;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,25544
	ctx.r4.s64 = r11.s64 + 25544;
	// beq cr6,0x826685d4
	if (cr6.eq) goto loc_826685D4;
	// bl 0x821c2fb0
	ctx.lr = 0x82668540;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82668550:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82668550
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82668550;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r10,5104
	r30.s64 = ctx.r10.s64 + 5104;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82668580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82668598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x826685CC;
	sub_826624C8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
loc_826685D4:
	// bl 0x821c2fb0
	ctx.lr = 0x826685D8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826685EC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826685ec
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826685EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668614;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,76(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266862C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82668658;
	sub_82634EC8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82668660"))) PPC_WEAK_FUNC(sub_82668660);
PPC_FUNC_IMPL(__imp__sub_82668660) {
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
	ctx.lr = 0x82668668;
	// stwu r1,-768(r1)
	ea = -768 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r30,r11,16256
	r30.u64 = r11.u64 | 16256;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// li r4,71
	ctx.r4.s64 = 71;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82668690;
	sub_82641CB0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,17
	cr6.compare<int32_t>(r28.s32, 17, xer);
	// beq cr6,0x82669864
	if (cr6.eq) goto loc_82669864;
	// cmpwi cr6,r28,55
	cr6.compare<int32_t>(r28.s32, 55, xer);
	// beq cr6,0x826686b8
	if (cr6.eq) goto loc_826686B8;
	// cmpwi cr6,r28,56
	cr6.compare<int32_t>(r28.s32, 56, xer);
	// beq cr6,0x82669864
	if (cr6.eq) goto loc_82669864;
loc_826686AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_826686B8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,13416
	ctx.r3.s64 = r11.s64 + 13416;
	// bl 0x82661508
	ctx.lr = 0x826686C8;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266870c
	if (cr6.eq) goto loc_8266870C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,38
	ctx.r4.s64 = 38;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826686EC;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82668700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_8266870C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6172
	ctx.r3.s64 = r11.s64 + 6172;
	// bl 0x82661508
	ctx.lr = 0x8266871C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82668778
	if (cr6.eq) goto loc_82668778;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,41
	ctx.r4.s64 = 41;
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82668758;
	sub_82641CB0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r6,704(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 704);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266876C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668778:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,13400
	ctx.r3.s64 = r11.s64 + 13400;
	// bl 0x82661508
	ctx.lr = 0x82668788;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826687cc
	if (cr6.eq) goto loc_826687CC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,30
	ctx.r4.s64 = 30;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826687AC;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826687C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_826687CC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6080
	ctx.r3.s64 = r11.s64 + 6080;
	// bl 0x82661508
	ctx.lr = 0x826687DC;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82668820
	if (cr6.eq) goto loc_82668820;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,39
	ctx.r4.s64 = 39;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82668800;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82668814;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668820:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5480
	ctx.r3.s64 = r11.s64 + 5480;
	// bl 0x82661508
	ctx.lr = 0x82668830;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266884c
	if (cr6.eq) goto loc_8266884C;
	// bl 0x8265f428
	ctx.lr = 0x82668840;
	sub_8265F428(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_8266884C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5664
	ctx.r3.s64 = r11.s64 + 5664;
	// bl 0x82661508
	ctx.lr = 0x8266885C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826697f8
	if (!cr6.eq) goto loc_826697F8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6160
	ctx.r3.s64 = r11.s64 + 6160;
	// bl 0x82661508
	ctx.lr = 0x82668878;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826697f8
	if (!cr6.eq) goto loc_826697F8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5776
	ctx.r3.s64 = r11.s64 + 5776;
	// bl 0x82661508
	ctx.lr = 0x82668894;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826688b4
	if (cr6.eq) goto loc_826688B4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8265f978
	ctx.lr = 0x826688A8;
	sub_8265F978(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_826688B4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5712
	ctx.r3.s64 = r11.s64 + 5712;
	// bl 0x82661508
	ctx.lr = 0x826688C4;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669790
	if (!cr6.eq) goto loc_82669790;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5608
	ctx.r3.s64 = r11.s64 + 5608;
	// bl 0x82661508
	ctx.lr = 0x826688E0;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669790
	if (!cr6.eq) goto loc_82669790;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,5424
	ctx.r3.s64 = r11.s64 + 5424;
	// bl 0x82661508
	ctx.lr = 0x826688FC;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266975c
	if (!cr6.eq) goto loc_8266975C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,5396
	ctx.r3.s64 = r11.s64 + 5396;
	// bl 0x82661508
	ctx.lr = 0x82668918;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266975c
	if (!cr6.eq) goto loc_8266975C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5408
	ctx.r3.s64 = r11.s64 + 5408;
	// bl 0x82661508
	ctx.lr = 0x82668934;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826696fc
	if (!cr6.eq) goto loc_826696FC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5380
	ctx.r3.s64 = r11.s64 + 5380;
	// bl 0x82661508
	ctx.lr = 0x82668950;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826696fc
	if (!cr6.eq) goto loc_826696FC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5652
	ctx.r3.s64 = r11.s64 + 5652;
	// bl 0x82661508
	ctx.lr = 0x8266896C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669634
	if (!cr6.eq) goto loc_82669634;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5436
	ctx.r3.s64 = r11.s64 + 5436;
	// bl 0x82661508
	ctx.lr = 0x82668988;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669634
	if (!cr6.eq) goto loc_82669634;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x82661508
	ctx.lr = 0x826689A4;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826698a4
	if (!cr6.eq) goto loc_826698A4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x82661508
	ctx.lr = 0x826689C0;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826694bc
	if (!cr6.eq) goto loc_826694BC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x82661508
	ctx.lr = 0x826689DC;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826694bc
	if (!cr6.eq) goto loc_826694BC;
	// bl 0x82387a18
	ctx.lr = 0x826689EC;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82668bc4
	if (!cr6.eq) goto loc_82668BC4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5504
	ctx.r3.s64 = r11.s64 + 5504;
	// bl 0x82661508
	ctx.lr = 0x82668A08;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82668a4c
	if (!cr6.eq) goto loc_82668A4C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5464
	ctx.r3.s64 = r11.s64 + 5464;
	// bl 0x82661508
	ctx.lr = 0x82668A24;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82668a4c
	if (!cr6.eq) goto loc_82668A4C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5732
	ctx.r3.s64 = r11.s64 + 5732;
	// bl 0x82661508
	ctx.lr = 0x82668A40;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82668bc4
	if (cr6.eq) goto loc_82668BC4;
loc_82668A4C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668A60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,25136
	ctx.r4.s64 = r11.s64 + 25136;
	// bne cr6,0x82668b14
	if (!cr6.eq) goto loc_82668B14;
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// bl 0x821c2fb0
	ctx.lr = 0x82668A88;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82668A9C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82668a9c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82668A9C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668AC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82668ADC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82668B08;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668B14:
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821c2fb0
	ctx.lr = 0x82668B1C;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82668B2C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82668b2c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82668B2C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668B54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82668B6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82668B84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x82668BB8;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668BC4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6148
	ctx.r3.s64 = r11.s64 + 6148;
	// bl 0x82661508
	ctx.lr = 0x82668BD4;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82668cb0
	if (cr6.eq) goto loc_82668CB0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82668c90
	if (cr6.eq) goto loc_82668C90;
	// lwz r30,76(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82668c90
	if (!cr6.gt) goto loc_82668C90;
	// bl 0x8265e5e8
	ctx.lr = 0x82668C04;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82668c90
	if (cr6.eq) goto loc_82668C90;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823dc018
	ctx.lr = 0x82668C24;
	sub_823DC018(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r9,-2496
	ctx.r4.s64 = ctx.r9.s64 + -2496;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82668C3C;
	sub_822183B0(ctx, base);
	// lis r8,-32154
	ctx.r8.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,31488
	ctx.r4.s64 = ctx.r8.s64 + 31488;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// bl 0x821c2fb0
	ctx.lr = 0x82668C58;
	sub_821C2FB0(ctx, base);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r6,r7,13380
	ctx.r6.s64 = ctx.r7.s64 + 13380;
	// rldicr r10,r4,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// li r29,0
	r29.s64 = 0;
	// addi r5,r5,-2516
	ctx.r5.s64 = ctx.r5.s64 + -2516;
	// li r7,2
	ctx.r7.s64 = 2;
	// stb r29,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r29.u8);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82634ec8
	ctx.lr = 0x82668C90;
	sub_82634EC8(ctx, base);
loc_82668C90:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826698ac
	if (cr6.eq) goto loc_826698AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82667160
	ctx.lr = 0x82668CA4;
	sub_82667160(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668CB0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,-15096
	ctx.r3.s64 = r11.s64 + -15096;
	// bl 0x82661508
	ctx.lr = 0x82668CC0;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82668f3c
	if (cr6.eq) goto loc_82668F3C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826602b0
	ctx.lr = 0x82668CD4;
	sub_826602B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82668e58
	if (cr6.eq) goto loc_82668E58;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668CF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,26576
	ctx.r4.s64 = r11.s64 + 26576;
	// beq cr6,0x82668dc4
	if (cr6.eq) goto loc_82668DC4;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// bl 0x821c2fb0
	ctx.lr = 0x82668D1C;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82668D2C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82668d2c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82668D2C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668D54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,108(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82668D6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82668D84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x82668DB8;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668DC4:
	// addi r3,r1,592
	ctx.r3.s64 = ctx.r1.s64 + 592;
	// bl 0x821c2fb0
	ctx.lr = 0x82668DCC;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82668DE0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82668de0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82668DE0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82668E08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82668E20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82668E4C;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668E58:
	// lwz r3,-10028(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x82668E60;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r7,1
	ctx.r7.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// beq cr6,0x82668ed0
	if (cr6.eq) goto loc_82668ED0;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// addi r4,r11,26576
	ctx.r4.s64 = r11.s64 + 26576;
	// bl 0x821c2fb0
	ctx.lr = 0x82668E88;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// ld r30,8(r3)
	r30.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r6,r10,11976
	ctx.r6.s64 = ctx.r10.s64 + 11976;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r5,r9,12232
	ctx.r5.s64 = ctx.r9.s64 + 12232;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// std r30,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r30.u64);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x82668EC4;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668ED0:
	// lis r11,-32154
	r11.s64 = -2107244544;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// addi r4,r11,26704
	ctx.r4.s64 = r11.s64 + 26704;
	// bl 0x821c2fb0
	ctx.lr = 0x82668EE0;
	sub_821C2FB0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,20
	ctx.r5.s64 = 20;
	// stb r10,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, ctx.r10.u8);
	// bl 0x823da950
	ctx.lr = 0x82668EF8;
	sub_823DA950(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// addi r10,r9,13360
	ctx.r10.s64 = ctx.r9.s64 + 13360;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r9,r8,13344
	ctx.r9.s64 = ctx.r8.s64 + 13344;
	// addi r8,r7,13324
	ctx.r8.s64 = ctx.r7.s64 + 13324;
	// addi r6,r6,13312
	ctx.r6.s64 = ctx.r6.s64 + 13312;
	// addi r5,r5,13288
	ctx.r5.s64 = ctx.r5.s64 + 13288;
	// li r7,3
	ctx.r7.s64 = 3;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82634db0
	ctx.lr = 0x82668F30;
	sub_82634DB0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82668F3C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6132
	ctx.r3.s64 = r11.s64 + 6132;
	// bl 0x82661508
	ctx.lr = 0x82668F4C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82669028
	if (cr6.eq) goto loc_82669028;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82669008
	if (cr6.eq) goto loc_82669008;
	// lwz r30,76(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82669008
	if (!cr6.gt) goto loc_82669008;
	// bl 0x8265e5e8
	ctx.lr = 0x82668F7C;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82669008
	if (cr6.eq) goto loc_82669008;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823dc018
	ctx.lr = 0x82668F9C;
	sub_823DC018(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r9,-2496
	ctx.r4.s64 = ctx.r9.s64 + -2496;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82668FB4;
	sub_822183B0(ctx, base);
	// lis r8,-32154
	ctx.r8.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,31568
	ctx.r4.s64 = ctx.r8.s64 + 31568;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// bl 0x821c2fb0
	ctx.lr = 0x82668FD0;
	sub_821C2FB0(ctx, base);
	// lwz r4,16(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r6,r7,13380
	ctx.r6.s64 = ctx.r7.s64 + 13380;
	// rldicr r10,r4,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// li r29,0
	r29.s64 = 0;
	// addi r5,r5,-2516
	ctx.r5.s64 = ctx.r5.s64 + -2516;
	// li r7,2
	ctx.r7.s64 = 2;
	// stb r29,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r29.u8);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82634ec8
	ctx.lr = 0x82669008;
	sub_82634EC8(ctx, base);
loc_82669008:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826698ac
	if (cr6.eq) goto loc_826698AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826673c8
	ctx.lr = 0x8266901C;
	sub_826673C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669028:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6120
	ctx.r3.s64 = r11.s64 + 6120;
	// bl 0x82661508
	ctx.lr = 0x82669038;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82669114
	if (cr6.eq) goto loc_82669114;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826690f4
	if (cr6.eq) goto loc_826690F4;
	// lwz r30,76(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826690f4
	if (!cr6.gt) goto loc_826690F4;
	// bl 0x8265e5e8
	ctx.lr = 0x82669068;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826690f4
	if (cr6.eq) goto loc_826690F4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823dc018
	ctx.lr = 0x82669088;
	sub_823DC018(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r9,-2496
	ctx.r4.s64 = ctx.r9.s64 + -2496;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826690A0;
	sub_822183B0(ctx, base);
	// lis r8,-32154
	ctx.r8.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,31648
	ctx.r4.s64 = ctx.r8.s64 + 31648;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c2fb0
	ctx.lr = 0x826690BC;
	sub_821C2FB0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r7,13380
	ctx.r6.s64 = ctx.r7.s64 + 13380;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// addi r5,r5,-2516
	ctx.r5.s64 = ctx.r5.s64 + -2516;
	// li r7,2
	ctx.r7.s64 = 2;
	// stb r29,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r29.u8);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82634ec8
	ctx.lr = 0x826690F4;
	sub_82634EC8(ctx, base);
loc_826690F4:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826698ac
	if (cr6.eq) goto loc_826698AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82666ef8
	ctx.lr = 0x82669108;
	sub_82666EF8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669114:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6112
	ctx.r3.s64 = r11.s64 + 6112;
	// bl 0x82661508
	ctx.lr = 0x82669124;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82669200
	if (cr6.eq) goto loc_82669200;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826691e0
	if (cr6.eq) goto loc_826691E0;
	// lwz r30,76(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826691e0
	if (!cr6.gt) goto loc_826691E0;
	// bl 0x8265e5e8
	ctx.lr = 0x82669154;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826691e0
	if (cr6.eq) goto loc_826691E0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823dc018
	ctx.lr = 0x82669174;
	sub_823DC018(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r9,-2496
	ctx.r4.s64 = ctx.r9.s64 + -2496;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8266918C;
	sub_822183B0(ctx, base);
	// lis r8,-32154
	ctx.r8.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,31728
	ctx.r4.s64 = ctx.r8.s64 + 31728;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x821c2fb0
	ctx.lr = 0x826691A8;
	sub_821C2FB0(ctx, base);
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r7,13380
	ctx.r6.s64 = ctx.r7.s64 + 13380;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// li r29,0
	r29.s64 = 0;
	// addi r5,r5,-2516
	ctx.r5.s64 = ctx.r5.s64 + -2516;
	// li r7,2
	ctx.r7.s64 = 2;
	// stb r29,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r29.u8);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82634ec8
	ctx.lr = 0x826691E0;
	sub_82634EC8(ctx, base);
loc_826691E0:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826698ac
	if (cr6.eq) goto loc_826698AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82667630
	ctx.lr = 0x826691F4;
	sub_82667630(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669200:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6096
	ctx.r3.s64 = r11.s64 + 6096;
	// bl 0x82661508
	ctx.lr = 0x82669210;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826692ec
	if (cr6.eq) goto loc_826692EC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// lwz r11,-10016(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826692cc
	if (cr6.eq) goto loc_826692CC;
	// lwz r30,76(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826692cc
	if (!cr6.gt) goto loc_826692CC;
	// bl 0x8265e5e8
	ctx.lr = 0x82669240;
	sub_8265E5E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826692cc
	if (cr6.eq) goto loc_826692CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823dc018
	ctx.lr = 0x82669260;
	sub_823DC018(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r9,-2496
	ctx.r4.s64 = ctx.r9.s64 + -2496;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82669278;
	sub_822183B0(ctx, base);
	// lis r8,-32154
	ctx.r8.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,31808
	ctx.r4.s64 = ctx.r8.s64 + 31808;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x821c2fb0
	ctx.lr = 0x82669294;
	sub_821C2FB0(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stb r29,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r29.u8);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r7,13380
	ctx.r6.s64 = ctx.r7.s64 + 13380;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// addi r5,r5,-2516
	ctx.r5.s64 = ctx.r5.s64 + -2516;
	// li r7,2
	ctx.r7.s64 = 2;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82634ec8
	ctx.lr = 0x826692CC;
	sub_82634EC8(ctx, base);
loc_826692CC:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826698ac
	if (cr6.eq) goto loc_826698AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82667898
	ctx.lr = 0x826692E0;
	sub_82667898(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_826692EC:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5520
	ctx.r3.s64 = r11.s64 + 5520;
	// bl 0x82661508
	ctx.lr = 0x826692FC;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669424
	if (!cr6.eq) goto loc_82669424;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x82661508
	ctx.lr = 0x82669318;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669424
	if (!cr6.eq) goto loc_82669424;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5548
	ctx.r3.s64 = r11.s64 + 5548;
	// bl 0x82661508
	ctx.lr = 0x82669334;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266935c
	if (!cr6.eq) goto loc_8266935C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5640
	ctx.r3.s64 = r11.s64 + 5640;
	// bl 0x82661508
	ctx.lr = 0x82669350;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826686ac
	if (cr6.eq) goto loc_826686AC;
loc_8266935C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82669414
	if (cr6.eq) goto loc_82669414;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,26160
	ctx.r4.s64 = r11.s64 + 26160;
	// addi r3,r1,304
	ctx.r3.s64 = ctx.r1.s64 + 304;
	// bl 0x821c2fb0
	ctx.lr = 0x82669398;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826693AC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826693ac
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826693AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r10,13260
	r29.s64 = ctx.r10.s64 + 13260;
	// lwz r9,84(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826693DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82669408;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669414:
	// bl 0x82666408
	ctx.lr = 0x82669418;
	sub_82666408(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669424:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669438;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82669450
	if (cr6.eq) goto loc_82669450;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,13232
	r30.s64 = r11.s64 + 13232;
	// b 0x82669458
	goto loc_82669458;
loc_82669450:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,13204
	r30.s64 = r11.s64 + 13204;
loc_82669458:
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,24520
	ctx.r4.s64 = r11.s64 + 24520;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x821c2fb0
	ctx.lr = 0x82669474;
	sub_821C2FB0(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r29,8(r3)
	r29.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r7,r10,5104
	ctx.r7.s64 = ctx.r10.s64 + 5104;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r9,13180
	ctx.r6.s64 = ctx.r9.s64 + 13180;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// std r29,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r29.u64);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x826694B0;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_826694BC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826694D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,24824
	ctx.r4.s64 = r11.s64 + 24824;
	// bne cr6,0x82669584
	if (!cr6.eq) goto loc_82669584;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x821c2fb0
	ctx.lr = 0x826694F8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266950C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8266950c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266950C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266954C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82669578;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669584:
	// addi r3,r1,496
	ctx.r3.s64 = ctx.r1.s64 + 496;
	// bl 0x821c2fb0
	ctx.lr = 0x8266958C;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266959C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8266959c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266959C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826695C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,96(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826695DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,92(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826695F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x82669628;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669634:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669648;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82669664
	if (cr6.eq) goto loc_82669664;
	// bl 0x82665ce0
	ctx.lr = 0x82669658;
	sub_82665CE0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669664:
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,27528
	ctx.r4.s64 = r11.s64 + 27528;
	// addi r3,r1,560
	ctx.r3.s64 = ctx.r1.s64 + 560;
	// bl 0x821c2fb0
	ctx.lr = 0x82669680;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82669694:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82669694
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82669694;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r10,13156
	r29.s64 = ctx.r10.s64 + 13156;
	// lwz r9,88(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826696C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,112(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x826696F0;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_826696FC:
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,27592
	ctx.r4.s64 = r11.s64 + 27592;
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x821c2fb0
	ctx.lr = 0x82669718;
	sub_821C2FB0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// stb r11,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r11.u8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r6,r10,13132
	ctx.r6.s64 = ctx.r10.s64 + 13132;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r5,r9,13100
	ctx.r5.s64 = ctx.r9.s64 + 13100;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,1808
	ctx.r3.s64 = r31.s64 + 1808;
	// bl 0x82634ec8
	ctx.lr = 0x82669750;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_8266975C:
	// lwz r3,-10028(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// bl 0x82212608
	ctx.lr = 0x82669764;
	sub_82212608(ctx, base);
	// bl 0x8265f568
	ctx.lr = 0x82669768;
	sub_8265F568(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82665940
	ctx.lr = 0x82669770;
	sub_82665940(ctx, base);
	// lwz r11,656(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 656);
	// addi r3,r27,656
	ctx.r3.s64 = r27.s64 + 656;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669790:
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,26224
	ctx.r4.s64 = r11.s64 + 26224;
	// addi r3,r1,688
	ctx.r3.s64 = ctx.r1.s64 + 688;
	// bl 0x821c2fb0
	ctx.lr = 0x826697AC;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r7,r10,5104
	ctx.r7.s64 = ctx.r10.s64 + 5104;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r9,13072
	ctx.r6.s64 = ctx.r9.s64 + 13072;
	// addi r5,r8,13036
	ctx.r5.s64 = ctx.r8.s64 + 13036;
	// li r9,0
	ctx.r9.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x826697EC;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_826697F8:
	// bl 0x82256058
	ctx.lr = 0x826697FC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266984c
	if (cr6.eq) goto loc_8266984C;
	// bl 0x82256058
	ctx.lr = 0x82669808;
	sub_82256058(ctx, base);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266984c
	if (cr6.eq) goto loc_8266984C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266982C;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82669840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_8266984C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82669858;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
loc_82669864:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826698ac
	if (!cr6.eq) goto loc_826698AC;
	// lwz r3,-10028(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// bl 0x82207138
	ctx.lr = 0x8266988C;
	sub_82207138(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826698ac
	if (!cr6.eq) goto loc_826698AC;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x826698A4;
	sub_821E6800(ctx, base);
loc_826698A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82668480
	ctx.lr = 0x826698AC;
	sub_82668480(ctx, base);
loc_826698AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,768
	ctx.r1.s64 = ctx.r1.s64 + 768;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826698B8"))) PPC_WEAK_FUNC(sub_826698B8);
PPC_FUNC_IMPL(__imp__sub_826698B8) {
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
	ctx.lr = 0x826698C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// bne cr6,0x82669978
	if (!cr6.eq) goto loc_82669978;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5700
	ctx.r3.s64 = r11.s64 + 5700;
	// bl 0x82661508
	ctx.lr = 0x826698E8;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82669978
	if (cr6.eq) goto loc_82669978;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266990C;
	sub_82641CB0(ctx, base);
	// lis r10,-32154
	ctx.r10.s64 = -2107244544;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,27728
	ctx.r4.s64 = ctx.r10.s64 + 27728;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2fb0
	ctx.lr = 0x8266992C;
	sub_821C2FB0(ctx, base);
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lwz r29,16(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r7,r9,5104
	ctx.r7.s64 = ctx.r9.s64 + 5104;
	// addi r6,r8,13460
	ctx.r6.s64 = ctx.r8.s64 + 13460;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// addi r5,r5,13432
	ctx.r5.s64 = ctx.r5.s64 + 13432;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x8266996C;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82669978:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82668660
	ctx.lr = 0x82669988;
	sub_82668660(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82669990"))) PPC_WEAK_FUNC(sub_82669990);
PPC_FUNC_IMPL(__imp__sub_82669990) {
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
	ctx.lr = 0x82669998;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204018
	ctx.lr = 0x826699B8;
	sub_82204018(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// addi r9,r3,-4
	ctx.r9.s64 = ctx.r3.s64 + -4;
	// ori r30,r10,16256
	r30.u64 = ctx.r10.u64 | 16256;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// li r4,71
	ctx.r4.s64 = 71;
	// rlwinm r26,r8,27,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826699E0;
	sub_82641CB0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,55
	cr6.compare<int32_t>(r28.s32, 55, xer);
	// bne cr6,0x82669a94
	if (!cr6.eq) goto loc_82669A94;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5664
	ctx.r3.s64 = r11.s64 + 5664;
	// bl 0x82661508
	ctx.lr = 0x826699FC;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669c38
	if (!cr6.eq) goto loc_82669C38;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6160
	ctx.r3.s64 = r11.s64 + 6160;
	// bl 0x82661508
	ctx.lr = 0x82669A18;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669c38
	if (!cr6.eq) goto loc_82669C38;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x82661508
	ctx.lr = 0x82669A34;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669b74
	if (!cr6.eq) goto loc_82669B74;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x82661508
	ctx.lr = 0x82669A50;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669b74
	if (!cr6.eq) goto loc_82669B74;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5520
	ctx.r3.s64 = r11.s64 + 5520;
	// bl 0x82661508
	ctx.lr = 0x82669A6C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669aac
	if (!cr6.eq) goto loc_82669AAC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x82661508
	ctx.lr = 0x82669A88;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669aac
	if (!cr6.eq) goto loc_82669AAC;
loc_82669A94:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82668660
	ctx.lr = 0x82669AA4;
	sub_82668660(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d923c
	return;
loc_82669AAC:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// li r7,1
	ctx.r7.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,24520
	ctx.r4.s64 = r11.s64 + 24520;
	// beq cr6,0x82669b20
	if (cr6.eq) goto loc_82669B20;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x821c2fb0
	ctx.lr = 0x82669AD4;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r7,r10,5104
	ctx.r7.s64 = ctx.r10.s64 + 5104;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r9,13576
	ctx.r6.s64 = ctx.r9.s64 + 13576;
	// addi r5,r8,13540
	ctx.r5.s64 = ctx.r8.s64 + 13540;
	// li r9,0
	ctx.r9.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x82669B14;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d923c
	return;
loc_82669B20:
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x821c2fb0
	ctx.lr = 0x82669B28;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r30,16(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r7,r10,5104
	ctx.r7.s64 = ctx.r10.s64 + 5104;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r9,13516
	ctx.r6.s64 = ctx.r9.s64 + 13516;
	// addi r5,r8,13484
	ctx.r5.s64 = ctx.r8.s64 + 13484;
	// li r9,0
	ctx.r9.s64 = 0;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x82669B68;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d923c
	return;
loc_82669B74:
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,24824
	ctx.r4.s64 = r11.s64 + 24824;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821c2fb0
	ctx.lr = 0x82669B90;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82669BA0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82669ba0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82669BA0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 100);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,96(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82669BE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,92(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82669BF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,128(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// ld r11,120(r1)
	r11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// ld r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826624c8
	ctx.lr = 0x82669C2C;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d923c
	return;
loc_82669C38:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,50
	ctx.r4.s64 = 50;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82669C4C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,808(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 808);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82669C60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,704(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 704);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82669C78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82669C84"))) PPC_WEAK_FUNC(sub_82669C84);
PPC_FUNC_IMPL(__imp__sub_82669C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82669C88"))) PPC_WEAK_FUNC(sub_82669C88);
PPC_FUNC_IMPL(__imp__sub_82669C88) {
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
	ctx.lr = 0x82669C90;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r30,r10,16256
	r30.u64 = ctx.r10.u64 | 16256;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// li r4,71
	ctx.r4.s64 = 71;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82669CBC;
	sub_82641CB0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,55
	cr6.compare<int32_t>(r29.s32, 55, xer);
	// bne cr6,0x82669db4
	if (!cr6.eq) goto loc_82669DB4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5664
	ctx.r3.s64 = r11.s64 + 5664;
	// bl 0x82661508
	ctx.lr = 0x82669CD8;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669e74
	if (!cr6.eq) goto loc_82669E74;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6160
	ctx.r3.s64 = r11.s64 + 6160;
	// bl 0x82661508
	ctx.lr = 0x82669CF4;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669e74
	if (!cr6.eq) goto loc_82669E74;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x82661508
	ctx.lr = 0x82669D10;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669dcc
	if (!cr6.eq) goto loc_82669DCC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x82661508
	ctx.lr = 0x82669D2C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82669dcc
	if (!cr6.eq) goto loc_82669DCC;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5756
	ctx.r3.s64 = r11.s64 + 5756;
	// bl 0x82661508
	ctx.lr = 0x82669D48;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82669db4
	if (cr6.eq) goto loc_82669DB4;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r29,r11,2532
	r29.s64 = r11.s64 + 2532;
	// addi r4,r10,2516
	ctx.r4.s64 = ctx.r10.s64 + 2516;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x8220ef00
	ctx.lr = 0x82669D74;
	sub_8220EF00(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823db670
	ctx.lr = 0x82669D88;
	sub_823DB670(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-9136
	ctx.r4.s64 = ctx.r8.s64 + -9136;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x821fde78
	ctx.lr = 0x82669DA4;
	sub_821FDE78(ctx, base);
	// bl 0x8265f428
	ctx.lr = 0x82669DA8;
	sub_8265F428(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9244
	return;
loc_82669DB4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82668660
	ctx.lr = 0x82669DC4;
	sub_82668660(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9244
	return;
loc_82669DCC:
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,24744
	ctx.r4.s64 = r11.s64 + 24744;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c2fb0
	ctx.lr = 0x82669DE8;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82669DFC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82669dfc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82669DFC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669E24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82669E3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,96(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x82669E68;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9244
	return;
loc_82669E74:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,42
	ctx.r4.s64 = 42;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82669E8C;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826748a8
	ctx.lr = 0x82669E94;
	sub_826748A8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82669EAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82669EB8"))) PPC_WEAK_FUNC(sub_82669EB8);
PPC_FUNC_IMPL(__imp__sub_82669EB8) {
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
	ctx.lr = 0x82669EC0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,71
	ctx.r4.s64 = 71;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82669EE8;
	sub_82641CB0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// bne cr6,0x8266a120
	if (!cr6.eq) goto loc_8266A120;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5520
	ctx.r3.s64 = r11.s64 + 5520;
	// bl 0x82661508
	ctx.lr = 0x82669F04;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266a138
	if (!cr6.eq) goto loc_8266A138;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x82661508
	ctx.lr = 0x82669F20;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266a138
	if (!cr6.eq) goto loc_8266A138;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5504
	ctx.r3.s64 = r11.s64 + 5504;
	// bl 0x82661508
	ctx.lr = 0x82669F3C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82669f5c
	if (cr6.eq) goto loc_82669F5C;
	// bl 0x826661a0
	ctx.lr = 0x82669F4C;
	sub_826661A0(ctx, base);
	// bl 0x8265f428
	ctx.lr = 0x82669F50;
	sub_8265F428(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_82669F5C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5464
	ctx.r3.s64 = r11.s64 + 5464;
	// bl 0x82661508
	ctx.lr = 0x82669F6C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266a020
	if (cr6.eq) goto loc_8266A020;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,25136
	ctx.r4.s64 = r11.s64 + 25136;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x821c2fb0
	ctx.lr = 0x82669F94;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82669FA8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82669fa8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82669FA8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82669FD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,104(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82669FE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,96(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x8266A014;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_8266A020:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x82661508
	ctx.lr = 0x8266A030;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266a0e4
	if (cr6.eq) goto loc_8266A0E4;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,24744
	ctx.r4.s64 = r11.s64 + 24744;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x821c2fb0
	ctx.lr = 0x8266A058;
	sub_821C2FB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266A06C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8266a06c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266A06C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266A094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266A0AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// ld r8,96(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// ld r9,104(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// stb r30,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r30.u8);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r11,32,63
	ctx.r10.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x82634ec8
	ctx.lr = 0x8266A0D8;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_8266A0E4:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x82661508
	ctx.lr = 0x8266A0F4;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266a120
	if (cr6.eq) goto loc_8266A120;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10028(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82205950
	ctx.lr = 0x8266A110;
	sub_82205950(ctx, base);
	// bl 0x82666008
	ctx.lr = 0x8266A114;
	sub_82666008(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_8266A120:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82668660
	ctx.lr = 0x8266A130;
	sub_82668660(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_8266A138:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266A14C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266a1b8
	if (!cr6.eq) goto loc_8266A1B8;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,24520
	ctx.r4.s64 = r11.s64 + 24520;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x821c2fb0
	ctx.lr = 0x8266A174;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r10,13636
	ctx.r6.s64 = ctx.r10.s64 + 13636;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r5,r9,13604
	ctx.r5.s64 = ctx.r9.s64 + 13604;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// stb r11,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r11.u8);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82634ec8
	ctx.lr = 0x8266A1AC;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
loc_8266A1B8:
	// bl 0x82665da8
	ctx.lr = 0x8266A1BC;
	sub_82665DA8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8266A1C8"))) PPC_WEAK_FUNC(sub_8266A1C8);
PPC_FUNC_IMPL(__imp__sub_8266A1C8) {
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
	ctx.lr = 0x8266A1D0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// li r4,71
	ctx.r4.s64 = 71;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266A1FC;
	sub_82641CB0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,55
	cr6.compare<int32_t>(r29.s32, 55, xer);
	// bne cr6,0x8266a2a8
	if (!cr6.eq) goto loc_8266A2A8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r25,r11,5452
	r25.s64 = r11.s64 + 5452;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82661508
	ctx.lr = 0x8266A21C;
	sub_82661508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8266a2c0
	if (!cr6.eq) goto loc_8266A2C0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5492
	ctx.r3.s64 = r11.s64 + 5492;
	// bl 0x82661508
	ctx.lr = 0x8266A238;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266a2c0
	if (!cr6.eq) goto loc_8266A2C0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5664
	ctx.r3.s64 = r11.s64 + 5664;
	// bl 0x82661508
	ctx.lr = 0x8266A254;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266a2a8
	if (cr6.eq) goto loc_8266A2A8;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// li r4,52
	ctx.r4.s64 = 52;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266A270;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,808(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 808);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266A284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,704(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 704);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266A29C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
loc_8266A2A8:
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82668660
	ctx.lr = 0x8266A2B8;
	sub_82668660(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
loc_8266A2C0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82661508
	ctx.lr = 0x8266A2CC;
	sub_82661508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266a338
	if (cr6.eq) goto loc_8266A338;
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,24928
	ctx.r4.s64 = r11.s64 + 24928;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x821c2fb0
	ctx.lr = 0x8266A2F4;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// ld r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r10,13700
	ctx.r6.s64 = ctx.r10.s64 + 13700;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r5,r9,13664
	ctx.r5.s64 = ctx.r9.s64 + 13664;
	// ld r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// li r11,0
	r11.s64 = 0;
	// li r7,3
	ctx.r7.s64 = 3;
	// rldicr r10,r10,32,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// stb r11,95(r1)
	PPC_STORE_U8(ctx.r1.u32 + 95, r11.u8);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x82634ec8
	ctx.lr = 0x8266A32C;
	sub_82634EC8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
loc_8266A338:
	// bl 0x82666008
	ctx.lr = 0x8266A33C;
	sub_82666008(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266A348"))) PPC_WEAK_FUNC(sub_8266A348);
PPC_FUNC_IMPL(__imp__sub_8266A348) {
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
	ctx.lr = 0x8266A350;
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
	// cmpwi cr6,r31,55
	cr6.compare<int32_t>(r31.s32, 55, xer);
	// bne cr6,0x8266a3a0
	if (!cr6.eq) goto loc_8266A3A0;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5664
	ctx.r3.s64 = r11.s64 + 5664;
	// bl 0x82661508
	ctx.lr = 0x8266A378;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266a3b8
	if (!cr6.eq) goto loc_8266A3B8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,6160
	ctx.r3.s64 = r11.s64 + 6160;
	// bl 0x82661508
	ctx.lr = 0x8266A394;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266a3b8
	if (!cr6.eq) goto loc_8266A3B8;
loc_8266A3A0:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82668660
	ctx.lr = 0x8266A3B0;
	sub_82668660(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8266A3B8:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,71
	ctx.r4.s64 = 71;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266A3D4;
	sub_82641CB0(ctx, base);
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,49
	ctx.r4.s64 = 49;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266A3E8;
	sub_82641CB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,808(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 808);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266A3FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,704(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 704);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266A414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266A420"))) PPC_WEAK_FUNC(sub_8266A420);
PPC_FUNC_IMPL(__imp__sub_8266A420) {
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
	ctx.lr = 0x8266A428;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// bne cr6,0x8266a478
	if (!cr6.eq) goto loc_8266A478;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5520
	ctx.r3.s64 = r11.s64 + 5520;
	// bl 0x82661508
	ctx.lr = 0x8266A450;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266a490
	if (!cr6.eq) goto loc_8266A490;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5628
	ctx.r3.s64 = r11.s64 + 5628;
	// bl 0x82661508
	ctx.lr = 0x8266A46C;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266a490
	if (!cr6.eq) goto loc_8266A490;
loc_8266A478:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82668660
	ctx.lr = 0x8266A488;
	sub_82668660(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
loc_8266A490:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266A4A8;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266A4C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8266a4d8
	if (cr6.eq) goto loc_8266A4D8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,13776
	r30.s64 = r11.s64 + 13776;
	// b 0x8266a4e0
	goto loc_8266A4E0;
loc_8266A4D8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r30,r11,13748
	r30.s64 = r11.s64 + 13748;
loc_8266A4E0:
	// lis r11,-32154
	r11.s64 = -2107244544;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,24520
	ctx.r4.s64 = r11.s64 + 24520;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2fb0
	ctx.lr = 0x8266A4FC;
	sub_821C2FB0(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lwz r28,16(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// addi r7,r10,5104
	ctx.r7.s64 = ctx.r10.s64 + 5104;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// addi r6,r9,13728
	ctx.r6.s64 = ctx.r9.s64 + 13728;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x8266A538;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266A544"))) PPC_WEAK_FUNC(sub_8266A544);
PPC_FUNC_IMPL(__imp__sub_8266A544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266A548"))) PPC_WEAK_FUNC(sub_8266A548);
PPC_FUNC_IMPL(__imp__sub_8266A548) {
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
	ctx.lr = 0x8266A550;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// bne cr6,0x8266a608
	if (!cr6.eq) goto loc_8266A608;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5732
	ctx.r3.s64 = r11.s64 + 5732;
	// bl 0x82661508
	ctx.lr = 0x8266A578;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266a608
	if (cr6.eq) goto loc_8266A608;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266A59C;
	sub_82641CB0(ctx, base);
	// lis r10,-32154
	ctx.r10.s64 = -2107244544;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,27880
	ctx.r4.s64 = ctx.r10.s64 + 27880;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2fb0
	ctx.lr = 0x8266A5BC;
	sub_821C2FB0(ctx, base);
	// ld r11,8(r3)
	r11.u64 = PPC_LOAD_U64(ctx.r3.u32 + 8);
	// lwz r29,16(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r7,r9,13860
	ctx.r7.s64 = ctx.r9.s64 + 13860;
	// addi r6,r8,13828
	ctx.r6.s64 = ctx.r8.s64 + 13828;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r11.u64);
	// addi r5,r5,13796
	ctx.r5.s64 = ctx.r5.s64 + 13796;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,3600
	ctx.r3.s64 = r31.s64 + 3600;
	// bl 0x826624c8
	ctx.lr = 0x8266A5FC;
	sub_826624C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_8266A608:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82668660
	ctx.lr = 0x8266A618;
	sub_82668660(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266A620"))) PPC_WEAK_FUNC(sub_8266A620);
PPC_FUNC_IMPL(__imp__sub_8266A620) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,17
	cr6.compare<int32_t>(ctx.r4.s32, 17, xer);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4992, temp.u32);
	// beq cr6,0x8266a708
	if (cr6.eq) goto loc_8266A708;
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8266a670
	if (cr6.eq) goto loc_8266A670;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x8266a708
	if (cr6.eq) goto loc_8266A708;
	// bl 0x82668660
	ctx.lr = 0x8266A65C;
	sub_82668660(ctx, base);
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
loc_8266A670:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5452
	ctx.r3.s64 = r11.s64 + 5452;
	// bl 0x82661508
	ctx.lr = 0x8266A680;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266a694
	if (cr6.eq) goto loc_8266A694;
	// bl 0x82665ce0
	ctx.lr = 0x8266A690;
	sub_82665CE0(ctx, base);
	// b 0x8266a72c
	goto loc_8266A72C;
loc_8266A694:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5464
	ctx.r3.s64 = r11.s64 + 5464;
	// bl 0x82661508
	ctx.lr = 0x8266A6A4;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266a6e8
	if (cr6.eq) goto loc_8266A6E8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266A6C8;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266A6D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82666e28
	ctx.lr = 0x8266A6E0;
	sub_82666E28(ctx, base);
	// bl 0x8265f428
	ctx.lr = 0x8266A6E4;
	sub_8265F428(ctx, base);
	// b 0x8266a72c
	goto loc_8266A72C;
loc_8266A6E8:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r11,5480
	ctx.r3.s64 = r11.s64 + 5480;
	// bl 0x82661508
	ctx.lr = 0x8266A6F8;
	sub_82661508(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266a72c
	if (cr6.eq) goto loc_8266A72C;
	// b 0x8266a724
	goto loc_8266A724;
loc_8266A708:
	// bl 0x8265eb48
	ctx.lr = 0x8266A70C;
	sub_8265EB48(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266a72c
	if (cr6.eq) goto loc_8266A72C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8266A724;
	sub_821E6800(ctx, base);
loc_8266A724:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8265fc90
	ctx.lr = 0x8266A72C;
	sub_8265FC90(ctx, base);
loc_8266A72C:
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

__attribute__((alias("__imp__sub_8266A744"))) PPC_WEAK_FUNC(sub_8266A744);
PPC_FUNC_IMPL(__imp__sub_8266A744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266A748"))) PPC_WEAK_FUNC(sub_8266A748);
PPC_FUNC_IMPL(__imp__sub_8266A748) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,64
	ctx.r10.s64 = ctx.r3.s64 + 64;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
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
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266A798:
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8266a798
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266A798;
	// stb r11,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, r11.u8);
	// stb r11,73(r3)
	PPC_STORE_U8(ctx.r3.u32 + 73, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266A7B0"))) PPC_WEAK_FUNC(sub_8266A7B0);
PPC_FUNC_IMPL(__imp__sub_8266A7B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_8266A7BC:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// beq cr6,0x8266a7d8
	if (cr6.eq) goto loc_8266A7D8;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lbz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 64);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8266a7f0
	if (cr6.eq) goto loc_8266A7F0;
loc_8266A7D8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266a7bc
	if (cr6.lt) goto loc_8266A7BC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8266A7F0:
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwinm r11,r11,3,0,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// stb r9,64(r8)
	PPC_STORE_U8(ctx.r8.u32 + 64, ctx.r9.u8);
	// stb r9,73(r10)
	PPC_STORE_U8(ctx.r10.u32 + 73, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266A80C"))) PPC_WEAK_FUNC(sub_8266A80C);
PPC_FUNC_IMPL(__imp__sub_8266A80C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266A810"))) PPC_WEAK_FUNC(sub_8266A810);
PPC_FUNC_IMPL(__imp__sub_8266A810) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
loc_8266A818:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266a83c
	if (cr6.eq) goto loc_8266A83C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266a818
	if (cr6.lt) goto loc_8266A818;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8266A83C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266A844"))) PPC_WEAK_FUNC(sub_8266A844);
PPC_FUNC_IMPL(__imp__sub_8266A844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266A848"))) PPC_WEAK_FUNC(sub_8266A848);
PPC_FUNC_IMPL(__imp__sub_8266A848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// addi r11,r3,64
	r11.s64 = ctx.r3.s64 + 64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266A858:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266a858
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266A858;
	// stb r9,73(r3)
	PPC_STORE_U8(ctx.r3.u32 + 73, ctx.r9.u8);
	// stb r9,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, ctx.r9.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266A870"))) PPC_WEAK_FUNC(sub_8266A870);
PPC_FUNC_IMPL(__imp__sub_8266A870) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630158
	ctx.lr = 0x8266A88C;
	sub_82630158(ctx, base);
	// lwz r11,320(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 320);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8266a9e0
	if (cr6.lt) goto loc_8266A9E0;
	// beq cr6,0x8266a934
	if (cr6.eq) goto loc_8266A934;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8266aa4c
	if (!cr6.lt) goto loc_8266AA4C;
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-10308
	ctx.r4.s64 = ctx.r10.s64 + -10308;
	// bl 0x82722678
	ctx.lr = 0x8266A8C0;
	sub_82722678(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r5,r31,212
	ctx.r5.s64 = r31.s64 + 212;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A8D4;
	sub_82722678(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r4,r8,-11016
	ctx.r4.s64 = ctx.r8.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x8266A8E8;
	sub_827227B8(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r5,r31,308
	ctx.r5.s64 = r31.s64 + 308;
	// addi r4,r7,-11024
	ctx.r4.s64 = ctx.r7.s64 + -11024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A8FC;
	sub_82722678(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r31,252
	ctx.r5.s64 = r31.s64 + 252;
	// addi r4,r6,-11032
	ctx.r4.s64 = ctx.r6.s64 + -11032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A910;
	sub_82722678(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r5,r31,256
	ctx.r5.s64 = r31.s64 + 256;
	// addi r4,r4,2440
	ctx.r4.s64 = ctx.r4.s64 + 2440;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266A924;
	sub_827227B8(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r5,r31,281
	ctx.r5.s64 = r31.s64 + 281;
	// addi r4,r3,-3656
	ctx.r4.s64 = ctx.r3.s64 + -3656;
	// b 0x8266aa44
	goto loc_8266AA44;
loc_8266A934:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r10,-10308
	ctx.r4.s64 = ctx.r10.s64 + -10308;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A950;
	sub_82722678(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r5,r31,212
	ctx.r5.s64 = r31.s64 + 212;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A964;
	sub_82722678(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r4,r8,-11016
	ctx.r4.s64 = ctx.r8.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x8266A978;
	sub_827227B8(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r5,r31,308
	ctx.r5.s64 = r31.s64 + 308;
	// addi r4,r7,-11024
	ctx.r4.s64 = ctx.r7.s64 + -11024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A98C;
	sub_82722678(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r31,252
	ctx.r5.s64 = r31.s64 + 252;
	// addi r4,r6,-11032
	ctx.r4.s64 = ctx.r6.s64 + -11032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A9A0;
	sub_82722678(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r5,r31,256
	ctx.r5.s64 = r31.s64 + 256;
	// addi r4,r4,2440
	ctx.r4.s64 = ctx.r4.s64 + 2440;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266A9B4;
	sub_827227B8(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r5,r31,312
	ctx.r5.s64 = r31.s64 + 312;
	// addi r4,r3,-3656
	ctx.r4.s64 = ctx.r3.s64 + -3656;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A9C8;
	sub_82722678(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r31,316
	ctx.r5.s64 = r31.s64 + 316;
	// addi r4,r11,14332
	ctx.r4.s64 = r11.s64 + 14332;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A9DC;
	sub_82722678(ctx, base);
	// b 0x8266aa4c
	goto loc_8266AA4C;
loc_8266A9E0:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r10,-10308
	ctx.r4.s64 = ctx.r10.s64 + -10308;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266A9FC;
	sub_82722678(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r5,r31,212
	ctx.r5.s64 = r31.s64 + 212;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266AA10;
	sub_82722678(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r4,r8,-11016
	ctx.r4.s64 = ctx.r8.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x8266AA24;
	sub_827227B8(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,220(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// addi r4,r7,-11024
	ctx.r4.s64 = ctx.r7.s64 + -11024;
	// bl 0x827227b8
	ctx.lr = 0x8266AA38;
	sub_827227B8(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r31,224
	ctx.r5.s64 = r31.s64 + 224;
	// addi r4,r6,-11032
	ctx.r4.s64 = ctx.r6.s64 + -11032;
loc_8266AA44:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266AA4C;
	sub_827227B8(ctx, base);
loc_8266AA4C:
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

__attribute__((alias("__imp__sub_8266AA64"))) PPC_WEAK_FUNC(sub_8266AA64);
PPC_FUNC_IMPL(__imp__sub_8266AA64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266AA68"))) PPC_WEAK_FUNC(sub_8266AA68);
PPC_FUNC_IMPL(__imp__sub_8266AA68) {
	PPC_FUNC_PROLOGUE();
	// b 0x826535f8
	sub_826535F8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8266AA6C"))) PPC_WEAK_FUNC(sub_8266AA6C);
PPC_FUNC_IMPL(__imp__sub_8266AA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266AA70"))) PPC_WEAK_FUNC(sub_8266AA70);
PPC_FUNC_IMPL(__imp__sub_8266AA70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	// addi r11,r4,-7
	r11.s64 = ctx.r4.s64 + -7;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,-21868
	r12.s64 = r12.s64 + -21868;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8266AAAC;
	case 1:
		goto loc_8266AAC4;
	case 2:
		goto loc_8266AADC;
	case 3:
		goto loc_8266AAF4;
	case 4:
		goto loc_8266AB0C;
	case 5:
		goto loc_8266AB24;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-21844(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21844);
	// lwz r19,-21820(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21820);
	// lwz r19,-21796(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21796);
	// lwz r19,-21772(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21772);
	// lwz r19,-21748(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21748);
	// lwz r19,-21724(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21724);
loc_8266AAAC:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,84
	ctx.r4.s64 = ctx.r10.s64 + 84;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266AAC4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14456
	ctx.r4.s64 = ctx.r10.s64 + 14456;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266AADC:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14428
	ctx.r4.s64 = ctx.r10.s64 + 14428;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266AAF4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14400
	ctx.r4.s64 = ctx.r10.s64 + 14400;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266AB0C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14368
	ctx.r4.s64 = ctx.r10.s64 + 14368;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266AB24:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
}

__attribute__((alias("__imp__sub_8266AB3C"))) PPC_WEAK_FUNC(sub_8266AB3C);
PPC_FUNC_IMPL(__imp__sub_8266AB3C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266AB40"))) PPC_WEAK_FUNC(sub_8266AB40);
PPC_FUNC_IMPL(__imp__sub_8266AB40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r5,4528(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4528, ctx.r5.u32);
	// stw r6,10856(r3)
	PPC_STORE_U32(ctx.r3.u32 + 10856, ctx.r6.u32);
	// stb r11,4524(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4524, r11.u8);
	// b 0x82630318
	sub_82630318(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8266AB54"))) PPC_WEAK_FUNC(sub_8266AB54);
PPC_FUNC_IMPL(__imp__sub_8266AB54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266AB58"))) PPC_WEAK_FUNC(sub_8266AB58);
PPC_FUNC_IMPL(__imp__sub_8266AB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	// addi r11,r4,-2
	r11.s64 = ctx.r4.s64 + -2;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgtlr cr6
	if (cr6.gt) return;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,-21636
	r12.s64 = r12.s64 + -21636;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8266AB90;
	case 1:
		goto loc_8266ABA8;
	case 2:
		goto loc_8266ABC0;
	case 3:
		goto loc_8266ABD8;
	case 4:
		goto loc_8266ABF0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-21616(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21616);
	// lwz r19,-21592(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21592);
	// lwz r19,-21568(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21568);
	// lwz r19,-21544(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21544);
	// lwz r19,-21520(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -21520);
loc_8266AB90:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14592
	ctx.r4.s64 = ctx.r10.s64 + 14592;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266ABA8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14564
	ctx.r4.s64 = ctx.r10.s64 + 14564;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266ABC0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14540
	ctx.r4.s64 = ctx.r10.s64 + 14540;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266ABD8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14512
	ctx.r4.s64 = ctx.r10.s64 + 14512;
	// lwz r9,788(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8266ABF0:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
}

__attribute__((alias("__imp__sub_8266AC08"))) PPC_WEAK_FUNC(sub_8266AC08);
PPC_FUNC_IMPL(__imp__sub_8266AC08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266AC0C"))) PPC_WEAK_FUNC(sub_8266AC0C);
PPC_FUNC_IMPL(__imp__sub_8266AC0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266AC10"))) PPC_WEAK_FUNC(sub_8266AC10);
PPC_FUNC_IMPL(__imp__sub_8266AC10) {
	PPC_FUNC_PROLOGUE();
	// stw r5,4528(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4528, ctx.r5.u32);
	// b 0x82630318
	sub_82630318(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8266AC18"))) PPC_WEAK_FUNC(sub_8266AC18);
PPC_FUNC_IMPL(__imp__sub_8266AC18) {
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
	ctx.lr = 0x8266AC20;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// stw r4,212(r31)
	PPC_STORE_U32(r31.u32 + 212, ctx.r4.u32);
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// stw r5,216(r31)
	PPC_STORE_U32(r31.u32 + 216, ctx.r5.u32);
	// stw r29,320(r31)
	PPC_STORE_U32(r31.u32 + 320, r29.u32);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266AC4C;
	sub_82218310(ctx, base);
	// stw r3,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r3.u32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// addi r11,r31,224
	r11.s64 = r31.s64 + 224;
	// li r8,24
	ctx.r8.s64 = 24;
loc_8266AC5C:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266ad30
	if (cr6.eq) goto loc_8266AD30;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266acec
	if (cr6.eq) goto loc_8266ACEC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266acfc
	if (cr6.eq) goto loc_8266ACFC;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266ad0c
	if (cr6.eq) goto loc_8266AD0C;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266ad1c
	if (cr6.eq) goto loc_8266AD1C;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266ad2c
	if (cr6.eq) goto loc_8266AD2C;
	// stb r9,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r9.u8);
	// addic. r8,r8,-6
	xer.ca = ctx.r8.u32 > 5;
	ctx.r8.s64 = ctx.r8.s64 + -6;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// bgt 0x8266ac5c
	if (cr0.gt) goto loc_8266AC5C;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8266ACEC:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8266ACFC:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8266AD0C:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8266AD1C:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8266AD2C:
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
loc_8266AD30:
	// stb r29,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r29.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266AD3C"))) PPC_WEAK_FUNC(sub_8266AD3C);
PPC_FUNC_IMPL(__imp__sub_8266AD3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266AD40"))) PPC_WEAK_FUNC(sub_8266AD40);
PPC_FUNC_IMPL(__imp__sub_8266AD40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// li r11,1
	r11.s64 = 1;
	// stw r4,212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 212, ctx.r4.u32);
	// stw r5,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, ctx.r5.u32);
	// li r4,24
	ctx.r4.s64 = 24;
	// stw r11,320(r3)
	PPC_STORE_U32(ctx.r3.u32 + 320, r11.u32);
	// addi r11,r3,256
	r11.s64 = ctx.r3.s64 + 256;
loc_8266AD5C:
	// lbz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8266ae08
	if (cr6.eq) goto loc_8266AE08;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stb r5,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r5.u8);
	// lbz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8266ade4
	if (cr6.eq) goto loc_8266ADE4;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stb r5,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r5.u8);
	// lbz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8266adec
	if (cr6.eq) goto loc_8266ADEC;
	// stb r5,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r5.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lbz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8266adf4
	if (cr6.eq) goto loc_8266ADF4;
	// stb r5,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r5.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lbz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8266adfc
	if (cr6.eq) goto loc_8266ADFC;
	// stb r5,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r5.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// lbz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r6.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8266ae04
	if (cr6.eq) goto loc_8266AE04;
	// stb r5,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r5.u8);
	// addic. r4,r4,-6
	xer.ca = ctx.r4.u32 > 5;
	ctx.r4.s64 = ctx.r4.s64 + -6;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// bgt 0x8266ad5c
	if (cr0.gt) goto loc_8266AD5C;
	// b 0x8266ae08
	goto loc_8266AE08;
loc_8266ADE4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8266ae08
	goto loc_8266AE08;
loc_8266ADEC:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x8266ae08
	goto loc_8266AE08;
loc_8266ADF4:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x8266ae08
	goto loc_8266AE08;
loc_8266ADFC:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// b 0x8266ae08
	goto loc_8266AE08;
loc_8266AE04:
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
loc_8266AE08:
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r6,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r6.u8);
	// stw r7,252(r3)
	PPC_STORE_U32(ctx.r3.u32 + 252, ctx.r7.u32);
	// stw r8,308(r3)
	PPC_STORE_U32(ctx.r3.u32 + 308, ctx.r8.u32);
	// stw r9,312(r3)
	PPC_STORE_U32(ctx.r3.u32 + 312, ctx.r9.u32);
	// stw r10,316(r3)
	PPC_STORE_U32(ctx.r3.u32 + 316, ctx.r10.u32);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266AE28"))) PPC_WEAK_FUNC(sub_8266AE28);
PPC_FUNC_IMPL(__imp__sub_8266AE28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// stw r6,308(r3)
	PPC_STORE_U32(ctx.r3.u32 + 308, ctx.r6.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r4,212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 212, ctx.r4.u32);
	// stw r5,216(r3)
	PPC_STORE_U32(ctx.r3.u32 + 216, ctx.r5.u32);
	// addi r11,r3,256
	r11.s64 = ctx.r3.s64 + 256;
	// stw r9,320(r3)
	PPC_STORE_U32(ctx.r3.u32 + 320, ctx.r9.u32);
	// li r6,24
	ctx.r6.s64 = 24;
	// stw r7,252(r3)
	PPC_STORE_U32(ctx.r3.u32 + 252, ctx.r7.u32);
loc_8266AE4C:
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8266aef8
	if (cr6.eq) goto loc_8266AEF8;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8266aed4
	if (cr6.eq) goto loc_8266AED4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stb r7,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r7.u8);
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8266aedc
	if (cr6.eq) goto loc_8266AEDC;
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8266aee4
	if (cr6.eq) goto loc_8266AEE4;
	// stb r7,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r7.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8266aeec
	if (cr6.eq) goto loc_8266AEEC;
	// stb r7,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r7.u8);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lbz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8266aef4
	if (cr6.eq) goto loc_8266AEF4;
	// stb r7,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r7.u8);
	// addic. r6,r6,-6
	xer.ca = ctx.r6.u32 > 5;
	ctx.r6.s64 = ctx.r6.s64 + -6;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// bgt 0x8266ae4c
	if (cr0.gt) goto loc_8266AE4C;
	// b 0x8266aef8
	goto loc_8266AEF8;
loc_8266AED4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8266aef8
	goto loc_8266AEF8;
loc_8266AEDC:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// b 0x8266aef8
	goto loc_8266AEF8;
loc_8266AEE4:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// b 0x8266aef8
	goto loc_8266AEF8;
loc_8266AEEC:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// b 0x8266aef8
	goto loc_8266AEF8;
loc_8266AEF4:
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
loc_8266AEF8:
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,24
	ctx.r8.s64 = 24;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// addi r11,r3,281
	r11.s64 = ctx.r3.s64 + 281;
loc_8266AF08:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266afc8
	if (cr6.eq) goto loc_8266AFC8;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266af94
	if (cr6.eq) goto loc_8266AF94;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266afa0
	if (cr6.eq) goto loc_8266AFA0;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266afac
	if (cr6.eq) goto loc_8266AFAC;
	// stb r9,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266afb8
	if (cr6.eq) goto loc_8266AFB8;
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266afc4
	if (cr6.eq) goto loc_8266AFC4;
	// stb r9,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r9.u8);
	// addic. r8,r8,-6
	xer.ca = ctx.r8.u32 > 5;
	ctx.r8.s64 = ctx.r8.s64 + -6;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// bgt 0x8266af08
	if (cr0.gt) goto loc_8266AF08;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// blr 
	return;
loc_8266AF94:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// blr 
	return;
loc_8266AFA0:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// blr 
	return;
loc_8266AFAC:
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// blr 
	return;
loc_8266AFB8:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// blr 
	return;
loc_8266AFC4:
	// addi r11,r11,5
	r11.s64 = r11.s64 + 5;
loc_8266AFC8:
	// stb r7,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r7.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8266AFD0"))) PPC_WEAK_FUNC(sub_8266AFD0);
PPC_FUNC_IMPL(__imp__sub_8266AFD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r10,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r10.u8);
	// b 0x82216138
	sub_82216138(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8266AFE8"))) PPC_WEAK_FUNC(sub_8266AFE8);
PPC_FUNC_IMPL(__imp__sub_8266AFE8) {
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
	ctx.lr = 0x8266AFF0;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// ld r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// bl 0x823dba80
	ctx.lr = 0x8266B010;
	sub_823DBA80(ctx, base);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,31016(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31016);
	f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fdivs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// beq 0x8266b07c
	if (cr0.eq) goto loc_8266B07C;
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// std r8,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// frsp f8,f12
	ctx.f8.f64 = double(float(ctx.f12.f64));
	// fdivs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 / ctx.f8.f64));
	// fmuls f31,f7,f0
	f31.f64 = double(float(ctx.f7.f64 * f0.f64));
	// b 0x8266b084
	goto loc_8266B084;
loc_8266B07C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8266B084:
	// stfd f1,40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r30,r11,-5880
	r30.s64 = r11.s64 + -5880;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x8266B0A4;
	sub_82137A08(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// addi r29,r11,14620
	r29.s64 = r11.s64 + 14620;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8266B0B4:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266b0b4
	if (!cr6.eq) goto loc_8266B0B4;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8266B0C8:
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
	// bne cr6,0x8266b0c8
	if (!cr6.eq) goto loc_8266B0C8;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8266B0FC;
	sub_82137A08(ctx, base);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
loc_8266B104:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266b104
	if (!cr6.eq) goto loc_8266B104;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_8266B118:
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
	// bne cr6,0x8266b118
	if (!cr6.eq) goto loc_8266B118;
	// mulli r11,r26,336
	r11.s64 = r26.s64 * 336;
	// ld r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r4,16(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// add r11,r11,r27
	r11.u64 = r11.u64 + r27.u64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,88
	ctx.r8.s64 = ctx.r1.s64 + 88;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r11,992
	ctx.r3.s64 = r11.s64 + 992;
	// bl 0x8266ae28
	ctx.lr = 0x8266B158;
	sub_8266AE28(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266B164"))) PPC_WEAK_FUNC(sub_8266B164);
PPC_FUNC_IMPL(__imp__sub_8266B164) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266B168"))) PPC_WEAK_FUNC(sub_8266B168);
PPC_FUNC_IMPL(__imp__sub_8266B168) {
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
	ctx.lr = 0x8266B170;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x8266b18c
	if (cr6.gt) goto loc_8266B18C;
	// stw r10,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r10.u32);
loc_8266B18C:
	// lwz r9,4352(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4352);
	// addi r11,r31,4352
	r11.s64 = r31.s64 + 4352;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266b1b8
	if (cr6.eq) goto loc_8266B1B8;
	// lbz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266b1b8
	if (!cr6.eq) goto loc_8266B1B8;
	// stb r10,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r10.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r10,73(r11)
	PPC_STORE_U8(r11.u32 + 73, ctx.r10.u8);
	// b 0x8266b1bc
	goto loc_8266B1BC;
loc_8266B1B8:
	// li r30,0
	r30.s64 = 0;
loc_8266B1BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r29,4508(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// bl 0x82388580
	ctx.lr = 0x8266B1C8;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r31,4544
	r31.s64 = r31.s64 + 4544;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266B1E0;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x8266B1F0;
	sub_82272E00(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266B1F8"))) PPC_WEAK_FUNC(sub_8266B1F8);
PPC_FUNC_IMPL(__imp__sub_8266B1F8) {
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
	ctx.lr = 0x8266B200;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r30,4428
	r11.s64 = r30.s64 + 4428;
	// lwz r10,4428(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4428);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8266b238
	if (cr6.eq) goto loc_8266B238;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266b238
	if (!cr6.eq) goto loc_8266B238;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// stb r10,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r10.u8);
	// stb r10,73(r11)
	PPC_STORE_U8(r11.u32 + 73, ctx.r10.u8);
	// b 0x8266b23c
	goto loc_8266B23C;
loc_8266B238:
	// li r31,0
	r31.s64 = 0;
loc_8266B23C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266B244;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266B258;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8266B260;
	sub_824E7110(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266B26C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r30,r30,10248
	r30.s64 = r30.s64 + 10248;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266B280;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82272df8
	ctx.lr = 0x8266B294;
	sub_82272DF8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266B29C"))) PPC_WEAK_FUNC(sub_8266B29C);
PPC_FUNC_IMPL(__imp__sub_8266B29C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266B2A0"))) PPC_WEAK_FUNC(sub_8266B2A0);
PPC_FUNC_IMPL(__imp__sub_8266B2A0) {
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
	ctx.lr = 0x8266B2A8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// ld r4,24(r28)
	ctx.r4.u64 = PPC_LOAD_U64(r28.u32 + 24);
	// bl 0x8223de50
	ctx.lr = 0x8266B2C8;
	sub_8223DE50(ctx, base);
	// lwz r3,16(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// bl 0x82396fb8
	ctx.lr = 0x8266B2D0;
	sub_82396FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266b2e4
	if (cr6.eq) goto loc_8266B2E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,10872(r31)
	PPC_STORE_U32(r31.u32 + 10872, r11.u32);
	// b 0x8266b2f0
	goto loc_8266B2F0;
loc_8266B2E4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,6316
	ctx.r10.s64 = r11.s64 + 6316;
	// stw r10,10872(r31)
	PPC_STORE_U32(r31.u32 + 10872, ctx.r10.u32);
loc_8266B2F0:
	// mulli r11,r29,336
	r11.s64 = r29.s64 * 336;
	// lwz r6,10872(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 10872);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,992
	ctx.r3.s64 = r11.s64 + 992;
	// bl 0x8266ac18
	ctx.lr = 0x8266B310;
	sub_8266AC18(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266B318"))) PPC_WEAK_FUNC(sub_8266B318);
PPC_FUNC_IMPL(__imp__sub_8266B318) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8266B320;
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266B340;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266b358
	if (!cr6.eq) goto loc_8266B358;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266B358:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266B360;
	sub_82388580(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266B370;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8266B378;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266b4d4
	if (cr6.eq) goto loc_8266B4D4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266B38C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266B39C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x8266B3A4;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266b4d4
	if (cr6.eq) goto loc_8266B4D4;
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// beq cr6,0x8266b42c
	if (cr6.eq) goto loc_8266B42C;
	// cmpwi cr6,r30,56
	cr6.compare<int32_t>(r30.s32, 56, xer);
	// beq cr6,0x8266b3d8
	if (cr6.eq) goto loc_8266B3D8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8266B3D0;
	sub_826537D0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266B3D8:
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266B3EC:
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266b3ec
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266B3EC;
	// stb r8,73(r10)
	PPC_STORE_U8(ctx.r10.u32 + 73, ctx.r8.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r8,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, ctx.r8.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266B414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r9,-17880
	ctx.r3.s64 = ctx.r9.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x8266B420;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266B42C:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x8266B434;
	sub_82203240(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8266b4d4
	if (cr6.gt) goto loc_8266B4D4;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,-19372
	r12.s64 = r12.s64 + -19372;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8266B464;
	case 1:
		goto loc_8266B470;
	case 2:
		goto loc_8266B47C;
	case 3:
		goto loc_8266B488;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-19356(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19356);
	// lwz r19,-19344(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19344);
	// lwz r19,-19332(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19332);
	// lwz r19,-19320(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19320);
loc_8266B464:
	// lwz r11,8220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8220);
	// addi r3,r31,8220
	ctx.r3.s64 = r31.s64 + 8220;
	// b 0x8266b490
	goto loc_8266B490;
loc_8266B470:
	// lwz r11,8816(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8816);
	// addi r3,r31,8816
	ctx.r3.s64 = r31.s64 + 8816;
	// b 0x8266b490
	goto loc_8266B490;
loc_8266B47C:
	// lwz r11,9408(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9408);
	// addi r3,r31,9408
	ctx.r3.s64 = r31.s64 + 9408;
	// b 0x8266b490
	goto loc_8266B490;
loc_8266B488:
	// lwz r11,10000(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10000);
	// addi r3,r31,10000
	ctx.r3.s64 = r31.s64 + 10000;
loc_8266B490:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266B4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x8266B4AC;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x8266b4d4
	if (cr6.eq) goto loc_8266B4D4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266B4BC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266B4CC;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x8266B4D4;
	sub_822734B0(ctx, base);
loc_8266B4D4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266B4E0"))) PPC_WEAK_FUNC(sub_8266B4E0);
PPC_FUNC_IMPL(__imp__sub_8266B4E0) {
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
	// li r31,0
	r31.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,9
	ctx.r3.s64 = 9;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// stb r31,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, r31.u8);
	// bl 0x82216138
	ctx.lr = 0x8266B510;
	sub_82216138(ctx, base);
	// stb r31,10600(r30)
	PPC_STORE_U8(r30.u32 + 10600, r31.u8);
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

__attribute__((alias("__imp__sub_8266B52C"))) PPC_WEAK_FUNC(sub_8266B52C);
PPC_FUNC_IMPL(__imp__sub_8266B52C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266B530"))) PPC_WEAK_FUNC(sub_8266B530);
PPC_FUNC_IMPL(__imp__sub_8266B530) {
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
	ctx.lr = 0x8266B538;
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
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// ld r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// bl 0x823dba80
	ctx.lr = 0x8266B554;
	sub_823DBA80(ctx, base);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-5880
	ctx.r4.s64 = ctx.r8.s64 + -5880;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,31016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fdivs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// bl 0x823dc018
	ctx.lr = 0x8266B594;
	sub_823DC018(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,14620
	r11.s64 = r11.s64 + 14620;
loc_8266B5A0:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266b5a0
	if (!cr6.eq) goto loc_8266B5A0;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8266B5B4:
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
	// bne cr6,0x8266b5b4
	if (!cr6.eq) goto loc_8266B5B4;
	// mulli r11,r28,336
	r11.s64 = r28.s64 * 336;
	// ld r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U64(r31.u32 + 16);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r7,28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r11,992
	ctx.r3.s64 = r11.s64 + 992;
	// bl 0x8266ad40
	ctx.lr = 0x8266B5F8;
	sub_8266AD40(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266B600"))) PPC_WEAK_FUNC(sub_8266B600);
PPC_FUNC_IMPL(__imp__sub_8266B600) {
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
	ctx.lr = 0x8266B608;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266B624;
	sub_821F9FB8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r3,r29,672
	ctx.r3.s64 = r29.s64 + 672;
	// lwz r28,56(r10)
	r28.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// bl 0x82631f88
	ctx.lr = 0x8266B634;
	sub_82631F88(ctx, base);
	// lwz r11,856(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266b644
	if (cr6.lt) goto loc_8266B644;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8266B644:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8266b72c
	if (cr6.lt) goto loc_8266B72C;
	// beq cr6,0x8266b6f4
	if (cr6.eq) goto loc_8266B6F4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8266b664
	if (cr6.lt) goto loc_8266B664;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266B664:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r4,12
	ctx.r4.s64 = 12;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B680;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266B694;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r6,r31
	ctx.r3.u64 = ctx.r6.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B6A8;
	sub_82641CB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r5,-32246
	ctx.r5.s64 = -2113273856;
	// addi r4,r5,14624
	ctx.r4.s64 = ctx.r5.s64 + 14624;
	// lwz r10,788(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266B6C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B6D4;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r7,704(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 704);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266B6E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266B6F4:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r4,10
	ctx.r4.s64 = 10;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B710;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266B724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,10
	ctx.r4.s64 = 10;
	// b 0x8266b760
	goto loc_8266B760;
loc_8266B72C:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// li r4,14
	ctx.r4.s64 = 14;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B748;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266B75C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,14
	ctx.r4.s64 = 14;
loc_8266B760:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r6,r31
	ctx.r3.u64 = ctx.r6.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B770;
	sub_82641CB0(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,704(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 704);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266B784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266B790"))) PPC_WEAK_FUNC(sub_8266B790);
PPC_FUNC_IMPL(__imp__sub_8266B790) {
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
	ctx.lr = 0x8266B798;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r31.u8);
	// lwz r3,-10220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// bl 0x8261fb00
	ctx.lr = 0x8266B7D8;
	sub_8261FB00(ctx, base);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r8,-10256
	ctx.r4.s64 = ctx.r8.s64 + -10256;
	// stb r31,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r10,377(r11)
	PPC_STORE_U8(r11.u32 + 377, ctx.r10.u8);
	// lwz r3,-10236(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266B808;
	sub_821F9FB8(ctx, base);
	// lwz r7,256(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r3,r30,256
	ctx.r3.s64 = r30.s64 + 256;
	// lwz r5,196(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 196);
	// lwz r4,56(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 56);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8266B824;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630318
	ctx.lr = 0x8266B830;
	sub_82630318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266B838"))) PPC_WEAK_FUNC(sub_8266B838);
PPC_FUNC_IMPL(__imp__sub_8266B838) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8266B840;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266B85C;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,8
	ctx.r4.s64 = 8;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B87C;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266B890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r29,672
	ctx.r3.s64 = r29.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8266B898;
	sub_82631F88(ctx, base);
	// lwz r11,856(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266b8a8
	if (cr6.lt) goto loc_8266B8A8;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8266B8A8:
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8266bb14
	if (cr6.gt) goto loc_8266BB14;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,-18232
	r12.s64 = r12.s64 + -18232;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8266B8DC;
	case 1:
		goto loc_8266B940;
	case 2:
		goto loc_8266B9A4;
	case 3:
		goto loc_8266BA08;
	case 4:
		goto loc_8266BAB0;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-18212(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18212);
	// lwz r19,-18112(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18112);
	// lwz r19,-18012(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -18012);
	// lwz r19,-17912(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17912);
	// lwz r19,-17744(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -17744);
loc_8266B8DC:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B8F0;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14484
	ctx.r4.s64 = ctx.r10.s64 + 14484;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266B908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B91C;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266B934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266B940:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B954;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14592
	ctx.r4.s64 = ctx.r10.s64 + 14592;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266B96C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B980;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266B998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266B9A4:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B9B8;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14512
	ctx.r4.s64 = ctx.r10.s64 + 14512;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266B9D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266B9E4;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,5
	ctx.r5.s64 = 5;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266B9FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266BA08:
	// lwz r11,992(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// addi r28,r29,992
	r28.s64 = r29.s64 + 992;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// addi r4,r9,17232
	ctx.r4.s64 = ctx.r9.s64 + 17232;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266BA30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,992(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266BA44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266bab0
	if (!cr6.gt) goto loc_8266BAB0;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266BA60;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14564
	ctx.r4.s64 = ctx.r10.s64 + 14564;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266BA78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266BA8C;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266BAA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266BAB0:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266BAC4;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14540
	ctx.r4.s64 = ctx.r10.s64 + 14540;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266BADC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266BAF0;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266BB08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266BB14:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266BB20"))) PPC_WEAK_FUNC(sub_8266BB20);
PPC_FUNC_IMPL(__imp__sub_8266BB20) {
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
	ctx.lr = 0x8266BB28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r31,0
	r31.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r31.u8);
	// lwz r3,-10220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// bl 0x8261fb00
	ctx.lr = 0x8266BB68;
	sub_8261FB00(ctx, base);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-10256
	ctx.r4.s64 = ctx.r9.s64 + -10256;
	// stb r31,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r31.u8);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r31,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r31.u8);
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266BB8C;
	sub_821F9FB8(ctx, base);
	// lwz r8,256(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 256);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r3,r30,256
	ctx.r3.s64 = r30.s64 + 256;
	// lwz r6,196(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// lwz r4,56(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266BBA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630318
	ctx.lr = 0x8266BBB4;
	sub_82630318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266BBBC"))) PPC_WEAK_FUNC(sub_8266BBBC);
PPC_FUNC_IMPL(__imp__sub_8266BBBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266BBC0"))) PPC_WEAK_FUNC(sub_8266BBC0);
PPC_FUNC_IMPL(__imp__sub_8266BBC0) {
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
	ctx.lr = 0x8266BBC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266BBE4;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,13
	ctx.r4.s64 = 13;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266BC04;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266BC18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r6,-32126
	ctx.r6.s64 = -2105409536;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// li r4,13
	ctx.r4.s64 = 13;
	// addi r28,r6,29640
	r28.s64 = ctx.r6.s64 + 29640;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r27,r5,-21896
	r27.s64 = ctx.r5.s64 + -21896;
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266BC3C;
	sub_82641CB0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// bl 0x823dedd8
	ctx.lr = 0x8266BC50;
	sub_823DEDD8(ctx, base);
	// bl 0x82654c68
	ctx.lr = 0x8266BC54;
	sub_82654C68(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266BC68;
	sub_82641CB0(ctx, base);
	// addi r11,r30,672
	r11.s64 = r30.s64 + 672;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82631f88
	ctx.lr = 0x8266BC78;
	sub_82631F88(ctx, base);
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266bc88
	if (cr6.lt) goto loc_8266BC88;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8266BC88:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,700(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266BCA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10220(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x8266BCC0;
	sub_8262A058(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8266BCCC"))) PPC_WEAK_FUNC(sub_8266BCCC);
PPC_FUNC_IMPL(__imp__sub_8266BCCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266BCD0"))) PPC_WEAK_FUNC(sub_8266BCD0);
PPC_FUNC_IMPL(__imp__sub_8266BCD0) {
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
	ctx.lr = 0x8266BCD8;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r27,r11,-18768
	r27.s64 = r11.s64 + -18768;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266BCF8;
	sub_821F9FB8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r28,r11,2612
	r28.s64 = r11.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r26,56(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266BD14;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266BD24;
	sub_825ED480(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,1072
	ctx.r4.s64 = ctx.r10.s64 + 1072;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x8266BD3C;
	sub_825EE0E0(ctx, base);
	// li r9,3
	ctx.r9.s64 = 3;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-13268
	ctx.r4.s64 = ctx.r8.s64 + -13268;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82722678
	ctx.lr = 0x8266BD58;
	sub_82722678(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stb r30,5060(r31)
	PPC_STORE_U8(r31.u32 + 5060, r30.u8);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r7,6136
	ctx.r4.s64 = ctx.r7.s64 + 6136;
	// addi r31,r6,-19728
	r31.s64 = ctx.r6.s64 + -19728;
	// addi r28,r5,-22108
	r28.s64 = ctx.r5.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8266BD88;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8266BD9C;
	sub_823DEDD8(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// bl 0x826209d8
	ctx.lr = 0x8266BDAC;
	sub_826209D8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8266be44
	if (cr6.eq) goto loc_8266BE44;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266BDCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r9,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// lvx128 v61,r9,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r9,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826208d0
	ctx.lr = 0x8266BE24;
	sub_826208D0(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82625ac0
	ctx.lr = 0x8266BE40;
	sub_82625AC0(ctx, base);
	// b 0x8266be74
	goto loc_8266BE74;
loc_8266BE44:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82625f50
	ctx.lr = 0x8266BE74;
	sub_82625F50(ctx, base);
loc_8266BE74:
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stb r30,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r30.u8);
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266BEB0;
	sub_821F9FB8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8266bed8
	if (cr6.eq) goto loc_8266BED8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x8266BEC4;
	sub_82720E28(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-19772
	ctx.r4.s64 = r11.s64 + -19772;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827205a8
	ctx.lr = 0x8266BED8;
	sub_827205A8(ctx, base);
loc_8266BED8:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266BEF0;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266BF00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266BF08"))) PPC_WEAK_FUNC(sub_8266BF08);
PPC_FUNC_IMPL(__imp__sub_8266BF08) {
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
	ctx.lr = 0x8266BF10;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r29,r11,-18768
	r29.s64 = r11.s64 + -18768;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8266BF38;
	sub_821F9FB8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,56
	cr6.compare<int32_t>(r28.s32, 56, xer);
	// beq cr6,0x8266c0d8
	if (cr6.eq) goto loc_8266C0D8;
	// cmpwi cr6,r28,63
	cr6.compare<int32_t>(r28.s32, 63, xer);
	// beq cr6,0x8266bf64
	if (cr6.eq) goto loc_8266BF64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82659ec8
	ctx.lr = 0x8266BF5C;
	sub_82659EC8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266BF64:
	// lbz r11,5060(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5060);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266bf84
	if (cr6.eq) goto loc_8266BF84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8266bcd0
	ctx.lr = 0x8266BF78;
	sub_8266BCD0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266BF84:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266BF9C;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266BFB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8266c0cc
	if (cr6.eq) goto loc_8266C0CC;
	// addi r3,r30,672
	ctx.r3.s64 = r30.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x8266BFC4;
	sub_82203240(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8266c0cc
	if (cr6.lt) goto loc_8266C0CC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266BFE0;
	sub_825EE0E0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82657678
	ctx.lr = 0x8266BFE8;
	sub_82657678(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r9,352
	ctx.r9.s64 = 352;
	// lwz r10,-10236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r26,r3,-22108
	r26.s64 = ctx.r3.s64 + -22108;
	// lfs f0,6076(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 6076);
	f0.f64 = double(temp.f32);
	// addi r4,r6,6060
	ctx.r4.s64 = ctx.r6.s64 + 6060;
	// addi r27,r5,-19728
	r27.s64 = ctx.r5.s64 + -19728;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8266C034;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8266C048;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82625f50
	ctx.lr = 0x8266C06C;
	sub_82625F50(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stb r11,5060(r30)
	PPC_STORE_U8(r30.u32 + 5060, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1120(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1120, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,372(r10)
	PPC_STORE_U8(ctx.r10.u32 + 372, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1427(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1427, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1401(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1401, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,375(r10)
	PPC_STORE_U8(ctx.r10.u32 + 375, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,374(r10)
	PPC_STORE_U8(ctx.r10.u32 + 374, r11.u8);
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C0B0;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266c0bc
	if (cr6.eq) goto loc_8266C0BC;
	// bl 0x82720560
	ctx.lr = 0x8266C0BC;
	sub_82720560(ctx, base);
loc_8266C0BC:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,34
	ctx.r4.s64 = 34;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220f040
	ctx.lr = 0x8266C0CC;
	sub_8220F040(ctx, base);
loc_8266C0CC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266C0D8:
	// lbz r11,5060(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5060);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266c0f8
	if (cr6.eq) goto loc_8266C0F8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8266bcd0
	ctx.lr = 0x8266C0EC;
	sub_8266BCD0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266C0F8:
	// li r4,56
	ctx.r4.s64 = 56;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82659ec8
	ctx.lr = 0x8266C108;
	sub_82659EC8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266C110"))) PPC_WEAK_FUNC(sub_8266C110);
PPC_FUNC_IMPL(__imp__sub_8266C110) {
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
	ctx.lr = 0x8266C118;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r30,5024
	ctx.r3.s64 = r30.s64 + 5024;
	// lwz r11,5024(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 5024);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266C134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8266c2d8
	if (cr6.eq) goto loc_8266C2D8;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8266C148;
	sub_8238EC00(ctx, base);
	// addi r29,r30,672
	r29.s64 = r30.s64 + 672;
	// lwz r31,864(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82631f88
	ctx.lr = 0x8266C15C;
	sub_82631F88(ctx, base);
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266c16c
	if (cr6.lt) goto loc_8266C16C;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8266C16C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266C188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266c2d8
	if (cr6.eq) goto loc_8266C2D8;
	// lwz r27,864(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x82203240
	ctx.lr = 0x8266C1A0;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C1B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82389800
	ctx.lr = 0x8266C1C4;
	sub_82389800(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r24,864(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C1EC;
	sub_82641CB0(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r26,0(r24)
	r26.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r25,0(r23)
	r25.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// bl 0x82203240
	ctx.lr = 0x8266C200;
	sub_82203240(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,12(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 12);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C218;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r7,788(r25)
	ctx.r7.u64 = PPC_LOAD_U32(r25.u32 + 788);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266C22C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r6,16(r27)
	ctx.r6.u64 = PPC_LOAD_U16(r27.u32 + 16);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// cmpwi cr6,r5,110
	cr6.compare<int32_t>(ctx.r5.s32, 110, xer);
	// bgt cr6,0x8266c2d8
	if (cr6.gt) goto loc_8266C2D8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// bl 0x821f9fb8
	ctx.lr = 0x8266C24C;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r26,56(r3)
	r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r31
	ctx.r3.u64 = ctx.r10.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C264;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r8,196(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C28C;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r29,r30,5052
	r29.s64 = r30.s64 + 5052;
	// lwz r31,0(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82203240
	ctx.lr = 0x8266C2A0;
	sub_82203240(ctx, base);
	// lhz r5,16(r27)
	ctx.r5.u64 = PPC_LOAD_U16(r27.u32 + 16);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r10,688(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 688);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// extsh r11,r5
	r11.s64 = ctx.r5.s16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266C2CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
loc_8266C2D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8266C2E4"))) PPC_WEAK_FUNC(sub_8266C2E4);
PPC_FUNC_IMPL(__imp__sub_8266C2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266C2E8"))) PPC_WEAK_FUNC(sub_8266C2E8);
PPC_FUNC_IMPL(__imp__sub_8266C2E8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// stw r5,5048(r31)
	PPC_STORE_U32(r31.u32 + 5048, ctx.r5.u32);
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C31C;
	sub_821F9FB8(ctx, base);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266C338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8266C344;
	sub_82630318(ctx, base);
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

__attribute__((alias("__imp__sub_8266C35C"))) PPC_WEAK_FUNC(sub_8266C35C);
PPC_FUNC_IMPL(__imp__sub_8266C35C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266C360"))) PPC_WEAK_FUNC(sub_8266C360);
PPC_FUNC_IMPL(__imp__sub_8266C360) {
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
	ctx.lr = 0x8266C368;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C384;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,7
	ctx.r4.s64 = 7;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C3A4;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266C3B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r6,r31
	ctx.r3.u64 = ctx.r6.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C3CC;
	sub_82641CB0(ctx, base);
	// addi r31,r30,672
	r31.s64 = r30.s64 + 672;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8266C3DC;
	sub_82631F88(ctx, base);
	// lwz r11,856(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// mr r28,r11
	r28.u64 = r11.u64;
	// blt cr6,0x8266c3f0
	if (cr6.lt) goto loc_8266C3F0;
	// addi r28,r3,-1
	r28.s64 = ctx.r3.s64 + -1;
loc_8266C3F0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8266C3F8;
	sub_82631F88(ctx, base);
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r10,r3
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266c408
	if (cr6.lt) goto loc_8266C408;
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
loc_8266C408:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r8,r30,1832
	ctx.r8.s64 = r30.s64 + 1832;
	// lwz r11,1824(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1824);
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r7,1828(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 1828);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,684(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 684);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C434;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266C440"))) PPC_WEAK_FUNC(sub_8266C440);
PPC_FUNC_IMPL(__imp__sub_8266C440) {
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
	ctx.lr = 0x8266C448;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r27,r11,-18768
	r27.s64 = r11.s64 + -18768;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C468;
	sub_821F9FB8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r11,2612
	r30.s64 = r11.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,56(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266C484;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266C494;
	sub_825ED480(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,1072
	ctx.r4.s64 = ctx.r10.s64 + 1072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x825ee0e0
	ctx.lr = 0x8266C4AC;
	sub_825EE0E0(ctx, base);
	// li r9,3
	ctx.r9.s64 = 3;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-13268
	ctx.r4.s64 = ctx.r8.s64 + -13268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266C4C8;
	sub_82722678(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stb r30,1840(r25)
	PPC_STORE_U8(r25.u32 + 1840, r30.u8);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r7,6136
	ctx.r4.s64 = ctx.r7.s64 + 6136;
	// addi r31,r6,-19728
	r31.s64 = ctx.r6.s64 + -19728;
	// addi r28,r5,-22108
	r28.s64 = ctx.r5.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8266C4F8;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8266C50C;
	sub_823DEDD8(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// bl 0x826209d8
	ctx.lr = 0x8266C51C;
	sub_826209D8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8266c5b4
	if (cr6.eq) goto loc_8266C5B4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266C53C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r9,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,32
	ctx.r5.s64 = 32;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// lvx128 v61,r9,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r9,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826208d0
	ctx.lr = 0x8266C594;
	sub_826208D0(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82625ac0
	ctx.lr = 0x8266C5B0;
	sub_82625AC0(ctx, base);
	// b 0x8266c5e4
	goto loc_8266C5E4;
loc_8266C5B4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x82625f50
	ctx.lr = 0x8266C5E4;
	sub_82625F50(ctx, base);
loc_8266C5E4:
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stb r30,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r30.u8);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// stb r30,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r30.u8);
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C620;
	sub_821F9FB8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8266c648
	if (cr6.eq) goto loc_8266C648;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x8266C634;
	sub_82720E28(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-19772
	ctx.r4.s64 = r11.s64 + -19772;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827205a8
	ctx.lr = 0x8266C648;
	sub_827205A8(ctx, base);
loc_8266C648:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r31,r25,256
	r31.s64 = r25.s64 + 256;
	// addi r4,r11,29148
	ctx.r4.s64 = r11.s64 + 29148;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x8262ffe0
	ctx.lr = 0x8266C660;
	sub_8262FFE0(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// bl 0x821f9fb8
	ctx.lr = 0x8266C670;
	sub_821F9FB8(ctx, base);
	// lwz r9,256(r25)
	ctx.r9.u64 = PPC_LOAD_U32(r25.u32 + 256);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266C68C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r25)
	ctx.r6.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r5,184(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 184);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8266C6A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266C6A8"))) PPC_WEAK_FUNC(sub_8266C6A8);
PPC_FUNC_IMPL(__imp__sub_8266C6A8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8266C6B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C6CC;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,9
	ctx.r4.s64 = 9;
	// ori r31,r10,16256
	r31.u64 = ctx.r10.u64 | 16256;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C6EC;
	sub_82641CB0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r7,196(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266C700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r29,672
	ctx.r3.s64 = r29.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8266C708;
	sub_82631F88(ctx, base);
	// lwz r11,856(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266c718
	if (cr6.lt) goto loc_8266C718;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8266C718:
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x8266c9a8
	if (cr6.gt) goto loc_8266C9A8;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,-14536
	r12.s64 = r12.s64 + -14536;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8266C750;
	case 1:
		goto loc_8266C7B4;
	case 2:
		goto loc_8266C818;
	case 3:
		goto loc_8266C87C;
	case 4:
		goto loc_8266C8E0;
	case 5:
		goto loc_8266C944;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-14512(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14512);
	// lwz r19,-14412(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14412);
	// lwz r19,-14312(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14312);
	// lwz r19,-14212(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14212);
	// lwz r19,-14112(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14112);
	// lwz r19,-14012(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -14012);
loc_8266C750:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C764;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,84
	ctx.r4.s64 = ctx.r10.s64 + 84;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C77C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C790;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C7A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C7B4:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C7C8;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14368
	ctx.r4.s64 = ctx.r10.s64 + 14368;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C7E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C7F4;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,11
	ctx.r5.s64 = 11;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C80C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C818:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C82C;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14400
	ctx.r4.s64 = ctx.r10.s64 + 14400;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C858;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,10
	ctx.r5.s64 = 10;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C87C:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C890;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14456
	ctx.r4.s64 = ctx.r10.s64 + 14456;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C8A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C8BC;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C8D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C8E0:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C8F4;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14428
	ctx.r4.s64 = ctx.r10.s64 + 14428;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C90C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C920;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,9
	ctx.r5.s64 = 9;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C944:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C958;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,14340
	ctx.r4.s64 = ctx.r10.s64 + 14340;
	// lwz r8,788(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 788);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266C970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x8266C984;
	sub_82641CB0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,12
	ctx.r5.s64 = 12;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,700(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 700);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266C99C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8266C9A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266C9B4"))) PPC_WEAK_FUNC(sub_8266C9B4);
PPC_FUNC_IMPL(__imp__sub_8266C9B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266C9B8"))) PPC_WEAK_FUNC(sub_8266C9B8);
PPC_FUNC_IMPL(__imp__sub_8266C9B8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266C9E8;
	sub_821F9FB8(ctx, base);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266CA04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8266CA10;
	sub_82630318(ctx, base);
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

__attribute__((alias("__imp__sub_8266CA28"))) PPC_WEAK_FUNC(sub_8266CA28);
PPC_FUNC_IMPL(__imp__sub_8266CA28) {
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
	ctx.lr = 0x8266CA30;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r30,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r30.u32);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// stb r30,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r30.u8);
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266CA5C;
	sub_821F9FB8(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// addi r4,r10,14648
	ctx.r4.s64 = ctx.r10.s64 + 14648;
	// bl 0x825ee120
	ctx.lr = 0x8266CA70;
	sub_825EE120(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,10
	ctx.r8.s64 = 10;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// stw r8,860(r31)
	PPC_STORE_U32(r31.u32 + 860, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r7,65(r31)
	PPC_STORE_U8(r31.u32 + 65, ctx.r7.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r30,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r30.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r30,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, r30.u8);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r11,648(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 648);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266CAAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r4,r10,29060
	ctx.r4.s64 = ctx.r10.s64 + 29060;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// bl 0x8262ffe0
	ctx.lr = 0x8266CAC4;
	sub_8262FFE0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// addi r4,r9,-10256
	ctx.r4.s64 = ctx.r9.s64 + -10256;
	// bl 0x821f9fb8
	ctx.lr = 0x8266CAD4;
	sub_821F9FB8(ctx, base);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,196(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// lwz r4,56(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266CAF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266CAF8"))) PPC_WEAK_FUNC(sub_8266CAF8);
PPC_FUNC_IMPL(__imp__sub_8266CAF8) {
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
	ctx.lr = 0x8266CB00;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266CB24;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r9,14672
	r31.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266CB40;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266CB50;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r26,r8,2612
	r26.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9790
	ctx.lr = 0x8266CB6C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266CB7C;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8266CB94;
	sub_821C9790(ctx, base);
	// li r6,7
	ctx.r6.s64 = 7;
	// li r27,1
	r27.s64 = 1;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r22,0
	r22.s64 = 0;
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// stw r27,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r27.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r22,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r22.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266CBB8;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266CBD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,65(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 65);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266CBE8;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266CC00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r5,4524(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 4524);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8266cc24
	if (!cr6.eq) goto loc_8266CC24;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266CC20;
	sub_825EE0E0(ctx, base);
	// stb r27,4524(r30)
	PPC_STORE_U8(r30.u32 + 4524, r27.u8);
loc_8266CC24:
	// li r11,6
	r11.s64 = 6;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x8266CC40;
	sub_82722678(ctx, base);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// mr r11,r22
	r11.u64 = r22.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266cda4
	if (cr6.eq) goto loc_8266CDA4;
	// addi r29,r30,4428
	r29.s64 = r30.s64 + 4428;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8266CC58:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266cd9c
	if (cr6.eq) goto loc_8266CD9C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266cc58
	if (cr6.lt) goto loc_8266CC58;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8266CC78:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d020
	if (cr6.eq) goto loc_8266D020;
	// lbz r11,4501(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d020
	if (cr6.eq) goto loc_8266D020;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14304
	ctx.r4.s64 = ctx.r10.s64 + -14304;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266CCA4;
	sub_82218310(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CCBC;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266CCC4;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,-10240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266CCD8;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266CCE0;
	sub_824E7118(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-11016
	ctx.r4.s64 = ctx.r6.s64 + -11016;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CCF4;
	sub_827227B8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r4,-11024
	ctx.r4.s64 = ctx.r4.s64 + -11024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD08;
	sub_827227B8(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r3,-11032
	ctx.r4.s64 = ctx.r3.s64 + -11032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD1C;
	sub_827227B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,2440
	ctx.r4.s64 = r11.s64 + 2440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD30;
	sub_827227B8(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r10,-3656
	ctx.r4.s64 = ctx.r10.s64 + -3656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD44;
	sub_827227B8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,14332
	ctx.r4.s64 = ctx.r9.s64 + 14332;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CD58;
	sub_827227B8(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266CD6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r29,64
	r11.s64 = r29.s64 + 64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266CD7C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266cd7c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266CD7C;
	// stb r22,73(r29)
	PPC_STORE_U8(r29.u32 + 73, r22.u8);
	// stb r22,72(r29)
	PPC_STORE_U8(r29.u32 + 72, r22.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8266CD9C:
	// mr r11,r22
	r11.u64 = r22.u64;
	// b 0x8266cc78
	goto loc_8266CC78;
loc_8266CDA4:
	// addi r23,r30,4428
	r23.s64 = r30.s64 + 4428;
	// mr r10,r23
	ctx.r10.u64 = r23.u64;
loc_8266CDAC:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266ce78
	if (cr6.eq) goto loc_8266CE78;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266cdac
	if (cr6.lt) goto loc_8266CDAC;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8266CDCC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d020
	if (cr6.eq) goto loc_8266D020;
	// lbz r11,4501(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d020
	if (cr6.eq) goto loc_8266D020;
	// lwz r11,10248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r30,10248
	ctx.r3.s64 = r30.s64 + 10248;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266CDFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r29,40(r24)
	r29.u64 = PPC_LOAD_U32(r24.u32 + 40);
	// ld r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U64(r29.u32 + 16);
	// bl 0x823dba80
	ctx.lr = 0x8266CE0C;
	sub_823DBA80(ctx, base);
	// lwz r7,28(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r10,44(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// add. r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fdivs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// beq 0x8266ce80
	if (cr0.eq) goto loc_8266CE80;
	// lwz r8,52(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 52);
	// clrldi r9,r11,32
	ctx.r9.u64 = r11.u64 & 0xFFFFFFFF;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fdivs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 / ctx.f9.f64));
	// fmuls f31,f7,f0
	f31.f64 = double(float(ctx.f7.f64 * f0.f64));
	// b 0x8266ce88
	goto loc_8266CE88;
loc_8266CE78:
	// mr r11,r22
	r11.u64 = r22.u64;
	// b 0x8266cdcc
	goto loc_8266CDCC;
loc_8266CE80:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_8266CE88:
	// stfd f1,32(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r27,r30,10848
	r27.s64 = r30.s64 + 10848;
	// addi r26,r11,-5880
	r26.s64 = r11.s64 + -5880;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x823dc018
	ctx.lr = 0x8266CEA8;
	sub_823DC018(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// addi r25,r11,14620
	r25.s64 = r11.s64 + 14620;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8266CEB8:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266ceb8
	if (!cr6.eq) goto loc_8266CEB8;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8266CECC:
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
	// bne cr6,0x8266cecc
	if (!cr6.eq) goto loc_8266CECC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// addi r28,r30,10855
	r28.s64 = r30.s64 + 10855;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823dc018
	ctx.lr = 0x8266CF00;
	sub_823DC018(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
loc_8266CF08:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266cf08
	if (!cr6.eq) goto loc_8266CF08;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8266CF1C:
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
	// bne cr6,0x8266cf1c
	if (!cr6.eq) goto loc_8266CF1C;
	// lwz r11,16(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20268
	ctx.r4.s64 = ctx.r10.s64 + 20268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266CF50;
	sub_82722678(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266CF58;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,-10240(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266CF6C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266CF74;
	sub_824E7118(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-11016
	ctx.r4.s64 = ctx.r7.s64 + -11016;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CF88;
	sub_827227B8(ctx, base);
	// ld r11,16(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 16);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-11024
	ctx.r4.s64 = ctx.r6.s64 + -11024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266CFA4;
	sub_82722678(ctx, base);
	// lwz r8,28(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-11032
	ctx.r4.s64 = ctx.r9.s64 + -11032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x8266CFC0;
	sub_82722678(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// addi r4,r7,2440
	ctx.r4.s64 = ctx.r7.s64 + 2440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CFD4;
	sub_827227B8(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r6,-3656
	ctx.r4.s64 = ctx.r6.s64 + -3656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266CFE8;
	sub_827227B8(ctx, base);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,184(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 184);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8266CFFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r23,64
	r11.s64 = r23.s64 + 64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266D00C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266d00c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266D00C;
	// stb r22,73(r23)
	PPC_STORE_U8(r23.u32 + 73, r22.u8);
	// stb r22,72(r23)
	PPC_STORE_U8(r23.u32 + 72, r22.u8);
loc_8266D020:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8266D02C"))) PPC_WEAK_FUNC(sub_8266D02C);
PPC_FUNC_IMPL(__imp__sub_8266D02C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D030"))) PPC_WEAK_FUNC(sub_8266D030);
PPC_FUNC_IMPL(__imp__sub_8266D030) {
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
	ctx.lr = 0x8266D038;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266D058;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r9,14672
	r30.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266D074;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D084;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r26,r8,2612
	r26.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9790
	ctx.lr = 0x8266D0A0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D0B0;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8266D0C8;
	sub_821C9790(ctx, base);
	// li r6,7
	ctx.r6.s64 = 7;
	// li r26,1
	r26.s64 = 1;
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// li r25,0
	r25.s64 = 0;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stw r26,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r26.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D0EC;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266D104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,65(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D11C;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266D134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r5,4524(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 4524);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8266d158
	if (!cr6.eq) goto loc_8266D158;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266D154;
	sub_825EE0E0(ctx, base);
	// stb r26,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r26.u8);
loc_8266D158:
	// li r11,4
	r11.s64 = 4;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266D174;
	sub_82722678(ctx, base);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// mr r11,r25
	r11.u64 = r25.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266d298
	if (cr6.eq) goto loc_8266D298;
	// addi r29,r31,4428
	r29.s64 = r31.s64 + 4428;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8266D18C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266d290
	if (cr6.eq) goto loc_8266D290;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266d18c
	if (cr6.lt) goto loc_8266D18C;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8266D1AC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d3f4
	if (cr6.eq) goto loc_8266D3F4;
	// lbz r11,4501(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d3f4
	if (cr6.eq) goto loc_8266D3F4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14304
	ctx.r4.s64 = ctx.r10.s64 + -14304;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D1D8;
	sub_82218310(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D1F0;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266D1F8;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,-10240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266D20C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266D214;
	sub_824E7118(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-11016
	ctx.r4.s64 = ctx.r6.s64 + -11016;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D228;
	sub_827227B8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r4,-11024
	ctx.r4.s64 = ctx.r4.s64 + -11024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D23C;
	sub_827227B8(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r3,-11032
	ctx.r4.s64 = ctx.r3.s64 + -11032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D250;
	sub_827227B8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266D264;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r29,64
	r11.s64 = r29.s64 + 64;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266D274:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266d274
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266D274;
	// stb r25,73(r29)
	PPC_STORE_U8(r29.u32 + 73, r25.u8);
	// stb r25,72(r29)
	PPC_STORE_U8(r29.u32 + 72, r25.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
loc_8266D290:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x8266d1ac
	goto loc_8266D1AC;
loc_8266D298:
	// addi r27,r31,4428
	r27.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8266D2A0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266d320
	if (cr6.eq) goto loc_8266D320;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266d2a0
	if (cr6.lt) goto loc_8266D2A0;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8266D2C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d3f4
	if (cr6.eq) goto loc_8266D3F4;
	// lbz r11,4501(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266d3f4
	if (cr6.eq) goto loc_8266D3F4;
	// lwz r11,10248(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10248);
	// addi r3,r31,10248
	ctx.r3.s64 = r31.s64 + 10248;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266D2F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r29,40(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// addi r28,r31,10864
	r28.s64 = r31.s64 + 10864;
	// stw r3,10868(r31)
	PPC_STORE_U32(r31.u32 + 10868, ctx.r3.u32);
	// stw r9,10864(r31)
	PPC_STORE_U32(r31.u32 + 10864, ctx.r9.u32);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x82396fb8
	ctx.lr = 0x8266D30C;
	sub_82396FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// beq cr6,0x8266d328
	if (cr6.eq) goto loc_8266D328;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8266d330
	goto loc_8266D330;
loc_8266D320:
	// mr r11,r25
	r11.u64 = r25.u64;
	// b 0x8266d2c0
	goto loc_8266D2C0;
loc_8266D328:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6316
	ctx.r4.s64 = ctx.r10.s64 + 6316;
loc_8266D330:
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D338;
	sub_82218310(ctx, base);
	// stw r3,10872(r31)
	PPC_STORE_U32(r31.u32 + 10872, ctx.r3.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// ld r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U64(r29.u32 + 24);
	// bl 0x8223de50
	ctx.lr = 0x8266D348;
	sub_8223DE50(ctx, base);
	// addi r29,r31,10876
	r29.s64 = r31.s64 + 10876;
	// addi r10,r1,88
	ctx.r10.s64 = ctx.r1.s64 + 88;
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// subf r10,r10,r29
	ctx.r10.s64 = r29.s64 - ctx.r10.s64;
loc_8266D358:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8266d358
	if (!cr6.eq) goto loc_8266D358;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,20268
	ctx.r4.s64 = r11.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8266D380;
	sub_82722678(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,10868(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10868);
	// addi r4,r10,-11016
	ctx.r4.s64 = ctx.r10.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x8266D394;
	sub_827227B8(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,10872(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 10872);
	// addi r4,r9,-11024
	ctx.r4.s64 = ctx.r9.s64 + -11024;
	// bl 0x827227b8
	ctx.lr = 0x8266D3A8;
	sub_827227B8(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r8,-11032
	ctx.r4.s64 = ctx.r8.s64 + -11032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D3BC;
	sub_827227B8(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266D3D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r27,64
	r11.s64 = r27.s64 + 64;
	// mr r9,r25
	ctx.r9.u64 = r25.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266D3E0:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266d3e0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266D3E0;
	// stb r25,73(r27)
	PPC_STORE_U8(r27.u32 + 73, r25.u8);
	// stb r25,72(r27)
	PPC_STORE_U8(r27.u32 + 72, r25.u8);
loc_8266D3F4:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266D3FC"))) PPC_WEAK_FUNC(sub_8266D3FC);
PPC_FUNC_IMPL(__imp__sub_8266D3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D400"))) PPC_WEAK_FUNC(sub_8266D400);
PPC_FUNC_IMPL(__imp__sub_8266D400) {
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
	ctx.lr = 0x8266D408;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ble cr6,0x8266d42c
	if (!cr6.gt) goto loc_8266D42C;
	// lwz r30,12(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// b 0x8266d430
	goto loc_8266D430;
loc_8266D42C:
	// li r30,0
	r30.s64 = 0;
loc_8266D430:
	// lwz r29,40(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 40);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r4,24(r29)
	ctx.r4.u64 = PPC_LOAD_U64(r29.u32 + 24);
	// bl 0x8223de50
	ctx.lr = 0x8266D440;
	sub_8223DE50(ctx, base);
	// lwz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8266d478
	if (!cr6.eq) goto loc_8266D478;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r30,r10,-14304
	r30.s64 = ctx.r10.s64 + -14304;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D464;
	sub_82218310(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8266d4b0
	goto loc_8266D4B0;
loc_8266D478:
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x82396fb8
	ctx.lr = 0x8266D480;
	sub_82396FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266d494
	if (cr6.eq) goto loc_8266D494;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,8200(r31)
	PPC_STORE_U32(r31.u32 + 8200, r11.u32);
	// b 0x8266d4a0
	goto loc_8266D4A0;
loc_8266D494:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,6316
	ctx.r10.s64 = r11.s64 + 6316;
	// stw r10,8200(r31)
	PPC_STORE_U32(r31.u32 + 8200, ctx.r10.u32);
loc_8266D4A0:
	// lwz r6,8200(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8200);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r4,16(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
loc_8266D4B0:
	// mulli r11,r28,336
	r11.s64 = r28.s64 * 336;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,6848
	ctx.r3.s64 = r11.s64 + 6848;
	// bl 0x8266ac18
	ctx.lr = 0x8266D4C0;
	sub_8266AC18(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// stw r9,16(r27)
	PPC_STORE_U32(r27.u32 + 16, ctx.r9.u32);
	// stw r8,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8266D4E0"))) PPC_WEAK_FUNC(sub_8266D4E0);
PPC_FUNC_IMPL(__imp__sub_8266D4E0) {
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
	// bl 0x8266ca28
	ctx.lr = 0x8266D4FC;
	sub_8266CA28(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r4,r11,28652
	ctx.r4.s64 = r11.s64 + 28652;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x8262ffe0
	ctx.lr = 0x8266D514;
	sub_8262FFE0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-10256
	ctx.r4.s64 = ctx.r9.s64 + -10256;
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266D528;
	sub_821F9FB8(ctx, base);
	// lwz r8,256(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,196(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 196);
	// lwz r4,56(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266D544;
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

__attribute__((alias("__imp__sub_8266D55C"))) PPC_WEAK_FUNC(sub_8266D55C);
PPC_FUNC_IMPL(__imp__sub_8266D55C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D560"))) PPC_WEAK_FUNC(sub_8266D560);
PPC_FUNC_IMPL(__imp__sub_8266D560) {
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
	ctx.lr = 0x8266D568;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266D584;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r9,14672
	r30.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r28,56(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266D5A0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D5B0;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r29,56(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r28,r8,2612
	r28.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x821c9790
	ctx.lr = 0x8266D5CC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D5DC;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8266D5F4;
	sub_821C9790(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D618;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266D630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,65(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D648;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266D660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,4548(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r28,r11,-14304
	r28.s64 = r11.s64 + -14304;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8266d6a8
	if (cr6.eq) goto loc_8266D6A8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8223de50
	ctx.lr = 0x8266D680;
	sub_8223DE50(ctx, base);
	// addi r31,r31,8204
	r31.s64 = r31.s64 + 8204;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// subf r10,r10,r31
	ctx.r10.s64 = r31.s64 - ctx.r10.s64;
loc_8266D690:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + r11.u32, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8266d690
	if (!cr6.eq) goto loc_8266D690;
	// b 0x8266d6d4
	goto loc_8266D6D4;
loc_8266D6A8:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D6B4;
	sub_82218310(ctx, base);
	// addi r31,r31,8204
	r31.s64 = r31.s64 + 8204;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_8266D6BC:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne cr6,0x8266d6bc
	if (!cr6.eq) goto loc_8266D6BC;
loc_8266D6D4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D6E0;
	sub_82218310(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,20268
	ctx.r4.s64 = r11.s64 + 20268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D6F4;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266D6FC;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266D710;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266D718;
	sub_824E7118(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,-11016
	ctx.r4.s64 = ctx.r8.s64 + -11016;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D72C;
	sub_827227B8(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,17268(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17268);
	// lwz r29,-10244(r29)
	r29.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x822a39c8
	ctx.lr = 0x8266D73C;
	sub_822A39C8(ctx, base);
	// bl 0x822a8d98
	ctx.lr = 0x8266D740;
	sub_822A8D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x8266D74C;
	sub_82218310(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-11024
	ctx.r4.s64 = ctx.r6.s64 + -11024;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D760;
	sub_827227B8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-11032
	ctx.r4.s64 = ctx.r4.s64 + -11032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D774;
	sub_827227B8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266D77C"))) PPC_WEAK_FUNC(sub_8266D77C);
PPC_FUNC_IMPL(__imp__sub_8266D77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D780"))) PPC_WEAK_FUNC(sub_8266D780);
PPC_FUNC_IMPL(__imp__sub_8266D780) {
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
	// bl 0x8266d560
	ctx.lr = 0x8266D798;
	sub_8266D560(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826535f8
	ctx.lr = 0x8266D7A0;
	sub_826535F8(ctx, base);
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

__attribute__((alias("__imp__sub_8266D7B4"))) PPC_WEAK_FUNC(sub_8266D7B4);
PPC_FUNC_IMPL(__imp__sub_8266D7B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266D7B8"))) PPC_WEAK_FUNC(sub_8266D7B8);
PPC_FUNC_IMPL(__imp__sub_8266D7B8) {
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
	ctx.lr = 0x8266D7C0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266D7E0;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r9,14672
	r31.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8266D7FC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D80C;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r27,56(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// addi r26,r8,2612
	r26.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x821c9790
	ctx.lr = 0x8266D828;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x8266D838;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8266D850;
	sub_821C9790(ctx, base);
	// li r25,1
	r25.s64 = 1;
	// li r24,0
	r24.s64 = 0;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r27,7
	r27.s64 = 7;
	// stw r25,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r25.u32);
	// stw r24,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r24.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D874;
	sub_825EF9F0(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r11,36(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266D88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,65(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 65);
	// li r10,3
	ctx.r10.s64 = 3;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8266D8A4;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266D8BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,4524(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 4524);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8266d8e0
	if (!cr6.eq) goto loc_8266D8E0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266D8DC;
	sub_825EE0E0(ctx, base);
	// stb r25,4524(r30)
	PPC_STORE_U8(r30.u32 + 4524, r25.u8);
loc_8266D8E0:
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-13284
	ctx.r4.s64 = r11.s64 + -13284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x8266D8F8;
	sub_82722678(ctx, base);
	// clrlwi r10,r28,24
	ctx.r10.u64 = r28.u32 & 0xFF;
	// mr r11,r24
	r11.u64 = r24.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8266da58
	if (cr6.eq) goto loc_8266DA58;
	// addi r29,r30,4428
	r29.s64 = r30.s64 + 4428;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8266D910:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266da50
	if (cr6.eq) goto loc_8266DA50;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266d910
	if (cr6.lt) goto loc_8266D910;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8266D930:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dc50
	if (cr6.eq) goto loc_8266DC50;
	// lbz r11,4501(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dc50
	if (cr6.eq) goto loc_8266DC50;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14304
	ctx.r4.s64 = ctx.r10.s64 + -14304;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8266D95C;
	sub_82218310(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,20268
	ctx.r4.s64 = ctx.r9.s64 + 20268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D974;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266D97C;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r3,-10240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266D990;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266D998;
	sub_824E7118(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r6,-11016
	ctx.r4.s64 = ctx.r6.s64 + -11016;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9AC;
	sub_827227B8(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r4,-11024
	ctx.r4.s64 = ctx.r4.s64 + -11024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9C0;
	sub_827227B8(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r3,-11032
	ctx.r4.s64 = ctx.r3.s64 + -11032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9D4;
	sub_827227B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,2440
	ctx.r4.s64 = r11.s64 + 2440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9E8;
	sub_827227B8(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r10,-3656
	ctx.r4.s64 = ctx.r10.s64 + -3656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266D9FC;
	sub_827227B8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r9,14332
	ctx.r4.s64 = ctx.r9.s64 + 14332;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266DA10;
	sub_827227B8(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266DA24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r29,64
	r11.s64 = r29.s64 + 64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266DA34:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266da34
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266DA34;
	// stb r24,73(r29)
	PPC_STORE_U8(r29.u32 + 73, r24.u8);
	// stb r24,72(r29)
	PPC_STORE_U8(r29.u32 + 72, r24.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_8266DA50:
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8266d930
	goto loc_8266D930;
loc_8266DA58:
	// addi r26,r30,4428
	r26.s64 = r30.s64 + 4428;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_8266DA60:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266dc58
	if (cr6.eq) goto loc_8266DC58;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266da60
	if (cr6.lt) goto loc_8266DA60;
	// mr r11,r25
	r11.u64 = r25.u64;
loc_8266DA80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dc50
	if (cr6.eq) goto loc_8266DC50;
	// lbz r11,4501(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 4501);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dc50
	if (cr6.eq) goto loc_8266DC50;
	// lwz r11,10248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r30,10248
	ctx.r3.s64 = r30.s64 + 10248;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266DAB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r28,r30,10856
	r28.s64 = r30.s64 + 10856;
	// lwz r29,40(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 40);
	// ld r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U64(r29.u32 + 16);
	// bl 0x823dba80
	ctx.lr = 0x8266DAC4;
	sub_823DBA80(ctx, base);
	// lwz r7,28(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r5,r6,-5880
	ctx.r5.s64 = ctx.r6.s64 + -5880;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// lfs f0,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f0.f64 = double(temp.f32);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// li r4,7
	ctx.r4.s64 = 7;
	// fdivs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 / ctx.f10.f64));
	// fmuls f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// bl 0x82137a08
	ctx.lr = 0x8266DB08;
	sub_82137A08(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// addi r11,r11,14620
	r11.s64 = r11.s64 + 14620;
loc_8266DB14:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8266db14
	if (!cr6.eq) goto loc_8266DB14;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_8266DB28:
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
	// bne cr6,0x8266db28
	if (!cr6.eq) goto loc_8266DB28;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20268
	ctx.r4.s64 = ctx.r10.s64 + 20268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DB5C;
	sub_82722678(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266DB64;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r3,-10240(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266DB78;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8266DB80;
	sub_824E7118(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r7,-11016
	ctx.r4.s64 = ctx.r7.s64 + -11016;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266DB94;
	sub_827227B8(ctx, base);
	// ld r11,16(r29)
	r11.u64 = PPC_LOAD_U64(r29.u32 + 16);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-11024
	ctx.r4.s64 = ctx.r6.s64 + -11024;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DBB0;
	sub_82722678(ctx, base);
	// lwz r8,28(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-11032
	ctx.r4.s64 = ctx.r9.s64 + -11032;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DBCC;
	sub_82722678(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r7,2440
	ctx.r4.s64 = ctx.r7.s64 + 2440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8266DBE0;
	sub_827227B8(ctx, base);
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,-3656
	ctx.r4.s64 = ctx.r6.s64 + -3656;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DBFC;
	sub_82722678(ctx, base);
	// lwz r9,44(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,14332
	ctx.r4.s64 = ctx.r10.s64 + 14332;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x82722678
	ctx.lr = 0x8266DC18;
	sub_82722678(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,184(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266DC2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r26,64
	r11.s64 = r26.s64 + 64;
	// mr r9,r24
	ctx.r9.u64 = r24.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266DC3C:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266dc3c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266DC3C;
	// stb r24,73(r26)
	PPC_STORE_U8(r26.u32 + 73, r24.u8);
	// stb r24,72(r26)
	PPC_STORE_U8(r26.u32 + 72, r24.u8);
loc_8266DC50:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
loc_8266DC58:
	// mr r11,r24
	r11.u64 = r24.u64;
	// b 0x8266da80
	goto loc_8266DA80;
}

__attribute__((alias("__imp__sub_8266DC60"))) PPC_WEAK_FUNC(sub_8266DC60);
PPC_FUNC_IMPL(__imp__sub_8266DC60) {
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
	ctx.lr = 0x8266DC68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,3
	ctx.r6.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266DC98;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r7,r8,15452
	ctx.r7.s64 = ctx.r8.s64 + 15452;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,15424
	ctx.r4.s64 = ctx.r6.s64 + 15424;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DCBC;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,15400
	ctx.r4.s64 = ctx.r4.s64 + 15400;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DCD4;
	sub_82633D40(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,15376
	ctx.r4.s64 = ctx.r3.s64 + 15376;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DCEC;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266DD44"))) PPC_WEAK_FUNC(sub_8266DD44);
PPC_FUNC_IMPL(__imp__sub_8266DD44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266DD48"))) PPC_WEAK_FUNC(sub_8266DD48);
PPC_FUNC_IMPL(__imp__sub_8266DD48) {
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
	// addi r31,r30,1408
	r31.s64 = r30.s64 + 1408;
	// lhz r11,1602(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1602);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dd78
	if (cr6.eq) goto loc_8266DD78;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DD78;
	sub_82130588(ctx, base);
loc_8266DD78:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DD80;
	sub_82633B00(ctx, base);
	// lhz r11,1394(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1394);
	// addi r31,r30,1200
	r31.s64 = r30.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dd98
	if (cr6.eq) goto loc_8266DD98;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DD98;
	sub_82130588(ctx, base);
loc_8266DD98:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DDA0;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 1186);
	// addi r31,r30,992
	r31.s64 = r30.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ddb8
	if (cr6.eq) goto loc_8266DDB8;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DDB8;
	sub_82130588(ctx, base);
loc_8266DDB8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DDC0;
	sub_82633B00(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266DDC8;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266DDE0"))) PPC_WEAK_FUNC(sub_8266DDE0);
PPC_FUNC_IMPL(__imp__sub_8266DDE0) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8266DDE8;
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
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,15376
	ctx.r5.s64 = ctx.r10.s64 + 15376;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,5
	ctx.r6.s64 = 5;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266DE18;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,16284
	ctx.r7.s64 = ctx.r8.s64 + 16284;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x8266DE2C;
	sub_82659E28(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,14592
	ctx.r4.s64 = ctx.r6.s64 + 14592;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DE44;
	sub_82633D40(ctx, base);
	// addi r29,r31,1232
	r29.s64 = r31.s64 + 1232;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,14564
	ctx.r4.s64 = ctx.r4.s64 + 14564;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DE5C;
	sub_82633D40(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r28,r31,1440
	r28.s64 = r31.s64 + 1440;
	// addi r4,r3,14512
	ctx.r4.s64 = ctx.r3.s64 + 14512;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DE74;
	sub_82633D40(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r27,r31,1648
	r27.s64 = r31.s64 + 1648;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14540
	ctx.r4.s64 = r11.s64 + 14540;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DE8C;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r26,r31,1856
	r26.s64 = r31.s64 + 1856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,14484
	ctx.r4.s64 = ctx.r10.s64 + 14484;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266DEA4;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
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
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r26,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r26.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266DF2C"))) PPC_WEAK_FUNC(sub_8266DF2C);
PPC_FUNC_IMPL(__imp__sub_8266DF2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266DF30"))) PPC_WEAK_FUNC(sub_8266DF30);
PPC_FUNC_IMPL(__imp__sub_8266DF30) {
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
	// addi r30,r31,1856
	r30.s64 = r31.s64 + 1856;
	// lhz r11,2050(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2050);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266df60
	if (cr6.eq) goto loc_8266DF60;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DF60;
	sub_82130588(ctx, base);
loc_8266DF60:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DF68;
	sub_82633B00(ctx, base);
	// lhz r11,1842(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1842);
	// addi r30,r31,1648
	r30.s64 = r31.s64 + 1648;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266df80
	if (cr6.eq) goto loc_8266DF80;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DF80;
	sub_82130588(ctx, base);
loc_8266DF80:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DF88;
	sub_82633B00(ctx, base);
	// lhz r11,1634(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1634);
	// addi r30,r31,1440
	r30.s64 = r31.s64 + 1440;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dfa0
	if (cr6.eq) goto loc_8266DFA0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DFA0;
	sub_82130588(ctx, base);
loc_8266DFA0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DFA8;
	sub_82633B00(ctx, base);
	// lhz r11,1426(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1426);
	// addi r30,r31,1232
	r30.s64 = r31.s64 + 1232;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dfc0
	if (cr6.eq) goto loc_8266DFC0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DFC0;
	sub_82130588(ctx, base);
loc_8266DFC0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DFC8;
	sub_82633B00(ctx, base);
	// lhz r11,1218(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1218);
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266dfe0
	if (cr6.eq) goto loc_8266DFE0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266DFE0;
	sub_82130588(ctx, base);
loc_8266DFE0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266DFE8;
	sub_82633B00(ctx, base);
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e000
	if (cr6.eq) goto loc_8266E000;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8266E000;
	sub_82130588(ctx, base);
loc_8266E000:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8266E008;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266E010;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266E028"))) PPC_WEAK_FUNC(sub_8266E028);
PPC_FUNC_IMPL(__imp__sub_8266E028) {
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
	ctx.lr = 0x8266E030;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r29,848
	r31.s64 = r29.s64 + 848;
	// lhz r11,852(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 852);
	// lwz r9,848(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266e070
	if (cr6.eq) goto loc_8266E070;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8266E05C:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266e05c
	if (!cr6.eq) goto loc_8266E05C;
loc_8266E070:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// addi r28,r11,17232
	r28.s64 = r11.s64 + 17232;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r6,r29,1856
	ctx.r6.s64 = r29.s64 + 1856;
	// clrlwi r9,r7,16
	ctx.r9.u64 = ctx.r7.u32 & 0xFFFF;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// addi r30,r29,992
	r30.s64 = r29.s64 + 992;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// addi r5,r4,-4680
	ctx.r5.s64 = ctx.r4.s64 + -4680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r6,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r6.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r6,992(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// lwz r11,24(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8266E0D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,992(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E0E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e10c
	if (!cr6.gt) goto loc_8266E10C;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1024
	ctx.r8.s64 = r29.s64 + 1024;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E10C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4744
	ctx.r5.s64 = ctx.r10.s64 + -4744;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E12C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e168
	if (!cr6.gt) goto loc_8266E168;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1440
	ctx.r8.s64 = r29.s64 + 1440;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E168:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E19C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e1c4
	if (!cr6.gt) goto loc_8266E1C4;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1232
	ctx.r8.s64 = r29.s64 + 1232;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E1C4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4764
	ctx.r5.s64 = ctx.r10.s64 + -4764;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E1E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E1F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e220
	if (!cr6.gt) goto loc_8266E220;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1648
	ctx.r8.s64 = r29.s64 + 1648;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E220:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266E228"))) PPC_WEAK_FUNC(sub_8266E228);
PPC_FUNC_IMPL(__imp__sub_8266E228) {
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
	ctx.lr = 0x8266E230;
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
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,15424
	ctx.r5.s64 = ctx.r10.s64 + 15424;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266E260;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// addi r7,r8,17092
	ctx.r7.s64 = ctx.r8.s64 + 17092;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x8266E274;
	sub_82659E28(ctx, base);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,16392
	ctx.r4.s64 = ctx.r6.s64 + 16392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E28C;
	sub_82633D40(ctx, base);
	// addi r29,r31,1232
	r29.s64 = r31.s64 + 1232;
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,16364
	ctx.r4.s64 = ctx.r4.s64 + 16364;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E2A4;
	sub_82633D40(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r28,r31,1440
	r28.s64 = r31.s64 + 1440;
	// addi r4,r3,16336
	ctx.r4.s64 = ctx.r3.s64 + 16336;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E2BC;
	sub_82633D40(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r27,r31,1648
	r27.s64 = r31.s64 + 1648;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,16312
	ctx.r4.s64 = r11.s64 + 16312;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E2D4;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
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
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8266E344"))) PPC_WEAK_FUNC(sub_8266E344);
PPC_FUNC_IMPL(__imp__sub_8266E344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266E348"))) PPC_WEAK_FUNC(sub_8266E348);
PPC_FUNC_IMPL(__imp__sub_8266E348) {
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
	// addi r30,r31,1648
	r30.s64 = r31.s64 + 1648;
	// lhz r11,1842(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1842);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e378
	if (cr6.eq) goto loc_8266E378;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E378;
	sub_82130588(ctx, base);
loc_8266E378:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E380;
	sub_82633B00(ctx, base);
	// lhz r11,1634(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1634);
	// addi r30,r31,1440
	r30.s64 = r31.s64 + 1440;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e398
	if (cr6.eq) goto loc_8266E398;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E398;
	sub_82130588(ctx, base);
loc_8266E398:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E3A0;
	sub_82633B00(ctx, base);
	// lhz r11,1426(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1426);
	// addi r30,r31,1232
	r30.s64 = r31.s64 + 1232;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e3b8
	if (cr6.eq) goto loc_8266E3B8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E3B8;
	sub_82130588(ctx, base);
loc_8266E3B8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E3C0;
	sub_82633B00(ctx, base);
	// lhz r11,1218(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1218);
	// addi r30,r31,1024
	r30.s64 = r31.s64 + 1024;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e3d8
	if (cr6.eq) goto loc_8266E3D8;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E3D8;
	sub_82130588(ctx, base);
loc_8266E3D8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E3E0;
	sub_82633B00(ctx, base);
	// lhz r11,1002(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1002);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e3f8
	if (cr6.eq) goto loc_8266E3F8;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x8266E3F8;
	sub_82130588(ctx, base);
loc_8266E3F8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8266E400;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266E408;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266E420"))) PPC_WEAK_FUNC(sub_8266E420);
PPC_FUNC_IMPL(__imp__sub_8266E420) {
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
	ctx.lr = 0x8266E428;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r31,r29,848
	r31.s64 = r29.s64 + 848;
	// lhz r11,852(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 852);
	// lwz r9,848(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266e468
	if (cr6.eq) goto loc_8266E468;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8266E454:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266e454
	if (!cr6.eq) goto loc_8266E454;
loc_8266E468:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// srawi r8,r10,2
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// addi r28,r11,17232
	r28.s64 = r11.s64 + 17232;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// addi r30,r29,992
	r30.s64 = r29.s64 + 992;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lwz r11,992(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-4680
	ctx.r5.s64 = ctx.r6.s64 + -4680;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266E4A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,992(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 992);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266E4BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e4e4
	if (!cr6.gt) goto loc_8266E4E4;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1024
	ctx.r8.s64 = r29.s64 + 1024;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E4E4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4744
	ctx.r5.s64 = ctx.r10.s64 + -4744;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E504;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E518;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e540
	if (!cr6.gt) goto loc_8266E540;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1440
	ctx.r8.s64 = r29.s64 + 1440;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E540:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E574;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e59c
	if (!cr6.gt) goto loc_8266E59C;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1232
	ctx.r8.s64 = r29.s64 + 1232;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E59C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r10,-4764
	ctx.r5.s64 = ctx.r10.s64 + -4764;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E5BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266E5D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e5f8
	if (!cr6.gt) goto loc_8266E5F8;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r29,1648
	ctx.r8.s64 = r29.s64 + 1648;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// stwx r8,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r8.u32);
loc_8266E5F8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266E600"))) PPC_WEAK_FUNC(sub_8266E600);
PPC_FUNC_IMPL(__imp__sub_8266E600) {
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
	ctx.lr = 0x8266E608;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r28,r31,5052
	r28.s64 = r31.s64 + 5052;
	// lhz r11,5056(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5056);
	// lwz r9,5052(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 5052);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266e648
	if (cr6.eq) goto loc_8266E648;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8266E634:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266e634
	if (!cr6.eq) goto loc_8266E634;
loc_8266E648:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r30,r31,5024
	r30.s64 = r31.s64 + 5024;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// lwz r11,5048(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 5048);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// stw r30,864(r31)
	PPC_STORE_U32(r31.u32 + 864, r30.u32);
	// bgt cr6,0x8266e7b4
	if (cr6.gt) goto loc_8266E7B4;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r29,r10,17232
	r29.s64 = ctx.r10.s64 + 17232;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,-6512
	r12.s64 = r12.s64 + -6512;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8266E6A0;
	case 1:
		goto loc_8266E6E0;
	case 2:
		goto loc_8266E720;
	case 3:
		goto loc_8266E778;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-6496(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -6496);
	// lwz r19,-6432(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -6432);
	// lwz r19,-6368(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -6368);
	// lwz r19,-6280(r6)
	r19.u64 = PPC_LOAD_U32(ctx.r6.u32 + -6280);
loc_8266E6A0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r5,r10,-4680
	ctx.r5.s64 = ctx.r10.s64 + -4680;
	// addi r4,r9,17232
	ctx.r4.s64 = ctx.r9.s64 + 17232;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266E6C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,16392
	ctx.r4.s64 = ctx.r7.s64 + 16392;
	// lwz r5,788(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 788);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// b 0x8266e7b0
	goto loc_8266E7B0;
loc_8266E6E0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r5,r10,-4744
	ctx.r5.s64 = ctx.r10.s64 + -4744;
	// addi r4,r9,17232
	ctx.r4.s64 = ctx.r9.s64 + 17232;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8266E704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,16336
	ctx.r4.s64 = ctx.r7.s64 + 16336;
	// lwz r5,788(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 788);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// b 0x8266e7b0
	goto loc_8266E7B0;
loc_8266E720:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-4692
	ctx.r5.s64 = ctx.r10.s64 + -4692;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,16364
	ctx.r4.s64 = ctx.r8.s64 + 16364;
	// lwz r6,788(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8266E75C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8266E770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x8266e7b4
	if (cr6.gt) goto loc_8266E7B4;
loc_8266E778:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r10,-4764
	ctx.r5.s64 = ctx.r10.s64 + -4764;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E798;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r8,16312
	ctx.r4.s64 = ctx.r8.s64 + 16312;
	// lwz r6,788(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_8266E7B0:
	// bctrl 
	ctx.lr = 0x8266E7B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8266E7B4:
	// addi r29,r31,672
	r29.s64 = r31.s64 + 672;
	// li r30,0
	r30.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82631f88
	ctx.lr = 0x8266E7C4;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8266e83c
	if (!cr6.gt) goto loc_8266E83C;
	// lis r27,-32120
	r27.s64 = -2105016320;
loc_8266E7D0:
	// lwz r3,-27856(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8266E7D8;
	sub_8238EC00(ctx, base);
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266E7FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82389800
	ctx.lr = 0x8266E808;
	sub_82389800(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lhz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 16);
	// extsh r26,r7
	r26.s64 = ctx.r7.s16;
	// bl 0x8262e420
	ctx.lr = 0x8266E820;
	sub_8262E420(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r26,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r26.u32);
	// bl 0x82631f88
	ctx.lr = 0x8266E834;
	sub_82631F88(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8266e7d0
	if (cr6.lt) goto loc_8266E7D0;
loc_8266E83C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266E844"))) PPC_WEAK_FUNC(sub_8266E844);
PPC_FUNC_IMPL(__imp__sub_8266E844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266E848"))) PPC_WEAK_FUNC(sub_8266E848);
PPC_FUNC_IMPL(__imp__sub_8266E848) {
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
	ctx.lr = 0x8266E850;
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
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,18704
	ctx.r5.s64 = ctx.r10.s64 + 18704;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266E880;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r7,r8,17900
	ctx.r7.s64 = ctx.r8.s64 + 17900;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,6192
	ctx.r4.s64 = ctx.r6.s64 + 6192;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E8A4;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,6212
	ctx.r4.s64 = ctx.r4.s64 + 6212;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E8BC;
	sub_82633D40(ctx, base);
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,6232
	ctx.r4.s64 = ctx.r3.s64 + 6232;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E8D4;
	sub_82633D40(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r27,r31,1616
	r27.s64 = r31.s64 + 1616;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,6252
	ctx.r4.s64 = r11.s64 + 6252;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266E8EC;
	sub_82633D40(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,848
	ctx.r10.s64 = r31.s64 + 848;
	// stw r11,1832(r31)
	PPC_STORE_U32(r31.u32 + 1832, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,1836(r31)
	PPC_STORE_U16(r31.u32 + 1836, r11.u16);
	// sth r11,1838(r31)
	PPC_STORE_U16(r31.u32 + 1838, r11.u16);
	// stb r11,1840(r31)
	PPC_STORE_U8(r31.u32 + 1840, r11.u8);
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
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r28,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r28.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r9,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r9.u16);
	// stwx r27,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8266E970"))) PPC_WEAK_FUNC(sub_8266E970);
PPC_FUNC_IMPL(__imp__sub_8266E970) {
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
	// lhz r11,1838(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1838);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e99c
	if (cr6.eq) goto loc_8266E99C;
	// lwz r3,1832(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1832);
	// bl 0x82130588
	ctx.lr = 0x8266E99C;
	sub_82130588(ctx, base);
loc_8266E99C:
	// lhz r11,1810(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1810);
	// addi r30,r31,1616
	r30.s64 = r31.s64 + 1616;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e9b4
	if (cr6.eq) goto loc_8266E9B4;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E9B4;
	sub_82130588(ctx, base);
loc_8266E9B4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E9BC;
	sub_82633B00(ctx, base);
	// lhz r11,1602(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1602);
	// addi r30,r31,1408
	r30.s64 = r31.s64 + 1408;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e9d4
	if (cr6.eq) goto loc_8266E9D4;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E9D4;
	sub_82130588(ctx, base);
loc_8266E9D4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E9DC;
	sub_82633B00(ctx, base);
	// lhz r11,1394(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1394);
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266e9f4
	if (cr6.eq) goto loc_8266E9F4;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266E9F4;
	sub_82130588(ctx, base);
loc_8266E9F4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266E9FC;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1186);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ea14
	if (cr6.eq) goto loc_8266EA14;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EA14;
	sub_82130588(ctx, base);
loc_8266EA14:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EA1C;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266EA24;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266EA3C"))) PPC_WEAK_FUNC(sub_8266EA3C);
PPC_FUNC_IMPL(__imp__sub_8266EA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266EA40"))) PPC_WEAK_FUNC(sub_8266EA40);
PPC_FUNC_IMPL(__imp__sub_8266EA40) {
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
	ctx.lr = 0x8266EA48;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r29,r11,-18768
	r29.s64 = r11.s64 + -18768;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8266EA70;
	sub_821F9FB8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,56
	cr6.compare<int32_t>(r28.s32, 56, xer);
	// beq cr6,0x8266ec10
	if (cr6.eq) goto loc_8266EC10;
	// cmpwi cr6,r28,63
	cr6.compare<int32_t>(r28.s32, 63, xer);
	// beq cr6,0x8266ea9c
	if (cr6.eq) goto loc_8266EA9C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826537d0
	ctx.lr = 0x8266EA94;
	sub_826537D0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266EA9C:
	// lbz r11,1840(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1840);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266eabc
	if (cr6.eq) goto loc_8266EABC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8266c440
	ctx.lr = 0x8266EAB0;
	sub_8266C440(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266EABC:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x8266EAD4;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8266EAE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8266ec04
	if (cr6.eq) goto loc_8266EC04;
	// addi r3,r30,672
	ctx.r3.s64 = r30.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x8266EAFC;
	sub_82203240(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8266ec04
	if (cr6.lt) goto loc_8266EC04;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,56(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 56);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,1072
	ctx.r4.s64 = r11.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8266EB18;
	sub_825EE0E0(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82657678
	ctx.lr = 0x8266EB20;
	sub_82657678(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// li r9,352
	ctx.r9.s64 = 352;
	// lwz r10,-10236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r26,r3,-22108
	r26.s64 = ctx.r3.s64 + -22108;
	// lfs f0,6076(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 6076);
	f0.f64 = double(temp.f32);
	// addi r4,r6,6060
	ctx.r4.s64 = ctx.r6.s64 + 6060;
	// addi r27,r5,-19728
	r27.s64 = ctx.r5.s64 + -19728;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8266EB6C;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8266EB80;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82625f50
	ctx.lr = 0x8266EBA4;
	sub_82625F50(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stb r11,1840(r30)
	PPC_STORE_U8(r30.u32 + 1840, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1120(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1120, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,372(r10)
	PPC_STORE_U8(ctx.r10.u32 + 372, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1427(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1427, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,1401(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1401, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,375(r10)
	PPC_STORE_U8(ctx.r10.u32 + 375, r11.u8);
	// lwz r10,-10220(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r11,374(r10)
	PPC_STORE_U8(ctx.r10.u32 + 374, r11.u8);
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266EBE8;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8266ebf4
	if (cr6.eq) goto loc_8266EBF4;
	// bl 0x82720560
	ctx.lr = 0x8266EBF4;
	sub_82720560(ctx, base);
loc_8266EBF4:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,34
	ctx.r4.s64 = 34;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220f040
	ctx.lr = 0x8266EC04;
	sub_8220F040(ctx, base);
loc_8266EC04:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266EC10:
	// lbz r11,1840(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 1840);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ec30
	if (cr6.eq) goto loc_8266EC30;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8266c440
	ctx.lr = 0x8266EC24;
	sub_8266C440(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8266EC30:
	// li r4,56
	ctx.r4.s64 = 56;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826537d0
	ctx.lr = 0x8266EC40;
	sub_826537D0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266EC48"))) PPC_WEAK_FUNC(sub_8266EC48);
PPC_FUNC_IMPL(__imp__sub_8266EC48) {
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
	ctx.lr = 0x8266EC50;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// addi r30,r31,1832
	r30.s64 = r31.s64 + 1832;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// stw r5,1824(r31)
	PPC_STORE_U32(r31.u32 + 1824, ctx.r5.u32);
	// stw r6,1828(r31)
	PPC_STORE_U32(r31.u32 + 1828, ctx.r6.u32);
	// beq cr6,0x8266eca4
	if (cr6.eq) goto loc_8266ECA4;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8266ec98
	if (cr6.eq) goto loc_8266EC98;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ec98
	if (cr6.eq) goto loc_8266EC98;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8266EC98;
	sub_82130588(ctx, base);
loc_8266EC98:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c7480
	ctx.lr = 0x8266ECA4;
	sub_826C7480(ctx, base);
loc_8266ECA4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-10256
	ctx.r4.s64 = ctx.r10.s64 + -10256;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8266ECB8;
	sub_821F9FB8(ctx, base);
	// lwz r9,256(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// lwz r7,196(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 196);
	// lwz r4,56(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8266ECD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8266ECE0;
	sub_82630318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266ECE8"))) PPC_WEAK_FUNC(sub_8266ECE8);
PPC_FUNC_IMPL(__imp__sub_8266ECE8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8266ECF0;
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
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29148
	ctx.r8.s64 = r11.s64 + 29148;
	// addi r5,r10,15400
	ctx.r5.s64 = ctx.r10.s64 + 15400;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,6
	ctx.r6.s64 = 6;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266ED20;
	sub_82654318(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r7,r8,18740
	ctx.r7.s64 = ctx.r8.s64 + 18740;
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,84
	ctx.r4.s64 = ctx.r6.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266ED44;
	sub_82633D40(ctx, base);
	// addi r29,r31,1200
	r29.s64 = r31.s64 + 1200;
	// lis r4,-32246
	ctx.r4.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,14368
	ctx.r4.s64 = ctx.r4.s64 + 14368;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266ED5C;
	sub_82633D40(ctx, base);
	// lis r3,-32246
	ctx.r3.s64 = -2113273856;
	// addi r28,r31,1408
	r28.s64 = r31.s64 + 1408;
	// addi r4,r3,14400
	ctx.r4.s64 = ctx.r3.s64 + 14400;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266ED74;
	sub_82633D40(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r27,r31,1616
	r27.s64 = r31.s64 + 1616;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,14456
	ctx.r4.s64 = r11.s64 + 14456;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266ED8C;
	sub_82633D40(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r26,r31,1824
	r26.s64 = r31.s64 + 1824;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,14428
	ctx.r4.s64 = ctx.r10.s64 + 14428;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266EDA4;
	sub_82633D40(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r25,r31,2032
	r25.s64 = r31.s64 + 2032;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,14340
	ctx.r4.s64 = ctx.r9.s64 + 14340;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266EDBC;
	sub_82633D40(ctx, base);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
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
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
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
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r25,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r25.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266EE5C"))) PPC_WEAK_FUNC(sub_8266EE5C);
PPC_FUNC_IMPL(__imp__sub_8266EE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266EE60"))) PPC_WEAK_FUNC(sub_8266EE60);
PPC_FUNC_IMPL(__imp__sub_8266EE60) {
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
	// addi r30,r31,2032
	r30.s64 = r31.s64 + 2032;
	// lhz r11,2226(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2226);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ee90
	if (cr6.eq) goto loc_8266EE90;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EE90;
	sub_82130588(ctx, base);
loc_8266EE90:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EE98;
	sub_82633B00(ctx, base);
	// lhz r11,2018(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2018);
	// addi r30,r31,1824
	r30.s64 = r31.s64 + 1824;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266eeb0
	if (cr6.eq) goto loc_8266EEB0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EEB0;
	sub_82130588(ctx, base);
loc_8266EEB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EEB8;
	sub_82633B00(ctx, base);
	// lhz r11,1810(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1810);
	// addi r30,r31,1616
	r30.s64 = r31.s64 + 1616;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266eed0
	if (cr6.eq) goto loc_8266EED0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EED0;
	sub_82130588(ctx, base);
loc_8266EED0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EED8;
	sub_82633B00(ctx, base);
	// lhz r11,1602(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1602);
	// addi r30,r31,1408
	r30.s64 = r31.s64 + 1408;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266eef0
	if (cr6.eq) goto loc_8266EEF0;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EEF0;
	sub_82130588(ctx, base);
loc_8266EEF0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EEF8;
	sub_82633B00(ctx, base);
	// lhz r11,1394(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1394);
	// addi r30,r31,1200
	r30.s64 = r31.s64 + 1200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ef10
	if (cr6.eq) goto loc_8266EF10;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EF10;
	sub_82130588(ctx, base);
loc_8266EF10:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EF18;
	sub_82633B00(ctx, base);
	// lhz r11,1186(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 1186);
	// addi r30,r31,992
	r30.s64 = r31.s64 + 992;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ef30
	if (cr6.eq) goto loc_8266EF30;
	// lwz r3,188(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266EF30;
	sub_82130588(ctx, base);
loc_8266EF30:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266EF38;
	sub_82633B00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266EF40;
	sub_8221FCC8(ctx, base);
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

__attribute__((alias("__imp__sub_8266EF58"))) PPC_WEAK_FUNC(sub_8266EF58);
PPC_FUNC_IMPL(__imp__sub_8266EF58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8266EF60;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82654318
	ctx.lr = 0x8266EF6C;
	sub_82654318(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r29,r30,992
	r29.s64 = r30.s64 + 992;
	// addi r10,r11,19548
	ctx.r10.s64 = r11.s64 + 19548;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r28,9
	r28.s64 = 9;
	// li r31,0
	r31.s64 = 0;
	// addi r27,r11,14724
	r27.s64 = r11.s64 + 14724;
	// addi r26,r10,3998
	r26.s64 = ctx.r10.s64 + 3998;
loc_8266EF94:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82633d40
	ctx.lr = 0x8266EFA4;
	sub_82633D40(ctx, base);
	// stw r27,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r27.u32);
	// stw r31,220(r29)
	PPC_STORE_U32(r29.u32 + 220, r31.u32);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r31,216(r29)
	PPC_STORE_U32(r29.u32 + 216, r31.u32);
	// stw r31,316(r29)
	PPC_STORE_U32(r29.u32 + 316, r31.u32);
	// stw r31,312(r29)
	PPC_STORE_U32(r29.u32 + 312, r31.u32);
	// stw r31,208(r29)
	PPC_STORE_U32(r29.u32 + 208, r31.u32);
	// stw r31,308(r29)
	PPC_STORE_U32(r29.u32 + 308, r31.u32);
	// stw r31,212(r29)
	PPC_STORE_U32(r29.u32 + 212, r31.u32);
	// stw r31,320(r29)
	PPC_STORE_U32(r29.u32 + 320, r31.u32);
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// bge 0x8266ef94
	if (!cr0.lt) goto loc_8266EF94;
	// addi r11,r30,4352
	r11.s64 = r30.s64 + 4352;
	// stw r31,4352(r30)
	PPC_STORE_U32(r30.u32 + 4352, r31.u32);
	// stw r31,4356(r30)
	PPC_STORE_U32(r30.u32 + 4356, r31.u32);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r10,r11,64
	ctx.r10.s64 = r11.s64 + 64;
	// stw r31,4360(r30)
	PPC_STORE_U32(r30.u32 + 4360, r31.u32);
	// stw r31,4364(r30)
	PPC_STORE_U32(r30.u32 + 4364, r31.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r31,4368(r30)
	PPC_STORE_U32(r30.u32 + 4368, r31.u32);
	// stw r31,4372(r30)
	PPC_STORE_U32(r30.u32 + 4372, r31.u32);
	// stw r31,4376(r30)
	PPC_STORE_U32(r30.u32 + 4376, r31.u32);
	// stw r31,4380(r30)
	PPC_STORE_U32(r30.u32 + 4380, r31.u32);
	// stw r31,4384(r30)
	PPC_STORE_U32(r30.u32 + 4384, r31.u32);
	// stw r31,4388(r30)
	PPC_STORE_U32(r30.u32 + 4388, r31.u32);
	// stw r31,4392(r30)
	PPC_STORE_U32(r30.u32 + 4392, r31.u32);
	// stw r31,4396(r30)
	PPC_STORE_U32(r30.u32 + 4396, r31.u32);
	// stw r31,4400(r30)
	PPC_STORE_U32(r30.u32 + 4400, r31.u32);
	// stw r31,4404(r30)
	PPC_STORE_U32(r30.u32 + 4404, r31.u32);
	// stw r31,4408(r30)
	PPC_STORE_U32(r30.u32 + 4408, r31.u32);
	// stw r31,4412(r30)
	PPC_STORE_U32(r30.u32 + 4412, r31.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266F028:
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8266f028
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266F028;
	// addi r10,r30,4428
	ctx.r10.s64 = r30.s64 + 4428;
	// stb r31,72(r11)
	PPC_STORE_U8(r11.u32 + 72, r31.u8);
	// stb r31,73(r11)
	PPC_STORE_U8(r11.u32 + 73, r31.u8);
	// mr r8,r31
	ctx.r8.u64 = r31.u64;
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// stw r31,4428(r30)
	PPC_STORE_U32(r30.u32 + 4428, r31.u32);
	// stw r31,4432(r30)
	PPC_STORE_U32(r30.u32 + 4432, r31.u32);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r31,4436(r30)
	PPC_STORE_U32(r30.u32 + 4436, r31.u32);
	// stw r31,4440(r30)
	PPC_STORE_U32(r30.u32 + 4440, r31.u32);
	// stw r31,4444(r30)
	PPC_STORE_U32(r30.u32 + 4444, r31.u32);
	// stw r31,4448(r30)
	PPC_STORE_U32(r30.u32 + 4448, r31.u32);
	// stw r31,4452(r30)
	PPC_STORE_U32(r30.u32 + 4452, r31.u32);
	// stw r31,4456(r30)
	PPC_STORE_U32(r30.u32 + 4456, r31.u32);
	// stw r31,4460(r30)
	PPC_STORE_U32(r30.u32 + 4460, r31.u32);
	// stw r31,4464(r30)
	PPC_STORE_U32(r30.u32 + 4464, r31.u32);
	// stw r31,4468(r30)
	PPC_STORE_U32(r30.u32 + 4468, r31.u32);
	// stw r31,4472(r30)
	PPC_STORE_U32(r30.u32 + 4472, r31.u32);
	// stw r31,4476(r30)
	PPC_STORE_U32(r30.u32 + 4476, r31.u32);
	// stw r31,4480(r30)
	PPC_STORE_U32(r30.u32 + 4480, r31.u32);
	// stw r31,4484(r30)
	PPC_STORE_U32(r30.u32 + 4484, r31.u32);
	// stw r31,4488(r30)
	PPC_STORE_U32(r30.u32 + 4488, r31.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8266F090:
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266f090
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266F090;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r31,72(r10)
	PPC_STORE_U8(ctx.r10.u32 + 72, r31.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r31,73(r10)
	PPC_STORE_U8(ctx.r10.u32 + 73, r31.u8);
	// stw r31,4504(r30)
	PPC_STORE_U32(r30.u32 + 4504, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,4508(r30)
	PPC_STORE_U32(r30.u32 + 4508, r31.u32);
	// stw r31,4512(r30)
	PPC_STORE_U32(r30.u32 + 4512, r31.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r31,4516(r30)
	PPC_STORE_U8(r30.u32 + 4516, r31.u8);
	// stfs f0,4520(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 4520, temp.u32);
	// stb r9,4517(r30)
	PPC_STORE_U8(r30.u32 + 4517, ctx.r9.u8);
	// stb r31,4524(r30)
	PPC_STORE_U8(r30.u32 + 4524, r31.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266F0D8"))) PPC_WEAK_FUNC(sub_8266F0D8);
PPC_FUNC_IMPL(__imp__sub_8266F0D8) {
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
	ctx.lr = 0x8266F0E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,9
	r30.s64 = 9;
	// addi r31,r29,4352
	r31.s64 = r29.s64 + 4352;
loc_8266F0F0:
	// addi r31,r31,-336
	r31.s64 = r31.s64 + -336;
	// lhz r11,194(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f108
	if (cr6.eq) goto loc_8266F108;
	// lwz r3,188(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x8266F108;
	sub_82130588(ctx, base);
loc_8266F108:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82633b00
	ctx.lr = 0x8266F110;
	sub_82633B00(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x8266f0f0
	if (!cr0.lt) goto loc_8266F0F0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8266F120;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8266F128"))) PPC_WEAK_FUNC(sub_8266F128);
PPC_FUNC_IMPL(__imp__sub_8266F128) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8266F130;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29060
	ctx.r8.s64 = r11.s64 + 29060;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,6
	ctx.r9.s64 = 6;
	// li r7,6
	ctx.r7.s64 = 6;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ef58
	ctx.lr = 0x8266F160;
	sub_8266EF58(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r20,r10,14704
	r20.s64 = ctx.r10.s64 + 14704;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r7,r8,20356
	ctx.r7.s64 = ctx.r8.s64 + 20356;
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// li r29,0
	r29.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r21,r11,212
	r21.s64 = r11.s64 + 212;
	// addi r11,r31,4544
	r11.s64 = r31.s64 + 4544;
	// stw r29,4548(r31)
	PPC_STORE_U32(r31.u32 + 4548, r29.u32);
	// addi r30,r10,560
	r30.s64 = ctx.r10.s64 + 560;
	// stw r29,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r29.u32);
	// lis r11,8192
	r11.s64 = 536870912;
	// stw r29,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r29.u32);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// stw r21,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r21.u32);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stw r20,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, r20.u32);
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// lis r7,4096
	ctx.r7.s64 = 268435456;
	// li r23,9
	r23.s64 = 9;
	// li r22,5
	r22.s64 = 5;
	// ori r24,r11,44
	r24.u64 = r11.u64 | 44;
	// ori r25,r10,36
	r25.u64 = ctx.r10.u64 | 36;
	// ori r26,r9,42
	r26.u64 = ctx.r9.u64 | 42;
	// ori r27,r8,41
	r27.u64 = ctx.r8.u64 | 41;
	// ori r28,r7,43
	r28.u64 = ctx.r7.u64 | 43;
loc_8266F1D0:
	// addi r3,r30,-536
	ctx.r3.s64 = r30.s64 + -536;
	// bl 0x824f9438
	ctx.lr = 0x8266F1D8;
	sub_824F9438(ctx, base);
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r11,r30,-512
	r11.s64 = r30.s64 + -512;
	// stw r22,-512(r30)
	PPC_STORE_U32(r30.u32 + -512, r22.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// std r29,-508(r30)
	PPC_STORE_U64(r30.u32 + -508, r29.u64);
	// stw r24,-500(r30)
	PPC_STORE_U32(r30.u32 + -500, r24.u32);
	// addic. r23,r23,-1
	xer.ca = r23.u32 > 0;
	r23.s64 = r23.s64 + -1;
	cr0.compare<int32_t>(r23.s32, 0, xer);
	// stw r25,-488(r30)
	PPC_STORE_U32(r30.u32 + -488, r25.u32);
	// stw r26,-480(r30)
	PPC_STORE_U32(r30.u32 + -480, r26.u32);
	// stw r27,-472(r30)
	PPC_STORE_U32(r30.u32 + -472, r27.u32);
	// stw r28,-464(r30)
	PPC_STORE_U32(r30.u32 + -464, r28.u32);
	// stb r9,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r9.u8);
	// stw r11,-520(r30)
	PPC_STORE_U32(r30.u32 + -520, r11.u32);
	// addi r30,r30,568
	r30.s64 = r30.s64 + 568;
	// bge 0x8266f1d0
	if (!cr0.lt) goto loc_8266F1D0;
	// stw r29,10252(r31)
	PPC_STORE_U32(r31.u32 + 10252, r29.u32);
	// addi r30,r31,10272
	r30.s64 = r31.s64 + 10272;
	// stw r29,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r29.u32);
	// addi r11,r31,10248
	r11.s64 = r31.s64 + 10248;
	// stw r29,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, r29.u32);
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// stw r21,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, r21.u32);
	// stw r20,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, r20.u32);
	// bl 0x824f9438
	ctx.lr = 0x8266F238;
	sub_824F9438(ctx, base);
	// lbz r6,10832(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 10832);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r22,10320(r31)
	PPC_STORE_U32(r31.u32 + 10320, r22.u32);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// std r29,10324(r31)
	PPC_STORE_U64(r31.u32 + 10324, r29.u64);
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// stw r24,10332(r31)
	PPC_STORE_U32(r31.u32 + 10332, r24.u32);
	// addi r9,r10,292
	ctx.r9.s64 = ctx.r10.s64 + 292;
	// stw r25,10344(r31)
	PPC_STORE_U32(r31.u32 + 10344, r25.u32);
	// stw r26,10352(r31)
	PPC_STORE_U32(r31.u32 + 10352, r26.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r27,10360(r31)
	PPC_STORE_U32(r31.u32 + 10360, r27.u32);
	// addi r10,r31,880
	ctx.r10.s64 = r31.s64 + 880;
	// stw r28,10368(r31)
	PPC_STORE_U32(r31.u32 + 10368, r28.u32);
	// addi r7,r8,29500
	ctx.r7.s64 = ctx.r8.s64 + 29500;
	// stb r5,10832(r31)
	PPC_STORE_U8(r31.u32 + 10832, ctx.r5.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,10312(r31)
	PPC_STORE_U32(r31.u32 + 10312, r11.u32);
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// lhz r4,884(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// sth r11,884(r31)
	PPC_STORE_U16(r31.u32 + 884, r11.u16);
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r11,29500(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 29500);
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r9,884(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,12(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,16(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,20(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8266F348"))) PPC_WEAK_FUNC(sub_8266F348);
PPC_FUNC_IMPL(__imp__sub_8266F348) {
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
	ctx.lr = 0x8266F350;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x8266F370;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266f64c
	if (cr6.eq) goto loc_8266F64C;
	// lfs f0,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,4520(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// bl 0x82388580
	ctx.lr = 0x8266F390;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266F3A0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8266F3A8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f3e0
	if (cr6.eq) goto loc_8266F3E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266F3BC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266F3CC;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x8266F3D4;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266f414
	if (!cr6.eq) goto loc_8266F414;
loc_8266F3E0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,21160
	ctx.r4.s64 = ctx.r10.s64 + 21160;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x8266F3FC;
	sub_82289AB0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82643bb8
	ctx.lr = 0x8266F414;
	sub_82643BB8(ctx, base);
loc_8266F414:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r28,r31,4352
	r28.s64 = r31.s64 + 4352;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x8266f528
	if (cr6.eq) goto loc_8266F528;
loc_8266F430:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266f520
	if (cr6.eq) goto loc_8266F520;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266f430
	if (cr6.lt) goto loc_8266F430;
	// li r11,1
	r11.s64 = 1;
loc_8266F450:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f630
	if (cr6.eq) goto loc_8266F630;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f630
	if (cr6.eq) goto loc_8266F630;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8266f500
	if (!cr6.gt) goto loc_8266F500;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_8266F47C:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x8266f500
	if (!cr6.lt) goto loc_8266F500;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266F4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x8266f4e0
	if (cr6.lt) goto loc_8266F4E0;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_8266F4E0:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266afe8
	ctx.lr = 0x8266F4EC;
	sub_8266AFE8(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8266f47c
	if (cr6.lt) goto loc_8266F47C;
loc_8266F500:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266F510:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266f510
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266F510;
	// b 0x8266f614
	goto loc_8266F614;
loc_8266F520:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8266f450
	goto loc_8266F450;
loc_8266F528:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266f658
	if (cr6.eq) goto loc_8266F658;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266f528
	if (cr6.lt) goto loc_8266F528;
	// li r11,1
	r11.s64 = 1;
loc_8266F548:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f630
	if (cr6.eq) goto loc_8266F630;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266f630
	if (cr6.eq) goto loc_8266F630;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8266f5f8
	if (!cr6.gt) goto loc_8266F5F8;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_8266F574:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x8266f5f8
	if (!cr6.lt) goto loc_8266F5F8;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266F598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x8266f5d8
	if (cr6.lt) goto loc_8266F5D8;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_8266F5D8:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266afe8
	ctx.lr = 0x8266F5E4;
	sub_8266AFE8(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8266f574
	if (cr6.lt) goto loc_8266F574;
loc_8266F5F8:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266F608:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266f608
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266F608;
loc_8266F614:
	// stb r27,73(r28)
	PPC_STORE_U8(r28.u32 + 73, r27.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r27,72(r28)
	PPC_STORE_U8(r28.u32 + 72, r27.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266F630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8266F630:
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8266f648
	if (cr6.eq) goto loc_8266F648;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8266F648:
	// bl 0x8266caf8
	ctx.lr = 0x8266F64C;
	sub_8266CAF8(ctx, base);
loc_8266F64C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8266F658:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8266f548
	goto loc_8266F548;
}

__attribute__((alias("__imp__sub_8266F660"))) PPC_WEAK_FUNC(sub_8266F660);
PPC_FUNC_IMPL(__imp__sub_8266F660) {
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
	ctx.lr = 0x8266F668;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// li r31,9
	r31.s64 = 9;
loc_8266F678:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9438
	ctx.lr = 0x8266F680;
	sub_824F9438(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bge 0x8266f678
	if (!cr0.lt) goto loc_8266F678;
	// li r26,0
	r26.s64 = 0;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// mr r31,r26
	r31.u64 = r26.u64;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_8266F69C:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x8266F6A8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266F6B8;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// add r9,r30,r31
	ctx.r9.u64 = r30.u64 + r31.u64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8266f6fc
	if (cr6.gt) goto loc_8266F6FC;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x8266F6D4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266F6E4;
	sub_82270170(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = r30.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mulli r11,r10,196
	r11.s64 = ctx.r10.s64 * 196;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,312
	ctx.r3.s64 = r11.s64 + 312;
	// bl 0x82500658
	ctx.lr = 0x8266F6FC;
	sub_82500658(ctx, base);
loc_8266F6FC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpwi cr6,r31,10
	cr6.compare<int32_t>(r31.s32, 10, xer);
	// blt cr6,0x8266f69c
	if (cr6.lt) goto loc_8266F69C;
	// lhz r11,852(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 852);
	// addi r8,r28,848
	ctx.r8.s64 = r28.s64 + 848;
	// lwz r9,848(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266f744
	if (cr6.eq) goto loc_8266F744;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_8266F730:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266f730
	if (!cr6.eq) goto loc_8266F730;
loc_8266F744:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r28,1180
	ctx.r9.s64 = r28.s64 + 1180;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// li r5,10
	ctx.r5.s64 = 10;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
loc_8266F760:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266f798
	if (cr6.eq) goto loc_8266F798;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_8266F784:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266f784
	if (!cr6.eq) goto loc_8266F784;
loc_8266F798:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,336
	ctx.r9.s64 = ctx.r9.s64 + 336;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// bne 0x8266f760
	if (!cr0.eq) goto loc_8266F760;
	// stw r26,4504(r28)
	PPC_STORE_U32(r28.u32 + 4504, r26.u32);
	// addi r11,r28,4352
	r11.s64 = r28.s64 + 4352;
	// stw r26,4508(r28)
	PPC_STORE_U32(r28.u32 + 4508, r26.u32);
	// lwz r10,4352(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4352);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8266f7f0
	if (cr6.eq) goto loc_8266F7F0;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266f7f0
	if (!cr6.eq) goto loc_8266F7F0;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// stb r10,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r10.u8);
	// stb r10,73(r11)
	PPC_STORE_U8(r11.u32 + 73, ctx.r10.u8);
	// b 0x8266f7f4
	goto loc_8266F7F4;
loc_8266F7F0:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_8266F7F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266F7FC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r28,4544
	r29.s64 = r28.s64 + 4544;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266F814;
	sub_82270170(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82272df8
	ctx.lr = 0x8266F828;
	sub_82272DF8(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8266F830"))) PPC_WEAK_FUNC(sub_8266F830);
PPC_FUNC_IMPL(__imp__sub_8266F830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8266F838;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29060
	ctx.r8.s64 = r11.s64 + 29060;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,6
	ctx.r9.s64 = 6;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ef58
	ctx.lr = 0x8266F868;
	sub_8266EF58(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r22,r10,-18644
	r22.s64 = ctx.r10.s64 + -18644;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// addi r7,r8,21180
	ctx.r7.s64 = ctx.r8.s64 + 21180;
	// li r30,0
	r30.s64 = 0;
	// addi r23,r11,19036
	r23.s64 = r11.s64 + 19036;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r11,r31,4544
	r11.s64 = r31.s64 + 4544;
	// stw r30,4548(r31)
	PPC_STORE_U32(r31.u32 + 4548, r30.u32);
	// addi r29,r10,560
	r29.s64 = ctx.r10.s64 + 560;
	// stw r30,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r30.u32);
	// lis r11,4096
	r11.s64 = 268435456;
	// stw r30,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r30.u32);
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// stw r23,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r23.u32);
	// lis r9,8192
	ctx.r9.s64 = 536870912;
	// stw r22,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, r22.u32);
	// li r25,9
	r25.s64 = 9;
	// li r24,3
	r24.s64 = 3;
	// ori r26,r11,27
	r26.u64 = r11.u64 | 27;
	// ori r27,r10,30
	r27.u64 = ctx.r10.u64 | 30;
	// ori r28,r9,31
	r28.u64 = ctx.r9.u64 | 31;
loc_8266F8C8:
	// addi r3,r29,-536
	ctx.r3.s64 = r29.s64 + -536;
	// bl 0x824f9438
	ctx.lr = 0x8266F8D0;
	sub_824F9438(ctx, base);
	// lbz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 0);
	// addi r11,r29,-512
	r11.s64 = r29.s64 + -512;
	// stw r24,-512(r29)
	PPC_STORE_U32(r29.u32 + -512, r24.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// std r30,-508(r29)
	PPC_STORE_U64(r29.u32 + -508, r30.u64);
	// stw r26,-500(r29)
	PPC_STORE_U32(r29.u32 + -500, r26.u32);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// stw r27,-492(r29)
	PPC_STORE_U32(r29.u32 + -492, r27.u32);
	// stw r28,-480(r29)
	PPC_STORE_U32(r29.u32 + -480, r28.u32);
	// stb r9,0(r29)
	PPC_STORE_U8(r29.u32 + 0, ctx.r9.u8);
	// stw r11,-520(r29)
	PPC_STORE_U32(r29.u32 + -520, r11.u32);
	// addi r29,r29,568
	r29.s64 = r29.s64 + 568;
	// bge 0x8266f8c8
	if (!cr0.lt) goto loc_8266F8C8;
	// stw r30,10252(r31)
	PPC_STORE_U32(r31.u32 + 10252, r30.u32);
	// addi r29,r31,10272
	r29.s64 = r31.s64 + 10272;
	// stw r30,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r30.u32);
	// addi r11,r31,10248
	r11.s64 = r31.s64 + 10248;
	// stw r30,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, r30.u32);
	// addi r3,r29,24
	ctx.r3.s64 = r29.s64 + 24;
	// stw r23,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, r23.u32);
	// stw r22,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, r22.u32);
	// bl 0x824f9438
	ctx.lr = 0x8266F928;
	sub_824F9438(ctx, base);
	// lbz r6,10832(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 10832);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r24,10320(r31)
	PPC_STORE_U32(r31.u32 + 10320, r24.u32);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// std r30,10324(r31)
	PPC_STORE_U64(r31.u32 + 10324, r30.u64);
	// addi r11,r29,48
	r11.s64 = r29.s64 + 48;
	// stw r26,10332(r31)
	PPC_STORE_U32(r31.u32 + 10332, r26.u32);
	// addi r9,r10,19116
	ctx.r9.s64 = ctx.r10.s64 + 19116;
	// stw r27,10340(r31)
	PPC_STORE_U32(r31.u32 + 10340, r27.u32);
	// stw r28,10352(r31)
	PPC_STORE_U32(r31.u32 + 10352, r28.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stb r5,10832(r31)
	PPC_STORE_U8(r31.u32 + 10832, ctx.r5.u8);
	// addi r10,r31,880
	ctx.r10.s64 = r31.s64 + 880;
	// stw r11,10312(r31)
	PPC_STORE_U32(r31.u32 + 10312, r11.u32);
	// addi r7,r8,29524
	ctx.r7.s64 = ctx.r8.s64 + 29524;
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r30,10848(r31)
	PPC_STORE_U32(r31.u32 + 10848, r30.u32);
	// sth r30,10852(r31)
	PPC_STORE_U16(r31.u32 + 10852, r30.u16);
	// sth r30,10854(r31)
	PPC_STORE_U16(r31.u32 + 10854, r30.u16);
	// stw r30,10856(r31)
	PPC_STORE_U32(r31.u32 + 10856, r30.u32);
	// lhz r4,884(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// sth r11,884(r31)
	PPC_STORE_U16(r31.u32 + 884, r11.u16);
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r11,29524(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 29524);
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,12(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8266FA00"))) PPC_WEAK_FUNC(sub_8266FA00);
PPC_FUNC_IMPL(__imp__sub_8266FA00) {
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
	ctx.lr = 0x8266FA08;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x8266FA28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8266fd04
	if (cr6.eq) goto loc_8266FD04;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266FA3C;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8266FA4C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8266FA54;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fa8c
	if (cr6.eq) goto loc_8266FA8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266FA68;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266FA78;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x8266FA80;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266fac0
	if (!cr6.eq) goto loc_8266FAC0;
loc_8266FA8C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,21160
	ctx.r4.s64 = ctx.r10.s64 + 21160;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x8266FAA8;
	sub_82289AB0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82643bb8
	ctx.lr = 0x8266FAC0;
	sub_82643BB8(ctx, base);
loc_8266FAC0:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// lfs f0,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	f0.f64 = double(temp.f32);
	// addi r28,r31,4352
	r28.s64 = r31.s64 + 4352;
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// li r27,0
	r27.s64 = 0;
	// stfs f13,4520(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x8266fbe0
	if (cr6.eq) goto loc_8266FBE0;
loc_8266FAE8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266fbd8
	if (cr6.eq) goto loc_8266FBD8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266fae8
	if (cr6.lt) goto loc_8266FAE8;
	// li r11,1
	r11.s64 = 1;
loc_8266FB08:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fce8
	if (cr6.eq) goto loc_8266FCE8;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fce8
	if (cr6.eq) goto loc_8266FCE8;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8266fbb8
	if (!cr6.gt) goto loc_8266FBB8;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_8266FB34:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x8266fbb8
	if (!cr6.lt) goto loc_8266FBB8;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266FB58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x8266fb98
	if (cr6.lt) goto loc_8266FB98;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_8266FB98:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b2a0
	ctx.lr = 0x8266FBA4;
	sub_8266B2A0(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8266fb34
	if (cr6.lt) goto loc_8266FB34;
loc_8266FBB8:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266FBC8:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266fbc8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266FBC8;
	// b 0x8266fccc
	goto loc_8266FCCC;
loc_8266FBD8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8266fb08
	goto loc_8266FB08;
loc_8266FBE0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8266fd10
	if (cr6.eq) goto loc_8266FD10;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8266fbe0
	if (cr6.lt) goto loc_8266FBE0;
	// li r11,1
	r11.s64 = 1;
loc_8266FC00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fce8
	if (cr6.eq) goto loc_8266FCE8;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266fce8
	if (cr6.eq) goto loc_8266FCE8;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8266fcb0
	if (!cr6.gt) goto loc_8266FCB0;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_8266FC2C:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x8266fcb0
	if (!cr6.lt) goto loc_8266FCB0;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266FC50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x8266fc90
	if (cr6.lt) goto loc_8266FC90;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_8266FC90:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b2a0
	ctx.lr = 0x8266FC9C;
	sub_8266B2A0(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x8266fc2c
	if (cr6.lt) goto loc_8266FC2C;
loc_8266FCB0:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8266FCC0:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8266fcc0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8266FCC0;
loc_8266FCCC:
	// stb r27,73(r28)
	PPC_STORE_U8(r28.u32 + 73, r27.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r27,72(r28)
	PPC_STORE_U8(r28.u32 + 72, r27.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8266FCE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8266FCE8:
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8266fd00
	if (cr6.eq) goto loc_8266FD00;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8266FD00:
	// bl 0x8266d030
	ctx.lr = 0x8266FD04;
	sub_8266D030(ctx, base);
loc_8266FD04:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8266FD10:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8266fc00
	goto loc_8266FC00;
}

__attribute__((alias("__imp__sub_8266FD18"))) PPC_WEAK_FUNC(sub_8266FD18);
PPC_FUNC_IMPL(__imp__sub_8266FD18) {
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
	ctx.lr = 0x8266FD20;
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// li r31,9
	r31.s64 = 9;
loc_8266FD30:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824f9438
	ctx.lr = 0x8266FD38;
	sub_824F9438(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bge 0x8266fd30
	if (!cr0.lt) goto loc_8266FD30;
	// li r25,0
	r25.s64 = 0;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// mr r27,r25
	r27.u64 = r25.u64;
	// mr r31,r25
	r31.u64 = r25.u64;
	// lis r26,-32121
	r26.s64 = -2105081856;
loc_8266FD58:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x8266FD64;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266FD74;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// add r9,r30,r31
	ctx.r9.u64 = r30.u64 + r31.u64;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8266fdbc
	if (cr6.gt) goto loc_8266FDBC;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x8266FD90;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266FDA0;
	sub_82270170(ctx, base);
	// add r10,r30,r31
	ctx.r10.u64 = r30.u64 + r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mulli r11,r10,196
	r11.s64 = ctx.r10.s64 * 196;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,312
	ctx.r3.s64 = r11.s64 + 312;
	// bl 0x82500658
	ctx.lr = 0x8266FDB8;
	sub_82500658(ctx, base);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_8266FDBC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpwi cr6,r31,10
	cr6.compare<int32_t>(r31.s32, 10, xer);
	// blt cr6,0x8266fd58
	if (cr6.lt) goto loc_8266FD58;
	// lhz r11,852(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 852);
	// addi r8,r28,848
	ctx.r8.s64 = r28.s64 + 848;
	// lwz r9,848(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266fe04
	if (cr6.eq) goto loc_8266FE04;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_8266FDF0:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266fdf0
	if (!cr6.eq) goto loc_8266FDF0;
loc_8266FE04:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r28,1180
	ctx.r9.s64 = r28.s64 + 1180;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// li r5,10
	ctx.r5.s64 = 10;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
loc_8266FE20:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8266fe58
	if (cr6.eq) goto loc_8266FE58;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_8266FE44:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8266fe44
	if (!cr6.eq) goto loc_8266FE44;
loc_8266FE58:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,336
	ctx.r9.s64 = ctx.r9.s64 + 336;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// bne 0x8266fe20
	if (!cr0.eq) goto loc_8266FE20;
	// stw r25,4504(r28)
	PPC_STORE_U32(r28.u32 + 4504, r25.u32);
	// addi r11,r28,4352
	r11.s64 = r28.s64 + 4352;
	// stw r25,4508(r28)
	PPC_STORE_U32(r28.u32 + 4508, r25.u32);
	// lwz r10,4352(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4352);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8266feb0
	if (cr6.eq) goto loc_8266FEB0;
	// lbz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8266feb0
	if (!cr6.eq) goto loc_8266FEB0;
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// stb r10,64(r11)
	PPC_STORE_U8(r11.u32 + 64, ctx.r10.u8);
	// stb r10,73(r11)
	PPC_STORE_U8(r11.u32 + 73, ctx.r10.u8);
	// b 0x8266feb4
	goto loc_8266FEB4;
loc_8266FEB0:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_8266FEB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8266FEBC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r28,4544
	r29.s64 = r28.s64 + 4544;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8266FED4;
	sub_82270170(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82272df8
	ctx.lr = 0x8266FEE8;
	sub_82272DF8(ctx, base);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8266FEF0"))) PPC_WEAK_FUNC(sub_8266FEF0);
PPC_FUNC_IMPL(__imp__sub_8266FEF0) {
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
	ctx.lr = 0x8266FEF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r8
	r29.u64 = ctx.r8.u64;
	// addi r30,r31,10848
	r30.s64 = r31.s64 + 10848;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// cmplw cr6,r30,r29
	cr6.compare<uint32_t>(r30.u32, r29.u32, xer);
	// stw r5,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, ctx.r5.u32);
	// stw r6,10856(r31)
	PPC_STORE_U32(r31.u32 + 10856, ctx.r6.u32);
	// stw r7,10860(r31)
	PPC_STORE_U32(r31.u32 + 10860, ctx.r7.u32);
	// beq cr6,0x8266ff50
	if (cr6.eq) goto loc_8266FF50;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8266ff44
	if (cr6.eq) goto loc_8266FF44;
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8266ff44
	if (cr6.eq) goto loc_8266FF44;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8266FF44;
	sub_82130588(ctx, base);
loc_8266FF44:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c7480
	ctx.lr = 0x8266FF50;
	sub_826C7480(ctx, base);
loc_8266FF50:
	// li r11,0
	r11.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stb r11,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r11.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8266FF64;
	sub_82630318(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8266FF6C"))) PPC_WEAK_FUNC(sub_8266FF6C);
PPC_FUNC_IMPL(__imp__sub_8266FF6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8266FF70"))) PPC_WEAK_FUNC(sub_8266FF70);
PPC_FUNC_IMPL(__imp__sub_8266FF70) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8266FF78;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r20,r11,3998
	r20.s64 = r11.s64 + 3998;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r10,28652
	ctx.r8.s64 = ctx.r10.s64 + 28652;
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// li r9,2
	ctx.r9.s64 = 2;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ef58
	ctx.lr = 0x8266FFAC;
	sub_8266EF58(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r23,r10,-18644
	r23.s64 = ctx.r10.s64 + -18644;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r31,4576
	ctx.r10.s64 = r31.s64 + 4576;
	// addi r7,r8,21988
	ctx.r7.s64 = ctx.r8.s64 + 21988;
	// li r30,0
	r30.s64 = 0;
	// addi r24,r11,19036
	r24.s64 = r11.s64 + 19036;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r11,r31,4552
	r11.s64 = r31.s64 + 4552;
	// stw r30,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r30.u32);
	// addi r26,r10,560
	r26.s64 = ctx.r10.s64 + 560;
	// stw r30,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r30.u32);
	// li r25,3
	r25.s64 = 3;
	// stw r30,4564(r31)
	PPC_STORE_U32(r31.u32 + 4564, r30.u32);
	// lis r11,4096
	r11.s64 = 268435456;
	// stw r24,4568(r31)
	PPC_STORE_U32(r31.u32 + 4568, r24.u32);
	// lis r10,8192
	ctx.r10.s64 = 536870912;
	// stw r23,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r23.u32);
	// lis r9,8192
	ctx.r9.s64 = 536870912;
	// mr r22,r25
	r22.u64 = r25.u64;
	// ori r27,r11,27
	r27.u64 = r11.u64 | 27;
	// ori r28,r10,30
	r28.u64 = ctx.r10.u64 | 30;
	// ori r29,r9,31
	r29.u64 = ctx.r9.u64 | 31;
loc_8267000C:
	// addi r3,r26,-536
	ctx.r3.s64 = r26.s64 + -536;
	// bl 0x824f9438
	ctx.lr = 0x82670014;
	sub_824F9438(ctx, base);
	// lbz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U8(r26.u32 + 0);
	// addi r11,r26,-512
	r11.s64 = r26.s64 + -512;
	// stw r25,-512(r26)
	PPC_STORE_U32(r26.u32 + -512, r25.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// std r30,-508(r26)
	PPC_STORE_U64(r26.u32 + -508, r30.u64);
	// stw r27,-500(r26)
	PPC_STORE_U32(r26.u32 + -500, r27.u32);
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// stw r28,-492(r26)
	PPC_STORE_U32(r26.u32 + -492, r28.u32);
	// stw r29,-480(r26)
	PPC_STORE_U32(r26.u32 + -480, r29.u32);
	// stb r9,0(r26)
	PPC_STORE_U8(r26.u32 + 0, ctx.r9.u8);
	// stw r11,-520(r26)
	PPC_STORE_U32(r26.u32 + -520, r11.u32);
	// addi r26,r26,568
	r26.s64 = r26.s64 + 568;
	// bge 0x8267000c
	if (!cr0.lt) goto loc_8267000C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r26,r31,6848
	r26.s64 = r31.s64 + 6848;
	// mr r22,r25
	r22.u64 = r25.u64;
	// addi r21,r11,14724
	r21.s64 = r11.s64 + 14724;
loc_82670058:
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82633d40
	ctx.lr = 0x82670068;
	sub_82633D40(ctx, base);
	// stw r21,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r21.u32);
	// stw r30,220(r26)
	PPC_STORE_U32(r26.u32 + 220, r30.u32);
	// addic. r22,r22,-1
	xer.ca = r22.u32 > 0;
	r22.s64 = r22.s64 + -1;
	cr0.compare<int32_t>(r22.s32, 0, xer);
	// stw r30,216(r26)
	PPC_STORE_U32(r26.u32 + 216, r30.u32);
	// stw r30,316(r26)
	PPC_STORE_U32(r26.u32 + 316, r30.u32);
	// stw r30,312(r26)
	PPC_STORE_U32(r26.u32 + 312, r30.u32);
	// stw r30,208(r26)
	PPC_STORE_U32(r26.u32 + 208, r30.u32);
	// stw r30,308(r26)
	PPC_STORE_U32(r26.u32 + 308, r30.u32);
	// stw r30,212(r26)
	PPC_STORE_U32(r26.u32 + 212, r30.u32);
	// stw r30,320(r26)
	PPC_STORE_U32(r26.u32 + 320, r30.u32);
	// addi r26,r26,336
	r26.s64 = r26.s64 + 336;
	// bge 0x82670058
	if (!cr0.lt) goto loc_82670058;
	// stw r30,8224(r31)
	PPC_STORE_U32(r31.u32 + 8224, r30.u32);
	// addi r26,r31,8248
	r26.s64 = r31.s64 + 8248;
	// stw r30,8228(r31)
	PPC_STORE_U32(r31.u32 + 8228, r30.u32);
	// addi r11,r31,8220
	r11.s64 = r31.s64 + 8220;
	// stw r30,8232(r31)
	PPC_STORE_U32(r31.u32 + 8232, r30.u32);
	// addi r3,r26,24
	ctx.r3.s64 = r26.s64 + 24;
	// stw r24,8236(r31)
	PPC_STORE_U32(r31.u32 + 8236, r24.u32);
	// stw r23,8220(r31)
	PPC_STORE_U32(r31.u32 + 8220, r23.u32);
	// bl 0x824f9438
	ctx.lr = 0x826700BC;
	sub_824F9438(ctx, base);
	// addi r10,r31,8816
	ctx.r10.s64 = r31.s64 + 8816;
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// stw r25,8296(r31)
	PPC_STORE_U32(r31.u32 + 8296, r25.u32);
	// std r30,8300(r31)
	PPC_STORE_U64(r31.u32 + 8300, r30.u64);
	// addi r26,r31,8840
	r26.s64 = r31.s64 + 8840;
	// stw r27,8308(r31)
	PPC_STORE_U32(r31.u32 + 8308, r27.u32);
	// stw r28,8316(r31)
	PPC_STORE_U32(r31.u32 + 8316, r28.u32);
	// addi r3,r26,24
	ctx.r3.s64 = r26.s64 + 24;
	// stw r29,8328(r31)
	PPC_STORE_U32(r31.u32 + 8328, r29.u32);
	// lbz r10,8808(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 8808);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,8808(r31)
	PPC_STORE_U8(r31.u32 + 8808, ctx.r9.u8);
	// stw r11,8288(r31)
	PPC_STORE_U32(r31.u32 + 8288, r11.u32);
	// stw r30,8820(r31)
	PPC_STORE_U32(r31.u32 + 8820, r30.u32);
	// stw r30,8824(r31)
	PPC_STORE_U32(r31.u32 + 8824, r30.u32);
	// stw r30,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, r30.u32);
	// stw r24,8832(r31)
	PPC_STORE_U32(r31.u32 + 8832, r24.u32);
	// stw r23,8816(r31)
	PPC_STORE_U32(r31.u32 + 8816, r23.u32);
	// bl 0x824f9438
	ctx.lr = 0x82670108;
	sub_824F9438(ctx, base);
	// lbz r8,9400(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 9400);
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// stw r25,8888(r31)
	PPC_STORE_U32(r31.u32 + 8888, r25.u32);
	// ori r7,r8,128
	ctx.r7.u64 = ctx.r8.u64 | 128;
	// std r30,8892(r31)
	PPC_STORE_U64(r31.u32 + 8892, r30.u64);
	// stw r27,8900(r31)
	PPC_STORE_U32(r31.u32 + 8900, r27.u32);
	// addi r26,r31,9432
	r26.s64 = r31.s64 + 9432;
	// stw r28,8908(r31)
	PPC_STORE_U32(r31.u32 + 8908, r28.u32);
	// addi r10,r31,9408
	ctx.r10.s64 = r31.s64 + 9408;
	// stw r29,8920(r31)
	PPC_STORE_U32(r31.u32 + 8920, r29.u32);
	// addi r3,r26,24
	ctx.r3.s64 = r26.s64 + 24;
	// stb r7,9400(r31)
	PPC_STORE_U8(r31.u32 + 9400, ctx.r7.u8);
	// stw r11,8880(r31)
	PPC_STORE_U32(r31.u32 + 8880, r11.u32);
	// stw r30,9412(r31)
	PPC_STORE_U32(r31.u32 + 9412, r30.u32);
	// stw r30,9416(r31)
	PPC_STORE_U32(r31.u32 + 9416, r30.u32);
	// stw r30,9420(r31)
	PPC_STORE_U32(r31.u32 + 9420, r30.u32);
	// stw r24,9424(r31)
	PPC_STORE_U32(r31.u32 + 9424, r24.u32);
	// stw r23,9408(r31)
	PPC_STORE_U32(r31.u32 + 9408, r23.u32);
	// bl 0x824f9438
	ctx.lr = 0x82670154;
	sub_824F9438(ctx, base);
	// lbz r6,9992(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 9992);
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// stw r25,9480(r31)
	PPC_STORE_U32(r31.u32 + 9480, r25.u32);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// std r30,9484(r31)
	PPC_STORE_U64(r31.u32 + 9484, r30.u64);
	// stw r27,9492(r31)
	PPC_STORE_U32(r31.u32 + 9492, r27.u32);
	// addi r26,r31,10024
	r26.s64 = r31.s64 + 10024;
	// stw r28,9500(r31)
	PPC_STORE_U32(r31.u32 + 9500, r28.u32);
	// stw r29,9512(r31)
	PPC_STORE_U32(r31.u32 + 9512, r29.u32);
	// addi r3,r26,24
	ctx.r3.s64 = r26.s64 + 24;
	// stb r5,9992(r31)
	PPC_STORE_U8(r31.u32 + 9992, ctx.r5.u8);
	// stw r11,9472(r31)
	PPC_STORE_U32(r31.u32 + 9472, r11.u32);
	// addi r11,r31,10000
	r11.s64 = r31.s64 + 10000;
	// stw r30,10004(r31)
	PPC_STORE_U32(r31.u32 + 10004, r30.u32);
	// stw r30,10008(r31)
	PPC_STORE_U32(r31.u32 + 10008, r30.u32);
	// stw r30,10012(r31)
	PPC_STORE_U32(r31.u32 + 10012, r30.u32);
	// stw r24,10016(r31)
	PPC_STORE_U32(r31.u32 + 10016, r24.u32);
	// stw r23,10000(r31)
	PPC_STORE_U32(r31.u32 + 10000, r23.u32);
	// bl 0x824f9438
	ctx.lr = 0x826701A0;
	sub_824F9438(ctx, base);
	// lbz r3,10584(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 10584);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// stw r25,10072(r31)
	PPC_STORE_U32(r31.u32 + 10072, r25.u32);
	// ori r7,r3,128
	ctx.r7.u64 = ctx.r3.u64 | 128;
	// std r30,10076(r31)
	PPC_STORE_U64(r31.u32 + 10076, r30.u64);
	// addi r11,r26,48
	r11.s64 = r26.s64 + 48;
	// stw r27,10084(r31)
	PPC_STORE_U32(r31.u32 + 10084, r27.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r28,10092(r31)
	PPC_STORE_U32(r31.u32 + 10092, r28.u32);
	// stw r29,10104(r31)
	PPC_STORE_U32(r31.u32 + 10104, r29.u32);
	// addi r9,r4,19116
	ctx.r9.s64 = ctx.r4.s64 + 19116;
	// stb r7,10584(r31)
	PPC_STORE_U8(r31.u32 + 10584, ctx.r7.u8);
	// addi r10,r31,880
	ctx.r10.s64 = r31.s64 + 880;
	// addi r6,r8,29524
	ctx.r6.s64 = ctx.r8.s64 + 29524;
	// stw r11,10064(r31)
	PPC_STORE_U32(r31.u32 + 10064, r11.u32);
	// stw r9,10592(r31)
	PPC_STORE_U32(r31.u32 + 10592, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,29524(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 29524);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r9,884(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,12(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// stb r30,10600(r31)
	PPC_STORE_U8(r31.u32 + 10600, r30.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82670270"))) PPC_WEAK_FUNC(sub_82670270);
PPC_FUNC_IMPL(__imp__sub_82670270) {
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
	ctx.lr = 0x82670278;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r10,-28
	r30.s64 = ctx.r10.s64 + -28;
	// addi r29,r11,48
	r29.s64 = r11.s64 + 48;
	// stw r30,10592(r31)
	PPC_STORE_U32(r31.u32 + 10592, r30.u32);
	// addi r28,r31,8192
	r28.s64 = r31.s64 + 8192;
	// stw r30,10016(r31)
	PPC_STORE_U32(r31.u32 + 10016, r30.u32);
	// li r27,3
	r27.s64 = 3;
	// stw r29,10000(r31)
	PPC_STORE_U32(r31.u32 + 10000, r29.u32);
	// stw r30,9424(r31)
	PPC_STORE_U32(r31.u32 + 9424, r30.u32);
	// stw r29,9408(r31)
	PPC_STORE_U32(r31.u32 + 9408, r29.u32);
	// stw r30,8832(r31)
	PPC_STORE_U32(r31.u32 + 8832, r30.u32);
	// stw r29,8816(r31)
	PPC_STORE_U32(r31.u32 + 8816, r29.u32);
	// stw r30,8236(r31)
	PPC_STORE_U32(r31.u32 + 8236, r30.u32);
	// stw r29,8220(r31)
	PPC_STORE_U32(r31.u32 + 8220, r29.u32);
loc_826702BC:
	// addi r28,r28,-336
	r28.s64 = r28.s64 + -336;
	// lhz r11,194(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 194);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826702d4
	if (cr6.eq) goto loc_826702D4;
	// lwz r3,188(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 188);
	// bl 0x82130588
	ctx.lr = 0x826702D4;
	sub_82130588(ctx, base);
loc_826702D4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82633b00
	ctx.lr = 0x826702DC;
	sub_82633B00(ctx, base);
	// addic. r27,r27,-1
	xer.ca = r27.u32 > 0;
	r27.s64 = r27.s64 + -1;
	cr0.compare<int32_t>(r27.s32, 0, xer);
	// bge 0x826702bc
	if (!cr0.lt) goto loc_826702BC;
	// stw r30,4568(r31)
	PPC_STORE_U32(r31.u32 + 4568, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r29.u32);
	// bl 0x8266f0d8
	ctx.lr = 0x826702F4;
	sub_8266F0D8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826702FC"))) PPC_WEAK_FUNC(sub_826702FC);
PPC_FUNC_IMPL(__imp__sub_826702FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82670300"))) PPC_WEAK_FUNC(sub_82670300);
PPC_FUNC_IMPL(__imp__sub_82670300) {
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
	ctx.lr = 0x82670308;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r8,r31,848
	ctx.r8.s64 = r31.s64 + 848;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82670348
	if (cr6.eq) goto loc_82670348;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82670334:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82670334
	if (!cr6.eq) goto loc_82670334;
loc_82670348:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r31,7036
	ctx.r9.s64 = r31.s64 + 7036;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// li r5,4
	ctx.r5.s64 = 4;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
loc_82670364:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8267039c
	if (cr6.eq) goto loc_8267039C;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_82670388:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82670388
	if (!cr6.eq) goto loc_82670388;
loc_8267039C:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,336
	ctx.r9.s64 = ctx.r9.s64 + 336;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// bne 0x82670364
	if (!cr0.eq) goto loc_82670364;
	// addi r11,r31,8248
	r11.s64 = r31.s64 + 8248;
	// li r29,1
	r29.s64 = 1;
	// stw r11,8232(r31)
	PPC_STORE_U32(r31.u32 + 8232, r11.u32);
	// addi r28,r31,8220
	r28.s64 = r31.s64 + 8220;
	// stw r29,8228(r31)
	PPC_STORE_U32(r31.u32 + 8228, r29.u32);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r10,r11,10
	ctx.r10.s64 = r11.s64 + 10;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// cmplwi cr6,r10,351
	cr6.compare<uint32_t>(ctx.r10.u32, 351, xer);
	// blt cr6,0x826703f0
	if (cr6.lt) goto loc_826703F0;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
loc_826703F0:
	// stw r10,10596(r31)
	PPC_STORE_U32(r31.u32 + 10596, ctx.r10.u32);
	// addi r11,r31,10592
	r11.s64 = r31.s64 + 10592;
	// addi r10,r31,8840
	ctx.r10.s64 = r31.s64 + 8840;
	// stw r11,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r11.u32);
	// addi r25,r31,8816
	r25.s64 = r31.s64 + 8816;
	// stw r10,8828(r31)
	PPC_STORE_U32(r31.u32 + 8828, ctx.r10.u32);
	// stw r29,8824(r31)
	PPC_STORE_U32(r31.u32 + 8824, r29.u32);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r9,r10,10
	ctx.r9.s64 = ctx.r10.s64 + 10;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplwi cr6,r10,351
	cr6.compare<uint32_t>(ctx.r10.u32, 351, xer);
	// blt cr6,0x8267042c
	if (cr6.lt) goto loc_8267042C;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
loc_8267042C:
	// addi r9,r31,9432
	ctx.r9.s64 = r31.s64 + 9432;
	// stw r10,10596(r31)
	PPC_STORE_U32(r31.u32 + 10596, ctx.r10.u32);
	// stw r11,20(r25)
	PPC_STORE_U32(r25.u32 + 20, r11.u32);
	// addi r23,r31,9408
	r23.s64 = r31.s64 + 9408;
	// stw r9,9420(r31)
	PPC_STORE_U32(r31.u32 + 9420, ctx.r9.u32);
	// stw r29,9416(r31)
	PPC_STORE_U32(r31.u32 + 9416, r29.u32);
	// lwz r9,4544(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r8,r10,10
	ctx.r8.s64 = ctx.r10.s64 + 10;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,351
	cr6.compare<uint32_t>(ctx.r10.u32, 351, xer);
	// blt cr6,0x82670464
	if (cr6.lt) goto loc_82670464;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
loc_82670464:
	// stw r10,10596(r31)
	PPC_STORE_U32(r31.u32 + 10596, ctx.r10.u32);
	// addi r9,r31,10024
	ctx.r9.s64 = r31.s64 + 10024;
	// stw r11,20(r23)
	PPC_STORE_U32(r23.u32 + 20, r11.u32);
	// addi r22,r31,10000
	r22.s64 = r31.s64 + 10000;
	// stw r29,10008(r31)
	PPC_STORE_U32(r31.u32 + 10008, r29.u32);
	// stw r9,10012(r31)
	PPC_STORE_U32(r31.u32 + 10012, ctx.r9.u32);
	// lwz r9,4544(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r8,r10,10
	ctx.r8.s64 = ctx.r10.s64 + 10;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// cmplwi cr6,r10,351
	cr6.compare<uint32_t>(ctx.r10.u32, 351, xer);
	// blt cr6,0x8267049c
	if (cr6.lt) goto loc_8267049C;
	// addi r10,r10,31
	ctx.r10.s64 = ctx.r10.s64 + 31;
loc_8267049C:
	// li r21,0
	r21.s64 = 0;
	// stw r10,10596(r31)
	PPC_STORE_U32(r31.u32 + 10596, ctx.r10.u32);
	// stw r11,20(r22)
	PPC_STORE_U32(r22.u32 + 20, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r21.u32);
	// stw r21,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r21.u32);
	// bl 0x82388580
	ctx.lr = 0x826704B8;
	sub_82388580(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r24,r31,8216
	r24.s64 = r31.s64 + 8216;
	// addi r26,r1,80
	r26.s64 = ctx.r1.s64 + 80;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r20,4(r10)
	r20.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r30,-10240(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826704E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82270170
	ctx.lr = 0x826704F4;
	sub_82270170(ctx, base);
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// bl 0x82272e08
	ctx.lr = 0x82670504;
	sub_82272E08(ctx, base);
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r8,1
	cr6.compare<uint32_t>(ctx.r8.u32, 1, xer);
	// bne cr6,0x82670544
	if (!cr6.eq) goto loc_82670544;
loc_82670510:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670518;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670528;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x8267052C;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82670530;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82670538;
	sub_821C91B8(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82670510
	if (cr6.eq) goto loc_82670510;
loc_82670544:
	// addi r31,r31,4352
	r31.s64 = r31.s64 + 4352;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r10,3
	ctx.r10.s64 = 3;
	// cmplwi cr6,r11,20
	cr6.compare<uint32_t>(r11.u32, 20, xer);
	// divwu r26,r11,r10
	r26.u32 = r11.u32 / ctx.r10.u32;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bge cr6,0x826706c0
	if (!cr6.lt) goto loc_826706C0;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x82670584
	if (cr6.eq) goto loc_82670584;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82670584
	if (!cr6.eq) goto loc_82670584;
	// stb r29,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r29.u8);
	// mr r30,r31
	r30.u64 = r31.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670588
	goto loc_82670588;
loc_82670584:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670588:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670590;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826705A0;
	sub_82270170(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x826705B0;
	sub_82272E00(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x826705dc
	if (cr6.eq) goto loc_826705DC;
	// lbz r10,65(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826705dc
	if (!cr6.eq) goto loc_826705DC;
	// stb r29,65(r31)
	PPC_STORE_U8(r31.u32 + 65, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x826705e0
	goto loc_826705E0;
loc_826705DC:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_826705E0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826705E8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826705F8;
	sub_82270170(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x82670608;
	sub_82272E00(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82670634
	if (cr6.eq) goto loc_82670634;
	// lbz r10,66(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 66);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82670634
	if (!cr6.eq) goto loc_82670634;
	// stb r29,66(r31)
	PPC_STORE_U8(r31.u32 + 66, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670638
	goto loc_82670638;
loc_82670634:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670638:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670640;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670650;
	sub_82270170(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x82670660;
	sub_82272E00(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r31,24
	r11.s64 = r31.s64 + 24;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8267068c
	if (cr6.eq) goto loc_8267068C;
	// lbz r10,67(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 67);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8267068c
	if (!cr6.eq) goto loc_8267068C;
	// stb r29,67(r31)
	PPC_STORE_U8(r31.u32 + 67, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670690
	goto loc_82670690;
loc_8267068C:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670690:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670698;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826706A8;
	sub_82270170(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82272e00
	ctx.lr = 0x826706B8;
	sub_82272E00(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
loc_826706C0:
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x826706e4
	if (cr6.eq) goto loc_826706E4;
	// lbz r11,64(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826706e4
	if (!cr6.eq) goto loc_826706E4;
	// stb r29,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r29.u8);
	// mr r30,r31
	r30.u64 = r31.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x826706e8
	goto loc_826706E8;
loc_826706E4:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_826706E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826706F0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670700;
	sub_82270170(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x82670710;
	sub_82272E00(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x8267073c
	if (cr6.eq) goto loc_8267073C;
	// lbz r10,65(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 65);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8267073c
	if (!cr6.eq) goto loc_8267073C;
	// stb r29,65(r31)
	PPC_STORE_U8(r31.u32 + 65, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670740
	goto loc_82670740;
loc_8267073C:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670740:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670748;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670758;
	sub_82270170(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x82670768;
	sub_82272E00(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x82670794
	if (cr6.eq) goto loc_82670794;
	// lbz r10,66(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 66);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82670794
	if (!cr6.eq) goto loc_82670794;
	// stb r29,66(r31)
	PPC_STORE_U8(r31.u32 + 66, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x82670798
	goto loc_82670798;
loc_82670794:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_82670798:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826707A0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826707B0;
	sub_82270170(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// rlwinm r5,r26,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82272e00
	ctx.lr = 0x826707C0;
	sub_82272E00(ctx, base);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r11,r31,24
	r11.s64 = r31.s64 + 24;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x826707ec
	if (cr6.eq) goto loc_826707EC;
	// lbz r10,67(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 67);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826707ec
	if (!cr6.eq) goto loc_826707EC;
	// stb r29,67(r31)
	PPC_STORE_U8(r31.u32 + 67, r29.u8);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stb r29,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r29.u8);
	// b 0x826707f0
	goto loc_826707F0;
loc_826707EC:
	// mr r30,r21
	r30.u64 = r21.u64;
loc_826707F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826707F8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r31,0(r24)
	r31.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8267080C;
	sub_82270170(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x82272e00
	ctx.lr = 0x8267081C;
	sub_82272E00(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_82670824"))) PPC_WEAK_FUNC(sub_82670824);
PPC_FUNC_IMPL(__imp__sub_82670824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82670828"))) PPC_WEAK_FUNC(sub_82670828);
PPC_FUNC_IMPL(__imp__sub_82670828) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x82670830;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r26,r7
	r26.u64 = ctx.r7.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8267085C;
	sub_821F9FB8(ctx, base);
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r31,r9,14672
	r31.s64 = ctx.r9.s64 + 14672;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r24,56(r25)
	r24.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82670878;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x82670888;
	sub_825ED480(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r31,56(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// addi r23,r8,2612
	r23.s64 = ctx.r8.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821c9790
	ctx.lr = 0x826708A4;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x825ed480
	ctx.lr = 0x826708B4;
	sub_825ED480(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r3,r7,-13268
	ctx.r3.s64 = ctx.r7.s64 + -13268;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x826708CC;
	sub_821C9790(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// li r31,0
	r31.s64 = 0;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x826708F0;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670908;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r8,65(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 65);
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82670920;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r6,56(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 56);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82670938;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// addi r4,r4,1072
	ctx.r4.s64 = ctx.r4.s64 + 1072;
	// bl 0x825ee0e0
	ctx.lr = 0x8267094C;
	sub_825EE0E0(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-13284
	ctx.r4.s64 = r11.s64 + -13284;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82722678
	ctx.lr = 0x82670968;
	sub_82722678(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-14304
	ctx.r4.s64 = ctx.r10.s64 + -14304;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8267097C;
	sub_82218310(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r8,20268
	ctx.r4.s64 = ctx.r8.s64 + 20268;
	// bl 0x827227b8
	ctx.lr = 0x82670994;
	sub_827227B8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267099C;
	sub_82388580(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r3,-10240(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826709B0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x826709B8;
	sub_824E7118(ctx, base);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r4,-11016
	ctx.r4.s64 = ctx.r4.s64 + -11016;
	// bl 0x827227b8
	ctx.lr = 0x826709CC;
	sub_827227B8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r4,r11,-11024
	ctx.r4.s64 = r11.s64 + -11024;
	// bl 0x827227b8
	ctx.lr = 0x826709E0;
	sub_827227B8(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// addi r4,r10,-11032
	ctx.r4.s64 = ctx.r10.s64 + -11032;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827227b8
	ctx.lr = 0x826709F4;
	sub_827227B8(ctx, base);
	// stw r28,4528(r30)
	PPC_STORE_U32(r30.u32 + 4528, r28.u32);
	// stw r27,4544(r30)
	PPC_STORE_U32(r30.u32 + 4544, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r26,4548(r30)
	PPC_STORE_U32(r30.u32 + 4548, r26.u32);
	// bl 0x82670300
	ctx.lr = 0x82670A08;
	sub_82670300(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,1120(r11)
	PPC_STORE_U8(r11.u32 + 1120, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,372(r11)
	PPC_STORE_U8(r11.u32 + 372, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,1427(r11)
	PPC_STORE_U8(r11.u32 + 1427, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,1401(r11)
	PPC_STORE_U8(r11.u32 + 1401, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,375(r11)
	PPC_STORE_U8(r11.u32 + 375, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,374(r11)
	PPC_STORE_U8(r11.u32 + 374, r31.u8);
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r31,377(r11)
	PPC_STORE_U8(r11.u32 + 377, r31.u8);
	// bl 0x82630318
	ctx.lr = 0x82670A50;
	sub_82630318(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82670A58"))) PPC_WEAK_FUNC(sub_82670A58);
PPC_FUNC_IMPL(__imp__sub_82670A58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82670A60;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// addi r8,r11,29060
	ctx.r8.s64 = r11.s64 + 29060;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// li r9,6
	ctx.r9.s64 = 6;
	// li r7,7
	ctx.r7.s64 = 7;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ef58
	ctx.lr = 0x82670A90;
	sub_8266EF58(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// addi r21,r10,14684
	r21.s64 = ctx.r10.s64 + 14684;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// addi r7,r8,22796
	ctx.r7.s64 = ctx.r8.s64 + 22796;
	// li r29,0
	r29.s64 = 0;
	// addi r22,r11,484
	r22.s64 = r11.s64 + 484;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r11,r31,4544
	r11.s64 = r31.s64 + 4544;
	// stw r29,4548(r31)
	PPC_STORE_U32(r31.u32 + 4548, r29.u32);
	// addi r30,r10,560
	r30.s64 = ctx.r10.s64 + 560;
	// stw r29,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, r29.u32);
	// lis r11,8192
	r11.s64 = 536870912;
	// stw r29,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r29.u32);
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// stw r22,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, r22.u32);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// stw r21,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, r21.u32);
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// li r24,9
	r24.s64 = 9;
	// li r23,4
	r23.s64 = 4;
	// ori r25,r11,44
	r25.u64 = r11.u64 | 44;
	// ori r26,r10,36
	r26.u64 = ctx.r10.u64 | 36;
	// ori r27,r9,39
	r27.u64 = ctx.r9.u64 | 39;
	// ori r28,r8,40
	r28.u64 = ctx.r8.u64 | 40;
loc_82670AF8:
	// addi r3,r30,-536
	ctx.r3.s64 = r30.s64 + -536;
	// bl 0x824f9438
	ctx.lr = 0x82670B00;
	sub_824F9438(ctx, base);
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// addi r11,r30,-512
	r11.s64 = r30.s64 + -512;
	// stw r23,-512(r30)
	PPC_STORE_U32(r30.u32 + -512, r23.u32);
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// std r29,-508(r30)
	PPC_STORE_U64(r30.u32 + -508, r29.u64);
	// stw r25,-500(r30)
	PPC_STORE_U32(r30.u32 + -500, r25.u32);
	// addic. r24,r24,-1
	xer.ca = r24.u32 > 0;
	r24.s64 = r24.s64 + -1;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// stw r26,-488(r30)
	PPC_STORE_U32(r30.u32 + -488, r26.u32);
	// stw r27,-480(r30)
	PPC_STORE_U32(r30.u32 + -480, r27.u32);
	// stw r28,-472(r30)
	PPC_STORE_U32(r30.u32 + -472, r28.u32);
	// stb r9,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r9.u8);
	// stw r11,-520(r30)
	PPC_STORE_U32(r30.u32 + -520, r11.u32);
	// addi r30,r30,568
	r30.s64 = r30.s64 + 568;
	// bge 0x82670af8
	if (!cr0.lt) goto loc_82670AF8;
	// stw r29,10252(r31)
	PPC_STORE_U32(r31.u32 + 10252, r29.u32);
	// addi r30,r31,10272
	r30.s64 = r31.s64 + 10272;
	// stw r29,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r29.u32);
	// addi r11,r31,10248
	r11.s64 = r31.s64 + 10248;
	// stw r29,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, r29.u32);
	// addi r3,r30,24
	ctx.r3.s64 = r30.s64 + 24;
	// stw r22,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, r22.u32);
	// stw r21,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, r21.u32);
	// bl 0x824f9438
	ctx.lr = 0x82670B5C;
	sub_824F9438(ctx, base);
	// lbz r6,10832(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 10832);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r23,10320(r31)
	PPC_STORE_U32(r31.u32 + 10320, r23.u32);
	// ori r5,r6,128
	ctx.r5.u64 = ctx.r6.u64 | 128;
	// std r29,10324(r31)
	PPC_STORE_U64(r31.u32 + 10324, r29.u64);
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// stw r25,10332(r31)
	PPC_STORE_U32(r31.u32 + 10332, r25.u32);
	// addi r9,r10,564
	ctx.r9.s64 = ctx.r10.s64 + 564;
	// stw r26,10344(r31)
	PPC_STORE_U32(r31.u32 + 10344, r26.u32);
	// stw r27,10352(r31)
	PPC_STORE_U32(r31.u32 + 10352, r27.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r28,10360(r31)
	PPC_STORE_U32(r31.u32 + 10360, r28.u32);
	// addi r10,r31,880
	ctx.r10.s64 = r31.s64 + 880;
	// stb r5,10832(r31)
	PPC_STORE_U8(r31.u32 + 10832, ctx.r5.u8);
	// addi r7,r8,29540
	ctx.r7.s64 = ctx.r8.s64 + 29540;
	// stw r11,10312(r31)
	PPC_STORE_U32(r31.u32 + 10312, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// lhz r4,884(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// sth r11,884(r31)
	PPC_STORE_U16(r31.u32 + 884, r11.u16);
	// rotlwi r9,r4,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// lwz r11,29540(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 29540);
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r9,884(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r10,880(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,12(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	// stwx r11,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r11.u32);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,16(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lhz r5,884(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r5,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// sth r4,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r4.u16);
	// lwz r11,20(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// lhz r10,884(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 884);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// lwz r9,880(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,884(r31)
	PPC_STORE_U16(r31.u32 + 884, ctx.r8.u16);
	// lwz r11,24(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// stwx r11,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82670C88"))) PPC_WEAK_FUNC(sub_82670C88);
PPC_FUNC_IMPL(__imp__sub_82670C88) {
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
	ctx.lr = 0x82670C90;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x82670CB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82670f8c
	if (cr6.eq) goto loc_82670F8C;
	// lfs f0,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	f0.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,4520(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// bl 0x82388580
	ctx.lr = 0x82670CD0;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82670CE0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82670CE8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670d20
	if (cr6.eq) goto loc_82670D20;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82670CFC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82670D0C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82670D14;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82670d54
	if (!cr6.eq) goto loc_82670D54;
loc_82670D20:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,21160
	ctx.r4.s64 = ctx.r10.s64 + 21160;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x82670D3C;
	sub_82289AB0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r7,1
	ctx.r3.s64 = ctx.r7.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82643bb8
	ctx.lr = 0x82670D54;
	sub_82643BB8(ctx, base);
loc_82670D54:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r28,r31,4352
	r28.s64 = r31.s64 + 4352;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x82670e68
	if (cr6.eq) goto loc_82670E68;
loc_82670D70:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82670e60
	if (cr6.eq) goto loc_82670E60;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82670d70
	if (cr6.lt) goto loc_82670D70;
	// li r11,1
	r11.s64 = 1;
loc_82670D90:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670f70
	if (cr6.eq) goto loc_82670F70;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670f70
	if (cr6.eq) goto loc_82670F70;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82670e40
	if (!cr6.gt) goto loc_82670E40;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_82670DBC:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82670e40
	if (!cr6.lt) goto loc_82670E40;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670DE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x82670e20
	if (cr6.lt) goto loc_82670E20;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_82670E20:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b530
	ctx.lr = 0x82670E2C;
	sub_8266B530(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82670dbc
	if (cr6.lt) goto loc_82670DBC;
loc_82670E40:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82670E50:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82670e50
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82670E50;
	// b 0x82670f54
	goto loc_82670F54;
loc_82670E60:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82670d90
	goto loc_82670D90;
loc_82670E68:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82670f98
	if (cr6.eq) goto loc_82670F98;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82670e68
	if (cr6.lt) goto loc_82670E68;
	// li r11,1
	r11.s64 = 1;
loc_82670E88:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670f70
	if (cr6.eq) goto loc_82670F70;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82670f70
	if (cr6.eq) goto loc_82670F70;
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r30,r27
	r30.u64 = r27.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82670f38
	if (!cr6.gt) goto loc_82670F38;
	// addi r29,r31,992
	r29.s64 = r31.s64 + 992;
loc_82670EB4:
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bge cr6,0x82670f38
	if (!cr6.lt) goto loc_82670F38;
	// lwz r11,4544(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670ED8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r9,4504(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// blt cr6,0x82670f18
	if (cr6.lt) goto loc_82670F18;
	// lhz r9,852(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r8.u16);
	// stwx r29,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r29.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
loc_82670F18:
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b530
	ctx.lr = 0x82670F24;
	sub_8266B530(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,336
	r29.s64 = r29.s64 + 336;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82670eb4
	if (cr6.lt) goto loc_82670EB4;
loc_82670F38:
	// addi r11,r28,64
	r11.s64 = r28.s64 + 64;
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82670F48:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82670f48
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82670F48;
loc_82670F54:
	// stb r27,73(r28)
	PPC_STORE_U8(r28.u32 + 73, r27.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r27,72(r28)
	PPC_STORE_U8(r28.u32 + 72, r27.u8);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82670F70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82670F70:
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82670f88
	if (cr6.eq) goto loc_82670F88;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82670F88:
	// bl 0x8266d7b8
	ctx.lr = 0x82670F8C;
	sub_8266D7B8(ctx, base);
loc_82670F8C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82670F98:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82670e88
	goto loc_82670E88;
}

__attribute__((alias("__imp__sub_82670FA0"))) PPC_WEAK_FUNC(sub_82670FA0);
PPC_FUNC_IMPL(__imp__sub_82670FA0) {
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
	// bl 0x8266f830
	ctx.lr = 0x82670FB8;
	sub_8266F830(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,23604
	ctx.r10.s64 = r11.s64 + 23604;
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

__attribute__((alias("__imp__sub_82670FDC"))) PPC_WEAK_FUNC(sub_82670FDC);
PPC_FUNC_IMPL(__imp__sub_82670FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82670FE0"))) PPC_WEAK_FUNC(sub_82670FE0);
PPC_FUNC_IMPL(__imp__sub_82670FE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// li r7,2
	ctx.r7.s64 = 2;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8265b008
	ctx.lr = 0x82671004;
	sub_8265B008(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// addi r10,r11,-1508
	ctx.r10.s64 = r11.s64 + -1508;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82659e28
	ctx.lr = 0x82671018;
	sub_82659E28(ctx, base);
	// addi r3,r31,952
	ctx.r3.s64 = r31.s64 + 952;
	// bl 0x826597b8
	ctx.lr = 0x82671020;
	sub_826597B8(ctx, base);
	// addi r3,r31,976
	ctx.r3.s64 = r31.s64 + 976;
	// bl 0x82659db8
	ctx.lr = 0x82671028;
	sub_82659DB8(ctx, base);
	// addi r3,r31,992
	ctx.r3.s64 = r31.s64 + 992;
	// bl 0x82659e28
	ctx.lr = 0x82671030;
	sub_82659E28(ctx, base);
	// addi r3,r31,1016
	ctx.r3.s64 = r31.s64 + 1016;
	// bl 0x826597b8
	ctx.lr = 0x82671038;
	sub_826597B8(ctx, base);
	// addi r3,r31,1040
	ctx.r3.s64 = r31.s64 + 1040;
	// bl 0x82659db8
	ctx.lr = 0x82671040;
	sub_82659DB8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32246
	ctx.r7.s64 = -2113273856;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f13,-28964(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -28964);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// addi r10,r7,-4144
	ctx.r10.s64 = ctx.r7.s64 + -4144;
	// stfs f0,1220(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1220, temp.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f0,1224(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1224, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f13,1228(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1228, temp.u32);
	// addi r7,r6,18928
	ctx.r7.s64 = ctx.r6.s64 + 18928;
	// stb r11,1216(r31)
	PPC_STORE_U8(r31.u32 + 1216, r11.u8);
	// stw r11,1364(r31)
	PPC_STORE_U32(r31.u32 + 1364, r11.u32);
	// lfs f0,21528(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 21528);
	f0.f64 = double(temp.f32);
	// stw r9,1368(r31)
	PPC_STORE_U32(r31.u32 + 1368, ctx.r9.u32);
	// lfs f13,-6176(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -6176);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,1372(r31)
	PPC_STORE_U32(r31.u32 + 1372, ctx.r8.u32);
	// addi r3,r31,1424
	ctx.r3.s64 = r31.s64 + 1424;
	// stw r10,1360(r31)
	PPC_STORE_U32(r31.u32 + 1360, ctx.r10.u32);
	// stw r11,1380(r31)
	PPC_STORE_U32(r31.u32 + 1380, r11.u32);
	// stw r7,1376(r31)
	PPC_STORE_U32(r31.u32 + 1376, ctx.r7.u32);
	// stfs f0,1408(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1408, temp.u32);
	// stfs f13,1412(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1412, temp.u32);
	// bl 0x82634b60
	ctx.lr = 0x826710B4;
	sub_82634B60(ctx, base);
	// addi r3,r31,3216
	ctx.r3.s64 = r31.s64 + 3216;
	// bl 0x82634b60
	ctx.lr = 0x826710BC;
	sub_82634B60(ctx, base);
	// lis r6,-32246
	ctx.r6.s64 = -2113273856;
	// lis r5,-32155
	ctx.r5.s64 = -2107310080;
	// addi r3,r6,-3372
	ctx.r3.s64 = ctx.r6.s64 + -3372;
	// addi r4,r5,22568
	ctx.r4.s64 = ctx.r5.s64 + 22568;
	// stw r3,3216(r31)
	PPC_STORE_U32(r31.u32 + 3216, ctx.r3.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821c2f90
	ctx.lr = 0x826710DC;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826710EC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826710ec
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826710EC;
	// addi r10,r31,888
	ctx.r10.s64 = r31.s64 + 888;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82671110:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82671110
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82671110;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

__attribute__((alias("__imp__sub_8267113C"))) PPC_WEAK_FUNC(sub_8267113C);
PPC_FUNC_IMPL(__imp__sub_8267113C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82671140"))) PPC_WEAK_FUNC(sub_82671140);
PPC_FUNC_IMPL(__imp__sub_82671140) {
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
	// bl 0x8266dd48
	ctx.lr = 0x82671160;
	sub_8266DD48(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671178
	if (cr6.eq) goto loc_82671178;
	// bl 0x82130588
	ctx.lr = 0x82671174;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671178:
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

__attribute__((alias("__imp__sub_82671190"))) PPC_WEAK_FUNC(sub_82671190);
PPC_FUNC_IMPL(__imp__sub_82671190) {
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
	// bl 0x8266df30
	ctx.lr = 0x826711B0;
	sub_8266DF30(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826711c8
	if (cr6.eq) goto loc_826711C8;
	// bl 0x82130588
	ctx.lr = 0x826711C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826711C8:
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

__attribute__((alias("__imp__sub_826711E0"))) PPC_WEAK_FUNC(sub_826711E0);
PPC_FUNC_IMPL(__imp__sub_826711E0) {
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
	// bl 0x8266e348
	ctx.lr = 0x82671200;
	sub_8266E348(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671218
	if (cr6.eq) goto loc_82671218;
	// bl 0x82130588
	ctx.lr = 0x82671214;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671218:
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

__attribute__((alias("__imp__sub_82671230"))) PPC_WEAK_FUNC(sub_82671230);
PPC_FUNC_IMPL(__imp__sub_82671230) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32246
	ctx.r9.s64 = -2113273856;
	// addi r30,r31,5024
	r30.s64 = r31.s64 + 5024;
	// addi r7,r11,29148
	ctx.r7.s64 = r11.s64 + 29148;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r10,16392
	ctx.r5.s64 = ctx.r10.s64 + 16392;
	// addi r4,r9,16256
	ctx.r4.s64 = ctx.r9.s64 + 16256;
	// li r8,2
	ctx.r8.s64 = 2;
	// bl 0x82670fe0
	ctx.lr = 0x82671270;
	sub_82670FE0(ctx, base);
	// lis r8,-32246
	ctx.r8.s64 = -2113273856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r7,r8,24412
	ctx.r7.s64 = ctx.r8.s64 + 24412;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82659e28
	ctx.lr = 0x82671284;
	sub_82659E28(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,5052(r31)
	PPC_STORE_U32(r31.u32 + 5052, r11.u32);
	// sth r11,5056(r31)
	PPC_STORE_U16(r31.u32 + 5056, r11.u16);
	// sth r11,5058(r31)
	PPC_STORE_U16(r31.u32 + 5058, r11.u16);
	// stb r11,5060(r31)
	PPC_STORE_U8(r31.u32 + 5060, r11.u8);
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

__attribute__((alias("__imp__sub_826712B4"))) PPC_WEAK_FUNC(sub_826712B4);
PPC_FUNC_IMPL(__imp__sub_826712B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826712B8"))) PPC_WEAK_FUNC(sub_826712B8);
PPC_FUNC_IMPL(__imp__sub_826712B8) {
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
	ctx.lr = 0x826712C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lhz r11,5058(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5058);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826712e0
	if (cr6.eq) goto loc_826712E0;
	// lwz r3,5052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 5052);
	// bl 0x82130588
	ctx.lr = 0x826712E0;
	sub_82130588(ctx, base);
loc_826712E0:
	// lhz r11,5034(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 5034);
	// addi r30,r31,5024
	r30.s64 = r31.s64 + 5024;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826712f8
	if (cr6.eq) goto loc_826712F8;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x826712F8;
	sub_82130588(ctx, base);
loc_826712F8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x82671300;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826440a8
	ctx.lr = 0x82671308;
	sub_826440A8(ctx, base);
	// clrlwi r11,r29,31
	r11.u64 = r29.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671320
	if (cr6.eq) goto loc_82671320;
	// bl 0x82130588
	ctx.lr = 0x8267131C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671320:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82671328"))) PPC_WEAK_FUNC(sub_82671328);
PPC_FUNC_IMPL(__imp__sub_82671328) {
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
	// bl 0x8266e970
	ctx.lr = 0x82671348;
	sub_8266E970(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671360
	if (cr6.eq) goto loc_82671360;
	// bl 0x82130588
	ctx.lr = 0x8267135C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671360:
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

__attribute__((alias("__imp__sub_82671378"))) PPC_WEAK_FUNC(sub_82671378);
PPC_FUNC_IMPL(__imp__sub_82671378) {
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
	// bl 0x8266ee60
	ctx.lr = 0x82671398;
	sub_8266EE60(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826713b0
	if (cr6.eq) goto loc_826713B0;
	// bl 0x82130588
	ctx.lr = 0x826713AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826713B0:
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

__attribute__((alias("__imp__sub_826713C8"))) PPC_WEAK_FUNC(sub_826713C8);
PPC_FUNC_IMPL(__imp__sub_826713C8) {
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
	// bl 0x8266f0d8
	ctx.lr = 0x826713E8;
	sub_8266F0D8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671400
	if (cr6.eq) goto loc_82671400;
	// bl 0x82130588
	ctx.lr = 0x826713FC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671400:
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

__attribute__((alias("__imp__sub_82671418"))) PPC_WEAK_FUNC(sub_82671418);
PPC_FUNC_IMPL(__imp__sub_82671418) {
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
	// li r10,10
	ctx.r10.s64 = 10;
	// addi r11,r31,4568
	r11.s64 = r31.s64 + 4568;
	// addi r9,r31,10272
	ctx.r9.s64 = r31.s64 + 10272;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r4,10844(r31)
	PPC_STORE_U32(r31.u32 + 10844, ctx.r4.u32);
	// addi r8,r31,848
	ctx.r8.s64 = r31.s64 + 848;
	// stw r11,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, r11.u32);
	// addi r11,r31,10840
	r11.s64 = r31.s64 + 10840;
	// stw r10,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, ctx.r10.u32);
	// stw r11,4564(r31)
	PPC_STORE_U32(r31.u32 + 4564, r11.u32);
	// stw r9,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, ctx.r9.u32);
	// stw r7,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, ctx.r7.u32);
	// stw r11,10268(r31)
	PPC_STORE_U32(r31.u32 + 10268, r11.u32);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r6,852(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r11,r6,2
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82671494
	if (cr6.eq) goto loc_82671494;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82671480:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82671480
	if (!cr6.eq) goto loc_82671480;
loc_82671494:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
	// stw r9,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r9.u32);
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826714C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,4516(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826714e0
	if (cr6.eq) goto loc_826714E0;
	// bl 0x8266f660
	ctx.lr = 0x826714DC;
	sub_8266F660(ctx, base);
	// b 0x826714e4
	goto loc_826714E4;
loc_826714E0:
	// bl 0x8266b168
	ctx.lr = 0x826714E4;
	sub_8266B168(ctx, base);
loc_826714E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b1f8
	ctx.lr = 0x826714EC;
	sub_8266B1F8(ctx, base);
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

__attribute__((alias("__imp__sub_82671500"))) PPC_WEAK_FUNC(sub_82671500);
PPC_FUNC_IMPL(__imp__sub_82671500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82671508;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x82671528;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267153C;
	sub_82388580(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8267154C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82671554;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671568;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671578;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82671580;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82671e00
	if (!cr6.gt) goto loc_82671E00;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x826715B8;
	sub_8221D6A8(ctx, base);
	// addi r11,r30,-55
	r11.s64 = r30.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82671de8
	if (cr6.gt) goto loc_82671DE8;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,5596
	r12.s64 = r12.s64 + 5596;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826717B0;
	case 1:
		goto loc_82671DC8;
	case 2:
		goto loc_82671BA0;
	case 3:
		goto loc_82671C98;
	case 4:
		goto loc_82671DE8;
	case 5:
		goto loc_82671600;
	case 6:
		goto loc_826716D8;
	case 7:
		goto loc_826718A0;
	case 8:
		goto loc_82671984;
	default:
		__builtin_unreachable();
	}
	// lwz r19,6064(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6064);
	// lwz r19,7624(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7624);
	// lwz r19,7072(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7072);
	// lwz r19,7320(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7320);
	// lwz r19,7656(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 7656);
	// lwz r19,5632(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 5632);
	// lwz r19,5848(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 5848);
	// lwz r19,6304(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6304);
	// lwz r19,6532(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 6532);
loc_82671600:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8267160C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826716c8
	if (cr6.eq) goto loc_826716C8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x8267160c
	if (cr6.lt) goto loc_8267160C;
	// li r11,1
	r11.s64 = 1;
loc_8267162C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82671640:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826716d0
	if (cr6.eq) goto loc_826716D0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671640
	if (cr6.lt) goto loc_82671640;
	// li r11,1
	r11.s64 = 1;
loc_82671660:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671678;
	sub_821E6800(ctx, base);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// ble cr6,0x82671694
	if (!cr6.gt) goto loc_82671694;
	// li r11,7
	r11.s64 = 7;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
loc_82671694:
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x8266aa70
	ctx.lr = 0x826716A4;
	sub_8266AA70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x826716B0;
	sub_82671418(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826716C8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x8267162c
	goto loc_8267162C;
loc_826716D0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671660
	goto loc_82671660;
loc_826716D8:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_826716E4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826717a0
	if (cr6.eq) goto loc_826717A0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826716e4
	if (cr6.lt) goto loc_826716E4;
	// li r11,1
	r11.s64 = 1;
loc_82671704:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82671718:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826717a8
	if (cr6.eq) goto loc_826717A8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671718
	if (cr6.lt) goto loc_82671718;
	// li r11,1
	r11.s64 = 1;
loc_82671738:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671750;
	sub_821E6800(ctx, base);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bge cr6,0x8267176c
	if (!cr6.lt) goto loc_8267176C;
	// li r11,12
	r11.s64 = 12;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
loc_8267176C:
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x8266aa70
	ctx.lr = 0x8267177C;
	sub_8266AA70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x82671788;
	sub_82671418(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826717A0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671704
	goto loc_82671704;
loc_826717A8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671738
	goto loc_82671738;
loc_826717B0:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_826717BC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671890
	if (cr6.eq) goto loc_82671890;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826717bc
	if (cr6.lt) goto loc_826717BC;
	// li r11,1
	r11.s64 = 1;
loc_826717DC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826717F0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671898
	if (cr6.eq) goto loc_82671898;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826717f0
	if (cr6.lt) goto loc_826717F0;
	// li r11,1
	r11.s64 = 1;
loc_82671810:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x82671824;
	sub_82203240(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82671884
	if (!cr6.lt) goto loc_82671884;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x82671884
	if (cr6.eq) goto loc_82671884;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82671850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x8267185C;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x82671884
	if (cr6.eq) goto loc_82671884;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267186C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8267187C;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x82671884;
	sub_822734B0(ctx, base);
loc_82671884:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671890:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826717dc
	goto loc_826717DC;
loc_82671898:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671810
	goto loc_82671810;
loc_826718A0:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_826718AC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8267193c
	if (cr6.eq) goto loc_8267193C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826718ac
	if (cr6.lt) goto loc_826718AC;
	// li r11,1
	r11.s64 = 1;
loc_826718CC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826718E0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671944
	if (cr6.eq) goto loc_82671944;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826718e0
	if (cr6.lt) goto loc_826718E0;
	// li r11,1
	r11.s64 = 1;
loc_82671900:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r27,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r27.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267194c
	if (cr6.eq) goto loc_8267194C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x82671930;
	sub_8262FFE0(ctx, base);
	// stb r27,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r27.u8);
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// b 0x82671960
	goto loc_82671960;
loc_8267193C:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826718cc
	goto loc_826718CC;
loc_82671944:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671900
	goto loc_82671900;
loc_8267194C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28596
	ctx.r4.s64 = r11.s64 + 28596;
	// bl 0x8262ffe0
	ctx.lr = 0x82671958;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, ctx.r10.u8);
loc_82671960:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267196C;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x82671978;
	sub_82671418(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671984:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82671990:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671a18
	if (cr6.eq) goto loc_82671A18;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82671990
	if (cr6.lt) goto loc_82671990;
	// li r11,1
	r11.s64 = 1;
loc_826719B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// addi r29,r31,4352
	r29.s64 = r31.s64 + 4352;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826719C8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671a20
	if (cr6.eq) goto loc_82671A20;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826719c8
	if (cr6.lt) goto loc_826719C8;
	// li r11,1
	r11.s64 = 1;
loc_826719E8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82671a28
	if (!cr6.eq) goto loc_82671A28;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82671A0C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671A18:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826719b0
	goto loc_826719B0;
loc_82671A20:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826719e8
	goto loc_826719E8;
loc_82671A28:
	// lbz r11,4517(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4517);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r27,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r27.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671b58
	if (cr6.eq) goto loc_82671B58;
	// stb r27,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r27.u8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29420
	ctx.r4.s64 = r11.s64 + 29420;
	// bl 0x8262ffe0
	ctx.lr = 0x82671A50;
	sub_8262FFE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671A58;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671A68;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82671A70;
	sub_824E7110(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671A7C;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,-10240(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// addi r30,r31,4544
	r30.s64 = r31.s64 + 4544;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x8266a7b0
	ctx.lr = 0x82671A94;
	sub_8266A7B0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x82671AA0;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82272df8
	ctx.lr = 0x82671AB4;
	sub_82272DF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82671b7c
	if (cr6.eq) goto loc_82671B7C;
loc_82671AC0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82671AC8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671b2c
	if (cr6.eq) goto loc_82671B2C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671ac8
	if (cr6.lt) goto loc_82671AC8;
	// li r11,1
	r11.s64 = 1;
loc_82671AE8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82671b34
	if (!cr6.eq) goto loc_82671B34;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671b34
	if (cr6.eq) goto loc_82671B34;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671B08;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671B18;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x82671B1C;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82671B20;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82671B28;
	sub_821C91B8(ctx, base);
	// b 0x82671ac0
	goto loc_82671AC0;
loc_82671B2C:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671ae8
	goto loc_82671AE8;
loc_82671B34:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82671B4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// b 0x82671b7c
	goto loc_82671B7C;
loc_82671B58:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x82671B64;
	sub_8262FFE0(ctx, base);
	// lwz r9,4508(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// beq cr6,0x82671b7c
	if (cr6.eq) goto loc_82671B7C;
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
loc_82671B7C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671B88;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x82671B94;
	sub_82671418(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671BA0:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82671BAC:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671c88
	if (cr6.eq) goto loc_82671C88;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82671bac
	if (cr6.lt) goto loc_82671BAC;
	// li r11,1
	r11.s64 = 1;
loc_82671BCC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82671BE0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671c90
	if (cr6.eq) goto loc_82671C90;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671be0
	if (cr6.lt) goto loc_82671BE0;
	// li r11,1
	r11.s64 = 1;
loc_82671C00:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82671c7c
	if (!cr6.gt) goto loc_82671C7C;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r11.u32);
	// bge 0x82671c28
	if (!cr0.lt) goto loc_82671C28;
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
loc_82671C28:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671c48
	if (cr6.eq) goto loc_82671C48;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r11.u32);
	// bge 0x82671c48
	if (!cr0.lt) goto loc_82671C48;
	// stw r27,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r27.u32);
loc_82671C48:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671C54;
	sub_821E6800(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,29060
	ctx.r4.s64 = ctx.r10.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82671C68;
	sub_8262FFE0(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// stb r9,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r9.u8);
	// bl 0x82671418
	ctx.lr = 0x82671C7C;
	sub_82671418(ctx, base);
loc_82671C7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671C88:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671bcc
	goto loc_82671BCC;
loc_82671C90:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671c00
	goto loc_82671C00;
loc_82671C98:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82671CA4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671db8
	if (cr6.eq) goto loc_82671DB8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82671ca4
	if (cr6.lt) goto loc_82671CA4;
	// li r11,1
	r11.s64 = 1;
loc_82671CC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82671CD8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82671dc0
	if (cr6.eq) goto loc_82671DC0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82671cd8
	if (cr6.lt) goto loc_82671CD8;
	// li r11,1
	r11.s64 = 1;
loc_82671CF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e00
	if (cr6.eq) goto loc_82671E00;
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x82671c7c
	if (cr6.lt) goto loc_82671C7C;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// beq cr6,0x82671d78
	if (cr6.eq) goto loc_82671D78;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,10
	r30.s64 = r11.s64 + 10;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// bl 0x82388580
	ctx.lr = 0x82671D3C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671D4C;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x82671d78
	if (!cr6.gt) goto loc_82671D78;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82671D60;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82671D70;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// stw r10,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, ctx.r10.u32);
loc_82671D78:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82671D84;
	sub_821E6800(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r10,29060
	ctx.r4.s64 = ctx.r10.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82671D98;
	sub_8262FFE0(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// stb r9,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r9.u8);
	// bl 0x82671418
	ctx.lr = 0x82671DAC;
	sub_82671418(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671DB8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671cc4
	goto loc_82671CC4;
loc_82671DC0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82671cf8
	goto loc_82671CF8;
loc_82671DC8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82671DDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r9,-17880
	ctx.r3.s64 = ctx.r9.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x82671DE8;
	sub_821E6800(ctx, base);
loc_82671DE8:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x82671DF8;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82671E00:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82671E0C"))) PPC_WEAK_FUNC(sub_82671E0C);
PPC_FUNC_IMPL(__imp__sub_82671E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82671E10"))) PPC_WEAK_FUNC(sub_82671E10);
PPC_FUNC_IMPL(__imp__sub_82671E10) {
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
	// lhz r11,10854(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 10854);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82671e40
	if (cr6.eq) goto loc_82671E40;
	// lwz r3,10848(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 10848);
	// bl 0x82130588
	ctx.lr = 0x82671E40;
	sub_82130588(ctx, base);
loc_82671E40:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, ctx.r9.u32);
	// stw r8,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, ctx.r8.u32);
	// stw r9,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, ctx.r9.u32);
	// stw r8,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, ctx.r8.u32);
	// bl 0x8266f0d8
	ctx.lr = 0x82671E6C;
	sub_8266F0D8(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82671e84
	if (cr6.eq) goto loc_82671E84;
	// bl 0x82130588
	ctx.lr = 0x82671E80;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82671E84:
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

__attribute__((alias("__imp__sub_82671E9C"))) PPC_WEAK_FUNC(sub_82671E9C);
PPC_FUNC_IMPL(__imp__sub_82671E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82671EA0"))) PPC_WEAK_FUNC(sub_82671EA0);
PPC_FUNC_IMPL(__imp__sub_82671EA0) {
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
	ctx.lr = 0x82671EA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,351
	cr6.compare<uint32_t>(ctx.r4.u32, 351, xer);
	// blt cr6,0x82671ebc
	if (cr6.lt) goto loc_82671EBC;
	// addi r4,r4,31
	ctx.r4.s64 = ctx.r4.s64 + 31;
loc_82671EBC:
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// stw r4,10844(r31)
	PPC_STORE_U32(r31.u32 + 10844, ctx.r4.u32);
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r11,r31,10840
	r11.s64 = r31.s64 + 10840;
	// stw r10,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, ctx.r10.u32);
	// addi r9,r31,10272
	ctx.r9.s64 = r31.s64 + 10272;
	// stw r5,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, ctx.r5.u32);
	// li r28,1
	r28.s64 = 1;
	// stw r11,4564(r31)
	PPC_STORE_U32(r31.u32 + 4564, r11.u32);
	// li r29,0
	r29.s64 = 0;
	// stw r9,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, ctx.r9.u32);
	// stw r28,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, r28.u32);
	// addi r30,r31,4544
	r30.s64 = r31.s64 + 4544;
	// stw r11,10268(r31)
	PPC_STORE_U32(r31.u32 + 10268, r11.u32);
	// addi r8,r31,848
	ctx.r8.s64 = r31.s64 + 848;
	// stb r29,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r29.u8);
	// lwz r9,848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r7,852(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r11,r7,2
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82671f30
	if (cr6.eq) goto loc_82671F30;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_82671F1C:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82671f1c
	if (!cr6.eq) goto loc_82671F1C;
loc_82671F30:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r31,1180
	ctx.r9.s64 = r31.s64 + 1180;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
loc_82671F48:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82671f80
	if (cr6.eq) goto loc_82671F80;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_82671F6C:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82671f6c
	if (!cr6.eq) goto loc_82671F6C;
loc_82671F80:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,336
	ctx.r9.s64 = ctx.r9.s64 + 336;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// subf r6,r8,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// bne 0x82671f48
	if (!cr0.eq) goto loc_82671F48;
	// lwz r11,672(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82671FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,4516(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// stw r29,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, r29.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82671fe0
	if (cr6.eq) goto loc_82671FE0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266fd18
	ctx.lr = 0x82671FD0;
	sub_8266FD18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b1f8
	ctx.lr = 0x82671FD8;
	sub_8266B1F8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82671FE0:
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x82671ff0
	if (cr6.gt) goto loc_82671FF0;
	// stw r28,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r28.u32);
loc_82671FF0:
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r29,4508(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// bl 0x82388580
	ctx.lr = 0x82671FFC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r3,r31,4352
	ctx.r3.s64 = r31.s64 + 4352;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r6,-10240(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x8266a7b0
	ctx.lr = 0x82672014;
	sub_8266A7B0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x82672020;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// bl 0x82272e00
	ctx.lr = 0x82672030;
	sub_82272E00(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b1f8
	ctx.lr = 0x82672038;
	sub_8266B1F8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82672040"))) PPC_WEAK_FUNC(sub_82672040);
PPC_FUNC_IMPL(__imp__sub_82672040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82672048;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82672064;
	sub_8238EC00(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267207C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// li r26,0
	r26.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r26,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r26.u8);
	// bl 0x82388580
	ctx.lr = 0x82672098;
	sub_82388580(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826720A8;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x826720B0;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826720C4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826720D4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x826720DC;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826721e4
	if (!cr6.gt) goto loc_826721E4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x82672114;
	sub_8221D6A8(ctx, base);
	// addi r11,r30,-55
	r11.s64 = r30.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x8267296c
	if (cr6.gt) goto loc_8267296C;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,8504
	r12.s64 = r12.s64 + 8504;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826723B4;
	case 1:
		goto loc_82672428;
	case 2:
		goto loc_8267274C;
	case 3:
		goto loc_82672840;
	case 4:
		goto loc_8267296C;
	case 5:
		goto loc_8267215C;
	case 6:
		goto loc_82672298;
	case 7:
		goto loc_82672454;
	case 8:
		goto loc_82672534;
	default:
		__builtin_unreachable();
	}
	// lwz r19,9140(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9140);
	// lwz r19,9256(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9256);
	// lwz r19,10060(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 10060);
	// lwz r19,10304(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 10304);
	// lwz r19,10604(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 10604);
	// lwz r19,8540(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8540);
	// lwz r19,8856(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8856);
	// lwz r19,9300(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9300);
	// lwz r19,9524(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 9524);
loc_8267215C:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_82672164:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826721f0
	if (cr6.eq) goto loc_826721F0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672164
	if (cr6.lt) goto loc_82672164;
	// li r11,1
	r11.s64 = 1;
loc_82672184:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672198:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826721f8
	if (cr6.eq) goto loc_826721F8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672198
	if (cr6.lt) goto loc_82672198;
	// li r11,1
	r11.s64 = 1;
loc_826721B8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,10860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10860);
	// lhz r10,10852(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 10852);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82672200
	if (cr6.lt) goto loc_82672200;
loc_826721D8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x826721E4;
	sub_821E6800(ctx, base);
loc_826721E4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826721F0:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672184
	goto loc_82672184;
loc_826721F8:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826721b8
	goto loc_826721B8;
loc_82672200:
	// lwz r9,10848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10848);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,10860(r31)
	PPC_STORE_U32(r31.u32 + 10860, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10856(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r6,r11,10
	ctx.r6.s64 = r11.s64 + 10;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
	// lwz r5,788(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwz r4,36(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// addi r11,r11,-40
	r11.s64 = r11.s64 + -40;
	// srawi r10,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r10.s64 = r11.s32 >> 2;
	// addze r30,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	r30.s64 = temp.s64;
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r4,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82672258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10220(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x82672274;
	sub_8262A058(ctx, base);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lwz r3,24588(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672280;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x8267228C;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672298:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_826722A0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826723a4
	if (cr6.eq) goto loc_826723A4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826722a0
	if (cr6.lt) goto loc_826722A0;
	// li r11,1
	r11.s64 = 1;
loc_826722C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826722D4:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826723ac
	if (cr6.eq) goto loc_826723AC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826722d4
	if (cr6.lt) goto loc_826722D4;
	// li r11,1
	r11.s64 = 1;
loc_826722F4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,10860(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10860);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x826721d8
	if (cr0.lt) goto loc_826721D8;
	// lwz r9,10848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10848);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,10860(r31)
	PPC_STORE_U32(r31.u32 + 10860, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,10856(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r11,r9,r8
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// addi r6,r11,10
	ctx.r6.s64 = r11.s64 + 10;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
	// lwz r5,788(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 788);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// lwz r9,36(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 36);
	// addi r4,r11,-40
	ctx.r4.s64 = r11.s64 + -40;
	// srawi r11,r4,2
	xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	r11.s64 = ctx.r4.s32 >> 2;
	// addze r30,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	r30.s64 = temp.s64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r9,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82672364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r11,-10220(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x82672380;
	sub_8262A058(ctx, base);
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// lwz r3,24588(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267238C;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672398;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826723A4:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826722c0
	goto loc_826722C0;
loc_826723AC:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826722f4
	goto loc_826722F4;
loc_826723B4:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x826723BC;
	sub_82203240(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8267241c
	if (!cr6.lt) goto loc_8267241C;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8267241c
	if (cr6.eq) goto loc_8267241C;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826723E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x826723F4;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x8267241c
	if (cr6.eq) goto loc_8267241C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672404;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672414;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x8267241C;
	sub_822734B0(ctx, base);
loc_8267241C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672428:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267243C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r9,-17880
	ctx.r3.s64 = ctx.r9.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x82672448;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672454:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_8267245C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826724ec
	if (cr6.eq) goto loc_826724EC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x8267245c
	if (cr6.lt) goto loc_8267245C;
	// li r11,1
	r11.s64 = 1;
loc_8267247C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672490:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826724f4
	if (cr6.eq) goto loc_826724F4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672490
	if (cr6.lt) goto loc_82672490;
	// li r11,1
	r11.s64 = 1;
loc_826724B0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r26,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r26.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826724fc
	if (cr6.eq) goto loc_826724FC;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x826724E0;
	sub_8262FFE0(ctx, base);
	// stb r26,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r26.u8);
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
	// b 0x82672510
	goto loc_82672510;
loc_826724EC:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x8267247c
	goto loc_8267247C;
loc_826724F4:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826724b0
	goto loc_826724B0;
loc_826724FC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28596
	ctx.r4.s64 = r11.s64 + 28596;
	// bl 0x8262ffe0
	ctx.lr = 0x82672508;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, ctx.r10.u8);
loc_82672510:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8267251C;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672528;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672534:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_8267253C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826725c4
	if (cr6.eq) goto loc_826725C4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x8267253c
	if (cr6.lt) goto loc_8267253C;
	// li r11,1
	r11.s64 = 1;
loc_8267255C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// addi r29,r31,4352
	r29.s64 = r31.s64 + 4352;
	// mr r11,r26
	r11.u64 = r26.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82672574:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826725cc
	if (cr6.eq) goto loc_826725CC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672574
	if (cr6.lt) goto loc_82672574;
	// li r11,1
	r11.s64 = 1;
loc_82672594:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826725d4
	if (!cr6.eq) goto loc_826725D4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x826725B8;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826725C4:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x8267255c
	goto loc_8267255C;
loc_826725CC:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672594
	goto loc_82672594;
loc_826725D4:
	// lbz r11,4517(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4517);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r26,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r26.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82672704
	if (cr6.eq) goto loc_82672704;
	// stb r26,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r26.u8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29420
	ctx.r4.s64 = r11.s64 + 29420;
	// bl 0x8262ffe0
	ctx.lr = 0x826725FC;
	sub_8262FFE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672604;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672614;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8267261C;
	sub_824E7110(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672628;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,-10240(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r30,r31,4544
	r30.s64 = r31.s64 + 4544;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x8266a7b0
	ctx.lr = 0x82672640;
	sub_8266A7B0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x8267264C;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82272df8
	ctx.lr = 0x82672660;
	sub_82272DF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82672728
	if (cr6.eq) goto loc_82672728;
loc_8267266C:
	// mr r11,r26
	r11.u64 = r26.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82672674:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826726d8
	if (cr6.eq) goto loc_826726D8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672674
	if (cr6.lt) goto loc_82672674;
	// li r11,1
	r11.s64 = 1;
loc_82672694:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826726e0
	if (!cr6.eq) goto loc_826726E0;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826726e0
	if (cr6.eq) goto loc_826726E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826726B4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826726C4;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x826726C8;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x826726CC;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x826726D4;
	sub_821C91B8(ctx, base);
	// b 0x8267266c
	goto loc_8267266C;
loc_826726D8:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672694
	goto loc_82672694;
loc_826726E0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826726F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// b 0x82672728
	goto loc_82672728;
loc_82672704:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x82672710;
	sub_8262FFE0(ctx, base);
	// lwz r9,4508(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// beq cr6,0x82672728
	if (cr6.eq) goto loc_82672728;
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
loc_82672728:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672734;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672740;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8267274C:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_82672754:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672830
	if (cr6.eq) goto loc_82672830;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672754
	if (cr6.lt) goto loc_82672754;
	// li r11,1
	r11.s64 = 1;
loc_82672774:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672788:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672838
	if (cr6.eq) goto loc_82672838;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672788
	if (cr6.lt) goto loc_82672788;
	// li r11,1
	r11.s64 = 1;
loc_826727A8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82672824
	if (!cr6.gt) goto loc_82672824;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r11.u32);
	// bge 0x826727d0
	if (!cr0.lt) goto loc_826727D0;
	// stw r26,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r26.u32);
loc_826727D0:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826727f0
	if (cr6.eq) goto loc_826727F0;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r11.u32);
	// bge 0x826727f0
	if (!cr0.lt) goto loc_826727F0;
	// stw r26,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r26.u32);
loc_826727F0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82672804;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672818;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672824;
	sub_82671EA0(ctx, base);
loc_82672824:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672830:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672774
	goto loc_82672774;
loc_82672838:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x826727a8
	goto loc_826727A8;
loc_82672840:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
loc_82672848:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x8267295c
	if (cr6.eq) goto loc_8267295C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672848
	if (cr6.lt) goto loc_82672848;
	// li r11,1
	r11.s64 = 1;
loc_82672868:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// mr r11,r26
	r11.u64 = r26.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_8267287C:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672964
	if (cr6.eq) goto loc_82672964;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x8267287c
	if (cr6.lt) goto loc_8267287C;
	// li r11,1
	r11.s64 = 1;
loc_8267289C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826721e4
	if (cr6.eq) goto loc_826721E4;
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x82672824
	if (cr6.lt) goto loc_82672824;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// beq cr6,0x8267291c
	if (cr6.eq) goto loc_8267291C;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,10
	r30.s64 = r11.s64 + 10;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// bl 0x82388580
	ctx.lr = 0x826728E0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x826728F0;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x8267291c
	if (!cr6.gt) goto loc_8267291C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672904;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672914;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// stw r10,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, ctx.r10.u32);
loc_8267291C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82672930;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672944;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82672950;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_8267295C:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82672868
	goto loc_82672868;
loc_82672964:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x8267289c
	goto loc_8267289C;
loc_8267296C:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8267297C;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82672984"))) PPC_WEAK_FUNC(sub_82672984);
PPC_FUNC_IMPL(__imp__sub_82672984) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82672988"))) PPC_WEAK_FUNC(sub_82672988);
PPC_FUNC_IMPL(__imp__sub_82672988) {
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
	// bl 0x82670270
	ctx.lr = 0x826729A8;
	sub_82670270(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826729c0
	if (cr6.eq) goto loc_826729C0;
	// bl 0x82130588
	ctx.lr = 0x826729BC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826729C0:
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

__attribute__((alias("__imp__sub_826729D8"))) PPC_WEAK_FUNC(sub_826729D8);
PPC_FUNC_IMPL(__imp__sub_826729D8) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// stw r9,10840(r31)
	PPC_STORE_U32(r31.u32 + 10840, ctx.r9.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,10264(r31)
	PPC_STORE_U32(r31.u32 + 10264, ctx.r9.u32);
	// stw r8,10248(r31)
	PPC_STORE_U32(r31.u32 + 10248, ctx.r8.u32);
	// stw r9,4560(r31)
	PPC_STORE_U32(r31.u32 + 4560, ctx.r9.u32);
	// stw r8,4544(r31)
	PPC_STORE_U32(r31.u32 + 4544, ctx.r8.u32);
	// bl 0x8266f0d8
	ctx.lr = 0x82672A1C;
	sub_8266F0D8(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82672a34
	if (cr6.eq) goto loc_82672A34;
	// bl 0x82130588
	ctx.lr = 0x82672A30;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82672A34:
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

__attribute__((alias("__imp__sub_82672A4C"))) PPC_WEAK_FUNC(sub_82672A4C);
PPC_FUNC_IMPL(__imp__sub_82672A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82672A50"))) PPC_WEAK_FUNC(sub_82672A50);
PPC_FUNC_IMPL(__imp__sub_82672A50) {
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
	// li r8,10
	ctx.r8.s64 = 10;
	// addi r10,r31,4568
	ctx.r10.s64 = r31.s64 + 4568;
	// addi r11,r31,10840
	r11.s64 = r31.s64 + 10840;
	// addi r7,r31,10272
	ctx.r7.s64 = r31.s64 + 10272;
	// stw r4,10844(r31)
	PPC_STORE_U32(r31.u32 + 10844, ctx.r4.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r10,4556(r31)
	PPC_STORE_U32(r31.u32 + 4556, ctx.r10.u32);
	// li r30,0
	r30.s64 = 0;
	// stw r8,4552(r31)
	PPC_STORE_U32(r31.u32 + 4552, ctx.r8.u32);
	// addi r9,r31,848
	ctx.r9.s64 = r31.s64 + 848;
	// stw r11,4564(r31)
	PPC_STORE_U32(r31.u32 + 4564, r11.u32);
	// stw r7,10260(r31)
	PPC_STORE_U32(r31.u32 + 10260, ctx.r7.u32);
	// stw r6,10256(r31)
	PPC_STORE_U32(r31.u32 + 10256, ctx.r6.u32);
	// stw r11,10268(r31)
	PPC_STORE_U32(r31.u32 + 10268, r11.u32);
	// stb r30,4524(r31)
	PPC_STORE_U8(r31.u32 + 4524, r30.u8);
	// lwz r8,848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r5,852(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// rotlwi r11,r5,2
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x82672ad8
	if (cr6.eq) goto loc_82672AD8;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_82672AC4:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82672ac4
	if (!cr6.eq) goto loc_82672AC4;
loc_82672AD8:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// srawi r8,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r8.s64 = r11.s32 >> 2;
	// li r4,0
	ctx.r4.s64 = 0;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r7.u16);
	// lwz r5,672(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 672);
	// lwz r11,648(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 648);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82672B04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// stw r30,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82672b20
	if (cr6.eq) goto loc_82672B20;
	// bl 0x8266f660
	ctx.lr = 0x82672B1C;
	sub_8266F660(ctx, base);
	// b 0x82672b24
	goto loc_82672B24;
loc_82672B20:
	// bl 0x8266b168
	ctx.lr = 0x82672B24;
	sub_8266B168(ctx, base);
loc_82672B24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266b1f8
	ctx.lr = 0x82672B2C;
	sub_8266B1F8(ctx, base);
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

__attribute__((alias("__imp__sub_82672B44"))) PPC_WEAK_FUNC(sub_82672B44);
PPC_FUNC_IMPL(__imp__sub_82672B44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82672B48"))) PPC_WEAK_FUNC(sub_82672B48);
PPC_FUNC_IMPL(__imp__sub_82672B48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x82672B50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	ctx.lr = 0x82672B70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672B84;
	sub_82388580(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82672B94;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82672B9C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672BB0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672BC0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82672BC8;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,4520(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4520);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826733d8
	if (!cr6.gt) goto loc_826733D8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x82672C00;
	sub_8221D6A8(ctx, base);
	// addi r11,r30,-55
	r11.s64 = r30.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x826733c0
	if (cr6.gt) goto loc_826733C0;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,11300
	r12.s64 = r12.s64 + 11300;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82672DF8;
	case 1:
		goto loc_82672E6C;
	case 2:
		goto loc_82673198;
	case 3:
		goto loc_82673290;
	case 4:
		goto loc_826733C0;
	case 5:
		goto loc_82672C48;
	case 6:
		goto loc_82672D20;
	case 7:
		goto loc_82672E98;
	case 8:
		goto loc_82672F7C;
	default:
		__builtin_unreachable();
	}
	// lwz r19,11768(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11768);
	// lwz r19,11884(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11884);
	// lwz r19,12696(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12696);
	// lwz r19,12944(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12944);
	// lwz r19,13248(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13248);
	// lwz r19,11336(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11336);
	// lwz r19,11552(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11552);
	// lwz r19,11928(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11928);
	// lwz r19,12156(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 12156);
loc_82672C48:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82672C54:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672d10
	if (cr6.eq) goto loc_82672D10;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672c54
	if (cr6.lt) goto loc_82672C54;
	// li r11,1
	r11.s64 = 1;
loc_82672C74:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672C88:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672d18
	if (cr6.eq) goto loc_82672D18;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672c88
	if (cr6.lt) goto loc_82672C88;
	// li r11,1
	r11.s64 = 1;
loc_82672CA8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672CC0;
	sub_821E6800(ctx, base);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// cmpwi cr6,r11,6
	cr6.compare<int32_t>(r11.s32, 6, xer);
	// ble cr6,0x82672cdc
	if (!cr6.gt) goto loc_82672CDC;
	// li r11,2
	r11.s64 = 2;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
loc_82672CDC:
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x8266ab58
	ctx.lr = 0x82672CEC;
	sub_8266AB58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82672CF8;
	sub_82672A50(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672D10:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672c74
	goto loc_82672C74;
loc_82672D18:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672ca8
	goto loc_82672CA8;
loc_82672D20:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82672D2C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672de8
	if (cr6.eq) goto loc_82672DE8;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672d2c
	if (cr6.lt) goto loc_82672D2C;
	// li r11,1
	r11.s64 = 1;
loc_82672D4C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672D60:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672df0
	if (cr6.eq) goto loc_82672DF0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672d60
	if (cr6.lt) goto loc_82672D60;
	// li r11,1
	r11.s64 = 1;
loc_82672D80:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672D98;
	sub_821E6800(ctx, base);
	// lwz r11,4528(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bge cr6,0x82672db4
	if (!cr6.lt) goto loc_82672DB4;
	// li r11,6
	r11.s64 = 6;
	// stw r11,4528(r31)
	PPC_STORE_U32(r31.u32 + 4528, r11.u32);
loc_82672DB4:
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x8266ab58
	ctx.lr = 0x82672DC4;
	sub_8266AB58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82672DD0;
	sub_82672A50(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,4520(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4520, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672DE8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672d4c
	goto loc_82672D4C;
loc_82672DF0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672d80
	goto loc_82672D80;
loc_82672DF8:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x82672E00;
	sub_82203240(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82672e60
	if (!cr6.lt) goto loc_82672E60;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x82672e60
	if (cr6.eq) goto loc_82672E60;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82672E2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x82672E38;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x82672e60
	if (cr6.eq) goto loc_82672E60;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82672E48;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82672E58;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x82672E60;
	sub_822734B0(ctx, base);
loc_82672E60:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672E6C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82672E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r3,r9,-17880
	ctx.r3.s64 = ctx.r9.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x82672E8C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672E98:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82672EA4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672f34
	if (cr6.eq) goto loc_82672F34;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672ea4
	if (cr6.lt) goto loc_82672EA4;
	// li r11,1
	r11.s64 = 1;
loc_82672EC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_82672ED8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82672f3c
	if (cr6.eq) goto loc_82672F3C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672ed8
	if (cr6.lt) goto loc_82672ED8;
	// li r11,1
	r11.s64 = 1;
loc_82672EF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r27,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r27.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82672f44
	if (cr6.eq) goto loc_82672F44;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x82672F28;
	sub_8262FFE0(ctx, base);
	// stb r27,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r27.u8);
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
	// b 0x82672f58
	goto loc_82672F58;
loc_82672F34:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672ec4
	goto loc_82672EC4;
loc_82672F3C:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672ef8
	goto loc_82672EF8;
loc_82672F44:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28596
	ctx.r4.s64 = r11.s64 + 28596;
	// bl 0x8262ffe0
	ctx.lr = 0x82672F50;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, ctx.r10.u8);
loc_82672F58:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82672F64;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82672F70;
	sub_82672A50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82672F7C:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_82672F88:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673010
	if (cr6.eq) goto loc_82673010;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x82672f88
	if (cr6.lt) goto loc_82672F88;
	// li r11,1
	r11.s64 = 1;
loc_82672FA8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// addi r29,r31,4352
	r29.s64 = r31.s64 + 4352;
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_82672FC0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673018
	if (cr6.eq) goto loc_82673018;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82672fc0
	if (cr6.lt) goto loc_82672FC0;
	// li r11,1
	r11.s64 = 1;
loc_82672FE0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82673020
	if (!cr6.eq) goto loc_82673020;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82673004;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673010:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672fa8
	goto loc_82672FA8;
loc_82673018:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x82672fe0
	goto loc_82672FE0;
loc_82673020:
	// lbz r11,4517(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4517);
	// li r5,6
	ctx.r5.s64 = 6;
	// stb r27,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r27.u8);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673150
	if (cr6.eq) goto loc_82673150;
	// stb r27,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r27.u8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29420
	ctx.r4.s64 = r11.s64 + 29420;
	// bl 0x8262ffe0
	ctx.lr = 0x82673048;
	sub_8262FFE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673050;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673060;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82673068;
	sub_824E7110(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673074;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,-10240(r28)
	ctx.r6.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// addi r30,r31,4544
	r30.s64 = r31.s64 + 4544;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x8266a7b0
	ctx.lr = 0x8267308C;
	sub_8266A7B0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x82673098;
	sub_82270170(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82272df8
	ctx.lr = 0x826730AC;
	sub_82272DF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82673174
	if (cr6.eq) goto loc_82673174;
loc_826730B8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_826730C0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673124
	if (cr6.eq) goto loc_82673124;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826730c0
	if (cr6.lt) goto loc_826730C0;
	// li r11,1
	r11.s64 = 1;
loc_826730E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267312c
	if (!cr6.eq) goto loc_8267312C;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267312c
	if (cr6.eq) goto loc_8267312C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673100;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673110;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x82673114;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82673118;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82673120;
	sub_821C91B8(ctx, base);
	// b 0x826730b8
	goto loc_826730B8;
loc_82673124:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826730e0
	goto loc_826730E0;
loc_8267312C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// b 0x82673174
	goto loc_82673174;
loc_82673150:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// bl 0x8262ffe0
	ctx.lr = 0x8267315C;
	sub_8262FFE0(ctx, base);
	// lwz r9,4508(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// beq cr6,0x82673174
	if (cr6.eq) goto loc_82673174;
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
loc_82673174:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673180;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x8267318C;
	sub_82672A50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673198:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_826731A4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673280
	if (cr6.eq) goto loc_82673280;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x826731a4
	if (cr6.lt) goto loc_826731A4;
	// li r11,1
	r11.s64 = 1;
loc_826731C4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826731D8:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673288
	if (cr6.eq) goto loc_82673288;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826731d8
	if (cr6.lt) goto loc_826731D8;
	// li r11,1
	r11.s64 = 1;
loc_826731F8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82673274
	if (!cr6.gt) goto loc_82673274;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r11.u32);
	// bge 0x82673220
	if (!cr0.lt) goto loc_82673220;
	// stw r27,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r27.u32);
loc_82673220:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673240
	if (cr6.eq) goto loc_82673240;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r11.u32);
	// bge 0x82673240
	if (!cr0.lt) goto loc_82673240;
	// stw r27,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r27.u32);
loc_82673240:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82673254;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673268;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82673274;
	sub_82672A50(ctx, base);
loc_82673274:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673280:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826731c4
	goto loc_826731C4;
loc_82673288:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826731f8
	goto loc_826731F8;
loc_82673290:
	// li r27,0
	r27.s64 = 0;
	// addi r11,r31,4428
	r11.s64 = r31.s64 + 4428;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
loc_8267329C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826733b0
	if (cr6.eq) goto loc_826733B0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// cmpwi cr6,r10,8
	cr6.compare<int32_t>(ctx.r10.s32, 8, xer);
	// blt cr6,0x8267329c
	if (cr6.lt) goto loc_8267329C;
	// li r11,1
	r11.s64 = 1;
loc_826732BC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// mr r11,r27
	r11.u64 = r27.u64;
	// addi r10,r31,4352
	ctx.r10.s64 = r31.s64 + 4352;
loc_826732D0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x826733b8
	if (cr6.eq) goto loc_826733B8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826732d0
	if (cr6.lt) goto loc_826732D0;
	// li r11,1
	r11.s64 = 1;
loc_826732F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826733d8
	if (cr6.eq) goto loc_826733D8;
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x82673274
	if (cr6.lt) goto loc_82673274;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// beq cr6,0x82673370
	if (cr6.eq) goto loc_82673370;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,10
	r30.s64 = r11.s64 + 10;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// bl 0x82388580
	ctx.lr = 0x82673334;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673344;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x82673370
	if (!cr6.gt) goto loc_82673370;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673358;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673368;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// stw r10,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, ctx.r10.u32);
loc_82673370:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r11,29060
	ctx.r4.s64 = r11.s64 + 29060;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82673384;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673398;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x826733A4;
	sub_82672A50(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826733B0:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826732bc
	goto loc_826732BC;
loc_826733B8:
	// mr r11,r27
	r11.u64 = r27.u64;
	// b 0x826732f0
	goto loc_826732F0;
loc_826733C0:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x826733D0;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826733D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826733E4"))) PPC_WEAK_FUNC(sub_826733E4);
PPC_FUNC_IMPL(__imp__sub_826733E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826733E8"))) PPC_WEAK_FUNC(sub_826733E8);
PPC_FUNC_IMPL(__imp__sub_826733E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	ctx.lr = 0x826733F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673410;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82673428
	if (!cr6.eq) goto loc_82673428;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673428:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673430;
	sub_82388580(ctx, base);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82673440;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82673448;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267358c
	if (cr6.eq) goto loc_8267358C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267345C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8267346C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82673474;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8267358c
	if (cr6.eq) goto loc_8267358C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x82673498;
	sub_8221D6A8(ctx, base);
	// addi r11,r29,-55
	r11.s64 = r29.s64 + -55;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x826738e4
	if (cr6.gt) goto loc_826738E4;
	// lis r12,-32153
	r12.s64 = -2107179008;
	// addi r12,r12,13500
	r12.s64 = r12.s64 + 13500;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826734E0;
	case 1:
		goto loc_82673554;
	case 2:
		goto loc_826737A8;
	case 3:
		goto loc_82673828;
	case 4:
		goto loc_826738E4;
	case 5:
		goto loc_8267358C;
	case 6:
		goto loc_8267358C;
	case 7:
		goto loc_82673598;
	case 8:
		goto loc_82673604;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13536(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13536);
	// lwz r19,13652(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13652);
	// lwz r19,14248(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14248);
	// lwz r19,14376(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14376);
	// lwz r19,14564(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 14564);
	// lwz r19,13708(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13708);
	// lwz r19,13708(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13708);
	// lwz r19,13720(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13720);
	// lwz r19,13828(r7)
	r19.u64 = PPC_LOAD_U32(ctx.r7.u32 + 13828);
loc_826734E0:
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// bl 0x82203240
	ctx.lr = 0x826734E8;
	sub_82203240(ctx, base);
	// lwz r11,4548(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4548);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x8267358c
	if (!cr6.lt) goto loc_8267358C;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8267358c
	if (cr6.eq) goto loc_8267358C;
	// lwz r10,4544(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4544);
	// addi r3,r31,4544
	ctx.r3.s64 = r31.s64 + 4544;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82673514;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r31,r3,24
	r31.s64 = ctx.r3.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824f92f0
	ctx.lr = 0x82673520;
	sub_824F92F0(ctx, base);
	// cmpldi cr6,r3,0
	cr6.compare<uint64_t>(ctx.r3.u64, 0, xer);
	// beq cr6,0x8267358c
	if (cr6.eq) goto loc_8267358C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673530;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673540;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x82673548;
	sub_822734B0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673554:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,4
	ctx.r10.s64 = 262144;
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r8,r10,64594
	ctx.r8.u64 = ctx.r10.u64 | 64594;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stbx r9,r7,r8
	PPC_STORE_U8(ctx.r7.u32 + ctx.r8.u32, ctx.r9.u8);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,736(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 736);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82673580;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// addi r3,r4,-17880
	ctx.r3.s64 = ctx.r4.s64 + -17880;
	// bl 0x821e6800
	ctx.lr = 0x8267358C;
	sub_821E6800(ctx, base);
loc_8267358C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673598:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// li r29,0
	r29.s64 = 0;
	// li r5,5
	ctx.r5.s64 = 5;
	// stb r29,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r29.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// beq cr6,0x826735cc
	if (cr6.eq) goto loc_826735CC;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28180
	ctx.r4.s64 = r11.s64 + 28180;
	// bl 0x8262ffe0
	ctx.lr = 0x826735C0;
	sub_8262FFE0(ctx, base);
	// stb r29,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r29.u8);
	// stw r29,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r29.u32);
	// b 0x826735e0
	goto loc_826735E0;
loc_826735CC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28220
	ctx.r4.s64 = r11.s64 + 28220;
	// bl 0x8262ffe0
	ctx.lr = 0x826735D8;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, ctx.r10.u8);
loc_826735E0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826735EC;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x826735F8;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673604:
	// lwz r11,10252(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 10252);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82673628
	if (!cr6.eq) goto loc_82673628;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8267361C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673628:
	// lbz r11,4517(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4517);
	// li r29,0
	r29.s64 = 0;
	// li r5,5
	ctx.r5.s64 = 5;
	// stb r29,4516(r31)
	PPC_STORE_U8(r31.u32 + 4516, r29.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// beq cr6,0x82673760
	if (cr6.eq) goto loc_82673760;
	// stb r29,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, r29.u8);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28444
	ctx.r4.s64 = r11.s64 + 28444;
	// bl 0x8262ffe0
	ctx.lr = 0x82673654;
	sub_8262FFE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8267365C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8267366C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82673674;
	sub_824E7110(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673680;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r30,r31,4352
	r30.s64 = r31.s64 + 4352;
	// lwz r6,-10240(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// addi r28,r31,4544
	r28.s64 = r31.s64 + 4544;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x8266a7b0
	ctx.lr = 0x8267369C;
	sub_8266A7B0(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x82270170
	ctx.lr = 0x826736A8;
	sub_82270170(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82272df8
	ctx.lr = 0x826736BC;
	sub_82272DF8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82673784
	if (cr6.eq) goto loc_82673784;
loc_826736C8:
	// mr r11,r29
	r11.u64 = r29.u64;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_826736D0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673734
	if (cr6.eq) goto loc_82673734;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x826736d0
	if (cr6.lt) goto loc_826736D0;
	// li r11,1
	r11.s64 = 1;
loc_826736F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267373c
	if (!cr6.eq) goto loc_8267373C;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267373c
	if (cr6.eq) goto loc_8267373C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673710;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673720;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x82673724;
	sub_82274B80(ctx, base);
	// bl 0x82130000
	ctx.lr = 0x82673728;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x821c91b8
	ctx.lr = 0x82673730;
	sub_821C91B8(ctx, base);
	// b 0x826736c8
	goto loc_826736C8;
loc_82673734:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x826736f0
	goto loc_826736F0;
loc_8267373C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673754;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// b 0x82673784
	goto loc_82673784;
loc_82673760:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r4,r11,28180
	ctx.r4.s64 = r11.s64 + 28180;
	// bl 0x8262ffe0
	ctx.lr = 0x8267376C;
	sub_8262FFE0(ctx, base);
	// lwz r9,4508(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// beq cr6,0x82673784
	if (cr6.eq) goto loc_82673784;
	// stw r29,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r29.u32);
loc_82673784:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673790;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x8267379C;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826737A8:
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8267358c
	if (!cr6.gt) goto loc_8267358C;
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r29,0
	r29.s64 = 0;
	// stw r11,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r11.u32);
	// bge 0x826737c8
	if (!cr0.lt) goto loc_826737C8;
	// stw r29,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, r29.u32);
loc_826737C8:
	// lbz r11,4516(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826737e8
	if (cr6.eq) goto loc_826737E8;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// addic. r11,r11,-10
	xer.ca = r11.u32 > 9;
	r11.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r11.u32);
	// bge 0x826737e8
	if (!cr0.lt) goto loc_826737E8;
	// stw r29,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r29.u32);
loc_826737E8:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,28180
	ctx.r4.s64 = r11.s64 + 28180;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x826737FC;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82673810;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x8267381C;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82673828:
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// blt cr6,0x8267358c
	if (cr6.lt) goto loc_8267358C;
	// lwz r11,4508(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4508);
	// lbz r10,4516(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4516);
	// addi r9,r11,10
	ctx.r9.s64 = r11.s64 + 10;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,4508(r31)
	PPC_STORE_U32(r31.u32 + 4508, ctx.r9.u32);
	// beq cr6,0x826738a4
	if (cr6.eq) goto loc_826738A4;
	// lwz r11,4512(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r11,10
	r30.s64 = r11.s64 + 10;
	// stw r30,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, r30.u32);
	// bl 0x82388580
	ctx.lr = 0x82673860;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673870;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// ble cr6,0x826738a4
	if (!cr6.gt) goto loc_826738A4;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,4512(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4512);
	// bl 0x82388580
	ctx.lr = 0x82673888;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673898;
	sub_82270170(ctx, base);
	// lwz r11,308(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// stw r10,4512(r31)
	PPC_STORE_U32(r31.u32 + 4512, ctx.r10.u32);
loc_826738A4:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,5
	ctx.r5.s64 = 5;
	// addi r4,r11,28180
	ctx.r4.s64 = r11.s64 + 28180;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x826738B8;
	sub_8262FFE0(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// stb r10,4517(r31)
	PPC_STORE_U8(r31.u32 + 4517, ctx.r10.u8);
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826738CC;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x826738D8;
	sub_82671EA0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826738E4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x826738F4;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_826738FC"))) PPC_WEAK_FUNC(sub_826738FC);
PPC_FUNC_IMPL(__imp__sub_826738FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673900"))) PPC_WEAK_FUNC(sub_82673900);
PPC_FUNC_IMPL(__imp__sub_82673900) {
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
	// bl 0x8266ca28
	ctx.lr = 0x82673918;
	sub_8266CA28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671418
	ctx.lr = 0x82673924;
	sub_82671418(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266caf8
	ctx.lr = 0x82673930;
	sub_8266CAF8(ctx, base);
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

__attribute__((alias("__imp__sub_82673944"))) PPC_WEAK_FUNC(sub_82673944);
PPC_FUNC_IMPL(__imp__sub_82673944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673948"))) PPC_WEAK_FUNC(sub_82673948);
PPC_FUNC_IMPL(__imp__sub_82673948) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
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
	// bl 0x8266ca28
	ctx.lr = 0x82673960;
	sub_8266CA28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x8267396C;
	sub_82671EA0(ctx, base);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// lwz r9,10856(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r8,r10,-40
	ctx.r8.s64 = ctx.r10.s64 + -40;
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x8267399C;
	sub_8262A058(ctx, base);
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

__attribute__((alias("__imp__sub_826739B0"))) PPC_WEAK_FUNC(sub_826739B0);
PPC_FUNC_IMPL(__imp__sub_826739B0) {
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
	ctx.lr = 0x826739B8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
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
	ctx.lr = 0x826739D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82673c84
	if (cr6.eq) goto loc_82673C84;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826739E4;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x826739F4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x826739FC;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673a34
	if (cr6.eq) goto loc_82673A34;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82673A10;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82673A20;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82673A28;
	sub_824E70E0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82673a64
	if (!cr6.eq) goto loc_82673A64;
loc_82673A34:
	// lbz r11,10600(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 10600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82673a64
	if (!cr6.eq) goto loc_82673A64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r4,r10,21160
	ctx.r4.s64 = ctx.r10.s64 + 21160;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x82289ab0
	ctx.lr = 0x82673A5C;
	sub_82289AB0(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r8,10600(r31)
	PPC_STORE_U8(r31.u32 + 10600, ctx.r8.u8);
loc_82673A64:
	// addi r30,r31,4352
	r30.s64 = r31.s64 + 4352;
	// li r29,0
	r29.s64 = 0;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82673A74:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// beq cr6,0x82673c8c
	if (cr6.eq) goto loc_82673C8C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82673a74
	if (cr6.lt) goto loc_82673A74;
	// li r11,1
	r11.s64 = 1;
loc_82673A94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673c84
	if (cr6.eq) goto loc_82673C84;
	// lbz r11,4425(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4425);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82673c84
	if (cr6.eq) goto loc_82673C84;
	// lwz r11,8224(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8224);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r9,8228(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8228);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lwz r7,8232(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8232);
	// addi r28,r10,19036
	r28.s64 = ctx.r10.s64 + 19036;
	// lwz r6,8240(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8240);
	// addi r27,r8,-18644
	r27.s64 = ctx.r8.s64 + -18644;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// bl 0x8266d400
	ctx.lr = 0x82673AF4;
	sub_8266D400(ctx, base);
	// lwz r11,8820(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8820);
	// lwz r10,8824(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8824);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r9,8828(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8828);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r8,8836(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8836);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// bl 0x8266d400
	ctx.lr = 0x82673B2C;
	sub_8266D400(ctx, base);
	// lwz r7,9412(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 9412);
	// lwz r6,9416(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 9416);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,9420(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 9420);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,9428(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 9428);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// bl 0x8266d400
	ctx.lr = 0x82673B64;
	sub_8266D400(ctx, base);
	// lwz r9,10004(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10004);
	// lwz r8,10008(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 10008);
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r7,10012(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 10012);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,10020(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 10020);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r28.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r6,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r6.u32);
	// bl 0x8266d400
	ctx.lr = 0x82673B9C;
	sub_8266D400(ctx, base);
	// lhz r3,852(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// rotlwi r9,r3,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r3.u32, 2);
	// addi r11,r3,1
	r11.s64 = ctx.r3.s64 + 1;
	// addi r5,r31,6848
	ctx.r5.s64 = r31.s64 + 6848;
	// sth r11,852(r31)
	PPC_STORE_U16(r31.u32 + 852, r11.u16);
	// addi r4,r31,7184
	ctx.r4.s64 = r31.s64 + 7184;
	// addi r8,r31,7520
	ctx.r8.s64 = r31.s64 + 7520;
	// stwx r5,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r5.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r7.u32);
	// addi r7,r31,7856
	ctx.r7.s64 = r31.s64 + 7856;
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r6,852(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// rotlwi r9,r6,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r5.u16);
	// stwx r4,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r4.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r6.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r5,852(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// rotlwi r9,r5,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, ctx.r10.u32);
	// lwz r10,848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// lhz r8,852(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// rotlwi r11,r8,2
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r6.u16);
	// stwx r7,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r7.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,4504(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4504);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r10,184(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	// stw r11,4504(r31)
	PPC_STORE_U32(r31.u32 + 4504, r11.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673C60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r11,r30,64
	r11.s64 = r30.s64 + 64;
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82673C70:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82673c70
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82673C70;
	// stb r29,73(r30)
	PPC_STORE_U8(r30.u32 + 73, r29.u8);
	// stb r29,72(r30)
	PPC_STORE_U8(r30.u32 + 72, r29.u8);
loc_82673C84:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82673C8C:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x82673a94
	goto loc_82673A94;
}

__attribute__((alias("__imp__sub_82673C94"))) PPC_WEAK_FUNC(sub_82673C94);
PPC_FUNC_IMPL(__imp__sub_82673C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673C98"))) PPC_WEAK_FUNC(sub_82673C98);
PPC_FUNC_IMPL(__imp__sub_82673C98) {
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
	// bl 0x8266ca28
	ctx.lr = 0x82673CB0;
	sub_8266CA28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82672a50
	ctx.lr = 0x82673CBC;
	sub_82672A50(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8266d7b8
	ctx.lr = 0x82673CC8;
	sub_8266D7B8(ctx, base);
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

__attribute__((alias("__imp__sub_82673CDC"))) PPC_WEAK_FUNC(sub_82673CDC);
PPC_FUNC_IMPL(__imp__sub_82673CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673CE0"))) PPC_WEAK_FUNC(sub_82673CE0);
PPC_FUNC_IMPL(__imp__sub_82673CE0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8266ca28
	ctx.lr = 0x82673CFC;
	sub_8266CA28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,4528(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// bl 0x82671ea0
	ctx.lr = 0x82673D08;
	sub_82671EA0(ctx, base);
	// lwz r10,4528(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4528);
	// lwz r9,10856(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 10856);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// subf r10,r9,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r9.s64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r8,r10,-40
	ctx.r8.s64 = ctx.r10.s64 + -40;
	// srawi r7,r8,2
	xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 2;
	// addze r4,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r4.s64 = temp.s64;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r3,368(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// bl 0x8262a058
	ctx.lr = 0x82673D38;
	sub_8262A058(ctx, base);
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// addi r30,r31,256
	r30.s64 = r31.s64 + 256;
	// addi r4,r6,28180
	ctx.r4.s64 = ctx.r6.s64 + 28180;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,5
	ctx.r5.s64 = 5;
	// bl 0x8262ffe0
	ctx.lr = 0x82673D50;
	sub_8262FFE0(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r4,r4,-10256
	ctx.r4.s64 = ctx.r4.s64 + -10256;
	// lwz r3,-10236(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82673D64;
	sub_821F9FB8(ctx, base);
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,196(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// lwz r4,56(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82673D80;
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

__attribute__((alias("__imp__sub_82673D98"))) PPC_WEAK_FUNC(sub_82673D98);
PPC_FUNC_IMPL(__imp__sub_82673D98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f1,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// stfs f0,992(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 992, temp.u32);
	// stfs f1,996(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 996, temp.u32);
	// lwz r7,1740(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r6,r7,0,14,14
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32237
	r11.s64 = -2112684032;
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
	// li r4,17
	ctx.r4.s64 = 17;
	// b 0x821ed368
	sub_821ED368(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82673DF0"))) PPC_WEAK_FUNC(sub_82673DF0);
PPC_FUNC_IMPL(__imp__sub_82673DF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82673DF4"))) PPC_WEAK_FUNC(sub_82673DF4);
PPC_FUNC_IMPL(__imp__sub_82673DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673DF8"))) PPC_WEAK_FUNC(sub_82673DF8);
PPC_FUNC_IMPL(__imp__sub_82673DF8) {
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
	ctx.lr = 0x82673E24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82673e40
	if (!cr6.eq) goto loc_82673E40;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207190
	ctx.lr = 0x82673E40;
	sub_82207190(ctx, base);
loc_82673E40:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x82673E4C;
	sub_82630318(ctx, base);
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

__attribute__((alias("__imp__sub_82673E64"))) PPC_WEAK_FUNC(sub_82673E64);
PPC_FUNC_IMPL(__imp__sub_82673E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673E68"))) PPC_WEAK_FUNC(sub_82673E68);
PPC_FUNC_IMPL(__imp__sub_82673E68) {
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
	// bl 0x82653670
	ctx.lr = 0x82673E78;
	sub_82653670(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82673E80;
	sub_82216138(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,14,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82673ea4
	if (cr6.eq) goto loc_82673EA4;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,17
	ctx.r4.s64 = 17;
	// bl 0x821ec468
	ctx.lr = 0x82673EA4;
	sub_821EC468(ctx, base);
loc_82673EA4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82673EB4"))) PPC_WEAK_FUNC(sub_82673EB4);
PPC_FUNC_IMPL(__imp__sub_82673EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673EB8"))) PPC_WEAK_FUNC(sub_82673EB8);
PPC_FUNC_IMPL(__imp__sub_82673EB8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x82653920
	ctx.lr = 0x82673EDC;
	sub_82653920(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673EF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82673f60
	if (cr6.eq) goto loc_82673F60;
	// lfs f0,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 992);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82673f48
	if (!cr6.gt) goto loc_82673F48;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x82673f40
	if (!cr6.lt) goto loc_82673F40;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x82673F38;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// b 0x82673f4c
	goto loc_82673F4C;
loc_82673F40:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x82673f4c
	goto loc_82673F4C;
loc_82673F48:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_82673F4C:
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// stfs f0,996(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x82673f60
	if (cr6.gt) goto loc_82673F60;
	// stfs f31,996(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
loc_82673F60:
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

__attribute__((alias("__imp__sub_82673F7C"))) PPC_WEAK_FUNC(sub_82673F7C);
PPC_FUNC_IMPL(__imp__sub_82673F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673F80"))) PPC_WEAK_FUNC(sub_82673F80);
PPC_FUNC_IMPL(__imp__sub_82673F80) {
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
	// bl 0x822166e8
	ctx.lr = 0x82673F98;
	sub_822166E8(ctx, base);
	// li r3,43
	ctx.r3.s64 = 43;
	// bl 0x82216138
	ctx.lr = 0x82673FA0;
	sub_82216138(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r9.u32);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
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

__attribute__((alias("__imp__sub_82673FD4"))) PPC_WEAK_FUNC(sub_82673FD4);
PPC_FUNC_IMPL(__imp__sub_82673FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82673FD8"))) PPC_WEAK_FUNC(sub_82673FD8);
PPC_FUNC_IMPL(__imp__sub_82673FD8) {
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
	ctx.lr = 0x82673FE0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82673FFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82674050
	if (!cr6.eq) goto loc_82674050;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x82207190
	ctx.lr = 0x82674018;
	sub_82207190(ctx, base);
	// bl 0x822166e8
	ctx.lr = 0x8267401C;
	sub_822166E8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,17268(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82674030;
	sub_821E80F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674050
	if (cr6.eq) goto loc_82674050;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x82674048;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a93a8
	ctx.lr = 0x82674050;
	sub_822A93A8(ctx, base);
loc_82674050:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630318
	ctx.lr = 0x8267405C;
	sub_82630318(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674064"))) PPC_WEAK_FUNC(sub_82674064);
PPC_FUNC_IMPL(__imp__sub_82674064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674068"))) PPC_WEAK_FUNC(sub_82674068);
PPC_FUNC_IMPL(__imp__sub_82674068) {
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
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f3,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x826533e8
	ctx.lr = 0x82674098;
	sub_826533E8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,17268(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x826740AC;
	sub_821E80F8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826740fc
	if (cr6.eq) goto loc_826740FC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x826740C4;
	sub_822A3998(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a93a8
	ctx.lr = 0x826740D0;
	sub_822A93A8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lwz r3,880(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 880);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x826740E8;
	sub_822AFCD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x826740F0;
	sub_822A5578(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
loc_826740FC:
	// bl 0x82216648
	ctx.lr = 0x82674100;
	sub_82216648(ctx, base);
	// li r3,9
	ctx.r3.s64 = 9;
	// bl 0x82216138
	ctx.lr = 0x82674108;
	sub_82216138(ctx, base);
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

__attribute__((alias("__imp__sub_8267411C"))) PPC_WEAK_FUNC(sub_8267411C);
PPC_FUNC_IMPL(__imp__sub_8267411C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674120"))) PPC_WEAK_FUNC(sub_82674120);
PPC_FUNC_IMPL(__imp__sub_82674120) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x82653920
	ctx.lr = 0x82674144;
	sub_82653920(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826741d8
	if (cr6.eq) goto loc_826741D8;
	// lfs f0,992(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 992);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f0,992(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 992, temp.u32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x826741b0
	if (!cr6.gt) goto loc_826741B0;
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x826741a8
	if (!cr6.lt) goto loc_826741A8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,26468(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 26468);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x823dbae8
	ctx.lr = 0x826741A0;
	sub_823DBAE8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// b 0x826741b4
	goto loc_826741B4;
loc_826741A8:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
	// b 0x826741b4
	goto loc_826741B4;
loc_826741B0:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_826741B4:
	// fsubs f13,f30,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f30.f64 - f0.f64));
	// lfs f0,996(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 996);
	f0.f64 = double(temp.f32);
	// stfs f13,996(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// bgt cr6,0x826741d8
	if (cr6.gt) goto loc_826741D8;
	// stfs f31,996(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 996, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x826741d8
	if (!cr6.gt) goto loc_826741D8;
	// bl 0x82215a60
	ctx.lr = 0x826741D8;
	sub_82215A60(ctx, base);
loc_826741D8:
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

__attribute__((alias("__imp__sub_826741F4"))) PPC_WEAK_FUNC(sub_826741F4);
PPC_FUNC_IMPL(__imp__sub_826741F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826741F8"))) PPC_WEAK_FUNC(sub_826741F8);
PPC_FUNC_IMPL(__imp__sub_826741F8) {
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
	// bl 0x826538a8
	ctx.lr = 0x82674218;
	sub_826538A8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,25756
	ctx.r5.s64 = r11.s64 + 25756;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,996
	ctx.r6.s64 = r31.s64 + 996;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82674238;
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

__attribute__((alias("__imp__sub_82674250"))) PPC_WEAK_FUNC(sub_82674250);
PPC_FUNC_IMPL(__imp__sub_82674250) {
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
	// bl 0x826538a8
	ctx.lr = 0x82674270;
	sub_826538A8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,25756
	ctx.r5.s64 = r11.s64 + 25756;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3668
	ctx.r6.s64 = r31.s64 + 3668;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x82674290;
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

__attribute__((alias("__imp__sub_826742A8"))) PPC_WEAK_FUNC(sub_826742A8);
PPC_FUNC_IMPL(__imp__sub_826742A8) {
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
	// bl 0x826538a8
	ctx.lr = 0x826742C8;
	sub_826538A8(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,25756
	ctx.r5.s64 = r11.s64 + 25756;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,1068
	ctx.r6.s64 = r31.s64 + 1068;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826742E8;
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

__attribute__((alias("__imp__sub_82674300"))) PPC_WEAK_FUNC(sub_82674300);
PPC_FUNC_IMPL(__imp__sub_82674300) {
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
	ctx.lr = 0x82674308;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r10,-12592
	r29.s64 = ctx.r10.s64 + -12592;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r30,208(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267432C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82674338;
	sub_825EE0E0(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r8,-19772
	r30.s64 = ctx.r8.s64 + -19772;
	// lwz r6,468(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 468);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82674354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82674360;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674368"))) PPC_WEAK_FUNC(sub_82674368);
PPC_FUNC_IMPL(__imp__sub_82674368) {
	PPC_FUNC_PROLOGUE();
	// b 0x82633f38
	sub_82633F38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267436C"))) PPC_WEAK_FUNC(sub_8267436C);
PPC_FUNC_IMPL(__imp__sub_8267436C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674370"))) PPC_WEAK_FUNC(sub_82674370);
PPC_FUNC_IMPL(__imp__sub_82674370) {
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
	// bl 0x82634010
	ctx.lr = 0x82674388;
	sub_82634010(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r11,208(r31)
	PPC_STORE_U32(r31.u32 + 208, r11.u32);
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

__attribute__((alias("__imp__sub_826743A4"))) PPC_WEAK_FUNC(sub_826743A4);
PPC_FUNC_IMPL(__imp__sub_826743A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826743A8"))) PPC_WEAK_FUNC(sub_826743A8);
PPC_FUNC_IMPL(__imp__sub_826743A8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// bne cr6,0x826743e4
	if (!cr6.eq) goto loc_826743E4;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826743D0;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826743E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826743E4:
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

__attribute__((alias("__imp__sub_826743FC"))) PPC_WEAK_FUNC(sub_826743FC);
PPC_FUNC_IMPL(__imp__sub_826743FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674400"))) PPC_WEAK_FUNC(sub_82674400);
PPC_FUNC_IMPL(__imp__sub_82674400) {
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
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x826744ac
	if (!cr6.eq) goto loc_826744AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8267443C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,246(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 246);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82674470
	if (cr6.eq) goto loc_82674470;
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82674468
	if (cr6.eq) goto loc_82674468;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,744(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 744);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674468:
	// li r11,0
	r11.s64 = 0;
	// stb r11,246(r31)
	PPC_STORE_U8(r31.u32 + 246, r11.u8);
loc_82674470:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,756(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 756);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674484;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674498;
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
loc_826744AC:
	// bl 0x82630580
	ctx.lr = 0x826744B0;
	sub_82630580(ctx, base);
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

__attribute__((alias("__imp__sub_826744C4"))) PPC_WEAK_FUNC(sub_826744C4);
PPC_FUNC_IMPL(__imp__sub_826744C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826744C8"))) PPC_WEAK_FUNC(sub_826744C8);
PPC_FUNC_IMPL(__imp__sub_826744C8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82674504
	if (cr6.eq) goto loc_82674504;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x826744f4
	if (cr6.eq) goto loc_826744F4;
	// bl 0x826537d0
	ctx.lr = 0x826744F0;
	sub_826537D0(ctx, base);
	// b 0x82674524
	goto loc_82674524;
loc_826744F4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x82674500;
	sub_821E6800(ctx, base);
	// b 0x82674524
	goto loc_82674524;
loc_82674504:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82674510;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674524;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674524:
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

__attribute__((alias("__imp__sub_8267453C"))) PPC_WEAK_FUNC(sub_8267453C);
PPC_FUNC_IMPL(__imp__sub_8267453C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674540"))) PPC_WEAK_FUNC(sub_82674540);
PPC_FUNC_IMPL(__imp__sub_82674540) {
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
	// bl 0x82653b30
	ctx.lr = 0x82674550;
	sub_82653B30(ctx, base);
	// bl 0x82216788
	ctx.lr = 0x82674554;
	sub_82216788(ctx, base);
	// bl 0x82215a60
	ctx.lr = 0x82674558;
	sub_82215A60(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82674568"))) PPC_WEAK_FUNC(sub_82674568);
PPC_FUNC_IMPL(__imp__sub_82674568) {
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
	// li r11,0
	r11.s64 = 0;
	// rlwinm r10,r30,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4;
	// stw r11,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,26,26
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,25,25
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,24,24
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,21,21
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,20,20
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x800;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,19,19
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x1000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826745ec
	if (!cr6.eq) goto loc_826745EC;
	// rlwinm r11,r30,0,18,18
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82674610
	if (cr6.eq) goto loc_82674610;
loc_826745EC:
	// li r11,1
	r11.s64 = 1;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r11,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, r11.u32);
	// addi r3,r31,1008
	ctx.r3.s64 = r31.s64 + 1008;
	// lwz r9,1008(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 1008);
	// addi r4,r10,25828
	ctx.r4.s64 = ctx.r10.s64 + 25828;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82674610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674610:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,30,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,28,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,22,22
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8267464c
	if (!cr6.eq) goto loc_8267464C;
	// rlwinm r11,r30,0,17,17
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8267467c
	if (cr6.eq) goto loc_8267467C;
loc_8267464C:
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r9,r11,126
	ctx.r9.s64 = r11.s64 + 126;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r9,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r8,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, ctx.r8.u32);
	// addi r4,r10,25800
	ctx.r4.s64 = ctx.r10.s64 + 25800;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r7,r11,r31
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8267467C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267467C:
	// rlwinm r11,r30,0,27,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826746b8
	if (cr6.eq) goto loc_826746B8;
	// lwz r11,1040(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1040);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r8,r11,126
	ctx.r8.s64 = r11.s64 + 126;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,1040(r31)
	PPC_STORE_U32(r31.u32 + 1040, ctx.r9.u32);
	// addi r4,r10,25768
	ctx.r4.s64 = ctx.r10.s64 + 25768;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r7,r11,r31
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826746B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826746B8:
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

__attribute__((alias("__imp__sub_826746D0"))) PPC_WEAK_FUNC(sub_826746D0);
PPC_FUNC_IMPL(__imp__sub_826746D0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653f28
	sub_82653F28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746D4"))) PPC_WEAK_FUNC(sub_826746D4);
PPC_FUNC_IMPL(__imp__sub_826746D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746D8"))) PPC_WEAK_FUNC(sub_826746D8);
PPC_FUNC_IMPL(__imp__sub_826746D8) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653b30
	sub_82653B30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746DC"))) PPC_WEAK_FUNC(sub_826746DC);
PPC_FUNC_IMPL(__imp__sub_826746DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746E0"))) PPC_WEAK_FUNC(sub_826746E0);
PPC_FUNC_IMPL(__imp__sub_826746E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82653670
	sub_82653670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826746E4"))) PPC_WEAK_FUNC(sub_826746E4);
PPC_FUNC_IMPL(__imp__sub_826746E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826746E8"))) PPC_WEAK_FUNC(sub_826746E8);
PPC_FUNC_IMPL(__imp__sub_826746E8) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x82674718
	if (cr6.eq) goto loc_82674718;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// bne cr6,0x8267474c
	if (!cr6.eq) goto loc_8267474C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r9,r11,24348
	ctx.r9.s64 = r11.s64 + 24348;
	// b 0x82674720
	goto loc_82674720;
loc_82674718:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
loc_82674720:
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x8267474c
	if (!cr6.eq) goto loc_8267474C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82674738;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8267474C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8267474C:
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

__attribute__((alias("__imp__sub_82674764"))) PPC_WEAK_FUNC(sub_82674764);
PPC_FUNC_IMPL(__imp__sub_82674764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674768"))) PPC_WEAK_FUNC(sub_82674768);
PPC_FUNC_IMPL(__imp__sub_82674768) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28644
	ctx.r4.s64 = r11.s64 + 28644;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// b 0x8262ffe0
	sub_8262FFE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8267477C"))) PPC_WEAK_FUNC(sub_8267477C);
PPC_FUNC_IMPL(__imp__sub_8267477C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82674780"))) PPC_WEAK_FUNC(sub_82674780);
PPC_FUNC_IMPL(__imp__sub_82674780) {
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
	ctx.lr = 0x82674788;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x826747a4
	if (!cr6.eq) goto loc_826747A4;
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8267481c
	if (cr6.eq) goto loc_8267481C;
loc_826747A4:
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
	ctx.lr = 0x826747C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee270
	ctx.lr = 0x826747D0;
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
	ctx.lr = 0x826747E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8267481c
	if (cr6.eq) goto loc_8267481C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r31,80(r1)
	r31.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674808;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82653450
	ctx.lr = 0x82674814;
	sub_82653450(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_8267481C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82674828"))) PPC_WEAK_FUNC(sub_82674828);
PPC_FUNC_IMPL(__imp__sub_82674828) {
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
	// bl 0x82630580
	ctx.lr = 0x82674840;
	sub_82630580(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,804(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82674854;
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

__attribute__((alias("__imp__sub_82674868"))) PPC_WEAK_FUNC(sub_82674868);
PPC_FUNC_IMPL(__imp__sub_82674868) {
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
	// bl 0x82674400
	ctx.lr = 0x82674880;
	sub_82674400(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,28644
	ctx.r4.s64 = r11.s64 + 28644;
	// addi r3,r31,256
	ctx.r3.s64 = r31.s64 + 256;
	// bl 0x8262ffe0
	ctx.lr = 0x82674894;
	sub_8262FFE0(ctx, base);
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

__attribute__((alias("__imp__sub_826748A8"))) PPC_WEAK_FUNC(sub_826748A8);
PPC_FUNC_IMPL(__imp__sub_826748A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,24348
	ctx.r4.s64 = r11.s64 + 24348;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// b 0x8262ffe0
	sub_8262FFE0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_826748BC"))) PPC_WEAK_FUNC(sub_826748BC);
PPC_FUNC_IMPL(__imp__sub_826748BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826748C0"))) PPC_WEAK_FUNC(sub_826748C0);
PPC_FUNC_IMPL(__imp__sub_826748C0) {
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
	// cmpwi cr6,r4,55
	cr6.compare<int32_t>(ctx.r4.s32, 55, xer);
	// beq cr6,0x8267491c
	if (cr6.eq) goto loc_8267491C;
	// cmpwi cr6,r4,56
	cr6.compare<int32_t>(ctx.r4.s32, 56, xer);
	// beq cr6,0x826748fc
	if (cr6.eq) goto loc_826748FC;
	// bl 0x826537d0
	ctx.lr = 0x826748E8;
	sub_826537D0(ctx, base);
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
loc_826748FC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82674950
	if (cr6.eq) goto loc_82674950;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// b 0x82674938
	goto loc_82674938;
loc_8267491C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r10,432(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 432);
	// addi r9,r11,28644
	ctx.r9.s64 = r11.s64 + 28644;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82674950
	if (!cr6.eq) goto loc_82674950;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
loc_82674938:
	// bl 0x821e6800
	ctx.lr = 0x8267493C;
	sub_821E6800(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,736(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82674950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82674950:
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

