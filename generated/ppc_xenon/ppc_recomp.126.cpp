#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8262A0E8"))) PPC_WEAK_FUNC(sub_8262A0E8);
PPC_FUNC_IMPL(__imp__sub_8262A0E8) {
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
	ctx.lr = 0x8262A0F0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8262A10C;
	sub_8238EC00(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x823895f8
	ctx.lr = 0x8262A11C;
	sub_823895F8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82389800
	ctx.lr = 0x8262A128;
	sub_82389800(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262a160
	if (cr6.eq) goto loc_8262A160;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82389800
	ctx.lr = 0x8262A13C;
	sub_82389800(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// addi r10,r11,-2
	ctx.r10.s64 = r11.s64 + -2;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r5,r9,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x8262a058
	ctx.lr = 0x8262A160;
	sub_8262A058(ctx, base);
loc_8262A160:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262A168"))) PPC_WEAK_FUNC(sub_8262A168);
PPC_FUNC_IMPL(__imp__sub_8262A168) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d8
	ctx.lr = 0x8262A170;
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r23,-32114
	r23.s64 = -2104623104;
	// addi r10,r11,-6208
	ctx.r10.s64 = r11.s64 + -6208;
	// lis r22,-32114
	r22.s64 = -2104623104;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r21,-22860(r23)
	r21.u64 = PPC_LOAD_U32(r23.u32 + -22860);
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r20,-22856(r22)
	r20.u64 = PPC_LOAD_U32(r22.u32 + -22856);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262a1a8
	if (cr6.eq) goto loc_8262A1A8;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r5,r11,-17832
	ctx.r5.s64 = r11.s64 + -17832;
	// b 0x8262a1b0
	goto loc_8262A1B0;
loc_8262A1A8:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r5,r11,-17856
	ctx.r5.s64 = r11.s64 + -17856;
loc_8262A1B0:
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x8262A1BC;
	sub_82137A08(ctx, base);
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x8262A1D0;
	sub_821CA540(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-11956
	ctx.r4.s64 = ctx.r10.s64 + -11956;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x823db730
	ctx.lr = 0x8262A1E4;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8262a204
	if (!cr6.eq) goto loc_8262A204;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-17864
	ctx.r4.s64 = r11.s64 + -17864;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r28,80
	ctx.r3.s64 = r28.s64 + 80;
	// bl 0x8224c378
	ctx.lr = 0x8262A204;
	sub_8224C378(ctx, base);
loc_8262A204:
	// lwz r11,88(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262a228
	if (!cr6.eq) goto loc_8262A228;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r11,-19368
	ctx.r4.s64 = r11.s64 + -19368;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r28,80
	ctx.r3.s64 = r28.s64 + 80;
	// bl 0x8224c378
	ctx.lr = 0x8262A228;
	sub_8224C378(ctx, base);
loc_8262A228:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x8262A230;
	sub_821C9A90(ctx, base);
	// lwz r11,88(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 88);
	// addi r27,r28,80
	r27.s64 = r28.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262a248
	if (cr6.eq) goto loc_8262A248;
	// lwz r24,228(r11)
	r24.u64 = PPC_LOAD_U32(r11.u32 + 228);
	// b 0x8262a24c
	goto loc_8262A24C;
loc_8262A248:
	// li r24,0
	r24.s64 = 0;
loc_8262A24C:
	// li r25,0
	r25.s64 = 0;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// ble cr6,0x8262a3c4
	if (!cr6.gt) goto loc_8262A3C4;
	// lis r26,-32121
	r26.s64 = -2105081856;
loc_8262A25C:
	// lwz r11,8(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 8);
	// lwz r10,172(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// lwz r11,116(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 116);
	// mullw r10,r10,r25
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(r25.s32);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8262a3b8
	if (cr6.eq) goto loc_8262A3B8;
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// addi r29,r28,264
	r29.s64 = r28.s64 + 264;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825edac0
	ctx.lr = 0x8262A294;
	sub_825EDAC0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262a2f4
	if (cr6.eq) goto loc_8262A2F4;
	// lwz r29,0(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r31,r29,68
	r31.s64 = r29.s64 + 68;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262e420
	ctx.lr = 0x8262A2B0;
	sub_8262E420(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x8262a2cc
	if (!cr6.eq) goto loc_8262A2CC;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8262A2CC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,144(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,33
	cr6.compare<uint32_t>(ctx.r9.u32, 33, xer);
	// bne cr6,0x8262a2ec
	if (!cr6.eq) goto loc_8262A2EC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_8262A2EC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// b 0x8262a3b0
	goto loc_8262A3B0;
loc_8262A2F4:
	// li r3,192
	ctx.r3.s64 = 192;
	// bl 0x82130528
	ctx.lr = 0x8262A2FC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262a310
	if (cr6.eq) goto loc_8262A310;
	// bl 0x82628b58
	ctx.lr = 0x8262A308;
	sub_82628B58(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8262a314
	goto loc_8262A314;
loc_8262A310:
	// li r31,0
	r31.s64 = 0;
loc_8262A314:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lwz r10,288(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 288);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262A32C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,144(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 144);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,6
	ctx.r9.s64 = r11.s64 + 6;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r9,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82627a70
	ctx.lr = 0x8262A348;
	sub_82627A70(ctx, base);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r7,368(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 368);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262A360;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r31,68
	r29.s64 = r31.s64 + 68;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8262A370;
	sub_8262E420(ctx, base);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x8262a38c
	if (!cr6.eq) goto loc_8262A38C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8262A38C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,144(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,33
	cr6.compare<uint32_t>(ctx.r9.u32, 33, xer);
	// bne cr6,0x8262a3ac
	if (!cr6.eq) goto loc_8262A3AC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_8262A3AC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262A3B0:
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// bl 0x82691cb0
	ctx.lr = 0x8262A3B8;
	sub_82691CB0(ctx, base);
loc_8262A3B8:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// cmpw cr6,r25,r24
	cr6.compare<int32_t>(r25.s32, r24.s32, xer);
	// blt cr6,0x8262a25c
	if (cr6.lt) goto loc_8262A25C;
loc_8262A3C4:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r21,-22860(r23)
	PPC_STORE_U32(r23.u32 + -22860, r21.u32);
	// li r11,1
	r11.s64 = 1;
	// stw r20,-22856(r22)
	PPC_STORE_U32(r22.u32 + -22856, r20.u32);
	// stb r11,28(r27)
	PPC_STORE_U8(r27.u32 + 28, r11.u8);
	// stb r11,38(r27)
	PPC_STORE_U8(r27.u32 + 38, r11.u8);
	// lfs f0,29500(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 29500);
	f0.f64 = double(temp.f32);
	// stb r11,44(r27)
	PPC_STORE_U8(r27.u32 + 44, r11.u8);
	// stb r11,58(r27)
	PPC_STORE_U8(r27.u32 + 58, r11.u8);
	// stb r11,57(r27)
	PPC_STORE_U8(r27.u32 + 57, r11.u8);
	// stfs f0,144(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 144, temp.u32);
	// stb r11,256(r28)
	PPC_STORE_U8(r28.u32 + 256, r11.u8);
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// b 0x823d9228
	return;
}

__attribute__((alias("__imp__sub_8262A3FC"))) PPC_WEAK_FUNC(sub_8262A3FC);
PPC_FUNC_IMPL(__imp__sub_8262A3FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262A400"))) PPC_WEAK_FUNC(sub_8262A400);
PPC_FUNC_IMPL(__imp__sub_8262A400) {
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
	ctx.lr = 0x8262A408;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r29,r31,128
	r29.s64 = r31.s64 + 128;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82624860
	ctx.lr = 0x8262A424;
	sub_82624860(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// stb r3,176(r31)
	PPC_STORE_U8(r31.u32 + 176, ctx.r3.u8);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262a568
	if (cr6.eq) goto loc_8262A568;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262A448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262a4a0
	if (cr6.eq) goto loc_8262A4A0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262A468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262a4ac
	if (cr6.eq) goto loc_8262A4AC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,156(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// bl 0x82621d50
	ctx.lr = 0x8262A480;
	sub_82621D50(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8262a4a0
	if (cr6.eq) goto loc_8262A4A0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,156(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// bl 0x82627648
	ctx.lr = 0x8262A494;
	sub_82627648(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262a4ac
	if (cr6.eq) goto loc_8262A4AC;
loc_8262A4A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82628c48
	ctx.lr = 0x8262A4A8;
	sub_82628C48(ctx, base);
	// stw r3,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r3.u32);
loc_8262A4AC:
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262a570
	if (cr6.eq) goto loc_8262A570;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262A4C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,156(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,52(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 52);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262A4E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v60,v61,v61
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_load_si128((simde__m128i*)v61.u8));
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,156(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 156);
	// lfs f0,14884(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 14884);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvlx128 v59,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v13,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0xFF));
	// vsubfp128 v12,v60,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_sub_ps(simde_mm_load_ps(v60.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v11,v12,v13,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// stvx128 v11,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82621a78
	ctx.lr = 0x8262A530;
	sub_82621A78(ctx, base);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f1,144(r31)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x8262a554
	if (!cr6.eq) goto loc_8262A554;
	// lfs f0,136(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 136);
	f0.f64 = double(temp.f32);
	// lfs f13,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// beq cr6,0x8262a570
	if (cr6.eq) goto loc_8262A570;
loc_8262A554:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,152(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 152, temp.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_8262A568:
	// li r11,0
	r11.s64 = 0;
	// stw r11,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r11.u32);
loc_8262A570:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262A578"))) PPC_WEAK_FUNC(sub_8262A578);
PPC_FUNC_IMPL(__imp__sub_8262A578) {
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
	// bl 0x82637a40
	ctx.lr = 0x8262A590;
	sub_82637A40(ctx, base);
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,144(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// addi r11,r11,6
	r11.s64 = r11.s64 + 6;
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r9,33
	cr6.compare<uint32_t>(ctx.r9.u32, 33, xer);
	// bne cr6,0x8262a5b0
	if (!cr6.eq) goto loc_8262A5B0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_8262A5B0:
	// lwz r3,160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r4,164(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 164);
	// mr r6,r11
	ctx.r6.u64 = r11.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f1,-2580(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -2580);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262A5D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f1,172(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 172, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262a400
	ctx.lr = 0x8262A5E0;
	sub_8262A400(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262A5F4"))) PPC_WEAK_FUNC(sub_8262A5F4);
PPC_FUNC_IMPL(__imp__sub_8262A5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262A5F8"))) PPC_WEAK_FUNC(sub_8262A5F8);
PPC_FUNC_IMPL(__imp__sub_8262A5F8) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// addi r31,r3,80
	r31.s64 = ctx.r3.s64 + 80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 224, r11.u32);
	// beq cr6,0x8262a634
	if (cr6.eq) goto loc_8262A634;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r4,r31,128
	ctx.r4.s64 = r31.s64 + 128;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262A634;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262A634:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262A648;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// li r9,0
	ctx.r9.s64 = 0;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-10220(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10220);
	// rlwinm r7,r5,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x826290c0
	ctx.lr = 0x8262A674;
	sub_826290C0(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262A688"))) PPC_WEAK_FUNC(sub_8262A688);
PPC_FUNC_IMPL(__imp__sub_8262A688) {
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
	PPCRegister f27{};
	PPCRegister f28{};
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
	// bl 0x823d91e4
	ctx.lr = 0x8262A690;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823db9d4
	ctx.lr = 0x8262A698;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	f27.f64 = ctx.f1.f64;
	// li r23,0
	r23.s64 = 0;
	// mr r26,r23
	r26.u64 = r23.u64;
	// lbz r11,1427(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1427);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262a9dc
	if (cr6.eq) goto loc_8262A9DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x8262A6C0;
	sub_82388598(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// addi r25,r31,448
	r25.s64 = r31.s64 + 448;
	// addi r24,r31,464
	r24.s64 = r31.s64 + 464;
	// add r28,r10,r11
	r28.u64 = ctx.r10.u64 + r11.u64;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stvx128 v63,r0,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lbz r5,18(r28)
	ctx.r5.u64 = PPC_LOAD_U8(r28.u32 + 18);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// lfs f12,-28876(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -28876);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,1068(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 1068);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,7444(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// frsp f9,f13
	ctx.f9.f64 = double(float(ctx.f13.f64));
	// lfs f13,14192(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f8,f9,f12
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// fmuls f0,f8,f11
	f0.f64 = double(float(ctx.f8.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8262a72c
	if (!cr6.lt) goto loc_8262A72C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x8262a738
	goto loc_8262A738;
loc_8262A72C:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x8262a738
	if (!cr6.gt) goto loc_8262A738;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
loc_8262A738:
	// stfs f0,1464(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1464, temp.u32);
	// lbz r10,19(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 19);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// addi r30,r31,1464
	r30.s64 = r31.s64 + 1464;
	// lfd f0,80(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f0
	ctx.f9.f64 = double(f0.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// fmuls f0,f7,f11
	f0.f64 = double(float(ctx.f7.f64 * ctx.f11.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8262a76c
	if (!cr6.lt) goto loc_8262A76C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x8262a778
	goto loc_8262A778;
loc_8262A76C:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x8262a778
	if (!cr6.gt) goto loc_8262A778;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
loc_8262A778:
	// stfs f0,1468(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1468, temp.u32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r29,r31,1468
	r29.s64 = r31.s64 + 1468;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f28,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	f28.f64 = double(temp.f32);
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// bl 0x8260c6d8
	ctx.lr = 0x8262A79C;
	sub_8260C6D8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r27,1
	r27.s64 = 1;
	// lfs f29,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fcmpu cr6,f1,f29
	cr6.compare(ctx.f1.f64, f29.f64);
	// ble cr6,0x8262a838
	if (!cr6.gt) goto loc_8262A838;
	// lfs f0,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x8262a7c0
	if (!cr6.lt) goto loc_8262A7C0;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_8262A7C0:
	// lfs f31,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// bge cr6,0x8262a7d0
	if (!cr6.lt) goto loc_8262A7D0;
	// fneg f31,f31
	f31.u64 = f31.u64 ^ 0x8000000000000000;
loc_8262A7D0:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// bl 0x82227c70
	ctx.lr = 0x8262A7D8;
	sub_82227C70(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82227c70
	ctx.lr = 0x8262A7E4;
	sub_82227C70(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x8262a7fc
	if (!cr6.lt) goto loc_8262A7FC;
	// fneg f0,f30
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// b 0x8262a800
	goto loc_8262A800;
loc_8262A7FC:
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
loc_8262A800:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x8262a818
	if (!cr6.lt) goto loc_8262A818;
	// fneg f0,f1
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// b 0x8262a81c
	goto loc_8262A81C;
loc_8262A818:
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_8262A81C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261fce8
	ctx.lr = 0x8262A824;
	sub_8261FCE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// bl 0x82629910
	ctx.lr = 0x8262A830;
	sub_82629910(ctx, base);
	// mr r26,r27
	r26.u64 = r27.u64;
	// stb r27,630(r31)
	PPC_STORE_U8(r31.u32 + 630, r27.u8);
loc_8262A838:
	// lbz r11,496(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 496);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262a9ac
	if (cr6.eq) goto loc_8262A9AC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r30,r31,1456
	r30.s64 = r31.s64 + 1456;
	// bl 0x8221cba0
	ctx.lr = 0x8262A850;
	sub_8221CBA0(ctx, base);
	// stfs f1,1456(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1456, temp.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r29,r31,1460
	r29.s64 = r31.s64 + 1460;
	// bl 0x8221cbf8
	ctx.lr = 0x8262A860;
	sub_8221CBF8(ctx, base);
	// stfs f1,1460(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1460, temp.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// fmr f1,f28
	ctx.f1.f64 = f28.f64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8260c6d8
	ctx.lr = 0x8262A878;
	sub_8260C6D8(ctx, base);
	// fcmpu cr6,f1,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f29.f64);
	// ble cr6,0x8262a90c
	if (!cr6.gt) goto loc_8262A90C;
	// lfs f0,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x8262a890
	if (!cr6.lt) goto loc_8262A890;
	// fneg f0,f0
	f0.u64 = f0.u64 ^ 0x8000000000000000;
loc_8262A890:
	// lfs f31,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// bge cr6,0x8262a8a0
	if (!cr6.lt) goto loc_8262A8A0;
	// fneg f31,f31
	f31.u64 = f31.u64 ^ 0x8000000000000000;
loc_8262A8A0:
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f0.f64;
	// bl 0x82227c70
	ctx.lr = 0x8262A8A8;
	sub_82227C70(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82227c70
	ctx.lr = 0x8262A8B4;
	sub_82227C70(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x8262a8cc
	if (!cr6.lt) goto loc_8262A8CC;
	// fneg f0,f30
	f0.u64 = f30.u64 ^ 0x8000000000000000;
	// stfs f0,0(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// b 0x8262a8d0
	goto loc_8262A8D0;
loc_8262A8CC:
	// stfs f30,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
loc_8262A8D0:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	cr6.compare(f0.f64, f29.f64);
	// bge cr6,0x8262a8e8
	if (!cr6.lt) goto loc_8262A8E8;
	// fneg f0,f1
	f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,0(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
	// b 0x8262a8ec
	goto loc_8262A8EC;
loc_8262A8E8:
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r29.u32 + 0, temp.u32);
loc_8262A8EC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261fce8
	ctx.lr = 0x8262A8F4;
	sub_8261FCE8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f27.f64;
	// bl 0x82629ba0
	ctx.lr = 0x8262A900;
	sub_82629BA0(ctx, base);
	// mr r26,r27
	r26.u64 = r27.u64;
	// stb r27,630(r31)
	PPC_STORE_U8(r31.u32 + 630, r27.u8);
	// b 0x8262a95c
	goto loc_8262A95C;
loc_8262A90C:
	// bl 0x82387a18
	ctx.lr = 0x8262A910;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262a95c
	if (cr6.eq) goto loc_8262A95C;
	// lbz r11,629(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262a95c
	if (cr6.eq) goto loc_8262A95C;
	// lwz r3,600(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262a95c
	if (cr6.eq) goto loc_8262A95C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262A944;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f3,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826263c0
	ctx.lr = 0x8262A95C;
	sub_826263C0(ctx, base);
loc_8262A95C:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lvx128 v62,r0,r24
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r25
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,2384
	ctx.r10.s64 = r11.s64 + 2384;
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v59,v61,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v58,v59,v60
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v58.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v58.f32), 0xF);
	// mfocrf r9,2
	ctx.r9.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8262a9a4
	if (!cr6.eq) goto loc_8262A9A4;
	// lfs f2,0(r29)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8262c120
	ctx.lr = 0x8262A99C;
	sub_8262C120(ctx, base);
	// stb r27,1472(r31)
	PPC_STORE_U8(r31.u32 + 1472, r27.u8);
	// b 0x8262a9ac
	goto loc_8262A9AC;
loc_8262A9A4:
	// bl 0x8262bfa8
	ctx.lr = 0x8262A9A8;
	sub_8262BFA8(ctx, base);
	// stb r23,1472(r31)
	PPC_STORE_U8(r31.u32 + 1472, r23.u8);
loc_8262A9AC:
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262a9e8
	if (!cr6.eq) goto loc_8262A9E8;
	// lbz r11,630(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 630);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262a9e8
	if (cr6.eq) goto loc_8262A9E8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826281e8
	ctx.lr = 0x8262A9CC;
	sub_826281E8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba20
	ctx.lr = 0x8262A9D8;
	// b 0x823d9234
	return;
loc_8262A9DC:
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8262bfa8
	ctx.lr = 0x8262A9E4;
	sub_8262BFA8(ctx, base);
	// stb r23,1472(r31)
	PPC_STORE_U8(r31.u32 + 1472, r23.u8);
loc_8262A9E8:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-80
	r12.s64 = ctx.r1.s64 + -80;
	// bl 0x823dba20
	ctx.lr = 0x8262A9F4;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8262A9F8"))) PPC_WEAK_FUNC(sub_8262A9F8);
PPC_FUNC_IMPL(__imp__sub_8262A9F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	ctx.lr = 0x8262AA00;
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823db9cc
	ctx.lr = 0x8262AA08;
	// li r12,-112
	r12.s64 = -112;
	// stvx128 v127,r1,r12
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r1.u32 + r12.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// fmr f25,f1
	ctx.fpscr.disableFlushMode();
	f25.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,1104
	ctx.r10.s64 = 1104;
	// li r9,848
	ctx.r9.s64 = 848;
	// addi r8,r11,2384
	ctx.r8.s64 = r11.s64 + 2384;
	// lvx128 v62,r31,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r31,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v60,v62,v63
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vand128 v59,v61,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vcmpeqfp128. v58,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v58.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	cr6.setFromMask(simde_mm_load_ps(v58.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r6,r7,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// li r30,0
	r30.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8262aa64
	if (!cr6.eq) goto loc_8262AA64;
	// stb r29,1121(r31)
	PPC_STORE_U8(r31.u32 + 1121, r29.u8);
	// b 0x8262aa68
	goto loc_8262AA68;
loc_8262AA64:
	// stb r30,1121(r31)
	PPC_STORE_U8(r31.u32 + 1121, r30.u8);
loc_8262AA68:
	// addi r11,r31,1056
	r11.s64 = r31.s64 + 1056;
	// addi r10,r31,800
	ctx.r10.s64 = r31.s64 + 800;
	// li r7,16
	ctx.r7.s64 = 16;
	// li r8,32
	ctx.r8.s64 = 32;
	// li r9,48
	ctx.r9.s64 = 48;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r7
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r11,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r10,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r11,r9
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,396(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 396);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262aac0
	if (cr6.eq) goto loc_8262AAC0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262AABC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r30,396(r31)
	PPC_STORE_U8(r31.u32 + 396, r30.u8);
loc_8262AAC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// bl 0x826355a8
	ctx.lr = 0x8262AACC;
	sub_826355A8(ctx, base);
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262ac58
	if (cr6.eq) goto loc_8262AC58;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262AAE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262abac
	if (cr6.eq) goto loc_8262ABAC;
	// vspltisw128 v53,0
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v53,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,728(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 728);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262AB18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// lfs f13,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,640(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 640);
	// lfs f0,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f31,f13,f13,f11
	f31.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262AB44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1512(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,644(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 644);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8262AB64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fsqrts f10,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(sqrt(f31.f64)));
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lvx128 v52,r0,r10
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v51,v52,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v51.f32, simde_mm_sub_ps(simde_mm_load_ps(v52.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v51,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f9,f0,f0
	ctx.f9.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f8,f13,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f7,f12,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fdivs f1,f10,f6
	ctx.f1.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// bl 0x8262c1e0
	ctx.lr = 0x8262ABA4;
	sub_8262C1E0(ctx, base);
	// stb r29,396(r31)
	PPC_STORE_U8(r31.u32 + 396, r29.u8);
	// b 0x8262ac58
	goto loc_8262AC58;
loc_8262ABAC:
	// vspltisw128 v50,0
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,96
	r11.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v50,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,728(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 728);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262ABCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// fmuls f12,f0,f0
	ctx.f12.f64 = double(float(f0.f64 * f0.f64));
	// lwz r3,1512(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,640(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 640);
	// lfs f0,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f0.f64 = double(temp.f32);
	// fmadds f11,f0,f0,f12
	ctx.f11.f64 = double(float(f0.f64 * f0.f64 + ctx.f12.f64));
	// fmadds f31,f13,f13,f11
	f31.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f11.f64));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262ABF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,1512(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 1512);
	// addi r5,r3,48
	ctx.r5.s64 = ctx.r3.s64 + 48;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// lwz r4,0(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// lvx128 v127,r0,r5
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,644(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 644);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8262AC18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r3,48
	ctx.r10.s64 = ctx.r3.s64 + 48;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// fsqrts f10,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(sqrt(f31.f64)));
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// lvx128 v49,r0,r10
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v48,v49,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v48.f32, simde_mm_sub_ps(simde_mm_load_ps(v49.f32), simde_mm_load_ps(v127.f32)));
	// stvx128 v48,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f9,f0,f0
	ctx.f9.f64 = double(float(f0.f64 * f0.f64));
	// fmadds f8,f13,f13,f9
	ctx.f8.f64 = double(float(ctx.f13.f64 * ctx.f13.f64 + ctx.f9.f64));
	// fmadds f7,f12,f12,f8
	ctx.f7.f64 = double(float(ctx.f12.f64 * ctx.f12.f64 + ctx.f8.f64));
	// fsqrts f6,f7
	ctx.f6.f64 = double(float(sqrt(ctx.f7.f64)));
	// fdivs f1,f10,f6
	ctx.f1.f64 = double(float(ctx.f10.f64 / ctx.f6.f64));
	// bl 0x8262c1e0
	ctx.lr = 0x8262AC58;
	sub_8262C1E0(ctx, base);
loc_8262AC58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// bl 0x8262a688
	ctx.lr = 0x8262AC64;
	sub_8262A688(ctx, base);
	// lbz r11,1184(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262ac7c
	if (cr6.eq) goto loc_8262AC7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// bl 0x82626768
	ctx.lr = 0x8262AC7C;
	sub_82626768(ctx, base);
loc_8262AC7C:
	// lbz r11,1185(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1185);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262ac94
	if (cr6.eq) goto loc_8262AC94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// bl 0x82626968
	ctx.lr = 0x8262AC94;
	sub_82626968(ctx, base);
loc_8262AC94:
	// lbz r6,1185(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 1185);
	// lfs f1,1396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1396);
	ctx.f1.f64 = double(temp.f32);
	// lbz r5,1184(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 1184);
	// lwz r3,104(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 104);
	// bl 0x8262bd88
	ctx.lr = 0x8262ACA8;
	sub_8262BD88(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262ACBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262adec
	if (cr6.eq) goto loc_8262ADEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262ACDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,208(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262ACF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,208(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 208);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262AD0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// lfs f0,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f13,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32256
	ctx.r3.s64 = -2113929216;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lfs f29,-18920(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -18920);
	f29.f64 = double(temp.f32);
	// fsubs f11,f29,f0
	ctx.f11.f64 = double(float(f29.f64 - f0.f64));
	// lfs f31,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f27,14988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	f27.f64 = double(temp.f32);
	// lfs f28,-21460(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -21460);
	f28.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8262ae3c
	if (!cr6.lt) goto loc_8262AE3C;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_8262AD54:
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// fabs f26,f13
	f26.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_8262AD60:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262AD74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lfs f13,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f0
	ctx.f12.f64 = double(float(f29.f64 - f0.f64));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fdivs f0,f11,f12
	f0.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8262ae4c
	if (!cr6.lt) goto loc_8262AE4C;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_8262AD94:
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// fabs f0,f13
	f0.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_8262ADA0:
	// fmuls f0,f0,f26
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f26.f64));
	// lfs f13,52(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,52(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// fmadds f11,f13,f12,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + f0.f64));
	// fsqrts f10,f11
	ctx.f10.f64 = double(float(sqrt(ctx.f11.f64)));
	// stfs f10,1132(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 1132, temp.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262ADCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f9,1132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1132);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f1,f8,f9
	ctx.f1.f64 = double(float(ctx.f8.f64 / ctx.f9.f64));
	// bl 0x823dcb30
	ctx.lr = 0x8262ADDC;
	sub_823DCB30(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// stfs f7,1488(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 1488, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82623bf8
	ctx.lr = 0x8262ADEC;
	sub_82623BF8(ctx, base);
loc_8262ADEC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// bl 0x82622ff0
	ctx.lr = 0x8262ADF8;
	sub_82622FF0(ctx, base);
	// lbz r11,372(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 372);
	// lwz r3,600(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262ae24
	if (cr6.eq) goto loc_8262AE24;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262ae24
	if (cr6.eq) goto loc_8262AE24;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f25
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f25.f64;
	// lwz r10,188(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262AE24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262AE24:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// li r0,-112
	r0.s64 = -112;
	// lvx128 v127,r1,r0
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r1.u32 + r0.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-32
	r12.s64 = ctx.r1.s64 + -32;
	// bl 0x823dba18
	ctx.lr = 0x8262AE38;
	// b 0x823d924c
	return;
loc_8262AE3C:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8262ad54
	if (!cr6.gt) goto loc_8262AD54;
	// fmr f26,f27
	f26.f64 = f27.f64;
	// b 0x8262ad60
	goto loc_8262AD60;
loc_8262AE4C:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8262ad94
	if (!cr6.gt) goto loc_8262AD94;
	// fmr f0,f27
	f0.f64 = f27.f64;
	// b 0x8262ada0
	goto loc_8262ADA0;
}

__attribute__((alias("__imp__sub_8262AE5C"))) PPC_WEAK_FUNC(sub_8262AE5C);
PPC_FUNC_IMPL(__imp__sub_8262AE5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262AE60"))) PPC_WEAK_FUNC(sub_8262AE60);
PPC_FUNC_IMPL(__imp__sub_8262AE60) {
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
	ctx.lr = 0x8262AE68;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// stw r4,588(r31)
	PPC_STORE_U32(r31.u32 + 588, ctx.r4.u32);
	// beq cr6,0x8262aed8
	if (cr6.eq) goto loc_8262AED8;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262AE9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262aed8
	if (cr6.eq) goto loc_8262AED8;
	// lwz r3,588(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 588);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262AEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// bl 0x826290c0
	ctx.lr = 0x8262AED8;
	sub_826290C0(ctx, base);
loc_8262AED8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262AEE0"))) PPC_WEAK_FUNC(sub_8262AEE0);
PPC_FUNC_IMPL(__imp__sub_8262AEE0) {
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
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
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
	// bl 0x823d91e8
	ctx.lr = 0x8262AEE8;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823db9d0
	ctx.lr = 0x8262AEF0;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635538
	ctx.lr = 0x8262AEFC;
	sub_82635538(ctx, base);
	// lis r25,-32121
	r25.s64 = -2105081856;
	// addi r11,r31,1200
	r11.s64 = r31.s64 + 1200;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,32
	ctx.r9.s64 = 32;
	// li r30,48
	r30.s64 = 48;
	// lwz r10,-10236(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// addi r10,r10,4272
	ctx.r10.s64 = ctx.r10.s64 + 4272;
	// lfs f13,12880(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 12880);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r10,r8
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r10,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r10,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1252(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1252);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bge cr6,0x8262af50
	if (!cr6.lt) goto loc_8262AF50;
	// stfs f0,1124(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 1124, temp.u32);
loc_8262AF50:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82623bf8
	ctx.lr = 0x8262AF58;
	sub_82623BF8(ctx, base);
	// lwz r3,600(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262af88
	if (cr6.eq) goto loc_8262AF88;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262AF74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8262aff4
	goto loc_8262AFF4;
loc_8262AF88:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a5948
	ctx.lr = 0x8262AF90;
	sub_822A5948(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262b000
	if (cr6.eq) goto loc_8262B000;
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262afe0
	if (cr6.eq) goto loc_8262AFE0;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8262afcc
	if (cr6.eq) goto loc_8262AFCC;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v58,r11,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8262aff4
	goto loc_8262AFF4;
loc_8262AFCC:
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v58,r11,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8262aff4
	goto loc_8262AFF4;
loc_8262AFE0:
	// bl 0x822a8108
	ctx.lr = 0x8262AFE4;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v57,r0,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8262AFF4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82620568
	ctx.lr = 0x8262B000;
	sub_82620568(ctx, base);
loc_8262B000:
	// addi r30,r31,720
	r30.s64 = r31.s64 + 720;
	// li r11,1104
	r11.s64 = 1104;
	// li r10,1408
	ctx.r10.s64 = 1408;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lvx128 v56,r0,r30
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r31,r11
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v54,v56,v55
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v55.f32)));
	// stvx128 v54,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r8,208(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262B030;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,208(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 208);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262B048;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,208(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 208);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8262B060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f0,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lfs f29,-18920(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	f29.f64 = double(temp.f32);
	// fsubs f11,f29,f0
	ctx.f11.f64 = double(float(f29.f64 - f0.f64));
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// lfs f30,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f30.f64 = double(temp.f32);
	// lfs f27,14988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 14988);
	f27.f64 = double(temp.f32);
	// lfs f28,-21460(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -21460);
	f28.f64 = double(temp.f32);
	// fdivs f0,f12,f11
	f0.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8262b338
	if (!cr6.lt) goto loc_8262B338;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_8262B0A8:
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// fabs f26,f13
	f26.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_8262B0B4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262B0C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f0,1124(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1124);
	f0.f64 = double(temp.f32);
	// lfs f13,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f29,f0
	ctx.f12.f64 = double(float(f29.f64 - f0.f64));
	// fsubs f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fdivs f0,f11,f12
	f0.f64 = double(float(ctx.f11.f64 / ctx.f12.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// bge cr6,0x8262b348
	if (!cr6.lt) goto loc_8262B348;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_8262B0E8:
	// fsubs f0,f30,f0
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f30.f64 - f0.f64));
	// fmuls f13,f0,f28
	ctx.f13.f64 = double(float(f0.f64 * f28.f64));
	// fabs f0,f13
	f0.u64 = ctx.f13.u64 & ~0x8000000000000000;
loc_8262B0F4:
	// fmuls f0,f0,f26
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 * f26.f64));
	// lfs f13,52(r28)
	temp.u32 = PPC_LOAD_U32(r28.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,52(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 52);
	ctx.f12.f64 = double(temp.f32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// fmadds f11,f13,f12,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64 + f0.f64));
	// fsqrts f10,f11
	ctx.f10.f64 = double(float(sqrt(ctx.f11.f64)));
	// stfs f10,1132(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 1132, temp.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262B120;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lfs f9,1132(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 1132);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,52(r3)
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f8.f64 = double(temp.f32);
	// fdivs f1,f8,f9
	ctx.f1.f64 = double(float(ctx.f8.f64 / ctx.f9.f64));
	// bl 0x823dcb30
	ctx.lr = 0x8262B130;
	sub_823DCB30(ctx, base);
	// frsp f7,f1
	ctx.fpscr.disableFlushMode();
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// stfs f7,1488(r31)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(r31.u32 + 1488, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82623ee8
	ctx.lr = 0x8262B140;
	sub_82623EE8(ctx, base);
	// lbz r9,496(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 496);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262b160
	if (cr6.eq) goto loc_8262B160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f3,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,4(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x826263c0
	ctx.lr = 0x8262B160;
	sub_826263C0(ctx, base);
loc_8262B160:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f970
	ctx.lr = 0x8262B16C;
	sub_8261F970(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262B184;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,552(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 552);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262B19C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82256058
	ctx.lr = 0x8262B1A0;
	sub_82256058(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r30,1
	r30.s64 = 1;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8262b1dc
	if (cr6.eq) goto loc_8262B1DC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-18800
	ctx.r3.s64 = r11.s64 + -18800;
	// bl 0x821fa230
	ctx.lr = 0x8262B1C0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262B1D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8262b1ec
	if (!cr6.eq) goto loc_8262B1EC;
loc_8262B1DC:
	// lwz r11,-6148(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -6148);
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262b358
	if (cr6.eq) goto loc_8262B358;
loc_8262B1EC:
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// stb r30,376(r31)
	PPC_STORE_U8(r31.u32 + 376, r30.u8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262B204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262B21C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,368(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,96(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 96);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262B234;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r29,368(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 368);
	// bl 0x82256438
	ctx.lr = 0x8262B240;
	sub_82256438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8262a0e8
	ctx.lr = 0x8262B250;
	sub_8262A0E8(ctx, base);
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r5,5
	ctx.r3.s64 = ctx.r5.s64 + 327680;
	// addi r3,r3,4672
	ctx.r3.s64 = ctx.r3.s64 + 4672;
	// bl 0x8221a2a8
	ctx.lr = 0x8262B268;
	sub_8221A2A8(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// stb r30,372(r31)
	PPC_STORE_U8(r31.u32 + 372, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r29,496(r31)
	PPC_STORE_U8(r31.u32 + 496, r29.u8);
	// stb r30,1427(r31)
	PPC_STORE_U8(r31.u32 + 1427, r30.u8);
	// stb r30,1401(r31)
	PPC_STORE_U8(r31.u32 + 1401, r30.u8);
	// stb r29,375(r31)
	PPC_STORE_U8(r31.u32 + 375, r29.u8);
	// stb r29,374(r31)
	PPC_STORE_U8(r31.u32 + 374, r29.u8);
	// stb r30,377(r31)
	PPC_STORE_U8(r31.u32 + 377, r30.u8);
	// bl 0x8261fbd0
	ctx.lr = 0x8262B290;
	sub_8261FBD0(ctx, base);
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204018
	ctx.lr = 0x8262B29C;
	sub_82204018(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// cmpwi cr6,r3,11
	cr6.compare<int32_t>(ctx.r3.s32, 11, xer);
	// addi r27,r11,-17820
	r27.s64 = r11.s64 + -17820;
	// beq cr6,0x8262b300
	if (cr6.eq) goto loc_8262B300;
	// lwz r11,-10236(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82204018
	ctx.lr = 0x8262B2BC;
	sub_82204018(ctx, base);
	// cmpwi cr6,r3,5
	cr6.compare<int32_t>(ctx.r3.s32, 5, xer);
	// beq cr6,0x8262b300
	if (cr6.eq) goto loc_8262B300;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r28,-10244(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// bl 0x82256438
	ctx.lr = 0x8262B2D0;
	sub_82256438(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82218310
	ctx.lr = 0x8262B2DC;
	sub_82218310(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262B2F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262B300;
	sub_825EE2D8(ctx, base);
loc_8262B300:
	// lwz r11,-6148(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -6148);
	// lbz r11,13(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262b390
	if (cr6.eq) goto loc_8262B390;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// addi r4,r11,2052
	ctx.r4.s64 = r11.s64 + 2052;
	// bl 0x82218310
	ctx.lr = 0x8262B320;
	sub_82218310(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// b 0x8262b380
	goto loc_8262B380;
loc_8262B338:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8262b0a8
	if (!cr6.gt) goto loc_8262B0A8;
	// fmr f26,f27
	f26.f64 = f27.f64;
	// b 0x8262b0b4
	goto loc_8262B0B4;
loc_8262B348:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, f30.f64);
	// ble cr6,0x8262b0e8
	if (!cr6.gt) goto loc_8262B0E8;
	// fmr f0,f27
	f0.f64 = f27.f64;
	// b 0x8262b0f4
	goto loc_8262B0F4;
loc_8262B358:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// stb r29,376(r31)
	PPC_STORE_U8(r31.u32 + 376, r29.u8);
	// addi r28,r10,3998
	r28.s64 = ctx.r10.s64 + 3998;
	// addi r27,r9,-17820
	r27.s64 = ctx.r9.s64 + -17820;
	// lwz r8,468(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_8262B380:
	// bctrl 
	ctx.lr = 0x8262B384;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262B390;
	sub_825EE2D8(ctx, base);
loc_8262B390:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701bd8
	ctx.lr = 0x8262B398;
	sub_82701BD8(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// ble cr6,0x8262b3ec
	if (!cr6.gt) goto loc_8262B3EC;
	// stb r29,496(r31)
	PPC_STORE_U8(r31.u32 + 496, r29.u8);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-20480
	ctx.r3.s64 = r11.s64 + -20480;
	// bl 0x821fa230
	ctx.lr = 0x8262B3B0;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262B3C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stb r30,1427(r31)
	PPC_STORE_U8(r31.u32 + 1427, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// stb r30,1401(r31)
	PPC_STORE_U8(r31.u32 + 1401, r30.u8);
	// stb r29,375(r31)
	PPC_STORE_U8(r31.u32 + 375, r29.u8);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r29,374(r31)
	PPC_STORE_U8(r31.u32 + 374, r29.u8);
	// stb r30,377(r31)
	PPC_STORE_U8(r31.u32 + 377, r30.u8);
	// stb r6,372(r31)
	PPC_STORE_U8(r31.u32 + 372, ctx.r6.u8);
	// bl 0x8261fbd0
	ctx.lr = 0x8262B3EC;
	sub_8261FBD0(ctx, base);
loc_8262B3EC:
	// lwz r4,616(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 616);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8262b420
	if (cr6.eq) goto loc_8262B420;
	// lwz r11,600(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 600);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x8262b420
	if (cr6.eq) goto loc_8262B420;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826290c0
	ctx.lr = 0x8262B420;
	sub_826290C0(ctx, base);
loc_8262B420:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8262B42C;
	sub_822A39C8(ctx, base);
	// bl 0x822a5680
	ctx.lr = 0x8262B430;
	sub_822A5680(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262b440
	if (cr6.eq) goto loc_8262B440;
	// stb r30,1168(r31)
	PPC_STORE_U8(r31.u32 + 1168, r30.u8);
loc_8262B440:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-72
	r12.s64 = ctx.r1.s64 + -72;
	// bl 0x823dba1c
	ctx.lr = 0x8262B44C;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8262B450"))) PPC_WEAK_FUNC(sub_8262B450);
PPC_FUNC_IMPL(__imp__sub_8262B450) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8262B458;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
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
	ctx.lr = 0x8262B470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262b654
	if (cr6.eq) goto loc_8262B654;
	// lwz r11,88(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262b654
	if (cr6.eq) goto loc_8262B654;
	// rotlwi r9,r11,0
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lis r26,-32114
	r26.s64 = -2104623104;
	// lis r25,-32114
	r25.s64 = -2104623104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,44(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// lwz r23,-22860(r26)
	r23.u64 = PPC_LOAD_U32(r26.u32 + -22860);
	// lwz r22,-22856(r25)
	r22.u64 = PPC_LOAD_U32(r25.u32 + -22856);
	// stw r11,-22860(r26)
	PPC_STORE_U32(r26.u32 + -22860, r11.u32);
	// lwz r8,88(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// lwz r11,48(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// stw r11,-22856(r25)
	PPC_STORE_U32(r25.u32 + -22856, r11.u32);
	// bl 0x82637a40
	ctx.lr = 0x8262B4B8;
	sub_82637A40(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r3,-10220(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10220);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,208(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 208);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8262B4D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32248
	ctx.r4.s64 = -2113404928;
	// lfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	f0.f64 = double(temp.f32);
	// li r30,0
	r30.s64 = 0;
	// lfs f13,-11360(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -11360);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8262b4f0
	if (!cr6.gt) goto loc_8262B4F0;
	// li r24,100
	r24.s64 = 100;
	// b 0x8262b538
	goto loc_8262B538;
loc_8262B4F0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lfs f13,-6432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -6432);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8262b508
	if (!cr6.gt) goto loc_8262B508;
	// li r24,80
	r24.s64 = 80;
	// b 0x8262b538
	goto loc_8262B538;
loc_8262B508:
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lfs f13,-18920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -18920);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8262b520
	if (!cr6.gt) goto loc_8262B520;
	// li r24,80
	r24.s64 = 80;
	// b 0x8262b538
	goto loc_8262B538;
loc_8262B520:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r24,40
	r24.s64 = 40;
	// lfs f13,-2376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -2376);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// bgt cr6,0x8262b538
	if (cr6.gt) goto loc_8262B538;
	// mr r24,r30
	r24.u64 = r30.u64;
loc_8262B538:
	// lbz r11,256(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 256);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262b64c
	if (cr6.eq) goto loc_8262B64C;
	// lis r11,-32112
	r11.s64 = -2104492032;
	// lwz r4,260(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// lwz r11,24432(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 24432);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8262b560
	if (cr6.eq) goto loc_8262B560;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826246d8
	ctx.lr = 0x8262B560;
	sub_826246D8(ctx, base);
loc_8262B560:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r10,-17804
	r29.s64 = ctx.r10.s64 + -17804;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262B57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x8262B588;
	sub_825EE0E0(ctx, base);
	// stw r30,1320(r31)
	PPC_STORE_U32(r31.u32 + 1320, r30.u32);
	// stw r30,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r30.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,480(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 480);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262B5AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8262b644
	if (cr6.eq) goto loc_8262B644;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r28,r11,-22132
	r28.s64 = r11.s64 + -22132;
	// addi r27,r10,23984
	r27.s64 = ctx.r10.s64 + 23984;
loc_8262B5C8:
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x823dedd8
	ctx.lr = 0x8262B5E0;
	sub_823DEDD8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x8262a578
	ctx.lr = 0x8262B5E8;
	sub_8262A578(ctx, base);
	// lwz r11,156(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262b624
	if (cr6.eq) goto loc_8262B624;
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r11,148(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// cmpw cr6,r11,r24
	cr6.compare<int32_t>(r11.s32, r24.s32, xer);
	// blt cr6,0x8262b624
	if (cr6.lt) goto loc_8262B624;
	// cmpwi cr6,r24,100
	cr6.compare<int32_t>(r24.s32, 100, xer);
	// bge cr6,0x8262b618
	if (!cr6.lt) goto loc_8262B618;
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// beq cr6,0x8262b624
	if (cr6.eq) goto loc_8262B624;
loc_8262B618:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82626e50
	ctx.lr = 0x8262B624;
	sub_82626E50(ctx, base);
loc_8262B624:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,484(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 484);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262B638;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8262b5c8
	if (!cr6.eq) goto loc_8262B5C8;
loc_8262B644:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826271c8
	ctx.lr = 0x8262B64C;
	sub_826271C8(ctx, base);
loc_8262B64C:
	// stw r23,-22860(r26)
	PPC_STORE_U32(r26.u32 + -22860, r23.u32);
	// stw r22,-22856(r25)
	PPC_STORE_U32(r25.u32 + -22856, r22.u32);
loc_8262B654:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8262B65C"))) PPC_WEAK_FUNC(sub_8262B65C);
PPC_FUNC_IMPL(__imp__sub_8262B65C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262B660"))) PPC_WEAK_FUNC(sub_8262B660);
PPC_FUNC_IMPL(__imp__sub_8262B660) {
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
	// bl 0x82627e48
	ctx.lr = 0x8262B678;
	sub_82627E48(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// bl 0x8262ae60
	ctx.lr = 0x8262B694;
	sub_8262AE60(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262B6A8"))) PPC_WEAK_FUNC(sub_8262B6A8);
PPC_FUNC_IMPL(__imp__sub_8262B6A8) {
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
	// bl 0x82635538
	ctx.lr = 0x8262B6C0;
	sub_82635538(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82627e48
	ctx.lr = 0x8262B6C8;
	sub_82627E48(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// bl 0x8262ae60
	ctx.lr = 0x8262B6E4;
	sub_8262AE60(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262B6F8"))) PPC_WEAK_FUNC(sub_8262B6F8);
PPC_FUNC_IMPL(__imp__sub_8262B6F8) {
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
	ctx.lr = 0x8262B710;
	sub_82637538(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r31,80
	ctx.r3.s64 = r31.s64 + 80;
	// addi r10,r11,-17780
	ctx.r10.s64 = r11.s64 + -17780;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x8224c100
	ctx.lr = 0x8262B724;
	sub_8224C100(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r11,270(r31)
	PPC_STORE_U16(r31.u32 + 270, r11.u16);
	// sth r11,268(r31)
	PPC_STORE_U16(r31.u32 + 268, r11.u16);
	// stw r11,264(r31)
	PPC_STORE_U32(r31.u32 + 264, r11.u32);
	// stb r11,275(r31)
	PPC_STORE_U8(r31.u32 + 275, r11.u8);
	// stw r11,796(r31)
	PPC_STORE_U32(r31.u32 + 796, r11.u32);
	// stw r11,792(r31)
	PPC_STORE_U32(r31.u32 + 792, r11.u32);
	// stw r11,788(r31)
	PPC_STORE_U32(r31.u32 + 788, r11.u32);
	// stw r11,1320(r31)
	PPC_STORE_U32(r31.u32 + 1320, r11.u32);
	// stw r11,1316(r31)
	PPC_STORE_U32(r31.u32 + 1316, r11.u32);
	// stw r11,1312(r31)
	PPC_STORE_U32(r31.u32 + 1312, r11.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262B768"))) PPC_WEAK_FUNC(sub_8262B768);
PPC_FUNC_IMPL(__imp__sub_8262B768) {
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
	// addi r3,r31,264
	ctx.r3.s64 = r31.s64 + 264;
	// bl 0x82608de8
	ctx.lr = 0x8262B788;
	sub_82608DE8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// addi r10,r11,-17868
	ctx.r10.s64 = r11.s64 + -17868;
	// addi r3,r30,156
	ctx.r3.s64 = r30.s64 + 156;
	// stw r10,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r10.u32);
	// lhz r5,242(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 242);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8262b7b0
	if (cr6.eq) goto loc_8262B7B0;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x8224a9c0
	ctx.lr = 0x8262B7B0;
	sub_8224A9C0(ctx, base);
loc_8262B7B0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821d2028
	ctx.lr = 0x8262B7B8;
	sub_821D2028(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375a0
	ctx.lr = 0x8262B7C0;
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

__attribute__((alias("__imp__sub_8262B7D8"))) PPC_WEAK_FUNC(sub_8262B7D8);
PPC_FUNC_IMPL(__imp__sub_8262B7D8) {
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
	// li r3,1328
	ctx.r3.s64 = 1328;
	// bl 0x82130528
	ctx.lr = 0x8262B7F8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262b808
	if (cr6.eq) goto loc_8262B808;
	// bl 0x8262b6f8
	ctx.lr = 0x8262B804;
	sub_8262B6F8(ctx, base);
	// b 0x8262b80c
	goto loc_8262B80C;
loc_8262B808:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8262B80C:
	// stw r3,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r3.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262B820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r4,-27856(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + -27856);
	// bl 0x8262a168
	ctx.lr = 0x8262B830;
	sub_8262A168(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,176(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r7,368(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 368);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262B848;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,176(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,468(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 468);
	// lwz r30,0(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8262B864;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,176(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8262B878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,180(r31)
	PPC_STORE_U8(r31.u32 + 180, r11.u8);
	// stb r11,160(r31)
	PPC_STORE_U8(r31.u32 + 160, r11.u8);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stb r11,161(r31)
	PPC_STORE_U8(r31.u32 + 161, r11.u8);
	// stfs f0,68(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 68, temp.u32);
	// stb r11,162(r31)
	PPC_STORE_U8(r31.u32 + 162, r11.u8);
	// stb r11,163(r31)
	PPC_STORE_U8(r31.u32 + 163, r11.u8);
	// stb r11,164(r31)
	PPC_STORE_U8(r31.u32 + 164, r11.u8);
	// bl 0x82635af8
	ctx.lr = 0x8262B8A8;
	sub_82635AF8(ctx, base);
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

__attribute__((alias("__imp__sub_8262B8C0"))) PPC_WEAK_FUNC(sub_8262B8C0);
PPC_FUNC_IMPL(__imp__sub_8262B8C0) {
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
	// bl 0x8262b768
	ctx.lr = 0x8262B8E0;
	sub_8262B768(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262b8f8
	if (cr6.eq) goto loc_8262B8F8;
	// bl 0x82130588
	ctx.lr = 0x8262B8F4;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262B8F8:
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

__attribute__((alias("__imp__sub_8262B910"))) PPC_WEAK_FUNC(sub_8262B910);
PPC_FUNC_IMPL(__imp__sub_8262B910) {
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
	// bl 0x82548ac0
	ctx.lr = 0x8262B928;
	sub_82548AC0(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-16892
	ctx.r10.s64 = r11.s64 + -16892;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82548ba8
	ctx.lr = 0x8262B93C;
	sub_82548BA8(ctx, base);
	// lis r9,-32131
	ctx.r9.s64 = -2105737216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// addi r7,r9,29952
	ctx.r7.s64 = ctx.r9.s64 + 29952;
	// li r11,0
	r11.s64 = 0;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// lfs f0,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// addi r4,r6,-16916
	ctx.r4.s64 = ctx.r6.s64 + -16916;
	// lwz r10,44(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// stfs f0,36(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
	// addi r3,r5,19856
	ctx.r3.s64 = ctx.r5.s64 + 19856;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// stb r11,44(r31)
	PPC_STORE_U8(r31.u32 + 44, r11.u8);
	// stb r11,45(r31)
	PPC_STORE_U8(r31.u32 + 45, r11.u8);
	// bl 0x82144a20
	ctx.lr = 0x8262B994;
	sub_82144A20(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8262B9B0"))) PPC_WEAK_FUNC(sub_8262B9B0);
PPC_FUNC_IMPL(__imp__sub_8262B9B0) {
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
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262b9d8
	if (cr6.eq) goto loc_8262B9D8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262B9D8;
	sub_8213C218(ctx, base);
loc_8262B9D8:
	// lwz r3,20(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262b9ec
	if (cr6.eq) goto loc_8262B9EC;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262B9EC;
	sub_8213C218(ctx, base);
loc_8262B9EC:
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262ba00
	if (cr6.eq) goto loc_8262BA00;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262BA00;
	sub_8213C218(ctx, base);
loc_8262BA00:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262ba14
	if (cr6.eq) goto loc_8262BA14;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262BA14;
	sub_8213C218(ctx, base);
loc_8262BA14:
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262ba28
	if (cr6.eq) goto loc_8262BA28;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262BA28;
	sub_8213C218(ctx, base);
loc_8262BA28:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262BA3C"))) PPC_WEAK_FUNC(sub_8262BA3C);
PPC_FUNC_IMPL(__imp__sub_8262BA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262BA40"))) PPC_WEAK_FUNC(sub_8262BA40);
PPC_FUNC_IMPL(__imp__sub_8262BA40) {
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
	// bl 0x8262b9b0
	ctx.lr = 0x8262BA58;
	sub_8262B9B0(ctx, base);
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12252(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12252);
	// lwz r10,1740(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r9,r10,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80;
	// beq cr6,0x8262ba84
	if (cr6.eq) goto loc_8262BA84;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262ba98
	if (cr6.eq) goto loc_8262BA98;
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x8262ba90
	goto loc_8262BA90;
loc_8262BA84:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262ba98
	if (cr6.eq) goto loc_8262BA98;
	// li r5,0
	ctx.r5.s64 = 0;
loc_8262BA90:
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x8262BA98;
	sub_821EC468(ctx, base);
loc_8262BA98:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262BAAC"))) PPC_WEAK_FUNC(sub_8262BAAC);
PPC_FUNC_IMPL(__imp__sub_8262BAAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262BAB0"))) PPC_WEAK_FUNC(sub_8262BAB0);
PPC_FUNC_IMPL(__imp__sub_8262BAB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r2{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// stfs f1,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// stfs f2,36(r31)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(r31.u32 + 36, temp.u32);
	// bl 0x8262b9b0
	ctx.lr = 0x8262BAD8;
	sub_8262B9B0(ctx, base);
	// cmplwi cr6,r30,6
	cr6.compare<uint32_t>(r30.u32, 6, xer);
	// bgt cr6,0x8262bd44
	if (cr6.gt) goto loc_8262BD44;
	// lis r12,-32157
	r12.s64 = -2107441152;
	// addi r12,r12,-17672
	r12.s64 = r12.s64 + -17672;
	// rlwinm r0,r30,2,0,29
	r0.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r30.u64) {
	case 0:
		goto loc_8262BB14;
	case 1:
		goto loc_8262BB7C;
	case 2:
		goto loc_8262BBC4;
	case 3:
		goto loc_8262BC2C;
	case 4:
		goto loc_8262BC74;
	case 5:
		goto loc_8262BCDC;
	case 6:
		goto loc_8262BD24;
	default:
		__builtin_unreachable();
	}
	// lwz r19,-17644(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -17644);
	// lwz r19,-17540(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -17540);
	// lwz r19,-17468(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -17468);
	// lwz r19,-17364(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -17364);
	// lwz r19,-17292(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -17292);
	// lwz r19,-17188(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -17188);
	// lwz r19,-17116(r2)
	r19.u64 = PPC_LOAD_U32(r2.u32 + -17116);
loc_8262BB14:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,66(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 66);
	// bl 0x825492c8
	ctx.lr = 0x8262BB34;
	sub_825492C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lwz r9,1740(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8262bd44
	if (!cr6.eq) goto loc_8262BD44;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,0
	ctx.r8.s64 = ctx.r10.s64 + 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r7,r7,0
	ctx.r7.s64 = ctx.r7.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ed368
	ctx.lr = 0x8262BB78;
	sub_821ED368(ctx, base);
	// b 0x8262bd44
	goto loc_8262BD44;
loc_8262BB7C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,70(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 70);
	// bl 0x825492c8
	ctx.lr = 0x8262BB9C;
	sub_825492C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lwz r9,1740(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8262bd44
	if (cr6.eq) goto loc_8262BD44;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x8262BBC0;
	sub_821EC468(ctx, base);
	// b 0x8262bd44
	goto loc_8262BD44;
loc_8262BBC4:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,74(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 74);
	// bl 0x825492c8
	ctx.lr = 0x8262BBE4;
	sub_825492C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lwz r9,1740(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8262bd44
	if (!cr6.eq) goto loc_8262BD44;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,0
	ctx.r8.s64 = ctx.r10.s64 + 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r7,r7,0
	ctx.r7.s64 = ctx.r7.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ed368
	ctx.lr = 0x8262BC28;
	sub_821ED368(ctx, base);
	// b 0x8262bd44
	goto loc_8262BD44;
loc_8262BC2C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,78(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 78);
	// bl 0x825492c8
	ctx.lr = 0x8262BC4C;
	sub_825492C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lwz r9,1740(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8262bd44
	if (cr6.eq) goto loc_8262BD44;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x8262BC70;
	sub_821EC468(ctx, base);
	// b 0x8262bd44
	goto loc_8262BD44;
loc_8262BC74:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,82(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 82);
	// bl 0x825492c8
	ctx.lr = 0x8262BC94;
	sub_825492C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lwz r9,1740(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8262bd44
	if (!cr6.eq) goto loc_8262BD44;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32237
	ctx.r10.s64 = -2112684032;
	// lis r7,-32237
	ctx.r7.s64 = -2112684032;
	// lis r6,-32237
	ctx.r6.s64 = -2112684032;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r8,r10,0
	ctx.r8.s64 = ctx.r10.s64 + 0;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r7,r7,0
	ctx.r7.s64 = ctx.r7.s64 + 0;
	// addi r6,r6,0
	ctx.r6.s64 = ctx.r6.s64 + 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ed368
	ctx.lr = 0x8262BCD8;
	sub_821ED368(ctx, base);
	// b 0x8262bd44
	goto loc_8262BD44;
loc_8262BCDC:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,86(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 86);
	// bl 0x825492c8
	ctx.lr = 0x8262BCFC;
	sub_825492C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-12252(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12252);
	// lwz r9,1740(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1740);
	// rlwinm r8,r9,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8262bd44
	if (cr6.eq) goto loc_8262BD44;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x821ec468
	ctx.lr = 0x8262BD20;
	sub_821EC468(ctx, base);
	// b 0x8262bd44
	goto loc_8262BD44;
loc_8262BD24:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r31,16
	ctx.r5.s64 = r31.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,90(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 90);
	// bl 0x825492c8
	ctx.lr = 0x8262BD44;
	sub_825492C8(ctx, base);
loc_8262BD44:
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262bd60
	if (cr6.eq) goto loc_8262BD60;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c0c0
	ctx.lr = 0x8262BD60;
	sub_8213C0C0(ctx, base);
loc_8262BD60:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x821e6828
	ctx.lr = 0x8262BD6C;
	sub_821E6828(ctx, base);
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

__attribute__((alias("__imp__sub_8262BD84"))) PPC_WEAK_FUNC(sub_8262BD84);
PPC_FUNC_IMPL(__imp__sub_8262BD84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262BD88"))) PPC_WEAK_FUNC(sub_8262BD88);
PPC_FUNC_IMPL(__imp__sub_8262BD88) {
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
	ctx.lr = 0x8262BD90;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r10,r6,24
	ctx.r10.u64 = ctx.r6.u32 & 0xFF;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// beq cr6,0x8262bf7c
	if (cr6.eq) goto loc_8262BF7C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beq cr6,0x8262bf7c
	if (cr6.eq) goto loc_8262BF7C;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// beq cr6,0x8262bf7c
	if (cr6.eq) goto loc_8262BF7C;
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r30,20
	r28.s64 = r30.s64 + 20;
	// li r31,0
	r31.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// beq cr6,0x8262beb0
	if (cr6.eq) goto loc_8262BEB0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8262be44
	if (!cr6.eq) goto loc_8262BE44;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r31,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r31.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r29,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r29.u8);
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x825495a8
	ctx.lr = 0x8262BE30;
	sub_825495A8(ctx, base);
	// stb r29,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r29.u8);
	// stb r31,45(r30)
	PPC_STORE_U8(r30.u32 + 45, r31.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8262BE44:
	// lbz r11,45(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 45);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262be9c
	if (cr6.eq) goto loc_8262BE9C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262BE58;
	sub_8213C218(ctx, base);
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r10,0
	ctx.r10.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r31,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r31.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r4,10(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 10);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stb r29,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r29.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// bl 0x825495a8
	ctx.lr = 0x8262BE9C;
	sub_825495A8(ctx, base);
loc_8262BE9C:
	// stb r29,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r29.u8);
	// stb r31,45(r30)
	PPC_STORE_U8(r30.u32 + 45, r31.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8262BEB0:
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8262bf10
	if (!cr6.eq) goto loc_8262BF10;
	// stb r29,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r29.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r31,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r31.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// lwz r4,14(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// bl 0x825495a8
	ctx.lr = 0x8262BEFC;
	sub_825495A8(ctx, base);
	// stb r31,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r31.u8);
	// stb r29,45(r30)
	PPC_STORE_U8(r30.u32 + 45, r29.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8262BF10:
	// lbz r11,44(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 44);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262bf68
	if (cr6.eq) goto loc_8262BF68;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262BF24;
	sub_8213C218(ctx, base);
	// stw r31,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r31.u32);
	// stb r29,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r29.u8);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// stb r31,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r31.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
	// lwz r4,14(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 14);
	// bl 0x825495a8
	ctx.lr = 0x8262BF68;
	sub_825495A8(ctx, base);
loc_8262BF68:
	// stb r31,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r31.u8);
	// stb r29,45(r30)
	PPC_STORE_U8(r30.u32 + 45, r29.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
loc_8262BF7C:
	// lwz r3,20(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262bf90
	if (cr6.eq) goto loc_8262BF90;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262BF90;
	sub_8213C218(ctx, base);
loc_8262BF90:
	// li r31,0
	r31.s64 = 0;
	// stb r31,44(r30)
	PPC_STORE_U8(r30.u32 + 44, r31.u8);
	// stb r31,45(r30)
	PPC_STORE_U8(r30.u32 + 45, r31.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262BFA8"))) PPC_WEAK_FUNC(sub_8262BFA8);
PPC_FUNC_IMPL(__imp__sub_8262BFA8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8213c218
	sub_8213C218(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8262BFBC"))) PPC_WEAK_FUNC(sub_8262BFBC);
PPC_FUNC_IMPL(__imp__sub_8262BFBC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262BFC0"))) PPC_WEAK_FUNC(sub_8262BFC0);
PPC_FUNC_IMPL(__imp__sub_8262BFC0) {
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
	// lwz r5,8(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r11,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r11.u8);
	// lfs f1,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,58(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 58);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82549428
	ctx.lr = 0x8262C00C;
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

__attribute__((alias("__imp__sub_8262C01C"))) PPC_WEAK_FUNC(sub_8262C01C);
PPC_FUNC_IMPL(__imp__sub_8262C01C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262C020"))) PPC_WEAK_FUNC(sub_8262C020);
PPC_FUNC_IMPL(__imp__sub_8262C020) {
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
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r30,r11,29952
	r30.s64 = r11.s64 + 29952;
	// lfs f13,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8262c080
	if (!cr6.gt) goto loc_8262C080;
	// lfs f12,8(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// stfs f13,40(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x8262c080
	if (cr6.gt) goto loc_8262C080;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// stfs f0,40(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 40, temp.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262c080
	if (cr6.eq) goto loc_8262C080;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x8262C080;
	sub_8213C218(ctx, base);
loc_8262C080:
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262c0a8
	if (cr6.eq) goto loc_8262C0A8;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// lwz r11,44(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cmplwi cr6,r9,1
	cr6.compare<uint32_t>(ctx.r9.u32, 1, xer);
	// ble cr6,0x8262c0a8
	if (!cr6.gt) goto loc_8262C0A8;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x8262C0A8;
	sub_8213C218(ctx, base);
loc_8262C0A8:
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

__attribute__((alias("__imp__sub_8262C0C0"))) PPC_WEAK_FUNC(sub_8262C0C0);
PPC_FUNC_IMPL(__imp__sub_8262C0C0) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-16892
	ctx.r10.s64 = r11.s64 + -16892;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82548b50
	ctx.lr = 0x8262C0EC;
	sub_82548B50(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262c104
	if (cr6.eq) goto loc_8262C104;
	// bl 0x82130588
	ctx.lr = 0x8262C100;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262C104:
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

__attribute__((alias("__imp__sub_8262C11C"))) PPC_WEAK_FUNC(sub_8262C11C);
PPC_FUNC_IMPL(__imp__sub_8262C11C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262C120"))) PPC_WEAK_FUNC(sub_8262C120);
PPC_FUNC_IMPL(__imp__sub_8262C120) {
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
	ctx.lr = 0x8262C128;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmuls f0,f2,f2
	f0.f64 = double(float(ctx.f2.f64 * ctx.f2.f64));
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// fmadds f13,f1,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f1.f64 + f0.f64));
	// fsqrts f31,f13
	f31.f64 = double(float(sqrt(ctx.f13.f64)));
	// bne cr6,0x8262c19c
	if (!cr6.eq) goto loc_8262C19C;
	// lwz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r29,1
	r29.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r11.u8);
	// lfs f1,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r4,18(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 18);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r29,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r29.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x825495a8
	ctx.lr = 0x8262C19C;
	sub_825495A8(ctx, base);
loc_8262C19C:
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 22);
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	f0.f64 = double(temp.f32);
	// beq cr6,0x8262c1d0
	if (cr6.eq) goto loc_8262C1D0;
	// lwz r11,26(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 26);
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// lfs f13,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fmadds f1,f12,f31,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f31.f64 + f0.f64));
	// bl 0x8213cb40
	ctx.lr = 0x8262C1D0;
	sub_8213CB40(ctx, base);
loc_8262C1D0:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262C1DC"))) PPC_WEAK_FUNC(sub_8262C1DC);
PPC_FUNC_IMPL(__imp__sub_8262C1DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262C1E0"))) PPC_WEAK_FUNC(sub_8262C1E0);
PPC_FUNC_IMPL(__imp__sub_8262C1E0) {
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
	ctx.lr = 0x8262C1E8;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823db9d8
	ctx.lr = 0x8262C1F0;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// lwz r10,34(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bge cr6,0x8262c234
	if (!cr6.lt) goto loc_8262C234;
	// lwz r3,24(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262c448
	if (cr6.eq) goto loc_8262C448;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8213c218
	ctx.lr = 0x8262C224;
	sub_8213C218(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba24
	ctx.lr = 0x8262C230;
	// b 0x823d9248
	return;
loc_8262C234:
	// lwz r10,38(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 38);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,34(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 34);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// lfs f13,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f1,f12
	ctx.f11.f64 = double(float(ctx.f1.f64 - ctx.f12.f64));
	// fsubs f10,f0,f12
	ctx.f10.f64 = double(float(f0.f64 - ctx.f12.f64));
	// fdivs f0,f11,f10
	f0.f64 = double(float(ctx.f11.f64 / ctx.f10.f64));
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8262c26c
	if (!cr6.gt) goto loc_8262C26C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_8262C26C:
	// lwz r8,54(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 54);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lwz r6,50(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 50);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r4,42(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 42);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,46(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 46);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r30,28(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + 28);
	// addi r31,r28,28
	r31.s64 = r28.s64 + 28;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lfs f12,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lfs f10,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f11
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// fsubs f8,f13,f12
	ctx.f8.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f30,3796(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 3796);
	f30.f64 = double(temp.f32);
	// lfs f28,11368(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11368);
	f28.f64 = double(temp.f32);
	// addi r30,r10,7216
	r30.s64 = ctx.r10.s64 + 7216;
	// addi r29,r9,-17232
	r29.s64 = ctx.r9.s64 + -17232;
	// fmadds f29,f9,f0,f11
	f29.f64 = double(float(ctx.f9.f64 * f0.f64 + ctx.f11.f64));
	// fmadds f31,f8,f0,f12
	f31.f64 = double(float(ctx.f8.f64 * f0.f64 + ctx.f12.f64));
	// bne cr6,0x8262c3a8
	if (!cr6.eq) goto loc_8262C3A8;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,30(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 30);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x825492c8
	ctx.lr = 0x8262C2F8;
	sub_825492C8(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262c3a8
	if (cr6.eq) goto loc_8262C3A8;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x8213cb40
	ctx.lr = 0x8262C30C;
	sub_8213CB40(ctx, base);
	// stfs f30,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,96(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f30,100(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	v61.f32[0] = log2f(v62.f32[0]);
	v61.f32[1] = log2f(v62.f32[1]);
	v61.f32[2] = log2f(v62.f32[2]);
	v61.f32[3] = log2f(v62.f32[3]);
	// vmulfp128 v60,v61,v63
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f28
	f0.f64 = double(float(f0.f64 * f28.f64));
	// beq cr6,0x8262c370
	if (cr6.eq) goto loc_8262C370;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r11,r11,r10
	r11.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r10,11444(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// b 0x8262c374
	goto loc_8262C374;
loc_8262C370:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8262C374:
	// lfs f13,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f31,f13
	ctx.f12.f64 = double(float(f31.f64 - ctx.f13.f64));
	// lfs f13,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fsel f1,f12,f0,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// bl 0x82148cb0
	ctx.lr = 0x8262C388;
	sub_82148CB0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x821607a0
	ctx.lr = 0x8262C394;
	sub_821607A0(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c0c0
	ctx.lr = 0x8262C3A8;
	sub_8213C0C0(ctx, base);
loc_8262C3A8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262c438
	if (cr6.eq) goto loc_8262C438;
	// fmr f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f29.f64;
	// bl 0x8213cb40
	ctx.lr = 0x8262C3BC;
	sub_8213CB40(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f30,104(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f30,100(r1)
	temp.f32 = float(f30.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,255
	cr6.compare<uint32_t>(ctx.r10.u32, 255, xer);
	// lvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vlogefp128 v58,v59
	ctx.fpscr.enableFlushModeUnconditional();
	v58.f32[0] = log2f(v59.f32[0]);
	v58.f32[1] = log2f(v59.f32[1]);
	v58.f32[2] = log2f(v59.f32[2]);
	v58.f32[3] = log2f(v59.f32[3]);
	// vmulfp128 v57,v58,v63
	simde_mm_store_ps(v57.f32, simde_mm_mul_ps(simde_mm_load_ps(v58.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fmuls f0,f0,f28
	f0.f64 = double(float(f0.f64 * f28.f64));
	// beq cr6,0x8262c420
	if (cr6.eq) goto loc_8262C420;
	// lbz r11,64(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 64);
	// lwz r9,232(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 232);
	// mulli r8,r11,11488
	ctx.r8.s64 = r11.s64 * 11488;
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// mullw r10,r11,r10
	ctx.r10.s64 = int64_t(r11.s32) * int64_t(ctx.r10.s32);
	// lwz r11,11444(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 11444);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// b 0x8262c424
	goto loc_8262C424;
loc_8262C420:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8262C424:
	// lfs f13,20(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f31,f13
	ctx.f12.f64 = double(float(f31.f64 - ctx.f13.f64));
	// lfs f13,16(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fsel f1,f12,f0,f13
	ctx.f1.f64 = ctx.f12.f64 >= 0.0 ? f0.f64 : ctx.f13.f64;
	// bl 0x82148cb0
	ctx.lr = 0x8262C438;
	sub_82148CB0(ctx, base);
loc_8262C438:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lwz r11,44(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// stw r11,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r11.u32);
loc_8262C448:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-40
	r12.s64 = ctx.r1.s64 + -40;
	// bl 0x823dba24
	ctx.lr = 0x8262C454;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262C458"))) PPC_WEAK_FUNC(sub_8262C458);
PPC_FUNC_IMPL(__imp__sub_8262C458) {
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
	// bl 0x82635ce0
	ctx.lr = 0x8262C470;
	sub_82635CE0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82638610
	ctx.lr = 0x8262C47C;
	sub_82638610(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stb r11,136(r31)
	PPC_STORE_U8(r31.u32 + 136, r11.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262C498"))) PPC_WEAK_FUNC(sub_8262C498);
PPC_FUNC_IMPL(__imp__sub_8262C498) {
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
	ctx.lr = 0x8262C4A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-16008
	ctx.r3.s64 = r11.s64 + -16008;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8262C4C0;
	sub_821C9790(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// lwz r8,468(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262C4E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r7,2612
	r29.s64 = ctx.r7.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x8262C4F8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x8262C508;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x8262C50C;
	sub_825EF9F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r5,7
	ctx.r5.s64 = 7;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262C538;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,56(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262C560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262C568"))) PPC_WEAK_FUNC(sub_8262C568);
PPC_FUNC_IMPL(__imp__sub_8262C568) {
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
	// bl 0x82636468
	ctx.lr = 0x8262C580;
	sub_82636468(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,580(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 580);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262C598;
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

__attribute__((alias("__imp__sub_8262C5AC"))) PPC_WEAK_FUNC(sub_8262C5AC);
PPC_FUNC_IMPL(__imp__sub_8262C5AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262C5B0"))) PPC_WEAK_FUNC(sub_8262C5B0);
PPC_FUNC_IMPL(__imp__sub_8262C5B0) {
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
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-15976
	ctx.r10.s64 = ctx.r10.s64 + -15976;
loc_8262C5D0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262c5f4
	if (cr6.eq) goto loc_8262C5F4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262c5d0
	if (cr6.eq) goto loc_8262C5D0;
loc_8262C5F4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262c620
	if (!cr6.eq) goto loc_8262C620;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// bl 0x8238e818
	ctx.lr = 0x8262C604;
	sub_8238E818(ctx, base);
	// stw r3,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r3.u32);
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
loc_8262C620:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-15984
	ctx.r10.s64 = ctx.r10.s64 + -15984;
loc_8262C62C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262c650
	if (cr6.eq) goto loc_8262C650;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262c62c
	if (cr6.eq) goto loc_8262C62C;
loc_8262C650:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262c718
	if (!cr6.eq) goto loc_8262C718;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// addi r10,r10,-22628
	ctx.r10.s64 = ctx.r10.s64 + -22628;
loc_8262C664:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262c688
	if (cr6.eq) goto loc_8262C688;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262c664
	if (cr6.eq) goto loc_8262C664;
loc_8262C688:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262c6b8
	if (!cr6.eq) goto loc_8262C6B8;
	// li r11,1
	r11.s64 = 1;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r11,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r11.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,292(r31)
	PPC_STORE_U32(r31.u32 + 292, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8262C6B8:
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
	// addi r10,r10,-15996
	ctx.r10.s64 = ctx.r10.s64 + -15996;
loc_8262C6C4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262c6e8
	if (cr6.eq) goto loc_8262C6E8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262c6c4
	if (cr6.eq) goto loc_8262C6C4;
loc_8262C6E8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262c700
	if (!cr6.eq) goto loc_8262C700;
	// li r11,2
	r11.s64 = 2;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r11.u32);
	// stw r10,292(r31)
	PPC_STORE_U32(r31.u32 + 292, ctx.r10.u32);
loc_8262C700:
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
loc_8262C718:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263a370
	ctx.lr = 0x8262C720;
	sub_8263A370(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262C734"))) PPC_WEAK_FUNC(sub_8262C734);
PPC_FUNC_IMPL(__imp__sub_8262C734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262C738"))) PPC_WEAK_FUNC(sub_8262C738);
PPC_FUNC_IMPL(__imp__sub_8262C738) {
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
	// bl 0x82637538
	ctx.lr = 0x8262C750;
	sub_82637538(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// addi r9,r11,-15956
	ctx.r9.s64 = r11.s64 + -15956;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// lwz r11,-17936(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17936);
	// addi r7,r11,45
	ctx.r7.s64 = r11.s64 + 45;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r5,r6,r10
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r10.u32);
	// lfs f0,648(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 648);
	f0.f64 = double(temp.f32);
	// lwz r4,688(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 688);
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// std r3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r3.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f0,11368(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 11368);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// stfs f0,132(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 132, temp.u32);
	// fctiwz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,1000
	cr6.compare<int32_t>(r11.s32, 1000, xer);
	// blt cr6,0x8262c7d4
	if (cr6.lt) goto loc_8262C7D4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,-12988(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -12988);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12072(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -12072);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8262c7e4
	goto loc_8262C7E4;
loc_8262C7D4:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lfs f13,31020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31020);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31304(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31304);
	ctx.f12.f64 = double(temp.f32);
loc_8262C7E4:
	// stfs f12,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 148, temp.u32);
	// stfs f13,144(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 144, temp.u32);
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

__attribute__((alias("__imp__sub_8262C800"))) PPC_WEAK_FUNC(sub_8262C800);
PPC_FUNC_IMPL(__imp__sub_8262C800) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-15956
	ctx.r10.s64 = r11.s64 + -15956;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826375a0
	ctx.lr = 0x8262C82C;
	sub_826375A0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262c844
	if (cr6.eq) goto loc_8262C844;
	// bl 0x82130588
	ctx.lr = 0x8262C840;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262C844:
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

__attribute__((alias("__imp__sub_8262C85C"))) PPC_WEAK_FUNC(sub_8262C85C);
PPC_FUNC_IMPL(__imp__sub_8262C85C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262C860"))) PPC_WEAK_FUNC(sub_8262C860);
PPC_FUNC_IMPL(__imp__sub_8262C860) {
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
	// bl 0x82635af8
	ctx.lr = 0x8262C87C;
	sub_82635AF8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r11,-15408
	r30.s64 = r11.s64 + -15408;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262C898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x8262C8A4;
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

__attribute__((alias("__imp__sub_8262C8BC"))) PPC_WEAK_FUNC(sub_8262C8BC);
PPC_FUNC_IMPL(__imp__sub_8262C8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262C8C0"))) PPC_WEAK_FUNC(sub_8262C8C0);
PPC_FUNC_IMPL(__imp__sub_8262C8C0) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r31,r10,-15392
	r31.s64 = ctx.r10.s64 + -15392;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262C8E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x8262C8F4;
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

__attribute__((alias("__imp__sub_8262C908"))) PPC_WEAK_FUNC(sub_8262C908);
PPC_FUNC_IMPL(__imp__sub_8262C908) {
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
	ctx.lr = 0x8262C910;
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
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262C930;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262c98c
	if (cr6.eq) goto loc_8262C98C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262C950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262c98c
	if (cr6.eq) goto loc_8262C98C;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268d280
	ctx.lr = 0x8262C96C;
	sub_8268D280(ctx, base);
	// lwz r11,180(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8262c98c
	if (!cr6.eq) goto loc_8262C98C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262C98C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262C98C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262C998"))) PPC_WEAK_FUNC(sub_8262C998);
PPC_FUNC_IMPL(__imp__sub_8262C998) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8262C9A0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32119
	r30.s64 = -2104950784;
	// lis r29,-32120
	r29.s64 = -2105016320;
	// addi r6,r1,100
	ctx.r6.s64 = ctx.r1.s64 + 100;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,-17936(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -17936);
	// lwz r10,-8092(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// addi r11,r11,45
	r11.s64 = r11.s64 + 45;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x8262C9D0;
	sub_8217C570(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f13,204(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 204);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lfs f12,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// stw r8,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r8.u32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// lwz r10,-17936(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -17936);
	// addi r6,r10,45
	ctx.r6.s64 = ctx.r10.s64 + 45;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f0,17032(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 17032);
	f0.f64 = double(temp.f32);
	// lwzx r4,r5,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + r11.u32);
	// lfs f10,648(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 648);
	ctx.f10.f64 = double(temp.f32);
	// lwz r3,688(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 688);
	// extsw r9,r3
	ctx.r9.s64 = ctx.r3.s32;
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r7,r8
	ctx.r7.s64 = ctx.r8.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmuls f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * f0.f64));
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x8262ca5c
	if (!cr6.lt) goto loc_8262CA5C;
	// li r11,1
	r11.s64 = 1;
	// stw r11,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r11.u32);
	// lwz r11,-8092(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -8092);
	// lwz r10,-17936(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -17936);
loc_8262CA5C:
	// addi r10,r10,45
	ctx.r10.s64 = ctx.r10.s64 + 45;
	// lfs f13,208(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 208);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// lwz r7,692(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 692);
	// lfs f10,652(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 652);
	ctx.f10.f64 = double(temp.f32);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// fmuls f6,f7,f10
	ctx.f6.f64 = double(float(ctx.f7.f64 * ctx.f10.f64));
	// fctiwz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r4,r5
	ctx.r4.s64 = ctx.r5.s32;
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f4,80(r1)
	ctx.f4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f3,f4
	ctx.f3.f64 = double(ctx.f4.s64);
	// frsp f2,f3
	ctx.f2.f64 = double(float(ctx.f3.f64));
	// fmuls f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 * f0.f64));
	// fcmpu cr6,f11,f1
	cr6.compare(ctx.f11.f64, ctx.f1.f64);
	// bge cr6,0x8262cad4
	if (!cr6.lt) goto loc_8262CAD4;
	// lwz r11,200(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// stw r9,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r9.u32);
loc_8262CAD4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262CADC"))) PPC_WEAK_FUNC(sub_8262CADC);
PPC_FUNC_IMPL(__imp__sub_8262CADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262CAE0"))) PPC_WEAK_FUNC(sub_8262CAE0);
PPC_FUNC_IMPL(__imp__sub_8262CAE0) {
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
	// bl 0x82638248
	ctx.lr = 0x8262CAF8;
	sub_82638248(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,-15364
	ctx.r9.s64 = r11.s64 + -15364;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r10,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r8.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262CB2C"))) PPC_WEAK_FUNC(sub_8262CB2C);
PPC_FUNC_IMPL(__imp__sub_8262CB2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262CB30"))) PPC_WEAK_FUNC(sub_8262CB30);
PPC_FUNC_IMPL(__imp__sub_8262CB30) {
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
	// bl 0x8263b730
	ctx.lr = 0x8262CB48;
	sub_8263B730(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262CB60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,308(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 308);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262CB70;
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

__attribute__((alias("__imp__sub_8262CB84"))) PPC_WEAK_FUNC(sub_8262CB84);
PPC_FUNC_IMPL(__imp__sub_8262CB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262CB88"))) PPC_WEAK_FUNC(sub_8262CB88);
PPC_FUNC_IMPL(__imp__sub_8262CB88) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8262cbc8
	if (!cr6.lt) goto loc_8262CBC8;
loc_8262CB9C:
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
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
	// lhz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8262cb9c
	if (cr6.lt) goto loc_8262CB9C;
loc_8262CBC8:
	// lhz r11,4(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4);
	// addis r10,r11,1
	ctx.r10.s64 = r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// sth r10,4(r3)
	PPC_STORE_U16(ctx.r3.u32 + 4, ctx.r10.u16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262CBDC"))) PPC_WEAK_FUNC(sub_8262CBDC);
PPC_FUNC_IMPL(__imp__sub_8262CBDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262CBE0"))) PPC_WEAK_FUNC(sub_8262CBE0);
PPC_FUNC_IMPL(__imp__sub_8262CBE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,72(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 72);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// b 0x822183a8
	sub_822183A8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8262CBF0"))) PPC_WEAK_FUNC(sub_8262CBF0);
PPC_FUNC_IMPL(__imp__sub_8262CBF0) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// bne cr6,0x8262cc18
	if (!cr6.eq) goto loc_8262CC18;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8262CC18:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-14792
	ctx.r5.s64 = r11.s64 + -14792;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x8262CC30;
	sub_8268B960(ctx, base);
	// stw r3,124(r31)
	PPC_STORE_U32(r31.u32 + 124, ctx.r3.u32);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r6,10
	ctx.r6.s64 = 10;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// addi r5,r10,-14816
	ctx.r5.s64 = ctx.r10.s64 + -14816;
	// addi r4,r31,88
	ctx.r4.s64 = r31.s64 + 88;
	// bl 0x8268b960
	ctx.lr = 0x8262CC4C;
	sub_8268B960(ctx, base);
	// stw r3,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r3.u32);
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

__attribute__((alias("__imp__sub_8262CC68"))) PPC_WEAK_FUNC(sub_8262CC68);
PPC_FUNC_IMPL(__imp__sub_8262CC68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// b 0x82213650
	sub_82213650(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8262CC7C"))) PPC_WEAK_FUNC(sub_8262CC7C);
PPC_FUNC_IMPL(__imp__sub_8262CC7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262CC80"))) PPC_WEAK_FUNC(sub_8262CC80);
PPC_FUNC_IMPL(__imp__sub_8262CC80) {
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
	ctx.lr = 0x8262CC88;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r30,r31,1
	r30.s64 = r31.s64 + 1;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// addi r5,r11,-14728
	ctx.r5.s64 = r11.s64 + -14728;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x82137a08
	ctx.lr = 0x8262CCB8;
	sub_82137A08(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-20156
	ctx.r3.s64 = ctx.r10.s64 + -20156;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8262CCCC;
	sub_821C9790(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// lwz r7,468(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 468);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262CCEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r25,r6,2612
	r25.s64 = ctx.r6.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x821c9790
	ctx.lr = 0x8262CD04;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x8262CD14;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x8262CD18;
	sub_825EF9F0(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,7
	ctx.r4.s64 = 7;
	// stw r5,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r5.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// stw r4,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r5,r11,-14748
	ctx.r5.s64 = r11.s64 + -14748;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x8262CD44;
	sub_82137A08(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8262CD58;
	sub_822183B0(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r28,r1,128
	r28.s64 = ctx.r1.s64 + 128;
	// addi r24,r1,160
	r24.s64 = ctx.r1.s64 + 160;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// lwz r30,-10244(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262CD78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82218888
	ctx.lr = 0x8262CD90;
	sub_82218888(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-14768
	ctx.r4.s64 = ctx.r8.s64 + -14768;
	// bl 0x825ef9a8
	ctx.lr = 0x8262CDA0;
	sub_825EF9A8(ctx, base);
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262CDBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r27,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, r27.u8);
	// li r30,2
	r30.s64 = 2;
	// bl 0x825ef9f0
	ctx.lr = 0x8262CDCC;
	sub_825EF9F0(ctx, base);
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r31,r11
	ctx.r5.u64 = r31.u64 + r11.u64;
	// lwz r11,24(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,116(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// stwx r4,r10,r11
	PPC_STORE_U32(ctx.r10.u32 + r11.u32, ctx.r4.u32);
	// stw r3,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r3.u32);
	// stw r30,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r30.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8262CDFC"))) PPC_WEAK_FUNC(sub_8262CDFC);
PPC_FUNC_IMPL(__imp__sub_8262CDFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262CE00"))) PPC_WEAK_FUNC(sub_8262CE00);
PPC_FUNC_IMPL(__imp__sub_8262CE00) {
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
	ctx.lr = 0x8262CE08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r11,1
	r11.s64 = 1;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// stb r11,136(r29)
	PPC_STORE_U8(r29.u32 + 136, r11.u8);
	// bl 0x82638610
	ctx.lr = 0x8262CE24;
	sub_82638610(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x8262CE28;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262ce64
	if (cr6.eq) goto loc_8262CE64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-18800
	ctx.r3.s64 = r11.s64 + -18800;
	// bl 0x821fa230
	ctx.lr = 0x8262CE3C;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,92(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262CE4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8262ce64
	if (cr6.eq) goto loc_8262CE64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-18820
	ctx.r3.s64 = ctx.r10.s64 + -18820;
	// b 0x8262ce6c
	goto loc_8262CE6C;
loc_8262CE64:
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r3,r10,-18844
	ctx.r3.s64 = ctx.r10.s64 + -18844;
loc_8262CE6C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,-10236
	r31.s64 = r11.s64 + -10236;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// lwz r28,4(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x8262CE88;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262CE9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,57
	ctx.r4.s64 = 57;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8268ee10
	ctx.lr = 0x8262CEBC;
	sub_8268EE10(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,108(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 108);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262CED0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r31,r8,-14716
	r31.s64 = ctx.r8.s64 + -14716;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268dce0
	ctx.lr = 0x8262CEE4;
	sub_8268DCE0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,108(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262CEF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268dce0
	ctx.lr = 0x8262CF00;
	sub_8268DCE0(ctx, base);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r11,580(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 580);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8262CF14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262CF28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8262CF30"))) PPC_WEAK_FUNC(sub_8262CF30);
PPC_FUNC_IMPL(__imp__sub_8262CF30) {
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
	ctx.lr = 0x8262CF38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r9,-14692
	r29.s64 = ctx.r9.s64 + -14692;
	// lwz r31,-10244(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// addi r28,r8,2612
	r28.s64 = ctx.r8.s64 + 2612;
	// lwz r7,468(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262CF68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// bl 0x82218888
	ctx.lr = 0x8262CF80;
	sub_82218888(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262CF88"))) PPC_WEAK_FUNC(sub_8262CF88);
PPC_FUNC_IMPL(__imp__sub_8262CF88) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,-14636
	ctx.r10.s64 = r11.s64 + -14636;
	// lwz r8,20(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_8262CFB0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x8262cfd4
	if (cr6.eq) goto loc_8262CFD4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262cfb0
	if (cr6.eq) goto loc_8262CFB0;
loc_8262CFD4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262d0f0
	if (cr6.eq) goto loc_8262D0F0;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lbz r11,376(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 376);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262d0dc
	if (!cr6.eq) goto loc_8262D0DC;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-14664
	ctx.r10.s64 = ctx.r10.s64 + -14664;
loc_8262CFFC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262d020
	if (cr6.eq) goto loc_8262D020;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262cffc
	if (cr6.eq) goto loc_8262CFFC;
loc_8262D020:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262d0dc
	if (!cr6.eq) goto loc_8262D0DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D03C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,124(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 124);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bge cr6,0x8262d0dc
	if (!cr6.lt) goto loc_8262D0DC;
	// lwz r10,120(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// rlwinm r11,r3,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x826c72d8
	ctx.lr = 0x8262D058;
	sub_826C72D8(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,24996(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// bl 0x826cb780
	ctx.lr = 0x8262D068;
	sub_826CB780(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8262d0dc
	if (cr6.eq) goto loc_8262D0DC;
	// lbz r11,8(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262d0dc
	if (!cr6.eq) goto loc_8262D0DC;
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lbz r10,375(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 375);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262d0dc
	if (cr6.eq) goto loc_8262D0DC;
	// lwz r10,616(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 616);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262d0b4
	if (cr6.eq) goto loc_8262D0B4;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D0B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8262d0b8
	goto loc_8262D0B8;
loc_8262D0B4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8262D0B8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bne cr6,0x8262d0d4
	if (!cr6.eq) goto loc_8262D0D4;
	// li r4,42
	ctx.r4.s64 = 42;
	// b 0x8262d0ec
	goto loc_8262D0EC;
loc_8262D0D4:
	// li r4,41
	ctx.r4.s64 = 41;
	// b 0x8262d0ec
	goto loc_8262D0EC;
loc_8262D0DC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
loc_8262D0EC:
	// bl 0x8220f040
	ctx.lr = 0x8262D0F0;
	sub_8220F040(ctx, base);
loc_8262D0F0:
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

__attribute__((alias("__imp__sub_8262D108"))) PPC_WEAK_FUNC(sub_8262D108);
PPC_FUNC_IMPL(__imp__sub_8262D108) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// lhz r11,116(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262d14c
	if (cr6.eq) goto loc_8262D14C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,112(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// rlwinm r8,r3,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
loc_8262D14C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262D160"))) PPC_WEAK_FUNC(sub_8262D160);
PPC_FUNC_IMPL(__imp__sub_8262D160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8262D168;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lhz r4,124(r28)
	ctx.r4.u64 = PPC_LOAD_U16(r28.u32 + 124);
	// lwz r10,572(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 572);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D184;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82638c50
	ctx.lr = 0x8262D18C;
	sub_82638C50(ctx, base);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r8,496(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 496);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262D1A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r7,7
	ctx.r7.s64 = 7;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r29,0
	r29.s64 = 0;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8262d3a8
	if (cr6.eq) goto loc_8262D3A8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-12116
	ctx.r3.s64 = r11.s64 + -12116;
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8262D1D4;
	sub_821C9790(ctx, base);
	// li r19,1
	r19.s64 = 1;
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// stw r19,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r19.u32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262D1FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r7,640(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 640);
	// lwz r31,76(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262D214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// bgt cr6,0x8262d29c
	if (cr6.gt) goto loc_8262D29C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// rlwinm r30,r31,2,0,29
	r30.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r27,r11,2672
	r27.s64 = r11.s64 + 2672;
loc_8262D22C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x825ef9f0
	ctx.lr = 0x8262D234;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,120(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 120);
	// lwz r11,-10244(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwzx r11,r9,r30
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r30.u32);
	// addi r4,r11,200
	ctx.r4.s64 = r11.s64 + 200;
	// bl 0x82218310
	ctx.lr = 0x8262D264;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x827227b8
	ctx.lr = 0x8262D274;
	sub_827227B8(ctx, base);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r7,640(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 640);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262D294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// ble cr6,0x8262d22c
	if (!cr6.gt) goto loc_8262D22C;
loc_8262D29C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x825ef9f0
	ctx.lr = 0x8262D2A4;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D2B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// ble cr6,0x8262d3a8
	if (!cr6.gt) goto loc_8262D3A8;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r21,2
	r21.s64 = 2;
	// addi r29,r7,20292
	r29.s64 = ctx.r7.s64 + 20292;
	// addi r27,r6,-13284
	r27.s64 = ctx.r6.s64 + -13284;
	// addi r26,r5,-14596
	r26.s64 = ctx.r5.s64 + -14596;
	// addi r25,r4,2836
	r25.s64 = ctx.r4.s64 + 2836;
	// addi r24,r8,2604
	r24.s64 = ctx.r8.s64 + 2604;
	// addi r23,r9,2688
	r23.s64 = ctx.r9.s64 + 2688;
	// addi r22,r10,2680
	r22.s64 = ctx.r10.s64 + 2680;
	// addi r31,r11,3998
	r31.s64 = r11.s64 + 3998;
loc_8262D308:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x825ef9f0
	ctx.lr = 0x8262D310;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D324;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// bl 0x827227b8
	ctx.lr = 0x8262D334;
	sub_827227B8(ctx, base);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x827227b8
	ctx.lr = 0x8262D344;
	sub_827227B8(ctx, base);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x827227b8
	ctx.lr = 0x8262D354;
	sub_827227B8(ctx, base);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x827227b8
	ctx.lr = 0x8262D364;
	sub_827227B8(ctx, base);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x827227b8
	ctx.lr = 0x8262D374;
	sub_827227B8(ctx, base);
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r21.u32);
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x8262D388;
	sub_82722678(ctx, base);
	// stw r19,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r19.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x82722678
	ctx.lr = 0x8262D39C;
	sub_82722678(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r20
	cr6.compare<int32_t>(r30.s32, r20.s32, xer);
	// blt cr6,0x8262d308
	if (cr6.lt) goto loc_8262D308;
loc_8262D3A8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262cf88
	ctx.lr = 0x8262D3B0;
	sub_8262CF88(ctx, base);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8262D3B8"))) PPC_WEAK_FUNC(sub_8262D3B8);
PPC_FUNC_IMPL(__imp__sub_8262D3B8) {
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
	// bl 0x826391f8
	ctx.lr = 0x8262D3C8;
	sub_826391F8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-14588
	ctx.r4.s64 = ctx.r10.s64 + -14588;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x8262D3E0;
	sub_8268B770(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262D3F0"))) PPC_WEAK_FUNC(sub_8262D3F0);
PPC_FUNC_IMPL(__imp__sub_8262D3F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,208(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8262D408"))) PPC_WEAK_FUNC(sub_8262D408);
PPC_FUNC_IMPL(__imp__sub_8262D408) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x826355a8
	ctx.lr = 0x8262D420;
	sub_826355A8(ctx, base);
	// lis r11,-32119
	r11.s64 = -2104950784;
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-17936(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -17936);
	// lwz r10,-8092(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -8092);
	// addi r8,r11,45
	ctx.r8.s64 = r11.s64 + 45;
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r11,448
	ctx.r4.s64 = r11.s64 + 448;
	// lwzx r3,r7,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	// bl 0x8217c570
	ctx.lr = 0x8262D454;
	sub_8217C570(ctx, base);
	// lfs f0,144(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 144);
	f0.f64 = double(temp.f32);
	// lfs f13,128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f11,80(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// bge cr6,0x8262d4a8
	if (!cr6.lt) goto loc_8262D4A8;
	// lfs f0,148(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 148);
	f0.f64 = double(temp.f32);
	// lfs f13,132(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f0,f13
	ctx.f12.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f11,84(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f12
	cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// bge cr6,0x8262d4a8
	if (!cr6.lt) goto loc_8262D4A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-15408
	r31.s64 = ctx.r10.s64 + -15408;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262D4A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8262d4c8
	goto loc_8262D4C8;
loc_8262D4A8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-15408
	r31.s64 = ctx.r10.s64 + -15408;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262D4C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r5,1
	ctx.r5.s64 = 1;
loc_8262D4C8:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8262D4D0;
	sub_825EE0E0(ctx, base);
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

__attribute__((alias("__imp__sub_8262D4E4"))) PPC_WEAK_FUNC(sub_8262D4E4);
PPC_FUNC_IMPL(__imp__sub_8262D4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262D4E8"))) PPC_WEAK_FUNC(sub_8262D4E8);
PPC_FUNC_IMPL(__imp__sub_8262D4E8) {
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
	ctx.lr = 0x8262D4F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r10,-14528
	ctx.r4.s64 = ctx.r10.s64 + -14528;
	// lwz r11,18508(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// lwz r5,508(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 508);
	// bl 0x82218788
	ctx.lr = 0x8262D51C;
	sub_82218788(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r4,r9,-14548
	ctx.r4.s64 = ctx.r9.s64 + -14548;
	// bl 0x82218310
	ctx.lr = 0x8262D52C;
	sub_82218310(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r7,-14556
	r29.s64 = ctx.r7.s64 + -14556;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,468(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262D54C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262D558;
	sub_825EE2D8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262D560"))) PPC_WEAK_FUNC(sub_8262D560);
PPC_FUNC_IMPL(__imp__sub_8262D560) {
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8262D568;
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f30.u64);
	// stfd f31,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635538
	ctx.lr = 0x8262D57C;
	sub_82635538(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262d4e8
	ctx.lr = 0x8262D584;
	sub_8262D4E8(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8262D590;
	sub_822A39C8(ctx, base);
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// lwz r11,17268(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262d5c0
	if (cr6.eq) goto loc_8262D5C0;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8262d5dc
	if (!cr6.gt) goto loc_8262D5DC;
	// lwz r11,136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// b 0x8262d5d0
	goto loc_8262D5D0;
loc_8262D5C0:
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8262d5dc
	if (!cr6.gt) goto loc_8262D5DC;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
loc_8262D5D0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8262d5e0
	if (!cr6.eq) goto loc_8262D5E0;
loc_8262D5DC:
	// li r11,0
	r11.s64 = 0;
loc_8262D5E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262dba0
	if (cr6.eq) goto loc_8262DBA0;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,18508(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 18508);
	// bl 0x826b95b0
	ctx.lr = 0x8262D5FC;
	sub_826B95B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,18508(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + 18508);
	// lwz r24,8(r11)
	r24.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826b92c8
	ctx.lr = 0x8262D610;
	sub_826B92C8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r11,r27,1
	r11.s64 = r27.s64 + 1;
	// cmpwi cr6,r11,12
	cr6.compare<int32_t>(r11.s32, 12, xer);
	// mr r23,r11
	r23.u64 = r11.u64;
	// blt cr6,0x8262d628
	if (cr6.lt) goto loc_8262D628;
	// li r23,12
	r23.s64 = 12;
loc_8262D628:
	// lwz r22,52(r26)
	r22.u64 = PPC_LOAD_U32(r26.u32 + 52);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8238f998
	ctx.lr = 0x8262D634;
	sub_8238F998(ctx, base);
	// lwz r30,18508(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 18508);
	// lwz r3,24(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// bl 0x82396058
	ctx.lr = 0x8262D640;
	sub_82396058(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826b9928
	ctx.lr = 0x8262D64C;
	sub_826B9928(ctx, base);
	// lwz r11,52(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 52);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8238f6b0
	ctx.lr = 0x8262D65C;
	sub_8238F6B0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8262d674
	if (!cr6.eq) goto loc_8262D674;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,-14148
	ctx.r4.s64 = r11.s64 + -14148;
	// b 0x8262d6ac
	goto loc_8262D6AC;
loc_8262D674:
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x8262d688
	if (!cr6.eq) goto loc_8262D688;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,-14176
	ctx.r4.s64 = r11.s64 + -14176;
	// b 0x8262d6ac
	goto loc_8262D6AC;
loc_8262D688:
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x8262d69c
	if (!cr6.eq) goto loc_8262D69C;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,-14204
	ctx.r4.s64 = r11.s64 + -14204;
	// b 0x8262d6ac
	goto loc_8262D6AC;
loc_8262D69C:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x8262d6e0
	if (!cr6.eq) goto loc_8262D6E0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,5836
	ctx.r4.s64 = r11.s64 + 5836;
loc_8262D6AC:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262D6B4;
	sub_82218310(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r21,r9,-14220
	r21.s64 = ctx.r9.s64 + -14220;
	// lwz r8,468(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262D6D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262D6E0;
	sub_825EE2D8(ctx, base);
loc_8262D6E0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lwz r29,-10244(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// rlwinm r10,r27,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-26544
	ctx.r9.s64 = r11.s64 + -26544;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x82218310
	ctx.lr = 0x8262D6FC;
	sub_82218310(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r21,r8,-14244
	r21.s64 = ctx.r8.s64 + -14244;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r7,-14252
	ctx.r5.s64 = ctx.r7.s64 + -14252;
	// bl 0x82218458
	ctx.lr = 0x8262D71C;
	sub_82218458(ctx, base);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262D728;
	sub_82218310(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r21,r5,-14264
	r21.s64 = ctx.r5.s64 + -14264;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,468(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 468);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8262D748;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262D754;
	sub_825EE2D8(ctx, base);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r29,-10244(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x822a8d98
	ctx.lr = 0x8262D760;
	sub_822A8D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x8262D76C;
	sub_82218310(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r26,r11,-14284
	r26.s64 = r11.s64 + -14284;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822183b0
	ctx.lr = 0x8262D784;
	sub_822183B0(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262D790;
	sub_82218310(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r26,r9,-14296
	r26.s64 = ctx.r9.s64 + -14296;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,468(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262D7B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262D7BC;
	sub_825EE2D8(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmpwi cr6,r27,12
	cr6.compare<int32_t>(r27.s32, 12, xer);
	// addi r26,r11,-13556
	r26.s64 = r11.s64 + -13556;
	// lwz r29,-10244(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bne cr6,0x8262d878
	if (!cr6.eq) goto loc_8262D878;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,-14304
	ctx.r4.s64 = r11.s64 + -14304;
	// bl 0x82218310
	ctx.lr = 0x8262D7E0;
	sub_82218310(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r10,-14316
	ctx.r4.s64 = ctx.r10.s64 + -14316;
	// bl 0x82218310
	ctx.lr = 0x8262D7F4;
	sub_82218310(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// addi r25,r9,-14336
	r25.s64 = ctx.r9.s64 + -14336;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r5,r8,-5820
	ctx.r5.s64 = ctx.r8.s64 + -5820;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// bl 0x82218458
	ctx.lr = 0x8262D818;
	sub_82218458(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262D824;
	sub_82218310(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r27,r6,-14348
	r27.s64 = ctx.r6.s64 + -14348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,468(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 468);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8262D844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262D850;
	sub_825EE2D8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r4,-32247
	ctx.r4.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r4,-14360
	r29.s64 = ctx.r4.s64 + -14360;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D86C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f1,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// b 0x8262d984
	goto loc_8262D984;
loc_8262D878:
	// addi r10,r23,38
	ctx.r10.s64 = r23.s64 + 38;
	// lwz r11,18508(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 18508);
	// addi r9,r27,38
	ctx.r9.s64 = r27.s64 + 38;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r4,r6,-14316
	ctx.r4.s64 = ctx.r6.s64 + -14316;
	// lfsx f31,r8,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	f31.f64 = double(temp.f32);
	// fctiwz f0,f31
	f0.s64 = (f31.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f31.f64));
	// stfd f0,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, f0.u64);
	// lfsx f30,r7,r11
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	f30.f64 = double(temp.f32);
	// lwz r27,84(r1)
	r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82218310
	ctx.lr = 0x8262D8AC;
	sub_82218310(ctx, base);
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r25,r5,-14336
	r25.s64 = ctx.r5.s64 + -14336;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// bl 0x82218458
	ctx.lr = 0x8262D8CC;
	sub_82218458(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262D8D8;
	sub_82218310(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r27,r11,-14348
	r27.s64 = r11.s64 + -14348;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262D8F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262D904;
	sub_825EE2D8(ctx, base);
	// extsw r9,r24
	ctx.r9.s64 = r24.s32;
	// fsubs f13,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - f30.f64));
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r8,-14360
	r29.s64 = ctx.r8.s64 + -14360;
	// lwz r4,468(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 468);
	// fctiwz f11,f13
	ctx.f11.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f12
	ctx.f10.f64 = double(ctx.f12.s64);
	// frsp f7,f10
	ctx.f7.f64 = double(float(ctx.f10.f64));
	// fsubs f5,f7,f30
	ctx.f5.f64 = double(float(ctx.f7.f64 - f30.f64));
	// fctiwz f4,f5
	ctx.f4.s64 = (ctx.f5.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f4.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f3,80(r1)
	ctx.f3.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// frsp f6,f8
	ctx.f6.f64 = double(float(ctx.f8.f64));
	// frsp f1,f2
	ctx.f1.f64 = double(float(ctx.f2.f64));
	// fdivs f31,f1,f6
	f31.f64 = double(float(ctx.f1.f64 / ctx.f6.f64));
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8262D980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_8262D984:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x825ee188
	ctx.lr = 0x8262D98C;
	sub_825EE188(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r29,r11,-14380
	r29.s64 = r11.s64 + -14380;
	// addi r5,r10,-14388
	ctx.r5.s64 = ctx.r10.s64 + -14388;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// bl 0x82218458
	ctx.lr = 0x8262D9AC;
	sub_82218458(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262D9B8;
	sub_82218310(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r27,r8,-12196
	r27.s64 = ctx.r8.s64 + -12196;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,468(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 468);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262D9D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262D9E4;
	sub_825EE2D8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826bc008
	ctx.lr = 0x8262D9EC;
	sub_826BC008(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826bbf80
	ctx.lr = 0x8262D9F8;
	sub_826BBF80(ctx, base);
	// lwz r10,12(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// lwz r11,8(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// subf r29,r3,r29
	r29.s64 = r29.s64 - ctx.r3.s64;
	// mr r27,r10
	r27.u64 = ctx.r10.u64;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bgt cr6,0x8262da14
	if (cr6.gt) goto loc_8262DA14;
	// mr r27,r11
	r27.u64 = r11.u64;
loc_8262DA14:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826bbf80
	ctx.lr = 0x8262DA1C;
	sub_826BBF80(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,-10244(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// subf r27,r3,r27
	r27.s64 = r27.s64 - ctx.r3.s64;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r25,r10,-14408
	r25.s64 = ctx.r10.s64 + -14408;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r5,r9,-14416
	ctx.r5.s64 = ctx.r9.s64 + -14416;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x82218458
	ctx.lr = 0x8262DA48;
	sub_82218458(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262DA54;
	sub_82218310(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r24,r7,-14428
	r24.s64 = ctx.r7.s64 + -14428;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,468(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262DA74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262DA80;
	sub_825EE2D8(ctx, base);
	// extsw r5,r29
	ctx.r5.s64 = r29.s32;
	// extsw r4,r27
	ctx.r4.s64 = r27.s32;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// std r5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r4,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r4.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addi r29,r3,-14440
	r29.s64 = ctx.r3.s64 + -14440;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fdivs f31,f10,f9
	f31.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262DAC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825ee188
	ctx.lr = 0x8262DAD4;
	sub_825EE188(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8238f998
	ctx.lr = 0x8262DADC;
	sub_8238F998(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r7,r8,-25924
	ctx.r7.s64 = ctx.r8.s64 + -25924;
	// lwz r6,24(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r5,r7
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r7.u32);
	// bl 0x82218310
	ctx.lr = 0x8262DAFC;
	sub_82218310(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r27,r11,-14456
	r27.s64 = r11.s64 + -14456;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262DB1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262DB28;
	sub_825EE2D8(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r29,-10244(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x826bbee8
	ctx.lr = 0x8262DB34;
	sub_826BBEE8(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r28,r3,1
	r28.s64 = ctx.r3.s64 + 1;
	// addi r4,r9,-14472
	ctx.r4.s64 = ctx.r9.s64 + -14472;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x8262DB48;
	sub_82218310(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r27,r8,-14492
	r27.s64 = ctx.r8.s64 + -14492;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82218458
	ctx.lr = 0x8262DB68;
	sub_82218458(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262DB74;
	sub_82218310(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r6,-14508
	r29.s64 = ctx.r6.s64 + -14508;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,468(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 468);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8262DB94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262DBA0;
	sub_825EE2D8(ctx, base);
loc_8262DBA0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8262DBB0"))) PPC_WEAK_FUNC(sub_8262DBB0);
PPC_FUNC_IMPL(__imp__sub_8262DBB0) {
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
	// bl 0x82637538
	ctx.lr = 0x8262DBCC;
	sub_82637538(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// addi r30,r31,68
	r30.s64 = r31.s64 + 68;
	// stw r10,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r10.u32);
	// addi r4,r9,21428
	ctx.r4.s64 = ctx.r9.s64 + 21428;
	// addi r3,r30,4
	ctx.r3.s64 = r30.s64 + 4;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x823db670
	ctx.lr = 0x8262DBF0;
	sub_823DB670(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r6,r8,-14100
	ctx.r6.s64 = ctx.r8.s64 + -14100;
	// addi r5,r7,-14112
	ctx.r5.s64 = ctx.r7.s64 + -14112;
	// stw r6,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r6.u32);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// stw r5,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r5.u32);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-18684
	ctx.r5.s64 = r11.s64 + -18684;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10224);
	// bl 0x8268b960
	ctx.lr = 0x8262DC24;
	sub_8268B960(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f0,11364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	f0.f64 = double(temp.f32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// stfs f0,192(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 192, temp.u32);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// stfs f0,196(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 196, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f13,31020(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 31020);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12988(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -12988);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-14120(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -14120);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// stfs f13,184(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 184, temp.u32);
	// stfs f13,188(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 188, temp.u32);
	// stfs f12,204(r31)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r31.u32 + 204, temp.u32);
	// stfs f11,208(r31)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(r31.u32 + 208, temp.u32);
	// stfs f10,176(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
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

__attribute__((alias("__imp__sub_8262DC88"))) PPC_WEAK_FUNC(sub_8262DC88);
PPC_FUNC_IMPL(__imp__sub_8262DC88) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-68
	ctx.r3.s64 = ctx.r3.s64 + -68;
	// b 0x8262ef28
	sub_8262EF28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8262DC90"))) PPC_WEAK_FUNC(sub_8262DC90);
PPC_FUNC_IMPL(__imp__sub_8262DC90) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-68
	ctx.r3.s64 = ctx.r3.s64 + -68;
	// b 0x8262c908
	sub_8262C908(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8262DC98"))) PPC_WEAK_FUNC(sub_8262DC98);
PPC_FUNC_IMPL(__imp__sub_8262DC98) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// bl 0x82622f68
	ctx.lr = 0x8262DCB8;
	sub_82622F68(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262DCCC;
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

__attribute__((alias("__imp__sub_8262DCE0"))) PPC_WEAK_FUNC(sub_8262DCE0);
PPC_FUNC_IMPL(__imp__sub_8262DCE0) {
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
	ctx.lr = 0x8262DCE8;
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x826355a8
	ctx.lr = 0x8262DCF8;
	sub_826355A8(ctx, base);
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lwz r3,-10220(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10220);
	// lbz r11,375(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 375);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262dfb4
	if (cr6.eq) goto loc_8262DFB4;
	// lbz r11,629(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262dfb4
	if (cr6.eq) goto loc_8262DFB4;
	// bl 0x82620130
	ctx.lr = 0x8262DD1C;
	sub_82620130(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,11364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	f0.f64 = double(temp.f32);
	// fmuls f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// stfs f31,176(r31)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r31.u32 + 176, temp.u32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262DD40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r30,4
	r30.s64 = 4;
	// stfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// stw r30,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r30.u32);
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// addi r29,r8,-13528
	r29.s64 = ctx.r8.s64 + -13528;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82203058
	ctx.lr = 0x8262DD64;
	sub_82203058(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,468(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 468);
	// lfs f31,176(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	f31.f64 = double(temp.f32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262DD7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f31,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stw r30,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r6,r1,104
	ctx.r6.s64 = ctx.r1.s64 + 104;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82203058
	ctx.lr = 0x8262DD94;
	sub_82203058(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,468(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 468);
	// lfs f31,176(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 176);
	f31.f64 = double(temp.f32);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8262DDAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stfs f31,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stw r30,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r30.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82203058
	ctx.lr = 0x8262DDC4;
	sub_82203058(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r11,-13552
	r30.s64 = r11.s64 + -13552;
	// lwz r9,468(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 468);
	// lwz r29,200(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 200);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262DDE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8262DDF0;
	sub_825EE0E0(ctx, base);
	// lis r30,-32112
	r30.s64 = -2104492032;
	// lwz r11,25004(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 25004);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8262de2c
	if (!cr6.eq) goto loc_8262DE2C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r29,r10,-15392
	r29.s64 = ctx.r10.s64 + -15392;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262DE1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x8262DE28;
	sub_825EE0E0(ctx, base);
	// lwz r11,25004(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 25004);
loc_8262DE2C:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r3,-10220(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10220);
	// stw r11,25004(r30)
	PPC_STORE_U32(r30.u32 + 25004, r11.u32);
	// bl 0x82620068
	ctx.lr = 0x8262DE3C;
	sub_82620068(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8262dfe8
	if (cr6.eq) goto loc_8262DFE8;
	// lwz r3,-10220(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262DE5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r27,16
	r27.s64 = 16;
	// li r28,32
	r28.s64 = 32;
	// li r26,48
	r26.s64 = 48;
	// lvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lvx128 v61,r9,r27
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r11,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r9,r28
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r9,r26
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r30
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v57,v63,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v57.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v58.f32)));
	// stvx128 v57,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,548(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 548);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262DEB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32252
	ctx.r5.s64 = -2113667072;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lvx128 v0,r0,r30
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r4,r31,160
	ctx.r4.s64 = r31.s64 + 160;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,27552(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 27552);
	f0.f64 = double(temp.f32);
	// lvx128 v56,r0,r6
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vor128 v13,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)v56.u8));
	// lvlx128 v55,r0,r11
	temp.u32 = r11.u32;
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v12,v55,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v55.u32), 0xFF));
	// vmaddfp v11,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v56,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8262c998
	ctx.lr = 0x8262DEF8;
	sub_8262C998(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f7ca8
	ctx.lr = 0x8262DF08;
	sub_821F7CA8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262dfe8
	if (cr6.eq) goto loc_8262DFE8;
	// li r4,13
	ctx.r4.s64 = 13;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// bl 0x821f9248
	ctx.lr = 0x8262DF20;
	sub_821F9248(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,-12100
	ctx.r3.s64 = r11.s64 + -12100;
	// addi r30,r10,-21000
	r30.s64 = ctx.r10.s64 + -21000;
	// addi r29,r9,-22108
	r29.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8262DF40;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8262DF54;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262dfe8
	if (cr6.eq) goto loc_8262DFE8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262DF6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r31,48
	r11.s64 = r31.s64 + 48;
	// lvx128 v53,r3,r27
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,544
	ctx.r9.s64 = 544;
	// stvx128 v53,r31,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r3,r28
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v51,r3,r26
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v50,v51,v51
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_load_si128((simde__m128i*)v51.u8));
	// stvx128 v51,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,-10220(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + -10220);
	// lvx128 v49,r10,r9
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v48,v50,v49
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v48.f32, simde_mm_add_ps(simde_mm_load_ps(v50.f32), simde_mm_load_ps(v49.f32)));
	// stvx128 v48,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_8262DFB4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-15392
	r31.s64 = ctx.r10.s64 + -15392;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262DFD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x8262DFDC;
	sub_825EE0E0(ctx, base);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r11,0
	r11.s64 = 0;
	// stw r11,25004(r8)
	PPC_STORE_U32(ctx.r8.u32 + 25004, r11.u32);
loc_8262DFE8:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8262DFF4"))) PPC_WEAK_FUNC(sub_8262DFF4);
PPC_FUNC_IMPL(__imp__sub_8262DFF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262DFF8"))) PPC_WEAK_FUNC(sub_8262DFF8);
PPC_FUNC_IMPL(__imp__sub_8262DFF8) {
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
	// bl 0x82637a40
	ctx.lr = 0x8262E014;
	sub_82637A40(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// bl 0x82620068
	ctx.lr = 0x8262E020;
	sub_82620068(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262e040
	if (cr6.eq) goto loc_8262E040;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// bl 0x82620068
	ctx.lr = 0x8262E030;
	sub_82620068(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262E040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262E040:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r10,-13500
	r31.s64 = ctx.r10.s64 + -13500;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262E05C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x8262E068;
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

__attribute__((alias("__imp__sub_8262E080"))) PPC_WEAK_FUNC(sub_8262E080);
PPC_FUNC_IMPL(__imp__sub_8262E080) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-16556
	ctx.r10.s64 = r11.s64 + -16556;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x826375a0
	ctx.lr = 0x8262E0AC;
	sub_826375A0(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262e0c4
	if (cr6.eq) goto loc_8262E0C4;
	// bl 0x82130588
	ctx.lr = 0x8262E0C0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262E0C4:
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

__attribute__((alias("__imp__sub_8262E0DC"))) PPC_WEAK_FUNC(sub_8262E0DC);
PPC_FUNC_IMPL(__imp__sub_8262E0DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262E0E0"))) PPC_WEAK_FUNC(sub_8262E0E0);
PPC_FUNC_IMPL(__imp__sub_8262E0E0) {
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
	ctx.lr = 0x8262E0E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82635538
	ctx.lr = 0x8262E0F4;
	sub_82635538(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,84(r30)
	PPC_STORE_U32(r30.u32 + 84, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,480(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 480);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262E114;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,304(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 304);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8262E124;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,88(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// li r31,1
	r31.s64 = 1;
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// ble cr6,0x8262e16c
	if (!cr6.gt) goto loc_8262E16C;
loc_8262E134:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262E14C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,308(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 308);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262E15C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,88(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 88);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r7
	cr6.compare<int32_t>(r31.s32, ctx.r7.s32, xer);
	// blt cr6,0x8262e134
	if (cr6.lt) goto loc_8262E134;
loc_8262E16C:
	// addi r29,r30,96
	r29.s64 = r30.s64 + 96;
	// mr r11,r29
	r11.u64 = r29.u64;
loc_8262E174:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8262e174
	if (!cr6.eq) goto loc_8262E174;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262e1e0
	if (cr6.eq) goto loc_8262E1E0;
	// mr r31,r29
	r31.u64 = r29.u64;
	// subfic r30,r30,-96
	xer.ca = r30.u32 <= 4294967200;
	r30.s64 = -96 - r30.s64;
loc_8262E1A0:
	// lbz r11,0(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x8262E1AC;
	sub_823DF058(ctx, base);
	// stb r3,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r3.u8);
	// mr r11,r29
	r11.u64 = r29.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_8262E1B8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8262e1b8
	if (!cr6.eq) goto loc_8262E1B8;
	// subf r11,r29,r11
	r11.s64 = r11.s64 - r29.s64;
	// add r10,r30,r31
	ctx.r10.u64 = r30.u64 + r31.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// rotlwi r8,r9,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmplw cr6,r10,r8
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, xer);
	// blt cr6,0x8262e1a0
	if (cr6.lt) goto loc_8262E1A0;
loc_8262E1E0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x8262E1F8;
	sub_82213B80(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262E200"))) PPC_WEAK_FUNC(sub_8262E200);
PPC_FUNC_IMPL(__imp__sub_8262E200) {
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
	// lwz r4,92(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183a8
	ctx.lr = 0x8262E21C;
	sub_822183A8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8262E220:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8262e220
	if (!cr6.eq) goto loc_8262E220;
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
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
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262E258"))) PPC_WEAK_FUNC(sub_8262E258);
PPC_FUNC_IMPL(__imp__sub_8262E258) {
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
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,-13480
	ctx.r10.s64 = ctx.r10.s64 + -13480;
loc_8262E278:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262e29c
	if (cr6.eq) goto loc_8262E29C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262e278
	if (cr6.eq) goto loc_8262E278;
loc_8262E29C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262e2d0
	if (!cr6.eq) goto loc_8262E2D0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822175c8
	ctx.lr = 0x8262E2B4;
	sub_822175C8(ctx, base);
	// stw r3,92(r31)
	PPC_STORE_U32(r31.u32 + 92, ctx.r3.u32);
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
loc_8262E2D0:
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,10504
	ctx.r10.s64 = ctx.r10.s64 + 10504;
loc_8262E2DC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262e300
	if (cr6.eq) goto loc_8262E300;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262e2dc
	if (cr6.eq) goto loc_8262E2DC;
loc_8262E300:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262e350
	if (!cr6.eq) goto loc_8262E350;
	// addi r11,r31,96
	r11.s64 = r31.s64 + 96;
	// li r10,31
	ctx.r10.s64 = 31;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r11,r7
	ctx.r9.s64 = ctx.r7.s64 - r11.s64;
loc_8262E318:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262e330
	if (cr6.eq) goto loc_8262E330;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8262e318
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8262E318;
loc_8262E330:
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8262E350:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82639ff8
	ctx.lr = 0x8262E358;
	sub_82639FF8(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262E36C"))) PPC_WEAK_FUNC(sub_8262E36C);
PPC_FUNC_IMPL(__imp__sub_8262E36C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262E370"))) PPC_WEAK_FUNC(sub_8262E370);
PPC_FUNC_IMPL(__imp__sub_8262E370) {
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
	ctx.lr = 0x8262E378;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,18508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18508);
	// bl 0x826b95b0
	ctx.lr = 0x8262E390;
	sub_826B95B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,18508(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 18508);
	// lwz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x826b92c8
	ctx.lr = 0x8262E3A0;
	sub_826B92C8(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-26544
	ctx.r8.s64 = ctx.r10.s64 + -26544;
	// lwz r31,-10244(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// bl 0x82218310
	ctx.lr = 0x8262E3C0;
	sub_82218310(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// addi r28,r7,-14244
	r28.s64 = ctx.r7.s64 + -14244;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r5,-13464
	ctx.r5.s64 = ctx.r5.s64 + -13464;
	// bl 0x82218458
	ctx.lr = 0x8262E3E0;
	sub_82218458(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10244(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262E3EC;
	sub_82218310(ctx, base);
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r11,-14264
	r29.s64 = r11.s64 + -14264;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,468(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262E40C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ee2d8
	ctx.lr = 0x8262E418;
	sub_825EE2D8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262E420"))) PPC_WEAK_FUNC(sub_8262E420);
PPC_FUNC_IMPL(__imp__sub_8262E420) {
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
	// bne cr6,0x8262e4a0
	if (!cr6.eq) goto loc_8262E4A0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// sth r10,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r10.u16);
	// rlwinm r3,r10,2,14,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0x3FFFC;
	// bl 0x82130528
	ctx.lr = 0x8262E45C;
	sub_82130528(ctx, base);
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262e494
	if (cr6.eq) goto loc_8262E494;
	// li r11,0
	r11.s64 = 0;
loc_8262E470:
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
	// blt cr6,0x8262e470
	if (cr6.lt) goto loc_8262E470;
loc_8262E494:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8262E49C;
	sub_82130588(ctx, base);
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_8262E4A0:
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

__attribute__((alias("__imp__sub_8262E4D0"))) PPC_WEAK_FUNC(sub_8262E4D0);
PPC_FUNC_IMPL(__imp__sub_8262E4D0) {
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
	ctx.lr = 0x8262E4D8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x8263a260
	ctx.lr = 0x8262E4EC;
	sub_8263A260(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262e54c
	if (!cr6.eq) goto loc_8262E54C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 262144;
	// addi r9,r9,976
	ctx.r9.s64 = ctx.r9.s64 + 976;
	// cmplw cr6,r31,r9
	cr6.compare<uint32_t>(r31.u32, ctx.r9.u32, xer);
	// bne cr6,0x8262e54c
	if (!cr6.eq) goto loc_8262E54C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,53
	cr6.compare<int32_t>(r11.s32, 53, xer);
	// bne cr6,0x8262e54c
	if (!cr6.eq) goto loc_8262E54C;
	// lbz r11,136(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 136);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r4,9
	ctx.r4.s64 = 9;
	// addi r3,r11,-22444
	ctx.r3.s64 = r11.s64 + -22444;
	// bne cr6,0x8262e544
	if (!cr6.eq) goto loc_8262E544;
	// li r4,10
	ctx.r4.s64 = 10;
loc_8262E544:
	// bl 0x8268ee10
	ctx.lr = 0x8262E548;
	sub_8268EE10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_8262E54C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262E554"))) PPC_WEAK_FUNC(sub_8262E554);
PPC_FUNC_IMPL(__imp__sub_8262E554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262E558"))) PPC_WEAK_FUNC(sub_8262E558);
PPC_FUNC_IMPL(__imp__sub_8262E558) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,536(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 536);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262E57C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8262e750
	if (cr6.eq) goto loc_8262E750;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r8,20(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r10,r11,-14716
	ctx.r10.s64 = r11.s64 + -14716;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_8262E598:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x8262e5bc
	if (cr6.eq) goto loc_8262E5BC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262e598
	if (cr6.eq) goto loc_8262E598;
loc_8262E5BC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262e750
	if (cr6.eq) goto loc_8262E750;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-13456
	ctx.r10.s64 = ctx.r10.s64 + -13456;
loc_8262E5D0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262e5f4
	if (cr6.eq) goto loc_8262E5F4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262e5d0
	if (cr6.eq) goto loc_8262E5D0;
loc_8262E5F4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262e750
	if (cr6.eq) goto loc_8262E750;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262E610;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r6,r9,24220
	ctx.r6.s64 = ctx.r9.s64 + 24220;
	// addi r5,r8,-17860
	ctx.r5.s64 = ctx.r8.s64 + -17860;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x8262E634;
	sub_823DEDD8(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8262e750
	if (cr6.lt) goto loc_8262E750;
	// lhz r11,116(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 116);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bge cr6,0x8262e750
	if (!cr6.lt) goto loc_8262E750;
	// lwz r11,112(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 112);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262e750
	if (cr6.eq) goto loc_8262E750;
	// addi r10,r11,72
	ctx.r10.s64 = r11.s64 + 72;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r8,63
	ctx.r8.s64 = 63;
loc_8262E668:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262e6c0
	if (cr6.eq) goto loc_8262E6C0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262e6b4
	if (cr6.eq) goto loc_8262E6B4;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262e6bc
	if (cr6.eq) goto loc_8262E6BC;
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
	// bgt 0x8262e668
	if (cr0.gt) goto loc_8262E668;
	// b 0x8262e6c0
	goto loc_8262E6C0;
loc_8262E6B4:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8262e6c0
	goto loc_8262E6C0;
loc_8262E6BC:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_8262E6C0:
	// li r31,0
	r31.s64 = 0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stb r31,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r31.u8);
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8262E6D0:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8262e6d0
	if (!cr6.eq) goto loc_8262E6D0;
	// subf r11,r11,r10
	r11.s64 = ctx.r10.s64 - r11.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262e738
	if (cr6.eq) goto loc_8262E738;
loc_8262E6F4:
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// lbzx r11,r31,r30
	r11.u64 = PPC_LOAD_U8(r31.u32 + r30.u32);
	// extsb r3,r11
	ctx.r3.s64 = r11.s8;
	// bl 0x823df058
	ctx.lr = 0x8262E704;
	sub_823DF058(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// stbx r3,r31,r30
	PPC_STORE_U8(r31.u32 + r30.u32, ctx.r3.u8);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_8262E714:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8262e714
	if (!cr6.eq) goto loc_8262E714;
	// subf r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// blt cr6,0x8262e6f4
	if (cr6.lt) goto loc_8262E6F4;
loc_8262E738:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213b80
	ctx.lr = 0x8262E750;
	sub_82213B80(ctx, base);
loc_8262E750:
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

__attribute__((alias("__imp__sub_8262E768"))) PPC_WEAK_FUNC(sub_8262E768);
PPC_FUNC_IMPL(__imp__sub_8262E768) {
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
	ctx.lr = 0x8262E770;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635ec8
	ctx.lr = 0x8262E77C;
	sub_82635EC8(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8262E790;
	sub_821F9FB8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,196(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// lwz r4,56(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262E7AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// addi r4,r7,-14664
	ctx.r4.s64 = ctx.r7.s64 + -14664;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8262E7C0;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,36
	ctx.r5.s64 = 36;
	// bl 0x8263ad08
	ctx.lr = 0x8262E7D0;
	sub_8263AD08(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r11,-18792
	r29.s64 = r11.s64 + -18792;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
loc_8262E7E0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262e804
	if (cr6.eq) goto loc_8262E804;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262e7e0
	if (cr6.eq) goto loc_8262E7E0;
loc_8262E804:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262e82c
	if (!cr6.eq) goto loc_8262E82C;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r4,r11,-13408
	ctx.r4.s64 = r11.s64 + -13408;
	// bl 0x82218310
	ctx.lr = 0x8262E81C;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,37
	ctx.r5.s64 = 37;
	// bl 0x8263ad08
	ctx.lr = 0x8262E82C;
	sub_8263AD08(ctx, base);
loc_8262E82C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// addi r4,r11,-14716
	ctx.r4.s64 = r11.s64 + -14716;
	// bl 0x82218310
	ctx.lr = 0x8262E83C;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,38
	ctx.r5.s64 = 38;
	// bl 0x8263ad08
	ctx.lr = 0x8262E84C;
	sub_8263AD08(ctx, base);
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
loc_8262E854:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262e878
	if (cr6.eq) goto loc_8262E878;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262e854
	if (cr6.eq) goto loc_8262E854;
loc_8262E878:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262e8c8
	if (!cr6.eq) goto loc_8262E8C8;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r30,r10,-13424
	r30.s64 = ctx.r10.s64 + -13424;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213058
	ctx.lr = 0x8262E8A0;
	sub_82213058(ctx, base);
	// stw r3,132(r31)
	PPC_STORE_U32(r31.u32 + 132, ctx.r3.u32);
	// lis r9,-32124
	ctx.r9.s64 = -2105278464;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-25232(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -25232);
	// bl 0x82182150
	ctx.lr = 0x8262E8B8;
	sub_82182150(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// stb r8,136(r31)
	PPC_STORE_U8(r31.u32 + 136, ctx.r8.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8262E8C8:
	// li r11,1
	r11.s64 = 1;
	// stb r11,136(r31)
	PPC_STORE_U8(r31.u32 + 136, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8262E8D8"))) PPC_WEAK_FUNC(sub_8262E8D8);
PPC_FUNC_IMPL(__imp__sub_8262E8D8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x8262E8E0;
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82638490
	ctx.lr = 0x8262E8EC;
	sub_82638490(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,-14716
	ctx.r3.s64 = r11.s64 + -14716;
	// addi r30,r10,-22160
	r30.s64 = ctx.r10.s64 + -22160;
	// addi r29,r9,-22108
	r29.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8262E908;
	sub_821FA230(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8262E91C;
	sub_823DEDD8(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r8,-13456
	ctx.r3.s64 = ctx.r8.s64 + -13456;
	// bl 0x821fa230
	ctx.lr = 0x8262E92C;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8262E940;
	sub_823DEDD8(ctx, base);
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r6,104(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 104);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262E958;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x8262ec0c
	if (!cr6.eq) goto loc_8262EC0C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262E978;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8262ec0c
	if (!cr6.eq) goto loc_8262EC0C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,536(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 536);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262E998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262ec88
	if (cr6.eq) goto loc_8262EC88;
	// li r24,0
	r24.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// bl 0x8262d108
	ctx.lr = 0x8262E9AC;
	sub_8262D108(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8262ec88
	if (cr6.eq) goto loc_8262EC88;
	// addi r4,r27,328
	ctx.r4.s64 = r27.s64 + 328;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262cf30
	ctx.lr = 0x8262E9C4;
	sub_8262CF30(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r28,0
	r28.s64 = 0;
	// addi r23,r11,3998
	r23.s64 = r11.s64 + 3998;
	// lhz r11,720(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 720);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262ea58
	if (cr6.eq) goto loc_8262EA58;
loc_8262E9DC:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826c72a0
	ctx.lr = 0x8262E9E8;
	sub_826C72A0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r11,117(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 117);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262ea08
	if (!cr6.eq) goto loc_8262EA08;
	// lbz r11,118(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 118);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x8262ea0c
	if (cr6.eq) goto loc_8262EA0C;
loc_8262EA08:
	// li r11,1
	r11.s64 = 1;
loc_8262EA0C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262ea40
	if (!cr6.eq) goto loc_8262EA40;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826cc350
	ctx.lr = 0x8262EA28;
	sub_826CC350(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lbz r6,116(r29)
	ctx.r6.u64 = PPC_LOAD_U8(r29.u32 + 116);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262cc80
	ctx.lr = 0x8262EA3C;
	sub_8262CC80(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
loc_8262EA40:
	// lhz r11,720(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 720);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8262e9dc
	if (cr6.lt) goto loc_8262E9DC;
	// cmpwi cr6,r30,5
	cr6.compare<int32_t>(r30.s32, 5, xer);
	// bge cr6,0x8262ea78
	if (!cr6.lt) goto loc_8262EA78;
loc_8262EA58:
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262cc80
	ctx.lr = 0x8262EA6C;
	sub_8262CC80(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,5
	cr6.compare<int32_t>(r30.s32, 5, xer);
	// blt cr6,0x8262ea58
	if (cr6.lt) goto loc_8262EA58;
loc_8262EA78:
	// lhz r9,728(r27)
	ctx.r9.u64 = PPC_LOAD_U16(r27.u32 + 728);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// li r26,0
	r26.s64 = 0;
	// addi r29,r11,2612
	r29.s64 = r11.s64 + 2612;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r28,r10,-14684
	r28.s64 = ctx.r10.s64 + -14684;
	// beq cr6,0x8262eb04
	if (cr6.eq) goto loc_8262EB04;
loc_8262EA9C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826c72b8
	ctx.lr = 0x8262EAA8;
	sub_826C72B8(ctx, base);
	// lbz r11,8(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262eaec
	if (!cr6.eq) goto loc_8262EAEC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r22,r3,10
	r22.s64 = ctx.r3.s64 + 10;
	// lwz r30,-10244(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262EAD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r22
	ctx.r7.u64 = r22.u64;
	// bl 0x82218888
	ctx.lr = 0x8262EAE8;
	sub_82218888(ctx, base);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
loc_8262EAEC:
	// lhz r11,728(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 728);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x8262ea9c
	if (cr6.lt) goto loc_8262EA9C;
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// bge cr6,0x8262ebb4
	if (!cr6.lt) goto loc_8262EBB4;
loc_8262EB04:
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x8262EB14;
	sub_821C9790(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262EB34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x8262EB44;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x8262EB54;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x8262EB58;
	sub_825EF9F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r8,7
	ctx.r8.s64 = 7;
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// beq cr6,0x8262ebb4
	if (cr6.eq) goto loc_8262EBB4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262EB8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef9a8
	ctx.lr = 0x8262EB98;
	sub_825EF9A8(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262EBB4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262EBB4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lwz r30,-10244(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + -10244);
	// addi r28,r27,520
	r28.s64 = r27.s64 + 520;
	// addi r26,r10,-14676
	r26.s64 = ctx.r10.s64 + -14676;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262EBD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// bl 0x82218888
	ctx.lr = 0x8262EBF0;
	sub_82218888(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826c72d8
	ctx.lr = 0x8262EBF8;
	sub_826C72D8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262c498
	ctx.lr = 0x8262EC04;
	sub_8262C498(ctx, base);
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9230
	return;
loc_8262EC0C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// addi r25,r11,3998
	r25.s64 = r11.s64 + 3998;
loc_8262EC18:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262cc80
	ctx.lr = 0x8262EC2C;
	sub_8262CC80(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r30,5
	cr6.compare<int32_t>(r30.s32, 5, xer);
	// blt cr6,0x8262ec18
	if (cr6.lt) goto loc_8262EC18;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r30,2
	r30.s64 = 2;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r28,r11,2612
	r28.s64 = r11.s64 + 2612;
	// addi r27,r10,-14684
	r27.s64 = ctx.r10.s64 + -14684;
loc_8262EC50:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r29,-10244(r26)
	r29.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262EC68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// bl 0x82218888
	ctx.lr = 0x8262EC80;
	sub_82218888(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bne 0x8262ec50
	if (!cr0.eq) goto loc_8262EC50;
loc_8262EC88:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8262EC90"))) PPC_WEAK_FUNC(sub_8262EC90);
PPC_FUNC_IMPL(__imp__sub_8262EC90) {
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
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8262ecd8
	if (!cr6.eq) goto loc_8262ECD8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8262ECC4;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262ecd4
	if (cr6.eq) goto loc_8262ECD4;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// stw r11,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r11.u32);
loc_8262ECD4:
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
loc_8262ECD8:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262ECEC"))) PPC_WEAK_FUNC(sub_8262ECEC);
PPC_FUNC_IMPL(__imp__sub_8262ECEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262ECF0"))) PPC_WEAK_FUNC(sub_8262ECF0);
PPC_FUNC_IMPL(__imp__sub_8262ECF0) {
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
	ctx.lr = 0x8262ECF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x8263a4a8
	ctx.lr = 0x8262ED0C;
	sub_8263A4A8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262ef18
	if (!cr6.eq) goto loc_8262EF18;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r11,-10236(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x8262ef18
	if (!cr6.eq) goto loc_8262EF18;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,52
	cr6.compare<int32_t>(r11.s32, 52, xer);
	// bne cr6,0x8262ef18
	if (!cr6.eq) goto loc_8262EF18;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r7,-10220(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lbz r11,375(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 375);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262ef18
	if (cr6.eq) goto loc_8262EF18;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lwz r8,20(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// addi r10,r11,-14664
	ctx.r10.s64 = r11.s64 + -14664;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
loc_8262ED68:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r6,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r6.s64;
	// beq cr6,0x8262ed8c
	if (cr6.eq) goto loc_8262ED8C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262ed68
	if (cr6.eq) goto loc_8262ED68;
loc_8262ED8C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262edcc
	if (cr6.eq) goto loc_8262EDCC;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r10,r10,-14636
	ctx.r10.s64 = ctx.r10.s64 + -14636;
loc_8262EDA0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262edc4
	if (cr6.eq) goto loc_8262EDC4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262eda0
	if (cr6.eq) goto loc_8262EDA0;
loc_8262EDC4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262ef18
	if (!cr6.eq) goto loc_8262EF18;
loc_8262EDCC:
	// lbz r11,376(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 376);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262ef18
	if (!cr6.eq) goto loc_8262EF18;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262EDEC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r9,116(r29)
	ctx.r9.u64 = PPC_LOAD_U16(r29.u32 + 116);
	// cmplw cr6,r3,r9
	cr6.compare<uint32_t>(ctx.r3.u32, ctx.r9.u32, xer);
	// bge cr6,0x8262ef18
	if (!cr6.lt) goto loc_8262EF18;
	// lwz r11,112(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 112);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x826c72d8
	ctx.lr = 0x8262EE08;
	sub_826C72D8(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,24996(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24996);
	// bl 0x826cb780
	ctx.lr = 0x8262EE18;
	sub_826CB780(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8262ef18
	if (cr6.eq) goto loc_8262EF18;
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262ef18
	if (!cr6.eq) goto loc_8262EF18;
	// addi r31,r29,128
	r31.s64 = r29.s64 + 128;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261f6d8
	ctx.lr = 0x8262EE40;
	sub_8261F6D8(ctx, base);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lwz r10,616(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 616);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262ee6c
	if (cr6.eq) goto loc_8262EE6C;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262EE64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// b 0x8262ee70
	goto loc_8262EE70;
loc_8262EE6C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8262EE70:
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// beq cr6,0x8262eeec
	if (cr6.eq) goto loc_8262EEEC;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82622dc0
	ctx.lr = 0x8262EE84;
	sub_82622DC0(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-13348
	ctx.r3.s64 = r11.s64 + -13348;
	// bl 0x821e6800
	ctx.lr = 0x8262EE90;
	sub_821E6800(ctx, base);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r10.u8);
	// lwz r11,-10236(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x8262eeb4
	if (!cr6.eq) goto loc_8262EEB4;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8262EEB4:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r11,776
	ctx.r3.s64 = r11.s64 + 776;
	// bl 0x8268dff0
	ctx.lr = 0x8262EEC0;
	sub_8268DFF0(ctx, base);
	// lwz r11,-10236(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10236);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262EEE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8262EEEC:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-13376
	ctx.r3.s64 = r11.s64 + -13376;
	// bl 0x821e6800
	ctx.lr = 0x8262EEF8;
	sub_821E6800(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10220(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// bl 0x8261fa70
	ctx.lr = 0x8262EF04;
	sub_8261FA70(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262EF18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262EF18:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8262EF24"))) PPC_WEAK_FUNC(sub_8262EF24);
PPC_FUNC_IMPL(__imp__sub_8262EF24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262EF28"))) PPC_WEAK_FUNC(sub_8262EF28);
PPC_FUNC_IMPL(__imp__sub_8262EF28) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r11,-14100
	ctx.r9.s64 = r11.s64 + -14100;
	// addi r8,r10,-14112
	ctx.r8.s64 = ctx.r10.s64 + -14112;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stw r8,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r8.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,68
	ctx.r4.s64 = r31.s64 + 68;
	// lwz r5,180(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// lwz r3,-10224(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x8262EF70;
	sub_8268B6D0(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r5,r6,-21868
	ctx.r5.s64 = ctx.r6.s64 + -21868;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r5,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r5.u32);
	// bl 0x826375a0
	ctx.lr = 0x8262EF84;
	sub_826375A0(ctx, base);
	// clrlwi r4,r30,31
	ctx.r4.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8262ef9c
	if (cr6.eq) goto loc_8262EF9C;
	// bl 0x82130588
	ctx.lr = 0x8262EF98;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262EF9C:
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

__attribute__((alias("__imp__sub_8262EFB4"))) PPC_WEAK_FUNC(sub_8262EFB4);
PPC_FUNC_IMPL(__imp__sub_8262EFB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262EFB8"))) PPC_WEAK_FUNC(sub_8262EFB8);
PPC_FUNC_IMPL(__imp__sub_8262EFB8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635af8
	ctx.lr = 0x8262EFD0;
	sub_82635AF8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8262EFE4;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
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
	ctx.lr = 0x8262F000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lfs f0,-12072(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -12072);
	f0.f64 = double(temp.f32);
	// stfs f0,176(r31)
	temp.f32 = float(f0.f64);
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

__attribute__((alias("__imp__sub_8262F020"))) PPC_WEAK_FUNC(sub_8262F020);
PPC_FUNC_IMPL(__imp__sub_8262F020) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x822b9708
	ctx.lr = 0x8262F03C;
	sub_822B9708(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8262F050;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
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
	ctx.lr = 0x8262F06C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82635840
	ctx.lr = 0x8262F078;
	sub_82635840(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r3,r6,-12116
	ctx.r3.s64 = ctx.r6.s64 + -12116;
	// li r30,0
	r30.s64 = 0;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// bl 0x821c9790
	ctx.lr = 0x8262F09C;
	sub_821C9790(ctx, base);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// lwz r10,496(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F0BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262F0D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x8262F0DC;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,80(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262F0F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-10308
	ctx.r4.s64 = ctx.r4.s64 + -10308;
	// bl 0x82722678
	ctx.lr = 0x8262F104;
	sub_82722678(ctx, base);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lwz r11,-10220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -10220);
	// lbz r10,375(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 375);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8262f128
	if (cr6.eq) goto loc_8262F128;
	// lbz r11,629(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262f128
	if (cr6.eq) goto loc_8262F128;
	// li r30,1
	r30.s64 = 1;
loc_8262F128:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-15392
	r31.s64 = ctx.r10.s64 + -15392;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8262F144;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// clrlwi r5,r30,24
	ctx.r5.u64 = r30.u32 & 0xFF;
	// bl 0x825ee230
	ctx.lr = 0x8262F150;
	sub_825EE230(ctx, base);
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

__attribute__((alias("__imp__sub_8262F168"))) PPC_WEAK_FUNC(sub_8262F168);
PPC_FUNC_IMPL(__imp__sub_8262F168) {
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
	ctx.lr = 0x8262F170;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// bl 0x82635be0
	ctx.lr = 0x8262F184;
	sub_82635BE0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262f334
	if (!cr6.eq) goto loc_8262F334;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r31,r10
	cr6.compare<uint32_t>(r31.u32, ctx.r10.u32, xer);
	// bne cr6,0x8262f334
	if (!cr6.eq) goto loc_8262F334;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpwi cr6,r11,52
	cr6.compare<int32_t>(r11.s32, 52, xer);
	// bne cr6,0x8262f334
	if (!cr6.eq) goto loc_8262F334;
	// bl 0x82387a18
	ctx.lr = 0x8262F1C0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r31,r11,-10220
	r31.s64 = r11.s64 + -10220;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// beq cr6,0x8262f224
	if (cr6.eq) goto loc_8262F224;
	// bl 0x82620068
	ctx.lr = 0x8262F1DC;
	sub_82620068(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262f268
	if (cr6.eq) goto loc_8262F268;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82620068
	ctx.lr = 0x8262F1EC;
	sub_82620068(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r3,r3,-48
	ctx.r3.s64 = ctx.r3.s64 + -48;
	// bne cr6,0x8262f1fc
	if (!cr6.eq) goto loc_8262F1FC;
	// li r3,0
	ctx.r3.s64 = 0;
loc_8262F1FC:
	// bl 0x82284368
	ctx.lr = 0x8262F200;
	sub_82284368(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8262F210;
	sub_822A39C8(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// bne cr6,0x8262f268
	if (!cr6.eq) goto loc_8262F268;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8262F224:
	// bl 0x82620068
	ctx.lr = 0x8262F228;
	sub_82620068(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262f268
	if (cr6.eq) goto loc_8262F268;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82620068
	ctx.lr = 0x8262F238;
	sub_82620068(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262f268
	if (cr6.eq) goto loc_8262F268;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8262f268
	if (!cr6.eq) goto loc_8262F268;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8262F268:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r11,375(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 375);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262f334
	if (cr6.eq) goto loc_8262F334;
	// bl 0x82620068
	ctx.lr = 0x8262F27C;
	sub_82620068(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8262f334
	if (cr6.eq) goto loc_8262F334;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r11,629(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262f334
	if (cr6.eq) goto loc_8262F334;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262dc98
	ctx.lr = 0x8262F29C;
	sub_8262DC98(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82620068
	ctx.lr = 0x8262F2A4;
	sub_82620068(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F2B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262f328
	if (cr6.eq) goto loc_8262F328;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-13308
	ctx.r3.s64 = r11.s64 + -13308;
	// bl 0x821e6800
	ctx.lr = 0x8262F2CC;
	sub_821E6800(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r10.u8);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x8262f2f0
	if (!cr6.eq) goto loc_8262F2F0;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8262F2F0:
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r11,776
	ctx.r3.s64 = r11.s64 + 776;
	// bl 0x8268dff0
	ctx.lr = 0x8262F2FC;
	sub_8268DFF0(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F31C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8262F328:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r3,r11,-13376
	ctx.r3.s64 = r11.s64 + -13376;
	// bl 0x821e6800
	ctx.lr = 0x8262F334;
	sub_821E6800(ctx, base);
loc_8262F334:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8262F340"))) PPC_WEAK_FUNC(sub_8262F340);
PPC_FUNC_IMPL(__imp__sub_8262F340) {
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
	ctx.lr = 0x8262F348;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// bl 0x82635be0
	ctx.lr = 0x8262F35C;
	sub_82635BE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8262f42c
	if (!cr6.eq) goto loc_8262F42C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 262144;
	// addi r9,r9,976
	ctx.r9.s64 = ctx.r9.s64 + 976;
	// cmplw cr6,r30,r9
	cr6.compare<uint32_t>(r30.u32, ctx.r9.u32, xer);
	// bne cr6,0x8262f42c
	if (!cr6.eq) goto loc_8262F42C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmpwi cr6,r11,56
	cr6.compare<int32_t>(r11.s32, 56, xer);
	// bne cr6,0x8262f42c
	if (!cr6.eq) goto loc_8262F42C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262e200
	ctx.lr = 0x8262F398;
	sub_8262E200(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262f428
	if (cr6.eq) goto loc_8262F428;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F3BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,308(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 308);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262F3CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,84(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r7,88(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 88);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// blt cr6,0x8262f3ec
	if (cr6.lt) goto loc_8262F3EC;
	// li r11,0
	r11.s64 = 0;
	// stw r11,84(r31)
	PPC_STORE_U32(r31.u32 + 84, r11.u32);
loc_8262F3EC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,84(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,304(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 304);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262F414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,184(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 184);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8262F428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262F428:
	// li r3,1
	ctx.r3.s64 = 1;
loc_8262F42C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262F434"))) PPC_WEAK_FUNC(sub_8262F434);
PPC_FUNC_IMPL(__imp__sub_8262F434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262F438"))) PPC_WEAK_FUNC(sub_8262F438);
PPC_FUNC_IMPL(__imp__sub_8262F438) {
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
	// bl 0x82638320
	ctx.lr = 0x8262F450;
	sub_82638320(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 92);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183a8
	ctx.lr = 0x8262F460;
	sub_822183A8(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_8262F464:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8262f464
	if (!cr6.eq) goto loc_8262F464;
	// subf r11,r3,r11
	r11.s64 = r11.s64 - ctx.r3.s64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r6,r7,24
	ctx.r6.u64 = ctx.r7.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8262f4ac
	if (cr6.eq) goto loc_8262F4AC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220f040
	ctx.lr = 0x8262F4AC;
	sub_8220F040(ctx, base);
loc_8262F4AC:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262F4C0"))) PPC_WEAK_FUNC(sub_8262F4C0);
PPC_FUNC_IMPL(__imp__sub_8262F4C0) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r10,r11,-13276
	ctx.r10.s64 = r11.s64 + -13276;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,86(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262f4fc
	if (cr6.eq) goto loc_8262F4FC;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x8262F4FC;
	sub_82130588(ctx, base);
loc_8262F4FC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375a0
	ctx.lr = 0x8262F504;
	sub_826375A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262f51c
	if (cr6.eq) goto loc_8262F51C;
	// bl 0x82130588
	ctx.lr = 0x8262F518;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262F51C:
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

__attribute__((alias("__imp__sub_8262F534"))) PPC_WEAK_FUNC(sub_8262F534);
PPC_FUNC_IMPL(__imp__sub_8262F534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262F538"))) PPC_WEAK_FUNC(sub_8262F538);
PPC_FUNC_IMPL(__imp__sub_8262F538) {
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
	// bl 0x8263ac88
	ctx.lr = 0x8262F550;
	sub_8263AC88(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r11,r31,88
	r11.s64 = r31.s64 + 88;
	// addi r9,r10,-21868
	ctx.r9.s64 = ctx.r10.s64 + -21868;
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r8,-12160
	ctx.r4.s64 = ctx.r8.s64 + -12160;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x8262F574;
	sub_823DB670(ctx, base);
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// addi r5,r7,-12708
	ctx.r5.s64 = ctx.r7.s64 + -12708;
	// addi r4,r6,-12724
	ctx.r4.s64 = ctx.r6.s64 + -12724;
	// stw r5,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r5.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r4.u32);
	// bl 0x82130000
	ctx.lr = 0x8262F594;
	sub_82130000(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262cbf0
	ctx.lr = 0x8262F59C;
	sub_8262CBF0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r3,64(r31)
	PPC_STORE_U8(r31.u32 + 64, ctx.r3.u8);
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

__attribute__((alias("__imp__sub_8262F5BC"))) PPC_WEAK_FUNC(sub_8262F5BC);
PPC_FUNC_IMPL(__imp__sub_8262F5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262F5C0"))) PPC_WEAK_FUNC(sub_8262F5C0);
PPC_FUNC_IMPL(__imp__sub_8262F5C0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-88
	ctx.r3.s64 = ctx.r3.s64 + -88;
	// b 0x8262f9d8
	sub_8262F9D8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8262F5C8"))) PPC_WEAK_FUNC(sub_8262F5C8);
PPC_FUNC_IMPL(__imp__sub_8262F5C8) {
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
	ctx.lr = 0x8262F5D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r9,r11,-12708
	ctx.r9.s64 = r11.s64 + -12708;
	// addi r8,r10,-12724
	ctx.r8.s64 = ctx.r10.s64 + -12724;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r8,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r8.u32);
	// addi r30,r31,88
	r30.s64 = r31.s64 + 88;
	// lwz r5,124(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// bl 0x8268b6d0
	ctx.lr = 0x8262F608;
	sub_8268B6D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10224(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10224);
	// lwz r5,128(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// bl 0x8268b6d0
	ctx.lr = 0x8262F618;
	sub_8268B6D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130000
	ctx.lr = 0x8262F620;
	sub_82130000(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82213650
	ctx.lr = 0x8262F634;
	sub_82213650(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// lis r5,-32247
	ctx.r5.s64 = -2113339392;
	// addi r4,r6,-21868
	ctx.r4.s64 = ctx.r6.s64 + -21868;
	// addi r3,r5,-13276
	ctx.r3.s64 = ctx.r5.s64 + -13276;
	// stw r4,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r4.u32);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lhz r11,86(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 86);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262f660
	if (cr6.eq) goto loc_8262F660;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x82130588
	ctx.lr = 0x8262F660;
	sub_82130588(ctx, base);
loc_8262F660:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375a0
	ctx.lr = 0x8262F668;
	sub_826375A0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262F670"))) PPC_WEAK_FUNC(sub_8262F670);
PPC_FUNC_IMPL(__imp__sub_8262F670) {
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
	ctx.lr = 0x8262F678;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x8268d280
	ctx.lr = 0x8262F688;
	sub_8268D280(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,92(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F6A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262f700
	if (cr6.eq) goto loc_8262F700;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F6C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262f700
	if (cr6.eq) goto loc_8262F700;
	// lwz r11,124(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 124);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x8262f6e4
	if (cr6.eq) goto loc_8262F6E4;
	// lwz r11,128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 128);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// bne cr6,0x8262f700
	if (!cr6.eq) goto loc_8262F700;
loc_8262F6E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8262e558
	ctx.lr = 0x8262F6EC;
	sub_8262E558(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262F700:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262F70C"))) PPC_WEAK_FUNC(sub_8262F70C);
PPC_FUNC_IMPL(__imp__sub_8262F70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262F710"))) PPC_WEAK_FUNC(sub_8262F710);
PPC_FUNC_IMPL(__imp__sub_8262F710) {
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
	// bl 0x82638bb8
	ctx.lr = 0x8262F72C;
	sub_82638BB8(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-12140
	ctx.r10.s64 = r11.s64 + -12140;
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// stw r30,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r30.u32);
	// sth r30,116(r31)
	PPC_STORE_U16(r31.u32 + 116, r30.u16);
	// sth r30,118(r31)
	PPC_STORE_U16(r31.u32 + 118, r30.u16);
	// stw r30,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r30.u32);
	// sth r30,124(r31)
	PPC_STORE_U16(r31.u32 + 124, r30.u16);
	// sth r30,126(r31)
	PPC_STORE_U16(r31.u32 + 126, r30.u16);
	// bl 0x82637538
	ctx.lr = 0x8262F75C;
	sub_82637538(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r11,1
	r11.s64 = 1;
	// stw r30,272(r31)
	PPC_STORE_U32(r31.u32 + 272, r30.u32);
	// addi r8,r9,7132
	ctx.r8.s64 = ctx.r9.s64 + 7132;
	// stw r30,276(r31)
	PPC_STORE_U32(r31.u32 + 276, r30.u32);
	// li r7,6
	ctx.r7.s64 = 6;
	// li r6,3
	ctx.r6.s64 = 3;
	// stw r8,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r8.u32);
	// stw r7,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,288(r31)
	PPC_STORE_U32(r31.u32 + 288, r11.u32);
	// stw r6,292(r31)
	PPC_STORE_U32(r31.u32 + 292, ctx.r6.u32);
	// stb r11,64(r31)
	PPC_STORE_U8(r31.u32 + 64, r11.u8);
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

__attribute__((alias("__imp__sub_8262F7A8"))) PPC_WEAK_FUNC(sub_8262F7A8);
PPC_FUNC_IMPL(__imp__sub_8262F7A8) {
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
	ctx.lr = 0x8262F7B0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x826363c0
	ctx.lr = 0x8262F7BC;
	sub_826363C0(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r23,0
	r23.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,564(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 564);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F7D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,124(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 124);
	// lwz r9,120(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 120);
	// addi r27,r29,120
	r27.s64 = r29.s64 + 120;
	// rotlwi r11,r8,2
	r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x8262f80c
	if (cr6.eq) goto loc_8262F80C;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_8262F7F8:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x8262f7f8
	if (!cr6.eq) goto loc_8262F7F8;
loc_8262F80C:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// lis r25,-32121
	r25.s64 = -2105081856;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// addi r31,r29,112
	r31.s64 = r29.s64 + 112;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r8.u16);
	// lwz r11,-10004(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10004);
	// lwz r6,288(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 288);
	// rlwinm r10,r6,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r30,r11,28
	r30.s64 = r11.s64 + 28;
	// cmplw cr6,r31,r30
	cr6.compare<uint32_t>(r31.u32, r30.u32, xer);
	// beq cr6,0x8262f874
	if (cr6.eq) goto loc_8262F874;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x8262f868
	if (cr6.eq) goto loc_8262F868;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262f868
	if (cr6.eq) goto loc_8262F868;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x8262F868;
	sub_82130588(ctx, base);
loc_8262F868:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c7480
	ctx.lr = 0x8262F874;
	sub_826C7480(ctx, base);
loc_8262F874:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lhz r10,116(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 116);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r26,10712(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 10712);
	// beq cr6,0x8262f968
	if (cr6.eq) goto loc_8262F968;
	// lis r11,0
	r11.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// ori r24,r11,65535
	r24.u64 = r11.u64 | 65535;
loc_8262F89C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,-10004(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10004);
	// lwz r4,292(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 292);
	// lwzx r5,r11,r30
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x826c65e8
	ctx.lr = 0x8262F8B0;
	sub_826C65E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262f900
	if (cr6.eq) goto loc_8262F900;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwzx r22,r11,r30
	r22.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// bl 0x8262e420
	ctx.lr = 0x8262F8D0;
	sub_8262E420(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// stw r22,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r22.u32);
	// beq cr6,0x8262f954
	if (cr6.eq) goto loc_8262F954;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// cmplw cr6,r26,r10
	cr6.compare<uint32_t>(r26.u32, ctx.r10.u32, xer);
	// bne cr6,0x8262f954
	if (!cr6.eq) goto loc_8262F954;
	// lhz r11,124(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 124);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r23,r11,-1
	r23.s64 = r11.s64 + -1;
	// bl 0x821f9370
	ctx.lr = 0x8262F8FC;
	sub_821F9370(ctx, base);
	// b 0x8262f954
	goto loc_8262F954;
loc_8262F900:
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// clrlwi r11,r28,16
	r11.u64 = r28.u32 & 0xFFFF;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x8262f940
	if (!cr6.lt) goto loc_8262F940;
loc_8262F914:
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
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
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x8262f914
	if (cr6.lt) goto loc_8262F914;
loc_8262F940:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r28,r28,-1
	r28.s64 = r28.s64 + -1;
	// addi r30,r30,-4
	r30.s64 = r30.s64 + -4;
	// add r10,r11,r24
	ctx.r10.u64 = r11.u64 + r24.u64;
	// sth r10,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r10.u16);
loc_8262F954:
	// lhz r11,116(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 116);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x8262f89c
	if (cr6.lt) goto loc_8262F89C;
loc_8262F968:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r4,124(r29)
	ctx.r4.u64 = PPC_LOAD_U16(r29.u32 + 124);
	// lwz r10,596(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 596);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262F980;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,580(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 580);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262F998;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r7,124(r29)
	ctx.r7.u64 = PPC_LOAD_U16(r29.u32 + 124);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x8262f9bc
	if (!cr6.eq) goto loc_8262F9BC;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r6,-1
	ctx.r6.s64 = -1;
	// addi r3,r11,-22444
	ctx.r3.s64 = r11.s64 + -22444;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8268ee10
	ctx.lr = 0x8262F9BC;
	sub_8268EE10(ctx, base);
loc_8262F9BC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262cf88
	ctx.lr = 0x8262F9C4;
	sub_8262CF88(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8262F9CC"))) PPC_WEAK_FUNC(sub_8262F9CC);
PPC_FUNC_IMPL(__imp__sub_8262F9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262F9D0"))) PPC_WEAK_FUNC(sub_8262F9D0);
PPC_FUNC_IMPL(__imp__sub_8262F9D0) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-88
	ctx.r3.s64 = ctx.r3.s64 + -88;
	// b 0x8262f670
	sub_8262F670(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8262F9D8"))) PPC_WEAK_FUNC(sub_8262F9D8);
PPC_FUNC_IMPL(__imp__sub_8262F9D8) {
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
	// bl 0x8262f5c8
	ctx.lr = 0x8262F9F8;
	sub_8262F5C8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262fa10
	if (cr6.eq) goto loc_8262FA10;
	// bl 0x82130588
	ctx.lr = 0x8262FA0C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262FA10:
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

__attribute__((alias("__imp__sub_8262FA28"))) PPC_WEAK_FUNC(sub_8262FA28);
PPC_FUNC_IMPL(__imp__sub_8262FA28) {
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
	// addi r3,r31,128
	ctx.r3.s64 = r31.s64 + 128;
	// addi r10,r11,6548
	ctx.r10.s64 = r11.s64 + 6548;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,128(r31)
	PPC_STORE_U32(r31.u32 + 128, ctx.r10.u32);
	// bl 0x826375a0
	ctx.lr = 0x8262FA58;
	sub_826375A0(ctx, base);
	// lhz r9,126(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 126);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8262fa6c
	if (cr6.eq) goto loc_8262FA6C;
	// lwz r3,120(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 120);
	// bl 0x82130588
	ctx.lr = 0x8262FA6C;
	sub_82130588(ctx, base);
loc_8262FA6C:
	// lhz r11,118(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 118);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262fa80
	if (cr6.eq) goto loc_8262FA80;
	// lwz r3,112(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 112);
	// bl 0x82130588
	ctx.lr = 0x8262FA80;
	sub_82130588(ctx, base);
loc_8262FA80:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375a0
	ctx.lr = 0x8262FA88;
	sub_826375A0(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8262faa0
	if (cr6.eq) goto loc_8262FAA0;
	// bl 0x82130588
	ctx.lr = 0x8262FA9C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8262FAA0:
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

__attribute__((alias("__imp__sub_8262FAB8"))) PPC_WEAK_FUNC(sub_8262FAB8);
PPC_FUNC_IMPL(__imp__sub_8262FAB8) {
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
	// bl 0x82635c68
	ctx.lr = 0x8262FAD4;
	sub_82635C68(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-11460
	ctx.r4.s64 = ctx.r10.s64 + -11460;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x8262FAEC;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,32684
	ctx.r4.s64 = ctx.r8.s64 + 32684;
	// stw r9,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r9.u32);
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// bl 0x823dc018
	ctx.lr = 0x8262FB0C;
	sub_823DC018(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r10,r11,-11484
	ctx.r10.s64 = r11.s64 + -11484;
	// stw r7,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r7.u32);
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
loc_8262FB20:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8262fb44
	if (cr6.eq) goto loc_8262FB44;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262fb20
	if (cr6.eq) goto loc_8262FB20;
loc_8262FB44:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262fb58
	if (!cr6.eq) goto loc_8262FB58;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82638610
	ctx.lr = 0x8262FB58;
	sub_82638610(ctx, base);
loc_8262FB58:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262e558
	ctx.lr = 0x8262FB60;
	sub_8262E558(ctx, base);
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

__attribute__((alias("__imp__sub_8262FB78"))) PPC_WEAK_FUNC(sub_8262FB78);
PPC_FUNC_IMPL(__imp__sub_8262FB78) {
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
	ctx.lr = 0x8262FB80;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// srawi r11,r31,31
	xer.ca = (r31.s32 < 0) & ((r31.u32 & 0x7FFFFFFF) != 0);
	r11.s64 = r31.s32 >> 31;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// xor r10,r31,r11
	ctx.r10.u64 = r31.u64 ^ r11.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// subf. r28,r11,r10
	r28.s64 = ctx.r10.s64 - r11.s64;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// bne 0x8262fbb0
	if (!cr0.eq) goto loc_8262FBB0;
	// li r29,1
	r29.s64 = 1;
	// b 0x8262fbf0
	goto loc_8262FBF0;
loc_8262FBB0:
	// extsw r11,r28
	r11.s64 = r28.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// bl 0x823db788
	ctx.lr = 0x8262FBC8;
	sub_823DB788(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// frsp f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = double(float(ctx.f1.f64));
	// lfd f1,14704(r10)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r10.u32 + 14704);
	// bl 0x823db788
	ctx.lr = 0x8262FBD8;
	sub_823DB788(ctx, base);
	// frsp f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// fdivs f11,f31,f12
	ctx.f11.f64 = double(float(f31.f64 / ctx.f12.f64));
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// addi r29,r11,1
	r29.s64 = r11.s64 + 1;
loc_8262FBF0:
	// extsw r11,r29
	r11.s64 = r29.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f0,32688(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32688);
	f0.f64 = double(temp.f32);
	// fmuls f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 * f0.f64));
	// bl 0x823dbaa8
	ctx.lr = 0x8262FC14;
	sub_823DBAA8(ctx, base);
	// frsp f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = double(float(ctx.f1.f64));
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// fctiwz f10,f11
	ctx.f10.s64 = (ctx.f11.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// bge cr6,0x8262fc54
	if (!cr6.lt) goto loc_8262FC54;
	// li r10,45
	ctx.r10.s64 = 45;
	// extsb r9,r27
	ctx.r9.s64 = r27.s8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r10,0(r30)
	PPC_STORE_U8(r30.u32 + 0, ctx.r10.u8);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8262fc68
	if (cr6.eq) goto loc_8262FC68;
	// stb r27,1(r30)
	PPC_STORE_U8(r30.u32 + 1, r27.u8);
	// b 0x8262fc64
	goto loc_8262FC64;
loc_8262FC54:
	// extsb r10,r27
	ctx.r10.s64 = r27.s8;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8262fc68
	if (cr6.eq) goto loc_8262FC68;
	// stb r27,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r27.u8);
loc_8262FC64:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_8262FC68:
	// add r10,r11,r30
	ctx.r10.u64 = r11.u64 + r30.u64;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r3,r10,-1
	ctx.r3.s64 = ctx.r10.s64 + -1;
	// mr r9,r28
	ctx.r9.u64 = r28.u64;
	// stbx r7,r11,r30
	PPC_STORE_U8(r11.u32 + r30.u32, ctx.r7.u8);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stb r8,-1(r10)
	PPC_STORE_U8(ctx.r10.u32 + -1, ctx.r8.u8);
	// beq cr6,0x8262fd14
	if (cr6.eq) goto loc_8262FD14;
	// lis r11,26214
	r11.s64 = 1717960704;
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// li r4,-1
	ctx.r4.s64 = -1;
	// ori r5,r11,26215
	ctx.r5.u64 = r11.u64 | 26215;
	// ori r6,r10,21846
	ctx.r6.u64 = ctx.r10.u64 | 21846;
	// li r31,10
	r31.s64 = 10;
loc_8262FCA4:
	// mr r30,r9
	r30.u64 = ctx.r9.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mulhw r11,r30,r5
	r11.s64 = (int64_t(r30.s32) * int64_t(ctx.r5.s32)) >> 32;
	// srawi r11,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	r11.s64 = r11.s32 >> 2;
	// mulhw r10,r29,r6
	ctx.r10.s64 = (int64_t(r29.s32) * int64_t(ctx.r6.s32)) >> 32;
	// rlwinm r8,r11,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// divw r9,r9,r31
	ctx.r9.s32 = ctx.r9.s32 / r31.s32;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// rlwinm r8,r10,1,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r8,r11,r7
	ctx.r8.u64 = r11.u64 + ctx.r7.u64;
	// rlwinm r11,r10,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// subf r10,r7,r30
	ctx.r10.s64 = r30.s64 - ctx.r7.s64;
	// subf r8,r11,r29
	ctx.r8.s64 = r29.s64 - r11.s64;
	// extsb r11,r10
	r11.s64 = ctx.r10.s8;
	// cmpwi cr6,r8,2
	cr6.compare<int32_t>(ctx.r8.s32, 2, xer);
	// addi r11,r11,48
	r11.s64 = r11.s64 + 48;
	// bne cr6,0x8262fd00
	if (!cr6.eq) goto loc_8262FD00;
	// stb r26,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r26.u8);
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_8262FD00:
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, r11.u8);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8262fca4
	if (!cr6.eq) goto loc_8262FCA4;
loc_8262FD14:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8262FD20"))) PPC_WEAK_FUNC(sub_8262FD20);
PPC_FUNC_IMPL(__imp__sub_8262FD20) {
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
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262FD44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r9,102(r31)
	PPC_STORE_U8(r31.u32 + 102, ctx.r9.u8);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8262FD60"))) PPC_WEAK_FUNC(sub_8262FD60);
PPC_FUNC_IMPL(__imp__sub_8262FD60) {
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
	ctx.lr = 0x8262FD68;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32119
	r29.s64 = -2104950784;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x8262FD84;
	sub_82305870(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262FD98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r8,r30,24
	ctx.r8.u64 = r30.u32 & 0xFF;
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// beq cr6,0x8262fdbc
	if (cr6.eq) goto loc_8262FDBC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262FDBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8262FDBC:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375b0
	ctx.lr = 0x8262FDC8;
	sub_826375B0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x8262FDD4;
	sub_823058F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262FDDC"))) PPC_WEAK_FUNC(sub_8262FDDC);
PPC_FUNC_IMPL(__imp__sub_8262FDDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262FDE0"))) PPC_WEAK_FUNC(sub_8262FDE0);
PPC_FUNC_IMPL(__imp__sub_8262FDE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-14524
	ctx.r3.s64 = r11.s64 + -14524;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262FDEC"))) PPC_WEAK_FUNC(sub_8262FDEC);
PPC_FUNC_IMPL(__imp__sub_8262FDEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262FDF0"))) PPC_WEAK_FUNC(sub_8262FDF0);
PPC_FUNC_IMPL(__imp__sub_8262FDF0) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-11124
	ctx.r5.s64 = r11.s64 + -11124;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,160
	ctx.r6.s64 = r31.s64 + 160;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x824df200
	ctx.lr = 0x8262FE2C;
	sub_824DF200(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r10,9856
	ctx.r5.s64 = ctx.r10.s64 + 9856;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,80
	ctx.r6.s64 = r31.s64 + 80;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x8262FE4C;
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

__attribute__((alias("__imp__sub_8262FE64"))) PPC_WEAK_FUNC(sub_8262FE64);
PPC_FUNC_IMPL(__imp__sub_8262FE64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262FE68"))) PPC_WEAK_FUNC(sub_8262FE68);
PPC_FUNC_IMPL(__imp__sub_8262FE68) {
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
	// lis r30,-32119
	r30.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-17944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x8262FE90;
	sub_823058F8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e0558
	ctx.lr = 0x8262FE98;
	sub_824E0558(ctx, base);
	// lwz r11,-17944(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -17944);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82305870
	ctx.lr = 0x8262FEAC;
	sub_82305870(ctx, base);
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

__attribute__((alias("__imp__sub_8262FEC8"))) PPC_WEAK_FUNC(sub_8262FEC8);
PPC_FUNC_IMPL(__imp__sub_8262FEC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,596(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 596);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8262FED8"))) PPC_WEAK_FUNC(sub_8262FED8);
PPC_FUNC_IMPL(__imp__sub_8262FED8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,160(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// stfs f2,164(r3)
	temp.f32 = float(ctx.f2.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// stfs f3,168(r3)
	temp.f32 = float(ctx.f3.f64);
	PPC_STORE_U32(ctx.r3.u32 + 168, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262FEE8"))) PPC_WEAK_FUNC(sub_8262FEE8);
PPC_FUNC_IMPL(__imp__sub_8262FEE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,160(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 160, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262FEF0"))) PPC_WEAK_FUNC(sub_8262FEF0);
PPC_FUNC_IMPL(__imp__sub_8262FEF0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,164(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 164, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262FEF8"))) PPC_WEAK_FUNC(sub_8262FEF8);
PPC_FUNC_IMPL(__imp__sub_8262FEF8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// stfs f1,168(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 168, temp.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262FF00"))) PPC_WEAK_FUNC(sub_8262FF00);
PPC_FUNC_IMPL(__imp__sub_8262FF00) {
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
	ctx.lr = 0x8262FF08;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262FF20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8262FF38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x8262ffd4
	if (cr6.eq) goto loc_8262FFD4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8262ffd4
	if (cr6.eq) goto loc_8262FFD4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r30,r11,2612
	r30.s64 = r11.s64 + 2612;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x8262FF60;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8262FF70;
	sub_825ED480(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r30,r11,-13268
	r30.s64 = r11.s64 + -13268;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82722398
	ctx.lr = 0x8262FF88;
	sub_82722398(ctx, base);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x8262ffac
	if (!cr6.eq) goto loc_8262FFAC;
	// li r11,3
	r11.s64 = 3;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x8262FFAC;
	sub_82722678(ctx, base);
loc_8262FFAC:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,332(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 332);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8262FFC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-11112
	ctx.r4.s64 = ctx.r9.s64 + -11112;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8262FFD4;
	sub_827227B8(ctx, base);
loc_8262FFD4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8262FFDC"))) PPC_WEAK_FUNC(sub_8262FFDC);
PPC_FUNC_IMPL(__imp__sub_8262FFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262FFE0"))) PPC_WEAK_FUNC(sub_8262FFE0);
PPC_FUNC_IMPL(__imp__sub_8262FFE0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r4.u32);
	// stw r5,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r5.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8262FFEC"))) PPC_WEAK_FUNC(sub_8262FFEC);
PPC_FUNC_IMPL(__imp__sub_8262FFEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8262FFF0"))) PPC_WEAK_FUNC(sub_8262FFF0);
PPC_FUNC_IMPL(__imp__sub_8262FFF0) {
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
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// stw r4,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r4.u32);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8263005c
	if (cr6.eq) goto loc_8263005C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630024;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82630050
	if (cr6.eq) goto loc_82630050;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,552(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 552);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82630050;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82630050:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,212
	ctx.r3.s64 = r31.s64 + 212;
	// bl 0x821c3048
	ctx.lr = 0x8263005C;
	sub_821C3048(ctx, base);
loc_8263005C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82630070"))) PPC_WEAK_FUNC(sub_82630070);
PPC_FUNC_IMPL(__imp__sub_82630070) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630094;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r9,2612
	r30.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x826300AC;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x826300BC;
	sub_825ED480(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,-10308
	ctx.r4.s64 = ctx.r8.s64 + -10308;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82722398
	ctx.lr = 0x826300D0;
	sub_82722398(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r7,-12116
	ctx.r3.s64 = ctx.r7.s64 + -12116;
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// bl 0x821c9790
	ctx.lr = 0x826300F4;
	sub_821C9790(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82630108;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630120;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x82630128;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r9,-1
	ctx.r4.s64 = ctx.r9.s64 + -1;
	// lwz r7,80(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82630140;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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

__attribute__((alias("__imp__sub_82630158"))) PPC_WEAK_FUNC(sub_82630158);
PPC_FUNC_IMPL(__imp__sub_82630158) {
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
	ctx.lr = 0x82630160;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630174;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r30,r9,2612
	r30.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x8263018C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8263019C;
	sub_825ED480(ctx, base);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r30,r8,-10308
	r30.s64 = ctx.r8.s64 + -10308;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82722398
	ctx.lr = 0x826301B4;
	sub_82722398(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r7,-12116
	ctx.r3.s64 = ctx.r7.s64 + -12116;
	// li r5,7
	ctx.r5.s64 = 7;
	// stw r6,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// bl 0x821c9790
	ctx.lr = 0x826301D8;
	sub_821C9790(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x826301EC;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630204;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x8263020C;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82630220;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r6,r7,1
	ctx.r6.s64 = ctx.r7.s64 + 1;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82630240;
	sub_82722678(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263024C"))) PPC_WEAK_FUNC(sub_8263024C);
PPC_FUNC_IMPL(__imp__sub_8263024C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630250"))) PPC_WEAK_FUNC(sub_82630250);
PPC_FUNC_IMPL(__imp__sub_82630250) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
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
	// lwz r9,740(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 740);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82630270"))) PPC_WEAK_FUNC(sub_82630270);
PPC_FUNC_IMPL(__imp__sub_82630270) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
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
	// lwz r9,744(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 744);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82630290"))) PPC_WEAK_FUNC(sub_82630290);
PPC_FUNC_IMPL(__imp__sub_82630290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lfs f0,176(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f1,176(r3)
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_826302B0"))) PPC_WEAK_FUNC(sub_826302B0);
PPC_FUNC_IMPL(__imp__sub_826302B0) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826302B4"))) PPC_WEAK_FUNC(sub_826302B4);
PPC_FUNC_IMPL(__imp__sub_826302B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826302B8"))) PPC_WEAK_FUNC(sub_826302B8);
PPC_FUNC_IMPL(__imp__sub_826302B8) {
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
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826302DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stb r9,102(r31)
	PPC_STORE_U8(r31.u32 + 102, ctx.r9.u8);
	// beq cr6,0x82630304
	if (cr6.eq) goto loc_82630304;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,764(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 764);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630304;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82630304:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82630318"))) PPC_WEAK_FUNC(sub_82630318);
PPC_FUNC_IMPL(__imp__sub_82630318) {
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
	// lis r11,-32123
	r11.s64 = -2105212928;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r10,r31,224
	ctx.r10.s64 = r31.s64 + 224;
	// addi r11,r11,23088
	r11.s64 = r11.s64 + 23088;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82630344:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x82630344
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82630344;
	// li r11,0
	r11.s64 = 0;
	// stw r3,220(r31)
	PPC_STORE_U32(r31.u32 + 220, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r11,200(r31)
	PPC_STORE_U32(r31.u32 + 200, r11.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// beq cr6,0x82630380
	if (cr6.eq) goto loc_82630380;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,740(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 740);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x8263039c
	goto loc_8263039C;
loc_82630380:
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
	// lwz r9,740(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 740);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8263039C:
	// bctrl 
	ctx.lr = 0x826303A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826303B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,608(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 608);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826303CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r7,246(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 246);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x826303f4
	if (!cr6.eq) goto loc_826303F4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,246(r31)
	PPC_STORE_U8(r31.u32 + 246, ctx.r10.u8);
	// lwz r9,400(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 400);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826303F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826303F4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630408;
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

__attribute__((alias("__imp__sub_8263041C"))) PPC_WEAK_FUNC(sub_8263041C);
PPC_FUNC_IMPL(__imp__sub_8263041C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630420"))) PPC_WEAK_FUNC(sub_82630420);
PPC_FUNC_IMPL(__imp__sub_82630420) {
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
	ctx.lr = 0x82630428;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// clrlwi r29,r30,24
	r29.u64 = r30.u32 & 0xFF;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630448;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r9,r29
	cr6.compare<uint32_t>(ctx.r9.u32, r29.u32, xer);
	// beq cr6,0x82630468
	if (cr6.eq) goto loc_82630468;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,608(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 608);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630468;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82630468:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268d9f8
	ctx.lr = 0x82630474;
	sub_8268D9F8(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826304a8
	if (cr6.eq) goto loc_826304A8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,760(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 760);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630490;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,180(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 180);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826304A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826304A8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826304B0"))) PPC_WEAK_FUNC(sub_826304B0);
PPC_FUNC_IMPL(__imp__sub_826304B0) {
	PPC_FUNC_PROLOGUE();
	// stw r4,200(r3)
	PPC_STORE_U32(ctx.r3.u32 + 200, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_826304B8"))) PPC_WEAK_FUNC(sub_826304B8);
PPC_FUNC_IMPL(__imp__sub_826304B8) {
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
	// std r5,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r5.u64);
	// std r6,136(r1)
	PPC_STORE_U64(ctx.r1.u32 + 136, ctx.r6.u64);
	// std r7,144(r1)
	PPC_STORE_U64(ctx.r1.u32 + 144, ctx.r7.u64);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826304E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r10,r31,224
	ctx.r10.s64 = r31.s64 + 224;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826304F8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826304f8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826304F8;
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82630520"))) PPC_WEAK_FUNC(sub_82630520);
PPC_FUNC_IMPL(__imp__sub_82630520) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,704(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 704);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82630530"))) PPC_WEAK_FUNC(sub_82630530);
PPC_FUNC_IMPL(__imp__sub_82630530) {
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
	// bl 0x82130000
	ctx.lr = 0x82630548;
	sub_82130000(ctx, base);
	// lbz r11,246(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 246);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263055c
	if (!cr6.eq) goto loc_8263055C;
	// li r11,1
	r11.s64 = 1;
	// stb r11,246(r31)
	PPC_STORE_U8(r31.u32 + 246, r11.u8);
loc_8263055C:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82630570"))) PPC_WEAK_FUNC(sub_82630570);
PPC_FUNC_IMPL(__imp__sub_82630570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// li r11,1
	r11.s64 = 1;
	// stb r11,102(r3)
	PPC_STORE_U8(ctx.r3.u32 + 102, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8263057C"))) PPC_WEAK_FUNC(sub_8263057C);
PPC_FUNC_IMPL(__imp__sub_8263057C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630580"))) PPC_WEAK_FUNC(sub_82630580);
PPC_FUNC_IMPL(__imp__sub_82630580) {
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
	ctx.lr = 0x82630588;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,246(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 246);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263073c
	if (cr6.eq) goto loc_8263073C;
	// lbz r11,252(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826305b8
	if (cr6.eq) goto loc_826305B8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826305B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826305B8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,752(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 752);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826305CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r27,0
	r27.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82630714
	if (!cr6.eq) goto loc_82630714;
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
	ctx.lr = 0x826305F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,180(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 180);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263060C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8263064c
	if (cr6.eq) goto loc_8263064C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8263064c
	if (cr6.eq) goto loc_8263064C;
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,180(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 180);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263064C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263064C:
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lis r11,1
	r11.s64 = 65536;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// ori r29,r11,16256
	r29.u64 = r11.u64 | 16256;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// beq cr6,0x82630670
	if (cr6.eq) goto loc_82630670;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8263067c
	goto loc_8263067C;
loc_82630670:
	// lwz r11,-10028(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10028);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// lwzx r11,r11,r29
	r11.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
loc_8263067C:
	// lwz r10,744(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 744);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630688;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263069C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r27,246(r31)
	PPC_STORE_U8(r31.u32 + 246, r27.u8);
	// lwz r8,756(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 756);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826306B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,220(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826306f0
	if (cr6.eq) goto loc_826306F0;
	// stw r27,220(r31)
	PPC_STORE_U32(r31.u32 + 220, r27.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826306D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82630708
	if (cr6.eq) goto loc_82630708;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// b 0x826306fc
	goto loc_826306FC;
loc_826306F0:
	// lwz r11,-10028(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10028);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// lwzx r11,r11,r29
	r11.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
loc_826306FC:
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630708;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82630708:
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,224
	ctx.r3.s64 = r31.s64 + 224;
	// bl 0x821c3048
	ctx.lr = 0x82630714;
	sub_821C3048(ctx, base);
loc_82630714:
	// lbz r11,252(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 252);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263073c
	if (cr6.eq) goto loc_8263073C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 96);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630738;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r27,252(r31)
	PPC_STORE_U8(r31.u32 + 252, r27.u8);
loc_8263073C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82630744"))) PPC_WEAK_FUNC(sub_82630744);
PPC_FUNC_IMPL(__imp__sub_82630744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630748"))) PPC_WEAK_FUNC(sub_82630748);
PPC_FUNC_IMPL(__imp__sub_82630748) {
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
	// bl 0x8262fdf0
	ctx.lr = 0x82630768;
	sub_8262FDF0(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,-11092
	ctx.r5.s64 = r11.s64 + -11092;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,248
	ctx.r6.s64 = r31.s64 + 248;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x824df200
	ctx.lr = 0x82630788;
	sub_824DF200(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r10,-15208
	ctx.r5.s64 = ctx.r10.s64 + -15208;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,65
	ctx.r6.s64 = r31.s64 + 65;
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x824df200
	ctx.lr = 0x826307A8;
	sub_824DF200(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r5,r9,-11100
	ctx.r5.s64 = ctx.r9.s64 + -11100;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r6,r31,244
	ctx.r6.s64 = r31.s64 + 244;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824df200
	ctx.lr = 0x826307C8;
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

__attribute__((alias("__imp__sub_826307E0"))) PPC_WEAK_FUNC(sub_826307E0);
PPC_FUNC_IMPL(__imp__sub_826307E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r3,220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 220);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826307fc
	if (cr6.eq) goto loc_826307FC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_826307FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82630804"))) PPC_WEAK_FUNC(sub_82630804);
PPC_FUNC_IMPL(__imp__sub_82630804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630808"))) PPC_WEAK_FUNC(sub_82630808);
PPC_FUNC_IMPL(__imp__sub_82630808) {
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
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82630860
	if (cr6.eq) goto loc_82630860;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,760(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 760);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,748(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 748);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263085C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82630864
	goto loc_82630864;
loc_82630860:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82630864:
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

__attribute__((alias("__imp__sub_8263087C"))) PPC_WEAK_FUNC(sub_8263087C);
PPC_FUNC_IMPL(__imp__sub_8263087C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630880"))) PPC_WEAK_FUNC(sub_82630880);
PPC_FUNC_IMPL(__imp__sub_82630880) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// b 0x821e6800
	sub_821E6800(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8263088C"))) PPC_WEAK_FUNC(sub_8263088C);
PPC_FUNC_IMPL(__imp__sub_8263088C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630890"))) PPC_WEAK_FUNC(sub_82630890);
PPC_FUNC_IMPL(__imp__sub_82630890) {
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
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// stw r4,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r4.u32);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// beq cr6,0x826308d0
	if (cr6.eq) goto loc_826308D0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826308C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,216
	ctx.r3.s64 = r31.s64 + 216;
	// bl 0x821c3048
	ctx.lr = 0x826308D0;
	sub_821C3048(ctx, base);
loc_826308D0:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826308E4"))) PPC_WEAK_FUNC(sub_826308E4);
PPC_FUNC_IMPL(__imp__sub_826308E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826308E8"))) PPC_WEAK_FUNC(sub_826308E8);
PPC_FUNC_IMPL(__imp__sub_826308E8) {
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
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82630938
	if (!cr6.eq) goto loc_82630938;
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// blt cr6,0x82630928
	if (cr6.lt) goto loc_82630928;
	// subf r11,r11,r4
	r11.s64 = ctx.r4.s64 - r11.s64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,256(r31)
	PPC_STORE_U32(r31.u32 + 256, r11.u32);
loc_82630928:
	// lwz r11,256(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82630938
	if (!cr6.lt) goto loc_82630938;
	// stw r4,256(r31)
	PPC_STORE_U32(r31.u32 + 256, ctx.r4.u32);
loc_82630938:
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// stw r4,184(r31)
	PPC_STORE_U32(r31.u32 + 184, ctx.r4.u32);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// beq cr6,0x82630968
	if (cr6.eq) goto loc_82630968;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263095C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,216
	ctx.r3.s64 = r31.s64 + 216;
	// bl 0x821c3048
	ctx.lr = 0x82630968;
	sub_821C3048(ctx, base);
loc_82630968:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_8263097C"))) PPC_WEAK_FUNC(sub_8263097C);
PPC_FUNC_IMPL(__imp__sub_8263097C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630980"))) PPC_WEAK_FUNC(sub_82630980);
PPC_FUNC_IMPL(__imp__sub_82630980) {
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
	ctx.lr = 0x82630988;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r11,72(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 72);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826309d4
	if (cr6.eq) goto loc_826309D4;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_826309A8:
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,176(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 176);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826309C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,72(r30)
	ctx.r8.u64 = PPC_LOAD_U16(r30.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x826309a8
	if (cr6.lt) goto loc_826309A8;
loc_826309D4:
	// stb r28,102(r30)
	PPC_STORE_U8(r30.u32 + 102, r28.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826309E0"))) PPC_WEAK_FUNC(sub_826309E0);
PPC_FUNC_IMPL(__imp__sub_826309E0) {
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
	ctx.lr = 0x826309E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630A08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82630a8c
	if (cr6.eq) goto loc_82630A8C;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82630a8c
	if (cr6.eq) goto loc_82630A8C;
	// li r30,0
	r30.s64 = 0;
loc_82630A28:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82630A40;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82630a78
	if (cr6.eq) goto loc_82630A78;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
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
	ctx.lr = 0x82630A6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82630a98
	if (!cr6.eq) goto loc_82630A98;
loc_82630A78:
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82630a28
	if (cr6.lt) goto loc_82630A28;
loc_82630A8C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82630A98:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82630AA4"))) PPC_WEAK_FUNC(sub_82630AA4);
PPC_FUNC_IMPL(__imp__sub_82630AA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630AA8"))) PPC_WEAK_FUNC(sub_82630AA8);
PPC_FUNC_IMPL(__imp__sub_82630AA8) {
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
	ctx.lr = 0x82630AB0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630AD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82630b54
	if (cr6.eq) goto loc_82630B54;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82630b54
	if (cr6.eq) goto loc_82630B54;
	// li r30,0
	r30.s64 = 0;
loc_82630AF0:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82630B08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82630b40
	if (cr6.eq) goto loc_82630B40;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82630B34;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82630b60
	if (!cr6.eq) goto loc_82630B60;
loc_82630B40:
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82630af0
	if (cr6.lt) goto loc_82630AF0;
loc_82630B54:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82630B60:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82630B6C"))) PPC_WEAK_FUNC(sub_82630B6C);
PPC_FUNC_IMPL(__imp__sub_82630B6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630B70"))) PPC_WEAK_FUNC(sub_82630B70);
PPC_FUNC_IMPL(__imp__sub_82630B70) {
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
	ctx.lr = 0x82630B78;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630B98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82630c1c
	if (cr6.eq) goto loc_82630C1C;
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82630c1c
	if (cr6.eq) goto loc_82630C1C;
	// li r30,0
	r30.s64 = 0;
loc_82630BB8:
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82630BD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82630c08
	if (cr6.eq) goto loc_82630C08;
	// lwz r11,68(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
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
	ctx.lr = 0x82630BFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82630c28
	if (!cr6.eq) goto loc_82630C28;
loc_82630C08:
	// lhz r11,72(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 72);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82630bb8
	if (cr6.lt) goto loc_82630BB8;
loc_82630C1C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82630C28:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82630C34"))) PPC_WEAK_FUNC(sub_82630C34);
PPC_FUNC_IMPL(__imp__sub_82630C34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630C38"))) PPC_WEAK_FUNC(sub_82630C38);
PPC_FUNC_IMPL(__imp__sub_82630C38) {
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
	ctx.lr = 0x82630C40;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x82635790
	ctx.lr = 0x82630C50;
	sub_82635790(ctx, base);
	// lhz r11,72(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 72);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82630c94
	if (cr6.eq) goto loc_82630C94;
	// li r30,0
	r30.s64 = 0;
loc_82630C64:
	// lwz r11,68(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82630C80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,72(r29)
	ctx.r8.u64 = PPC_LOAD_U16(r29.u32 + 72);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// blt cr6,0x82630c64
	if (cr6.lt) goto loc_82630C64;
loc_82630C94:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82630C9C"))) PPC_WEAK_FUNC(sub_82630C9C);
PPC_FUNC_IMPL(__imp__sub_82630C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630CA0"))) PPC_WEAK_FUNC(sub_82630CA0);
PPC_FUNC_IMPL(__imp__sub_82630CA0) {
	PPC_FUNC_PROLOGUE();
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// stw r4,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82630CAC"))) PPC_WEAK_FUNC(sub_82630CAC);
PPC_FUNC_IMPL(__imp__sub_82630CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630CB0"))) PPC_WEAK_FUNC(sub_82630CB0);
PPC_FUNC_IMPL(__imp__sub_82630CB0) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x8268dcb0
	ctx.lr = 0x82630CDC;
	sub_8268DCB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82630d1c
	if (cr6.eq) goto loc_82630D1C;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r6,r30,1
	ctx.r6.s64 = r30.s64 + 1;
	// addi r5,r11,-11084
	ctx.r5.s64 = r11.s64 + -11084;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x82630D04;
	sub_82137A08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x82630D14;
	sub_8268DA78(ctx, base);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82630d30
	goto loc_82630D30;
loc_82630D1C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,332(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 332);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630D30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82630D30:
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

__attribute__((alias("__imp__sub_82630D48"))) PPC_WEAK_FUNC(sub_82630D48);
PPC_FUNC_IMPL(__imp__sub_82630D48) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,12(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lwzx r4,r10,r11
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// bl 0x8268dcb0
	ctx.lr = 0x82630D6C;
	sub_8268DCB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82630dac
	if (cr6.eq) goto loc_82630DAC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,20276
	ctx.r4.s64 = r11.s64 + 20276;
	// bl 0x8268da78
	ctx.lr = 0x82630D8C;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82630dac
	if (cr6.eq) goto loc_82630DAC;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82630DAC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x82630dc4
	if (cr6.gt) goto loc_82630DC4;
	// li r11,0
	r11.s64 = 0;
loc_82630DC4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82630DE4"))) PPC_WEAK_FUNC(sub_82630DE4);
PPC_FUNC_IMPL(__imp__sub_82630DE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82630DE8"))) PPC_WEAK_FUNC(sub_82630DE8);
PPC_FUNC_IMPL(__imp__sub_82630DE8) {
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
	ctx.lr = 0x82630DF0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x82630c38
	ctx.lr = 0x82630E00;
	sub_82630C38(ctx, base);
	// lhz r31,184(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 184);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x82630e38
	if (!cr6.gt) goto loc_82630E38;
	// li r30,0
	r30.s64 = 0;
loc_82630E10:
	// lwz r11,180(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,196(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 196);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82630E2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82630e10
	if (!cr0.eq) goto loc_82630E10;
loc_82630E38:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82630E40"))) PPC_WEAK_FUNC(sub_82630E40);
PPC_FUNC_IMPL(__imp__sub_82630E40) {
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
	ctx.lr = 0x82630E48;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82630E60;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r21,184(r27)
	r21.u64 = PPC_LOAD_U16(r27.u32 + 184);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// addi r4,r9,-11044
	ctx.r4.s64 = ctx.r9.s64 + -11044;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82630E78;
	sub_825EE0E0(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x82630f88
	if (!cr6.gt) goto loc_82630F88;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// li r29,0
	r29.s64 = 0;
	// li r22,1
	r22.s64 = 1;
	// li r24,3
	r24.s64 = 3;
	// addi r23,r11,-14196
	r23.s64 = r11.s64 + -14196;
	// addi r26,r10,-11056
	r26.s64 = ctx.r10.s64 + -11056;
	// addi r25,r9,-11064
	r25.s64 = ctx.r9.s64 + -11064;
loc_82630EA8:
	// lwz r11,180(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 180);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,332(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 332);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82630EC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82630ECC;
	sub_821C9790(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r22.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82630EE0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x82630EF0;
	sub_825ED480(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82630f08
	if (!cr6.eq) goto loc_82630F08;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821bd618
	ctx.lr = 0x82630F08;
	sub_821BD618(ctx, base);
loc_82630F08:
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ed4a0
	ctx.lr = 0x82630F1C;
	sub_825ED4A0(ctx, base);
	// lwz r11,180(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 180);
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r10,r11,r29
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r9,176(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 176);
	// stw r24,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r24.u32);
	// stw r9,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r9.u32);
	// bl 0x821c9790
	ctx.lr = 0x82630F3C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x825ed480
	ctx.lr = 0x82630F4C;
	sub_825ED480(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82630f64
	if (!cr6.eq) goto loc_82630F64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x821bd618
	ctx.lr = 0x82630F64;
	sub_821BD618(ctx, base);
loc_82630F64:
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ed4a0
	ctx.lr = 0x82630F78;
	sub_825ED4A0(ctx, base);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r21
	cr6.compare<int32_t>(r28.s32, r21.s32, xer);
	// blt cr6,0x82630ea8
	if (cr6.lt) goto loc_82630EA8;
loc_82630F88:
	// lwz r11,176(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 176);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r10,-11072
	ctx.r4.s64 = ctx.r10.s64 + -11072;
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82630FA0;
	sub_825EE0E0(ctx, base);
	// lwz r11,176(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82630fd0
	if (cr6.lt) goto loc_82630FD0;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x82630fd0
	if (cr6.eq) goto loc_82630FD0;
	// lwz r10,180(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 180);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,176(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 176);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82630FD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82630FD0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-13284
	ctx.r4.s64 = r11.s64 + -13284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82630FE4;
	sub_825EE0E0(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// li r5,56
	ctx.r5.s64 = 56;
	// addi r30,r10,-13268
	r30.s64 = ctx.r10.s64 + -13268;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82630FFC;
	sub_825EE0E0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r29,r9,2612
	r29.s64 = ctx.r9.s64 + 2612;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x82631010;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82631020;
	sub_825ED480(ctx, base);
	// li r8,56
	ctx.r8.s64 = 56;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x82631034;
	sub_82722678(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-12592
	ctx.r4.s64 = ctx.r7.s64 + -12592;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82631048;
	sub_825EE0E0(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r6,1072
	ctx.r4.s64 = ctx.r6.s64 + 1072;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8263105C;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82631064"))) PPC_WEAK_FUNC(sub_82631064);
PPC_FUNC_IMPL(__imp__sub_82631064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631068"))) PPC_WEAK_FUNC(sub_82631068);
PPC_FUNC_IMPL(__imp__sub_82631068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
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
	// addi r11,r4,-51
	r11.s64 = ctx.r4.s64 + -51;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,7
	cr6.compare<uint32_t>(r11.u32, 7, xer);
	// bgt cr6,0x826311a4
	if (cr6.gt) goto loc_826311A4;
	// lis r12,-32157
	r12.s64 = -2107441152;
	// addi r12,r12,4256
	r12.s64 = r12.s64 + 4256;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826310C0;
	case 1:
		goto loc_82631140;
	case 2:
		goto loc_826311A4;
	case 3:
		goto loc_826311A4;
	case 4:
		goto loc_826311A4;
	case 5:
		goto loc_826311A4;
	case 6:
		goto loc_826310C0;
	case 7:
		goto loc_82631140;
	default:
		__builtin_unreachable();
	}
	// lwz r19,4288(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4288);
	// lwz r19,4416(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4416);
	// lwz r19,4516(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4516);
	// lwz r19,4516(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4516);
	// lwz r19,4516(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4516);
	// lwz r19,4516(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4516);
	// lwz r19,4288(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4288);
	// lwz r19,4416(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4416);
loc_826310C0:
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826310f0
	if (!cr6.eq) goto loc_826310F0;
loc_826310CC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x826310D8;
	sub_821E6800(ctx, base);
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
loc_826310F0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24604);
	// bl 0x821e6800
	ctx.lr = 0x826310FC;
	sub_821E6800(ctx, base);
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,188
	ctx.r3.s64 = r31.s64 + 188;
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stw r10,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r10.u32);
	// bl 0x821c3048
	ctx.lr = 0x82631114;
	sub_821C3048(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82631128;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_82631140:
	// lhz r11,184(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 184);
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// beq cr6,0x826310cc
	if (cr6.eq) goto loc_826310CC;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24608(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24608);
	// bl 0x821e6800
	ctx.lr = 0x82631160;
	sub_821E6800(ctx, base);
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,188
	ctx.r3.s64 = r31.s64 + 188;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r10.u32);
	// bl 0x821c3048
	ctx.lr = 0x82631178;
	sub_821C3048(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8263118C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
loc_826311A4:
	// lhz r11,184(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 184);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826311e0
	if (cr6.eq) goto loc_826311E0;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 180);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826311D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826311e4
	if (!cr6.eq) goto loc_826311E4;
loc_826311E0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826311E4:
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_826311F8"))) PPC_WEAK_FUNC(sub_826311F8);
PPC_FUNC_IMPL(__imp__sub_826311F8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82631218;
	sub_82218310(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82631230"))) PPC_WEAK_FUNC(sub_82631230);
PPC_FUNC_IMPL(__imp__sub_82631230) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263125C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82631434
	if (cr6.eq) goto loc_82631434;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263127C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82631434
	if (cr6.eq) goto loc_82631434;
	// addi r11,r30,-51
	r11.s64 = r30.s64 + -51;
	// lwz r8,216(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82631434
	if (cr6.gt) goto loc_82631434;
	// lis r12,-32157
	r12.s64 = -2107441152;
	// addi r12,r12,4784
	r12.s64 = r12.s64 + 4784;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826312C0;
	case 1:
		goto loc_82631390;
	case 2:
		goto loc_826312C0;
	case 3:
		goto loc_82631390;
	default:
		__builtin_unreachable();
	}
	// lwz r19,4800(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4800);
	// lwz r19,5008(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5008);
	// lwz r19,4800(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4800);
	// lwz r19,5008(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5008);
loc_826312C0:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lbz r9,224(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 224);
	// subf r10,r11,r8
	ctx.r10.s64 = ctx.r8.s64 - r11.s64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82631328
	if (cr6.eq) goto loc_82631328;
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x826312f0
	if (!cr6.lt) goto loc_826312F0;
	// lwz r9,212(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_826312F0:
	// lwz r9,212(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - r11.s64;
	// subf r10,r11,r9
	ctx.r10.s64 = ctx.r9.s64 - r11.s64;
	// rotlwi r9,r7,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// addi r5,r9,-1
	ctx.r5.s64 = ctx.r9.s64 + -1;
	// divw r4,r7,r6
	ctx.r4.s32 = ctx.r7.s32 / ctx.r6.s32;
	// andc r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r5.u64;
	// mullw r10,r4,r6
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// twllei r6,0
	// twlgei r3,-1
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82631348
	goto loc_82631348;
loc_82631328:
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x82631338
	if (cr6.lt) goto loc_82631338;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_82631338:
	// lwz r30,208(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// ble cr6,0x82631348
	if (!cr6.gt) goto loc_82631348;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
loc_82631348:
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// beq cr6,0x8263137c
	if (cr6.eq) goto loc_8263137C;
	// lwz r3,248(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 248);
	// bl 0x821e6800
	ctx.lr = 0x82631358;
	sub_821E6800(ctx, base);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// beq cr6,0x82631388
	if (cr6.eq) goto loc_82631388;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,228
	ctx.r3.s64 = r31.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x82631374;
	sub_821C3048(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82631438
	goto loc_82631438;
loc_8263137C:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82631388;
	sub_821E6800(ctx, base);
loc_82631388:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82631438
	goto loc_82631438;
loc_82631390:
	// lwz r11,220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 220);
	// lbz r9,224(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 224);
	// add r10,r11,r8
	ctx.r10.u64 = r11.u64 + ctx.r8.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826313e0
	if (cr6.eq) goto loc_826313E0;
	// lwz r11,208(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lwz r9,212(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// subf r7,r11,r10
	ctx.r7.s64 = ctx.r10.s64 - r11.s64;
	// subf r9,r11,r9
	ctx.r9.s64 = ctx.r9.s64 - r11.s64;
	// rotlwi r10,r7,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// divw r4,r7,r6
	ctx.r4.s32 = ctx.r7.s32 / ctx.r6.s32;
	// andc r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 & ~ctx.r5.u64;
	// mullw r10,r4,r6
	ctx.r10.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r6.s32);
	// subf r10,r10,r7
	ctx.r10.s64 = ctx.r7.s64 - ctx.r10.s64;
	// twllei r6,0
	// twlgei r3,-1
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// b 0x82631400
	goto loc_82631400;
loc_826313E0:
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x826313f0
	if (cr6.lt) goto loc_826313F0;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
loc_826313F0:
	// lwz r30,208(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// cmpw cr6,r10,r30
	cr6.compare<int32_t>(ctx.r10.s32, r30.s32, xer);
	// ble cr6,0x82631400
	if (!cr6.gt) goto loc_82631400;
	// mr r30,r10
	r30.u64 = ctx.r10.u64;
loc_82631400:
	// cmpw cr6,r30,r8
	cr6.compare<int32_t>(r30.s32, ctx.r8.s32, xer);
	// beq cr6,0x8263137c
	if (cr6.eq) goto loc_8263137C;
	// lwz r3,252(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 252);
	// bl 0x821e6800
	ctx.lr = 0x82631410;
	sub_821E6800(ctx, base);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// stw r30,216(r31)
	PPC_STORE_U32(r31.u32 + 216, r30.u32);
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// beq cr6,0x82631388
	if (cr6.eq) goto loc_82631388;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,228
	ctx.r3.s64 = r31.s64 + 228;
	// bl 0x821c3048
	ctx.lr = 0x8263142C;
	sub_821C3048(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82631438
	goto loc_82631438;
loc_82631434:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82631438:
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

__attribute__((alias("__imp__sub_82631450"))) PPC_WEAK_FUNC(sub_82631450);
PPC_FUNC_IMPL(__imp__sub_82631450) {
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
	ctx.lr = 0x82631458;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82630158
	ctx.lr = 0x82631464;
	sub_82630158(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r10,r11,-12116
	ctx.r10.s64 = r11.s64 + -12116;
	// li r25,0
	r25.s64 = 0;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r25,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r25.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x821c9790
	ctx.lr = 0x82631490;
	sub_821C9790(ctx, base);
	// li r26,1
	r26.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x826314A4;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826314BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x826314C4;
	sub_825EF9F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r27,r30,208
	r27.s64 = r30.s64 + 208;
	// addi r29,r11,-13276
	r29.s64 = r11.s64 + -13276;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,80(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 80);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826314E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82722678
	ctx.lr = 0x826314F4;
	sub_82722678(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r27,r30,216
	r27.s64 = r30.s64 + 216;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631510;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82722678
	ctx.lr = 0x8263151C;
	sub_82722678(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r30,r30,212
	r30.s64 = r30.s64 + 212;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82631538;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x82631544;
	sub_82722678(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r30,3
	r30.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,84(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 84);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8263155C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// ble cr6,0x826315b0
	if (!cr6.gt) goto loc_826315B0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r27,r11,3998
	r27.s64 = r11.s64 + 3998;
loc_8263156C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x827227b8
	ctx.lr = 0x82631590;
	sub_827227B8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826315A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8263156c
	if (cr6.lt) goto loc_8263156C;
loc_826315B0:
	// stw r25,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r25.u32);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-13284
	ctx.r4.s64 = r11.s64 + -13284;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82722678
	ctx.lr = 0x826315C8;
	sub_82722678(ctx, base);
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-10308
	ctx.r4.s64 = ctx.r9.s64 + -10308;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82722678
	ctx.lr = 0x826315E4;
	sub_82722678(ctx, base);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,620
	ctx.r4.s64 = ctx.r8.s64 + 620;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82722678
	ctx.lr = 0x826315FC;
	sub_82722678(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82631604"))) PPC_WEAK_FUNC(sub_82631604);
PPC_FUNC_IMPL(__imp__sub_82631604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631608"))) PPC_WEAK_FUNC(sub_82631608);
PPC_FUNC_IMPL(__imp__sub_82631608) {
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
	// bl 0x82630158
	ctx.lr = 0x82631624;
	sub_82630158(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263163C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r9,-11016
	ctx.r4.s64 = ctx.r9.s64 + -11016;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x82631654;
	sub_82722678(ctx, base);
	// lwz r7,208(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r8,-11024
	ctx.r4.s64 = ctx.r8.s64 + -11024;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x82722678
	ctx.lr = 0x82631670;
	sub_82722678(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// lis r6,-32247
	ctx.r6.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r6,-11032
	ctx.r4.s64 = ctx.r6.s64 + -11032;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x8263168C;
	sub_82722678(ctx, base);
	// li r10,16
	ctx.r10.s64 = 16;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,20292
	ctx.r4.s64 = ctx.r9.s64 + 20292;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x826316A8;
	sub_82722678(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630158
	ctx.lr = 0x826316B0;
	sub_82630158(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// addi r5,r8,3998
	ctx.r5.s64 = ctx.r8.s64 + 3998;
	// addi r4,r7,20268
	ctx.r4.s64 = ctx.r7.s64 + 20268;
	// bl 0x827227b8
	ctx.lr = 0x826316C4;
	sub_827227B8(ctx, base);
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

__attribute__((alias("__imp__sub_826316DC"))) PPC_WEAK_FUNC(sub_826316DC);
PPC_FUNC_IMPL(__imp__sub_826316DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826316E0"))) PPC_WEAK_FUNC(sub_826316E0);
PPC_FUNC_IMPL(__imp__sub_826316E0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x826316E8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82631840
	if (cr6.eq) goto loc_82631840;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631724;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82631840
	if (cr6.eq) goto loc_82631840;
	// lwz r11,200(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 200);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82631758
	if (cr6.eq) goto loc_82631758;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631750;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8263175c
	goto loc_8263175C;
loc_82631758:
	// lhz r30,192(r29)
	r30.u64 = PPC_LOAD_U16(r29.u32 + 192);
loc_8263175C:
	// addi r11,r31,-51
	r11.s64 = r31.s64 + -51;
	// lwz r10,208(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 208);
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x82631840
	if (cr6.gt) goto loc_82631840;
	// lis r12,-32157
	r12.s64 = -2107441152;
	// addi r12,r12,6020
	r12.s64 = r12.s64 + 6020;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82631794;
	case 1:
		goto loc_826317D8;
	case 2:
		goto loc_82631794;
	case 3:
		goto loc_826317D8;
	default:
		__builtin_unreachable();
	}
	// lwz r19,6036(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6036);
	// lwz r19,6104(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6104);
	// lwz r19,6036(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6036);
	// lwz r19,6104(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 6104);
loc_82631794:
	// lbz r11,232(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 232);
	// addi r31,r10,-1
	r31.s64 = ctx.r10.s64 + -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826317bc
	if (!cr6.eq) goto loc_826317BC;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x826317bc
	if (!cr6.lt) goto loc_826317BC;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// li r31,0
	r31.s64 = 0;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// b 0x82631808
	goto loc_82631808;
loc_826317BC:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24600(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24600);
	// bl 0x821e6800
	ctx.lr = 0x826317C8;
	sub_821E6800(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x8263180c
	if (!cr6.lt) goto loc_8263180C;
	// add r31,r31,r30
	r31.u64 = r31.u64 + r30.u64;
	// b 0x8263180c
	goto loc_8263180C;
loc_826317D8:
	// lbz r11,232(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 232);
	// addi r31,r10,1
	r31.s64 = ctx.r10.s64 + 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82631800
	if (!cr6.eq) goto loc_82631800;
	// cmpw cr6,r31,r30
	cr6.compare<int32_t>(r31.s32, r30.s32, xer);
	// blt cr6,0x82631800
	if (cr6.lt) goto loc_82631800;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// addi r31,r30,-1
	r31.s64 = r30.s64 + -1;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// b 0x82631808
	goto loc_82631808;
loc_82631800:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24596(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24596);
loc_82631808:
	// bl 0x821e6800
	ctx.lr = 0x8263180C;
	sub_821E6800(ctx, base);
loc_8263180C:
	// rotlwi r11,r31,1
	r11.u64 = __builtin_rotateleft32(r31.u32, 1);
	// divw r10,r31,r30
	ctx.r10.s32 = r31.s32 / r30.s32;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// mullw r8,r10,r30
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(r30.s32);
	// andc r7,r30,r9
	ctx.r7.u64 = r30.u64 & ~ctx.r9.u64;
	// subf r4,r8,r31
	ctx.r4.s64 = r31.s64 - ctx.r8.s64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// twllei r30,0
	// twlgei r7,-1
	// bl 0x8262fff0
	ctx.lr = 0x82631834;
	sub_8262FFF0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82631840:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8263184C"))) PPC_WEAK_FUNC(sub_8263184C);
PPC_FUNC_IMPL(__imp__sub_8263184C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631850"))) PPC_WEAK_FUNC(sub_82631850);
PPC_FUNC_IMPL(__imp__sub_82631850) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e4
	ctx.lr = 0x82631858;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82630158
	ctx.lr = 0x82631864;
	sub_82630158(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lhz r31,192(r29)
	r31.u64 = PPC_LOAD_U16(r29.u32 + 192);
	// addi r23,r29,208
	r23.s64 = r29.s64 + 208;
	// addi r4,r11,20292
	ctx.r4.s64 = r11.s64 + 20292;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x82722678
	ctx.lr = 0x82631880;
	sub_82722678(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// li r11,2
	r11.s64 = 2;
	// beq cr6,0x826318a0
	if (cr6.eq) goto loc_826318A0;
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
loc_826318A0:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x826318A8;
	sub_82722678(ctx, base);
	// li r24,0
	r24.s64 = 0;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-10308
	ctx.r4.s64 = ctx.r9.s64 + -10308;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82722678
	ctx.lr = 0x826318C4;
	sub_82722678(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,4
	r30.s64 = 4;
	// mr r31,r24
	r31.u64 = r24.u64;
	// li r28,3
	r28.s64 = 3;
	// lis r25,-32126
	r25.s64 = -2105409536;
	// addi r26,r11,-11008
	r26.s64 = r11.s64 + -11008;
loc_826318DC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r31,2
	ctx.r5.s64 = r31.s64 + 2;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x826318EC;
	sub_823DC018(ctx, base);
	// lhz r11,192(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 192);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bge cr6,0x82631914
	if (!cr6.lt) goto loc_82631914;
	// lwz r11,188(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 188);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82631918
	goto loc_82631918;
loc_82631914:
	// lwz r5,24288(r25)
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + 24288);
loc_82631918:
	// bl 0x827227b8
	ctx.lr = 0x8263191C;
	sub_827227B8(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x826318dc
	if (!cr0.eq) goto loc_826318DC;
	// lwz r11,0(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 0);
	// cmpwi cr6,r11,15
	cr6.compare<int32_t>(r11.s32, 15, xer);
	// bne cr6,0x82631a14
	if (!cr6.eq) goto loc_82631A14;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82631944;
	sub_8238EC00(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82631a14
	if (cr6.eq) goto loc_82631A14;
	// bl 0x82256058
	ctx.lr = 0x82631954;
	sub_82256058(ctx, base);
	// lwz r31,48(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// bl 0x82256058
	ctx.lr = 0x82631960;
	sub_82256058(ctx, base);
	// lwz r11,180(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 180);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82631978
	if (!cr6.eq) goto loc_82631978;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,8
	ctx.r10.s64 = r11.s64 + 8;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_82631978:
	// bl 0x82256058
	ctx.lr = 0x8263197C;
	sub_82256058(ctx, base);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lfs f0,-13148(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13148);
	f0.f64 = double(temp.f32);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lfs f13,36(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,24(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * f0.f64));
	// fcmpu cr6,f11,f10
	cr6.compare(ctx.f11.f64, ctx.f10.f64);
	// ble cr6,0x826319b8
	if (!cr6.gt) goto loc_826319B8;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_826319B8:
	// bl 0x82256058
	ctx.lr = 0x826319BC;
	sub_82256058(ctx, base);
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,136(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 136);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// bge cr6,0x826319ec
	if (!cr6.lt) goto loc_826319EC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,2
	ctx.r10.s64 = r11.s64 + 2;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
loc_826319EC:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,14
	cr6.compare<int32_t>(r11.s32, 14, xer);
	// bne cr6,0x82631a00
	if (!cr6.eq) goto loc_82631A00;
	// li r11,15
	r11.s64 = 15;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_82631A00:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-11016
	ctx.r4.s64 = r11.s64 + -11016;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82722678
	ctx.lr = 0x82631A14;
	sub_82722678(ctx, base);
loc_82631A14:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82631A1C"))) PPC_WEAK_FUNC(sub_82631A1C);
PPC_FUNC_IMPL(__imp__sub_82631A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631A20"))) PPC_WEAK_FUNC(sub_82631A20);
PPC_FUNC_IMPL(__imp__sub_82631A20) {
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
	ctx.lr = 0x82631A28;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82630158
	ctx.lr = 0x82631A34;
	sub_82630158(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r10,r11,-12116
	ctx.r10.s64 = r11.s64 + -12116;
	// li r31,0
	r31.s64 = 0;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x821c9790
	ctx.lr = 0x82631A60;
	sub_821C9790(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82631A74;
	sub_825EF9F0(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82631A8C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x82631A94;
	sub_825EF9F0(ctx, base);
	// lwz r5,200(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82631b40
	if (cr6.eq) goto loc_82631B40;
	// rotlwi r3,r5,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631AB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82631b9c
	if (!cr6.gt) goto loc_82631B9C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r27,r11,-13276
	r27.s64 = r11.s64 + -13276;
loc_82631AD0:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631AE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,200(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r28,-10244(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82631B10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82218310
	ctx.lr = 0x82631B1C;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x827227b8
	ctx.lr = 0x82631B2C;
	sub_827227B8(ctx, base);
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpw cr6,r31,r6
	cr6.compare<int32_t>(r31.s32, ctx.r6.s32, xer);
	// blt cr6,0x82631ad0
	if (cr6.lt) goto loc_82631AD0;
	// b 0x82631b9c
	goto loc_82631B9C;
loc_82631B40:
	// lhz r11,192(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 192);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// ble cr6,0x82631b9c
	if (!cr6.gt) goto loc_82631B9C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// mr r28,r31
	r28.u64 = r31.u64;
	// addi r27,r11,-13276
	r27.s64 = r11.s64 + -13276;
loc_82631B5C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631B74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,188(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 188);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwzx r8,r28,r9
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + ctx.r9.u32);
	// lwz r5,4(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x827227b8
	ctx.lr = 0x82631B88;
	sub_827227B8(ctx, base);
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpw cr6,r31,r7
	cr6.compare<int32_t>(r31.s32, ctx.r7.s32, xer);
	// blt cr6,0x82631b5c
	if (cr6.lt) goto loc_82631B5C;
loc_82631B9C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631BB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r8,-13284
	ctx.r4.s64 = ctx.r8.s64 + -13284;
	// rlwinm r6,r7,28,30,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 28) & 0x2;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82722678
	ctx.lr = 0x82631BD4;
	sub_82722678(ctx, base);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,-10308
	ctx.r4.s64 = ctx.r4.s64 + -10308;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82722678
	ctx.lr = 0x82631BE8;
	sub_82722678(ctx, base);
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r5,r30,208
	ctx.r5.s64 = r30.s64 + 208;
	// addi r4,r3,620
	ctx.r4.s64 = ctx.r3.s64 + 620;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82722678
	ctx.lr = 0x82631BFC;
	sub_82722678(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82631C04"))) PPC_WEAK_FUNC(sub_82631C04);
PPC_FUNC_IMPL(__imp__sub_82631C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631C08"))) PPC_WEAK_FUNC(sub_82631C08);
PPC_FUNC_IMPL(__imp__sub_82631C08) {
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
	ctx.lr = 0x82631C10;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x82630158
	ctx.lr = 0x82631C1C;
	sub_82630158(ctx, base);
	// lhz r11,192(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 192);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// bne cr6,0x82631c40
	if (!cr6.eq) goto loc_82631C40;
	// li r11,2
	r11.s64 = 2;
	// b 0x82631c44
	goto loc_82631C44;
loc_82631C40:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
loc_82631C44:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x82631C4C;
	sub_82722678(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-10308
	ctx.r4.s64 = ctx.r9.s64 + -10308;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82722678
	ctx.lr = 0x82631C68;
	sub_82722678(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,4
	r30.s64 = 4;
	// li r28,3
	r28.s64 = 3;
	// lis r25,-32126
	r25.s64 = -2105409536;
	// addi r26,r11,-11008
	r26.s64 = r11.s64 + -11008;
loc_82631C7C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r31,2
	ctx.r5.s64 = r31.s64 + 2;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823dc018
	ctx.lr = 0x82631C8C;
	sub_823DC018(ctx, base);
	// lhz r11,192(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 192);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bge cr6,0x82631cb4
	if (!cr6.lt) goto loc_82631CB4;
	// lwz r11,188(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 188);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x82631cb8
	goto loc_82631CB8;
loc_82631CB4:
	// lwz r5,24288(r25)
	ctx.r5.u64 = PPC_LOAD_U32(r25.u32 + 24288);
loc_82631CB8:
	// bl 0x827227b8
	ctx.lr = 0x82631CBC;
	sub_827227B8(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82631c7c
	if (!cr0.eq) goto loc_82631C7C;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82631CD4"))) PPC_WEAK_FUNC(sub_82631CD4);
PPC_FUNC_IMPL(__imp__sub_82631CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631CD8"))) PPC_WEAK_FUNC(sub_82631CD8);
PPC_FUNC_IMPL(__imp__sub_82631CD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,180(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r10,176(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,-4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,176(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 176);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82631D08"))) PPC_WEAK_FUNC(sub_82631D08);
PPC_FUNC_IMPL(__imp__sub_82631D08) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82631D0C"))) PPC_WEAK_FUNC(sub_82631D0C);
PPC_FUNC_IMPL(__imp__sub_82631D0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631D10"))) PPC_WEAK_FUNC(sub_82631D10);
PPC_FUNC_IMPL(__imp__sub_82631D10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,180(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82631d40
	if (cr6.eq) goto loc_82631D40;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r10,176(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,-4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,32(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82631D40:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82631D48"))) PPC_WEAK_FUNC(sub_82631D48);
PPC_FUNC_IMPL(__imp__sub_82631D48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r11,180(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 180);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// clrlwi r11,r11,16
	r11.u64 = r11.u32 & 0xFFFF;
	// lwz r10,176(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 176);
	// rotlwi r11,r11,2
	r11.u64 = __builtin_rotateleft32(r11.u32, 2);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,-4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,184(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 184);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82631D78"))) PPC_WEAK_FUNC(sub_82631D78);
PPC_FUNC_IMPL(__imp__sub_82631D78) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82631D7C"))) PPC_WEAK_FUNC(sub_82631D7C);
PPC_FUNC_IMPL(__imp__sub_82631D7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631D80"))) PPC_WEAK_FUNC(sub_82631D80);
PPC_FUNC_IMPL(__imp__sub_82631D80) {
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
	ctx.lr = 0x82631D88;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x82631D94;
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
	ctx.lr = 0x82631DA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82631e14
	if (cr6.eq) goto loc_82631E14;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631DC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r29,r9,-10292
	r29.s64 = ctx.r9.s64 + -10292;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x82631DE0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82631DF0;
	sub_825ED480(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r5,r31,176
	ctx.r5.s64 = r31.s64 + 176;
	// addi r4,r8,-11000
	ctx.r4.s64 = ctx.r8.s64 + -11000;
	// bl 0x82722718
	ctx.lr = 0x82631E00;
	sub_82722718(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r7,-10300
	ctx.r4.s64 = ctx.r7.s64 + -10300;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82631E14;
	sub_825EE0E0(ctx, base);
loc_82631E14:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82631E1C"))) PPC_WEAK_FUNC(sub_82631E1C);
PPC_FUNC_IMPL(__imp__sub_82631E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82631E20"))) PPC_WEAK_FUNC(sub_82631E20);
PPC_FUNC_IMPL(__imp__sub_82631E20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r19{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82631E28;
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
	// lwz r10,512(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 512);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631E48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82631e5c
	if (cr6.eq) goto loc_82631E5C;
	// li r31,0
	r31.s64 = 0;
	// b 0x82631e7c
	goto loc_82631E7C;
loc_82631E5C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631E78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_82631E7C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82631ef4
	if (cr6.eq) goto loc_82631EF4;
	// addi r11,r30,-47
	r11.s64 = r30.s64 + -47;
	// cmplwi cr6,r11,11
	cr6.compare<uint32_t>(r11.u32, 11, xer);
	// bgt cr6,0x82631edc
	if (cr6.gt) goto loc_82631EDC;
	// lis r12,-32157
	r12.s64 = -2107441152;
	// addi r12,r12,7852
	r12.s64 = r12.s64 + 7852;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82631EF4;
	case 1:
		goto loc_82631EF4;
	case 2:
		goto loc_82631EF4;
	case 3:
		goto loc_82631EF4;
	case 4:
		goto loc_82631EF4;
	case 5:
		goto loc_82631EF4;
	case 6:
		goto loc_82631EF4;
	case 7:
		goto loc_82631EF4;
	case 8:
		goto loc_82631EDC;
	case 9:
		goto loc_82631EDC;
	case 10:
		goto loc_82631EF4;
	case 11:
		goto loc_82631EF4;
	default:
		__builtin_unreachable();
	}
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7900(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7900);
	// lwz r19,7900(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7900);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
	// lwz r19,7924(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 7924);
loc_82631EDC:
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
	ctx.lr = 0x82631EF4;
	sub_8221D6A8(ctx, base);
loc_82631EF4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82631F00"))) PPC_WEAK_FUNC(sub_82631F00);
PPC_FUNC_IMPL(__imp__sub_82631F00) {
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
	ctx.lr = 0x82631F08;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,246(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 246);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82631f80
	if (!cr6.eq) goto loc_82631F80;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r29,1
	r29.s64 = 1;
	// stb r29,246(r31)
	PPC_STORE_U8(r31.u32 + 246, r29.u8);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x82631f40
	if (!cr6.eq) goto loc_82631F40;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82631F40:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,776
	ctx.r3.s64 = r11.s64 + 776;
	// bl 0x8268f6a8
	ctx.lr = 0x82631F4C;
	sub_8268F6A8(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r4,r11,4
	ctx.r4.s64 = r11.s64 + 4;
	// bne cr6,0x82631f64
	if (!cr6.eq) goto loc_82631F64;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82631F64:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,348(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 348);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631F78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x82215a60
	ctx.lr = 0x82631F7C;
	sub_82215A60(ctx, base);
	// stb r29,252(r31)
	PPC_STORE_U8(r31.u32 + 252, r29.u8);
loc_82631F80:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82631F88"))) PPC_WEAK_FUNC(sub_82631F88);
PPC_FUNC_IMPL(__imp__sub_82631F88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,196(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82631fa8
	if (cr6.eq) goto loc_82631FA8;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,324(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 324);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82631FA8:
	// lwz r11,192(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82631fc8
	if (cr6.eq) goto loc_82631FC8;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
loc_82631FC8:
	// lhz r3,180(r3)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r3.u32 + 180);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82631FD0"))) PPC_WEAK_FUNC(sub_82631FD0);
PPC_FUNC_IMPL(__imp__sub_82631FD0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82631FD8;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82631FF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826326c8
	if (cr6.eq) goto loc_826326C8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630980
	ctx.lr = 0x82632004;
	sub_82630980(ctx, base);
	// lwz r3,196(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82632024
	if (cr6.eq) goto loc_82632024;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,324(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 324);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82632048
	goto loc_82632048;
loc_82632024:
	// lwz r3,192(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82632044
	if (cr6.eq) goto loc_82632044;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632040;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82632048
	goto loc_82632048;
loc_82632044:
	// lhz r3,180(r30)
	ctx.r3.u64 = PPC_LOAD_U16(r30.u32 + 180);
loc_82632048:
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r26,0
	r26.s64 = 0;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x82632068
	if (!cr6.lt) goto loc_82632068;
	// mr r11,r26
	r11.u64 = r26.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// b 0x8263207c
	goto loc_8263207C;
loc_82632068:
	// ble cr6,0x8263207c
	if (!cr6.gt) goto loc_8263207C;
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x8263207c
	if (!cr6.eq) goto loc_8263207C;
	// stw r26,184(r30)
	PPC_STORE_U32(r30.u32 + 184, r26.u32);
loc_8263207C:
	// lwz r10,184(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// bge cr6,0x82632090
	if (!cr6.lt) goto loc_82632090;
	// stw r26,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r26.u32);
loc_82632090:
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x826320a4
	if (cr6.lt) goto loc_826320A4;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
loc_826320A4:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826320B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826320cc
	if (!cr6.eq) goto loc_826320CC;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
loc_826320CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826320E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826326c8
	if (cr6.eq) goto loc_826326C8;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826320FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r9,2612
	r29.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9790
	ctx.lr = 0x82632114;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x825ed480
	ctx.lr = 0x82632124;
	sub_825ED480(ctx, base);
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// addi r20,r11,-10308
	r20.s64 = r11.s64 + -10308;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// stw r19,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r19.u32);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// bl 0x82722678
	ctx.lr = 0x82632144;
	sub_82722678(ctx, base);
	// lhz r11,212(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 212);
	// li r15,1
	r15.s64 = 1;
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bgt cr6,0x8263215c
	if (cr6.gt) goto loc_8263215C;
	// stw r15,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r15.u32);
loc_8263215C:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r18,r11,-13284
	r18.s64 = r11.s64 + -13284;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// bl 0x82722678
	ctx.lr = 0x82632174;
	sub_82722678(ctx, base);
	// lhz r10,212(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 212);
	// mr r11,r26
	r11.u64 = r26.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826321dc
	if (cr6.eq) goto loc_826321DC;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r29,r26
	r29.u64 = r26.u64;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r28,r10,-10948
	r28.s64 = ctx.r10.s64 + -10948;
loc_82632194:
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823dc018
	ctx.lr = 0x826321A8;
	sub_823DC018(ctx, base);
	// lwz r11,208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 208);
	// lwz r3,-10244(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10244);
	// lwzx r4,r29,r11
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
	// bl 0x82218310
	ctx.lr = 0x826321B8;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x827227b8
	ctx.lr = 0x826321C8;
	sub_827227B8(ctx, base);
	// lhz r10,212(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 212);
	// mr r11,r31
	r11.u64 = r31.u64;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x82632194
	if (cr6.lt) goto loc_82632194;
loc_826321DC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r26,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r26.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r3,r11,-12116
	ctx.r3.s64 = r11.s64 + -12116;
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x826321FC;
	sub_821C9790(ctx, base);
	// stw r3,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r3.u32);
	// stw r15,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r15.u32);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x825ef9f0
	ctx.lr = 0x8263220C;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,136
	ctx.r5.s64 = ctx.r1.s64 + 136;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// lwz r8,36(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82632224;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// bl 0x825ef9f0
	ctx.lr = 0x8263222C;
	sub_825EF9F0(ctx, base);
	// lwz r7,196(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// bne cr6,0x8263224c
	if (!cr6.eq) goto loc_8263224C;
	// lwz r11,192(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8263225c
	if (cr6.eq) goto loc_8263225C;
loc_8263224C:
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82722678
	ctx.lr = 0x8263225C;
	sub_82722678(ctx, base);
loc_8263225C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r26
	r31.u64 = r26.u64;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,660(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 660);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,664(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 664);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82632290;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r25,r3
	cr6.compare<int32_t>(r25.s32, ctx.r3.s32, xer);
	// bge cr6,0x82632654
	if (!cr6.lt) goto loc_82632654;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r5,255
	ctx.r5.s64 = 16711680;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// addi r4,r11,-11008
	ctx.r4.s64 = r11.s64 + -11008;
	// rlwinm r14,r25,2,0,29
	r14.u64 = __builtin_rotateleft64(r25.u32 | (r25.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r28,r5,65535
	r28.u64 = ctx.r5.u64 | 65535;
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// li r16,56
	r16.s64 = 56;
	// addi r17,r10,-13268
	r17.s64 = ctx.r10.s64 + -13268;
	// addi r21,r9,20292
	r21.s64 = ctx.r9.s64 + 20292;
	// addi r24,r8,-18156
	r24.s64 = ctx.r8.s64 + -18156;
	// addi r23,r7,-10952
	r23.s64 = ctx.r7.s64 + -10952;
	// addi r22,r6,20268
	r22.s64 = ctx.r6.s64 + 20268;
	// b 0x826322e4
	goto loc_826322E4;
loc_826322E0:
	// lwz r31,96(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
loc_826322E4:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632300;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// bge cr6,0x82632654
	if (!cr6.lt) goto loc_82632654;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632320;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,196(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 196);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826323e4
	if (cr6.eq) goto loc_826323E4;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x8263233C;
	sub_8268DCB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,332(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 332);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263234C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x8263235C;
	sub_827227B8(ctx, base);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82632370;
	sub_82722678(ctx, base);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82632384;
	sub_82722678(ctx, base);
	// stw r15,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r15.u32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82632398;
	sub_82722678(ctx, base);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x826323AC;
	sub_82722678(ctx, base);
	// stw r15,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r15.u32);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x826323C0;
	sub_82722678(ctx, base);
	// stw r16,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r16.u32);
	// mr r4,r17
	ctx.r4.u64 = r17.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x826323D4;
	sub_82722678(ctx, base);
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// b 0x82632630
	goto loc_82632630;
loc_826323E4:
	// lwz r3,192(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82632524
	if (cr6.eq) goto loc_82632524;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r27,r26
	r27.u64 = r26.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632404;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// ble cr6,0x82632510
	if (!cr6.gt) goto loc_82632510;
loc_82632410:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,652(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 652);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263242C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bne cr6,0x826324e0
	if (!cr6.eq) goto loc_826324E0;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82632448;
	sub_827227B8(ctx, base);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x8263245C;
	sub_82722678(ctx, base);
	// stw r28,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r28.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82632470;
	sub_82722678(ctx, base);
	// lwz r3,192(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263248C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x826324A0;
	sub_82722678(ctx, base);
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x826324B4;
	sub_82722678(ctx, base);
	// lwz r3,192(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 192);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826324C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r3.u32);
	// mr r4,r18
	ctx.r4.u64 = r18.u64;
	// addi r5,r1,108
	ctx.r5.s64 = ctx.r1.s64 + 108;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x826324DC;
	sub_82722678(ctx, base);
	// b 0x82632500
	goto loc_82632500;
loc_826324E0:
	// addi r5,r27,1
	ctx.r5.s64 = r27.s64 + 1;
	// lwz r4,112(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x823dc018
	ctx.lr = 0x826324F0;
	sub_823DC018(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82632500;
	sub_827227B8(ctx, base);
loc_82632500:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpw cr6,r27,r19
	cr6.compare<int32_t>(r27.s32, r19.s32, xer);
	// blt cr6,0x82632410
	if (cr6.lt) goto loc_82632410;
	// lwz r29,92(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82632510:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r19,116(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// b 0x82632630
	goto loc_82632630;
loc_82632524:
	// lwz r11,176(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// lwzx r29,r14,r11
	r29.u64 = PPC_LOAD_U32(r14.u32 + r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82632540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8263262c
	if (cr6.eq) goto loc_8263262C;
	// lwz r11,176(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 176);
	// lwzx r3,r14,r11
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,332(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 332);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82632564;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82632574;
	sub_827227B8(ctx, base);
	// lwz r8,176(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x8263258C;
	sub_82722678(ctx, base);
	// lwz r7,180(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 180);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r7.u32);
	// bl 0x82722678
	ctx.lr = 0x826325A4;
	sub_82722678(ctx, base);
	// lwz r6,0(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,72(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 72);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826325B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// stw r15,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r15.u32);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x826325d8
	if (!cr6.eq) goto loc_826325D8;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
loc_826325D8:
	// bl 0x82722678
	ctx.lr = 0x826325DC;
	sub_82722678(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826325F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,196(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82632608;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,176(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 176);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8263261C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82722398
	ctx.lr = 0x8263262C;
	sub_82722398(ctx, base);
loc_8263262C:
	// lwz r29,92(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82632630:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r14,r14,4
	r14.s64 = r14.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263264C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r25,r3
	cr6.compare<int32_t>(r25.s32, ctx.r3.s32, xer);
	// blt cr6,0x826322e0
	if (cr6.lt) goto loc_826322E0;
loc_82632654:
	// lbz r11,204(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 204);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bne cr6,0x82632668
	if (!cr6.eq) goto loc_82632668;
	// li r11,-1
	r11.s64 = -1;
loc_82632668:
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r11,620
	ctx.r4.s64 = r11.s64 + 620;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82722678
	ctx.lr = 0x82632680;
	sub_82722678(ctx, base);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r5,r30,188
	ctx.r5.s64 = r30.s64 + 188;
	// addi r4,r10,-10964
	ctx.r4.s64 = ctx.r10.s64 + -10964;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82722678
	ctx.lr = 0x82632694;
	sub_82722678(ctx, base);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r9,-10984
	r31.s64 = ctx.r9.s64 + -10984;
	// lwz r7,468(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826326B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x826326BC;
	sub_825EE0E0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82635840
	ctx.lr = 0x826326C8;
	sub_82635840(ctx, base);
loc_826326C8:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_826326D0"))) PPC_WEAK_FUNC(sub_826326D0);
PPC_FUNC_IMPL(__imp__sub_826326D0) {
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
	ctx.lr = 0x826326D8;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82631fd0
	ctx.lr = 0x826326E8;
	sub_82631FD0(ctx, base);
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x826328c0
	if (!cr6.eq) goto loc_826328C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632708;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826328c0
	if (cr6.eq) goto loc_826328C0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826328c0
	if (cr6.eq) goto loc_826328C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x82632738;
	sub_82631F88(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r30,r10,2612
	r30.s64 = ctx.r10.s64 + 2612;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82632758;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82203008
	ctx.lr = 0x82632760;
	sub_82203008(ctx, base);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpw cr6,r11,r29
	cr6.compare<int32_t>(r11.s32, r29.s32, xer);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// blt cr6,0x82632778
	if (cr6.lt) goto loc_82632778;
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
loc_82632778:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-10308
	ctx.r4.s64 = r11.s64 + -10308;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8263278C;
	sub_82722678(ctx, base);
	// lbz r10,204(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 204);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826327ac
	if (cr6.eq) goto loc_826327AC;
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// b 0x826327b4
	goto loc_826327B4;
loc_826327AC:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_826327B4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,620
	ctx.r4.s64 = r11.s64 + 620;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x826327C8;
	sub_82722678(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x826327D0;
	sub_82631F88(ctx, base);
	// lwz r10,188(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r3,r10
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r10.s32, xer);
	// bgt cr6,0x826327e4
	if (cr6.gt) goto loc_826327E4;
	// li r11,0
	r11.s64 = 0;
loc_826327E4:
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// cntlzw r9,r30
	ctx.r9.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// addi r28,r10,-10984
	r28.s64 = ctx.r10.s64 + -10984;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r7,468(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// xori r27,r8,1
	r27.u64 = ctx.r8.u64 ^ 1;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82632810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8263281C;
	sub_825EE0E0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82632894
	if (cr6.eq) goto loc_82632894;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82632894
	if (!cr6.gt) goto loc_82632894;
	// addi r11,r29,-1
	r11.s64 = r29.s64 + -1;
	// lwz r10,184(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// extsw r7,r11
	ctx.r7.s64 = r11.s32;
	// extsw r6,r10
	ctx.r6.s64 = ctx.r10.s32;
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r6,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r6.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// lwz r5,468(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 468);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// addi r30,r8,-10936
	r30.s64 = ctx.r8.s64 + -10936;
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fdivs f31,f10,f9
	f31.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8263287C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x825ee188
	ctx.lr = 0x82632888;
	sub_825EE188(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82632894:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-10936
	r31.s64 = ctx.r10.s64 + -10936;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826328B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825ee188
	ctx.lr = 0x826328C0;
	sub_825EE188(ctx, base);
loc_826328C0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_826328CC"))) PPC_WEAK_FUNC(sub_826328CC);
PPC_FUNC_IMPL(__imp__sub_826328CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826328D0"))) PPC_WEAK_FUNC(sub_826328D0);
PPC_FUNC_IMPL(__imp__sub_826328D0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82632908
	if (cr6.eq) goto loc_82632908;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632904;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x8263290c
	goto loc_8263290C;
loc_82632908:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8263290C:
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

__attribute__((alias("__imp__sub_8263292C"))) PPC_WEAK_FUNC(sub_8263292C);
PPC_FUNC_IMPL(__imp__sub_8263292C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82632930"))) PPC_WEAK_FUNC(sub_82632930);
PPC_FUNC_IMPL(__imp__sub_82632930) {
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
	ctx.lr = 0x82632938;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82630980
	ctx.lr = 0x82632944;
	sub_82630980(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// addi r24,r11,-10256
	r24.s64 = r11.s64 + -10256;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-10236(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8263295C;
	sub_821F9FB8(ctx, base);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// addi r25,r11,-10292
	r25.s64 = r11.s64 + -10292;
	// beq cr6,0x826329ac
	if (cr6.eq) goto loc_826329AC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82632994;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x826329A4;
	sub_825ED480(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826329b0
	if (!cr6.eq) goto loc_826329B0;
loc_826329AC:
	// lwz r22,56(r30)
	r22.u64 = PPC_LOAD_U32(r30.u32 + 56);
loc_826329B0:
	// lwz r11,56(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// li r31,0
	r31.s64 = 0;
	// cmplw cr6,r11,r22
	cr6.compare<uint32_t>(r11.u32, r22.u32, xer);
	// bne cr6,0x826329e8
	if (!cr6.eq) goto loc_826329E8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82720e28
	ctx.lr = 0x826329CC;
	sub_82720E28(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r3,56(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// addi r4,r11,-10300
	ctx.r4.s64 = r11.s64 + -10300;
	// bl 0x825ee0e0
	ctx.lr = 0x826329E0;
	sub_825EE0E0(ctx, base);
	// li r28,1
	r28.s64 = 1;
	// b 0x826329ec
	goto loc_826329EC;
loc_826329E8:
	// mr r28,r31
	r28.u64 = r31.u64;
loc_826329EC:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826329F8;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x82632A08;
	sub_825ED480(ctx, base);
	// lbz r11,204(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 204);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// beq cr6,0x82632a2c
	if (cr6.eq) goto loc_82632A2C;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,-10888
	ctx.r4.s64 = r11.s64 + -10888;
	// b 0x82632a34
	goto loc_82632A34;
loc_82632A2C:
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,-10904
	ctx.r4.s64 = r11.s64 + -10904;
loc_82632A34:
	// bl 0x825ee120
	ctx.lr = 0x82632A38;
	sub_825EE120(ctx, base);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,-13268
	ctx.r4.s64 = r11.s64 + -13268;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x82632A4C;
	sub_82722678(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r27,r29,180
	r27.s64 = r29.s64 + 180;
	// addi r26,r11,-10308
	r26.s64 = r11.s64 + -10308;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x82632A68;
	sub_82722678(ctx, base);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,60(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 60);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82632A7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82632be4
	if (cr6.eq) goto loc_82632BE4;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82632be4
	if (!cr6.gt) goto loc_82632BE4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r3,r11,-12116
	ctx.r3.s64 = r11.s64 + -12116;
	// stw r10,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x82632AB4;
	sub_821C9790(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r3,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x82632AC8;
	sub_825EF9F0(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82632AE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x825ef9f0
	ctx.lr = 0x82632AE8;
	sub_825EF9F0(ctx, base);
	// lwz r6,0(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x82632c34
	if (!cr6.gt) goto loc_82632C34;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// mr r28,r31
	r28.u64 = r31.u64;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// addi r26,r11,-13284
	r26.s64 = r11.s64 + -13284;
	// addi r25,r10,-10912
	r25.s64 = ctx.r10.s64 + -10912;
	// addi r24,r9,20268
	r24.s64 = ctx.r9.s64 + 20268;
loc_82632B18:
	// lwz r11,176(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// lwz r3,-10244(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10244);
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82218310
	ctx.lr = 0x82632B2C;
	sub_82218310(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82632B48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// bl 0x827227b8
	ctx.lr = 0x82632B54;
	sub_827227B8(ctx, base);
	// lwz r8,176(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r21,r1,84
	r21.s64 = ctx.r1.s64 + 84;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r6,r8,r28
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + r28.u32);
	// lwz r5,80(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82632B7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// bl 0x82722678
	ctx.lr = 0x82632B88;
	sub_82722678(ctx, base);
	// lwz r11,176(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 176);
	// lwz r10,208(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 208);
	// addi r21,r1,88
	r21.s64 = ctx.r1.s64 + 88;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// subf r8,r11,r10
	ctx.r8.s64 = ctx.r10.s64 - r11.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r5,80(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82632BC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// bl 0x82722678
	ctx.lr = 0x82632BCC;
	sub_82722678(ctx, base);
	// lwz r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r28,r28,8
	r28.s64 = r28.s64 + 8;
	// cmpw cr6,r31,r4
	cr6.compare<int32_t>(r31.s32, ctx.r4.s32, xer);
	// blt cr6,0x82632b18
	if (cr6.lt) goto loc_82632B18;
	// b 0x82632c34
	goto loc_82632C34;
loc_82632BE4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82632c34
	if (cr6.eq) goto loc_82632C34;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// lwz r3,-10236(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82632BFC;
	sub_821F9FB8(ctx, base);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r31,r1,88
	r31.s64 = ctx.r1.s64 + 88;
	// lwz r30,56(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x82632C18;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// bl 0x825ed480
	ctx.lr = 0x82632C28;
	sub_825ED480(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82632C34;
	sub_82722678(ctx, base);
loc_82632C34:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r31,r11,1072
	r31.s64 = r11.s64 + 1072;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x825ee120
	ctx.lr = 0x82632C4C;
	sub_825EE120(ctx, base);
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82632c60
	if (cr6.lt) goto loc_82632C60;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82632c70
	if (!cr6.gt) goto loc_82632C70;
loc_82632C60:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82632C70;
	sub_825EE0E0(ctx, base);
loc_82632C70:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-10268
	ctx.r4.s64 = r11.s64 + -10268;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82632C84;
	sub_825EE0E0(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-10284
	ctx.r4.s64 = ctx.r10.s64 + -10284;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82632C98;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82632CA0"))) PPC_WEAK_FUNC(sub_82632CA0);
PPC_FUNC_IMPL(__imp__sub_82632CA0) {
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
	// bl 0x82631c08
	ctx.lr = 0x82632CBC;
	sub_82631C08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630070
	ctx.lr = 0x82632CC4;
	sub_82630070(ctx, base);
	// lwz r11,216(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 216);
	// addi r5,r31,216
	ctx.r5.s64 = r31.s64 + 216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82632ce4
	if (cr6.eq) goto loc_82632CE4;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,20292
	ctx.r4.s64 = r11.s64 + 20292;
	// bl 0x82722678
	ctx.lr = 0x82632CE4;
	sub_82722678(ctx, base);
loc_82632CE4:
	// lbz r11,209(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 209);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82632d44
	if (cr6.eq) goto loc_82632D44;
	// lbz r11,208(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 208);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r10,620
	ctx.r4.s64 = ctx.r10.s64 + 620;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stw r7,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// bl 0x82722678
	ctx.lr = 0x82632D18;
	sub_82722678(ctx, base);
	// lwz r11,212(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 212);
	// lis r6,-32255
	ctx.r6.s64 = -2113863680;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// addi r4,r6,-13284
	ctx.r4.s64 = ctx.r6.s64 + -13284;
	// rlwinm r11,r9,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r8,r11,6
	ctx.r8.s64 = r11.s64 + 6;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// b 0x82632d54
	goto loc_82632D54;
loc_82632D44:
	// li r11,0
	r11.s64 = 0;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
loc_82632D54:
	// bl 0x82722678
	ctx.lr = 0x82632D58;
	sub_82722678(ctx, base);
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

__attribute__((alias("__imp__sub_82632D70"))) PPC_WEAK_FUNC(sub_82632D70);
PPC_FUNC_IMPL(__imp__sub_82632D70) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82631c08
	ctx.lr = 0x82632D88;
	sub_82631C08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630070
	ctx.lr = 0x82632D90;
	sub_82630070(ctx, base);
	// li r11,33
	r11.s64 = 33;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// bl 0x82722678
	ctx.lr = 0x82632DA8;
	sub_82722678(ctx, base);
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

__attribute__((alias("__imp__sub_82632DBC"))) PPC_WEAK_FUNC(sub_82632DBC);
PPC_FUNC_IMPL(__imp__sub_82632DBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82632DC0"))) PPC_WEAK_FUNC(sub_82632DC0);
PPC_FUNC_IMPL(__imp__sub_82632DC0) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82631a20
	ctx.lr = 0x82632DD8;
	sub_82631A20(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630070
	ctx.lr = 0x82632DE0;
	sub_82630070(ctx, base);
	// li r11,33
	r11.s64 = 33;
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-13284
	ctx.r4.s64 = ctx.r10.s64 + -13284;
	// bl 0x82722678
	ctx.lr = 0x82632DF8;
	sub_82722678(ctx, base);
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

__attribute__((alias("__imp__sub_82632E0C"))) PPC_WEAK_FUNC(sub_82632E0C);
PPC_FUNC_IMPL(__imp__sub_82632E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82632E10"))) PPC_WEAK_FUNC(sub_82632E10);
PPC_FUNC_IMPL(__imp__sub_82632E10) {
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632E38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631fd0
	ctx.lr = 0x82632E44;
	sub_82631FD0(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r31,r9,2612
	r31.s64 = ctx.r9.s64 + 2612;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x82632E58;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x825ed480
	ctx.lr = 0x82632E68;
	sub_825ED480(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r7,-13284
	ctx.r4.s64 = ctx.r7.s64 + -13284;
	// bl 0x82722678
	ctx.lr = 0x82632E80;
	sub_82722678(ctx, base);
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

__attribute__((alias("__imp__sub_82632E98"))) PPC_WEAK_FUNC(sub_82632E98);
PPC_FUNC_IMPL(__imp__sub_82632E98) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,204
	ctx.r3.s64 = r31.s64 + 204;
	// bl 0x821c3048
	ctx.lr = 0x82632EC0;
	sub_821C3048(ctx, base);
	// addi r11,r31,176
	r11.s64 = r31.s64 + 176;
	// lwz r9,176(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,184
	ctx.r3.s64 = r31.s64 + 184;
	// lhz r11,180(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,180(r31)
	PPC_STORE_U16(r31.u32 + 180, ctx.r8.u16);
	// stwx r30,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, r30.u32);
	// bl 0x821c3048
	ctx.lr = 0x82632EE8;
	sub_821C3048(ctx, base);
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

__attribute__((alias("__imp__sub_82632F00"))) PPC_WEAK_FUNC(sub_82632F00);
PPC_FUNC_IMPL(__imp__sub_82632F00) {
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
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632F2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82632f50
	if (cr6.eq) goto loc_82632F50;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r10,-10868
	ctx.r4.s64 = ctx.r10.s64 + -10868;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82632F4C;
	sub_821F9FB8(ctx, base);
	// lwz r31,56(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
loc_82632F50:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630c38
	ctx.lr = 0x82632F5C;
	sub_82630C38(ctx, base);
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

__attribute__((alias("__imp__sub_82632F74"))) PPC_WEAK_FUNC(sub_82632F74);
PPC_FUNC_IMPL(__imp__sub_82632F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82632F78"))) PPC_WEAK_FUNC(sub_82632F78);
PPC_FUNC_IMPL(__imp__sub_82632F78) {
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
	ctx.lr = 0x82632F80;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632F98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,204(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82632ff8
	if (!cr6.eq) goto loc_82632FF8;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82632fbc
	if (cr6.eq) goto loc_82632FBC;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,304(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 304);
	// bl 0x82720e28
	ctx.lr = 0x82632FBC;
	sub_82720E28(ctx, base);
loc_82632FBC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82632FD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82633200
	if (cr6.eq) goto loc_82633200;
	// lbz r11,246(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 246);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82633200
	if (cr6.eq) goto loc_82633200;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630980
	ctx.lr = 0x82632FF0;
	sub_82630980(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82632FF8:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263300C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826331f0
	if (cr6.eq) goto loc_826331F0;
	// lbz r11,246(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 246);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826331f0
	if (cr6.eq) goto loc_826331F0;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,304(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 304);
	// bl 0x82720e28
	ctx.lr = 0x82633030;
	sub_82720E28(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r25,r11,2612
	r25.s64 = r11.s64 + 2612;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x82203008
	ctx.lr = 0x82633044;
	sub_82203008(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-11044
	ctx.r4.s64 = r11.s64 + -11044;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8263305C;
	sub_825EE0E0(ctx, base);
	// lwz r10,204(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 204);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// addi r27,r11,-13268
	r27.s64 = r11.s64 + -13268;
	// bne cr6,0x82633140
	if (!cr6.eq) goto loc_82633140;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,332(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 332);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82633084;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,-13276
	ctx.r4.s64 = ctx.r9.s64 + -13276;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x827227b8
	ctx.lr = 0x82633098;
	sub_827227B8(ctx, base);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,-11112
	ctx.r4.s64 = ctx.r7.s64 + -11112;
	// lwz r5,24288(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24288);
	// bl 0x827227b8
	ctx.lr = 0x826330B0;
	sub_827227B8(ctx, base);
	// li r26,0
	r26.s64 = 0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r28,r11,-10308
	r28.s64 = r11.s64 + -10308;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82722678
	ctx.lr = 0x826330D0;
	sub_82722678(ctx, base);
	// li r6,2
	ctx.r6.s64 = 2;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x826330E8;
	sub_82722678(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r4,-13284
	ctx.r4.s64 = ctx.r4.s64 + -13284;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82633104;
	sub_82722678(ctx, base);
	// lis r3,-32247
	ctx.r3.s64 = -2113339392;
	// addi r5,r30,248
	ctx.r5.s64 = r30.s64 + 248;
	// addi r4,r3,-10912
	ctx.r4.s64 = ctx.r3.s64 + -10912;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x82633118;
	sub_82722678(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,-10292
	ctx.r4.s64 = r11.s64 + -10292;
	// bl 0x82203008
	ctx.lr = 0x82633128;
	sub_82203008(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82633140
	if (cr6.eq) goto loc_82633140;
	// stw r26,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r26.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// bl 0x82722678
	ctx.lr = 0x82633140;
	sub_82722678(ctx, base);
loc_82633140:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82630980
	ctx.lr = 0x82633148;
	sub_82630980(ctx, base);
	// lbz r11,65(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 65);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// beq cr6,0x82633174
	if (cr6.eq) goto loc_82633174;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82203008
	ctx.lr = 0x82633160;
	sub_82203008(ctx, base);
	// lbz r11,65(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 65);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// bl 0x82722678
	ctx.lr = 0x82633174;
	sub_82722678(ctx, base);
loc_82633174:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-12592
	ctx.r4.s64 = r11.s64 + -12592;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82633188;
	sub_825EE0E0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82635840
	ctx.lr = 0x82633194;
	sub_82635840(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// addi r4,r9,-10868
	ctx.r4.s64 = ctx.r9.s64 + -10868;
	// lwz r3,-10236(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x826331A8;
	sub_821F9FB8(ctx, base);
	// lwz r8,56(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// cmplw cr6,r29,r8
	cr6.compare<uint32_t>(r29.u32, ctx.r8.u32, xer);
	// bne cr6,0x82633200
	if (!cr6.eq) goto loc_82633200;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826331C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// addi r4,r8,-19772
	ctx.r4.s64 = ctx.r8.s64 + -19772;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// xori r5,r6,1
	ctx.r5.u64 = ctx.r6.u64 ^ 1;
	// bl 0x825ee0e0
	ctx.lr = 0x826331E8;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_826331F0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82633200
	if (cr6.eq) goto loc_82633200;
	// lwz r3,304(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 304);
	// bl 0x82720560
	ctx.lr = 0x82633200;
	sub_82720560(ctx, base);
loc_82633200:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82633208"))) PPC_WEAK_FUNC(sub_82633208);
PPC_FUNC_IMPL(__imp__sub_82633208) {
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
	ctx.lr = 0x82633210;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82633228;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826332ec
	if (cr6.eq) goto loc_826332EC;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82633244;
	sub_821F9FB8(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,-12248
	ctx.r4.s64 = ctx.r10.s64 + -12248;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x821f9fb8
	ctx.lr = 0x8263325C;
	sub_821F9FB8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r28,56(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + 56);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,468(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 468);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82633278;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r28
	cr6.compare<uint32_t>(ctx.r3.u32, r28.u32, xer);
	// beq cr6,0x82633298
	if (cr6.eq) goto loc_82633298;
	// lbz r11,68(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82633298
	if (cr6.eq) goto loc_82633298;
loc_8263328C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82633298:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,56(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826332B0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// beq cr6,0x826332cc
	if (cr6.eq) goto loc_826332CC;
	// lwz r3,56(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 56);
	// bl 0x827204d0
	ctx.lr = 0x826332C0;
	sub_827204D0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8263328c
	if (!cr6.eq) goto loc_8263328C;
loc_826332CC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826332E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// bl 0x827204d0
	ctx.lr = 0x826332E4;
	sub_827204D0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826332EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826332F8"))) PPC_WEAK_FUNC(sub_826332F8);
PPC_FUNC_IMPL(__imp__sub_826332F8) {
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
	// bl 0x82632f78
	ctx.lr = 0x82633314;
	sub_82632F78(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,680(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82633328;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82633360
	if (cr6.eq) goto loc_82633360;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r30,208(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 208);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-12592
	r31.s64 = ctx.r10.s64 + -12592;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82633354;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x82633360;
	sub_825EE0E0(ctx, base);
loc_82633360:
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

__attribute__((alias("__imp__sub_82633378"))) PPC_WEAK_FUNC(sub_82633378);
PPC_FUNC_IMPL(__imp__sub_82633378) {
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
	ctx.lr = 0x82633380;
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
	ctx.lr = 0x826333A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826334c0
	if (cr6.eq) goto loc_826334C0;
	// cmpwi cr6,r30,55
	cr6.compare<int32_t>(r30.s32, 55, xer);
	// beq cr6,0x82633420
	if (cr6.eq) goto loc_82633420;
	// cmpwi cr6,r30,56
	cr6.compare<int32_t>(r30.s32, 56, xer);
	// beq cr6,0x826333d8
	if (cr6.eq) goto loc_826333D8;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826309e0
	ctx.lr = 0x826333CC;
	sub_826309E0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826333D8:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r10,1728(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 1728);
	// addi r9,r11,24340
	ctx.r9.s64 = r11.s64 + 24340;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x82633414
	if (cr6.eq) goto loc_82633414;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24592(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x826333F8;
	sub_821E6800(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r10,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r10.u32);
	// lwz r8,736(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 736);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82633414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82633414:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82633420:
	// addi r3,r31,432
	ctx.r3.s64 = r31.s64 + 432;
	// bl 0x82203240
	ctx.lr = 0x82633428;
	sub_82203240(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x826334b4
	if (cr6.lt) goto loc_826334B4;
	// lwz r11,608(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 608);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r31,688
	ctx.r9.s64 = r31.s64 + 688;
	// lwzx r11,r11,r10
	r11.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// bne cr6,0x82633460
	if (!cr6.eq) goto loc_82633460;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82633454;
	sub_821E6800(ctx, base);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r10.u32);
	// b 0x826334a0
	goto loc_826334A0;
loc_82633460:
	// addi r10,r31,1104
	ctx.r10.s64 = r31.s64 + 1104;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x82633484
	if (!cr6.eq) goto loc_82633484;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82633478;
	sub_821E6800(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r10.u32);
	// b 0x826334a0
	goto loc_826334A0;
loc_82633484:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,768(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 768);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82633498;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,200(r31)
	PPC_STORE_U32(r31.u32 + 200, ctx.r9.u32);
loc_826334A0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826334B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826334B4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826334C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_826334CC"))) PPC_WEAK_FUNC(sub_826334CC);
PPC_FUNC_IMPL(__imp__sub_826334CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_826334D0"))) PPC_WEAK_FUNC(sub_826334D0);
PPC_FUNC_IMPL(__imp__sub_826334D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x826334D8;
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
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826334F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82633510
	if (!cr6.eq) goto loc_82633510;
loc_82633504:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82633510:
	// addi r11,r29,-47
	r11.s64 = r29.s64 + -47;
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x82633758
	if (cr6.gt) goto loc_82633758;
	// lis r12,-32157
	r12.s64 = -2107441152;
	// addi r12,r12,13620
	r12.s64 = r12.s64 + 13620;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_826335FC;
	case 1:
		goto loc_82633658;
	case 2:
		goto loc_826335FC;
	case 3:
		goto loc_82633658;
	case 4:
		goto loc_826336CC;
	case 5:
		goto loc_826336CC;
	case 6:
		goto loc_826336CC;
	case 7:
		goto loc_826336CC;
	case 8:
		goto loc_82633558;
	default:
		__builtin_unreachable();
	}
	// lwz r19,13820(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13820);
	// lwz r19,13912(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13912);
	// lwz r19,13820(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13820);
	// lwz r19,13912(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13912);
	// lwz r19,14028(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14028);
	// lwz r19,14028(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14028);
	// lwz r19,14028(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14028);
	// lwz r19,14028(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 14028);
	// lwz r19,13656(r3)
	r19.u64 = PPC_LOAD_U32(ctx.r3.u32 + 13656);
loc_82633558:
	// lwz r11,196(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 196);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82633504
	if (!cr6.eq) goto loc_82633504;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8263356C;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x826335f0
	if (!cr6.gt) goto loc_826335F0;
	// lwz r11,192(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 192);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826335ac
	if (cr6.eq) goto loc_826335AC;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r4,184(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263359C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r9,r3,-1
	ctx.r9.s64 = ctx.r3.s64 + -1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// b 0x826335cc
	goto loc_826335CC;
loc_826335AC:
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,72(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 72);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826335CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826335CC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826335f0
	if (cr6.eq) goto loc_826335F0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x826335E4;
	sub_821E6800(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,236
	ctx.r3.s64 = r31.s64 + 236;
	// bl 0x821c3048
	ctx.lr = 0x826335F0;
	sub_821C3048(ctx, base);
loc_826335F0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826335FC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x82633604;
	sub_82631F88(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// ble cr6,0x8263361c
	if (!cr6.gt) goto loc_8263361C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24596(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24596);
	// bl 0x821e6800
	ctx.lr = 0x8263361C;
	sub_821E6800(ctx, base);
loc_8263361C:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x8263364c
	if (!cr6.gt) goto loc_8263364C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203240
	ctx.lr = 0x8263362C;
	sub_82203240(ctx, base);
	// addic. r4,r3,-1
	xer.ca = ctx.r3.u32 > 0;
	ctx.r4.s64 = ctx.r3.s64 + -1;
	cr0.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bge 0x82633638
	if (!cr0.lt) goto loc_82633638;
	// add r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 + r30.u64;
loc_82633638:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263364C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263364C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82633658:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x82633660;
	sub_82631F88(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// ble cr6,0x82633678
	if (!cr6.gt) goto loc_82633678;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24600(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24600);
	// bl 0x821e6800
	ctx.lr = 0x82633678;
	sub_821E6800(ctx, base);
loc_82633678:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826336c0
	if (!cr6.gt) goto loc_826336C0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203240
	ctx.lr = 0x82633688;
	sub_82203240(ctx, base);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rotlwi r11,r10,1
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// divw r8,r10,r30
	ctx.r8.s32 = ctx.r10.s32 / r30.s32;
	// addi r7,r11,-1
	ctx.r7.s64 = r11.s64 + -1;
	// mullw r6,r8,r30
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(r30.s32);
	// lwz r5,648(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 648);
	// andc r11,r30,r7
	r11.u64 = r30.u64 & ~ctx.r7.u64;
	// twllei r30,0
	// subf r4,r6,r10
	ctx.r4.s64 = ctx.r10.s64 - ctx.r6.s64;
	// twlgei r11,-1
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x826336C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826336C0:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826336CC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203240
	ctx.lr = 0x826336D4;
	sub_82203240(ctx, base);
	// lhz r11,180(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// bge cr6,0x8263374c
	if (!cr6.lt) goto loc_8263374C;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x8263374c
	if (cr6.lt) goto loc_8263374C;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// rlwinm r30,r3,2,0,29
	r30.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8263370C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8263374c
	if (cr6.eq) goto loc_8263374C;
	// lwz r11,176(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,552(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 552);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82633730;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8263374c
	if (!cr6.eq) goto loc_8263374C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8263374C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8263374C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82633758:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203240
	ctx.lr = 0x82633760;
	sub_82203240(ctx, base);
	// lhz r10,180(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 180);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bge cr6,0x826337a0
	if (!cr6.lt) goto loc_826337A0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x826337a0
	if (cr6.lt) goto loc_826337A0;
	// lwz r10,176(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 176);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826337A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826337A0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_826337A8"))) PPC_WEAK_FUNC(sub_826337A8);
PPC_FUNC_IMPL(__imp__sub_826337A8) {
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
	// bl 0x82637538
	ctx.lr = 0x826337C0;
	sub_82637538(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r9,r11,-10852
	ctx.r9.s64 = r11.s64 + -10852;
	// li r11,0
	r11.s64 = 0;
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// sth r11,72(r31)
	PPC_STORE_U16(r31.u32 + 72, r11.u16);
	// li r7,1
	ctx.r7.s64 = 1;
	// sth r11,74(r31)
	PPC_STORE_U16(r31.u32 + 74, r11.u16);
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stb r11,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r11.u8);
	// stb r11,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r11.u8);
	// stb r7,102(r31)
	PPC_STORE_U8(r31.u32 + 102, ctx.r7.u8);
	// lwz r11,24288(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24288);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x8262fd60
	ctx.lr = 0x82633820;
	sub_8262FD60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8221dad8
	ctx.lr = 0x8263382C;
	sub_8221DAD8(ctx, base);
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

__attribute__((alias("__imp__sub_82633844"))) PPC_WEAK_FUNC(sub_82633844);
PPC_FUNC_IMPL(__imp__sub_82633844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82633848"))) PPC_WEAK_FUNC(sub_82633848);
PPC_FUNC_IMPL(__imp__sub_82633848) {
	PPC_FUNC_PROLOGUE();
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82637538
	ctx.lr = 0x82633868;
	sub_82637538(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,-32247
	r11.s64 = -2113339392;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-10852
	ctx.r8.s64 = r11.s64 + -10852;
	// li r11,0
	r11.s64 = 0;
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
	// addi r10,r31,112
	ctx.r10.s64 = r31.s64 + 112;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// li r7,16
	ctx.r7.s64 = 16;
	// sth r11,72(r31)
	PPC_STORE_U16(r31.u32 + 72, r11.u16);
	// lfs f0,7444(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	f0.f64 = double(temp.f32);
	// sth r11,74(r31)
	PPC_STORE_U16(r31.u32 + 74, r11.u16);
	// li r6,1
	ctx.r6.s64 = 1;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stw r11,68(r31)
	PPC_STORE_U32(r31.u32 + 68, r11.u32);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// li r5,32
	ctx.r5.s64 = 32;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stw r11,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r11.u32);
	// li r9,48
	ctx.r9.s64 = 48;
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// stw r11,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r11.u32);
	// stb r11,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r11.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r11,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r11.u8);
	// stb r6,102(r31)
	PPC_STORE_U8(r31.u32 + 102, ctx.r6.u8);
	// stvx128 v61,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r10,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r10,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r10,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8262fd60
	ctx.lr = 0x826338F0;
	sub_8262FD60(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8221dad8
	ctx.lr = 0x826338FC;
	sub_8221DAD8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263b860
	ctx.lr = 0x82633908;
	sub_8263B860(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824e06e0
	ctx.lr = 0x82633914;
	sub_824E06E0(ctx, base);
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

__attribute__((alias("__imp__sub_82633930"))) PPC_WEAK_FUNC(sub_82633930);
PPC_FUNC_IMPL(__imp__sub_82633930) {
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82633938;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82637538
	ctx.lr = 0x82633948;
	sub_82637538(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-10852
	ctx.r10.s64 = r11.s64 + -10852;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// sth r30,72(r31)
	PPC_STORE_U16(r31.u32 + 72, r30.u16);
	// sth r29,74(r31)
	PPC_STORE_U16(r31.u32 + 74, r29.u16);
	// beq cr6,0x82633974
	if (cr6.eq) goto loc_82633974;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82633970;
	sub_82130528(ctx, base);
	// b 0x82633978
	goto loc_82633978;
loc_82633974:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82633978:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
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
	// li r7,32
	ctx.r7.s64 = 32;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r6,48
	ctx.r6.s64 = 48;
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// lis r5,-32126
	ctx.r5.s64 = -2105409536;
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stb r30,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r30.u8);
	// stb r30,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r30.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r8,102(r31)
	PPC_STORE_U8(r31.u32 + 102, ctx.r8.u8);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,24288(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 24288);
	// stw r11,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r11.u32);
	// bl 0x8262fd60
	ctx.lr = 0x826339F4;
	sub_8262FD60(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221dad8
	ctx.lr = 0x82633A00;
	sub_8221DAD8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82633A0C"))) PPC_WEAK_FUNC(sub_82633A0C);
PPC_FUNC_IMPL(__imp__sub_82633A0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82633A10"))) PPC_WEAK_FUNC(sub_82633A10);
PPC_FUNC_IMPL(__imp__sub_82633A10) {
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
	// bl 0x823d91f8
	ctx.lr = 0x82633A18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x82637538
	ctx.lr = 0x82633A2C;
	sub_82637538(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r30,0
	r30.s64 = 0;
	// addi r10,r11,-10852
	ctx.r10.s64 = r11.s64 + -10852;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// sth r30,72(r31)
	PPC_STORE_U16(r31.u32 + 72, r30.u16);
	// sth r29,74(r31)
	PPC_STORE_U16(r31.u32 + 74, r29.u16);
	// beq cr6,0x82633a58
	if (cr6.eq) goto loc_82633A58;
	// rlwinm r3,r29,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82633A54;
	sub_82130528(ctx, base);
	// b 0x82633a5c
	goto loc_82633A5C;
loc_82633A58:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82633A5C:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r11,r31,112
	r11.s64 = r31.s64 + 112;
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
	// li r9,16
	ctx.r9.s64 = 16;
	// stw r30,76(r31)
	PPC_STORE_U32(r31.u32 + 76, r30.u32);
	// li r8,1
	ctx.r8.s64 = 1;
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
	// li r7,32
	ctx.r7.s64 = 32;
	// lfs f0,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// li r6,48
	ctx.r6.s64 = 48;
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stfs f0,84(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 84, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stfs f0,88(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 88, temp.u32);
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stw r30,96(r31)
	PPC_STORE_U32(r31.u32 + 96, r30.u32);
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stb r30,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r30.u8);
	// stb r30,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r30.u8);
	// stb r8,102(r31)
	PPC_STORE_U8(r31.u32 + 102, ctx.r8.u8);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8262fd60
	ctx.lr = 0x82633ACC;
	sub_8262FD60(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221dad8
	ctx.lr = 0x82633AD8;
	sub_8221DAD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8263b860
	ctx.lr = 0x82633AE4;
	sub_8263B860(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x824e06e0
	ctx.lr = 0x82633AF0;
	sub_824E06E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82633AFC"))) PPC_WEAK_FUNC(sub_82633AFC);
PPC_FUNC_IMPL(__imp__sub_82633AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82633B00"))) PPC_WEAK_FUNC(sub_82633B00);
PPC_FUNC_IMPL(__imp__sub_82633B00) {
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
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r10,r11,-10852
	ctx.r10.s64 = r11.s64 + -10852;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r9,74(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 74);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82633b34
	if (cr6.eq) goto loc_82633B34;
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 68);
	// bl 0x82130588
	ctx.lr = 0x82633B34;
	sub_82130588(ctx, base);
loc_82633B34:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826375a0
	ctx.lr = 0x82633B3C;
	sub_826375A0(ctx, base);
	// addi r1,r1,96
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

__attribute__((alias("__imp__sub_82633B50"))) PPC_WEAK_FUNC(sub_82633B50);
PPC_FUNC_IMPL(__imp__sub_82633B50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32157
	r11.s64 = -2107441152;
	// lis r10,-32247
	ctx.r10.s64 = -2113339392;
	// addi r4,r11,10448
	ctx.r4.s64 = r11.s64 + 10448;
	// addi r3,r10,-10204
	ctx.r3.s64 = ctx.r10.s64 + -10204;
	// b 0x82554798
	sub_82554798(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82633B64"))) PPC_WEAK_FUNC(sub_82633B64);
PPC_FUNC_IMPL(__imp__sub_82633B64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82633B68"))) PPC_WEAK_FUNC(sub_82633B68);
PPC_FUNC_IMPL(__imp__sub_82633B68) {
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
	ctx.lr = 0x82633B70;
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
	// bl 0x826337a8
	ctx.lr = 0x82633B84;
	sub_826337A8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stw r30,176(r31)
	PPC_STORE_U32(r31.u32 + 176, r30.u32);
	// stw r29,180(r31)
	PPC_STORE_U32(r31.u32 + 180, r29.u32);
	// addi r3,r31,184
	ctx.r3.s64 = r31.s64 + 184;
	// addi r10,r11,-14100
	ctx.r10.s64 = r11.s64 + -14100;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821c2f70
	ctx.lr = 0x82633BA0;
	sub_821C2F70(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r9,204(r31)
	PPC_STORE_U8(r31.u32 + 204, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r8.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82633BBC"))) PPC_WEAK_FUNC(sub_82633BBC);
PPC_FUNC_IMPL(__imp__sub_82633BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82633BC0"))) PPC_WEAK_FUNC(sub_82633BC0);
PPC_FUNC_IMPL(__imp__sub_82633BC0) {
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
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82633c08
	if (cr6.eq) goto loc_82633C08;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
loc_82633BF0:
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r8,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r8.u16);
	// lhz r6,8(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x82633bf0
	if (!cr6.eq) goto loc_82633BF0;
loc_82633C08:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r30,0
	r30.s64 = 0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,324(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 324);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82633C20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82633c8c
	if (cr6.eq) goto loc_82633C8C;
loc_82633C28:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// bl 0x8268dcb0
	ctx.lr = 0x82633C34;
	sub_8268DCB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82633C44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82633c6c
	if (cr6.eq) goto loc_82633C6C;
	// lhz r11,8(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 8);
	// addi r10,r31,4
	ctx.r10.s64 = r31.s64 + 4;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,8(r31)
	PPC_STORE_U16(r31.u32 + 8, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
loc_82633C6C:
	// lwz r3,12(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,324(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 324);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82633C84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// blt cr6,0x82633c28
	if (cr6.lt) goto loc_82633C28;
loc_82633C8C:
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

__attribute__((alias("__imp__sub_82633CA4"))) PPC_WEAK_FUNC(sub_82633CA4);
PPC_FUNC_IMPL(__imp__sub_82633CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82633CA8"))) PPC_WEAK_FUNC(sub_82633CA8);
PPC_FUNC_IMPL(__imp__sub_82633CA8) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82633930
	ctx.lr = 0x82633CCC;
	sub_82633930(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,-10180
	ctx.r9.s64 = r11.s64 + -10180;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,176(r31)
	PPC_STORE_U32(r31.u32 + 176, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r3,184(r31)
	PPC_STORE_U16(r31.u32 + 184, ctx.r3.u16);
	// sth r30,186(r31)
	PPC_STORE_U16(r31.u32 + 186, r30.u16);
	// beq cr6,0x82633cfc
	if (cr6.eq) goto loc_82633CFC;
	// rlwinm r3,r30,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x82633CFC;
	sub_82130528(ctx, base);
loc_82633CFC:
	// stw r3,180(r31)
	PPC_STORE_U32(r31.u32 + 180, ctx.r3.u32);
	// addi r3,r31,188
	ctx.r3.s64 = r31.s64 + 188;
	// bl 0x821c2f70
	ctx.lr = 0x82633D08;
	sub_821C2F70(ctx, base);
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

__attribute__((alias("__imp__sub_82633D24"))) PPC_WEAK_FUNC(sub_82633D24);
PPC_FUNC_IMPL(__imp__sub_82633D24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82633D28"))) PPC_WEAK_FUNC(sub_82633D28);
PPC_FUNC_IMPL(__imp__sub_82633D28) {
	PPC_FUNC_PROLOGUE();
	// stw r4,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82633D30"))) PPC_WEAK_FUNC(sub_82633D30);
PPC_FUNC_IMPL(__imp__sub_82633D30) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,184(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 184);
	// blr 
	return;
}

