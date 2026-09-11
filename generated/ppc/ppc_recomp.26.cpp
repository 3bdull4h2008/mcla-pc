#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_822153A0) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826947a0
	ctx.lr = 0x822153C0;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x822153C4;
	sub_823DD7F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x822153D4;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x822153D8;
	sub_823DD7F0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822c7e78
	ctx.lr = 0x822153E0;
	sub_822C7E78(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x822153EC;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221541c
	if (cr6.eq) goto loc_8221541C;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82215400;
	sub_822A39C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a5578
	ctx.lr = 0x82215408;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8221541c
	if (cr6.eq) goto loc_8221541C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5578
	ctx.lr = 0x82215418;
	sub_822A5578(ctx, base);
	// bl 0x822a0028
	ctx.lr = 0x8221541C;
	sub_822A0028(ctx, base);
loc_8221541C:
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

PPC_WEAK_FUNC(sub_822153A0) {
	__imp__sub_822153A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215434) {
	__imp__sub_82215434(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215438) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6736(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6736);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,-6736(r11)
	PPC_STORE_U8(r11.u32 + -6736, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82215438) {
	__imp__sub_82215438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215454) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215454) {
	__imp__sub_82215454(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215458) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6736(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6736);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,-6736(r11)
	PPC_STORE_U8(r11.u32 + -6736, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82215458) {
	__imp__sub_82215458(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215474) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215474) {
	__imp__sub_82215474(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215478) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6745(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6745);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,-6745(r11)
	PPC_STORE_U8(r11.u32 + -6745, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82215478) {
	__imp__sub_82215478(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215494) {
	__imp__sub_82215494(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215498) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6745(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6745);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,-6745(r11)
	PPC_STORE_U8(r11.u32 + -6745, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82215498) {
	__imp__sub_82215498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822154B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822154B4) {
	__imp__sub_822154B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822154B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lwz r4,-7852(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -7852);
	// lwz r3,-8092(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// b 0x822e5ae0
	sub_822E5AE0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822154B8) {
	__imp__sub_822154B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822154CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822154CC) {
	__imp__sub_822154CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822154D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,-8092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -8092);
	// lwz r11,364(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 364);
	// stw r11,-7852(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7852, r11.u32);
	// b 0x822e5af0
	sub_822E5AF0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822154D0) {
	__imp__sub_822154D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822154EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822154EC) {
	__imp__sub_822154EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822154F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// stb r11,18268(r10)
	PPC_STORE_U8(ctx.r10.u32 + 18268, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822154F0) {
	__imp__sub_822154F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215500) {
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
	// li r5,60
	ctx.r5.s64 = 60;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x823da950
	ctx.lr = 0x82215524;
	sub_823DA950(ctx, base);
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// addi r4,r30,80
	ctx.r4.s64 = r30.s64 + 80;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// lbz r10,64(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 64);
	// stb r10,64(r31)
	PPC_STORE_U8(r31.u32 + 64, ctx.r10.u8);
	// lwz r9,68(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// stw r9,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r9.u32);
	// lwz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// bl 0x82214f50
	ctx.lr = 0x82215550;
	sub_82214F50(ctx, base);
	// lwz r7,640(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 640);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,640(r31)
	PPC_STORE_U32(r31.u32 + 640, ctx.r7.u32);
	// lwz r6,644(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 644);
	// stw r6,644(r31)
	PPC_STORE_U32(r31.u32 + 644, ctx.r6.u32);
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

PPC_WEAK_FUNC(sub_82215500) {
	__imp__sub_82215500(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221557C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221557C) {
	__imp__sub_8221557C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215580) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-5016
	ctx.r3.s64 = r11.s64 + -5016;
	// lwz r5,60(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lwz r4,124(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// bl 0x82130000
	ctx.lr = 0x822155A8;
	sub_82130000(ctx, base);
	// li r4,656
	ctx.r4.s64 = 656;
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// bl 0x827bd044
	ctx.lr = 0x822155B4;
	__imp__XamLoaderSetLaunchData(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-5028
	ctx.r3.s64 = ctx.r10.s64 + -5028;
	// bl 0x821324a0
	ctx.lr = 0x822155C4;
	sub_821324A0(ctx, base);
}

PPC_WEAK_FUNC(sub_82215580) {
	__imp__sub_82215580(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822155C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822155C4) {
	__imp__sub_822155C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822155C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f30.u64);
	// stfd f31,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
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
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826947a0
	ctx.lr = 0x82215624;
	sub_826947A0(ctx, base);
	// bl 0x823de058
	ctx.lr = 0x82215628;
	sub_823DE058(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,27644(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27644);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// bl 0x82214d90
	ctx.lr = 0x82215640;
	sub_82214D90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x826947a0
	ctx.lr = 0x8221564C;
	sub_826947A0(ctx, base);
	// bl 0x823de058
	ctx.lr = 0x82215650;
	sub_823DE058(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// bl 0x826947a0
	ctx.lr = 0x82215660;
	sub_826947A0(ctx, base);
	// bl 0x823de058
	ctx.lr = 0x82215664;
	sub_823DE058(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(ctx.f1.f64));
	// bl 0x826947a0
	ctx.lr = 0x82215674;
	sub_826947A0(ctx, base);
	// bl 0x823de058
	ctx.lr = 0x82215678;
	sub_823DE058(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stfs f30,132(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r5,-32122
	ctx.r5.s64 = -2105147392;
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r31,r5,2272
	r31.s64 = ctx.r5.s64 + 2272;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// lwz r3,17268(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822156A4;
	sub_822A3998(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x822156C8;
	sub_822A9930(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
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

PPC_WEAK_FUNC(sub_822155C8) {
	__imp__sub_822155C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822156E8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82215700;
	sub_822A39C8(ctx, base);
	// bl 0x822a6de0
	ctx.lr = 0x82215704;
	sub_822A6DE0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822156E8) {
	__imp__sub_822156E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215714) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215714) {
	__imp__sub_82215714(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215718) {
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
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// beq cr6,0x82215754
	if (cr6.eq) goto loc_82215754;
	// bl 0x822a39c8
	ctx.lr = 0x8221573C;
	sub_822A39C8(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82215740;
	sub_822A5578(ctx, base);
	// bl 0x822a2370
	ctx.lr = 0x82215744;
	sub_822A2370(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82215754:
	// bl 0x822a39c8
	ctx.lr = 0x82215758;
	sub_822A39C8(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8221575C;
	sub_822A5578(ctx, base);
	// bl 0x822a0f10
	ctx.lr = 0x82215760;
	sub_822A0F10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82215718) {
	__imp__sub_82215718(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215770) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8221578C;
	sub_822A3998(ctx, base);
	// bl 0x822a5a58
	ctx.lr = 0x82215790;
	sub_822A5A58(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82215770) {
	__imp__sub_82215770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822157A0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822157BC;
	sub_822A3998(ctx, base);
	// bl 0x822a7388
	ctx.lr = 0x822157C0;
	sub_822A7388(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822157A0) {
	__imp__sub_822157A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822157D0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822157EC;
	sub_822A3998(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82215800;
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

PPC_WEAK_FUNC(sub_822157D0) {
	__imp__sub_822157D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82215834;
	sub_822A3998(ctx, base);
	// lwz r31,48(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82215968
	if (cr6.eq) goto loc_82215968;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221585c
	if (cr6.eq) goto loc_8221585C;
	// addi r11,r31,272
	r11.s64 = r31.s64 + 272;
	// b 0x82215864
	goto loc_82215864;
loc_8221585C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_82215864:
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r10,48
	ctx.r10.s64 = 48;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82215908
	if (cr6.eq) goto loc_82215908;
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,24(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822158c8
	if (cr6.lt) goto loc_822158C8;
	// li r11,1
	r11.s64 = 1;
loc_822158C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215908
	if (cr6.eq) goto loc_82215908;
	// addi r11,r3,224
	r11.s64 = ctx.r3.s64 + 224;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r9
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82215908:
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82558290
	ctx.lr = 0x82215914;
	sub_82558290(ctx, base);
	// lfs f2,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dcdd8
	ctx.lr = 0x82215920;
	sub_823DCDD8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,176(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 176, temp.u32);
	// stfs f13,180(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 180, temp.u32);
	// stfs f0,184(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 184, temp.u32);
	// bl 0x822a3998
	ctx.lr = 0x82215948;
	sub_822A3998(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8221595C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x8232c788
	ctx.lr = 0x82215968;
	sub_8232C788(ctx, base);
loc_82215968:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

PPC_WEAK_FUNC(sub_82215810) {
	__imp__sub_82215810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215980) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,-7832(r9)
	PPC_STORE_U8(ctx.r9.u32 + -7832, r11.u8);
	// stfs f0,-7844(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + -7844, temp.u32);
	// bl 0x826947a0
	ctx.lr = 0x822159B0;
	sub_826947A0(ctx, base);
	// bl 0x823de058
	ctx.lr = 0x822159B4;
	sub_823DE058(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stfd f1,-7840(r7)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r7.u32 + -7840, ctx.f1.u64);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82215980) {
	__imp__sub_82215980(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822159CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822159CC) {
	__imp__sub_822159CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822159D0) {
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
	ctx.lr = 0x822159D8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ld r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U64(r11.u32 + 0);
	// rldicr r7,r10,32,63
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// bl 0x82696dc0
	ctx.lr = 0x822159FC;
	sub_82696DC0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-7848(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7848);
	// cmpwi cr6,r11,256
	cr6.compare<int32_t>(r11.s32, 256, xer);
	// blt cr6,0x82215a18
	if (cr6.lt) goto loc_82215A18;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_82215A18:
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,100
	ctx.r3.s64 = r29.s64 + 100;
	// bl 0x82694a90
	ctx.lr = 0x82215A28;
	sub_82694A90(ctx, base);
	// lwz r11,-7848(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -7848);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r10,-9912
	ctx.r7.s64 = ctx.r10.s64 + -9912;
	// addi r6,r9,-8880
	ctx.r6.s64 = ctx.r9.s64 + -8880;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,-7848(r30)
	PPC_STORE_U32(r30.u32 + -7848, r11.u32);
	// stwx r5,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r5.u32);
	// stwx r31,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822159D0) {
	__imp__sub_822159D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215A60) {
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
	ctx.lr = 0x82215A68;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwz r3,-12640(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12640);
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215a90
	if (cr6.eq) goto loc_82215A90;
	// lbz r11,10(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82215a94
	if (cr6.eq) goto loc_82215A94;
loc_82215A90:
	// li r11,0
	r11.s64 = 0;
loc_82215A94:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215ac4
	if (cr6.eq) goto loc_82215AC4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82215AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82215ac8
	if (cr6.eq) goto loc_82215AC8;
loc_82215AC4:
	// li r11,0
	r11.s64 = 0;
loc_82215AC8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// stb r11,-7830(r10)
	PPC_STORE_U8(ctx.r10.u32 + -7830, r11.u8);
	// bl 0x82387a18
	ctx.lr = 0x82215AD4;
	sub_82387A18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82215b24
	if (cr6.eq) goto loc_82215B24;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82215AF0;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x82215AF4;
	sub_822A5578(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82215B04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12640(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12640);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82215B1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82215B24:
	// lwz r11,-12640(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -12640);
	// lbz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 6);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82215b60
	if (!cr6.eq) goto loc_82215B60;
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82215b50
	if (cr6.eq) goto loc_82215B50;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82215b54
	if (cr6.eq) goto loc_82215B54;
loc_82215B50:
	// li r11,0
	r11.s64 = 0;
loc_82215B54:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215b64
	if (cr6.eq) goto loc_82215B64;
loc_82215B60:
	// bl 0x822150d8
	ctx.lr = 0x82215B64;
	sub_822150D8(ctx, base);
loc_82215B64:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r31,-32120
	r31.s64 = -2105016320;
	// lbz r11,-7829(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -7829);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82215b88
	if (!cr6.eq) goto loc_82215B88;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e5b30
	ctx.lr = 0x82215B80;
	sub_822E5B30(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stb r3,-7831(r11)
	PPC_STORE_U8(r11.u32 + -7831, ctx.r3.u8);
loc_82215B88:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-8092(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -8092);
	// bl 0x822e5b20
	ctx.lr = 0x82215B94;
	sub_822E5B20(ctx, base);
	// lwz r3,-12640(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12640);
	// li r11,1
	r11.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r11,-7829(r30)
	PPC_STORE_U8(r30.u32 + -7829, r11.u8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82215BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82215A60) {
	__imp__sub_82215A60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215BBC) {
	__imp__sub_82215BBC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215BC0) {
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
	ctx.lr = 0x82215BC8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x824e6a18
	ctx.lr = 0x82215BD8;
	sub_824E6A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82215da8
	if (!cr6.eq) goto loc_82215DA8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r11,-7824
	r29.s64 = r11.s64 + -7824;
	// addi r4,r10,-5940
	ctx.r4.s64 = ctx.r10.s64 + -5940;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// bl 0x824e6b98
	ctx.lr = 0x82215C04;
	sub_824E6B98(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82215da8
	if (cr6.eq) goto loc_82215DA8;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r10,r10,-4956
	ctx.r10.s64 = ctx.r10.s64 + -4956;
loc_82215C1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82215c40
	if (cr6.eq) goto loc_82215C40;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82215c1c
	if (cr6.eq) goto loc_82215C1C;
loc_82215C40:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82215c64
	if (!cr6.eq) goto loc_82215C64;
	// li r11,1
	r11.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r11.u32);
	// bl 0x824e6a10
	ctx.lr = 0x82215C58;
	sub_824E6A10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82215C64:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r10,r10,-4968
	ctx.r10.s64 = ctx.r10.s64 + -4968;
loc_82215C70:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82215c94
	if (cr6.eq) goto loc_82215C94;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82215c70
	if (cr6.eq) goto loc_82215C70;
loc_82215C94:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82215ce0
	if (!cr6.eq) goto loc_82215CE0;
	// li r11,3
	r11.s64 = 3;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// stw r11,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r11.u32);
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// bl 0x82215500
	ctx.lr = 0x82215CB8;
	sub_82215500(ctx, base);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,108(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82215CC8;
	sub_821F8730(ctx, base);
	// stw r3,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6a10
	ctx.lr = 0x82215CD4;
	sub_824E6A10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82215CE0:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r10,r10,-14972
	ctx.r10.s64 = ctx.r10.s64 + -14972;
loc_82215CEC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82215d10
	if (cr6.eq) goto loc_82215D10;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82215cec
	if (cr6.eq) goto loc_82215CEC;
loc_82215D10:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82215d8c
	if (!cr6.eq) goto loc_82215D8C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-3624(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,108(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82215d64
	if (cr6.eq) goto loc_82215D64;
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r3,r30,64
	ctx.r3.s64 = r30.s64 + 64;
	// stw r10,56(r30)
	PPC_STORE_U32(r30.u32 + 56, ctx.r10.u32);
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// bl 0x82215500
	ctx.lr = 0x82215D44;
	sub_82215500(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x82215D4C;
	sub_82388598(ctx, base);
	// stw r3,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6a10
	ctx.lr = 0x82215D58;
	sub_824E6A10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82215D64:
	// li r11,4
	r11.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r11.u32);
	// bl 0x82388598
	ctx.lr = 0x82215D74;
	sub_82388598(ctx, base);
	// stw r3,60(r30)
	PPC_STORE_U32(r30.u32 + 60, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e6a10
	ctx.lr = 0x82215D80;
	sub_824E6A10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82215D8C:
	// li r11,2
	r11.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r11,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r11.u32);
	// bl 0x824e6a10
	ctx.lr = 0x82215D9C;
	sub_824E6A10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82215DA8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82215BC0) {
	__imp__sub_82215BC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215DB4) {
	__imp__sub_82215DB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215DB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-7824
	ctx.r3.s64 = r11.s64 + -7824;
	// b 0x82215bc0
	sub_82215BC0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82215DB8) {
	__imp__sub_82215DB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215DC8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,-10224(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x826947a0
	ctx.lr = 0x82215DE8;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8268b770
	ctx.lr = 0x82215DF8;
	sub_8268B770(ctx, base);
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

PPC_WEAK_FUNC(sub_82215DC8) {
	__imp__sub_82215DC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215E0C) {
	__imp__sub_82215E0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215E10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82215e38
	if (cr6.eq) goto loc_82215E38;
	// lwz r11,864(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 864);
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
loc_82215E38:
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// rlwinm r10,r11,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82215e58
	if (cr6.eq) goto loc_82215E58;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// bne cr6,0x82215e5c
	if (!cr6.eq) goto loc_82215E5C;
loc_82215E58:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82215E5C:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82215e78
	if (cr6.eq) goto loc_82215E78;
	// rlwinm r11,r11,0,0,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r11,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, r11.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r10,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, ctx.r10.u32);
loc_82215E78:
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

PPC_WEAK_FUNC(sub_82215E10) {
	__imp__sub_82215E10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82215E8C) {
	__imp__sub_82215E8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82215E90) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82215E98;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r10
	r29.u64 = ctx.r10.u64;
	// addi r10,r11,-5044
	ctx.r10.s64 = r11.s64 + -5044;
	// li r3,164
	ctx.r3.s64 = 164;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// mr r20,r4
	r20.u64 = ctx.r4.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// mr r28,r9
	r28.u64 = ctx.r9.u64;
	// bl 0x82130528
	ctx.lr = 0x82215ED0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r30,r11,-4944
	r30.s64 = r11.s64 + -4944;
	// beq cr6,0x82215ef8
	if (cr6.eq) goto loc_82215EF8;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82215EF4;
	sub_82720A50(ctx, base);
	// b 0x82215efc
	goto loc_82215EFC;
loc_82215EF8:
	// li r31,0
	r31.s64 = 0;
loc_82215EFC:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82215F04;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82215f28
	if (cr6.eq) goto loc_82215F28;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82215F20;
	sub_82720A50(ctx, base);
	// mr r22,r29
	r22.u64 = r29.u64;
	// b 0x82215f2c
	goto loc_82215F2C;
loc_82215F28:
	// li r22,0
	r22.s64 = 0;
loc_82215F2C:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82215F34;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82215f58
	if (cr6.eq) goto loc_82215F58;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82215F50;
	sub_82720A50(ctx, base);
	// mr r24,r29
	r24.u64 = r29.u64;
	// b 0x82215f5c
	goto loc_82215F5C;
loc_82215F58:
	// li r24,0
	r24.s64 = 0;
loc_82215F5C:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82215F64;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82215f88
	if (cr6.eq) goto loc_82215F88;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82215F80;
	sub_82720A50(ctx, base);
	// mr r27,r29
	r27.u64 = r29.u64;
	// b 0x82215f8c
	goto loc_82215F8C;
loc_82215F88:
	// li r27,0
	r27.s64 = 0;
loc_82215F8C:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82215F94;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82215fb8
	if (cr6.eq) goto loc_82215FB8;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82215FB0;
	sub_82720A50(ctx, base);
	// mr r28,r29
	r28.u64 = r29.u64;
	// b 0x82215fbc
	goto loc_82215FBC;
loc_82215FB8:
	// li r28,0
	r28.s64 = 0;
loc_82215FBC:
	// li r3,164
	ctx.r3.s64 = 164;
	// bl 0x82130528
	ctx.lr = 0x82215FC4;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82215fe8
	if (cr6.eq) goto loc_82215FE8;
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82720a50
	ctx.lr = 0x82215FE0;
	sub_82720A50(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// b 0x82215fec
	goto loc_82215FEC;
loc_82215FE8:
	// li r5,0
	ctx.r5.s64 = 0;
loc_82215FEC:
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// mr r9,r22
	ctx.r9.u64 = r22.u64;
	// mr r8,r24
	ctx.r8.u64 = r24.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82695808
	ctx.lr = 0x8221600C;
	sub_82695808(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9228
	return;
}

PPC_WEAK_FUNC(sub_82215E90) {
	__imp__sub_82215E90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216018) {
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
	ctx.lr = 0x82216020;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r31,r1,176
	r31.s64 = ctx.r1.s64 + 176;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_82216038:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82216044;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8221605c
	if (cr6.eq) goto loc_8221605C;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8268c7b8
	ctx.lr = 0x82216058;
	sub_8268C7B8(ctx, base);
	// b 0x82216060
	goto loc_82216060;
loc_8221605C:
	// stb r27,0(r31)
	PPC_STORE_U8(r31.u32 + 0, r27.u8);
loc_82216060:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,64
	r31.s64 = r31.s64 + 64;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x82216038
	if (!cr6.eq) goto loc_82216038;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r8,r1,368
	ctx.r8.s64 = ctx.r1.s64 + 368;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// addi r7,r1,304
	ctx.r7.s64 = ctx.r1.s64 + 304;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82215e90
	ctx.lr = 0x82216098;
	sub_82215E90(ctx, base);
	// lhz r8,2(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 2);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// addi r9,r10,-9912
	ctx.r9.s64 = ctx.r10.s64 + -9912;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwzx r3,r6,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x821c3048
	ctx.lr = 0x822160B8;
	sub_821C3048(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82214e90
	ctx.lr = 0x822160C0;
	sub_82214E90(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82216018) {
	__imp__sub_82216018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822160CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822160CC) {
	__imp__sub_822160CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822160D0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82216124
	if (cr6.eq) goto loc_82216124;
	// addis r31,r11,4
	r31.s64 = r11.s64 + 262144;
	// addi r31,r31,1792
	r31.s64 = r31.s64 + 1792;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c6d8
	ctx.lr = 0x82216108;
	sub_8268C6D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82216124
	if (cr6.lt) goto loc_82216124;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82216124;
	sub_8268EE10(ctx, base);
loc_82216124:
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

PPC_WEAK_FUNC(sub_822160D0) {
	__imp__sub_822160D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216138) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r3,r3,1792
	ctx.r3.s64 = ctx.r3.s64 + 1792;
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82216138) {
	__imp__sub_82216138(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216164) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82216164) {
	__imp__sub_82216164(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216168) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822161f0
	if (cr6.eq) goto loc_822161F0;
	// addis r30,r31,4
	r30.s64 = r31.s64 + 262144;
	// addi r30,r30,1792
	r30.s64 = r30.s64 + 1792;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268c6d8
	ctx.lr = 0x822161AC;
	sub_8268C6D8(ctx, base);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// sth r11,82(r1)
	PPC_STORE_U16(ctx.r1.u32 + 82, r11.u16);
	// bl 0x8268d6f8
	ctx.lr = 0x822161C4;
	sub_8268D6F8(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r10,80(r1)
	PPC_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// lwz r30,80(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268ed60
	ctx.lr = 0x822161DC;
	sub_8268ED60(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268ece0
	ctx.lr = 0x822161F0;
	sub_8268ECE0(ctx, base);
loc_822161F0:
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

PPC_WEAK_FUNC(sub_82216168) {
	__imp__sub_82216168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221620C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221620C) {
	__imp__sub_8221620C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216210) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8221d798
	ctx.lr = 0x82216234;
	sub_8221D798(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8221d798
	ctx.lr = 0x82216244;
	sub_8221D798(ctx, base);
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

PPC_WEAK_FUNC(sub_82216210) {
	__imp__sub_82216210(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216258) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8221626C;
	sub_82388580(ctx, base);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82216284
	if (!cr6.eq) goto loc_82216284;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-4928
	ctx.r3.s64 = r11.s64 + -4928;
	// b 0x8221628c
	goto loc_8221628C;
loc_82216284:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-4936
	ctx.r3.s64 = r11.s64 + -4936;
loc_8221628C:
	// bl 0x821fa230
	ctx.lr = 0x82216290;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,108(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822162A0;
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

PPC_WEAK_FUNC(sub_82216258) {
	__imp__sub_82216258(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822162B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r3,r3,1792
	ctx.r3.s64 = ctx.r3.s64 + 1792;
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822162B0) {
	__imp__sub_822162B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822162DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822162DC) {
	__imp__sub_822162DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822162E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,9
	ctx.r4.s64 = 9;
	// addi r3,r3,1792
	ctx.r3.s64 = ctx.r3.s64 + 1792;
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822162E0) {
	__imp__sub_822162E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221630C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221630C) {
	__imp__sub_8221630C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216310) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,-10236(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x82216338;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x82216344;
	sub_821F9FB8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82216380
	if (cr6.eq) goto loc_82216380;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x8221635C;
	sub_826947A0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
	// addi r9,r11,-102
	ctx.r9.s64 = r11.s64 + -102;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r4,r7,1
	ctx.r4.u64 = ctx.r7.u64 ^ 1;
	// bl 0x82720e28
	ctx.lr = 0x82216380;
	sub_82720E28(ctx, base);
loc_82216380:
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

PPC_WEAK_FUNC(sub_82216310) {
	__imp__sub_82216310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216398) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826947a0
	ctx.lr = 0x822163AC;
	sub_826947A0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-7824
	ctx.r3.s64 = r11.s64 + -7824;
	// bl 0x82215bc0
	ctx.lr = 0x822163BC;
	sub_82215BC0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82216398) {
	__imp__sub_82216398(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822163CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822163CC) {
	__imp__sub_822163CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822163D0) {
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
	ctx.lr = 0x822163D8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r30,-10236(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x826947a0
	ctx.lr = 0x822163F0;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x822163FC;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822164c8
	if (cr6.eq) goto loc_822164C8;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r28,56(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,-10244(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x826947a0
	ctx.lr = 0x8221641C;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82216428;
	sub_82218310(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x82216438;
	sub_826947A0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x821c9790
	ctx.lr = 0x82216444;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x82216454;
	sub_825ED480(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r30,-10244(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826947a0
	ctx.lr = 0x82216468;
	sub_826947A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82216474;
	sub_82218310(ctx, base);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82216480;
	sub_821C9790(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825ef9a8
	ctx.lr = 0x822164A8;
	sub_825EF9A8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x822164B0;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822164C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822164C8:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822163D0) {
	__imp__sub_822163D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822164D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lbz r11,-7832(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + -7832);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f0,-7844(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7844);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f1
	f0.f64 = double(float(f0.f64 + ctx.f1.f64));
	// lfd f13,-7840(r11)
	ctx.f13.u64 = PPC_LOAD_U64(r11.u32 + -7840);
	// stfs f0,-7844(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -7844, temp.u32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r11,-7832(r10)
	PPC_STORE_U8(ctx.r10.u32 + -7832, r11.u8);
	// lwz r11,-10236(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10236);
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,-7844(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + -7844, temp.u32);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r3,1792
	ctx.r3.s64 = ctx.r3.s64 + 1792;
	// b 0x8268ee10
	sub_8268EE10(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822164D0) {
	__imp__sub_822164D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216540) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82216540) {
	__imp__sub_82216540(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82216544) {
	__imp__sub_82216544(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216548) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r8,r11,-19708
	ctx.r8.s64 = r11.s64 + -19708;
	// addi r7,r10,-21500
	ctx.r7.s64 = ctx.r10.s64 + -21500;
	// addi r6,r9,-5056
	ctx.r6.s64 = ctx.r9.s64 + -5056;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// clrlwi r5,r4,31
	ctx.r5.u64 = ctx.r4.u32 & 0x1;
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82216594
	if (cr6.eq) goto loc_82216594;
	// bl 0x82130588
	ctx.lr = 0x82216590;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82216594:
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

PPC_WEAK_FUNC(sub_82216548) {
	__imp__sub_82216548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822165A8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// addi r30,r11,264
	r30.s64 = r11.s64 + 264;
	// lwz r31,264(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82216630
	if (cr6.eq) goto loc_82216630;
loc_822165D4:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a6198
	ctx.lr = 0x822165E4;
	sub_822A6198(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822165f4
	if (cr6.eq) goto loc_822165F4;
	// lwz r31,864(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// b 0x82216628
	goto loc_82216628;
loc_822165F4:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82216610
	if (cr6.eq) goto loc_82216610;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82216614
	if (!cr6.eq) goto loc_82216614;
loc_82216610:
	// li r11,0
	r11.s64 = 0;
loc_82216614:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82216630
	if (cr6.eq) goto loc_82216630;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_82216628:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822165d4
	if (!cr6.eq) goto loc_822165D4;
loc_82216630:
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

PPC_WEAK_FUNC(sub_822165A8) {
	__imp__sub_822165A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216648) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// addi r30,r11,264
	r30.s64 = r11.s64 + 264;
	// lwz r31,264(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822166d0
	if (cr6.eq) goto loc_822166D0;
loc_82216674:
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a6198
	ctx.lr = 0x82216684;
	sub_822A6198(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82216694
	if (cr6.eq) goto loc_82216694;
	// lwz r31,864(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// b 0x822166c8
	goto loc_822166C8;
loc_82216694:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822166b0
	if (cr6.eq) goto loc_822166B0;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822166b4
	if (!cr6.eq) goto loc_822166B4;
loc_822166B0:
	// li r11,0
	r11.s64 = 0;
loc_822166B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822166d0
	if (cr6.eq) goto loc_822166D0;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_822166C8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82216674
	if (!cr6.eq) goto loc_82216674;
loc_822166D0:
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

PPC_WEAK_FUNC(sub_82216648) {
	__imp__sub_82216648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822166E8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// addi r30,r11,264
	r30.s64 = r11.s64 + 264;
	// lwz r31,264(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82216770
	if (cr6.eq) goto loc_82216770;
loc_82216714:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a6198
	ctx.lr = 0x82216724;
	sub_822A6198(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82216734
	if (cr6.eq) goto loc_82216734;
	// lwz r31,864(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// b 0x82216768
	goto loc_82216768;
loc_82216734:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82216750
	if (cr6.eq) goto loc_82216750;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82216754
	if (!cr6.eq) goto loc_82216754;
loc_82216750:
	// li r11,0
	r11.s64 = 0;
loc_82216754:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82216770
	if (cr6.eq) goto loc_82216770;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_82216768:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82216714
	if (!cr6.eq) goto loc_82216714;
loc_82216770:
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

PPC_WEAK_FUNC(sub_822166E8) {
	__imp__sub_822166E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216788) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// addi r30,r11,264
	r30.s64 = r11.s64 + 264;
	// lwz r31,264(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82216810
	if (cr6.eq) goto loc_82216810;
loc_822167B4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a6198
	ctx.lr = 0x822167C4;
	sub_822A6198(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822167d4
	if (cr6.eq) goto loc_822167D4;
	// lwz r31,864(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// b 0x82216808
	goto loc_82216808;
loc_822167D4:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822167f0
	if (cr6.eq) goto loc_822167F0;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822167f4
	if (!cr6.eq) goto loc_822167F4;
loc_822167F0:
	// li r11,0
	r11.s64 = 0;
loc_822167F4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82216810
	if (cr6.eq) goto loc_82216810;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_82216808:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822167b4
	if (!cr6.eq) goto loc_822167B4;
loc_82216810:
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

PPC_WEAK_FUNC(sub_82216788) {
	__imp__sub_82216788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216828) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// lwz r31,264(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 264);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8221686c
	if (cr6.eq) goto loc_8221686C;
loc_8221684C:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82216860
	if (cr6.eq) goto loc_82216860;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8232c3a8
	ctx.lr = 0x82216860;
	sub_8232C3A8(ctx, base);
loc_82216860:
	// lwz r31,864(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8221684c
	if (!cr6.eq) goto loc_8221684C;
loc_8221686C:
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

PPC_WEAK_FUNC(sub_82216828) {
	__imp__sub_82216828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82216880) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r7,r9,3600
	ctx.r7.u64 = ctx.r9.u64 | 3600;
	// stw r11,-7848(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7848, r11.u32);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,22912
	ctx.r4.s64 = ctx.r8.s64 + 22912;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r30,r31,r7
	r30.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// bl 0x821c2ff8
	ctx.lr = 0x822168C8;
	sub_821C2FF8(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19740(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19740);
	// bl 0x822159d0
	ctx.lr = 0x822168DC;
	sub_822159D0(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,24008
	ctx.r4.s64 = ctx.r4.s64 + 24008;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x822168F4;
	sub_821C2FF8(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19744(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19744);
	// bl 0x822159d0
	ctx.lr = 0x82216908;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,23136
	ctx.r4.s64 = ctx.r10.s64 + 23136;
	// bl 0x821c2fd8
	ctx.lr = 0x82216918;
	sub_821C2FD8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19748(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19748);
	// bl 0x822159d0
	ctx.lr = 0x8221692C;
	sub_822159D0(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,20696
	ctx.r4.s64 = ctx.r8.s64 + 20696;
	// bl 0x821c2fd8
	ctx.lr = 0x8221693C;
	sub_821C2FD8(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19752(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19752);
	// bl 0x822159d0
	ctx.lr = 0x82216950;
	sub_822159D0(ctx, base);
	// lis r6,-32223
	ctx.r6.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,20936
	ctx.r4.s64 = ctx.r6.s64 + 20936;
	// bl 0x821c2fd8
	ctx.lr = 0x82216960;
	sub_821C2FD8(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19756(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19756);
	// bl 0x822159d0
	ctx.lr = 0x82216974;
	sub_822159D0(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,20960
	ctx.r4.s64 = r11.s64 + 20960;
	// bl 0x821c2fd8
	ctx.lr = 0x82216984;
	sub_821C2FD8(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19760(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -19760);
	// bl 0x822159d0
	ctx.lr = 0x82216998;
	sub_822159D0(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,21152
	ctx.r4.s64 = ctx.r9.s64 + 21152;
	// bl 0x821c2fd8
	ctx.lr = 0x822169A8;
	sub_821C2FD8(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19764(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -19764);
	// bl 0x822159d0
	ctx.lr = 0x822169BC;
	sub_822159D0(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,21320
	ctx.r4.s64 = ctx.r7.s64 + 21320;
	// bl 0x821c2fd8
	ctx.lr = 0x822169CC;
	sub_821C2FD8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19768(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19768);
	// bl 0x822159d0
	ctx.lr = 0x822169E0;
	sub_822159D0(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r5,26184
	ctx.r4.s64 = ctx.r5.s64 + 26184;
	// bl 0x821c2fd8
	ctx.lr = 0x822169F0;
	sub_821C2FD8(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19772(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19772);
	// bl 0x822159d0
	ctx.lr = 0x82216A04;
	sub_822159D0(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,26344
	ctx.r4.s64 = r11.s64 + 26344;
	// bl 0x821c2fd8
	ctx.lr = 0x82216A14;
	sub_821C2FD8(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19776(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -19776);
	// bl 0x822159d0
	ctx.lr = 0x82216A28;
	sub_822159D0(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,26024
	ctx.r4.s64 = ctx.r9.s64 + 26024;
	// bl 0x821c2fd8
	ctx.lr = 0x82216A38;
	sub_821C2FD8(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19780(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -19780);
	// bl 0x822159d0
	ctx.lr = 0x82216A4C;
	sub_822159D0(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,26184
	ctx.r4.s64 = ctx.r7.s64 + 26184;
	// bl 0x821c2fd8
	ctx.lr = 0x82216A5C;
	sub_821C2FD8(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19784(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19784);
	// bl 0x822159d0
	ctx.lr = 0x82216A70;
	sub_822159D0(ctx, base);
	// lis r5,-32223
	ctx.r5.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r5,21744
	ctx.r4.s64 = ctx.r5.s64 + 21744;
	// bl 0x821c2fd8
	ctx.lr = 0x82216A80;
	sub_821C2FD8(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19788(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19788);
	// bl 0x822159d0
	ctx.lr = 0x82216A94;
	sub_822159D0(ctx, base);
	// lis r3,-32223
	ctx.r3.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r3,25496
	ctx.r4.s64 = ctx.r3.s64 + 25496;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82216AAC;
	sub_821C2FF8(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19792(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19792);
	// bl 0x822159d0
	ctx.lr = 0x82216AC0;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,20536
	ctx.r4.s64 = ctx.r10.s64 + 20536;
	// bl 0x821c2fd8
	ctx.lr = 0x82216AD0;
	sub_821C2FD8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19796(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19796);
	// bl 0x822159d0
	ctx.lr = 0x82216AE4;
	sub_822159D0(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,20552
	ctx.r4.s64 = ctx.r8.s64 + 20552;
	// bl 0x821c2fd8
	ctx.lr = 0x82216AF4;
	sub_821C2FD8(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19800(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19800);
	// bl 0x822159d0
	ctx.lr = 0x82216B08;
	sub_822159D0(ctx, base);
	// lis r6,-32223
	ctx.r6.s64 = -2111766528;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,22296
	ctx.r4.s64 = ctx.r6.s64 + 22296;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c3028
	ctx.lr = 0x82216B1C;
	sub_821C3028(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19804(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19804);
	// bl 0x822159d0
	ctx.lr = 0x82216B30;
	sub_822159D0(ctx, base);
	// lis r3,-32224
	ctx.r3.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r3,16208
	ctx.r4.s64 = ctx.r3.s64 + 16208;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216B4C;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19808(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19808);
	// bl 0x822159d0
	ctx.lr = 0x82216B60;
	sub_822159D0(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,16096
	ctx.r4.s64 = ctx.r10.s64 + 16096;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216B7C;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19812(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19812);
	// bl 0x822159d0
	ctx.lr = 0x82216B90;
	sub_822159D0(ctx, base);
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r8,0
	ctx.r4.s64 = ctx.r8.s64 + 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216BAC;
	sub_821C2FB0(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19816(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19816);
	// bl 0x822159d0
	ctx.lr = 0x82216BC0;
	sub_822159D0(ctx, base);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,16256
	ctx.r4.s64 = ctx.r4.s64 + 16256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216BDC;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19820(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19820);
	// bl 0x822159d0
	ctx.lr = 0x82216BF0;
	sub_822159D0(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,16272
	ctx.r4.s64 = ctx.r10.s64 + 16272;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216C0C;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19824(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19824);
	// bl 0x822159d0
	ctx.lr = 0x82216C20;
	sub_822159D0(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r8,-27176
	ctx.r4.s64 = ctx.r8.s64 + -27176;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216C3C;
	sub_821C2FB0(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19828(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19828);
	// bl 0x822159d0
	ctx.lr = 0x82216C50;
	sub_822159D0(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-27760
	ctx.r4.s64 = ctx.r4.s64 + -27760;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216C6C;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19832(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19832);
	// bl 0x822159d0
	ctx.lr = 0x82216C80;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,-26560
	ctx.r4.s64 = ctx.r10.s64 + -26560;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216C9C;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19836(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19836);
	// bl 0x822159d0
	ctx.lr = 0x82216CB0;
	sub_822159D0(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r8,-26360
	ctx.r4.s64 = ctx.r8.s64 + -26360;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216CCC;
	sub_821C2FB0(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19840(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19840);
	// bl 0x822159d0
	ctx.lr = 0x82216CE0;
	sub_822159D0(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,-26136
	ctx.r4.s64 = ctx.r4.s64 + -26136;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216CFC;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19844(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19844);
	// bl 0x822159d0
	ctx.lr = 0x82216D10;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,-25912
	ctx.r4.s64 = ctx.r10.s64 + -25912;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216D2C;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19848(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19848);
	// bl 0x822159d0
	ctx.lr = 0x82216D40;
	sub_822159D0(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r8,-25720
	ctx.r4.s64 = ctx.r8.s64 + -25720;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216D5C;
	sub_821C2FB0(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19852(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19852);
	// bl 0x822159d0
	ctx.lr = 0x82216D70;
	sub_822159D0(ctx, base);
	// lis r4,-32224
	ctx.r4.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,29072
	ctx.r4.s64 = ctx.r4.s64 + 29072;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216D8C;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19856(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19856);
	// bl 0x822159d0
	ctx.lr = 0x82216DA0;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-28752
	ctx.r4.s64 = ctx.r10.s64 + -28752;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216DBC;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19860(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19860);
	// bl 0x822159d0
	ctx.lr = 0x82216DD0;
	sub_822159D0(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,13640
	ctx.r4.s64 = ctx.r8.s64 + 13640;
	// bl 0x821c2fd8
	ctx.lr = 0x82216DE0;
	sub_821C2FD8(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19864(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19864);
	// bl 0x822159d0
	ctx.lr = 0x82216DF4;
	sub_822159D0(ctx, base);
	// lis r6,-32223
	ctx.r6.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,20440
	ctx.r4.s64 = ctx.r6.s64 + 20440;
	// bl 0x821c2fd8
	ctx.lr = 0x82216E04;
	sub_821C2FD8(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19868(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19868);
	// bl 0x822159d0
	ctx.lr = 0x82216E18;
	sub_822159D0(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,25104
	ctx.r4.s64 = r11.s64 + 25104;
	// bl 0x821c2fd8
	ctx.lr = 0x82216E28;
	sub_821C2FD8(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19872(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -19872);
	// bl 0x822159d0
	ctx.lr = 0x82216E3C;
	sub_822159D0(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,25312
	ctx.r4.s64 = ctx.r9.s64 + 25312;
	// bl 0x821c2fd8
	ctx.lr = 0x82216E4C;
	sub_821C2FD8(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19876(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -19876);
	// bl 0x822159d0
	ctx.lr = 0x82216E60;
	sub_822159D0(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,25360
	ctx.r4.s64 = ctx.r7.s64 + 25360;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82216E78;
	sub_821C2FF8(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19880(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19880);
	// bl 0x822159d0
	ctx.lr = 0x82216E8C;
	sub_822159D0(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,25552
	ctx.r4.s64 = ctx.r4.s64 + 25552;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82216EA4;
	sub_821C2FF8(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19884(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19884);
	// bl 0x822159d0
	ctx.lr = 0x82216EB8;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,22432
	ctx.r4.s64 = ctx.r10.s64 + 22432;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82216ED0;
	sub_821C2FF8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19888(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19888);
	// bl 0x822159d0
	ctx.lr = 0x82216EE4;
	sub_822159D0(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,22544
	ctx.r4.s64 = ctx.r8.s64 + 22544;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82216EFC;
	sub_821C2FF8(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19892(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19892);
	// bl 0x822159d0
	ctx.lr = 0x82216F10;
	sub_822159D0(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,22480
	ctx.r4.s64 = ctx.r4.s64 + 22480;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82216F28;
	sub_821C2FF8(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19896(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19896);
	// bl 0x822159d0
	ctx.lr = 0x82216F3C;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,21960
	ctx.r4.s64 = ctx.r10.s64 + 21960;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82216F54;
	sub_821C2FF8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19900(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19900);
	// bl 0x822159d0
	ctx.lr = 0x82216F68;
	sub_822159D0(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,26664
	ctx.r4.s64 = ctx.r8.s64 + 26664;
	// bl 0x821c2fd8
	ctx.lr = 0x82216F78;
	sub_821C2FD8(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19904(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19904);
	// bl 0x822159d0
	ctx.lr = 0x82216F8C;
	sub_822159D0(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,8440
	ctx.r4.s64 = ctx.r4.s64 + 8440;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216FA8;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19908(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19908);
	// bl 0x822159d0
	ctx.lr = 0x82216FBC;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,8544
	ctx.r4.s64 = ctx.r10.s64 + 8544;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82216FD8;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19912(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19912);
	// bl 0x822159d0
	ctx.lr = 0x82216FEC;
	sub_822159D0(ctx, base);
	// lis r8,-32237
	ctx.r8.s64 = -2112684032;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,0
	ctx.r4.s64 = ctx.r8.s64 + 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82217004;
	sub_821C2FF8(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19916(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19916);
	// bl 0x822159d0
	ctx.lr = 0x82217018;
	sub_822159D0(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r4,21688
	ctx.r4.s64 = ctx.r4.s64 + 21688;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82217030;
	sub_821C2FF8(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19920(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19920);
	// bl 0x822159d0
	ctx.lr = 0x82217044;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,21712
	ctx.r4.s64 = ctx.r10.s64 + 21712;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x8221705C;
	sub_821C2FF8(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19924(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19924);
	// bl 0x822159d0
	ctx.lr = 0x82217070;
	sub_822159D0(ctx, base);
	// lis r8,-32223
	ctx.r8.s64 = -2111766528;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,21408
	ctx.r4.s64 = ctx.r8.s64 + 21408;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2ff8
	ctx.lr = 0x82217088;
	sub_821C2FF8(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19928(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19928);
	// bl 0x822159d0
	ctx.lr = 0x8221709C;
	sub_822159D0(ctx, base);
	// lis r6,-32223
	ctx.r6.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,25176
	ctx.r4.s64 = ctx.r6.s64 + 25176;
	// bl 0x821c2fd8
	ctx.lr = 0x822170AC;
	sub_821C2FD8(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19932(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19932);
	// bl 0x822159d0
	ctx.lr = 0x822170C0;
	sub_822159D0(ctx, base);
	// lis r3,-32223
	ctx.r3.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r3,3384
	ctx.r4.s64 = ctx.r3.s64 + 3384;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x822170DC;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19936(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19936);
	// bl 0x822159d0
	ctx.lr = 0x822170F0;
	sub_822159D0(ctx, base);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,15912
	ctx.r4.s64 = ctx.r10.s64 + 15912;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x8221710C;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19940(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19940);
	// bl 0x822159d0
	ctx.lr = 0x82217120;
	sub_822159D0(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r8,15952
	ctx.r4.s64 = ctx.r8.s64 + 15952;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x8221713C;
	sub_821C2FB0(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19944(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19944);
	// bl 0x822159d0
	ctx.lr = 0x82217150;
	sub_822159D0(ctx, base);
	// lis r4,-32223
	ctx.r4.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,3464
	ctx.r4.s64 = ctx.r4.s64 + 3464;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x8221716C;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r4,-19948(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19948);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822159d0
	ctx.lr = 0x82217180;
	sub_822159D0(ctx, base);
	// lis r10,-32223
	ctx.r10.s64 = -2111766528;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,-28864
	ctx.r4.s64 = ctx.r10.s64 + -28864;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x8221719C;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19952(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19952);
	// bl 0x822159d0
	ctx.lr = 0x822171B0;
	sub_822159D0(ctx, base);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,29600
	ctx.r4.s64 = ctx.r8.s64 + 29600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x822171C4;
	sub_821C2F90(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19956(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19956);
	// bl 0x822159d0
	ctx.lr = 0x822171D8;
	sub_822159D0(ctx, base);
	// lis r6,-32223
	ctx.r6.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r6,21560
	ctx.r4.s64 = ctx.r6.s64 + 21560;
	// bl 0x821c2fd8
	ctx.lr = 0x822171E8;
	sub_821C2FD8(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19960(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19960);
	// bl 0x822159d0
	ctx.lr = 0x822171FC;
	sub_822159D0(ctx, base);
	// lis r11,-32223
	r11.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,21592
	ctx.r4.s64 = r11.s64 + 21592;
	// bl 0x821c2fd8
	ctx.lr = 0x8221720C;
	sub_821C2FD8(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19964(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -19964);
	// bl 0x822159d0
	ctx.lr = 0x82217220;
	sub_822159D0(ctx, base);
	// lis r9,-32223
	ctx.r9.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,21624
	ctx.r4.s64 = ctx.r9.s64 + 21624;
	// bl 0x821c2fd8
	ctx.lr = 0x82217230;
	sub_821C2FD8(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19968(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + -19968);
	// bl 0x822159d0
	ctx.lr = 0x82217244;
	sub_822159D0(ctx, base);
	// lis r7,-32223
	ctx.r7.s64 = -2111766528;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,21656
	ctx.r4.s64 = ctx.r7.s64 + 21656;
	// bl 0x821c2fd8
	ctx.lr = 0x82217254;
	sub_821C2FD8(ctx, base);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19972(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + -19972);
	// bl 0x822159d0
	ctx.lr = 0x82217268;
	sub_822159D0(ctx, base);
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r5,-32150
	ctx.r5.s64 = -2106982400;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r5,-5016
	ctx.r4.s64 = ctx.r5.s64 + -5016;
	// lwz r5,-29340(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -29340);
	// bl 0x821c2f90
	ctx.lr = 0x82217280;
	sub_821C2F90(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19976(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19976);
	// bl 0x822159d0
	ctx.lr = 0x82217294;
	sub_822159D0(ctx, base);
	// lis r11,-32150
	r11.s64 = -2106982400;
	// lwz r5,-29340(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -29340);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,18840
	ctx.r4.s64 = r11.s64 + 18840;
	// bl 0x821c2f90
	ctx.lr = 0x822172A8;
	sub_821C2F90(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19980(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -19980);
	// bl 0x822159d0
	ctx.lr = 0x822172BC;
	sub_822159D0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32219
	ctx.r8.s64 = -2111504384;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,16424
	ctx.r4.s64 = ctx.r8.s64 + 16424;
	// lwz r5,-6148(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + -6148);
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x821c2f90
	ctx.lr = 0x822172D8;
	sub_821C2F90(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19984(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -19984);
	// bl 0x822159d0
	ctx.lr = 0x822172EC;
	sub_822159D0(ctx, base);
	// lis r6,-32219
	ctx.r6.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r6,16712
	ctx.r4.s64 = ctx.r6.s64 + 16712;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217300;
	sub_821C2F90(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19988(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -19988);
	// bl 0x822159d0
	ctx.lr = 0x82217314;
	sub_822159D0(ctx, base);
	// lis r3,-32219
	ctx.r3.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r3,1600
	ctx.r4.s64 = ctx.r3.s64 + 1600;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217328;
	sub_821C2F90(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19992(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -19992);
	// bl 0x822159d0
	ctx.lr = 0x8221733C;
	sub_822159D0(ctx, base);
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,20176
	ctx.r4.s64 = ctx.r10.s64 + 20176;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217350;
	sub_821C2F90(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-19996(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -19996);
	// bl 0x822159d0
	ctx.lr = 0x82217364;
	sub_822159D0(ctx, base);
	// lis r8,-32219
	ctx.r8.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,23904
	ctx.r4.s64 = ctx.r8.s64 + 23904;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217378;
	sub_821C2F90(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20000(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20000);
	// bl 0x822159d0
	ctx.lr = 0x8221738C;
	sub_822159D0(ctx, base);
	// lis r6,-32219
	ctx.r6.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r6,3280
	ctx.r4.s64 = ctx.r6.s64 + 3280;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x822173A0;
	sub_821C2F90(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20004(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20004);
	// bl 0x822159d0
	ctx.lr = 0x822173B4;
	sub_822159D0(ctx, base);
	// lis r3,-32219
	ctx.r3.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r3,11632
	ctx.r4.s64 = ctx.r3.s64 + 11632;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x822173C8;
	sub_821C2F90(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20008(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -20008);
	// bl 0x822159d0
	ctx.lr = 0x822173DC;
	sub_822159D0(ctx, base);
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,11792
	ctx.r4.s64 = ctx.r10.s64 + 11792;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x822173F0;
	sub_821C2F90(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20012(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20012);
	// bl 0x822159d0
	ctx.lr = 0x82217404;
	sub_822159D0(ctx, base);
	// lis r8,-32219
	ctx.r8.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r8,20960
	ctx.r4.s64 = ctx.r8.s64 + 20960;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217418;
	sub_821C2F90(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20016(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20016);
	// bl 0x822159d0
	ctx.lr = 0x8221742C;
	sub_822159D0(ctx, base);
	// lis r6,-32219
	ctx.r6.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r6,13936
	ctx.r4.s64 = ctx.r6.s64 + 13936;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217440;
	sub_821C2F90(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20020(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20020);
	// bl 0x822159d0
	ctx.lr = 0x82217454;
	sub_822159D0(ctx, base);
	// lis r3,-32237
	ctx.r3.s64 = -2112684032;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r3,0
	ctx.r4.s64 = ctx.r3.s64 + 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217468;
	sub_821C2F90(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20024(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -20024);
	// bl 0x822159d0
	ctx.lr = 0x8221747C;
	sub_822159D0(ctx, base);
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,3496
	ctx.r4.s64 = ctx.r10.s64 + 3496;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217490;
	sub_821C2F90(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20028(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20028);
	// bl 0x822159d0
	ctx.lr = 0x822174A4;
	sub_822159D0(ctx, base);
	// lis r8,-32219
	ctx.r8.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r8,9768
	ctx.r4.s64 = ctx.r8.s64 + 9768;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x822174C0;
	sub_821C2FB0(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20032(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20032);
	// bl 0x822159d0
	ctx.lr = 0x822174D4;
	sub_822159D0(ctx, base);
	// lis r4,-32219
	ctx.r4.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r4,22944
	ctx.r4.s64 = ctx.r4.s64 + 22944;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x822174F0;
	sub_821C2FB0(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20036(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -20036);
	// bl 0x822159d0
	ctx.lr = 0x82217504;
	sub_822159D0(ctx, base);
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,3728
	ctx.r4.s64 = ctx.r10.s64 + 3728;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2fb0
	ctx.lr = 0x82217520;
	sub_821C2FB0(ctx, base);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20040(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -20040);
	// bl 0x822159d0
	ctx.lr = 0x82217534;
	sub_822159D0(ctx, base);
	// lis r8,-32219
	ctx.r8.s64 = -2111504384;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,13624
	ctx.r4.s64 = ctx.r8.s64 + 13624;
	// bl 0x821c2fb0
	ctx.lr = 0x82217550;
	sub_821C2FB0(ctx, base);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20044(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + -20044);
	// bl 0x822159d0
	ctx.lr = 0x82217564;
	sub_822159D0(ctx, base);
	// lis r6,-32219
	ctx.r6.s64 = -2111504384;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r6,13240
	ctx.r4.s64 = ctx.r6.s64 + 13240;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c2f90
	ctx.lr = 0x82217578;
	sub_821C2F90(ctx, base);
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20048(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + -20048);
	// bl 0x822159d0
	ctx.lr = 0x8221758C;
	sub_822159D0(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// bl 0x821c2fd8
	ctx.lr = 0x8221759C;
	sub_821C2FD8(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-20052(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -20052);
	// bl 0x822159d0
	ctx.lr = 0x822175B0;
	sub_822159D0(ctx, base);
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

PPC_WEAK_FUNC(sub_82216880) {
	__imp__sub_82216880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822175C8) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x825f21e8
	sub_825F21E8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822175C8) {
	__imp__sub_822175C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822175D0) {
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
	// bl 0x825f21e8
	ctx.lr = 0x822175EC;
	sub_825F21E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x825f2770
	ctx.lr = 0x822175F8;
	sub_825F2770(ctx, base);
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
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822175D0) {
	__imp__sub_822175D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217618) {
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
	ctx.lr = 0x82217620;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,-3348
	ctx.r4.s64 = ctx.r10.s64 + -3348;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x82217644;
	sub_821CA540(ctx, base);
	// lhz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r8,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// bl 0x825f23c0
	ctx.lr = 0x82217670;
	sub_825F23C0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82217678;
	sub_821C9A90(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82217618) {
	__imp__sub_82217618(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217680) {
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
	ctx.lr = 0x82217688;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// bl 0x823dc018
	ctx.lr = 0x822176AC;
	sub_823DC018(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
loc_822176B0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822176b0
	if (!cr6.eq) goto loc_822176B0;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// bge cr6,0x822176dc
	if (!cr6.lt) goto loc_822176DC;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_822176DC:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bge cr6,0x822176ec
	if (!cr6.lt) goto loc_822176EC;
	// li r9,0
	ctx.r9.s64 = 0;
	// b 0x8221771c
	goto loc_8221771C;
loc_822176EC:
	// cmpwi cr6,r11,7
	cr6.compare<int32_t>(r11.s32, 7, xer);
	// bge cr6,0x822176fc
	if (!cr6.lt) goto loc_822176FC;
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x8221771c
	goto loc_8221771C;
loc_822176FC:
	// cmpwi cr6,r11,10
	cr6.compare<int32_t>(r11.s32, 10, xer);
	// bge cr6,0x8221770c
	if (!cr6.lt) goto loc_8221770C;
	// li r9,2
	ctx.r9.s64 = 2;
	// b 0x8221771c
	goto loc_8221771C;
loc_8221770C:
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// li r9,3
	ctx.r9.s64 = 3;
	// blt cr6,0x8221771c
	if (cr6.lt) goto loc_8221771C;
	// li r9,4
	ctx.r9.s64 = 4;
loc_8221771C:
	// add r11,r8,r9
	r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// stbx r10,r11,r31
	PPC_STORE_U8(r11.u32 + r31.u32, ctx.r10.u8);
	// ble cr6,0x8221776c
	if (!cr6.gt) goto loc_8221776C;
	// add r11,r8,r31
	r11.u64 = ctx.r8.u64 + r31.u64;
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
loc_82217738:
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lbz r7,1(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 1);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// addi r8,r8,-3
	ctx.r8.s64 = ctx.r8.s64 + -3;
	// stb r7,-1(r10)
	PPC_STORE_U8(ctx.r10.u32 + -1, ctx.r7.u8);
	// lbz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// stb r6,-2(r10)
	PPC_STORE_U8(ctx.r10.u32 + -2, ctx.r6.u8);
	// lbz r5,-1(r11)
	ctx.r5.u64 = PPC_LOAD_U8(r11.u32 + -1);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// stb r5,-3(r10)
	PPC_STORE_U8(ctx.r10.u32 + -3, ctx.r5.u8);
	// stb r29,-4(r10)
	PPC_STORE_U8(ctx.r10.u32 + -4, r29.u8);
	// bgt 0x82217738
	if (cr0.gt) goto loc_82217738;
loc_8221776C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82217680) {
	__imp__sub_82217680(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82217774) {
	__imp__sub_82217774(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217778) {
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
	ctx.lr = 0x82217780;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r10,-3316
	ctx.r4.s64 = ctx.r10.s64 + -3316;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x822177A4;
	sub_821CA540(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r6,r9,-3332
	ctx.r6.s64 = ctx.r9.s64 + -3332;
	// addi r5,r8,-3340
	ctx.r5.s64 = ctx.r8.s64 + -3340;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r4,63
	ctx.r4.s64 = 63;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x822177C4;
	sub_82137A08(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r7,-3348
	ctx.r4.s64 = ctx.r7.s64 + -3348;
	// bl 0x821ca540
	ctx.lr = 0x822177D4;
	sub_821CA540(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// extsh r6,r11
	ctx.r6.s64 = r11.s16;
	// bl 0x825f23c0
	ctx.lr = 0x82217804;
	sub_825F23C0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8221780C;
	sub_821C9A90(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82217814;
	sub_821C9A90(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82217778) {
	__imp__sub_82217778(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221781C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221781C) {
	__imp__sub_8221781C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217820) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82217828;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bgt cr6,0x82217a0c
	if (cr6.gt) goto loc_82217A0C;
	// lis r12,-32223
	r12.s64 = -2111766528;
	// addi r12,r12,30812
	r12.s64 = r12.s64 + 30812;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,30832(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 30832);
	// lwz r17,31016(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 31016);
	// lwz r17,31152(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 31152);
	// lwz r17,30924(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 30924);
	// lwz r17,31016(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 31016);
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82217680
	ctx.lr = 0x8221787C;
	sub_82217680(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82217a24
	if (!cr6.eq) goto loc_82217A24;
	// addic. r10,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r10.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// ble 0x82217a80
	if (!cr0.gt) goto loc_82217A80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// subf r8,r29,r9
	ctx.r8.s64 = ctx.r9.s64 - r29.s64;
loc_8221789C:
	// lbzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82217a80
	if (cr6.eq) goto loc_82217A80;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x8221789c
	if (cr0.gt) goto loc_8221789C;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
	// li r5,46
	ctx.r5.s64 = 46;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82217680
	ctx.lr = 0x822178D8;
	sub_82217680(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82217a24
	if (!cr6.eq) goto loc_82217A24;
	// addic. r10,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r10.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// ble 0x82217a80
	if (!cr0.gt) goto loc_82217A80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// subf r8,r29,r9
	ctx.r8.s64 = ctx.r9.s64 - r29.s64;
loc_822178F8:
	// lbzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82217a80
	if (cr6.eq) goto loc_82217A80;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x822178f8
	if (cr0.gt) goto loc_822178F8;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
	// li r5,46
	ctx.r5.s64 = 46;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82217680
	ctx.lr = 0x82217934;
	sub_82217680(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221796c
	if (cr6.eq) goto loc_8221796C;
loc_82217940:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r7,r11,-3312
	ctx.r7.s64 = r11.s64 + -3312;
	// addi r5,r10,10372
	ctx.r5.s64 = ctx.r10.s64 + 10372;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x82217960;
	sub_82137A08(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_8221796C:
	// addic. r10,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r10.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// ble 0x82217a80
	if (!cr0.gt) goto loc_82217A80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// subf r8,r29,r9
	ctx.r8.s64 = ctx.r9.s64 - r29.s64;
loc_82217980:
	// lbzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82217a80
	if (cr6.eq) goto loc_82217A80;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x82217980
	if (cr0.gt) goto loc_82217980;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
	// li r5,124
	ctx.r5.s64 = 124;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82217680
	ctx.lr = 0x822179BC;
	sub_82217680(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82217940
	if (!cr6.eq) goto loc_82217940;
	// addic. r10,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r10.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// ble 0x82217a80
	if (!cr0.gt) goto loc_82217A80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// subf r8,r29,r9
	ctx.r8.s64 = ctx.r9.s64 - r29.s64;
loc_822179DC:
	// lbzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82217a80
	if (cr6.eq) goto loc_82217A80;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x822179dc
	if (cr0.gt) goto loc_822179DC;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82217A0C:
	// li r5,44
	ctx.r5.s64 = 44;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82217680
	ctx.lr = 0x82217A18;
	sub_82217680(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82217a50
	if (cr6.eq) goto loc_82217A50;
loc_82217A24:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r6,r11,-3312
	ctx.r6.s64 = r11.s64 + -3312;
	// addi r5,r10,10372
	ctx.r5.s64 = ctx.r10.s64 + 10372;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x82217A44;
	sub_82137A08(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
loc_82217A50:
	// addic. r10,r31,-1
	xer.ca = r31.u32 > 0;
	ctx.r10.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// ble 0x82217a80
	if (!cr0.gt) goto loc_82217A80;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// subf r8,r29,r9
	ctx.r8.s64 = ctx.r9.s64 - r29.s64;
loc_82217A64:
	// lbzx r9,r8,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82217a80
	if (cr6.eq) goto loc_82217A80;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x82217a64
	if (cr0.gt) goto loc_82217A64;
loc_82217A80:
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82217820) {
	__imp__sub_82217820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82217A94) {
	__imp__sub_82217A94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217A98) {
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
	ctx.lr = 0x82217AA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,11(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 11);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82217b68
	if (cr6.eq) goto loc_82217B68;
	// rlwinm r3,r28,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0x3FFFC;
	// clrlwi r31,r28,16
	r31.u64 = r28.u32 & 0xFFFF;
	// bl 0x82130528
	ctx.lr = 0x82217AC4;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82217ae8
	if (cr6.eq) goto loc_82217AE8;
	// mr r11,r30
	r11.u64 = r30.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mtctr r31
	ctr.u64 = r31.u64;
loc_82217ADC:
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82217adc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82217ADC;
loc_82217AE8:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82217b58
	if (cr6.eq) goto loc_82217B58;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82217AFC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r11,r8,r11
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82217b44
	if (cr6.eq) goto loc_82217B44;
loc_82217B0C:
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// twllei r31,0
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// divwu r4,r5,r31
	ctx.r4.u32 = ctx.r5.u32 / r31.u32;
	// mullw r3,r4,r31
	ctx.r3.s64 = int64_t(ctx.r4.s32) * int64_t(r31.s32);
	// subf r10,r3,r5
	ctx.r10.s64 = ctx.r5.s64 - ctx.r3.s64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r10,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// stw r5,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stwx r6,r10,r30
	PPC_STORE_U32(ctx.r10.u32 + r30.u32, ctx.r6.u32);
	// bne cr6,0x82217b0c
	if (!cr6.eq) goto loc_82217B0C;
loc_82217B44:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r7,r11
	cr6.compare<uint32_t>(ctx.r7.u32, r11.u32, xer);
	// blt cr6,0x82217afc
	if (cr6.lt) goto loc_82217AFC;
loc_82217B58:
	// sth r28,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r28.u16);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82217B64;
	sub_82130588(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_82217B68:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82217A98) {
	__imp__sub_82217A98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217B70) {
	PPC_FUNC_PROLOGUE();
	// b 0x82217820
	sub_82217820(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82217B70) {
	__imp__sub_82217B70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82217B74) {
	__imp__sub_82217B74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217B78) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// addi r10,r11,-3304
	ctx.r10.s64 = r11.s64 + -3304;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82246010
	ctx.lr = 0x82217BA0;
	sub_82246010(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r9,255
	ctx.r9.s64 = 255;
	// sth r11,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r11.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r11.u16);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// stb r11,27(r31)
	PPC_STORE_U8(r31.u32 + 27, r11.u8);
	// sth r11,50(r31)
	PPC_STORE_U16(r31.u32 + 50, r11.u16);
	// sth r11,48(r31)
	PPC_STORE_U16(r31.u32 + 48, r11.u16);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// stb r11,55(r31)
	PPC_STORE_U8(r31.u32 + 55, r11.u8);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// sth r9,32(r31)
	PPC_STORE_U16(r31.u32 + 32, ctx.r9.u16);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
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

PPC_WEAK_FUNC(sub_82217B78) {
	__imp__sub_82217B78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217BEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82217BEC) {
	__imp__sub_82217BEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217BF0) {
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
	ctx.lr = 0x82217BF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// addi r28,r3,16
	r28.s64 = ctx.r3.s64 + 16;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82237920
	ctx.lr = 0x82217C18;
	sub_82237920(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82237920
	ctx.lr = 0x82217C20;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82217c8c
	if (cr6.eq) goto loc_82217C8C;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82217C34:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82217c8c
	if (cr6.eq) goto loc_82217C8C;
loc_82217C3C:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82217C44;
	sub_82130588(ctx, base);
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82217c3c
	if (!cr6.eq) goto loc_82217C3C;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_82217C5C:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82217c84
	if (!cr6.lt) goto loc_82217C84;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r30,r8,r11
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82217c5c
	if (cr6.eq) goto loc_82217C5C;
	// b 0x82217c34
	goto loc_82217C34;
loc_82217C84:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82217c3c
	if (!cr6.eq) goto loc_82217C3C;
loc_82217C8C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82608de8
	ctx.lr = 0x82217C94;
	sub_82608DE8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82217BF0) {
	__imp__sub_82217BF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82217C9C) {
	__imp__sub_82217C9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217CA0) {
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
	ctx.lr = 0x82217CA8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// stw r28,300(r1)
	PPC_STORE_U32(ctx.r1.u32 + 300, r28.u32);
	// addi r4,r1,300
	ctx.r4.s64 = ctx.r1.s64 + 300;
	// addi r3,r29,44
	ctx.r3.s64 = r29.s64 + 44;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x826bddb0
	ctx.lr = 0x82217CC8;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82217d00
	if (cr6.eq) goto loc_82217D00;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// li r10,127
	ctx.r10.s64 = 127;
loc_82217CDC:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82217d64
	if (cr6.eq) goto loc_82217D64;
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bgt 0x82217cdc
	if (cr0.gt) goto loc_82217CDC;
	// b 0x82217d64
	goto loc_82217D64;
loc_82217D00:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// li r9,127
	ctx.r9.s64 = 127;
	// beq cr6,0x82217d38
	if (cr6.eq) goto loc_82217D38;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// subf r8,r10,r31
	ctx.r8.s64 = r31.s64 - ctx.r10.s64;
loc_82217D18:
	// lbzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82217d64
	if (cr6.eq) goto loc_82217D64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x82217d18
	if (cr0.gt) goto loc_82217D18;
	// b 0x82217d64
	goto loc_82217D64;
loc_82217D38:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r8,r11,-3292
	ctx.r8.s64 = r11.s64 + -3292;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// subf r8,r10,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r10.s64;
loc_82217D48:
	// lbzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82217d64
	if (cr6.eq) goto loc_82217D64;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x82217d48
	if (cr0.gt) goto loc_82217D48;
loc_82217D64:
	// li r30,0
	r30.s64 = 0;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// addi r31,r29,16
	r31.s64 = r29.s64 + 16;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826bddb0
	ctx.lr = 0x82217D80;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82217d94
	if (cr6.eq) goto loc_82217D94;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82217e10
	if (!cr6.eq) goto loc_82217E10;
loc_82217D94:
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x82130528
	ctx.lr = 0x82217D9C;
	sub_82130528(ctx, base);
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r11,r11,132
	r11.s64 = r11.s64 + 132;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,36(r29)
	PPC_STORE_U32(r29.u32 + 36, r11.u32);
	// addi r4,r1,300
	ctx.r4.s64 = ctx.r1.s64 + 300;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82389998
	ctx.lr = 0x82217DC0;
	sub_82389998(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r9,r10,-7088
	ctx.r9.s64 = ctx.r10.s64 + -7088;
	// li r4,132
	ctx.r4.s64 = 132;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82217df8
	if (cr6.eq) goto loc_82217DF8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// bl 0x82137a08
	ctx.lr = 0x82217DEC;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_82217DF8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r11,-3300
	ctx.r5.s64 = r11.s64 + -3300;
	// bl 0x82137a08
	ctx.lr = 0x82217E04;
	sub_82137A08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_82217E10:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r9,127
	ctx.r9.s64 = 127;
	// subf r8,r3,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r3.s64;
loc_82217E20:
	// lbzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82217e3c
	if (cr6.eq) goto loc_82217E3C;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x82217e20
	if (cr0.gt) goto loc_82217E20;
loc_82217E3C:
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82217CA0) {
	__imp__sub_82217CA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217E48) {
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
	ctx.lr = 0x82217E50;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82217bf0
	ctx.lr = 0x82217E5C;
	sub_82217BF0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// addi r28,r31,44
	r28.s64 = r31.s64 + 44;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x82237920
	ctx.lr = 0x82217E78;
	sub_82237920(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82237920
	ctx.lr = 0x82217E80;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82217eec
	if (cr6.eq) goto loc_82217EEC;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_82217E94:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82217eec
	if (cr6.eq) goto loc_82217EEC;
loc_82217E9C:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82130588
	ctx.lr = 0x82217EA4;
	sub_82130588(ctx, base);
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82217e9c
	if (!cr6.eq) goto loc_82217E9C;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_82217EBC:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82217ee4
	if (!cr6.lt) goto loc_82217EE4;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r30,r8,r11
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82217ebc
	if (cr6.eq) goto loc_82217EBC;
	// b 0x82217e94
	goto loc_82217E94;
loc_82217EE4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82217e9c
	if (!cr6.eq) goto loc_82217E9C;
loc_82217EEC:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82608de8
	ctx.lr = 0x82217EF4;
	sub_82608DE8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82217E48) {
	__imp__sub_82217E48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82217EFC) {
	__imp__sub_82217EFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82217F00) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82217F08;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r3,r23,4
	ctx.r3.s64 = r23.s64 + 4;
	// bl 0x825f2770
	ctx.lr = 0x82217F1C;
	sub_825F2770(ctx, base);
	// li r22,0
	r22.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r29,r22
	r29.u64 = r22.u64;
	// mr r24,r22
	r24.u64 = r22.u64;
	// beq cr6,0x82218054
	if (cr6.eq) goto loc_82218054;
	// lwz r28,8(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82217F38:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82217f38
	if (!cr6.eq) goto loc_82217F38;
	// subf r11,r28,r11
	r11.s64 = r11.s64 - r28.s64;
	// mr r31,r22
	r31.u64 = r22.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r27,r11,0
	r27.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x8221803c
	if (!cr6.gt) goto loc_8221803C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r28
	r30.u64 = r28.u64;
	// addi r26,r10,-3260
	r26.s64 = ctx.r10.s64 + -3260;
	// addi r25,r11,-3352
	r25.s64 = r11.s64 + -3352;
loc_82217F74:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dd800
	ctx.lr = 0x82217F84;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82217f9c
	if (!cr6.eq) goto loc_82217F9C;
	// addi r31,r31,3
	r31.s64 = r31.s64 + 3;
	// addi r30,r30,3
	r30.s64 = r30.s64 + 3;
	// mr r29,r31
	r29.u64 = r31.u64;
	// b 0x8221802c
	goto loc_8221802C;
loc_82217F9C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dd800
	ctx.lr = 0x82217FAC;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82218028
	if (!cr6.eq) goto loc_82218028;
	// subf r7,r29,r31
	ctx.r7.s64 = r31.s64 - r29.s64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x82217ff0
	if (!cr6.gt) goto loc_82217FF0;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// subf r10,r10,r28
	ctx.r10.s64 = r28.s64 - ctx.r10.s64;
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + r29.u64;
loc_82217FD4:
	// lbzx r10,r8,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r8.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82217ff0
	if (cr6.eq) goto loc_82217FF0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x82217fd4
	if (cr0.gt) goto loc_82217FD4;
loc_82217FF0:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stb r22,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r22.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stbx r22,r7,r10
	PPC_STORE_U8(ctx.r7.u32 + ctx.r10.u32, r22.u8);
	// bl 0x823dd7f0
	ctx.lr = 0x82218004;
	sub_823DD7F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bne cr6,0x82218048
	if (!cr6.eq) goto loc_82218048;
	// bl 0x825f21e8
	ctx.lr = 0x82218014;
	sub_825F21E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82217f00
	ctx.lr = 0x82218020;
	sub_82217F00(ctx, base);
	// add r24,r3,r24
	r24.u64 = ctx.r3.u64 + r24.u64;
	// b 0x8221802c
	goto loc_8221802C;
loc_82218028:
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
loc_8221802C:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r27
	cr6.compare<int32_t>(r31.s32, r27.s32, xer);
	// blt cr6,0x82217f74
	if (cr6.lt) goto loc_82217F74;
loc_8221803C:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9230
	return;
loc_82218048:
	// bl 0x823dd7f0
	ctx.lr = 0x8221804C;
	sub_823DD7F0(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9230
	return;
loc_82218054:
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r23,16
	ctx.r3.s64 = r23.s64 + 16;
	// bl 0x826bddb0
	ctx.lr = 0x82218064;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82218078
	if (cr6.eq) goto loc_82218078;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82218088
	if (!cr6.eq) goto loc_82218088;
loc_82218078:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82217ca0
	ctx.lr = 0x82218088;
	sub_82217CA0(ctx, base);
loc_82218088:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8221808C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8221808c
	if (!cr6.eq) goto loc_8221808C;
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82217F00) {
	__imp__sub_82217F00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822180B0) {
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
	ctx.lr = 0x822180B8;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// addi r3,r26,4
	ctx.r3.s64 = r26.s64 + 4;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r21,r6
	r21.u64 = ctx.r6.u64;
	// mr r25,r22
	r25.u64 = r22.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
	// mr r31,r22
	r31.u64 = r22.u64;
	// bl 0x825f2770
	ctx.lr = 0x822180E0;
	sub_825F2770(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82218260
	if (cr6.eq) goto loc_82218260;
	// lwz r23,8(r3)
	r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r11,r23
	r11.u64 = r23.u64;
loc_822180F0:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822180f0
	if (!cr6.eq) goto loc_822180F0;
	// subf r11,r23,r11
	r11.s64 = r11.s64 - r23.s64;
	// mr r29,r22
	r29.u64 = r22.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r20,r11,0
	r20.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// ble cr6,0x8221825c
	if (!cr6.gt) goto loc_8221825C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r28,r23
	r28.u64 = r23.u64;
	// addi r19,r10,-3260
	r19.s64 = ctx.r10.s64 + -3260;
	// addi r18,r11,-3352
	r18.s64 = r11.s64 + -3352;
loc_8221812C:
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823dd800
	ctx.lr = 0x8221813C;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82218158
	if (!cr6.eq) goto loc_82218158;
	// addi r29,r29,3
	r29.s64 = r29.s64 + 3;
	// addi r28,r28,3
	r28.s64 = r28.s64 + 3;
	// mr r25,r29
	r25.u64 = r29.u64;
	// li r31,1
	r31.s64 = 1;
	// b 0x8221824c
	goto loc_8221824C;
loc_82218158:
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823dd800
	ctx.lr = 0x82218168;
	sub_823DD800(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82218234
	if (!cr6.eq) goto loc_82218234;
	// subf r31,r25,r29
	r31.s64 = r29.s64 - r25.s64;
	// add r4,r23,r25
	ctx.r4.u64 = r23.u64 + r25.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823db670
	ctx.lr = 0x82218184;
	sub_823DB670(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stbx r22,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, r22.u8);
	// bl 0x823dd7f0
	ctx.lr = 0x82218194;
	sub_823DD7F0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82218260
	if (!cr6.eq) goto loc_82218260;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825f21e8
	ctx.lr = 0x822181A4;
	sub_825F21E8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82218268
	ctx.lr = 0x822181B8;
	sub_82218268(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82217f00
	ctx.lr = 0x822181C8;
	sub_82217F00(ctx, base);
	// subf r11,r27,r21
	r11.s64 = r21.s64 - r27.s64;
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x822181d8
	if (cr6.lt) goto loc_822181D8;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822181D8:
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r3,r27,r24
	ctx.r3.u64 = r27.u64 + r24.u64;
	// bl 0x823db670
	ctx.lr = 0x822181E8;
	sub_823DB670(ctx, base);
	// mr r11,r31
	r11.u64 = r31.u64;
loc_822181EC:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822181ec
	if (!cr6.eq) goto loc_822181EC;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// rotlwi r31,r11,0
	r31.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x82217f00
	ctx.lr = 0x82218214;
	sub_82217F00(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// bge cr6,0x82218220
	if (!cr6.lt) goto loc_82218220;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82218220:
	// add r27,r3,r27
	r27.u64 = ctx.r3.u64 + r27.u64;
	// mr r31,r22
	r31.u64 = r22.u64;
	// addi r29,r29,3
	r29.s64 = r29.s64 + 3;
	// addi r28,r28,3
	r28.s64 = r28.s64 + 3;
	// b 0x8221824c
	goto loc_8221824C;
loc_82218234:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221824c
	if (!cr6.eq) goto loc_8221824C;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// stbx r11,r27,r24
	PPC_STORE_U8(r27.u32 + r24.u32, r11.u8);
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_8221824C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r29,r20
	cr6.compare<int32_t>(r29.s32, r20.s32, xer);
	// blt cr6,0x8221812c
	if (cr6.lt) goto loc_8221812C;
loc_8221825C:
	// stbx r22,r27,r24
	PPC_STORE_U8(r27.u32 + r24.u32, r22.u8);
loc_82218260:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9220
	return;
}

PPC_WEAK_FUNC(sub_822180B0) {
	__imp__sub_822180B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218268) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x82218270;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x825f2770
	ctx.lr = 0x82218288;
	sub_825F2770(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x826bddb0
	ctx.lr = 0x8221829C;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822182b0
	if (cr6.eq) goto loc_822182B0;
	// lwz r29,0(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x822182dc
	if (!cr6.eq) goto loc_822182DC;
loc_822182B0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822182c4
	if (cr6.eq) goto loc_822182C4;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_822182C4:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82217ca0
	ctx.lr = 0x822182D4;
	sub_82217CA0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_822182DC:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82218304
	if (cr6.eq) goto loc_82218304;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82217f00
	ctx.lr = 0x822182F0;
	sub_82217F00(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822180b0
	ctx.lr = 0x82218304;
	sub_822180B0(ctx, base);
loc_82218304:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82218268) {
	__imp__sub_82218268(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218310) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82218388
	if (cr6.eq) goto loc_82218388;
	// mr r11,r31
	r11.u64 = r31.u64;
loc_82218338:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82218338
	if (!cr6.eq) goto loc_82218338;
	// subf r11,r31,r11
	r11.s64 = r11.s64 - r31.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82218388
	if (cr6.eq) goto loc_82218388;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825f21e8
	ctx.lr = 0x82218364;
	sub_825F21E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218268
	ctx.lr = 0x82218374;
	sub_82218268(ctx, base);
	// lbz r11,40(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 40);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82218390
	if (cr6.eq) goto loc_82218390;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x82218390
	goto loc_82218390;
loc_82218388:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-3360
	ctx.r3.s64 = r11.s64 + -3360;
loc_82218390:
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

PPC_WEAK_FUNC(sub_82218310) {
	__imp__sub_82218310(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822183A8) {
	PPC_FUNC_PROLOGUE();
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x82218268
	sub_82218268(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822183A8) {
	__imp__sub_822183A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822183B0) {
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
	ctx.lr = 0x822183B8;
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
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x825f21e8
	ctx.lr = 0x822183D0;
	sub_825F21E8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x826bddb0
	ctx.lr = 0x822183E0;
	sub_826BDDB0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82218440
	if (cr6.eq) goto loc_82218440;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825f21e8
	ctx.lr = 0x822183F4;
	sub_825F21E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82217f00
	ctx.lr = 0x82218400;
	sub_82217F00(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addic. r11,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	r11.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// ble 0x82218430
	if (!cr0.gt) goto loc_82218430;
loc_82218410:
	// lbz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82218430
	if (cr6.eq) goto loc_82218430;
	// stb r8,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// bgt 0x82218410
	if (cr0.gt) goto loc_82218410;
loc_82218430:
	// li r11,0
	r11.s64 = 0;
	// stb r11,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82218440:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-3252
	ctx.r3.s64 = r11.s64 + -3252;
	// bl 0x82130000
	ctx.lr = 0x82218450;
	sub_82130000(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822183B0) {
	__imp__sub_822183B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218458) {
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
	ctx.lr = 0x82218460;
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
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
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x825f21e8
	ctx.lr = 0x8221848C;
	sub_825F21E8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x826bddb0
	ctx.lr = 0x8221849C;
	sub_826BDDB0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822184dc
	if (cr6.eq) goto loc_822184DC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,168
	ctx.r10.s64 = ctx.r1.s64 + 168;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x825f21e8
	ctx.lr = 0x822184BC;
	sub_825F21E8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82217f00
	ctx.lr = 0x822184C8;
	sub_82217F00(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x821c9748
	ctx.lr = 0x822184DC;
	sub_821C9748(ctx, base);
loc_822184DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82218458) {
	__imp__sub_82218458(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822184E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822184E4) {
	__imp__sub_822184E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822184E8) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r3,r11,-3200
	ctx.r3.s64 = r11.s64 + -3200;
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r31.u32);
	// bl 0x825f21e8
	ctx.lr = 0x82218514;
	sub_825F21E8(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x82218588
	if (!cr6.eq) goto loc_82218588;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x825f2770
	ctx.lr = 0x82218528;
	sub_825F2770(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8221857c
	if (cr6.eq) goto loc_8221857C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r11,-3212
	ctx.r10.s64 = r11.s64 + -3212;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_82218540:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218564
	if (cr6.eq) goto loc_82218564;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218540
	if (cr6.eq) goto loc_82218540;
loc_82218564:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8221857c
	if (!cr6.eq) goto loc_8221857C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,11
	ctx.r5.s64 = 11;
	// addi r4,r11,-3224
	ctx.r4.s64 = r11.s64 + -3224;
	// bl 0x823da950
	ctx.lr = 0x8221857C;
	sub_823DA950(ctx, base);
loc_8221857C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82217f00
	ctx.lr = 0x82218588;
	sub_82217F00(ctx, base);
loc_82218588:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82217f00
	ctx.lr = 0x82218594;
	sub_82217F00(ctx, base);
	// addi r31,r3,1
	r31.s64 = ctx.r3.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130528
	ctx.lr = 0x822185A0;
	sub_82130528(ctx, base);
	// lwz r10,36(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// add r10,r10,r31
	ctx.r10.u64 = ctx.r10.u64 + r31.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r10,36(r30)
	PPC_STORE_U32(r30.u32 + 36, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,140
	ctx.r4.s64 = ctx.r1.s64 + 140;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x82389998
	ctx.lr = 0x822185CC;
	sub_82389998(ctx, base);
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

PPC_WEAK_FUNC(sub_822184E8) {
	__imp__sub_822184E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822185E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822185E4) {
	__imp__sub_822185E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822185E8) {
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
	ctx.lr = 0x822185F0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r30,r28,4
	r30.s64 = r28.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825f2d88
	ctx.lr = 0x82218604;
	sub_825F2D88(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// addi r4,r10,-3316
	ctx.r4.s64 = ctx.r10.s64 + -3316;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x8221861C;
	sub_821CA540(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lhz r6,32(r28)
	ctx.r6.u64 = PPC_LOAD_U16(r28.u32 + 32);
	// li r31,1
	r31.s64 = 1;
	// addi r4,r9,-3332
	ctx.r4.s64 = ctx.r9.s64 + -3332;
	// lwz r5,28(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// bl 0x825f23c0
	ctx.lr = 0x82218650;
	sub_825F23C0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82218658;
	sub_821C9A90(ctx, base);
loc_82218658:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82217778
	ctx.lr = 0x82218664;
	sub_82217778(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,8
	cr6.compare<int32_t>(r31.s32, 8, xer);
	// ble cr6,0x82218658
	if (!cr6.gt) goto loc_82218658;
	// li r27,0
	r27.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r27,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r27,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r27.u32);
	// bl 0x825f21f8
	ctx.lr = 0x82218688;
	sub_825F21F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221877c
	if (cr6.eq) goto loc_8221877C;
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822186a8
	if (cr6.eq) goto loc_822186A8;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x822186ac
	goto loc_822186AC;
loc_822186A8:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822186AC:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825f2770
	ctx.lr = 0x822186BC;
	sub_825F2770(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r29,r11,-3352
	r29.s64 = r11.s64 + -3352;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823d90b0
	ctx.lr = 0x822186D0;
	sub_823D90B0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822186f4
	if (cr6.eq) goto loc_822186F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822184e8
	ctx.lr = 0x822186F4;
	sub_822184E8(ctx, base);
loc_822186F4:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825f21f0
	ctx.lr = 0x82218700;
	sub_825F21F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221877c
	if (cr6.eq) goto loc_8221877C;
loc_8221870C:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82218720
	if (cr6.eq) goto loc_82218720;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x82218724
	goto loc_82218724;
loc_82218720:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_82218724:
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825f2770
	ctx.lr = 0x82218734;
	sub_825F2770(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x823d90b0
	ctx.lr = 0x82218740;
	sub_823D90B0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82218764
	if (cr6.eq) goto loc_82218764;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822184e8
	ctx.lr = 0x82218764;
	sub_822184E8(ctx, base);
loc_82218764:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825f21f0
	ctx.lr = 0x82218770;
	sub_825F21F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221870c
	if (!cr6.eq) goto loc_8221870C;
loc_8221877C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822185E8) {
	__imp__sub_822185E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82218784) {
	__imp__sub_82218784(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218788) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82217820
	ctx.lr = 0x822187B8;
	sub_82217820(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822183b0
	ctx.lr = 0x822187C8;
	sub_822183B0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
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

PPC_WEAK_FUNC(sub_82218788) {
	__imp__sub_82218788(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822187E0) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,-3304
	ctx.r10.s64 = r11.s64 + -3304;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82217e48
	ctx.lr = 0x82218804;
	sub_82217E48(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x82608de8
	ctx.lr = 0x8221880C;
	sub_82608DE8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82608de8
	ctx.lr = 0x82218814;
	sub_82608DE8(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82130000
	ctx.lr = 0x8221881C;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82218824;
	sub_821D2028(ctx, base);
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

PPC_WEAK_FUNC(sub_822187E0) {
	__imp__sub_822187E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218838) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// bl 0x823dc018
	ctx.lr = 0x82218860;
	sub_823DC018(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82218874;
	sub_822183B0(ctx, base);
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

PPC_WEAK_FUNC(sub_82218838) {
	__imp__sub_82218838(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218888) {
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
	ctx.lr = 0x82218890;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x821c9790
	ctx.lr = 0x822188B8;
	sub_821C9790(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x822188D0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825ed480
	ctx.lr = 0x822188E0;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x822188E4;
	sub_825EF9F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r26,r11,3998
	r26.s64 = r11.s64 + 3998;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82218988
	if (cr6.eq) goto loc_82218988;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82218920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r11,r29
	r11.u64 = r29.u64;
loc_82218924:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82218924
	if (!cr6.eq) goto loc_82218924;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82218958
	if (cr6.eq) goto loc_82218958;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x82218954;
	sub_82218310(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_82218958:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825ef9a8
	ctx.lr = 0x82218964;
	sub_825EF9A8(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82218980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82218988:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x82218994;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x822189A4;
	sub_825EE2D8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82218888) {
	__imp__sub_82218888(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822189AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822189AC) {
	__imp__sub_822189AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822189B0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r4.u32);
	// b 0x822185e8
	sub_822185E8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822189B0) {
	__imp__sub_822189B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822189B8) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-3304
	ctx.r10.s64 = r11.s64 + -3304;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82217e48
	ctx.lr = 0x822189E4;
	sub_82217E48(ctx, base);
	// addi r3,r31,44
	ctx.r3.s64 = r31.s64 + 44;
	// bl 0x82608de8
	ctx.lr = 0x822189EC;
	sub_82608DE8(ctx, base);
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82608de8
	ctx.lr = 0x822189F4;
	sub_82608DE8(ctx, base);
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x82130000
	ctx.lr = 0x822189FC;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82218A04;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82218a1c
	if (cr6.eq) goto loc_82218A1C;
	// bl 0x82130588
	ctx.lr = 0x82218A18;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82218A1C:
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

PPC_WEAK_FUNC(sub_822189B8) {
	__imp__sub_822189B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218A34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82218A34) {
	__imp__sub_82218A34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218A38) {
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
	ctx.lr = 0x82218A40;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// bl 0x825f2188
	ctx.lr = 0x82218A54;
	sub_825F2188(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-7068
	ctx.r10.s64 = r11.s64 + -7068;
	// li r9,255
	ctx.r9.s64 = 255;
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// sth r9,32(r31)
	PPC_STORE_U16(r31.u32 + 32, ctx.r9.u16);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82218a88
	if (cr6.eq) goto loc_82218A88;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// li r11,1
	r11.s64 = 1;
	// b 0x82218a8c
	goto loc_82218A8C;
loc_82218A88:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82218A8C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// addi r5,r10,-7112
	ctx.r5.s64 = ctx.r10.s64 + -7112;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,-7112(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7112, r11.u32);
	// beq cr6,0x82218ab0
	if (cr6.eq) goto loc_82218AB0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,32684
	ctx.r4.s64 = r11.s64 + 32684;
	// bl 0x823ddb08
	ctx.lr = 0x82218AB0;
	sub_823DDB08(ctx, base);
loc_82218AB0:
	// lis r10,-32127
	ctx.r10.s64 = -2105475072;
	// stb r30,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r30.u8);
	// li r11,4
	r11.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,14316(r10)
	PPC_STORE_U32(ctx.r10.u32 + 14316, r11.u32);
	// lhz r8,32(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// ori r7,r8,39
	ctx.r7.u64 = ctx.r8.u64 | 39;
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// sth r7,32(r31)
	PPC_STORE_U16(r31.u32 + 32, ctx.r7.u16);
	// bl 0x822185e8
	ctx.lr = 0x82218AD8;
	sub_822185E8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82218A38) {
	__imp__sub_82218A38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218AE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x822183b0
	sub_822183B0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82218AE0) {
	__imp__sub_82218AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218AF8) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,32684
	ctx.r4.s64 = ctx.r10.s64 + 32684;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x823dc018
	ctx.lr = 0x82218B24;
	sub_823DC018(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82218B38;
	sub_822183B0(ctx, base);
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

PPC_WEAK_FUNC(sub_82218AF8) {
	__imp__sub_82218AF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82218B4C) {
	__imp__sub_82218B4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218B50) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x82218310
	ctx.lr = 0x82218B78;
	sub_82218310(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r3.u32);
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

PPC_WEAK_FUNC(sub_82218B50) {
	__imp__sub_82218B50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218B94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82218B94) {
	__imp__sub_82218B94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218B98) {
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
	// lis r11,-32222
	r11.s64 = -2111700992;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r11,-29984
	ctx.r4.s64 = r11.s64 + -29984;
	// addi r3,r10,-3136
	ctx.r3.s64 = ctx.r10.s64 + -3136;
	// bl 0x82554798
	ctx.lr = 0x82218BB8;
	sub_82554798(ctx, base);
	// lis r9,-32222
	ctx.r9.s64 = -2111700992;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r4,r9,-29960
	ctx.r4.s64 = ctx.r9.s64 + -29960;
	// addi r3,r8,-3156
	ctx.r3.s64 = ctx.r8.s64 + -3156;
	// bl 0x82554798
	ctx.lr = 0x82218BCC;
	sub_82554798(ctx, base);
	// lis r7,-32222
	ctx.r7.s64 = -2111700992;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r7,-29872
	ctx.r4.s64 = ctx.r7.s64 + -29872;
	// addi r3,r6,-3180
	ctx.r3.s64 = ctx.r6.s64 + -3180;
	// bl 0x82554798
	ctx.lr = 0x82218BE0;
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

PPC_WEAK_FUNC(sub_82218B98) {
	__imp__sub_82218B98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218BF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v59{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lbz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r11,r4,16
	r11.s64 = ctx.r4.s64 + 16;
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r8,48
	ctx.r8.s64 = 48;
	// stb r9,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r9.u8);
	// li r9,80
	ctx.r9.s64 = 80;
	// lbz r5,1(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// stb r5,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r5.u8);
	// lbz r5,2(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// stb r5,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, ctx.r5.u8);
	// lbz r5,3(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// stb r5,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, ctx.r5.u8);
	// lbz r5,4(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// stb r5,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r5.u8);
	// lbz r5,5(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 5);
	// stb r5,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, ctx.r5.u8);
	// lbz r5,6(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 6);
	// stb r5,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r5.u8);
	// lbz r5,7(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 7);
	// stb r5,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, ctx.r5.u8);
	// lbz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// stb r5,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r5.u8);
	// lbz r5,9(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// stb r5,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r5.u8);
	// lbz r5,10(r4)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// stb r5,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r5.u8);
	// lwz r5,12(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r10,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r4,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r3,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 96);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lwz r11,104(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 104);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// lwz r10,108(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// stw r10,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, ctx.r10.u32);
	// lfs f13,100(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82218BF0) {
	__imp__sub_82218BF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218CB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82218CB4) {
	__imp__sub_82218CB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218CB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// addi r10,r3,16
	ctx.r10.s64 = ctx.r3.s64 + 16;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,48
	ctx.r9.s64 = ctx.r10.s64 + 48;
	// addi r8,r10,32
	ctx.r8.s64 = ctx.r10.s64 + 32;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// li r6,29
	ctx.r6.s64 = 29;
	// stb r11,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, r11.u8);
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// stb r11,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, r11.u8);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stb r11,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r11.u8);
	// li r4,80
	ctx.r4.s64 = 80;
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// stb r11,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, r11.u8);
	// stb r11,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r11.u8);
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// stb r11,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r11.u8);
	// lfs f0,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r11.u8);
	// stb r11,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r11.u8);
	// stw r11,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r11.u32);
	// stw r11,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r11.u32);
	// stw r6,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stvx128 v63,r3,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82218CB8) {
	__imp__sub_82218CB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218D34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82218D34) {
	__imp__sub_82218D34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82218D38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2400
	ctx.r10.s64 = ctx.r10.s64 + -2400;
loc_82218D44:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218d68
	if (cr6.eq) goto loc_82218D68;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218d44
	if (cr6.eq) goto loc_82218D44;
loc_82218D68:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218d78
	if (!cr6.eq) goto loc_82218D78;
	// li r11,0
	r11.s64 = 0;
	// b 0x82219274
	goto loc_82219274;
loc_82218D78:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2428
	ctx.r10.s64 = ctx.r10.s64 + -2428;
loc_82218D84:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218da8
	if (cr6.eq) goto loc_82218DA8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218d84
	if (cr6.eq) goto loc_82218D84;
loc_82218DA8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218db8
	if (!cr6.eq) goto loc_82218DB8;
	// li r11,1
	r11.s64 = 1;
	// b 0x82219274
	goto loc_82219274;
loc_82218DB8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2452
	ctx.r10.s64 = ctx.r10.s64 + -2452;
loc_82218DC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218de8
	if (cr6.eq) goto loc_82218DE8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218dc4
	if (cr6.eq) goto loc_82218DC4;
loc_82218DE8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218df8
	if (!cr6.eq) goto loc_82218DF8;
	// li r11,2
	r11.s64 = 2;
	// b 0x82219274
	goto loc_82219274;
loc_82218DF8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2480
	ctx.r10.s64 = ctx.r10.s64 + -2480;
loc_82218E04:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218e28
	if (cr6.eq) goto loc_82218E28;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218e04
	if (cr6.eq) goto loc_82218E04;
loc_82218E28:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218e38
	if (!cr6.eq) goto loc_82218E38;
	// li r11,3
	r11.s64 = 3;
	// b 0x82219274
	goto loc_82219274;
loc_82218E38:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2500
	ctx.r10.s64 = ctx.r10.s64 + -2500;
loc_82218E44:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218e68
	if (cr6.eq) goto loc_82218E68;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218e44
	if (cr6.eq) goto loc_82218E44;
loc_82218E68:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218e78
	if (!cr6.eq) goto loc_82218E78;
	// li r11,4
	r11.s64 = 4;
	// b 0x82219274
	goto loc_82219274;
loc_82218E78:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2516
	ctx.r10.s64 = ctx.r10.s64 + -2516;
loc_82218E84:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218ea8
	if (cr6.eq) goto loc_82218EA8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218e84
	if (cr6.eq) goto loc_82218E84;
loc_82218EA8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218eb8
	if (!cr6.eq) goto loc_82218EB8;
	// li r11,5
	r11.s64 = 5;
	// b 0x82219274
	goto loc_82219274;
loc_82218EB8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2524
	ctx.r10.s64 = ctx.r10.s64 + -2524;
loc_82218EC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218ee8
	if (cr6.eq) goto loc_82218EE8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218ec4
	if (cr6.eq) goto loc_82218EC4;
loc_82218EE8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218ef8
	if (!cr6.eq) goto loc_82218EF8;
	// li r11,7
	r11.s64 = 7;
	// b 0x82219274
	goto loc_82219274;
loc_82218EF8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2544
	ctx.r10.s64 = ctx.r10.s64 + -2544;
loc_82218F04:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218f28
	if (cr6.eq) goto loc_82218F28;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218f04
	if (cr6.eq) goto loc_82218F04;
loc_82218F28:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218f38
	if (!cr6.eq) goto loc_82218F38;
	// li r11,10
	r11.s64 = 10;
	// b 0x82219274
	goto loc_82219274;
loc_82218F38:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2564
	ctx.r10.s64 = ctx.r10.s64 + -2564;
loc_82218F44:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218f68
	if (cr6.eq) goto loc_82218F68;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218f44
	if (cr6.eq) goto loc_82218F44;
loc_82218F68:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218f78
	if (!cr6.eq) goto loc_82218F78;
	// li r11,11
	r11.s64 = 11;
	// b 0x82219274
	goto loc_82219274;
loc_82218F78:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2584
	ctx.r10.s64 = ctx.r10.s64 + -2584;
loc_82218F84:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218fa8
	if (cr6.eq) goto loc_82218FA8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218f84
	if (cr6.eq) goto loc_82218F84;
loc_82218FA8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218fb8
	if (!cr6.eq) goto loc_82218FB8;
	// li r11,12
	r11.s64 = 12;
	// b 0x82219274
	goto loc_82219274;
loc_82218FB8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2592
	ctx.r10.s64 = ctx.r10.s64 + -2592;
loc_82218FC4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82218fe8
	if (cr6.eq) goto loc_82218FE8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82218fc4
	if (cr6.eq) goto loc_82218FC4;
loc_82218FE8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82218ff8
	if (!cr6.eq) goto loc_82218FF8;
	// li r11,8
	r11.s64 = 8;
	// b 0x82219274
	goto loc_82219274;
loc_82218FF8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2612
	ctx.r10.s64 = ctx.r10.s64 + -2612;
loc_82219004:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82219028
	if (cr6.eq) goto loc_82219028;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82219004
	if (cr6.eq) goto loc_82219004;
loc_82219028:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82219038
	if (!cr6.eq) goto loc_82219038;
	// li r11,13
	r11.s64 = 13;
	// b 0x82219274
	goto loc_82219274;
loc_82219038:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2636
	ctx.r10.s64 = ctx.r10.s64 + -2636;
loc_82219044:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82219068
	if (cr6.eq) goto loc_82219068;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82219044
	if (cr6.eq) goto loc_82219044;
loc_82219068:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82219078
	if (!cr6.eq) goto loc_82219078;
	// li r11,14
	r11.s64 = 14;
	// b 0x82219274
	goto loc_82219274;
loc_82219078:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2648
	ctx.r10.s64 = ctx.r10.s64 + -2648;
loc_82219084:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822190a8
	if (cr6.eq) goto loc_822190A8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82219084
	if (cr6.eq) goto loc_82219084;
loc_822190A8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822190b8
	if (!cr6.eq) goto loc_822190B8;
	// li r11,15
	r11.s64 = 15;
	// b 0x82219274
	goto loc_82219274;
loc_822190B8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2668
	ctx.r10.s64 = ctx.r10.s64 + -2668;
loc_822190C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822190e8
	if (cr6.eq) goto loc_822190E8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822190c4
	if (cr6.eq) goto loc_822190C4;
loc_822190E8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822190f8
	if (!cr6.eq) goto loc_822190F8;
	// li r11,16
	r11.s64 = 16;
	// b 0x82219274
	goto loc_82219274;
loc_822190F8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2696
	ctx.r10.s64 = ctx.r10.s64 + -2696;
loc_82219104:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82219128
	if (cr6.eq) goto loc_82219128;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82219104
	if (cr6.eq) goto loc_82219104;
loc_82219128:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82219138
	if (!cr6.eq) goto loc_82219138;
	// li r11,17
	r11.s64 = 17;
	// b 0x82219274
	goto loc_82219274;
loc_82219138:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2716
	ctx.r10.s64 = ctx.r10.s64 + -2716;
loc_82219144:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82219168
	if (cr6.eq) goto loc_82219168;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82219144
	if (cr6.eq) goto loc_82219144;
loc_82219168:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82219178
	if (!cr6.eq) goto loc_82219178;
	// li r11,18
	r11.s64 = 18;
	// b 0x82219274
	goto loc_82219274;
loc_82219178:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2728
	ctx.r10.s64 = ctx.r10.s64 + -2728;
loc_82219184:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822191a8
	if (cr6.eq) goto loc_822191A8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82219184
	if (cr6.eq) goto loc_82219184;
loc_822191A8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822191b8
	if (!cr6.eq) goto loc_822191B8;
	// li r11,9
	r11.s64 = 9;
	// b 0x82219274
	goto loc_82219274;
loc_822191B8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2736
	ctx.r10.s64 = ctx.r10.s64 + -2736;
loc_822191C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822191e8
	if (cr6.eq) goto loc_822191E8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822191c4
	if (cr6.eq) goto loc_822191C4;
loc_822191E8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822191f8
	if (!cr6.eq) goto loc_822191F8;
	// li r11,23
	r11.s64 = 23;
	// b 0x82219274
	goto loc_82219274;
loc_822191F8:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,-2748
	ctx.r10.s64 = ctx.r10.s64 + -2748;
loc_82219204:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82219228
	if (cr6.eq) goto loc_82219228;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82219204
	if (cr6.eq) goto loc_82219204;
loc_82219228:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82219238
	if (!cr6.eq) goto loc_82219238;
	// li r11,24
	r11.s64 = 24;
	// b 0x82219274
	goto loc_82219274;
loc_82219238:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r10,r10,9864
	ctx.r10.s64 = ctx.r10.s64 + 9864;
loc_82219244:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x82219268
	if (cr6.eq) goto loc_82219268;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82219244
	if (cr6.eq) goto loc_82219244;
loc_82219268:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82219278
	if (!cr6.eq) goto loc_82219278;
	// li r11,25
	r11.s64 = 25;
loc_82219274:
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
loc_82219278:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-2772
	ctx.r3.s64 = r11.s64 + -2772;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82218D38) {
	__imp__sub_82218D38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82219284) {
	__imp__sub_82219284(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219288) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822192A4;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x822192A8;
	sub_822A8108(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82219288) {
	__imp__sub_82219288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822192B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822192cc
	if (cr6.eq) goto loc_822192CC;
	// lbz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// blr 
	return;
loc_822192CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822192B8) {
	__imp__sub_822192B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822192D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822192D4) {
	__imp__sub_822192D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822192D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822192ec
	if (cr6.eq) goto loc_822192EC;
	// lbz r3,10(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// blr 
	return;
loc_822192EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822192D8) {
	__imp__sub_822192D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822192F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822192F4) {
	__imp__sub_822192F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822192F8) {
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
	// bl 0x823d91e4
	ctx.lr = 0x82219300;
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,5
	r11.s64 = 327680;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// ori r31,r11,5088
	r31.u64 = r11.u64 | 5088;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r27,16
	r27.s64 = 16;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// li r28,32
	r28.s64 = 32;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// mr r23,r5
	r23.u64 = ctx.r5.u64;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// add r6,r6,r31
	ctx.r6.u64 = ctx.r6.u64 + r31.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,48
	r29.s64 = 48;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// lfs f31,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f31.f64 = double(temp.f32);
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lvx128 v62,r6,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r6,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lvx128 v60,r6,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,80(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c9c0
	ctx.lr = 0x82219394;
	sub_8216C9C0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r4,r5,r31
	ctx.r4.u64 = ctx.r5.u64 + r31.u64;
	// lvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r4,r27
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r24,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r4,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r24,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r4,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r24,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822193e0
	if (cr6.eq) goto loc_822193E0;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvx128 v55,r26,r29
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r26.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v53,v54,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822193E0:
	// lbz r11,9(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,12(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 12);
	// beq cr6,0x822194fc
	if (cr6.eq) goto loc_822194FC;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x82219404
	if (!cr6.eq) goto loc_82219404;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2068
	ctx.r4.s64 = ctx.r10.s64 + -2068;
	// b 0x82219588
	goto loc_82219588;
loc_82219404:
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// bne cr6,0x82219418
	if (!cr6.eq) goto loc_82219418;
loc_8221940C:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2092
	ctx.r4.s64 = ctx.r10.s64 + -2092;
	// b 0x82219588
	goto loc_82219588;
loc_82219418:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822194a8
	if (cr6.eq) goto loc_822194A8;
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f0,f13,f13,f10
	f0.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f9,f0
	ctx.f9.f64 = double(float(sqrt(f0.f64)));
	// fcmpu cr6,f9,f12
	cr6.compare(ctx.f9.f64, ctx.f12.f64);
	// ble cr6,0x822194a8
	if (!cr6.gt) goto loc_822194A8;
	// fsqrts f13,f0
	ctx.f13.f64 = double(float(sqrt(f0.f64)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822194a8
	if (!cr6.lt) goto loc_822194A8;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r10,-2120
	ctx.r4.s64 = ctx.r10.s64 + -2120;
	// addi r31,r9,-19728
	r31.s64 = ctx.r9.s64 + -19728;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r29,r8,-22108
	r29.s64 = ctx.r8.s64 + -22108;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82219488;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8221949C;
	sub_823DEDD8(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,4(r25)
	PPC_STORE_U8(r25.u32 + 4, ctx.r7.u8);
	// b 0x822195bc
	goto loc_822195BC;
loc_822194A8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-2124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2124);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x822194cc
	if (!cr6.lt) goto loc_822194CC;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x822194cc
	if (!cr6.gt) goto loc_822194CC;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2164
	ctx.r4.s64 = ctx.r10.s64 + -2164;
	// b 0x82219588
	goto loc_82219588;
loc_822194CC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-2168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2168);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822194f0
	if (!cr6.gt) goto loc_822194F0;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x822194f0
	if (!cr6.lt) goto loc_822194F0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2204
	ctx.r4.s64 = ctx.r10.s64 + -2204;
	// b 0x82219588
	goto loc_82219588;
loc_822194F0:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2236
	ctx.r4.s64 = ctx.r10.s64 + -2236;
	// b 0x82219588
	goto loc_82219588;
loc_822194FC:
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x82219510
	if (!cr6.eq) goto loc_82219510;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2256
	ctx.r4.s64 = ctx.r10.s64 + -2256;
	// b 0x82219588
	goto loc_82219588;
loc_82219510:
	// cmpwi cr6,r11,9
	cr6.compare<int32_t>(r11.s32, 9, xer);
	// beq cr6,0x8221940c
	if (cr6.eq) goto loc_8221940C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,56(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-2260(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2260);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82219538
	if (!cr6.lt) goto loc_82219538;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2284
	ctx.r4.s64 = ctx.r10.s64 + -2284;
	// b 0x82219588
	goto loc_82219588;
loc_82219538:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-2124(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2124);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8221955c
	if (!cr6.lt) goto loc_8221955C;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x8221955c
	if (!cr6.gt) goto loc_8221955C;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2316
	ctx.r4.s64 = ctx.r10.s64 + -2316;
	// b 0x82219588
	goto loc_82219588;
loc_8221955C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-2168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2168);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82219580
	if (!cr6.gt) goto loc_82219580;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x82219580
	if (!cr6.lt) goto loc_82219580;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2348
	ctx.r4.s64 = ctx.r10.s64 + -2348;
	// b 0x82219588
	goto loc_82219588;
loc_82219580:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2372
	ctx.r4.s64 = ctx.r10.s64 + -2372;
loc_82219588:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r31,r9,-19728
	r31.s64 = ctx.r9.s64 + -19728;
	// addi r29,r8,-22108
	r29.s64 = ctx.r8.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x822195A8;
	sub_82691650(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x822195BC;
	sub_823DEDD8(ctx, base);
loc_822195BC:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822195D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,632(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 632);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822195EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,636(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 636);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82219604;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r4,5
	ctx.r4.s64 = 327680;
	// ori r11,r5,5152
	r11.u64 = ctx.r5.u64 | 5152;
	// ori r10,r4,5184
	ctx.r10.u64 = ctx.r4.u64 | 5184;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lvx128 v52,r7,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r30,r5,r8
	r30.u64 = ctx.r5.u64 + ctx.r8.u64;
	// lwz r11,736(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 736);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82219650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,744(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 744);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82219668;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

PPC_WEAK_FUNC(sub_822192F8) {
	__imp__sub_822192F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219678) {
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
	ctx.lr = 0x82219680;
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// li r28,48
	r28.s64 = 48;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r27,r11,5
	r27.s64 = r11.s64 + 327680;
	// addi r27,r27,5088
	r27.s64 = r27.s64 + 5088;
	// beq cr6,0x822196f4
	if (cr6.eq) goto loc_822196F4;
	// li r11,16
	r11.s64 = 16;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v62,r5,r28
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lvx128 v61,r5,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r5,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82219730
	goto loc_82219730;
loc_822196F4:
	// addi r11,r29,16
	r11.s64 = r29.s64 + 16;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// lvx128 v58,r11,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r11,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82219730:
	// addi r31,r27,32
	r31.s64 = r27.s64 + 32;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8216c9c0
	ctx.lr = 0x82219740;
	sub_8216C9C0(ctx, base);
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lvx128 v55,r27,r28
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v53,v55,v54
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v53.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v54.f32)));
	// lfs f29,3796(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// stfs f29,84(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fmadds f11,f13,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f0,88(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fsqrts f31,f11
	f31.f64 = double(float(sqrt(ctx.f11.f64)));
	// bl 0x8216c9c0
	ctx.lr = 0x82219790;
	sub_8216C9C0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lbz r8,9(r29)
	ctx.r8.u64 = PPC_LOAD_U8(r29.u32 + 9);
	// lfs f12,52(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lfs f13,-30176(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30176);
	ctx.f13.f64 = double(temp.f32);
	// beq cr6,0x82219940
	if (cr6.eq) goto loc_82219940;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x822197d8
	if (!cr6.gt) goto loc_822197D8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x822197cc
	if (cr6.gt) goto loc_822197CC;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-31392(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31392);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
loc_822197CC:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1716
	ctx.r4.s64 = ctx.r10.s64 + -1716;
	// b 0x82219a64
	goto loc_82219A64;
loc_822197D8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32312);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x8221980c
	if (!cr6.gt) goto loc_8221980C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82219800
	if (cr6.gt) goto loc_82219800;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-31392(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31392);
	f0.f64 = double(temp.f32);
loc_82219800:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1756
	ctx.r4.s64 = ctx.r10.s64 + -1756;
	// b 0x82219a64
	goto loc_82219A64;
loc_8221980C:
	// lbz r11,4(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822198f8
	if (!cr6.eq) goto loc_822198F8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x82219838
	if (!cr6.lt) goto loc_82219838;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31020(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31020);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// blt cr6,0x822198f8
	if (cr6.lt) goto loc_822198F8;
loc_82219838:
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x82219868
	if (!cr6.lt) goto loc_82219868;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lfs f13,-1760(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1760);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	f0.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x82219868
	if (!cr6.lt) goto loc_82219868;
loc_8221985C:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1788
	ctx.r4.s64 = ctx.r10.s64 + -1788;
	// b 0x82219a64
	goto loc_82219A64;
loc_82219868:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82219888
	if (!cr6.gt) goto loc_82219888;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-1792(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1792);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x8221985c
	if (cr6.lt) goto loc_8221985C;
loc_82219888:
	// lfs f0,56(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 56);
	f0.f64 = double(temp.f32);
	// lfs f13,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8221985c
	if (cr6.gt) goto loc_8221985C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// ble cr6,0x822198b4
	if (!cr6.gt) goto loc_822198B4;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1824
	ctx.r4.s64 = ctx.r10.s64 + -1824;
	// b 0x82219a64
	goto loc_82219A64;
loc_822198B4:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r31,r9,-19728
	r31.s64 = ctx.r9.s64 + -19728;
	// addi r29,r8,-22108
	r29.s64 = ctx.r8.s64 + -22108;
	// lfs f0,-31392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31392);
	f0.f64 = double(temp.f32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bge cr6,0x822198ec
	if (!cr6.lt) goto loc_822198EC;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1824
	ctx.r4.s64 = ctx.r10.s64 + -1824;
	// b 0x82219a80
	goto loc_82219A80;
loc_822198EC:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1864
	ctx.r4.s64 = ctx.r10.s64 + -1864;
	// b 0x82219a80
	goto loc_82219A80;
loc_822198F8:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r10,-1884
	ctx.r4.s64 = ctx.r10.s64 + -1884;
	// addi r31,r9,-19728
	r31.s64 = ctx.r9.s64 + -19728;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r28,r8,-22108
	r28.s64 = ctx.r8.s64 + -22108;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82219920;
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
	ctx.lr = 0x82219934;
	sub_823DEDD8(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r7,4(r29)
	PPC_STORE_U8(r29.u32 + 4, ctx.r7.u8);
	// b 0x82219a98
	goto loc_82219A98;
loc_82219940:
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x82219970
	if (!cr6.gt) goto loc_82219970;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82219964
	if (cr6.gt) goto loc_82219964;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-31392(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31392);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
loc_82219964:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1916
	ctx.r4.s64 = ctx.r10.s64 + -1916;
	// b 0x82219a64
	goto loc_82219A64;
loc_82219970:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,32312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32312);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x822199a4
	if (!cr6.gt) goto loc_822199A4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82219998
	if (cr6.gt) goto loc_82219998;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,-31392(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31392);
	f0.f64 = double(temp.f32);
loc_82219998:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1952
	ctx.r4.s64 = ctx.r10.s64 + -1952;
	// b 0x82219a64
	goto loc_82219A64;
loc_822199A4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x822199d0
	if (!cr6.lt) goto loc_822199D0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,31020(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31020);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x822199d0
	if (!cr6.lt) goto loc_822199D0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1884
	ctx.r4.s64 = ctx.r10.s64 + -1884;
	// b 0x82219a64
	goto loc_82219A64;
loc_822199D0:
	// fcmpu cr6,f12,f13
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x822199f4
	if (!cr6.lt) goto loc_822199F4;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,-29232(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lfs f13,-1760(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1760);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	f0.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// blt cr6,0x82219a5c
	if (cr6.lt) goto loc_82219A5C;
loc_822199F4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82219a5c
	if (cr6.gt) goto loc_82219A5C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-1792(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1792);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// blt cr6,0x82219a5c
	if (cr6.lt) goto loc_82219A5C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// fabs f13,f30
	ctx.f13.u64 = f30.u64 & ~0x8000000000000000;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r31,r9,-19728
	r31.s64 = ctx.r9.s64 + -19728;
	// addi r29,r8,-22108
	r29.s64 = ctx.r8.s64 + -22108;
	// lfs f0,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	f0.f64 = double(temp.f32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// ble cr6,0x82219a50
	if (!cr6.gt) goto loc_82219A50;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-1980
	ctx.r4.s64 = ctx.r10.s64 + -1980;
	// b 0x82219a80
	goto loc_82219A80;
loc_82219A50:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2016
	ctx.r4.s64 = ctx.r10.s64 + -2016;
	// b 0x82219a80
	goto loc_82219A80;
loc_82219A5C:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-2044
	ctx.r4.s64 = ctx.r10.s64 + -2044;
loc_82219A64:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r31,r9,-19728
	r31.s64 = ctx.r9.s64 + -19728;
	// addi r29,r8,-22108
	r29.s64 = ctx.r8.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
loc_82219A80:
	// bl 0x82691650
	ctx.lr = 0x82219A84;
	sub_82691650(ctx, base);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82219A98;
	sub_823DEDD8(ctx, base);
loc_82219A98:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82219AB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,632(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 632);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82219AC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,636(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 636);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82219AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,736(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 736);
	// addis r30,r5,5
	r30.s64 = ctx.r5.s64 + 327680;
	// addi r30,r30,5152
	r30.s64 = r30.s64 + 5152;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stfs f29,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82219B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,744(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 744);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82219B24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

PPC_WEAK_FUNC(sub_82219678) {
	__imp__sub_82219678(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219B3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82219B3C) {
	__imp__sub_82219B3C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219B40) {
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
	ctx.lr = 0x82219B48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// addi r4,r10,-1676
	ctx.r4.s64 = ctx.r10.s64 + -1676;
	// addi r30,r9,-19700
	r30.s64 = ctx.r9.s64 + -19700;
	// addi r29,r8,-22108
	r29.s64 = ctx.r8.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82219B7C;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82219B90;
	sub_823DEDD8(ctx, base);
	// stw r3,292(r31)
	PPC_STORE_U32(r31.u32 + 292, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82219B40) {
	__imp__sub_82219B40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82219B9C) {
	__imp__sub_82219B9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219BA0) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82219BA8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,5
	r11.s64 = 327680;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// ori r11,r11,5152
	r11.u64 = r11.u64 | 5152;
	// lis r10,5
	ctx.r10.s64 = 327680;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// ori r7,r10,5184
	ctx.r7.u64 = ctx.r10.u64 | 5184;
	// mr r31,r6
	r31.u64 = ctx.r6.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// addi r4,r30,192
	ctx.r4.s64 = r30.s64 + 192;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r5,272(r30)
	PPC_STORE_U8(r30.u32 + 272, ctx.r5.u8);
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r8,648(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 648);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82219C2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r5,632(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 632);
	// addis r4,r6,5
	ctx.r4.s64 = ctx.r6.s64 + 327680;
	// addi r4,r4,5088
	ctx.r4.s64 = ctx.r4.s64 + 5088;
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82219C50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,636(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 636);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82219C68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,736(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 736);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82219C80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,744(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 744);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82219C98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82219CA8;
	sub_82220980(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204468
	ctx.lr = 0x82219CB4;
	sub_82204468(ctx, base);
	// lwz r5,68(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// stw r31,108(r5)
	PPC_STORE_U32(ctx.r5.u32 + 108, r31.u32);
	// beq cr6,0x82219d90
	if (cr6.eq) goto loc_82219D90;
	// lwz r3,292(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 292);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// ori r9,r10,5168
	ctx.r9.u64 = ctx.r10.u64 | 5168;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r6,804(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 804);
	// lfsx f1,r7,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82219CEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,292(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 292);
	// addi r4,r30,284
	ctx.r4.s64 = r30.s64 + 284;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,800(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 800);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82219D04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,292(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 292);
	// lfs f1,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,812(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 812);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82219D1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,292(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 292);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,580(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 580);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82219D34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,292(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 292);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,628(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 628);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82219D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,292(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 292);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,592(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 592);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82219D64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r3,292(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 292);
	// lwz r8,576(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 576);
	// lfs f0,-32032(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -32032);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82219D80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r4,292(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 292);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82219D90;
	sub_82220980(ctx, base);
loc_82219D90:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82219BA0) {
	__imp__sub_82219BA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82219D9C) {
	__imp__sub_82219D9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219DA0) {
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
	ctx.lr = 0x82219DA8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r28,1
	r28.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r30,r31,192
	r30.s64 = r31.s64 + 192;
	// lwz r11,-10220(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// stb r28,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, r28.u8);
	// lwz r25,68(r31)
	r25.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82219678
	ctx.lr = 0x82219DE4;
	sub_82219678(ctx, base);
	// lbz r10,10(r25)
	ctx.r10.u64 = PPC_LOAD_U8(r25.u32 + 10);
	// stw r3,108(r25)
	PPC_STORE_U32(r25.u32 + 108, ctx.r3.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,796(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 796);
	// beq cr6,0x82219e08
	if (cr6.eq) goto loc_82219E08;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f1,-1680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1680);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82219e10
	goto loc_82219E10;
loc_82219E08:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
loc_82219E10:
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82219E18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r28,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r28.u8);
	// lwz r3,108(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,648(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 648);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82219E38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,108(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r4,r7,5
	ctx.r4.s64 = ctx.r7.s64 + 327680;
	// lwz r5,632(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 632);
	// addi r4,r4,5088
	ctx.r4.s64 = ctx.r4.s64 + 5088;
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82219E64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,108(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,636(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 636);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82219E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,108(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,720(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 720);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82219E9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r6,108(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// stw r6,300(r31)
	PPC_STORE_U32(r31.u32 + 300, ctx.r6.u32);
	// lwz r10,-10236(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r4,108(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// lwz r3,52(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82219EB8;
	sub_82220980(ctx, base);
	// lbz r5,280(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82219edc
	if (cr6.eq) goto loc_82219EDC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 180);
	ctx.f1.f64 = double(temp.f32);
	// lwz r10,804(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 804);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x82219efc
	goto loc_82219EFC;
loc_82219EDC:
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// ori r9,r10,5168
	ctx.r9.u64 = ctx.r10.u64 | 5168;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r6,804(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 804);
	// lfsx f1,r7,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	ctx.f1.f64 = double(temp.f32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_82219EFC:
	// bctrl 
	ctx.lr = 0x82219F00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// addi r4,r31,284
	ctx.r4.s64 = r31.s64 + 284;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,800(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 800);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82219F18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lfs f1,0(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,812(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 812);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82219F30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r6,292(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r3,108(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,592(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 592);
	// lwz r29,0(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82219F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r10,576(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 576);
	// lfs f0,-6176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6176);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82219F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r8,292(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r3,108(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,592(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 592);
	// lwz r29,0(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82219F8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r4,580(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 580);
	// lfs f0,-332(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -332);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82219FA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,292(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,628(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 628);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82219FBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r4,292(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 292);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82219FCC;
	sub_82220980(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204468
	ctx.lr = 0x82219FD8;
	sub_82204468(ctx, base);
	// stb r28,279(r31)
	PPC_STORE_U8(r31.u32 + 279, r28.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_82219DA0) {
	__imp__sub_82219DA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82219FE4) {
	__imp__sub_82219FE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82219FE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8221a028
	if (cr6.eq) goto loc_8221A028;
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addi r10,r3,44
	ctx.r10.s64 = ctx.r3.s64 + 44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8221a014
	if (!cr6.eq) goto loc_8221A014;
	// li r11,0
	r11.s64 = 0;
loc_8221A014:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8221A028:
	// lhz r11,40(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 40);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addis r8,r11,1
	ctx.r8.s64 = r11.s64 + 65536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// lfs f0,3796(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r31,29
	r31.s64 = 29;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// li r30,80
	r30.s64 = 80;
	// rlwinm r5,r7,2,14,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FFFC;
	// sth r7,40(r3)
	PPC_STORE_U16(ctx.r3.u32 + 40, ctx.r7.u16);
	// addi r4,r3,36
	ctx.r4.s64 = ctx.r3.s64 + 36;
	// addi r8,r3,44
	ctx.r8.s64 = ctx.r3.s64 + 44;
	// lwzx r11,r5,r9
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// addi r7,r9,48
	ctx.r7.s64 = ctx.r9.s64 + 48;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r6,r9,32
	ctx.r6.s64 = ctx.r9.s64 + 32;
	// stb r10,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r10.u8);
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// stb r10,10(r11)
	PPC_STORE_U8(r11.u32 + 10, ctx.r10.u8);
	// stb r10,9(r11)
	PPC_STORE_U8(r11.u32 + 9, ctx.r10.u8);
	// stb r10,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r10.u8);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// stb r10,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r10.u8);
	// stb r10,7(r11)
	PPC_STORE_U8(r11.u32 + 7, ctx.r10.u8);
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// stw r10,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r10.u32);
	// stw r10,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r10.u32);
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 96, temp.u32);
	// stvx128 v63,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,64(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// beq cr6,0x8221a104
	if (cr6.eq) goto loc_8221A104;
	// lwz r9,12(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r9.u32);
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// bne cr6,0x8221a0ec
	if (!cr6.eq) goto loc_8221A0EC;
	// stw r10,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
loc_8221A0EC:
	// lwz r10,12(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r11,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r11.u32);
	// lwz r10,20(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r7.u32);
loc_8221A104:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82219FE8) {
	__imp__sub_82219FE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A114) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221A114) {
	__imp__sub_8221A114(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A118) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82219fe8
	ctx.lr = 0x8221A130;
	sub_82219FE8(ctx, base);
	// addi r8,r3,16
	ctx.r8.s64 = ctx.r3.s64 + 16;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// li r10,32
	ctx.r10.s64 = 32;
	// li r11,48
	r11.s64 = 48;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r31,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r8,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

PPC_WEAK_FUNC(sub_8221A118) {
	__imp__sub_8221A118(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221A174) {
	__imp__sub_8221A174(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A178) {
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
	// bl 0x82219fe8
	ctx.lr = 0x8221A190;
	sub_82219FE8(ctx, base);
	// stb r31,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r31.u8);
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

PPC_WEAK_FUNC(sub_8221A178) {
	__imp__sub_8221A178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A1A8) {
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
	// bl 0x82219fe8
	ctx.lr = 0x8221A1C0;
	sub_82219FE8(ctx, base);
	// stb r31,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r31.u8);
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

PPC_WEAK_FUNC(sub_8221A1A8) {
	__imp__sub_8221A1A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A1D8) {
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
	// bl 0x82219fe8
	ctx.lr = 0x8221A1F0;
	sub_82219FE8(ctx, base);
	// stb r31,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r31.u8);
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

PPC_WEAK_FUNC(sub_8221A1D8) {
	__imp__sub_8221A1D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A208) {
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
	// bl 0x82219fe8
	ctx.lr = 0x8221A220;
	sub_82219FE8(ctx, base);
	// stb r31,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, r31.u8);
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

PPC_WEAK_FUNC(sub_8221A208) {
	__imp__sub_8221A208(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A238) {
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
	// bl 0x82219fe8
	ctx.lr = 0x8221A250;
	sub_82219FE8(ctx, base);
	// stb r31,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, r31.u8);
	// stb r31,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r31.u8);
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

PPC_WEAK_FUNC(sub_8221A238) {
	__imp__sub_8221A238(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221A26C) {
	__imp__sub_8221A26C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A270) {
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
	// bl 0x82219fe8
	ctx.lr = 0x8221A288;
	sub_82219FE8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82218d38
	ctx.lr = 0x8221A290;
	sub_82218D38(ctx, base);
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

PPC_WEAK_FUNC(sub_8221A270) {
	__imp__sub_8221A270(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A2A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221A2A4) {
	__imp__sub_8221A2A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A2A8) {
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
	// bl 0x82219fe8
	ctx.lr = 0x8221A2C0;
	sub_82219FE8(ctx, base);
	// stw r31,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r31.u32);
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

PPC_WEAK_FUNC(sub_8221A2A8) {
	__imp__sub_8221A2A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A2D8) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-1664
	ctx.r3.s64 = r11.s64 + -1664;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82130000
	ctx.lr = 0x8221A300;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219fe8
	ctx.lr = 0x8221A308;
	sub_82219FE8(ctx, base);
	// stb r30,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r30.u8);
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

PPC_WEAK_FUNC(sub_8221A2D8) {
	__imp__sub_8221A2D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221A324) {
	__imp__sub_8221A324(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A328) {
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
	ctx.lr = 0x8221A330;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8221a3a0
	if (cr6.eq) goto loc_8221A3A0;
	// addi r11,r3,44
	r11.s64 = ctx.r3.s64 + 44;
	// addi r9,r3,36
	ctx.r9.s64 = ctx.r3.s64 + 36;
loc_8221A34C:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x8221a370
	if (!cr6.eq) goto loc_8221A370;
	// stw r30,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r30.u32);
loc_8221A370:
	// lwz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r10,r6,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// sth r5,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r5.u16);
	// stwx r10,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r10.u32);
	// lwz r8,64(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x8221a34c
	if (!cr6.eq) goto loc_8221A34C;
loc_8221A3A0:
	// stw r30,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, r30.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// ori r31,r11,3488
	r31.u64 = r11.u64 | 3488;
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82224a08
	ctx.lr = 0x8221A3BC;
	sub_82224A08(ctx, base);
	// lwz r11,-10028(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10028);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// bl 0x82224a18
	ctx.lr = 0x8221A3C8;
	sub_82224A18(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r9,r10,3528
	ctx.r9.s64 = ctx.r10.s64 + 3528;
	// stb r11,28(r9)
	PPC_STORE_U8(ctx.r9.u32 + 28, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8221A328) {
	__imp__sub_8221A328(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A3E0) {
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
	ctx.lr = 0x8221A3E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r28,r11,-19728
	r28.s64 = r11.s64 + -19728;
	// addi r27,r10,-22108
	r27.s64 = ctx.r10.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8221A410;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8221A424;
	sub_823DEDD8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221A438;
	sub_82219BA0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_8221A3E0) {
	__imp__sub_8221A3E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221A440) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	// bl 0x823d91dc
	ctx.lr = 0x8221A448;
	// stfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -120, f29.u64);
	// stfd f30,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221b6fc
	if (!cr6.eq) goto loc_8221B6FC;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r23,0
	r23.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8221a4b4
	if (cr6.eq) goto loc_8221A4B4;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r11,r31,44
	r11.s64 = r31.s64 + 44;
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// addi r10,r9,1
	ctx.r10.s64 = ctx.r9.s64 + 1;
	// stw r8,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r8.u32);
	// stw r10,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r10.u32);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x8221a4a0
	if (!cr6.eq) goto loc_8221A4A0;
	// stw r23,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r23.u32);
loc_8221A4A0:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// stw r8,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r8.u32);
	// b 0x8221a4dc
	goto loc_8221A4DC;
loc_8221A4B4:
	// lhz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 40);
	// addi r11,r31,36
	r11.s64 = r31.s64 + 36;
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addis r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 65536;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// rlwinm r6,r7,2,14,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FFFC;
	// sth r7,40(r31)
	PPC_STORE_U16(r31.u32 + 40, ctx.r7.u16);
	// lwzx r5,r6,r9
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// stw r5,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r5.u32);
loc_8221A4DC:
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// li r21,15
	r21.s64 = 15;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221a500
	if (cr6.eq) goto loc_8221A500;
	// addi r4,r31,80
	ctx.r4.s64 = r31.s64 + 80;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82218bf0
	ctx.lr = 0x8221A4F8;
	sub_82218BF0(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r21,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r21.u32);
loc_8221A500:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,5
	r11.s64 = 327680;
	// vspltisw128 v61,-1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,5
	ctx.r10.s64 = 327680;
	// ori r9,r11,5168
	ctx.r9.u64 = r11.u64 | 5168;
	// ori r29,r10,5088
	r29.u64 = ctx.r10.u64 | 5088;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// addi r27,r31,192
	r27.s64 = r31.s64 + 192;
	// li r24,16
	r24.s64 = 16;
	// li r25,32
	r25.s64 = 32;
	// li r26,48
	r26.s64 = 48;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r6,r8,2384
	ctx.r6.s64 = ctx.r8.s64 + 2384;
	// lfsx f0,r7,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,284(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 284, temp.u32);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r4,r5,r29
	ctx.r4.u64 = ctx.r5.u64 + r29.u64;
	// lvx128 v60,r0,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r4,r24
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r27,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r4,r25
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r27,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r4,r26
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r27,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v56,v62,v63
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v54,r11,r26
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r25
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r11,r24
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v47,v55,v63
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v51,v52,v63
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128 v44,v47,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v44.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v47.f32), simde_mm_load_ps(v56.f32)));
	// vand128 v50,v53,v63
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v48,v54,v63
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128 v49,v51,v56
	simde_mm_store_ps(v49.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v56.f32)));
	// vcmpeqfp128 v46,v50,v56
	simde_mm_store_ps(v46.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v56.f32)));
	// vcmpeqfp128 v45,v48,v56
	simde_mm_store_ps(v45.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v56.f32)));
	// vand128 v42,v44,v49
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)v49.u8)));
	// vand128 v43,v46,v45
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)v45.u8)));
	// vand128 v41,v42,v43
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)v43.u8)));
	// vcmpequw128. v40,v41,v61
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v41.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	cr6.setFromMask(simde_mm_load_ps(v40.f32), 0xF);
	// mfocrf r3,2
	ctx.r3.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r3,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221a5f0
	if (cr6.eq) goto loc_8221A5F0;
	// lvx128 v39,r0,r27
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r27,r24
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r27,r25
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v36,r27,r26
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r27.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8221A5F0:
	// stb r23,279(r31)
	PPC_STORE_U8(r31.u32 + 279, r23.u8);
	// stb r23,273(r31)
	PPC_STORE_U8(r31.u32 + 273, r23.u8);
	// bl 0x82387a18
	ctx.lr = 0x8221A5FC;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221a670
	if (!cr6.eq) goto loc_8221A670;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221a63c
	if (cr6.eq) goto loc_8221A63C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8221a658
	if (!cr6.gt) goto loc_8221A658;
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// b 0x8221a64c
	goto loc_8221A64C;
loc_8221A63C:
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8221a658
	if (!cr6.gt) goto loc_8221A658;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
loc_8221A64C:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r30
	r11.u64 = r30.u64;
	// bne cr6,0x8221a65c
	if (!cr6.eq) goto loc_8221A65C;
loc_8221A658:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_8221A65C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221a670
	if (cr6.eq) goto loc_8221A670;
	// bl 0x822a39c8
	ctx.lr = 0x8221A66C;
	sub_822A39C8(ctx, base);
	// bl 0x822ab258
	ctx.lr = 0x8221A670;
	sub_822AB258(ctx, base);
loc_8221A670:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lbz r9,277(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 277);
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,264(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// stw r23,268(r31)
	PPC_STORE_U32(r31.u32 + 268, r23.u32);
	// stw r8,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r8.u32);
	// stb r9,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r9.u8);
	// lwz r11,288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// cmplwi cr6,r11,25
	cr6.compare<uint32_t>(r11.u32, 25, xer);
	// bgt cr6,0x8221b6fc
	if (cr6.gt) goto loc_8221B6FC;
	// lis r12,-32222
	r12.s64 = -2111700992;
	// addi r12,r12,-22856
	r12.s64 = r12.s64 + -22856;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,-22548(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22548);
	// lwz r17,-22284(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22284);
	// lwz r17,-22024(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22024);
	// lwz r17,-22024(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22024);
	// lwz r17,-22284(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22284);
	// lwz r17,-22024(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22024);
	// lwz r17,-22024(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22024);
	// lwz r17,-21996(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -21996);
	// lwz r17,-18692(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -18692);
	// lwz r17,-19752(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -19752);
	// lwz r17,-22284(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22284);
	// lwz r17,-19964(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -19964);
	// lwz r17,-20108(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -20108);
	// lwz r17,-19360(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -19360);
	// lwz r17,-18968(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -18968);
	// lwz r17,-21996(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -21996);
	// lwz r17,-19148(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -19148);
	// lwz r17,-21068(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -21068);
	// lwz r17,-20580(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -20580);
	// lwz r17,-18692(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -18692);
	// lwz r17,-18692(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -18692);
	// lwz r17,-18692(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -18692);
	// lwz r17,-18692(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -18692);
	// lwz r17,-18768(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -18768);
	// lwz r17,-21908(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -21908);
	// lwz r17,-22752(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -22752);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stb r23,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r23.u8);
	// lfs f0,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r30.u8);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f0,96(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 96, temp.u32);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// stb r30,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r30.u8);
	// lwz r6,104(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8221a764
	if (cr6.eq) goto loc_8221A764;
	// addi r5,r3,96
	ctx.r5.s64 = ctx.r3.s64 + 96;
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// b 0x8221a794
	goto loc_8221A794;
loc_8221A764:
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// addi r30,r3,16
	r30.s64 = ctx.r3.s64 + 16;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r29,r3,96
	r29.s64 = ctx.r3.s64 + 96;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bl 0x822192f8
	ctx.lr = 0x8221A788;
	sub_822192F8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
loc_8221A794:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221A79C;
	sub_82219BA0(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,108(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 592);
	// lwz r11,-10220(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10220);
	// lwz r30,104(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8221A7C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221A7D0;
	sub_8262BAB0(ctx, base);
	// li r7,29
	ctx.r7.s64 = 29;
	// stw r7,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r7.u32);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// lfs f0,-1536(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1536);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r30.u8);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f0,96(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 96, temp.u32);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,4(r7)
	PPC_STORE_U8(ctx.r7.u32 + 4, r30.u8);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r6)
	PPC_STORE_U8(ctx.r6.u32 + 7, r30.u8);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r3,-10000(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10000);
	// bl 0x823bc1a8
	ctx.lr = 0x8221A82C;
	sub_823BC1A8(ctx, base);
	// lwz r11,-10000(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10000);
	// stb r30,292(r11)
	PPC_STORE_U8(r11.u32 + 292, r30.u8);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r3,r5,-2120
	ctx.r3.s64 = ctx.r5.s64 + -2120;
	// addi r26,r4,-19728
	r26.s64 = ctx.r4.s64 + -19728;
	// addi r25,r10,-22108
	r25.s64 = ctx.r10.s64 + -22108;
	// addi r30,r11,96
	r30.s64 = r11.s64 + 96;
	// addi r27,r11,16
	r27.s64 = r11.s64 + 16;
	// bl 0x821fa230
	ctx.lr = 0x8221A85C;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8221A870;
	sub_823DEDD8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221A884;
	sub_82219BA0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10028(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// add r4,r8,r29
	ctx.r4.u64 = ctx.r8.u64 + r29.u64;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// bl 0x822249b8
	ctx.lr = 0x8221A8AC;
	sub_822249B8(ctx, base);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,108(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 108);
	// lwz r11,-10220(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10220);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,592(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 592);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8221A8D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221A8E0;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// lfs f0,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r30.u8);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f0,96(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 96, temp.u32);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r7)
	PPC_STORE_U8(ctx.r7.u32 + 7, r30.u8);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r3,-10000(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10000);
	// bl 0x823bc1a8
	ctx.lr = 0x8221A92C;
	sub_823BC1A8(ctx, base);
	// lwz r11,-10000(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10000);
	// stb r30,292(r11)
	PPC_STORE_U8(r11.u32 + 292, r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// bl 0x822a3998
	ctx.lr = 0x8221A948;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x8221A94C;
	sub_822A8108(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r26,r11,96
	r26.s64 = r11.s64 + 96;
	// addi r25,r11,16
	r25.s64 = r11.s64 + 16;
	// bl 0x822192f8
	ctx.lr = 0x8221A96C;
	sub_822192F8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221A980;
	sub_82219BA0(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10028(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// bl 0x822249b8
	ctx.lr = 0x8221A9A8;
	sub_822249B8(ctx, base);
	// li r3,43
	ctx.r3.s64 = 43;
	// bl 0x82216138
	ctx.lr = 0x8221A9B0;
	sub_82216138(ctx, base);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,108(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// lwz r11,-10220(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10220);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,592(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 592);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8221A9D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221A9E4;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221b790
	ctx.lr = 0x8221AA00;
	sub_8221B790(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// lfs f0,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r30.u8);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f0,96(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 96, temp.u32);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r23,7(r7)
	PPC_STORE_U8(ctx.r7.u32 + 7, r23.u8);
	// stb r30,273(r31)
	PPC_STORE_U8(r31.u32 + 273, r30.u8);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r3,-10000(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// bl 0x823bc1a8
	ctx.lr = 0x8221AA50;
	sub_823BC1A8(ctx, base);
	// lwz r11,-10000(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10000);
	// stb r30,292(r11)
	PPC_STORE_U8(r11.u32 + 292, r30.u8);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lis r6,5
	ctx.r6.s64 = 327680;
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// ori r3,r6,5136
	ctx.r3.u64 = ctx.r6.u64 | 5136;
	// lwz r4,48(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r5,64
	ctx.r5.s64 = 64;
	// add r4,r4,r29
	ctx.r4.u64 = ctx.r4.u64 + r29.u64;
	// lvx128 v35,r9,r26
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f30,11368(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11368);
	f30.f64 = double(temp.f32);
	// lvx128 v34,r4,r26
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// stb r30,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r30.u8);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r4)
	PPC_STORE_U8(ctx.r4.u32 + 7, r30.u8);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,10(r11)
	PPC_STORE_U8(r11.u32 + 10, r30.u8);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,3(r10)
	PPC_STORE_U8(ctx.r10.u32 + 3, r30.u8);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r11,-10012(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r4,48(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lvx128 v33,r9,r5
	simde_mm_store_si128((simde__m128i*)v33.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r4,r3
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v32,v33
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_sub_ps(simde_mm_load_ps(v32.f32), simde_mm_load_ps(v33.f32)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// stvx128 v34,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,124(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f30,140(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fsqrts f29,f10
	f29.f64 = double(float(sqrt(ctx.f10.f64)));
	// beq cr6,0x8221ab60
	if (cr6.eq) goto loc_8221AB60;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// ori r25,r10,16704
	r25.u64 = ctx.r10.u64 | 16704;
	// add r3,r11,r25
	ctx.r3.u64 = r11.u64 + r25.u64;
	// bl 0x8224a2b8
	ctx.lr = 0x8221AB3C;
	sub_8224A2B8(ctx, base);
	// lwz r11,-10012(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10012);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221ab64
	if (cr6.eq) goto loc_8221AB64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// add r3,r11,r25
	ctx.r3.u64 = r11.u64 + r25.u64;
	// bl 0x8224a2b8
	ctx.lr = 0x8221AB58;
	sub_8224A2B8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// b 0x8221ab68
	goto loc_8221AB68;
loc_8221AB60:
	// mr r24,r23
	r24.u64 = r23.u64;
loc_8221AB64:
	// mr r26,r23
	r26.u64 = r23.u64;
loc_8221AB68:
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lwz r3,-10000(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10000);
	// bl 0x823bc1a8
	ctx.lr = 0x8221AB74;
	sub_823BC1A8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,-10000(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10000);
	// lfs f0,31016(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	f0.f64 = double(temp.f32);
	// stb r30,292(r11)
	PPC_STORE_U8(r11.u32 + 292, r30.u8);
	// fcmpu cr6,f29,f0
	cr6.compare(f29.f64, f0.f64);
	// blt cr6,0x8221ad28
	if (cr6.lt) goto loc_8221AD28;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x8221ac48
	if (cr6.eq) goto loc_8221AC48;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x8221ac48
	if (cr6.eq) goto loc_8221AC48;
	// lwz r9,144(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 144);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8221ac48
	if (cr6.eq) goto loc_8221AC48;
	// lwz r10,144(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 144);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8221ac48
	if (cr6.eq) goto loc_8221AC48;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
loc_8221ABB8:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8221abb8
	if (!cr6.eq) goto loc_8221ABB8;
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r8,6
	cr6.compare<uint32_t>(ctx.r8.u32, 6, xer);
	// ble cr6,0x8221ac48
	if (!cr6.gt) goto loc_8221AC48;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8221ABE0:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8221abe0
	if (!cr6.eq) goto loc_8221ABE0;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r8,6
	cr6.compare<uint32_t>(ctx.r8.u32, 6, xer);
	// ble cr6,0x8221ac48
	if (!cr6.gt) goto loc_8221AC48;
	// addi r10,r10,6
	ctx.r10.s64 = ctx.r10.s64 + 6;
	// addi r11,r9,6
	r11.s64 = ctx.r9.s64 + 6;
loc_8221AC0C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8221ac30
	if (cr6.eq) goto loc_8221AC30;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8221ac0c
	if (cr6.eq) goto loc_8221AC0C;
loc_8221AC30:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8221ac48
	if (!cr6.eq) goto loc_8221AC48;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-1540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1540);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f29,f0
	cr6.compare(f29.f64, f0.f64);
	// blt cr6,0x8221ad28
	if (cr6.lt) goto loc_8221AD28;
loc_8221AC48:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r21,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r21.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,-11624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11624);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r23,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, r23.u32);
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r25,48(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// addi r26,r11,96
	r26.s64 = r11.s64 + 96;
	// bl 0x822a3998
	ctx.lr = 0x8221AC84;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa10
	ctx.lr = 0x8221AC8C;
	sub_822AFA10(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r25,r29
	ctx.r5.u64 = r25.u64 + r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x822192f8
	ctx.lr = 0x8221ACA4;
	sub_822192F8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221ACB8;
	sub_82219BA0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// add r4,r7,r29
	ctx.r4.u64 = ctx.r7.u64 + r29.u64;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// bl 0x822249b8
	ctx.lr = 0x8221ACE0;
	sub_822249B8(ctx, base);
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,108(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	// lwz r11,-10220(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10220);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// lwz r11,592(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 592);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8221AD04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221AD14;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_8221AD28:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r9,-1572
	ctx.r6.s64 = ctx.r9.s64 + -1572;
	// lfs f0,-1544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1544);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,4(r8)
	PPC_STORE_U8(ctx.r8.u32 + 4, r30.u8);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lfs f0,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,68(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 68, temp.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r5,r11,96
	ctx.r5.s64 = r11.s64 + 96;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8221a3e0
	ctx.lr = 0x8221AD6C;
	sub_8221A3E0(ctx, base);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,108(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + 108);
	// lwz r11,-10220(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10220);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,592(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 592);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8221AD90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221ADA0;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// li r9,64
	ctx.r9.s64 = 64;
	// ori r8,r10,5136
	ctx.r8.u64 = ctx.r10.u64 | 5136;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r6)
	PPC_STORE_U8(ctx.r6.u32 + 9, r30.u8);
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r5)
	PPC_STORE_U8(ctx.r5.u32 + 7, r30.u8);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,10(r4)
	PPC_STORE_U8(ctx.r4.u32 + 10, r30.u8);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, r30.u8);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,-10000(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10000);
	// lvx128 v62,r10,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lvx128 v61,r9,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823bc1a8
	ctx.lr = 0x8221AE18;
	sub_823BC1A8(ctx, base);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// lwz r11,-10000(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10000);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r30,292(r11)
	PPC_STORE_U8(r11.u32 + 292, r30.u8);
	// lfs f12,31016(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31016);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f10,f13,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fmadds f9,f0,f0,f10
	ctx.f9.f64 = double(float(f0.f64 * f0.f64 + ctx.f10.f64));
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fcmpu cr6,f8,f12
	cr6.compare(ctx.f8.f64, ctx.f12.f64);
	// bge cr6,0x8221aec0
	if (!cr6.lt) goto loc_8221AEC0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r9,-1596
	ctx.r6.s64 = ctx.r9.s64 + -1596;
	// lfs f0,-1576(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1576);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r5,r11,96
	ctx.r5.s64 = r11.s64 + 96;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8221a3e0
	ctx.lr = 0x8221AE78;
	sub_8221A3E0(ctx, base);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,108(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// lwz r11,-10220(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10220);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,592(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 592);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8221AE9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221AEAC;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_8221AEC0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r21,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r21.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,-11624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -11624);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 96, temp.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r23,108(r9)
	PPC_STORE_U32(ctx.r9.u32 + 108, r23.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// addi r26,r11,96
	r26.s64 = r11.s64 + 96;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r25,48(r11)
	r25.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x822a3998
	ctx.lr = 0x8221AEF8;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa10
	ctx.lr = 0x8221AF00;
	sub_822AFA10(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r25,r29
	ctx.r5.u64 = r25.u64 + r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x822192f8
	ctx.lr = 0x8221AF18;
	sub_822192F8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221AF2C;
	sub_82219BA0(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10028(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// add r4,r7,r29
	ctx.r4.u64 = ctx.r7.u64 + r29.u64;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// bl 0x822249b8
	ctx.lr = 0x8221AF54;
	sub_822249B8(ctx, base);
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,108(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	// lwz r11,-10220(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10220);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// lwz r11,592(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 592);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8221AF78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221AF88;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// li r9,64
	ctx.r9.s64 = 64;
	// ori r8,r10,5136
	ctx.r8.u64 = ctx.r10.u64 | 5136;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stb r23,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r23.u8);
	// lfs f12,31016(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31016);
	ctx.f12.f64 = double(temp.f32);
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r23,9(r5)
	PPC_STORE_U8(ctx.r5.u32 + 9, r23.u8);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r4)
	PPC_STORE_U8(ctx.r4.u32 + 7, r30.u8);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r30.u8);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r23,3(r11)
	PPC_STORE_U8(r11.u32 + 3, r23.u8);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// stb r30,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r30.u8);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lvx128 v58,r10,r8
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v57,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f0
	ctx.f11.f64 = double(float(f0.f64 * f0.f64));
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f10,f0,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f9,f13,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fsqrts f8,f9
	ctx.f8.f64 = double(float(sqrt(ctx.f9.f64)));
	// fcmpu cr6,f8,f12
	cr6.compare(ctx.f8.f64, ctx.f12.f64);
	// bge cr6,0x8221b094
	if (!cr6.lt) goto loc_8221B094;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r9,-1596
	ctx.r6.s64 = ctx.r9.s64 + -1596;
	// lfs f0,-1576(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1576);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 96, temp.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r5,r11,96
	ctx.r5.s64 = r11.s64 + 96;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8221a3e0
	ctx.lr = 0x8221B04C;
	sub_8221A3E0(ctx, base);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,108(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// lwz r11,-10220(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10220);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,592(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 592);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8221B070;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221B080;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
loc_8221B094:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r9,14
	ctx.r9.s64 = 14;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r9.u32);
	// lfs f0,-11624(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 96, temp.u32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r23,108(r8)
	PPC_STORE_U32(ctx.r8.u32 + 108, r23.u32);
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// addi r30,r11,16
	r30.s64 = r11.s64 + 16;
	// addi r26,r11,96
	r26.s64 = r11.s64 + 96;
	// lwz r25,48(r10)
	r25.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// bl 0x822a3998
	ctx.lr = 0x8221B0D0;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa10
	ctx.lr = 0x8221B0D8;
	sub_822AFA10(ctx, base);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r25,r29
	ctx.r5.u64 = r25.u64 + r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x822192f8
	ctx.lr = 0x8221B0F0;
	sub_822192F8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221B104;
	sub_82219BA0(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10028(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10028);
	// lwz r4,48(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// add r4,r4,r29
	ctx.r4.u64 = ctx.r4.u64 + r29.u64;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// bl 0x822249b8
	ctx.lr = 0x8221B12C;
	sub_822249B8(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r11,-10220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10220);
	// lwz r3,108(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 592);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8221B150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221B160;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r9,-1596
	ctx.r6.s64 = ctx.r9.s64 + -1596;
	// stb r30,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r30.u8);
	// lfs f0,-1576(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1576);
	f0.f64 = double(temp.f32);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r8)
	PPC_STORE_U8(ctx.r8.u32 + 7, r30.u8);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f0,96(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 96, temp.u32);
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,10(r5)
	PPC_STORE_U8(ctx.r5.u32 + 10, r30.u8);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r5,r11,96
	ctx.r5.s64 = r11.s64 + 96;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x8221a3e0
	ctx.lr = 0x8221B1BC;
	sub_8221A3E0(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r11,-10220(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10220);
	// lwz r3,108(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221B1E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221B1F0;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stb r23,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r23.u8);
	// lfs f0,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r30.u8);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r8)
	PPC_STORE_U8(ctx.r8.u32 + 7, r30.u8);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f0,96(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 96, temp.u32);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 + r29.u64;
	// addi r30,r3,16
	r30.s64 = ctx.r3.s64 + 16;
	// addi r27,r3,96
	r27.s64 = ctx.r3.s64 + 96;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x822192f8
	ctx.lr = 0x8221B254;
	sub_822192F8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221B268;
	sub_82219BA0(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10028(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// bl 0x822249b8
	ctx.lr = 0x8221B290;
	sub_822249B8(ctx, base);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,108(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// lwz r11,-10220(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10220);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,592(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 592);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8221B2B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221B2C4;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r9,352
	ctx.r9.s64 = 352;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stb r23,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r23.u8);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r23,r1,80
	r23.s64 = ctx.r1.s64 + 80;
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lfs f12,14988(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14988);
	ctx.f12.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r11)
	PPC_STORE_U8(r11.u32 + 9, r30.u8);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r11)
	PPC_STORE_U8(r11.u32 + 7, r30.u8);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f13,96(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 96, temp.u32);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r11,-10220(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10220);
	// lvx128 v56,r11,r9
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 320);
	f0.f64 = double(temp.f32);
	// stvx128 v56,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v55,r0,r10
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v54,v63,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v54,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82202ec0
	ctx.lr = 0x8221B384;
	sub_82202EC0(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// lvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r0,r9
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r0,r8
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r0,r7
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r30,r3,16
	r30.s64 = ctx.r3.s64 + 16;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r27,r3,96
	r27.s64 = ctx.r3.s64 + 96;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 + r29.u64;
	// bl 0x822192f8
	ctx.lr = 0x8221B3E0;
	sub_822192F8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221B3F4;
	sub_82219BA0(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10028(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// bl 0x822249b8
	ctx.lr = 0x8221B41C;
	sub_822249B8(ctx, base);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r11,-10220(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + -10220);
	// lwz r3,108(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 592);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8221B43C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221B44C;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stb r23,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r23.u8);
	// lfs f0,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r30.u8);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,7(r8)
	PPC_STORE_U8(ctx.r8.u32 + 7, r30.u8);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f0,96(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 96, temp.u32);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r30,r3,16
	r30.s64 = ctx.r3.s64 + 16;
	// addi r27,r3,96
	r27.s64 = ctx.r3.s64 + 96;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// add r5,r5,r29
	ctx.r5.u64 = ctx.r5.u64 + r29.u64;
	// bl 0x822192f8
	ctx.lr = 0x8221B4B0;
	sub_822192F8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82219ba0
	ctx.lr = 0x8221B4C4;
	sub_82219BA0(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10028(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// add r4,r11,r29
	ctx.r4.u64 = r11.u64 + r29.u64;
	// bl 0x822249b8
	ctx.lr = 0x8221B4EC;
	sub_822249B8(ctx, base);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,108(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 108);
	// lwz r11,-10220(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10220);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,592(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 592);
	// lwz r31,104(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8221B510;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221B520;
	sub_8262BAB0(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r23,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r23.u8);
	// lfs f0,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r30.u8);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r23,7(r8)
	PPC_STORE_U8(ctx.r8.u32 + 7, r23.u8);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// stfs f0,96(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 96, temp.u32);
	// bl 0x822a3998
	ctx.lr = 0x8221B568;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa10
	ctx.lr = 0x8221B570;
	sub_822AFA10(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// li r3,43
	ctx.r3.s64 = 43;
	// lvx128 v49,r0,r6
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r6,r24
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r6,r25
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v46,r6,r26
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,6(r5)
	PPC_STORE_U8(ctx.r5.u32 + 6, r30.u8);
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// bl 0x82216138
	ctx.lr = 0x8221B5B0;
	sub_82216138(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lwz r11,-10028(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// bl 0x822249b8
	ctx.lr = 0x8221B5D4;
	sub_822249B8(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r23,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r23.u8);
	// lfs f0,-11624(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -11624);
	f0.f64 = double(temp.f32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r23,9(r9)
	PPC_STORE_U8(ctx.r9.u32 + 9, r23.u8);
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r23,7(r8)
	PPC_STORE_U8(ctx.r8.u32 + 7, r23.u8);
	// lwz r7,68(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f0,96(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 96, temp.u32);
	// lwz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r30,6(r6)
	PPC_STORE_U8(ctx.r6.u32 + 6, r30.u8);
	// lwz r3,17268(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8221B624;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa10
	ctx.lr = 0x8221B62C;
	sub_822AFA10(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lvx128 v45,r0,r3
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r10,80
	ctx.r10.s64 = 80;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// stvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v44,r0,r4
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v43,r3,r24
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r11,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r3,r25
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r11,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v41,r3,r26
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stvx128 v44,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r11,-10028(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// bl 0x822249b8
	ctx.lr = 0x8221B69C;
	sub_822249B8(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
	// stb r30,280(r31)
	PPC_STORE_U8(r31.u32 + 280, r30.u8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stb r30,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r30.u8);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r10,-1620
	ctx.r4.s64 = ctx.r10.s64 + -1620;
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// addi r11,r11,2544
	r11.s64 = r11.s64 + 2544;
	// lvx128 v40,r0,r11
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r0,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v39,r11,r24
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r27,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r11,r25
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r27,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v37,r11,r26
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r27,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r27.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82130000
	ctx.lr = 0x8221B6F4;
	sub_82130000(ctx, base);
	// lfs f0,180(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 180);
	f0.f64 = double(temp.f32);
	// stfs f0,284(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 284, temp.u32);
loc_8221B6FC:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// lfd f29,-120(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f30,-112(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_8221A440) {
	__imp__sub_8221A440(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221B710) {
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
	ctx.lr = 0x8221B718;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r10,r11,-1528
	ctx.r10.s64 = r11.s64 + -1528;
	// lis r11,0
	r11.s64 = 0;
	// addi r31,r28,36
	r31.s64 = r28.s64 + 36;
	// li r30,3
	r30.s64 = 3;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// ori r29,r11,65535
	r29.u64 = r11.u64 | 65535;
loc_8221B73C:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r9,r11,r29
	ctx.r9.u64 = r11.u64 + r29.u64;
	// clrlwi r8,r9,16
	ctx.r8.u64 = ctx.r9.u32 & 0xFFFF;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// rlwinm r7,r8,2,14,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3FFFC;
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x82130588
	ctx.lr = 0x8221B75C;
	sub_82130588(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8221b73c
	if (!cr0.eq) goto loc_8221B73C;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221b778
	if (cr6.eq) goto loc_8221B778;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8221B778;
	sub_82130588(ctx, base);
loc_8221B778:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_8221B710) {
	__imp__sub_8221B710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221B78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221B78C) {
	__imp__sub_8221B78C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221B790) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r5,29
	ctx.r5.s64 = 29;
	// stb r10,272(r3)
	PPC_STORE_U8(ctx.r3.u32 + 272, ctx.r10.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,268(r3)
	PPC_STORE_U32(ctx.r3.u32 + 268, ctx.r10.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r10,275(r3)
	PPC_STORE_U8(ctx.r3.u32 + 275, ctx.r10.u8);
	// stfs f0,260(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 260, temp.u32);
	// stb r10,276(r3)
	PPC_STORE_U8(ctx.r3.u32 + 276, ctx.r10.u8);
	// stfs f0,264(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 264, temp.u32);
	// stw r5,288(r3)
	PPC_STORE_U32(ctx.r3.u32 + 288, ctx.r5.u32);
	// stb r10,274(r3)
	PPC_STORE_U8(ctx.r3.u32 + 274, ctx.r10.u8);
	// stb r10,280(r3)
	PPC_STORE_U8(ctx.r3.u32 + 280, ctx.r10.u8);
	// stb r10,279(r3)
	PPC_STORE_U8(ctx.r3.u32 + 279, ctx.r10.u8);
	// beq cr6,0x8221b878
	if (cr6.eq) goto loc_8221B878;
	// lbz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// addi r9,r11,16
	ctx.r9.s64 = r11.s64 + 16;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r31,80
	r31.s64 = 80;
	// addi r8,r9,48
	ctx.r8.s64 = ctx.r9.s64 + 48;
	// addi r7,r9,32
	ctx.r7.s64 = ctx.r9.s64 + 32;
	// addi r6,r9,16
	ctx.r6.s64 = ctx.r9.s64 + 16;
	// stb r4,277(r3)
	PPC_STORE_U8(ctx.r3.u32 + 277, ctx.r4.u8);
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// stb r10,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r10.u8);
	// stb r10,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r10.u8);
	// stb r10,10(r11)
	PPC_STORE_U8(r11.u32 + 10, ctx.r10.u8);
	// stb r10,9(r11)
	PPC_STORE_U8(r11.u32 + 9, ctx.r10.u8);
	// stb r10,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r10.u8);
	// stb r10,4(r11)
	PPC_STORE_U8(r11.u32 + 4, ctx.r10.u8);
	// stb r10,5(r11)
	PPC_STORE_U8(r11.u32 + 5, ctx.r10.u8);
	// stb r10,6(r11)
	PPC_STORE_U8(r11.u32 + 6, ctx.r10.u8);
	// stb r10,7(r11)
	PPC_STORE_U8(r11.u32 + 7, ctx.r10.u8);
	// stb r10,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r10.u8);
	// stw r10,104(r11)
	PPC_STORE_U32(r11.u32 + 104, ctx.r10.u32);
	// stw r10,108(r11)
	PPC_STORE_U32(r11.u32 + 108, ctx.r10.u32);
	// stw r5,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r5.u32);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r3,36
	ctx.r8.s64 = ctx.r3.s64 + 36;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 96, temp.u32);
	// stvx128 v63,r11,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,36(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lhz r11,40(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 40);
	// rotlwi r8,r11,2
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,40(r3)
	PPC_STORE_U16(ctx.r3.u32 + 40, ctx.r7.u16);
	// lwz r5,68(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// stw r10,68(r3)
	PPC_STORE_U32(ctx.r3.u32 + 68, ctx.r10.u32);
loc_8221B878:
	// lwz r11,64(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8221b8b4
	if (cr6.eq) goto loc_8221B8B4;
	// lwz r11,60(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// addi r9,r3,44
	ctx.r9.s64 = ctx.r3.s64 + 44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8221b89c
	if (!cr6.eq) goto loc_8221B89C;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8221B89C:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r9
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,29
	cr6.compare<int32_t>(ctx.r9.s32, 29, xer);
	// beq cr6,0x8221b8b4
	if (cr6.eq) goto loc_8221B8B4;
	// bl 0x8221a440
	ctx.lr = 0x8221B8B4;
	sub_8221A440(ctx, base);
loc_8221B8B4:
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

PPC_WEAK_FUNC(sub_8221B790) {
	__imp__sub_8221B790(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221B8C8) {
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
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bne cr6,0x8221b9a0
	if (!cr6.eq) goto loc_8221B9A0;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221b9a0
	if (cr6.eq) goto loc_8221B9A0;
	// lwz r11,108(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x8221b9a0
	if (!cr6.eq) goto loc_8221B9A0;
	// lwz r11,300(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// cmplw cr6,r5,r11
	cr6.compare<uint32_t>(ctx.r5.u32, r11.u32, xer);
	// bne cr6,0x8221b928
	if (!cr6.eq) goto loc_8221B928;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3408
	ctx.r3.s64 = ctx.r3.s64 + 3408;
	// bl 0x82224a28
	ctx.lr = 0x8221B920;
	sub_82224A28(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,300(r31)
	PPC_STORE_U32(r31.u32 + 300, ctx.r10.u32);
loc_8221B928:
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lbz r11,7(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 7);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221b984
	if (cr6.eq) goto loc_8221B984;
	// lwz r11,288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// cmpwi cr6,r11,17
	cr6.compare<int32_t>(r11.s32, 17, xer);
	// beq cr6,0x8221b96c
	if (cr6.eq) goto loc_8221B96C;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// beq cr6,0x8221b96c
	if (cr6.eq) goto loc_8221B96C;
	// cmpwi cr6,r11,18
	cr6.compare<int32_t>(r11.s32, 18, xer);
	// beq cr6,0x8221b96c
	if (cr6.eq) goto loc_8221B96C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204480
	ctx.lr = 0x8221B968;
	sub_82204480(ctx, base);
	// b 0x8221b984
	goto loc_8221B984;
loc_8221B96C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lfs f1,96(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204558
	ctx.lr = 0x8221B984;
	sub_82204558(ctx, base);
loc_8221B984:
	// lbz r11,276(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 276);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221b998
	if (cr6.eq) goto loc_8221B998;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221b790
	ctx.lr = 0x8221B998;
	sub_8221B790(ctx, base);
loc_8221B998:
	// li r11,1
	r11.s64 = 1;
	// stb r11,273(r31)
	PPC_STORE_U8(r31.u32 + 273, r11.u8);
loc_8221B9A0:
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

PPC_WEAK_FUNC(sub_8221B8C8) {
	__imp__sub_8221B8C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221B9B8) {
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
	// bl 0x82219fe8
	ctx.lr = 0x8221B9D0;
	sub_82219FE8(ctx, base);
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// li r11,1
	r11.s64 = 1;
	// stb r11,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r11.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221b9f0
	if (cr6.eq) goto loc_8221B9F0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-2612
	ctx.r4.s64 = r11.s64 + -2612;
	// b 0x8221bac4
	goto loc_8221BAC4;
loc_8221B9F0:
	// lbz r11,2(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 2);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221ba08
	if (cr6.eq) goto loc_8221BA08;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-2696
	ctx.r4.s64 = r11.s64 + -2696;
	// b 0x8221bac4
	goto loc_8221BAC4;
loc_8221BA08:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221ba20
	if (cr6.eq) goto loc_8221BA20;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-2544
	ctx.r4.s64 = r11.s64 + -2544;
	// b 0x8221bac4
	goto loc_8221BAC4;
loc_8221BA20:
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221ba5c
	if (cr6.eq) goto loc_8221BA5C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221a328
	ctx.lr = 0x8221BA34;
	sub_8221A328(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204480
	ctx.lr = 0x8221BA48;
	sub_82204480(ctx, base);
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
loc_8221BA5C:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8221babc
	if (cr6.eq) goto loc_8221BABC;
	// lwz r11,60(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// addi r10,r31,44
	ctx.r10.s64 = r31.s64 + 44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8221ba80
	if (!cr6.eq) goto loc_8221BA80;
	// li r11,0
	r11.s64 = 0;
loc_8221BA80:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// lwz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// cmpwi cr6,r8,29
	cr6.compare<int32_t>(ctx.r8.s32, 29, xer);
	// bne cr6,0x8221bac8
	if (!cr6.eq) goto loc_8221BAC8;
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8221baa8
	if (!cr6.eq) goto loc_8221BAA8;
	// li r11,0
	r11.s64 = 0;
loc_8221BAA8:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r4,r9,-2564
	ctx.r4.s64 = ctx.r9.s64 + -2564;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// b 0x8221bac4
	goto loc_8221BAC4;
loc_8221BABC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-2564
	ctx.r4.s64 = r11.s64 + -2564;
loc_8221BAC4:
	// bl 0x82218d38
	ctx.lr = 0x8221BAC8;
	sub_82218D38(ctx, base);
loc_8221BAC8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221a440
	ctx.lr = 0x8221BAD0;
	sub_8221A440(ctx, base);
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

PPC_WEAK_FUNC(sub_8221B9B8) {
	__imp__sub_8221B9B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221BAE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221BAE4) {
	__imp__sub_8221BAE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221BAE8) {
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
	// addi r11,r31,36
	r11.s64 = r31.s64 + 36;
	// lhz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 40);
	// lwz r9,36(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addis r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 65536;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r7,40(r31)
	PPC_STORE_U16(r31.u32 + 40, ctx.r7.u16);
	// rlwinm r6,r7,2,14,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FFFC;
	// lwzx r30,r6,r9
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218bf0
	ctx.lr = 0x8221BB2C;
	sub_82218BF0(ctx, base);
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// addi r11,r31,44
	r11.s64 = r31.s64 + 44;
	// cmpwi cr6,r5,3
	cr6.compare<int32_t>(ctx.r5.s32, 3, xer);
	// beq cr6,0x8221bb70
	if (cr6.eq) goto loc_8221BB70;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x8221bb58
	if (!cr6.eq) goto loc_8221BB58;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_8221BB58:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r9,r11
	PPC_STORE_U32(ctx.r9.u32 + r11.u32, r30.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
loc_8221BB70:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221a440
	ctx.lr = 0x8221BB78;
	sub_8221A440(ctx, base);
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

PPC_WEAK_FUNC(sub_8221BAE8) {
	__imp__sub_8221BAE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221BB90) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8221bc1c
	if (!cr6.gt) goto loc_8221BC1C;
	// addi r11,r31,44
	r11.s64 = r31.s64 + 44;
	// addi r9,r31,36
	ctx.r9.s64 = r31.s64 + 36;
loc_8221BBC4:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r6,r10,-1
	ctx.r6.s64 = ctx.r10.s64 + -1;
	// addi r10,r7,1
	ctx.r10.s64 = ctx.r7.s64 + 1;
	// stw r6,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r6.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x8221bbe8
	if (!cr6.eq) goto loc_8221BBE8;
	// stw r4,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r4.u32);
loc_8221BBE8:
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rotlwi r7,r10,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// sth r3,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r3.u16);
	// lwzx r5,r5,r11
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// stwx r5,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r5.u32);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmpw cr6,r8,r3
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r3.s32, xer);
	// blt cr6,0x8221bbc4
	if (cr6.lt) goto loc_8221BBC4;
loc_8221BC1C:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// addis r3,r11,5
	ctx.r3.s64 = r11.s64 + 327680;
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// bl 0x8221b790
	ctx.lr = 0x8221BC30;
	sub_8221B790(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221bc50
	if (cr6.eq) goto loc_8221BC50;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r4,108(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// lwz r11,-10236(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8221e310
	ctx.lr = 0x8221BC50;
	sub_8221E310(ctx, base);
loc_8221BC50:
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r11,-10028(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10028);
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r8,r10,4945
	ctx.r8.u64 = ctx.r10.u64 | 4945;
	// stbx r9,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r9.u8);
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

PPC_WEAK_FUNC(sub_8221BB90) {
	__imp__sub_8221BB90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221BC7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221BC7C) {
	__imp__sub_8221BC7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221BC80) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8221BC88;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-21868
	ctx.r9.s64 = r11.s64 + -21868;
	// addi r4,r10,-1500
	ctx.r4.s64 = ctx.r10.s64 + -1500;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x8221BCBC;
	sub_823DB670(ctx, base);
	// addi r10,r30,80
	ctx.r10.s64 = r30.s64 + 80;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// vspltisw128 v127,0
	simde_mm_store_si128((simde__m128i*)v127.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r10,16
	r11.s64 = ctx.r10.s64 + 16;
	// addi r7,r8,-1528
	ctx.r7.s64 = ctx.r8.s64 + -1528;
	// li r31,0
	r31.s64 = 0;
	// addi r9,r11,48
	ctx.r9.s64 = r11.s64 + 48;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// addi r8,r11,32
	ctx.r8.s64 = r11.s64 + 32;
	// stw r31,36(r30)
	PPC_STORE_U32(r30.u32 + 36, r31.u32);
	// addi r7,r11,16
	ctx.r7.s64 = r11.s64 + 16;
	// sth r31,40(r30)
	PPC_STORE_U16(r30.u32 + 40, r31.u16);
	// li r26,29
	r26.s64 = 29;
	// sth r31,42(r30)
	PPC_STORE_U16(r30.u32 + 42, r31.u16);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stw r31,64(r30)
	PPC_STORE_U32(r30.u32 + 64, r31.u32);
	// stw r31,60(r30)
	PPC_STORE_U32(r30.u32 + 60, r31.u32);
	// li r27,80
	r27.s64 = 80;
	// stw r31,56(r30)
	PPC_STORE_U32(r30.u32 + 56, r31.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// stb r31,80(r30)
	PPC_STORE_U8(r30.u32 + 80, r31.u8);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// stb r31,81(r30)
	PPC_STORE_U8(r30.u32 + 81, r31.u8);
	// li r6,10
	ctx.r6.s64 = 10;
	// stb r31,82(r30)
	PPC_STORE_U8(r30.u32 + 82, r31.u8);
	// lfs f31,3796(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stb r31,90(r30)
	PPC_STORE_U8(r30.u32 + 90, r31.u8);
	// addi r5,r4,-1520
	ctx.r5.s64 = ctx.r4.s64 + -1520;
	// stb r31,89(r30)
	PPC_STORE_U8(r30.u32 + 89, r31.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stb r31,83(r30)
	PPC_STORE_U8(r30.u32 + 83, r31.u8);
	// addi r29,r30,36
	r29.s64 = r30.s64 + 36;
	// stb r31,84(r30)
	PPC_STORE_U8(r30.u32 + 84, r31.u8);
	// stb r31,85(r30)
	PPC_STORE_U8(r30.u32 + 85, r31.u8);
	// stb r31,86(r30)
	PPC_STORE_U8(r30.u32 + 86, r31.u8);
	// stb r31,87(r30)
	PPC_STORE_U8(r30.u32 + 87, r31.u8);
	// stb r31,88(r30)
	PPC_STORE_U8(r30.u32 + 88, r31.u8);
	// stw r31,184(r30)
	PPC_STORE_U32(r30.u32 + 184, r31.u32);
	// stw r31,188(r30)
	PPC_STORE_U32(r30.u32 + 188, r31.u32);
	// stw r26,92(r30)
	PPC_STORE_U32(r30.u32 + 92, r26.u32);
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,176(r30)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r30.u32 + 176, temp.u32);
	// stvx128 v127,r10,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-10224(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x8221BD7C;
	sub_8268B960(ctx, base);
	// stw r3,256(r30)
	PPC_STORE_U32(r30.u32 + 256, ctx.r3.u32);
	// li r25,3
	r25.s64 = 3;
loc_8221BD84:
	// li r3,112
	ctx.r3.s64 = 112;
	// bl 0x82130528
	ctx.lr = 0x8221BD8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8221bdfc
	if (cr6.eq) goto loc_8221BDFC;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// stb r31,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r31.u8);
	// stb r31,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, r31.u8);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r10,r11,48
	ctx.r10.s64 = r11.s64 + 48;
	// stb r31,2(r3)
	PPC_STORE_U8(ctx.r3.u32 + 2, r31.u8);
	// addi r9,r11,32
	ctx.r9.s64 = r11.s64 + 32;
	// stb r31,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, r31.u8);
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// stb r31,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, r31.u8);
	// stb r31,3(r3)
	PPC_STORE_U8(ctx.r3.u32 + 3, r31.u8);
	// stb r31,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, r31.u8);
	// stb r31,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r31.u8);
	// stb r31,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, r31.u8);
	// stb r31,7(r3)
	PPC_STORE_U8(ctx.r3.u32 + 7, r31.u8);
	// stb r31,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, r31.u8);
	// stw r31,104(r3)
	PPC_STORE_U32(ctx.r3.u32 + 104, r31.u32);
	// stw r31,108(r3)
	PPC_STORE_U32(ctx.r3.u32 + 108, r31.u32);
	// stw r26,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r26.u32);
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f31,96(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// stvx128 v127,r3,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8221be00
	goto loc_8221BE00;
loc_8221BDFC:
	// mr r28,r31
	r28.u64 = r31.u64;
loc_8221BE00:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8221BE0C;
	sub_8262E420(ctx, base);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// bne 0x8221bd84
	if (!cr0.eq) goto loc_8221BD84;
	// stw r31,68(r30)
	PPC_STORE_U32(r30.u32 + 68, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r31,277(r30)
	PPC_STORE_U8(r30.u32 + 277, r31.u8);
	// stb r31,278(r30)
	PPC_STORE_U8(r30.u32 + 278, r31.u8);
	// bl 0x8221b790
	ctx.lr = 0x8221BE2C;
	sub_8221B790(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_8221BC80) {
	__imp__sub_8221BC80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221BE44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221BE44) {
	__imp__sub_8221BE44(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221BE48) {
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
	// bl 0x8221b710
	ctx.lr = 0x8221BE68;
	sub_8221B710(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221be80
	if (cr6.eq) goto loc_8221BE80;
	// bl 0x82130588
	ctx.lr = 0x8221BE7C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8221BE80:
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

PPC_WEAK_FUNC(sub_8221BE48) {
	__imp__sub_8221BE48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221BE98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
	PPCRegister r26{};
	PPCRegister r27{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
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
	// bl 0x823d91f0
	ctx.lr = 0x8221BEA0;
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,1
	r28.s64 = 1;
	// li r26,0
	r26.s64 = 0;
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lfs f0,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lbz r9,716(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 716);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8221bf48
	if (!cr6.eq) goto loc_8221BF48;
	// lbz r11,272(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 272);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221bf48
	if (!cr6.eq) goto loc_8221BF48;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// ori r8,r10,5140
	ctx.r8.u64 = ctx.r10.u64 | 5140;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mr r11,r28
	r11.u64 = r28.u64;
	// lfs f0,-2376(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -2376);
	f0.f64 = double(temp.f32);
	// lfsx f13,r7,r8
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8221bf18
	if (cr6.gt) goto loc_8221BF18;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8221BF18:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221bf48
	if (!cr6.eq) goto loc_8221BF48;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221bf48
	if (cr6.eq) goto loc_8221BF48;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x8221BF48;
	sub_821EC468(ctx, base);
loc_8221BF48:
	// lwz r11,288(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 288);
	// cmplwi cr6,r11,28
	cr6.compare<uint32_t>(r11.u32, 28, xer);
	// bgt cr6,0x8221cb90
	if (cr6.gt) goto loc_8221CB90;
	// lis r12,-32222
	r12.s64 = -2111700992;
	// addi r12,r12,-16532
	r12.s64 = r12.s64 + -16532;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r17,-15296(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15296);
	// lwz r17,-15296(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15296);
	// lwz r17,-15332(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15332);
	// lwz r17,-15332(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15332);
	// lwz r17,-15296(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15296);
	// lwz r17,-15332(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15332);
	// lwz r17,-15332(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15332);
	// lwz r17,-15296(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15296);
	// lwz r17,-13576(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13576);
	// lwz r17,-13576(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13576);
	// lwz r17,-15296(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15296);
	// lwz r17,-15512(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15512);
	// lwz r17,-14136(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -14136);
	// lwz r17,-13576(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13576);
	// lwz r17,-13752(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13752);
	// lwz r17,-15296(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15296);
	// lwz r17,-13752(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13752);
	// lwz r17,-14136(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -14136);
	// lwz r17,-13424(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13424);
	// lwz r17,-16316(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16316);
	// lwz r17,-16096(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16096);
	// lwz r17,-13516(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13516);
	// lwz r17,-13540(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13540);
	// lwz r17,-13480(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13480);
	// lwz r17,-15296(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15296);
	// lwz r17,-13424(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13424);
	// lwz r17,-15888(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -15888);
	// lwz r17,-13424(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -13424);
	// lwz r17,-16416(r1)
	r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + -16416);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r30,108(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8221BFFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,608(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 608);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8221C014;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fsubs f13,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f0,-332(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -332);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8221cb90
	if (!cr6.lt) goto loc_8221CB90;
	// li r11,29
	r11.s64 = 29;
	// stb r26,279(r31)
	PPC_STORE_U8(r31.u32 + 279, r26.u8);
	// stw r11,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lbz r30,3(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// lbz r29,0(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// beq cr6,0x8221c07c
	if (cr6.eq) goto loc_8221C07C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221C06C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r11,r28
	r11.u64 = r28.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8221c080
	if (!cr6.eq) goto loc_8221C080;
loc_8221C07C:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8221C080:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8221cb90
	if (!cr6.eq) goto loc_8221CB90;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221cb90
	if (cr6.eq) goto loc_8221CB90;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221cb90
	if (cr6.eq) goto loc_8221CB90;
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221C0BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,260(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	f0.f64 = double(temp.f32);
	// addi r7,r9,29952
	ctx.r7.s64 = ctx.r9.s64 + 29952;
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(f0.f64 + f31.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,27632(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f0,18612(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 18612);
	f0.f64 = double(temp.f32);
	// stfs f12,260(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// fadds f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fsubs f9,f1,f11
	ctx.f9.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// fcmpu cr6,f10,f9
	cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// blt cr6,0x8221cb90
	if (cr6.lt) goto loc_8221CB90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,29
	ctx.r10.s64 = 29;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r26,293(r11)
	PPC_STORE_U8(r11.u32 + 293, r26.u8);
	// stb r28,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r28.u8);
	// stw r10,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lbz r30,3(r11)
	r30.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// lbz r29,0(r11)
	r29.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// beq cr6,0x8221c158
	if (cr6.eq) goto loc_8221C158;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221C148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// mr r11,r28
	r11.u64 = r28.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8221c15c
	if (!cr6.eq) goto loc_8221C15C;
loc_8221C158:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8221C15C:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221cb90
	if (cr6.eq) goto loc_8221CB90;
	// clrlwi r10,r29,24
	ctx.r10.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221cb90
	if (cr6.eq) goto loc_8221CB90;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221cb90
	if (cr6.eq) goto loc_8221CB90;
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221C198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,296(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 296);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,608(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 608);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8221C1B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fadds f13,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 + f31.f64));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,18612(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 18612);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fcmpu cr6,f12,f30
	cr6.compare(ctx.f12.f64, f30.f64);
	// blt cr6,0x8221cb90
	if (cr6.lt) goto loc_8221CB90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,29
	ctx.r10.s64 = 29;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// stb r26,293(r11)
	PPC_STORE_U8(r11.u32 + 293, r26.u8);
	// stb r28,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r28.u8);
	// stw r10,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lfs f0,260(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 260);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f12,f0,f31
	ctx.f12.f64 = double(float(f0.f64 + f31.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f12,260(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// stb r28,272(r31)
	PPC_STORE_U8(r31.u32 + 272, r28.u8);
	// lfs f0,18612(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 18612);
	f0.f64 = double(temp.f32);
	// lfs f13,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// fcmpu cr6,f11,f13
	cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// blt cr6,0x8221cb90
	if (cr6.lt) goto loc_8221CB90;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221c274
	if (cr6.eq) goto loc_8221C274;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x8221C238;
	sub_821E6828(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// bl 0x821f0270
	ctx.lr = 0x8221C248;
	sub_821F0270(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-12216(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -12216);
	// bl 0x821f0590
	ctx.lr = 0x8221C254;
	sub_821F0590(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// addi r7,r11,19
	ctx.r7.s64 = r11.s64 + 19;
	// stw r7,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r7.u32);
	// b 0x8221c2a4
	goto loc_8221C2A4;
loc_8221C274:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8221C280;
	sub_822A39C8(ctx, base);
	// bl 0x822a5680
	ctx.lr = 0x8221C284;
	sub_822A5680(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221c29c
	if (cr6.eq) goto loc_8221C29C;
	// li r11,28
	r11.s64 = 28;
	// stb r28,279(r31)
	PPC_STORE_U8(r31.u32 + 279, r28.u8);
	// b 0x8221c2a0
	goto loc_8221C2A0;
loc_8221C29C:
	// li r11,29
	r11.s64 = 29;
loc_8221C2A0:
	// stw r11,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r11.u32);
loc_8221C2A4:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r6,r11,96
	ctx.r6.s64 = r11.s64 + 96;
	// addi r5,r11,80
	ctx.r5.s64 = r11.s64 + 80;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,260(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 260, temp.u32);
	// bl 0x82219da0
	ctx.lr = 0x8221C2C8;
	sub_82219DA0(ctx, base);
	// li r3,43
	ctx.r3.s64 = 43;
	// bl 0x82216138
	ctx.lr = 0x8221C2D0;
	sub_82216138(ctx, base);
	// lwz r10,68(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 244);
	f0.f64 = double(temp.f32);
	// lwz r3,108(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// lfs f13,-30176(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -30176);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 592);
	// ble cr6,0x8221c30c
	if (!cr6.gt) goto loc_8221C30C;
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lwz r30,104(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8221C304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8221c33c
	goto loc_8221C33C;
loc_8221C30C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,31016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lwz r30,104(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bge cr6,0x8221c334
	if (!cr6.lt) goto loc_8221C334;
	// bctrl 
	ctx.lr = 0x8221C32C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// b 0x8221c33c
	goto loc_8221C33C;
loc_8221C334:
	// bctrl 
	ctx.lr = 0x8221C338;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,3
	ctx.r4.s64 = 3;
loc_8221C33C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8262bab0
	ctx.lr = 0x8221C348;
	sub_8262BAB0(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// stw r10,296(r31)
	PPC_STORE_U32(r31.u32 + 296, ctx.r10.u32);
	// stb r28,6(r11)
	PPC_STORE_U8(r11.u32 + 6, r28.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lbz r11,273(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 273);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221cb90
	if (cr6.eq) goto loc_8221CB90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-12012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2256(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2256);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221c398
	if (cr6.eq) goto loc_8221C398;
	// lwz r11,2260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r28
	r11.u64 = r28.u64;
	// bne cr6,0x8221c39c
	if (!cr6.eq) goto loc_8221C39C;
loc_8221C398:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8221C39C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221c3bc
	if (cr6.eq) goto loc_8221C3BC;
	// lwz r11,2256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2256);
	// lbz r10,467(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 467);
	// mr r11,r28
	r11.u64 = r28.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221c3c0
	if (cr6.eq) goto loc_8221C3C0;
loc_8221C3BC:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8221C3C0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221cb90
	if (!cr6.eq) goto loc_8221CB90;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r10,10850(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10850);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8221cb90
	if (!cr6.eq) goto loc_8221CB90;
	// bl 0x821fec58
	ctx.lr = 0x8221C3E4;
	sub_821FEC58(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221cb90
	if (cr6.eq) goto loc_8221CB90;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r10,26
	ctx.r10.s64 = 26;
	// stb r28,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r28.u8);
	// stb r28,6(r11)
	PPC_STORE_U8(r11.u32 + 6, r28.u8);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stb r26,7(r9)
	PPC_STORE_U8(ctx.r9.u32 + 7, r26.u8);
	// stw r10,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r10,29
	ctx.r10.s64 = 29;
	// stb r28,6(r11)
	PPC_STORE_U8(r11.u32 + 6, r28.u8);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r11,-10000(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10000);
	// lbz r11,291(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 291);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221c46c
	if (cr6.eq) goto loc_8221C46C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221bb90
	ctx.lr = 0x8221C45C;
	sub_8221BB90(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C46C:
	// lbz r11,273(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 273);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221c494
	if (!cr6.eq) goto loc_8221C494;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-828
	ctx.r3.s64 = r11.s64 + -828;
	// bl 0x82130000
	ctx.lr = 0x8221C484;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C494:
	// bl 0x823bc178
	ctx.lr = 0x8221C498;
	sub_823BC178(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221c7d0
	if (!cr6.eq) goto loc_8221C7D0;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r29,r11,29952
	r29.s64 = r11.s64 + 29952;
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,84(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 84);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// beq cr6,0x8221c4dc
	if (cr6.eq) goto loc_8221C4DC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-892
	ctx.r3.s64 = r11.s64 + -892;
	// bl 0x82130000
	ctx.lr = 0x8221C4CC;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C4DC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,2832(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2832);
	// lbz r10,10850(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10850);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221c50c
	if (cr6.eq) goto loc_8221C50C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-944
	ctx.r3.s64 = r11.s64 + -944;
	// bl 0x82130000
	ctx.lr = 0x8221C4FC;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C50C:
	// bl 0x821fec58
	ctx.lr = 0x8221C510;
	sub_821FEC58(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221c538
	if (!cr6.eq) goto loc_8221C538;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-1000
	ctx.r3.s64 = r11.s64 + -1000;
	// bl 0x82130000
	ctx.lr = 0x8221C528;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C538:
	// bl 0x823bc168
	ctx.lr = 0x8221C53C;
	sub_823BC168(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221c564
	if (!cr6.eq) goto loc_8221C564;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-1052
	ctx.r3.s64 = r11.s64 + -1052;
	// bl 0x82130000
	ctx.lr = 0x8221C554;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C564:
	// lwz r11,268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x8221c594
	if (!cr6.lt) goto loc_8221C594;
loc_8221C570:
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r4,268(r31)
	PPC_STORE_U32(r31.u32 + 268, ctx.r4.u32);
	// addi r3,r11,-1096
	ctx.r3.s64 = r11.s64 + -1096;
	// bl 0x82130000
	ctx.lr = 0x8221C584;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C594:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,3528(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lfs f1,31016(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822d52a0
	ctx.lr = 0x8221C5A8;
	sub_822D52A0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8221c60c
	if (!cr6.eq) goto loc_8221C60C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8221c60c
	if (!cr6.lt) goto loc_8221C60C;
	// lfs f12,92(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f0,264(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// fsubs f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 - f0.f64));
	// bl 0x822d5338
	ctx.lr = 0x8221C5DC;
	sub_822D5338(ctx, base);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-1216
	ctx.r3.s64 = r11.s64 + -1216;
	// bl 0x82130000
	ctx.lr = 0x8221C5FC;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C60C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-1288
	ctx.r3.s64 = r11.s64 + -1288;
	// bl 0x82130000
	ctx.lr = 0x8221C618;
	sub_82130000(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-1304
	ctx.r3.s64 = ctx.r10.s64 + -1304;
	// bl 0x821fa230
	ctx.lr = 0x8221C624;
	sub_821FA230(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r8,112(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 112);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8221C638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,96(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8221C650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,64(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8221C668;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-21704
	ctx.r4.s64 = ctx.r10.s64 + -21704;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r29,r11,4
	r29.s64 = r11.s64 + 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r28,4(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82691650
	ctx.lr = 0x8221C688;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8221C69C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x822150d8
	ctx.lr = 0x8221C6A0;
	sub_822150D8(ctx, base);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-12640(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12640);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8221C6BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-10000(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10000);
	// bl 0x823bb5a0
	ctx.lr = 0x8221C6C4;
	sub_823BB5A0(ctx, base);
	// lwz r10,-10236(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r5,5
	ctx.r5.s64 = 327680;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// ori r11,r5,5088
	r11.u64 = ctx.r5.u64 | 5088;
	// li r27,16
	r27.s64 = 16;
	// lwz r6,48(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// add r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 + ctx.r9.u64;
	// li r28,32
	r28.s64 = 32;
	// li r29,48
	r29.s64 = 48;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r7,-1328
	ctx.r4.s64 = ctx.r7.s64 + -1328;
	// lwz r11,-5008(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -5008);
	// addi r11,r11,2544
	r11.s64 = r11.s64 + 2544;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r5,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r5,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r5,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r3,r8
	ctx.r3.u64 = ctx.r3.u64 + ctx.r8.u64;
	// bl 0x82130000
	ctx.lr = 0x8221C730;
	sub_82130000(ctx, base);
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8221c758
	if (!cr6.eq) goto loc_8221C758;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,5
	ctx.r10.s64 = 327680;
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// ori r8,r10,5168
	ctx.r8.u64 = ctx.r10.u64 | 5168;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfsx f0,r7,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// stfs f0,100(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 100, temp.u32);
loc_8221C758:
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82218bf0
	ctx.lr = 0x8221C764;
	sub_82218BF0(ctx, base);
	// bl 0x82322db8
	ctx.lr = 0x8221C768;
	sub_82322DB8(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lis r9,1
	ctx.r9.s64 = 65536;
	// ori r8,r10,12784
	ctx.r8.u64 = ctx.r10.u64 | 12784;
	// ori r7,r9,12788
	ctx.r7.u64 = ctx.r9.u64 | 12788;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r5,r6,1
	ctx.r5.s64 = ctx.r6.s64 + 65536;
	// addis r4,r6,1
	ctx.r4.s64 = ctx.r6.s64 + 65536;
	// addi r5,r5,12656
	ctx.r5.s64 = ctx.r5.s64 + 12656;
	// addi r4,r4,12720
	ctx.r4.s64 = ctx.r4.s64 + 12720;
	// lvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r5,r27
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r4,r27
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r5,r28
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r4,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r5,r29
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r4,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfsx f0,r3,r8
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r8.u32);
	f0.f64 = double(temp.f32);
	// stfsx f0,r3,r7
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, temp.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C7D0:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10000(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10000);
	// addi r5,r11,96
	ctx.r5.s64 = r11.s64 + 96;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lbz r10,3(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8221c7fc
	if (cr6.eq) goto loc_8221C7FC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8221c804
	goto loc_8221C804;
loc_8221C7FC:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
loc_8221C804:
	// bl 0x823c0d10
	ctx.lr = 0x8221C808;
	sub_823C0D10(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stb r26,7(r11)
	PPC_STORE_U8(r11.u32 + 7, r26.u8);
	// lfs f31,-1332(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -1332);
	f31.f64 = double(temp.f32);
	// bl 0x82178848
	ctx.lr = 0x8221C81C;
	sub_82178848(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221c830
	if (cr6.eq) goto loc_8221C830;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f31,-1336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1336);
	f31.f64 = double(temp.f32);
loc_8221C830:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,-10000(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10000);
	// lfs f13,96(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29920(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29920);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fdivs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 / f31.f64));
	// stfs f11,96(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 96, temp.u32);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r4,r11,80
	ctx.r4.s64 = r11.s64 + 80;
	// lbz r9,3(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 3);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221c870
	if (cr6.eq) goto loc_8221C870;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f1,14992(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14992);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8221c888
	goto loc_8221C888;
loc_8221C870:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// lfs f13,27632(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27632);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 * ctx.f13.f64));
loc_8221C888:
	// bl 0x823c0f88
	ctx.lr = 0x8221C88C;
	sub_823C0F88(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// lwz r11,-10028(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,3488
	ctx.r3.s64 = ctx.r3.s64 + 3488;
	// bl 0x822249b8
	ctx.lr = 0x8221C8B0;
	sub_822249B8(ctx, base);
	// li r9,26
	ctx.r9.s64 = 26;
	// stw r9,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r9.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lbz r11,274(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 274);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221c95c
	if (cr6.eq) goto loc_8221C95C;
	// bl 0x823bbf60
	ctx.lr = 0x8221C8D8;
	sub_823BBF60(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221cb90
	if (cr6.eq) goto loc_8221CB90;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-1304
	ctx.r3.s64 = r11.s64 + -1304;
	// bl 0x821fa230
	ctx.lr = 0x8221C8F0;
	sub_821FA230(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,112(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8221C904;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8221C91C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8221C934;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r26,274(r31)
	PPC_STORE_U8(r31.u32 + 274, r26.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221b790
	ctx.lr = 0x8221C940;
	sub_8221B790(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204468
	ctx.lr = 0x8221C94C;
	sub_82204468(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C95C:
	// lbz r11,273(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 273);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221c9d8
	if (cr6.eq) goto loc_8221C9D8;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// addi r5,r11,96
	ctx.r5.s64 = r11.s64 + 96;
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f1,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,-10000(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// bl 0x823c0d10
	ctx.lr = 0x8221C98C;
	sub_823C0D10(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221c9d8
	if (cr6.eq) goto loc_8221C9D8;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-12640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8221C9B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-10000(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// bl 0x823bb5a0
	ctx.lr = 0x8221C9BC;
	sub_823BB5A0(ctx, base);
	// lwz r11,-10000(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10000);
	// stb r26,293(r11)
	PPC_STORE_U8(r11.u32 + 293, r26.u8);
	// stb r28,274(r31)
	PPC_STORE_U8(r31.u32 + 274, r28.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221C9D8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r11,3998
	r31.s64 = r11.s64 + 3998;
	// bl 0x823bb658
	ctx.lr = 0x8221C9E4;
	sub_823BB658(ctx, base);
loc_8221C9E4:
	// lbz r11,0(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// beq cr6,0x8221ca08
	if (cr6.eq) goto loc_8221CA08;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8221c9e4
	if (cr6.eq) goto loc_8221C9E4;
loc_8221CA08:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8221ca2c
	if (!cr6.eq) goto loc_8221CA2C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-1408
	ctx.r3.s64 = r11.s64 + -1408;
	// bl 0x82130000
	ctx.lr = 0x8221CA1C;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221CA2C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-1480
	ctx.r3.s64 = r11.s64 + -1480;
	// bl 0x82130000
	ctx.lr = 0x8221CA38;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lwz r11,268(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 268);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x8221c570
	if (cr6.lt) goto loc_8221C570;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,3528(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3528);
	// lfs f1,31016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822d52a0
	ctx.lr = 0x8221CA68;
	sub_822D52A0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8221cad4
	if (!cr6.eq) goto loc_8221CAD4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 264);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8221cad4
	if (!cr6.lt) goto loc_8221CAD4;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f12,92(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f12
	f0.f64 = double(float(f0.f64 + ctx.f12.f64));
	// stfs f0,264(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 264, temp.u32);
	// fsubs f31,f13,f0
	f31.f64 = double(float(ctx.f13.f64 - f0.f64));
	// bl 0x822d5338
	ctx.lr = 0x8221CAA4;
	sub_822D5338(ctx, base);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// stfd f2,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.f2.u64);
	// ld r5,32(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 32);
	// stfd f1,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f1.u64);
	// ld r4,24(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 24);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r3,r9,-1216
	ctx.r3.s64 = ctx.r9.s64 + -1216;
	// bl 0x82130000
	ctx.lr = 0x8221CAC4;
	sub_82130000(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
loc_8221CAD4:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r10,26
	ctx.r10.s64 = 26;
	// stb r28,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r28.u8);
	// stb r26,7(r11)
	PPC_STORE_U8(r11.u32 + 7, r26.u8);
	// stw r10,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r10,29
	ctx.r10.s64 = 29;
	// stb r28,7(r11)
	PPC_STORE_U8(r11.u32 + 7, r28.u8);
	// stb r28,276(r31)
	PPC_STORE_U8(r31.u32 + 276, r28.u8);
	// stw r10,288(r31)
	PPC_STORE_U32(r31.u32 + 288, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221b790
	ctx.lr = 0x8221CB24;
	sub_8221B790(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r10,22
	ctx.r10.s64 = 22;
	// stb r28,6(r11)
	PPC_STORE_U8(r11.u32 + 6, r28.u8);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r10,12(r9)
	PPC_STORE_U32(ctx.r9.u32 + 12, ctx.r10.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-72(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
	// lbz r11,273(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 273);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221cb8c
	if (cr6.eq) goto loc_8221CB8C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221b790
	ctx.lr = 0x8221CB6C;
	sub_8221B790(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-10236(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lfs f1,176(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,-5008(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5008);
	// addi r4,r11,2544
	ctx.r4.s64 = r11.s64 + 2544;
	// bl 0x82204558
	ctx.lr = 0x8221CB88;
	sub_82204558(ctx, base);
	// stb r28,280(r31)
	PPC_STORE_U8(r31.u32 + 280, r28.u8);
loc_8221CB8C:
	// stb r28,273(r31)
	PPC_STORE_U8(r31.u32 + 273, r28.u8);
loc_8221CB90:
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

PPC_WEAK_FUNC(sub_8221BE98) {
	__imp__sub_8221BE98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CBA0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r8,16(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,-28876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28876);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,1068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 1068);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fmuls f0,f11,f13
	f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CBA0) {
	__imp__sub_8221CBA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CBF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CBF4) {
	__imp__sub_8221CBF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CBF8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r8,17(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 17);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,-28876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28876);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,1068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 1068);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fmuls f0,f11,f13
	f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CBF8) {
	__imp__sub_8221CBF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CC4C) {
	__imp__sub_8221CC4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CC50) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r8,18(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 18);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,-28876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28876);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,1068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 1068);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fmuls f0,f11,f13
	f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CC50) {
	__imp__sub_8221CC50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CCA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CCA4) {
	__imp__sub_8221CCA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CCA8) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r8,19(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 19);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f0,-16(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f0,-28876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28876);
	f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,1068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 1068);
	ctx.f13.f64 = double(temp.f32);
	// lfs f1,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fmuls f0,f11,f13
	f0.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bltlr cr6
	if (cr6.lt) return;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	cr6.compare(f0.f64, ctx.f1.f64);
	// bgtlr cr6
	if (cr6.gt) return;
	// fmr f1,f0
	ctx.f1.f64 = f0.f64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CCA8) {
	__imp__sub_8221CCA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CCFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CCFC) {
	__imp__sub_8221CCFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CD00) {
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
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221CD24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221cd58
	if (cr6.eq) goto loc_8221CD58;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8221cd48
	if (cr6.gt) goto loc_8221CD48;
	// li r11,0
	r11.s64 = 0;
loc_8221CD48:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8221cd5c
	if (cr6.eq) goto loc_8221CD5C;
loc_8221CD58:
	// li r11,0
	r11.s64 = 0;
loc_8221CD5C:
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

PPC_WEAK_FUNC(sub_8221CD00) {
	__imp__sub_8221CD00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CD74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CD74) {
	__imp__sub_8221CD74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CD78) {
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
	ctx.lr = 0x8221CD90;
	sub_8263AD60(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,1092
	ctx.r8.s64 = ctx.r9.s64 + 1092;
	// stw r10,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r10.u32);
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stw r10,64(r31)
	PPC_STORE_U32(r31.u32 + 64, ctx.r10.u32);
	// stb r11,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r11.u8);
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

PPC_WEAK_FUNC(sub_8221CD78) {
	__imp__sub_8221CD78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CDCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CDCC) {
	__imp__sub_8221CDCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CDD0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8221cde8
	if (cr6.gt) goto loc_8221CDE8;
	// li r11,0
	r11.s64 = 0;
loc_8221CDE8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CDD0) {
	__imp__sub_8221CDD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CDF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8221ce08
	if (cr6.gt) goto loc_8221CE08;
	// li r11,0
	r11.s64 = 0;
loc_8221CE08:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CDF0) {
	__imp__sub_8221CDF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CE10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8221ce28
	if (cr6.gt) goto loc_8221CE28;
	// li r11,0
	r11.s64 = 0;
loc_8221CE28:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CE10) {
	__imp__sub_8221CE10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CE30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// xori r10,r11,256
	ctx.r10.u64 = r11.u64 ^ 256;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CE30) {
	__imp__sub_8221CE30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CE40) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,23,23
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x100;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8221ce58
	if (cr6.gt) goto loc_8221CE58;
	// li r11,0
	r11.s64 = 0;
loc_8221CE58:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CE40) {
	__imp__sub_8221CE40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CE60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8221ce78
	if (cr6.gt) goto loc_8221CE78;
	// li r11,0
	r11.s64 = 0;
loc_8221CE78:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CE60) {
	__imp__sub_8221CE60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CE80) {
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
	// clrlwi r30,r4,24
	r30.u64 = ctx.r4.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8221ced4
	if (cr6.eq) goto loc_8221CED4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221CEB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8221cecc
	if (!cr6.eq) goto loc_8221CECC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// ori r10,r11,256
	ctx.r10.u64 = r11.u64 | 256;
	// b 0x8221cefc
	goto loc_8221CEFC;
loc_8221CECC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8221cf00
	if (!cr6.eq) goto loc_8221CF00;
loc_8221CED4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221CEE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221cf00
	if (cr6.eq) goto loc_8221CF00;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,24,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFEFF;
loc_8221CEFC:
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_8221CF00:
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

PPC_WEAK_FUNC(sub_8221CE80) {
	__imp__sub_8221CE80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CF18) {
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
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8221cf6c
	if (cr6.eq) goto loc_8221CF6C;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-22132
	ctx.r6.s64 = r11.s64 + -22132;
	// addi r5,r10,-22108
	ctx.r5.s64 = ctx.r10.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8221CF4C;
	sub_823DEDD8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,468(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 468);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8221CF5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8221CF6C:
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

PPC_WEAK_FUNC(sub_8221CF18) {
	__imp__sub_8221CF18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CF80) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,60(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 60);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CF80) {
	__imp__sub_8221CF80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CF88) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,68(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 68);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CF88) {
	__imp__sub_8221CF88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CF90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,104(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CF90) {
	__imp__sub_8221CF90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CF98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,80(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CF98) {
	__imp__sub_8221CF98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,96(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CFA0) {
	__imp__sub_8221CFA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f1,88(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CFA8) {
	__imp__sub_8221CFA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,100(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CFB0) {
	__imp__sub_8221CFB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,71(r3)
	PPC_STORE_U8(ctx.r3.u32 + 71, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CFB8) {
	__imp__sub_8221CFB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CFC4) {
	__imp__sub_8221CFC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,72(r3)
	PPC_STORE_U8(ctx.r3.u32 + 72, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CFC8) {
	__imp__sub_8221CFC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CFD4) {
	__imp__sub_8221CFD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,73(r3)
	PPC_STORE_U8(ctx.r3.u32 + 73, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CFD8) {
	__imp__sub_8221CFD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221CFE4) {
	__imp__sub_8221CFE4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFE8) {
	PPC_FUNC_PROLOGUE();
	// stw r4,368(r3)
	PPC_STORE_U32(ctx.r3.u32 + 368, ctx.r4.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221CFE8) {
	__imp__sub_8221CFE8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221CFF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,660(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 660);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8221CFF0) {
	__imp__sub_8221CFF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D000) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,176(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D000) {
	__imp__sub_8221D000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D008) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,180(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 180, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D008) {
	__imp__sub_8221D008(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D010) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,184(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 184, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D010) {
	__imp__sub_8221D010(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D018) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,192(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D018) {
	__imp__sub_8221D018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,196(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D020) {
	__imp__sub_8221D020(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D028) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,200(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D028) {
	__imp__sub_8221D028(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,208(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 208, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D030) {
	__imp__sub_8221D030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,212(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 212, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D038) {
	__imp__sub_8221D038(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,216(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 216, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D040) {
	__imp__sub_8221D040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D048) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,224(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 224, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D048) {
	__imp__sub_8221D048(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,228(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 228, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D050) {
	__imp__sub_8221D050(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,232(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 232, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D058) {
	__imp__sub_8221D058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8221d0ac
	if (!cr6.lt) goto loc_8221D0AC;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,800(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 800);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8221D09C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,576(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 576);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221D0AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8221D0AC:
	// lfs f1,76(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
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

PPC_WEAK_FUNC(sub_8221D060) {
	__imp__sub_8221D060(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D0C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,469(r3)
	PPC_STORE_U8(ctx.r3.u32 + 469, r11.u8);
	// stb r10,468(r3)
	PPC_STORE_U8(ctx.r3.u32 + 468, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D0C8) {
	__imp__sub_8221D0C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D0DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D0DC) {
	__imp__sub_8221D0DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D0E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r11,469(r3)
	PPC_STORE_U8(ctx.r3.u32 + 469, r11.u8);
	// stb r10,468(r3)
	PPC_STORE_U8(ctx.r3.u32 + 468, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D0E0) {
	__imp__sub_8221D0E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D0F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D0F4) {
	__imp__sub_8221D0F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D0F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stb r11,469(r3)
	PPC_STORE_U8(ctx.r3.u32 + 469, r11.u8);
	// stb r11,468(r3)
	PPC_STORE_U8(ctx.r3.u32 + 468, r11.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D0F8) {
	__imp__sub_8221D0F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D108) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,471(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 471);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221d128
	if (cr6.eq) goto loc_8221D128;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,80(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,32688(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32688);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// blr 
	return;
loc_8221D128:
	// lfs f1,80(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D108) {
	__imp__sub_8221D108(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D130) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,471(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 471);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221d150
	if (cr6.eq) goto loc_8221D150;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,32688(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32688);
	f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * f0.f64));
	// blr 
	return;
loc_8221D150:
	// lfs f1,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D130) {
	__imp__sub_8221D130(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D158) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r31,544
	ctx.r3.s64 = r31.s64 + 544;
	// addi r10,r11,5124
	ctx.r10.s64 = r11.s64 + 5124;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82585de8
	ctx.lr = 0x8221D188;
	sub_82585DE8(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,2700
	ctx.r8.s64 = ctx.r9.s64 + 2700;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// bl 0x826375a0
	ctx.lr = 0x8221D19C;
	sub_826375A0(ctx, base);
	// clrlwi r7,r30,31
	ctx.r7.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8221d1b4
	if (cr6.eq) goto loc_8221D1B4;
	// bl 0x82130588
	ctx.lr = 0x8221D1B0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8221D1B4:
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

PPC_WEAK_FUNC(sub_8221D158) {
	__imp__sub_8221D158(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D1CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D1CC) {
	__imp__sub_8221D1CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D1D0) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,5996
	ctx.r10.s64 = r11.s64 + 5996;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826375a0
	ctx.lr = 0x8221D1FC;
	sub_826375A0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221d214
	if (cr6.eq) goto loc_8221D214;
	// bl 0x82130588
	ctx.lr = 0x8221D210;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8221D214:
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

PPC_WEAK_FUNC(sub_8221D1D0) {
	__imp__sub_8221D1D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D22C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D22C) {
	__imp__sub_8221D22C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D230) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,80
	ctx.r3.s64 = ctx.r3.s64 + 80;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D230) {
	__imp__sub_8221D230(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D238) {
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
	// bl 0x82637538
	ctx.lr = 0x8221D250;
	sub_82637538(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,7132
	ctx.r9.s64 = ctx.r10.s64 + 7132;
	// stw r11,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r11,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r11.u32);
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

PPC_WEAK_FUNC(sub_8221D238) {
	__imp__sub_8221D238(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D280) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,144(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D280) {
	__imp__sub_8221D280(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D288) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,7716
	ctx.r10.s64 = r11.s64 + 7716;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826375a0
	ctx.lr = 0x8221D2B4;
	sub_826375A0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8221d2cc
	if (cr6.eq) goto loc_8221D2CC;
	// bl 0x82130588
	ctx.lr = 0x8221D2C8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8221D2CC:
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

PPC_WEAK_FUNC(sub_8221D288) {
	__imp__sub_8221D288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D2E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D2E4) {
	__imp__sub_8221D2E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D2E8) {
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,8844
	ctx.r9.s64 = r11.s64 + 8844;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8221d31c
	if (cr6.eq) goto loc_8221D31C;
	// bl 0x82130588
	ctx.lr = 0x8221D318;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8221D31C:
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

PPC_WEAK_FUNC(sub_8221D2E8) {
	__imp__sub_8221D2E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D330) {
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
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// li r11,-1
	r11.s64 = -1;
	// addi r8,r10,8844
	ctx.r8.s64 = ctx.r10.s64 + 8844;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// addi r7,r9,3998
	ctx.r7.s64 = ctx.r9.s64 + 3998;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// stw r7,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r7.u32);
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r30.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stw r30,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r30.u32);
	// stw r30,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r30.u32);
	// bl 0x82637538
	ctx.lr = 0x8221D394;
	sub_82637538(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r3,r6,6548
	ctx.r3.s64 = ctx.r6.s64 + 6548;
	// addi r11,r5,9456
	r11.s64 = ctx.r5.s64 + 9456;
	// addi r10,r4,8876
	ctx.r10.s64 = ctx.r4.s64 + 8876;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r10.u32);
	// stb r30,192(r31)
	PPC_STORE_U8(r31.u32 + 192, r30.u8);
	// stw r30,196(r31)
	PPC_STORE_U32(r31.u32 + 196, r30.u32);
	// stb r30,200(r31)
	PPC_STORE_U8(r31.u32 + 200, r30.u8);
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

PPC_WEAK_FUNC(sub_8221D330) {
	__imp__sub_8221D330(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D3E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8221d400
	if (cr6.eq) goto loc_8221D400;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_8221D400:
	// b 0x8221cdd0
	sub_8221CDD0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_8221D3E0) {
	__imp__sub_8221D3E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D404) {
	__imp__sub_8221D404(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D408) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

PPC_WEAK_FUNC(sub_8221D408) {
	__imp__sub_8221D408(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D41C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D41C) {
	__imp__sub_8221D41C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D420) {
	PPC_FUNC_PROLOGUE();
	// stw r4,148(r3)
	PPC_STORE_U32(ctx.r3.u32 + 148, ctx.r4.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D420) {
	__imp__sub_8221D420(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addic. r30,r31,80
	xer.ca = r31.u32 > 4294967215;
	r30.s64 = r31.s64 + 80;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r10,r11,9484
	ctx.r10.s64 = r11.s64 + 9484;
	// addi r3,r30,48
	ctx.r3.s64 = r30.s64 + 48;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bne 0x8221d45c
	if (!cr0.eq) goto loc_8221D45C;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8221D45C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r11,6548
	ctx.r10.s64 = r11.s64 + 6548;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// bl 0x826375a0
	ctx.lr = 0x8221D46C;
	sub_826375A0(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r7,r9,8844
	ctx.r7.s64 = ctx.r9.s64 + 8844;
	// addi r6,r8,7716
	ctx.r6.s64 = ctx.r8.s64 + 7716;
	// stw r7,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// bl 0x826375a0
	ctx.lr = 0x8221D48C;
	sub_826375A0(ctx, base);
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

PPC_WEAK_FUNC(sub_8221D428) {
	__imp__sub_8221D428(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D4A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D4A4) {
	__imp__sub_8221D4A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D4A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addic. r11,r3,80
	xer.ca = ctx.r3.u32 > 4294967215;
	r11.s64 = ctx.r3.s64 + 80;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// bnelr 
	if (!cr0.eq) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D4A8) {
	__imp__sub_8221D4A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D4BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D4BC) {
	__imp__sub_8221D4BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D4C0) {
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
	// bl 0x8221d428
	ctx.lr = 0x8221D4E0;
	sub_8221D428(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221d4f8
	if (cr6.eq) goto loc_8221D4F8;
	// bl 0x82130588
	ctx.lr = 0x8221D4F4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8221D4F8:
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

PPC_WEAK_FUNC(sub_8221D4C0) {
	__imp__sub_8221D4C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D510) {
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
	// bl 0x82637538
	ctx.lr = 0x8221D528;
	sub_82637538(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,10068
	ctx.r9.s64 = ctx.r10.s64 + 10068;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// stb r11,73(r31)
	PPC_STORE_U8(r31.u32 + 73, r11.u8);
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
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

PPC_WEAK_FUNC(sub_8221D510) {
	__imp__sub_8221D510(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D560) {
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
	ctx.lr = 0x8221D568;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r7,r11,15020
	ctx.r7.s64 = r11.s64 + 15020;
	// addi r6,r10,-19304
	ctx.r6.s64 = ctx.r10.s64 + -19304;
	// addi r5,r9,-19624
	ctx.r5.s64 = ctx.r9.s64 + -19624;
	// stw r7,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r7.u32);
	// addi r4,r8,15012
	ctx.r4.s64 = ctx.r8.s64 + 15012;
	// stw r6,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r6.u32);
	// li r24,0
	r24.s64 = 0;
	// stw r5,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r5.u32);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// addi r28,r31,20
	r28.s64 = r31.s64 + 20;
	// stb r24,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r24.u8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8260b730
	ctx.lr = 0x8221D5B8;
	sub_8260B730(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r30,796(r31)
	PPC_STORE_U32(r31.u32 + 796, r30.u32);
	// addi r27,r11,-6984
	r27.s64 = r11.s64 + -6984;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stb r3,800(r31)
	PPC_STORE_U8(r31.u32 + 800, ctx.r3.u8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r29,r24
	r29.u64 = r24.u64;
	// mr r30,r27
	r30.u64 = r27.u64;
	// addi r26,r11,-19200
	r26.s64 = r11.s64 + -19200;
	// addi r25,r10,-19296
	r25.s64 = ctx.r10.s64 + -19296;
loc_8221D5E4:
	// li r7,-1
	ctx.r7.s64 = -1;
	// lwzx r5,r29,r25
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + r25.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lwzx r4,r29,r26
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r26.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8260b740
	ctx.lr = 0x8221D5FC;
	sub_8260B740(ctx, base);
	// addi r30,r30,12
	r30.s64 = r30.s64 + 12;
	// addi r11,r27,288
	r11.s64 = r27.s64 + 288;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x8221d5e4
	if (!cr6.eq) goto loc_8221D5E4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stb r24,801(r31)
	PPC_STORE_U8(r31.u32 + 801, r24.u8);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stb r24,802(r31)
	PPC_STORE_U8(r31.u32 + 802, r24.u8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,6
	ctx.r8.s64 = 6;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f0,15004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 15004);
	f0.f64 = double(temp.f32);
	// stb r8,803(r31)
	PPC_STORE_U8(r31.u32 + 803, ctx.r8.u8);
	// lfs f13,15000(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 15000);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,801
	r11.s64 = r31.s64 + 801;
	// lfs f12,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,804(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 804, temp.u32);
	// stfs f13,808(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 808, temp.u32);
	// stfs f12,812(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 812, temp.u32);
	// bl 0x82388598
	ctx.lr = 0x8221D650;
	sub_82388598(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_8221D560) {
	__imp__sub_8221D560(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D660) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	PPCRegister temp{};
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// addi r10,r10,-6984
	ctx.r10.s64 = ctx.r10.s64 + -6984;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lbz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 2);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// xor r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 ^ ctx.r8.u64;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// subfic r5,r6,127
	xer.ca = ctx.r6.u32 <= 127;
	ctx.r5.s64 = 127 - ctx.r6.s64;
	// subfe r4,r5,r5
	temp.u8 = (~ctx.r5.u32 + ctx.r5.u32 < ~ctx.r5.u32) | (~ctx.r5.u32 + ctx.r5.u32 + xer.ca < xer.ca);
	ctx.r4.u64 = ~ctx.r5.u64 + ctx.r5.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r3,r4,31
	ctx.r3.u64 = ctx.r4.u32 & 0x1;
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D660) {
	__imp__sub_8221D660(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D6A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D6A4) {
	__imp__sub_8221D6A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D6A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r11,r11,-7012
	r11.s64 = r11.s64 + -7012;
	// li r10,24
	ctx.r10.s64 = 24;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8221D6BC:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8221d6bc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8221D6BC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r11,r11,-7040
	r11.s64 = r11.s64 + -7040;
	// li r10,24
	ctx.r10.s64 = 24;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_8221D6DC:
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8221d6dc
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8221D6DC;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D6A8) {
	__imp__sub_8221D6A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D6EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D6EC) {
	__imp__sub_8221D6EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D6F0) {
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
	ctx.lr = 0x8221D6F8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8221d790
	if (cr6.eq) goto loc_8221D790;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r27,16
	r27.s64 = 16;
	// li r28,32
	r28.s64 = 32;
	// li r29,48
	r29.s64 = 48;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8221d76c
	if (cr6.eq) goto loc_8221D76C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8221D730;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8221d76c
	if (cr6.eq) goto loc_8221D76C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8221D748;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x8221D74C;
	sub_822A8108(ctx, base);
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r3,r27
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r28
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r29
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8221D76C:
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
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
	// vpermwi128 v57,v58,234
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x15));
	// vpermwi128 v56,v58,186
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x45));
	// vpermwi128 v55,v58,174
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0x51));
	// stvx128 v57,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8221D790:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_8221D6F0) {
	__imp__sub_8221D6F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D798) {
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
	ctx.lr = 0x8221D7A0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x8221d7d0
	if (!cr6.eq) goto loc_8221D7D0;
	// addis r3,r29,4
	ctx.r3.s64 = r29.s64 + 262144;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r3,960
	ctx.r3.s64 = ctx.r3.s64 + 960;
	// bl 0x8268ee10
	ctx.lr = 0x8221D7C8;
	sub_8268EE10(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8221D7D0:
	// addi r31,r29,4
	r31.s64 = r29.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x8221D7DC;
	sub_82691650(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8221d81c
	if (cr6.eq) goto loc_8221D81C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bne cr6,0x8221d7f8
	if (!cr6.eq) goto loc_8221D7F8;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8221D7F8:
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r3,r29,776
	ctx.r3.s64 = r29.s64 + 776;
	// bl 0x8268f6a8
	ctx.lr = 0x8221D804;
	sub_8268F6A8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8221D81C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8221D81C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_8221D798) {
	__imp__sub_8221D798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D824) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D824) {
	__imp__sub_8221D824(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D828) {
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
	// bl 0x82130000
	ctx.lr = 0x8221D840;
	sub_82130000(ctx, base);
	// lis r11,4
	r11.s64 = 262144;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,2132
	r11.u64 = r11.u64 | 2132;
	// stbx r10,r31,r11
	PPC_STORE_U8(r31.u32 + r11.u32, ctx.r10.u8);
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

PPC_WEAK_FUNC(sub_8221D828) {
	__imp__sub_8221D828(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D864) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D864) {
	__imp__sub_8221D864(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D868) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x8221d880
	if (!cr6.eq) goto loc_8221D880;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8221D880:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x8221d89c
	if (!cr6.eq) goto loc_8221D89C;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_8221D89C:
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// stw r7,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D868) {
	__imp__sub_8221D868(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D8C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x8221d8d8
	if (!cr6.eq) goto loc_8221D8D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8221D8D8:
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r8,r11
	PPC_STORE_U32(ctx.r8.u32 + r11.u32, ctx.r9.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x8221d904
	if (!cr6.eq) goto loc_8221D904;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
loc_8221D904:
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D8C0) {
	__imp__sub_8221D8C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D918) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,20(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r4,1
	r11.s64 = ctx.r4.s64 + 1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8221d990
	if (!cr6.lt) goto loc_8221D990;
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// ori r10,r10,21846
	ctx.r10.u64 = ctx.r10.u64 | 21846;
loc_8221D930:
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r5,r9,1
	ctx.r5.s64 = ctx.r9.s64 + 1;
	// mr r4,r9
	ctx.r4.u64 = ctx.r9.u64;
	// mulhw r9,r5,r10
	ctx.r9.s64 = (int64_t(ctx.r5.s32) * int64_t(ctx.r10.s32)) >> 32;
	// rlwinm r7,r9,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0x1;
	// mulhw r8,r4,r10
	ctx.r8.s64 = (int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32)) >> 32;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// rlwinm r7,r8,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0x1;
	// rlwinm r6,r9,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r7,r9,r6
	ctx.r7.u64 = ctx.r9.u64 + ctx.r6.u64;
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r7,r5
	ctx.r6.s64 = ctx.r5.s64 - ctx.r7.s64;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r5,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r5.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r6,r9,r3
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r3.u32);
	// stwx r6,r7,r3
	PPC_STORE_U32(ctx.r7.u32 + ctx.r3.u32, ctx.r6.u32);
	// lwz r5,20(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// blt cr6,0x8221d930
	if (cr6.lt) goto loc_8221D930;
loc_8221D990:
	// lwz r11,20(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8221d9b4
	if (!cr6.eq) goto loc_8221D9B4;
	// li r11,2
	r11.s64 = 2;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
loc_8221D9B4:
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D918) {
	__imp__sub_8221D918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D9C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lhz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_8221D9C0) {
	__imp__sub_8221D9C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8221D9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8221D9CC) {
	__imp__sub_8221D9CC(ctx, base);
}

