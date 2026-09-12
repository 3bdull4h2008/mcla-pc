#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82288A08"))) PPC_WEAK_FUNC(sub_82288A08);
PPC_FUNC_IMPL(__imp__sub_82288A08) {
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
	ctx.lr = 0x82288A10;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268f078
	ctx.lr = 0x82288A28;
	sub_8268F078(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r10,7
	ctx.r10.s64 = 7;
	// lwz r27,80(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// addi r9,r11,-12116
	ctx.r9.s64 = r11.s64 + -12116;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// bl 0x821c9790
	ctx.lr = 0x82288A58;
	sub_821C9790(ctx, base);
	// li r26,1
	r26.s64 = 1;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stw r26,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r26.u32);
	// lwz r7,0(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r6,496(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 496);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82288A78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82288A90;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef9f0
	ctx.lr = 0x82288A98;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82288AAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82287948
	ctx.lr = 0x82288ABC;
	sub_82287948(ctx, base);
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,108(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 108);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82288AD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,36(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// lwz r30,48(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82288AE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,344(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 344);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82288AFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82288b38
	if (cr6.lt) goto loc_82288B38;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r27,17268(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82288B1C;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82288b38
	if (cr6.eq) goto loc_82288B38;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822a3998
	ctx.lr = 0x82288B34;
	sub_822A3998(ctx, base);
	// b 0x82288b3c
	goto loc_82288B3C;
loc_82288B38:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82288B3C:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82288B4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82288b60
	if (cr6.eq) goto loc_82288B60;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// stw r28,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r28.u32);
loc_82288B60:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-19624
	ctx.r4.s64 = r11.s64 + -19624;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x82288B74;
	sub_8268DA78(ctx, base);
	// li r30,6
	r30.s64 = 6;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82288b8c
	if (cr6.eq) goto loc_82288B8C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_82288B8C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2824
	ctx.r4.s64 = r11.s64 + 2824;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x82288BA0;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82288bc4
	if (cr6.eq) goto loc_82288BC4;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82288bbc
	if (!cr6.eq) goto loc_82288BBC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r11,r11,3998
	r11.s64 = r11.s64 + 3998;
loc_82288BBC:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_82288BC4:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2812
	ctx.r4.s64 = r11.s64 + 2812;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x82288BD8;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82288bec
	if (cr6.eq) goto loc_82288BEC;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_82288BEC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2800
	ctx.r4.s64 = r11.s64 + 2800;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x82288C00;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82288c2c
	if (cr6.eq) goto loc_82288C2C;
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82288c20
	if (cr6.eq) goto loc_82288C20;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82288c24
	if (!cr6.eq) goto loc_82288C24;
loc_82288C20:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
loc_82288C24:
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
loc_82288C2C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2792
	ctx.r4.s64 = r11.s64 + 2792;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x82288C40;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82288c54
	if (cr6.eq) goto loc_82288C54;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_82288C54:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2776
	ctx.r4.s64 = r11.s64 + 2776;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x82288C68;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82288c7c
	if (cr6.eq) goto loc_82288C7C;
	// lwz r11,40(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_82288C7C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,2752
	ctx.r4.s64 = r11.s64 + 2752;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x82288C90;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82288ca4
	if (cr6.eq) goto loc_82288CA4;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// stw r26,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r26.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
loc_82288CA4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82288CAC"))) PPC_WEAK_FUNC(sub_82288CAC);
PPC_FUNC_IMPL(__imp__sub_82288CAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82288CB0"))) PPC_WEAK_FUNC(sub_82288CB0);
PPC_FUNC_IMPL(__imp__sub_82288CB0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	ctx.lr = 0x82288CB8;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r9,-2628
	ctx.r4.s64 = ctx.r9.s64 + -2628;
	// lwz r11,-3624(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -3624);
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r27,700(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x822701c8
	ctx.lr = 0x82288CE0;
	sub_822701C8(ctx, base);
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r7,468(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 468);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82288CF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228907c
	if (cr6.eq) goto loc_8228907C;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82288D14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228907c
	if (cr6.eq) goto loc_8228907C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228907c
	if (cr6.eq) goto loc_8228907C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82288D30;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228907c
	if (cr6.eq) goto loc_8228907C;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x8228907c
	if (cr6.eq) goto loc_8228907C;
	// li r19,0
	r19.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82288d60
	if (!cr6.eq) goto loc_82288D60;
	// bl 0x82256058
	ctx.lr = 0x82288D58;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82288d64
	if (cr6.eq) goto loc_82288D64;
loc_82288D60:
	// stb r19,132(r29)
	PPC_STORE_U8(r29.u32 + 132, r19.u8);
loc_82288D64:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,672(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 672);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82288D78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r18,-1
	r18.s64 = -1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82288d8c
	if (!cr6.eq) goto loc_82288D8C;
	// stw r18,112(r29)
	PPC_STORE_U32(r29.u32 + 112, r18.u32);
loc_82288D8C:
	// lwz r11,112(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 112);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r31,r8,1
	r31.u64 = ctx.r8.u64 ^ 1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82286ab8
	ctx.lr = 0x82288DAC;
	sub_82286AB8(ctx, base);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,496(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 496);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82288DC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// stw r3,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r3.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r4,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// lwz r11,496(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 496);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82288DE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,12(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// lis r9,-32138
	ctx.r9.s64 = -2106195968;
	// stw r19,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r19.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r9,9352
	ctx.r7.s64 = ctx.r9.s64 + 9352;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// stw r10,68(r29)
	PPC_STORE_U32(r29.u32 + 68, ctx.r10.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// ld r5,0(r8)
	ctx.r5.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// bl 0x82220308
	ctx.lr = 0x82288E14;
	sub_82220308(ctx, base);
	// lwz r6,16(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// lis r11,-32255
	r11.s64 = -2113863680;
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// addi r28,r11,-13284
	r28.s64 = r11.s64 + -13284;
	// bne cr6,0x82288e58
	if (!cr6.eq) goto loc_82288E58;
	// lwz r11,24(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82288e58
	if (!cr6.eq) goto loc_82288E58;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// li r10,2
	ctx.r10.s64 = 2;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82288E58;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82288E58:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228901c
	if (cr6.eq) goto loc_8228901C;
	// lwz r11,-3624(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -3624);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lwz r9,0(r17)
	ctx.r9.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// li r8,-10
	ctx.r8.s64 = -10;
	// addi r4,r10,620
	ctx.r4.s64 = ctx.r10.s64 + 620;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r6,44(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// lwz r20,36(r7)
	r20.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82288E98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82288ec0
	if (!cr6.eq) goto loc_82288EC0;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r19,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r19.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x82289018
	goto loc_82289018;
loc_82288EC0:
	// cmplw cr6,r30,r20
	cr6.compare<uint32_t>(r30.u32, r20.u32, xer);
	// bge cr6,0x8228901c
	if (!cr6.lt) goto loc_8228901C;
	// li r11,7
	r11.s64 = 7;
	// stw r19,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r19.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-12116
	ctx.r4.s64 = ctx.r10.s64 + -12116;
	// bl 0x82202fb8
	ctx.lr = 0x82288EE4;
	sub_82202FB8(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,496(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 496);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82288EF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82288F10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef9f0
	ctx.lr = 0x82288F18;
	sub_825EF9F0(ctx, base);
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
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32255
	ctx.r4.s64 = -2113863680;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// addi r28,r11,2640
	r28.s64 = r11.s64 + 2640;
	// addi r27,r10,2556
	r27.s64 = ctx.r10.s64 + 2556;
	// addi r26,r9,2664
	r26.s64 = ctx.r9.s64 + 2664;
	// addi r25,r8,2836
	r25.s64 = ctx.r8.s64 + 2836;
	// addi r24,r7,2688
	r24.s64 = ctx.r7.s64 + 2688;
	// addi r23,r6,2680
	r23.s64 = ctx.r6.s64 + 2680;
	// addi r22,r5,2672
	r22.s64 = ctx.r5.s64 + 2672;
	// addi r31,r4,-14360
	r31.s64 = ctx.r4.s64 + -14360;
loc_82288F5C:
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82288F74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// bl 0x827227b8
	ctx.lr = 0x82288F84;
	sub_827227B8(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x827227b8
	ctx.lr = 0x82288F94;
	sub_827227B8(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x827227b8
	ctx.lr = 0x82288FA4;
	sub_827227B8(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bl 0x827227b8
	ctx.lr = 0x82288FB4;
	sub_827227B8(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x827227b8
	ctx.lr = 0x82288FC4;
	sub_827227B8(ctx, base);
	// stw r18,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r18.u32);
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x82288FD8;
	sub_82722678(ctx, base);
	// stw r19,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r19.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x82722678
	ctx.lr = 0x82288FEC;
	sub_82722678(ctx, base);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmplw cr6,r30,r20
	cr6.compare<uint32_t>(r30.u32, r20.u32, xer);
	// blt cr6,0x82288f5c
	if (cr6.lt) goto loc_82288F5C;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r20.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,-10308
	ctx.r4.s64 = ctx.r10.s64 + -10308;
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_82289018:
	// bctrl 
	ctx.lr = 0x8228901C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228901C:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r31,r10,-10300
	r31.s64 = ctx.r10.s64 + -10300;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82289038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82289044;
	sub_825EE0E0(ctx, base);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// lwz r6,496(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 496);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82289060;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r4,-32254
	ctx.r4.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r4,20304
	ctx.r4.s64 = ctx.r4.s64 + 20304;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228907C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228907C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9218
	return;
}

__attribute__((alias("__imp__sub_82289084"))) PPC_WEAK_FUNC(sub_82289084);
PPC_FUNC_IMPL(__imp__sub_82289084) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82289088"))) PPC_WEAK_FUNC(sub_82289088);
PPC_FUNC_IMPL(__imp__sub_82289088) {
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
	ctx.lr = 0x82289090;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635f18
	ctx.lr = 0x8228909C;
	sub_82635F18(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r3,r11,-12116
	ctx.r3.s64 = r11.s64 + -12116;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r9,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r9.u32);
	// bl 0x821c9790
	ctx.lr = 0x822890C0;
	sub_821C9790(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// lwz r6,496(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 496);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822890E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822890F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef9f0
	ctx.lr = 0x82289100;
	sub_825EF9F0(ctx, base);
	// stw r3,144(r31)
	PPC_STORE_U32(r31.u32 + 144, ctx.r3.u32);
	// addi r26,r31,132
	r26.s64 = r31.s64 + 132;
	// li r28,31
	r28.s64 = 31;
loc_8228910C:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x82289114;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82289128
	if (cr6.eq) goto loc_82289128;
	// bl 0x8221d330
	ctx.lr = 0x82289120;
	sub_8221D330(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x8228912c
	goto loc_8228912C;
loc_82289128:
	// li r30,0
	r30.s64 = 0;
loc_8228912C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r29,r30,48
	r29.s64 = r30.s64 + 48;
	// lwz r27,48(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,468(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82289148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,196(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 196);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228915C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,496(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 496);
	// lwz r27,48(r30)
	r27.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82289174;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r6,508(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 508);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82289188;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8262e420
	ctx.lr = 0x82289194;
	sub_8262E420(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// bne 0x8228910c
	if (!cr0.eq) goto loc_8228910C;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822891A8"))) PPC_WEAK_FUNC(sub_822891A8);
PPC_FUNC_IMPL(__imp__sub_822891A8) {
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
	ctx.lr = 0x822891B0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,116(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822891CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r26,0
	r26.s64 = 0;
	// lwz r4,116(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r29,r26
	r29.u64 = r26.u64;
	// lwz r8,480(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 480);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822891EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82289268
	if (cr6.eq) goto loc_82289268;
	// addi r27,r30,132
	r27.s64 = r30.s64 + 132;
loc_822891FC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82289210;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82289230
	if (cr6.eq) goto loc_82289230;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82289230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82289230:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82289244;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r28,r31,-48
	r28.s64 = r31.s64 + -48;
	// bl 0x8262e420
	ctx.lr = 0x82289254;
	sub_8262E420(ctx, base);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822891fc
	if (!cr6.eq) goto loc_822891FC;
loc_82289268:
	// lwz r11,80(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 80);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r4,r29,r11
	ctx.r4.s64 = r11.s64 - r29.s64;
	// stw r4,80(r30)
	PPC_STORE_U32(r30.u32 + 80, ctx.r4.u32);
	// lwz r9,572(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 572);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82289288;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,116(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822892bc
	if (cr6.eq) goto loc_822892BC;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,480(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 480);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822892AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r26,36(r3)
	PPC_STORE_U32(ctx.r3.u32 + 36, r26.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822892BC:
	// stw r26,44(r30)
	PPC_STORE_U32(r30.u32 + 44, r26.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822892CC"))) PPC_WEAK_FUNC(sub_822892CC);
PPC_FUNC_IMPL(__imp__sub_822892CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822892D0"))) PPC_WEAK_FUNC(sub_822892D0);
PPC_FUNC_IMPL(__imp__sub_822892D0) {
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
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// addi r9,r11,5568
	ctx.r9.s64 = r11.s64 + 5568;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x82289304
	if (cr6.eq) goto loc_82289304;
	// bl 0x82130588
	ctx.lr = 0x82289300;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82289304:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82289318"))) PPC_WEAK_FUNC(sub_82289318);
PPC_FUNC_IMPL(__imp__sub_82289318) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// beq cr6,0x82289344
	if (cr6.eq) goto loc_82289344;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// bltlr cr6
	if (cr6.lt) return;
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
loc_82289344:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// bgelr 
	if (!cr0.lt) return;
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228935C"))) PPC_WEAK_FUNC(sub_8228935C);
PPC_FUNC_IMPL(__imp__sub_8228935C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82289360"))) PPC_WEAK_FUNC(sub_82289360);
PPC_FUNC_IMPL(__imp__sub_82289360) {
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
	// lbz r11,28(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289420
	if (cr6.eq) goto loc_82289420;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82289394;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82289420
	if (cr6.eq) goto loc_82289420;
	// bl 0x822a7cc8
	ctx.lr = 0x822893A4;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289420
	if (cr6.eq) goto loc_82289420;
	// lbz r11,17(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822893cc
	if (!cr6.eq) goto loc_822893CC;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x822893d0
	if (cr6.eq) goto loc_822893D0;
loc_822893CC:
	// li r11,1
	r11.s64 = 1;
loc_822893D0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82289420
	if (!cr6.eq) goto loc_82289420;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a8710
	ctx.lr = 0x822893E4;
	sub_822A8710(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289420
	if (cr6.eq) goto loc_82289420;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a86e8
	ctx.lr = 0x822893F8;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289420
	if (cr6.eq) goto loc_82289420;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,41
	ctx.r4.s64 = 41;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82289418;
	sub_8268EE10(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,28(r30)
	PPC_STORE_U8(r30.u32 + 28, r11.u8);
loc_82289420:
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

__attribute__((alias("__imp__sub_82289438"))) PPC_WEAK_FUNC(sub_82289438);
PPC_FUNC_IMPL(__imp__sub_82289438) {
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
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8228947c
	if (cr6.eq) goto loc_8228947C;
	// addi r3,r4,16
	ctx.r3.s64 = ctx.r4.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8228945C;
	sub_824E7110(ctx, base);
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// bne cr6,0x8228947c
	if (!cr6.eq) goto loc_8228947C;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,23
	ctx.r4.s64 = 23;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268ee10
	ctx.lr = 0x8228947C;
	sub_8268EE10(ctx, base);
loc_8228947C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82289490"))) PPC_WEAK_FUNC(sub_82289490);
PPC_FUNC_IMPL(__imp__sub_82289490) {
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
	ctx.lr = 0x82289498;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r30,r28
	r30.u64 = r28.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x822894B0;
	sub_8268DCB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82289528
	if (cr6.eq) goto loc_82289528;
	// li r29,-1
	r29.s64 = -1;
loc_822894C0:
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// stw r28,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r28.u32);
	// bl 0x82387b90
	ctx.lr = 0x822894D0;
	sub_82387B90(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x8238aec0
	ctx.lr = 0x822894DC;
	sub_8238AEC0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82289504
	if (cr6.lt) goto loc_82289504;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r9,r11,0,28,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// lwz r8,84(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 84);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x82289514
	goto loc_82289514;
loc_82289504:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
loc_82289514:
	// bctrl 
	ctx.lr = 0x82289518;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822894c0
	if (!cr6.eq) goto loc_822894C0;
loc_82289528:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82289530"))) PPC_WEAK_FUNC(sub_82289530);
PPC_FUNC_IMPL(__imp__sub_82289530) {
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
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x82289538;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lwz r31,1220(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82289968
	if (cr6.eq) goto loc_82289968;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a91e0
	ctx.lr = 0x82289568;
	sub_822A91E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82289968
	if (!cr6.eq) goto loc_82289968;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82289968
	if (cr6.eq) goto loc_82289968;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82289584;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82289968
	if (!cr6.eq) goto loc_82289968;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82289968
	if (!cr6.eq) goto loc_82289968;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x822895A4;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289968
	if (cr6.eq) goto loc_82289968;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822895d0
	if (cr6.eq) goto loc_822895D0;
	// addi r11,r11,208
	r11.s64 = r11.s64 + 208;
	// b 0x822895d4
	goto loc_822895D4;
loc_822895D0:
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
loc_822895D4:
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// lis r8,-32119
	ctx.r8.s64 = -2104950784;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,184(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-17936(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -17936);
	// lfs f12,176(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// lwz r10,-8092(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8092);
	// addi r4,r11,45
	ctx.r4.s64 = r11.s64 + 45;
	// lfs f30,180(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	f30.f64 = double(temp.f32);
	// lfs f0,-16984(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + -16984);
	f0.f64 = double(temp.f32);
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f31,7444(r5)
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + 7444);
	f31.f64 = double(temp.f32);
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r11,r8,112
	r11.s64 = ctx.r8.s64 + 112;
	// lfs f11,116(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 116);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f30
	ctx.f10.f64 = double(float(ctx.f11.f64 - f30.f64));
	// lfs f9,120(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 120);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f13
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f13.f64));
	// lfs f7,112(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// fmuls f6,f10,f10
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fsubs f5,f7,f12
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f12.f64));
	// fmadds f4,f8,f8,f6
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fmadds f3,f5,f5,f4
	ctx.f3.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f4.f64));
	// fsqrts f2,f3
	ctx.f2.f64 = double(float(sqrt(ctx.f3.f64)));
	// fdivs f0,f2,f0
	f0.f64 = double(float(ctx.f2.f64 / f0.f64));
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// ble cr6,0x82289658
	if (!cr6.gt) goto loc_82289658;
	// fmr f0,f31
	f0.f64 = f31.f64;
loc_82289658:
	// fsubs f13,f31,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f31.f64 - f0.f64));
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r11
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(v61.f32, simde_mm_sub_ps(simde_mm_load_ps(v63.f32), simde_mm_load_ps(v62.f32)));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// stvx128 v61,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82289968
	if (cr6.eq) goto loc_82289968;
	// lfs f13,104(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,120(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f12.f64));
	// lfs f10,100(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 100);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,96(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	ctx.f8.f64 = double(temp.f32);
	// lfs f7,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f7.f64 = double(temp.f32);
	// fmadds f6,f10,f9,f11
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f9.f64 + ctx.f11.f64));
	// fmadds f5,f7,f8,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fcmpu cr6,f5,f0
	cr6.compare(ctx.f5.f64, f0.f64);
	// bgt cr6,0x82289968
	if (cr6.gt) goto loc_82289968;
	// vspltisw128 v60,0
	simde_mm_store_si128((simde__m128i*)v60.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,192
	r11.s64 = ctx.r1.s64 + 192;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// lwzx r31,r9,r10
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// vupkd3d128 v59,v60,4
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += v60.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	v59 = vTemp;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x15));
	// vpermwi128 v57,v59,186
	simde_mm_store_si128((simde__m128i*)v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x45));
	// vpermwi128 v56,v59,174
	simde_mm_store_si128((simde__m128i*)v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x51));
	// vpermwi128 v55,v59,171
	simde_mm_store_si128((simde__m128i*)v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)v59.u32), 0x54));
	// stvx128 v58,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v57,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v57.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v56,r0,r7
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r7.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v56.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v55,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v55.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217c568
	ctx.lr = 0x822896F0;
	sub_8217C568(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r31,384
	ctx.r5.s64 = r31.s64 + 384;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// bl 0x8215e000
	ctx.lr = 0x82289700;
	sub_8215E000(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r11,15748(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 15748);
	// lfs f0,-16988(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r5.u32 + -16988);
	f0.f64 = double(temp.f32);
	// clrlwi r4,r11,31
	ctx.r4.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x82289734
	if (!cr6.eq) goto loc_82289734;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// fmr f13,f0
	ctx.f13.f64 = f0.f64;
	// stfs f13,15744(r9)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r9.u32 + 15744, temp.u32);
	// stw r11,15748(r10)
	PPC_STORE_U32(ctx.r10.u32 + 15748, r11.u32);
	// b 0x82289738
	goto loc_82289738;
loc_82289734:
	// lfs f13,15744(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15744);
	ctx.f13.f64 = double(temp.f32);
loc_82289738:
	// rlwinm r8,r11,0,30,30
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82289758
	if (!cr6.eq) goto loc_82289758;
	// ori r11,r11,2
	r11.u64 = r11.u64 | 2;
	// stfs f0,15740(r9)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r9.u32 + 15740, temp.u32);
	// stw r11,15748(r10)
	PPC_STORE_U32(ctx.r10.u32 + 15748, r11.u32);
	// b 0x8228975c
	goto loc_8228975C;
loc_82289758:
	// lfs f0,15740(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 15740);
	f0.f64 = double(temp.f32);
loc_8228975C:
	// lwz r11,48(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82289794
	if (cr6.eq) goto loc_82289794;
	// lwz r11,68(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82289794
	if (cr6.eq) goto loc_82289794;
	// lbz r10,113(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 113);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228978c
	if (!cr6.eq) goto loc_8228978C;
	// lbz r11,114(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 114);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289794
	if (cr6.eq) goto loc_82289794;
loc_8228978C:
	// fadds f0,f0,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + f30.f64));
	// b 0x82289798
	goto loc_82289798;
loc_82289794:
	// fadds f0,f13,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f13.f64 + f30.f64));
loc_82289798:
	// addi r11,r1,176
	r11.s64 = ctx.r1.s64 + 176;
	// stfs f0,180(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v1,r0,r11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8217bd00
	ctx.lr = 0x822897B0;
	sub_8217BD00(ctx, base);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v54,r0,r3
	simde_mm_store_si128((simde__m128i*)v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// stvx128 v54,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v54.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,80(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// lfs f0,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f0.f64 = double(temp.f32);
	// fadds f11,f0,f31
	ctx.f11.f64 = double(float(f0.f64 + f31.f64));
	// fadds f12,f13,f31
	ctx.f12.f64 = double(float(ctx.f13.f64 + f31.f64));
	// lfs f0,14884(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14884);
	f0.f64 = double(temp.f32);
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * f0.f64));
	// lfs f13,5640(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 5640);
	ctx.f13.f64 = double(temp.f32);
	// addi r27,r5,5624
	r27.s64 = ctx.r5.s64 + 5624;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fnmsubs f10,f12,f0,f31
	ctx.f10.f64 = double(float(-(ctx.f12.f64 * f0.f64 - f31.f64)));
	// lfs f12,5636(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 5636);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f7,f9,f13
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// stfs f7,96(r1)
	temp.f32 = float(ctx.f7.f64);
	PPC_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmuls f8,f10,f12
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f8,100(r1)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82289820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82722718
	ctx.lr = 0x8228982C;
	sub_82722718(ctx, base);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r31,r1,100
	r31.s64 = ctx.r1.s64 + 100;
	// addi r27,r10,5612
	r27.s64 = ctx.r10.s64 + 5612;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82289850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82722718
	ctx.lr = 0x8228985C;
	sub_82722718(ctx, base);
	// li r7,-1
	ctx.r7.s64 = -1;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// lwz r11,-3624(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e0b0
	ctx.lr = 0x82289874;
	sub_8227E0B0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82289890
	if (cr6.eq) goto loc_82289890;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a5ab8
	ctx.lr = 0x82289888;
	sub_822A5AB8(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// b 0x82289898
	goto loc_82289898;
loc_82289890:
	// li r11,0
	r11.s64 = 0;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
loc_82289898:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r27,r1,92
	r27.s64 = ctx.r1.s64 + 92;
	// addi r31,r11,5596
	r31.s64 = r11.s64 + 5596;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,80(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822898BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82722398
	ctx.lr = 0x822898C8;
	sub_82722398(ctx, base);
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpw cr6,r8,r7
	cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, xer);
	// beq cr6,0x82289914
	if (cr6.eq) goto loc_82289914;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r27,r1,84
	r27.s64 = ctx.r1.s64 + 84;
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822898F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82722678
	ctx.lr = 0x82289900;
	sub_82722678(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r9,20304
	ctx.r4.s64 = ctx.r9.s64 + 20304;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x827205a8
	ctx.lr = 0x82289914;
	sub_827205A8(ctx, base);
loc_82289914:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lfs f13,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// addi r31,r1,88
	r31.s64 = ctx.r1.s64 + 88;
	// addi r30,r9,5580
	r30.s64 = ctx.r9.s64 + 5580;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// lwz r8,80(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 80);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8228994C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82722718
	ctx.lr = 0x82289958;
	sub_82722718(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82289968:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r4,136(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// addi r31,r10,5580
	r31.s64 = ctx.r10.s64 + 5580;
	// lwz r8,80(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82289994;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82722678
	ctx.lr = 0x822899A0;
	sub_82722678(ctx, base);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822899B0"))) PPC_WEAK_FUNC(sub_822899B0);
PPC_FUNC_IMPL(__imp__sub_822899B0) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r11,r6
	r11.u64 = ctx.r6.u64;
	// addi r10,r10,5644
	ctx.r10.s64 = ctx.r10.s64 + 5644;
loc_822899D4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822899f8
	if (cr6.eq) goto loc_822899F8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x822899d4
	if (cr6.eq) goto loc_822899D4;
loc_822899F8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82289a24
	if (!cr6.eq) goto loc_82289A24;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// bl 0x82691650
	ctx.lr = 0x82289A08;
	sub_82691650(ctx, base);
	// stw r3,68(r31)
	PPC_STORE_U32(r31.u32 + 68, ctx.r3.u32);
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
loc_82289A24:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82639498
	ctx.lr = 0x82289A30;
	sub_82639498(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82289A44"))) PPC_WEAK_FUNC(sub_82289A44);
PPC_FUNC_IMPL(__imp__sub_82289A44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82289A48"))) PPC_WEAK_FUNC(sub_82289A48);
PPC_FUNC_IMPL(__imp__sub_82289A48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lwz r12,0(r3)
	r12.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,796(r12)
	r11.u64 = PPC_LOAD_U32(r12.u32 + 796);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82289A58"))) PPC_WEAK_FUNC(sub_82289A58);
PPC_FUNC_IMPL(__imp__sub_82289A58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r5,r10,5668
	ctx.r5.s64 = ctx.r10.s64 + 5668;
	// addi r4,r9,-7984
	ctx.r4.s64 = ctx.r9.s64 + -7984;
	// addi r10,r8,-8160
	ctx.r10.s64 = ctx.r8.s64 + -8160;
	// stw r5,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r5.u32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// stw r4,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// li r11,0
	r11.s64 = 0;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// addi r9,r7,5660
	ctx.r9.s64 = ctx.r7.s64 + 5660;
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// stb r11,28(r3)
	PPC_STORE_U8(ctx.r3.u32 + 28, r11.u8);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// lwz r11,-8164(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -8164);
	// stw r11,30116(r8)
	PPC_STORE_U32(ctx.r8.u32 + 30116, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82289AB0"))) PPC_WEAK_FUNC(sub_82289AB0);
PPC_FUNC_IMPL(__imp__sub_82289AB0) {
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
	ctx.lr = 0x82289AB8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x82289ACC;
	sub_82388580(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82289ADC;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82289AE4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289dec
	if (cr6.eq) goto loc_82289DEC;
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r30,r11,2280
	r30.s64 = r11.s64 + 2280;
	// beq cr6,0x82289b24
	if (cr6.eq) goto loc_82289B24;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r11,5704
	ctx.r4.s64 = r11.s64 + 5704;
	// bl 0x823d90b0
	ctx.lr = 0x82289B18;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82289b28
	if (!cr6.eq) goto loc_82289B28;
loc_82289B24:
	// li r11,0
	r11.s64 = 0;
loc_82289B28:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82289b60
	if (!cr6.eq) goto loc_82289B60;
	// lwz r31,72(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// cmpwi cr6,r31,-1
	cr6.compare<int32_t>(r31.s32, -1, xer);
	// beq cr6,0x82289b58
	if (cr6.eq) goto loc_82289B58;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r4,r11,5696
	ctx.r4.s64 = r11.s64 + 5696;
	// bl 0x82294ef8
	ctx.lr = 0x82289B50;
	sub_82294EF8(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// beq cr6,0x82289b60
	if (cr6.eq) goto loc_82289B60;
loc_82289B58:
	// li r11,0
	r11.s64 = 0;
	// b 0x82289b64
	goto loc_82289B64;
loc_82289B60:
	// li r11,1
	r11.s64 = 1;
loc_82289B64:
	// li r3,0
	ctx.r3.s64 = 0;
	// clrlwi r30,r11,24
	r30.u64 = r11.u32 & 0xFF;
	// bl 0x82388580
	ctx.lr = 0x82289B70;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82289B80;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82289B88;
	sub_824E70F0(ctx, base);
	// lwz r11,-10240(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82500ef8
	ctx.lr = 0x82289B98;
	sub_82500EF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82289BA4;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82289BB4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// addi r25,r1,80
	r25.s64 = ctx.r1.s64 + 80;
	// bl 0x821f8730
	ctx.lr = 0x82289BC0;
	sub_821F8730(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,16
	ctx.r5.s64 = 16;
	// bl 0x824e7240
	ctx.lr = 0x82289BCC;
	sub_824E7240(ctx, base);
	// lbz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// extsb r11,r9
	r11.s64 = ctx.r9.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82289c5c
	if (cr6.eq) goto loc_82289C5C;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lwz r9,-8164(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + -8164);
loc_82289BF0:
	// blt cr6,0x82289c48
	if (cr6.lt) goto loc_82289C48;
	// lbz r11,0(r9)
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289c24
	if (cr6.eq) goto loc_82289C24;
	// extsb r11,r11
	r11.s64 = r11.s8;
loc_82289C08:
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// beq cr6,0x82289c24
	if (cr6.eq) goto loc_82289C24;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbzx r11,r9,r10
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// extsb r11,r11
	r11.s64 = r11.s8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82289c08
	if (!cr6.eq) goto loc_82289C08;
loc_82289C24:
	// lbzx r11,r9,r10
	r11.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289c48
	if (cr6.eq) goto loc_82289C48;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// lbz r11,0(r7)
	r11.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// extsb r8,r11
	ctx.r8.s64 = r11.s8;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x82289bf0
	if (!cr6.eq) goto loc_82289BF0;
	// b 0x82289c5c
	goto loc_82289C5C;
loc_82289C48:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82289C5C;
	sub_8268EE10(ctx, base);
loc_82289C5C:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82289c70
	if (!cr6.eq) goto loc_82289C70;
loc_82289C68:
	// li r4,5
	ctx.r4.s64 = 5;
	// b 0x82289df0
	goto loc_82289DF0;
loc_82289C70:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289dcc
	if (cr6.eq) goto loc_82289DCC;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289c68
	if (cr6.eq) goto loc_82289C68;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82289cb0
	if (cr6.eq) goto loc_82289CB0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r11,5684
	ctx.r4.s64 = r11.s64 + 5684;
	// bl 0x823d90b0
	ctx.lr = 0x82289CA4;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82289cb4
	if (!cr6.eq) goto loc_82289CB4;
loc_82289CB0:
	// li r11,0
	r11.s64 = 0;
loc_82289CB4:
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82289cdc
	if (cr6.eq) goto loc_82289CDC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r4,r11,5672
	ctx.r4.s64 = r11.s64 + 5672;
	// bl 0x823d90b0
	ctx.lr = 0x82289CD0;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82289ce0
	if (!cr6.eq) goto loc_82289CE0;
loc_82289CDC:
	// li r11,0
	r11.s64 = 0;
loc_82289CE0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289d10
	if (cr6.eq) goto loc_82289D10;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82289CF8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82289D08;
	sub_82270170(ctx, base);
	// bl 0x82272e38
	ctx.lr = 0x82289D0C;
	sub_82272E38(ctx, base);
	// clrlwi r30,r3,31
	r30.u64 = ctx.r3.u32 & 0x1;
loc_82289D10:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82289d84
	if (cr6.eq) goto loc_82289D84;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82289D20;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82289D30;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272e60
	ctx.lr = 0x82289D38;
	sub_82272E60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82289d84
	if (!cr6.eq) goto loc_82289D84;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82289D4C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82289D5C;
	sub_82270170(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82272e60
	ctx.lr = 0x82289D64;
	sub_82272E60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82289d84
	if (!cr6.eq) goto loc_82289D84;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82289D84;
	sub_8268EE10(ctx, base);
loc_82289D84:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289db8
	if (cr6.eq) goto loc_82289DB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82289D98;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82289DA8;
	sub_82270170(ctx, base);
	// bl 0x82272e98
	ctx.lr = 0x82289DAC;
	sub_82272E98(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r9,r30,24
	ctx.r9.u64 = r30.u32 & 0xFF;
	// and r30,r10,r9
	r30.u64 = ctx.r10.u64 & ctx.r9.u64;
loc_82289DB8:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82289dcc
	if (!cr6.eq) goto loc_82289DCC;
	// li r4,6
	ctx.r4.s64 = 6;
	// b 0x82289df0
	goto loc_82289DF0;
loc_82289DCC:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82289DE0;
	sub_8268EE10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82289DEC:
	// li r4,4
	ctx.r4.s64 = 4;
loc_82289DF0:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82289E00;
	sub_8268EE10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82289E0C"))) PPC_WEAK_FUNC(sub_82289E0C);
PPC_FUNC_IMPL(__imp__sub_82289E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82289E10"))) PPC_WEAK_FUNC(sub_82289E10);
PPC_FUNC_IMPL(__imp__sub_82289E10) {
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
	ctx.lr = 0x82289E18;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x82294f78
	ctx.lr = 0x82289E30;
	sub_82294F78(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82289f18
	if (cr6.lt) goto loc_82289F18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r28,r11,4
	r28.s64 = r11.s64 + 4;
	// bne cr6,0x82289e54
	if (!cr6.eq) goto loc_82289E54;
	// li r28,0
	r28.s64 = 0;
loc_82289E54:
	// lwz r10,-10240(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mulli r9,r3,76
	ctx.r9.s64 = ctx.r3.s64 * 76;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,4304(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4304);
	// li r30,-1
	r30.s64 = -1;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// lwz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// add r29,r10,r9
	r29.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq cr6,0x82289f10
	if (cr6.eq) goto loc_82289F10;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82289ea4
	if (cr6.eq) goto loc_82289EA4;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x82289f14
	if (!cr6.eq) goto loc_82289F14;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,4(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82294ef8
	ctx.lr = 0x82289E94;
	sub_82294EF8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r30,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82289EA4:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c970
	ctx.lr = 0x82289EB0;
	sub_8268C970(ctx, base);
	// bl 0x8221cd00
	ctx.lr = 0x82289EB4;
	sub_8221CD00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82289f14
	if (cr6.eq) goto loc_82289F14;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c970
	ctx.lr = 0x82289ECC;
	sub_8268C970(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82289EDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82289f14
	if (!cr6.gt) goto loc_82289F14;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c970
	ctx.lr = 0x82289EF0;
	sub_8268C970(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82289F00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r3,-1
	r30.s64 = ctx.r3.s64 + -1;
	// stw r30,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r30.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82289F10:
	// lwz r30,4(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 4);
loc_82289F14:
	// stw r30,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r30.u32);
loc_82289F18:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82289F20"))) PPC_WEAK_FUNC(sub_82289F20);
PPC_FUNC_IMPL(__imp__sub_82289F20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d4
	ctx.lr = 0x82289F28;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r10,-28304
	ctx.r3.s64 = ctx.r10.s64 + -28304;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,-3624(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + -3624);
	// lwz r28,4304(r11)
	r28.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r21,28(r9)
	r21.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// addi r20,r11,2356
	r20.s64 = r11.s64 + 2356;
	// bl 0x82388178
	ctx.lr = 0x82289F64;
	sub_82388178(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r27,0
	r27.s64 = 0;
	// lwz r8,72(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x82289fdc
	if (!cr6.eq) goto loc_82289FDC;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r10,528(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 528);
	// addi r31,r11,456
	r31.s64 = r11.s64 + 456;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// lwz r9,-10236(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// addis r30,r8,3
	r30.s64 = ctx.r8.s64 + 196608;
	// addi r30,r30,-21024
	r30.s64 = r30.s64 + -21024;
	// beq cr6,0x82289fa8
	if (cr6.eq) goto loc_82289FA8;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
loc_82289FA8:
	// lwz r11,1136(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 1136);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82289fb8
	if (cr6.eq) goto loc_82289FB8;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
loc_82289FB8:
	// lwz r11,-3624(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x82283660
	ctx.lr = 0x82289FC4;
	sub_82283660(ctx, base);
	// lwz r11,72(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r4,r10,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x823974a8
	ctx.lr = 0x82289FDC;
	sub_823974A8(ctx, base);
loc_82289FDC:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r26,-1
	r26.s64 = -1;
	// mr r29,r27
	r29.u64 = r27.u64;
	// li r25,32
	r25.s64 = 32;
	// li r22,1
	r22.s64 = 1;
	// lwz r11,528(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 528);
	// addi r10,r11,-2
	ctx.r10.s64 = r11.s64 + -2;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// addi r23,r11,-2524
	r23.s64 = r11.s64 + -2524;
	// rlwinm r30,r9,27,31,31
	r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
loc_8228A008:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r31,r29,r11
	r31.u64 = r29.u64 + r11.u64;
	// lwz r10,72(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 72);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x8228a188
	if (!cr6.eq) goto loc_8228A188;
	// cmplwi cr6,r26,28
	cr6.compare<uint32_t>(r26.u32, 28, xer);
	// bgt cr6,0x8228a188
	if (cr6.gt) goto loc_8228A188;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,-24516
	r12.s64 = r12.s64 + -24516;
	// rlwinm r0,r26,2,0,29
	r0.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r26.u64) {
	case 0:
		goto loc_8228A0B0;
	case 1:
		goto loc_8228A184;
	case 2:
		goto loc_8228A184;
	case 3:
		goto loc_8228A0EC;
	case 4:
		goto loc_8228A124;
	case 5:
		goto loc_8228A184;
	case 6:
		goto loc_8228A188;
	case 7:
		goto loc_8228A100;
	case 8:
		goto loc_8228A184;
	case 9:
		goto loc_8228A184;
	case 10:
		goto loc_8228A174;
	case 11:
		goto loc_8228A184;
	case 12:
		goto loc_8228A184;
	case 13:
		goto loc_8228A184;
	case 14:
		goto loc_8228A188;
	case 15:
		goto loc_8228A188;
	case 16:
		goto loc_8228A188;
	case 17:
		goto loc_8228A188;
	case 18:
		goto loc_8228A188;
	case 19:
		goto loc_8228A188;
	case 20:
		goto loc_8228A188;
	case 21:
		goto loc_8228A188;
	case 22:
		goto loc_8228A188;
	case 23:
		goto loc_8228A124;
	case 24:
		goto loc_8228A124;
	case 25:
		goto loc_8228A13C;
	case 26:
		goto loc_8228A158;
	case 27:
		goto loc_8228A184;
	case 28:
		goto loc_8228A184;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-24400(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24400);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24340(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24340);
	// lwz r17,-24284(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24284);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24320(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24320);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24204(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24204);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24184(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24184);
	// lwz r17,-24284(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24284);
	// lwz r17,-24284(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24284);
	// lwz r17,-24260(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24260);
	// lwz r17,-24232(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24232);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
	// lwz r17,-24188(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -24188);
loc_8228A0B0:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r19,72(r20)
	r19.u64 = PPC_LOAD_U32(r20.u32 + 72);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82294ef8
	ctx.lr = 0x8228A0C0;
	sub_82294EF8(ctx, base);
	// cmpw cr6,r19,r3
	cr6.compare<int32_t>(r19.s32, ctx.r3.s32, xer);
	// bne cr6,0x8228a184
	if (!cr6.eq) goto loc_8228A184;
	// bl 0x82387b90
	ctx.lr = 0x8228A0CC;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// mulli r11,r11,8176
	r11.s64 = r11.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238f6b0
	ctx.lr = 0x8228A0E0;
	sub_8238F6B0(ctx, base);
	// subfic r10,r3,4
	xer.ca = ctx.r3.u32 <= 4;
	ctx.r10.s64 = 4 - ctx.r3.s64;
	// stw r10,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r10.u32);
	// b 0x8228a188
	goto loc_8228A188;
loc_8228A0EC:
	// lwz r11,680(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 680);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bgt cr6,0x8228a184
	if (cr6.gt) goto loc_8228A184;
	// stw r22,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r22.u32);
	// b 0x8228a188
	goto loc_8228A188;
loc_8228A100:
	// bl 0x8227d3b0
	ctx.lr = 0x8228A104;
	sub_8227D3B0(ctx, base);
	// cmplw cr6,r3,r21
	cr6.compare<uint32_t>(ctx.r3.u32, r21.u32, xer);
	// bge cr6,0x8228a118
	if (!cr6.lt) goto loc_8228A118;
	// bl 0x8227d3b0
	ctx.lr = 0x8228A110;
	sub_8227D3B0(ctx, base);
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// b 0x8228a188
	goto loc_8228A188;
loc_8228A118:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// stw r3,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r3.u32);
	// b 0x8228a188
	goto loc_8228A188;
loc_8228A124:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// b 0x8228a188
	goto loc_8228A188;
loc_8228A13C:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r8,r9,0,28,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xE;
	// rlwinm r8,r8,0,30,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFB;
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// b 0x8228a188
	goto loc_8228A188;
loc_8228A158:
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r8,r9,29
	ctx.r8.u64 = ctx.r9.u32 & 0x7;
	// rlwinm r8,r8,0,31,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stw r8,72(r31)
	PPC_STORE_U32(r31.u32 + 72, ctx.r8.u32);
	// b 0x8228a188
	goto loc_8228A188;
loc_8228A174:
	// lwz r11,-3624(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -3624);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// b 0x8228a188
	goto loc_8228A188;
loc_8228A184:
	// stw r27,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r27.u32);
loc_8228A188:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r29,r29,76
	r29.s64 = r29.s64 + 76;
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// bne 0x8228a008
	if (!cr0.eq) goto loc_8228A008;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8228A1A0"))) PPC_WEAK_FUNC(sub_8228A1A0);
PPC_FUNC_IMPL(__imp__sub_8228A1A0) {
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
	ctx.lr = 0x8228A1A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// beq cr6,0x8228a388
	if (cr6.eq) goto loc_8228A388;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,328(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 328);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228A1E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r26,r11,-22108
	r26.s64 = r11.s64 + -22108;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r6,r9,-17860
	ctx.r6.s64 = ctx.r9.s64 + -17860;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823dedd8
	ctx.lr = 0x8228A208;
	sub_823DEDD8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// addi r25,r11,-18512
	r25.s64 = r11.s64 + -18512;
	// beq cr6,0x8228a268
	if (cr6.eq) goto loc_8228A268;
	// lwz r27,0(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// addi r24,r11,-22132
	r24.s64 = r11.s64 + -22132;
	// lwz r10,576(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 576);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228A234;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,480(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 480);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228A248;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8228A25C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228a388
	if (cr6.eq) goto loc_8228A388;
	// addi r27,r3,48
	r27.s64 = ctx.r3.s64 + 48;
loc_8228A268:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228a388
	if (cr6.eq) goto loc_8228A388;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228A284;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228a388
	if (cr6.eq) goto loc_8228A388;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x823dedd8
	ctx.lr = 0x8228A2A8;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228a2d8
	if (cr6.eq) goto loc_8228A2D8;
	// bl 0x822842e0
	ctx.lr = 0x8228A2B4;
	sub_822842E0(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// beq cr6,0x8228a374
	if (cr6.eq) goto loc_8228A374;
	// addi r11,r3,16
	r11.s64 = ctx.r3.s64 + 16;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// b 0x8228a374
	goto loc_8228A374;
loc_8228A2D8:
	// lis r28,-32111
	r28.s64 = -2104426496;
	// lwz r3,-29340(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -29340);
	// bl 0x8269a1a8
	ctx.lr = 0x8228A2E4;
	sub_8269A1A8(ctx, base);
	// lbz r11,16(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// beq cr6,0x8228a33c
	if (cr6.eq) goto loc_8228A33C;
	// lwz r30,-29340(r28)
	r30.u64 = PPC_LOAD_U32(r28.u32 + -29340);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228A308;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8269a1a8
	ctx.lr = 0x8228A314;
	sub_8269A1A8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x826afc18
	ctx.lr = 0x8228A31C;
	sub_826AFC18(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// beq cr6,0x8228a388
	if (cr6.eq) goto loc_8228A388;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_8228A33C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,336(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// lwz r30,-10240(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228A350;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r30,4312
	ctx.r3.s64 = r30.s64 + 4312;
	// bl 0x822973f0
	ctx.lr = 0x8228A35C;
	sub_822973F0(ctx, base);
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r29,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r29.u32);
	// beq cr6,0x8228a374
	if (cr6.eq) goto loc_8228A374;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
loc_8228A374:
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228a388
	if (cr6.eq) goto loc_8228A388;
	// bl 0x824e7110
	ctx.lr = 0x8228A384;
	sub_824E7110(ctx, base);
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
loc_8228A388:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8228A390"))) PPC_WEAK_FUNC(sub_8228A390);
PPC_FUNC_IMPL(__imp__sub_8228A390) {
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
	ctx.lr = 0x8228A398;
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
	// beq cr6,0x8228a430
	if (cr6.eq) goto loc_8228A430;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228A3B8;
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
	ctx.lr = 0x8228A3CC;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x8228A3D4;
	sub_82502300(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82502300
	ctx.lr = 0x8228A3E0;
	sub_82502300(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824f0570
	ctx.lr = 0x8228A3E8;
	sub_824F0570(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228a430
	if (cr6.eq) goto loc_8228A430;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82502300
	ctx.lr = 0x8228A3FC;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82296dd8
	ctx.lr = 0x8228A408;
	sub_82296DD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228a430
	if (cr6.eq) goto loc_8228A430;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lbz r10,281(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 281);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// bl 0x82274828
	ctx.lr = 0x8228A424;
	sub_82274828(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8228A430:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8228A43C"))) PPC_WEAK_FUNC(sub_8228A43C);
PPC_FUNC_IMPL(__imp__sub_8228A43C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228A440"))) PPC_WEAK_FUNC(sub_8228A440);
PPC_FUNC_IMPL(__imp__sub_8228A440) {
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
	ctx.lr = 0x8228A448;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228a5ec
	if (cr6.eq) goto loc_8228A5EC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228a5ec
	if (cr6.eq) goto loc_8228A5EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228A480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8228A494;
	sub_8227E750(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228a534
	if (cr6.eq) goto loc_8228A534;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228A4A8;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8228A4B8;
	sub_82270170(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmplw cr6,r11,r3
	cr6.compare<uint32_t>(r11.u32, ctx.r3.u32, xer);
	// beq cr6,0x8228a534
	if (cr6.eq) goto loc_8228A534;
	// lis r11,-32119
	r11.s64 = -2104950784;
	// addi r10,r11,-6680
	ctx.r10.s64 = r11.s64 + -6680;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228a534
	if (!cr6.eq) goto loc_8228A534;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228A4E0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228A4F0;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228A4F8;
	sub_82272A30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228a534
	if (cr6.eq) goto loc_8228A534;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228A508;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228A518;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228A520;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x8228A524;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228a538
	if (cr6.eq) goto loc_8228A538;
loc_8228A534:
	// li r30,0
	r30.s64 = 0;
loc_8228A538:
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
	ctx.lr = 0x8228A550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x8228A55C;
	sub_824E7118(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,5712
	ctx.r4.s64 = ctx.r8.s64 + 5712;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8228A574;
	sub_822183B0(ctx, base);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r7,700(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r6,16(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq cr6,0x8228a5ec
	if (cr6.eq) goto loc_8228A5EC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,324(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 324);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228A59C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// ble cr6,0x8228a5ec
	if (!cr6.gt) goto loc_8228A5EC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r31,0
	r31.s64 = 0;
	// bl 0x8268dc70
	ctx.lr = 0x8228A5B0;
	sub_8268DC70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228a5ec
	if (cr6.eq) goto loc_8228A5EC;
loc_8228A5B8:
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// bge cr6,0x8228a5ec
	if (!cr6.lt) goto loc_8228A5EC;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// rlwinm r10,r11,0,23,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// bne cr6,0x8228a5d8
	if (!cr6.eq) goto loc_8228A5D8;
	// ori r10,r11,512
	ctx.r10.u64 = r11.u64 | 512;
loc_8228A5D8:
	// stw r10,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// lwz r3,40(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8228a5b8
	if (!cr6.eq) goto loc_8228A5B8;
loc_8228A5EC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228A5F4"))) PPC_WEAK_FUNC(sub_8228A5F4);
PPC_FUNC_IMPL(__imp__sub_8228A5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228A5F8"))) PPC_WEAK_FUNC(sub_8228A5F8);
PPC_FUNC_IMPL(__imp__sub_8228A5F8) {
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
	ctx.lr = 0x8228A600;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r4,36(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 36);
	// bl 0x8227e5a0
	ctx.lr = 0x8228A610;
	sub_8227E5A0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8228A628;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228A634;
	sub_82295E90(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r30,-10244(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x823896c0
	ctx.lr = 0x8228A650;
	sub_823896C0(ctx, base);
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// rlwinm r7,r3,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r8,-27892
	ctx.r6.s64 = ctx.r8.s64 + -27892;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwzx r4,r7,r6
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// bl 0x82218310
	ctx.lr = 0x8228A668;
	sub_82218310(ctx, base);
	// lis r5,-32115
	ctx.r5.s64 = -2104688640;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-12672(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -12672);
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x8228a684
	if (!cr6.eq) goto loc_8228A684;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r30,r11,3998
	r30.s64 = r11.s64 + 3998;
loc_8228A684:
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8228a6fc
	if (cr6.eq) goto loc_8228A6FC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8228a6fc
	if (cr6.eq) goto loc_8228A6FC;
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// lwz r29,-10244(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x824e7118
	ctx.lr = 0x8228A6A0;
	sub_824E7118(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r31,-10244(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,15768
	ctx.r4.s64 = r11.s64 + 15768;
	// bl 0x82218310
	ctx.lr = 0x8228A6B8;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r10,5724
	ctx.r4.s64 = ctx.r10.s64 + 5724;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x8228A6CC;
	sub_82218310(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r31,r9,15480
	r31.s64 = ctx.r9.s64 + 15480;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// mr r8,r29
	ctx.r8.u64 = r29.u64;
	// bl 0x82137a08
	ctx.lr = 0x8228A6F0;
	sub_82137A08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8228A6FC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15480
	ctx.r3.s64 = r11.s64 + 15480;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228A70C"))) PPC_WEAK_FUNC(sub_8228A70C);
PPC_FUNC_IMPL(__imp__sub_8228A70C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228A710"))) PPC_WEAK_FUNC(sub_8228A710);
PPC_FUNC_IMPL(__imp__sub_8228A710) {
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
	ctx.lr = 0x8228A718;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8268daf8
	ctx.lr = 0x8228A728;
	sub_8268DAF8(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// li r31,0
	r31.s64 = 0;
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r3,r11,4312
	ctx.r3.s64 = r11.s64 + 4312;
	// bl 0x822973e8
	ctx.lr = 0x8228A73C;
	sub_822973E8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8228a7a4
	if (cr6.eq) goto loc_8228A7A4;
loc_8228A744:
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r11,4312
	ctx.r3.s64 = r11.s64 + 4312;
	// bl 0x822973f0
	ctx.lr = 0x8228A754;
	sub_822973F0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228a78c
	if (cr6.eq) goto loc_8228A78C;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8268db80
	ctx.lr = 0x8228A768;
	sub_8268DB80(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x824e7118
	ctx.lr = 0x8228A778;
	sub_824E7118(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,344(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 344);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8228A78C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228A78C:
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r3,r11,4312
	ctx.r3.s64 = r11.s64 + 4312;
	// bl 0x822973e8
	ctx.lr = 0x8228A79C;
	sub_822973E8(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// bne cr6,0x8228a744
	if (!cr6.eq) goto loc_8228A744;
loc_8228A7A4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228A7AC"))) PPC_WEAK_FUNC(sub_8228A7AC);
PPC_FUNC_IMPL(__imp__sub_8228A7AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228A7B0"))) PPC_WEAK_FUNC(sub_8228A7B0);
PPC_FUNC_IMPL(__imp__sub_8228A7B0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x8228A7B8;
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r19,0
	r19.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r19,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r19.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r19,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r19.u32);
	// stw r19,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r19.u32);
	// stw r19,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r19.u32);
	// stw r19,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r19.u32);
	// stw r19,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r19.u32);
	// stw r19,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r19.u32);
	// stw r19,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r19.u32);
	// bl 0x82388580
	ctx.lr = 0x8228A7F0;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8228A800;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x8228A808;
	sub_822577D0(ctx, base);
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r9,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r9.u8);
	// beq cr6,0x8228a82c
	if (cr6.eq) goto loc_8228A82C;
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// mr r11,r19
	r11.u64 = r19.u64;
	// bne cr6,0x8228a830
	if (!cr6.eq) goto loc_8228A830;
loc_8228A82C:
	// li r11,1
	r11.s64 = 1;
loc_8228A830:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x8228A844;
	sub_822701C8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r27,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r27.u32);
	// bl 0x8227e750
	ctx.lr = 0x8228A854;
	sub_8227E750(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x8228A860;
	sub_8227E0B0(ctx, base);
	// stb r3,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r3.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822809b8
	ctx.lr = 0x8228A86C;
	sub_822809B8(ctx, base);
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822801f0
	ctx.lr = 0x8228A878;
	sub_822801F0(ctx, base);
	// stb r3,82(r1)
	PPC_STORE_U8(ctx.r1.u32 + 82, ctx.r3.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e7f8
	ctx.lr = 0x8228A884;
	sub_8227E7F8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8228a8c4
	if (cr6.eq) goto loc_8228A8C4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228A898;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228A8A8;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228A8B0;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x8228A8B4;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228a8c8
	if (cr6.eq) goto loc_8228A8C8;
loc_8228A8C4:
	// mr r11,r19
	r11.u64 = r19.u64;
loc_8228A8C8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r11.u8);
	// bl 0x82280ad8
	ctx.lr = 0x8228A8D4;
	sub_82280AD8(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,83(r1)
	PPC_STORE_U8(ctx.r1.u32 + 83, ctx.r8.u8);
	// bl 0x82256058
	ctx.lr = 0x8228A8EC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228a900
	if (cr6.eq) goto loc_8228A900;
	// bl 0x82256058
	ctx.lr = 0x8228A8F8;
	sub_82256058(ctx, base);
	// addi r28,r3,8
	r28.s64 = ctx.r3.s64 + 8;
	// b 0x8228a904
	goto loc_8228A904;
loc_8228A900:
	// mr r28,r19
	r28.u64 = r19.u64;
loc_8228A904:
	// stw r28,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r28.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228a93c
	if (cr6.eq) goto loc_8228A93C;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822952b0
	ctx.lr = 0x8228A91C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228a93c
	if (cr6.eq) goto loc_8228A93C;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228A934;
	sub_82295E90(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// b 0x8228a940
	goto loc_8228A940;
loc_8228A93C:
	// mr r21,r19
	r21.u64 = r19.u64;
loc_8228A940:
	// cntlzw r11,r21
	r11.u64 = r21.u32 == 0 ? 32 : __builtin_clz(r21.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r16,r10,1
	r16.u64 = ctx.r10.u64 ^ 1;
	// bl 0x82388580
	ctx.lr = 0x8228A954;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228A964;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228A96C;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x8228A970;
	sub_82481590(ctx, base);
	// stb r3,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r3.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e250
	ctx.lr = 0x8228A980;
	sub_8227E250(ctx, base);
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
	// mr r17,r19
	r17.u64 = r19.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8228a9dc
	if (cr6.eq) goto loc_8228A9DC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x8228a9dc
	if (cr6.lt) goto loc_8228A9DC;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228a9dc
	if (cr6.eq) goto loc_8228A9DC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,44(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// lis r8,-32129
	ctx.r8.s64 = -2105606144;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// addi r6,r8,-28304
	ctx.r6.s64 = ctx.r8.s64 + -28304;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r4,144(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 144);
	// and r3,r4,r11
	ctx.r3.u64 = ctx.r4.u64 & r11.u64;
	// subfic r11,r3,0
	xer.ca = ctx.r3.u32 <= 0;
	r11.s64 = 0 - ctx.r3.s64;
	// subfe r10,r11,r11
	temp.u8 = (~r11.u32 + r11.u32 < ~r11.u32) | (~r11.u32 + r11.u32 + xer.ca < xer.ca);
	ctx.r10.u64 = ~r11.u64 + r11.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r17,r10,31
	r17.u64 = ctx.r10.u32 & 0x1;
loc_8228A9DC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x8228A9E8;
	sub_8268DCB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228af54
	if (cr6.eq) goto loc_8228AF54;
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
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// lis r3,-32254
	ctx.r3.s64 = -2113798144;
	// addi r29,r11,5828
	r29.s64 = r11.s64 + 5828;
	// addi r28,r10,5820
	r28.s64 = ctx.r10.s64 + 5820;
	// addi r27,r9,5816
	r27.s64 = ctx.r9.s64 + 5816;
	// addi r26,r8,5808
	r26.s64 = ctx.r8.s64 + 5808;
	// addi r25,r7,5800
	r25.s64 = ctx.r7.s64 + 5800;
	// addi r24,r6,5792
	r24.s64 = ctx.r6.s64 + 5792;
	// addi r23,r5,5784
	r23.s64 = ctx.r5.s64 + 5784;
	// addi r22,r4,5776
	r22.s64 = ctx.r4.s64 + 5776;
	// addi r30,r3,612
	r30.s64 = ctx.r3.s64 + 612;
loc_8228AA3C:
	// lwz r10,20(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// li r8,63
	ctx.r8.s64 = 63;
loc_8228AA48:
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228aaa0
	if (cr6.eq) goto loc_8228AAA0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228aa94
	if (cr6.eq) goto loc_8228AA94;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228aa9c
	if (cr6.eq) goto loc_8228AA9C;
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
	// bgt 0x8228aa48
	if (cr0.gt) goto loc_8228AA48;
	// b 0x8228aaa0
	goto loc_8228AAA0;
loc_8228AA94:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x8228aaa0
	goto loc_8228AAA0;
loc_8228AA9C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_8228AAA0:
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// bl 0x823defc8
	ctx.lr = 0x8228AAB0;
	sub_823DEFC8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AABC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228aac8
	if (cr6.eq) goto loc_8228AAC8;
	// mr r19,r31
	r19.u64 = r31.u64;
loc_8228AAC8:
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AAD4;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228aae0
	if (cr6.eq) goto loc_8228AAE0;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r31.u32);
loc_8228AAE0:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AAEC;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228aaf8
	if (cr6.eq) goto loc_8228AAF8;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
loc_8228AAF8:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AB04;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ab10
	if (cr6.eq) goto loc_8228AB10;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
loc_8228AB10:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AB1C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ab28
	if (cr6.eq) goto loc_8228AB28;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
loc_8228AB28:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AB34;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ab40
	if (cr6.eq) goto loc_8228AB40;
	// stw r31,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r31.u32);
loc_8228AB40:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AB4C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ab58
	if (cr6.eq) goto loc_8228AB58;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r31.u32);
loc_8228AB58:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AB64;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ab70
	if (cr6.eq) goto loc_8228AB70;
	// stw r31,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r31.u32);
loc_8228AB70:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x823d90b0
	ctx.lr = 0x8228AB7C;
	sub_823D90B0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ab88
	if (cr6.eq) goto loc_8228AB88;
	// stw r31,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r31.u32);
loc_8228AB88:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8228aa3c
	if (!cr6.eq) goto loc_8228AA3C;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x8228abdc
	if (cr6.eq) goto loc_8228ABDC;
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228abc4
	if (cr6.eq) goto loc_8228ABC4;
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228abc4
	if (cr6.eq) goto loc_8228ABC4;
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228abc8
	if (!cr6.eq) goto loc_8228ABC8;
loc_8228ABC4:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228ABC8:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228ABDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228ABDC:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ac1c
	if (cr6.eq) goto loc_8228AC1C;
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228ac04
	if (!cr6.eq) goto loc_8228AC04;
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228ac08
	if (!cr6.eq) goto loc_8228AC08;
loc_8228AC04:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228AC08:
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228AC1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228AC1C:
	// lwz r11,92(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ac5c
	if (cr6.eq) goto loc_8228AC5C;
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ac44
	if (cr6.eq) goto loc_8228AC44;
	// lbz r10,82(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 82);
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228ac48
	if (!cr6.eq) goto loc_8228AC48;
loc_8228AC44:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228AC48:
	// lwz r3,92(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228AC5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228AC5C:
	// lwz r11,96(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228acc4
	if (cr6.eq) goto loc_8228ACC4;
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228ac7c
	if (cr6.eq) goto loc_8228AC7C;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x8228aca4
	if (cr6.eq) goto loc_8228ACA4;
loc_8228AC7C:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228acac
	if (cr6.eq) goto loc_8228ACAC;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,124(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x82295e90
	ctx.lr = 0x8228AC94;
	sub_82295E90(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x8228acac
	if (cr6.eq) goto loc_8228ACAC;
loc_8228ACA4:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x8228acb0
	goto loc_8228ACB0;
loc_8228ACAC:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228ACB0:
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228ACC4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228ACC4:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ad20
	if (cr6.eq) goto loc_8228AD20;
	// lbz r11,83(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 83);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228ace8
	if (!cr6.eq) goto loc_8228ACE8;
	// clrlwi r10,r16,24
	ctx.r10.u64 = r16.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228ad08
	if (cr6.eq) goto loc_8228AD08;
loc_8228ACE8:
	// cmpwi cr6,r15,0
	cr6.compare<int32_t>(r15.s32, 0, xer);
	// bne cr6,0x8228acf8
	if (!cr6.eq) goto loc_8228ACF8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ad08
	if (cr6.eq) goto loc_8228AD08;
loc_8228ACF8:
	// lbz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228ad0c
	if (cr6.eq) goto loc_8228AD0C;
loc_8228AD08:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228AD0C:
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228AD20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228AD20:
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ad78
	if (cr6.eq) goto loc_8228AD78;
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ad60
	if (cr6.eq) goto loc_8228AD60;
	// lwz r11,3140(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 3140);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8228ad60
	if (!cr6.eq) goto loc_8228AD60;
	// lbz r10,85(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228ad60
	if (cr6.eq) goto loc_8228AD60;
	// clrlwi r11,r17,24
	r11.u64 = r17.u32 & 0xFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228ad64
	if (!cr6.eq) goto loc_8228AD64;
loc_8228AD60:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228AD64:
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228AD78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228AD78:
	// lwz r11,108(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228adb8
	if (cr6.eq) goto loc_8228ADB8;
	// lbz r10,86(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228ada0
	if (cr6.eq) goto loc_8228ADA0;
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228ada4
	if (!cr6.eq) goto loc_8228ADA4;
loc_8228ADA0:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228ADA4:
	// lwz r3,108(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228ADB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228ADB8:
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ae20
	if (cr6.eq) goto loc_8228AE20;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228ADCC;
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
	ctx.lr = 0x8228ADE0;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228ADE8;
	sub_82272A30(ctx, base);
	// bl 0x82481598
	ctx.lr = 0x8228ADEC;
	sub_82481598(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228ae08
	if (cr6.eq) goto loc_8228AE08;
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// li r4,1
	ctx.r4.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228ae0c
	if (cr6.eq) goto loc_8228AE0C;
loc_8228AE08:
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228AE0C:
	// lwz r3,112(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228AE20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228AE20:
	// lwz r11,116(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ae70
	if (cr6.eq) goto loc_8228AE70;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228AE34;
	sub_82388580(ctx, base);
	// lwz r31,116(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8228AE50;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228AE58;
	sub_82272A30(ctx, base);
	// bl 0x82481598
	ctx.lr = 0x8228AE5C;
	sub_82481598(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,76(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228AE70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228AE70:
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228af54
	if (cr6.eq) goto loc_8228AF54;
	// rotlwi r31,r11,0
	r31.u64 = __builtin_rotateleft32(r11.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228AE94;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228af54
	if (cr6.eq) goto loc_8228AF54;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,18884
	ctx.r4.s64 = r11.s64 + 18884;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8228AEB4;
	sub_8268DA78(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228AEC0;
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
	ctx.lr = 0x8228AED4;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x822577d0
	ctx.lr = 0x8228AEDC;
	sub_822577D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r30,-10244(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// beq cr6,0x8228af28
	if (cr6.eq) goto loc_8228AF28;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2208
	ctx.r4.s64 = ctx.r10.s64 + 2208;
	// bl 0x82218310
	ctx.lr = 0x8228AEFC;
	sub_82218310(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,5756
	ctx.r4.s64 = ctx.r9.s64 + 5756;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822183b0
	ctx.lr = 0x8228AF10;
	sub_822183B0(ctx, base);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9210
	return;
loc_8228AF28:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2232
	ctx.r4.s64 = ctx.r10.s64 + 2232;
	// bl 0x82218310
	ctx.lr = 0x8228AF34;
	sub_82218310(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r9,5756
	ctx.r4.s64 = ctx.r9.s64 + 5756;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822183b0
	ctx.lr = 0x8228AF48;
	sub_822183B0(ctx, base);
	// li r11,1
	r11.s64 = 1;
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_8228AF54:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_8228AF5C"))) PPC_WEAK_FUNC(sub_8228AF5C);
PPC_FUNC_IMPL(__imp__sub_8228AF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228AF60"))) PPC_WEAK_FUNC(sub_8228AF60);
PPC_FUNC_IMPL(__imp__sub_8228AF60) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228AF74;
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
	ctx.lr = 0x8228AF88;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8228AF90;
	sub_824E70F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228afac
	if (cr6.eq) goto loc_8228AFAC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228AFA4;
	sub_82388580(ctx, base);
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82131c20
	ctx.lr = 0x8228AFAC;
	sub_82131C20(ctx, base);
loc_8228AFAC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228AFBC"))) PPC_WEAK_FUNC(sub_8228AFBC);
PPC_FUNC_IMPL(__imp__sub_8228AFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228AFC0"))) PPC_WEAK_FUNC(sub_8228AFC0);
PPC_FUNC_IMPL(__imp__sub_8228AFC0) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x8268daf8
	ctx.lr = 0x8228AFD4;
	sub_8268DAF8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228AFDC;
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
	ctx.lr = 0x8228AFF0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x8228AFF8;
	sub_821F8730(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,240
	ctx.r6.s64 = 240;
	// bl 0x82131c40
	ctx.lr = 0x8228B008;
	sub_82131C40(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228B018"))) PPC_WEAK_FUNC(sub_8228B018);
PPC_FUNC_IMPL(__imp__sub_8228B018) {
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
	ctx.lr = 0x8228B020;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// bl 0x82387a18
	ctx.lr = 0x8228B02C;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b068
	if (cr6.eq) goto loc_8228B068;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B040;
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
	ctx.lr = 0x8228B054;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228B05C;
	sub_82272A30(ctx, base);
	// bl 0x824817c0
	ctx.lr = 0x8228B060;
	sub_824817C0(ctx, base);
	// addi r22,r3,12
	r22.s64 = ctx.r3.s64 + 12;
	// b 0x8228b06c
	goto loc_8228B06C;
loc_8228B068:
	// li r22,0
	r22.s64 = 0;
loc_8228B06C:
	// bl 0x82387b90
	ctx.lr = 0x8228B070;
	sub_82387B90(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,5836
	ctx.r4.s64 = r11.s64 + 5836;
	// li r5,25
	ctx.r5.s64 = 25;
	// lwz r23,1340(r10)
	r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1340);
	// bl 0x823da950
	ctx.lr = 0x8228B08C;
	sub_823DA950(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8268daf8
	ctx.lr = 0x8228B094;
	sub_8268DAF8(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// ble cr6,0x8228b1a0
	if (!cr6.gt) goto loc_8228B1A0;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r29,0
	r29.s64 = 0;
	// li r24,6
	r24.s64 = 6;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// addi r27,r11,-19624
	r27.s64 = r11.s64 + -19624;
loc_8228B0B4:
	// bl 0x82387b90
	ctx.lr = 0x8228B0B8;
	sub_82387B90(ctx, base);
	// add r11,r3,r29
	r11.u64 = ctx.r3.u64 + r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r30,r11,1360
	r30.s64 = r11.s64 + 1360;
	// bl 0x8268db80
	ctx.lr = 0x8228B0C8;
	sub_8268DB80(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228b1a0
	if (cr6.eq) goto loc_8228B1A0;
	// cmplwi cr6,r22,0
	cr6.compare<uint32_t>(r22.u32, 0, xer);
	// beq cr6,0x8228b110
	if (cr6.eq) goto loc_8228B110;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823906d8
	ctx.lr = 0x8228B0E8;
	sub_823906D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b104
	if (cr6.eq) goto loc_8228B104;
	// bl 0x82387b90
	ctx.lr = 0x8228B0F8;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bne cr6,0x8228b110
	if (!cr6.eq) goto loc_8228B110;
loc_8228B104:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// b 0x8228b118
	goto loc_8228B118;
loc_8228B110:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,28,26
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFFEF;
loc_8228B118:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r30,8141
	ctx.r4.s64 = r30.s64 + 8141;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228B134;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8238f6b0
	ctx.lr = 0x8228B13C;
	sub_8238F6B0(ctx, base);
	// addi r9,r3,65
	ctx.r9.s64 = ctx.r3.s64 + 65;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// stb r9,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r9.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8228B154;
	sub_8268DA78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228b174
	if (cr6.eq) goto loc_8228B174;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-10244(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8228B16C;
	sub_82218310(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// stw r24,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r24.u32);
loc_8228B174:
	// bl 0x82387b90
	ctx.lr = 0x8228B178;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bne cr6,0x8228b190
	if (!cr6.eq) goto loc_8228B190;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// ori r10,r11,16
	ctx.r10.u64 = r11.u64 | 16;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_8228B190:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,8176
	r29.s64 = r29.s64 + 8176;
	// cmpw cr6,r28,r23
	cr6.compare<int32_t>(r28.s32, r23.s32, xer);
	// blt cr6,0x8228b0b4
	if (cr6.lt) goto loc_8228B0B4;
loc_8228B1A0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8228B1A8"))) PPC_WEAK_FUNC(sub_8228B1A8);
PPC_FUNC_IMPL(__imp__sub_8228B1A8) {
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
	ctx.lr = 0x8228B1B0;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r22,r4
	r22.u64 = ctx.r4.u64;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r18,r5
	r18.u64 = ctx.r5.u64;
	// addi r6,r11,-17860
	ctx.r6.s64 = r11.s64 + -17860;
	// addi r5,r10,-22108
	ctx.r5.s64 = ctx.r10.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823dedd8
	ctx.lr = 0x8228B1DC;
	sub_823DEDD8(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B1E8;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8228B1F8;
	sub_82270170(ctx, base);
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8228b228
	if (cr6.eq) goto loc_8228B228;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B20C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228B21C;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r20,r11,144
	r20.s64 = r11.s64 + 144;
	// b 0x8228b22c
	goto loc_8228B22C;
loc_8228B228:
	// li r20,0
	r20.s64 = 0;
loc_8228B22C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B234;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228B244;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x8228B248;
	sub_82274B80(ctx, base);
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8268daf8
	ctx.lr = 0x8228B250;
	sub_8268DAF8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// li r21,0
	r21.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B25C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228B26C;
	sub_82270170(ctx, base);
	// lwz r9,308(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8228b450
	if (!cr6.gt) goto loc_8228B450;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r28,0
	r28.s64 = 0;
	// li r26,6
	r26.s64 = 6;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r24,r11,5884
	r24.s64 = r11.s64 + 5884;
	// addi r23,r10,5864
	r23.s64 = ctx.r10.s64 + 5864;
	// addi r25,r9,-19624
	r25.s64 = ctx.r9.s64 + -19624;
loc_8228B29C:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8268db80
	ctx.lr = 0x8228B2A4;
	sub_8268DB80(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228b3a0
	if (cr6.eq) goto loc_8228B3A0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B2B8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228B2C8;
	sub_82270170(ctx, base);
	// add r11,r28,r3
	r11.u64 = r28.u64 + ctx.r3.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r11,312
	ctx.r3.s64 = r11.s64 + 312;
	// bl 0x825006a0
	ctx.lr = 0x8228B2D8;
	sub_825006A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,344(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 344);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228B2EC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x8228B2FC;
	sub_8268DA78(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228b374
	if (cr6.eq) goto loc_8228B374;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B310;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228B320;
	sub_82270170(ctx, base);
	// add r11,r28,r3
	r11.u64 = r28.u64 + ctx.r3.u64;
	// addi r3,r11,312
	ctx.r3.s64 = r11.s64 + 312;
	// bl 0x825006a8
	ctx.lr = 0x8228B32C;
	sub_825006A8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,-10244(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10244);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228b358
	if (cr6.eq) goto loc_8228B358;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// bl 0x82218310
	ctx.lr = 0x8228B344;
	sub_82218310(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,23,21
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFFFFFFFFFDFF;
	// b 0x8228b370
	goto loc_8228B370;
loc_8228B358:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x82218310
	ctx.lr = 0x8228B360;
	sub_82218310(ctx, base);
	// stw r3,4(r30)
	PPC_STORE_U32(r30.u32 + 4, ctx.r3.u32);
	// stw r26,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r26.u32);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// ori r10,r11,512
	ctx.r10.u64 = r11.u64 | 512;
loc_8228B370:
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
loc_8228B374:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r21,r21,1
	r21.s64 = r21.s64 + 1;
	// addi r28,r28,196
	r28.s64 = r28.s64 + 196;
	// bl 0x82388580
	ctx.lr = 0x8228B384;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228B394;
	sub_82270170(ctx, base);
	// lwz r10,308(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 308);
	// cmpw cr6,r21,r10
	cr6.compare<int32_t>(r21.s32, ctx.r10.s32, xer);
	// blt cr6,0x8228b29c
	if (cr6.lt) goto loc_8228B29C;
loc_8228B3A0:
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// beq cr6,0x8228b450
	if (cr6.eq) goto loc_8228B450;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x8228B3B4;
	sub_8268DCB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228B3C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228b3fc
	if (cr6.eq) goto loc_8228B3FC;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8228b3ec
	if (cr6.gt) goto loc_8228B3EC;
	// li r11,0
	r11.s64 = 0;
loc_8228B3EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8228b400
	if (cr6.eq) goto loc_8228B400;
loc_8228B3FC:
	// li r11,0
	r11.s64 = 0;
loc_8228B400:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b450
	if (cr6.eq) goto loc_8228B450;
	// bl 0x82387a18
	ctx.lr = 0x8228B410;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b450
	if (cr6.eq) goto loc_8228B450;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x8228b450
	if (cr6.eq) goto loc_8228B450;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82481598
	ctx.lr = 0x8228B42C;
	sub_82481598(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b450
	if (cr6.eq) goto loc_8228B450;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x82481590
	ctx.lr = 0x8228B440;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r31,1
	r31.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b454
	if (cr6.eq) goto loc_8228B454;
loc_8228B450:
	// li r31,0
	r31.s64 = 0;
loc_8228B454:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8268dcb0
	ctx.lr = 0x8228B460;
	sub_8268DCB0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 76);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228B474;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x8228b494
	if (cr6.eq) goto loc_8228B494;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r10,572(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 572);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228B494;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228B494:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8228B49C"))) PPC_WEAK_FUNC(sub_8228B49C);
PPC_FUNC_IMPL(__imp__sub_8228B49C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228B4A0"))) PPC_WEAK_FUNC(sub_8228B4A0);
PPC_FUNC_IMPL(__imp__sub_8228B4A0) {
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
	ctx.lr = 0x8228B4A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8228B4BC;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8228B4CC;
	sub_82270170(ctx, base);
	// lwz r29,208(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8228b5ec
	if (cr6.eq) goto loc_8228B5EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B4E0;
	sub_82388580(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r28,-10240(r30)
	r28.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,336(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// lwz r26,4(r10)
	r26.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228B500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82270170
	ctx.lr = 0x8228B510;
	sub_82270170(ctx, base);
	// mulli r8,r25,196
	ctx.r8.s64 = r25.s64 * 196;
	// add r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64;
	// addic. r3,r7,312
	xer.ca = ctx.r7.u32 > 4294966983;
	ctx.r3.s64 = ctx.r7.s64 + 312;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x8228b5d8
	if (cr0.eq) goto loc_8228B5D8;
	// bl 0x825006a8
	ctx.lr = 0x8228B524;
	sub_825006A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b5d8
	if (cr6.eq) goto loc_8228B5D8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f9438
	ctx.lr = 0x8228B538;
	sub_824F9438(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B540;
	sub_82388580(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r30,-10240(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,336(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// lwz r31,4(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228B560;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82270170
	ctx.lr = 0x8228B570;
	sub_82270170(ctx, base);
	// mulli r11,r28,196
	r11.s64 = r28.s64 * 196;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r11,312
	ctx.r3.s64 = r11.s64 + 312;
	// bl 0x82500658
	ctx.lr = 0x8228B584;
	sub_82500658(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82296e50
	ctx.lr = 0x8228B590;
	sub_82296E50(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8228b5d8
	if (!cr6.eq) goto loc_8228B5D8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-1896
	ctx.r4.s64 = ctx.r10.s64 + -1896;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8228B5B0;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r29,144
	ctx.r3.s64 = r29.s64 + 144;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x82486a58
	ctx.lr = 0x8228B5C8;
	sub_82486A58(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8228b5dc
	if (!cr6.eq) goto loc_8228B5DC;
loc_8228B5D8:
	// li r4,3
	ctx.r4.s64 = 3;
loc_8228B5DC:
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8268ee10
	ctx.lr = 0x8228B5EC;
	sub_8268EE10(ctx, base);
loc_8228B5EC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8228B5F4"))) PPC_WEAK_FUNC(sub_8228B5F4);
PPC_FUNC_IMPL(__imp__sub_8228B5F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228B5F8"))) PPC_WEAK_FUNC(sub_8228B5F8);
PPC_FUNC_IMPL(__imp__sub_8228B5F8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8228B618;
	sub_82388580(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,336(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// lwz r30,4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r31,-10240(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8228B63C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82270170
	ctx.lr = 0x8228B648;
	sub_82270170(ctx, base);
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

__attribute__((alias("__imp__sub_8228B660"))) PPC_WEAK_FUNC(sub_8228B660);
PPC_FUNC_IMPL(__imp__sub_8228B660) {
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
	// lwz r11,76(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// cmpw cr6,r11,r4
	cr6.compare<int32_t>(r11.s32, ctx.r4.s32, xer);
	// beq cr6,0x8228b6ec
	if (cr6.eq) goto loc_8228B6EC;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// stw r4,76(r3)
	PPC_STORE_U32(ctx.r3.u32 + 76, ctx.r4.u32);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r10,r11,29952
	ctx.r10.s64 = r11.s64 + 29952;
	// lfs f0,20(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r3)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r3.u32 + 80, temp.u32);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x822809b8
	ctx.lr = 0x8228B6A0;
	sub_822809B8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228b6ec
	if (cr6.eq) goto loc_8228B6EC;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8228B6B8;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228b6ec
	if (!cr6.eq) goto loc_8228B6EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228B6CC;
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
	ctx.lr = 0x8228B6E0;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8228B6EC;
	sub_82274128(ctx, base);
loc_8228B6EC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228B700"))) PPC_WEAK_FUNC(sub_8228B700);
PPC_FUNC_IMPL(__imp__sub_8228B700) {
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
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stb r4,84(r30)
	PPC_STORE_U8(r30.u32 + 84, ctx.r4.u8);
	// beq cr6,0x8228b734
	if (cr6.eq) goto loc_8228B734;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,5944
	ctx.r4.s64 = r11.s64 + 5944;
	// b 0x8228b73c
	goto loc_8228B73C;
loc_8228B734:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,5924
	ctx.r4.s64 = r11.s64 + 5924;
loc_8228B73C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,-10244(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x8228B74C;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,5904
	ctx.r4.s64 = ctx.r10.s64 + 5904;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822183b0
	ctx.lr = 0x8228B760;
	sub_822183B0(ctx, base);
	// lwz r11,72(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 72);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r10
	ctx.r9.u64 = r11.u64 + ctx.r10.u64;
	// stw r9,72(r30)
	PPC_STORE_U32(r30.u32 + 72, ctx.r9.u32);
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

__attribute__((alias("__imp__sub_8228B788"))) PPC_WEAK_FUNC(sub_8228B788);
PPC_FUNC_IMPL(__imp__sub_8228B788) {
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
	ctx.lr = 0x8228B790;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// bl 0x826355a8
	ctx.lr = 0x8228B7A0;
	sub_826355A8(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x8228B7A4;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b8c8
	if (cr6.eq) goto loc_8228B8C8;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,80(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r28.u32 + 80);
	f0.f64 = double(temp.f32);
	// lfs f31,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	cr6.compare(f0.f64, f31.f64);
	// beq cr6,0x8228b808
	if (cr6.eq) goto loc_8228B808;
	// lis r11,-32252
	r11.s64 = -2113667072;
	// lis r10,-32131
	ctx.r10.s64 = -2105737216;
	// addi r9,r10,29952
	ctx.r9.s64 = ctx.r10.s64 + 29952;
	// lfs f13,3732(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3732);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(f0.f64 + ctx.f13.f64));
	// lfs f0,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x8228b808
	if (!cr6.gt) goto loc_8228B808;
	// bl 0x82387b90
	ctx.lr = 0x8228B7E8;
	sub_82387B90(ctx, base);
	// lwz r4,76(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 76);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x8228b808
	if (cr6.eq) goto loc_8228B808;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-29340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// bl 0x826a4718
	ctx.lr = 0x8228B804;
	sub_826A4718(ctx, base);
	// stfs f31,80(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(r28.u32 + 80, temp.u32);
loc_8228B808:
	// lwz r4,68(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8228b8c8
	if (cr6.eq) goto loc_8228B8C8;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8228a7b0
	ctx.lr = 0x8228B824;
	sub_8228A7B0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,68(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 68);
	// li r29,0
	r29.s64 = 0;
	// bl 0x8268dcb0
	ctx.lr = 0x8228B834;
	sub_8268DCB0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228b89c
	if (cr6.eq) goto loc_8228B89C;
loc_8228B844:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228B858;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228b88c
	if (cr6.eq) goto loc_8228B88C;
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bgt cr6,0x8228b87c
	if (cr6.gt) goto loc_8228B87C;
	// li r11,0
	r11.s64 = 0;
loc_8228B87C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228b88c
	if (!cr6.eq) goto loc_8228B88C;
	// or r29,r30,r29
	r29.u64 = r30.u64 | r29.u64;
loc_8228B88C:
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rotlwi r30,r30,1
	r30.u64 = __builtin_rotateleft32(r30.u32, 1);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8228b844
	if (!cr6.eq) goto loc_8228B844;
loc_8228B89C:
	// lwz r11,72(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 72);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// beq cr6,0x8228b8c8
	if (cr6.eq) goto loc_8228B8C8;
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,22
	ctx.r4.s64 = 22;
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8228B8C4;
	sub_8268EE10(ctx, base);
	// stw r29,72(r28)
	PPC_STORE_U32(r28.u32 + 72, r29.u32);
loc_8228B8C8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228B8D4"))) PPC_WEAK_FUNC(sub_8228B8D4);
PPC_FUNC_IMPL(__imp__sub_8228B8D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228B8D8"))) PPC_WEAK_FUNC(sub_8228B8D8);
PPC_FUNC_IMPL(__imp__sub_8228B8D8) {
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
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228b90c
	if (cr6.eq) goto loc_8228B90C;
	// stw r11,80(r31)
	PPC_STORE_U32(r31.u32 + 80, r11.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,1220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 1220);
	// bl 0x822051a0
	ctx.lr = 0x8228B908;
	sub_822051A0(ctx, base);
	// stw r3,84(r31)
	PPC_STORE_U32(r31.u32 + 84, ctx.r3.u32);
loc_8228B90C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228B920"))) PPC_WEAK_FUNC(sub_8228B920);
PPC_FUNC_IMPL(__imp__sub_8228B920) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// bl 0x82130000
	ctx.lr = 0x8228B93C;
	sub_82130000(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ba80
	if (cr6.eq) goto loc_8228BA80;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r30,-10244(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228B960;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,5968
	ctx.r4.s64 = ctx.r8.s64 + 5968;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822183b0
	ctx.lr = 0x8228B974;
	sub_822183B0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228B980;
	sub_822A39C8(ctx, base);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b1648
	ctx.lr = 0x8228B98C;
	sub_822B1648(ctx, base);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228B994;
	sub_822A39C8(ctx, base);
	// lwz r7,880(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r11,80(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 80);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// stw r11,92(r31)
	PPC_STORE_U32(r31.u32 + 92, r11.u32);
	// beq cr6,0x8228b9b8
	if (cr6.eq) goto loc_8228B9B8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8228b9b8
	if (cr6.eq) goto loc_8228B9B8;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x8228b9cc
	if (!cr6.eq) goto loc_8228B9CC;
loc_8228B9B8:
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228B9C0;
	sub_822A39C8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afab0
	ctx.lr = 0x8228B9CC;
	sub_822AFAB0(ctx, base);
loc_8228B9CC:
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228B9D4;
	sub_822A39C8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// li r4,4
	ctx.r4.s64 = 4;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x8228B9E8;
	sub_822B0F10(ctx, base);
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228B9F0;
	sub_822A39C8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x822a6198
	ctx.lr = 0x8228B9FC;
	sub_822A6198(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228BA14;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,464(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 464);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228BA2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,96(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 96);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8228BA44;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r3,-32121
	ctx.r3.s64 = -2105081856;
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,17892(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x8228BA54;
	sub_822B62A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228BA60;
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
	ctx.lr = 0x8228BA74;
	sub_82270170(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274120
	ctx.lr = 0x8228BA80;
	sub_82274120(ctx, base);
loc_8228BA80:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,26
	ctx.r4.s64 = 26;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x8220f040
	ctx.lr = 0x8228BA90;
	sub_8220F040(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,88(r31)
	PPC_STORE_U8(r31.u32 + 88, r11.u8);
	// stb r11,102(r31)
	PPC_STORE_U8(r31.u32 + 102, r11.u8);
	// stb r11,103(r31)
	PPC_STORE_U8(r31.u32 + 103, r11.u8);
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

__attribute__((alias("__imp__sub_8228BAB8"))) PPC_WEAK_FUNC(sub_8228BAB8);
PPC_FUNC_IMPL(__imp__sub_8228BAB8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	ctx.lr = 0x8228BAC0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228BAD0;
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
	ctx.lr = 0x8228BAE4;
	sub_82270170(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x8228BAF0;
	sub_82274120(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r31,17268(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a39c8
	ctx.lr = 0x8228BB00;
	sub_822A39C8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,880(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 880);
	// bl 0x822a39c8
	ctx.lr = 0x8228BB10;
	sub_822A39C8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822b1648
	ctx.lr = 0x8228BB1C;
	sub_822B1648(ctx, base);
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228BB24;
	sub_822A39C8(ctx, base);
	// lwz r4,92(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 92);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afab0
	ctx.lr = 0x8228BB30;
	sub_822AFAB0(ctx, base);
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228BB38;
	sub_822A39C8(ctx, base);
	// lwz r8,880(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r11,80(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 80);
	// addi r7,r11,11
	ctx.r7.s64 = r11.s64 + 11;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r6,r8
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r8.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,36(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8228BB5C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228BB64;
	sub_822A39C8(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822b0f10
	ctx.lr = 0x8228BB78;
	sub_822B0F10(ctx, base);
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228BB80;
	sub_822A39C8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x822a6198
	ctx.lr = 0x8228BB8C;
	sub_822A6198(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228BBA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228BBBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// stb r6,89(r30)
	PPC_STORE_U8(r30.u32 + 89, ctx.r6.u8);
	// bl 0x8221fa88
	ctx.lr = 0x8228BBC8;
	sub_8221FA88(ctx, base);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// addi r3,r5,-1304
	ctx.r3.s64 = ctx.r5.s64 + -1304;
	// bl 0x821fa230
	ctx.lr = 0x8228BBD4;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,112(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 112);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8228BBE8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,96(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 96);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228BC00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,64(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 64);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228BC18;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10028(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10028);
	// bl 0x8220f040
	ctx.lr = 0x8228BC28;
	sub_8220F040(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8228BC30"))) PPC_WEAK_FUNC(sub_8228BC30);
PPC_FUNC_IMPL(__imp__sub_8228BC30) {
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
	ctx.lr = 0x8228BC38;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r30,84(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 84);
	// lwz r29,17268(r28)
	r29.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8228BC58;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228bcf4
	if (cr6.eq) goto loc_8228BCF4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8228BC70;
	sub_822A3998(ctx, base);
	// stw r3,80(r31)
	PPC_STORE_U32(r31.u32 + 80, ctx.r3.u32);
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228BC7C;
	sub_822A39C8(ctx, base);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b1648
	ctx.lr = 0x8228BC88;
	sub_822B1648(ctx, base);
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// lwz r30,-10244(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228BCA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r8,5968
	ctx.r4.s64 = ctx.r8.s64 + 5968;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822183b0
	ctx.lr = 0x8228BCB8;
	sub_822183B0(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,17892(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x8228BCC8;
	sub_822B62A0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228BCD4;
	sub_82388580(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r3,-10240(r6)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8228BCE8;
	sub_82270170(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x8228BCF4;
	sub_82274120(ctx, base);
loc_8228BCF4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8228BCFC"))) PPC_WEAK_FUNC(sub_8228BCFC);
PPC_FUNC_IMPL(__imp__sub_8228BCFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228BD00"))) PPC_WEAK_FUNC(sub_8228BD00);
PPC_FUNC_IMPL(__imp__sub_8228BD00) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228BD1C;
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
	ctx.lr = 0x8228BD30;
	sub_82270170(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,572(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 572);
	// lwz r4,308(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 308);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228BD4C;
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

__attribute__((alias("__imp__sub_8228BD60"))) PPC_WEAK_FUNC(sub_8228BD60);
PPC_FUNC_IMPL(__imp__sub_8228BD60) {
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
	ctx.lr = 0x8228BD68;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228BD80;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r28,0
	r28.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r9,7
	ctx.r9.s64 = 7;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// beq cr6,0x8228bec8
	if (cr6.eq) goto loc_8228BEC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228BDA4;
	sub_82388580(ctx, base);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8228BDB4;
	sub_82270170(ctx, base);
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,572(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 572);
	// lwz r4,308(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 308);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228BDD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r8,-12116
	ctx.r3.s64 = ctx.r8.s64 + -12116;
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// bl 0x821c9790
	ctx.lr = 0x8228BDE4;
	sub_821C9790(ctx, base);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,36(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8228BE0C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,80(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x8228bec8
	if (!cr6.gt) goto loc_8228BEC8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r25,r11,20292
	r25.s64 = r11.s64 + 20292;
	// addi r24,r10,2672
	r24.s64 = ctx.r10.s64 + 2672;
loc_8228BE2C:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x8228BE34;
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
	ctx.lr = 0x8228BE48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228BE54;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228BE64;
	sub_82270170(ctx, base);
	// add r8,r3,r28
	ctx.r8.u64 = ctx.r3.u64 + r28.u64;
	// addic. r31,r8,312
	xer.ca = ctx.r8.u32 > 4294966983;
	r31.s64 = ctx.r8.s64 + 312;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x8228beb4
	if (cr0.eq) goto loc_8228BEB4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825006a0
	ctx.lr = 0x8228BE78;
	sub_825006A0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x8228BE88;
	sub_827227B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825006a8
	ctx.lr = 0x8228BE90;
	sub_825006A8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// xori r8,r9,1
	ctx.r8.u64 = ctx.r9.u64 ^ 1;
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// bl 0x82722678
	ctx.lr = 0x8228BEB4;
	sub_82722678(ctx, base);
loc_8228BEB4:
	// lwz r11,80(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 80);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r28,r28,196
	r28.s64 = r28.s64 + 196;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x8228be2c
	if (cr6.lt) goto loc_8228BE2C;
loc_8228BEC8:
	// lwz r3,68(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 68);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8228BED4"))) PPC_WEAK_FUNC(sub_8228BED4);
PPC_FUNC_IMPL(__imp__sub_8228BED4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228BED8"))) PPC_WEAK_FUNC(sub_8228BED8);
PPC_FUNC_IMPL(__imp__sub_8228BED8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	ctx.lr = 0x8228BEE0;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-19636
	ctx.r4.s64 = ctx.r10.s64 + -19636;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8228BEFC;
	sub_821F9FB8(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,56(r19)
	r31.u64 = PPC_LOAD_U32(r19.u32 + 56);
	// bl 0x8227d3a0
	ctx.lr = 0x8228BF0C;
	sub_8227D3A0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8228bf34
	if (!cr6.eq) goto loc_8228BF34;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,6008
	ctx.r4.s64 = r11.s64 + 6008;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8228BF2C;
	sub_825EE0E0(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9224
	return;
loc_8228BF34:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r30,r11,5996
	r30.s64 = r11.s64 + 5996;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x8228BF48;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8228BF58;
	sub_825ED480(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r8,r10,-12116
	ctx.r8.s64 = ctx.r10.s64 + -12116;
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// stw r8,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r8.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x821c9790
	ctx.lr = 0x8228BF84;
	sub_821C9790(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r6.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8228BF98;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228BFB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x825ef9f0
	ctx.lr = 0x8228BFB8;
	sub_825EF9F0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8228BFD0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8228c1ac
	if (!cr6.gt) goto loc_8228C1AC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r21,0(r13)
	r21.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// li r20,72
	r20.s64 = 72;
	// li r22,8
	r22.s64 = 8;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// addi r24,r11,20304
	r24.s64 = r11.s64 + 20304;
	// addi r26,r10,5984
	r26.s64 = ctx.r10.s64 + 5984;
	// addi r25,r9,-23048
	r25.s64 = ctx.r9.s64 + -23048;
loc_8228C000:
	// lhz r11,0(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 0);
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,114
	ctx.r3.s64 = ctx.r1.s64 + 114;
	// sth r11,112(r1)
	PPC_STORE_U16(ctx.r1.u32 + 112, r11.u16);
	// bl 0x823d9890
	ctx.lr = 0x8228C018;
	sub_823D9890(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r31,r1,112
	r31.s64 = ctx.r1.s64 + 112;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C034;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82722238
	ctx.lr = 0x8228C040;
	sub_82722238(ctx, base);
	// lbzx r9,r20,r21
	ctx.r9.u64 = PPC_LOAD_U8(r20.u32 + r21.u32);
	// lwz r3,17268(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 17268);
	// mr r27,r25
	r27.u64 = r25.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228c078
	if (cr6.eq) goto loc_8228C078;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x8228c09c
	if (cr6.lt) goto loc_8228C09C;
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x8228c09c
	if (!cr6.lt) goto loc_8228C09C;
	// add r11,r22,r3
	r11.u64 = r22.u64 + ctx.r3.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// b 0x8228c094
	goto loc_8228C094;
loc_8228C078:
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// blt cr6,0x8228c09c
	if (cr6.lt) goto loc_8228C09C;
	// lwz r11,132(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 132);
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// bge cr6,0x8228c09c
	if (!cr6.lt) goto loc_8228C09C;
	// lwzx r11,r22,r3
	r11.u64 = PPC_LOAD_U32(r22.u32 + ctx.r3.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
loc_8228C094:
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8228c0a0
	if (!cr6.eq) goto loc_8228C0A0;
loc_8228C09C:
	// li r11,0
	r11.s64 = 0;
loc_8228C0A0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c120
	if (cr6.eq) goto loc_8228C120;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x822a3998
	ctx.lr = 0x8228C0B4;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228c0c8
	if (cr6.eq) goto loc_8228C0C8;
	// lwz r31,1220(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 1220);
	// b 0x8228c0cc
	goto loc_8228C0CC;
loc_8228C0C8:
	// li r31,0
	r31.s64 = 0;
loc_8228C0CC:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228c120
	if (cr6.eq) goto loc_8228C120;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8228C0DC;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c120
	if (!cr6.eq) goto loc_8228C120;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x8228C0F0;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c120
	if (cr6.eq) goto loc_8228C120;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c120
	if (!cr6.eq) goto loc_8228C120;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C11C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
loc_8228C120:
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
loc_8228C128:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8228c14c
	if (cr6.eq) goto loc_8228C14C;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8228c128
	if (cr6.eq) goto loc_8228C128;
loc_8228C14C:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8228c188
	if (cr6.eq) goto loc_8228C188;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x827205a8
	ctx.lr = 0x8228C164;
	sub_827205A8(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C17C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x827227b8
	ctx.lr = 0x8228C188;
	sub_827227B8(ctx, base);
loc_8228C188:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r22,r22,4
	r22.s64 = r22.s64 + 4;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C1A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228c000
	if (cr6.lt) goto loc_8228C000;
loc_8228C1AC:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9224
	return;
}

__attribute__((alias("__imp__sub_8228C1B4"))) PPC_WEAK_FUNC(sub_8228C1B4);
PPC_FUNC_IMPL(__imp__sub_8228C1B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228C1B8"))) PPC_WEAK_FUNC(sub_8228C1B8);
PPC_FUNC_IMPL(__imp__sub_8228C1B8) {
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
	// bl 0x82635538
	ctx.lr = 0x8228C1D0;
	sub_82635538(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,72(r31)
	PPC_STORE_U32(r31.u32 + 72, r11.u32);
	// bl 0x82387b90
	ctx.lr = 0x8228C1DC;
	sub_82387B90(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lwz r9,1344(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lfs f0,14192(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 80, temp.u32);
	// stw r9,76(r31)
	PPC_STORE_U32(r31.u32 + 76, ctx.r9.u32);
	// lwz r3,-10028(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10028);
	// bl 0x82211210
	ctx.lr = 0x8228C1FC;
	sub_82211210(ctx, base);
	// addi r7,r3,1
	ctx.r7.s64 = ctx.r3.s64 + 1;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// rlwinm r5,r6,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// xori r4,r5,1
	ctx.r4.u64 = ctx.r5.u64 ^ 1;
	// bl 0x8228b700
	ctx.lr = 0x8228C214;
	sub_8228B700(ctx, base);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r11,-3624(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e750
	ctx.lr = 0x8228C224;
	sub_8227E750(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228c258
	if (cr6.eq) goto loc_8228C258;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228C238;
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
	ctx.lr = 0x8228C24C;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x8228C258;
	sub_82274128(ctx, base);
loc_8228C258:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lfs f1,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// lwz r9,188(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 188);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228C274;
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

__attribute__((alias("__imp__sub_8228C288"))) PPC_WEAK_FUNC(sub_8228C288);
PPC_FUNC_IMPL(__imp__sub_8228C288) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x8228C290;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r23,r4
	r23.u64 = ctx.r4.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r21,r8
	r21.u64 = ctx.r8.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// bne cr6,0x8228c5e0
	if (!cr6.eq) goto loc_8228C5E0;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// cmpwi cr6,r11,56
	cr6.compare<int32_t>(r11.s32, 56, xer);
	// beq cr6,0x8228c604
	if (cr6.eq) goto loc_8228C604;
	// cmpwi cr6,r11,57
	cr6.compare<int32_t>(r11.s32, 57, xer);
	// bne cr6,0x8228c5e0
	if (!cr6.eq) goto loc_8228C5E0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8228C2F0;
	sub_822701C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228c5d4
	if (cr6.eq) goto loc_8228C5D4;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82295e90
	ctx.lr = 0x8228C304;
	sub_82295E90(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// cntlzw r10,r3
	ctx.r10.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// addi r31,r11,6080
	r31.s64 = r11.s64 + 6080;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// rlwinm r26,r10,27,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8228C31C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8228c340
	if (cr6.eq) goto loc_8228C340;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8228c31c
	if (cr6.eq) goto loc_8228C31C;
loc_8228C340:
	// lis r27,-32115
	r27.s64 = -2104688640;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8228c57c
	if (!cr6.eq) goto loc_8228C57C;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c57c
	if (cr6.eq) goto loc_8228C57C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228C364;
	sub_82295E90(ctx, base);
	// lwz r11,-12672(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -12672);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x8228c57c
	if (cr6.eq) goto loc_8228C57C;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8228C37C;
	sub_821E6800(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r10,-10236(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// li r9,352
	ctx.r9.s64 = 352;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r3,-32130
	ctx.r3.s64 = -2105671680;
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
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
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,52(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8228C3C8;
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
	ctx.lr = 0x8228C3DC;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
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
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82625f50
	ctx.lr = 0x8228C400;
	sub_82625F50(ctx, base);
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8228C40C;
	sub_8238EC00(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// bl 0x82295e90
	ctx.lr = 0x8228C428;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82389668
	ctx.lr = 0x8228C438;
	sub_82389668(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// addi r30,r29,88
	r30.s64 = r29.s64 + 88;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,88(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 88);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r8,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r6,28(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8228C470;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r5,80(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8228c498
	if (cr6.eq) goto loc_8228C498;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 112, temp.u32);
	// stfs f13,116(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 116, temp.u32);
	// stfs f0,120(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 120, temp.u32);
loc_8228C498:
	// stw r30,100(r29)
	PPC_STORE_U32(r29.u32 + 100, r30.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r10,-2
	ctx.r8.s64 = ctx.r10.s64 + -2;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r30,248(r11)
	PPC_STORE_U32(r11.u32 + 248, r30.u32);
	// addi r3,r9,6048
	ctx.r3.s64 = ctx.r9.s64 + 6048;
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stb r6,252(r11)
	PPC_STORE_U8(r11.u32 + 252, ctx.r6.u8);
	// bl 0x821fa230
	ctx.lr = 0x8228C4C8;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,112(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 112);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8228C4DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C4F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,96(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8228C50C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r3,r7,-1992
	ctx.r3.s64 = ctx.r7.s64 + -1992;
	// bl 0x821fa230
	ctx.lr = 0x8228C518;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r5,132(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 132);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8228C52C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,108(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 108);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8228C540;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,64(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228C558;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228C570;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d922c
	return;
loc_8228C57C:
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
loc_8228C584:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x8228c5a8
	if (cr6.eq) goto loc_8228C5A8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8228c584
	if (cr6.eq) goto loc_8228C584;
loc_8228C5A8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8228c5e0
	if (!cr6.eq) goto loc_8228C5E0;
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c5e0
	if (cr6.eq) goto loc_8228C5E0;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228C5C8;
	sub_82295E90(ctx, base);
	// lwz r11,-12672(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -12672);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bne cr6,0x8228c5e0
	if (!cr6.eq) goto loc_8228C5E0;
loc_8228C5D4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8228C5E0;
	sub_821E6800(ctx, base);
loc_8228C5E0:
	// mr r8,r21
	ctx.r8.u64 = r21.u64;
	// mr r7,r24
	ctx.r7.u64 = r24.u64;
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82635be0
	ctx.lr = 0x8228C5FC;
	sub_82635BE0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d922c
	return;
loc_8228C604:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,68(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 68);
	// addi r4,r11,6028
	ctx.r4.s64 = r11.s64 + 6028;
	// bl 0x8268dce0
	ctx.lr = 0x8228C614;
	sub_8268DCE0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228c5e0
	if (cr6.eq) goto loc_8228C5E0;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C62C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228c5e0
	if (cr6.eq) goto loc_8228C5E0;
	// lbz r11,84(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 84);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c66c
	if (cr6.eq) goto loc_8228C66C;
	// lwz r3,-10028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// bl 0x82211210
	ctx.lr = 0x8228C650;
	sub_82211210(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x8228c66c
	if (cr6.eq) goto loc_8228C66C;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// bl 0x82212200
	ctx.lr = 0x8228C664;
	sub_82212200(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x8228c678
	goto loc_8228C678;
loc_8228C66C:
	// lwz r3,-10028(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10028);
	// bl 0x82212608
	ctx.lr = 0x8228C674;
	sub_82212608(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
loc_8228C678:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8228b700
	ctx.lr = 0x8228C680;
	sub_8228B700(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8228C68C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_8228C698"))) PPC_WEAK_FUNC(sub_8228C698);
PPC_FUNC_IMPL(__imp__sub_8228C698) {
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
	ctx.lr = 0x8228C6A0;
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lbz r10,103(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 103);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r29,r7,27,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bne cr6,0x8228c748
	if (!cr6.eq) goto loc_8228C748;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lbz r11,17(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c6fc
	if (!cr6.eq) goto loc_8228C6FC;
	// lbz r11,16(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x8228c700
	if (cr6.eq) goto loc_8228C700;
loc_8228C6FC:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8228C700:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c72c
	if (!cr6.eq) goto loc_8228C72C;
	// bl 0x822a7cc8
	ctx.lr = 0x8228C710;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c72c
	if (cr6.eq) goto loc_8228C72C;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x8228c748
	if (!cr6.eq) goto loc_8228C748;
loc_8228C72C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228C738;
	sub_822A39C8(ctx, base);
	// lwz r4,80(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b1648
	ctx.lr = 0x8228C744;
	sub_822B1648(ctx, base);
	// stb r28,102(r31)
	PPC_STORE_U8(r31.u32 + 102, r28.u8);
loc_8228C748:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C768;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8228c868
	if (!cr6.eq) goto loc_8228C868;
	// bl 0x82207e88
	ctx.lr = 0x8228C778;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c868
	if (!cr6.eq) goto loc_8228C868;
	// lwz r3,80(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lbz r11,17(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 17);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c7a4
	if (!cr6.eq) goto loc_8228C7A4;
	// lbz r11,16(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r27
	r11.u64 = r27.u64;
	// beq cr6,0x8228c7a8
	if (cr6.eq) goto loc_8228C7A8;
loc_8228C7A4:
	// mr r11,r28
	r11.u64 = r28.u64;
loc_8228C7A8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c80c
	if (!cr6.eq) goto loc_8228C80C;
	// bl 0x822a7cc8
	ctx.lr = 0x8228C7B8;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c80c
	if (cr6.eq) goto loc_8228C80C;
	// lwz r11,80(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8228c80c
	if (cr6.eq) goto loc_8228C80C;
	// lbz r10,102(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 102);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228c80c
	if (!cr6.eq) goto loc_8228C80C;
	// lbz r10,103(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 103);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228c80c
	if (!cr6.eq) goto loc_8228C80C;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,1220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x8228C7F8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8228c868
	if (!cr6.eq) goto loc_8228C868;
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c868
	if (!cr6.eq) goto loc_8228C868;
loc_8228C80C:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// beq cr6,0x8228c834
	if (cr6.eq) goto loc_8228C834;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-2012
	ctx.r3.s64 = ctx.r10.s64 + -2012;
	// b 0x8228c83c
	goto loc_8228C83C;
loc_8228C834:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-2032
	ctx.r3.s64 = ctx.r10.s64 + -2032;
loc_8228C83C:
	// bl 0x821fa230
	ctx.lr = 0x8228C840;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228C854;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228C868:
	// lbz r11,100(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c974
	if (cr6.eq) goto loc_8228C974;
	// lfs f0,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	f0.f64 = double(temp.f32);
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// lis r11,-32254
	r11.s64 = -2113798144;
	// stfs f13,96(r31)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// addi r30,r11,-1304
	r30.s64 = r11.s64 + -1304;
	// lfs f0,3732(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8228c8fc
	if (!cr6.gt) goto loc_8228C8FC;
	// lbz r11,101(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 101);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228c8fc
	if (!cr6.eq) goto loc_8228C8FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821fa230
	ctx.lr = 0x8228C8AC;
	sub_821FA230(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228C8C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r8,96(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 96);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8228C8D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r6,64(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 64);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8228C8F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r28,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r28.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8228bc30
	ctx.lr = 0x8228C8FC;
	sub_8228BC30(ctx, base);
loc_8228C8FC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lfs f13,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,6088(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 6088);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x8228c974
	if (!cr6.gt) goto loc_8228C974;
	// bl 0x8221fa88
	ctx.lr = 0x8228C914;
	sub_8221FA88(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stb r27,100(r31)
	PPC_STORE_U8(r31.u32 + 100, r27.u8);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r27,101(r31)
	PPC_STORE_U8(r31.u32 + 101, r27.u8);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,96(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 96, temp.u32);
	// bl 0x821fa230
	ctx.lr = 0x8228C930;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,112(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 112);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228C944;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r7,96(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 96);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228C95C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,64(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 64);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8228C974;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228C974:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,26
	ctx.r4.s64 = 26;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x8220f040
	ctx.lr = 0x8228C984;
	sub_8220F040(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228C990"))) PPC_WEAK_FUNC(sub_8228C990);
PPC_FUNC_IMPL(__imp__sub_8228C990) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91cc
	ctx.lr = 0x8228C998;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r22,r5
	r22.u64 = ctx.r5.u64;
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r19,r4
	r19.u64 = ctx.r4.u64;
	// mr r18,r6
	r18.u64 = ctx.r6.u64;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// mr r28,r7
	r28.u64 = ctx.r7.u64;
	// mr r17,r8
	r17.u64 = ctx.r8.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r22,r10
	cr6.compare<uint32_t>(r22.u32, ctx.r10.u32, xer);
	// bne cr6,0x8228cc4c
	if (!cr6.eq) goto loc_8228CC4C;
	// lbz r11,100(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228cc8c
	if (!cr6.eq) goto loc_8228CC8C;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x8221d660
	ctx.lr = 0x8228C9E4;
	sub_8221D660(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228c9fc
	if (cr6.eq) goto loc_8228C9FC;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// bne cr6,0x8228cc4c
	if (!cr6.eq) goto loc_8228CC4C;
loc_8228C9FC:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// cmplwi cr6,r11,64
	cr6.compare<uint32_t>(r11.u32, 64, xer);
	// lwz r10,-3624(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r10,700(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r20,r8,27,31,31
	r20.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// bgt cr6,0x8228cd98
	if (cr6.gt) goto loc_8228CD98;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,-13764
	r12.s64 = r12.s64 + -13764;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8228CCB8;
	case 1:
		goto loc_8228CD98;
	case 2:
		goto loc_8228CB40;
	case 3:
		goto loc_8228CB40;
	case 4:
		goto loc_8228CD98;
	case 5:
		goto loc_8228CD98;
	case 6:
		goto loc_8228CD98;
	case 7:
		goto loc_8228CD98;
	case 8:
		goto loc_8228CD98;
	case 9:
		goto loc_8228CD98;
	case 10:
		goto loc_8228CD98;
	case 11:
		goto loc_8228CD98;
	case 12:
		goto loc_8228CD98;
	case 13:
		goto loc_8228CD98;
	case 14:
		goto loc_8228CD98;
	case 15:
		goto loc_8228CD98;
	case 16:
		goto loc_8228CD98;
	case 17:
		goto loc_8228CD98;
	case 18:
		goto loc_8228CD98;
	case 19:
		goto loc_8228CD98;
	case 20:
		goto loc_8228CD98;
	case 21:
		goto loc_8228CD98;
	case 22:
		goto loc_8228CD98;
	case 23:
		goto loc_8228CD98;
	case 24:
		goto loc_8228CD98;
	case 25:
		goto loc_8228CD98;
	case 26:
		goto loc_8228CD98;
	case 27:
		goto loc_8228CD98;
	case 28:
		goto loc_8228CD98;
	case 29:
		goto loc_8228CD98;
	case 30:
		goto loc_8228CD98;
	case 31:
		goto loc_8228CD98;
	case 32:
		goto loc_8228CD98;
	case 33:
		goto loc_8228CD98;
	case 34:
		goto loc_8228CD98;
	case 35:
		goto loc_8228CD98;
	case 36:
		goto loc_8228CD98;
	case 37:
		goto loc_8228CD98;
	case 38:
		goto loc_8228CD98;
	case 39:
		goto loc_8228CD98;
	case 40:
		goto loc_8228CD98;
	case 41:
		goto loc_8228CD98;
	case 42:
		goto loc_8228CD98;
	case 43:
		goto loc_8228CD98;
	case 44:
		goto loc_8228CC8C;
	case 45:
		goto loc_8228CCDC;
	case 46:
		goto loc_8228CD98;
	case 47:
		goto loc_8228CD98;
	case 48:
		goto loc_8228CD98;
	case 49:
		goto loc_8228CC98;
	case 50:
		goto loc_8228CD98;
	case 51:
		goto loc_8228CD98;
	case 52:
		goto loc_8228CD98;
	case 53:
		goto loc_8228CD98;
	case 54:
		goto loc_8228CD98;
	case 55:
		goto loc_8228CD98;
	case 56:
		goto loc_8228CD98;
	case 57:
		goto loc_8228CD98;
	case 58:
		goto loc_8228CD98;
	case 59:
		goto loc_8228CD98;
	case 60:
		goto loc_8228CD98;
	case 61:
		goto loc_8228CD98;
	case 62:
		goto loc_8228CD98;
	case 63:
		goto loc_8228CD98;
	case 64:
		goto loc_8228CC8C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-13128(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -13128);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-13504(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -13504);
	// lwz r17,-13504(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -13504);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-13172(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -13172);
	// lwz r17,-13092(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -13092);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-13160(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -13160);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-12904(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12904);
	// lwz r17,-13172(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -13172);
loc_8228CB40:
	// lwz r11,80(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 80);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r23,0
	r23.s64 = 0;
	// lwz r3,1220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 1220);
	// bl 0x822051a0
	ctx.lr = 0x8228CB54;
	sub_822051A0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// addi r26,r11,-12464
	r26.s64 = r11.s64 + -12464;
loc_8228CB68:
	// lbz r11,100(r21)
	r11.u64 = PPC_LOAD_U8(r21.u32 + 100);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228cc34
	if (!cr6.eq) goto loc_8228CC34;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8228CB80;
	sub_821F9FB8(ctx, base);
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,11
	cr6.compare<int32_t>(r11.s32, 11, xer);
	// bne cr6,0x8228cba4
	if (!cr6.eq) goto loc_8228CBA4;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// cmpwi cr6,r31,31
	cr6.compare<int32_t>(r31.s32, 31, xer);
	// blt cr6,0x8228cbb0
	if (cr6.lt) goto loc_8228CBB0;
	// li r31,0
	r31.s64 = 0;
	// b 0x8228cbb0
	goto loc_8228CBB0;
loc_8228CBA4:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bge 0x8228cbb0
	if (!cr0.lt) goto loc_8228CBB0;
	// li r31,30
	r31.s64 = 30;
loc_8228CBB0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228CBB8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228CBC8;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822051a0
	ctx.lr = 0x8228CBD0;
	sub_822051A0(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// beq cr6,0x8228cc34
	if (cr6.eq) goto loc_8228CC34;
	// lwz r30,17268(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + 17268);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8228CBE8;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228cc34
	if (cr6.eq) goto loc_8228CC34;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8228CC00;
	sub_822A3998(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x8228CC0C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// beq cr6,0x8228cc20
	if (cr6.eq) goto loc_8228CC20;
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228cc34
	if (cr6.eq) goto loc_8228CC34;
loc_8228CC20:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82720558
	ctx.lr = 0x8228CC28;
	sub_82720558(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228cc70
	if (cr6.eq) goto loc_8228CC70;
loc_8228CC34:
	// addi r23,r23,1
	r23.s64 = r23.s64 + 1;
	// cmpwi cr6,r23,31
	cr6.compare<int32_t>(r23.s32, 31, xer);
	// blt cr6,0x8228cb68
	if (cr6.lt) goto loc_8228CB68;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8228CC4C;
	sub_821E6800(ctx, base);
loc_8228CC4C:
	// mr r8,r17
	ctx.r8.u64 = r17.u64;
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// mr r6,r18
	ctx.r6.u64 = r18.u64;
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// mr r4,r19
	ctx.r4.u64 = r19.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x82635be0
	ctx.lr = 0x8228CC68;
	sub_82635BE0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
loc_8228CC70:
	// li r11,1
	r11.s64 = 1;
	// stw r31,84(r21)
	PPC_STORE_U32(r21.u32 + 84, r31.u32);
	// stb r11,100(r21)
	PPC_STORE_U8(r21.u32 + 100, r11.u8);
	// bl 0x8221f980
	ctx.lr = 0x8228CC80;
	sub_8221F980(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// lwz r3,24588(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8228CC8C;
	sub_821E6800(ctx, base);
loc_8228CC8C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
loc_8228CC98:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228CCA4;
	sub_822A39C8(ctx, base);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b1110
	ctx.lr = 0x8228CCAC;
	sub_822B1110(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
loc_8228CCB8:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228CCC4;
	sub_822A39C8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b23d0
	ctx.lr = 0x8228CCD0;
	sub_822B23D0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
loc_8228CCDC:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,28(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228CCF8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8228cd84
	if (!cr6.eq) goto loc_8228CD84;
	// bl 0x82207e88
	ctx.lr = 0x8228CD08;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228cd84
	if (!cr6.eq) goto loc_8228CD84;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bne cr6,0x8228cd44
	if (!cr6.eq) goto loc_8228CD44;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-2012
	ctx.r3.s64 = ctx.r10.s64 + -2012;
	// b 0x8228cd4c
	goto loc_8228CD4C;
loc_8228CD44:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r3,r10,-2032
	ctx.r3.s64 = ctx.r10.s64 + -2032;
loc_8228CD4C:
	// bl 0x821fa230
	ctx.lr = 0x8228CD50;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,32(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228CD64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 0);
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228CD78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
loc_8228CD84:
	// li r11,1
	r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,103(r21)
	PPC_STORE_U8(r21.u32 + 103, r11.u8);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
loc_8228CD98:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x8228CDA4;
	sub_822A39C8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822b23d0
	ctx.lr = 0x8228CDB0;
	sub_822B23D0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
}

__attribute__((alias("__imp__sub_8228CDBC"))) PPC_WEAK_FUNC(sub_8228CDBC);
PPC_FUNC_IMPL(__imp__sub_8228CDBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228CDC0"))) PPC_WEAK_FUNC(sub_8228CDC0);
PPC_FUNC_IMPL(__imp__sub_8228CDC0) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8228CDC8;
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r29,672
	ctx.r3.s64 = r29.s64 + 672;
	// bl 0x82631f88
	ctx.lr = 0x8228CDD8;
	sub_82631F88(ctx, base);
	// lwz r11,856(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 856);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228cde8
	if (cr6.lt) goto loc_8228CDE8;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8228CDE8:
	// li r30,0
	r30.s64 = 0;
	// stw r11,980(r29)
	PPC_STORE_U32(r29.u32 + 980, r11.u32);
	// cmplwi cr6,r11,50
	cr6.compare<uint32_t>(r11.u32, 50, xer);
	// ble cr6,0x8228cdfc
	if (!cr6.gt) goto loc_8228CDFC;
	// stw r30,980(r29)
	PPC_STORE_U32(r29.u32 + 980, r30.u32);
loc_8228CDFC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,980(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 980);
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// bl 0x82298f08
	ctx.lr = 0x8228CE10;
	sub_82298F08(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r31,r30
	r31.u64 = r30.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8228cfd4
	if (cr6.eq) goto loc_8228CFD4;
	// lbz r10,624(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 624);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,624(r1)
	PPC_STORE_U8(ctx.r1.u32 + 624, ctx.r9.u8);
	// bl 0x8226b078
	ctx.lr = 0x8228CE34;
	sub_8226B078(ctx, base);
	// addi r4,r28,44
	ctx.r4.s64 = r28.s64 + 44;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824ea1b0
	ctx.lr = 0x8228CE40;
	sub_824EA1B0(ctx, base);
	// ld r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 116);
	// li r11,1
	r11.s64 = 1;
	// rlwinm r7,r8,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// bne cr6,0x8228ce58
	if (!cr6.eq) goto loc_8228CE58;
	// mr r11,r30
	r11.u64 = r30.u64;
loc_8228CE58:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ce68
	if (cr6.eq) goto loc_8228CE68;
	// lwz r31,224(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
loc_8228CE68:
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// cmplwi cr6,r11,2
	cr6.compare<uint32_t>(r11.u32, 2, xer);
	// bne cr6,0x8228ce8c
	if (!cr6.eq) goto loc_8228CE8C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r30,248(r10)
	PPC_STORE_U32(ctx.r10.u32 + 248, r30.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d923c
	return;
loc_8228CE8C:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x8228cfd4
	if (cr6.eq) goto loc_8228CFD4;
	// lwz r11,128(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8228cfd4
	if (cr6.eq) goto loc_8228CFD4;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// li r10,352
	ctx.r10.s64 = 352;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r11,-10220(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10220);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lfs f0,6076(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 6076);
	f0.f64 = double(temp.f32);
	// addi r4,r7,6092
	ctx.r4.s64 = ctx.r7.s64 + 6092;
	// addi r26,r6,-19728
	r26.s64 = ctx.r6.s64 + -19728;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r25,r5,-22108
	r25.s64 = ctx.r5.s64 + -22108;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8228CEF8;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8228CF0C;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10220(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10220);
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
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82625f50
	ctx.lr = 0x8228CF30;
	sub_82625F50(ctx, base);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lwz r3,-27856(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8228CF3C;
	sub_8238EC00(ctx, base);
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82389668
	ctx.lr = 0x8228CF50;
	sub_82389668(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r30,r29,988
	r30.s64 = r29.s64 + 988;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// lwz r10,988(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 988);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228CF88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8228cfb0
	if (cr6.eq) goto loc_8228CFB0;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,1008(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 1008, temp.u32);
	// stfs f13,1012(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 1012, temp.u32);
	// stfs f0,1016(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 1016, temp.u32);
loc_8228CFB0:
	// stw r30,1000(r29)
	PPC_STORE_U32(r29.u32 + 1000, r30.u32);
	// lwz r11,-10236(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10236);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r30,248(r11)
	PPC_STORE_U32(r11.u32 + 248, r30.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,252(r11)
	PPC_STORE_U8(r11.u32 + 252, ctx.r8.u8);
loc_8228CFD4:
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8228CFDC"))) PPC_WEAK_FUNC(sub_8228CFDC);
PPC_FUNC_IMPL(__imp__sub_8228CFDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228CFE0"))) PPC_WEAK_FUNC(sub_8228CFE0);
PPC_FUNC_IMPL(__imp__sub_8228CFE0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x8228CFE8;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
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
	ctx.lr = 0x8228D008;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228d35c
	if (cr6.eq) goto loc_8228D35C;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8221df70
	ctx.lr = 0x8228D024;
	sub_8221DF70(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228d35c
	if (!cr6.eq) goto loc_8228D35C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// bl 0x82298e40
	ctx.lr = 0x8228D040;
	sub_82298E40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228d12c
	if (!cr6.eq) goto loc_8228D12C;
	// addi r11,r28,-47
	r11.s64 = r28.s64 + -47;
	// cmplwi cr6,r11,16
	cr6.compare<uint32_t>(r11.u32, 16, xer);
	// bgt cr6,0x8228d4b0
	if (cr6.gt) goto loc_8228D4B0;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,-12176
	r12.s64 = r12.s64 + -12176;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8228D0B4;
	case 1:
		goto loc_8228D0B4;
	case 2:
		goto loc_8228D0B4;
	case 3:
		goto loc_8228D0B4;
	case 4:
		goto loc_8228D4B0;
	case 5:
		goto loc_8228D4B0;
	case 6:
		goto loc_8228D4B0;
	case 7:
		goto loc_8228D4B0;
	case 8:
		goto loc_8228D0D8;
	case 9:
		goto loc_8228D2EC;
	case 10:
		goto loc_8228D4B0;
	case 11:
		goto loc_8228D4B0;
	case 12:
		goto loc_8228D4B0;
	case 13:
		goto loc_8228D4B0;
	case 14:
		goto loc_8228D4B0;
	case 15:
		goto loc_8228D368;
	case 16:
		goto loc_8228D414;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-12108(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12108);
	// lwz r17,-12108(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12108);
	// lwz r17,-12108(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12108);
	// lwz r17,-12108(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12108);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-12072(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12072);
	// lwz r17,-11540(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11540);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-11088(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11088);
	// lwz r17,-11416(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11416);
	// lwz r17,-11244(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -11244);
loc_8228D0B4:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8228D0C4;
	sub_826537D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8228cdc0
	ctx.lr = 0x8228D0CC;
	sub_8228CDC0(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D0D8:
	// addi r31,r31,672
	r31.s64 = r31.s64 + 672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203240
	ctx.lr = 0x8228D0E4;
	sub_82203240(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// bl 0x82298f08
	ctx.lr = 0x8228D0F4;
	sub_82298F08(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x8228d138
	if (!cr6.eq) goto loc_8228D138;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,3
	ctx.r4.s64 = 3;
loc_8228D110:
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8228D120;
	sub_8268EE10(ctx, base);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lwz r3,24612(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8228D12C;
	sub_821E6800(ctx, base);
loc_8228D12C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D138:
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
	ctx.lr = 0x8228D158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8228d178
	if (!cr6.eq) goto loc_8228D178;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,39
	ctx.r4.s64 = 39;
	// b 0x8228d110
	goto loc_8228D110;
loc_8228D178:
	// addi r31,r29,44
	r31.s64 = r29.s64 + 44;
	// bl 0x82387b90
	ctx.lr = 0x8228D180;
	sub_82387B90(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x8228D188;
	sub_8238B7E0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bge cr6,0x8228d1a8
	if (!cr6.lt) goto loc_8228D1A8;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8228D19C;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D1A8:
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82500ef8
	ctx.lr = 0x8228D1B4;
	sub_82500EF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228d2b4
	if (cr6.eq) goto loc_8228D2B4;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8228d1f8
	if (!cr6.eq) goto loc_8228D1F8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228D1D4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228D1E4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x8228D1EC;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228d2b4
	if (cr6.eq) goto loc_8228D2B4;
loc_8228D1F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228D200;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r31,-3624(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// bl 0x82270170
	ctx.lr = 0x8228D218;
	sub_82270170(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x822705d8
	ctx.lr = 0x8228D22C;
	sub_822705D8(ctx, base);
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,30
	ctx.r4.s64 = 30;
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8228D248;
	sub_8268EE10(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8228D258;
	sub_822A3998(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// lwz r31,-10220(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// bl 0x822afa10
	ctx.lr = 0x8228D268;
	sub_822AFA10(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8261fec0
	ctx.lr = 0x8228D274;
	sub_8261FEC0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8228D280;
	sub_822A3998(ctx, base);
	// lwz r31,-10220(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lwz r3,880(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 880);
	// bl 0x822afa30
	ctx.lr = 0x8228D28C;
	sub_822AFA30(ctx, base);
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f1,1524(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(r31.u32 + 1524, temp.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// stb r9,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r9.u8);
	// lwz r3,24588(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8228D2A8;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D2B4:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x8228D2C0;
	sub_821E6800(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r11,-3624(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x8228D2E0;
	sub_8268EE10(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D2EC:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r10,6104
	ctx.r4.s64 = ctx.r10.s64 + 6104;
	// addi r30,r9,-7660
	r30.s64 = ctx.r9.s64 + -7660;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r29,r8,-22108
	r29.s64 = ctx.r8.s64 + -22108;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8228D314;
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
	ctx.lr = 0x8228D328;
	sub_823DEDD8(ctx, base);
	// li r30,1
	r30.s64 = 1;
	// lis r7,-32126
	ctx.r7.s64 = -2105409536;
	// stb r30,164(r3)
	PPC_STORE_U8(ctx.r3.u32 + 164, r30.u8);
	// lwz r3,24592(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24592);
	// bl 0x821e6800
	ctx.lr = 0x8228D33C;
	sub_821E6800(ctx, base);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// lwz r11,-10220(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + -10220);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r30,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, r30.u8);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r4,736(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 736);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x8228D35C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228D35C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D368:
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,980(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 980);
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// bl 0x82298f08
	ctx.lr = 0x8228D378;
	sub_82298F08(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228d12c
	if (cr6.eq) goto loc_8228D12C;
	// lbz r10,592(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 592);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r29,0
	r29.s64 = 0;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,592(r1)
	PPC_STORE_U8(ctx.r1.u32 + 592, ctx.r9.u8);
	// bl 0x8226b078
	ctx.lr = 0x8228D39C;
	sub_8226B078(ctx, base);
	// addi r4,r30,44
	ctx.r4.s64 = r30.s64 + 44;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824ea1b0
	ctx.lr = 0x8228D3A8;
	sub_824EA1B0(ctx, base);
	// ld r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 84);
	// li r30,1
	r30.s64 = 1;
	// rlwinm r7,r8,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// mr r11,r30
	r11.u64 = r30.u64;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// bne cr6,0x8228d3c4
	if (!cr6.eq) goto loc_8228D3C4;
	// li r11,0
	r11.s64 = 0;
loc_8228D3C4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228d3d4
	if (cr6.eq) goto loc_8228D3D4;
	// lwz r29,192(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
loc_8228D3D4:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x8228d12c
	if (cr6.eq) goto loc_8228D12C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228D3F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r30,985(r31)
	PPC_STORE_U8(r31.u32 + 985, r30.u8);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8228D408;
	sub_821E6800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D414:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x8228D428;
	sub_8221D6A8(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// lwz r3,24588(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8228D434;
	sub_821E6800(ctx, base);
	// lbz r9,984(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 984);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// bne cr6,0x8228d470
	if (!cr6.eq) goto loc_8228D470;
	// bl 0x821f9fb8
	ctx.lr = 0x8228D450;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228d45c
	if (cr6.eq) goto loc_8228D45C;
	// bl 0x82720560
	ctx.lr = 0x8228D45C;
	sub_82720560(ctx, base);
loc_8228D45C:
	// li r11,1
	r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,984(r31)
	PPC_STORE_U8(r31.u32 + 984, r11.u8);
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D470:
	// bl 0x821f9fb8
	ctx.lr = 0x8228D474;
	sub_821F9FB8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228d49c
	if (cr6.eq) goto loc_8228D49C;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x8228D488;
	sub_82720E28(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-19772
	ctx.r4.s64 = r11.s64 + -19772;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827205a8
	ctx.lr = 0x8228D49C;
	sub_827205A8(ctx, base);
loc_8228D49C:
	// li r11,0
	r11.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,984(r31)
	PPC_STORE_U8(r31.u32 + 984, r11.u8);
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
loc_8228D4B0:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826537d0
	ctx.lr = 0x8228D4C0;
	sub_826537D0(ctx, base);
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228D4C8"))) PPC_WEAK_FUNC(sub_8228D4C8);
PPC_FUNC_IMPL(__imp__sub_8228D4C8) {
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
	ctx.lr = 0x8228D4D0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82632f78
	ctx.lr = 0x8228D4DC;
	sub_82632F78(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8228cdc0
	ctx.lr = 0x8228D4E4;
	sub_8228CDC0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,45
	ctx.r4.s64 = 45;
	// lwz r3,-10028(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10028);
	// bl 0x8220f040
	ctx.lr = 0x8228D4F4;
	sub_8220F040(ctx, base);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r9,7
	ctx.r9.s64 = 7;
	// addi r3,r10,-12116
	ctx.r3.s64 = ctx.r10.s64 + -12116;
	// li r29,0
	r29.s64 = 0;
	// stw r9,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r29.u32);
	// bl 0x821c9790
	ctx.lr = 0x8228D518;
	sub_821C9790(ctx, base);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r7,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r7.u32);
	// lwz r6,496(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 496);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8228D538;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
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
	ctx.lr = 0x8228D550;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228D560;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8228d5b0
	if (!cr6.gt) goto loc_8228D5B0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r28,r11,-13284
	r28.s64 = r11.s64 + -13284;
loc_8228D570:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x8228D578;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228D58C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r29,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r29.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x8228D59C;
	sub_82722678(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x82631f88
	ctx.lr = 0x8228D5A8;
	sub_82631F88(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228d570
	if (cr6.lt) goto loc_8228D570;
loc_8228D5B0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8228D5B8"))) PPC_WEAK_FUNC(sub_8228D5B8);
PPC_FUNC_IMPL(__imp__sub_8228D5B8) {
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
	// bl 0x8263b730
	ctx.lr = 0x8228D5D0;
	sub_8263B730(ctx, base);
	// lbz r11,985(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 985);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228d5f0
	if (!cr6.eq) goto loc_8228D5F0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r10,248(r9)
	PPC_STORE_U32(ctx.r9.u32 + 248, ctx.r10.u32);
loc_8228D5F0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228D604"))) PPC_WEAK_FUNC(sub_8228D604);
PPC_FUNC_IMPL(__imp__sub_8228D604) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228D608"))) PPC_WEAK_FUNC(sub_8228D608);
PPC_FUNC_IMPL(__imp__sub_8228D608) {
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
	ctx.lr = 0x8228D610;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,60(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 60);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228D630;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228d780
	if (cr6.eq) goto loc_8228D780;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r4,r11,6092
	ctx.r4.s64 = r11.s64 + 6092;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// addi r27,r10,-19728
	r27.s64 = ctx.r10.s64 + -19728;
	// addi r26,r9,-22108
	r26.s64 = ctx.r9.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8228D668;
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
	ctx.lr = 0x8228D67C;
	sub_823DEDD8(ctx, base);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,104(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 104);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228D68C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x8228d758
	if (!cr6.eq) goto loc_8228D758;
	// cmpwi cr6,r29,56
	cr6.compare<int32_t>(r29.s32, 56, xer);
	// beq cr6,0x8228d764
	if (cr6.eq) goto loc_8228D764;
	// cmpwi cr6,r29,62
	cr6.compare<int32_t>(r29.s32, 62, xer);
	// beq cr6,0x8228d758
	if (cr6.eq) goto loc_8228D758;
	// cmpwi cr6,r29,63
	cr6.compare<int32_t>(r29.s32, 63, xer);
	// beq cr6,0x8228d6c8
	if (cr6.eq) goto loc_8228D6C8;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826537d0
	ctx.lr = 0x8228D6C0;
	sub_826537D0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8228D6C8:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r3,r11,4
	ctx.r3.s64 = r11.s64 + 262144;
	// addi r3,r3,976
	ctx.r3.s64 = ctx.r3.s64 + 976;
	// bl 0x8221d6a8
	ctx.lr = 0x8228D6DC;
	sub_8221D6A8(ctx, base);
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// lwz r3,24588(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8228D6E8;
	sub_821E6800(ctx, base);
	// lbz r9,968(r30)
	ctx.r9.u64 = PPC_LOAD_U8(r30.u32 + 968);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,-10236(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// addi r4,r11,-18768
	ctx.r4.s64 = r11.s64 + -18768;
	// bne cr6,0x8228d724
	if (!cr6.eq) goto loc_8228D724;
	// bl 0x821f9fb8
	ctx.lr = 0x8228D704;
	sub_821F9FB8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228d710
	if (cr6.eq) goto loc_8228D710;
	// bl 0x82720560
	ctx.lr = 0x8228D710;
	sub_82720560(ctx, base);
loc_8228D710:
	// li r11,1
	r11.s64 = 1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,968(r30)
	PPC_STORE_U8(r30.u32 + 968, r11.u8);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8228D724:
	// bl 0x821f9fb8
	ctx.lr = 0x8228D728;
	sub_821F9FB8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228d750
	if (cr6.eq) goto loc_8228D750;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x8228D73C;
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
	ctx.lr = 0x8228D750;
	sub_827205A8(ctx, base);
loc_8228D750:
	// li r11,0
	r11.s64 = 0;
	// stb r11,968(r30)
	PPC_STORE_U8(r30.u32 + 968, r11.u8);
loc_8228D758:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8228D764:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stb r10,968(r30)
	PPC_STORE_U8(r30.u32 + 968, ctx.r10.u8);
	// lwz r9,736(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228D780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228D780:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8228D78C"))) PPC_WEAK_FUNC(sub_8228D78C);
PPC_FUNC_IMPL(__imp__sub_8228D78C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228D790"))) PPC_WEAK_FUNC(sub_8228D790);
PPC_FUNC_IMPL(__imp__sub_8228D790) {
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
	ctx.lr = 0x8228D798;
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r27,r11,-18768
	r27.s64 = r11.s64 + -18768;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8228D7B4;
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
	ctx.lr = 0x8228D7D0;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8228D7E0;
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
	ctx.lr = 0x8228D7F8;
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
	ctx.lr = 0x8228D814;
	sub_82722678(ctx, base);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// addi r4,r7,6136
	ctx.r4.s64 = ctx.r7.s64 + 6136;
	// addi r31,r6,-19728
	r31.s64 = ctx.r6.s64 + -19728;
	// addi r30,r5,-22108
	r30.s64 = ctx.r5.s64 + -22108;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8228D83C;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8228D850;
	sub_823DEDD8(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// bl 0x826209d8
	ctx.lr = 0x8228D860;
	sub_826209D8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228d904
	if (cr6.eq) goto loc_8228D904;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228D880;
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
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r9,r7
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r9,r5
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r9,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r30
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,164(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8261fc88
	ctx.lr = 0x8228D8D8;
	sub_8261FC88(ctx, base);
	// lfs f0,168(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	f0.f64 = double(temp.f32);
	// li r8,1
	ctx.r8.s64 = 1;
	// fadds f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 + f0.f64));
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,160
	ctx.r5.s64 = ctx.r1.s64 + 160;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82625ac0
	ctx.lr = 0x8228D900;
	sub_82625AC0(ctx, base);
	// b 0x8228d934
	goto loc_8228D934;
loc_8228D904:
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
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
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
	ctx.lr = 0x8228D934;
	sub_82625F50(ctx, base);
loc_8228D934:
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10236(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x8228D940;
	sub_821F9FB8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228d968
	if (cr6.eq) goto loc_8228D968;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x8228D954;
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
	ctx.lr = 0x8228D968;
	sub_827205A8(ctx, base);
loc_8228D968:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228D970"))) PPC_WEAK_FUNC(sub_8228D970);
PPC_FUNC_IMPL(__imp__sub_8228D970) {
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
	PPCVRegister v63{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x8228D978;
	// stwu r1,-704(r1)
	ea = -704 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r27,0
	r27.s64 = 0;
	// mr r31,r27
	r31.u64 = r27.u64;
	// lwz r11,972(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 972);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8228d9ac
	if (!cr6.eq) goto loc_8228D9AC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r27,248(r10)
	PPC_STORE_U32(ctx.r10.u32 + 248, r27.u32);
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d923c
	return;
loc_8228D9AC:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8228D9C0;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228d9e4
	if (cr6.eq) goto loc_8228D9E4;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228d9e4
	if (cr6.eq) goto loc_8228D9E4;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x8228D9DC;
	sub_82295E90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8228da40
	goto loc_8228DA40;
loc_8228D9E4:
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,964(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 964);
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// bl 0x82298f08
	ctx.lr = 0x8228D9F4;
	sub_82298F08(ctx, base);
	// lbz r10,624(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 624);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// stb r9,624(r1)
	PPC_STORE_U8(ctx.r1.u32 + 624, ctx.r9.u8);
	// bl 0x8226b078
	ctx.lr = 0x8228DA0C;
	sub_8226B078(ctx, base);
	// addi r4,r30,44
	ctx.r4.s64 = r30.s64 + 44;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x824ea1b0
	ctx.lr = 0x8228DA18;
	sub_824EA1B0(ctx, base);
	// ld r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r1.u32 + 116);
	// li r11,1
	r11.s64 = 1;
	// rlwinm r7,r8,0,19,19
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x1000;
	// cmpldi cr6,r7,0
	cr6.compare<uint64_t>(ctx.r7.u64, 0, xer);
	// bne cr6,0x8228da30
	if (!cr6.eq) goto loc_8228DA30;
	// mr r11,r27
	r11.u64 = r27.u64;
loc_8228DA30:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228da40
	if (cr6.eq) goto loc_8228DA40;
	// lwz r31,224(r1)
	r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
loc_8228DA40:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r31,r11
	cr6.compare<uint32_t>(r31.u32, r11.u32, xer);
	// beq cr6,0x8228db7c
	if (cr6.eq) goto loc_8228DB7C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r10,352
	ctx.r10.s64 = 352;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// lfs f0,6076(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 6076);
	f0.f64 = double(temp.f32);
	// addi r4,r7,6092
	ctx.r4.s64 = ctx.r7.s64 + 6092;
	// addi r26,r6,-19728
	r26.s64 = ctx.r6.s64 + -19728;
	// lvx128 v63,r11,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r11.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// stvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r25,r5,-22108
	r25.s64 = ctx.r5.s64 + -22108;
	// stfs f0,100(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8228DAA0;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8228DAB4;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
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
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82625f50
	ctx.lr = 0x8228DAD8;
	sub_82625F50(ctx, base);
	// lis r4,-32120
	ctx.r4.s64 = -2105016320;
	// lwz r3,-27856(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x8228DAE4;
	sub_8238EC00(ctx, base);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82389668
	ctx.lr = 0x8228DAF8;
	sub_82389668(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,44(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 44);
	// addi r30,r28,980
	r30.s64 = r28.s64 + 980;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// addi r5,r31,48
	ctx.r5.s64 = r31.s64 + 48;
	// addi r4,r31,84
	ctx.r4.s64 = r31.s64 + 84;
	// lwz r10,980(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 980);
	// lwz r9,28(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 28);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228DB30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,80(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 80);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8228db58
	if (cr6.eq) goto loc_8228DB58;
	// lwz r11,76(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 76);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,1008(r28)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r28.u32 + 1008, temp.u32);
	// stfs f13,1012(r28)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r28.u32 + 1012, temp.u32);
	// stfs f0,1016(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 1016, temp.u32);
loc_8228DB58:
	// stw r30,992(r28)
	PPC_STORE_U32(r28.u32 + 992, r30.u32);
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// stw r30,248(r11)
	PPC_STORE_U32(r11.u32 + 248, r30.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stb r8,252(r11)
	PPC_STORE_U8(r11.u32 + 252, ctx.r8.u8);
loc_8228DB7C:
	// addi r1,r1,704
	ctx.r1.s64 = ctx.r1.s64 + 704;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8228DB84"))) PPC_WEAK_FUNC(sub_8228DB84);
PPC_FUNC_IMPL(__imp__sub_8228DB84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228DB88"))) PPC_WEAK_FUNC(sub_8228DB88);
PPC_FUNC_IMPL(__imp__sub_8228DB88) {
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
	ctx.lr = 0x8228DB90;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82632f78
	ctx.lr = 0x8228DB9C;
	sub_82632F78(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8228DBB0;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228dbcc
	if (cr6.eq) goto loc_8228DBCC;
	// lbz r11,5(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228dbcc
	if (cr6.eq) goto loc_8228DBCC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8228d970
	ctx.lr = 0x8228DBCC;
	sub_8228D970(ctx, base);
loc_8228DBCC:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r3,r11,-12116
	ctx.r3.s64 = r11.s64 + -12116;
	// li r28,0
	r28.s64 = 0;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r28,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r28.u32);
	// bl 0x821c9790
	ctx.lr = 0x8228DBF0;
	sub_821C9790(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// lwz r7,496(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 496);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228DC10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,36(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8228DC28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r31,672
	r30.s64 = r31.s64 + 672;
	// mr r31,r28
	r31.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228DC38;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8228dc88
	if (!cr6.gt) goto loc_8228DC88;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r29,r11,-13284
	r29.s64 = r11.s64 + -13284;
loc_8228DC48:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x8228DC50;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228DC64;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x8228DC74;
	sub_82722678(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x82631f88
	ctx.lr = 0x8228DC80;
	sub_82631F88(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228dc48
	if (cr6.lt) goto loc_8228DC48;
loc_8228DC88:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8228DC90"))) PPC_WEAK_FUNC(sub_8228DC90);
PPC_FUNC_IMPL(__imp__sub_8228DC90) {
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
	ctx.lr = 0x8228DC98;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r31,56(r25)
	r31.u64 = PPC_LOAD_U32(r25.u32 + 56);
	// bl 0x8227d3a0
	ctx.lr = 0x8228DCAC;
	sub_8227D3A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228de5c
	if (cr6.eq) goto loc_8228DE5C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-21704
	ctx.r3.s64 = r11.s64 + -21704;
	// bl 0x821fa230
	ctx.lr = 0x8228DCC4;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228DCD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8228de5c
	if (cr6.eq) goto loc_8228DE5C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6008
	ctx.r4.s64 = r11.s64 + 6008;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8228DCF4;
	sub_825EE0E0(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r30,r10,5996
	r30.s64 = ctx.r10.s64 + 5996;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c9790
	ctx.lr = 0x8228DD08;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8228DD18;
	sub_825ED480(ctx, base);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r7,7
	ctx.r7.s64 = 7;
	// addi r8,r9,-12116
	ctx.r8.s64 = ctx.r9.s64 + -12116;
	// li r26,0
	r26.s64 = 0;
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// stw r8,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r8.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r8
	ctx.r3.u64 = ctx.r8.u64;
	// bl 0x821c9790
	ctx.lr = 0x8228DD44;
	sub_821C9790(ctx, base);
	// li r6,1
	ctx.r6.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r6,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r6.u32);
	// bl 0x825ef9f0
	ctx.lr = 0x8228DD58;
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
	ctx.lr = 0x8228DD70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x8228DD78;
	sub_825EF9F0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8228bed8
	ctx.lr = 0x8228DD84;
	sub_8228BED8(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r26
	r30.u64 = r26.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8228DD9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8228de70
	if (!cr6.gt) goto loc_8228DE70;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r27,r11,5580
	r27.s64 = r11.s64 + 5580;
loc_8228DDB4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r23,r1,80
	r23.s64 = ctx.r1.s64 + 80;
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228DDD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x82722678
	ctx.lr = 0x8228DDE0;
	sub_82722678(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x8228DDEC;
	sub_821E80F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228de34
	if (cr6.eq) goto loc_8228DE34;
	// lwz r3,-10028(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10028);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228de34
	if (cr6.eq) goto loc_8228DE34;
	// bl 0x82209150
	ctx.lr = 0x8228DE08;
	sub_82209150(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228de34
	if (!cr6.eq) goto loc_8228DE34;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x8228DE20;
	sub_822A3998(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// bl 0x82289530
	ctx.lr = 0x8228DE34;
	sub_82289530(ctx, base);
loc_8228DE34:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228DE4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228ddb4
	if (cr6.lt) goto loc_8228DDB4;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_8228DE5C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,6008
	ctx.r4.s64 = r11.s64 + 6008;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x825ee0e0
	ctx.lr = 0x8228DE70;
	sub_825EE0E0(ctx, base);
loc_8228DE70:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8228DE78"))) PPC_WEAK_FUNC(sub_8228DE78);
PPC_FUNC_IMPL(__imp__sub_8228DE78) {
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
	ctx.lr = 0x8228DE80;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8228DE90;
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
	ctx.lr = 0x8228DEA4;
	sub_82270170(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,10252(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 10252);
	// addi r31,r11,2092
	r31.s64 = r11.s64 + 2092;
	// bl 0x82388580
	ctx.lr = 0x8228DEB8;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228DEC8;
	sub_82270170(ctx, base);
	// bl 0x82274b80
	ctx.lr = 0x8228DECC;
	sub_82274B80(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268daf8
	ctx.lr = 0x8228DED4;
	sub_8268DAF8(ctx, base);
	// mr r30,r31
	r30.u64 = r31.u64;
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228df54
	if (cr6.eq) goto loc_8228DF54;
loc_8228DEE4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268db80
	ctx.lr = 0x8228DEEC;
	sub_8268DB80(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228df54
	if (cr6.eq) goto loc_8228DF54;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228DF08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228df18
	if (cr6.eq) goto loc_8228DF18;
	// lwz r31,96(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 96);
	// b 0x8228df4c
	goto loc_8228DF4C;
loc_8228DF18:
	// rlwinm r11,r30,0,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228df34
	if (cr6.eq) goto loc_8228DF34;
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8228df38
	if (!cr6.eq) goto loc_8228DF38;
loc_8228DF34:
	// li r11,0
	r11.s64 = 0;
loc_8228DF38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228df54
	if (cr6.eq) goto loc_8228DF54;
	// rlwinm r30,r30,0,0,30
	r30.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_8228DF4C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x8228dee4
	if (!cr6.eq) goto loc_8228DEE4;
loc_8228DF54:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8228DF5C"))) PPC_WEAK_FUNC(sub_8228DF5C);
PPC_FUNC_IMPL(__imp__sub_8228DF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228DF60"))) PPC_WEAK_FUNC(sub_8228DF60);
PPC_FUNC_IMPL(__imp__sub_8228DF60) {
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
	ctx.lr = 0x8228DF68;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635538
	ctx.lr = 0x8228DF74;
	sub_82635538(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// addi r4,r10,6152
	ctx.r4.s64 = ctx.r10.s64 + 6152;
	// addi r30,r9,-19728
	r30.s64 = ctx.r9.s64 + -19728;
	// addi r29,r8,-22108
	r29.s64 = ctx.r8.s64 + -22108;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x8228DFA0;
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
	ctx.lr = 0x8228DFB4;
	sub_823DEDD8(ctx, base);
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// lfs f0,7444(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stw r6,1512(r11)
	PPC_STORE_U32(r11.u32 + 1512, ctx.r6.u32);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stfs f0,1392(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 1392, temp.u32);
	// bl 0x8228cdc0
	ctx.lr = 0x8228DFDC;
	sub_8228CDC0(ctx, base);
	// lis r5,-32254
	ctx.r5.s64 = -2113798144;
	// li r4,7
	ctx.r4.s64 = 7;
	// addi r3,r5,-12116
	ctx.r3.s64 = ctx.r5.s64 + -12116;
	// li r27,0
	r27.s64 = 0;
	// stw r4,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r4.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// bl 0x821c9790
	ctx.lr = 0x8228E000;
	sub_821C9790(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r25,1
	r25.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r25,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r25.u32);
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228E020;
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
	ctx.lr = 0x8228E038;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r31,672
	r29.s64 = r31.s64 + 672;
	// mr r30,r27
	r30.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228E048;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8228e098
	if (!cr6.gt) goto loc_8228E098;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r26,r11,-13284
	r26.s64 = r11.s64 + -13284;
loc_8228E058:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x8228E060;
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
	ctx.lr = 0x8228E074;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x8228E084;
	sub_82722678(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// bl 0x82631f88
	ctx.lr = 0x8228E090;
	sub_82631F88(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228e058
	if (cr6.lt) goto loc_8228E058;
loc_8228E098:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228E0AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stb r27,985(r31)
	PPC_STORE_U8(r31.u32 + 985, r27.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8228E0BC;
	sub_82630318(ctx, base);
	// lwz r11,-10220(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -10220);
	// stb r25,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, r25.u8);
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8228E0CC"))) PPC_WEAK_FUNC(sub_8228E0CC);
PPC_FUNC_IMPL(__imp__sub_8228E0CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228E0D0"))) PPC_WEAK_FUNC(sub_8228E0D0);
PPC_FUNC_IMPL(__imp__sub_8228E0D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r17{};
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
	ctx.lr = 0x8228E0D8;
	// stwu r1,-688(r1)
	ea = -688 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r9,608(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 608);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stb r8,608(r1)
	PPC_STORE_U8(ctx.r1.u32 + 608, ctx.r8.u8);
	// bl 0x8226b078
	ctx.lr = 0x8228E100;
	sub_8226B078(ctx, base);
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8228E108;
	sub_82130528(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r24,r11,3998
	r24.s64 = r11.s64 + 3998;
	// beq cr6,0x8228e12c
	if (cr6.eq) goto loc_8228E12C;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x82633d40
	ctx.lr = 0x8228E124;
	sub_82633D40(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x8228e130
	goto loc_8228E130;
loc_8228E12C:
	// li r28,0
	r28.s64 = 0;
loc_8228E130:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228E148;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r31,944
	r30.s64 = r31.s64 + 944;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228E158;
	sub_8262E420(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r4,r29,44
	ctx.r4.s64 = r29.s64 + 44;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r28,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r28.u32);
	// bl 0x824ea1b0
	ctx.lr = 0x8228E16C;
	sub_824EA1B0(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8228E174;
	sub_82130528(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// addi r25,r11,5568
	r25.s64 = r11.s64 + 5568;
	// beq cr6,0x8228e198
	if (cr6.eq) goto loc_8228E198;
	// stw r25,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228E194;
	sub_826311F8(ctx, base);
	// b 0x8228e19c
	goto loc_8228E19C;
loc_8228E198:
	// li r28,0
	r28.s64 = 0;
loc_8228E19C:
	// ld r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 100);
	// clrldi r11,r10,63
	r11.u64 = ctx.r10.u64 & 0x1;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8228e1b4
	if (!cr6.eq) goto loc_8228E1B4;
	// li r11,0
	r11.s64 = 0;
loc_8228E1B4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228e1d8
	if (cr6.eq) goto loc_8228E1D8;
	// lwz r11,112(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8228e1d8
	if (!cr6.eq) goto loc_8228E1D8;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2168
	ctx.r4.s64 = ctx.r10.s64 + 2168;
	// b 0x8228e290
	goto loc_8228E290;
loc_8228E1D8:
	// rlwinm r11,r10,0,19,19
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// cmpldi cr6,r11,0
	cr6.compare<uint64_t>(r11.u64, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8228e1ec
	if (!cr6.eq) goto loc_8228E1EC;
	// li r11,0
	r11.s64 = 0;
loc_8228E1EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228e2a4
	if (cr6.eq) goto loc_8228E2A4;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r4,208(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x8228e288
	if (cr6.eq) goto loc_8228E288;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389668
	ctx.lr = 0x8228E228;
	sub_82389668(ctx, base);
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,4(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82389668
	ctx.lr = 0x8228E240;
	sub_82389668(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8228e258
	if (!cr6.eq) goto loc_8228E258;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6316
	ctx.r4.s64 = ctx.r10.s64 + 6316;
	// b 0x8228e290
	goto loc_8228E290;
loc_8228E258:
	// lwz r11,-3624(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -3624);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,700(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r5,4(r7)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r4,36(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// lwzx r4,r4,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r8.u32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// b 0x8228e2a0
	goto loc_8228E2A0;
loc_8228E288:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6304
	ctx.r4.s64 = ctx.r10.s64 + 6304;
loc_8228E290:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8228E2A0:
	// bctrl 
	ctx.lr = 0x8228E2A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228E2A4:
	// addi r27,r31,952
	r27.s64 = r31.s64 + 952;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228E2B4;
	sub_8262E420(ctx, base);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r9,32(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r28,r11,9072
	r28.s64 = r11.s64 + 9072;
	// lwz r8,36(r29)
	ctx.r8.u64 = PPC_LOAD_U32(r29.u32 + 36);
	// lwz r11,28(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 28);
	// addi r5,r7,6296
	ctx.r5.s64 = ctx.r7.s64 + 6296;
	// lwz r6,976(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// rlwinm r29,r6,6,0,25
	r29.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r3,r28,4096
	ctx.r3.s64 = r28.s64 + 4096;
	// li r4,64
	ctx.r4.s64 = 64;
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r6,r8,r11
	ctx.r6.u64 = ctx.r8.u64 + r11.u64;
	// add r3,r29,r3
	ctx.r3.u64 = r29.u64 + ctx.r3.u64;
	// bl 0x82137a08
	ctx.lr = 0x8228E2F8;
	sub_82137A08(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8228E300;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8228e31c
	if (cr6.eq) goto loc_8228E31C;
	// stw r25,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228E318;
	sub_826311F8(ctx, base);
	// b 0x8228e320
	goto loc_8228E320;
loc_8228E31C:
	// li r29,0
	r29.s64 = 0;
loc_8228E320:
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r28,4096
	r11.s64 = r28.s64 + 4096;
	// lwz r8,976(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r7,8(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + r11.u64;
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228E344;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r28,r31,960
	r28.s64 = r31.s64 + 960;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228E354;
	sub_8262E420(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r29,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r29.u32);
	// bl 0x82130528
	ctx.lr = 0x8228E364;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8228e380
	if (cr6.eq) goto loc_8228E380;
	// stw r25,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r25.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228E37C;
	sub_826311F8(ctx, base);
	// b 0x8228e384
	goto loc_8228E384;
loc_8228E380:
	// li r29,0
	r29.s64 = 0;
loc_8228E384:
	// lwz r11,120(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// cmplwi cr6,r11,6
	cr6.compare<uint32_t>(r11.u32, 6, xer);
	// bgt cr6,0x8228e428
	if (cr6.gt) goto loc_8228E428;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,-7256
	r12.s64 = r12.s64 + -7256;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8228E3C4;
	case 1:
		goto loc_8228E3D0;
	case 2:
		goto loc_8228E3DC;
	case 3:
		goto loc_8228E3E8;
	case 4:
		goto loc_8228E3F4;
	case 5:
		goto loc_8228E400;
	case 6:
		goto loc_8228E40C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-7228(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7228);
	// lwz r17,-7216(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7216);
	// lwz r17,-7204(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7204);
	// lwz r17,-7192(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7192);
	// lwz r17,-7180(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7180);
	// lwz r17,-7168(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7168);
	// lwz r17,-7156(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -7156);
loc_8228E3C4:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6272
	ctx.r4.s64 = ctx.r10.s64 + 6272;
	// b 0x8228e414
	goto loc_8228E414;
loc_8228E3D0:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6252
	ctx.r4.s64 = ctx.r10.s64 + 6252;
	// b 0x8228e414
	goto loc_8228E414;
loc_8228E3DC:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6232
	ctx.r4.s64 = ctx.r10.s64 + 6232;
	// b 0x8228e414
	goto loc_8228E414;
loc_8228E3E8:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6212
	ctx.r4.s64 = ctx.r10.s64 + 6212;
	// b 0x8228e414
	goto loc_8228E414;
loc_8228E3F4:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6192
	ctx.r4.s64 = ctx.r10.s64 + 6192;
	// b 0x8228e414
	goto loc_8228E414;
loc_8228E400:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6180
	ctx.r4.s64 = ctx.r10.s64 + 6180;
	// b 0x8228e414
	goto loc_8228E414;
loc_8228E40C:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,6164
	ctx.r4.s64 = ctx.r10.s64 + 6164;
loc_8228E414:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228E428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228E428:
	// addi r3,r31,968
	ctx.r3.s64 = r31.s64 + 968;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x8262e420
	ctx.lr = 0x8228E434;
	sub_8262E420(ctx, base);
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// lwz r9,976(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r11,852(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 852);
	// lis r5,-32129
	ctx.r5.s64 = -2105606144;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// lwz r8,848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 848);
	// rotlwi r7,r11,2
	ctx.r7.u64 = __builtin_rotateleft32(r11.u32, 2);
	// sth r4,852(r31)
	PPC_STORE_U16(r31.u32 + 852, ctx.r4.u16);
	// addi r11,r31,848
	r11.s64 = r31.s64 + 848;
	// lwzx r11,r9,r10
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// stwx r11,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, r11.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r8,976(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r9
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lhz r9,192(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// rotlwi r6,r9,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,188(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// stwx r3,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r3.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,976(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lhz r9,192(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// rotlwi r6,r9,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r7,188(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// stwx r3,r6,r7
	PPC_STORE_U32(ctx.r6.u32 + ctx.r7.u32, ctx.r3.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,976(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r9,r11
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// lwz r6,968(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 968);
	// lhz r10,192(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// sth r4,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r4.u16);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwzx r3,r9,r6
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r6.u32);
	// lwz r7,188(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// stwx r3,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r3.u32);
	// lwz r10,232(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 232);
	// lwz r11,-28304(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + -28304);
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// bne cr6,0x8228e63c
	if (!cr6.eq) goto loc_8228E63C;
	// lwz r10,240(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	// rlwinm r9,r11,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x2;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// bne cr6,0x8228e63c
	if (!cr6.eq) goto loc_8228E63C;
	// lwz r10,248(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 248);
	// rlwinm r9,r11,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// bne cr6,0x8228e63c
	if (!cr6.eq) goto loc_8228E63C;
	// lwz r10,256(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// rlwinm r9,r11,0,28,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x8;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// bne cr6,0x8228e63c
	if (!cr6.eq) goto loc_8228E63C;
	// lwz r10,264(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 264);
	// rlwinm r9,r11,0,27,27
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x10;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// bne cr6,0x8228e63c
	if (!cr6.eq) goto loc_8228E63C;
	// lwz r10,272(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// bne cr6,0x8228e63c
	if (!cr6.eq) goto loc_8228E63C;
	// lwz r10,280(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// rlwinm r9,r11,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// bne cr6,0x8228e63c
	if (!cr6.eq) goto loc_8228E63C;
	// lwz r10,288(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// rlwinm r9,r11,0,24,24
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x80;
	// cntlzw r8,r10
	ctx.r8.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subfic r7,r9,0
	xer.ca = ctx.r9.u32 <= 0;
	ctx.r7.s64 = 0 - ctx.r9.s64;
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// subfe r5,r7,r7
	temp.u8 = (~ctx.r7.u32 + ctx.r7.u32 < ~ctx.r7.u32) | (~ctx.r7.u32 + ctx.r7.u32 + xer.ca < xer.ca);
	ctx.r5.u64 = ~ctx.r7.u64 + ctx.r7.u64 + xer.ca;
	xer.ca = temp.u8;
	// xori r4,r6,1
	ctx.r4.u64 = ctx.r6.u64 ^ 1;
	// clrlwi r3,r5,31
	ctx.r3.u64 = ctx.r5.u32 & 0x1;
	// cmpw cr6,r3,r4
	cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, xer);
	// beq cr6,0x8228e660
	if (cr6.eq) goto loc_8228E660;
loc_8228E63C:
	// lwz r11,976(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,76(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 76);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228E660;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228E660:
	// lwz r11,976(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 976);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,976(r31)
	PPC_STORE_U32(r31.u32 + 976, r11.u32);
	// addi r1,r1,688
	ctx.r1.s64 = ctx.r1.s64 + 688;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_8228E674"))) PPC_WEAK_FUNC(sub_8228E674);
PPC_FUNC_IMPL(__imp__sub_8228E674) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228E678"))) PPC_WEAK_FUNC(sub_8228E678);
PPC_FUNC_IMPL(__imp__sub_8228E678) {
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
	// bl 0x82635538
	ctx.lr = 0x8228E694;
	sub_82635538(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stb r11,976(r31)
	PPC_STORE_U8(r31.u32 + 976, r11.u8);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// addi r4,r8,-7764
	ctx.r4.s64 = ctx.r8.s64 + -7764;
	// lwz r10,-10220(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// li r5,2
	ctx.r5.s64 = 2;
	// stb r11,372(r10)
	PPC_STORE_U8(ctx.r10.u32 + 372, r11.u8);
	// lwz r10,-10220(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r11,1427(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1427, r11.u8);
	// lwz r10,-10220(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r11,1401(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1401, r11.u8);
	// lwz r10,-10220(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r11,377(r10)
	PPC_STORE_U8(ctx.r10.u32 + 377, r11.u8);
	// bl 0x826347f0
	ctx.lr = 0x8228E6D4;
	sub_826347F0(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r4,r6,-2628
	ctx.r4.s64 = ctx.r6.s64 + -2628;
	// lwz r3,-10240(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8228E6E8;
	sub_822701C8(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r11,476(r5)
	r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + 476);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8228E704;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r9,528(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 528);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228E71C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8228e7d4
	if (cr6.eq) goto loc_8228E7D4;
	// lbz r11,5(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 5);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228e7d4
	if (cr6.eq) goto loc_8228E7D4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8228d970
	ctx.lr = 0x8228E738;
	sub_8228D970(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r11,r11,6328
	r11.s64 = r11.s64 + 6328;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8228E74C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8228e74c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8228E74C;
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,90
	ctx.r3.s64 = ctx.r1.s64 + 90;
	// bl 0x823d9890
	ctx.lr = 0x8228E770;
	sub_823D9890(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228E77C;
	sub_82295E90(ctx, base);
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-27892
	ctx.r9.s64 = r11.s64 + -27892;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_8228E790:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8228e790
	if (!cr6.eq) goto loc_8228E790;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_8228E7A4:
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
	// bne cr6,0x8228e7a4
	if (!cr6.eq) goto loc_8228E7A4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,788(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228E7D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228E7D4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82630318
	ctx.lr = 0x8228E7E0;
	sub_82630318(ctx, base);
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

__attribute__((alias("__imp__sub_8228E7F8"))) PPC_WEAK_FUNC(sub_8228E7F8);
PPC_FUNC_IMPL(__imp__sub_8228E7F8) {
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
	// bl 0x8263b730
	ctx.lr = 0x8228E810;
	sub_8263B730(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stb r11,976(r31)
	PPC_STORE_U8(r31.u32 + 976, r11.u8);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r3,r8,6124
	ctx.r3.s64 = ctx.r8.s64 + 6124;
	// lwz r10,-10236(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10236);
	// lwz r7,48(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// stw r11,248(r7)
	PPC_STORE_U32(ctx.r7.u32 + 248, r11.u32);
	// lwz r10,-10220(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r11,372(r10)
	PPC_STORE_U8(ctx.r10.u32 + 372, r11.u8);
	// lwz r10,-10220(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r11,1427(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1427, r11.u8);
	// lwz r10,-10220(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r11,1401(r10)
	PPC_STORE_U8(ctx.r10.u32 + 1401, r11.u8);
	// lwz r10,-10220(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r11,377(r10)
	PPC_STORE_U8(ctx.r10.u32 + 377, r11.u8);
	// bl 0x821fa230
	ctx.lr = 0x8228E858;
	sub_821FA230(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,112(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 112);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8228E868;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// lwz r11,-3624(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227d3a0
	ctx.lr = 0x8228E878;
	sub_8227D3A0(ctx, base);
	// clrlwi r3,r3,24
	ctx.r3.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228e88c
	if (cr6.eq) goto loc_8228E88C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8228d790
	ctx.lr = 0x8228E88C;
	sub_8228D790(ctx, base);
loc_8228E88C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,736(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 736);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228E8A0;
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

__attribute__((alias("__imp__sub_8228E8B4"))) PPC_WEAK_FUNC(sub_8228E8B4);
PPC_FUNC_IMPL(__imp__sub_8228E8B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228E8B8"))) PPC_WEAK_FUNC(sub_8228E8B8);
PPC_FUNC_IMPL(__imp__sub_8228E8B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91c4
	ctx.lr = 0x8228E8C0;
	// stwu r1,-832(r1)
	ea = -832 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r10,672(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 672);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// stb r9,672(r1)
	PPC_STORE_U8(ctx.r1.u32 + 672, ctx.r9.u8);
	// bl 0x8226b078
	ctx.lr = 0x8228E8E0;
	sub_8226B078(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r18,0
	r18.s64 = 0;
	// addi r4,r7,-2628
	ctx.r4.s64 = ctx.r7.s64 + -2628;
	// mr r28,r18
	r28.u64 = r18.u64;
	// lwz r3,-10240(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10240);
	// mr r26,r18
	r26.u64 = r18.u64;
	// mr r24,r18
	r24.u64 = r18.u64;
	// mr r22,r18
	r22.u64 = r18.u64;
	// mr r21,r18
	r21.u64 = r18.u64;
	// mr r20,r18
	r20.u64 = r18.u64;
	// mr r19,r18
	r19.u64 = r18.u64;
	// mr r16,r18
	r16.u64 = r18.u64;
	// li r23,1
	r23.s64 = 1;
	// mr r15,r18
	r15.u64 = r18.u64;
	// bl 0x822701c8
	ctx.lr = 0x8228E920;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228ea08
	if (cr6.eq) goto loc_8228EA08;
	// lbz r8,86(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// li r10,255
	ctx.r10.s64 = 255;
	// lbz r6,81(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// ori r4,r8,128
	ctx.r4.u64 = ctx.r8.u64 | 128;
	// lbz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// ori r10,r6,224
	ctx.r10.u64 = ctx.r6.u64 | 224;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// stb r18,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r18.u8);
	// clrlwi r3,r7,25
	ctx.r3.u64 = ctx.r7.u32 & 0x7F;
	// stw r18,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r18.u32);
	// ori r9,r11,64
	ctx.r9.u64 = r11.u64 | 64;
	// stw r18,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r18.u32);
	// stb r3,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r3.u8);
	// li r4,18
	ctx.r4.s64 = 18;
	// stw r18,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r18.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r10,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// stb r18,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r18.u8);
	// stb r18,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r18.u8);
	// stw r18,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r18.u32);
	// stb r9,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r9.u8);
	// bl 0x82295538
	ctx.lr = 0x8228E98C;
	sub_82295538(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228E998;
	sub_82295E90(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228E9A8;
	sub_82295E90(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r24,92(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82397470
	ctx.lr = 0x8228E9B8;
	sub_82397470(ctx, base);
	// clrlwi r22,r3,24
	r22.u64 = ctx.r3.u32 & 0xFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228E9C8;
	sub_82295E90(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82397458
	ctx.lr = 0x8228E9D4;
	sub_82397458(ctx, base);
	// clrlwi r21,r3,24
	r21.u64 = ctx.r3.u32 & 0xFF;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228E9E4;
	sub_82295E90(ctx, base);
	// lbz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// lbz r7,86(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// lbz r6,85(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 85);
	// rlwinm r20,r8,25,7,31
	r20.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 25) & 0x1FFFFFF;
	// lwz r15,88(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r19,r7,25,7,31
	r19.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 25) & 0x1FFFFFF;
	// stw r3,972(r30)
	PPC_STORE_U32(r30.u32 + 972, ctx.r3.u32);
	// extsb r16,r6
	r16.s64 = ctx.r6.s8;
	// b 0x8228eb24
	goto loc_8228EB24;
loc_8228EA08:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8228ea4c
	if (cr6.eq) goto loc_8228EA4C;
	// addi r4,r29,44
	ctx.r4.s64 = r29.s64 + 44;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x824ea1b0
	ctx.lr = 0x8228EA1C;
	sub_824EA1B0(ctx, base);
	// lwz r11,224(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// stw r11,972(r30)
	PPC_STORE_U32(r30.u32 + 972, r11.u32);
	// lwz r28,192(r1)
	r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// lwz r26,200(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 200);
	// lwz r24,208(r1)
	r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// lwz r22,216(r1)
	r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 216);
	// lwz r23,288(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// lwz r21,280(r1)
	r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 280);
	// lwz r20,372(r1)
	r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r19,380(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 380);
	// lwz r16,388(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 388);
	// lwz r15,396(r1)
	r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 396);
loc_8228EA4C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,6328
	r11.s64 = r11.s64 + 6328;
	// li r9,10
	ctx.r9.s64 = 10;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8228EA60:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stb r9,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8228ea60
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8228EA60;
	// li r5,30
	ctx.r5.s64 = 30;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,122
	ctx.r3.s64 = ctx.r1.s64 + 122;
	// bl 0x823d9890
	ctx.lr = 0x8228EA84;
	sub_823D9890(ctx, base);
	// lwz r11,176(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8228eacc
	if (!cr6.eq) goto loc_8228EACC;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,6512
	ctx.r10.s64 = ctx.r10.s64 + 6512;
loc_8228EA9C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8228ea9c
	if (!cr6.eq) goto loc_8228EA9C;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_8228EAB0:
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
	// bne cr6,0x8228eab0
	if (!cr6.eq) goto loc_8228EAB0;
	// b 0x8228eb0c
	goto loc_8228EB0C;
loc_8228EACC:
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r23,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r23.u32 | (r23.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-27892
	ctx.r9.s64 = r11.s64 + -27892;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lwzx r10,r10,r9
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
loc_8228EAE0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8228eae0
	if (!cr6.eq) goto loc_8228EAE0;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
loc_8228EAF4:
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
	// bne cr6,0x8228eaf4
	if (!cr6.eq) goto loc_8228EAF4;
loc_8228EB0C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,788(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 788);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228EB24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228EB24:
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8228EB2C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228eb4c
	if (cr6.eq) goto loc_8228EB4C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6496
	ctx.r4.s64 = r11.s64 + 6496;
	// bl 0x82633d40
	ctx.lr = 0x8228EB44;
	sub_82633D40(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8228eb50
	goto loc_8228EB50;
loc_8228EB4C:
	// mr r31,r18
	r31.u64 = r18.u64;
loc_8228EB50:
	// addi r29,r30,944
	r29.s64 = r30.s64 + 944;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228EB60;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r31,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r31.u32);
	// bl 0x82130528
	ctx.lr = 0x8228EB70;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r17,r11,5568
	r17.s64 = r11.s64 + 5568;
	// beq cr6,0x8228eba0
	if (cr6.eq) goto loc_8228EBA0;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r28,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-28076
	ctx.r9.s64 = r11.s64 + -28076;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// bl 0x826311f8
	ctx.lr = 0x8228EB9C;
	sub_826311F8(ctx, base);
	// b 0x8228eba4
	goto loc_8228EBA4;
loc_8228EBA0:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228EBA4:
	// addi r28,r30,952
	r28.s64 = r30.s64 + 952;
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228EBB4;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,208
	ctx.r3.s64 = 208;
	// addi r31,r30,848
	r31.s64 = r30.s64 + 848;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,848(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 848);
	// lhz r10,852(r30)
	ctx.r10.u64 = PPC_LOAD_U16(r30.u32 + 852);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// sth r7,852(r30)
	PPC_STORE_U16(r30.u32 + 852, ctx.r7.u16);
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,952(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 952);
	// lwz r4,960(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r9,192(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r6.u16);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r4,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r4.u32);
	// bl 0x82130528
	ctx.lr = 0x8228EC3C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ec5c
	if (cr6.eq) goto loc_8228EC5C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6484
	ctx.r4.s64 = r11.s64 + 6484;
	// bl 0x82633d40
	ctx.lr = 0x8228EC54;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8228ec60
	goto loc_8228EC60;
loc_8228EC5C:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228EC60:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228EC6C;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x82130528
	ctx.lr = 0x8228EC7C;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228eca4
	if (cr6.eq) goto loc_8228ECA4;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// rlwinm r10,r26,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r26.u32 | (r26.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r11,-28096
	ctx.r9.s64 = r11.s64 + -28096;
	// lwzx r4,r10,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// bl 0x826311f8
	ctx.lr = 0x8228ECA0;
	sub_826311F8(ctx, base);
	// b 0x8228eca8
	goto loc_8228ECA8;
loc_8228ECA4:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228ECA8:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228ECB4;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,208
	ctx.r3.s64 = 208;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,960(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + -4);
	// lwz r8,188(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 188);
	// lhz r9,192(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 192);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,192(r11)
	PPC_STORE_U16(r11.u32 + 192, ctx.r6.u16);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r4,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r4.u32);
	// bl 0x82130528
	ctx.lr = 0x8228ED38;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ed58
	if (cr6.eq) goto loc_8228ED58;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6472
	ctx.r4.s64 = r11.s64 + 6472;
	// bl 0x82633d40
	ctx.lr = 0x8228ED50;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8228ed5c
	goto loc_8228ED5C;
loc_8228ED58:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228ED5C:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228ED68;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x82130528
	ctx.lr = 0x8228ED78;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// addi r26,r11,6468
	r26.s64 = r11.s64 + 6468;
	// addi r25,r10,6464
	r25.s64 = ctx.r10.s64 + 6464;
	// beq cr6,0x8228edb4
	if (cr6.eq) goto loc_8228EDB4;
	// cmpwi cr6,r24,0
	cr6.compare<int32_t>(r24.s32, 0, xer);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bne cr6,0x8228eda4
	if (!cr6.eq) goto loc_8228EDA4;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
loc_8228EDA4:
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228EDB0;
	sub_826311F8(ctx, base);
	// b 0x8228edb8
	goto loc_8228EDB8;
loc_8228EDB4:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228EDB8:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228EDC4;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,208
	ctx.r3.s64 = 208;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r6,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r5,960(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -4);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r4,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r4.u32);
	// bl 0x82130528
	ctx.lr = 0x8228EE4C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ee6c
	if (cr6.eq) goto loc_8228EE6C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6452
	ctx.r4.s64 = r11.s64 + 6452;
	// bl 0x82633d40
	ctx.lr = 0x8228EE64;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8228ee70
	goto loc_8228EE70;
loc_8228EE6C:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228EE70:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228EE7C;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x82130528
	ctx.lr = 0x8228EE8C;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228eeb8
	if (cr6.eq) goto loc_8228EEB8;
	// cmpwi cr6,r22,0
	cr6.compare<int32_t>(r22.s32, 0, xer);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bne cr6,0x8228eea8
	if (!cr6.eq) goto loc_8228EEA8;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
loc_8228EEA8:
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228EEB4;
	sub_826311F8(ctx, base);
	// b 0x8228eebc
	goto loc_8228EEBC;
loc_8228EEB8:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228EEBC:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228EEC8;
	sub_8262E420(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r26,r11,6448
	r26.s64 = r11.s64 + 6448;
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// addi r25,r10,6444
	r25.s64 = ctx.r10.s64 + 6444;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r23,2
	cr6.compare<int32_t>(r23.s32, 2, xer);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r4,960(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r4,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r4.u32);
	// bne cr6,0x8228f05c
	if (!cr6.eq) goto loc_8228F05C;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8228EF64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228ef84
	if (cr6.eq) goto loc_8228EF84;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,2036
	ctx.r4.s64 = r11.s64 + 2036;
	// bl 0x82633d40
	ctx.lr = 0x8228EF7C;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8228ef88
	goto loc_8228EF88;
loc_8228EF84:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228EF88:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228EF94;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x82130528
	ctx.lr = 0x8228EFA4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228efd0
	if (cr6.eq) goto loc_8228EFD0;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bne cr6,0x8228efc0
	if (!cr6.eq) goto loc_8228EFC0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
loc_8228EFC0:
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228EFCC;
	sub_826311F8(ctx, base);
	// b 0x8228efd4
	goto loc_8228EFD4;
loc_8228EFD0:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228EFD4:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228EFE0;
	sub_8262E420(ctx, base);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// rotlwi r8,r10,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r5,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r5.u32);
	// lwz r4,960(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + -4);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// rotlwi r7,r9,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r4,r7,r8
	PPC_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r4.u32);
loc_8228F05C:
	// lwz r11,972(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 972);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8228f4c0
	if (!cr6.eq) goto loc_8228F4C0;
	// li r3,208
	ctx.r3.s64 = 208;
	// bl 0x82130528
	ctx.lr = 0x8228F070;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228f090
	if (cr6.eq) goto loc_8228F090;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6428
	ctx.r4.s64 = r11.s64 + 6428;
	// bl 0x82633d40
	ctx.lr = 0x8228F088;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8228f094
	goto loc_8228F094;
loc_8228F090:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228F094:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228F0A0;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x82130528
	ctx.lr = 0x8228F0B0;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228f0dc
	if (cr6.eq) goto loc_8228F0DC;
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bne cr6,0x8228f0cc
	if (!cr6.eq) goto loc_8228F0CC;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
loc_8228F0CC:
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228F0D8;
	sub_826311F8(ctx, base);
	// b 0x8228f0e0
	goto loc_8228F0E0;
loc_8228F0DC:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228F0E0:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228F0EC;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,208
	ctx.r3.s64 = 208;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,960(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r4,r11,r10
	ctx.r4.u64 = r11.u64 + ctx.r10.u64;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -4);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,-4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// bl 0x82130528
	ctx.lr = 0x8228F174;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228f194
	if (cr6.eq) goto loc_8228F194;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6412
	ctx.r4.s64 = r11.s64 + 6412;
	// bl 0x82633d40
	ctx.lr = 0x8228F18C;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8228f198
	goto loc_8228F198;
loc_8228F194:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228F198:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228F1A4;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x82130528
	ctx.lr = 0x8228F1B4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228f1e0
	if (cr6.eq) goto loc_8228F1E0;
	// cmpwi cr6,r19,0
	cr6.compare<int32_t>(r19.s32, 0, xer);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// bne cr6,0x8228f1d0
	if (!cr6.eq) goto loc_8228F1D0;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
loc_8228F1D0:
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228F1DC;
	sub_826311F8(ctx, base);
	// b 0x8228f1e4
	goto loc_8228F1E4;
loc_8228F1E0:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228F1E4:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228F1F0;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,208
	ctx.r3.s64 = 208;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r7,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r7.u16);
	// lwz r5,-4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// lwz r4,960(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r9,r11,r9
	ctx.r9.u64 = r11.u64 + ctx.r9.u64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// addi r6,r9,1
	ctx.r6.s64 = ctx.r9.s64 + 1;
	// sth r6,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r6.u16);
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r4,-4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r4,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r4.u32);
	// bl 0x82130528
	ctx.lr = 0x8228F278;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228f298
	if (cr6.eq) goto loc_8228F298;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6396
	ctx.r4.s64 = r11.s64 + 6396;
	// bl 0x82633d40
	ctx.lr = 0x8228F290;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8228f29c
	goto loc_8228F29C;
loc_8228F298:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228F29C:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228F2A8;
	sub_8262E420(ctx, base);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r25,r10,9072
	r25.s64 = ctx.r10.s64 + 9072;
	// addi r24,r11,32684
	r24.s64 = r11.s64 + 32684;
	// mr r6,r16
	ctx.r6.u64 = r16.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r25,2176
	ctx.r3.s64 = r25.s64 + 2176;
	// bl 0x82137a08
	ctx.lr = 0x8228F2D0;
	sub_82137A08(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r23,-32121
	r23.s64 = -2105081856;
	// addi r26,r11,6376
	r26.s64 = r11.s64 + 6376;
	// addi r5,r25,2176
	ctx.r5.s64 = r25.s64 + 2176;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// lwz r3,-10244(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x8228F2EC;
	sub_822183B0(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8228F2F4;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228f310
	if (cr6.eq) goto loc_8228F310;
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228F30C;
	sub_826311F8(ctx, base);
	// b 0x8228f314
	goto loc_8228F314;
loc_8228F310:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228F314:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228F320;
	sub_8262E420(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,208
	ctx.r3.s64 = 208;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwz r5,960(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -4);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r7,r9,1
	ctx.r7.s64 = ctx.r9.s64 + 1;
	// rotlwi r9,r9,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r7,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r7.u16);
	// lwz r5,-4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// bl 0x82130528
	ctx.lr = 0x8228F3A8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228f3c8
	if (cr6.eq) goto loc_8228F3C8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,6360
	ctx.r4.s64 = r11.s64 + 6360;
	// bl 0x82633d40
	ctx.lr = 0x8228F3C0;
	sub_82633D40(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// b 0x8228f3cc
	goto loc_8228F3CC;
loc_8228F3C8:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228F3CC:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228F3D8;
	sub_8262E420(ctx, base);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lis r11,0
	r11.s64 = 0;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// ori r10,r11,60000
	ctx.r10.u64 = r11.u64 | 60000;
	// li r4,64
	ctx.r4.s64 = 64;
	// divw r6,r15,r10
	ctx.r6.s32 = r15.s32 / ctx.r10.s32;
	// addi r3,r25,2240
	ctx.r3.s64 = r25.s64 + 2240;
	// bl 0x82137a08
	ctx.lr = 0x8228F3F8;
	sub_82137A08(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r5,r25,2240
	ctx.r5.s64 = r25.s64 + 2240;
	// lwz r3,-10244(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + -10244);
	// addi r26,r11,6340
	r26.s64 = r11.s64 + 6340;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x822183b0
	ctx.lr = 0x8228F410;
	sub_822183B0(ctx, base);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82130528
	ctx.lr = 0x8228F418;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x8228f434
	if (cr6.eq) goto loc_8228F434;
	// stw r17,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r17.u32);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x826311f8
	ctx.lr = 0x8228F430;
	sub_826311F8(ctx, base);
	// b 0x8228f438
	goto loc_8228F438;
loc_8228F434:
	// mr r27,r18
	r27.u64 = r18.u64;
loc_8228F438:
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8262e420
	ctx.lr = 0x8228F444;
	sub_8262E420(ctx, base);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// lwz r11,960(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,960(r30)
	PPC_STORE_U32(r30.u32 + 960, r11.u32);
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = r11.s64 + -4;
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// sth r8,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r8.u16);
	// lwz r6,-4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -4);
	// stwx r6,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r6.u32);
	// lwz r5,960(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 960);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r11,r5,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// add r4,r11,r9
	ctx.r4.u64 = r11.u64 + ctx.r9.u64;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// addi r11,r10,-4
	r11.s64 = ctx.r10.s64 + -4;
	// lwz r11,-4(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -4);
	// addi r11,r11,188
	r11.s64 = r11.s64 + 188;
	// lhz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U16(r11.u32 + 4);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// rotlwi r8,r9,2
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// sth r3,4(r11)
	PPC_STORE_U16(r11.u32 + 4, ctx.r3.u16);
	// lwz r6,-4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + -4);
	// stwx r6,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r6.u32);
loc_8228F4C0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228F4D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,832
	ctx.r1.s64 = ctx.r1.s64 + 832;
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_8228F4DC"))) PPC_WEAK_FUNC(sub_8228F4DC);
PPC_FUNC_IMPL(__imp__sub_8228F4DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228F4E0"))) PPC_WEAK_FUNC(sub_8228F4E0);
PPC_FUNC_IMPL(__imp__sub_8228F4E0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82631f88
	sub_82631F88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8228F4E4"))) PPC_WEAK_FUNC(sub_8228F4E4);
PPC_FUNC_IMPL(__imp__sub_8228F4E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228F4E8"))) PPC_WEAK_FUNC(sub_8228F4E8);
PPC_FUNC_IMPL(__imp__sub_8228F4E8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,260(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8228f4fc
	if (!cr6.eq) goto loc_8228F4FC;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8228F4FC:
	// lwz r3,256(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 256);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228F504"))) PPC_WEAK_FUNC(sub_8228F504);
PPC_FUNC_IMPL(__imp__sub_8228F504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228F508"))) PPC_WEAK_FUNC(sub_8228F508);
PPC_FUNC_IMPL(__imp__sub_8228F508) {
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
	// lwz r11,260(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 260);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8228f548
	if (cr6.eq) goto loc_8228F548;
	// lwz r10,256(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 256);
	// lwz r11,188(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 188);
	// add r30,r10,r11
	r30.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228F53C;
	sub_82631F88(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// ble cr6,0x8228f550
	if (!cr6.gt) goto loc_8228F550;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8228F548:
	// bl 0x82631f88
	ctx.lr = 0x8228F54C;
	sub_82631F88(ctx, base);
	// b 0x8228f554
	goto loc_8228F554;
loc_8228F550:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_8228F554:
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

__attribute__((alias("__imp__sub_8228F56C"))) PPC_WEAK_FUNC(sub_8228F56C);
PPC_FUNC_IMPL(__imp__sub_8228F56C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228F570"))) PPC_WEAK_FUNC(sub_8228F570);
PPC_FUNC_IMPL(__imp__sub_8228F570) {
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
	// lwz r3,192(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 192);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r31,-10244(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// lwz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228F59C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82218310
	ctx.lr = 0x8228F5A8;
	sub_82218310(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228F5BC"))) PPC_WEAK_FUNC(sub_8228F5BC);
PPC_FUNC_IMPL(__imp__sub_8228F5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228F5C0"))) PPC_WEAK_FUNC(sub_8228F5C0);
PPC_FUNC_IMPL(__imp__sub_8228F5C0) {
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
	ctx.lr = 0x8228F5C8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// bl 0x82130588
	ctx.lr = 0x8228F5D8;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r30.u32);
	// sth r30,948(r31)
	PPC_STORE_U16(r31.u32 + 948, r30.u16);
	// sth r30,950(r31)
	PPC_STORE_U16(r31.u32 + 950, r30.u16);
	// lwz r3,952(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// bl 0x82130588
	ctx.lr = 0x8228F5F0;
	sub_82130588(ctx, base);
	// stw r30,952(r31)
	PPC_STORE_U32(r31.u32 + 952, r30.u32);
	// sth r30,956(r31)
	PPC_STORE_U16(r31.u32 + 956, r30.u16);
	// sth r30,958(r31)
	PPC_STORE_U16(r31.u32 + 958, r30.u16);
	// lwz r3,960(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 960);
	// bl 0x82130588
	ctx.lr = 0x8228F604;
	sub_82130588(ctx, base);
	// stw r30,960(r31)
	PPC_STORE_U32(r31.u32 + 960, r30.u32);
	// sth r30,964(r31)
	PPC_STORE_U16(r31.u32 + 964, r30.u16);
	// sth r30,966(r31)
	PPC_STORE_U16(r31.u32 + 966, r30.u16);
	// lwz r3,968(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 968);
	// bl 0x82130588
	ctx.lr = 0x8228F618;
	sub_82130588(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r30,968(r31)
	PPC_STORE_U32(r31.u32 + 968, r30.u32);
	// sth r30,972(r31)
	PPC_STORE_U16(r31.u32 + 972, r30.u16);
	// sth r30,974(r31)
	PPC_STORE_U16(r31.u32 + 974, r30.u16);
	// sth r30,852(r31)
	PPC_STORE_U16(r31.u32 + 852, r30.u16);
	// stw r30,976(r31)
	PPC_STORE_U32(r31.u32 + 976, r30.u32);
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// lwz r11,2000(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2000);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8228f678
	if (cr6.eq) goto loc_8228F678;
loc_8228F644:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82298f08
	ctx.lr = 0x8228F64C;
	sub_82298F08(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8228f660
	if (cr6.eq) goto loc_8228F660;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8228e0d0
	ctx.lr = 0x8228F660;
	sub_8228E0D0(ctx, base);
loc_8228F660:
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// lwz r11,2000(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2000);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// bne cr6,0x8228f644
	if (!cr6.eq) goto loc_8228F644;
loc_8228F678:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8228F680"))) PPC_WEAK_FUNC(sub_8228F680);
PPC_FUNC_IMPL(__imp__sub_8228F680) {
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
	ctx.lr = 0x8228F688;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r3,944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// bl 0x82130588
	ctx.lr = 0x8228F698;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// stw r30,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r30.u32);
	// sth r30,948(r31)
	PPC_STORE_U16(r31.u32 + 948, r30.u16);
	// sth r30,950(r31)
	PPC_STORE_U16(r31.u32 + 950, r30.u16);
	// lwz r3,952(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// bl 0x82130588
	ctx.lr = 0x8228F6B0;
	sub_82130588(ctx, base);
	// stw r30,952(r31)
	PPC_STORE_U32(r31.u32 + 952, r30.u32);
	// sth r30,956(r31)
	PPC_STORE_U16(r31.u32 + 956, r30.u16);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// sth r30,958(r31)
	PPC_STORE_U16(r31.u32 + 958, r30.u16);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// sth r30,852(r31)
	PPC_STORE_U16(r31.u32 + 852, r30.u16);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// stw r30,960(r31)
	PPC_STORE_U32(r31.u32 + 960, r30.u32);
	// addi r3,r11,7192
	ctx.r3.s64 = r11.s64 + 7192;
	// addi r30,r10,-7572
	r30.s64 = ctx.r10.s64 + -7572;
	// addi r29,r9,-22108
	r29.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8228F6E0;
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
	ctx.lr = 0x8228F6F4;
	sub_823DEDD8(ctx, base);
	// addi r30,r3,672
	r30.s64 = ctx.r3.s64 + 672;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228F700;
	sub_82631F88(ctx, base);
	// lwz r11,184(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228f710
	if (cr6.lt) goto loc_8228F710;
	// addi r11,r3,-1
	r11.s64 = ctx.r3.s64 + -1;
loc_8228F710:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r3,4292(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// bl 0x82298f08
	ctx.lr = 0x8228F724;
	sub_82298F08(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x8228f74c
	if (!cr6.eq) goto loc_8228F74C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227d3a0
	ctx.lr = 0x8228F740;
	sub_8227D3A0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228f758
	if (cr6.eq) goto loc_8228F758;
loc_8228F74C:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8228e8b8
	ctx.lr = 0x8228F758;
	sub_8228E8B8(ctx, base);
loc_8228F758:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8228F760"))) PPC_WEAK_FUNC(sub_8228F760);
PPC_FUNC_IMPL(__imp__sub_8228F760) {
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
	ctx.lr = 0x8228F768;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r26,r5
	r26.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// mr r25,r7
	r25.u64 = ctx.r7.u64;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r26,r10
	cr6.compare<uint32_t>(r26.u32, ctx.r10.u32, xer);
	// bne cr6,0x8228f7f4
	if (!cr6.eq) goto loc_8228F7F4;
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmpwi cr6,r10,59
	cr6.compare<int32_t>(ctx.r10.s32, 59, xer);
	// bne cr6,0x8228f7f4
	if (!cr6.eq) goto loc_8228F7F4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bne cr6,0x8228f7bc
	if (!cr6.eq) goto loc_8228F7BC;
	// li r31,0
	r31.s64 = 0;
loc_8228F7BC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,7208
	ctx.r3.s64 = r11.s64 + 7208;
	// bl 0x821fa230
	ctx.lr = 0x8228F7C8;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r9,348(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 348);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228F7DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32126
	ctx.r8.s64 = -2105409536;
	// lwz r3,24588(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x8228F7E8;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
loc_8228F7F4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// li r10,7
	ctx.r10.s64 = 7;
	// addi r3,r11,-12116
	ctx.r3.s64 = r11.s64 + -12116;
	// li r27,0
	r27.s64 = 0;
	// stw r10,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r27,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r27.u32);
	// bl 0x821c9790
	ctx.lr = 0x8228F818;
	sub_821C9790(ctx, base);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r8,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// lwz r7,496(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 496);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228F838;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,36(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 36);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8228F850;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r29,r30,672
	r29.s64 = r30.s64 + 672;
	// mr r31,r27
	r31.u64 = r27.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228F860;
	sub_82631F88(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x8228f8b0
	if (!cr6.gt) goto loc_8228F8B0;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// addi r28,r11,-13284
	r28.s64 = r11.s64 + -13284;
loc_8228F870:
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x8228F878;
	sub_825EF9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228F88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r27,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r27.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x82722678
	ctx.lr = 0x8228F89C;
	sub_82722678(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// bl 0x82631f88
	ctx.lr = 0x8228F8A8;
	sub_82631F88(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228f870
	if (cr6.lt) goto loc_8228F870;
loc_8228F8B0:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r26,r9
	cr6.compare<uint32_t>(r26.u32, ctx.r9.u32, xer);
	// bne cr6,0x8228f8fc
	if (!cr6.eq) goto loc_8228F8FC;
	// lwz r11,0(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x8228f8fc
	if (!cr6.eq) goto loc_8228F8FC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8228f5c0
	ctx.lr = 0x8228F8DC;
	sub_8228F5C0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228F8F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
loc_8228F8FC:
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r25
	ctx.r7.u64 = r25.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82635be0
	ctx.lr = 0x8228F918;
	sub_82635BE0(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8228F920"))) PPC_WEAK_FUNC(sub_8228F920);
PPC_FUNC_IMPL(__imp__sub_8228F920) {
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
	ctx.lr = 0x8228F928;
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
	ctx.lr = 0x8228F948;
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
	ctx.lr = 0x8228F968;
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
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82634738
	ctx.lr = 0x8228F988;
	sub_82634738(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,6524
	ctx.r6.s64 = ctx.r7.s64 + 6524;
	// stw r11,928(r31)
	PPC_STORE_U32(r31.u32 + 928, r11.u32);
	// lis r4,-32215
	ctx.r4.s64 = -2111242240;
	// stw r6,672(r31)
	PPC_STORE_U32(r31.u32 + 672, ctx.r6.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,932(r31)
	PPC_STORE_U32(r31.u32 + 932, r11.u32);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r4,-26040
	ctx.r4.s64 = ctx.r4.s64 + -26040;
	// bl 0x821c2f90
	ctx.lr = 0x8228F9B4;
	sub_821C2F90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8228F9C4:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8228f9c4
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8228F9C4;
	// addi r10,r31,908
	ctx.r10.s64 = r31.s64 + 908;
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// li r9,5
	ctx.r9.s64 = 5;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_8228F9E8:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x8228f9e8
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8228F9E8;
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

__attribute__((alias("__imp__sub_8228FA3C"))) PPC_WEAK_FUNC(sub_8228FA3C);
PPC_FUNC_IMPL(__imp__sub_8228FA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228FA40"))) PPC_WEAK_FUNC(sub_8228FA40);
PPC_FUNC_IMPL(__imp__sub_8228FA40) {
	PPC_FUNC_PROLOGUE();
	// stw r4,248(r3)
	PPC_STORE_U32(ctx.r3.u32 + 248, ctx.r4.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FA48"))) PPC_WEAK_FUNC(sub_8228FA48);
PPC_FUNC_IMPL(__imp__sub_8228FA48) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,248(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 248);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FA50"))) PPC_WEAK_FUNC(sub_8228FA50);
PPC_FUNC_IMPL(__imp__sub_8228FA50) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,200(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FA58"))) PPC_WEAK_FUNC(sub_8228FA58);
PPC_FUNC_IMPL(__imp__sub_8228FA58) {
	PPC_FUNC_PROLOGUE();
	// stb r4,244(r3)
	PPC_STORE_U8(ctx.r3.u32 + 244, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FA60"))) PPC_WEAK_FUNC(sub_8228FA60);
PPC_FUNC_IMPL(__imp__sub_8228FA60) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,244(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 244);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FA68"))) PPC_WEAK_FUNC(sub_8228FA68);
PPC_FUNC_IMPL(__imp__sub_8228FA68) {
	PPC_FUNC_PROLOGUE();
	// stb r4,245(r3)
	PPC_STORE_U8(ctx.r3.u32 + 245, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FA70"))) PPC_WEAK_FUNC(sub_8228FA70);
PPC_FUNC_IMPL(__imp__sub_8228FA70) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,245(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 245);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FA78"))) PPC_WEAK_FUNC(sub_8228FA78);
PPC_FUNC_IMPL(__imp__sub_8228FA78) {
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
	ctx.lr = 0x8228FA80;
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
	ctx.lr = 0x8228FAA0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228fab8
	if (cr6.eq) goto loc_8228FAB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8228FAB8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228FAD4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8228FADC"))) PPC_WEAK_FUNC(sub_8228FADC);
PPC_FUNC_IMPL(__imp__sub_8228FADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228FAE0"))) PPC_WEAK_FUNC(sub_8228FAE0);
PPC_FUNC_IMPL(__imp__sub_8228FAE0) {
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
	ctx.lr = 0x8228FAE8;
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
	ctx.lr = 0x8228FB08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228fb20
	if (cr6.eq) goto loc_8228FB20;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8228FB20:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228FB3C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8228FB44"))) PPC_WEAK_FUNC(sub_8228FB44);
PPC_FUNC_IMPL(__imp__sub_8228FB44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228FB48"))) PPC_WEAK_FUNC(sub_8228FB48);
PPC_FUNC_IMPL(__imp__sub_8228FB48) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,724(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 724);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8228FB58"))) PPC_WEAK_FUNC(sub_8228FB58);
PPC_FUNC_IMPL(__imp__sub_8228FB58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,720(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 720);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8228FB68"))) PPC_WEAK_FUNC(sub_8228FB68);
PPC_FUNC_IMPL(__imp__sub_8228FB68) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,716(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 716);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8228FB78"))) PPC_WEAK_FUNC(sub_8228FB78);
PPC_FUNC_IMPL(__imp__sub_8228FB78) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,712(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 712);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8228FB88"))) PPC_WEAK_FUNC(sub_8228FB88);
PPC_FUNC_IMPL(__imp__sub_8228FB88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,708(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 708);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8228FB98"))) PPC_WEAK_FUNC(sub_8228FB98);
PPC_FUNC_IMPL(__imp__sub_8228FB98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,8036
	ctx.r3.s64 = r11.s64 + 8036;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FBA4"))) PPC_WEAK_FUNC(sub_8228FBA4);
PPC_FUNC_IMPL(__imp__sub_8228FBA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228FBA8"))) PPC_WEAK_FUNC(sub_8228FBA8);
PPC_FUNC_IMPL(__imp__sub_8228FBA8) {
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
	// lwz r10,748(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 748);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228FBCC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r3,208(r31)
	PPC_STORE_U32(r31.u32 + 208, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FBE4"))) PPC_WEAK_FUNC(sub_8228FBE4);
PPC_FUNC_IMPL(__imp__sub_8228FBE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228FBE8"))) PPC_WEAK_FUNC(sub_8228FBE8);
PPC_FUNC_IMPL(__imp__sub_8228FBE8) {
	PPC_FUNC_PROLOGUE();
	// stb r4,480(r3)
	PPC_STORE_U8(ctx.r3.u32 + 480, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FBF0"))) PPC_WEAK_FUNC(sub_8228FBF0);
PPC_FUNC_IMPL(__imp__sub_8228FBF0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,480(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 480);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FBF8"))) PPC_WEAK_FUNC(sub_8228FBF8);
PPC_FUNC_IMPL(__imp__sub_8228FBF8) {
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
	// addi r31,r3,672
	r31.s64 = ctx.r3.s64 + 672;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228FC18;
	sub_82631F88(ctx, base);
	// lwz r11,184(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 184);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// mr r30,r11
	r30.u64 = r11.u64;
	// blt cr6,0x8228fc2c
	if (cr6.lt) goto loc_8228FC2C;
	// addi r30,r3,-1
	r30.s64 = ctx.r3.s64 + -1;
loc_8228FC2C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228FC34;
	sub_82631F88(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x8228fc68
	if (cr6.lt) goto loc_8228FC68;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82631f88
	ctx.lr = 0x8228FC44;
	sub_82631F88(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,-1
	ctx.r4.s64 = -1;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// beq cr6,0x8228fc60
	if (cr6.eq) goto loc_8228FC60;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228FC60:
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228FC68;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228FC68:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,648(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 648);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228FC80;
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

__attribute__((alias("__imp__sub_8228FC98"))) PPC_WEAK_FUNC(sub_8228FC98);
PPC_FUNC_IMPL(__imp__sub_8228FC98) {
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// addi r4,r10,8860
	ctx.r4.s64 = ctx.r10.s64 + 8860;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// li r6,50
	ctx.r6.s64 = 50;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8228FCD0;
	sub_8228F920(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r11,0
	r11.s64 = 0;
	// addi r8,r9,8060
	ctx.r8.s64 = ctx.r9.s64 + 8060;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// stw r11,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r11.u32);
	// addi r10,r7,18928
	ctx.r10.s64 = ctx.r7.s64 + 18928;
	// sth r11,948(r31)
	PPC_STORE_U16(r31.u32 + 948, r11.u16);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// sth r11,950(r31)
	PPC_STORE_U16(r31.u32 + 950, r11.u16);
	// addi r4,r6,-7780
	ctx.r4.s64 = ctx.r6.s64 + -7780;
	// stw r11,952(r31)
	PPC_STORE_U32(r31.u32 + 952, r11.u32);
	// li r5,4
	ctx.r5.s64 = 4;
	// sth r11,956(r31)
	PPC_STORE_U16(r31.u32 + 956, r11.u16);
	// sth r11,958(r31)
	PPC_STORE_U16(r31.u32 + 958, r11.u16);
	// stw r11,960(r31)
	PPC_STORE_U32(r31.u32 + 960, r11.u32);
	// sth r11,964(r31)
	PPC_STORE_U16(r31.u32 + 964, r11.u16);
	// sth r11,966(r31)
	PPC_STORE_U16(r31.u32 + 966, r11.u16);
	// stw r11,968(r31)
	PPC_STORE_U32(r31.u32 + 968, r11.u32);
	// sth r11,972(r31)
	PPC_STORE_U16(r31.u32 + 972, r11.u16);
	// sth r11,974(r31)
	PPC_STORE_U16(r31.u32 + 974, r11.u16);
	// stb r11,984(r31)
	PPC_STORE_U8(r31.u32 + 984, r11.u8);
	// stb r11,985(r31)
	PPC_STORE_U8(r31.u32 + 985, r11.u8);
	// stw r10,988(r31)
	PPC_STORE_U32(r31.u32 + 988, ctx.r10.u32);
	// stw r11,992(r31)
	PPC_STORE_U32(r31.u32 + 992, r11.u32);
	// stw r11,980(r31)
	PPC_STORE_U32(r31.u32 + 980, r11.u32);
	// stw r11,976(r31)
	PPC_STORE_U32(r31.u32 + 976, r11.u32);
	// bl 0x826347f0
	ctx.lr = 0x8228FD44;
	sub_826347F0(ctx, base);
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

__attribute__((alias("__imp__sub_8228FD5C"))) PPC_WEAK_FUNC(sub_8228FD5C);
PPC_FUNC_IMPL(__imp__sub_8228FD5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228FD60"))) PPC_WEAK_FUNC(sub_8228FD60);
PPC_FUNC_IMPL(__imp__sub_8228FD60) {
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
	// addi r3,r31,988
	ctx.r3.s64 = r31.s64 + 988;
	// addi r10,r11,15048
	ctx.r10.s64 = r11.s64 + 15048;
	// stw r10,988(r31)
	PPC_STORE_U32(r31.u32 + 988, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8228FD88;
	sub_821D2028(ctx, base);
	// lhz r9,974(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 974);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228fd9c
	if (cr6.eq) goto loc_8228FD9C;
	// lwz r3,968(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 968);
	// bl 0x82130588
	ctx.lr = 0x8228FD9C;
	sub_82130588(ctx, base);
loc_8228FD9C:
	// lhz r11,966(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 966);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228fdb0
	if (cr6.eq) goto loc_8228FDB0;
	// lwz r3,960(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 960);
	// bl 0x82130588
	ctx.lr = 0x8228FDB0;
	sub_82130588(ctx, base);
loc_8228FDB0:
	// lhz r11,958(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 958);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228fdc4
	if (cr6.eq) goto loc_8228FDC4;
	// lwz r3,952(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// bl 0x82130588
	ctx.lr = 0x8228FDC4;
	sub_82130588(ctx, base);
loc_8228FDC4:
	// lhz r11,950(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 950);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228fdd8
	if (cr6.eq) goto loc_8228FDD8;
	// lwz r3,944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// bl 0x82130588
	ctx.lr = 0x8228FDD8;
	sub_82130588(ctx, base);
loc_8228FDD8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8228FDE0;
	sub_8221FCC8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8228FDF4"))) PPC_WEAK_FUNC(sub_8228FDF4);
PPC_FUNC_IMPL(__imp__sub_8228FDF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228FDF8"))) PPC_WEAK_FUNC(sub_8228FDF8);
PPC_FUNC_IMPL(__imp__sub_8228FDF8) {
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
	// bl 0x8228fd60
	ctx.lr = 0x8228FE18;
	sub_8228FD60(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228fe30
	if (cr6.eq) goto loc_8228FE30;
	// bl 0x82130588
	ctx.lr = 0x8228FE2C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8228FE30:
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

__attribute__((alias("__imp__sub_8228FE48"))) PPC_WEAK_FUNC(sub_8228FE48);
PPC_FUNC_IMPL(__imp__sub_8228FE48) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r11,3998
	ctx.r5.s64 = r11.s64 + 3998;
	// addi r4,r10,9684
	ctx.r4.s64 = ctx.r10.s64 + 9684;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,2
	ctx.r7.s64 = 2;
	// li r6,10
	ctx.r6.s64 = 10;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x8228f920
	ctx.lr = 0x8228FE84;
	sub_8228F920(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r7,r9,8884
	ctx.r7.s64 = ctx.r9.s64 + 8884;
	// li r30,0
	r30.s64 = 0;
	// stw r7,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r7.u32);
	// addi r6,r8,18928
	ctx.r6.s64 = ctx.r8.s64 + 18928;
	// stw r30,944(r31)
	PPC_STORE_U32(r31.u32 + 944, r30.u32);
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// sth r30,948(r31)
	PPC_STORE_U16(r31.u32 + 948, r30.u16);
	// addi r3,r31,672
	ctx.r3.s64 = r31.s64 + 672;
	// sth r30,950(r31)
	PPC_STORE_U16(r31.u32 + 950, r30.u16);
	// addi r4,r5,-7764
	ctx.r4.s64 = ctx.r5.s64 + -7764;
	// stw r30,952(r31)
	PPC_STORE_U32(r31.u32 + 952, r30.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// sth r30,956(r31)
	PPC_STORE_U16(r31.u32 + 956, r30.u16);
	// sth r30,958(r31)
	PPC_STORE_U16(r31.u32 + 958, r30.u16);
	// stw r6,980(r31)
	PPC_STORE_U32(r31.u32 + 980, ctx.r6.u32);
	// stw r30,984(r31)
	PPC_STORE_U32(r31.u32 + 984, r30.u32);
	// stw r30,964(r31)
	PPC_STORE_U32(r31.u32 + 964, r30.u32);
	// stw r30,960(r31)
	PPC_STORE_U32(r31.u32 + 960, r30.u32);
	// bl 0x826347f0
	ctx.lr = 0x8228FED8;
	sub_826347F0(ctx, base);
	// stb r30,968(r31)
	PPC_STORE_U8(r31.u32 + 968, r30.u8);
	// stb r30,976(r31)
	PPC_STORE_U8(r31.u32 + 976, r30.u8);
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

__attribute__((alias("__imp__sub_8228FEFC"))) PPC_WEAK_FUNC(sub_8228FEFC);
PPC_FUNC_IMPL(__imp__sub_8228FEFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8228FF00"))) PPC_WEAK_FUNC(sub_8228FF00);
PPC_FUNC_IMPL(__imp__sub_8228FF00) {
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
	// addi r3,r31,980
	ctx.r3.s64 = r31.s64 + 980;
	// addi r10,r11,15048
	ctx.r10.s64 = r11.s64 + 15048;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// stw r10,980(r31)
	PPC_STORE_U32(r31.u32 + 980, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x8228FF30;
	sub_821D2028(ctx, base);
	// lhz r9,958(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 958);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228ff44
	if (cr6.eq) goto loc_8228FF44;
	// lwz r3,952(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 952);
	// bl 0x82130588
	ctx.lr = 0x8228FF44;
	sub_82130588(ctx, base);
loc_8228FF44:
	// lhz r11,950(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 950);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ff58
	if (cr6.eq) goto loc_8228FF58;
	// lwz r3,944(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 944);
	// bl 0x82130588
	ctx.lr = 0x8228FF58;
	sub_82130588(ctx, base);
loc_8228FF58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8221fcc8
	ctx.lr = 0x8228FF60;
	sub_8221FCC8(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228ff78
	if (cr6.eq) goto loc_8228FF78;
	// bl 0x82130588
	ctx.lr = 0x8228FF74;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8228FF78:
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

__attribute__((alias("__imp__sub_8228FF90"))) PPC_WEAK_FUNC(sub_8228FF90);
PPC_FUNC_IMPL(__imp__sub_8228FF90) {
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
	ctx.lr = 0x8228FF98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r31,r7
	r31.u64 = ctx.r7.u64;
	// mr r27,r8
	r27.u64 = ctx.r8.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228FFC0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228fff4
	if (cr6.eq) goto loc_8228FFF4;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// lbz r11,8(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 8);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8228ffec
	if (cr6.eq) goto loc_8228FFEC;
	// cmplwi cr6,r11,4
	cr6.compare<uint32_t>(r11.u32, 4, xer);
	// bne cr6,0x8228fff4
	if (!cr6.eq) goto loc_8228FFF4;
loc_8228FFEC:
	// li r11,1
	r11.s64 = 1;
	// b 0x8228fff8
	goto loc_8228FFF8;
loc_8228FFF4:
	// li r11,0
	r11.s64 = 0;
loc_8228FFF8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82290034
	if (cr6.eq) goto loc_82290034;
	// rlwinm r11,r31,1,0,30
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// add r10,r11,r3
	ctx.r10.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x8226f2a0
	ctx.lr = 0x8229002C;
	sub_8226F2A0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_82290034:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82290040"))) PPC_WEAK_FUNC(sub_82290040);
PPC_FUNC_IMPL(__imp__sub_82290040) {
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
	ctx.lr = 0x82290048;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822900f8
	if (cr6.eq) goto loc_822900F8;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822900f8
	if (cr6.eq) goto loc_822900F8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290070;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82290080;
	sub_82270170(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r4,r11,16
	ctx.r4.s64 = r11.s64 + 16;
	// bl 0x824e7130
	ctx.lr = 0x82290090;
	sub_824E7130(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822900f8
	if (cr6.eq) goto loc_822900F8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x822900A4;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822900f8
	if (cr6.eq) goto loc_822900F8;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481590
	ctx.lr = 0x822900B8;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822900f8
	if (!cr6.eq) goto loc_822900F8;
	// li r10,3
	ctx.r10.s64 = 3;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8228ff90
	ctx.lr = 0x822900EC;
	sub_8228FF90(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_822900F8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82290104"))) PPC_WEAK_FUNC(sub_82290104);
PPC_FUNC_IMPL(__imp__sub_82290104) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82290108"))) PPC_WEAK_FUNC(sub_82290108);
PPC_FUNC_IMPL(__imp__sub_82290108) {
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
	ctx.lr = 0x82290110;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822901cc
	if (cr6.eq) goto loc_822901CC;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822901cc
	if (cr6.eq) goto loc_822901CC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290138;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82290148;
	sub_82270170(ctx, base);
	// addi r4,r3,16
	ctx.r4.s64 = ctx.r3.s64 + 16;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x824e7130
	ctx.lr = 0x82290154;
	sub_824E7130(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822901cc
	if (cr6.eq) goto loc_822901CC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x82290168;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822901cc
	if (cr6.eq) goto loc_822901CC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481590
	ctx.lr = 0x8229017C;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822901cc
	if (!cr6.eq) goto loc_822901CC;
	// li r10,4
	ctx.r10.s64 = 4;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8228ff90
	ctx.lr = 0x822901B0;
	sub_8228FF90(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r3,r11,13928
	ctx.r3.s64 = r11.s64 + 13928;
	// bl 0x822976f8
	ctx.lr = 0x822901C0;
	sub_822976F8(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
loc_822901CC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822901D8"))) PPC_WEAK_FUNC(sub_822901D8);
PPC_FUNC_IMPL(__imp__sub_822901D8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x822901E0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// lwz r28,-3624(r26)
	r28.u64 = PPC_LOAD_U32(r26.u32 + -3624);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,49
	cr6.compare<uint32_t>(r11.u32, 49, xer);
	// lwz r27,700(r28)
	r27.u64 = PPC_LOAD_U32(r28.u32 + 700);
	// bgt cr6,0x822912bc
	if (cr6.gt) goto loc_822912BC;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,548
	r12.s64 = r12.s64 + 548;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82290378;
	case 1:
		goto loc_82290B40;
	case 2:
		goto loc_82290B14;
	case 3:
		goto loc_82290B54;
	case 4:
		goto loc_82290BEC;
	case 5:
		goto loc_82290BEC;
	case 6:
		goto loc_82290558;
	case 7:
		goto loc_82290D34;
	case 8:
		goto loc_82290834;
	case 9:
		goto loc_82290670;
	case 10:
		goto loc_822906B8;
	case 11:
		goto loc_822912BC;
	case 12:
		goto loc_82290740;
	case 13:
		goto loc_82290634;
	case 14:
		goto loc_8229043C;
	case 15:
		goto loc_822907A8;
	case 16:
		goto loc_822907D4;
	case 17:
		goto loc_82290320;
	case 18:
		goto loc_82290E28;
	case 19:
		goto loc_822909C8;
	case 20:
		goto loc_822909D4;
	case 21:
		goto loc_82290924;
	case 22:
		goto loc_8229095C;
	case 23:
		goto loc_82290334;
	case 24:
		goto loc_82290AD4;
	case 25:
		goto loc_82290348;
	case 26:
		goto loc_822905FC;
	case 27:
		goto loc_8229112C;
	case 28:
		goto loc_822902EC;
	case 29:
		goto loc_82290450;
	case 30:
		goto loc_82290774;
	case 31:
		goto loc_82290F44;
	case 32:
		goto loc_82290F44;
	case 33:
		goto loc_82290F44;
	case 34:
		goto loc_82290F44;
	case 35:
		goto loc_82290F44;
	case 36:
		goto loc_82290F44;
	case 37:
		goto loc_8229038C;
	case 38:
		goto loc_822903A0;
	case 39:
		goto loc_82290464;
	case 40:
		goto loc_822904BC;
	case 41:
		goto loc_822904F0;
	case 42:
		goto loc_82290524;
	case 43:
		goto loc_82290A54;
	case 44:
		goto loc_822903D4;
	case 45:
		goto loc_82290708;
	case 46:
		goto loc_82290EF8;
	case 47:
		goto loc_82290408;
	case 48:
		goto loc_8229084C;
	case 49:
		goto loc_82290880;
	default:
		__builtin_unreachable();
	}
	// lwz r17,888(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 888);
	// lwz r17,2880(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2880);
	// lwz r17,2836(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2836);
	// lwz r17,2900(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2900);
	// lwz r17,3052(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3052);
	// lwz r17,3052(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3052);
	// lwz r17,1368(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1368);
	// lwz r17,3380(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3380);
	// lwz r17,2100(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2100);
	// lwz r17,1648(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1648);
	// lwz r17,1720(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1720);
	// lwz r17,4796(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4796);
	// lwz r17,1856(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1856);
	// lwz r17,1588(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1588);
	// lwz r17,1084(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1084);
	// lwz r17,1960(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1960);
	// lwz r17,2004(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2004);
	// lwz r17,800(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 800);
	// lwz r17,3624(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3624);
	// lwz r17,2504(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2504);
	// lwz r17,2516(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2516);
	// lwz r17,2340(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2340);
	// lwz r17,2396(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2396);
	// lwz r17,820(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 820);
	// lwz r17,2772(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2772);
	// lwz r17,840(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 840);
	// lwz r17,1532(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1532);
	// lwz r17,4396(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4396);
	// lwz r17,748(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 748);
	// lwz r17,1104(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1104);
	// lwz r17,1908(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1908);
	// lwz r17,3908(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3908);
	// lwz r17,3908(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3908);
	// lwz r17,3908(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3908);
	// lwz r17,3908(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3908);
	// lwz r17,3908(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3908);
	// lwz r17,3908(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3908);
	// lwz r17,908(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 908);
	// lwz r17,928(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 928);
	// lwz r17,1124(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1124);
	// lwz r17,1212(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1212);
	// lwz r17,1264(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1264);
	// lwz r17,1316(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1316);
	// lwz r17,2644(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2644);
	// lwz r17,980(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 980);
	// lwz r17,1800(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1800);
	// lwz r17,3832(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3832);
	// lwz r17,1032(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 1032);
	// lwz r17,2124(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2124);
	// lwz r17,2176(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 2176);
loc_822902EC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822902F8;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228a7b0
	ctx.lr = 0x82290314;
	sub_8228A7B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290320:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82282788
	ctx.lr = 0x82290328;
	sub_82282788(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290334:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226bcf0
	ctx.lr = 0x8229033C;
	sub_8226BCF0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290348:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290350;
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
	ctx.lr = 0x82290364;
	sub_82270170(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82272d50
	ctx.lr = 0x8229036C;
	sub_82272D50(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290378:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82130000
	ctx.lr = 0x82290380;
	sub_82130000(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8229038C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226b930
	ctx.lr = 0x82290394;
	sub_8226B930(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822903A0:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822903AC;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82289490
	ctx.lr = 0x822903C8;
	sub_82289490(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822903D4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822903E0;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228a710
	ctx.lr = 0x822903FC;
	sub_8228A710(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290408:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290414;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228afc0
	ctx.lr = 0x82290430;
	sub_8228AFC0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8229043C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82289f20
	ctx.lr = 0x82290444;
	sub_82289F20(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290450:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8228af60
	ctx.lr = 0x82290458;
	sub_8228AF60(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290464:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290470;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r8,r10
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8268c9f0
	ctx.lr = 0x82290490;
	sub_8268C9F0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r6,76(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r6
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	// bl 0x8228b1a8
	ctx.lr = 0x822904B0;
	sub_8228B1A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822904BC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822904C8;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228de78
	ctx.lr = 0x822904E4;
	sub_8228DE78(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822904F0:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822904FC;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228b4a0
	ctx.lr = 0x82290518;
	sub_8228B4A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290524:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290530;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228b5f8
	ctx.lr = 0x8229054C;
	sub_8228B5F8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290558:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290564;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,336(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 336);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82290584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x822912bc
	if (cr6.lt) goto loc_822912BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290598;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r8,r10
	r31.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x82388580
	ctx.lr = 0x822905B4;
	sub_82388580(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,4(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r31,-10240(r5)
	r31.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10240);
	// lwz r4,336(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 336);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x822905D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82270170
	ctx.lr = 0x822905E8;
	sub_82270170(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82273978
	ctx.lr = 0x822905F0;
	sub_82273978(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822905FC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290608;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// beq cr6,0x82290620
	if (cr6.eq) goto loc_82290620;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x8229061C;
	sub_8268C9F0(ctx, base);
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
loc_82290620:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82289ab0
	ctx.lr = 0x82290628;
	sub_82289AB0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290634:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290640;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8268c9f0
	ctx.lr = 0x82290654;
	sub_8268C9F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82289e10
	ctx.lr = 0x82290664;
	sub_82289E10(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290670:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x8229067C;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r5,r7,-22108
	ctx.r5.s64 = ctx.r7.s64 + -22108;
	// addi r6,r9,-7572
	ctx.r6.s64 = ctx.r9.s64 + -7572;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x823dedd8
	ctx.lr = 0x822906A8;
	sub_823DEDD8(ctx, base);
	// bl 0x8228f5c0
	ctx.lr = 0x822906AC;
	sub_8228F5C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822906B8:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822906C4;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lis r7,-32130
	ctx.r7.s64 = -2105671680;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r5,r7,-22108
	ctx.r5.s64 = ctx.r7.s64 + -22108;
	// addi r6,r9,-11404
	ctx.r6.s64 = ctx.r9.s64 + -11404;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r8,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x823dedd8
	ctx.lr = 0x822906F0;
	sub_823DEDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8228f680
	ctx.lr = 0x822906FC;
	sub_8228F680(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290708:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290714;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r9,-32129
	ctx.r9.s64 = -2105606144;
	// addi r3,r9,-28304
	ctx.r3.s64 = ctx.r9.s64 + -28304;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,4304(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// bl 0x82388178
	ctx.lr = 0x82290734;
	sub_82388178(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290740:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x8229074C;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228a440
	ctx.lr = 0x82290768;
	sub_8228A440(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290774:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290780;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228a1a0
	ctx.lr = 0x8229079C;
	sub_8228A1A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822907A8:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822907B4;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r5,-1
	ctx.r5.s64 = -1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82283660
	ctx.lr = 0x822907C8;
	sub_82283660(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822907D4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822907E0;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,328(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 328);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82290800;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r5,332(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 332);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82290810;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x82290818;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82282580
	ctx.lr = 0x82290828;
	sub_82282580(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290834:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227d3e8
	ctx.lr = 0x82290840;
	sub_8227D3E8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8229084C:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290858;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x8228b018
	ctx.lr = 0x82290874;
	sub_8228B018(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290880:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-13208
	ctx.r3.s64 = r11.s64 + -13208;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r30,r11,4
	r30.s64 = r11.s64 + 4;
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x821fa230
	ctx.lr = 0x822908A0;
	sub_821FA230(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,32(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 32);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822908B4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r9,1
	ctx.r9.s64 = 65536;
	// li r4,71
	ctx.r4.s64 = 71;
	// ori r30,r9,16256
	r30.u64 = ctx.r9.u64 | 16256;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x822908D0;
	sub_82641CB0(ctx, base);
	// addi r11,r3,656
	r11.s64 = ctx.r3.s64 + 656;
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r6,176(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// stw r7,176(r11)
	PPC_STORE_U32(r11.u32 + 176, ctx.r7.u32);
	// cmpwi cr6,r6,1
	cr6.compare<int32_t>(ctx.r6.s32, 1, xer);
	// beq cr6,0x822908f4
	if (cr6.eq) goto loc_822908F4;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,188
	ctx.r3.s64 = r11.s64 + 188;
	// bl 0x821c3048
	ctx.lr = 0x822908F4;
	sub_821C3048(ctx, base);
loc_822908F4:
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,71
	ctx.r4.s64 = 71;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82290908;
	sub_82641CB0(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,184(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 184);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82290918;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290924:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822801f0
	ctx.lr = 0x8229092C;
	sub_822801F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
loc_82290938:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290944;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8229095C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82280280
	ctx.lr = 0x82290964;
	sub_82280280(ctx, base);
loc_82290964:
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82290994
	if (cr6.eq) goto loc_82290994;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8268c9f0
	ctx.lr = 0x8229097C;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290994:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x8268c9f0
	ctx.lr = 0x8229099C;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822909B0;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822909C8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226be68
	ctx.lr = 0x822909D0;
	sub_8226BE68(ctx, base);
	// b 0x82290964
	goto loc_82290964;
loc_822909D4:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226be68
	ctx.lr = 0x822909DC;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82290a1c
	if (cr6.eq) goto loc_82290A1C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822909F0;
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
	ctx.lr = 0x82290A04;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82290A0C;
	sub_82272A30(ctx, base);
	// bl 0x824815a0
	ctx.lr = 0x82290A10;
	sub_824815A0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82290938
	if (cr6.eq) goto loc_82290938;
loc_82290A1C:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290A28;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290A3C;
	sub_8268C9F0(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,76(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290A54:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290A5C;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82290A6C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x82290A74;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290A88;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82290A98;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70f0
	ctx.lr = 0x82290AA0;
	sub_824E70F0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290AB8;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8227ea18
	ctx.lr = 0x82290AC8;
	sub_8227EA18(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290AD4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290AE0;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r31,-10244(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x8228a5f8
	ctx.lr = 0x82290AF8;
	sub_8228A5F8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822183b0
	ctx.lr = 0x82290B08;
	sub_822183B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290B14:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r10,4292(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// lwz r3,4304(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// addi r4,r10,12
	ctx.r4.s64 = ctx.r10.s64 + 12;
	// bl 0x82295050
	ctx.lr = 0x82290B2C;
	sub_82295050(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226c038
	ctx.lr = 0x82290B34;
	sub_8226C038(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290B40:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226bad0
	ctx.lr = 0x82290B48;
	sub_8226BAD0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290B54:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290B60;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290B74;
	sub_8268C9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82290bc4
	if (cr6.eq) goto loc_82290BC4;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822912bc
	if (!cr6.eq) goto loc_822912BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290B94;
	sub_8268C9F0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268c970
	ctx.lr = 0x82290B9C;
	sub_8268C970(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82290BAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8226bf80
	ctx.lr = 0x82290BB8;
	sub_8226BF80(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290BC4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290BD0;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8226bf80
	ctx.lr = 0x82290BE0;
	sub_8226BF80(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290BEC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r27,r10,-28304
	r27.s64 = ctx.r10.s64 + -28304;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// addi r28,r28,48
	r28.s64 = r28.s64 + 48;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r30,4304(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// stb r9,28(r29)
	PPC_STORE_U8(r29.u32 + 28, ctx.r9.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82388178
	ctx.lr = 0x82290C1C;
	sub_82388178(ctx, base);
	// lhz r8,2(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// cmplwi cr6,r8,4
	cr6.compare<uint32_t>(ctx.r8.u32, 4, xer);
	// bne cr6,0x82290c4c
	if (!cr6.eq) goto loc_82290C4C;
	// lwz r11,-3624(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -3624);
	// lwz r11,108(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82290c4c
	if (cr6.eq) goto loc_82290C4C;
	// addi r31,r28,92
	r31.s64 = r28.s64 + 92;
	// bl 0x82387b90
	ctx.lr = 0x82290C40;
	sub_82387B90(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x82290C48;
	sub_8238B7E0(ctx, base);
	// b 0x82290c58
	goto loc_82290C58;
loc_82290C4C:
	// bl 0x82387b90
	ctx.lr = 0x82290C50;
	sub_82387B90(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8238b9d8
	ctx.lr = 0x82290C58;
	sub_8238B9D8(ctx, base);
loc_82290C58:
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r28,92
	ctx.r4.s64 = r28.s64 + 92;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82388628
	ctx.lr = 0x82290C68;
	sub_82388628(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// ld r4,0(r27)
	ctx.r4.u64 = PPC_LOAD_U64(r27.u32 + 0);
	// bl 0x823882b8
	ctx.lr = 0x82290C78;
	sub_823882B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82290c9c
	if (!cr6.eq) goto loc_82290C9C;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,39
	ctx.r4.s64 = 39;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82290C98;
	sub_8268EE10(ctx, base);
	// b 0x82290d0c
	goto loc_82290D0C;
loc_82290C9C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bge cr6,0x82290cbc
	if (!cr6.lt) goto loc_82290CBC;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,37
	ctx.r4.s64 = 37;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82290CB8;
	sub_8268EE10(ctx, base);
	// b 0x82290d0c
	goto loc_82290D0C;
loc_82290CBC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82290CCC;
	sub_822A3998(ctx, base);
	// lwz r10,52(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r9,8100(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8100);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82290d04
	if (cr6.eq) goto loc_82290D04;
	// bl 0x82387b90
	ctx.lr = 0x82290CE0;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// bne cr6,0x82290d04
	if (!cr6.eq) goto loc_82290D04;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,41
	ctx.r4.s64 = 41;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268ee10
	ctx.lr = 0x82290D00;
	sub_8268EE10(ctx, base);
	// b 0x82290d0c
	goto loc_82290D0C;
loc_82290D04:
	// li r11,1
	r11.s64 = 1;
	// stb r11,28(r29)
	PPC_STORE_U8(r29.u32 + 28, r11.u8);
loc_82290D0C:
	// lbz r11,28(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-29340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// bl 0x826a4718
	ctx.lr = 0x82290D28;
	sub_826A4718(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290D34:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290D40;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x82290D54;
	sub_8268C9F0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r9,76(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 76);
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r6,r10,-7572
	ctx.r6.s64 = ctx.r10.s64 + -7572;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r5,r8,-22108
	ctx.r5.s64 = ctx.r8.s64 + -22108;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r3,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r9.u32);
	// lwz r30,4292(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4292);
	// bl 0x823dedd8
	ctx.lr = 0x82290D8C;
	sub_823DEDD8(ctx, base);
	// bl 0x82204ab8
	ctx.lr = 0x82290D90;
	sub_82204AB8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82298f08
	ctx.lr = 0x82290D9C;
	sub_82298F08(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r11,0
	r11.s64 = 0;
	// addi r30,r3,44
	r30.s64 = ctx.r3.s64 + 44;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lis r4,8192
	ctx.r4.s64 = 536870912;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// ori r4,r4,53
	ctx.r4.u64 = ctx.r4.u64 | 53;
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// bl 0x824e9038
	ctx.lr = 0x82290DC4;
	sub_824E9038(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// bl 0x824e9690
	ctx.lr = 0x82290DD8;
	sub_824E9690(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824f9438
	ctx.lr = 0x82290DEC;
	sub_824F9438(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ld r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x824f92a0
	ctx.lr = 0x82290DF8;
	sub_824F92A0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290E00;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82290E14;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x82290E1C;
	sub_822734B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290E28:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822809b8
	ctx.lr = 0x82290E30;
	sub_822809B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227e750
	ctx.lr = 0x82290E44;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82290ec4
	if (!cr6.eq) goto loc_82290EC4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290E58;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r29,4(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r31,-10240(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82388580
	ctx.lr = 0x82290E70;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,-10240(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r30,4(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82290E88;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x822577d0
	ctx.lr = 0x82290E90;
	sub_822577D0(ctx, base);
	// cntlzw r29,r3
	r29.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82270170
	ctx.lr = 0x82290EA0;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// rlwinm r5,r29,27,31,31
	ctx.r5.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 27) & 0x1;
	// bl 0x82274128
	ctx.lr = 0x82290EAC;
	sub_82274128(ctx, base);
	// lis r9,-32126
	ctx.r9.s64 = -2105409536;
	// lwz r3,24588(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82290EB8;
	sub_821E6800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290EC4:
	// lwz r3,700(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 700);
	// bl 0x82280ad8
	ctx.lr = 0x82290ECC;
	sub_82280AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82280e38
	ctx.lr = 0x82290EE0;
	sub_82280E38(ctx, base);
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82290EEC;
	sub_821E6800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290EF8:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// bl 0x82387b90
	ctx.lr = 0x82290F10;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// mulli r11,r11,8176
	r11.s64 = r11.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238f6b0
	ctx.lr = 0x82290F24;
	sub_8238F6B0(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// subfic r10,r3,4
	xer.ca = ctx.r3.u32 <= 4;
	ctx.r10.s64 = 4 - ctx.r3.s64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r9,4304(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,148(r8)
	PPC_STORE_U32(ctx.r8.u32 + 148, ctx.r10.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290F44:
	// lwz r10,24(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82291114
	if (cr6.eq) goto loc_82291114;
	// addi r11,r11,-31
	r11.s64 = r11.s64 + -31;
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// bgt cr6,0x82291114
	if (cr6.gt) goto loc_82291114;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,3956
	r12.s64 = r12.s64 + 3956;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82290F8C;
	case 1:
		goto loc_8229100C;
	case 2:
		goto loc_82291090;
	case 3:
		goto loc_822910D8;
	case 4:
		goto loc_8229104C;
	case 5:
		goto loc_82290FCC;
	default:
		__builtin_unreachable();
	}
	// lwz r17,3980(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 3980);
	// lwz r17,4108(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4108);
	// lwz r17,4240(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4240);
	// lwz r17,4312(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4312);
	// lwz r17,4172(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4172);
	// lwz r17,4044(r9)
	r17.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4044);
loc_82290F8C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290F94;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,24(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82290FAC;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822734b0
	ctx.lr = 0x82290FB4;
	sub_822734B0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82291114
	if (cr6.eq) goto loc_82291114;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82290FCC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82290FD4;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,24(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82290FEC;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82273520
	ctx.lr = 0x82290FF4;
	sub_82273520(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82291114
	if (cr6.eq) goto loc_82291114;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8229100C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291014;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,16(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8229102C;
	sub_82270170(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x821a5cc0
	ctx.lr = 0x82291034;
	sub_821A5CC0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82291114
	if (cr6.eq) goto loc_82291114;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8229104C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291054;
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
	ctx.lr = 0x82291068;
	sub_82270170(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// lwz r4,208(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// bl 0x8228a390
	ctx.lr = 0x82291078;
	sub_8228A390(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82291114
	if (cr6.eq) goto loc_82291114;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_82291090:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291098;
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
	ctx.lr = 0x822910AC;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x822910B4;
	sub_82272A30(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// bl 0x82290040
	ctx.lr = 0x822910C0;
	sub_82290040(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82291114
	if (cr6.eq) goto loc_82291114;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822910D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822910E0;
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
	ctx.lr = 0x822910F4;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x822910FC;
	sub_82272A30(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r29,16
	ctx.r3.s64 = r29.s64 + 16;
	// bl 0x82290108
	ctx.lr = 0x82291108;
	sub_82290108(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822912bc
	if (!cr6.eq) goto loc_822912BC;
loc_82291114:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24612(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24612);
	// bl 0x821e6800
	ctx.lr = 0x82291120;
	sub_821E6800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8229112C:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227e750
	ctx.lr = 0x82291134;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// addi r29,r11,-2628
	r29.s64 = r11.s64 + -2628;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82291158;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8229116C;
	sub_822701C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x8229117C;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82295b28
	ctx.lr = 0x8229118C;
	sub_82295B28(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82295510
	ctx.lr = 0x8229119C;
	sub_82295510(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822911B4;
	sub_8268C9F0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822912bc
	if (cr6.eq) goto loc_822912BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822911C8;
	sub_8268C9F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82291270
	if (cr6.eq) goto loc_82291270;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// beq cr6,0x82291204
	if (cr6.eq) goto loc_82291204;
	// cmpwi cr6,r11,5
	cr6.compare<int32_t>(r11.s32, 5, xer);
	// bne cr6,0x822912bc
	if (!cr6.eq) goto loc_822912BC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x822911F0;
	sub_8268C9F0(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x821c9790
	ctx.lr = 0x822911FC;
	sub_821C9790(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x822912b0
	goto loc_822912B0;
loc_82291204:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x8229124c
	if (!cr6.eq) goto loc_8229124C;
	// bl 0x8268c9f0
	ctx.lr = 0x82291218;
	sub_8268C9F0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268c970
	ctx.lr = 0x82291220;
	sub_8268C970(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82291230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295d70
	ctx.lr = 0x82291240;
	sub_82295D70(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_8229124C:
	// bl 0x8268c9f0
	ctx.lr = 0x82291250;
	sub_8268C9F0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8268c970
	ctx.lr = 0x82291258;
	sub_8268C970(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82291268;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// b 0x822912b0
	goto loc_822912B0;
loc_82291270:
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x822912a4
	if (!cr6.eq) goto loc_822912A4;
	// bl 0x8268c9f0
	ctx.lr = 0x82291284;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82295d70
	ctx.lr = 0x82291298;
	sub_82295D70(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
loc_822912A4:
	// bl 0x8268c9f0
	ctx.lr = 0x822912A8;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r5,4(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4);
loc_822912B0:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295f70
	ctx.lr = 0x822912BC;
	sub_82295F70(ctx, base);
loc_822912BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822912C8"))) PPC_WEAK_FUNC(sub_822912C8);
PPC_FUNC_IMPL(__imp__sub_822912C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r3,15765(r11)
	ctx.r3.u64 = PPC_LOAD_U8(r11.u32 + 15765);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822912D4"))) PPC_WEAK_FUNC(sub_822912D4);
PPC_FUNC_IMPL(__imp__sub_822912D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822912D8"))) PPC_WEAK_FUNC(sub_822912D8);
PPC_FUNC_IMPL(__imp__sub_822912D8) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82291310
	if (cr6.eq) goto loc_82291310;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,7
	ctx.r4.s64 = 7;
	// bl 0x82274120
	ctx.lr = 0x82291300;
	sub_82274120(ctx, base);
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82291310;
	sub_82274120(ctx, base);
loc_82291310:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291324"))) PPC_WEAK_FUNC(sub_82291324);
PPC_FUNC_IMPL(__imp__sub_82291324) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291328"))) PPC_WEAK_FUNC(sub_82291328);
PPC_FUNC_IMPL(__imp__sub_82291328) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r6,r11,-12632
	ctx.r6.s64 = r11.s64 + -12632;
	// addi r5,r10,-12656
	ctx.r5.s64 = ctx.r10.s64 + -12656;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8229135C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822913ac
	if (cr6.eq) goto loc_822913AC;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822913ac
	if (cr6.eq) goto loc_822913AC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82291380;
	sub_82274120(ctx, base);
	// cmpwi cr6,r30,-1
	cr6.compare<int32_t>(r30.s32, -1, xer);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x82291398
	if (!cr6.eq) goto loc_82291398;
	// li r5,0
	ctx.r5.s64 = 0;
	// b 0x822913a8
	goto loc_822913A8;
loc_82291398:
	// cntlzw r11,r30
	r11.u64 = r30.u32 == 0 ? 32 : __builtin_clz(r30.u32);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r5,r11,2
	ctx.r5.s64 = r11.s64 + 2;
loc_822913A8:
	// bl 0x82274128
	ctx.lr = 0x822913AC;
	sub_82274128(ctx, base);
loc_822913AC:
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

__attribute__((alias("__imp__sub_822913C4"))) PPC_WEAK_FUNC(sub_822913C4);
PPC_FUNC_IMPL(__imp__sub_822913C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822913C8"))) PPC_WEAK_FUNC(sub_822913C8);
PPC_FUNC_IMPL(__imp__sub_822913C8) {
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
	ctx.lr = 0x822913F4;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82291428
	if (cr6.eq) goto loc_82291428;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82291428
	if (cr6.eq) goto loc_82291428;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82291418;
	sub_82274120(ctx, base);
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274128
	ctx.lr = 0x82291428;
	sub_82274128(ctx, base);
loc_82291428:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8229143C"))) PPC_WEAK_FUNC(sub_8229143C);
PPC_FUNC_IMPL(__imp__sub_8229143C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291440"))) PPC_WEAK_FUNC(sub_82291440);
PPC_FUNC_IMPL(__imp__sub_82291440) {
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
	ctx.lr = 0x82291448;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r31,r11,16
	r31.s64 = r11.s64 + 16;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82502300
	ctx.lr = 0x82291460;
	sub_82502300(ctx, base);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82502300
	ctx.lr = 0x82291470;
	sub_82502300(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824f0550
	ctx.lr = 0x82291478;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291490
	if (cr6.eq) goto loc_82291490;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82291490:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82502300
	ctx.lr = 0x82291498;
	sub_82502300(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82502300
	ctx.lr = 0x822914A4;
	sub_82502300(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x824f0590
	ctx.lr = 0x822914AC;
	sub_824F0590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// subfic r10,r11,0
	xer.ca = r11.u32 <= 0;
	ctx.r10.s64 = 0 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// rlwinm r11,r9,0,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r3,r11,1
	ctx.r3.s64 = r11.s64 + 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822914C8"))) PPC_WEAK_FUNC(sub_822914C8);
PPC_FUNC_IMPL(__imp__sub_822914C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// stw r3,15896(r11)
	PPC_STORE_U32(r11.u32 + 15896, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822914D4"))) PPC_WEAK_FUNC(sub_822914D4);
PPC_FUNC_IMPL(__imp__sub_822914D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822914D8"))) PPC_WEAK_FUNC(sub_822914D8);
PPC_FUNC_IMPL(__imp__sub_822914D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// stw r3,-7448(r11)
	PPC_STORE_U32(r11.u32 + -7448, ctx.r3.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822914E4"))) PPC_WEAK_FUNC(sub_822914E4);
PPC_FUNC_IMPL(__imp__sub_822914E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822914E8"))) PPC_WEAK_FUNC(sub_822914E8);
PPC_FUNC_IMPL(__imp__sub_822914E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291504"))) PPC_WEAK_FUNC(sub_82291504);
PPC_FUNC_IMPL(__imp__sub_82291504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291508"))) PPC_WEAK_FUNC(sub_82291508);
PPC_FUNC_IMPL(__imp__sub_82291508) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r12{};
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
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stb r11,15764(r10)
	PPC_STORE_U8(ctx.r10.u32 + 15764, r11.u8);
	// lfs f1,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x82291530;
	sub_82293E30(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r8,15900
	ctx.r3.s64 = ctx.r8.s64 + 15900;
	// bl 0x82293e60
	ctx.lr = 0x82291540;
	sub_82293E60(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// addi r6,r7,15912
	ctx.r6.s64 = ctx.r7.s64 + 15912;
	// stw r11,64(r6)
	PPC_STORE_U32(ctx.r6.u32 + 64, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291560"))) PPC_WEAK_FUNC(sub_82291560);
PPC_FUNC_IMPL(__imp__sub_82291560) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,0
	r11.s64 = 0;
	// stb r11,15764(r10)
	PPC_STORE_U8(ctx.r10.u32 + 15764, r11.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291570"))) PPC_WEAK_FUNC(sub_82291570);
PPC_FUNC_IMPL(__imp__sub_82291570) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// b 0x8229c750
	sub_8229C750(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8229158C"))) PPC_WEAK_FUNC(sub_8229158C);
PPC_FUNC_IMPL(__imp__sub_8229158C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291590"))) PPC_WEAK_FUNC(sub_82291590);
PPC_FUNC_IMPL(__imp__sub_82291590) {
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
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227f5f0
	ctx.lr = 0x822915B4;
	sub_8227F5F0(ctx, base);
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

__attribute__((alias("__imp__sub_822915D4"))) PPC_WEAK_FUNC(sub_822915D4);
PPC_FUNC_IMPL(__imp__sub_822915D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822915D8"))) PPC_WEAK_FUNC(sub_822915D8);
PPC_FUNC_IMPL(__imp__sub_822915D8) {
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
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x82280848
	ctx.lr = 0x822915FC;
	sub_82280848(ctx, base);
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

__attribute__((alias("__imp__sub_8229161C"))) PPC_WEAK_FUNC(sub_8229161C);
PPC_FUNC_IMPL(__imp__sub_8229161C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291620"))) PPC_WEAK_FUNC(sub_82291620);
PPC_FUNC_IMPL(__imp__sub_82291620) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226bf18
	ctx.lr = 0x82291640;
	sub_8226BF18(ctx, base);
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

__attribute__((alias("__imp__sub_82291660"))) PPC_WEAK_FUNC(sub_82291660);
PPC_FUNC_IMPL(__imp__sub_82291660) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b298
	ctx.lr = 0x82291680;
	sub_8226B298(ctx, base);
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

__attribute__((alias("__imp__sub_822916A0"))) PPC_WEAK_FUNC(sub_822916A0);
PPC_FUNC_IMPL(__imp__sub_822916A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,-7448(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7448, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822916B4"))) PPC_WEAK_FUNC(sub_822916B4);
PPC_FUNC_IMPL(__imp__sub_822916B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822916B8"))) PPC_WEAK_FUNC(sub_822916B8);
PPC_FUNC_IMPL(__imp__sub_822916B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-7448(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -7448);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822916CC"))) PPC_WEAK_FUNC(sub_822916CC);
PPC_FUNC_IMPL(__imp__sub_822916CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822916D0"))) PPC_WEAK_FUNC(sub_822916D0);
PPC_FUNC_IMPL(__imp__sub_822916D0) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// stw r11,-7448(r10)
	PPC_STORE_U32(ctx.r10.u32 + -7448, r11.u32);
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// bl 0x8226f5d8
	ctx.lr = 0x82291700;
	sub_8226F5D8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291710"))) PPC_WEAK_FUNC(sub_82291710);
PPC_FUNC_IMPL(__imp__sub_82291710) {
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
	// bl 0x82387a18
	ctx.lr = 0x82291728;
	sub_82387A18(ctx, base);
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

__attribute__((alias("__imp__sub_82291748"))) PPC_WEAK_FUNC(sub_82291748);
PPC_FUNC_IMPL(__imp__sub_82291748) {
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
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r11,108(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291794
	if (cr6.eq) goto loc_82291794;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82291778;
	sub_821F8730(ctx, base);
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
loc_82291794:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
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

__attribute__((alias("__imp__sub_822917B4"))) PPC_WEAK_FUNC(sub_822917B4);
PPC_FUNC_IMPL(__imp__sub_822917B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822917B8"))) PPC_WEAK_FUNC(sub_822917B8);
PPC_FUNC_IMPL(__imp__sub_822917B8) {
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
	// bl 0x82387a18
	ctx.lr = 0x822917D0;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229180c
	if (cr6.eq) goto loc_8229180C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x822917EC;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x822917F0;
	sub_82293F60(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stfs f1,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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
loc_8229180C:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r10.u32 + 0, temp.u32);
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

__attribute__((alias("__imp__sub_82291830"))) PPC_WEAK_FUNC(sub_82291830);
PPC_FUNC_IMPL(__imp__sub_82291830) {
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
	// bl 0x82387a18
	ctx.lr = 0x82291848;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229187c
	if (cr6.eq) goto loc_8229187C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b328
	ctx.lr = 0x82291860;
	sub_8226B328(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8229187C:
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

__attribute__((alias("__imp__sub_8229189C"))) PPC_WEAK_FUNC(sub_8229189C);
PPC_FUNC_IMPL(__imp__sub_8229189C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822918A0"))) PPC_WEAK_FUNC(sub_822918A0);
PPC_FUNC_IMPL(__imp__sub_822918A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r9,700(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r8,16(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// stw r6,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r6.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822918C4"))) PPC_WEAK_FUNC(sub_822918C4);
PPC_FUNC_IMPL(__imp__sub_822918C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822918C8"))) PPC_WEAK_FUNC(sub_822918C8);
PPC_FUNC_IMPL(__imp__sub_822918C8) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226c270
	ctx.lr = 0x822918E8;
	sub_8226C270(ctx, base);
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

__attribute__((alias("__imp__sub_82291908"))) PPC_WEAK_FUNC(sub_82291908);
PPC_FUNC_IMPL(__imp__sub_82291908) {
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
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x82291924;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229193c
	if (cr6.eq) goto loc_8229193C;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82291938;
	sub_822A39C8(ctx, base);
	// bl 0x822a6b00
	ctx.lr = 0x8229193C;
	sub_822A6B00(ctx, base);
loc_8229193C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291950"))) PPC_WEAK_FUNC(sub_82291950);
PPC_FUNC_IMPL(__imp__sub_82291950) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32460(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 32460);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291964"))) PPC_WEAK_FUNC(sub_82291964);
PPC_FUNC_IMPL(__imp__sub_82291964) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291968"))) PPC_WEAK_FUNC(sub_82291968);
PPC_FUNC_IMPL(__imp__sub_82291968) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r10,127
	ctx.r10.s64 = 127;
	// addi r9,r11,15768
	ctx.r9.s64 = r11.s64 + 15768;
	// mr r11,r9
	r11.u64 = ctx.r9.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// subf r9,r9,r3
	ctx.r9.s64 = ctx.r3.s64 - ctx.r9.s64;
loc_8229198C:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822919a4
	if (cr6.eq) goto loc_822919A4;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x8229198c
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_8229198C;
loc_822919A4:
	// li r10,0
	ctx.r10.s64 = 0;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r3,r9,15900
	ctx.r3.s64 = ctx.r9.s64 + 15900;
	// bl 0x82293e60
	ctx.lr = 0x822919B8;
	sub_82293E60(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// li r11,1
	r11.s64 = 1;
	// stb r11,15764(r8)
	PPC_STORE_U8(ctx.r8.u32 + 15764, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822919D4"))) PPC_WEAK_FUNC(sub_822919D4);
PPC_FUNC_IMPL(__imp__sub_822919D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822919D8"))) PPC_WEAK_FUNC(sub_822919D8);
PPC_FUNC_IMPL(__imp__sub_822919D8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822919EC;
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
	ctx.lr = 0x82291A00;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x82291A0C;
	sub_82274128(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291A1C"))) PPC_WEAK_FUNC(sub_82291A1C);
PPC_FUNC_IMPL(__imp__sub_82291A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291A20"))) PPC_WEAK_FUNC(sub_82291A20);
PPC_FUNC_IMPL(__imp__sub_82291A20) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82291a64
	if (cr6.eq) goto loc_82291A64;
	// bl 0x82203310
	ctx.lr = 0x82291A40;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291a64
	if (cr6.eq) goto loc_82291A64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82291A58;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82291a68
	if (!cr6.eq) goto loc_82291A68;
loc_82291A64:
	// li r11,0
	r11.s64 = 0;
loc_82291A68:
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

__attribute__((alias("__imp__sub_82291A80"))) PPC_WEAK_FUNC(sub_82291A80);
PPC_FUNC_IMPL(__imp__sub_82291A80) {
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
	ctx.lr = 0x82291A88;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291A98;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82291AA8;
	sub_82270170(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lbz r11,15764(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 15764);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291c24
	if (cr6.eq) goto loc_82291C24;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82291c24
	if (cr6.eq) goto loc_82291C24;
	// lbz r11,9(r10)
	r11.u64 = PPC_LOAD_U8(ctx.r10.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82291c24
	if (!cr6.eq) goto loc_82291C24;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x82291ADC;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291c24
	if (cr6.eq) goto loc_82291C24;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r27,r11,15900
	r27.s64 = r11.s64 + 15900;
	// bl 0x8226b2f0
	ctx.lr = 0x82291AFC;
	sub_8226B2F0(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82293ee8
	ctx.lr = 0x82291B04;
	sub_82293EE8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82291c24
	if (cr6.eq) goto loc_82291C24;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e3d8
	ctx.lr = 0x82291B1C;
	sub_8227E3D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291b94
	if (cr6.eq) goto loc_82291B94;
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r10,127
	ctx.r10.s64 = 127;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r9,r10,15768
	ctx.r9.s64 = ctx.r10.s64 + 15768;
	// subf r9,r28,r9
	ctx.r9.s64 = ctx.r9.s64 - r28.s64;
loc_82291B40:
	// lbzx r10,r9,r11
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82291b58
	if (cr6.eq) goto loc_82291B58;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bdnz 0x82291b40
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_82291B40;
loc_82291B58:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r8,10016
	ctx.r4.s64 = ctx.r8.s64 + 10016;
	// lwz r3,-12440(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12440);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,48(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 48);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82291B88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82291B94:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291B9C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82291BAC;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82291BB8;
	sub_82274128(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stb r11,15764(r29)
	PPC_STORE_U8(r29.u32 + 15764, r11.u8);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227f2c8
	ctx.lr = 0x82291BCC;
	sub_8227F2C8(ctx, base);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,35
	ctx.r4.s64 = 35;
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8268ee10
	ctx.lr = 0x82291BE8;
	sub_8268EE10(ctx, base);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82291c24
	if (!cr6.eq) goto loc_82291C24;
	// bl 0x82280ad8
	ctx.lr = 0x82291C00;
	sub_82280AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291c24
	if (cr6.eq) goto loc_82291C24;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f1,10012(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 10012);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x82280da8
	ctx.lr = 0x82291C24;
	sub_82280DA8(ctx, base);
loc_82291C24:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82291C30"))) PPC_WEAK_FUNC(sub_82291C30);
PPC_FUNC_IMPL(__imp__sub_82291C30) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b298
	ctx.lr = 0x82291C4C;
	sub_8226B298(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82291ca8
	if (cr6.eq) goto loc_82291CA8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291C60;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82291C70;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481580
	ctx.lr = 0x82291C7C;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82291ca8
	if (!cr6.eq) goto loc_82291CA8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291C90;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82291CA0;
	sub_82270170(ctx, base);
	// lwz r3,208(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// bl 0x822975d0
	ctx.lr = 0x82291CA8;
	sub_822975D0(ctx, base);
loc_82291CA8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291CBC"))) PPC_WEAK_FUNC(sub_82291CBC);
PPC_FUNC_IMPL(__imp__sub_82291CBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291CC0"))) PPC_WEAK_FUNC(sub_82291CC0);
PPC_FUNC_IMPL(__imp__sub_82291CC0) {
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
	ctx.lr = 0x82291CC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r28,0
	r28.s64 = 0;
	// li r30,12
	r30.s64 = 12;
	// lis r29,-32121
	r29.s64 = -2105081856;
loc_82291CD8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291CE0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82291CF0;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwzx r31,r10,r30
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82291d70
	if (cr6.eq) goto loc_82291D70;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291d34
	if (cr6.eq) goto loc_82291D34;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82291d2c
	if (!cr6.eq) goto loc_82291D2C;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82291D20;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291d34
	if (cr6.eq) goto loc_82291D34;
loc_82291D2C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82291d38
	goto loc_82291D38;
loc_82291D34:
	// li r11,0
	r11.s64 = 0;
loc_82291D38:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291d5c
	if (cr6.eq) goto loc_82291D5C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82291D50;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82291d60
	if (!cr6.eq) goto loc_82291D60;
loc_82291D5C:
	// li r11,0
	r11.s64 = 0;
loc_82291D60:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291d70
	if (cr6.eq) goto loc_82291D70;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_82291D70:
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r30,136
	cr6.compare<int32_t>(r30.s32, 136, xer);
	// blt cr6,0x82291cd8
	if (cr6.lt) goto loc_82291CD8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82291D88"))) PPC_WEAK_FUNC(sub_82291D88);
PPC_FUNC_IMPL(__imp__sub_82291D88) {
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
	ctx.lr = 0x82291D90;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291D9C;
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
	ctx.lr = 0x82291DB0;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291e40
	if (cr6.eq) goto loc_82291E40;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_82291DC4:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82291e34
	if (cr6.eq) goto loc_82291E34;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291e04
	if (cr6.eq) goto loc_82291E04;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82291dfc
	if (!cr6.eq) goto loc_82291DFC;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82291DF0;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291e04
	if (cr6.eq) goto loc_82291E04;
loc_82291DFC:
	// li r11,1
	r11.s64 = 1;
	// b 0x82291e08
	goto loc_82291E08;
loc_82291E04:
	// li r11,0
	r11.s64 = 0;
loc_82291E08:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82291e34
	if (cr6.eq) goto loc_82291E34;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82291E24;
	sub_82274120(ctx, base);
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82291E34;
	sub_82274120(ctx, base);
loc_82291E34:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82291dc4
	if (!cr0.eq) goto loc_82291DC4;
loc_82291E40:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82291E48"))) PPC_WEAK_FUNC(sub_82291E48);
PPC_FUNC_IMPL(__imp__sub_82291E48) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r6,r11,-12632
	ctx.r6.s64 = r11.s64 + -12632;
	// addi r5,r10,-12656
	ctx.r5.s64 = ctx.r10.s64 + -12656;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82291E7C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82291ed4
	if (cr6.eq) goto loc_82291ED4;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82291ec4
	if (cr6.eq) goto loc_82291EC4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82291E9C;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// beq cr6,0x82291eac
	if (cr6.eq) goto loc_82291EAC;
	// cmpwi cr6,r3,4
	cr6.compare<int32_t>(ctx.r3.s32, 4, xer);
	// bne cr6,0x82291ed4
	if (!cr6.eq) goto loc_82291ED4;
loc_82291EAC:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82291EB8;
	sub_822051A0(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82291ed8
	goto loc_82291ED8;
loc_82291EC4:
	// li r11,-1
	r11.s64 = -1;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// b 0x82291ed8
	goto loc_82291ED8;
loc_82291ED4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82291ED8:
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

__attribute__((alias("__imp__sub_82291EF0"))) PPC_WEAK_FUNC(sub_82291EF0);
PPC_FUNC_IMPL(__imp__sub_82291EF0) {
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
	ctx.lr = 0x82291F1C;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82291f90
	if (cr6.eq) goto loc_82291F90;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82291f90
	if (cr6.eq) goto loc_82291F90;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274120
	ctx.lr = 0x82291F40;
	sub_82274120(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82274128
	ctx.lr = 0x82291F50;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82291F58;
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
	ctx.lr = 0x82291F6C;
	sub_82270170(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x82291f90
	if (!cr6.eq) goto loc_82291F90;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x822049c0
	ctx.lr = 0x82291F7C;
	sub_822049C0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82207190
	ctx.lr = 0x82291F90;
	sub_82207190(ctx, base);
loc_82291F90:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82291FA4"))) PPC_WEAK_FUNC(sub_82291FA4);
PPC_FUNC_IMPL(__imp__sub_82291FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82291FA8"))) PPC_WEAK_FUNC(sub_82291FA8);
PPC_FUNC_IMPL(__imp__sub_82291FA8) {
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
	ctx.lr = 0x82291FD4;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292024
	if (cr6.eq) goto loc_82292024;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82292024
	if (cr6.eq) goto loc_82292024;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e0b0
	ctx.lr = 0x82291FF8;
	sub_8227E0B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82292024
	if (cr6.eq) goto loc_82292024;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82292010;
	sub_822577D0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82292024:
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

__attribute__((alias("__imp__sub_8229203C"))) PPC_WEAK_FUNC(sub_8229203C);
PPC_FUNC_IMPL(__imp__sub_8229203C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292040"))) PPC_WEAK_FUNC(sub_82292040);
PPC_FUNC_IMPL(__imp__sub_82292040) {
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
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8229206C;
	sub_822701C8(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x82292080;
	sub_82293E30(ctx, base);
	// bl 0x82256058
	ctx.lr = 0x82292084;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822920a8
	if (cr6.eq) goto loc_822920A8;
	// bl 0x82256058
	ctx.lr = 0x82292090;
	sub_82256058(ctx, base);
	// lbz r11,3764(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 3764);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822920a8
	if (cr6.eq) goto loc_822920A8;
	// bl 0x82256058
	ctx.lr = 0x822920A0;
	sub_82256058(ctx, base);
	// bl 0x82256028
	ctx.lr = 0x822920A4;
	sub_82256028(ctx, base);
	// b 0x82292158
	goto loc_82292158;
loc_822920A8:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82292154
	if (cr6.eq) goto loc_82292154;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x822920BC;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292154
	if (cr6.eq) goto loc_82292154;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822952b0
	ctx.lr = 0x822920D4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292154
	if (cr6.eq) goto loc_82292154;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295538
	ctx.lr = 0x822920F0;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82292154
	if (cr6.eq) goto loc_82292154;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293f60
	ctx.lr = 0x82292100;
	sub_82293F60(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x82292110;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82292114;
	sub_82293F60(ctx, base);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f0,30712(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 30712);
	f0.f64 = double(temp.f32);
	// lfd f13,10024(r9)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r9.u32 + 10024);
	// lfs f12,32(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	ctx.f12.f64 = double(temp.f32);
	// fadds f11,f12,f31
	ctx.f11.f64 = double(float(ctx.f12.f64 + f31.f64));
	// fadds f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 + f0.f64));
	// fsubs f9,f1,f10
	ctx.f9.f64 = double(float(ctx.f1.f64 - ctx.f10.f64));
	// fmul f8,f9,f13
	ctx.f8.f64 = ctx.f9.f64 * ctx.f13.f64;
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f7.u64);
	// lwz r7,84(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r3,r7,-200
	xer.ca = ctx.r7.u32 <= 4294967096;
	ctx.r3.s64 = -200 - ctx.r7.s64;
	// b 0x82292158
	goto loc_82292158;
loc_82292154:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82292158:
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

__attribute__((alias("__imp__sub_82292174"))) PPC_WEAK_FUNC(sub_82292174);
PPC_FUNC_IMPL(__imp__sub_82292174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292178"))) PPC_WEAK_FUNC(sub_82292178);
PPC_FUNC_IMPL(__imp__sub_82292178) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822921A4;
	sub_822701C8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x822921B4;
	sub_8226BE68(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82292220
	if (cr6.eq) goto loc_82292220;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82292220
	if (cr6.eq) goto loc_82292220;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295b28
	ctx.lr = 0x822921D4;
	sub_82295B28(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82292220
	if (cr6.lt) goto loc_82292220;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295510
	ctx.lr = 0x822921EC;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bne cr6,0x82292204
	if (!cr6.eq) goto loc_82292204;
	// bl 0x82295c90
	ctx.lr = 0x82292200;
	sub_82295C90(ctx, base);
	// b 0x82292224
	goto loc_82292224;
loc_82292204:
	// bl 0x82295510
	ctx.lr = 0x82292208;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82292220
	if (!cr6.eq) goto loc_82292220;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8229221C;
	sub_82295E90(ctx, base);
	// b 0x82292224
	goto loc_82292224;
loc_82292220:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82292224:
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

__attribute__((alias("__imp__sub_8229223C"))) PPC_WEAK_FUNC(sub_8229223C);
PPC_FUNC_IMPL(__imp__sub_8229223C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292240"))) PPC_WEAK_FUNC(sub_82292240);
PPC_FUNC_IMPL(__imp__sub_82292240) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8229226C;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82292298
	if (cr6.eq) goto loc_82292298;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x82295b28
	ctx.lr = 0x82292280;
	sub_82295B28(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82292298
	if (cr6.lt) goto loc_82292298;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82292294;
	sub_822952B0(ctx, base);
	// b 0x8229229c
	goto loc_8229229C;
loc_82292298:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8229229C:
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

__attribute__((alias("__imp__sub_822922B4"))) PPC_WEAK_FUNC(sub_822922B4);
PPC_FUNC_IMPL(__imp__sub_822922B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822922B8"))) PPC_WEAK_FUNC(sub_822922B8);
PPC_FUNC_IMPL(__imp__sub_822922B8) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lbz r11,15765(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 15765);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292340
	if (cr6.eq) goto loc_82292340;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822922E0;
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
	ctx.lr = 0x822922F4;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292328
	if (cr6.eq) goto loc_82292328;
	// addi r10,r11,12
	ctx.r10.s64 = r11.s64 + 12;
	// li r9,31
	ctx.r9.s64 = 31;
loc_8229230C:
	// lwz r11,0(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8229231c
	if (cr6.eq) goto loc_8229231C;
	// stb r8,277(r11)
	PPC_STORE_U8(r11.u32 + 277, ctx.r8.u8);
loc_8229231C:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x8229230c
	if (!cr0.eq) goto loc_8229230C;
loc_82292328:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r11,r8
	r11.u64 = ctx.r8.u64;
	// addi r9,r10,15912
	ctx.r9.s64 = ctx.r10.s64 + 15912;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stb r10,15765(r31)
	PPC_STORE_U8(r31.u32 + 15765, ctx.r10.u8);
	// stw r11,64(r9)
	PPC_STORE_U32(ctx.r9.u32 + 64, r11.u32);
loc_82292340:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292354"))) PPC_WEAK_FUNC(sub_82292354);
PPC_FUNC_IMPL(__imp__sub_82292354) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292358"))) PPC_WEAK_FUNC(sub_82292358);
PPC_FUNC_IMPL(__imp__sub_82292358) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82292370;
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
	ctx.lr = 0x82292384;
	sub_82270170(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822923b8
	if (cr6.eq) goto loc_822923B8;
	// bl 0x82203310
	ctx.lr = 0x82292394;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822923b8
	if (cr6.eq) goto loc_822923B8;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x822923AC;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822923bc
	if (!cr6.eq) goto loc_822923BC;
loc_822923B8:
	// li r11,0
	r11.s64 = 0;
loc_822923BC:
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

__attribute__((alias("__imp__sub_822923D4"))) PPC_WEAK_FUNC(sub_822923D4);
PPC_FUNC_IMPL(__imp__sub_822923D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822923D8"))) PPC_WEAK_FUNC(sub_822923D8);
PPC_FUNC_IMPL(__imp__sub_822923D8) {
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
	ctx.lr = 0x822923E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,15765(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 15765);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82292468
	if (cr6.eq) goto loc_82292468;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822923FC;
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
	ctx.lr = 0x82292410;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292468
	if (cr6.eq) goto loc_82292468;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_82292424:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82292458
	if (cr6.eq) goto loc_82292458;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x82292438;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292458
	if (cr6.eq) goto loc_82292458;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82292450;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// beq cr6,0x82292474
	if (cr6.eq) goto loc_82292474;
loc_82292458:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// blt cr6,0x82292424
	if (cr6.lt) goto loc_82292424;
loc_82292468:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82292474:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82292480"))) PPC_WEAK_FUNC(sub_82292480);
PPC_FUNC_IMPL(__imp__sub_82292480) {
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
	ctx.lr = 0x822924AC;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822924ec
	if (cr6.eq) goto loc_822924EC;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822924ec
	if (cr6.eq) goto loc_822924EC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x822924C8;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822924ec
	if (cr6.eq) goto loc_822924EC;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x822924E0;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq cr6,0x822924f0
	if (cr6.eq) goto loc_822924F0;
loc_822924EC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822924F0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292504"))) PPC_WEAK_FUNC(sub_82292504);
PPC_FUNC_IMPL(__imp__sub_82292504) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292508"))) PPC_WEAK_FUNC(sub_82292508);
PPC_FUNC_IMPL(__imp__sub_82292508) {
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
	ctx.lr = 0x82292510;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// li r28,12
	r28.s64 = 12;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lis r25,-32121
	r25.s64 = -2105081856;
loc_8229252C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82292534;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82292544;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// lwzx r31,r10,r28
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r28.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82292614
	if (cr6.eq) goto loc_82292614;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292588
	if (cr6.eq) goto loc_82292588;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82292580
	if (!cr6.eq) goto loc_82292580;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82292574;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292588
	if (cr6.eq) goto loc_82292588;
loc_82292580:
	// li r11,1
	r11.s64 = 1;
	// b 0x8229258c
	goto loc_8229258C;
loc_82292588:
	// li r11,0
	r11.s64 = 0;
loc_8229258C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292614
	if (cr6.eq) goto loc_82292614;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x822925A0;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822925c4
	if (cr6.eq) goto loc_822925C4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x822925B8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822925c8
	if (!cr6.eq) goto loc_822925C8;
loc_822925C4:
	// li r11,0
	r11.s64 = 0;
loc_822925C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292614
	if (cr6.eq) goto loc_82292614;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,17268(r26)
	r30.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x822925E4;
	sub_822051A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822925F0;
	sub_822A3998(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,68(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 68);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82292600;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r24
	cr6.compare<int32_t>(ctx.r3.s32, r24.s32, xer);
	// bne cr6,0x82292614
	if (!cr6.eq) goto loc_82292614;
	// stw r31,0(r27)
	PPC_STORE_U32(r27.u32 + 0, r31.u32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
loc_82292614:
	// addi r28,r28,4
	r28.s64 = r28.s64 + 4;
	// cmpwi cr6,r28,136
	cr6.compare<int32_t>(r28.s32, 136, xer);
	// blt cr6,0x8229252c
	if (cr6.lt) goto loc_8229252C;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82292670
	if (cr6.eq) goto loc_82292670;
	// lis r11,-32215
	r11.s64 = -2111242240;
	// li r5,4
	ctx.r5.s64 = 4;
	// addi r6,r11,5184
	ctx.r6.s64 = r11.s64 + 5184;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823dcf08
	ctx.lr = 0x82292640;
	sub_823DCF08(ctx, base);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x82292670
	if (!cr6.gt) goto loc_82292670;
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
loc_82292650:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x82274120
	ctx.lr = 0x82292660;
	sub_82274120(ctx, base);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r29
	cr6.compare<int32_t>(r31.s32, r29.s32, xer);
	// blt cr6,0x82292650
	if (cr6.lt) goto loc_82292650;
loc_82292670:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82292678"))) PPC_WEAK_FUNC(sub_82292678);
PPC_FUNC_IMPL(__imp__sub_82292678) {
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
	ctx.lr = 0x82292680;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r7,86(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// li r11,0
	r11.s64 = 0;
	// lbz r5,81(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// li r8,255
	ctx.r8.s64 = 255;
	// ori r4,r7,128
	ctx.r4.u64 = ctx.r7.u64 | 128;
	// lbz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// ori r9,r5,224
	ctx.r9.u64 = ctx.r5.u64 | 224;
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// clrlwi r3,r6,25
	ctx.r3.u64 = ctx.r6.u32 & 0x7F;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// ori r7,r10,64
	ctx.r7.u64 = ctx.r10.u64 | 64;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// addi r29,r1,80
	r29.s64 = ctx.r1.s64 + 80;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stb r3,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r3.u8);
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// addi r31,r11,-2628
	r31.s64 = r11.s64 + -2628;
	// stb r9,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// stb r7,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r7.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822926F4;
	sub_822701C8(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82295538
	ctx.lr = 0x82292700;
	sub_82295538(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82397458
	ctx.lr = 0x82292708;
	sub_82397458(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82292730
	if (cr6.eq) goto loc_82292730;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e320
	ctx.lr = 0x82292724;
	sub_8227E320(ctx, base);
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
loc_82292730:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8229273C;
	sub_822701C8(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// bl 0x82295c90
	ctx.lr = 0x82292744;
	sub_82295C90(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8229274C"))) PPC_WEAK_FUNC(sub_8229274C);
PPC_FUNC_IMPL(__imp__sub_8229274C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292750"))) PPC_WEAK_FUNC(sub_82292750);
PPC_FUNC_IMPL(__imp__sub_82292750) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r7,86(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// li r8,255
	ctx.r8.s64 = 255;
	// lbz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// li r11,0
	r11.s64 = 0;
	// ori r4,r7,128
	ctx.r4.u64 = ctx.r7.u64 | 128;
	// lbz r5,81(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// clrlwi r3,r6,25
	ctx.r3.u64 = ctx.r6.u32 & 0x7F;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// ori r9,r5,224
	ctx.r9.u64 = ctx.r5.u64 | 224;
	// stb r3,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r3.u8);
	// ori r8,r10,64
	ctx.r8.u64 = ctx.r10.u64 | 64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// stb r9,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r9.u8);
	// addi r31,r1,80
	r31.s64 = ctx.r1.s64 + 80;
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
	// addi r4,r6,-2628
	ctx.r4.s64 = ctx.r6.s64 + -2628;
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// stb r8,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r8.u8);
	// lwz r3,-10240(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822927CC;
	sub_822701C8(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x822927D8;
	sub_82295538(ctx, base);
	// lwz r3,104(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
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

__attribute__((alias("__imp__sub_822927F0"))) PPC_WEAK_FUNC(sub_822927F0);
PPC_FUNC_IMPL(__imp__sub_822927F0) {
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
	ctx.lr = 0x822927F8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r28,0
	r28.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82292808;
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
	ctx.lr = 0x8229281C;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r29,31
	r29.s64 = 31;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_82292828:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82292890
	if (cr6.eq) goto loc_82292890;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292868
	if (cr6.eq) goto loc_82292868;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82292860
	if (!cr6.eq) goto loc_82292860;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82292854;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292868
	if (cr6.eq) goto loc_82292868;
loc_82292860:
	// li r11,1
	r11.s64 = 1;
	// b 0x8229286c
	goto loc_8229286C;
loc_82292868:
	// li r11,0
	r11.s64 = 0;
loc_8229286C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292890
	if (cr6.eq) goto loc_82292890;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82292884;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82292890
	if (!cr6.eq) goto loc_82292890;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_82292890:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82292828
	if (!cr0.eq) goto loc_82292828;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822928A8"))) PPC_WEAK_FUNC(sub_822928A8);
PPC_FUNC_IMPL(__imp__sub_822928A8) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822928D0;
	sub_822701C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,28
	ctx.r3.s64 = 28;
	// bl 0x82130528
	ctx.lr = 0x822928DC;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8229293c
	if (cr6.eq) goto loc_8229293C;
	// lbz r10,1(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// li r9,255
	ctx.r9.s64 = 255;
	// li r11,0
	r11.s64 = 0;
	// ori r8,r10,224
	ctx.r8.u64 = ctx.r10.u64 | 224;
	// stb r9,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r9.u8);
	// addi r10,r3,4
	ctx.r10.s64 = ctx.r3.s64 + 4;
	// stb r8,1(r3)
	PPC_STORE_U8(ctx.r3.u32 + 1, ctx.r8.u8);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// lbz r7,6(r3)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r3.u32 + 6);
	// ori r4,r7,192
	ctx.r4.u64 = ctx.r7.u64 | 192;
	// clrlwi r5,r6,25
	ctx.r5.u64 = ctx.r6.u32 & 0x7F;
	// stb r11,5(r3)
	PPC_STORE_U8(ctx.r3.u32 + 5, r11.u8);
	// stb r4,6(r3)
	PPC_STORE_U8(ctx.r3.u32 + 6, ctx.r4.u8);
	// stb r5,4(r3)
	PPC_STORE_U8(ctx.r3.u32 + 4, ctx.r5.u8);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stb r11,20(r3)
	PPC_STORE_U8(ctx.r3.u32 + 20, r11.u8);
	// stb r11,21(r3)
	PPC_STORE_U8(ctx.r3.u32 + 21, r11.u8);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, r11.u32);
	// b 0x82292940
	goto loc_82292940;
loc_8229293C:
	// li r31,0
	r31.s64 = 0;
loc_82292940:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295538
	ctx.lr = 0x82292950;
	sub_82295538(ctx, base);
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

__attribute__((alias("__imp__sub_8229296C"))) PPC_WEAK_FUNC(sub_8229296C);
PPC_FUNC_IMPL(__imp__sub_8229296C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292970"))) PPC_WEAK_FUNC(sub_82292970);
PPC_FUNC_IMPL(__imp__sub_82292970) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82292984;
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
	ctx.lr = 0x82292998;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x822929A0;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x822929A4;
	sub_82481590(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_822929B4"))) PPC_WEAK_FUNC(sub_822929B4);
PPC_FUNC_IMPL(__imp__sub_822929B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822929B8"))) PPC_WEAK_FUNC(sub_822929B8);
PPC_FUNC_IMPL(__imp__sub_822929B8) {
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
	// bl 0x82291cc0
	ctx.lr = 0x822929D0;
	sub_82291CC0(ctx, base);
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
}

__attribute__((alias("__imp__sub_822929EC"))) PPC_WEAK_FUNC(sub_822929EC);
PPC_FUNC_IMPL(__imp__sub_822929EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822929F0"))) PPC_WEAK_FUNC(sub_822929F0);
PPC_FUNC_IMPL(__imp__sub_822929F0) {
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
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-12632
	ctx.r6.s64 = ctx.r10.s64 + -12632;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82292A28;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292a60
	if (cr6.eq) goto loc_82292A60;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292a60
	if (cr6.eq) goto loc_82292A60;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x822051a0
	ctx.lr = 0x82292A44;
	sub_822051A0(ctx, base);
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
loc_82292A60:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,-1
	r11.s64 = -1;
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

__attribute__((alias("__imp__sub_82292A80"))) PPC_WEAK_FUNC(sub_82292A80);
PPC_FUNC_IMPL(__imp__sub_82292A80) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82291fa8
	ctx.lr = 0x82292AA0;
	sub_82291FA8(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292ABC"))) PPC_WEAK_FUNC(sub_82292ABC);
PPC_FUNC_IMPL(__imp__sub_82292ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292AC0"))) PPC_WEAK_FUNC(sub_82292AC0);
PPC_FUNC_IMPL(__imp__sub_82292AC0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82291d88
	sub_82291D88(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82292AC4"))) PPC_WEAK_FUNC(sub_82292AC4);
PPC_FUNC_IMPL(__imp__sub_82292AC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292AC8"))) PPC_WEAK_FUNC(sub_82292AC8);
PPC_FUNC_IMPL(__imp__sub_82292AC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82291328
	sub_82291328(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82292AD8"))) PPC_WEAK_FUNC(sub_82292AD8);
PPC_FUNC_IMPL(__imp__sub_82292AD8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x822913c8
	sub_822913C8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82292AE4"))) PPC_WEAK_FUNC(sub_82292AE4);
PPC_FUNC_IMPL(__imp__sub_82292AE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292AE8"))) PPC_WEAK_FUNC(sub_82292AE8);
PPC_FUNC_IMPL(__imp__sub_82292AE8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// b 0x82291ef0
	sub_82291EF0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82292AF4"))) PPC_WEAK_FUNC(sub_82292AF4);
PPC_FUNC_IMPL(__imp__sub_82292AF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292AF8"))) PPC_WEAK_FUNC(sub_82292AF8);
PPC_FUNC_IMPL(__imp__sub_82292AF8) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-12632
	ctx.r6.s64 = ctx.r10.s64 + -12632;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82292B28;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292b48
	if (cr6.eq) goto loc_82292B48;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292b48
	if (cr6.eq) goto loc_82292B48;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82274128
	ctx.lr = 0x82292B48;
	sub_82274128(ctx, base);
loc_82292B48:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292B58"))) PPC_WEAK_FUNC(sub_82292B58);
PPC_FUNC_IMPL(__imp__sub_82292B58) {
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
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-12632
	ctx.r6.s64 = ctx.r10.s64 + -12632;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82292B88;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292ba8
	if (cr6.eq) goto loc_82292BA8;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292ba8
	if (cr6.eq) goto loc_82292BA8;
	// li r5,5
	ctx.r5.s64 = 5;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82274128
	ctx.lr = 0x82292BA8;
	sub_82274128(ctx, base);
loc_82292BA8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292BB8"))) PPC_WEAK_FUNC(sub_82292BB8);
PPC_FUNC_IMPL(__imp__sub_82292BB8) {
	PPC_FUNC_PROLOGUE();
	// b 0x822922b8
	sub_822922B8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82292BBC"))) PPC_WEAK_FUNC(sub_82292BBC);
PPC_FUNC_IMPL(__imp__sub_82292BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292BC0"))) PPC_WEAK_FUNC(sub_82292BC0);
PPC_FUNC_IMPL(__imp__sub_82292BC0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// blt cr6,0x82292bf8
	if (cr6.lt) goto loc_82292BF8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r11,r11,15912
	r11.s64 = r11.s64 + 15912;
	// lwz r9,64(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 64);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// bge cr6,0x82292bf8
	if (!cr6.lt) goto loc_82292BF8;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// blr 
	return;
loc_82292BF8:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292C08"))) PPC_WEAK_FUNC(sub_82292C08);
PPC_FUNC_IMPL(__imp__sub_82292C08) {
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
	// bl 0x82292358
	ctx.lr = 0x82292C20;
	sub_82292358(ctx, base);
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

__attribute__((alias("__imp__sub_82292C40"))) PPC_WEAK_FUNC(sub_82292C40);
PPC_FUNC_IMPL(__imp__sub_82292C40) {
	PPC_FUNC_PROLOGUE();
	// b 0x82291c30
	sub_82291C30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82292C44"))) PPC_WEAK_FUNC(sub_82292C44);
PPC_FUNC_IMPL(__imp__sub_82292C44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292C48"))) PPC_WEAK_FUNC(sub_82292C48);
PPC_FUNC_IMPL(__imp__sub_82292C48) {
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
	ctx.lr = 0x82292C64;
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
	ctx.lr = 0x82292C78;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481580
	ctx.lr = 0x82292C84;
	sub_82481580(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292CA4"))) PPC_WEAK_FUNC(sub_82292CA4);
PPC_FUNC_IMPL(__imp__sub_82292CA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292CA8"))) PPC_WEAK_FUNC(sub_82292CA8);
PPC_FUNC_IMPL(__imp__sub_82292CA8) {
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
	// bl 0x822923d8
	ctx.lr = 0x82292CC0;
	sub_822923D8(ctx, base);
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

__attribute__((alias("__imp__sub_82292CE0"))) PPC_WEAK_FUNC(sub_82292CE0);
PPC_FUNC_IMPL(__imp__sub_82292CE0) {
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
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x82292480
	ctx.lr = 0x82292D00;
	sub_82292480(ctx, base);
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

__attribute__((alias("__imp__sub_82292D20"))) PPC_WEAK_FUNC(sub_82292D20);
PPC_FUNC_IMPL(__imp__sub_82292D20) {
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
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-12632
	ctx.r6.s64 = ctx.r10.s64 + -12632;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82292D58;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292d7c
	if (cr6.eq) goto loc_82292D7C;
	// lwz r11,1220(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82292d7c
	if (cr6.eq) goto loc_82292D7C;
	// lbz r11,278(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82292d80
	if (!cr6.eq) goto loc_82292D80;
loc_82292D7C:
	// li r11,0
	r11.s64 = 0;
loc_82292D80:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_82292DA0"))) PPC_WEAK_FUNC(sub_82292DA0);
PPC_FUNC_IMPL(__imp__sub_82292DA0) {
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
	// bl 0x82292678
	ctx.lr = 0x82292DB8;
	sub_82292678(ctx, base);
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
}

__attribute__((alias("__imp__sub_82292DD4"))) PPC_WEAK_FUNC(sub_82292DD4);
PPC_FUNC_IMPL(__imp__sub_82292DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292DD8"))) PPC_WEAK_FUNC(sub_82292DD8);
PPC_FUNC_IMPL(__imp__sub_82292DD8) {
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
	// bl 0x822927f0
	ctx.lr = 0x82292DF0;
	sub_822927F0(ctx, base);
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
}

__attribute__((alias("__imp__sub_82292E0C"))) PPC_WEAK_FUNC(sub_82292E0C);
PPC_FUNC_IMPL(__imp__sub_82292E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292E10"))) PPC_WEAK_FUNC(sub_82292E10);
PPC_FUNC_IMPL(__imp__sub_82292E10) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// stw r11,15896(r10)
	PPC_STORE_U32(ctx.r10.u32 + 15896, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292E24"))) PPC_WEAK_FUNC(sub_82292E24);
PPC_FUNC_IMPL(__imp__sub_82292E24) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292E28"))) PPC_WEAK_FUNC(sub_82292E28);
PPC_FUNC_IMPL(__imp__sub_82292E28) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,15896(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 15896);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292E3C"))) PPC_WEAK_FUNC(sub_82292E3C);
PPC_FUNC_IMPL(__imp__sub_82292E3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292E40"))) PPC_WEAK_FUNC(sub_82292E40);
PPC_FUNC_IMPL(__imp__sub_82292E40) {
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
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17892(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17892);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x822b62a0
	ctx.lr = 0x82292E60;
	sub_822B62A0(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226f598
	ctx.lr = 0x82292E74;
	sub_8226F598(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292E84"))) PPC_WEAK_FUNC(sub_82292E84);
PPC_FUNC_IMPL(__imp__sub_82292E84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292E88"))) PPC_WEAK_FUNC(sub_82292E88);
PPC_FUNC_IMPL(__imp__sub_82292E88) {
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
	// bl 0x822928a8
	ctx.lr = 0x82292EA0;
	sub_822928A8(ctx, base);
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
}

__attribute__((alias("__imp__sub_82292EBC"))) PPC_WEAK_FUNC(sub_82292EBC);
PPC_FUNC_IMPL(__imp__sub_82292EBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292EC0"))) PPC_WEAK_FUNC(sub_82292EC0);
PPC_FUNC_IMPL(__imp__sub_82292EC0) {
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
	// b 0x82130588
	sub_82130588(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82292ED4"))) PPC_WEAK_FUNC(sub_82292ED4);
PPC_FUNC_IMPL(__imp__sub_82292ED4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292ED8"))) PPC_WEAK_FUNC(sub_82292ED8);
PPC_FUNC_IMPL(__imp__sub_82292ED8) {
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
	ctx.lr = 0x82292EF4;
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
	ctx.lr = 0x82292F08;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82292F10;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82292F14;
	sub_82481590(ctx, base);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// stw r8,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82292F34"))) PPC_WEAK_FUNC(sub_82292F34);
PPC_FUNC_IMPL(__imp__sub_82292F34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82292F38"))) PPC_WEAK_FUNC(sub_82292F38);
PPC_FUNC_IMPL(__imp__sub_82292F38) {
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
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-12632
	ctx.r6.s64 = ctx.r10.s64 + -12632;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82292F70;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82292f94
	if (cr6.eq) goto loc_82292F94;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x82292F84;
	sub_822577D0(ctx, base);
	// addi r11,r3,-3
	r11.s64 = ctx.r3.s64 + -3;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r11,r10,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x82292f98
	goto loc_82292F98;
loc_82292F94:
	// li r11,0
	r11.s64 = 0;
loc_82292F98:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_82292FB8"))) PPC_WEAK_FUNC(sub_82292FB8);
PPC_FUNC_IMPL(__imp__sub_82292FB8) {
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
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-12632
	ctx.r6.s64 = ctx.r10.s64 + -12632;
	// addi r5,r9,-12656
	ctx.r5.s64 = ctx.r9.s64 + -12656;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x823dedd8
	ctx.lr = 0x82292FF0;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82293010
	if (cr6.eq) goto loc_82293010;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x82293004;
	sub_822577D0(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// b 0x82293014
	goto loc_82293014;
loc_82293010:
	// li r11,0
	r11.s64 = 0;
loc_82293014:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
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

