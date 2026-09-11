#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8227DD28"))) PPC_WEAK_FUNC(sub_8227DD28);
PPC_FUNC_IMPL(__imp__sub_8227DD28) {
	PPC_FUNC_PROLOGUE();
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// b 0x8227dbb8
	sub_8227DBB8(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8227DD30"))) PPC_WEAK_FUNC(sub_8227DD30);
PPC_FUNC_IMPL(__imp__sub_8227DD30) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// bl 0x823d91d0
	ctx.lr = 0x8227DD38;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// li r18,1
	r18.s64 = 1;
	// std r22,0(r23)
	PPC_STORE_U64(r23.u32 + 0, r22.u64);
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// stb r22,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r22.u8);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r18
	r31.u64 = r18.u64;
	// add r20,r4,r9
	r20.u64 = ctx.r4.u64 + ctx.r9.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227DD7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
loc_8227DD84:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227de8c
	if (cr6.eq) goto loc_8227DE8C;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227DDA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x824e8f28
	ctx.lr = 0x8227DDB8;
	sub_824E8F28(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8227de80
	if (!cr6.eq) goto loc_8227DE80;
	// cmplwi cr6,r27,4
	cr6.compare<uint32_t>(r27.u32, 4, xer);
	// bgt cr6,0x8227de08
	if (cr6.gt) goto loc_8227DE08;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-8732
	r12.s64 = r12.s64 + -8732;
	// rlwinm r0,r27,2,0,29
	r0.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r27.u64) {
	case 0:
		goto loc_8227DDF8;
	case 1:
		goto loc_8227DE00;
	case 2:
		goto loc_8227DE00;
	case 3:
		goto loc_8227DE00;
	case 4:
		goto loc_8227DE00;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-8712(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8712);
	// lwz r17,-8704(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8704);
	// lwz r17,-8704(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8704);
	// lwz r17,-8704(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8704);
	// lwz r17,-8704(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -8704);
loc_8227DDF8:
	// li r6,8
	ctx.r6.s64 = 8;
	// b 0x8227de0c
	goto loc_8227DE0C;
loc_8227DE00:
	// li r6,4
	ctx.r6.s64 = 4;
	// b 0x8227de0c
	goto loc_8227DE0C;
loc_8227DE08:
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
loc_8227DE0C:
	// cmplw cr6,r19,r27
	cr6.compare<uint32_t>(r19.u32, r27.u32, xer);
	// bne cr6,0x8227de34
	if (!cr6.eq) goto loc_8227DE34;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8227DE28;
	sub_824E9690(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r31,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r31.u8);
	// b 0x8227de80
	goto loc_8227DE80;
loc_8227DE34:
	// add r30,r6,r28
	r30.u64 = ctx.r6.u64 + r28.u64;
	// cmplw cr6,r30,r20
	cr6.compare<uint32_t>(r30.u32, r20.u32, xer);
	// bgt cr6,0x8227de60
	if (cr6.gt) goto loc_8227DE60;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8227DE50;
	sub_824E9690(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r18
	r11.u64 = r18.u64;
	// bne cr6,0x8227de64
	if (!cr6.eq) goto loc_8227DE64;
loc_8227DE60:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8227DE64:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227de7c
	if (cr6.eq) goto loc_8227DE7C;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// sld r10,r18,r11
	ctx.r10.u64 = r11.u8 & 0x40 ? 0 : (r18.u64 << (r11.u8 & 0x7F));
	// std r10,0(r23)
	PPC_STORE_U64(r23.u32 + 0, ctx.r10.u64);
loc_8227DE7C:
	// mr r28,r30
	r28.u64 = r30.u64;
loc_8227DE80:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpwi cr6,r27,5
	cr6.compare<int32_t>(r27.s32, 5, xer);
	// blt cr6,0x8227dd84
	if (cr6.lt) goto loc_8227DD84;
loc_8227DE8C:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8227DE98"))) PPC_WEAK_FUNC(sub_8227DE98);
PPC_FUNC_IMPL(__imp__sub_8227DE98) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,8
	cr6.compare<uint32_t>(ctx.r5.u32, 8, xer);
	// blt cr6,0x8227def4
	if (cr6.lt) goto loc_8227DEF4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227def4
	if (cr6.eq) goto loc_8227DEF4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227DECC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,292
	ctx.r8.s64 = ctx.r9.s64 + 292;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8227DEF4:
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

__attribute__((alias("__imp__sub_8227DF0C"))) PPC_WEAK_FUNC(sub_8227DF0C);
PPC_FUNC_IMPL(__imp__sub_8227DF0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227DF10"))) PPC_WEAK_FUNC(sub_8227DF10);
PPC_FUNC_IMPL(__imp__sub_8227DF10) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8227DF18;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227DF34;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227DF40;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227DF50;
	sub_82270170(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r29,208(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 208);
	// lfs f1,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x8227DF68;
	sub_82293E30(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x8227DF7C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x8227DF98;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x8227DFB0;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293f28
	ctx.lr = 0x8227DFBC;
	sub_82293F28(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// addi r3,r29,144
	ctx.r3.s64 = r29.s64 + 144;
	// bl 0x82481580
	ctx.lr = 0x8227DFD8;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x8229bd30
	ctx.lr = 0x8227DFEC;
	sub_8229BD30(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// lwz r3,8(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 8);
	// bl 0x8229bcd0
	ctx.lr = 0x8227E000;
	sub_8229BCD0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e030
	if (cr6.eq) goto loc_8227E030;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E014;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227E024;
	sub_82270170(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x8227E030;
	sub_82274128(ctx, base);
loc_8227E030:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E038"))) PPC_WEAK_FUNC(sub_8227E038);
PPC_FUNC_IMPL(__imp__sub_8227E038) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227E05C;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e094
	if (cr6.eq) goto loc_8227E094;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822952b0
	ctx.lr = 0x8227E070;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e094
	if (cr6.eq) goto loc_8227E094;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227E088;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227e098
	if (!cr6.eq) goto loc_8227E098;
loc_8227E094:
	// li r11,0
	r11.s64 = 0;
loc_8227E098:
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

__attribute__((alias("__imp__sub_8227E0B0"))) PPC_WEAK_FUNC(sub_8227E0B0);
PPC_FUNC_IMPL(__imp__sub_8227E0B0) {
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
	ctx.lr = 0x8227E0B8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r30,r11,-2628
	r30.s64 = r11.s64 + -2628;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227E0D8;
	sub_822701C8(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8227e110
	if (!cr6.eq) goto loc_8227E110;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x8227e100
	if (cr6.eq) goto loc_8227E100;
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// li r11,0
	r11.s64 = 0;
	// bne cr6,0x8227e104
	if (!cr6.eq) goto loc_8227E104;
loc_8227E100:
	// li r11,1
	r11.s64 = 1;
loc_8227E104:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
loc_8227E110:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E11C;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822952b0
	ctx.lr = 0x8227E13C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227E154;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x8227E15C;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// bl 0x82389668
	ctx.lr = 0x8227E16C;
	sub_82389668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e1a4
	if (cr6.eq) goto loc_8227E1A4;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,44(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// rlwinm r10,r8,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// lwz r3,4(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x8238eab8
	ctx.lr = 0x8227E19C;
	sub_8238EAB8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227E1A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E1B0"))) PPC_WEAK_FUNC(sub_8227E1B0);
PPC_FUNC_IMPL(__imp__sub_8227E1B0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f31,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = f31.f64;
	// bl 0x82293e30
	ctx.lr = 0x8227E1D8;
	sub_82293E30(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,-2628
	ctx.r4.s64 = ctx.r9.s64 + -2628;
	// lwz r3,-10240(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227E1EC;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e230
	if (cr6.eq) goto loc_8227E230;
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822952b0
	ctx.lr = 0x8227E200;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e230
	if (cr6.eq) goto loc_8227E230;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x8227E21C;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x8227e230
	if (cr6.eq) goto loc_8227E230;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293f60
	ctx.lr = 0x8227E22C;
	sub_82293F60(ctx, base);
	// b 0x8227e234
	goto loc_8227E234;
loc_8227E230:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
loc_8227E234:
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

__attribute__((alias("__imp__sub_8227E24C"))) PPC_WEAK_FUNC(sub_8227E24C);
PPC_FUNC_IMPL(__imp__sub_8227E24C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E250"))) PPC_WEAK_FUNC(sub_8227E250);
PPC_FUNC_IMPL(__imp__sub_8227E250) {
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
	ctx.lr = 0x8227E258;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E270;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e310
	if (cr6.eq) goto loc_8227E310;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x8227E284;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e310
	if (cr6.eq) goto loc_8227E310;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E298;
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
	ctx.lr = 0x8227E2AC;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e310
	if (cr6.eq) goto loc_8227E310;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_8227E2C0:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e304
	if (cr6.eq) goto loc_8227E304;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x8227E2D4;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e304
	if (cr6.eq) goto loc_8227E304;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e304
	if (!cr6.eq) goto loc_8227E304;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227E2F8;
	sub_822577D0(ctx, base);
	// cmplw cr6,r3,r27
	cr6.compare<uint32_t>(ctx.r3.u32, r27.u32, xer);
	// bne cr6,0x8227e304
	if (!cr6.eq) goto loc_8227E304;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_8227E304:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8227e2c0
	if (!cr0.eq) goto loc_8227E2C0;
loc_8227E310:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227E31C"))) PPC_WEAK_FUNC(sub_8227E31C);
PPC_FUNC_IMPL(__imp__sub_8227E31C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E320"))) PPC_WEAK_FUNC(sub_8227E320);
PPC_FUNC_IMPL(__imp__sub_8227E320) {
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
	ctx.lr = 0x8227E328;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// li r28,0
	r28.s64 = 0;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E33C;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e3c8
	if (cr6.eq) goto loc_8227E3C8;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x8227E350;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e3c8
	if (cr6.eq) goto loc_8227E3C8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E364;
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
	ctx.lr = 0x8227E378;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e3c8
	if (cr6.eq) goto loc_8227E3C8;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_8227E38C:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e3bc
	if (cr6.eq) goto loc_8227E3BC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x8227E3A0;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e3bc
	if (cr6.eq) goto loc_8227E3BC;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e3bc
	if (!cr6.eq) goto loc_8227E3BC;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_8227E3BC:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x8227e38c
	if (!cr0.eq) goto loc_8227E38C;
loc_8227E3C8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E3D4"))) PPC_WEAK_FUNC(sub_8227E3D4);
PPC_FUNC_IMPL(__imp__sub_8227E3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E3D8"))) PPC_WEAK_FUNC(sub_8227E3D8);
PPC_FUNC_IMPL(__imp__sub_8227E3D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x8227E3E0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822927f0
	ctx.lr = 0x8227E3EC;
	sub_822927F0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E3F8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227E40C;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8227E414;
	sub_82272A30(ctx, base);
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822701c8
	ctx.lr = 0x8227E42C;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e4a8
	if (cr6.eq) goto loc_8227E4A8;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227e4a8
	if (cr6.eq) goto loc_8227E4A8;
	// lbz r11,12(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e454
	if (cr6.eq) goto loc_8227E454;
loc_8227E448:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8227E454:
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// ble cr6,0x8227e4a8
	if (!cr6.gt) goto loc_8227E4A8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82481590
	ctx.lr = 0x8227E464;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e448
	if (cr6.eq) goto loc_8227E448;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227e320
	ctx.lr = 0x8227E478;
	sub_8227E320(ctx, base);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// bne cr6,0x8227e4a8
	if (!cr6.eq) goto loc_8227E4A8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x8227E488;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e448
	if (cr6.eq) goto loc_8227E448;
	// srawi r11,r29,1
	xer.ca = (r29.s32 < 0) & ((r29.u32 & 0x1) != 0);
	r11.s64 = r29.s32 >> 1;
	// addze r10,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r8,r9,r29
	ctx.r8.s64 = r29.s64 - ctx.r9.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq 0x8227e448
	if (cr0.eq) goto loc_8227E448;
loc_8227E4A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227E4B4"))) PPC_WEAK_FUNC(sub_8227E4B4);
PPC_FUNC_IMPL(__imp__sub_8227E4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E4B8"))) PPC_WEAK_FUNC(sub_8227E4B8);
PPC_FUNC_IMPL(__imp__sub_8227E4B8) {
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
	ctx.lr = 0x8227E4C0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// lwzx r27,r11,r10
	r27.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x821c9790
	ctx.lr = 0x8227E4E8;
	sub_821C9790(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x823896c0
	ctx.lr = 0x8227E4F8;
	sub_823896C0(ctx, base);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x8227e51c
	if (cr6.eq) goto loc_8227E51C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823896c0
	ctx.lr = 0x8227E510;
	sub_823896C0(ctx, base);
	// bl 0x8238eb20
	ctx.lr = 0x8227E514;
	sub_8238EB20(ctx, base);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bne cr6,0x8227e58c
	if (!cr6.eq) goto loc_8227E58C;
loc_8227E51C:
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x8227e52c
	if (cr6.eq) goto loc_8227E52C;
	// cmpw cr6,r28,r26
	cr6.compare<int32_t>(r28.s32, r26.s32, xer);
	// bne cr6,0x8227e58c
	if (!cr6.eq) goto loc_8227E58C;
loc_8227E52C:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82389760
	ctx.lr = 0x8227E538;
	sub_82389760(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e58c
	if (!cr6.eq) goto loc_8227E58C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// bl 0x826bf4b0
	ctx.lr = 0x8227E554;
	sub_826BF4B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,4
	cr6.compare<int32_t>(r26.s32, 4, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,6
	cr6.compare<int32_t>(r26.s32, 6, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,7
	cr6.compare<int32_t>(r26.s32, 7, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// beq cr6,0x8227e58c
	if (cr6.eq) goto loc_8227E58C;
	// cmpwi cr6,r26,-1
	cr6.compare<int32_t>(r26.s32, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227e590
	if (!cr6.eq) goto loc_8227E590;
loc_8227E58C:
	// li r11,0
	r11.s64 = 0;
loc_8227E590:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_8227E59C"))) PPC_WEAK_FUNC(sub_8227E59C);
PPC_FUNC_IMPL(__imp__sub_8227E59C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E5A0"))) PPC_WEAK_FUNC(sub_8227E5A0);
PPC_FUNC_IMPL(__imp__sub_8227E5A0) {
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
	ctx.lr = 0x8227E5A8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8227E5B8;
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
	ctx.lr = 0x8227E5CC;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e654
	if (cr6.eq) goto loc_8227E654;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8227E5E0:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e644
	if (cr6.eq) goto loc_8227E644;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e620
	if (cr6.eq) goto loc_8227E620;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e618
	if (!cr6.eq) goto loc_8227E618;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227E60C;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e620
	if (cr6.eq) goto loc_8227E620;
loc_8227E618:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227e624
	goto loc_8227E624;
loc_8227E620:
	// li r11,0
	r11.s64 = 0;
loc_8227E624:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e644
	if (cr6.eq) goto loc_8227E644;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8227E63C;
	sub_822051A0(ctx, base);
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// beq cr6,0x8227e660
	if (cr6.eq) goto loc_8227E660;
loc_8227E644:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x8227e5e0
	if (!cr6.eq) goto loc_8227E5E0;
loc_8227E654:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227E660:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E66C"))) PPC_WEAK_FUNC(sub_8227E66C);
PPC_FUNC_IMPL(__imp__sub_8227E66C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E670"))) PPC_WEAK_FUNC(sub_8227E670);
PPC_FUNC_IMPL(__imp__sub_8227E670) {
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
	ctx.lr = 0x8227E678;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8227E688;
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
	ctx.lr = 0x8227E69C;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e72c
	if (cr6.eq) goto loc_8227E72C;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8227E6B0:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e71c
	if (cr6.eq) goto loc_8227E71C;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e6f0
	if (cr6.eq) goto loc_8227E6F0;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e6e8
	if (!cr6.eq) goto loc_8227E6E8;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227E6DC;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e6f0
	if (cr6.eq) goto loc_8227E6F0;
loc_8227E6E8:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227e6f4
	goto loc_8227E6F4;
loc_8227E6F0:
	// li r11,0
	r11.s64 = 0;
loc_8227E6F4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e71c
	if (cr6.eq) goto loc_8227E71C;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x8227E708;
	sub_82502300(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x824f0550
	ctx.lr = 0x8227E710;
	sub_824F0550(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227e738
	if (!cr6.eq) goto loc_8227E738;
loc_8227E71C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x8227e6b0
	if (!cr6.eq) goto loc_8227E6B0;
loc_8227E72C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8227E738:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8227E744;
	sub_822051A0(ctx, base);
	// bl 0x822a5948
	ctx.lr = 0x8227E748;
	sub_822A5948(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227E750"))) PPC_WEAK_FUNC(sub_8227E750);
PPC_FUNC_IMPL(__imp__sub_8227E750) {
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
	// bl 0x8226be68
	ctx.lr = 0x8227E76C;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e7dc
	if (cr6.eq) goto loc_8227E7DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E780;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227E790;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8227E798;
	sub_82272A30(ctx, base);
	// bl 0x82481688
	ctx.lr = 0x8227E79C;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e7dc
	if (cr6.eq) goto loc_8227E7DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E7B0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227E7C0;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8227E7C8;
	sub_82272A30(ctx, base);
	// bl 0x82481608
	ctx.lr = 0x8227E7CC;
	sub_82481608(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227e7e0
	if (cr6.eq) goto loc_8227E7E0;
loc_8227E7DC:
	// li r11,0
	r11.s64 = 0;
loc_8227E7E0:
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

__attribute__((alias("__imp__sub_8227E7F8"))) PPC_WEAK_FUNC(sub_8227E7F8);
PPC_FUNC_IMPL(__imp__sub_8227E7F8) {
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
	ctx.lr = 0x8227E824;
	sub_822701C8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-3624(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227E834;
	sub_8226BE68(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8227e8a4
	if (cr6.eq) goto loc_8227E8A4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227e8a4
	if (cr6.eq) goto loc_8227E8A4;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x8227E854;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e8a4
	if (cr6.eq) goto loc_8227E8A4;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227E86C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227e8a4
	if (!cr6.eq) goto loc_8227E8A4;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8227e8a4
	if (cr6.eq) goto loc_8227E8A4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,32(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r30.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x8227e8a4
	if (!cr6.eq) goto loc_8227E8A4;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x8227e8a8
	if (cr6.eq) goto loc_8227E8A8;
loc_8227E8A4:
	// li r11,0
	r11.s64 = 0;
loc_8227E8A8:
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

__attribute__((alias("__imp__sub_8227E8C4"))) PPC_WEAK_FUNC(sub_8227E8C4);
PPC_FUNC_IMPL(__imp__sub_8227E8C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227E8C8"))) PPC_WEAK_FUNC(sub_8227E8C8);
PPC_FUNC_IMPL(__imp__sub_8227E8C8) {
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
	ctx.lr = 0x8227E8D0;
	// stwu r1,-656(r1)
	ea = -656 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x8227ea0c
	if (cr6.eq) goto loc_8227EA0C;
	// addi r29,r4,144
	r29.s64 = ctx.r4.s64 + 144;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8227ea0c
	if (cr6.eq) goto loc_8227EA0C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x8227E8F0;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ea0c
	if (cr6.eq) goto loc_8227EA0C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82481688
	ctx.lr = 0x8227E904;
	sub_82481688(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227e9ec
	if (cr6.eq) goto loc_8227E9EC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E918;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227E928;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x8227E934;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E93C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227E94C;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x8227E954;
	sub_824E7110(ctx, base);
	// bl 0x824f92f0
	ctx.lr = 0x8227E958;
	sub_824F92F0(ctx, base);
	// std r3,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r3.u64);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824817c0
	ctx.lr = 0x8227E964;
	sub_824817C0(ctx, base);
	// addi r4,r3,12
	ctx.r4.s64 = ctx.r3.s64 + 12;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ea3b8
	ctx.lr = 0x8227E970;
	sub_824EA3B8(ctx, base);
	// lis r4,8192
	ctx.r4.s64 = 536870912;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ori r4,r4,53
	ctx.r4.u64 = ctx.r4.u64 | 53;
	// bl 0x824e9038
	ctx.lr = 0x8227E980;
	sub_824E9038(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824e9740
	ctx.lr = 0x8227E990;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,8
	cr6.compare<uint32_t>(ctx.r3.u32, 8, xer);
	// bne cr6,0x8227e9ec
	if (!cr6.eq) goto loc_8227E9EC;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9530
	ctx.lr = 0x8227E9AC;
	sub_824E9530(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227E9B4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227E9C4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x8227E9CC;
	sub_821F8730(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x824e9240
	ctx.lr = 0x8227E9DC;
	sub_824E9240(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82486800
	ctx.lr = 0x8227E9EC;
	sub_82486800(ctx, base);
loc_8227E9EC:
	// lbz r11,80(r1)
	r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// clrlwi r9,r11,28
	ctx.r9.u64 = r11.u32 & 0xF;
	// ori r8,r9,112
	ctx.r8.u64 = ctx.r9.u64 | 112;
	// lwz r3,-10012(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10012);
	// stb r8,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
	// bl 0x826d5a18
	ctx.lr = 0x8227EA0C;
	sub_826D5A18(ctx, base);
loc_8227EA0C:
	// addi r1,r1,656
	ctx.r1.s64 = ctx.r1.s64 + 656;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227EA14"))) PPC_WEAK_FUNC(sub_8227EA14);
PPC_FUNC_IMPL(__imp__sub_8227EA14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227EA18"))) PPC_WEAK_FUNC(sub_8227EA18);
PPC_FUNC_IMPL(__imp__sub_8227EA18) {
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
	ctx.lr = 0x8227EA20;
	// stwu r1,-1168(r1)
	ea = -1168 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x8227EA30;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227EA40;
	sub_82270170(ctx, base);
	// lwz r11,296(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x8227EA5C;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227eba4
	if (!cr6.eq) goto loc_8227EBA4;
	// cmplwi cr6,r30,1
	cr6.compare<uint32_t>(r30.u32, 1, xer);
	// blt cr6,0x8227eaf8
	if (cr6.lt) goto loc_8227EAF8;
	// bne cr6,0x8227eba4
	if (!cr6.eq) goto loc_8227EBA4;
	// lbz r9,592(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 592);
	// li r11,0
	r11.s64 = 0;
	// lwz r30,-10240(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// std r11,84(r1)
	PPC_STORE_U64(ctx.r1.u32 + 84, r11.u64);
	// stb r8,592(r1)
	PPC_STORE_U8(ctx.r1.u32 + 592, ctx.r8.u8);
	// bl 0x82388598
	ctx.lr = 0x8227EA90;
	sub_82388598(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82270170
	ctx.lr = 0x8227EA9C;
	sub_82270170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// addi r29,r30,16
	r29.s64 = r30.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EAB4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EAC8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r7,r30,296
	ctx.r7.s64 = r30.s64 + 296;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// bl 0x824e7b20
	ctx.lr = 0x8227EAF0;
	sub_824E7B20(ctx, base);
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d924c
	return;
loc_8227EAF8:
	// lbz r9,1120(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1120);
	// li r11,0
	r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,-10240(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, r11.u32);
	// std r11,612(r1)
	PPC_STORE_U64(ctx.r1.u32 + 612, r11.u64);
	// stb r8,1120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1120, ctx.r8.u8);
	// bl 0x82388598
	ctx.lr = 0x8227EB1C;
	sub_82388598(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82270170
	ctx.lr = 0x8227EB28;
	sub_82270170(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// addi r30,r29,16
	r30.s64 = r29.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EB40;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EB54;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EB68;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EB7C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227eba4
	if (cr6.eq) goto loc_8227EBA4;
	// lwz r11,-10240(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r7,r29,296
	ctx.r7.s64 = r29.s64 + 296;
	// addi r6,r1,608
	ctx.r6.s64 = ctx.r1.s64 + 608;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// bl 0x824e7b20
	ctx.lr = 0x8227EBA4;
	sub_824E7B20(ctx, base);
loc_8227EBA4:
	// addi r1,r1,1168
	ctx.r1.s64 = ctx.r1.s64 + 1168;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227EBAC"))) PPC_WEAK_FUNC(sub_8227EBAC);
PPC_FUNC_IMPL(__imp__sub_8227EBAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227EBB0"))) PPC_WEAK_FUNC(sub_8227EBB0);
PPC_FUNC_IMPL(__imp__sub_8227EBB0) {
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
	ctx.lr = 0x8227EBB8;
	// stwu r1,-3808(r1)
	ea = -3808 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227EBC4;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227EBD4;
	sub_82270170(ctx, base);
	// lwz r11,296(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 296);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x8227EBF0;
	sub_822701C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227EBFC;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227EC0C;
	sub_82270170(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227EC1C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x8227eff0
	if (cr6.lt) goto loc_8227EFF0;
	// beq cr6,0x8227ee10
	if (cr6.eq) goto loc_8227EE10;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bge cr6,0x8227f094
	if (!cr6.lt) goto loc_8227F094;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227EC3C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227ecc4
	if (!cr6.eq) goto loc_8227ECC4;
	// lbz r9,1120(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1120);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, r11.u32);
	// std r11,612(r1)
	PPC_STORE_U64(ctx.r1.u32 + 612, r11.u64);
	// stb r8,1120(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1120, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EC70;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EC84;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EC98;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227ECAC;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,608
	ctx.r6.s64 = ctx.r1.s64 + 608;
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227ECC4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8227ed70
	if (!cr6.eq) goto loc_8227ED70;
	// bl 0x822577d0
	ctx.lr = 0x8227ECE8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// lbz r9,3232(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 3232);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,2720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2720, r11.u32);
	// std r11,2724(r1)
	PPC_STORE_U64(ctx.r1.u32 + 2724, r11.u64);
	// stb r8,3232(r1)
	PPC_STORE_U8(ctx.r1.u32 + 3232, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227ED1C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227ED30;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227ED44;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227ED58;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,2720
	ctx.r6.s64 = ctx.r1.s64 + 2720;
	// li r5,8
	ctx.r5.s64 = 8;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227ED70:
	// bl 0x822577d0
	ctx.lr = 0x8227ED74;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227ED88;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x8227f094
	if (!cr6.eq) goto loc_8227F094;
	// lbz r9,2176(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 2176);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,1664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1664, r11.u32);
	// std r11,1668(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1668, r11.u64);
	// stb r8,2176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 2176, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EDBC;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EDD0;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EDE4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EDF8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,1664
	ctx.r6.s64 = ctx.r1.s64 + 1664;
	// li r5,7
	ctx.r5.s64 = 7;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227EE10:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227EE1C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227eea4
	if (!cr6.eq) goto loc_8227EEA4;
	// lbz r9,592(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 592);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// std r11,84(r1)
	PPC_STORE_U64(ctx.r1.u32 + 84, r11.u64);
	// stb r8,592(r1)
	PPC_STORE_U8(ctx.r1.u32 + 592, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EE50;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EE64;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EE78;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EE8C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,6
	ctx.r5.s64 = 6;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227EEA4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8227ef50
	if (!cr6.eq) goto loc_8227EF50;
	// bl 0x822577d0
	ctx.lr = 0x8227EEC8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// lbz r9,1648(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1648);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,1136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1136, r11.u32);
	// std r11,1140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 1140, r11.u64);
	// stb r8,1648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1648, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EEFC;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EF10;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EF24;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EF38;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,1136
	ctx.r6.s64 = ctx.r1.s64 + 1136;
	// li r5,4
	ctx.r5.s64 = 4;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227EF50:
	// bl 0x822577d0
	ctx.lr = 0x8227EF54;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x8227EF68;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x8227f094
	if (!cr6.eq) goto loc_8227F094;
	// lbz r9,2704(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 2704);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,2192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2192, r11.u32);
	// std r11,2196(r1)
	PPC_STORE_U64(ctx.r1.u32 + 2196, r11.u64);
	// stb r8,2704(r1)
	PPC_STORE_U8(ctx.r1.u32 + 2704, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EF9C;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EFB0;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227EFC4;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227EFD8;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,2192
	ctx.r6.s64 = ctx.r1.s64 + 2192;
	// li r5,5
	ctx.r5.s64 = 5;
	// b 0x8227f080
	goto loc_8227F080;
loc_8227EFF0:
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227EFFC;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x8227f094
	if (!cr6.eq) goto loc_8227F094;
	// lbz r9,3760(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 3760);
	// li r11,0
	r11.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r11,3248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 3248, r11.u32);
	// std r11,3252(r1)
	PPC_STORE_U64(ctx.r1.u32 + 3252, r11.u64);
	// stb r8,3760(r1)
	PPC_STORE_U8(ctx.r1.u32 + 3760, ctx.r8.u8);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r30,r31,16
	r30.s64 = r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227F030;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227F044;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70e0
	ctx.lr = 0x8227F058;
	sub_824E70E0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e70f0
	ctx.lr = 0x8227F06C;
	sub_824E70F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f094
	if (cr6.eq) goto loc_8227F094;
	// addi r6,r1,3248
	ctx.r6.s64 = ctx.r1.s64 + 3248;
	// li r5,3
	ctx.r5.s64 = 3;
loc_8227F080:
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// addi r7,r31,296
	ctx.r7.s64 = r31.s64 + 296;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r11,1184
	ctx.r3.s64 = r11.s64 + 1184;
	// bl 0x824e7b20
	ctx.lr = 0x8227F094;
	sub_824E7B20(ctx, base);
loc_8227F094:
	// addi r1,r1,3808
	ctx.r1.s64 = ctx.r1.s64 + 3808;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227F09C"))) PPC_WEAK_FUNC(sub_8227F09C);
PPC_FUNC_IMPL(__imp__sub_8227F09C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227F0A0"))) PPC_WEAK_FUNC(sub_8227F0A0);
PPC_FUNC_IMPL(__imp__sub_8227F0A0) {
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
	ctx.lr = 0x8227F0A8;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x8227F0C0;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227f2c0
	if (cr6.eq) goto loc_8227F2C0;
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// blt cr6,0x8227f0f4
	if (cr6.lt) goto loc_8227F0F4;
	// bne cr6,0x8227f2c0
	if (!cr6.eq) goto loc_8227F2C0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,28
	ctx.r4.s64 = 28;
	// bl 0x8268ee10
	ctx.lr = 0x8227F0EC;
	sub_8268EE10(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
loc_8227F0F4:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,2
	r11.s64 = 2;
	// beq cr6,0x8227f108
	if (cr6.eq) goto loc_8227F108;
	// li r11,-1
	r11.s64 = -1;
loc_8227F108:
	// stw r11,24(r29)
	PPC_STORE_U32(r29.u32 + 24, r11.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e750
	ctx.lr = 0x8227F114;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227f148
	if (!cr6.eq) goto loc_8227F148;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F12C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227F13C;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8227F148;
	sub_82274128(ctx, base);
loc_8227F148:
	// lwz r11,24(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8227f168
	if (!cr6.eq) goto loc_8227F168;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,26
	ctx.r4.s64 = 26;
	// bl 0x8268ee10
	ctx.lr = 0x8227F168;
	sub_8268EE10(ctx, base);
loc_8227F168:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r3,r11,-1992
	ctx.r3.s64 = r11.s64 + -1992;
	// addi r31,r10,-11404
	r31.s64 = ctx.r10.s64 + -11404;
	// addi r28,r9,-22108
	r28.s64 = ctx.r9.s64 + -22108;
	// bl 0x821fa230
	ctx.lr = 0x8227F184;
	sub_821FA230(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x8227F198;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r7,92(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 92);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8227F1AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8227f1cc
	if (cr6.eq) goto loc_8227F1CC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227F1CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8227F1CC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e750
	ctx.lr = 0x8227F1D4;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f2c0
	if (cr6.eq) goto loc_8227F2C0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r31,r11,-2628
	r31.s64 = r11.s64 + -2628;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822701c8
	ctx.lr = 0x8227F1F4;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f2c0
	if (cr6.eq) goto loc_8227F2C0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8227F208;
	sub_822701C8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x82295f70
	ctx.lr = 0x8227F214;
	sub_82295F70(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// lbz r7,86(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 86);
	// li r10,255
	ctx.r10.s64 = 255;
	// stb r11,85(r1)
	PPC_STORE_U8(ctx.r1.u32 + 85, r11.u8);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r28,r1,80
	r28.s64 = ctx.r1.s64 + 80;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r11.u32);
	// stb r11,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, r11.u8);
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// ori r11,r7,128
	r11.u64 = ctx.r7.u64 | 128;
	// lbz r5,81(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 84);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// ori r8,r5,224
	ctx.r8.u64 = ctx.r5.u64 | 224;
	// clrlwi r10,r6,25
	ctx.r10.u64 = ctx.r6.u32 & 0x7F;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// ori r7,r9,64
	ctx.r7.u64 = ctx.r9.u64 | 64;
	// stb r8,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, ctx.r8.u8);
	// stb r10,84(r1)
	PPC_STORE_U8(ctx.r1.u32 + 84, ctx.r10.u8);
	// stb r7,86(r1)
	PPC_STORE_U8(ctx.r1.u32 + 86, ctx.r7.u8);
	// bl 0x822701c8
	ctx.lr = 0x8227F278;
	sub_822701C8(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82295538
	ctx.lr = 0x8227F284;
	sub_82295538(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82397458
	ctx.lr = 0x8227F28C;
	sub_82397458(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x8227f2c0
	if (cr6.eq) goto loc_8227F2C0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r30,-10240(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x8227e320
	ctx.lr = 0x8227F2A4;
	sub_8227E320(ctx, base);
	// addi r29,r3,-1
	r29.s64 = ctx.r3.s64 + -1;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822701c8
	ctx.lr = 0x8227F2B4;
	sub_822701C8(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82295d70
	ctx.lr = 0x8227F2C0;
	sub_82295D70(ctx, base);
loc_8227F2C0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227F2C8"))) PPC_WEAK_FUNC(sub_8227F2C8);
PPC_FUNC_IMPL(__imp__sub_8227F2C8) {
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
	ctx.lr = 0x8227F2D0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F2E0;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x8227F2F0;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8227F2FC;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F304;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227F314;
	sub_82270170(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8227F320;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F328;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227F338;
	sub_82270170(ctx, base);
	// li r4,10
	ctx.r4.s64 = 10;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x8227F344;
	sub_82274120(ctx, base);
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x8229bd58
	ctx.lr = 0x8227F34C;
	sub_8229BD58(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F354;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8227F364;
	sub_82270170(ctx, base);
	// lwz r29,208(r3)
	r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r29,144
	ctx.r3.s64 = r29.s64 + 144;
	// bl 0x82481580
	ctx.lr = 0x8227F370;
	sub_82481580(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x8227f388
	if (!cr6.eq) goto loc_8227F388;
	// lwz r11,11784(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11784);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// bne cr6,0x8227f39c
	if (!cr6.eq) goto loc_8227F39C;
loc_8227F388:
	// lwz r11,11792(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 11792);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// beq cr6,0x8227f39c
	if (cr6.eq) goto loc_8227F39C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82297638
	ctx.lr = 0x8227F39C;
	sub_82297638(ctx, base);
loc_8227F39C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x8227F3AC;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227e750
	ctx.lr = 0x8227F3B8;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8227f3f8
	if (cr6.eq) goto loc_8227F3F8;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227f3f8
	if (cr6.eq) goto loc_8227F3F8;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8227f3e8
	if (!cr6.eq) goto loc_8227F3E8;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x8227F3E8;
	sub_82295F70(ctx, base);
loc_8227F3E8:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x8227F3F8;
	sub_82295F70(ctx, base);
loc_8227F3F8:
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8227f418
	if (!cr6.eq) goto loc_8227F418;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,27
	ctx.r4.s64 = 27;
	// bl 0x8268ee10
	ctx.lr = 0x8227F418;
	sub_8268EE10(ctx, base);
loc_8227F418:
	// li r11,-1
	r11.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,24(r30)
	PPC_STORE_U32(r30.u32 + 24, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,40(r30)
	PPC_STORE_U32(r30.u32 + 40, r11.u32);
	// bl 0x821e6828
	ctx.lr = 0x8227F430;
	sub_821E6828(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227F438"))) PPC_WEAK_FUNC(sub_8227F438);
PPC_FUNC_IMPL(__imp__sub_8227F438) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x8227F440;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,0(r13)
	r26.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// li r25,72
	r25.s64 = 72;
	// li r24,0
	r24.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// li r29,8
	r29.s64 = 8;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_8227F464:
	// lbzx r11,r25,r26
	r11.u64 = PPC_LOAD_U8(r25.u32 + r26.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f498
	if (cr6.eq) goto loc_8227F498;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8227f4c4
	if (cr6.lt) goto loc_8227F4C4;
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x8227f4c4
	if (!cr6.lt) goto loc_8227F4C4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// b 0x8227f4b8
	goto loc_8227F4B8;
loc_8227F498:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x8227f4c4
	if (cr6.lt) goto loc_8227F4C4;
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x8227f4c4
	if (!cr6.lt) goto loc_8227F4C4;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
loc_8227F4B8:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8227f4c8
	if (!cr6.eq) goto loc_8227F4C8;
loc_8227F4C4:
	// li r11,0
	r11.s64 = 0;
loc_8227F4C8:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f4e4
	if (cr6.eq) goto loc_8227F4E4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a5948
	ctx.lr = 0x8227F4DC;
	sub_822A5948(ctx, base);
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x8227f4e8
	goto loc_8227F4E8;
loc_8227F4E4:
	// li r31,0
	r31.s64 = 0;
loc_8227F4E8:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227f56c
	if (cr6.eq) goto loc_8227F56C;
	// lwz r11,16(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8227f510
	if (!cr6.eq) goto loc_8227F510;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227F508;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f56c
	if (cr6.eq) goto loc_8227F56C;
loc_8227F510:
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f544
	if (cr6.eq) goto loc_8227F544;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227f53c
	if (!cr6.eq) goto loc_8227F53C;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x8227F530;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f544
	if (cr6.eq) goto loc_8227F544;
loc_8227F53C:
	// li r11,1
	r11.s64 = 1;
	// b 0x8227f548
	goto loc_8227F548;
loc_8227F544:
	// li r11,0
	r11.s64 = 0;
loc_8227F548:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f56c
	if (cr6.eq) goto loc_8227F56C;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227F560;
	sub_822577D0(ctx, base);
	// cmplw cr6,r3,r27
	cr6.compare<uint32_t>(ctx.r3.u32, r27.u32, xer);
	// bne cr6,0x8227f56c
	if (!cr6.eq) goto loc_8227F56C;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
loc_8227F56C:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r29,132
	cr6.compare<int32_t>(r29.s32, 132, xer);
	// bne cr6,0x8227f464
	if (!cr6.eq) goto loc_8227F464;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_8227F588"))) PPC_WEAK_FUNC(sub_8227F588);
PPC_FUNC_IMPL(__imp__sub_8227F588) {
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
	// bl 0x8227e0b0
	ctx.lr = 0x8227F5A0;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f5d8
	if (cr6.eq) goto loc_8227F5D8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-5052(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -5052);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f5d8
	if (cr6.eq) goto loc_8227F5D8;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82257160
	ctx.lr = 0x8227F5C4;
	sub_82257160(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_8227F5D8:
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

__attribute__((alias("__imp__sub_8227F5F0"))) PPC_WEAK_FUNC(sub_8227F5F0);
PPC_FUNC_IMPL(__imp__sub_8227F5F0) {
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
	ctx.lr = 0x8227F5F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8227F604;
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
	ctx.lr = 0x8227F618;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f690
	if (cr6.eq) goto loc_8227F690;
	// li r29,0
	r29.s64 = 0;
	// addi r30,r11,12
	r30.s64 = r11.s64 + 12;
loc_8227F62C:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227f680
	if (cr6.eq) goto loc_8227F680;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8227f680
	if (!cr6.eq) goto loc_8227F680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x8227F64C;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227f680
	if (cr6.eq) goto loc_8227F680;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227F664;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f680
	if (cr6.eq) goto loc_8227F680;
	// li r4,12
	ctx.r4.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x8227F678;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8227f6ec
	if (cr6.eq) goto loc_8227F6EC;
loc_8227F680:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x8227f62c
	if (!cr6.eq) goto loc_8227F62C;
loc_8227F690:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,444
	ctx.r3.s64 = r11.s64 + 444;
	// bl 0x821fa230
	ctx.lr = 0x8227F69C;
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
	ctx.lr = 0x8227F6B0;
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
	ctx.lr = 0x8227F6C8;
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
	ctx.lr = 0x8227F6E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_8227F6EC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_8227F6F8"))) PPC_WEAK_FUNC(sub_8227F6F8);
PPC_FUNC_IMPL(__imp__sub_8227F6F8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8227F700;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227f744
	if (cr6.gt) goto loc_8227F744;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-2252
	r12.s64 = r12.s64 + -2252;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227F74C;
	case 1:
		goto loc_8227F74C;
	case 2:
		goto loc_8227F74C;
	case 3:
		goto loc_8227F74C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-2228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2228);
	// lwz r17,-2228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2228);
	// lwz r17,-2228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2228);
	// lwz r17,-2228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2228);
loc_8227F744:
	// li r31,-1
	r31.s64 = -1;
	// b 0x8227f750
	goto loc_8227F750;
loc_8227F74C:
	// li r31,3
	r31.s64 = 3;
loc_8227F750:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227F760;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8227f808
	if (cr6.gt) goto loc_8227F808;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-2176
	r12.s64 = r12.s64 + -2176;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8227F790;
	case 1:
		goto loc_8227F7B0;
	case 2:
		goto loc_8227F7D0;
	case 3:
		goto loc_8227F7F0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-2160(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2160);
	// lwz r17,-2128(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2128);
	// lwz r17,-2096(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2096);
	// lwz r17,-2064(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -2064);
loc_8227F790:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d7a0
	ctx.lr = 0x8227F7A4;
	sub_8227D7A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F7B0:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d838
	ctx.lr = 0x8227F7C4;
	sub_8227D838(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F7D0:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d8d0
	ctx.lr = 0x8227F7E4;
	sub_8227D8D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F7F0:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229cb20
	ctx.lr = 0x8227F804;
	sub_8229CB20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8227F808:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227F814"))) PPC_WEAK_FUNC(sub_8227F814);
PPC_FUNC_IMPL(__imp__sub_8227F814) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227F818"))) PPC_WEAK_FUNC(sub_8227F818);
PPC_FUNC_IMPL(__imp__sub_8227F818) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227F844;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x8227f868
	if (!cr6.eq) goto loc_8227F868;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227f868
	if (cr6.eq) goto loc_8227F868;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,212
	ctx.r10.s64 = r11.s64 + 212;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x8227f86c
	goto loc_8227F86C;
loc_8227F868:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227F86C:
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

__attribute__((alias("__imp__sub_8227F884"))) PPC_WEAK_FUNC(sub_8227F884);
PPC_FUNC_IMPL(__imp__sub_8227F884) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227F888"))) PPC_WEAK_FUNC(sub_8227F888);
PPC_FUNC_IMPL(__imp__sub_8227F888) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8227F890;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r4,4
	cr6.compare<uint32_t>(ctx.r4.u32, 4, xer);
	// bgt cr6,0x8227f8d8
	if (cr6.gt) goto loc_8227F8D8;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1852
	r12.s64 = r12.s64 + -1852;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227F8E0;
	case 1:
		goto loc_8227F8E0;
	case 2:
		goto loc_8227F8E0;
	case 3:
		goto loc_8227F8E0;
	case 4:
		goto loc_8227F8E0;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
	// lwz r17,-1824(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1824);
loc_8227F8D8:
	// li r31,-1
	r31.s64 = -1;
	// b 0x8227f8e4
	goto loc_8227F8E4;
loc_8227F8E0:
	// li r31,3
	r31.s64 = 3;
loc_8227F8E4:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227F8F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8227f99c
	if (cr6.gt) goto loc_8227F99C;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1772
	r12.s64 = r12.s64 + -1772;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8227F924;
	case 1:
		goto loc_8227F944;
	case 2:
		goto loc_8227F964;
	case 3:
		goto loc_8227F984;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1756(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1756);
	// lwz r17,-1724(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1724);
	// lwz r17,-1692(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1692);
	// lwz r17,-1660(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1660);
loc_8227F924:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d7a0
	ctx.lr = 0x8227F938;
	sub_8227D7A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F944:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d838
	ctx.lr = 0x8227F958;
	sub_8227D838(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F964:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d8d0
	ctx.lr = 0x8227F978;
	sub_8227D8D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227F984:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229cb20
	ctx.lr = 0x8227F998;
	sub_8229CB20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8227F99C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227F9A8"))) PPC_WEAK_FUNC(sub_8227F9A8);
PPC_FUNC_IMPL(__imp__sub_8227F9A8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// bge cr6,0x8227f9c4
	if (!cr6.lt) goto loc_8227F9C4;
	// lwz r10,12(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// mulli r11,r4,568
	r11.s64 = ctx.r4.s64 * 568;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
loc_8227F9C4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227F9CC"))) PPC_WEAK_FUNC(sub_8227F9CC);
PPC_FUNC_IMPL(__imp__sub_8227F9CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227F9D0"))) PPC_WEAK_FUNC(sub_8227F9D0);
PPC_FUNC_IMPL(__imp__sub_8227F9D0) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227F9FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x8227fa20
	if (!cr6.eq) goto loc_8227FA20;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227fa20
	if (cr6.eq) goto loc_8227FA20;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,372
	ctx.r10.s64 = r11.s64 + 372;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x8227fa24
	goto loc_8227FA24;
loc_8227FA20:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8227FA24:
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

__attribute__((alias("__imp__sub_8227FA3C"))) PPC_WEAK_FUNC(sub_8227FA3C);
PPC_FUNC_IMPL(__imp__sub_8227FA3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FA40"))) PPC_WEAK_FUNC(sub_8227FA40);
PPC_FUNC_IMPL(__imp__sub_8227FA40) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x8227FA48;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// bgt cr6,0x8227faac
	if (cr6.gt) goto loc_8227FAAC;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1412
	r12.s64 = r12.s64 + -1412;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		goto loc_8227FA8C;
	case 1:
		goto loc_8227FA94;
	case 2:
		goto loc_8227FA9C;
	case 3:
		goto loc_8227FAA4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1396(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1396);
	// lwz r17,-1388(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1388);
	// lwz r17,-1380(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1380);
	// lwz r17,-1372(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1372);
loc_8227FA8C:
	// li r11,61
	r11.s64 = 61;
	// b 0x8227fab0
	goto loc_8227FAB0;
loc_8227FA94:
	// li r11,62
	r11.s64 = 62;
	// b 0x8227fab0
	goto loc_8227FAB0;
loc_8227FA9C:
	// li r11,63
	r11.s64 = 63;
	// b 0x8227fab0
	goto loc_8227FAB0;
loc_8227FAA4:
	// li r11,64
	r11.s64 = 64;
	// b 0x8227fab0
	goto loc_8227FAB0;
loc_8227FAAC:
	// li r11,-1
	r11.s64 = -1;
loc_8227FAB0:
	// addi r11,r11,-61
	r11.s64 = r11.s64 + -61;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x8227faf4
	if (cr6.gt) goto loc_8227FAF4;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1324
	r12.s64 = r12.s64 + -1324;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_8227FAE4;
	case 1:
		goto loc_8227FAEC;
	case 2:
		goto loc_8227FAE4;
	case 3:
		goto loc_8227FAE4;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1308(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1308);
	// lwz r17,-1300(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1300);
	// lwz r17,-1308(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1308);
	// lwz r17,-1308(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1308);
loc_8227FAE4:
	// li r31,2
	r31.s64 = 2;
	// b 0x8227faf8
	goto loc_8227FAF8;
loc_8227FAEC:
	// li r31,3
	r31.s64 = 3;
	// b 0x8227faf8
	goto loc_8227FAF8;
loc_8227FAF4:
	// li r31,-1
	r31.s64 = -1;
loc_8227FAF8:
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227FB08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bgt cr6,0x8227fbb0
	if (cr6.gt) goto loc_8227FBB0;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-1240
	r12.s64 = r12.s64 + -1240;
	// rlwinm r0,r3,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r3.u64) {
	case 0:
		goto loc_8227FB38;
	case 1:
		goto loc_8227FB58;
	case 2:
		goto loc_8227FB78;
	case 3:
		goto loc_8227FB98;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-1224(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1224);
	// lwz r17,-1192(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1192);
	// lwz r17,-1160(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1160);
	// lwz r17,-1128(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -1128);
loc_8227FB38:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d7a0
	ctx.lr = 0x8227FB4C;
	sub_8227D7A0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227FB58:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d838
	ctx.lr = 0x8227FB6C;
	sub_8227D838(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227FB78:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227d8d0
	ctx.lr = 0x8227FB8C;
	sub_8227D8D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_8227FB98:
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8229cb20
	ctx.lr = 0x8227FBAC;
	sub_8229CB20(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
loc_8227FBB0:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227FBBC"))) PPC_WEAK_FUNC(sub_8227FBBC);
PPC_FUNC_IMPL(__imp__sub_8227FBBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FBC0"))) PPC_WEAK_FUNC(sub_8227FBC0);
PPC_FUNC_IMPL(__imp__sub_8227FBC0) {
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
	ctx.lr = 0x8227FBC8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8227FBE4;
	sub_821C8FE0(ctx, base);
	// addi r11,r30,187
	r11.s64 = r30.s64 + 187;
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r29,r11,2,0,29
	r29.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r10.u32);
	// lbz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227fc84
	if (cr6.eq) goto loc_8227FC84;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295510
	ctx.lr = 0x8227FC0C;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8227fc84
	if (!cr6.eq) goto loc_8227FC84;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8227FC1C;
	sub_82618750(ctx, base);
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r27,r10,r31
	r27.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x822954b8
	ctx.lr = 0x8227FC34;
	sub_822954B8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,6
	ctx.r4.s64 = r31.s64 + 6;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// bl 0x82618610
	ctx.lr = 0x8227FC48;
	sub_82618610(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822559f0
	ctx.lr = 0x8227FC54;
	sub_822559F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227fc84
	if (cr6.eq) goto loc_8227FC84;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618698
	ctx.lr = 0x8227FC68;
	sub_82618698(ctx, base);
	// stwx r3,r29,r31
	PPC_STORE_U32(r29.u32 + r31.u32, ctx.r3.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822951d0
	ctx.lr = 0x8227FC78;
	sub_822951D0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295930
	ctx.lr = 0x8227FC84;
	sub_82295930(ctx, base);
loc_8227FC84:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r31,r29,r31
	r31.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// bl 0x821c9030
	ctx.lr = 0x8227FC90;
	sub_821C9030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8227FC9C"))) PPC_WEAK_FUNC(sub_8227FC9C);
PPC_FUNC_IMPL(__imp__sub_8227FC9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FCA0"))) PPC_WEAK_FUNC(sub_8227FCA0);
PPC_FUNC_IMPL(__imp__sub_8227FCA0) {
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
	ctx.lr = 0x8227FCA8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r31,1396
	ctx.r4.s64 = r31.s64 + 1396;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// bl 0x821c8fe0
	ctx.lr = 0x8227FCC4;
	sub_821C8FE0(ctx, base);
	// lbz r11,4(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227fd58
	if (cr6.eq) goto loc_8227FD58;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295510
	ctx.lr = 0x8227FCE0;
	sub_82295510(ctx, base);
	// cmpwi cr6,r3,3
	cr6.compare<int32_t>(ctx.r3.s32, 3, xer);
	// bne cr6,0x8227fd58
	if (!cr6.eq) goto loc_8227FD58;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x8227FCF4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227fd58
	if (cr6.eq) goto loc_8227FD58;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82618750
	ctx.lr = 0x8227FD08;
	sub_82618750(ctx, base);
	// addi r11,r30,153
	r11.s64 = r30.s64 + 153;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r30,r10,r31
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// bl 0x822954b8
	ctx.lr = 0x8227FD20;
	sub_822954B8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,6
	ctx.r4.s64 = r31.s64 + 6;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x826185b0
	ctx.lr = 0x8227FD34;
	sub_826185B0(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82255ae0
	ctx.lr = 0x8227FD40;
	sub_82255AE0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8227fd58
	if (cr6.eq) goto loc_8227FD58;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8268d518
	ctx.lr = 0x8227FD54;
	sub_8268D518(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
loc_8227FD58:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821c9030
	ctx.lr = 0x8227FD60;
	sub_821C9030(ctx, base);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8227FD6C"))) PPC_WEAK_FUNC(sub_8227FD6C);
PPC_FUNC_IMPL(__imp__sub_8227FD6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FD70"))) PPC_WEAK_FUNC(sub_8227FD70);
PPC_FUNC_IMPL(__imp__sub_8227FD70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r0{};
	PPCRegister r11{};
	PPCRegister r12{};
	// lis r11,4096
	r11.s64 = 268435456;
	// cmplwi cr6,r4,3
	cr6.compare<uint32_t>(ctx.r4.u32, 3, xer);
	// ori r10,r11,36
	ctx.r10.u64 = r11.u64 | 36;
	// bgt cr6,0x8227fdbc
	if (cr6.gt) {
		sub_8227FDBC(ctx, base);
		return;
	}
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-616
	r12.s64 = r12.s64 + -616;
	// rlwinm r0,r4,2,0,29
	r0.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (ctx.r4.u64) {
	case 0:
		// ERROR: 0x8227FDF0
		return;
	case 1:
		// ERROR: 0x8227FDB4
		return;
	case 2:
		// ERROR: 0x8227FDA8
		return;
	case 3:
		// ERROR: 0x8227FDE0
		return;
	default:
		__builtin_unreachable();
	}
}

__attribute__((alias("__imp__sub_8227FD98"))) PPC_WEAK_FUNC(sub_8227FD98);
PPC_FUNC_IMPL(__imp__sub_8227FD98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCRegister r17{};
	// lwz r17,-528(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -528);
	// lwz r17,-588(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -588);
	// lwz r17,-600(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -600);
	// lwz r17,-544(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -544);
	// lis r11,4096
	r11.s64 = 268435456;
	// ori r11,r11,39
	r11.u64 = r11.u64 | 39;
	// b 0x8227fdc0
	// ERROR 8227FDC0
	return;
}

__attribute__((alias("__imp__sub_8227FDB4"))) PPC_WEAK_FUNC(sub_8227FDB4);
PPC_FUNC_IMPL(__imp__sub_8227FDB4) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// mr r11,r10
	r11.u64 = ctx.r10.u64;
	// b 0x8227fdc0
	// ERROR 8227FDC0
	return;
}

__attribute__((alias("__imp__sub_8227FDBC"))) PPC_WEAK_FUNC(sub_8227FDBC);
PPC_FUNC_IMPL(__imp__sub_8227FDBC) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// li r11,-1
	r11.s64 = -1;
	// subf. r11,r10,r11
	r11.s64 = r11.s64 - ctx.r10.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x8227fdd8
	if (cr0.eq) goto loc_8227FDD8;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bne cr6,0x8227fde8
	if (!cr6.eq) {
		sub_8227FDE8(ctx, base);
		return;
	}
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_8227FDD8:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227FDE0"))) PPC_WEAK_FUNC(sub_8227FDE0);
PPC_FUNC_IMPL(__imp__sub_8227FDE0) {
	PPC_FUNC_PROLOGUE();
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227FDE8"))) PPC_WEAK_FUNC(sub_8227FDE8);
PPC_FUNC_IMPL(__imp__sub_8227FDE8) {
	PPC_FUNC_PROLOGUE();
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227FDF0"))) PPC_WEAK_FUNC(sub_8227FDF0);
PPC_FUNC_IMPL(__imp__sub_8227FDF0) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227FDF8"))) PPC_WEAK_FUNC(sub_8227FDF8);
PPC_FUNC_IMPL(__imp__sub_8227FDF8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	// cmpwi cr6,r4,3
	cr6.compare<int32_t>(ctx.r4.s32, 3, xer);
	// bgt cr6,0x8227fe38
	if (cr6.gt) goto loc_8227FE38;
	// beq cr6,0x8227fe2c
	if (cr6.eq) goto loc_8227FE2C;
	// cmpwi cr6,r4,1
	cr6.compare<int32_t>(ctx.r4.s32, 1, xer);
	// beq cr6,0x8227fe20
	if (cr6.eq) goto loc_8227FE20;
	// cmpwi cr6,r4,2
	cr6.compare<int32_t>(ctx.r4.s32, 2, xer);
	// bne cr6,0x8227fe40
	if (!cr6.eq) goto loc_8227FE40;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,39
	ctx.r3.u64 = ctx.r3.u64 | 39;
	// blr 
	return;
loc_8227FE20:
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,36
	ctx.r3.u64 = ctx.r3.u64 | 36;
	// blr 
	return;
loc_8227FE2C:
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// ori r3,r3,40
	ctx.r3.u64 = ctx.r3.u64 | 40;
	// blr 
	return;
loc_8227FE38:
	// cmplwi cr6,r4,65534
	cr6.compare<uint32_t>(ctx.r4.u32, 65534, xer);
	// beq cr6,0x8227fe48
	if (cr6.eq) goto loc_8227FE48;
loc_8227FE40:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
loc_8227FE48:
	// lis r3,8192
	ctx.r3.s64 = 536870912;
	// ori r3,r3,44
	ctx.r3.u64 = ctx.r3.u64 | 44;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8227FE54"))) PPC_WEAK_FUNC(sub_8227FE54);
PPC_FUNC_IMPL(__imp__sub_8227FE54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FE58"))) PPC_WEAK_FUNC(sub_8227FE58);
PPC_FUNC_IMPL(__imp__sub_8227FE58) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	// bl 0x823d91d0
	ctx.lr = 0x8227FE60;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// mr r24,r7
	r24.u64 = ctx.r7.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// li r22,0
	r22.s64 = 0;
	// li r18,1
	r18.s64 = 1;
	// std r22,0(r23)
	PPC_STORE_U64(r23.u32 + 0, r22.u64);
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// stb r22,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r22.u8);
	// mr r25,r8
	r25.u64 = ctx.r8.u64;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r31,r18
	r31.u64 = r18.u64;
	// add r20,r4,r9
	r20.u64 = ctx.r4.u64 + ctx.r9.u64;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227FEA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r27,r22
	r27.u64 = r22.u64;
loc_8227FEAC:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8227ffb0
	if (cr6.eq) goto loc_8227FFB0;
	// lwz r11,0(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8227FED0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x824e8f28
	ctx.lr = 0x8227FEE0;
	sub_824E8F28(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x8227ffa4
	if (!cr6.eq) goto loc_8227FFA4;
	// cmplwi cr6,r27,3
	cr6.compare<uint32_t>(r27.u32, 3, xer);
	// bgt cr6,0x8227ff2c
	if (cr6.gt) goto loc_8227FF2C;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,-244
	r12.s64 = r12.s64 + -244;
	// rlwinm r0,r27,2,0,29
	r0.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r27.u64) {
	case 0:
		goto loc_8227FF1C;
	case 1:
		goto loc_8227FF24;
	case 2:
		goto loc_8227FF24;
	case 3:
		goto loc_8227FF24;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-228(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -228);
	// lwz r17,-220(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -220);
	// lwz r17,-220(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -220);
	// lwz r17,-220(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -220);
loc_8227FF1C:
	// li r6,8
	ctx.r6.s64 = 8;
	// b 0x8227ff30
	goto loc_8227FF30;
loc_8227FF24:
	// li r6,4
	ctx.r6.s64 = 4;
	// b 0x8227ff30
	goto loc_8227FF30;
loc_8227FF2C:
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
loc_8227FF30:
	// cmplw cr6,r19,r27
	cr6.compare<uint32_t>(r19.u32, r27.u32, xer);
	// bne cr6,0x8227ff58
	if (!cr6.eq) goto loc_8227FF58;
	// li r6,8
	ctx.r6.s64 = 8;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8227FF4C;
	sub_824E9690(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stb r31,0(r24)
	PPC_STORE_U8(r24.u32 + 0, r31.u8);
	// b 0x8227ffa4
	goto loc_8227FFA4;
loc_8227FF58:
	// add r29,r6,r28
	r29.u64 = ctx.r6.u64 + r28.u64;
	// cmplw cr6,r29,r20
	cr6.compare<uint32_t>(r29.u32, r20.u32, xer);
	// bgt cr6,0x8227ff84
	if (cr6.gt) goto loc_8227FF84;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x824e9690
	ctx.lr = 0x8227FF74;
	sub_824E9690(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// mr r11,r18
	r11.u64 = r18.u64;
	// bne cr6,0x8227ff88
	if (!cr6.eq) goto loc_8227FF88;
loc_8227FF84:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_8227FF88:
	// clrlwi r31,r11,24
	r31.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8227ffa0
	if (cr6.eq) goto loc_8227FFA0;
	// extsw r11,r27
	r11.s64 = r27.s32;
	// sld r10,r18,r11
	ctx.r10.u64 = r11.u8 & 0x40 ? 0 : (r18.u64 << (r11.u8 & 0x7F));
	// std r10,0(r23)
	PPC_STORE_U64(r23.u32 + 0, ctx.r10.u64);
loc_8227FFA0:
	// mr r28,r29
	r28.u64 = r29.u64;
loc_8227FFA4:
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
	// cmpwi cr6,r27,4
	cr6.compare<int32_t>(r27.s32, 4, xer);
	// blt cr6,0x8227feac
	if (cr6.lt) goto loc_8227FEAC;
loc_8227FFB0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8227FFBC"))) PPC_WEAK_FUNC(sub_8227FFBC);
PPC_FUNC_IMPL(__imp__sub_8227FFBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8227FFC0"))) PPC_WEAK_FUNC(sub_8227FFC0);
PPC_FUNC_IMPL(__imp__sub_8227FFC0) {
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
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x8227fff4
	if (cr6.eq) goto loc_8227FFF4;
	// bl 0x82130588
	ctx.lr = 0x8227FFF0;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8227FFF4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82280008"))) PPC_WEAK_FUNC(sub_82280008);
PPC_FUNC_IMPL(__imp__sub_82280008) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,8
	cr6.compare<uint32_t>(ctx.r5.u32, 8, xer);
	// blt cr6,0x82280064
	if (cr6.lt) goto loc_82280064;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82280064
	if (cr6.eq) goto loc_82280064;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228003C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r8,r9,564
	ctx.r8.s64 = ctx.r9.s64 + 564;
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82280064:
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

__attribute__((alias("__imp__sub_8228007C"))) PPC_WEAK_FUNC(sub_8228007C);
PPC_FUNC_IMPL(__imp__sub_8228007C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82280080"))) PPC_WEAK_FUNC(sub_82280080);
PPC_FUNC_IMPL(__imp__sub_82280080) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x82280088;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280098;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822800A8;
	sub_82270170(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r26,208(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// bl 0x8227e0b0
	ctx.lr = 0x822800B8;
	sub_8227E0B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822801e4
	if (cr6.eq) goto loc_822801E4;
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x822801e4
	if (cr6.eq) goto loc_822801E4;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f438
	ctx.lr = 0x822800D8;
	sub_8227F438(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f438
	ctx.lr = 0x822800E8;
	sub_8227F438(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822701c8
	ctx.lr = 0x82280100;
	sub_822701C8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lwz r8,16(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r7,48(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r29,r7,3
	r29.s64 = ctx.r7.s64 + 196608;
	// addi r29,r29,-21024
	r29.s64 = r29.s64 + -21024;
	// beq cr6,0x822801e4
	if (cr6.eq) goto loc_822801E4;
	// addi r3,r26,144
	ctx.r3.s64 = r26.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x8228012C;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228015c
	if (cr6.eq) goto loc_8228015C;
	// add r11,r27,r28
	r11.u64 = r27.u64 + r28.u64;
	// srawi r10,r11,1
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x1) != 0);
	ctx.r10.s64 = r11.s32 >> 1;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + xer.ca;
	xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r7,r8,r11
	ctx.r7.s64 = r11.s64 - ctx.r8.s64;
	// cntlzw r6,r7
	ctx.r6.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r3,r6,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_8228015C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822801b4
	if (cr6.eq) goto loc_822801B4;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295538
	ctx.lr = 0x82280174;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x822801b4
	if (cr6.eq) goto loc_822801B4;
	// lbz r11,6(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 6);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822801b4
	if (cr6.eq) goto loc_822801B4;
	// subf r11,r27,r28
	r11.s64 = r28.s64 - r27.s64;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// blt cr6,0x822801a4
	if (cr6.lt) goto loc_822801A4;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// ble cr6,0x822801a8
	if (!cr6.gt) goto loc_822801A8;
loc_822801A4:
	// li r11,0
	r11.s64 = 0;
loc_822801A8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822801B4:
	// lbz r11,12(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822801e4
	if (!cr6.eq) goto loc_822801E4;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x822801d4
	if (cr6.eq) goto loc_822801D4;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822801d8
	if (!cr6.eq) goto loc_822801D8;
loc_822801D4:
	// li r11,0
	r11.s64 = 0;
loc_822801D8:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
loc_822801E4:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_822801F0"))) PPC_WEAK_FUNC(sub_822801F0);
PPC_FUNC_IMPL(__imp__sub_822801F0) {
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
	// bl 0x8227e750
	ctx.lr = 0x82280208;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280260
	if (cr6.eq) goto loc_82280260;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e7f8
	ctx.lr = 0x8228021C;
	sub_8227E7F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280260
	if (cr6.eq) goto loc_82280260;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280230;
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
	ctx.lr = 0x82280244;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228024C;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82280250;
	sub_82481590(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82280264
	if (cr6.eq) goto loc_82280264;
loc_82280260:
	// li r11,0
	r11.s64 = 0;
loc_82280264:
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

__attribute__((alias("__imp__sub_8228027C"))) PPC_WEAK_FUNC(sub_8228027C);
PPC_FUNC_IMPL(__imp__sub_8228027C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82280280"))) PPC_WEAK_FUNC(sub_82280280);
PPC_FUNC_IMPL(__imp__sub_82280280) {
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
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x822802A0;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82280308
	if (cr6.eq) goto loc_82280308;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822802B4;
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
	ctx.lr = 0x822802C8;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x822802D0;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x822802D4;
	sub_82481590(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82280308
	if (cr6.eq) goto loc_82280308;
	// bl 0x82256058
	ctx.lr = 0x822802E4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280308
	if (cr6.eq) goto loc_82280308;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f5f0
	ctx.lr = 0x822802F4;
	sub_8227F5F0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82280308:
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

__attribute__((alias("__imp__sub_82280320"))) PPC_WEAK_FUNC(sub_82280320);
PPC_FUNC_IMPL(__imp__sub_82280320) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82280348;
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
	ctx.lr = 0x8228035C;
	sub_82293E30(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82280368;
	sub_8226BE68(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822803a8
	if (cr6.eq) goto loc_822803A8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822803a8
	if (cr6.eq) goto loc_822803A8;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e7f8
	ctx.lr = 0x82280388;
	sub_8227E7F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822803a8
	if (cr6.eq) goto loc_822803A8;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295e90
	ctx.lr = 0x822803A0;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82280408
	if (!cr6.eq) goto loc_82280408;
loc_822803A8:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822952b0
	ctx.lr = 0x822803B4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280410
	if (cr6.eq) goto loc_82280410;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295538
	ctx.lr = 0x822803D0;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82280410
	if (cr6.eq) goto loc_82280410;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r31,36(r4)
	r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// bl 0x8226b2f0
	ctx.lr = 0x822803E8;
	sub_8226B2F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82294028
	ctx.lr = 0x822803F8;
	sub_82294028(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x822803FC;
	sub_82293F60(ctx, base);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 12);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x82280410
	if (!cr6.gt) goto loc_82280410;
loc_82280408:
	// li r11,1
	r11.s64 = 1;
	// b 0x82280414
	goto loc_82280414;
loc_82280410:
	// li r11,0
	r11.s64 = 0;
loc_82280414:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
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

__attribute__((alias("__imp__sub_82280430"))) PPC_WEAK_FUNC(sub_82280430);
PPC_FUNC_IMPL(__imp__sub_82280430) {
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
	ctx.lr = 0x82280438;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// beq cr6,0x82280838
	if (cr6.eq) goto loc_82280838;
	// cmpwi cr6,r31,4
	cr6.compare<int32_t>(r31.s32, 4, xer);
	// bne cr6,0x822806a0
	if (!cr6.eq) goto loc_822806A0;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822804b0
	if (cr6.eq) goto loc_822804B0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10000(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// bl 0x823c34d0
	ctx.lr = 0x82280474;
	sub_823C34D0(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82727cc0
	ctx.lr = 0x82280480;
	sub_82727CC0(ctx, base);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// bl 0x82727c48
	ctx.lr = 0x82280488;
	sub_82727C48(ctx, base);
	// lwz r3,28(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822804a8
	if (cr6.eq) goto loc_822804A8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822804A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822804A8:
	// stw r28,28(r30)
	PPC_STORE_U32(r30.u32 + 28, r28.u32);
	// bl 0x82727640
	ctx.lr = 0x822804B0;
	sub_82727640(ctx, base);
loc_822804B0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822804B8;
	sub_82388580(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822804C8;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272d70
	ctx.lr = 0x822804D0;
	sub_82272D70(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,716
	ctx.r4.s64 = ctx.r10.s64 + 716;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x822804F0;
	sub_82691650(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,268(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 268);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82280500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r6,-32130
	ctx.r6.s64 = -2105671680;
	// lis r5,-32130
	ctx.r5.s64 = -2105671680;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r7,704
	ctx.r4.s64 = ctx.r7.s64 + 704;
	// addi r31,r6,-17724
	r31.s64 = ctx.r6.s64 + -17724;
	// addi r27,r5,-22108
	r27.s64 = ctx.r5.s64 + -22108;
	// bl 0x82691650
	ctx.lr = 0x82280520;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82280534;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822805f0
	if (cr6.eq) goto loc_822805F0;
	// lis r27,-32119
	r27.s64 = -2104950784;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -17944);
	// bl 0x82305870
	ctx.lr = 0x82280550;
	sub_82305870(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r28.u32);
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82280568;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,-13284
	ctx.r4.s64 = ctx.r9.s64 + -13284;
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82280584;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r6,-10300
	r28.s64 = ctx.r6.s64 + -10300;
	// lwz r4,468(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 468);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x822805A0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x822805AC;
	sub_825EE0E0(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r9,496(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 496);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822805C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r8,20304
	ctx.r4.s64 = ctx.r8.s64 + 20304;
	// lwz r6,44(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x822805E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-17944(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -17944);
	// bl 0x823058f8
	ctx.lr = 0x822805F0;
	sub_823058F8(ctx, base);
loc_822805F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822805F8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280608;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82280764
	if (!cr6.eq) goto loc_82280764;
	// li r11,4
	r11.s64 = 4;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r11,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r11.u32);
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r10,672
	ctx.r3.s64 = ctx.r10.s64 + 672;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x8228063C;
	sub_82727908(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b1f8
	ctx.lr = 0x82280648;
	sub_8226B1F8(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228066c
	if (cr6.eq) goto loc_8228066C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228066c
	if (cr6.eq) goto loc_8228066C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826d7118
	ctx.lr = 0x8228066C;
	sub_826D7118(ctx, base);
loc_8228066C:
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lbz r11,756(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 756);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228068c
	if (cr6.eq) goto loc_8228068C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82729c80
	ctx.lr = 0x8228068C;
	sub_82729C80(ctx, base);
loc_8228068C:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388680
	ctx.lr = 0x82280694;
	sub_82388680(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_822806A0:
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x82280764
	if (!cr6.eq) goto loc_82280764;
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822806d8
	if (!cr6.eq) goto loc_822806D8;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r8,1500
	ctx.r8.s64 = 1500;
	// addi r3,r11,644
	ctx.r3.s64 = r11.s64 + 644;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82727908
	ctx.lr = 0x822806D4;
	sub_82727908(ctx, base);
	// stw r3,28(r30)
	PPC_STORE_U32(r30.u32 + 28, ctx.r3.u32);
loc_822806D8:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280764
	if (cr6.eq) goto loc_82280764;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,-12356(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12356);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82280700;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwz r3,-12012(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -12012);
	// bl 0x821f15c8
	ctx.lr = 0x8228070C;
	sub_821F15C8(ctx, base);
	// bl 0x821e60c0
	ctx.lr = 0x82280710;
	sub_821E60C0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822700e8
	ctx.lr = 0x8228071C;
	sub_822700E8(ctx, base);
	// lwz r11,-10240(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82463cb0
	ctx.lr = 0x8228072C;
	sub_82463CB0(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// stw r31,16(r30)
	PPC_STORE_U32(r30.u32 + 16, r31.u32);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lbz r7,756(r11)
	ctx.r7.u64 = PPC_LOAD_U8(r11.u32 + 756);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82280754
	if (cr6.eq) goto loc_82280754;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-4964(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -4964);
	// bl 0x82729c80
	ctx.lr = 0x82280754;
	sub_82729C80(ctx, base);
loc_82280754:
	// cmplwi cr6,r31,1
	cr6.compare<uint32_t>(r31.u32, 1, xer);
	// blt cr6,0x82280788
	if (cr6.lt) goto loc_82280788;
	// beq cr6,0x82280770
	if (cr6.eq) goto loc_82280770;
	// cmplwi cr6,r31,4
	cr6.compare<uint32_t>(r31.u32, 4, xer);
loc_82280764:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82280770:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,25
	ctx.r4.s64 = 25;
	// bl 0x8268ee10
	ctx.lr = 0x82280784;
	sub_8268EE10(ctx, base);
	// b 0x822807c4
	goto loc_822807C4;
loc_82280788:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,18
	ctx.r4.s64 = 18;
	// bl 0x8268ee10
	ctx.lr = 0x8228079C;
	sub_8268EE10(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r10,636
	ctx.r4.s64 = ctx.r10.s64 + 636;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-12440(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12440);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,48(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 48);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822807C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822807C4:
	// lwz r3,-3624(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// bl 0x8226b1f8
	ctx.lr = 0x822807CC;
	sub_8226B1F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822807f0
	if (cr6.eq) goto loc_822807F0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10012);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822807f0
	if (cr6.eq) goto loc_822807F0;
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826d7118
	ctx.lr = 0x822807F0;
	sub_826D7118(ctx, base);
loc_822807F0:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x822807FC;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280838
	if (cr6.eq) goto loc_82280838;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82280810;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82280838
	if (cr6.eq) goto loc_82280838;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82280824;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,72(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280838
	if (cr6.eq) goto loc_82280838;
	// bl 0x82338388
	ctx.lr = 0x82280838;
	sub_82338388(ctx, base);
loc_82280838:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82280844"))) PPC_WEAK_FUNC(sub_82280844);
PPC_FUNC_IMPL(__imp__sub_82280844) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82280848"))) PPC_WEAK_FUNC(sub_82280848);
PPC_FUNC_IMPL(__imp__sub_82280848) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
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
	// bl 0x823d91fc
	ctx.lr = 0x82280850;
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82280874;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82280894
	if (!cr6.eq) goto loc_82280894;
loc_82280880:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_82280894:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e750
	ctx.lr = 0x8228089C;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228096c
	if (cr6.eq) goto loc_8228096C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e1b0
	ctx.lr = 0x822808B0;
	sub_8227E1B0(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r10,36(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 36);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// lfs f30,20(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	f30.f64 = double(temp.f32);
	// blt cr6,0x82280880
	if (cr6.lt) goto loc_82280880;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8226b2f0
	ctx.lr = 0x822808DC;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x822808E0;
	sub_82293F60(ctx, base);
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	cr6.compare(ctx.f1.f64, f31.f64);
	// bge cr6,0x822808fc
	if (!cr6.lt) goto loc_822808FC;
loc_822808E8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_822808FC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280904;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280914;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228091C;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82280920;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x822808e8
	if (!cr6.eq) goto loc_822808E8;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82280938;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x8228093C;
	sub_82293F60(ctx, base);
	// fsubs f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 - f31.f64));
	// fcmpu cr6,f0,f30
	cr6.compare(f0.f64, f30.f64);
	// bgt cr6,0x82280880
	if (cr6.gt) goto loc_82280880;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e250
	ctx.lr = 0x82280954;
	sub_8227E250(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
loc_8228096C:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82280978;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228099c
	if (cr6.eq) goto loc_8228099C;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x82280990;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x822809a0
	if (cr6.eq) goto loc_822809A0;
loc_8228099C:
	// li r11,0
	r11.s64 = 0;
loc_822809A0:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822809B4"))) PPC_WEAK_FUNC(sub_822809B4);
PPC_FUNC_IMPL(__imp__sub_822809B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822809B8"))) PPC_WEAK_FUNC(sub_822809B8);
PPC_FUNC_IMPL(__imp__sub_822809B8) {
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
	ctx.lr = 0x822809C0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822809DC;
	sub_822701C8(ctx, base);
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82280848
	ctx.lr = 0x822809F4;
	sub_82280848(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82280ac8
	if (!cr6.eq) goto loc_82280AC8;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280A1C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280A2C;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82280A34;
	sub_82272A30(ctx, base);
	// bl 0x82481578
	ctx.lr = 0x82280A38;
	sub_82481578(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x82280A50;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280ac8
	if (cr6.eq) goto loc_82280AC8;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82280A68;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82280ac8
	if (!cr6.eq) goto loc_82280AC8;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x82280A7C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280ab8
	if (cr6.eq) goto loc_82280AB8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280A90;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280AA0;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82280AA8;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82280AAC;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82280ac8
	if (!cr6.eq) goto loc_82280AC8;
loc_82280AB8:
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_82280AC8:
	// li r11,0
	r11.s64 = 0;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82280AD8"))) PPC_WEAK_FUNC(sub_82280AD8);
PPC_FUNC_IMPL(__imp__sub_82280AD8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x82280AE0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280AF0;
	sub_82388580(ctx, base);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82280B00;
	sub_82270170(ctx, base);
	// lwz r31,208(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// lwz r11,24(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// lwz r11,16(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// addi r30,r31,144
	r30.s64 = r31.s64 + 144;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82481580
	ctx.lr = 0x82280B30;
	sub_82481580(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8226b020
	ctx.lr = 0x82280B44;
	sub_8226B020(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// lbz r11,9(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 9);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// lwz r11,16(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 16);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82280c9c
	if (cr6.eq) goto loc_82280C9C;
	// bl 0x8227e750
	ctx.lr = 0x82280B70;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r28,1
	r28.s64 = 1;
	// li r27,1
	r27.s64 = 1;
	// bl 0x82481590
	ctx.lr = 0x82280B8C;
	sub_82481590(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_82280B98:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82280c00
	if (cr6.eq) goto loc_82280C00;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x82280BAC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280c00
	if (cr6.eq) goto loc_82280C00;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280c00
	if (!cr6.eq) goto loc_82280C00;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280BCC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280BDC;
	sub_82270170(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// beq cr6,0x82280c00
	if (cr6.eq) goto loc_82280C00;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// bl 0x822577d0
	ctx.lr = 0x82280BF4;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280c00
	if (cr6.eq) goto loc_82280C00;
	// addi r27,r27,1
	r27.s64 = r27.s64 + 1;
loc_82280C00:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82280b98
	if (!cr0.eq) goto loc_82280B98;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82280C14;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280c34
	if (cr6.eq) goto loc_82280C34;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82280080
	ctx.lr = 0x82280C28;
	sub_82280080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
loc_82280C34:
	// cmpw cr6,r27,r28
	cr6.compare<int32_t>(r27.s32, r28.s32, xer);
	// bne cr6,0x82280c64
	if (!cr6.eq) goto loc_82280C64;
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// bgt cr6,0x82280c54
	if (cr6.gt) goto loc_82280C54;
	// lbz r11,12(r24)
	r11.u64 = PPC_LOAD_U8(r24.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,0
	r11.s64 = 0;
	// beq cr6,0x82280c58
	if (cr6.eq) goto loc_82280C58;
loc_82280C54:
	// li r11,1
	r11.s64 = 1;
loc_82280C58:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_82280C64:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// ble cr6,0x82280c8c
	if (!cr6.gt) goto loc_82280C8C;
	// srawi r11,r28,1
	xer.ca = (r28.s32 < 0) & ((r28.u32 & 0x1) != 0);
	r11.s64 = r28.s32 >> 1;
	// addze r10,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r10.s64 = temp.s64;
	// li r11,1
	r11.s64 = 1;
	// cmpw cr6,r27,r10
	cr6.compare<int32_t>(r27.s32, ctx.r10.s32, xer);
	// bgt cr6,0x82280c90
	if (cr6.gt) goto loc_82280C90;
loc_82280C8C:
	// li r11,0
	r11.s64 = 0;
loc_82280C90:
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_82280C9C:
	// bl 0x8227e038
	ctx.lr = 0x82280CA0;
	sub_8227E038(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280CB4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280CC4;
	sub_82270170(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// bl 0x822577d0
	ctx.lr = 0x82280CCC;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280d98
	if (cr6.eq) goto loc_82280D98;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82293e18
	ctx.lr = 0x82280CDC;
	sub_82293E18(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293e18
	ctx.lr = 0x82280CE4;
	sub_82293E18(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280CEC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10240);
	// addi r30,r1,80
	r30.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280D00;
	sub_82270170(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x8227d968
	ctx.lr = 0x82280D0C;
	sub_8227D968(ctx, base);
	// li r29,0
	r29.s64 = 0;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
loc_82280D14:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82280d7c
	if (cr6.eq) goto loc_82280D7C;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d7c
	if (!cr6.eq) goto loc_82280D7C;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x82280D34;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280d7c
	if (cr6.eq) goto loc_82280D7C;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82280D4C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82280d7c
	if (cr6.eq) goto loc_82280D7C;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227d968
	ctx.lr = 0x82280D64;
	sub_8227D968(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82293f28
	ctx.lr = 0x82280D70;
	sub_82293F28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280d98
	if (!cr6.eq) goto loc_82280D98;
loc_82280D7C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpwi cr6,r29,31
	cr6.compare<int32_t>(r29.s32, 31, xer);
	// bne cr6,0x82280d14
	if (!cr6.eq) goto loc_82280D14;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
loc_82280D98:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82280DA4"))) PPC_WEAK_FUNC(sub_82280DA4);
PPC_FUNC_IMPL(__imp__sub_82280DA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82280DA8"))) PPC_WEAK_FUNC(sub_82280DA8);
PPC_FUNC_IMPL(__imp__sub_82280DA8) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82280ad8
	ctx.lr = 0x82280DD0;
	sub_82280AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82280e1c
	if (cr6.eq) goto loc_82280E1C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,32(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14192(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bne cr6,0x82280e1c
	if (!cr6.eq) goto loc_82280E1C;
	// lbz r11,14(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280e1c
	if (!cr6.eq) goto loc_82280E1C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82280E0C;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82280E10;
	sub_82293F60(ctx, base);
	// fadds f0,f1,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(ctx.f1.f64 + f31.f64));
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stb r30,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r30.u8);
loc_82280E1C:
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

__attribute__((alias("__imp__sub_82280E38"))) PPC_WEAK_FUNC(sub_82280E38);
PPC_FUNC_IMPL(__imp__sub_82280E38) {
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
	ctx.lr = 0x82280E40;
	// stwu r1,-1200(r1)
	ea = -1200 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82280E58;
	sub_8226B2F0(ctx, base);
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r9,9008
	ctx.r3.s64 = ctx.r9.s64 + 9008;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f0,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x821c07c0
	ctx.lr = 0x82280E80;
	sub_821C07C0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280E88;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82280E98;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82280EA0;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82280EA4;
	sub_82481590(ctx, base);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82280ec0
	if (cr6.eq) goto loc_82280EC0;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	f0.f64 = double(temp.f32);
	// b 0x82280ed8
	goto loc_82280ED8;
loc_82280EC0:
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82280edc
	if (!cr6.eq) goto loc_82280EDC;
	// lwz r11,-3624(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
loc_82280ED8:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_82280EDC:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r28)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r28.u32 + 32, temp.u32);
	// bl 0x82280ad8
	ctx.lr = 0x82280EF0;
	sub_82280AD8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r31,r11,-2628
	r31.s64 = r11.s64 + -2628;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x822701c8
	ctx.lr = 0x82280F10;
	sub_822701C8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82280f48
	if (!cr6.eq) goto loc_82280F48;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82280F2C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82280F3C;
	sub_82270170(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// bl 0x822577d0
	ctx.lr = 0x82280F44;
	sub_822577D0(ctx, base);
	// b 0x82280f70
	goto loc_82280F70;
loc_82280F48:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227e750
	ctx.lr = 0x82280F50;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82280F68;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x82280F70;
	sub_82295E90(ctx, base);
loc_82280F70:
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// subf r10,r4,r11
	ctx.r10.s64 = r11.s64 - ctx.r4.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r27,r11
	r27.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82280fb4
	if (!cr6.eq) goto loc_82280FB4;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// bl 0x82389668
	ctx.lr = 0x82280FA8;
	sub_82389668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
loc_82280FB4:
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82280fc8
	if (cr6.eq) goto loc_82280FC8;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r29,-28256(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -28256);
	// b 0x82280fdc
	goto loc_82280FDC;
loc_82280FC8:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r29,r8,r9
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
loc_82280FDC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82280FE8;
	sub_822701C8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82295e90
	ctx.lr = 0x82280FF0;
	sub_82295E90(ctx, base);
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// lwz r10,24(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmpwi cr6,r10,-1
	cr6.compare<int32_t>(ctx.r10.s32, -1, xer);
	// bne cr6,0x82281108
	if (!cr6.eq) goto loc_82281108;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82281018
	if (!cr6.eq) goto loc_82281018;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281028
	if (cr6.eq) goto loc_82281028;
loc_82281018:
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82281108
	if (!cr6.eq) goto loc_82281108;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
loc_82281028:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293f88
	ctx.lr = 0x82281034;
	sub_82293F88(ctx, base);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x822810f0
	if (cr6.eq) goto loc_822810F0;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822810a8
	if (!cr6.eq) goto loc_822810A8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r31,r10,3
	r31.s64 = ctx.r10.s64 + 196608;
	// addi r31,r31,-16384
	r31.s64 = r31.s64 + -16384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654d90
	ctx.lr = 0x82281064;
	sub_82654D90(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,-6148(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// bl 0x82655ff8
	ctx.lr = 0x82281080;
	sub_82655FF8(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mulli r10,r3,1056
	ctx.r10.s64 = ctx.r3.s64 * 1056;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// add r11,r10,r31
	r11.u64 = ctx.r10.u64 + r31.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r6,r11,11984
	ctx.r6.s64 = r11.s64 + 11984;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x8227b770
	ctx.lr = 0x822810A0;
	sub_8227B770(ctx, base);
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// b 0x823d9244
	return;
loc_822810A8:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227e750
	ctx.lr = 0x822810B0;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281108
	if (cr6.eq) goto loc_82281108;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82250410
	ctx.lr = 0x822810C4;
	sub_82250410(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// bl 0x822701c8
	ctx.lr = 0x822810D4;
	sub_822701C8(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x8227fca0
	ctx.lr = 0x822810E0;
	sub_8227FCA0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82281108
	if (!cr6.gt) goto loc_82281108;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// b 0x822810f4
	goto loc_822810F4;
loc_822810F0:
	// li r6,0
	ctx.r6.s64 = 0;
loc_822810F4:
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b770
	ctx.lr = 0x82281108;
	sub_8227B770(ctx, base);
loc_82281108:
	// addi r1,r1,1200
	ctx.r1.s64 = ctx.r1.s64 + 1200;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82281110"))) PPC_WEAK_FUNC(sub_82281110);
PPC_FUNC_IMPL(__imp__sub_82281110) {
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
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x82281134;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281158
	if (cr6.eq) goto loc_82281158;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82281148;
	sub_822A39C8(ctx, base);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82281150;
	sub_822A39C8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822ae7c8
	ctx.lr = 0x82281158;
	sub_822AE7C8(ctx, base);
loc_82281158:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82280430
	ctx.lr = 0x82281164;
	sub_82280430(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82281180;
	sub_82641CB0(ctx, base);
	// addi r3,r3,2832
	ctx.r3.s64 = ctx.r3.s64 + 2832;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,64(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 64);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82281198;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,19
	ctx.r4.s64 = 19;
	// bl 0x8268ee10
	ctx.lr = 0x822811AC;
	sub_8268EE10(ctx, base);
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

__attribute__((alias("__imp__sub_822811C4"))) PPC_WEAK_FUNC(sub_822811C4);
PPC_FUNC_IMPL(__imp__sub_822811C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822811C8"))) PPC_WEAK_FUNC(sub_822811C8);
PPC_FUNC_IMPL(__imp__sub_822811C8) {
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
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x822811D0;
	// stfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f31.u64);
	// stwu r1,-784(r1)
	ea = -784 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x82387b38
	ctx.lr = 0x822811E4;
	sub_82387B38(ctx, base);
	// addi r29,r31,144
	r29.s64 = r31.s64 + 144;
	// li r22,0
	r22.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r29.u32);
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
	// bl 0x824817c0
	ctx.lr = 0x822811FC;
	sub_824817C0(ctx, base);
	// lbz r10,608(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 608);
	// addi r30,r3,12
	r30.s64 = ctx.r3.s64 + 12;
	// ori r9,r10,128
	ctx.r9.u64 = ctx.r10.u64 | 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stb r9,608(r1)
	PPC_STORE_U8(ctx.r1.u32 + 608, ctx.r9.u8);
	// bl 0x8226b078
	ctx.lr = 0x82281214;
	sub_8226B078(ctx, base);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// cmplw cr6,r8,r30
	cr6.compare<uint32_t>(ctx.r8.u32, r30.u32, xer);
	// beq cr6,0x8228122c
	if (cr6.eq) goto loc_8228122C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824ea350
	ctx.lr = 0x8228122C;
	sub_824EA350(ctx, base);
loc_8228122C:
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// bl 0x824e9038
	ctx.lr = 0x8228123C;
	sub_824E9038(ctx, base);
	// lis r19,-32121
	r19.s64 = -2105081856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// addi r3,r11,4312
	ctx.r3.s64 = r11.s64 + 4312;
	// bl 0x82297350
	ctx.lr = 0x82281250;
	sub_82297350(ctx, base);
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// addi r3,r11,13928
	ctx.r3.s64 = r11.s64 + 13928;
	// bl 0x82297350
	ctx.lr = 0x8228125C;
	sub_82297350(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82281a70
	if (cr6.eq) goto loc_82281A70;
	// addi r31,r1,96
	r31.s64 = ctx.r1.s64 + 96;
	// bl 0x82387b90
	ctx.lr = 0x8228126C;
	sub_82387B90(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8238b7e0
	ctx.lr = 0x82281274;
	sub_8238B7E0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822812c0
	if (cr6.lt) goto loc_822812C0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82281290;
	sub_822A3998(ctx, base);
	// lwz r11,52(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// lwz r10,8100(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8100);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822812b0
	if (cr6.eq) goto loc_822812B0;
	// bl 0x82387b90
	ctx.lr = 0x822812A4;
	sub_82387B90(ctx, base);
	// lwz r11,1344(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// beq cr6,0x822812c0
	if (cr6.eq) goto loc_822812C0;
loc_822812B0:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-29340(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -29340);
	// bl 0x826a4718
	ctx.lr = 0x822812C0;
	sub_826A4718(ctx, base);
loc_822812C0:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x82281310
	if (cr6.lt) goto loc_82281310;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x822812D4;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82281310
	if (!cr6.eq) goto loc_82281310;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x822812E8;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281310
	if (cr6.eq) goto loc_82281310;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x82281308
	if (cr6.lt) goto loc_82281308;
	// bne cr6,0x82281310
	if (!cr6.eq) goto loc_82281310;
	// stw r22,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r22.u32);
	// b 0x82281310
	goto loc_82281310;
loc_82281308:
	// li r11,1
	r11.s64 = 1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_82281310:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x82281320;
	sub_822701C8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x8227e750
	ctx.lr = 0x8228132C;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// lis r15,-32121
	r15.s64 = -2105081856;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822817b0
	if (cr6.eq) goto loc_822817B0;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822817b0
	if (cr6.eq) goto loc_822817B0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x82281350;
	sub_824E9038(ctx, base);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x82281364;
	sub_824E9038(ctx, base);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// ori r4,r4,10
	ctx.r4.u64 = ctx.r4.u64 | 10;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x82281378;
	sub_824E9038(ctx, base);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// ori r4,r4,35
	ctx.r4.u64 = ctx.r4.u64 | 35;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x8228138C;
	sub_824E9038(ctx, base);
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// ori r4,r4,11
	ctx.r4.u64 = ctx.r4.u64 | 11;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9038
	ctx.lr = 0x822813A0;
	sub_824E9038(ctx, base);
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r10,9048
	ctx.r8.s64 = ctx.r10.s64 + 9048;
	// lis r7,-32120
	ctx.r7.s64 = -2105016320;
	// lwz r6,4304(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// mr r21,r22
	r21.u64 = r22.u64;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// lfs f31,3796(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f31.f64 = double(temp.f32);
	// li r24,-1
	r24.s64 = -1;
	// lwz r10,4(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r17,-7884(r7)
	r17.u64 = PPC_LOAD_U32(ctx.r7.u32 + -7884);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// lwz r29,2124(r5)
	r29.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2124);
	// lwz r16,2200(r5)
	r16.u64 = PPC_LOAD_U32(ctx.r5.u32 + 2200);
	// bne cr6,0x822813fc
	if (!cr6.eq) goto loc_822813FC;
	// rotlwi r11,r6,0
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// mr r31,r22
	r31.u64 = r22.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,452(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 452);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x82281400
	if (!cr6.gt) goto loc_82281400;
loc_822813FC:
	// li r31,1
	r31.s64 = 1;
loc_82281400:
	// lwz r11,-10236(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -10236);
	// mr r18,r22
	r18.u64 = r22.u64;
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r27,r11,3
	r27.s64 = r11.s64 + 196608;
	// addi r27,r27,-21024
	r27.s64 = r27.s64 + -21024;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82397470
	ctx.lr = 0x8228141C;
	sub_82397470(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82281468
	if (!cr6.eq) goto loc_82281468;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281430;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281440;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x8228144C;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281468
	if (cr6.eq) goto loc_82281468;
	// cntlzw r11,r31
	r11.u64 = r31.u32 == 0 ? 32 : __builtin_clz(r31.u32);
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r9,r10,1
	ctx.r9.u64 = ctx.r10.u64 ^ 1;
	// stb r9,21(r27)
	PPC_STORE_U8(r27.u32 + 21, ctx.r9.u8);
loc_82281468:
	// lbz r11,4(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228150c
	if (!cr6.eq) goto loc_8228150C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281480;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281490;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x8228149C;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x8228150c
	if (cr6.eq) goto loc_8228150C;
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// li r11,1
	r11.s64 = 1;
	// lwz r9,1896(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 1896);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bgt cr6,0x822814c8
	if (cr6.gt) goto loc_822814C8;
	// li r11,0
	r11.s64 = 0;
loc_822814C8:
	// lbz r10,6(r27)
	ctx.r10.u64 = PPC_LOAD_U8(r27.u32 + 6);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lbz r6,4(r27)
	ctx.r6.u64 = PPC_LOAD_U8(r27.u32 + 4);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// lbz r5,5(r27)
	ctx.r5.u64 = PPC_LOAD_U8(r27.u32 + 5);
	// rlwinm r7,r10,25,7,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// ori r4,r9,60000
	ctx.r4.u64 = ctx.r9.u64 | 60000;
	// rlwimi r8,r7,7,17,24
	ctx.r8.u64 = (__builtin_rotateleft32(ctx.r7.u32, 7) & 0x7F80) | (ctx.r8.u64 & 0xFFFFFFFFFFFF807F);
	// rlwimi r6,r11,7,17,24
	ctx.r6.u64 = (__builtin_rotateleft32(r11.u32, 7) & 0x7F80) | (ctx.r6.u64 & 0xFFFFFFFFFFFF807F);
	// clrlwi r3,r8,24
	ctx.r3.u64 = ctx.r8.u32 & 0xFF;
	// stb r5,5(r27)
	PPC_STORE_U8(r27.u32 + 5, ctx.r5.u8);
	// mullw r11,r29,r4
	r11.s64 = int64_t(r29.s32) * int64_t(ctx.r4.s32);
	// stb r6,4(r27)
	PPC_STORE_U8(r27.u32 + 4, ctx.r6.u8);
	// stw r11,8(r27)
	PPC_STORE_U32(r27.u32 + 8, r11.u32);
	// rlwinm r3,r3,0,26,24
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFFFFFFFFBF;
	// ori r9,r3,64
	ctx.r9.u64 = ctx.r3.u64 | 64;
	// stb r9,6(r27)
	PPC_STORE_U8(r27.u32 + 6, ctx.r9.u8);
loc_8228150C:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82281528
	if (cr6.eq) goto loc_82281528;
	// lwz r11,-10240(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r11,4304(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r24,984(r10)
	r24.u64 = PPC_LOAD_U32(ctx.r10.u32 + 984);
loc_82281528:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x82281588
	if (cr6.lt) goto loc_82281588;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x8228153C;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x8228155c
	if (!cr6.eq) goto loc_8228155C;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x82281550;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x8228155c
	if (cr6.eq) goto loc_8228155C;
	// lwz r21,0(r3)
	r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_8228155C:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x82281568;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82281588
	if (!cr6.eq) goto loc_82281588;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x8228157C;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281588
	if (cr6.eq) goto loc_82281588;
	// lwz r22,0(r3)
	r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_82281588:
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// blt cr6,0x822815e4
	if (cr6.lt) goto loc_822815E4;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x8228159C;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x822815e4
	if (!cr6.eq) goto loc_822815E4;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x822815B0;
	sub_824E95F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822815e4
	if (cr6.eq) goto loc_822815E4;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-7572(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -7572);
	// bl 0x822f10d0
	ctx.lr = 0x822815C8;
	sub_822F10D0(ctx, base);
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x8238eb90
	ctx.lr = 0x822815D0;
	sub_8238EB90(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x82295f70
	ctx.lr = 0x822815E4;
	sub_82295F70(ctx, base);
loc_822815E4:
	// cmpwi cr6,r23,0
	cr6.compare<int32_t>(r23.s32, 0, xer);
	// blt cr6,0x82281624
	if (cr6.lt) goto loc_82281624;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x822815F8;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82281624
	if (!cr6.eq) goto loc_82281624;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x8228160C;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281624
	if (cr6.eq) goto loc_82281624;
	// lwz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x82281624;
	sub_82295F70(ctx, base);
loc_82281624:
	// cmpwi cr6,r20,0
	cr6.compare<int32_t>(r20.s32, 0, xer);
	// blt cr6,0x82281658
	if (cr6.lt) goto loc_82281658;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e9740
	ctx.lr = 0x82281638;
	sub_824E9740(ctx, base);
	// cmplwi cr6,r3,4
	cr6.compare<uint32_t>(ctx.r3.u32, 4, xer);
	// bne cr6,0x82281658
	if (!cr6.eq) goto loc_82281658;
	// mr r4,r20
	ctx.r4.u64 = r20.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x824e95f8
	ctx.lr = 0x8228164C;
	sub_824E95F8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281658
	if (cr6.eq) goto loc_82281658;
	// lwz r18,0(r3)
	r18.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
loc_82281658:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281660;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281670;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82281678;
	sub_82502300(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281684;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281694;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x82274128
	ctx.lr = 0x822816A0;
	sub_82274128(ctx, base);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x822816B0;
	sub_82295F70(ctx, base);
	// mr r5,r22
	ctx.r5.u64 = r22.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x822816C0;
	sub_82295F70(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x822816D0;
	sub_82295F70(ctx, base);
	// cmpwi cr6,r24,-1
	cr6.compare<int32_t>(r24.s32, -1, xer);
	// beq cr6,0x822816e8
	if (cr6.eq) goto loc_822816E8;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x822816E8;
	sub_82295F70(ctx, base);
loc_822816E8:
	// lwz r11,-10236(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r31,r11,3
	r31.s64 = r11.s64 + 196608;
	// addi r31,r31,-16384
	r31.s64 = r31.s64 + -16384;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82654d90
	ctx.lr = 0x82281700;
	sub_82654D90(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281738
	if (cr6.eq) goto loc_82281738;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r31,-6148(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// bl 0x82655ff8
	ctx.lr = 0x8228171C;
	sub_82655FF8(ctx, base);
	// mulli r11,r3,1056
	r11.s64 = ctx.r3.s64 * 1056;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r5,r11,11984
	ctx.r5.s64 = r11.s64 + 11984;
	// bl 0x8227fbc0
	ctx.lr = 0x82281734;
	sub_8227FBC0(ctx, base);
	// b 0x82281744
	goto loc_82281744;
loc_82281738:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295828
	ctx.lr = 0x82281744;
	sub_82295828(ctx, base);
loc_82281744:
	// li r4,6
	ctx.r4.s64 = 6;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82296088
	ctx.lr = 0x82281754;
	sub_82296088(ctx, base);
	// mr r5,r17
	ctx.r5.u64 = r17.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295d70
	ctx.lr = 0x82281764;
	sub_82295D70(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295bc8
	ctx.lr = 0x82281774;
	sub_82295BC8(ctx, base);
	// mr r5,r16
	ctx.r5.u64 = r16.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295d70
	ctx.lr = 0x82281784;
	sub_82295D70(ctx, base);
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295f70
	ctx.lr = 0x82281794;
	sub_82295F70(ctx, base);
	// stw r18,12(r27)
	PPC_STORE_U32(r27.u32 + 12, r18.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82295bc8
	ctx.lr = 0x822817A8;
	sub_82295BC8(ctx, base);
	// lwz r29,84(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r22,0
	r22.s64 = 0;
loc_822817B0:
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// bl 0x82280430
	ctx.lr = 0x822817BC;
	sub_82280430(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281a70
	if (cr6.eq) goto loc_82281A70;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82280430
	ctx.lr = 0x822817D4;
	sub_82280430(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281a70
	if (cr6.eq) goto loc_82281A70;
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8268ee10
	ctx.lr = 0x822817F4;
	sub_8268EE10(ctx, base);
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,3
	ctx.r5.s64 = 3;
	// lwz r3,0(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// li r4,17
	ctx.r4.s64 = 17;
	// bl 0x8268ee10
	ctx.lr = 0x82281808;
	sub_8268EE10(ctx, base);
	// lwz r11,-10236(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -10236);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,728
	ctx.r4.s64 = ctx.r10.s64 + 728;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82281820;
	sub_82691650(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82281870
	if (cr6.eq) goto loc_82281870;
	// lwz r11,-10236(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + -10236);
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// bne cr6,0x82281844
	if (!cr6.eq) goto loc_82281844;
	// mr r31,r22
	r31.u64 = r22.u64;
loc_82281844:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824815a0
	ctx.lr = 0x8228184C;
	sub_824815A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r9,r10,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r11,r9,1
	r11.u64 = ctx.r9.u64 ^ 1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x8268dcb0
	ctx.lr = 0x82281868;
	sub_8268DCB0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x8268dd70
	ctx.lr = 0x82281870;
	sub_8268DD70(ctx, base);
loc_82281870:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c0
	ctx.lr = 0x8228187C;
	sub_822A39C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822818ec
	if (cr6.eq) goto loc_822818EC;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x82281890;
	sub_822A39C8(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x82281894;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// lwz r30,1316(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 1316);
	// bl 0x822a39c8
	ctx.lr = 0x822818A4;
	sub_822A39C8(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x822ae7c8
	ctx.lr = 0x822818AC;
	sub_822AE7C8(ctx, base);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822818B4;
	sub_822A39C8(ctx, base);
	// lwz r10,48(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822818ec
	if (cr6.eq) goto loc_822818EC;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822818C8;
	sub_822A39C8(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r9,592(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 592);
	// rlwinm r8,r9,0,29,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x822818ec
	if (cr6.eq) goto loc_822818EC;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822818E8;
	sub_822A39C8(ctx, base);
	// bl 0x822a57d0
	ctx.lr = 0x822818EC;
	sub_822A57D0(ctx, base);
loc_822818EC:
	// bl 0x82387b90
	ctx.lr = 0x822818F0;
	sub_82387B90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,1316(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 1316);
	// bl 0x82388580
	ctx.lr = 0x82281900;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281910;
	sub_82270170(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274128
	ctx.lr = 0x8228191C;
	sub_82274128(ctx, base);
	// bl 0x82387b90
	ctx.lr = 0x82281920;
	sub_82387B90(ctx, base);
	// lwz r9,1344(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1344);
	// mulli r11,r9,8176
	r11.s64 = ctx.r9.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x8238f6b0
	ctx.lr = 0x82281934;
	sub_8238F6B0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281940;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r19)
	ctx.r3.u64 = PPC_LOAD_U32(r19.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281950;
	sub_82270170(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274128
	ctx.lr = 0x8228195C;
	sub_82274128(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// lwz r3,-12640(r7)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12640);
	// lbz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82281980
	if (cr6.eq) goto loc_82281980;
	// lbz r11,10(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 10);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// beq cr6,0x82281984
	if (cr6.eq) goto loc_82281984;
loc_82281980:
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82281984:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822819a4
	if (cr6.eq) goto loc_822819A4;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822819A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822819A4:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// stb r22,796(r9)
	PPC_STORE_U8(ctx.r9.u32 + 796, r22.u8);
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822819C4;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x82281a84
	if (cr6.eq) goto loc_82281A84;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822819DC;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82281a84
	if (cr6.eq) goto loc_82281A84;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822819F8;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281a84
	if (cr6.eq) goto loc_82281A84;
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281a84
	if (cr6.eq) goto loc_82281A84;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82281A20;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r3,20(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82281A38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82281A44;
	sub_822A3998(ctx, base);
	// lwz r8,48(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// lwz r11,12(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x82281a5c
	if (!cr6.eq) goto loc_82281A5C;
	// mr r11,r22
	r11.u64 = r22.u64;
loc_82281A5C:
	// lwz r3,1020(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 1020);
	// bl 0x82308888
	ctx.lr = 0x82281A64;
	sub_82308888(ctx, base);
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
loc_82281A70:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r14)
	ctx.r3.u64 = PPC_LOAD_U32(r14.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x8268ee10
	ctx.lr = 0x82281A84;
	sub_8268EE10(ctx, base);
loc_82281A84:
	// addi r1,r1,784
	ctx.r1.s64 = ctx.r1.s64 + 784;
	// lfd f31,-160(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82281A90"))) PPC_WEAK_FUNC(sub_82281A90);
PPC_FUNC_IMPL(__imp__sub_82281A90) {
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
	ctx.lr = 0x82281A98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// subf r28,r10,r11
	r28.s64 = r11.s64 - ctx.r10.s64;
	// bl 0x822577d0
	ctx.lr = 0x82281AC0;
	sub_822577D0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82281b18
	if (!cr6.eq) goto loc_82281B18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// ble cr6,0x82281afc
	if (!cr6.gt) goto loc_82281AFC;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x8227b860
	ctx.lr = 0x82281AE8;
	sub_8227B860(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82281AFC:
	// li r5,2
	ctx.r5.s64 = 2;
	// bl 0x8227b860
	ctx.lr = 0x82281B04;
	sub_8227B860(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82281B18:
	// cmpwi cr6,r28,1
	cr6.compare<int32_t>(r28.s32, 1, xer);
	// ble cr6,0x82281b60
	if (!cr6.gt) goto loc_82281B60;
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x82281ba0
	if (!cr6.eq) goto loc_82281BA0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b860
	ctx.lr = 0x82281B40;
	sub_8227B860(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82281B60:
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// bge cr6,0x82281ba0
	if (!cr6.lt) goto loc_82281BA0;
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bne cr6,0x82281ba0
	if (!cr6.eq) goto loc_82281BA0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,-10240(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// bl 0x8227b860
	ctx.lr = 0x82281B88;
	sub_8227B860(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,-1
	ctx.r10.s64 = r11.s64 + -1;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
loc_82281BA0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82281BA8"))) PPC_WEAK_FUNC(sub_82281BA8);
PPC_FUNC_IMPL(__imp__sub_82281BA8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82388580
	ctx.lr = 0x82281BCC;
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
	ctx.lr = 0x82281BE0;
	sub_82270170(ctx, base);
	// cmplw cr6,r30,r3
	cr6.compare<uint32_t>(r30.u32, ctx.r3.u32, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-3624(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82281BF4;
	sub_8226BE68(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x82281C08;
	sub_824E7118(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,-1952
	ctx.r4.s64 = ctx.r10.s64 + -1952;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x82281C20;
	sub_822183B0(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r4,r7,744
	ctx.r4.s64 = ctx.r7.s64 + 744;
	// lwz r3,-10028(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10028);
	// lfs f1,30712(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 30712);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82208800
	ctx.lr = 0x82281C3C;
	sub_82208800(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e750
	ctx.lr = 0x82281C44;
	sub_8227E750(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82281C58;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82203310
	ctx.lr = 0x82281C6C;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281cac
	if (cr6.eq) goto loc_82281CAC;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f438
	ctx.lr = 0x82281C84;
	sub_8227F438(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8227f438
	ctx.lr = 0x82281C94;
	sub_8227F438(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82281a90
	ctx.lr = 0x82281CAC;
	sub_82281A90(ctx, base);
loc_82281CAC:
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

__attribute__((alias("__imp__sub_82281CC4"))) PPC_WEAK_FUNC(sub_82281CC4);
PPC_FUNC_IMPL(__imp__sub_82281CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82281CC8"))) PPC_WEAK_FUNC(sub_82281CC8);
PPC_FUNC_IMPL(__imp__sub_82281CC8) {
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
	ctx.lr = 0x82281CD0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82281CF0;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82281CFC;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82281D0C;
	sub_82270170(ctx, base);
	// lwz r27,208(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82281D2C;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82281D44;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x82281D5C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281e04
	if (cr6.eq) goto loc_82281E04;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x82281D70;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82281e04
	if (!cr6.eq) goto loc_82281E04;
	// lwz r11,40(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82281e04
	if (!cr6.lt) goto loc_82281E04;
	// addi r30,r27,12
	r30.s64 = r27.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_82281D8C:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82281df8
	if (cr6.eq) goto loc_82281DF8;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x82281DA0;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281df8
	if (cr6.eq) goto loc_82281DF8;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82281DB8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281df8
	if (cr6.eq) goto loc_82281DF8;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82281DCC;
	sub_822051A0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82281df8
	if (!cr6.gt) goto loc_82281DF8;
	// lwz r11,40(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 40);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// blt cr6,0x82281de8
	if (cr6.lt) goto loc_82281DE8;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82281df8
	if (!cr6.lt) goto loc_82281DF8;
loc_82281DE8:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82281DF4;
	sub_822051A0(ctx, base);
	// stw r3,40(r28)
	PPC_STORE_U32(r28.u32 + 40, ctx.r3.u32);
loc_82281DF8:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x82281d8c
	if (!cr0.eq) goto loc_82281D8C;
loc_82281E04:
	// lwz r11,204(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 204);
	// rlwinm r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4000;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82281e98
	if (cr6.eq) goto loc_82281E98;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82281e98
	if (cr6.eq) goto loc_82281E98;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82281E28;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281e98
	if (cr6.eq) goto loc_82281E98;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82281e98
	if (cr6.eq) goto loc_82281E98;
	// addi r3,r27,144
	ctx.r3.s64 = r27.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x82281E44;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82281e98
	if (!cr6.eq) goto loc_82281E98;
	// lwz r11,24(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82281e64
	if (cr6.eq) goto loc_82281E64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82281e98
	if (!cr6.eq) goto loc_82281E98;
loc_82281E64:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227f438
	ctx.lr = 0x82281E70;
	sub_8227F438(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8227f438
	ctx.lr = 0x82281E80;
	sub_8227F438(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82281a90
	ctx.lr = 0x82281E98;
	sub_82281A90(ctx, base);
loc_82281E98:
	// bl 0x82256058
	ctx.lr = 0x82281E9C;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82281f60
	if (cr6.eq) goto loc_82281F60;
	// lwz r11,16(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82281f60
	if (!cr6.eq) goto loc_82281F60;
	// lwz r11,204(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 204);
	// rlwinm r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82281ee0
	if (!cr6.eq) goto loc_82281EE0;
	// rlwinm r11,r11,0,26,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x20;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82281f60
	if (cr6.eq) goto loc_82281F60;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x822577d0
	ctx.lr = 0x82281ED8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bne cr6,0x82281f60
	if (!cr6.eq) goto loc_82281F60;
loc_82281EE0:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,44
	ctx.r4.s64 = 44;
	// ori r30,r11,16256
	r30.u64 = r11.u64 | 16256;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r30
	ctx.r3.u64 = ctx.r10.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82281F00;
	sub_82641CB0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,60(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 60);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82281F10;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r7,r3,24
	ctx.r7.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82281f60
	if (cr6.eq) goto loc_82281F60;
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r4,r9,764
	ctx.r4.s64 = ctx.r9.s64 + 764;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r29,-10020(r10)
	r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x82691650
	ctx.lr = 0x82281F3C;
	sub_82691650(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r29,340
	ctx.r3.s64 = r29.s64 + 340;
	// bl 0x826cac98
	ctx.lr = 0x82281F48;
	sub_826CAC98(ctx, base);
	// lwz r11,-10236(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10236);
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 + r30.u64;
	// bl 0x82641cb0
	ctx.lr = 0x82281F5C;
	sub_82641CB0(ctx, base);
	// bl 0x8227d228
	ctx.lr = 0x82281F60;
	sub_8227D228(ctx, base);
loc_82281F60:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,22
	ctx.r4.s64 = 22;
	// bl 0x8268ee10
	ctx.lr = 0x82281F74;
	sub_8268EE10(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

__attribute__((alias("__imp__sub_82281F7C"))) PPC_WEAK_FUNC(sub_82281F7C);
PPC_FUNC_IMPL(__imp__sub_82281F7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82281F80"))) PPC_WEAK_FUNC(sub_82281F80);
PPC_FUNC_IMPL(__imp__sub_82281F80) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82281FAC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x82281fd0
	if (!cr6.eq) goto loc_82281FD0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82281fd0
	if (cr6.eq) goto loc_82281FD0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,484
	ctx.r10.s64 = r11.s64 + 484;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// b 0x82281fd4
	goto loc_82281FD4;
loc_82281FD0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82281FD4:
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

__attribute__((alias("__imp__sub_82281FEC"))) PPC_WEAK_FUNC(sub_82281FEC);
PPC_FUNC_IMPL(__imp__sub_82281FEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82281FF0"))) PPC_WEAK_FUNC(sub_82281FF0);
PPC_FUNC_IMPL(__imp__sub_82281FF0) {
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
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r9,r11,-28
	ctx.r9.s64 = r11.s64 + -28;
	// addi r8,r10,48
	ctx.r8.s64 = ctx.r10.s64 + 48;
	// clrlwi r7,r4,31
	ctx.r7.u64 = ctx.r4.u32 & 0x1;
	// stw r9,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r9.u32);
	// stw r8,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r8.u32);
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x82282030
	if (cr6.eq) goto loc_82282030;
	// bl 0x82130588
	ctx.lr = 0x8228202C;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_82282030:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82282044"))) PPC_WEAK_FUNC(sub_82282044);
PPC_FUNC_IMPL(__imp__sub_82282044) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82282048"))) PPC_WEAK_FUNC(sub_82282048);
PPC_FUNC_IMPL(__imp__sub_82282048) {
	PPC_FUNC_PROLOGUE();
	// lwz r3,524(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 524);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82282050"))) PPC_WEAK_FUNC(sub_82282050);
PPC_FUNC_IMPL(__imp__sub_82282050) {
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
	ctx.lr = 0x82282058;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282068;
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
	ctx.lr = 0x8228207C;
	sub_82270170(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r31,208(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// bl 0x8227e750
	ctx.lr = 0x8228208C;
	sub_8227E750(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8228213c
	if (cr6.eq) goto loc_8228213C;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x822820A0;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228213c
	if (cr6.eq) goto loc_8228213C;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228213c
	if (cr6.eq) goto loc_8228213C;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227f438
	ctx.lr = 0x822820C0;
	sub_8227F438(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227f438
	ctx.lr = 0x822820D0;
	sub_8227F438(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// li r28,31
	r28.s64 = 31;
loc_822820DC:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82282130
	if (cr6.eq) goto loc_82282130;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82282130
	if (!cr6.eq) goto loc_82282130;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x822820FC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282130
	if (cr6.eq) goto loc_82282130;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82282114;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82282130
	if (cr6.eq) goto loc_82282130;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82281a90
	ctx.lr = 0x82282130;
	sub_82281A90(ctx, base);
loc_82282130:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x822820dc
	if (!cr0.eq) goto loc_822820DC;
loc_8228213C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82282144"))) PPC_WEAK_FUNC(sub_82282144);
PPC_FUNC_IMPL(__imp__sub_82282144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82282148"))) PPC_WEAK_FUNC(sub_82282148);
PPC_FUNC_IMPL(__imp__sub_82282148) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x82282150;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32122
	ctx.r8.s64 = -2105147392;
	// lis r7,23772
	ctx.r7.s64 = 1557921792;
	// addi r6,r8,2176
	ctx.r6.s64 = ctx.r8.s64 + 2176;
	// ori r5,r7,64167
	ctx.r5.u64 = ctx.r7.u64 | 64167;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,2176(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 2176);
	// lwz r11,4(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r10,r4,r5
	ctx.r10.s64 = ctx.r4.s64 * ctx.r5.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// rldicl r9,r11,32,32
	ctx.r9.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,2176(r8)
	PPC_STORE_U32(ctx.r8.u32 + 2176, r11.u32);
	// clrlwi r3,r11,1
	ctx.r3.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r9,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r9.u32);
	// srawi r11,r3,1
	xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	r11.s64 = ctx.r3.s32 >> 1;
	// addze r10,r11
	temp.s64 = r11.s64 + xer.ca;
	xer.ca = temp.u32 < r11.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r9,r3
	r11.s64 = ctx.r3.s64 - ctx.r9.s64;
	// addi r27,r11,1
	r27.s64 = r11.s64 + 1;
	// bl 0x82387b90
	ctx.lr = 0x822821A0;
	sub_82387B90(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r8,1344(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 1344);
	// mulli r11,r8,8176
	r11.s64 = ctx.r8.s64 * 8176;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// addi r29,r11,1360
	r29.s64 = r11.s64 + 1360;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8238f998
	ctx.lr = 0x822821BC;
	sub_8238F998(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82280430
	ctx.lr = 0x822821CC;
	sub_82280430(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r11,-1
	r11.s64 = -1;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// lfs f0,14192(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stb r6,14(r31)
	PPC_STORE_U8(r31.u32 + 14, ctx.r6.u8);
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// bl 0x82388580
	ctx.lr = 0x822821F8;
	sub_82388580(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x82282208;
	sub_82270170(ctx, base);
	// addic. r3,r3,112
	xer.ca = ctx.r3.u32 > 4294967183;
	ctx.r3.s64 = ctx.r3.s64 + 112;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq 0x82282214
	if (cr0.eq) goto loc_82282214;
	// bl 0x82273218
	ctx.lr = 0x82282214;
	sub_82273218(ctx, base);
loc_82282214:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228221C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228222C;
	sub_82270170(ctx, base);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,279(r3)
	PPC_STORE_U8(ctx.r3.u32 + 279, ctx.r10.u8);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228223C;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228224C;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x82282258;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r26,4(r28)
	r26.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// bl 0x82388580
	ctx.lr = 0x82282264;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282274;
	sub_82270170(ctx, base);
	// li r4,21
	ctx.r4.s64 = 21;
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// bl 0x82274120
	ctx.lr = 0x82282280;
	sub_82274120(ctx, base);
	// lwz r7,48(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 48);
	// rlwinm r6,r7,0,16,23
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFF00;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822822bc
	if (cr6.eq) goto loc_822822BC;
	// lwz r3,12(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// bl 0x82396408
	ctx.lr = 0x82282298;
	sub_82396408(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822822A4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822822B4;
	sub_82270170(ctx, base);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// b 0x822822ec
	goto loc_822822EC;
loc_822822BC:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822822C4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r28,-10240(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r26,4(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8238f1e8
	ctx.lr = 0x822822D8;
	sub_8238F1E8(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82270170
	ctx.lr = 0x822822E8;
	sub_82270170(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
loc_822822EC:
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82274120
	ctx.lr = 0x822822F4;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822822FC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r28,r10,9000
	r28.s64 = ctx.r10.s64 + 9000;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282314;
	sub_82270170(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82272d48
	ctx.lr = 0x82282320;
	sub_82272D48(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282328;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282338;
	sub_82270170(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82282344;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228234C;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228235C;
	sub_82270170(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274128
	ctx.lr = 0x82282368;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282370;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282380;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8228238C;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282394;
	sub_82388580(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822823A4;
	sub_82270170(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x822823B0;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822823B8;
	sub_82388580(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822823C8;
	sub_82270170(ctx, base);
	// li r4,7
	ctx.r4.s64 = 7;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x822823D4;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822823DC;
	sub_82388580(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822823EC;
	sub_82270170(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x822823F8;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282400;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282410;
	sub_82270170(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x8228241C;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282424;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282434;
	sub_82270170(ctx, base);
	// li r4,10
	ctx.r4.s64 = 10;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x82282440;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282448;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282458;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82282464;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228246C;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228247C;
	sub_82270170(ctx, base);
	// li r4,13
	ctx.r4.s64 = 13;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82282488;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282490;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822824A0;
	sub_82270170(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82274128
	ctx.lr = 0x822824AC;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r30,1316(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + 1316);
	// bl 0x82388580
	ctx.lr = 0x822824B8;
	sub_82388580(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822824C8;
	sub_82270170(ctx, base);
	// li r4,16
	ctx.r4.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274128
	ctx.lr = 0x822824D4;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822824DC;
	sub_82388580(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822824EC;
	sub_82270170(ctx, base);
	// li r4,17
	ctx.r4.s64 = 17;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x822824F8;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282500;
	sub_82388580(ctx, base);
	// lwz r28,4(r3)
	r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r30,-10240(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x8238f6b0
	ctx.lr = 0x82282510;
	sub_8238F6B0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82270170
	ctx.lr = 0x82282520;
	sub_82270170(ctx, base);
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x82274128
	ctx.lr = 0x8228252C;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282534;
	sub_82388580(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r4)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282544;
	sub_82270170(ctx, base);
	// li r4,19
	ctx.r4.s64 = 19;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x82282550;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282558;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282568;
	sub_82270170(ctx, base);
	// li r4,20
	ctx.r4.s64 = 20;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x82282574;
	sub_82274120(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_8228257C"))) PPC_WEAK_FUNC(sub_8228257C);
PPC_FUNC_IMPL(__imp__sub_8228257C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82282580"))) PPC_WEAK_FUNC(sub_82282580);
PPC_FUNC_IMPL(__imp__sub_82282580) {
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
	ctx.lr = 0x82282588;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// bl 0x823896c0
	ctx.lr = 0x8228259C;
	sub_823896C0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x8238eb20
	ctx.lr = 0x822825A4;
	sub_8238EB20(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,-3624(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x822825B4;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228274c
	if (cr6.eq) goto loc_8228274C;
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8228267c
	if (!cr6.eq) goto loc_8228267C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x822825D8;
	sub_8226B2F0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822825E0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822825F8;
	sub_82270170(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// bl 0x82272d48
	ctx.lr = 0x82282604;
	sub_82272D48(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228260C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228261C;
	sub_82270170(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82274128
	ctx.lr = 0x82282628;
	sub_82274128(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282630;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282640;
	sub_82270170(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82274128
	ctx.lr = 0x8228264C;
	sub_82274128(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82280ad8
	ctx.lr = 0x82282654;
	sub_82280AD8(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82282780
	if (cr6.eq) goto loc_82282780;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lbz r5,13(r29)
	ctx.r5.u64 = PPC_LOAD_U8(r29.u32 + 13);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82280da8
	ctx.lr = 0x82282674;
	sub_82280DA8(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8228267C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82282690;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822801f0
	ctx.lr = 0x8228269C;
	sub_822801F0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82282780
	if (cr6.eq) goto loc_82282780;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82282780
	if (cr6.eq) goto loc_82282780;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822826C0;
	sub_82295F70(ctx, base);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822826D0;
	sub_82295F70(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822826E0;
	sub_82295F70(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r30,r10,3
	r30.s64 = ctx.r10.s64 + 196608;
	// addi r30,r30,-16384
	r30.s64 = r30.s64 + -16384;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82654d90
	ctx.lr = 0x822826FC;
	sub_82654D90(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82282738
	if (cr6.eq) goto loc_82282738;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,-6148(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// bl 0x82655ff8
	ctx.lr = 0x82282718;
	sub_82655FF8(ctx, base);
	// mulli r11,r3,1056
	r11.s64 = ctx.r3.s64 * 1056;
	// add r11,r11,r30
	r11.u64 = r11.u64 + r30.u64;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r11,11984
	ctx.r5.s64 = r11.s64 + 11984;
	// bl 0x8227fbc0
	ctx.lr = 0x82282730;
	sub_8227FBC0(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82282738:
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295828
	ctx.lr = 0x82282744;
	sub_82295828(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_8228274C:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r9,4304(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// stw r30,984(r8)
	PPC_STORE_U32(ctx.r8.u32 + 984, r30.u32);
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r7,4304(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// stw r28,528(r6)
	PPC_STORE_U32(ctx.r6.u32 + 528, r28.u32);
	// lwz r11,-10240(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10240);
	// lwz r5,4304(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 4304);
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// stw r27,1136(r4)
	PPC_STORE_U32(ctx.r4.u32 + 1136, r27.u32);
loc_82282780:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82282788"))) PPC_WEAK_FUNC(sub_82282788);
PPC_FUNC_IMPL(__imp__sub_82282788) {
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
	ctx.lr = 0x82282790;
	// stfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -80, f30.u64);
	// stfd f31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, f31.u64);
	// stwu r1,-1232(r1)
	ea = -1232 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// bne cr6,0x822827b4
	if (!cr6.eq) goto loc_822827B4;
	// li r4,10
	ctx.r4.s64 = 10;
	// b 0x82282c18
	goto loc_82282C18;
loc_822827B4:
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r29,r11,-12068
	r29.s64 = r11.s64 + -12068;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addi r31,r11,4
	r31.s64 = r11.s64 + 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x822827D8;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,312(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 312);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822827E8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// li r26,1
	r26.s64 = 1;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822828a8
	if (cr6.eq) goto loc_822828A8;
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
	ctx.lr = 0x82282818;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82282898
	if (!cr6.eq) goto loc_82282898;
	// bl 0x82207e88
	ctx.lr = 0x82282828;
	sub_82207E88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82282898
	if (!cr6.eq) goto loc_82282898;
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82282874
	if (!cr6.eq) goto loc_82282874;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2012
	ctx.r4.s64 = r11.s64 + -2012;
	// bl 0x82691650
	ctx.lr = 0x8228285C;
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
	ctx.lr = 0x82282870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822828a8
	goto loc_822828A8;
loc_82282874:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2032
	ctx.r4.s64 = r11.s64 + -2032;
	// bl 0x82691650
	ctx.lr = 0x82282880;
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
	ctx.lr = 0x82282894;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x822828a8
	goto loc_822828A8;
loc_82282898:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82691650
	ctx.lr = 0x822828A4;
	sub_82691650(ctx, base);
	// stb r26,103(r3)
	PPC_STORE_U8(ctx.r3.u32 + 103, r26.u8);
loc_822828A8:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x822828BC;
	sub_822701C8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r3,r10,15900
	ctx.r3.s64 = ctx.r10.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x822828CC;
	sub_82293F60(ctx, base);
	// lwz r3,-3624(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b330
	ctx.lr = 0x822828D8;
	sub_8226B330(ctx, base);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x82282c14
	if (cr6.eq) goto loc_82282C14;
	// lwz r11,24(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82282c14
	if (!cr6.eq) goto loc_82282C14;
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82282c14
	if (cr6.eq) goto loc_82282C14;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227e038
	ctx.lr = 0x82282904;
	sub_8227E038(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282c14
	if (cr6.eq) goto loc_82282C14;
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// fsubs f0,f31,f30
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - f30.f64));
	// lwz r11,36(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f13,16(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x82282c14
	if (!cr6.gt) goto loc_82282C14;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x82282938;
	sub_822A3998(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282944;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282954;
	sub_82270170(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// li r5,-1
	ctx.r5.s64 = -1;
	// bl 0x82274120
	ctx.lr = 0x82282960;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282968;
	sub_82388580(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282978;
	sub_82270170(ctx, base);
	// li r4,19
	ctx.r4.s64 = 19;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274120
	ctx.lr = 0x82282984;
	sub_82274120(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228298C;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228299C;
	sub_82270170(ctx, base);
	// li r4,12
	ctx.r4.s64 = 12;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x822829A8;
	sub_82274128(ctx, base);
	// stw r26,24(r27)
	PPC_STORE_U32(r27.u32 + 24, r26.u32);
	// bl 0x822919d8
	ctx.lr = 0x822829B0;
	sub_822919D8(ctx, base);
	// lwz r7,16(r27)
	ctx.r7.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne cr6,0x82282a24
	if (!cr6.eq) goto loc_82282A24;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x822829C4;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282a24
	if (cr6.eq) goto loc_82282A24;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227f438
	ctx.lr = 0x822829DC;
	sub_8227F438(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227f438
	ctx.lr = 0x822829EC;
	sub_8227F438(ctx, base);
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822829F8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// addi r29,r1,92
	r29.s64 = ctx.r1.s64 + 92;
	// addi r28,r1,88
	r28.s64 = ctx.r1.s64 + 88;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282A10;
	sub_82270170(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82281a90
	ctx.lr = 0x82282A24;
	sub_82281A90(ctx, base);
loc_82282A24:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,34
	ctx.r4.s64 = 34;
	// bl 0x8268ee10
	ctx.lr = 0x82282A38;
	sub_8268EE10(ctx, base);
	// lwz r3,880(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 880);
	// lwz r11,84(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 84);
	// lwz r10,784(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 784);
	// cmpwi cr6,r10,13
	cr6.compare<int32_t>(ctx.r10.s32, 13, xer);
	// bne cr6,0x82282a74
	if (!cr6.eq) goto loc_82282A74;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r5,-1
	ctx.r5.s64 = -1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f1,-17424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -17424);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822afcd0
	ctx.lr = 0x82282A60;
	sub_822AFCD0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a5578
	ctx.lr = 0x82282A68;
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
loc_82282A74:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0498
	ctx.lr = 0x82282A7C;
	sub_824F0498(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82295538
	ctx.lr = 0x82282A8C;
	sub_82295538(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82295e90
	ctx.lr = 0x82282A98;
	sub_82295E90(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lis r29,-32115
	r29.s64 = -2104688640;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bne cr6,0x82282b9c
	if (!cr6.eq) goto loc_82282B9C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282AB4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282AC4;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82282ACC;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0570
	ctx.lr = 0x82282AD8;
	sub_824F0570(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282b9c
	if (cr6.eq) goto loc_82282B9C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282AEC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282AFC;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x82282b9c
	if (cr6.eq) goto loc_82282B9C;
	// lwz r3,-12440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,808
	ctx.r4.s64 = r11.s64 + 808;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82282B2C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282B34;
	sub_82388580(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282B44;
	sub_82270170(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,208(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// bl 0x82296dd8
	ctx.lr = 0x82282B50;
	sub_82296DD8(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82282b9c
	if (cr6.eq) goto loc_82282B9C;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82250410
	ctx.lr = 0x82282B64;
	sub_82250410(ctx, base);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8227fca0
	ctx.lr = 0x82282B74;
	sub_8227FCA0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82282b9c
	if (!cr6.gt) goto loc_82282B9C;
	// addi r3,r30,16
	ctx.r3.s64 = r30.s64 + 16;
	// bl 0x824e7118
	ctx.lr = 0x82282B84;
	sub_824E7118(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-6148(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -6148);
	// addi r3,r11,11984
	ctx.r3.s64 = r11.s64 + 11984;
	// bl 0x82251260
	ctx.lr = 0x82282B9C;
	sub_82251260(ctx, base);
loc_82282B9C:
	// lwz r11,16(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82282c28
	if (!cr6.eq) goto loc_82282C28;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282BB0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82282BC0;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x82282BC8;
	sub_82502300(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x824f0570
	ctx.lr = 0x82282BD4;
	sub_824F0570(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282c28
	if (cr6.eq) goto loc_82282C28;
	// lwz r3,-12440(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -12440);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r11,800
	ctx.r4.s64 = r11.s64 + 800;
	// li r5,4
	ctx.r5.s64 = 4;
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,48(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82282C04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
loc_82282C14:
	// li r4,3
	ctx.r4.s64 = 3;
loc_82282C18:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// bl 0x8268ee10
	ctx.lr = 0x82282C28;
	sub_8268EE10(ctx, base);
loc_82282C28:
	// addi r1,r1,1232
	ctx.r1.s64 = ctx.r1.s64 + 1232;
	// lfd f30,-80(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82282C38"))) PPC_WEAK_FUNC(sub_82282C38);
PPC_FUNC_IMPL(__imp__sub_82282C38) {
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
	ctx.lr = 0x82282C40;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r25,r6
	r25.u64 = ctx.r6.u64;
	// bl 0x8227e038
	ctx.lr = 0x82282C58;
	sub_8227E038(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282c74
	if (cr6.eq) goto loc_82282C74;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,15764(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 15764);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82282eac
	if (!cr6.eq) goto loc_82282EAC;
loc_82282C74:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82282eac
	if (cr6.eq) goto loc_82282EAC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82282C90;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82293eb0
	ctx.lr = 0x82282C9C;
	sub_82293EB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282eac
	if (cr6.eq) goto loc_82282EAC;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// stw r25,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r25.u32);
	// bne cr6,0x82282cdc
	if (!cr6.eq) goto loc_82282CDC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82282CBC;
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
	ctx.lr = 0x82282CD0;
	sub_82270170(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82282CDC;
	sub_82274128(ctx, base);
loc_82282CDC:
	// lis r26,-32115
	r26.s64 = -2104688640;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lwz r11,-12672(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -12672);
	// subf r10,r27,r11
	ctx.r10.s64 = r11.s64 - r27.s64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82282d20
	if (!cr6.eq) goto loc_82282D20;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x82389668
	ctx.lr = 0x82282D14;
	sub_82389668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282eac
	if (cr6.eq) goto loc_82282EAC;
loc_82282D20:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82282d34
	if (cr6.eq) goto loc_82282D34;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r29,-28256(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + -28256);
	// b 0x82282d48
	goto loc_82282D48;
loc_82282D34:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,36(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r29,r8,r9
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
loc_82282D48:
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82282d78
	if (cr6.eq) goto loc_82282D78;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82282eac
	if (!cr6.eq) goto loc_82282EAC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293eb0
	ctx.lr = 0x82282D6C;
	sub_82293EB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282eac
	if (cr6.eq) goto loc_82282EAC;
loc_82282D78:
	// li r30,0
	r30.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82291968
	ctx.lr = 0x82282D8C;
	sub_82291968(ctx, base);
	// lbz r11,14(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 14);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282dac
	if (cr6.eq) goto loc_82282DAC;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82282788
	ctx.lr = 0x82282DA0;
	sub_82282788(ctx, base);
	// stb r30,14(r31)
	PPC_STORE_U8(r31.u32 + 14, r30.u8);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82282DAC:
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82282e98
	if (!cr6.eq) goto loc_82282E98;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x822090b8
	ctx.lr = 0x82282DC8;
	sub_822090B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282e98
	if (cr6.eq) goto loc_82282E98;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x82282DE4;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282e98
	if (cr6.eq) goto loc_82282E98;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,36(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// bl 0x8227e5a0
	ctx.lr = 0x82282DFC;
	sub_8227E5A0(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r31,-10244(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x823896c0
	ctx.lr = 0x82282E18;
	sub_823896C0(ctx, base);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// rlwinm r9,r3,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-27892
	ctx.r8.s64 = ctx.r10.s64 + -27892;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwzx r4,r9,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// bl 0x82218310
	ctx.lr = 0x82282E30;
	sub_82218310(ctx, base);
	// lwz r11,-12672(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -12672);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplw cr6,r27,r11
	cr6.compare<uint32_t>(r27.u32, r11.u32, xer);
	// bne cr6,0x82282e48
	if (!cr6.eq) goto loc_82282E48;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r11,3998
	r31.s64 = r11.s64 + 3998;
loc_82282E48:
	// lwz r11,-10236(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10236);
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r30,-10244(r30)
	r30.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r11,1
	ctx.r3.s64 = r11.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x82282E64;
	sub_82641CB0(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r10,15768
	ctx.r4.s64 = ctx.r10.s64 + 15768;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82218310
	ctx.lr = 0x82282E78;
	sub_82218310(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r28,16
	ctx.r4.s64 = r28.s64 + 16;
	// addi r3,r29,2832
	ctx.r3.s64 = r29.s64 + 2832;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x8264f2f8
	ctx.lr = 0x82282E90;
	sub_8264F2F8(ctx, base);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82282E98:
	// li r6,-1
	ctx.r6.s64 = -1;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,3
	ctx.r5.s64 = 3;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x8268ee10
	ctx.lr = 0x82282EAC;
	sub_8268EE10(ctx, base);
loc_82282EAC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82282EB4"))) PPC_WEAK_FUNC(sub_82282EB4);
PPC_FUNC_IMPL(__imp__sub_82282EB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82282EB8"))) PPC_WEAK_FUNC(sub_82282EB8);
PPC_FUNC_IMPL(__imp__sub_82282EB8) {
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
	ctx.lr = 0x82282EC0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82282EDC;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283114
	if (cr6.eq) goto loc_82283114;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r3,-3624(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x82282EF4;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293e18
	ctx.lr = 0x82282F08;
	sub_82293E18(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822952b0
	ctx.lr = 0x82282F14;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x82282F30;
	sub_82295538(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,9000
	ctx.r4.s64 = r11.s64 + 9000;
	// bl 0x82293e78
	ctx.lr = 0x82282F48;
	sub_82293E78(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82282F60;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293eb0
	ctx.lr = 0x82282F6C;
	sub_82293EB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lbz r10,15764(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 15764);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82282fdc
	if (!cr6.eq) goto loc_82282FDC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x824f0498
	ctx.lr = 0x82282F90;
	sub_824F0498(ctx, base);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295538
	ctx.lr = 0x82282FA0;
	sub_82295538(ctx, base);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e670
	ctx.lr = 0x82282FAC;
	sub_8227E670(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82282fdc
	if (cr6.eq) goto loc_82282FDC;
	// lwz r30,136(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 136);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r27,r1,80
	r27.s64 = ctx.r1.s64 + 80;
	// bl 0x82295e90
	ctx.lr = 0x82282FC8;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82282c38
	ctx.lr = 0x82282FDC;
	sub_82282C38(ctx, base);
loc_82282FDC:
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x82282FE8;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283074
	if (cr6.eq) goto loc_82283074;
	// lbz r7,102(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 102);
	// li r8,255
	ctx.r8.s64 = 255;
	// lbz r5,97(r1)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r1.u32 + 97);
	// li r11,0
	r11.s64 = 0;
	// ori r4,r7,128
	ctx.r4.u64 = ctx.r7.u64 | 128;
	// lbz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 100);
	// stb r8,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, ctx.r8.u8);
	// ori r9,r5,224
	ctx.r9.u64 = ctx.r5.u64 | 224;
	// clrlwi r10,r4,24
	ctx.r10.u64 = ctx.r4.u32 & 0xFF;
	// stb r11,101(r1)
	PPC_STORE_U8(ctx.r1.u32 + 101, r11.u8);
	// clrlwi r3,r6,25
	ctx.r3.u64 = ctx.r6.u32 & 0x7F;
	// stw r11,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r11.u32);
	// ori r8,r10,64
	ctx.r8.u64 = ctx.r10.u64 | 64;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r11.u32);
	// stb r3,100(r1)
	PPC_STORE_U8(ctx.r1.u32 + 100, ctx.r3.u8);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, r11.u32);
	// li r4,18
	ctx.r4.s64 = 18;
	// stb r9,97(r1)
	PPC_STORE_U8(ctx.r1.u32 + 97, ctx.r9.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, r11.u8);
	// stb r11,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r11.u8);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r11.u32);
	// stb r8,102(r1)
	PPC_STORE_U8(ctx.r1.u32 + 102, ctx.r8.u8);
	// bl 0x82295538
	ctx.lr = 0x82283058;
	sub_82295538(ctx, base);
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,-10236(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -10236);
	// lwz r6,48(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r6,3
	ctx.r3.s64 = ctx.r6.s64 + 196608;
	// addi r3,r3,-21024
	ctx.r3.s64 = ctx.r3.s64 + -21024;
	// bl 0x8227d1b0
	ctx.lr = 0x82283074;
	sub_8227D1B0(ctx, base);
loc_82283074:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227ebb0
	ctx.lr = 0x8228307C;
	sub_8227EBB0(ctx, base);
	// lwz r11,16(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82283114
	if (cr6.eq) goto loc_82283114;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x82283094;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822830d0
	if (!cr6.eq) goto loc_822830D0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x822830AC;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822830d0
	if (!cr6.eq) goto loc_822830D0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295238
	ctx.lr = 0x822830C4;
	sub_82295238(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283114
	if (cr6.eq) goto loc_82283114;
loc_822830D0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822830D8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r31,-10240(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -10240);
	// lwz r30,4(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8227e750
	ctx.lr = 0x822830EC;
	sub_8227E750(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r31,r8,1
	r31.u64 = ctx.r8.u64 ^ 1;
	// bl 0x82270170
	ctx.lr = 0x82283108;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// bl 0x82274128
	ctx.lr = 0x82283114;
	sub_82274128(ctx, base);
loc_82283114:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_8228311C"))) PPC_WEAK_FUNC(sub_8228311C);
PPC_FUNC_IMPL(__imp__sub_8228311C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82283120"))) PPC_WEAK_FUNC(sub_82283120);
PPC_FUNC_IMPL(__imp__sub_82283120) {
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
	ctx.lr = 0x82283128;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283150
	if (cr6.eq) goto loc_82283150;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82283150;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82283150:
	// lwz r31,8(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822831b4
	if (cr6.eq) goto loc_822831B4;
	// lwz r11,24(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// addi r30,r31,24
	r30.s64 = r31.s64 + 24;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82283174;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r28,r9,-28
	r28.s64 = ctx.r9.s64 + -28;
	// addi r7,r8,68
	ctx.r7.s64 = ctx.r8.s64 + 68;
	// stw r28,120(r31)
	PPC_STORE_U32(r31.u32 + 120, r28.u32);
	// addi r3,r30,52
	ctx.r3.s64 = r30.s64 + 52;
	// stw r7,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r7.u32);
	// stw r28,108(r31)
	PPC_STORE_U32(r31.u32 + 108, r28.u32);
	// bl 0x82130000
	ctx.lr = 0x82283198;
	sub_82130000(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824e6b58
	ctx.lr = 0x822831A0;
	sub_824E6B58(ctx, base);
	// stw r28,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r28.u32);
	// stw r28,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r28.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
	// bl 0x82130588
	ctx.lr = 0x822831B4;
	sub_82130588(ctx, base);
loc_822831B4:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwz r3,64(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 64);
	// addi r31,r29,44
	r31.s64 = r29.s64 + 44;
	// addi r10,r11,-11804
	ctx.r10.s64 = r11.s64 + -11804;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// stw r10,44(r29)
	PPC_STORE_U32(r29.u32 + 44, ctx.r10.u32);
	// beq cr6,0x822831e0
	if (cr6.eq) goto loc_822831E0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bl 0x82270908
	ctx.lr = 0x822831D8;
	sub_82270908(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r11.u32);
loc_822831E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_822831E8"))) PPC_WEAK_FUNC(sub_822831E8);
PPC_FUNC_IMPL(__imp__sub_822831E8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x822831F0;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82283210;
	sub_822701C8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228321C;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228322C;
	sub_82270170(ctx, base);
	// lwz r4,20(r25)
	ctx.r4.u64 = PPC_LOAD_U32(r25.u32 + 20);
	// lwz r31,208(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r4,5
	cr6.compare<int32_t>(ctx.r4.s32, 5, xer);
	// beq cr6,0x8228324c
	if (cr6.eq) goto loc_8228324C;
	// li r11,5
	r11.s64 = 5;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// stw r11,20(r25)
	PPC_STORE_U32(r25.u32 + 20, r11.u32);
	// bl 0x82280430
	ctx.lr = 0x8228324C;
	sub_82280430(ctx, base);
loc_8228324C:
	// lis r22,-32121
	r22.s64 = -2105081856;
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226be68
	ctx.lr = 0x82283258;
	sub_8226BE68(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283650
	if (cr6.eq) goto loc_82283650;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82283650
	if (cr6.eq) goto loc_82283650;
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x82283274;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283650
	if (cr6.eq) goto loc_82283650;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283650
	if (cr6.eq) goto loc_82283650;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82283294;
	sub_8226B2F0(ctx, base);
	// lis r23,-32121
	r23.s64 = -2105081856;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,8920(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + 8920);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// beq cr6,0x82283648
	if (cr6.eq) goto loc_82283648;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x822832B4;
	sub_8226B2F0(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,16(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stw r11,8920(r23)
	PPC_STORE_U32(r23.u32 + 8920, r11.u32);
	// bne cr6,0x822832f0
	if (!cr6.eq) goto loc_822832F0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82280ad8
	ctx.lr = 0x822832D0;
	sub_82280AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822832f0
	if (cr6.eq) goto loc_822832F0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lfs f1,7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82280da8
	ctx.lr = 0x822832F0;
	sub_82280DA8(ctx, base);
loc_822832F0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8227e750
	ctx.lr = 0x822832F8;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// lis r10,21845
	ctx.r10.s64 = 1431633920;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// ori r26,r10,21846
	r26.u64 = ctx.r10.u64 | 21846;
	// beq cr6,0x822833a8
	if (cr6.eq) goto loc_822833A8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82283314;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822833a8
	if (cr6.eq) goto loc_822833A8;
	// lwz r11,24(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82283334
	if (cr6.eq) goto loc_82283334;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822833a8
	if (!cr6.eq) goto loc_822833A8;
loc_82283334:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293f60
	ctx.lr = 0x82283340;
	sub_82293F60(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r22)
	ctx.r4.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x82283350;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82283354;
	sub_82293F60(ctx, base);
	// fsubs f0,f31,f1
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f31.f64 - ctx.f1.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r9,92(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// mulhw r11,r9,r26
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(r26.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// subf. r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne 0x822833a8
	if (!cr0.eq) goto loc_822833A8;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x82283388;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822833a0
	if (!cr6.eq) goto loc_822833A0;
	// lwz r11,16(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822833a8
	if (!cr6.eq) goto loc_822833A8;
loc_822833A0:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82282050
	ctx.lr = 0x822833A8;
	sub_82282050(ctx, base);
loc_822833A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822833B0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822833C0;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822833C8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283538
	if (cr6.eq) goto loc_82283538;
	// bl 0x82256058
	ctx.lr = 0x822833D4;
	sub_82256058(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82283450
	if (cr6.eq) goto loc_82283450;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x822833EC;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82283450
	if (!cr6.eq) goto loc_82283450;
	// addic. r31,r30,8
	xer.ca = r30.u32 > 4294967287;
	r31.s64 = r30.s64 + 8;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x82283538
	if (cr0.eq) goto loc_82283538;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82283408;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r30,3080(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 3080);
	// bne cr6,0x82283434
	if (!cr6.eq) goto loc_82283434;
	// bl 0x823eaef8
	ctx.lr = 0x8228341C;
	sub_823EAEF8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82263f60
	ctx.lr = 0x8228342C;
	sub_82263F60(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x8228350c
	goto loc_8228350C;
loc_82283434:
	// bl 0x823eaef8
	ctx.lr = 0x82283438;
	sub_823EAEF8(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// bl 0x82263c28
	ctx.lr = 0x82283448;
	sub_82263C28(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// b 0x8228350c
	goto loc_8228350C;
loc_82283450:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228345C;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,8
	cr6.compare<uint32_t>(ctx.r3.u32, 8, xer);
	// blt cr6,0x82283538
	if (cr6.lt) goto loc_82283538;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82283470;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,13
	cr6.compare<uint32_t>(ctx.r3.u32, 13, xer);
	// bgt cr6,0x82283538
	if (cr6.gt) goto loc_82283538;
	// li r3,0
	ctx.r3.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// bl 0x82388580
	ctx.lr = 0x82283484;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82283494;
	sub_82270170(ctx, base);
	// li r4,6
	ctx.r4.s64 = 6;
	// bl 0x822051a0
	ctx.lr = 0x8228349C;
	sub_822051A0(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// addi r30,r31,12
	r30.s64 = r31.s64 + 12;
	// li r29,31
	r29.s64 = 31;
loc_822834A8:
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283500
	if (cr6.eq) goto loc_82283500;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82203310
	ctx.lr = 0x822834BC;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283500
	if (cr6.eq) goto loc_82283500;
	// lbz r11,278(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82283500
	if (!cr6.eq) goto loc_82283500;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x822834E0;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283500
	if (cr6.eq) goto loc_82283500;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x822834F4;
	sub_822051A0(ctx, base);
	// cmpw cr6,r27,r3
	cr6.compare<int32_t>(r27.s32, ctx.r3.s32, xer);
	// bge cr6,0x82283500
	if (!cr6.lt) goto loc_82283500;
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
loc_82283500:
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// bne 0x822834a8
	if (!cr0.eq) goto loc_822834A8;
loc_8228350C:
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// beq cr6,0x82283538
	if (cr6.eq) goto loc_82283538;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228351C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228352C;
	sub_82270170(ctx, base);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x82274128
	ctx.lr = 0x82283538;
	sub_82274128(ctx, base);
loc_82283538:
	// lwz r11,16(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822835cc
	if (!cr6.eq) goto loc_822835CC;
	// lwz r9,8920(r23)
	ctx.r9.u64 = PPC_LOAD_U32(r23.u32 + 8920);
	// mulhw r11,r9,r26
	r11.s64 = (int64_t(ctx.r9.s32) * int64_t(r26.s32)) >> 32;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0x1;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// subf. r7,r8,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r8.s64;
	cr0.compare<int32_t>(ctx.r7.s32, 0, xer);
	// bne 0x822835cc
	if (!cr0.eq) goto loc_822835CC;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f1,32(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r25.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// ble cr6,0x822835cc
	if (!cr6.gt) goto loc_822835CC;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82293e30
	ctx.lr = 0x82283580;
	sub_82293E30(ctx, base);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82293eb0
	ctx.lr = 0x8228358C;
	sub_82293EB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822835cc
	if (cr6.eq) goto loc_822835CC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82280ad8
	ctx.lr = 0x822835A0;
	sub_82280AD8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822835b8
	if (cr6.eq) goto loc_822835B8;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82280e38
	ctx.lr = 0x822835B4;
	sub_82280E38(ctx, base);
	// b 0x822835c0
	goto loc_822835C0;
loc_822835B8:
	// li r11,0
	r11.s64 = 0;
	// stb r11,14(r25)
	PPC_STORE_U8(r25.u32 + 14, r11.u8);
loc_822835C0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	f0.f64 = double(temp.f32);
	// stfs f0,32(r25)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r25.u32 + 32, temp.u32);
loc_822835CC:
	// lwz r11,-10240(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x824fb3f8
	ctx.lr = 0x822835D8;
	sub_824FB3F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82283648
	if (!cr6.eq) goto loc_82283648;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822835EC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822835FC;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82283604;
	sub_82272A30(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283648
	if (cr6.eq) goto loc_82283648;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82283614;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82283624;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228362C;
	sub_82272A30(ctx, base);
	// bl 0x824815a0
	ctx.lr = 0x82283630;
	sub_824815A0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82283648
	if (cr6.eq) goto loc_82283648;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-3624(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -3624);
	// bl 0x8226c5b0
	ctx.lr = 0x82283648;
	sub_8226C5B0(ctx, base);
loc_82283648:
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8227df10
	ctx.lr = 0x82283650;
	sub_8227DF10(ctx, base);
loc_82283650:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_8228365C"))) PPC_WEAK_FUNC(sub_8228365C);
PPC_FUNC_IMPL(__imp__sub_8228365C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82283660"))) PPC_WEAK_FUNC(sub_82283660);
PPC_FUNC_IMPL(__imp__sub_82283660) {
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
	ctx.lr = 0x82283668;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lis r11,-32122
	r11.s64 = -2105147392;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// ori r26,r10,64167
	r26.u64 = ctx.r10.u64 | 64167;
	// addi r29,r11,2176
	r29.s64 = r11.s64 + 2176;
loc_82283688:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// li r31,0
	r31.s64 = 0;
	// li r30,0
	r30.s64 = 0;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x822837ac
	if (!cr6.gt) goto loc_822837AC;
loc_822836A0:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8227e4b8
	ctx.lr = 0x822836B0;
	sub_8227E4B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822836c0
	if (cr6.eq) goto loc_822836C0;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_822836C0:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x822836a0
	if (cr6.lt) goto loc_822836A0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822837ac
	if (cr6.eq) goto loc_822837AC;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// twllei r31,0
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r30,0
	r30.s64 = 0;
	// mulld r11,r11,r26
	r11.s64 = r11.s64 * r26.s64;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// clrlwi r8,r11,1
	ctx.r8.u64 = r11.u32 & 0x7FFFFFFF;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// rldicl r11,r11,32,32
	r11.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// rotlwi r9,r8,1
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 1);
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// divw r7,r8,r31
	ctx.r7.s32 = ctx.r8.s32 / r31.s32;
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r6,r9,-1
	ctx.r6.s64 = ctx.r9.s64 + -1;
	// mullw r5,r7,r31
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(r31.s32);
	// andc r4,r31,r6
	ctx.r4.u64 = r31.u64 & ~ctx.r6.u64;
	// subf r27,r5,r8
	r27.s64 = ctx.r8.s64 - ctx.r5.s64;
	// twlgei r4,-1
	// li r31,0
	r31.s64 = 0;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x82283688
	if (!cr6.gt) goto loc_82283688;
loc_82283738:
	// mr r6,r24
	ctx.r6.u64 = r24.u64;
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8227e4b8
	ctx.lr = 0x82283748;
	sub_8227E4B8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283760
	if (cr6.eq) goto loc_82283760;
	// cmplw cr6,r27,r31
	cr6.compare<uint32_t>(r27.u32, r31.u32, xer);
	// beq cr6,0x82283778
	if (cr6.eq) goto loc_82283778;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_82283760:
	// lwz r3,4(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r11,32(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x82283738
	if (cr6.lt) goto loc_82283738;
	// b 0x82283688
	goto loc_82283688;
loc_82283778:
	// lwz r11,4(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// rlwinm r10,r30,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwzx r3,r10,r9
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x821c9790
	ctx.lr = 0x82283790;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82282580
	ctx.lr = 0x822837A0;
	sub_82282580(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_822837AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_822837B8"))) PPC_WEAK_FUNC(sub_822837B8);
PPC_FUNC_IMPL(__imp__sub_822837B8) {
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
	ctx.lr = 0x822837C0;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r24,r5
	r24.u64 = ctx.r5.u64;
	// mr r22,r6
	r22.u64 = ctx.r6.u64;
	// mr r23,r7
	r23.u64 = ctx.r7.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x823896c0
	ctx.lr = 0x822837E0;
	sub_823896C0(ctx, base);
	// bl 0x8238eb20
	ctx.lr = 0x822837E4;
	sub_8238EB20(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// bl 0x8227e5a0
	ctx.lr = 0x822837F4;
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
	ctx.lr = 0x8228380C;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8227e750
	ctx.lr = 0x82283818;
	sub_8227E750(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,4
	cr6.compare<int32_t>(r11.s32, 4, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,-3624(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82283848;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x82293eb0
	ctx.lr = 0x82283854;
	sub_82293EB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x82283898
	if (cr6.eq) goto loc_82283898;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82283a18
	if (!cr6.eq) goto loc_82283A18;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// addi r3,r11,15900
	ctx.r3.s64 = r11.s64 + 15900;
	// bl 0x82293eb0
	ctx.lr = 0x8228388C;
	sub_82293EB0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82283a18
	if (cr6.eq) goto loc_82283A18;
loc_82283898:
	// addi r3,r28,16
	ctx.r3.s64 = r28.s64 + 16;
	// bl 0x82502300
	ctx.lr = 0x822838A0;
	sub_82502300(ctx, base);
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x823896c0
	ctx.lr = 0x822838B4;
	sub_823896C0(ctx, base);
	// lwz r10,16(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82283978
	if (!cr6.eq) goto loc_82283978;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r10,r27,-2
	ctx.r10.s64 = r27.s64 + -2;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r28,r8,3
	r28.s64 = ctx.r8.s64 + 196608;
	// addi r28,r28,-21024
	r28.s64 = r28.s64 + -21024;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x823974a8
	ctx.lr = 0x822838EC;
	sub_823974A8(ctx, base);
	// li r4,17
	ctx.r4.s64 = 17;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x822838F8;
	sub_82295E90(ctx, base);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295bc8
	ctx.lr = 0x8228390C;
	sub_82295BC8(ctx, base);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// li r28,0
	r28.s64 = 0;
	// lwz r11,-12672(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + -12672);
	// cmplw cr6,r29,r11
	cr6.compare<uint32_t>(r29.u32, r11.u32, xer);
	// beq cr6,0x82283968
	if (cr6.eq) goto loc_82283968;
	// li r11,-1
	r11.s64 = -1;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82389668
	ctx.lr = 0x82283938;
	sub_82389668(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82283968
	if (cr6.eq) goto loc_82283968;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,44(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// rlwinm r10,r8,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// lbz r6,19(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 19);
	// extsb r28,r6
	r28.s64 = ctx.r6.s8;
loc_82283968:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295d70
	ctx.lr = 0x82283978;
	sub_82295D70(ctx, base);
loc_82283978:
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x82283988;
	sub_82295F70(ctx, base);
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x82283998;
	sub_82295F70(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822839A8;
	sub_82295F70(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295bc8
	ctx.lr = 0x822839B8;
	sub_82295BC8(ctx, base);
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295828
	ctx.lr = 0x822839C4;
	sub_82295828(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295f70
	ctx.lr = 0x822839D4;
	sub_82295F70(ctx, base);
	// mr r5,r26
	ctx.r5.u64 = r26.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295bc8
	ctx.lr = 0x822839E4;
	sub_82295BC8(ctx, base);
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// li r4,9
	ctx.r4.s64 = 9;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x82283a00
	if (cr6.eq) goto loc_82283A00;
	// mr r5,r23
	ctx.r5.u64 = r23.u64;
	// bl 0x8227fbc0
	ctx.lr = 0x822839FC;
	sub_8227FBC0(ctx, base);
	// b 0x82283a04
	goto loc_82283A04;
loc_82283A00:
	// bl 0x82295828
	ctx.lr = 0x82283A04;
	sub_82295828(ctx, base);
loc_82283A04:
	// mr r6,r22
	ctx.r6.u64 = r22.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82282c38
	ctx.lr = 0x82283A18;
	sub_82282C38(ctx, base);
loc_82283A18:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82283A20"))) PPC_WEAK_FUNC(sub_82283A20);
PPC_FUNC_IMPL(__imp__sub_82283A20) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82283A28;
	// stwu r1,-1344(r1)
	ea = -1344 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// addi r31,r11,8924
	r31.s64 = r11.s64 + 8924;
	// stw r14,1364(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1364, r14.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r11,8944(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8944);
	// li r26,0
	r26.s64 = 0;
	// clrlwi r9,r11,31
	ctx.r9.u64 = r11.u32 & 0x1;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82283a9c
	if (!cr6.eq) goto loc_82283A9C;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r9,r9,464
	ctx.r9.s64 = ctx.r9.s64 + 464;
	// addi r8,r8,372
	ctx.r8.s64 = ctx.r8.s64 + 372;
	// ori r11,r11,1
	r11.u64 = r11.u64 | 1;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// mr r9,r26
	ctx.r9.u64 = r26.u64;
	// stw r11,8944(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8944, r11.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// mr r11,r26
	r11.u64 = r26.u64;
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// stw r8,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r8.u32);
	// lis r10,-32132
	ctx.r10.s64 = -2105802752;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// addi r3,r10,-29216
	ctx.r3.s64 = ctx.r10.s64 + -29216;
	// bl 0x823d9a98
	ctx.lr = 0x82283A9C;
	sub_823D9A98(ctx, base);
loc_82283A9C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// addi r24,r11,-2628
	r24.s64 = r11.s64 + -2628;
	// addi r22,r30,144
	r22.s64 = r30.s64 + 144;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r22.u32);
	// lwz r3,-10240(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82283ABC;
	sub_822701C8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82295e90
	ctx.lr = 0x82283AC4;
	sub_82295E90(ctx, base);
	// stw r3,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// mr r29,r26
	r29.u64 = r26.u64;
	// bl 0x8227e320
	ctx.lr = 0x82283AD4;
	sub_8227E320(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82283b94
	if (!cr6.gt) goto loc_82283B94;
	// addi r27,r30,12
	r27.s64 = r30.s64 + 12;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// lis r23,-32121
	r23.s64 = -2105081856;
loc_82283AE8:
	// lwz r30,0(r27)
	r30.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82283b7c
	if (cr6.eq) goto loc_82283B7C;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822577d0
	ctx.lr = 0x82283B00;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82283b48
	if (!cr6.eq) goto loc_82283B48;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,17268(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 17268);
	// bl 0x822a3de0
	ctx.lr = 0x82283B14;
	sub_822A3DE0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x82283b7c
	if (cr6.eq) goto loc_82283B7C;
	// lwz r3,17892(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17892);
	// bl 0x822b62a0
	ctx.lr = 0x82283B28;
	sub_822B62A0(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// addi r20,r31,16
	r20.s64 = r31.s64 + 16;
	// bl 0x8227e320
	ctx.lr = 0x82283B38;
	sub_8227E320(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// extsb r5,r21
	ctx.r5.s64 = r21.s8;
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// b 0x82283b70
	goto loc_82283B70;
loc_82283B48:
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// addi r21,r31,16
	r21.s64 = r31.s64 + 16;
	// bl 0x8227e320
	ctx.lr = 0x82283B54;
	sub_8227E320(ctx, base);
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// li r4,14
	ctx.r4.s64 = 14;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822577d0
	ctx.lr = 0x82283B64;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r20
	ctx.r6.u64 = r20.u64;
	// mr r7,r21
	ctx.r7.u64 = r21.u64;
loc_82283B70:
	// addi r4,r30,16
	ctx.r4.s64 = r30.s64 + 16;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82481750
	ctx.lr = 0x82283B7C;
	sub_82481750(ctx, base);
loc_82283B7C:
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bl 0x8227e320
	ctx.lr = 0x82283B8C;
	sub_8227E320(ctx, base);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// blt cr6,0x82283ae8
	if (cr6.lt) goto loc_82283AE8;
loc_82283B94:
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82481590
	ctx.lr = 0x82283B9C;
	sub_82481590(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82283e78
	if (cr6.eq) goto loc_82283E78;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82283BB4;
	sub_8238EC00(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,-10240(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r8,r10,564
	ctx.r8.s64 = ctx.r10.s64 + 564;
	// addi r7,r9,292
	ctx.r7.s64 = ctx.r9.s64 + 292;
	// li r6,-1
	ctx.r6.s64 = -1;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r30,r1,108
	r30.s64 = ctx.r1.s64 + 108;
	// bl 0x822701c8
	ctx.lr = 0x82283BEC;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x82295e90
	ctx.lr = 0x82283BF4;
	sub_82295E90(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x82389668
	ctx.lr = 0x82283C04;
	sub_82389668(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x82283e78
	if (cr6.eq) goto loc_82283E78;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82283C18;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82283C28;
	sub_82270170(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// stw r26,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r26.u32);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lwz r31,208(r10)
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + 208);
	// bl 0x8227e320
	ctx.lr = 0x82283C3C;
	sub_8227E320(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82283e78
	if (!cr6.gt) goto loc_82283E78;
	// addi r11,r31,12
	r11.s64 = r31.s64 + 12;
	// lis r28,4096
	r28.s64 = 268435456;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// lis r5,8192
	ctx.r5.s64 = 536870912;
	// lis r4,4096
	ctx.r4.s64 = 268435456;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// lis r3,4096
	ctx.r3.s64 = 268435456;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r31,4096
	r31.s64 = 268435456;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// ori r23,r28,40
	r23.u64 = r28.u64 | 40;
	// ori r29,r5,44
	r29.u64 = ctx.r5.u64 | 44;
	// ori r30,r4,36
	r30.u64 = ctx.r4.u64 | 36;
	// ori r15,r3,43
	r15.u64 = ctx.r3.u64 | 43;
	// li r21,1
	r21.s64 = 1;
	// li r16,4
	r16.s64 = 4;
	// ori r22,r31,39
	r22.u64 = r31.u64 | 39;
	// li r17,6
	r17.s64 = 6;
	// li r18,15
	r18.s64 = 15;
	// addi r25,r7,820
	r25.s64 = ctx.r7.s64 + 820;
	// addi r28,r6,68
	r28.s64 = ctx.r6.s64 + 68;
	// addi r20,r8,784
	r20.s64 = ctx.r8.s64 + 784;
	// addi r19,r9,212
	r19.s64 = ctx.r9.s64 + 212;
	// addi r24,r10,484
	r24.s64 = ctx.r10.s64 + 484;
	// addi r27,r11,-28
	r27.s64 = r11.s64 + -28;
loc_82283CB4:
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82283e50
	if (cr6.eq) goto loc_82283E50;
	// lwz r11,104(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// cmpwi cr6,r11,8
	cr6.compare<int32_t>(r11.s32, 8, xer);
	// blt cr6,0x82283dd8
	if (cr6.lt) goto loc_82283DD8;
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// bgt cr6,0x82283dd8
	if (cr6.gt) goto loc_82283DD8;
	// lbz r7,648(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 648);
	// lis r9,4096
	ctx.r9.s64 = 268435456;
	// lis r8,4096
	ctx.r8.s64 = 268435456;
	// stw r19,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r19.u32);
	// addi r11,r11,-8
	r11.s64 = r11.s64 + -8;
	// stw r20,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r20.u32);
	// li r6,5
	ctx.r6.s64 = 5;
	// stw r29,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, r29.u32);
	// ori r5,r7,128
	ctx.r5.u64 = ctx.r7.u64 | 128;
	// stw r30,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, r30.u32);
	// ori r4,r9,42
	ctx.r4.u64 = ctx.r9.u64 | 42;
	// stw r15,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, r15.u32);
	// ori r3,r8,41
	ctx.r3.u64 = ctx.r8.u64 | 41;
	// stw r6,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r6.u32);
	// stb r5,648(r1)
	PPC_STORE_U8(ctx.r1.u32 + 648, ctx.r5.u8);
	// cmplwi cr6,r11,5
	cr6.compare<uint32_t>(r11.u32, 5, xer);
	// stw r4,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r4.u32);
	// stw r3,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r3.u32);
	// bgt cr6,0x82283d84
	if (cr6.gt) goto loc_82283D84;
	// lis r12,-32216
	r12.s64 = -2111307776;
	// addi r12,r12,15676
	r12.s64 = r12.s64 + 15676;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82283D54;
	case 1:
		goto loc_82283D64;
	case 2:
		goto loc_82283D5C;
	case 3:
		goto loc_82283D74;
	case 4:
		goto loc_82283D6C;
	case 5:
		goto loc_82283D7C;
	default:
		__builtin_unreachable();
	}
	// lwz r17,15700(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15700);
	// lwz r17,15716(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15716);
	// lwz r17,15708(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15708);
	// lwz r17,15732(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15732);
	// lwz r17,15724(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15724);
	// lwz r17,15740(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + 15740);
loc_82283D54:
	// li r11,7
	r11.s64 = 7;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D5C:
	// li r11,8
	r11.s64 = 8;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D64:
	// li r11,9
	r11.s64 = 9;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D6C:
	// li r11,10
	r11.s64 = 10;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D74:
	// li r11,11
	r11.s64 = 11;
	// b 0x82283d80
	goto loc_82283D80;
loc_82283D7C:
	// li r11,12
	r11.s64 = 12;
loc_82283D80:
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
loc_82283D84:
	// addi r11,r1,88
	r11.s64 = ctx.r1.s64 + 88;
	// std r26,152(r1)
	PPC_STORE_U64(ctx.r1.u32 + 152, r26.u64);
	// stw r21,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, r21.u32);
	// li r10,31
	ctx.r10.s64 = 31;
	// stw r26,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, r26.u32);
	// li r4,14
	ctx.r4.s64 = 14;
	// stw r11,652(r1)
	PPC_STORE_U32(ctx.r1.u32 + 652, r11.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r26,188(r1)
	PPC_STORE_U32(ctx.r1.u32 + 188, r26.u32);
	// addi r14,r1,128
	r14.s64 = ctx.r1.s64 + 128;
	// stw r26,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, r26.u32);
	// std r10,140(r1)
	PPC_STORE_U64(ctx.r1.u32 + 140, ctx.r10.u64);
	// bl 0x822577d0
	ctx.lr = 0x82283DB8;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// bl 0x824816e8
	ctx.lr = 0x82283DCC;
	sub_824816E8(ctx, base);
	// stw r27,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r27.u32);
	// stw r28,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r28.u32);
	// b 0x82283e4c
	goto loc_82283E4C;
loc_82283DD8:
	// lbz r9,1176(r1)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r1.u32 + 1176);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// std r26,680(r1)
	PPC_STORE_U64(ctx.r1.u32 + 680, r26.u64);
	// li r4,14
	ctx.r4.s64 = 14;
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stw r24,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, r24.u32);
	// stw r16,664(r1)
	PPC_STORE_U32(ctx.r1.u32 + 664, r16.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r29,676(r1)
	PPC_STORE_U32(ctx.r1.u32 + 676, r29.u32);
	// addi r14,r1,656
	r14.s64 = ctx.r1.s64 + 656;
	// stw r25,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r25.u32);
	// stw r30,688(r1)
	PPC_STORE_U32(ctx.r1.u32 + 688, r30.u32);
	// stb r8,1176(r1)
	PPC_STORE_U8(ctx.r1.u32 + 1176, ctx.r8.u8);
	// stw r22,696(r1)
	PPC_STORE_U32(ctx.r1.u32 + 696, r22.u32);
	// stw r23,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, r23.u32);
	// stw r17,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r17.u32);
	// stw r10,1180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1180, ctx.r10.u32);
	// stw r26,700(r1)
	PPC_STORE_U32(ctx.r1.u32 + 700, r26.u32);
	// stw r26,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, r26.u32);
	// stw r21,692(r1)
	PPC_STORE_U32(ctx.r1.u32 + 692, r21.u32);
	// std r18,668(r1)
	PPC_STORE_U64(ctx.r1.u32 + 668, r18.u64);
	// bl 0x822577d0
	ctx.lr = 0x82283E30;
	sub_822577D0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,16
	ctx.r4.s64 = r31.s64 + 16;
	// lwz r3,96(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// mr r6,r14
	ctx.r6.u64 = r14.u64;
	// bl 0x824816e8
	ctx.lr = 0x82283E44;
	sub_824816E8(ctx, base);
	// stw r27,660(r1)
	PPC_STORE_U32(ctx.r1.u32 + 660, r27.u32);
	// stw r28,656(r1)
	PPC_STORE_U32(ctx.r1.u32 + 656, r28.u32);
loc_82283E4C:
	// lwz r14,1364(r1)
	r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1364);
loc_82283E50:
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// mr r3,r14
	ctx.r3.u64 = r14.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// stw r31,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r31.u32);
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// bl 0x8227e320
	ctx.lr = 0x82283E70;
	sub_8227E320(ctx, base);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// blt cr6,0x82283cb4
	if (cr6.lt) goto loc_82283CB4;
loc_82283E78:
	// addi r1,r1,1344
	ctx.r1.s64 = ctx.r1.s64 + 1344;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82283E80"))) PPC_WEAK_FUNC(sub_82283E80);
PPC_FUNC_IMPL(__imp__sub_82283E80) {
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
	ctx.lr = 0x82283E88;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r10,r11,9028
	ctx.r10.s64 = r11.s64 + 9028;
	// li r30,0
	r30.s64 = 0;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r30,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r30.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// li r3,5
	ctx.r3.s64 = 5;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cntlzw r5,r11
	ctx.r5.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// lfs f0,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	f0.f64 = double(temp.f32);
	// li r11,-1
	r11.s64 = -1;
	// stw r3,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r3.u32);
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// stfs f0,32(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 32, temp.u32);
	// addi r9,r8,-11804
	ctx.r9.s64 = ctx.r8.s64 + -11804;
	// stb r7,13(r31)
	PPC_STORE_U8(r31.u32 + 13, ctx.r7.u8);
	// stw r6,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r6.u32);
	// addi r29,r31,44
	r29.s64 = r31.s64 + 44;
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r30,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r30.u32);
	// addi r28,r29,12
	r28.s64 = r29.s64 + 12;
	// stb r10,12(r31)
	PPC_STORE_U8(r31.u32 + 12, ctx.r10.u8);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r30,52(r31)
	PPC_STORE_U32(r31.u32 + 52, r30.u32);
	// stw r9,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r9.u32);
	// bl 0x821b5a60
	ctx.lr = 0x82283F10;
	sub_821B5A60(ctx, base);
	// addi r3,r28,4
	ctx.r3.s64 = r28.s64 + 4;
	// bl 0x821b5a60
	ctx.lr = 0x82283F18;
	sub_821B5A60(ctx, base);
	// lis r8,-32216
	ctx.r8.s64 = -2111307776;
	// stw r30,60(r31)
	PPC_STORE_U32(r31.u32 + 60, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r7,r8,-3936
	ctx.r7.s64 = ctx.r8.s64 + -3936;
	// stw r30,56(r31)
	PPC_STORE_U32(r31.u32 + 56, r30.u32);
	// stw r30,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r30.u32);
	// stw r30,48(r31)
	PPC_STORE_U32(r31.u32 + 48, r30.u32);
	// stw r7,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r7.u32);
	// bl 0x82130000
	ctx.lr = 0x82283F3C;
	sub_82130000(ctx, base);
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// lis r6,-32121
	ctx.r6.s64 = -2105081856;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r29,-9996(r6)
	r29.u64 = PPC_LOAD_U32(ctx.r6.u32 + -9996);
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x82207db8
	ctx.lr = 0x82283F54;
	sub_82207DB8(ctx, base);
	// stw r29,64(r31)
	PPC_STORE_U32(r31.u32 + 64, r29.u32);
	// lis r5,-32120
	ctx.r5.s64 = -2105016320;
	// lwz r3,-27856(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x82283F64;
	sub_8238EC00(ctx, base);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// li r3,32
	ctx.r3.s64 = 32;
	// bl 0x82130528
	ctx.lr = 0x82283F70;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283f80
	if (cr6.eq) goto loc_82283F80;
	// bl 0x82289a58
	ctx.lr = 0x82283F7C;
	sub_82289A58(ctx, base);
	// b 0x82283f84
	goto loc_82283F84;
loc_82283F80:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_82283F84:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r3,808
	ctx.r3.s64 = 808;
	// bl 0x82130528
	ctx.lr = 0x82283F90;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82283fb0
	if (cr6.eq) goto loc_82283FB0;
	// bl 0x8229bd90
	ctx.lr = 0x82283F9C;
	sub_8229BD90(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82283FB0:
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82283FC0"))) PPC_WEAK_FUNC(sub_82283FC0);
PPC_FUNC_IMPL(__imp__sub_82283FC0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// stw r10,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r10.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82283FD0"))) PPC_WEAK_FUNC(sub_82283FD0);
PPC_FUNC_IMPL(__imp__sub_82283FD0) {
	PPC_FUNC_PROLOGUE();
	// lbz r3,152(r3)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r3.u32 + 152);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82283FD8"))) PPC_WEAK_FUNC(sub_82283FD8);
PPC_FUNC_IMPL(__imp__sub_82283FD8) {
	PPC_FUNC_PROLOGUE();
	// stb r4,152(r3)
	PPC_STORE_U8(ctx.r3.u32 + 152, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82283FE0"))) PPC_WEAK_FUNC(sub_82283FE0);
PPC_FUNC_IMPL(__imp__sub_82283FE0) {
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
	ctx.lr = 0x82284044;
	sub_82637538(ctx, base);
	// lis r5,-32253
	ctx.r5.s64 = -2113732608;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// stw r30,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r30.u32);
	// addi r3,r5,1292
	ctx.r3.s64 = ctx.r5.s64 + 1292;
	// addi r4,r6,1264
	ctx.r4.s64 = ctx.r6.s64 + 1264;
	// stw r3,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
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

__attribute__((alias("__imp__sub_8228407C"))) PPC_WEAK_FUNC(sub_8228407C);
PPC_FUNC_IMPL(__imp__sub_8228407C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284080"))) PPC_WEAK_FUNC(sub_82284080);
PPC_FUNC_IMPL(__imp__sub_82284080) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x822840cc
	if (cr6.eq) goto loc_822840CC;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822840B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822840cc
	if (cr6.eq) goto loc_822840CC;
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// stw r11,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r11.u32);
loc_822840CC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r11,116(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// stw r10,116(r31)
	PPC_STORE_U32(r31.u32 + 116, ctx.r10.u32);
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

__attribute__((alias("__imp__sub_82284100"))) PPC_WEAK_FUNC(sub_82284100);
PPC_FUNC_IMPL(__imp__sub_82284100) {
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
	ctx.lr = 0x82284108;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r4,116(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 116);
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228412C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822841ac
	if (cr6.eq) goto loc_822841AC;
	// addi r31,r3,-48
	r31.s64 = ctx.r3.s64 + -48;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822841a0
	if (cr6.eq) goto loc_822841A0;
	// lwz r11,48(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// addi r29,r31,48
	r29.s64 = r31.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284158;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82284178
	if (!cr6.eq) goto loc_82284178;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284178;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82284178:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82284080
	ctx.lr = 0x822841A0;
	sub_82284080(ctx, base);
loc_822841A0:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822841AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822841B8"))) PPC_WEAK_FUNC(sub_822841B8);
PPC_FUNC_IMPL(__imp__sub_822841B8) {
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
	ctx.lr = 0x822841C0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r31,-44(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + -44);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82284250
	if (cr6.lt) goto loc_82284250;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822841E8;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284250
	if (cr6.eq) goto loc_82284250;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82284200;
	sub_822A3998(ctx, base);
	// lwz r11,48(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284238
	if (cr6.eq) goto loc_82284238;
	// lwz r10,0(r13)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x8228422c
	if (cr6.eq) goto loc_8228422C;
	// addi r3,r11,208
	ctx.r3.s64 = r11.s64 + 208;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_8228422C:
	// addi r3,r11,144
	ctx.r3.s64 = r11.s64 + 144;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82284238:
	// lwz r3,17268(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 17268);
	// lwz r4,-44(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + -44);
	// bl 0x822a3998
	ctx.lr = 0x82284244;
	sub_822A3998(ctx, base);
	// bl 0x822a8108
	ctx.lr = 0x82284248;
	sub_822A8108(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_82284250:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_8228425C"))) PPC_WEAK_FUNC(sub_8228425C);
PPC_FUNC_IMPL(__imp__sub_8228425C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284260"))) PPC_WEAK_FUNC(sub_82284260);
PPC_FUNC_IMPL(__imp__sub_82284260) {
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
	// lwz r4,-44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -44);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x822842c4
	if (cr6.lt) goto loc_822842C4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x8228428C;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822842c4
	if (cr6.eq) goto loc_822842C4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822842AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_822842C4:
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

__attribute__((alias("__imp__sub_822842DC"))) PPC_WEAK_FUNC(sub_822842DC);
PPC_FUNC_IMPL(__imp__sub_822842DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822842E0"))) PPC_WEAK_FUNC(sub_822842E0);
PPC_FUNC_IMPL(__imp__sub_822842E0) {
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
	// lwz r31,4(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// blt cr6,0x82284324
	if (cr6.lt) goto loc_82284324;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82284314;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82284328
	if (!cr6.eq) goto loc_82284328;
loc_82284324:
	// li r11,0
	r11.s64 = 0;
loc_82284328:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284348
	if (cr6.eq) goto loc_82284348;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82284340;
	sub_822A3998(ctx, base);
	// lwz r3,1220(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x8228434c
	goto loc_8228434C;
loc_82284348:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8228434C:
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

__attribute__((alias("__imp__sub_82284364"))) PPC_WEAK_FUNC(sub_82284364);
PPC_FUNC_IMPL(__imp__sub_82284364) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284368"))) PPC_WEAK_FUNC(sub_82284368);
PPC_FUNC_IMPL(__imp__sub_82284368) {
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
	// lwz r30,4(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822843b8
	if (cr6.lt) goto loc_822843B8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r31,17268(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821e80f8
	ctx.lr = 0x8228439C;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822843b8
	if (cr6.eq) goto loc_822843B8;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a3998
	ctx.lr = 0x822843B4;
	sub_822A3998(ctx, base);
	// b 0x822843bc
	goto loc_822843BC;
loc_822843B8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_822843BC:
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

__attribute__((alias("__imp__sub_822843D4"))) PPC_WEAK_FUNC(sub_822843D4);
PPC_FUNC_IMPL(__imp__sub_822843D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822843D8"))) PPC_WEAK_FUNC(sub_822843D8);
PPC_FUNC_IMPL(__imp__sub_822843D8) {
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
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,-40(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -40);
	// lwz r11,-8204(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8204);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x82284418
	if (!cr6.eq) goto loc_82284418;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284414;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// b 0x82284474
	goto loc_82284474;
loc_82284418:
	// lwz r4,-44(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -44);
	// addi r31,r30,-48
	r31.s64 = r30.s64 + -48;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82284444
	if (cr6.lt) goto loc_82284444;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x82284434;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82284448
	if (!cr6.eq) goto loc_82284448;
loc_82284444:
	// li r11,0
	r11.s64 = 0;
loc_82284448:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284474
	if (cr6.eq) goto loc_82284474;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822842e0
	ctx.lr = 0x8228445C;
	sub_822842E0(ctx, base);
	// bl 0x82203310
	ctx.lr = 0x82284460;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284474
	if (cr6.eq) goto loc_82284474;
	// li r11,1
	r11.s64 = 1;
	// stb r11,52(r30)
	PPC_STORE_U8(r30.u32 + 52, r11.u8);
loc_82284474:
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

__attribute__((alias("__imp__sub_8228448C"))) PPC_WEAK_FUNC(sub_8228448C);
PPC_FUNC_IMPL(__imp__sub_8228448C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284490"))) PPC_WEAK_FUNC(sub_82284490);
PPC_FUNC_IMPL(__imp__sub_82284490) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91fc
	ctx.lr = 0x82284498;
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -40, f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,128(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 128);
	f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(f31.f64 + f0.f64));
	// lfs f0,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f0.f64 = double(temp.f32);
	// stfs f13,128(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 128, temp.u32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x822844d4
	if (!cr6.gt) goto loc_822844D4;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822844D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822844D4:
	// lwz r31,44(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 44);
	// lwz r30,116(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 116);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82284510
	if (cr6.eq) goto loc_82284510;
loc_822844E4:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x82284510
	if (!cr6.gt) goto loc_82284510;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284500;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,-1
	r30.s64 = r30.s64 + -1;
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x822844e4
	if (!cr6.eq) goto loc_822844E4;
loc_82284510:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x826355a8
	ctx.lr = 0x8228451C;
	sub_826355A8(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82284528"))) PPC_WEAK_FUNC(sub_82284528);
PPC_FUNC_IMPL(__imp__sub_82284528) {
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
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r10,-3624(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + -3624);
	// lfs f0,9068(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 9068);
	f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	f0.f64 = double(float(f0.f64 + f31.f64));
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// stfs f0,9068(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 9068, temp.u32);
	// lfs f13,40(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	cr6.compare(f0.f64, ctx.f13.f64);
	// ble cr6,0x822845a8
	if (!cr6.gt) goto loc_822845A8;
	// lwz r10,700(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822845a8
	if (!cr6.eq) goto loc_822845A8;
	// lbz r10,132(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 132);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cntlzw r7,r10
	ctx.r7.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lfs f0,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f0.f64 = double(temp.f32);
	// lwz r5,184(r8)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r8.u32 + 184);
	// stfs f0,9068(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 9068, temp.u32);
	// stb r6,132(r31)
	PPC_STORE_U8(r31.u32 + 132, ctx.r6.u8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x822845A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822845A8:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = f31.f64;
	// bl 0x82284490
	ctx.lr = 0x822845B4;
	sub_82284490(ctx, base);
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

__attribute__((alias("__imp__sub_822845CC"))) PPC_WEAK_FUNC(sub_822845CC);
PPC_FUNC_IMPL(__imp__sub_822845CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822845D0"))) PPC_WEAK_FUNC(sub_822845D0);
PPC_FUNC_IMPL(__imp__sub_822845D0) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r30,0
	r30.s64 = 0;
	// lwz r4,116(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 116);
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822845FC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82284660
	if (cr6.eq) goto loc_82284660;
loc_82284608:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228461C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228463c
	if (cr6.eq) goto loc_8228463C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228463C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228463C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284650;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// lwz r31,36(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x82284608
	if (!cr6.eq) goto loc_82284608;
loc_82284660:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
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

__attribute__((alias("__imp__sub_8228467C"))) PPC_WEAK_FUNC(sub_8228467C);
PPC_FUNC_IMPL(__imp__sub_8228467C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284680"))) PPC_WEAK_FUNC(sub_82284680);
PPC_FUNC_IMPL(__imp__sub_82284680) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_82284694"))) PPC_WEAK_FUNC(sub_82284694);
PPC_FUNC_IMPL(__imp__sub_82284694) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284698"))) PPC_WEAK_FUNC(sub_82284698);
PPC_FUNC_IMPL(__imp__sub_82284698) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCRegister r11{};
	// lwz r11,128(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 128);
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// lwz r10,548(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 548);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_822846AC"))) PPC_WEAK_FUNC(sub_822846AC);
PPC_FUNC_IMPL(__imp__sub_822846AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822846B0"))) PPC_WEAK_FUNC(sub_822846B0);
PPC_FUNC_IMPL(__imp__sub_822846B0) {
	PPC_FUNC_PROLOGUE();
	// b 0x82635538
	sub_82635538(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_822846B4"))) PPC_WEAK_FUNC(sub_822846B4);
PPC_FUNC_IMPL(__imp__sub_822846B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822846B8"))) PPC_WEAK_FUNC(sub_822846B8);
PPC_FUNC_IMPL(__imp__sub_822846B8) {
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
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r31,r11,80
	r31.s64 = r11.s64 + 80;
	// lwz r30,80(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// bl 0x822a5948
	ctx.lr = 0x822846E0;
	sub_822A5948(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822846F4;
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

__attribute__((alias("__imp__sub_8228470C"))) PPC_WEAK_FUNC(sub_8228470C);
PPC_FUNC_IMPL(__imp__sub_8228470C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284710"))) PPC_WEAK_FUNC(sub_82284710);
PPC_FUNC_IMPL(__imp__sub_82284710) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-48
	ctx.r3.s64 = ctx.r3.s64 + -48;
	// b 0x82284718
	sub_82284718(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82284718"))) PPC_WEAK_FUNC(sub_82284718);
PPC_FUNC_IMPL(__imp__sub_82284718) {
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r3,r31,48
	ctx.r3.s64 = r31.s64 + 48;
	// bne cr6,0x82284744
	if (!cr6.eq) goto loc_82284744;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82284744:
	// bl 0x826375a0
	ctx.lr = 0x82284748;
	sub_826375A0(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// clrlwi r10,r30,31
	ctx.r10.u64 = r30.u32 & 0x1;
	// addi r9,r11,8844
	ctx.r9.s64 = r11.s64 + 8844;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x8228476c
	if (cr6.eq) goto loc_8228476C;
	// bl 0x82130588
	ctx.lr = 0x82284768;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_8228476C:
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

__attribute__((alias("__imp__sub_82284784"))) PPC_WEAK_FUNC(sub_82284784);
PPC_FUNC_IMPL(__imp__sub_82284784) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82284788"))) PPC_WEAK_FUNC(sub_82284788);
PPC_FUNC_IMPL(__imp__sub_82284788) {
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
	ctx.lr = 0x82284790;
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
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r30,116(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822847B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// bge cr6,0x822848c8
	if (!cr6.lt) goto loc_822848C8;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,480(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 480);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822847D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822847ec
	if (cr6.eq) goto loc_822847EC;
	// addi r30,r3,-48
	r30.s64 = ctx.r3.s64 + -48;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// bne cr6,0x82284840
	if (!cr6.eq) goto loc_82284840;
loc_822847EC:
	// lhz r10,136(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 136);
	// addi r11,r31,132
	r11.s64 = r31.s64 + 132;
	// lwz r9,132(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 132);
	// addis r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 65536;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// clrlwi r7,r8,16
	ctx.r7.u64 = ctx.r8.u32 & 0xFFFF;
	// sth r7,136(r31)
	PPC_STORE_U16(r31.u32 + 136, ctx.r7.u16);
	// rlwinm r6,r7,2,14,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0x3FFFC;
	// lwzx r30,r6,r9
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// addi r29,r30,48
	r29.s64 = r30.s64 + 48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268d0d8
	ctx.lr = 0x8228481C;
	sub_8268D0D8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bne cr6,0x8228482c
	if (!cr6.eq) goto loc_8228482C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228482C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,368(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 368);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284840;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82284840:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284858;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,84(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 84);
	// lwz r29,116(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 116);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82284870;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// bge cr6,0x822848bc
	if (!cr6.lt) goto loc_822848BC;
	// lwz r3,144(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 144);
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284890;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,48(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 48);
	// addi r11,r30,48
	r11.s64 = r30.s64 + 48;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r8,532(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 532);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822848AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82284080
	ctx.lr = 0x822848BC;
	sub_82284080(ctx, base);
loc_822848BC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_822848C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822848D4"))) PPC_WEAK_FUNC(sub_822848D4);
PPC_FUNC_IMPL(__imp__sub_822848D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822848D8"))) PPC_WEAK_FUNC(sub_822848D8);
PPC_FUNC_IMPL(__imp__sub_822848D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	PPCRegister f0{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c4
	ctx.lr = 0x822848E0;
	// stfd f30,-160(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -160, f30.u64);
	// stfd f31,-152(r1)
	PPC_STORE_U64(ctx.r1.u32 + -152, f31.u64);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r21,-2
	ctx.r10.s64 = r21.s64 + -2;
	// addi r11,r11,3998
	r11.s64 = r11.s64 + 3998;
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// clrlwi r20,r5,24
	r20.u64 = ctx.r5.u32 & 0xFF;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r17,r3
	r17.u64 = ctx.r3.u64;
	// mr r15,r6
	r15.u64 = ctx.r6.u64;
	// mr r18,r7
	r18.u64 = ctx.r7.u64;
	// mr r23,r11
	r23.u64 = r11.u64;
	// mr r19,r11
	r19.u64 = r11.u64;
	// rlwinm r26,r9,27,31,31
	r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// addi r28,r10,2168
	r28.s64 = ctx.r10.s64 + 2168;
	// beq cr6,0x82284930
	if (cr6.eq) goto loc_82284930;
	// mr r11,r28
	r11.u64 = r28.u64;
loc_82284930:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82284940;
	sub_82218310(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// addi r30,r11,-2628
	r30.s64 = r11.s64 + -2628;
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x8228495C;
	sub_822701C8(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// bl 0x822952b0
	ctx.lr = 0x82284968;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228498c
	if (cr6.eq) goto loc_8228498C;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295e90
	ctx.lr = 0x82284984;
	sub_82295E90(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// b 0x82284990
	goto loc_82284990;
loc_8228498C:
	// mr r25,r24
	r25.u64 = r24.u64;
loc_82284990:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// bl 0x82270180
	ctx.lr = 0x8228499C;
	sub_82270180(ctx, base);
	// addi r3,r3,144
	ctx.r3.s64 = ctx.r3.s64 + 144;
	// bl 0x82481590
	ctx.lr = 0x822849A4;
	sub_82481590(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bne cr6,0x822849c4
	if (!cr6.eq) goto loc_822849C4;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822849BC;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_822849C4:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822849D8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bge cr6,0x82284a54
	if (!cr6.lt) goto loc_82284A54;
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// clrlwi r11,r26,24
	r11.u64 = r26.u32 & 0xFF;
	// beq cr6,0x82284a24
	if (cr6.eq) goto loc_82284A24;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284a10
	if (cr6.eq) goto loc_82284A10;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2140
	ctx.r4.s64 = r11.s64 + 2140;
	// bl 0x82218310
	ctx.lr = 0x82284A08;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284A10:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2112
	ctx.r4.s64 = r11.s64 + 2112;
	// bl 0x82218310
	ctx.lr = 0x82284A1C;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284A24:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284a40
	if (cr6.eq) goto loc_82284A40;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2088
	ctx.r4.s64 = r11.s64 + 2088;
	// bl 0x82218310
	ctx.lr = 0x82284A38;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284A40:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2064
	ctx.r4.s64 = r11.s64 + 2064;
	// bl 0x82218310
	ctx.lr = 0x82284A4C;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284A54:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f1,14192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x82284A64;
	sub_82293E30(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822952b0
	ctx.lr = 0x82284A70;
	sub_822952B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82284a8c
	if (cr6.eq) goto loc_82284A8C;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295538
	ctx.lr = 0x82284A8C;
	sub_82295538(ctx, base);
loc_82284A8C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r30,-32115
	r30.s64 = -2104688640;
	// addi r28,r11,15480
	r28.s64 = r11.s64 + 15480;
	// mr r11,r24
	r11.u64 = r24.u64;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r10,-12672(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -12672);
	// stb r11,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r11.u8);
	// cmplw cr6,r25,r10
	cr6.compare<uint32_t>(r25.u32, ctx.r10.u32, xer);
	// bne cr6,0x82284af4
	if (!cr6.eq) goto loc_82284AF4;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// lwz r4,-28256(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -28256);
	// bl 0x82218310
	ctx.lr = 0x82284AC0;
	sub_82218310(ctx, base);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lwz r11,-10244(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r9,r10,-27892
	ctx.r9.s64 = ctx.r10.s64 + -27892;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r4,4(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82218310
	ctx.lr = 0x82284ADC;
	sub_82218310(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r8,2052
	ctx.r4.s64 = ctx.r8.s64 + 2052;
	// bl 0x82218310
	ctx.lr = 0x82284AEC;
	sub_82218310(ctx, base);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// b 0x82284b88
	goto loc_82284B88;
loc_82284AF4:
	// stw r24,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r24.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82389668
	ctx.lr = 0x82284B10;
	sub_82389668(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82284b88
	if (cr6.eq) goto loc_82284B88;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lis r10,-32129
	ctx.r10.s64 = -2105606144;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r9,r10,-27892
	ctx.r9.s64 = ctx.r10.s64 + -27892;
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 5) & 0xFFFFFFE0;
	// lwz r10,44(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + r11.u64;
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r9
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r9.u32);
	// bl 0x82218310
	ctx.lr = 0x82284B5C;
	sub_82218310(ctx, base);
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,700(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r7,4(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r6,36(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 36);
	// lwzx r4,r6,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r9.u32);
	// bl 0x82218310
	ctx.lr = 0x82284B84;
	sub_82218310(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
loc_82284B88:
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822952b0
	ctx.lr = 0x82284B94;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284cec
	if (cr6.eq) goto loc_82284CEC;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295e90
	ctx.lr = 0x82284BAC;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x82284cec
	if (!cr6.eq) goto loc_82284CEC;
	// lbz r8,118(r1)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r1.u32 + 118);
	// li r10,255
	ctx.r10.s64 = 255;
	// lbz r6,113(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 113);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// ori r4,r8,128
	ctx.r4.u64 = ctx.r8.u64 | 128;
	// lbz r7,116(r1)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r1.u32 + 116);
	// stb r10,112(r1)
	PPC_STORE_U8(ctx.r1.u32 + 112, ctx.r10.u8);
	// ori r10,r6,224
	ctx.r10.u64 = ctx.r6.u64 | 224;
	// clrlwi r11,r4,24
	r11.u64 = ctx.r4.u32 & 0xFF;
	// stb r24,117(r1)
	PPC_STORE_U8(ctx.r1.u32 + 117, r24.u8);
	// clrlwi r3,r7,25
	ctx.r3.u64 = ctx.r7.u32 & 0x7F;
	// stw r24,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, r24.u32);
	// ori r9,r11,64
	ctx.r9.u64 = r11.u64 | 64;
	// stw r24,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r24.u32);
	// stb r3,116(r1)
	PPC_STORE_U8(ctx.r1.u32 + 116, ctx.r3.u8);
	// li r4,18
	ctx.r4.s64 = 18;
	// stw r24,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, r24.u32);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// stb r10,113(r1)
	PPC_STORE_U8(ctx.r1.u32 + 113, ctx.r10.u8);
	// stb r24,132(r1)
	PPC_STORE_U8(ctx.r1.u32 + 132, r24.u8);
	// stb r24,133(r1)
	PPC_STORE_U8(ctx.r1.u32 + 133, r24.u8);
	// stw r24,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, r24.u32);
	// stb r9,118(r1)
	PPC_STORE_U8(ctx.r1.u32 + 118, ctx.r9.u8);
	// bl 0x82295538
	ctx.lr = 0x82284C14;
	sub_82295538(ctx, base);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82397458
	ctx.lr = 0x82284C1C;
	sub_82397458(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x82284c58
	if (cr6.eq) goto loc_82284C58;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r11,2036
	ctx.r4.s64 = r11.s64 + 2036;
	// bl 0x82218310
	ctx.lr = 0x82284C38;
	sub_82218310(ctx, base);
	// lis r10,-32255
	ctx.r10.s64 = -2113863680;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,-5820
	ctx.r5.s64 = ctx.r10.s64 + -5820;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r7,r19
	ctx.r7.u64 = r19.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284C54;
	sub_82137A08(ctx, base);
	// b 0x82284ce8
	goto loc_82284CE8;
loc_82284C58:
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82295c90
	ctx.lr = 0x82284C64;
	sub_82295C90(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bge cr6,0x82284ca8
	if (!cr6.lt) goto loc_82284CA8;
	// lwz r11,-12672(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -12672);
	// cmplw cr6,r25,r11
	cr6.compare<uint32_t>(r25.u32, r11.u32, xer);
	// bne cr6,0x82284ca8
	if (!cr6.eq) goto loc_82284CA8;
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r9,127
	ctx.r9.s64 = 127;
	// subf r8,r28,r19
	ctx.r8.s64 = r19.s64 - r28.s64;
loc_82284C84:
	// lbzx r10,r11,r8
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + ctx.r8.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82284ca0
	if (cr6.eq) goto loc_82284CA0;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bgt 0x82284c84
	if (cr0.gt) goto loc_82284C84;
loc_82284CA0:
	// stb r24,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r24.u8);
	// b 0x82284ce8
	goto loc_82284CE8;
loc_82284CA8:
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bne cr6,0x82284cb8
	if (!cr6.eq) goto loc_82284CB8;
	// li r30,2
	r30.s64 = 2;
loc_82284CB8:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r11,2020
	ctx.r4.s64 = r11.s64 + 2020;
	// bl 0x82218310
	ctx.lr = 0x82284CC8;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r5,r10,2008
	ctx.r5.s64 = ctx.r10.s64 + 2008;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// mr r8,r19
	ctx.r8.u64 = r19.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284CE8;
	sub_82137A08(ctx, base);
loc_82284CE8:
	// mr r19,r28
	r19.u64 = r28.u64;
loc_82284CEC:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284D00;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82284ee4
	if (cr6.eq) goto loc_82284EE4;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x82284ee4
	if (!cr6.eq) goto loc_82284EE4;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e1b0
	ctx.lr = 0x82284D20;
	sub_8227E1B0(ctx, base);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r4,-3624(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x82284D30;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82284D34;
	sub_82293F60(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,-3624(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	f30.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x82284D44;
	sub_8226B2F0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82293eb0
	ctx.lr = 0x82284D50;
	sub_82293EB0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284e18
	if (cr6.eq) goto loc_82284E18;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// lwz r4,-3624(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// bl 0x8226b2f0
	ctx.lr = 0x82284D68;
	sub_8226B2F0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82294028
	ctx.lr = 0x82284D78;
	sub_82294028(ctx, base);
	// lwz r30,0(r3)
	r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 120);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// beq cr6,0x82284d98
	if (cr6.eq) goto loc_82284D98;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r3,r11,1976
	ctx.r3.s64 = r11.s64 + 1976;
	// bl 0x821e6800
	ctx.lr = 0x82284D94;
	sub_821E6800(ctx, base);
	// stw r30,120(r17)
	PPC_STORE_U32(r17.u32 + 120, r30.u32);
loc_82284D98:
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82284ddc
	if (cr6.eq) goto loc_82284DDC;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-27008
	ctx.r4.s64 = r11.s64 + -27008;
	// bl 0x82218310
	ctx.lr = 0x82284DB0;
	sub_82218310(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r31,r11,15608
	r31.s64 = r11.s64 + 15608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r10,1964
	ctx.r5.s64 = ctx.r10.s64 + 1964;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r7,r23
	ctx.r7.u64 = r23.u64;
	// mr r8,r30
	ctx.r8.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284DD8;
	sub_82137A08(ctx, base);
	// b 0x82284ee0
	goto loc_82284EE0;
loc_82284DDC:
	// cmpwi cr6,r21,2
	cr6.compare<int32_t>(r21.s32, 2, xer);
	// bne cr6,0x82284df0
	if (!cr6.eq) goto loc_82284DF0;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,1944
	ctx.r4.s64 = r11.s64 + 1944;
	// b 0x82284df8
	goto loc_82284DF8;
loc_82284DF0:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,1924
	ctx.r4.s64 = r11.s64 + 1924;
loc_82284DF8:
	// bl 0x82218310
	ctx.lr = 0x82284DFC;
	sub_82218310(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r31,r11,15608
	r31.s64 = r11.s64 + 15608;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284E14;
	sub_82137A08(ctx, base);
	// b 0x82284ee0
	goto loc_82284EE0;
loc_82284E18:
	// clrlwi r11,r22,24
	r11.u64 = r22.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82284eac
	if (!cr6.eq) goto loc_82284EAC;
	// clrlwi r10,r18,24
	ctx.r10.u64 = r18.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82284ea4
	if (cr6.eq) goto loc_82284EA4;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x82284ea4
	if (!cr6.gt) goto loc_82284EA4;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// ble cr6,0x82284ea4
	if (!cr6.gt) goto loc_82284EA4;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// fsubs f0,f30,f31
	f0.f64 = double(float(f30.f64 - f31.f64));
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r10,1904
	ctx.r4.s64 = ctx.r10.s64 + 1904;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lfs f13,20(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 - f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r11,100(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r31,r11,1
	r31.s64 = r11.s64 + 1;
	// bl 0x82218310
	ctx.lr = 0x82284E7C;
	sub_82218310(ctx, base);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r23,r8,15608
	r23.s64 = ctx.r8.s64 + 15608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r7,1896
	ctx.r5.s64 = ctx.r7.s64 + 1896;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// bl 0x82137a08
	ctx.lr = 0x82284EA0;
	sub_82137A08(ctx, base);
	// b 0x82284ee4
	goto loc_82284EE4;
loc_82284EA4:
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82284ee4
	if (cr6.eq) goto loc_82284EE4;
loc_82284EAC:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r11,1880
	ctx.r4.s64 = r11.s64 + 1880;
	// bl 0x82218310
	ctx.lr = 0x82284EBC;
	sub_82218310(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r31,r10,15608
	r31.s64 = ctx.r10.s64 + 15608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r9,1872
	ctx.r5.s64 = ctx.r9.s64 + 1872;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// bl 0x82137a08
	ctx.lr = 0x82284EE0;
	sub_82137A08(ctx, base);
loc_82284EE0:
	// mr r23,r31
	r23.u64 = r31.u64;
loc_82284EE4:
	// cmpwi cr6,r15,1
	cr6.compare<int32_t>(r15.s32, 1, xer);
	// mr r31,r23
	r31.u64 = r23.u64;
	// beq cr6,0x82284ef4
	if (cr6.eq) goto loc_82284EF4;
	// mr r31,r16
	r31.u64 = r16.u64;
loc_82284EF4:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284F08;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,-13276
	ctx.r4.s64 = ctx.r9.s64 + -13276;
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82284F24;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r15,1
	cr6.compare<int32_t>(r15.s32, 1, xer);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// beq cr6,0x82284f34
	if (cr6.eq) goto loc_82284F34;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
loc_82284F34:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,344(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 344);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r15,2
	cr6.compare<int32_t>(r15.s32, 2, xer);
	// mr r31,r23
	r31.u64 = r23.u64;
	// beq cr6,0x82284f58
	if (cr6.eq) goto loc_82284F58;
	// mr r31,r16
	r31.u64 = r16.u64;
loc_82284F58:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r9,1864
	ctx.r4.s64 = ctx.r9.s64 + 1864;
	// lwz r7,52(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 52);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82284F88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r17)
	ctx.r6.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r5,496(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 496);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82284F9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r4,-32253
	ctx.r4.s64 = -2113732608;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// addi r4,r4,1856
	ctx.r4.s64 = ctx.r4.s64 + 1856;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284FB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r9,0(r19)
	ctx.r9.u64 = PPC_LOAD_U8(r19.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82284fe8
	if (cr6.eq) goto loc_82284FE8;
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82284FD8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82284fe8
	if (cr6.eq) goto loc_82284FE8;
	// stw r15,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r15.u32);
	// b 0x82284ff0
	goto loc_82284FF0;
loc_82284FE8:
	// li r11,3
	r11.s64 = 3;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
loc_82284FF0:
	// lwz r11,0(r17)
	r11.u64 = PPC_LOAD_U32(r17.u32 + 0);
	// mr r3,r17
	ctx.r3.u64 = r17.u64;
	// lwz r10,496(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 496);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285004;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,1840
	ctx.r4.s64 = ctx.r9.s64 + 1840;
	// lwz r7,44(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 44);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82285020;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// lfd f30,-160(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -160);
	// lfd f31,-152(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// b 0x823d9214
	return;
}

__attribute__((alias("__imp__sub_82285030"))) PPC_WEAK_FUNC(sub_82285030);
PPC_FUNC_IMPL(__imp__sub_82285030) {
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
	ctx.lr = 0x82285038;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82635538
	ctx.lr = 0x82285044;
	sub_82635538(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r6,r11,-18484
	ctx.r6.s64 = r11.s64 + -18484;
	// addi r5,r10,-18604
	ctx.r5.s64 = ctx.r10.s64 + -18604;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,-10220(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// lwz r3,588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 588);
	// bl 0x823dedd8
	ctx.lr = 0x8228506C;
	sub_823DEDD8(ctx, base);
	// lwz r4,-44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -44);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82285128
	if (cr6.lt) goto loc_82285128;
	// lwz r11,32(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285128
	if (cr6.eq) goto loc_82285128;
	// lwz r11,20(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285128
	if (cr6.eq) goto loc_82285128;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r10,r10,2192
	ctx.r10.s64 = ctx.r10.s64 + 2192;
loc_8228509C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x822850c0
	if (cr6.eq) goto loc_822850C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x8228509c
	if (cr6.eq) goto loc_8228509C;
loc_822850C0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x82285128
	if (!cr6.eq) goto loc_82285128;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822850fc
	if (cr6.eq) goto loc_822850FC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x822a3998
	ctx.lr = 0x822850E0;
	sub_822A3998(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,560(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822850F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822850FC:
	// addic. r11,r31,-48
	xer.ca = r31.u32 > 47;
	r11.s64 = r31.s64 + -48;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// bne 0x8228510c
	if (!cr0.eq) goto loc_8228510C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8228510C:
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,-10220(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10220);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x826290c0
	ctx.lr = 0x82285128;
	sub_826290C0(ctx, base);
loc_82285128:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82285130"))) PPC_WEAK_FUNC(sub_82285130);
PPC_FUNC_IMPL(__imp__sub_82285130) {
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
	ctx.lr = 0x82285138;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r25,0
	r25.s64 = 0;
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82285184
	if (cr6.lt) goto loc_82285184;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82285164;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285184
	if (cr6.eq) goto loc_82285184;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x8228517C;
	sub_822A3998(ctx, base);
	// lwz r27,1220(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x82285188
	goto loc_82285188;
loc_82285184:
	// mr r27,r25
	r27.u64 = r25.u64;
loc_82285188:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r26,700(r11)
	r26.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x822701c8
	ctx.lr = 0x822851A8;
	sub_822701C8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822851e0
	if (cr6.eq) goto loc_822851E0;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x822952b0
	ctx.lr = 0x822851BC;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822851e0
	if (cr6.eq) goto loc_822851E0;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x822851D4;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822851e4
	if (!cr6.eq) goto loc_822851E4;
loc_822851E0:
	// mr r11,r25
	r11.u64 = r25.u64;
loc_822851E4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r29,r11,24
	r29.u64 = r11.u32 & 0xFF;
	// bl 0x822952b0
	ctx.lr = 0x822851F4;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285214
	if (cr6.eq) goto loc_82285214;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82295e90
	ctx.lr = 0x8228520C;
	sub_82295E90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x82285218
	goto loc_82285218;
loc_82285214:
	// mr r31,r25
	r31.u64 = r25.u64;
loc_82285218:
	// stw r25,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r25.u32);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822577d0
	ctx.lr = 0x82285228;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82285270
	if (cr6.eq) goto loc_82285270;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmpwi cr6,r31,2
	cr6.compare<int32_t>(r31.s32, 2, xer);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bne cr6,0x82285258
	if (!cr6.eq) goto loc_82285258;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2088
	ctx.r4.s64 = ctx.r10.s64 + 2088;
	// bl 0x82218310
	ctx.lr = 0x8228524C;
	sub_82218310(ctx, base);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285258:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2064
	ctx.r4.s64 = ctx.r10.s64 + 2064;
	// bl 0x82218310
	ctx.lr = 0x82285264;
	sub_82218310(ctx, base);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285270:
	// lwz r11,16(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x82285290
	if (!cr6.eq) goto loc_82285290;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// stw r10,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285290:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822852c0
	if (cr6.eq) goto loc_822852C0;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2304
	ctx.r4.s64 = ctx.r10.s64 + 2304;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822852B0;
	sub_82218310(ctx, base);
	// stw r25,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r25.u32);
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_822852C0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822852C8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822852D8;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// li r4,11
	ctx.r4.s64 = 11;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r9,11780(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 11780);
	// cmplw cr6,r27,r9
	cr6.compare<uint32_t>(r27.u32, ctx.r9.u32, xer);
	// bne cr6,0x82285344
	if (!cr6.eq) goto loc_82285344;
	// bl 0x822577d0
	ctx.lr = 0x822852F4;
	sub_822577D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// beq cr6,0x82285324
	if (cr6.eq) goto loc_82285324;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2280
	ctx.r4.s64 = ctx.r10.s64 + 2280;
	// bl 0x82218310
	ctx.lr = 0x82285310;
	sub_82218310(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// stw r11,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285324:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2256
	ctx.r4.s64 = ctx.r10.s64 + 2256;
	// bl 0x82218310
	ctx.lr = 0x82285330;
	sub_82218310(ctx, base);
	// li r11,3
	r11.s64 = 3;
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// stw r11,28(r28)
	PPC_STORE_U32(r28.u32 + 28, r11.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285344:
	// bl 0x822577d0
	ctx.lr = 0x82285348;
	sub_822577D0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// beq cr6,0x82285378
	if (cr6.eq) goto loc_82285378;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2232
	ctx.r4.s64 = ctx.r10.s64 + 2232;
	// bl 0x82218310
	ctx.lr = 0x82285364;
	sub_82218310(ctx, base);
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// stw r9,28(r28)
	PPC_STORE_U32(r28.u32 + 28, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_82285378:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2208
	ctx.r4.s64 = ctx.r10.s64 + 2208;
	// bl 0x82218310
	ctx.lr = 0x82285384;
	sub_82218310(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r3,12(r28)
	PPC_STORE_U32(r28.u32 + 12, ctx.r3.u32);
	// stw r9,28(r28)
	PPC_STORE_U32(r28.u32 + 28, ctx.r9.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82285398"))) PPC_WEAK_FUNC(sub_82285398);
PPC_FUNC_IMPL(__imp__sub_82285398) {
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
	ctx.lr = 0x822853A0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// lwz r31,4(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x822853f4
	if (cr6.lt) goto loc_822853F4;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x822853CC;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x822853f4
	if (cr6.eq) goto loc_822853F4;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x822853E4;
	sub_822A3998(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822853f4
	if (cr6.eq) goto loc_822853F4;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x822853f8
	goto loc_822853F8;
loc_822853F4:
	// li r31,0
	r31.s64 = 0;
loc_822853F8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// addi r10,r11,3998
	ctx.r10.s64 = r11.s64 + 3998;
	// stw r10,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r10.u32);
	// beq cr6,0x822854dc
	if (cr6.eq) goto loc_822854DC;
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82285428
	if (cr6.eq) goto loc_82285428;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8238f6b0
	ctx.lr = 0x8228541C;
	sub_8238F6B0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r7,r27,8141
	ctx.r7.s64 = r27.s64 + 8141;
	// b 0x8228549c
	goto loc_8228549C;
loc_82285428:
	// li r4,18
	ctx.r4.s64 = 18;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822577d0
	ctx.lr = 0x82285434;
	sub_822577D0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,21
	ctx.r4.s64 = 21;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82285444;
	sub_822051A0(ctx, base);
	// bl 0x82396f58
	ctx.lr = 0x82285448;
	sub_82396F58(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// addi r30,r11,-12120
	r30.s64 = r11.s64 + -12120;
	// bge cr6,0x8228546c
	if (!cr6.lt) goto loc_8228546C;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82285464;
	sub_822051A0(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// blt cr6,0x82285478
	if (cr6.lt) goto loc_82285478;
loc_8228546C:
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// blt cr6,0x8228547c
	if (cr6.lt) goto loc_8228547C;
loc_82285478:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8228547C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mulli r10,r3,104
	ctx.r10.s64 = ctx.r3.s64 * 104;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + r11.u64;
	// lwz r3,-10244(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10244);
	// lwz r4,8(r8)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// bl 0x822183a8
	ctx.lr = 0x82285498;
	sub_822183A8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
loc_8228549C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// addi r31,r11,9072
	r31.s64 = r11.s64 + 9072;
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r31,2048
	r11.s64 = r31.s64 + 2048;
	// addi r5,r9,2332
	ctx.r5.s64 = ctx.r9.s64 + 2332;
	// addi r6,r29,65
	ctx.r6.s64 = r29.s64 + 65;
	// li r4,64
	ctx.r4.s64 = 64;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82137a08
	ctx.lr = 0x822854C8;
	sub_82137A08(ctx, base);
	// lwz r8,4(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// addi r11,r31,2048
	r11.s64 = r31.s64 + 2048;
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + r11.u64;
	// stw r7,8(r28)
	PPC_STORE_U32(r28.u32 + 8, ctx.r7.u32);
loc_822854DC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_822854E4"))) PPC_WEAK_FUNC(sub_822854E4);
PPC_FUNC_IMPL(__imp__sub_822854E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822854E8"))) PPC_WEAK_FUNC(sub_822854E8);
PPC_FUNC_IMPL(__imp__sub_822854E8) {
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
	ctx.lr = 0x822854F0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r31,4(r29)
	r31.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82285540
	if (cr6.lt) goto loc_82285540;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82285518;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285540
	if (cr6.eq) goto loc_82285540;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82285530;
	sub_822A3998(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82285540
	if (cr6.eq) goto loc_82285540;
	// lwz r31,1220(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1220);
	// b 0x82285544
	goto loc_82285544;
loc_82285540:
	// li r31,0
	r31.s64 = 0;
loc_82285544:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228554C;
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
	ctx.lr = 0x82285560;
	sub_82270170(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x822855c0
	if (!cr6.eq) goto loc_822855C0;
	// lwz r11,80(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x822855c0
	if (cr6.eq) goto loc_822855C0;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// lwz r3,32(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r6,r10,-17564
	ctx.r6.s64 = ctx.r10.s64 + -17564;
	// addi r5,r9,-22108
	ctx.r5.s64 = ctx.r9.s64 + -22108;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82285594;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822855c0
	if (cr6.eq) goto loc_822855C0;
	// lwz r31,76(r3)
	r31.u64 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	// bl 0x82387b90
	ctx.lr = 0x822855A4;
	sub_82387B90(ctx, base);
	// mulli r11,r31,8176
	r11.s64 = r31.s64 * 8176;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r4,r11,1360
	ctx.r4.s64 = r11.s64 + 1360;
	// bl 0x82285398
	ctx.lr = 0x822855B8;
	sub_82285398(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_822855C0:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82285398
	ctx.lr = 0x822855CC;
	sub_82285398(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822855D4"))) PPC_WEAK_FUNC(sub_822855D4);
PPC_FUNC_IMPL(__imp__sub_822855D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822855D8"))) PPC_WEAK_FUNC(sub_822855D8);
PPC_FUNC_IMPL(__imp__sub_822855D8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91ec
	ctx.lr = 0x822855E0;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r7,-32121
	ctx.r7.s64 = -2105081856;
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r11,r7,9072
	r11.s64 = ctx.r7.s64 + 9072;
	// lwz r8,4(r27)
	ctx.r8.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// addi r4,r6,-2628
	ctx.r4.s64 = ctx.r6.s64 + -2628;
	// lwz r3,-10240(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10240);
	// rlwinm r10,r8,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// add r28,r10,r11
	r28.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x822701c8
	ctx.lr = 0x82285610;
	sub_822701C8(ctx, base);
	// lwz r31,4(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// li r26,0
	r26.s64 = 0;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82285664
	if (cr6.lt) goto loc_82285664;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r30,17268(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82285638;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285664
	if (cr6.eq) goto loc_82285664;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a3998
	ctx.lr = 0x82285650;
	sub_822A3998(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82285668
	if (cr6.eq) goto loc_82285668;
	// lwz r30,1220(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// b 0x8228566c
	goto loc_8228566C;
loc_82285664:
	// mr r31,r26
	r31.u64 = r26.u64;
loc_82285668:
	// mr r30,r26
	r30.u64 = r26.u64;
loc_8228566C:
	// lwz r11,20(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285688
	if (cr6.eq) goto loc_82285688;
	// lbz r11,0(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x8228568c
	if (!cr6.eq) goto loc_8228568C;
loc_82285688:
	// mr r11,r26
	r11.u64 = r26.u64;
loc_8228568C:
	// stb r26,0(r28)
	PPC_STORE_U8(r28.u32 + 0, r26.u8);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r25,r11,24
	r25.u64 = r11.u32 & 0xFF;
	// bl 0x822a5ab8
	ctx.lr = 0x8228569C;
	sub_822A5AB8(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x82285b24
	if (cr6.eq) goto loc_82285B24;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82285b24
	if (cr6.eq) goto loc_82285B24;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x822856B8;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285b24
	if (cr6.eq) goto loc_82285B24;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x822856D0;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// bne cr6,0x82285b24
	if (!cr6.eq) goto loc_82285B24;
	// bl 0x82292040
	ctx.lr = 0x822856DC;
	sub_82292040(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// ble cr6,0x82285b24
	if (!cr6.gt) goto loc_82285B24;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822577d0
	ctx.lr = 0x822856F0;
	sub_822577D0(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// beq cr6,0x82285aac
	if (cr6.eq) goto loc_82285AAC;
	// cmpwi cr6,r30,4
	cr6.compare<int32_t>(r30.s32, 4, xer);
	// beq cr6,0x82285aac
	if (cr6.eq) goto loc_82285AAC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x82285aac
	if (cr6.eq) goto loc_82285AAC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82285718;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82285a58
	if (!cr6.eq) goto loc_82285A58;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285734;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x8228584c
	if (cr6.eq) goto loc_8228584C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-3624(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -3624);
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,40(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 40);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x8228584c
	if (!cr6.gt) goto loc_8228584C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285770;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f1,14192(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14192);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82293e30
	ctx.lr = 0x82285784;
	sub_82293E30(ctx, base);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822952b0
	ctx.lr = 0x82285790;
	sub_822952B0(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822857ac
	if (cr6.eq) goto loc_822857AC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295538
	ctx.lr = 0x822857AC;
	sub_82295538(ctx, base);
loc_822857AC:
	// lis r11,32767
	r11.s64 = 2147418112;
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// bne cr6,0x8228582c
	if (!cr6.eq) goto loc_8228582C;
	// cmpwi cr6,r30,2
	cr6.compare<int32_t>(r30.s32, 2, xer);
	// bne cr6,0x8228583c
	if (!cr6.eq) goto loc_8228583C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2384
	ctx.r4.s64 = ctx.r10.s64 + 2384;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822857D8;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_822857E0:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x822857e0
	if (cr0.gt) goto loc_822857E0;
	// b 0x82285b20
	goto loc_82285B20;
loc_8228582C:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// bgt cr6,0x8228583c
	if (cr6.gt) goto loc_8228583C;
	// bl 0x82292040
	ctx.lr = 0x82285838;
	sub_82292040(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
loc_8228583C:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8223de50
	ctx.lr = 0x82285848;
	sub_8223DE50(ctx, base);
	// b 0x82285b24
	goto loc_82285B24;
loc_8228584C:
	// lwz r11,44(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285b24
	if (cr6.eq) goto loc_82285B24;
	// cmpwi cr6,r11,31
	cr6.compare<int32_t>(r11.s32, 31, xer);
	// ble cr6,0x82285868
	if (!cr6.gt) goto loc_82285868;
	// li r11,32
	r11.s64 = 32;
	// stw r11,44(r27)
	PPC_STORE_U32(r27.u32 + 44, r11.u32);
loc_82285868:
	// lwz r11,44(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x822858dc
	if (!cr6.eq) goto loc_822858DC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2384
	ctx.r4.s64 = ctx.r10.s64 + 2384;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82285888;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82285890:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82285890
	if (cr0.gt) goto loc_82285890;
	// b 0x82285b20
	goto loc_82285B20;
loc_822858DC:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x8228594c
	if (!cr6.eq) goto loc_8228594C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2376
	ctx.r4.s64 = ctx.r10.s64 + 2376;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x822858F8;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82285900:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82285900
	if (cr0.gt) goto loc_82285900;
	// b 0x82285b20
	goto loc_82285B20;
loc_8228594C:
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bne cr6,0x822859bc
	if (!cr6.eq) goto loc_822859BC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2368
	ctx.r4.s64 = ctx.r10.s64 + 2368;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82285968;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82285970:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82285970
	if (cr0.gt) goto loc_82285970;
	// b 0x82285b20
	goto loc_82285B20;
loc_822859BC:
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// ble cr6,0x82285a2c
	if (!cr6.gt) goto loc_82285A2C;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2352
	ctx.r4.s64 = ctx.r10.s64 + 2352;
	// bl 0x82218310
	ctx.lr = 0x822859D8;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_822859E0:
	// lbz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r10,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r10.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x822859e0
	if (cr0.gt) goto loc_822859E0;
	// b 0x82285b20
	goto loc_82285B20;
loc_82285A2C:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2348
	ctx.r4.s64 = ctx.r10.s64 + 2348;
	// bl 0x82218310
	ctx.lr = 0x82285A38;
	sub_82218310(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r6,44(r27)
	ctx.r6.u64 = PPC_LOAD_U32(r27.u32 + 44);
	// addi r5,r9,2340
	ctx.r5.s64 = ctx.r9.s64 + 2340;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x82285A54;
	sub_82137A08(ctx, base);
	// b 0x82285b24
	goto loc_82285B24;
loc_82285A58:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5df8
	ctx.lr = 0x82285A60;
	sub_822A5DF8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82295e90
	ctx.lr = 0x82285A70;
	sub_82295E90(ctx, base);
	// cmplwi cr6,r3,13
	cr6.compare<uint32_t>(ctx.r3.u32, 13, xer);
	// bne cr6,0x82285a88
	if (!cr6.eq) goto loc_82285A88;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8223de50
	ctx.lr = 0x82285A84;
	sub_8223DE50(ctx, base);
	// b 0x82285b24
	goto loc_82285B24;
loc_82285A88:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// blt cr6,0x82285b24
	if (cr6.lt) goto loc_82285B24;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r6,r31
	ctx.r6.u64 = r31.u64;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x82285AA8;
	sub_82137A08(ctx, base);
	// b 0x82285b24
	goto loc_82285B24;
loc_82285AAC:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2352
	ctx.r4.s64 = ctx.r10.s64 + 2352;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82285AC0;
	sub_82218310(ctx, base);
	// mr r11,r28
	r11.u64 = r28.u64;
	// li r8,63
	ctx.r8.s64 = 63;
loc_82285AC8:
	// lbz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b20
	if (cr6.eq) goto loc_82285B20;
	// stb r9,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r9.u8);
	// addi r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 1;
	// lbz r9,1(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b14
	if (cr6.eq) goto loc_82285B14;
	// stb r9,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82285b1c
	if (cr6.eq) goto loc_82285B1C;
	// stb r9,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r9.u8);
	// addic. r8,r8,-3
	xer.ca = ctx.r8.u32 > 2;
	ctx.r8.s64 = ctx.r8.s64 + -3;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3
	r11.s64 = r11.s64 + 3;
	// bgt 0x82285ac8
	if (cr0.gt) goto loc_82285AC8;
	// b 0x82285b20
	goto loc_82285B20;
loc_82285B14:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// b 0x82285b20
	goto loc_82285B20;
loc_82285B1C:
	// addi r11,r11,2
	r11.s64 = r11.s64 + 2;
loc_82285B20:
	// stb r26,0(r11)
	PPC_STORE_U8(r11.u32 + 0, r26.u8);
loc_82285B24:
	// clrlwi r11,r25,24
	r11.u64 = r25.u32 & 0xFF;
	// stw r28,20(r27)
	PPC_STORE_U32(r27.u32 + 20, r28.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82285b50
	if (!cr6.eq) goto loc_82285B50;
	// lbz r11,0(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285b50
	if (cr6.eq) goto loc_82285B50;
	// li r11,1
	r11.s64 = 1;
	// clrlwi r3,r11,24
	ctx.r3.u64 = r11.u32 & 0xFF;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
loc_82285B50:
	// clrlwi r3,r26,24
	ctx.r3.u64 = r26.u32 & 0xFF;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d923c
	return;
}

__attribute__((alias("__imp__sub_82285B5C"))) PPC_WEAK_FUNC(sub_82285B5C);
PPC_FUNC_IMPL(__imp__sub_82285B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82285B60"))) PPC_WEAK_FUNC(sub_82285B60);
PPC_FUNC_IMPL(__imp__sub_82285B60) {
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
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// bne cr6,0x82285b8c
	if (!cr6.eq) goto loc_82285B8C;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2412
	ctx.r4.s64 = r11.s64 + 2412;
	// b 0x82285b94
	goto loc_82285B94;
loc_82285B8C:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,2392
	ctx.r4.s64 = r11.s64 + 2392;
loc_82285B94:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x82285BA4;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,20(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285BB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// addi r7,r8,3998
	ctx.r7.s64 = ctx.r8.s64 + 3998;
	// lwz r10,-8204(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8204);
	// stw r10,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r10.u32);
	// lwz r10,-8204(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8204);
	// stw r7,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r7.u32);
	// stw r7,20(r31)
	PPC_STORE_U32(r31.u32 + 20, ctx.r7.u32);
	// stw r11,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r11.u32);
	// stw r11,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r11.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
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

__attribute__((alias("__imp__sub_82285C08"))) PPC_WEAK_FUNC(sub_82285C08);
PPC_FUNC_IMPL(__imp__sub_82285C08) {
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
	ctx.lr = 0x82285C10;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82285C20;
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
	ctx.lr = 0x82285C34;
	sub_82270170(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r31,208(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 208);
	// bl 0x82635f20
	ctx.lr = 0x82285C44;
	sub_82635F20(ctx, base);
	// li r8,1
	ctx.r8.s64 = 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// stw r8,148(r30)
	PPC_STORE_U32(r30.u32 + 148, ctx.r8.u32);
	// beq cr6,0x82285cc4
	if (cr6.eq) goto loc_82285CC4;
	// addi r3,r31,144
	ctx.r3.s64 = r31.s64 + 144;
	// bl 0x824817c0
	ctx.lr = 0x82285C5C;
	sub_824817C0(ctx, base);
	// li r28,0
	r28.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r28,148(r30)
	PPC_STORE_U32(r30.u32 + 148, r28.u32);
	// bl 0x82387b90
	ctx.lr = 0x82285C6C;
	sub_82387B90(ctx, base);
	// lwz r11,1340(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285cc4
	if (cr6.eq) goto loc_82285CC4;
	// addi r29,r31,12
	r29.s64 = r31.s64 + 12;
	// mr r31,r28
	r31.u64 = r28.u64;
loc_82285C80:
	// bl 0x82387b90
	ctx.lr = 0x82285C84;
	sub_82387B90(ctx, base);
	// add r11,r31,r3
	r11.u64 = r31.u64 + ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x823906d8
	ctx.lr = 0x82285C94;
	sub_823906D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285cac
	if (cr6.eq) goto loc_82285CAC;
	// lwz r11,148(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 148);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,148(r30)
	PPC_STORE_U32(r30.u32 + 148, r11.u32);
loc_82285CAC:
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r31,r31,8176
	r31.s64 = r31.s64 + 8176;
	// bl 0x82387b90
	ctx.lr = 0x82285CB8;
	sub_82387B90(ctx, base);
	// lwz r11,1340(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// bne cr6,0x82285c80
	if (!cr6.eq) goto loc_82285C80;
loc_82285CC4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

__attribute__((alias("__imp__sub_82285CCC"))) PPC_WEAK_FUNC(sub_82285CCC);
PPC_FUNC_IMPL(__imp__sub_82285CCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82285CD0"))) PPC_WEAK_FUNC(sub_82285CD0);
PPC_FUNC_IMPL(__imp__sub_82285CD0) {
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
	ctx.lr = 0x82285CD8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// addi r30,r29,80
	r30.s64 = r29.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r11,80(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 80);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285CFC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82285d48
	if (cr6.eq) goto loc_82285D48;
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82285d48
	if (cr6.eq) goto loc_82285D48;
	// lbz r11,278(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82285d48
	if (!cr6.eq) goto loc_82285D48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a7cc8
	ctx.lr = 0x82285D24;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285d48
	if (cr6.eq) goto loc_82285D48;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a86e8
	ctx.lr = 0x82285D38;
	sub_822A86E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r7,1
	ctx.r7.s64 = 1;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82285d4c
	if (!cr6.eq) goto loc_82285D4C;
loc_82285D48:
	// li r7,0
	ctx.r7.s64 = 0;
loc_82285D4C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r4,r29,128
	ctx.r4.s64 = r29.s64 + 128;
	// bne cr6,0x82285d5c
	if (!cr6.eq) goto loc_82285D5C;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82285D5C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10220(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10220);
	// bl 0x826290c0
	ctx.lr = 0x82285D78;
	sub_826290C0(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_82285D80"))) PPC_WEAK_FUNC(sub_82285D80);
PPC_FUNC_IMPL(__imp__sub_82285D80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x826355a8
	ctx.lr = 0x82285D9C;
	sub_826355A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388598
	ctx.lr = 0x82285DA4;
	sub_82388598(ctx, base);
	// lis r11,-32112
	r11.s64 = -2104492032;
	// rlwinm r10,r3,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r11,r11,21384
	r11.s64 = r11.s64 + 21384;
	// lis r9,-32255
	ctx.r9.s64 = -2113863680;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lfs f12,-28876(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -28876);
	ctx.f12.f64 = double(temp.f32);
	// lbz r4,18(r11)
	ctx.r4.u64 = PPC_LOAD_U8(r11.u32 + 18);
	// lfs f11,1068(r8)
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 1068);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,14192(r7)
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14192);
	ctx.f13.f64 = double(temp.f32);
	// lfs f10,7444(r6)
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	ctx.f10.f64 = double(temp.f32);
	// std r4,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r4.u64);
	// lfd f0,88(r1)
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
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
	// bge cr6,0x82285e00
	if (!cr6.lt) goto loc_82285E00;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x82285e0c
	goto loc_82285E0C;
loc_82285E00:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x82285e0c
	if (!cr6.gt) goto loc_82285E0C;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
loc_82285E0C:
	// lbz r10,19(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 19);
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
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
	// bge cr6,0x82285e3c
	if (!cr6.lt) goto loc_82285E3C;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
	// b 0x82285e48
	goto loc_82285E48;
loc_82285E3C:
	// fcmpu cr6,f0,f10
	ctx.fpscr.disableFlushMode();
	cr6.compare(f0.f64, ctx.f10.f64);
	// ble cr6,0x82285e48
	if (!cr6.gt) goto loc_82285E48;
	// fmr f0,f10
	f0.f64 = ctx.f10.f64;
loc_82285E48:
	// lis r31,-32121
	r31.s64 = -2105081856;
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lbz r11,629(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82285f2c
	if (cr6.eq) goto loc_82285F2C;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f1,31308(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31308);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8260c6d8
	ctx.lr = 0x82285E78;
	sub_8260C6D8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f0,3796(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	cr6.compare(ctx.f1.f64, f0.f64);
	// bgt cr6,0x82285f2c
	if (cr6.gt) goto loc_82285F2C;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,208(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 208);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82285E9C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lwz r7,0(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r11,r1,128
	r11.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r9,r6
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,548(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 548);
	// lvx128 v61,r9,r4
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r4.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r9,r10
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r9.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82285EF0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v59,r0,r6
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v59,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x826208d0
	ctx.lr = 0x82285F0C;
	sub_826208D0(ctx, base);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x82625f50
	ctx.lr = 0x82285F2C;
	sub_82625F50(ctx, base);
loc_82285F2C:
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

__attribute__((alias("__imp__sub_82285F44"))) PPC_WEAK_FUNC(sub_82285F44);
PPC_FUNC_IMPL(__imp__sub_82285F44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82285F48"))) PPC_WEAK_FUNC(sub_82285F48);
PPC_FUNC_IMPL(__imp__sub_82285F48) {
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
	PPCRegister f29{};
	PPCRegister f30{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e0
	ctx.lr = 0x82285F50;
	// stfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -112, f29.u64);
	// stfd f30,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, f30.u64);
	// stfd f31,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// li r26,0
	r26.s64 = 0;
	// lfs f29,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmr f31,f29
	f31.f64 = f29.f64;
	// bl 0x82388580
	ctx.lr = 0x82285F80;
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
	ctx.lr = 0x82285F94;
	sub_82270170(ctx, base);
	// lwz r8,128(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 128);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// addi r3,r28,128
	ctx.r3.s64 = r28.s64 + 128;
	// lwz r6,548(r8)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r8.u32 + 548);
	// lwz r31,208(r7)
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + 208);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82285FB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// li r23,0
	r23.s64 = 0;
	// addi r27,r31,12
	r27.s64 = r31.s64 + 12;
	// li r25,31
	r25.s64 = 31;
	// lfd f30,2432(r11)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(r11.u32 + 2432);
	// lis r22,-32121
	r22.s64 = -2105081856;
loc_82285FCC:
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822860e8
	if (cr6.eq) goto loc_822860E8;
	// lbz r11,279(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 279);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228600c
	if (cr6.eq) goto loc_8228600C;
	// lbz r11,280(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 280);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82286004
	if (!cr6.eq) goto loc_82286004;
	// addi r3,r31,16
	ctx.r3.s64 = r31.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82285FF8;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228600c
	if (cr6.eq) goto loc_8228600C;
loc_82286004:
	// li r11,1
	r11.s64 = 1;
	// b 0x82286010
	goto loc_82286010;
loc_8228600C:
	// li r11,0
	r11.s64 = 0;
loc_82286010:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822860e8
	if (cr6.eq) goto loc_822860E8;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r30,17268(r22)
	r30.u64 = PPC_LOAD_U32(r22.u32 + 17268);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x8228602C;
	sub_822051A0(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821e80f8
	ctx.lr = 0x82286038;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822860e8
	if (cr6.eq) goto loc_822860E8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822051a0
	ctx.lr = 0x82286050;
	sub_822051A0(ctx, base);
	// bl 0x822a5948
	ctx.lr = 0x82286054;
	sub_822A5948(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x822a8108
	ctx.lr = 0x8228605C;
	sub_822A8108(ctx, base);
	// addi r11,r3,48
	r11.s64 = ctx.r3.s64 + 48;
	// lfs f13,4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,0(r29)
	temp.u32 = PPC_LOAD_U32(r29.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	f0.f64 = double(temp.f32);
	// fsubs f10,f13,f0
	ctx.f10.f64 = double(float(ctx.f13.f64 - f0.f64));
	// lfs f13,8(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f8,f11,f12
	ctx.f8.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmuls f7,f10,f10
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// fmadds f6,f9,f9,f7
	ctx.f6.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f7.f64));
	// fmadds f5,f8,f8,f6
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f6.f64));
	// fsqrts f11,f5
	ctx.f11.f64 = double(float(sqrt(ctx.f5.f64)));
	// fcmpu cr6,f11,f31
	cr6.compare(ctx.f11.f64, f31.f64);
	// bge cr6,0x822860d4
	if (!cr6.lt) goto loc_822860D4;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x822860dc
	if (cr6.eq) goto loc_822860DC;
	// lfs f10,4(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f9,f10,f0
	ctx.f9.f64 = double(float(ctx.f10.f64 - f0.f64));
	// lfs f8,8(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f13
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f13.f64));
	// lfs f6,0(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// fsubs f5,f6,f12
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f12.f64));
	// fmuls f4,f9,f9
	ctx.f4.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fmadds f3,f7,f7,f4
	ctx.f3.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fcmpu cr6,f1,f30
	cr6.compare(ctx.f1.f64, f30.f64);
	// bgt cr6,0x822860dc
	if (cr6.gt) goto loc_822860DC;
loc_822860D4:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	cr6.compare(f31.f64, f29.f64);
	// bne cr6,0x822860e8
	if (!cr6.eq) goto loc_822860E8;
loc_822860DC:
	// fmr f31,f11
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f11.f64;
	// mr r26,r31
	r26.u64 = r31.u64;
	// mr r23,r30
	r23.u64 = r30.u64;
loc_822860E8:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// addi r27,r27,4
	r27.s64 = r27.s64 + 4;
	// bne 0x82285fcc
	if (!cr0.eq) goto loc_82285FCC;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lfs f0,568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 568);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// bge cr6,0x8228615c
	if (!cr6.lt) goto loc_8228615C;
	// fcmpu cr6,f31,f29
	cr6.compare(f31.f64, f29.f64);
	// ble cr6,0x8228615c
	if (!cr6.gt) goto loc_8228615C;
	// addi r31,r28,80
	r31.s64 = r28.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822842e0
	ctx.lr = 0x8228611C;
	sub_822842E0(ctx, base);
	// cmplw cr6,r26,r3
	cr6.compare<uint32_t>(r26.u32, ctx.r3.u32, xer);
	// bne cr6,0x82286144
	if (!cr6.eq) goto loc_82286144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822842e0
	ctx.lr = 0x8228612C;
	sub_822842E0(ctx, base);
	// cmplw cr6,r26,r3
	cr6.compare<uint32_t>(r26.u32, ctx.r3.u32, xer);
	// bne cr6,0x8228615c
	if (!cr6.eq) goto loc_8228615C;
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// lbz r11,629(r11)
	r11.u64 = PPC_LOAD_U8(r11.u32 + 629);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x8228615c
	if (!cr6.eq) goto loc_8228615C;
loc_82286144:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
loc_8228615C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	f29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

__attribute__((alias("__imp__sub_82286174"))) PPC_WEAK_FUNC(sub_82286174);
PPC_FUNC_IMPL(__imp__sub_82286174) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82286178"))) PPC_WEAK_FUNC(sub_82286178);
PPC_FUNC_IMPL(__imp__sub_82286178) {
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
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r31,0(r30)
	r31.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x82285f48
	ctx.lr = 0x82286198;
	sub_82285F48(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,560(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 560);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822861AC;
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

__attribute__((alias("__imp__sub_822861C4"))) PPC_WEAK_FUNC(sub_822861C4);
PPC_FUNC_IMPL(__imp__sub_822861C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_822861C8"))) PPC_WEAK_FUNC(sub_822861C8);
PPC_FUNC_IMPL(__imp__sub_822861C8) {
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
	ctx.lr = 0x822861D0;
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -64, f30.u64);
	// stfd f31,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// bl 0x82285f48
	ctx.lr = 0x822861EC;
	sub_82285F48(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82286330
	if (cr6.eq) goto loc_82286330;
	// bl 0x822a8108
	ctx.lr = 0x822861FC;
	sub_822A8108(ctx, base);
	// addi r11,r1,80
	r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r30.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v62,r0,r3
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r7,32
	ctx.r7.s64 = 32;
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	f0.f64 = double(temp.f32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// li r5,48
	ctx.r5.s64 = 48;
	// stvx128 v62,r0,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r9
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stvx128 v61,r0,r8
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lvx128 v60,r3,r7
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// stvx128 v60,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// lvx128 v59,r3,r5
	simde_mm_store_si128((simde__m128i*)v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r8,-32130
	ctx.r8.s64 = -2105671680;
	// stvx128 v59,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r9,-18512
	ctx.r6.s64 = ctx.r9.s64 + -18512;
	// lfs f13,152(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r8,-18664
	ctx.r5.s64 = ctx.r8.s64 + -18664;
	// lfs f12,88(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f11,144(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f0,f11
	ctx.f10.f64 = double(float(f0.f64 - ctx.f11.f64));
	// fsubs f9,f12,f13
	ctx.f9.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lfs f31,3796(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3796);
	f31.f64 = double(temp.f32);
	// fmuls f8,f10,f10
	ctx.f8.f64 = double(float(ctx.f10.f64 * ctx.f10.f64));
	// stfs f31,148(r1)
	temp.f32 = float(f31.f64);
	PPC_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 604);
	// fmadds f7,f9,f9,f8
	ctx.f7.f64 = double(float(ctx.f9.f64 * ctx.f9.f64 + ctx.f8.f64));
	// fsqrts f30,f7
	f30.f64 = double(float(sqrt(ctx.f7.f64)));
	// bl 0x823dedd8
	ctx.lr = 0x8228629C;
	sub_823DEDD8(ctx, base);
	// lwz r11,-10220(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lfs f6,568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 568);
	ctx.f6.f64 = double(temp.f32);
	// fcmpu cr6,f30,f6
	cr6.compare(f30.f64, ctx.f6.f64);
	// bge cr6,0x82286330
	if (!cr6.lt) goto loc_82286330;
	// fcmpu cr6,f30,f31
	cr6.compare(f30.f64, f31.f64);
	// ble cr6,0x82286330
	if (!cr6.gt) goto loc_82286330;
	// clrlwi r11,r27,24
	r11.u64 = r27.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82286304
	if (!cr6.eq) goto loc_82286304;
	// addi r3,r28,80
	ctx.r3.s64 = r28.s64 + 80;
	// bl 0x82284368
	ctx.lr = 0x822862CC;
	sub_82284368(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x82286304
	if (!cr6.eq) goto loc_82286304;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822862ec
	if (cr6.eq) goto loc_822862EC;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82284368
	ctx.lr = 0x822862E4;
	sub_82284368(ctx, base);
	// cmplw cr6,r31,r3
	cr6.compare<uint32_t>(r31.u32, ctx.r3.u32, xer);
	// bne cr6,0x82286304
	if (!cr6.eq) goto loc_82286304;
loc_822862EC:
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r3,-10220(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10220);
	// bl 0x8261fef8
	ctx.lr = 0x822862F8;
	sub_8261FEF8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286330
	if (cr6.eq) goto loc_82286330;
loc_82286304:
	// lwz r11,0(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r10,560(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 560);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228631C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
loc_82286330:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82286344"))) PPC_WEAK_FUNC(sub_82286344);
PPC_FUNC_IMPL(__imp__sub_82286344) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82286348"))) PPC_WEAK_FUNC(sub_82286348);
PPC_FUNC_IMPL(__imp__sub_82286348) {
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
	ctx.lr = 0x82286350;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r30,r31,80
	r30.s64 = r31.s64 + 80;
	// lwz r29,80(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// bl 0x822a5948
	ctx.lr = 0x82286368;
	sub_822A5948(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x8228637C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r3,-10220(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10220);
	// bl 0x8262ae60
	ctx.lr = 0x82286398;
	sub_8262AE60(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

__attribute__((alias("__imp__sub_822863A0"))) PPC_WEAK_FUNC(sub_822863A0);
PPC_FUNC_IMPL(__imp__sub_822863A0) {
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
	// lwz r11,68(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286480
	if (cr6.eq) goto loc_82286480;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822863CC;
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
	ctx.lr = 0x822863E0;
	sub_82270170(ctx, base);
	// lwz r9,208(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x82286480
	if (cr6.eq) goto loc_82286480;
	// lwz r4,-44(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -44);
	// addi r31,r30,-48
	r31.s64 = r30.s64 + -48;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82286418
	if (cr6.lt) goto loc_82286418;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,17268(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x82286408;
	sub_821E80F8(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// li r11,1
	r11.s64 = 1;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228641c
	if (!cr6.eq) goto loc_8228641C;
loc_82286418:
	// li r11,0
	r11.s64 = 0;
loc_8228641C:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286480
	if (cr6.eq) goto loc_82286480;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822855d8
	ctx.lr = 0x82286430;
	sub_822855D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286450
	if (cr6.eq) goto loc_82286450;
	// lwz r3,32(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 32);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,184(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 184);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82286450;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82286450:
	// lwz r11,20(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286468
	if (cr6.eq) goto loc_82286468;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228646c
	if (!cr6.eq) goto loc_8228646C;
loc_82286468:
	// lwz r11,12(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 12);
loc_8228646C:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r3,68(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 68);
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// addi r4,r10,2440
	ctx.r4.s64 = ctx.r10.s64 + 2440;
	// bl 0x827227b8
	ctx.lr = 0x82286480;
	sub_827227B8(ctx, base);
loc_82286480:
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

__attribute__((alias("__imp__sub_82286498"))) PPC_WEAK_FUNC(sub_82286498);
PPC_FUNC_IMPL(__imp__sub_82286498) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x822864A0;
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r20,r6,24
	r20.u64 = ctx.r6.u32 & 0xFF;
	// stw r5,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r5.u32);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r16,r4
	r16.u64 = ctx.r4.u64;
	// mr r17,r7
	r17.u64 = ctx.r7.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x822864d8
	if (!cr6.eq) goto loc_822864D8;
	// lwz r11,112(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 112);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blt cr6,0x822864d8
	if (cr6.lt) goto loc_822864D8;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9210
	return;
loc_822864D8:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822864E0;
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
	ctx.lr = 0x822864F4;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822864FC;
	sub_822577D0(ctx, base);
	// lwz r10,0(r24)
	ctx.r10.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r23,0
	r23.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// mr r25,r23
	r25.u64 = r23.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r9,496(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 496);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82286520;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r14,-32121
	r14.s64 = -2105081856;
	// mr r15,r3
	r15.u64 = ctx.r3.u64;
	// lwz r11,-3624(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + -3624);
	// lwz r29,700(r11)
	r29.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82286538;
	sub_8227E0B0(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// addi r4,r8,-2628
	ctx.r4.s64 = ctx.r8.s64 + -2628;
	// bl 0x822701c8
	ctx.lr = 0x82286550;
	sub_822701C8(ctx, base);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82295e90
	ctx.lr = 0x82286558;
	sub_82295E90(ctx, base);
	// cntlzw r7,r3
	ctx.r7.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r18,r7,27,31,31
	r18.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// bl 0x82388580
	ctx.lr = 0x82286568;
	sub_82388580(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r6)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82286578;
	sub_82270170(ctx, base);
	// lwz r5,16(r29)
	ctx.r5.u64 = PPC_LOAD_U32(r29.u32 + 16);
	// lwz r22,208(r3)
	r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// beq cr6,0x822865bc
	if (cr6.eq) goto loc_822865BC;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228659C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822865bc
	if (cr6.eq) goto loc_822865BC;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x822865bc
	if (cr6.eq) goto loc_822865BC;
	// cmpwi cr6,r31,1
	cr6.compare<int32_t>(r31.s32, 1, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822865c0
	if (!cr6.eq) goto loc_822865C0;
loc_822865BC:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_822865C0:
	// lis r28,-32121
	r28.s64 = -2105081856;
	// clrlwi r21,r11,24
	r21.u64 = r11.u32 & 0xFF;
	// lwz r3,17268(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822865D0;
	sub_822A39C8(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x822865e4
	if (cr6.eq) goto loc_822865E4;
	// cmpwi cr6,r17,0
	cr6.compare<int32_t>(r17.s32, 0, xer);
	// beq cr6,0x82286858
	if (cr6.eq) goto loc_82286858;
loc_822865E4:
	// mr r26,r23
	r26.u64 = r23.u64;
loc_822865E8:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x822865fc
	if (!cr6.eq) goto loc_822865FC;
	// lwz r11,112(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 112);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82286858
	if (!cr6.lt) goto loc_82286858;
loc_822865FC:
	// mr r30,r23
	r30.u64 = r23.u64;
	// li r29,8
	r29.s64 = 8;
loc_82286604:
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// bne cr6,0x82286684
	if (!cr6.eq) goto loc_82286684;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r17,-1
	ctx.r10.s64 = r17.s64 + -1;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// bne cr6,0x82286684
	if (!cr6.eq) goto loc_82286684;
	// lwz r11,124(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 124);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bge cr6,0x82286684
	if (!cr6.lt) goto loc_82286684;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822a5ab8
	ctx.lr = 0x82286630;
	sub_822A5AB8(ctx, base);
	// cmpw cr6,r3,r16
	cr6.compare<int32_t>(ctx.r3.s32, r16.s32, xer);
	// bne cr6,0x82286684
	if (!cr6.eq) goto loc_82286684;
	// mr r31,r27
	r31.u64 = r27.u64;
loc_8228663C:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x8228676c
	if (cr6.eq) goto loc_8228676C;
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x8228676c
	if (cr6.eq) goto loc_8228676C;
	// lbz r10,279(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 279);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82286714
	if (cr6.eq) goto loc_82286714;
	// lbz r10,280(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 280);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x8228667c
	if (!cr6.eq) goto loc_8228667C;
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7008
	ctx.lr = 0x82286670;
	sub_824E7008(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286714
	if (cr6.eq) goto loc_82286714;
loc_8228667C:
	// li r11,1
	r11.s64 = 1;
	// b 0x82286718
	goto loc_82286718;
loc_82286684:
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// lbzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822866c0
	if (cr6.eq) goto loc_822866C0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822866ec
	if (cr6.lt) goto loc_822866EC;
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lwz r10,260(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 260);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x822866ec
	if (!cr6.lt) goto loc_822866EC;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// add r11,r29,r11
	r11.u64 = r29.u64 + r11.u64;
	// lwz r10,128(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 128);
	// b 0x822866e0
	goto loc_822866E0;
loc_822866C0:
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// blt cr6,0x822866ec
	if (cr6.lt) goto loc_822866EC;
	// lwz r11,17268(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 17268);
	// lwz r10,132(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 132);
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// bge cr6,0x822866ec
	if (!cr6.lt) goto loc_822866EC;
	// rotlwi r11,r11,0
	r11.u64 = __builtin_rotateleft32(r11.u32, 0);
	// lwzx r10,r29,r11
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r11.u32);
loc_822866E0:
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x822866f0
	if (!cr6.eq) goto loc_822866F0;
loc_822866EC:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_822866F0:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228670c
	if (cr6.eq) goto loc_8228670C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822a5948
	ctx.lr = 0x82286704;
	sub_822A5948(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x8228663c
	goto loc_8228663C;
loc_8228670C:
	// mr r31,r23
	r31.u64 = r23.u64;
	// b 0x8228676c
	goto loc_8228676C;
loc_82286714:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_82286718:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228676c
	if (cr6.eq) goto loc_8228676C;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228673C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r26
	cr6.compare<int32_t>(ctx.r3.s32, r26.s32, xer);
	// bne cr6,0x8228676c
	if (!cr6.eq) goto loc_8228676C;
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// addi r3,r11,16
	ctx.r3.s64 = r11.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82286750;
	sub_824E7110(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82296e50
	ctx.lr = 0x8228675C;
	sub_82296E50(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82286770
	if (!cr6.eq) goto loc_82286770;
loc_8228676C:
	// mr r11,r23
	r11.u64 = r23.u64;
loc_82286770:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286820
	if (cr6.eq) goto loc_82286820;
	// clrlwi r11,r19,24
	r11.u64 = r19.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822867a4
	if (cr6.eq) goto loc_822867A4;
	// clrlwi r11,r18,24
	r11.u64 = r18.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822867a4
	if (cr6.eq) goto loc_822867A4;
	// li r4,14
	ctx.r4.s64 = 14;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// bl 0x822577d0
	ctx.lr = 0x822867A0;
	sub_822577D0(ctx, base);
	// b 0x822867ac
	goto loc_822867AC;
loc_822867A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822a5ab8
	ctx.lr = 0x822867AC;
	sub_822A5AB8(ctx, base);
loc_822867AC:
	// cmpw cr6,r3,r16
	cr6.compare<int32_t>(ctx.r3.s32, r16.s32, xer);
	// bne cr6,0x82286820
	if (!cr6.eq) goto loc_82286820;
	// clrlwi r11,r21,24
	r11.u64 = r21.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822867d0
	if (!cr6.eq) goto loc_822867D0;
	// lwz r11,1220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// lbz r10,278(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 278);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82286820
	if (!cr6.eq) goto loc_82286820;
loc_822867D0:
	// lwz r5,80(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r5,r17
	cr6.compare<int32_t>(ctx.r5.s32, r17.s32, xer);
	// bge cr6,0x82286834
	if (!cr6.lt) goto loc_82286834;
	// cmplwi cr6,r20,0
	cr6.compare<uint32_t>(r20.u32, 0, xer);
	// beq cr6,0x82286804
	if (cr6.eq) goto loc_82286804;
	// lwz r11,108(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 108);
	// cmpw cr6,r16,r11
	cr6.compare<int32_t>(r16.s32, r11.s32, xer);
	// bne cr6,0x82286804
	if (!cr6.eq) goto loc_82286804;
	// lwz r11,112(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 112);
	// cmpw cr6,r25,r11
	cr6.compare<int32_t>(r25.s32, r11.s32, xer);
	// bge cr6,0x82286804
	if (!cr6.lt) goto loc_82286804;
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// b 0x82286820
	goto loc_82286820;
loc_82286804:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82286820;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82286820:
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpwi cr6,r29,132
	cr6.compare<int32_t>(r29.s32, 132, xer);
	// bne cr6,0x82286604
	if (!cr6.eq) goto loc_82286604;
	// b 0x8228684c
	goto loc_8228684C;
loc_82286834:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,676(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 676);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228684C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_8228684C:
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// cmpwi cr6,r26,32
	cr6.compare<int32_t>(r26.s32, 32, xer);
	// ble cr6,0x822865e8
	if (!cr6.gt) goto loc_822865E8;
loc_82286858:
	// lis r26,-32121
	r26.s64 = -2105081856;
	// cmpwi cr6,r16,0
	cr6.compare<int32_t>(r16.s32, 0, xer);
	// bne cr6,0x822869a0
	if (!cr6.eq) goto loc_822869A0;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82286878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822869a0
	if (cr6.eq) goto loc_822869A0;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r11,r17
	cr6.compare<int32_t>(r11.s32, r17.s32, xer);
	// bge cr6,0x822869a0
	if (!cr6.lt) goto loc_822869A0;
	// addi r30,r22,144
	r30.s64 = r22.s64 + 144;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824818a0
	ctx.lr = 0x822868A0;
	sub_824818A0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82296eb8
	ctx.lr = 0x822868B0;
	sub_82296EB8(ctx, base);
	// subf. r31,r3,r31
	r31.s64 = r31.s64 - ctx.r3.s64;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x822868ec
	if (cr0.eq) goto loc_822868EC;
loc_822868B8:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822868D4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822868e4
	if (cr6.eq) goto loc_822868E4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82285b60
	ctx.lr = 0x822868E4;
	sub_82285B60(ctx, base);
loc_822868E4:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x822868b8
	if (!cr0.eq) goto loc_822868B8;
loc_822868EC:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x824818a0
	ctx.lr = 0x822868F8;
	sub_824818A0(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x82296eb8
	ctx.lr = 0x82286908;
	sub_82296EB8(ctx, base);
	// subf. r25,r3,r31
	r25.s64 = r31.s64 - ctx.r3.s64;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// beq 0x822869a0
	if (cr0.eq) goto loc_822869A0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r28,-32130
	r28.s64 = -2105671680;
	// addi r29,r11,3998
	r29.s64 = r11.s64 + 3998;
	// addi r27,r10,2392
	r27.s64 = ctx.r10.s64 + 2392;
loc_82286924:
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,664(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 664);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82286940;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x82286998
	if (cr6.eq) goto loc_82286998;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,-10244(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82218310
	ctx.lr = 0x8228695C;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,20(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x82286970;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,-8204(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -8204);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// lwz r11,-8204(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -8204);
	// stw r29,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r29.u32);
	// stw r29,20(r31)
	PPC_STORE_U32(r31.u32 + 20, r29.u32);
	// stw r23,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r23.u32);
	// stw r23,28(r31)
	PPC_STORE_U32(r31.u32 + 28, r23.u32);
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r23,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r23.u32);
	// stw r23,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r23.u32);
loc_82286998:
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bne 0x82286924
	if (!cr0.eq) goto loc_82286924;
loc_822869A0:
	// lwz r29,356(r1)
	r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r11,2496
	ctx.r5.s64 = r11.s64 + 2496;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x822869BC;
	sub_82137A08(ctx, base);
	// lwz r10,0(r15)
	ctx.r10.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// stw r16,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r16.u32);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822869DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r16,0
	cr6.compare<int32_t>(r16.s32, 0, xer);
	// beq cr6,0x82286a74
	if (cr6.eq) goto loc_82286A74;
	// lwz r11,-3624(r14)
	r11.u64 = PPC_LOAD_U32(r14.u32 + -3624);
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227f588
	ctx.lr = 0x822869F4;
	sub_8227F588(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// bge cr6,0x82286a04
	if (!cr6.lt) goto loc_82286A04;
	// mr r30,r23
	r30.u64 = r23.u64;
loc_82286A04:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r11,2484
	ctx.r5.s64 = r11.s64 + 2484;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82286A1C;
	sub_82137A08(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// lwz r3,-10244(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -10244);
	// addi r11,r10,15224
	r11.s64 = ctx.r10.s64 + 15224;
	// rlwinm r10,r29,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 6) & 0xFFFFFFC0;
	// addi r4,r9,2468
	ctx.r4.s64 = ctx.r9.s64 + 2468;
	// add r31,r10,r11
	r31.u64 = ctx.r10.u64 + r11.u64;
	// bl 0x82218310
	ctx.lr = 0x82286A3C;
	sub_82218310(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r5,r8,2460
	ctx.r5.s64 = ctx.r8.s64 + 2460;
	// li r4,64
	ctx.r4.s64 = 64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// bl 0x82137a08
	ctx.lr = 0x82286A58;
	sub_82137A08(ctx, base);
	// lwz r7,0(r15)
	ctx.r7.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lwz r6,52(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 52);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82286A74;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82286A74:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// addi r5,r11,2448
	ctx.r5.s64 = r11.s64 + 2448;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82137a08
	ctx.lr = 0x82286A8C;
	sub_82137A08(ctx, base);
	// lwz r10,0(r15)
	ctx.r10.u64 = PPC_LOAD_U32(r15.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lwz r9,44(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82286AA8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r3,80(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82286AB4"))) PPC_WEAK_FUNC(sub_82286AB4);
PPC_FUNC_IMPL(__imp__sub_82286AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82286AB8"))) PPC_WEAK_FUNC(sub_82286AB8);
PPC_FUNC_IMPL(__imp__sub_82286AB8) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91c0
	ctx.lr = 0x82286AC0;
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r17,0
	r17.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r17.u32);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// stw r17,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r17.u32);
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// addi r4,r11,-2628
	ctx.r4.s64 = r11.s64 + -2628;
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r15,700(r11)
	r15.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x822701c8
	ctx.lr = 0x82286AF8;
	sub_822701C8(ctx, base);
	// lwz r11,-3624(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + -3624);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r9,36(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r8,496(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 496);
	// lwz r27,36(r9)
	r27.u64 = PPC_LOAD_U32(ctx.r9.u32 + 36);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82286B1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// li r22,-1
	r22.s64 = -1;
	// stw r17,116(r31)
	PPC_STORE_U32(r31.u32 + 116, r17.u32);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// stw r22,124(r31)
	PPC_STORE_U32(r31.u32 + 124, r22.u32);
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// lfs f0,3796(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 3796);
	f0.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r31.u32 + 128, temp.u32);
	// bl 0x8227d3a0
	ctx.lr = 0x82286B40;
	sub_8227D3A0(ctx, base);
	// clrlwi r6,r3,24
	ctx.r6.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x82287428
	if (cr6.eq) goto loc_82287428;
	// cmplwi cr6,r19,0
	cr6.compare<uint32_t>(r19.u32, 0, xer);
	// beq cr6,0x82287428
	if (cr6.eq) goto loc_82287428;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82287428
	if (cr6.eq) goto loc_82287428;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822952b0
	ctx.lr = 0x82286B68;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287428
	if (cr6.eq) goto loc_82287428;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82286B7C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82286B8C;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82286B94;
	sub_822577D0(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lwz r9,16(r15)
	ctx.r9.u64 = PPC_LOAD_U32(r15.u32 + 16);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// cntlzw r8,r29
	ctx.r8.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r6,r8,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// rlwinm r18,r7,27,31,31
	r18.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// lwz r3,17268(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 17268);
	// xori r23,r6,1
	r23.u64 = ctx.r6.u64 ^ 1;
	// bl 0x822a39c8
	ctx.lr = 0x82286BBC;
	sub_822A39C8(ctx, base);
	// bl 0x822a5ab8
	ctx.lr = 0x82286BC0;
	sub_822A5AB8(ctx, base);
	// addi r5,r3,-2
	ctx.r5.s64 = ctx.r3.s64 + -2;
	// li r4,0
	ctx.r4.s64 = 0;
	// cntlzw r11,r5
	r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// rlwinm r26,r11,27,31,31
	r26.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// bl 0x822952b0
	ctx.lr = 0x82286BD8;
	sub_822952B0(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82286bf8
	if (cr6.eq) goto loc_82286BF8;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295e90
	ctx.lr = 0x82286BF0;
	sub_82295E90(ctx, base);
	// mr r16,r3
	r16.u64 = ctx.r3.u64;
	// b 0x82286bfc
	goto loc_82286BFC;
loc_82286BF8:
	// mr r16,r17
	r16.u64 = r17.u64;
loc_82286BFC:
	// clrlwi r24,r18,24
	r24.u64 = r18.u32 & 0xFF;
	// li r21,1
	r21.s64 = 1;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82286c1c
	if (cr6.eq) goto loc_82286C1C;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// li r25,2
	r25.s64 = 2;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286c20
	if (cr6.eq) goto loc_82286C20;
loc_82286C1C:
	// mr r25,r21
	r25.u64 = r21.u64;
loc_82286C20:
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295e90
	ctx.lr = 0x82286C2C;
	sub_82295E90(ctx, base);
	// cntlzw r11,r3
	r11.u64 = ctx.r3.u32 == 0 ? 32 : __builtin_clz(ctx.r3.u32);
	// cmpwi cr6,r16,2
	cr6.compare<int32_t>(r16.s32, 2, xer);
	// rlwinm r11,r11,27,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// stb r11,81(r1)
	PPC_STORE_U8(ctx.r1.u32 + 81, r11.u8);
	// bne cr6,0x82286c50
	if (!cr6.eq) goto loc_82286C50;
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// stb r21,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r21.u8);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286c54
	if (cr6.eq) goto loc_82286C54;
loc_82286C50:
	// stb r17,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, r17.u8);
loc_82286C54:
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x82286C5C;
	sub_8227E0B0(ctx, base);
	// mr r14,r3
	r14.u64 = ctx.r3.u64;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// beq cr6,0x82286c74
	if (cr6.eq) goto loc_82286C74;
	// cmpwi cr6,r29,1
	cr6.compare<int32_t>(r29.s32, 1, xer);
	// mr r20,r21
	r20.u64 = r21.u64;
	// bne cr6,0x82286c78
	if (!cr6.eq) goto loc_82286C78;
loc_82286C74:
	// mr r20,r17
	r20.u64 = r17.u64;
loc_82286C78:
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82286ca4
	if (!cr6.eq) goto loc_82286CA4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,656(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82286C98;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// mr r28,r21
	r28.u64 = r21.u64;
	// bgt cr6,0x82286ca8
	if (cr6.gt) goto loc_82286CA8;
loc_82286CA4:
	// mr r28,r17
	r28.u64 = r17.u64;
loc_82286CA8:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82286CBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82286d5c
	if (cr6.eq) goto loc_82286D5C;
	// clrlwi r29,r26,24
	r29.u64 = r26.u32 & 0xFF;
	// li r7,16
	ctx.r7.s64 = 16;
	// cntlzw r11,r29
	r11.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r5,0
	ctx.r5.s64 = 0;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// mr r25,r21
	r25.u64 = r21.u64;
	// bl 0x82286498
	ctx.lr = 0x82286CF4;
	sub_82286498(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cntlzw r9,r29
	ctx.r9.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r10,r9,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subfic r7,r11,16
	xer.ca = r11.u32 <= 16;
	ctx.r7.s64 = 16 - r11.s64;
	// bl 0x82286498
	ctx.lr = 0x82286D1C;
	sub_82286498(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r7,r28,24
	ctx.r7.u64 = r28.u32 & 0xFF;
	// add r11,r3,r8
	r11.u64 = ctx.r3.u64 + ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// beq cr6,0x82287068
	if (cr6.eq) goto loc_82287068;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,2
	ctx.r5.s64 = 2;
	// subfic r9,r10,16
	xer.ca = ctx.r10.u32 <= 16;
	ctx.r9.s64 = 16 - ctx.r10.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82286498
	ctx.lr = 0x82286D54;
	sub_82286498(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// b 0x82287114
	goto loc_82287114;
loc_82286D5C:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82287070
	if (cr6.eq) goto loc_82287070;
	// clrlwi r11,r23,24
	r11.u64 = r23.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82286ef0
	if (!cr6.eq) goto loc_82286EF0;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286e7c
	if (cr6.eq) goto loc_82286E7C;
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82286e7c
	if (cr6.eq) goto loc_82286E7C;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82286e04
	if (!cr6.eq) goto loc_82286E04;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r25,r21
	r25.u64 = r21.u64;
	// bl 0x82286498
	ctx.lr = 0x82286DAC;
	sub_82286498(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r7,r11,r27
	ctx.r7.s64 = r27.s64 - r11.s64;
	// bl 0x82286498
	ctx.lr = 0x82286DCC;
	sub_82286498(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// bl 0x82286498
	ctx.lr = 0x82286DF4;
	sub_82286498(ctx, base);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// b 0x82287114
	goto loc_82287114;
loc_82286E04:
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x82287114
	if (!cr6.eq) goto loc_82287114;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r25,r21
	r25.u64 = r21.u64;
	// bl 0x82286498
	ctx.lr = 0x82286E28;
	sub_82286498(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82286498
	ctx.lr = 0x82286E44;
	sub_82286498(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// bl 0x82286498
	ctx.lr = 0x82286E6C;
	sub_82286498(ctx, base);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// b 0x82287114
	goto loc_82287114;
loc_82286E7C:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r25,2
	r25.s64 = 2;
	// bl 0x82286498
	ctx.lr = 0x82286E98;
	sub_82286498(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r7,r11,r27
	ctx.r7.s64 = r27.s64 - r11.s64;
	// bl 0x82286498
	ctx.lr = 0x82286EB8;
	sub_82286498(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,84(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// subf r9,r11,r27
	ctx.r9.s64 = r27.s64 - r11.s64;
	// li r5,2
	ctx.r5.s64 = 2;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r7,r10,r9
	ctx.r7.s64 = ctx.r9.s64 - ctx.r10.s64;
	// bl 0x82286498
	ctx.lr = 0x82286EE0;
	sub_82286498(ctx, base);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64;
	// stw r7,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r7.u32);
	// b 0x82287114
	goto loc_82287114;
loc_82286EF0:
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82287070
	if (cr6.eq) goto loc_82287070;
	// lwz r11,24(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 24);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bne cr6,0x82287070
	if (!cr6.eq) goto loc_82287070;
	// clrlwi r11,r30,24
	r11.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82286fd4
	if (cr6.eq) goto loc_82286FD4;
	// clrlwi r29,r26,24
	r29.u64 = r26.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x82286f30
	if (cr6.eq) goto loc_82286F30;
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x82286fd4
	if (cr6.eq) goto loc_82286FD4;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// bne cr6,0x82286f3c
	if (!cr6.eq) goto loc_82286F3C;
loc_82286F30:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// beq cr6,0x82286fd4
	if (cr6.eq) goto loc_82286FD4;
loc_82286F3C:
	// lwz r11,108(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 108);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// cntlzw r11,r29
	r11.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bne cr6,0x82286ff8
	if (!cr6.eq) goto loc_82286FF8;
	// li r25,2
	r25.s64 = 2;
	// bl 0x82286498
	ctx.lr = 0x82286F70;
	sub_82286498(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cntlzw r9,r29
	ctx.r9.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82286498
	ctx.lr = 0x82286F94;
	sub_82286498(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r7,r28,24
	ctx.r7.u64 = r28.u32 & 0xFF;
	// add r11,r3,r8
	r11.u64 = ctx.r3.u64 + ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// beq cr6,0x82287068
	if (cr6.eq) goto loc_82287068;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// subf r9,r10,r27
	ctx.r9.s64 = r27.s64 - ctx.r10.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82286498
	ctx.lr = 0x82286FCC;
	sub_82286498(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// b 0x82287114
	goto loc_82287114;
loc_82286FD4:
	// clrlwi r29,r26,24
	r29.u64 = r26.u32 & 0xFF;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// cntlzw r11,r29
	r11.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// li r5,0
	ctx.r5.s64 = 0;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
loc_82286FF8:
	// mr r25,r21
	r25.u64 = r21.u64;
	// bl 0x82286498
	ctx.lr = 0x82287000;
	sub_82286498(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cntlzw r9,r29
	ctx.r9.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// rlwinm r10,r9,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// subf r7,r11,r27
	ctx.r7.s64 = r27.s64 - r11.s64;
	// bl 0x82286498
	ctx.lr = 0x82287028;
	sub_82286498(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// clrlwi r7,r28,24
	ctx.r7.u64 = r28.u32 & 0xFF;
	// add r11,r3,r8
	r11.u64 = ctx.r3.u64 + ctx.r8.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// beq cr6,0x82287068
	if (cr6.eq) goto loc_82287068;
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// subf r9,r10,r27
	ctx.r9.s64 = r27.s64 - ctx.r10.s64;
	// li r4,0
	ctx.r4.s64 = 0;
	// subf r7,r11,r9
	ctx.r7.s64 = ctx.r9.s64 - r11.s64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82286498
	ctx.lr = 0x82287060;
	sub_82286498(ctx, base);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// b 0x82287114
	goto loc_82287114;
loc_82287068:
	// stw r17,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r17.u32);
	// b 0x82287114
	goto loc_82287114;
loc_82287070:
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// beq cr6,0x822870e0
	if (cr6.eq) goto loc_822870E0;
	// clrlwi r29,r26,24
	r29.u64 = r26.u32 & 0xFF;
	// rlwinm r28,r27,31,1,31
	r28.u64 = __builtin_rotateleft64(r27.u32 | (r27.u64 << 32), 31) & 0x7FFFFFFF;
	// cntlzw r11,r29
	r11.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// rlwinm r10,r11,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 27) & 0x1;
	// xori r11,r10,1
	r11.u64 = ctx.r10.u64 ^ 1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// bl 0x82286498
	ctx.lr = 0x822870A8;
	sub_82286498(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// stw r22,112(r31)
	PPC_STORE_U32(r31.u32 + 112, r22.u32);
	// cntlzw r9,r29
	ctx.r9.u64 = r29.u32 == 0 ? 32 : __builtin_clz(r29.u32);
	// mr r7,r28
	ctx.r7.u64 = r28.u64;
	// rlwinm r11,r9,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,1
	ctx.r4.s64 = r11.s64 + 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82286498
	ctx.lr = 0x822870D0;
	sub_82286498(ctx, base);
	// lwz r8,84(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r7,r3,r8
	ctx.r7.u64 = ctx.r3.u64 + ctx.r8.u64;
	// stw r7,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// b 0x82287114
	goto loc_82287114;
loc_822870E0:
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x82286498
	ctx.lr = 0x822870EC;
	sub_82286498(ctx, base);
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82286498
	ctx.lr = 0x82287108;
	sub_82286498(ctx, base);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + r11.u64;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
loc_82287114:
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x8228712c
	if (!cr6.eq) goto loc_8228712C;
	// lwz r11,88(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// stw r17,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r17.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
loc_8228712C:
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// mr r6,r25
	ctx.r6.u64 = r25.u64;
	// mr r5,r18
	ctx.r5.u64 = r18.u64;
	// mr r4,r16
	ctx.r4.u64 = r16.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822848d8
	ctx.lr = 0x82287144;
	sub_822848D8(ctx, base);
	// clrlwi r29,r30,24
	r29.u64 = r30.u32 & 0xFF;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822871d4
	if (cr6.eq) goto loc_822871D4;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// beq cr6,0x822871d4
	if (cr6.eq) goto loc_822871D4;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// addi r4,r10,2592
	ctx.r4.s64 = ctx.r10.s64 + 2592;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// bne cr6,0x8228719c
	if (!cr6.eq) goto loc_8228719C;
	// stw r27,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r27.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82287190;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r17.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// b 0x822871f8
	goto loc_822871F8;
loc_8228719C:
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822871A8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r19)
	ctx.r7.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// subf r11,r6,r27
	r11.s64 = r27.s64 - ctx.r6.s64;
	// addi r4,r8,2580
	ctx.r4.s64 = ctx.r8.s64 + 2580;
	// lwz r10,44(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r11.u32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// b 0x82287210
	goto loc_82287210;
loc_822871D4:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r10,2592
	ctx.r4.s64 = ctx.r10.s64 + 2592;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822871F4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
loc_822871F8:
	// lwz r7,0(r19)
	ctx.r7.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// addi r4,r8,2580
	ctx.r4.s64 = ctx.r8.s64 + 2580;
	// lwz r6,44(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_82287210:
	// bctrl 
	ctx.lr = 0x82287214;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r10,81(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 81);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82287270
	if (cr6.eq) goto loc_82287270;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,668(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 668);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82287234;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x82287270
	if (cr6.eq) goto loc_82287270;
	// clrlwi r11,r14,24
	r11.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287270
	if (cr6.eq) goto loc_82287270;
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// ble cr6,0x82287270
	if (!cr6.gt) goto loc_82287270;
	// mr r3,r15
	ctx.r3.u64 = r15.u64;
	// bl 0x82280080
	ctx.lr = 0x82287260;
	sub_82280080(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// stw r21,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r21.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287274
	if (cr6.eq) goto loc_82287274;
loc_82287270:
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r17.u32);
loc_82287274:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r10,2564
	ctx.r4.s64 = ctx.r10.s64 + 2564;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82287294;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lbz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// lwz r9,0(r19)
	ctx.r9.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// cntlzw r3,r6
	ctx.r3.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r4,r7,2556
	ctx.r4.s64 = ctx.r7.s64 + 2556;
	// rlwinm r11,r3,27,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// xori r10,r11,1
	ctx.r10.u64 = r11.u64 ^ 1;
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// stw r10,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822872C8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r30,r14,24
	r30.u64 = r14.u32 & 0xFF;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x822872e4
	if (cr6.eq) goto loc_822872E4;
	// lwz r11,24(r15)
	r11.u64 = PPC_LOAD_U32(r15.u32 + 24);
	// stw r21,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r21.u32);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// beq cr6,0x822872e8
	if (cr6.eq) goto loc_822872E8;
loc_822872E4:
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r17.u32);
loc_822872E8:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r10,2544
	ctx.r4.s64 = ctx.r10.s64 + 2544;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82287308;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82287340
	if (cr6.eq) goto loc_82287340;
	// cmpwi cr6,r25,1
	cr6.compare<int32_t>(r25.s32, 1, xer);
	// bne cr6,0x822873d0
	if (!cr6.eq) goto loc_822873D0;
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r9,3
	ctx.r9.s64 = 3;
	// addi r4,r10,2532
	ctx.r4.s64 = ctx.r10.s64 + 2532;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r8,44(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// b 0x822873cc
	goto loc_822873CC;
loc_82287340:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r17.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r10,2520
	ctx.r4.s64 = ctx.r10.s64 + 2520;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82287364;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,88(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// bne cr6,0x82287378
	if (!cr6.eq) goto loc_82287378;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x822873d0
	if (cr6.eq) goto loc_822873D0;
loc_82287378:
	// li r30,3
	r30.s64 = 3;
	// stw r17,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r17.u32);
	// cmpwi cr6,r25,1
	cr6.compare<int32_t>(r25.s32, 1, xer);
	// beq cr6,0x8228738c
	if (cr6.eq) goto loc_8228738C;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
loc_8228738C:
	// lwz r11,0(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r10,2508
	ctx.r4.s64 = ctx.r10.s64 + 2508;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822873AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,0(r19)
	ctx.r7.u64 = PPC_LOAD_U32(r19.u32 + 0);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// stw r30,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r30.u32);
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r8,2532
	ctx.r4.s64 = ctx.r8.s64 + 2532;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// lwz r6,44(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 44);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
loc_822873CC:
	// bctrl 
	ctx.lr = 0x822873D0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822873D0:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,576(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 576);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x822873E4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r10,480(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 480);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822873F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82287410
	if (cr6.eq) goto loc_82287410;
	// bl 0x8221cd00
	ctx.lr = 0x82287404;
	sub_8221CD00(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82287428
	if (!cr6.eq) goto loc_82287428;
loc_82287410:
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
	ctx.lr = 0x82287428;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82287428:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,660(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 660);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8228743C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,84(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,88(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + r11.u64;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x823d9210
	return;
}

__attribute__((alias("__imp__sub_82287450"))) PPC_WEAK_FUNC(sub_82287450);
PPC_FUNC_IMPL(__imp__sub_82287450) {
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
	ctx.lr = 0x82287458;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r11,48(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addi r3,r11,224
	ctx.r3.s64 = r11.s64 + 224;
	// lwz r10,224(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 224);
	// lwz r9,32(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82287480;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r26,-32121
	r26.s64 = -2105081856;
	// li r25,0
	r25.s64 = 0;
	// addi r27,r3,8
	r27.s64 = ctx.r3.s64 + 8;
	// lwz r10,17268(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 17268);
loc_82287490:
	// lwz r31,0(r27)
	r31.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// beq cr6,0x82287538
	if (cr6.eq) goto loc_82287538;
	// addi r28,r24,-48
	r28.s64 = r24.s64 + -48;
loc_822874A0:
	// lwz r30,8(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r4,4(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 4);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// lwz r29,120(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 120);
	// blt cr6,0x82287520
	if (cr6.lt) goto loc_82287520;
	// lwz r11,0(r13)
	r11.u64 = PPC_LOAD_U32(ctx.r13.u32 + 0);
	// li r9,72
	ctx.r9.s64 = 72;
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822874dc
	if (cr6.eq) goto loc_822874DC;
	// lwz r11,260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 260);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82287500
	if (!cr6.lt) goto loc_82287500;
	// addi r11,r4,34
	r11.s64 = ctx.r4.s64 + 34;
	// b 0x822874ec
	goto loc_822874EC;
loc_822874DC:
	// lwz r11,132(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 132);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// bge cr6,0x82287500
	if (!cr6.lt) goto loc_82287500;
	// addi r11,r4,2
	r11.s64 = ctx.r4.s64 + 2;
loc_822874EC:
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r11,1
	r11.s64 = 1;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x82287504
	if (!cr6.eq) goto loc_82287504;
loc_82287500:
	// li r11,0
	r11.s64 = 0;
loc_82287504:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287520
	if (cr6.eq) goto loc_82287520;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x822a3998
	ctx.lr = 0x82287518;
	sub_822A3998(ctx, base);
	// lwz r10,17268(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 17268);
	// b 0x82287524
	goto loc_82287524;
loc_82287520:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82287524:
	// cmplw cr6,r29,r3
	cr6.compare<uint32_t>(r29.u32, ctx.r3.u32, xer);
	// beq cr6,0x82287554
	if (cr6.eq) goto loc_82287554;
	// lwz r31,0(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplw cr6,r31,r27
	cr6.compare<uint32_t>(r31.u32, r27.u32, xer);
	// bne cr6,0x822874a0
	if (!cr6.eq) goto loc_822874A0;
loc_82287538:
	// addi r25,r25,1
	r25.s64 = r25.s64 + 1;
	// addi r27,r27,8
	r27.s64 = r27.s64 + 8;
	// cmpwi cr6,r25,7
	cr6.compare<int32_t>(r25.s32, 7, xer);
	// blt cr6,0x82287490
	if (cr6.lt) goto loc_82287490;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
loc_82287554:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

__attribute__((alias("__imp__sub_82287560"))) PPC_WEAK_FUNC(sub_82287560);
PPC_FUNC_IMPL(__imp__sub_82287560) {
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
	ctx.lr = 0x82287568;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// li r26,0
	r26.s64 = 0;
	// lwz r8,148(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lis r23,-32121
	r23.s64 = -2105081856;
	// lis r25,-32121
	r25.s64 = -2105081856;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// addi r24,r11,2688
	r24.s64 = r11.s64 + 2688;
	// addi r28,r10,2680
	r28.s64 = ctx.r10.s64 + 2680;
	// addi r27,r9,2672
	r27.s64 = ctx.r9.s64 + 2672;
	// beq cr6,0x8228770c
	if (cr6.eq) goto loc_8228770C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822875A8;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822875B8;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x8228770c
	if (cr6.eq) goto loc_8228770C;
	// lwz r4,-44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -44);
	// lwz r30,148(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82287630
	if (cr6.lt) goto loc_82287630;
	// lwz r3,17268(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x822875DC;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287630
	if (cr6.eq) goto loc_82287630;
	// addi r29,r31,-48
	r29.s64 = r31.s64 + -48;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822842e0
	ctx.lr = 0x822875F4;
	sub_822842E0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82287630
	if (cr6.eq) goto loc_82287630;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822842e0
	ctx.lr = 0x82287604;
	sub_822842E0(ctx, base);
	// bl 0x82203310
	ctx.lr = 0x82287608;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287630
	if (cr6.eq) goto loc_82287630;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82287628;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x822855d8
	ctx.lr = 0x82287630;
	sub_822855D8(ctx, base);
loc_82287630:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,332(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 332);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82287644;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x82287654;
	sub_827227B8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r5,-40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// bl 0x827227b8
	ctx.lr = 0x82287664;
	sub_827227B8(ctx, base);
	// lwz r11,-28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -28);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228767c
	if (cr6.eq) goto loc_8228767C;
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82287680
	if (!cr6.eq) goto loc_82287680;
loc_8228767C:
	// lwz r11,-36(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -36);
loc_82287680:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r5,r11
	ctx.r5.u64 = r11.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x827227b8
	ctx.lr = 0x82287690;
	sub_827227B8(ctx, base);
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r5,r31,-24
	ctx.r5.s64 = r31.s64 + -24;
	// addi r4,r11,2664
	ctx.r4.s64 = r11.s64 + 2664;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x822876A4;
	sub_82722678(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r31,-20
	ctx.r5.s64 = r31.s64 + -20;
	// addi r4,r10,2652
	ctx.r4.s64 = ctx.r10.s64 + 2652;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x822876B8;
	sub_82722678(ctx, base);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r9,20292
	ctx.r4.s64 = ctx.r9.s64 + 20292;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x822876D0;
	sub_82722678(ctx, base);
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// addi r5,r31,-16
	ctx.r5.s64 = r31.s64 + -16;
	// addi r4,r8,2556
	ctx.r4.s64 = ctx.r8.s64 + 2556;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x822876E4;
	sub_82722678(ctx, base);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// addi r5,r31,-8
	ctx.r5.s64 = r31.s64 + -8;
	// addi r4,r7,2640
	ctx.r4.s64 = ctx.r7.s64 + 2640;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x822876F8;
	sub_82722678(ctx, base);
	// lis r6,-32253
	ctx.r6.s64 = -2113732608;
	// addi r5,r31,-12
	ctx.r5.s64 = r31.s64 + -12;
	// addi r4,r6,2620
	ctx.r4.s64 = ctx.r6.s64 + 2620;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82722678
	ctx.lr = 0x8228770C;
	sub_82722678(ctx, base);
loc_8228770C:
	// lwz r4,-44(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -44);
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x8228793c
	if (cr6.lt) goto loc_8228793C;
	// lwz r3,17268(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 17268);
	// bl 0x821e80f8
	ctx.lr = 0x82287720;
	sub_821E80F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x8228793c
	if (cr6.eq) goto loc_8228793C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r4,r10,-18768
	ctx.r4.s64 = ctx.r10.s64 + -18768;
	// lwz r3,-10236(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// bl 0x821f9fb8
	ctx.lr = 0x82287740;
	sub_821F9FB8(ctx, base);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// addi r30,r9,2612
	r30.s64 = ctx.r9.s64 + 2612;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r29,56(r8)
	r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + 56);
	// bl 0x821c9790
	ctx.lr = 0x8228775C;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x825ed480
	ctx.lr = 0x8228776C;
	sub_825ED480(ctx, base);
	// bl 0x825ef9f0
	ctx.lr = 0x82287770;
	sub_825EF9F0(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r6,7
	ctx.r6.s64 = 7;
	// stw r26,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, r26.u32);
	// addi r5,r7,-12116
	ctx.r5.s64 = ctx.r7.s64 + -12116;
	// stw r6,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x821c9790
	ctx.lr = 0x82287798;
	sub_821C9790(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r3,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r3.u32);
	// addi r5,r1,104
	ctx.r5.s64 = ctx.r1.s64 + 104;
	// stw r4,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822877C0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x825ef9f0
	ctx.lr = 0x822877C8;
	sub_825EF9F0(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,80(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 80);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822877DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addi r30,r31,-48
	r30.s64 = r31.s64 + -48;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82284368
	ctx.lr = 0x822877EC;
	sub_82284368(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r6,332(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 332);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82287804;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x827227b8
	ctx.lr = 0x82287814;
	sub_827227B8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r5,-40(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -40);
	// bl 0x827227b8
	ctx.lr = 0x82287824;
	sub_827227B8(ctx, base);
	// lwz r5,148(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// addi r28,r11,3998
	r28.s64 = r11.s64 + 3998;
	// beq cr6,0x822878a4
	if (cr6.eq) goto loc_822878A4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82287840;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82287850;
	sub_82270170(ctx, base);
	// lwz r10,208(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x822878a4
	if (cr6.eq) goto loc_822878A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822842e0
	ctx.lr = 0x82287864;
	sub_822842E0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822878a4
	if (cr6.eq) goto loc_822878A4;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822842e0
	ctx.lr = 0x82287874;
	sub_822842E0(ctx, base);
	// bl 0x82203310
	ctx.lr = 0x82287878;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822878a4
	if (cr6.eq) goto loc_822878A4;
	// lwz r5,20(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 20);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x8228789c
	if (cr6.eq) goto loc_8228789C;
	// lbz r11,0(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822878a8
	if (!cr6.eq) goto loc_822878A8;
loc_8228789C:
	// lwz r5,12(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 12);
	// b 0x822878a8
	goto loc_822878A8;
loc_822878A4:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
loc_822878A8:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827227b8
	ctx.lr = 0x822878B4;
	sub_827227B8(ctx, base);
	// cmplwi cr6,r26,0
	cr6.compare<uint32_t>(r26.u32, 0, xer);
	// beq cr6,0x82287928
	if (cr6.eq) goto loc_82287928;
	// lwz r3,17268(r23)
	ctx.r3.u64 = PPC_LOAD_U32(r23.u32 + 17268);
	// bl 0x822a39c8
	ctx.lr = 0x822878C4;
	sub_822A39C8(ctx, base);
	// cmplw cr6,r26,r3
	cr6.compare<uint32_t>(r26.u32, ctx.r3.u32, xer);
	// beq cr6,0x82287928
	if (cr6.eq) goto loc_82287928;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,556(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 556);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822878E0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822878f8
	if (cr6.eq) goto loc_822878F8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-11224
	ctx.r4.s64 = r11.s64 + -11224;
	// b 0x82287900
	goto loc_82287900;
loc_822878F8:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r4,r11,-11204
	ctx.r4.s64 = r11.s64 + -11204;
loc_82287900:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x8228790C;
	sub_82218310(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r10,2604
	ctx.r4.s64 = ctx.r10.s64 + 2604;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827227b8
	ctx.lr = 0x82287920;
	sub_827227B8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
loc_82287928:
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r4,r11,2604
	ctx.r4.s64 = r11.s64 + 2604;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x827227b8
	ctx.lr = 0x8228793C;
	sub_827227B8(ctx, base);
loc_8228793C:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9234
	return;
}

__attribute__((alias("__imp__sub_82287944"))) PPC_WEAK_FUNC(sub_82287944);
PPC_FUNC_IMPL(__imp__sub_82287944) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82287948"))) PPC_WEAK_FUNC(sub_82287948);
PPC_FUNC_IMPL(__imp__sub_82287948) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x82287950;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r21,0
	r21.s64 = 0;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x82287970
	if (cr6.eq) goto loc_82287970;
	// lwz r27,1220(r24)
	r27.u64 = PPC_LOAD_U32(r24.u32 + 1220);
	// b 0x82287974
	goto loc_82287974;
loc_82287970:
	// mr r27,r21
	r27.u64 = r21.u64;
loc_82287974:
	// lis r26,-32121
	r26.s64 = -2105081856;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// lwz r11,-3624(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -3624);
	// lwz r22,700(r11)
	r22.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// beq cr6,0x82287990
	if (cr6.eq) goto loc_82287990;
	// lwz r11,136(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 136);
	// b 0x82287994
	goto loc_82287994;
loc_82287990:
	// li r11,-1
	r11.s64 = -1;
loc_82287994:
	// stw r11,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r11.u32);
	// cmplwi cr6,r27,0
	cr6.compare<uint32_t>(r27.u32, 0, xer);
	// beq cr6,0x82287dcc
	if (cr6.eq) goto loc_82287DCC;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82203310
	ctx.lr = 0x822879A8;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287dcc
	if (cr6.eq) goto loc_82287DCC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822879BC;
	sub_82388580(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r4,4(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// bl 0x82270170
	ctx.lr = 0x822879CC;
	sub_82270170(ctx, base);
	// lwz r11,208(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 208);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82287dcc
	if (cr6.eq) goto loc_82287DCC;
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r29,0(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,36(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822879F0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r9,20(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82287A04;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,12(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82287A1C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r5,8(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mtctr r5
	ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x82287A30;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x822855d8
	ctx.lr = 0x82287A38;
	sub_822855D8(ctx, base);
	// lwz r11,0(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// lwz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82287A50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// stw r3,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r3.u32);
	// li r25,3
	r25.s64 = 3;
	// addi r8,r9,19816
	ctx.r8.s64 = ctx.r9.s64 + 19816;
	// stw r21,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r21.u32);
	// li r23,1
	r23.s64 = 1;
	// lwz r11,4(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82287c1c
	if (!cr6.eq) goto loc_82287C1C;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r11,4300(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82287c1c
	if (cr6.eq) goto loc_82287C1C;
	// lbz r11,278(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82287c1c
	if (!cr6.eq) goto loc_82287C1C;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82203310
	ctx.lr = 0x82287A98;
	sub_82203310(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287c1c
	if (cr6.eq) goto loc_82287C1C;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822577d0
	ctx.lr = 0x82287AB0;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x82287c1c
	if (!cr6.eq) goto loc_82287C1C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82287AC0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82287AD0;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272e60
	ctx.lr = 0x82287AD8;
	sub_82272E60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82287b10
	if (!cr6.eq) goto loc_82287B10;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82287AEC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82287AFC;
	sub_82270170(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82272e60
	ctx.lr = 0x82287B04;
	sub_82272E60(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82287c1c
	if (cr6.eq) goto loc_82287C1C;
loc_82287B10:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82287B18;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82287B28;
	sub_82270170(ctx, base);
	// cmplw cr6,r27,r3
	cr6.compare<uint32_t>(r27.u32, ctx.r3.u32, xer);
	// beq cr6,0x82287b7c
	if (cr6.eq) goto loc_82287B7C;
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x824e7110
	ctx.lr = 0x82287B38;
	sub_824E7110(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82287B44;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82287B54;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82287B5C;
	sub_821F8730(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82463d20
	ctx.lr = 0x82287B70;
	sub_82463D20(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82287c1c
	if (cr6.eq) goto loc_82287C1C;
loc_82287B7C:
	// stw r23,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r23.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82287B88;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82287B98;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x821f8730
	ctx.lr = 0x82287BA0;
	sub_821F8730(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x82287bb8
	if (!cr6.eq) goto loc_82287BB8;
	// lbz r11,281(r27)
	r11.u64 = PPC_LOAD_U8(r27.u32 + 281);
	// mr r28,r21
	r28.u64 = r21.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287bbc
	if (cr6.eq) goto loc_82287BBC;
loc_82287BB8:
	// mr r28,r23
	r28.u64 = r23.u64;
loc_82287BBC:
	// addi r29,r27,16
	r29.s64 = r27.s64 + 16;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x824e7110
	ctx.lr = 0x82287BC8;
	sub_824E7110(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x82463cb8
	ctx.lr = 0x82287BDC;
	sub_82463CB8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287bf4
	if (cr6.eq) goto loc_82287BF4;
	// li r11,2
	r11.s64 = 2;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
	// b 0x82287c1c
	goto loc_82287C1C;
loc_82287BF4:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82502300
	ctx.lr = 0x82287BFC;
	sub_82502300(ctx, base);
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4300(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4300);
	// bl 0x824649b0
	ctx.lr = 0x82287C0C;
	sub_824649B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287c1c
	if (cr6.eq) goto loc_82287C1C;
	// stw r25,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r25.u32);
loc_82287C1C:
	// stw r21,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r21.u32);
	// addi r3,r27,16
	ctx.r3.s64 = r27.s64 + 16;
	// bl 0x824e7060
	ctx.lr = 0x82287C28;
	sub_824E7060(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287cc8
	if (cr6.eq) goto loc_82287CC8;
	// lwz r11,-10240(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10240);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// lwz r3,4296(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4296);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82287C50;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82287cc8
	if (cr6.eq) goto loc_82287CC8;
	// lwz r11,200(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// lwz r11,-3624(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -3624);
	// lwz r10,200(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// lwz r8,20(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r9,28(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// bge cr6,0x82287c84
	if (!cr6.lt) goto loc_82287C84;
	// li r11,4
	r11.s64 = 4;
	// stw r11,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r11.u32);
	// b 0x82287cc8
	goto loc_82287CC8;
loc_82287C84:
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r10,200(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 200);
	// lwz r11,28(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwz r7,24(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 24);
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - r11.s64;
	// rlwinm r9,r6,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + r11.u64;
	// cmplw cr6,r10,r5
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, xer);
	// bge cr6,0x82287cb0
	if (!cr6.lt) goto loc_82287CB0;
	// stw r25,36(r31)
	PPC_STORE_U32(r31.u32 + 36, r25.u32);
	// b 0x82287cc8
	goto loc_82287CC8;
loc_82287CB0:
	// lwz r11,24(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// subfc r10,r11,r10
	xer.ca = ctx.r10.u32 >= r11.u32;
	ctx.r10.s64 = ctx.r10.s64 - r11.s64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + xer.ca < xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + xer.ca;
	xer.ca = temp.u8;
	// clrlwi r11,r9,31
	r11.u64 = ctx.r9.u32 & 0x1;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,36(r31)
	PPC_STORE_U32(r31.u32 + 36, ctx.r8.u32);
loc_82287CC8:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822577d0
	ctx.lr = 0x82287CD4;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82287d64
	if (cr6.eq) goto loc_82287D64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822577d0
	ctx.lr = 0x82287CE8;
	sub_822577D0(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r11,r4
	cr6.compare<uint32_t>(r11.u32, ctx.r4.u32, xer);
	// bne cr6,0x82287d14
	if (!cr6.eq) goto loc_82287D14;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// mr r4,r11
	ctx.r4.u64 = r11.u64;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// bl 0x822183a8
	ctx.lr = 0x82287D0C;
	sub_822183A8(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// b 0x82287d70
	goto loc_82287D70;
loc_82287D14:
	// lwz r11,4(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 4);
	// stw r21,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r21.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x82287d70
	if (cr6.eq) goto loc_82287D70;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x82389668
	ctx.lr = 0x82287D30;
	sub_82389668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287d70
	if (cr6.eq) goto loc_82287D70;
	// lwz r11,4(r22)
	r11.u64 = PPC_LOAD_U32(r22.u32 + 4);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r9,80(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,36(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 36);
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// lwzx r4,r7,r8
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// bl 0x82218310
	ctx.lr = 0x82287D5C;
	sub_82218310(ctx, base);
	// stw r3,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r3.u32);
	// b 0x82287d70
	goto loc_82287D70;
loc_82287D64:
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r11,-8204(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -8204);
	// stw r11,16(r31)
	PPC_STORE_U32(r31.u32 + 16, r11.u32);
loc_82287D70:
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822577d0
	ctx.lr = 0x82287D7C;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x82287d8c
	if (cr6.eq) goto loc_82287D8C;
	// stw r23,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r23.u32);
	// b 0x82287d90
	goto loc_82287D90;
loc_82287D8C:
	// stw r21,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r21.u32);
loc_82287D90:
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// li r11,-1
	r11.s64 = -1;
	// stw r11,32(r31)
	PPC_STORE_U32(r31.u32 + 32, r11.u32);
	// lwz r30,-5052(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + -5052);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82287dcc
	if (cr6.eq) goto loc_82287DCC;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257da8
	ctx.lr = 0x82287DB4;
	sub_82257DA8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	cr6.compare<int32_t>(ctx.r4.s32, 0, xer);
	// blt cr6,0x82287dcc
	if (cr6.lt) goto loc_82287DCC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82257d78
	ctx.lr = 0x82287DC8;
	sub_82257D78(ctx, base);
	// stw r3,32(r31)
	PPC_STORE_U32(r31.u32 + 32, ctx.r3.u32);
loc_82287DCC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

__attribute__((alias("__imp__sub_82287DD4"))) PPC_WEAK_FUNC(sub_82287DD4);
PPC_FUNC_IMPL(__imp__sub_82287DD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82287DD8"))) PPC_WEAK_FUNC(sub_82287DD8);
PPC_FUNC_IMPL(__imp__sub_82287DD8) {
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
	ctx.lr = 0x82287DE0;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r10,-2628
	ctx.r4.s64 = ctx.r10.s64 + -2628;
	// lwz r3,-10240(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82287DFC;
	sub_822701C8(ctx, base);
	// lis r29,-32121
	r29.s64 = -2105081856;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,-3624(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// lwz r8,496(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 496);
	// lwz r27,700(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82287E20;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x82288038
	if (cr6.eq) goto loc_82288038;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x8227d3a0
	ctx.lr = 0x82287E34;
	sub_8227D3A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82288010
	if (cr6.eq) goto loc_82288010;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x82288010
	if (cr6.eq) goto loc_82288010;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x822952b0
	ctx.lr = 0x82287E54;
	sub_822952B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82288010
	if (cr6.eq) goto loc_82288010;
	// lwz r3,-3624(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -3624);
	// bl 0x8226b2a0
	ctx.lr = 0x82287E68;
	sub_8226B2A0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82288010
	if (cr6.eq) goto loc_82288010;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x822801f0
	ctx.lr = 0x82287E7C;
	sub_822801F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82287ea8
	if (cr6.eq) goto loc_82287EA8;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295e90
	ctx.lr = 0x82287E94;
	sub_82295E90(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82287eac
	if (!cr6.eq) goto loc_82287EAC;
loc_82287EA8:
	// li r11,0
	r11.s64 = 0;
loc_82287EAC:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r28,r11,24
	r28.u64 = r11.u32 & 0xFF;
	// bl 0x82286ab8
	ctx.lr = 0x82287EBC;
	sub_82286AB8(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,576(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 576);
	// lwz r29,80(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82287ED4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r3,r29
	cr6.compare<int32_t>(ctx.r3.s32, r29.s32, xer);
	// blt cr6,0x82287ef4
	if (cr6.lt) goto loc_82287EF4;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r29,-1
	ctx.r4.s64 = r29.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,580(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 580);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82287EF4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_82287EF4:
	// clrlwi r11,r28,24
	r11.u64 = r28.u32 & 0xFF;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r9,-32253
	ctx.r9.s64 = -2113732608;
	// cntlzw r8,r11
	ctx.r8.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// addi r4,r9,2740
	ctx.r4.s64 = ctx.r9.s64 + 2740;
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// lwz r6,44(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 44);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// xori r11,r7,1
	r11.u64 = ctx.r7.u64 ^ 1;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x82287F28;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r5,r31,124
	ctx.r5.s64 = r31.s64 + 124;
	// addi r4,r10,2732
	ctx.r4.s64 = ctx.r10.s64 + 2732;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,44(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 44);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82287F48;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r7,-32253
	ctx.r7.s64 = -2113732608;
	// li r6,2
	ctx.r6.s64 = 2;
	// addi r4,r7,2716
	ctx.r4.s64 = ctx.r7.s64 + 2716;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lwz r10,44(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82287F70;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,148(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 148);
	// cmpwi cr6,r9,1
	cr6.compare<int32_t>(ctx.r9.s32, 1, xer);
	// ble cr6,0x82287f94
	if (!cr6.gt) goto loc_82287F94;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82280320
	ctx.lr = 0x82287F84;
	sub_82280320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// li r11,1
	r11.s64 = 1;
	// bne cr6,0x82287f98
	if (!cr6.eq) goto loc_82287F98;
loc_82287F94:
	// li r11,0
	r11.s64 = 0;
loc_82287F98:
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r10,2696
	ctx.r4.s64 = ctx.r10.s64 + 2696;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,44(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 44);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82287FBC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82638c50
	ctx.lr = 0x82287FC4;
	sub_82638C50(ctx, base);
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
	ctx.lr = 0x82287FE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x825ee0e0
	ctx.lr = 0x82287FEC;
	sub_825EE0E0(ctx, base);
	// lwz r5,0(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r4,500(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 500);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x82288000;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x82720e28
	ctx.lr = 0x82288008;
	sub_82720E28(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
loc_82288010:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r31,r10,-19772
	r31.s64 = ctx.r10.s64 + -19772;
	// lwz r9,468(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 468);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8228802C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x825ee0e0
	ctx.lr = 0x82288038;
	sub_825EE0E0(ctx, base);
loc_82288038:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9244
	return;
}

__attribute__((alias("__imp__sub_82288040"))) PPC_WEAK_FUNC(sub_82288040);
PPC_FUNC_IMPL(__imp__sub_82288040) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91d0
	ctx.lr = 0x82288048;
	// stfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -128, f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r19,-32121
	r19.s64 = -2105081856;
	// mr r27,r5
	r27.u64 = ctx.r5.u64;
	// mr r20,r3
	r20.u64 = ctx.r3.u64;
	// mr r24,r4
	r24.u64 = ctx.r4.u64;
	// mr r23,r6
	r23.u64 = ctx.r6.u64;
	// lwz r11,-10236(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10236);
	// mr r29,r7
	r29.u64 = ctx.r7.u64;
	// mr r22,r8
	r22.u64 = ctx.r8.u64;
	// lwz r11,52(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// addis r10,r11,4
	ctx.r10.s64 = r11.s64 + 262144;
	// addi r10,r10,976
	ctx.r10.s64 = ctx.r10.s64 + 976;
	// cmplw cr6,r27,r10
	cr6.compare<uint32_t>(r27.u32, ctx.r10.u32, xer);
	// bne cr6,0x82288924
	if (!cr6.eq) goto loc_82288924;
	// lwz r31,0(r20)
	r31.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// addi r30,r11,-18512
	r30.s64 = r11.s64 + -18512;
	// addi r28,r10,-22132
	r28.s64 = ctx.r10.s64 + -22132;
	// lwz r9,576(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 576);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x822880A4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r8,480(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 480);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x822880B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x822880CC;
	sub_823DEDD8(ctx, base);
	// lis r11,-32130
	r11.s64 = -2105671680;
	// lwz r10,32(r20)
	ctx.r10.u64 = PPC_LOAD_U32(r20.u32 + 32);
	// lis r9,-32130
	ctx.r9.s64 = -2105671680;
	// addi r21,r11,-22108
	r21.s64 = r11.s64 + -22108;
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// addi r6,r9,-17564
	ctx.r6.s64 = ctx.r9.s64 + -17564;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x823dedd8
	ctx.lr = 0x822880F8;
	sub_823DEDD8(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r8,-32253
	ctx.r8.s64 = -2113732608;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r4,r8,-2628
	ctx.r4.s64 = ctx.r8.s64 + -2628;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// bl 0x822701c8
	ctx.lr = 0x82288110;
	sub_822701C8(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r18,700(r11)
	r18.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x82388580
	ctx.lr = 0x82288128;
	sub_82388580(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82288138;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82288140;
	sub_822577D0(ctx, base);
	// addi r6,r3,-1
	ctx.r6.s64 = ctx.r3.s64 + -1;
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// addi r11,r11,-2
	r11.s64 = r11.s64 + -2;
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// cmplwi cr6,r11,55
	cr6.compare<uint32_t>(r11.u32, 55, xer);
	// xori r10,r4,1
	ctx.r10.u64 = ctx.r4.u64 ^ 1;
	// bgt cr6,0x82288924
	if (cr6.gt) goto loc_82288924;
	// lis r12,-32215
	r12.s64 = -2111242240;
	// addi r12,r12,-32392
	r12.s64 = r12.s64 + -32392;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	switch (r11.u64) {
	case 0:
		goto loc_82288258;
	case 1:
		goto loc_82288258;
	case 2:
		goto loc_82288924;
	case 3:
		goto loc_82288924;
	case 4:
		goto loc_82288924;
	case 5:
		goto loc_82288924;
	case 6:
		goto loc_82288924;
	case 7:
		goto loc_82288924;
	case 8:
		goto loc_822883BC;
	case 9:
		goto loc_822883BC;
	case 10:
		goto loc_82288924;
	case 11:
		goto loc_82288924;
	case 12:
		goto loc_82288924;
	case 13:
		goto loc_82288924;
	case 14:
		goto loc_82288924;
	case 15:
		goto loc_82288924;
	case 16:
		goto loc_82288258;
	case 17:
		goto loc_82288258;
	case 18:
		goto loc_82288924;
	case 19:
		goto loc_82288924;
	case 20:
		goto loc_82288924;
	case 21:
		goto loc_82288924;
	case 22:
		goto loc_82288924;
	case 23:
		goto loc_82288924;
	case 24:
		goto loc_82288924;
	case 25:
		goto loc_82288924;
	case 26:
		goto loc_82288924;
	case 27:
		goto loc_82288924;
	case 28:
		goto loc_82288924;
	case 29:
		goto loc_82288924;
	case 30:
		goto loc_82288924;
	case 31:
		goto loc_82288924;
	case 32:
		goto loc_82288924;
	case 33:
		goto loc_82288924;
	case 34:
		goto loc_82288924;
	case 35:
		goto loc_82288924;
	case 36:
		goto loc_82288924;
	case 37:
		goto loc_82288924;
	case 38:
		goto loc_82288924;
	case 39:
		goto loc_82288924;
	case 40:
		goto loc_82288924;
	case 41:
		goto loc_82288924;
	case 42:
		goto loc_82288924;
	case 43:
		goto loc_82288924;
	case 44:
		goto loc_82288924;
	case 45:
		goto loc_82288924;
	case 46:
		goto loc_82288924;
	case 47:
		goto loc_82288924;
	case 48:
		goto loc_82288924;
	case 49:
		goto loc_82288924;
	case 50:
		goto loc_82288924;
	case 51:
		goto loc_82288924;
	case 52:
		goto loc_822887EC;
	case 53:
		goto loc_82288924;
	case 54:
		goto loc_82288924;
	case 55:
		goto loc_82288564;
	default:
		__builtin_unreachable();
	}
	// lwz r17,-32168(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32168);
	// lwz r17,-32168(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32168);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-31812(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31812);
	// lwz r17,-31812(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31812);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-32168(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32168);
	// lwz r17,-32168(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -32168);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30740(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30740);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-30428(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -30428);
	// lwz r17,-31388(r8)
	r17.u64 = PPC_LOAD_U32(ctx.r8.u32 + -31388);
loc_82288258:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822883ac
	if (cr6.eq) goto loc_822883AC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82288268;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82288278;
	sub_82270170(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822842e0
	ctx.lr = 0x82288284;
	sub_822842E0(ctx, base);
	// cmplw cr6,r3,r30
	cr6.compare<uint32_t>(ctx.r3.u32, r30.u32, xer);
	// bne cr6,0x822883ac
	if (!cr6.eq) goto loc_822883AC;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x82280320
	ctx.lr = 0x82288294;
	sub_82280320(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822883ac
	if (cr6.eq) goto loc_822883AC;
	// bl 0x82387b90
	ctx.lr = 0x822882A4;
	sub_82387B90(ctx, base);
	// lwz r10,76(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// lwz r27,1340(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 1340);
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// beq cr6,0x822882c8
	if (cr6.eq) goto loc_822882C8;
	// cmpwi cr6,r11,19
	cr6.compare<int32_t>(r11.s32, 19, xer);
	// li r28,0
	r28.s64 = 0;
	// bne cr6,0x822882cc
	if (!cr6.eq) goto loc_822882CC;
loc_822882C8:
	// li r28,1
	r28.s64 = 1;
loc_822882CC:
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82289318
	ctx.lr = 0x822882DC;
	sub_82289318(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822882E4;
	sub_82388580(ctx, base);
	// lwz r30,-10240(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r25,80(r1)
	r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r24,4(r3)
	r24.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82387b90
	ctx.lr = 0x822882F4;
	sub_82387B90(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82270170
	ctx.lr = 0x82288304;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x8228830C;
	sub_82272A30(ctx, base);
	// bl 0x824817c0
	ctx.lr = 0x82288310;
	sub_824817C0(ctx, base);
	// mulli r11,r25,8176
	r11.s64 = r25.s64 * 8176;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// addi r4,r3,12
	ctx.r4.s64 = ctx.r3.s64 + 12;
	// addi r3,r11,1360
	ctx.r3.s64 = r11.s64 + 1360;
	// bl 0x823906d8
	ctx.lr = 0x82288324;
	sub_823906D8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// lwz r11,76(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 76);
	// bne cr6,0x82288350
	if (!cr6.eq) goto loc_82288350;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// bne cr6,0x822882cc
	if (!cr6.eq) goto loc_822882CC;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82288350:
	// lwz r4,80(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r4,r11
	cr6.compare<int32_t>(ctx.r4.s32, r11.s32, xer);
	// beq cr6,0x822883ac
	if (cr6.eq) goto loc_822883AC;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x8228b660
	ctx.lr = 0x82288364;
	sub_8228B660(ctx, base);
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82288378;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r28,24
	ctx.r9.u64 = r28.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822883a0
	if (cr6.eq) goto loc_822883A0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24608(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24608);
	// bl 0x821e6800
	ctx.lr = 0x82288390;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_822883A0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24604);
	// bl 0x821e6800
	ctx.lr = 0x822883AC;
	sub_821E6800(ctx, base);
loc_822883AC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_822883BC:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x822801f0
	ctx.lr = 0x822883C4;
	sub_822801F0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822883ac
	if (cr6.eq) goto loc_822883AC;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295e90
	ctx.lr = 0x822883DC;
	sub_82295E90(ctx, base);
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12672(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12672);
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// beq cr6,0x822883ac
	if (cr6.eq) goto loc_822883AC;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82295e90
	ctx.lr = 0x822883F8;
	sub_82295E90(ctx, base);
	// lwz r31,4(r18)
	r31.u64 = PPC_LOAD_U32(r18.u32 + 4);
	// li r11,0
	r11.s64 = 0;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x822883ac
	if (cr6.eq) goto loc_822883AC;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82389668
	ctx.lr = 0x82288420;
	sub_82389668(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822883ac
	if (cr6.eq) goto loc_822883AC;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,-11
	ctx.r9.s64 = ctx.r9.s64 + -11;
	// add r8,r11,r10
	ctx.r8.u64 = r11.u64 + ctx.r10.u64;
	// lwz r11,44(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// cntlzw r7,r9
	ctx.r7.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r10,r8,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r29,r7,27,31,31
	r29.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + r11.u64;
	// lis r11,-32129
	r11.s64 = -2105606144;
	// addi r27,r11,-28304
	r27.s64 = r11.s64 + -28304;
	// lwz r30,4(r6)
	r30.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
loc_82288460:
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r4,32(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82289318
	ctx.lr = 0x82288470;
	sub_82289318(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x82657178
	ctx.lr = 0x82288484;
	sub_82657178(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x822884d4
	if (cr6.eq) goto loc_822884D4;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// bne cr6,0x822884d4
	if (!cr6.eq) goto loc_822884D4;
	// lwz r8,144(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 144);
	// lwz r9,4(r27)
	ctx.r9.u64 = PPC_LOAD_U32(r27.u32 + 4);
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// cmplwi cr6,r7,0
	cr6.compare<uint32_t>(ctx.r7.u32, 0, xer);
	// beq cr6,0x822884d4
	if (cr6.eq) goto loc_822884D4;
	// lbz r10,96(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 96);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x82288504
	if (cr6.eq) goto loc_82288504;
loc_822884D4:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,44(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 44);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,5,0,26
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 5) & 0xFFFFFFE0;
	// add r10,r11,r9
	ctx.r10.u64 = r11.u64 + ctx.r9.u64;
	// lwz r9,148(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 148);
	// cmplw cr6,r28,r9
	cr6.compare<uint32_t>(r28.u32, ctx.r9.u32, xer);
	// bne cr6,0x82288460
	if (!cr6.eq) goto loc_82288460;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82288504:
	// lwz r10,36(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 36);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r9,r10
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// bl 0x821c9790
	ctx.lr = 0x82288518;
	sub_821C9790(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82282580
	ctx.lr = 0x82288528;
	sub_82282580(ctx, base);
	// lwz r8,0(r20)
	ctx.r8.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r7,176(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 176);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8228853C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r6,r29,24
	ctx.r6.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x822883a0
	if (cr6.eq) goto loc_822883A0;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24608(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24608);
	// bl 0x821e6800
	ctx.lr = 0x82288554;
	sub_821E6800(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82288564:
	// clrlwi r11,r10,24
	r11.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822887dc
	if (cr6.eq) goto loc_822887DC;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r3,700(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// bl 0x8227e1b0
	ctx.lr = 0x8228857C;
	sub_8227E1B0(ctx, base);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,-3624(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8226b2f0
	ctx.lr = 0x8228858C;
	sub_8226B2F0(ctx, base);
	// bl 0x82293f60
	ctx.lr = 0x82288590;
	sub_82293F60(ctx, base);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f0,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	cr6.compare(f31.f64, f0.f64);
	// ble cr6,0x822885ac
	if (!cr6.gt) goto loc_822885AC;
	// fcmpu cr6,f1,f31
	cr6.compare(ctx.f1.f64, f31.f64);
	// li r10,1
	ctx.r10.s64 = 1;
	// bgt cr6,0x822885b0
	if (cr6.gt) goto loc_822885B0;
loc_822885AC:
	// li r10,0
	ctx.r10.s64 = 0;
loc_822885B0:
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// clrlwi r29,r10,24
	r29.u64 = ctx.r10.u32 & 0xFF;
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822885f4
	if (!cr6.eq) goto loc_822885F4;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822885D0;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822885E0;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x822885E8;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,2
	cr6.compare<uint32_t>(ctx.r3.u32, 2, xer);
	// beq cr6,0x8228862c
	if (cr6.eq) goto loc_8228862C;
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
loc_822885F4:
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x8228863c
	if (!cr6.eq) goto loc_8228863C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228860C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228861C;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82288624;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bne cr6,0x82288638
	if (!cr6.eq) goto loc_82288638;
loc_8228862C:
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x82288640
	goto loc_82288640;
loc_82288638:
	// lwz r11,-3624(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -3624);
loc_8228863C:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82288640:
	// clrlwi r9,r29,24
	ctx.r9.u64 = r29.u32 & 0xFF;
	// clrlwi r29,r10,24
	r29.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x82288660
	if (!cr6.eq) goto loc_82288660;
	// lwz r10,700(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x822886a4
	if (!cr6.eq) goto loc_822886A4;
loc_82288660:
	// lwz r11,700(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 700);
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// bne cr6,0x82288698
	if (!cr6.eq) goto loc_82288698;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82288678;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82288688;
	sub_82270170(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82288690;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822886a4
	if (cr6.eq) goto loc_822886A4;
loc_82288698:
	// clrlwi r11,r29,24
	r11.u64 = r29.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822887dc
	if (cr6.eq) goto loc_822887DC;
loc_822886A4:
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x822887dc
	if (cr6.eq) goto loc_822887DC;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822886B4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822886C4;
	sub_82270170(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822842e0
	ctx.lr = 0x822886D0;
	sub_822842E0(ctx, base);
	// cmplw cr6,r3,r31
	cr6.compare<uint32_t>(ctx.r3.u32, r31.u32, xer);
	// beq cr6,0x822887dc
	if (cr6.eq) goto loc_822887DC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82284368
	ctx.lr = 0x822886E0;
	sub_82284368(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x822887dc
	if (cr6.eq) goto loc_822887DC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x82284368
	ctx.lr = 0x822886F0;
	sub_82284368(ctx, base);
	// bl 0x822a7cc8
	ctx.lr = 0x822886F4;
	sub_822A7CC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x822887dc
	if (cr6.eq) goto loc_822887DC;
	// lwz r11,-10236(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + -10236);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// lwz r10,-3624(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -3624);
	// lwz r31,52(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// lwz r30,700(r10)
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + 700);
	// bl 0x822842e0
	ctx.lr = 0x82288718;
	sub_822842E0(ctx, base);
	// lbz r11,278(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 278);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x822887dc
	if (!cr6.eq) goto loc_822887DC;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x822842e0
	ctx.lr = 0x8228872C;
	sub_822842E0(ctx, base);
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x82288734;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x82288748
	if (!cr6.eq) goto loc_82288748;
	// lwz r11,16(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x822887dc
	if (!cr6.eq) goto loc_822887DC;
loc_82288748:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24588(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24588);
	// bl 0x821e6800
	ctx.lr = 0x82288754;
	sub_821E6800(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// addi r30,r31,4
	r30.s64 = r31.s64 + 4;
	// bl 0x82284368
	ctx.lr = 0x82288760;
	sub_82284368(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// addi r29,r11,-12068
	r29.s64 = r11.s64 + -12068;
	// lis r10,-32130
	ctx.r10.s64 = -2105671680;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r27,r10,-17812
	r27.s64 = ctx.r10.s64 + -17812;
	// bl 0x82691650
	ctx.lr = 0x82288780;
	sub_82691650(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// bl 0x823dedd8
	ctx.lr = 0x82288794;
	sub_823DEDD8(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x8228b8d8
	ctx.lr = 0x8228879C;
	sub_8228B8D8(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// mr r31,r30
	r31.u64 = r30.u64;
	// lwz r11,-10220(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10220);
	// stb r8,1529(r11)
	PPC_STORE_U8(r11.u32 + 1529, ctx.r8.u8);
	// bne cr6,0x822887bc
	if (!cr6.eq) goto loc_822887BC;
	// li r31,0
	r31.s64 = 0;
loc_822887BC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82691650
	ctx.lr = 0x822887C8;
	sub_82691650(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,348(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 348);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822887DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822887DC:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_822887EC:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8227e0b0
	ctx.lr = 0x822887F4;
	sub_8227E0B0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82288900
	if (cr6.eq) goto loc_82288900;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8227e7f8
	ctx.lr = 0x82288808;
	sub_8227E7F8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x82288900
	if (cr6.eq) goto loc_82288900;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228881C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228882C;
	sub_82270170(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82272a30
	ctx.lr = 0x82288834;
	sub_82272A30(ctx, base);
	// bl 0x82481590
	ctx.lr = 0x82288838;
	sub_82481590(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x82288900
	if (!cr6.eq) goto loc_82288900;
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lwz r3,24604(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 24604);
	// bl 0x821e6800
	ctx.lr = 0x82288850;
	sub_821E6800(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x82288858;
	sub_82388580(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x82288868;
	sub_82270170(ctx, base);
	// li r4,14
	ctx.r4.s64 = 14;
	// bl 0x822577d0
	ctx.lr = 0x82288870;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// blt cr6,0x822888a4
	if (cr6.lt) goto loc_822888A4;
	// beq cr6,0x822888a4
	if (cr6.eq) goto loc_822888A4;
	// cmplwi cr6,r3,3
	cr6.compare<uint32_t>(ctx.r3.u32, 3, xer);
	// bge cr6,0x822888c8
	if (!cr6.lt) goto loc_822888C8;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x8228888C;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x8228889C;
	sub_82270170(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// b 0x822888c0
	goto loc_822888C0;
loc_822888A4:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822888AC;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822888BC;
	sub_82270170(ctx, base);
	// li r5,2
	ctx.r5.s64 = 2;
loc_822888C0:
	// li r4,14
	ctx.r4.s64 = 14;
	// bl 0x82274128
	ctx.lr = 0x822888C8;
	sub_82274128(ctx, base);
loc_822888C8:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8227e750
	ctx.lr = 0x822888D0;
	sub_8227E750(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x82288900
	if (!cr6.eq) goto loc_82288900;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x822888E4;
	sub_82388580(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r3,-10240(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10240);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x82270170
	ctx.lr = 0x822888F4;
	sub_82270170(ctx, base);
	// li r4,11
	ctx.r4.s64 = 11;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x82274128
	ctx.lr = 0x82288900;
	sub_82274128(ctx, base);
loc_82288900:
	// lwz r11,0(r20)
	r11.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r10,176(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 176);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82288914;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
loc_82288924:
	// mr r8,r22
	ctx.r8.u64 = r22.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x8263a4a8
	ctx.lr = 0x82288940;
	sub_8263A4A8(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x823d9220
	return;
}

__attribute__((alias("__imp__sub_8228894C"))) PPC_WEAK_FUNC(sub_8228894C);
PPC_FUNC_IMPL(__imp__sub_8228894C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82288950"))) PPC_WEAK_FUNC(sub_82288950);
PPC_FUNC_IMPL(__imp__sub_82288950) {
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
	// bl 0x82287948
	ctx.lr = 0x82288968;
	sub_82287948(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r31,r31,48
	r31.s64 = r31.s64 + 48;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,72(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 72);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// blt cr6,0x822889b8
	if (cr6.lt) goto loc_822889B8;
	// bctrl 
	ctx.lr = 0x8228898C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x822889ac
	if (!cr6.eq) goto loc_822889AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,84(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 84);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822889AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822889AC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,108(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 108);
	// b 0x822889e4
	goto loc_822889E4;
loc_822889B8:
	// bctrl 
	ctx.lr = 0x822889BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x822889dc
	if (cr6.eq) goto loc_822889DC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,80(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 80);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822889DC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_822889DC:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,112(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 112);
loc_822889E4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x822889F0;
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

__attribute__((alias("__imp__sub_82288A04"))) PPC_WEAK_FUNC(sub_82288A04);
PPC_FUNC_IMPL(__imp__sub_82288A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

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

