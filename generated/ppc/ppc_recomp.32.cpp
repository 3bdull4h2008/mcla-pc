#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_82252628) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82252630;
	// stwu r1,-3376(r1)
	ea = -3376 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r25,1
	r25.s64 = 1;
	// lis r11,0
	r11.s64 = 0;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// ori r29,r11,54708
	r29.u64 = r11.u64 | 54708;
	// li r31,0
	r31.s64 = 0;
	// mr r24,r25
	r24.u64 = r25.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822526d0
	if (cr6.eq) goto loc_822526D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826947a0
	ctx.lr = 0x82252664;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82252668;
	sub_823DD7F0(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r24,-1
	cr6.compare<int32_t>(r24.s32, -1, xer);
	// bne cr6,0x822526d0
	if (!cr6.eq) goto loc_822526D0;
	// lbz r11,13(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// lwzx r24,r30,r29
	r24.u64 = PPC_LOAD_U32(r30.u32 + r29.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82252698
	if (cr6.eq) goto loc_82252698;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82261058
	ctx.lr = 0x8225268C;
	sub_82261058(ctx, base);
	// mr r11,r25
	r11.u64 = r25.u64;
	// stb r31,13(r30)
	PPC_STORE_U8(r30.u32 + 13, r31.u8);
	// stb r11,-6144(r23)
	PPC_STORE_U8(r23.u32 + -6144, r11.u8);
loc_82252698:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,108
	ctx.r4.s64 = 108;
	// lwz r11,-10028(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x822526B0;
	sub_82641CB0(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f3,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x826533e8
	ctx.lr = 0x822526D0;
	sub_826533E8(ctx, base);
loc_822526D0:
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// stwx r24,r30,r29
	PPC_STORE_U32(r30.u32 + r29.u32, r24.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x822528b4
	if (cr6.lt) goto loc_822528B4;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// bl 0x82250310
	ctx.lr = 0x822526F8;
	sub_82250310(ctx, base);
	// stw r31,3276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3276, r31.u32);
	// stw r31,3280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3280, r31.u32);
	// stw r31,3284(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3284, r31.u32);
	// bl 0x82256c88
	ctx.lr = 0x82252708;
	sub_82256C88(ctx, base);
	// addis r29,r30,1
	r29.s64 = r30.s64 + 65536;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r29,r29,-11232
	r29.s64 = r29.s64 + -11232;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// bl 0x82250498
	ctx.lr = 0x82252724;
	sub_82250498(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82267de0
	ctx.lr = 0x8225272C;
	sub_82267DE0(ctx, base);
	// lwz r3,11584(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 11584);
	// bl 0x82267860
	ctx.lr = 0x82252734;
	sub_82267860(ctx, base);
	// bl 0x822635a8
	ctx.lr = 0x82252738;
	sub_822635A8(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82256180
	ctx.lr = 0x82252744;
	sub_82256180(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82256048
	ctx.lr = 0x8225274C;
	sub_82256048(ctx, base);
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r27,r11,-1
	r27.s64 = r11.s64 + -1;
	// bl 0x823eaef8
	ctx.lr = 0x8225275C;
	sub_823EAEF8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// bl 0x82267860
	ctx.lr = 0x82252764;
	sub_82267860(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822677a0
	ctx.lr = 0x82252770;
	sub_822677A0(ctx, base);
	// mr r29,r31
	r29.u64 = r31.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x822527b0
	if (!cr6.gt) goto loc_822527B0;
	// addi r28,r30,712
	r28.s64 = r30.s64 + 712;
loc_82252780:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x82267480
	ctx.lr = 0x8225278C;
	sub_82267480(ctx, base);
	// addi r4,r28,-104
	ctx.r4.s64 = r28.s64 + -104;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// bl 0x82264e80
	ctx.lr = 0x82252798;
	sub_82264E80(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 0);
	f0.f64 = double(temp.f32);
	// addi r28,r28,368
	r28.s64 = r28.s64 + 368;
	// stfs f0,168(r22)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r22.u32 + 168, temp.u32);
	// cmpw cr6,r29,r27
	cr6.compare<int32_t>(r29.s32, r27.s32, xer);
	// blt cr6,0x82252780
	if (cr6.lt) goto loc_82252780;
loc_822527B0:
	// stw r25,3176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3176, r25.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822527C4;
	sub_822A3998(ctx, base);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
	// li r3,28
	ctx.r3.s64 = 28;
	// stw r25,3184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3184, r25.u32);
	// stw r25,3188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3188, r25.u32);
	// stw r25,3192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3192, r25.u32);
	// stw r24,3212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3212, r24.u32);
	// stw r25,3236(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3236, r25.u32);
	// bl 0x82130528
	ctx.lr = 0x822527E8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82252844
	if (cr6.eq) goto loc_82252844;
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// li r9,255
	ctx.r9.s64 = 255;
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// ori r8,r10,224
	ctx.r8.u64 = ctx.r10.u64 | 224;
	// stb r9,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r9.u8);
	// stb r8,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r8.u8);
	// lbz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r7,6(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// ori r4,r7,192
	ctx.r4.u64 = ctx.r7.u64 | 192;
	// clrlwi r5,r6,25
	ctx.r5.u64 = ctx.r6.u32 & 0x7F;
	// stb r31,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r31.u8);
	// stb r4,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r4.u8);
	// stb r5,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r5.u8);
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r31.u32);
	// stw r31,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r31.u32);
	// stw r31,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r31.u32);
	// stb r31,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r31.u8);
	// stb r31,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r31.u8);
	// stw r31,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r31.u32);
	// stw r3,3256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3256, ctx.r3.u32);
	// b 0x82252848
	goto loc_82252848;
loc_82252844:
	// stw r31,3256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3256, r31.u32);
loc_82252848:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-15824
	ctx.r9.s64 = r11.s64 + -15824;
	// addi r3,r10,-15856
	ctx.r3.s64 = ctx.r10.s64 + -15856;
	// stw r9,3276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3276, ctx.r9.u32);
	// li r8,3800
	ctx.r8.s64 = 3800;
	// li r7,3208
	ctx.r7.s64 = 3208;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x82252874;
	sub_82727908(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r7,r8,54300
	ctx.r7.u64 = ctx.r8.u64 | 54300;
	// stwx r3,r30,r7
	PPC_STORE_U32(r30.u32 + ctx.r7.u32, ctx.r3.u32);
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8225288C;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b1418
	ctx.lr = 0x82252894;
	sub_822B1418(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// mr r11,r31
	r11.u64 = r31.u64;
	// stb r25,13(r30)
	PPC_STORE_U8(r30.u32 + 13, r25.u8);
	// stb r11,-6144(r23)
	PPC_STORE_U8(r23.u32 + -6144, r11.u8);
	// stb r31,158(r30)
	PPC_STORE_U8(r30.u32 + 158, r31.u8);
	// lwz r11,-10236(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10236);
	// lwz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r31,248(r5)
	PPC_STORE_U32(ctx.r5.u32 + 248, r31.u32);
loc_822528B4:
	// addi r1,r1,3376
	ctx.r1.s64 = ctx.r1.s64 + 3376;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_82252628) {
	__imp__sub_82252628(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822528BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822528BC) {
	__imp__sub_822528BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822528C0) {
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
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,176
	ctx.r3.s64 = r11.s64 + 176;
	// bl 0x82264c90
	ctx.lr = 0x822528F0;
	sub_82264C90(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,160(r31)
	PPC_STORE_U32(r31.u32 + 160, ctx.r10.u32);
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// bl 0x82250690
	ctx.lr = 0x82252908;
	sub_82250690(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x822523f0
	ctx.lr = 0x82252914;
	sub_822523F0(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r30,64
	ctx.r5.s64 = r30.s64 + 64;
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// bl 0x822681e0
	ctx.lr = 0x82252928;
	sub_822681E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268118
	ctx.lr = 0x82252930;
	sub_82268118(ctx, base);
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

PPC_WEAK_FUNC(sub_822528C0) {
	__imp__sub_822528C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252948) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x82252950;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r10,r11,54609
	ctx.r10.u64 = r11.u64 | 54609;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82252aac
	if (cr6.eq) goto loc_82252AAC;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82252aac
	if (!cr6.gt) goto loc_82252AAC;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822529a4
	if (cr6.eq) goto loc_822529A4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82250928
	ctx.lr = 0x82252990;
	sub_82250928(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822529a4
	if (cr6.eq) goto loc_822529A4;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82252aac
	if (!cr6.eq) goto loc_82252AAC;
loc_822529A4:
	// lwz r9,160(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lbz r11,14(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14);
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822529e0
	if (cr6.eq) goto loc_822529E0;
	// lwz r11,-4944(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -4944);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822529d8
	if (cr6.eq) goto loc_822529D8;
	// rotlwi r11,r10,0
	r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// b 0x822529dc
	goto loc_822529DC;
loc_822529D8:
	// li r11,0
	r11.s64 = 0;
loc_822529DC:
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
loc_822529E0:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// add. r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x822529f4
	if (!cr0.lt) goto loc_822529F4;
	// li r11,0
	r11.s64 = 0;
	// b 0x82252a00
	goto loc_82252A00;
loc_822529F4:
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x82252a00
	if (!cr6.gt) goto loc_82252A00;
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82252A00:
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// stb r10,158(r31)
	PPC_STORE_U8(r31.u32 + 158, ctx.r10.u8);
	// mulli r9,r9,368
	ctx.r9.s64 = ctx.r9.s64 * 368;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// add r11,r9,r31
	r11.u64 = ctx.r9.u64 + r31.u64;
	// addi r4,r10,240
	ctx.r4.s64 = ctx.r10.s64 + 240;
	// addi r3,r11,176
	ctx.r3.s64 = r11.s64 + 176;
	// bl 0x82264e80
	ctx.lr = 0x82252A28;
	sub_82264E80(ctx, base);
	// lwz r4,160(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r3,-4944(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -4944);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r5,r11,176
	ctx.r5.s64 = r11.s64 + 176;
	// bl 0x822627c0
	ctx.lr = 0x82252A40;
	sub_822627C0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250898
	ctx.lr = 0x82252A4C;
	sub_82250898(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lfs f3,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f3.f64 = double(temp.f32);
	// fmr f2,f3
	ctx.f2.f64 = ctx.f3.f64;
	// fmr f1,f3
	ctx.f1.f64 = ctx.f3.f64;
	// bl 0x82250710
	ctx.lr = 0x82252A60;
	sub_82250710(ctx, base);
	// lwz r6,168(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mulli r11,r6,368
	r11.s64 = ctx.r6.s64 * 368;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,344(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 344);
	f0.f64 = double(temp.f32);
	// stfs f0,-13516(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + -13516, temp.u32);
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lfs f0,356(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 356);
	f0.f64 = double(temp.f32);
	// stfs f0,-13512(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -13512, temp.u32);
	// bl 0x82268118
	ctx.lr = 0x82252A98;
	sub_82268118(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250690
	ctx.lr = 0x82252AA0;
	sub_82250690(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x822523f0
	ctx.lr = 0x82252AAC;
	sub_822523F0(ctx, base);
loc_82252AAC:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82252948) {
	__imp__sub_82252948(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82252AB4) {
	__imp__sub_82252AB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252AB8) {
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
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82252b74
	if (!cr6.gt) goto loc_82252B74;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82252b04
	if (!cr6.eq) goto loc_82252B04;
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82252b04
	if (cr6.eq) goto loc_82252B04;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82251cb0
	ctx.lr = 0x82252AF8;
	sub_82251CB0(ctx, base);
	// extsb r11,r3
	r11.s64 = ctx.r3.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82252b74
	if (!cr6.eq) goto loc_82252B74;
loc_82252B04:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250928
	ctx.lr = 0x82252B10;
	sub_82250928(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82252b30
	if (cr6.eq) goto loc_82252B30;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82252b30
	if (cr6.eq) goto loc_82252B30;
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82252b74
	if (!cr6.eq) goto loc_82252B74;
loc_82252B30:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250c08
	ctx.lr = 0x82252B38;
	sub_82250C08(ctx, base);
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,158(r31)
	PPC_STORE_U8(r31.u32 + 158, ctx.r9.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82252b6c
	if (cr6.eq) goto loc_82252B6C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250818
	ctx.lr = 0x82252B58;
	sub_82250818(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82252948
	ctx.lr = 0x82252B64;
	sub_82252948(ctx, base);
	// li r3,44
	ctx.r3.s64 = 44;
	// b 0x82252b70
	goto loc_82252B70;
loc_82252B6C:
	// li r3,20
	ctx.r3.s64 = 20;
loc_82252B70:
	// bl 0x82216138
	ctx.lr = 0x82252B74;
	sub_82216138(ctx, base);
loc_82252B74:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82252AB8) {
	__imp__sub_82252AB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252B88) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82252B90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// li r30,3
	r30.s64 = 3;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// stw r30,176(r9)
	PPC_STORE_U32(ctx.r9.u32 + 176, r30.u32);
	// lfs f0,-13512(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// lwz r6,160(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mulli r11,r6,368
	r11.s64 = ctx.r6.s64 * 368;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// stfs f0,356(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 356, temp.u32);
	// lwz r3,160(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lfs f0,-13516(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13516);
	f0.f64 = double(temp.f32);
	// mulli r11,r3,368
	r11.s64 = ctx.r3.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// stfs f0,344(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 344, temp.u32);
	// lwz r9,160(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lfs f0,-13520(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -13520);
	f0.f64 = double(temp.f32);
	// mulli r11,r9,368
	r11.s64 = ctx.r9.s64 * 368;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stfs f0,340(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + 340, temp.u32);
	// lwz r7,160(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lfs f0,-13512(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// mulli r11,r7,368
	r11.s64 = ctx.r7.s64 * 368;
	// add r6,r11,r31
	ctx.r6.u64 = r11.u64 + r31.u64;
	// stfs f0,352(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 352, temp.u32);
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mulli r11,r5,368
	r11.s64 = ctx.r5.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,176
	ctx.r3.s64 = r11.s64 + 176;
	// bl 0x82264e80
	ctx.lr = 0x82252C20;
	sub_82264E80(ctx, base);
	// lis r3,0
	ctx.r3.s64 = 0;
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r11,r3,54720
	r11.u64 = ctx.r3.u64 | 54720;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mulli r11,r10,368
	r11.s64 = ctx.r10.s64 * 368;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// stw r30,376(r9)
	PPC_STORE_U32(ctx.r9.u32 + 376, r30.u32);
	// bl 0x822523f0
	ctx.lr = 0x82252C4C;
	sub_822523F0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82252B88) {
	__imp__sub_82252B88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82252C54) {
	__imp__sub_82252C54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252C58) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82252C60;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,176
	ctx.r4.s64 = r11.s64 + 176;
	// addi r3,r11,544
	ctx.r3.s64 = r11.s64 + 544;
	// bl 0x82264c90
	ctx.lr = 0x82252C84;
	sub_82264C90(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82266208
	ctx.lr = 0x82252C8C;
	sub_82266208(ctx, base);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// li r30,2
	r30.s64 = 2;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lfs f0,-13512(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13512);
	f0.f64 = double(temp.f32);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// lfs f13,-13516(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -13516);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f12,-13520(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13520);
	ctx.f12.f64 = double(temp.f32);
	// stfs f0,260(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f13,248(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f12,244(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// bl 0x82264e80
	ctx.lr = 0x82252CC8;
	sub_82264E80(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stw r30,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,344(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// bl 0x822528c0
	ctx.lr = 0x82252CE4;
	sub_822528C0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82265240
	ctx.lr = 0x82252CEC;
	sub_82265240(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82252C58) {
	__imp__sub_82252C58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82252CF4) {
	__imp__sub_82252CF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252CF8) {
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
	ctx.lr = 0x82252D00;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r28,r11,-6128
	r28.s64 = r11.s64 + -6128;
	// lis r11,3
	r11.s64 = 196608;
	// li r29,0
	r29.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// mr r31,r28
	r31.u64 = r28.u64;
	// ori r26,r11,57220
	r26.u64 = r11.u64 | 57220;
loc_82252D24:
	// bl 0x82387b90
	ctx.lr = 0x82252D28;
	sub_82387B90(ctx, base);
	// add r11,r3,r30
	r11.u64 = ctx.r3.u64 + r30.u64;
	// lbzx r10,r11,r26
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + r26.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82252d50
	if (!cr6.eq) goto loc_82252D50;
	// cmpwi cr6,r29,30
	cr6.compare<int32_t>(r29.s32, 30, xer);
	// bge cr6,0x82252d50
	if (!cr6.lt) goto loc_82252D50;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82252c58
	ctx.lr = 0x82252D4C;
	sub_82252C58(ctx, base);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
loc_82252D50:
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// addi r11,r28,960
	r11.s64 = r28.s64 + 960;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x82252d24
	if (cr6.lt) goto loc_82252D24;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82252CF8) {
	__imp__sub_82252CF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252D6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82252D6C) {
	__imp__sub_82252D6C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252D70) {
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
	// bl 0x82267de0
	ctx.lr = 0x82252D8C;
	sub_82267DE0(ctx, base);
	// lwz r3,11584(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 11584);
	// bl 0x82267860
	ctx.lr = 0x82252D94;
	sub_82267860(ctx, base);
	// bl 0x822635a8
	ctx.lr = 0x82252D98;
	sub_822635A8(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r30,0
	r30.s64 = 0;
	// stw r30,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r30.u32);
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82252dd0
	if (cr6.eq) goto loc_82252DD0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82252DC0;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82252DC4;
	sub_822A8108(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252b88
	ctx.lr = 0x82252DD0;
	sub_82252B88(ctx, base);
loc_82252DD0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r30,158(r31)
	PPC_STORE_U8(r31.u32 + 158, r30.u8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r30,157(r31)
	PPC_STORE_U8(r31.u32 + 157, r30.u8);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r10,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r10.u32);
	// stb r9,159(r31)
	PPC_STORE_U8(r31.u32 + 159, ctx.r9.u8);
	// lfs f0,29500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 29500);
	f0.f64 = double(temp.f32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
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

PPC_WEAK_FUNC(sub_82252D70) {
	__imp__sub_82252D70(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82252E0C) {
	__imp__sub_82252E0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82252E10) {
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
	// bl 0x823d91e8
	ctx.lr = 0x82252E18;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,17268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82252E34;
	sub_822A3998(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,880(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 880);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r8,56(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// cmplw cr6,r9,r8
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, xer);
	// bne cr6,0x82252e5c
	if (!cr6.eq) goto loc_82252E5C;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253290
	if (cr6.eq) goto loc_82253290;
loc_82252E5C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822a5948
	ctx.lr = 0x82252E64;
	sub_822A5948(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r4,72(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// lwz r3,16(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// bl 0x8271eb28
	ctx.lr = 0x82252E74;
	sub_8271EB28(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82253290
	if (!cr6.eq) goto loc_82253290;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,54320
	ctx.r10.u64 = r11.u64 | 54320;
	// lbzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82253290
	if (!cr6.eq) goto loc_82253290;
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82252edc
	if (cr6.eq) goto loc_82252EDC;
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82252edc
	if (cr6.eq) goto loc_82252EDC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250928
	ctx.lr = 0x82252EB4;
	sub_82250928(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82253290
	if (!cr6.eq) goto loc_82253290;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82252edc
	if (!cr6.eq) goto loc_82252EDC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82251d70
	ctx.lr = 0x82252ED4;
	sub_82251D70(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// bne cr6,0x82253290
	if (!cr6.eq) goto loc_82253290;
loc_82252EDC:
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,156(r31)
	PPC_STORE_U8(r31.u32 + 156, ctx.r9.u8);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8225308c
	if (!cr6.eq) goto loc_8225308C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15720
	ctx.r3.s64 = r11.s64 + -15720;
	// bl 0x821fa230
	ctx.lr = 0x82252F00;
	sub_821FA230(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// stb r28,384(r3)
	PPC_STORE_U8(ctx.r3.u32 + 384, r28.u8);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82252F1C;
	sub_82220980(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,17292(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17292);
	// li r3,6
	ctx.r3.s64 = 6;
	// lwz r4,92(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// bl 0x82267e98
	ctx.lr = 0x82252F30;
	sub_82267E98(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r9,-15732
	ctx.r3.s64 = ctx.r9.s64 + -15732;
	// bl 0x821fa230
	ctx.lr = 0x82252F40;
	sub_821FA230(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r8,-15744
	ctx.r4.s64 = ctx.r8.s64 + -15744;
	// bl 0x8268da78
	ctx.lr = 0x82252F50;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82252f64
	if (cr6.eq) goto loc_82252F64;
	// li r11,1
	r11.s64 = 1;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_82252F64:
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x82216138
	ctx.lr = 0x82252F6C;
	sub_82216138(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,54609
	ctx.r10.u64 = r11.u64 | 54609;
	// stbx r28,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r28.u8);
	// lwz r3,880(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 880);
	// bl 0x822b1418
	ctx.lr = 0x82252F80;
	sub_822B1418(ctx, base);
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r9,54296
	ctx.r8.u64 = ctx.r9.u64 | 54296;
	// li r7,5
	ctx.r7.s64 = 5;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stbx r7,r31,r8
	PPC_STORE_U8(r31.u32 + ctx.r8.u32, ctx.r7.u8);
	// bl 0x822a5578
	ctx.lr = 0x82252F98;
	sub_822A5578(ctx, base);
	// bl 0x822a2370
	ctx.lr = 0x82252F9C;
	sub_822A2370(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lis r7,-32122
	ctx.r7.s64 = -2105147392;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r3,r7,2272
	ctx.r3.s64 = ctx.r7.s64 + 2272;
	// ori r11,r9,54720
	r11.u64 = ctx.r9.u64 | 54720;
	// lfs f2,30712(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r31,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// li r26,32
	r26.s64 = 32;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r25,r1,128
	r25.s64 = ctx.r1.s64 + 128;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f1,7444(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r27,880(r27)
	r27.u64 = PPC_LOAD_U32(r27.u32 + 880);
	// lwz r11,128(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 128);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r11,r26
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r25
	simde_mm_store_si128((simde__m128i*)(base + ((r25.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a9930
	ctx.lr = 0x82253018;
	sub_822A9930(ctx, base);
	// lwz r9,160(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r10,3
	ctx.r10.s64 = 3;
	// mulli r11,r9,368
	r11.s64 = ctx.r9.s64 * 368;
	// add r8,r11,r31
	ctx.r8.u64 = r11.u64 + r31.u64;
	// stw r10,376(r8)
	PPC_STORE_U32(ctx.r8.u32 + 376, ctx.r10.u32);
	// lbz r7,13(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 13);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// bne cr6,0x82253054
	if (!cr6.eq) goto loc_82253054;
	// lwz r4,160(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// lwz r3,-4944(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4944);
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r5,r11,176
	ctx.r5.s64 = r11.s64 + 176;
	// bl 0x822627c0
	ctx.lr = 0x82253054;
	sub_822627C0(ctx, base);
loc_82253054:
	// stb r28,158(r31)
	PPC_STORE_U8(r31.u32 + 158, r28.u8);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r28,248(r11)
	PPC_STORE_U32(r11.u32 + 248, r28.u32);
	// lwz r3,17268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 17268);
	// bl 0x822a3d80
	ctx.lr = 0x82253074;
	sub_822A3D80(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82207190
	ctx.lr = 0x82253084;
	sub_82207190(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9238
	return;
loc_8225308C:
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82216138
	ctx.lr = 0x82253094;
	sub_82216138(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15720
	ctx.r3.s64 = r11.s64 + -15720;
	// bl 0x821fa230
	ctx.lr = 0x822530A0;
	sub_821FA230(ctx, base);
	// li r25,1
	r25.s64 = 1;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// stb r25,384(r3)
	PPC_STORE_U8(ctx.r3.u32 + 384, r25.u8);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x822530BC;
	sub_82220980(ctx, base);
	// lwz r3,880(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 880);
	// bl 0x822afca8
	ctx.lr = 0x822530C4;
	sub_822AFCA8(ctx, base);
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r9,r9,-11120
	ctx.r9.s64 = ctx.r9.s64 + -11120;
	// li r28,16
	r28.s64 = 16;
	// li r29,32
	r29.s64 = 32;
	// li r30,48
	r30.s64 = 48;
	// lvx128 v59,r0,r10
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r8,r31,1
	ctx.r8.s64 = r31.s64 + 65536;
	// stvx128 v59,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lvx128 v58,r10,r28
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,-11056
	ctx.r8.s64 = ctx.r8.s64 + -11056;
	// stvx128 v58,r9,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v57,r10,r29
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r9,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r10,r30
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r9,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v55,r0,r9
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v54,r9,r28
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r8,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r9,r29
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r8,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v52,r9,r30
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r8,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x822a8108
	ctx.lr = 0x8225312C;
	sub_822A8108(ctx, base);
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r6,r6,-11200
	ctx.r6.s64 = ctx.r6.s64 + -11200;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lvx128 v51,r0,r7
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stvx128 v51,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v50,r7,r28
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r6,r28
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v49,r7,r29
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r6,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v48,r7,r30
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32 + r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r6,r30
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f3,-15748(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -15748);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-1540(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -1540);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82250710
	ctx.lr = 0x82253178;
	sub_82250710(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r6,r10,54408
	ctx.r6.u64 = ctx.r10.u64 | 54408;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,-12084(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12084);
	f0.f64 = double(temp.f32);
	// ori r3,r8,54400
	ctx.r3.u64 = ctx.r8.u64 | 54400;
	// ori r11,r7,54404
	r11.u64 = ctx.r7.u64 | 54404;
	// stfsx f0,r31,r6
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + ctx.r6.u32, temp.u32);
	// lfs f0,-15752(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -15752);
	f0.f64 = double(temp.f32);
	// lfs f13,27640(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 27640);
	ctx.f13.f64 = double(temp.f32);
	// stfsx f0,r31,r3
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, temp.u32);
	// stfsx f13,r31,r11
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + r11.u32, temp.u32);
	// lwz r3,880(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 880);
	// bl 0x822b1468
	ctx.lr = 0x822531BC;
	sub_822B1468(ctx, base);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822a5578
	ctx.lr = 0x822531C4;
	sub_822A5578(ctx, base);
	// bl 0x822a0f10
	ctx.lr = 0x822531C8;
	sub_822A0F10(ctx, base);
	// lwz r3,17268(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + 17268);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3d80
	ctx.lr = 0x822531D8;
	sub_822A3D80(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lwz r8,160(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r28,0
	r28.s64 = 0;
	// ori r9,r10,54609
	ctx.r9.u64 = ctx.r10.u64 | 54609;
	// mr r30,r28
	r30.u64 = r28.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// stbx r25,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, r25.u8);
	// ble cr6,0x8225322c
	if (!cr6.gt) goto loc_8225322C;
	// addi r29,r31,176
	r29.s64 = r31.s64 + 176;
	// lis r25,-32121
	r25.s64 = -2105081856;
loc_82253200:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82264c40
	ctx.lr = 0x82253208;
	sub_82264C40(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-4944(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -4944);
	// bl 0x822627c0
	ctx.lr = 0x82253218;
	sub_822627C0(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,368
	r29.s64 = r29.s64 + 368;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82253200
	if (cr6.lt) goto loc_82253200;
loc_8225322C:
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r30,r11,2272
	r30.s64 = r11.s64 + 2272;
	// bl 0x822a8108
	ctx.lr = 0x8225323C;
	sub_822A8108(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// lfs f1,7444(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f2,30712(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 30712);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x822a9930
	ctx.lr = 0x82253264;
	sub_822A9930(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r7,r8,54692
	ctx.r7.u64 = ctx.r8.u64 | 54692;
	// lwzx r6,r31,r7
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stb r28,252(r11)
	PPC_STORE_U8(r11.u32 + 252, r28.u8);
	// stw r6,248(r11)
	PPC_STORE_U32(r11.u32 + 248, ctx.r6.u32);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82207190
	ctx.lr = 0x82253290;
	sub_82207190(ctx, base);
loc_82253290:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82252E10) {
	__imp__sub_82252E10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253298) {
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
	// lis r11,0
	r11.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// ori r9,r11,54610
	ctx.r9.u64 = r11.u64 | 54610;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stbx r4,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, ctx.r4.u8);
	// bne cr6,0x82253338
	if (!cr6.eq) goto loc_82253338;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,54312
	ctx.r10.u64 = r11.u64 | 54312;
	// lwzx r3,r31,r10
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82253314
	if (cr6.eq) goto loc_82253314;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x822532E0;
	sub_82720E28(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// ori r9,r11,54308
	ctx.r9.u64 = r11.u64 | 54308;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,-19772
	ctx.r4.s64 = ctx.r10.s64 + -19772;
	// lwzx r3,r31,r9
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// bl 0x825ee0e0
	ctx.lr = 0x822532FC;
	sub_825EE0E0(ctx, base);
	// lbz r8,156(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82253314
	if (cr6.eq) goto loc_82253314;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252e10
	ctx.lr = 0x82253314;
	sub_82252E10(ctx, base);
loc_82253314:
	// lis r11,0
	r11.s64 = 0;
	// li r10,5
	ctx.r10.s64 = 5;
	// ori r9,r11,54296
	ctx.r9.u64 = r11.u64 | 54296;
	// stbx r10,r31,r9
	PPC_STORE_U8(r31.u32 + ctx.r9.u32, ctx.r10.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82253338:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15700
	ctx.r3.s64 = r11.s64 + -15700;
	// bl 0x821fa230
	ctx.lr = 0x82253344;
	sub_821FA230(ctx, base);
	// lwz r10,160(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// ble cr6,0x82253384
	if (!cr6.gt) goto loc_82253384;
	// bl 0x82387a18
	ctx.lr = 0x82253358;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82253384
	if (!cr6.eq) goto loc_82253384;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82253378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r8,r9,0,28,26
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// b 0x822533a0
	goto loc_822533A0;
loc_82253384:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82253398;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// ori r8,r9,16
	ctx.r8.u64 = ctx.r9.u64 | 16;
loc_822533A0:
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82253298) {
	__imp__sub_82253298(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822533B8) {
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
	// bl 0x82252468
	ctx.lr = 0x822533D8;
	sub_82252468(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// addi r3,r11,-15616
	ctx.r3.s64 = r11.s64 + -15616;
	// ble cr6,0x822533fc
	if (!cr6.gt) goto loc_822533FC;
	// bl 0x821fa230
	ctx.lr = 0x822533F0;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// b 0x82253408
	goto loc_82253408;
loc_822533FC:
	// bl 0x821fa230
	ctx.lr = 0x82253400;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
loc_82253408:
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15628
	ctx.r3.s64 = r11.s64 + -15628;
	// ble cr6,0x82253430
	if (!cr6.gt) goto loc_82253430;
	// bl 0x821fa230
	ctx.lr = 0x82253424;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// b 0x8225343c
	goto loc_8225343C;
loc_82253430:
	// bl 0x821fa230
	ctx.lr = 0x82253434;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
loc_8225343C:
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252468
	ctx.lr = 0x8225344C;
	sub_82252468(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// add r30,r3,r30
	r30.u64 = ctx.r3.u64 + r30.u64;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r3,r11,-15640
	ctx.r3.s64 = r11.s64 + -15640;
	// ble cr6,0x82253470
	if (!cr6.gt) goto loc_82253470;
	// bl 0x821fa230
	ctx.lr = 0x82253464;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// b 0x8225347c
	goto loc_8225347C;
loc_82253470:
	// bl 0x821fa230
	ctx.lr = 0x82253474;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
loc_8225347C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// addi r3,r11,-15652
	ctx.r3.s64 = r11.s64 + -15652;
	// bgt cr6,0x822534bc
	if (cr6.gt) goto loc_822534BC;
	// bl 0x821fa230
	ctx.lr = 0x82253494;
	sub_821FA230(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r9,-15668
	ctx.r3.s64 = ctx.r9.s64 + -15668;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// ori r7,r8,16
	ctx.r7.u64 = ctx.r8.u64 | 16;
	// stw r7,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// bl 0x821fa230
	ctx.lr = 0x822534B0;
	sub_821FA230(ctx, base);
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r5,r6,16
	ctx.r5.u64 = ctx.r6.u64 | 16;
	// b 0x822534e4
	goto loc_822534E4;
loc_822534BC:
	// bl 0x821fa230
	ctx.lr = 0x822534C0;
	sub_821FA230(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r3,r9,-15668
	ctx.r3.s64 = ctx.r9.s64 + -15668;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r7,r8,0,28,26
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r7,16(r10)
	PPC_STORE_U32(ctx.r10.u32 + 16, ctx.r7.u32);
	// bl 0x821fa230
	ctx.lr = 0x822534DC;
	sub_821FA230(ctx, base);
	// lwz r6,16(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r5,r6,0,28,26
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_822534E4:
	// stw r5,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r5.u32);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15688
	ctx.r3.s64 = r11.s64 + -15688;
	// bge cr6,0x8225350c
	if (!cr6.lt) goto loc_8225350C;
	// bl 0x821fa230
	ctx.lr = 0x82253500;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// b 0x82253518
	goto loc_82253518;
loc_8225350C:
	// bl 0x821fa230
	ctx.lr = 0x82253510;
	sub_821FA230(ctx, base);
	// lwz r10,16(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r9,r10,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_82253518:
	// stw r9,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_822533B8) {
	__imp__sub_822533B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82253534) {
	__imp__sub_82253534(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253538) {
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
	ctx.lr = 0x82253540;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82253558;
	sub_8238EC00(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r9,80
	ctx.r9.s64 = 80;
	// addis r26,r31,1
	r26.s64 = r31.s64 + 65536;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r26,r26,-11248
	r26.s64 = r26.s64 + -11248;
	// lwz r11,-12648(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12648);
	// subf r8,r11,r3
	ctx.r8.s64 = ctx.r3.s64 - r11.s64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// divw r7,r8,r9
	ctx.r7.s32 = ctx.r8.s32 / ctx.r9.s32;
	// clrlwi r28,r7,24
	r28.u64 = ctx.r7.u32 & 0xFF;
	// bl 0x826947a0
	ctx.lr = 0x82253584;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x82253588;
	sub_823DD7F0(ctx, base);
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r3,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r3.u32);
	// li r30,1
	r30.s64 = 1;
	// addi r29,r29,-32432
	r29.s64 = r29.s64 + -32432;
	// addi r27,r11,-15604
	r27.s64 = r11.s64 + -15604;
loc_822535A0:
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// addi r31,r29,-21120
	r31.s64 = r29.s64 + -21120;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822535b4
	if (cr6.eq) goto loc_822535B4;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_822535B4:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,30
	ctx.r4.s64 = 30;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x822535C8;
	sub_82137A08(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821fa230
	ctx.lr = 0x822535D0;
	sub_821FA230(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82253654
	if (cr6.eq) goto loc_82253654;
	// lbz r10,1043(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1043);
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82253610
	if (cr6.eq) goto loc_82253610;
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// beq cr6,0x822535f8
	if (cr6.eq) goto loc_822535F8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82253608
	if (!cr6.eq) goto loc_82253608;
loc_822535F8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253610
	if (cr6.eq) goto loc_82253610;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x82253610
	if (cr6.eq) goto loc_82253610;
loc_82253608:
	// li r11,0
	r11.s64 = 0;
	// b 0x82253614
	goto loc_82253614;
loc_82253610:
	// li r11,1
	r11.s64 = 1;
loc_82253614:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253648
	if (cr6.eq) goto loc_82253648;
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x82253630
	if (!cr6.eq) goto loc_82253630;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x82253634
	goto loc_82253634;
loc_82253630:
	// lbz r11,1042(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1042);
loc_82253634:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82253648
	if (!cr6.gt) goto loc_82253648;
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// b 0x82253650
	goto loc_82253650;
loc_82253648:
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
loc_82253650:
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
loc_82253654:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,1056
	r29.s64 = r29.s64 + 1056;
	// cmpwi cr6,r30,20
	cr6.compare<int32_t>(r30.s32, 20, xer);
	// ble cr6,0x822535a0
	if (!cr6.gt) goto loc_822535A0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82253538) {
	__imp__sub_82253538(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225366C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225366C) {
	__imp__sub_8225366C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253670) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82253678;
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f31.u64);
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82252d70
	ctx.lr = 0x82253688;
	sub_82252D70(ctx, base);
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,54288
	ctx.r10.u64 = r11.u64 | 54288;
	// lis r11,0
	r11.s64 = 0;
	// lwzx r9,r29,r10
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// ori r10,r11,54292
	ctx.r10.u64 = r11.u64 | 54292;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwzx r9,r29,r10
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// mulli r11,r9,1056
	r11.s64 = ctx.r9.s64 * 1056;
	// bne cr6,0x822536b8
	if (!cr6.eq) goto loc_822536B8;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r28,r11,11984
	r28.s64 = r11.s64 + 11984;
	// b 0x822536c4
	goto loc_822536C4;
loc_822536B8:
	// add r8,r11,r29
	ctx.r8.u64 = r11.u64 + r29.u64;
	// addis r28,r8,1
	r28.s64 = ctx.r8.s64 + 65536;
	// addi r28,r28,-32432
	r28.s64 = r28.s64 + -32432;
loc_822536C4:
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x822536D0;
	sub_8238EC00(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lbz r10,1043(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1043);
	// li r8,80
	ctx.r8.s64 = 80;
	// li r26,0
	r26.s64 = 0;
	// lwz r11,-12648(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12648);
	// subf r7,r11,r3
	ctx.r7.s64 = ctx.r3.s64 - r11.s64;
	// divw r6,r7,r8
	ctx.r6.s32 = ctx.r7.s32 / ctx.r8.s32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x82253720
	if (cr6.eq) goto loc_82253720;
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// beq cr6,0x82253708
	if (cr6.eq) goto loc_82253708;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82253718
	if (!cr6.eq) goto loc_82253718;
loc_82253708:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253720
	if (cr6.eq) goto loc_82253720;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// beq cr6,0x82253720
	if (cr6.eq) goto loc_82253720;
loc_82253718:
	// mr r11,r26
	r11.u64 = r26.u64;
	// b 0x82253724
	goto loc_82253724;
loc_82253720:
	// li r11,1
	r11.s64 = 1;
loc_82253724:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253814
	if (cr6.eq) goto loc_82253814;
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x82253740
	if (!cr6.eq) goto loc_82253740;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// b 0x82253744
	goto loc_82253744;
loc_82253740:
	// lbz r11,1042(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 1042);
loc_82253744:
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82253814
	if (!cr6.gt) goto loc_82253814;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r30,r26
	r30.u64 = r26.u64;
	// bl 0x822502d8
	ctx.lr = 0x82253758;
	sub_822502D8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82253804
	if (!cr6.gt) goto loc_82253804;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r28,65
	r31.s64 = r28.s64 + 65;
	// li r27,2
	r27.s64 = 2;
	// lfs f31,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f31.f64 = double(temp.f32);
loc_82253770:
	// lwz r11,160(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 160);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r4,r11,176
	ctx.r4.s64 = r11.s64 + 176;
	// addi r3,r11,544
	ctx.r3.s64 = r11.s64 + 544;
	// bl 0x82264c90
	ctx.lr = 0x82253788;
	sub_82264C90(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82266208
	ctx.lr = 0x82253790;
	sub_82266208(ctx, base);
	// stw r26,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r26.u32);
	// lbz r9,-1(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + -1);
	// addi r4,r31,-17
	ctx.r4.s64 = r31.s64 + -17;
	// std r9,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r9.u64);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f12,276(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// lbz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 0);
	// std r7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r7.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,264(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// bl 0x82264e80
	ctx.lr = 0x822537D0;
	sub_82264E80(ctx, base);
	// stfs f31,360(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// stw r27,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, r27.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822528c0
	ctx.lr = 0x822537E4;
	sub_822528C0(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82265240
	ctx.lr = 0x822537EC;
	sub_82265240(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// bl 0x822502d8
	ctx.lr = 0x822537FC;
	sub_822502D8(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x82253770
	if (cr6.lt) goto loc_82253770;
loc_82253804:
	// lbz r11,1040(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 1040);
	// stb r11,11968(r29)
	PPC_STORE_U8(r29.u32 + 11968, r11.u8);
	// lbz r10,1041(r28)
	ctx.r10.u64 = PPC_LOAD_U8(r28.u32 + 1041);
	// stb r10,11969(r29)
	PPC_STORE_U8(r29.u32 + 11969, ctx.r10.u8);
loc_82253814:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82253670) {
	__imp__sub_82253670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253820) {
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
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lfs f1,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x82253848;
	sub_8213E850(ctx, base);
	// addi r3,r1,82
	ctx.r3.s64 = ctx.r1.s64 + 82;
	// lfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x82253854;
	sub_8213E850(ctx, base);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// lfs f1,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8213e850
	ctx.lr = 0x82253860;
	sub_8213E850(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x82253870;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822538f0
	if (cr6.eq) goto loc_822538F0;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,82
	ctx.r4.s64 = ctx.r1.s64 + 82;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x8225388C;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822538f0
	if (cr6.eq) goto loc_822538F0;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618f90
	ctx.lr = 0x822538A8;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822538f0
	if (cr6.eq) goto loc_822538F0;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822525b0
	ctx.lr = 0x822538C4;
	sub_822525B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822538f0
	if (cr6.eq) goto loc_822538F0;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r31,17
	ctx.r4.s64 = r31.s64 + 17;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822525b0
	ctx.lr = 0x822538E0;
	sub_822525B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822538f4
	if (!cr6.eq) goto loc_822538F4;
loc_822538F0:
	// li r11,0
	r11.s64 = 0;
loc_822538F4:
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

PPC_WEAK_FUNC(sub_82253820) {
	__imp__sub_82253820(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253910) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x8225393C;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253a80
	if (cr6.eq) goto loc_82253A80;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82253958;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253a80
	if (cr6.eq) goto loc_82253A80;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f80
	ctx.lr = 0x82253974;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253a80
	if (cr6.eq) goto loc_82253A80;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822510e8
	ctx.lr = 0x82253990;
	sub_822510E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253a80
	if (cr6.eq) goto loc_82253A80;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r30,17
	ctx.r4.s64 = r30.s64 + 17;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822510e8
	ctx.lr = 0x822539AC;
	sub_822510E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253a80
	if (cr6.eq) goto loc_82253A80;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lhz r11,80(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// bne cr6,0x822539d4
	if (!cr6.eq) goto loc_822539D4;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// b 0x822539fc
	goto loc_822539FC;
loc_822539D4:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
loc_822539FC:
	// lhz r11,84(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// stfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 0, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82253a14
	if (!cr6.eq) goto loc_82253A14;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// b 0x82253a3c
	goto loc_82253A3C;
loc_82253A14:
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
loc_82253A3C:
	// lhz r11,88(r1)
	r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 88);
	// stfs f13,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 4, temp.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253a74
	if (cr6.eq) goto loc_82253A74;
	// rlwinm r10,r11,3,0,13
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFC0000;
	// clrlwi r9,r11,22
	ctx.r9.u64 = r11.u32 & 0x3FF;
	// rlwinm r11,r11,22,27,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 22) & 0x1F;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// addi r7,r11,112
	ctx.r7.s64 = r11.s64 + 112;
	// rlwinm r6,r8,13,0,18
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 13) & 0xFFFFE000;
	// rlwinm r5,r7,23,0,8
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 23) & 0xFF800000;
	// or r4,r6,r5
	ctx.r4.u64 = ctx.r6.u64 | ctx.r5.u64;
	// stw r4,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// lfs f0,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	f0.f64 = double(temp.f32);
loc_82253A74:
	// stfs f0,8(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 8, temp.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82253a84
	goto loc_82253A84;
loc_82253A80:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82253A84:
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

PPC_WEAK_FUNC(sub_82253910) {
	__imp__sub_82253910(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82253A9C) {
	__imp__sub_82253A9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253AA0) {
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
	// bl 0x823d91f4
	ctx.lr = 0x82253AA8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x824e0648
	ctx.lr = 0x82253AB4;
	sub_824E0648(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r29,r31,176
	r29.s64 = r31.s64 + 176;
	// addi r10,r11,-15572
	ctx.r10.s64 = r11.s64 + -15572;
	// li r30,30
	r30.s64 = 30;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
loc_82253AC8:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82266208
	ctx.lr = 0x82253AD0;
	sub_82266208(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,368
	r29.s64 = r29.s64 + 368;
	// bge 0x82253ac8
	if (!cr0.lt) goto loc_82253AC8;
	// addi r3,r31,11600
	ctx.r3.s64 = r31.s64 + 11600;
	// bl 0x82266208
	ctx.lr = 0x82253AE4;
	sub_82266208(ctx, base);
	// addi r28,r31,11984
	r28.s64 = r31.s64 + 11984;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82251168
	ctx.lr = 0x82253AF0;
	sub_82251168(ctx, base);
	// addis r27,r31,1
	r27.s64 = r31.s64 + 65536;
	// li r30,0
	r30.s64 = 0;
	// addi r27,r27,-10860
	r27.s64 = r27.s64 + -10860;
	// li r29,32
	r29.s64 = 32;
	// li r3,512
	ctx.r3.s64 = 512;
	// sth r30,4(r27)
	PPC_STORE_U16(r27.u32 + 4, r30.u16);
	// sth r29,6(r27)
	PPC_STORE_U16(r27.u32 + 6, r29.u16);
	// bl 0x82130528
	ctx.lr = 0x82253B10;
	sub_82130528(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = r31.s64 + 65536;
	// stw r3,0(r27)
	PPC_STORE_U32(r27.u32 + 0, ctx.r3.u32);
	// lis r27,-32256
	r27.s64 = -2113929216;
	// addi r10,r10,-10852
	ctx.r10.s64 = ctx.r10.s64 + -10852;
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, r30.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// lfs f0,29500(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r27.u32 + 29500);
	f0.f64 = double(temp.f32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// ori r9,r9,54308
	ctx.r9.u64 = ctx.r9.u64 | 54308;
	// ori r8,r8,54312
	ctx.r8.u64 = ctx.r8.u64 | 54312;
	// ori r7,r7,54608
	ctx.r7.u64 = ctx.r7.u64 | 54608;
	// ori r6,r6,54609
	ctx.r6.u64 = ctx.r6.u64 | 54609;
	// ori r5,r5,54296
	ctx.r5.u64 = ctx.r5.u64 | 54296;
	// ori r4,r4,54320
	ctx.r4.u64 = ctx.r4.u64 | 54320;
	// addi r3,r3,-5168
	ctx.r3.s64 = ctx.r3.s64 + -5168;
	// addi r27,r11,18896
	r27.s64 = r11.s64 + 18896;
	// li r11,-1
	r11.s64 = -1;
	// stw r27,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r27.u32);
	// stfs f0,164(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 164, temp.u32);
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// stwx r30,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r30.u32);
	// stbx r30,r31,r7
	PPC_STORE_U8(r31.u32 + ctx.r7.u32, r30.u8);
	// stbx r30,r31,r6
	PPC_STORE_U8(r31.u32 + ctx.r6.u32, r30.u8);
	// stbx r30,r31,r5
	PPC_STORE_U8(r31.u32 + ctx.r5.u32, r30.u8);
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// stb r30,13(r31)
	PPC_STORE_U8(r31.u32 + 13, r30.u8);
	// stb r30,158(r31)
	PPC_STORE_U8(r31.u32 + 158, r30.u8);
	// stb r30,156(r31)
	PPC_STORE_U8(r31.u32 + 156, r30.u8);
	// stb r30,157(r31)
	PPC_STORE_U8(r31.u32 + 157, r30.u8);
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
	// stb r30,159(r31)
	PPC_STORE_U8(r31.u32 + 159, r30.u8);
	// stw r30,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r30.u32);
	// stb r11,11968(r31)
	PPC_STORE_U8(r31.u32 + 11968, r11.u8);
	// stb r30,11969(r31)
	PPC_STORE_U8(r31.u32 + 11969, r30.u8);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82253bc8
	if (cr6.eq) goto loc_82253BC8;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// stb r11,-6144(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6144, r11.u8);
loc_82253BC8:
	// lis r11,0
	r11.s64 = 0;
	// stb r30,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r30.u8);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// ori r8,r11,54708
	ctx.r8.u64 = r11.u64 | 54708;
	// stb r30,20(r31)
	PPC_STORE_U8(r31.u32 + 20, r30.u8);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// stb r30,21(r31)
	PPC_STORE_U8(r31.u32 + 21, r30.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stb r30,22(r31)
	PPC_STORE_U8(r31.u32 + 22, r30.u8);
	// addi r11,r11,-10800
	r11.s64 = r11.s64 + -10800;
	// stb r30,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r30.u8);
	// lfs f10,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f10.f64 = double(temp.f32);
	// mr r9,r30
	ctx.r9.u64 = r30.u64;
	// stfs f10,32(r31)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stb r30,24(r31)
	PPC_STORE_U8(r31.u32 + 24, r30.u8);
	// stb r30,25(r31)
	PPC_STORE_U8(r31.u32 + 25, r30.u8);
	// li r10,31
	ctx.r10.s64 = 31;
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// stwx r7,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r7.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82253C1C:
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x82253c1c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82253C1C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250b38
	ctx.lr = 0x82253C30;
	sub_82250B38(ctx, base);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r11,0
	r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
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
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// ori r3,r9,54288
	ctx.r3.u64 = ctx.r9.u64 | 54288;
	// ori r4,r10,54304
	ctx.r4.u64 = ctx.r10.u64 | 54304;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// ori r5,r11,54300
	ctx.r5.u64 = r11.u64 | 54300;
	// lfs f0,-6172(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -6172);
	f0.f64 = double(temp.f32);
	// ori r9,r8,54292
	ctx.r9.u64 = ctx.r8.u64 | 54292;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// ori r8,r7,54712
	ctx.r8.u64 = ctx.r7.u64 | 54712;
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// addis r7,r31,1
	ctx.r7.s64 = r31.s64 + 65536;
	// stwx r30,r31,r3
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, r30.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stwx r30,r31,r4
	PPC_STORE_U32(r31.u32 + ctx.r4.u32, r30.u32);
	// stwx r30,r31,r5
	PPC_STORE_U32(r31.u32 + ctx.r5.u32, r30.u32);
	// addi r7,r7,-11200
	ctx.r7.s64 = ctx.r7.s64 + -11200;
	// li r10,16
	ctx.r10.s64 = 16;
	// stwx r30,r31,r9
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, r30.u32);
	// ori r3,r6,54400
	ctx.r3.u64 = ctx.r6.u64 | 54400;
	// stfsx f0,r31,r8
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// vpermwi128 v58,v62,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// lis r4,0
	ctx.r4.s64 = 0;
	// vpermwi128 v57,v62,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// addis r6,r31,1
	ctx.r6.s64 = r31.s64 + 65536;
	// vpermwi128 v56,v62,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// li r11,48
	r11.s64 = 48;
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r9,r5,54404
	ctx.r9.u64 = ctx.r5.u64 | 54404;
	// stvx128 v60,r7,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r8,r4,54408
	ctx.r8.u64 = ctx.r4.u64 | 54408;
	// vpermwi128 v55,v62,234
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// addi r6,r6,-11120
	ctx.r6.s64 = ctx.r6.s64 + -11120;
	// stvx128 v59,r7,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addis r5,r31,1
	ctx.r5.s64 = r31.s64 + 65536;
	// vpermwi128 v54,v62,186
	simde_mm_store_si128((simde__m128i*)v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stvx128 v63,r7,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v53,v62,174
	simde_mm_store_si128((simde__m128i*)v53.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// addi r5,r5,-11056
	ctx.r5.s64 = ctx.r5.s64 + -11056;
	// stfsx f10,r31,r3
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, temp.u32);
	// stfsx f10,r31,r9
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + ctx.r9.u32, temp.u32);
	// addis r4,r31,1
	ctx.r4.s64 = r31.s64 + 65536;
	// stfsx f10,r31,r8
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, temp.u32);
	// vpermwi128 v52,v62,234
	simde_mm_store_si128((simde__m128i*)v52.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v51,v62,186
	simde_mm_store_si128((simde__m128i*)v51.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// stvx128 v57,r6,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r4,-10992
	ctx.r4.s64 = ctx.r4.s64 + -10992;
	// stvx128 v56,r6,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v50,v62,174
	simde_mm_store_si128((simde__m128i*)v50.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v63,r6,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,0
	ctx.r3.s64 = 0;
	// stvx128 v55,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stvx128 v54,r5,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r8,r3,54696
	ctx.r8.u64 = ctx.r3.u64 | 54696;
	// stvx128 v53,r5,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,27
	ctx.r6.s64 = 27;
	// stvx128 v63,r5,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,0
	ctx.r5.s64 = 0;
	// stvx128 v52,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r3,0
	ctx.r3.s64 = 0;
	// stvx128 v51,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r10,r5,54704
	ctx.r10.u64 = ctx.r5.u64 | 54704;
	// stvx128 v50,r4,r29
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// stvx128 v63,r4,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r3,r3,54700
	ctx.r3.u64 = ctx.r3.u64 | 54700;
	// lfs f0,-15580(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -15580);
	f0.f64 = double(temp.f32);
	// lis r5,-32125
	ctx.r5.s64 = -2105344000;
	// stwx r6,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, ctx.r6.u32);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// lfs f13,11368(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 11368);
	ctx.f13.f64 = double(temp.f32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// stfsx f0,r31,r3
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + ctx.r3.u32, temp.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stfsx f13,r31,r10
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + ctx.r10.u32, temp.u32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lwz r3,2832(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2832);
	// addi r9,r4,-14596
	ctx.r9.s64 = ctx.r4.s64 + -14596;
	// addi r5,r6,-15592
	ctx.r5.s64 = ctx.r6.s64 + -15592;
	// addi r8,r11,-14960
	ctx.r8.s64 = r11.s64 + -14960;
	// ori r7,r7,42256
	ctx.r7.u64 = ctx.r7.u64 | 42256;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82202b98
	ctx.lr = 0x82253DA4;
	sub_82202B98(ctx, base);
	// bl 0x82263b18
	ctx.lr = 0x82253DA8;
	sub_82263B18(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stw r3,11584(r31)
	PPC_STORE_U32(r31.u32 + 11584, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// ori r4,r5,54610
	ctx.r4.u64 = ctx.r5.u64 | 54610;
	// stbx r30,r31,r4
	PPC_STORE_U8(r31.u32 + ctx.r4.u32, r30.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82253AA0) {
	__imp__sub_82253AA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253DC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82253DC4) {
	__imp__sub_82253DC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253DC8) {
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
	ctx.lr = 0x82253DD0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r11,-15572
	ctx.r10.s64 = r11.s64 + -15572;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// lwz r3,11584(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 11584);
	// bl 0x82263c18
	ctx.lr = 0x82253DEC;
	sub_82263C18(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822687b0
	ctx.lr = 0x82253DF4;
	sub_822687B0(ctx, base);
	// addis r3,r29,1
	ctx.r3.s64 = r29.s64 + 65536;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r3,r3,-10852
	ctx.r3.s64 = ctx.r3.s64 + -10852;
	// addi r8,r9,15048
	ctx.r8.s64 = ctx.r9.s64 + 15048;
	// stw r8,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r8.u32);
	// bl 0x821d2028
	ctx.lr = 0x82253E0C;
	sub_821D2028(ctx, base);
	// addis r11,r29,1
	r11.s64 = r29.s64 + 65536;
	// addi r11,r11,-10860
	r11.s64 = r11.s64 + -10860;
	// lhz r7,6(r11)
	ctx.r7.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82253e28
	if (cr6.eq) goto loc_82253E28;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x82253E28;
	sub_82130588(ctx, base);
loc_82253E28:
	// addi r3,r29,11600
	ctx.r3.s64 = r29.s64 + 11600;
	// bl 0x82265240
	ctx.lr = 0x82253E30;
	sub_82265240(ctx, base);
	// addi r31,r29,11584
	r31.s64 = r29.s64 + 11584;
	// li r30,30
	r30.s64 = 30;
loc_82253E38:
	// addi r31,r31,-368
	r31.s64 = r31.s64 + -368;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82265240
	ctx.lr = 0x82253E44;
	sub_82265240(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x82253e38
	if (!cr0.lt) goto loc_82253E38;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e0430
	ctx.lr = 0x82253E54;
	sub_824E0430(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82253DC8) {
	__imp__sub_82253DC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82253E5C) {
	__imp__sub_82253E5C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253E60) {
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
	// lis r3,0
	ctx.r3.s64 = 0;
	// ori r3,r3,54864
	ctx.r3.u64 = ctx.r3.u64 | 54864;
	// bl 0x82130528
	ctx.lr = 0x82253E78;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82253e88
	if (cr6.eq) goto loc_82253E88;
	// bl 0x82253aa0
	ctx.lr = 0x82253E84;
	sub_82253AA0(ctx, base);
	// b 0x82253e8c
	goto loc_82253E8C;
loc_82253E88:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82253E8C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-6148(r11)
	PPC_STORE_U32(r11.u32 + -6148, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82253E60) {
	__imp__sub_82253E60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253EA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82253EA4) {
	__imp__sub_82253EA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253EA8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCVRegister v63{};
	PPCRegister temp{};
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// addi r8,r11,4
	ctx.r8.s64 = r11.s64 + 4;
	// addi r7,r10,-6128
	ctx.r7.s64 = ctx.r10.s64 + -6128;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,0(r9)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stwx r5,r6,r3
	PPC_STORE_U32(ctx.r6.u32 + ctx.r3.u32, ctx.r5.u32);
	// lfs f0,8(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	f0.f64 = double(temp.f32);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r4,r11,2
	ctx.r4.s64 = r11.s64 + 2;
	// rlwinm r11,r4,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f13,4(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 0);
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,12(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,2
	ctx.r9.s64 = r11.s64 + 2;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rlwinm r11,r9,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r5,r6,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// lvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r5,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82253EA8) {
	__imp__sub_82253EA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82253F20) {
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
	ctx.lr = 0x82253F28;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82254020
	if (cr6.eq) goto loc_82254020;
	// bl 0x82250818
	ctx.lr = 0x82253F40;
	sub_82250818(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r28,168(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// ble cr6,0x82253ffc
	if (!cr6.gt) goto loc_82253FFC;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82267e30
	ctx.lr = 0x82253F58;
	sub_82267E30(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bge cr6,0x82253f94
	if (!cr6.lt) goto loc_82253F94;
	// mulli r11,r28,368
	r11.s64 = r28.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r30,r11,176
	r30.s64 = r11.s64 + 176;
loc_82253F74:
	// addi r4,r30,368
	ctx.r4.s64 = r30.s64 + 368;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82264c90
	ctx.lr = 0x82253F80;
	sub_82264C90(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,368
	r30.s64 = r30.s64 + 368;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x82253f74
	if (cr6.lt) goto loc_82253F74;
loc_82253F94:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x82253fbc
	if (!cr6.eq) goto loc_82253FBC;
	// li r11,1
	r11.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// stb r11,158(r31)
	PPC_STORE_U8(r31.u32 + 158, r11.u8);
	// b 0x82253fc0
	goto loc_82253FC0;
loc_82253FBC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_82253FC0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252948
	ctx.lr = 0x82253FC8;
	sub_82252948(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,160(r31)
	PPC_STORE_U32(r31.u32 + 160, r11.u32);
	// ble 0x82253ff8
	if (!cr0.gt) goto loc_82253FF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250690
	ctx.lr = 0x82253FE0;
	sub_82250690(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x822523f0
	ctx.lr = 0x82253FEC;
	sub_822523F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268118
	ctx.lr = 0x82253FF4;
	sub_82268118(ctx, base);
	// b 0x82253ffc
	goto loc_82253FFC;
loc_82253FF8:
	// bl 0x822635a8
	ctx.lr = 0x82253FFC;
	sub_822635A8(ctx, base);
loc_82253FFC:
	// li r11,3
	r11.s64 = 3;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stb r11,159(r31)
	PPC_STORE_U8(r31.u32 + 159, r11.u8);
	// bne cr6,0x82254020
	if (!cr6.eq) goto loc_82254020;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82254020
	if (!cr6.gt) goto loc_82254020;
	// li r11,0
	r11.s64 = 0;
	// stw r11,168(r31)
	PPC_STORE_U32(r31.u32 + 168, r11.u32);
loc_82254020:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82253F20) {
	__imp__sub_82253F20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254028) {
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
	ctx.lr = 0x82254030;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82254044;
	sub_8238EC00(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addis r29,r30,1
	r29.s64 = r30.s64 + 65536;
	// li r9,80
	ctx.r9.s64 = 80;
	// addi r29,r29,-11244
	r29.s64 = r29.s64 + -11244;
	// lwz r11,-12648(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12648);
	// subf r8,r11,r3
	ctx.r8.s64 = ctx.r3.s64 - r11.s64;
	// lwz r31,0(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// divw r7,r8,r9
	ctx.r7.s32 = ctx.r8.s32 / ctx.r9.s32;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
loc_82254068:
	// addi r11,r31,1
	r11.s64 = r31.s64 + 1;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// srawi r7,r10,3
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 3;
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// addze r5,r7
	temp.s64 = ctx.r7.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r7.u32;
	ctx.r5.s64 = temp.s64;
	// rlwinm r11,r6,30,28,28
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x8;
	// rlwinm r4,r5,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r10,r4,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r4.s64;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// mulli r11,r31,1056
	r11.s64 = r31.s64 * 1056;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r11,r11,11984
	r11.s64 = r11.s64 + 11984;
	// lbz r10,1043(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1043);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x822540d0
	if (cr6.eq) goto loc_822540D0;
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// beq cr6,0x822540b8
	if (cr6.eq) goto loc_822540B8;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822540c8
	if (!cr6.eq) goto loc_822540C8;
loc_822540B8:
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822540d0
	if (cr6.eq) goto loc_822540D0;
	// cmplwi cr6,r9,3
	cr6.compare<uint32_t>(ctx.r9.u32, 3, xer);
	// beq cr6,0x822540d0
	if (cr6.eq) goto loc_822540D0;
loc_822540C8:
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x822540d4
	goto loc_822540D4;
loc_822540D0:
	// li r10,1
	ctx.r10.s64 = 1;
loc_822540D4:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82254068
	if (cr6.eq) goto loc_82254068;
	// lbz r10,1043(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1043);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x822540f4
	if (!cr6.eq) goto loc_822540F4;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822540f8
	goto loc_822540F8;
loc_822540F4:
	// lbz r11,1042(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 1042);
loc_822540F8:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x82254068
	if (cr6.lt) goto loc_82254068;
	// lbz r11,13(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254128
	if (cr6.eq) goto loc_82254128;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82261058
	ctx.lr = 0x82254114;
	sub_82261058(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r11,1
	r11.s64 = 1;
	// stb r9,13(r30)
	PPC_STORE_U8(r30.u32 + 13, ctx.r9.u8);
	// stb r11,-6144(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6144, r11.u8);
loc_82254128:
	// stw r31,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82253670
	ctx.lr = 0x82254134;
	sub_82253670(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82252628
	ctx.lr = 0x82254140;
	sub_82252628(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82254028) {
	__imp__sub_82254028(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254148) {
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
	// bl 0x82252d70
	ctx.lr = 0x82254160;
	sub_82252D70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252cf8
	ctx.lr = 0x82254168;
	sub_82252CF8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82254148) {
	__imp__sub_82254148(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225417C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225417C) {
	__imp__sub_8225417C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254180) {
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
	ctx.lr = 0x82254188;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addis r28,r31,1
	r28.s64 = r31.s64 + 65536;
	// addi r28,r28,-11236
	r28.s64 = r28.s64 + -11236;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82727b08
	ctx.lr = 0x822541A0;
	sub_82727B08(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254284
	if (cr6.eq) goto loc_82254284;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822541cc
	if (cr6.eq) goto loc_822541CC;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822541CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822541CC:
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r29,-11232
	r29.s64 = r29.s64 + -11232;
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822541f8
	if (cr6.eq) goto loc_822541F8;
	// bl 0x82256068
	ctx.lr = 0x822541EC;
	sub_82256068(ctx, base);
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x821f8480
	ctx.lr = 0x822541F4;
	sub_821F8480(ctx, base);
	// stw r30,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r30.u32);
loc_822541F8:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x8225422c
	if (!cr6.gt) goto loc_8225422C;
	// addi r29,r31,240
	r29.s64 = r31.s64 + 240;
loc_82254208:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822681e0
	ctx.lr = 0x82254218;
	sub_822681E0(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,368
	r29.s64 = r29.s64 + 368;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82254208
	if (cr6.lt) goto loc_82254208;
loc_8225422C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250690
	ctx.lr = 0x82254234;
	sub_82250690(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x822523f0
	ctx.lr = 0x82254240;
	sub_822523F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268118
	ctx.lr = 0x82254248;
	sub_82268118(ctx, base);
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254260
	if (cr6.eq) goto loc_82254260;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252e10
	ctx.lr = 0x82254260;
	sub_82252E10(ctx, base);
loc_82254260:
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x82216138
	ctx.lr = 0x82254268;
	sub_82216138(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-12248
	ctx.r4.s64 = ctx.r10.s64 + -12248;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8225427C;
	sub_821F9FB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82720e28
	ctx.lr = 0x82254284;
	sub_82720E28(ctx, base);
loc_82254284:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82254180) {
	__imp__sub_82254180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225428C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225428C) {
	__imp__sub_8225428C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254290) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addis r4,r31,1
	ctx.r4.s64 = r31.s64 + 65536;
	// addi r4,r4,-10860
	ctx.r4.s64 = ctx.r4.s64 + -10860;
	// lhz r11,4(r4)
	r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rotlwi r11,r11,4
	r11.u64 = __builtin_rotateleft32(r11.u32, 4);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x822542e4
	if (cr6.eq) goto loc_822542E4;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_822542D0:
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r8,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x822542d0
	if (!cr6.eq) goto loc_822542D0;
loc_822542E4:
	// subf r10,r9,r11
	ctx.r10.s64 = r11.s64 - ctx.r9.s64;
	// lhz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// srawi r8,r10,4
	xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 4;
	// subf r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	// sth r7,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, ctx.r7.u16);
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x82254344
	if (!cr6.gt) goto loc_82254344;
	// addi r10,r31,240
	ctx.r10.s64 = r31.s64 + 240;
loc_8225430C:
	// lhz r9,4(r4)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r4.u32 + 4);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lwz r8,0(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r7,r9
	ctx.r7.u64 = ctx.r9.u64;
	// rotlwi r9,r9,4
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 4);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r7,4(r4)
	PPC_STORE_U16(ctx.r4.u32 + 4, ctx.r7.u16);
	// lvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,368
	ctx.r10.s64 = ctx.r10.s64 + 368;
	// stvx128 v62,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,160(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpw cr6,r11,r5
	cr6.compare<int32_t>(r11.s32, ctx.r5.s32, xer);
	// blt cr6,0x8225430c
	if (cr6.lt) goto loc_8225430C;
loc_82254344:
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// addi r30,r30,-10852
	r30.s64 = r30.s64 + -10852;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,24(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82254360;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r8,r9,54692
	ctx.r8.u64 = ctx.r9.u64 | 54692;
	// stwx r30,r31,r8
	PPC_STORE_U32(r31.u32 + ctx.r8.u32, r30.u32);
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

PPC_WEAK_FUNC(sub_82254290) {
	__imp__sub_82254290(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82254384) {
	__imp__sub_82254384(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254388) {
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
	ctx.lr = 0x82254390;
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82251d70
	ctx.lr = 0x822543A4;
	sub_82251D70(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822543c0
	if (cr6.eq) goto loc_822543C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15540
	ctx.r3.s64 = r11.s64 + -15540;
	// bl 0x821e6800
	ctx.lr = 0x822543B8;
	sub_821E6800(ctx, base);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d924c
	return;
loc_822543C0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15924
	ctx.r3.s64 = r11.s64 + -15924;
	// bl 0x821e6800
	ctx.lr = 0x822543CC;
	sub_821E6800(ctx, base);
	// addis r4,r31,1
	ctx.r4.s64 = r31.s64 + 65536;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r4,-10816
	ctx.r4.s64 = ctx.r4.s64 + -10816;
	// lwz r30,168(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// bl 0x82252c58
	ctx.lr = 0x822543E0;
	sub_82252C58(ctx, base);
	// clrlwi r29,r29,24
	r29.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8225447c
	if (cr6.eq) goto loc_8225447C;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// ble cr6,0x8225447c
	if (!cr6.gt) goto loc_8225447C;
loc_822543FC:
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,176
	ctx.r4.s64 = r11.s64 + 176;
	// bl 0x82251338
	ctx.lr = 0x82254414;
	sub_82251338(ctx, base);
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82254468
	if (cr6.eq) goto loc_82254468;
	// li r4,-1
	ctx.r4.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268058
	ctx.lr = 0x8225442C;
	sub_82268058(ctx, base);
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r4,r11,-192
	ctx.r4.s64 = r11.s64 + -192;
	// addi r3,r11,176
	ctx.r3.s64 = r11.s64 + 176;
	// bl 0x82264c90
	ctx.lr = 0x82254444;
	sub_82264C90(ctx, base);
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mulli r11,r10,368
	r11.s64 = ctx.r10.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// addi r3,r11,-192
	ctx.r3.s64 = r11.s64 + -192;
	// bl 0x82264c90
	ctx.lr = 0x8225445C;
	sub_82264C90(ctx, base);
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r9,168(r31)
	PPC_STORE_U32(r31.u32 + 168, ctx.r9.u32);
loc_82254468:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82265240
	ctx.lr = 0x82254470;
	sub_82265240(ctx, base);
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// bgt cr6,0x822543fc
	if (cr6.gt) goto loc_822543FC;
loc_8225447C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8225448C;
	sub_822A3998(ctx, base);
	// lwz r10,880(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// addis r9,r31,1
	ctx.r9.s64 = r31.s64 + 65536;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r9,r9,-10992
	ctx.r9.s64 = ctx.r9.s64 + -10992;
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,16(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r5,48(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 48);
	// stw r9,144(r5)
	PPC_STORE_U32(ctx.r5.u32 + 144, ctx.r9.u32);
	// lwz r4,168(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lfs f0,344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 344);
	f0.f64 = double(temp.f32);
	// stfs f0,-13516(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + -13516, temp.u32);
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// mulli r11,r10,368
	r11.s64 = ctx.r10.s64 * 368;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// lfs f0,356(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 356);
	f0.f64 = double(temp.f32);
	// stfs f0,-13512(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -13512, temp.u32);
	// lwz r6,160(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mulli r11,r6,368
	r11.s64 = ctx.r6.s64 * 368;
	// add r5,r11,r31
	ctx.r5.u64 = r11.u64 + r31.u64;
	// lfs f0,344(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 344);
	f0.f64 = double(temp.f32);
	// stfs f0,-13516(r8)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r8.u32 + -13516, temp.u32);
	// lwz r4,160(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lfs f0,356(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 356);
	f0.f64 = double(temp.f32);
	// stfs f0,-13512(r7)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r7.u32 + -13512, temp.u32);
	// bl 0x82250690
	ctx.lr = 0x82254504;
	sub_82250690(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x822523f0
	ctx.lr = 0x82254510;
	sub_822523F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268118
	ctx.lr = 0x82254518;
	sub_82268118(ctx, base);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// li r11,2
	r11.s64 = 2;
	// bne cr6,0x82254528
	if (!cr6.eq) goto loc_82254528;
	// li r11,1
	r11.s64 = 1;
loc_82254528:
	// stb r11,159(r31)
	PPC_STORE_U8(r31.u32 + 159, r11.u8);
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82254388) {
	__imp__sub_82254388(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82254534) {
	__imp__sub_82254534(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254538) {
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
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82251d70
	ctx.lr = 0x82254554;
	sub_82251D70(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8225457c
	if (cr6.eq) goto loc_8225457C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15540
	ctx.r3.s64 = r11.s64 + -15540;
	// bl 0x821e6800
	ctx.lr = 0x82254568;
	sub_821E6800(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8225457C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15924
	ctx.r3.s64 = r11.s64 + -15924;
	// bl 0x821e6800
	ctx.lr = 0x82254588;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82254598;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x8225459C;
	sub_822A8108(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,48
	ctx.r4.s64 = r11.s64 + 48;
	// bl 0x82252c58
	ctx.lr = 0x822545AC;
	sub_82252C58(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,159(r31)
	PPC_STORE_U8(r31.u32 + 159, ctx.r9.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82254538) {
	__imp__sub_82254538(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822545C8) {
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
	// bl 0x823d91e0
	ctx.lr = 0x822545D0;
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addis r29,r31,1
	r29.s64 = r31.s64 + 65536;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r29,-11224
	r29.s64 = r29.s64 + -11224;
	// li r22,0
	r22.s64 = 0;
	// ori r24,r10,54308
	r24.u64 = ctx.r10.u64 | 54308;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r30,r11,-12248
	r30.s64 = r11.s64 + -12248;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82254664
	if (!cr6.eq) goto loc_82254664;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// addi r4,r11,-21652
	ctx.r4.s64 = r11.s64 + -21652;
	// bl 0x821f9fb8
	ctx.lr = 0x82254614;
	sub_821F9FB8(ctx, base);
	// stw r3,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r3.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82254664
	if (cr6.eq) goto loc_82254664;
	// lwz r11,56(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 56);
	// li r4,1
	ctx.r4.s64 = 1;
	// stwx r11,r31,r24
	PPC_STORE_U32(r31.u32 + r24.u32, r11.u32);
	// bl 0x82720e28
	ctx.lr = 0x82254630;
	sub_82720E28(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8225463C;
	sub_821F9FB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82720e28
	ctx.lr = 0x82254644;
	sub_82720E28(ctx, base);
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// addi r11,r11,-10928
	r11.s64 = r11.s64 + -10928;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82254664
	if (cr6.eq) goto loc_82254664;
	// stb r22,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r22.u8);
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x82216138
	ctx.lr = 0x82254664;
	sub_82216138(ctx, base);
loc_82254664:
	// lbz r11,13(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225468c
	if (!cr6.eq) goto loc_8225468C;
	// lis r11,0
	r11.s64 = 0;
	// ori r10,r11,54300
	ctx.r10.u64 = r11.u64 | 54300;
	// lwzx r9,r31,r10
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225468c
	if (cr6.eq) goto loc_8225468C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82254180
	ctx.lr = 0x8225468C;
	sub_82254180(ctx, base);
loc_8225468C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,-6144(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6144);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82254ec4
	if (cr6.eq) goto loc_82254EC4;
	// lbz r11,13(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 13);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254ec4
	if (!cr6.eq) goto loc_82254EC4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r28,r10,54609
	r28.u64 = ctx.r10.u64 | 54609;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225475c
	if (cr6.eq) goto loc_8225475C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10236(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x822546C8;
	sub_821F9FB8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82720e28
	ctx.lr = 0x822546D0;
	sub_82720E28(ctx, base);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r3,r11,224
	ctx.r3.s64 = r11.s64 + 224;
	// bl 0x82237390
	ctx.lr = 0x822546E0;
	sub_82237390(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x8225473c
	if (!cr6.eq) goto loc_8225473C;
	// lbzx r11,r31,r28
	r11.u64 = PPC_LOAD_U8(r31.u32 + r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225473c
	if (!cr6.eq) goto loc_8225473C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,-12640(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82254718
	if (cr6.eq) goto loc_82254718;
	// lbz r11,10(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8225471c
	if (cr6.eq) goto loc_8225471C;
loc_82254718:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8225471C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225473c
	if (!cr6.eq) goto loc_8225473C;
	// lbz r11,6(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225473c
	if (!cr6.eq) goto loc_8225473C;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x8225474c
	goto loc_8225474C;
loc_8225473C:
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82720e28
	ctx.lr = 0x82254748;
	sub_82720E28(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
loc_8225474C:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwzx r3,r31,r24
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r24.u32);
	// addi r4,r11,-19772
	ctx.r4.s64 = r11.s64 + -19772;
	// bl 0x825ee0e0
	ctx.lr = 0x8225475C;
	sub_825EE0E0(ctx, base);
loc_8225475C:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addis r11,r31,1
	r11.s64 = r31.s64 + 65536;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r11,-10992
	r11.s64 = r11.s64 + -10992;
	// li r9,32
	ctx.r9.s64 = 32;
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
	// li r8,48
	ctx.r8.s64 = 48;
	// lis r7,0
	ctx.r7.s64 = 0;
	// li r6,240
	ctx.r6.s64 = 240;
	// ori r5,r7,54592
	ctx.r5.u64 = ctx.r7.u64 | 54592;
	// vpermwi128 v61,v62,234
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x15));
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vpermwi128 v60,v62,186
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x45));
	// vpermwi128 v59,v62,174
	simde_mm_store_si128((simde__m128i*)v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0x51));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r11,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,160(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mulli r11,r4,368
	r11.s64 = ctx.r4.s64 * 368;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// lvx128 v58,r11,r6
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82250690
	ctx.lr = 0x822547BC;
	sub_82250690(ctx, base);
	// bl 0x82268270
	ctx.lr = 0x822547C0;
	sub_82268270(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lfs f13,-13516(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -13516);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-13520(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13520);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x822547dc
	if (!cr6.lt) goto loc_822547DC;
	// stfs f0,-13516(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + -13516, temp.u32);
loc_822547DC:
	// lbz r11,156(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254834
	if (cr6.eq) goto loc_82254834;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822547F8;
	sub_822A3998(ctx, base);
	// lbz r11,908(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 908);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254814
	if (!cr6.eq) goto loc_82254814;
	// lbz r11,909(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 909);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82254818
	if (cr6.eq) goto loc_82254818;
loc_82254814:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82254818:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254834
	if (cr6.eq) goto loc_82254834;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a3d80
	ctx.lr = 0x82254834;
	sub_822A3D80(ctx, base);
loc_82254834:
	// lbz r11,14(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254850
	if (cr6.eq) goto loc_82254850;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268b30
	ctx.lr = 0x82254848;
	sub_82268B30(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9230
	return;
loc_82254850:
	// addis r30,r31,1
	r30.s64 = r31.s64 + 65536;
	// addi r30,r30,-11240
	r30.s64 = r30.s64 + -11240;
	// lbz r11,0(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225486c
	if (cr6.eq) goto loc_8225486C;
	// addi r11,r11,255
	r11.s64 = r11.s64 + 255;
	// stb r11,0(r30)
	PPC_STORE_U8(r30.u32 + 0, r11.u8);
loc_8225486C:
	// addis r25,r31,1
	r25.s64 = r31.s64 + 65536;
	// addi r25,r25,-11216
	r25.s64 = r25.s64 + -11216;
	// lbz r11,0(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254888
	if (cr6.eq) goto loc_82254888;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822514f0
	ctx.lr = 0x82254888;
	sub_822514F0(ctx, base);
loc_82254888:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82387ba0
	ctx.lr = 0x82254890;
	sub_82387BA0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82254ebc
	if (cr6.eq) goto loc_82254EBC;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,54610
	ctx.r9.u64 = ctx.r10.u64 | 54610;
	// lbzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + ctx.r9.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82254ebc
	if (!cr6.eq) goto loc_82254EBC;
	// lbz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U8(r30.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82254ebc
	if (!cr6.eq) goto loc_82254EBC;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lbz r8,156(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 156);
	// rlwinm r9,r11,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r10,r10,21384
	ctx.r10.s64 = ctx.r10.s64 + 21384;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r10,8
	ctx.r7.s64 = ctx.r10.s64 + 8;
	// lwz r6,8(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r5,12(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lwzx r27,r9,r7
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	// xor r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 ^ ctx.r6.u64;
	// and r23,r4,r6
	r23.u64 = ctx.r4.u64 & ctx.r6.u64;
	// bne cr6,0x82254ab0
	if (!cr6.eq) goto loc_82254AB0;
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r22,248(r11)
	PPC_STORE_U32(r11.u32 + 248, r22.u32);
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82254908;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8225490C;
	sub_822A5578(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x82254918;
	sub_822A4CE0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225492c
	if (cr6.eq) goto loc_8225492C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82254538
	ctx.lr = 0x8225492C;
	sub_82254538(ctx, base);
loc_8225492C:
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82254938;
	sub_822A3998(ctx, base);
	// bl 0x822a5578
	ctx.lr = 0x8225493C;
	sub_822A5578(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,116(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// bl 0x822a4ce0
	ctx.lr = 0x82254948;
	sub_822A4CE0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225495c
	if (cr6.eq) goto loc_8225495C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250df0
	ctx.lr = 0x8225495C;
	sub_82250DF0(ctx, base);
loc_8225495C:
	// lwzx r3,r31,r24
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r24.u32);
	// add r29,r31,r24
	r29.u64 = r31.u64 + r24.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82254ebc
	if (cr6.eq) goto loc_82254EBC;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r30,4
	r30.s64 = 4;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// addi r28,r10,-15480
	r28.s64 = ctx.r10.s64 + -15480;
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,240(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 240);
	f0.f64 = double(temp.f32);
	// stw r30,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r30.u32);
	// stfs f0,176(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x822549A0;
	sub_82203058(ctx, base);
	// lwz r8,160(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r11,r8,368
	r11.s64 = ctx.r8.s64 * 368;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f13,244(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r30.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x822549CC;
	sub_82203058(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// li r5,2
	ctx.r5.s64 = 2;
	// lfs f12,248(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 248);
	ctx.f12.f64 = double(temp.f32);
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, r30.u32);
	// stfs f12,240(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x822549F8;
	sub_82203058(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r9,-15496
	ctx.r4.s64 = ctx.r9.s64 + -15496;
	// bl 0x825ee0e0
	ctx.lr = 0x82254A0C;
	sub_825EE0E0(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r30,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, r30.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// ori r11,r8,54720
	r11.u64 = ctx.r8.u64 | 54720;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r28,r7,-15508
	r28.s64 = ctx.r7.s64 + -15508;
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfsx f11,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254A3C;
	sub_82203058(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r30,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r30.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r9,r10,54724
	ctx.r9.u64 = ctx.r10.u64 | 54724;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfsx f10,r31,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,208(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254A64;
	sub_82203058(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// ori r7,r8,54728
	ctx.r7.u64 = ctx.r8.u64 | 54728;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,2
	ctx.r5.s64 = 2;
	// lfsx f9,r31,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254A8C;
	sub_82203058(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r6,-15524
	ctx.r4.s64 = ctx.r6.s64 + -15524;
	// bl 0x825ee0e0
	ctx.lr = 0x82254AA0;
	sub_825EE0E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82254290
	ctx.lr = 0x82254AA8;
	sub_82254290(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9230
	return;
loc_82254AB0:
	// add r28,r31,r28
	r28.u64 = r31.u64 + r28.u64;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-10236(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// beq cr6,0x82254ae0
	if (cr6.eq) goto loc_82254AE0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,54692
	ctx.r9.u64 = ctx.r10.u64 | 54692;
	// lwzx r8,r31,r9
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// stb r22,252(r11)
	PPC_STORE_U8(r11.u32 + 252, r22.u8);
	// stw r8,248(r11)
	PPC_STORE_U32(r11.u32 + 248, ctx.r8.u32);
	// b 0x82254ae4
	goto loc_82254AE4;
loc_82254AE0:
	// stw r22,248(r11)
	PPC_STORE_U32(r11.u32 + 248, r22.u32);
loc_82254AE4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82251fd0
	ctx.lr = 0x82254AEC;
	sub_82251FD0(ctx, base);
	// lwzx r3,r31,r24
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + r24.u32);
	// add r29,r31,r24
	r29.u64 = r31.u64 + r24.u64;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82254c3c
	if (cr6.eq) goto loc_82254C3C;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254c3c
	if (cr6.eq) goto loc_82254C3C;
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// li r30,4
	r30.s64 = 4;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r9,r11,r31
	ctx.r9.u64 = r11.u64 + r31.u64;
	// addi r26,r10,-15480
	r26.s64 = ctx.r10.s64 + -15480;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,240(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 240);
	f0.f64 = double(temp.f32);
	// stw r30,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r30.u32);
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254B3C;
	sub_82203058(ctx, base);
	// lwz r8,160(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r11,r8,368
	r11.s64 = ctx.r8.s64 * 368;
	// add r7,r11,r31
	ctx.r7.u64 = r11.u64 + r31.u64;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfs f13,244(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 244);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r30.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254B68;
	sub_82203058(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mulli r11,r11,368
	r11.s64 = r11.s64 * 368;
	// add r10,r11,r31
	ctx.r10.u64 = r11.u64 + r31.u64;
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// li r5,2
	ctx.r5.s64 = 2;
	// lfs f12,248(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 248);
	ctx.f12.f64 = double(temp.f32);
	// stw r30,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, r30.u32);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254B94;
	sub_82203058(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r5,9
	ctx.r5.s64 = 9;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r9,-15496
	ctx.r4.s64 = ctx.r9.s64 + -15496;
	// bl 0x825ee0e0
	ctx.lr = 0x82254BA8;
	sub_825EE0E0(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r30,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, r30.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// ori r11,r8,54720
	r11.u64 = ctx.r8.u64 | 54720;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r26,r7,-15508
	r26.s64 = ctx.r7.s64 + -15508;
	// addi r6,r1,192
	ctx.r6.s64 = ctx.r1.s64 + 192;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfsx f11,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,192(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254BD8;
	sub_82203058(ctx, base);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r30,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// ori r9,r10,54724
	ctx.r9.u64 = ctx.r10.u64 | 54724;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// li r5,1
	ctx.r5.s64 = 1;
	// lfsx f10,r31,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,224(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254C00;
	sub_82203058(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stw r30,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, r30.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// ori r7,r8,54728
	ctx.r7.u64 = ctx.r8.u64 | 54728;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// li r5,2
	ctx.r5.s64 = 2;
	// lfsx f9,r31,r7
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + ctx.r7.u32);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,256(r1)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// bl 0x82203058
	ctx.lr = 0x82254C28;
	sub_82203058(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// li r5,11
	ctx.r5.s64 = 11;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r6,-15524
	ctx.r4.s64 = ctx.r6.s64 + -15524;
	// bl 0x825ee0e0
	ctx.lr = 0x82254C3C;
	sub_825EE0E0(ctx, base);
loc_82254C3C:
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254c58
	if (cr6.eq) goto loc_82254C58;
	// lbz r11,0(r25)
	r11.u64 = PPC_LOAD_U8(r25.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82254c5c
	if (cr6.eq) goto loc_82254C5C;
loc_82254C58:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82254C5C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r29,r11
	r29.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254cf8
	if (cr6.eq) goto loc_82254CF8;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lbz r11,-5144(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + -5144);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// rlwinm r11,r27,0,21,21
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x400;
	// bne cr6,0x82254cdc
	if (!cr6.eq) goto loc_82254CDC;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254cf8
	if (cr6.eq) goto loc_82254CF8;
	// rlwinm r11,r27,0,22,22
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254cf8
	if (cr6.eq) goto loc_82254CF8;
	// rlwinm r11,r27,0,30,30
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254cf8
	if (cr6.eq) goto loc_82254CF8;
	// clrlwi r11,r27,31
	r11.u64 = r27.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254cf8
	if (cr6.eq) goto loc_82254CF8;
	// rlwinm r11,r27,0,29,29
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254cf8
	if (cr6.eq) goto loc_82254CF8;
	// rlwinm r11,r23,0,25,25
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254cf8
	if (cr6.eq) goto loc_82254CF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252d70
	ctx.lr = 0x82254CCC;
	sub_82252D70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252cf8
	ctx.lr = 0x82254CD4;
	sub_82252CF8(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// b 0x82254cf4
	goto loc_82254CF4;
loc_82254CDC:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254cf8
	if (!cr6.eq) goto loc_82254CF8;
	// rlwinm r11,r27,0,22,22
	r11.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 0) & 0x200;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254cf8
	if (!cr6.eq) goto loc_82254CF8;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82254CF4:
	// stb r11,-5144(r30)
	PPC_STORE_U8(r30.u32 + -5144, r11.u8);
loc_82254CF8:
	// rlwinm r11,r23,0,24,24
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254d18
	if (cr6.eq) goto loc_82254D18;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82254d18
	if (cr6.eq) goto loc_82254D18;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82254388
	ctx.lr = 0x82254D18;
	sub_82254388(ctx, base);
loc_82254D18:
	// rlwinm r11,r23,0,25,25
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254d4c
	if (cr6.eq) goto loc_82254D4C;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82254d4c
	if (cr6.eq) goto loc_82254D4C;
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254d44
	if (cr6.eq) goto loc_82254D44;
	// bl 0x82252ab8
	ctx.lr = 0x82254D40;
	sub_82252AB8(ctx, base);
	// b 0x82254d4c
	goto loc_82254D4C;
loc_82254D44:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82254388
	ctx.lr = 0x82254D4C;
	sub_82254388(ctx, base);
loc_82254D4C:
	// rlwinm r11,r23,0,26,26
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254d80
	if (cr6.eq) goto loc_82254D80;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82254d80
	if (cr6.eq) goto loc_82254D80;
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254d80
	if (cr6.eq) goto loc_82254D80;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15924
	ctx.r3.s64 = r11.s64 + -15924;
	// bl 0x821e6800
	ctx.lr = 0x82254D78;
	sub_821E6800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82253f20
	ctx.lr = 0x82254D80;
	sub_82253F20(ctx, base);
loc_82254D80:
	// rlwinm r11,r23,0,27,27
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x10;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254d94
	if (cr6.eq) goto loc_82254D94;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250df0
	ctx.lr = 0x82254D94;
	sub_82250DF0(ctx, base);
loc_82254D94:
	// clrlwi r11,r23,31
	r11.u64 = r23.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254db0
	if (cr6.eq) goto loc_82254DB0;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82254db0
	if (cr6.eq) goto loc_82254DB0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252ab8
	ctx.lr = 0x82254DB0;
	sub_82252AB8(ctx, base);
loc_82254DB0:
	// rlwinm r11,r23,0,16,16
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254e6c
	if (!cr6.eq) goto loc_82254E6C;
	// rlwinm r11,r23,0,29,29
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254e6c
	if (!cr6.eq) goto loc_82254E6C;
	// rlwinm r11,r23,0,18,18
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x2000;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254de0
	if (!cr6.eq) goto loc_82254DE0;
	// rlwinm r11,r23,0,28,28
	r11.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 0) & 0x8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254ebc
	if (cr6.eq) goto loc_82254EBC;
loc_82254DE0:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x82254ebc
	if (cr6.lt) goto loc_82254EBC;
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254ebc
	if (cr6.eq) goto loc_82254EBC;
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bgt cr6,0x82254e20
	if (cr6.gt) goto loc_82254E20;
	// bne cr6,0x82254ebc
	if (!cr6.eq) goto loc_82254EBC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82251cb0
	ctx.lr = 0x82254E14;
	sub_82251CB0(ctx, base);
	// extsb r11,r3
	r11.s64 = ctx.r3.s8;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82254ebc
	if (cr6.eq) goto loc_82254EBC;
loc_82254E20:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250818
	ctx.lr = 0x82254E28;
	sub_82250818(ctx, base);
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// lwz r10,168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bge cr6,0x82254ebc
	if (!cr6.lt) goto loc_82254EBC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82252948
	ctx.lr = 0x82254E48;
	sub_82252948(ctx, base);
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254eb4
	if (cr6.eq) goto loc_82254EB4;
	// li r3,44
	ctx.r3.s64 = 44;
	// bl 0x82216138
	ctx.lr = 0x82254E5C;
	sub_82216138(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82254290
	ctx.lr = 0x82254E64;
	sub_82254290(ctx, base);
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9230
	return;
loc_82254E6C:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// blt cr6,0x82254ebc
	if (cr6.lt) goto loc_82254EBC;
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82254ebc
	if (cr6.eq) goto loc_82254EBC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82250818
	ctx.lr = 0x82254E8C;
	sub_82250818(ctx, base);
	// lwz r11,168(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 168);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82254ebc
	if (!cr6.gt) goto loc_82254EBC;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,-1
	ctx.r4.s64 = -1;
	// bl 0x82252948
	ctx.lr = 0x82254EA4;
	sub_82252948(ctx, base);
	// lbz r11,158(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 158);
	// li r3,44
	ctx.r3.s64 = 44;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254eb8
	if (!cr6.eq) goto loc_82254EB8;
loc_82254EB4:
	// li r3,20
	ctx.r3.s64 = 20;
loc_82254EB8:
	// bl 0x82216138
	ctx.lr = 0x82254EBC;
	sub_82216138(ctx, base);
loc_82254EBC:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82254290
	ctx.lr = 0x82254EC4;
	sub_82254290(ctx, base);
loc_82254EC4:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_822545C8) {
	__imp__sub_822545C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82254ECC) {
	__imp__sub_82254ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82254ED0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82254ED8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,0
	ctx.r9.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// ori r26,r9,54609
	r26.u64 = ctx.r9.u64 | 54609;
	// lbz r8,-6144(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6144);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r11,r7,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r11,-6144(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6144, r11.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254fac
	if (!cr6.eq) goto loc_82254FAC;
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82254f28
	if (!cr6.eq) goto loc_82254F28;
	// lis r10,-32119
	ctx.r10.s64 = -2104950784;
	// lbz r9,-6745(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -6745);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r11,r8,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// stb r11,-6745(r10)
	PPC_STORE_U8(ctx.r10.u32 + -6745, r11.u8);
loc_82254F28:
	// lis r11,0
	r11.s64 = 0;
	// li r27,1
	r27.s64 = 1;
	// ori r10,r11,54610
	ctx.r10.u64 = r11.u64 | 54610;
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// stbx r27,r31,r10
	PPC_STORE_U8(r31.u32 + ctx.r10.u32, r27.u8);
	// bl 0x827057e0
	ctx.lr = 0x82254F44;
	sub_827057E0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x826d5d90
	ctx.lr = 0x82254F4C;
	sub_826D5D90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252d70
	ctx.lr = 0x82254F54;
	sub_82252D70(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822687b0
	ctx.lr = 0x82254F5C;
	sub_822687B0(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r9,-32120
	ctx.r9.s64 = -2105016320;
	// li r29,0
	r29.s64 = 0;
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r29,248(r8)
	PPC_STORE_U32(ctx.r8.u32 + 248, r29.u32);
	// stb r10,-7880(r9)
	PPC_STORE_U8(ctx.r9.u32 + -7880, ctx.r10.u8);
	// lbzx r7,r31,r26
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + r26.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822550ec
	if (cr6.eq) goto loc_822550EC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15720
	ctx.r3.s64 = r11.s64 + -15720;
	// bl 0x821fa230
	ctx.lr = 0x82254F94;
	sub_821FA230(ctx, base);
	// stb r29,384(r3)
	PPC_STORE_U8(ctx.r3.u32 + 384, r29.u8);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82220980
	ctx.lr = 0x82254FA8;
	sub_82220980(ctx, base);
	// b 0x822550ec
	goto loc_822550EC;
loc_82254FAC:
	// lis r11,-32119
	r11.s64 = -2104950784;
	// li r29,0
	r29.s64 = 0;
	// lis r8,-32120
	ctx.r8.s64 = -2105016320;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// lbz r6,-6745(r11)
	ctx.r6.u64 = PPC_LOAD_U8(r11.u32 + -6745);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// li r27,1
	r27.s64 = 1;
	// stw r10,-7884(r8)
	PPC_STORE_U32(ctx.r8.u32 + -7884, ctx.r10.u32);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// stb r9,-7880(r7)
	PPC_STORE_U8(ctx.r7.u32 + -7880, ctx.r9.u8);
	// beq cr6,0x82254fe4
	if (cr6.eq) goto loc_82254FE4;
	// stb r27,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r27.u8);
	// b 0x82254ff8
	goto loc_82254FF8;
loc_82254FE4:
	// stb r29,12(r31)
	PPC_STORE_U8(r31.u32 + 12, r29.u8);
	// lbz r10,-6745(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + -6745);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r9,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r10,-6745(r11)
	PPC_STORE_U8(r11.u32 + -6745, ctx.r10.u8);
loc_82254FF8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r3,6
	ctx.r3.s64 = 6;
	// lwz r11,17292(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 17292);
	// lwz r4,92(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 92);
	// bl 0x82267e98
	ctx.lr = 0x8225500C;
	sub_82267E98(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r10,-15732
	ctx.r3.s64 = ctx.r10.s64 + -15732;
	// bl 0x821fa230
	ctx.lr = 0x8225501C;
	sub_821FA230(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r9,-15744
	ctx.r4.s64 = ctx.r9.s64 + -15744;
	// bl 0x8268da78
	ctx.lr = 0x8225502C;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8225503c
	if (cr6.eq) goto loc_8225503C;
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
loc_8225503C:
	// li r3,22
	ctx.r3.s64 = 22;
	// bl 0x82216138
	ctx.lr = 0x82255044;
	sub_82216138(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x826d5d90
	ctx.lr = 0x8225504C;
	sub_826D5D90(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x827057e0
	ctx.lr = 0x82255058;
	sub_827057E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82268748
	ctx.lr = 0x82255060;
	sub_82268748(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8225506C;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lbz r10,88(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 88);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82255090
	if (cr6.eq) goto loc_82255090;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82255088;
	sub_822A3998(ctx, base);
	// lwz r11,880(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// stb r29,88(r11)
	PPC_STORE_U8(r11.u32 + 88, r29.u8);
loc_82255090:
	// lwz r11,160(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 160);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822550b8
	if (!cr6.eq) goto loc_822550B8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822550A8;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x822550AC;
	sub_822A8108(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82252b88
	ctx.lr = 0x822550B8;
	sub_82252B88(ctx, base);
loc_822550B8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5148(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5148);
	// bl 0x822b7dc8
	ctx.lr = 0x822550C4;
	sub_822B7DC8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r9,-15464
	ctx.r4.s64 = ctx.r9.s64 + -15464;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12440);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822550EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822550EC:
	// stb r29,156(r31)
	PPC_STORE_U8(r31.u32 + 156, r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stbx r29,r31,r26
	PPC_STORE_U8(r31.u32 + r26.u32, r29.u8);
	// stb r29,158(r31)
	PPC_STORE_U8(r31.u32 + 158, r29.u8);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82255104;
	sub_822A3998(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b1418
	ctx.lr = 0x8225510C;
	sub_822B1418(ctx, base);
	// stb r29,157(r31)
	PPC_STORE_U8(r31.u32 + 157, r29.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8225511C;
	sub_822A3998(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,880(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 880);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// lwz r31,80(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// bl 0x822a3998
	ctx.lr = 0x82255134;
	sub_822A3998(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afab0
	ctx.lr = 0x82255140;
	sub_822AFAB0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8225514C;
	sub_822A3998(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// lwz r8,880(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 880);
	// lwz r31,80(r8)
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// bl 0x822a3998
	ctx.lr = 0x82255164;
	sub_822A3998(ctx, base);
	// addi r7,r31,11
	ctx.r7.s64 = r31.s64 + 11;
	// lwz r6,880(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r6.u32);
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82255184;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82255190;
	sub_822A3998(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lfs f1,-15468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -15468);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x822551A4;
	sub_822B0F10(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822551B0;
	sub_822A3998(ctx, base);
	// lwz r9,880(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r3,16(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,36(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 36);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x822551C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r3,-12012(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x822551D4;
	sub_821F15C8(ctx, base);
	// bl 0x821e60c0
	ctx.lr = 0x822551D8;
	sub_821E60C0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82254ED0) {
	__imp__sub_82254ED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822551E0) {
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
	// bl 0x823d91e0
	ctx.lr = 0x822551E8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	r11.s64 = 0;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// ori r10,r11,54292
	ctx.r10.u64 = r11.u64 | 54292;
	// li r9,240
	ctx.r9.s64 = 240;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r7,608
	ctx.r7.s64 = 608;
	// lfs f0,356(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 356);
	f0.f64 = double(temp.f32);
	// li r29,80
	r29.s64 = 80;
	// lwzx r6,r30,r10
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + ctx.r10.u32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// li r10,976
	ctx.r10.s64 = 976;
	// mulli r11,r6,1056
	r11.s64 = ctx.r6.s64 * 1056;
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// stb r6,12048(r11)
	PPC_STORE_U8(r11.u32 + 12048, ctx.r6.u8);
	// lfs f12,344(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 344);
	ctx.f12.f64 = double(temp.f32);
	// addi r31,r11,11984
	r31.s64 = r11.s64 + 11984;
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// li r5,112
	ctx.r5.s64 = 112;
	// stb r6,12049(r11)
	PPC_STORE_U8(r11.u32 + 12049, ctx.r6.u8);
	// li r4,1344
	ctx.r4.s64 = 1344;
	// lvx128 v63,r30,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,144
	ctx.r3.s64 = 144;
	// stvx128 v63,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r28,1712
	r28.s64 = 1712;
	// lfs f10,724(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 724);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,12080(r11)
	PPC_STORE_U8(r11.u32 + 12080, ctx.r8.u8);
	// li r27,176
	r27.s64 = 176;
	// lfs f8,712(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 712);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r6,12081(r11)
	PPC_STORE_U8(r11.u32 + 12081, ctx.r6.u8);
	// li r26,2080
	r26.s64 = 2080;
	// lvx128 v62,r30,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,1092(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1092);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,12112(r11)
	PPC_STORE_U8(r11.u32 + 12112, ctx.r8.u8);
	// lfs f4,1080(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1080);
	ctx.f4.f64 = double(temp.f32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r7,12113(r11)
	PPC_STORE_U8(r11.u32 + 12113, ctx.r7.u8);
	// lvx128 v61,r30,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,1460(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1460);
	ctx.f2.f64 = double(temp.f32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r6,12144(r11)
	PPC_STORE_U8(r11.u32 + 12144, ctx.r6.u8);
	// lfs f0,1448(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1448);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r5,12145(r11)
	PPC_STORE_U8(r11.u32 + 12145, ctx.r5.u8);
	// lvx128 v60,r30,r4
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,1828(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1828);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r4,12176(r11)
	PPC_STORE_U8(r11.u32 + 12176, ctx.r4.u8);
	// lfs f10,1816(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 1816);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r3,12177(r11)
	PPC_STORE_U8(r11.u32 + 12177, ctx.r3.u8);
	// lvx128 v59,r30,r28
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r31,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,2196(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 2196);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// li r6,208
	ctx.r6.s64 = 208;
	// li r5,2448
	ctx.r5.s64 = 2448;
	// li r4,2816
	ctx.r4.s64 = 2816;
	// li r3,272
	ctx.r3.s64 = 272;
	// li r28,336
	r28.s64 = 336;
	// stb r8,12208(r11)
	PPC_STORE_U8(r11.u32 + 12208, ctx.r8.u8);
	// lfs f6,2184(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 2184);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// li r8,3184
	ctx.r8.s64 = 3184;
	// stb r7,12209(r11)
	PPC_STORE_U8(r11.u32 + 12209, ctx.r7.u8);
	// li r7,304
	ctx.r7.s64 = 304;
	// lvx128 v58,r30,r26
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r27,3920
	r27.s64 = 3920;
	// stvx128 v58,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r6,3552
	ctx.r6.s64 = 3552;
	// lfs f4,2564(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 2564);
	ctx.f4.f64 = double(temp.f32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r24,87(r1)
	r24.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r24,12240(r11)
	PPC_STORE_U8(r11.u32 + 12240, r24.u8);
	// li r26,368
	r26.s64 = 368;
	// lfs f2,2552(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 2552);
	ctx.f2.f64 = double(temp.f32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lbz r24,87(r1)
	r24.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r24,12241(r11)
	PPC_STORE_U8(r11.u32 + 12241, r24.u8);
	// li r25,4288
	r25.s64 = 4288;
	// lvx128 v57,r30,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2932(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 2932);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r5,12272(r11)
	PPC_STORE_U8(r11.u32 + 12272, ctx.r5.u8);
	// lfs f12,2920(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 2920);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,12273(r11)
	PPC_STORE_U8(r11.u32 + 12273, ctx.r9.u8);
	// lvx128 v56,r30,r4
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,3300(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 3300);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r5,12304(r11)
	PPC_STORE_U8(r11.u32 + 12304, ctx.r5.u8);
	// lfs f8,3288(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 3288);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r4,12305(r11)
	PPC_STORE_U8(r11.u32 + 12305, ctx.r4.u8);
	// lvx128 v55,r30,r8
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,3668(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 3668);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r3,12336(r11)
	PPC_STORE_U8(r11.u32 + 12336, ctx.r3.u8);
	// lfs f4,3656(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 3656);
	ctx.f4.f64 = double(temp.f32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,12337(r11)
	PPC_STORE_U8(r11.u32 + 12337, ctx.r9.u8);
	// lvx128 v54,r30,r6
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v54,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,4036(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4036);
	ctx.f2.f64 = double(temp.f32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,12368(r11)
	PPC_STORE_U8(r11.u32 + 12368, ctx.r8.u8);
	// lfs f0,4024(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4024);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r7,12369(r11)
	PPC_STORE_U8(r11.u32 + 12369, ctx.r7.u8);
	// lvx128 v53,r30,r27
	simde_mm_store_si128((simde__m128i*)v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v53,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,4404(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4404);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// li r5,400
	ctx.r5.s64 = 400;
	// li r4,4656
	ctx.r4.s64 = 4656;
	// li r9,432
	ctx.r9.s64 = 432;
	// li r8,5024
	ctx.r8.s64 = 5024;
	// li r7,464
	ctx.r7.s64 = 464;
	// li r28,528
	r28.s64 = 528;
	// li r27,6128
	r27.s64 = 6128;
	// li r26,560
	r26.s64 = 560;
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r6,12400(r11)
	PPC_STORE_U8(r11.u32 + 12400, ctx.r6.u8);
	// lfs f10,4392(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4392);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// li r6,5392
	ctx.r6.s64 = 5392;
	// stb r3,12401(r11)
	PPC_STORE_U8(r11.u32 + 12401, ctx.r3.u8);
	// lvx128 v52,r30,r25
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v52,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,496
	ctx.r5.s64 = 496;
	// lfs f8,4772(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4772);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lbz r25,87(r1)
	r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r25,12432(r11)
	PPC_STORE_U8(r11.u32 + 12432, r25.u8);
	// li r3,5760
	ctx.r3.s64 = 5760;
	// lfs f6,4760(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 4760);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r25,87(r1)
	r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r25,12433(r11)
	PPC_STORE_U8(r11.u32 + 12433, r25.u8);
	// lvx128 v51,r30,r4
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v51,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v51.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,5140(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 5140);
	ctx.f4.f64 = double(temp.f32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,12464(r11)
	PPC_STORE_U8(r11.u32 + 12464, ctx.r9.u8);
	// lfs f2,5128(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 5128);
	ctx.f2.f64 = double(temp.f32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r4,12465(r11)
	PPC_STORE_U8(r11.u32 + 12465, ctx.r4.u8);
	// lvx128 v50,r30,r8
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v50,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v50.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,5508(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 5508);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,12496(r11)
	PPC_STORE_U8(r11.u32 + 12496, ctx.r9.u8);
	// lfs f12,5496(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 5496);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,12497(r11)
	PPC_STORE_U8(r11.u32 + 12497, ctx.r8.u8);
	// lvx128 v49,r30,r6
	simde_mm_store_si128((simde__m128i*)v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v49,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v49.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,5876(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 5876);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r7,12528(r11)
	PPC_STORE_U8(r11.u32 + 12528, ctx.r7.u8);
	// lfs f8,5864(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 5864);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r6,12529(r11)
	PPC_STORE_U8(r11.u32 + 12529, ctx.r6.u8);
	// lvx128 v48,r30,r3
	simde_mm_store_si128((simde__m128i*)v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v48,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,6244(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 6244);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r5,12560(r11)
	PPC_STORE_U8(r11.u32 + 12560, ctx.r5.u8);
	// lfs f4,6232(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 6232);
	ctx.f4.f64 = double(temp.f32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r4,12561(r11)
	PPC_STORE_U8(r11.u32 + 12561, ctx.r4.u8);
	// lvx128 v47,r30,r27
	simde_mm_store_si128((simde__m128i*)v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v47,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v47.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,6496
	ctx.r3.s64 = 6496;
	// lfs f2,6612(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 6612);
	ctx.f2.f64 = double(temp.f32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// li r9,592
	ctx.r9.s64 = 592;
	// li r8,6864
	ctx.r8.s64 = 6864;
	// li r7,624
	ctx.r7.s64 = 624;
	// li r6,7232
	ctx.r6.s64 = 7232;
	// li r5,656
	ctx.r5.s64 = 656;
	// li r4,7600
	ctx.r4.s64 = 7600;
	// li r28,688
	r28.s64 = 688;
	// li r27,7968
	r27.s64 = 7968;
	// li r26,720
	r26.s64 = 720;
	// li r25,8336
	r25.s64 = 8336;
	// li r24,752
	r24.s64 = 752;
	// li r23,8704
	r23.s64 = 8704;
	// lbz r22,87(r1)
	r22.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r22,12592(r11)
	PPC_STORE_U8(r11.u32 + 12592, r22.u8);
	// lfs f0,6600(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 6600);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r22,87(r1)
	r22.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r22,12593(r11)
	PPC_STORE_U8(r11.u32 + 12593, r22.u8);
	// lvx128 v46,r30,r3
	simde_mm_store_si128((simde__m128i*)v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v46,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v46.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,6980(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 6980);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r3,12624(r11)
	PPC_STORE_U8(r11.u32 + 12624, ctx.r3.u8);
	// lfs f10,6968(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 6968);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,12625(r11)
	PPC_STORE_U8(r11.u32 + 12625, ctx.r9.u8);
	// lvx128 v45,r30,r8
	simde_mm_store_si128((simde__m128i*)v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v45,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v45.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,7348(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7348);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,12656(r11)
	PPC_STORE_U8(r11.u32 + 12656, ctx.r8.u8);
	// lfs f6,7336(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7336);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r7,12657(r11)
	PPC_STORE_U8(r11.u32 + 12657, ctx.r7.u8);
	// lvx128 v44,r30,r6
	simde_mm_store_si128((simde__m128i*)v44.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v44,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v44.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,7716(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7716);
	ctx.f4.f64 = double(temp.f32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r6,12688(r11)
	PPC_STORE_U8(r11.u32 + 12688, ctx.r6.u8);
	// lfs f2,7704(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 7704);
	ctx.f2.f64 = double(temp.f32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r5,12689(r11)
	PPC_STORE_U8(r11.u32 + 12689, ctx.r5.u8);
	// lvx128 v43,r30,r4
	simde_mm_store_si128((simde__m128i*)v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v43,r31,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v43.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,8084(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8084);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r4,12720(r11)
	PPC_STORE_U8(r11.u32 + 12720, ctx.r4.u8);
	// lfs f12,8072(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8072);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r3,12721(r11)
	PPC_STORE_U8(r11.u32 + 12721, ctx.r3.u8);
	// lvx128 v42,r30,r27
	simde_mm_store_si128((simde__m128i*)v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r27.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v42,r31,r26
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r26.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v42.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,8452(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8452);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,12752(r11)
	PPC_STORE_U8(r11.u32 + 12752, ctx.r9.u8);
	// lfs f8,8440(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8440);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// li r7,784
	ctx.r7.s64 = 784;
	// li r6,9072
	ctx.r6.s64 = 9072;
	// li r5,816
	ctx.r5.s64 = 816;
	// li r4,9440
	ctx.r4.s64 = 9440;
	// li r3,848
	ctx.r3.s64 = 848;
	// li r9,9808
	ctx.r9.s64 = 9808;
	// li r28,10176
	r28.s64 = 10176;
	// li r27,912
	r27.s64 = 912;
	// li r26,10544
	r26.s64 = 10544;
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,12753(r11)
	PPC_STORE_U8(r11.u32 + 12753, ctx.r8.u8);
	// lvx128 v41,r30,r25
	simde_mm_store_si128((simde__m128i*)v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v41,r31,r24
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r24.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v41.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,880
	ctx.r8.s64 = 880;
	// lfs f6,8820(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8820);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r25,87(r1)
	r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r25,12784(r11)
	PPC_STORE_U8(r11.u32 + 12784, r25.u8);
	// lfs f4,8808(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 8808);
	ctx.f4.f64 = double(temp.f32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r25,87(r1)
	r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r25,12785(r11)
	PPC_STORE_U8(r11.u32 + 12785, r25.u8);
	// lvx128 v40,r30,r23
	simde_mm_store_si128((simde__m128i*)v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r23.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v40,r31,r7
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v40.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f2,9188(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 9188);
	ctx.f2.f64 = double(temp.f32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r7,12816(r11)
	PPC_STORE_U8(r11.u32 + 12816, ctx.r7.u8);
	// lfs f0,9176(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 9176);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r7,12817(r11)
	PPC_STORE_U8(r11.u32 + 12817, ctx.r7.u8);
	// lvx128 v39,r30,r6
	simde_mm_store_si128((simde__m128i*)v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v39,r31,r5
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v39.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,9556(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 9556);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lbz r6,87(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r6,12848(r11)
	PPC_STORE_U8(r11.u32 + 12848, ctx.r6.u8);
	// lfs f10,9544(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 9544);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r5,12849(r11)
	PPC_STORE_U8(r11.u32 + 12849, ctx.r5.u8);
	// lvx128 v38,r30,r4
	simde_mm_store_si128((simde__m128i*)v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v38,r31,r3
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v38.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,9924(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 9924);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lbz r4,87(r1)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r4,12880(r11)
	PPC_STORE_U8(r11.u32 + 12880, ctx.r4.u8);
	// lfs f6,9912(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 9912);
	ctx.f6.f64 = double(temp.f32);
	// fctidz f5,f6
	ctx.f5.s64 = (ctx.f6.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f5,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f5.u64);
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r3,12881(r11)
	PPC_STORE_U8(r11.u32 + 12881, ctx.r3.u8);
	// lvx128 v37,r30,r9
	simde_mm_store_si128((simde__m128i*)v37.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v37,r31,r8
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v37.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f4,10292(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 10292);
	ctx.f4.f64 = double(temp.f32);
	// fctidz f3,f4
	ctx.f3.s64 = (ctx.f4.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f4.f64));
	// stfd f3,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f3.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,12912(r11)
	PPC_STORE_U8(r11.u32 + 12912, ctx.r9.u8);
	// lfs f2,10280(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 10280);
	ctx.f2.f64 = double(temp.f32);
	// fctidz f1,f2
	ctx.f1.s64 = (ctx.f2.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f1,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f1.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,12913(r11)
	PPC_STORE_U8(r11.u32 + 12913, ctx.r8.u8);
	// lvx128 v36,r30,r28
	simde_mm_store_si128((simde__m128i*)v36.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r28.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v36,r31,r27
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r27.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v36.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,10660(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 10660);
	f0.f64 = double(temp.f32);
	// fctidz f13,f0
	ctx.f13.s64 = (f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lbz r7,87(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r7,12944(r11)
	PPC_STORE_U8(r11.u32 + 12944, ctx.r7.u8);
	// lfs f12,10648(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 10648);
	ctx.f12.f64 = double(temp.f32);
	// fctidz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// li r6,944
	ctx.r6.s64 = 944;
	// li r5,10912
	ctx.r5.s64 = 10912;
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lbz r3,87(r1)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r3,12945(r11)
	PPC_STORE_U8(r11.u32 + 12945, ctx.r3.u8);
	// lvx128 v35,r30,r26
	simde_mm_store_si128((simde__m128i*)v35.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + r26.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v35,r31,r6
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v35.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,11028(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 11028);
	ctx.f10.f64 = double(temp.f32);
	// fctidz f9,f10
	ctx.f9.s64 = (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lbz r9,87(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r9,12976(r11)
	PPC_STORE_U8(r11.u32 + 12976, ctx.r9.u8);
	// lfs f8,11016(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 11016);
	ctx.f8.f64 = double(temp.f32);
	// fctidz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lbz r8,87(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 87);
	// stb r8,12977(r11)
	PPC_STORE_U8(r11.u32 + 12977, ctx.r8.u8);
	// lvx128 v34,r30,r5
	simde_mm_store_si128((simde__m128i*)v34.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v34,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v34.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,-27856(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8225589C;
	sub_8238EC00(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lwz r11,-12648(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12648);
	// subf r6,r11,r3
	ctx.r6.s64 = ctx.r3.s64 - r11.s64;
	// divw r5,r6,r29
	ctx.r5.s32 = ctx.r6.s32 / r29.s32;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// stb r11,1043(r31)
	PPC_STORE_U8(r31.u32 + 1043, r11.u8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,205
	cr6.compare<uint32_t>(r11.u32, 205, xer);
	// bne cr6,0x822558c8
	if (!cr6.eq) goto loc_822558C8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x822558cc
	goto loc_822558CC;
loc_822558C8:
	// lbz r11,1042(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1042);
loc_822558CC:
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x822558e0
	if (!cr6.eq) goto loc_822558E0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x822558fc
	goto loc_822558FC;
loc_822558E0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822558f4
	if (!cr6.eq) goto loc_822558F4;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stb r11,1042(r31)
	PPC_STORE_U8(r31.u32 + 1042, r11.u8);
	// b 0x822558fc
	goto loc_822558FC;
loc_822558F4:
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,1042(r31)
	PPC_STORE_U8(r31.u32 + 1042, r11.u8);
loc_822558FC:
	// lbz r10,1043(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 1043);
	// lwz r11,160(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 160);
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x82255914
	if (!cr6.eq) goto loc_82255914;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x82255930
	goto loc_82255930;
loc_82255914:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82255928
	if (!cr6.eq) goto loc_82255928;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stb r11,1042(r31)
	PPC_STORE_U8(r31.u32 + 1042, r11.u8);
	// b 0x82255930
	goto loc_82255930;
loc_82255928:
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stb r11,1042(r31)
	PPC_STORE_U8(r31.u32 + 1042, r11.u8);
loc_82255930:
	// lbz r11,11969(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 11969);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lbz r9,11968(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 11968);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r8,-14960
	ctx.r4.s64 = ctx.r8.s64 + -14960;
	// stb r11,1041(r31)
	PPC_STORE_U8(r31.u32 + 1041, r11.u8);
	// stb r9,1040(r31)
	PPC_STORE_U8(r31.u32 + 1040, ctx.r9.u8);
	// lwz r3,2832(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2832);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r6,8(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82255964;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r3,-32115
	ctx.r3.s64 = -2104688640;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,-15456
	ctx.r4.s64 = r11.s64 + -15456;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r3,-12440(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + -12440);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8225598C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822533b8
	ctx.lr = 0x82255994;
	sub_822533B8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_822551E0) {
	__imp__sub_822551E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225599C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225599C) {
	__imp__sub_8225599C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822559A0) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826947a0
	ctx.lr = 0x822559C0;
	sub_826947A0(ctx, base);
	// bl 0x823dd7f0
	ctx.lr = 0x822559C4;
	sub_823DD7F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r4,r9,1
	ctx.r4.u64 = ctx.r9.u64 ^ 1;
	// bl 0x82253298
	ctx.lr = 0x822559DC;
	sub_82253298(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822559A0) {
	__imp__sub_822559A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822559F0) {
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
	ctx.lr = 0x822559F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lbz r11,1043(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1043);
	// cmplwi cr6,r11,205
	cr6.compare<uint32_t>(r11.u32, 205, xer);
	// bne cr6,0x82255a18
	if (!cr6.eq) goto loc_82255A18;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x82255a1c
	goto loc_82255A1C;
loc_82255A18:
	// lbz r29,1042(r31)
	r29.u64 = PPC_LOAD_U8(r31.u32 + 1042);
loc_82255A1C:
	// li r5,6
	ctx.r5.s64 = 6;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226b338
	ctx.lr = 0x82255A2C;
	sub_8226B338(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255a8c
	if (cr6.eq) goto loc_82255A8C;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82618f90
	ctx.lr = 0x82255A48;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255a8c
	if (cr6.eq) goto loc_82255A8C;
	// li r5,2
	ctx.r5.s64 = 2;
	// lbz r4,1040(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1040);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82250f50
	ctx.lr = 0x82255A64;
	sub_82250F50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255a8c
	if (cr6.eq) goto loc_82255A8C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lbz r4,1041(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 1041);
	// bl 0x82618f70
	ctx.lr = 0x82255A7C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82255a90
	if (!cr6.eq) goto loc_82255A90;
loc_82255A8C:
	// li r11,0
	r11.s64 = 0;
loc_82255A90:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82255ad4
	if (cr6.eq) goto loc_82255AD4;
	// li r30,0
	r30.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82255ad4
	if (!cr6.gt) goto loc_82255AD4;
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
loc_82255AAC:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255ad4
	if (cr6.eq) goto loc_82255AD4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82253820
	ctx.lr = 0x82255AC4;
	sub_82253820(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x82255aac
	if (cr6.lt) goto loc_82255AAC;
loc_82255AD4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822559F0) {
	__imp__sub_822559F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82255ADC) {
	__imp__sub_82255ADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255AE0) {
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
	ctx.lr = 0x82255AE8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// li r5,6
	ctx.r5.s64 = 6;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82275750
	ctx.lr = 0x82255B0C;
	sub_82275750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255b6c
	if (cr6.eq) goto loc_82255B6C;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82618f80
	ctx.lr = 0x82255B28;
	sub_82618F80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255b6c
	if (cr6.eq) goto loc_82255B6C;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r31,1040
	ctx.r4.s64 = r31.s64 + 1040;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82250ff8
	ctx.lr = 0x82255B44;
	sub_82250FF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255b6c
	if (cr6.eq) goto loc_82255B6C;
	// addi r4,r31,1041
	ctx.r4.s64 = r31.s64 + 1041;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82618f10
	ctx.lr = 0x82255B5C;
	sub_82618F10(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82255b70
	if (!cr6.eq) goto loc_82255B70;
loc_82255B6C:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_82255B70:
	// lis r10,-32120
	ctx.r10.s64 = -2105016320;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// lwz r3,-27856(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82255B80;
	sub_8238EC00(ctx, base);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r8,80
	ctx.r8.s64 = 80;
	// lwz r11,-12648(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12648);
	// subf r7,r11,r3
	ctx.r7.s64 = ctx.r3.s64 - r11.s64;
	// divw r6,r7,r8
	ctx.r6.s32 = ctx.r7.s32 / ctx.r8.s32;
	// clrlwi r11,r6,24
	r11.u64 = ctx.r6.u32 & 0xFF;
	// stb r11,1043(r31)
	PPC_STORE_U8(r31.u32 + 1043, r11.u8);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplwi cr6,r11,205
	cr6.compare<uint32_t>(r11.u32, 205, xer);
	// bne cr6,0x82255bb0
	if (!cr6.eq) goto loc_82255BB0;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// b 0x82255bb4
	goto loc_82255BB4;
loc_82255BB0:
	// lbz r11,1042(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1042);
loc_82255BB4:
	// cmplwi cr6,r10,205
	cr6.compare<uint32_t>(ctx.r10.u32, 205, xer);
	// bne cr6,0x82255bc4
	if (!cr6.eq) goto loc_82255BC4;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// b 0x82255be0
	goto loc_82255BE0;
loc_82255BC4:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82255bd8
	if (!cr6.eq) goto loc_82255BD8;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// stb r11,1042(r31)
	PPC_STORE_U8(r31.u32 + 1042, r11.u8);
	// b 0x82255be0
	goto loc_82255BE0;
loc_82255BD8:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// stb r11,1042(r31)
	PPC_STORE_U8(r31.u32 + 1042, r11.u8);
loc_82255BE0:
	// lbz r11,1043(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 1043);
	// lwz r29,80(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,205
	cr6.compare<uint32_t>(r11.u32, 205, xer);
	// bne cr6,0x82255bf8
	if (!cr6.eq) goto loc_82255BF8;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// b 0x82255c10
	goto loc_82255C10;
loc_82255BF8:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r29,1042(r31)
	PPC_STORE_U8(r31.u32 + 1042, r29.u8);
	// bne cr6,0x82255c0c
	if (!cr6.eq) goto loc_82255C0C;
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// b 0x82255c10
	goto loc_82255C10;
loc_82255C0C:
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
loc_82255C10:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255c54
	if (cr6.eq) goto loc_82255C54;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82255c54
	if (!cr6.gt) goto loc_82255C54;
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
loc_82255C28:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255c54
	if (cr6.eq) goto loc_82255C54;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82253910
	ctx.lr = 0x82255C40;
	sub_82253910(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r31,r31,32
	r31.s64 = r31.s64 + 32;
	// cmpw cr6,r30,r29
	cr6.compare<int32_t>(r30.s32, r29.s32, xer);
	// blt cr6,0x82255c28
	if (cr6.lt) goto loc_82255C28;
loc_82255C54:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82255AE0) {
	__imp__sub_82255AE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255C60) {
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
	// bl 0x82253dc8
	ctx.lr = 0x82255C80;
	sub_82253DC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82255c98
	if (cr6.eq) goto loc_82255C98;
	// bl 0x82130588
	ctx.lr = 0x82255C94;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82255C98:
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

PPC_WEAK_FUNC(sub_82255C60) {
	__imp__sub_82255C60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255CB0) {
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
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,16040
	ctx.r4.s64 = r11.s64 + 16040;
	// addi r3,r10,-15420
	ctx.r3.s64 = ctx.r10.s64 + -15420;
	// bl 0x82554798
	ctx.lr = 0x82255CD0;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,4896
	ctx.r4.s64 = ctx.r9.s64 + 4896;
	// addi r3,r8,-15448
	ctx.r3.s64 = ctx.r8.s64 + -15448;
	// bl 0x82554798
	ctx.lr = 0x82255CE4;
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

PPC_WEAK_FUNC(sub_82255CB0) {
	__imp__sub_82255CB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255CF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82255CF4) {
	__imp__sub_82255CF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255CF8) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x82255D24;
	sub_821FD980(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r31,92
	ctx.r3.s64 = r31.s64 + 92;
	// addi r4,r10,32684
	ctx.r4.s64 = ctx.r10.s64 + 32684;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// stw r30,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r30.u32);
	// bl 0x823dc018
	ctx.lr = 0x82255D40;
	sub_823DC018(ctx, base);
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
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

PPC_WEAK_FUNC(sub_82255CF8) {
	__imp__sub_82255CF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255D60) {
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
	// bl 0x82387a18
	ctx.lr = 0x82255D70;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82255d8c
	if (!cr6.eq) goto loc_82255D8C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-15384
	ctx.r3.s64 = r11.s64 + -15384;
	// bl 0x82255cf8
	ctx.lr = 0x82255D8C;
	sub_82255CF8(ctx, base);
loc_82255D8C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82255D60) {
	__imp__sub_82255D60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82255D9C) {
	__imp__sub_82255D9C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255DA0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r9,r4,104
	ctx.r9.s64 = ctx.r4.s64 + 104;
	// addi r11,r3,40
	r11.s64 = ctx.r3.s64 + 40;
	// subf r8,r3,r4
	ctx.r8.s64 = ctx.r4.s64 - ctx.r3.s64;
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// lwz r6,4(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// lwz r7,12(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// stw r7,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r7.u32);
	// lwz r6,16(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r6,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r6.u32);
	// lwz r5,20(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 20);
	// stw r5,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r5.u32);
	// lwz r7,24(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 24);
	// stw r7,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r7.u32);
	// lwz r6,28(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 28);
	// stw r6,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r6.u32);
	// lwz r5,32(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// stw r5,32(r3)
	PPC_STORE_U32(ctx.r3.u32 + 32, ctx.r5.u32);
	// lwz r7,36(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// stw r7,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, ctx.r7.u32);
	// lwz r6,100(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 100);
	// stw r6,100(r3)
	PPC_STORE_U32(ctx.r3.u32 + 100, ctx.r6.u32);
	// lwz r5,168(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 168);
	// stw r5,168(r3)
	PPC_STORE_U32(ctx.r3.u32 + 168, ctx.r5.u32);
	// lwz r7,172(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 172);
	// stw r7,172(r3)
	PPC_STORE_U32(ctx.r3.u32 + 172, ctx.r7.u32);
	// lwz r6,176(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 176);
	// stw r6,176(r3)
	PPC_STORE_U32(ctx.r3.u32 + 176, ctx.r6.u32);
	// lwz r5,180(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 180);
	// stw r5,180(r3)
	PPC_STORE_U32(ctx.r3.u32 + 180, ctx.r5.u32);
	// lwz r7,184(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 184);
	// stw r7,184(r3)
	PPC_STORE_U32(ctx.r3.u32 + 184, ctx.r7.u32);
	// lwz r6,188(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 188);
	// stw r6,188(r3)
	PPC_STORE_U32(ctx.r3.u32 + 188, ctx.r6.u32);
loc_82255E38:
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r6,64(r11)
	PPC_STORE_U32(r11.u32 + 64, ctx.r6.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x82255e38
	if (!cr0.eq) goto loc_82255E38;
	// lwz r11,164(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 164);
	// stw r11,164(r3)
	PPC_STORE_U32(ctx.r3.u32 + 164, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82255DA0) {
	__imp__sub_82255DA0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82255E64) {
	__imp__sub_82255E64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255E68) {
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
	ctx.lr = 0x82255E70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,16
	r28.s64 = 16;
	// addi r29,r31,8
	r29.s64 = r31.s64 + 8;
	// subf r27,r31,r30
	r27.s64 = r30.s64 - r31.s64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
loc_82255E98:
	// add r4,r27,r29
	ctx.r4.u64 = r27.u64 + r29.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82255da0
	ctx.lr = 0x82255EA4;
	sub_82255DA0(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// bne 0x82255e98
	if (!cr0.eq) goto loc_82255E98;
	// lwz r11,3080(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3080);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,3080(r31)
	PPC_STORE_U32(r31.u32 + 3080, r11.u32);
	// lwz r10,3084(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 3084);
	// stw r10,3084(r31)
	PPC_STORE_U32(r31.u32 + 3084, ctx.r10.u32);
	// lwz r9,3088(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 3088);
	// stw r9,3088(r31)
	PPC_STORE_U32(r31.u32 + 3088, ctx.r9.u32);
	// lwz r8,3092(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 3092);
	// stw r8,3092(r31)
	PPC_STORE_U32(r31.u32 + 3092, ctx.r8.u32);
	// lwz r7,3096(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 3096);
	// stw r7,3096(r31)
	PPC_STORE_U32(r31.u32 + 3096, ctx.r7.u32);
	// lwz r6,3100(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 3100);
	// stw r6,3100(r31)
	PPC_STORE_U32(r31.u32 + 3100, ctx.r6.u32);
	// lwz r5,3104(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 3104);
	// stw r5,3104(r31)
	PPC_STORE_U32(r31.u32 + 3104, ctx.r5.u32);
	// lwz r4,3108(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 3108);
	// stw r4,3108(r31)
	PPC_STORE_U32(r31.u32 + 3108, ctx.r4.u32);
	// lwz r11,3116(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3116);
	// stw r11,3116(r31)
	PPC_STORE_U32(r31.u32 + 3116, r11.u32);
	// lwz r10,3120(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 3120);
	// stw r10,3120(r31)
	PPC_STORE_U32(r31.u32 + 3120, ctx.r10.u32);
	// lwz r9,3124(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 3124);
	// stw r9,3124(r31)
	PPC_STORE_U32(r31.u32 + 3124, ctx.r9.u32);
	// lwz r8,3128(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 3128);
	// stw r8,3128(r31)
	PPC_STORE_U32(r31.u32 + 3128, ctx.r8.u32);
	// lwz r7,3132(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 3132);
	// stw r7,3132(r31)
	PPC_STORE_U32(r31.u32 + 3132, ctx.r7.u32);
	// lwz r6,3136(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 3136);
	// stw r6,3136(r31)
	PPC_STORE_U32(r31.u32 + 3136, ctx.r6.u32);
	// lwz r5,3140(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 3140);
	// stw r5,3140(r31)
	PPC_STORE_U32(r31.u32 + 3140, ctx.r5.u32);
	// lwz r4,3144(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 3144);
	// stw r4,3144(r31)
	PPC_STORE_U32(r31.u32 + 3144, ctx.r4.u32);
	// lwz r11,3148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 3148);
	// stw r11,3148(r31)
	PPC_STORE_U32(r31.u32 + 3148, r11.u32);
	// lwz r10,3152(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 3152);
	// stw r10,3152(r31)
	PPC_STORE_U32(r31.u32 + 3152, ctx.r10.u32);
	// lwz r9,3156(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 3156);
	// stw r9,3156(r31)
	PPC_STORE_U32(r31.u32 + 3156, ctx.r9.u32);
	// lwz r8,3160(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 3160);
	// stw r8,3160(r31)
	PPC_STORE_U32(r31.u32 + 3160, ctx.r8.u32);
	// lwz r7,3168(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 3168);
	// stw r7,3168(r31)
	PPC_STORE_U32(r31.u32 + 3168, ctx.r7.u32);
	// lwz r6,3172(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 3172);
	// stw r6,3172(r31)
	PPC_STORE_U32(r31.u32 + 3172, ctx.r6.u32);
	// lwz r5,3176(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 3176);
	// stw r5,3176(r31)
	PPC_STORE_U32(r31.u32 + 3176, ctx.r5.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82255E68) {
	__imp__sub_82255E68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82255F74) {
	__imp__sub_82255F74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82255F78) {
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
	ctx.lr = 0x82255F80;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82267860
	ctx.lr = 0x82255F90;
	sub_82267860(ctx, base);
	// lis r29,-32115
	r29.s64 = -2104688640;
	// li r11,0
	r11.s64 = 0;
	// li r10,100
	ctx.r10.s64 = 100;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stb r11,3774(r31)
	PPC_STORE_U8(r31.u32 + 3774, r11.u8);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stb r11,3773(r31)
	PPC_STORE_U8(r31.u32 + 3773, r11.u8);
	// stb r11,3775(r31)
	PPC_STORE_U8(r31.u32 + 3775, r11.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r10,3756(r31)
	PPC_STORE_U32(r31.u32 + 3756, ctx.r10.u32);
	// addi r28,r8,-15032
	r28.s64 = ctx.r8.s64 + -15032;
	// stw r9,3760(r31)
	PPC_STORE_U32(r31.u32 + 3760, ctx.r9.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r31,-12440(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r7
	r30.u64 = ctx.r7.u64;
	// lwz r6,76(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 76);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82255FE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r4,r5,-15040
	ctx.r4.s64 = ctx.r5.s64 + -15040;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82256000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,-12440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82256020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82255F78) {
	__imp__sub_82255F78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256028) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,3748(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3748);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256028) {
	__imp__sub_82256028(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256030) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,3748(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3748);
	// lwz r10,3768(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3768);
	// subf r3,r10,r11
	ctx.r3.s64 = r11.s64 - ctx.r10.s64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256030) {
	__imp__sub_82256030(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256040) {
	PPC_FUNC_PROLOGUE();
	// b 0x82255f78
	sub_82255F78(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82256040) {
	__imp__sub_82256040(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256044) {
	__imp__sub_82256044(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256048) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,-5128(r11)
	PPC_STORE_U32(r11.u32 + -5128, ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256048) {
	__imp__sub_82256048(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256054) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256054) {
	__imp__sub_82256054(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256058) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5128(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5128);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256058) {
	__imp__sub_82256058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256064) {
	__imp__sub_82256064(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256068) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-5128(r10)
	PPC_STORE_U32(ctx.r10.u32 + -5128, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256068) {
	__imp__sub_82256068(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256078) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82256088
	if (cr6.eq) goto loc_82256088;
	// lbz r3,3764(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3764);
	// blr 
	return;
loc_82256088:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256078) {
	__imp__sub_82256078(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256090) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r11,-5124
	ctx.r3.s64 = r11.s64 + -5124;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f0,32(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x821c07c0
	ctx.lr = 0x822560D0;
	sub_821C07C0(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82256118
	if (cr6.eq) goto loc_82256118;
	// lwz r11,3128(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3128);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822560ec
	if (!cr6.eq) goto loc_822560EC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8225611c
	goto loc_8225611C;
loc_822560EC:
	// lwz r3,-3624(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// bl 0x8226b330
	ctx.lr = 0x822560F4;
	sub_8226B330(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x82256104;
	sub_82293F60(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + f0.f64));
	// li r3,1
	ctx.r3.s64 = 1;
	// fcmpu cr6,f31,f13
	cr6.compare(f31.f64, ctx.f13.f64);
	// bgt cr6,0x8225611c
	if (cr6.gt) goto loc_8225611C;
loc_82256118:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8225611C:
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

PPC_WEAK_FUNC(sub_82256090) {
	__imp__sub_82256090(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256138) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82256148
	if (cr6.eq) goto loc_82256148;
	// lbz r3,3773(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3773);
	// blr 
	return;
loc_82256148:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256138) {
	__imp__sub_82256138(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256150) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82256160
	if (cr6.eq) goto loc_82256160;
	// lwz r3,3752(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3752);
	// blr 
	return;
loc_82256160:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256150) {
	__imp__sub_82256150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256168) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82256178
	if (cr6.eq) goto loc_82256178;
	// lwz r3,3096(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3096);
	// blr 
	return;
loc_82256178:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256168) {
	__imp__sub_82256168(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256180) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// b 0x82255e68
	sub_82255E68(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82256180) {
	__imp__sub_82256180(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256198) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256198) {
	__imp__sub_82256198(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225619C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225619C) {
	__imp__sub_8225619C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822561A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822561b8
	if (cr6.eq) goto loc_822561B8;
	// mulli r11,r4,272
	r11.s64 = ctx.r4.s64 * 272;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,3200
	ctx.r3.s64 = r11.s64 + 3200;
	// blr 
	return;
loc_822561B8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822561A0) {
	__imp__sub_822561A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822561C0) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,3744(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3744);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822561C0) {
	__imp__sub_822561C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822561C8) {
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
	ctx.lr = 0x822561D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x8225620c
	if (!cr6.gt) goto loc_8225620C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_822561E8:
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
	ctx.lr = 0x82256200;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// bne 0x822561e8
	if (!cr0.eq) goto loc_822561E8;
loc_8225620C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x82256214;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822561C8) {
	__imp__sub_822561C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225621C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225621C) {
	__imp__sub_8225621C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256220) {
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
	// lbz r11,3764(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 3764);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82256300
	if (cr6.eq) goto loc_82256300;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12640(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12640);
	// lbz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82256264
	if (cr6.eq) goto loc_82256264;
	// lbz r11,10(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82256268
	if (cr6.eq) goto loc_82256268;
loc_82256264:
	// li r11,0
	r11.s64 = 0;
loc_82256268:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82256300
	if (!cr6.eq) goto loc_82256300;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r11,18444
	ctx.r10.s64 = r11.s64 + 18444;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822562cc
	if (!cr6.eq) goto loc_822562CC;
	// bl 0x82387a18
	ctx.lr = 0x8225628C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822562cc
	if (!cr6.eq) goto loc_822562CC;
	// lwz r11,3748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3748);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x822562bc
	if (!cr6.lt) goto loc_822562BC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823bb408
	ctx.lr = 0x822562B0;
	sub_823BB408(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822562cc
	if (!cr6.eq) goto loc_822562CC;
loc_822562BC:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f0,8(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	f0.f64 = double(temp.f32);
	// b 0x822562d8
	goto loc_822562D8;
loc_822562CC:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// addi r9,r11,29952
	ctx.r9.s64 = r11.s64 + 29952;
	// lfs f0,100(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 100);
	f0.f64 = double(temp.f32);
loc_822562D8:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r11,3748(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3748);
	// lfs f13,11364(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11364);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	f0.f64 = double(float(f0.f64 * ctx.f13.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// li r12,3768
	r12.s64 = 3768;
	// stfiwx f13,r31,r12
	PPC_STORE_U32(r31.u32 + r12.u32, ctx.f13.u32);
	// lwz r10,3768(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 3768);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,3748(r31)
	PPC_STORE_U32(r31.u32 + 3748, r11.u32);
loc_82256300:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256220) {
	__imp__sub_82256220(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256314) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256314) {
	__imp__sub_82256314(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256318) {
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
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225634c
	if (cr6.eq) goto loc_8225634C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-14988
	ctx.r4.s64 = r11.s64 + -14988;
	// b 0x82256354
	goto loc_82256354;
loc_8225634C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-14992
	ctx.r4.s64 = r11.s64 + -14992;
loc_82256354:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-15016
	ctx.r3.s64 = r11.s64 + -15016;
	// bl 0x82130000
	ctx.lr = 0x82256360;
	sub_82130000(ctx, base);
	// stb r31,3764(r30)
	PPC_STORE_U8(r30.u32 + 3764, r31.u8);
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

PPC_WEAK_FUNC(sub_82256318) {
	__imp__sub_82256318(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225637C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225637C) {
	__imp__sub_8225637C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256380) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-5128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5128);
	// cntlzw r9,r11
	ctx.r9.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256380) {
	__imp__sub_82256380(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822563A0) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8225641c
	if (cr6.eq) goto loc_8225641C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,11364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 11364);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fmuls f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 * f0.f64));
	// lfs f13,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// lfs f13,14884(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14884);
	ctx.f13.f64 = double(temp.f32);
	// bge cr6,0x822563f8
	if (!cr6.lt) goto loc_822563F8;
	// fsubs f0,f0,f13
	f0.f64 = double(float(f0.f64 - ctx.f13.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x82256408
	goto loc_82256408;
loc_822563F8:
	// fadds f0,f0,f13
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + ctx.f13.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r31,84(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_82256408:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,-14984
	ctx.r3.s64 = r11.s64 + -14984;
	// bl 0x82130000
	ctx.lr = 0x82256418;
	sub_82130000(ctx, base);
	// stw r31,3748(r30)
	PPC_STORE_U32(r30.u32 + 3748, r31.u32);
loc_8225641C:
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

PPC_WEAK_FUNC(sub_822563A0) {
	__imp__sub_822563A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256434) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256434) {
	__imp__sub_82256434(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256438) {
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
	// lis r11,-32120
	r11.s64 = -2105016320;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82256458;
	sub_8238EC00(ctx, base);
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x82256484
	if (cr6.lt) goto loc_82256484;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82256484:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-14944
	ctx.r3.s64 = r11.s64 + -14944;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256438) {
	__imp__sub_82256438(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822564A0) {
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
	ctx.lr = 0x822564A8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225653c
	if (cr6.eq) goto loc_8225653C;
	// lwz r11,3744(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3744);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225653c
	if (cr6.eq) goto loc_8225653C;
	// lhz r11,8(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 8);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82256514
	if (cr6.eq) goto loc_82256514;
	// li r31,0
	r31.s64 = 0;
loc_822564E0:
	// lwz r11,3744(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3744);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// add r3,r11,r31
	ctx.r3.u64 = r11.u64 + r31.u64;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822564FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,3744(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 3744);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// lhz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + 8);
	// cmpw cr6,r30,r7
	cr6.compare<int32_t>(r30.s32, ctx.r7.s32, xer);
	// blt cr6,0x822564e0
	if (cr6.lt) goto loc_822564E0;
loc_82256514:
	// lwz r3,3744(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 3744);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82256534
	if (cr6.eq) goto loc_82256534;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82256534;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82256534:
	// li r11,0
	r11.s64 = 0;
	// stw r11,3744(r29)
	PPC_STORE_U32(r29.u32 + 3744, r11.u32);
loc_8225653C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822564A0) {
	__imp__sub_822564A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256544) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256544) {
	__imp__sub_82256544(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256548) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82256550;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r31,8
	ctx.r3.s64 = r31.s64 + 8;
	// addi r10,r11,-15020
	ctx.r10.s64 = r11.s64 + -15020;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82250310
	ctx.lr = 0x8225656C;
	sub_82250310(ctx, base);
	// addi r29,r31,3200
	r29.s64 = r31.s64 + 3200;
	// li r30,1
	r30.s64 = 1;
loc_82256574:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82264580
	ctx.lr = 0x8225657C;
	sub_82264580(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r29,r29,272
	r29.s64 = r29.s64 + 272;
	// bge 0x82256574
	if (!cr0.lt) goto loc_82256574;
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,3744(r31)
	PPC_STORE_U32(r31.u32 + 3744, r11.u32);
	// stw r11,3748(r31)
	PPC_STORE_U32(r31.u32 + 3748, r11.u32);
	// stw r11,3752(r31)
	PPC_STORE_U32(r31.u32 + 3752, r11.u32);
	// stw r11,3756(r31)
	PPC_STORE_U32(r31.u32 + 3756, r11.u32);
	// stw r10,3760(r31)
	PPC_STORE_U32(r31.u32 + 3760, ctx.r10.u32);
	// stb r11,3764(r31)
	PPC_STORE_U8(r31.u32 + 3764, r11.u8);
	// stw r11,3768(r31)
	PPC_STORE_U32(r31.u32 + 3768, r11.u32);
	// stb r9,3772(r31)
	PPC_STORE_U8(r31.u32 + 3772, ctx.r9.u8);
	// stb r11,3773(r31)
	PPC_STORE_U8(r31.u32 + 3773, r11.u8);
	// stb r11,3774(r31)
	PPC_STORE_U8(r31.u32 + 3774, r11.u8);
	// stb r11,3775(r31)
	PPC_STORE_U8(r31.u32 + 3775, r11.u8);
	// bl 0x82263b18
	ctx.lr = 0x822565C4;
	sub_82263B18(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82256548) {
	__imp__sub_82256548(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822565D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822565D4) {
	__imp__sub_822565D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822565D8) {
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
	// addi r10,r11,-15020
	ctx.r10.s64 = r11.s64 + -15020;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x82255f78
	ctx.lr = 0x82256604;
	sub_82255F78(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82263c18
	ctx.lr = 0x8225660C;
	sub_82263C18(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821d2028
	ctx.lr = 0x82256614;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225662c
	if (cr6.eq) goto loc_8225662C;
	// bl 0x82130588
	ctx.lr = 0x82256628;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8225662C:
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

PPC_WEAK_FUNC(sub_822565D8) {
	__imp__sub_822565D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256644) {
	__imp__sub_82256644(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256648) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82255f78
	sub_82255F78(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82256648) {
	__imp__sub_82256648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256654) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256654) {
	__imp__sub_82256654(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256658) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,-5128(r10)
	PPC_STORE_U32(ctx.r10.u32 + -5128, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256658) {
	__imp__sub_82256658(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225666C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225666C) {
	__imp__sub_8225666C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256670) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-5128(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5128);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256670) {
	__imp__sub_82256670(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256684) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256684) {
	__imp__sub_82256684(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256688) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822566b8
	if (cr6.eq) goto loc_822566B8;
	// lwz r3,3092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 3092);
	// bl 0x8238eab8
	ctx.lr = 0x822566B4;
	sub_8238EAB8(ctx, base);
	// b 0x822566bc
	goto loc_822566BC;
loc_822566B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822566BC:
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

PPC_WEAK_FUNC(sub_82256688) {
	__imp__sub_82256688(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822566DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822566DC) {
	__imp__sub_822566DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822566E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// b 0x82255e68
	sub_82255E68(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_822566E0) {
	__imp__sub_822566E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256704) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256704) {
	__imp__sub_82256704(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256708) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// addi r4,r11,8
	ctx.r4.s64 = r11.s64 + 8;
	// b 0x82255e68
	sub_82255E68(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82256708) {
	__imp__sub_82256708(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225671C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225671C) {
	__imp__sub_8225671C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256720) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8225674c
	if (cr6.eq) goto loc_8225674C;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mulli r11,r11,272
	r11.s64 = r11.s64 * 272;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r11,3200
	r11.s64 = r11.s64 + 3200;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r11.u32);
	// blr 
	return;
loc_8225674C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256720) {
	__imp__sub_82256720(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225675C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225675C) {
	__imp__sub_8225675C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256760) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822564a0
	sub_822564A0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82256760) {
	__imp__sub_82256760(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225676C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225676C) {
	__imp__sub_8225676C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256770) {
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
	// clrlwi r4,r11,24
	ctx.r4.u64 = r11.u32 & 0xFF;
	// b 0x82256318
	sub_82256318(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82256770) {
	__imp__sub_82256770(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256798) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256798) {
	__imp__sub_82256798(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225679C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225679C) {
	__imp__sub_8225679C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822567A0) {
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
	// beq cr6,0x822567c4
	if (cr6.eq) goto loc_822567C4;
	// lbz r11,3764(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 3764);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_822567C4:
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

PPC_WEAK_FUNC(sub_822567A0) {
	__imp__sub_822567A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822567D8) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82256814
	if (cr6.eq) goto loc_82256814;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-14984
	ctx.r3.s64 = r11.s64 + -14984;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82130000
	ctx.lr = 0x82256810;
	sub_82130000(ctx, base);
	// stw r30,3748(r31)
	PPC_STORE_U32(r31.u32 + 3748, r30.u32);
loc_82256814:
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

PPC_WEAK_FUNC(sub_822567D8) {
	__imp__sub_822567D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225682C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225682C) {
	__imp__sub_8225682C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256830) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822563a0
	sub_822563A0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82256830) {
	__imp__sub_82256830(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256840) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,3748(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3748);
	// stw r8,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256840) {
	__imp__sub_82256840(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256858) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,-13028(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13028);
	f0.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f12,12196(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12196);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,3748(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3748);
	// lfs f11,14884(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,3768(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3768);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// fmuls f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// fsel f6,f9,f9,f0
	ctx.f6.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f0.f64;
	// fsel f5,f9,f9,f0
	ctx.f5.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : f0.f64;
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// fsubs f3,f6,f13
	ctx.f3.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fsel f2,f3,f13,f5
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? ctx.f13.f64 : ctx.f5.f64;
	// fmuls f1,f2,f11
	ctx.f1.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// fmuls f0,f1,f4
	f0.f64 = double(float(ctx.f1.f64 * ctx.f4.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256858) {
	__imp__sub_82256858(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822568EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822568EC) {
	__imp__sub_822568EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822568F0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r4,0(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f0,-13028(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13028);
	f0.f64 = double(temp.f32);
	// fmuls f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lfs f12,12196(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 12196);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,3796(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// lwz r3,3748(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3748);
	// lfs f11,14884(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 14884);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,3768(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3768);
	// subf r11,r11,r3
	r11.s64 = ctx.r3.s64 - r11.s64;
	// subf r10,r11,r3
	ctx.r10.s64 = ctx.r3.s64 - r11.s64;
	// fmuls f9,f10,f12
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r9.u64);
	// lfd f8,-16(r1)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// fsel f6,f9,f9,f13
	ctx.f6.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : ctx.f13.f64;
	// fsel f5,f9,f9,f13
	ctx.f5.f64 = ctx.f9.f64 >= 0.0 ? ctx.f9.f64 : ctx.f13.f64;
	// frsp f4,f7
	ctx.f4.f64 = double(float(ctx.f7.f64));
	// fsubs f3,f6,f0
	ctx.f3.f64 = double(float(ctx.f6.f64 - f0.f64));
	// fsel f2,f3,f0,f5
	ctx.f2.f64 = ctx.f3.f64 >= 0.0 ? f0.f64 : ctx.f5.f64;
	// fadds f1,f2,f0
	ctx.f1.f64 = double(float(ctx.f2.f64 + f0.f64));
	// fmuls f0,f1,f11
	f0.f64 = double(float(ctx.f1.f64 * ctx.f11.f64));
	// fmuls f13,f0,f4
	ctx.f13.f64 = double(float(f0.f64 * ctx.f4.f64));
	// fctiwz f12,f13
	ctx.f12.s64 = (ctx.f13.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f12.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r7,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822568F0) {
	__imp__sub_822568F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256988) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r9,3760(r10)
	PPC_STORE_U32(ctx.r10.u32 + 3760, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256988) {
	__imp__sub_82256988(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225699C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225699C) {
	__imp__sub_8225699C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822569A0) {
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
	// beq cr6,0x822569c0
	if (cr6.eq) goto loc_822569C0;
	// lwz r11,3760(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3760);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822569C0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822569A0) {
	__imp__sub_822569A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822569CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822569CC) {
	__imp__sub_822569CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822569D0) {
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
	// beq cr6,0x822569f0
	if (cr6.eq) goto loc_822569F0;
	// lwz r11,3752(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3752);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_822569F0:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822569D0) {
	__imp__sub_822569D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822569FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822569FC) {
	__imp__sub_822569FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256A00) {
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
	// beq cr6,0x82256a20
	if (cr6.eq) goto loc_82256A20;
	// lwz r11,3096(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3096);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_82256A20:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256A00) {
	__imp__sub_82256A00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256A2C) {
	__imp__sub_82256A2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256A30) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,3752(r10)
	PPC_STORE_U32(ctx.r10.u32 + 3752, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256A30) {
	__imp__sub_82256A30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256A4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256A4C) {
	__imp__sub_82256A4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256A50) {
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
	// stb r10,3774(r11)
	PPC_STORE_U8(r11.u32 + 3774, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256A50) {
	__imp__sub_82256A50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256A78) {
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
	// beq cr6,0x82256a9c
	if (cr6.eq) goto loc_82256A9C;
	// lbz r11,3774(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 3774);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82256A9C:
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

PPC_WEAK_FUNC(sub_82256A78) {
	__imp__sub_82256A78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256AB0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r11,3756(r10)
	PPC_STORE_U32(ctx.r10.u32 + 3756, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256AB0) {
	__imp__sub_82256AB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256ACC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256ACC) {
	__imp__sub_82256ACC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256AD0) {
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
	// beq cr6,0x82256af0
	if (cr6.eq) goto loc_82256AF0;
	// lwz r11,3756(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3756);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
loc_82256AF0:
	// li r11,100
	r11.s64 = 100;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256AD0) {
	__imp__sub_82256AD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256AFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256AFC) {
	__imp__sub_82256AFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256B00) {
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
	// stb r10,3772(r11)
	PPC_STORE_U8(r11.u32 + 3772, ctx.r10.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256B00) {
	__imp__sub_82256B00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256B28) {
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
	// beq cr6,0x82256b4c
	if (cr6.eq) goto loc_82256B4C;
	// lbz r11,3772(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 3772);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82256B4C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256B28) {
	__imp__sub_82256B28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256B60) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lfs f1,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82256090
	ctx.lr = 0x82256B84;
	sub_82256090(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256B60) {
	__imp__sub_82256B60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256BA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256BA4) {
	__imp__sub_82256BA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256BA8) {
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
	// beq cr6,0x82256bcc
	if (cr6.eq) goto loc_82256BCC;
	// lbz r11,3773(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 3773);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82256BCC:
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

PPC_WEAK_FUNC(sub_82256BA8) {
	__imp__sub_82256BA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256BE0) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82256c3c
	if (cr6.eq) goto loc_82256C3C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// lbz r9,796(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 796);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82256c28
	if (!cr6.eq) goto loc_82256C28;
	// lbz r11,797(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 797);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82256c34
	if (cr6.eq) goto loc_82256C34;
loc_82256C28:
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x827057e0
	ctx.lr = 0x82256C34;
	sub_827057E0(ctx, base);
loc_82256C34:
	// li r11,1
	r11.s64 = 1;
	// stb r11,3773(r31)
	PPC_STORE_U8(r31.u32 + 3773, r11.u8);
loc_82256C3C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256BE0) {
	__imp__sub_82256BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256C50) {
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
	// beq cr6,0x82256c74
	if (cr6.eq) goto loc_82256C74;
	// lbz r11,3775(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 3775);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
loc_82256C74:
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

PPC_WEAK_FUNC(sub_82256C50) {
	__imp__sub_82256C50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256C88) {
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
	// li r3,3776
	ctx.r3.s64 = 3776;
	// bl 0x82130528
	ctx.lr = 0x82256C9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82256cb8
	if (cr6.eq) goto loc_82256CB8;
	// bl 0x82256548
	ctx.lr = 0x82256CA8;
	sub_82256548(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82256CB8:
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

PPC_WEAK_FUNC(sub_82256C88) {
	__imp__sub_82256C88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256CCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256CCC) {
	__imp__sub_82256CCC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256CD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-21540(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -21540);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82256CD0) {
	__imp__sub_82256CD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256CDC) {
	__imp__sub_82256CDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256CE0) {
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
	// addi r10,r11,-14920
	ctx.r10.s64 = r11.s64 + -14920;
	// addi r3,r31,4
	ctx.r3.s64 = r31.s64 + 4;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lhz r5,10(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 10);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82256d20
	if (cr6.eq) goto loc_82256D20;
	// lwz r4,0(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x822561c8
	ctx.lr = 0x82256D20;
	sub_822561C8(ctx, base);
loc_82256D20:
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82256d38
	if (cr6.eq) goto loc_82256D38;
	// bl 0x82130588
	ctx.lr = 0x82256D34;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82256D38:
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

PPC_WEAK_FUNC(sub_82256CE0) {
	__imp__sub_82256CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256D50) {
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
	// li r3,3776
	ctx.r3.s64 = 3776;
	// bl 0x82130528
	ctx.lr = 0x82256D6C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82256d94
	if (cr6.eq) goto loc_82256D94;
	// bl 0x82256548
	ctx.lr = 0x82256D78;
	sub_82256548(ctx, base);
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
loc_82256D94:
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

PPC_WEAK_FUNC(sub_82256D50) {
	__imp__sub_82256D50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256DB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82256DB4) {
	__imp__sub_82256DB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256DB8) {
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
	ctx.lr = 0x82256DC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82256e48
	if (cr6.eq) goto loc_82256E48;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82256e48
	if (cr6.eq) goto loc_82256E48;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// addi r4,r10,-14912
	ctx.r4.s64 = ctx.r10.s64 + -14912;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x82256DFC;
	sub_821CA540(ctx, base);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x82256E04;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82256e2c
	if (cr6.eq) goto loc_82256E2C;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r9,r10,-14920
	ctx.r9.s64 = ctx.r10.s64 + -14920;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// sth r11,8(r3)
	PPC_STORE_U16(ctx.r3.u32 + 8, r11.u16);
	// sth r11,10(r3)
	PPC_STORE_U16(ctx.r3.u32 + 10, r11.u16);
	// b 0x82256e30
	goto loc_82256E30;
loc_82256E2C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82256E30:
	// stw r3,3744(r29)
	PPC_STORE_U32(r29.u32 + 3744, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82738d90
	ctx.lr = 0x82256E40;
	sub_82738D90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82256E48;
	sub_821C9A90(ctx, base);
loc_82256E48:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82256DB8) {
	__imp__sub_82256DB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256E50) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82256db8
	sub_82256DB8(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82256E50) {
	__imp__sub_82256E50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82256E60) {
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
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,27984
	ctx.r4.s64 = r11.s64 + 27984;
	// addi r3,r10,-14132
	ctx.r3.s64 = ctx.r10.s64 + -14132;
	// bl 0x82554798
	ctx.lr = 0x82256E80;
	sub_82554798(ctx, base);
	// lis r9,-32199
	ctx.r9.s64 = -2110193664;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,1456
	ctx.r4.s64 = ctx.r9.s64 + 1456;
	// addi r3,r8,-14148
	ctx.r3.s64 = ctx.r8.s64 + -14148;
	// bl 0x82554798
	ctx.lr = 0x82256E94;
	sub_82554798(ctx, base);
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,26184
	ctx.r4.s64 = ctx.r7.s64 + 26184;
	// addi r3,r6,-14160
	ctx.r3.s64 = ctx.r6.s64 + -14160;
	// bl 0x82554798
	ctx.lr = 0x82256EA8;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,26200
	ctx.r4.s64 = ctx.r5.s64 + 26200;
	// addi r3,r3,-14180
	ctx.r3.s64 = ctx.r3.s64 + -14180;
	// bl 0x82554798
	ctx.lr = 0x82256EBC;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,26224
	ctx.r4.s64 = r11.s64 + 26224;
	// addi r3,r10,-14200
	ctx.r3.s64 = ctx.r10.s64 + -14200;
	// bl 0x82554798
	ctx.lr = 0x82256ED0;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,24680
	ctx.r4.s64 = ctx.r9.s64 + 24680;
	// addi r3,r8,-14224
	ctx.r3.s64 = ctx.r8.s64 + -14224;
	// bl 0x82554798
	ctx.lr = 0x82256EE4;
	sub_82554798(ctx, base);
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,25472
	ctx.r4.s64 = ctx.r7.s64 + 25472;
	// addi r3,r6,-14244
	ctx.r3.s64 = ctx.r6.s64 + -14244;
	// bl 0x82554798
	ctx.lr = 0x82256EF8;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,26248
	ctx.r4.s64 = ctx.r5.s64 + 26248;
	// addi r3,r3,-14260
	ctx.r3.s64 = ctx.r3.s64 + -14260;
	// bl 0x82554798
	ctx.lr = 0x82256F0C;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,26336
	ctx.r4.s64 = r11.s64 + 26336;
	// addi r3,r10,-14280
	ctx.r3.s64 = ctx.r10.s64 + -14280;
	// bl 0x82554798
	ctx.lr = 0x82256F20;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,26376
	ctx.r4.s64 = ctx.r9.s64 + 26376;
	// addi r3,r8,-14300
	ctx.r3.s64 = ctx.r8.s64 + -14300;
	// bl 0x82554798
	ctx.lr = 0x82256F34;
	sub_82554798(ctx, base);
	// lis r7,-32198
	ctx.r7.s64 = -2110128128;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,-10240
	ctx.r4.s64 = ctx.r7.s64 + -10240;
	// addi r3,r6,-14324
	ctx.r3.s64 = ctx.r6.s64 + -14324;
	// bl 0x82554798
	ctx.lr = 0x82256F48;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,26400
	ctx.r4.s64 = ctx.r5.s64 + 26400;
	// addi r3,r3,-14344
	ctx.r3.s64 = ctx.r3.s64 + -14344;
	// bl 0x82554798
	ctx.lr = 0x82256F5C;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,28240
	ctx.r4.s64 = r11.s64 + 28240;
	// addi r3,r10,-14372
	ctx.r3.s64 = ctx.r10.s64 + -14372;
	// bl 0x82554798
	ctx.lr = 0x82256F70;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,26464
	ctx.r4.s64 = ctx.r9.s64 + 26464;
	// addi r3,r8,-14400
	ctx.r3.s64 = ctx.r8.s64 + -14400;
	// bl 0x82554798
	ctx.lr = 0x82256F84;
	sub_82554798(ctx, base);
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,26480
	ctx.r4.s64 = ctx.r7.s64 + 26480;
	// addi r3,r6,-14424
	ctx.r3.s64 = ctx.r6.s64 + -14424;
	// bl 0x82554798
	ctx.lr = 0x82256F98;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,26528
	ctx.r4.s64 = ctx.r5.s64 + 26528;
	// addi r3,r3,-14448
	ctx.r3.s64 = ctx.r3.s64 + -14448;
	// bl 0x82554798
	ctx.lr = 0x82256FAC;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,26584
	ctx.r4.s64 = r11.s64 + 26584;
	// addi r3,r10,-14464
	ctx.r3.s64 = ctx.r10.s64 + -14464;
	// bl 0x82554798
	ctx.lr = 0x82256FC0;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,26672
	ctx.r4.s64 = ctx.r9.s64 + 26672;
	// addi r3,r8,-14488
	ctx.r3.s64 = ctx.r8.s64 + -14488;
	// bl 0x82554798
	ctx.lr = 0x82256FD4;
	sub_82554798(ctx, base);
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,26688
	ctx.r4.s64 = ctx.r7.s64 + 26688;
	// addi r3,r6,-14504
	ctx.r3.s64 = ctx.r6.s64 + -14504;
	// bl 0x82554798
	ctx.lr = 0x82256FE8;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,26712
	ctx.r4.s64 = ctx.r5.s64 + 26712;
	// addi r3,r3,-14524
	ctx.r3.s64 = ctx.r3.s64 + -14524;
	// bl 0x82554798
	ctx.lr = 0x82256FFC;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,26864
	ctx.r4.s64 = r11.s64 + 26864;
	// addi r3,r10,-14540
	ctx.r3.s64 = ctx.r10.s64 + -14540;
	// bl 0x82554798
	ctx.lr = 0x82257010;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,27016
	ctx.r4.s64 = ctx.r9.s64 + 27016;
	// addi r3,r8,-14560
	ctx.r3.s64 = ctx.r8.s64 + -14560;
	// bl 0x82554798
	ctx.lr = 0x82257024;
	sub_82554798(ctx, base);
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,27040
	ctx.r4.s64 = ctx.r7.s64 + 27040;
	// addi r3,r6,-14580
	ctx.r3.s64 = ctx.r6.s64 + -14580;
	// bl 0x82554798
	ctx.lr = 0x82257038;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,27088
	ctx.r4.s64 = ctx.r5.s64 + 27088;
	// addi r3,r3,-14600
	ctx.r3.s64 = ctx.r3.s64 + -14600;
	// bl 0x82554798
	ctx.lr = 0x8225704C;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,27136
	ctx.r4.s64 = r11.s64 + 27136;
	// addi r3,r10,-14620
	ctx.r3.s64 = ctx.r10.s64 + -14620;
	// bl 0x82554798
	ctx.lr = 0x82257060;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,27184
	ctx.r4.s64 = ctx.r9.s64 + 27184;
	// addi r3,r8,-14640
	ctx.r3.s64 = ctx.r8.s64 + -14640;
	// bl 0x82554798
	ctx.lr = 0x82257074;
	sub_82554798(ctx, base);
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,27216
	ctx.r4.s64 = ctx.r7.s64 + 27216;
	// addi r3,r6,-14664
	ctx.r3.s64 = ctx.r6.s64 + -14664;
	// bl 0x82554798
	ctx.lr = 0x82257088;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,27256
	ctx.r4.s64 = ctx.r5.s64 + 27256;
	// addi r3,r3,-14684
	ctx.r3.s64 = ctx.r3.s64 + -14684;
	// bl 0x82554798
	ctx.lr = 0x8225709C;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,27312
	ctx.r4.s64 = r11.s64 + 27312;
	// addi r3,r10,-14708
	ctx.r3.s64 = ctx.r10.s64 + -14708;
	// bl 0x82554798
	ctx.lr = 0x822570B0;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,27344
	ctx.r4.s64 = ctx.r9.s64 + 27344;
	// addi r3,r8,-14732
	ctx.r3.s64 = ctx.r8.s64 + -14732;
	// bl 0x82554798
	ctx.lr = 0x822570C4;
	sub_82554798(ctx, base);
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,27392
	ctx.r4.s64 = ctx.r7.s64 + 27392;
	// addi r3,r6,-14760
	ctx.r3.s64 = ctx.r6.s64 + -14760;
	// bl 0x82554798
	ctx.lr = 0x822570D8;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,27432
	ctx.r4.s64 = ctx.r5.s64 + 27432;
	// addi r3,r3,-14792
	ctx.r3.s64 = ctx.r3.s64 + -14792;
	// bl 0x82554798
	ctx.lr = 0x822570EC;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// addi r4,r11,27488
	ctx.r4.s64 = r11.s64 + 27488;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-14820
	ctx.r3.s64 = ctx.r10.s64 + -14820;
	// bl 0x82554798
	ctx.lr = 0x82257100;
	sub_82554798(ctx, base);
	// lis r9,-32219
	ctx.r9.s64 = -2111504384;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r4,r9,27560
	ctx.r4.s64 = ctx.r9.s64 + 27560;
	// addi r3,r8,-14836
	ctx.r3.s64 = ctx.r8.s64 + -14836;
	// bl 0x82554798
	ctx.lr = 0x82257114;
	sub_82554798(ctx, base);
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r7,27616
	ctx.r4.s64 = ctx.r7.s64 + 27616;
	// addi r3,r6,-14848
	ctx.r3.s64 = ctx.r6.s64 + -14848;
	// bl 0x82554798
	ctx.lr = 0x82257128;
	sub_82554798(ctx, base);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// lis r3,-32253
	ctx.r3.s64 = -2113732608;
	// addi r4,r5,27728
	ctx.r4.s64 = ctx.r5.s64 + 27728;
	// addi r3,r3,-14872
	ctx.r3.s64 = ctx.r3.s64 + -14872;
	// bl 0x82554798
	ctx.lr = 0x8225713C;
	sub_82554798(ctx, base);
	// lis r11,-32219
	r11.s64 = -2111504384;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r11,4896
	ctx.r4.s64 = r11.s64 + 4896;
	// addi r3,r10,-14888
	ctx.r3.s64 = ctx.r10.s64 + -14888;
	// bl 0x82554798
	ctx.lr = 0x82257150;
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

PPC_WEAK_FUNC(sub_82256E60) {
	__imp__sub_82256E60(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257160) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,794
	r11.s64 = ctx.r4.s64 + 794;
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257160) {
	__imp__sub_82257160(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257174) {
	__imp__sub_82257174(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257178) {
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
	// li r11,0
	r11.s64 = 0;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r11,0(r4)
	PPC_STORE_U32(ctx.r4.u32 + 0, r11.u32);
	// stw r11,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, r11.u32);
	// stw r11,44(r4)
	PPC_STORE_U32(ctx.r4.u32 + 44, r11.u32);
	// stw r11,48(r4)
	PPC_STORE_U32(ctx.r4.u32 + 48, r11.u32);
	// stw r10,4(r4)
	PPC_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// stw r10,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, ctx.r10.u32);
	// lwz r31,36(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// bl 0x82237910
	ctx.lr = 0x822571B0;
	sub_82237910(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82238140
	ctx.lr = 0x822571B8;
	sub_82238140(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257178) {
	__imp__sub_82257178(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822571CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822571CC) {
	__imp__sub_822571CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822571D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82263680
	ctx.lr = 0x822571E4;
	sub_82263680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82257244
	if (cr6.eq) goto loc_82257244;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r3,200
	ctx.r10.s64 = ctx.r3.s64 + 200;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r7,2
	ctx.r7.s64 = 2;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82257204:
	// stb r9,329(r3)
	PPC_STORE_U8(ctx.r3.u32 + 329, ctx.r9.u8);
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82257220
	if (cr6.eq) goto loc_82257220;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// bne cr6,0x82257224
	if (!cr6.eq) goto loc_82257224;
loc_82257220:
	// li r11,1
	r11.s64 = 1;
loc_82257224:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82257238
	if (!cr6.eq) goto loc_82257238;
	// stfs f0,64(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 64, temp.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
loc_82257238:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82257204
	if (!cr0.eq) goto loc_82257204;
loc_82257244:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822571D0) {
	__imp__sub_822571D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257254) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257254) {
	__imp__sub_82257254(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257258) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82263680
	ctx.lr = 0x8225726C;
	sub_82263680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822572cc
	if (cr6.eq) goto loc_822572CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r3,200
	ctx.r10.s64 = ctx.r3.s64 + 200;
	// li r8,16
	ctx.r8.s64 = 16;
	// li r7,1
	ctx.r7.s64 = 1;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
loc_82257288:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822572a0
	if (cr6.eq) goto loc_822572A0;
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822572a4
	if (!cr6.eq) goto loc_822572A4;
loc_822572A0:
	// mr r11,r7
	r11.u64 = ctx.r7.u64;
loc_822572A4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822572c0
	if (cr6.eq) goto loc_822572C0;
	// cmpwi cr6,r9,3
	cr6.compare<int32_t>(ctx.r9.s32, 3, xer);
	// beq cr6,0x822572c0
	if (cr6.eq) goto loc_822572C0;
	// stfs f0,64(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 64, temp.u32);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
loc_822572C0:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x82257288
	if (!cr0.eq) goto loc_82257288;
loc_822572CC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257258) {
	__imp__sub_82257258(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822572DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822572DC) {
	__imp__sub_822572DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822572E0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x82263680
	ctx.lr = 0x822572F4;
	sub_82263680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822573c4
	if (cr6.eq) goto loc_822573C4;
	// addi r9,r3,204
	ctx.r9.s64 = ctx.r3.s64 + 204;
	// li r8,4
	ctx.r8.s64 = 4;
	// li r10,1
	ctx.r10.s64 = 1;
loc_82257308:
	// lwz r11,-4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82257320
	if (cr6.eq) goto loc_82257320;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82257324
	if (!cr6.eq) goto loc_82257324;
loc_82257320:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82257324:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82257334
	if (cr6.eq) goto loc_82257334;
	// stb r10,329(r3)
	PPC_STORE_U8(ctx.r3.u32 + 329, ctx.r10.u8);
loc_82257334:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8225734c
	if (cr6.eq) goto loc_8225734C;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x82257350
	if (!cr6.eq) goto loc_82257350;
loc_8225734C:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_82257350:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82257360
	if (cr6.eq) goto loc_82257360;
	// stb r10,329(r3)
	PPC_STORE_U8(ctx.r3.u32 + 329, ctx.r10.u8);
loc_82257360:
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82257378
	if (cr6.eq) goto loc_82257378;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8225737c
	if (!cr6.eq) goto loc_8225737C;
loc_82257378:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_8225737C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225738c
	if (cr6.eq) goto loc_8225738C;
	// stb r10,329(r3)
	PPC_STORE_U8(ctx.r3.u32 + 329, ctx.r10.u8);
loc_8225738C:
	// lwz r11,8(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822573a4
	if (cr6.eq) goto loc_822573A4;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x822573a8
	if (!cr6.eq) goto loc_822573A8;
loc_822573A4:
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
loc_822573A8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822573b8
	if (cr6.eq) goto loc_822573B8;
	// stb r10,329(r3)
	PPC_STORE_U8(ctx.r3.u32 + 329, ctx.r10.u8);
loc_822573B8:
	// addic. r8,r8,-1
	xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// bne 0x82257308
	if (!cr0.eq) goto loc_82257308;
loc_822573C4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822572E0) {
	__imp__sub_822572E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822573D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822573D4) {
	__imp__sub_822573D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822573D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// li r11,16
	r11.s64 = 16;
	// li r10,80
	ctx.r10.s64 = 80;
	// lvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r4,r11
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r9,36(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// lvx128 v62,r0,r31
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r9,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,40(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 40);
	// bl 0x82263680
	ctx.lr = 0x82257410;
	sub_82263680(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82264e80
	ctx.lr = 0x82257418;
	sub_82264E80(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822573D8) {
	__imp__sub_822573D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225742C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225742C) {
	__imp__sub_8225742C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257430) {
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
	// lwz r3,-5084(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82257480
	if (cr6.eq) goto loc_82257480;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82257474
	if (cr6.eq) goto loc_82257474;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(r11.u32, 0);
	// bl 0x82130588
	ctx.lr = 0x82257464;
	sub_82130588(ctx, base);
	// lwz r11,-5084(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -5084);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// lwz r3,-5084(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -5084);
loc_82257474:
	// bl 0x82130588
	ctx.lr = 0x82257478;
	sub_82130588(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,-5084(r31)
	PPC_STORE_U32(r31.u32 + -5084, r11.u32);
loc_82257480:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257430) {
	__imp__sub_82257430(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257494) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257494) {
	__imp__sub_82257494(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257498) {
	PPC_FUNC_PROLOGUE();
	// li r3,80
	ctx.r3.s64 = 80;
	// b 0x82130528
	sub_82130528(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82257498) {
	__imp__sub_82257498(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822574A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5092(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5092);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822574A0) {
	__imp__sub_822574A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822574AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822574AC) {
	__imp__sub_822574AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822574B0) {
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
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x822574C4;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82257540
	if (cr6.eq) goto loc_82257540;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r7,-32252
	ctx.r7.s64 = -2113667072;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f13,14988(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14988);
	ctx.f13.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f12,-13300(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -13300);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,-13304(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -13304);
	ctx.f10.f64 = double(temp.f32);
	// stw r5,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r5.u32);
	// lfs f9,3732(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3732);
	ctx.f9.f64 = double(temp.f32);
	// lfs f0,3796(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f13,4(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f12,8(r3)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f11,12(r3)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// stfs f10,16(r3)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r3.u32 + 16, temp.u32);
	// stfs f9,20(r3)
	temp.f32 = float(ctx.f9.f64);
	PPC_STORE_U32(ctx.r3.u32 + 20, temp.u32);
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
	// stfs f0,56(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_82257540:
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

PPC_WEAK_FUNC(sub_822574B0) {
	__imp__sub_822574B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257554) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257554) {
	__imp__sub_82257554(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257558) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5088(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5088);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257558) {
	__imp__sub_82257558(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257564) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257564) {
	__imp__sub_82257564(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257568) {
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
	ctx.lr = 0x82257570;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// bl 0x826187f0
	ctx.lr = 0x8225758C;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822575d4
	if (cr6.eq) goto loc_822575D4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618318
	ctx.lr = 0x822575B4;
	sub_82618318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// bl 0x826188d8
	ctx.lr = 0x822575C8;
	sub_826188D8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_822575D4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r28,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r28.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82257568) {
	__imp__sub_82257568(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822575E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822575E4) {
	__imp__sub_822575E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822575E8) {
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
	ctx.lr = 0x822575F0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// bl 0x82618750
	ctx.lr = 0x82257608;
	sub_82618750(ctx, base);
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
	// blt cr6,0x82257668
	if (cr6.lt) goto loc_82257668;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82257620;
	sub_82618640(ctx, base);
	// li r5,14
	ctx.r5.s64 = 14;
	// li r4,12870
	ctx.r4.s64 = 12870;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x82257630;
	sub_824E6390(ctx, base);
	// cmplwi cr6,r30,255
	cr6.compare<uint32_t>(r30.u32, 255, xer);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bgt cr6,0x82257650
	if (cr6.gt) goto loc_82257650;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x824e6390
	ctx.lr = 0x82257648;
	sub_824E6390(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x8225765c
	goto loc_8225765C;
loc_82257650:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x824e6390
	ctx.lr = 0x82257658;
	sub_824E6390(ctx, base);
	// li r5,16
	ctx.r5.s64 = 16;
loc_8225765C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824e6390
	ctx.lr = 0x82257668;
	sub_824E6390(ctx, base);
loc_82257668:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82257670;
	sub_826186A0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_822575E8) {
	__imp__sub_822575E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257678) {
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
	ctx.lr = 0x82257680;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x82618750
	ctx.lr = 0x8225769C;
	sub_82618750(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826185e0
	ctx.lr = 0x822576AC;
	sub_826185E0(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826187f0
	ctx.lr = 0x822576B8;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225779c
	if (cr6.eq) goto loc_8225779C;
	// li r5,14
	ctx.r5.s64 = 14;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x822576D4;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225779c
	if (cr6.eq) goto loc_8225779C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r11,12870
	cr6.compare<uint32_t>(r11.u32, 12870, xer);
	// bne cr6,0x8225779c
	if (!cr6.eq) goto loc_8225779C;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x822576FC;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225779c
	if (cr6.eq) goto loc_8225779C;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// clrlwi r10,r11,31
	ctx.r10.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8225775c
	if (!cr6.eq) goto loc_8225775C;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x826187f0
	ctx.lr = 0x82257724;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82257750
	if (cr6.eq) goto loc_82257750;
	// li r5,8
	ctx.r5.s64 = 8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x82257740;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82257754
	if (!cr6.eq) goto loc_82257754;
loc_82257750:
	// li r11,0
	r11.s64 = 0;
loc_82257754:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// b 0x822577a4
	goto loc_822577A4;
loc_8225775C:
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x826187f0
	ctx.lr = 0x82257764;
	sub_826187F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82257790
	if (cr6.eq) goto loc_82257790;
	// li r5,16
	ctx.r5.s64 = 16;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82257568
	ctx.lr = 0x82257780;
	sub_82257568(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82257794
	if (!cr6.eq) goto loc_82257794;
loc_82257790:
	// li r11,0
	r11.s64 = 0;
loc_82257794:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// b 0x822577a4
	goto loc_822577A4;
loc_8225779C:
	// li r11,-1
	r11.s64 = -1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
loc_822577A4:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822577c0
	if (cr6.eq) goto loc_822577C0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x826186b0
	ctx.lr = 0x822577B8;
	sub_826186B0(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
loc_822577C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82257678) {
	__imp__sub_82257678(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822577CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822577CC) {
	__imp__sub_822577CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822577D0) {
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
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82257820
	if (cr6.eq) goto loc_82257820;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82257818
	if (!cr6.eq) goto loc_82257818;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8225780C;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82257820
	if (cr6.eq) goto loc_82257820;
loc_82257818:
	// li r11,1
	r11.s64 = 1;
	// b 0x82257824
	goto loc_82257824;
loc_82257820:
	// li r11,0
	r11.s64 = 0;
loc_82257824:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82257854
	if (!cr6.eq) goto loc_82257854;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r30,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r11,8788(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8788);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82257854
	if (cr6.eq) goto loc_82257854;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82257860
	goto loc_82257860;
loc_82257854:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,112
	ctx.r3.s64 = r31.s64 + 112;
	// bl 0x82273ff8
	ctx.lr = 0x82257860;
	sub_82273FF8(ctx, base);
loc_82257860:
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

PPC_WEAK_FUNC(sub_822577D0) {
	__imp__sub_822577D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257878) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r9,20(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 20);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// blt cr6,0x822578d8
	if (cr6.lt) goto loc_822578D8;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,1460
	ctx.r10.s64 = ctx.r3.s64 + 1460;
loc_822578B0:
	// lbz r8,-4(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + -4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822578c8
	if (cr6.eq) goto loc_822578C8;
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r8,r9
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, xer);
	// beq cr6,0x822578e0
	if (cr6.eq) goto loc_822578E0;
loc_822578C8:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x822578b0
	if (cr6.lt) goto loc_822578B0;
loc_822578D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822578E0:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,1456
	ctx.r3.s64 = r11.s64 + 1456;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257878) {
	__imp__sub_82257878(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822578F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,2144(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2144);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,32
	cr6.compare<int32_t>(r11.s32, 32, xer);
	// bne cr6,0x82257960
	if (!cr6.eq) goto loc_82257960;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwz r7,2140(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2140);
	// addi r11,r3,1496
	r11.s64 = ctx.r3.s64 + 1496;
	// addi r6,r8,-1
	ctx.r6.s64 = ctx.r8.s64 + -1;
	// addi r8,r7,1
	ctx.r8.s64 = ctx.r7.s64 + 1;
	// stw r6,2144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2144, ctx.r6.u32);
	// stw r8,2140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2140, ctx.r8.u32);
	// cmpwi cr6,r8,32
	cr6.compare<int32_t>(ctx.r8.s32, 32, xer);
	// bne cr6,0x82257934
	if (!cr6.eq) goto loc_82257934;
	// stw r10,644(r11)
	PPC_STORE_U32(r11.u32 + 644, ctx.r10.u32);
loc_82257934:
	// lwz r8,644(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 644);
	// li r6,-1
	ctx.r6.s64 = -1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r6,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r6.u32);
loc_82257960:
	// lwz r8,2136(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2136);
	// addi r11,r3,1496
	r11.s64 = ctx.r3.s64 + 1496;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stw r8,2136(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2136, ctx.r8.u32);
	// cmpwi cr6,r8,32
	cr6.compare<int32_t>(ctx.r8.s32, 32, xer);
	// bne cr6,0x8225797c
	if (!cr6.eq) goto loc_8225797C;
	// stw r10,640(r11)
	PPC_STORE_U32(r11.u32 + 640, ctx.r10.u32);
loc_8225797C:
	// lwz r10,640(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 640);
	// li r8,5
	ctx.r8.s64 = 5;
	// lwz r6,648(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// add r5,r10,r7
	ctx.r5.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r6,648(r11)
	PPC_STORE_U32(r11.u32 + 648, ctx.r6.u32);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_822579A4:
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bdnz 0x822579a4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_822579A4;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822578F8) {
	__imp__sub_822578F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822579BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822579BC) {
	__imp__sub_822579BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822579C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,2144(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2144);
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822579d8
	if (!cr6.eq) goto loc_822579D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_822579D8:
	// lwz r10,2144(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2144);
	// addi r11,r3,1496
	r11.s64 = ctx.r3.s64 + 1496;
	// lwz r8,2140(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2140);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// stw r7,2144(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2144, ctx.r7.u32);
	// stw r10,2140(r3)
	PPC_STORE_U32(ctx.r3.u32 + 2140, ctx.r10.u32);
	// cmpwi cr6,r10,32
	cr6.compare<int32_t>(ctx.r10.s32, 32, xer);
	// bne cr6,0x82257a04
	if (!cr6.eq) goto loc_82257A04;
	// stw r6,644(r11)
	PPC_STORE_U32(r11.u32 + 644, ctx.r6.u32);
loc_82257A04:
	// lwz r10,644(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 644);
	// li r8,5
	ctx.r8.s64 = 5;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
loc_82257A24:
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82257a24
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82257A24;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r6,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r6.u32);
	// stw r6,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r6.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r6,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r6.u32);
	// stw r6,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r6.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_822579C0) {
	__imp__sub_822579C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257A58) {
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
	// li r11,0
	r11.s64 = 0;
	// addi r10,r3,1460
	ctx.r10.s64 = ctx.r3.s64 + 1460;
loc_82257A70:
	// lbz r9,-4(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82257a88
	if (cr6.eq) goto loc_82257A88;
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r9,r4
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r4.s32, xer);
	// beq cr6,0x82257aac
	if (cr6.eq) goto loc_82257AAC;
loc_82257A88:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x82257a70
	if (cr6.lt) goto loc_82257A70;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82257AAC:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,0
	ctx.r9.s64 = 0;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r10,r11,1456
	ctx.r10.s64 = r11.s64 + 1456;
	// stb r9,1456(r11)
	PPC_STORE_U8(r11.u32 + 1456, ctx.r9.u8);
	// lwz r31,1464(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 1464);
	// bl 0x82237910
	ctx.lr = 0x82257AD0;
	sub_82237910(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82238140
	ctx.lr = 0x82257AD8;
	sub_82238140(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257A58) {
	__imp__sub_82257A58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257AEC) {
	__imp__sub_82257AEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257AF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lvx128 v0,r0,r4
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,32
	ctx.r9.s64 = 32;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r11,-5084(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5084);
	// li r7,48
	ctx.r7.s64 = 48;
	// lvx128 v12,r4,r9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v13,r4,r10
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,128
	r31.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stvx128 v0,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lvx128 v11,r4,r7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stvx128 v12,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,20
	ctx.r7.s64 = 20;
	// stvx128 v11,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,24
	ctx.r4.s64 = 24;
	// lvlx128 v63,r11,r10
	temp.u32 = r11.u32 + ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v10,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// vmaddfp v0,v0,v10,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lfs f2,3732(r10)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f2.f64 = double(temp.f32);
	// stvx128 v0,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lvlx128 v62,r11,r7
	temp.u32 = r11.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v9,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v62.u32), 0xFF));
	// vmaddfp v0,v13,v9,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// lfs f1,-12084(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12084);
	ctx.f1.f64 = double(temp.f32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stvx128 v0,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v61,r11,r4
	temp.u32 = r11.u32 + ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v8,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v61.u32), 0xFF));
	// vmaddfp v7,v12,v8,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stvx128 v7,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// beq cr6,0x82257bb8
	if (cr6.eq) goto loc_82257BB8;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82257BB8:
	// bl 0x822e9760
	ctx.lr = 0x82257BBC;
	sub_822E9760(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82257be4
	if (cr6.eq) goto loc_82257BE4;
	// lwz r11,68(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,12
	ctx.r9.s64 = 12;
	// stw r10,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r10.u32);
	// lwz r8,68(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// stw r9,20(r6)
	PPC_STORE_U32(ctx.r6.u32 + 20, ctx.r9.u32);
loc_82257BE4:
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

PPC_WEAK_FUNC(sub_82257AF0) {
	__imp__sub_82257AF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257BF8) {
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
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x82257C00;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r4,-32122
	ctx.r4.s64 = -2105147392;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r4,2256
	ctx.r3.s64 = ctx.r4.s64 + 2256;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r30,r1,128
	r30.s64 = ctx.r1.s64 + 128;
	// li r11,0
	r11.s64 = 0;
	// stw r11,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, r11.u32);
	// lfs f13,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lfs f0,0(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 0);
	f0.f64 = double(temp.f32);
	// lfs f12,8(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f2
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f2.f64));
	// fadds f10,f13,f1
	ctx.f10.f64 = double(float(ctx.f13.f64 + ctx.f1.f64));
	// stvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,96
	r29.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,112
	r28.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// sth r7,220(r1)
	PPC_STORE_U16(ctx.r1.u32 + 220, ctx.r7.u16);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// sth r11,222(r1)
	PPC_STORE_U16(ctx.r1.u32 + 222, r11.u16);
	// stfs f0,128(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stb r11,224(r1)
	PPC_STORE_U8(ctx.r1.u32 + 224, r11.u8);
	// stfs f10,132(r1)
	temp.f32 = float(ctx.f10.f64);
	PPC_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// sth r11,226(r1)
	PPC_STORE_U16(ctx.r1.u32 + 226, r11.u16);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stw r11,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, r11.u32);
	// lvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r6,-32114
	ctx.r6.s64 = -2104623104;
	// stvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)(base + ((r29.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lfs f0,3796(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r3,-23452(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -23452);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f0,208(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// li r9,7
	ctx.r9.s64 = 7;
	// stfs f0,212(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stvx128 v63,r0,r28
	simde_mm_store_si128((simde__m128i*)(base + ((r28.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,2048
	ctx.r7.s64 = 2048;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82574418
	ctx.lr = 0x82257CD4;
	sub_82574418(ctx, base);
	// lwz r3,144(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82257cf8
	if (cr6.eq) goto loc_82257CF8;
	// addi r11,r1,160
	r11.s64 = ctx.r1.s64 + 160;
	// li r3,1
	ctx.r3.s64 = 1;
	// lvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9248
	return;
loc_82257CF8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82257BF8) {
	__imp__sub_82257BF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257D04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257D04) {
	__imp__sub_82257D04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257D08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,15
	ctx.r10.s64 = 15;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257D08) {
	__imp__sub_82257D08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257D18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257D18) {
	__imp__sub_82257D18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257D28) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCRegister r11{};
	// addi r11,r3,1460
	r11.s64 = ctx.r3.s64 + 1460;
	// li r10,2
	ctx.r10.s64 = 2;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r9,-1
	ctx.r9.s64 = -1;
loc_82257D38:
	// stb r8,-4(r11)
	PPC_STORE_U8(r11.u32 + -4, ctx.r8.u8);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// bne 0x82257d38
	if (!cr0.eq) goto loc_82257D38;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// li r10,15
	ctx.r10.s64 = 15;
loc_82257D54:
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
	// stw r9,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r9.u32);
	// stw r8,32(r11)
	PPC_STORE_U32(r11.u32 + 32, ctx.r8.u32);
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// bne 0x82257d54
	if (!cr0.eq) goto loc_82257D54;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257D28) {
	__imp__sub_82257D28(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257D74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257D74) {
	__imp__sub_82257D74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257D78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r9,r11,r3
	ctx.r9.u64 = r11.u64 + ctx.r3.u64;
	// lwz r8,20(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,16(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257D78) {
	__imp__sub_82257D78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257DA4) {
	__imp__sub_82257DA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257DA8) {
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
	ctx.lr = 0x82257DB0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r3,48
	r31.s64 = ctx.r3.s64 + 48;
loc_82257DC0:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r11,r29
	cr6.compare<uint32_t>(r11.u32, r29.u32, xer);
	// bne cr6,0x82257df4
	if (!cr6.eq) goto loc_82257DF4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a90c0
	ctx.lr = 0x82257DD4;
	sub_822A90C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82257e10
	if (!cr6.eq) goto loc_82257E10;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822a90f0
	ctx.lr = 0x82257DE8;
	sub_822A90F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82257e10
	if (!cr6.eq) goto loc_82257E10;
loc_82257DF4:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// cmpwi cr6,r30,15
	cr6.compare<int32_t>(r30.s32, 15, xer);
	// blt cr6,0x82257dc0
	if (cr6.lt) goto loc_82257DC0;
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82257E10:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82257DA8) {
	__imp__sub_82257DA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257E1C) {
	__imp__sub_82257E1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257E20) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lbz r10,1456(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 1456);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82257ef0
	if (cr6.eq) goto loc_82257EF0;
	// lwz r3,1468(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 1468);
	// bl 0x82263680
	ctx.lr = 0x82257E5C;
	sub_82263680(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82257ef0
	if (cr6.eq) goto loc_82257EF0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82257E70;
	sub_822A8108(ctx, base);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lwz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r7,32
	ctx.r7.s64 = 32;
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lvlx128 v63,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v63.u32), 0xFF));
	// lvx128 v61,r3,r7
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v60,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v60.f32, simde_mm_mul_ps(simde_mm_load_ps(v61.f32), simde_mm_load_ps(v62.f32)));
	// lvx128 v59,r0,r11
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v58,v59,v60
	simde_mm_store_ps(v58.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v60.f32)));
	// stvx128 v58,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82257ec8
	if (cr6.eq) goto loc_82257EC8;
	// li r11,400
	r11.s64 = 400;
	// lvx128 v57,r31,r11
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82257ed0
	goto loc_82257ED0;
loc_82257EC8:
	// lvx128 v56,r0,r11
	simde_mm_store_si128((simde__m128i*)v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82257ED0:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822653a8
	ctx.lr = 0x82257EE0;
	sub_822653A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82257ef4
	if (!cr6.eq) goto loc_82257EF4;
loc_82257EF0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82257EF4:
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

PPC_WEAK_FUNC(sub_82257E20) {
	__imp__sub_82257E20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257F0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257F0C) {
	__imp__sub_82257F0C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257F10) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// rlwinm r11,r5,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// add r11,r5,r11
	r11.u64 = ctx.r5.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// bne cr6,0x82257fb8
	if (!cr6.eq) goto loc_82257FB8;
	// lwz r3,56(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// bl 0x82263680
	ctx.lr = 0x82257F4C;
	sub_82263680(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82257fb8
	if (cr6.eq) goto loc_82257FB8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8108
	ctx.lr = 0x82257F60;
	sub_822A8108(ctx, base);
	// addi r4,r3,48
	ctx.r4.s64 = ctx.r3.s64 + 48;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,48(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82257f90
	if (cr6.eq) goto loc_82257F90;
	// li r11,400
	r11.s64 = 400;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r31,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82257f9c
	goto loc_82257F9C;
loc_82257F90:
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82257F9C:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822653a8
	ctx.lr = 0x82257FA8;
	sub_822653A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,1
	ctx.r3.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82257fbc
	if (!cr6.eq) goto loc_82257FBC;
loc_82257FB8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82257FBC:
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

PPC_WEAK_FUNC(sub_82257F10) {
	__imp__sub_82257F10(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257FD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82257FD4) {
	__imp__sub_82257FD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82257FD8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,20(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x8225803c
	if (cr6.lt) goto loc_8225803C;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,1460
	r11.s64 = r11.s64 + 1460;
loc_82258014:
	// lbz r9,-4(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + -4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8225802c
	if (cr6.eq) goto loc_8225802C;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// beqlr cr6
	if (cr6.eq) return;
loc_8225802C:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r11,r11,20
	r11.s64 = r11.s64 + 20;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// blt cr6,0x82258014
	if (cr6.lt) goto loc_82258014;
loc_8225803C:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82257FD8) {
	__imp__sub_82257FD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82258044) {
	__imp__sub_82258044(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258048) {
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
	ctx.lr = 0x82258050;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-12632
	ctx.r6.s64 = r11.s64 + -12632;
	// addi r5,r10,-12656
	ctx.r5.s64 = ctx.r10.s64 + -12656;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82258070;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822580e0
	if (cr6.eq) goto loc_822580E0;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822580e0
	if (cr6.eq) goto loc_822580E0;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82258090;
	sub_822051A0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// bl 0x82256058
	ctx.lr = 0x8225809C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822580d4
	if (cr6.eq) goto loc_822580D4;
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x822580B0;
	sub_822051A0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x822580d4
	if (!cr6.gt) goto loc_822580D4;
	// bl 0x82256058
	ctx.lr = 0x822580BC;
	sub_82256058(ctx, base);
	// bl 0x82256028
	ctx.lr = 0x822580C0;
	sub_82256028(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x822580D0;
	sub_822051A0(ctx, base);
	// subf r30,r3,r30
	r30.s64 = r30.s64 - ctx.r3.s64;
loc_822580D4:
	// add r3,r30,r29
	ctx.r3.u64 = r30.u64 + r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822580E0:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82258048) {
	__imp__sub_82258048(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822580EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822580EC) {
	__imp__sub_822580EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822580F0) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82258110;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82258124;
	sub_82270170(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x822051a0
	ctx.lr = 0x8225812C;
	sub_822051A0(ctx, base);
	// add r31,r3,r31
	r31.u64 = ctx.r3.u64 + r31.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82258138;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82258148;
	sub_82270170(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82258154;
	sub_82274120(ctx, base);
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

PPC_WEAK_FUNC(sub_822580F0) {
	__imp__sub_822580F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225816C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225816C) {
	__imp__sub_8225816C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258170) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8225818C;
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
	ctx.lr = 0x822581A0;
	sub_82270170(ctx, base);
	// li r4,19
	ctx.r4.s64 = 19;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x822581AC;
	sub_82274120(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82258170) {
	__imp__sub_82258170(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822581C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r28{};
	PPCRegister r29{};
	PPCRegister r30{};
	PPCRegister r31{};
	PPCVRegister v60{};
	PPCVRegister v61{};
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x822581C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-13268
	ctx.r4.s64 = r11.s64 + -13268;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// bl 0x823db730
	ctx.lr = 0x822581EC;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82258228
	if (!cr6.eq) goto loc_82258228;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// li r8,-1
	ctx.r8.s64 = -1;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r9,r11,5
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 5);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82258228:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-13276
	ctx.r4.s64 = r11.s64 + -13276;
	// bl 0x823db730
	ctx.lr = 0x82258238;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82258270
	if (!cr6.eq) goto loc_82258270;
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r10,r31,8
	ctx.r10.s64 = r31.s64 + 8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// rotlwi r9,r11,5
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 5);
	// sth r8,12(r31)
	PPC_STORE_U16(r31.u32 + 12, ctx.r8.u16);
	// add r11,r9,r10
	r11.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lvx128 v62,r0,r30
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82258270:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r4,r11,-13296
	ctx.r4.s64 = r11.s64 + -13296;
	// bl 0x823db730
	ctx.lr = 0x82258280;
	sub_823DB730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x822582dc
	if (!cr6.eq) goto loc_822582DC;
	// addi r11,r31,8
	r11.s64 = r31.s64 + 8;
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,-1
	ctx.r8.s64 = -1;
	// rotlwi r10,r11,5
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 5);
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lvx128 v61,r0,r30
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r8,20(r11)
	PPC_STORE_U32(r11.u32 + 20, ctx.r8.u32);
	// lhz r11,12(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// addi r5,r11,1
	ctx.r5.s64 = r11.s64 + 1;
	// sth r5,12(r31)
	PPC_STORE_U16(r31.u32 + 12, ctx.r5.u16);
	// lvx128 v60,r0,r30
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r10,r11,5
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 5);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r10,r9
	r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// stvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r29,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r29.u32);
loc_822582DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822581C0) {
	__imp__sub_822581C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822582E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822582E4) {
	__imp__sub_822582E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822582E8) {
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
	// bl 0x823d91e8
	ctx.lr = 0x822582F0;
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225840c
	if (cr6.eq) goto loc_8225840C;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// li r29,0
	r29.s64 = 0;
	// lfs f31,8884(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 8884);
	f31.f64 = double(temp.f32);
	// li r24,-1
	r24.s64 = -1;
	// addi r25,r11,2384
	r25.s64 = r11.s64 + 2384;
	// addi r27,r10,-13256
	r27.s64 = ctx.r10.s64 + -13256;
	// addi r26,r9,-27688
	r26.s64 = ctx.r9.s64 + -27688;
loc_82258334:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r31,0
	r31.s64 = 0;
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// stw r24,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r24.u32);
	// lhz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U16(r30.u32 + 12);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x822583f8
	if (!cr6.gt) goto loc_822583F8;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lvx128 v62,r0,r25
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// stfs f31,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// add r10,r29,r10
	ctx.r10.u64 = r29.u64 + ctx.r10.u64;
	// vspltisw128 v61,-1
	simde_mm_store_si128((simde__m128i*)v61.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v63,r0,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
loc_82258370:
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v60,r0,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vand128 v59,v60,v62
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)v62.u8)));
	// lvlx128 v58,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vspltw128 v57,v58,0
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v58.u32), 0xFF));
	// vaddfp128 v56,v59,v57
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v57.f32)));
	// vsubfp128 v55,v59,v57
	simde_mm_store_ps(v55.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v57.f32)));
	// vcmpgefp128 v54,v56,v63
	simde_mm_store_ps(v54.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v63.f32)));
	// vcmpgefp128 v53,v63,v55
	simde_mm_store_ps(v53.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v55.f32)));
	// vand128 v52,v53,v54
	simde_mm_store_si128((simde__m128i*)v52.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v53.u8), simde_mm_load_si128((simde__m128i*)v54.u8)));
	// vcmpequw128. v51,v52,v61
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v52.u32), simde_mm_load_si128((simde__m128i*)v61.u32)));
	cr6.setFromMask(simde_mm_load_ps(v51.f32), 0xF);
	// mfocrf r7,2
	ctx.r7.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r6,r7,0,24,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822583bc
	if (cr6.eq) goto loc_822583BC;
	// lwz r8,16(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// beq cr6,0x822583d0
	if (cr6.eq) goto loc_822583D0;
loc_822583BC:
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r11,r11,32
	r11.s64 = r11.s64 + 32;
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// blt cr6,0x82258370
	if (cr6.lt) goto loc_82258370;
	// b 0x822583f8
	goto loc_822583F8;
loc_822583D0:
	// lwz r11,16(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// lwzx r4,r10,r26
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + r26.u32);
	// bl 0x82130000
	ctx.lr = 0x822583EC;
	sub_82130000(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r9,r29,r11
	ctx.r9.u64 = r29.u64 + r11.u64;
	// stw r31,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r31.u32);
loc_822583F8:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,32
	r29.s64 = r29.s64 + 32;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x82258334
	if (cr6.lt) goto loc_82258334;
loc_8225840C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_822582E8) {
	__imp__sub_822582E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258418) {
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
	ctx.lr = 0x82258420;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x8225843C;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258474
	if (cr6.eq) goto loc_82258474;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,9
	ctx.r5.s64 = 9;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82258464;
	sub_82618390(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82258470;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_82258474:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822584d0
	if (cr6.eq) goto loc_822584D0;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r28,4
	ctx.r4.s64 = r28.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82258490;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822584d0
	if (cr6.eq) goto loc_822584D0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 8);
	// bl 0x82618f70
	ctx.lr = 0x822584A8;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822584d0
	if (cr6.eq) goto loc_822584D0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,9(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 9);
	// bl 0x82618f70
	ctx.lr = 0x822584C0;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822584d4
	if (!cr6.eq) goto loc_822584D4;
loc_822584D0:
	// li r11,0
	r11.s64 = 0;
loc_822584D4:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82258418) {
	__imp__sub_82258418(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822584E0) {
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
	ctx.lr = 0x822584E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x82258504;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225853c
	if (cr6.eq) goto loc_8225853C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,9
	ctx.r5.s64 = 9;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x8225852C;
	sub_82618390(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82258538;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_8225853C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225859c
	if (cr6.eq) goto loc_8225859C;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r28,4
	ctx.r4.s64 = r28.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82258558;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225859c
	if (cr6.eq) goto loc_8225859C;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r28,8
	ctx.r4.s64 = r28.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82258574;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225859c
	if (cr6.eq) goto loc_8225859C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,12(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 12);
	// bl 0x82618f70
	ctx.lr = 0x8225858C;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822585a0
	if (!cr6.eq) goto loc_822585A0;
loc_8225859C:
	// li r11,0
	r11.s64 = 0;
loc_822585A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822584E0) {
	__imp__sub_822584E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822585AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822585AC) {
	__imp__sub_822585AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822585B0) {
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
	ctx.lr = 0x822585B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r28,0(r29)
	r28.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x822585D4;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225860c
	if (cr6.eq) goto loc_8225860C;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,9
	ctx.r5.s64 = 9;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x822585FC;
	sub_82618390(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x82258608;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_8225860C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258688
	if (cr6.eq) goto loc_82258688;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r4,r29,4
	ctx.r4.s64 = r29.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82258628;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258688
	if (cr6.eq) goto loc_82258688;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r29,8
	ctx.r4.s64 = r29.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82258644;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258688
	if (cr6.eq) goto loc_82258688;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r29,16
	ctx.r4.s64 = r29.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82618f90
	ctx.lr = 0x82258660;
	sub_82618F90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258688
	if (cr6.eq) goto loc_82258688;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,32(r29)
	ctx.r4.u64 = PPC_LOAD_U8(r29.u32 + 32);
	// bl 0x82618f70
	ctx.lr = 0x82258678;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225868c
	if (!cr6.eq) goto loc_8225868C;
loc_82258688:
	// li r11,0
	r11.s64 = 0;
loc_8225868C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_822585B0) {
	__imp__sub_822585B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258698) {
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
	ctx.lr = 0x822586A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,0
	r30.s64 = 0;
	// lwz r29,0(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x822586BC;
	sub_826186C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822586f4
	if (cr6.eq) goto loc_822586F4;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,7
	ctx.r5.s64 = 7;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x822586E4;
	sub_82618390(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x822586F0;
	sub_826188B8(ctx, base);
	// li r30,1
	r30.s64 = 1;
loc_822586F4:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258738
	if (cr6.eq) goto loc_82258738;
	// li r5,7
	ctx.r5.s64 = 7;
	// addi r4,r28,4
	ctx.r4.s64 = r28.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82299788
	ctx.lr = 0x82258710;
	sub_82299788(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258738
	if (cr6.eq) goto loc_82258738;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lbz r4,8(r28)
	ctx.r4.u64 = PPC_LOAD_U8(r28.u32 + 8);
	// bl 0x82618f70
	ctx.lr = 0x82258728;
	sub_82618F70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8225873c
	if (!cr6.eq) goto loc_8225873C;
loc_82258738:
	// li r11,0
	r11.s64 = 0;
loc_8225873C:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82258698) {
	__imp__sub_82258698(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258748) {
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
	ctx.lr = 0x82258750;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826186c0
	ctx.lr = 0x8225876C;
	sub_826186C0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822587ac
	if (cr6.eq) goto loc_822587AC;
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r5,9
	ctx.r5.s64 = 9;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// bl 0x82618390
	ctx.lr = 0x82258794;
	sub_82618390(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826188b8
	ctx.lr = 0x822587A0;
	sub_826188B8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822587AC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_82258748) {
	__imp__sub_82258748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822587B8) {
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
	ctx.lr = 0x822587C0;
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
	ctx.lr = 0x822587E4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x822587F0;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82258800;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82258824
	if (cr6.eq) goto loc_82258824;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82258418
	ctx.lr = 0x82258814;
	sub_82258418(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82258828
	if (!cr6.eq) goto loc_82258828;
loc_82258824:
	// li r30,0
	r30.s64 = 0;
loc_82258828:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82258860
	if (cr6.eq) goto loc_82258860;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258858
	if (cr6.eq) goto loc_82258858;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82258844;
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
loc_82258858:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82258860:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822587B8) {
	__imp__sub_822587B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225886C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225886C) {
	__imp__sub_8225886C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258870) {
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
	ctx.lr = 0x82258878;
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
	ctx.lr = 0x8225889C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x822588A8;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x822588B8;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822588dc
	if (cr6.eq) goto loc_822588DC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822584e0
	ctx.lr = 0x822588CC;
	sub_822584E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822588e0
	if (!cr6.eq) goto loc_822588E0;
loc_822588DC:
	// li r30,0
	r30.s64 = 0;
loc_822588E0:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82258918
	if (cr6.eq) goto loc_82258918;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258910
	if (cr6.eq) goto loc_82258910;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x822588FC;
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
loc_82258910:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82258918:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82258870) {
	__imp__sub_82258870(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258924) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82258924) {
	__imp__sub_82258924(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258928) {
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
	ctx.lr = 0x82258930;
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
	ctx.lr = 0x82258954;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82258960;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82258970;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82258994
	if (cr6.eq) goto loc_82258994;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x822585b0
	ctx.lr = 0x82258984;
	sub_822585B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82258998
	if (!cr6.eq) goto loc_82258998;
loc_82258994:
	// li r30,0
	r30.s64 = 0;
loc_82258998:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x822589d0
	if (cr6.eq) goto loc_822589D0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822589c8
	if (cr6.eq) goto loc_822589C8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x822589B4;
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
loc_822589C8:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_822589D0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82258928) {
	__imp__sub_82258928(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822589DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822589DC) {
	__imp__sub_822589DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822589E0) {
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
	ctx.lr = 0x822589E8;
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
	ctx.lr = 0x82258A0C;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82258A18;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82258A28;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82258a4c
	if (cr6.eq) goto loc_82258A4C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82258698
	ctx.lr = 0x82258A3C;
	sub_82258698(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82258a50
	if (!cr6.eq) goto loc_82258A50;
loc_82258A4C:
	// li r30,0
	r30.s64 = 0;
loc_82258A50:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82258a88
	if (cr6.eq) goto loc_82258A88;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258a80
	if (cr6.eq) goto loc_82258A80;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82258A6C;
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
loc_82258A80:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82258A88:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_822589E0) {
	__imp__sub_822589E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258A94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82258A94) {
	__imp__sub_82258A94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258A98) {
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
	ctx.lr = 0x82258AA0;
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
	ctx.lr = 0x82258AC4;
	sub_822575E8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618750
	ctx.lr = 0x82258AD0;
	sub_82618750(ctx, base);
	// subf r5,r31,r27
	ctx.r5.s64 = r27.s64 - r31.s64;
	// add r4,r31,r30
	ctx.r4.u64 = r31.u64 + r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82618640
	ctx.lr = 0x82258AE0;
	sub_82618640(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82258b04
	if (cr6.eq) goto loc_82258B04;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82258748
	ctx.lr = 0x82258AF4;
	sub_82258748(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82258b08
	if (!cr6.eq) goto loc_82258B08;
loc_82258B04:
	// li r30,0
	r30.s64 = 0;
loc_82258B08:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82258b40
	if (cr6.eq) goto loc_82258B40;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258b38
	if (cr6.eq) goto loc_82258B38;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826186a0
	ctx.lr = 0x82258B24;
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
loc_82258B38:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r11.u32);
loc_82258B40:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82258A98) {
	__imp__sub_82258A98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82258B4C) {
	__imp__sub_82258B4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258B50) {
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
	ctx.lr = 0x82258B58;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r11,0
	r11.s64 = 0;
	// addi r10,r30,1456
	ctx.r10.s64 = r30.s64 + 1456;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r9,12(r9)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r9.u32 + 12);
	// stw r9,-5072(r8)
	PPC_STORE_U32(ctx.r8.u32 + -5072, ctx.r9.u32);
loc_82258B7C:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82258ba0
	if (cr6.eq) goto loc_82258BA0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x82258b7c
	if (cr6.lt) goto loc_82258B7C;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82258BA0:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r11,73
	ctx.r10.s64 = r11.s64 + 73;
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r10,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// add r31,r9,r30
	r31.u64 = ctx.r9.u64 + r30.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,1464(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1464);
	// addi r28,r31,1456
	r28.s64 = r31.s64 + 1456;
	// stb r6,1456(r31)
	PPC_STORE_U8(r31.u32 + 1456, ctx.r6.u8);
	// stwx r29,r7,r30
	PPC_STORE_U32(ctx.r7.u32 + r30.u32, r29.u32);
	// stb r5,38(r3)
	PPC_STORE_U8(ctx.r3.u32 + 38, ctx.r5.u8);
	// stb r4,1472(r31)
	PPC_STORE_U8(r31.u32 + 1472, ctx.r4.u8);
	// lwz r3,1468(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1468);
	// bl 0x82263680
	ctx.lr = 0x82258BEC;
	sub_82263680(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-5084(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5084);
	// rlwinm r29,r29,5,0,26
	r29.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lfs f0,36(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 36);
	f0.f64 = double(temp.f32);
	// stfs f0,176(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 176, temp.u32);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// lfs f13,32(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,168(r3)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r3.u32 + 168, temp.u32);
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + r29.u64;
	// lwz r4,16(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// bl 0x82265088
	ctx.lr = 0x82258C1C;
	sub_82265088(ctx, base);
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,80
	ctx.r6.s64 = 80;
	// lwz r5,1464(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 1464);
	// lwz r11,8(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 8);
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r5,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,1468(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1468);
	// bl 0x82263680
	ctx.lr = 0x82258C40;
	sub_82263680(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82264e80
	ctx.lr = 0x82258C48;
	sub_82264E80(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82258B50) {
	__imp__sub_82258B50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258C50) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r31{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,0(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lhz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x82258ce0
	if (!cr6.gt) goto loc_82258CE0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r11,16
	ctx.r8.s64 = r11.s64 + 16;
loc_82258C78:
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bne cr6,0x82258cd0
	if (!cr6.eq) goto loc_82258CD0;
	// cmpw cr6,r9,r5
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, xer);
	// beq cr6,0x82258cd0
	if (cr6.eq) goto loc_82258CD0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r7,20
	r11.s64 = ctx.r7.s64 + 20;
loc_82258C94:
	// lwz r31,-4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x82258cac
	if (cr6.eq) goto loc_82258CAC;
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r31,r9
	cr6.compare<int32_t>(r31.s32, ctx.r9.s32, xer);
	// beq cr6,0x82258ce8
	if (cr6.eq) goto loc_82258CE8;
loc_82258CAC:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmpwi cr6,r10,15
	cr6.compare<int32_t>(ctx.r10.s32, 15, xer);
	// blt cr6,0x82258c94
	if (cr6.lt) goto loc_82258C94;
	// li r11,0
	r11.s64 = 0;
loc_82258CC0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82258cd0
	if (!cr6.eq) goto loc_82258CD0;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_82258CD0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r8,r8,32
	ctx.r8.s64 = ctx.r8.s64 + 32;
	// cmpw cr6,r9,r6
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r6.s32, xer);
	// blt cr6,0x82258c78
	if (cr6.lt) goto loc_82258C78;
loc_82258CE0:
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_82258CE8:
	// li r11,1
	r11.s64 = 1;
	// b 0x82258cc0
	goto loc_82258CC0;
}

PPC_WEAK_FUNC(sub_82258C50) {
	__imp__sub_82258C50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258CF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32122
	ctx.r10.s64 = -2105147392;
	// add r11,r4,r11
	r11.u64 = ctx.r4.u64 + r11.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// li r8,80
	ctx.r8.s64 = 80;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r7,r10,2384
	ctx.r7.s64 = ctx.r10.s64 + 2384;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f0,17032(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 17032);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// li r5,32
	ctx.r5.s64 = 32;
	// lvx128 v61,r11,r8
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvlx128 v60,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + (temp.u32 & ~0xF))), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vand128 v59,v61,v63
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vspltw128 v58,v60,0
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v60.u32), 0xFF));
	// lvx128 v57,r11,r5
	simde_mm_store_si128((simde__m128i*)v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v56,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v56.f32, simde_mm_add_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// vand128 v55,v57,v63
	simde_mm_store_si128((simde__m128i*)v55.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)v63.u8)));
	// vsubfp128 v54,v59,v58
	simde_mm_store_ps(v54.f32, simde_mm_sub_ps(simde_mm_load_ps(v59.f32), simde_mm_load_ps(v58.f32)));
	// vcmpgefp128 v53,v56,v55
	simde_mm_store_ps(v53.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v56.f32), simde_mm_load_ps(v55.f32)));
	// vcmpgefp128 v52,v55,v54
	simde_mm_store_ps(v52.f32, simde_mm_cmpge_ps(simde_mm_load_ps(v55.f32), simde_mm_load_ps(v54.f32)));
	// vand128 v51,v52,v53
	simde_mm_store_si128((simde__m128i*)v51.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)v52.u8), simde_mm_load_si128((simde__m128i*)v53.u8)));
	// vcmpequw128. v50,v51,v62
	simde_mm_store_si128((simde__m128i*)v50.u8, simde_mm_cmpeq_epi32(simde_mm_load_si128((simde__m128i*)v51.u32), simde_mm_load_si128((simde__m128i*)v62.u32)));
	cr6.setFromMask(simde_mm_load_ps(v50.f32), 0xF);
	// mfocrf r11,2
	r11.u64 = (cr6.lt << 7) | (cr6.gt << 6) | (cr6.eq << 5) | (cr6.so << 4);
	// rlwinm r10,r11,0,24,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82258d94
	if (cr6.eq) goto loc_82258D94;
	// bl 0x82257878
	ctx.lr = 0x82258D78;
	sub_82257878(ctx, base);
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
loc_82258D94:
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

PPC_WEAK_FUNC(sub_82258CF0) {
	__imp__sub_82258CF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82258DA8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x82258DB0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r24,0
	r24.s64 = 0;
	// addi r31,r28,48
	r31.s64 = r28.s64 + 48;
	// mr r26,r24
	r26.u64 = r24.u64;
	// li r27,2
	r27.s64 = 2;
	// li r25,1
	r25.s64 = 1;
loc_82258DCC:
	// lwz r11,-32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -32);
	// mr r29,r24
	r29.u64 = r24.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82258f8c
	if (cr6.eq) goto loc_82258F8C;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82257878
	ctx.lr = 0x82258DE8;
	sub_82257878(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82258df8
	if (cr6.eq) goto loc_82258DF8;
	// stb r24,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r24.u8);
loc_82258DF8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stb r24,41(r11)
	PPC_STORE_U8(r11.u32 + 41, r24.u8);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82258ecc
	if (cr6.eq) goto loc_82258ECC;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822572e0
	ctx.lr = 0x82258E18;
	sub_822572E0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822a90c0
	ctx.lr = 0x82258E20;
	sub_822A90C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82258e40
	if (!cr6.eq) goto loc_82258E40;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822a90f0
	ctx.lr = 0x82258E34;
	sub_822A90F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258f3c
	if (cr6.eq) goto loc_82258F3C;
loc_82258E40:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822a91e0
	ctx.lr = 0x82258E48;
	sub_822A91E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258e68
	if (cr6.eq) goto loc_82258E68;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82224ac8
	ctx.lr = 0x82258E5C;
	sub_82224AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258f3c
	if (cr6.eq) goto loc_82258F3C;
loc_82258E68:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r25
	r29.u64 = r25.u64;
	// stb r27,36(r11)
	PPC_STORE_U8(r11.u32 + 36, r27.u8);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r9,4(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,-28(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + -28);
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// addi r3,r9,8
	ctx.r3.s64 = ctx.r9.s64 + 8;
	// lwz r30,16(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// bl 0x82269288
	ctx.lr = 0x82258E9C;
	sub_82269288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82258eb0
	if (cr6.eq) goto loc_82258EB0;
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// cmpw cr6,r11,r30
	cr6.compare<int32_t>(r11.s32, r30.s32, xer);
	// bne cr6,0x82258eb8
	if (!cr6.eq) goto loc_82258EB8;
loc_82258EB0:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bne cr6,0x82258f3c
	if (!cr6.eq) goto loc_82258F3C;
loc_82258EB8:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lbz r10,41(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 41);
	// ori r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 | 32;
	// stb r9,41(r11)
	PPC_STORE_U8(r11.u32 + 41, ctx.r9.u8);
	// b 0x82258f3c
	goto loc_82258F3C;
loc_82258ECC:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x82258cf0
	ctx.lr = 0x82258ED4;
	sub_82258CF0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258f14
	if (cr6.eq) goto loc_82258F14;
	// bl 0x822571d0
	ctx.lr = 0x82258EEC;
	sub_822571D0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82263680
	ctx.lr = 0x82258EF4;
	sub_82263680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82258f04
	if (cr6.eq) goto loc_82258F04;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82265df8
	ctx.lr = 0x82258F04;
	sub_82265DF8(ctx, base);
loc_82258F04:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82258f3c
	if (cr6.eq) goto loc_82258F3C;
	// stb r25,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r25.u8);
	// b 0x82258f3c
	goto loc_82258F3C;
loc_82258F14:
	// bl 0x822571d0
	ctx.lr = 0x82258F18;
	sub_822571D0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82263680
	ctx.lr = 0x82258F20;
	sub_82263680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82258f30
	if (cr6.eq) goto loc_82258F30;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82265df8
	ctx.lr = 0x82258F30;
	sub_82265DF8(ctx, base);
loc_82258F30:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r29,r25
	r29.u64 = r25.u64;
	// stb r27,36(r11)
	PPC_STORE_U8(r11.u32 + 36, r27.u8);
loc_82258F3C:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,-28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -28);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,16(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82258f78
	if (cr6.eq) goto loc_82258F78;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82258f94
	if (!cr6.eq) goto loc_82258F94;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lbz r10,41(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 41);
	// ori r9,r10,8
	ctx.r9.u64 = ctx.r10.u64 | 8;
	// stb r9,41(r11)
	PPC_STORE_U8(r11.u32 + 41, ctx.r9.u8);
	// b 0x82258f94
	goto loc_82258F94;
loc_82258F78:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lbz r10,41(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 41);
	// ori r9,r10,16
	ctx.r9.u64 = ctx.r10.u64 | 16;
	// stb r9,41(r11)
	PPC_STORE_U8(r11.u32 + 41, ctx.r9.u8);
	// b 0x82258f94
	goto loc_82258F94;
loc_82258F8C:
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82257258
	ctx.lr = 0x82258F94;
	sub_82257258(ctx, base);
loc_82258F94:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82237f18
	ctx.lr = 0x82258F9C;
	sub_82237F18(ctx, base);
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258fc8
	if (cr6.eq) goto loc_82258FC8;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82258fc0
	if (!cr6.eq) goto loc_82258FC0;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82238988
	ctx.lr = 0x82258FBC;
	sub_82238988(ctx, base);
	// b 0x82258fdc
	goto loc_82258FDC;
loc_82258FC0:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82258fdc
	if (!cr6.eq) goto loc_82258FDC;
loc_82258FC8:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82258fdc
	if (cr6.eq) goto loc_82258FDC;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82238498
	ctx.lr = 0x82258FDC;
	sub_82238498(ctx, base);
loc_82258FDC:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r31,r31,96
	r31.s64 = r31.s64 + 96;
	// cmpwi cr6,r26,15
	cr6.compare<int32_t>(r26.s32, 15, xer);
	// blt cr6,0x82258dcc
	if (cr6.lt) goto loc_82258DCC;
	// mr r29,r27
	r29.u64 = r27.u64;
	// addi r31,r28,1468
	r31.s64 = r28.s64 + 1468;
	// li r27,10
	r27.s64 = 10;
loc_82258FF8:
	// lbz r11,-12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + -12);
	// mr r30,r24
	r30.u64 = r24.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822590c4
	if (cr6.eq) goto loc_822590C4;
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// stb r24,41(r11)
	PPC_STORE_U8(r11.u32 + 41, r24.u8);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82259034
	if (cr6.eq) goto loc_82259034;
	// bl 0x82257258
	ctx.lr = 0x82259028;
	sub_82257258(ctx, base);
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// stb r27,36(r11)
	PPC_STORE_U8(r11.u32 + 36, r27.u8);
	// b 0x82259058
	goto loc_82259058;
loc_82259034:
	// bl 0x822571d0
	ctx.lr = 0x82259038;
	sub_822571D0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82263680
	ctx.lr = 0x82259040;
	sub_82263680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82259050
	if (cr6.eq) goto loc_82259050;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82265df8
	ctx.lr = 0x82259050;
	sub_82265DF8(ctx, base);
loc_82259050:
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// stb r24,36(r11)
	PPC_STORE_U8(r11.u32 + 36, r24.u8);
loc_82259058:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r10,-8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -8);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r11,8(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// lwz r11,-4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// subfic r9,r10,0
	xer.ca = ctx.r10.u32 <= 0;
	ctx.r9.s64 = 0 - ctx.r10.s64;
	// lbz r7,41(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 41);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// subfe r8,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + xer.ca < xer.ca);
	ctx.r8.u64 = ~ctx.r9.u64 + ctx.r9.u64 + xer.ca;
	xer.ca = temp.u8;
	// beq cr6,0x822590a8
	if (cr6.eq) goto loc_822590A8;
	// rlwinm r10,r8,0,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF8;
	// mr r30,r25
	r30.u64 = r25.u64;
	// rlwinm r10,r10,0,28,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFCF;
	// addi r6,r10,64
	ctx.r6.s64 = ctx.r10.s64 + 64;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stb r5,41(r11)
	PPC_STORE_U8(r11.u32 + 41, ctx.r5.u8);
	// b 0x822590cc
	goto loc_822590CC;
loc_822590A8:
	// rlwinm r10,r8,0,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFF0;
	// mr r30,r25
	r30.u64 = r25.u64;
	// rlwinm r10,r10,0,27,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFF9F;
	// addi r6,r10,128
	ctx.r6.s64 = ctx.r10.s64 + 128;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// stb r5,41(r11)
	PPC_STORE_U8(r11.u32 + 41, ctx.r5.u8);
	// b 0x822590cc
	goto loc_822590CC;
loc_822590C4:
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82257258
	ctx.lr = 0x822590CC;
	sub_82257258(ctx, base);
loc_822590CC:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82263680
	ctx.lr = 0x822590D4;
	sub_82263680(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822590e4
	if (cr6.eq) goto loc_822590E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82265df8
	ctx.lr = 0x822590E4;
	sub_82265DF8(ctx, base);
loc_822590E4:
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// bl 0x82237f18
	ctx.lr = 0x822590EC;
	sub_82237F18(ctx, base);
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82259118
	if (cr6.eq) goto loc_82259118;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82259110
	if (!cr6.eq) goto loc_82259110;
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// bl 0x82238988
	ctx.lr = 0x8225910C;
	sub_82238988(ctx, base);
	// b 0x8225912c
	goto loc_8225912C;
loc_82259110:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225912c
	if (!cr6.eq) goto loc_8225912C;
loc_82259118:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8225912c
	if (cr6.eq) goto loc_8225912C;
	// lwz r3,-4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// bl 0x82238498
	ctx.lr = 0x8225912C;
	sub_82238498(ctx, base);
loc_8225912C:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r31,r31,20
	r31.s64 = r31.s64 + 20;
	// bne 0x82258ff8
	if (!cr0.eq) goto loc_82258FF8;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-6432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -6432);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82259264
	if (cr6.eq) goto loc_82259264;
	// lhz r11,12(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// subfc r10,r11,r24
	xer.ca = r24.u32 >= r11.u32;
	ctx.r10.s64 = r24.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82259264
	if (cr6.eq) goto loc_82259264;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8225916C;
	sub_822A39C8(ctx, base);
	// lwz r11,-6432(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -6432);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8225918C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r29,700(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 700);
	// bl 0x82257da8
	ctx.lr = 0x822591A0;
	sub_82257DA8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x8225925c
	if (cr6.lt) goto loc_8225925C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a90f0
	ctx.lr = 0x822591B4;
	sub_822A90F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8225925c
	if (!cr6.eq) goto loc_8225925C;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r8,r11,r28
	ctx.r8.u64 = r11.u64 + r28.u64;
	// lwz r7,20(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 20);
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,16(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82259238
	if (cr6.eq) goto loc_82259238;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-5084(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5084);
	// beq cr6,0x8225921c
	if (cr6.eq) goto loc_8225921C;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82241d28
	ctx.lr = 0x82259214;
	sub_82241D28(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8225921C:
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82241d28
	ctx.lr = 0x82259230;
	sub_82241D28(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82259238:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,-5084(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -5084);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82241d28
	ctx.lr = 0x82259254;
	sub_82241D28(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8225925C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82241d98
	ctx.lr = 0x82259264;
	sub_82241D98(ctx, base);
loc_82259264:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_82258DA8) {
	__imp__sub_82258DA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225926C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225926C) {
	__imp__sub_8225926C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259270) {
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
	PPCVRegister v62{};
	PPCVRegister v63{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82259278;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r27,r5,24
	r27.u64 = ctx.r5.u32 & 0xFF;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82259298
	if (cr6.eq) goto loc_82259298;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r6,r11,-13108
	ctx.r6.s64 = r11.s64 + -13108;
	// b 0x822592a0
	goto loc_822592A0;
loc_82259298:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r6,r11,-13120
	ctx.r6.s64 = r11.s64 + -13120;
loc_822592A0:
	// rlwinm r11,r4,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// add r9,r4,r11
	ctx.r9.u64 = ctx.r4.u64 + r11.u64;
	// addi r3,r10,-13156
	ctx.r3.s64 = ctx.r10.s64 + -13156;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// bl 0x82130000
	ctx.lr = 0x822592C4;
	sub_82130000(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r28,1
	r28.s64 = 1;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r10,r7,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x822578f8
	ctx.lr = 0x82259304;
	sub_822578F8(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r11,r31,16
	r11.s64 = r31.s64 + 16;
	// beq cr6,0x82259354
	if (cr6.eq) goto loc_82259354;
	// addi r29,r31,80
	r29.s64 = r31.s64 + 80;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r9,80
	ctx.r9.s64 = 80;
	// lvx128 v63,r0,r29
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// lvx128 v62,r0,r29
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r29.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r8,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,56(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// bl 0x82263680
	ctx.lr = 0x82259338;
	sub_82263680(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82264e80
	ctx.lr = 0x82259340;
	sub_82264E80(ctx, base);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
loc_82259354:
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r10,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r10.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r10.u32);
	// lwz r29,52(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// bl 0x82237910
	ctx.lr = 0x82259378;
	sub_82237910(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82238140
	ctx.lr = 0x82259380;
	sub_82238140(ctx, base);
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82259270) {
	__imp__sub_82259270(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225938C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225938C) {
	__imp__sub_8225938C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259390) {
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
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r11,-13088
	ctx.r3.s64 = r11.s64 + -13088;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82130000
	ctx.lr = 0x822593C0;
	sub_82130000(ctx, base);
	// lbz r10,9(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 9);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82259428
	if (cr6.eq) goto loc_82259428;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r11,r30,20
	r11.s64 = r30.s64 + 20;
loc_822593D8:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bne cr6,0x822593f8
	if (!cr6.eq) goto loc_822593F8;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// beq cr6,0x822593fc
	if (cr6.eq) goto loc_822593FC;
loc_822593F8:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822593FC:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8225941c
	if (!cr6.eq) goto loc_8225941C;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// addi r11,r11,96
	r11.s64 = r11.s64 + 96;
	// cmpwi cr6,r4,15
	cr6.compare<int32_t>(ctx.r4.s32, 15, xer);
	// blt cr6,0x822593d8
	if (cr6.lt) goto loc_822593D8;
	// b 0x82259428
	goto loc_82259428;
loc_8225941C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lbz r5,8(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// bl 0x82259270
	ctx.lr = 0x82259428;
	sub_82259270(ctx, base);
loc_82259428:
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

PPC_WEAK_FUNC(sub_82259390) {
	__imp__sub_82259390(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259440) {
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
	ctx.lr = 0x82259448;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8225947c
	if (cr6.eq) goto loc_8225947C;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82259474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// b 0x82259484
	goto loc_82259484;
loc_8225947C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r29,r11,-13000
	r29.s64 = r11.s64 + -13000;
loc_82259484:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r3,17892(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17892);
	// add r31,r11,r28
	r31.u64 = r11.u64 + r28.u64;
	// bl 0x822b62a0
	ctx.lr = 0x822594A4;
	sub_822B62A0(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r3,r8,-13048
	ctx.r3.s64 = ctx.r8.s64 + -13048;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x822594C0;
	sub_82130000(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822595bc
	if (cr6.eq) goto loc_822595BC;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822595bc
	if (cr6.eq) goto loc_822595BC;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822595bc
	if (cr6.eq) goto loc_822595BC;
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x822594F0;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822595bc
	if (cr6.eq) goto loc_822595BC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r29,0
	r29.s64 = 0;
	// lwz r9,20(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r4,1
	ctx.r4.s64 = 1;
	// lbz r8,96(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 96);
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r29,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r29.u32);
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// beq cr6,0x8225957c
	if (cr6.eq) goto loc_8225957C;
	// li r10,9
	ctx.r10.s64 = 9;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8232adf8
	ctx.lr = 0x8225954C;
	sub_8232ADF8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r6,48(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r11,-5084(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -5084);
	// lwz r5,68(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 68);
	// lfs f0,-29232(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + -29232);
	f0.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r5)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r5.u32 + 128, temp.u32);
	// stfs f0,116(r5)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r5.u32 + 116, temp.u32);
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// b 0x822595a4
	goto loc_822595A4;
loc_8225957C:
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x8232adf0
	ctx.lr = 0x82259588;
	sub_8232ADF0(ctx, base);
	// lwz r7,48(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r6,68(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 68);
	// lfs f0,3732(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3732);
	f0.f64 = double(temp.f32);
	// stfs f0,116(r6)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r6.u32 + 116, temp.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
loc_822595A4:
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r29,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r29.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// bl 0x822578f8
	ctx.lr = 0x822595BC;
	sub_822578F8(ctx, base);
loc_822595BC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_82259440) {
	__imp__sub_82259440(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822595C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822595C4) {
	__imp__sub_822595C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822595C8) {
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
	ctx.lr = 0x822595D0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r3,17892(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x822595EC;
	sub_822B62A0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82259614
	if (cr6.eq) goto loc_82259614;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8225960C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8225961c
	goto loc_8225961C;
loc_82259614:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r27,r11,-13000
	r27.s64 = r11.s64 + -13000;
loc_8225961C:
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,17892(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17892);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r30,r11,r29
	r30.u64 = r11.u64 + r29.u64;
	// bl 0x822b62a0
	ctx.lr = 0x82259638;
	sub_822B62A0(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r5,24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r3,r10,-12896
	ctx.r3.s64 = ctx.r10.s64 + -12896;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x82259654;
	sub_82130000(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82259784
	if (cr6.eq) goto loc_82259784;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82259784
	if (cr6.eq) goto loc_82259784;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82259784
	if (cr6.eq) goto loc_82259784;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x82259684;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82259784
	if (cr6.eq) goto loc_82259784;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269288
	ctx.lr = 0x822596A0;
	sub_82269288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82259774
	if (cr6.eq) goto loc_82259774;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r27,0
	r27.s64 = 0;
	// lwz r9,20(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// rlwinm r11,r9,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r28,16(r8)
	r28.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x822596dc
	if (cr6.eq) goto loc_822596DC;
	// lwz r11,168(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 168);
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822596e0
	if (cr6.eq) goto loc_822596E0;
loc_822596DC:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_822596E0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// beq cr6,0x82259724
	if (cr6.eq) goto loc_82259724;
	// bctrl 
	ctx.lr = 0x82259700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r3,r9,-12944
	ctx.r3.s64 = ctx.r9.s64 + -12944;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// bl 0x82130000
	ctx.lr = 0x8225971C;
	sub_82130000(ctx, base);
	// li r8,5
	ctx.r8.s64 = 5;
	// b 0x82259748
	goto loc_82259748;
loc_82259724:
	// bctrl 
	ctx.lr = 0x82259728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,24(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r3,r9,-12992
	ctx.r3.s64 = ctx.r9.s64 + -12992;
	// lwz r4,20(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r7,r26
	ctx.r7.u64 = r26.u64;
	// bl 0x82130000
	ctx.lr = 0x82259744;
	sub_82130000(ctx, base);
	// li r8,4
	ctx.r8.s64 = 4;
loc_82259748:
	// lwz r7,20(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// bl 0x822578f8
	ctx.lr = 0x8225976C;
	sub_822578F8(ctx, base);
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// bl 0x82257178
	ctx.lr = 0x82259774;
	sub_82257178(ctx, base);
loc_82259774:
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x8232adf0
	ctx.lr = 0x82259784;
	sub_8232ADF0(ctx, base);
loc_82259784:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_822595C8) {
	__imp__sub_822595C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_8225978C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_8225978C) {
	__imp__sub_8225978C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259790) {
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
	ctx.lr = 0x82259798;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r26,r6
	r26.u64 = ctx.r6.u64;
	// lwz r3,17892(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x822597B8;
	sub_822B62A0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822597dc
	if (cr6.eq) goto loc_822597DC;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822597D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x822597e4
	goto loc_822597E4;
loc_822597DC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r27,r11,-13000
	r27.s64 = r11.s64 + -13000;
loc_822597E4:
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,17892(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17892);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r29
	r31.u64 = r11.u64 + r29.u64;
	// bl 0x822b62a0
	ctx.lr = 0x82259800;
	sub_822B62A0(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r5,24(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r4,20(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r3,r10,-12828
	ctx.r3.s64 = ctx.r10.s64 + -12828;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x82130000
	ctx.lr = 0x8225981C;
	sub_82130000(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822598d4
	if (cr6.eq) goto loc_822598D4;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822598d4
	if (cr6.eq) goto loc_822598D4;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822598d4
	if (cr6.eq) goto loc_822598D4;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,8
	ctx.r3.s64 = r11.s64 + 8;
	// bl 0x82269388
	ctx.lr = 0x8225984C;
	sub_82269388(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822598d4
	if (cr6.eq) goto loc_822598D4;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// bl 0x8232ae00
	ctx.lr = 0x82259864;
	sub_8232AE00(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r28,0
	r28.s64 = 0;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// addi r27,r31,16
	r27.s64 = r31.s64 + 16;
	// stw r28,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r28.u32);
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x82256028
	ctx.lr = 0x82259880;
	sub_82256028(ctx, base);
	// stw r3,60(r31)
	PPC_STORE_U32(r31.u32 + 60, ctx.r3.u32);
	// stw r28,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r28.u32);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822573d8
	ctx.lr = 0x82259898;
	sub_822573D8(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r7,20(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// li r9,6
	ctx.r9.s64 = 6;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r28,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r28.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,0(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// lwz r5,16(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// bl 0x822578f8
	ctx.lr = 0x822598D4;
	sub_822578F8(ctx, base);
loc_822598D4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_82259790) {
	__imp__sub_82259790(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822598DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_822598DC) {
	__imp__sub_822598DC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_822598E0) {
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
	PPCRegister f0{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x822598E8;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// lwz r11,48(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82259b28
	if (cr6.eq) goto loc_82259B28;
	// lwz r10,48(r22)
	ctx.r10.u64 = PPC_LOAD_U32(r22.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82259b28
	if (cr6.eq) goto loc_82259B28;
	// lwz r31,68(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r30,68(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	// li r29,0
	r29.s64 = 0;
	// li r25,0
	r25.s64 = 0;
	// li r24,0
	r24.s64 = 0;
	// lbz r11,113(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 113);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82259984
	if (cr6.eq) goto loc_82259984;
	// bl 0x82257da8
	ctx.lr = 0x82259938;
	sub_82257DA8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x822599e4
	if (cr6.lt) goto loc_822599E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8232adf0
	ctx.lr = 0x82259950;
	sub_8232ADF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8232adf0
	ctx.lr = 0x8225995C;
	sub_8232ADF0(ctx, base);
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r25,r29
	r25.u64 = r29.u64;
	// lwz r11,-5084(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -5084);
	// lfs f0,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f0.f64 = double(temp.f32);
	// stfs f0,116(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 116, temp.u32);
	// b 0x822599e4
	goto loc_822599E4;
loc_82259984:
	// lbz r11,113(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 113);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822599e4
	if (cr6.eq) goto loc_822599E4;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82257da8
	ctx.lr = 0x8225999C;
	sub_82257DA8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x822599e4
	if (cr6.lt) goto loc_822599E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8232adf0
	ctx.lr = 0x822599B4;
	sub_8232ADF0(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8232adf0
	ctx.lr = 0x822599C0;
	sub_8232ADF0(ctx, base);
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r24,r29
	r24.u64 = r29.u64;
	// lwz r11,-5084(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -5084);
	// lfs f0,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f0.f64 = double(temp.f32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
loc_822599E4:
	// lbz r11,114(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 114);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82259a50
	if (cr6.eq) goto loc_82259A50;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82257da8
	ctx.lr = 0x822599FC;
	sub_82257DA8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x82259ab8
	if (cr6.lt) goto loc_82259AB8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8232adf8
	ctx.lr = 0x82259A14;
	sub_8232ADF8(ctx, base);
	// lwz r11,-5084(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -5084);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f0,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f0.f64 = double(temp.f32);
	// stfs f0,116(r30)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r30.u32 + 116, temp.u32);
	// lfs f13,128(r31)
	temp.u32 = PPC_LOAD_U32(r31.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r30)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r30.u32 + 128, temp.u32);
	// bl 0x8232adf8
	ctx.lr = 0x82259A34;
	sub_8232ADF8(ctx, base);
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r25,r29
	r25.u64 = r29.u64;
	// b 0x82259ab8
	goto loc_82259AB8;
loc_82259A50:
	// lbz r11,114(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 114);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82259ab8
	if (cr6.eq) goto loc_82259AB8;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82257da8
	ctx.lr = 0x82259A68;
	sub_82257DA8(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// blt cr6,0x82259ab8
	if (cr6.lt) goto loc_82259AB8;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8232adf8
	ctx.lr = 0x82259A80;
	sub_8232ADF8(ctx, base);
	// lwz r11,-5084(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -5084);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lfs f0,48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 48);
	f0.f64 = double(temp.f32);
	// stfs f0,116(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 116, temp.u32);
	// lfs f13,128(r30)
	temp.u32 = PPC_LOAD_U32(r30.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// bl 0x8232adf8
	ctx.lr = 0x82259AA0;
	sub_8232ADF8(ctx, base);
	// rlwinm r11,r26,1,0,30
	r11.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r26,r11
	r11.u64 = r26.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r28
	r11.u64 = r11.u64 + r28.u64;
	// addi r29,r11,16
	r29.s64 = r11.s64 + 16;
	// mr r24,r29
	r24.u64 = r29.u64;
loc_82259AB8:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82259ac4
	if (cr6.eq) goto loc_82259AC4;
	// stw r22,32(r25)
	PPC_STORE_U32(r25.u32 + 32, r22.u32);
loc_82259AC4:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82259ad0
	if (cr6.eq) goto loc_82259AD0;
	// stw r23,32(r24)
	PPC_STORE_U32(r24.u32 + 32, r23.u32);
loc_82259AD0:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82259b1c
	if (cr6.eq) goto loc_82259B1C;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r9,8
	ctx.r9.s64 = 8;
	// lwz r8,4(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r23,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r23.u32);
	// stw r22,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r22.u32);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// bl 0x822578f8
	ctx.lr = 0x82259B14;
	sub_822578F8(ctx, base);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
loc_82259B1C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,-12780
	ctx.r3.s64 = r11.s64 + -12780;
	// bl 0x82130000
	ctx.lr = 0x82259B28;
	sub_82130000(ctx, base);
loc_82259B28:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_822598E0) {
	__imp__sub_822598E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259B30) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r31,-5064(r11)
	PPC_STORE_U32(r11.u32 + -5064, r31.u32);
	// bl 0x82258b50
	ctx.lr = 0x82259B58;
	sub_82258B50(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x822578f8
	ctx.lr = 0x82259B80;
	sub_822578F8(ctx, base);
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

PPC_WEAK_FUNC(sub_82259B30) {
	__imp__sub_82259B30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259B98) {
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
	// lwz r31,0(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r31,-5064(r11)
	PPC_STORE_U32(r11.u32 + -5064, r31.u32);
	// bl 0x82258b50
	ctx.lr = 0x82259BC4;
	sub_82258B50(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// li r10,7
	ctx.r10.s64 = 7;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x822578f8
	ctx.lr = 0x82259BEC;
	sub_822578F8(ctx, base);
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

PPC_WEAK_FUNC(sub_82259B98) {
	__imp__sub_82259B98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259C04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82259C04) {
	__imp__sub_82259C04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259C08) {
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
	ctx.lr = 0x82259C10;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x82257da8
	ctx.lr = 0x82259C20;
	sub_82257DA8(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// li r29,-1
	r29.s64 = -1;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82259c6c
	if (cr6.lt) goto loc_82259C6C;
	// rlwinm r11,r3,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r3,r11
	r11.u64 = ctx.r3.u64 + r11.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r10,r11,16
	ctx.r10.s64 = r11.s64 + 16;
	// stw r31,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r31.u32);
	// stw r31,48(r11)
	PPC_STORE_U32(r11.u32 + 48, r31.u32);
	// stw r31,60(r11)
	PPC_STORE_U32(r11.u32 + 60, r31.u32);
	// stw r31,64(r11)
	PPC_STORE_U32(r11.u32 + 64, r31.u32);
	// stw r29,20(r11)
	PPC_STORE_U32(r11.u32 + 20, r29.u32);
	// stw r29,24(r11)
	PPC_STORE_U32(r11.u32 + 24, r29.u32);
	// lwz r27,52(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x82237910
	ctx.lr = 0x82259C64;
	sub_82237910(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82238140
	ctx.lr = 0x82259C6C;
	sub_82238140(ctx, base);
loc_82259C6C:
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82259cc0
	if (cr6.eq) goto loc_82259CC0;
	// lwz r3,68(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82259c8c
	if (cr6.eq) goto loc_82259C8C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8232adf8
	ctx.lr = 0x82259C8C;
	sub_8232ADF8(ctx, base);
loc_82259C8C:
	// lwz r11,48(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x82257af0
	ctx.lr = 0x82259CA0;
	sub_82257AF0(ctx, base);
	// lwz r9,48(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r3,20(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// lfs f1,-6432(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + -6432);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,16(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82259CC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82259CC0:
	// li r11,10
	r11.s64 = 10;
	// stw r28,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r28.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r29,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r29.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x822578f8
	ctx.lr = 0x82259CE4;
	sub_822578F8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_82259C08) {
	__imp__sub_82259C08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259CEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82259CEC) {
	__imp__sub_82259CEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259CF0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r31{};
	PPCRegister f0{};
	PPCVRegister v61{};
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// rlwinm r10,r4,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lvx128 v127,r10,r8
	simde_mm_store_si128((simde__m128i*)v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v127,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82259dbc
	if (cr6.eq) goto loc_82259DBC;
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// ble cr6,0x82259dbc
	if (!cr6.gt) goto loc_82259DBC;
	// extsw r11,r5
	r11.s64 = ctx.r5.s32;
	// extsw r10,r6
	ctx.r10.s64 = ctx.r6.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f0
	ctx.f10.f64 = double(f0.s64);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// lfs f12,7444(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 7444);
	ctx.f12.f64 = double(temp.f32);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,3796(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lfs f13,-12736(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -12736);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,30284(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 30284);
	f0.f64 = double(temp.f32);
	// lfs f13,27644(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 27644);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f7,f9,f12
	ctx.f7.f64 = double(float(ctx.f9.f64 - ctx.f12.f64));
	// fdivs f6,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 / ctx.f7.f64));
	// fmuls f5,f6,f0
	ctx.f5.f64 = double(float(ctx.f6.f64 * f0.f64));
	// fmuls f1,f5,f13
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f13.f64));
	// bl 0x8216c890
	ctx.lr = 0x82259DA8;
	sub_8216C890(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v127,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(v62.f32, simde_mm_add_ps(simde_mm_load_ps(v127.f32), simde_mm_load_ps(v63.f32)));
	// stvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82259DBC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f2,32668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32668);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,27640(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 27640);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82257bf8
	ctx.lr = 0x82259DD4;
	sub_82257BF8(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

PPC_WEAK_FUNC(sub_82259CF0) {
	__imp__sub_82259CF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259DFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82259DFC) {
	__imp__sub_82259DFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259E00) {
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
	// addi r10,r11,-5028
	ctx.r10.s64 = r11.s64 + -5028;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82259e68
	if (cr6.eq) goto loc_82259E68;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32255
	ctx.r8.s64 = -2113863680;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// addi r5,r8,5276
	ctx.r5.s64 = ctx.r8.s64 + 5276;
	// lwz r7,-5084(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + -5084);
	// addi r4,r4,-12708
	ctx.r4.s64 = ctx.r4.s64 + -12708;
	// lwz r6,-5092(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5092);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,2828(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2828);
	// bl 0x821c04b0
	ctx.lr = 0x82259E54;
	sub_821C04B0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82259E68:
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r31,r11,30576
	r31.s64 = r11.s64 + 30576;
	// addi r4,r10,-12720
	ctx.r4.s64 = ctx.r10.s64 + -12720;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821ca540
	ctx.lr = 0x82259E80;
	sub_821CA540(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r6,-5092(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + -5092);
	// addi r5,r11,5276
	ctx.r5.s64 = r11.s64 + 5276;
	// addi r4,r10,-12732
	ctx.r4.s64 = ctx.r10.s64 + -12732;
	// lwz r7,-5084(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + -5084);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,2828(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2828);
	// bl 0x821c04b0
	ctx.lr = 0x82259EB0;
	sub_821C04B0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9a90
	ctx.lr = 0x82259EB8;
	sub_821C9A90(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_82259E00) {
	__imp__sub_82259E00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_82259ECC) {
	__imp__sub_82259ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_82259ED0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82257d28
	sub_82257D28(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_82259ED0) {
	__imp__sub_82259ED0(ctx, base);
}

