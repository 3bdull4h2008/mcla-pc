#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_822AE70C"))) PPC_WEAK_FUNC(sub_822AE70C);
PPC_FUNC_IMPL(__imp__sub_822AE70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE710"))) PPC_WEAK_FUNC(sub_822AE710);
PPC_FUNC_IMPL(__imp__sub_822AE710) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,112(r11)
	PPC_STORE_U8(r11.u32 + 112, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE738"))) PPC_WEAK_FUNC(sub_822AE738);
PPC_FUNC_IMPL(__imp__sub_822AE738) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae758
	if (cr6.eq) goto loc_822AE758;
	// lwz r11,116(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822AE758:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE764"))) PPC_WEAK_FUNC(sub_822AE764);
PPC_FUNC_IMPL(__imp__sub_822AE764) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE768"))) PPC_WEAK_FUNC(sub_822AE768);
PPC_FUNC_IMPL(__imp__sub_822AE768) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lfs f0,27644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// beq cr6,0x822ae7b4
	if (cr6.eq) goto loc_822AE7B4;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,192(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// stfs f12,196(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// stfs f11,200(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// stfs f0,204(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// bl 0x822a9788
	ctx.lr = 0x822AE7B4;
	sub_822A9788(ctx, base);
loc_822AE7B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AE7C4"))) PPC_WEAK_FUNC(sub_822AE7C4);
PPC_FUNC_IMPL(__imp__sub_822AE7C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AE7C8"))) PPC_WEAK_FUNC(sub_822AE7C8);
PPC_FUNC_IMPL(__imp__sub_822AE7C8) {
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
	ctx.lr = 0x822AE7D0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822ae7f8
	if (cr6.eq) goto loc_822AE7F8;
	// lwz r11,656(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 656);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x822ae7fc
	goto loc_822AE7FC;
loc_822AE7F8:
	// li r11,0
	r11.s64 = 0;
loc_822AE7FC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aeafc
	if (cr6.eq) goto loc_822AEAFC;
	// lwz r4,672(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 672);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822aeb40
	if (cr6.lt) goto loc_822AEB40;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// bl 0x823c98b0
	ctx.lr = 0x822AE820;
	sub_823C98B0(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// stw r11,672(r30)
	PPC_STORE_U32(r30.u32 + 672, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bne cr6,0x822ae848
	if (!cr6.eq) goto loc_822AE848;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// bl 0x822ab0f0
	ctx.lr = 0x822AE840;
	sub_822AB0F0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_822AE848:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-27520
	ctx.r9.s64 = r11.s64 + -27520;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x822ab0f0
	ctx.lr = 0x822AE85C;
	sub_822AB0F0(ctx, base);
	// lwz r24,48(r30)
	r24.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x822aeb40
	if (cr6.eq) goto loc_822AEB40;
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae87c
	if (cr6.eq) goto loc_822AE87C;
	// addi r10,r11,8109
	ctx.r10.s64 = r11.s64 + 8109;
	// b 0x822ae890
	goto loc_822AE890;
loc_822AE87C:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r10,r11,8109
	ctx.r10.s64 = r11.s64 + 8109;
	// bne cr6,0x822ae890
	if (!cr6.eq) goto loc_822AE890;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822AE890:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r11,r11,24808
	r11.s64 = r11.s64 + 24808;
loc_822AE898:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822ae8bc
	if (cr6.eq) goto loc_822AE8BC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822ae898
	if (cr6.eq) goto loc_822AE898;
loc_822AE8BC:
	// lwz r11,28(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822aeb40
	if (cr6.eq) goto loc_822AEB40;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822aeb40
	if (cr6.eq) goto loc_822AEB40;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// stw r8,336(r11)
	PPC_STORE_U32(r11.u32 + 336, ctx.r8.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,672(r30)
	PPC_STORE_U32(r30.u32 + 672, ctx.r10.u32);
	// lwz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 40);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822AE920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822ae950
	if (cr6.eq) goto loc_822AE950;
	// lwz r11,136(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822ae950
	if (!cr6.eq) goto loc_822AE950;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// addi r10,r11,17492
	ctx.r10.s64 = r11.s64 + 17492;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae954
	if (cr6.eq) goto loc_822AE954;
loc_822AE950:
	// li r29,0
	r29.s64 = 0;
loc_822AE954:
	// lbz r11,177(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 177);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r27,r10,27,31,31
	r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x823315c0
	ctx.lr = 0x822AE968;
	sub_823315C0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82332098
	ctx.lr = 0x822AE974;
	sub_82332098(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822ae998
	if (cr6.eq) goto loc_822AE998;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r25,1
	r25.s64 = 1;
	// addi r10,r11,17572
	ctx.r10.s64 = r11.s64 + 17572;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae99c
	if (cr6.eq) goto loc_822AE99C;
loc_822AE998:
	// li r25,0
	r25.s64 = 0;
loc_822AE99C:
	// lwz r11,60(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 60);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822ae9b0
	if (cr6.eq) goto loc_822AE9B0;
	// addi r31,r11,8109
	r31.s64 = r11.s64 + 8109;
	// b 0x822ae9c4
	goto loc_822AE9C4;
loc_822AE9B0:
	// lwz r11,52(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,8109
	r31.s64 = r11.s64 + 8109;
	// bne cr6,0x822ae9c4
	if (!cr6.eq) goto loc_822AE9C4;
	// li r31,0
	r31.s64 = 0;
loc_822AE9C4:
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82332098
	ctx.lr = 0x822AE9CC;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// li r4,2
	ctx.r4.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r9,r31
	ctx.r9.u64 = r31.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x8239e458
	ctx.lr = 0x822AE9F8;
	sub_8239E458(ctx, base);
	// clrlwi r26,r29,24
	r26.u64 = r29.u32 & 0xFF;
	// addi r31,r30,144
	r31.s64 = r30.s64 + 144;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// clrlwi r27,r25,24
	r27.u64 = r25.u32 & 0xFF;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// beq cr6,0x822aea54
	if (cr6.eq) goto loc_822AEA54;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822aea38
	if (cr6.eq) goto loc_822AEA38;
	// bl 0x823c99e0
	ctx.lr = 0x822AEA20;
	sub_823C99E0(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9a10
	ctx.lr = 0x822AEA34;
	sub_823C9A10(ctx, base);
	// b 0x822aea90
	goto loc_822AEA90;
loc_822AEA38:
	// bl 0x823c9980
	ctx.lr = 0x822AEA3C;
	sub_823C9980(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c99b0
	ctx.lr = 0x822AEA50;
	sub_823C99B0(ctx, base);
	// b 0x822aea90
	goto loc_822AEA90;
loc_822AEA54:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822aea78
	if (cr6.eq) goto loc_822AEA78;
	// bl 0x823c9b60
	ctx.lr = 0x822AEA60;
	sub_823C9B60(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9b90
	ctx.lr = 0x822AEA74;
	sub_823C9B90(ctx, base);
	// b 0x822aea90
	goto loc_822AEA90;
loc_822AEA78:
	// bl 0x823c9b00
	ctx.lr = 0x822AEA7C;
	sub_823C9B00(ctx, base);
	// lwz r11,-4960(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823c9b30
	ctx.lr = 0x822AEA90;
	sub_823C9B30(ctx, base);
loc_822AEA90:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822aead4
	if (cr6.eq) goto loc_822AEAD4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aead4
	if (cr6.eq) goto loc_822AEAD4;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r3,-4960(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -4960);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r5,676(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 676);
	// lwz r4,672(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 672);
	// bl 0x823c9c58
	ctx.lr = 0x822AEAC4;
	sub_823C9C58(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x822AEACC;
	sub_82130588(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_822AEAD4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// addi r3,r11,24720
	ctx.r3.s64 = r11.s64 + 24720;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x822AEAEC;
	sub_82130000(ctx, base);
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82130588
	ctx.lr = 0x822AEAF4;
	sub_82130588(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_822AEAFC:
	// lwz r11,672(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 672);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822aeb40
	if (!cr6.lt) goto loc_822AEB40;
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// bne cr6,0x822aeb28
	if (!cr6.eq) goto loc_822AEB28;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,3998
	ctx.r4.s64 = r11.s64 + 3998;
	// bl 0x822ab0f0
	ctx.lr = 0x822AEB20;
	sub_822AB0F0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
loc_822AEB28:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-27520
	ctx.r9.s64 = r11.s64 + -27520;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x822ab0f0
	ctx.lr = 0x822AEB40;
	sub_822AB0F0(ctx, base);
loc_822AEB40:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822AEB48"))) PPC_WEAK_FUNC(sub_822AEB48);
PPC_FUNC_IMPL(__imp__sub_822AEB48) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r6,r7,r31
	PPC_STORE_U32(ctx.r7.u32 + r31.u32, ctx.r6.u32);
	// lfs f0,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r9,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r9.u32);
	// add r4,r11,r31
	ctx.r4.u64 = r11.u64 + r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AEBC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r8.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_822AEBE0"))) PPC_WEAK_FUNC(sub_822AEBE0);
PPC_FUNC_IMPL(__imp__sub_822AEBE0) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AEC04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r9,26672
	ctx.r3.s64 = ctx.r9.s64 + 26672;
	// bl 0x82130000
	ctx.lr = 0x822AEC14;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822abd38
	ctx.lr = 0x822AEC1C;
	sub_822ABD38(ctx, base);
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r3,8(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x8255b9a8
	ctx.lr = 0x822AEC28;
	sub_8255B9A8(ctx, base);
	// lfs f0,24(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	f0.f64 = double(temp.f32);
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lfs f13,40(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fabs f10,f13
	ctx.f10.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lfs f11,16(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,32(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// fabs f8,f11
	ctx.f8.u64 = ctx.f11.u64 & ~0x8000000000000000;
	// fabs f7,f9
	ctx.f7.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// addi r11,r31,472
	r11.s64 = r31.s64 + 472;
	// lfs f0,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fsubs f6,f10,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 - ctx.f12.f64));
	// fsubs f5,f7,f8
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fsel f4,f6,f10,f12
	ctx.f4.f64 = ctx.f6.f64 >= 0.0 ? ctx.f10.f64 : ctx.f12.f64;
	// stfs f4,476(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 476, temp.u32);
	// fsel f3,f5,f7,f8
	ctx.f3.f64 = ctx.f5.f64 >= 0.0 ? ctx.f7.f64 : ctx.f8.f64;
	// stfs f3,472(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 472, temp.u32);
	// fmr f1,f4
	ctx.f1.f64 = ctx.f4.f64;
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// fmuls f13,f1,f1
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64));
	// fmadds f12,f2,f2,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f13.f64));
	// fsqrts f11,f12
	ctx.f11.f64 = double(float(sqrt(ctx.f12.f64)));
	// stfs f11,480(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 480, temp.u32);
	// lfs f10,472(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 472);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,476(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 476);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f8,f10,f0
	ctx.f8.f64 = double(float(ctx.f10.f64 * f0.f64));
	// stfs f8,472(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 472, temp.u32);
	// fmuls f7,f9,f0
	ctx.f7.f64 = double(float(ctx.f9.f64 * f0.f64));
	// stfs f7,476(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 476, temp.u32);
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lbz r9,689(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 689);
	// beq cr6,0x822aecdc
	if (cr6.eq) goto loc_822AECDC;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aecdc
	if (cr6.eq) goto loc_822AECDC;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aecdc
	if (cr6.eq) goto loc_822AECDC;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822aecd8
	if (!cr6.eq) goto loc_822AECD8;
	// li r11,0
	r11.s64 = 0;
loc_822AECD8:
	// stb r9,597(r11)
	PPC_STORE_U8(r11.u32 + 597, ctx.r9.u8);
loc_822AECDC:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lbz r9,690(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 690);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822aed1c
	if (cr6.eq) goto loc_822AED1C;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aed1c
	if (cr6.eq) goto loc_822AED1C;
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822aed1c
	if (cr6.eq) goto loc_822AED1C;
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x822aed18
	if (!cr6.eq) goto loc_822AED18;
	// li r11,0
	r11.s64 = 0;
loc_822AED18:
	// stb r9,598(r11)
	PPC_STORE_U8(r11.u32 + 598, ctx.r9.u8);
loc_822AED1C:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aed38
	if (cr6.eq) goto loc_822AED38;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AED38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822AED38:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a93a8
	ctx.lr = 0x822AED44;
	sub_822A93A8(ctx, base);
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

__attribute__((alias("__imp__sub_822AED58"))) PPC_WEAK_FUNC(sub_822AED58);
PPC_FUNC_IMPL(__imp__sub_822AED58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822aed74
	if (cr6.eq) goto loc_822AED74;
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// addi r11,r11,-3
	r11.s64 = r11.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x822aed78
	goto loc_822AED78;
loc_822AED74:
	// li r11,0
	r11.s64 = 0;
loc_822AED78:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822abd38
	sub_822ABD38(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AED88"))) PPC_WEAK_FUNC(sub_822AED88);
PPC_FUNC_IMPL(__imp__sub_822AED88) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AED8C"))) PPC_WEAK_FUNC(sub_822AED8C);
PPC_FUNC_IMPL(__imp__sub_822AED8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AED90"))) PPC_WEAK_FUNC(sub_822AED90);
PPC_FUNC_IMPL(__imp__sub_822AED90) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x822ab0f0
	ctx.lr = 0x822AEDBC;
	sub_822AB0F0(ctx, base);
	// stw r30,140(r31)
	PPC_STORE_U32(r31.u32 + 140, r30.u32);
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

__attribute__((alias("__imp__sub_822AEDD8"))) PPC_WEAK_FUNC(sub_822AEDD8);
PPC_FUNC_IMPL(__imp__sub_822AEDD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// b 0x822ab0f0
	sub_822AB0F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AEDF0"))) PPC_WEAK_FUNC(sub_822AEDF0);
PPC_FUNC_IMPL(__imp__sub_822AEDF0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AEDF4"))) PPC_WEAK_FUNC(sub_822AEDF4);
PPC_FUNC_IMPL(__imp__sub_822AEDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AEDF8"))) PPC_WEAK_FUNC(sub_822AEDF8);
PPC_FUNC_IMPL(__imp__sub_822AEDF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lfs f0,27644(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27644);
	f0.f64 = double(temp.f32);
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// lwz r5,4(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm r4,r6,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stwx r5,r4,r11
	PPC_STORE_U32(ctx.r4.u32 + r11.u32, ctx.r5.u32);
	// lfs f13,8(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// stfs f11,0(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// stfs f12,4(r10)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r10.u32 + 4, temp.u32);
	// stfs f13,8(r10)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// addi r8,r10,2
	ctx.r8.s64 = ctx.r10.s64 + 2;
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r8,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// lfs f10,8(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f10.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// fmuls f0,f10,f0
	f0.f64 = double(float(ctx.f10.f64 * f0.f64));
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822aeeac
	if (cr6.eq) goto loc_822AEEAC;
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,192(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 192, temp.u32);
	// stfs f12,196(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 196, temp.u32);
	// stfs f11,200(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 200, temp.u32);
	// stfs f0,204(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 204, temp.u32);
	// bl 0x822a9788
	ctx.lr = 0x822AEEAC;
	sub_822A9788(ctx, base);
loc_822AEEAC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AEEBC"))) PPC_WEAK_FUNC(sub_822AEEBC);
PPC_FUNC_IMPL(__imp__sub_822AEEBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AEEC0"))) PPC_WEAK_FUNC(sub_822AEEC0);
PPC_FUNC_IMPL(__imp__sub_822AEEC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwx r7,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u32);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// beq cr6,0x822aef6c
	if (cr6.eq) goto loc_822AEF6C;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aef60
	if (cr6.eq) goto loc_822AEF60;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822aef4c
	if (cr6.eq) goto loc_822AEF4C;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822aef54
	goto loc_822AEF54;
loc_822AEF4C:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822AEF54:
	// li r10,32
	ctx.r10.s64 = 32;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822AEF60:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26796
	ctx.r3.s64 = r11.s64 + 26796;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
loc_822AEF6C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,26732
	ctx.r3.s64 = r11.s64 + 26732;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AEF78"))) PPC_WEAK_FUNC(sub_822AEF78);
PPC_FUNC_IMPL(__imp__sub_822AEF78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32213
	r11.s64 = -2111111168;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,-29424
	ctx.r3.s64 = r11.s64 + -29424;
	// b 0x822aeb48
	sub_822AEB48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AEF88"))) PPC_WEAK_FUNC(sub_822AEF88);
PPC_FUNC_IMPL(__imp__sub_822AEF88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stwx r7,r8,r3
	PPC_STORE_U32(ctx.r8.u32 + ctx.r3.u32, ctx.r7.u32);
	// lfs f0,8(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r6,r11,2
	ctx.r6.s64 = r11.s64 + 2;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 0, temp.u32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 4, temp.u32);
	// stfs f0,8(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 8, temp.u32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// rlwinm r11,r5,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r4,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822af038
	if (cr6.eq) goto loc_822AF038;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r8,72
	ctx.r8.s64 = 72;
	// lbzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822af020
	if (cr6.eq) goto loc_822AF020;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822AF020:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_822AF038:
	// addi r11,r10,288
	r11.s64 = ctx.r10.s64 + 288;
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF04C"))) PPC_WEAK_FUNC(sub_822AF04C);
PPC_FUNC_IMPL(__imp__sub_822AF04C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AF050"))) PPC_WEAK_FUNC(sub_822AF050);
PPC_FUNC_IMPL(__imp__sub_822AF050) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822aad90
	sub_822AAD90(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AF060"))) PPC_WEAK_FUNC(sub_822AF060);
PPC_FUNC_IMPL(__imp__sub_822AF060) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r10,2048
	ctx.r10.s64 = 2048;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// stb r9,32(r8)
	PPC_STORE_U8(ctx.r8.u32 + 32, ctx.r9.u8);
	// lwz r7,28(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r5,20(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// stw r5,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, ctx.r5.u32);
	// lwz r4,28(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r3,4(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r10,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,376(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 376);
	// stw r7,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r7.u32);
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r10,376(r6)
	PPC_STORE_U32(ctx.r6.u32 + 376, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF0B0"))) PPC_WEAK_FUNC(sub_822AF0B0);
PPC_FUNC_IMPL(__imp__sub_822AF0B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r7,36(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// stb r10,32(r9)
	PPC_STORE_U8(ctx.r9.u32 + 32, ctx.r10.u8);
	// lwz r6,28(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// stw r7,20(r5)
	PPC_STORE_U32(ctx.r5.u32 + 20, ctx.r7.u32);
	// lwz r4,48(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r11,40(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// stw r11,376(r3)
	PPC_STORE_U32(ctx.r3.u32 + 376, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF0E8"))) PPC_WEAK_FUNC(sub_822AF0E8);
PPC_FUNC_IMPL(__imp__sub_822AF0E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822ae7c8
	sub_822AE7C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AF0F8"))) PPC_WEAK_FUNC(sub_822AF0F8);
PPC_FUNC_IMPL(__imp__sub_822AF0F8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f2,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,0(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
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
	// bl 0x822ab838
	ctx.lr = 0x822AF138;
	sub_822AB838(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF148"))) PPC_WEAK_FUNC(sub_822AF148);
PPC_FUNC_IMPL(__imp__sub_822AF148) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f12,-8(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// li r9,96
	ctx.r9.s64 = 96;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,108(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 108, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AF194"))) PPC_WEAK_FUNC(sub_822AF194);
PPC_FUNC_IMPL(__imp__sub_822AF194) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AF198"))) PPC_WEAK_FUNC(sub_822AF198);
PPC_FUNC_IMPL(__imp__sub_822AF198) {
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
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-12608
	ctx.r4.s64 = r11.s64 + -12608;
	// addi r3,r10,29228
	ctx.r3.s64 = ctx.r10.s64 + 29228;
	// bl 0x82554798
	ctx.lr = 0x822AF1B8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-12480
	ctx.r4.s64 = ctx.r9.s64 + -12480;
	// addi r3,r8,29208
	ctx.r3.s64 = ctx.r8.s64 + 29208;
	// bl 0x82554798
	ctx.lr = 0x822AF1CC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-12408
	ctx.r4.s64 = ctx.r7.s64 + -12408;
	// addi r3,r6,29192
	ctx.r3.s64 = ctx.r6.s64 + 29192;
	// bl 0x82554798
	ctx.lr = 0x822AF1E0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-12384
	ctx.r4.s64 = ctx.r5.s64 + -12384;
	// addi r3,r3,29176
	ctx.r3.s64 = ctx.r3.s64 + 29176;
	// bl 0x82554798
	ctx.lr = 0x822AF1F4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-12336
	ctx.r4.s64 = r11.s64 + -12336;
	// addi r3,r10,29160
	ctx.r3.s64 = ctx.r10.s64 + 29160;
	// bl 0x82554798
	ctx.lr = 0x822AF208;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-12224
	ctx.r4.s64 = ctx.r9.s64 + -12224;
	// addi r3,r8,29132
	ctx.r3.s64 = ctx.r8.s64 + 29132;
	// bl 0x82554798
	ctx.lr = 0x822AF21C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4720
	ctx.r4.s64 = ctx.r7.s64 + -4720;
	// addi r3,r6,29100
	ctx.r3.s64 = ctx.r6.s64 + 29100;
	// bl 0x82554798
	ctx.lr = 0x822AF230;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-4648
	ctx.r4.s64 = ctx.r5.s64 + -4648;
	// addi r3,r3,29076
	ctx.r3.s64 = ctx.r3.s64 + 29076;
	// bl 0x82554798
	ctx.lr = 0x822AF244;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-12184
	ctx.r4.s64 = r11.s64 + -12184;
	// addi r3,r10,29044
	ctx.r3.s64 = ctx.r10.s64 + 29044;
	// bl 0x82554798
	ctx.lr = 0x822AF258;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-12144
	ctx.r4.s64 = ctx.r9.s64 + -12144;
	// addi r3,r8,29016
	ctx.r3.s64 = ctx.r8.s64 + 29016;
	// bl 0x82554798
	ctx.lr = 0x822AF26C;
	sub_82554798(ctx, base);
	// lis r7,-32144
	ctx.r7.s64 = -2106589184;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,12560
	ctx.r4.s64 = ctx.r7.s64 + 12560;
	// addi r3,r6,28996
	ctx.r3.s64 = ctx.r6.s64 + 28996;
	// bl 0x82554798
	ctx.lr = 0x822AF280;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-12104
	ctx.r4.s64 = ctx.r5.s64 + -12104;
	// addi r3,r3,28976
	ctx.r3.s64 = ctx.r3.s64 + 28976;
	// bl 0x82554798
	ctx.lr = 0x822AF294;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-12024
	ctx.r4.s64 = r11.s64 + -12024;
	// addi r3,r10,28952
	ctx.r3.s64 = ctx.r10.s64 + 28952;
	// bl 0x82554798
	ctx.lr = 0x822AF2A8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-11960
	ctx.r4.s64 = ctx.r9.s64 + -11960;
	// addi r3,r8,28932
	ctx.r3.s64 = ctx.r8.s64 + 28932;
	// bl 0x82554798
	ctx.lr = 0x822AF2BC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4616
	ctx.r4.s64 = ctx.r7.s64 + -4616;
	// addi r3,r6,28900
	ctx.r3.s64 = ctx.r6.s64 + 28900;
	// bl 0x82554798
	ctx.lr = 0x822AF2D0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-11848
	ctx.r4.s64 = ctx.r5.s64 + -11848;
	// addi r3,r3,28856
	ctx.r3.s64 = ctx.r3.s64 + 28856;
	// bl 0x82554798
	ctx.lr = 0x822AF2E4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-11832
	ctx.r4.s64 = r11.s64 + -11832;
	// addi r3,r10,28844
	ctx.r3.s64 = ctx.r10.s64 + 28844;
	// bl 0x82554798
	ctx.lr = 0x822AF2F8;
	sub_82554798(ctx, base);
	// lis r9,-32151
	ctx.r9.s64 = -2107047936;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,3664
	ctx.r4.s64 = ctx.r9.s64 + 3664;
	// addi r3,r8,28816
	ctx.r3.s64 = ctx.r8.s64 + 28816;
	// bl 0x82554798
	ctx.lr = 0x822AF30C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-11792
	ctx.r4.s64 = ctx.r7.s64 + -11792;
	// addi r3,r6,28800
	ctx.r3.s64 = ctx.r6.s64 + 28800;
	// bl 0x82554798
	ctx.lr = 0x822AF320;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-11776
	ctx.r4.s64 = ctx.r5.s64 + -11776;
	// addi r3,r3,28780
	ctx.r3.s64 = ctx.r3.s64 + 28780;
	// bl 0x82554798
	ctx.lr = 0x822AF334;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-11760
	ctx.r4.s64 = r11.s64 + -11760;
	// addi r3,r10,28752
	ctx.r3.s64 = ctx.r10.s64 + 28752;
	// bl 0x82554798
	ctx.lr = 0x822AF348;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-11728
	ctx.r4.s64 = ctx.r9.s64 + -11728;
	// addi r3,r8,28732
	ctx.r3.s64 = ctx.r8.s64 + 28732;
	// bl 0x82554798
	ctx.lr = 0x822AF35C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-11672
	ctx.r4.s64 = ctx.r7.s64 + -11672;
	// addi r3,r6,28708
	ctx.r3.s64 = ctx.r6.s64 + 28708;
	// bl 0x82554798
	ctx.lr = 0x822AF370;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-11568
	ctx.r4.s64 = ctx.r5.s64 + -11568;
	// addi r3,r3,28692
	ctx.r3.s64 = ctx.r3.s64 + 28692;
	// bl 0x82554798
	ctx.lr = 0x822AF384;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-11432
	ctx.r4.s64 = r11.s64 + -11432;
	// addi r3,r10,28672
	ctx.r3.s64 = ctx.r10.s64 + 28672;
	// bl 0x82554798
	ctx.lr = 0x822AF398;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-11336
	ctx.r4.s64 = ctx.r9.s64 + -11336;
	// addi r3,r8,28656
	ctx.r3.s64 = ctx.r8.s64 + 28656;
	// bl 0x82554798
	ctx.lr = 0x822AF3AC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-11240
	ctx.r4.s64 = ctx.r7.s64 + -11240;
	// addi r3,r6,28636
	ctx.r3.s64 = ctx.r6.s64 + 28636;
	// bl 0x82554798
	ctx.lr = 0x822AF3C0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-11176
	ctx.r4.s64 = ctx.r5.s64 + -11176;
	// addi r3,r3,28616
	ctx.r3.s64 = ctx.r3.s64 + 28616;
	// bl 0x82554798
	ctx.lr = 0x822AF3D4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-11080
	ctx.r4.s64 = r11.s64 + -11080;
	// addi r3,r10,28592
	ctx.r3.s64 = ctx.r10.s64 + 28592;
	// bl 0x82554798
	ctx.lr = 0x822AF3E8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10976
	ctx.r4.s64 = ctx.r9.s64 + -10976;
	// addi r3,r8,28576
	ctx.r3.s64 = ctx.r8.s64 + 28576;
	// bl 0x82554798
	ctx.lr = 0x822AF3FC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4416
	ctx.r4.s64 = ctx.r7.s64 + -4416;
	// addi r3,r6,28556
	ctx.r3.s64 = ctx.r6.s64 + 28556;
	// bl 0x82554798
	ctx.lr = 0x822AF410;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10912
	ctx.r4.s64 = ctx.r5.s64 + -10912;
	// addi r3,r3,28532
	ctx.r3.s64 = ctx.r3.s64 + 28532;
	// bl 0x82554798
	ctx.lr = 0x822AF424;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// addi r4,r11,-10856
	ctx.r4.s64 = r11.s64 + -10856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,28504
	ctx.r3.s64 = ctx.r10.s64 + 28504;
	// bl 0x82554798
	ctx.lr = 0x822AF438;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10792
	ctx.r4.s64 = ctx.r9.s64 + -10792;
	// addi r3,r8,28480
	ctx.r3.s64 = ctx.r8.s64 + 28480;
	// bl 0x82554798
	ctx.lr = 0x822AF44C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4232
	ctx.r4.s64 = ctx.r7.s64 + -4232;
	// addi r3,r6,28456
	ctx.r3.s64 = ctx.r6.s64 + 28456;
	// bl 0x82554798
	ctx.lr = 0x822AF460;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10720
	ctx.r4.s64 = ctx.r5.s64 + -10720;
	// addi r3,r3,28440
	ctx.r3.s64 = ctx.r3.s64 + 28440;
	// bl 0x82554798
	ctx.lr = 0x822AF474;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-10688
	ctx.r4.s64 = r11.s64 + -10688;
	// addi r3,r10,28416
	ctx.r3.s64 = ctx.r10.s64 + 28416;
	// bl 0x82554798
	ctx.lr = 0x822AF488;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10576
	ctx.r4.s64 = ctx.r9.s64 + -10576;
	// addi r3,r8,28388
	ctx.r3.s64 = ctx.r8.s64 + 28388;
	// bl 0x82554798
	ctx.lr = 0x822AF49C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4216
	ctx.r4.s64 = ctx.r7.s64 + -4216;
	// addi r3,r6,28368
	ctx.r3.s64 = ctx.r6.s64 + 28368;
	// bl 0x82554798
	ctx.lr = 0x822AF4B0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10528
	ctx.r4.s64 = ctx.r5.s64 + -10528;
	// addi r3,r3,28340
	ctx.r3.s64 = ctx.r3.s64 + 28340;
	// bl 0x82554798
	ctx.lr = 0x822AF4C4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-10496
	ctx.r4.s64 = r11.s64 + -10496;
	// addi r3,r10,28312
	ctx.r3.s64 = ctx.r10.s64 + 28312;
	// bl 0x82554798
	ctx.lr = 0x822AF4D8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10464
	ctx.r4.s64 = ctx.r9.s64 + -10464;
	// addi r3,r8,28284
	ctx.r3.s64 = ctx.r8.s64 + 28284;
	// bl 0x82554798
	ctx.lr = 0x822AF4EC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-10432
	ctx.r4.s64 = ctx.r7.s64 + -10432;
	// addi r3,r6,28256
	ctx.r3.s64 = ctx.r6.s64 + 28256;
	// bl 0x82554798
	ctx.lr = 0x822AF500;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10400
	ctx.r4.s64 = ctx.r5.s64 + -10400;
	// addi r3,r3,28228
	ctx.r3.s64 = ctx.r3.s64 + 28228;
	// bl 0x82554798
	ctx.lr = 0x822AF514;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-10352
	ctx.r4.s64 = r11.s64 + -10352;
	// addi r3,r10,28208
	ctx.r3.s64 = ctx.r10.s64 + 28208;
	// bl 0x82554798
	ctx.lr = 0x822AF528;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-10304
	ctx.r4.s64 = ctx.r9.s64 + -10304;
	// addi r3,r8,28188
	ctx.r3.s64 = ctx.r8.s64 + 28188;
	// bl 0x82554798
	ctx.lr = 0x822AF53C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-10232
	ctx.r4.s64 = ctx.r7.s64 + -10232;
	// addi r3,r6,28168
	ctx.r3.s64 = ctx.r6.s64 + 28168;
	// bl 0x82554798
	ctx.lr = 0x822AF550;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-10192
	ctx.r4.s64 = ctx.r5.s64 + -10192;
	// addi r3,r3,28148
	ctx.r3.s64 = ctx.r3.s64 + 28148;
	// bl 0x82554798
	ctx.lr = 0x822AF564;
	sub_82554798(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32213
	ctx.r10.s64 = -2111111168;
	// addi r3,r11,28120
	ctx.r3.s64 = r11.s64 + 28120;
	// addi r4,r10,-10072
	ctx.r4.s64 = ctx.r10.s64 + -10072;
	// bl 0x82554798
	ctx.lr = 0x822AF578;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-9952
	ctx.r4.s64 = ctx.r9.s64 + -9952;
	// addi r3,r8,28092
	ctx.r3.s64 = ctx.r8.s64 + 28092;
	// bl 0x82554798
	ctx.lr = 0x822AF58C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-9832
	ctx.r4.s64 = ctx.r7.s64 + -9832;
	// addi r3,r6,28068
	ctx.r3.s64 = ctx.r6.s64 + 28068;
	// bl 0x82554798
	ctx.lr = 0x822AF5A0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-4016
	ctx.r4.s64 = ctx.r5.s64 + -4016;
	// addi r3,r3,28052
	ctx.r3.s64 = ctx.r3.s64 + 28052;
	// bl 0x82554798
	ctx.lr = 0x822AF5B4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-9768
	ctx.r4.s64 = r11.s64 + -9768;
	// addi r3,r10,28028
	ctx.r3.s64 = ctx.r10.s64 + 28028;
	// bl 0x82554798
	ctx.lr = 0x822AF5C8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-9752
	ctx.r4.s64 = ctx.r9.s64 + -9752;
	// addi r3,r8,28008
	ctx.r3.s64 = ctx.r8.s64 + 28008;
	// bl 0x82554798
	ctx.lr = 0x822AF5DC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-9704
	ctx.r4.s64 = ctx.r7.s64 + -9704;
	// addi r3,r6,27992
	ctx.r3.s64 = ctx.r6.s64 + 27992;
	// bl 0x82554798
	ctx.lr = 0x822AF5F0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-9680
	ctx.r4.s64 = ctx.r5.s64 + -9680;
	// addi r3,r3,27976
	ctx.r3.s64 = ctx.r3.s64 + 27976;
	// bl 0x82554798
	ctx.lr = 0x822AF604;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-9608
	ctx.r4.s64 = r11.s64 + -9608;
	// addi r3,r10,27956
	ctx.r3.s64 = ctx.r10.s64 + 27956;
	// bl 0x82554798
	ctx.lr = 0x822AF618;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-9520
	ctx.r4.s64 = ctx.r9.s64 + -9520;
	// addi r3,r8,27936
	ctx.r3.s64 = ctx.r8.s64 + 27936;
	// bl 0x82554798
	ctx.lr = 0x822AF62C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-9416
	ctx.r4.s64 = ctx.r7.s64 + -9416;
	// addi r3,r6,27916
	ctx.r3.s64 = ctx.r6.s64 + 27916;
	// bl 0x82554798
	ctx.lr = 0x822AF640;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-9312
	ctx.r4.s64 = ctx.r5.s64 + -9312;
	// addi r3,r3,27892
	ctx.r3.s64 = ctx.r3.s64 + 27892;
	// bl 0x82554798
	ctx.lr = 0x822AF654;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-9240
	ctx.r4.s64 = r11.s64 + -9240;
	// addi r3,r10,27868
	ctx.r3.s64 = ctx.r10.s64 + 27868;
	// bl 0x82554798
	ctx.lr = 0x822AF668;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-9168
	ctx.r4.s64 = ctx.r9.s64 + -9168;
	// addi r3,r8,27836
	ctx.r3.s64 = ctx.r8.s64 + 27836;
	// bl 0x82554798
	ctx.lr = 0x822AF67C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-9080
	ctx.r4.s64 = ctx.r7.s64 + -9080;
	// addi r3,r6,27804
	ctx.r3.s64 = ctx.r6.s64 + 27804;
	// bl 0x82554798
	ctx.lr = 0x822AF690;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-8992
	ctx.r4.s64 = ctx.r5.s64 + -8992;
	// addi r3,r3,27772
	ctx.r3.s64 = ctx.r3.s64 + 27772;
	// bl 0x82554798
	ctx.lr = 0x822AF6A4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-8904
	ctx.r4.s64 = r11.s64 + -8904;
	// addi r3,r10,27752
	ctx.r3.s64 = ctx.r10.s64 + 27752;
	// bl 0x82554798
	ctx.lr = 0x822AF6B8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-8776
	ctx.r4.s64 = ctx.r9.s64 + -8776;
	// addi r3,r8,27728
	ctx.r3.s64 = ctx.r8.s64 + 27728;
	// bl 0x82554798
	ctx.lr = 0x822AF6CC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-8760
	ctx.r4.s64 = ctx.r7.s64 + -8760;
	// addi r3,r6,27704
	ctx.r3.s64 = ctx.r6.s64 + 27704;
	// bl 0x82554798
	ctx.lr = 0x822AF6E0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-8632
	ctx.r4.s64 = ctx.r5.s64 + -8632;
	// addi r3,r3,27684
	ctx.r3.s64 = ctx.r3.s64 + 27684;
	// bl 0x82554798
	ctx.lr = 0x822AF6F4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-8560
	ctx.r4.s64 = r11.s64 + -8560;
	// addi r3,r10,27652
	ctx.r3.s64 = ctx.r10.s64 + 27652;
	// bl 0x82554798
	ctx.lr = 0x822AF708;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-8512
	ctx.r4.s64 = ctx.r9.s64 + -8512;
	// addi r3,r8,27624
	ctx.r3.s64 = ctx.r8.s64 + 27624;
	// bl 0x82554798
	ctx.lr = 0x822AF71C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-8448
	ctx.r4.s64 = ctx.r7.s64 + -8448;
	// addi r3,r6,27604
	ctx.r3.s64 = ctx.r6.s64 + 27604;
	// bl 0x82554798
	ctx.lr = 0x822AF730;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-8304
	ctx.r4.s64 = ctx.r5.s64 + -8304;
	// addi r3,r3,27584
	ctx.r3.s64 = ctx.r3.s64 + 27584;
	// bl 0x82554798
	ctx.lr = 0x822AF744;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-8200
	ctx.r4.s64 = r11.s64 + -8200;
	// addi r3,r10,27560
	ctx.r3.s64 = ctx.r10.s64 + 27560;
	// bl 0x82554798
	ctx.lr = 0x822AF758;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-8080
	ctx.r4.s64 = ctx.r9.s64 + -8080;
	// addi r3,r8,27540
	ctx.r3.s64 = ctx.r8.s64 + 27540;
	// bl 0x82554798
	ctx.lr = 0x822AF76C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-8016
	ctx.r4.s64 = ctx.r7.s64 + -8016;
	// addi r3,r6,27520
	ctx.r3.s64 = ctx.r6.s64 + 27520;
	// bl 0x82554798
	ctx.lr = 0x822AF780;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-7880
	ctx.r4.s64 = ctx.r5.s64 + -7880;
	// addi r3,r3,27492
	ctx.r3.s64 = ctx.r3.s64 + 27492;
	// bl 0x82554798
	ctx.lr = 0x822AF794;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-7744
	ctx.r4.s64 = r11.s64 + -7744;
	// addi r3,r10,27464
	ctx.r3.s64 = ctx.r10.s64 + 27464;
	// bl 0x82554798
	ctx.lr = 0x822AF7A8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-7616
	ctx.r4.s64 = ctx.r9.s64 + -7616;
	// addi r3,r8,27448
	ctx.r3.s64 = ctx.r8.s64 + 27448;
	// bl 0x82554798
	ctx.lr = 0x822AF7BC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-7592
	ctx.r4.s64 = ctx.r7.s64 + -7592;
	// addi r3,r6,27432
	ctx.r3.s64 = ctx.r6.s64 + 27432;
	// bl 0x82554798
	ctx.lr = 0x822AF7D0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-7568
	ctx.r4.s64 = ctx.r5.s64 + -7568;
	// addi r3,r3,27408
	ctx.r3.s64 = ctx.r3.s64 + 27408;
	// bl 0x82554798
	ctx.lr = 0x822AF7E4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-7448
	ctx.r4.s64 = r11.s64 + -7448;
	// addi r3,r10,27376
	ctx.r3.s64 = ctx.r10.s64 + 27376;
	// bl 0x82554798
	ctx.lr = 0x822AF7F8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-7320
	ctx.r4.s64 = ctx.r9.s64 + -7320;
	// addi r3,r8,27352
	ctx.r3.s64 = ctx.r8.s64 + 27352;
	// bl 0x82554798
	ctx.lr = 0x822AF80C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-4000
	ctx.r4.s64 = ctx.r7.s64 + -4000;
	// addi r3,r6,27328
	ctx.r3.s64 = ctx.r6.s64 + 27328;
	// bl 0x82554798
	ctx.lr = 0x822AF820;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-3920
	ctx.r4.s64 = ctx.r5.s64 + -3920;
	// addi r3,r3,27304
	ctx.r3.s64 = ctx.r3.s64 + 27304;
	// bl 0x82554798
	ctx.lr = 0x822AF834;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-7296
	ctx.r4.s64 = r11.s64 + -7296;
	// addi r3,r10,27284
	ctx.r3.s64 = ctx.r10.s64 + 27284;
	// bl 0x82554798
	ctx.lr = 0x822AF848;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-7264
	ctx.r4.s64 = ctx.r9.s64 + -7264;
	// addi r3,r8,27264
	ctx.r3.s64 = ctx.r8.s64 + 27264;
	// bl 0x82554798
	ctx.lr = 0x822AF85C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-7224
	ctx.r4.s64 = ctx.r7.s64 + -7224;
	// addi r3,r6,27248
	ctx.r3.s64 = ctx.r6.s64 + 27248;
	// bl 0x82554798
	ctx.lr = 0x822AF870;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-7184
	ctx.r4.s64 = ctx.r5.s64 + -7184;
	// addi r3,r3,27224
	ctx.r3.s64 = ctx.r3.s64 + 27224;
	// bl 0x82554798
	ctx.lr = 0x822AF884;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-7160
	ctx.r4.s64 = r11.s64 + -7160;
	// addi r3,r10,27204
	ctx.r3.s64 = ctx.r10.s64 + 27204;
	// bl 0x82554798
	ctx.lr = 0x822AF898;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-7112
	ctx.r4.s64 = ctx.r9.s64 + -7112;
	// addi r3,r8,27184
	ctx.r3.s64 = ctx.r8.s64 + 27184;
	// bl 0x82554798
	ctx.lr = 0x822AF8AC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-7064
	ctx.r4.s64 = ctx.r7.s64 + -7064;
	// addi r3,r6,27168
	ctx.r3.s64 = ctx.r6.s64 + 27168;
	// bl 0x82554798
	ctx.lr = 0x822AF8C0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-6920
	ctx.r4.s64 = ctx.r5.s64 + -6920;
	// addi r3,r3,27140
	ctx.r3.s64 = ctx.r3.s64 + 27140;
	// bl 0x82554798
	ctx.lr = 0x822AF8D4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-6880
	ctx.r4.s64 = r11.s64 + -6880;
	// addi r3,r10,27112
	ctx.r3.s64 = ctx.r10.s64 + 27112;
	// bl 0x82554798
	ctx.lr = 0x822AF8E8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-3864
	ctx.r4.s64 = ctx.r9.s64 + -3864;
	// addi r3,r8,27084
	ctx.r3.s64 = ctx.r8.s64 + 27084;
	// bl 0x82554798
	ctx.lr = 0x822AF8FC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-6856
	ctx.r4.s64 = ctx.r7.s64 + -6856;
	// addi r3,r6,27068
	ctx.r3.s64 = ctx.r6.s64 + 27068;
	// bl 0x82554798
	ctx.lr = 0x822AF910;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-6808
	ctx.r4.s64 = ctx.r5.s64 + -6808;
	// addi r3,r3,27052
	ctx.r3.s64 = ctx.r3.s64 + 27052;
	// bl 0x82554798
	ctx.lr = 0x822AF924;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-6728
	ctx.r4.s64 = r11.s64 + -6728;
	// addi r3,r10,27036
	ctx.r3.s64 = ctx.r10.s64 + 27036;
	// bl 0x82554798
	ctx.lr = 0x822AF938;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-6648
	ctx.r4.s64 = ctx.r9.s64 + -6648;
	// addi r3,r8,27012
	ctx.r3.s64 = ctx.r8.s64 + 27012;
	// bl 0x82554798
	ctx.lr = 0x822AF94C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-3848
	ctx.r4.s64 = ctx.r7.s64 + -3848;
	// addi r3,r6,26996
	ctx.r3.s64 = ctx.r6.s64 + 26996;
	// bl 0x82554798
	ctx.lr = 0x822AF960;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-6552
	ctx.r4.s64 = ctx.r5.s64 + -6552;
	// addi r3,r3,26976
	ctx.r3.s64 = ctx.r3.s64 + 26976;
	// bl 0x82554798
	ctx.lr = 0x822AF974;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-3768
	ctx.r4.s64 = r11.s64 + -3768;
	// addi r3,r10,26956
	ctx.r3.s64 = ctx.r10.s64 + 26956;
	// bl 0x82554798
	ctx.lr = 0x822AF988;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,-6464
	ctx.r4.s64 = ctx.r9.s64 + -6464;
	// addi r3,r8,26924
	ctx.r3.s64 = ctx.r8.s64 + 26924;
	// bl 0x82554798
	ctx.lr = 0x822AF99C;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-6448
	ctx.r4.s64 = ctx.r7.s64 + -6448;
	// addi r3,r6,26896
	ctx.r3.s64 = ctx.r6.s64 + 26896;
	// bl 0x82554798
	ctx.lr = 0x822AF9B0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,-6384
	ctx.r4.s64 = ctx.r5.s64 + -6384;
	// addi r3,r3,26880
	ctx.r3.s64 = ctx.r3.s64 + 26880;
	// bl 0x82554798
	ctx.lr = 0x822AF9C4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,-6344
	ctx.r4.s64 = r11.s64 + -6344;
	// addi r3,r10,26860
	ctx.r3.s64 = ctx.r10.s64 + 26860;
	// bl 0x82554798
	ctx.lr = 0x822AF9D8;
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

__attribute__((alias("__imp__sub_822AF9E8"))) PPC_WEAK_FUNC(sub_822AF9E8);
PPC_FUNC_IMPL(__imp__sub_822AF9E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822afa00
	if (cr6.lt) goto loc_822AFA00;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// li r11,1
	r11.s64 = 1;
	// blt cr6,0x822afa04
	if (cr6.lt) goto loc_822AFA04;
loc_822AFA00:
	// li r11,0
	r11.s64 = 0;
loc_822AFA04:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA0C"))) PPC_WEAK_FUNC(sub_822AFA0C);
PPC_FUNC_IMPL(__imp__sub_822AFA0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AFA10"))) PPC_WEAK_FUNC(sub_822AFA10);
PPC_FUNC_IMPL(__imp__sub_822AFA10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r3,r11,80
	ctx.r3.s64 = r11.s64 + 80;
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA30"))) PPC_WEAK_FUNC(sub_822AFA30);
PPC_FUNC_IMPL(__imp__sub_822AFA30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,168(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA40"))) PPC_WEAK_FUNC(sub_822AFA40);
PPC_FUNC_IMPL(__imp__sub_822AFA40) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,180(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 180);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA50"))) PPC_WEAK_FUNC(sub_822AFA50);
PPC_FUNC_IMPL(__imp__sub_822AFA50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,172(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 172);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA60"))) PPC_WEAK_FUNC(sub_822AFA60);
PPC_FUNC_IMPL(__imp__sub_822AFA60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lbz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 92);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822afa78
	if (cr6.eq) goto loc_822AFA78;
	// lfs f1,84(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822AFA78:
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f1,176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 176);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFA84"))) PPC_WEAK_FUNC(sub_822AFA84);
PPC_FUNC_IMPL(__imp__sub_822AFA84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AFA88"))) PPC_WEAK_FUNC(sub_822AFA88);
PPC_FUNC_IMPL(__imp__sub_822AFA88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,80(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822afa9c
	if (cr6.eq) goto loc_822AFA9C;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822afaa8
	if (!cr6.eq) goto loc_822AFAA8;
loc_822AFA9C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	f0.f64 = double(temp.f32);
	// fmuls f2,f2,f0
	ctx.f2.f64 = double(float(ctx.f2.f64 * f0.f64));
loc_822AFAA8:
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// b 0x823147f0
	sub_823147F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822AFAB0"))) PPC_WEAK_FUNC(sub_822AFAB0);
PPC_FUNC_IMPL(__imp__sub_822AFAB0) {
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
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// bl 0x82388580
	ctx.lr = 0x822AFAD8;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// stw r31,80(r30)
	PPC_STORE_U32(r30.u32 + 80, r31.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822afaf4
	if (cr6.lt) goto loc_822AFAF4;
	// bl 0x82387ba0
	ctx.lr = 0x822AFAEC;
	sub_82387BA0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82398568
	ctx.lr = 0x822AFAF4;
	sub_82398568(ctx, base);
loc_822AFAF4:
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

__attribute__((alias("__imp__sub_822AFB0C"))) PPC_WEAK_FUNC(sub_822AFB0C);
PPC_FUNC_IMPL(__imp__sub_822AFB0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AFB10"))) PPC_WEAK_FUNC(sub_822AFB10);
PPC_FUNC_IMPL(__imp__sub_822AFB10) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822AFB18;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// bl 0x82388580
	ctx.lr = 0x822AFB30;
	sub_82388580(ctx, base);
	// lwz r28,8(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x821789d8
	ctx.lr = 0x822AFB38;
	sub_821789D8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822afb50
	if (cr6.eq) goto loc_822AFB50;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r29,17004(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17004);
	// b 0x822afb58
	goto loc_822AFB58;
loc_822AFB50:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r29,17012(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 17012);
loc_822AFB58:
	// bl 0x821789d8
	ctx.lr = 0x822AFB5C;
	sub_821789D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822afb74
	if (cr6.eq) goto loc_822AFB74;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r30,17008(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17008);
	// b 0x822afb7c
	goto loc_822AFB7C;
loc_822AFB74:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r30,17016(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17016);
loc_822AFB7C:
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x822afc98
	if (cr6.eq) goto loc_822AFC98;
	// li r3,992
	ctx.r3.s64 = 992;
	// bl 0x82130528
	ctx.lr = 0x822AFB8C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822afb9c
	if (cr6.eq) goto loc_822AFB9C;
	// bl 0x8217d5e8
	ctx.lr = 0x822AFB98;
	sub_8217D5E8(ctx, base);
	// b 0x822afba0
	goto loc_822AFBA0;
loc_822AFB9C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822AFBA0:
	// stw r3,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r3.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217ce70
	ctx.lr = 0x822AFBB0;
	sub_8217CE70(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lfs f1,29824(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29824);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217ce78
	ctx.lr = 0x822AFBC0;
	sub_8217CE78(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f31,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f2,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x8217d120
	ctx.lr = 0x822AFBEC;
	sub_8217D120(ctx, base);
	// lwz r4,12(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e910
	ctx.lr = 0x822AFBF8;
	sub_8271E910(ctx, base);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r29,r31,44
	r29.s64 = r31.s64 + 44;
	// li r30,5
	r30.s64 = 5;
	// stb r7,92(r6)
	PPC_STORE_U8(ctx.r6.u32 + 92, ctx.r7.u8);
	// lwz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lfs f0,704(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 704);
	f0.f64 = double(temp.f32);
	// stfs f0,88(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 88, temp.u32);
	// lfs f13,708(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 708);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r4)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r4.u32 + 84, temp.u32);
loc_822AFC24:
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC30;
	sub_8271EED8(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// bne 0x822afc24
	if (!cr0.eq) goto loc_822AFC24;
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC48;
	sub_8271EED8(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC54;
	sub_8271EED8(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC60;
	sub_8271EED8(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC6C;
	sub_8271EED8(ctx, base);
	// lwz r4,16(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x8271eed8
	ctx.lr = 0x822AFC78;
	sub_8271EED8(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f4,84(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 84);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,88(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,168(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 168);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8217d460
	ctx.lr = 0x822AFC98;
	sub_8217D460(ctx, base);
loc_822AFC98:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822AFCA4"))) PPC_WEAK_FUNC(sub_822AFCA4);
PPC_FUNC_IMPL(__imp__sub_822AFCA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822AFCA8"))) PPC_WEAK_FUNC(sub_822AFCA8);
PPC_FUNC_IMPL(__imp__sub_822AFCA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822afcc8
	if (cr6.eq) goto loc_822AFCC8;
	// addi r3,r11,80
	ctx.r3.s64 = r11.s64 + 80;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
loc_822AFCC8:
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822AFCD0"))) PPC_WEAK_FUNC(sub_822AFCD0);
PPC_FUNC_IMPL(__imp__sub_822AFCD0) {
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
	PPCRegister f31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822AFCD8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AFD04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822aff04
	if (cr6.eq) goto loc_822AFF04;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822afe44
	if (cr6.eq) goto loc_822AFE44;
	// bl 0x8271eb28
	ctx.lr = 0x822AFD28;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822afd40
	if (cr6.eq) goto loc_822AFD40;
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// beq cr6,0x822afd40
	if (cr6.eq) goto loc_822AFD40;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// bne cr6,0x822aff04
	if (!cr6.eq) goto loc_822AFF04;
loc_822AFD40:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82316148
	ctx.lr = 0x822AFD4C;
	sub_82316148(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822aff04
	if (cr6.eq) goto loc_822AFF04;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x822afd70
	if (!cr6.lt) goto loc_822AFD70;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lfs f31,160(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 160);
	f31.f64 = double(temp.f32);
loc_822AFD70:
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// beq cr6,0x822afe20
	if (cr6.eq) goto loc_822AFE20;
	// cmpwi cr6,r30,14
	cr6.compare<int32_t>(r30.s32, 14, xer);
	// ble cr6,0x822afda0
	if (!cr6.gt) goto loc_822AFDA0;
	// cmpwi cr6,r30,16
	cr6.compare<int32_t>(r30.s32, 16, xer);
	// bgt cr6,0x822afda0
	if (cr6.gt) goto loc_822AFDA0;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e930
	ctx.lr = 0x822AFD94;
	sub_8271E930(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822AFDA0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 592);
	// rlwinm r7,r8,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822aff04
	if (!cr6.eq) goto loc_822AFF04;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822AFDE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32123
	ctx.r8.s64 = -2105212928;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r6,r8,23088
	ctx.r6.s64 = ctx.r8.s64 + 23088;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// ld r7,23088(r8)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r8.u32 + 23088);
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r8,8(r6)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// bl 0x8271e9a0
	ctx.lr = 0x822AFE14;
	sub_8271E9A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822AFE20:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_setzero_si128());
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822AFE44:
	// bl 0x8271eb28
	ctx.lr = 0x822AFE48;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822afef8
	if (cr6.eq) goto loc_822AFEF8;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,784(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 784);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x822afe84
	if (cr6.eq) goto loc_822AFE84;
	// rotlwi r11,r9,0
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r8,784(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// lfs f13,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// mulli r10,r8,112
	ctx.r10.s64 = ctx.r8.s64 * 112;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lfs f0,824(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 824);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x822afe88
	if (cr6.gt) goto loc_822AFE88;
loc_822AFE84:
	// lfs f0,160(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 160);
	f0.f64 = double(temp.f32);
loc_822AFE88:
	// fsel f31,f31,f31,f0
	ctx.fpscr.disableFlushMode();
	f31.f64 = f31.f64 >= 0.0 ? f31.f64 : f0.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,4
	r30.s64 = 4;
	// lfs f0,8884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8884);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x822afea4
	if (!cr6.gt) goto loc_822AFEA4;
	// li r30,3
	r30.s64 = 3;
loc_822AFEA4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822afec0
	if (!cr6.eq) goto loc_822AFEC0;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x8271f230
	ctx.lr = 0x822AFEC0;
	sub_8271F230(ctx, base);
loc_822AFEC0:
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r9,r10,23088
	ctx.r9.s64 = ctx.r10.s64 + 23088;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// addi r8,r11,11
	ctx.r8.s64 = r11.s64 + 11;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// ld r7,23088(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// lwz r4,16(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// rldicr r9,r4,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r4,r6,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// bl 0x8271e9a0
	ctx.lr = 0x822AFEF8;
	sub_8271E9A0(ctx, base);
loc_822AFEF8:
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82316148
	ctx.lr = 0x822AFF04;
	sub_82316148(ctx, base);
loc_822AFF04:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822AFF10"))) PPC_WEAK_FUNC(sub_822AFF10);
PPC_FUNC_IMPL(__imp__sub_822AFF10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,17
	cr6.compare<int32_t>(ctx.r10.s32, 17, xer);
	// beq cr6,0x822b0358
	if (cr6.eq) goto loc_822B0358;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822AFF40;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822affa0
	if (cr6.eq) goto loc_822AFFA0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lbz r9,82(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 82);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822affa0
	if (!cr6.eq) goto loc_822AFFA0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x82562740
	ctx.lr = 0x822AFF70;
	sub_82562740(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822affa0
	if (!cr6.eq) goto loc_822AFFA0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822ab650
	ctx.lr = 0x822AFF84;
	sub_822AB650(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822affb8
	if (cr6.eq) goto loc_822AFFB8;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822ab650
	ctx.lr = 0x822AFF94;
	sub_822AB650(ctx, base);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stw r3,144(r11)
	PPC_STORE_U32(r11.u32 + 144, ctx.r3.u32);
	// b 0x822affb8
	goto loc_822AFFB8;
loc_822AFFA0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r8,r11,304
	ctx.r8.s64 = r11.s64 + 304;
	// stw r8,144(r10)
	PPC_STORE_U32(ctx.r10.u32 + 144, ctx.r8.u32);
loc_822AFFB8:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822AFFCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,208(r8)
	PPC_STORE_U32(ctx.r8.u32 + 208, ctx.r9.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r6,56(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// bne cr6,0x822b000c
	if (!cr6.eq) goto loc_822B000C;
	// rotlwi r3,r7,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// bl 0x8271f3b0
	ctx.lr = 0x822AFFF4;
	sub_8271F3B0(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B000C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B000C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x822B0024;
	sub_822AFCD0(ctx, base);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r8,448
	ctx.r8.s64 = 448;
	// lfs f13,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,304(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 304);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r6,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b0230
	if (cr6.eq) goto loc_822B0230;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b0230
	if (cr6.eq) goto loc_822B0230;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lbz r9,82(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 82);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b0230
	if (!cr6.eq) goto loc_822B0230;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// rlwinm r7,r9,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822b00f8
	if (cr6.eq) goto loc_822B00F8;
loc_822B009C:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B00B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B00C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32123
	ctx.r7.s64 = -2105212928;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r11,r7,23088
	r11.s64 = ctx.r7.s64 + 23088;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r5,3
	ctx.r5.s64 = 3;
	// lfs f1,14884(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	ctx.f1.f64 = double(temp.f32);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// ld r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U64(r11.u32 + 8);
	// rldicr r9,r10,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r7,23088(r7)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r7.u32 + 23088);
	// bl 0x8271e9a0
	ctx.lr = 0x822B00F4;
	sub_8271E9A0(ctx, base);
	// b 0x822b027c
	goto loc_822B027C;
loc_822B00F8:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r10,-6148(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -6148);
	// lbz r9,157(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 157);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b027c
	if (!cr6.eq) goto loc_822B027C;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f12,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x822b009c
	if (!cr6.gt) goto loc_822B009C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r7,0(r13)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lbzx r5,r10,r7
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r7.u32);
	// lvx128 v62,r9,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,128(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 128);
	// beq cr6,0x822b0160
	if (cr6.eq) goto loc_822B0160;
	// addi r11,r11,272
	r11.s64 = r11.s64 + 272;
	// b 0x822b0168
	goto loc_822B0168;
loc_822B0160:
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
loc_822B0168:
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,276(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 276);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f9,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,280(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 280);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f8.f64 = double(temp.f32);
	// li r11,1
	r11.s64 = 1;
	// lfs f7,272(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 272);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f10,f9,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f5,f8,f7,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f7.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bgt cr6,0x822b019c
	if (cr6.gt) goto loc_822B019C;
	// li r11,-1
	r11.s64 = -1;
loc_822B019C:
	// extsw r11,r11
	r11.s64 = r11.s32;
	// lfs f11,304(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// stfs f0,104(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// fmuls f9,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,36(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822B01E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B01FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// addi r6,r10,23088
	ctx.r6.s64 = ctx.r10.s64 + 23088;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r5,3
	ctx.r5.s64 = 3;
	// ld r7,23088(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// lfs f1,-29232(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// ld r8,8(r6)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x8271e9a0
	ctx.lr = 0x822B022C;
	sub_8271E9A0(ctx, base);
	// b 0x822b027c
	goto loc_822B027C;
loc_822B0230:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B0244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B0258;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e930
	ctx.lr = 0x822B0264;
	sub_8271E930(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f3,11360(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,17032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B027C;
	sub_82207EF0(ctx, base);
loc_822B027C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a93a8
	ctx.lr = 0x822B0288;
	sub_822A93A8(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82314790
	ctx.lr = 0x822B0290;
	sub_82314790(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,988
	ctx.r3.s64 = r11.s64 + 988;
	// bl 0x822eb078
	ctx.lr = 0x822B029C;
	sub_822EB078(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b02c0
	if (cr6.eq) goto loc_822B02C0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x821ec468
	ctx.lr = 0x822B02C0;
	sub_821EC468(ctx, base);
loc_822B02C0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lbz r9,82(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 82);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b0310
	if (cr6.eq) goto loc_822B0310;
	// bl 0x82387a18
	ctx.lr = 0x822B02DC;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b02f4
	if (!cr6.eq) goto loc_822B02F4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,1064
	ctx.r3.s64 = r11.s64 + 1064;
	// bl 0x822eb400
	ctx.lr = 0x822B02F4;
	sub_822EB400(ctx, base);
loc_822B02F4:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,208(r11)
	PPC_STORE_U32(r11.u32 + 208, ctx.r10.u32);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f1,216(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 216);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,212(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 212);
	ctx.f2.f64 = double(temp.f32);
	// b 0x822b0330
	goto loc_822B0330;
loc_822B0310:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,592(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// rlwinm r9,r10,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822b0358
	if (cr6.eq) goto loc_822B0358;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f1,216(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 216);
	ctx.f1.f64 = double(temp.f32);
	// lfs f2,212(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 212);
	ctx.f2.f64 = double(temp.f32);
loc_822B0330:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b0344
	if (cr6.eq) goto loc_822B0344;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822b0350
	if (!cr6.eq) goto loc_822B0350;
loc_822B0344:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f0,-12084(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12084);
	f0.f64 = double(temp.f32);
	// fmuls f2,f2,f0
	ctx.f2.f64 = double(float(ctx.f2.f64 * f0.f64));
loc_822B0350:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823147f0
	ctx.lr = 0x822B0358;
	sub_823147F0(ctx, base);
loc_822B0358:
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

__attribute__((alias("__imp__sub_822B036C"))) PPC_WEAK_FUNC(sub_822B036C);
PPC_FUNC_IMPL(__imp__sub_822B036C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B0370"))) PPC_WEAK_FUNC(sub_822B0370);
PPC_FUNC_IMPL(__imp__sub_822B0370) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCRegister f27{};
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
	// bl 0x823db9d4
	ctx.lr = 0x822B0388;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b03b4
	if (cr6.eq) goto loc_822B03B4;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,54320
	ctx.r9.u64 = ctx.r10.u64 | 54320;
	// lbzx r8,r11,r9
	ctx.r8.u64 = PPC_LOAD_U8(r11.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0530
	if (!cr6.eq) goto loc_822B0530;
loc_822B03B4:
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b0530
	if (cr6.eq) goto loc_822B0530;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B03C8;
	sub_82388598(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r31,r11,21384
	r31.s64 = r11.s64 + 21384;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r31,18
	ctx.r8.s64 = r31.s64 + 18;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f30,-28876(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28876);
	f30.f64 = double(temp.f32);
	// lbzx r3,r10,r8
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r8.u32);
	// lfs f29,1068(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 1068);
	f29.f64 = double(temp.f32);
	// lfs f31,14192(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	f31.f64 = double(temp.f32);
	// lfs f27,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f27.f64 = double(temp.f32);
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 - f30.f64));
	// fmuls f0,f11,f29
	f0.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822b0424
	if (!cr6.lt) goto loc_822B0424;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x822b0430
	goto loc_822B0430;
loc_822B0424:
	// fcmpu cr6,f0,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f27.f64);
	// ble cr6,0x822b0430
	if (!cr6.gt) goto loc_822B0430;
	// fmr f0,f27
	f0.f64 = f27.f64;
loc_822B0430:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// lfs f2,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8260c5c8
	ctx.lr = 0x822B0440;
	sub_8260C5C8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// bl 0x82388598
	ctx.lr = 0x822B044C;
	sub_82388598(ctx, base);
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r9,r31,19
	ctx.r9.s64 = r31.s64 + 19;
	// lbzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// fsubs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 - f30.f64));
	// fmuls f0,f11,f29
	f0.f64 = double(float(ctx.f11.f64 * f29.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822b0480
	if (!cr6.lt) goto loc_822B0480;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// b 0x822b048c
	goto loc_822B048C;
loc_822B0480:
	// fcmpu cr6,f0,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f27.f64);
	// ble cr6,0x822b048c
	if (!cr6.gt) goto loc_822B048C;
	// fmr f0,f27
	f0.f64 = f27.f64;
loc_822B048C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// lfs f2,-28880(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28880);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8260c5c8
	ctx.lr = 0x822B049C;
	sub_8260C5C8(ctx, base);
	// lwz r10,128(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,244(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 244);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// rlwinm r8,r11,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822b04e4
	if (cr6.eq) goto loc_822B04E4;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// bne cr6,0x822b04cc
	if (!cr6.eq) goto loc_822B04CC;
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// bgt cr6,0x822b04e0
	if (cr6.gt) goto loc_822B04E0;
loc_822B04CC:
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x822b04e4
	if (!cr6.eq) goto loc_822B04E4;
	// fcmpu cr6,f28,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(f28.f64, f0.f64);
	// bge cr6,0x822b04e4
	if (!cr6.lt) goto loc_822B04E4;
loc_822B04E0:
	// fmr f28,f0
	ctx.fpscr.disableFlushMode();
	f28.f64 = f0.f64;
loc_822B04E4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 192);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,11368(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x822b052c
	if (!cr6.lt) goto loc_822B052C;
	// fcmpu cr6,f28,f0
	cr6.compare(f28.f64, f0.f64);
	// beq cr6,0x822b0530
	if (cr6.eq) goto loc_822B0530;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r11,128(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 128);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// lfs f12,200(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 200);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-31384(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31384);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f11,f0,f28
	ctx.f11.f64 = double(float(f0.f64 * f28.f64));
	// fmadds f10,f11,f13,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f13.f64 + ctx.f12.f64));
	// stfs f10,200(r11)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r11.u32 + 200, temp.u32);
	// b 0x822b0530
	goto loc_822B0530;
loc_822B052C:
	// stfs f0,200(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 200, temp.u32);
loc_822B0530:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// addi r12,r1,-24
	r12.s64 = ctx.r1.s64 + -24;
	// bl 0x823dba20
	ctx.lr = 0x822B053C;
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

__attribute__((alias("__imp__sub_822B0550"))) PPC_WEAK_FUNC(sub_822B0550);
PPC_FUNC_IMPL(__imp__sub_822B0550) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0578
	if (cr6.eq) goto loc_822B0578;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0578;
	sub_8213C218(ctx, base);
loc_822B0578:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b058c
	if (cr6.eq) goto loc_822B058C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B058C;
	sub_8213C218(ctx, base);
loc_822B058C:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b05a0
	if (cr6.eq) goto loc_822B05A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B05A0;
	sub_8213C218(ctx, base);
loc_822B05A0:
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

__attribute__((alias("__imp__sub_822B05B4"))) PPC_WEAK_FUNC(sub_822B05B4);
PPC_FUNC_IMPL(__imp__sub_822B05B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B05B8"))) PPC_WEAK_FUNC(sub_822B05B8);
PPC_FUNC_IMPL(__imp__sub_822B05B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stb r10,101(r31)
	PPC_STORE_U8(r31.u32 + 101, ctx.r10.u8);
	// lfs f0,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_setzero_si128());
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stfs f0,224(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 224, temp.u32);
	// lwz r7,96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// std r6,772(r7)
	PPC_STORE_U64(ctx.r7.u32 + 772, ctx.r6.u64);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0624
	if (cr6.eq) goto loc_822B0624;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0624;
	sub_8213C218(ctx, base);
loc_822B0624:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0638
	if (cr6.eq) goto loc_822B0638;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0638;
	sub_8213C218(ctx, base);
loc_822B0638:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b064c
	if (cr6.eq) goto loc_822B064C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B064C;
	sub_8213C218(ctx, base);
loc_822B064C:
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

__attribute__((alias("__imp__sub_822B0660"))) PPC_WEAK_FUNC(sub_822B0660);
PPC_FUNC_IMPL(__imp__sub_822B0660) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCVRegister v126{};
	PPCVRegister v127{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822B0668;
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823db9c0
	ctx.lr = 0x822B0670;
	// li r12,-160
	r12.s64 = -160;
	// stvx128 v126,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-144
	r12.s64 = -144;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,136(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// lbz r11,908(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// bl 0x822a5578
	ctx.lr = 0x822B06A8;
	sub_822A5578(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r30,116(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b0ee0
	if (cr6.eq) goto loc_822B0EE0;
	// li r4,67
	ctx.r4.s64 = 67;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B06C4;
	sub_822A4BB8(ctx, base);
	// li r4,66
	ctx.r4.s64 = 66;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B06D4;
	sub_822A4BB8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// lfs f30,-332(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -332);
	f30.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B06E8;
	sub_8260C5C8(ctx, base);
	// li r4,64
	ctx.r4.s64 = 64;
	// fmr f26,f1
	ctx.fpscr.disableFlushMode();
	f26.f64 = ctx.f1.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B06F8;
	sub_822A4BB8(ctx, base);
	// li r4,65
	ctx.r4.s64 = 65;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B0708;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B0714;
	sub_8260C5C8(ctx, base);
	// lbz r10,101(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f1.f64;
	// lis r27,-32130
	r27.s64 = -2105671680;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b08a0
	if (!cr6.eq) goto loc_822B08A0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stfs f30,-256(r27)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r27.u32 + -256, temp.u32);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b07d4
	if (cr6.eq) goto loc_822B07D4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b07cc
	if (!cr6.eq) goto loc_822B07CC;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x8271eb28
	ctx.lr = 0x822B0758;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b07cc
	if (!cr6.eq) goto loc_822B07CC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8271f3b0
	ctx.lr = 0x822B076C;
	sub_8271F3B0(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B0784;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r7,48(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r6,56(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplw cr6,r7,r6
	cr6.compare<uint32_t>(ctx.r7.u32, ctx.r6.u32, xer);
	// bne cr6,0x822b07cc
	if (!cr6.eq) goto loc_822B07CC;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x8271eb28
	ctx.lr = 0x822B07A0;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b07cc
	if (!cr6.eq) goto loc_822B07CC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8271f3b0
	ctx.lr = 0x822B07B4;
	sub_8271F3B0(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B07CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B07CC:
	// li r11,1
	r11.s64 = 1;
	// stb r11,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r11.u8);
loc_822B07D4:
	// lbz r11,101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822b08a0
	if (!cr6.eq) goto loc_822B08A0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b081c
	if (!cr6.eq) goto loc_822B081C;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822abca8
	ctx.lr = 0x822B080C;
	sub_822ABCA8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8271e930
	ctx.lr = 0x822B0818;
	sub_8271E930(ctx, base);
	// b 0x822b0878
	goto loc_822B0878;
loc_822B081C:
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b0850
	if (!cr6.eq) goto loc_822B0850;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822abca8
	ctx.lr = 0x822B0840;
	sub_822ABCA8(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// bl 0x8271e930
	ctx.lr = 0x822B084C;
	sub_8271E930(ctx, base);
	// b 0x822b0878
	goto loc_822B0878;
loc_822B0850:
	// lis r11,-32123
	r11.s64 = -2105212928;
	// lwz r4,96(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r10,r11,23088
	ctx.r10.s64 = r11.s64 + 23088;
	// lfs f1,160(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
	// ld r7,23088(r11)
	ctx.r7.u64 = PPC_LOAD_U64(r11.u32 + 23088);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ld r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r10.u32 + 8);
	// rldicr r9,r9,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x8271e9a0
	ctx.lr = 0x822B0878;
	sub_8271E9A0(ctx, base);
loc_822B0878:
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B0884;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b08a0
	if (cr6.eq) goto loc_822B08A0;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,576(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f0,14980(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14980);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 20, temp.u32);
loc_822B08A0:
	// lbz r11,101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// li r4,69
	ctx.r4.s64 = 69;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B08B8;
	sub_822A4BB8(ctx, base);
	// li r4,68
	ctx.r4.s64 = 68;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B08C8;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B08D4;
	sub_8260C5C8(ctx, base);
	// li r4,70
	ctx.r4.s64 = 70;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = ctx.f1.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B08E4;
	sub_822A4BB8(ctx, base);
	// li r4,71
	ctx.r4.s64 = 71;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B08F4;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B0900;
	sub_8260C5C8(ctx, base);
	// li r4,73
	ctx.r4.s64 = 73;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	f29.f64 = ctx.f1.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B0910;
	sub_822A4BB8(ctx, base);
	// li r4,72
	ctx.r4.s64 = 72;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B0920;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fmr f2,f30
	ctx.f2.f64 = f30.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B092C;
	sub_8260C5C8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	f28.f64 = ctx.f1.f64;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f26,f31
	cr6.compare(f26.f64, f31.f64);
	// bne cr6,0x822b0954
	if (!cr6.eq) goto loc_822B0954;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// bne cr6,0x822b0954
	if (!cr6.eq) goto loc_822B0954;
	// fcmpu cr6,f25,f31
	cr6.compare(f25.f64, f31.f64);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822b0958
	if (cr6.eq) goto loc_822B0958;
loc_822B0954:
	// li r11,0
	r11.s64 = 0;
loc_822B0958:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// bne cr6,0x822b0970
	if (!cr6.eq) goto loc_822B0970;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822b0974
	if (cr6.eq) goto loc_822B0974;
loc_822B0970:
	// li r11,1
	r11.s64 = 1;
loc_822B0974:
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x82388598
	ctx.lr = 0x822B0980;
	sub_82388598(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r30,r11,21384
	r30.s64 = r11.s64 + 21384;
	// addi r9,r30,44
	ctx.r9.s64 = r30.s64 + 44;
	// lbzx r8,r10,r9
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b0a24
	if (cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B09A4;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0a24
	if (!cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B09C4;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r8,r9,0,27,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0a24
	if (!cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B09E4;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0a24
	if (!cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B0A04;
	sub_82388598(ctx, base);
	// rlwinm r11,r3,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r30,8
	ctx.r10.s64 = r30.s64 + 8;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b0a24
	if (!cr6.eq) goto loc_822B0A24;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x822B0A24;
	sub_82388598(ctx, base);
loc_822B0A24:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b0a38
	if (cr6.eq) goto loc_822B0A38;
	// stfs f30,-256(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r27.u32 + -256, temp.u32);
	// b 0x822b0a44
	goto loc_822B0A44;
loc_822B0A38:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,-256(r27)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r27.u32 + -256, temp.u32);
loc_822B0A44:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// li r29,16
	r29.s64 = 16;
	// addi r8,r10,29952
	ctx.r8.s64 = ctx.r10.s64 + 29952;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r30,240
	r30.s64 = 240;
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lwz r9,668(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// rlwinm r6,r9,0,26,26
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// lvx128 v127,r11,r30
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r10,r29
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// stvx128 v126,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822b0aa4
	if (cr6.eq) goto loc_822B0AA4;
	// rlwinm r7,r9,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// bne cr6,0x822b0a90
	if (!cr6.eq) goto loc_822B0A90;
	// fcmpu cr6,f27,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f31.f64);
	// blt cr6,0x822b0b1c
	if (cr6.lt) goto loc_822B0B1C;
loc_822B0A90:
	// rlwinm r9,r9,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x822b0aa4
	if (!cr6.eq) goto loc_822B0AA4;
	// fcmpu cr6,f27,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f31.f64);
	// bgt cr6,0x822b0b1c
	if (cr6.gt) goto loc_822B0B1C;
loc_822B0AA4:
	// fcmpu cr6,f27,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f27.f64, f31.f64);
	// beq cr6,0x822b0b20
	if (cr6.eq) goto loc_822B0B20;
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fmuls f11,f0,f27
	ctx.f11.f64 = double(float(f0.f64 * f27.f64));
	// lfs f10,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f10.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f12,-28872(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -28872);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,29940(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29940);
	f0.f64 = double(temp.f32);
	// lfs f13,29936(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 29936);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f27,f11,f12
	f27.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// fadds f9,f10,f27
	ctx.f9.f64 = double(float(ctx.f10.f64 + f27.f64));
	// stfs f9,24(r10)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r10.u32 + 24, temp.u32);
	// lwz r6,96(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r11,576(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 576);
	// lfs f8,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// fsel f6,f7,f8,f0
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsel f5,f7,f8,f0
	ctx.f5.f64 = ctx.f7.f64 >= 0.0 ? ctx.f8.f64 : f0.f64;
	// fsubs f4,f6,f13
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fsel f3,f4,f13,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f13.f64 : ctx.f5.f64;
	// stfs f3,24(r11)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f12,24(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// beq cr6,0x822b0b1c
	if (cr6.eq) goto loc_822B0B1C;
	// fcmpu cr6,f12,f13
	cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bne cr6,0x822b0b20
	if (!cr6.eq) goto loc_822B0B20;
loc_822B0B1C:
	// fmr f27,f31
	ctx.fpscr.disableFlushMode();
	f27.f64 = f31.f64;
loc_822B0B20:
	// lwz r11,668(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822b0b68
	if (cr6.eq) goto loc_822B0B68;
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r9,16
	cr6.compare<int32_t>(ctx.r9.s32, 16, xer);
	// bne cr6,0x822b0b4c
	if (!cr6.eq) goto loc_822B0B4C;
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// ble cr6,0x822b0b4c
	if (!cr6.gt) goto loc_822B0B4C;
	// fmr f26,f31
	f26.f64 = f31.f64;
	// b 0x822b0b90
	goto loc_822B0B90;
loc_822B0B4C:
	// rlwinm r11,r11,0,28,28
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x822b0b68
	if (!cr6.eq) goto loc_822B0B68;
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// bge cr6,0x822b0b68
	if (!cr6.lt) goto loc_822B0B68;
	// fmr f26,f31
	f26.f64 = f31.f64;
	// b 0x822b0b90
	goto loc_822B0B90;
loc_822B0B68:
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// beq cr6,0x822b0b90
	if (cr6.eq) goto loc_822B0B90;
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// fmuls f13,f0,f26
	ctx.f13.f64 = double(float(f0.f64 * f26.f64));
	// lfs f12,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fmuls f26,f13,f0
	f26.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fadds f11,f12,f26
	ctx.f11.f64 = double(float(ctx.f12.f64 + f26.f64));
	// stfs f11,20(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 20, temp.u32);
loc_822B0B90:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822b0c28
	if (!cr6.eq) goto loc_822B0C28;
	// fcmpu cr6,f25,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f25.f64, f31.f64);
	// beq cr6,0x822b0c2c
	if (cr6.eq) goto loc_822B0C2C;
	// lfs f0,88(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fmuls f13,f0,f25
	ctx.f13.f64 = double(float(f0.f64 * f25.f64));
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f0,32668(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32668);
	f0.f64 = double(temp.f32);
	// lfs f12,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f25,f13,f0
	f25.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fadds f11,f25,f12
	ctx.f11.f64 = double(float(f25.f64 + ctx.f12.f64));
	// stfs f11,28(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lfs f9,748(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 748);
	ctx.f9.f64 = double(temp.f32);
	// lwz r11,576(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 576);
	// lfs f10,744(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 744);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fneg f7,f8
	ctx.f7.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// lfs f6,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	ctx.f6.f64 = double(temp.f32);
	// fabs f5,f8
	ctx.f5.u64 = ctx.f8.u64 & ~0x8000000000000000;
	// fsubs f4,f6,f7
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fsel f3,f4,f6,f7
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f6.f64 : ctx.f7.f64;
	// fsubs f2,f3,f8
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f8.f64));
	// fsel f1,f2,f8,f3
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f8.f64 : ctx.f3.f64;
	// stfs f1,28(r11)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r11.u32 + 28, temp.u32);
	// lwz r7,96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r6,576(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 576);
	// lfs f0,28(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	f0.f64 = double(temp.f32);
	// stfs f0,224(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 224, temp.u32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r5,576(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f13,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f5
	cr6.compare(ctx.f12.f64, ctx.f5.f64);
	// bne cr6,0x822b0c2c
	if (!cr6.eq) goto loc_822B0C2C;
loc_822B0C28:
	// fmr f25,f31
	ctx.fpscr.disableFlushMode();
	f25.f64 = f31.f64;
loc_822B0C2C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f10,88(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 88);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,772
	r11.s64 = r11.s64 + 772;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f9,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f9.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fmuls f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// lfs f7,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f6.f64 = double(temp.f32);
	// clrlwi r5,r28,24
	ctx.r5.u64 = r28.u32 & 0xFF;
	// lfs f0,29932(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29932);
	f0.f64 = double(temp.f32);
	// lfs f13,23884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 23884);
	ctx.f13.f64 = double(temp.f32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// lfs f12,29928(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 29928);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,26468(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 26468);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f29,f8,f29
	f29.f64 = double(float(ctx.f8.f64 * f29.f64));
	// fmuls f28,f8,f28
	f28.f64 = double(float(ctx.f8.f64 * f28.f64));
	// fadds f5,f7,f29
	ctx.f5.f64 = double(float(ctx.f7.f64 + f29.f64));
	// fsubs f4,f6,f28
	ctx.f4.f64 = double(float(ctx.f6.f64 - f28.f64));
	// fsubs f3,f5,f0
	ctx.f3.f64 = double(float(ctx.f5.f64 - f0.f64));
	// fsubs f2,f4,f13
	ctx.f2.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fsel f1,f3,f5,f0
	ctx.f1.f64 = ctx.f3.f64 >= 0.0 ? ctx.f5.f64 : f0.f64;
	// fsel f13,f2,f4,f13
	ctx.f13.f64 = ctx.f2.f64 >= 0.0 ? ctx.f4.f64 : ctx.f13.f64;
	// fsubs f8,f1,f12
	ctx.f8.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// fsubs f7,f13,f11
	ctx.f7.f64 = double(float(ctx.f13.f64 - ctx.f11.f64));
	// fsel f0,f8,f12,f1
	f0.f64 = ctx.f8.f64 >= 0.0 ? ctx.f12.f64 : ctx.f1.f64;
	// fsel f13,f7,f11,f13
	ctx.f13.f64 = ctx.f7.f64 >= 0.0 ? ctx.f11.f64 : ctx.f13.f64;
	// beq cr6,0x822b0cbc
	if (cr6.eq) goto loc_822B0CBC;
	// fmuls f11,f13,f9
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f9.f64));
	// fmuls f12,f0,f9
	ctx.f12.f64 = double(float(f0.f64 * ctx.f9.f64));
	// fmuls f8,f11,f10
	ctx.f8.f64 = double(float(ctx.f11.f64 * ctx.f10.f64));
	// fmuls f9,f12,f10
	ctx.f9.f64 = double(float(ctx.f12.f64 * ctx.f10.f64));
	// fsubs f13,f13,f8
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f8.f64));
	// fsubs f0,f0,f9
	f0.f64 = double(float(f0.f64 - ctx.f9.f64));
loc_822B0CBC:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,0(r11)
	PPC_STORE_U64(r11.u32 + 0, ctx.r9.u64);
	// lfd f0,29920(r10)
	f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 29920);
	// fabs f11,f0
	ctx.f11.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bne cr6,0x822b0ce8
	if (!cr6.eq) goto loc_822B0CE8;
	// fmr f29,f31
	f29.f64 = f31.f64;
loc_822B0CE8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// fabs f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// lfd f0,3456(r11)
	f0.u64 = PPC_LOAD_U64(r11.u32 + 3456);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bne cr6,0x822b0d04
	if (!cr6.eq) goto loc_822B0D04;
	// fmr f28,f31
	f28.f64 = f31.f64;
loc_822B0D04:
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r9,144(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 144);
	// lfd f2,29912(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f2.u64 = PPC_LOAD_U64(ctx.r10.u32 + 29912);
	// lfs f1,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823dc480
	ctx.lr = 0x822B0D1C;
	sub_823DC480(ctx, base);
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// frsp f24,f1
	ctx.fpscr.disableFlushMode();
	f24.f64 = double(float(ctx.f1.f64));
	// lwz r7,576(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 576);
	// lfs f23,20(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	f23.f64 = double(temp.f32);
	// lfs f30,24(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	f30.f64 = double(temp.f32);
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// bl 0x823dbae8
	ctx.lr = 0x822B0D38;
	sub_823DBAE8(ctx, base);
	// frsp f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822B0D44;
	sub_823DBBC8(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// fmr f1,f23
	ctx.f1.f64 = f23.f64;
	// lfs f0,17032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f22
	ctx.f12.f64 = double(float(ctx.f13.f64 * f22.f64));
	// fmuls f11,f12,f24
	ctx.f11.f64 = double(float(ctx.f12.f64 * f24.f64));
	// fmuls f23,f11,f0
	f23.f64 = double(float(ctx.f11.f64 * f0.f64));
	// bl 0x823dbbc8
	ctx.lr = 0x822B0D64;
	sub_823DBBC8(ctx, base);
	// frsp f22,f1
	ctx.fpscr.disableFlushMode();
	f22.f64 = double(float(ctx.f1.f64));
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// bl 0x823dbbc8
	ctx.lr = 0x822B0D70;
	sub_823DBBC8(ctx, base);
	// lwz r5,96(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// frsp f10,f1
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f1.f64));
	// lwz r4,576(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 576);
	// stfs f31,16(r4)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r4.u32 + 16, temp.u32);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stfs f23,240(r3)
	temp.f32 = float(f23.f64);
	PPC_STORE_U32(ctx.r3.u32 + 240, temp.u32);
	// fmuls f9,f10,f22
	ctx.f9.f64 = double(float(ctx.f10.f64 * f22.f64));
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// fmuls f8,f9,f24
	ctx.f8.f64 = double(float(ctx.f9.f64 * f24.f64));
	// stfs f8,248(r11)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r11.u32 + 248, temp.u32);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r28,668(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 668);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B0DB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x822b0de8
	if (!cr6.eq) goto loc_822B0DE8;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822b0de8
	if (cr6.eq) goto loc_822B0DE8;
	// stvx128 v127,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// stvx128 v126,r10,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	f0.f64 = double(temp.f32);
	// stfs f0,224(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 224, temp.u32);
loc_822B0DE8:
	// fcmpu cr6,f26,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f26.f64, f31.f64);
	// bne cr6,0x822b0e20
	if (!cr6.eq) goto loc_822B0E20;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// bne cr6,0x822b0e20
	if (!cr6.eq) goto loc_822B0E20;
	// fcmpu cr6,f29,f31
	cr6.compare(f29.f64, f31.f64);
	// bne cr6,0x822b0e20
	if (!cr6.eq) goto loc_822B0E20;
	// fcmpu cr6,f28,f31
	cr6.compare(f28.f64, f31.f64);
	// bne cr6,0x822b0e20
	if (!cr6.eq) goto loc_822B0E20;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0e3c
	if (cr6.eq) goto loc_822B0E3C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0E1C;
	sub_8213C218(ctx, base);
	// b 0x822b0e3c
	goto loc_822B0E3C;
loc_822B0E20:
	// lwz r11,144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// addi r4,r31,144
	ctx.r4.s64 = r31.s64 + 144;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b0e3c
	if (!cr6.eq) goto loc_822B0E3C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,29888
	ctx.r3.s64 = r11.s64 + 29888;
	// bl 0x821e6810
	ctx.lr = 0x822B0E3C;
	sub_821E6810(ctx, base);
loc_822B0E3C:
	// fcmpu cr6,f25,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f25.f64, f31.f64);
	// ble cr6,0x822b0e78
	if (!cr6.gt) goto loc_822B0E78;
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0e58
	if (cr6.eq) goto loc_822B0E58;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0E58;
	sub_8213C218(ctx, base);
loc_822B0E58:
	// lwz r11,152(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// addi r4,r31,152
	ctx.r4.s64 = r31.s64 + 152;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,29864
	ctx.r3.s64 = r11.s64 + 29864;
	// bl 0x821e6810
	ctx.lr = 0x822B0E74;
	sub_821E6810(ctx, base);
	// b 0x822b0ef0
	goto loc_822B0EF0;
loc_822B0E78:
	// fcmpu cr6,f25,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(f25.f64, f31.f64);
	// bge cr6,0x822b0eb4
	if (!cr6.lt) goto loc_822B0EB4;
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0e94
	if (cr6.eq) goto loc_822B0E94;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0E94;
	sub_8213C218(ctx, base);
loc_822B0E94:
	// lwz r11,148(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// addi r4,r31,148
	ctx.r4.s64 = r31.s64 + 148;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b0ef0
	if (!cr6.eq) goto loc_822B0EF0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,29840
	ctx.r3.s64 = r11.s64 + 29840;
	// bl 0x821e6810
	ctx.lr = 0x822B0EB0;
	sub_821E6810(ctx, base);
	// b 0x822b0ef0
	goto loc_822B0EF0;
loc_822B0EB4:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0ec8
	if (cr6.eq) goto loc_822B0EC8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0EC8;
	sub_8213C218(ctx, base);
loc_822B0EC8:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b0ef0
	if (cr6.eq) goto loc_822B0EF0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B0EDC;
	sub_8213C218(ctx, base);
	// b 0x822b0ef0
	goto loc_822B0EF0;
loc_822B0EE0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f0,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,-256(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + -256, temp.u32);
loc_822B0EF0:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-160
	r0.s64 = -160;
	// lvx128 v126,r1,r0
	simde_mm_store_si128((simde__m128i*)v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-144
	r0.s64 = -144;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-48
	r12.s64 = ctx.r1.s64 + -48;
	// bl 0x823dba0c
	ctx.lr = 0x822B0F0C;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822B0F10"))) PPC_WEAK_FUNC(sub_822B0F10);
PPC_FUNC_IMPL(__imp__sub_822B0F10) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822b0f50
	if (!cr6.eq) goto loc_822B0F50;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822B0F50:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82351cb0
	ctx.lr = 0x822B0F58;
	sub_82351CB0(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822b0fa0
	if (!cr6.eq) goto loc_822B0FA0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822abca8
	ctx.lr = 0x822B0F7C;
	sub_822ABCA8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B0F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822b0fe8
	goto loc_822B0FE8;
loc_822B0FA0:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// bne cr6,0x822b0fdc
	if (!cr6.eq) goto loc_822B0FDC;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x822abca8
	ctx.lr = 0x822B0FB8;
	sub_822ABCA8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B0FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822b0fe8
	goto loc_822B0FE8;
loc_822B0FDC:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x822abca8
	ctx.lr = 0x822B0FE8;
	sub_822ABCA8(ctx, base);
loc_822B0FE8:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-228
	ctx.r6.s64 = ctx.r10.s64 + -228;
	// addi r5,r9,-252
	ctx.r5.s64 = ctx.r9.s64 + -252;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x823dedd8
	ctx.lr = 0x822B100C;
	sub_823DEDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822b1038
	if (cr6.eq) goto loc_822B1038;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,72(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 72);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B1038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B1038:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x822b105c
	if (!cr6.eq) goto loc_822B105C;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x8271e930
	ctx.lr = 0x822B1058;
	sub_8271E930(ctx, base);
	// b 0x822b10c8
	goto loc_822B10C8;
loc_822B105C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// ld r7,23088(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x822b10a0
	if (!cr6.gt) goto loc_822B10A0;
	// addi r9,r10,23088
	ctx.r9.s64 = ctx.r10.s64 + 23088;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// addi r8,r11,11
	ctx.r8.s64 = r11.s64 + 11;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,16(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// rldicr r9,r4,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwzx r4,r6,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// b 0x822b10c4
	goto loc_822B10C4;
loc_822B10A0:
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// addi r8,r10,23088
	ctx.r8.s64 = ctx.r10.s64 + 23088;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,16(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// lwzx r11,r6,r31
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// rldicr r9,r4,32,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// ld r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lfs f1,160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 160);
	ctx.f1.f64 = double(temp.f32);
loc_822B10C4:
	// bl 0x8271e9a0
	ctx.lr = 0x822B10C8;
	sub_8271E9A0(ctx, base);
loc_822B10C8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a93a8
	ctx.lr = 0x822B10D4;
	sub_822A93A8(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// addi r3,r10,29944
	ctx.r3.s64 = ctx.r10.s64 + 29944;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r8,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82130000
	ctx.lr = 0x822B10F4;
	sub_82130000(ctx, base);
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

__attribute__((alias("__imp__sub_822B1110"))) PPC_WEAK_FUNC(sub_822B1110);
PPC_FUNC_IMPL(__imp__sub_822B1110) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B1140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r4,68(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B1158;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r4,72(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B116C;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r4,84(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 84);
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B1180;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x8271eef0
	ctx.lr = 0x822B1194;
	sub_8271EEF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lwz r31,80(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// lis r11,26214
	r11.s64 = 1717960704;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// ori r8,r11,26215
	ctx.r8.u64 = r11.u64 | 26215;
loc_822B11AC:
	// addic. r11,r4,-1
	xer.ca = ctx.r4.u32 > 0;
	r11.s64 = ctx.r4.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// li r9,5
	ctx.r9.s64 = 5;
	// blt 0x822b11bc
	if (cr0.lt) goto loc_822B11BC;
	// li r9,0
	ctx.r9.s64 = 0;
loc_822B11BC:
	// mr r7,r11
	ctx.r7.u64 = r11.u64;
	// mulhw r6,r7,r8
	ctx.r6.s64 = (int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32)) >> 32;
	// srawi r11,r6,1
	xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	r11.s64 = ctx.r6.s32 >> 1;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r11,r10
	ctx.r5.u64 = r11.u64 + ctx.r10.u64;
	// subf r11,r5,r7
	r11.s64 = ctx.r7.s64 - ctx.r5.s64;
	// add. r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// beq 0x822b11ac
	if (cr0.eq) goto loc_822B11AC;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x822b11ac
	if (cr6.eq) goto loc_822B11AC;
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// beq cr6,0x822b11ac
	if (cr6.eq) goto loc_822B11AC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822afab0
	ctx.lr = 0x822B11FC;
	sub_822AFAB0(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x822b1224
	if (cr6.eq) goto loc_822B1224;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// beq cr6,0x822b1224
	if (cr6.eq) goto loc_822B1224;
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b1224
	if (cr6.eq) goto loc_822B1224;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r31,3
	r31.s64 = 3;
	// bne cr6,0x822b1228
	if (!cr6.eq) goto loc_822B1228;
loc_822B1224:
	// li r31,4
	r31.s64 = 4;
loc_822B1228:
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r30
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B1248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f1,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822B125C;
	sub_822B0F10(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-12252(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12252);
	// bl 0x821ec4e8
	ctx.lr = 0x822B1268;
	sub_821EC4E8(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// addi r4,r5,17840
	ctx.r4.s64 = ctx.r5.s64 + 17840;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b1294
	if (!cr6.eq) goto loc_822B1294;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B1294;
	sub_82207EF0(ctx, base);
loc_822B1294:
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

__attribute__((alias("__imp__sub_822B12AC"))) PPC_WEAK_FUNC(sub_822B12AC);
PPC_FUNC_IMPL(__imp__sub_822B12AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B12B0"))) PPC_WEAK_FUNC(sub_822B12B0);
PPC_FUNC_IMPL(__imp__sub_822B12B0) {
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
	ctx.lr = 0x822B12B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x822B12C4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822b12d8
	if (!cr6.eq) goto loc_822B12D8;
loc_822B12CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822B12D8:
	// lwz r4,72(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 72);
	// lwz r3,16(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B12E4;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b12cc
	if (!cr6.eq) goto loc_822B12CC;
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b12cc
	if (cr6.eq) goto loc_822B12CC;
	// lwz r31,48(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822b12cc
	if (cr6.eq) goto loc_822B12CC;
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b12cc
	if (cr6.eq) goto loc_822B12CC;
	// lwz r11,592(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 592);
	// rlwinm r10,r11,0,26,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3C;
	// rlwinm r10,r10,0,29,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b136c
	if (cr6.eq) goto loc_822B136C;
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,17
	cr6.compare<int32_t>(ctx.r10.s32, 17, xer);
	// beq cr6,0x822b136c
	if (cr6.eq) goto loc_822B136C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82332098
	ctx.lr = 0x822B133C;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b136c
	if (cr6.eq) goto loc_822B136C;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lbz r10,82(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 82);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b136c
	if (!cr6.eq) goto loc_822B136C;
	// lwz r3,12(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// bl 0x82562740
	ctx.lr = 0x822B1360;
	sub_82562740(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b12cc
	if (cr6.eq) goto loc_822B12CC;
loc_822B136C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r3,r10,26,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B1384"))) PPC_WEAK_FUNC(sub_822B1384);
PPC_FUNC_IMPL(__imp__sub_822B1384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B1388"))) PPC_WEAK_FUNC(sub_822B1388);
PPC_FUNC_IMPL(__imp__sub_822B1388) {
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
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b13cc
	if (cr6.eq) goto loc_822B13CC;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b13cc
	if (cr6.eq) goto loc_822B13CC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B13BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b13d0
	if (!cr6.eq) goto loc_822B13D0;
loc_822B13CC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822B13D0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B13E0"))) PPC_WEAK_FUNC(sub_822B13E0);
PPC_FUNC_IMPL(__imp__sub_822B13E0) {
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
	// lwz r4,132(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B13F8;
	sub_8271EB28(ctx, base);
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

__attribute__((alias("__imp__sub_822B1414"))) PPC_WEAK_FUNC(sub_822B1414);
PPC_FUNC_IMPL(__imp__sub_822B1414) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B1418"))) PPC_WEAK_FUNC(sub_822B1418);
PPC_FUNC_IMPL(__imp__sub_822B1418) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b1458
	if (cr6.eq) goto loc_822B1458;
	// lbz r11,157(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 157);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b1458
	if (cr6.eq) goto loc_822B1458;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,132(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
	// stw r8,144(r10)
	PPC_STORE_U32(ctx.r10.u32 + 144, ctx.r8.u32);
	// lwz r4,132(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// b 0x8271e930
	sub_8271E930(ctx, base);
	return;
loc_822B1458:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,3
	ctx.r4.s64 = 3;
	// lfs f1,-15468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -15468);
	ctx.f1.f64 = double(temp.f32);
	// b 0x822b0f10
	sub_822B0F10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B1468"))) PPC_WEAK_FUNC(sub_822B1468);
PPC_FUNC_IMPL(__imp__sub_822B1468) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,128(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// addis r9,r11,1
	ctx.r9.s64 = r11.s64 + 65536;
	// addi r9,r9,-10992
	ctx.r9.s64 = ctx.r9.s64 + -10992;
	// stw r9,144(r10)
	PPC_STORE_U32(ctx.r10.u32 + 144, ctx.r9.u32);
	// lwz r4,128(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// b 0x8271e930
	sub_8271E930(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B148C"))) PPC_WEAK_FUNC(sub_822B148C);
PPC_FUNC_IMPL(__imp__sub_822B148C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B1490"))) PPC_WEAK_FUNC(sub_822B1490);
PPC_FUNC_IMPL(__imp__sub_822B1490) {
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
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b1584
	if (cr6.eq) goto loc_822B1584;
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r11,124(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// stb r9,120(r3)
	PPC_STORE_U8(ctx.r3.u32 + 120, ctx.r9.u8);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplw cr6,r8,r11
	cr6.compare<uint32_t>(ctx.r8.u32, r11.u32, xer);
	// beq cr6,0x822b159c
	if (cr6.eq) goto loc_822B159C;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// li r6,16
	ctx.r6.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// lwz r10,-17936(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -17936);
	// li r8,48
	ctx.r8.s64 = 48;
	// lwz r9,-8092(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8092);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// addi r4,r10,3
	ctx.r4.s64 = ctx.r10.s64 + 3;
	// lis r31,-32253
	r31.s64 = -2113732608;
	// rlwinm r10,r4,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 6) & 0xFFFFFFC0;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfs f0,29976(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 29976);
	f0.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r8
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,124(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// stfs f0,192(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 192, temp.u32);
	// lwz r10,124(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// lfs f0,29972(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 29972);
	f0.f64 = double(temp.f32);
	// stfs f0,196(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 196, temp.u32);
	// lwz r8,124(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// lfs f0,29968(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 29968);
	f0.f64 = double(temp.f32);
	// stfs f0,200(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 200, temp.u32);
	// lwz r7,124(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// lfs f0,29964(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29964);
	f0.f64 = double(temp.f32);
	// stfs f0,204(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 204, temp.u32);
	// lwz r6,124(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// lfs f0,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,208(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 208, temp.u32);
	// lwz r4,124(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 124);
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x8271e930
	ctx.lr = 0x822B1570;
	sub_8271E930(ctx, base);
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
loc_822B1584:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stb r11,120(r3)
	PPC_STORE_U8(ctx.r3.u32 + 120, r11.u8);
	// li r4,3
	ctx.r4.s64 = 3;
	// lfs f1,-32032(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -32032);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822B159C;
	sub_822B0F10(ctx, base);
loc_822B159C:
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

__attribute__((alias("__imp__sub_822B15B0"))) PPC_WEAK_FUNC(sub_822B15B0);
PPC_FUNC_IMPL(__imp__sub_822B15B0) {
	PPC_FUNC_PROLOGUE();
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
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r6,r10,23088
	ctx.r6.s64 = ctx.r10.s64 + 23088;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lfs f1,-32032(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -32032);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,48(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,28(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// stw r3,144(r9)
	PPC_STORE_U32(ctx.r9.u32 + 144, ctx.r3.u32);
	// ld r7,23088(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// ld r8,8(r6)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r6.u32 + 8);
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// bl 0x8271e9a0
	ctx.lr = 0x822B160C;
	sub_8271E9A0(ctx, base);
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x822abca8
	ctx.lr = 0x822B1624;
	sub_822ABCA8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a93a8
	ctx.lr = 0x822B1630;
	sub_822A93A8(ctx, base);
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

__attribute__((alias("__imp__sub_822B1644"))) PPC_WEAK_FUNC(sub_822B1644);
PPC_FUNC_IMPL(__imp__sub_822B1644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B1648"))) PPC_WEAK_FUNC(sub_822B1648);
PPC_FUNC_IMPL(__imp__sub_822B1648) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822B1650;
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -88, f29.u64);
	// stfd f30,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// bl 0x822a8d98
	ctx.lr = 0x822B1674;
	sub_822A8D98(ctx, base);
	// bl 0x82396408
	ctx.lr = 0x822B1678;
	sub_82396408(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r26,48(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r11,-12120(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12120);
	// lwz r29,0(r9)
	r29.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lis r7,-32129
	ctx.r7.s64 = -2105606144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r6,r7,-25924
	ctx.r6.s64 = ctx.r7.s64 + -25924;
	// addi r28,r31,44
	r28.s64 = r31.s64 + 44;
	// lwz r5,24(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r27,r4,r6
	r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r6.u32);
	// bl 0x822a8d98
	ctx.lr = 0x822B16B4;
	sub_822A8D98(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r11,30092
	ctx.r5.s64 = r11.s64 + 30092;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822B16CC;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B16E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r29,-32256
	r29.s64 = -2113929216;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// stfs f0,172(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 172, temp.u32);
	// lwz r25,48(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r26,0(r8)
	r26.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x822a8d98
	ctx.lr = 0x822B1708;
	sub_822A8D98(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r7,30084
	ctx.r5.s64 = ctx.r7.s64 + 30084;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822B1720;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r6,76(r26)
	ctx.r6.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822B1738;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r4,48(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f30,17032(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	f30.f64 = double(temp.f32);
	// stfs f30,172(r4)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r4.u32 + 172, temp.u32);
	// lwz r25,48(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r26,0(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x822a8d98
	ctx.lr = 0x822B175C;
	sub_822A8D98(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,30072
	ctx.r5.s64 = ctx.r10.s64 + 30072;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822B1774;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r9,76(r26)
	ctx.r9.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B178C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lwz r7,56(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f0,172(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 172, temp.u32);
	// lwz r25,48(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r26,0(r7)
	r26.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// bl 0x822a8d98
	ctx.lr = 0x822B17AC;
	sub_822A8D98(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r5,30060
	ctx.r5.s64 = ctx.r5.s64 + 30060;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822B17C4;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,76(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B17DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lwz r9,60(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f0,172(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 172, temp.u32);
	// lwz r25,48(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r26,0(r9)
	r26.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x822a8d98
	ctx.lr = 0x822B17FC;
	sub_822A8D98(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r8,30048
	ctx.r5.s64 = ctx.r8.s64 + 30048;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822B1814;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r7,76(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822B182C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,60(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stfs f0,172(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 172, temp.u32);
	// lwz r25,48(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r26,0(r5)
	r26.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// bl 0x822a8d98
	ctx.lr = 0x822B184C;
	sub_822A8D98(ctx, base);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r4,30036
	ctx.r5.s64 = ctx.r4.s64 + 30036;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822B1864;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,76(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B187C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,240(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 240);
	// stfs f0,172(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 172, temp.u32);
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stfs f31,128(r7)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r7.u32 + 128, temp.u32);
	// lwz r26,0(r8)
	r26.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r25,48(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// bl 0x822a8d98
	ctx.lr = 0x822B18AC;
	sub_822A8D98(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r5,30020
	ctx.r5.s64 = ctx.r5.s64 + 30020;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822B18C4;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,76(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B18DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// lwz r9,84(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r5,r10,30008
	ctx.r5.s64 = ctx.r10.s64 + 30008;
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,172(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 172, temp.u32);
	// lwz r25,48(r30)
	r25.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r26,0(r8)
	r26.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x82137a08
	ctx.lr = 0x822B190C;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r7,76(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822B1924;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f31,100(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,172(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 172, temp.u32);
	// stfs f30,488(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 488, temp.u32);
	// stfs f30,496(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 496, temp.u32);
	// lfs f29,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f29.f64 = double(temp.f32);
	// lfs f13,3732(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// stfs f29,500(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 500, temp.u32);
	// stfs f13,504(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 504, temp.u32);
	// lfs f12,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,472(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 472, temp.u32);
	// stfs f12,476(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 476, temp.u32);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b19a8
	if (cr6.eq) goto loc_822B19A8;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x8232c638
	ctx.lr = 0x822B1980;
	sub_8232C638(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,32
	ctx.r9.s64 = 32;
	// lfs f0,-13148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13148);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v63,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v63.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// b 0x822b19b0
	goto loc_822B19B0;
loc_822B19A8:
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822B19B0:
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// li r10,240
	ctx.r10.s64 = 240;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// addi r5,r9,29996
	ctx.r5.s64 = ctx.r9.s64 + 29996;
	// li r4,64
	ctx.r4.s64 = 64;
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwz r26,48(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r27,0(r8)
	r27.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// bl 0x82137a08
	ctx.lr = 0x822B19E0;
	sub_82137A08(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r7,76(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 76);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822B19F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// li r27,0
	r27.s64 = 0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stfs f0,172(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 172, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f13,-32032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -32032);
	ctx.f13.f64 = double(temp.f32);
	// li r4,3
	ctx.r4.s64 = 3;
	// stfs f13,160(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 160, temp.u32);
	// stw r27,256(r9)
	PPC_STORE_U32(ctx.r9.u32 + 256, r27.u32);
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lfs f12,-11624(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -11624);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,744(r8)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r8.u32 + 744, temp.u32);
	// lfs f11,31304(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31304);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,748(r8)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r8.u32 + 748, temp.u32);
	// stfs f31,736(r8)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 736, temp.u32);
	// lfs f10,-6172(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6172);
	ctx.f10.f64 = double(temp.f32);
	// stfs f31,740(r8)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 740, temp.u32);
	// stfs f10,468(r8)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r8.u32 + 468, temp.u32);
	// stfs f0,472(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 472, temp.u32);
	// stb r10,184(r8)
	PPC_STORE_U8(ctx.r8.u32 + 184, ctx.r10.u8);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,68(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822B1A6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// lwz r9,96(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lwz r8,128(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r10,3
	ctx.r10.s64 = 3;
	// lfs f13,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,25088(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 25088);
	f0.f64 = double(temp.f32);
	// stfs f0,756(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 756, temp.u32);
	// stfs f29,760(r9)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r9.u32 + 760, temp.u32);
	// stfs f13,172(r8)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r8.u32 + 172, temp.u32);
	// stw r10,240(r8)
	PPC_STORE_U32(ctx.r8.u32 + 240, ctx.r10.u32);
	// lwz r7,128(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// lfs f12,29992(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 29992);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-1684(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,252(r7)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r7.u32 + 252, temp.u32);
	// stfs f11,256(r7)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r7.u32 + 256, temp.u32);
	// bl 0x822a8d98
	ctx.lr = 0x822B1AB8;
	sub_822A8D98(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r5,29980
	ctx.r5.s64 = ctx.r5.s64 + 29980;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82137a08
	ctx.lr = 0x822B1AD0;
	sub_82137A08(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r7,64(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r5,16(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// bl 0x82317f60
	ctx.lr = 0x822B1AEC;
	sub_82317F60(ctx, base);
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f0,172(r4)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r4.u32 + 172, temp.u32);
	// lwz r4,48(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B1B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,68(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lfs f0,31308(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 31308);
	f0.f64 = double(temp.f32);
	// stfs f0,172(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 172, temp.u32);
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b1b44
	if (cr6.eq) goto loc_822B1B44;
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// bl 0x82337a48
	ctx.lr = 0x822B1B34;
	sub_82337A48(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x822b1b44
	if (!cr6.eq) goto loc_822B1B44;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r27,200(r11)
	PPC_STORE_U32(r11.u32 + 200, r27.u32);
loc_822B1B44:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
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

__attribute__((alias("__imp__sub_822B1B58"))) PPC_WEAK_FUNC(sub_822B1B58);
PPC_FUNC_IMPL(__imp__sub_822B1B58) {
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
	// bl 0x823d91f0
	ctx.lr = 0x822B1B60;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823db9cc
	ctx.lr = 0x822B1B68;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,30128
	ctx.r10.s64 = r11.s64 + 30128;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// stw r4,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r4.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r26,136(r4)
	r26.u64 = PPC_LOAD_U32(ctx.r4.u32 + 136);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82388580
	ctx.lr = 0x822B1B90;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822b1ba8
	if (cr6.lt) goto loc_822B1BA8;
	// bl 0x82387ba0
	ctx.lr = 0x822B1BA0;
	sub_82387BA0(ctx, base);
	// bl 0x82618670
	ctx.lr = 0x822B1BA4;
	sub_82618670(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
loc_822B1BA8:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82388580
	ctx.lr = 0x822B1BB0;
	sub_82388580(ctx, base);
	// bl 0x82398698
	ctx.lr = 0x822B1BB4;
	sub_82398698(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// li r3,672
	ctx.r3.s64 = 672;
	// stb r29,91(r31)
	PPC_STORE_U8(r31.u32 + 91, r29.u8);
	// stb r29,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r29.u8);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// stb r29,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r29.u8);
	// stfs f31,108(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stb r29,93(r31)
	PPC_STORE_U8(r31.u32 + 93, r29.u8);
	// stfs f31,112(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stb r29,120(r31)
	PPC_STORE_U8(r31.u32 + 120, r29.u8);
	// stfs f31,116(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stb r29,92(r31)
	PPC_STORE_U8(r31.u32 + 92, r29.u8);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1BF0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1c04
	if (cr6.eq) goto loc_822B1C04;
	// bl 0x823216f8
	ctx.lr = 0x822B1BFC;
	sub_823216F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822b1c08
	goto loc_822B1C08;
loc_822B1C04:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B1C08:
	// li r27,1
	r27.s64 = 1;
	// li r28,768
	r28.s64 = 768;
	// stb r27,668(r11)
	PPC_STORE_U8(r11.u32 + 668, r27.u8);
	// li r3,672
	ctx.r3.s64 = 672;
	// stw r28,200(r11)
	PPC_STORE_U32(r11.u32 + 200, r28.u32);
	// stw r11,44(r31)
	PPC_STORE_U32(r31.u32 + 44, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1C24;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1c38
	if (cr6.eq) goto loc_822B1C38;
	// bl 0x823216f8
	ctx.lr = 0x822B1C30;
	sub_823216F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822b1c3c
	goto loc_822B1C3C;
loc_822B1C38:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B1C3C:
	// stb r27,668(r11)
	PPC_STORE_U8(r11.u32 + 668, r27.u8);
	// li r3,672
	ctx.r3.s64 = 672;
	// stw r28,200(r11)
	PPC_STORE_U32(r11.u32 + 200, r28.u32);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1C50;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1c64
	if (cr6.eq) goto loc_822B1C64;
	// bl 0x823216f8
	ctx.lr = 0x822B1C5C;
	sub_823216F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822b1c68
	goto loc_822B1C68;
loc_822B1C64:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B1C68:
	// stw r28,200(r11)
	PPC_STORE_U32(r11.u32 + 200, r28.u32);
	// li r3,672
	ctx.r3.s64 = 672;
	// stw r11,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1C78;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1c8c
	if (cr6.eq) goto loc_822B1C8C;
	// bl 0x823216f8
	ctx.lr = 0x822B1C84;
	sub_823216F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822b1c90
	goto loc_822B1C90;
loc_822B1C8C:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B1C90:
	// stw r28,200(r11)
	PPC_STORE_U32(r11.u32 + 200, r28.u32);
	// li r3,672
	ctx.r3.s64 = 672;
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1CA0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1cb4
	if (cr6.eq) goto loc_822B1CB4;
	// bl 0x823216f8
	ctx.lr = 0x822B1CAC;
	sub_823216F8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822b1cb8
	goto loc_822B1CB8;
loc_822B1CB4:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B1CB8:
	// stw r28,200(r11)
	PPC_STORE_U32(r11.u32 + 200, r28.u32);
	// li r3,672
	ctx.r3.s64 = 672;
	// stw r11,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1CC8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1cdc
	if (cr6.eq) goto loc_822B1CDC;
	// bl 0x823216f8
	ctx.lr = 0x822B1CD4;
	sub_823216F8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x822b1ce0
	goto loc_822B1CE0;
loc_822B1CDC:
	// mr r30,r29
	r30.u64 = r29.u64;
loc_822B1CE0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r28,200(r30)
	PPC_STORE_U32(r30.u32 + 200, r28.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B1CFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// li r3,736
	ctx.r3.s64 = 736;
	// bl 0x82130528
	ctx.lr = 0x822B1D08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1d18
	if (cr6.eq) goto loc_822B1D18;
	// bl 0x82319e78
	ctx.lr = 0x822B1D14;
	sub_82319E78(ctx, base);
	// b 0x822b1d1c
	goto loc_822B1D1C;
loc_822B1D18:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822B1D1C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,-31384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f0,432(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 432, temp.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f28,7444(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 7444);
	f28.f64 = double(temp.f32);
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stw r28,200(r8)
	PPC_STORE_U32(ctx.r8.u32 + 200, r28.u32);
	// lfs f12,-31376(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31376);
	ctx.f12.f64 = double(temp.f32);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f29,14988(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14988);
	f29.f64 = double(temp.f32);
	// stb r27,184(r6)
	PPC_STORE_U8(ctx.r6.u32 + 184, r27.u8);
	// lfs f0,31304(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31304);
	f0.f64 = double(temp.f32);
	// lwz r5,72(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f0,168(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 168, temp.u32);
	// lfs f30,27640(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	f30.f64 = double(temp.f32);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f13,-28872(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// stfs f13,244(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 244, temp.u32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// stfs f31,240(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 240, temp.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stfs f31,248(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 248, temp.u32);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f31,448(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 448, temp.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f0,-17876(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -17876);
	f0.f64 = double(temp.f32);
	// li r3,2848
	ctx.r3.s64 = 2848;
	// stfs f28,452(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 452, temp.u32);
	// stfs f0,456(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 456, temp.u32);
	// lfs f27,27632(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27632);
	f27.f64 = double(temp.f32);
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f12,304(r4)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r4.u32 + 304, temp.u32);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f29,300(r11)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 300, temp.u32);
	// lfs f11,-13148(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	ctx.f11.f64 = double(temp.f32);
	// lwz r9,72(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f27,268(r9)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r9.u32 + 268, temp.u32);
	// lwz r8,72(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f31,492(r8)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r8.u32 + 492, temp.u32);
	// lwz r7,72(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f30,496(r7)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r7.u32 + 496, temp.u32);
	// lwz r6,72(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f29,488(r6)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r6.u32 + 488, temp.u32);
	// lwz r5,72(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f30,508(r5)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r5.u32 + 508, temp.u32);
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f29,512(r4)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r4.u32 + 512, temp.u32);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lfs f13,-6176(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,212(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 212, temp.u32);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// stfs f11,216(r10)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r10.u32 + 216, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1E0C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1e1c
	if (cr6.eq) goto loc_822B1E1C;
	// bl 0x82315728
	ctx.lr = 0x822B1E18;
	sub_82315728(ctx, base);
	// b 0x822b1e20
	goto loc_822B1E20;
loc_822B1E1C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822B1E20:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
	// stw r28,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, r28.u32);
	// li r3,176
	ctx.r3.s64 = 176;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lfs f0,3732(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,476(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 476, temp.u32);
	// stb r29,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r29.u8);
	// stb r29,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r29.u8);
	// stb r29,90(r31)
	PPC_STORE_U8(r31.u32 + 90, r29.u8);
	// bl 0x82130528
	ctx.lr = 0x822B1E4C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1e5c
	if (cr6.eq) goto loc_822B1E5C;
	// bl 0x82317da0
	ctx.lr = 0x822B1E58;
	sub_82317DA0(ctx, base);
	// b 0x822b1e60
	goto loc_822B1E60;
loc_822B1E5C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822B1E60:
	// stw r3,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r3.u32);
	// li r3,784
	ctx.r3.s64 = 784;
	// bl 0x82130528
	ctx.lr = 0x822B1E6C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1e7c
	if (cr6.eq) goto loc_822B1E7C;
	// bl 0x8231aa58
	ctx.lr = 0x822B1E78;
	sub_8231AA58(ctx, base);
	// b 0x822b1e80
	goto loc_822B1E80;
loc_822B1E7C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822B1E80:
	// stw r3,96(r31)
	PPC_STORE_U32(r31.u32 + 96, ctx.r3.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r28,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, r28.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r3,736
	ctx.r3.s64 = 736;
	// lfs f0,-19928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -19928);
	f0.f64 = double(temp.f32);
	// lfs f26,-30580(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -30580);
	f26.f64 = double(temp.f32);
	// lfs f25,11360(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11360);
	f25.f64 = double(temp.f32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stfs f0,244(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 244, temp.u32);
	// stfs f31,248(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 248, temp.u32);
	// stfs f31,240(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 240, temp.u32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stfs f31,448(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 448, temp.u32);
	// stfs f28,452(r11)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r11.u32 + 452, temp.u32);
	// stfs f30,456(r11)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r11.u32 + 456, temp.u32);
	// lwz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stfs f26,476(r8)
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r8.u32 + 476, temp.u32);
	// lwz r7,96(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// stfs f25,468(r7)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r7.u32 + 468, temp.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1ED8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1ee8
	if (cr6.eq) goto loc_822B1EE8;
	// bl 0x82319e78
	ctx.lr = 0x822B1EE4;
	sub_82319E78(ctx, base);
	// b 0x822b1eec
	goto loc_822B1EEC;
loc_822B1EE8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822B1EEC:
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// stw r28,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, r28.u32);
	// li r3,240
	ctx.r3.s64 = 240;
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// stw r29,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r29.u32);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1F08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1f1c
	if (cr6.eq) goto loc_822B1F1C;
	// bl 0x8271fa20
	ctx.lr = 0x822B1F14;
	sub_8271FA20(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822b1f20
	goto loc_822B1F20;
loc_822B1F1C:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B1F20:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stfs f31,192(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 192, temp.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stfs f31,200(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 200, temp.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stfs f31,212(r11)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 212, temp.u32);
	// stw r29,216(r11)
	PPC_STORE_U32(r11.u32 + 216, r29.u32);
	// li r3,272
	ctx.r3.s64 = 272;
	// stb r29,227(r11)
	PPC_STORE_U8(r11.u32 + 227, r29.u8);
	// lfs f0,27636(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27636);
	f0.f64 = double(temp.f32);
	// lfs f13,30120(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30116(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30116);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,168(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stfs f13,196(r11)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r11.u32 + 196, temp.u32);
	// stfs f12,204(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 204, temp.u32);
	// stw r11,132(r31)
	PPC_STORE_U32(r31.u32 + 132, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1F64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1f78
	if (cr6.eq) goto loc_822B1F78;
	// bl 0x823192c0
	ctx.lr = 0x822B1F70;
	sub_823192C0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822b1f7c
	goto loc_822B1F7C;
loc_822B1F78:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B1F7C:
	// li r10,2832
	ctx.r10.s64 = 2832;
	// stfs f26,260(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(r11.u32 + 260, temp.u32);
	// stb r29,227(r11)
	PPC_STORE_U8(r11.u32 + 227, r29.u8);
	// li r3,240
	ctx.r3.s64 = 240;
	// stw r10,264(r11)
	PPC_STORE_U32(r11.u32 + 264, ctx.r10.u32);
	// stw r11,128(r31)
	PPC_STORE_U32(r31.u32 + 128, r11.u32);
	// bl 0x82130528
	ctx.lr = 0x822B1F98;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1fac
	if (cr6.eq) goto loc_822B1FAC;
	// bl 0x8271fa20
	ctx.lr = 0x822B1FA4;
	sub_8271FA20(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x822b1fb0
	goto loc_822B1FB0;
loc_822B1FAC:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B1FB0:
	// stfs f29,196(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r11.u32 + 196, temp.u32);
	// stw r27,216(r11)
	PPC_STORE_U32(r11.u32 + 216, r27.u32);
	// stfs f27,168(r11)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(r11.u32 + 168, temp.u32);
	// stb r29,227(r11)
	PPC_STORE_U8(r11.u32 + 227, r29.u8);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
	// li r3,304
	ctx.r3.s64 = 304;
	// bl 0x82130528
	ctx.lr = 0x822B1FCC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b1fe0
	if (cr6.eq) goto loc_822B1FE0;
	// bl 0x82319218
	ctx.lr = 0x822B1FD8;
	sub_82319218(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x822b1fe4
	goto loc_822B1FE4;
loc_822B1FE0:
	// mr r30,r29
	r30.u64 = r29.u64;
loc_822B1FE4:
	// stfs f28,192(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r30.u32 + 192, temp.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,-20156
	ctx.r4.s64 = r11.s64 + -20156;
	// bl 0x822ebb00
	ctx.lr = 0x822B1FF8;
	sub_822EBB00(ctx, base);
	// stb r27,225(r30)
	PPC_STORE_U8(r30.u32 + 225, r27.u8);
	// stb r27,224(r30)
	PPC_STORE_U8(r30.u32 + 224, r27.u8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stb r27,226(r30)
	PPC_STORE_U8(r30.u32 + 226, r27.u8);
	// stw r30,136(r31)
	PPC_STORE_U32(r31.u32 + 136, r30.u32);
	// stw r29,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r29.u32);
	// stw r29,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r29.u32);
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
	// stw r29,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r29.u32);
	// bl 0x82388580
	ctx.lr = 0x822B2020;
	sub_82388580(ctx, base);
	// bl 0x82398628
	ctx.lr = 0x822B2024;
	sub_82398628(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822b2038
	if (cr6.eq) goto loc_822B2038;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x822b203c
	if (!cr6.eq) goto loc_822B203C;
loc_822B2038:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822B203C:
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x822b2054
	if (cr6.eq) goto loc_822B2054;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// mr r11,r29
	r11.u64 = r29.u64;
	// bne cr6,0x822b2058
	if (!cr6.eq) goto loc_822B2058;
loc_822B2054:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822B2058:
	// stb r10,88(r31)
	PPC_STORE_U8(r31.u32 + 88, ctx.r10.u8);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// stb r11,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r11.u8);
	// bl 0x82388580
	ctx.lr = 0x822B2068;
	sub_82388580(ctx, base);
	// bl 0x82398660
	ctx.lr = 0x822B206C;
	sub_82398660(ctx, base);
	// addi r10,r3,-1
	ctx.r10.s64 = ctx.r3.s64 + -1;
	// li r3,96
	ctx.r3.s64 = 96;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,90(r31)
	PPC_STORE_U8(r31.u32 + 90, ctx.r8.u8);
	// bl 0x82130528
	ctx.lr = 0x822B2084;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2094
	if (cr6.eq) goto loc_822B2094;
	// bl 0x8271e858
	ctx.lr = 0x822B2090;
	sub_8271E858(ctx, base);
	// b 0x822b2098
	goto loc_822B2098;
loc_822B2094:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822B2098:
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// li r3,224
	ctx.r3.s64 = 224;
	// bl 0x82130528
	ctx.lr = 0x822B20A4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b20b4
	if (cr6.eq) goto loc_822B20B4;
	// bl 0x8271f0a8
	ctx.lr = 0x822B20B0;
	sub_8271F0A8(ctx, base);
	// b 0x822b20b8
	goto loc_822B20B8;
loc_822B20B4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822B20B8:
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// stb r27,184(r3)
	PPC_STORE_U8(ctx.r3.u32 + 184, r27.u8);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e918
	ctx.lr = 0x822B20CC;
	sub_8271E918(ctx, base);
	// li r3,1216
	ctx.r3.s64 = 1216;
	// bl 0x82130528
	ctx.lr = 0x822B20D4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b20e4
	if (cr6.eq) goto loc_822B20E4;
	// bl 0x82314c30
	ctx.lr = 0x822B20E0;
	sub_82314C30(ctx, base);
	// b 0x822b20e8
	goto loc_822B20E8;
loc_822B20E4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
loc_822B20E8:
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// stfs f25,516(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r3.u32 + 516, temp.u32);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stfs f25,740(r11)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(r11.u32 + 740, temp.u32);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B210C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r8,r11,11
	ctx.r8.s64 = r11.s64 + 11;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// bl 0x8271e930
	ctx.lr = 0x822B2124;
	sub_8271E930(ctx, base);
	// stw r29,144(r31)
	PPC_STORE_U32(r31.u32 + 144, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,148(r31)
	PPC_STORE_U32(r31.u32 + 148, r29.u32);
	// stw r29,152(r31)
	PPC_STORE_U32(r31.u32 + 152, r29.u32);
	// bl 0x822afb10
	ctx.lr = 0x822B2138;
	sub_822AFB10(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,30104
	ctx.r3.s64 = ctx.r6.s64 + 30104;
	// bl 0x825f1ff8
	ctx.lr = 0x822B2148;
	sub_825F1FF8(ctx, base);
	// stw r3,104(r31)
	PPC_STORE_U32(r31.u32 + 104, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-56
	r12.s64 = ctx.r1.s64 + -56;
	// bl 0x823dba18
	ctx.lr = 0x822B215C;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822B2160"))) PPC_WEAK_FUNC(sub_822B2160);
PPC_FUNC_IMPL(__imp__sub_822B2160) {
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
	ctx.lr = 0x822B2168;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r28,0
	r28.s64 = 0;
	// addi r10,r11,30128
	ctx.r10.s64 = r11.s64 + 30128;
	// addi r30,r31,44
	r30.s64 = r31.s64 + 44;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// li r29,5
	r29.s64 = 5;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r28,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r28.u32);
	// stw r28,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r28.u32);
	// stw r28,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r28.u32);
loc_822B2198:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b21b8
	if (cr6.eq) goto loc_822B21B8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B21B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B21B8:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x822b2198
	if (!cr0.eq) goto loc_822B2198;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b21e4
	if (cr6.eq) goto loc_822B21E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B21E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B21E4:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2204
	if (cr6.eq) goto loc_822B2204;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2204:
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2224
	if (cr6.eq) goto loc_822B2224;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2224:
	// lwz r3,136(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 136);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2244
	if (cr6.eq) goto loc_822B2244;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2244:
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2264
	if (cr6.eq) goto loc_822B2264;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2264;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2264:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2284
	if (cr6.eq) goto loc_822B2284;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2284:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b22a4
	if (cr6.eq) goto loc_822B22A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B22A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B22A4:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b22c4
	if (cr6.eq) goto loc_822B22C4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B22C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B22C4:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b22e4
	if (cr6.eq) goto loc_822B22E4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B22E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B22E4:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2304
	if (cr6.eq) goto loc_822B2304;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2304:
	// lwz r3,132(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2324
	if (cr6.eq) goto loc_822B2324;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2324:
	// lwz r3,128(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2344
	if (cr6.eq) goto loc_822B2344;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2344;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2344:
	// lwz r3,124(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2364
	if (cr6.eq) goto loc_822B2364;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2364:
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2378
	if (cr6.eq) goto loc_822B2378;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B2378;
	sub_8213C218(ctx, base);
loc_822B2378:
	// lwz r3,148(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b238c
	if (cr6.eq) goto loc_822B238C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B238C;
	sub_8213C218(ctx, base);
loc_822B238C:
	// lwz r3,152(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 152);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b23a0
	if (cr6.eq) goto loc_822B23A0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x822B23A0;
	sub_8213C218(ctx, base);
loc_822B23A0:
	// lwz r30,12(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b23c0
	if (cr6.eq) goto loc_822B23C0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8217cb48
	ctx.lr = 0x822B23B4;
	sub_8217CB48(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82130588
	ctx.lr = 0x822B23BC;
	sub_82130588(ctx, base);
	// stw r28,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r28.u32);
loc_822B23C0:
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x825f1de0
	ctx.lr = 0x822B23C8;
	sub_825F1DE0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822B23D0"))) PPC_WEAK_FUNC(sub_822B23D0);
PPC_FUNC_IMPL(__imp__sub_822B23D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B2400;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b28a4
	if (!cr6.eq) goto loc_822B28A4;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x8271eb28
	ctx.lr = 0x822B2414;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b242c
	if (cr6.eq) goto loc_822B242C;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,12
	cr6.compare<int32_t>(ctx.r10.s32, 12, xer);
	// beq cr6,0x822b28a4
	if (cr6.eq) goto loc_822B28A4;
loc_822B242C:
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B2438;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b2450
	if (cr6.eq) goto loc_822B2450;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,11
	cr6.compare<int32_t>(ctx.r10.s32, 11, xer);
	// beq cr6,0x822b28a4
	if (cr6.eq) goto loc_822B28A4;
loc_822B2450:
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B245C;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b28a4
	if (!cr6.eq) goto loc_822B28A4;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B2470;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b2488
	if (cr6.eq) goto loc_822B2488;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,14
	cr6.compare<int32_t>(ctx.r10.s32, 14, xer);
	// bge cr6,0x822b28a4
	if (!cr6.lt) goto loc_822B28A4;
loc_822B2488:
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B249C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b28a4
	if (cr6.eq) goto loc_822B28A4;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bge cr6,0x822b28a4
	if (!cr6.lt) goto loc_822B28A4;
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b26ac
	if (cr6.eq) goto loc_822B26AC;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b2624
	if (cr6.eq) goto loc_822B2624;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b2624
	if (cr6.eq) goto loc_822B2624;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x8271eb28
	ctx.lr = 0x822B24DC;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b28a4
	if (!cr6.eq) goto loc_822B28A4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,88(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,14192(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f30.f64 = double(temp.f32);
	// bne cr6,0x822b25d8
	if (!cr6.eq) goto loc_822B25D8;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B251C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x822b25d8
	if (!cr6.gt) goto loc_822B25D8;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2176
	ctx.r6.s64 = ctx.r8.s64 + 2176;
	// ori r11,r7,64167
	r11.u64 = ctx.r7.u64 | 64167;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r7,2176(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r7,r4
	ctx.r10.s64 = ctx.r7.s64 * ctx.r4.s64;
	// lfs f0,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// mulld r10,r10,r3
	ctx.r10.s64 = ctx.r10.s64 * ctx.r3.s64;
	// lfs f13,12120(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12120);
	ctx.f13.f64 = double(temp.f32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r11,9
	r11.u64 = r11.u32 & 0x7FFFFF;
	// clrlwi r9,r10,9
	ctx.r9.u64 = ctx.r10.u32 & 0x7FFFFF;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f11
	ctx.f9.f64 = double(ctx.f11.s64);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// lfs f12,30136(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 30136);
	ctx.f12.f64 = double(temp.f32);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// rldicl r10,r10,32,32
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// stw r11,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, r11.u32);
	// lfs f11,30132(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 30132);
	ctx.f11.f64 = double(temp.f32);
	// stw r10,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r10.u32);
	// lwz r6,64(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// fmsubs f6,f8,f13,f0
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f13.f64 - f0.f64));
	// frsp f5,f7
	ctx.f5.f64 = double(float(ctx.f7.f64));
	// fsel f4,f6,f0,f30
	ctx.f4.f64 = ctx.f6.f64 >= 0.0 ? f0.f64 : f30.f64;
	// fmadds f3,f5,f12,f11
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f12.f64 + ctx.f11.f64));
	// fmuls f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f4.f64));
	// stfs f2,452(r6)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r6.u32 + 452, temp.u32);
	// lwz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stfs f31,456(r5)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r5.u32 + 456, temp.u32);
	// b 0x822b25e8
	goto loc_822B25E8;
loc_822B25D8:
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stfs f31,452(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r11.u32 + 452, temp.u32);
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stfs f31,456(r10)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r10.u32 + 456, temp.u32);
loc_822B25E8:
	// li r5,-1
	ctx.r5.s64 = -1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B25FC;
	sub_822AFCD0(ctx, base);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e930
	ctx.lr = 0x822B2608;
	sub_8271E930(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B2620;
	sub_82207EF0(ctx, base);
	// b 0x822b28a4
	goto loc_822B28A4;
loc_822B2624:
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B2640;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822b28a4
	if (!cr6.eq) goto loc_822B28A4;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B2670;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r7,r11,11
	ctx.r7.s64 = r11.s64 + 11;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + r31.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,40(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x822B2690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f3,11360(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B26A8;
	sub_82207EF0(ctx, base);
	// b 0x822b28a4
	goto loc_822B28A4;
loc_822B26AC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b2708
	if (cr6.eq) goto loc_822B2708;
	// lwz r11,72(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x822b2708
	if (!cr6.eq) goto loc_822B2708;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B26D8;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b2708
	if (cr6.eq) goto loc_822B2708;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e930
	ctx.lr = 0x822B26EC;
	sub_8271E930(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,17032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B2704;
	sub_82207EF0(ctx, base);
	// b 0x822b28a4
	goto loc_822B28A4;
loc_822B2708:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b27ac
	if (cr6.eq) goto loc_822B27AC;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b27ac
	if (cr6.eq) goto loc_822B27AC;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x8271eb28
	ctx.lr = 0x822B2728;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b28a4
	if (cr6.eq) goto loc_822B28A4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,452(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 452, temp.u32);
	// lwz r9,64(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// stfs f0,456(r9)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 456, temp.u32);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r8,r11,11
	ctx.r8.s64 = r11.s64 + 11;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + r31.u32);
	// bl 0x8271e930
	ctx.lr = 0x822B2760;
	sub_8271E930(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f3,11360(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,17032(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B2778;
	sub_82207EF0(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,988
	ctx.r3.s64 = r11.s64 + 988;
	// bl 0x822eb078
	ctx.lr = 0x822B2784;
	sub_822EB078(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r3,-12252(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -12252);
	// lwz r11,1740(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b28a4
	if (cr6.eq) goto loc_822B28A4;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x821ec468
	ctx.lr = 0x822B27A8;
	sub_821EC468(ctx, base);
	// b 0x822b28a4
	goto loc_822B28A4;
loc_822B27AC:
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B27C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822b28a4
	if (cr6.eq) goto loc_822B28A4;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B27F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f3,11360(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,17032(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B2810;
	sub_82207EF0(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r3,r11,11
	ctx.r3.s64 = r11.s64 + 11;
	// lis r4,-32130
	ctx.r4.s64 = -2105671680;
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r5,-172
	ctx.r6.s64 = ctx.r5.s64 + -172;
	// addi r5,r4,-228
	ctx.r5.s64 = ctx.r4.s64 + -228;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x823dedd8
	ctx.lr = 0x822B283C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b2854
	if (cr6.eq) goto loc_822B2854;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,452(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 452, temp.u32);
	// stfs f0,456(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 456, temp.u32);
loc_822B2854:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,988
	ctx.r3.s64 = r11.s64 + 988;
	// bl 0x822eb078
	ctx.lr = 0x822B2860;
	sub_822EB078(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b2884
	if (cr6.eq) goto loc_822B2884;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x821ec468
	ctx.lr = 0x822B2884;
	sub_821EC468(ctx, base);
loc_822B2884:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B28A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B28A4:
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

__attribute__((alias("__imp__sub_822B28C4"))) PPC_WEAK_FUNC(sub_822B28C4);
PPC_FUNC_IMPL(__imp__sub_822B28C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B28C8"))) PPC_WEAK_FUNC(sub_822B28C8);
PPC_FUNC_IMPL(__imp__sub_822B28C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,157(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 157);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b2a9c
	if (cr6.eq) goto loc_822B2A9C;
	// lbz r11,156(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b2a9c
	if (!cr6.eq) goto loc_822B2A9C;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a8108
	ctx.lr = 0x822B2904;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,3732(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 + f0.f64));
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x822a8108
	ctx.lr = 0x822B2930;
	sub_822A8108(ctx, base);
	// li r6,48
	ctx.r6.s64 = 48;
	// lwz r7,8(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// addi r10,r8,2256
	ctx.r10.s64 = ctx.r8.s64 + 2256;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r3,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,11368(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// stw r11,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r11.u32);
	// lfs f11,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fadds f10,f11,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// stfs f0,192(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r5,-32114
	ctx.r5.s64 = -2104623104;
	// stvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r8,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r8.u16);
	// lvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r11,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r11.u16);
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stb r11,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r11.u8);
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r11,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r11.u16);
	// stfs f0,196(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stw r11,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r11.u32);
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r3,-23452(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -23452);
	// li r9,7
	ctx.r9.s64 = 7;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r7,2048
	ctx.r7.s64 = 2048;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// lwz r6,128(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lwz r6,16(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// bl 0x82574418
	ctx.lr = 0x822B2A04;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b2a68
	if (cr6.eq) goto loc_822B2A68;
	// li r11,3
	r11.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afab0
	ctx.lr = 0x822B2A20;
	sub_822AFAB0(ctx, base);
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r10,r11,11
	ctx.r10.s64 = r11.s64 + 11;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + r31.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822B2A40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,14192(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822B2A54;
	sub_822B0F10(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822B2A68:
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B2A74;
	sub_8271EB28(ctx, base);
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
	// bne cr6,0x822b2a9c
	if (!cr6.eq) goto loc_822B2A9C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b15b0
	ctx.lr = 0x822B2A94;
	sub_822B15B0(ctx, base);
	// li r11,4
	r11.s64 = 4;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
loc_822B2A9C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B2AB0"))) PPC_WEAK_FUNC(sub_822B2AB0);
PPC_FUNC_IMPL(__imp__sub_822B2AB0) {
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
	// bl 0x823d91ec
	ctx.lr = 0x822B2AB8;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9c8
	ctx.lr = 0x822B2AC0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b32bc
	if (cr6.eq) goto loc_822B32BC;
	// lwz r11,656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822b32bc
	if (!cr6.eq) goto loc_822B32BC;
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 108);
	f0.f64 = double(temp.f32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// li r25,1
	r25.s64 = 1;
	// addi r27,r31,108
	r27.s64 = r31.s64 + 108;
	// mr r30,r25
	r30.u64 = r25.u64;
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// bl 0x82388580
	ctx.lr = 0x822B2B04;
	sub_82388580(ctx, base);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r26,0
	r26.s64 = 0;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x822b2b18
	if (!cr6.eq) goto loc_822B2B18;
	// mr r30,r26
	r30.u64 = r26.u64;
loc_822B2B18:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x8271eb28
	ctx.lr = 0x822B2B30;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b2b58
	if (!cr6.eq) goto loc_822B2B58;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B2B58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2B58:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// bl 0x8271eb28
	ctx.lr = 0x822B2B64;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b2b80
	if (!cr6.eq) goto loc_822B2B80;
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2B80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B2B80:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x8271eb28
	ctx.lr = 0x822B2B8C;
	sub_8271EB28(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
	// bne cr6,0x822b2bf0
	if (!cr6.eq) goto loc_822B2BF0;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2BB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B2BC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,68(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822B2BE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stfs f31,672(r5)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r5.u32 + 672, temp.u32);
	// stw r26,668(r5)
	PPC_STORE_U32(ctx.r5.u32 + 668, r26.u32);
	// stb r26,156(r5)
	PPC_STORE_U8(ctx.r5.u32 + 156, r26.u8);
loc_822B2BF0:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r28,r11,-140
	r28.s64 = r11.s64 + -140;
	// addi r30,r10,-252
	r30.s64 = ctx.r10.s64 + -252;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x822B2C18;
	sub_823DEDD8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822b2c44
	if (cr6.eq) goto loc_822B2C44;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2C34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b2c44
	if (!cr6.eq) goto loc_822B2C44;
	// stfs f31,512(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + 512, temp.u32);
loc_822B2C44:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x822B2C5C;
	sub_823DEDD8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822b2ca8
	if (cr6.eq) goto loc_822B2CA8;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2C78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b2ca4
	if (cr6.eq) goto loc_822B2CA4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f13,224(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822b2ca8
	if (!cr6.gt) goto loc_822B2CA8;
loc_822B2CA4:
	// stfs f31,512(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r29.u32 + 512, temp.u32);
loc_822B2CA8:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// addi r6,r10,-172
	ctx.r6.s64 = ctx.r10.s64 + -172;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r8,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// bl 0x823dedd8
	ctx.lr = 0x822B2CD0;
	sub_823DEDD8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822b30ec
	if (cr6.eq) goto loc_822B30EC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B2CEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b30ec
	if (!cr6.eq) goto loc_822B30EC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r30,r26
	r30.u64 = r26.u64;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b2d2c
	if (cr6.eq) goto loc_822B2D2C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lhz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 8);
	// cmplwi cr6,r8,65535
	cr6.compare<uint32_t>(ctx.r8.u32, 65535, xer);
	// beq cr6,0x822b2d2c
	if (cr6.eq) goto loc_822B2D2C;
	// bl 0x822a5578
	ctx.lr = 0x822B2D28;
	sub_822A5578(ctx, base);
	// lwz r30,116(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
loc_822B2D2C:
	// fmr f27,f31
	ctx.fpscr.disableFlushMode();
	f27.f64 = f31.f64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// fmr f28,f31
	f28.f64 = f31.f64;
	// fmr f24,f31
	f24.f64 = f31.f64;
	// fmr f25,f31
	f25.f64 = f31.f64;
	// beq cr6,0x822b308c
	if (cr6.eq) goto loc_822B308C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f30,60(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	f30.f64 = double(temp.f32);
	// lfs f26,64(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	f26.f64 = double(temp.f32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x822b2d70
	if (!cr6.eq) goto loc_822B2D70;
	// lfs f30,68(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	f30.f64 = double(temp.f32);
	// lfs f26,72(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	f26.f64 = double(temp.f32);
	// b 0x822b2d88
	goto loc_822B2D88;
loc_822B2D70:
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b2d88
	if (!cr6.eq) goto loc_822B2D88;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f30,30280(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30280);
	f30.f64 = double(temp.f32);
	// fmr f26,f30
	f26.f64 = f30.f64;
loc_822B2D88:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r8,60(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 60);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// lfs f29,-12084(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12084);
	f29.f64 = double(temp.f32);
	// beq cr6,0x822b2e00
	if (cr6.eq) goto loc_822B2E00;
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b2e00
	if (cr6.eq) goto loc_822B2E00;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b2e00
	if (cr6.eq) goto loc_822B2E00;
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x822b2dd4
	if (!cr6.eq) goto loc_822B2DD4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822B2DC8;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b2e00
	if (cr6.eq) goto loc_822B2E00;
loc_822B2DD4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b2e4c
	if (!cr6.eq) goto loc_822B2E4C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822B2DF4;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b2e4c
	if (!cr6.eq) goto loc_822B2E4C;
loc_822B2E00:
	// li r4,28
	ctx.r4.s64 = 28;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B2E0C;
	sub_822A4BB8(ctx, base);
	// li r4,27
	ctx.r4.s64 = 27;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f1.f64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B2E1C;
	sub_822A4BB8(ctx, base);
	// fsubs f1,f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f27.f64 - ctx.f1.f64));
	// fmr f2,f29
	ctx.f2.f64 = f29.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B2E28;
	sub_8260C5C8(ctx, base);
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x822b2e48
	if (cr6.eq) goto loc_822B2E48;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822b2e44
	if (!cr6.gt) goto loc_822B2E44;
	// fmuls f0,f0,f30
	f0.f64 = double(float(f0.f64 * f30.f64));
	// b 0x822b2e48
	goto loc_822B2E48;
loc_822B2E44:
	// fmuls f0,f0,f26
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f26.f64));
loc_822B2E48:
	// fmr f27,f0
	ctx.fpscr.disableFlushMode();
	f27.f64 = f0.f64;
loc_822B2E4C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b2ee8
	if (cr6.eq) goto loc_822B2EE8;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r4,29
	ctx.r4.s64 = 29;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b2ec8
	if (!cr6.eq) goto loc_822B2EC8;
	// bl 0x822a4bb8
	ctx.lr = 0x822B2E78;
	sub_822A4BB8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f2,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8260c5c8
	ctx.lr = 0x822B2E84;
	sub_8260C5C8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x822b2ee8
	if (!cr6.gt) goto loc_822B2EE8;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f0,80(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 80);
	f0.f64 = double(temp.f32);
	// fmuls f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64));
	// lfs f12,76(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 76);
	ctx.f12.f64 = double(temp.f32);
	// fneg f11,f0
	ctx.f11.u64 = f0.u64 ^ 0x8000000000000000;
	// lfs f10,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f10,f1
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64));
	// fneg f28,f13
	f28.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// fneg f25,f9
	f25.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// fsubs f8,f28,f11
	ctx.f8.f64 = double(float(f28.f64 - ctx.f11.f64));
	// fsel f7,f8,f28,f11
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f28.f64 : ctx.f11.f64;
	// fsubs f6,f7,f12
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fsel f5,f6,f12,f7
	ctx.f5.f64 = ctx.f6.f64 >= 0.0 ? ctx.f12.f64 : ctx.f7.f64;
	// stfs f5,116(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// b 0x822b2ee8
	goto loc_822B2EE8;
loc_822B2EC8:
	// bl 0x822a4bb8
	ctx.lr = 0x822B2ECC;
	sub_822A4BB8(ctx, base);
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f29.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B2ED4;
	sub_8260C5C8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x822b2ee8
	if (!cr6.gt) goto loc_822B2EE8;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f0,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// fmuls f24,f0,f1
	f24.f64 = double(float(f0.f64 * ctx.f1.f64));
loc_822B2EE8:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r30,4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplw cr6,r8,r9
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, xer);
	// bne cr6,0x822b3030
	if (!cr6.eq) goto loc_822B3030;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822B2F10;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b3030
	if (!cr6.eq) goto loc_822B3030;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r29,r30,6,0,25
	r29.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r30,r11,21384
	r30.s64 = r11.s64 + 21384;
	// addi r11,r30,52
	r11.s64 = r30.s64 + 52;
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// beq cr6,0x822b3030
	if (cr6.eq) goto loc_822B3030;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a5578
	ctx.lr = 0x822B2F40;
	sub_822A5578(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f13,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,40(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 40);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822b3030
	if (!cr6.gt) goto loc_822B3030;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f13,588(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 588);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822b3030
	if (!cr6.gt) goto loc_822B3030;
	// fcmpu cr6,f27,f31
	cr6.compare(f27.f64, f31.f64);
	// bne cr6,0x822b3030
	if (!cr6.eq) goto loc_822B3030;
	// fcmpu cr6,f28,f31
	cr6.compare(f28.f64, f31.f64);
	// bne cr6,0x822b3030
	if (!cr6.eq) goto loc_822B3030;
	// add r30,r29,r30
	r30.u64 = r29.u64 + r30.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8221cba0
	ctx.lr = 0x822B2F88;
	sub_8221CBA0(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f31,-29232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -29232);
	f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = f31.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B2F98;
	sub_8260C5C8(ctx, base);
	// fneg f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f11,0(r27)
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r29,r10,29952
	r29.s64 = ctx.r10.s64 + 29952;
	// fneg f10,f26
	ctx.f10.u64 = f26.u64 ^ 0x8000000000000000;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f13,-31384(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31384);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f9,f0,f12
	ctx.f9.f64 = double(float(f0.f64 * ctx.f12.f64));
	// fmadds f8,f9,f13,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsubs f7,f8,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f10.f64));
	// fsel f6,f7,f8,f10
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f8.f64 : ctx.f10.f64;
	// fsubs f5,f6,f30
	ctx.f5.f64 = double(float(ctx.f6.f64 - f30.f64));
	// fsel f4,f5,f30,f6
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? f30.f64 : ctx.f6.f64;
	// stfs f4,0(r27)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r27.u32 + 0, temp.u32);
	// bl 0x8221cbf8
	ctx.lr = 0x822B2FDC;
	sub_8221CBF8(ctx, base);
	// fmr f2,f31
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = f31.f64;
	// bl 0x8260c5c8
	ctx.lr = 0x822B2FE4;
	sub_8260C5C8(ctx, base);
	// fneg f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// lfs f0,88(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 88);
	f0.f64 = double(temp.f32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lwz r7,24(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f2,116(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// addi r30,r31,116
	r30.s64 = r31.s64 + 116;
	// lfs f13,-13148(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13148);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f0,f3
	ctx.f1.f64 = double(float(f0.f64 * ctx.f3.f64));
	// fmadds f0,f1,f13,f2
	f0.f64 = double(float(ctx.f1.f64 * ctx.f13.f64 + ctx.f2.f64));
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// lfs f13,76(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,80(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsel f9,f10,f0,f11
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? f0.f64 : ctx.f11.f64;
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// fsel f7,f8,f13,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? ctx.f13.f64 : ctx.f9.f64;
	// stfs f7,116(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// b 0x822b306c
	goto loc_822B306C;
loc_822B3030:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lfs f2,-31384(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -31384);
	ctx.f2.f64 = double(temp.f32);
	// lfs f3,88(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// bl 0x821ce490
	ctx.lr = 0x822B3050;
	sub_821CE490(ctx, base);
	// lfs f3,88(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 88);
	ctx.f3.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r30,r31,116
	r30.s64 = r31.s64 + 116;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f2,-13148(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x821ce490
	ctx.lr = 0x822B306C;
	sub_821CE490(ctx, base);
loc_822B306C:
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// fneg f13,f26
	ctx.f13.u64 = f26.u64 ^ 0x8000000000000000;
	// fadds f12,f0,f27
	ctx.f12.f64 = double(float(f0.f64 + f27.f64));
	// lfs f28,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f28.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fsel f10,f11,f12,f13
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fsubs f9,f10,f30
	ctx.f9.f64 = double(float(ctx.f10.f64 - f30.f64));
	// fsel f27,f9,f30,f10
	f27.f64 = ctx.f9.f64 >= 0.0 ? f30.f64 : ctx.f10.f64;
loc_822B308C:
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lfs f1,452(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 452);
	ctx.f1.f64 = double(temp.f32);
	// lfs f3,14980(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14980);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,2432(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 2432);
	ctx.f2.f64 = double(temp.f32);
	// lfs f31,48(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	f31.f64 = double(temp.f32);
	// bl 0x82151fe0
	ctx.lr = 0x822B30AC;
	sub_82151FE0(ctx, base);
	// fsubs f0,f27,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f27.f64 - ctx.f1.f64));
	// fmadds f13,f0,f31,f1
	ctx.f13.f64 = double(float(f0.f64 * f31.f64 + ctx.f1.f64));
	// stfs f13,452(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 452, temp.u32);
	// stfs f13,112(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// lfs f11,456(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 456);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,460(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 460);
	ctx.f10.f64 = double(temp.f32);
	// lfs f12,224(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 224);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f7,f25,f12
	ctx.f7.f64 = double(float(f25.f64 - ctx.f12.f64));
	// fsubs f9,f24,f10
	ctx.f9.f64 = double(float(f24.f64 - ctx.f10.f64));
	// fsubs f8,f28,f11
	ctx.f8.f64 = double(float(f28.f64 - ctx.f11.f64));
	// fmadds f4,f7,f31,f12
	ctx.f4.f64 = double(float(ctx.f7.f64 * f31.f64 + ctx.f12.f64));
	// stfs f4,224(r28)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r28.u32 + 224, temp.u32);
	// fmadds f6,f9,f31,f10
	ctx.f6.f64 = double(float(ctx.f9.f64 * f31.f64 + ctx.f10.f64));
	// stfs f6,460(r28)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r28.u32 + 460, temp.u32);
	// fmadds f5,f8,f31,f11
	ctx.f5.f64 = double(float(ctx.f8.f64 * f31.f64 + ctx.f11.f64));
	// stfs f5,456(r28)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r28.u32 + 456, temp.u32);
loc_822B30EC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B3104;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lbz r7,93(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 93);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// lhz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// addi r6,r10,-4
	ctx.r6.s64 = ctx.r10.s64 + -4;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stb r4,91(r31)
	PPC_STORE_U8(r31.u32 + 91, ctx.r4.u8);
	// beq cr6,0x822b3164
	if (cr6.eq) goto loc_822B3164;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stb r26,184(r11)
	PPC_STORE_U8(r11.u32 + 184, r26.u8);
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stb r26,184(r10)
	PPC_STORE_U8(ctx.r10.u32 + 184, r26.u8);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,192(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b3150
	if (cr6.eq) goto loc_822B3150;
	// stb r26,184(r11)
	PPC_STORE_U8(r11.u32 + 184, r26.u8);
loc_822B3150:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b3164
	if (cr6.eq) goto loc_822B3164;
	// stb r26,184(r11)
	PPC_STORE_U8(r11.u32 + 184, r26.u8);
loc_822B3164:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B3178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,93(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 93);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b31c0
	if (cr6.eq) goto loc_822B31C0;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stb r25,184(r10)
	PPC_STORE_U8(ctx.r10.u32 + 184, r25.u8);
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// stb r25,184(r9)
	PPC_STORE_U8(ctx.r9.u32 + 184, r25.u8);
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,192(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b31ac
	if (cr6.eq) goto loc_822B31AC;
	// stb r25,184(r11)
	PPC_STORE_U8(r11.u32 + 184, r25.u8);
loc_822B31AC:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// lwz r11,196(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b31c0
	if (cr6.eq) goto loc_822B31C0;
	// stb r25,184(r11)
	PPC_STORE_U8(r11.u32 + 184, r25.u8);
loc_822B31C0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// not r8,r9
	ctx.r8.u64 = ~ctx.r9.u64;
	// rlwinm r10,r8,29,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 29) & 0x1;
	// beq cr6,0x822b321c
	if (cr6.eq) goto loc_822B321C;
	// lwz r11,72(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b321c
	if (cr6.eq) goto loc_822B321C;
	// lwz r9,52(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822b3208
	if (!cr6.eq) goto loc_822B3208;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// mr r11,r25
	r11.u64 = r25.u64;
	// beq cr6,0x822b320c
	if (cr6.eq) goto loc_822B320C;
loc_822B3208:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_822B320C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
loc_822B321C:
	// lbz r11,89(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 89);
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// and r30,r11,r10
	r30.u64 = r11.u64 & ctx.r10.u64;
	// bl 0x822b12b0
	ctx.lr = 0x822B3230;
	sub_822B12B0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b3268
	if (!cr6.eq) goto loc_822B3268;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-6148(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b326c
	if (cr6.eq) goto loc_822B326C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r9,-6144(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b326c
	if (cr6.eq) goto loc_822B326C;
	// lbz r11,156(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b326c
	if (cr6.eq) goto loc_822B326C;
loc_822B3268:
	// mr r30,r26
	r30.u64 = r26.u64;
loc_822B326C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b32bc
	if (cr6.eq) goto loc_822B32BC;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lbzx r7,r10,r11
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r30,48(r9)
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// addi r29,r11,208
	r29.s64 = r11.s64 + 208;
	// bne cr6,0x822b32a4
	if (!cr6.eq) goto loc_822B32A4;
	// addi r29,r11,144
	r29.s64 = r11.s64 + 144;
loc_822B32A4:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8271f020
	ctx.lr = 0x822B32AC;
	sub_8271F020(ctx, base);
	// addi r5,r29,48
	ctx.r5.s64 = r29.s64 + 48;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82315000
	ctx.lr = 0x822B32BC;
	sub_82315000(ctx, base);
loc_822B32BC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba14
	ctx.lr = 0x822B32C8;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822B32CC"))) PPC_WEAK_FUNC(sub_822B32CC);
PPC_FUNC_IMPL(__imp__sub_822B32CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B32D0"))) PPC_WEAK_FUNC(sub_822B32D0);
PPC_FUNC_IMPL(__imp__sub_822B32D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// bl 0x82388580
	ctx.lr = 0x822B3300;
	sub_82388580(ctx, base);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x822b33c8
	if (cr6.eq) goto loc_822B33C8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b05b8
	ctx.lr = 0x822B3314;
	sub_822B05B8(ctx, base);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f31,29940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29940);
	f31.f64 = double(temp.f32);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B3330;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r8,668(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// rlwinm r7,r8,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822b33c8
	if (cr6.eq) goto loc_822B33C8;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r30,r10,29952
	r30.s64 = ctx.r10.s64 + 29952;
	// lfs f29,-28872(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28872);
	f29.f64 = double(temp.f32);
	// lfs f30,29936(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 29936);
	f30.f64 = double(temp.f32);
loc_822B335C:
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f0,24(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bge cr6,0x822b33c8
	if (!cr6.lt) goto loc_822B33C8;
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lfs f0,88(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 88);
	f0.f64 = double(temp.f32);
	// lwz r11,576(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lfs f13,24(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f29,f13
	ctx.f12.f64 = double(float(f0.f64 * f29.f64 + ctx.f13.f64));
	// stfs f12,24(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// fmr f11,f12
	ctx.f11.f64 = ctx.f12.f64;
	// fsubs f10,f11,f31
	ctx.f10.f64 = double(float(ctx.f11.f64 - f31.f64));
	// fsel f9,f10,f11,f31
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f11.f64 : f31.f64;
	// fsel f8,f10,f11,f31
	ctx.f8.f64 = ctx.f10.f64 >= 0.0 ? ctx.f11.f64 : f31.f64;
	// fsubs f7,f9,f30
	ctx.f7.f64 = double(float(ctx.f9.f64 - f30.f64));
	// fsel f6,f7,f30,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f30.f64 : ctx.f8.f64;
	// stfs f6,24(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 24, temp.u32);
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B33B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,96(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r8,668(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// rlwinm r7,r8,0,26,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822b335c
	if (!cr6.eq) goto loc_822B335C;
loc_822B33C8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

__attribute__((alias("__imp__sub_822B33EC"))) PPC_WEAK_FUNC(sub_822B33EC);
PPC_FUNC_IMPL(__imp__sub_822B33EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B33F0"))) PPC_WEAK_FUNC(sub_822B33F0);
PPC_FUNC_IMPL(__imp__sub_822B33F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// bl 0x82388580
	ctx.lr = 0x822B3410;
	sub_82388580(ctx, base);
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// beq cr6,0x822b349c
	if (cr6.eq) goto loc_822B349C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822b3450
	if (!cr6.eq) goto loc_822B3450;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x8271f3b0
	ctx.lr = 0x822B3438;
	sub_8271F3B0(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B3450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B3450:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822B3464;
	sub_822B0F10(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b05b8
	ctx.lr = 0x822B346C;
	sub_822B05B8(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,988
	ctx.r3.s64 = r11.s64 + 988;
	// bl 0x822eb078
	ctx.lr = 0x822B3478;
	sub_822EB078(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lwz r9,1740(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r8,r9,0,26,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b349c
	if (cr6.eq) goto loc_822B349C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x821ec468
	ctx.lr = 0x822B349C;
	sub_821EC468(ctx, base);
loc_822B349C:
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

__attribute__((alias("__imp__sub_822B34B0"))) PPC_WEAK_FUNC(sub_822B34B0);
PPC_FUNC_IMPL(__imp__sub_822B34B0) {
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
	// bl 0x82387b90
	ctx.lr = 0x822B34CC;
	sub_82387B90(ctx, base);
	// lwz r11,1192(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1192);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b34e8
	if (cr6.eq) goto loc_822B34E8;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
	// bne cr6,0x822b34ec
	if (!cr6.eq) goto loc_822B34EC;
loc_822B34E8:
	// li r10,1
	ctx.r10.s64 = 1;
loc_822B34EC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b3504
	if (cr6.eq) goto loc_822B3504;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// bne cr6,0x822b3508
	if (!cr6.eq) goto loc_822B3508;
loc_822B3504:
	// li r11,1
	r11.s64 = 1;
loc_822B3508:
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stb r10,88(r31)
	PPC_STORE_U8(r31.u32 + 88, ctx.r10.u8);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stb r9,101(r31)
	PPC_STORE_U8(r31.u32 + 101, ctx.r9.u8);
	// stb r9,93(r31)
	PPC_STORE_U8(r31.u32 + 93, ctx.r9.u8);
	// stb r9,91(r31)
	PPC_STORE_U8(r31.u32 + 91, ctx.r9.u8);
	// stb r11,89(r31)
	PPC_STORE_U8(r31.u32 + 89, r11.u8);
	// lfs f13,27640(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,140(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// stfs f0,108(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f0,112(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// lwz r3,136(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 136);
	// bl 0x82388580
	ctx.lr = 0x822B3548;
	sub_82388580(ctx, base);
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822b3560
	if (cr6.lt) goto loc_822B3560;
	// bl 0x82387ba0
	ctx.lr = 0x822B3558;
	sub_82387BA0(ctx, base);
	// bl 0x82618670
	ctx.lr = 0x822B355C;
	sub_82618670(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
loc_822B3560:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f31,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x822afcd0
	ctx.lr = 0x822B357C;
	sub_822AFCD0(ctx, base);
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// bl 0x82318168
	ctx.lr = 0x822B3584;
	sub_82318168(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b23d0
	ctx.lr = 0x822B3590;
	sub_822B23D0(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822b0f10
	ctx.lr = 0x822B35A0;
	sub_822B0F10(ctx, base);
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82314790
	ctx.lr = 0x822B35A8;
	sub_82314790(ctx, base);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B35BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82316148
	ctx.lr = 0x822B35C8;
	sub_82316148(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b05b8
	ctx.lr = 0x822B35D0;
	sub_822B05B8(ctx, base);
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

__attribute__((alias("__imp__sub_822B35E8"))) PPC_WEAK_FUNC(sub_822B35E8);
PPC_FUNC_IMPL(__imp__sub_822B35E8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822B35F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b3b90
	if (cr6.eq) goto loc_822B3B90;
	// bl 0x822a5578
	ctx.lr = 0x822B360C;
	sub_822A5578(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b3b90
	if (cr6.eq) goto loc_822B3B90;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bne cr6,0x822b3b90
	if (!cr6.eq) goto loc_822B3B90;
	// bl 0x822a5578
	ctx.lr = 0x822B3628;
	sub_822A5578(ctx, base);
	// lwz r28,116(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822b3b90
	if (cr6.eq) goto loc_822B3B90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b3654
	if (cr6.eq) goto loc_822B3654;
	// bl 0x82209150
	ctx.lr = 0x822B3648;
	sub_82209150(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b3b90
	if (!cr6.eq) goto loc_822B3B90;
loc_822B3654:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10008(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10008);
	// bl 0x823cdc90
	ctx.lr = 0x822B3660;
	sub_823CDC90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b3b90
	if (!cr6.eq) goto loc_822B3B90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b3698
	if (cr6.eq) goto loc_822B3698;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B368C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b3b90
	if (!cr6.eq) goto loc_822B3B90;
loc_822B3698:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b12b0
	ctx.lr = 0x822B36A0;
	sub_822B12B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b36e0
	if (cr6.eq) goto loc_822B36E0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,136(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// bl 0x82388598
	ctx.lr = 0x822B36B8;
	sub_82388598(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r9,21384
	r11.s64 = ctx.r9.s64 + 21384;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823170c8
	ctx.lr = 0x822B36D8;
	sub_823170C8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822B36E0:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x822b3b90
	if (cr6.eq) goto loc_822B3B90;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r29,0
	r29.s64 = 0;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b3720
	if (cr6.eq) goto loc_822B3720;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822b3724
	if (cr6.eq) goto loc_822B3724;
loc_822B3720:
	// mr r11,r29
	r11.u64 = r29.u64;
loc_822B3724:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b3b90
	if (!cr6.eq) goto loc_822B3B90;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B3740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b3b90
	if (cr6.eq) goto loc_822B3B90;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b3770
	if (cr6.eq) goto loc_822B3770;
	// lwz r11,-6148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -6148);
	// lbz r11,156(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b3780
	if (cr6.eq) goto loc_822B3780;
loc_822B3770:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lbz r10,-6734(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6734);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b38e0
	if (cr6.eq) goto loc_822B38E0;
loc_822B3780:
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a4ce0
	ctx.lr = 0x822B378C;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b37b0
	if (!cr6.eq) goto loc_822B37B0;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a4ce0
	ctx.lr = 0x822B37A4;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b3b2c
	if (cr6.eq) goto loc_822B3B2C;
loc_822B37B0:
	// lwz r11,-6148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -6148);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r10,157(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 157);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b37f4
	if (cr6.eq) goto loc_822B37F4;
	// stb r29,157(r11)
	PPC_STORE_U8(r11.u32 + 157, r29.u8);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822afab0
	ctx.lr = 0x822B37D0;
	sub_822AFAB0(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822B37E4;
	sub_822B0F10(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// bl 0x821ec4e8
	ctx.lr = 0x822B37F0;
	sub_821EC4E8(ctx, base);
	// b 0x822b3b2c
	goto loc_822B3B2C;
loc_822B37F4:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// lwz r11,-6148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -6148);
	// bge 0x822b382c
	if (!cr0.lt) goto loc_822B382C;
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,157(r11)
	PPC_STORE_U8(r11.u32 + 157, ctx.r10.u8);
	// bl 0x822b15b0
	ctx.lr = 0x822B3814;
	sub_822B15B0(ctx, base);
	// li r9,4
	ctx.r9.s64 = 4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r9,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r9.u32);
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// bl 0x821ec4e8
	ctx.lr = 0x822B3828;
	sub_821EC4E8(ctx, base);
	// b 0x822b3b2c
	goto loc_822B3B2C;
loc_822B382C:
	// stb r29,157(r11)
	PPC_STORE_U8(r11.u32 + 157, r29.u8);
	// lwz r30,80(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822afab0
	ctx.lr = 0x822B383C;
	sub_822AFAB0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822b3864
	if (cr6.eq) goto loc_822B3864;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// beq cr6,0x822b3864
	if (cr6.eq) goto loc_822B3864;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b3864
	if (cr6.eq) goto loc_822B3864;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r30,3
	r30.s64 = 3;
	// bne cr6,0x822b3868
	if (!cr6.eq) goto loc_822B3868;
loc_822B3864:
	// li r30,4
	r30.s64 = 4;
loc_822B3868:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B3888;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822B389C;
	sub_822B0F10(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// addi r5,r6,17840
	ctx.r5.s64 = ctx.r6.s64 + 17840;
	// lwz r11,4(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b38d0
	if (!cr6.eq) goto loc_822B38D0;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x822b38d0
	if (!cr6.eq) goto loc_822B38D0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B38D0;
	sub_82207EF0(ctx, base);
loc_822B38D0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// bl 0x821ec4e8
	ctx.lr = 0x822B38DC;
	sub_821EC4E8(ctx, base);
	// b 0x822b3b2c
	goto loc_822B3B2C;
loc_822B38E0:
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a4ce0
	ctx.lr = 0x822B38EC;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b39c8
	if (cr6.eq) goto loc_822B39C8;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3904;
	sub_8271EB28(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x822b394c
	if (!cr6.gt) goto loc_822B394C;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// beq cr6,0x822b394c
	if (cr6.eq) goto loc_822B394C;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// beq cr6,0x822b394c
	if (cr6.eq) goto loc_822B394C;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// beq cr6,0x822b394c
	if (cr6.eq) goto loc_822B394C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x822B3948;
	sub_822AFCD0(ctx, base);
	// mr r30,r29
	r30.u64 = r29.u64;
loc_822B394C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B3964;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B397C;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3990;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B39A4;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r30,80(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822b3a80
	if (cr6.eq) goto loc_822B3A80;
	// addic. r4,r30,-1
	xer.ca = r30.u32 > 0;
	ctx.r4.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// b 0x822b3a6c
	goto loc_822B3A6C;
loc_822B39C8:
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a4ce0
	ctx.lr = 0x822B39D4;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b3b2c
	if (cr6.eq) goto loc_822B3B2C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B39F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3A10;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3A24;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3A38;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x8271eef0
	ctx.lr = 0x822B3A4C;
	sub_8271EEF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lwz r30,80(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x822b3a68
	if (!cr6.eq) goto loc_822B3A68;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x822b3a84
	goto loc_822B3A84;
loc_822B3A68:
	// addic. r4,r30,1
	xer.ca = r30.u32 > 4294967294;
	ctx.r4.s64 = r30.s64 + 1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
loc_822B3A6C:
	// bge 0x822b3a78
	if (!cr0.lt) goto loc_822B3A78;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// b 0x822b3a84
	goto loc_822B3A84;
loc_822B3A78:
	// cmpwi cr6,r4,4
	cr6.compare<int32_t>(ctx.r4.s32, 4, xer);
	// ble cr6,0x822b3a84
	if (!cr6.gt) goto loc_822B3A84;
loc_822B3A80:
	// li r4,4
	ctx.r4.s64 = 4;
loc_822B3A84:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afab0
	ctx.lr = 0x822B3A8C;
	sub_822AFAB0(ctx, base);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x822b3ab4
	if (cr6.eq) goto loc_822B3AB4;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// beq cr6,0x822b3ab4
	if (cr6.eq) goto loc_822B3AB4;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b3ab4
	if (cr6.eq) goto loc_822B3AB4;
	// li r30,3
	r30.s64 = 3;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822b3ab8
	if (!cr6.eq) goto loc_822B3AB8;
loc_822B3AB4:
	// li r30,4
	r30.s64 = 4;
loc_822B3AB8:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B3AD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822B3AEC;
	sub_822B0F10(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-12252(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12252);
	// bl 0x821ec4e8
	ctx.lr = 0x822B3AF8;
	sub_821EC4E8(ctx, base);
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// addi r4,r5,17840
	ctx.r4.s64 = ctx.r5.s64 + 17840;
	// lwz r11,4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// bne cr6,0x822b3b2c
	if (!cr6.eq) goto loc_822B3B2C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f3,11360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11360);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-29232(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -29232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82207ef0
	ctx.lr = 0x822B3B2C;
	sub_82207EF0(ctx, base);
loc_822B3B2C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r11,17268(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// lwz r11,568(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 568);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b3b5c
	if (cr6.eq) goto loc_822B3B5C;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B3B5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B3B5C:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b3b84
	if (cr6.eq) goto loc_822B3B84;
	// li r4,26
	ctx.r4.s64 = 26;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B3B74;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b3b88
	if (!cr6.eq) goto loc_822B3B88;
loc_822B3B84:
	// li r4,0
	ctx.r4.s64 = 0;
loc_822B3B88:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b23d0
	ctx.lr = 0x822B3B90;
	sub_822B23D0(ctx, base);
loc_822B3B90:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822B3B98"))) PPC_WEAK_FUNC(sub_822B3B98);
PPC_FUNC_IMPL(__imp__sub_822B3B98) {
	PPC_FUNC_PROLOGUE();
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x822b1648
	sub_822B1648(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B3BA0"))) PPC_WEAK_FUNC(sub_822B3BA0);
PPC_FUNC_IMPL(__imp__sub_822B3BA0) {
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
	// bl 0x822b2160
	ctx.lr = 0x822B3BC0;
	sub_822B2160(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b3bd8
	if (cr6.eq) goto loc_822B3BD8;
	// bl 0x82130588
	ctx.lr = 0x822B3BD4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822B3BD8:
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

__attribute__((alias("__imp__sub_822B3BF0"))) PPC_WEAK_FUNC(sub_822B3BF0);
PPC_FUNC_IMPL(__imp__sub_822B3BF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x822B3BF8;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d0
	ctx.lr = 0x822B3C00;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B3C1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b4c88
	if (cr6.eq) goto loc_822B4C88;
	// lwz r4,132(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3C34;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4c88
	if (!cr6.eq) goto loc_822B4C88;
	// li r25,0
	r25.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r22,r25
	r22.u64 = r25.u64;
	// bl 0x822a5578
	ctx.lr = 0x822B3C4C;
	sub_822A5578(ctx, base);
	// lhz r11,8(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 8);
	// li r20,1
	r20.s64 = 1;
	// cmplwi cr6,r11,65535
	cr6.compare<uint32_t>(r11.u32, 65535, xer);
	// beq cr6,0x822b3c9c
	if (cr6.eq) goto loc_822B3C9C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b3c80
	if (cr6.eq) goto loc_822B3C80;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r20
	r11.u64 = r20.u64;
	// beq cr6,0x822b3c84
	if (cr6.eq) goto loc_822B3C84;
loc_822B3C80:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_822B3C84:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b3c9c
	if (!cr6.eq) goto loc_822B3C9C;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a5578
	ctx.lr = 0x822B3C98;
	sub_822A5578(ctx, base);
	// lwz r22,116(r3)
	r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
loc_822B3C9C:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// bl 0x8271eb28
	ctx.lr = 0x822B3CA8;
	sub_8271EB28(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// lfs f29,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// beq cr6,0x822b3d24
	if (cr6.eq) goto loc_822B3D24;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822B3CC4;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b3d24
	if (!cr6.eq) goto loc_822B3D24;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// rlwinm r8,r9,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822b3d24
	if (cr6.eq) goto loc_822B3D24;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lfs f0,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 44);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bgt cr6,0x822b3d24
	if (cr6.gt) goto loc_822B3D24;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,17
	ctx.r5.s64 = 17;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x822B3D14;
	sub_822AFCD0(ctx, base);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba1c
	ctx.lr = 0x822B3D20;
	// b 0x823d9228
	return;
loc_822B3D24:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b12b0
	ctx.lr = 0x822B3D2C;
	sub_822B12B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4c88
	if (!cr6.eq) goto loc_822B4C88;
	// bl 0x823bbf80
	ctx.lr = 0x822B3D3C;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4c88
	if (!cr6.eq) goto loc_822B4C88;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3D54;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4c88
	if (!cr6.eq) goto loc_822B4C88;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3D68;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4c88
	if (!cr6.eq) goto loc_822B4C88;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B3D7C;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4c88
	if (!cr6.eq) goto loc_822B4C88;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// stw r25,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r25.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r8,r11,2256
	ctx.r8.s64 = r11.s64 + 2256;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r7,r1,208
	ctx.r7.s64 = ctx.r1.s64 + 208;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// li r5,-1
	ctx.r5.s64 = -1;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f29,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f29,244(r1)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r5,252(r1)
	PPC_STORE_U16(ctx.r1.u32 + 252, ctx.r5.u16);
	// sth r25,254(r1)
	PPC_STORE_U16(ctx.r1.u32 + 254, r25.u16);
	// stb r25,256(r1)
	PPC_STORE_U8(ctx.r1.u32 + 256, r25.u8);
	// sth r25,258(r1)
	PPC_STORE_U16(ctx.r1.u32 + 258, r25.u16);
	// stw r25,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, r25.u32);
	// lwz r11,48(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r27,28(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// bl 0x8271eb28
	ctx.lr = 0x822B3DE4;
	sub_8271EB28(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f27,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f27.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r28,-1
	r28.s64 = -1;
	// li r21,48
	r21.s64 = 48;
	// lfs f26,-13148(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13148);
	f26.f64 = double(temp.f32);
	// li r23,400
	r23.s64 = 400;
	// lfs f28,14884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14884);
	f28.f64 = double(temp.f32);
	// li r24,16
	r24.s64 = 16;
	// lfs f30,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f30.f64 = double(temp.f32);
	// lis r26,-32114
	r26.s64 = -2104623104;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4420
	if (!cr6.eq) goto loc_822B4420;
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822b4420
	if (!cr6.eq) goto loc_822B4420;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x8271eef0
	ctx.lr = 0x822B3E38;
	sub_8271EEF0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4420
	if (!cr6.eq) goto loc_822B4420;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4420
	if (cr6.eq) goto loc_822B4420;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b4420
	if (cr6.eq) goto loc_822B4420;
	// lbz r11,101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4420
	if (!cr6.eq) goto loc_822B4420;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b4420
	if (!cr6.eq) goto loc_822B4420;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,668(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 668);
	// lbz r8,40(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b3edc
	if (cr6.eq) goto loc_822B3EDC;
	// bl 0x82345dd0
	ctx.lr = 0x822B3E94;
	sub_82345DD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b3edc
	if (cr6.eq) goto loc_822B3EDC;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822b3edc
	if (!cr6.eq) goto loc_822B3EDC;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lfs f0,820(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 820);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822b3edc
	if (!cr6.gt) goto loc_822B3EDC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lhz r8,18(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 18);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b3edc
	if (!cr6.eq) goto loc_822B3EDC;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B3EDC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,664(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 664);
	// lbz r8,32(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b3f44
	if (cr6.eq) goto loc_822B3F44;
	// bl 0x82345638
	ctx.lr = 0x822B3EFC;
	sub_82345638(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b3f44
	if (cr6.eq) goto loc_822B3F44;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822b3f44
	if (!cr6.eq) goto loc_822B3F44;
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lfs f0,932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 932);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822b3f44
	if (!cr6.gt) goto loc_822B3F44;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lhz r8,18(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 18);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b3f44
	if (!cr6.eq) goto loc_822B3F44;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B3F44:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822B3F50;
	sub_82332098(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f31,14988(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14988);
	f31.f64 = double(temp.f32);
	// beq cr6,0x822b3fa4
	if (cr6.eq) goto loc_822B3FA4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b3fa4
	if (cr6.eq) goto loc_822B3FA4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bne cr6,0x822b3fa4
	if (!cr6.eq) goto loc_822B3FA4;
	// lfs f0,224(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822b3fa4
	if (!cr6.gt) goto loc_822B3FA4;
	// li r5,2
	ctx.r5.s64 = 2;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B3FA4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lhz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 16);
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822b3fe8
	if (!cr6.gt) goto loc_822B3FE8;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,412(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 412);
	// lbz r9,529(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 529);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b3fe8
	if (!cr6.eq) goto loc_822B3FE8;
	// lfs f0,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822b3fe8
	if (!cr6.gt) goto loc_822B3FE8;
	// li r5,3
	ctx.r5.s64 = 3;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B3FE8:
	// bl 0x82332098
	ctx.lr = 0x822B3FEC;
	sub_82332098(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b4038
	if (cr6.eq) goto loc_822B4038;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 16);
	// cmplwi cr6,r9,32768
	cr6.compare<uint32_t>(ctx.r9.u32, 32768, xer);
	// blt cr6,0x822b4038
	if (cr6.lt) goto loc_822B4038;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,416(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 416);
	// lbz r9,529(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 529);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b4038
	if (!cr6.eq) goto loc_822B4038;
	// lfs f0,224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822b4038
	if (!cr6.gt) goto loc_822B4038;
	// li r5,4
	ctx.r5.s64 = 4;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B4038:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822b4084
	if (!cr6.gt) goto loc_822B4084;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r8,128(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 128);
	// lfs f0,44(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	f0.f64 = double(temp.f32);
	// lfs f13,292(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 292);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822b4084
	if (!cr6.gt) goto loc_822B4084;
	// lfs f0,580(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 580);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// blt cr6,0x822b4084
	if (cr6.lt) goto loc_822B4084;
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B4084:
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r11,676(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b40e0
	if (cr6.eq) goto loc_822B40E0;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b40e0
	if (cr6.eq) goto loc_822B40E0;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x822b40e0
	if (cr6.eq) goto loc_822B40E0;
	// li r4,22
	ctx.r4.s64 = 22;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4ce0
	ctx.lr = 0x822B40B4;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b40d8
	if (!cr6.eq) goto loc_822B40D8;
	// li r4,23
	ctx.r4.s64 = 23;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4ce0
	ctx.lr = 0x822B40CC;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b40e0
	if (cr6.eq) goto loc_822B40E0;
loc_822B40D8:
	// li r5,11
	ctx.r5.s64 = 11;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B40E0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r3,672(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b412c
	if (cr6.eq) goto loc_822B412C;
	// bl 0x8234fdf0
	ctx.lr = 0x822B40FC;
	sub_8234FDF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b412c
	if (cr6.eq) goto loc_822B412C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,672(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// lbz r7,13(r8)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r8.u32 + 13);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822b412c
	if (cr6.eq) goto loc_822B412C;
	// li r5,12
	ctx.r5.s64 = 12;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B412C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822B4138;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b4184
	if (!cr6.eq) goto loc_822B4184;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lhz r8,18(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 18);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b4184
	if (cr6.eq) goto loc_822B4184;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x822b417c
	if (!cr6.eq) goto loc_822B417C;
	// li r5,5
	ctx.r5.s64 = 5;
	// b 0x822b441c
	goto loc_822B441C;
loc_822B417C:
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x822b441c
	goto loc_822B441C;
loc_822B4184:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822B4190;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b41e0
	if (cr6.eq) goto loc_822B41E0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r9,18(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 18);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b41e0
	if (cr6.eq) goto loc_822B41E0;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f26
	cr6.compare(ctx.f13.f64, f26.f64);
	// ble cr6,0x822b41e0
	if (!cr6.gt) goto loc_822B41E0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822b41e0
	if (!cr6.gt) goto loc_822B41E0;
	// li r5,9
	ctx.r5.s64 = 9;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B41E0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B41FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f0,17032(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822b4360
	if (!cr6.gt) goto loc_822B4360;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,668(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 668);
	// lbz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b4360
	if (!cr6.eq) goto loc_822B4360;
	// lwz r10,664(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// lbz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b4360
	if (!cr6.eq) goto loc_822B4360;
	// lwz r30,0(r13)
	r30.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r29,72
	r29.s64 = 72;
	// lbzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b4254
	if (cr6.eq) goto loc_822B4254;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// b 0x822b4258
	goto loc_822B4258;
loc_822B4254:
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
loc_822B4258:
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// lwz r3,-23452(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -23452);
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r25.u32);
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// stw r20,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r20.u32);
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// lfs f31,3732(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3732);
	f31.f64 = double(temp.f32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82574ca0
	ctx.lr = 0x822B428C;
	sub_82574CA0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4420
	if (!cr6.eq) goto loc_822B4420;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lbzx r10,r29,r30
	ctx.r10.u64 = PPC_LOAD_U8(r29.u32 + r30.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r9,r11,208
	ctx.r9.s64 = r11.s64 + 208;
	// bne cr6,0x822b42b0
	if (!cr6.eq) goto loc_822B42B0;
	// addi r9,r11,144
	ctx.r9.s64 = r11.s64 + 144;
loc_822B42B0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lvx128 v0,r9,r21
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// bne cr6,0x822b42c4
	if (!cr6.eq) goto loc_822B42C4;
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
loc_822B42C4:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f31,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r11,r23
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f28,96(r1)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r10,r24
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r1,160
	r30.s64 = ctx.r1.s64 + 160;
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lvlx128 v61,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v0,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f0,-1684(r5)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -1684);
	f0.f64 = double(temp.f32);
	// vspltw128 v11,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// li r9,4
	ctx.r9.s64 = 4;
	// lvx128 v10,r0,r7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// lwz r3,-23452(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -23452);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// vmaddfp v9,v10,v11,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x822B4350;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4420
	if (!cr6.eq) goto loc_822B4420;
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B4360:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82332098
	ctx.lr = 0x822B436C;
	sub_82332098(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b43b4
	if (cr6.eq) goto loc_822B43B4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x822b43b4
	if (!cr6.eq) goto loc_822B43B4;
	// lfs f0,144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 144);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x822b43b4
	if (cr6.eq) goto loc_822B43B4;
	// lfs f0,224(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 224);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x822b43b4
	if (!cr6.gt) goto loc_822B43B4;
	// li r5,10
	ctx.r5.s64 = 10;
	// b 0x822b4410
	goto loc_822B4410;
loc_822B43B4:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822b4420
	if (!cr6.gt) goto loc_822B4420;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a5578
	ctx.lr = 0x822B43CC;
	sub_822A5578(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f0,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	f0.f64 = double(temp.f32);
	// lfs f13,36(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822b4420
	if (cr6.lt) goto loc_822B4420;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r31
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B4400;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822b4420
	if (!cr6.eq) goto loc_822B4420;
	// li r5,13
	ctx.r5.s64 = 13;
loc_822B4410:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,1
	ctx.r4.s64 = 1;
loc_822B441C:
	// bl 0x822afcd0
	ctx.lr = 0x822B4420;
	sub_822AFCD0(ctx, base);
loc_822B4420:
	// lwz r8,84(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,784(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 784);
	// cmpwi cr6,r9,-1
	cr6.compare<int32_t>(ctx.r9.s32, -1, xer);
	// beq cr6,0x822b44f8
	if (cr6.eq) goto loc_822B44F8;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x822b4458
	if (!cr6.eq) goto loc_822B4458;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lhz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 16);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822b4458
	if (cr6.eq) goto loc_822B4458;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f28.f64;
	// b 0x822b44e8
	goto loc_822B44E8;
loc_822B4458:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r7,668(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 668);
	// lbz r6,40(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 40);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822b44a4
	if (cr6.eq) goto loc_822B44A4;
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r6,18(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 18);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x822b44a4
	if (!cr6.eq) goto loc_822B44A4;
	// lwz r7,80(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r7,4
	cr6.compare<int32_t>(ctx.r7.s32, 4, xer);
	// bne cr6,0x822b44a4
	if (!cr6.eq) goto loc_822B44A4;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822b44a4
	if (cr6.eq) goto loc_822B44A4;
	// lfs f0,820(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 820);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bgt cr6,0x822b44e4
	if (cr6.gt) goto loc_822B44E4;
loc_822B44A4:
	// lwz r10,664(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// lbz r7,32(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822b44f8
	if (cr6.eq) goto loc_822B44F8;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b44f8
	if (!cr6.eq) goto loc_822B44F8;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822b44f8
	if (!cr6.eq) goto loc_822B44F8;
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// beq cr6,0x822b44f8
	if (cr6.eq) goto loc_822B44F8;
	// lfs f0,932(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 932);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822b44f8
	if (!cr6.gt) goto loc_822B44F8;
loc_822B44E4:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
loc_822B44E8:
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B44F8;
	sub_822AFCD0(ctx, base);
loc_822B44F8:
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r11,784(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// cmplwi cr6,r11,17
	cr6.compare<uint32_t>(r11.u32, 17, xer);
	// bgt cr6,0x822b4c30
	if (cr6.gt) goto loc_822B4C30;
	// lis r12,-32213
	r12.s64 = -2111111168;
	// addi r12,r12,17696
	r12.s64 = r12.s64 + 17696;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_822B4688;
	case 1:
		goto loc_822B46B4;
	case 2:
		goto loc_822B4770;
	case 3:
		goto loc_822B47AC;
	case 4:
		goto loc_822B47CC;
	case 5:
		goto loc_822B4844;
	case 6:
		goto loc_822B4844;
	case 7:
		goto loc_822B47F8;
	case 8:
		goto loc_822B4588;
	case 9:
		goto loc_822B4894;
	case 10:
		goto loc_822B48F0;
	case 11:
		goto loc_822B4BC0;
	case 12:
		goto loc_822B4914;
	case 13:
		goto loc_822B4A60;
	case 14:
		goto loc_822B4C30;
	case 15:
		goto loc_822B4C30;
	case 16:
		goto loc_822B4C30;
	case 17:
		goto loc_822B4568;
	default:
		__builtin_unreachable();
	}
	// lwz r17,18056(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18056);
	// lwz r17,18100(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18100);
	// lwz r17,18288(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18288);
	// lwz r17,18348(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18348);
	// lwz r17,18380(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18380);
	// lwz r17,18500(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18500);
	// lwz r17,18500(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18500);
	// lwz r17,18424(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18424);
	// lwz r17,17800(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 17800);
	// lwz r17,18580(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18580);
	// lwz r17,18672(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18672);
	// lwz r17,19392(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 19392);
	// lwz r17,18708(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 18708);
	// lwz r17,19040(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 19040);
	// lwz r17,19504(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 19504);
	// lwz r17,19504(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 19504);
	// lwz r17,19504(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 19504);
	// lwz r17,17768(r11)
	r17.u64 = PPC_LOAD_U32(r11.u32 + 17768);
loc_822B4568:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 592);
	// rlwinm r7,r8,0,29,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x822b4c30
	if (!cr6.eq) goto loc_822B4C30;
	// b 0x822b4c1c
	goto loc_822B4C1C;
loc_822B4588:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// bne cr6,0x822b45ac
	if (!cr6.eq) goto loc_822B45AC;
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
loc_822B45AC:
	// lvx128 v0,r10,r21
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r21.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// bne cr6,0x822b45c0
	if (!cr6.eq) goto loc_822B45C0;
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
loc_822B45C0:
	// stfs f28,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v13,r10,r24
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v60,r11,r23
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,144
	r11.s64 = ctx.r1.s64 + 144;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// addi r30,r1,160
	r30.s64 = ctx.r1.s64 + 160;
	// lwz r3,-23452(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -23452);
	// li r10,1
	ctx.r10.s64 = 1;
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,4
	ctx.r9.s64 = 4;
	// lfs f0,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f27
	ctx.f13.f64 = double(float(f0.f64 - f27.f64));
	// lvlx128 v59,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// mr r8,r28
	ctx.r8.u64 = r28.u64;
	// vspltw128 v12,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v58,r0,r7
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// vmaddfp v11,v13,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// vaddfp128 v57,v58,v11
	simde_mm_store_ps(v57.f32, simde_mm_add_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(ctx.v11.f32)));
	// stvx128 v11,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x822B4634;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b4c30
	if (cr6.eq) goto loc_822B4C30;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B4658;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f28.f64);
	// bgt cr6,0x822b4c1c
	if (cr6.gt) goto loc_822B4C1C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B467C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// bgt cr6,0x822b4c30
	if (cr6.gt) goto loc_822B4C30;
	// b 0x822b4c1c
	goto loc_822B4C1C;
loc_822B4688:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,668(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 668);
	// lbz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b4c1c
	if (cr6.eq) goto loc_822B4C1C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x822b4c18
	goto loc_822B4C18;
loc_822B46B4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,664(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 664);
	// lbz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b46e0
	if (cr6.eq) goto loc_822B46E0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r10,18(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 18);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b46f4
	if (cr6.eq) goto loc_822B46F4;
loc_822B46E0:
	// li r5,-1
	ctx.r5.s64 = -1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B46F4;
	sub_822AFCD0(ctx, base);
loc_822B46F4:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lbz r10,156(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b4c30
	if (cr6.eq) goto loc_822B4C30;
	// addi r11,r11,80
	r11.s64 = r11.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b4c30
	if (cr6.eq) goto loc_822B4C30;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bne cr6,0x822b474c
	if (!cr6.eq) goto loc_822B474C;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x8271f3b0
	ctx.lr = 0x822B472C;
	sub_8271F3B0(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B4744;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// b 0x822b4754
	goto loc_822B4754;
loc_822B474C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
loc_822B4754:
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B4764;
	sub_822AFCD0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stb r25,2817(r11)
	PPC_STORE_U8(r11.u32 + 2817, r25.u8);
	// b 0x822b4c30
	goto loc_822B4C30;
loc_822B4770:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r8,40(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 40);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b4c1c
	if (cr6.eq) goto loc_822B4C1C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,16(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bgt cr6,0x822b4c1c
	if (cr6.gt) goto loc_822B4C1C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x822b4c18
	goto loc_822B4C18;
loc_822B47AC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lhz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bgt cr6,0x822b4c30
	if (cr6.gt) goto loc_822B4C30;
	// b 0x822b4c1c
	goto loc_822B4C1C;
loc_822B47CC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 16);
	// cmplwi cr6,r9,32768
	cr6.compare<uint32_t>(ctx.r9.u32, 32768, xer);
	// bge cr6,0x822b4c30
	if (!cr6.lt) goto loc_822B4C30;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,416(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 416);
	// lbz r9,529(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 529);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// b 0x822b4c18
	goto loc_822B4C18;
loc_822B47F8:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x822b4c1c
	if (cr6.eq) goto loc_822B4C1C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,580(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 580);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// blt cr6,0x822b4c1c
	if (cr6.lt) goto loc_822B4C1C;
	// lwz r11,128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lwz r10,24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lfs f0,292(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 292);
	f0.f64 = double(temp.f32);
	// lfs f13,44(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = f0.u64 & ~0x8000000000000000;
	// fmuls f11,f13,f28
	ctx.f11.f64 = double(float(ctx.f13.f64 * f28.f64));
	// fcmpu cr6,f12,f11
	cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bge cr6,0x822b4c30
	if (!cr6.lt) goto loc_822B4C30;
	// b 0x822b4c1c
	goto loc_822B4C1C;
loc_822B4844:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lhz r7,18(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 18);
	// extsh r11,r7
	r11.s64 = ctx.r7.s16;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4c1c
	if (cr6.eq) goto loc_822B4C1C;
	// lfs f0,240(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 240);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// beq cr6,0x822b4c30
	if (cr6.eq) goto loc_822B4C30;
	// fneg f13,f0
	ctx.f13.u64 = f0.u64 ^ 0x8000000000000000;
	// extsw r11,r11
	r11.s64 = r11.s32;
	// std r11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, r11.u64);
	// lfd f10,96(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// fsel f12,f13,f29,f27
	ctx.f12.f64 = ctx.f13.f64 >= 0.0 ? f29.f64 : f27.f64;
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fsel f11,f0,f12,f30
	ctx.f11.f64 = f0.f64 >= 0.0 ? ctx.f12.f64 : f30.f64;
	// fcmpu cr6,f8,f11
	cr6.compare(ctx.f8.f64, ctx.f11.f64);
	// b 0x822b4c18
	goto loc_822B4C18;
loc_822B4894:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lhz r9,18(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 18);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b4c1c
	if (cr6.eq) goto loc_822B4C1C;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f0,36(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f26
	cr6.compare(ctx.f13.f64, f26.f64);
	// blt cr6,0x822b4c1c
	if (cr6.lt) goto loc_822B4C1C;
	// lfs f0,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f26
	cr6.compare(ctx.f13.f64, f26.f64);
	// bgt cr6,0x822b4c1c
	if (cr6.gt) goto loc_822B4C1C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lfs f0,580(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 580);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f28
	cr6.compare(f0.f64, f28.f64);
	// bgt cr6,0x822b4c1c
	if (cr6.gt) goto loc_822B4C1C;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lbz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 40);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x822b4c18
	goto loc_822B4C18;
loc_822B48F0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f0,11360(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	f0.f64 = double(temp.f32);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f13,144(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822b4c30
	if (!cr6.lt) goto loc_822B4C30;
	// b 0x822b4c1c
	goto loc_822B4C1C;
loc_822B4914:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,672(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4938
	if (cr6.eq) goto loc_822B4938;
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b494c
	if (!cr6.eq) goto loc_822B494C;
loc_822B4938:
	// li r5,-1
	ctx.r5.s64 = -1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B494C;
	sub_822AFCD0(ctx, base);
loc_822B494C:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x822b4c30
	if (cr6.eq) goto loc_822B4C30;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4960;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4a40
	if (!cr6.eq) goto loc_822B4A40;
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4978;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4a40
	if (!cr6.eq) goto loc_822B4A40;
	// li r4,21
	ctx.r4.s64 = 21;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4990;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4a40
	if (!cr6.eq) goto loc_822B4A40;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B49A8;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4a40
	if (!cr6.eq) goto loc_822B4A40;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B49C0;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4a40
	if (!cr6.eq) goto loc_822B4A40;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B49D8;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4a40
	if (!cr6.eq) goto loc_822B4A40;
	// li r4,26
	ctx.r4.s64 = 26;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B49F0;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4a40
	if (!cr6.eq) goto loc_822B4A40;
	// li r4,27
	ctx.r4.s64 = 27;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B4A08;
	sub_822A4BB8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bgt cr6,0x822b4a40
	if (cr6.gt) goto loc_822B4A40;
	// li r4,28
	ctx.r4.s64 = 28;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B4A24;
	sub_822A4BB8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bgt cr6,0x822b4a40
	if (cr6.gt) goto loc_822B4A40;
	// li r4,29
	ctx.r4.s64 = 29;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B4A38;
	sub_822A4BB8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x822b4c30
	if (!cr6.gt) goto loc_822B4C30;
loc_822B4A40:
	// li r5,-1
	ctx.r5.s64 = -1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B4A54;
	sub_822AFCD0(ctx, base);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stb r25,2828(r11)
	PPC_STORE_U8(r11.u32 + 2828, r25.u8);
	// b 0x822b4c30
	goto loc_822B4C30;
loc_822B4A60:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a5578
	ctx.lr = 0x822B4A68;
	sub_822A5578(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lfs f0,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// lfs f30,-17424(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	f30.f64 = double(temp.f32);
	// bne cr6,0x822b4a90
	if (!cr6.eq) goto loc_822B4A90;
	// li r5,-1
	ctx.r5.s64 = -1;
	// fmr f1,f30
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B4A90;
	sub_822AFCD0(ctx, base);
loc_822B4A90:
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x822b4c30
	if (cr6.eq) goto loc_822B4C30;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4AA4;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4b9c
	if (!cr6.eq) goto loc_822B4B9C;
	// li r4,44
	ctx.r4.s64 = 44;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4ABC;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4b9c
	if (!cr6.eq) goto loc_822B4B9C;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4AD4;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4b9c
	if (!cr6.eq) goto loc_822B4B9C;
	// li r4,26
	ctx.r4.s64 = 26;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4AEC;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4b9c
	if (!cr6.eq) goto loc_822B4B9C;
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4B04;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4b9c
	if (!cr6.eq) goto loc_822B4B9C;
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4B1C;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4b9c
	if (!cr6.eq) goto loc_822B4B9C;
	// li r4,21
	ctx.r4.s64 = 21;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4B34;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4b9c
	if (!cr6.eq) goto loc_822B4B9C;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B4B4C;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4b9c
	if (!cr6.eq) goto loc_822B4B9C;
	// li r4,27
	ctx.r4.s64 = 27;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B4B64;
	sub_822A4BB8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f31,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// bgt cr6,0x822b4b9c
	if (cr6.gt) goto loc_822B4B9C;
	// li r4,28
	ctx.r4.s64 = 28;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B4B80;
	sub_822A4BB8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bgt cr6,0x822b4b9c
	if (cr6.gt) goto loc_822B4B9C;
	// li r4,29
	ctx.r4.s64 = 29;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4bb8
	ctx.lr = 0x822B4B94;
	sub_822A4BB8(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// ble cr6,0x822b4c30
	if (!cr6.gt) goto loc_822B4C30;
loc_822B4B9C:
	// li r5,-1
	ctx.r5.s64 = -1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B4BB0;
	sub_822AFCD0(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x822a5578
	ctx.lr = 0x822B4BB8;
	sub_822A5578(ctx, base);
	// stfs f29,112(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// b 0x822b4c30
	goto loc_822B4C30;
loc_822B4BC0:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,676(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 676);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4c1c
	if (cr6.eq) goto loc_822B4C1C;
	// lwz r11,16(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4c1c
	if (cr6.eq) goto loc_822B4C1C;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x822b4c30
	if (cr6.eq) goto loc_822B4C30;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4ce0
	ctx.lr = 0x822B4BF8;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4c1c
	if (!cr6.eq) goto loc_822B4C1C;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822a4ce0
	ctx.lr = 0x822B4C10;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_822B4C18:
	// beq cr6,0x822b4c30
	if (cr6.eq) goto loc_822B4C30;
loc_822B4C1C:
	// li r5,-1
	ctx.r5.s64 = -1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822afcd0
	ctx.lr = 0x822B4C30;
	sub_822AFCD0(ctx, base);
loc_822B4C30:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,672(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 672);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4c54
	if (cr6.eq) goto loc_822B4C54;
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4c5c
	if (!cr6.eq) goto loc_822B4C5C;
loc_822B4C54:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stb r20,2828(r11)
	PPC_STORE_U8(r11.u32 + 2828, r20.u8);
loc_822B4C5C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,664(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4c80
	if (cr6.eq) goto loc_822B4C80;
	// lbz r11,32(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4c88
	if (!cr6.eq) goto loc_822B4C88;
loc_822B4C80:
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// stb r20,2817(r11)
	PPC_STORE_U8(r11.u32 + 2817, r20.u8);
loc_822B4C88:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba1c
	ctx.lr = 0x822B4C94;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_822B4C98"))) PPC_WEAK_FUNC(sub_822B4C98);
PPC_FUNC_IMPL(__imp__sub_822B4C98) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822B4CA0;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823db9c8
	ctx.lr = 0x822B4CA8;
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b58e0
	if (cr6.eq) goto loc_822B58E0;
	// lwz r11,656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822b58e0
	if (!cr6.eq) goto loc_822B58E0;
	// li r28,0
	r28.s64 = 0;
	// mr r30,r28
	r30.u64 = r28.u64;
	// bl 0x822b12b0
	ctx.lr = 0x822B4CD8;
	sub_822B12B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r26,1
	r26.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b4d4c
	if (cr6.eq) goto loc_822B4D4C;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// bl 0x823189d0
	ctx.lr = 0x822B4CF0;
	sub_823189D0(ctx, base);
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x822b4d0c
	if (cr6.lt) goto loc_822B4D0C;
	// cmpwi cr6,r10,5
	cr6.compare<int32_t>(ctx.r10.s32, 5, xer);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// blt cr6,0x822b4d10
	if (cr6.lt) goto loc_822B4D10;
loc_822B4D0C:
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
loc_822B4D10:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b4d20
	if (!cr6.eq) goto loc_822B4D20;
	// li r10,2
	ctx.r10.s64 = 2;
loc_822B4D20:
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822b4d3c
	if (cr6.lt) goto loc_822B4D3C;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// blt cr6,0x822b4d40
	if (cr6.lt) goto loc_822B4D40;
loc_822B4D3C:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_822B4D40:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r30,r10,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
loc_822B4D4C:
	// clrlwi r10,r30,24
	ctx.r10.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b4d60
	if (!cr6.eq) goto loc_822B4D60;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stb r26,92(r11)
	PPC_STORE_U8(r11.u32 + 92, r26.u8);
loc_822B4D60:
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r11,-6148(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -6148);
	// lfs f25,14884(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f25.f64 = double(temp.f32);
	// lfs f26,3732(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3732);
	f26.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f31,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lfs f30,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f30.f64 = double(temp.f32);
	// beq cr6,0x822b4dc4
	if (cr6.eq) goto loc_822B4DC4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r9,-6144(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b4dc4
	if (cr6.eq) goto loc_822B4DC4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b28c8
	ctx.lr = 0x822B4DA8;
	sub_822B28C8(ctx, base);
	// lwz r11,-6148(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -6148);
	// lbz r11,156(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b543c
	if (cr6.eq) goto loc_822B543C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b0370
	ctx.lr = 0x822B4DC0;
	sub_822B0370(ctx, base);
	// b 0x822b543c
	goto loc_822B543C;
loc_822B4DC4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,592(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 592);
	// rlwinm r7,r8,0,26,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x3C;
	// rlwinm r7,r7,0,29,27
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF7;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x822b4e0c
	if (cr6.eq) goto loc_822B4E0C;
	// lwz r4,72(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B4DF8;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822aff10
	ctx.lr = 0x822B4E08;
	sub_822AFF10(ctx, base);
	// b 0x822b543c
	goto loc_822B543C;
loc_822B4E0C:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4eb0
	if (cr6.eq) goto loc_822B4EB0;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b4eb0
	if (cr6.eq) goto loc_822B4EB0;
	// lwz r11,72(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,3
	cr6.compare<int32_t>(ctx.r10.s32, 3, xer);
	// bne cr6,0x822b4eb0
	if (!cr6.eq) goto loc_822B4EB0;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B4E3C;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4eb0
	if (!cr6.eq) goto loc_822B4EB0;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B4E50;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4eb0
	if (!cr6.eq) goto loc_822B4EB0;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,56(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b543c
	if (cr6.eq) goto loc_822B543C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32123
	ctx.r10.s64 = -2105212928;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// addi r9,r10,23088
	ctx.r9.s64 = ctx.r10.s64 + 23088;
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// ld r7,23088(r10)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r10.u32 + 23088);
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// ld r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r9.u32 + 8);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwz r10,72(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 72);
	// lfs f1,796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8271e9a0
	ctx.lr = 0x822B4EA0;
	sub_8271E9A0(ctx, base);
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r3,84(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// bl 0x82316148
	ctx.lr = 0x822B4EAC;
	sub_82316148(ctx, base);
	// b 0x822b543c
	goto loc_822B543C;
loc_822B4EB0:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b4f6c
	if (cr6.eq) goto loc_822B4F6C;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x822b4f6c
	if (cr6.eq) goto loc_822B4F6C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,72(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmpwi cr6,r8,3
	cr6.compare<int32_t>(ctx.r8.s32, 3, xer);
	// beq cr6,0x822b4f6c
	if (cr6.eq) goto loc_822B4F6C;
	// lwz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B4EE8;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b4f6c
	if (cr6.eq) goto loc_822B4F6C;
	// lwz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x822B4EFC;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b4f6c
	if (!cr6.eq) goto loc_822B4F6C;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x8271eb28
	ctx.lr = 0x822B4F1C;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r9,-32123
	ctx.r9.s64 = -2105212928;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r8,r9,23088
	ctx.r8.s64 = ctx.r9.s64 + 23088;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r7,r11,11
	ctx.r7.s64 = r11.s64 + 11;
	// lwz r6,48(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// rlwinm r4,r7,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// ld r7,23088(r9)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r9.u32 + 23088);
	// lwz r11,16(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// ld r8,8(r8)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r8.u32 + 8);
	// rldicr r9,r11,32,63
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFFFFFFFFFF;
	// lwz r10,72(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 72);
	// lwzx r4,r4,r31
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + r31.u32);
	// lfs f1,800(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 800);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8271e9a0
	ctx.lr = 0x822B4F68;
	sub_8271E9A0(ctx, base);
	// b 0x822b543c
	goto loc_822B543C;
loc_822B4F6C:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r28
	r29.u64 = r28.u64;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// cmplwi cr6,r9,65535
	cr6.compare<uint32_t>(ctx.r9.u32, 65535, xer);
	// beq cr6,0x822b4fc4
	if (cr6.eq) goto loc_822B4FC4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b4fac
	if (cr6.eq) goto loc_822B4FAC;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// beq cr6,0x822b4fb0
	if (cr6.eq) goto loc_822B4FB0;
loc_822B4FAC:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_822B4FB0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b4fc4
	if (!cr6.eq) goto loc_822B4FC4;
	// bl 0x822a5578
	ctx.lr = 0x822B4FC0;
	sub_822A5578(ctx, base);
	// lwz r29,116(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
loc_822B4FC4:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b5048
	if (!cr6.eq) goto loc_822B5048;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r11,r11,11
	r11.s64 = r11.s64 + 11;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r30,r10,r31
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B4FFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x8271e930
	ctx.lr = 0x822B5008;
	sub_8271E930(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a93a8
	ctx.lr = 0x822B5014;
	sub_822A93A8(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r3,r11,988
	ctx.r3.s64 = r11.s64 + 988;
	// bl 0x822eb078
	ctx.lr = 0x822B5020;
	sub_822EB078(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,-12252(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12252);
	// lwz r6,1740(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r5,r6,0,26,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822b543c
	if (cr6.eq) goto loc_822B543C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x821ec468
	ctx.lr = 0x822B5044;
	sub_821EC468(ctx, base);
	// b 0x822b543c
	goto loc_822B543C;
loc_822B5048:
	// lwz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b536c
	if (!cr6.eq) goto loc_822B536C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmr f28,f30
	ctx.fpscr.disableFlushMode();
	f28.f64 = f30.f64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// lfs f27,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f27.f64 = double(temp.f32);
	// beq cr6,0x822b50a4
	if (cr6.eq) goto loc_822B50A4;
	// li r4,22
	ctx.r4.s64 = 22;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B5074;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5088
	if (cr6.eq) goto loc_822B5088;
	// fmr f28,f27
	ctx.fpscr.disableFlushMode();
	f28.f64 = f27.f64;
	// b 0x822b50a4
	goto loc_822B50A4;
loc_822B5088:
	// li r4,23
	ctx.r4.s64 = 23;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B5094;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b50a4
	if (cr6.eq) goto loc_822B50A4;
	// fmr f28,f31
	ctx.fpscr.disableFlushMode();
	f28.f64 = f31.f64;
loc_822B50A4:
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// fmr f29,f30
	ctx.fpscr.disableFlushMode();
	f29.f64 = f30.f64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// addi r30,r10,29952
	r30.s64 = ctx.r10.s64 + 29952;
	// lfs f13,452(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 452);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,88(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f28
	ctx.f12.f64 = double(float(f0.f64 * f28.f64));
	// fmadds f11,f12,f26,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 * f26.f64 + ctx.f13.f64));
	// stfs f11,452(r11)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r11.u32 + 452, temp.u32);
	// beq cr6,0x822b510c
	if (cr6.eq) goto loc_822B510C;
	// li r4,24
	ctx.r4.s64 = 24;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B50DC;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b50f0
	if (cr6.eq) goto loc_822B50F0;
	// fmr f29,f31
	ctx.fpscr.disableFlushMode();
	f29.f64 = f31.f64;
	// b 0x822b510c
	goto loc_822B510C;
loc_822B50F0:
	// li r4,25
	ctx.r4.s64 = 25;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B50FC;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b510c
	if (cr6.eq) goto loc_822B510C;
	// fmr f29,f27
	ctx.fpscr.disableFlushMode();
	f29.f64 = f27.f64;
loc_822B510C:
	// lfs f0,88(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 88);
	f0.f64 = double(temp.f32);
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// fmuls f12,f0,f29
	ctx.f12.f64 = double(float(f0.f64 * f29.f64));
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lfs f11,456(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 456);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,-28872(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28872);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,29936(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 29936);
	f0.f64 = double(temp.f32);
	// fmadds f10,f12,f13,f11
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f13.f64 + ctx.f11.f64));
	// fsel f9,f10,f10,f30
	ctx.f9.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f30.f64;
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsel f7,f8,f0,f9
	ctx.f7.f64 = ctx.f8.f64 >= 0.0 ? f0.f64 : ctx.f9.f64;
	// stfs f7,456(r11)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r11.u32 + 456, temp.u32);
	// bl 0x82387a18
	ctx.lr = 0x822B5144;
	sub_82387A18(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r30,r11,988
	r30.s64 = r11.s64 + 988;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B5170;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lfs f0,-29232(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822b5318
	if (!cr6.gt) goto loc_822B5318;
	// lbz r11,88(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 88);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// lwz r11,64(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 64);
	// lfs f0,452(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 452);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bne cr6,0x822b51a8
	if (!cr6.eq) goto loc_822B51A8;
	// lfs f0,456(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 456);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// beq cr6,0x822b543c
	if (cr6.eq) goto loc_822B543C;
loc_822B51A8:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lwz r7,0(r13)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r8,r11,2256
	ctx.r8.s64 = r11.s64 + 2256;
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// li r3,72
	ctx.r3.s64 = 72;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lbzx r10,r3,r7
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + ctx.r7.u32);
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// sth r4,204(r1)
	PPC_STORE_U16(ctx.r1.u32 + 204, ctx.r4.u16);
	// stfs f30,196(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// sth r28,206(r1)
	PPC_STORE_U16(ctx.r1.u32 + 206, r28.u16);
	// stb r28,208(r1)
	PPC_STORE_U8(ctx.r1.u32 + 208, r28.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// sth r28,210(r1)
	PPC_STORE_U16(ctx.r1.u32 + 210, r28.u16);
	// stw r28,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r28.u32);
	// lwz r11,48(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// addi r8,r11,208
	ctx.r8.s64 = r11.s64 + 208;
	// lwz r6,28(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// bne cr6,0x822b5218
	if (!cr6.eq) goto loc_822B5218;
	// addi r8,r11,144
	ctx.r8.s64 = r11.s64 + 144;
loc_822B5218:
	// li r7,48
	ctx.r7.s64 = 48;
	// lwz r11,48(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// addi r10,r11,208
	ctx.r10.s64 = r11.s64 + 208;
	// lvx128 v0,r8,r7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bne cr6,0x822b5234
	if (!cr6.eq) goto loc_822B5234;
	// addi r10,r11,144
	ctx.r10.s64 = r11.s64 + 144;
loc_822B5234:
	// li r9,400
	ctx.r9.s64 = 400;
	// stfs f26,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f26.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f25,100(r1)
	temp.f32 = float(f25.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,100
	ctx.r4.s64 = ctx.r1.s64 + 100;
	// lvx128 v63,r11,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,16
	ctx.r3.s64 = 16;
	// lvlx128 v62,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,224
	r29.s64 = ctx.r1.s64 + 224;
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// addi r25,r1,240
	r25.s64 = ctx.r1.s64 + 240;
	// lvlx128 v61,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// lvx128 v12,r10,r3
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v11,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v0,v12,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f0,-1684(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -1684);
	f0.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v10,r0,r5
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32114
	ctx.r7.s64 = -2104623104;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// lwz r3,-23452(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -23452);
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// addi r4,r1,224
	ctx.r4.s64 = ctx.r1.s64 + 224;
	// vmaddfp v9,v10,v11,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v0,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82574418
	ctx.lr = 0x822B52C8;
	sub_82574418(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822eb400
	ctx.lr = 0x822B52D8;
	sub_822EB400(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// lis r11,-32237
	r11.s64 = -2112684032;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// addi r8,r11,0
	ctx.r8.s64 = r11.s64 + 0;
	// addi r7,r10,0
	ctx.r7.s64 = ctx.r10.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x821ed368
	ctx.lr = 0x822B5314;
	sub_821ED368(ctx, base);
	// b 0x822b543c
	goto loc_822B543C;
loc_822B5318:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B5334;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f30.f64);
	// bgt cr6,0x822b543c
	if (cr6.gt) goto loc_822B543C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822eb078
	ctx.lr = 0x822B5344;
	sub_822EB078(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b543c
	if (cr6.eq) goto loc_822B543C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x821ec468
	ctx.lr = 0x822B5368;
	sub_821EC468(ctx, base);
	// b 0x822b543c
	goto loc_822B543C;
loc_822B536C:
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b53ac
	if (!cr6.eq) goto loc_822B53AC;
	// lwz r11,784(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 784);
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// bne cr6,0x822b53ac
	if (!cr6.eq) goto loc_822B53AC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822b53ac
	if (cr6.eq) goto loc_822B53AC;
	// li r4,26
	ctx.r4.s64 = 26;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B5398;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b53ac
	if (cr6.eq) goto loc_822B53AC;
	// fmr f29,f30
	ctx.fpscr.disableFlushMode();
	f29.f64 = f30.f64;
	// b 0x822b53d8
	goto loc_822B53D8;
loc_822B53AC:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplw cr6,r9,r11
	cr6.compare<uint32_t>(ctx.r9.u32, r11.u32, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// lwz r11,784(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bne cr6,0x822b543c
	if (!cr6.eq) goto loc_822B543C;
	// fmr f29,f30
	ctx.fpscr.disableFlushMode();
	f29.f64 = f30.f64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822b5418
	if (cr6.eq) goto loc_822B5418;
loc_822B53D8:
	// li r4,22
	ctx.r4.s64 = 22;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B53E4;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b53fc
	if (cr6.eq) goto loc_822B53FC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f29,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f29.f64 = double(temp.f32);
	// b 0x822b5418
	goto loc_822B5418;
loc_822B53FC:
	// li r4,23
	ctx.r4.s64 = 23;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a4db0
	ctx.lr = 0x822B5408;
	sub_822A4DB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5418
	if (cr6.eq) goto loc_822B5418;
	// fmr f29,f31
	ctx.fpscr.disableFlushMode();
	f29.f64 = f31.f64;
loc_822B5418:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lwz r10,84(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lwz r11,576(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 576);
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f29
	f0.f64 = double(float(f0.f64 * f29.f64));
	// lfs f13,20(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f12,f0,f26,f13
	ctx.f12.f64 = double(float(f0.f64 * f26.f64 + ctx.f13.f64));
	// stfs f12,20(r11)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r11.u32 + 20, temp.u32);
loc_822B543C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,89(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 89);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// lfs f27,17032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	f27.f64 = double(temp.f32);
	// lfs f24,-12084(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12084);
	f24.f64 = double(temp.f32);
	// bne cr6,0x822b55ec
	if (!cr6.eq) goto loc_822B55EC;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lfs f29,224(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 224);
	f29.f64 = double(temp.f32);
	// bl 0x8232c638
	ctx.lr = 0x822B546C;
	sub_8232C638(ctx, base);
	// lwz r9,148(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 148);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f13,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = f30.f64;
	// lfs f12,12(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-7912(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -7912);
	f0.f64 = double(temp.f32);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// fmuls f11,f12,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * f0.f64));
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// lwz r5,100(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 100);
	// fdivs f10,f29,f11
	ctx.f10.f64 = double(float(f29.f64 / ctx.f11.f64));
	// lfs f0,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	f0.f64 = double(temp.f32);
	// lfs f9,32(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	ctx.f9.f64 = double(temp.f32);
	// lfs f28,24(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	f28.f64 = double(temp.f32);
	// fsubs f11,f9,f0
	ctx.f11.f64 = double(float(ctx.f9.f64 - f0.f64));
	// fsel f8,f10,f10,f30
	ctx.f8.f64 = ctx.f10.f64 >= 0.0 ? ctx.f10.f64 : f30.f64;
	// fsubs f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsel f12,f7,f31,f8
	ctx.f12.f64 = ctx.f7.f64 >= 0.0 ? f31.f64 : ctx.f8.f64;
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822b54ec
	if (!cr6.gt) goto loc_822B54EC;
	// fcmpu cr6,f11,f30
	cr6.compare(ctx.f11.f64, f30.f64);
	// bgt cr6,0x822b54cc
	if (cr6.gt) goto loc_822B54CC;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f11,11360(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11360);
	ctx.f11.f64 = double(temp.f32);
loc_822B54CC:
	// fsubs f0,f12,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f12.f64 - f0.f64));
	// fsel f13,f0,f0,f30
	ctx.f13.f64 = f0.f64 >= 0.0 ? f0.f64 : f30.f64;
	// fsubs f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 - f31.f64));
	// fsel f10,f12,f31,f13
	ctx.f10.f64 = ctx.f12.f64 >= 0.0 ? f31.f64 : ctx.f13.f64;
	// fdivs f13,f10,f11
	ctx.f13.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// fcmpu cr6,f13,f31
	cr6.compare(ctx.f13.f64, f31.f64);
	// ble cr6,0x822b54ec
	if (!cr6.gt) goto loc_822B54EC;
	// fmr f13,f31
	ctx.f13.f64 = f31.f64;
loc_822B54EC:
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// fmuls f29,f13,f28
	ctx.fpscr.disableFlushMode();
	f29.f64 = double(float(ctx.f13.f64 * f28.f64));
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B5508;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fcmpu cr6,f1,f27
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f27.f64);
	// ble cr6,0x822b5514
	if (!cr6.gt) goto loc_822B5514;
	// fmr f29,f30
	f29.f64 = f30.f64;
loc_822B5514:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B5530;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x822b5540
	if (!cr6.eq) goto loc_822B5540;
	// fmr f29,f30
	ctx.fpscr.disableFlushMode();
	f29.f64 = f30.f64;
loc_822B5540:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r10,72(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	// lwz r9,52(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// bne cr6,0x822b5568
	if (!cr6.eq) goto loc_822B5568;
	// lwz r11,48(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// mr r11,r26
	r11.u64 = r26.u64;
	// beq cr6,0x822b556c
	if (cr6.eq) goto loc_822B556C;
loc_822B5568:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_822B556C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5598
	if (cr6.eq) goto loc_822B5598;
	// lfs f0,44(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// lfs f0,30712(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 30712);
	f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	f0.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822b5598
	if (!cr6.gt) goto loc_822B5598;
	// fmr f29,f0
	f29.f64 = f0.f64;
loc_822B5598:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b12b0
	ctx.lr = 0x822B55A0;
	sub_822B12B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b55ec
	if (!cr6.eq) goto loc_822B55EC;
	// lwz r11,-6148(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -6148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b55ec
	if (cr6.eq) goto loc_822B55EC;
	// lbz r11,157(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 157);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b55ec
	if (!cr6.eq) goto loc_822B55EC;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b55dc
	if (cr6.eq) goto loc_822B55DC;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822b55e0
	if (!cr6.eq) goto loc_822B55E0;
loc_822B55DC:
	// fmuls f1,f29,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f29.f64 * f24.f64));
loc_822B55E0:
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823147c0
	ctx.lr = 0x822B55EC;
	sub_823147C0(ctx, base);
loc_822B55EC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r10,89(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 89);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// lfs f28,31308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f28.f64 = double(temp.f32);
	// bne cr6,0x822b56a4
	if (!cr6.eq) goto loc_822B56A4;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// fmr f29,f30
	f29.f64 = f30.f64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r9,578(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 578);
	// extsb r8,r9
	ctx.r8.s64 = ctx.r9.s8;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822b5624
	if (!cr6.gt) goto loc_822B5624;
	// lfs f29,580(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 580);
	f29.f64 = double(temp.f32);
loc_822B5624:
	// lwz r10,660(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 660);
	// lfs f0,24(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x822b5640
	if (!cr6.gt) goto loc_822B5640;
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822b5640
	if (!cr6.gt) goto loc_822B5640;
	// fmr f29,f0
	f29.f64 = f0.f64;
loc_822B5640:
	// lwz r11,664(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// lbz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b5658
	if (cr6.eq) goto loc_822B5658;
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// b 0x822b565c
	goto loc_822B565C;
loc_822B5658:
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = f30.f64;
loc_822B565C:
	// fcmpu cr6,f0,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f29.f64);
	// ble cr6,0x822b5668
	if (!cr6.gt) goto loc_822B5668;
	// fmr f29,f0
	f29.f64 = f0.f64;
loc_822B5668:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b12b0
	ctx.lr = 0x822B5670;
	sub_822B12B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b56a4
	if (!cr6.eq) goto loc_822B56A4;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b5694
	if (cr6.eq) goto loc_822B5694;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822b5698
	if (!cr6.eq) goto loc_822B5698;
loc_822B5694:
	// fmuls f1,f29,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f29.f64 * f28.f64));
loc_822B5698:
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823147c0
	ctx.lr = 0x822B56A4;
	sub_823147C0(ctx, base);
loc_822B56A4:
	// lbz r11,89(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 89);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x822b5870
	if (!cr6.eq) goto loc_822B5870;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f12,11368(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11368);
	ctx.f12.f64 = double(temp.f32);
	// lwz r9,8(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f13,224(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x822b581c
	if (!cr6.gt) goto loc_822B581C;
	// lwz r11,24(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// fmr f0,f30
	f0.f64 = f30.f64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// cmpwi cr6,r10,4
	cr6.compare<int32_t>(ctx.r10.s32, 4, xer);
	// blt cr6,0x822b57a0
	if (cr6.lt) goto loc_822B57A0;
	// addi r7,r11,-2
	ctx.r7.s64 = r11.s64 + -2;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// rlwinm r6,r10,0,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// subf r11,r6,r11
	r11.s64 = r11.s64 - ctx.r6.s64;
loc_822B5704:
	// lwz r8,8(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r7,4(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,-4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// lfs f11,520(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 520);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f25
	ctx.f10.f64 = double(float(ctx.f11.f64 - f25.f64));
	// lfs f9,520(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 520);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f25
	ctx.f8.f64 = double(float(ctx.f9.f64 - f25.f64));
	// lfs f7,520(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 520);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f25
	ctx.f6.f64 = double(float(ctx.f7.f64 - f25.f64));
	// lfs f5,520(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 520);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f25
	ctx.f4.f64 = double(float(ctx.f5.f64 - f25.f64));
	// fmuls f3,f10,f26
	ctx.f3.f64 = double(float(ctx.f10.f64 * f26.f64));
	// fmuls f2,f8,f26
	ctx.f2.f64 = double(float(ctx.f8.f64 * f26.f64));
	// fmuls f1,f6,f26
	ctx.f1.f64 = double(float(ctx.f6.f64 * f26.f64));
	// fmuls f11,f4,f26
	ctx.f11.f64 = double(float(ctx.f4.f64 * f26.f64));
	// fsel f10,f3,f3,f30
	ctx.f10.f64 = ctx.f3.f64 >= 0.0 ? ctx.f3.f64 : f30.f64;
	// fsel f9,f2,f2,f30
	ctx.f9.f64 = ctx.f2.f64 >= 0.0 ? ctx.f2.f64 : f30.f64;
	// fsel f8,f1,f1,f30
	ctx.f8.f64 = ctx.f1.f64 >= 0.0 ? ctx.f1.f64 : f30.f64;
	// fsel f7,f11,f11,f30
	ctx.f7.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f30.f64;
	// fsubs f6,f10,f31
	ctx.f6.f64 = double(float(ctx.f10.f64 - f31.f64));
	// fsubs f5,f9,f31
	ctx.f5.f64 = double(float(ctx.f9.f64 - f31.f64));
	// fsubs f4,f8,f31
	ctx.f4.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsubs f3,f7,f31
	ctx.f3.f64 = double(float(ctx.f7.f64 - f31.f64));
	// fsel f2,f6,f31,f10
	ctx.f2.f64 = ctx.f6.f64 >= 0.0 ? f31.f64 : ctx.f10.f64;
	// fsel f1,f5,f31,f9
	ctx.f1.f64 = ctx.f5.f64 >= 0.0 ? f31.f64 : ctx.f9.f64;
	// fsel f11,f4,f31,f8
	ctx.f11.f64 = ctx.f4.f64 >= 0.0 ? f31.f64 : ctx.f8.f64;
	// fsel f10,f3,f31,f7
	ctx.f10.f64 = ctx.f3.f64 >= 0.0 ? f31.f64 : ctx.f7.f64;
	// fsubs f9,f0,f2
	ctx.f9.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fsel f8,f9,f0,f2
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? f0.f64 : ctx.f2.f64;
	// fsubs f7,f8,f1
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f1.f64));
	// fsel f6,f7,f8,f1
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? ctx.f8.f64 : ctx.f1.f64;
	// fsubs f5,f6,f11
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// fsel f4,f5,f6,f11
	ctx.f4.f64 = ctx.f5.f64 >= 0.0 ? ctx.f6.f64 : ctx.f11.f64;
	// fsubs f3,f4,f10
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f10.f64));
	// fsel f0,f3,f4,f10
	f0.f64 = ctx.f3.f64 >= 0.0 ? ctx.f4.f64 : ctx.f10.f64;
	// bne 0x822b5704
	if (!cr0.eq) goto loc_822B5704;
loc_822B57A0:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822b57f0
	if (cr6.lt) goto loc_822B57F0;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r9,28(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_822B57C0:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// lfs f11,520(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 520);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f25
	ctx.f10.f64 = double(float(ctx.f11.f64 - f25.f64));
	// fmuls f9,f10,f26
	ctx.f9.f64 = double(float(ctx.f10.f64 * f26.f64));
	// fsel f8,f9,f9,f30
	ctx.f8.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f30.f64;
	// fsubs f7,f8,f31
	ctx.f7.f64 = double(float(ctx.f8.f64 - f31.f64));
	// fsel f6,f7,f31,f8
	ctx.f6.f64 = ctx.f7.f64 >= 0.0 ? f31.f64 : ctx.f8.f64;
	// fsubs f5,f0,f6
	ctx.f5.f64 = double(float(f0.f64 - ctx.f6.f64));
	// fsel f0,f5,f0,f6
	f0.f64 = ctx.f5.f64 >= 0.0 ? f0.f64 : ctx.f6.f64;
	// bge 0x822b57c0
	if (!cr0.lt) goto loc_822B57C0;
loc_822B57F0:
	// fmuls f11,f0,f26
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(f0.f64 * f26.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f0,f13,f12
	f0.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f13,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// fsel f10,f11,f11,f30
	ctx.f10.f64 = ctx.f11.f64 >= 0.0 ? ctx.f11.f64 : f30.f64;
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// fsubs f9,f10,f31
	ctx.f9.f64 = double(float(ctx.f10.f64 - f31.f64));
	// fsel f30,f9,f31,f10
	f30.f64 = ctx.f9.f64 >= 0.0 ? f31.f64 : ctx.f10.f64;
	// bge cr6,0x822b581c
	if (!cr6.lt) goto loc_822B581C;
	// fmuls f0,f0,f30
	f0.f64 = double(float(f0.f64 * f30.f64));
	// fmuls f30,f0,f27
	f30.f64 = double(float(f0.f64 * f27.f64));
loc_822B581C:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b5830
	if (cr6.eq) goto loc_822B5830;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822b5834
	if (!cr6.eq) goto loc_822B5834;
loc_822B5830:
	// fmuls f30,f30,f28
	ctx.fpscr.disableFlushMode();
	f30.f64 = double(float(f30.f64 * f28.f64));
loc_822B5834:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b12b0
	ctx.lr = 0x822B583C;
	sub_822B12B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b5870
	if (!cr6.eq) goto loc_822B5870;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f30.f64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b5860
	if (cr6.eq) goto loc_822B5860;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822b5864
	if (!cr6.eq) goto loc_822B5864;
loc_822B5860:
	// fmuls f1,f30,f24
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(f30.f64 * f24.f64));
loc_822B5864:
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x823147c0
	ctx.lr = 0x822B5870;
	sub_823147C0(ctx, base);
loc_822B5870:
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b5884
	if (cr6.eq) goto loc_822B5884;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822b58b8
	if (!cr6.eq) goto loc_822B58B8;
loc_822B5884:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r9,r11,11
	ctx.r9.s64 = r11.s64 + 11;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwzx r6,r8,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r31.u32);
	// lwz r5,72(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 72);
	// lfs f0,224(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 224);
	f0.f64 = double(temp.f32);
	// lfs f13,36(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f11,40(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,228(r6)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r6.u32 + 228, temp.u32);
	// fsel f10,f12,f0,f13
	ctx.f10.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// stfs f10,224(r6)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r6.u32 + 224, temp.u32);
loc_822B58B8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b3bf0
	ctx.lr = 0x822B58C0;
	sub_822B3BF0(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stb r26,92(r31)
	PPC_STORE_U8(r31.u32 + 92, r26.u8);
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 16);
	// extsh r11,r10
	r11.s64 = ctx.r10.s16;
	// addi r9,r11,-4
	ctx.r9.s64 = r11.s64 + -4;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r7,91(r31)
	PPC_STORE_U8(r31.u32 + 91, ctx.r7.u8);
loc_822B58E0:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// addi r12,r1,-64
	r12.s64 = ctx.r1.s64 + -64;
	// bl 0x823dba14
	ctx.lr = 0x822B58EC;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_822B58F0"))) PPC_WEAK_FUNC(sub_822B58F0);
PPC_FUNC_IMPL(__imp__sub_822B58F0) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-6148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -6148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b593c
	if (cr6.eq) goto loc_822B593C;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lbz r9,-6144(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6144);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b593c
	if (cr6.eq) goto loc_822B593C;
	// lbz r11,156(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b593c
	if (cr6.eq) goto loc_822B593C;
	// bl 0x822b0370
	ctx.lr = 0x822B5938;
	sub_822B0370(ctx, base);
	// b 0x822b598c
	goto loc_822B598C;
loc_822B593C:
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5954
	if (cr6.eq) goto loc_822B5954;
	// bl 0x822b0660
	ctx.lr = 0x822B5950;
	sub_822B0660(ctx, base);
	// b 0x822b598c
	goto loc_822B598C;
loc_822B5954:
	// bl 0x822b12b0
	ctx.lr = 0x822B5958;
	sub_822B12B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b598c
	if (cr6.eq) goto loc_822B598C;
	// lwz r3,76(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lbz r11,37(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 37);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5988
	if (cr6.eq) goto loc_822B5988;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b4c98
	ctx.lr = 0x822B597C;
	sub_822B4C98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b2ab0
	ctx.lr = 0x822B5984;
	sub_822B2AB0(ctx, base);
	// b 0x822b598c
	goto loc_822B598C;
loc_822B5988:
	// bl 0x82318978
	ctx.lr = 0x822B598C;
	sub_82318978(ctx, base);
loc_822B598C:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5a14
	if (cr6.eq) goto loc_822B5A14;
	// lbz r10,101(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r10,1
	cr6.compare<uint32_t>(ctx.r10.u32, 1, xer);
	// beq cr6,0x822b59e4
	if (cr6.eq) goto loc_822B59E4;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,56(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x822b59e4
	if (cr6.eq) goto loc_822B59E4;
	// lwz r11,-6148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -6148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5a14
	if (cr6.eq) goto loc_822B5A14;
	// lbz r11,156(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5a14
	if (cr6.eq) goto loc_822B5A14;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B59E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822b5a14
	goto loc_822B5A14;
loc_822B59E4:
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B59F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r8,56(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x822b5a14
	if (!cr6.eq) goto loc_822B5A14;
	// rotlwi r3,r8,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// bl 0x8271f438
	ctx.lr = 0x822B5A14;
	sub_8271F438(ctx, base);
loc_822B5A14:
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

__attribute__((alias("__imp__sub_822B5A2C"))) PPC_WEAK_FUNC(sub_822B5A2C);
PPC_FUNC_IMPL(__imp__sub_822B5A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B5A30"))) PPC_WEAK_FUNC(sub_822B5A30);
PPC_FUNC_IMPL(__imp__sub_822B5A30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r3,900(r11)
	PPC_STORE_U8(r11.u32 + 900, ctx.r3.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B5A48"))) PPC_WEAK_FUNC(sub_822B5A48);
PPC_FUNC_IMPL(__imp__sub_822B5A48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,202
	r11.s64 = ctx.r4.s64 + 202;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B5A58"))) PPC_WEAK_FUNC(sub_822B5A58);
PPC_FUNC_IMPL(__imp__sub_822B5A58) {
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
	ctx.lr = 0x822B5A60;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r31,0
	r31.s64 = 0;
	// lis r28,-32119
	r28.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,400(r30)
	PPC_STORE_U32(r30.u32 + 400, r31.u32);
	// stw r31,804(r30)
	PPC_STORE_U32(r30.u32 + 804, r31.u32);
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x822B5A84;
	sub_82305870(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r30,808
	r30.s64 = r30.s64 + 808;
	// addi r29,r11,30524
	r29.s64 = r11.s64 + 30524;
loc_822B5A90:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822B5AA4;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82723808
	ctx.lr = 0x822B5AAC;
	sub_82723808(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r31,19
	cr6.compare<int32_t>(r31.s32, 19, xer);
	// blt cr6,0x822b5a90
	if (cr6.lt) goto loc_822B5A90;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x822B5ACC;
	sub_823058F8(ctx, base);
	// bl 0x822a91c8
	ctx.lr = 0x822B5AD0;
	sub_822A91C8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822B5AD8"))) PPC_WEAK_FUNC(sub_822B5AD8);
PPC_FUNC_IMPL(__imp__sub_822B5AD8) {
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
	PPCRegister f27{};
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
	// bl 0x823d91e0
	ctx.lr = 0x822B5AE0;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9d4
	ctx.lr = 0x822B5AE8;
	// stwu r1,-1440(r1)
	ea = -1440 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,112
	ctx.r8.s64 = 112;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// addi r6,r11,45
	ctx.r6.s64 = r11.s64 + 45;
	// lwz r3,-10220(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwzx r4,r5,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r10.u32);
	// lvx128 v63,r4,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822b5b7c
	if (cr6.eq) goto loc_822B5B7C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B5B3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b5b7c
	if (cr6.eq) goto loc_822B5B7C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x822B5B54;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5b7c
	if (cr6.eq) goto loc_822B5B7C;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822B5B68;
	sub_822A39C8(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x822B5B6C;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r3,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_822B5B7C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,400(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + 400);
	// li r28,0
	r28.s64 = 0;
	// li r22,8
	r22.s64 = 8;
	// stw r28,1296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1296, r28.u32);
	// li r24,0
	r24.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lfs f27,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f27.f64 = double(temp.f32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x822b5d38
	if (!cr6.gt) goto loc_822B5D38;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f30,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f30.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f29,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f29.f64 = double(temp.f32);
	// mr r31,r23
	r31.u64 = r23.u64;
	// lfs f28,29500(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29500);
	f28.f64 = double(temp.f32);
	// lfs f31,14192(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f31.f64 = double(temp.f32);
loc_822B5BC0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b5d24
	if (cr6.eq) goto loc_822B5D24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B5BDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b5bf0
	if (cr6.eq) goto loc_822B5BF0;
	// addi r22,r22,-1
	r22.s64 = r22.s64 + -1;
	// b 0x822b5d24
	goto loc_822B5D24;
loc_822B5BF0:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822a8108
	ctx.lr = 0x822B5BF8;
	sub_822A8108(ctx, base);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r11,656(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 656);
	// fsubs f13,f0,f29
	ctx.f13.f64 = double(float(f0.f64 - f29.f64));
	// lfs f12,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f30
	ctx.f11.f64 = double(float(ctx.f12.f64 - f30.f64));
	// lwz r10,660(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 660);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// fmuls f10,f13,f13
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f9,f11,f11,f10
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64 + ctx.f10.f64));
	// fsqrts f0,f9
	f0.f64 = double(float(sqrt(ctx.f9.f64)));
	// beq cr6,0x822b5c40
	if (cr6.eq) goto loc_822B5C40;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b5c40
	if (cr6.eq) goto loc_822B5C40;
	// fmr f0,f31
	f0.f64 = f31.f64;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// b 0x822b5c78
	goto loc_822B5C78;
loc_822B5C40:
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x822b5c50
	if (!cr6.eq) goto loc_822B5C50;
	// fmr f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = f31.f64;
	// b 0x822b5c78
	goto loc_822B5C78;
loc_822B5C50:
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x822b5c60
	if (!cr6.eq) goto loc_822B5C60;
	// fmr f0,f28
	ctx.fpscr.disableFlushMode();
	f0.f64 = f28.f64;
	// b 0x822b5c78
	goto loc_822B5C78;
loc_822B5C60:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822b5c78
	if (!cr6.eq) goto loc_822B5C78;
	// lfs f13,896(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 896);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fneg f11,f12
	ctx.f11.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// fsel f0,f11,f27,f12
	f0.f64 = ctx.f11.f64 >= 0.0 ? f27.f64 : ctx.f12.f64;
loc_822B5C78:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x822b5ca4
	if (!cr6.gt) goto loc_822B5CA4;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
loc_822B5C88:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// blt cr6,0x822b5ca4
	if (cr6.lt) goto loc_822B5CA4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,12
	r11.s64 = r11.s64 + 12;
	// cmpw cr6,r10,r28
	cr6.compare<int32_t>(ctx.r10.s32, r28.s32, xer);
	// blt cr6,0x822b5c88
	if (cr6.lt) goto loc_822B5C88;
loc_822B5CA4:
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmpw cr6,r28,r10
	cr6.compare<int32_t>(r28.s32, ctx.r10.s32, xer);
	// ble cr6,0x822b5cf4
	if (!cr6.gt) goto loc_822B5CF4;
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// subf r9,r10,r28
	ctx.r9.s64 = r28.s64 - ctx.r10.s64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
loc_822B5CCC:
	// lwz r8,-12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + -12);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r6,-8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -8);
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// stw r5,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r5.u32);
	// addi r11,r11,-12
	r11.s64 = r11.s64 + -12;
	// bne 0x822b5ccc
	if (!cr0.eq) goto loc_822B5CCC;
	// lwz r28,1296(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1296);
loc_822B5CF4:
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,80(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// addi r5,r28,1
	ctx.r5.s64 = r28.s64 + 1;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,1296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1296, ctx.r5.u32);
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// stwx r8,r11,r9
	PPC_STORE_U32(r11.u32 + ctx.r9.u32, ctx.r8.u32);
	// stw r7,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r7.u32);
	// stw r30,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r30.u32);
	// lwz r28,1296(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1296);
loc_822B5D24:
	// lwz r11,400(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 400);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822b5bc0
	if (cr6.lt) goto loc_822B5BC0;
loc_822B5D38:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3652);
	f0.f64 = double(temp.f32);
	// lfs f13,11364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x822b5d58
	if (!cr6.lt) goto loc_822B5D58;
	// lfs f31,884(r23)
	temp.u32 = PPC_LOAD_U32(r23.u32 + 884);
	f31.f64 = double(temp.f32);
	// b 0x822b5d5c
	goto loc_822B5D5C;
loc_822B5D58:
	// lfs f31,888(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 888);
	f31.f64 = double(temp.f32);
loc_822B5D5C:
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// ble cr6,0x822b5e74
	if (!cr6.gt) goto loc_822B5E74;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r27,r1,96
	r27.s64 = ctx.r1.s64 + 96;
	// addi r25,r11,30576
	r25.s64 = r11.s64 + 30576;
	// addi r26,r10,30540
	r26.s64 = ctx.r10.s64 + 30540;
loc_822B5D7C:
	// lwz r31,4(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 0);
	f0.f64 = double(temp.f32);
	// lwz r30,8(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// fcmpu cr6,f0,f27
	cr6.compare(f0.f64, f27.f64);
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// blt cr6,0x822b5e1c
	if (cr6.lt) goto loc_822B5E1C;
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x822b5da4
	if (!cr6.lt) goto loc_822B5DA4;
	// cmpw cr6,r29,r22
	cr6.compare<int32_t>(r29.s32, r22.s32, xer);
	// blt cr6,0x822b5e1c
	if (cr6.lt) goto loc_822B5E1C;
loc_822B5DA4:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822b5e64
	if (!cr6.eq) goto loc_822B5E64;
	// lbz r11,468(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 468);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5dd0
	if (cr6.eq) goto loc_822B5DD0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B5DCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822b5e64
	goto loc_822B5E64;
loc_822B5DD0:
	// lfs f13,892(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r23.u32 + 892);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x822b5de4
	if (cr6.gt) goto loc_822B5DE4;
	// cmpw cr6,r29,r22
	cr6.compare<int32_t>(r29.s32, r22.s32, xer);
	// blt cr6,0x822b5e64
	if (cr6.lt) goto loc_822B5E64;
loc_822B5DE4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8d98
	ctx.lr = 0x822B5DEC;
	sub_822A8D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x822B5DFC;
	sub_82130000(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e10
	ctx.lr = 0x822B5E08;
	sub_822A8E10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e18
	ctx.lr = 0x822B5E14;
	sub_822A8E18(ctx, base);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// b 0x822b5e64
	goto loc_822B5E64;
loc_822B5E1C:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822b5e64
	if (!cr6.eq) goto loc_822B5E64;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// bne cr6,0x822b5e64
	if (!cr6.eq) goto loc_822B5E64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8d98
	ctx.lr = 0x822B5E34;
	sub_822A8D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x822B5E48;
	sub_82130000(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e18
	ctx.lr = 0x822B5E54;
	sub_822A8E18(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e10
	ctx.lr = 0x822B5E60;
	sub_822A8E10(ctx, base);
	// li r24,1
	r24.s64 = 1;
loc_822B5E64:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,12
	r27.s64 = r27.s64 + 12;
	// cmpw cr6,r29,r28
	cr6.compare<int32_t>(r29.s32, r28.s32, xer);
	// blt cr6,0x822b5d7c
	if (cr6.lt) goto loc_822B5D7C;
loc_822B5E74:
	// addi r1,r1,1440
	ctx.r1.s64 = ctx.r1.s64 + 1440;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba20
	ctx.lr = 0x822B5E80;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_822B5E84"))) PPC_WEAK_FUNC(sub_822B5E84);
PPC_FUNC_IMPL(__imp__sub_822B5E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B5E88"))) PPC_WEAK_FUNC(sub_822B5E88);
PPC_FUNC_IMPL(__imp__sub_822B5E88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,17892(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17892);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// xori r10,r7,1
	ctx.r10.u64 = ctx.r7.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,900(r11)
	PPC_STORE_U8(r11.u32 + 900, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B5EB4"))) PPC_WEAK_FUNC(sub_822B5EB4);
PPC_FUNC_IMPL(__imp__sub_822B5EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B5EB8"))) PPC_WEAK_FUNC(sub_822B5EB8);
PPC_FUNC_IMPL(__imp__sub_822B5EB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,17892(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b5edc
	if (cr6.eq) goto loc_822B5EDC;
	// lbz r11,900(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 900);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822B5EDC:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B5EF0"))) PPC_WEAK_FUNC(sub_822B5EF0);
PPC_FUNC_IMPL(__imp__sub_822B5EF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B5F00"))) PPC_WEAK_FUNC(sub_822B5F00);
PPC_FUNC_IMPL(__imp__sub_822B5F00) {
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
	ctx.lr = 0x822B5F08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,400(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 400);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822b5fd4
	if (!cr6.gt) goto loc_822B5FD4;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// mr r31,r27
	r31.u64 = r27.u64;
	// addi r29,r10,-12656
	r29.s64 = ctx.r10.s64 + -12656;
	// addi r28,r11,-12632
	r28.s64 = r11.s64 + -12632;
loc_822B5F34:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b5fc0
	if (cr6.eq) goto loc_822B5FC0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B5F50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b5f8c
	if (cr6.eq) goto loc_822B5F8C;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x822B5F74;
	sub_823DEDD8(ctx, base);
	// lwz r11,1220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b5f8c
	if (cr6.eq) goto loc_822B5F8C;
	// lbz r11,278(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b5fc0
	if (!cr6.eq) goto loc_822B5FC0;
loc_822B5F8C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,660(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 660);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x822b5fc0
	if (cr6.lt) goto loc_822B5FC0;
	// beq cr6,0x822b5fb4
	if (cr6.eq) goto loc_822B5FB4;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x822b5fe0
	if (!cr6.lt) goto loc_822B5FE0;
	// lwz r11,656(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// b 0x822b5fbc
	goto loc_822B5FBC;
loc_822B5FB4:
	// lwz r11,656(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
loc_822B5FBC:
	// bne cr6,0x822b5fe0
	if (!cr6.eq) goto loc_822B5FE0;
loc_822B5FC0:
	// lwz r11,400(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 400);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822b5f34
	if (cr6.lt) goto loc_822B5F34;
loc_822B5FD4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822B5FE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822B5FEC"))) PPC_WEAK_FUNC(sub_822B5FEC);
PPC_FUNC_IMPL(__imp__sub_822B5FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B5FF0"))) PPC_WEAK_FUNC(sub_822B5FF0);
PPC_FUNC_IMPL(__imp__sub_822B5FF0) {
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
	ctx.lr = 0x822B5FF8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r27,400(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 400);
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x822b6080
	if (!cr6.gt) goto loc_822B6080;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_822B6018:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b609c
	if (cr6.eq) goto loc_822B609C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B6038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b6070
	if (cr6.eq) goto loc_822B6070;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B6058;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b6070
	if (!cr6.eq) goto loc_822B6070;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// mr r30,r11
	r30.u64 = r11.u64;
loc_822B6070:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x822b6018
	if (cr6.lt) goto loc_822B6018;
loc_822B6080:
	// lwz r11,400(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 400);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,400(r28)
	PPC_STORE_U32(r28.u32 + 400, r11.u32);
	// stwx r30,r10,r28
	PPC_STORE_U32(ctx.r10.u32 + r28.u32, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822B609C:
	// rlwinm r11,r29,2,0,29
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r30,r11,r28
	PPC_STORE_U32(r11.u32 + r28.u32, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822B60AC"))) PPC_WEAK_FUNC(sub_822B60AC);
PPC_FUNC_IMPL(__imp__sub_822B60AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B60B0"))) PPC_WEAK_FUNC(sub_822B60B0);
PPC_FUNC_IMPL(__imp__sub_822B60B0) {
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
	// lwz r11,400(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 400);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822b6118
	if (!cr6.gt) goto loc_822B6118;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_822B60D8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b610c
	if (cr6.eq) goto loc_822B610C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b610c
	if (cr6.eq) goto loc_822B610C;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b610c
	if (cr6.eq) goto loc_822B610C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B610C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B610C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822b60d8
	if (!cr0.eq) goto loc_822B60D8;
loc_822B6118:
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

__attribute__((alias("__imp__sub_822B6130"))) PPC_WEAK_FUNC(sub_822B6130);
PPC_FUNC_IMPL(__imp__sub_822B6130) {
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
	// lwz r11,400(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 400);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822b6198
	if (!cr6.gt) goto loc_822B6198;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r11
	r30.u64 = r11.u64;
loc_822B6158:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b618c
	if (cr6.eq) goto loc_822B618C;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b618c
	if (cr6.eq) goto loc_822B618C;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822b618c
	if (cr6.eq) goto loc_822B618C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B618C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B618C:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822b6158
	if (!cr0.eq) goto loc_822B6158;
loc_822B6198:
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

__attribute__((alias("__imp__sub_822B61B0"))) PPC_WEAK_FUNC(sub_822B61B0);
PPC_FUNC_IMPL(__imp__sub_822B61B0) {
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
	ctx.lr = 0x822B61B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,-10012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b61ec
	if (cr6.eq) goto loc_822B61EC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b61ec
	if (cr6.eq) goto loc_822B61EC;
	// bl 0x826d5a40
	ctx.lr = 0x822B61E0;
	sub_826D5A40(ctx, base);
	// lwz r3,-10012(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10012);
	// lwz r4,56(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// bl 0x826d5a40
	ctx.lr = 0x822B61EC;
	sub_826D5A40(ctx, base);
loc_822B61EC:
	// lwz r9,400(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 400);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822b621c
	if (!cr6.gt) goto loc_822B621C;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_822B6200:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// beq cr6,0x822b6220
	if (cr6.eq) goto loc_822B6220;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822b6200
	if (cr6.lt) goto loc_822B6200;
loc_822B621C:
	// li r11,-1
	r11.s64 = -1;
loc_822B6220:
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r10,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r10.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B6234"))) PPC_WEAK_FUNC(sub_822B6234);
PPC_FUNC_IMPL(__imp__sub_822B6234) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B6238"))) PPC_WEAK_FUNC(sub_822B6238);
PPC_FUNC_IMPL(__imp__sub_822B6238) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b6250
	if (cr6.eq) goto loc_822B6250;
	// addi r3,r3,404
	ctx.r3.s64 = ctx.r3.s64 + 404;
loc_822B6250:
	// lwz r8,400(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 400);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822b628c
	if (!cr6.gt) goto loc_822B628C;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_822B6264:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b627c
	if (cr6.eq) goto loc_822B627C;
	// lwz r9,140(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 140);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x822b6294
	if (cr6.eq) goto loc_822B6294;
loc_822B627C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// blt cr6,0x822b6264
	if (cr6.lt) goto loc_822B6264;
loc_822B628C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822B6294:
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r3
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B62A0"))) PPC_WEAK_FUNC(sub_822B62A0);
PPC_FUNC_IMPL(__imp__sub_822B62A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x822b62b4
	if (!cr6.eq) goto loc_822B62B4;
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_822B62B4:
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b62cc
	if (cr6.eq) goto loc_822B62CC;
	// addi r11,r11,404
	r11.s64 = r11.s64 + 404;
loc_822B62CC:
	// lwz r9,400(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 400);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822b62f8
	if (!cr6.gt) goto loc_822B62F8;
loc_822B62DC:
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r8,r4
	cr6.compare<uint32_t>(ctx.r8.u32, ctx.r4.u32, xer);
	// beq cr6,0x822b62fc
	if (cr6.eq) goto loc_822B62FC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x822b62dc
	if (cr6.lt) goto loc_822B62DC;
loc_822B62F8:
	// li r10,-1
	ctx.r10.s64 = -1;
loc_822B62FC:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B6304"))) PPC_WEAK_FUNC(sub_822B6304);
PPC_FUNC_IMPL(__imp__sub_822B6304) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B6308"))) PPC_WEAK_FUNC(sub_822B6308);
PPC_FUNC_IMPL(__imp__sub_822B6308) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822b6374
	if (cr6.lt) goto loc_822B6374;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b632c
	if (cr6.eq) goto loc_822B632C;
	// lwz r11,804(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 804);
	// b 0x822b6330
	goto loc_822B6330;
loc_822B632C:
	// lwz r11,400(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 400);
loc_822B6330:
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x822b6374
	if (!cr6.lt) goto loc_822B6374;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b635c
	if (cr6.eq) goto loc_822B635C;
	// addi r11,r4,101
	r11.s64 = ctx.r4.s64 + 101;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r3
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// blr 
	return;
loc_822B635C:
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r3.u32);
	// cntlzw r11,r11
	r11.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r3,r10,1
	ctx.r3.u64 = ctx.r10.u64 ^ 1;
	// blr 
	return;
loc_822B6374:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B637C"))) PPC_WEAK_FUNC(sub_822B637C);
PPC_FUNC_IMPL(__imp__sub_822B637C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B6380"))) PPC_WEAK_FUNC(sub_822B6380);
PPC_FUNC_IMPL(__imp__sub_822B6380) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// lwz r30,400(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 400);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// stw r30,804(r3)
	PPC_STORE_U32(ctx.r3.u32 + 804, r30.u32);
	// ble cr6,0x822b63c8
	if (!cr6.gt) goto loc_822B63C8;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_822B63A8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r3,404(r31)
	PPC_STORE_U32(r31.u32 + 404, ctx.r3.u32);
	// beq cr6,0x822b63bc
	if (cr6.eq) goto loc_822B63BC;
	// bl 0x822a7c58
	ctx.lr = 0x822B63BC;
	sub_822A7C58(ctx, base);
loc_822B63BC:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x822b63a8
	if (!cr0.eq) goto loc_822B63A8;
loc_822B63C8:
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

__attribute__((alias("__imp__sub_822B63E0"))) PPC_WEAK_FUNC(sub_822B63E0);
PPC_FUNC_IMPL(__imp__sub_822B63E0) {
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
	// li r3,904
	ctx.r3.s64 = 904;
	// bl 0x82130528
	ctx.lr = 0x822B63F4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6454
	if (cr6.eq) goto loc_822B6454;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lfs f0,31020(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31020);
	f0.f64 = double(temp.f32);
	// stw r11,400(r3)
	PPC_STORE_U32(ctx.r3.u32 + 400, r11.u32);
	// lfs f13,-12988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12988);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,804(r3)
	PPC_STORE_U32(ctx.r3.u32 + 804, r11.u32);
	// lfs f12,-1760(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -1760);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,31016(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31016);
	ctx.f11.f64 = double(temp.f32);
	// stb r11,900(r3)
	PPC_STORE_U8(ctx.r3.u32 + 900, r11.u8);
	// stfs f0,884(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 884, temp.u32);
	// stfs f13,888(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 888, temp.u32);
	// stfs f12,892(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 892, temp.u32);
	// stfs f11,896(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 896, temp.u32);
	// stw r3,17892(r6)
	PPC_STORE_U32(ctx.r6.u32 + 17892, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822B6454:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r3,17892(r11)
	PPC_STORE_U32(r11.u32 + 17892, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B6470"))) PPC_WEAK_FUNC(sub_822B6470);
PPC_FUNC_IMPL(__imp__sub_822B6470) {
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
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// bl 0x822b62a0
	ctx.lr = 0x822B6484;
	sub_822B62A0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822b64d8
	if (cr6.lt) goto loc_822B64D8;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// blt cr6,0x822b64d8
	if (cr6.lt) goto loc_822B64D8;
	// lwz r11,400(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 400);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// bgt cr6,0x822b64c4
	if (cr6.gt) goto loc_822B64C4;
	// li r9,0
	ctx.r9.s64 = 0;
loc_822B64A4:
	// lwz r11,400(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 400);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,400(r7)
	PPC_STORE_U32(ctx.r7.u32 + 400, r11.u32);
	// stwx r9,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r9.u32);
	// lwz r10,400(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 400);
	// cmpw cr6,r10,r5
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, xer);
	// ble cr6,0x822b64a4
	if (!cr6.gt) goto loc_822B64A4;
loc_822B64C4:
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r7
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + ctx.r7.u32);
	// stwx r9,r10,r7
	PPC_STORE_U32(ctx.r10.u32 + ctx.r7.u32, ctx.r9.u32);
	// stwx r4,r11,r7
	PPC_STORE_U32(r11.u32 + ctx.r7.u32, ctx.r4.u32);
loc_822B64D8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B64E8"))) PPC_WEAK_FUNC(sub_822B64E8);
PPC_FUNC_IMPL(__imp__sub_822B64E8) {
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
	// lwz r3,17892(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17892);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b650c
	if (cr6.eq) goto loc_822B650C;
	// bl 0x82130588
	ctx.lr = 0x822B650C;
	sub_82130588(ctx, base);
loc_822B650C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,17892(r31)
	PPC_STORE_U32(r31.u32 + 17892, r11.u32);
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

__attribute__((alias("__imp__sub_822B6528"))) PPC_WEAK_FUNC(sub_822B6528);
PPC_FUNC_IMPL(__imp__sub_822B6528) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6554
	if (cr6.eq) goto loc_822B6554;
	// bl 0x822b5f00
	ctx.lr = 0x822B6550;
	sub_822B5F00(ctx, base);
	// b 0x822b6558
	goto loc_822B6558;
loc_822B6554:
	// li r3,1
	ctx.r3.s64 = 1;
loc_822B6558:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_822B6578"))) PPC_WEAK_FUNC(sub_822B6578);
PPC_FUNC_IMPL(__imp__sub_822B6578) {
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
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,25896
	ctx.r4.s64 = r11.s64 + 25896;
	// addi r3,r10,30716
	ctx.r3.s64 = ctx.r10.s64 + 30716;
	// bl 0x82554798
	ctx.lr = 0x822B6598;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,24200
	ctx.r4.s64 = ctx.r9.s64 + 24200;
	// addi r3,r8,30676
	ctx.r3.s64 = ctx.r8.s64 + 30676;
	// bl 0x82554798
	ctx.lr = 0x822B65AC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,24248
	ctx.r4.s64 = ctx.r7.s64 + 24248;
	// addi r3,r6,30640
	ctx.r3.s64 = ctx.r6.s64 + 30640;
	// bl 0x82554798
	ctx.lr = 0x822B65C0;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,24304
	ctx.r4.s64 = ctx.r5.s64 + 24304;
	// addi r3,r3,30596
	ctx.r3.s64 = ctx.r3.s64 + 30596;
	// bl 0x82554798
	ctx.lr = 0x822B65D4;
	sub_82554798(ctx, base);
	// bl 0x822af198
	ctx.lr = 0x822B65D8;
	sub_822AF198(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B65E8"))) PPC_WEAK_FUNC(sub_822B65E8);
PPC_FUNC_IMPL(__imp__sub_822B65E8) {
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
	ctx.lr = 0x822B65F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// bl 0x82350510
	ctx.lr = 0x822B6610;
	sub_82350510(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stb r28,165(r31)
	PPC_STORE_U8(r31.u32 + 165, r28.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r30,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r30.u32);
	// addi r9,r11,22804
	ctx.r9.s64 = r11.s64 + 22804;
	// stw r29,172(r31)
	PPC_STORE_U32(r31.u32 + 172, r29.u32);
	// stb r10,164(r31)
	PPC_STORE_U8(r31.u32 + 164, ctx.r10.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r27,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r27.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822B6640"))) PPC_WEAK_FUNC(sub_822B6640);
PPC_FUNC_IMPL(__imp__sub_822B6640) {
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
	ctx.lr = 0x822B6648;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// stw r4,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r4.u32);
	// stw r5,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r5.u32);
	// stw r6,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r6.u32);
	// stb r11,164(r31)
	PPC_STORE_U8(r31.u32 + 164, r11.u8);
	// bl 0x82130000
	ctx.lr = 0x822B6668;
	sub_82130000(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B667C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822B6690;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x822B6698;
	sub_82130000(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,12(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822B66AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B66C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B66D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822B66E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,36(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822B66FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,40(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B6710;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B6724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822B6738;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,48(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822B674C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,52(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 52);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B6760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B6774;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822B6788;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82562c80
	ctx.lr = 0x822B678C;
	sub_82562C80(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b67bc
	if (cr6.eq) goto loc_822B67BC;
	// bl 0x82562c80
	ctx.lr = 0x822B6798;
	sub_82562C80(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,0(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x823eaef8
	ctx.lr = 0x822B67A8;
	sub_823EAEF8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822B67BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B67BC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B67C4;
	sub_823EAEF8(ctx, base);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,-16
	ctx.r3.s64 = r11.s64 + -16;
	// bne cr6,0x822b67d8
	if (!cr6.eq) goto loc_822B67D8;
	// li r3,0
	ctx.r3.s64 = 0;
loc_822B67D8:
	// bl 0x82352ef0
	ctx.lr = 0x822B67DC;
	sub_82352EF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B67E4;
	sub_823EAEF8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B67F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B67FC;
	sub_823EAEF8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B6804"))) PPC_WEAK_FUNC(sub_822B6804);
PPC_FUNC_IMPL(__imp__sub_822B6804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B6808"))) PPC_WEAK_FUNC(sub_822B6808);
PPC_FUNC_IMPL(__imp__sub_822B6808) {
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
	// bl 0x823eaef8
	ctx.lr = 0x822B6824;
	sub_823EAEF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,8032
	ctx.r3.s64 = 8032;
	// bl 0x82130528
	ctx.lr = 0x822B6830;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b689c
	if (cr6.eq) goto loc_822B689C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r6,172(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 172);
	// lwz r5,20(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x8235af90
	ctx.lr = 0x822B6848;
	sub_8235AF90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// bne cr6,0x822b685c
	if (!cr6.eq) goto loc_822B685C;
loc_822B6858:
	// li r11,0
	r11.s64 = 0;
loc_822B685C:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,593(r31)
	PPC_STORE_U8(r31.u32 + 593, ctx.r10.u8);
	// lwz r4,132(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 132);
	// bl 0x82357b80
	ctx.lr = 0x822B6874;
	sub_82357B80(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x822B687C;
	sub_82130000(ctx, base);
	// li r3,2176
	ctx.r3.s64 = 2176;
	// bl 0x82130528
	ctx.lr = 0x822B6884;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b68a4
	if (cr6.eq) goto loc_822B68A4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8233d908
	ctx.lr = 0x822B6894;
	sub_8233D908(ctx, base);
	// stw r3,84(r30)
	PPC_STORE_U32(r30.u32 + 84, ctx.r3.u32);
	// b 0x822b68ac
	goto loc_822B68AC;
loc_822B689C:
	// li r31,0
	r31.s64 = 0;
	// b 0x822b6858
	goto loc_822B6858;
loc_822B68A4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,84(r30)
	PPC_STORE_U32(r30.u32 + 84, r11.u32);
loc_822B68AC:
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

__attribute__((alias("__imp__sub_822B68C4"))) PPC_WEAK_FUNC(sub_822B68C4);
PPC_FUNC_IMPL(__imp__sub_822B68C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B68C8"))) PPC_WEAK_FUNC(sub_822B68C8);
PPC_FUNC_IMPL(__imp__sub_822B68C8) {
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
	ctx.lr = 0x822B68D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,172(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// bl 0x82388580
	ctx.lr = 0x822B68E0;
	sub_82388580(ctx, base);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822b69a0
	if (cr6.lt) goto loc_822B69A0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B68F4;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,360
	ctx.r3.s64 = 360;
	// bl 0x82130528
	ctx.lr = 0x822B6900;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6914
	if (cr6.eq) goto loc_822B6914;
	// bl 0x82364580
	ctx.lr = 0x822B690C;
	sub_82364580(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822b6918
	goto loc_822B6918;
loc_822B6914:
	// li r31,0
	r31.s64 = 0;
loc_822B6918:
	// lwz r3,172(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// bl 0x82388580
	ctx.lr = 0x822B6920;
	sub_82388580(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822b69a0
	if (cr6.lt) goto loc_822B69A0;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// rlwinm r10,r11,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r9,21384
	r11.s64 = ctx.r9.s64 + 21384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x825ae378
	ctx.lr = 0x822B6944;
	sub_825AE378(ctx, base);
	// lwz r3,172(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// bl 0x82388580
	ctx.lr = 0x822B694C;
	sub_82388580(ctx, base);
	// bl 0x823985f0
	ctx.lr = 0x822B6950;
	sub_823985F0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blt cr6,0x822b6984
	if (cr6.lt) goto loc_822B6984;
	// bne cr6,0x822b6984
	if (!cr6.eq) goto loc_822B6984;
	// li r4,1
	ctx.r4.s64 = 1;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B6974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x822B6980;
	sub_82130000(ctx, base);
	// b 0x822b6990
	goto loc_822B6990;
loc_822B6984:
	// li r4,0
	ctx.r4.s64 = 0;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B6990;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B6990:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826e32d0
	ctx.lr = 0x822B699C;
	sub_826E32D0(ctx, base);
	// stw r31,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r31.u32);
loc_822B69A0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B69A8"))) PPC_WEAK_FUNC(sub_822B69A8);
PPC_FUNC_IMPL(__imp__sub_822B69A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,172(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 172);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822b69e8
	if (!cr6.eq) goto loc_822B69E8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,17896
	ctx.r10.s64 = r11.s64 + 17896;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b69e8
	if (!cr6.eq) goto loc_822B69E8;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10432(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10432);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_822B69E8:
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82365298
	sub_82365298(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B69F0"))) PPC_WEAK_FUNC(sub_822B69F0);
PPC_FUNC_IMPL(__imp__sub_822B69F0) {
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
	ctx.lr = 0x822B69F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B6A04;
	sub_823EAEF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,60
	ctx.r3.s64 = 60;
	// bl 0x82130528
	ctx.lr = 0x822B6A10;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6a24
	if (cr6.eq) goto loc_822B6A24;
	// bl 0x82562638
	ctx.lr = 0x822B6A1C;
	sub_82562638(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822b6a28
	goto loc_822B6A28;
loc_822B6A24:
	// li r31,0
	r31.s64 = 0;
loc_822B6A28:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// addi r5,r11,8
	ctx.r5.s64 = r11.s64 + 8;
	// bl 0x826e32d0
	ctx.lr = 0x822B6A3C;
	sub_826E32D0(ctx, base);
	// stw r31,52(r30)
	PPC_STORE_U32(r30.u32 + 52, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B6A48"))) PPC_WEAK_FUNC(sub_822B6A48);
PPC_FUNC_IMPL(__imp__sub_822B6A48) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822B6A50;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B6A5C;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,256
	ctx.r3.s64 = 256;
	// bl 0x82130528
	ctx.lr = 0x822B6A68;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6a7c
	if (cr6.eq) goto loc_822B6A7C;
	// bl 0x8232afd8
	ctx.lr = 0x822B6A74;
	sub_8232AFD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822b6a80
	goto loc_822B6A80;
loc_822B6A7C:
	// li r31,0
	r31.s64 = 0;
loc_822B6A80:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,172(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8232bb38
	ctx.lr = 0x822B6A90;
	sub_8232BB38(ctx, base);
	// stw r31,68(r29)
	PPC_STORE_U32(r29.u32 + 68, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B6A9C"))) PPC_WEAK_FUNC(sub_822B6A9C);
PPC_FUNC_IMPL(__imp__sub_822B6A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B6AA0"))) PPC_WEAK_FUNC(sub_822B6AA0);
PPC_FUNC_IMPL(__imp__sub_822B6AA0) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,31072
	ctx.r10.s64 = r11.s64 + 31072;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x822B6ACC;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b6ae4
	if (cr6.eq) goto loc_822B6AE4;
	// bl 0x82130588
	ctx.lr = 0x822B6AE0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822B6AE4:
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

__attribute__((alias("__imp__sub_822B6AFC"))) PPC_WEAK_FUNC(sub_822B6AFC);
PPC_FUNC_IMPL(__imp__sub_822B6AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B6B00"))) PPC_WEAK_FUNC(sub_822B6B00);
PPC_FUNC_IMPL(__imp__sub_822B6B00) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822B6B08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B6B14;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,832
	ctx.r3.s64 = 832;
	// bl 0x82130528
	ctx.lr = 0x822B6B20;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6b34
	if (cr6.eq) goto loc_822B6B34;
	// bl 0x8232c238
	ctx.lr = 0x822B6B2C;
	sub_8232C238(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822b6b38
	goto loc_822B6B38;
loc_822B6B34:
	// li r31,0
	r31.s64 = 0;
loc_822B6B38:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r11,-16
	r28.s64 = r11.s64 + -16;
	// bne cr6,0x822b6b4c
	if (!cr6.eq) goto loc_822B6B4C;
	// li r28,0
	r28.s64 = 0;
loc_822B6B4C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,92(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// bl 0x8221cfe8
	ctx.lr = 0x822B6B58;
	sub_8221CFE8(ctx, base);
	// lwz r11,84(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 84);
	// stw r31,8(r29)
	PPC_STORE_U32(r29.u32 + 8, r31.u32);
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// lwz r3,80(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// bl 0x82360f90
	ctx.lr = 0x822B6B70;
	sub_82360F90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,16(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// lwz r5,28(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// bl 0x8232ceb0
	ctx.lr = 0x822B6B8C;
	sub_8232CEB0(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8232cf88
	ctx.lr = 0x822B6B9C;
	sub_8232CF88(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8232cff0
	ctx.lr = 0x822B6BAC;
	sub_8232CFF0(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8255a4e8
	ctx.lr = 0x822B6BBC;
	sub_8255A4E8(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8255a490
	ctx.lr = 0x822B6BCC;
	sub_8255A490(ctx, base);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r11,76(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822b6be4
	if (!cr6.eq) goto loc_822B6BE4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822b6bf8
	goto loc_822B6BF8;
loc_822B6BE4:
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mulli r10,r11,104
	ctx.r10.s64 = r11.s64 * 104;
	// lwz r11,-12120(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12120);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823964a8
	ctx.lr = 0x822B6BF8;
	sub_823964A8(ctx, base);
loc_822B6BF8:
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subfic r7,r8,0
	xer.ca = ctx.r8.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r8.s64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// lbzx r6,r9,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// cntlzw r10,r6
	ctx.r10.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r11,r5,0,29,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r8,r11,264
	ctx.r8.s64 = r11.s64 + 264;
	// rlwinm r11,r8,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r28
	ctx.r5.u64 = r11.u64 + r28.u64;
	// bl 0x8232d068
	ctx.lr = 0x822B6C40;
	sub_8232D068(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8255a710
	ctx.lr = 0x822B6C50;
	sub_8255A710(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8232d408
	ctx.lr = 0x822B6C60;
	sub_8232D408(ctx, base);
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// bl 0x8232d460
	ctx.lr = 0x822B6C70;
	sub_8232D460(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8232d8c8
	ctx.lr = 0x822B6C78;
	sub_8232D8C8(ctx, base);
	// li r3,36
	ctx.r3.s64 = 36;
	// bl 0x82130528
	ctx.lr = 0x822B6C80;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6c94
	if (cr6.eq) goto loc_822B6C94;
	// bl 0x82345540
	ctx.lr = 0x822B6C8C;
	sub_82345540(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x822b6c98
	goto loc_822B6C98;
loc_822B6C94:
	// li r28,0
	r28.s64 = 0;
loc_822B6C98:
	// lwz r11,92(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,172(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// lwz r6,196(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 196);
	// bl 0x823455a8
	ctx.lr = 0x822B6CB0;
	sub_823455A8(ctx, base);
	// stw r28,664(r31)
	PPC_STORE_U32(r31.u32 + 664, r28.u32);
	// li r28,0
	r28.s64 = 0;
	// lbz r10,165(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 165);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b6cfc
	if (cr6.eq) goto loc_822B6CFC;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x822B6CCC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6ce0
	if (cr6.eq) goto loc_822B6CE0;
	// bl 0x82345cc8
	ctx.lr = 0x822B6CD8;
	sub_82345CC8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x822b6ce4
	goto loc_822B6CE4;
loc_822B6CE0:
	// li r28,0
	r28.s64 = 0;
loc_822B6CE4:
	// lwz r11,92(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 92);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,172(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// lwz r6,200(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 200);
	// bl 0x82345da0
	ctx.lr = 0x822B6CFC;
	sub_82345DA0(ctx, base);
loc_822B6CFC:
	// stw r28,668(r31)
	PPC_STORE_U32(r31.u32 + 668, r28.u32);
	// li r3,832
	ctx.r3.s64 = 832;
	// bl 0x82130528
	ctx.lr = 0x822B6D08;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6d1c
	if (cr6.eq) goto loc_822B6D1C;
	// bl 0x823380b0
	ctx.lr = 0x822B6D14;
	sub_823380B0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x822b6d20
	goto loc_822B6D20;
loc_822B6D1C:
	// li r28,0
	r28.s64 = 0;
loc_822B6D20:
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82338fa8
	ctx.lr = 0x822B6D30;
	sub_82338FA8(ctx, base);
	// stw r28,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r28.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B6D48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B6D5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,2256
	ctx.r4.s64 = ctx.r7.s64 + 2256;
	// bl 0x82558290
	ctx.lr = 0x822B6D6C;
	sub_82558290(ctx, base);
	// li r6,6
	ctx.r6.s64 = 6;
	// li r11,-1
	r11.s64 = -1;
	// stb r6,384(r31)
	PPC_STORE_U8(r31.u32 + 384, ctx.r6.u8);
	// lwz r5,172(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 172);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822b6d88
	if (cr6.eq) goto loc_822B6D88;
	// li r11,-16385
	r11.s64 = -16385;
loc_822B6D88:
	// stw r11,376(r31)
	PPC_STORE_U32(r31.u32 + 376, r11.u32);
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b6dc4
	if (cr6.eq) goto loc_822B6DC4;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8258e660
	ctx.lr = 0x822B6DAC;
	sub_8258E660(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8258e620
	ctx.lr = 0x822B6DBC;
	sub_8258E620(ctx, base);
	// lwz r11,376(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 376);
	// stw r11,20(r30)
	PPC_STORE_U32(r30.u32 + 20, r11.u32);
loc_822B6DC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822B6DCC"))) PPC_WEAK_FUNC(sub_822B6DCC);
PPC_FUNC_IMPL(__imp__sub_822B6DCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B6DD0"))) PPC_WEAK_FUNC(sub_822B6DD0);
PPC_FUNC_IMPL(__imp__sub_822B6DD0) {
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
	ctx.lr = 0x822B6DD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B6DE4;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,96
	ctx.r3.s64 = 96;
	// bl 0x82130528
	ctx.lr = 0x822B6DF0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6e04
	if (cr6.eq) goto loc_822B6E04;
	// bl 0x823430e0
	ctx.lr = 0x822B6DFC;
	sub_823430E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822b6e08
	goto loc_822B6E08;
loc_822B6E04:
	// li r31,0
	r31.s64 = 0;
loc_822B6E08:
	// lwz r11,12(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,92(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// bl 0x8221ed98
	ctx.lr = 0x822B6E1C;
	sub_8221ED98(ctx, base);
	// stw r31,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B6E28"))) PPC_WEAK_FUNC(sub_822B6E28);
PPC_FUNC_IMPL(__imp__sub_822B6E28) {
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
	ctx.lr = 0x822B6E30;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823eaef8
	ctx.lr = 0x822B6E3C;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,80
	ctx.r3.s64 = 80;
	// bl 0x82130528
	ctx.lr = 0x822B6E48;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6e5c
	if (cr6.eq) goto loc_822B6E5C;
	// bl 0x823505e0
	ctx.lr = 0x822B6E54;
	sub_823505E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822b6e60
	goto loc_822B6E60;
loc_822B6E5C:
	// li r31,0
	r31.s64 = 0;
loc_822B6E60:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,12(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// lwz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,80(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B6E80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r31,44(r29)
	PPC_STORE_U32(r29.u32 + 44, r31.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B6E8C"))) PPC_WEAK_FUNC(sub_822B6E8C);
PPC_FUNC_IMPL(__imp__sub_822B6E8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B6E90"))) PPC_WEAK_FUNC(sub_822B6E90);
PPC_FUNC_IMPL(__imp__sub_822B6E90) {
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
	// bl 0x823eaef8
	ctx.lr = 0x822B6EAC;
	sub_823EAEF8(ctx, base);
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,76(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822b6ec8
	if (!cr6.eq) goto loc_822B6EC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x822b6edc
	goto loc_822B6EDC;
loc_822B6EC8:
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mulli r10,r11,104
	ctx.r10.s64 = r11.s64 * 104;
	// lwz r11,-12120(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12120);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x823964a8
	ctx.lr = 0x822B6EDC;
	sub_823964A8(ctx, base);
loc_822B6EDC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b6f28
	if (cr6.eq) goto loc_822B6F28;
	// li r3,160
	ctx.r3.s64 = 160;
	// bl 0x82130528
	ctx.lr = 0x822B6EF0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6f10
	if (cr6.eq) goto loc_822B6F10;
	// bl 0x82368728
	ctx.lr = 0x822B6EFC;
	sub_82368728(ctx, base);
	// lwz r5,96(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82562cc8
	ctx.lr = 0x822B6F0C;
	sub_82562CC8(ctx, base);
	// b 0x822b6f58
	goto loc_822B6F58;
loc_822B6F10:
	// li r31,0
	r31.s64 = 0;
	// lwz r5,96(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82562cc8
	ctx.lr = 0x822B6F24;
	sub_82562CC8(ctx, base);
	// b 0x822b6f58
	goto loc_822B6F58;
loc_822B6F28:
	// li r3,104
	ctx.r3.s64 = 104;
	// bl 0x82130528
	ctx.lr = 0x822B6F30;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6f44
	if (cr6.eq) goto loc_822B6F44;
	// bl 0x82366238
	ctx.lr = 0x822B6F3C;
	sub_82366238(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822b6f48
	goto loc_822B6F48;
loc_822B6F44:
	// li r31,0
	r31.s64 = 0;
loc_822B6F48:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,96(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 96);
	// lwz r4,8(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x823662b8
	ctx.lr = 0x822B6F58;
	sub_823662B8(ctx, base);
loc_822B6F58:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// oris r9,r11,24
	ctx.r9.u64 = r11.u64 | 1572864;
	// stw r9,28(r31)
	PPC_STORE_U32(r31.u32 + 28, ctx.r9.u32);
	// stw r10,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r10.u32);
	// stw r31,48(r30)
	PPC_STORE_U32(r30.u32 + 48, r31.u32);
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

__attribute__((alias("__imp__sub_822B6F88"))) PPC_WEAK_FUNC(sub_822B6F88);
PPC_FUNC_IMPL(__imp__sub_822B6F88) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x822B6F90;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,496
	ctx.r3.s64 = 496;
	// bl 0x82130528
	ctx.lr = 0x822B6FA4;
	sub_82130528(ctx, base);
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6fbc
	if (cr6.eq) goto loc_822B6FBC;
	// bl 0x82330e20
	ctx.lr = 0x822B6FB4;
	sub_82330E20(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x822b6fc0
	goto loc_822B6FC0;
loc_822B6FBC:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_822B6FC0:
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// li r3,112
	ctx.r3.s64 = 112;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// lwz r10,16(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// lwz r9,24(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// stw r9,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r9.u32);
	// bl 0x82130528
	ctx.lr = 0x822B6FE0;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b6ff4
	if (cr6.eq) goto loc_822B6FF4;
	// bl 0x823318e8
	ctx.lr = 0x822B6FEC;
	sub_823318E8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x822b6ff8
	goto loc_822B6FF8;
loc_822B6FF4:
	// mr r28,r27
	r28.u64 = r27.u64;
loc_822B6FF8:
	// stw r31,80(r28)
	PPC_STORE_U32(r28.u32 + 80, r31.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r28,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r28.u32);
	// bl 0x82130528
	ctx.lr = 0x822B7008;
	sub_82130528(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b7040
	if (cr6.eq) goto loc_822B7040;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// addi r10,r11,31072
	ctx.r10.s64 = r11.s64 + 31072;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x821b5a60
	ctx.lr = 0x822B7028;
	sub_821B5A60(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r27,4(r30)
	PPC_STORE_U32(r30.u32 + 4, r27.u32);
	// mr r11,r30
	r11.u64 = r30.u64;
	// addi r8,r9,31116
	ctx.r8.s64 = ctx.r9.s64 + 31116;
	// stw r8,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r8.u32);
	// b 0x822b7044
	goto loc_822B7044;
loc_822B7040:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822B7044:
	// stw r28,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r28.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stw r27,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r27.u32);
	// lwz r3,88(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// lwz r9,12(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lwz r6,88(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 88);
	// lwz r5,84(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// bl 0x822b7240
	ctx.lr = 0x822B7070;
	sub_822B7240(ctx, base);
	// lwz r8,12(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r6,108(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 108);
	// lwz r5,104(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 104);
	// bl 0x8236c008
	ctx.lr = 0x822B7088;
	sub_8236C008(ctx, base);
	// lwz r7,12(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// lwz r3,96(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// lwz r6,116(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 116);
	// lwz r5,112(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 112);
	// bl 0x8236b400
	ctx.lr = 0x822B70A0;
	sub_8236B400(ctx, base);
	// stw r31,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r31.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822B70B0"))) PPC_WEAK_FUNC(sub_822B70B0);
PPC_FUNC_IMPL(__imp__sub_822B70B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r31.u64);
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823db9d8
	ctx.lr = 0x822B70C4;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8255fe10
	ctx.lr = 0x822B70D0;
	sub_8255FE10(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f11,31304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31304);
	ctx.f11.f64 = double(temp.f32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,14884(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// lis r4,-32252
	ctx.r4.s64 = -2113667072;
	// lfs f10,-29232(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -29232);
	ctx.f10.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// lfs f9,11368(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 11368);
	ctx.f9.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f8,24920(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24920);
	ctx.f8.f64 = double(temp.f32);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lfs f7,12428(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 12428);
	ctx.f7.f64 = double(temp.f32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfs f6,3732(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3732);
	ctx.f6.f64 = double(temp.f32);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lfs f5,14988(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 14988);
	ctx.f5.f64 = double(temp.f32);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// lfs f4,17032(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 17032);
	ctx.f4.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f3,-32032(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -32032);
	ctx.f3.f64 = double(temp.f32);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f2,25088(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 25088);
	ctx.f2.f64 = double(temp.f32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lfs f1,-31384(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31384);
	ctx.f1.f64 = double(temp.f32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f28,31304(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 31304);
	f28.f64 = double(temp.f32);
	// lfs f31,27640(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 27640);
	f31.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,31908
	ctx.r10.s64 = r11.s64 + 31908;
	// lfs f12,31924(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 31924);
	ctx.f12.f64 = double(temp.f32);
	// lfs f30,27636(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 27636);
	f30.f64 = double(temp.f32);
	// lfs f29,30120(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 30120);
	f29.f64 = double(temp.f32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stfs f11,24(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f13,28(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 28, temp.u32);
	// stfs f10,112(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 112, temp.u32);
	// stfs f9,116(r31)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// stfs f8,32(r31)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stfs f13,36(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f0,76(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 76, temp.u32);
	// stfs f7,80(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,72(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 72, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// stfs f6,88(r31)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stfs f13,92(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 92, temp.u32);
	// stfs f5,96(r31)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// stfs f4,100(r31)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(r31.u32 + 100, temp.u32);
	// stfs f3,104(r31)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(r31.u32 + 104, temp.u32);
	// stfs f2,108(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 108, temp.u32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f1,44(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 44, temp.u32);
	// stfs f31,48(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 48, temp.u32);
	// stfs f12,52(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 52, temp.u32);
	// stfs f30,56(r31)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r31.u32 + 56, temp.u32);
	// stfs f29,60(r31)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(r31.u32 + 60, temp.u32);
	// stfs f12,64(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 64, temp.u32);
	// stfs f28,68(r31)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// addi r12,r1,-16
	r12.s64 = ctx.r1.s64 + -16;
	// bl 0x823dba24
	ctx.lr = 0x822B71DC;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B71EC"))) PPC_WEAK_FUNC(sub_822B71EC);
PPC_FUNC_IMPL(__imp__sub_822B71EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B71F0"))) PPC_WEAK_FUNC(sub_822B71F0);
PPC_FUNC_IMPL(__imp__sub_822B71F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17916(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17916);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B71FC"))) PPC_WEAK_FUNC(sub_822B71FC);
PPC_FUNC_IMPL(__imp__sub_822B71FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7200"))) PPC_WEAK_FUNC(sub_822B7200);
PPC_FUNC_IMPL(__imp__sub_822B7200) {
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
	// bl 0x8255fe90
	ctx.lr = 0x822B7218;
	sub_8255FE90(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,31908
	ctx.r10.s64 = r11.s64 + 31908;
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

__attribute__((alias("__imp__sub_822B723C"))) PPC_WEAK_FUNC(sub_822B723C);
PPC_FUNC_IMPL(__imp__sub_822B723C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7240"))) PPC_WEAK_FUNC(sub_822B7240);
PPC_FUNC_IMPL(__imp__sub_822B7240) {
	PPC_FUNC_PROLOGUE();
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,24(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 24);
	f0.f64 = double(temp.f32);
	// lfs f13,24(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f1,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + f0.f64));
	// stfs f11,24(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// lfs f10,28(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 28);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,28(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f1,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f1.f64 + ctx.f10.f64));
	// stfs f7,28(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// lfs f6,112(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,112(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f1,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f1.f64 + ctx.f6.f64));
	// stfs f3,112(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 112, temp.u32);
	// lfs f2,116(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 116);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,116(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 116);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f2
	ctx.f13.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fmadds f12,f13,f1,f2
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f2.f64));
	// stfs f12,116(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 116, temp.u32);
	// lfs f11,32(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,32(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 32);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmadds f8,f9,f1,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f1.f64 + ctx.f11.f64));
	// stfs f8,32(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// lfs f7,36(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,36(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fmadds f4,f5,f1,f7
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f1.f64 + ctx.f7.f64));
	// stfs f4,36(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// lfs f3,76(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 76);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,76(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 76);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f0,f2,f3
	f0.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// fmadds f13,f0,f1,f3
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64 + ctx.f3.f64));
	// stfs f13,76(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// lfs f12,80(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,80(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f1,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f9,80(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lfs f8,72(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 72);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,72(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 72);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f1,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f8.f64));
	// stfs f5,72(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// lfs f4,84(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 84);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,84(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 84);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f0,f2,f1,f4
	f0.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f4.f64));
	// stfs f0,84(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// lfs f13,88(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f1,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64 + ctx.f13.f64));
	// stfs f10,88(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 88, temp.u32);
	// lfs f9,92(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 92);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,92(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 92);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f9
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f9.f64));
	// fmadds f6,f7,f1,f9
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f1.f64 + ctx.f9.f64));
	// stfs f6,92(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// lfs f5,96(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 96);
	ctx.f5.f64 = double(temp.f32);
	// lfs f4,96(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 96);
	ctx.f4.f64 = double(temp.f32);
	// fsubs f3,f4,f5
	ctx.f3.f64 = double(float(ctx.f4.f64 - ctx.f5.f64));
	// fmadds f2,f3,f1,f5
	ctx.f2.f64 = double(float(ctx.f3.f64 * ctx.f1.f64 + ctx.f5.f64));
	// stfs f2,96(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 96, temp.u32);
	// lfs f0,100(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 100);
	f0.f64 = double(temp.f32);
	// lfs f13,100(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f11,f12,f1,f0
	ctx.f11.f64 = double(float(ctx.f12.f64 * ctx.f1.f64 + f0.f64));
	// stfs f11,100(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 100, temp.u32);
	// lfs f10,104(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 104);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,104(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 104);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f1,f10
	ctx.f7.f64 = double(float(ctx.f8.f64 * ctx.f1.f64 + ctx.f10.f64));
	// stfs f7,104(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 104, temp.u32);
	// lfs f6,108(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 108);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,108(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 108);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f4,f5,f6
	ctx.f4.f64 = double(float(ctx.f5.f64 - ctx.f6.f64));
	// fmadds f3,f4,f1,f6
	ctx.f3.f64 = double(float(ctx.f4.f64 * ctx.f1.f64 + ctx.f6.f64));
	// stfs f3,108(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// lfs f2,40(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// lfs f0,40(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 40);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f2
	ctx.f13.f64 = double(float(f0.f64 - ctx.f2.f64));
	// fmadds f12,f13,f1,f2
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f1.f64 + ctx.f2.f64));
	// stfs f12,40(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// lfs f11,44(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 44);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,44(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmadds f8,f9,f1,f11
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f1.f64 + ctx.f11.f64));
	// stfs f8,44(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// lfs f7,48(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 48);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,48(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f7
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// fmadds f4,f5,f1,f7
	ctx.f4.f64 = double(float(ctx.f5.f64 * ctx.f1.f64 + ctx.f7.f64));
	// stfs f4,48(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// lfs f3,52(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 52);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,52(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f0,f2,f3
	f0.f64 = double(float(ctx.f2.f64 - ctx.f3.f64));
	// fmadds f13,f0,f1,f3
	ctx.f13.f64 = double(float(f0.f64 * ctx.f1.f64 + ctx.f3.f64));
	// stfs f13,52(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lfs f12,56(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,56(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 56);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f9,f10,f1,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f1.f64 + ctx.f12.f64));
	// stfs f9,56(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// lfs f8,60(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 60);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,60(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 60);
	ctx.f7.f64 = double(temp.f32);
	// fsubs f6,f7,f8
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f8.f64));
	// fmadds f5,f6,f1,f8
	ctx.f5.f64 = double(float(ctx.f6.f64 * ctx.f1.f64 + ctx.f8.f64));
	// stfs f5,60(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// lfs f4,64(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 64);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,64(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	ctx.f3.f64 = double(temp.f32);
	// fsubs f2,f3,f4
	ctx.f2.f64 = double(float(ctx.f3.f64 - ctx.f4.f64));
	// fmadds f0,f2,f1,f4
	f0.f64 = double(float(ctx.f2.f64 * ctx.f1.f64 + ctx.f4.f64));
	// stfs f0,64(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// lfs f13,68(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,68(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 68);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmadds f10,f11,f1,f13
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f1.f64 + ctx.f13.f64));
	// stfs f10,68(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B7424"))) PPC_WEAK_FUNC(sub_822B7424);
PPC_FUNC_IMPL(__imp__sub_822B7424) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7428"))) PPC_WEAK_FUNC(sub_822B7428);
PPC_FUNC_IMPL(__imp__sub_822B7428) {
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
	// li r3,132
	ctx.r3.s64 = 132;
	// bl 0x82130528
	ctx.lr = 0x822B743C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b7458
	if (cr6.eq) goto loc_822B7458;
	// bl 0x822b70b0
	ctx.lr = 0x822B7448;
	sub_822B70B0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_822B7458:
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

__attribute__((alias("__imp__sub_822B746C"))) PPC_WEAK_FUNC(sub_822B746C);
PPC_FUNC_IMPL(__imp__sub_822B746C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7470"))) PPC_WEAK_FUNC(sub_822B7470);
PPC_FUNC_IMPL(__imp__sub_822B7470) {
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
	ctx.lr = 0x822B7478;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,17916
	r31.s64 = r11.s64 + 17916;
	// lwz r11,17916(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17916);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b7704
	if (!cr6.eq) goto loc_822B7704;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822B7498;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b74ac
	if (cr6.eq) goto loc_822B74AC;
	// bl 0x821d5408
	ctx.lr = 0x822B74A8;
	sub_821D5408(ctx, base);
	// b 0x822b74b0
	goto loc_822B74B0;
loc_822B74AC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822B74B0:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32227
	r11.s64 = -2112028672;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,31928
	ctx.r7.s64 = ctx.r10.s64 + 31928;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,25672
	ctx.r9.s64 = r11.s64 + 25672;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,132
	ctx.r5.s64 = 132;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32213
	ctx.r8.s64 = -2111111168;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r8,29736
	ctx.r4.s64 = ctx.r8.s64 + 29736;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r5,r10,-12
	ctx.r5.s64 = ctx.r10.s64 + -12;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,-36
	ctx.r9.s64 = ctx.r3.s64 + -36;
	// addi r4,r8,36
	ctx.r4.s64 = ctx.r8.s64 + 36;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,80
	ctx.r10.s64 = 80;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r11,76
	r11.s64 = 76;
	// addi r6,r3,12
	ctx.r6.s64 = ctx.r3.s64 + 12;
	// addi r5,r8,60
	ctx.r5.s64 = ctx.r8.s64 + 60;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// li r11,84
	r11.s64 = 84;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r9,72
	ctx.r9.s64 = 72;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,88
	ctx.r10.s64 = 88;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,108
	ctx.r4.s64 = ctx.r7.s64 + 108;
	// addi r6,r3,84
	ctx.r6.s64 = ctx.r3.s64 + 84;
	// addi r5,r8,132
	ctx.r5.s64 = ctx.r8.s64 + 132;
	// li r11,96
	r11.s64 = 96;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r9,92
	ctx.r9.s64 = 92;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,100
	ctx.r10.s64 = 100;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,180
	ctx.r4.s64 = ctx.r7.s64 + 180;
	// addi r6,r3,156
	ctx.r6.s64 = ctx.r3.s64 + 156;
	// addi r5,r8,204
	ctx.r5.s64 = ctx.r8.s64 + 204;
	// li r11,108
	r11.s64 = 108;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r9,104
	ctx.r9.s64 = 104;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,28
	ctx.r10.s64 = 28;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,252
	ctx.r4.s64 = ctx.r7.s64 + 252;
	// addi r6,r3,228
	ctx.r6.s64 = ctx.r3.s64 + 228;
	// addi r5,r8,276
	ctx.r5.s64 = ctx.r8.s64 + 276;
	// li r11,112
	r11.s64 = 112;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,116
	ctx.r10.s64 = 116;
	// addi r4,r7,300
	ctx.r4.s64 = ctx.r7.s64 + 300;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r11,32
	r11.s64 = 32;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r30,-32114
	r30.s64 = -2104623104;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r4,-23488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23488);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r7,r11,348
	ctx.r7.s64 = r11.s64 + 348;
	// addi r6,r10,372
	ctx.r6.s64 = ctx.r10.s64 + 372;
	// addi r8,r3,324
	ctx.r8.s64 = ctx.r3.s64 + 324;
	// li r11,36
	r11.s64 = 36;
	// li r10,40
	ctx.r10.s64 = 40;
	// li r9,44
	ctx.r9.s64 = 44;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// lis r29,-32130
	r29.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// addi r8,r5,396
	ctx.r8.s64 = ctx.r5.s64 + 396;
	// addi r7,r3,420
	ctx.r7.s64 = ctx.r3.s64 + 420;
	// addi r6,r29,444
	ctx.r6.s64 = r29.s64 + 444;
	// li r11,48
	r11.s64 = 48;
	// li r10,52
	ctx.r10.s64 = 52;
	// li r9,56
	ctx.r9.s64 = 56;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r29,-32130
	r29.s64 = -2105671680;
	// addi r8,r5,468
	ctx.r8.s64 = ctx.r5.s64 + 468;
	// addi r7,r3,492
	ctx.r7.s64 = ctx.r3.s64 + 492;
	// addi r6,r29,516
	ctx.r6.s64 = r29.s64 + 516;
	// li r11,60
	r11.s64 = 60;
	// li r10,64
	ctx.r10.s64 = 64;
	// li r9,68
	ctx.r9.s64 = 68;
	// stw r11,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// bne cr6,0x822b769c
	if (!cr6.eq) goto loc_822B769C;
	// bl 0x82564488
	ctx.lr = 0x822B7698;
	sub_82564488(ctx, base);
	// lwz r4,-23488(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -23488);
loc_822B769C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821d4458
	ctx.lr = 0x822B76A8;
	sub_821D4458(ctx, base);
	// lwz r11,-23488(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -23488);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// rlwinm r4,r11,16,22,31
	ctx.r4.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 16) & 0x3FF;
	// bl 0x821d4100
	ctx.lr = 0x822B76C0;
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
	ctx.lr = 0x822B76DC;
	sub_821D41D0(ctx, base);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r8,544
	ctx.r4.s64 = ctx.r8.s64 + 544;
	// bl 0x821d4b00
	ctx.lr = 0x822B76EC;
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
	ctx.lr = 0x822B7704;
	sub_821C0548(ctx, base);
loc_822B7704:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B770C"))) PPC_WEAK_FUNC(sub_822B770C);
PPC_FUNC_IMPL(__imp__sub_822B770C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7710"))) PPC_WEAK_FUNC(sub_822B7710);
PPC_FUNC_IMPL(__imp__sub_822B7710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,0
	r11.s64 = 0;
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B771C"))) PPC_WEAK_FUNC(sub_822B771C);
PPC_FUNC_IMPL(__imp__sub_822B771C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7720"))) PPC_WEAK_FUNC(sub_822B7720);
PPC_FUNC_IMPL(__imp__sub_822B7720) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822B7728;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82256058
	ctx.lr = 0x822B7734;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b782c
	if (cr6.eq) goto loc_822B782C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lfs f12,32272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32272);
	ctx.f12.f64 = double(temp.f32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f0,-4960(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -4960);
	f0.f64 = double(temp.f32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r28,r3,8
	r28.s64 = ctx.r3.s64 + 8;
	// lfs f13,32268(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32268);
	ctx.f13.f64 = double(temp.f32);
	// li r29,0
	r29.s64 = 0;
	// lfs f11,32264(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32264);
	ctx.f11.f64 = double(temp.f32);
	// lfs f9,-30576(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -30576);
	ctx.f9.f64 = double(temp.f32);
	// lfs f10,32252(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 32252);
	ctx.f10.f64 = double(temp.f32);
	// lfs f8,32260(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 32260);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,32256(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 32256);
	ctx.f7.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f8,128(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f7,144(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f10,168(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f11,176(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f10,184(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lwz r3,3088(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3088);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x822b782c
	if (!cr6.gt) goto loc_822B782C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r28,8
	r31.s64 = r28.s64 + 8;
	// lfs f31,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_822B77F4:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x822ae768
	ctx.lr = 0x822B7804;
	sub_822AE768(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822a8838
	ctx.lr = 0x822B780C;
	sub_822A8838(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822ab258
	ctx.lr = 0x822B7814;
	sub_822AB258(ctx, base);
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822b77f4
	if (cr6.lt) goto loc_822B77F4;
loc_822B782C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822B7838"))) PPC_WEAK_FUNC(sub_822B7838);
PPC_FUNC_IMPL(__imp__sub_822B7838) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,27644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	f0.f64 = double(temp.f32);
	// lwz r8,188(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 188);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B7874;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B7884"))) PPC_WEAK_FUNC(sub_822B7884);
PPC_FUNC_IMPL(__imp__sub_822B7884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7888"))) PPC_WEAK_FUNC(sub_822B7888);
PPC_FUNC_IMPL(__imp__sub_822B7888) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,27644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27644);
	f0.f64 = double(temp.f32);
	// lwz r8,184(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// stfs f0,92(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822B78C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B78D4"))) PPC_WEAK_FUNC(sub_822B78D4);
PPC_FUNC_IMPL(__imp__sub_822B78D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B78D8"))) PPC_WEAK_FUNC(sub_822B78D8);
PPC_FUNC_IMPL(__imp__sub_822B78D8) {
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
	ctx.lr = 0x822B78E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b7934
	if (cr6.eq) goto loc_822B7934;
	// li r31,0
	r31.s64 = 0;
loc_822B78FC:
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b7920
	if (cr6.eq) goto loc_822B7920;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B7920;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B7920:
	// lhz r11,12(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822b78fc
	if (cr6.lt) goto loc_822B78FC;
loc_822B7934:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B793C"))) PPC_WEAK_FUNC(sub_822B793C);
PPC_FUNC_IMPL(__imp__sub_822B793C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7940"))) PPC_WEAK_FUNC(sub_822B7940);
PPC_FUNC_IMPL(__imp__sub_822B7940) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,-5148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// lhz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822b798c
	if (!cr6.gt) goto loc_822B798C;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_822B7970:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r31,r7
	cr6.compare<uint32_t>(r31.u32, ctx.r7.u32, xer);
	// beq cr6,0x822b79a8
	if (cr6.eq) goto loc_822B79A8;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r9,r8
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, xer);
	// blt cr6,0x822b7970
	if (cr6.lt) goto loc_822B7970;
loc_822B798C:
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// addi r9,r11,8
	ctx.r9.s64 = r11.s64 + 8;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,12(r11)
	PPC_STORE_U16(r11.u32 + 12, ctx.r7.u16);
	// stwx r31,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, r31.u32);
loc_822B79A8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B79BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,17892(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 17892);
	// bl 0x822b5ff0
	ctx.lr = 0x822B79CC;
	sub_822B5FF0(ctx, base);
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

__attribute__((alias("__imp__sub_822B79E0"))) PPC_WEAK_FUNC(sub_822B79E0);
PPC_FUNC_IMPL(__imp__sub_822B79E0) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r11,0
	r11.s64 = 0;
	// lwz r10,-5148(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -5148);
	// lhz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 28);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822b7a3c
	if (!cr6.gt) goto loc_822B7A3C;
	// lwz r10,24(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
loc_822B7A14:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r31
	cr6.compare<uint32_t>(ctx.r8.u32, r31.u32, xer);
	// beq cr6,0x822b7a34
	if (cr6.eq) goto loc_822B7A34;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x822b7a14
	if (cr6.lt) goto loc_822B7A14;
	// b 0x822b7a3c
	goto loc_822B7A3C;
loc_822B7A34:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x822b7a94
	if (!cr6.eq) goto loc_822B7A94;
loc_822B7A3C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,136(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B7A54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8e38
	ctx.lr = 0x822B7A5C;
	sub_822A8E38(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7f10
	ctx.lr = 0x822B7A68;
	sub_822A7F10(ctx, base);
	// lwz r11,-5148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -5148);
	// li r4,-1
	ctx.r4.s64 = -1;
	// addi r10,r11,24
	ctx.r10.s64 = r11.s64 + 24;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,24(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// lhz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 28);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,28(r11)
	PPC_STORE_U16(r11.u32 + 28, ctx.r7.u16);
	// stwx r31,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, r31.u32);
	// bl 0x82683820
	ctx.lr = 0x822B7A94;
	sub_82683820(ctx, base);
loc_822B7A94:
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

__attribute__((alias("__imp__sub_822B7AAC"))) PPC_WEAK_FUNC(sub_822B7AAC);
PPC_FUNC_IMPL(__imp__sub_822B7AAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7AB0"))) PPC_WEAK_FUNC(sub_822B7AB0);
PPC_FUNC_IMPL(__imp__sub_822B7AB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// li r7,0
	ctx.r7.s64 = 0;
	// lbzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-5148
	r11.s64 = r11.s64 + -5148;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x822b7adc
	if (cr6.eq) goto loc_822B7ADC;
	// lhz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 20);
	// b 0x822b7ae0
	goto loc_822B7AE0;
loc_822B7ADC:
	// lhz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 12);
loc_822B7AE0:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822b7b28
	if (!cr6.gt) goto loc_822B7B28;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822B7AEC:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822b7afc
	if (cr6.eq) goto loc_822B7AFC;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// b 0x822b7b00
	goto loc_822B7B00;
loc_822B7AFC:
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
loc_822B7B00:
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b7b18
	if (cr6.eq) goto loc_822B7B18;
	// lwz r5,140(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// cmpw cr6,r5,r3
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r3.s32, xer);
	// beq cr6,0x822b7b30
	if (cr6.eq) goto loc_822B7B30;
loc_822B7B18:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// blt cr6,0x822b7aec
	if (cr6.lt) goto loc_822B7AEC;
loc_822B7B28:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822B7B30:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B7B38"))) PPC_WEAK_FUNC(sub_822B7B38);
PPC_FUNC_IMPL(__imp__sub_822B7B38) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// li r7,0
	ctx.r7.s64 = 0;
	// lbzx r6,r10,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,-5148
	r11.s64 = r11.s64 + -5148;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x822b7b64
	if (cr6.eq) goto loc_822B7B64;
	// lhz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 20);
	// b 0x822b7b68
	goto loc_822B7B68;
loc_822B7B64:
	// lhz r8,12(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 12);
loc_822B7B68:
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822b7bbc
	if (!cr6.gt) goto loc_822B7BBC;
	// li r11,0
	r11.s64 = 0;
loc_822B7B74:
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822b7b84
	if (cr6.eq) goto loc_822B7B84;
	// lwz r10,16(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// b 0x822b7b88
	goto loc_822B7B88;
loc_822B7B84:
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
loc_822B7B88:
	// lwzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b7bac
	if (cr6.eq) goto loc_822B7BAC;
	// lwz r5,660(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 660);
	// cmpwi cr6,r5,2
	cr6.compare<int32_t>(ctx.r5.s32, 2, xer);
	// bne cr6,0x822b7bac
	if (!cr6.eq) goto loc_822B7BAC;
	// lwz r10,656(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822b7bc4
	if (!cr6.eq) goto loc_822B7BC4;
loc_822B7BAC:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r7,r8
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r8.s32, xer);
	// blt cr6,0x822b7b74
	if (cr6.lt) goto loc_822B7B74;
loc_822B7BBC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822B7BC4:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B7BCC"))) PPC_WEAK_FUNC(sub_822B7BCC);
PPC_FUNC_IMPL(__imp__sub_822B7BCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7BD0"))) PPC_WEAK_FUNC(sub_822B7BD0);
PPC_FUNC_IMPL(__imp__sub_822B7BD0) {
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
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b7c3c
	if (cr6.eq) goto loc_822B7C3C;
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// twllei r11,0
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// divwu r8,r10,r11
	ctx.r8.u32 = ctx.r10.u32 / r11.u32;
	// mullw r7,r8,r11
	ctx.r7.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// rlwinm r11,r6,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lwz r5,0(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x822b7c3c
	if (cr6.eq) goto loc_822B7C3C;
loc_822B7C1C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// beq cr6,0x822b7c54
	if (cr6.eq) goto loc_822B7C54;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r9,8
	r11.s64 = ctx.r9.s64 + 8;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x822b7c1c
	if (!cr6.eq) goto loc_822B7C1C;
loc_822B7C3C:
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
loc_822B7C54:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130588
	ctx.lr = 0x822B7C64;
	sub_82130588(ctx, base);
	// lhz r9,6(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// li r3,1
	ctx.r3.s64 = 1;
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// sth r8,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r8.u16);
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

__attribute__((alias("__imp__sub_822B7C8C"))) PPC_WEAK_FUNC(sub_822B7C8C);
PPC_FUNC_IMPL(__imp__sub_822B7C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7C90"))) PPC_WEAK_FUNC(sub_822B7C90);
PPC_FUNC_IMPL(__imp__sub_822B7C90) {
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
	ctx.lr = 0x822B7C98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b7cc4
	if (cr6.eq) goto loc_822B7CC4;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822b7cc8
	if (cr6.eq) goto loc_822B7CC8;
loc_822B7CC4:
	// li r11,0
	r11.s64 = 0;
loc_822B7CC8:
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b7d64
	if (cr6.eq) goto loc_822B7D64;
	// clrlwi r27,r28,24
	r27.u64 = r28.u32 & 0xFF;
loc_822B7CE0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lhz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// add r9,r29,r11
	ctx.r9.u64 = r29.u64 + r11.u64;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// twllei r10,0
	// divw r7,r9,r10
	ctx.r7.s32 = ctx.r9.s32 / ctx.r10.s32;
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r5,r7,r10
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r10.s32);
	// subf r4,r5,r9
	ctx.r4.s64 = ctx.r9.s64 - ctx.r5.s64;
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// rlwinm r30,r4,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// andc r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 & ~ctx.r6.u64;
	// twlgei r3,-1
	// lwzx r3,r30,r8
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + ctx.r8.u32);
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x822b7d34
	if (cr6.eq) goto loc_822B7D34;
	// lbz r11,467(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 467);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b7d34
	if (cr6.eq) goto loc_822B7D34;
	// bl 0x822b79e0
	ctx.lr = 0x822B7D34;
	sub_822B79E0(ctx, base);
loc_822B7D34:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x822b7d54
	if (!cr6.eq) goto loc_822B7D54;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B7D54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B7D54:
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x822b7ce0
	if (cr6.lt) goto loc_822B7CE0;
loc_822B7D64:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b7db0
	if (!cr6.eq) goto loc_822B7DB0;
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b7da8
	if (cr6.eq) goto loc_822B7DA8;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// twllei r11,0
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r8,r9,r11
	ctx.r8.s32 = ctx.r9.s32 / r11.s32;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// mullw r6,r8,r11
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(r11.s32);
	// andc r5,r11,r7
	ctx.r5.u64 = r11.u64 & ~ctx.r7.u64;
	// subf r11,r6,r9
	r11.s64 = ctx.r9.s64 - ctx.r6.s64;
	// twlgei r5,-1
	// b 0x822b7dac
	goto loc_822B7DAC;
loc_822B7DA8:
	// li r11,0
	r11.s64 = 0;
loc_822B7DAC:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
loc_822B7DB0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// bl 0x822b5ad8
	ctx.lr = 0x822B7DBC;
	sub_822B5AD8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822B7DC4"))) PPC_WEAK_FUNC(sub_822B7DC4);
PPC_FUNC_IMPL(__imp__sub_822B7DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7DC8"))) PPC_WEAK_FUNC(sub_822B7DC8);
PPC_FUNC_IMPL(__imp__sub_822B7DC8) {
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
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 12);
	// li r11,0
	r11.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, r11.u32);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x822b7e64
	if (!cr6.gt) goto loc_822B7E64;
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_822B7E00:
	// lwz r5,0(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lbz r10,467(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 467);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b7e58
	if (cr6.eq) goto loc_822B7E58;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// ble cr6,0x822b7e40
	if (!cr6.gt) goto loc_822B7E40;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// subf r10,r7,r11
	ctx.r10.s64 = r11.s64 - ctx.r7.s64;
	// add r11,r9,r8
	r11.u64 = ctx.r9.u64 + ctx.r8.u64;
loc_822B7E28:
	// lwz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,-4
	r11.s64 = r11.s64 + -4;
	// bne 0x822b7e28
	if (!cr0.eq) goto loc_822B7E28;
	// lwz r11,480(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 480);
loc_822B7E40:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// stw r11,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, r11.u32);
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// lwz r11,480(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 480);
loc_822B7E58:
	// addic. r3,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r3.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bne 0x822b7e00
	if (!cr0.eq) goto loc_822B7E00;
loc_822B7E64:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x822b7e88
	if (!cr6.gt) goto loc_822B7E88;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
loc_822B7E74:
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x822b79e0
	ctx.lr = 0x822B7E7C;
	sub_822B79E0(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x822b7e74
	if (!cr0.eq) goto loc_822B7E74;
loc_822B7E88:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
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

__attribute__((alias("__imp__sub_822B7EA0"))) PPC_WEAK_FUNC(sub_822B7EA0);
PPC_FUNC_IMPL(__imp__sub_822B7EA0) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x822B7EC0;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x826bddb0
	ctx.lr = 0x822B7ED0;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b7ef0
	if (cr6.eq) goto loc_822B7EF0;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
loc_822B7EF0:
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
}

__attribute__((alias("__imp__sub_822B7F08"))) PPC_WEAK_FUNC(sub_822B7F08);
PPC_FUNC_IMPL(__imp__sub_822B7F08) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x822B7F30;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,36
	ctx.r3.s64 = r30.s64 + 36;
	// bl 0x826bddb0
	ctx.lr = 0x822B7F40;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b7f58
	if (cr6.eq) goto loc_822B7F58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,48(r11)
	PPC_STORE_U8(r11.u32 + 48, ctx.r10.u8);
	// b 0x822b7f68
	goto loc_822B7F68;
loc_822B7F58:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,32280
	ctx.r3.s64 = r11.s64 + 32280;
	// bl 0x82130000
	ctx.lr = 0x822B7F68;
	sub_82130000(ctx, base);
loc_822B7F68:
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

__attribute__((alias("__imp__sub_822B7F80"))) PPC_WEAK_FUNC(sub_822B7F80);
PPC_FUNC_IMPL(__imp__sub_822B7F80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822b7940
	sub_822B7940(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B7F8C"))) PPC_WEAK_FUNC(sub_822B7F8C);
PPC_FUNC_IMPL(__imp__sub_822B7F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7F90"))) PPC_WEAK_FUNC(sub_822B7F90);
PPC_FUNC_IMPL(__imp__sub_822B7F90) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822b79e0
	sub_822B79E0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B7F9C"))) PPC_WEAK_FUNC(sub_822B7F9C);
PPC_FUNC_IMPL(__imp__sub_822B7F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7FA0"))) PPC_WEAK_FUNC(sub_822B7FA0);
PPC_FUNC_IMPL(__imp__sub_822B7FA0) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,8(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x822b7ab0
	ctx.lr = 0x822B7FBC;
	sub_822B7AB0(ctx, base);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B7FD4"))) PPC_WEAK_FUNC(sub_822B7FD4);
PPC_FUNC_IMPL(__imp__sub_822B7FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B7FD8"))) PPC_WEAK_FUNC(sub_822B7FD8);
PPC_FUNC_IMPL(__imp__sub_822B7FD8) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// bl 0x822b7b38
	ctx.lr = 0x822B7FEC;
	sub_822B7B38(ctx, base);
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_822B8008"))) PPC_WEAK_FUNC(sub_822B8008);
PPC_FUNC_IMPL(__imp__sub_822B8008) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822b7720
	sub_822B7720(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B801C"))) PPC_WEAK_FUNC(sub_822B801C);
PPC_FUNC_IMPL(__imp__sub_822B801C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B8020"))) PPC_WEAK_FUNC(sub_822B8020);
PPC_FUNC_IMPL(__imp__sub_822B8020) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b804c
	if (cr6.eq) goto loc_822B804C;
	// lhz r11,28(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 28);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822B804C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B8060"))) PPC_WEAK_FUNC(sub_822B8060);
PPC_FUNC_IMPL(__imp__sub_822B8060) {
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
	// li r11,0
	r11.s64 = 0;
	// li r9,864
	ctx.r9.s64 = 864;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// beq cr6,0x822b80ac
	if (cr6.eq) goto loc_822B80AC;
	// mulli r3,r10,864
	ctx.r3.s64 = ctx.r10.s64 * 864;
	// bl 0x82130528
	ctx.lr = 0x822B80A8;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_822B80AC:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x822B80BC;
	sub_821F10E0(ctx, base);
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

__attribute__((alias("__imp__sub_822B80D4"))) PPC_WEAK_FUNC(sub_822B80D4);
PPC_FUNC_IMPL(__imp__sub_822B80D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B80D8"))) PPC_WEAK_FUNC(sub_822B80D8);
PPC_FUNC_IMPL(__imp__sub_822B80D8) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,32376
	ctx.r9.s64 = ctx.r10.s64 + 32376;
	// addi r30,r31,48
	r30.s64 = r31.s64 + 48;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// sth r11,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r11.u16);
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// sth r11,20(r31)
	PPC_STORE_U16(r31.u32 + 20, r11.u16);
	// sth r11,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r11.u16);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// sth r11,28(r31)
	PPC_STORE_U16(r31.u32 + 28, r11.u16);
	// sth r11,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r11.u16);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// sth r11,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r11.u16);
	// sth r11,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r11.u16);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// stb r11,47(r31)
	PPC_STORE_U8(r31.u32 + 47, r11.u8);
	// bl 0x821ce460
	ctx.lr = 0x822B8150;
	sub_821CE460(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821ce210
	ctx.lr = 0x822B815C;
	sub_821CE210(ctx, base);
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

__attribute__((alias("__imp__sub_822B8178"))) PPC_WEAK_FUNC(sub_822B8178);
PPC_FUNC_IMPL(__imp__sub_822B8178) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// addi r10,r11,32376
	ctx.r10.s64 = r11.s64 + 32376;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82608de8
	ctx.lr = 0x822B81A0;
	sub_82608DE8(ctx, base);
	// lhz r9,30(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 30);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b81b4
	if (cr6.eq) goto loc_822B81B4;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x82130588
	ctx.lr = 0x822B81B4;
	sub_82130588(ctx, base);
loc_822B81B4:
	// lhz r11,22(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 22);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b81c8
	if (cr6.eq) goto loc_822B81C8;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// bl 0x82130588
	ctx.lr = 0x822B81C8;
	sub_82130588(ctx, base);
loc_822B81C8:
	// lhz r11,14(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b81dc
	if (cr6.eq) goto loc_822B81DC;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x822B81DC;
	sub_82130588(ctx, base);
loc_822B81DC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x822B81E4;
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

__attribute__((alias("__imp__sub_822B81F8"))) PPC_WEAK_FUNC(sub_822B81F8);
PPC_FUNC_IMPL(__imp__sub_822B81F8) {
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
	ctx.lr = 0x822B8200;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lhz r11,12(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b8248
	if (cr6.eq) goto loc_822B8248;
	// li r31,0
	r31.s64 = 0;
loc_822B821C:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwzx r3,r31,r11
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,116(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 116);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B8234;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,12(r27)
	ctx.r8.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// blt cr6,0x822b821c
	if (cr6.lt) goto loc_822B821C;
loc_822B8248:
	// lhz r11,28(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 28);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b83ec
	if (cr6.eq) goto loc_822B83EC;
	// lis r11,0
	r11.s64 = 0;
	// addi r29,r27,24
	r29.s64 = r27.s64 + 24;
	// li r28,0
	r28.s64 = 0;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// ori r24,r11,65535
	r24.u64 = r11.u64 | 65535;
	// lis r25,-32121
	r25.s64 = -2105081856;
loc_822B8270:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r3,r28,r11
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// lwz r10,656(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x822b83d0
	if (!cr6.eq) goto loc_822B83D0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B8294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r3,17892(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 17892);
	// lwzx r4,r28,r9
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + ctx.r9.u32);
	// bl 0x822b61b0
	ctx.lr = 0x822B82A4;
	sub_822B61B0(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r7,r28,r8
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822b833c
	if (cr6.eq) goto loc_822B833C;
	// lwz r10,-5148(r23)
	ctx.r10.u64 = PPC_LOAD_U32(r23.u32 + -5148);
	// li r11,0
	r11.s64 = 0;
	// lhz r8,12(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822b833c
	if (!cr6.gt) goto loc_822B833C;
	// addi r9,r10,8
	ctx.r9.s64 = ctx.r10.s64 + 8;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
loc_822B82D0:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r6,r7
	cr6.compare<uint32_t>(ctx.r6.u32, ctx.r7.u32, xer);
	// beq cr6,0x822b82f0
	if (cr6.eq) goto loc_822B82F0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822b82d0
	if (cr6.lt) goto loc_822B82D0;
	// b 0x822b833c
	goto loc_822B833C;
loc_822B82F0:
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x822b8330
	if (!cr6.lt) goto loc_822B8330;
loc_822B8304:
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x822b8304
	if (cr6.lt) goto loc_822B8304;
loc_822B8330:
	// lhz r11,4(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// add r10,r11,r24
	ctx.r10.u64 = r11.u64 + r24.u64;
	// sth r10,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r10.u16);
loc_822B833C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r30,32(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 32);
	// lwzx r31,r28,r11
	r31.u64 = PPC_LOAD_U32(r28.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822b8380
	if (cr6.eq) goto loc_822B8380;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B8368;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r31,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r31.u32);
	// lhz r11,6(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,6(r30)
	PPC_STORE_U16(r30.u32 + 6, ctx.r8.u16);
loc_822B8380:
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// clrlwi r11,r26,16
	r11.u64 = r26.u32 & 0xFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x822b83c0
	if (!cr6.lt) goto loc_822B83C0;
loc_822B8394:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822b8394
	if (cr6.lt) goto loc_822B8394;
loc_822B83C0:
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// add r10,r11,r24
	ctx.r10.u64 = r11.u64 + r24.u64;
	// sth r10,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r10.u16);
	// b 0x822b83d8
	goto loc_822B83D8;
loc_822B83D0:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a7f10
	ctx.lr = 0x822B83D8;
	sub_822A7F10(ctx, base);
loc_822B83D8:
	// lhz r11,28(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 28);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x822b8270
	if (cr6.lt) goto loc_822B8270;
loc_822B83EC:
	// lhz r11,22(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 22);
	// addi r29,r27,16
	r29.s64 = r27.s64 + 16;
	// lhz r31,12(r27)
	r31.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b8420
	if (!cr6.eq) goto loc_822B8420;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// sth r31,6(r29)
	PPC_STORE_U16(r29.u32 + 6, r31.u16);
	// beq cr6,0x822b8418
	if (cr6.eq) goto loc_822B8418;
	// rlwinm r3,r31,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x822B8414;
	sub_82130528(ctx, base);
	// b 0x822b841c
	goto loc_822B841C;
loc_822B8418:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822B841C:
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
loc_822B8420:
	// sth r31,4(r29)
	PPC_STORE_U16(r29.u32 + 4, r31.u16);
	// li r30,0
	r30.s64 = 0;
	// lhz r10,12(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b8484
	if (cr6.eq) goto loc_822B8484;
	// li r31,0
	r31.s64 = 0;
loc_822B8438:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwzx r9,r31,r11
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// stwx r9,r31,r10
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// lwz r8,8(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwzx r7,r31,r8
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822b8470
	if (cr6.eq) goto loc_822B8470;
	// rotlwi r11,r8,0
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lwz r3,48(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b8470
	if (cr6.eq) goto loc_822B8470;
	// bl 0x82331648
	ctx.lr = 0x822B8470;
	sub_82331648(ctx, base);
loc_822B8470:
	// lhz r11,12(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822b8438
	if (cr6.lt) goto loc_822B8438;
loc_822B8484:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_822B848C"))) PPC_WEAK_FUNC(sub_822B848C);
PPC_FUNC_IMPL(__imp__sub_822B848C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8490"))) PPC_WEAK_FUNC(sub_822B8490);
PPC_FUNC_IMPL(__imp__sub_822B8490) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r10,r31,36
	ctx.r10.s64 = r31.s64 + 36;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r30,r11
	r30.u64 = r11.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// bl 0x82237920
	ctx.lr = 0x822B84C8;
	sub_82237920(ctx, base);
	// lis r9,23772
	ctx.r9.s64 = 1557921792;
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// ori r7,r9,64167
	ctx.r7.u64 = ctx.r9.u64 | 64167;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lhz r6,42(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 42);
	// mulld r11,r8,r7
	r11.s64 = ctx.r8.s64 * ctx.r7.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// twllei r6,0
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r5,r11,1
	ctx.r5.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// rldicl r8,r11,32,32
	ctx.r8.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// rotlwi r9,r5,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r5.u32, 1);
	// divw r3,r5,r6
	ctx.r3.s32 = ctx.r5.s32 / ctx.r6.s32;
	// stw r8,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r8.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// andc r7,r6,r9
	ctx.r7.u64 = ctx.r6.u64 & ~ctx.r9.u64;
	// mullw r6,r3,r6
	ctx.r6.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r6.s32);
	// twlgei r7,-1
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// beq cr6,0x822b85e8
	if (cr6.eq) goto loc_822B85E8;
	// lwz r7,88(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_822B852C:
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x822b8548
	if (!cr6.eq) goto loc_822B8548;
	// lbz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b8548
	if (!cr6.eq) goto loc_822B8548;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_822B8548:
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// bne cr6,0x822b859c
	if (!cr6.eq) goto loc_822B859C;
	// lbz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 48);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822b85ec
	if (cr6.eq) goto loc_822B85EC;
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b852c
	if (!cr6.eq) goto loc_822B852C;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
loc_822B8574:
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// bge cr6,0x822b85e0
	if (!cr6.lt) goto loc_822B85E0;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b8574
	if (cr6.eq) goto loc_822B8574;
	// b 0x822b852c
	goto loc_822B852C;
loc_822B859C:
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b852c
	if (!cr6.eq) goto loc_822B852C;
	// lhz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
loc_822B85B8:
	// cmpw cr6,r8,r6
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, xer);
	// bge cr6,0x822b85e0
	if (!cr6.lt) goto loc_822B85E0;
	// lwz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// lwzx r10,r9,r10
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b85b8
	if (cr6.eq) goto loc_822B85B8;
	// b 0x822b852c
	goto loc_822B852C;
loc_822B85E0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822b852c
	if (!cr6.eq) goto loc_822B852C;
loc_822B85E8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_822B85EC:
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

__attribute__((alias("__imp__sub_822B8604"))) PPC_WEAK_FUNC(sub_822B8604);
PPC_FUNC_IMPL(__imp__sub_822B8604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8608"))) PPC_WEAK_FUNC(sub_822B8608);
PPC_FUNC_IMPL(__imp__sub_822B8608) {
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
	ctx.lr = 0x822B8610;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,36
	ctx.r10.s64 = ctx.r3.s64 + 36;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r27,r11
	r27.u64 = r11.u64;
	// bl 0x82237920
	ctx.lr = 0x822B8638;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b86c4
	if (cr6.eq) goto loc_822B86C4;
	// lwz r28,88(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_822B864C:
	// lwz r29,4(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lbz r11,48(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b867c
	if (!cr6.eq) goto loc_822B867C;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// bne cr6,0x822b8668
	if (!cr6.eq) goto loc_822B8668;
	// mr r27,r29
	r27.u64 = r29.u64;
loc_822B8668:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822b7ea0
	ctx.lr = 0x822B8674;
	sub_822B7EA0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x822b86e0
	if (!cr6.eq) goto loc_822B86E0;
loc_822B867C:
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x822b864c
	if (!cr6.eq) goto loc_822B864C;
	// lhz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_822B8694:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x822b86bc
	if (!cr6.lt) goto loc_822B86BC;
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
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
	// beq cr6,0x822b8694
	if (cr6.eq) goto loc_822B8694;
	// b 0x822b864c
	goto loc_822B864C;
loc_822B86BC:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x822b864c
	if (!cr6.eq) goto loc_822B864C;
loc_822B86C4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r11,32384
	ctx.r3.s64 = r11.s64 + 32384;
	// bl 0x82130000
	ctx.lr = 0x822B86D4;
	sub_82130000(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
loc_822B86E0:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822B86EC"))) PPC_WEAK_FUNC(sub_822B86EC);
PPC_FUNC_IMPL(__imp__sub_822B86EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B86F0"))) PPC_WEAK_FUNC(sub_822B86F0);
PPC_FUNC_IMPL(__imp__sub_822B86F0) {
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
	ctx.lr = 0x822B86F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,36
	ctx.r10.s64 = ctx.r3.s64 + 36;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// bl 0x82237920
	ctx.lr = 0x822B8718;
	sub_82237920(ctx, base);
	// lwz r30,84(r1)
	r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b877c
	if (cr6.eq) goto loc_822B877C;
	// lwz r29,88(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r31,80(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_822B872C:
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x82398c08
	ctx.lr = 0x822B8734;
	sub_82398C08(ctx, base);
	// lwz r30,8(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x822b872c
	if (!cr6.eq) goto loc_822B872C;
	// lhz r9,4(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// rlwinm r11,r31,2,0,29
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r31,1
	ctx.r10.s64 = r31.s64 + 1;
loc_822B874C:
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x822b8774
	if (!cr6.lt) goto loc_822B8774;
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
	// beq cr6,0x822b874c
	if (cr6.eq) goto loc_822B874C;
	// b 0x822b872c
	goto loc_822B872C;
loc_822B8774:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x822b872c
	if (!cr6.eq) goto loc_822B872C;
loc_822B877C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B8784"))) PPC_WEAK_FUNC(sub_822B8784);
PPC_FUNC_IMPL(__imp__sub_822B8784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8788"))) PPC_WEAK_FUNC(sub_822B8788);
PPC_FUNC_IMPL(__imp__sub_822B8788) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r31.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x822B87B4;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r30,r30,36
	r30.s64 = r30.s64 + 36;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826bddb0
	ctx.lr = 0x822B87C8;
	sub_826BDDB0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b87ec
	if (cr6.eq) goto loc_822B87EC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b87ec
	if (cr6.eq) goto loc_822B87EC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,32536
	ctx.r3.s64 = r11.s64 + 32536;
	// bl 0x82130000
	ctx.lr = 0x822B87E8;
	sub_82130000(ctx, base);
	// b 0x822b8804
	goto loc_822B8804;
loc_822B87EC:
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r5,r1,140
	ctx.r5.s64 = ctx.r1.s64 + 140;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82389998
	ctx.lr = 0x822B8804;
	sub_82389998(ctx, base);
loc_822B8804:
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

__attribute__((alias("__imp__sub_822B881C"))) PPC_WEAK_FUNC(sub_822B881C);
PPC_FUNC_IMPL(__imp__sub_822B881C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8820"))) PPC_WEAK_FUNC(sub_822B8820);
PPC_FUNC_IMPL(__imp__sub_822B8820) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-5148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lwz r3,12(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// sth r8,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r8.u16);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// beq cr6,0x822b8884
	if (cr6.eq) goto loc_822B8884;
	// bl 0x822b9bf8
	ctx.lr = 0x822B8868;
	sub_822B9BF8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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
loc_822B8884:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_822B88A4"))) PPC_WEAK_FUNC(sub_822B88A4);
PPC_FUNC_IMPL(__imp__sub_822B88A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B88A8"))) PPC_WEAK_FUNC(sub_822B88A8);
PPC_FUNC_IMPL(__imp__sub_822B88A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32213
	r11.s64 = -2111111168;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,30776
	ctx.r3.s64 = r11.s64 + 30776;
	// b 0x822c97b0
	sub_822C97B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B88B8"))) PPC_WEAK_FUNC(sub_822B88B8);
PPC_FUNC_IMPL(__imp__sub_822B88B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32213
	r11.s64 = -2111111168;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,30856
	ctx.r3.s64 = r11.s64 + 30856;
	// b 0x822c97b0
	sub_822C97B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B88C8"))) PPC_WEAK_FUNC(sub_822B88C8);
PPC_FUNC_IMPL(__imp__sub_822B88C8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822b7dc8
	sub_822B7DC8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B88DC"))) PPC_WEAK_FUNC(sub_822B88DC);
PPC_FUNC_IMPL(__imp__sub_822B88DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B88E0"))) PPC_WEAK_FUNC(sub_822B88E0);
PPC_FUNC_IMPL(__imp__sub_822B88E0) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-5148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x822b892c
	if (cr6.eq) goto loc_822B892C;
	// bl 0x822b7ea0
	ctx.lr = 0x822B8910;
	sub_822B7EA0(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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
loc_822B892C:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_822B894C"))) PPC_WEAK_FUNC(sub_822B894C);
PPC_FUNC_IMPL(__imp__sub_822B894C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8950"))) PPC_WEAK_FUNC(sub_822B8950);
PPC_FUNC_IMPL(__imp__sub_822B8950) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x822b7f08
	sub_822B7F08(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B8970"))) PPC_WEAK_FUNC(sub_822B8970);
PPC_FUNC_IMPL(__imp__sub_822B8970) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B8974"))) PPC_WEAK_FUNC(sub_822B8974);
PPC_FUNC_IMPL(__imp__sub_822B8974) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8978"))) PPC_WEAK_FUNC(sub_822B8978);
PPC_FUNC_IMPL(__imp__sub_822B8978) {
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
	// bl 0x822b8178
	ctx.lr = 0x822B8998;
	sub_822B8178(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b89b0
	if (cr6.eq) goto loc_822B89B0;
	// bl 0x82130588
	ctx.lr = 0x822B89AC;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822B89B0:
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

__attribute__((alias("__imp__sub_822B89C8"))) PPC_WEAK_FUNC(sub_822B89C8);
PPC_FUNC_IMPL(__imp__sub_822B89C8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x822B89D0;
	// stwu r1,-752(r1)
	ea = -752 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r25,r11,30576
	r25.s64 = r11.s64 + 30576;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r4,r10,-32748
	ctx.r4.s64 = ctx.r10.s64 + -32748;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821ca540
	ctx.lr = 0x822B89F0;
	sub_821CA540(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// addi r31,r11,-32760
	r31.s64 = r11.s64 + -32760;
	// addi r5,r9,-32764
	ctx.r5.s64 = ctx.r9.s64 + -32764;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x821ca6a8
	ctx.lr = 0x822B8A14;
	sub_821CA6A8(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// bne cr6,0x822b8a48
	if (!cr6.eq) goto loc_822B8A48;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822B8A28;
	sub_821C9A90(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,32752
	ctx.r4.s64 = r11.s64 + 32752;
	// addi r3,r10,32692
	ctx.r3.s64 = ctx.r10.s64 + 32692;
	// bl 0x82130000
	ctx.lr = 0x822B8A40;
	sub_82130000(ctx, base);
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d9230
	return;
loc_822B8A48:
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821d1cd0
	ctx.lr = 0x822B8A50;
	sub_821D1CD0(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// addi r4,r11,32672
	ctx.r4.s64 = r11.s64 + 32672;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821cf7b8
	ctx.lr = 0x822B8A64;
	sub_821CF7B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r24,r11,32660
	r24.s64 = r11.s64 + 32660;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x821cff40
	ctx.lr = 0x822B8A7C;
	sub_821CFF40(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b8bb8
	if (cr6.eq) goto loc_822B8BB8;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r29,r22,36
	r29.s64 = r22.s64 + 36;
	// li r30,0
	r30.s64 = 0;
	// addi r26,r10,-29628
	r26.s64 = ctx.r10.s64 + -29628;
	// addi r28,r9,9848
	r28.s64 = ctx.r9.s64 + 9848;
	// addi r27,r11,-29624
	r27.s64 = r11.s64 + -29624;
loc_822B8AA8:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821d0898
	ctx.lr = 0x822B8AB4;
	sub_821D0898(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821cfe20
	ctx.lr = 0x822B8AC0;
	sub_821CFE20(ctx, base);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821cfaa8
	ctx.lr = 0x822B8AD0;
	sub_821CFAA8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9790
	ctx.lr = 0x822B8ADC;
	sub_821C9790(ctx, base);
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b8b40
	if (cr6.eq) goto loc_822B8B40;
	// divwu r10,r3,r11
	ctx.r10.u32 = ctx.r3.u32 / r11.u32;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// twllei r11,0
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r11.s32);
	// subf r7,r8,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r8.s64;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r6,r9
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b8b40
	if (cr6.eq) goto loc_822B8B40;
loc_822B8B0C:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplw cr6,r3,r10
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b8b28
	if (cr6.eq) goto loc_822B8B28;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b8b0c
	if (!cr6.eq) goto loc_822B8B0C;
	// b 0x822b8b40
	goto loc_822B8B40;
loc_822B8B28:
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b8b40
	if (cr6.eq) goto loc_822B8B40;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822b8b84
	if (!cr6.eq) goto loc_822B8B84;
loc_822B8B40:
	// li r3,52
	ctx.r3.s64 = 52;
	// bl 0x82130528
	ctx.lr = 0x822B8B48;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822b8b74
	if (cr6.eq) goto loc_822B8B74;
	// sth r30,42(r31)
	PPC_STORE_U16(r31.u32 + 42, r30.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r30,40(r31)
	PPC_STORE_U16(r31.u32 + 40, r30.u16);
	// stw r30,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r30.u32);
	// stb r30,47(r31)
	PPC_STORE_U8(r31.u32 + 47, r30.u8);
	// stb r30,48(r31)
	PPC_STORE_U8(r31.u32 + 48, r30.u8);
	// bl 0x823986d0
	ctx.lr = 0x822B8B70;
	sub_823986D0(ctx, base);
	// b 0x822b8b78
	goto loc_822B8B78;
loc_822B8B74:
	// mr r31,r30
	r31.u64 = r30.u64;
loc_822B8B78:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x822b8788
	ctx.lr = 0x822B8B84;
	sub_822B8788(ctx, base);
loc_822B8B84:
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82398ca8
	ctx.lr = 0x822B8B90;
	sub_82398CA8(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821d0898
	ctx.lr = 0x822B8B9C;
	sub_821D0898(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x821cff40
	ctx.lr = 0x822B8BAC;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b8aa8
	if (!cr6.eq) goto loc_822B8AA8;
loc_822B8BB8:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821be610
	ctx.lr = 0x822B8BC0;
	sub_821BE610(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9a90
	ctx.lr = 0x822B8BC8;
	sub_821C9A90(ctx, base);
	// addi r1,r1,752
	ctx.r1.s64 = ctx.r1.s64 + 752;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_822B8BD0"))) PPC_WEAK_FUNC(sub_822B8BD0);
PPC_FUNC_IMPL(__imp__sub_822B8BD0) {
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
	ctx.lr = 0x822B8BD8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,36
	r30.s64 = ctx.r3.s64 + 36;
	// li r29,0
	r29.s64 = 0;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r29,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r29.u32);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// bl 0x82237920
	ctx.lr = 0x822B8BF8;
	sub_82237920(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b8c74
	if (cr6.eq) goto loc_822B8C74;
loc_822B8C04:
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x822b7bd0
	ctx.lr = 0x822B8C1C;
	sub_822B7BD0(ctx, base);
	// addi r3,r31,36
	ctx.r3.s64 = r31.s64 + 36;
	// bl 0x82608de8
	ctx.lr = 0x822B8C24;
	sub_82608DE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x822B8C2C;
	sub_82130588(ctx, base);
	// lhz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r11,r29
	r11.u64 = r29.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x822b8c60
	if (!cr6.gt) goto loc_822B8C60;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_822B8C44:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b8c60
	if (!cr6.eq) goto loc_822B8C60;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x822b8c44
	if (cr6.lt) goto loc_822B8C44;
loc_822B8C60:
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822b8c04
	if (!cr6.eq) goto loc_822B8C04;
loc_822B8C74:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B8C7C"))) PPC_WEAK_FUNC(sub_822B8C7C);
PPC_FUNC_IMPL(__imp__sub_822B8C7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8C80"))) PPC_WEAK_FUNC(sub_822B8C80);
PPC_FUNC_IMPL(__imp__sub_822B8C80) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-5148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b8cc4
	if (cr6.eq) goto loc_822B8CC4;
	// bl 0x822b8490
	ctx.lr = 0x822B8CA8;
	sub_822B8490(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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
loc_822B8CC4:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_822B8CE4"))) PPC_WEAK_FUNC(sub_822B8CE4);
PPC_FUNC_IMPL(__imp__sub_822B8CE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8CE8"))) PPC_WEAK_FUNC(sub_822B8CE8);
PPC_FUNC_IMPL(__imp__sub_822B8CE8) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-5148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// beq cr6,0x822b8d34
	if (cr6.eq) goto loc_822B8D34;
	// bl 0x822b8608
	ctx.lr = 0x822B8D18;
	sub_822B8608(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r3.u32);
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
loc_822B8D34:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
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

__attribute__((alias("__imp__sub_822B8D54"))) PPC_WEAK_FUNC(sub_822B8D54);
PPC_FUNC_IMPL(__imp__sub_822B8D54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B8D58"))) PPC_WEAK_FUNC(sub_822B8D58);
PPC_FUNC_IMPL(__imp__sub_822B8D58) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// b 0x822b86f0
	sub_822B86F0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B8D6C"))) PPC_WEAK_FUNC(sub_822B8D6C);
PPC_FUNC_IMPL(__imp__sub_822B8D6C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B8D70"))) PPC_WEAK_FUNC(sub_822B8D70);
PPC_FUNC_IMPL(__imp__sub_822B8D70) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x822B8D90;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b8da4
	if (cr6.eq) goto loc_822B8DA4;
	// li r4,100
	ctx.r4.s64 = 100;
	// bl 0x822b8060
	ctx.lr = 0x822B8DA0;
	sub_822B8060(ctx, base);
	// b 0x822b8da8
	goto loc_822B8DA8;
loc_822B8DA4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822B8DA8:
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
	// li r3,400
	ctx.r3.s64 = 400;
	// bl 0x82130528
	ctx.lr = 0x822B8DB4;
	sub_82130528(ctx, base);
	// li r30,100
	r30.s64 = 100;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// li r3,400
	ctx.r3.s64 = 400;
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// bl 0x82130528
	ctx.lr = 0x822B8DC8;
	sub_82130528(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// sth r30,22(r31)
	PPC_STORE_U16(r31.u32 + 22, r30.u16);
	// li r3,400
	ctx.r3.s64 = 400;
	// bl 0x82130528
	ctx.lr = 0x822B8DD8;
	sub_82130528(ctx, base);
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// sth r30,30(r31)
	PPC_STORE_U16(r31.u32 + 30, r30.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b89c8
	ctx.lr = 0x822B8DE8;
	sub_822B89C8(ctx, base);
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

__attribute__((alias("__imp__sub_822B8E00"))) PPC_WEAK_FUNC(sub_822B8E00);
PPC_FUNC_IMPL(__imp__sub_822B8E00) {
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
	ctx.lr = 0x822B8E08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r8,r31,8
	ctx.r8.s64 = r31.s64 + 8;
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x822b8e48
	if (cr6.eq) goto loc_822B8E48;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_822B8E34:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x822b8e34
	if (!cr6.eq) goto loc_822B8E34;
loc_822B8E48:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// addi r9,r31,16
	ctx.r9.s64 = r31.s64 + 16;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r6.u16);
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// lhz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 20);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x822b8e94
	if (cr6.eq) goto loc_822B8E94;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - r11.s64;
loc_822B8E80:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x822b8e80
	if (!cr6.eq) goto loc_822B8E80;
loc_822B8E94:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,4(r9)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r9.u32 + 4);
	// addi r8,r31,24
	ctx.r8.s64 = r31.s64 + 24;
	// srawi r7,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r7.s64 = r11.s32 >> 2;
	// subf r6,r7,r10
	ctx.r6.s64 = ctx.r10.s64 - ctx.r7.s64;
	// sth r6,4(r9)
	PPC_STORE_U16(ctx.r9.u32 + 4, ctx.r6.u16);
	// lwz r9,24(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lhz r4,28(r31)
	ctx.r4.u64 = PPC_LOAD_U16(r31.u32 + 28);
	// rotlwi r11,r4,2
	r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x822b8ee0
	if (cr6.eq) goto loc_822B8EE0;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
loc_822B8ECC:
	// lwz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r6,r7,r10
	PPC_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r6.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x822b8ecc
	if (!cr6.eq) goto loc_822B8ECC;
loc_822B8EE0:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r7,r9,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r7,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r7.u16);
	// lwz r30,32(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822b8f38
	if (cr6.eq) goto loc_822B8F38;
	// lbz r11,16(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b8f14
	if (cr6.eq) goto loc_822B8F14;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x822B8F14;
	sub_82130588(ctx, base);
loc_822B8F14:
	// li r29,0
	r29.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r29,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r29.u32);
	// sth r29,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r29.u16);
	// sth r29,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r29.u16);
	// stw r29,12(r30)
	PPC_STORE_U32(r30.u32 + 12, r29.u32);
	// stb r29,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r29.u8);
	// bl 0x82130588
	ctx.lr = 0x822B8F34;
	sub_82130588(ctx, base);
	// stw r29,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r29.u32);
loc_822B8F38:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b8bd0
	ctx.lr = 0x822B8F40;
	sub_822B8BD0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B8F48"))) PPC_WEAK_FUNC(sub_822B8F48);
PPC_FUNC_IMPL(__imp__sub_822B8F48) {
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
	// lis r11,-32212
	r11.s64 = -2111045632;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30688
	ctx.r4.s64 = r11.s64 + -30688;
	// addi r3,r10,-32108
	ctx.r3.s64 = ctx.r10.s64 + -32108;
	// bl 0x82554798
	ctx.lr = 0x822B8F68;
	sub_82554798(ctx, base);
	// lis r9,-32212
	ctx.r9.s64 = -2111045632;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30552
	ctx.r4.s64 = ctx.r9.s64 + -30552;
	// addi r3,r8,-32140
	ctx.r3.s64 = ctx.r8.s64 + -32140;
	// bl 0x82554798
	ctx.lr = 0x822B8F7C;
	sub_82554798(ctx, base);
	// lis r7,-32212
	ctx.r7.s64 = -2111045632;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-30536
	ctx.r4.s64 = ctx.r7.s64 + -30536;
	// addi r3,r6,-32180
	ctx.r3.s64 = ctx.r6.s64 + -32180;
	// bl 0x82554798
	ctx.lr = 0x822B8F90;
	sub_82554798(ctx, base);
	// lis r5,-32213
	ctx.r5.s64 = -2111111168;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,32640
	ctx.r4.s64 = ctx.r5.s64 + 32640;
	// addi r3,r3,-32216
	ctx.r3.s64 = ctx.r3.s64 + -32216;
	// bl 0x82554798
	ctx.lr = 0x822B8FA4;
	sub_82554798(ctx, base);
	// lis r11,-32237
	r11.s64 = -2112684032;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,0
	ctx.r4.s64 = r11.s64 + 0;
	// addi r3,r10,-32256
	ctx.r3.s64 = ctx.r10.s64 + -32256;
	// bl 0x82554798
	ctx.lr = 0x822B8FB8;
	sub_82554798(ctx, base);
	// lis r9,-32213
	ctx.r9.s64 = -2111111168;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,32656
	ctx.r4.s64 = ctx.r9.s64 + 32656;
	// addi r3,r8,-32288
	ctx.r3.s64 = ctx.r8.s64 + -32288;
	// bl 0x82554798
	ctx.lr = 0x822B8FCC;
	sub_82554798(ctx, base);
	// lis r7,-32213
	ctx.r7.s64 = -2111111168;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,32672
	ctx.r4.s64 = ctx.r7.s64 + 32672;
	// addi r3,r6,-32316
	ctx.r3.s64 = ctx.r6.s64 + -32316;
	// bl 0x82554798
	ctx.lr = 0x822B8FE0;
	sub_82554798(ctx, base);
	// lis r5,-32212
	ctx.r5.s64 = -2111045632;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-30520
	ctx.r4.s64 = ctx.r5.s64 + -30520;
	// addi r3,r3,-32356
	ctx.r3.s64 = ctx.r3.s64 + -32356;
	// bl 0x82554798
	ctx.lr = 0x822B8FF4;
	sub_82554798(ctx, base);
	// lis r11,-32213
	r11.s64 = -2111111168;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,32728
	ctx.r4.s64 = r11.s64 + 32728;
	// addi r3,r10,-32392
	ctx.r3.s64 = ctx.r10.s64 + -32392;
	// bl 0x82554798
	ctx.lr = 0x822B9008;
	sub_82554798(ctx, base);
	// lis r9,-32212
	ctx.r9.s64 = -2111045632;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-30496
	ctx.r4.s64 = ctx.r9.s64 + -30496;
	// addi r3,r8,-32432
	ctx.r3.s64 = ctx.r8.s64 + -32432;
	// bl 0x82554798
	ctx.lr = 0x822B901C;
	sub_82554798(ctx, base);
	// lis r7,-32212
	ctx.r7.s64 = -2111045632;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-29568
	ctx.r4.s64 = ctx.r7.s64 + -29568;
	// addi r3,r6,-32480
	ctx.r3.s64 = ctx.r6.s64 + -32480;
	// bl 0x82554798
	ctx.lr = 0x822B9030;
	sub_82554798(ctx, base);
	// lis r5,-32212
	ctx.r5.s64 = -2111045632;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-29464
	ctx.r4.s64 = ctx.r5.s64 + -29464;
	// addi r3,r3,-32540
	ctx.r3.s64 = ctx.r3.s64 + -32540;
	// bl 0x82554798
	ctx.lr = 0x822B9044;
	sub_82554798(ctx, base);
	// lis r11,-32212
	r11.s64 = -2111045632;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-30384
	ctx.r4.s64 = r11.s64 + -30384;
	// addi r3,r10,-32576
	ctx.r3.s64 = ctx.r10.s64 + -32576;
	// bl 0x82554798
	ctx.lr = 0x822B9058;
	sub_82554798(ctx, base);
	// lis r9,-32212
	ctx.r9.s64 = -2111045632;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-29352
	ctx.r4.s64 = ctx.r9.s64 + -29352;
	// addi r3,r8,-32612
	ctx.r3.s64 = ctx.r8.s64 + -32612;
	// bl 0x82554798
	ctx.lr = 0x822B906C;
	sub_82554798(ctx, base);
	// lis r7,-32171
	ctx.r7.s64 = -2108358656;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,17552
	ctx.r4.s64 = ctx.r7.s64 + 17552;
	// addi r3,r6,-32652
	ctx.r3.s64 = ctx.r6.s64 + -32652;
	// bl 0x82554798
	ctx.lr = 0x822B9080;
	sub_82554798(ctx, base);
	// lis r5,-32212
	ctx.r5.s64 = -2111045632;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-32760
	ctx.r4.s64 = ctx.r5.s64 + -32760;
	// addi r3,r3,-32684
	ctx.r3.s64 = ctx.r3.s64 + -32684;
	// bl 0x82554798
	ctx.lr = 0x822B9094;
	sub_82554798(ctx, base);
	// lis r11,-32212
	r11.s64 = -2111045632;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-32736
	ctx.r4.s64 = r11.s64 + -32736;
	// addi r3,r10,-32724
	ctx.r3.s64 = ctx.r10.s64 + -32724;
	// bl 0x82554798
	ctx.lr = 0x822B90A8;
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

__attribute__((alias("__imp__sub_822B90B8"))) PPC_WEAK_FUNC(sub_822B90B8);
PPC_FUNC_IMPL(__imp__sub_822B90B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823db9d4
	ctx.lr = 0x822B90C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
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
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lfs f12,-12736(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12736);
	ctx.f12.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f11,32692(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 32692);
	ctx.f11.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f10,-31640(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31640);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f9,12428(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12428);
	ctx.f9.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f8,-31376(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -31376);
	ctx.f8.f64 = double(temp.f32);
	// lfs f13,3732(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f7,27632(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27632);
	ctx.f7.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f6,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f6.f64 = double(temp.f32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lfs f5,14184(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14184);
	ctx.f5.f64 = double(temp.f32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f4,11368(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11368);
	ctx.f4.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f3,30712(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	ctx.f3.f64 = double(temp.f32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lfs f2,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	ctx.f2.f64 = double(temp.f32);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// lfs f1,-15468(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -15468);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,-31644(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -31644);
	f31.f64 = double(temp.f32);
	// lfs f30,14884(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 14884);
	f30.f64 = double(temp.f32);
	// lfs f29,-31648(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31648);
	f29.f64 = double(temp.f32);
	// lfs f28,-7912(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -7912);
	f28.f64 = double(temp.f32);
	// lfs f27,-31652(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -31652);
	f27.f64 = double(temp.f32);
	// stfs f0,0(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f12,4(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f11,8(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f10,12(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f9,16(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f8,20(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// stfs f13,24(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 24, temp.u32);
	// stfs f7,28(r3)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// stfs f6,32(r3)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// stfs f5,36(r3)
	temp.f32 = float(ctx.f5.f64);
	PPC_STORE_U32(ctx.r3.u32 + 36, temp.u32);
	// stfs f13,40(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// stfs f4,44(r3)
	temp.f32 = float(ctx.f4.f64);
	PPC_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// stfs f3,48(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 48, temp.u32);
	// stfs f2,52(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// stfs f1,56(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// stfs f31,60(r3)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r3.u32 + 60, temp.u32);
	// stfs f30,64(r3)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r3.u32 + 64, temp.u32);
	// stfs f0,68(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stfs f29,72(r3)
	temp.f32 = float(f29.f64);
	PPC_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// stfs f28,76(r3)
	temp.f32 = float(f28.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
	// stfs f27,80(r3)
	temp.f32 = float(f27.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// addi r12,r1,-8
	r12.s64 = ctx.r1.s64 + -8;
	// bl 0x823dba20
	ctx.lr = 0x822B91BC;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B91C8"))) PPC_WEAK_FUNC(sub_822B91C8);
PPC_FUNC_IMPL(__imp__sub_822B91C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,169(r3)
	PPC_STORE_U8(ctx.r3.u32 + 169, ctx.r10.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,152(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 152, temp.u32);
	// stfs f0,156(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 156, temp.u32);
	// stfs f0,160(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// stfs f0,164(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// b 0x82560bb0
	sub_82560BB0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B91EC"))) PPC_WEAK_FUNC(sub_822B91EC);
PPC_FUNC_IMPL(__imp__sub_822B91EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B91F0"))) PPC_WEAK_FUNC(sub_822B91F0);
PPC_FUNC_IMPL(__imp__sub_822B91F0) {
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
	// bl 0x82130000
	ctx.lr = 0x822B9208;
	sub_82130000(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r9,168(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 168);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// lfs f10,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f9.f64 = double(temp.f32);
	// bne cr6,0x822b9254
	if (!cr6.eq) goto loc_822B9254;
	// lbz r11,169(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 169);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b9254
	if (!cr6.eq) goto loc_822B9254;
	// lfs f0,152(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	f0.f64 = double(temp.f32);
	// lfs f13,156(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,160(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,164(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,24(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// stfs f13,12(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f12,16(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f11,20(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// b 0x822b93dc
	goto loc_822B93DC;
loc_822B9254:
	// lbz r11,148(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 148);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b9268
	if (cr6.eq) goto loc_822B9268;
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f9.f64;
	// b 0x822b926c
	goto loc_822B926C;
loc_822B9268:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f10.f64;
loc_822B926C:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lbz r10,169(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 169);
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lfs f13,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(f0.f64 * ctx.f13.f64));
	// beq cr6,0x822b9294
	if (cr6.eq) goto loc_822B9294;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f12,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f12.f64 = double(temp.f32);
	// b 0x822b9298
	goto loc_822B9298;
loc_822B9294:
	// fmr f12,f9
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f9.f64;
loc_822B9298:
	// lfs f8,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f0,152(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 152);
	f0.f64 = double(temp.f32);
	// fmr f13,f8
	ctx.f13.f64 = ctx.f8.f64;
	// fsubs f7,f8,f0
	ctx.f7.f64 = double(float(ctx.f8.f64 - f0.f64));
	// lfs f6,72(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 72);
	ctx.f6.f64 = double(temp.f32);
	// lfs f5,76(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 76);
	ctx.f5.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// fmuls f4,f7,f8
	ctx.f4.f64 = double(float(ctx.f7.f64 * ctx.f8.f64));
	// fsel f3,f4,f6,f5
	ctx.f3.f64 = ctx.f4.f64 >= 0.0 ? ctx.f6.f64 : ctx.f5.f64;
	// fmuls f12,f3,f12
	ctx.f12.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// bge cr6,0x822b92d8
	if (!cr6.lt) goto loc_822B92D8;
	// fmadds f12,f12,f11,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822b92f8
	if (!cr6.gt) goto loc_822B92F8;
	// b 0x822b92f4
	goto loc_822B92F4;
loc_822B92D8:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822b92f8
	if (!cr6.gt) goto loc_822B92F8;
	// lfs f13,24(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f12,f11,f13
	ctx.f12.f64 = double(float(-(ctx.f12.f64 * ctx.f11.f64 - ctx.f13.f64)));
	// stfs f12,24(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x822b92f8
	if (!cr6.lt) goto loc_822B92F8;
loc_822B92F4:
	// stfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 24, temp.u32);
loc_822B92F8:
	// lfs f0,156(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 156);
	f0.f64 = double(temp.f32);
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,92(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822b9320
	if (!cr6.lt) goto loc_822B9320;
	// fmadds f12,f12,f11,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822b9340
	if (!cr6.gt) goto loc_822B9340;
	// b 0x822b933c
	goto loc_822B933C;
loc_822B9320:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822b9340
	if (!cr6.gt) goto loc_822B9340;
	// lfs f13,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f12,f11,f13
	ctx.f12.f64 = double(float(-(ctx.f12.f64 * ctx.f11.f64 - ctx.f13.f64)));
	// stfs f12,12(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x822b9340
	if (!cr6.lt) goto loc_822B9340;
loc_822B933C:
	// stfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
loc_822B9340:
	// lfs f0,160(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 160);
	f0.f64 = double(temp.f32);
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 - ctx.f13.f64));
	// lfs f8,80(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 80);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,84(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 84);
	ctx.f7.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// fsel f12,f12,f8,f7
	ctx.f12.f64 = ctx.f12.f64 >= 0.0 ? ctx.f8.f64 : ctx.f7.f64;
	// bge cr6,0x822b9374
	if (!cr6.lt) goto loc_822B9374;
	// fmadds f12,f12,f11,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f12,16(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822b9394
	if (!cr6.gt) goto loc_822B9394;
	// b 0x822b9390
	goto loc_822B9390;
loc_822B9374:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822b9394
	if (!cr6.gt) goto loc_822B9394;
	// lfs f13,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f12,f11,f13
	ctx.f12.f64 = double(float(-(ctx.f12.f64 * ctx.f11.f64 - ctx.f13.f64)));
	// stfs f12,16(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x822b9394
	if (!cr6.lt) goto loc_822B9394;
loc_822B9390:
	// stfs f0,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
loc_822B9394:
	// lfs f0,164(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 164);
	f0.f64 = double(temp.f32);
	// lfs f13,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,88(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822b93bc
	if (!cr6.lt) goto loc_822B93BC;
	// fmadds f12,f12,f11,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64 + ctx.f13.f64));
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// ble cr6,0x822b93dc
	if (!cr6.gt) goto loc_822B93DC;
	// b 0x822b93d8
	goto loc_822B93D8;
loc_822B93BC:
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822b93dc
	if (!cr6.gt) goto loc_822B93DC;
	// lfs f13,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fnmsubs f12,f12,f11,f13
	ctx.f12.f64 = double(float(-(ctx.f12.f64 * ctx.f11.f64 - ctx.f13.f64)));
	// stfs f12,20(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
	// fcmpu cr6,f12,f0
	cr6.compare(ctx.f12.f64, f0.f64);
	// bge cr6,0x822b93dc
	if (!cr6.lt) goto loc_822B93DC;
loc_822B93D8:
	// stfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 20, temp.u32);
loc_822B93DC:
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x822b93ec
	if (!cr6.gt) goto loc_822B93EC;
	// stfs f10,16(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
loc_822B93EC:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 24);
	f0.f64 = double(temp.f32);
	// stfs f0,132(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 132, temp.u32);
	// lbz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b940c
	if (cr6.eq) goto loc_822B940C;
	// lfs f0,12(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// b 0x822b9410
	goto loc_822B9410;
loc_822B940C:
	// fmr f0,f10
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f10.f64;
loc_822B9410:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f0,136(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 136, temp.u32);
	// lbz r10,148(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 148);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822b942c
	if (cr6.eq) goto loc_822B942C;
	// lfs f0,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	f0.f64 = double(temp.f32);
	// b 0x822b9430
	goto loc_822B9430;
loc_822B942C:
	// fmr f0,f9
	ctx.fpscr.disableFlushMode();
	f0.f64 = ctx.f9.f64;
loc_822B9430:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// stfs f0,140(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 140, temp.u32);
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f0,20(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,144(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 144, temp.u32);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lfs f13,28(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,148(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 148, temp.u32);
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r8,592(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 592);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x822b9470
	if (!cr6.eq) goto loc_822B9470;
	// lhz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 44);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// extsh r4,r10
	ctx.r4.s64 = ctx.r10.s16;
	// bl 0x825617e8
	ctx.lr = 0x822B9470;
	sub_825617E8(ctx, base);
loc_822B9470:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,28,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b94b8
	if (cr6.eq) goto loc_822B94B8;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r11,664(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b94b8
	if (cr6.eq) goto loc_822B94B8;
	// bl 0x823eaef8
	ctx.lr = 0x822B9494;
	sub_823EAEF8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-31588
	ctx.r3.s64 = ctx.r10.s64 + -31588;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// bl 0x82130000
	ctx.lr = 0x822B94AC;
	sub_82130000(ctx, base);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r3,664(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 664);
	// bl 0x82345988
	ctx.lr = 0x822B94B8;
	sub_82345988(ctx, base);
loc_822B94B8:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b9500
	if (cr6.eq) goto loc_822B9500;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r11,668(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 668);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b9500
	if (cr6.eq) goto loc_822B9500;
	// bl 0x823eaef8
	ctx.lr = 0x822B94DC;
	sub_823EAEF8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r3,r10,-31636
	ctx.r3.s64 = ctx.r10.s64 + -31636;
	// lwz r11,132(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// addi r4,r11,8109
	ctx.r4.s64 = r11.s64 + 8109;
	// bl 0x82130000
	ctx.lr = 0x822B94F4;
	sub_82130000(ctx, base);
	// lwz r9,52(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lwz r3,668(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 668);
	// bl 0x823460a0
	ctx.lr = 0x822B9500;
	sub_823460A0(ctx, base);
loc_822B9500:
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// rlwinm r10,r11,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2000;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b9518
	if (cr6.eq) goto loc_822B9518;
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x8232d4b8
	ctx.lr = 0x822B9518;
	sub_8232D4B8(ctx, base);
loc_822B9518:
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

__attribute__((alias("__imp__sub_822B952C"))) PPC_WEAK_FUNC(sub_822B952C);
PPC_FUNC_IMPL(__imp__sub_822B952C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9530"))) PPC_WEAK_FUNC(sub_822B9530);
PPC_FUNC_IMPL(__imp__sub_822B9530) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82560be8
	ctx.lr = 0x822B9554;
	sub_82560BE8(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r3,r31,56
	ctx.r3.s64 = r31.s64 + 56;
	// addi r10,r11,-31540
	ctx.r10.s64 = r11.s64 + -31540;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822b90b8
	ctx.lr = 0x822B9568;
	sub_822B90B8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f12,116(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// li r11,1
	r11.s64 = 1;
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stw r5,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r5.u32);
	// lfs f13,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fadds f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfs f13,144(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// stb r11,148(r31)
	PPC_STORE_U8(r31.u32 + 148, r11.u8);
	// stfs f11,140(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 140, temp.u32);
	// stb r11,168(r31)
	PPC_STORE_U8(r31.u32 + 168, r11.u8);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// sth r7,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r7.u16);
	// stfs f0,156(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 156, temp.u32);
	// stb r6,169(r31)
	PPC_STORE_U8(r31.u32 + 169, ctx.r6.u8);
	// stfs f0,160(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 160, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// bl 0x82560bb0
	ctx.lr = 0x822B95C8;
	sub_82560BB0(ctx, base);
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

__attribute__((alias("__imp__sub_822B95E4"))) PPC_WEAK_FUNC(sub_822B95E4);
PPC_FUNC_IMPL(__imp__sub_822B95E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B95E8"))) PPC_WEAK_FUNC(sub_822B95E8);
PPC_FUNC_IMPL(__imp__sub_822B95E8) {
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
	// bl 0x82560ba0
	ctx.lr = 0x822B9608;
	sub_82560BA0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b9620
	if (cr6.eq) goto loc_822B9620;
	// bl 0x82130588
	ctx.lr = 0x822B961C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822B9620:
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

__attribute__((alias("__imp__sub_822B9638"))) PPC_WEAK_FUNC(sub_822B9638);
PPC_FUNC_IMPL(__imp__sub_822B9638) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,824(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 824);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x822b9650
	if (!cr6.eq) goto loc_822B9650;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_822B9650:
	// b 0x826fc510
	sub_826FC510(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B9654"))) PPC_WEAK_FUNC(sub_822B9654);
PPC_FUNC_IMPL(__imp__sub_822B9654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9658"))) PPC_WEAK_FUNC(sub_822B9658);
PPC_FUNC_IMPL(__imp__sub_822B9658) {
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
	// bl 0x826fc528
	ctx.lr = 0x822B9670;
	sub_826FC528(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,-31196
	ctx.r8.s64 = ctx.r9.s64 + -31196;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,11364(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// stfs f0,12(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 12, temp.u32);
	// stfs f0,16(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 16, temp.u32);
	// stfs f13,20(r31)
	temp.f32 = float(ctx.f13.f64);
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
}

__attribute__((alias("__imp__sub_822B96B0"))) PPC_WEAK_FUNC(sub_822B96B0);
PPC_FUNC_IMPL(__imp__sub_822B96B0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r3,r9,1
	ctx.r3.u64 = ctx.r9.u64 ^ 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B96C4"))) PPC_WEAK_FUNC(sub_822B96C4);
PPC_FUNC_IMPL(__imp__sub_822B96C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B96C8"))) PPC_WEAK_FUNC(sub_822B96C8);
PPC_FUNC_IMPL(__imp__sub_822B96C8) {
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
	// bl 0x826fc558
	ctx.lr = 0x822B96E0;
	sub_826FC558(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B96F4;
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

__attribute__((alias("__imp__sub_822B9708"))) PPC_WEAK_FUNC(sub_822B9708);
PPC_FUNC_IMPL(__imp__sub_822B9708) {
	PPC_FUNC_PROLOGUE();
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B970C"))) PPC_WEAK_FUNC(sub_822B970C);
PPC_FUNC_IMPL(__imp__sub_822B970C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9710"))) PPC_WEAK_FUNC(sub_822B9710);
PPC_FUNC_IMPL(__imp__sub_822B9710) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// lwz r7,144(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// lfs f0,20(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// stb r10,816(r5)
	PPC_STORE_U8(ctx.r5.u32 + 816, ctx.r10.u8);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,48(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stb r10,817(r11)
	PPC_STORE_U8(r11.u32 + 817, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B974C"))) PPC_WEAK_FUNC(sub_822B974C);
PPC_FUNC_IMPL(__imp__sub_822B974C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9750"))) PPC_WEAK_FUNC(sub_822B9750);
PPC_FUNC_IMPL(__imp__sub_822B9750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,20(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	f0.f64 = double(temp.f32);
	// li r11,0
	r11.s64 = 0;
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// lwz r7,144(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// stfs f0,20(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 20, temp.u32);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r5,48(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	// lwz r4,8(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stb r11,816(r4)
	PPC_STORE_U8(ctx.r4.u32 + 816, r11.u8);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stb r11,817(r9)
	PPC_STORE_U8(ctx.r9.u32 + 817, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B9790"))) PPC_WEAK_FUNC(sub_822B9790);
PPC_FUNC_IMPL(__imp__sub_822B9790) {
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
	// bl 0x826fc548
	ctx.lr = 0x822B97B0;
	sub_826FC548(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b97c8
	if (cr6.eq) goto loc_822B97C8;
	// bl 0x82130588
	ctx.lr = 0x822B97C4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822B97C8:
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

__attribute__((alias("__imp__sub_822B97E0"))) PPC_WEAK_FUNC(sub_822B97E0);
PPC_FUNC_IMPL(__imp__sub_822B97E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	PPCRegister f0{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x822B97E8;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823db9d4
	ctx.lr = 0x822B97F0;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
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
	// beq cr6,0x822b99e0
	if (cr6.eq) goto loc_822B99E0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b99e0
	if (cr6.eq) goto loc_822B99E0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f31,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmr f28,f31
	f28.f64 = f31.f64;
	// fmr f27,f31
	f27.f64 = f31.f64;
	// fmr f30,f31
	f30.f64 = f31.f64;
	// fmr f29,f31
	f29.f64 = f31.f64;
	// lwz r8,92(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 92);
	// lwz r28,8(r9)
	r28.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r7,144(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 144);
	// lwz r11,664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 664);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lfs f0,8(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	f0.f64 = double(temp.f32);
	// stfs f0,20(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + 20, temp.u32);
	// beq cr6,0x822b9870
	if (cr6.eq) goto loc_822B9870;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b9870
	if (cr6.eq) goto loc_822B9870;
	// lwz r11,664(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 664);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f28,28(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 28);
	f28.f64 = double(temp.f32);
	// lfs f27,8(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	f27.f64 = double(temp.f32);
loc_822B9870:
	// lwz r11,668(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 668);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b9898
	if (cr6.eq) goto loc_822B9898;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822b9898
	if (cr6.eq) goto loc_822B9898;
	// lwz r11,668(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 668);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lfs f30,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f30.f64 = double(temp.f32);
	// lfs f29,4(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	f29.f64 = double(temp.f32);
loc_822B9898:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stfs f31,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f31,164(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f31,172(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f0,168(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// lwz r10,20(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// extsh r27,r9
	r27.s64 = ctx.r9.s16;
	// cmpwi cr6,r27,2
	cr6.compare<int32_t>(r27.s32, 2, xer);
	// bgt cr6,0x822b98c8
	if (cr6.gt) goto loc_822B98C8;
	// li r27,2
	r27.s64 = 2;
loc_822B98C8:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwz r30,4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x822a8108
	ctx.lr = 0x822B98DC;
	sub_822A8108(ctx, base);
	// li r9,32
	ctx.r9.s64 = 32;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// lwz r7,4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r6,48(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// lwz r28,128(r28)
	r28.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x822b9928
	if (cr6.eq) goto loc_822B9928;
	// rotlwi r11,r7,0
	r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,96(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lfs f0,180(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 180);
	f0.f64 = double(temp.f32);
	// lfs f13,20(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f31,f0,f13
	f31.f64 = double(float(f0.f64 / ctx.f13.f64));
loc_822B9928:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r26,r1,172
	r26.s64 = ctx.r1.s64 + 172;
	// addi r25,r1,168
	r25.s64 = ctx.r1.s64 + 168;
	// addi r24,r1,164
	r24.s64 = ctx.r1.s64 + 164;
	// addi r23,r1,160
	r23.s64 = ctx.r1.s64 + 160;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r22,104(r11)
	r22.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// bl 0x822a8108
	ctx.lr = 0x822B9948;
	sub_822A8108(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// addi r20,r1,176
	r20.s64 = ctx.r1.s64 + 176;
	// addi r28,r28,272
	r28.s64 = r28.s64 + 272;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B9968;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// extsh r11,r27
	r11.s64 = r27.s16;
	// lfs f2,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	ctx.f2.f64 = double(temp.f32);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// fmr f7,f29
	ctx.f7.f64 = f29.f64;
	// addi r6,r11,-2
	ctx.r6.s64 = r11.s64 + -2;
	// fmr f6,f30
	ctx.f6.f64 = f30.f64;
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// fmr f5,f27
	ctx.f5.f64 = f27.f64;
	// lfs f0,-31128(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -31128);
	f0.f64 = double(temp.f32);
	// stw r20,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r20.u32);
	// fmuls f8,f1,f0
	ctx.f8.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f1,16(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// fmr f4,f28
	ctx.f4.f64 = f28.f64;
	// stw r21,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r21.u32);
	// fmr f3,f31
	ctx.f3.f64 = f31.f64;
	// stw r23,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r23.u32);
	// stw r24,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r24.u32);
	// stw r25,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, r25.u32);
	// stw r26,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r26.u32);
	// bl 0x8254a280
	ctx.lr = 0x822B99BC;
	sub_8254A280(ctx, base);
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	f0.f64 = double(temp.f32);
	// sth r27,44(r29)
	PPC_STORE_U16(r29.u32 + 44, r27.u16);
	// lfs f13,164(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,168(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,172(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,152(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 152, temp.u32);
	// stfs f13,156(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 156, temp.u32);
	// stfs f12,160(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 160, temp.u32);
	// stfs f11,164(r29)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r29.u32 + 164, temp.u32);
loc_822B99E0:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// addi r12,r1,-104
	r12.s64 = ctx.r1.s64 + -104;
	// bl 0x823dba20
	ctx.lr = 0x822B99EC;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_822B99F0"))) PPC_WEAK_FUNC(sub_822B99F0);
PPC_FUNC_IMPL(__imp__sub_822B99F0) {
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
	// lis r11,-32252
	r11.s64 = -2113667072;
	// addi r10,r11,-30812
	ctx.r10.s64 = r11.s64 + -30812;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b9a54
	if (cr6.eq) goto loc_822B9A54;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B9A2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822b9a4c
	if (cr6.eq) goto loc_822B9A4C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B9A4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822B9A4C:
	// li r11,0
	r11.s64 = 0;
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
loc_822B9A54:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fc6b8
	ctx.lr = 0x822B9A5C;
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

__attribute__((alias("__imp__sub_822B9A70"))) PPC_WEAK_FUNC(sub_822B9A70);
PPC_FUNC_IMPL(__imp__sub_822B9A70) {
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
	// bl 0x822b99f0
	ctx.lr = 0x822B9A90;
	sub_822B99F0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b9aa8
	if (cr6.eq) goto loc_822B9AA8;
	// bl 0x82130588
	ctx.lr = 0x822B9AA4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822B9AA8:
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

__attribute__((alias("__imp__sub_822B9AC0"))) PPC_WEAK_FUNC(sub_822B9AC0);
PPC_FUNC_IMPL(__imp__sub_822B9AC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x822B9AC8;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b9b54
	if (!cr6.eq) goto loc_822B9B54;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b9b54
	if (cr6.eq) goto loc_822B9B54;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,984(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 984);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B9B14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b9b54
	if (cr6.eq) goto loc_822B9B54;
	// lwz r11,80(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// lwz r3,128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822B9B38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822b9b54
	if (cr6.eq) goto loc_822B9B54;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lfs f1,-31384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -31384);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b9e58
	ctx.lr = 0x822B9B54;
	sub_822B9E58(ctx, base);
loc_822B9B54:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822aceb8
	ctx.lr = 0x822B9B68;
	sub_822ACEB8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B9B74"))) PPC_WEAK_FUNC(sub_822B9B74);
PPC_FUNC_IMPL(__imp__sub_822B9B74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9B78"))) PPC_WEAK_FUNC(sub_822B9B78);
PPC_FUNC_IMPL(__imp__sub_822B9B78) {
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
	// addi r3,r31,20
	ctx.r3.s64 = r31.s64 + 20;
	// addi r10,r11,22868
	ctx.r10.s64 = r11.s64 + 22868;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x822a5a70
	ctx.lr = 0x822B9BA8;
	sub_822A5A70(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r9,22740
	ctx.r7.s64 = ctx.r9.s64 + 22740;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// bl 0x82740ec0
	ctx.lr = 0x822B9BC4;
	sub_82740EC0(ctx, base);
	// clrlwi r6,r30,31
	ctx.r6.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822b9bdc
	if (cr6.eq) goto loc_822B9BDC;
	// bl 0x82130588
	ctx.lr = 0x822B9BD8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_822B9BDC:
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

__attribute__((alias("__imp__sub_822B9BF4"))) PPC_WEAK_FUNC(sub_822B9BF4);
PPC_FUNC_IMPL(__imp__sub_822B9BF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9BF8"))) PPC_WEAK_FUNC(sub_822B9BF8);
PPC_FUNC_IMPL(__imp__sub_822B9BF8) {
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
	// bl 0x826fc678
	ctx.lr = 0x822B9C14;
	sub_826FC678(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r3,316
	ctx.r3.s64 = 316;
	// addi r10,r11,-30812
	ctx.r10.s64 = r11.s64 + -30812;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// bl 0x82130528
	ctx.lr = 0x822B9C28;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822b9c58
	if (cr6.eq) goto loc_822B9C58;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x822a6460
	ctx.lr = 0x822B9C3C;
	sub_822A6460(ctx, base);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-30612
	ctx.r9.s64 = r11.s64 + -30612;
	// stw r10,312(r31)
	PPC_STORE_U32(r31.u32 + 312, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// b 0x822b9c5c
	goto loc_822B9C5C;
loc_822B9C58:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822B9C5C:
	// stw r3,56(r30)
	PPC_STORE_U32(r30.u32 + 56, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822B9C70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,56(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r30,312(r9)
	PPC_STORE_U32(ctx.r9.u32 + 312, r30.u32);
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

__attribute__((alias("__imp__sub_822B9C94"))) PPC_WEAK_FUNC(sub_822B9C94);
PPC_FUNC_IMPL(__imp__sub_822B9C94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9C98"))) PPC_WEAK_FUNC(sub_822B9C98);
PPC_FUNC_IMPL(__imp__sub_822B9C98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r11,r8,1
	r11.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,-1
	ctx.r4.s64 = -1;
	// stb r11,467(r3)
	PPC_STORE_U8(ctx.r3.u32 + 467, r11.u8);
	// b 0x82683820
	sub_82683820(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B9CC4"))) PPC_WEAK_FUNC(sub_822B9CC4);
PPC_FUNC_IMPL(__imp__sub_822B9CC4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B9CC8"))) PPC_WEAK_FUNC(sub_822B9CC8);
PPC_FUNC_IMPL(__imp__sub_822B9CC8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r10,r8,1
	ctx.r10.u64 = ctx.r8.u64 ^ 1;
	// beqlr cr6
	if (cr6.eq) return;
	// stb r10,468(r11)
	PPC_STORE_U8(r11.u32 + 468, ctx.r10.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B9CF0"))) PPC_WEAK_FUNC(sub_822B9CF0);
PPC_FUNC_IMPL(__imp__sub_822B9CF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822b9d14
	if (cr6.eq) goto loc_822B9D14;
	// lbz r11,468(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 468);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822B9D14:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B9D28"))) PPC_WEAK_FUNC(sub_822B9D28);
PPC_FUNC_IMPL(__imp__sub_822B9D28) {
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
	// lis r11,-32198
	r11.s64 = -2110128128;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r4,r11,-12200
	ctx.r4.s64 = r11.s64 + -12200;
	// addi r3,r10,-30456
	ctx.r3.s64 = ctx.r10.s64 + -30456;
	// bl 0x82554798
	ctx.lr = 0x822B9D48;
	sub_82554798(ctx, base);
	// lis r9,-32212
	ctx.r9.s64 = -2111045632;
	// lis r8,-32252
	ctx.r8.s64 = -2113667072;
	// addi r4,r9,-25448
	ctx.r4.s64 = ctx.r9.s64 + -25448;
	// addi r3,r8,-30488
	ctx.r3.s64 = ctx.r8.s64 + -30488;
	// bl 0x82554798
	ctx.lr = 0x822B9D5C;
	sub_82554798(ctx, base);
	// lis r7,-32212
	ctx.r7.s64 = -2111045632;
	// lis r6,-32252
	ctx.r6.s64 = -2113667072;
	// addi r4,r7,-25400
	ctx.r4.s64 = ctx.r7.s64 + -25400;
	// addi r3,r6,-30520
	ctx.r3.s64 = ctx.r6.s64 + -30520;
	// bl 0x82554798
	ctx.lr = 0x822B9D70;
	sub_82554798(ctx, base);
	// lis r5,-32212
	ctx.r5.s64 = -2111045632;
	// lis r3,-32252
	ctx.r3.s64 = -2113667072;
	// addi r4,r5,-25360
	ctx.r4.s64 = ctx.r5.s64 + -25360;
	// addi r3,r3,-30552
	ctx.r3.s64 = ctx.r3.s64 + -30552;
	// bl 0x82554798
	ctx.lr = 0x822B9D84;
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

__attribute__((alias("__imp__sub_822B9D94"))) PPC_WEAK_FUNC(sub_822B9D94);
PPC_FUNC_IMPL(__imp__sub_822B9D94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9D98"))) PPC_WEAK_FUNC(sub_822B9D98);
PPC_FUNC_IMPL(__imp__sub_822B9D98) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,984(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 984);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bne cr6,0x822b9db0
	if (!cr6.eq) goto loc_822B9DB0;
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
loc_822B9DB0:
	// b 0x826fcd48
	sub_826FCD48(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822B9DB4"))) PPC_WEAK_FUNC(sub_822B9DB4);
PPC_FUNC_IMPL(__imp__sub_822B9DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9DB8"))) PPC_WEAK_FUNC(sub_822B9DB8);
PPC_FUNC_IMPL(__imp__sub_822B9DB8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b9df0
	if (cr6.eq) goto loc_822B9DF0;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x822b9df0
	if (cr6.eq) goto loc_822B9DF0;
	// rlwinm r11,r11,0,26,30
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x3E;
	// rlwinm r11,r11,0,30,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822b9df0
	if (!cr6.eq) goto loc_822B9DF0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,27640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 27640);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
loc_822B9DF0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B9DFC"))) PPC_WEAK_FUNC(sub_822B9DFC);
PPC_FUNC_IMPL(__imp__sub_822B9DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822B9E00"))) PPC_WEAK_FUNC(sub_822B9E00);
PPC_FUNC_IMPL(__imp__sub_822B9E00) {
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
	ctx.lr = 0x822B9E08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r31,308
	ctx.r10.s64 = r31.s64 + 308;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// lwz r11,164(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x822b9e40
	if (!cr6.eq) goto loc_822B9E40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826fd730
	ctx.lr = 0x822B9E30;
	sub_826FD730(ctx, base);
	// stw r3,316(r31)
	PPC_STORE_U32(r31.u32 + 316, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826fd730
	ctx.lr = 0x822B9E3C;
	sub_826FD730(ctx, base);
	// stw r3,320(r31)
	PPC_STORE_U32(r31.u32 + 320, ctx.r3.u32);
loc_822B9E40:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826fd410
	ctx.lr = 0x822B9E50;
	sub_826FD410(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822B9E58"))) PPC_WEAK_FUNC(sub_822B9E58);
PPC_FUNC_IMPL(__imp__sub_822B9E58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,296(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822B9E60"))) PPC_WEAK_FUNC(sub_822B9E60);
PPC_FUNC_IMPL(__imp__sub_822B9E60) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822b9e94
	if (cr6.eq) goto loc_822B9E94;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r8,96(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lfs f0,180(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 180);
	f0.f64 = double(temp.f32);
	// lfs f13,20(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f1,f0,f13
	ctx.f1.f64 = double(float(f0.f64 / ctx.f13.f64));
	// blr 
	return;
loc_822B9E94:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

