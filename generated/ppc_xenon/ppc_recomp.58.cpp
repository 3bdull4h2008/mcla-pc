#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8237926C"))) PPC_WEAK_FUNC(sub_8237926C);
PPC_FUNC_IMPL(__imp__sub_8237926C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82379270"))) PPC_WEAK_FUNC(sub_82379270);
PPC_FUNC_IMPL(__imp__sub_82379270) {
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
	ctx.lr = 0x82379278;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,-8176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8176);
	// lwz r4,5976(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5976);
	// bl 0x82374928
	ctx.lr = 0x82379294;
	sub_82374928(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r30,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r30.u32);
	// stw r30,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r30.u32);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
	// beq cr6,0x823793e0
	if (cr6.eq) goto loc_823793E0;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// addi r4,r11,-23936
	ctx.r4.s64 = r11.s64 + -23936;
	// bl 0x82192680
	ctx.lr = 0x823792C4;
	sub_82192680(ctx, base);
	// stw r3,236(r31)
	PPC_STORE_U32(r31.u32 + 236, ctx.r3.u32);
	// lwz r3,12(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,260(r31)
	PPC_STORE_U32(r31.u32 + 260, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-24252
	ctx.r4.s64 = ctx.r10.s64 + -24252;
	// bl 0x82193af8
	ctx.lr = 0x823792E0;
	sub_82193AF8(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lwz r3,260(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-24232
	ctx.r4.s64 = ctx.r9.s64 + -24232;
	// bl 0x82193af8
	ctx.lr = 0x823792F8;
	sub_82193AF8(ctx, base);
	// stw r3,148(r31)
	PPC_STORE_U32(r31.u32 + 148, ctx.r3.u32);
	// lwz r8,236(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-23952
	ctx.r4.s64 = ctx.r7.s64 + -23952;
	// lwz r3,20(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82379314;
	sub_8218A568(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r6,236(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-23972
	ctx.r4.s64 = ctx.r4.s64 + -23972;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82379330;
	sub_8218A568(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lwz r11,236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r3,-23988
	ctx.r4.s64 = ctx.r3.s64 + -23988;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x8237934C;
	sub_8218A568(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lwz r10,236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-27840
	ctx.r4.s64 = ctx.r9.s64 + -27840;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82379368;
	sub_8218A568(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lwz r7,236(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-24000
	ctx.r4.s64 = ctx.r8.s64 + -24000;
	// lwz r3,20(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x82379384;
	sub_8218A568(ctx, base);
	// stw r3,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r3.u32);
	// lwz r6,236(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r4,-24016
	ctx.r4.s64 = ctx.r4.s64 + -24016;
	// lwz r3,20(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x823793A0;
	sub_8218A568(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lwz r11,236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r3,-24032
	ctx.r4.s64 = ctx.r3.s64 + -24032;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x823793BC;
	sub_8218A568(ctx, base);
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// lwz r10,236(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 236);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,-24048
	ctx.r4.s64 = ctx.r9.s64 + -24048;
	// lwz r3,20(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// bl 0x8218a568
	ctx.lr = 0x823793D8;
	sub_8218A568(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// stb r30,268(r31)
	PPC_STORE_U8(r31.u32 + 268, r30.u8);
loc_823793E0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_823793E8"))) PPC_WEAK_FUNC(sub_823793E8);
PPC_FUNC_IMPL(__imp__sub_823793E8) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,-8176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8176);
	// lwz r4,5964(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5964);
	// bl 0x82374788
	ctx.lr = 0x82379410;
	sub_82374788(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823794cc
	if (cr6.eq) goto loc_823794CC;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-24196
	ctx.r4.s64 = r11.s64 + -24196;
	// stw r3,252(r31)
	PPC_STORE_U32(r31.u32 + 252, ctx.r3.u32);
	// bl 0x82193af8
	ctx.lr = 0x82379430;
	sub_82193AF8(ctx, base);
	// stw r3,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r3.u32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lwz r3,252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,11892
	ctx.r4.s64 = ctx.r10.s64 + 11892;
	// bl 0x82193af8
	ctx.lr = 0x82379448;
	sub_82193AF8(ctx, base);
	// stw r3,172(r31)
	PPC_STORE_U32(r31.u32 + 172, ctx.r3.u32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lwz r3,252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,32684
	ctx.r4.s64 = ctx.r9.s64 + 32684;
	// bl 0x82193af8
	ctx.lr = 0x82379460;
	sub_82193AF8(ctx, base);
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lwz r3,252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-23924
	ctx.r4.s64 = ctx.r8.s64 + -23924;
	// bl 0x82193af8
	ctx.lr = 0x82379478;
	sub_82193AF8(ctx, base);
	// stw r3,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r3.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lwz r3,252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,32668
	ctx.r4.s64 = ctx.r7.s64 + 32668;
	// bl 0x82193af8
	ctx.lr = 0x82379490;
	sub_82193AF8(ctx, base);
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lwz r3,252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,-24252
	ctx.r4.s64 = ctx.r6.s64 + -24252;
	// bl 0x82193af8
	ctx.lr = 0x823794A8;
	sub_82193AF8(ctx, base);
	// stw r3,136(r31)
	PPC_STORE_U32(r31.u32 + 136, ctx.r3.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lwz r3,252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,-24232
	ctx.r4.s64 = ctx.r4.s64 + -24232;
	// bl 0x82193af8
	ctx.lr = 0x823794C0;
	sub_82193AF8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r3,140(r31)
	PPC_STORE_U32(r31.u32 + 140, ctx.r3.u32);
	// stb r11,266(r31)
	PPC_STORE_U8(r31.u32 + 266, r11.u8);
loc_823794CC:
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

__attribute__((alias("__imp__sub_823794E0"))) PPC_WEAK_FUNC(sub_823794E0);
PPC_FUNC_IMPL(__imp__sub_823794E0) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,-8176(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8176);
	// lwz r4,5968(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 5968);
	// bl 0x82374858
	ctx.lr = 0x82379508;
	sub_82374858(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8237954c
	if (cr6.eq) goto loc_8237954C;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-23888
	ctx.r4.s64 = r11.s64 + -23888;
	// stw r3,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r3.u32);
	// bl 0x82193af8
	ctx.lr = 0x82379528;
	sub_82193AF8(ctx, base);
	// stw r3,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r3.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lwz r3,256(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-23912
	ctx.r4.s64 = ctx.r10.s64 + -23912;
	// bl 0x82193af8
	ctx.lr = 0x82379540;
	sub_82193AF8(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r3,188(r31)
	PPC_STORE_U32(r31.u32 + 188, ctx.r3.u32);
	// stb r9,267(r31)
	PPC_STORE_U8(r31.u32 + 267, ctx.r9.u8);
loc_8237954C:
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

__attribute__((alias("__imp__sub_82379560"))) PPC_WEAK_FUNC(sub_82379560);
PPC_FUNC_IMPL(__imp__sub_82379560) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lbz r11,264(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 264);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// ble cr6,0x823795bc
	if (!cr6.gt) goto loc_823795BC;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r10,r10,464
	ctx.r10.s64 = ctx.r10.s64 + 464;
	// subf r9,r5,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r5.s64;
	// li r8,-448
	ctx.r8.s64 = -448;
loc_8237958C:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8237959c
	if (cr6.eq) goto loc_8237959C;
	// lvx128 v63,r9,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237959C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x823795ac
	if (cr6.eq) goto loc_823795AC;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823795AC:
	// addic. r6,r6,-1
	xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x8237958c
	if (!cr0.eq) goto loc_8237958C;
loc_823795BC:
	// lwz r4,248(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// b 0x82378528
	sub_82378528(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823795C8"))) PPC_WEAK_FUNC(sub_823795C8);
PPC_FUNC_IMPL(__imp__sub_823795C8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823795CC"))) PPC_WEAK_FUNC(sub_823795CC);
PPC_FUNC_IMPL(__imp__sub_823795CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823795D0"))) PPC_WEAK_FUNC(sub_823795D0);
PPC_FUNC_IMPL(__imp__sub_823795D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// lbz r11,265(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 265);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// ble cr6,0x8237962c
	if (!cr6.gt) goto loc_8237962C;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// addi r10,r10,464
	ctx.r10.s64 = ctx.r10.s64 + 464;
	// subf r9,r5,r4
	ctx.r9.s64 = ctx.r4.s64 - ctx.r5.s64;
	// li r8,-448
	ctx.r8.s64 = -448;
loc_823795FC:
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8237960c
	if (cr6.eq) goto loc_8237960C;
	// lvx128 v63,r9,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237960C:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8237961c
	if (cr6.eq) goto loc_8237961C;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237961C:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x823795fc
	if (!cr0.eq) goto loc_823795FC;
loc_8237962C:
	// lwz r4,248(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// lwz r3,56(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// b 0x82378528
	sub_82378528(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82379638"))) PPC_WEAK_FUNC(sub_82379638);
PPC_FUNC_IMPL(__imp__sub_82379638) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237963C"))) PPC_WEAK_FUNC(sub_8237963C);
PPC_FUNC_IMPL(__imp__sub_8237963C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82379640"))) PPC_WEAK_FUNC(sub_82379640);
PPC_FUNC_IMPL(__imp__sub_82379640) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
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
	// lwz r4,64(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stfs f4,92(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// beq cr6,0x82379674
	if (cr6.eq) goto loc_82379674;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,248(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// bl 0x82192a88
	ctx.lr = 0x82379674;
	sub_82192A88(ctx, base);
loc_82379674:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82379684"))) PPC_WEAK_FUNC(sub_82379684);
PPC_FUNC_IMPL(__imp__sub_82379684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82379688"))) PPC_WEAK_FUNC(sub_82379688);
PPC_FUNC_IMPL(__imp__sub_82379688) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
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
	// lwz r4,68(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stfs f4,92(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// beq cr6,0x823796bc
	if (cr6.eq) goto loc_823796BC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,248(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// bl 0x82192a88
	ctx.lr = 0x823796BC;
	sub_82192A88(ctx, base);
loc_823796BC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823796CC"))) PPC_WEAK_FUNC(sub_823796CC);
PPC_FUNC_IMPL(__imp__sub_823796CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823796D0"))) PPC_WEAK_FUNC(sub_823796D0);
PPC_FUNC_IMPL(__imp__sub_823796D0) {
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
	ctx.lr = 0x823796E8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfd f31,31344(r11)
	f31.u64 = PPC_LOAD_U64(r11.u32 + 31344);
	// lfs f1,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// bl 0x823dc480
	ctx.lr = 0x8237970C;
	sub_823DC480(ctx, base);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// frsp f29,f1
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// bl 0x823dc480
	ctx.lr = 0x82379720;
	sub_823DC480(ctx, base);
	// lfs f13,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// frsp f28,f1
	f28.f64 = double(float(ctx.f1.f64));
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f13
	ctx.f1.f64 = ctx.f13.f64;
	// bl 0x823dc480
	ctx.lr = 0x82379734;
	sub_823DC480(ctx, base);
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// stfs f29,80(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f28,84(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stfs f30,92(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x82379760
	if (cr6.eq) goto loc_82379760;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// bl 0x82192a88
	ctx.lr = 0x82379760;
	sub_82192A88(ctx, base);
loc_82379760:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x8237976C;
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

__attribute__((alias("__imp__sub_82379780"))) PPC_WEAK_FUNC(sub_82379780);
PPC_FUNC_IMPL(__imp__sub_82379780) {
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
	ctx.lr = 0x82379798;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lfd f31,31344(r11)
	f31.u64 = PPC_LOAD_U64(r11.u32 + 31344);
	// lfs f1,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// bl 0x823dc480
	ctx.lr = 0x823797BC;
	sub_823DC480(ctx, base);
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// frsp f29,f1
	f29.f64 = double(float(ctx.f1.f64));
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// bl 0x823dc480
	ctx.lr = 0x823797D0;
	sub_823DC480(ctx, base);
	// lfs f13,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// frsp f28,f1
	f28.f64 = double(float(ctx.f1.f64));
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// fmr f1,f13
	ctx.f1.f64 = ctx.f13.f64;
	// bl 0x823dc480
	ctx.lr = 0x823797E4;
	sub_823DC480(ctx, base);
	// lwz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// stfs f29,80(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f28,84(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stfs f30,92(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x82379810
	if (cr6.eq) goto loc_82379810;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// bl 0x82192a88
	ctx.lr = 0x82379810;
	sub_82192A88(ctx, base);
loc_82379810:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x8237981C;
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

__attribute__((alias("__imp__sub_82379830"))) PPC_WEAK_FUNC(sub_82379830);
PPC_FUNC_IMPL(__imp__sub_82379830) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
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
	// lwz r4,80(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f3,88(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stfs f4,92(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// beq cr6,0x82379864
	if (cr6.eq) goto loc_82379864;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,248(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// bl 0x82192a88
	ctx.lr = 0x82379864;
	sub_82192A88(ctx, base);
loc_82379864:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82379874"))) PPC_WEAK_FUNC(sub_82379874);
PPC_FUNC_IMPL(__imp__sub_82379874) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82379878"))) PPC_WEAK_FUNC(sub_82379878);
PPC_FUNC_IMPL(__imp__sub_82379878) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,84(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x823798c4
	if (cr6.eq) goto loc_823798C4;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,248(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// bl 0x82192a88
	ctx.lr = 0x823798C4;
	sub_82192A88(ctx, base);
loc_823798C4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823798D4"))) PPC_WEAK_FUNC(sub_823798D4);
PPC_FUNC_IMPL(__imp__sub_823798D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823798D8"))) PPC_WEAK_FUNC(sub_823798D8);
PPC_FUNC_IMPL(__imp__sub_823798D8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,88(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// stfs f1,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x8237991c
	if (cr6.eq) goto loc_8237991C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,248(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// bl 0x82192a88
	ctx.lr = 0x8237991C;
	sub_82192A88(ctx, base);
loc_8237991C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237992C"))) PPC_WEAK_FUNC(sub_8237992C);
PPC_FUNC_IMPL(__imp__sub_8237992C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82379930"))) PPC_WEAK_FUNC(sub_82379930);
PPC_FUNC_IMPL(__imp__sub_82379930) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r4,92(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// beq cr6,0x8237997c
	if (cr6.eq) goto loc_8237997C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,248(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// bl 0x82192a88
	ctx.lr = 0x8237997C;
	sub_82192A88(ctx, base);
loc_8237997C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237998C"))) PPC_WEAK_FUNC(sub_8237998C);
PPC_FUNC_IMPL(__imp__sub_8237998C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82379990"))) PPC_WEAK_FUNC(sub_82379990);
PPC_FUNC_IMPL(__imp__sub_82379990) {
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
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r11,269(r31)
	PPC_STORE_U8(r31.u32 + 269, r11.u8);
	// bl 0x82378da8
	ctx.lr = 0x823799B4;
	sub_82378DA8(ctx, base);
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

__attribute__((alias("__imp__sub_823799CC"))) PPC_WEAK_FUNC(sub_823799CC);
PPC_FUNC_IMPL(__imp__sub_823799CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823799D0"))) PPC_WEAK_FUNC(sub_823799D0);
PPC_FUNC_IMPL(__imp__sub_823799D0) {
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
	// lbz r11,267(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 267);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823799f4
	if (cr6.eq) goto loc_823799F4;
	// bl 0x823794e0
	ctx.lr = 0x823799F4;
	sub_823794E0(ctx, base);
loc_823799F4:
	// lbz r11,266(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 266);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82379a08
	if (cr6.eq) goto loc_82379A08;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823793e8
	ctx.lr = 0x82379A08;
	sub_823793E8(ctx, base);
loc_82379A08:
	// lbz r11,268(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 268);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82379a1c
	if (cr6.eq) goto loc_82379A1C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82379270
	ctx.lr = 0x82379A1C;
	sub_82379270(ctx, base);
loc_82379A1C:
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

__attribute__((alias("__imp__sub_82379A30"))) PPC_WEAK_FUNC(sub_82379A30);
PPC_FUNC_IMPL(__imp__sub_82379A30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-8108(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8108);
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

__attribute__((alias("__imp__sub_82379A54"))) PPC_WEAK_FUNC(sub_82379A54);
PPC_FUNC_IMPL(__imp__sub_82379A54) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82379A58"))) PPC_WEAK_FUNC(sub_82379A58);
PPC_FUNC_IMPL(__imp__sub_82379A58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,816(r3)
	PPC_STORE_U32(ctx.r3.u32 + 816, ctx.r4.u32);
	// addi r9,r3,512
	ctx.r9.s64 = ctx.r3.s64 + 512;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// lfs f11,27640(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27640);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// li r5,32
	ctx.r5.s64 = 32;
	// lfs f13,14348(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14348);
	ctx.f13.f64 = double(temp.f32);
	// ori r6,r6,64167
	ctx.r6.u64 = ctx.r6.u64 | 64167;
	// lfs f0,3796(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r10,r10,2176
	ctx.r10.s64 = ctx.r10.s64 + 2176;
loc_82379A98:
	// stfs f0,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// stfs f0,-4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mulld r7,r4,r6
	ctx.r7.s64 = ctx.r4.s64 * ctx.r6.s64;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// rotlwi r7,r8,0
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rldicl r4,r8,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// mulld r7,r7,r6
	ctx.r7.s64 = ctx.r7.s64 * ctx.r6.s64;
	// add r7,r7,r4
	ctx.r7.u64 = ctx.r7.u64 + ctx.r4.u64;
	// clrlwi r4,r8,9
	ctx.r4.u64 = ctx.r8.u32 & 0x7FFFFF;
	// clrlwi r3,r7,9
	ctx.r3.u64 = ctx.r7.u32 & 0x7FFFFF;
	// std r4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r4.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// std r3,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r3.u64);
	// lfd f9,-8(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f8,f10
	ctx.f8.f64 = double(ctx.f10.s64);
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// rldicl r7,r7,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u64, 32) & 0xFFFFFFFF;
	// fcfid f6,f9
	ctx.f6.f64 = double(ctx.f9.s64);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// fmuls f5,f7,f13
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f13.f64));
	// frsp f4,f6
	ctx.f4.f64 = double(float(ctx.f6.f64));
	// fsubs f3,f5,f12
	ctx.f3.f64 = double(float(ctx.f5.f64 - ctx.f12.f64));
	// fmsubs f2,f4,f13,f12
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 - ctx.f12.f64));
	// fmuls f1,f3,f11
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// stfs f1,4(r9)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fmuls f10,f2,f11
	ctx.f10.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// stfs f10,0(r9)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// bne 0x82379a98
	if (!cr0.eq) goto loc_82379A98;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82379B30"))) PPC_WEAK_FUNC(sub_82379B30);
PPC_FUNC_IMPL(__imp__sub_82379B30) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82379B38;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,816(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 816);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,668(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 668);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82379c60
	if (cr6.eq) goto loc_82379C60;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8217fed0
	ctx.lr = 0x82379B5C;
	sub_8217FED0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,24
	ctx.r3.s64 = 24;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r29,r10,1
	r29.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8217fed0
	ctx.lr = 0x82379B70;
	sub_8217FED0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x8217fed0
	ctx.lr = 0x82379B7C;
	sub_8217FED0(ctx, base);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r9,30248(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 30248);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x82379bc0
	if (cr6.eq) goto loc_82379BC0;
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x8217f768
	ctx.lr = 0x82379B9C;
	sub_8217F768(ctx, base);
	// li r3,25
	ctx.r3.s64 = 25;
	// lwz r4,30248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 30248);
	// bl 0x8217f768
	ctx.lr = 0x82379BA8;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x8217f768
	ctx.lr = 0x82379BB4;
	sub_8217F768(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8217f768
	ctx.lr = 0x82379BC0;
	sub_8217F768(ctx, base);
loc_82379BC0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,780(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 780);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82379c30
	if (!cr6.gt) goto loc_82379C30;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r26,-32119
	r26.s64 = -2104950784;
	// li r6,32
	ctx.r6.s64 = 32;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,-8116(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -8116);
	// lwz r3,-8104(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -8104);
	// bl 0x82192b18
	ctx.lr = 0x82379BF0;
	sub_82192B18(ctx, base);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r3,-8104(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -8104);
	// lfs f1,780(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 780);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,-8112(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8112);
	// bl 0x82192798
	ctx.lr = 0x82379C04;
	sub_82192798(ctx, base);
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r4,r8,-31280
	ctx.r4.s64 = ctx.r8.s64 + -31280;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-8108(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8108);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82379C30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82379C30:
	// lwz r11,30248(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 30248);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82379c60
	if (cr6.eq) goto loc_82379C60;
	// clrlwi r4,r29,24
	ctx.r4.u64 = r29.u32 & 0xFF;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x8217f768
	ctx.lr = 0x82379C48;
	sub_8217F768(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x8217f768
	ctx.lr = 0x82379C54;
	sub_8217F768(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r3,23
	ctx.r3.s64 = 23;
	// bl 0x8217f768
	ctx.lr = 0x82379C60;
	sub_8217F768(ctx, base);
loc_82379C60:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82379C68"))) PPC_WEAK_FUNC(sub_82379C68);
PPC_FUNC_IMPL(__imp__sub_82379C68) {
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
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r30,r11,30576
	r30.s64 = r11.s64 + 30576;
	// addi r4,r10,-23516
	ctx.r4.s64 = ctx.r10.s64 + -23516;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x82379C94;
	sub_821CA540(ctx, base);
	// li r3,128
	ctx.r3.s64 = 128;
	// bl 0x82130528
	ctx.lr = 0x82379C9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82379cac
	if (cr6.eq) goto loc_82379CAC;
	// bl 0x82611298
	ctx.lr = 0x82379CA8;
	sub_82611298(ctx, base);
	// b 0x82379cb0
	goto loc_82379CB0;
loc_82379CAC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82379CB0:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r31,r11,-8108
	r31.s64 = r11.s64 + -8108;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,-23528
	ctx.r4.s64 = ctx.r10.s64 + -23528;
	// stw r3,-8108(r11)
	PPC_STORE_U32(r11.u32 + -8108, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82379CDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82379CE4;
	sub_821C9A90(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-23544
	ctx.r4.s64 = ctx.r8.s64 + -23544;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r3,-8104(r31)
	PPC_STORE_U32(r31.u32 + -8104, ctx.r3.u32);
	// bl 0x82193af8
	ctx.lr = 0x82379D04;
	sub_82193AF8(ctx, base);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-8104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8104);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r6,-23556
	ctx.r4.s64 = ctx.r6.s64 + -23556;
	// stw r11,-8116(r7)
	PPC_STORE_U32(ctx.r7.u32 + -8116, r11.u32);
	// bl 0x82193af8
	ctx.lr = 0x82379D24;
	sub_82193AF8(ctx, base);
	// lis r5,-32119
	ctx.r5.s64 = -2104950784;
	// stw r3,-8112(r5)
	PPC_STORE_U32(ctx.r5.u32 + -8112, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_82379D44"))) PPC_WEAK_FUNC(sub_82379D44);
PPC_FUNC_IMPL(__imp__sub_82379D44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82379D48"))) PPC_WEAK_FUNC(sub_82379D48);
PPC_FUNC_IMPL(__imp__sub_82379D48) {
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
	// bl 0x823d91e4
	ctx.lr = 0x82379D50;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r10,816(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 816);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,668(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8237a414
	if (cr6.eq) goto loc_8237A414;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r9,5(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 5);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82379d94
	if (cr6.eq) goto loc_82379D94;
	// lbz r11,11(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82379d98
	if (cr6.eq) goto loc_82379D98;
loc_82379D94:
	// li r11,0
	r11.s64 = 0;
loc_82379D98:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237a414
	if (!cr6.eq) goto loc_8237A414;
	// lwz r25,0(r13)
	r25.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r24,72
	r24.s64 = 72;
	// lbzx r11,r24,r25
	r11.u64 = PPC_LOAD_U8(r24.u32 + r25.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82379dc0
	if (cr6.eq) goto loc_82379DC0;
	// addi r11,r10,272
	r11.s64 = ctx.r10.s64 + 272;
	// b 0x82379dc8
	goto loc_82379DC8;
loc_82379DC0:
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82379DC8:
	// lfs f0,804(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 804);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,808(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 808);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,800(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 800);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f0,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fcmpu cr6,f2,f0
	cr6.compare(ctx.f2.f64, f0.f64);
	// ble cr6,0x8237a214
	if (!cr6.gt) goto loc_8237A214;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// addi r10,r27,752
	ctx.r10.s64 = r27.s64 + 752;
	// addi r11,r27,508
	r11.s64 = r27.s64 + 508;
	// li r30,3
	r30.s64 = 3;
	// lfs f0,-29232(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	f0.f64 = double(temp.f32);
	// li r28,-12
	r28.s64 = -12;
	// li r29,-140
	r29.s64 = -140;
	// addi r9,r9,29952
	ctx.r9.s64 = ctx.r9.s64 + 29952;
loc_82379E38:
	// addi r8,r11,-28
	ctx.r8.s64 = r11.s64 + -28;
	// addi r7,r11,-44
	ctx.r7.s64 = r11.s64 + -44;
	// addi r6,r11,-60
	ctx.r6.s64 = r11.s64 + -60;
	// addi r5,r11,-76
	ctx.r5.s64 = r11.s64 + -76;
	// addi r4,r11,-92
	ctx.r4.s64 = r11.s64 + -92;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r11,-108
	ctx.r3.s64 = r11.s64 + -108;
	// stvx128 v63,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r26,4(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r23,0(r10)
	r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r31,r11,-124
	r31.s64 = r11.s64 + -124;
	// stw r23,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r23.u32);
	// stw r26,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r26.u32);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -8);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f13,f0,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f11.f64));
	// stfs f10,-8(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + -8, temp.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f9,f13,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f8,0(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r26,-8(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// lwz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r26,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r26.u32);
	// lfs f7,-16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -16);
	ctx.f7.f64 = double(temp.f32);
	// lvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f6,-24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -24);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f5,f13,f0,f6
	ctx.f5.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f6.f64));
	// stfs f5,-24(r11)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r11.u32 + -24, temp.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f4,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f13,f4,f7
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f4.f64 + ctx.f7.f64));
	// stfs f3,-16(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + -16, temp.u32);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-12(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	// lwz r8,-16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	// stw r8,-8(r10)
	PPC_STORE_U32(ctx.r10.u32 + -8, ctx.r8.u32);
	// stw r7,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r7.u32);
	// lfs f2,-32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -32);
	ctx.f2.f64 = double(temp.f32);
	// lvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,-40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -40);
	ctx.f1.f64 = double(temp.f32);
	// fmadds f13,f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f1.f64));
	// stfs f13,-40(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + -40, temp.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f13,f2
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f2.f64));
	// stfs f11,-32(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + -32, temp.u32);
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-20(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -20);
	// lwz r6,-24(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24);
	// stw r6,-16(r10)
	PPC_STORE_U32(ctx.r10.u32 + -16, ctx.r6.u32);
	// stw r7,-12(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12, ctx.r7.u32);
	// lfs f10,-48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -48);
	ctx.f10.f64 = double(temp.f32);
	// lvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,-56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -56);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f13,f0,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f9.f64));
	// stfs f8,-56(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + -56, temp.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f7,-16(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f7,f13,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f13.f64 + ctx.f10.f64));
	// stfs f6,-48(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + -48, temp.u32);
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,-28(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -28);
	// lwz r8,-32(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -32);
	// stw r8,-24(r10)
	PPC_STORE_U32(ctx.r10.u32 + -24, ctx.r8.u32);
	// stw r5,-20(r10)
	PPC_STORE_U32(ctx.r10.u32 + -20, ctx.r5.u32);
	// lfs f5,-64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -64);
	ctx.f5.f64 = double(temp.f32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f4,-72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -72);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f13,f0,f4
	ctx.f3.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f4.f64));
	// stfs f3,-72(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + -72, temp.u32);
	// lfs f2,-24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -24);
	ctx.f2.f64 = double(temp.f32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f13,f2,f5
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f2.f64 + ctx.f5.f64));
	// stfs f1,-64(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -64, temp.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// lvx128 v58,r0,r3
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,-36(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + -36);
	// lwz r6,-40(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -40);
	// stw r6,-32(r10)
	PPC_STORE_U32(ctx.r10.u32 + -32, ctx.r6.u32);
	// stw r7,-28(r10)
	PPC_STORE_U32(ctx.r10.u32 + -28, ctx.r7.u32);
	// lfs f12,-80(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -80);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-88(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -88);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f13,f0,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f11.f64));
	// stfs f10,-88(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + -88, temp.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,-32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -32);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f9,f13,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f8,-80(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + -80, temp.u32);
	// stvx128 v57,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,-48(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -48);
	// stw r4,-40(r10)
	PPC_STORE_U32(ctx.r10.u32 + -40, ctx.r4.u32);
	// lwz r5,-44(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -44);
	// stw r5,-36(r10)
	PPC_STORE_U32(ctx.r10.u32 + -36, ctx.r5.u32);
	// lfs f7,-104(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -104);
	ctx.f7.f64 = double(temp.f32);
	// lfs f5,-96(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -96);
	ctx.f5.f64 = double(temp.f32);
	// lvx128 v56,r11,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f6,f13,f0,f7
	ctx.f6.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f7.f64));
	// stfs f6,-104(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + -104, temp.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f4,-40(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -40);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f4,f13,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f13.f64 + ctx.f5.f64));
	// stfs f3,-96(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + -96, temp.u32);
	// stvx128 v56,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,-52(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + -52);
	// stw r8,-44(r10)
	PPC_STORE_U32(ctx.r10.u32 + -44, ctx.r8.u32);
	// lwz r3,-56(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -56);
	// stw r3,-48(r10)
	PPC_STORE_U32(ctx.r10.u32 + -48, ctx.r3.u32);
	// lfs f12,-112(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -112);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,-120(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -120);
	ctx.f2.f64 = double(temp.f32);
	// fmadds f1,f13,f0,f2
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f2.f64));
	// stfs f1,-120(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + -120, temp.u32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -48);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f13,f11,f12
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f12.f64));
	// stfs f10,-112(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + -112, temp.u32);
	// addi r10,r10,-64
	ctx.r10.s64 = ctx.r10.s64 + -64;
	// addi r11,r11,-128
	r11.s64 = r11.s64 + -128;
	// bne 0x82379e38
	if (!cr0.eq) goto loc_82379E38;
	// addi r10,r27,568
	ctx.r10.s64 = r27.s64 + 568;
	// addi r11,r27,116
	r11.s64 = r27.s64 + 116;
	// li r8,7
	ctx.r8.s64 = 7;
	// li r6,-20
	ctx.r6.s64 = -20;
	// li r7,-4
	ctx.r7.s64 = -4;
loc_8237A058:
	// lvx128 v55,r11,r6
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stvx128 v55,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r5,-8(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// stw r5,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// lfs f13,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f13,f0,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// lfs f10,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// stfs f11,0(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lfs f9,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// addi r10,r10,-8
	ctx.r10.s64 = ctx.r10.s64 + -8;
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f8,f9,f13,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// stfs f8,8(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne 0x8237a058
	if (!cr0.eq) goto loc_8237A058;
	// lbzx r9,r24,r25
	ctx.r9.u64 = PPC_LOAD_U8(r24.u32 + r25.u32);
	// lwz r11,816(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 816);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8237a0bc
	if (cr6.eq) goto loc_8237A0BC;
	// addi r10,r11,272
	ctx.r10.s64 = r11.s64 + 272;
	// b 0x8237a0c4
	goto loc_8237A0C4;
loc_8237A0BC:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_8237A0C4:
	// li r8,48
	ctx.r8.s64 = 48;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v0,r10,r8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8237a0dc
	if (cr6.eq) goto loc_8237A0DC;
	// addi r10,r11,272
	ctx.r10.s64 = r11.s64 + 272;
	// b 0x8237a0e4
	goto loc_8237A0E4;
loc_8237A0DC:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_8237A0E4:
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f0,-13148(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13148);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v54,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v54,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// lvx128 v13,r10,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8237a120
	if (cr6.eq) goto loc_8237A120;
	// addi r10,r11,272
	ctx.r10.s64 = r11.s64 + 272;
	// b 0x8237a128
	goto loc_8237A128;
loc_8237A120:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
loc_8237A128:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r8,32
	ctx.r8.s64 = 32;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r5,23772
	ctx.r5.s64 = 1557921792;
	// lfs f0,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ori r11,r5,64167
	r11.u64 = ctx.r5.u64 | 64167;
	// lvx128 v13,r10,r8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r6,2176
	ctx.r4.s64 = ctx.r6.s64 + 2176;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// stfs f31,12(r27)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r27.u32 + 12, temp.u32);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,14348(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lvlx128 v53,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v53,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,8(r27)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r27.u32 + 8, temp.u32);
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,4(r27)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r27.u32 + 4, temp.u32);
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,0(r27)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r9,2176(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 2176);
	// mulld r10,r9,r8
	ctx.r10.s64 = ctx.r9.s64 * ctx.r8.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r10,r10,r5
	ctx.r10.s64 = ctx.r10.s64 * ctx.r5.s64;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// clrlwi r3,r10,9
	ctx.r3.u64 = ctx.r10.u32 & 0x7FFFFF;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r11,2176(r6)
	PPC_STORE_U32(ctx.r6.u32 + 2176, r11.u32);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// lfd f8,80(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// lfd f7,80(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f7
	ctx.f4.f64 = double(ctx.f7.s64);
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// frsp f2,f4
	ctx.f2.f64 = double(float(ctx.f4.f64));
	// fmuls f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmsubs f0,f2,f0,f13
	f0.f64 = double(float(ctx.f2.f64 * f0.f64 - ctx.f13.f64));
	// fsubs f1,f3,f13
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f13.f64));
	// fmuls f13,f1,f12
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// stfs f13,516(r27)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r27.u32 + 516, temp.u32);
	// fmuls f12,f0,f12
	ctx.f12.f64 = double(float(f0.f64 * ctx.f12.f64));
	// stfs f12,512(r27)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r27.u32 + 512, temp.u32);
loc_8237A214:
	// lwz r11,816(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 816);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// lwz r29,8(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,17892(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17892);
	// lwz r7,668(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 668);
	// lwz r11,68(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8237a2a4
	if (cr6.eq) goto loc_8237A2A4;
	// lbzx r8,r24,r25
	ctx.r8.u64 = PPC_LOAD_U8(r24.u32 + r25.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237a24c
	if (cr6.eq) goto loc_8237A24C;
	// lwz r9,804(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 804);
	// b 0x8237a250
	goto loc_8237A250;
loc_8237A24C:
	// lwz r9,400(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 400);
loc_8237A250:
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8237a2a4
	if (!cr6.lt) goto loc_8237A2A4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237a270
	if (cr6.eq) goto loc_8237A270;
	// addi r9,r11,101
	ctx.r9.s64 = r11.s64 + 101;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// b 0x8237a278
	goto loc_8237A278;
loc_8237A270:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_8237A278:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8237a2a4
	if (cr6.eq) goto loc_8237A2A4;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237a298
	if (cr6.eq) goto loc_8237A298;
	// addi r11,r11,101
	r11.s64 = r11.s64 + 101;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x8237a2a0
	goto loc_8237A2A0;
loc_8237A298:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
loc_8237A2A0:
	// lwz r28,48(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 48);
loc_8237A2A4:
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8237a338
	if (cr6.eq) goto loc_8237A338;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r11,668(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8237a338
	if (cr6.eq) goto loc_8237A338;
	// lwz r11,72(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x8237a338
	if (cr6.eq) goto loc_8237A338;
	// lbzx r8,r24,r25
	ctx.r8.u64 = PPC_LOAD_U8(r24.u32 + r25.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237a2e0
	if (cr6.eq) goto loc_8237A2E0;
	// lwz r9,804(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 804);
	// b 0x8237a2e4
	goto loc_8237A2E4;
loc_8237A2E0:
	// lwz r9,400(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 400);
loc_8237A2E4:
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// bge cr6,0x8237a338
	if (!cr6.lt) goto loc_8237A338;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237a304
	if (cr6.eq) goto loc_8237A304;
	// addi r9,r11,101
	ctx.r9.s64 = r11.s64 + 101;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r6,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// b 0x8237a30c
	goto loc_8237A30C;
loc_8237A304:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
loc_8237A30C:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8237a338
	if (cr6.eq) goto loc_8237A338;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237a32c
	if (cr6.eq) goto loc_8237A32C;
	// addi r11,r11,101
	r11.s64 = r11.s64 + 101;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// b 0x8237a334
	goto loc_8237A334;
loc_8237A32C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
loc_8237A334:
	// lwz r26,48(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 48);
loc_8237A338:
	// lwz r3,8(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// bl 0x82331d28
	ctx.lr = 0x8237A344;
	sub_82331D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237a374
	if (cr6.eq) goto loc_8237A374;
	// lwz r10,668(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 668);
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82331d18
	ctx.lr = 0x8237A368;
	sub_82331D18(ctx, base);
	// subf r9,r3,r30
	ctx.r9.s64 = r30.s64 - ctx.r3.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r30,r8,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
loc_8237A374:
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8237a3b0
	if (cr6.eq) goto loc_8237A3B0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82331d28
	ctx.lr = 0x8237A388;
	sub_82331D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237a3b0
	if (cr6.eq) goto loc_8237A3B0;
	// lwz r11,17268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82331d18
	ctx.lr = 0x8237A3A4;
	sub_82331D18(ctx, base);
	// subf r11,r3,r31
	r11.s64 = r31.s64 - ctx.r3.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r29,r10,27,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_8237A3B0:
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8237a3cc
	if (cr6.eq) goto loc_8237A3CC;
	// lwz r11,816(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 816);
	// subf r10,r26,r11
	ctx.r10.s64 = r11.s64 - r26.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
loc_8237A3CC:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8237a3e0
	if (cr6.eq) goto loc_8237A3E0;
	// li r31,1
	r31.s64 = 1;
loc_8237A3E0:
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8237a3fc
	if (cr6.eq) goto loc_8237A3FC;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237a3fc
	if (cr6.eq) goto loc_8237A3FC;
	// li r31,1
	r31.s64 = 1;
loc_8237A3FC:
	// addi r3,r27,772
	ctx.r3.s64 = r27.s64 + 772;
	// bl 0x82375d90
	ctx.lr = 0x8237A404;
	sub_82375D90(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237a414
	if (!cr6.eq) goto loc_8237A414;
	// stfs f31,776(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r27.u32 + 776, temp.u32);
loc_8237A414:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8237A420"))) PPC_WEAK_FUNC(sub_8237A420);
PPC_FUNC_IMPL(__imp__sub_8237A420) {
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
	ctx.lr = 0x8237A428;
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
	// li r28,0
	r28.s64 = 0;
	// lis r11,16383
	r11.s64 = 1073676288;
	// li r29,-1
	r29.s64 = -1;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// ori r30,r11,65535
	r30.u64 = r11.u64 | 65535;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// rlwinm r3,r4,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
	// stw r28,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r28.u32);
	// stw r28,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r28.u32);
	// beq cr6,0x8237a47c
	if (cr6.eq) goto loc_8237A47C;
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// ble cr6,0x8237a470
	if (!cr6.gt) goto loc_8237A470;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8237A470:
	// bl 0x82130528
	ctx.lr = 0x8237A474;
	sub_82130528(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// b 0x8237a4e4
	goto loc_8237A4E4;
loc_8237A47C:
	// cmplw cr6,r4,r30
	cr6.compare<uint32_t>(ctx.r4.u32, r30.u32, xer);
	// ble cr6,0x8237a488
	if (!cr6.gt) goto loc_8237A488;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8237A488:
	// bl 0x82130528
	ctx.lr = 0x8237A48C;
	sub_82130528(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8237a4a4
	if (!cr6.gt) goto loc_8237A4A4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8237A4A4:
	// bl 0x82130528
	ctx.lr = 0x8237A4A8;
	sub_82130528(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8237a4c0
	if (!cr6.gt) goto loc_8237A4C0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8237A4C0:
	// bl 0x82130528
	ctx.lr = 0x8237A4C4;
	sub_82130528(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8237a4dc
	if (!cr6.gt) goto loc_8237A4DC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8237A4DC:
	// bl 0x82130528
	ctx.lr = 0x8237A4E0;
	sub_82130528(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
loc_8237A4E4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x8237a4f8
	if (!cr6.gt) goto loc_8237A4F8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8237A4F8:
	// bl 0x82130528
	ctx.lr = 0x8237A4FC;
	sub_82130528(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// mr r11,r28
	r11.u64 = r28.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8237a534
	if (!cr6.gt) goto loc_8237A534;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// li r9,-1
	ctx.r9.s64 = -1;
loc_8237A518:
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r9,r10,r8
	PPC_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x8237a518
	if (cr6.lt) goto loc_8237A518;
loc_8237A534:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8237A540"))) PPC_WEAK_FUNC(sub_8237A540);
PPC_FUNC_IMPL(__imp__sub_8237A540) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8237A548;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// addi r30,r28,400
	r30.s64 = r28.s64 + 400;
	// lfs f31,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f31.f64 = double(temp.f32);
	// addi r31,r28,104
	r31.s64 = r28.s64 + 104;
	// lfs f30,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// li r29,19
	r29.s64 = 19;
	// li r26,0
	r26.s64 = 0;
loc_8237A57C:
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x8237A584;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8237a59c
	if (cr6.eq) goto loc_8237A59C;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8237a420
	ctx.lr = 0x8237A598;
	sub_8237A420(ctx, base);
	// b 0x8237a5a0
	goto loc_8237A5A0;
loc_8237A59C:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
loc_8237A5A0:
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stw r3,-384(r30)
	PPC_STORE_U32(r30.u32 + -384, ctx.r3.u32);
	// stfs f31,-8(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -8, temp.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stfs f31,-4(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -4, temp.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// stfs f31,0(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x8237a57c
	if (!cr0.eq) goto loc_8237A57C;
	// stw r26,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r26.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r26,8(r28)
	PPC_STORE_U32(r28.u32 + 8, r26.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8237A5E0"))) PPC_WEAK_FUNC(sub_8237A5E0);
PPC_FUNC_IMPL(__imp__sub_8237A5E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237A5F8"))) PPC_WEAK_FUNC(sub_8237A5F8);
PPC_FUNC_IMPL(__imp__sub_8237A5F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lwz r9,4(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stw r9,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r9.u32);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237A618"))) PPC_WEAK_FUNC(sub_8237A618);
PPC_FUNC_IMPL(__imp__sub_8237A618) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r7,r3,16
	ctx.r7.s64 = ctx.r3.s64 + 16;
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// li r5,19
	ctx.r5.s64 = 19;
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r6,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r6.u32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
loc_8237A638:
	// lwz r9,0(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8237a66c
	if (!cr6.gt) goto loc_8237A66C;
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
loc_8237A650:
	// lwz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r8,r4,r10
	PPC_STORE_U32(ctx.r4.u32 + ctx.r10.u32, ctx.r8.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8237a650
	if (cr6.lt) goto loc_8237A650;
loc_8237A66C:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// bne 0x8237a638
	if (!cr0.eq) goto loc_8237A638;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237A67C"))) PPC_WEAK_FUNC(sub_8237A67C);
PPC_FUNC_IMPL(__imp__sub_8237A67C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237A680"))) PPC_WEAK_FUNC(sub_8237A680);
PPC_FUNC_IMPL(__imp__sub_8237A680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,22080(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 22080);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237A698"))) PPC_WEAK_FUNC(sub_8237A698);
PPC_FUNC_IMPL(__imp__sub_8237A698) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCVRegister v56{};
	PPCVRegister v57{};
	PPCVRegister v58{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
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
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8237a714
	if (cr6.eq) goto loc_8237A714;
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237a758
	if (cr6.eq) goto loc_8237A758;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwzx r5,r10,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x821a1768
	ctx.lr = 0x8237A6D4;
	sub_821A1768(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// li r4,32
	ctx.r4.s64 = 32;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8237a798
	goto loc_8237A798;
loc_8237A714:
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237a758
	if (cr6.eq) goto loc_8237A758;
	// rlwinm r7,r5,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// lwzx r6,r7,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// lvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r6,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r6,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r6,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8237a798
	goto loc_8237A798;
loc_8237A758:
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
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237A798:
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

__attribute__((alias("__imp__sub_8237A7B0"))) PPC_WEAK_FUNC(sub_8237A7B0);
PPC_FUNC_IMPL(__imp__sub_8237A7B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237a7c8
	if (cr6.eq) goto loc_8237A7C8;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// blr 
	return;
loc_8237A7C8:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r3,r11,-31280
	ctx.r3.s64 = r11.s64 + -31280;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237A7D4"))) PPC_WEAK_FUNC(sub_8237A7D4);
PPC_FUNC_IMPL(__imp__sub_8237A7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237A7D8"))) PPC_WEAK_FUNC(sub_8237A7D8);
PPC_FUNC_IMPL(__imp__sub_8237A7D8) {
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
	ctx.lr = 0x8237A7E0;
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// stw r24,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r24.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r11,-12204
	ctx.r5.s64 = r11.s64 + -12204;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8237A810;
	sub_82137A08(ctx, base);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8237a824
	if (!cr6.eq) goto loc_8237A824;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8237A824:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82351ef8
	ctx.lr = 0x8237A834;
	sub_82351EF8(ctx, base);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8237a848
	if (!cr6.eq) goto loc_8237A848;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8237A848:
	// bl 0x823576f0
	ctx.lr = 0x8237A84C;
	sub_823576F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237a898
	if (cr6.eq) goto loc_8237A898;
loc_8237A858:
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x8237a898
	if (!cr6.lt) goto loc_8237A898;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stwx r11,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r11.u32);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r7.u32);
	// bl 0x82203148
	ctx.lr = 0x8237A888;
	sub_82203148(ctx, base);
	// bl 0x823576f0
	ctx.lr = 0x8237A88C;
	sub_823576F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237a858
	if (!cr6.eq) goto loc_8237A858;
loc_8237A898:
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r27,r24
	r27.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8237a8b0
	if (!cr6.eq) goto loc_8237A8B0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8237A8B0:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82351ef8
	ctx.lr = 0x8237A8C0;
	sub_82351EF8(ctx, base);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8237a8d4
	if (!cr6.eq) goto loc_8237A8D4;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8237A8D4:
	// bl 0x823576f0
	ctx.lr = 0x8237A8D8;
	sub_823576F0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8237a990
	if (cr6.eq) goto loc_8237A990;
	// mr r31,r24
	r31.u64 = r24.u64;
	// li r25,1
	r25.s64 = 1;
	// li r26,2
	r26.s64 = 2;
loc_8237A8F0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// bge cr6,0x8237a990
	if (!cr6.lt) goto loc_8237A990;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82203148
	ctx.lr = 0x8237A904;
	sub_82203148(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,6
	ctx.r5.s64 = 6;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x82357600
	ctx.lr = 0x8237A918;
	sub_82357600(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237a930
	if (cr6.eq) goto loc_8237A930;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// stwx r25,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r25.u32);
	// b 0x8237a968
	goto loc_8237A968;
loc_8237A930:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82203148
	ctx.lr = 0x8237A938;
	sub_82203148(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x82357600
	ctx.lr = 0x8237A94C;
	sub_82357600(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// beq cr6,0x8237a964
	if (cr6.eq) goto loc_8237A964;
	// stwx r26,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r26.u32);
	// b 0x8237a968
	goto loc_8237A968;
loc_8237A964:
	// stwx r24,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r24.u32);
loc_8237A968:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// stwx r29,r11,r31
	PPC_STORE_U32(r11.u32 + r31.u32, r29.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bl 0x82203148
	ctx.lr = 0x8237A980;
	sub_82203148(ctx, base);
	// bl 0x823576f0
	ctx.lr = 0x8237A984;
	sub_823576F0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8237a8f0
	if (!cr6.eq) goto loc_8237A8F0;
loc_8237A990:
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// mr r29,r24
	r29.u64 = r24.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8237a9a8
	if (!cr6.eq) goto loc_8237A9A8;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8237A9A8:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82351ef8
	ctx.lr = 0x8237A9B8;
	sub_82351EF8(ctx, base);
	// lwz r11,12(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x8237a9cc
	if (!cr6.eq) goto loc_8237A9CC;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
loc_8237A9CC:
	// bl 0x823576f0
	ctx.lr = 0x8237A9D0;
	sub_823576F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237aa14
	if (cr6.eq) goto loc_8237AA14;
	// mr r31,r24
	r31.u64 = r24.u64;
loc_8237A9E0:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// bge cr6,0x8237aa14
	if (!cr6.lt) goto loc_8237AA14;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwx r11,r10,r31
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, r11.u32);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bl 0x82203148
	ctx.lr = 0x8237AA04;
	sub_82203148(ctx, base);
	// bl 0x823576f0
	ctx.lr = 0x8237AA08;
	sub_823576F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237a9e0
	if (!cr6.eq) goto loc_8237A9E0;
loc_8237AA14:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8237AA1C"))) PPC_WEAK_FUNC(sub_8237AA1C);
PPC_FUNC_IMPL(__imp__sub_8237AA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237AA20"))) PPC_WEAK_FUNC(sub_8237AA20);
PPC_FUNC_IMPL(__imp__sub_8237AA20) {
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
	ctx.lr = 0x8237AA28;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// addi r5,r11,-12204
	ctx.r5.s64 = r11.s64 + -12204;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8237AA54;
	sub_82137A08(ctx, base);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82323318
	ctx.lr = 0x8237AA68;
	sub_82323318(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8237aab4
	if (cr6.eq) goto loc_8237AAB4;
loc_8237AA70:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8237aab4
	if (!cr6.lt) goto loc_8237AAB4;
	// lhz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 20);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r10,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r10.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// bl 0x82323318
	ctx.lr = 0x8237AAAC;
	sub_82323318(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8237aa70
	if (!cr6.eq) goto loc_8237AA70;
loc_8237AAB4:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8237AABC"))) PPC_WEAK_FUNC(sub_8237AABC);
PPC_FUNC_IMPL(__imp__sub_8237AABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237AAC0"))) PPC_WEAK_FUNC(sub_8237AAC0);
PPC_FUNC_IMPL(__imp__sub_8237AAC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8237AAC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,16
	r29.s64 = ctx.r3.s64 + 16;
	// li r28,19
	r28.s64 = 19;
	// li r30,0
	r30.s64 = 0;
loc_8237AAD8:
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8237ab34
	if (cr6.eq) goto loc_8237AB34;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// bl 0x82130588
	ctx.lr = 0x8237AAEC;
	sub_82130588(ctx, base);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x82130588
	ctx.lr = 0x8237AAF8;
	sub_82130588(ctx, base);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x8237AB04;
	sub_82130588(ctx, base);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130588
	ctx.lr = 0x8237AB10;
	sub_82130588(ctx, base);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x8237AB1C;
	sub_82130588(ctx, base);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x8237AB28;
	sub_82130588(ctx, base);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x8237AB34;
	sub_82130588(ctx, base);
loc_8237AB34:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x8237aad8
	if (!cr0.eq) goto loc_8237AAD8;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8237AB48"))) PPC_WEAK_FUNC(sub_8237AB48);
PPC_FUNC_IMPL(__imp__sub_8237AB48) {
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
	ctx.lr = 0x8237AB50;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r9,30344
	r29.s64 = ctx.r9.s64 + 30344;
	// addi r28,r10,-22940
	r28.s64 = ctx.r10.s64 + -22940;
	// addi r30,r11,30264
	r30.s64 = r11.s64 + 30264;
loc_8237AB74:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwzx r6,r31,r30
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8237AB88;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// add r6,r31,r29
	ctx.r6.u64 = r31.u64 + r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824df200
	ctx.lr = 0x8237ABA4;
	sub_824DF200(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r31,76
	cr6.compare<int32_t>(r31.s32, 76, xer);
	// blt cr6,0x8237ab74
	if (cr6.lt) goto loc_8237AB74;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r31,0
	r31.s64 = 0;
	// addi r29,r10,30424
	r29.s64 = ctx.r10.s64 + 30424;
	// addi r28,r11,-22960
	r28.s64 = r11.s64 + -22960;
loc_8237ABC4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwzx r6,r31,r30
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + r30.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x8237ABD8;
	sub_82137A08(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// add r6,r31,r29
	ctx.r6.u64 = r31.u64 + r29.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x824df200
	ctx.lr = 0x8237ABF4;
	sub_824DF200(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r31,76
	cr6.compare<int32_t>(r31.s32, 76, xer);
	// blt cr6,0x8237abc4
	if (cr6.lt) goto loc_8237ABC4;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8237AC08"))) PPC_WEAK_FUNC(sub_8237AC08);
PPC_FUNC_IMPL(__imp__sub_8237AC08) {
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
	ctx.lr = 0x8237AC10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r29,16
	r30.s64 = r29.s64 + 16;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r28,r11,30264
	r28.s64 = r11.s64 + 30264;
	// mr r31,r28
	r31.u64 = r28.u64;
	// beq cr6,0x8237ac60
	if (cr6.eq) goto loc_8237AC60;
loc_8237AC34:
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8237a7d8
	ctx.lr = 0x8237AC44;
	sub_8237A7D8(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r28,76
	r11.s64 = r28.s64 + 76;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8237ac34
	if (cr6.lt) goto loc_8237AC34;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8237AC60:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x8237aa20
	ctx.lr = 0x8237AC74;
	sub_8237AA20(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// addi r11,r28,76
	r11.s64 = r28.s64 + 76;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x8237ac60
	if (cr6.lt) goto loc_8237AC60;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8237AC90"))) PPC_WEAK_FUNC(sub_8237AC90);
PPC_FUNC_IMPL(__imp__sub_8237AC90) {
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
	PPCRegister f0{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8237AC98;
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -176, f29.u64);
	// stfd f30,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// addi r12,r1,-176
	r12.s64 = ctx.r1.s64 + -176;
	// bl 0x823dd52c
	ctx.lr = 0x8237ACAC;
	// stwu r1,-720(r1)
	ea = -720 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32112
	r30.s64 = -2104492032;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8237ACD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,21664(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 21664);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// std r9,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lwz r3,44(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8237AD04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// vspltisw128 v125,0
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// std r6,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f11,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vupkd3d128 v123,v125,4
	temp.f32 = 3.0f;
	temp.s32 += v125.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v125.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v123 = vTemp;
	// lvlx128 v63,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvlx128 v60,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vrlimi128 v62,v61,7,0
	simde_mm_store_ps(v62.f32, simde_mm_blend_ps(simde_mm_load_ps(v62.f32), simde_mm_permute_ps(simde_mm_load_ps(v61.f32), 228), 7));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vspltw128 v126,v123,3
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), 0x0));
	// clrlwi r14,r31,24
	r14.u64 = r31.u32 & 0xFF;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// stw r14,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r14.u32);
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// vrlimi128 v59,v62,11,0
	simde_mm_store_ps(v59.f32, simde_mm_blend_ps(simde_mm_load_ps(v59.f32), simde_mm_permute_ps(simde_mm_load_ps(v62.f32), 228), 11));
	// addi r23,r11,-7476
	r23.s64 = r11.s64 + -7476;
	// vor128 v13,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// vrefp128 v0,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(v59.f32)));
	// vor128 v58,v0,v0
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vnmsubfp128 v13,v58,v59,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v0,v0,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8237adb4
	if (cr6.eq) goto loc_8237ADB4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r11,-7460
	ctx.r9.s64 = r11.s64 + -7460;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,-7460(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -7460);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v56,v0,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8237add8
	goto loc_8237ADD8;
loc_8237ADB4:
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v54,v0,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237ADD8:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237ae60
	if (cr6.eq) goto loc_8237AE60;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r8,r10,-16
	ctx.r8.s64 = ctx.r10.s64 + -16;
	// bne cr6,0x8237adfc
	if (!cr6.eq) goto loc_8237ADFC;
	// li r8,0
	ctx.r8.s64 = 0;
loc_8237ADFC:
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// lwz r9,-8968(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8968);
	// subf r8,r8,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r8.s64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r9,r7,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bne cr6,0x8237ae24
	if (!cr6.eq) goto loc_8237AE24;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237AE24:
	// lbz r10,6482(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6482);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// stb r7,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r7.u8);
	// bne cr6,0x8237ae48
	if (!cr6.eq) goto loc_8237AE48;
	// li r11,0
	r11.s64 = 0;
loc_8237AE48:
	// lbz r11,6483(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 6483);
	// li r10,1
	ctx.r10.s64 = 1;
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// stb r10,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r10.u8);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r7,98(r1)
	PPC_STORE_U8(ctx.r1.u32 + 98, ctx.r7.u8);
loc_8237AE60:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// clrlwi r22,r9,24
	r22.u64 = ctx.r9.u32 & 0xFF;
	// addi r11,r11,30344
	r11.s64 = r11.s64 + 30344;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8237ae7c
	if (cr6.eq) goto loc_8237AE7C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r11,r11,30424
	r11.s64 = r11.s64 + 30424;
loc_8237AE7C:
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// lfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f31.f64 = double(temp.f32);
	// mr r17,r11
	r17.u64 = r11.u64;
	// lfs f30,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f30.f64 = double(temp.f32);
	// li r9,112
	ctx.r9.s64 = 112;
	// li r8,19
	ctx.r8.s64 = 19;
	// addi r31,r26,16
	r31.s64 = r26.s64 + 16;
	// lwz r11,-26876(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -26876);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r16,r26,96
	r16.s64 = r26.s64 + 96;
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// lis r25,-32130
	r25.s64 = -2105671680;
	// lis r24,-32130
	r24.s64 = -2105671680;
	// lis r18,1024
	r18.s64 = 67108864;
	// lvx128 v124,r11,r9
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lfs f29,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lis r27,-32130
	r27.s64 = -2105671680;
	// lis r19,-32119
	r19.s64 = -2104950784;
	// addi r15,r11,-22976
	r15.s64 = r11.s64 + -22976;
loc_8237AECC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// lwz r21,4(r11)
	r21.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821d2398
	ctx.lr = 0x8237AEE0;
	sub_821D2398(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x8237b180
	if (!cr6.gt) goto loc_8237B180;
	// addi r20,r31,384
	r20.s64 = r31.s64 + 384;
	// li r29,0
	r29.s64 = 0;
loc_8237AEF4:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237af20
	if (cr6.eq) goto loc_8237AF20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,32
	ctx.r10.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r29.u32);
	// lvx128 v61,r7,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r7,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8237afb4
	goto loc_8237AFB4;
loc_8237AF20:
	// lwz r11,22080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r10,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// bl 0x8237a698
	ctx.lr = 0x8237AF40;
	sub_8237A698(ctx, base);
	// lwz r11,22080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// addi r30,r3,48
	r30.s64 = ctx.r3.s64 + 48;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r8,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r26.u32);
	// bl 0x8237a698
	ctx.lr = 0x8237AF64;
	sub_8237A698(ctx, base);
	// lwz r11,22080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// addi r14,r3,32
	r14.s64 = ctx.r3.s64 + 32;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r6,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + r26.u32);
	// bl 0x8237a698
	ctx.lr = 0x8237AF88;
	sub_8237A698(ctx, base);
	// lwz r11,22080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r1,400
	ctx.r3.s64 = ctx.r1.s64 + 400;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r10,r26
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// bl 0x8237a698
	ctx.lr = 0x8237AFA8;
	sub_8237A698(ctx, base);
	// lvx128 v61,r0,r14
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r14.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r14,144(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237AFB4:
	// lvlx128 v53,r0,r17
	temp.u32 = r17.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v52,r0,r20
	temp.u32 = r20.u32;
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v51,v53,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// vspltw128 v50,v52,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), 0xFF));
	// lvx128 v60,r0,r15
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r15.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v50,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_mul_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v51.f32)));
	// vcmpgefp128. v49,v60,v59
	simde_mm_store_ps(v49.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v59.f32)));
	cr6.setFromMask(simde_mm_load_ps(v49.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8237b170
	if (!cr6.eq) goto loc_8237B170;
	// vsubfp128 v48,v62,v124
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v124.f32)));
	// vspltisw128 v47,1
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_set1_epi32(int(0x1)));
	// vor128 v13,v126,v126
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v126.u8));
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// vcuxwfp128 v46,v47,1
	simde_mm_store_ps(v46.f32, simde_mm_mul_ps(simde_mm_cvtepu32_ps_(simde_mm_load_si128((simde__m128i*)v47.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3F000000)))));
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// vmsum3fp128 v45,v48,v48
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v48.f32), 0xEF));
	// vrsqrtefp128 v0,v45
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v45.f32))));
	// vmulfp128 v44,v0,v0
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v12,v46,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp128 v13,v45,v44,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v44.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v11,v13,v12,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v63,v48,v11
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(ctx.v11.f32)));
	// bne cr6,0x8237b024
	if (!cr6.eq) goto loc_8237B024;
	// li r11,0
	r11.s64 = 0;
	// b 0x8237b028
	goto loc_8237B028;
loc_8237B024:
	// lwzx r11,r29,r11
	r11.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
loc_8237B028:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8237b044
	if (cr6.eq) goto loc_8237B044;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lbzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8237b170
	if (cr6.eq) goto loc_8237B170;
loc_8237B044:
	// vmsum3fp128 v43,v63,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// vmaxfp128 v42,v43,v125
	simde_mm_store_ps(v42.f32, simde_mm_max_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v125.f32)));
	// vminfp128 v41,v42,v126
	simde_mm_store_ps(v41.f32, simde_mm_min_ps(simde_mm_load_ps(v42.f32), simde_mm_load_ps(v126.f32)));
	// vmulfp128 v127,v41,v59
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v59.f32)));
	// vcmpgtfp128. v40,v127,v60
	simde_mm_store_ps(v40.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v40.f32), 0xF);
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mfocrf r10,2
	ctx.r10.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8237b170
	if (cr6.eq) goto loc_8237B170;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lwz r4,22080(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 22080);
	// li r7,2
	ctx.r7.s64 = 2;
	// lwz r3,-17628(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -17628);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// fmr f1,f29
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f1.f64 = f29.f64;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82175f20
	ctx.lr = 0x8237B090;
	sub_82175F20(ctx, base);
	// rlwinm r10,r3,0,5,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x4000000;
	// cmpw cr6,r10,r18
	cr6.compare<int32_t>(ctx.r10.s32, r18.s32, xer);
	// beq cr6,0x8237b0b0
	if (cr6.eq) goto loc_8237B0B0;
	// rlwinm r11,r3,0,3,3
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x10000000;
	// lis r10,4096
	ctx.r10.s64 = 268435456;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8237b0b4
	if (!cr6.eq) goto loc_8237B0B4;
loc_8237B0B0:
	// li r11,0
	r11.s64 = 0;
loc_8237B0B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237b170
	if (cr6.eq) goto loc_8237B170;
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// bne cr6,0x8237b128
	if (!cr6.eq) goto loc_8237B128;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f11,0(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// cntlzw r6,r22
	ctx.r6.u64 = r22.u32 == 0 ? 32 : __builtin_clz(r22.u32);
	// lfs f0,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	f0.f64 = double(temp.f32);
	// lfs f13,8500(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 8500);
	ctx.f13.f64 = double(temp.f32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f12,8496(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 8496);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r10,r6,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// add r8,r29,r8
	ctx.r8.u64 = r29.u64 + ctx.r8.u64;
	// lvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// fmuls f2,f0,f13
	ctx.f2.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lwz r30,8(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// fmuls f1,f0,f12
	ctx.f1.f64 = double(float(f0.f64 * ctx.f12.f64));
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x822fc250
	ctx.lr = 0x8237B120;
	sub_822FC250(ctx, base);
	// stwx r3,r29,r30
	PPC_STORE_U32(r29.u32 + r30.u32, ctx.r3.u32);
	// b 0x8237b170
	goto loc_8237B170;
loc_8237B128:
	// bl 0x822f1190
	ctx.lr = 0x8237B12C;
	sub_822F1190(ctx, base);
	// addi r11,r1,148
	r11.s64 = ctx.r1.s64 + 148;
	// stfs f1,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f30,112(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vpermwi128 v39,v123,187
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), 0x44));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lvlx128 v38,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v37,v38,0
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), 0xFF));
	// vmulfp128 v36,v127,v37
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v37.f32)));
	// lvx128 v35,r0,r10
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v1,v35,v39
	simde_mm_store_ps(ctx.v1.f32, simde_mm_sub_ps(simde_mm_load_ps(v35.f32), simde_mm_load_ps(v39.f32)));
	// stvx128 v36,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822fb508
	ctx.lr = 0x8237B170;
	sub_822FB508(ctx, base);
loc_8237B170:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r21
	cr6.compare<int32_t>(r28.s32, r21.s32, xer);
	// blt cr6,0x8237aef4
	if (cr6.lt) goto loc_8237AEF4;
loc_8237B180:
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r16,r16,16
	r16.s64 = r16.s64 + 16;
	// addi r17,r17,4
	r17.s64 = r17.s64 + 4;
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// bne 0x8237aecc
	if (!cr0.eq) goto loc_8237AECC;
	// addi r1,r1,720
	ctx.r1.s64 = ctx.r1.s64 + 720;
	// addi r12,r1,-176
	r12.s64 = ctx.r1.s64 + -176;
	// bl 0x823dd7c4
	ctx.lr = 0x8237B1A8;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8237B1B8"))) PPC_WEAK_FUNC(sub_8237B1B8);
PPC_FUNC_IMPL(__imp__sub_8237B1B8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r31,r11,-22900
	r31.s64 = r11.s64 + -22900;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824df990
	ctx.lr = 0x8237B1E4;
	sub_824DF990(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8237ab48
	ctx.lr = 0x8237B1EC;
	sub_8237AB48(ctx, base);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r30,r10,30576
	r30.s64 = ctx.r10.s64 + 30576;
	// addi r4,r9,-2648
	ctx.r4.s64 = ctx.r9.s64 + -2648;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ca540
	ctx.lr = 0x8237B204;
	sub_821CA540(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,-22924
	ctx.r4.s64 = ctx.r8.s64 + -22924;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e0288
	ctx.lr = 0x8237B218;
	sub_824E0288(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8237B220;
	sub_821C9A90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824dfa38
	ctx.lr = 0x8237B228;
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

__attribute__((alias("__imp__sub_8237B240"))) PPC_WEAK_FUNC(sub_8237B240);
PPC_FUNC_IMPL(__imp__sub_8237B240) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,36(r11)
	PPC_STORE_U32(r11.u32 + 36, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237B260"))) PPC_WEAK_FUNC(sub_8237B260);
PPC_FUNC_IMPL(__imp__sub_8237B260) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	ctx.lr = 0x8237B268;
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -176, f29.u64);
	// stfd f30,-168(r1)
	PPC_STORE_U64(ctx.r1.u32 + -168, f30.u64);
	// stfd f31,-160(r1)
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32124
	r31.s64 = -2105278464;
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// li r27,16
	r27.s64 = 16;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// li r28,32
	r28.s64 = 32;
	// lwz r10,-26876(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -26876);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,48
	r29.s64 = 48;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// clrlwi r26,r4,24
	r26.u64 = ctx.r4.u32 & 0xFF;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r24,-32124
	r24.s64 = -2105278464;
	// lvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r25,-32119
	r25.s64 = -2104950784;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r19,r10
	r19.u64 = ctx.r10.u64;
	// lvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,3796(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lfs f29,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f29.f64 = double(temp.f32);
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8237b450
	if (cr6.eq) goto loc_8237B450;
	// lwz r11,-8096(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -8096);
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// li r9,9
	ctx.r9.s64 = 9;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r6,r19,320
	ctx.r6.s64 = r19.s64 + 320;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r5,-8088(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8088);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8237B314;
	sub_8218A6E0(ctx, base);
	// lwz r3,-25232(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -25232);
	// lis r7,-32119
	ctx.r7.s64 = -2104950784;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,-8100(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8100);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,60(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8237B348;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// li r8,0
	ctx.r8.s64 = 0;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82178370
	ctx.lr = 0x8237B364;
	sub_82178370(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f29.f64;
	// lis r24,-32119
	r24.s64 = -2104950784;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,30508(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30508);
	// lwz r6,30504(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 30504);
	// lwz r3,-8092(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -8092);
	// bl 0x8217d120
	ctx.lr = 0x8237B390;
	sub_8217D120(ctx, base);
	// lfs f2,128(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 128);
	ctx.f2.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fneg f1,f2
	ctx.f1.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r3,-8092(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -8092);
	// fmr f3,f2
	ctx.f3.f64 = ctx.f2.f64;
	// lfs f6,12880(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12880);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,11360(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	ctx.f5.f64 = double(temp.f32);
	// fmr f4,f1
	ctx.f4.f64 = ctx.f1.f64;
	// bl 0x8217cc80
	ctx.lr = 0x8237B3B8;
	sub_8217CC80(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-8092(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -8092);
	// bl 0x8217c658
	ctx.lr = 0x8237B3C4;
	sub_8217C658(ctx, base);
	// addi r11,r30,64
	r11.s64 = r30.s64 + 64;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v58,r11,r27
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821b9c70
	ctx.lr = 0x8237B400;
	sub_821B9C70(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r3,-26876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -26876);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// lfs f0,27640(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	f0.f64 = double(temp.f32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvlx128 v55,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// lvx128 v13,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v11,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217ce80
	ctx.lr = 0x8237B440;
	sub_8217CE80(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x8237B448;
	sub_82190870(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82187be0
	ctx.lr = 0x8237B450;
	sub_82187BE0(ctx, base);
loc_8237B450:
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217fed0
	ctx.lr = 0x8237B458;
	sub_8217FED0(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217fed0
	ctx.lr = 0x8237B464;
	sub_8217FED0(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217fed0
	ctx.lr = 0x8237B470;
	sub_8217FED0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,7
	ctx.r3.s64 = 7;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r22,r10,1
	r22.u64 = ctx.r10.u64 ^ 1;
	// bl 0x8217fed0
	ctx.lr = 0x8237B484;
	sub_8217FED0(ctx, base);
	// cntlzw r9,r3
	ctx.r9.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,11
	ctx.r3.s64 = 11;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r21,r8,1
	r21.u64 = ctx.r8.u64 ^ 1;
	// bl 0x8217fed0
	ctx.lr = 0x8237B498;
	sub_8217FED0(ctx, base);
	// cntlzw r7,r3
	ctx.r7.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// xori r20,r6,1
	r20.u64 = ctx.r6.u64 ^ 1;
	// bl 0x8217fed0
	ctx.lr = 0x8237B4AC;
	sub_8217FED0(ctx, base);
	// lwz r11,-26876(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -26876);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// cntlzw r7,r3
	ctx.r7.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,15
	ctx.r4.s64 = 15;
	// stvx128 v54,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lvx128 v53,r11,r27
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,16
	ctx.r3.s64 = 16;
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r11,r28
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r11,r29
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// xori r29,r6,1
	r29.u64 = ctx.r6.u64 ^ 1;
	// stvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217f768
	ctx.lr = 0x8237B4F8;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x8237B504;
	sub_8217F768(ctx, base);
	// lis r5,-32124
	ctx.r5.s64 = -2105278464;
	// lwz r3,-25360(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -25360);
	// bl 0x8217d9a0
	ctx.lr = 0x8237B510;
	sub_8217D9A0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8237B51C;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8237B528;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x8237B534;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x8237B540;
	sub_8217F768(ctx, base);
	// addi r4,r30,64
	ctx.r4.s64 = r30.s64 + 64;
	// lwz r3,-26876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8237B54C;
	sub_8217C088(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// mr r30,r28
	r30.u64 = r28.u64;
	// beq cr6,0x8237b588
	if (cr6.eq) goto loc_8237B588;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,-8096(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -8096);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82187f40
	ctx.lr = 0x8237B570;
	sub_82187F40(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8237b588
	if (cr6.eq) goto loc_8237B588;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-8096(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -8096);
	// bl 0x82187b88
	ctx.lr = 0x8237B588;
	sub_82187B88(ctx, base);
loc_8237B588:
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,4
	ctx.r3.s64 = 4;
	// bl 0x8217bb68
	ctx.lr = 0x8237B594;
	sub_8217BB68(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r27,-32124
	r27.s64 = -2105278464;
	// fmr f5,f30
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = f30.f64;
	// lis r18,-32124
	r18.s64 = -2105278464;
	// fmr f4,f30
	ctx.f4.f64 = f30.f64;
	// lis r17,-32124
	r17.s64 = -2105278464;
	// lis r16,-32124
	r16.s64 = -2105278464;
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// lfs f31,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmr f6,f31
	ctx.f6.f64 = f31.f64;
	// ori r9,r9,65280
	ctx.r9.u64 = ctx.r9.u64 | 65280;
	// stfs f30,-26928(r18)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r18.u32 + -26928, temp.u32);
	// stfs f30,-26908(r17)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r17.u32 + -26908, temp.u32);
	// lis r15,-32124
	r15.s64 = -2105278464;
	// stfs f31,-26896(r16)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r16.u32 + -26896, temp.u32);
	// stw r9,-26892(r27)
	PPC_STORE_U32(r27.u32 + -26892, ctx.r9.u32);
	// lis r14,-32124
	r14.s64 = -2105278464;
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f30,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f30.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f8,-26924(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8237B5F8;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + -26892);
	// lfs f6,-26896(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r16.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f5,-26908(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f4,-26928(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// lfs f8,-26924(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8237B620;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + -26892);
	// lfs f6,-26896(r16)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r16.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,-26908(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f4,-26928(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// lfs f8,-26924(r15)
	temp.u32 = PPC_LOAD_U32(r15.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lfs f7,-26916(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8237B648;
	sub_8217BC28(ctx, base);
	// lwz r9,-26892(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + -26892);
	// lfs f8,-26924(r15)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r15.u32 + -26924);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,-26916(r14)
	temp.u32 = PPC_LOAD_U32(r14.u32 + -26916);
	ctx.f7.f64 = double(temp.f32);
	// fmr f3,f30
	ctx.f3.f64 = f30.f64;
	// lfs f6,-26896(r16)
	temp.u32 = PPC_LOAD_U32(r16.u32 + -26896);
	ctx.f6.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// lfs f5,-26908(r17)
	temp.u32 = PPC_LOAD_U32(r17.u32 + -26908);
	ctx.f5.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lfs f4,-26928(r18)
	temp.u32 = PPC_LOAD_U32(r18.u32 + -26928);
	ctx.f4.f64 = double(temp.f32);
	// bl 0x8217bc28
	ctx.lr = 0x8237B670;
	sub_8217BC28(ctx, base);
	// bl 0x8217bc98
	ctx.lr = 0x8237B674;
	sub_8217BC98(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8237b6e8
	if (cr6.eq) goto loc_8237B6E8;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8237b694
	if (cr6.eq) goto loc_8237B694;
	// lwz r3,-8096(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -8096);
	// bl 0x82187ba8
	ctx.lr = 0x8237B68C;
	sub_82187BA8(ctx, base);
	// lwz r3,-8096(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -8096);
	// bl 0x82187bd0
	ctx.lr = 0x8237B694;
	sub_82187BD0(ctx, base);
loc_8237B694:
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r28.u32);
	// lis r10,-32124
	ctx.r10.s64 = -2105278464;
	// li r11,1
	r11.s64 = 1;
	// stfs f29,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r9,-256
	ctx.r9.s64 = -16777216;
	// stfs f29,116(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stb r28,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r28.u8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// stb r11,135(r1)
	PPC_STORE_U8(ctx.r1.u32 + 135, r11.u8);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r3,-25232(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -25232);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r9.u32);
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// stb r28,134(r1)
	PPC_STORE_U8(ctx.r1.u32 + 134, r28.u8);
	// stb r11,136(r1)
	PPC_STORE_U8(ctx.r1.u32 + 136, r11.u8);
	// stb r28,133(r1)
	PPC_STORE_U8(ctx.r1.u32 + 133, r28.u8);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8237B6E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8237B6E8:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x8217c658
	ctx.lr = 0x8237B6F4;
	sub_8217C658(ctx, base);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lwz r3,-26876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -26876);
	// bl 0x8217ce80
	ctx.lr = 0x8237B700;
	sub_8217CE80(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8217f768
	ctx.lr = 0x8237B70C;
	sub_8217F768(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8217f768
	ctx.lr = 0x8237B718;
	sub_8217F768(ctx, base);
	// clrlwi r4,r22,24
	ctx.r4.u64 = r22.u32 & 0xFF;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8237B724;
	sub_8217F768(ctx, base);
	// clrlwi r4,r21,24
	ctx.r4.u64 = r21.u32 & 0xFF;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8237B730;
	sub_8217F768(ctx, base);
	// clrlwi r4,r20,24
	ctx.r4.u64 = r20.u32 & 0xFF;
	// li r3,11
	ctx.r3.s64 = 11;
	// bl 0x8217f768
	ctx.lr = 0x8237B73C;
	sub_8217F768(ctx, base);
	// clrlwi r4,r29,24
	ctx.r4.u64 = r29.u32 & 0xFF;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x8217f768
	ctx.lr = 0x8237B748;
	sub_8217F768(ctx, base);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// lwz r3,-26876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -26876);
	// bl 0x8217c088
	ctx.lr = 0x8237B754;
	sub_8217C088(ctx, base);
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8237B768"))) PPC_WEAK_FUNC(sub_8237B768);
PPC_FUNC_IMPL(__imp__sub_8237B768) {
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
	// bl 0x823d91f4
	ctx.lr = 0x8237B770;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,0(r13)
	r29.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r28,72
	r28.s64 = 72;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lbzx r10,r28,r29
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8237b79c
	if (cr6.eq) goto loc_8237B79C;
	// addi r31,r11,272
	r31.s64 = r11.s64 + 272;
	// b 0x8237b7a4
	goto loc_8237B7A4;
loc_8237B79C:
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r31,r10,16
	r31.s64 = ctx.r10.s64 + 16;
loc_8237B7A4:
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x8237B7AC;
	sub_8255B9A8(ctx, base);
	// li r10,48
	ctx.r10.s64 = 48;
	// lbzx r9,r28,r29
	ctx.r9.u64 = PPC_LOAD_U8(r28.u32 + r29.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lwz r11,132(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r3,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,32
	ctx.r4.s64 = 32;
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,16
	ctx.r3.s64 = 16;
	// lvlx128 v58,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvlx128 v57,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lvlx128 v59,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v59,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// lvx128 v54,r31,r4
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvx128 v52,r31,r3
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v53.f32)));
	// vmulfp128 v62,v52,v56
	simde_mm_store_ps(v62.f32, simde_mm_mul_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v56.f32)));
	// vmulfp128 v63,v54,v55
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// beq cr6,0x8237b818
	if (cr6.eq) goto loc_8237B818;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x8237b820
	goto loc_8237B820;
loc_8237B818:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_8237B820:
	// lvx128 v51,r11,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// vaddfp128 v50,v51,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v61.f32)));
	// vaddfp128 v49,v50,v62
	simde_mm_store_ps(v49.f32, simde_mm_add_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v62.f32)));
	// vaddfp128 v48,v49,v63
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v48,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8237B840"))) PPC_WEAK_FUNC(sub_8237B840);
PPC_FUNC_IMPL(__imp__sub_8237B840) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8237B848;
	// li r12,-48
	r12.s64 = -48;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// li r30,16
	r30.s64 = 16;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r11,-7572(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// lvx128 v127,r11,r30
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8237b768
	ctx.lr = 0x8237B874;
	sub_8237B768(ctx, base);
	// lwz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x8237B880;
	sub_8255B9A8(ctx, base);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,12(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,132(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addi r29,r31,128
	r29.s64 = r31.s64 + 128;
	// lfs f0,27532(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27532);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,128(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x8237B8A4;
	sub_8255B9A8(ctx, base);
	// lvlx128 v63,r0,r29
	temp.u32 = r29.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// li r7,8
	ctx.r7.s64 = 8;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v61,v127,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvlx128 v60,r3,r7
	temp.u32 = ctx.r3.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lfs f0,-13148(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -13148);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvlx128 v58,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vmulfp128 v56,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v59.f32)));
	// lvx128 v55,r0,r4
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vmulfp128 v54,v56,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_mul_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v57.f32)));
	// vsubfp128 v53,v55,v54
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v54.f32)));
	// vaddfp128 v63,v127,v53
	simde_mm_store_ps(v63.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v53.f32)));
	// vsubfp128 v52,v63,v53
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v53.f32)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x8237B92C;
	sub_82202EC0(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f11,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f0,30512(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30512);
	f0.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v51,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vspltw128 v46,v51,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lvlx128 v50,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r31,64
	r11.s64 = r31.s64 + 64;
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// lvlx128 v49,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v47,r0,r3
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v43,v50,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), 0xFF));
	// lvx128 v44,r0,r8
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v42,v44,v46
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v46.f32)));
	// vmulfp128 v45,v47,v48
	simde_mm_store_ps(v45.f32, simde_mm_mul_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v48.f32)));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// stvx128 v42,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// addi r3,r5,2384
	ctx.r3.s64 = ctx.r5.s64 + 2384;
	// addi r8,r4,2352
	ctx.r8.s64 = ctx.r4.s64 + 2352;
	// lvx128 v41,r0,r6
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v40,v41,v43
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v43.f32)));
	// stvx128 v40,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v39,v45,v62
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvx128 v39,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v38,v42,v62
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvx128 v38,r31,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v37,v40,v62
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// stvx128 v37,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v36,v63,v62
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// vor128 v35,v61,v36
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v36.u8)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v35,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x821cec00
	ctx.lr = 0x8237BA04;
	sub_821CEC00(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-48
	r0.s64 = -48;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8237BA14"))) PPC_WEAK_FUNC(sub_8237BA14);
PPC_FUNC_IMPL(__imp__sub_8237BA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237BA18"))) PPC_WEAK_FUNC(sub_8237BA18);
PPC_FUNC_IMPL(__imp__sub_8237BA18) {
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
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
	// addi r4,r8,29632
	ctx.r4.s64 = ctx.r8.s64 + 29632;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// addi r3,r7,19856
	ctx.r3.s64 = ctx.r7.s64 + 19856;
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stb r11,32(r31)
	PPC_STORE_U8(r31.u32 + 32, r11.u8);
	// stb r11,33(r31)
	PPC_STORE_U8(r31.u32 + 33, r11.u8);
	// bl 0x82144a20
	ctx.lr = 0x8237BA70;
	sub_82144A20(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// addi r3,r6,-22260
	ctx.r3.s64 = ctx.r6.s64 + -22260;
	// bl 0x821380e0
	ctx.lr = 0x8237BA80;
	sub_821380E0(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lis r4,-32119
	ctx.r4.s64 = -2104950784;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,-12568(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + -12568);
	// stw r11,-8084(r4)
	PPC_STORE_U32(ctx.r4.u32 + -8084, r11.u32);
	// stw r11,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, r11.u32);
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

__attribute__((alias("__imp__sub_8237BAB0"))) PPC_WEAK_FUNC(sub_8237BAB0);
PPC_FUNC_IMPL(__imp__sub_8237BAB0) {
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
	ctx.lr = 0x8237BAB8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x8237badc
	if (cr6.eq) goto loc_8237BADC;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_8237BADC:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r30,r31,20
	r30.s64 = r31.s64 + 20;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8237baf4
	if (cr6.eq) goto loc_8237BAF4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8237BAF4;
	sub_8213C218(ctx, base);
loc_8237BAF4:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r11,0
	r11.s64 = 0;
	// li r4,255
	ctx.r4.s64 = 255;
	// lwz r10,-8084(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8084);
	// li r3,5
	ctx.r3.s64 = 5;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// lfs f13,-22264(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -22264);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
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
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// stb r4,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, ctx.r4.u8);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stb r3,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, ctx.r3.u8);
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// stw r5,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r5.u32);
	// lbz r11,0(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,-10432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10432);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// beq cr6,0x8237bbac
	if (cr6.eq) goto loc_8237BBAC;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825491f0
	ctx.lr = 0x8237BBA0;
	sub_825491F0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_8237BBAC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82549118
	ctx.lr = 0x8237BBB4;
	sub_82549118(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8237BBC0"))) PPC_WEAK_FUNC(sub_8237BBC0);
PPC_FUNC_IMPL(__imp__sub_8237BBC0) {
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
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// lwz r3,-10432(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10432);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,3796(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,135(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 135);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r11,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r11.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82549428
	ctx.lr = 0x8237BC18;
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

__attribute__((alias("__imp__sub_8237BC28"))) PPC_WEAK_FUNC(sub_8237BC28);
PPC_FUNC_IMPL(__imp__sub_8237BC28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r23{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8237BC30;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x8237bd94
	if (cr6.eq) goto loc_8237BD94;
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x8237bd94
	if (cr6.eq) goto loc_8237BD94;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8237bd94
	if (!cr6.eq) goto loc_8237BD94;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lwz r11,-8084(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8084);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237bd94
	if (!cr6.eq) goto loc_8237BD94;
	// li r5,255
	ctx.r5.s64 = 255;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,81
	ctx.r3.s64 = ctx.r1.s64 + 81;
	// bl 0x823d9890
	ctx.lr = 0x8237BC84;
	sub_823D9890(ctx, base);
	// cmplwi cr6,r30,5
	cr6.compare<uint32_t>(r30.u32, 5, xer);
	// bgt cr6,0x8237bd94
	if (cr6.gt) goto loc_8237BD94;
	// lis r12,-32200
	r12.s64 = -2110259200;
	// addi r12,r12,-17244
	r12.s64 = r12.s64 + -17244;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r30.u64) {
	case 0:
		goto loc_8237BCBC;
	case 1:
		goto loc_8237BCDC;
	case 2:
		goto loc_8237BCFC;
	case 3:
		goto loc_8237BD1C;
	case 4:
		goto loc_8237BD3C;
	case 5:
		goto loc_8237BD5C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-17220(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -17220);
	// lwz r17,-17188(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -17188);
	// lwz r17,-17156(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -17156);
	// lwz r17,-17124(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -17124);
	// lwz r17,-17092(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -17092);
	// lwz r17,-17060(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -17060);
loc_8237BCBC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r11,10
	ctx.r8.s64 = r11.s64 + 10;
	// addi r5,r9,-22196
	ctx.r5.s64 = ctx.r9.s64 + -22196;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// lwz r6,30556(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30556);
	// b 0x8237bd6c
	goto loc_8237BD6C;
loc_8237BCDC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r11,27
	ctx.r8.s64 = r11.s64 + 27;
	// addi r5,r9,-22204
	ctx.r5.s64 = ctx.r9.s64 + -22204;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// lwz r6,30556(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30556);
	// b 0x8237bd6c
	goto loc_8237BD6C;
loc_8237BCFC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r11,44
	ctx.r8.s64 = r11.s64 + 44;
	// addi r5,r9,-22212
	ctx.r5.s64 = ctx.r9.s64 + -22212;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// lwz r6,30556(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30556);
	// b 0x8237bd6c
	goto loc_8237BD6C;
loc_8237BD1C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r11,61
	ctx.r8.s64 = r11.s64 + 61;
	// addi r5,r9,-22220
	ctx.r5.s64 = ctx.r9.s64 + -22220;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// lwz r6,30556(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30556);
	// b 0x8237bd6c
	goto loc_8237BD6C;
loc_8237BD3C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// addi r8,r11,78
	ctx.r8.s64 = r11.s64 + 78;
	// addi r5,r9,-22228
	ctx.r5.s64 = ctx.r9.s64 + -22228;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// lwz r6,30556(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30556);
	// b 0x8237bd6c
	goto loc_8237BD6C;
loc_8237BD5C:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r5,r10,-22240
	ctx.r5.s64 = ctx.r10.s64 + -22240;
	// lwz r6,30556(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 30556);
loc_8237BD6C:
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x8237BD78;
	sub_82137A08(ctx, base);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821372f0
	ctx.lr = 0x8237BD84;
	sub_821372F0(ctx, base);
	// sth r3,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r3.u16);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-8084(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -8084);
	// bl 0x821374e0
	ctx.lr = 0x8237BD94;
	sub_821374E0(ctx, base);
loc_8237BD94:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8237BD9C"))) PPC_WEAK_FUNC(sub_8237BD9C);
PPC_FUNC_IMPL(__imp__sub_8237BD9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237BDA0"))) PPC_WEAK_FUNC(sub_8237BDA0);
PPC_FUNC_IMPL(__imp__sub_8237BDA0) {
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
	ctx.lr = 0x8237BDA8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,32(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237bdc8
	if (cr6.eq) goto loc_8237BDC8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8237be98
	if (cr6.eq) goto loc_8237BE98;
loc_8237BDC8:
	// li r30,1
	r30.s64 = 1;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,32(r31)
	PPC_STORE_U8(r31.u32 + 32, r30.u8);
	// lwz r4,1(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 1);
	// bl 0x8237bab0
	ctx.lr = 0x8237BDE0;
	sub_8237BAB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8237bdf8
	if (!cr6.eq) goto loc_8237BDF8;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
loc_8237BDF8:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// li r11,0
	r11.s64 = 0;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r30,255
	r30.s64 = 255;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// li r29,5
	r29.s64 = 5;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// lfs f13,-22264(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -22264);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r11,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r11.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// addi r5,r31,24
	ctx.r5.s64 = r31.s64 + 24;
	// stb r11,149(r1)
	PPC_STORE_U8(ctx.r1.u32 + 149, r11.u8);
	// lwz r11,-10432(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10432);
	// lwz r10,-8084(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + -8084);
	// stw r3,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r3.u32);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// stw r4,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r4.u32);
	// stb r30,148(r1)
	PPC_STORE_U8(ctx.r1.u32 + 148, r30.u8);
	// stb r29,150(r1)
	PPC_STORE_U8(ctx.r1.u32 + 150, r29.u8);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// lwz r4,9(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 9);
	// bl 0x825491f0
	ctx.lr = 0x8237BE98;
	sub_825491F0(ctx, base);
loc_8237BE98:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8237BEA0"))) PPC_WEAK_FUNC(sub_8237BEA0);
PPC_FUNC_IMPL(__imp__sub_8237BEA0) {
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
	// lbz r11,32(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237bf18
	if (cr6.eq) goto loc_8237BF18;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,19836
	ctx.r10.s64 = r11.s64 + 19836;
	// stb r30,32(r31)
	PPC_STORE_U8(r31.u32 + 32, r30.u8);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237bf14
	if (!cr6.eq) goto loc_8237BF14;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,5(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 5);
	// bl 0x8237bab0
	ctx.lr = 0x8237BEEC;
	sub_8237BAB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8237bf14
	if (cr6.eq) goto loc_8237BF14;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8237bf18
	if (cr6.eq) goto loc_8237BF18;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8237BF10;
	sub_8213C218(ctx, base);
	// b 0x8237bf18
	goto loc_8237BF18;
loc_8237BF14:
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
loc_8237BF18:
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

__attribute__((alias("__imp__sub_8237BF30"))) PPC_WEAK_FUNC(sub_8237BF30);
PPC_FUNC_IMPL(__imp__sub_8237BF30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r23{};
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
	ctx.lr = 0x8237BF38;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r29,-10432(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r4,65535
	cr6.compare<uint32_t>(ctx.r4.u32, 65535, xer);
	// lwz r27,136(r29)
	r27.u64 = PPC_LOAD_U32(r29.u32 + 136);
	// beq cr6,0x8237c064
	if (cr6.eq) goto loc_8237C064;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lwz r3,-8084(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8084);
	// bl 0x821375c8
	ctx.lr = 0x8237BF68;
	sub_821375C8(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8237c360
	if (cr6.gt) goto loc_8237C360;
	// lis r12,-32200
	r12.s64 = -2110259200;
	// addi r12,r12,-16504
	r12.s64 = r12.s64 + -16504;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8237BF98;
	case 1:
		goto loc_8237BFDC;
	case 2:
		goto loc_8237C000;
	case 3:
		goto loc_8237C01C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-16488(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -16488);
	// lwz r17,-16420(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -16420);
	// lwz r17,-16384(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -16384);
	// lwz r17,-16356(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -16356);
loc_8237BF98:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f31,20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	f31.f64 = double(temp.f32);
	// bl 0x821372d8
	ctx.lr = 0x8237BFAC;
	sub_821372D8(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-22056
	ctx.r3.s64 = ctx.r9.s64 + -22056;
	// bl 0x82130000
	ctx.lr = 0x8237BFC8;
	sub_82130000(ctx, base);
	// li r8,-1
	ctx.r8.s64 = -1;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237BFDC:
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// bl 0x821372d8
	ctx.lr = 0x8237BFE4;
	sub_821372D8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-22104
	ctx.r3.s64 = r11.s64 + -22104;
	// bl 0x82130000
	ctx.lr = 0x8237BFF4;
	sub_82130000(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C000:
	// li r11,-1
	r11.s64 = -1;
	// li r10,-1
	ctx.r10.s64 = -1;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C01C:
	// lwz r3,-8084(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8084);
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// bl 0x821374e0
	ctx.lr = 0x8237C028;
	sub_821374E0(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lhz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f31,20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	f31.f64 = double(temp.f32);
	// bl 0x821372d8
	ctx.lr = 0x8237C03C;
	sub_821372D8(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// stfd f1,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f1.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,-22168
	ctx.r3.s64 = ctx.r9.s64 + -22168;
	// bl 0x82130000
	ctx.lr = 0x8237C058;
	sub_82130000(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C064:
	// lbz r11,32(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237c138
	if (cr6.eq) goto loc_8237C138;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x8237c0a0
	if (cr6.lt) goto loc_8237C0A0;
	// beq cr6,0x8237c094
	if (cr6.eq) goto loc_8237C094;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8237c0dc
	if (!cr6.lt) goto loc_8237C0DC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bea0
	ctx.lr = 0x8237C090;
	sub_8237BEA0(ctx, base);
	// b 0x8237c0dc
	goto loc_8237C0DC;
loc_8237C094:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bda0
	ctx.lr = 0x8237C09C;
	sub_8237BDA0(ctx, base);
	// b 0x8237c0dc
	goto loc_8237C0DC;
loc_8237C0A0:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r28,r31,24
	r28.s64 = r31.s64 + 24;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237c0dc
	if (!cr6.eq) goto loc_8237C0DC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821e8080
	ctx.lr = 0x8237C0B8;
	sub_821E8080(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// lwz r11,-8084(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8084);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// lwz r4,9(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 9);
	// bl 0x825491f0
	ctx.lr = 0x8237C0DC;
	sub_825491F0(ctx, base);
loc_8237C0DC:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8237c0fc
	if (cr6.eq) goto loc_8237C0FC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8237C0EC;
	sub_823EAEF8(ctx, base);
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// beq cr6,0x8237c360
	if (cr6.eq) goto loc_8237C360;
loc_8237C0FC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bea0
	ctx.lr = 0x8237C104;
	sub_8237BEA0(ctx, base);
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325d30
	ctx.lr = 0x8237C10C;
	sub_82325D30(ctx, base);
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325d58
	ctx.lr = 0x8237C114;
	sub_82325D58(ctx, base);
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325d80
	ctx.lr = 0x8237C11C;
	sub_82325D80(ctx, base);
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325da8
	ctx.lr = 0x8237C124;
	sub_82325DA8(ctx, base);
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325dd0
	ctx.lr = 0x8237C12C;
	sub_82325DD0(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C138:
	// lbz r11,33(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 33);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237c1c0
	if (cr6.eq) goto loc_8237C1C0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// beq cr6,0x8237c360
	if (cr6.eq) goto loc_8237C360;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lwz r11,-8084(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -8084);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237c360
	if (!cr6.eq) goto loc_8237C360;
	// li r5,255
	ctx.r5.s64 = 255;
	// stb r11,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,161
	ctx.r3.s64 = ctx.r1.s64 + 161;
	// bl 0x823d9890
	ctx.lr = 0x8237C178;
	sub_823D9890(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r5,r9,-22240
	ctx.r5.s64 = ctx.r9.s64 + -22240;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r6,30556(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30556);
	// bl 0x82137a08
	ctx.lr = 0x8237C194;
	sub_82137A08(ctx, base);
	// li r8,5
	ctx.r8.s64 = 5;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// bl 0x821372f0
	ctx.lr = 0x8237C1A4;
	sub_821372F0(ctx, base);
	// sth r3,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r3.u16);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-8084(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8084);
	// bl 0x821374e0
	ctx.lr = 0x8237C1B4;
	sub_821374E0(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C1C0:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8237c360
	if (cr6.eq) goto loc_8237C360;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8237C1D0;
	sub_823EAEF8(ctx, base);
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x8237c208
	if (cr6.eq) goto loc_8237C208;
	// cmpwi cr6,r11,20
	cr6.compare<int32_t>(r11.s32, 20, xer);
	// beq cr6,0x8237c208
	if (cr6.eq) goto loc_8237C208;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8237C1F0;
	sub_823EAEF8(ctx, base);
	// lwz r3,72(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// bl 0x82337a48
	ctx.lr = 0x8237C1F8;
	sub_82337A48(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bc28
	ctx.lr = 0x8237C204;
	sub_8237BC28(ctx, base);
	// b 0x8237c290
	goto loc_8237C290;
loc_8237C208:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8237c290
	if (cr6.eq) goto loc_8237C290;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// bne cr6,0x8237c290
	if (!cr6.eq) goto loc_8237C290;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lwz r11,-8084(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8084);
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237c290
	if (!cr6.eq) goto loc_8237C290;
	// li r5,255
	ctx.r5.s64 = 255;
	// stb r11,160(r1)
	PPC_STORE_U8(ctx.r1.u32 + 160, r11.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,161
	ctx.r3.s64 = ctx.r1.s64 + 161;
	// bl 0x823d9890
	ctx.lr = 0x8237C248;
	sub_823D9890(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r9,r11,27
	ctx.r9.s64 = r11.s64 + 27;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r5,r8,-22204
	ctx.r5.s64 = ctx.r8.s64 + -22204;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r6,30556(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 30556);
	// bl 0x82137a08
	ctx.lr = 0x8237C270;
	sub_82137A08(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// stw r7,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r7.u32);
	// bl 0x821372f0
	ctx.lr = 0x8237C280;
	sub_821372F0(ctx, base);
	// sth r3,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r3.u16);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-8084(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -8084);
	// bl 0x821374e0
	ctx.lr = 0x8237C290;
	sub_821374E0(ctx, base);
loc_8237C290:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823eaef8
	ctx.lr = 0x8237C298;
	sub_823EAEF8(ctx, base);
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x8237c360
	if (!cr6.eq) goto loc_8237C360;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x8237c360
	if (cr6.gt) goto loc_8237C360;
	// lis r12,-32200
	r12.s64 = -2110259200;
	// addi r12,r12,-15668
	r12.s64 = r12.s64 + -15668;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8237C2E0;
	case 1:
		goto loc_8237C2FC;
	case 2:
		goto loc_8237C318;
	case 3:
		goto loc_8237C334;
	case 4:
		goto loc_8237C350;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-15648(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -15648);
	// lwz r17,-15620(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -15620);
	// lwz r17,-15592(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -15592);
	// lwz r17,-15564(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -15564);
	// lwz r17,-15536(r23)
	r17.u64 = PPC_LOAD_U32(r23.u32 + -15536);
loc_8237C2E0:
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325ae0
	ctx.lr = 0x8237C2E8;
	sub_82325AE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bda0
	ctx.lr = 0x8237C2F0;
	sub_8237BDA0(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C2FC:
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325b28
	ctx.lr = 0x8237C304;
	sub_82325B28(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bda0
	ctx.lr = 0x8237C30C;
	sub_8237BDA0(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C318:
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325b70
	ctx.lr = 0x8237C320;
	sub_82325B70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bda0
	ctx.lr = 0x8237C328;
	sub_8237BDA0(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C334:
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82325bb8
	ctx.lr = 0x8237C33C;
	sub_82325BB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bda0
	ctx.lr = 0x8237C344;
	sub_8237BDA0(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C350:
	// lwz r3,-10432(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10432);
	// bl 0x82329db8
	ctx.lr = 0x8237C358;
	sub_82329DB8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237bda0
	ctx.lr = 0x8237C360;
	sub_8237BDA0(ctx, base);
loc_8237C360:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8237C36C"))) PPC_WEAK_FUNC(sub_8237C36C);
PPC_FUNC_IMPL(__imp__sub_8237C36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237C370"))) PPC_WEAK_FUNC(sub_8237C370);
PPC_FUNC_IMPL(__imp__sub_8237C370) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lfs f13,-26928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -26928);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lfs f0,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stfs f13,60(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,56(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lis r31,-32254
	r31.s64 = -2113798144;
	// lfs f11,-21668(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21668);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stfs f11,68(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// lis r30,-32251
	r30.s64 = -2113601536;
	// lfs f12,-3072(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3072);
	ctx.f12.f64 = double(temp.f32);
	// li r7,10
	ctx.r7.s64 = 10;
	// stfs f12,64(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f11,-21672(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -21672);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,72(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f11,76(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f13,84(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lfs f13,-29232(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,88(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// lfs f12,30712(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 30712);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,92(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// lfs f13,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,-21676(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21676);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,20(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lfs f13,-6176(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + -6176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f12,-21680(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21680);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-21684(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -21684);
	ctx.f13.f64 = double(temp.f32);
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f0,8(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f13,44(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stw r7,96(r3)
	PPC_STORE_U32(ctx.r3.u32 + 96, ctx.r7.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237C45C"))) PPC_WEAK_FUNC(sub_8237C45C);
PPC_FUNC_IMPL(__imp__sub_8237C45C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237C460"))) PPC_WEAK_FUNC(sub_8237C460);
PPC_FUNC_IMPL(__imp__sub_8237C460) {
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
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,25
	r11.s64 = 25;
	// addi r9,r10,-21660
	ctx.r9.s64 = ctx.r10.s64 + -21660;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x82495cf0
	ctx.lr = 0x8237C49C;
	sub_82495CF0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f0,14988(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f12,27640(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27640);
	ctx.f12.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f13,11368(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lfs f11,-17424(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -17424);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,3732(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3732);
	ctx.f10.f64 = double(temp.f32);
	// stb r11,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r11.u8);
	// lfs f9,12428(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12428);
	ctx.f9.f64 = double(temp.f32);
	// stb r11,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r11.u8);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stb r11,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r11.u8);
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stb r11,37(r31)
	PPC_STORE_U8(r31.u32 + 37, r11.u8);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stb r10,36(r31)
	PPC_STORE_U8(r31.u32 + 36, ctx.r10.u8);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stw r9,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r9.u32);
	// stfs f11,44(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stfs f10,56(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f9,52(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// addi r3,r8,6612
	ctx.r3.s64 = ctx.r8.s64 + 6612;
	// stfs f13,48(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// bl 0x825f29b0
	ctx.lr = 0x8237C520;
	sub_825F29B0(ctx, base);
	// stw r3,100(r31)
	PPC_STORE_U32(r31.u32 + 100, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8237C540"))) PPC_WEAK_FUNC(sub_8237C540);
PPC_FUNC_IMPL(__imp__sub_8237C540) {
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
	ctx.lr = 0x8237C548;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,68(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x82387a18
	ctx.lr = 0x8237C55C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237c5a4
	if (cr6.eq) goto loc_8237C5A4;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237c5b4
	if (!cr6.eq) goto loc_8237C5B4;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lhz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// extsh r31,r10
	r31.s64 = ctx.r10.s16;
	// bl 0x8232a4b0
	ctx.lr = 0x8237C588;
	sub_8232A4B0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226ff18
	ctx.lr = 0x8237C59C;
	sub_8226FF18(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8237C5A4:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8232c080
	ctx.lr = 0x8237C5B4;
	sub_8232C080(ctx, base);
loc_8237C5B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8237C5BC"))) PPC_WEAK_FUNC(sub_8237C5BC);
PPC_FUNC_IMPL(__imp__sub_8237C5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237C5C0"))) PPC_WEAK_FUNC(sub_8237C5C0);
PPC_FUNC_IMPL(__imp__sub_8237C5C0) {
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
	ctx.lr = 0x8237C5C8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8237c5f4
	if (cr6.eq) goto loc_8237C5F4;
	// addi r27,r31,272
	r27.s64 = r31.s64 + 272;
	// b 0x8237c5fc
	goto loc_8237C5FC;
loc_8237C5F4:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r27,r11,16
	r27.s64 = r11.s64 + 16;
loc_8237C5FC:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8237c60c
	if (cr6.eq) goto loc_8237C60C;
	// addi r30,r29,272
	r30.s64 = r29.s64 + 272;
	// b 0x8237c614
	goto loc_8237C614;
loc_8237C60C:
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
loc_8237C614:
	// lis r26,-32119
	r26.s64 = -2104950784;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r11,-18004(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -18004);
	// lwz r4,36(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82747720
	ctx.lr = 0x8237C62C;
	sub_82747720(ctx, base);
	// lwz r11,-18004(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -18004);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r4,40(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// bl 0x82747720
	ctx.lr = 0x8237C640;
	sub_82747720(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,-18004(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -18004);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r10,r5,29736
	ctx.r10.s64 = ctx.r5.s64 + 29736;
	// lfs f13,14884(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f12,-31384(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31384);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x82748340
	ctx.lr = 0x8237C6BC;
	sub_82748340(ctx, base);
	// stw r3,40(r28)
	PPC_STORE_U32(r28.u32 + 40, ctx.r3.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8237C6C8"))) PPC_WEAK_FUNC(sub_8237C6C8);
PPC_FUNC_IMPL(__imp__sub_8237C6C8) {
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
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x8237c700
	if (cr6.eq) goto loc_8237C700;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-18004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -18004);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82747630
	ctx.lr = 0x8237C6F8;
	sub_82747630(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r10.u32);
loc_8237C700:
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

__attribute__((alias("__imp__sub_8237C714"))) PPC_WEAK_FUNC(sub_8237C714);
PPC_FUNC_IMPL(__imp__sub_8237C714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237C718"))) PPC_WEAK_FUNC(sub_8237C718);
PPC_FUNC_IMPL(__imp__sub_8237C718) {
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
	ctx.lr = 0x8237C720;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lfs f31,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f31.f64 = double(temp.f32);
	// bl 0x82332098
	ctx.lr = 0x8237C744;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// beq cr6,0x8237c798
	if (cr6.eq) goto loc_8237C798;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// beq cr6,0x8237c778
	if (cr6.eq) goto loc_8237C778;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x8237c7b0
	goto loc_8237C7B0;
loc_8237C778:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f12,31492(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31492);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x8237c7b4
	goto loc_8237C7B4;
loc_8237C798:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f13,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_8237C7B0:
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_8237C7B4:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// ble cr6,0x8237c84c
	if (!cr6.gt) goto loc_8237C84C;
	// cmpwi cr6,r11,21
	cr6.compare<int32_t>(r11.s32, 21, xer);
	// bge cr6,0x8237c84c
	if (!cr6.lt) goto loc_8237C84C;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r28,68(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r27,r9,29736
	r27.s64 = ctx.r9.s64 + 29736;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,-18004(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -18004);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,136(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// lwzx r9,r8,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + r27.u32);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82747650
	ctx.lr = 0x8237C804;
	sub_82747650(ctx, base);
	// stw r3,36(r28)
	PPC_STORE_U32(r28.u32 + 36, ctx.r3.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,128(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,-18004(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -18004);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,136(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r31,68(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwzx r9,r10,r27
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + r27.u32);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82747650
	ctx.lr = 0x8237C83C;
	sub_82747650(ctx, base);
	// stw r3,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r3.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_8237C84C:
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r9,128(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lwz r30,68(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r8,r8,29736
	ctx.r8.s64 = ctx.r8.s64 + 29736;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// lwz r11,-18004(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -18004);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r4,136(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 136);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwzx r9,r3,r8
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82747650
	ctx.lr = 0x8237C888;
	sub_82747650(ctx, base);
	// stw r3,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r3.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8237C898"))) PPC_WEAK_FUNC(sub_8237C898);
PPC_FUNC_IMPL(__imp__sub_8237C898) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,36(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 36);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237c940
	if (cr6.eq) goto loc_8237C940;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// li r8,0
	ctx.r8.s64 = 0;
	// bne cr6,0x8237c8e4
	if (!cr6.eq) goto loc_8237C8E4;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r7,r11,240
	ctx.r7.s64 = r11.s64 + 240;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lfs f13,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,31492(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31492);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8237c938
	goto loc_8237C938;
loc_8237C8E4:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// vupkd3d128 v61,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v61 = vTemp;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// vpermwi128 v60,v61,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// vpermwi128 v59,v61,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// lfs f13,-29232(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v58,v61,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
	// lfs f1,31492(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31492);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237C938:
	// fmuls f2,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(f0.f64 * ctx.f13.f64));
	// bl 0x82682590
	ctx.lr = 0x8237C940;
	sub_82682590(ctx, base);
loc_8237C940:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237C950"))) PPC_WEAK_FUNC(sub_8237C950);
PPC_FUNC_IMPL(__imp__sub_8237C950) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-21468
	ctx.r5.s64 = r11.s64 + -21468;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237C98C;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-21484
	ctx.r5.s64 = ctx.r10.s64 + -21484;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x8237C9AC;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-21496
	ctx.r5.s64 = ctx.r9.s64 + -21496;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x8237C9CC;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-21508
	ctx.r5.s64 = ctx.r8.s64 + -21508;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237C9EC;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-21520
	ctx.r5.s64 = ctx.r7.s64 + -21520;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,28
	ctx.r6.s64 = r31.s64 + 28;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237CA0C;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-21532
	ctx.r5.s64 = ctx.r6.s64 + -21532;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,36
	ctx.r6.s64 = r31.s64 + 36;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824df200
	ctx.lr = 0x8237CA2C;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-21544
	ctx.r5.s64 = ctx.r5.s64 + -21544;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,44
	ctx.r6.s64 = r31.s64 + 44;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237CA4C;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-21560
	ctx.r5.s64 = ctx.r4.s64 + -21560;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,48
	ctx.r6.s64 = r31.s64 + 48;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237CA6C;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-21576
	ctx.r5.s64 = r11.s64 + -21576;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,52
	ctx.r6.s64 = r31.s64 + 52;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237CA8C;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-21596
	ctx.r5.s64 = ctx.r10.s64 + -21596;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,56
	ctx.r6.s64 = r31.s64 + 56;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237CAAC;
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

__attribute__((alias("__imp__sub_8237CAC4"))) PPC_WEAK_FUNC(sub_8237CAC4);
PPC_FUNC_IMPL(__imp__sub_8237CAC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237CAC8"))) PPC_WEAK_FUNC(sub_8237CAC8);
PPC_FUNC_IMPL(__imp__sub_8237CAC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f29{};
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
	// stfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f29.u64);
	// stfd f30,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f30.u64);
	// stfd f31,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8237cbb0
	if (cr6.eq) goto loc_8237CBB0;
	// lwz r11,68(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8237cbb0
	if (cr6.eq) goto loc_8237CBB0;
	// lwz r11,236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 236);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8237cbb0
	if (cr6.eq) goto loc_8237CBB0;
	// lwz r11,68(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,44(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 44);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,236(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 236);
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfs f12,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// lfs f29,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lfs f11,16(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bgt cr6,0x8237cb58
	if (cr6.gt) goto loc_8237CB58;
	// fmr f30,f29
	f30.f64 = f29.f64;
loc_8237CB40:
	// lfs f2,56(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f2.f64 = double(temp.f32);
	// fcmpu cr6,f2,f29
	cr6.compare(ctx.f2.f64, f29.f64);
	// bge cr6,0x8237cb74
	if (!cr6.lt) goto loc_8237CB74;
	// fneg f2,f2
	ctx.f2.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// b 0x8237cb78
	goto loc_8237CB78;
loc_8237CB58:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8237cb6c
	if (!cr6.lt) goto loc_8237CB6C;
	// fdivs f30,f0,f13
	f30.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// bne cr6,0x8237cb40
	if (!cr6.eq) goto loc_8237CB40;
loc_8237CB6C:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// b 0x8237cbb8
	goto loc_8237CBB8;
loc_8237CB74:
	// fsubs f1,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - f30.f64));
loc_8237CB78:
	// bl 0x823dc480
	ctx.lr = 0x8237CB7C;
	sub_823DC480(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64));
	// lfs f13,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x8237CB8C;
	sub_823DBBC8(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// fmadds f10,f11,f12,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + f31.f64));
	// fmuls f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 * f30.f64));
	// fsel f8,f9,f9,f29
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// fsel f7,f9,f9,f29
	ctx.f7.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// fsubs f6,f8,f31
	ctx.f6.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsel f1,f6,f31,f7
	ctx.f1.f64 = ctx.f6.f64 >= 0.0 ? f31.f64 : ctx.f7.f64;
	// b 0x8237cbb8
	goto loc_8237CBB8;
loc_8237CBB0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
loc_8237CBB8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f29,-40(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f30,-32(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// lfd f31,-24(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237CBD8"))) PPC_WEAK_FUNC(sub_8237CBD8);
PPC_FUNC_IMPL(__imp__sub_8237CBD8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-21388
	ctx.r4.s64 = r11.s64 + -21388;
	// bl 0x8237c460
	ctx.lr = 0x8237CBF8;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-21452
	ctx.r8.s64 = ctx.r10.s64 + -21452;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r7,13(r31)
	PPC_STORE_U8(r31.u32 + 13, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_8237CC2C"))) PPC_WEAK_FUNC(sub_8237CC2C);
PPC_FUNC_IMPL(__imp__sub_8237CC2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237CC30"))) PPC_WEAK_FUNC(sub_8237CC30);
PPC_FUNC_IMPL(__imp__sub_8237CC30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237cc4c
	if (cr6.eq) goto loc_8237CC4C;
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// sth r9,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r9.u16);
loc_8237CC4C:
	// lwz r11,68(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// li r10,25
	ctx.r10.s64 = 25;
	// lwz r9,140(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// stw r10,140(r11)
	PPC_STORE_U32(r11.u32 + 140, ctx.r10.u32);
	// stw r9,136(r11)
	PPC_STORE_U32(r11.u32 + 136, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237CC64"))) PPC_WEAK_FUNC(sub_8237CC64);
PPC_FUNC_IMPL(__imp__sub_8237CC64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237CC68"))) PPC_WEAK_FUNC(sub_8237CC68);
PPC_FUNC_IMPL(__imp__sub_8237CC68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// lhz r9,18(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 18);
	// lhz r8,14(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 14);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// sth r9,18(r11)
	PPC_STORE_U16(r11.u32 + 18, ctx.r9.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237CCB4"))) PPC_WEAK_FUNC(sub_8237CCB4);
PPC_FUNC_IMPL(__imp__sub_8237CCB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237CCB8"))) PPC_WEAK_FUNC(sub_8237CCB8);
PPC_FUNC_IMPL(__imp__sub_8237CCB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91f8
	ctx.lr = 0x8237CCC0;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-21260
	ctx.r4.s64 = r11.s64 + -21260;
	// bl 0x8237c460
	ctx.lr = 0x8237CCDC;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lfs f0,-21264(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21264);
	f0.f64 = double(temp.f32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lfs f13,-29496(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29496);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21268(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21268);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stfs f13,108(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,-11300(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -11300);
	f0.f64 = double(temp.f32);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lfs f11,6088(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 6088);
	ctx.f11.f64 = double(temp.f32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// lis r29,-32251
	r29.s64 = -2113601536;
	// lfs f13,-21272(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -21272);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r6,-21340
	ctx.r6.s64 = ctx.r6.s64 + -21340;
	// stfs f12,112(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// stb r11,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r11.u8);
	// lis r28,-32251
	r28.s64 = -2113601536;
	// stfs f11,116(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stw r5,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r5.u32);
	// lfs f12,-21276(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -21276);
	ctx.f12.f64 = double(temp.f32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f12,136(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// lfs f11,-21352(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21352);
	ctx.f11.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f11,140(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,-21356(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -21356);
	f0.f64 = double(temp.f32);
	// lfs f13,-21364(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -21364);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -21360);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stfs f12,148(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f13,152(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f11,-21368(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -21368);
	ctx.f11.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfs f31,160(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// stfs f11,164(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f31,168(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// lfs f10,-21372(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -21372);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,180(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f13,184(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// lfs f10,-21376(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -21376);
	ctx.f10.f64 = double(temp.f32);
	// stfs f31,192(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stfs f10,196(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f31,200(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 200, temp.u32);
	// lfs f30,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f30.f64 = double(temp.f32);
	// stfs f0,208(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f12,212(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f13,216(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f30,80(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,224(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// stfs f11,228(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// stfs f31,232(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x8237CE08;
	sub_82496790(ctx, base);
	// stfs f30,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f1,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237CE2C;
	sub_82496790(ctx, base);
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82496790
	ctx.lr = 0x8237CE4C;
	sub_82496790(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8237CE60"))) PPC_WEAK_FUNC(sub_8237CE60);
PPC_FUNC_IMPL(__imp__sub_8237CE60) {
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
	// bl 0x8237c950
	ctx.lr = 0x8237CE80;
	sub_8237C950(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-21052
	ctx.r5.s64 = r11.s64 + -21052;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,108
	ctx.r6.s64 = r31.s64 + 108;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237CEA0;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-21068
	ctx.r5.s64 = ctx.r10.s64 + -21068;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237CEC0;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-21084
	ctx.r5.s64 = ctx.r9.s64 + -21084;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,116
	ctx.r6.s64 = r31.s64 + 116;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237CEE0;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-21096
	ctx.r5.s64 = ctx.r8.s64 + -21096;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237CF00;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-21116
	ctx.r5.s64 = ctx.r7.s64 + -21116;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237CF20;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-21136
	ctx.r5.s64 = ctx.r6.s64 + -21136;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237CF40;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-21164
	ctx.r5.s64 = ctx.r5.s64 + -21164;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,176
	ctx.r6.s64 = r31.s64 + 176;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237CF60;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-21192
	ctx.r5.s64 = ctx.r4.s64 + -21192;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,192
	ctx.r6.s64 = r31.s64 + 192;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237CF80;
	sub_824DF200(ctx, base);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r3,-21224
	ctx.r5.s64 = ctx.r3.s64 + -21224;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,208
	ctx.r6.s64 = r31.s64 + 208;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237CFA0;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,-21256
	ctx.r5.s64 = r11.s64 + -21256;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237CFC0;
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

__attribute__((alias("__imp__sub_8237CFD8"))) PPC_WEAK_FUNC(sub_8237CFD8);
PPC_FUNC_IMPL(__imp__sub_8237CFD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,68(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,236(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 236);
	// lfs f13,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// lwz r11,16(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,96(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8237D018"))) PPC_WEAK_FUNC(sub_8237D018);
PPC_FUNC_IMPL(__imp__sub_8237D018) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237D01C"))) PPC_WEAK_FUNC(sub_8237D01C);
PPC_FUNC_IMPL(__imp__sub_8237D01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237D020"))) PPC_WEAK_FUNC(sub_8237D020);
PPC_FUNC_IMPL(__imp__sub_8237D020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r10,128
	ctx.r10.s64 = 128;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,624(r11)
	PPC_STORE_U32(r11.u32 + 624, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237D034"))) PPC_WEAK_FUNC(sub_8237D034);
PPC_FUNC_IMPL(__imp__sub_8237D034) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237D038"))) PPC_WEAK_FUNC(sub_8237D038);
PPC_FUNC_IMPL(__imp__sub_8237D038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,624(r11)
	PPC_STORE_U32(r11.u32 + 624, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237D048"))) PPC_WEAK_FUNC(sub_8237D048);
PPC_FUNC_IMPL(__imp__sub_8237D048) {
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
	// bl 0x8237ccb8
	ctx.lr = 0x8237D060;
	sub_8237CCB8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,12
	ctx.r9.s64 = 12;
	// addi r8,r10,-21028
	ctx.r8.s64 = ctx.r10.s64 + -21028;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stb r7,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_8237D0A0"))) PPC_WEAK_FUNC(sub_8237D0A0);
PPC_FUNC_IMPL(__imp__sub_8237D0A0) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-20892
	ctx.r4.s64 = r11.s64 + -20892;
	// bl 0x8237c460
	ctx.lr = 0x8237D0C0;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// addi r9,r10,-20956
	ctx.r9.s64 = ctx.r10.s64 + -20956;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// bl 0x8237c370
	ctx.lr = 0x8237D0D4;
	sub_8237C370(ctx, base);
	// addi r3,r31,224
	ctx.r3.s64 = r31.s64 + 224;
	// bl 0x8237c370
	ctx.lr = 0x8237D0DC;
	sub_8237C370(ctx, base);
	// li r8,2
	ctx.r8.s64 = 2;
	// li r7,13
	ctx.r7.s64 = 13;
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r6,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r6.u8);
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

__attribute__((alias("__imp__sub_8237D10C"))) PPC_WEAK_FUNC(sub_8237D10C);
PPC_FUNC_IMPL(__imp__sub_8237D10C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237D110"))) PPC_WEAK_FUNC(sub_8237D110);
PPC_FUNC_IMPL(__imp__sub_8237D110) {
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
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r9,64
	ctx.r9.s64 = 64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r9,624(r11)
	PPC_STORE_U32(r11.u32 + 624, ctx.r9.u32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8237d140
	if (!cr6.eq) goto loc_8237D140;
	// li r11,0
	r11.s64 = 0;
loc_8237D140:
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r3,7188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 7188);
	// addi r6,r10,224
	ctx.r6.s64 = ctx.r10.s64 + 224;
	// addi r5,r10,112
	ctx.r5.s64 = ctx.r10.s64 + 112;
	// lwz r11,-21528(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21528);
	// addi r4,r11,12
	ctx.r4.s64 = r11.s64 + 12;
	// bl 0x82375e58
	ctx.lr = 0x8237D15C;
	sub_82375E58(ctx, base);
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

__attribute__((alias("__imp__sub_8237D170"))) PPC_WEAK_FUNC(sub_8237D170);
PPC_FUNC_IMPL(__imp__sub_8237D170) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8237d184
	if (!cr6.eq) goto loc_8237D184;
	// li r11,0
	r11.s64 = 0;
loc_8237D184:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,7188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 7188);
	// lwz r11,-21528(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21528);
	// addi r4,r11,304
	ctx.r4.s64 = r11.s64 + 304;
	// b 0x82375eb8
	sub_82375EB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8237D198"))) PPC_WEAK_FUNC(sub_8237D198);
PPC_FUNC_IMPL(__imp__sub_8237D198) {
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
	// bl 0x8237c950
	ctx.lr = 0x8237D1B8;
	sub_8237C950(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-20468
	ctx.r5.s64 = r11.s64 + -20468;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237D1D8;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20480
	ctx.r5.s64 = ctx.r10.s64 + -20480;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237D1F8;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-20492
	ctx.r5.s64 = ctx.r9.s64 + -20492;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237D218;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-20512
	ctx.r5.s64 = ctx.r8.s64 + -20512;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D238;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-20536
	ctx.r5.s64 = ctx.r7.s64 + -20536;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,168
	ctx.r6.s64 = r31.s64 + 168;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D258;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-20564
	ctx.r5.s64 = ctx.r6.s64 + -20564;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,176
	ctx.r6.s64 = r31.s64 + 176;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D278;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-20592
	ctx.r5.s64 = ctx.r5.s64 + -20592;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,184
	ctx.r6.s64 = r31.s64 + 184;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D298;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-20616
	ctx.r5.s64 = ctx.r4.s64 + -20616;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,192
	ctx.r6.s64 = r31.s64 + 192;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D2B8;
	sub_824DF200(ctx, base);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r3,-20632
	ctx.r5.s64 = ctx.r3.s64 + -20632;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,200
	ctx.r6.s64 = r31.s64 + 200;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237D2D8;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,-20648
	ctx.r5.s64 = r11.s64 + -20648;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,204
	ctx.r6.s64 = r31.s64 + 204;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237D2F8;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20664
	ctx.r5.s64 = ctx.r10.s64 + -20664;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,208
	ctx.r6.s64 = r31.s64 + 208;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x8237D318;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-20676
	ctx.r5.s64 = ctx.r9.s64 + -20676;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,224
	ctx.r6.s64 = r31.s64 + 224;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237D338;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-20688
	ctx.r5.s64 = ctx.r8.s64 + -20688;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,240
	ctx.r6.s64 = r31.s64 + 240;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237D358;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-20700
	ctx.r5.s64 = ctx.r7.s64 + -20700;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,256
	ctx.r6.s64 = r31.s64 + 256;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237D378;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-20720
	ctx.r5.s64 = ctx.r6.s64 + -20720;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,272
	ctx.r6.s64 = r31.s64 + 272;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D398;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-20744
	ctx.r5.s64 = ctx.r5.s64 + -20744;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,280
	ctx.r6.s64 = r31.s64 + 280;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D3B8;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-20772
	ctx.r5.s64 = ctx.r4.s64 + -20772;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,288
	ctx.r6.s64 = r31.s64 + 288;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D3D8;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-20800
	ctx.r5.s64 = r11.s64 + -20800;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,296
	ctx.r6.s64 = r31.s64 + 296;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D3F8;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20824
	ctx.r5.s64 = ctx.r10.s64 + -20824;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,304
	ctx.r6.s64 = r31.s64 + 304;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237D418;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r9,-20840
	ctx.r5.s64 = ctx.r9.s64 + -20840;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,312
	ctx.r6.s64 = r31.s64 + 312;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237D438;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-20856
	ctx.r5.s64 = ctx.r8.s64 + -20856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,316
	ctx.r6.s64 = r31.s64 + 316;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237D458;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-20872
	ctx.r5.s64 = ctx.r7.s64 + -20872;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,320
	ctx.r6.s64 = r31.s64 + 320;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237D478;
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

__attribute__((alias("__imp__sub_8237D490"))) PPC_WEAK_FUNC(sub_8237D490);
PPC_FUNC_IMPL(__imp__sub_8237D490) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-20892
	ctx.r4.s64 = r11.s64 + -20892;
	// bl 0x8237c460
	ctx.lr = 0x8237D4B0;
	sub_8237C460(ctx, base);
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x8237c370
	ctx.lr = 0x8237D4B8;
	sub_8237C370(ctx, base);
	// addi r3,r31,224
	ctx.r3.s64 = r31.s64 + 224;
	// bl 0x8237c370
	ctx.lr = 0x8237D4C0;
	sub_8237C370(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r11,13
	r11.s64 = 13;
	// addi r8,r9,-20452
	ctx.r8.s64 = ctx.r9.s64 + -20452;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stb r7,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_8237D504"))) PPC_WEAK_FUNC(sub_8237D504);
PPC_FUNC_IMPL(__imp__sub_8237D504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237D508"))) PPC_WEAK_FUNC(sub_8237D508);
PPC_FUNC_IMPL(__imp__sub_8237D508) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-20316
	ctx.r4.s64 = r11.s64 + -20316;
	// bl 0x8237c460
	ctx.lr = 0x8237D528;
	sub_8237C460(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r8,3
	ctx.r8.s64 = 3;
	// addi r7,r9,-20380
	ctx.r7.s64 = ctx.r9.s64 + -20380;
	// li r6,14
	ctx.r6.s64 = 14;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8237D568"))) PPC_WEAK_FUNC(sub_8237D568);
PPC_FUNC_IMPL(__imp__sub_8237D568) {
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
	// lis r31,-32119
	r31.s64 = -2104950784;
	// lwz r3,-9052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// bl 0x82339390
	ctx.lr = 0x8237D588;
	sub_82339390(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lwz r5,29856(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29856);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8237d5b4
	if (cr6.eq) goto loc_8237D5B4;
	// lwz r11,29888(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 29888);
	// lwz r10,-9052(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r6,288(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 288);
	// bl 0x82189ce0
	ctx.lr = 0x8237D5B4;
	sub_82189CE0(ctx, base);
loc_8237D5B4:
	// lwz r3,-9052(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -9052);
	// bl 0x82339390
	ctx.lr = 0x8237D5BC;
	sub_82339390(ctx, base);
	// lwz r3,29888(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 29888);
	// bl 0x82190870
	ctx.lr = 0x8237D5C4;
	sub_82190870(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,-32228(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32228);
	// bl 0x82187be0
	ctx.lr = 0x8237D5D0;
	sub_82187BE0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8217f768
	ctx.lr = 0x8237D5DC;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8237D5E8;
	sub_8217F768(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x8237D5F4;
	sub_8217F768(ctx, base);
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

__attribute__((alias("__imp__sub_8237D60C"))) PPC_WEAK_FUNC(sub_8237D60C);
PPC_FUNC_IMPL(__imp__sub_8237D60C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237D610"))) PPC_WEAK_FUNC(sub_8237D610);
PPC_FUNC_IMPL(__imp__sub_8237D610) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x8237D624;
	sub_82190870(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x8237D62C;
	sub_82187BE0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237D63C"))) PPC_WEAK_FUNC(sub_8237D63C);
PPC_FUNC_IMPL(__imp__sub_8237D63C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237D640"))) PPC_WEAK_FUNC(sub_8237D640);
PPC_FUNC_IMPL(__imp__sub_8237D640) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-20316
	ctx.r4.s64 = r11.s64 + -20316;
	// bl 0x8237c460
	ctx.lr = 0x8237D660;
	sub_8237C460(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r11,14
	r11.s64 = 14;
	// addi r8,r9,-20300
	ctx.r8.s64 = ctx.r9.s64 + -20300;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
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

__attribute__((alias("__imp__sub_8237D69C"))) PPC_WEAK_FUNC(sub_8237D69C);
PPC_FUNC_IMPL(__imp__sub_8237D69C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237D6A0"))) PPC_WEAK_FUNC(sub_8237D6A0);
PPC_FUNC_IMPL(__imp__sub_8237D6A0) {
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
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8237D6A8;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9d4
	ctx.lr = 0x8237D6B0;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd534
	ctx.lr = 0x8237D6B8;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r4,r11,-20164
	ctx.r4.s64 = r11.s64 + -20164;
	// bl 0x8237c460
	ctx.lr = 0x8237D6CC;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r9,r10,-20228
	ctx.r9.s64 = ctx.r10.s64 + -20228;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r9,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r9.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vupkd3d128 v63,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v63 = vTemp;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f27,-29924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29924);
	f27.f64 = double(temp.f32);
	// addi r30,r22,112
	r30.s64 = r22.s64 + 112;
	// lfs f28,-26872(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -26872);
	f28.f64 = double(temp.f32);
	// li r29,9
	r29.s64 = 9;
	// lfs f29,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f29.f64 = double(temp.f32);
	// addi r31,r30,128
	r31.s64 = r30.s64 + 128;
	// lfs f30,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f30.f64 = double(temp.f32);
	// vpermwi128 v126,v63,234
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// vpermwi128 v125,v63,186
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v124,v63,174
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// li r24,-32
	r24.s64 = -32;
	// li r25,-16
	r25.s64 = -16;
	// li r26,16
	r26.s64 = 16;
	// li r23,0
	r23.s64 = 0;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// lis r27,-32111
	r27.s64 = -2104426496;
loc_8237D738:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r6,r11,0
	ctx.r6.s64 = r11.s64 + 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x821305f0
	ctx.lr = 0x8237D750;
	sub_821305F0(ctx, base);
	// stfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f30,-120(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -120, temp.u32);
	// mr r11,r23
	r11.u64 = r23.u64;
	// stfs f29,-124(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + -124, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f28,-116(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + -116, temp.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stfs f27,-112(r31)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r31.u32 + -112, temp.u32);
	// addi r30,r30,336
	r30.s64 = r30.s64 + 336;
	// stfs f31,-108(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -108, temp.u32);
	// stvx128 v126,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,-21424(r27)
	PPC_STORE_U8(r27.u32 + -21424, r11.u8);
	// stb r10,-5340(r28)
	PPC_STORE_U8(r28.u32 + -5340, ctx.r10.u8);
	// addi r31,r31,336
	r31.s64 = r31.s64 + 336;
	// bge 0x8237d738
	if (!cr0.lt) goto loc_8237D738;
	// addi r3,r22,3472
	ctx.r3.s64 = r22.s64 + 3472;
	// bl 0x8237c370
	ctx.lr = 0x8237D7A0;
	sub_8237C370(ctx, base);
	// addi r3,r22,3584
	ctx.r3.s64 = r22.s64 + 3584;
	// bl 0x8237c370
	ctx.lr = 0x8237D7A8;
	sub_8237C370(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r22,3696
	r11.s64 = r22.s64 + 3696;
	// li r10,19
	ctx.r10.s64 = 19;
	// lfs f30,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
loc_8237D7B8:
	// stfs f31,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// std r23,40(r11)
	PPC_STORE_U64(r11.u32 + 40, r23.u64);
	// stfs f31,20(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stw r23,56(r11)
	PPC_STORE_U32(r11.u32 + 56, r23.u32);
	// stfs f31,24(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f31,28(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// stfs f30,12(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f30,8(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f30,4(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f30,0(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f31,32(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bge 0x8237d7b8
	if (!cr0.lt) goto loc_8237D7B8;
	// li r11,4
	r11.s64 = 4;
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r10,15
	ctx.r10.s64 = 15;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stw r11,4(r22)
	PPC_STORE_U32(r22.u32 + 4, r11.u32);
	// stw r10,8(r22)
	PPC_STORE_U32(r22.u32 + 8, ctx.r10.u32);
	// addi r31,r22,60
	r31.s64 = r22.s64 + 60;
	// stb r9,20(r22)
	PPC_STORE_U8(r22.u32 + 20, ctx.r9.u8);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82496790
	ctx.lr = 0x8237D82C;
	sub_82496790(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f31,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f0,14184(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14184);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f1,-3072(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -3072);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237D858;
	sub_82496790(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// stfs f31,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f0,-11624(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -11624);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f1,-29232(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237D884;
	sub_82496790(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,140(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f0,32668(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32668);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f1,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237D8B0;
	sub_82496790(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f31,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,156(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f0,14988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	f0.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f1,-13148(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13148);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237D8DC;
	sub_82496790(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// stfs f31,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// stfs f31,168(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f31,172(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// lfs f0,-20236(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -20236);
	f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x8237D904;
	sub_82496790(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd7cc
	ctx.lr = 0x8237D914;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba20
	ctx.lr = 0x8237D91C;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8237D920"))) PPC_WEAK_FUNC(sub_8237D920);
PPC_FUNC_IMPL(__imp__sub_8237D920) {
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
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82331d28
	ctx.lr = 0x8237D944;
	sub_82331D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237d964
	if (cr6.eq) goto loc_8237D964;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82331d18
	ctx.lr = 0x8237D958;
	sub_82331D18(ctx, base);
	// bl 0x822a5948
	ctx.lr = 0x8237D95C;
	sub_822A5948(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,916(r3)
	PPC_STORE_U8(ctx.r3.u32 + 916, r11.u8);
loc_8237D964:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82331d40
	ctx.lr = 0x8237D96C;
	sub_82331D40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237d9a8
	if (!cr6.eq) goto loc_8237D9A8;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8237d98c
	if (!cr6.eq) goto loc_8237D98C;
	// li r11,0
	r11.s64 = 0;
loc_8237D98C:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,7188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 7188);
	// addi r6,r30,3584
	ctx.r6.s64 = r30.s64 + 3584;
	// addi r5,r30,3472
	ctx.r5.s64 = r30.s64 + 3472;
	// lwz r11,-21528(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21528);
	// addi r4,r11,12
	ctx.r4.s64 = r11.s64 + 12;
	// bl 0x82375e58
	ctx.lr = 0x8237D9A8;
	sub_82375E58(ctx, base);
loc_8237D9A8:
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_8237D9C4"))) PPC_WEAK_FUNC(sub_8237D9C4);
PPC_FUNC_IMPL(__imp__sub_8237D9C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237D9C8"))) PPC_WEAK_FUNC(sub_8237D9C8);
PPC_FUNC_IMPL(__imp__sub_8237D9C8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82331d28
	ctx.lr = 0x8237D9E4;
	sub_82331D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237da04
	if (cr6.eq) goto loc_8237DA04;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82331d18
	ctx.lr = 0x8237D9F8;
	sub_82331D18(ctx, base);
	// bl 0x822a5948
	ctx.lr = 0x8237D9FC;
	sub_822A5948(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,916(r3)
	PPC_STORE_U8(ctx.r3.u32 + 916, r11.u8);
loc_8237DA04:
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

__attribute__((alias("__imp__sub_8237DA18"))) PPC_WEAK_FUNC(sub_8237DA18);
PPC_FUNC_IMPL(__imp__sub_8237DA18) {
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
	// bl 0x8237c950
	ctx.lr = 0x8237DA38;
	sub_8237C950(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-20468
	ctx.r5.s64 = r11.s64 + -20468;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3472
	ctx.r6.s64 = r31.s64 + 3472;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237DA58;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20480
	ctx.r5.s64 = ctx.r10.s64 + -20480;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3488
	ctx.r6.s64 = r31.s64 + 3488;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237DA78;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-20492
	ctx.r5.s64 = ctx.r9.s64 + -20492;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3504
	ctx.r6.s64 = r31.s64 + 3504;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237DA98;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-20512
	ctx.r5.s64 = ctx.r8.s64 + -20512;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3520
	ctx.r6.s64 = r31.s64 + 3520;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DAB8;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-20536
	ctx.r5.s64 = ctx.r7.s64 + -20536;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3528
	ctx.r6.s64 = r31.s64 + 3528;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DAD8;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-20564
	ctx.r5.s64 = ctx.r6.s64 + -20564;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3536
	ctx.r6.s64 = r31.s64 + 3536;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DAF8;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-20592
	ctx.r5.s64 = ctx.r5.s64 + -20592;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3544
	ctx.r6.s64 = r31.s64 + 3544;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DB18;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-20616
	ctx.r5.s64 = ctx.r4.s64 + -20616;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3552
	ctx.r6.s64 = r31.s64 + 3552;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DB38;
	sub_824DF200(ctx, base);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r3,-20632
	ctx.r5.s64 = ctx.r3.s64 + -20632;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3560
	ctx.r6.s64 = r31.s64 + 3560;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237DB58;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r11,-20648
	ctx.r5.s64 = r11.s64 + -20648;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3564
	ctx.r6.s64 = r31.s64 + 3564;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237DB78;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20664
	ctx.r5.s64 = ctx.r10.s64 + -20664;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3568
	ctx.r6.s64 = r31.s64 + 3568;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x8237DB98;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-20676
	ctx.r5.s64 = ctx.r9.s64 + -20676;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3584
	ctx.r6.s64 = r31.s64 + 3584;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237DBB8;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-20688
	ctx.r5.s64 = ctx.r8.s64 + -20688;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3600
	ctx.r6.s64 = r31.s64 + 3600;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237DBD8;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-20700
	ctx.r5.s64 = ctx.r7.s64 + -20700;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3616
	ctx.r6.s64 = r31.s64 + 3616;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237DBF8;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-20720
	ctx.r5.s64 = ctx.r6.s64 + -20720;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3632
	ctx.r6.s64 = r31.s64 + 3632;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DC18;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-20744
	ctx.r5.s64 = ctx.r5.s64 + -20744;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3640
	ctx.r6.s64 = r31.s64 + 3640;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DC38;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-20772
	ctx.r5.s64 = ctx.r4.s64 + -20772;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3648
	ctx.r6.s64 = r31.s64 + 3648;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DC58;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-20800
	ctx.r5.s64 = r11.s64 + -20800;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3656
	ctx.r6.s64 = r31.s64 + 3656;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DC78;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20824
	ctx.r5.s64 = ctx.r10.s64 + -20824;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3664
	ctx.r6.s64 = r31.s64 + 3664;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x824df200
	ctx.lr = 0x8237DC98;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r9,-20840
	ctx.r5.s64 = ctx.r9.s64 + -20840;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3672
	ctx.r6.s64 = r31.s64 + 3672;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237DCB8;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-20856
	ctx.r5.s64 = ctx.r8.s64 + -20856;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3676
	ctx.r6.s64 = r31.s64 + 3676;
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x824df200
	ctx.lr = 0x8237DCD8;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r7,-20872
	ctx.r5.s64 = ctx.r7.s64 + -20872;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,3680
	ctx.r6.s64 = r31.s64 + 3680;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237DCF8;
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

__attribute__((alias("__imp__sub_8237DD10"))) PPC_WEAK_FUNC(sub_8237DD10);
PPC_FUNC_IMPL(__imp__sub_8237DD10) {
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
	// bl 0x8237d6a0
	ctx.lr = 0x8237DD28;
	sub_8237D6A0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r8,r10,-20148
	ctx.r8.s64 = ctx.r10.s64 + -20148;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_8237DD60"))) PPC_WEAK_FUNC(sub_8237DD60);
PPC_FUNC_IMPL(__imp__sub_8237DD60) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8237DD68;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-19936
	ctx.r4.s64 = r11.s64 + -19936;
	// bl 0x8237c460
	ctx.lr = 0x8237DD88;
	sub_8237C460(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r10,-20004
	ctx.r3.s64 = ctx.r10.s64 + -20004;
	// lfs f30,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f30.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f0,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,16
	ctx.r9.s64 = 16;
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f0,160(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// stb r11,136(r31)
	PPC_STORE_U8(r31.u32 + 136, r11.u8);
	// stfs f0,192(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// stb r11,168(r31)
	PPC_STORE_U8(r31.u32 + 168, r11.u8);
	// stfs f0,224(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// stb r11,200(r31)
	PPC_STORE_U8(r31.u32 + 200, r11.u8);
	// stfs f0,256(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 256, temp.u32);
	// stb r11,232(r31)
	PPC_STORE_U8(r31.u32 + 232, r11.u8);
	// stfs f0,288(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 288, temp.u32);
	// stb r11,264(r31)
	PPC_STORE_U8(r31.u32 + 264, r11.u8);
	// stfs f0,320(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 320, temp.u32);
	// stb r11,296(r31)
	PPC_STORE_U8(r31.u32 + 296, r11.u8);
	// stfs f0,352(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 352, temp.u32);
	// stb r11,328(r31)
	PPC_STORE_U8(r31.u32 + 328, r11.u8);
	// stb r11,360(r31)
	PPC_STORE_U8(r31.u32 + 360, r11.u8);
	// stfs f31,112(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f31,116(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stfs f30,120(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stfs f30,132(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// stfs f31,144(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stfs f31,148(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f30,152(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// stfs f30,164(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f31,176(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// stfs f31,180(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 180, temp.u32);
	// stfs f30,184(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// stfs f30,196(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// stfs f31,208(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f31,212(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f30,216(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f30,228(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// stfs f31,240(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// stfs f31,244(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 244, temp.u32);
	// stfs f30,248(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stfs f30,260(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// stfs f31,272(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 272, temp.u32);
	// stfs f31,276(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 276, temp.u32);
	// stfs f30,280(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// stfs f30,292(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 292, temp.u32);
	// stfs f31,304(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 304, temp.u32);
	// stfs f31,308(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 308, temp.u32);
	// stfs f30,312(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 312, temp.u32);
	// stfs f30,324(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 324, temp.u32);
	// stfs f31,336(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 336, temp.u32);
	// stfs f31,340(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 340, temp.u32);
	// stfs f30,344(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 344, temp.u32);
	// stfs f30,356(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 356, temp.u32);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// lfs f0,-20016(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -20016);
	f0.f64 = double(temp.f32);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// lfs f13,-20020(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -20020);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20024(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -20024);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,448(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 448, temp.u32);
	// stfs f13,452(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 452, temp.u32);
	// stfs f12,456(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 456, temp.u32);
	// stfs f31,464(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 464, temp.u32);
	// lfs f11,-20028(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20028);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lfs f10,-11620(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -11620);
	ctx.f10.f64 = double(temp.f32);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stfs f11,468(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 468, temp.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// stfs f10,472(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 472, temp.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f9,-20032(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -20032);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,-20036(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20036);
	ctx.f8.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f9,480(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stfs f8,484(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 484, temp.u32);
	// lis r29,-32256
	r29.s64 = -2113929216;
	// lfs f7,-20040(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -20040);
	ctx.f7.f64 = double(temp.f32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stfs f7,488(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 488, temp.u32);
	// lis r28,-32254
	r28.s64 = -2113798144;
	// lfs f9,-20044(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -20044);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f8,-20048(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20048);
	ctx.f8.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stfs f31,496(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 496, temp.u32);
	// lis r27,-32253
	r27.s64 = -2113732608;
	// stfs f9,500(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 500, temp.u32);
	// lis r26,-32251
	r26.s64 = -2113601536;
	// stfs f8,504(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 504, temp.u32);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stfs f0,512(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 512, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f13,516(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 516, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f12,520(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 520, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stfs f31,528(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 528, temp.u32);
	// stfs f11,532(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 532, temp.u32);
	// stfs f10,536(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 536, temp.u32);
	// lfs f0,31960(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31960);
	f0.f64 = double(temp.f32);
	// lfs f13,-26224(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -26224);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,372(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 372, temp.u32);
	// stfs f13,368(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 368, temp.u32);
	// stfs f30,376(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 376, temp.u32);
	// stfs f30,380(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 380, temp.u32);
	// lfs f0,17032(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lfs f13,-20052(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20052);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,416(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 416, temp.u32);
	// stfs f13,428(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 428, temp.u32);
	// lfs f29,31308(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f29.f64 = double(temp.f32);
	// stfs f29,420(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 420, temp.u32);
	// stfs f30,424(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 424, temp.u32);
	// lfs f0,-6176(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6176);
	f0.f64 = double(temp.f32);
	// lfs f12,31952(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31952);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-12084(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -12084);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,432(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 432, temp.u32);
	// stfs f13,436(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 436, temp.u32);
	// stfs f12,444(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 444, temp.u32);
	// lfs f0,12424(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 12424);
	f0.f64 = double(temp.f32);
	// lfs f13,6088(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 6088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20056(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + -20056);
	ctx.f12.f64 = double(temp.f32);
	// stfs f30,440(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 440, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f30,80(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f30,84(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,400(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 400, temp.u32);
	// stfs f30,404(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 404, temp.u32);
	// stfs f13,408(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 408, temp.u32);
	// stfs f12,412(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 412, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x8237DFD4;
	sub_82496790(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f0,-20060(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -20060);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,-20064(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -20064);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f1,-20068(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -20068);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237E008;
	sub_82496790(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// stfs f31,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lfs f0,-20072(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20072);
	f0.f64 = double(temp.f32);
	// lfs f13,-20076(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -20076);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x8237E038;
	sub_82496790(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// stfs f31,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f0,-20080(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -20080);
	f0.f64 = double(temp.f32);
	// lfs f13,-20084(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -20084);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f1,31316(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31316);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237E06C;
	sub_82496790(ctx, base);
	// stfs f30,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f30,148(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f31,156(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x82496790
	ctx.lr = 0x8237E08C;
	sub_82496790(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

__attribute__((alias("__imp__sub_8237E0A4"))) PPC_WEAK_FUNC(sub_8237E0A4);
PPC_FUNC_IMPL(__imp__sub_8237E0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E0A8"))) PPC_WEAK_FUNC(sub_8237E0A8);
PPC_FUNC_IMPL(__imp__sub_8237E0A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237E0C0"))) PPC_WEAK_FUNC(sub_8237E0C0);
PPC_FUNC_IMPL(__imp__sub_8237E0C0) {
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
	// bl 0x8237c950
	ctx.lr = 0x8237E0E0;
	sub_8237C950(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-19784
	ctx.r5.s64 = r11.s64 + -19784;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,416
	ctx.r6.s64 = r31.s64 + 416;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237E100;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-21096
	ctx.r5.s64 = ctx.r10.s64 + -21096;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,432
	ctx.r6.s64 = r31.s64 + 432;
	// li r4,9
	ctx.r4.s64 = 9;
	// bl 0x824df200
	ctx.lr = 0x8237E120;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-19804
	ctx.r5.s64 = ctx.r9.s64 + -19804;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,448
	ctx.r6.s64 = r31.s64 + 448;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237E140;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-19824
	ctx.r5.s64 = ctx.r8.s64 + -19824;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,464
	ctx.r6.s64 = r31.s64 + 464;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237E160;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-19848
	ctx.r5.s64 = ctx.r7.s64 + -19848;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,480
	ctx.r6.s64 = r31.s64 + 480;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237E180;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,-19872
	ctx.r5.s64 = ctx.r6.s64 + -19872;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,496
	ctx.r6.s64 = r31.s64 + 496;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237E1A0;
	sub_824DF200(ctx, base);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,-19900
	ctx.r5.s64 = ctx.r5.s64 + -19900;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,512
	ctx.r6.s64 = r31.s64 + 512;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237E1C0;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r4,-19928
	ctx.r5.s64 = ctx.r4.s64 + -19928;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,528
	ctx.r6.s64 = r31.s64 + 528;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237E1E0;
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

__attribute__((alias("__imp__sub_8237E1F8"))) PPC_WEAK_FUNC(sub_8237E1F8);
PPC_FUNC_IMPL(__imp__sub_8237E1F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, ctx.r9.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,376(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 376, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237E214"))) PPC_WEAK_FUNC(sub_8237E214);
PPC_FUNC_IMPL(__imp__sub_8237E214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E218"))) PPC_WEAK_FUNC(sub_8237E218);
PPC_FUNC_IMPL(__imp__sub_8237E218) {
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
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8237e240
	if (cr6.eq) goto loc_8237E240;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82342780
	ctx.lr = 0x8237E240;
	sub_82342780(ctx, base);
loc_8237E240:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,384(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 384, temp.u32);
	// stfs f0,388(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 388, temp.u32);
	// stfs f0,392(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 392, temp.u32);
	// stfs f0,396(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 396, temp.u32);
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

__attribute__((alias("__imp__sub_8237E270"))) PPC_WEAK_FUNC(sub_8237E270);
PPC_FUNC_IMPL(__imp__sub_8237E270) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// lwz r3,20(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x82342798
	sub_82342798(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8237E28C"))) PPC_WEAK_FUNC(sub_8237E28C);
PPC_FUNC_IMPL(__imp__sub_8237E28C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237E290"))) PPC_WEAK_FUNC(sub_8237E290);
PPC_FUNC_IMPL(__imp__sub_8237E290) {
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
	// bl 0x8237dd60
	ctx.lr = 0x8237E2A8;
	sub_8237DD60(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r11,-19764
	ctx.r9.s64 = r11.s64 + -19764;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_8237E2D4"))) PPC_WEAK_FUNC(sub_8237E2D4);
PPC_FUNC_IMPL(__imp__sub_8237E2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E2D8"))) PPC_WEAK_FUNC(sub_8237E2D8);
PPC_FUNC_IMPL(__imp__sub_8237E2D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,104(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237E2F0"))) PPC_WEAK_FUNC(sub_8237E2F0);
PPC_FUNC_IMPL(__imp__sub_8237E2F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8237dd60
	ctx.lr = 0x8237E318;
	sub_8237DD60(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lfs f30,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f13,-13148(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f12,-12084(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12084);
	ctx.f12.f64 = double(temp.f32);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// lfs f29,31308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31308);
	f29.f64 = double(temp.f32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stfs f30,16(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lfs f0,-12736(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12736);
	f0.f64 = double(temp.f32);
	// addi r7,r10,-19676
	ctx.r7.s64 = ctx.r10.s64 + -19676;
	// lfs f31,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f11,-19684(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -19684);
	ctx.f11.f64 = double(temp.f32);
	// addi r30,r31,60
	r30.s64 = r31.s64 + 60;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f13,416(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 416, temp.u32);
	// stfs f12,428(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 428, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f13,-19688(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19688);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f12,31224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31224);
	ctx.f12.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lfs f10,31952(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31952);
	ctx.f10.f64 = double(temp.f32);
	// stfs f29,420(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 420, temp.u32);
	// stfs f29,424(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 424, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f30,80(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,432(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 432, temp.u32);
	// stfs f13,436(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 436, temp.u32);
	// stfs f12,440(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 440, temp.u32);
	// stfs f10,444(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 444, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x8237E3BC;
	sub_82496790(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,108(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f0,-20060(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -20060);
	f0.f64 = double(temp.f32);
	// lfs f13,-20064(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -20064);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f1,-20068(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -20068);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237E3F0;
	sub_82496790(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stfs f31,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,124(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// lfs f0,-20072(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -20072);
	f0.f64 = double(temp.f32);
	// lfs f13,-19692(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -19692);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x8237E420;
	sub_82496790(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// stfs f31,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lfs f0,-20080(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -20080);
	f0.f64 = double(temp.f32);
	// lfs f13,-19696(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -19696);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f1,31316(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31316);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82496790
	ctx.lr = 0x8237E454;
	sub_82496790(ctx, base);
	// stfs f30,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f30,148(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// stfs f31,156(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// bl 0x82496790
	ctx.lr = 0x8237E474;
	sub_82496790(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_8237E49C"))) PPC_WEAK_FUNC(sub_8237E49C);
PPC_FUNC_IMPL(__imp__sub_8237E49C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E4A0"))) PPC_WEAK_FUNC(sub_8237E4A0);
PPC_FUNC_IMPL(__imp__sub_8237E4A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,384(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 384, temp.u32);
	// stfs f0,388(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 388, temp.u32);
	// stfs f0,392(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 392, temp.u32);
	// stfs f0,396(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 396, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237E4C4"))) PPC_WEAK_FUNC(sub_8237E4C4);
PPC_FUNC_IMPL(__imp__sub_8237E4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E4C8"))) PPC_WEAK_FUNC(sub_8237E4C8);
PPC_FUNC_IMPL(__imp__sub_8237E4C8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-19540
	ctx.r4.s64 = r11.s64 + -19540;
	// bl 0x8237c460
	ctx.lr = 0x8237E4E8;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,8
	ctx.r9.s64 = 8;
	// addi r8,r10,-19604
	ctx.r8.s64 = ctx.r10.s64 + -19604;
	// li r7,19
	ctx.r7.s64 = 19;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r6,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r6.u8);
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

__attribute__((alias("__imp__sub_8237E524"))) PPC_WEAK_FUNC(sub_8237E524);
PPC_FUNC_IMPL(__imp__sub_8237E524) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E528"))) PPC_WEAK_FUNC(sub_8237E528);
PPC_FUNC_IMPL(__imp__sub_8237E528) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8237e548
	if (cr6.eq) goto loc_8237E548;
	// stfs f0,4092(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4092, temp.u32);
	// blr 
	return;
loc_8237E548:
	// li r11,0
	r11.s64 = 0;
	// stfs f0,0(0)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237E554"))) PPC_WEAK_FUNC(sub_8237E554);
PPC_FUNC_IMPL(__imp__sub_8237E554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E558"))) PPC_WEAK_FUNC(sub_8237E558);
PPC_FUNC_IMPL(__imp__sub_8237E558) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8237e574
	if (cr6.eq) goto loc_8237E574;
	// stfs f0,4092(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4092, temp.u32);
	// blr 
	return;
loc_8237E574:
	// li r11,0
	r11.s64 = 0;
	// stfs f0,0(0)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(0, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237E580"))) PPC_WEAK_FUNC(sub_8237E580);
PPC_FUNC_IMPL(__imp__sub_8237E580) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-19540
	ctx.r4.s64 = r11.s64 + -19540;
	// bl 0x8237c460
	ctx.lr = 0x8237E5A0;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,19
	r11.s64 = 19;
	// addi r9,r10,-19524
	ctx.r9.s64 = ctx.r10.s64 + -19524;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r8,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r8.u8);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
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

__attribute__((alias("__imp__sub_8237E5D8"))) PPC_WEAK_FUNC(sub_8237E5D8);
PPC_FUNC_IMPL(__imp__sub_8237E5D8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-19388
	ctx.r4.s64 = r11.s64 + -19388;
	// bl 0x8237c460
	ctx.lr = 0x8237E5F8;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,9
	ctx.r9.s64 = 9;
	// addi r8,r10,-19452
	ctx.r8.s64 = ctx.r10.s64 + -19452;
	// li r7,20
	ctx.r7.s64 = 20;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r6,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r6.u8);
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

__attribute__((alias("__imp__sub_8237E634"))) PPC_WEAK_FUNC(sub_8237E634);
PPC_FUNC_IMPL(__imp__sub_8237E634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E638"))) PPC_WEAK_FUNC(sub_8237E638);
PPC_FUNC_IMPL(__imp__sub_8237E638) {
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
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// bl 0x82337a48
	ctx.lr = 0x8237E65C;
	sub_82337A48(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// bl 0x82338a48
	ctx.lr = 0x8237E66C;
	sub_82338A48(ctx, base);
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// bl 0x823383c8
	ctx.lr = 0x8237E674;
	sub_823383C8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_8237E690"))) PPC_WEAK_FUNC(sub_8237E690);
PPC_FUNC_IMPL(__imp__sub_8237E690) {
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
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// bl 0x82338388
	ctx.lr = 0x8237E6B4;
	sub_82338388(ctx, base);
	// lwz r4,104(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lwz r3,72(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// bl 0x82338a48
	ctx.lr = 0x8237E6C0;
	sub_82338A48(ctx, base);
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

__attribute__((alias("__imp__sub_8237E6D8"))) PPC_WEAK_FUNC(sub_8237E6D8);
PPC_FUNC_IMPL(__imp__sub_8237E6D8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-19388
	ctx.r4.s64 = r11.s64 + -19388;
	// bl 0x8237c460
	ctx.lr = 0x8237E6F8;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r11,20
	r11.s64 = 20;
	// addi r9,r10,-19372
	ctx.r9.s64 = ctx.r10.s64 + -19372;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r8,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r8.u8);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
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

__attribute__((alias("__imp__sub_8237E730"))) PPC_WEAK_FUNC(sub_8237E730);
PPC_FUNC_IMPL(__imp__sub_8237E730) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-19236
	ctx.r4.s64 = r11.s64 + -19236;
	// bl 0x8237c460
	ctx.lr = 0x8237E750;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,10
	ctx.r9.s64 = 10;
	// addi r8,r10,-19300
	ctx.r8.s64 = ctx.r10.s64 + -19300;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stb r7,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r7.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r6,13(r31)
	PPC_STORE_U8(r31.u32 + 13, ctx.r6.u8);
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

__attribute__((alias("__imp__sub_8237E78C"))) PPC_WEAK_FUNC(sub_8237E78C);
PPC_FUNC_IMPL(__imp__sub_8237E78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E790"))) PPC_WEAK_FUNC(sub_8237E790);
PPC_FUNC_IMPL(__imp__sub_8237E790) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-19236
	ctx.r4.s64 = r11.s64 + -19236;
	// bl 0x8237c460
	ctx.lr = 0x8237E7B0;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-19220
	ctx.r8.s64 = ctx.r10.s64 + -19220;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r9,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r9.u8);
	// li r6,21
	ctx.r6.s64 = 21;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stb r7,13(r31)
	PPC_STORE_U8(r31.u32 + 13, ctx.r7.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r6.u32);
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

__attribute__((alias("__imp__sub_8237E7EC"))) PPC_WEAK_FUNC(sub_8237E7EC);
PPC_FUNC_IMPL(__imp__sub_8237E7EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E7F0"))) PPC_WEAK_FUNC(sub_8237E7F0);
PPC_FUNC_IMPL(__imp__sub_8237E7F0) {
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
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8237E7F8;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9d4
	ctx.lr = 0x8237E800;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd534
	ctx.lr = 0x8237E808;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r4,r11,-19084
	ctx.r4.s64 = r11.s64 + -19084;
	// bl 0x8237c460
	ctx.lr = 0x8237E81C;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r9,r10,-19148
	ctx.r9.s64 = ctx.r10.s64 + -19148;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r9,0(r22)
	PPC_STORE_U32(r22.u32 + 0, ctx.r9.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// vupkd3d128 v63,v127,4
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v127.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v63 = vTemp;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f27,-29924(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29924);
	f27.f64 = double(temp.f32);
	// addi r30,r22,112
	r30.s64 = r22.s64 + 112;
	// lfs f28,-26872(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -26872);
	f28.f64 = double(temp.f32);
	// li r29,9
	r29.s64 = 9;
	// lfs f29,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f29.f64 = double(temp.f32);
	// addi r31,r30,128
	r31.s64 = r30.s64 + 128;
	// lfs f30,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	f30.f64 = double(temp.f32);
	// vpermwi128 v126,v63,234
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x15));
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
	// vpermwi128 v125,v63,186
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x45));
	// vpermwi128 v124,v63,174
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x51));
	// li r24,-32
	r24.s64 = -32;
	// li r25,-16
	r25.s64 = -16;
	// li r26,16
	r26.s64 = 16;
	// li r23,0
	r23.s64 = 0;
	// lis r28,-32125
	r28.s64 = -2105344000;
	// lis r27,-32111
	r27.s64 = -2104426496;
loc_8237E888:
	// lis r11,-32237
	r11.s64 = -2112684032;
	// li r5,10
	ctx.r5.s64 = 10;
	// addi r6,r11,0
	ctx.r6.s64 = r11.s64 + 0;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r31,32
	ctx.r3.s64 = r31.s64 + 32;
	// bl 0x821305f0
	ctx.lr = 0x8237E8A0;
	sub_821305F0(ctx, base);
	// stfs f31,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// stfs f30,-120(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + -120, temp.u32);
	// mr r11,r23
	r11.u64 = r23.u64;
	// stfs f29,-124(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + -124, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f28,-116(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + -116, temp.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// stfs f27,-112(r31)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r31.u32 + -112, temp.u32);
	// addi r30,r30,336
	r30.s64 = r30.s64 + 336;
	// stfs f31,-108(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + -108, temp.u32);
	// stvx128 v126,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v125,r31,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v124,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,-21424(r27)
	PPC_STORE_U8(r27.u32 + -21424, r11.u8);
	// stb r10,-5340(r28)
	PPC_STORE_U8(r28.u32 + -5340, ctx.r10.u8);
	// addi r31,r31,336
	r31.s64 = r31.s64 + 336;
	// bge 0x8237e888
	if (!cr0.lt) goto loc_8237E888;
	// addi r3,r22,3472
	ctx.r3.s64 = r22.s64 + 3472;
	// bl 0x8237c370
	ctx.lr = 0x8237E8F0;
	sub_8237C370(ctx, base);
	// addi r3,r22,3584
	ctx.r3.s64 = r22.s64 + 3584;
	// bl 0x8237c370
	ctx.lr = 0x8237E8F8;
	sub_8237C370(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r11,r22,3696
	r11.s64 = r22.s64 + 3696;
	// li r10,19
	ctx.r10.s64 = 19;
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
loc_8237E908:
	// stfs f31,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 16, temp.u32);
	// std r23,40(r11)
	PPC_STORE_U64(r11.u32 + 40, r23.u64);
	// stfs f31,20(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
	// stw r23,56(r11)
	PPC_STORE_U32(r11.u32 + 56, r23.u32);
	// stfs f31,24(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stfs f31,28(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,0(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f31,32(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 32, temp.u32);
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// bge 0x8237e908
	if (!cr0.lt) goto loc_8237E908;
	// li r11,6
	r11.s64 = 6;
	// li r10,17
	ctx.r10.s64 = 17;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,4(r22)
	PPC_STORE_U32(r22.u32 + 4, r11.u32);
	// stw r10,8(r22)
	PPC_STORE_U32(r22.u32 + 8, ctx.r10.u32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// stb r9,20(r22)
	PPC_STORE_U8(r22.u32 + 20, ctx.r9.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-128
	r12.s64 = ctx.r1.s64 + -128;
	// bl 0x823dd7cc
	ctx.lr = 0x8237E968;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba20
	ctx.lr = 0x8237E970;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8237E974"))) PPC_WEAK_FUNC(sub_8237E974);
PPC_FUNC_IMPL(__imp__sub_8237E974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237E978"))) PPC_WEAK_FUNC(sub_8237E978);
PPC_FUNC_IMPL(__imp__sub_8237E978) {
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
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// li r9,6
	ctx.r9.s64 = 6;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r9,624(r11)
	PPC_STORE_U32(r11.u32 + 624, ctx.r9.u32);
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8237e9a8
	if (!cr6.eq) goto loc_8237E9A8;
	// li r11,0
	r11.s64 = 0;
loc_8237E9A8:
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r3,7188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 7188);
	// addi r6,r10,3584
	ctx.r6.s64 = ctx.r10.s64 + 3584;
	// addi r5,r10,3472
	ctx.r5.s64 = ctx.r10.s64 + 3472;
	// lwz r11,-21528(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -21528);
	// addi r4,r11,12
	ctx.r4.s64 = r11.s64 + 12;
	// bl 0x82375e58
	ctx.lr = 0x8237E9C4;
	sub_82375E58(ctx, base);
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

__attribute__((alias("__imp__sub_8237E9D8"))) PPC_WEAK_FUNC(sub_8237E9D8);
PPC_FUNC_IMPL(__imp__sub_8237E9D8) {
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
	// bl 0x8237e7f0
	ctx.lr = 0x8237E9F0;
	sub_8237E7F0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,17
	ctx.r9.s64 = 17;
	// addi r8,r10,-19068
	ctx.r8.s64 = ctx.r10.s64 + -19068;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_8237EA28"))) PPC_WEAK_FUNC(sub_8237EA28);
PPC_FUNC_IMPL(__imp__sub_8237EA28) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-18932
	ctx.r4.s64 = r11.s64 + -18932;
	// bl 0x8237c460
	ctx.lr = 0x8237EA48;
	sub_8237C460(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r8,r10,-18996
	ctx.r8.s64 = ctx.r10.s64 + -18996;
	// li r7,7
	ctx.r7.s64 = 7;
	// li r6,18
	ctx.r6.s64 = 18;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// stb r5,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r5.u8);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f0,120(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f0,132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f0,136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// lfs f13,11368(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stfs f0,148(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// lfs f12,21588(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 21588);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f11,-15876(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15876);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,160(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// stfs f13,164(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stfs f13,168(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 168, temp.u32);
	// stfs f12,172(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f11,176(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
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

__attribute__((alias("__imp__sub_8237EAE0"))) PPC_WEAK_FUNC(sub_8237EAE0);
PPC_FUNC_IMPL(__imp__sub_8237EAE0) {
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
	// bl 0x8237c950
	ctx.lr = 0x8237EB00;
	sub_8237C950(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-14100
	ctx.r5.s64 = r11.s64 + -14100;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,112
	ctx.r6.s64 = r31.s64 + 112;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237EB20;
	sub_824DF200(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-20568
	ctx.r5.s64 = ctx.r10.s64 + -20568;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,128
	ctx.r6.s64 = r31.s64 + 128;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8237EB40;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r9,-18924
	ctx.r5.s64 = ctx.r9.s64 + -18924;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,144
	ctx.r6.s64 = r31.s64 + 144;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8237EB60;
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

__attribute__((alias("__imp__sub_8237EB78"))) PPC_WEAK_FUNC(sub_8237EB78);
PPC_FUNC_IMPL(__imp__sub_8237EB78) {
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
	// bl 0x8237ea28
	ctx.lr = 0x8237EB90;
	sub_8237EA28(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,18
	ctx.r9.s64 = 18;
	// addi r8,r10,-18908
	ctx.r8.s64 = ctx.r10.s64 + -18908;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stb r7,20(r31)
	PPC_STORE_U8(r31.u32 + 20, ctx.r7.u8);
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

__attribute__((alias("__imp__sub_8237EBD0"))) PPC_WEAK_FUNC(sub_8237EBD0);
PPC_FUNC_IMPL(__imp__sub_8237EBD0) {
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
	ctx.lr = 0x8237EBD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,68(r4)
	r30.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// ble cr6,0x8237ec00
	if (!cr6.gt) goto loc_8237EC00;
	// cmpwi cr6,r11,21
	cr6.compare<int32_t>(r11.s32, 21, xer);
	// bge cr6,0x8237ec00
	if (!cr6.lt) goto loc_8237EC00;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8237EC00:
	// addi r29,r30,44
	r29.s64 = r30.s64 + 44;
	// lfs f2,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x8232bce8
	ctx.lr = 0x8237EC18;
	sub_8232BCE8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// stb r3,37(r31)
	PPC_STORE_U8(r31.u32 + 37, ctx.r3.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237ec68
	if (cr6.eq) goto loc_8237EC68;
	// lwz r10,104(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 104);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8237ec68
	if (!cr6.gt) goto loc_8237EC68;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_8237EC44:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8237ec54
	if (cr6.eq) goto loc_8237EC54;
	// stfs f0,108(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 108, temp.u32);
loc_8237EC54:
	// lwz r9,104(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 104);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8237ec44
	if (cr6.lt) goto loc_8237EC44;
loc_8237EC68:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8237EC74"))) PPC_WEAK_FUNC(sub_8237EC74);
PPC_FUNC_IMPL(__imp__sub_8237EC74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237EC78"))) PPC_WEAK_FUNC(sub_8237EC78);
PPC_FUNC_IMPL(__imp__sub_8237EC78) {
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
	ctx.lr = 0x8237EC80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r29,68(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8237ed50
	if (cr6.eq) goto loc_8237ED50;
	// lbz r11,37(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 37);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237ece4
	if (!cr6.eq) goto loc_8237ECE4;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// ble cr6,0x8237ecc0
	if (!cr6.gt) goto loc_8237ECC0;
	// cmpwi cr6,r11,21
	cr6.compare<int32_t>(r11.s32, 21, xer);
	// bge cr6,0x8237ecc0
	if (!cr6.lt) goto loc_8237ECC0;
	// li r7,1
	ctx.r7.s64 = 1;
loc_8237ECC0:
	// addi r6,r29,44
	ctx.r6.s64 = r29.s64 + 44;
	// lfs f2,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,28(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8232bce8
	ctx.lr = 0x8237ECD4;
	sub_8232BCE8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r3,37(r30)
	PPC_STORE_U8(r30.u32 + 37, ctx.r3.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,108(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 108, temp.u32);
loc_8237ECE4:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f12,108(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f13,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,108(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 108, temp.u32);
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// ble cr6,0x8237ed50
	if (!cr6.gt) goto loc_8237ED50;
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8237ed50
	if (!cr6.gt) goto loc_8237ED50;
	// addi r31,r29,44
	r31.s64 = r29.s64 + 44;
loc_8237ED20:
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8237ed3c
	if (cr6.eq) goto loc_8237ED3C;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r6,4(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8237c540
	ctx.lr = 0x8237ED3C;
	sub_8237C540(ctx, base);
loc_8237ED3C:
	// lwz r11,104(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 104);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8237ed20
	if (cr6.lt) goto loc_8237ED20;
loc_8237ED50:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8237ED58"))) PPC_WEAK_FUNC(sub_8237ED58);
PPC_FUNC_IMPL(__imp__sub_8237ED58) {
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
	PPCVRegister v32{};
	PPCVRegister v33{};
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
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x8237ED60;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,36(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8237f3a4
	if (cr6.eq) goto loc_8237F3A4;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// li r8,0
	ctx.r8.s64 = 0;
	// bne cr6,0x8237eda0
	if (!cr6.eq) goto loc_8237EDA0;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r7,r11,240
	ctx.r7.s64 = r11.s64 + 240;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// lfs f2,-29232(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,31492(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31492);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8237edf0
	goto loc_8237EDF0;
loc_8237EDA0:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// vupkd3d128 v61,v63,4
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v61 = vTemp;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// vpermwi128 v60,v61,234
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x15));
	// vpermwi128 v59,v61,186
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x45));
	// lfs f2,-29232(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// vpermwi128 v58,v61,174
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x51));
	// lfs f1,31492(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31492);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237EDF0:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82682590
	ctx.lr = 0x8237EDF8;
	sub_82682590(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8237EE0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8237f3a4
	if (cr6.eq) goto loc_8237F3A4;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lwz r11,-7968(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -7968);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8237ee34
	if (!cr6.eq) goto loc_8237EE34;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r11,-7968(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7968, r11.u32);
loc_8237EE34:
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8237ee48
	if (!cr6.eq) goto loc_8237EE48;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stw r11,-7968(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7968, r11.u32);
loc_8237EE48:
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8237ee5c
	if (!cr6.eq) goto loc_8237EE5C;
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// stw r11,-7968(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7968, r11.u32);
loc_8237EE5C:
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lfs f11,14348(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14348);
	ctx.f11.f64 = double(temp.f32);
	// lis r6,-32122
	ctx.r6.s64 = -2105147392;
	// lfs f13,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-31664
	r11.s64 = r11.s64 + -31664;
	// addi r7,r7,2240
	ctx.r7.s64 = ctx.r7.s64 + 2240;
	// addi r29,r9,2176
	r29.s64 = ctx.r9.s64 + 2176;
	// addi r31,r8,-31648
	r31.s64 = ctx.r8.s64 + -31648;
	// addi r5,r6,2528
	ctx.r5.s64 = ctx.r6.s64 + 2528;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lvx128 v12,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,23772
	ctx.r4.s64 = 1557921792;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32119
	ctx.r9.s64 = -2104950784;
	// lwz r30,4(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12120(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 12120);
	f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r11,r4,64167
	r11.u64 = ctx.r4.u64 | 64167;
	// addi r9,r9,-8000
	ctx.r9.s64 = ctx.r9.s64 + -8000;
	// addi r7,r8,-8032
	ctx.r7.s64 = ctx.r8.s64 + -8032;
loc_8237EED0:
	// clrldi r6,r6,32
	ctx.r6.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// vor128 v0,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// clrldi r8,r30,32
	ctx.r8.u64 = r30.u64 & 0xFFFFFFFF;
	// vor128 v13,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// mulld r6,r6,r11
	ctx.r6.s64 = ctx.r6.s64 * r11.s64;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r3,r10,r7
	ctx.r3.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rotlwi r6,r8,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rldicl r5,r8,32,32
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// mulld r6,r6,r11
	ctx.r6.s64 = ctx.r6.s64 * r11.s64;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// clrlwi r8,r8,9
	ctx.r8.u64 = ctx.r8.u32 & 0x7FFFFF;
	// rotlwi r5,r6,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// rldicl r4,r6,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFF;
	// std r8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// mulld r5,r5,r11
	ctx.r5.s64 = ctx.r5.s64 * r11.s64;
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// clrlwi r6,r6,9
	ctx.r6.u64 = ctx.r6.u32 & 0x7FFFFF;
	// std r6,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r6.u64);
	// clrlwi r31,r5,9
	r31.u64 = ctx.r5.u32 & 0x7FFFFF;
	// std r31,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, r31.u64);
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// rldicl r5,r5,32,32
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF;
	// lfd f8,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mulld r4,r4,r11
	ctx.r4.s64 = ctx.r4.s64 * r11.s64;
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f1,f7
	ctx.f1.f64 = double(float(ctx.f7.f64));
	// add r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 + ctx.r5.u64;
	// lfd f6,96(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// lfd f12,88(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// rotlwi r8,r5,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// rldicl r4,r5,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF;
	// mulld r8,r8,r11
	ctx.r8.s64 = ctx.r8.s64 * r11.s64;
	// fcfid f3,f6
	ctx.f3.f64 = double(ctx.f6.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// frsp f12,f3
	ctx.f12.f64 = double(float(ctx.f3.f64));
	// fmsubs f10,f1,f0,f13
	ctx.f10.f64 = double(float(ctx.f1.f64 * f0.f64 - ctx.f13.f64));
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// clrlwi r6,r5,9
	ctx.r6.u64 = ctx.r5.u32 & 0x7FFFFF;
	// clrlwi r5,r8,9
	ctx.r5.u64 = ctx.r8.u32 & 0x7FFFFF;
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// rotlwi r6,r8,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r5,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r5.u64);
	// rldicl r8,r8,32,32
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// mulld r5,r6,r11
	ctx.r5.s64 = ctx.r6.s64 * r11.s64;
	// fmsubs f2,f9,f0,f13
	ctx.f2.f64 = double(float(ctx.f9.f64 * f0.f64 - ctx.f13.f64));
	// stfsx f2,r10,r7
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, temp.u32);
	// fmuls f9,f12,f11
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// add r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 + ctx.r8.u64;
	// addi r6,r7,8
	ctx.r6.s64 = ctx.r7.s64 + 8;
	// clrlwi r8,r5,9
	ctx.r8.u64 = ctx.r5.u32 & 0x7FFFFF;
	// add r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lfd f5,104(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// std r8,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// lfd f8,120(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// lfd f4,112(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f7,f5
	ctx.f7.f64 = double(ctx.f5.s64);
	// fcfid f6,f4
	ctx.f6.f64 = double(ctx.f4.s64);
	// rotlwi r6,r5,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// rldicl r30,r5,32,32
	r30.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF;
	// stfs f10,0(r4)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// addi r5,r9,4
	ctx.r5.s64 = ctx.r9.s64 + 4;
	// stfs f9,-4(r4)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r4.u32 + -4, temp.u32);
	// addi r4,r9,8
	ctx.r4.s64 = ctx.r9.s64 + 8;
	// lvx128 v57,r0,r3
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v56,v57,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v57.f32), 0xEF));
	// vrsqrtefp128 v55,v56
	simde_mm_store_ps(v55.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v56.f32))));
	// frsp f4,f7
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// frsp f3,f6
	ctx.f3.f64 = double(float(ctx.f6.f64));
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// fcfid f5,f8
	ctx.f5.f64 = double(ctx.f8.s64);
	// stw r6,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r6.u32);
	// fmsubs f2,f4,f0,f13
	ctx.f2.f64 = double(float(ctx.f4.f64 * f0.f64 - ctx.f13.f64));
	// stfsx f2,r10,r4
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r4.u32, temp.u32);
	// fmuls f1,f3,f11
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f11.f64));
	// stfsx f1,r10,r5
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r5.u32, temp.u32);
	// frsp f12,f5
	ctx.f12.f64 = double(float(ctx.f5.f64));
	// vcmpeqfp128 v11,v55,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v10,v55,v55
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v55.u8));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// fmsubs f10,f12,f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64 - ctx.f13.f64));
	// stfs f10,0(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
	// lvx128 v54,r0,r8
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v53,v54,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// vrsqrtefp128 v52,v53
	simde_mm_store_ps(v52.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v53.f32))));
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vor128 v9,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// vor128 v8,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v53.u8));
	// vmulfp128 v7,v0,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v6,v61,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vcmpeqfp128 v5,v52,v63
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v4,v52,v52
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)v52.u8));
	// vnmsubfp v3,v9,v7,v12
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v13,v4,v13,v5
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v2,v13,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v1,v61,v13
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v31,v3,v6,v0
	simde_mm_store_ps(v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v30,v8,v2,v12
	simde_mm_store_ps(v30.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v51,v57,v31
	simde_mm_store_ps(v51.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v31.f32)));
	// vmaddfp v29,v30,v1,v13
	simde_mm_store_ps(v29.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v30.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v51,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v50,v54,v29
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v29.f32)));
	// stvx128 v50,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8237eed0
	if (cr6.lt) goto loc_8237EED0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
	// lwz r10,-12640(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12640);
	// lbz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237f0a0
	if (cr6.eq) goto loc_8237F0A0;
	// lbz r10,10(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x8237f0a4
	if (cr6.eq) goto loc_8237F0A4;
loc_8237F0A0:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8237F0A4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8237f0f8
	if (!cr6.eq) goto loc_8237F0F8;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lfs f9,-8048(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -8048);
	ctx.f9.f64 = double(temp.f32);
	// lis r3,-32131
	ctx.r3.s64 = -2105737216;
	// addi r31,r4,31460
	r31.s64 = ctx.r4.s64 + 31460;
	// addi r3,r3,29952
	ctx.r3.s64 = ctx.r3.s64 + 29952;
	// lis r28,-32256
	r28.s64 = -2113929216;
	// lwz r10,31460(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 31460);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f10,12428(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 12428);
	ctx.f10.f64 = double(temp.f32);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// fmadds f12,f12,f10,f9
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f9.f64));
	// stfs f12,-8048(r8)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r8.u32 + -8048, temp.u32);
	// stw r10,31460(r4)
	PPC_STORE_U32(ctx.r4.u32 + 31460, ctx.r10.u32);
	// stw r5,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r5.u32);
	// b 0x8237f0fc
	goto loc_8237F0FC;
loc_8237F0F8:
	// lfs f12,-8048(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -8048);
	ctx.f12.f64 = double(temp.f32);
loc_8237F0FC:
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f10,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f12,f10
	cr6.compare(ctx.f12.f64, ctx.f10.f64);
	// ble cr6,0x8237f3a4
	if (!cr6.gt) goto loc_8237F3A4;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f10,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// stfs f10,-8048(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + -8048, temp.u32);
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lfs f9,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,-31384(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -31384);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r8,-8080
	r28.s64 = ctx.r8.s64 + -8080;
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f10,-1684(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -1684);
	ctx.f10.f64 = double(temp.f32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_8237F144:
	// clrldi r6,r6,32
	ctx.r6.u64 = ctx.r6.u64 & 0xFFFFFFFF;
	// vor128 v0,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// clrldi r8,r30,32
	ctx.r8.u64 = r30.u64 & 0xFFFFFFFF;
	// vor128 v13,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// mulld r6,r6,r11
	ctx.r6.s64 = ctx.r6.s64 * r11.s64;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// addi r31,r9,8
	r31.s64 = ctx.r9.s64 + 8;
	// rotlwi r6,r8,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rldicl r5,r8,32,32
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// mulld r6,r6,r11
	ctx.r6.s64 = ctx.r6.s64 * r11.s64;
	// add r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 + ctx.r5.u64;
	// clrlwi r8,r8,9
	ctx.r8.u64 = ctx.r8.u32 & 0x7FFFFF;
	// rotlwi r5,r6,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// rldicl r4,r6,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u64, 32) & 0xFFFFFFFF;
	// mulld r5,r5,r11
	ctx.r5.s64 = ctx.r5.s64 * r11.s64;
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// clrlwi r8,r5,9
	ctx.r8.u64 = ctx.r5.u32 & 0x7FFFFF;
	// std r4,120(r1)
	PPC_STORE_U64(ctx.r1.u32 + 120, ctx.r4.u64);
	// clrlwi r6,r6,9
	ctx.r6.u64 = ctx.r6.u32 & 0x7FFFFF;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// std r6,104(r1)
	PPC_STORE_U64(ctx.r1.u32 + 104, ctx.r6.u64);
	// rotlwi r8,r5,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// std r4,112(r1)
	PPC_STORE_U64(ctx.r1.u32 + 112, ctx.r4.u64);
	// rldicl r5,r5,32,32
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF;
	// mulld r8,r8,r11
	ctx.r8.s64 = ctx.r8.s64 * r11.s64;
	// add r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 + ctx.r5.u64;
	// lfd f9,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 120);
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// rotlwi r5,r8,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lfd f5,104(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 104);
	// rldicl r4,r8,32,32
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// lfd f7,112(r1)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// mulld r5,r5,r11
	ctx.r5.s64 = ctx.r5.s64 * r11.s64;
	// frsp f3,f8
	ctx.f3.f64 = double(float(ctx.f8.f64));
	// frsp f1,f4
	ctx.f1.f64 = double(float(ctx.f4.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// clrlwi r30,r8,9
	r30.u64 = ctx.r8.u32 & 0x7FFFFF;
	// rldicl r6,r5,32,32
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u64, 32) & 0xFFFFFFFF;
	// fmsubs f9,f3,f0,f13
	ctx.f9.f64 = double(float(ctx.f3.f64 * f0.f64 - ctx.f13.f64));
	// clrlwi r27,r5,9
	r27.u64 = ctx.r5.u32 & 0x7FFFFF;
	// std r30,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r30.u64);
	// rotlwi r8,r5,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// fmuls f7,f1,f11
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmsubs f8,f2,f0,f13
	ctx.f8.f64 = double(float(ctx.f2.f64 * f0.f64 - ctx.f13.f64));
	// stfsx f8,r10,r7
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, temp.u32);
	// addi r5,r7,8
	ctx.r5.s64 = ctx.r7.s64 + 8;
	// std r27,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, r27.u64);
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// mulld r8,r8,r11
	ctx.r8.s64 = ctx.r8.s64 * r11.s64;
	// stfs f9,0(r5)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// stfs f7,-4(r5)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r5.u32 + -4, temp.u32);
	// lfd f6,96(r1)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f4,f6
	ctx.f4.f64 = double(ctx.f6.s64);
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// lvx128 v49,r0,r4
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r9,4
	r27.s64 = ctx.r9.s64 + 4;
	// lfd f5,128(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// clrlwi r30,r8,9
	r30.u64 = ctx.r8.u32 & 0x7FFFFF;
	// fcfid f3,f5
	ctx.f3.f64 = double(ctx.f5.s64);
	// rotlwi r6,r8,0
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// std r30,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, r30.u64);
	// lfd f2,136(r1)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// stw r6,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r6.u32);
	// vmsum3fp128 v48,v49,v49
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v49.f32), 0xEF));
	// frsp f9,f4
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(ctx.f4.f64));
	// frsp f8,f3
	ctx.f8.f64 = double(float(ctx.f3.f64));
	// rldicl r30,r8,32,32
	r30.u64 = __builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF;
	// frsp f5,f1
	ctx.f5.f64 = double(float(ctx.f1.f64));
	// fmsubs f7,f9,f0,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64 - ctx.f13.f64));
	// stfsx f7,r10,r31
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// fmuls f6,f8,f11
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// stfsx f6,r10,r27
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + r27.u32, temp.u32);
	// vrsqrtefp128 v47,v48
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v47.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v48.f32))));
	// vcmpeqfp128 v11,v47,v63
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v63.f32)));
	// fmsubs f4,f5,f0,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64 - ctx.f13.f64));
	// stfsx f4,r10,r9
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// lvx128 v43,r0,r3
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v42,v43,v43
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v42.f32, simde_mm_dp_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v43.f32), 0xEF));
	// vrsqrtefp128 v41,v42
	simde_mm_store_ps(v41.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v42.f32))));
	// vor128 v10,v47,v47
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)v47.u8));
	// vor128 v9,v48,v48
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)v48.u8));
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// vor128 v7,v42,v42
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)v42.u8));
	// addi r26,r1,88
	r26.s64 = ctx.r1.s64 + 88;
	// vor128 v8,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)v62.u8));
	// add r8,r10,r28
	ctx.r8.u64 = ctx.r10.u64 + r28.u64;
	// vsel v0,v10,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// lvlx128 v46,r0,r27
	temp.u32 = r27.u32;
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v45,v46,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), 0xFF));
	// lvlx128 v44,r0,r26
	temp.u32 = r26.u32;
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmulfp128 v6,v0,v0
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vspltw128 v40,v44,0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v44.u32), 0xFF));
	// vmulfp128 v5,v61,v0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vcmpeqfp128 v4,v41,v63
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v3,v41,v41
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_load_si128((simde__m128i*)v41.u8));
	// vnmsubfp v2,v9,v6,v12
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v13,v3,v13,v4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v1,v13,v13
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmulfp128 v31,v61,v13
	simde_mm_store_ps(v31.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v30,v2,v5,v0
	simde_mm_store_ps(v30.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v29,v7,v1,v12
	simde_mm_store_ps(v29.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmulfp128 v39,v49,v30
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v30.f32)));
	// vmaddfp v28,v29,v31,v13
	simde_mm_store_ps(v28.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v29.f32), simde_mm_load_ps(v31.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v39,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f3,r10,r7
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// vmulfp128 v38,v43,v28
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v43.f32), simde_mm_load_ps(v28.f32)));
	// stvx128 v38,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfsx f9,r10,r31
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	ctx.f9.f64 = double(temp.f32);
	// lfsx f1,r10,r9
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// fmuls f7,f1,f12
	ctx.f7.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// fmuls f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// stfsx f7,r10,r9
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// fmuls f6,f3,f12
	ctx.f6.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// stfsx f6,r10,r7
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, temp.u32);
	// fmuls f5,f2,f10
	ctx.f5.f64 = double(float(ctx.f2.f64 * ctx.f10.f64));
	// stfsx f8,r10,r31
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r10.u32 + r31.u32, temp.u32);
	// stfs f5,0(r5)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lvx128 v37,r0,r4
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r0,r3
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v35,v37,v36
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v35.f32, simde_mm_add_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v36.f32)));
	// vor128 v34,v35,v35
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_load_si128((simde__m128i*)v35.u8));
	// stvx128 v35,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// vmulfp128 v33,v34,v45
	simde_mm_store_ps(v33.f32, simde_mm_mul_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v45.f32)));
	// vor128 v32,v33,v33
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_load_si128((simde__m128i*)v33.u8));
	// stvx128 v33,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v33.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v60,v32,v32
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v32.f32), 0xEF));
	// vrsqrtefp128 v59,v60
	simde_mm_store_ps(v59.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v60.f32))));
	// vor128 v27,v60,v60
	simde_mm_store_si128((simde__m128i*)v27.u8, simde_mm_load_si128((simde__m128i*)v60.u8));
	// vcmpeqfp128 v26,v59,v63
	simde_mm_store_ps(v26.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v63.f32)));
	// vor128 v25,v59,v59
	simde_mm_store_si128((simde__m128i*)v25.u8, simde_mm_load_si128((simde__m128i*)v59.u8));
	// vsel v0,v25,v8,v26
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)v25.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// vmulfp128 v24,v0,v0
	simde_mm_store_ps(v24.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v23,v61,v0
	simde_mm_store_ps(v23.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v22,v27,v24,v12
	simde_mm_store_ps(v22.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(v27.f32), simde_mm_load_ps(v24.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v21,v22,v23,v0
	simde_mm_store_ps(v21.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v22.f32), simde_mm_load_ps(v23.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmulfp128 v58,v32,v21
	simde_mm_store_ps(v58.f32, simde_mm_mul_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v21.f32)));
	// vor128 v57,v58,v58
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_load_si128((simde__m128i*)v58.u8));
	// stvx128 v58,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v56,v57,v40
	simde_mm_store_ps(v56.f32, simde_mm_mul_ps(simde_mm_load_ps(v57.f32), simde_mm_load_ps(v40.f32)));
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x8237f144
	if (cr6.lt) goto loc_8237F144;
	// stw r30,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r30.u32);
loc_8237F3A4:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8237F3AC"))) PPC_WEAK_FUNC(sub_8237F3AC);
PPC_FUNC_IMPL(__imp__sub_8237F3AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237F3B0"))) PPC_WEAK_FUNC(sub_8237F3B0);
PPC_FUNC_IMPL(__imp__sub_8237F3B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dd52c
	ctx.lr = 0x8237F3C8;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x8237F3DC;
	sub_8255B9A8(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8237f408
	if (cr6.eq) goto loc_8237F408;
	// addi r10,r31,272
	ctx.r10.s64 = r31.s64 + 272;
	// b 0x8237f410
	goto loc_8237F410;
loc_8237F408:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
loc_8237F410:
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r5,32
	ctx.r5.s64 = 32;
	// lvx128 v125,r10,r8
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// lvx128 v126,r0,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lwz r9,236(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 236);
	// lfs f13,12(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lvx128 v124,r10,r5
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v123,r10,r4
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lhz r8,88(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 88);
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// fsubs f0,f0,f11
	f0.f64 = double(float(f0.f64 - ctx.f11.f64));
	// ble cr6,0x8237f47c
	if (!cr6.gt) goto loc_8237F47C;
	// lwz r7,84(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// addi r10,r7,48
	ctx.r10.s64 = ctx.r7.s64 + 48;
loc_8237F460:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8237f530
	if (!cr6.lt) goto loc_8237F530;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8237f460
	if (cr6.lt) goto loc_8237F460;
loc_8237F47C:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,84(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_8237F490:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,144
	ctx.r9.s64 = 144;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r6,160
	ctx.r6.s64 = 160;
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f9,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f4.f64 = double(temp.f32);
	// lvx128 v62,r30,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v127,r30,r6
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f3,f11,f12,f10
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f10.f64));
	// stfs f3,96(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f2,f9,f12,f8
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f8.f64));
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f1,f7,f12,f6
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f6.f64));
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f0,f5,f12,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f4.f64));
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82332098
	ctx.lr = 0x8237F50C;
	sub_82332098(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8237f544
	if (cr6.eq) goto loc_8237F544;
	// li r11,176
	r11.s64 = 176;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,192
	ctx.r9.s64 = 192;
	// lvx128 v60,r30,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8237f574
	goto loc_8237F574;
loc_8237F530:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// b 0x8237f490
	goto loc_8237F490;
loc_8237F544:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,-18844
	ctx.r4.s64 = ctx.r10.s64 + -18844;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x823db730
	ctx.lr = 0x8237F558;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8237f578
	if (!cr6.eq) goto loc_8237F578;
	// li r11,208
	r11.s64 = 208;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,224
	ctx.r9.s64 = 224;
	// lvx128 v59,r30,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237F574:
	// lvx128 v127,r30,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237F578:
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// vmrghw128 v58,v126,v124
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// vmrghw128 v57,v125,v123
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), simde_mm_load_si128((simde__m128i*)v125.u32)));
	// vmrglw128 v56,v126,v124
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// vmrglw128 v55,v125,v123
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), simde_mm_load_si128((simde__m128i*)v125.u32)));
	// lfs f11,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// vmrghw128 v54,v58,v57
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// fmuls f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// vmrglw128 v53,v58,v57
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// vmrghw128 v52,v56,v55
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// vmsum3fp128 v51,v127,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v54.f32), 0xEF));
	// addi r9,r1,84
	ctx.r9.s64 = ctx.r1.s64 + 84;
	// vmsum3fp128 v50,v127,v53
	simde_mm_store_ps(v50.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// vmsum3fp128 v49,v127,v52
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// fabs f6,f12
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f6.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// fmuls f5,f9,f0
	ctx.f5.f64 = double(float(ctx.f9.f64 * f0.f64));
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,8
	ctx.r3.s64 = 8;
	// fabs f4,f7
	ctx.f4.u64 = ctx.f7.u64 & ~0x8000000000000000;
	// stfs f4,84(r1)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvlx128 v48,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v47,v48,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), 0xFF));
	// vmrghw128 v46,v51,v49
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// fabs f3,f5
	ctx.f3.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// lvlx128 v45,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vmulfp128 v44,v126,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v47.f32)));
	// stfs f3,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vspltw128 v43,v45,0
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), 0xFF));
	// lvlx128 v42,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v41,v42,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xFF));
	// vmrghw128 v40,v50,v46
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmulfp128 v39,v124,v43
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v43.f32)));
	// vmulfp128 v38,v125,v41
	simde_mm_store_ps(v38.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v41.f32)));
	// stvx128 v44,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v37,v46,v40
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vaddfp128 v36,v123,v37
	simde_mm_store_ps(v36.f32, simde_mm_add_ps(simde_mm_load_ps(v123.f32), simde_mm_load_ps(v37.f32)));
	// stvx128 v39,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217f768
	ctx.lr = 0x8237F648;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8237F654;
	sub_8217F768(ctx, base);
	// lis r4,-32112
	ctx.r4.s64 = -2104492032;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lwz r5,29860(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 29860);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8237f680
	if (cr6.eq) goto loc_8237F680;
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,29904(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 29904);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8237F680;
	sub_82189CE0(ctx, base);
loc_8237F680:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29636(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29636);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8237f6b8
	if (cr6.eq) goto loc_8237F6B8;
	// lfs f0,108(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 108);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8237F6B8;
	sub_8218A6E0(ctx, base);
loc_8237F6B8:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29832(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29832);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8237f6f0
	if (cr6.eq) goto loc_8237F6F0;
	// lfs f0,112(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 112);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8237F6F0;
	sub_8218A6E0(ctx, base);
loc_8237F6F0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29628(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29628);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8237f728
	if (cr6.eq) goto loc_8237F728;
	// lfs f0,116(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 116);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8237F728;
	sub_8218A6E0(ctx, base);
loc_8237F728:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29848(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29848);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8237f758
	if (cr6.eq) goto loc_8237F758;
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r30,128
	ctx.r6.s64 = r30.s64 + 128;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8237F758;
	sub_8218A6E0(ctx, base);
loc_8237F758:
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lwz r3,-9052(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -9052);
	// bl 0x82339390
	ctx.lr = 0x8237F764;
	sub_82339390(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29856(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29856);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8237f78c
	if (cr6.eq) goto loc_8237F78C;
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// lwz r10,-9052(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -9052);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r6,288(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 288);
	// bl 0x82189ce0
	ctx.lr = 0x8237F78C;
	sub_82189CE0(ctx, base);
loc_8237F78C:
	// lwz r3,-9052(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -9052);
	// bl 0x82339390
	ctx.lr = 0x8237F794;
	sub_82339390(ctx, base);
	// lwz r3,29888(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// bl 0x82190870
	ctx.lr = 0x8237F79C;
	sub_82190870(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,-32232(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32232);
	// bl 0x82187be0
	ctx.lr = 0x8237F7A8;
	sub_82187BE0(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,29896(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 29896);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8237F7D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x8237F7D8;
	sub_82190870(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x8237F7E0;
	sub_82187BE0(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dd7c4
	ctx.lr = 0x8237F7EC;
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

__attribute__((alias("__imp__sub_8237F800"))) PPC_WEAK_FUNC(sub_8237F800);
PPC_FUNC_IMPL(__imp__sub_8237F800) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,68(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,12(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// lwz r8,236(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 236);
	// lfs f13,12(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f12,16(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f1,f0,f10
	ctx.f1.f64 = double(float(f0.f64 - ctx.f10.f64));
	// bne cr6,0x8237f838
	if (!cr6.eq) goto loc_8237F838;
	// li r11,0
	r11.s64 = 0;
loc_8237F838:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,7188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 7188);
	// lwz r11,-21528(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21528);
	// addi r4,r11,304
	ctx.r4.s64 = r11.s64 + 304;
	// b 0x82376070
	sub_82376070(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8237F84C"))) PPC_WEAK_FUNC(sub_8237F84C);
PPC_FUNC_IMPL(__imp__sub_8237F84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237F850"))) PPC_WEAK_FUNC(sub_8237F850);
PPC_FUNC_IMPL(__imp__sub_8237F850) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// addi r3,r31,60
	ctx.r3.s64 = r31.s64 + 60;
	// addi r10,r11,-21660
	ctx.r10.s64 = r11.s64 + -21660;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82495d58
	ctx.lr = 0x8237F880;
	sub_82495D58(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8237f898
	if (cr6.eq) goto loc_8237F898;
	// bl 0x82130588
	ctx.lr = 0x8237F894;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8237F898:
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

__attribute__((alias("__imp__sub_8237F8B0"))) PPC_WEAK_FUNC(sub_8237F8B0);
PPC_FUNC_IMPL(__imp__sub_8237F8B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,28(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// li r11,2048
	r11.s64 = 2048;
	// lwz r9,68(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// stw r7,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r7.u32);
	// lwz r6,28(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r11,20(r5)
	PPC_STORE_U32(ctx.r5.u32 + 20, r11.u32);
	// lwz r10,8(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r9,68(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lwz r8,376(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 376);
	// stw r8,32(r9)
	PPC_STORE_U32(ctx.r9.u32 + 32, ctx.r8.u32);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r11,376(r7)
	PPC_STORE_U32(ctx.r7.u32 + 376, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237F8F4"))) PPC_WEAK_FUNC(sub_8237F8F4);
PPC_FUNC_IMPL(__imp__sub_8237F8F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8237F8F8"))) PPC_WEAK_FUNC(sub_8237F8F8);
PPC_FUNC_IMPL(__imp__sub_8237F8F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,68(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lwz r10,28(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r9.u32);
	// lwz r7,68(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 68);
	// lwz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r5,32(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 32);
	// stw r5,376(r6)
	PPC_STORE_U32(ctx.r6.u32 + 376, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237F920"))) PPC_WEAK_FUNC(sub_8237F920);
PPC_FUNC_IMPL(__imp__sub_8237F920) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,1
	r11.s64 = 1;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r9,236(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 236);
	// lfs f13,12(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// lhz r8,88(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 88);
	// fdivs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// fsubs f0,f0,f11
	f0.f64 = double(float(f0.f64 - ctx.f11.f64));
	// ble cr6,0x8237f988
	if (!cr6.gt) goto loc_8237F988;
	// lwz r7,84(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// addi r10,r7,48
	ctx.r10.s64 = ctx.r7.s64 + 48;
loc_8237F96C:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8237fa6c
	if (!cr6.lt) goto loc_8237FA6C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8237f96c
	if (cr6.lt) goto loc_8237F96C;
loc_8237F988:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,84(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_8237F99C:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f11,f12,f10
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f10.f64));
	// stfs f3,80(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f2,f9,f12,f8
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f8.f64));
	// stfs f2,84(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmadds f1,f7,f12,f6
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f6.f64));
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fmadds f0,f5,f12,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f4.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82331d40
	ctx.lr = 0x8237FA00;
	sub_82331D40(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8237fa1c
	if (cr6.eq) goto loc_8237FA1C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lwz r11,21664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 21664);
	// stfs f0,264(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 264, temp.u32);
loc_8237FA1C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82331d40
	ctx.lr = 0x8237FA24;
	sub_82331D40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8237fa58
	if (!cr6.eq) goto loc_8237FA58;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8237fa44
	if (!cr6.eq) goto loc_8237FA44;
	// li r11,0
	r11.s64 = 0;
loc_8237FA44:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,7188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 7188);
	// lwz r11,-21528(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21528);
	// addi r4,r11,304
	ctx.r4.s64 = r11.s64 + 304;
	// bl 0x82375eb8
	ctx.lr = 0x8237FA58;
	sub_82375EB8(ctx, base);
loc_8237FA58:
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
loc_8237FA6C:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r7
	r11.u64 = r11.u64 + ctx.r7.u64;
	// b 0x8237f99c
	goto loc_8237F99C;
}

__attribute__((alias("__imp__sub_8237FA80"))) PPC_WEAK_FUNC(sub_8237FA80);
PPC_FUNC_IMPL(__imp__sub_8237FA80) {
	PPC_FUNC_PROLOGUE();
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lfs f31,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwz r9,236(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 236);
	// lfs f0,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 / ctx.f13.f64));
	// fsubs f30,f31,f12
	f30.f64 = double(float(f31.f64 - ctx.f12.f64));
	// bl 0x82331d40
	ctx.lr = 0x8237FAC4;
	sub_82331D40(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8237fafc
	if (!cr6.eq) goto loc_8237FAFC;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// fsubs f1,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - f30.f64));
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8237fae8
	if (!cr6.eq) goto loc_8237FAE8;
	// li r11,0
	r11.s64 = 0;
loc_8237FAE8:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,7188(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 7188);
	// lwz r11,-21528(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -21528);
	// addi r4,r11,304
	ctx.r4.s64 = r11.s64 + 304;
	// bl 0x82376070
	ctx.lr = 0x8237FAFC;
	sub_82376070(ctx, base);
loc_8237FAFC:
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

__attribute__((alias("__imp__sub_8237FB18"))) PPC_WEAK_FUNC(sub_8237FB18);
PPC_FUNC_IMPL(__imp__sub_8237FB18) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister temp{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,376(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,380(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 380);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r11,29952
	r11.s64 = r11.s64 + 29952;
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f11,376(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 376, temp.u32);
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// ble cr6,0x8237fb4c
	if (!cr6.gt) goto loc_8237FB4C;
	// stfs f0,376(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 376, temp.u32);
loc_8237FB4C:
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,384(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 384);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,368(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 368);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// lfs f10,388(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 388);
	ctx.f10.f64 = double(temp.f32);
	// stfs f11,384(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 384, temp.u32);
	// lfs f0,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 + f0.f64));
	// lfs f8,372(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	ctx.f8.f64 = double(temp.f32);
	// stfs f9,388(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 388, temp.u32);
	// fcmpu cr6,f9,f8
	cr6.compare(ctx.f9.f64, ctx.f8.f64);
	// ble cr6,0x8237fc20
	if (!cr6.gt) goto loc_8237FC20;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2176
	ctx.r7.s64 = ctx.r9.s64 + 2176;
	// ori r11,r8,64167
	r11.u64 = ctx.r8.u64 | 64167;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r31,2176(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r31,r5
	ctx.r10.s64 = r31.s64 * ctx.r5.s64;
	// lfs f0,14348(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f12,-16(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r10,2176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2176, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// lfs f13,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f9,392(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 392, temp.u32);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r8,2176(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
	// mulld r10,r8,r4
	ctx.r10.s64 = ctx.r8.s64 * ctx.r4.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r5,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r5.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// stw r10,2176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2176, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// stfs f13,388(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 388, temp.u32);
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// stfs f5,396(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 396, temp.u32);
loc_8237FC20:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8237FC28"))) PPC_WEAK_FUNC(sub_8237FC28);
PPC_FUNC_IMPL(__imp__sub_8237FC28) {
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
	PPCVRegister v32{};
	PPCVRegister v33{};
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
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8237FC30;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dd52c
	ctx.lr = 0x8237FC3C;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x8237FC50;
	sub_8255B9A8(ctx, base);
	// lwz r28,0(r13)
	r28.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r27,72
	r27.s64 = 72;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lbzx r9,r27,r28
	ctx.r9.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// bne cr6,0x8237fc7c
	if (!cr6.eq) goto loc_8237FC7C;
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
loc_8237FC7C:
	// li r9,448
	ctx.r9.s64 = 448;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v126,r11,r10
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,464
	ctx.r6.s64 = 464;
	// li r29,48
	r29.s64 = 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v62,r30,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v125,r11,r7
	simde_mm_store_si128((simde__m128i*)v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v124,r30,r6
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v123,r11,r29
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82332098
	ctx.lr = 0x8237FCB4;
	sub_82332098(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8237fcd8
	if (cr6.eq) goto loc_8237FCD8;
	// li r11,480
	r11.s64 = 480;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,496
	ctx.r9.s64 = 496;
	// lvx128 v61,r30,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8237fd08
	goto loc_8237FD08;
loc_8237FCD8:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// addi r4,r10,-18844
	ctx.r4.s64 = ctx.r10.s64 + -18844;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x823db730
	ctx.lr = 0x8237FCEC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8237fd0c
	if (!cr6.eq) goto loc_8237FD0C;
	// li r11,512
	r11.s64 = 512;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,528
	ctx.r9.s64 = 528;
	// lvx128 v60,r30,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237FD08:
	// lvx128 v124,r30,r9
	simde_mm_store_si128((simde__m128i*)v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8237FD0C:
	// lfs f0,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f9,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lbzx r8,r27,r28
	ctx.r8.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// fabs f6,f10
	ctx.f6.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// stfs f6,80(r1)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v58,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fabs f5,f8
	ctx.f5.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fabs f7,f11
	ctx.f7.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// lvlx128 v57,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// stfs f7,112(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vmulfp128 v127,v127,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v55.f32)));
	// lvlx128 v59,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v54,v59,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// vmulfp128 v126,v126,v56
	simde_mm_store_ps(v126.f32, simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v56.f32)));
	// vmulfp128 v125,v125,v54
	simde_mm_store_ps(v125.f32, simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v54.f32)));
	// bne cr6,0x8237fd84
	if (!cr6.eq) goto loc_8237FD84;
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
loc_8237FD84:
	// vspltisw128 v53,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v52,r11,r29
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// vupkd3d128 v51,v53,4
	temp.f32 = 3.0f;
	temp.s32 += v53.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v53.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v51 = vTemp;
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// lis r5,-32131
	ctx.r5.s64 = -2105737216;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r5,29952
	ctx.r4.s64 = ctx.r5.s64 + 29952;
	// vpermwi128 v50,v51,234
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x15));
	// vpermwi128 v49,v51,186
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x45));
	// stvx128 v52,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v48,v51,174
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0x51));
	// lfs f1,24(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82204cb8
	ctx.lr = 0x8237FDD8;
	sub_82204CB8(ctx, base);
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lbzx r6,r27,r28
	ctx.r6.u64 = PPC_LOAD_U8(r27.u32 + r28.u32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// addi r8,r1,272
	ctx.r8.s64 = ctx.r1.s64 + 272;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,288
	ctx.r7.s64 = ctx.r1.s64 + 288;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v46,v62,0
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v47,v63,0
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vspltw128 v45,v61,0
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// vspltw128 v44,v63,1
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xAA));
	// addi r11,r31,208
	r11.s64 = r31.s64 + 208;
	// vmulfp128 v41,v127,v46
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v46.f32)));
	// vspltw128 v42,v62,1
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xAA));
	// vmulfp128 v43,v127,v47
	simde_mm_store_ps(v43.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v47.f32)));
	// vspltw128 v40,v61,1
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xAA));
	// vmulfp128 v39,v127,v45
	simde_mm_store_ps(v39.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v45.f32)));
	// vspltw128 v38,v63,2
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0x55));
	// vspltw128 v37,v62,2
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x55));
	// vspltw128 v36,v61,2
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0x55));
	// vmaddfp128 v41,v126,v42,v41
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v42.f32)), simde_mm_load_ps(v41.f32)));
	// vmaddfp128 v43,v126,v44,v43
	simde_mm_store_ps(v43.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v44.f32)), simde_mm_load_ps(v43.f32)));
	// vmaddfp128 v39,v126,v40,v39
	simde_mm_store_ps(v39.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v40.f32)), simde_mm_load_ps(v39.f32)));
	// vmaddfp128 v41,v125,v37,v41
	simde_mm_store_ps(v41.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v37.f32)), simde_mm_load_ps(v41.f32)));
	// vmaddfp128 v43,v125,v38,v43
	simde_mm_store_ps(v43.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v38.f32)), simde_mm_load_ps(v43.f32)));
	// vmaddfp128 v39,v125,v36,v39
	simde_mm_store_ps(v39.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v36.f32)), simde_mm_load_ps(v39.f32)));
	// stvx128 v41,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8237fe64
	if (!cr6.eq) goto loc_8237FE64;
	// addi r11,r31,144
	r11.s64 = r31.s64 + 144;
loc_8237FE64:
	// vmrghw128 v35,v127,v125
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// lvx128 v34,r11,r29
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v33,v126,v123
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// addi r11,r1,304
	r11.s64 = ctx.r1.s64 + 304;
	// vmrglw128 v32,v126,v123
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v123.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// li r4,1
	ctx.r4.s64 = 1;
	// vmrglw128 v63,v127,v125
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v127.u32)));
	// li r3,8
	ctx.r3.s64 = 8;
	// vmrghw128 v62,v35,v33
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrglw128 v61,v35,v33
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v60,v63,v32
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// vmsum3fp128 v59,v124,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// vmsum3fp128 v58,v124,v61
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmsum3fp128 v57,v124,v60
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v60.f32), 0xEF));
	// vmrghw128 v56,v59,v57
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v55,v58,v56
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrghw128 v54,v56,v55
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vaddfp128 v53,v34,v54
	simde_mm_store_ps(v53.f32, simde_mm_add_ps(simde_mm_load_ps(v34.f32), simde_mm_load_ps(v54.f32)));
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217f768
	ctx.lr = 0x8237FEB4;
	sub_8217F768(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,7
	ctx.r3.s64 = 7;
	// bl 0x8217f768
	ctx.lr = 0x8237FEC0;
	sub_8217F768(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8237cac8
	ctx.lr = 0x8237FECC;
	sub_8237CAC8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r9,88(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 88);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// stfs f31,140(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// ble cr6,0x8237ff20
	if (!cr6.gt) goto loc_8237FF20;
	// lwz r8,84(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// lfs f0,376(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 376);
	f0.f64 = double(temp.f32);
	// addi r10,r8,48
	ctx.r10.s64 = ctx.r8.s64 + 48;
loc_8237FF04:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x823802c4
	if (!cr6.lt) goto loc_823802C4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x8237ff04
	if (cr6.lt) goto loc_8237FF04;
loc_8237FF20:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,84(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
loc_8237FF34:
	// addi r11,r11,-48
	r11.s64 = r11.s64 + -48;
	// lfs f13,376(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 376);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// lfs f0,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lwz r5,29860(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 29860);
	// lfs f9,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f8.f64 = double(temp.f32);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lfs f7,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,44(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f4.f64 = double(temp.f32);
	// fmadds f3,f11,f12,f10
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f12.f64 + ctx.f10.f64));
	// stfs f3,96(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmadds f2,f9,f12,f8
	ctx.f2.f64 = double(float(ctx.f9.f64 * ctx.f12.f64 + ctx.f8.f64));
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmadds f1,f7,f12,f6
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f6.f64));
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fmadds f0,f5,f12,f4
	f0.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f4.f64));
	// stfs f0,108(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8237ffc0
	if (cr6.eq) goto loc_8237FFC0;
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r6,29900(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 29900);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x82189ce0
	ctx.lr = 0x8237FFC0;
	sub_82189CE0(ctx, base);
loc_8237FFC0:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29844(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29844);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82380000
	if (cr6.eq) goto loc_82380000;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// li r9,3
	ctx.r9.s64 = 3;
	// stfs f0,144(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82380000;
	sub_8218A6E0(ctx, base);
loc_82380000:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lwz r5,29620(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29620);
	// lvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8238004c
	if (cr6.eq) goto loc_8238004C;
	// li r10,416
	ctx.r10.s64 = 416;
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v51,r30,r10
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// vmulfp128 v50,v127,v51
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v51.f32)));
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stvx128 v50,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8238004C;
	sub_8218A6E0(ctx, base);
loc_8238004C:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29848(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29848);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82380090
	if (cr6.eq) goto loc_82380090;
	// li r10,432
	ctx.r10.s64 = 432;
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// li r9,5
	ctx.r9.s64 = 5;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v49,r30,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// vmulfp128 v48,v127,v49
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_mul_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v49.f32)));
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// stvx128 v48,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82380090;
	sub_8218A6E0(ctx, base);
loc_82380090:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29880(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29880);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823800c8
	if (cr6.eq) goto loc_823800C8;
	// lfs f0,376(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 376);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x823800C8;
	sub_8218A6E0(ctx, base);
loc_823800C8:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29636(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29636);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82380100
	if (cr6.eq) goto loc_82380100;
	// lfs f0,400(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 400);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82380100;
	sub_8218A6E0(ctx, base);
loc_82380100:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29832(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29832);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82380138
	if (cr6.eq) goto loc_82380138;
	// lfs f0,404(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 404);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82380138;
	sub_8218A6E0(ctx, base);
loc_82380138:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29628(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29628);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82380170
	if (cr6.eq) goto loc_82380170;
	// lfs f0,408(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 408);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x82380170;
	sub_8218A6E0(ctx, base);
loc_82380170:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29864(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29864);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823801ac
	if (cr6.eq) goto loc_823801AC;
	// lfs f0,412(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 412);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8218a6e0
	ctx.lr = 0x823801AC;
	sub_8218A6E0(ctx, base);
loc_823801AC:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29868(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29868);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x823801e4
	if (cr6.eq) goto loc_823801E4;
	// lfs f0,384(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 384);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x823801E4;
	sub_8218A6E0(ctx, base);
loc_823801E4:
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29840(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29840);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x8238021c
	if (cr6.eq) goto loc_8238021C;
	// lfs f0,392(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 392);
	f0.f64 = double(temp.f32);
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,4
	ctx.r7.s64 = 4;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// bl 0x8218a6e0
	ctx.lr = 0x8238021C;
	sub_8218A6E0(ctx, base);
loc_8238021C:
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lwz r3,-9052(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -9052);
	// bl 0x82339390
	ctx.lr = 0x82380228;
	sub_82339390(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r5,29856(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 29856);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x82380250
	if (cr6.eq) goto loc_82380250;
	// lwz r11,29888(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// lwz r10,-9052(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -9052);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r6,288(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 288);
	// bl 0x82189ce0
	ctx.lr = 0x82380250;
	sub_82189CE0(ctx, base);
loc_82380250:
	// lwz r3,-9052(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -9052);
	// bl 0x82339390
	ctx.lr = 0x82380258;
	sub_82339390(ctx, base);
	// lwz r3,29888(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 29888);
	// bl 0x82190870
	ctx.lr = 0x82380260;
	sub_82190870(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,-32236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -32236);
	// bl 0x82187be0
	ctx.lr = 0x8238026C;
	sub_82187BE0(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x8217f768
	ctx.lr = 0x82380278;
	sub_8217F768(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// lwz r3,29892(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 29892);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x823802A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82190870
	ctx.lr = 0x823802A8;
	sub_82190870(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// bl 0x82187be0
	ctx.lr = 0x823802B0;
	sub_82187BE0(ctx, base);
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dd7c4
	ctx.lr = 0x823802BC;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_823802C4:
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// b 0x8237ff34
	goto loc_8237FF34;
}

__attribute__((alias("__imp__sub_823802D8"))) PPC_WEAK_FUNC(sub_823802D8);
PPC_FUNC_IMPL(__imp__sub_823802D8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8237ed58
	ctx.lr = 0x823802F8;
	sub_8237ED58(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8237cac8
	ctx.lr = 0x82380304;
	sub_8237CAC8(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x82380318
	if (!cr6.eq) goto loc_82380318;
	// li r11,0
	r11.s64 = 0;
loc_82380318:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,4108(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 4108, temp.u32);
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

__attribute__((alias("__imp__sub_82380350"))) PPC_WEAK_FUNC(sub_82380350);
PPC_FUNC_IMPL(__imp__sub_82380350) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,-18828
	ctx.r4.s64 = ctx.r10.s64 + -18828;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-4916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4916);
	// bl 0x824804d0
	ctx.lr = 0x82380384;
	sub_824804D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823803a4
	if (cr6.eq) goto loc_823803A4;
	// bl 0x8247a838
	ctx.lr = 0x82380394;
	sub_8247A838(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,288
	ctx.r4.s64 = r11.s64 + 288;
	// bl 0x8247a020
	ctx.lr = 0x823803A4;
	sub_8247A020(ctx, base);
loc_823803A4:
	// lwz r10,128(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// li r11,0
	r11.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r8,9
	ctx.r8.s64 = 9;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x8232adf8
	ctx.lr = 0x823803D4;
	sub_8232ADF8(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,-5052(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -5052);
	// lfs f0,27640(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 27640);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 128, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823803fc
	if (cr6.eq) goto loc_823803FC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822578f8
	ctx.lr = 0x823803FC;
	sub_822578F8(ctx, base);
loc_823803FC:
	// li r3,1
	ctx.r3.s64 = 1;
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

__attribute__((alias("__imp__sub_82380418"))) PPC_WEAK_FUNC(sub_82380418);
PPC_FUNC_IMPL(__imp__sub_82380418) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
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
	PPCVRegister v32{};
	PPCVRegister v33{};
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
	PPCVRegister v123{};
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82380420;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9d4
	ctx.lr = 0x82380428;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd52c
	ctx.lr = 0x82380430;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r11,112
	r11.s64 = 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r8,144
	ctx.r8.s64 = 144;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r9,28(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// lfs f9,24(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f9.f64 = double(temp.f32);
	// li r30,48
	r30.s64 = 48;
	// lfs f11,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f11.f64 = double(temp.f32);
	// li r31,16
	r31.s64 = 16;
	// lfs f4,56(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	ctx.f4.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f10,16(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f5,52(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	ctx.f5.f64 = double(temp.f32);
	// li r29,32
	r29.s64 = 32;
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// li r27,128
	r27.s64 = 128;
	// lfs f1,48(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f6,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// lfs f31,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f30,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f29,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	f29.f64 = double(temp.f32);
	// lvx128 v61,r3,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 * f0.f64));
	// fmuls f3,f4,f0
	ctx.f3.f64 = double(float(ctx.f4.f64 * f0.f64));
	// fmadds f7,f11,f13,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f8.f64));
	// fmadds f0,f5,f13,f3
	f0.f64 = double(float(ctx.f5.f64 * ctx.f13.f64 + ctx.f3.f64));
	// fmadds f2,f10,f12,f7
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fnmadds f28,f1,f12,f0
	f28.f64 = double(float(-(ctx.f1.f64 * ctx.f12.f64 + f0.f64)));
	// fneg f13,f2
	ctx.f13.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// fsel f12,f13,f31,f30
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f31.f64 : f30.f64;
	// fsel f27,f2,f12,f29
	f27.f64 = ctx.f2.f64 >= 0.0 ? ctx.f12.f64 : f29.f64;
	// fmuls f11,f27,f6
	ctx.f11.f64 = double(float(f27.f64 * ctx.f6.f64));
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v58,r11,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r31
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v55,v59,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v56,v57,v58
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrglw128 v54,v59,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrglw128 v53,v57,v58
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v52,v55,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrglw128 v51,v55,v56
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v50,v54,v53
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmsum3fp128 v49,v63,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v52.f32), 0xEF));
	// vmsum3fp128 v48,v63,v51
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v51.f32), 0xEF));
	// vmsum3fp128 v47,v63,v50
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v50.f32), 0xEF));
	// vmrghw128 v46,v49,v47
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v45,v48,v46
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v46,v45
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// stvx128 v44,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82380554;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r10,28(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// stfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// fneg f10,f28
	ctx.f10.u64 = f28.u64 ^ 0x8000000000000000;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// lvlx128 v43,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v42,v43,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// lvx128 v41,r0,r7
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsel f9,f10,f31,f30
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f31.f64 : f30.f64;
	// vmulfp128 v40,v41,v42
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v40.f32, simde_mm_mul_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v42.f32)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lfs f8,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f7,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f6.f64 = double(temp.f32);
	// fsel f5,f28,f9,f29
	ctx.f5.f64 = f28.f64 >= 0.0 ? ctx.f9.f64 : f29.f64;
	// stvx128 v40,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lvx128 v37,r11,r31
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r11,r30
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r11,r29
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r0,r11
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v35,v38,v39
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// fmuls f4,f5,f27
	ctx.f4.f64 = double(float(ctx.f5.f64 * f27.f64));
	// vmrghw128 v126,v38,v39
	simde_mm_store_si128((simde__m128i*)v126.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrglw128 v34,v37,v36
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v125,v37,v36
	simde_mm_store_si128((simde__m128i*)v125.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v33,v35,v34
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmrghw128 v32,v126,v125
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// fmuls f3,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f4.f64));
	// stfs f3,96(r1)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f2,f7,f4
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f4.f64));
	// stfs f2,100(r1)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fmuls f1,f6,f4
	ctx.f1.f64 = double(float(ctx.f6.f64 * ctx.f4.f64));
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v127,r0,r6
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v63,v127,v33
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v33.f32), 0xEF));
	// vmsum3fp128 v62,v127,v32
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v32.f32), 0xEF));
	// lwz r10,36(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// vmrghw128 v124,v62,v63
	simde_mm_store_si128((simde__m128i*)v124.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82380608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,28(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r31,-32112
	r31.s64 = -2104492032;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lhz r4,8(r9)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// lvx128 v123,r0,r8
	simde_mm_store_si128((simde__m128i*)v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-2288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -2288);
	// bl 0x8258d8b8
	ctx.lr = 0x8238062C;
	sub_8258D8B8(ctx, base);
	// vmrglw128 v61,v126,v125
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v125.u32), simde_mm_load_si128((simde__m128i*)v126.u32)));
	// lwz r7,28(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// lwz r3,-2288(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -2288);
	// vmsum3fp128 v60,v127,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// lhz r4,8(r7)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + 8);
	// vmrghw128 v59,v60,v124
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v124.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// vmrghw128 v58,v124,v59
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v124.u32)));
	// vmulfp128 v1,v58,v123
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v123.f32)));
	// bl 0x8258d938
	ctx.lr = 0x82380650;
	sub_8258D938(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dd7c4
	ctx.lr = 0x82380660;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba20
	ctx.lr = 0x82380668;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8238066C"))) PPC_WEAK_FUNC(sub_8238066C);
PPC_FUNC_IMPL(__imp__sub_8238066C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82380670"))) PPC_WEAK_FUNC(sub_82380670);
PPC_FUNC_IMPL(__imp__sub_82380670) {
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
	// bl 0x8237fb18
	ctx.lr = 0x82380688;
	sub_8237FB18(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,376(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 376, temp.u32);
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

__attribute__((alias("__imp__sub_823806A8"))) PPC_WEAK_FUNC(sub_823806A8);
PPC_FUNC_IMPL(__imp__sub_823806A8) {
	PPC_FUNC_PROLOGUE();
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823806B4"))) PPC_WEAK_FUNC(sub_823806B4);
PPC_FUNC_IMPL(__imp__sub_823806B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823806B8"))) PPC_WEAK_FUNC(sub_823806B8);
PPC_FUNC_IMPL(__imp__sub_823806B8) {
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
	// bl 0x8256ad18
	ctx.lr = 0x823806D0;
	sub_8256AD18(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,-18540
	ctx.r8.s64 = ctx.r10.s64 + -18540;
	// stb r9,40(r31)
	PPC_STORE_U8(r31.u32 + 40, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,28(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
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

__attribute__((alias("__imp__sub_82380710"))) PPC_WEAK_FUNC(sub_82380710);
PPC_FUNC_IMPL(__imp__sub_82380710) {
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
	// bl 0x8256ad60
	ctx.lr = 0x82380728;
	sub_8256AD60(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,40(r31)
	PPC_STORE_U8(r31.u32 + 40, ctx.r10.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
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

__attribute__((alias("__imp__sub_82380750"))) PPC_WEAK_FUNC(sub_82380750);
PPC_FUNC_IMPL(__imp__sub_82380750) {
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
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x8232c638
	ctx.lr = 0x8238076C;
	sub_8232C638(ctx, base);
	// lwz r11,148(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f13,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-7912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	f0.f64 = double(temp.f32);
	// lfd f2,-32664(r10)
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r10.u32 + -32664);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x823dc480
	ctx.lr = 0x8238078C;
	sub_823DC480(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f11,88(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// fdivs f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 / ctx.f12.f64));
	// fmuls f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stfs f9,28(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// lfs f8,92(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 92);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f10.f64));
	// stfs f7,32(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lfs f6,68(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f6,f10
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f10.f64));
	// stfs f5,24(r31)
	temp.f32 = float(ctx.f5.f64);
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

__attribute__((alias("__imp__sub_823807D8"))) PPC_WEAK_FUNC(sub_823807D8);
PPC_FUNC_IMPL(__imp__sub_823807D8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-18540
	ctx.r10.s64 = r11.s64 + -18540;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8256ad70
	ctx.lr = 0x82380804;
	sub_8256AD70(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8238081c
	if (cr6.eq) goto loc_8238081C;
	// bl 0x82130588
	ctx.lr = 0x82380818;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8238081C:
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

__attribute__((alias("__imp__sub_82380834"))) PPC_WEAK_FUNC(sub_82380834);
PPC_FUNC_IMPL(__imp__sub_82380834) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82380838"))) PPC_WEAK_FUNC(sub_82380838);
PPC_FUNC_IMPL(__imp__sub_82380838) {
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
	// lbz r11,40(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82380860
	if (cr6.eq) goto loc_82380860;
	// lfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	f0.f64 = double(temp.f32);
	// b 0x82380864
	goto loc_82380864;
loc_82380860:
	// lfs f0,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	f0.f64 = double(temp.f32);
loc_82380864:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238087C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f0,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82380898
	if (!cr6.gt) goto loc_82380898;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
loc_82380898:
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// bl 0x8256ada8
	ctx.lr = 0x823808B0;
	sub_8256ADA8(ctx, base);
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

__attribute__((alias("__imp__sub_823808C4"))) PPC_WEAK_FUNC(sub_823808C4);
PPC_FUNC_IMPL(__imp__sub_823808C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823808C8"))) PPC_WEAK_FUNC(sub_823808C8);
PPC_FUNC_IMPL(__imp__sub_823808C8) {
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
	// bl 0x82562a00
	ctx.lr = 0x823808E0;
	sub_82562A00(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r9,r10,-18220
	ctx.r9.s64 = ctx.r10.s64 + -18220;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stfs f0,1088(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1088, temp.u32);
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

__attribute__((alias("__imp__sub_82380910"))) PPC_WEAK_FUNC(sub_82380910);
PPC_FUNC_IMPL(__imp__sub_82380910) {
	PPC_FUNC_PROLOGUE();
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
	// bl 0x82562728
	ctx.lr = 0x82380928;
	sub_82562728(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82380948
	if (!cr6.gt) goto loc_82380948;
	// lfs f0,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// b 0x8238094c
	goto loc_8238094C;
loc_82380948:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
loc_8238094C:
	// stfs f0,1072(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1072, temp.u32);
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

__attribute__((alias("__imp__sub_82380964"))) PPC_WEAK_FUNC(sub_82380964);
PPC_FUNC_IMPL(__imp__sub_82380964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82380968"))) PPC_WEAK_FUNC(sub_82380968);
PPC_FUNC_IMPL(__imp__sub_82380968) {
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
	// bl 0x82562718
	ctx.lr = 0x82380980;
	sub_82562718(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,1088(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1088, temp.u32);
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

__attribute__((alias("__imp__sub_823809A0"))) PPC_WEAK_FUNC(sub_823809A0);
PPC_FUNC_IMPL(__imp__sub_823809A0) {
	PPC_FUNC_PROLOGUE();
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,1088(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1088);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x823809f0
	if (cr6.gt) goto loc_823809F0;
	// bl 0x82562750
	ctx.lr = 0x823809D0;
	sub_82562750(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x823809e8
	if (!cr6.gt) goto loc_823809E8;
	// lfs f0,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	f0.f64 = double(temp.f32);
	// b 0x823809ec
	goto loc_823809EC;
loc_823809E8:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
loc_823809EC:
	// stfs f0,1072(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1072, temp.u32);
loc_823809F0:
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

__attribute__((alias("__imp__sub_82380A08"))) PPC_WEAK_FUNC(sub_82380A08);
PPC_FUNC_IMPL(__imp__sub_82380A08) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-18220
	ctx.r10.s64 = r11.s64 + -18220;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82562708
	ctx.lr = 0x82380A34;
	sub_82562708(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82380a4c
	if (cr6.eq) goto loc_82380A4C;
	// bl 0x82130588
	ctx.lr = 0x82380A48;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82380A4C:
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

__attribute__((alias("__imp__sub_82380A64"))) PPC_WEAK_FUNC(sub_82380A64);
PPC_FUNC_IMPL(__imp__sub_82380A64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82380A68"))) PPC_WEAK_FUNC(sub_82380A68);
PPC_FUNC_IMPL(__imp__sub_82380A68) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// lfs f0,1088(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1088);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82380aac
	if (!cr6.gt) goto loc_82380AAC;
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,1088(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1088, temp.u32);
loc_82380AAC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82562740
	ctx.lr = 0x82380AB4;
	sub_82562740(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82380b08
	if (cr6.eq) goto loc_82380B08;
	// lfs f0,1072(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1072);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82380b08
	if (!cr6.gt) goto loc_82380B08;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82562788
	ctx.lr = 0x82380AD4;
	sub_82562788(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,1072(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1072);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// stfs f11,1072(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 1072, temp.u32);
	// lfs f10,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f11,f9
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// fsel f7,f8,f11,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f11.f64 : ctx.f9.f64;
	// fsubs f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f10.f64));
	// fsel f5,f6,f10,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f10.f64 : ctx.f7.f64;
	// stfs f5,1072(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 1072, temp.u32);
loc_82380B08:
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

__attribute__((alias("__imp__sub_82380B24"))) PPC_WEAK_FUNC(sub_82380B24);
PPC_FUNC_IMPL(__imp__sub_82380B24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82380B28"))) PPC_WEAK_FUNC(sub_82380B28);
PPC_FUNC_IMPL(__imp__sub_82380B28) {
	PPC_FUNC_PROLOGUE();
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82380B34"))) PPC_WEAK_FUNC(sub_82380B34);
PPC_FUNC_IMPL(__imp__sub_82380B34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82380B38"))) PPC_WEAK_FUNC(sub_82380B38);
PPC_FUNC_IMPL(__imp__sub_82380B38) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82380B4C"))) PPC_WEAK_FUNC(sub_82380B4C);
PPC_FUNC_IMPL(__imp__sub_82380B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82380B50"))) PPC_WEAK_FUNC(sub_82380B50);
PPC_FUNC_IMPL(__imp__sub_82380B50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r8,-17888
	ctx.r6.s64 = ctx.r8.s64 + -17888;
	// lfs f13,-15468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15468);
	ctx.f13.f64 = double(temp.f32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f12,32680(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32680);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stfs f13,12(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stfs f12,16(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r5,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r5.u8);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82380B98"))) PPC_WEAK_FUNC(sub_82380B98);
PPC_FUNC_IMPL(__imp__sub_82380B98) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-17888
	ctx.r10.s64 = r11.s64 + -17888;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x82380BC4;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82380bdc
	if (cr6.eq) goto loc_82380BDC;
	// bl 0x82130588
	ctx.lr = 0x82380BD8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82380BDC:
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

__attribute__((alias("__imp__sub_82380BF4"))) PPC_WEAK_FUNC(sub_82380BF4);
PPC_FUNC_IMPL(__imp__sub_82380BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82380BF8"))) PPC_WEAK_FUNC(sub_82380BF8);
PPC_FUNC_IMPL(__imp__sub_82380BF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82380C10;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f29,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lfs f0,40(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x8238136c
	if (cr6.eq) goto loc_8238136C;
	// lfs f0,32(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 32);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x8238136c
	if (cr6.eq) goto loc_8238136C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,28(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	f0.f64 = double(temp.f32);
	// lfs f28,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f28.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bge cr6,0x8238136c
	if (!cr6.lt) goto loc_8238136C;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f31,f29
	f31.f64 = f29.f64;
	// lwz r9,400(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 400);
	// lwz r11,20(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x82380d04
	if (cr6.lt) goto loc_82380D04;
	// addi r8,r10,5
	ctx.r8.s64 = ctx.r10.s64 + 5;
	// rlwinm r5,r11,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r11,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// subf r10,r5,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r5.s64;
loc_82380C88:
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82380ca4
	if (cr6.eq) goto loc_82380CA4;
	// lfs f0,520(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82380ca4
	if (!cr6.gt) goto loc_82380CA4;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_82380CA4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82380cc0
	if (cr6.eq) goto loc_82380CC0;
	// lfs f0,520(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82380cc0
	if (!cr6.gt) goto loc_82380CC0;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_82380CC0:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82380cdc
	if (cr6.eq) goto loc_82380CDC;
	// lfs f0,520(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82380cdc
	if (!cr6.gt) goto loc_82380CDC;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_82380CDC:
	// lwz r9,-8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82380cf8
	if (cr6.eq) goto loc_82380CF8;
	// lfs f0,520(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82380cf8
	if (!cr6.gt) goto loc_82380CF8;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_82380CF8:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne 0x82380c88
	if (!cr0.eq) goto loc_82380C88;
loc_82380D04:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82380d48
	if (cr6.lt) goto loc_82380D48;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r9,r10,6
	ctx.r9.s64 = ctx.r10.s64 + 6;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 400);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
loc_82380D20:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82380d3c
	if (cr6.eq) goto loc_82380D3C;
	// lfs f0,520(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82380d3c
	if (!cr6.gt) goto loc_82380D3C;
	// fmr f31,f0
	f31.f64 = f0.f64;
loc_82380D3C:
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bge 0x82380d20
	if (!cr0.lt) goto loc_82380D20;
loc_82380D48:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// ble 0x82380d68
	if (!cr0.gt) goto loc_82380D68;
	// lwz r10,24(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x82380d6c
	if (!cr6.gt) goto loc_82380D6C;
loc_82380D68:
	// li r11,0
	r11.s64 = 0;
loc_82380D6C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f30,14884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f30.f64 = double(temp.f32);
	// beq cr6,0x82380e24
	if (cr6.eq) goto loc_82380E24;
	// lfs f0,580(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 580);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bgt cr6,0x82380e20
	if (cr6.gt) goto loc_82380E20;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,136(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// lfs f13,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// bge cr6,0x82380dac
	if (!cr6.lt) goto loc_82380DAC;
	// lfs f12,140(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bgt cr6,0x82380e20
	if (cr6.gt) goto loc_82380E20;
loc_82380DAC:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x82380dc0
	if (!cr6.lt) goto loc_82380DC0;
	// lfs f0,144(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x82380e20
	if (cr6.gt) goto loc_82380E20;
loc_82380DC0:
	// lfs f0,572(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 572);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82380e20
	if (cr6.lt) goto loc_82380E20;
	// bl 0x823eaef8
	ctx.lr = 0x82380DDC;
	sub_823EAEF8(ctx, base);
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82380e24
	if (cr6.eq) goto loc_82380E24;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x823eaef8
	ctx.lr = 0x82380DF0;
	sub_823EAEF8(ctx, base);
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82380e10
	if (!cr6.eq) goto loc_82380E10;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82380e14
	if (cr6.eq) goto loc_82380E14;
loc_82380E10:
	// li r11,0
	r11.s64 = 0;
loc_82380E14:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82380e24
	if (cr6.eq) goto loc_82380E24;
loc_82380E20:
	// li r30,0
	r30.s64 = 0;
loc_82380E24:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,136(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 - f30.f64));
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// beq cr6,0x82380e94
	if (cr6.eq) goto loc_82380E94;
	// fsel f0,f0,f0,f29
	f0.f64 = f0.f64 >= 0.0 ? f0.f64 : f29.f64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f28
	ctx.f12.f64 = double(float(f0.f64 - f28.f64));
	// fsel f11,f12,f28,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f28.f64 : f0.f64;
	// fmuls f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64));
	// fcmpu cr6,f10,f13
	cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// ble cr6,0x82380e94
	if (!cr6.gt) goto loc_82380E94;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lfs f13,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmadds f11,f13,f0,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64 + ctx.f12.f64));
	// stfs f11,24(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fcmpu cr6,f11,f28
	cr6.compare(ctx.f11.f64, f28.f64);
	// ble cr6,0x82380ebc
	if (!cr6.gt) goto loc_82380EBC;
	// stfs f28,24(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// b 0x82380ebc
	goto loc_82380EBC;
loc_82380E94:
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x82380ebc
	if (!cr6.gt) goto loc_82380EBC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f12,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f11,f12,f13,f0
	ctx.f11.f64 = double(float(-(ctx.f12.f64 * ctx.f13.f64 - f0.f64)));
	// stfs f11,24(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
loc_82380EBC:
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82380f90
	if (cr6.eq) goto loc_82380F90;
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x82380f28
	if (!cr6.gt) goto loc_82380F28;
	// bl 0x8232c638
	ctx.lr = 0x82380ED8;
	sub_8232C638(ctx, base);
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82380efc
	if (!cr6.eq) goto loc_82380EFC;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82380efc
	if (!cr6.eq) goto loc_82380EFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8255a908
	ctx.lr = 0x82380EFC;
	sub_8255A908(ctx, base);
loc_82380EFC:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8232c638
	ctx.lr = 0x82380F04;
	sub_8232C638(ctx, base);
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82380f90
	if (!cr6.eq) goto loc_82380F90;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82380f90
	if (!cr6.eq) goto loc_82380F90;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82380f8c
	goto loc_82380F8C;
loc_82380F28:
	// lfs f13,580(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 580);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// bgt cr6,0x82380f90
	if (cr6.gt) goto loc_82380F90;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x82380f90
	if (!cr6.lt) goto loc_82380F90;
	// bl 0x8232c638
	ctx.lr = 0x82380F40;
	sub_8232C638(ctx, base);
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82380f64
	if (!cr6.eq) goto loc_82380F64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82380f64
	if (!cr6.eq) goto loc_82380F64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x8255a908
	ctx.lr = 0x82380F64;
	sub_8255A908(ctx, base);
loc_82380F64:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8232c638
	ctx.lr = 0x82380F6C;
	sub_8232C638(ctx, base);
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x82380f90
	if (!cr6.eq) goto loc_82380F90;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,372(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 372);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82380f90
	if (!cr6.eq) goto loc_82380F90;
	// li r4,3
	ctx.r4.s64 = 3;
loc_82380F8C:
	// bl 0x8255a908
	ctx.lr = 0x82380F90;
	sub_8255A908(ctx, base);
loc_82380F90:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,24(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lfs f0,8884(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8884);
	f0.f64 = double(temp.f32);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// addi r11,r10,1
	r11.s64 = ctx.r10.s64 + 1;
	// mr r7,r10
	ctx.r7.u64 = ctx.r10.u64;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// blt cr6,0x8238116c
	if (cr6.lt) goto loc_8238116C;
	// rlwinm r10,r11,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r11,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r7,r10,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r10.s64;
loc_82380FC4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82381028
	if (cr6.eq) goto loc_82381028;
	// lfs f13,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// ble cr6,0x82381014
	if (!cr6.gt) goto loc_82381014;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,116(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f9,120(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f10,468(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f6,f7,f12,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f6,472(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
	// b 0x82381028
	goto loc_82381028;
loc_82381014:
	// lfs f13,116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f12,120(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,472(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_82381028:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82381090
	if (cr6.eq) goto loc_82381090;
	// lfs f13,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// ble cr6,0x8238107c
	if (!cr6.gt) goto loc_8238107C;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,116(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f9,120(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f10,468(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f6,f7,f12,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f6,472(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
	// b 0x82381090
	goto loc_82381090;
loc_8238107C:
	// lfs f13,116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f12,120(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,472(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_82381090:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r9,-12
	ctx.r10.s64 = ctx.r9.s64 + -12;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823810fc
	if (cr6.eq) goto loc_823810FC;
	// lfs f13,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// ble cr6,0x823810e8
	if (!cr6.gt) goto loc_823810E8;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,116(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f9,120(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f10,468(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f6,f7,f12,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f6,472(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
	// b 0x823810fc
	goto loc_823810FC;
loc_823810E8:
	// lfs f13,116(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f12,120(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,472(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_823810FC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwzx r11,r6,r10
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82381160
	if (cr6.eq) goto loc_82381160;
	// lfs f13,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// ble cr6,0x8238114c
	if (!cr6.gt) goto loc_8238114C;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,116(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f9,120(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f10,468(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f6,f7,f12,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f6,472(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
	// b 0x82381160
	goto loc_82381160;
loc_8238114C:
	// lfs f13,116(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f12,120(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,472(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_82381160:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,-16
	ctx.r9.s64 = ctx.r9.s64 + -16;
	// bne 0x82380fc4
	if (!cr0.eq) goto loc_82380FC4;
loc_8238116C:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// blt cr6,0x823811e4
	if (cr6.lt) goto loc_823811E4;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
loc_82381178:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x823811d8
	if (cr6.eq) goto loc_823811D8;
	// lfs f13,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// ble cr6,0x823811c8
	if (!cr6.gt) goto loc_823811C8;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,116(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// lfs f9,120(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// stfs f10,468(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// fsubs f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 - f0.f64));
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f6,f7,f12,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f9.f64));
	// stfs f6,472(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
	// b 0x823811d8
	goto loc_823811D8;
loc_823811C8:
	// lfs f13,116(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,468(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 468, temp.u32);
	// lfs f12,120(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,472(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_823811D8:
	// addic. r7,r7,-1
	xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x82381178
	if (!cr0.lt) goto loc_82381178;
loc_823811E4:
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x8238135c
	if (!cr6.gt) goto loc_8238135C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,400(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 400);
	// lwz r11,20(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// blt cr6,0x8238130c
	if (cr6.lt) goto loc_8238130C;
	// addi r11,r9,5
	r11.s64 = ctx.r9.s64 + 5;
	// rlwinm r7,r10,0,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
loc_82381224:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,400(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 400);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238125c
	if (cr6.eq) goto loc_8238125C;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,120(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f10,472(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 472, temp.u32);
loc_8238125C:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r7,400(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 400);
	// lwzx r10,r7,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82381290
	if (cr6.eq) goto loc_82381290;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,120(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f10,472(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 472, temp.u32);
loc_82381290:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,400(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 400);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,-4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + -4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823812c8
	if (cr6.eq) goto loc_823812C8;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,120(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f10,472(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 472, temp.u32);
loc_823812C8:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,400(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 400);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,-8(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82381300
	if (cr6.eq) goto loc_82381300;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// lwz r6,4(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,120(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f0,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// stfs f10,472(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 472, temp.u32);
loc_82381300:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne 0x82381224
	if (!cr0.eq) goto loc_82381224;
loc_8238130C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x8238135c
	if (cr6.lt) goto loc_8238135C;
	// addi r11,r9,6
	r11.s64 = ctx.r9.s64 + 6;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
loc_8238131C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,400(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 400);
	// lwzx r11,r8,r10
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82381350
	if (cr6.eq) goto loc_82381350;
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// lwz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f13,40(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,120(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmadds f10,f11,f0,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f12.f64));
	// stfs f10,472(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_82381350:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x8238131c
	if (!cr0.lt) goto loc_8238131C;
loc_8238135C:
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x8238136c
	if (!cr6.lt) goto loc_8238136C;
	// stfs f29,24(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
loc_8238136C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba24
	ctx.lr = 0x82381378;
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

__attribute__((alias("__imp__sub_8238138C"))) PPC_WEAK_FUNC(sub_8238138C);
PPC_FUNC_IMPL(__imp__sub_8238138C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82381390"))) PPC_WEAK_FUNC(sub_82381390);
PPC_FUNC_IMPL(__imp__sub_82381390) {
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
	// bl 0x825640f8
	ctx.lr = 0x823813A8;
	sub_825640F8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r11,-17580
	ctx.r9.s64 = r11.s64 + -17580;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_823813D4"))) PPC_WEAK_FUNC(sub_823813D4);
PPC_FUNC_IMPL(__imp__sub_823813D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823813D8"))) PPC_WEAK_FUNC(sub_823813D8);
PPC_FUNC_IMPL(__imp__sub_823813D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-7964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7964);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823813E4"))) PPC_WEAK_FUNC(sub_823813E4);
PPC_FUNC_IMPL(__imp__sub_823813E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823813E8"))) PPC_WEAK_FUNC(sub_823813E8);
PPC_FUNC_IMPL(__imp__sub_823813E8) {
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
	// bl 0x825641a0
	ctx.lr = 0x82381400;
	sub_825641A0(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-17580
	ctx.r10.s64 = r11.s64 + -17580;
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

__attribute__((alias("__imp__sub_82381424"))) PPC_WEAK_FUNC(sub_82381424);
PPC_FUNC_IMPL(__imp__sub_82381424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82381428"))) PPC_WEAK_FUNC(sub_82381428);
PPC_FUNC_IMPL(__imp__sub_82381428) {
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
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x82381440;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8238147c
	if (cr6.eq) goto loc_8238147C;
	// bl 0x825640f8
	ctx.lr = 0x82381450;
	sub_825640F8(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r9,r11,-17580
	ctx.r9.s64 = r11.s64 + -17580;
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
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
loc_8238147C:
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

__attribute__((alias("__imp__sub_82381494"))) PPC_WEAK_FUNC(sub_82381494);
PPC_FUNC_IMPL(__imp__sub_82381494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82381498"))) PPC_WEAK_FUNC(sub_82381498);
PPC_FUNC_IMPL(__imp__sub_82381498) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-7964
	r31.s64 = r11.s64 + -7964;
	// lwz r11,-7964(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7964);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823815a8
	if (!cr6.eq) goto loc_823815A8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x823814C8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x823814dc
	if (cr6.eq) goto loc_823814DC;
	// bl 0x821d5408
	ctx.lr = 0x823814D8;
	sub_821D5408(ctx, base);
	// b 0x823814e0
	goto loc_823814E0;
loc_823814DC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_823814E0:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17564
	ctx.r7.s64 = ctx.r10.s64 + -17564;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,28
	ctx.r5.s64 = 28;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32200
	ctx.r8.s64 = -2110259200;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,5160
	ctx.r4.s64 = ctx.r8.s64 + 5160;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r3,31620
	ctx.r9.s64 = ctx.r3.s64 + 31620;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// li r10,24
	ctx.r10.s64 = 24;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x82381554;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x82381564;
	sub_821D4100(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x821d41d0
	ctx.lr = 0x82381580;
	sub_821D41D0(ctx, base);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,31644
	ctx.r4.s64 = ctx.r5.s64 + 31644;
	// bl 0x821d4b00
	ctx.lr = 0x82381590;
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
	ctx.lr = 0x823815A8;
	sub_821C0548(ctx, base);
loc_823815A8:
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

__attribute__((alias("__imp__sub_823815C0"))) PPC_WEAK_FUNC(sub_823815C0);
PPC_FUNC_IMPL(__imp__sub_823815C0) {
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
	// bl 0x825640f8
	ctx.lr = 0x823815D8;
	sub_825640F8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f0,48(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// lis r5,-32251
	ctx.r5.s64 = -2113601536;
	// lfs f13,14992(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14992);
	ctx.f13.f64 = double(temp.f32);
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// lfs f12,25728(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 25728);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r10,-17144
	r11.s64 = ctx.r10.s64 + -17144;
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f10,-17152(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -17152);
	ctx.f10.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f12,40(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// lfs f11,14988(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14988);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,-17156(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -17156);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29232(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -29232);
	ctx.f12.f64 = double(temp.f32);
	// stfs f11,52(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f12,60(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f10,64(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f0,92(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f0,100(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f0,104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
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

__attribute__((alias("__imp__sub_82381684"))) PPC_WEAK_FUNC(sub_82381684);
PPC_FUNC_IMPL(__imp__sub_82381684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82381688"))) PPC_WEAK_FUNC(sub_82381688);
PPC_FUNC_IMPL(__imp__sub_82381688) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-7960(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7960);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82381694"))) PPC_WEAK_FUNC(sub_82381694);
PPC_FUNC_IMPL(__imp__sub_82381694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82381698"))) PPC_WEAK_FUNC(sub_82381698);
PPC_FUNC_IMPL(__imp__sub_82381698) {
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
	// bl 0x825641a0
	ctx.lr = 0x823816B0;
	sub_825641A0(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-17144
	ctx.r10.s64 = r11.s64 + -17144;
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

__attribute__((alias("__imp__sub_823816D4"))) PPC_WEAK_FUNC(sub_823816D4);
PPC_FUNC_IMPL(__imp__sub_823816D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823816D8"))) PPC_WEAK_FUNC(sub_823816D8);
PPC_FUNC_IMPL(__imp__sub_823816D8) {
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x823816E0;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d8
	ctx.lr = 0x823816E8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r11,132(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 132);
	// lfs f30,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f30.f64 = double(temp.f32);
	// lwz r30,92(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// addi r28,r11,64
	r28.s64 = r11.s64 + 64;
	// lwz r8,416(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 416);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r7,412(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 412);
	// lfs f0,388(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 388);
	f0.f64 = double(temp.f32);
	// lfs f13,388(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 388);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fmuls f29,f12,f30
	f29.f64 = double(float(ctx.f12.f64 * f30.f64));
	// bl 0x82392f08
	ctx.lr = 0x82381734;
	sub_82392F08(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82392f08
	ctx.lr = 0x82381744;
	sub_82392F08(ctx, base);
	// lwz r6,8(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// fadds f11,f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f28.f64 + ctx.f1.f64));
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lwz r11,416(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 416);
	// lwz r10,412(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 412);
	// lvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f0,8884(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8884);
	f0.f64 = double(temp.f32);
	// lfs f9,432(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 432);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,432(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 432);
	ctx.f8.f64 = double(temp.f32);
	// fmsubs f7,f11,f30,f29
	ctx.f7.f64 = double(float(ctx.f11.f64 * f30.f64 - f29.f64));
	// fadds f6,f9,f8
	ctx.f6.f64 = double(float(ctx.f9.f64 + ctx.f8.f64));
	// fmadds f5,f6,f30,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 * f30.f64 + ctx.f7.f64));
	// fsubs f13,f10,f5
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f5.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82381798
	if (!cr6.lt) goto loc_82381798;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_82381798:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,48
	ctx.r10.s64 = 48;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lfs f0,212(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 212);
	f0.f64 = double(temp.f32);
	// lfs f13,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f31,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// stfs f11,212(r30)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r30.u32 + 212, temp.u32);
	// lfs f10,116(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 116);
	ctx.f10.f64 = double(temp.f32);
	// lwz r10,96(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 96);
	// lfs f9,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f31,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f10.f64));
	// stfs f7,116(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lfs f6,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f6.f64 = double(temp.f32);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f5,120(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 120);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fmadds f3,f4,f31,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 * f31.f64 + ctx.f5.f64));
	// stfs f3,120(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// lwz r11,140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// lfs f2,52(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,116(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 116);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f0,f2,f1
	f0.f64 = double(float(ctx.f2.f64 - ctx.f1.f64));
	// fmadds f12,f0,f31,f1
	ctx.f12.f64 = double(float(f0.f64 * f31.f64 + ctx.f1.f64));
	// stfs f12,116(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 116, temp.u32);
	// lwz r11,140(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 140);
	// lfs f11,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,120(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 120);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// fmadds f8,f9,f31,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * f31.f64 + ctx.f10.f64));
	// stfs f8,120(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 120, temp.u32);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lfs f7,60(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 60);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,112(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmadds f4,f5,f31,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 * f31.f64 + ctx.f6.f64));
	// stfs f4,112(r11)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r11.u32 + 112, temp.u32);
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lfs f3,64(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 64);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f3,f2
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f2.f64));
	// fmadds f0,f1,f31,f2
	f0.f64 = double(float(ctx.f1.f64 * f31.f64 + ctx.f2.f64));
	// stfs f0,40(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 40, temp.u32);
	// lfs f0,68(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 68);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82381874
	if (!cr6.gt) goto loc_82381874;
	// lfs f12,84(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,84(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 84, temp.u32);
loc_82381874:
	// lfs f0,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82381890
	if (!cr6.gt) goto loc_82381890;
	// lfs f12,68(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,68(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 68, temp.u32);
loc_82381890:
	// lfs f0,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x823818ac
	if (!cr6.gt) goto loc_823818AC;
	// lfs f12,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,24(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
loc_823818AC:
	// lfs f0,80(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x823818c8
	if (!cr6.gt) goto loc_823818C8;
	// lfs f12,76(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,76(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 76, temp.u32);
loc_823818C8:
	// lfs f0,84(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x823818e4
	if (!cr6.gt) goto loc_823818E4;
	// lfs f12,80(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,80(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 80, temp.u32);
loc_823818E4:
	// lfs f0,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82381900
	if (!cr6.gt) goto loc_82381900;
	// lfs f12,92(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,92(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 92, temp.u32);
loc_82381900:
	// lfs f0,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8238191c
	if (!cr6.gt) goto loc_8238191C;
	// lfs f12,52(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,52(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 52, temp.u32);
loc_8238191C:
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82381938
	if (!cr6.gt) goto loc_82381938;
	// lfs f12,108(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,108(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 108, temp.u32);
loc_82381938:
	// lfs f0,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 100);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82381954
	if (!cr6.gt) goto loc_82381954;
	// lfs f12,112(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f12
	ctx.f11.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fmadds f10,f11,f31,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * f31.f64 + ctx.f12.f64));
	// stfs f10,112(r10)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r10.u32 + 112, temp.u32);
loc_82381954:
	// lfs f0,104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82381970
	if (!cr6.gt) goto loc_82381970;
	// lfs f13,100(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmadds f11,f12,f31,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f31.f64 + ctx.f13.f64));
	// stfs f11,100(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 100, temp.u32);
loc_82381970:
	// lwz r31,8(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lfs f0,56(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	f0.f64 = double(temp.f32);
	// lfs f13,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f12,112(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// bl 0x8232d8b8
	ctx.lr = 0x82381998;
	sub_8232D8B8(ctx, base);
	// lwz r11,412(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 412);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823819b0
	if (cr6.eq) goto loc_823819B0;
	// lwz r10,136(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lfs f0,120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	f0.f64 = double(temp.f32);
	// stfs f0,472(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_823819B0:
	// lwz r11,420(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 420);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823819c8
	if (cr6.eq) goto loc_823819C8;
	// lwz r10,136(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lfs f0,120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	f0.f64 = double(temp.f32);
	// stfs f0,472(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_823819C8:
	// lwz r11,416(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 416);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823819e0
	if (cr6.eq) goto loc_823819E0;
	// lwz r10,136(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lfs f0,120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	f0.f64 = double(temp.f32);
	// stfs f0,472(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_823819E0:
	// lwz r11,424(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 424);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x823819f8
	if (cr6.eq) goto loc_823819F8;
	// lwz r10,136(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lfs f0,120(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 120);
	f0.f64 = double(temp.f32);
	// stfs f0,472(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 472, temp.u32);
loc_823819F8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba24
	ctx.lr = 0x82381A04;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82381A08"))) PPC_WEAK_FUNC(sub_82381A08);
PPC_FUNC_IMPL(__imp__sub_82381A08) {
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
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x82381A1C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82381a38
	if (cr6.eq) goto loc_82381A38;
	// bl 0x823815c0
	ctx.lr = 0x82381A28;
	sub_823815C0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82381A38:
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

__attribute__((alias("__imp__sub_82381A4C"))) PPC_WEAK_FUNC(sub_82381A4C);
PPC_FUNC_IMPL(__imp__sub_82381A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82381A50"))) PPC_WEAK_FUNC(sub_82381A50);
PPC_FUNC_IMPL(__imp__sub_82381A50) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-7960
	r31.s64 = r11.s64 + -7960;
	// lwz r11,-7960(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7960);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82381c50
	if (!cr6.eq) goto loc_82381C50;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82381A80;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82381a94
	if (cr6.eq) goto loc_82381A94;
	// bl 0x821d5408
	ctx.lr = 0x82381A90;
	sub_821D5408(ctx, base);
	// b 0x82381a98
	goto loc_82381A98;
loc_82381A94:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82381A98:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-17128
	ctx.r7.s64 = ctx.r10.s64 + -17128;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,112
	ctx.r5.s64 = 112;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32200
	ctx.r8.s64 = -2110259200;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,6664
	ctx.r4.s64 = ctx.r8.s64 + 6664;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,31692
	ctx.r9.s64 = ctx.r3.s64 + 31692;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,31716
	ctx.r8.s64 = ctx.r10.s64 + 31716;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,32
	ctx.r10.s64 = 32;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r11,48
	r11.s64 = 48;
	// addi r6,r5,31752
	ctx.r6.s64 = ctx.r5.s64 + 31752;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,52
	ctx.r9.s64 = 52;
	// addi r5,r4,31776
	ctx.r5.s64 = ctx.r4.s64 + 31776;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r7,31800
	ctx.r4.s64 = ctx.r7.s64 + 31800;
	// addi r6,r8,31824
	ctx.r6.s64 = ctx.r8.s64 + 31824;
	// li r11,56
	r11.s64 = 56;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r10,60
	ctx.r10.s64 = 60;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,31848
	ctx.r5.s64 = ctx.r7.s64 + 31848;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,31872
	ctx.r4.s64 = r30.s64 + 31872;
	// addi r6,r8,31896
	ctx.r6.s64 = ctx.r8.s64 + 31896;
	// li r11,68
	r11.s64 = 68;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r10,72
	ctx.r10.s64 = 72;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// li r9,76
	ctx.r9.s64 = 76;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,31920
	ctx.r5.s64 = ctx.r7.s64 + 31920;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,31944
	ctx.r4.s64 = r30.s64 + 31944;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r6,r8,31968
	ctx.r6.s64 = ctx.r8.s64 + 31968;
	// li r11,80
	r11.s64 = 80;
	// li r10,84
	ctx.r10.s64 = 84;
	// addi r8,r7,31992
	ctx.r8.s64 = ctx.r7.s64 + 31992;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// addi r7,r30,32016
	ctx.r7.s64 = r30.s64 + 32016;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r9,104
	ctx.r9.s64 = 104;
	// li r11,88
	r11.s64 = 88;
	// li r10,92
	ctx.r10.s64 = 92;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r9,r6,32040
	ctx.r9.s64 = ctx.r6.s64 + 32040;
	// addi r8,r11,32064
	ctx.r8.s64 = r11.s64 + 32064;
	// li r11,96
	r11.s64 = 96;
	// li r10,100
	ctx.r10.s64 = 100;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// bl 0x821d4458
	ctx.lr = 0x82381BFC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x82381C0C;
	sub_821D4100(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// bl 0x821d41d0
	ctx.lr = 0x82381C28;
	sub_821D41D0(ctx, base);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,32088
	ctx.r4.s64 = ctx.r5.s64 + 32088;
	// bl 0x821d4b00
	ctx.lr = 0x82381C38;
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
	ctx.lr = 0x82381C50;
	sub_821C0548(ctx, base);
loc_82381C50:
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

__attribute__((alias("__imp__sub_82381C68"))) PPC_WEAK_FUNC(sub_82381C68);
PPC_FUNC_IMPL(__imp__sub_82381C68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// li r11,0
	r11.s64 = 0;
	// li r8,80
	ctx.r8.s64 = 80;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r7,96
	ctx.r7.s64 = 96;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32114
	ctx.r5.s64 = -2104623104;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,2
	ctx.r4.s64 = 2;
	// stvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, r11.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f0,-31068(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31068);
	f0.f64 = double(temp.f32);
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// stfs f0,116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r10,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// lwz r11,-32452(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -32452);
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82381CE4"))) PPC_WEAK_FUNC(sub_82381CE4);
PPC_FUNC_IMPL(__imp__sub_82381CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82381CE8"))) PPC_WEAK_FUNC(sub_82381CE8);
PPC_FUNC_IMPL(__imp__sub_82381CE8) {
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
	ctx.lr = 0x82381CF0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// addi r29,r11,19856
	r29.s64 = r11.s64 + 19856;
	// stw r4,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r4.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,14(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 14);
	// bl 0x82144a28
	ctx.lr = 0x82381D14;
	sub_82144A28(ctx, base);
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,18(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 18);
	// bl 0x82144a28
	ctx.lr = 0x82381D28;
	sub_82144A28(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,10(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 10);
	// bl 0x82144a28
	ctx.lr = 0x82381D3C;
	sub_82144A28(ctx, base);
	// stw r3,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r3.u32);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,22(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 22);
	// bl 0x82144a28
	ctx.lr = 0x82381D50;
	sub_82144A28(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82381D60"))) PPC_WEAK_FUNC(sub_82381D60);
PPC_FUNC_IMPL(__imp__sub_82381D60) {
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
	ctx.lr = 0x82381D68;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32119
	r31.s64 = -2104950784;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// lis r30,-32114
	r30.s64 = -2104623104;
	// lis r26,-32119
	r26.s64 = -2104950784;
	// lwz r11,-7940(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7940);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82381dbc
	if (!cr6.eq) goto loc_82381DBC;
	// lwz r3,-23464(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -23464);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// addi r4,r10,-16744
	ctx.r4.s64 = ctx.r10.s64 + -16744;
	// stw r11,-7940(r31)
	PPC_STORE_U32(r31.u32 + -7940, r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82381DB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-7940(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7940);
	// stw r3,-7944(r26)
	PPC_STORE_U32(r26.u32 + -7944, ctx.r3.u32);
loc_82381DBC:
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// lis r27,-32119
	r27.s64 = -2104950784;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82381df8
	if (!cr6.eq) goto loc_82381DF8;
	// lwz r3,-23464(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -23464);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// addi r4,r10,-16764
	ctx.r4.s64 = ctx.r10.s64 + -16764;
	// stw r11,-7940(r31)
	PPC_STORE_U32(r31.u32 + -7940, r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82381DF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-7940(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7940);
	// stw r3,-7948(r27)
	PPC_STORE_U32(r27.u32 + -7948, ctx.r3.u32);
loc_82381DF8:
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82381e34
	if (!cr6.eq) goto loc_82381E34;
	// lwz r3,-23464(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -23464);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// ori r11,r11,4
	r11.u64 = r11.u64 | 4;
	// addi r4,r10,-16776
	ctx.r4.s64 = ctx.r10.s64 + -16776;
	// stw r11,-7940(r31)
	PPC_STORE_U32(r31.u32 + -7940, r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82381E2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-7940(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -7940);
	// stw r3,-7952(r28)
	PPC_STORE_U32(r28.u32 + -7952, ctx.r3.u32);
loc_82381E34:
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82381e70
	if (!cr6.eq) goto loc_82381E70;
	// lwz r3,-23464(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -23464);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// ori r11,r11,8
	r11.u64 = r11.u64 | 8;
	// addi r4,r10,-16788
	ctx.r4.s64 = ctx.r10.s64 + -16788;
	// stw r11,-7940(r31)
	PPC_STORE_U32(r31.u32 + -7940, r11.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,24(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82381E68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,-7956(r29)
	PPC_STORE_U32(r29.u32 + -7956, ctx.r3.u32);
	// b 0x82381e74
	goto loc_82381E74;
loc_82381E70:
	// lwz r3,-7956(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -7956);
loc_82381E74:
	// lwz r11,-7944(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -7944);
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// beq cr6,0x82381ec4
	if (cr6.eq) goto loc_82381EC4;
	// lwz r11,-7948(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -7948);
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bne cr6,0x82381e98
	if (!cr6.eq) goto loc_82381E98;
	// lwz r3,24(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82381E98:
	// lwz r11,-7952(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -7952);
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bne cr6,0x82381eb0
	if (!cr6.eq) goto loc_82381EB0;
	// lwz r3,28(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82381EB0:
	// cmplw cr6,r25,r3
	cr6.compare<uint32_t>(r25.u32, ctx.r3.u32, xer);
	// bne cr6,0x82381ec4
	if (!cr6.eq) goto loc_82381EC4;
	// lwz r3,32(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82381EC4:
	// lwz r3,20(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 20);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82381ED0"))) PPC_WEAK_FUNC(sub_82381ED0);
PPC_FUNC_IMPL(__imp__sub_82381ED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,2256
	ctx.r9.s64 = ctx.r10.s64 + 2256;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// li r8,64
	ctx.r8.s64 = 64;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// li r7,80
	ctx.r7.s64 = 80;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// li r6,96
	ctx.r6.s64 = 96;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32114
	ctx.r4.s64 = -2104623104;
	// stvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,2
	ctx.r10.s64 = 2;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,112(r3)
	PPC_STORE_U32(ctx.r3.u32 + 112, r11.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 120, r11.u32);
	// lwz r9,20(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// lfs f0,-31068(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31068);
	f0.f64 = double(temp.f32);
	// stfs f0,116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stw r11,124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 124, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stw r11,44(r3)
	PPC_STORE_U32(ctx.r3.u32 + 44, r11.u32);
	// stw r9,40(r3)
	PPC_STORE_U32(ctx.r3.u32 + 40, ctx.r9.u32);
	// lwz r11,-32452(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -32452);
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// stw r11,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82381F50"))) PPC_WEAK_FUNC(sub_82381F50);
PPC_FUNC_IMPL(__imp__sub_82381F50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r8,96
	ctx.r8.s64 = 96;
	// addi r10,r11,80
	ctx.r10.s64 = r11.s64 + 80;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// addi r9,r9,64
	ctx.r9.s64 = ctx.r9.s64 + 64;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,124(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 124);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r9,120(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 120);
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// lwz r11,44(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// subf r7,r9,r11
	ctx.r7.s64 = r11.s64 - ctx.r9.s64;
	// cmplwi cr6,r7,2
	cr6.compare<uint32_t>(ctx.r7.u32, 2, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8213c218
	sub_8213C218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82381FAC"))) PPC_WEAK_FUNC(sub_82381FAC);
PPC_FUNC_IMPL(__imp__sub_82381FAC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82381FB0"))) PPC_WEAK_FUNC(sub_82381FB0);
PPC_FUNC_IMPL(__imp__sub_82381FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v32{};
	PPCVRegister v33{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82381FB8;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9d8
	ctx.lr = 0x82381FC0;
	// li r12,-208
	r12.s64 = -208;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lwz r9,12(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r25,0(r4)
	r25.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r29,4(r4)
	r29.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r14,0
	r14.s64 = 0;
	// stw r22,756(r1)
	PPC_STORE_U32(ctx.r1.u32 + 756, r22.u32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lwz r11,20(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 20);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// stw r9,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// mr r27,r11
	r27.u64 = r11.u64;
	// lfs f29,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f29.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f30,17032(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 17032);
	f30.f64 = double(temp.f32);
	// mr r15,r14
	r15.u64 = r14.u64;
	// stw r14,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r14.u32);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r5,r14
	ctx.r5.u64 = r14.u64;
	// addi r16,r11,2256
	r16.s64 = r11.s64 + 2256;
	// stb r14,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r14.u8);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// stw r14,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r14.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// fmr f31,f29
	f31.f64 = f29.f64;
	// addi r4,r10,3998
	ctx.r4.s64 = ctx.r10.s64 + 3998;
	// fmr f28,f29
	f28.f64 = f29.f64;
	// addi r3,r7,24092
	ctx.r3.s64 = ctx.r7.s64 + 24092;
	// stb r15,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r15.u8);
	// addi r11,r6,32232
	r11.s64 = ctx.r6.s64 + 32232;
	// stw r5,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r5.u32);
	// stw r16,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r16.u32);
	// lis r21,-32114
	r21.s64 = -2104623104;
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// lis r19,-32119
	r19.s64 = -2104950784;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// lis r18,-32119
	r18.s64 = -2104950784;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r17,r9,-16732
	r17.s64 = ctx.r9.s64 + -16732;
	// addi r20,r8,19856
	r20.s64 = ctx.r8.s64 + 19856;
loc_8238207C:
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// cmpw cr6,r5,r11
	cr6.compare<int32_t>(ctx.r5.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// bge cr6,0x82382090
	if (!cr6.lt) goto loc_82382090;
	// mr r11,r14
	r11.u64 = r14.u64;
loc_82382090:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x823824e8
	if (!cr6.eq) goto loc_823824E8;
	// rlwinm r28,r5,2,0,29
	r28.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r28,r25
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r25.u32);
	// lbz r11,165(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 165);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x823824d4
	if (cr6.eq) goto loc_823824D4;
	// lwz r11,8(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 8);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x823824d4
	if (!cr6.eq) goto loc_823824D4;
	// lwz r10,160(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x823820d8
	if (!cr6.eq) goto loc_823820D8;
	// lwz r30,4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x823820dc
	goto loc_823820DC;
loc_823820D8:
	// mr r30,r11
	r30.u64 = r11.u64;
loc_823820DC:
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x823820ec
	if (!cr6.eq) goto loc_823820EC;
	// lwz r31,8(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x823820f0
	goto loc_823820F0;
loc_823820EC:
	// lwz r31,12(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
loc_823820F0:
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// bne cr6,0x82382100
	if (!cr6.eq) goto loc_82382100;
	// lwz r26,12(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x82382104
	goto loc_82382104;
loc_82382100:
	// lwz r26,8(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
loc_82382104:
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x825a2aa8
	ctx.lr = 0x82382114;
	sub_825A2AA8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82381d60
	ctx.lr = 0x82382120;
	sub_82381D60(ctx, base);
	// lwzx r9,r28,r25
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + r25.u32);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lwz r24,-23464(r21)
	r24.u64 = PPC_LOAD_U32(r21.u32 + -23464);
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,160(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// subf r6,r29,r7
	ctx.r6.s64 = ctx.r7.s64 - r29.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// xori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 ^ 1;
	// bl 0x825a2aa8
	ctx.lr = 0x8238214C;
	sub_825A2AA8(ctx, base);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82382164;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,60(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lwz r24,0(r9)
	r24.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// beq cr6,0x82382270
	if (cr6.eq) goto loc_82382270;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r11,-10432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10432);
	// lwz r11,140(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x823824d4
	if (cr6.eq) goto loc_823824D4;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x823821A0;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82382234
	if (cr6.eq) goto loc_82382234;
	// lwz r11,-7936(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + -7936);
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x823821dc
	if (!cr6.eq) goto loc_823821DC;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// stw r11,-7936(r18)
	PPC_STORE_U32(r18.u32 + -7936, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x823821CC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82144a28
	ctx.lr = 0x823821D8;
	sub_82144A28(ctx, base);
	// stw r3,-7932(r19)
	PPC_STORE_U32(r19.u32 + -7932, ctx.r3.u32);
loc_823821DC:
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x823821f0
	if (!cr6.eq) goto loc_823821F0;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
loc_823821F0:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x823821F8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82144a28
	ctx.lr = 0x82382204;
	sub_82144A28(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82382210
	if (!cr6.eq) goto loc_82382210;
	// lwz r3,-7932(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -7932);
loc_82382210:
	// lbz r11,62(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 62);
	// clrlwi r10,r15,24
	ctx.r10.u64 = r15.u32 & 0xFF;
	// lbz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// rlwinm r8,r11,31,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x1;
	// clrlwi r7,r11,31
	ctx.r7.u64 = r11.u32 & 0x1;
	// or r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r15,r7,r10
	r15.u64 = ctx.r7.u64 | ctx.r10.u64;
	// stb r6,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r6.u8);
	// b 0x82382270
	goto loc_82382270;
loc_82382234:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82382248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,8
	cr6.compare<int32_t>(ctx.r3.s32, 8, xer);
	// beq cr6,0x8238225c
	if (cr6.eq) goto loc_8238225C;
	// cmpwi cr6,r3,13
	cr6.compare<int32_t>(ctx.r3.s32, 13, xer);
	// bne cr6,0x82382268
	if (!cr6.eq) goto loc_82382268;
	// b 0x82382270
	goto loc_82382270;
loc_8238225C:
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// stw r10,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
loc_82382268:
	// li r15,1
	r15.s64 = 1;
	// stb r15,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, r15.u8);
loc_82382270:
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r16
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r16.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r10,r28,r25
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r25.u32);
	// lwz r11,160(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x823822d8
	if (cr6.eq) goto loc_823822D8;
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// bne cr6,0x823822a8
	if (!cr6.eq) goto loc_823822A8;
	// lwz r5,28(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x823822ac
	goto loc_823822AC;
loc_823822A8:
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
loc_823822AC:
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// beq cr6,0x823822bc
	if (cr6.eq) goto loc_823822BC;
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
loc_823822BC:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x82382314
	goto loc_82382314;
loc_823822D8:
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// bne cr6,0x823822e8
	if (!cr6.eq) goto loc_823822E8;
	// lwz r5,28(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// b 0x823822ec
	goto loc_823822EC;
loc_823822E8:
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
loc_823822EC:
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
	// beq cr6,0x823822fc
	if (cr6.eq) goto loc_823822FC;
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
loc_823822FC:
	// lwz r3,8(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 8);
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82382314:
	// bctrl 
	ctx.lr = 0x82382318;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82382360
	if (cr6.eq) goto loc_82382360;
	// lwzx r10,r28,r25
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r25.u32);
	// lwz r11,160(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// bne cr6,0x8238233c
	if (!cr6.eq) goto loc_8238233C;
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// b 0x82382340
	goto loc_82382340;
loc_8238233C:
	// lwz r5,28(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28);
loc_82382340:
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// beq cr6,0x82382350
	if (cr6.eq) goto loc_82382350;
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
loc_82382350:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r9,84(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// b 0x823823a4
	goto loc_823823A4;
loc_82382360:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x823823b4
	if (cr6.eq) goto loc_823823B4;
	// lwzx r10,r28,r25
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + r25.u32);
	// lwz r11,160(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 160);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// bne cr6,0x82382384
	if (!cr6.eq) goto loc_82382384;
	// lwz r5,36(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// b 0x82382388
	goto loc_82382388;
loc_82382384:
	// lwz r5,28(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 28);
loc_82382388:
	// cmplw cr6,r29,r9
	cr6.compare<uint32_t>(r29.u32, ctx.r9.u32, xer);
	// addi r11,r10,64
	r11.s64 = ctx.r10.s64 + 64;
	// beq cr6,0x82382398
	if (cr6.eq) goto loc_82382398;
	// addi r11,r10,48
	r11.s64 = ctx.r10.s64 + 48;
loc_82382398:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
loc_823823A4:
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,432
	ctx.r4.s64 = ctx.r1.s64 + 432;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823823B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_823823B4:
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r11,r28,r25
	r11.u64 = PPC_LOAD_U32(r28.u32 + r25.u32);
	// li r9,80
	ctx.r9.s64 = 80;
	// lwz r8,160(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bne cr6,0x823823fc
	if (!cr6.eq) goto loc_823823FC;
	// vspltisw128 v61,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v60
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v60.f32)));
	// b 0x82382400
	goto loc_82382400;
loc_823823FC:
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82382400:
	// vmsum3fp128 v59,v62,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v59.f32, simde_mm_dp_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v62.f32), 0xEF));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f10.f64 = double(temp.f32);
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// lfs f11,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	f0.f64 = double(temp.f32);
	// fmuls f8,f0,f0
	ctx.f8.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,184(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f7,f13,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f8.f64));
	// vrsqrtefp128 v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v59.f32))));
	// lfs f9,164(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f12,f12,f7
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f7.f64));
	// vmulfp128 v57,v62,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,308(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,312(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 312);
	ctx.f4.f64 = double(temp.f32);
	// fmuls f3,f11,f4
	ctx.f3.f64 = double(float(ctx.f11.f64 * ctx.f4.f64));
	// lfs f6,304(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f6.f64 = double(temp.f32);
	// fmadds f2,f10,f6,f3
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f1,f9,f5,f2
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f5.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f30
	cr6.compare(ctx.f1.f64, f30.f64);
	// blt cr6,0x823824a0
	if (cr6.lt) goto loc_823824A0;
	// fmuls f0,f0,f9
	f0.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmadds f13,f10,f13,f0
	ctx.f13.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + f0.f64));
	// fmadds f0,f12,f11,f13
	f0.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x823824d4
	if (!cr6.gt) goto loc_823824D4;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bne cr6,0x82382484
	if (!cr6.eq) goto loc_82382484;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// b 0x82382488
	goto loc_82382488;
loc_82382484:
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
loc_82382488:
	// addi r9,r1,448
	ctx.r9.s64 = ctx.r1.s64 + 448;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,400
	ctx.r10.s64 = ctx.r1.s64 + 400;
	// mr r27,r23
	r27.u64 = r23.u64;
	// stvx128 v56,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823824d0
	goto loc_823824D0;
loc_823824A0:
	// fcmpu cr6,f8,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f8.f64, f28.f64);
	// ble cr6,0x823824d4
	if (!cr6.gt) goto loc_823824D4;
	// fmr f28,f8
	f28.f64 = ctx.f8.f64;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bne cr6,0x823824bc
	if (!cr6.eq) goto loc_823824BC;
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// b 0x823824c0
	goto loc_823824C0;
loc_823824BC:
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
loc_823824C0:
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r23,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r23.u32);
	// stw r24,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r24.u32);
loc_823824D0:
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823824D4:
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// rotlwi r5,r10,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// b 0x8238207c
	goto loc_8238207C;
loc_823824E8:
	// lwz r6,34(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 34);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// stb r15,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r15.u8);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f0,-13028(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13028);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,-32131
	ctx.r7.s64 = -2105737216;
	// lfs f30,-3064(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -3064);
	f30.f64 = double(temp.f32);
	// li r25,48
	r25.s64 = 48;
	// li r26,16
	r26.s64 = 16;
	// li r24,32
	r24.s64 = 32;
	// li r17,-1
	r17.s64 = -1;
	// li r15,-1
	r15.s64 = -1;
	// li r16,255
	r16.s64 = 255;
	// addi r21,r11,7216
	r21.s64 = r11.s64 + 7216;
	// addi r22,r10,-17104
	r22.s64 = ctx.r10.s64 + -17104;
	// addi r20,r9,2352
	r20.s64 = ctx.r9.s64 + 2352;
	// addi r19,r8,2384
	r19.s64 = ctx.r8.s64 + 2384;
	// addi r18,r7,29952
	r18.s64 = ctx.r7.s64 + 29952;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x82382d7c
	if (cr6.lt) goto loc_82382D7C;
	// lwz r11,62(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 62);
	// mr r23,r14
	r23.u64 = r14.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x823825b8
	if (!cr6.lt) goto loc_823825B8;
	// rotlwi r11,r6,0
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// lwz r10,26(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 26);
	// lwz r9,30(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 30);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lwz r29,10(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 10);
	// lwz r28,14(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 14);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lwz r31,18(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 18);
	// lwz r30,22(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 22);
	// lfs f9,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 - ctx.f9.f64));
	// fsubs f7,f13,f9
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// fmadds f0,f6,f10,f12
	f0.f64 = double(float(ctx.f6.f64 * ctx.f10.f64 + ctx.f12.f64));
	// b 0x82382700
	goto loc_82382700;
loc_823825B8:
	// lwz r11,90(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 90);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f11,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	cr6.compare(f0.f64, ctx.f11.f64);
	// bge cr6,0x8238261c
	if (!cr6.lt) goto loc_8238261C;
	// lwz r11,54(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 54);
	// li r23,1
	r23.s64 = 1;
	// lwz r10,58(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 58);
	// lwz r9,62(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 62);
	// lwz r29,38(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 38);
	// lwz r28,42(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 42);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lwz r31,46(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 46);
	// fsubs f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// lwz r30,50(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 50);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fdivs f7,f12,f11
	ctx.f7.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fmadds f0,f7,f8,f10
	f0.f64 = double(float(ctx.f7.f64 * ctx.f8.f64 + ctx.f10.f64));
	// b 0x82382700
	goto loc_82382700;
loc_8238261C:
	// lwz r11,118(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 118);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8238267c
	if (!cr6.lt) goto loc_8238267C;
	// lwz r11,82(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 82);
	// lwz r9,90(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 90);
	// lwz r10,86(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 86);
	// lwz r29,66(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 66);
	// lwz r28,70(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 70);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lwz r31,74(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 74);
	// fsubs f9,f13,f11
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lwz r30,78(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 78);
	// fdivs f6,f10,f9
	ctx.f6.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// fmadds f0,f6,f7,f12
	f0.f64 = double(float(ctx.f6.f64 * ctx.f7.f64 + ctx.f12.f64));
	// b 0x823826fc
	goto loc_823826FC;
loc_8238267C:
	// lwz r11,122(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 122);
	// lwz r10,756(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,44(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 44);
	// lwz r9,112(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// lfs f12,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// bge cr6,0x823826d4
	if (!cr6.lt) goto loc_823826D4;
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x8238315c
	if (cr6.eq) goto loc_8238315C;
	// lwz r8,114(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 114);
	// fsubs f0,f0,f11
	f0.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lwz r9,110(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 110);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// fdivs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 / ctx.f13.f64));
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// fmadds f0,f11,f9,f10
	f0.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 + ctx.f10.f64));
	// b 0x823826e8
	goto loc_823826E8;
loc_823826D4:
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// beq cr6,0x8238315c
	if (cr6.eq) goto loc_8238315C;
	// lwz r9,114(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 114);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
loc_823826E8:
	// lwz r29,94(r27)
	r29.u64 = PPC_LOAD_U32(r27.u32 + 94);
	// lwz r28,98(r27)
	r28.u64 = PPC_LOAD_U32(r27.u32 + 98);
	// lwz r31,102(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 102);
	// lwz r30,106(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 106);
	// stw r11,112(r10)
	PPC_STORE_U32(ctx.r10.u32 + 112, r11.u32);
loc_823826FC:
	// li r23,2
	r23.s64 = 2;
loc_82382700:
	// lwz r11,756(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// addi r8,r1,512
	ctx.r8.s64 = ctx.r1.s64 + 512;
	// addi r7,r1,304
	ctx.r7.s64 = ctx.r1.s64 + 304;
	// fmr f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f0.f64;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// addi r4,r1,304
	ctx.r4.s64 = ctx.r1.s64 + 304;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r6,-31616
	ctx.r5.s64 = ctx.r6.s64 + -31616;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// lvx128 v54,r11,r25
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v53,v55,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v54.f32)));
	// lvx128 v52,r11,r26
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r11,r24
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v49,v52,v53
	simde_mm_store_ps(v49.f32, simde_mm_dp_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v48,v51,v53
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmsum3fp128 v47,v50,v53
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v53.f32), 0xEF));
	// vmrghw128 v46,v49,v49
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v45,v47,v48
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v48.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v63,v45,v46
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// vsubfp128 v44,v63,v62
	simde_mm_store_ps(v44.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x82382774;
	sub_82202EC0(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,496
	r11.s64 = ctx.r1.s64 + 496;
	// lwz r10,756(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// addi r9,r1,480
	ctx.r9.s64 = ctx.r1.s64 + 480;
	// lfs f0,14884(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	f0.f64 = double(temp.f32);
	// addi r8,r1,512
	ctx.r8.s64 = ctx.r1.s64 + 512;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// lvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v43,v61,v60
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// lvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v42,v61,v60
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v41,v62,v59
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lfs f13,31492(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31492);
	ctx.f13.f64 = double(temp.f32);
	// vmrglw128 v40,v62,v59
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v39,v43,v41
	simde_mm_store_si128((simde__m128i*)v39.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v38,v42,v40
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v42.u32)));
	// vmrghw128 v37,v43,v41
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrglw128 v36,v43,v41
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// vmrghw128 v35,v43,v41
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v43.u32)));
	// lwz r5,178(r27)
	ctx.r5.u64 = PPC_LOAD_U32(r27.u32 + 178);
	// stfs f29,196(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f29,200(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lvx128 v62,r0,r20
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// stfs f11,192(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v34,r0,r4
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,178(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 178);
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// stfs f29,212(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// vand128 v33,v34,v63
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// stfs f29,216(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f9,208(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lvx128 v32,r0,r6
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v61,v32,v63
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v32.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v60,v62,v33
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v33.u8)));
	// vor128 v59,v62,v61
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v61.u8)));
	// vmsum4fp128 v58,v60,v39
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v39.f32), 0xFF));
	// vmsum4fp128 v57,v60,v38
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v38.f32), 0xFF));
	// vmsum4fp128 v56,v60,v37
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v37.f32), 0xFF));
	// vmrghw128 v55,v58,v60
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmsum4fp128 v54,v59,v36
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v36.f32), 0xFF));
	// vmrghw128 v51,v56,v57
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmsum4fp128 v53,v59,v38
	simde_mm_store_ps(v53.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v38.f32), 0xFF));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// vmsum4fp128 v52,v59,v35
	simde_mm_store_ps(v52.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v35.f32), 0xFF));
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lwz r4,36(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// vmrghw128 v61,v51,v55
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lvx128 v60,r0,r22
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r22.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f31,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r27,r1,128
	r27.s64 = ctx.r1.s64 + 128;
	// stfs f29,136(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// vand128 v48,v61,v63
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stfs f29,132(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f0,284(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 284);
	f0.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lvx128 v47,r0,r6
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v46,v47
	ctx.fpscr.enableFlushModeUnconditional();
	v46.f32[0] = log2f(v47.f32[0]);
	v46.f32[1] = log2f(v47.f32[1]);
	v46.f32[2] = log2f(v47.f32[2]);
	v46.f32[3] = log2f(v47.f32[3]);
	// vmrghw128 v50,v54,v59
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vor128 v45,v62,v48
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v48.u8)));
	// vmrghw128 v49,v52,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// vmulfp128 v44,v46,v60
	simde_mm_store_ps(v44.f32, simde_mm_mul_ps(simde_mm_load_ps(v46.f32), simde_mm_load_ps(v60.f32)));
	// fsubs f8,f31,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f8.f64 = double(float(f31.f64 - f0.f64));
	// lfs f0,11368(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11368);
	f0.f64 = double(temp.f32);
	// lfs f13,312(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,224
	ctx.r5.s64 = ctx.r1.s64 + 224;
	// vmrghw128 v61,v49,v50
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vand128 v43,v61,v63
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r11,r24
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v41,v62,v43
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// lvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r11,r25
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r11,r26
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f7,f0
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64));
	// vmrghw128 v37,v40,v42
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// lfs f0,280(r22)
	temp.u32 = PPC_LOAD_U32(r22.u32 + 280);
	f0.f64 = double(temp.f32);
	// vmrghw128 v36,v38,v39
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrglw128 v35,v40,v42
	simde_mm_store_si128((simde__m128i*)v35.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrglw128 v34,v38,v39
	simde_mm_store_si128((simde__m128i*)v34.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v38.u32)));
	// vmrglw128 v33,v37,v36
	simde_mm_store_si128((simde__m128i*)v33.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v32,v37,v36
	simde_mm_store_si128((simde__m128i*)v32.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v36.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// vmrghw128 v63,v35,v34
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v34.u32), simde_mm_load_si128((simde__m128i*)v35.u32)));
	// vmsum4fp128 v62,v45,v33
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v33.f32), 0xFF));
	// vmsum4fp128 v61,v45,v32
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v32.f32), 0xFF));
	// vmsum4fp128 v60,v45,v63
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v45.f32), simde_mm_load_ps(v63.f32), 0xFF));
	// vmrghw128 v59,v62,v45
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v58,v61,v60
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v57,v58,v59
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r24
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r26
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r11
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v50,v52,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// lvx128 v55,r11,r25
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v53,v54,v55
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmrglw128 v51,v54,v55
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// stfs f13,284(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// vmrglw128 v49,v52,v56
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// stw r9,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r9.u32);
	// vmrglw128 v48,v50,v53
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// stw r14,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, r14.u32);
	// vmrghw128 v47,v50,v53
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// stw r14,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r14.u32);
	// stw r14,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, r14.u32);
	// vmrghw128 v46,v49,v51
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// stw r14,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, r14.u32);
	// stw r14,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, r14.u32);
	// vmsum4fp128 v45,v41,v48
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v48.f32), 0xFF));
	// vmsum4fp128 v44,v41,v47
	simde_mm_store_ps(v44.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v47.f32), 0xFF));
	// vmsum4fp128 v43,v41,v46
	simde_mm_store_ps(v43.f32, simde_mm_dp_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v46.f32), 0xFF));
	// vmrghw128 v42,v45,v41
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v45.u32)));
	// li r8,4
	ctx.r8.s64 = 4;
	// vmrghw128 v41,v44,v43
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// addi r7,r1,448
	ctx.r7.s64 = ctx.r1.s64 + 448;
	// fsel f5,f8,f6,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f5.f64 = ctx.f8.f64 >= 0.0 ? ctx.f6.f64 : f0.f64;
	// stfs f5,224(r1)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stw r14,252(r1)
	PPC_STORE_U32(ctx.r1.u32 + 252, r14.u32);
	// stw r14,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, r14.u32);
	// vmrghw128 v40,v41,v42
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// stw r14,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r14.u32);
	// stw r14,268(r1)
	PPC_STORE_U32(ctx.r1.u32 + 268, r14.u32);
	// stw r14,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, r14.u32);
	// stw r14,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, r14.u32);
	// stw r17,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r17.u32);
	// stw r15,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, r15.u32);
	// stb r16,292(r1)
	PPC_STORE_U8(ctx.r1.u32 + 292, r16.u8);
	// stb r14,293(r1)
	PPC_STORE_U8(ctx.r1.u32 + 293, r14.u8);
	// stvx128 v40,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r8,294(r1)
	PPC_STORE_U8(ctx.r1.u32 + 294, ctx.r8.u8);
	// stw r7,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r7.u32);
	// bl 0x82549118
	ctx.lr = 0x823829DC;
	sub_82549118(ctx, base);
	// lbz r10,294(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 294);
	// lwz r5,756(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// lbz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stw r14,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r14.u32);
	// stw r14,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r14.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r14,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r14.u32);
	// lwz r11,8(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stb r9,294(r1)
	PPC_STORE_U8(ctx.r1.u32 + 294, ctx.r9.u8);
	// beq cr6,0x82382aa8
	if (cr6.eq) goto loc_82382AA8;
	// lfs f0,56(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	f0.f64 = double(temp.f32);
	// lfs f13,408(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 408);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,404(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 404);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,48(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,400(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f8,f9,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f30
	cr6.compare(ctx.f6.f64, f30.f64);
	// bge cr6,0x82382aa8
	if (!cr6.lt) goto loc_82382AA8;
	// rotlwi r27,r5,0
	r27.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// bl 0x82548fd0
	ctx.lr = 0x82382A4C;
	sub_82548FD0(ctx, base);
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82382aac
	if (cr6.eq) goto loc_82382AAC;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82382a88
	if (cr6.eq) goto loc_82382A88;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82382a8c
	goto loc_82382A8C;
loc_82382A88:
	// mr r11,r14
	r11.u64 = r14.u64;
loc_82382A8C:
	// stw r26,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r26.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// bl 0x8213c0c0
	ctx.lr = 0x82382AA4;
	sub_8213C0C0(ctx, base);
	// b 0x82382aac
	goto loc_82382AAC;
loc_82382AA8:
	// lwz r27,756(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
loc_82382AAC:
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82382d80
	if (cr6.eq) goto loc_82382D80;
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stw r11,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82548fd0
	ctx.lr = 0x82382AD4;
	sub_82548FD0(ctx, base);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// stw r10,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82548fd0
	ctx.lr = 0x82382AF0;
	sub_82548FD0(ctx, base);
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82382b48
	if (cr6.eq) goto loc_82382B48;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82382b2c
	if (cr6.eq) goto loc_82382B2C;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82382b30
	goto loc_82382B30;
loc_82382B2C:
	// mr r11,r14
	r11.u64 = r14.u64;
loc_82382B30:
	// stw r26,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r26.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// bl 0x8213c0c0
	ctx.lr = 0x82382B48;
	sub_8213C0C0(ctx, base);
loc_82382B48:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82382ba0
	if (cr6.eq) goto loc_82382BA0;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82382b84
	if (cr6.eq) goto loc_82382B84;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r10,232(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82382b88
	goto loc_82382B88;
loc_82382B84:
	// mr r11,r14
	r11.u64 = r14.u64;
loc_82382B88:
	// stw r26,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r26.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8213c0c0
	ctx.lr = 0x82382BA0;
	sub_8213C0C0(ctx, base);
loc_82382BA0:
	// lwz r31,116(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82382d80
	if (cr6.eq) goto loc_82382D80;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,8(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r11,-10432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10432);
	// lwz r9,140(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82382d80
	if (!cr6.eq) goto loc_82382D80;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82382BD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82382d80
	if (!cr6.eq) goto loc_82382D80;
	// lbz r11,465(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 465);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82382d80
	if (!cr6.eq) goto loc_82382D80;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82382c14
	if (cr6.eq) goto loc_82382C14;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82382c18
	if (!cr6.eq) goto loc_82382C18;
loc_82382C14:
	// mr r11,r14
	r11.u64 = r14.u64;
loc_82382C18:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82382d80
	if (!cr6.eq) goto loc_82382D80;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r8,80(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82382c4c
	if (cr6.eq) goto loc_82382C4C;
	// addi r11,r8,272
	r11.s64 = ctx.r8.s64 + 272;
	// b 0x82382c54
	goto loc_82382C54;
loc_82382C4C:
	// lwz r11,28(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82382C54:
	// lvx128 v63,r11,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82382c68
	if (cr6.eq) goto loc_82382C68;
	// addi r11,r9,272
	r11.s64 = ctx.r9.s64 + 272;
	// b 0x82382c70
	goto loc_82382C70;
loc_82382C68:
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82382C70:
	// lvx128 v39,r11,r25
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// vsubfp128 v63,v39,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v63.f32)));
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// vmsum3fp128 v38,v63,v63
	simde_mm_store_ps(v38.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v63.f32), 0xEF));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vrsqrtefp128 v37,v38
	simde_mm_store_ps(v37.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(v38.f32))));
	// vmulfp128 v36,v63,v37
	simde_mm_store_ps(v36.f32, simde_mm_mul_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v37.f32)));
	// stvx128 v36,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82382ca4
	if (cr6.eq) goto loc_82382CA4;
	// addi r11,r8,272
	r11.s64 = ctx.r8.s64 + 272;
	// b 0x82382cac
	goto loc_82382CAC;
loc_82382CA4:
	// lwz r11,28(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82382CAC:
	// lfs f13,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f0,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f0.f64 = double(temp.f32);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// lfs f9,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// fmadds f8,f10,f13,f11
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fmadds f11,f12,f9,f8
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f9.f64 + ctx.f8.f64));
	// beq cr6,0x82382ce0
	if (cr6.eq) goto loc_82382CE0;
	// addi r11,r9,272
	r11.s64 = ctx.r9.s64 + 272;
	// b 0x82382ce8
	goto loc_82382CE8;
loc_82382CE0:
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82382CE8:
	// lfs f10,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lfs f8,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f8,f13,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fnmadds f5,f12,f7,f6
	ctx.f5.f64 = double(float(-(ctx.f12.f64 * ctx.f7.f64 + ctx.f6.f64)));
	// fcmpu cr6,f11,f5
	cr6.compare(ctx.f11.f64, ctx.f5.f64);
	// bge cr6,0x82382d2c
	if (!cr6.lt) goto loc_82382D2C;
	// lwz r11,8(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f0,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// lfs f13,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f0,32308(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32308);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// blt cr6,0x82382d80
	if (cr6.lt) goto loc_82382D80;
loc_82382D2C:
	// lwz r11,72(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82382d4c
	if (!cr6.eq) goto loc_82382D4C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82382d50
	if (cr6.eq) goto loc_82382D50;
loc_82382D4C:
	// mr r11,r14
	r11.u64 = r14.u64;
loc_82382D50:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82382d60
	if (cr6.eq) goto loc_82382D60;
	// li r23,3
	r23.s64 = 3;
loc_82382D60:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r5,128(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 128);
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// bl 0x826c28f8
	ctx.lr = 0x82382D78;
	sub_826C28F8(ctx, base);
	// b 0x82382d80
	goto loc_82382D80;
loc_82382D7C:
	// lwz r27,756(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
loc_82382D80:
	// fsqrts f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(sqrt(f28.f64)));
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r29,108(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lfs f0,-7912(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -7912);
	f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * f0.f64));
	// beq cr6,0x8238315c
	if (cr6.eq) goto loc_8238315C;
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238315c
	if (cr6.eq) goto loc_8238315C;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r10,146(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 146);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x8238315c
	if (cr6.lt) goto loc_8238315C;
	// lwz r7,146(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 146);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r10,150(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 150);
	// lfs f12,116(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lwz r5,170(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 170);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r8,174(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 174);
	// addi r30,r27,124
	r30.s64 = r27.s64 + 124;
	// lwz r4,138(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 138);
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// lfs f7,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lfs f0,-12492(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12492);
	f0.f64 = double(temp.f32);
	// stw r5,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r5.u32);
	// lfs f4,108(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f4.f64 = double(temp.f32);
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// fsubs f9,f0,f12
	ctx.f9.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lwz r3,124(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 124);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r11,r25
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r11,r26
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v34,v127,v35
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v34.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v35.f32)));
	// lvx128 v32,r11,r24
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,116(r27)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + 116, temp.u32);
	// lwz r11,44(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 44);
	// stw r11,120(r27)
	PPC_STORE_U32(r27.u32 + 120, r11.u32);
	// addi r11,r27,64
	r11.s64 = r27.s64 + 64;
	// lfs f11,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f11.f64 = double(temp.f32);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// fsubs f5,f13,f7
	ctx.f5.f64 = double(float(ctx.f13.f64 - ctx.f7.f64));
	// vmsum3fp128 v60,v63,v34
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_dp_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// fsubs f3,f11,f7
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f3.f64 = double(float(ctx.f11.f64 - ctx.f7.f64));
	// vmsum3fp128 v62,v33,v34
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_dp_ps(simde_mm_load_ps(v33.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// vmsum3fp128 v61,v32,v34
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v34.f32), 0xEF));
	// lfs f13,7444(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f5,f3
	f0.f64 = double(float(ctx.f5.f64 / ctx.f3.f64));
	// vmrghw128 v59,v62,v62
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v58,v60,v61
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v60.u32)));
	// lfs f10,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// fsubs f2,f10,f4
	ctx.f2.f64 = double(float(ctx.f10.f64 - ctx.f4.f64));
	// lfs f8,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f6,f9,f8
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64));
	// fmadds f12,f0,f2,f4
	ctx.f12.f64 = double(float(f0.f64 * ctx.f2.f64 + ctx.f4.f64));
	// vmrghw128 v63,v58,v59
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// fsubs f1,f6,f13
	ctx.f1.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fsubs f11,f12,f4
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f4.f64));
	// fsel f13,f1,f13,f6
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f13.f64 : ctx.f6.f64;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsel f9,f11,f12,f4
	ctx.f9.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f4.f64;
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fsel f31,f8,f10,f9
	f31.f64 = ctx.f8.f64 >= 0.0 ? ctx.f10.f64 : ctx.f9.f64;
	// beq cr6,0x82382ec0
	if (cr6.eq) goto loc_82382EC0;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v0,v63,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v57.f32)));
	// vor128 v12,v57,v57
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)v57.u8));
	// lvlx128 v56,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vmaddfp v11,v0,v13,v12
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82382ec4
	goto loc_82382EC4;
loc_82382EC0:
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82382EC4:
	// lwz r10,8(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r19
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r19.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,416
	ctx.r7.s64 = ctx.r1.s64 + 416;
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// vand128 v54,v55,v63
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// lvx128 v63,r0,r20
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r20.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// lwz r9,12(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 12);
	// vor128 v53,v63,v54
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// lvx128 v52,r11,r24
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r31,-32452(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32452);
	// lvx128 v50,r11,r25
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v49,v51,v52
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// lvx128 v48,r11,r26
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrglw128 v47,v51,v52
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v46,v48,v50
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v45,v48,v50
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v44,v49,v46
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v43,v47,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v47.u32)));
	// vmrghw128 v42,v49,v46
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v46.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmsum4fp128 v41,v53,v44
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v40,v53,v43
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmsum4fp128 v39,v53,v42
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v42.f32), 0xFF));
	// vmrghw128 v38,v41,v53
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v37,v39,v40
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v39.u32)));
	// vmrghw128 v36,v37,v38
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// stvx128 v36,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blt cr6,0x82382fc4
	if (cr6.lt) goto loc_82382FC4;
	// beq cr6,0x82382f88
	if (cr6.eq) goto loc_82382F88;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// bge cr6,0x82382ffc
	if (!cr6.lt) goto loc_82382FFC;
	// lfs f0,40(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	f0.f64 = double(temp.f32);
	// lfs f13,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f8,f9,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f30
	cr6.compare(ctx.f6.f64, f30.f64);
	// bge cr6,0x82382f80
	if (!cr6.lt) goto loc_82382F80;
	// lwz r31,66(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 66);
	// b 0x82382ffc
	goto loc_82382FFC;
loc_82382F80:
	// lwz r31,70(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 70);
	// b 0x82382ffc
	goto loc_82382FFC;
loc_82382F88:
	// lfs f0,40(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	f0.f64 = double(temp.f32);
	// lfs f13,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f30
	cr6.compare(ctx.f6.f64, f30.f64);
	// bge cr6,0x82382fbc
	if (!cr6.lt) goto loc_82382FBC;
	// lwz r31,54(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 54);
	// b 0x82382ffc
	goto loc_82382FFC;
loc_82382FBC:
	// lwz r31,58(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 58);
	// b 0x82382ffc
	goto loc_82382FFC;
loc_82382FC4:
	// lfs f0,40(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	f0.f64 = double(temp.f32);
	// lfs f13,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,36(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f30
	cr6.compare(ctx.f6.f64, f30.f64);
	// bge cr6,0x82382ff8
	if (!cr6.lt) goto loc_82382FF8;
	// lwz r31,34(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 34);
	// b 0x82382ffc
	goto loc_82382FFC;
loc_82382FF8:
	// lwz r31,30(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 30);
loc_82382FFC:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238301c
	if (cr6.eq) goto loc_8238301C;
	// lwz r11,48(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 48);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x8238301c
	if (cr6.eq) goto loc_8238301C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x8238301C;
	sub_8213C218(ctx, base);
loc_8238301C:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x823830e4
	if (!cr6.eq) goto loc_823830E4;
	// addi r11,r1,416
	r11.s64 = ctx.r1.s64 + 416;
	// lfs f0,312(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r22.u32 + 312);
	f0.f64 = double(temp.f32);
	// li r10,36
	ctx.r10.s64 = 36;
	// stfs f29,320(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f0,380(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stw r14,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, r14.u32);
	// stw r14,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, r14.u32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// stw r14,332(r1)
	PPC_STORE_U32(ctx.r1.u32 + 332, r14.u32);
	// stw r14,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, r14.u32);
	// stw r14,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, r14.u32);
	// stw r14,348(r1)
	PPC_STORE_U32(ctx.r1.u32 + 348, r14.u32);
	// stw r14,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, r14.u32);
	// stw r14,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, r14.u32);
	// stw r14,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, r14.u32);
	// stw r14,364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 364, r14.u32);
	// stw r14,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, r14.u32);
	// stw r14,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, r14.u32);
	// stw r17,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, r17.u32);
	// stw r15,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, r15.u32);
	// stb r16,388(r1)
	PPC_STORE_U8(ctx.r1.u32 + 388, r16.u8);
	// stb r14,389(r1)
	PPC_STORE_U8(ctx.r1.u32 + 389, r14.u8);
	// stw r11,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, r11.u32);
	// stb r10,390(r1)
	PPC_STORE_U8(ctx.r1.u32 + 390, ctx.r10.u8);
	// bl 0x823db918
	ctx.lr = 0x8238308C;
	sub_823DB918(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,36(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 36);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r3,4(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r5,17
	ctx.r5.s64 = 17;
	// addi r6,r1,320
	ctx.r6.s64 = ctx.r1.s64 + 320;
	// stw r5,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r5.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f0,11332(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11332);
	f0.f64 = double(temp.f32);
	// stw r8,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r8.u32);
	// lfs f13,11328(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11328);
	ctx.f13.f64 = double(temp.f32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f9.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// stw r11,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, r11.u32);
	// bl 0x825491f0
	ctx.lr = 0x823830DC;
	sub_825491F0(ctx, base);
	// stw r31,48(r27)
	PPC_STORE_U32(r27.u32 + 48, r31.u32);
	// b 0x82383158
	goto loc_82383158;
loc_823830E4:
	// addi r4,r1,416
	ctx.r4.s64 = ctx.r1.s64 + 416;
	// bl 0x8213b860
	ctx.lr = 0x823830EC;
	sub_8213B860(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x823db918
	ctx.lr = 0x823830F4;
	sub_823DB918(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,11332(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11332);
	f0.f64 = double(temp.f32);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// lfs f13,11328(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11328);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fmuls f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f9.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// beq cr6,0x82383150
	if (cr6.eq) goto loc_82383150;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r21)
	ctx.r9.u64 = PPC_LOAD_U32(r21.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r10,r11
	r11.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// lwz r10,11444(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82383154
	goto loc_82383154;
loc_82383150:
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
loc_82383154:
	// bl 0x82148c60
	ctx.lr = 0x82383158;
	sub_82148C60(ctx, base);
loc_82383158:
	// stw r29,44(r27)
	PPC_STORE_U32(r27.u32 + 44, r29.u32);
loc_8238315C:
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// li r0,-208
	r0.s64 = -208;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823dba24
	ctx.lr = 0x82383170;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82383174"))) PPC_WEAK_FUNC(sub_82383174);
PPC_FUNC_IMPL(__imp__sub_82383174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383178"))) PPC_WEAK_FUNC(sub_82383178);
PPC_FUNC_IMPL(__imp__sub_82383178) {
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
	PPCVRegister v32{};
	PPCVRegister v33{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82383180;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// stw r28,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r28.u32);
	// stw r28,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r28.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// stw r28,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r28.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r28,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r28.u32);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r28,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r28.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stw r28,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r28.u32);
	// lwz r9,8(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// li r4,255
	ctx.r4.s64 = 255;
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r3,4
	ctx.r3.s64 = 4;
	// lfs f0,-16792(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -16792);
	f0.f64 = double(temp.f32);
	// stfs f31,128(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stw r28,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, r28.u32);
	// stfs f0,188(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stw r28,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r28.u32);
	// stw r28,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r28.u32);
	// stw r28,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r28.u32);
	// stw r28,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r28.u32);
	// stw r28,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r28.u32);
	// stw r28,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r28.u32);
	// stw r8,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r8.u32);
	// stw r6,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r6.u32);
	// stb r4,196(r1)
	PPC_STORE_U8(ctx.r1.u32 + 196, ctx.r4.u8);
	// stb r28,197(r1)
	PPC_STORE_U8(ctx.r1.u32 + 197, r28.u8);
	// stb r3,198(r1)
	PPC_STORE_U8(ctx.r1.u32 + 198, ctx.r3.u8);
	// lwz r10,4(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lwzx r11,r5,r7
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// lwz r9,160(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 160);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// bne cr6,0x82383230
	if (!cr6.eq) goto loc_82383230;
	// addi r11,r11,64
	r11.s64 = r11.s64 + 64;
	// b 0x82383234
	goto loc_82383234;
loc_82383230:
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
loc_82383234:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r11.u32);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stw r10,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r10.u32);
	// lwz r4,134(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 134);
	// bl 0x82549118
	ctx.lr = 0x82383254;
	sub_82549118(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r8,148(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// li r29,48
	r29.s64 = 48;
	// li r27,16
	r27.s64 = 16;
	// li r30,32
	r30.s64 = 32;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// lvx128 v62,r11,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r7,2256
	ctx.r5.s64 = ctx.r7.s64 + 2256;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v60,r11,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r30
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r9,-31616
	ctx.r5.s64 = ctx.r9.s64 + -31616;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// vmsum3fp128 v57,v60,v61
	simde_mm_store_ps(v57.f32, simde_mm_dp_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmsum3fp128 v56,v59,v61
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmsum3fp128 v55,v58,v61
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v61.f32), 0xEF));
	// vmrghw128 v54,v57,v57
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v53,v55,v56
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v63,v53,v54
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v53.u32)));
	// vsubfp128 v52,v63,v62
	simde_mm_store_ps(v52.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x823832D0;
	sub_82202EC0(ctx, base);
	// addi r5,r1,272
	ctx.r5.s64 = ctx.r1.s64 + 272;
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// lvx128 v60,r0,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// lfs f0,14884(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f0.f64 = double(temp.f32);
	// lis r3,-32122
	ctx.r3.s64 = -2105147392;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,2384
	ctx.r8.s64 = ctx.r3.s64 + 2384;
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v51,v62,v61
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v50,v63,v60
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// addi r6,r7,2352
	ctx.r6.s64 = ctx.r7.s64 + 2352;
	// vmrglw128 v49,v63,v60
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v63.u32)));
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// vmrglw128 v48,v62,v61
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v47,v51,v50
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v46,v51,v50
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v45,v48,v49
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrglw128 v44,v51,v50
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// vmrghw128 v43,v51,v50
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v50.u32), simde_mm_load_si128((simde__m128i*)v51.u32)));
	// lwz r5,178(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 178);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r4,178(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 178);
	// lvx128 v42,r0,r9
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,116(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// vand128 v41,v42,v63
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stfs f31,120(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,31492(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31492);
	f0.f64 = double(temp.f32);
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r25,r1,112
	r25.s64 = ctx.r1.s64 + 112;
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v39,r0,r10
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v38,v39,v63
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v40,v62,v41
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v41.u8)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vor128 v37,v62,v38
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v38.u8)));
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// vmsum4fp128 v36,v40,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v36.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v47.f32), 0xFF));
	// vmsum4fp128 v35,v40,v45
	simde_mm_store_ps(v35.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v45.f32), 0xFF));
	// vmsum4fp128 v34,v40,v46
	simde_mm_store_ps(v34.f32, simde_mm_dp_ps(simde_mm_load_ps(v40.f32), simde_mm_load_ps(v46.f32), 0xFF));
	// vmsum4fp128 v33,v37,v44
	simde_mm_store_ps(v33.f32, simde_mm_dp_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v32,v37,v45
	simde_mm_store_ps(v32.f32, simde_mm_dp_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v45.f32), 0xFF));
	// vmsum4fp128 v61,v37,v43
	simde_mm_store_ps(v61.f32, simde_mm_dp_ps(simde_mm_load_ps(v37.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmrghw128 v60,v36,v40
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v40.u32), simde_mm_load_si128((simde__m128i*)v36.u32)));
	// vmrghw128 v59,v34,v35
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v58,v33,v37
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v37.u32), simde_mm_load_si128((simde__m128i*)v33.u32)));
	// vmrghw128 v57,v61,v32
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v32.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmrghw128 v61,v59,v60
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v59.u32)));
	// vmrghw128 v60,v57,v58
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vand128 v56,v61,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v55,v60,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vor128 v54,v62,v56
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v56.u8)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r11,r29
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v53,v62,v55
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// lvx128 v52,r11,r30
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r11,r27
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v48,v49,v52
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrghw128 v47,v50,v51
	simde_mm_store_si128((simde__m128i*)v47.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrglw128 v46,v49,v52
	simde_mm_store_si128((simde__m128i*)v46.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v49.u32)));
	// vmrglw128 v45,v50,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v50.u32)));
	// vmrglw128 v44,v48,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v43,v48,v47
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v42,v46,v45
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmsum4fp128 v41,v54,v44
	simde_mm_store_ps(v41.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v44.f32), 0xFF));
	// vmsum4fp128 v40,v54,v43
	simde_mm_store_ps(v40.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v43.f32), 0xFF));
	// vmsum4fp128 v39,v54,v42
	simde_mm_store_ps(v39.f32, simde_mm_dp_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v42.f32), 0xFF));
	// vmrghw128 v38,v41,v54
	simde_mm_store_si128((simde__m128i*)v38.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v41.u32)));
	// vmrghw128 v37,v40,v39
	simde_mm_store_si128((simde__m128i*)v37.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v39.u32), simde_mm_load_si128((simde__m128i*)v40.u32)));
	// vmrghw128 v36,v37,v38
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v38.u32), simde_mm_load_si128((simde__m128i*)v37.u32)));
	// stvx128 v36,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v33,r11,r29
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r11,r27
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v35,r11,r30
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v34,r0,r11
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v62,v34,v35
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// vmrghw128 v63,v32,v33
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// vmrglw128 v61,v34,v35
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v35.u32), simde_mm_load_si128((simde__m128i*)v34.u32)));
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// vmrglw128 v60,v32,v33
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v33.u32), simde_mm_load_si128((simde__m128i*)v32.u32)));
	// stw r10,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// vmrglw128 v59,v62,v63
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v58,v62,v63
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrghw128 v57,v61,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	// vmsum4fp128 v56,v53,v59
	simde_mm_store_ps(v56.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v59.f32), 0xFF));
	// vmsum4fp128 v55,v53,v58
	simde_mm_store_ps(v55.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v58.f32), 0xFF));
	// vmsum4fp128 v54,v53,v57
	simde_mm_store_ps(v54.f32, simde_mm_dp_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v57.f32), 0xFF));
	// vmrghw128 v53,v56,v53
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v56.u32)));
	// vmrghw128 v52,v55,v54
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), simde_mm_load_si128((simde__m128i*)v55.u32)));
	// vmrghw128 v51,v52,v53
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v52.u32)));
	// stvx128 v51,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,126(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 126);
	// bl 0x82548fd0
	ctx.lr = 0x823834B0;
	sub_82548FD0(ctx, base);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stw r9,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r9.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r4,130(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 130);
	// bl 0x82548fd0
	ctx.lr = 0x823834D0;
	sub_82548FD0(ctx, base);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r30,r11,7216
	r30.s64 = r11.s64 + 7216;
	// beq cr6,0x82383530
	if (cr6.eq) goto loc_82383530;
	// lbz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x82383514
	if (cr6.eq) goto loc_82383514;
	// lbz r11,64(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 64);
	// lwz r10,232(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r9,r11,11488
	ctx.r9.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82383518
	goto loc_82383518;
loc_82383514:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82383518:
	// stw r27,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r27.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,84(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x8213c0c0
	ctx.lr = 0x82383530;
	sub_8213C0C0(ctx, base);
loc_82383530:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82383588
	if (cr6.eq) goto loc_82383588;
	// lbz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r8,255
	cr6.compare<uint32_t>(ctx.r8.u32, 255, xer);
	// beq cr6,0x8238356c
	if (cr6.eq) goto loc_8238356C;
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
	// mullw r11,r8,r11
	r11.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// lwz r10,11444(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11444);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82383570
	goto loc_82383570;
loc_8238356C:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82383570:
	// stw r27,172(r11)
	PPC_STORE_U32(r11.u32 + 172, r27.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8213c0c0
	ctx.lr = 0x82383588;
	sub_8213C0C0(ctx, base);
loc_82383588:
	// lwz r11,8(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,4(r26)
	ctx.r8.u64 = PPC_LOAD_U32(r26.u32 + 4);
	// lwzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,160(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 160);
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// bne cr6,0x823835b0
	if (!cr6.eq) goto loc_823835B0;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_823835B0:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82383678
	if (cr6.eq) goto loc_82383678;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823835CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,8
	cr6.compare<int32_t>(ctx.r3.s32, 8, xer);
	// bne cr6,0x82383678
	if (!cr6.eq) goto loc_82383678;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lwz r30,128(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82383678
	if (cr6.eq) goto loc_82383678;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,-10432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10432);
	// lwz r9,140(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x82383678
	if (!cr6.eq) goto loc_82383678;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82383610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82383678
	if (!cr6.eq) goto loc_82383678;
	// lbz r11,465(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 465);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82383678
	if (!cr6.eq) goto loc_82383678;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8238364c
	if (cr6.eq) goto loc_8238364C;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8238364c
	if (cr6.eq) goto loc_8238364C;
	// li r28,1
	r28.s64 = 1;
loc_8238364C:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82383678
	if (!cr6.eq) goto loc_82383678;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,80(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// lwz r3,-27288(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27288);
	// lwz r5,128(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 128);
	// bl 0x826c28f8
	ctx.lr = 0x82383678;
	sub_826C28F8(ctx, base);
loc_82383678:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82383684"))) PPC_WEAK_FUNC(sub_82383684);
PPC_FUNC_IMPL(__imp__sub_82383684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383688"))) PPC_WEAK_FUNC(sub_82383688);
PPC_FUNC_IMPL(__imp__sub_82383688) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// lwz r6,8(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x823837ec
	if (cr6.eq) goto loc_823837EC;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// addi r9,r10,7216
	ctx.r9.s64 = ctx.r10.s64 + 7216;
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// lwz r10,232(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 232);
	// lwz r9,200(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 200);
	// beq cr6,0x823836e8
	if (cr6.eq) goto loc_823836E8;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r7,r9,r11
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r8,r8,11488
	ctx.r8.s64 = ctx.r8.s64 * 11488;
	// add r5,r8,r10
	ctx.r5.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,11444(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 11444);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// b 0x823836ec
	goto loc_823836EC;
loc_823836E8:
	// li r8,0
	ctx.r8.s64 = 0;
loc_823836EC:
	// lwz r8,172(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 172);
	// cmplwi cr6,r8,16
	cr6.compare<uint32_t>(ctx.r8.u32, 16, xer);
	// beq cr6,0x8238379c
	if (cr6.eq) goto loc_8238379C;
	// cmplwi cr6,r8,17
	cr6.compare<uint32_t>(ctx.r8.u32, 17, xer);
	// beq cr6,0x82383714
	if (cr6.eq) goto loc_82383714;
	// li r11,64
	r11.s64 = 64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r6,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823837e0
	goto loc_823837E0;
loc_82383714:
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// addi r11,r6,16
	r11.s64 = ctx.r6.s64 + 16;
	// addi r5,r10,2384
	ctx.r5.s64 = ctx.r10.s64 + 2384;
	// li r9,64
	ctx.r9.s64 = 64;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r6,16
	ctx.r6.s64 = 16;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r30,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r10,r4,2352
	ctx.r10.s64 = ctx.r4.s64 + 2352;
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v57,v62,v60
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// lvx128 v58,r11,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v55,v61,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vmrghw128 v56,v58,v59
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// vmrglw128 v54,v62,v60
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	// vmrglw128 v53,v58,v59
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), simde_mm_load_si128((simde__m128i*)v58.u32)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v51,v63,v55
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v55.u8)));
	// vmrglw128 v52,v57,v56
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_unpacklo_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v50,v57,v56
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), simde_mm_load_si128((simde__m128i*)v57.u32)));
	// vmrghw128 v49,v54,v53
	simde_mm_store_si128((simde__m128i*)v49.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), simde_mm_load_si128((simde__m128i*)v54.u32)));
	// vmsum4fp128 v48,v51,v52
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32), 0xFF));
	// vmsum4fp128 v46,v51,v50
	simde_mm_store_ps(v46.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v50.f32), 0xFF));
	// vmsum4fp128 v47,v51,v49
	simde_mm_store_ps(v47.f32, simde_mm_dp_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v49.f32), 0xFF));
	// vmrghw128 v45,v48,v51
	simde_mm_store_si128((simde__m128i*)v45.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v48.u32)));
	// vmrghw128 v44,v46,v47
	simde_mm_store_si128((simde__m128i*)v44.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v47.u32), simde_mm_load_si128((simde__m128i*)v46.u32)));
	// vmrghw128 v43,v44,v45
	simde_mm_store_si128((simde__m128i*)v43.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)v45.u32), simde_mm_load_si128((simde__m128i*)v44.u32)));
	// stvx128 v43,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823837e0
	goto loc_823837E0;
loc_8238379C:
	// cmplwi cr6,r11,255
	cr6.compare<uint32_t>(r11.u32, 255, xer);
	// beq cr6,0x823837c0
	if (cr6.eq) goto loc_823837C0;
	// lbz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 64);
	// mullw r9,r9,r11
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(r11.s32);
	// mulli r11,r8,11488
	r11.s64 = ctx.r8.s64 * 11488;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,11444(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 11444);
	// add r3,r11,r9
	ctx.r3.u64 = r11.u64 + ctx.r9.u64;
	// b 0x823837c4
	goto loc_823837C4;
loc_823837C0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823837C4:
	// bl 0x82148e58
	ctx.lr = 0x823837C8;
	sub_82148E58(ctx, base);
	// li r11,96
	r11.s64 = 96;
	// lvx128 v42,r0,r3
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v41,r30,r11
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v40,v41,v42
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v40.f32, simde_mm_add_ps(simde_mm_load_ps(v41.f32), simde_mm_load_ps(v42.f32)));
	// stvx128 v40,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823837E0:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8213b860
	ctx.lr = 0x823837EC;
	sub_8213B860(ctx, base);
loc_823837EC:
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

__attribute__((alias("__imp__sub_82383804"))) PPC_WEAK_FUNC(sub_82383804);
PPC_FUNC_IMPL(__imp__sub_82383804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383808"))) PPC_WEAK_FUNC(sub_82383808);
PPC_FUNC_IMPL(__imp__sub_82383808) {
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
	// bl 0x8256a838
	ctx.lr = 0x82383820;
	sub_8256A838(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-16396
	ctx.r10.s64 = r11.s64 + -16396;
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

__attribute__((alias("__imp__sub_82383844"))) PPC_WEAK_FUNC(sub_82383844);
PPC_FUNC_IMPL(__imp__sub_82383844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383848"))) PPC_WEAK_FUNC(sub_82383848);
PPC_FUNC_IMPL(__imp__sub_82383848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-7928(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7928);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82383854"))) PPC_WEAK_FUNC(sub_82383854);
PPC_FUNC_IMPL(__imp__sub_82383854) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383858"))) PPC_WEAK_FUNC(sub_82383858);
PPC_FUNC_IMPL(__imp__sub_82383858) {
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
	// bl 0x8256a7a8
	ctx.lr = 0x82383870;
	sub_8256A7A8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// lfs f0,-332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r7,-16396
	ctx.r6.s64 = ctx.r7.s64 + -16396;
	// lfs f12,-30580(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -30580);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,27640(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f12,28(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f11,48(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f0,44(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
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

__attribute__((alias("__imp__sub_823838CC"))) PPC_WEAK_FUNC(sub_823838CC);
PPC_FUNC_IMPL(__imp__sub_823838CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823838D0"))) PPC_WEAK_FUNC(sub_823838D0);
PPC_FUNC_IMPL(__imp__sub_823838D0) {
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
	// li r3,56
	ctx.r3.s64 = 56;
	// bl 0x82130528
	ctx.lr = 0x823838E4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82383900
	if (cr6.eq) goto loc_82383900;
	// bl 0x82383858
	ctx.lr = 0x823838F0;
	sub_82383858(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82383900:
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

__attribute__((alias("__imp__sub_82383914"))) PPC_WEAK_FUNC(sub_82383914);
PPC_FUNC_IMPL(__imp__sub_82383914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383918"))) PPC_WEAK_FUNC(sub_82383918);
PPC_FUNC_IMPL(__imp__sub_82383918) {
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
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-7928
	r31.s64 = r11.s64 + -7928;
	// lwz r11,-7928(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7928);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82383a54
	if (!cr6.eq) goto loc_82383A54;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82383948;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8238395c
	if (cr6.eq) goto loc_8238395C;
	// bl 0x821d5408
	ctx.lr = 0x82383958;
	sub_821D5408(ctx, base);
	// b 0x82383960
	goto loc_82383960;
loc_8238395C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82383960:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-16380
	ctx.r7.s64 = ctx.r10.s64 + -16380;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,56
	ctx.r5.s64 = 56;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32200
	ctx.r8.s64 = -2110259200;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r8,14544
	ctx.r4.s64 = ctx.r8.s64 + 14544;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r30,-32114
	r30.s64 = -2104623104;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r5,r10,32288
	ctx.r5.s64 = ctx.r10.s64 + 32288;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r8,r3,32264
	ctx.r8.s64 = ctx.r3.s64 + 32264;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,48
	ctx.r10.s64 = 48;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r9,52
	ctx.r9.s64 = 52;
	// lwz r4,-23468(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23468);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r9,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r9.u32);
	// bne cr6,0x823839ec
	if (!cr6.eq) goto loc_823839EC;
	// bl 0x8256a988
	ctx.lr = 0x823839E8;
	sub_8256A988(ctx, base);
	// lwz r4,-23468(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23468);
loc_823839EC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x823839F8;
	sub_821D4458(ctx, base);
	// lwz r11,-23468(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23468);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x82383A10;
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
	ctx.lr = 0x82383A2C;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,32312
	ctx.r4.s64 = ctx.r8.s64 + 32312;
	// bl 0x821d4b00
	ctx.lr = 0x82383A3C;
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
	ctx.lr = 0x82383A54;
	sub_821C0548(ctx, base);
loc_82383A54:
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

__attribute__((alias("__imp__sub_82383A6C"))) PPC_WEAK_FUNC(sub_82383A6C);
PPC_FUNC_IMPL(__imp__sub_82383A6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383A70"))) PPC_WEAK_FUNC(sub_82383A70);
PPC_FUNC_IMPL(__imp__sub_82383A70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
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
	// bl 0x823d91f4
	ctx.lr = 0x82383A78;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825640f8
	ctx.lr = 0x82383A84;
	sub_825640F8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r30,-32252
	r30.s64 = -2113667072;
	// lis r29,-32256
	r29.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r28,-32253
	r28.s64 = -2113732608;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r8,r1,84
	ctx.r8.s64 = ctx.r1.s64 + 84;
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,92
	ctx.r6.s64 = ctx.r1.s64 + 92;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lfs f10,-12072(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12072);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lfs f12,14988(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// lfs f7,31020(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31020);
	ctx.f7.f64 = double(temp.f32);
	// lis r27,-32254
	r27.s64 = -2113798144;
	// lfs f6,1752(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1752);
	ctx.f6.f64 = double(temp.f32);
	// lis r3,-32251
	ctx.r3.s64 = -2113601536;
	// lfs f5,-2580(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + -2580);
	ctx.f5.f64 = double(temp.f32);
	// lis r30,-32255
	r30.s64 = -2113863680;
	// lis r29,-32255
	r29.s64 = -2113863680;
	// lfs f11,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f11.f64 = double(temp.f32);
	// lis r28,-32256
	r28.s64 = -2113929216;
	// lfs f3,-15752(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15752);
	ctx.f3.f64 = double(temp.f32);
	// addi r10,r3,-15768
	ctx.r10.s64 = ctx.r3.s64 + -15768;
	// stfs f10,24(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// lfs f4,-1684(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + -1684);
	ctx.f4.f64 = double(temp.f32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lfs f9,-17424(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + -17424);
	ctx.f9.f64 = double(temp.f32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lfs f10,-32032(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -32032);
	ctx.f10.f64 = double(temp.f32);
	// li r11,80
	r11.s64 = 80;
	// lfs f8,14884(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 14884);
	ctx.f8.f64 = double(temp.f32);
	// li r10,96
	ctx.r10.s64 = 96;
	// stfs f7,28(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// li r30,112
	r30.s64 = 112;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r9,128
	ctx.r9.s64 = 128;
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r8,144
	ctx.r8.s64 = 144;
	// lvlx128 v61,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r7,160
	ctx.r7.s64 = 160;
	// lvlx128 v60,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// li r6,50
	ctx.r6.s64 = 50;
	// lvlx128 v59,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v63,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvlx128 v57,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// stfs f13,32(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// stfs f6,36(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// stfs f12,40(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// vspltw128 v53,v59,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// stfs f5,44(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// vspltw128 v52,v57,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// stfs f12,48(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// li r5,176
	ctx.r5.s64 = 176;
	// stfs f12,52(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f11,56(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f13,60(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f4,64(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f3,72(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f10,208(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f9,212(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 212, temp.u32);
	// stfs f8,216(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 216, temp.u32);
	// stfs f13,220(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 220, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// lvlx128 v51,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// vspltw128 v50,v51,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), 0xFF));
	// lis r29,-32251
	r29.s64 = -2113601536;
	// li r28,192
	r28.s64 = 192;
	// stfs f0,236(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 236, temp.u32);
	// stfs f10,224(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 224, temp.u32);
	// stfs f9,228(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 228, temp.u32);
	// stfs f8,232(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 232, temp.u32);
	// lfs f12,-31376(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + -31376);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f13,240(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// stfs f12,244(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 244, temp.u32);
	// stfs f13,248(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 248, temp.u32);
	// stfs f0,260(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// stfs f11,256(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 256, temp.u32);
	// stfs f11,264(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// stw r6,284(r31)
	PPC_STORE_U32(r31.u32 + 284, ctx.r6.u32);
	// lfs f0,-15776(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + -15776);
	f0.f64 = double(temp.f32);
	// stfs f13,272(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 272, temp.u32);
	// stfs f13,276(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 276, temp.u32);
	// stfs f0,280(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 280, temp.u32);
	// stvx128 v58,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v49,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v48,v49,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v49.u32), 0xFF));
	// stvx128 v55,r31,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82383C50"))) PPC_WEAK_FUNC(sub_82383C50);
PPC_FUNC_IMPL(__imp__sub_82383C50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r3,-7924(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7924);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82383C5C"))) PPC_WEAK_FUNC(sub_82383C5C);
PPC_FUNC_IMPL(__imp__sub_82383C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383C60"))) PPC_WEAK_FUNC(sub_82383C60);
PPC_FUNC_IMPL(__imp__sub_82383C60) {
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
	// bl 0x825641a0
	ctx.lr = 0x82383C78;
	sub_825641A0(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-15768
	ctx.r10.s64 = r11.s64 + -15768;
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

__attribute__((alias("__imp__sub_82383C9C"))) PPC_WEAK_FUNC(sub_82383C9C);
PPC_FUNC_IMPL(__imp__sub_82383C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383CA0"))) PPC_WEAK_FUNC(sub_82383CA0);
PPC_FUNC_IMPL(__imp__sub_82383CA0) {
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
	// li r3,288
	ctx.r3.s64 = 288;
	// bl 0x82130528
	ctx.lr = 0x82383CB4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82383cd0
	if (cr6.eq) goto loc_82383CD0;
	// bl 0x82383a70
	ctx.lr = 0x82383CC0;
	sub_82383A70(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82383CD0:
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

__attribute__((alias("__imp__sub_82383CE4"))) PPC_WEAK_FUNC(sub_82383CE4);
PPC_FUNC_IMPL(__imp__sub_82383CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383CE8"))) PPC_WEAK_FUNC(sub_82383CE8);
PPC_FUNC_IMPL(__imp__sub_82383CE8) {
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
	ctx.lr = 0x82383CF0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r31,r11,-7924
	r31.s64 = r11.s64 + -7924;
	// lwz r11,-7924(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7924);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82383f20
	if (!cr6.eq) goto loc_82383F20;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x82383D10;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82383d24
	if (cr6.eq) goto loc_82383D24;
	// bl 0x821d5408
	ctx.lr = 0x82383D20;
	sub_821D5408(ctx, base);
	// b 0x82383d28
	goto loc_82383D28;
loc_82383D24:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82383D28:
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-15748
	ctx.r7.s64 = ctx.r10.s64 + -15748;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,288
	ctx.r5.s64 = 288;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32200
	ctx.r8.s64 = -2110259200;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// addi r4,r8,15520
	ctx.r4.s64 = ctx.r8.s64 + 15520;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,32404
	ctx.r9.s64 = ctx.r3.s64 + 32404;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r10,32428
	ctx.r8.s64 = ctx.r10.s64 + 32428;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,28
	ctx.r10.s64 = 28;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r11,24
	r11.s64 = 24;
	// addi r6,r5,32452
	ctx.r6.s64 = ctx.r5.s64 + 32452;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r5,r4,32476
	ctx.r5.s64 = ctx.r4.s64 + 32476;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r7,32500
	ctx.r4.s64 = ctx.r7.s64 + 32500;
	// addi r6,r8,32524
	ctx.r6.s64 = ctx.r8.s64 + 32524;
	// li r11,36
	r11.s64 = 36;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// li r9,44
	ctx.r9.s64 = 44;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,32548
	ctx.r5.s64 = ctx.r7.s64 + 32548;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,32572
	ctx.r4.s64 = r30.s64 + 32572;
	// addi r6,r8,32596
	ctx.r6.s64 = ctx.r8.s64 + 32596;
	// li r11,48
	r11.s64 = 48;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r10,52
	ctx.r10.s64 = 52;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// lis r30,-32130
	r30.s64 = -2105671680;
	// li r9,56
	ctx.r9.s64 = 56;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// addi r5,r7,32620
	ctx.r5.s64 = ctx.r7.s64 + 32620;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r4,r30,32644
	ctx.r4.s64 = r30.s64 + 32644;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lis r30,-32130
	r30.s64 = -2105671680;
	// addi r6,r8,32668
	ctx.r6.s64 = ctx.r8.s64 + 32668;
	// li r11,60
	r11.s64 = 60;
	// li r10,64
	ctx.r10.s64 = 64;
	// addi r8,r7,32692
	ctx.r8.s64 = ctx.r7.s64 + 32692;
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, r11.u32);
	// addi r7,r30,32728
	ctx.r7.s64 = r30.s64 + 32728;
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// li r9,72
	ctx.r9.s64 = 72;
	// li r11,80
	r11.s64 = 80;
	// li r10,96
	ctx.r10.s64 = 96;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// addi r8,r6,32764
	ctx.r8.s64 = ctx.r6.s64 + 32764;
	// addi r7,r11,-32736
	ctx.r7.s64 = r11.s64 + -32736;
	// addi r6,r10,-32700
	ctx.r6.s64 = ctx.r10.s64 + -32700;
	// li r11,112
	r11.s64 = 112;
	// li r10,128
	ctx.r10.s64 = 128;
	// li r9,144
	ctx.r9.s64 = 144;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// lis r30,-32129
	r30.s64 = -2105606144;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r29,-32129
	r29.s64 = -2105606144;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r28,-32129
	r28.s64 = -2105606144;
	// addi r8,r30,-32664
	ctx.r8.s64 = r30.s64 + -32664;
	// addi r7,r29,-32628
	ctx.r7.s64 = r29.s64 + -32628;
	// addi r6,r28,-32592
	ctx.r6.s64 = r28.s64 + -32592;
	// li r11,160
	r11.s64 = 160;
	// li r10,176
	ctx.r10.s64 = 176;
	// li r9,192
	ctx.r9.s64 = 192;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// bl 0x821d4458
	ctx.lr = 0x82383ECC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x82383EDC;
	sub_821D4100(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,28
	ctx.r3.s64 = r11.s64 + 28;
	// lwz r11,0(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x821d41d0
	ctx.lr = 0x82383EF8;
	sub_821D41D0(ctx, base);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r10,-32552
	ctx.r4.s64 = ctx.r10.s64 + -32552;
	// bl 0x821d4b00
	ctx.lr = 0x82383F08;
	sub_821D4B00(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,2828(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2828);
	// bl 0x821c0548
	ctx.lr = 0x82383F20;
	sub_821C0548(ctx, base);
loc_82383F20:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82383F28"))) PPC_WEAK_FUNC(sub_82383F28);
PPC_FUNC_IMPL(__imp__sub_82383F28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	// rlwinm r9,r5,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r11,r3,12
	r11.s64 = ctx.r3.s64 + 12;
	// addi r10,r9,-6
	ctx.r10.s64 = ctx.r9.s64 + -6;
	// li r8,6
	ctx.r8.s64 = 6;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// blt cr6,0x82384014
	if (cr6.lt) goto loc_82384014;
	// addi r10,r9,-10
	ctx.r10.s64 = ctx.r9.s64 + -10;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,6
	ctx.r8.s64 = ctx.r8.s64 + 6;
loc_82383F54:
	// lhz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lhz r3,2(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 2);
	// lhz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// extsh r6,r5
	ctx.r6.s64 = ctx.r5.s16;
	// lhz r4,6(r11)
	ctx.r4.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// extsh r5,r3
	ctx.r5.s64 = ctx.r3.s16;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// std r6,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r6.u64);
	// extsh r7,r4
	ctx.r7.s64 = ctx.r4.s16;
	// lfd f0,-48(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// extsh r6,r3
	ctx.r6.s64 = ctx.r3.s16;
	// std r5,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r5.u64);
	// std r7,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r7.u64);
	// lfd f12,-32(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// std r6,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r6.u64);
	// lfd f11,-24(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// lfd f13,-40(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// fcfid f8,f13
	ctx.f8.f64 = double(ctx.f13.s64);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// fcfid f9,f0
	ctx.f9.f64 = double(f0.s64);
	// fcfid f6,f11
	ctx.f6.f64 = double(ctx.f11.s64);
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// frsp f5,f9
	ctx.f5.f64 = double(float(ctx.f9.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// fmuls f13,f4,f1
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f1.f64));
	// fmuls f3,f7,f1
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f1.f64));
	// fmuls f0,f5,f1
	f0.f64 = double(float(ctx.f5.f64 * ctx.f1.f64));
	// fmuls f11,f2,f1
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f1.f64));
	// fctiwz f9,f13
	ctx.f9.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f9,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.f9.u64);
	// lhz r3,-2(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + -2);
	// fctiwz f12,f3
	ctx.f12.s64 = (ctx.f3.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfd f12,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f12.u64);
	// lhz r5,-10(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// fctiwz f10,f0
	ctx.f10.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// fctiwz f8,f11
	ctx.f8.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// stfd f8,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.f8.u64);
	// lhz r4,-10(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// lhz r7,-2(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + -2);
	// sth r5,6(r11)
	PPC_STORE_U16(r11.u32 + 6, ctx.r5.u16);
	// sth r3,2(r11)
	PPC_STORE_U16(r11.u32 + 2, ctx.r3.u16);
	// sth r4,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r4.u16);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bne 0x82383f54
	if (!cr0.eq) goto loc_82383F54;
loc_82384014:
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bgelr cr6
	if (!cr6.lt) return;
	// subf r10,r8,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r8.s64;
loc_82384020:
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 0);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// std r7,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r7.u64);
	// lfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f12,f1
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f1.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f10.u64);
	// lhz r6,-10(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// sth r6,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r6.u16);
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
	// bne 0x82384020
	if (!cr0.eq) goto loc_82384020;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238405C"))) PPC_WEAK_FUNC(sub_8238405C);
PPC_FUNC_IMPL(__imp__sub_8238405C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384060"))) PPC_WEAK_FUNC(sub_82384060);
PPC_FUNC_IMPL(__imp__sub_82384060) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-15192
	ctx.r5.s64 = r11.s64 + -15192;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,6
	ctx.r6.s64 = r31.s64 + 6;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x8238409C;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-15204
	ctx.r5.s64 = ctx.r10.s64 + -15204;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x823840BC;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-15216
	ctx.r5.s64 = ctx.r9.s64 + -15216;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,14
	ctx.r6.s64 = r31.s64 + 14;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x823840DC;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-15228
	ctx.r5.s64 = ctx.r8.s64 + -15228;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x823840FC;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-15236
	ctx.r5.s64 = ctx.r7.s64 + -15236;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,18
	ctx.r6.s64 = r31.s64 + 18;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x8238411C;
	sub_824DF200(ctx, base);
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r6,17064
	ctx.r5.s64 = ctx.r6.s64 + 17064;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x8238413C;
	sub_824DF200(ctx, base);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r5,17020
	ctx.r5.s64 = ctx.r5.s64 + 17020;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,22
	ctx.r6.s64 = r31.s64 + 22;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x8238415C;
	sub_824DF200(ctx, base);
	// lis r4,-32251
	ctx.r4.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r4,-29468
	ctx.r5.s64 = ctx.r4.s64 + -29468;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,24
	ctx.r6.s64 = r31.s64 + 24;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x8238417C;
	sub_824DF200(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-15244
	ctx.r5.s64 = r11.s64 + -15244;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,26
	ctx.r6.s64 = r31.s64 + 26;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x8238419C;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,-15256
	ctx.r5.s64 = ctx.r10.s64 + -15256;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,28
	ctx.r6.s64 = r31.s64 + 28;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x823841BC;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r9,-28720
	ctx.r5.s64 = ctx.r9.s64 + -28720;
	// addi r6,r31,30
	ctx.r6.s64 = r31.s64 + 30;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x823841DC;
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

__attribute__((alias("__imp__sub_823841F4"))) PPC_WEAK_FUNC(sub_823841F4);
PPC_FUNC_IMPL(__imp__sub_823841F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823841F8"))) PPC_WEAK_FUNC(sub_823841F8);
PPC_FUNC_IMPL(__imp__sub_823841F8) {
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
	// lis r11,-32251
	r11.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-15192
	ctx.r5.s64 = r11.s64 + -15192;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,6
	ctx.r6.s64 = r31.s64 + 6;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x82384234;
	sub_824DF200(ctx, base);
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-15156
	ctx.r5.s64 = ctx.r10.s64 + -15156;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,12
	ctx.r6.s64 = r31.s64 + 12;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x82384254;
	sub_824DF200(ctx, base);
	// lis r9,-32251
	ctx.r9.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r9,-15164
	ctx.r5.s64 = ctx.r9.s64 + -15164;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,14
	ctx.r6.s64 = r31.s64 + 14;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x82384274;
	sub_824DF200(ctx, base);
	// lis r8,-32251
	ctx.r8.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r8,-15176
	ctx.r5.s64 = ctx.r8.s64 + -15176;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,16
	ctx.r6.s64 = r31.s64 + 16;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x82384294;
	sub_824DF200(ctx, base);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r7,-15228
	ctx.r5.s64 = ctx.r7.s64 + -15228;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,18
	ctx.r6.s64 = r31.s64 + 18;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x824df200
	ctx.lr = 0x823842B4;
	sub_824DF200(ctx, base);
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r6,-28720
	ctx.r5.s64 = ctx.r6.s64 + -28720;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,20
	ctx.r6.s64 = r31.s64 + 20;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x823842D4;
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

