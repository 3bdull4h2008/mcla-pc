#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8270BFBC"))) PPC_WEAK_FUNC(sub_8270BFBC);
PPC_FUNC_IMPL(__imp__sub_8270BFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270BFC0"))) PPC_WEAK_FUNC(sub_8270BFC0);
PPC_FUNC_IMPL(__imp__sub_8270BFC0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r11,27988
	ctx.r9.s64 = r11.s64 + 27988;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lwz r11,-10028(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10028);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270bffc
	if (cr6.eq) goto loc_8270BFFC;
	// addi r4,r31,928
	ctx.r4.s64 = r31.s64 + 928;
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// bl 0x82238140
	ctx.lr = 0x8270BFFC;
	sub_82238140(ctx, base);
loc_8270BFFC:
	// lwz r4,864(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8270c014
	if (cr6.lt) goto loc_8270C014;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// bl 0x826fd8a0
	ctx.lr = 0x8270C014;
	sub_826FD8A0(ctx, base);
loc_8270C014:
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// bl 0x822378e8
	ctx.lr = 0x8270C01C;
	sub_822378E8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fc6b8
	ctx.lr = 0x8270C024;
	sub_826FC6B8(ctx, base);
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

__attribute__((alias("__imp__sub_8270C038"))) PPC_WEAK_FUNC(sub_8270C038);
PPC_FUNC_IMPL(__imp__sub_8270C038) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,896
	ctx.r8.s64 = 896;
	// li r7,912
	ctx.r7.s64 = 912;
	// lfs f0,11412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11412);
	f0.f64 = double(temp.f32);
	// li r6,1088
	ctx.r6.s64 = 1088;
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// li r11,0
	r11.s64 = 0;
	// lvlx128 v62,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v61,v62,0
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stfs f0,1116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1116, temp.u32);
	// stfs f0,1112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1112, temp.u32);
	// stb r10,872(r3)
	PPC_STORE_U8(ctx.r3.u32 + 872, ctx.r10.u8);
	// stfs f0,1108(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1108, temp.u32);
	// stb r11,880(r3)
	PPC_STORE_U8(ctx.r3.u32 + 880, r11.u8);
	// stfs f0,1104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1104, temp.u32);
	// stb r10,1073(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1073, ctx.r10.u8);
	// stfs f0,1144(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1144, temp.u32);
	// stb r10,1072(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1072, ctx.r10.u8);
	// stfs f0,1140(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1140, temp.u32);
	// stb r11,1074(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1074, r11.u8);
	// stfs f0,1136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1136, temp.u32);
	// stw r11,1076(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1076, r11.u32);
	// stfs f0,1132(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1132, temp.u32);
	// stw r9,1120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1120, ctx.r9.u32);
	// stfs f0,1128(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1128, temp.u32);
	// stw r9,1124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1124, ctx.r9.u32);
	// stvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r10,1148(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1148, ctx.r10.u8);
	// stvx128 v63,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,1152(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1152, r11.u32);
	// stb r11,1156(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1156, r11.u8);
	// stvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,1157(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1157, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C0D8"))) PPC_WEAK_FUNC(sub_8270C0D8);
PPC_FUNC_IMPL(__imp__sub_8270C0D8) {
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
	// bl 0x826fc9f0
	ctx.lr = 0x8270C0F0;
	sub_826FC9F0(ctx, base);
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270c11c
	if (!cr6.eq) goto loc_8270C11C;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270c11c
	if (cr6.eq) goto loc_8270C11C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270c11c
	if (cr6.eq) goto loc_8270C11C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,819(r11)
	PPC_STORE_U8(r11.u32 + 819, ctx.r10.u8);
loc_8270C11C:
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

__attribute__((alias("__imp__sub_8270C130"))) PPC_WEAK_FUNC(sub_8270C130);
PPC_FUNC_IMPL(__imp__sub_8270C130) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270c204
	if (cr6.eq) goto loc_8270C204;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c204
	if (cr6.eq) goto loc_8270C204;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c204
	if (cr6.eq) goto loc_8270C204;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8270c174
	if (!cr6.eq) goto loc_8270C174;
	// li r11,0
	r11.s64 = 0;
loc_8270C174:
	// lbz r11,304(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 304);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c204
	if (cr6.eq) goto loc_8270C204;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270c19c
	if (cr6.eq) goto loc_8270C19C;
	// addi r11,r10,272
	r11.s64 = ctx.r10.s64 + 272;
	// b 0x8270c1a4
	goto loc_8270C1A4;
loc_8270C19C:
	// lwz r11,28(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_8270C1A4:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// li r7,32
	ctx.r7.s64 = 32;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,48
	ctx.r5.s64 = 48;
	// lvx128 v62,r11,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// stvx128 v62,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r11,r5
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-7572(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7572);
	// lfs f0,3732(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// bl 0x822f1368
	ctx.lr = 0x8270C204;
	sub_822F1368(ctx, base);
loc_8270C204:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C214"))) PPC_WEAK_FUNC(sub_8270C214);
PPC_FUNC_IMPL(__imp__sub_8270C214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270C218"))) PPC_WEAK_FUNC(sub_8270C218);
PPC_FUNC_IMPL(__imp__sub_8270C218) {
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
	// bl 0x822a91a0
	ctx.lr = 0x8270C230;
	sub_822A91A0(ctx, base);
	// lwz r11,1152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1152);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8270c258
	if (!cr6.eq) goto loc_8270C258;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7f10
	ctx.lr = 0x8270C248;
	sub_822A7F10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e38
	ctx.lr = 0x8270C250;
	sub_822A8E38(ctx, base);
	// li r11,2
	r11.s64 = 2;
	// stw r11,1152(r31)
	PPC_STORE_U32(r31.u32 + 1152, r11.u32);
loc_8270C258:
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

__attribute__((alias("__imp__sub_8270C26C"))) PPC_WEAK_FUNC(sub_8270C26C);
PPC_FUNC_IMPL(__imp__sub_8270C26C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270C270"))) PPC_WEAK_FUNC(sub_8270C270);
PPC_FUNC_IMPL(__imp__sub_8270C270) {
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
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r4,864(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 864);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8270c2a0
	if (cr6.lt) goto loc_8270C2A0;
	// lwz r3,-24400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24400);
	// bl 0x826fd8a0
	ctx.lr = 0x8270C2A0;
	sub_826FD8A0(ctx, base);
loc_8270C2A0:
	// lwz r3,-24400(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24400);
	// bl 0x826fdb10
	ctx.lr = 0x8270C2A8;
	sub_826FDB10(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// stw r3,864(r30)
	PPC_STORE_U32(r30.u32 + 864, ctx.r3.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
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

__attribute__((alias("__imp__sub_8270C2D4"))) PPC_WEAK_FUNC(sub_8270C2D4);
PPC_FUNC_IMPL(__imp__sub_8270C2D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270C2D8"))) PPC_WEAK_FUNC(sub_8270C2D8);
PPC_FUNC_IMPL(__imp__sub_8270C2D8) {
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
	// lwz r11,864(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x8270c2fc
	if (!cr6.lt) goto loc_8270C2FC;
	// bl 0x8270c270
	ctx.lr = 0x8270C2FC;
	sub_8270C270(ctx, base);
loc_8270C2FC:
	// lwz r4,864(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 864);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge cr6,0x8270c320
	if (!cr6.lt) goto loc_8270C320;
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
loc_8270C320:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// bl 0x826fdc40
	ctx.lr = 0x8270C32C;
	sub_826FDC40(ctx, base);
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

__attribute__((alias("__imp__sub_8270C340"))) PPC_WEAK_FUNC(sub_8270C340);
PPC_FUNC_IMPL(__imp__sub_8270C340) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r4,864(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 864);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8270c358
	if (cr6.lt) goto loc_8270C358;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// b 0x826fd8d8
	sub_826FD8D8(ctx, base);
	return;
loc_8270C358:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C360"))) PPC_WEAK_FUNC(sub_8270C360);
PPC_FUNC_IMPL(__imp__sub_8270C360) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,876(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c374
	if (cr6.eq) goto loc_8270C374;
	// lwz r3,568(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 568);
	// blr 
	return;
loc_8270C374:
	// lwz r11,1076(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1076);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r3,r9,0,30,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C388"))) PPC_WEAK_FUNC(sub_8270C388);
PPC_FUNC_IMPL(__imp__sub_8270C388) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,876(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c3a8
	if (cr6.eq) goto loc_8270C3A8;
	// lwz r11,568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 568);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// blr 
	return;
loc_8270C3A8:
	// lwz r11,1076(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1076);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C3C8"))) PPC_WEAK_FUNC(sub_8270C3C8);
PPC_FUNC_IMPL(__imp__sub_8270C3C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,876(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c3dc
	if (cr6.eq) goto loc_8270C3DC;
	// lwz r3,576(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// blr 
	return;
loc_8270C3DC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C3E4"))) PPC_WEAK_FUNC(sub_8270C3E4);
PPC_FUNC_IMPL(__imp__sub_8270C3E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270C3E8"))) PPC_WEAK_FUNC(sub_8270C3E8);
PPC_FUNC_IMPL(__imp__sub_8270C3E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,876(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c3fc
	if (cr6.eq) goto loc_8270C3FC;
	// lbz r3,774(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 774);
	// blr 
	return;
loc_8270C3FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C404"))) PPC_WEAK_FUNC(sub_8270C404);
PPC_FUNC_IMPL(__imp__sub_8270C404) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270C408"))) PPC_WEAK_FUNC(sub_8270C408);
PPC_FUNC_IMPL(__imp__sub_8270C408) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r30,r4,24
	r30.u64 = ctx.r4.u32 & 0xFF;
	// lbz r11,880(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 880);
	// cmplw cr6,r11,r30
	cr6.compare<uint32_t>(r11.u32, r30.u32, xer);
	// beq cr6,0x8270c4f8
	if (cr6.eq) goto loc_8270C4F8;
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// stb r4,880(r31)
	PPC_STORE_U8(r31.u32 + 880, ctx.r4.u8);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stb r10,1073(r31)
	PPC_STORE_U8(r31.u32 + 1073, ctx.r10.u8);
	// stb r10,1072(r31)
	PPC_STORE_U8(r31.u32 + 1072, ctx.r10.u8);
	// bl 0x822a8108
	ctx.lr = 0x8270C448;
	sub_822A8108(ctx, base);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// li r8,16
	ctx.r8.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r6,32
	ctx.r6.s64 = 32;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lvx128 v62,r3,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,896
	r11.s64 = r31.s64 + 896;
	// stvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r6
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x8270c484
	if (!cr6.eq) goto loc_8270C484;
	// addi r11,r31,912
	r11.s64 = r31.s64 + 912;
loc_8270C484:
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8270c4b0
	if (cr6.eq) goto loc_8270C4B0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r31,928
	ctx.r4.s64 = r31.s64 + 928;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// bl 0x82238140
	ctx.lr = 0x8270C4AC;
	sub_82238140(ctx, base);
	// b 0x8270c4cc
	goto loc_8270C4CC;
loc_8270C4B0:
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270c4cc
	if (cr6.eq) goto loc_8270C4CC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270C4CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8270C4CC:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r5,r11,2272
	ctx.r5.s64 = r11.s64 + 2272;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f2,30712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x8270C4F8;
	sub_822A9930(ctx, base);
loc_8270C4F8:
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

__attribute__((alias("__imp__sub_8270C510"))) PPC_WEAK_FUNC(sub_8270C510);
PPC_FUNC_IMPL(__imp__sub_8270C510) {
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
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c580
	if (cr6.eq) goto loc_8270C580;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,-5460(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -5460);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270C54C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270c580
	if (cr6.eq) goto loc_8270C580;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r10,1708(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1708);
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
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8270C580:
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

__attribute__((alias("__imp__sub_8270C598"))) PPC_WEAK_FUNC(sub_8270C598);
PPC_FUNC_IMPL(__imp__sub_8270C598) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// stw r4,1120(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1120, ctx.r4.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// stw r5,1124(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1124, ctx.r5.u32);
	// bltlr cr6
	if (cr6.lt) return;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,-13624
	ctx.r10.s64 = r11.s64 + -13624;
	// lfs f0,316(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 316);
	f0.f64 = double(temp.f32);
	// stfs f0,1128(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1128, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C5BC"))) PPC_WEAK_FUNC(sub_8270C5BC);
PPC_FUNC_IMPL(__imp__sub_8270C5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270C5C0"))) PPC_WEAK_FUNC(sub_8270C5C0);
PPC_FUNC_IMPL(__imp__sub_8270C5C0) {
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
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c624
	if (cr6.eq) goto loc_8270C624;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270c624
	if (cr6.eq) goto loc_8270C624;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270c624
	if (cr6.eq) goto loc_8270C624;
	// bl 0x8234a000
	ctx.lr = 0x8270C5FC;
	sub_8234A000(ctx, base);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r6,868(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 868);
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// addi r5,r10,28188
	ctx.r5.s64 = ctx.r10.s64 + 28188;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,344(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 344);
	f0.f64 = double(temp.f32);
	// stfs f0,1136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1136, temp.u32);
	// bl 0x82130000
	ctx.lr = 0x8270C624;
	sub_82130000(ctx, base);
loc_8270C624:
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

__attribute__((alias("__imp__sub_8270C638"))) PPC_WEAK_FUNC(sub_8270C638);
PPC_FUNC_IMPL(__imp__sub_8270C638) {
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
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c74c
	if (cr6.eq) goto loc_8270C74C;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r11,r11,3796
	r11.s64 = r11.s64 + 3796;
	// lfs f31,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f31.f64 = double(temp.f32);
	// beq cr6,0x8270c708
	if (cr6.eq) goto loc_8270C708;
	// lfs f0,1140(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1140);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x8270c740
	if (!cr6.eq) goto loc_8270C740;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2192
	ctx.r7.s64 = ctx.r9.s64 + 2192;
	// ori r6,r8,64167
	ctx.r6.u64 = ctx.r8.u64 | 64167;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r8,2192(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2192);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// addi r3,r5,-13624
	ctx.r3.s64 = ctx.r5.s64 + -13624;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r8,r6
	ctx.r10.s64 = ctx.r8.s64 * ctx.r6.s64;
	// lfs f13,14348(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14348);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,340(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 340);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// clrlwi r3,r11,9
	ctx.r3.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// addi r5,r5,28236
	ctx.r5.s64 = ctx.r5.s64 + 28236;
	// lwz r6,868(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 868);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fmuls f1,f9,f13
	ctx.f1.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfd f1,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f1.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfs f1,1140(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1140, temp.u32);
	// bl 0x82130000
	ctx.lr = 0x8270C704;
	sub_82130000(ctx, base);
	// b 0x8270c740
	goto loc_8270C740;
loc_8270C708:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stfs f31,1140(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1140, temp.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270c728
	if (cr6.eq) goto loc_8270C728;
	// lwz r3,16(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270c728
	if (cr6.eq) goto loc_8270C728;
	// bl 0x8234a180
	ctx.lr = 0x8270C728;
	sub_8234A180(ctx, base);
loc_8270C728:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r6,868(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 868);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r11,28212
	ctx.r5.s64 = r11.s64 + 28212;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x8270C740;
	sub_82130000(ctx, base);
loc_8270C740:
	// li r11,1
	r11.s64 = 1;
	// stfs f31,1144(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1144, temp.u32);
	// stb r11,1074(r31)
	PPC_STORE_U8(r31.u32 + 1074, r11.u8);
loc_8270C74C:
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

__attribute__((alias("__imp__sub_8270C764"))) PPC_WEAK_FUNC(sub_8270C764);
PPC_FUNC_IMPL(__imp__sub_8270C764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270C768"))) PPC_WEAK_FUNC(sub_8270C768);
PPC_FUNC_IMPL(__imp__sub_8270C768) {
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
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c7d4
	if (cr6.eq) goto loc_8270C7D4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270c7bc
	if (cr6.eq) goto loc_8270C7BC;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270c7bc
	if (cr6.eq) goto loc_8270C7BC;
	// bl 0x8234a280
	ctx.lr = 0x8270C7A4;
	sub_8234A280(ctx, base);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r6,868(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 868);
	// addi r5,r11,28276
	ctx.r5.s64 = r11.s64 + 28276;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x8270C7BC;
	sub_82130000(ctx, base);
loc_8270C7BC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,1074(r31)
	PPC_STORE_U8(r31.u32 + 1074, ctx.r10.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,1144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1144, temp.u32);
	// stfs f0,1140(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1140, temp.u32);
loc_8270C7D4:
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

__attribute__((alias("__imp__sub_8270C7E8"))) PPC_WEAK_FUNC(sub_8270C7E8);
PPC_FUNC_IMPL(__imp__sub_8270C7E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lbz r11,872(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8270c82c
	if (!cr6.eq) goto loc_8270C82C;
	// li r11,0
	r11.s64 = 0;
loc_8270C82C:
	// lbz r11,304(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 304);
	// clrlwi r9,r4,24
	ctx.r9.u64 = ctx.r4.u32 & 0xFF;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x8270c850
	if (!cr6.eq) goto loc_8270C850;
	// li r11,0
	r11.s64 = 0;
loc_8270C850:
	// stb r4,304(r11)
	PPC_STORE_U8(r11.u32 + 304, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C858"))) PPC_WEAK_FUNC(sub_8270C858);
PPC_FUNC_IMPL(__imp__sub_8270C858) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270c8ac
	if (cr6.eq) goto loc_8270C8AC;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270c8ac
	if (cr6.eq) goto loc_8270C8AC;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270c8ac
	if (cr6.eq) goto loc_8270C8AC;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,128(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,164(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 164);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8270C8AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8270C8AC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C8BC"))) PPC_WEAK_FUNC(sub_8270C8BC);
PPC_FUNC_IMPL(__imp__sub_8270C8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270C8C0"))) PPC_WEAK_FUNC(sub_8270C8C0);
PPC_FUNC_IMPL(__imp__sub_8270C8C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lbz r11,880(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270c94c
	if (!cr6.eq) goto loc_8270C94C;
	// lwz r11,876(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c8ec
	if (cr6.eq) goto loc_8270C8EC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 584);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8270c94c
	if (cr6.gt) goto loc_8270C94C;
loc_8270C8EC:
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270c940
	if (cr6.eq) goto loc_8270C940;
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270c940
	if (cr6.eq) goto loc_8270C940;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f0,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8270c920
	if (cr6.lt) goto loc_8270C920;
	// li r11,1
	r11.s64 = 1;
loc_8270C920:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270c940
	if (cr6.eq) goto loc_8270C940;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,44(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8270c94c
	if (!cr6.gt) goto loc_8270C94C;
loc_8270C940:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_8270C94C:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270C958"))) PPC_WEAK_FUNC(sub_8270C958);
PPC_FUNC_IMPL(__imp__sub_8270C958) {
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
	// lwz r11,1152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8270c9dc
	if (!cr6.eq) goto loc_8270C9DC;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270c9c0
	if (cr6.eq) goto loc_8270C9C0;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r4,-5460(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -5460);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270C99C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270c9c0
	if (cr6.eq) goto loc_8270C9C0;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r10,1708(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 1708);
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// bne cr6,0x8270c9c0
	if (!cr6.eq) goto loc_8270C9C0;
	// li r11,1
	r11.s64 = 1;
	// b 0x8270c9d8
	goto loc_8270C9D8;
loc_8270C9C0:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7f10
	ctx.lr = 0x8270C9CC;
	sub_822A7F10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e38
	ctx.lr = 0x8270C9D4;
	sub_822A8E38(ctx, base);
	// li r11,2
	r11.s64 = 2;
loc_8270C9D8:
	// stw r11,1152(r31)
	PPC_STORE_U32(r31.u32 + 1152, r11.u32);
loc_8270C9DC:
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

__attribute__((alias("__imp__sub_8270C9F0"))) PPC_WEAK_FUNC(sub_8270C9F0);
PPC_FUNC_IMPL(__imp__sub_8270C9F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,1076(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1076);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ca4c
	if (cr6.eq) goto loc_8270CA4C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,68(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r11,-13624
	ctx.r8.s64 = r11.s64 + -13624;
	// stw r9,1076(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1076, ctx.r9.u32);
	// lfs f0,300(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 300);
	f0.f64 = double(temp.f32);
	// stfs f0,1104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 1104, temp.u32);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8270CA38;
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
loc_8270CA4C:
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

__attribute__((alias("__imp__sub_8270CA60"))) PPC_WEAK_FUNC(sub_8270CA60);
PPC_FUNC_IMPL(__imp__sub_8270CA60) {
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
	// bl 0x8270bfc0
	ctx.lr = 0x8270CA80;
	sub_8270BFC0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ca98
	if (cr6.eq) goto loc_8270CA98;
	// bl 0x82130588
	ctx.lr = 0x8270CA94;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8270CA98:
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

__attribute__((alias("__imp__sub_8270CAB0"))) PPC_WEAK_FUNC(sub_8270CAB0);
PPC_FUNC_IMPL(__imp__sub_8270CAB0) {
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
	// bl 0x826fc718
	ctx.lr = 0x8270CAC8;
	sub_826FC718(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c038
	ctx.lr = 0x8270CAD4;
	sub_8270C038(ctx, base);
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
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

__attribute__((alias("__imp__sub_8270CAEC"))) PPC_WEAK_FUNC(sub_8270CAEC);
PPC_FUNC_IMPL(__imp__sub_8270CAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270CAF0"))) PPC_WEAK_FUNC(sub_8270CAF0);
PPC_FUNC_IMPL(__imp__sub_8270CAF0) {
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
	// bl 0x8270c038
	ctx.lr = 0x8270CB08;
	sub_8270C038(ctx, base);
	// bl 0x826fc7c0
	ctx.lr = 0x8270CB0C;
	sub_826FC7C0(ctx, base);
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

__attribute__((alias("__imp__sub_8270CB20"))) PPC_WEAK_FUNC(sub_8270CB20);
PPC_FUNC_IMPL(__imp__sub_8270CB20) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822a8e80
	ctx.lr = 0x8270CB40;
	sub_822A8E80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822ac310
	ctx.lr = 0x8270CB48;
	sub_822AC310(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r7,1088
	ctx.r7.s64 = 1088;
	// li r11,1
	r11.s64 = 1;
	// lfs f0,11412(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11412);
	f0.f64 = double(temp.f32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r30,0
	r30.s64 = 0;
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,1073(r31)
	PPC_STORE_U8(r31.u32 + 1073, r11.u8);
	// stfs f0,1116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1116, temp.u32);
	// stb r11,1072(r31)
	PPC_STORE_U8(r31.u32 + 1072, r11.u8);
	// stfs f0,1112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1112, temp.u32);
	// stw r30,1076(r31)
	PPC_STORE_U32(r31.u32 + 1076, r30.u32);
	// stfs f0,1108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1108, temp.u32);
	// stw r10,1124(r31)
	PPC_STORE_U32(r31.u32 + 1124, ctx.r10.u32);
	// stfs f0,1104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1104, temp.u32);
	// stw r10,1120(r31)
	PPC_STORE_U32(r31.u32 + 1120, ctx.r10.u32);
	// stfs f0,1136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1136, temp.u32);
	// stb r11,1148(r31)
	PPC_STORE_U8(r31.u32 + 1148, r11.u8);
	// stfs f0,1132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1132, temp.u32);
	// stb r11,1156(r31)
	PPC_STORE_U8(r31.u32 + 1156, r11.u8);
	// stfs f0,1128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1128, temp.u32);
	// stb r30,1157(r31)
	PPC_STORE_U8(r31.u32 + 1157, r30.u8);
	// stvx128 v62,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// bl 0x82237af8
	ctx.lr = 0x8270CBC4;
	sub_82237AF8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c768
	ctx.lr = 0x8270CBCC;
	sub_8270C768(ctx, base);
	// lbz r6,880(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 880);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8270cbe8
	if (cr6.eq) goto loc_8270CBE8;
	// stb r30,880(r31)
	PPC_STORE_U8(r31.u32 + 880, r30.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c408
	ctx.lr = 0x8270CBE8;
	sub_8270C408(ctx, base);
loc_8270CBE8:
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

__attribute__((alias("__imp__sub_8270CC00"))) PPC_WEAK_FUNC(sub_8270CC00);
PPC_FUNC_IMPL(__imp__sub_8270CC00) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r4,68(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8270cc34
	if (cr6.eq) goto loc_8270CC34;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x82702918
	ctx.lr = 0x8270CC34;
	sub_82702918(ctx, base);
loc_8270CC34:
	// stw r31,68(r30)
	PPC_STORE_U32(r30.u32 + 68, r31.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8270cc70
	if (cr6.eq) goto loc_8270CC70;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,-12744(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -12744);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270CC5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270cc70
	if (cr6.eq) goto loc_8270CC70;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// b 0x8270cc74
	goto loc_8270CC74;
loc_8270CC70:
	// li r11,0
	r11.s64 = 0;
loc_8270CC74:
	// stw r11,876(r30)
	PPC_STORE_U32(r30.u32 + 876, r11.u32);
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

__attribute__((alias("__imp__sub_8270CC90"))) PPC_WEAK_FUNC(sub_8270CC90);
PPC_FUNC_IMPL(__imp__sub_8270CC90) {
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
	ctx.lr = 0x8270CC98;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-24312
	ctx.r9.s64 = r11.s64 + -24312;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// addi r5,r7,28300
	ctx.r5.s64 = ctx.r7.s64 + 28300;
	// lwz r6,868(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 868);
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82130000
	ctx.lr = 0x8270CCD4;
	sub_82130000(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x8270cd14
	if (!cr6.eq) goto loc_8270CD14;
	// lwz r11,876(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ccf0
	if (cr6.eq) goto loc_8270CCF0;
	// lwz r11,568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 568);
	// b 0x8270cd00
	goto loc_8270CD00;
loc_8270CCF0:
	// lwz r11,1076(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1076);
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
loc_8270CD00:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8270cd60
	if (!cr6.eq) goto loc_8270CD60;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c9f0
	ctx.lr = 0x8270CD10;
	sub_8270C9F0(ctx, base);
	// b 0x8270cd84
	goto loc_8270CD84;
loc_8270CD14:
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x8270cd60
	if (!cr6.eq) goto loc_8270CD60;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r8,r11,-13624
	ctx.r8.s64 = r11.s64 + -13624;
	// stw r10,1076(r31)
	PPC_STORE_U32(r31.u32 + 1076, ctx.r10.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,300(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,1104(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 1104, temp.u32);
	// stfs f0,1116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1116, temp.u32);
	// stfs f0,1112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1112, temp.u32);
	// stfs f0,1108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1108, temp.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8270CD5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8270cd84
	goto loc_8270CD84;
loc_8270CD60:
	// lwz r11,876(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270cd84
	if (cr6.eq) goto loc_8270CD84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c9f0
	ctx.lr = 0x8270CD74;
	sub_8270C9F0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,876(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// bl 0x8270f1a0
	ctx.lr = 0x8270CD84;
	sub_8270F1A0(ctx, base);
loc_8270CD84:
	// lwz r11,876(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270cd98
	if (cr6.eq) goto loc_8270CD98;
	// lwz r11,676(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// b 0x8270cd9c
	goto loc_8270CD9C;
loc_8270CD98:
	// li r11,0
	r11.s64 = 0;
loc_8270CD9C:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r3,r31,928
	ctx.r3.s64 = r31.s64 + 928;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r4,r10,1
	ctx.r4.u64 = ctx.r10.u64 ^ 1;
	// bl 0x82237af8
	ctx.lr = 0x8270CDB0;
	sub_82237AF8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8270CDB8"))) PPC_WEAK_FUNC(sub_8270CDB8);
PPC_FUNC_IMPL(__imp__sub_8270CDB8) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8270CDC0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270cde0
	if (!cr6.eq) goto loc_8270CDE0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8270CDE0:
	// lbz r11,1148(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1148);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ceb4
	if (cr6.eq) goto loc_8270CEB4;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ceb4
	if (cr6.eq) goto loc_8270CEB4;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// bl 0x82702b98
	ctx.lr = 0x8270CE10;
	sub_82702B98(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ceb4
	if (cr6.eq) goto loc_8270CEB4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x8270CE24;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10012(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10012);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addis r3,r11,6
	ctx.r3.s64 = r11.s64 + 393216;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r3,16704
	ctx.r3.s64 = ctx.r3.s64 + 16704;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822499f8
	ctx.lr = 0x8270CE48;
	sub_822499F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8270ceb0
	if (!cr6.eq) goto loc_8270CEB0;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10016(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10016);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82700640
	ctx.lr = 0x8270CE60;
	sub_82700640(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270ceb4
	if (cr6.eq) goto loc_8270CEB4;
	// lfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	f0.f64 = double(temp.f32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// lfs f11,64(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,56(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// lfs f13,356(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 356);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f7,f11,f0,f13
	ctx.f7.f64 = double(float(ctx.f11.f64 * f0.f64 + ctx.f13.f64));
	// fmuls f6,f12,f12
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmuls f5,f7,f7
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fmadds f4,f8,f8,f6
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fcmpu cr6,f4,f5
	cr6.compare(ctx.f4.f64, ctx.f5.f64);
	// bge cr6,0x8270ceb4
	if (!cr6.lt) goto loc_8270CEB4;
loc_8270CEB0:
	// li r28,1
	r28.s64 = 1;
loc_8270CEB4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8270CEC0"))) PPC_WEAK_FUNC(sub_8270CEC0);
PPC_FUNC_IMPL(__imp__sub_8270CEC0) {
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
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270cfb0
	if (cr6.eq) goto loc_8270CFB0;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// lfs f13,1144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1144);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8270cf68
	if (cr6.eq) goto loc_8270CF68;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x8270cfb0
	if (!cr6.eq) goto loc_8270CFB0;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270cfb0
	if (cr6.eq) goto loc_8270CFB0;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,1074(r31)
	PPC_STORE_U8(r31.u32 + 1074, ctx.r10.u8);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270cfb0
	if (cr6.eq) goto loc_8270CFB0;
	// bl 0x8234a0c0
	ctx.lr = 0x8270CF24;
	sub_8234A0C0(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lfs f13,1144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1144);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lwz r6,868(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 868);
	// addi r5,r10,28336
	ctx.r5.s64 = ctx.r10.s64 + 28336;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lfs f0,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,1144(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 1144, temp.u32);
	// bl 0x82130000
	ctx.lr = 0x8270CF54;
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
loc_8270CF68:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8270cfb0
	if (!cr6.gt) goto loc_8270CFB0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x82702b98
	ctx.lr = 0x8270CF80;
	sub_82702B98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270cfac
	if (cr6.eq) goto loc_8270CFAC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8270c638
	ctx.lr = 0x8270CF98;
	sub_8270C638(ctx, base);
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
loc_8270CFAC:
	// bl 0x8270c768
	ctx.lr = 0x8270CFB0;
	sub_8270C768(ctx, base);
loc_8270CFB0:
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

__attribute__((alias("__imp__sub_8270CFC4"))) PPC_WEAK_FUNC(sub_8270CFC4);
PPC_FUNC_IMPL(__imp__sub_8270CFC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270CFC8"))) PPC_WEAK_FUNC(sub_8270CFC8);
PPC_FUNC_IMPL(__imp__sub_8270CFC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x8270CFD0;
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f29.u64);
	// stfd f30,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,465(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 465);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// fmr f30,f2
	f30.f64 = ctx.f2.f64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d014
	if (cr6.eq) goto loc_8270D014;
	// lbz r11,880(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d014
	if (cr6.eq) goto loc_8270D014;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8270d158
	goto loc_8270D158;
loc_8270D014:
	// li r31,1
	r31.s64 = 1;
	// bl 0x822a8108
	ctx.lr = 0x8270D01C;
	sub_822A8108(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x8270D028;
	sub_822A8108(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,48
	ctx.r9.s64 = 48;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f13,27644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmuls f29,f30,f13
	f29.f64 = double(float(f30.f64 * ctx.f13.f64));
	// lvx128 v127,r3,r9
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x8270d094
	if (!cr6.gt) goto loc_8270D094;
	// lfs f13,52(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f31,f31
	ctx.f12.f64 = double(float(f31.f64 * f31.f64));
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f9,56(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 56);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// lfs f6,48(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 48);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fmuls f3,f10,f10
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f2,f7,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// ble cr6,0x8270d094
	if (!cr6.gt) goto loc_8270D094;
	// li r31,0
	r31.s64 = 0;
loc_8270D094:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d154
	if (cr6.eq) goto loc_8270D154;
	// li r30,48
	r30.s64 = 48;
	// fcmpu cr6,f30,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f30.f64, f0.f64);
	// ble cr6,0x8270d0f4
	if (!cr6.gt) goto loc_8270D0F4;
	// li r11,32
	r11.s64 = 32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v62,r29,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v61,v127,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r29,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v59,v63,v60
	simde_mm_store_ps(v59.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c900
	ctx.lr = 0x8270D0E0;
	sub_8216C900(ctx, base);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x8270d0f0
	if (cr6.lt) goto loc_8270D0F0;
	// li r11,0
	r11.s64 = 0;
loc_8270D0F0:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
loc_8270D0F4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d154
	if (cr6.eq) goto loc_8270D154;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v58,r29,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stvx128 v127,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lfs f12,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 + f0.f64));
	// fadds f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 + f0.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r3,-10016(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10016);
	// lvx128 v2,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82700578
	ctx.lr = 0x8270D150;
	sub_82700578(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8270D154:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8270D158:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_8270D174"))) PPC_WEAK_FUNC(sub_8270D174);
PPC_FUNC_IMPL(__imp__sub_8270D174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270D178"))) PPC_WEAK_FUNC(sub_8270D178);
PPC_FUNC_IMPL(__imp__sub_8270D178) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	ctx.lr = 0x8270D180;
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r11,1076(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 1076);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d5d4
	if (cr6.eq) goto loc_8270D5D4;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lwz r11,-10012(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d5d4
	if (cr6.eq) goto loc_8270D5D4;
	// lwz r24,68(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// bl 0x822a8108
	ctx.lr = 0x8270D1BC;
	sub_822A8108(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,1076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1076);
	// bl 0x822a8108
	ctx.lr = 0x8270D1C8;
	sub_822A8108(ctx, base);
	// li r26,48
	r26.s64 = 48;
	// addi r7,r31,48
	ctx.r7.s64 = r31.s64 + 48;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// li r27,32
	r27.s64 = 32;
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// lvx128 v63,r3,r26
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v60,r3,r27
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,2272
	ctx.r10.s64 = ctx.r10.s64 + 2272;
	// stvx128 v61,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8270d228
	if (cr6.eq) goto loc_8270D228;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d228
	if (cr6.eq) goto loc_8270D228;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x8270d22c
	goto loc_8270D22C;
loc_8270D228:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8270D22C:
	// lwz r9,1076(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 1076);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,48(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d25c
	if (cr6.eq) goto loc_8270D25C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d25c
	if (cr6.eq) goto loc_8270D25C;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r10,r11,272
	ctx.r10.s64 = r11.s64 + 272;
loc_8270D25C:
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f13,40(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f11,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,36(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 36);
	ctx.f10.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f9,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// addi r11,r31,32
	r11.s64 = r31.s64 + 32;
	// lfs f8,32(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f8.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f29,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f29.f64 = double(temp.f32);
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f7,f10,f11,f12
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f11.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// ble cr6,0x8270d2c8
	if (!cr6.gt) goto loc_8270D2C8;
	// lfs f13,1108(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1108);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 + f31.f64));
	// stfs f12,1108(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 1108, temp.u32);
	// fcmpu cr6,f12,f29
	cr6.compare(ctx.f12.f64, f29.f64);
	// ble cr6,0x8270d2cc
	if (!cr6.gt) goto loc_8270D2CC;
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x8270d2cc
	goto loc_8270D2CC;
loc_8270D2C8:
	// stfs f0,1108(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 1108, temp.u32);
loc_8270D2CC:
	// lfs f13,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f12,216(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,212(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,208(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f10,f9,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f5,f8,f7,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bge cr6,0x8270d318
	if (!cr6.lt) goto loc_8270D318;
	// lfs f13,1112(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1112);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f31,f13
	ctx.f12.f64 = double(float(f31.f64 + ctx.f13.f64));
	// stfs f12,1112(r30)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r30.u32 + 1112, temp.u32);
	// fcmpu cr6,f12,f29
	cr6.compare(ctx.f12.f64, f29.f64);
	// ble cr6,0x8270d31c
	if (!cr6.gt) goto loc_8270D31C;
	// li r9,1
	ctx.r9.s64 = 1;
	// b 0x8270d31c
	goto loc_8270D31C;
loc_8270D318:
	// stfs f0,1112(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 1112, temp.u32);
loc_8270D31C:
	// lfs f13,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f13.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f10,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f10,f9,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f5,f8,f7,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bge cr6,0x8270d368
	if (!cr6.lt) goto loc_8270D368;
	// lfs f0,1116(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1116);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// stfs f13,1116(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 1116, temp.u32);
	// fcmpu cr6,f13,f29
	cr6.compare(ctx.f13.f64, f29.f64);
	// ble cr6,0x8270d36c
	if (!cr6.gt) goto loc_8270D36C;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x8270d36c
	goto loc_8270D36C;
loc_8270D368:
	// stfs f0,1116(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 1116, temp.u32);
loc_8270D36C:
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,228(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f11,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,232(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	ctx.f10.f64 = double(temp.f32);
	// addi r29,r11,-13624
	r29.s64 = r11.s64 + -13624;
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,224(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// lfs f0,288(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 288);
	f0.f64 = double(temp.f32);
	// fmuls f5,f0,f0
	ctx.f5.f64 = double(float(f0.f64 * f0.f64));
	// fmuls f4,f12,f12
	ctx.f4.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f3,f9,f9,f4
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f4.f64));
	// fmadds f2,f6,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fcmpu cr6,f2,f5
	cr6.compare(ctx.f2.f64, ctx.f5.f64);
	// bgt cr6,0x8270d5cc
	if (cr6.gt) goto loc_8270D5CC;
	// clrlwi r11,r8,24
	r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d5cc
	if (!cr6.eq) goto loc_8270D5CC;
	// clrlwi r11,r9,24
	r11.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d5cc
	if (!cr6.eq) goto loc_8270D5CC;
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d5cc
	if (!cr6.eq) goto loc_8270D5CC;
	// lwz r11,1708(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 1708);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8270d5cc
	if (cr6.eq) goto loc_8270D5CC;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82744ac8
	ctx.lr = 0x8270D3EC;
	sub_82744AC8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8270d408
	if (cr6.lt) goto loc_8270D408;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82744ab0
	ctx.lr = 0x8270D3FC;
	sub_82744AB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d5d4
	if (cr6.eq) goto loc_8270D5D4;
loc_8270D408:
	// lwz r3,1076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1076);
	// li r28,0
	r28.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270D420;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,6
	ctx.r8.s64 = 393216;
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// ori r31,r8,16704
	r31.u64 = ctx.r8.u64 | 16704;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lfs f30,27640(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 27640);
	f30.f64 = double(temp.f32);
	// beq cr6,0x8270d4cc
	if (cr6.eq) goto loc_8270D4CC;
	// lwz r3,1076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1076);
	// lwz r11,640(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 640);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d4cc
	if (cr6.eq) goto loc_8270D4CC;
	// li r11,608
	r11.s64 = 608;
	// lfs f31,284(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 284);
	f31.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v57,r3,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x8270D464;
	sub_822A8108(ctx, base);
	// addi r9,r1,104
	ctx.r9.s64 = ctx.r1.s64 + 104;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r7,32
	ctx.r7.s64 = 32;
	// lwz r11,-10012(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10012);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r23,r1,80
	r23.s64 = ctx.r1.s64 + 80;
	// lvlx128 v56,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v0,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lvx128 v13,r3,r7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// lvx128 v12,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,100
	ctx.r8.s64 = ctx.r1.s64 + 100;
	// vmaddfp v0,v13,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// stvx128 v0,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,172(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stvx128 v0,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8224a4f8
	ctx.lr = 0x8270D4C0;
	sub_8224A4F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270d4cc
	if (cr6.eq) goto loc_8270D4CC;
	// li r28,1
	r28.s64 = 1;
loc_8270D4CC:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d53c
	if (!cr6.eq) goto loc_8270D53C;
	// lwz r3,1076(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 1076);
	// bl 0x822a8108
	ctx.lr = 0x8270D4E0;
	sub_822A8108(ctx, base);
	// li r10,284
	ctx.r10.s64 = 284;
	// lvx128 v13,r3,r26
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r3,r27
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10012(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10012);
	// addi r25,r1,144
	r25.s64 = ctx.r1.s64 + 144;
	// addi r23,r1,80
	r23.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// lvlx128 v55,r29,r10
	temp.u32 = r29.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vspltw128 v0,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// stvx128 v0,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,156(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stvx128 v0,r0,r23
	simde_mm_store_si128((simde__m128i*)(base + ((r23.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8224a4f8
	ctx.lr = 0x8270D530;
	sub_8224A4F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270d53c
	if (cr6.eq) goto loc_8270D53C;
	// li r28,1
	r28.s64 = 1;
loc_8270D53C:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d5cc
	if (cr6.eq) goto loc_8270D5CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,1092(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1092);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,11412(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11412);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x8270d594
	if (cr6.eq) goto loc_8270D594;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// lfs f13,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,1096(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1096);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// lfs f8,1088(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1088);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fmuls f5,f12,f12
	ctx.f5.f64 = double(float(ctx.f12.f64 * ctx.f12.f64));
	// fmadds f4,f9,f9,f5
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f29
	cr6.compare(ctx.f3.f64, f29.f64);
	// ble cr6,0x8270d5d4
	if (!cr6.gt) goto loc_8270D5D4;
loc_8270D594:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,1088
	ctx.r10.s64 = 1088;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r30,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82744d40
	ctx.lr = 0x8270D5B0;
	sub_82744D40(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827458d8
	ctx.lr = 0x8270D5B8;
	sub_827458D8(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
loc_8270D5CC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270c9f0
	ctx.lr = 0x8270D5D4;
	sub_8270C9F0(ctx, base);
loc_8270D5D4:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8270D5E8"))) PPC_WEAK_FUNC(sub_8270D5E8);
PPC_FUNC_IMPL(__imp__sub_8270D5E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d618
	if (!cr6.eq) goto loc_8270D618;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d618
	if (cr6.eq) goto loc_8270D618;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d618
	if (cr6.eq) goto loc_8270D618;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,160(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 160, temp.u32);
loc_8270D618:
	// b 0x826fc908
	sub_826FC908(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270D61C"))) PPC_WEAK_FUNC(sub_8270D61C);
PPC_FUNC_IMPL(__imp__sub_8270D61C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270D620"))) PPC_WEAK_FUNC(sub_8270D620);
PPC_FUNC_IMPL(__imp__sub_8270D620) {
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
	ctx.lr = 0x8270D628;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r10,-10028(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270d7f4
	if (cr6.eq) goto loc_8270D7F4;
	// lbz r11,880(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d7e8
	if (!cr6.eq) goto loc_8270D7E8;
	// lwz r11,48(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d68c
	if (cr6.eq) goto loc_8270D68C;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d68c
	if (cr6.eq) goto loc_8270D68C;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,24(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8270d680
	if (cr6.lt) goto loc_8270D680;
	// li r11,1
	r11.s64 = 1;
loc_8270D680:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d7e8
	if (!cr6.eq) goto loc_8270D7E8;
loc_8270D68C:
	// lwz r11,876(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 876);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d6a0
	if (cr6.eq) goto loc_8270D6A0;
	// lwz r11,676(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// b 0x8270d6a4
	goto loc_8270D6A4;
loc_8270D6A0:
	// li r11,0
	r11.s64 = 0;
loc_8270D6A4:
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r30,r29,928
	r30.s64 = r29.s64 + 928;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// xori r31,r10,1
	r31.u64 = ctx.r10.u64 ^ 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82237af8
	ctx.lr = 0x8270D6C0;
	sub_82237AF8(ctx, base);
	// clrlwi r9,r31,24
	ctx.r9.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8270d798
	if (!cr6.eq) goto loc_8270D798;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// lwz r10,17268(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270d77c
	if (cr6.eq) goto loc_8270D77C;
	// lwz r11,264(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 264);
	// addi r10,r10,264
	ctx.r10.s64 = ctx.r10.s64 + 264;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// beq cr6,0x8270d77c
	if (cr6.eq) goto loc_8270D77C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r31,r10,-13624
	r31.s64 = ctx.r10.s64 + -13624;
loc_8270D700:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// mr r26,r11
	r26.u64 = r11.u64;
	// bl 0x82215e10
	ctx.lr = 0x8270D710;
	sub_82215E10(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822a8108
	ctx.lr = 0x8270D718;
	sub_822A8108(ctx, base);
	// addi r26,r3,48
	r26.s64 = ctx.r3.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a8108
	ctx.lr = 0x8270D724;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f13,4(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,396(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 396);
	f0.f64 = double(temp.f32);
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f0,f0
	ctx.f9.f64 = double(float(f0.f64 * f0.f64));
	// fsubs f8,f10,f13
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f7,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f5,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f11
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f11.f64));
	// fmuls f3,f8,f8
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fmadds f2,f6,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f9
	cr6.compare(ctx.f1.f64, ctx.f9.f64);
	// blt cr6,0x8270d778
	if (cr6.lt) goto loc_8270D778;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d700
	if (!cr6.eq) goto loc_8270D700;
	// b 0x8270d77c
	goto loc_8270D77C;
loc_8270D778:
	// li r28,1
	r28.s64 = 1;
loc_8270D77C:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d7d0
	if (cr6.eq) goto loc_8270D7D0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701bd8
	ctx.lr = 0x8270D790;
	sub_82701BD8(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bge cr6,0x8270d7d0
	if (!cr6.lt) goto loc_8270D7D0;
loc_8270D798:
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// bl 0x82237cc0
	ctx.lr = 0x8270D7A8;
	sub_82237CC0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d7f4
	if (!cr6.eq) goto loc_8270D7F4;
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// bl 0x82238688
	ctx.lr = 0x8270D7C8;
	sub_82238688(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8270D7D0:
	// lwz r11,-10028(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10028);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,128
	ctx.r3.s64 = r11.s64 + 128;
	// bl 0x82238140
	ctx.lr = 0x8270D7E0;
	sub_82238140(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_8270D7E8:
	// addi r4,r29,928
	ctx.r4.s64 = r29.s64 + 928;
	// addi r3,r10,128
	ctx.r3.s64 = ctx.r10.s64 + 128;
	// bl 0x82238140
	ctx.lr = 0x8270D7F4;
	sub_82238140(ctx, base);
loc_8270D7F4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8270D7FC"))) PPC_WEAK_FUNC(sub_8270D7FC);
PPC_FUNC_IMPL(__imp__sub_8270D7FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270D800"))) PPC_WEAK_FUNC(sub_8270D800);
PPC_FUNC_IMPL(__imp__sub_8270D800) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8270d620
	ctx.lr = 0x8270D820;
	sub_8270D620(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f30,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f30.f64 = double(temp.f32);
	// bl 0x826fcbd0
	ctx.lr = 0x8270D834;
	sub_826FCBD0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8270d178
	ctx.lr = 0x8270D840;
	sub_8270D178(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,1104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1104);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8270d868
	if (!cr6.gt) goto loc_8270D868;
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// stfs f0,1104(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1104, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8270d868
	if (!cr6.lt) goto loc_8270D868;
	// stfs f31,1104(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1104, temp.u32);
loc_8270D868:
	// lfs f0,1128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1128);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8270d888
	if (!cr6.gt) goto loc_8270D888;
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// stfs f0,1128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1128, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8270d888
	if (!cr6.lt) goto loc_8270D888;
	// stfs f31,1128(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1128, temp.u32);
loc_8270D888:
	// lfs f0,1132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1132);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8270d8a8
	if (!cr6.gt) goto loc_8270D8A8;
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// stfs f0,1132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1132, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8270d8a8
	if (!cr6.lt) goto loc_8270D8A8;
	// stfs f31,1132(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1132, temp.u32);
loc_8270D8A8:
	// lfs f0,1144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1144);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8270d8c0
	if (!cr6.gt) goto loc_8270D8C0;
	// fadds f0,f0,f30
	f0.f64 = double(float(f0.f64 + f30.f64));
	// stfs f0,1144(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1144, temp.u32);
	// b 0x8270d908
	goto loc_8270D908;
loc_8270D8C0:
	// lfs f0,1140(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1140);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8270d908
	if (!cr6.gt) goto loc_8270D908;
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// stfs f0,1140(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1140, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8270d908
	if (cr6.gt) goto loc_8270D908;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// stfs f31,1140(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 1140, temp.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d908
	if (cr6.eq) goto loc_8270D908;
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8270d908
	if (cr6.eq) goto loc_8270D908;
	// lbz r11,872(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d908
	if (cr6.eq) goto loc_8270D908;
	// bl 0x8234a180
	ctx.lr = 0x8270D908;
	sub_8234A180(ctx, base);
loc_8270D908:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x82702b30
	ctx.lr = 0x8270D918;
	sub_82702B30(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270d948
	if (cr6.eq) goto loc_8270D948;
	// lfs f0,1136(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1136);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8270d948
	if (!cr6.gt) goto loc_8270D948;
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// stfs f0,1136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1136, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8270d948
	if (cr6.gt) goto loc_8270D948;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c5c0
	ctx.lr = 0x8270D948;
	sub_8270C5C0(ctx, base);
loc_8270D948:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d9e4
	if (cr6.eq) goto loc_8270D9E4;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270d9e4
	if (cr6.eq) goto loc_8270D9E4;
	// lwz r10,876(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 876);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270d9e4
	if (cr6.eq) goto loc_8270D9E4;
	// lwz r10,676(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 676);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270d9e4
	if (cr6.eq) goto loc_8270D9E4;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lfs f13,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x8270d994
	if (cr6.lt) goto loc_8270D994;
	// li r11,1
	r11.s64 = 1;
loc_8270D994:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270d9dc
	if (cr6.eq) goto loc_8270D9DC;
	// lbz r11,1157(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1157);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270d9e4
	if (!cr6.eq) goto loc_8270D9E4;
	// li r11,1
	r11.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r11,1157(r31)
	PPC_STORE_U8(r31.u32 + 1157, r11.u8);
	// bl 0x82714c58
	ctx.lr = 0x8270D9BC;
	sub_82714C58(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270c2d8
	ctx.lr = 0x8270D9C4;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82714080
	ctx.lr = 0x8270D9D0;
	sub_82714080(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82714070
	ctx.lr = 0x8270D9D8;
	sub_82714070(ctx, base);
	// b 0x8270d9e4
	goto loc_8270D9E4;
loc_8270D9DC:
	// li r11,0
	r11.s64 = 0;
	// stb r11,1157(r31)
	PPC_STORE_U8(r31.u32 + 1157, r11.u8);
loc_8270D9E4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

__attribute__((alias("__imp__sub_8270DA00"))) PPC_WEAK_FUNC(sub_8270DA00);
PPC_FUNC_IMPL(__imp__sub_8270DA00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24216(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24216);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270DA0C"))) PPC_WEAK_FUNC(sub_8270DA0C);
PPC_FUNC_IMPL(__imp__sub_8270DA0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270DA10"))) PPC_WEAK_FUNC(sub_8270DA10);
PPC_FUNC_IMPL(__imp__sub_8270DA10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24212(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24212);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270DA1C"))) PPC_WEAK_FUNC(sub_8270DA1C);
PPC_FUNC_IMPL(__imp__sub_8270DA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270DA20"))) PPC_WEAK_FUNC(sub_8270DA20);
PPC_FUNC_IMPL(__imp__sub_8270DA20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-24208(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24208);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270DA2C"))) PPC_WEAK_FUNC(sub_8270DA2C);
PPC_FUNC_IMPL(__imp__sub_8270DA2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270DA30"))) PPC_WEAK_FUNC(sub_8270DA30);
PPC_FUNC_IMPL(__imp__sub_8270DA30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,12(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_8270DA48:
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + r11.u64;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// stw r8,16(r9)
	PPC_STORE_U32(ctx.r9.u32 + 16, ctx.r8.u32);
	// lhz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8270da48
	if (cr6.lt) goto loc_8270DA48;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270DA6C"))) PPC_WEAK_FUNC(sub_8270DA6C);
PPC_FUNC_IMPL(__imp__sub_8270DA6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270DA70"))) PPC_WEAK_FUNC(sub_8270DA70);
PPC_FUNC_IMPL(__imp__sub_8270DA70) {
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
	ctx.lr = 0x8270DA78;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270dbb0
	if (cr6.eq) goto loc_8270DBB0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r28,0
	r28.s64 = 0;
	// addi r27,r11,28640
	r27.s64 = r11.s64 + 28640;
loc_8270DA9C:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r30,r11,8
	r30.s64 = r11.s64 + 8;
	// lhz r10,14(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 14);
	// lhz r31,4(r11)
	r31.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8270dad8
	if (!cr6.eq) goto loc_8270DAD8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// beq cr6,0x8270dad0
	if (cr6.eq) goto loc_8270DAD0;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8270DACC;
	sub_82130528(ctx, base);
	// b 0x8270dad4
	goto loc_8270DAD4;
loc_8270DAD0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8270DAD4:
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_8270DAD8:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
	// ble cr6,0x8270db9c
	if (!cr6.gt) goto loc_8270DB9C;
	// li r30,0
	r30.s64 = 0;
loc_8270DAE8:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// lhz r6,4(r29)
	ctx.r6.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// lwzx r5,r10,r30
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// ble cr6,0x8270db50
	if (!cr6.gt) goto loc_8270DB50;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r7,r4
	ctx.r7.u64 = ctx.r4.u64;
loc_8270DB0C:
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// mr r11,r5
	r11.u64 = ctx.r5.u64;
loc_8270DB14:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r3,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r3.s64;
	// beq cr6,0x8270db38
	if (cr6.eq) goto loc_8270DB38;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8270db14
	if (cr6.eq) goto loc_8270DB14;
loc_8270DB38:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8270dbb8
	if (cr6.eq) goto loc_8270DBB8;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r7,r7,12
	ctx.r7.s64 = ctx.r7.s64 + 12;
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// blt cr6,0x8270db0c
	if (cr6.lt) goto loc_8270DB0C;
loc_8270DB50:
	// li r11,0
	r11.s64 = 0;
loc_8270DB54:
	// lwz r10,8(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stwx r11,r9,r30
	PPC_STORE_U32(ctx.r9.u32 + r30.u32, r11.u32);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// add r8,r11,r28
	ctx.r8.u64 = r11.u64 + r28.u64;
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwzx r6,r7,r30
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + r30.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8270db90
	if (!cr6.eq) goto loc_8270DB90;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// lwzx r4,r10,r30
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// bl 0x821bd618
	ctx.lr = 0x8270DB90;
	sub_821BD618(ctx, base);
loc_8270DB90:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8270dae8
	if (!cr0.eq) goto loc_8270DAE8;
loc_8270DB9C:
	// lhz r11,12(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 12);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,20
	r28.s64 = r28.s64 + 20;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8270da9c
	if (cr6.lt) goto loc_8270DA9C;
loc_8270DBB0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8270DBB8:
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// b 0x8270db54
	goto loc_8270DB54;
}

__attribute__((alias("__imp__sub_8270DBCC"))) PPC_WEAK_FUNC(sub_8270DBCC);
PPC_FUNC_IMPL(__imp__sub_8270DBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270DBD0"))) PPC_WEAK_FUNC(sub_8270DBD0);
PPC_FUNC_IMPL(__imp__sub_8270DBD0) {
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
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8270DBF4;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8270dc28
	if (!cr6.gt) goto loc_8270DC28;
	// addi r11,r3,10
	r11.s64 = ctx.r3.s64 + 10;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8270DC04:
	// addic. r9,r11,-10
	xer.ca = r11.u32 > 9;
	ctx.r9.s64 = r11.s64 + -10;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8270dc1c
	if (cr0.eq) goto loc_8270DC1C;
	// stw r10,-10(r11)
	PPC_STORE_U32(r11.u32 + -10, ctx.r10.u32);
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
loc_8270DC1C:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// bne 0x8270dc04
	if (!cr0.eq) goto loc_8270DC04;
loc_8270DC28:
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

__attribute__((alias("__imp__sub_8270DC3C"))) PPC_WEAK_FUNC(sub_8270DC3C);
PPC_FUNC_IMPL(__imp__sub_8270DC3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270DC40"))) PPC_WEAK_FUNC(sub_8270DC40);
PPC_FUNC_IMPL(__imp__sub_8270DC40) {
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
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x8270DC54;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270dc80
	if (cr6.eq) goto loc_8270DC80;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8270DC80:
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

__attribute__((alias("__imp__sub_8270DC94"))) PPC_WEAK_FUNC(sub_8270DC94);
PPC_FUNC_IMPL(__imp__sub_8270DC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270DC98"))) PPC_WEAK_FUNC(sub_8270DC98);
PPC_FUNC_IMPL(__imp__sub_8270DC98) {
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
	ctx.lr = 0x8270DCAC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270dce4
	if (cr6.eq) goto loc_8270DCE4;
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
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8270DCE4:
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

__attribute__((alias("__imp__sub_8270DCF8"))) PPC_WEAK_FUNC(sub_8270DCF8);
PPC_FUNC_IMPL(__imp__sub_8270DCF8) {
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
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x8270DD1C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x8270dd5c
	if (!cr6.gt) goto loc_8270DD5C;
	// addi r11,r3,14
	r11.s64 = ctx.r3.s64 + 14;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8270DD2C:
	// addic. r9,r11,-14
	xer.ca = r11.u32 > 13;
	ctx.r9.s64 = r11.s64 + -14;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq 0x8270dd50
	if (cr0.eq) goto loc_8270DD50;
	// stw r10,-14(r11)
	PPC_STORE_U32(r11.u32 + -14, ctx.r10.u32);
	// sth r10,-10(r11)
	PPC_STORE_U16(r11.u32 + -10, ctx.r10.u16);
	// sth r10,-8(r11)
	PPC_STORE_U16(r11.u32 + -8, ctx.r10.u16);
	// stw r10,-6(r11)
	PPC_STORE_U32(r11.u32 + -6, ctx.r10.u32);
	// sth r10,-2(r11)
	PPC_STORE_U16(r11.u32 + -2, ctx.r10.u16);
	// sth r10,0(r11)
	PPC_STORE_U16(r11.u32 + 0, ctx.r10.u16);
	// stw r10,2(r11)
	PPC_STORE_U32(r11.u32 + 2, ctx.r10.u32);
loc_8270DD50:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// bne 0x8270dd2c
	if (!cr0.eq) goto loc_8270DD2C;
loc_8270DD5C:
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

__attribute__((alias("__imp__sub_8270DD70"))) PPC_WEAK_FUNC(sub_8270DD70);
PPC_FUNC_IMPL(__imp__sub_8270DD70) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-24216
	r31.s64 = r11.s64 + -24216;
	// lwz r11,-24216(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270de90
	if (!cr6.eq) goto loc_8270DE90;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8270DDA0;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270ddb4
	if (cr6.eq) goto loc_8270DDB4;
	// bl 0x821d5408
	ctx.lr = 0x8270DDB0;
	sub_821D5408(ctx, base);
	// b 0x8270ddb8
	goto loc_8270DDB8;
loc_8270DDB4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8270DDB8:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32143
	r11.s64 = -2106523648;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,28700
	ctx.r7.s64 = ctx.r10.s64 + 28700;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-9728
	ctx.r9.s64 = r11.s64 + -9728;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,12
	ctx.r5.s64 = 12;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32143
	ctx.r8.s64 = -2106523648;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-9152
	ctx.r4.s64 = ctx.r8.s64 + -9152;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r8,r3,-13152
	ctx.r8.s64 = ctx.r3.s64 + -13152;
	// ld r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r10,-12964
	ctx.r7.s64 = ctx.r10.s64 + -12964;
	// std r5,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r5.u64);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x8270DE3C;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8270DE4C;
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
	ctx.lr = 0x8270DE68;
	sub_821D41D0(ctx, base);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,-13092
	ctx.r4.s64 = ctx.r8.s64 + -13092;
	// bl 0x821d4b00
	ctx.lr = 0x8270DE78;
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
	ctx.lr = 0x8270DE90;
	sub_821C0548(ctx, base);
loc_8270DE90:
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

__attribute__((alias("__imp__sub_8270DEA8"))) PPC_WEAK_FUNC(sub_8270DEA8);
PPC_FUNC_IMPL(__imp__sub_8270DEA8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-24212
	r31.s64 = r11.s64 + -24212;
	// lwz r11,-24212(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24212);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270dfb8
	if (!cr6.eq) goto loc_8270DFB8;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8270DED8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270deec
	if (cr6.eq) goto loc_8270DEEC;
	// bl 0x821d5408
	ctx.lr = 0x8270DEE8;
	sub_821D5408(ctx, base);
	// b 0x8270def0
	goto loc_8270DEF0;
loc_8270DEEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8270DEF0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32143
	r11.s64 = -2106523648;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,28716
	ctx.r7.s64 = ctx.r10.s64 + 28716;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,-9712
	ctx.r9.s64 = r11.s64 + -9712;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32143
	ctx.r8.s64 = -2106523648;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-9064
	ctx.r4.s64 = ctx.r8.s64 + -9064;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r3,-12916
	ctx.r9.s64 = ctx.r3.s64 + -12916;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
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
	ctx.lr = 0x8270DF64;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8270DF74;
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
	ctx.lr = 0x8270DF90;
	sub_821D41D0(ctx, base);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r5,-13056
	ctx.r4.s64 = ctx.r5.s64 + -13056;
	// bl 0x821d4b00
	ctx.lr = 0x8270DFA0;
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
	ctx.lr = 0x8270DFB8;
	sub_821C0548(ctx, base);
loc_8270DFB8:
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

__attribute__((alias("__imp__sub_8270DFD0"))) PPC_WEAK_FUNC(sub_8270DFD0);
PPC_FUNC_IMPL(__imp__sub_8270DFD0) {
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
	// bne cr6,0x8270e014
	if (!cr6.eq) goto loc_8270E014;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x8270e00c
	if (cr6.eq) goto loc_8270E00C;
	// bl 0x8270dbd0
	ctx.lr = 0x8270E008;
	sub_8270DBD0(ctx, base);
	// b 0x8270e010
	goto loc_8270E010;
loc_8270E00C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8270E010:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8270E014:
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

__attribute__((alias("__imp__sub_8270E030"))) PPC_WEAK_FUNC(sub_8270E030);
PPC_FUNC_IMPL(__imp__sub_8270E030) {
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
	// bne cr6,0x8270e074
	if (!cr6.eq) goto loc_8270E074;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x8270e06c
	if (cr6.eq) goto loc_8270E06C;
	// bl 0x8270dcf8
	ctx.lr = 0x8270E068;
	sub_8270DCF8(ctx, base);
	// b 0x8270e070
	goto loc_8270E070;
loc_8270E06C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8270E070:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_8270E074:
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

__attribute__((alias("__imp__sub_8270E090"))) PPC_WEAK_FUNC(sub_8270E090);
PPC_FUNC_IMPL(__imp__sub_8270E090) {
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
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x82130528
	ctx.lr = 0x8270E0A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270e0d8
	if (cr6.eq) goto loc_8270E0D8;
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
	// sth r11,12(r3)
	PPC_STORE_U16(ctx.r3.u32 + 12, r11.u16);
	// sth r11,14(r3)
	PPC_STORE_U16(ctx.r3.u32 + 14, r11.u16);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_8270E0D8:
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

__attribute__((alias("__imp__sub_8270E0EC"))) PPC_WEAK_FUNC(sub_8270E0EC);
PPC_FUNC_IMPL(__imp__sub_8270E0EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E0F0"))) PPC_WEAK_FUNC(sub_8270E0F0);
PPC_FUNC_IMPL(__imp__sub_8270E0F0) {
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
	ctx.lr = 0x8270E0F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r31,r11,-24208
	r31.s64 = r11.s64 + -24208;
	// lwz r11,-24208(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270e250
	if (!cr6.eq) goto loc_8270E250;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x8270E118;
	sub_82130528(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270e12c
	if (cr6.eq) goto loc_8270E12C;
	// bl 0x821d5408
	ctx.lr = 0x8270E128;
	sub_821D5408(ctx, base);
	// b 0x8270e130
	goto loc_8270E130;
loc_8270E12C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_8270E130:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32143
	r11.s64 = -2106523648;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r7,r10,28736
	ctx.r7.s64 = ctx.r10.s64 + 28736;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// addi r9,r11,-9696
	ctx.r9.s64 = r11.s64 + -9696;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,16
	ctx.r5.s64 = 16;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32143
	ctx.r8.s64 = -2106523648;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// addi r4,r8,-8048
	ctx.r4.s64 = ctx.r8.s64 + -8048;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r9,r3,-12868
	ctx.r9.s64 = ctx.r3.s64 + -12868;
	// ld r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// std r8,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r8.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lwz r11,-24216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24216);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8270e1ac
	if (!cr6.eq) goto loc_8270E1AC;
	// bl 0x8270dd70
	ctx.lr = 0x8270E1A8;
	sub_8270DD70(ctx, base);
	// lwz r11,-24216(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24216);
loc_8270E1AC:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r8,r10,-13048
	ctx.r8.s64 = ctx.r10.s64 + -13048;
	// addi r7,r9,-12820
	ctx.r7.s64 = ctx.r9.s64 + -12820;
	// li r9,8
	ctx.r9.s64 = 8;
	// lwz r10,-24212(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -24212);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// bne cr6,0x8270e1e0
	if (!cr6.eq) goto loc_8270E1E0;
	// bl 0x8270dea8
	ctx.lr = 0x8270E1DC;
	sub_8270DEA8(ctx, base);
	// lwz r10,-24212(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -24212);
loc_8270E1E0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r11,-13012
	ctx.r9.s64 = r11.s64 + -13012;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// bl 0x821d4458
	ctx.lr = 0x8270E1FC;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x8270E20C;
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
	ctx.lr = 0x8270E228;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-12976
	ctx.r4.s64 = ctx.r6.s64 + -12976;
	// bl 0x821d4b00
	ctx.lr = 0x8270E238;
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
	ctx.lr = 0x8270E250;
	sub_821C0548(ctx, base);
loc_8270E250:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8270E258"))) PPC_WEAK_FUNC(sub_8270E258);
PPC_FUNC_IMPL(__imp__sub_8270E258) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r11,-12744(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12744);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x8270e270
	if (!cr6.eq) goto loc_8270E270;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_8270E270:
	// b 0x822b9d98
	sub_822B9D98(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270E274"))) PPC_WEAK_FUNC(sub_8270E274);
PPC_FUNC_IMPL(__imp__sub_8270E274) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E278"))) PPC_WEAK_FUNC(sub_8270E278);
PPC_FUNC_IMPL(__imp__sub_8270E278) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r10,r11,0,26,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3E;
	// rlwinm r10,r10,0,30,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270e298
	if (cr6.eq) goto loc_8270E298;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8270E298:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E2A4"))) PPC_WEAK_FUNC(sub_8270E2A4);
PPC_FUNC_IMPL(__imp__sub_8270E2A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E2A8"))) PPC_WEAK_FUNC(sub_8270E2A8);
PPC_FUNC_IMPL(__imp__sub_8270E2A8) {
	PPC_FUNC_PROLOGUE();
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
	// li r4,32
	ctx.r4.s64 = 32;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822bc838
	ctx.lr = 0x8270E2C4;
	sub_822BC838(ctx, base);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r11,2272
	ctx.r8.s64 = r11.s64 + 2272;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r9,29116
	ctx.r7.s64 = ctx.r9.s64 + 29116;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,560(r31)
	PPC_STORE_U32(r31.u32 + 560, r11.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// stfs f0,572(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 572, temp.u32);
	// stfs f0,580(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// stw r11,564(r31)
	PPC_STORE_U32(r31.u32 + 564, r11.u32);
	// stfs f0,584(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// stw r11,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r11.u32);
	// stfs f0,588(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// stw r11,576(r31)
	PPC_STORE_U32(r31.u32 + 576, r11.u32);
	// stfs f0,596(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// stb r11,592(r31)
	PPC_STORE_U8(r31.u32 + 592, r11.u8);
	// stfs f0,600(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// stb r11,593(r31)
	PPC_STORE_U8(r31.u32 + 593, r11.u8);
	// stb r11,604(r31)
	PPC_STORE_U8(r31.u32 + 604, r11.u8);
	// li r6,608
	ctx.r6.s64 = 608;
	// stb r11,605(r31)
	PPC_STORE_U8(r31.u32 + 605, r11.u8);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,624
	ctx.r5.s64 = 624;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,640
	ctx.r4.s64 = 640;
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,656
	ctx.r3.s64 = 656;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stvx128 v63,r31,r4
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stvx128 v63,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,676(r31)
	PPC_STORE_U32(r31.u32 + 676, r11.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r10,-13624
	ctx.r5.s64 = ctx.r10.s64 + -13624;
	// lfs f11,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,672(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 672, temp.u32);
	// stw r11,680(r31)
	PPC_STORE_U32(r31.u32 + 680, r11.u32);
	// stfs f11,692(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 692, temp.u32);
	// stw r11,684(r31)
	PPC_STORE_U32(r31.u32 + 684, r11.u32);
	// stfs f13,696(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 696, temp.u32);
	// stb r11,688(r31)
	PPC_STORE_U8(r31.u32 + 688, r11.u8);
	// lfs f12,11412(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11412);
	ctx.f12.f64 = double(temp.f32);
	// stb r11,708(r31)
	PPC_STORE_U8(r31.u32 + 708, r11.u8);
	// stfs f12,700(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 700, temp.u32);
	// li r10,720
	ctx.r10.s64 = 720;
	// stfs f0,704(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 704, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f11,304(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// stfs f11,712(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 712, temp.u32);
	// addi r3,r31,132
	ctx.r3.s64 = r31.s64 + 132;
	// lfs f11,308(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 308);
	ctx.f11.f64 = double(temp.f32);
	// addi r4,r7,-12740
	ctx.r4.s64 = ctx.r7.s64 + -12740;
	// stfs f11,716(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 716, temp.u32);
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,736(r31)
	PPC_STORE_U8(r31.u32 + 736, r11.u8);
	// stfs f0,740(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 740, temp.u32);
	// stb r11,764(r31)
	PPC_STORE_U8(r31.u32 + 764, r11.u8);
	// stfs f13,744(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 744, temp.u32);
	// stb r11,772(r31)
	PPC_STORE_U8(r31.u32 + 772, r11.u8);
	// stfs f13,748(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 748, temp.u32);
	// stb r9,773(r31)
	PPC_STORE_U8(r31.u32 + 773, ctx.r9.u8);
	// stfs f13,752(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 752, temp.u32);
	// stb r11,774(r31)
	PPC_STORE_U8(r31.u32 + 774, r11.u8);
	// stfs f12,756(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 756, temp.u32);
	// stb r11,775(r31)
	PPC_STORE_U8(r31.u32 + 775, r11.u8);
	// stfs f0,760(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 760, temp.u32);
	// stfs f13,768(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 768, temp.u32);
	// bl 0x8254ab60
	ctx.lr = 0x8270E3F8;
	sub_8254AB60(ctx, base);
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

__attribute__((alias("__imp__sub_8270E410"))) PPC_WEAK_FUNC(sub_8270E410);
PPC_FUNC_IMPL(__imp__sub_8270E410) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270e42c
	if (cr6.eq) goto loc_8270E42C;
	// lwz r11,560(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 560);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8270e430
	if (!cr6.eq) goto loc_8270E430;
loc_8270E42C:
	// li r11,0
	r11.s64 = 0;
loc_8270E430:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E438"))) PPC_WEAK_FUNC(sub_8270E438);
PPC_FUNC_IMPL(__imp__sub_8270E438) {
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
	ctx.lr = 0x8270E440;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,24
	ctx.r3.s64 = 24;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82130528
	ctx.lr = 0x8270E458;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270e468
	if (cr6.eq) goto loc_8270E468;
	// bl 0x8271b830
	ctx.lr = 0x8270E464;
	sub_8271B830(ctx, base);
	// b 0x8270e46c
	goto loc_8270E46C;
loc_8270E468:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8270E46C:
	// stw r3,560(r31)
	PPC_STORE_U32(r31.u32 + 560, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270E488;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bcaa0
	ctx.lr = 0x8270E498;
	sub_822BCAA0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8270E4A0"))) PPC_WEAK_FUNC(sub_8270E4A0);
PPC_FUNC_IMPL(__imp__sub_8270E4A0) {
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
	// bl 0x822bb3a0
	ctx.lr = 0x8270E4B8;
	sub_822BB3A0(ctx, base);
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270e4fc
	if (cr6.eq) goto loc_8270E4FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270E4D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270e4f4
	if (cr6.eq) goto loc_8270E4F4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270E4F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8270E4F4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,560(r31)
	PPC_STORE_U32(r31.u32 + 560, r11.u32);
loc_8270E4FC:
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

__attribute__((alias("__imp__sub_8270E510"))) PPC_WEAK_FUNC(sub_8270E510);
PPC_FUNC_IMPL(__imp__sub_8270E510) {
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
	// bl 0x822bb410
	ctx.lr = 0x8270E530;
	sub_822BB410(ctx, base);
	// lbz r11,465(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 465);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270e544
	if (cr6.eq) goto loc_8270E544;
	// stw r30,564(r31)
	PPC_STORE_U32(r31.u32 + 564, r30.u32);
	// b 0x8270e54c
	goto loc_8270E54C;
loc_8270E544:
	// li r11,0
	r11.s64 = 0;
	// stw r11,564(r31)
	PPC_STORE_U32(r31.u32 + 564, r11.u32);
loc_8270E54C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270E560;
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

__attribute__((alias("__imp__sub_8270E578"))) PPC_WEAK_FUNC(sub_8270E578);
PPC_FUNC_IMPL(__imp__sub_8270E578) {
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
	// bl 0x826fd2c0
	ctx.lr = 0x8270E590;
	sub_826FD2C0(ctx, base);
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270E5A8;
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

__attribute__((alias("__imp__sub_8270E5BC"))) PPC_WEAK_FUNC(sub_8270E5BC);
PPC_FUNC_IMPL(__imp__sub_8270E5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E5C0"))) PPC_WEAK_FUNC(sub_8270E5C0);
PPC_FUNC_IMPL(__imp__sub_8270E5C0) {
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
	// bl 0x822bb470
	ctx.lr = 0x8270E5D8;
	sub_822BB470(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 300);
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,25360(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 25360, temp.u32);
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

__attribute__((alias("__imp__sub_8270E5FC"))) PPC_WEAK_FUNC(sub_8270E5FC);
PPC_FUNC_IMPL(__imp__sub_8270E5FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E600"))) PPC_WEAK_FUNC(sub_8270E600);
PPC_FUNC_IMPL(__imp__sub_8270E600) {
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
	// bl 0x826fd068
	ctx.lr = 0x8270E620;
	sub_826FD068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270e634
	if (cr6.eq) goto loc_8270E634;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8270e650
	goto loc_8270E650;
loc_8270E634:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd508
	ctx.lr = 0x8270E640;
	sub_826FD508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
loc_8270E650:
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

__attribute__((alias("__imp__sub_8270E668"))) PPC_WEAK_FUNC(sub_8270E668);
PPC_FUNC_IMPL(__imp__sub_8270E668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,744(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 744, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E68C"))) PPC_WEAK_FUNC(sub_8270E68C);
PPC_FUNC_IMPL(__imp__sub_8270E68C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E690"))) PPC_WEAK_FUNC(sub_8270E690);
PPC_FUNC_IMPL(__imp__sub_8270E690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,748(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 748, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E6B4"))) PPC_WEAK_FUNC(sub_8270E6B4);
PPC_FUNC_IMPL(__imp__sub_8270E6B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E6B8"))) PPC_WEAK_FUNC(sub_8270E6B8);
PPC_FUNC_IMPL(__imp__sub_8270E6B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fsel f13,f1,f1,f0
	ctx.f13.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fsel f11,f12,f0,f13
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f11,752(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 752, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E6DC"))) PPC_WEAK_FUNC(sub_8270E6DC);
PPC_FUNC_IMPL(__imp__sub_8270E6DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E6E0"))) PPC_WEAK_FUNC(sub_8270E6E0);
PPC_FUNC_IMPL(__imp__sub_8270E6E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - f0.f64));
	// lfs f13,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fsel f11,f12,f1,f0
	ctx.f11.f64 = ctx.f12.f64 >= 0.0 ? ctx.f1.f64 : f0.f64;
	// fsubs f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f13.f64));
	// fsel f9,f10,f13,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f11.f64;
	// stfs f9,756(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 756, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E708"))) PPC_WEAK_FUNC(sub_8270E708);
PPC_FUNC_IMPL(__imp__sub_8270E708) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x822a8108
	sub_822A8108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270E710"))) PPC_WEAK_FUNC(sub_8270E710);
PPC_FUNC_IMPL(__imp__sub_8270E710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270e734
	if (cr6.eq) goto loc_8270E734;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270e734
	if (cr6.eq) goto loc_8270E734;
	// lfs f1,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8270E734:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E740"))) PPC_WEAK_FUNC(sub_8270E740);
PPC_FUNC_IMPL(__imp__sub_8270E740) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270e768
	if (cr6.eq) goto loc_8270E768;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270e768
	if (cr6.eq) goto loc_8270E768;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r3,r11,272
	ctx.r3.s64 = r11.s64 + 272;
	// blr 
	return;
loc_8270E768:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2272
	ctx.r3.s64 = r11.s64 + 2272;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E774"))) PPC_WEAK_FUNC(sub_8270E774);
PPC_FUNC_IMPL(__imp__sub_8270E774) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E778"))) PPC_WEAK_FUNC(sub_8270E778);
PPC_FUNC_IMPL(__imp__sub_8270E778) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -16, f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x8270E79C;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// lfs f13,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f31,f31
	ctx.f12.f64 = double(float(f31.f64 * f31.f64));
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f10,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f8,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// lfs f6,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fcmpu cr6,f2,f12
	cr6.compare(ctx.f2.f64, ctx.f12.f64);
	// blt cr6,0x8270e7e4
	if (cr6.lt) goto loc_8270E7E4;
	// li r11,0
	r11.s64 = 0;
loc_8270E7E4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// lfd f31,-16(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E7FC"))) PPC_WEAK_FUNC(sub_8270E7FC);
PPC_FUNC_IMPL(__imp__sub_8270E7FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E800"))) PPC_WEAK_FUNC(sub_8270E800);
PPC_FUNC_IMPL(__imp__sub_8270E800) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270e844
	if (cr6.eq) goto loc_8270E844;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270e844
	if (cr6.eq) goto loc_8270E844;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f12,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,-13624
	ctx.r8.s64 = ctx.r10.s64 + -13624;
	// li r11,1
	r11.s64 = 1;
	// lfs f13,-7912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 312);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bgt cr6,0x8270e848
	if (cr6.gt) goto loc_8270E848;
loc_8270E844:
	// li r11,0
	r11.s64 = 0;
loc_8270E848:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E850"))) PPC_WEAK_FUNC(sub_8270E850);
PPC_FUNC_IMPL(__imp__sub_8270E850) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// bl 0x822a8108
	ctx.lr = 0x8270E870;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// vsubfp128 v62,v127,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f5,f11,f9,f6
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// blt cr6,0x8270e8c0
	if (cr6.lt) goto loc_8270E8C0;
	// li r11,0
	r11.s64 = 0;
loc_8270E8C0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E8DC"))) PPC_WEAK_FUNC(sub_8270E8DC);
PPC_FUNC_IMPL(__imp__sub_8270E8DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E8E0"))) PPC_WEAK_FUNC(sub_8270E8E0);
PPC_FUNC_IMPL(__imp__sub_8270E8E0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// bl 0x822a8108
	ctx.lr = 0x8270E900;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// vsubfp128 v62,v127,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f5,f11,f9,f6
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bgt cr6,0x8270e950
	if (cr6.gt) goto loc_8270E950;
	// li r11,0
	r11.s64 = 0;
loc_8270E950:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270E96C"))) PPC_WEAK_FUNC(sub_8270E96C);
PPC_FUNC_IMPL(__imp__sub_8270E96C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270E970"))) PPC_WEAK_FUNC(sub_8270E970);
PPC_FUNC_IMPL(__imp__sub_8270E970) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,564(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270e9b4
	if (cr6.eq) goto loc_8270E9B4;
	// lbz r11,880(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270e9b4
	if (cr6.eq) goto loc_8270E9B4;
loc_8270E99C:
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_8270E9B4:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826fd068
	ctx.lr = 0x8270E9C8;
	sub_826FD068(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8270e9ec
	if (!cr6.eq) goto loc_8270E9EC;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd508
	ctx.lr = 0x8270E9E0;
	sub_826FD508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270e99c
	if (cr6.eq) goto loc_8270E99C;
loc_8270E9EC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822be478
	ctx.lr = 0x8270EA00;
	sub_822BE478(ctx, base);
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

__attribute__((alias("__imp__sub_8270EA18"))) PPC_WEAK_FUNC(sub_8270EA18);
PPC_FUNC_IMPL(__imp__sub_8270EA18) {
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
	// stfs f0,588(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 588, temp.u32);
	// b 0x822bcb68
	sub_822BCB68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270EA28"))) PPC_WEAK_FUNC(sub_8270EA28);
PPC_FUNC_IMPL(__imp__sub_8270EA28) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,680(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 680);
	// b 0x822a8108
	sub_822A8108(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8270EA30"))) PPC_WEAK_FUNC(sub_8270EA30);
PPC_FUNC_IMPL(__imp__sub_8270EA30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 680);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ea54
	if (cr6.eq) goto loc_8270EA54;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ea54
	if (cr6.eq) goto loc_8270EA54;
	// lfs f1,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_8270EA54:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270EA60"))) PPC_WEAK_FUNC(sub_8270EA60);
PPC_FUNC_IMPL(__imp__sub_8270EA60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 680);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ea88
	if (cr6.eq) goto loc_8270EA88;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ea88
	if (cr6.eq) goto loc_8270EA88;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r3,r11,272
	ctx.r3.s64 = r11.s64 + 272;
	// blr 
	return;
loc_8270EA88:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r3,r11,2272
	ctx.r3.s64 = r11.s64 + 2272;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270EA94"))) PPC_WEAK_FUNC(sub_8270EA94);
PPC_FUNC_IMPL(__imp__sub_8270EA94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270EA98"))) PPC_WEAK_FUNC(sub_8270EA98);
PPC_FUNC_IMPL(__imp__sub_8270EA98) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// bl 0x822a8108
	ctx.lr = 0x8270EABC;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8270e778
	ctx.lr = 0x8270EAD0;
	sub_8270E778(ctx, base);
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

__attribute__((alias("__imp__sub_8270EAE8"))) PPC_WEAK_FUNC(sub_8270EAE8);
PPC_FUNC_IMPL(__imp__sub_8270EAE8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 680);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270eb2c
	if (cr6.eq) goto loc_8270EB2C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270eb2c
	if (cr6.eq) goto loc_8270EB2C;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f12,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,-13624
	ctx.r8.s64 = ctx.r10.s64 + -13624;
	// li r11,1
	r11.s64 = 1;
	// lfs f13,-7912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 312);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bgt cr6,0x8270eb30
	if (cr6.gt) goto loc_8270EB30;
loc_8270EB2C:
	// li r11,0
	r11.s64 = 0;
loc_8270EB30:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270EB38"))) PPC_WEAK_FUNC(sub_8270EB38);
PPC_FUNC_IMPL(__imp__sub_8270EB38) {
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
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// bl 0x822a8108
	ctx.lr = 0x8270EB54;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8270e850
	ctx.lr = 0x8270EB64;
	sub_8270E850(ctx, base);
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

__attribute__((alias("__imp__sub_8270EB78"))) PPC_WEAK_FUNC(sub_8270EB78);
PPC_FUNC_IMPL(__imp__sub_8270EB78) {
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
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// bl 0x822a8108
	ctx.lr = 0x8270EB94;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8270e8e0
	ctx.lr = 0x8270EBA4;
	sub_8270E8E0(ctx, base);
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

__attribute__((alias("__imp__sub_8270EBB8"))) PPC_WEAK_FUNC(sub_8270EBB8);
PPC_FUNC_IMPL(__imp__sub_8270EBB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,680(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 680);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r11,r11,2272
	r11.s64 = r11.s64 + 2272;
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270ebe8
	if (cr6.eq) goto loc_8270EBE8;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270ebe8
	if (cr6.eq) goto loc_8270EBE8;
	// lwz r10,128(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// addi r9,r10,272
	ctx.r9.s64 = ctx.r10.s64 + 272;
	// b 0x8270ebec
	goto loc_8270EBEC;
loc_8270EBE8:
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_8270EBEC:
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270ec10
	if (cr6.eq) goto loc_8270EC10;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270ec10
	if (cr6.eq) goto loc_8270EC10;
	// lwz r11,128(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
loc_8270EC10:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 * ctx.f13.f64));
	// lfs f11,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f9,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmadds f7,f11,f10,f12
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f10.f64 + ctx.f12.f64));
	// fmadds f6,f9,f8,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x8270ec4c
	if (cr6.gt) goto loc_8270EC4C;
	// li r11,0
	r11.s64 = 0;
loc_8270EC4C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270EC54"))) PPC_WEAK_FUNC(sub_8270EC54);
PPC_FUNC_IMPL(__imp__sub_8270EC54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270EC58"))) PPC_WEAK_FUNC(sub_8270EC58);
PPC_FUNC_IMPL(__imp__sub_8270EC58) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// bl 0x822a8108
	ctx.lr = 0x8270EC78;
	sub_822A8108(ctx, base);
	// addi r30,r3,32
	r30.s64 = ctx.r3.s64 + 32;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x8270EC84;
	sub_822A8108(ctx, base);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 * ctx.f11.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fmadds f7,f13,f9,f10
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f6,f12,f8,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f0
	cr6.compare(ctx.f6.f64, f0.f64);
	// bgt cr6,0x8270ecc4
	if (cr6.gt) goto loc_8270ECC4;
	// li r11,0
	r11.s64 = 0;
loc_8270ECC4:
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

__attribute__((alias("__imp__sub_8270ECE0"))) PPC_WEAK_FUNC(sub_8270ECE0);
PPC_FUNC_IMPL(__imp__sub_8270ECE0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,764(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 764);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ed10
	if (cr6.eq) goto loc_8270ED10;
	// lfs f1,760(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 760);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8270ed5c
	goto loc_8270ED5C;
loc_8270ED10:
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// bl 0x822a8108
	ctx.lr = 0x8270ED18;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x8270ED28;
	sub_822A8108(ctx, base);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v127,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c900
	ctx.lr = 0x8270ED44;
	sub_8216C900(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r7,764(r31)
	PPC_STORE_U8(r31.u32 + 764, ctx.r7.u8);
	// lfs f0,30288(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f1,760(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 760, temp.u32);
loc_8270ED5C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8270ED78"))) PPC_WEAK_FUNC(sub_8270ED78);
PPC_FUNC_IMPL(__imp__sub_8270ED78) {
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
	// lwz r11,564(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270edac
	if (cr6.eq) goto loc_8270EDAC;
	// lbz r11,872(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270edac
	if (cr6.eq) goto loc_8270EDAC;
	// bl 0x82256058
	ctx.lr = 0x8270EDA0;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8270edb0
	if (!cr6.eq) goto loc_8270EDB0;
loc_8270EDAC:
	// li r11,1
	r11.s64 = 1;
loc_8270EDB0:
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

__attribute__((alias("__imp__sub_8270EDC4"))) PPC_WEAK_FUNC(sub_8270EDC4);
PPC_FUNC_IMPL(__imp__sub_8270EDC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270EDC8"))) PPC_WEAK_FUNC(sub_8270EDC8);
PPC_FUNC_IMPL(__imp__sub_8270EDC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lwz r11,564(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ee04
	if (cr6.eq) goto loc_8270EE04;
	// lbz r11,880(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270f034
	if (!cr6.eq) goto loc_8270F034;
loc_8270EE04:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8270f034
	if (cr6.eq) goto loc_8270F034;
	// lwz r4,680(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8270f034
	if (cr6.eq) goto loc_8270F034;
	// lwz r11,568(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 568);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x8270f034
	if (cr6.eq) goto loc_8270F034;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// beq cr6,0x8270f034
	if (cr6.eq) goto loc_8270F034;
	// lwz r11,560(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,7
	cr6.compare<int32_t>(ctx.r10.s32, 7, xer);
	// bne cr6,0x8270ef04
	if (!cr6.eq) goto loc_8270EF04;
	// lfs f0,596(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	f0.f64 = double(temp.f32);
	// lbz r11,605(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 605);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,596(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ee64
	if (cr6.eq) goto loc_8270EE64;
	// li r11,2
	r11.s64 = 2;
	// stw r11,576(r31)
	PPC_STORE_U32(r31.u32 + 576, r11.u32);
	// b 0x8270f034
	goto loc_8270F034;
loc_8270EE64:
	// lbz r10,604(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 604);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r30,r11,-13624
	r30.s64 = r11.s64 + -13624;
	// beq cr6,0x8270ee84
	if (cr6.eq) goto loc_8270EE84;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,32668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32668);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8270ee88
	goto loc_8270EE88;
loc_8270EE84:
	// lfs f1,204(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 204);
	ctx.f1.f64 = double(temp.f32);
loc_8270EE88:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// bl 0x8270cfc8
	ctx.lr = 0x8270EE9C;
	sub_8270CFC8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270eeb8
	if (cr6.eq) goto loc_8270EEB8;
	// lfs f0,216(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 216);
	f0.f64 = double(temp.f32);
	// stfs f0,600(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// stfs f31,596(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// b 0x8270f034
	goto loc_8270F034;
loc_8270EEB8:
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f2,224(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 224);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,204(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 204);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,680(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x8270cfc8
	ctx.lr = 0x8270EED0;
	sub_8270CFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270eefc
	if (cr6.eq) goto loc_8270EEFC;
	// lfs f0,600(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 600);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,600(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// lfs f0,216(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 216);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8270f034
	if (!cr6.gt) goto loc_8270F034;
	// stfs f31,596(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// b 0x8270f034
	goto loc_8270F034;
loc_8270EEFC:
	// stfs f31,600(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// b 0x8270f034
	goto loc_8270F034;
loc_8270EF04:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r30,r11,-13624
	r30.s64 = r11.s64 + -13624;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f1,204(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 204);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// bl 0x8270cfc8
	ctx.lr = 0x8270EF24;
	sub_8270CFC8(ctx, base);
	// lfs f0,600(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 600);
	f0.f64 = double(temp.f32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,600(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270efa4
	if (cr6.eq) goto loc_8270EFA4;
	// stfs f31,596(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// bl 0x822a8108
	ctx.lr = 0x8270EF48;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// li r10,608
	ctx.r10.s64 = 608;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwz r11,48(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ef8c
	if (cr6.eq) goto loc_8270EF8C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ef8c
	if (cr6.eq) goto loc_8270EF8C;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// li r10,624
	ctx.r10.s64 = 624;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8270f034
	goto loc_8270F034;
loc_8270EF8C:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r10,624
	ctx.r10.s64 = 624;
	// addi r11,r11,2272
	r11.s64 = r11.s64 + 2272;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8270f034
	goto loc_8270F034;
loc_8270EFA4:
	// lbz r10,773(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 773);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270efd4
	if (cr6.eq) goto loc_8270EFD4;
	// lfs f0,596(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 596);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 + f30.f64));
	// stfs f13,596(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// lfs f0,212(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 212);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8270efd4
	if (!cr6.gt) goto loc_8270EFD4;
	// stfs f31,600(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// li r11,1
	r11.s64 = 1;
loc_8270EFD4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270f034
	if (!cr6.eq) goto loc_8270F034;
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// bl 0x822a8108
	ctx.lr = 0x8270EFE8;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// li r10,608
	ctx.r10.s64 = 608;
	// lvx128 v61,r3,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,680(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwz r11,48(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270f020
	if (cr6.eq) goto loc_8270F020;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270f020
	if (cr6.eq) goto loc_8270F020;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x8270f028
	goto loc_8270F028;
loc_8270F020:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// addi r11,r11,2272
	r11.s64 = r11.s64 + 2272;
loc_8270F028:
	// li r10,624
	ctx.r10.s64 = 624;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8270F034:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_8270F054"))) PPC_WEAK_FUNC(sub_8270F054);
PPC_FUNC_IMPL(__imp__sub_8270F054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270F058"))) PPC_WEAK_FUNC(sub_8270F058);
PPC_FUNC_IMPL(__imp__sub_8270F058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822bcb68
	ctx.lr = 0x8270F070;
	sub_822BCB68(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f0,-28880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28880);
	f0.f64 = double(temp.f32);
	// stfs f0,240(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 240, temp.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8270F094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r11,0
	r11.s64 = 0;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r8,608
	ctx.r8.s64 = 608;
	// li r7,624
	ctx.r7.s64 = 624;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,640
	ctx.r6.s64 = 640;
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,656
	ctx.r5.s64 = 656;
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r11.u32);
	// stw r11,576(r31)
	PPC_STORE_U32(r31.u32 + 576, r11.u32);
	// lis r4,-32125
	ctx.r4.s64 = -2105344000;
	// stb r11,592(r31)
	PPC_STORE_U8(r31.u32 + 592, r11.u8);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stb r11,593(r31)
	PPC_STORE_U8(r31.u32 + 593, r11.u8);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r11,604(r31)
	PPC_STORE_U8(r31.u32 + 604, r11.u8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r11,605(r31)
	PPC_STORE_U8(r31.u32 + 605, r11.u8);
	// addi r7,r4,-13624
	ctx.r7.s64 = ctx.r4.s64 + -13624;
	// stw r11,676(r31)
	PPC_STORE_U32(r31.u32 + 676, r11.u32);
	// lfs f0,3796(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,680(r31)
	PPC_STORE_U32(r31.u32 + 680, r11.u32);
	// lfs f11,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// stw r11,684(r31)
	PPC_STORE_U32(r31.u32 + 684, r11.u32);
	// lfs f13,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stb r11,688(r31)
	PPC_STORE_U8(r31.u32 + 688, r11.u8);
	// lfs f12,11412(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11412);
	ctx.f12.f64 = double(temp.f32);
	// stb r11,708(r31)
	PPC_STORE_U8(r31.u32 + 708, r11.u8);
	// stfs f0,572(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 572, temp.u32);
	// li r6,720
	ctx.r6.s64 = 720;
	// stfs f0,580(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// stfs f0,584(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// stfs f0,588(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// stfs f0,600(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// stfs f0,596(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
	// stfs f0,672(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 672, temp.u32);
	// stfs f11,692(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 692, temp.u32);
	// stfs f13,696(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 696, temp.u32);
	// stfs f12,700(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 700, temp.u32);
	// stfs f0,704(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 704, temp.u32);
	// lfs f11,304(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,712(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 712, temp.u32);
	// lfs f11,308(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 308);
	ctx.f11.f64 = double(temp.f32);
	// stb r11,736(r31)
	PPC_STORE_U8(r31.u32 + 736, r11.u8);
	// stfs f11,716(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 716, temp.u32);
	// stb r11,764(r31)
	PPC_STORE_U8(r31.u32 + 764, r11.u8);
	// stfs f0,740(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 740, temp.u32);
	// stb r11,772(r31)
	PPC_STORE_U8(r31.u32 + 772, r11.u8);
	// stfs f0,760(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 760, temp.u32);
	// stb r5,773(r31)
	PPC_STORE_U8(r31.u32 + 773, ctx.r5.u8);
	// stfs f13,768(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 768, temp.u32);
	// stb r11,775(r31)
	PPC_STORE_U8(r31.u32 + 775, r11.u8);
	// stfs f13,744(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 744, temp.u32);
	// stb r11,774(r31)
	PPC_STORE_U8(r31.u32 + 774, r11.u8);
	// stfs f13,748(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 748, temp.u32);
	// stfs f13,752(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 752, temp.u32);
	// stfs f12,756(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 756, temp.u32);
	// stvx128 v63,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

__attribute__((alias("__imp__sub_8270F1A0"))) PPC_WEAK_FUNC(sub_8270F1A0);
PPC_FUNC_IMPL(__imp__sub_8270F1A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r16{};
	PPCRegister r19{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x8270F1A8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r29,0
	r29.s64 = 0;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x8270f1ec
	if (!cr6.eq) goto loc_8270F1EC;
	// stfs f31,588(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// bl 0x822bcb68
	ctx.lr = 0x8270F1D8;
	sub_822BCB68(ctx, base);
	// stw r29,680(r31)
	PPC_STORE_U32(r31.u32 + 680, r29.u32);
	// stw r29,684(r31)
	PPC_STORE_U32(r31.u32 + 684, r29.u32);
	// stb r29,592(r31)
	PPC_STORE_U8(r31.u32 + 592, r29.u8);
	// stb r29,593(r31)
	PPC_STORE_U8(r31.u32 + 593, r29.u8);
	// b 0x8270f2e4
	goto loc_8270F2E4;
loc_8270F1EC:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// blt cr6,0x8270f2e4
	if (cr6.lt) goto loc_8270F2E4;
	// cmpwi cr6,r28,9
	cr6.compare<int32_t>(r28.s32, 9, xer);
	// bge cr6,0x8270f2e4
	if (!cr6.lt) goto loc_8270F2E4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,680(r31)
	PPC_STORE_U32(r31.u32 + 680, r11.u32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lfs f1,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// stw r8,684(r31)
	PPC_STORE_U32(r31.u32 + 684, ctx.r8.u32);
	// lfs f13,12(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fsel f12,f13,f13,f31
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? ctx.f13.f64 : f31.f64;
	// fsubs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f10,f11,f0,f12
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? f0.f64 : ctx.f12.f64;
	// stfs f10,704(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 704, temp.u32);
	// bl 0x822ba068
	ctx.lr = 0x8270F238;
	sub_822BA068(ctx, base);
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x8270f2e4
	if (cr6.gt) goto loc_8270F2E4;
	// lis r12,-32143
	r12.s64 = -2106523648;
	// addi r12,r12,-3492
	r12.s64 = r12.s64 + -3492;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8270F27C;
	case 1:
		goto loc_8270F2E4;
	case 2:
		goto loc_8270F2E4;
	case 3:
		goto loc_8270F2E4;
	case 4:
		goto loc_8270F2A0;
	case 5:
		goto loc_8270F2B4;
	case 6:
		goto loc_8270F2C0;
	case 7:
		goto loc_8270F2D4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-3460(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -3460);
	// lwz r19,-3356(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -3356);
	// lwz r19,-3356(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -3356);
	// lwz r19,-3356(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -3356);
	// lwz r19,-3424(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -3424);
	// lwz r19,-3404(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -3404);
	// lwz r19,-3392(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -3392);
	// lwz r19,-3372(r16)
	r19.u64 = PPC_LOAD_U32(r16.u32 + -3372);
loc_8270F27C:
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// stb r11,688(r31)
	PPC_STORE_U8(r31.u32 + 688, r11.u8);
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,692(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 692, temp.u32);
	// lfs f13,24(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,696(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 696, temp.u32);
	// lfs f12,28(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,700(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 700, temp.u32);
	// b 0x8270f2e4
	goto loc_8270F2E4;
loc_8270F2A0:
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// stb r11,708(r31)
	PPC_STORE_U8(r31.u32 + 708, r11.u8);
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,712(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 712, temp.u32);
	// b 0x8270f2e4
	goto loc_8270F2E4;
loc_8270F2B4:
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,716(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 716, temp.u32);
	// b 0x8270f2e4
	goto loc_8270F2E4;
loc_8270F2C0:
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// stb r11,736(r31)
	PPC_STORE_U8(r31.u32 + 736, r11.u8);
	// lfs f0,20(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,740(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 740, temp.u32);
	// b 0x8270f2e4
	goto loc_8270F2E4;
loc_8270F2D4:
	// li r11,16
	r11.s64 = 16;
	// li r10,720
	ctx.r10.s64 = 720;
	// lvx128 v63,r30,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8270F2E4:
	// lwz r10,568(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 568);
	// stfs f31,572(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 572, temp.u32);
	// stfs f31,580(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// stw r28,568(r31)
	PPC_STORE_U32(r31.u32 + 568, r28.u32);
	// stfs f31,584(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// stw r29,576(r31)
	PPC_STORE_U32(r31.u32 + 576, r29.u32);
	// cmpwi cr6,r28,7
	cr6.compare<int32_t>(r28.s32, 7, xer);
	// beq cr6,0x8270f30c
	if (cr6.eq) goto loc_8270F30C;
	// stfs f31,600(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 600, temp.u32);
	// stfs f31,596(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 596, temp.u32);
loc_8270F30C:
	// stb r29,604(r31)
	PPC_STORE_U8(r31.u32 + 604, r29.u8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stb r29,605(r31)
	PPC_STORE_U8(r31.u32 + 605, r29.u8);
	// beq cr6,0x8270f324
	if (cr6.eq) goto loc_8270F324;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// b 0x8270f328
	goto loc_8270F328;
loc_8270F324:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8270F328:
	// stw r11,676(r31)
	PPC_STORE_U32(r31.u32 + 676, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r29,772(r31)
	PPC_STORE_U8(r31.u32 + 772, r29.u8);
	// bne cr6,0x8270f344
	if (!cr6.eq) goto loc_8270F344;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8270f398
	if (cr6.eq) goto loc_8270F398;
	// stb r29,592(r31)
	PPC_STORE_U8(r31.u32 + 592, r29.u8);
loc_8270F344:
	// cmpw cr6,r10,r28
	cr6.compare<int32_t>(ctx.r10.s32, r28.s32, xer);
	// beq cr6,0x8270f398
	if (cr6.eq) goto loc_8270F398;
	// lwz r11,560(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270f398
	if (cr6.eq) goto loc_8270F398;
	// lwz r11,564(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270f380
	if (cr6.eq) goto loc_8270F380;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lwz r6,868(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 868);
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r10,29184
	ctx.r5.s64 = ctx.r10.s64 + 29184;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82130000
	ctx.lr = 0x8270F380;
	sub_82130000(ctx, base);
loc_8270F380:
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270F398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8270F398:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// bl 0x8271bae8
	ctx.lr = 0x8270F3A4;
	sub_8271BAE8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8270F3B0"))) PPC_WEAK_FUNC(sub_8270F3B0);
PPC_FUNC_IMPL(__imp__sub_8270F3B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822badd0
	ctx.lr = 0x8270F3D4;
	sub_822BADD0(ctx, base);
	// lhz r11,180(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 180);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bge cr6,0x8270f3f4
	if (!cr6.lt) goto loc_8270F3F4;
	// lwz r11,176(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// rlwinm r10,r3,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 5) & 0xFFFFFFE0;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8270f408
	goto loc_8270F408;
loc_8270F3F4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,11412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11412);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 0, temp.u32);
	// stfs f0,4(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 4, temp.u32);
	// stfs f0,8(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 8, temp.u32);
loc_8270F408:
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

__attribute__((alias("__imp__sub_8270F424"))) PPC_WEAK_FUNC(sub_8270F424);
PPC_FUNC_IMPL(__imp__sub_8270F424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270F428"))) PPC_WEAK_FUNC(sub_8270F428);
PPC_FUNC_IMPL(__imp__sub_8270F428) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
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
	// bl 0x823d91f8
	ctx.lr = 0x8270F430;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// li r12,-96
	r12.s64 = -96;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-80
	r12.s64 = -80;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// vor128 v126,v2,v2
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_load_si128((simde__m128i*)ctx.v2.u8));
	// lwz r11,564(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270f474
	if (cr6.eq) goto loc_8270F474;
	// lbz r11,880(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270f69c
	if (!cr6.eq) goto loc_8270F69C;
loc_8270F474:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,588(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 588);
	f0.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8270f494
	if (cr6.eq) goto loc_8270F494;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8270F494:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270f69c
	if (cr6.eq) goto loc_8270F69C;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826fd068
	ctx.lr = 0x8270F4B4;
	sub_826FD068(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8270f5c4
	if (!cr6.eq) goto loc_8270F5C4;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd508
	ctx.lr = 0x8270F4CC;
	sub_826FD508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270f5c4
	if (!cr6.eq) goto loc_8270F5C4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stw r30,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r30.u32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// stfs f31,128(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lfs f0,30712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	f0.f64 = double(temp.f32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r9,2256
	ctx.r7.s64 = ctx.r9.s64 + 2256;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// lvx128 v62,r0,r4
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,-1
	ctx.r3.s64 = -1;
	// lvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v61.f32)));
	// vaddfp128 v59,v62,v60
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,272
	r29.s64 = ctx.r1.s64 + 272;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,256
	r28.s64 = ctx.r1.s64 + 256;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r3,236(r1)
	PPC_STORE_U16(ctx.r1.u32 + 236, ctx.r3.u16);
	// lwz r3,-23452(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23452);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// stfs f31,224(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stfs f31,228(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// li r7,2048
	ctx.r7.s64 = 2048;
	// sth r30,238(r1)
	PPC_STORE_U16(ctx.r1.u32 + 238, r30.u16);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r30,240(r1)
	PPC_STORE_U8(ctx.r1.u32 + 240, r30.u8);
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// sth r30,242(r1)
	PPC_STORE_U16(ctx.r1.u32 + 242, r30.u16);
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// stw r30,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r30.u32);
	// stvx128 v58,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x8270F59C;
	sub_82574418(ctx, base);
	// lwz r8,160(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270f5c4
	if (cr6.eq) goto loc_8270F5C4;
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826fd508
	ctx.lr = 0x8270F5C4;
	sub_826FD508(ctx, base);
loc_8270F5C4:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd068
	ctx.lr = 0x8270F5D0;
	sub_826FD068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270f65c
	if (cr6.eq) goto loc_8270F65C;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,27640(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,208(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	f0.f64 = double(temp.f32);
	// stfs f0,588(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// bl 0x822be478
	ctx.lr = 0x8270F600;
	sub_822BE478(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x8221d030
	ctx.lr = 0x8270F60C;
	sub_8221D030(ctx, base);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stfs f31,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stvx128 v126,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f1,31292(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v1,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x8270F640;
	sub_82165300(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b9fc0
	ctx.lr = 0x8270F64C;
	sub_822B9FC0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r4,593(r31)
	PPC_STORE_U8(r31.u32 + 593, ctx.r4.u8);
	// b 0x8270f6a0
	goto loc_8270F6A0;
loc_8270F65C:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r10,29240
	ctx.r5.s64 = ctx.r10.s64 + 29240;
	// li r3,1
	ctx.r3.s64 = 1;
	// stvx128 v127,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// stfd f1,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.f1.u64);
	// ld r6,40(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 40);
	// stfd f2,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.f2.u64);
	// ld r7,48(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 48);
	// stfd f3,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f3.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// bl 0x82130000
	ctx.lr = 0x8270F69C;
	sub_82130000(ctx, base);
loc_8270F69C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8270F6A0:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// li r0,-96
	r0.s64 = -96;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-80
	r0.s64 = -80;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8270F6C0"))) PPC_WEAK_FUNC(sub_8270F6C0);
PPC_FUNC_IMPL(__imp__sub_8270F6C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x8270F6C8;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d8
	ctx.lr = 0x8270F6D0;
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r11,772(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 772);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270fbb4
	if (!cr6.eq) goto loc_8270FBB4;
	// lwz r11,564(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270f704
	if (cr6.eq) goto loc_8270F704;
	// lbz r11,880(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270fbb4
	if (!cr6.eq) goto loc_8270FBB4;
loc_8270F704:
	// lwz r3,560(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 560);
	// bl 0x8271bb08
	ctx.lr = 0x8270F70C;
	sub_8271BB08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fbb4
	if (cr6.eq) goto loc_8270FBB4;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10012(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fbb4
	if (cr6.eq) goto loc_8270FBB4;
	// lhz r28,180(r29)
	r28.u64 = PPC_LOAD_U16(r29.u32 + 180);
	// li r30,0
	r30.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// li r27,0
	r27.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x8270f75c
	if (!cr6.gt) goto loc_8270F75C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822b9f70
	ctx.lr = 0x8270F74C;
	sub_822B9F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8270f760
	if (!cr6.eq) goto loc_8270F760;
loc_8270F75C:
	// li r11,0
	r11.s64 = 0;
loc_8270F760:
	// clrlwi r24,r11,24
	r24.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x8270f774
	if (!cr6.eq) goto loc_8270F774;
	// li r26,-1
	r26.s64 = -1;
	// b 0x8270f780
	goto loc_8270F780;
loc_8270F774:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822badd0
	ctx.lr = 0x8270F77C;
	sub_822BADD0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
loc_8270F780:
	// lwz r3,680(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 680);
	// bl 0x822a8108
	ctx.lr = 0x8270F788;
	sub_822A8108(ctx, base);
	// lwz r11,680(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 680);
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lvx128 v127,r3,r10
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270f7c4
	if (cr6.eq) goto loc_8270F7C4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270f7c4
	if (cr6.eq) goto loc_8270F7C4;
	// lfs f28,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f28.f64 = double(temp.f32);
	// b 0x8270f7c8
	goto loc_8270F7C8;
loc_8270F7C4:
	// fmr f28,f31
	ctx.fpscr.disableFlushMode();
	f28.f64 = f31.f64;
loc_8270F7C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,774(r29)
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + 774);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f30,14884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f30.f64 = double(temp.f32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r11,r11,-13624
	r11.s64 = r11.s64 + -13624;
	// lfs f0,208(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 208);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8270f7f0
	if (cr6.eq) goto loc_8270F7F0;
	// fmuls f29,f0,f30
	f29.f64 = double(float(f0.f64 * f30.f64));
	// b 0x8270f7f4
	goto loc_8270F7F4;
loc_8270F7F0:
	// fmr f29,f0
	ctx.fpscr.disableFlushMode();
	f29.f64 = f0.f64;
loc_8270F7F4:
	// lfs f13,588(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 588);
	ctx.f13.f64 = double(temp.f32);
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// beq cr6,0x8270fa44
	if (cr6.eq) goto loc_8270FA44;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270f824
	if (cr6.eq) goto loc_8270F824;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// beq cr6,0x8270fa44
	if (cr6.eq) goto loc_8270FA44;
loc_8270F824:
	// lbz r11,775(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 775);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270f838
	if (cr6.eq) goto loc_8270F838;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270fa44
	if (cr6.eq) goto loc_8270FA44;
loc_8270F838:
	// lwz r11,684(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 684);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fa48
	if (cr6.eq) goto loc_8270FA48;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f12,-332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x8270fa48
	if (!cr6.lt) goto loc_8270FA48;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r29,656
	ctx.r3.s64 = r29.s64 + 656;
	// bl 0x8216c900
	ctx.lr = 0x8270F864;
	sub_8216C900(ctx, base);
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lfs f0,-30864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30864);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x8270fa24
	if (!cr6.gt) goto loc_8270FA24;
	// lwz r11,684(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 684);
	// li r27,1
	r27.s64 = 1;
	// li r30,1
	r30.s64 = 1;
	// lwz r11,56(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fa48
	if (cr6.eq) goto loc_8270FA48;
	// lis r9,6
	ctx.r9.s64 = 393216;
	// lwz r10,-10012(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// lwz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// ori r6,r9,16712
	ctx.r6.u64 = ctx.r9.u64 | 16712;
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r8,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// fneg f10,f0
	ctx.f10.u64 = f0.u64 ^ 0x8000000000000000;
	// fneg f9,f13
	ctx.f9.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfs f6,24528(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24528);
	ctx.f6.f64 = double(temp.f32);
	// lwzx r5,r10,r6
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// lwz r10,60(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 60);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8270fa48
	if (!cr6.gt) goto loc_8270FA48;
	// lfs f8,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f7,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f7.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfd f12,21560(r7)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r7.u32 + 21560);
	// lfd f11,32224(r11)
	ctx.f11.u64 = PPC_LOAD_U64(r11.u32 + 32224);
loc_8270F8F0:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f0,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	f0.f64 = double(temp.f32);
	// fsubs f0,f0,f8
	f0.f64 = double(float(f0.f64 - ctx.f8.f64));
	// lfs f13,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f7
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f7.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bne cr6,0x8270f914
	if (!cr6.eq) goto loc_8270F914;
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// beq cr6,0x8270f974
	if (cr6.eq) goto loc_8270F974;
loc_8270F914:
	// fmuls f5,f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f4,f13,f13,f5
	ctx.f4.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f5.f64));
	// frsqrte f3,f4
	// fneg f2,f4
	ctx.f2.u64 = ctx.f4.u64 ^ 0x8000000000000000;
	// fmul f1,f3,f3
	ctx.f1.f64 = ctx.f3.f64 * ctx.f3.f64;
	// fmul f5,f3,f11
	ctx.f5.f64 = ctx.f3.f64 * ctx.f11.f64;
	// fnmsub f1,f1,f4,f12
	ctx.f1.f64 = -(ctx.f1.f64 * ctx.f4.f64 - ctx.f12.f64);
	// fmadd f5,f1,f5,f3
	ctx.f5.f64 = ctx.f1.f64 * ctx.f5.f64 + ctx.f3.f64;
	// fmul f3,f5,f5
	ctx.f3.f64 = ctx.f5.f64 * ctx.f5.f64;
	// fmul f1,f5,f11
	ctx.f1.f64 = ctx.f5.f64 * ctx.f11.f64;
	// fnmsub f4,f3,f4,f12
	ctx.f4.f64 = -(ctx.f3.f64 * ctx.f4.f64 - ctx.f12.f64);
	// fmadd f3,f4,f1,f5
	ctx.f3.f64 = ctx.f4.f64 * ctx.f1.f64 + ctx.f5.f64;
	// frsp f1,f3
	ctx.f1.f64 = double(float(ctx.f3.f64));
	// fsel f5,f2,f31,f1
	ctx.f5.f64 = ctx.f2.f64 >= 0.0 ? f31.f64 : ctx.f1.f64;
	// fmuls f4,f5,f0
	ctx.f4.f64 = double(float(ctx.f5.f64 * f0.f64));
	// fmuls f3,f13,f5
	ctx.f3.f64 = double(float(ctx.f13.f64 * ctx.f5.f64));
	// fmuls f2,f4,f10
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f10.f64));
	// fmadds f0,f3,f9,f2
	f0.f64 = double(float(ctx.f3.f64 * ctx.f9.f64 + ctx.f2.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8270f974
	if (!cr6.gt) goto loc_8270F974;
	// fcmpu cr6,f0,f6
	cr6.compare(f0.f64, ctx.f6.f64);
	// ble cr6,0x8270f974
	if (!cr6.gt) goto loc_8270F974;
	// fmr f6,f0
	ctx.f6.f64 = f0.f64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_8270F974:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8270f8f0
	if (!cr0.eq) goto loc_8270F8F0;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8270fa48
	if (cr6.eq) goto loc_8270FA48;
	// lwz r4,36(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8270fa48
	if (cr6.eq) goto loc_8270FA48;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270F9AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826fd0a8
	ctx.lr = 0x8270F9C4;
	sub_826FD0A8(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8270fa18
	if (!cr6.eq) goto loc_8270FA18;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826fd618
	ctx.lr = 0x8270F9DC;
	sub_826FD618(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270fa18
	if (!cr6.eq) goto loc_8270FA18;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826fd068
	ctx.lr = 0x8270F9F4;
	sub_826FD068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270fa18
	if (!cr6.eq) goto loc_8270FA18;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826fd508
	ctx.lr = 0x8270FA0C;
	sub_826FD508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fa48
	if (cr6.eq) goto loc_8270FA48;
loc_8270FA18:
	// li r27,0
	r27.s64 = 0;
	// li r25,1
	r25.s64 = 1;
	// b 0x8270fa48
	goto loc_8270FA48;
loc_8270FA24:
	// lfs f0,672(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 672);
	f0.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// fsubs f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 - f28.f64));
	// lfs f0,24920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24920);
	f0.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x8270fa48
	if (!cr6.gt) goto loc_8270FA48;
	// li r27,1
	r27.s64 = 1;
loc_8270FA44:
	// li r30,1
	r30.s64 = 1;
loc_8270FA48:
	// clrlwi r31,r30,24
	r31.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8270fa74
	if (!cr6.eq) goto loc_8270FA74;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x8270fa74
	if (cr6.eq) goto loc_8270FA74;
	// addi r11,r28,-1
	r11.s64 = r28.s64 + -1;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// bne cr6,0x8270fa78
	if (!cr6.eq) goto loc_8270FA78;
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fa78
	if (cr6.eq) goto loc_8270FA78;
loc_8270FA74:
	// li r23,1
	r23.s64 = 1;
loc_8270FA78:
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x8270FA80;
	sub_822A8108(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8270fa94
	if (cr6.eq) goto loc_8270FA94;
	// stfs f31,588(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + 588, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822bcb68
	ctx.lr = 0x8270FA94;
	sub_822BCB68(ctx, base);
loc_8270FA94:
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fbb4
	if (cr6.eq) goto loc_8270FBB4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// clrlwi r9,r25,24
	ctx.r9.u64 = r25.u32 & 0xFF;
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// lfs f13,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x8270faf4
	if (cr6.eq) goto loc_8270FAF4;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// stfs f28,80(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8270fb44
	goto loc_8270FB44;
loc_8270FAF4:
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fb20
	if (cr6.eq) goto loc_8270FB20;
	// li r11,640
	r11.s64 = 640;
	// stfs f28,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lvx128 v63,r29,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8270fb44
	goto loc_8270FB44;
loc_8270FB20:
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lwz r3,560(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 560);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// bl 0x8271bb88
	ctx.lr = 0x8270FB38;
	sub_8271BB88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fb48
	if (cr6.eq) goto loc_8270FB48;
loc_8270FB44:
	// li r31,1
	r31.s64 = 1;
loc_8270FB48:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fbb4
	if (cr6.eq) goto loc_8270FBB4;
	// stfs f29,588(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r29.u32 + 588, temp.u32);
	// addi r30,r1,160
	r30.s64 = ctx.r1.s64 + 160;
	// li r31,2
	r31.s64 = 2;
loc_8270FB60:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lfs f1,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822be478
	ctx.lr = 0x8270FB70;
	sub_822BE478(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x8270fb60
	if (!cr0.eq) goto loc_8270FB60;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8221d030
	ctx.lr = 0x8270FB88;
	sub_8221D030(ctx, base);
	// stfs f31,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f31,152(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822b9fc0
	ctx.lr = 0x8270FBA0;
	sub_822B9FC0(ctx, base);
	// li r11,656
	r11.s64 = 656;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,593(r29)
	PPC_STORE_U8(r29.u32 + 593, ctx.r10.u8);
	// stvx128 v127,r29,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f28,672(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r29.u32 + 672, temp.u32);
loc_8270FBB4:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba24
	ctx.lr = 0x8270FBC8;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8270FBCC"))) PPC_WEAK_FUNC(sub_8270FBCC);
PPC_FUNC_IMPL(__imp__sub_8270FBCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8270FBD0"))) PPC_WEAK_FUNC(sub_8270FBD0);
PPC_FUNC_IMPL(__imp__sub_8270FBD0) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r9,r11,29116
	ctx.r9.s64 = r11.s64 + 29116;
	// lwz r10,560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270fc08
	if (cr6.eq) goto loc_8270FC08;
	// bl 0x8270e4a0
	ctx.lr = 0x8270FC08;
	sub_8270E4A0(ctx, base);
loc_8270FC08:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822bca08
	ctx.lr = 0x8270FC10;
	sub_822BCA08(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fc28
	if (cr6.eq) goto loc_8270FC28;
	// bl 0x82130588
	ctx.lr = 0x8270FC24;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8270FC28:
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

__attribute__((alias("__imp__sub_8270FC40"))) PPC_WEAK_FUNC(sub_8270FC40);
PPC_FUNC_IMPL(__imp__sub_8270FC40) {
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
	ctx.lr = 0x8270FC48;
	// stfd f29,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f29.u64);
	// stfd f30,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f30.u64);
	// stfd f31,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f29,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f29.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = f29.f64;
	// bl 0x8270edc8
	ctx.lr = 0x8270FC70;
	sub_8270EDC8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r26,1
	r26.s64 = 1;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// lfs f30,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f30.f64 = double(temp.f32);
	// stfs f0,768(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 768, temp.u32);
	// beq cr6,0x8270ff40
	if (cr6.eq) goto loc_8270FF40;
	// bl 0x822a8108
	ctx.lr = 0x8270FC9C;
	sub_822A8108(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x8270FCA8;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f13,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f12,48(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// addi r28,r11,-13624
	r28.s64 = r11.s64 + -13624;
	// mr r11,r26
	r11.u64 = r26.u64;
	// lfs f11,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// lfs f0,428(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 428);
	f0.f64 = double(temp.f32);
	// fmuls f5,f0,f0
	ctx.f5.f64 = double(float(f0.f64 * f0.f64));
	// fmuls f4,f10,f10
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f6,f6,f3
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fcmpu cr6,f2,f5
	cr6.compare(ctx.f2.f64, ctx.f5.f64);
	// bgt cr6,0x8270fcfc
	if (cr6.gt) goto loc_8270FCFC;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8270FCFC:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stb r11,236(r31)
	PPC_STORE_U8(r31.u32 + 236, r11.u8);
	// lfs f0,312(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 312);
	f0.f64 = double(temp.f32);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lfs f31,-7912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	f31.f64 = double(temp.f32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270fd3c
	if (cr6.eq) goto loc_8270FD3C;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270fd3c
	if (cr6.eq) goto loc_8270FD3C;
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 * f31.f64));
	// lfs f12,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// mr r11,r26
	r11.u64 = r26.u64;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bgt cr6,0x8270fd40
	if (cr6.gt) goto loc_8270FD40;
loc_8270FD3C:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8270FD40:
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// li r30,32
	r30.s64 = 32;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r29,r11,2272
	r29.s64 = r11.s64 + 2272;
	// beq cr6,0x8270fd80
	if (cr6.eq) goto loc_8270FD80;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270fd78
	if (cr6.eq) goto loc_8270FD78;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270fd78
	if (cr6.eq) goto loc_8270FD78;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x8270fda0
	goto loc_8270FDA0;
loc_8270FD78:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8270fda0
	goto loc_8270FDA0;
loc_8270FD80:
	// bl 0x822a8108
	ctx.lr = 0x8270FD84;
	sub_822A8108(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v62,r3,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,312(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 312);
	f0.f64 = double(temp.f32);
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8270FDA0:
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270fddc
	if (cr6.eq) goto loc_8270FDDC;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270fddc
	if (cr6.eq) goto loc_8270FDDC;
	// fmuls f0,f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f31.f64));
	// lfs f13,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r26
	r11.u64 = r26.u64;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8270fde0
	if (cr6.gt) goto loc_8270FDE0;
loc_8270FDDC:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8270FDE0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270fe14
	if (cr6.eq) goto loc_8270FE14;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270fe0c
	if (cr6.eq) goto loc_8270FE0C;
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270fe0c
	if (cr6.eq) goto loc_8270FE0C;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x8270fe30
	goto loc_8270FE30;
loc_8270FE0C:
	// mr r11,r29
	r11.u64 = r29.u64;
	// b 0x8270fe30
	goto loc_8270FE30;
loc_8270FE14:
	// bl 0x822a8108
	ctx.lr = 0x8270FE18;
	sub_822A8108(ctx, base);
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v58,r3,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// vsubfp128 v57,v59,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8270FE30:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c900
	ctx.lr = 0x8270FE48;
	sub_8216C900(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lfs f0,30288(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30288);
	f0.f64 = double(temp.f32);
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f0,768(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 768, temp.u32);
	// bl 0x822a8108
	ctx.lr = 0x8270FE60;
	sub_822A8108(ctx, base);
	// addi r8,r3,48
	ctx.r8.s64 = ctx.r3.s64 + 48;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826fd068
	ctx.lr = 0x8270FE7C;
	sub_826FD068(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8270fea0
	if (!cr6.eq) goto loc_8270FEA0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd508
	ctx.lr = 0x8270FE94;
	sub_826FD508(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270feb0
	if (cr6.eq) goto loc_8270FEB0;
loc_8270FEA0:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r10,640
	ctx.r10.s64 = 640;
	// lvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8270FEB0:
	// lbz r11,774(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 774);
	// stb r27,774(r31)
	PPC_STORE_U8(r31.u32 + 774, r27.u8);
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// stb r11,775(r31)
	PPC_STORE_U8(r31.u32 + 775, r11.u8);
	// bl 0x822a8108
	ctx.lr = 0x8270FEC4;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8270e850
	ctx.lr = 0x8270FED4;
	sub_8270E850(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8270ff40
	if (cr6.eq) goto loc_8270FF40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270ebb8
	ctx.lr = 0x8270FEE8;
	sub_8270EBB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270ff40
	if (!cr6.eq) goto loc_8270FF40;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270ec58
	ctx.lr = 0x8270FEFC;
	sub_8270EC58(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270ff40
	if (!cr6.eq) goto loc_8270FF40;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,680(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f30.f64;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x8270cfc8
	ctx.lr = 0x8270FF20;
	sub_8270CFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ff40
	if (cr6.eq) goto loc_8270FF40;
	// lfs f13,768(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 768);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,400(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 400);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8270ff40
	if (!cr6.gt) goto loc_8270FF40;
	// stb r26,774(r31)
	PPC_STORE_U8(r31.u32 + 774, r26.u8);
loc_8270FF40:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8270f6c0
	ctx.lr = 0x8270FF48;
	sub_8270F6C0(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ffa0
	if (cr6.eq) goto loc_8270FFA0;
	// lbz r10,465(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 465);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8270ffa0
	if (cr6.eq) goto loc_8270FFA0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ffa0
	if (cr6.eq) goto loc_8270FFA0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ffa0
	if (cr6.eq) goto loc_8270FFA0;
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8270ffa0
	if (cr6.eq) goto loc_8270FFA0;
	// lwz r11,564(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8270ffa0
	if (cr6.eq) goto loc_8270FFA0;
	// lbz r11,872(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 872);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8270ffa0
	if (!cr6.eq) goto loc_8270FFA0;
	// sth r26,18(r10)
	PPC_STORE_U16(ctx.r10.u32 + 18, r26.u16);
loc_8270FFA0:
	// lwz r3,560(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// stb r27,764(r31)
	PPC_STORE_U8(r31.u32 + 764, r27.u8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8270FFBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,568(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 568);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8270ffe0
	if (cr6.eq) goto loc_8270FFE0;
	// lwz r10,576(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 576);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8270ffe0
	if (!cr6.eq) goto loc_8270FFE0;
	// lfs f0,572(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 572);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// stfs f13,572(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 572, temp.u32);
loc_8270FFE0:
	// lfs f0,588(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 588);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82710000
	if (!cr6.gt) goto loc_82710000;
	// fsubs f0,f0,f29
	f0.f64 = double(float(f0.f64 - f29.f64));
	// stfs f0,588(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x82710000
	if (!cr6.lt) goto loc_82710000;
	// stfs f30,588(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 588, temp.u32);
loc_82710000:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710054
	if (cr6.eq) goto loc_82710054;
	// lwz r11,564(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 564);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82710050
	if (cr6.eq) goto loc_82710050;
	// lbz r11,880(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82710050
	if (!cr6.eq) goto loc_82710050;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x82710028;
	sub_822A8108(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd068
	ctx.lr = 0x82710034;
	sub_826FD068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82710050
	if (!cr6.eq) goto loc_82710050;
	// lfs f0,584(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 584);
	f0.f64 = double(temp.f32);
	// fadds f13,f29,f0
	ctx.f13.f64 = double(float(f29.f64 + f0.f64));
	// stfs f13,584(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
	// b 0x82710054
	goto loc_82710054;
loc_82710050:
	// stfs f30,584(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 584, temp.u32);
loc_82710054:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x8271005C;
	sub_822A8108(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8270f3b0
	ctx.lr = 0x8271006C;
	sub_8270F3B0(ctx, base);
	// lfs f0,52(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	f0.f64 = double(temp.f32);
	// lfs f11,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lis r11,-32250
	r11.s64 = -2113536000;
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// lfs f13,56(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f12,48(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// lfs f0,16680(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16680);
	f0.f64 = double(temp.f32);
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f3,f6,f6,f4
	ctx.f3.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f3,f0
	cr6.compare(ctx.f3.f64, f0.f64);
	// bge cr6,0x827100bc
	if (!cr6.lt) goto loc_827100BC;
	// lfs f0,580(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 580);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// stfs f13,580(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
	// b 0x827100c0
	goto loc_827100C0;
loc_827100BC:
	// stfs f30,580(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 580, temp.u32);
loc_827100C0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822be670
	ctx.lr = 0x827100C8;
	sub_822BE670(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

__attribute__((alias("__imp__sub_827100DC"))) PPC_WEAK_FUNC(sub_827100DC);
PPC_FUNC_IMPL(__imp__sub_827100DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827100E0"))) PPC_WEAK_FUNC(sub_827100E0);
PPC_FUNC_IMPL(__imp__sub_827100E0) {
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827101c8
	if (cr6.eq) goto loc_827101C8;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827101c8
	if (cr6.eq) goto loc_827101C8;
	// bl 0x822bcfe0
	ctx.lr = 0x82710118;
	sub_822BCFE0(ctx, base);
	// lbz r11,252(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82710134
	if (cr6.eq) goto loc_82710134;
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,592(r31)
	PPC_STORE_U8(r31.u32 + 592, r11.u8);
	// stb r10,593(r31)
	PPC_STORE_U8(r31.u32 + 593, ctx.r10.u8);
loc_82710134:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// lfs f12,11412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11412);
	ctx.f12.f64 = double(temp.f32);
	// beq cr6,0x827101b0
	if (cr6.eq) goto loc_827101B0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,744(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 744);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82710170
	if (cr6.lt) goto loc_82710170;
	// stfs f13,156(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 156, temp.u32);
	// lfs f13,744(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 744);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82710190
	if (!cr6.gt) goto loc_82710190;
	// stfs f0,160(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 160, temp.u32);
	// b 0x82710190
	goto loc_82710190;
loc_82710170:
	// lfs f13,748(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 748);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// blt cr6,0x82710190
	if (cr6.lt) goto loc_82710190;
	// stfs f13,160(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 160, temp.u32);
	// lfs f13,748(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 748);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82710190
	if (!cr6.gt) goto loc_82710190;
	// stfs f0,156(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 156, temp.u32);
loc_82710190:
	// lfs f13,752(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 752);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x827101a0
	if (!cr6.gt) goto loc_827101A0;
	// stfs f13,164(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 164, temp.u32);
loc_827101A0:
	// lfs f0,756(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 756);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	cr6.compare(f0.f64, ctx.f12.f64);
	// beq cr6,0x827101b0
	if (cr6.eq) goto loc_827101B0;
	// stfs f0,152(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 152, temp.u32);
loc_827101B0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f12,756(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 756, temp.u32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,744(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 744, temp.u32);
	// stfs f0,748(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 748, temp.u32);
	// stfs f0,752(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 752, temp.u32);
loc_827101C8:
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

__attribute__((alias("__imp__sub_827101E0"))) PPC_WEAK_FUNC(sub_827101E0);
PPC_FUNC_IMPL(__imp__sub_827101E0) {
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
	// lbz r11,28(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82710254
	if (cr6.eq) goto loc_82710254;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82710210;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82710254
	if (!cr6.eq) goto loc_82710254;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x82710254
	if (cr6.gt) goto loc_82710254;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82710244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82710258
	if (cr6.eq) goto loc_82710258;
loc_82710254:
	// li r11,0
	r11.s64 = 0;
loc_82710258:
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

__attribute__((alias("__imp__sub_82710270"))) PPC_WEAK_FUNC(sub_82710270);
PPC_FUNC_IMPL(__imp__sub_82710270) {
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
	// lbz r11,31(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 31);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827102b8
	if (cr6.eq) goto loc_827102B8;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827102b8
	if (cr6.eq) goto loc_827102B8;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827102A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x827102bc
	if (!cr6.eq) goto loc_827102BC;
loc_827102B8:
	// li r11,0
	r11.s64 = 0;
loc_827102BC:
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

__attribute__((alias("__imp__sub_827102D0"))) PPC_WEAK_FUNC(sub_827102D0);
PPC_FUNC_IMPL(__imp__sub_827102D0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lfs f13,108(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r11,-13624
	ctx.r10.s64 = r11.s64 + -13624;
	// lfs f0,360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 360);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8271030c
	if (cr6.gt) goto loc_8271030C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,140(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 140);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8271030c
	if (cr6.gt) goto loc_8271030C;
	// lfs f13,144(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82710310
	if (!cr6.gt) goto loc_82710310;
loc_8271030C:
	// li r11,1
	r11.s64 = 1;
loc_82710310:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82710318"))) PPC_WEAK_FUNC(sub_82710318);
PPC_FUNC_IMPL(__imp__sub_82710318) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82710370
	if (cr6.eq) goto loc_82710370;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710364
	if (cr6.eq) goto loc_82710364;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710364
	if (cr6.eq) goto loc_82710364;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lfs f12,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,-13624
	ctx.r8.s64 = ctx.r10.s64 + -13624;
	// li r11,1
	r11.s64 = 1;
	// lfs f13,-7912(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,312(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 312);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bgt cr6,0x82710368
	if (cr6.gt) goto loc_82710368;
loc_82710364:
	// li r11,0
	r11.s64 = 0;
loc_82710368:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_82710370:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82710378"))) PPC_WEAK_FUNC(sub_82710378);
PPC_FUNC_IMPL(__imp__sub_82710378) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827103a4
	if (cr6.eq) goto loc_827103A4;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827103a4
	if (cr6.eq) goto loc_827103A4;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827103a4
	if (cr6.eq) goto loc_827103A4;
	// lfs f1,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_827103A4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827103B0"))) PPC_WEAK_FUNC(sub_827103B0);
PPC_FUNC_IMPL(__imp__sub_827103B0) {
	PPC_FUNC_PROLOGUE();
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// li r12,-32
	r12.s64 = -32;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r3,32(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// bl 0x822a8108
	ctx.lr = 0x827103D0;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f13,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f11,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// vsubfp128 v62,v127,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v62.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f13,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f8.f64));
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fmadds f5,f11,f9,f6
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f9.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bgt cr6,0x82710420
	if (cr6.gt) goto loc_82710420;
	// li r11,0
	r11.s64 = 0;
loc_82710420:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// li r0,-32
	r0.s64 = -32;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8271043C"))) PPC_WEAK_FUNC(sub_8271043C);
PPC_FUNC_IMPL(__imp__sub_8271043C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82710440"))) PPC_WEAK_FUNC(sub_82710440);
PPC_FUNC_IMPL(__imp__sub_82710440) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,144(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827104c8
	if (cr6.eq) goto loc_827104C8;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r9,r9,20224
	ctx.r9.s64 = ctx.r9.s64 + 20224;
	// addi r7,r11,2
	ctx.r7.s64 = r11.s64 + 2;
loc_8271045C:
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// lbz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// subf. r8,r6,r8
	ctx.r8.s64 = ctx.r8.s64 - ctx.r6.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne 0x8271047c
	if (!cr0.eq) goto loc_8271047C;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// bne cr6,0x8271045c
	if (!cr6.eq) goto loc_8271045C;
loc_8271047C:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x827104bc
	if (cr6.eq) goto loc_827104BC;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r8,r11,2
	ctx.r8.s64 = r11.s64 + 2;
	// addi r10,r10,20220
	ctx.r10.s64 = ctx.r10.s64 + 20220;
loc_82710490:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne 0x827104b0
	if (!cr0.eq) goto loc_827104B0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// bne cr6,0x82710490
	if (!cr6.eq) goto loc_82710490;
loc_827104B0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x827104c0
	if (!cr6.eq) goto loc_827104C0;
loc_827104BC:
	// li r11,1
	r11.s64 = 1;
loc_827104C0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
loc_827104C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827104D0"))) PPC_WEAK_FUNC(sub_827104D0);
PPC_FUNC_IMPL(__imp__sub_827104D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r7,48
	ctx.r7.s64 = 48;
	// lhz r6,80(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// li r11,0
	r11.s64 = 0;
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stb r8,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r8.u8);
	// stb r8,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r8.u8);
	// stvx128 v63,r3,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r8,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r8.u8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stb r8,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r8.u8);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// stb r11,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, r11.u8);
	// beq cr6,0x82710544
	if (cr6.eq) goto loc_82710544;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_82710528:
	// lwz r7,76(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r11,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, r11.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// lhz r6,80(r3)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r3.u32 + 80);
	// cmpw cr6,r10,r6
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, xer);
	// blt cr6,0x82710528
	if (cr6.lt) goto loc_82710528;
loc_82710544:
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stb r11,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, r11.u8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r8,96(r3)
	PPC_STORE_U8(ctx.r3.u32 + 96, ctx.r8.u8);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// stw r10,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r10.u32);
	// stw r10,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r10.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,144(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 144, temp.u32);
	// stfs f0,140(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// stfs f0,136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// stfs f0,132(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// stfs f0,128(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// stfs f0,124(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// stfs f0,120(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// stfs f0,116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// stfs f0,108(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82710594"))) PPC_WEAK_FUNC(sub_82710594);
PPC_FUNC_IMPL(__imp__sub_82710594) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82710598"))) PPC_WEAK_FUNC(sub_82710598);
PPC_FUNC_IMPL(__imp__sub_82710598) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827105bc
	if (cr6.eq) goto loc_827105BC;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lbz r10,872(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 872);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x827105c0
	if (!cr6.eq) goto loc_827105C0;
loc_827105BC:
	// li r11,0
	r11.s64 = 0;
loc_827105C0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827105C8"))) PPC_WEAK_FUNC(sub_827105C8);
PPC_FUNC_IMPL(__imp__sub_827105C8) {
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
	ctx.lr = 0x827105D0;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8271064c
	if (!cr6.gt) goto loc_8271064C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r31,0
	r31.s64 = 0;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82710604:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82710638
	if (cr6.eq) goto loc_82710638;
	// li r7,0
	ctx.r7.s64 = 0;
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8270cfc8
	ctx.lr = 0x8271062C;
	sub_8270CFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82710660
	if (!cr6.eq) goto loc_82710660;
loc_82710638:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82710604
	if (cr6.lt) goto loc_82710604;
loc_8271064C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82710660:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8271067C"))) PPC_WEAK_FUNC(sub_8271067C);
PPC_FUNC_IMPL(__imp__sub_8271067C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82710680"))) PPC_WEAK_FUNC(sub_82710680);
PPC_FUNC_IMPL(__imp__sub_82710680) {
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
	// bl 0x823d91fc
	ctx.lr = 0x82710688;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x827106A4;
	sub_822A8108(ctx, base);
	// addi r29,r3,48
	r29.s64 = ctx.r3.s64 + 48;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a8108
	ctx.lr = 0x827106B0;
	sub_822A8108(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// beq cr6,0x82710700
	if (cr6.eq) goto loc_82710700;
	// lfs f13,4(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f31,f31
	ctx.f12.f64 = double(float(f31.f64 * f31.f64));
	// lfs f11,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f13,f11
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// lfs f9,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// lfs f6,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f5.f64));
	// fmuls f3,f10,f10
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f2,f7,f7,f3
	ctx.f2.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f12
	cr6.compare(ctx.f1.f64, ctx.f12.f64);
	// bge cr6,0x82710804
	if (!cr6.lt) goto loc_82710804;
loc_82710700:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710804
	if (cr6.eq) goto loc_82710804;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82710804
	if (cr6.eq) goto loc_82710804;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710804
	if (cr6.eq) goto loc_82710804;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710804
	if (cr6.eq) goto loc_82710804;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// lfs f13,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r6,r8,-13624
	ctx.r6.s64 = ctx.r8.s64 + -13624;
	// lfs f11,-7912(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -7912);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,312(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 312);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x82710804
	if (!cr6.gt) goto loc_82710804;
	// lfs f12,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x82710804
	if (!cr6.gt) goto loc_82710804;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v63.f32)));
	// lwz r5,128(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r4,272
	ctx.r4.s64 = 272;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fdivs f0,f0,f13
	f0.f64 = double(float(f0.f64 / ctx.f13.f64));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvlx128 v60,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v58,r5,r4
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,31292(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v59,v60,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// vmulfp128 v57,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x827107CC;
	sub_82165300(ctx, base);
	// lfs f13,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f10,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// fmuls f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f10.f64));
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f8.f64 = double(temp.f32);
	// lfs f11,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// lfs f7,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f7.f64 = double(temp.f32);
	// lfs f0,32680(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32680);
	f0.f64 = double(temp.f32);
	// fmadds f6,f12,f8,f9
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f8.f64 + ctx.f9.f64));
	// fmadds f5,f11,f7,f6
	ctx.f5.f64 = double(float(ctx.f11.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bgt cr6,0x82710808
	if (cr6.gt) goto loc_82710808;
loc_82710804:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82710808:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82710814"))) PPC_WEAK_FUNC(sub_82710814);
PPC_FUNC_IMPL(__imp__sub_82710814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82710818"))) PPC_WEAK_FUNC(sub_82710818);
PPC_FUNC_IMPL(__imp__sub_82710818) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82710880
	if (cr6.eq) goto loc_82710880;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82710880
	if (cr6.eq) goto loc_82710880;
	// bl 0x826ffea0
	ctx.lr = 0x82710858;
	sub_826FFEA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82710880
	if (cr6.eq) goto loc_82710880;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 360);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// b 0x827109c0
	goto loc_827109C0;
loc_82710880:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r30,r11,-13624
	r30.s64 = r11.s64 + -13624;
	// beq cr6,0x827108f8
	if (cr6.eq) goto loc_827108F8;
	// bl 0x822a7d90
	ctx.lr = 0x82710898;
	sub_822A7D90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827108f8
	if (cr6.eq) goto loc_827108F8;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r11,48(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827108f8
	if (cr6.eq) goto loc_827108F8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827108f8
	if (cr6.eq) goto loc_827108F8;
	// lwz r11,592(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x827108f8
	if (!cr6.gt) goto loc_827108F8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,372(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 372);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827105c8
	ctx.lr = 0x827108DC;
	sub_827105C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827108f8
	if (cr6.eq) goto loc_827108F8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,360(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 360);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// b 0x827109c0
	goto loc_827109C0;
loc_827108F8:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827109a4
	if (cr6.eq) goto loc_827109A4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82710918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fadds f1,f1,f0
	ctx.f1.f64 = double(float(ctx.f1.f64 + f0.f64));
	// bl 0x827105c8
	ctx.lr = 0x82710930;
	sub_827105C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827109a4
	if (cr6.eq) goto loc_827109A4;
	// lfs f0,128(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	f0.f64 = double(temp.f32);
	// lfs f13,124(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x827109c4
	if (!cr6.lt) goto loc_827109C4;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82710974
	if (cr6.eq) goto loc_82710974;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710974
	if (cr6.eq) goto loc_82710974;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710974
	if (cr6.eq) goto loc_82710974;
	// lfs f12,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8271097c
	goto loc_8271097C;
loc_82710974:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f12.f64 = double(temp.f32);
loc_8271097C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f0,368(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 368);
	f0.f64 = double(temp.f32);
	// lfs f13,-7912(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x827109c4
	if (!cr6.lt) goto loc_827109C4;
	// lfs f0,108(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// stfs f13,108(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// b 0x827109c4
	goto loc_827109C4;
loc_827109A4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x827109c4
	if (!cr6.gt) goto loc_827109C4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_827109C0:
	// stfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
loc_827109C4:
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

__attribute__((alias("__imp__sub_827109E0"))) PPC_WEAK_FUNC(sub_827109E0);
PPC_FUNC_IMPL(__imp__sub_827109E0) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827109E8;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,120(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82710a18
	if (!cr6.gt) goto loc_82710A18;
loc_82710A08:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82710A18:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r28,0
	r28.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82710a64
	if (!cr6.gt) goto loc_82710A64;
	// li r31,0
	r31.s64 = 0;
loc_82710A30:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x8270c8c0
	ctx.lr = 0x82710A3C;
	sub_8270C8C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82710a60
	if (!cr6.eq) goto loc_82710A60;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82710a30
	if (cr6.lt) goto loc_82710A30;
	// b 0x82710a64
	goto loc_82710A64;
loc_82710A60:
	// li r28,1
	r28.s64 = 1;
loc_82710A64:
	// clrlwi r31,r28,24
	r31.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82710ad4
	if (!cr6.eq) goto loc_82710AD4;
	// bl 0x82256058
	ctx.lr = 0x82710A74;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82710a08
	if (!cr6.eq) goto loc_82710A08;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x82710a08
	if (cr6.lt) goto loc_82710A08;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82710A9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82710a08
	if (!cr6.eq) goto loc_82710A08;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82710ad4
	if (!cr6.eq) goto loc_82710AD4;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,-13624
	ctx.r10.s64 = r11.s64 + -13624;
	// lfs f0,336(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 336);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82710ad4
	if (!cr6.gt) goto loc_82710AD4;
	// lfs f13,104(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x82710ad8
	if (!cr6.lt) goto loc_82710AD8;
loc_82710AD4:
	// li r11,1
	r11.s64 = 1;
loc_82710AD8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82710AE8"))) PPC_WEAK_FUNC(sub_82710AE8);
PPC_FUNC_IMPL(__imp__sub_82710AE8) {
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
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82710B0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82710b50
	if (!cr6.eq) goto loc_82710B50;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82710b3c
	if (cr6.eq) goto loc_82710B3C;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lbz r10,872(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 872);
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82710b40
	if (!cr6.eq) goto loc_82710B40;
loc_82710B3C:
	// li r11,0
	r11.s64 = 0;
loc_82710B40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82710b54
	if (!cr6.eq) goto loc_82710B54;
loc_82710B50:
	// li r11,0
	r11.s64 = 0;
loc_82710B54:
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

__attribute__((alias("__imp__sub_82710B6C"))) PPC_WEAK_FUNC(sub_82710B6C);
PPC_FUNC_IMPL(__imp__sub_82710B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82710B70"))) PPC_WEAK_FUNC(sub_82710B70);
PPC_FUNC_IMPL(__imp__sub_82710B70) {
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
	PPCRegister f0{};
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
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82710B78;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823db9bc
	ctx.lr = 0x82710B80;
	// addi r12,r1,-192
	r12.s64 = ctx.r1.s64 + -192;
	// bl 0x823dd534
	ctx.lr = 0x82710B88;
	// stwu r1,-672(r1)
	ea = -672 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,36(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// fmr f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = ctx.f1.f64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r21,r8
	r21.u64 = ctx.r8.u64;
	// mr r25,r9
	r25.u64 = ctx.r9.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82710ef4
	if (cr6.eq) goto loc_82710EF4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// li r31,0
	r31.s64 = 0;
	// lfs f31,12424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12424);
	f31.f64 = double(temp.f32);
loc_82710BC4:
	// extsw r10,r30
	ctx.r10.s64 = r30.s32;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// std r10,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// add r6,r31,r11
	ctx.r6.u64 = r31.u64 + r11.u64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64));
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82710BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stvx128 v63,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmpwi cr6,r31,128
	cr6.compare<int32_t>(r31.s32, 128, xer);
	// blt cr6,0x82710bc4
	if (cr6.lt) goto loc_82710BC4;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	f0.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,276(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fsubs f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 - ctx.f12.f64));
	// lfs f9,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,280(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f9,f8
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f8.f64));
	// fsubs f5,f9,f7
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f7.f64));
	// lfs f4,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,272(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f1,f4,f3
	ctx.f1.f64 = double(float(ctx.f4.f64 - ctx.f3.f64));
	// fsubs f0,f4,f2
	f0.f64 = double(float(ctx.f4.f64 - ctx.f2.f64));
	// fmuls f13,f11,f11
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmuls f12,f10,f10
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f11,f6,f6,f13
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f13.f64));
	// fmadds f10,f5,f5,f12
	ctx.f10.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f12.f64));
	// fmadds f9,f1,f1,f11
	ctx.f9.f64 = double(float(ctx.f1.f64 * ctx.f1.f64 + ctx.f11.f64));
	// fmadds f8,f0,f0,f10
	ctx.f8.f64 = double(float(f0.f64 * f0.f64 + ctx.f10.f64));
	// fcmpu cr6,f9,f8
	cr6.compare(ctx.f9.f64, ctx.f8.f64);
	// blt cr6,0x82710c7c
	if (cr6.lt) goto loc_82710C7C;
	// li r11,0
	r11.s64 = 0;
loc_82710C7C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// subfic r9,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r9.s64 = 0 - r11.s64;
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// subfic r7,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r7.s64 = 0 - r11.s64;
	// rlwinm r11,r8,0,30,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subfe r6,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r6.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r27,r11,-1
	r27.s64 = r11.s64 + -1;
	// rlwinm r5,r6,0,31,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF9;
	// addic. r30,r5,7
	xer.ca = ctx.r5.u32 > 4294967288;
	r30.s64 = ctx.r5.s64 + 7;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// blt 0x82710ef4
	if (cr0.lt) goto loc_82710EF4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f25,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f25.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f24,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f24.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f23,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f23.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f29,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f29.f64 = double(temp.f32);
	// rlwinm r26,r27,4,0,27
	r26.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 4) & 0xFFFFFFF0;
	// lfd f30,3456(r10)
	f30.u64 = PPC_LOAD_U64(ctx.r10.u32 + 3456);
	// rlwinm r29,r30,4,0,27
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f26,31292(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31292);
	f26.f64 = double(temp.f32);
	// li r24,48
	r24.s64 = 48;
	// lfs f27,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f27.f64 = double(temp.f32);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lfs f31,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82710CF0:
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// bge cr6,0x82710ef4
	if (!cr6.lt) goto loc_82710EF4;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r22,24
	ctx.r9.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lvx128 v127,r29,r11
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82710d6c
	if (cr6.eq) goto loc_82710D6C;
	// lwz r3,32(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 32);
	// bl 0x822a8108
	ctx.lr = 0x82710D1C;
	sub_822A8108(ctx, base);
	// lvx128 v62,r3,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// vsubfp128 v61,v127,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v62.f32)));
	// lfs f0,40(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	f0.f64 = double(temp.f32);
	// lfs f13,36(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	r11.s64 = 1;
	// lfs f11,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f0,f9
	ctx.f8.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmadds f7,f13,f11,f8
	ctx.f7.f64 = double(float(ctx.f13.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f6,f12,f10,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f10.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f31
	cr6.compare(ctx.f6.f64, f31.f64);
	// blt cr6,0x82710d60
	if (cr6.lt) goto loc_82710D60;
	// li r11,0
	r11.s64 = 0;
loc_82710D60:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82710ee8
	if (!cr6.eq) goto loc_82710EE8;
loc_82710D6C:
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f31,132(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// fadds f28,f0,f24
	f28.f64 = double(float(f0.f64 + f24.f64));
	// stfs f27,128(r1)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmr f1,f26
	ctx.f1.f64 = f26.f64;
	// stfs f31,136(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v60,r29,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f28,84(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x82710DA4;
	sub_82165300(ctx, base);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v59,r0,r25
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x823dbae8
	ctx.lr = 0x82710DB8;
	sub_823DBAE8(ctx, base);
	// frsp f21,f1
	ctx.fpscr.disableFlushMode();
	f21.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x82710DC4;
	sub_823DBBC8(ctx, base);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// fmuls f7,f23,f29
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(f23.f64 * f29.f64));
	// stfs f7,96(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// frsp f12,f1
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,4(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// fsubs f10,f28,f11
	ctx.f10.f64 = double(float(f28.f64 - ctx.f11.f64));
	// lfs f9,8(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f13,f25,f29
	ctx.f13.f64 = double(float(f25.f64 * f29.f64));
	// lvlx128 v57,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fsubs f6,f8,f9
	ctx.f6.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// lfs f5,0(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	ctx.f5.f64 = double(temp.f32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f4,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// lfs f0,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	f0.f64 = double(temp.f32);
	// fmuls f2,f0,f21
	ctx.f2.f64 = double(float(f0.f64 * f21.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvlx128 v58,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// fmuls f1,f10,f10
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// lfs f13,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	f0.f64 = double(float(f0.f64 * ctx.f12.f64));
	// vspltw128 v56,v57,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// fmsubs f12,f13,f12,f2
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 - ctx.f2.f64));
	// lvx128 v54,r0,r25
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vmulfp128 v125,v54,v55
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v125.f32, simde_mm_mul_ps(simde_mm_load_ps(v54.f32), simde_mm_load_ps(v55.f32)));
	// fmadds f11,f6,f6,f1
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f1.f64));
	// fmadds f10,f13,f21,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f21.f64 + f0.f64));
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v53,r0,r6
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v127,v53,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v53.f32), simde_mm_load_ps(v56.f32)));
	// fmadds f9,f3,f3,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(ctx.f3.f64 * ctx.f3.f64 + ctx.f11.f64));
	// fcmpu cr6,f9,f22
	cr6.compare(ctx.f9.f64, f22.f64);
	// bge cr6,0x82710ee8
	if (!cr6.lt) goto loc_82710EE8;
	// vaddfp128 v52,v125,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v52.f32, simde_mm_add_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v127.f32)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lvx128 v1,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v126,v52
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v52.f32)));
	// bl 0x82700578
	ctx.lr = 0x82710E74;
	sub_82700578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82710ee8
	if (!cr6.eq) goto loc_82710EE8;
	// vspltisw128 v51,0
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_set1_epi32(int(0x0)));
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lvx128 v1,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v124,v51,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v124.f32, simde_mm_sub_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v125.f32)));
	// vaddfp128 v50,v124,v127
	simde_mm_store_ps(v50.f32, simde_mm_add_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v127.f32)));
	// vaddfp128 v2,v126,v50
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v50.f32)));
	// bl 0x82700578
	ctx.lr = 0x82710E9C;
	sub_82700578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82710ee8
	if (!cr6.eq) goto loc_82710EE8;
	// vsubfp128 v49,v125,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v127.f32)));
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lvx128 v1,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v126,v49
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v49.f32)));
	// bl 0x82700578
	ctx.lr = 0x82710EBC;
	sub_82700578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82710ee8
	if (!cr6.eq) goto loc_82710EE8;
	// vsubfp128 v48,v124,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v127.f32)));
	// lwz r3,-10016(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10016);
	// lvx128 v1,r0,r28
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v126,v48
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v48.f32)));
	// bl 0x82700578
	ctx.lr = 0x82710EDC;
	sub_82700578(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82710f10
	if (cr6.eq) goto loc_82710F10;
loc_82710EE8:
	// add. r30,r30,r27
	r30.u64 = r30.u64 + r27.u64;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// add r29,r26,r29
	r29.u64 = r26.u64 + r29.u64;
	// bge 0x82710cf0
	if (!cr0.lt) goto loc_82710CF0;
loc_82710EF4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82710EF8:
	// addi r1,r1,672
	ctx.r1.s64 = ctx.r1.s64 + 672;
	// addi r12,r1,-192
	r12.s64 = ctx.r1.s64 + -192;
	// bl 0x823dd7cc
	ctx.lr = 0x82710F04;
	// addi r12,r1,-96
	r12.s64 = ctx.r1.s64 + -96;
	// bl 0x823dba08
	ctx.lr = 0x82710F0C;
	// b 0x823d922c
	return;
loc_82710F10:
	// rlwinm r11,r30,4,0,27
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v47,r11,r10
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r0,r21
	simde_mm_store_si128((simde__m128i*)(base + ((r21.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82710ef8
	goto loc_82710EF8;
}

__attribute__((alias("__imp__sub_82710F28"))) PPC_WEAK_FUNC(sub_82710F28);
PPC_FUNC_IMPL(__imp__sub_82710F28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f1,136(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_82710F44:
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82710f64
	if (cr6.lt) goto loc_82710F64;
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82710f64
	if (!cr6.lt) goto loc_82710F64;
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwzx r11,r11,r9
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// b 0x82710f68
	goto loc_82710F68;
loc_82710F64:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82710F68:
	// lwz r11,876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 876);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82710fa0
	if (cr6.eq) goto loc_82710FA0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82710f94
	if (cr6.lt) goto loc_82710F94;
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82710f94
	if (!cr6.lt) goto loc_82710F94;
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwzx r11,r11,r9
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// b 0x82710f98
	goto loc_82710F98;
loc_82710F94:
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82710F98:
	// lwz r11,876(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 876);
	// stb r8,773(r11)
	PPC_STORE_U8(r11.u32 + 773, ctx.r8.u8);
loc_82710FA0:
	// lwz r11,72(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82710f44
	if (cr6.lt) goto loc_82710F44;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82710FB8"))) PPC_WEAK_FUNC(sub_82710FB8);
PPC_FUNC_IMPL(__imp__sub_82710FB8) {
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
	ctx.lr = 0x82710FC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82711008
	if (!cr6.gt) goto loc_82711008;
	// li r31,0
	r31.s64 = 0;
loc_82710FDC:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x8270c388
	ctx.lr = 0x82710FE8;
	sub_8270C388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711014
	if (cr6.eq) goto loc_82711014;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82710fdc
	if (cr6.lt) goto loc_82710FDC;
loc_82711008:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82711014:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82711020"))) PPC_WEAK_FUNC(sub_82711020);
PPC_FUNC_IMPL(__imp__sub_82711020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82711028;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r28,1
	r28.s64 = 1;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827110b8
	if (!cr6.gt) goto loc_827110B8;
	// li r31,0
	r31.s64 = 0;
loc_82711050:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r9,876(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 876);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82711098
	if (cr6.eq) goto loc_82711098;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x822a8108
	ctx.lr = 0x8271106C;
	sub_822A8108(ctx, base);
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r10,48
	ctx.r10.s64 = 48;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lvx128 v1,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,876(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 876);
	// bl 0x8270e778
	ctx.lr = 0x82711088;
	sub_8270E778(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8271109c
	if (!cr6.eq) goto loc_8271109C;
loc_82711098:
	// li r11,0
	r11.s64 = 0;
loc_8271109C:
	// lwz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// and r28,r9,r11
	r28.u64 = ctx.r9.u64 & r11.u64;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x82711050
	if (cr6.lt) goto loc_82711050;
loc_827110B8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827110C8"))) PPC_WEAK_FUNC(sub_827110C8);
PPC_FUNC_IMPL(__imp__sub_827110C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827110D0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x827111a0
	if (!cr6.gt) goto loc_827111A0;
	// li r31,0
	r31.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_827110FC:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lbz r9,880(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 880);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8271117c
	if (!cr6.eq) goto loc_8271117C;
	// lwz r10,-10016(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10016);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8271117c
	if (cr6.eq) goto loc_8271117C;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwzx r4,r31,r11
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// bl 0x826ffea0
	ctx.lr = 0x82711128;
	sub_826FFEA0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8271117c
	if (!cr6.eq) goto loc_8271117C;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r9,876(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 876);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8271117c
	if (cr6.eq) goto loc_8271117C;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x822a8108
	ctx.lr = 0x82711150;
	sub_822A8108(ctx, base);
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r10,48
	ctx.r10.s64 = 48;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lvx128 v1,r3,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,876(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 876);
	// bl 0x8270e778
	ctx.lr = 0x8271116C;
	sub_8270E778(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82711180
	if (!cr6.eq) goto loc_82711180;
loc_8271117C:
	// li r11,0
	r11.s64 = 0;
loc_82711180:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827111a0
	if (!cr6.eq) goto loc_827111A0;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x827110fc
	if (cr6.lt) goto loc_827110FC;
loc_827111A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827111AC"))) PPC_WEAK_FUNC(sub_827111AC);
PPC_FUNC_IMPL(__imp__sub_827111AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827111B0"))) PPC_WEAK_FUNC(sub_827111B0);
PPC_FUNC_IMPL(__imp__sub_827111B0) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r7,32(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82711414
	if (cr6.eq) goto loc_82711414;
	// bl 0x82710318
	ctx.lr = 0x827111D8;
	sub_82710318(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827111ec
	if (!cr6.eq) goto loc_827111EC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82711418
	goto loc_82711418;
loc_827111EC:
	// lwz r11,48(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82711414
	if (cr6.eq) goto loc_82711414;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82711414
	if (cr6.eq) goto loc_82711414;
	// lhz r11,44(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 44);
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82711220
	if (!cr6.eq) goto loc_82711220;
	// bl 0x822a8108
	ctx.lr = 0x82711218;
	sub_822A8108(ctx, base);
	// addi r11,r3,32
	r11.s64 = ctx.r3.s64 + 32;
	// b 0x82711240
	goto loc_82711240;
loc_82711220:
	// bl 0x822a8108
	ctx.lr = 0x82711224;
	sub_822A8108(ctx, base);
	// li r10,32
	ctx.r10.s64 = 32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r3,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82711240:
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r9,2272
	ctx.r7.s64 = ctx.r9.s64 + 2272;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,31292(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 31292);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v1,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x82711268;
	sub_82165300(ctx, base);
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x822a8108
	ctx.lr = 0x82711270;
	sub_822A8108(ctx, base);
	// lwz r6,32(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// li r5,48
	ctx.r5.s64 = 48;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r11,48(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	// lvx128 v0,r3,r5
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827112f0
	if (cr6.eq) goto loc_827112F0;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827112f0
	if (cr6.eq) goto loc_827112F0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827112f0
	if (cr6.eq) goto loc_827112F0;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827112f0
	if (cr6.eq) goto loc_827112F0;
	// li r10,32
	ctx.r10.s64 = 32;
	// lfs f13,132(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v59,r11,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r11,r9
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v59.f32)));
	// lfs f0,14884(r7)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,244(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f11,f12,f0,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64 + ctx.f13.f64));
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_827112F0:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,2256
	ctx.r9.s64 = r11.s64 + 2256;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// li r31,0
	r31.s64 = 0;
	// stw r31,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r31.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// stfs f0,208(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,-1
	ctx.r10.s64 = -1;
	// lfs f13,-12736(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12736);
	ctx.f13.f64 = double(temp.f32);
	// sth r10,220(r1)
	PPC_STORE_U16(ctx.r1.u32 + 220, ctx.r10.u16);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// sth r31,222(r1)
	PPC_STORE_U16(ctx.r1.u32 + 222, r31.u16);
	// stvx128 v0,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r31,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r31.u8);
	// sth r31,226(r1)
	PPC_STORE_U16(ctx.r1.u32 + 226, r31.u16);
	// lvlx128 v56,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// stw r31,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r31.u32);
	// vspltw128 v13,v56,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// lvx128 v12,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// vmaddfp v11,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r11,r1,272
	r11.s64 = ctx.r1.s64 + 272;
	// li r8,-1
	ctx.r8.s64 = -1;
	// stfs f0,212(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// lwz r3,-23452(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -23452);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x827113A4;
	sub_82574418(ctx, base);
	// lwz r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// li r10,-1
	ctx.r10.s64 = -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// stw r10,88(r30)
	PPC_STORE_U32(r30.u32 + 88, ctx.r10.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r3,r7,1
	ctx.r3.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82711418
	if (cr6.eq) goto loc_82711418;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82711418
	if (!cr6.gt) goto loc_82711418;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
loc_827113D8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,48(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827113f4
	if (cr6.eq) goto loc_827113F4;
	// lwz r10,28(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x8271140c
	if (cr6.eq) goto loc_8271140C;
loc_827113F4:
	// lwz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x827113d8
	if (cr6.lt) goto loc_827113D8;
	// b 0x82711418
	goto loc_82711418;
loc_8271140C:
	// stw r31,88(r30)
	PPC_STORE_U32(r30.u32 + 88, r31.u32);
	// b 0x82711418
	goto loc_82711418;
loc_82711414:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82711418:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r30,-24(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82711430"))) PPC_WEAK_FUNC(sub_82711430);
PPC_FUNC_IMPL(__imp__sub_82711430) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82711438;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// lbz r11,20(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8271145c
	if (!cr6.eq) goto loc_8271145C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8271145C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r27,0
	r27.s64 = 0;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8271147c
	if (cr6.eq) goto loc_8271147C;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// ori r9,r10,17106
	ctx.r9.u64 = ctx.r10.u64 | 17106;
	// stbx r27,r11,r9
	PPC_STORE_U8(r11.u32 + ctx.r9.u32, r27.u8);
loc_8271147C:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// mr r28,r27
	r28.u64 = r27.u64;
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r25,r7,1
	r25.u64 = ctx.r7.u64 ^ 1;
	// ble cr6,0x8271153c
	if (!cr6.gt) goto loc_8271153C;
	// mr r30,r27
	r30.u64 = r27.u64;
	// li r26,1
	r26.s64 = 1;
loc_827114A8:
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r10,r30,r11
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82711528
	if (cr6.eq) goto loc_82711528;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r31,876(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 876);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x827114dc
	if (cr6.eq) goto loc_827114DC;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8270cc90
	ctx.lr = 0x827114D4;
	sub_8270CC90(ctx, base);
	// stb r26,773(r31)
	PPC_STORE_U8(r31.u32 + 773, r26.u8);
	// stw r27,408(r31)
	PPC_STORE_U32(r31.u32 + 408, r27.u32);
loc_827114DC:
	// clrlwi r11,r24,24
	r11.u64 = r24.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711528
	if (cr6.eq) goto loc_82711528;
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x8270c768
	ctx.lr = 0x827114F4;
	sub_8270C768(ctx, base);
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82711528
	if (cr6.eq) goto loc_82711528;
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x8270c7e8
	ctx.lr = 0x82711510;
	sub_8270C7E8(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82711514;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82711528
	if (!cr6.eq) goto loc_82711528;
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x822a8e50
	ctx.lr = 0x82711528;
	sub_822A8E50(ctx, base);
loc_82711528:
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x827114a8
	if (cr6.lt) goto loc_827114A8;
loc_8271153C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f1,104(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 104);
	ctx.f1.f64 = double(temp.f32);
	// stfd f1,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.f1.u64);
	// ld r8,56(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 56);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r7,16(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// rlwinm r6,r3,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r9,-24332
	r11.s64 = ctx.r9.s64 + -24332;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r5,r10,29628
	ctx.r5.s64 = ctx.r10.s64 + 29628;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwzx r6,r6,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// bl 0x82130000
	ctx.lr = 0x82711584;
	sub_82130000(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82711598;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_827115A4"))) PPC_WEAK_FUNC(sub_827115A4);
PPC_FUNC_IMPL(__imp__sub_827115A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827115A8"))) PPC_WEAK_FUNC(sub_827115A8);
PPC_FUNC_IMPL(__imp__sub_827115A8) {
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lfs f0,124(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// bl 0x827111b0
	ctx.lr = 0x827115D0;
	sub_827111B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// beq cr6,0x827115f8
	if (cr6.eq) goto loc_827115F8;
	// lfs f0,124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 124);
	f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,124(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
	// stfs f0,132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// b 0x8271160c
	goto loc_8271160C;
loc_827115F8:
	// lfs f0,132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,132(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// stfs f0,124(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 124, temp.u32);
loc_8271160C:
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

__attribute__((alias("__imp__sub_82711624"))) PPC_WEAK_FUNC(sub_82711624);
PPC_FUNC_IMPL(__imp__sub_82711624) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82711628"))) PPC_WEAK_FUNC(sub_82711628);
PPC_FUNC_IMPL(__imp__sub_82711628) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82711630;
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -104, f29.u64);
	// stfd f30,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f30.u64);
	// stfd f31,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	f29.f64 = ctx.f1.f64;
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711c8c
	if (cr6.eq) goto loc_82711C8C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711664;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82711684
	if (cr6.eq) goto loc_82711684;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711684;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82711684:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,104(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 104);
	f0.f64 = double(temp.f32);
	// fadds f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 + f29.f64));
	// stfs f13,104(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827116A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827116c8
	if (cr6.eq) goto loc_827116C8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827116C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827116C8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 112);
	f0.f64 = double(temp.f32);
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x827116f0
	if (!cr6.gt) goto loc_827116F0;
	// fsubs f0,f0,f29
	f0.f64 = double(float(f0.f64 - f29.f64));
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x827116f0
	if (!cr6.lt) goto loc_827116F0;
	// stfs f31,112(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
loc_827116F0:
	// lfs f0,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	f0.f64 = double(temp.f32);
	// li r24,1
	r24.s64 = 1;
	// li r26,0
	r26.s64 = 0;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8271174c
	if (!cr6.gt) goto loc_8271174C;
	// fsubs f0,f0,f29
	f0.f64 = double(float(f0.f64 - f29.f64));
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x8271174c
	if (cr6.gt) goto loc_8271174C;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f31,116(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8271174c
	if (!cr6.gt) goto loc_8271174C;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8271172C:
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stb r24,1148(r8)
	PPC_STORE_U8(ctx.r8.u32 + 1148, r24.u8);
	// lwz r7,72(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x8271172c
	if (cr6.lt) goto loc_8271172C;
loc_8271174C:
	// lfs f0,120(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 120);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8271176c
	if (!cr6.gt) goto loc_8271176C;
	// fsubs f0,f0,f29
	f0.f64 = double(float(f0.f64 - f29.f64));
	// stfs f0,120(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8271176c
	if (!cr6.lt) goto loc_8271176C;
	// stfs f31,120(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 120, temp.u32);
loc_8271176C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r29,r26
	r29.u64 = r26.u64;
	// addi r25,r11,-13624
	r25.s64 = r11.s64 + -13624;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x827117d8
	if (!cr6.gt) goto loc_827117D8;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// mr r30,r26
	r30.u64 = r26.u64;
loc_827117A4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x8270c7e8
	ctx.lr = 0x827117B0;
	sub_8270C7E8(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lfs f0,1144(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 1144);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x82711a8c
	if (cr6.gt) goto loc_82711A8C;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r10
	cr6.compare<int32_t>(r29.s32, ctx.r10.s32, xer);
	// blt cr6,0x827117a4
	if (cr6.lt) goto loc_827117A4;
loc_827117D8:
	// lwz r30,76(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r27,0(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x822a8108
	ctx.lr = 0x827117E8;
	sub_822A8108(ctx, base);
	// addi r29,r3,48
	r29.s64 = ctx.r3.s64 + 48;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x822a8108
	ctx.lr = 0x827117F4;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	f0.f64 = double(temp.f32);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f13,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mr r28,r24
	r28.u64 = r24.u64;
	// lfs f12,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f30,f6,f6,f4
	f30.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// ble cr6,0x827118b0
	if (!cr6.gt) goto loc_827118B0;
	// li r30,4
	r30.s64 = 4;
loc_8271183C:
	// lwz r29,76(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x822a8108
	ctx.lr = 0x82711848;
	sub_822A8108(ctx, base);
	// addi r23,r3,48
	r23.s64 = ctx.r3.s64 + 48;
	// lwzx r3,r29,r30
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// bl 0x822a8108
	ctx.lr = 0x82711854;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 - f0.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f0,f6,f6,f4
	f0.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f30,f0
	cr6.compare(f30.f64, f0.f64);
	// ble cr6,0x8271189c
	if (!cr6.gt) goto loc_8271189C;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// fmr f30,f0
	f30.f64 = f0.f64;
	// lwzx r27,r11,r30
	r27.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
loc_8271189C:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8271183c
	if (cr6.lt) goto loc_8271183C;
loc_827118B0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8270cdb8
	ctx.lr = 0x827118B8;
	sub_8270CDB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711994
	if (cr6.eq) goto loc_82711994;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lwz r11,352(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 352);
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2192
	ctx.r7.s64 = ctx.r9.s64 + 2192;
	// ori r5,r8,64167
	ctx.r5.u64 = ctx.r8.u64 | 64167;
	// extsw r6,r11
	ctx.r6.s64 = r11.s32;
	// lwz r3,2192(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2192);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r3,r5
	ctx.r10.s64 = ctx.r3.s64 * ctx.r5.s64;
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f0,14348(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14348);
	f0.f64 = double(temp.f32);
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lfs f13,11360(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11360);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stw r10,2192(r9)
	PPC_STORE_U32(ctx.r9.u32 + 2192, ctx.r10.u32);
	// stw r11,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r11.u32);
	// fmuls f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * f0.f64));
	// fcmpu cr6,f7,f11
	cr6.compare(ctx.f7.f64, ctx.f11.f64);
	// bge cr6,0x82711b14
	if (!cr6.lt) goto loc_82711B14;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8270cec0
	ctx.lr = 0x8271194C;
	sub_8270CEC0(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82711994
	if (cr6.eq) goto loc_82711994;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82711994
	if (!cr6.gt) goto loc_82711994;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82711968:
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplw cr6,r8,r27
	cr6.compare<uint32_t>(ctx.r8.u32, r27.u32, xer);
	// beq cr6,0x82711980
	if (cr6.eq) goto loc_82711980;
	// rotlwi r10,r8,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// stb r26,1148(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1148, r26.u8);
loc_82711980:
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x82711968
	if (cr6.lt) goto loc_82711968;
loc_82711994:
	// lfs f0,136(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82711a10
	if (!cr6.gt) goto loc_82711A10;
	// fsubs f0,f0,f29
	f0.f64 = double(float(f0.f64 - f29.f64));
	// stfs f0,136(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 136, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x82711a10
	if (cr6.gt) goto loc_82711A10;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827119C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82711a10
	if (cr6.eq) goto loc_82711A10;
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82711a10
	if (!cr6.gt) goto loc_82711A10;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_827119E4:
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r10,876(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 876);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827119fc
	if (cr6.eq) goto loc_827119FC;
	// stb r24,773(r10)
	PPC_STORE_U8(ctx.r10.u32 + 773, r24.u8);
loc_827119FC:
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x827119e4
	if (cr6.lt) goto loc_827119E4;
loc_82711A10:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711bd4
	if (cr6.eq) goto loc_82711BD4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711A30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82711bd4
	if (!cr6.eq) goto loc_82711BD4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711A50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827110c8
	ctx.lr = 0x82711A58;
	sub_827110C8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82711bd4
	if (cr6.eq) goto loc_82711BD4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x826fffa0
	ctx.lr = 0x82711A74;
	sub_826FFFA0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82711b68
	if (cr6.eq) goto loc_82711B68;
	// lfs f0,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 140);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	f0.f64 = double(float(f0.f64 + f29.f64));
	// b 0x82711b6c
	goto loc_82711B6C;
loc_82711A8C:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r11
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x827117d8
	if (cr6.eq) goto loc_827117D8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270cdb8
	ctx.lr = 0x82711AA8;
	sub_8270CDB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82711994
	if (!cr6.eq) goto loc_82711994;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8270cec0
	ctx.lr = 0x82711AC0;
	sub_8270CEC0(ctx, base);
	// lfs f0,348(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 348);
	f0.f64 = double(temp.f32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// mr r11,r24
	r11.u64 = r24.u64;
	// beq cr6,0x82711ad8
	if (cr6.eq) goto loc_82711AD8;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82711AD8:
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82711994
	if (!cr6.gt) goto loc_82711994;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82711AF0:
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stb r9,1148(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1148, ctx.r9.u8);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x82711af0
	if (cr6.lt) goto loc_82711AF0;
	// b 0x82711994
	goto loc_82711994;
loc_82711B14:
	// lfs f0,348(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 348);
	f0.f64 = double(temp.f32);
	// mr r11,r24
	r11.u64 = r24.u64;
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x82711b2c
	if (cr6.eq) goto loc_82711B2C;
	// mr r11,r26
	r11.u64 = r26.u64;
loc_82711B2C:
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82711994
	if (!cr6.gt) goto loc_82711994;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_82711B44:
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stb r9,1148(r7)
	PPC_STORE_U8(ctx.r7.u32 + 1148, ctx.r9.u8);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x82711b44
	if (cr6.lt) goto loc_82711B44;
	// b 0x82711994
	goto loc_82711994;
loc_82711B68:
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
loc_82711B6C:
	// stfs f0,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x822a8108
	ctx.lr = 0x82711B78;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f13,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f12,56(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,368(r25)
	temp.u32 = PPC_LOAD_U32(r25.u32 + 368);
	f0.f64 = double(temp.f32);
	// lfs f11,48(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f8,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// lfs f13,-7912(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7912);
	ctx.f13.f64 = double(temp.f32);
	// lfs f6,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f0,f13
	ctx.f5.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fsubs f4,f6,f11
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// fmuls f3,f9,f9
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmuls f2,f5,f29
	ctx.f2.f64 = double(float(ctx.f5.f64 * f29.f64));
	// fmadds f1,f7,f7,f3
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmadds f0,f4,f4,f1
	f0.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f1.f64));
	// fcmpu cr6,f0,f2
	cr6.compare(f0.f64, ctx.f2.f64);
	// bge cr6,0x82711bd8
	if (!cr6.lt) goto loc_82711BD8;
	// lfs f0,144(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f29
	f31.f64 = double(float(f0.f64 + f29.f64));
	// b 0x82711bd8
	goto loc_82711BD8;
loc_82711BD4:
	// stfs f31,140(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
loc_82711BD8:
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// stfs f31,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,876(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 876);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82711c24
	if (cr6.eq) goto loc_82711C24;
	// lwz r11,680(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 680);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82711c24
	if (cr6.eq) goto loc_82711C24;
	// bl 0x8270ea28
	ctx.lr = 0x82711C00;
	sub_8270EA28(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,76(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r3,876(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 876);
	// bl 0x8270ea30
	ctx.lr = 0x82711C20;
	sub_8270EA30(ctx, base);
	// stfs f1,64(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
loc_82711C24:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711C38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82711c5c
	if (cr6.eq) goto loc_82711C5C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711C5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82711C5C:
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82711c8c
	if (cr6.lt) goto loc_82711C8C;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r3,876(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 876);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82711c8c
	if (cr6.eq) goto loc_82711C8C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8270e690
	ctx.lr = 0x82711C8C;
	sub_8270E690(ctx, base);
loc_82711C8C:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82711CA0"))) PPC_WEAK_FUNC(sub_82711CA0);
PPC_FUNC_IMPL(__imp__sub_82711CA0) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82711CA8;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711CC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r7,r11,-13624
	ctx.r7.s64 = r11.s64 + -13624;
	// lfs f30,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f30.f64 = double(temp.f32);
	// beq cr6,0x82711cec
	if (cr6.eq) goto loc_82711CEC;
	// lfs f1,432(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 432);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82711cf0
	goto loc_82711CF0;
loc_82711CEC:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
loc_82711CF0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82710f28
	ctx.lr = 0x82711CF8;
	sub_82710F28(ctx, base);
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	f31.f64 = f30.f64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f0,376(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 376);
	f0.f64 = double(temp.f32);
	// stfs f0,112(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 112, temp.u32);
	// beq cr6,0x82711d30
	if (cr6.eq) goto loc_82711D30;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82711d30
	if (cr6.eq) goto loc_82711D30;
	// lwz r3,132(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82711d30
	if (cr6.eq) goto loc_82711D30;
	// bl 0x8238efe8
	ctx.lr = 0x82711D2C;
	sub_8238EFE8(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
loc_82711D30:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82711dc8
	if (!cr6.gt) goto loc_82711DC8;
	// li r28,0
	r28.s64 = 0;
loc_82711D44:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x82711db4
	if (cr6.lt) goto loc_82711DB4;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x82711db4
	if (!cr6.lt) goto loc_82711DB4;
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r31,r11,r28
	r31.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82711db4
	if (cr6.eq) goto loc_82711DB4;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82711db4
	if (cr6.eq) goto loc_82711DB4;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82711db4
	if (cr6.eq) goto loc_82711DB4;
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f30.f64);
	// ble cr6,0x82711db4
	if (!cr6.gt) goto loc_82711DB4;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r3,r11,8109
	ctx.r3.s64 = r11.s64 + 8109;
	// bl 0x8239c698
	ctx.lr = 0x82711D94;
	sub_8239C698(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82711db4
	if (cr6.eq) goto loc_82711DB4;
	// li r5,1
	ctx.r5.s64 = 1;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x8239c080
	ctx.lr = 0x82711DA8;
	sub_8239C080(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e80
	ctx.lr = 0x82711DB4;
	sub_822A8E80(ctx, base);
loc_82711DB4:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82711d44
	if (cr6.lt) goto loc_82711D44;
loc_82711DC8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82711DD8"))) PPC_WEAK_FUNC(sub_82711DD8);
PPC_FUNC_IMPL(__imp__sub_82711DD8) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82711DE0;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-896(r1)
	ea = -896 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// bl 0x827142a0
	ctx.lr = 0x82711DF8;
	sub_827142A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82712548
	if (!cr6.eq) goto loc_82712548;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// ori r27,r9,64167
	r27.u64 = ctx.r9.u64 | 64167;
	// li r25,0
	r25.s64 = 0;
	// lfs f30,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f30.f64 = double(temp.f32);
	// addi r31,r11,2192
	r31.s64 = r11.s64 + 2192;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x827121d0
	if (cr6.eq) goto loc_827121D0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82711E3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82711ff0
	if (cr6.eq) goto loc_82711FF0;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711ff0
	if (cr6.eq) goto loc_82711FF0;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r3,640(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 640);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82711ff0
	if (cr6.eq) goto loc_82711FF0;
	// bl 0x82245340
	ctx.lr = 0x82711E68;
	sub_82245340(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82711ff0
	if (cr6.eq) goto loc_82711FF0;
	// lwz r28,36(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lwz r5,60(r28)
	ctx.r5.u64 = PPC_LOAD_U32(r28.u32 + 60);
	// cmplw cr6,r26,r5
	cr6.compare<uint32_t>(r26.u32, ctx.r5.u32, xer);
	// bne cr6,0x82711f7c
	if (!cr6.eq) goto loc_82711F7C;
	// lfs f0,64(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 64);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x82711ff0
	if (!cr6.gt) goto loc_82711FF0;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,64(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 64, temp.u32);
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// lfs f12,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f30
	cr6.compare(ctx.f12.f64, f30.f64);
	// bgt cr6,0x82711ff0
	if (cr6.gt) goto loc_82711FF0;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82711ef8
	if (!cr6.gt) goto loc_82711EF8;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r11,0
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r9,r8,r27
	ctx.r9.s64 = ctx.r8.s64 * r27.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r7,r10,1
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// rotlwi r8,r7,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r6,r7,r11
	ctx.r6.s32 = ctx.r7.s32 / r11.s32;
	// addi r5,r8,-1
	ctx.r5.s64 = ctx.r8.s64 + -1;
	// mullw r4,r6,r11
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(r11.s32);
	// andc r3,r11,r5
	ctx.r3.u64 = r11.u64 & ~ctx.r5.u64;
	// rldicl r11,r10,32,32
	r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// twlgei r3,-1
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// subf r29,r4,r7
	r29.s64 = ctx.r7.s64 - ctx.r4.s64;
	// b 0x82711efc
	goto loc_82711EFC;
loc_82711EF8:
	// li r29,0
	r29.s64 = 0;
loc_82711EFC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82710440
	ctx.lr = 0x82711F08;
	sub_82710440(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711f48
	if (cr6.eq) goto loc_82711F48;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x82714af8
	ctx.lr = 0x82711F1C;
	sub_82714AF8(ctx, base);
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x8270c2d8
	ctx.lr = 0x82711F2C;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x82714080
	ctx.lr = 0x82711F38;
	sub_82714080(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// bl 0x82714070
	ctx.lr = 0x82711F44;
	sub_82714070(ctx, base);
	// b 0x82711ff0
	goto loc_82711FF0;
loc_82711F48:
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x82714b50
	ctx.lr = 0x82711F50;
	sub_82714B50(ctx, base);
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x8270c2d8
	ctx.lr = 0x82711F60;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x82714080
	ctx.lr = 0x82711F6C;
	sub_82714080(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r1,624
	ctx.r3.s64 = ctx.r1.s64 + 624;
	// bl 0x82714070
	ctx.lr = 0x82711F78;
	sub_82714070(ctx, base);
	// b 0x82711ff0
	goto loc_82711FF0;
loc_82711F7C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82710440
	ctx.lr = 0x82711F88;
	sub_82710440(ctx, base);
	// clrlwi r29,r3,24
	r29.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82711fbc
	if (cr6.eq) goto loc_82711FBC;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82711fdc
	if (cr6.eq) goto loc_82711FDC;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82710440
	ctx.lr = 0x82711FA8;
	sub_82710440(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711fdc
	if (cr6.eq) goto loc_82711FDC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82711fe8
	if (!cr6.eq) goto loc_82711FE8;
loc_82711FBC:
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82711fe8
	if (cr6.eq) goto loc_82711FE8;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82710440
	ctx.lr = 0x82711FD0;
	sub_82710440(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82711fe8
	if (cr6.eq) goto loc_82711FE8;
loc_82711FDC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,64(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 64, temp.u32);
loc_82711FE8:
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// stw r26,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r26.u32);
loc_82711FF0:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827120c8
	if (!cr6.eq) goto loc_827120C8;
	// lwz r11,36(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827120c8
	if (cr6.eq) goto loc_827120C8;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827120c8
	if (cr6.eq) goto loc_827120C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r26,-1
	r26.s64 = -1;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f31,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// ble cr6,0x827120c8
	if (!cr6.gt) goto loc_827120C8;
	// li r28,0
	r28.s64 = 0;
loc_82712038:
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r10,r11,r28
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r28.u32);
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8271207c
	if (cr6.eq) goto loc_8271207C;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// bl 0x822aafc8
	ctx.lr = 0x8271205C;
	sub_822AAFC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8271207c
	if (cr6.eq) goto loc_8271207C;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x8271207c
	if (!cr6.gt) goto loc_8271207C;
	// fmr f31,f0
	f31.f64 = f0.f64;
	// mr r26,r29
	r26.u64 = r29.u64;
loc_8271207C:
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82712038
	if (cr6.lt) goto loc_82712038;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x827120c8
	if (cr6.lt) goto loc_827120C8;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82714db8
	ctx.lr = 0x827120A0;
	sub_82714DB8(ctx, base);
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x8270c2d8
	ctx.lr = 0x827120B0;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82714080
	ctx.lr = 0x827120BC;
	sub_82714080(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// bl 0x82714070
	ctx.lr = 0x827120C8;
	sub_82714070(ctx, base);
loc_827120C8:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827121d0
	if (!cr6.eq) goto loc_827121D0;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bge cr6,0x827121d0
	if (!cr6.lt) goto loc_827121D0;
	// lwz r10,72(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x827121d0
	if (!cr6.gt) goto loc_827121D0;
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827121d0
	if (cr6.eq) goto loc_827121D0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827121d0
	if (cr6.eq) goto loc_827121D0;
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827121d0
	if (cr6.eq) goto loc_827121D0;
	// lbz r11,32(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827121d0
	if (cr6.eq) goto loc_827121D0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// twllei r10,0
	// mulld r11,r11,r27
	r11.s64 = r11.s64 * r27.s64;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// clrlwi r9,r11,1
	ctx.r9.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r8,r9,r10
	ctx.r8.s32 = ctx.r9.s32 / ctx.r10.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r10
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// andc r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 & ~ctx.r7.u64;
	// subf r29,r6,r9
	r29.s64 = ctx.r9.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// bl 0x82714d60
	ctx.lr = 0x82712168;
	sub_82714D60(ctx, base);
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r29,1
	ctx.r3.s64 = r29.s64 + 1;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// bl 0x82250268
	ctx.lr = 0x8271217C;
	sub_82250268(ctx, base);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x8270c2d8
	ctx.lr = 0x8271218C;
	sub_8270C2D8(ctx, base);
	// stw r3,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r3.u32);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x8270c2d8
	ctx.lr = 0x827121A0;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82714080
	ctx.lr = 0x827121AC;
	sub_82714080(ctx, base);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827121c8
	if (cr6.eq) goto loc_827121C8;
	// lwz r11,100(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 100);
	// li r25,1
	r25.s64 = 1;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,100(r30)
	PPC_STORE_U32(r30.u32 + 100, r11.u32);
loc_827121C8:
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x82714070
	ctx.lr = 0x827121D0;
	sub_82714070(ctx, base);
loc_827121D0:
	// clrlwi r10,r25,24
	ctx.r10.u64 = r25.u32 & 0xFF;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r26,r11,-13624
	r26.s64 = r11.s64 + -13624;
	// bne cr6,0x827124e8
	if (!cr6.eq) goto loc_827124E8;
	// lfs f0,112(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 112);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x827124e8
	if (!cr6.eq) goto loc_827124E8;
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82712240
	if (!cr6.gt) goto loc_82712240;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// twllei r11,0
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r10,r10,r27
	ctx.r10.s64 = ctx.r10.s64 * r27.s64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r7,r10,1
	ctx.r7.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// rotlwi r8,r7,1
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// divw r6,r7,r11
	ctx.r6.s32 = ctx.r7.s32 / r11.s32;
	// addi r5,r8,-1
	ctx.r5.s64 = ctx.r8.s64 + -1;
	// mullw r4,r6,r11
	ctx.r4.s64 = int64_t(ctx.r6.s32) * int64_t(r11.s32);
	// andc r3,r11,r5
	ctx.r3.u64 = r11.u64 & ~ctx.r5.u64;
	// rldicl r11,r10,32,32
	r11.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// twlgei r3,-1
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// subf r28,r4,r7
	r28.s64 = ctx.r7.s64 - ctx.r4.s64;
	// b 0x82712244
	goto loc_82712244;
loc_82712240:
	// li r28,0
	r28.s64 = 0;
loc_82712244:
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x82714848
	ctx.lr = 0x8271224C;
	sub_82714848(ctx, base);
	// addi r11,r1,768
	r11.s64 = ctx.r1.s64 + 768;
	// addi r3,r1,672
	ctx.r3.s64 = ctx.r1.s64 + 672;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// bl 0x827148f8
	ctx.lr = 0x8271225C;
	sub_827148F8(ctx, base);
	// addi r10,r1,672
	ctx.r10.s64 = ctx.r1.s64 + 672;
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// stw r10,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// li r29,2
	r29.s64 = 2;
	// bl 0x82714998
	ctx.lr = 0x82712270;
	sub_82714998(ctx, base);
	// bl 0x82701928
	ctx.lr = 0x82712274;
	sub_82701928(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82712288
	if (!cr6.eq) goto loc_82712288;
	// addi r11,r1,576
	r11.s64 = ctx.r1.s64 + 576;
	// li r29,3
	r29.s64 = 3;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
loc_82712288:
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x82714d08
	ctx.lr = 0x82712290;
	sub_82714D08(ctx, base);
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,480
	ctx.r9.s64 = ctx.r1.s64 + 480;
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
	// bl 0x827148a0
	ctx.lr = 0x827122AC;
	sub_827148A0(ctx, base);
	// lwz r11,32(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82712300
	if (cr6.eq) goto loc_82712300;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827122d8
	if (cr6.eq) goto loc_827122D8;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827122d8
	if (cr6.eq) goto loc_827122D8;
	// lfs f0,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// b 0x827122dc
	goto loc_827122DC;
loc_827122D8:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_827122DC:
	// lis r11,-32251
	r11.s64 = -2113601536;
	// lfs f13,-30480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -30480);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82712300
	if (!cr6.gt) goto loc_82712300;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
loc_82712300:
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x827149f0
	ctx.lr = 0x82712308;
	sub_827149F0(ctx, base);
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x82714a48
	ctx.lr = 0x82712310;
	sub_82714A48(ctx, base);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82714aa0
	ctx.lr = 0x82712318;
	sub_82714AA0(ctx, base);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x82714cb0
	ctx.lr = 0x82712320;
	sub_82714CB0(ctx, base);
	// addi r3,r1,720
	ctx.r3.s64 = ctx.r1.s64 + 720;
	// bl 0x827147f0
	ctx.lr = 0x82712328;
	sub_827147F0(ctx, base);
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x8271241c
	if (!cr6.gt) goto loc_8271241C;
	// addi r5,r11,-1
	ctx.r5.s64 = r11.s64 + -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r28,1
	ctx.r3.s64 = r28.s64 + 1;
	// bl 0x82250268
	ctx.lr = 0x82712344;
	sub_82250268(ctx, base);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// bl 0x8270c2d8
	ctx.lr = 0x82712354;
	sub_8270C2D8(ctx, base);
	// stw r3,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r3.u32);
	// stw r3,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r3.u32);
	// bl 0x82256058
	ctx.lr = 0x82712360;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// rlwinm r10,r29,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r11,r29,1
	r11.s64 = r29.s64 + 1;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// bne cr6,0x8271237c
	if (!cr6.eq) goto loc_8271237C;
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
loc_8271237C:
	// stwx r8,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r8.u32);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,168(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f1,384(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 384);
	ctx.f1.f64 = double(temp.f32);
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// stw r10,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r10.u32);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// stw r10,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
	// stwx r4,r7,r6
	PPC_STORE_U32(ctx.r7.u32 + ctx.r6.u32, ctx.r4.u32);
	// bl 0x827110c8
	ctx.lr = 0x827123C0;
	sub_827110C8(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x827123d8
	if (!cr6.eq) goto loc_827123D8;
	// li r11,1
	r11.s64 = 1;
	// stb r11,96(r30)
	PPC_STORE_U8(r30.u32 + 96, r11.u8);
	// b 0x8271241c
	goto loc_8271241C;
loc_827123D8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827110c8
	ctx.lr = 0x827123E8;
	sub_827110C8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8271241c
	if (!cr6.eq) goto loc_8271241C;
	// lbz r11,96(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8271241c
	if (cr6.eq) goto loc_8271241C;
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,720
	ctx.r9.s64 = ctx.r1.s64 + 720;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// stb r8,96(r30)
	PPC_STORE_U8(r30.u32 + 96, ctx.r8.u8);
	// stwx r9,r11,r10
	PPC_STORE_U32(r11.u32 + ctx.r10.u32, ctx.r9.u32);
loc_8271241C:
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r28,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// mulld r11,r7,r27
	r11.s64 = ctx.r7.s64 * r27.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// twllei r29,0
	// clrlwi r6,r11,1
	ctx.r6.u64 = r11.u32 & 0x7FFFFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// divw r5,r6,r29
	ctx.r5.s32 = ctx.r6.s32 / r29.s32;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// rotlwi r10,r6,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 1);
	// mullw r4,r5,r29
	ctx.r4.s64 = int64_t(ctx.r5.s32) * int64_t(r29.s32);
	// lwz r11,76(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lwzx r3,r9,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// subf r11,r4,r6
	r11.s64 = ctx.r6.s64 - ctx.r4.s64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r7,r29,r10
	ctx.r7.u64 = r29.u64 & ~ctx.r10.u64;
	// twlgei r7,-1
	// lwzx r28,r9,r8
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x8270c2d8
	ctx.lr = 0x82712480;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,4(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82712494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r1,720
	ctx.r3.s64 = ctx.r1.s64 + 720;
	// bl 0x82714070
	ctx.lr = 0x827124A0;
	sub_82714070(ctx, base);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x82714070
	ctx.lr = 0x827124A8;
	sub_82714070(ctx, base);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x82714070
	ctx.lr = 0x827124B0;
	sub_82714070(ctx, base);
	// addi r3,r1,336
	ctx.r3.s64 = ctx.r1.s64 + 336;
	// bl 0x82714070
	ctx.lr = 0x827124B8;
	sub_82714070(ctx, base);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82714070
	ctx.lr = 0x827124C0;
	sub_82714070(ctx, base);
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// bl 0x82714070
	ctx.lr = 0x827124C8;
	sub_82714070(ctx, base);
	// addi r3,r1,480
	ctx.r3.s64 = ctx.r1.s64 + 480;
	// bl 0x82714070
	ctx.lr = 0x827124D0;
	sub_82714070(ctx, base);
	// addi r3,r1,576
	ctx.r3.s64 = ctx.r1.s64 + 576;
	// bl 0x82714070
	ctx.lr = 0x827124D8;
	sub_82714070(ctx, base);
	// addi r3,r1,672
	ctx.r3.s64 = ctx.r1.s64 + 672;
	// bl 0x82714070
	ctx.lr = 0x827124E0;
	sub_82714070(ctx, base);
	// addi r3,r1,768
	ctx.r3.s64 = ctx.r1.s64 + 768;
	// bl 0x82714070
	ctx.lr = 0x827124E8;
	sub_82714070(ctx, base);
loc_827124E8:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82712548
	if (cr6.eq) goto loc_82712548;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,376(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r26.u32 + 376);
	f0.f64 = double(temp.f32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,380(r26)
	temp.u32 = PPC_LOAD_U32(r26.u32 + 380);
	ctx.f13.f64 = double(temp.f32);
	// mulld r11,r11,r27
	r11.s64 = r11.s64 * r27.s64;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// clrlwi r7,r11,9
	ctx.r7.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// lfs f13,14348(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// fmuls f8,f12,f9
	ctx.f8.f64 = double(float(ctx.f12.f64 * ctx.f9.f64));
	// fmadds f7,f8,f13,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 + f0.f64));
	// stfs f7,112(r30)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r30.u32 + 112, temp.u32);
loc_82712548:
	// addi r1,r1,896
	ctx.r1.s64 = ctx.r1.s64 + 896;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82712558"))) PPC_WEAK_FUNC(sub_82712558);
PPC_FUNC_IMPL(__imp__sub_82712558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r7,r11,2272
	ctx.r7.s64 = r11.s64 + 2272;
	// li r6,48
	ctx.r6.s64 = 48;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// addi r4,r8,29684
	ctx.r4.s64 = ctx.r8.s64 + 29684;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// lfs f0,14192(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stb r10,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, ctx.r10.u8);
	// stb r10,29(r3)
	PPC_STORE_U8(ctx.r3.u32 + 29, ctx.r10.u8);
	// stb r10,30(r3)
	PPC_STORE_U8(ctx.r3.u32 + 30, ctx.r10.u8);
	// stb r10,31(r3)
	PPC_STORE_U8(ctx.r3.u32 + 31, ctx.r10.u8);
	// stw r11,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, r11.u32);
	// stw r11,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r11.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,68(r3)
	PPC_STORE_U8(ctx.r3.u32 + 68, r11.u8);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stw r11,72(r3)
	PPC_STORE_U32(ctx.r3.u32 + 72, r11.u32);
	// stw r11,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, r11.u32);
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// sth r11,80(r3)
	PPC_STORE_U16(ctx.r3.u32 + 80, r11.u16);
	// sth r11,82(r3)
	PPC_STORE_U16(ctx.r3.u32 + 82, r11.u16);
	// stfs f0,104(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// stfs f0,108(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stb r11,84(r3)
	PPC_STORE_U8(ctx.r3.u32 + 84, r11.u8);
	// stfs f0,112(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// stw r9,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r9.u32);
	// stfs f0,116(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// stw r9,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r9.u32);
	// stfs f0,120(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 120, temp.u32);
	// stb r10,96(r3)
	PPC_STORE_U8(ctx.r3.u32 + 96, ctx.r10.u8);
	// stfs f0,124(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 124, temp.u32);
	// stw r11,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, r11.u32);
	// stfs f0,128(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 128, temp.u32);
	// stfs f0,132(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// stfs f0,136(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 136, temp.u32);
	// stfs f0,140(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 140, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82712610"))) PPC_WEAK_FUNC(sub_82712610);
PPC_FUNC_IMPL(__imp__sub_82712610) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,29(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 29);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82712618"))) PPC_WEAK_FUNC(sub_82712618);
PPC_FUNC_IMPL(__imp__sub_82712618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// addi r10,r11,-13624
	ctx.r10.s64 = r11.s64 + -13624;
	// lfs f1,192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 192);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82712628"))) PPC_WEAK_FUNC(sub_82712628);
PPC_FUNC_IMPL(__imp__sub_82712628) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,29684
	ctx.r10.s64 = r11.s64 + 29684;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lhz r9,82(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 82);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r3,76(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82712648"))) PPC_WEAK_FUNC(sub_82712648);
PPC_FUNC_IMPL(__imp__sub_82712648) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8271264C"))) PPC_WEAK_FUNC(sub_8271264C);
PPC_FUNC_IMPL(__imp__sub_8271264C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82712650"))) PPC_WEAK_FUNC(sub_82712650);
PPC_FUNC_IMPL(__imp__sub_82712650) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82712658;
	// stfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f29.u64);
	// stfd f30,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, f30.u64);
	// stfd f31,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// stwu r1,-1248(r1)
	ea = -1248 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// lbz r11,20(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82712ab4
	if (!cr6.eq) goto loc_82712AB4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r20,1
	r20.s64 = 1;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8271269c
	if (cr6.eq) goto loc_8271269C;
	// lis r10,6
	ctx.r10.s64 = 393216;
	// ori r9,r10,17106
	ctx.r9.u64 = ctx.r10.u64 | 17106;
	// stbx r20,r11,r9
	PPC_STORE_U8(r11.u32 + ctx.r9.u32, r20.u8);
loc_8271269C:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,72(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// li r7,48
	ctx.r7.s64 = 48;
	// stb r20,96(r28)
	PPC_STORE_U8(r28.u32 + 96, r20.u8);
	// li r11,-1
	r11.s64 = -1;
	// li r21,0
	r21.s64 = 0;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stw r11,88(r28)
	PPC_STORE_U32(r28.u32 + 88, r11.u32);
	// lfs f31,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stw r11,92(r28)
	PPC_STORE_U32(r28.u32 + 92, r11.u32);
	// stfs f0,64(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 64, temp.u32);
	// stw r21,24(r28)
	PPC_STORE_U32(r28.u32 + 24, r21.u32);
	// stfs f31,144(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 144, temp.u32);
	// stb r21,68(r28)
	PPC_STORE_U8(r28.u32 + 68, r21.u8);
	// stfs f31,140(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 140, temp.u32);
	// stw r21,100(r28)
	PPC_STORE_U32(r28.u32 + 100, r21.u32);
	// stfs f31,136(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 136, temp.u32);
	// mr r11,r21
	r11.u64 = r21.u64;
	// stfs f31,132(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 132, temp.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stfs f31,128(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 128, temp.u32);
	// stfs f31,124(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 124, temp.u32);
	// stfs f31,120(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 120, temp.u32);
	// stfs f31,116(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 116, temp.u32);
	// stfs f31,112(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 112, temp.u32);
	// stfs f31,108(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 108, temp.u32);
	// stfs f31,104(r28)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 104, temp.u32);
	// stvx128 v63,r28,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x82712738
	if (!cr6.gt) goto loc_82712738;
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
loc_8271271C:
	// lwz r9,76(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stwx r21,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r21.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// lwz r8,72(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8271271c
	if (cr6.lt) goto loc_8271271C;
loc_82712738:
	// lis r23,-32121
	r23.s64 = -2105081856;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827127a0
	if (cr6.eq) goto loc_827127A0;
	// lbz r11,12(r4)
	r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 12);
	// lwz r10,76(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// stb r11,28(r28)
	PPC_STORE_U8(r28.u32 + 28, r11.u8);
	// lbz r9,13(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 13);
	// stb r9,29(r28)
	PPC_STORE_U8(r28.u32 + 29, ctx.r9.u8);
	// lbz r8,14(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 14);
	// stb r8,30(r28)
	PPC_STORE_U8(r28.u32 + 30, ctx.r8.u8);
	// lbz r7,15(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 15);
	// stb r7,31(r28)
	PPC_STORE_U8(r28.u32 + 31, ctx.r7.u8);
	// lfs f0,16(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	f0.f64 = double(temp.f32);
	// stfs f0,120(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 120, temp.u32);
	// lwz r6,4(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r6,32(r28)
	PPC_STORE_U32(r28.u32 + 32, ctx.r6.u32);
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r5,36(r28)
	PPC_STORE_U32(r28.u32 + 36, ctx.r5.u32);
	// lwz r3,0(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827127a0
	if (cr6.eq) goto loc_827127A0;
	// lwz r11,72(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82712a84
	if (!cr6.gt) goto loc_82712A84;
loc_827127A0:
	// lwz r3,-10016(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10016);
	// bl 0x82701080
	ctx.lr = 0x827127A8;
	sub_82701080(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// clrlwi r22,r26,16
	r22.u64 = r26.u32 & 0xFFFF;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x827127c8
	if (cr6.eq) goto loc_827127C8;
	// rlwinm r3,r26,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x827127C0;
	sub_82130528(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// b 0x827127cc
	goto loc_827127CC;
loc_827127C8:
	// mr r25,r21
	r25.u64 = r21.u64;
loc_827127CC:
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x827127e4
	if (cr6.eq) goto loc_827127E4;
	// rlwinm r3,r26,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x827127DC;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x827127e8
	goto loc_827127E8;
loc_827127E4:
	// mr r27,r21
	r27.u64 = r21.u64;
loc_827127E8:
	// lwz r3,32(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82712800
	if (cr6.eq) goto loc_82712800;
	// bl 0x822a8108
	ctx.lr = 0x827127F8;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// b 0x82712810
	goto loc_82712810;
loc_82712800:
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stfs f31,84(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
loc_82712810:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r31,r21
	r31.u64 = r21.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x8271288c
	if (!cr6.gt) goto loc_8271288C;
	// lfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f31.f64 = double(temp.f32);
	// mr r30,r27
	r30.u64 = r27.u64;
	// lfs f30,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f30.f64 = double(temp.f32);
	// subf r29,r27,r25
	r29.s64 = r25.s64 - r27.s64;
	// lfs f29,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f29.f64 = double(temp.f32);
loc_8271283C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10016(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10016);
	// bl 0x827010e8
	ctx.lr = 0x82712848;
	sub_827010E8(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x8271284C;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f30
	ctx.f13.f64 = double(float(f0.f64 - f30.f64));
	// lfs f12,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 - f31.f64));
	// lfs f10,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f29
	ctx.f9.f64 = double(float(ctx.f10.f64 - f29.f64));
	// fmuls f8,f13,f13
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f7,f11,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f8.f64));
	// fmadds f6,f9,f9,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// stfsx f6,r29,r30
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r29.u32 + r30.u32, temp.u32);
	// stw r31,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r31.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r26
	cr6.compare<int32_t>(r31.s32, r26.s32, xer);
	// blt cr6,0x8271283c
	if (cr6.lt) goto loc_8271283C;
loc_8271288C:
	// cmpwi cr6,r26,1
	cr6.compare<int32_t>(r26.s32, 1, xer);
	// ble cr6,0x827129d8
	if (!cr6.gt) goto loc_827129D8;
	// addi r6,r26,-1
	ctx.r6.s64 = r26.s64 + -1;
	// addi r5,r26,-1
	ctx.r5.s64 = r26.s64 + -1;
loc_8271289C:
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// cmpwi cr6,r6,4
	cr6.compare<int32_t>(ctx.r6.s32, 4, xer);
	// blt cr6,0x82712974
	if (cr6.lt) goto loc_82712974;
	// addi r11,r6,-4
	r11.s64 = ctx.r6.s64 + -4;
	// addi r10,r27,12
	ctx.r10.s64 = r27.s64 + 12;
	// rlwinm r9,r11,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r11,r25,4
	r11.s64 = r25.s64 + 4;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// subf r9,r25,r27
	ctx.r9.s64 = r27.s64 - r25.s64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_827128C4:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x827128ec
	if (!cr6.gt) goto loc_827128EC;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,-4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// lwz r3,-12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12);
	// lwzx r4,r11,r9
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stwx r3,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r3.u32);
	// stw r4,-12(r10)
	PPC_STORE_U32(ctx.r10.u32 + -12, ctx.r4.u32);
loc_827128EC:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82712914
	if (!cr6.gt) goto loc_82712914;
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f0,4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// lwzx r4,r11,r9
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// lwz r3,-4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stw r4,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r4.u32);
	// stwx r3,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82712914:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8271293c
	if (!cr6.gt) goto loc_8271293C;
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r3,-4(r10)
	PPC_STORE_U32(ctx.r10.u32 + -4, ctx.r3.u32);
loc_8271293C:
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82712964
	if (!cr6.gt) goto loc_82712964;
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// stfs f0,12(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 12, temp.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r4,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r4.u32);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
loc_82712964:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x827128c4
	if (!cr0.eq) goto loc_827128C4;
loc_82712974:
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// bge cr6,0x827129cc
	if (!cr6.lt) goto loc_827129CC;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r25,r27
	ctx.r8.s64 = r27.s64 - r25.s64;
	// add r9,r11,r25
	ctx.r9.u64 = r11.u64 + r25.u64;
	// add r10,r11,r27
	ctx.r10.u64 = r11.u64 + r27.u64;
	// addi r11,r9,4
	r11.s64 = ctx.r9.s64 + 4;
	// subf r9,r7,r6
	ctx.r9.s64 = ctx.r6.s64 - ctx.r7.s64;
loc_82712994:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x827129bc
	if (!cr6.gt) goto loc_827129BC;
	// stfs f0,-4(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -4, temp.u32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// lwzx r4,r11,r8
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stwx r7,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r7.u32);
loc_827129BC:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82712994
	if (!cr0.eq) goto loc_82712994;
loc_827129CC:
	// addic. r5,r5,-1
	xer.ca = ctx.r5.u32 > 0;
	ctx.r5.s64 = ctx.r5.s64 + -1;
	cr0.compare<int32_t>(ctx.r5.s32, 0, xer);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// bne 0x8271289c
	if (!cr0.eq) goto loc_8271289C;
loc_827129D8:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82712a5c
	if (!cr6.gt) goto loc_82712A5C;
	// clrlwi r30,r24,24
	r30.u64 = r24.u32 & 0xFF;
	// mr r31,r27
	r31.u64 = r27.u64;
	// mr r29,r26
	r29.u64 = r26.u64;
loc_827129EC:
	// lwz r3,-10016(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10016);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x827010e8
	ctx.lr = 0x827129F8;
	sub_827010E8(ctx, base);
	// lbz r11,872(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 872);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x82712a50
	if (!cr6.eq) goto loc_82712A50;
	// lwz r11,72(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// mr r9,r21
	ctx.r9.u64 = r21.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82712a50
	if (!cr6.gt) goto loc_82712A50;
	// lwz r8,76(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_82712A1C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r10,r3
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, xer);
	// beq cr6,0x82712a50
	if (cr6.eq) goto loc_82712A50;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82712a48
	if (cr6.eq) goto loc_82712A48;
	// lwz r10,72(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x82712a1c
	if (cr6.lt) goto loc_82712A1C;
	// b 0x82712a50
	goto loc_82712A50;
loc_82712A48:
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r8
	PPC_STORE_U32(r11.u32 + ctx.r8.u32, ctx.r3.u32);
loc_82712A50:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x827129ec
	if (!cr0.eq) goto loc_827129EC;
loc_82712A5C:
	// clrlwi r11,r22,16
	r11.u64 = r22.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82712a70
	if (cr6.eq) goto loc_82712A70;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x82712A70;
	sub_82130588(ctx, base);
loc_82712A70:
	// clrlwi r11,r22,16
	r11.u64 = r22.u32 & 0xFFFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82712a84
	if (cr6.eq) goto loc_82712A84;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82130588
	ctx.lr = 0x82712A84;
	sub_82130588(ctx, base);
loc_82712A84:
	// lwz r11,72(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// lwz r10,76(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82712acc
	if (!cr6.eq) goto loc_82712ACC;
loc_82712AA0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82712AB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82712AB4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1248
	ctx.r1.s64 = ctx.r1.s64 + 1248;
	// lfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f30,-120(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82712ACC:
	// mr r30,r21
	r30.u64 = r21.u64;
	// stb r21,84(r28)
	PPC_STORE_U8(r28.u32 + 84, r21.u8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82712b74
	if (!cr6.gt) goto loc_82712B74;
	// mr r31,r21
	r31.u64 = r21.u64;
loc_82712AE0:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 88);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82712AF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82712b2c
	if (cr6.eq) goto loc_82712B2C;
	// lwz r11,76(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r9,876(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 876);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82712b2c
	if (!cr6.eq) goto loc_82712B2C;
	// rotlwi r4,r10,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r3,-10016(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10016);
	// bl 0x827053c8
	ctx.lr = 0x82712B20;
	sub_827053C8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82712aa0
	if (cr6.eq) goto loc_82712AA0;
loc_82712B2C:
	// lwz r11,76(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x82700070
	ctx.lr = 0x82712B3C;
	sub_82700070(ctx, base);
	// lwz r10,76(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x822a8e20
	ctx.lr = 0x82712B48;
	sub_822A8E20(ctx, base);
	// lwz r9,76(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwz r7,656(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 656);
	// cmpwi cr6,r7,3
	cr6.compare<int32_t>(ctx.r7.s32, 3, xer);
	// beq cr6,0x82712b60
	if (cr6.eq) goto loc_82712B60;
	// stb r20,84(r28)
	PPC_STORE_U8(r28.u32 + 84, r20.u8);
loc_82712B60:
	// lwz r11,72(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82712ae0
	if (cr6.lt) goto loc_82712AE0;
loc_82712B74:
	// lwz r11,72(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// mr r30,r21
	r30.u64 = r21.u64;
	// stb r21,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r21.u8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82712bc8
	if (!cr6.gt) goto loc_82712BC8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r31,r21
	r31.u64 = r21.u64;
	// addi r29,r11,29812
	r29.s64 = r11.s64 + 29812;
loc_82712B94:
	// lwz r11,76(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r7,868(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 868);
	// bl 0x82137a08
	ctx.lr = 0x82712BB4;
	sub_82137A08(ctx, base);
	// lwz r9,72(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x82712b94
	if (cr6.lt) goto loc_82712B94;
loc_82712BC8:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82712BDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// rlwinm r6,r3,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,16(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// addi r11,r9,-24332
	r11.s64 = ctx.r9.s64 + -24332;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r5,r10,29776
	ctx.r5.s64 = ctx.r10.s64 + 29776;
	// li r4,2
	ctx.r4.s64 = 2;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwzx r6,r6,r11
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + r11.u32);
	// bl 0x82130000
	ctx.lr = 0x82712C08;
	sub_82130000(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r20,20(r28)
	PPC_STORE_U8(r28.u32 + 20, r20.u8);
	// addi r1,r1,1248
	ctx.r1.s64 = ctx.r1.s64 + 1248;
	// lfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f30,-120(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82712C24"))) PPC_WEAK_FUNC(sub_82712C24);
PPC_FUNC_IMPL(__imp__sub_82712C24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82712C28"))) PPC_WEAK_FUNC(sub_82712C28);
PPC_FUNC_IMPL(__imp__sub_82712C28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
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
	PPCRegister f31{};
	PPCVRegister v127{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x82712C30;
	// stfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f31.u64);
	// li r12,-128
	r12.s64 = -128;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r9
	r29.u64 = ctx.r9.u64;
	// vor128 v127,v1,v1
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// lis r9,6
	ctx.r9.s64 = 393216;
	// mr r26,r8
	r26.u64 = ctx.r8.u64;
	// ori r8,r9,16712
	ctx.r8.u64 = ctx.r9.u64 | 16712;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// mr r22,r7
	r22.u64 = ctx.r7.u64;
	// mr r21,r10
	r21.u64 = ctx.r10.u64;
	// lwz r10,32(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 32);
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// lwz r11,60(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 60);
	// add r31,r11,r10
	r31.u64 = r11.u64 + ctx.r10.u64;
	// lhz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82712e00
	if (cr6.eq) goto loc_82712E00;
	// li r28,0
	r28.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// sth r28,132(r1)
	PPC_STORE_U16(ctx.r1.u32 + 132, r28.u16);
	// sth r28,134(r1)
	PPC_STORE_U16(ctx.r1.u32 + 134, r28.u16);
	// bl 0x8247bb70
	ctx.lr = 0x82712CA8;
	sub_8247BB70(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r20,128(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// beq cr6,0x82712cf0
	if (cr6.eq) goto loc_82712CF0;
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82712d1c
	if (cr6.eq) goto loc_82712D1C;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82712CCC:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// stwx r8,r11,r20
	PPC_STORE_U32(r11.u32 + r20.u32, ctx.r8.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// lhz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x82712ccc
	if (cr6.lt) goto loc_82712CCC;
	// b 0x82712d1c
	goto loc_82712D1C;
loc_82712CF0:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x82712d1c
	if (cr0.lt) goto loc_82712D1C;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r9,r20
	ctx.r9.u64 = r20.u64;
loc_82712D00:
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lwzx r7,r10,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bge 0x82712d00
	if (!cr0.lt) goto loc_82712D00;
loc_82712D1C:
	// lhz r25,132(r1)
	r25.u64 = PPC_LOAD_U16(ctx.r1.u32 + 132);
	// mr r30,r28
	r30.u64 = r28.u64;
	// lwz r27,380(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82712d74
	if (!cr6.gt) goto loc_82712D74;
	// mr r31,r20
	r31.u64 = r20.u64;
loc_82712D34:
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r9,r27
	ctx.r9.u64 = r27.u64;
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82710b70
	ctx.lr = 0x82712D58;
	sub_82710B70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82712e18
	if (!cr6.eq) goto loc_82712E18;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r25
	cr6.compare<int32_t>(r30.s32, r25.s32, xer);
	// blt cr6,0x82712d34
	if (cr6.lt) goto loc_82712D34;
loc_82712D74:
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x82712dec
	if (!cr6.gt) goto loc_82712DEC;
	// mr r31,r29
	r31.u64 = r29.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x82712dec
	if (!cr6.gt) goto loc_82712DEC;
	// lwz r29,388(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// mr r30,r20
	r30.u64 = r20.u64;
loc_82712D90:
	// addi r26,r26,-1
	r26.s64 = r26.s64 + -1;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// mr r10,r21
	ctx.r10.u64 = r21.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// stw r29,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r29.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// stw r27,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r27.u32);
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82712c28
	ctx.lr = 0x82712DC4;
	sub_82712C28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82712e54
	if (!cr6.eq) goto loc_82712E54;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// rlwinm r31,r10,27,31,31
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// cmpw cr6,r28,r25
	cr6.compare<int32_t>(r28.s32, r25.s32, xer);
	// blt cr6,0x82712d90
	if (cr6.lt) goto loc_82712D90;
loc_82712DEC:
	// lhz r10,134(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 134);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82712e00
	if (cr6.eq) goto loc_82712E00;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82130588
	ctx.lr = 0x82712E00;
	sub_82130588(ctx, base);
loc_82712E00:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82712E18:
	// rlwinm r11,r30,2,0,29
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,388(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// lhz r8,134(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 134);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwzx r7,r11,r20
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + r20.u32);
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// beq cr6,0x82712e3c
	if (cr6.eq) goto loc_82712E3C;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82130588
	ctx.lr = 0x82712E3C;
	sub_82130588(ctx, base);
loc_82712E3C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
loc_82712E54:
	// rlwinm r11,r28,2,0,29
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r9,134(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 134);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lwzx r8,r11,r20
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + r20.u32);
	// stw r8,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r8.u32);
	// beq cr6,0x82712e3c
	if (cr6.eq) goto loc_82712E3C;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82130588
	ctx.lr = 0x82712E74;
	sub_82130588(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-128
	r0.s64 = -128;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f31,-112(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_82712E8C"))) PPC_WEAK_FUNC(sub_82712E8C);
PPC_FUNC_IMPL(__imp__sub_82712E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82712E90"))) PPC_WEAK_FUNC(sub_82712E90);
PPC_FUNC_IMPL(__imp__sub_82712E90) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,29684
	ctx.r10.s64 = r11.s64 + 29684;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,82(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 82);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82712ecc
	if (cr6.eq) goto loc_82712ECC;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// bl 0x82130588
	ctx.lr = 0x82712ECC;
	sub_82130588(ctx, base);
loc_82712ECC:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82712ee4
	if (cr6.eq) goto loc_82712EE4;
	// bl 0x82130588
	ctx.lr = 0x82712EE0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82712EE4:
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

__attribute__((alias("__imp__sub_82712EFC"))) PPC_WEAK_FUNC(sub_82712EFC);
PPC_FUNC_IMPL(__imp__sub_82712EFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82712F00"))) PPC_WEAK_FUNC(sub_82712F00);
PPC_FUNC_IMPL(__imp__sub_82712F00) {
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
	PPCRegister f14{};
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
	PPCVRegister v124{};
	PPCVRegister v125{};
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82712F08;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9a0
	ctx.lr = 0x82712F10;
	// addi r12,r1,-304
	r12.s64 = ctx.r1.s64 + -304;
	// bl 0x823dd534
	ctx.lr = 0x82712F18;
	// stwu r1,-1296(r1)
	ea = -1296 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,32(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82713f94
	if (cr6.eq) goto loc_82713F94;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713f94
	if (cr6.eq) goto loc_82713F94;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713f94
	if (cr6.eq) goto loc_82713F94;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713f94
	if (cr6.eq) goto loc_82713F94;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713f94
	if (cr6.eq) goto loc_82713F94;
	// bl 0x822a8108
	ctx.lr = 0x82712F60;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lwz r9,32(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r11,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r11.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// stw r3,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r3.u32);
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// lwz r4,72(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,0
	r28.s64 = 0;
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,48(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lfs f0,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	f0.f64 = double(temp.f32);
	// stw r28,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r28.u32);
	// sth r28,188(r1)
	PPC_STORE_U16(ctx.r1.u32 + 188, r28.u16);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// sth r28,190(r1)
	PPC_STORE_U16(ctx.r1.u32 + 190, r28.u16);
	// addi r3,r1,184
	ctx.r3.s64 = ctx.r1.s64 + 184;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// addis r11,r11,6
	r11.s64 = r11.s64 + 393216;
	// addi r11,r11,16704
	r11.s64 = r11.s64 + 16704;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// lwz r10,28(r5)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r5,12(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	// lvx128 v62,r5,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r5,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_sub_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,308(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// bl 0x82478748
	ctx.lr = 0x82712FE8;
	sub_82478748(ctx, base);
	// lwz r4,72(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// mr r26,r28
	r26.u64 = r28.u64;
	// mr r31,r28
	r31.u64 = r28.u64;
	// stw r26,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, r26.u32);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lwz r27,184(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// ble cr6,0x82713040
	if (!cr6.gt) goto loc_82713040;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_82713008:
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x8270c8c0
	ctx.lr = 0x82713014;
	sub_8270C8C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// stbx r3,r27,r31
	PPC_STORE_U8(r27.u32 + r31.u32, ctx.r3.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82713028
	if (cr6.eq) goto loc_82713028;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
loc_82713028:
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82713008
	if (cr6.lt) goto loc_82713008;
	// stw r26,220(r1)
	PPC_STORE_U32(ctx.r1.u32 + 220, r26.u32);
loc_82713040:
	// lwz r11,36(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82713080
	if (cr6.eq) goto loc_82713080;
	// lwz r4,60(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82713080
	if (cr6.eq) goto loc_82713080;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82713080
	if (!cr6.eq) goto loc_82713080;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82710440
	ctx.lr = 0x82713070;
	sub_82710440(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82713084
	if (!cr6.eq) goto loc_82713084;
loc_82713080:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82713084:
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// clrlwi r21,r11,24
	r21.u64 = r11.u32 & 0xFF;
	// mr r25,r28
	r25.u64 = r28.u64;
	// stw r28,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r28.u32);
	// mr r15,r28
	r15.u64 = r28.u64;
	// mr r14,r28
	r14.u64 = r28.u64;
	// li r23,1
	r23.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x82713f80
	if (!cr6.gt) goto loc_82713F80;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r30,132(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,-28012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28012);
	f0.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f13,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lfs f15,-29232(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -29232);
	f15.f64 = double(temp.f32);
	// lfs f20,-12736(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12736);
	f20.f64 = double(temp.f32);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lfs f22,26468(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 26468);
	f22.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f23,31292(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 31292);
	f23.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,23960(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 23960);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f14,29828(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 29828);
	f14.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f18,30280(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 30280);
	f18.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f24,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f24.f64 = double(temp.f32);
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lfs f17,30712(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f17.f64 = double(temp.f32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lfs f16,14348(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14348);
	f16.f64 = double(temp.f32);
	// lfs f25,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f25.f64 = double(temp.f32);
	// lis r3,23772
	ctx.r3.s64 = 1557921792;
	// lfs f19,11360(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 11360);
	f19.f64 = double(temp.f32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lfs f28,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f28.f64 = double(temp.f32);
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// stfs f0,240(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r5,r9,2272
	ctx.r5.s64 = ctx.r9.s64 + 2272;
	// stfs f12,228(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r4,r8,-31616
	ctx.r4.s64 = ctx.r8.s64 + -31616;
	// ori r19,r3,64167
	r19.u64 = ctx.r3.u64 | 64167;
	// stw r5,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r5.u32);
	// ori r20,r6,65535
	r20.u64 = ctx.r6.u64 | 65535;
	// stw r4,236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 236, ctx.r4.u32);
	// lis r16,-32114
	r16.s64 = -2104623104;
	// lis r22,-32121
	r22.s64 = -2105081856;
	// addi r17,r11,2256
	r17.s64 = r11.s64 + 2256;
	// addi r24,r10,-13624
	r24.s64 = ctx.r10.s64 + -13624;
	// addi r27,r7,2192
	r27.s64 = ctx.r7.s64 + 2192;
loc_82713178:
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// rlwinm r26,r11,2,0,29
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r26,r10
	r11.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// lfs f0,1132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 1132);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bne cr6,0x82713f68
	if (!cr6.eq) goto loc_82713F68;
	// lwz r9,876(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 876);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82713f68
	if (cr6.eq) goto loc_82713F68;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713f68
	if (cr6.eq) goto loc_82713F68;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713f68
	if (cr6.eq) goto loc_82713F68;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713f68
	if (cr6.eq) goto loc_82713F68;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713f68
	if (cr6.eq) goto loc_82713F68;
	// lwzx r3,r26,r10
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// bl 0x822a8108
	ctx.lr = 0x827131D8;
	sub_822A8108(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// addi r7,r1,752
	ctx.r7.s64 = ctx.r1.s64 + 752;
	// lfs f13,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// li r11,16
	r11.s64 = 16;
	// lfs f12,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,768
	ctx.r6.s64 = ctx.r1.s64 + 768;
	// lfs f11,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// li r10,32
	ctx.r10.s64 = 32;
	// lwz r3,-10016(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10016);
	// addi r5,r1,784
	ctx.r5.s64 = ctx.r1.s64 + 784;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,800
	ctx.r7.s64 = ctx.r1.s64 + 800;
	// lvx128 v58,r9,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,48
	ctx.r4.s64 = 48;
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// lvx128 v57,r9,r10
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,272
	r31.s64 = ctx.r1.s64 + 272;
	// stvx128 v57,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,448
	ctx.r5.s64 = ctx.r1.s64 + 448;
	// lvx128 v63,r9,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r9,r26,r8
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + ctx.r8.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,276(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 276);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,272(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,280(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// fsubs f6,f9,f11
	ctx.f6.f64 = double(float(ctx.f9.f64 - ctx.f11.f64));
	// lwz r18,876(r9)
	r18.u64 = PPC_LOAD_U32(ctx.r9.u32 + 876);
	// lwz r7,28(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r4,12(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// lvx128 v56,r4,r10
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r4,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v127,v55,v56
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v127.f32, simde_mm_sub_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v56.f32)));
	// stvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f26,452(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 452);
	f26.f64 = double(temp.f32);
	// fadds f0,f10,f26
	f0.f64 = double(float(ctx.f10.f64 + f26.f64));
	// fsubs f5,f0,f13
	ctx.f5.f64 = double(float(f0.f64 - ctx.f13.f64));
	// stfs f0,276(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// lvx128 v2,r0,r31
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f4,f5,f5
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f27,f6,f6,f3
	f27.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// bl 0x82700578
	ctx.lr = 0x827132A4;
	sub_82700578(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82713f68
	if (!cr6.eq) goto loc_82713F68;
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lfs f0,324(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 324);
	f0.f64 = double(temp.f32);
	// lwz r10,184(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lbzx r11,r10,r11
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827132d4
	if (!cr6.eq) goto loc_827132D4;
	// fmuls f13,f0,f0
	ctx.f13.f64 = double(float(f0.f64 * f0.f64));
	// fcmpu cr6,f27,f13
	cr6.compare(f27.f64, ctx.f13.f64);
	// ble cr6,0x82713f68
	if (!cr6.gt) goto loc_82713F68;
loc_827132D4:
	// lwz r10,332(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 332);
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f28.f64);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,352(r1)
	PPC_STORE_U64(ctx.r1.u32 + 352, ctx.r10.u64);
	// lfd f13,352(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 352);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f19
	ctx.f10.f64 = double(float(ctx.f11.f64 * f19.f64));
	// fsel f9,f10,f10,f28
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f28.f64;
	// fsubs f8,f9,f25
	ctx.f8.f64 = double(float(ctx.f9.f64 - f25.f64));
	// fsel f21,f8,f25,f9
	f21.f64 = ctx.f8.f64 >= 0.0 ? f25.f64 : ctx.f9.f64;
	// ble cr6,0x82713318
	if (!cr6.gt) goto loc_82713318;
	// fsqrts f13,f27
	ctx.f13.f64 = double(float(sqrt(f27.f64)));
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fdivs f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 / f0.f64));
	// fadds f10,f11,f25
	ctx.f10.f64 = double(float(ctx.f11.f64 + f25.f64));
	// fmuls f21,f10,f21
	f21.f64 = double(float(ctx.f10.f64 * f21.f64));
loc_82713318:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8271333c
	if (!cr6.eq) goto loc_8271333C;
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lfs f0,328(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 328);
	f0.f64 = double(temp.f32);
	// lwzx r10,r26,r11
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// stfs f0,1132(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 1132, temp.u32);
	// lfs f0,328(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 328);
	f0.f64 = double(temp.f32);
	// stfs f0,120(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 120, temp.u32);
	// lfs f0,324(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 324);
	f0.f64 = double(temp.f32);
loc_8271333C:
	// lwz r11,184(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lwz r10,140(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lbzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8271338c
	if (!cr6.eq) goto loc_8271338C;
	// lwz r9,0(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// mulld r10,r9,r19
	ctx.r10.s64 = ctx.r9.s64 * r19.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r6,r11,9
	ctx.r6.u64 = r11.u32 & 0x7FFFFF;
	// stw r11,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r11.u32);
	// rldicl r5,r11,32,32
	ctx.r5.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// std r6,400(r1)
	PPC_STORE_U64(ctx.r1.u32 + 400, ctx.r6.u64);
	// lfd f13,400(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 400);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stw r5,4(r27)
	PPC_STORE_U32(r27.u32 + 4, ctx.r5.u32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f16
	ctx.f10.f64 = double(float(ctx.f11.f64 * f16.f64));
	// fcmpu cr6,f10,f21
	cr6.compare(ctx.f10.f64, f21.f64);
	// bge cr6,0x82713f50
	if (!cr6.lt) goto loc_82713F50;
loc_8271338C:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x82713500
	if (!cr6.eq) goto loc_82713500;
	// lwz r31,180(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// addi r11,r1,256
	r11.s64 = ctx.r1.s64 + 256;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lvx128 v54,r0,r31
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f17,268(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f17.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// bl 0x8224a2b8
	ctx.lr = 0x827133B4;
	sub_8224A2B8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x827134b0
	if (cr6.eq) goto loc_827134B0;
	// lwz r11,4(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 4);
	// rlwinm r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x827134fc
	if (cr6.eq) goto loc_827134FC;
	// stw r28,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r28.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r28,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r28.u32);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,216
	ctx.r4.s64 = ctx.r1.s64 + 216;
	// bl 0x82244840
	ctx.lr = 0x827133E8;
	sub_82244840(ctx, base);
	// lwz r3,32(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8271342c
	if (cr6.eq) goto loc_8271342C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8271342c
	if (cr6.eq) goto loc_8271342C;
	// lfs f0,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// lfs f13,228(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 228);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8271342c
	if (!cr6.lt) goto loc_8271342C;
	// lwz r11,212(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// lfs f0,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	f0.f64 = double(temp.f32);
	// lfs f13,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fneg f12,f0
	ctx.f12.u64 = f0.u64 ^ 0x8000000000000000;
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// b 0x82713438
	goto loc_82713438;
loc_8271342C:
	// bl 0x822a8148
	ctx.lr = 0x82713430;
	sub_822A8148(ctx, base);
	// lfs f12,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
loc_82713438:
	// lwz r11,216(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82713478
	if (cr6.eq) goto loc_82713478;
	// lfs f10,56(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f8,52(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fmuls f6,f9,f11
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmadds f5,f7,f12,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f28
	cr6.compare(ctx.f5.f64, f28.f64);
	// ble cr6,0x82713478
	if (!cr6.gt) goto loc_82713478;
	// lwz r14,208(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// mr r15,r11
	r15.u64 = r11.u64;
	// b 0x827134fc
	goto loc_827134FC;
loc_82713478:
	// lwz r10,208(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827134fc
	if (cr6.eq) goto loc_827134FC;
	// lfs f10,56(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f8,52(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fmuls f6,f9,f11
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fmadds f5,f7,f12,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f12.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f28
	cr6.compare(ctx.f5.f64, f28.f64);
	// ble cr6,0x827134fc
	if (!cr6.gt) goto loc_827134FC;
	// mr r15,r10
	r15.u64 = ctx.r10.u64;
	// mr r14,r11
	r14.u64 = r11.u64;
	// b 0x827134fc
	goto loc_827134FC;
loc_827134B0:
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8224a078
	ctx.lr = 0x827134BC;
	sub_8224A078(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x827134fc
	if (!cr6.eq) goto loc_827134FC;
	// lfs f0,324(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 324);
	f0.f64 = double(temp.f32);
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// fmuls f0,f0,f24
	f0.f64 = double(float(f0.f64 * f24.f64));
	// stfs f0,268(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8224a2b8
	ctx.lr = 0x827134E0;
	sub_8224A2B8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// bne cr6,0x827134fc
	if (!cr6.eq) goto loc_827134FC;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8224a078
	ctx.lr = 0x827134F8;
	sub_8224A078(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
loc_827134FC:
	// lfs f0,324(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 324);
	f0.f64 = double(temp.f32);
loc_82713500:
	// stw r28,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r28.u32);
	// mr r31,r28
	r31.u64 = r28.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x827137b0
	if (cr6.eq) goto loc_827137B0;
	// cmplwi cr6,r14,0
	cr6.compare<uint32_t>(r14.u32, 0, xer);
	// beq cr6,0x827135ac
	if (cr6.eq) goto loc_827135AC;
	// lwz r11,72(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// lwz r10,220(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 220);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x827135ac
	if (!cr6.eq) goto loc_827135AC;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82710b70
	ctx.lr = 0x8271354C;
	sub_82710B70(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827135a4
	if (!cr6.eq) goto loc_827135A4;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// stw r8,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r8.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82712c28
	ctx.lr = 0x82713594;
	sub_82712C28(ctx, base);
	// clrlwi r7,r23,24
	ctx.r7.u64 = r23.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r23,r6,27,31,31
	r23.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
loc_827135A4:
	// mr r14,r28
	r14.u64 = r28.u64;
	// b 0x82713640
	goto loc_82713640;
loc_827135AC:
	// cmplwi cr6,r15,0
	cr6.compare<uint32_t>(r15.u32, 0, xer);
	// beq cr6,0x82713640
	if (cr6.eq) goto loc_82713640;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82713640
	if (!cr6.eq) goto loc_82713640;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82710b70
	ctx.lr = 0x827135E4;
	sub_82710B70(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8271363c
	if (!cr6.eq) goto loc_8271363C;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r15
	ctx.r6.u64 = r15.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82712c28
	ctx.lr = 0x8271362C;
	sub_82712C28(ctx, base);
	// clrlwi r7,r23,24
	ctx.r7.u64 = r23.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r23,r6,27,31,31
	r23.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
loc_8271363C:
	// mr r15,r28
	r15.u64 = r28.u64;
loc_82713640:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827136c8
	if (!cr6.eq) goto loc_827136C8;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82710b70
	ctx.lr = 0x82713670;
	sub_82710B70(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827136c8
	if (!cr6.eq) goto loc_827136C8;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// vor128 v1,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)v127.u8));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stw r8,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// mr r9,r23
	ctx.r9.u64 = r23.u64;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82712c28
	ctx.lr = 0x827136B8;
	sub_82712C28(ctx, base);
	// clrlwi r7,r23,24
	ctx.r7.u64 = r23.u32 & 0xFF;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r23,r6,27,31,31
	r23.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
loc_827136C8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82713ae8
	if (cr6.eq) goto loc_82713AE8;
	// addi r11,r1,432
	r11.s64 = ctx.r1.s64 + 432;
	// stfs f20,436(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f20.f64);
	PPC_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// addi r6,r1,816
	ctx.r6.s64 = ctx.r1.s64 + 816;
	// stfs f28,440(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// stfs f28,432(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// addi r30,r1,496
	r30.s64 = ctx.r1.s64 + 496;
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// stfs f28,496(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r17
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,136(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// addi r9,r1,576
	ctx.r9.s64 = ctx.r1.s64 + 576;
	// stw r28,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, r28.u32);
	// addi r8,r1,608
	ctx.r8.s64 = ctx.r1.s64 + 608;
	// stfs f20,500(r1)
	temp.f32 = float(f20.f64);
	PPC_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// addi r7,r1,592
	ctx.r7.s64 = ctx.r1.s64 + 592;
	// stfs f28,504(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,832
	ctx.r10.s64 = ctx.r1.s64 + 832;
	// stw r10,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v54,v62,v57
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v57.f32)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r28,640(r1)
	PPC_STORE_U8(ctx.r1.u32 + 640, r28.u8);
	// lvx128 v56,r0,r30
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v55,v62,v56
	simde_mm_store_ps(v55.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v56.f32)));
	// stfs f28,628(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 628, temp.u32);
	// sth r28,642(r1)
	PPC_STORE_U16(ctx.r1.u32 + 642, r28.u16);
	// stw r28,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, r28.u32);
	// stvx128 v55,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r3,-23452(r16)
	ctx.r3.u64 = PPC_LOAD_U32(r16.u32 + -23452);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stfs f28,624(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 624, temp.u32);
	// li r7,2048
	ctx.r7.s64 = 2048;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r20,636(r1)
	PPC_STORE_U16(ctx.r1.u32 + 636, r20.u16);
	// addi r5,r1,560
	ctx.r5.s64 = ctx.r1.s64 + 560;
	// sth r28,638(r1)
	PPC_STORE_U16(ctx.r1.u32 + 638, r28.u16);
	// addi r4,r1,816
	ctx.r4.s64 = ctx.r1.s64 + 816;
	// stvx128 v54,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x82713790;
	sub_82574418(ctx, base);
	// lwz r10,560(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 560);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82713ae0
	if (cr6.eq) goto loc_82713AE0;
	// addi r11,r1,576
	r11.s64 = ctx.r1.s64 + 576;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82713ae4
	goto loc_82713AE4;
loc_827137B0:
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// fmuls f0,f0,f24
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f24.f64));
	// lwz r11,4(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// mulld r10,r8,r19
	ctx.r10.s64 = ctx.r8.s64 * r19.s64;
	// lwz r7,212(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 212);
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvlx128 v53,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v52,v53,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v53.u32), 0xFF));
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// li r6,32
	ctx.r6.s64 = 32;
	// clrlwi r5,r11,1
	ctx.r5.u64 = r11.u32 & 0x7FFFFFFF;
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// srawi r3,r5,3
	xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 3;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addze r9,r3
	temp.s64 = ctx.r3.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r9.s64 = temp.s64;
	// lvx128 v51,r7,r6
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v50,v51,v52
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v50.f32, simde_mm_mul_ps(simde_mm_load_ps(v51.f32), simde_mm_load_ps(v52.f32)));
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rlwinm r8,r9,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r10,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r10.u32);
	// stw r11,4(r27)
	PPC_STORE_U32(r27.u32 + 4, r11.u32);
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// subf r7,r8,r5
	ctx.r7.s64 = ctx.r5.s64 - ctx.r8.s64;
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,408(r1)
	PPC_STORE_U64(ctx.r1.u32 + 408, ctx.r6.u64);
	// stvx128 v50,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f12,408(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 408);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f1,f10,f18
	ctx.f1.f64 = double(float(ctx.f10.f64 * f18.f64));
	// bl 0x8216c890
	ctx.lr = 0x82713834;
	sub_8216C890(ctx, base);
	// lfs f30,456(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 456);
	f30.f64 = double(temp.f32);
	// mr r30,r28
	r30.u64 = r28.u64;
	// lfs f29,448(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 448);
	f29.f64 = double(temp.f32);
loc_82713840:
	// addi r11,r1,464
	r11.s64 = ctx.r1.s64 + 464;
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// lvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v47,v49,v48
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v47.f32, simde_mm_add_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v48.f32)));
	// stvx128 v47,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8270e600
	ctx.lr = 0x82713868;
	sub_8270E600(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82713aac
	if (cr6.eq) goto loc_82713AAC;
	// lwz r11,180(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// addi r7,r1,288
	ctx.r7.s64 = ctx.r1.s64 + 288;
	// stfs f28,388(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// addi r8,r1,384
	ctx.r8.s64 = ctx.r1.s64 + 384;
	// stfs f25,384(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f28,392(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// lvx128 v46,r0,r11
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v45,v63,v46
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v45.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v46.f32)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,292(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 292);
	f0.f64 = double(temp.f32);
	// fadds f31,f0,f26
	f31.f64 = double(float(f0.f64 + f26.f64));
	// stfs f31,292(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// bl 0x82165300
	ctx.lr = 0x827138C4;
	sub_82165300(ctx, base);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// addi r5,r1,528
	ctx.r5.s64 = ctx.r1.s64 + 528;
	// lvx128 v44,r0,r6
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,528
	ctx.r3.s64 = ctx.r1.s64 + 528;
	// fmr f1,f22
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f22.f64;
	// stvx128 v44,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8216c890
	ctx.lr = 0x827138E0;
	sub_8216C890(ctx, base);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// fmuls f10,f29,f24
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(f29.f64 * f24.f64));
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lfs f9,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f9.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// fsubs f8,f31,f9
	ctx.f8.f64 = double(float(f31.f64 - ctx.f9.f64));
	// lfs f12,296(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 296);
	ctx.f12.f64 = double(temp.f32);
	// lfs f7,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f7.f64 = double(temp.f32);
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// lvlx128 v42,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// lfs f11,288(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r1,528
	ctx.r10.s64 = ctx.r1.s64 + 528;
	// lfs f5,160(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f5.f64 = double(temp.f32);
	// fmuls f13,f30,f24
	ctx.f13.f64 = double(float(f30.f64 * f24.f64));
	// fsubs f4,f11,f5
	ctx.f4.f64 = double(float(ctx.f11.f64 - ctx.f5.f64));
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvlx128 v43,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v40,v43,0
	simde_mm_store_si128((simde__m128i*)v40.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// fmuls f3,f8,f8
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// vspltw128 v41,v42,0
	simde_mm_store_si128((simde__m128i*)v41.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v42.u32), 0xFF));
	// lvx128 v39,r0,r11
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v38,r0,r10
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v125,v39,v40
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v125.f32, simde_mm_mul_ps(simde_mm_load_ps(v39.f32), simde_mm_load_ps(v40.f32)));
	// vmulfp128 v127,v38,v41
	simde_mm_store_ps(v127.f32, simde_mm_mul_ps(simde_mm_load_ps(v38.f32), simde_mm_load_ps(v41.f32)));
	// fmadds f2,f6,f6,f3
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f2.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f3.f64));
	// fmadds f1,f4,f4,f2
	ctx.f1.f64 = double(float(ctx.f4.f64 * ctx.f4.f64 + ctx.f2.f64));
	// fcmpu cr6,f1,f27
	cr6.compare(ctx.f1.f64, f27.f64);
	// bge cr6,0x82713aac
	if (!cr6.lt) goto loc_82713AAC;
	// vaddfp128 v37,v125,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v37.f32, simde_mm_add_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v127.f32)));
	// addi r11,r1,288
	r11.s64 = ctx.r1.s64 + 288;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lwz r3,-10016(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10016);
	// lvx128 v126,r0,r11
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v126,v37
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v37.f32)));
	// bl 0x82700578
	ctx.lr = 0x82713974;
	sub_82700578(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82713aac
	if (!cr6.eq) goto loc_82713AAC;
	// vspltisw128 v36,0
	simde_mm_store_si128((simde__m128i*)v36.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lwz r3,-10016(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10016);
	// vsubfp128 v124,v36,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v124.f32, simde_mm_sub_ps(simde_mm_load_ps(v36.f32), simde_mm_load_ps(v125.f32)));
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v35,v124,v127
	simde_mm_store_ps(v35.f32, simde_mm_add_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v127.f32)));
	// vaddfp128 v2,v126,v35
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v35.f32)));
	// bl 0x82700578
	ctx.lr = 0x827139A0;
	sub_82700578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82713aac
	if (!cr6.eq) goto loc_82713AAC;
	// vsubfp128 v34,v125,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v34.f32, simde_mm_sub_ps(simde_mm_load_ps(v125.f32), simde_mm_load_ps(v127.f32)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lwz r3,-10016(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10016);
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v126,v34
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v34.f32)));
	// bl 0x82700578
	ctx.lr = 0x827139C4;
	sub_82700578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82713aac
	if (!cr6.eq) goto loc_82713AAC;
	// vsubfp128 v33,v124,v127
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v33.f32, simde_mm_sub_ps(simde_mm_load_ps(v124.f32), simde_mm_load_ps(v127.f32)));
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// lwz r3,-10016(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10016);
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v2,v126,v33
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_load_ps(v126.f32), simde_mm_load_ps(v33.f32)));
	// bl 0x82700578
	ctx.lr = 0x827139E8;
	sub_82700578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82713aac
	if (!cr6.eq) goto loc_82713AAC;
	// addi r11,r1,480
	r11.s64 = ctx.r1.s64 + 480;
	// stfs f28,480(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// stfs f20,484(r1)
	temp.f32 = float(f20.f64);
	PPC_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// addi r9,r1,512
	ctx.r9.s64 = ctx.r1.s64 + 512;
	// stfs f28,488(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f20,516(r1)
	temp.f32 = float(f20.f64);
	PPC_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// addi r8,r1,672
	ctx.r8.s64 = ctx.r1.s64 + 672;
	// stfs f28,512(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// stfs f28,520(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// addi r7,r1,688
	ctx.r7.s64 = ctx.r1.s64 + 688;
	// addi r6,r1,704
	ctx.r6.s64 = ctx.r1.s64 + 704;
	// lvx128 v63,r0,r17
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r17.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r28,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r28.u32);
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,848
	ctx.r4.s64 = ctx.r1.s64 + 848;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,1
	ctx.r10.s64 = 1;
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r20,732(r1)
	PPC_STORE_U16(ctx.r1.u32 + 732, r20.u16);
	// stfs f28,724(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 724, temp.u32);
	// stw r28,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, r28.u32);
	// stfs f28,720(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 720, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// sth r28,734(r1)
	PPC_STORE_U16(ctx.r1.u32 + 734, r28.u16);
	// addi r5,r1,656
	ctx.r5.s64 = ctx.r1.s64 + 656;
	// stb r28,736(r1)
	PPC_STORE_U8(ctx.r1.u32 + 736, r28.u8);
	// sth r28,738(r1)
	PPC_STORE_U16(ctx.r1.u32 + 738, r28.u16);
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v32,r0,r9
	simde_mm_store_si128((simde__m128i*)v32.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v62,v32
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v32.f32)));
	// stvx128 v61,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v62,v60
	simde_mm_store_ps(v59.f32, simde_mm_add_ps(simde_mm_load_ps(v62.f32), simde_mm_load_ps(v60.f32)));
	// li r9,4
	ctx.r9.s64 = 4;
	// lwz r3,-23452(r16)
	ctx.r3.u64 = PPC_LOAD_U32(r16.u32 + -23452);
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,848
	ctx.r4.s64 = ctx.r1.s64 + 848;
	// bl 0x82574418
	ctx.lr = 0x82713AA0;
	sub_82574418(ctx, base);
	// lwz r11,656(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 656);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82713ac8
	if (!cr6.eq) goto loc_82713AC8;
loc_82713AAC:
	// addi r3,r1,464
	ctx.r3.s64 = ctx.r1.s64 + 464;
	// fmr f1,f18
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f18.f64;
	// bl 0x8216c890
	ctx.lr = 0x82713AB8;
	sub_8216C890(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,8
	cr6.compare<int32_t>(r30.s32, 8, xer);
	// blt cr6,0x82713840
	if (cr6.lt) goto loc_82713840;
	// b 0x82713ae4
	goto loc_82713AE4;
loc_82713AC8:
	// addi r11,r1,672
	r11.s64 = ctx.r1.s64 + 672;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// li r31,1
	r31.s64 = 1;
	// lvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82713ae4
	goto loc_82713AE4;
loc_82713AE0:
	// mr r31,r28
	r31.u64 = r28.u64;
loc_82713AE4:
	// lwz r30,132(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
loc_82713AE8:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82713f50
	if (cr6.eq) goto loc_82713F50;
	// lfs f0,196(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 196);
	f0.f64 = double(temp.f32);
	// lwz r10,176(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// fadds f13,f0,f15
	ctx.f13.f64 = double(float(f0.f64 + f15.f64));
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82713dac
	if (cr6.eq) goto loc_82713DAC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,32(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// lis r9,6
	ctx.r9.s64 = 393216;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// ori r8,r9,16712
	ctx.r8.u64 = ctx.r9.u64 | 16712;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// lwzx r7,r11,r8
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + ctx.r8.u32);
	// lwz r11,60(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 60);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82713dac
	if (cr6.eq) goto loc_82713DAC;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,0(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713dac
	if (cr6.eq) goto loc_82713DAC;
	// li r10,80
	ctx.r10.s64 = 80;
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// addi r4,r1,544
	ctx.r4.s64 = ctx.r1.s64 + 544;
	// addi r3,r9,-1
	ctx.r3.s64 = ctx.r9.s64 + -1;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,1
	ctx.r7.s64 = 1;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// lvx128 v52,r0,r5
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,328(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 328);
	f0.f64 = double(temp.f32);
	// lfs f13,324(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	ctx.f13.f64 = double(temp.f32);
	// fneg f11,f13
	ctx.f11.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// lfs f8,320(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,552(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 552);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f9,f13,f0
	ctx.f9.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f12,544(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 544);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f11,f11
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fsubs f7,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f8.f64));
	// fmadds f6,f9,f9,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f10.f64));
	// fmadds f0,f7,f7,f6
	f0.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f6.f64));
	// blt cr6,0x82713cdc
	if (cr6.lt) goto loc_82713CDC;
	// addi r11,r9,-5
	r11.s64 = ctx.r9.s64 + -5;
	// addi r10,r6,12
	ctx.r10.s64 = ctx.r6.s64 + 12;
	// rlwinm r11,r11,30,2,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
loc_82713BC0:
	// lwz r11,-8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713c04
	if (cr6.eq) goto loc_82713C04;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lfs f11,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f11,f6,f6,f4
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bge cr6,0x82713c04
	if (!cr6.lt) goto loc_82713C04;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
loc_82713C04:
	// lwz r11,-4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713c48
	if (cr6.eq) goto loc_82713C48;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lfs f11,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f11,f6,f6,f4
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bge cr6,0x82713c48
	if (!cr6.lt) goto loc_82713C48;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
loc_82713C48:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713c8c
	if (cr6.eq) goto loc_82713C8C;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lfs f11,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f11,f6,f6,f4
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bge cr6,0x82713c8c
	if (!cr6.lt) goto loc_82713C8C;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
loc_82713C8C:
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713cd0
	if (cr6.eq) goto loc_82713CD0;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lfs f11,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f11,f6,f6,f4
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bge cr6,0x82713cd0
	if (!cr6.lt) goto loc_82713CD0;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
loc_82713CD0:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// bne 0x82713bc0
	if (!cr0.eq) goto loc_82713BC0;
loc_82713CDC:
	// cmpw cr6,r7,r9
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, xer);
	// bge cr6,0x82713d40
	if (!cr6.lt) goto loc_82713D40;
	// rlwinm r11,r7,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// add r10,r11,r6
	ctx.r10.u64 = r11.u64 + ctx.r6.u64;
loc_82713CF0:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82713d34
	if (cr6.eq) goto loc_82713D34;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// lfs f11,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// fneg f10,f11
	ctx.f10.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f12,f7
	ctx.f6.f64 = double(float(ctx.f12.f64 - ctx.f7.f64));
	// fmuls f5,f10,f10
	ctx.f5.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f4,f8,f8,f5
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f5.f64));
	// fmadds f11,f6,f6,f4
	ctx.f11.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f4.f64));
	// fcmpu cr6,f11,f0
	cr6.compare(ctx.f11.f64, f0.f64);
	// bge cr6,0x82713d34
	if (!cr6.lt) goto loc_82713D34;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f0,f11
	f0.f64 = ctx.f11.f64;
loc_82713D34:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82713cf0
	if (!cr0.eq) goto loc_82713CF0;
loc_82713D40:
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// lfs f12,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,416
	ctx.r8.s64 = ctx.r1.s64 + 416;
	// lvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f28,308(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// lvx128 v50,r0,r9
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v49,v63,v50
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v49.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v50.f32)));
	// stvx128 v49,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,424(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 424);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f9,420(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 420);
	ctx.f9.f64 = double(temp.f32);
	// lfs f7,416(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 416);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f8,f9,f13,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f12,f7,f8
	ctx.f6.f64 = double(float(ctx.f12.f64 * ctx.f7.f64 + ctx.f8.f64));
	// fcmpu cr6,f6,f28
	cr6.compare(ctx.f6.f64, f28.f64);
	// ble cr6,0x82713dac
	if (!cr6.gt) goto loc_82713DAC;
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// vspltisw128 v48,0
	simde_mm_store_si128((simde__m128i*)v48.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lvx128 v47,r0,r11
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v46,v48,v47
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v46.f32, simde_mm_sub_ps(simde_mm_load_ps(v48.f32), simde_mm_load_ps(v47.f32)));
	// stvx128 v46,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82713DAC:
	// lwz r3,32(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// fmr f31,f28
	ctx.fpscr.disableFlushMode();
	f31.f64 = f28.f64;
	// bl 0x822a8148
	ctx.lr = 0x82713DB8;
	sub_822A8148(ctx, base);
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	f0.f64 = double(temp.f32);
	// lfs f11,8(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f13,148(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f13.f64 = double(temp.f32);
	// lfs f9,4(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// lfs f12,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f12.f64 = double(temp.f32);
	// lfs f8,0(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f7,f9,f13,f10
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f10.f64));
	// fmadds f6,f8,f12,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f12.f64 + ctx.f7.f64));
	// fcmpu cr6,f6,f28
	cr6.compare(ctx.f6.f64, f28.f64);
	// ble cr6,0x82713de8
	if (!cr6.gt) goto loc_82713DE8;
	// fmr f31,f14
	f31.f64 = f14.f64;
loc_82713DE8:
	// stfs f25,336(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// stfs f28,344(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// addi r10,r1,800
	ctx.r10.s64 = ctx.r1.s64 + 800;
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// stfs f28,340(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// lvx128 v45,r0,r11
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r9
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82165300
	ctx.lr = 0x82713E18;
	sub_82165300(ctx, base);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r5,236(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 236);
	// addi r3,r1,752
	ctx.r3.s64 = ctx.r1.s64 + 752;
	// bl 0x82202ec0
	ctx.lr = 0x82713E28;
	sub_82202EC0(ctx, base);
	// lwz r8,76(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r7,r26,r8
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + ctx.r8.u32);
	// lwz r3,48(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82713E44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,76(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r3,r26,r4
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + ctx.r4.u32);
	// bl 0x8270c270
	ctx.lr = 0x82713E50;
	sub_8270C270(ctx, base);
	// lwz r3,76(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r3,r26,r3
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + ctx.r3.u32);
	// lbz r11,880(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 880);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82713e6c
	if (cr6.eq) goto loc_82713E6C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8270c408
	ctx.lr = 0x82713E6C;
	sub_8270C408(ctx, base);
loc_82713E6C:
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,224(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// addi r4,r1,752
	ctx.r4.s64 = ctx.r1.s64 + 752;
	// fmr f2,f17
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f17.f64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// fmr f1,f25
	ctx.f1.f64 = f25.f64;
	// lwzx r3,r26,r11
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// bl 0x822a9930
	ctx.lr = 0x82713E90;
	sub_822A9930(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82710598
	ctx.lr = 0x82713E98;
	sub_82710598(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82713ee4
	if (cr6.eq) goto loc_82713EE4;
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r3,r26,r11
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// bl 0x8270c340
	ctx.lr = 0x82713EB0;
	sub_8270C340(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82713ee4
	if (!cr6.eq) goto loc_82713EE4;
	// addi r3,r1,880
	ctx.r3.s64 = ctx.r1.s64 + 880;
	// bl 0x82714588
	ctx.lr = 0x82713EC4;
	sub_82714588(ctx, base);
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r3,r26,r11
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// bl 0x8270c2d8
	ctx.lr = 0x82713ED0;
	sub_8270C2D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,880
	ctx.r3.s64 = ctx.r1.s64 + 880;
	// bl 0x82714080
	ctx.lr = 0x82713EDC;
	sub_82714080(ctx, base);
	// addi r3,r1,880
	ctx.r3.s64 = ctx.r1.s64 + 880;
	// bl 0x82714070
	ctx.lr = 0x82713EE4;
	sub_82714070(ctx, base);
loc_82713EE4:
	// fcmpu cr6,f31,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f28.f64);
	// beq cr6,0x82713f20
	if (cr6.eq) goto loc_82713F20;
	// fneg f0,f31
	f0.u64 = f31.u64 ^ 0x8000000000000000;
	// stfs f0,136(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r11,r1,136
	r11.s64 = ctx.r1.s64 + 136;
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v44,r0,r9
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v43,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v42,v43,0
	simde_mm_store_si128((simde__m128i*)v42.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v43.u32), 0xFF));
	// vmulfp128 v1,v44,v42
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(v44.f32), simde_mm_load_ps(v42.f32)));
	// stvx128 v1,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwzx r3,r26,r10
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + ctx.r10.u32);
	// bl 0x8270c858
	ctx.lr = 0x82713F20;
	sub_8270C858(ctx, base);
loc_82713F20:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8270ea18
	ctx.lr = 0x82713F28;
	sub_8270EA18(ctx, base);
	// addi r11,r1,368
	r11.s64 = ctx.r1.s64 + 368;
	// stfs f28,372(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// lwz r10,180(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// stfs f28,376(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// stfs f28,368(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// lfs f1,232(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v1,r0,r10
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8270f428
	ctx.lr = 0x82713F50;
	sub_8270F428(ctx, base);
loc_82713F50:
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f21,f0
	cr6.compare(f21.f64, f0.f64);
	// ble cr6,0x82713f68
	if (!cr6.gt) goto loc_82713F68;
	// lwz r11,76(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// lwzx r10,r26,r11
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + r11.u32);
	// stfs f28,1132(r10)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r10.u32 + 1132, temp.u32);
loc_82713F68:
	// lwz r11,140(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// lwz r10,72(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r11.u32);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x82713178
	if (cr6.lt) goto loc_82713178;
loc_82713F80:
	// lhz r10,190(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 190);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82713f94
	if (cr6.eq) goto loc_82713F94;
	// lwz r3,184(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// bl 0x82130588
	ctx.lr = 0x82713F94;
	sub_82130588(ctx, base);
loc_82713F94:
	// addi r1,r1,1296
	ctx.r1.s64 = ctx.r1.s64 + 1296;
	// addi r12,r1,-304
	r12.s64 = ctx.r1.s64 + -304;
	// bl 0x823dd7cc
	ctx.lr = 0x82713FA0;
	// addi r12,r1,-152
	r12.s64 = ctx.r1.s64 + -152;
	// bl 0x823db9ec
	ctx.lr = 0x82713FA8;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82713FAC"))) PPC_WEAK_FUNC(sub_82713FAC);
PPC_FUNC_IMPL(__imp__sub_82713FAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82713FB0"))) PPC_WEAK_FUNC(sub_82713FB0);
PPC_FUNC_IMPL(__imp__sub_82713FB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// stb r11,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, r11.u8);
	// stb r11,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82713FE4"))) PPC_WEAK_FUNC(sub_82713FE4);
PPC_FUNC_IMPL(__imp__sub_82713FE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82713FE8"))) PPC_WEAK_FUNC(sub_82713FE8);
PPC_FUNC_IMPL(__imp__sub_82713FE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,1
	r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// stb r11,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, r11.u8);
	// stb r11,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714020"))) PPC_WEAK_FUNC(sub_82714020);
PPC_FUNC_IMPL(__imp__sub_82714020) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// lfs f13,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// lfs f0,11412(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11412);
	f0.f64 = double(temp.f32);
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stfs f13,16(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stb r11,13(r3)
	PPC_STORE_U8(ctx.r3.u32 + 13, r11.u8);
	// stb r11,14(r3)
	PPC_STORE_U8(ctx.r3.u32 + 14, r11.u8);
	// stb r11,15(r3)
	PPC_STORE_U8(ctx.r3.u32 + 15, r11.u8);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stw r10,48(r3)
	PPC_STORE_U32(ctx.r3.u32 + 48, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8271406C"))) PPC_WEAK_FUNC(sub_8271406C);
PPC_FUNC_IMPL(__imp__sub_8271406C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82714070"))) PPC_WEAK_FUNC(sub_82714070);
PPC_FUNC_IMPL(__imp__sub_82714070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r10,r11,30132
	ctx.r10.s64 = r11.s64 + 30132;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714080"))) PPC_WEAK_FUNC(sub_82714080);
PPC_FUNC_IMPL(__imp__sub_82714080) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827140d4
	if (cr6.eq) goto loc_827140D4;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_827140AC:
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x827140ac
	if (!cr6.eq) goto loc_827140AC;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827140d4
	if (cr6.eq) goto loc_827140D4;
	// li r9,1
	ctx.r9.s64 = 1;
loc_827140D4:
	// clrlwi r8,r9,24
	ctx.r8.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82714138
	if (cr6.eq) goto loc_82714138;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r6,23772
	ctx.r6.s64 = 1557921792;
	// addi r4,r7,2176
	ctx.r4.s64 = ctx.r7.s64 + 2176;
	// ori r3,r6,64167
	ctx.r3.u64 = ctx.r6.u64 | 64167;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r6,2176(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 2176);
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// mulld r10,r6,r3
	ctx.r10.s64 = ctx.r6.s64 * ctx.r3.s64;
	// lfs f0,14348(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2176(r7)
	PPC_STORE_U32(ctx.r7.u32 + 2176, r11.u32);
	// clrlwi r11,r11,9
	r11.u64 = r11.u32 & 0x7FFFFF;
	// stw r9,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r9.u32);
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// blt cr6,0x827141ec
	if (cr6.lt) goto loc_827141EC;
loc_82714138:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82714154
	if (cr6.eq) goto loc_82714154;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,30324
	ctx.r4.s64 = r11.s64 + 30324;
	// b 0x827141f8
	goto loc_827141F8;
loc_82714154:
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8271416c
	if (cr6.eq) goto loc_8271416C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,30300
	ctx.r4.s64 = r11.s64 + 30300;
	// b 0x827141f8
	goto loc_827141F8;
loc_8271416C:
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82714184
	if (cr6.eq) goto loc_82714184;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,30268
	ctx.r4.s64 = r11.s64 + 30268;
	// b 0x827141f8
	goto loc_827141F8;
loc_82714184:
	// rlwinm r10,r11,0,22,22
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8271419c
	if (cr6.eq) goto loc_8271419C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,30240
	ctx.r4.s64 = r11.s64 + 30240;
	// b 0x827141f8
	goto loc_827141F8;
loc_8271419C:
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827141b4
	if (cr6.eq) goto loc_827141B4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,30204
	ctx.r4.s64 = r11.s64 + 30204;
	// b 0x827141f8
	goto loc_827141F8;
loc_827141B4:
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x827141cc
	if (cr6.eq) goto loc_827141CC;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,30168
	ctx.r4.s64 = r11.s64 + 30168;
	// b 0x827141f8
	goto loc_827141F8;
loc_827141CC:
	// clrlwi r11,r11,29
	r11.u64 = r11.u32 & 0x7;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827141e4
	if (cr6.eq) goto loc_827141E4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,30140
	ctx.r4.s64 = r11.s64 + 30140;
	// b 0x827141f8
	goto loc_827141F8;
loc_827141E4:
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82714288
	if (cr6.eq) goto loc_82714288;
loc_827141EC:
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82714288
	if (cr6.eq) goto loc_82714288;
loc_827141F8:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r9,r9,21124
	ctx.r9.s64 = ctx.r9.s64 + 21124;
	// addi r10,r10,20572
	ctx.r10.s64 = ctx.r10.s64 + 20572;
	// bne cr6,0x8271421c
	if (!cr6.eq) goto loc_8271421C;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// b 0x8271422c
	goto loc_8271422C;
loc_8271421C:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// beq cr6,0x8271422c
	if (cr6.eq) goto loc_8271422C;
	// lwz r6,24(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 24);
loc_8271422C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82714240
	if (!cr6.eq) goto loc_82714240;
	// mr r5,r10
	ctx.r5.u64 = ctx.r10.u64;
	// b 0x8271424c
	goto loc_8271424C;
loc_82714240:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8271424c
	if (!cr6.eq) goto loc_8271424C;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
loc_8271424C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lbz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 40);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r3,-24400(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// bl 0x821f32d0
	ctx.lr = 0x82714264;
	sub_821F32D0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82714288
	if (cr6.eq) goto loc_82714288;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82714288
	if (cr6.eq) goto loc_82714288;
	// lwz r5,36(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// bl 0x826c27f8
	ctx.lr = 0x82714288;
	sub_826C27F8(ctx, base);
loc_82714288:
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

__attribute__((alias("__imp__sub_827142A0"))) PPC_WEAK_FUNC(sub_827142A0);
PPC_FUNC_IMPL(__imp__sub_827142A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r11,-24400(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -24400);
	// lbz r3,269(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 269);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827142B0"))) PPC_WEAK_FUNC(sub_827142B0);
PPC_FUNC_IMPL(__imp__sub_827142B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r11,-24400(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -24400);
	// lwz r9,2252(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2252);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x821f1498
	sub_821F1498(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827142DC"))) PPC_WEAK_FUNC(sub_827142DC);
PPC_FUNC_IMPL(__imp__sub_827142DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827142E0"))) PPC_WEAK_FUNC(sub_827142E0);
PPC_FUNC_IMPL(__imp__sub_827142E0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32122
	ctx.r9.s64 = -2105147392;
	// lis r8,23772
	ctx.r8.s64 = 1557921792;
	// addi r7,r9,2176
	ctx.r7.s64 = ctx.r9.s64 + 2176;
	// ori r6,r8,64167
	ctx.r6.u64 = ctx.r8.u64 | 64167;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r31,2176(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r10,r31,r6
	ctx.r10.s64 = r31.s64 * ctx.r6.s64;
	// lfs f0,14348(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14348);
	f0.f64 = double(temp.f32);
	// lfs f13,-29232(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// clrlwi r5,r11,9
	ctx.r5.u64 = r11.u32 & 0x7FFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
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
	// fmuls f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 * f0.f64));
	// fcmpu cr6,f9,f13
	cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bge cr6,0x8271435c
	if (!cr6.lt) goto loc_8271435C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
loc_8271435C:
	// bl 0x82714080
	ctx.lr = 0x82714360;
	sub_82714080(ctx, base);
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

__attribute__((alias("__imp__sub_82714374"))) PPC_WEAK_FUNC(sub_82714374);
PPC_FUNC_IMPL(__imp__sub_82714374) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82714378"))) PPC_WEAK_FUNC(sub_82714378);
PPC_FUNC_IMPL(__imp__sub_82714378) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,31308(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// addi r6,r9,30132
	ctx.r6.s64 = ctx.r9.s64 + 30132;
	// addi r5,r8,30348
	ctx.r5.s64 = ctx.r8.s64 + 30348;
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// li r4,2
	ctx.r4.s64 = 2;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r10,r7,3998
	ctx.r10.s64 = ctx.r7.s64 + 3998;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r4,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r4.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r10,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r10.u32);
	// stw r10,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827143D0"))) PPC_WEAK_FUNC(sub_827143D0);
PPC_FUNC_IMPL(__imp__sub_827143D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30404
	ctx.r4.s64 = ctx.r8.s64 + 30404;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30376
	ctx.r10.s64 = ctx.r7.s64 + 30376;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714428"))) PPC_WEAK_FUNC(sub_82714428);
PPC_FUNC_IMPL(__imp__sub_82714428) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// lfs f0,31308(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31308);
	f0.f64 = double(temp.f32);
	// addi r5,r9,3998
	ctx.r5.s64 = ctx.r9.s64 + 3998;
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// addi r4,r8,30444
	ctx.r4.s64 = ctx.r8.s64 + 30444;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r10,r7,30412
	ctx.r10.s64 = ctx.r7.s64 + 30412;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714480"))) PPC_WEAK_FUNC(sub_82714480);
PPC_FUNC_IMPL(__imp__sub_82714480) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30484
	ctx.r4.s64 = ctx.r8.s64 + 30484;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30452
	ctx.r10.s64 = ctx.r7.s64 + 30452;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827144D8"))) PPC_WEAK_FUNC(sub_827144D8);
PPC_FUNC_IMPL(__imp__sub_827144D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30496
	ctx.r4.s64 = ctx.r8.s64 + 30496;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30324
	ctx.r10.s64 = ctx.r7.s64 + 30324;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714530"))) PPC_WEAK_FUNC(sub_82714530);
PPC_FUNC_IMPL(__imp__sub_82714530) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30536
	ctx.r4.s64 = ctx.r8.s64 + 30536;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30504
	ctx.r10.s64 = ctx.r7.s64 + 30504;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714588"))) PPC_WEAK_FUNC(sub_82714588);
PPC_FUNC_IMPL(__imp__sub_82714588) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30568
	ctx.r4.s64 = ctx.r8.s64 + 30568;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30544
	ctx.r10.s64 = ctx.r7.s64 + 30544;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827145E0"))) PPC_WEAK_FUNC(sub_827145E0);
PPC_FUNC_IMPL(__imp__sub_827145E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30600
	ctx.r4.s64 = ctx.r8.s64 + 30600;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30576
	ctx.r10.s64 = ctx.r7.s64 + 30576;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714638"))) PPC_WEAK_FUNC(sub_82714638);
PPC_FUNC_IMPL(__imp__sub_82714638) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30636
	ctx.r4.s64 = ctx.r8.s64 + 30636;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30608
	ctx.r10.s64 = ctx.r7.s64 + 30608;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714690"))) PPC_WEAK_FUNC(sub_82714690);
PPC_FUNC_IMPL(__imp__sub_82714690) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30676
	ctx.r4.s64 = ctx.r8.s64 + 30676;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30644
	ctx.r10.s64 = ctx.r7.s64 + 30644;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827146E8"))) PPC_WEAK_FUNC(sub_827146E8);
PPC_FUNC_IMPL(__imp__sub_827146E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30708
	ctx.r4.s64 = ctx.r8.s64 + 30708;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30684
	ctx.r10.s64 = ctx.r7.s64 + 30684;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714740"))) PPC_WEAK_FUNC(sub_82714740);
PPC_FUNC_IMPL(__imp__sub_82714740) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30748
	ctx.r4.s64 = ctx.r8.s64 + 30748;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30716
	ctx.r10.s64 = ctx.r7.s64 + 30716;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714798"))) PPC_WEAK_FUNC(sub_82714798);
PPC_FUNC_IMPL(__imp__sub_82714798) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30784
	ctx.r4.s64 = ctx.r8.s64 + 30784;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30756
	ctx.r10.s64 = ctx.r7.s64 + 30756;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827147F0"))) PPC_WEAK_FUNC(sub_827147F0);
PPC_FUNC_IMPL(__imp__sub_827147F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30824
	ctx.r4.s64 = ctx.r8.s64 + 30824;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30792
	ctx.r10.s64 = ctx.r7.s64 + 30792;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714848"))) PPC_WEAK_FUNC(sub_82714848);
PPC_FUNC_IMPL(__imp__sub_82714848) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30860
	ctx.r4.s64 = ctx.r8.s64 + 30860;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30832
	ctx.r10.s64 = ctx.r7.s64 + 30832;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827148A0"))) PPC_WEAK_FUNC(sub_827148A0);
PPC_FUNC_IMPL(__imp__sub_827148A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30896
	ctx.r4.s64 = ctx.r8.s64 + 30896;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30868
	ctx.r10.s64 = ctx.r7.s64 + 30868;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827148F8"))) PPC_WEAK_FUNC(sub_827148F8);
PPC_FUNC_IMPL(__imp__sub_827148F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30932
	ctx.r4.s64 = ctx.r8.s64 + 30932;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30904
	ctx.r10.s64 = ctx.r7.s64 + 30904;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714950"))) PPC_WEAK_FUNC(sub_82714950);
PPC_FUNC_IMPL(__imp__sub_82714950) {
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
	// lis r11,-32244
	r11.s64 = -2113142784;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,30132
	ctx.r9.s64 = r11.s64 + 30132;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82714984
	if (cr6.eq) goto loc_82714984;
	// bl 0x82130588
	ctx.lr = 0x82714980;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82714984:
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

__attribute__((alias("__imp__sub_82714998"))) PPC_WEAK_FUNC(sub_82714998);
PPC_FUNC_IMPL(__imp__sub_82714998) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,30968
	ctx.r4.s64 = ctx.r8.s64 + 30968;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,30940
	ctx.r10.s64 = ctx.r7.s64 + 30940;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827149F0"))) PPC_WEAK_FUNC(sub_827149F0);
PPC_FUNC_IMPL(__imp__sub_827149F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r5,r9,3998
	ctx.r5.s64 = ctx.r9.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r7,31012
	ctx.r4.s64 = ctx.r7.s64 + 31012;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r9,r6,30976
	ctx.r9.s64 = ctx.r6.s64 + 30976;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714A48"))) PPC_WEAK_FUNC(sub_82714A48);
PPC_FUNC_IMPL(__imp__sub_82714A48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r5,r9,3998
	ctx.r5.s64 = ctx.r9.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r7,31060
	ctx.r4.s64 = ctx.r7.s64 + 31060;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r9,r6,31020
	ctx.r9.s64 = ctx.r6.s64 + 31020;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714AA0"))) PPC_WEAK_FUNC(sub_82714AA0);
PPC_FUNC_IMPL(__imp__sub_82714AA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r5,r9,3998
	ctx.r5.s64 = ctx.r9.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r7,31100
	ctx.r4.s64 = ctx.r7.s64 + 31100;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r9,r6,31068
	ctx.r9.s64 = ctx.r6.s64 + 31068;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714AF8"))) PPC_WEAK_FUNC(sub_82714AF8);
PPC_FUNC_IMPL(__imp__sub_82714AF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,31136
	ctx.r4.s64 = ctx.r8.s64 + 31136;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,31108
	ctx.r10.s64 = ctx.r7.s64 + 31108;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714B50"))) PPC_WEAK_FUNC(sub_82714B50);
PPC_FUNC_IMPL(__imp__sub_82714B50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,31168
	ctx.r4.s64 = ctx.r8.s64 + 31168;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,31144
	ctx.r10.s64 = ctx.r7.s64 + 31144;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714BA8"))) PPC_WEAK_FUNC(sub_82714BA8);
PPC_FUNC_IMPL(__imp__sub_82714BA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r10,3998
	ctx.r6.s64 = ctx.r10.s64 + 3998;
	// addi r5,r8,31220
	ctx.r5.s64 = ctx.r8.s64 + 31220;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r7,31176
	ctx.r4.s64 = ctx.r7.s64 + 31176;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r6,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r6.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r6,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r6.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// stw r4,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714C00"))) PPC_WEAK_FUNC(sub_82714C00);
PPC_FUNC_IMPL(__imp__sub_82714C00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,31252
	ctx.r4.s64 = ctx.r8.s64 + 31252;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,31228
	ctx.r10.s64 = ctx.r7.s64 + 31228;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714C58"))) PPC_WEAK_FUNC(sub_82714C58);
PPC_FUNC_IMPL(__imp__sub_82714C58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,31288
	ctx.r4.s64 = ctx.r8.s64 + 31288;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,31260
	ctx.r10.s64 = ctx.r7.s64 + 31260;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714CB0"))) PPC_WEAK_FUNC(sub_82714CB0);
PPC_FUNC_IMPL(__imp__sub_82714CB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r5,r9,3998
	ctx.r5.s64 = ctx.r9.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r7,31320
	ctx.r4.s64 = ctx.r7.s64 + 31320;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r9,r6,31296
	ctx.r9.s64 = ctx.r6.s64 + 31296;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714D08"))) PPC_WEAK_FUNC(sub_82714D08);
PPC_FUNC_IMPL(__imp__sub_82714D08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,31360
	ctx.r4.s64 = ctx.r8.s64 + 31360;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,31328
	ctx.r10.s64 = ctx.r7.s64 + 31328;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714D60"))) PPC_WEAK_FUNC(sub_82714D60);
PPC_FUNC_IMPL(__imp__sub_82714D60) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r5,r9,3998
	ctx.r5.s64 = ctx.r9.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r7,31396
	ctx.r4.s64 = ctx.r7.s64 + 31396;
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r9,r6,31368
	ctx.r9.s64 = ctx.r6.s64 + 31368;
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// lfs f0,7444(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714DB8"))) PPC_WEAK_FUNC(sub_82714DB8);
PPC_FUNC_IMPL(__imp__sub_82714DB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r11,0
	r11.s64 = 0;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r5,r10,3998
	ctx.r5.s64 = ctx.r10.s64 + 3998;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// addi r4,r8,31440
	ctx.r4.s64 = ctx.r8.s64 + 31440;
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// addi r10,r7,31404
	ctx.r10.s64 = ctx.r7.s64 + 31404;
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, r11.u32);
	// stw r5,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r5.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// stb r11,40(r3)
	PPC_STORE_U8(ctx.r3.u32 + 40, r11.u8);
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714E10"))) PPC_WEAK_FUNC(sub_82714E10);
PPC_FUNC_IMPL(__imp__sub_82714E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714E30"))) PPC_WEAK_FUNC(sub_82714E30);
PPC_FUNC_IMPL(__imp__sub_82714E30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lfs f13,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f12,11412(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11412);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f13,24(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f12,28(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714E70"))) PPC_WEAK_FUNC(sub_82714E70);
PPC_FUNC_IMPL(__imp__sub_82714E70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// lfs f0,304(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 304);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714EA4"))) PPC_WEAK_FUNC(sub_82714EA4);
PPC_FUNC_IMPL(__imp__sub_82714EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82714EA8"))) PPC_WEAK_FUNC(sub_82714EA8);
PPC_FUNC_IMPL(__imp__sub_82714EA8) {
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
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f13,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stb r11,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, r11.u8);
	// stfs f13,20(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714ED8"))) PPC_WEAK_FUNC(sub_82714ED8);
PPC_FUNC_IMPL(__imp__sub_82714ED8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,2272
	ctx.r9.s64 = r11.s64 + 2272;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r11,0
	r11.s64 = 0;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stfs f0,12(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r3,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714F0C"))) PPC_WEAK_FUNC(sub_82714F0C);
PPC_FUNC_IMPL(__imp__sub_82714F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82714F10"))) PPC_WEAK_FUNC(sub_82714F10);
PPC_FUNC_IMPL(__imp__sub_82714F10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stfs f0,16(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stb r11,12(r3)
	PPC_STORE_U8(ctx.r3.u32 + 12, r11.u8);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stb r11,44(r3)
	PPC_STORE_U8(ctx.r3.u32 + 44, r11.u8);
	// stfs f0,24(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stw r11,56(r3)
	PPC_STORE_U32(ctx.r3.u32 + 56, r11.u32);
	// stfs f0,28(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stw r11,60(r3)
	PPC_STORE_U32(ctx.r3.u32 + 60, r11.u32);
	// stfs f0,32(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f0,36(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f0,40(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f0,48(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f0,52(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714F64"))) PPC_WEAK_FUNC(sub_82714F64);
PPC_FUNC_IMPL(__imp__sub_82714F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82714F68"))) PPC_WEAK_FUNC(sub_82714F68);
PPC_FUNC_IMPL(__imp__sub_82714F68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,160(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 160);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// blt cr6,0x82714fb0
	if (cr6.lt) goto loc_82714FB0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82714f9c
	if (cr6.eq) goto loc_82714F9C;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82714fa0
	if (!cr6.eq) goto loc_82714FA0;
loc_82714F9C:
	// li r11,0
	r11.s64 = 0;
loc_82714FA0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82714fb4
	if (cr6.eq) goto loc_82714FB4;
loc_82714FB0:
	// li r11,0
	r11.s64 = 0;
loc_82714FB4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82714FBC"))) PPC_WEAK_FUNC(sub_82714FBC);
PPC_FUNC_IMPL(__imp__sub_82714FBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82714FC0"))) PPC_WEAK_FUNC(sub_82714FC0);
PPC_FUNC_IMPL(__imp__sub_82714FC0) {
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
	// bl 0x82711ca0
	ctx.lr = 0x82714FD8;
	sub_82711CA0(ctx, base);
	// lwz r3,160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82714FF0;
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

__attribute__((alias("__imp__sub_82715004"))) PPC_WEAK_FUNC(sub_82715004);
PPC_FUNC_IMPL(__imp__sub_82715004) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82715008"))) PPC_WEAK_FUNC(sub_82715008);
PPC_FUNC_IMPL(__imp__sub_82715008) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82715048
	if (cr6.lt) goto loc_82715048;
	// beq cr6,0x82715038
	if (cr6.eq) goto loc_82715038;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// blt cr6,0x82715028
	if (cr6.lt) goto loc_82715028;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_82715028:
	// addi r11,r4,-3
	r11.s64 = ctx.r4.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
loc_82715038:
	// addi r11,r4,-2
	r11.s64 = ctx.r4.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
loc_82715048:
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82715058"))) PPC_WEAK_FUNC(sub_82715058);
PPC_FUNC_IMPL(__imp__sub_82715058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82715064"))) PPC_WEAK_FUNC(sub_82715064);
PPC_FUNC_IMPL(__imp__sub_82715064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82715068"))) PPC_WEAK_FUNC(sub_82715068);
PPC_FUNC_IMPL(__imp__sub_82715068) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r10,2256(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 2256);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8271508c
	if (cr6.eq) goto loc_8271508C;
	// lwz r11,2260(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82715090
	if (!cr6.eq) goto loc_82715090;
loc_8271508C:
	// li r11,0
	r11.s64 = 0;
loc_82715090:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// li r4,2
	ctx.r4.s64 = 2;
	// b 0x827a6e68
	sub_827A6E68(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_827150A8"))) PPC_WEAK_FUNC(sub_827150A8);
PPC_FUNC_IMPL(__imp__sub_827150A8) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827150AC"))) PPC_WEAK_FUNC(sub_827150AC);
PPC_FUNC_IMPL(__imp__sub_827150AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827150B0"))) PPC_WEAK_FUNC(sub_827150B0);
PPC_FUNC_IMPL(__imp__sub_827150B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// ble cr6,0x827150c8
	if (!cr6.gt) goto loc_827150C8;
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x827150cc
	if (cr6.lt) goto loc_827150CC;
loc_827150C8:
	// li r11,0
	r11.s64 = 0;
loc_827150CC:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827150D4"))) PPC_WEAK_FUNC(sub_827150D4);
PPC_FUNC_IMPL(__imp__sub_827150D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827150D8"))) PPC_WEAK_FUNC(sub_827150D8);
PPC_FUNC_IMPL(__imp__sub_827150D8) {
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
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82715100;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82715140
	if (cr6.eq) goto loc_82715140;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,80(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8271512C;
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
loc_82715140:
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

__attribute__((alias("__imp__sub_82715158"))) PPC_WEAK_FUNC(sub_82715158);
PPC_FUNC_IMPL(__imp__sub_82715158) {
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
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82715180;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x827151c0
	if (cr6.eq) goto loc_827151C0;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,84(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x827151AC;
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
loc_827151C0:
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

__attribute__((alias("__imp__sub_827151D8"))) PPC_WEAK_FUNC(sub_827151D8);
PPC_FUNC_IMPL(__imp__sub_827151D8) {
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
	// bl 0x823d91f8
	ctx.lr = 0x827151E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x827104d0
	ctx.lr = 0x827151EC;
	sub_827104D0(ctx, base);
	// lwz r3,160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82715204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r6,176
	ctx.r6.s64 = 176;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,11412(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11412);
	f0.f64 = double(temp.f32);
	// addi r11,r31,224
	r11.s64 = r31.s64 + 224;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r5,192(r31)
	PPC_STORE_U32(r31.u32 + 192, ctx.r5.u32);
	// lvlx128 v63,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r10,3
	ctx.r10.s64 = 3;
	// stvx128 v62,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,-16
	ctx.r6.s64 = -16;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
loc_82715250:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvlx128 v60,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v59,v61,0
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvlx128 v58,r0,r30
	temp.u32 = r30.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvlx128 v56,r0,r29
	temp.u32 = r29.u32;
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v55,v58,0
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// lvlx128 v54,r0,r28
	temp.u32 = r28.u32;
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v53,v56,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v56.u32), 0xFF));
	// vspltw128 v52,v54,0
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v54.u32), 0xFF));
	// stvx128 v59,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// bne 0x82715250
	if (!cr0.eq) goto loc_82715250;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f0,456(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 456, temp.u32);
	// stw r5,448(r31)
	PPC_STORE_U32(r31.u32 + 448, ctx.r5.u32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,452(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 452, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827152C8"))) PPC_WEAK_FUNC(sub_827152C8);
PPC_FUNC_IMPL(__imp__sub_827152C8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x827152D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82712650
	ctx.lr = 0x827152E0;
	sub_82712650(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827153c4
	if (cr6.eq) goto loc_827153C4;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r8,176
	ctx.r8.s64 = 176;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r11,r30,224
	r11.s64 = r30.s64 + 224;
	// li r10,3
	ctx.r10.s64 = 3;
	// lvx128 v63,r31,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r30,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stw r6,192(r30)
	PPC_STORE_U32(r30.u32 + 192, ctx.r6.u32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r6,-16
	ctx.r6.s64 = -16;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,48
	ctx.r8.s64 = 48;
loc_82715324:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v60,v62,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// lvlx128 v59,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v58,v61,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvlx128 v57,r0,r31
	temp.u32 = r31.u32;
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v56,v59,0
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// lvlx128 v55,r0,r29
	temp.u32 = r29.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v54,v57,0
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v57.u32), 0xFF));
	// vspltw128 v53,v55,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// stvx128 v60,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// bne 0x82715324
	if (!cr0.eq) goto loc_82715324;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,84(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 84);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f0,456(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 456, temp.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,448(r30)
	PPC_STORE_U32(r30.u32 + 448, ctx.r9.u32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,452(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 452, temp.u32);
	// bne cr6,0x827153b8
	if (!cr6.eq) goto loc_827153B8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827153B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_827153B8:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_827153C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_827153D0"))) PPC_WEAK_FUNC(sub_827153D0);
PPC_FUNC_IMPL(__imp__sub_827153D0) {
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
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x827153D8;
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f30.u64);
	// stfd f31,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	f30.f64 = ctx.f1.f64;
	// lbz r11,20(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827156b4
	if (cr6.eq) goto loc_827156B4;
	// lbz r11,84(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 84);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82715460
	if (cr6.eq) goto loc_82715460;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82715460
	if (!cr6.eq) goto loc_82715460;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,656(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// addi r9,r11,-3
	ctx.r9.s64 = r11.s64 + -3;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r6,r7,1
	ctx.r6.u64 = ctx.r7.u64 ^ 1;
	// clrlwi r5,r6,24
	ctx.r5.u64 = ctx.r6.u32 & 0xFF;
	// stb r6,84(r31)
	PPC_STORE_U8(r31.u32 + 84, ctx.r6.u8);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x827156b4
	if (!cr6.eq) goto loc_827156B4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82715450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_82715460:
	// lwz r3,160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// bl 0x827150d8
	ctx.lr = 0x82715468;
	sub_827150D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827154a0
	if (cr6.eq) goto loc_827154A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82710fb8
	ctx.lr = 0x8271547C;
	sub_82710FB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x827154a0
	if (!cr6.eq) goto loc_827154A0;
	// li r11,3
	r11.s64 = 3;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_827154A0:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r28,12(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// beq cr6,0x827155f0
	if (cr6.eq) goto loc_827155F0;
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// bge cr6,0x827155f0
	if (!cr6.lt) goto loc_827155F0;
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bge cr6,0x827155f0
	if (!cr6.lt) goto loc_827155F0;
	// lfs f0,452(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 452);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x827155f0
	if (!cr6.gt) goto loc_827155F0;
	// fsubs f0,f0,f30
	f0.f64 = double(float(f0.f64 - f30.f64));
	// stfs f0,452(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 452, temp.u32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bgt cr6,0x827155f0
	if (cr6.gt) goto loc_827155F0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,452(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 452, temp.u32);
	// bl 0x822a8108
	ctx.lr = 0x827154FC;
	sub_822A8108(ctx, base);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r8,76(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// li r29,1
	r29.s64 = 1;
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r30,68(r7)
	r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82715574
	if (cr6.eq) goto loc_82715574;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r11,-32125
	r11.s64 = -2105344000;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,-16628(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -16628);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82715540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82715574
	if (cr6.eq) goto loc_82715574;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826fd068
	ctx.lr = 0x82715558;
	sub_826FD068(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82715574
	if (cr6.eq) goto loc_82715574;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826fd508
	ctx.lr = 0x82715570;
	sub_826FD508(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
loc_82715574:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x827155f0
	if (cr6.eq) goto loc_827155F0;
	// lwz r11,448(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 448);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,13
	ctx.r9.s64 = r11.s64 + 13;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r7,r9,4,0,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,448(r31)
	PPC_STORE_U32(r31.u32 + 448, ctx.r8.u32);
	// stvx128 v62,r7,r31
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,40(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x827155B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x827155d8
	if (cr6.eq) goto loc_827155D8;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// lwz r10,640(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 640);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// b 0x827155e4
	goto loc_827155E4;
loc_827155D8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826fd0a8
	ctx.lr = 0x827155E0;
	sub_826FD0A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
loc_827155E4:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x827155f0
	if (cr6.eq) goto loc_827155F0;
	// stfs f31,452(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 452, temp.u32);
loc_827155F0:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8271568c
	if (cr6.eq) goto loc_8271568C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8271560C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8271568c
	if (cr6.eq) goto loc_8271568C;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// beq cr6,0x82715628
	if (cr6.eq) goto loc_82715628;
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// bne cr6,0x8271568c
	if (!cr6.eq) goto loc_8271568C;
loc_82715628:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r10,76(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r9,r11,-13624
	ctx.r9.s64 = r11.s64 + -13624;
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f2,220(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 220);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,384(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 384);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8270cfc8
	ctx.lr = 0x8271564C;
	sub_8270CFC8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8271568c
	if (cr6.eq) goto loc_8271568C;
	// lfs f0,456(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 456);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fadds f13,f30,f0
	ctx.f13.f64 = double(float(f30.f64 + f0.f64));
	// stfs f13,456(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 456, temp.u32);
	// lfs f0,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x82715690
	if (!cr6.gt) goto loc_82715690;
	// li r11,1
	r11.s64 = 1;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8271568C:
	// stfs f31,456(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 456, temp.u32);
loc_82715690:
	// lwz r3,160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827156A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// bl 0x82711628
	ctx.lr = 0x827156B4;
	sub_82711628(ctx, base);
loc_827156B4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_827156C4"))) PPC_WEAK_FUNC(sub_827156C4);
PPC_FUNC_IMPL(__imp__sub_827156C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827156C8"))) PPC_WEAK_FUNC(sub_827156C8);
PPC_FUNC_IMPL(__imp__sub_827156C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r3,880(r10)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + 880);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827156D8"))) PPC_WEAK_FUNC(sub_827156D8);
PPC_FUNC_IMPL(__imp__sub_827156D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,32284
	ctx.r3.s64 = r11.s64 + 32284;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827156E4"))) PPC_WEAK_FUNC(sub_827156E4);
PPC_FUNC_IMPL(__imp__sub_827156E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_827156E8"))) PPC_WEAK_FUNC(sub_827156E8);
PPC_FUNC_IMPL(__imp__sub_827156E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,20572
	ctx.r3.s64 = r11.s64 + 20572;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_827156F4"))) PPC_WEAK_FUNC(sub_827156F4);
PPC_FUNC_IMPL(__imp__sub_827156F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

