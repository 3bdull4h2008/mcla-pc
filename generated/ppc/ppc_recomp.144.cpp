#include "ppc_recomp_shared.h"

PPC_FUNC_IMPL(__imp__sub_826C2BDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C2BDC) {
	__imp__sub_826C2BDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2BE0) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r5,-27288(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -27288);
	// lwz r3,60(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 60);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c2c18
	if (cr6.eq) goto loc_826C2C18;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8213c218
	ctx.lr = 0x826C2C14;
	sub_8213C218(ctx, base);
	// lwz r5,-27288(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -27288);
loc_826C2C18:
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// li r11,0
	r11.s64 = 0;
	// li r31,1
	r31.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, r11.u32);
	// lwz r3,-12012(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12012);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f1,3796(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r8.u32 + 3796);
	ctx.f1.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// stb r11,127(r1)
	PPC_STORE_U8(ctx.r1.u32 + 127, r11.u8);
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r11,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r11.u32);
	// addi r5,r5,60
	ctx.r5.s64 = ctx.r5.s64 + 60;
	// stb r31,111(r1)
	PPC_STORE_U8(ctx.r1.u32 + 111, r31.u8);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, r11.u32);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r11.u32);
	// bl 0x825495a8
	ctx.lr = 0x826C2C68;
	sub_825495A8(ctx, base);
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

PPC_WEAK_FUNC(sub_826C2BE0) {
	__imp__sub_826C2BE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2C80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// b 0x821f2a60
	sub_821F2A60(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826C2C80) {
	__imp__sub_826C2C80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2C8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C2C8C) {
	__imp__sub_826C2C8C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2C90) {
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
	ctx.lr = 0x826C2C98;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r29,r6
	r29.u64 = ctx.r6.u64;
	// lwz r3,-10016(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10016);
	// bl 0x82700880
	ctx.lr = 0x826C2CB8;
	sub_82700880(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c2d0c
	if (cr6.eq) goto loc_826C2D0C;
	// bl 0x82224ac8
	ctx.lr = 0x826C2CC8;
	sub_82224AC8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c2cf0
	if (cr6.eq) goto loc_826C2CF0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r3,r11,-9724
	ctx.r3.s64 = r11.s64 + -9724;
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// bl 0x826c2718
	ctx.lr = 0x826C2CE8;
	sub_826C2718(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826C2CF0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r11,-9756
	ctx.r3.s64 = r11.s64 + -9756;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x826c2718
	ctx.lr = 0x826C2D04;
	sub_826C2718(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826C2D0C:
	// cmpwi cr6,r30,1
	cr6.compare<int32_t>(r30.s32, 1, xer);
	// bgt cr6,0x826c2d20
	if (cr6.gt) goto loc_826C2D20;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,-9776
	ctx.r4.s64 = r11.s64 + -9776;
	// b 0x826c2d48
	goto loc_826C2D48;
loc_826C2D20:
	// lwz r11,3096(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3096);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// ble cr6,0x826c2d40
	if (!cr6.gt) goto loc_826C2D40;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826c2d40
	if (cr6.lt) goto loc_826C2D40;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,-9796
	ctx.r4.s64 = r11.s64 + -9796;
	// b 0x826c2d48
	goto loc_826C2D48;
loc_826C2D40:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r11,-9820
	ctx.r4.s64 = r11.s64 + -9820;
loc_826C2D48:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r6,r28,144
	ctx.r6.s64 = r28.s64 + 144;
	// addi r5,r27,144
	ctx.r5.s64 = r27.s64 + 144;
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// bl 0x821f3628
	ctx.lr = 0x826C2D5C;
	sub_821F3628(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c2d78
	if (cr6.eq) goto loc_826C2D78;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r3,2260(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
loc_826C2D78:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826C2C90) {
	__imp__sub_826C2C90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2D84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C2D84) {
	__imp__sub_826C2D84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2D88) {
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
	// li r3,72
	ctx.r3.s64 = 72;
	// bl 0x82130528
	ctx.lr = 0x826C2D9C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c2dc0
	if (cr6.eq) goto loc_826C2DC0;
	// bl 0x826c2b18
	ctx.lr = 0x826C2DA8;
	sub_826C2B18(ctx, base);
	// lis r11,-32111
	r11.s64 = -2104426496;
	// stw r3,-27288(r11)
	PPC_STORE_U32(r11.u32 + -27288, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C2DC0:
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// li r11,0
	r11.s64 = 0;
	// stw r11,-27288(r10)
	PPC_STORE_U32(ctx.r10.u32 + -27288, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C2D88) {
	__imp__sub_826C2D88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C2DDC) {
	__imp__sub_826C2DDC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2DE0) {
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
	ctx.lr = 0x826C2DE8;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r5,r9,-9600
	ctx.r5.s64 = ctx.r9.s64 + -9600;
	// addi r6,r10,-9584
	ctx.r6.s64 = ctx.r10.s64 + -9584;
	// addi r10,r8,-9616
	ctx.r10.s64 = ctx.r8.s64 + -9616;
	// stw r5,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// addi r9,r7,-9632
	ctx.r9.s64 = ctx.r7.s64 + -9632;
	// stw r6,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// stw r10,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// li r5,2
	ctx.r5.s64 = 2;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// mtctr r11
	ctr.u64 = r11.u64;
	// bctrl 
	ctx.lr = 0x826C2E38;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826C2E54;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r6,32(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// li r24,0
	r24.s64 = 0;
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826c2ff4
	if (cr6.eq) goto loc_826C2FF4;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// li r30,0
	r30.s64 = 0;
	// addi r29,r11,-9652
	r29.s64 = r11.s64 + -9652;
	// addi r25,r10,-9660
	r25.s64 = ctx.r10.s64 + -9660;
	// addi r27,r9,-9676
	r27.s64 = ctx.r9.s64 + -9676;
	// addi r26,r8,-9692
	r26.s64 = ctx.r8.s64 + -9692;
	// addi r28,r7,-10052
	r28.s64 = ctx.r7.s64 + -10052;
loc_826C2E90:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r10,r28
	ctx.r10.u64 = r28.u64;
	// add r8,r30,r11
	ctx.r8.u64 = r30.u64 + r11.u64;
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_826C2EA4:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826c2ec8
	if (cr6.eq) goto loc_826C2EC8;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c2ea4
	if (cr6.eq) goto loc_826C2EA4;
loc_826C2EC8:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c2ed8
	if (!cr6.eq) goto loc_826C2ED8;
	// stw r8,40(r31)
	PPC_STORE_U32(r31.u32 + 40, ctx.r8.u32);
	// b 0x826c2fe0
	goto loc_826C2FE0;
loc_826C2ED8:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_826C2EE0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826c2f04
	if (cr6.eq) goto loc_826C2F04;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c2ee0
	if (cr6.eq) goto loc_826C2EE0;
loc_826C2F04:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c2f14
	if (!cr6.eq) goto loc_826C2F14;
	// stw r8,44(r31)
	PPC_STORE_U32(r31.u32 + 44, ctx.r8.u32);
	// b 0x826c2fe0
	goto loc_826C2FE0;
loc_826C2F14:
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
loc_826C2F1C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r7,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r7.s64;
	// beq cr6,0x826c2f40
	if (cr6.eq) goto loc_826C2F40;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c2f1c
	if (cr6.eq) goto loc_826C2F1C;
loc_826C2F40:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c2f50
	if (!cr6.eq) goto loc_826C2F50;
	// stw r8,48(r31)
	PPC_STORE_U32(r31.u32 + 48, ctx.r8.u32);
	// b 0x826c2fe0
	goto loc_826C2FE0;
loc_826C2F50:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x821c7d28
	ctx.lr = 0x826C2F5C;
	sub_821C7D28(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c2fe0
	if (cr6.eq) goto loc_826C2FE0;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r5,0
	ctx.r5.s64 = 0;
	// add r6,r30,r11
	ctx.r6.u64 = r30.u64 + r11.u64;
	// stw r6,52(r31)
	PPC_STORE_U32(r31.u32 + 52, ctx.r6.u32);
	// lhz r11,12(r6)
	r11.u64 = PPC_LOAD_U16(ctx.r6.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c2fe0
	if (cr6.eq) goto loc_826C2FE0;
	// li r7,0
	ctx.r7.s64 = 0;
loc_826C2F88:
	// lwz r11,8(r6)
	r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// mr r10,r29
	ctx.r10.u64 = r29.u64;
	// add r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 + r11.u64;
	// lwzx r11,r7,r11
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
loc_826C2F98:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r4,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r4.s64;
	// beq cr6,0x826c2fbc
	if (cr6.eq) goto loc_826C2FBC;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c2f98
	if (cr6.eq) goto loc_826C2F98;
loc_826C2FBC:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c2fc8
	if (!cr6.eq) goto loc_826C2FC8;
	// stw r8,56(r31)
	PPC_STORE_U32(r31.u32 + 56, ctx.r8.u32);
loc_826C2FC8:
	// lwz r11,52(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 52);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,24
	ctx.r7.s64 = ctx.r7.s64 + 24;
	// lhz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 12);
	// cmpw cr6,r5,r10
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r10.s32, xer);
	// blt cr6,0x826c2f88
	if (cr6.lt) goto loc_826C2F88;
loc_826C2FE0:
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
	// addi r30,r30,20
	r30.s64 = r30.s64 + 20;
	// cmpw cr6,r24,r11
	cr6.compare<int32_t>(r24.s32, r11.s32, xer);
	// blt cr6,0x826c2e90
	if (cr6.lt) goto loc_826C2E90;
loc_826C2FF4:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_826C2DE0) {
	__imp__sub_826C2DE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C2FFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C2FFC) {
	__imp__sub_826C2FFC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3000) {
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
	ctx.lr = 0x826C3008;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// mr r30,r6
	r30.u64 = ctx.r6.u64;
	// bl 0x821c9790
	ctx.lr = 0x826C3028;
	sub_821C9790(ctx, base);
	// lhz r5,12(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 12);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826c305c
	if (cr6.eq) goto loc_826C305C;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r4,8(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r7,r11,10896
	ctx.r7.s64 = r11.s64 + 10896;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823de288
	ctx.lr = 0x826C3050;
	sub_823DE288(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addi r11,r3,4
	r11.s64 = ctx.r3.s64 + 4;
	// bne cr6,0x826c3060
	if (!cr6.eq) goto loc_826C3060;
loc_826C305C:
	// li r11,0
	r11.s64 = 0;
loc_826C3060:
	// lwz r11,0(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r11,8
	cr6.compare<uint32_t>(r11.u32, 8, xer);
	// bgt cr6,0x826c34f4
	if (cr6.gt) goto loc_826C34F4;
	// lis r12,-32148
	r12.s64 = -2106851328;
	// addi r12,r12,12420
	r12.s64 = r12.s64 + 12420;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,12456(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12456);
	// lwz r19,12528(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12528);
	// lwz r19,12616(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12616);
	// lwz r19,12684(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12684);
	// lwz r19,12844(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 12844);
	// lwz r19,13036(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 13036);
	// lwz r19,13228(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 13228);
	// lwz r19,13332(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 13332);
	// lwz r19,13436(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 13436);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,-9408
	ctx.r5.s64 = r11.s64 + -9408;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C30BC;
	sub_82137A08(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r10,r30,264
	ctx.r10.s64 = r30.s64 + 264;
	// addi r11,r9,-10164
	r11.s64 = ctx.r9.s64 + -10164;
	// li r9,7
	ctx.r9.s64 = 7;
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
loc_826C30D0:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826c30d0
	--ctr.u64;
	if (ctr.u32 != 0) goto loc_826C30D0;
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C3100;
	sub_82137A08(ctx, base);
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x826c3120
	if (cr6.eq) goto loc_826C3120;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// addi r10,r11,11232
	ctx.r10.s64 = r11.s64 + 11232;
	// stw r10,432(r30)
	PPC_STORE_U32(r30.u32 + 432, ctx.r10.u32);
loc_826C3120:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-9436
	ctx.r3.s64 = r11.s64 + -9436;
	// bl 0x821c9790
	ctx.lr = 0x826C3130;
	sub_821C9790(ctx, base);
	// stw r3,436(r30)
	PPC_STORE_U32(r30.u32 + 436, ctx.r3.u32);
	// lwz r10,56(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,408(r30)
	PPC_STORE_U32(r30.u32 + 408, ctx.r10.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C3158;
	sub_82137A08(ctx, base);
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// cmplw cr6,r9,r10
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, xer);
	// beq cr6,0x826c3178
	if (cr6.eq) goto loc_826C3178;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// addi r10,r11,9800
	ctx.r10.s64 = r11.s64 + 9800;
	// stw r10,432(r30)
	PPC_STORE_U32(r30.u32 + 432, ctx.r10.u32);
loc_826C3178:
	// lwz r11,56(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 56);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,408(r30)
	PPC_STORE_U32(r30.u32 + 408, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,-9452
	ctx.r5.s64 = r11.s64 + -9452;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C31A0;
	sub_82137A08(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lwz r11,-12348(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12348);
	// lbz r9,76(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c31e8
	if (!cr6.eq) goto loc_826C31E8;
	// bl 0x82256058
	ctx.lr = 0x826C31BC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c31e0
	if (cr6.eq) goto loc_826C31E0;
	// bl 0x82256058
	ctx.lr = 0x826C31C8;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826c31e0
	if (cr0.eq) goto loc_826C31E0;
	// bl 0x82256058
	ctx.lr = 0x826C31D4;
	sub_82256058(ctx, base);
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c31e8
	if (!cr6.eq) goto loc_826C31E8;
loc_826C31E0:
	// li r11,0
	r11.s64 = 0;
	// b 0x826c31ec
	goto loc_826C31EC;
loc_826C31E8:
	// li r11,1
	r11.s64 = 1;
loc_826C31EC:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c3218
	if (!cr6.eq) goto loc_826C3218;
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// clrlwi r10,r11,24
	ctx.r10.u64 = r11.u32 & 0xFF;
	// stb r10,68(r31)
	PPC_STORE_U8(r31.u32 + 68, ctx.r10.u8);
	// cmplwi cr6,r10,12
	cr6.compare<uint32_t>(ctx.r10.u32, 12, xer);
	// ble cr6,0x826c3218
	if (!cr6.gt) goto loc_826C3218;
	// li r11,1
	r11.s64 = 1;
	// stb r11,68(r31)
	PPC_STORE_U8(r31.u32 + 68, r11.u8);
loc_826C3218:
	// lbz r11,68(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 68);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r11,424(r30)
	PPC_STORE_U32(r30.u32 + 424, r11.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c32bc
	if (cr6.eq) goto loc_826C32BC;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c3284
	if (!cr6.eq) goto loc_826C3284;
	// bl 0x82256058
	ctx.lr = 0x826C3258;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c327c
	if (cr6.eq) goto loc_826C327C;
	// bl 0x82256058
	ctx.lr = 0x826C3264;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826c327c
	if (cr0.eq) goto loc_826C327C;
	// bl 0x82256058
	ctx.lr = 0x826C3270;
	sub_82256058(ctx, base);
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c3284
	if (!cr6.eq) goto loc_826C3284;
loc_826C327C:
	// li r11,0
	r11.s64 = 0;
	// b 0x826c3288
	goto loc_826C3288;
loc_826C3284:
	// li r11,1
	r11.s64 = 1;
loc_826C3288:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c32b4
	if (!cr6.eq) goto loc_826C32B4;
	// lbz r11,69(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,69(r31)
	PPC_STORE_U8(r31.u32 + 69, ctx.r9.u8);
	// cmpwi cr6,r9,70
	cr6.compare<int32_t>(ctx.r9.s32, 70, xer);
	// ble cr6,0x826c32b4
	if (!cr6.gt) goto loc_826C32B4;
	// li r11,65
	r11.s64 = 65;
	// stb r11,69(r31)
	PPC_STORE_U8(r31.u32 + 69, r11.u8);
loc_826C32B4:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// b 0x826c32c0
	goto loc_826C32C0;
loc_826C32BC:
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
loc_826C32C0:
	// lbz r9,69(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r5,r10,-9476
	ctx.r5.s64 = ctx.r10.s64 + -9476;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C32E0;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c337c
	if (cr6.eq) goto loc_826C337C;
	// lis r11,-32115
	r11.s64 = -2104688640;
	// lwz r11,-12348(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12348);
	// lbz r10,76(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 76);
	// rlwinm r9,r10,0,25,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c3344
	if (!cr6.eq) goto loc_826C3344;
	// bl 0x82256058
	ctx.lr = 0x826C3318;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c333c
	if (cr6.eq) goto loc_826C333C;
	// bl 0x82256058
	ctx.lr = 0x826C3324;
	sub_82256058(ctx, base);
	// addic. r11,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r11.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// beq 0x826c333c
	if (cr0.eq) goto loc_826C333C;
	// bl 0x82256058
	ctx.lr = 0x826C3330;
	sub_82256058(ctx, base);
	// lwz r11,3152(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3152);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c3344
	if (!cr6.eq) goto loc_826C3344;
loc_826C333C:
	// li r11,0
	r11.s64 = 0;
	// b 0x826c3348
	goto loc_826C3348;
loc_826C3344:
	// li r11,1
	r11.s64 = 1;
loc_826C3348:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c3374
	if (!cr6.eq) goto loc_826C3374;
	// lbz r11,69(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,69(r31)
	PPC_STORE_U8(r31.u32 + 69, ctx.r9.u8);
	// cmpwi cr6,r9,70
	cr6.compare<int32_t>(ctx.r9.s32, 70, xer);
	// ble cr6,0x826c3374
	if (!cr6.gt) goto loc_826C3374;
	// li r11,65
	r11.s64 = 65;
	// stb r11,69(r31)
	PPC_STORE_U8(r31.u32 + 69, r11.u8);
loc_826C3374:
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
	// b 0x826c3380
	goto loc_826C3380;
loc_826C337C:
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
loc_826C3380:
	// lbz r9,69(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 69);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r5,r10,-9500
	ctx.r5.s64 = ctx.r10.s64 + -9500;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C33A0;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c33c4
	if (cr6.eq) goto loc_826C33C4;
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// b 0x826c33e8
	goto loc_826C33E8;
loc_826C33C4:
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,70(r31)
	PPC_STORE_U8(r31.u32 + 70, ctx.r9.u8);
	// cmpwi cr6,r9,69
	cr6.compare<int32_t>(ctx.r9.s32, 69, xer);
	// ble cr6,0x826c33e4
	if (!cr6.gt) goto loc_826C33E4;
	// li r11,65
	r11.s64 = 65;
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
loc_826C33E4:
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
loc_826C33E8:
	// lbz r9,70(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r5,r10,-9532
	ctx.r5.s64 = ctx.r10.s64 + -9532;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C3408;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lbz r10,22(r11)
	ctx.r10.u64 = PPC_LOAD_U8(r11.u32 + 22);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c342c
	if (cr6.eq) goto loc_826C342C;
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// b 0x826c3450
	goto loc_826C3450;
loc_826C342C:
	// lbz r11,70(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// addi r10,r11,1
	ctx.r10.s64 = r11.s64 + 1;
	// extsb r9,r10
	ctx.r9.s64 = ctx.r10.s8;
	// stb r9,70(r31)
	PPC_STORE_U8(r31.u32 + 70, ctx.r9.u8);
	// cmpwi cr6,r9,69
	cr6.compare<int32_t>(ctx.r9.s32, 69, xer);
	// ble cr6,0x826c344c
	if (!cr6.gt) goto loc_826C344C;
	// li r11,65
	r11.s64 = 65;
	// stb r11,70(r31)
	PPC_STORE_U8(r31.u32 + 70, r11.u8);
loc_826C344C:
	// lwz r11,412(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 412);
loc_826C3450:
	// lbz r9,70(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 70);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// extsb r7,r9
	ctx.r7.s64 = ctx.r9.s8;
	// addi r5,r10,-9568
	ctx.r5.s64 = ctx.r10.s64 + -9568;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C3470;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
	// lwz r11,408(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 408);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r10,-26992
	ctx.r5.s64 = ctx.r10.s64 + -26992;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r9,20(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 20);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// bl 0x82137a08
	ctx.lr = 0x826C34A0;
	sub_82137A08(ctx, base);
	// lis r31,-32125
	r31.s64 = -2105344000;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,-26224(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + -26224);
	// bl 0x8215b4d0
	ctx.lr = 0x826C34B0;
	sub_8215B4D0(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c34d4
	if (cr6.eq) goto loc_826C34D4;
	// li r4,128
	ctx.r4.s64 = 128;
	// lwz r5,-26224(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + -26224);
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82137a08
	ctx.lr = 0x826C34C8;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C34D4:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// li r4,128
	ctx.r4.s64 = 128;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwz r5,-26228(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + -26228);
	// bl 0x82137a08
	ctx.lr = 0x826C34E8;
	sub_82137A08(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
loc_826C34F4:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C3000) {
	__imp__sub_826C3000(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3500) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r7,2260(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 2260);
	// subf r6,r7,r8
	ctx.r6.s64 = ctx.r8.s64 - ctx.r7.s64;
	// cntlzw r5,r6
	ctx.r5.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// rlwinm r4,r5,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 27) & 0x1;
	// stw r4,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C3500) {
	__imp__sub_826C3500(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C352C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C352C) {
	__imp__sub_826C352C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3530) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r10,-12012(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r11,2260(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2260);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c3568
	if (cr6.eq) goto loc_826C3568;
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r11,r8
	cr6.compare<uint32_t>(r11.u32, ctx.r8.u32, xer);
	// bne cr6,0x826c3568
	if (!cr6.eq) goto loc_826C3568;
	// lwz r11,2256(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 2256);
	// lwz r10,420(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 420);
	// li r11,1
	r11.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826c356c
	if (cr6.eq) goto loc_826C356C;
loc_826C3568:
	// li r11,0
	r11.s64 = 0;
loc_826C356C:
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi r9,r11,24
	ctx.r9.u64 = r11.u32 & 0xFF;
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C3530) {
	__imp__sub_826C3530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C357C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C357C) {
	__imp__sub_826C357C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3580) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-12012(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x821f1d58
	sub_821F1D58(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826C3580) {
	__imp__sub_826C3580(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3598) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// bl 0x826c2c90
	ctx.lr = 0x826C35C4;
	sub_826C2C90(ctx, base);
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

PPC_WEAK_FUNC(sub_826C3598) {
	__imp__sub_826C3598(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C35E0) {
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
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r5,r7,24
	ctx.r5.u64 = ctx.r7.u32 & 0xFF;
	// bl 0x826c2878
	ctx.lr = 0x826C3618;
	sub_826C2878(ctx, base);
	// lwz r6,0(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C35E0) {
	__imp__sub_826C35E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3634) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3634) {
	__imp__sub_826C3634(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3638) {
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
	ctx.lr = 0x826C3640;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r29,r31,4
	r29.s64 = r31.s64 + 4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x826C3654;
	sub_82130588(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// li r28,1
	r28.s64 = 1;
	// stw r30,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r30.u32);
	// li r3,72
	ctx.r3.s64 = 72;
	// sth r30,12(r31)
	PPC_STORE_U16(r31.u32 + 12, r30.u16);
	// sth r30,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r30.u16);
	// stb r28,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r28.u8);
	// bl 0x82130528
	ctx.lr = 0x826C3674;
	sub_82130528(ctx, base);
	// li r11,9
	r11.s64 = 9;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// sth r11,14(r31)
	PPC_STORE_U16(r31.u32 + 14, r11.u16);
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-9408
	ctx.r3.s64 = ctx.r10.s64 + -9408;
	// bl 0x821c9790
	ctx.lr = 0x826C3690;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C36A4;
	sub_824787B0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r8,-9284
	ctx.r3.s64 = ctx.r8.s64 + -9284;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// stw r30,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, r30.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C36C0;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C36D4;
	sub_824787B0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,-9304
	ctx.r3.s64 = ctx.r6.s64 + -9304;
	// stw r27,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r27.u32);
	// stw r28,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, r28.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C36F0;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C3704;
	sub_824787B0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r11,2
	r11.s64 = 2;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-9452
	ctx.r3.s64 = ctx.r10.s64 + -9452;
	// stw r27,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r27.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C3724;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C3738;
	sub_824787B0(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// li r8,3
	ctx.r8.s64 = 3;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r7,-9324
	ctx.r3.s64 = ctx.r7.s64 + -9324;
	// stw r27,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, r27.u32);
	// stw r8,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C3758;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C376C;
	sub_824787B0(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// li r5,4
	ctx.r5.s64 = 4;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r3,-9344
	ctx.r3.s64 = ctx.r3.s64 + -9344;
	// stw r27,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, r27.u32);
	// stw r5,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r5.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C378C;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C37A0;
	sub_824787B0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// li r10,5
	ctx.r10.s64 = 5;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r9,-9372
	ctx.r3.s64 = ctx.r9.s64 + -9372;
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C37C0;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C37D4;
	sub_824787B0(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// li r7,6
	ctx.r7.s64 = 6;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r6,-9400
	ctx.r3.s64 = ctx.r6.s64 + -9400;
	// stw r27,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r27.u32);
	// stw r7,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r7.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C37F4;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C3808;
	sub_824787B0(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r11,7
	r11.s64 = 7;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r10,-9856
	ctx.r3.s64 = ctx.r10.s64 + -9856;
	// stw r27,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, r27.u32);
	// stw r11,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, r11.u32);
	// bl 0x821c9790
	ctx.lr = 0x826C3828;
	sub_821C9790(ctx, base);
	// stb r30,4(r31)
	PPC_STORE_U8(r31.u32 + 4, r30.u8);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r29,4
	ctx.r3.s64 = r29.s64 + 4;
	// bl 0x824787b0
	ctx.lr = 0x826C383C;
	sub_824787B0(ctx, base);
	// li r9,8
	ctx.r9.s64 = 8;
	// stw r30,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r30.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// lbz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 4);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c3878
	if (!cr6.eq) goto loc_826C3878;
	// lhz r4,8(r29)
	ctx.r4.u64 = PPC_LOAD_U16(r29.u32 + 8);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c3874
	if (cr6.eq) goto loc_826C3874;
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lwz r3,4(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r6,r11,10896
	ctx.r6.s64 = r11.s64 + 10896;
	// bl 0x823dcf08
	ctx.lr = 0x826C3874;
	sub_823DCF08(ctx, base);
loc_826C3874:
	// stb r28,0(r29)
	PPC_STORE_U8(r29.u32 + 0, r28.u8);
loc_826C3878:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826C3638) {
	__imp__sub_826C3638(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3880) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x821f3468
	ctx.lr = 0x826C38B0;
	sub_821F3468(ctx, base);
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

PPC_WEAK_FUNC(sub_826C3880) {
	__imp__sub_826C3880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C38D0) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x821f3628
	ctx.lr = 0x826C3900;
	sub_821F3628(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c3930
	if (cr6.eq) goto loc_826C3930;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2260);
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
loc_826C3930:
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

PPC_WEAK_FUNC(sub_826C38D0) {
	__imp__sub_826C38D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C394C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C394C) {
	__imp__sub_826C394C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3950) {
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
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27288);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r5,r11,144
	ctx.r5.s64 = r11.s64 + 144;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r10,144
	ctx.r6.s64 = ctx.r10.s64 + 144;
	// bl 0x821f3628
	ctx.lr = 0x826C3988;
	sub_821F3628(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c39b8
	if (cr6.eq) goto loc_826C39B8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2260);
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
loc_826C39B8:
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

PPC_WEAK_FUNC(sub_826C3950) {
	__imp__sub_826C3950(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C39D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C39D4) {
	__imp__sub_826C39D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C39D8) {
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
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r5,8(r11)
	ctx.r5.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// bl 0x826c2778
	ctx.lr = 0x826C3A00;
	sub_826C2778(ctx, base);
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

PPC_WEAK_FUNC(sub_826C39D8) {
	__imp__sub_826C39D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3A1C) {
	__imp__sub_826C3A1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3A20) {
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
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -27288);
	// lwz r11,4(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r10,8(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r5,r11,144
	ctx.r5.s64 = r11.s64 + 144;
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r10,144
	ctx.r6.s64 = ctx.r10.s64 + 144;
	// bl 0x821f3730
	ctx.lr = 0x826C3A58;
	sub_821F3730(ctx, base);
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r3,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C3A20) {
	__imp__sub_826C3A20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3A74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3A74) {
	__imp__sub_826C3A74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3A78) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r5,4(r10)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// bl 0x821f32d0
	ctx.lr = 0x826C3AB4;
	sub_821F32D0(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c3ae8
	if (cr6.eq) goto loc_826C3AE8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-12012(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -12012);
	// lwz r9,2260(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 2260);
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
loc_826C3AE8:
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

PPC_WEAK_FUNC(sub_826C3A78) {
	__imp__sub_826C3A78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3B04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3B04) {
	__imp__sub_826C3B04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3B08) {
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
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r3,-27288(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27288);
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x821f2060
	ctx.lr = 0x826C3B30;
	sub_821F2060(ctx, base);
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

PPC_WEAK_FUNC(sub_826C3B08) {
	__imp__sub_826C3B08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3B4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3B4C) {
	__imp__sub_826C3B4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3B50) {
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
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,14464
	ctx.r4.s64 = r11.s64 + 14464;
	// addi r3,r10,-8836
	ctx.r3.s64 = ctx.r10.s64 + -8836;
	// bl 0x82554798
	ctx.lr = 0x826C3B70;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,14544
	ctx.r4.s64 = ctx.r9.s64 + 14544;
	// addi r3,r8,-8872
	ctx.r3.s64 = ctx.r8.s64 + -8872;
	// bl 0x82554798
	ctx.lr = 0x826C3B84;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,14672
	ctx.r4.s64 = ctx.r7.s64 + 14672;
	// addi r3,r6,-8908
	ctx.r3.s64 = ctx.r6.s64 + -8908;
	// bl 0x82554798
	ctx.lr = 0x826C3B98;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,13568
	ctx.r4.s64 = ctx.r5.s64 + 13568;
	// addi r3,r3,-8944
	ctx.r3.s64 = ctx.r3.s64 + -8944;
	// bl 0x82554798
	ctx.lr = 0x826C3BAC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,9936
	ctx.r4.s64 = r11.s64 + 9936;
	// addi r3,r10,-8964
	ctx.r3.s64 = ctx.r10.s64 + -8964;
	// bl 0x82554798
	ctx.lr = 0x826C3BC0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,14808
	ctx.r4.s64 = ctx.r9.s64 + 14808;
	// addi r3,r8,-8996
	ctx.r3.s64 = ctx.r8.s64 + -8996;
	// bl 0x82554798
	ctx.lr = 0x826C3BD4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,14880
	ctx.r4.s64 = ctx.r7.s64 + 14880;
	// addi r3,r6,-9032
	ctx.r3.s64 = ctx.r6.s64 + -9032;
	// bl 0x82554798
	ctx.lr = 0x826C3BE8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,14968
	ctx.r4.s64 = ctx.r5.s64 + 14968;
	// addi r3,r3,-9068
	ctx.r3.s64 = ctx.r3.s64 + -9068;
	// bl 0x82554798
	ctx.lr = 0x826C3BFC;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,13616
	ctx.r4.s64 = r11.s64 + 13616;
	// addi r3,r10,-9104
	ctx.r3.s64 = ctx.r10.s64 + -9104;
	// bl 0x82554798
	ctx.lr = 0x826C3C10;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,11392
	ctx.r4.s64 = ctx.r9.s64 + 11392;
	// addi r3,r8,-9140
	ctx.r3.s64 = ctx.r8.s64 + -9140;
	// bl 0x82554798
	ctx.lr = 0x826C3C24;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,15112
	ctx.r4.s64 = ctx.r7.s64 + 15112;
	// addi r3,r6,-9168
	ctx.r3.s64 = ctx.r6.s64 + -9168;
	// bl 0x82554798
	ctx.lr = 0x826C3C38;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,13696
	ctx.r4.s64 = ctx.r5.s64 + 13696;
	// addi r3,r3,-9196
	ctx.r3.s64 = ctx.r3.s64 + -9196;
	// bl 0x82554798
	ctx.lr = 0x826C3C4C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,13720
	ctx.r4.s64 = r11.s64 + 13720;
	// addi r3,r10,-9228
	ctx.r3.s64 = ctx.r10.s64 + -9228;
	// bl 0x82554798
	ctx.lr = 0x826C3C60;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,13792
	ctx.r4.s64 = ctx.r9.s64 + 13792;
	// addi r3,r8,-9264
	ctx.r3.s64 = ctx.r8.s64 + -9264;
	// bl 0x82554798
	ctx.lr = 0x826C3C74;
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

PPC_WEAK_FUNC(sub_826C3B50) {
	__imp__sub_826C3B50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3C84) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3C84) {
	__imp__sub_826C3C84(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3C88) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x821378b8
	ctx.lr = 0x826C3CA4;
	sub_821378B8(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-8808
	ctx.r3.s64 = r11.s64 + -8808;
	// bl 0x821378b8
	ctx.lr = 0x826C3CB4;
	sub_821378B8(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r3,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// addi r31,r31,28
	r31.s64 = r31.s64 + 28;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// sth r11,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, r11.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// sth r11,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, r11.u16);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,96(r1)
	PPC_STORE_U8(ctx.r1.u32 + 96, r11.u8);
	// bl 0x821f1138
	ctx.lr = 0x826C3CE0;
	sub_821F1138(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x826c3d14
	if (!cr6.eq) goto loc_826C3D14;
	// bl 0x821d2aa0
	ctx.lr = 0x826C3CF4;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x826C3CFC;
	sub_821D2AA0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
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
loc_826C3D14:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r9
	r31.u64 = r11.u64 + ctx.r9.u64;
	// bl 0x821d2aa0
	ctx.lr = 0x826C3D2C;
	sub_821D2AA0(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x821d2aa0
	ctx.lr = 0x826C3D34;
	sub_821D2AA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
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

PPC_WEAK_FUNC(sub_826C3C88) {
	__imp__sub_826C3C88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3D4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3D4C) {
	__imp__sub_826C3D4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3D50) {
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
	// addi r9,r11,-8448
	ctx.r9.s64 = r11.s64 + -8448;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826c3d84
	if (cr6.eq) goto loc_826C3D84;
	// bl 0x82130588
	ctx.lr = 0x826C3D80;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826C3D84:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C3D50) {
	__imp__sub_826C3D50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3D98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// addi r11,r4,13
	r11.s64 = ctx.r4.s64 + 13;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r10,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r3.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C3D98) {
	__imp__sub_826C3D98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3DA8) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618670
	ctx.lr = 0x826C3DCC;
	sub_82618670(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// lwz r8,8(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// and r7,r9,r3
	ctx.r7.u64 = ctx.r9.u64 & ctx.r3.u64;
	// lwz r6,8(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r6,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r6.u32);
	// lwzx r4,r8,r5
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r5.u32);
	// stw r4,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r4.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stwx r10,r3,r5
	PPC_STORE_U32(ctx.r3.u32 + ctx.r5.u32, ctx.r10.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// stw r11,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r11.u32);
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
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

PPC_WEAK_FUNC(sub_826C3DA8) {
	__imp__sub_826C3DA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3E34) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3E34) {
	__imp__sub_826C3E34(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3E38) {
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
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwzx r31,r10,r11
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c3e88
	if (cr6.eq) goto loc_826C3E88;
loc_826C3E64:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c68c0
	ctx.lr = 0x826C3E70;
	sub_826C68C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c3ea4
	if (!cr6.eq) goto loc_826C3EA4;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826c3e64
	if (!cr6.eq) goto loc_826C3E64;
loc_826C3E88:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C3E8C:
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
loc_826C3EA4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// b 0x826c3e8c
	goto loc_826C3E8C;
}

PPC_WEAK_FUNC(sub_826C3E38) {
	__imp__sub_826C3E38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3EAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C3EAC) {
	__imp__sub_826C3EAC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3EB0) {
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
	ctx.lr = 0x826C3EB8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// li r30,0
	r30.s64 = 0;
	// lwzx r31,r10,r11
	r31.u64 = PPC_LOAD_U32(ctx.r10.u32 + r11.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c3f04
	if (cr6.eq) goto loc_826C3F04;
loc_826C3EDC:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c68c0
	ctx.lr = 0x826C3EE8;
	sub_826C68C0(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c3f10
	if (!cr6.eq) goto loc_826C3F10;
	// mr r30,r31
	r30.u64 = r31.u64;
	// lwz r31,8(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// bne cr6,0x826c3edc
	if (!cr6.eq) goto loc_826C3EDC;
loc_826C3F04:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826C3F10:
	// stw r30,0(r28)
	PPC_STORE_U32(r28.u32 + 0, r30.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C3EB0) {
	__imp__sub_826C3EB0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3F20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r4,4
	ctx.r9.s64 = ctx.r4.s64 + 4;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r7,r9,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r11,28
	ctx.r10.s64 = r11.s64 + 28;
	// addi r4,r4,174
	ctx.r4.s64 = ctx.r4.s64 + 174;
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// lwz r8,28(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// addi r6,r10,1
	ctx.r6.s64 = ctx.r10.s64 + 1;
	// rotlwi r9,r10,2
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r10,32(r11)
	PPC_STORE_U16(r11.u32 + 32, ctx.r10.u16);
	// stwx r5,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r5.u32);
	// lhzx r11,r7,r3
	r11.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r3.u32);
	// addi r4,r11,-1
	ctx.r4.s64 = r11.s64 + -1;
	// stwx r4,r6,r5
	PPC_STORE_U32(ctx.r6.u32 + ctx.r5.u32, ctx.r4.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C3F20) {
	__imp__sub_826C3F20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C3F68) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r30{};
	PPCRegister r31{};
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, r31.u64);
	// addi r11,r4,4
	r11.s64 = ctx.r4.s64 + 4;
	// li r31,0
	r31.s64 = 0;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// li r7,0
	ctx.r7.s64 = 0;
	// lhzx r6,r10,r3
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// cmpwi cr6,r6,0
	cr6.compare<int32_t>(ctx.r6.s32, 0, xer);
	// ble cr6,0x826c4018
	if (!cr6.gt) goto loc_826C4018;
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r4,174
	ctx.r10.s64 = ctx.r4.s64 + 174;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r11,28
	ctx.r8.s64 = r11.s64 + 28;
	// lwz r11,28(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// lwzx r9,r10,r5
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r5.u32);
loc_826C3FA8:
	// lwz r30,0(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwzx r30,r10,r30
	r30.u64 = PPC_LOAD_U32(ctx.r10.u32 + r30.u32);
	// cmpw cr6,r9,r30
	cr6.compare<int32_t>(ctx.r9.s32, r30.s32, xer);
	// blt cr6,0x826c3fcc
	if (cr6.lt) goto loc_826C3FCC;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// cmpw cr6,r7,r6
	cr6.compare<int32_t>(ctx.r7.s32, ctx.r6.s32, xer);
	// blt cr6,0x826c3fa8
	if (cr6.lt) goto loc_826C3FA8;
	// b 0x826c4018
	goto loc_826C4018;
loc_826C3FCC:
	// lhz r11,4(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// cmpw cr6,r11,r7
	cr6.compare<int32_t>(r11.s32, ctx.r7.s32, xer);
	// ble cr6,0x826c3ffc
	if (!cr6.gt) goto loc_826C3FFC;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r7,r11
	r11.s64 = r11.s64 - ctx.r7.s64;
loc_826C3FE0:
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// lwz r6,-4(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// stw r6,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r6.u32);
	// bne 0x826c3fe0
	if (!cr0.eq) goto loc_826C3FE0;
loc_826C3FFC:
	// lhz r11,4(r8)
	r11.u64 = PPC_LOAD_U16(ctx.r8.u32 + 4);
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,0(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// li r31,1
	r31.s64 = 1;
	// addi r7,r11,1
	ctx.r7.s64 = r11.s64 + 1;
	// sth r7,4(r8)
	PPC_STORE_U16(ctx.r8.u32 + 4, ctx.r7.u16);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
loc_826C4018:
	// clrlwi r11,r31,24
	r11.u64 = r31.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c404c
	if (!cr6.eq) goto loc_826C404C;
	// rlwinm r11,r4,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r3
	r11.u64 = r11.u64 + ctx.r3.u64;
	// addi r10,r11,28
	ctx.r10.s64 = r11.s64 + 28;
	// lhz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// lwz r9,28(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 28);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// rotlwi r10,r10,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// sth r8,32(r11)
	PPC_STORE_U16(r11.u32 + 32, ctx.r8.u16);
	// stwx r5,r10,r9
	PPC_STORE_U32(ctx.r10.u32 + ctx.r9.u32, ctx.r5.u32);
loc_826C404C:
	// ld r30,-16(r1)
	r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C3F68) {
	__imp__sub_826C3F68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4058) {
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
	ctx.lr = 0x826C4060;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r30,174
	ctx.r10.s64 = r30.s64 + 174;
	// add r11,r11,r31
	r11.u64 = r11.u64 + r31.u64;
	// rlwinm r29,r10,2,0,29
	r29.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r11,28
	r28.s64 = r11.s64 + 28;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// lwzx r4,r29,r5
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + ctx.r5.u32);
	// bl 0x8262cb88
	ctx.lr = 0x826C408C;
	sub_8262CB88(ctx, base);
	// addi r9,r30,4
	ctx.r9.s64 = r30.s64 + 4;
	// li r11,0
	r11.s64 = 0;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lhzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + r31.u32);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826c40c8
	if (cr6.eq) goto loc_826C40C8;
	// li r10,0
	ctx.r10.s64 = 0;
loc_826C40A8:
	// lwz r8,0(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stwx r11,r7,r29
	PPC_STORE_U32(ctx.r7.u32 + r29.u32, r11.u32);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// lhzx r6,r9,r31
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + r31.u32);
	// cmpw cr6,r11,r6
	cr6.compare<int32_t>(r11.s32, ctx.r6.s32, xer);
	// blt cr6,0x826c40a8
	if (cr6.lt) goto loc_826C40A8;
loc_826C40C8:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C4058) {
	__imp__sub_826C4058(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C40D0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x826C40D8;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r17,0
	r17.s64 = 0;
	// lhz r11,32(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4380
	if (cr6.eq) goto loc_826C4380;
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r31,0
	r31.s64 = 0;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// addi r19,r5,-8100
	r19.s64 = ctx.r5.s64 + -8100;
	// addi r26,r4,-8116
	r26.s64 = ctx.r4.s64 + -8116;
	// addi r22,r3,-8136
	r22.s64 = ctx.r3.s64 + -8136;
	// addi r21,r6,-8160
	r21.s64 = ctx.r6.s64 + -8160;
	// addi r18,r7,7044
	r18.s64 = ctx.r7.s64 + 7044;
	// addi r20,r8,-8184
	r20.s64 = ctx.r8.s64 + -8184;
	// addi r25,r9,-8220
	r25.s64 = ctx.r9.s64 + -8220;
	// addi r24,r10,-8248
	r24.s64 = ctx.r10.s64 + -8248;
	// addi r23,r11,-8260
	r23.s64 = r11.s64 + -8260;
loc_826C4140:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// lwzx r11,r31,r11
	r11.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// addi r4,r11,72
	ctx.r4.s64 = r11.s64 + 72;
	// bl 0x823d9750
	ctx.lr = 0x826C4154;
	sub_823D9750(ctx, base);
	// lwz r10,28(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwz r3,-10244(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10244);
	// lwzx r11,r31,r10
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r10.u32);
	// addi r29,r11,200
	r29.s64 = r11.s64 + 200;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x826C416C;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C417C;
	sub_823D9750(ctx, base);
	// lwz r9,28(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwz r3,-10244(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10244);
	// lwzx r11,r31,r9
	r11.u64 = PPC_LOAD_U32(r31.u32 + ctx.r9.u32);
	// addi r29,r11,328
	r29.s64 = r11.s64 + 328;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x82218310
	ctx.lr = 0x826C4194;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C41A4;
	sub_823D9750(ctx, base);
	// lwz r8,28(r30)
	ctx.r8.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r7,r31,r8
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + ctx.r8.u32);
	// lhz r6,712(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 712);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// beq cr6,0x826c4210
	if (cr6.eq) goto loc_826C4210;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C41C0;
	sub_823D9750(ctx, base);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r29,0
	r29.s64 = 0;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,712(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 712);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c4208
	if (cr6.eq) goto loc_826C4208;
loc_826C41DC:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826c7288
	ctx.lr = 0x826C41E8;
	sub_826C7288(ctx, base);
	// bl 0x826cc2d0
	ctx.lr = 0x826C41EC;
	sub_826CC2D0(ctx, base);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,712(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 712);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x826c41dc
	if (cr6.lt) goto loc_826C41DC;
loc_826C4208:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C4210;
	sub_823D9750(ctx, base);
loc_826C4210:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lhz r9,720(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 720);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c427c
	if (cr6.eq) goto loc_826C427C;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C422C;
	sub_823D9750(ctx, base);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r29,0
	r29.s64 = 0;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,720(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 720);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c4274
	if (cr6.eq) goto loc_826C4274;
loc_826C4248:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826c72a0
	ctx.lr = 0x826C4254;
	sub_826C72A0(ctx, base);
	// bl 0x826cc2d0
	ctx.lr = 0x826C4258;
	sub_826CC2D0(ctx, base);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,720(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 720);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x826c4248
	if (cr6.lt) goto loc_826C4248;
loc_826C4274:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C427C;
	sub_823D9750(ctx, base);
loc_826C427C:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r10,728(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 728);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c42e0
	if (cr6.eq) goto loc_826C42E0;
	// li r29,0
	r29.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826c42d8
	if (!cr6.gt) goto loc_826C42D8;
loc_826C42A0:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826c72b8
	ctx.lr = 0x826C42AC;
	sub_826C72B8(ctx, base);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C42BC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r8,728(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 728);
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x826c42a0
	if (cr6.lt) goto loc_826C42A0;
loc_826C42D8:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C42E0;
	sub_823D9750(ctx, base);
loc_826C42E0:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r10,r31,r11
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + r11.u32);
	// lhz r9,748(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 748);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c4364
	if (cr6.eq) goto loc_826C4364;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C42FC;
	sub_823D9750(ctx, base);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// li r29,0
	r29.s64 = 0;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,748(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 748);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c4364
	if (cr6.eq) goto loc_826C4364;
loc_826C4318:
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// bl 0x826c72c8
	ctx.lr = 0x826C4324;
	sub_826C72C8(ctx, base);
	// lwz r11,-10244(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10244);
	// addi r28,r3,4
	r28.s64 = ctx.r3.s64 + 4;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x82218310
	ctx.lr = 0x826C4338;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C4348;
	sub_823D9750(ctx, base);
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// add r11,r31,r11
	r11.u64 = r31.u64 + r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lhz r9,748(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 748);
	// cmpw cr6,r29,r9
	cr6.compare<int32_t>(r29.s32, ctx.r9.s32, xer);
	// blt cr6,0x826c4318
	if (cr6.lt) goto loc_826C4318;
loc_826C4364:
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823d9750
	ctx.lr = 0x826C436C;
	sub_823D9750(ctx, base);
	// lhz r11,32(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 32);
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r17,r11
	cr6.compare<int32_t>(r17.s32, r11.s32, xer);
	// blt cr6,0x826c4140
	if (cr6.lt) goto loc_826C4140;
loc_826C4380:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_826C40D0) {
	__imp__sub_826C40D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4388) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
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
	// lhz r11,32(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
	// li r7,0
	ctx.r7.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c43d8
	if (cr6.eq) goto loc_826C43D8;
	// lwz r11,28(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 28);
	// lhz r9,32(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 32);
loc_826C43AC:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r8,685(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 685);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c43cc
	if (!cr6.eq) goto loc_826C43CC;
	// lbz r10,693(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 693);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c43cc
	if (!cr6.eq) goto loc_826C43CC;
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
loc_826C43CC:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826c43ac
	if (!cr0.eq) goto loc_826C43AC;
loc_826C43D8:
	// lhz r11,48(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c441c
	if (cr6.eq) goto loc_826C441C;
	// lwz r11,44(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// lhz r9,48(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 48);
loc_826C43F0:
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lbz r6,685(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 685);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826c4410
	if (!cr6.eq) goto loc_826C4410;
	// lbz r10,693(r10)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r10.u32 + 693);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c4410
	if (!cr6.eq) goto loc_826C4410;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_826C4410:
	// addic. r9,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r9.s32, 0, xer);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// bne 0x826c43f0
	if (!cr0.eq) goto loc_826C43F0;
loc_826C441C:
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x826c4454
	if (cr6.eq) goto loc_826C4454;
	// extsw r11,r7
	r11.s64 = ctx.r7.s32;
	// extsw r10,r8
	ctx.r10.s64 = ctx.r8.s32;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f0
	ctx.f11.f64 = double(f0.s64);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fdivs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 / ctx.f9.f64));
	// stfs f8,76(r3)
	temp.f32 = float(ctx.f8.f64);
	PPC_STORE_U32(ctx.r3.u32 + 76, temp.u32);
loc_826C4454:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lfs f13,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r9,-32252
	ctx.r9.s64 = -2113667072;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r9,-18192
	ctx.r4.s64 = ctx.r9.s64 + -18192;
	// lfs f0,31016(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 31016);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// lwz r3,-12440(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12440);
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r7,48(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 48);
	// lwz r6,84(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mtctr r7
	ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826C4494;
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

PPC_WEAK_FUNC(sub_826C4388) {
	__imp__sub_826C4388(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C44A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C44A4) {
	__imp__sub_826C44A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C44A8) {
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
	ctx.lr = 0x826C44B0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r11,-10004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4508
	if (cr6.eq) goto loc_826C4508;
	// lhz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 40);
	// addi r30,r11,36
	r30.s64 = r11.s64 + 36;
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c4508
	if (cr6.eq) goto loc_826C4508;
	// li r31,0
	r31.s64 = 0;
loc_826C44E0:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x826c72d8
	ctx.lr = 0x826C44EC;
	sub_826C72D8(ctx, base);
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// beq cr6,0x826c4514
	if (cr6.eq) goto loc_826C4514;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c44e0
	if (cr6.lt) goto loc_826C44E0;
loc_826C4508:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826C4514:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C44A8) {
	__imp__sub_826C44A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4520) {
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
	ctx.lr = 0x826C4528;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,32(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4588
	if (cr6.eq) goto loc_826C4588;
	// li r31,0
	r31.s64 = 0;
loc_826C4544:
	// lwz r11,28(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 28);
	// lwzx r3,r11,r31
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// lbz r10,691(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 691);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c4560
	if (cr6.eq) goto loc_826C4560;
	// lbz r11,690(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 690);
	// b 0x826c4564
	goto loc_826C4564;
loc_826C4560:
	// li r11,0
	r11.s64 = 0;
loc_826C4564:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4574
	if (cr6.eq) goto loc_826C4574;
	// bl 0x826c7370
	ctx.lr = 0x826C4574;
	sub_826C7370(ctx, base);
loc_826C4574:
	// lhz r11,32(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 32);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c4544
	if (cr6.lt) goto loc_826C4544;
loc_826C4588:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826C4520) {
	__imp__sub_826C4520(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4590) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,-10004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// lhz r11,32(r9)
	r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// li r10,0
	ctx.r10.s64 = 0;
loc_826C45B4:
	// cmpwi cr6,r6,-1
	cr6.compare<int32_t>(ctx.r6.s32, -1, xer);
	// beq cr6,0x826c45d4
	if (cr6.eq) goto loc_826C45D4;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwz r4,676(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 676);
	// and r8,r4,r6
	ctx.r8.u64 = ctx.r4.u64 & ctx.r6.u64;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// beq cr6,0x826c45f8
	if (cr6.eq) goto loc_826C45F8;
loc_826C45D4:
	// clrlwi r8,r5,24
	ctx.r8.u64 = ctx.r5.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826c45f4
	if (cr6.eq) goto loc_826C45F4;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwzx r7,r8,r10
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lbz r4,685(r7)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r7.u32 + 685);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// bne cr6,0x826c45f8
	if (!cr6.eq) goto loc_826C45F8;
loc_826C45F4:
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_826C45F8:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x826c45b4
	if (!cr0.eq) goto loc_826C45B4;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C4590) {
	__imp__sub_826C4590(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4608) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82618670
	ctx.lr = 0x826C462C;
	sub_82618670(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r11,r11,-1
	r11.s64 = r11.s64 + -1;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// and r30,r11,r3
	r30.u64 = r11.u64 & ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x826c3eb0
	ctx.lr = 0x826C464C;
	sub_826C3EB0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c46a0
	if (cr6.eq) goto loc_826C46A0;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c4670
	if (cr6.eq) goto loc_826C4670;
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r9,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// b 0x826c4680
	goto loc_826C4680;
loc_826C4670:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stwx r8,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, ctx.r8.u32);
loc_826C4680:
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// b 0x826c46a4
	goto loc_826C46A4;
loc_826C46A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C46A4:
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

PPC_WEAK_FUNC(sub_826C4608) {
	__imp__sub_826C4608(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C46BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C46BC) {
	__imp__sub_826C46BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C46C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lhz r11,2(r5)
	r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 2);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bnelr cr6
	if (!cr6.eq) return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// ori r8,r10,64167
	ctx.r8.u64 = ctx.r10.u64 | 64167;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// addis r6,r11,1
	ctx.r6.s64 = r11.s64 + 65536;
	// lwz r11,-10004(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10004);
	// lfs f0,14348(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 14348);
	f0.f64 = double(temp.f32);
	// addi r6,r6,27768
	ctx.r6.s64 = ctx.r6.s64 + 27768;
	// lfs f13,88(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,92(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// lwz r10,4(r6)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// mulld r9,r5,r8
	ctx.r9.s64 = ctx.r5.s64 * ctx.r8.s64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// clrlwi r8,r10,9
	ctx.r8.u64 = ctx.r10.u32 & 0x7FFFFF;
	// stw r10,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// rldicl r7,r10,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF;
	// std r8,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r8.u64);
	// lfd f10,-16(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// stw r7,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r7.u32);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// fmadds f6,f7,f0,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stfs f6,84(r11)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C46C0) {
	__imp__sub_826C46C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4744) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C4744) {
	__imp__sub_826C4744(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4748) {
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
	ctx.lr = 0x826C4750;
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -96, f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// clrlwi r11,r5,24
	r11.u64 = ctx.r5.u32 & 0xFF;
	// fmr f31,f1
	f31.f64 = ctx.f1.f64;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c4a5c
	if (!cr6.eq) goto loc_826C4A5C;
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lwz r11,-10220(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4a5c
	if (cr6.eq) goto loc_826C4A5C;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4a5c
	if (cr6.eq) goto loc_826C4A5C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10000(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10000);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4a5c
	if (cr6.eq) goto loc_826C4A5C;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82701bd8
	ctx.lr = 0x826C47A4;
	sub_82701BD8(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// bgt cr6,0x826c4a5c
	if (cr6.gt) goto loc_826C4A5C;
	// lwz r3,-10220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10220);
	// lbz r11,628(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 628);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c4a5c
	if (!cr6.eq) goto loc_826C4A5C;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,104(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 104);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C47CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c4a5c
	if (!cr6.eq) goto loc_826C4A5C;
	// lwz r3,-10236(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// bl 0x821f7c90
	ctx.lr = 0x826C47E0;
	sub_821F7C90(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c4a5c
	if (!cr6.eq) goto loc_826C4A5C;
	// bl 0x823bbf80
	ctx.lr = 0x826C47F0;
	sub_823BBF80(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c4a5c
	if (!cr6.eq) goto loc_826C4A5C;
	// lhz r11,40(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 40);
	// addi r30,r24,36
	r30.s64 = r24.s64 + 36;
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826c4a5c
	if (!cr6.gt) goto loc_826C4A5C;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_826C4814:
	// lwz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r8,685(r9)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + 685);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c4828
	if (!cr6.eq) goto loc_826C4828;
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
loc_826C4828:
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bne 0x826c4814
	if (!cr0.eq) goto loc_826C4814;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x826c4a5c
	if (cr6.eq) goto loc_826C4A5C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r3,r11,-11844
	ctx.r3.s64 = r11.s64 + -11844;
	// bl 0x821fa230
	ctx.lr = 0x826C4848;
	sub_821FA230(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,312(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 312);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826C4858;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826c4a5c
	if (cr6.eq) goto loc_826C4A5C;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82207370
	ctx.lr = 0x826C486C;
	sub_82207370(ctx, base);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bne cr6,0x826c4a5c
	if (!cr6.eq) goto loc_826C4A5C;
	// lfs f0,84(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r24.u32 + 84);
	f0.f64 = double(temp.f32);
	// lis r11,-32256
	r11.s64 = -2113929216;
	// fsubs f13,f0,f31
	ctx.f13.f64 = double(float(f0.f64 - f31.f64));
	// stfs f13,84(r24)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r24.u32 + 84, temp.u32);
	// lfs f0,3796(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bge cr6,0x826c4a5c
	if (!cr6.lt) goto loc_826C4A5C;
	// lis r27,-32121
	r27.s64 = -2105081856;
	// lfs f13,88(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,23772
	r11.s64 = 1557921792;
	// lfs f12,92(r24)
	temp.u32 = PPC_LOAD_U32(r24.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fsubs f11,f12,f13
	ctx.f11.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// ori r8,r11,64167
	ctx.r8.u64 = r11.u64 | 64167;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-10020(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10020);
	// twllei r31,0
	// addis r7,r11,1
	ctx.r7.s64 = r11.s64 + 65536;
	// lfs f0,14348(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14348);
	f0.f64 = double(temp.f32);
	// addi r7,r7,27768
	ctx.r7.s64 = ctx.r7.s64 + 27768;
	// lwz r6,0(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r11,4(r7)
	r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mulld r9,r6,r8
	ctx.r9.s64 = ctx.r6.s64 * ctx.r8.s64;
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// rldicl r4,r11,32,32
	ctx.r4.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// stw r11,0(r7)
	PPC_STORE_U32(ctx.r7.u32 + 0, r11.u32);
	// clrlwi r8,r11,9
	ctx.r8.u64 = r11.u32 & 0x7FFFFF;
	// stw r4,4(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4, ctx.r4.u32);
	// lwz r9,80(r24)
	ctx.r9.u64 = PPC_LOAD_U32(r24.u32 + 80);
	// std r8,128(r1)
	PPC_STORE_U64(ctx.r1.u32 + 128, ctx.r8.u64);
	// lfd f10,128(r1)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// frsp f8,f9
	ctx.f8.f64 = double(float(ctx.f9.f64));
	// rotlwi r11,r9,1
	r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// divw r7,r9,r31
	ctx.r7.s32 = ctx.r9.s32 / r31.s32;
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// mullw r5,r7,r31
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(r31.s32);
	// fmuls f7,f11,f8
	ctx.f7.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// andc r4,r31,r6
	ctx.r4.u64 = r31.u64 & ~ctx.r6.u64;
	// subf r8,r5,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r5.s64;
	// twlgei r4,-1
	// fmadds f6,f7,f0,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 * f0.f64 + ctx.f13.f64));
	// stfs f6,84(r24)
	temp.f32 = float(ctx.f6.f64);
	PPC_STORE_U32(r24.u32 + 84, temp.u32);
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826c495c
	if (!cr6.gt) goto loc_826C495C;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
loc_826C4930:
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lbz r6,685(r7)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r7.u32 + 685);
	// cmplwi cr6,r6,0
	cr6.compare<uint32_t>(ctx.r6.u32, 0, xer);
	// bne cr6,0x826c494c
	if (!cr6.eq) goto loc_826C494C;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826c495c
	if (!cr6.gt) goto loc_826C495C;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
loc_826C494C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmpw cr6,r10,r11
	cr6.compare<int32_t>(ctx.r10.s32, r11.s32, xer);
	// blt cr6,0x826c4930
	if (cr6.lt) goto loc_826C4930;
loc_826C495C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r31,r10,2,0,29
	r31.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,-10020(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + -10020);
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r28,r11,520
	r28.s64 = r11.s64 + 520;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// bl 0x826be2b0
	ctx.lr = 0x826C4978;
	sub_826BE2B0(ctx, base);
	// lwz r29,0(r30)
	r29.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r25,r11,-18792
	r25.s64 = r11.s64 + -18792;
	// addi r11,r10,-8080
	r11.s64 = ctx.r10.s64 + -8080;
	// lwzx r10,r29,r31
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r30,r10,72
	r30.s64 = ctx.r10.s64 + 72;
	// mr r10,r30
	ctx.r10.u64 = r30.u64;
loc_826C499C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826c49c0
	if (cr6.eq) goto loc_826C49C0;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c499c
	if (cr6.eq) goto loc_826C499C;
loc_826C49C0:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826c49d0
	if (!cr6.eq) goto loc_826C49D0;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r25,r11,3998
	r25.s64 = r11.s64 + 3998;
loc_826C49D0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lwzx r3,r29,r31
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// lwz r27,-10020(r27)
	r27.u64 = PPC_LOAD_U32(r27.u32 + -10020);
	// addi r23,r11,-10052
	r23.s64 = r11.s64 + -10052;
	// bl 0x826c73f8
	ctx.lr = 0x826C49E4;
	sub_826C73F8(ctx, base);
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// lwzx r3,r29,r31
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + r31.u32);
	// bl 0x826c73f8
	ctx.lr = 0x826C49F0;
	sub_826C73F8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// addi r29,r10,-8096
	r29.s64 = ctx.r10.s64 + -8096;
	// bl 0x826be310
	ctx.lr = 0x826C4A08;
	sub_826BE310(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r8,2
	ctx.r8.s64 = 2;
	// stw r22,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, r22.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// stw r25,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r25.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r8,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// stw r26,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, r26.u32);
	// lfs f1,14988(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 14988);
	ctx.f1.f64 = double(temp.f32);
	// li r3,1
	ctx.r3.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// stb r7,103(r1)
	PPC_STORE_U8(ctx.r1.u32 + 103, ctx.r7.u8);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// stw r23,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, r23.u32);
	// mr r9,r29
	ctx.r9.u64 = r29.u64;
	// mr r10,r31
	ctx.r10.u64 = r31.u64;
	// bl 0x8220def0
	ctx.lr = 0x826C4A50;
	sub_8220DEF0(ctx, base);
	// lwz r11,80(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 80);
	// addi r6,r11,1
	ctx.r6.s64 = r11.s64 + 1;
	// stw r6,80(r24)
	PPC_STORE_U32(r24.u32 + 80, ctx.r6.u32);
loc_826C4A5C:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_826C4748) {
	__imp__sub_826C4748(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4A68) {
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
	ctx.lr = 0x826C4A70;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r27,r6
	r27.u64 = ctx.r6.u64;
	// bl 0x826c4590
	ctx.lr = 0x826C4A90;
	sub_826C4590(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r28,0
	r28.s64 = 0;
	// stwx r3,r11,r26
	PPC_STORE_U32(r11.u32 + r26.u32, ctx.r3.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lhz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c4af0
	if (cr6.eq) goto loc_826C4AF0;
	// li r29,0
	r29.s64 = 0;
loc_826C4AB8:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r3,r11,r29
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// lwz r10,676(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 676);
	// and r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & r27.u64;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c4adc
	if (cr6.eq) goto loc_826C4ADC;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// bl 0x826c69c8
	ctx.lr = 0x826C4ADC;
	sub_826C69C8(ctx, base);
loc_826C4ADC:
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x826c4ab8
	if (cr6.lt) goto loc_826C4AB8;
loc_826C4AF0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826C4A68) {
	__imp__sub_826C4A68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4AF8) {
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
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4b2c
	if (cr6.eq) goto loc_826C4B2C;
	// bl 0x821bbea8
	ctx.lr = 0x826C4B2C;
	sub_821BBEA8(ctx, base);
loc_826C4B2C:
	// bl 0x826b7f00
	ctx.lr = 0x826C4B30;
	sub_826B7F00(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4b3c
	if (cr6.eq) goto loc_826C4B3C;
	// bl 0x821bbf00
	ctx.lr = 0x826C4B3C;
	sub_821BBF00(ctx, base);
loc_826C4B3C:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4b58
	if (cr6.eq) goto loc_826C4B58;
	// bl 0x821bbea8
	ctx.lr = 0x826C4B58;
	sub_821BBEA8(ctx, base);
loc_826C4B58:
	// bl 0x826b8018
	ctx.lr = 0x826C4B5C;
	sub_826B8018(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4b68
	if (cr6.eq) goto loc_826C4B68;
	// bl 0x821bbf00
	ctx.lr = 0x826C4B68;
	sub_821BBF00(ctx, base);
loc_826C4B68:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4b84
	if (cr6.eq) goto loc_826C4B84;
	// bl 0x821bbea8
	ctx.lr = 0x826C4B84;
	sub_821BBEA8(ctx, base);
loc_826C4B84:
	// bl 0x826b8170
	ctx.lr = 0x826C4B88;
	sub_826B8170(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4b94
	if (cr6.eq) goto loc_826C4B94;
	// bl 0x821bbf00
	ctx.lr = 0x826C4B94;
	sub_821BBF00(ctx, base);
loc_826C4B94:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4bb0
	if (cr6.eq) goto loc_826C4BB0;
	// bl 0x821bbea8
	ctx.lr = 0x826C4BB0;
	sub_821BBEA8(ctx, base);
loc_826C4BB0:
	// bl 0x826b82b8
	ctx.lr = 0x826C4BB4;
	sub_826B82B8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4bc0
	if (cr6.eq) goto loc_826C4BC0;
	// bl 0x821bbf00
	ctx.lr = 0x826C4BC0;
	sub_821BBF00(ctx, base);
loc_826C4BC0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4bdc
	if (cr6.eq) goto loc_826C4BDC;
	// bl 0x821bbea8
	ctx.lr = 0x826C4BDC;
	sub_821BBEA8(ctx, base);
loc_826C4BDC:
	// bl 0x826b8400
	ctx.lr = 0x826C4BE0;
	sub_826B8400(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4bec
	if (cr6.eq) goto loc_826C4BEC;
	// bl 0x821bbf00
	ctx.lr = 0x826C4BEC;
	sub_821BBF00(ctx, base);
loc_826C4BEC:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4c08
	if (cr6.eq) goto loc_826C4C08;
	// bl 0x821bbea8
	ctx.lr = 0x826C4C08;
	sub_821BBEA8(ctx, base);
loc_826C4C08:
	// bl 0x826b8548
	ctx.lr = 0x826C4C0C;
	sub_826B8548(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4c18
	if (cr6.eq) goto loc_826C4C18;
	// bl 0x821bbf00
	ctx.lr = 0x826C4C18;
	sub_821BBF00(ctx, base);
loc_826C4C18:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4c34
	if (cr6.eq) goto loc_826C4C34;
	// bl 0x821bbea8
	ctx.lr = 0x826C4C34;
	sub_821BBEA8(ctx, base);
loc_826C4C34:
	// bl 0x826b86b0
	ctx.lr = 0x826C4C38;
	sub_826B86B0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4c44
	if (cr6.eq) goto loc_826C4C44;
	// bl 0x821bbf00
	ctx.lr = 0x826C4C44;
	sub_821BBF00(ctx, base);
loc_826C4C44:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4c60
	if (cr6.eq) goto loc_826C4C60;
	// bl 0x821bbea8
	ctx.lr = 0x826C4C60;
	sub_821BBEA8(ctx, base);
loc_826C4C60:
	// bl 0x826b87f8
	ctx.lr = 0x826C4C64;
	sub_826B87F8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4c70
	if (cr6.eq) goto loc_826C4C70;
	// bl 0x821bbf00
	ctx.lr = 0x826C4C70;
	sub_821BBF00(ctx, base);
loc_826C4C70:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4c8c
	if (cr6.eq) goto loc_826C4C8C;
	// bl 0x821bbea8
	ctx.lr = 0x826C4C8C;
	sub_821BBEA8(ctx, base);
loc_826C4C8C:
	// bl 0x826b8940
	ctx.lr = 0x826C4C90;
	sub_826B8940(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4c9c
	if (cr6.eq) goto loc_826C4C9C;
	// bl 0x821bbf00
	ctx.lr = 0x826C4C9C;
	sub_821BBF00(ctx, base);
loc_826C4C9C:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4cb8
	if (cr6.eq) goto loc_826C4CB8;
	// bl 0x821bbea8
	ctx.lr = 0x826C4CB8;
	sub_821BBEA8(ctx, base);
loc_826C4CB8:
	// bl 0x826b8aa8
	ctx.lr = 0x826C4CBC;
	sub_826B8AA8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4cc8
	if (cr6.eq) goto loc_826C4CC8;
	// bl 0x821bbf00
	ctx.lr = 0x826C4CC8;
	sub_821BBF00(ctx, base);
loc_826C4CC8:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4ce4
	if (cr6.eq) goto loc_826C4CE4;
	// bl 0x821bbea8
	ctx.lr = 0x826C4CE4;
	sub_821BBEA8(ctx, base);
loc_826C4CE4:
	// bl 0x826b8bf0
	ctx.lr = 0x826C4CE8;
	sub_826B8BF0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4cf4
	if (cr6.eq) goto loc_826C4CF4;
	// bl 0x821bbf00
	ctx.lr = 0x826C4CF4;
	sub_821BBF00(ctx, base);
loc_826C4CF4:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4d10
	if (cr6.eq) goto loc_826C4D10;
	// bl 0x821bbea8
	ctx.lr = 0x826C4D10;
	sub_821BBEA8(ctx, base);
loc_826C4D10:
	// bl 0x826b8d48
	ctx.lr = 0x826C4D14;
	sub_826B8D48(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4d20
	if (cr6.eq) goto loc_826C4D20;
	// bl 0x821bbf00
	ctx.lr = 0x826C4D20;
	sub_821BBF00(ctx, base);
loc_826C4D20:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4d3c
	if (cr6.eq) goto loc_826C4D3C;
	// bl 0x821bbea8
	ctx.lr = 0x826C4D3C;
	sub_821BBEA8(ctx, base);
loc_826C4D3C:
	// bl 0x826b8e90
	ctx.lr = 0x826C4D40;
	sub_826B8E90(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4d4c
	if (cr6.eq) goto loc_826C4D4C;
	// bl 0x821bbf00
	ctx.lr = 0x826C4D4C;
	sub_821BBF00(ctx, base);
loc_826C4D4C:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4d68
	if (cr6.eq) goto loc_826C4D68;
	// bl 0x821bbea8
	ctx.lr = 0x826C4D68;
	sub_821BBEA8(ctx, base);
loc_826C4D68:
	// bl 0x826d2a08
	ctx.lr = 0x826C4D6C;
	sub_826D2A08(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4d78
	if (cr6.eq) goto loc_826C4D78;
	// bl 0x821bbf00
	ctx.lr = 0x826C4D78;
	sub_821BBF00(ctx, base);
loc_826C4D78:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4d94
	if (cr6.eq) goto loc_826C4D94;
	// bl 0x821bbea8
	ctx.lr = 0x826C4D94;
	sub_821BBEA8(ctx, base);
loc_826C4D94:
	// bl 0x826d2b10
	ctx.lr = 0x826C4D98;
	sub_826D2B10(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4da4
	if (cr6.eq) goto loc_826C4DA4;
	// bl 0x821bbf00
	ctx.lr = 0x826C4DA4;
	sub_821BBF00(ctx, base);
loc_826C4DA4:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4dc0
	if (cr6.eq) goto loc_826C4DC0;
	// bl 0x821bbea8
	ctx.lr = 0x826C4DC0;
	sub_821BBEA8(ctx, base);
loc_826C4DC0:
	// bl 0x826d2c68
	ctx.lr = 0x826C4DC4;
	sub_826D2C68(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4dd0
	if (cr6.eq) goto loc_826C4DD0;
	// bl 0x821bbf00
	ctx.lr = 0x826C4DD0;
	sub_821BBF00(ctx, base);
loc_826C4DD0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4dec
	if (cr6.eq) goto loc_826C4DEC;
	// bl 0x821bbea8
	ctx.lr = 0x826C4DEC;
	sub_821BBEA8(ctx, base);
loc_826C4DEC:
	// bl 0x826d2db0
	ctx.lr = 0x826C4DF0;
	sub_826D2DB0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4dfc
	if (cr6.eq) goto loc_826C4DFC;
	// bl 0x821bbf00
	ctx.lr = 0x826C4DFC;
	sub_821BBF00(ctx, base);
loc_826C4DFC:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4e18
	if (cr6.eq) goto loc_826C4E18;
	// bl 0x821bbea8
	ctx.lr = 0x826C4E18;
	sub_821BBEA8(ctx, base);
loc_826C4E18:
	// bl 0x826d2ef8
	ctx.lr = 0x826C4E1C;
	sub_826D2EF8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4e28
	if (cr6.eq) goto loc_826C4E28;
	// bl 0x821bbf00
	ctx.lr = 0x826C4E28;
	sub_821BBF00(ctx, base);
loc_826C4E28:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4e44
	if (cr6.eq) goto loc_826C4E44;
	// bl 0x821bbea8
	ctx.lr = 0x826C4E44;
	sub_821BBEA8(ctx, base);
loc_826C4E44:
	// bl 0x826d3058
	ctx.lr = 0x826C4E48;
	sub_826D3058(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4e54
	if (cr6.eq) goto loc_826C4E54;
	// bl 0x821bbf00
	ctx.lr = 0x826C4E54;
	sub_821BBF00(ctx, base);
loc_826C4E54:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4e70
	if (cr6.eq) goto loc_826C4E70;
	// bl 0x821bbea8
	ctx.lr = 0x826C4E70;
	sub_821BBEA8(ctx, base);
loc_826C4E70:
	// bl 0x826d31a0
	ctx.lr = 0x826C4E74;
	sub_826D31A0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4e80
	if (cr6.eq) goto loc_826C4E80;
	// bl 0x821bbf00
	ctx.lr = 0x826C4E80;
	sub_821BBF00(ctx, base);
loc_826C4E80:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4e9c
	if (cr6.eq) goto loc_826C4E9C;
	// bl 0x821bbea8
	ctx.lr = 0x826C4E9C;
	sub_821BBEA8(ctx, base);
loc_826C4E9C:
	// bl 0x826d3310
	ctx.lr = 0x826C4EA0;
	sub_826D3310(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4eac
	if (cr6.eq) goto loc_826C4EAC;
	// bl 0x821bbf00
	ctx.lr = 0x826C4EAC;
	sub_821BBF00(ctx, base);
loc_826C4EAC:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4ec8
	if (cr6.eq) goto loc_826C4EC8;
	// bl 0x821bbea8
	ctx.lr = 0x826C4EC8;
	sub_821BBEA8(ctx, base);
loc_826C4EC8:
	// bl 0x826d3478
	ctx.lr = 0x826C4ECC;
	sub_826D3478(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4ed8
	if (cr6.eq) goto loc_826C4ED8;
	// bl 0x821bbf00
	ctx.lr = 0x826C4ED8;
	sub_821BBF00(ctx, base);
loc_826C4ED8:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4ef4
	if (cr6.eq) goto loc_826C4EF4;
	// bl 0x821bbea8
	ctx.lr = 0x826C4EF4;
	sub_821BBEA8(ctx, base);
loc_826C4EF4:
	// bl 0x826ccec0
	ctx.lr = 0x826C4EF8;
	sub_826CCEC0(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4f04
	if (cr6.eq) goto loc_826C4F04;
	// bl 0x821bbf00
	ctx.lr = 0x826C4F04;
	sub_821BBF00(ctx, base);
loc_826C4F04:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4f20
	if (cr6.eq) goto loc_826C4F20;
	// bl 0x821bbea8
	ctx.lr = 0x826C4F20;
	sub_821BBEA8(ctx, base);
loc_826C4F20:
	// bl 0x826d3f08
	ctx.lr = 0x826C4F24;
	sub_826D3F08(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4f30
	if (cr6.eq) goto loc_826C4F30;
	// bl 0x821bbf00
	ctx.lr = 0x826C4F30;
	sub_821BBF00(ctx, base);
loc_826C4F30:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4f4c
	if (cr6.eq) goto loc_826C4F4C;
	// bl 0x821bbea8
	ctx.lr = 0x826C4F4C;
	sub_821BBEA8(ctx, base);
loc_826C4F4C:
	// bl 0x826d4090
	ctx.lr = 0x826C4F50;
	sub_826D4090(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4f5c
	if (cr6.eq) goto loc_826C4F5C;
	// bl 0x821bbf00
	ctx.lr = 0x826C4F5C;
	sub_821BBF00(ctx, base);
loc_826C4F5C:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4f78
	if (cr6.eq) goto loc_826C4F78;
	// bl 0x821bbea8
	ctx.lr = 0x826C4F78;
	sub_821BBEA8(ctx, base);
loc_826C4F78:
	// bl 0x826d41f8
	ctx.lr = 0x826C4F7C;
	sub_826D41F8(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4f88
	if (cr6.eq) goto loc_826C4F88;
	// bl 0x821bbf00
	ctx.lr = 0x826C4F88;
	sub_821BBF00(ctx, base);
loc_826C4F88:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4fa4
	if (cr6.eq) goto loc_826C4FA4;
	// bl 0x821bbea8
	ctx.lr = 0x826C4FA4;
	sub_821BBEA8(ctx, base);
loc_826C4FA4:
	// bl 0x826d3c18
	ctx.lr = 0x826C4FA8;
	sub_826D3C18(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c4fb4
	if (cr6.eq) goto loc_826C4FB4;
	// bl 0x821bbf00
	ctx.lr = 0x826C4FB4;
	sub_821BBF00(ctx, base);
loc_826C4FB4:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r11,40(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r11,15,31,31
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 15) & 0x1;
	// mr r31,r11
	r31.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c4fd0
	if (cr6.eq) goto loc_826C4FD0;
	// bl 0x821bbea8
	ctx.lr = 0x826C4FD0;
	sub_821BBEA8(ctx, base);
loc_826C4FD0:
	// bl 0x826c7fa8
	ctx.lr = 0x826C4FD4;
	sub_826C7FA8(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c4fe0
	if (cr6.eq) goto loc_826C4FE0;
	// bl 0x821bbf00
	ctx.lr = 0x826C4FE0;
	sub_821BBF00(ctx, base);
loc_826C4FE0:
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

PPC_WEAK_FUNC(sub_826C4AF8) {
	__imp__sub_826C4AF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C4FF8) {
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
	// lis r31,-32125
	r31.s64 = -2105344000;
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c502c
	if (cr6.eq) goto loc_826C502C;
	// bl 0x821bbea8
	ctx.lr = 0x826C502C;
	sub_821BBEA8(ctx, base);
loc_826C502C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27224(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27224);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5044
	if (cr6.eq) goto loc_826C5044;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5044;
	sub_821BFA90(ctx, base);
loc_826C5044:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5050
	if (cr6.eq) goto loc_826C5050;
	// bl 0x821bbf00
	ctx.lr = 0x826C5050;
	sub_821BBF00(ctx, base);
loc_826C5050:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c506c
	if (cr6.eq) goto loc_826C506C;
	// bl 0x821bbea8
	ctx.lr = 0x826C506C;
	sub_821BBEA8(ctx, base);
loc_826C506C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27156(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27156);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5084
	if (cr6.eq) goto loc_826C5084;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5084;
	sub_821BFA90(ctx, base);
loc_826C5084:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5090
	if (cr6.eq) goto loc_826C5090;
	// bl 0x821bbf00
	ctx.lr = 0x826C5090;
	sub_821BBF00(ctx, base);
loc_826C5090:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c50ac
	if (cr6.eq) goto loc_826C50AC;
	// bl 0x821bbea8
	ctx.lr = 0x826C50AC;
	sub_821BBEA8(ctx, base);
loc_826C50AC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27160(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27160);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c50c4
	if (cr6.eq) goto loc_826C50C4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C50C4;
	sub_821BFA90(ctx, base);
loc_826C50C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c50d0
	if (cr6.eq) goto loc_826C50D0;
	// bl 0x821bbf00
	ctx.lr = 0x826C50D0;
	sub_821BBF00(ctx, base);
loc_826C50D0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c50ec
	if (cr6.eq) goto loc_826C50EC;
	// bl 0x821bbea8
	ctx.lr = 0x826C50EC;
	sub_821BBEA8(ctx, base);
loc_826C50EC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27164(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27164);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5104
	if (cr6.eq) goto loc_826C5104;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5104;
	sub_821BFA90(ctx, base);
loc_826C5104:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5110
	if (cr6.eq) goto loc_826C5110;
	// bl 0x821bbf00
	ctx.lr = 0x826C5110;
	sub_821BBF00(ctx, base);
loc_826C5110:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c512c
	if (cr6.eq) goto loc_826C512C;
	// bl 0x821bbea8
	ctx.lr = 0x826C512C;
	sub_821BBEA8(ctx, base);
loc_826C512C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27168(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27168);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5144
	if (cr6.eq) goto loc_826C5144;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5144;
	sub_821BFA90(ctx, base);
loc_826C5144:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5150
	if (cr6.eq) goto loc_826C5150;
	// bl 0x821bbf00
	ctx.lr = 0x826C5150;
	sub_821BBF00(ctx, base);
loc_826C5150:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c516c
	if (cr6.eq) goto loc_826C516C;
	// bl 0x821bbea8
	ctx.lr = 0x826C516C;
	sub_821BBEA8(ctx, base);
loc_826C516C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27208(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27208);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5184
	if (cr6.eq) goto loc_826C5184;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5184;
	sub_821BFA90(ctx, base);
loc_826C5184:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5190
	if (cr6.eq) goto loc_826C5190;
	// bl 0x821bbf00
	ctx.lr = 0x826C5190;
	sub_821BBF00(ctx, base);
loc_826C5190:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c51ac
	if (cr6.eq) goto loc_826C51AC;
	// bl 0x821bbea8
	ctx.lr = 0x826C51AC;
	sub_821BBEA8(ctx, base);
loc_826C51AC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27516(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27516);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c51c4
	if (cr6.eq) goto loc_826C51C4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C51C4;
	sub_821BFA90(ctx, base);
loc_826C51C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c51d0
	if (cr6.eq) goto loc_826C51D0;
	// bl 0x821bbf00
	ctx.lr = 0x826C51D0;
	sub_821BBF00(ctx, base);
loc_826C51D0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c51ec
	if (cr6.eq) goto loc_826C51EC;
	// bl 0x821bbea8
	ctx.lr = 0x826C51EC;
	sub_821BBEA8(ctx, base);
loc_826C51EC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27520(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27520);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5204
	if (cr6.eq) goto loc_826C5204;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5204;
	sub_821BFA90(ctx, base);
loc_826C5204:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5210
	if (cr6.eq) goto loc_826C5210;
	// bl 0x821bbf00
	ctx.lr = 0x826C5210;
	sub_821BBF00(ctx, base);
loc_826C5210:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c522c
	if (cr6.eq) goto loc_826C522C;
	// bl 0x821bbea8
	ctx.lr = 0x826C522C;
	sub_821BBEA8(ctx, base);
loc_826C522C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27524(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27524);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5244
	if (cr6.eq) goto loc_826C5244;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5244;
	sub_821BFA90(ctx, base);
loc_826C5244:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5250
	if (cr6.eq) goto loc_826C5250;
	// bl 0x821bbf00
	ctx.lr = 0x826C5250;
	sub_821BBF00(ctx, base);
loc_826C5250:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c526c
	if (cr6.eq) goto loc_826C526C;
	// bl 0x821bbea8
	ctx.lr = 0x826C526C;
	sub_821BBEA8(ctx, base);
loc_826C526C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27528(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27528);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5284
	if (cr6.eq) goto loc_826C5284;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5284;
	sub_821BFA90(ctx, base);
loc_826C5284:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5290
	if (cr6.eq) goto loc_826C5290;
	// bl 0x821bbf00
	ctx.lr = 0x826C5290;
	sub_821BBF00(ctx, base);
loc_826C5290:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c52ac
	if (cr6.eq) goto loc_826C52AC;
	// bl 0x821bbea8
	ctx.lr = 0x826C52AC;
	sub_821BBEA8(ctx, base);
loc_826C52AC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27532(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27532);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c52c4
	if (cr6.eq) goto loc_826C52C4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C52C4;
	sub_821BFA90(ctx, base);
loc_826C52C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c52d0
	if (cr6.eq) goto loc_826C52D0;
	// bl 0x821bbf00
	ctx.lr = 0x826C52D0;
	sub_821BBF00(ctx, base);
loc_826C52D0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c52ec
	if (cr6.eq) goto loc_826C52EC;
	// bl 0x821bbea8
	ctx.lr = 0x826C52EC;
	sub_821BBEA8(ctx, base);
loc_826C52EC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27536(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27536);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5304
	if (cr6.eq) goto loc_826C5304;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5304;
	sub_821BFA90(ctx, base);
loc_826C5304:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5310
	if (cr6.eq) goto loc_826C5310;
	// bl 0x821bbf00
	ctx.lr = 0x826C5310;
	sub_821BBF00(ctx, base);
loc_826C5310:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c532c
	if (cr6.eq) goto loc_826C532C;
	// bl 0x821bbea8
	ctx.lr = 0x826C532C;
	sub_821BBEA8(ctx, base);
loc_826C532C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27540(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27540);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5344
	if (cr6.eq) goto loc_826C5344;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5344;
	sub_821BFA90(ctx, base);
loc_826C5344:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5350
	if (cr6.eq) goto loc_826C5350;
	// bl 0x821bbf00
	ctx.lr = 0x826C5350;
	sub_821BBF00(ctx, base);
loc_826C5350:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c536c
	if (cr6.eq) goto loc_826C536C;
	// bl 0x821bbea8
	ctx.lr = 0x826C536C;
	sub_821BBEA8(ctx, base);
loc_826C536C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27544(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27544);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5384
	if (cr6.eq) goto loc_826C5384;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5384;
	sub_821BFA90(ctx, base);
loc_826C5384:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5390
	if (cr6.eq) goto loc_826C5390;
	// bl 0x821bbf00
	ctx.lr = 0x826C5390;
	sub_821BBF00(ctx, base);
loc_826C5390:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c53ac
	if (cr6.eq) goto loc_826C53AC;
	// bl 0x821bbea8
	ctx.lr = 0x826C53AC;
	sub_821BBEA8(ctx, base);
loc_826C53AC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27548(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27548);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c53c4
	if (cr6.eq) goto loc_826C53C4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C53C4;
	sub_821BFA90(ctx, base);
loc_826C53C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c53d0
	if (cr6.eq) goto loc_826C53D0;
	// bl 0x821bbf00
	ctx.lr = 0x826C53D0;
	sub_821BBF00(ctx, base);
loc_826C53D0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c53ec
	if (cr6.eq) goto loc_826C53EC;
	// bl 0x821bbea8
	ctx.lr = 0x826C53EC;
	sub_821BBEA8(ctx, base);
loc_826C53EC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27552(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27552);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5404
	if (cr6.eq) goto loc_826C5404;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5404;
	sub_821BFA90(ctx, base);
loc_826C5404:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5410
	if (cr6.eq) goto loc_826C5410;
	// bl 0x821bbf00
	ctx.lr = 0x826C5410;
	sub_821BBF00(ctx, base);
loc_826C5410:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c542c
	if (cr6.eq) goto loc_826C542C;
	// bl 0x821bbea8
	ctx.lr = 0x826C542C;
	sub_821BBEA8(ctx, base);
loc_826C542C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27556(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27556);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5444
	if (cr6.eq) goto loc_826C5444;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5444;
	sub_821BFA90(ctx, base);
loc_826C5444:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5450
	if (cr6.eq) goto loc_826C5450;
	// bl 0x821bbf00
	ctx.lr = 0x826C5450;
	sub_821BBF00(ctx, base);
loc_826C5450:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c546c
	if (cr6.eq) goto loc_826C546C;
	// bl 0x821bbea8
	ctx.lr = 0x826C546C;
	sub_821BBEA8(ctx, base);
loc_826C546C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27560(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27560);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5484
	if (cr6.eq) goto loc_826C5484;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5484;
	sub_821BFA90(ctx, base);
loc_826C5484:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5490
	if (cr6.eq) goto loc_826C5490;
	// bl 0x821bbf00
	ctx.lr = 0x826C5490;
	sub_821BBF00(ctx, base);
loc_826C5490:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c54ac
	if (cr6.eq) goto loc_826C54AC;
	// bl 0x821bbea8
	ctx.lr = 0x826C54AC;
	sub_821BBEA8(ctx, base);
loc_826C54AC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27564(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27564);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c54c4
	if (cr6.eq) goto loc_826C54C4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C54C4;
	sub_821BFA90(ctx, base);
loc_826C54C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c54d0
	if (cr6.eq) goto loc_826C54D0;
	// bl 0x821bbf00
	ctx.lr = 0x826C54D0;
	sub_821BBF00(ctx, base);
loc_826C54D0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c54ec
	if (cr6.eq) goto loc_826C54EC;
	// bl 0x821bbea8
	ctx.lr = 0x826C54EC;
	sub_821BBEA8(ctx, base);
loc_826C54EC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27172(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27172);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5504
	if (cr6.eq) goto loc_826C5504;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5504;
	sub_821BFA90(ctx, base);
loc_826C5504:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5510
	if (cr6.eq) goto loc_826C5510;
	// bl 0x821bbf00
	ctx.lr = 0x826C5510;
	sub_821BBF00(ctx, base);
loc_826C5510:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c552c
	if (cr6.eq) goto loc_826C552C;
	// bl 0x821bbea8
	ctx.lr = 0x826C552C;
	sub_821BBEA8(ctx, base);
loc_826C552C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27176(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27176);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5544
	if (cr6.eq) goto loc_826C5544;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5544;
	sub_821BFA90(ctx, base);
loc_826C5544:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5550
	if (cr6.eq) goto loc_826C5550;
	// bl 0x821bbf00
	ctx.lr = 0x826C5550;
	sub_821BBF00(ctx, base);
loc_826C5550:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c556c
	if (cr6.eq) goto loc_826C556C;
	// bl 0x821bbea8
	ctx.lr = 0x826C556C;
	sub_821BBEA8(ctx, base);
loc_826C556C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27180(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27180);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5584
	if (cr6.eq) goto loc_826C5584;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5584;
	sub_821BFA90(ctx, base);
loc_826C5584:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5590
	if (cr6.eq) goto loc_826C5590;
	// bl 0x821bbf00
	ctx.lr = 0x826C5590;
	sub_821BBF00(ctx, base);
loc_826C5590:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c55ac
	if (cr6.eq) goto loc_826C55AC;
	// bl 0x821bbea8
	ctx.lr = 0x826C55AC;
	sub_821BBEA8(ctx, base);
loc_826C55AC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27184(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27184);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c55c4
	if (cr6.eq) goto loc_826C55C4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C55C4;
	sub_821BFA90(ctx, base);
loc_826C55C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c55d0
	if (cr6.eq) goto loc_826C55D0;
	// bl 0x821bbf00
	ctx.lr = 0x826C55D0;
	sub_821BBF00(ctx, base);
loc_826C55D0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c55ec
	if (cr6.eq) goto loc_826C55EC;
	// bl 0x821bbea8
	ctx.lr = 0x826C55EC;
	sub_821BBEA8(ctx, base);
loc_826C55EC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27188(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27188);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5604
	if (cr6.eq) goto loc_826C5604;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5604;
	sub_821BFA90(ctx, base);
loc_826C5604:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5610
	if (cr6.eq) goto loc_826C5610;
	// bl 0x821bbf00
	ctx.lr = 0x826C5610;
	sub_821BBF00(ctx, base);
loc_826C5610:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c562c
	if (cr6.eq) goto loc_826C562C;
	// bl 0x821bbea8
	ctx.lr = 0x826C562C;
	sub_821BBEA8(ctx, base);
loc_826C562C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27192(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27192);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5644
	if (cr6.eq) goto loc_826C5644;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5644;
	sub_821BFA90(ctx, base);
loc_826C5644:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5650
	if (cr6.eq) goto loc_826C5650;
	// bl 0x821bbf00
	ctx.lr = 0x826C5650;
	sub_821BBF00(ctx, base);
loc_826C5650:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c566c
	if (cr6.eq) goto loc_826C566C;
	// bl 0x821bbea8
	ctx.lr = 0x826C566C;
	sub_821BBEA8(ctx, base);
loc_826C566C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27196(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27196);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5684
	if (cr6.eq) goto loc_826C5684;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5684;
	sub_821BFA90(ctx, base);
loc_826C5684:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5690
	if (cr6.eq) goto loc_826C5690;
	// bl 0x821bbf00
	ctx.lr = 0x826C5690;
	sub_821BBF00(ctx, base);
loc_826C5690:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c56ac
	if (cr6.eq) goto loc_826C56AC;
	// bl 0x821bbea8
	ctx.lr = 0x826C56AC;
	sub_821BBEA8(ctx, base);
loc_826C56AC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27200(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27200);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c56c4
	if (cr6.eq) goto loc_826C56C4;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C56C4;
	sub_821BFA90(ctx, base);
loc_826C56C4:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c56d0
	if (cr6.eq) goto loc_826C56D0;
	// bl 0x821bbf00
	ctx.lr = 0x826C56D0;
	sub_821BBF00(ctx, base);
loc_826C56D0:
	// lwz r11,2828(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// lwz r10,40(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 40);
	// rlwinm r11,r10,15,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 15) & 0x1;
	// mr r30,r11
	r30.u64 = r11.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c56ec
	if (cr6.eq) goto loc_826C56EC;
	// bl 0x821bbea8
	ctx.lr = 0x826C56EC;
	sub_821BBEA8(ctx, base);
loc_826C56EC:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r4,-27204(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + -27204);
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c5704
	if (cr6.eq) goto loc_826C5704;
	// lwz r3,2828(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 2828);
	// bl 0x821bfa90
	ctx.lr = 0x826C5704;
	sub_821BFA90(ctx, base);
loc_826C5704:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c5710
	if (cr6.eq) goto loc_826C5710;
	// bl 0x821bbf00
	ctx.lr = 0x826C5710;
	sub_821BBF00(ctx, base);
loc_826C5710:
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

PPC_WEAK_FUNC(sub_826C4FF8) {
	__imp__sub_826C4FF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5728) {
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
	ctx.lr = 0x826C5730;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826ed200
	ctx.lr = 0x826C5740;
	sub_826ED200(ctx, base);
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c57e4
	if (cr6.eq) goto loc_826C57E4;
	// li r29,0
	r29.s64 = 0;
	// lis r27,-32121
	r27.s64 = -2105081856;
loc_826C5758:
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r11,-10004(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + -10004);
	// lwzx r3,r29,r10
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + ctx.r10.u32);
	// lwz r4,52(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x826c67f8
	ctx.lr = 0x826C5770;
	sub_826C67F8(ctx, base);
	// lwz r9,28(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r4,r29,r9
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + ctx.r9.u32);
	// bl 0x826c68d8
	ctx.lr = 0x826C5780;
	sub_826C68D8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x826c4608
	ctx.lr = 0x826C578C;
	sub_826C4608(ctx, base);
	// lwz r8,28(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r30,r29,r8
	r30.u64 = PPC_LOAD_U32(r29.u32 + ctx.r8.u32);
	// lwz r28,20(r31)
	r28.u64 = PPC_LOAD_U32(r31.u32 + 20);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c57d0
	if (cr6.eq) goto loc_826C57D0;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C57B8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,12(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 12);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// lhz r11,6(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 6);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r30,12(r28)
	PPC_STORE_U32(r28.u32 + 12, r30.u32);
	// sth r8,6(r28)
	PPC_STORE_U16(r28.u32 + 6, ctx.r8.u16);
loc_826C57D0:
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r26,r26,1
	r26.s64 = r26.s64 + 1;
	// addi r29,r29,4
	r29.s64 = r29.s64 + 4;
	// cmpw cr6,r26,r11
	cr6.compare<int32_t>(r26.s32, r11.s32, xer);
	// blt cr6,0x826c5758
	if (cr6.lt) goto loc_826C5758;
loc_826C57E4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826C5728) {
	__imp__sub_826C5728(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C57EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C57EC) {
	__imp__sub_826C57EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C57F0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister f0{};
	PPCRegister temp{};
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	f0.f64 = double(temp.f32);
	// stfs f0,84(r11)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r11.u32 + 84, temp.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C57F0) {
	__imp__sub_826C57F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5810) {
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
	// bl 0x826c44a8
	ctx.lr = 0x826C5830;
	sub_826C44A8(ctx, base);
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

PPC_WEAK_FUNC(sub_826C5810) {
	__imp__sub_826C5810(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5850) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826ed200
	ctx.lr = 0x826C586C;
	sub_826ED200(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821c9790
	ctx.lr = 0x826C5878;
	sub_821C9790(ctx, base);
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// lwz r31,24(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x82618670
	ctx.lr = 0x826C5890;
	sub_82618670(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// and r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 & ctx.r10.u64;
	// bl 0x826c3e38
	ctx.lr = 0x826C58AC;
	sub_826C3E38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c58cc
	if (cr6.eq) goto loc_826C58CC;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
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
loc_826C58CC:
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

PPC_WEAK_FUNC(sub_826C5850) {
	__imp__sub_826C5850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C58E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C58E4) {
	__imp__sub_826C58E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C58E8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// bl 0x826ed200
	ctx.lr = 0x826C5904;
	sub_826ED200(ctx, base);
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r11,-10004(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// lwz r31,24(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 24);
	// bl 0x82618670
	ctx.lr = 0x826C591C;
	sub_82618670(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// and r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 & ctx.r10.u64;
	// bl 0x826c3e38
	ctx.lr = 0x826C5938;
	sub_826C3E38(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5958
	if (cr6.eq) goto loc_826C5958;
	// lwz r3,4(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
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
loc_826C5958:
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

PPC_WEAK_FUNC(sub_826C58E8) {
	__imp__sub_826C58E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5970) {
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
	ctx.lr = 0x826C5978;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c59ac
	if (cr6.eq) goto loc_826C59AC;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x826C5998;
	sub_82130588(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c59ac
	if (cr6.eq) goto loc_826C59AC;
	// addi r3,r11,-4
	ctx.r3.s64 = r11.s64 + -4;
	// bl 0x82130588
	ctx.lr = 0x826C59AC;
	sub_82130588(ctx, base);
loc_826C59AC:
	// rlwinm r11,r29,31,1,31
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 31) & 0x7FFFFFFF;
	// lis r10,16383
	ctx.r10.s64 = 1073676288;
	// add r11,r11,r29
	r11.u64 = r11.u64 + r29.u64;
	// ori r9,r10,65535
	ctx.r9.u64 = ctx.r10.u64 | 65535;
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 31) & 0x7FFFFFFF;
	// li r30,-1
	r30.s64 = -1;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | r11.u64;
	// rlwinm r6,r7,30,2,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 30) & 0x3FFFFFFF;
	// or r5,r6,r7
	ctx.r5.u64 = ctx.r6.u64 | ctx.r7.u64;
	// rlwinm r4,r5,28,4,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	// or r3,r4,r5
	ctx.r3.u64 = ctx.r4.u64 | ctx.r5.u64;
	// rlwinm r11,r3,24,8,31
	r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// or r10,r11,r3
	ctx.r10.u64 = r11.u64 | ctx.r3.u64;
	// rlwinm r8,r10,16,16,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF;
	// or r11,r8,r10
	r11.u64 = ctx.r8.u64 | ctx.r10.u64;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// cmplw cr6,r11,r9
	cr6.compare<uint32_t>(r11.u32, ctx.r9.u32, xer);
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ble cr6,0x826c5a00
	if (!cr6.gt) goto loc_826C5A00;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826C5A00:
	// bl 0x82130528
	ctx.lr = 0x826C5A04;
	sub_82130528(ctx, base);
	// lis r11,5461
	r11.s64 = 357892096;
	// stw r3,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r3.u32);
	// ori r10,r11,21845
	ctx.r10.u64 = r11.u64 | 21845;
	// cmplw cr6,r29,r10
	cr6.compare<uint32_t>(r29.u32, ctx.r10.u32, xer);
	// bgt cr6,0x826c5a34
	if (cr6.gt) goto loc_826C5A34;
	// rlwinm r11,r29,1,0,30
	r11.u64 = __builtin_rotateleft64(r29.u32 | (r29.u64 << 32), 1) & 0xFFFFFFFE;
	// li r10,-5
	ctx.r10.s64 = -5;
	// add r9,r29,r11
	ctx.r9.u64 = r29.u64 + r11.u64;
	// rlwinm r11,r9,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// ble cr6,0x826c5a38
	if (!cr6.gt) goto loc_826C5A38;
loc_826C5A34:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826C5A38:
	// bl 0x82130528
	ctx.lr = 0x826C5A3C;
	sub_82130528(ctx, base);
	// li r26,0
	r26.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5a78
	if (cr6.eq) goto loc_826C5A78;
	// addi r27,r3,4
	r27.s64 = ctx.r3.s64 + 4;
	// stw r29,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r29.u32);
	// addic. r30,r29,-1
	xer.ca = r29.u32 > 0;
	r30.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// mr r28,r27
	r28.u64 = r27.u64;
	// blt 0x826c5a70
	if (cr0.lt) goto loc_826C5A70;
loc_826C5A5C:
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826ed200
	ctx.lr = 0x826C5A64;
	sub_826ED200(ctx, base);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r28,r28,12
	r28.s64 = r28.s64 + 12;
	// bge 0x826c5a5c
	if (!cr0.lt) goto loc_826C5A5C;
loc_826C5A70:
	// mr r10,r27
	ctx.r10.u64 = r27.u64;
	// b 0x826c5a7c
	goto loc_826C5A7C;
loc_826C5A78:
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
loc_826C5A7C:
	// addic. r11,r29,-1
	xer.ca = r29.u32 > 0;
	r11.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stw r26,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r26.u32);
	// mr r8,r26
	ctx.r8.u64 = r26.u64;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// beq 0x826c5ab8
	if (cr0.eq) goto loc_826C5AB8;
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_826C5A9C:
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,12
	ctx.r10.s64 = ctx.r10.s64 + 12;
	// addi r7,r9,12
	ctx.r7.s64 = ctx.r9.s64 + 12;
	// stw r7,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r7.u32);
	// bne 0x826c5a9c
	if (!cr0.eq) goto loc_826C5A9C;
loc_826C5AB8:
	// rlwinm r11,r8,1,0,30
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// li r4,0
	ctx.r4.s64 = 0;
	// add r11,r8,r11
	r11.u64 = ctx.r8.u64 + r11.u64;
	// rlwinm r11,r11,2,0,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = r11.u64 + ctx.r10.u64;
	// stw r26,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, r26.u32);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x823d9890
	ctx.lr = 0x826C5AE4;
	sub_823D9890(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826C5970) {
	__imp__sub_826C5970(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5AEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C5AEC) {
	__imp__sub_826C5AEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5AF0) {
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
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f0
	ctx.lr = 0x826C5AF8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// addi r6,r11,-8064
	ctx.r6.s64 = r11.s64 + -8064;
	// addi r11,r7,-8280
	r11.s64 = ctx.r7.s64 + -8280;
	// addi r5,r10,-8272
	ctx.r5.s64 = ctx.r10.s64 + -8272;
	// stw r6,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r6.u32);
	// li r26,2
	r26.s64 = 2;
	// stw r11,4(r29)
	PPC_STORE_U32(r29.u32 + 4, r11.u32);
	// addi r4,r9,-26208
	ctx.r4.s64 = ctx.r9.s64 + -26208;
	// stw r5,8(r29)
	PPC_STORE_U32(r29.u32 + 8, ctx.r5.u32);
	// addi r3,r8,-26216
	ctx.r3.s64 = ctx.r8.s64 + -26216;
	// addi r31,r29,28
	r31.s64 = r29.s64 + 28;
	// stw r4,12(r29)
	PPC_STORE_U32(r29.u32 + 12, ctx.r4.u32);
	// stw r3,16(r29)
	PPC_STORE_U32(r29.u32 + 16, ctx.r3.u32);
	// mr r10,r26
	ctx.r10.u64 = r26.u64;
	// mr r11,r31
	r11.u64 = r31.u64;
	// li r27,0
	r27.s64 = 0;
loc_826C5B50:
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// sth r27,4(r11)
	PPC_STORE_U16(r11.u32 + 4, r27.u16);
	// sth r27,6(r11)
	PPC_STORE_U16(r11.u32 + 6, r27.u16);
	// addi r11,r11,8
	r11.s64 = r11.s64 + 8;
	// bge 0x826c5b50
	if (!cr0.lt) goto loc_826C5B50;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// stw r27,80(r29)
	PPC_STORE_U32(r29.u32 + 80, r27.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// li r30,3
	r30.s64 = 3;
	// li r28,160
	r28.s64 = 160;
	// lfs f13,3796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 3796);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12880(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 12880);
	f0.f64 = double(temp.f32);
	// lfs f12,-12988(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + -12988);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,76(r29)
	temp.f32 = float(ctx.f13.f64);
	PPC_STORE_U32(r29.u32 + 76, temp.u32);
	// stfs f0,84(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 84, temp.u32);
	// stfs f12,88(r29)
	temp.f32 = float(ctx.f12.f64);
	PPC_STORE_U32(r29.u32 + 88, temp.u32);
	// stfs f0,92(r29)
	temp.f32 = float(f0.f64);
	PPC_STORE_U32(r29.u32 + 92, temp.u32);
loc_826C5B9C:
	// li r3,640
	ctx.r3.s64 = 640;
	// bl 0x82130528
	ctx.lr = 0x826C5BA4;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// sth r28,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r28.u16);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,8
	r31.s64 = r31.s64 + 8;
	// bne 0x826c5b9c
	if (!cr0.eq) goto loc_826C5B9C;
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826C5BC0;
	sub_82130528(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r30,1
	r30.s64 = 1;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c5c54
	if (cr6.eq) goto loc_826C5C54;
	// li r11,752
	r11.s64 = 752;
	// stw r27,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r27.u32);
	// sth r27,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r27.u16);
	// lis r3,1
	ctx.r3.s64 = 65536;
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// stw r27,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r27.u32);
	// ori r3,r3,54784
	ctx.r3.u64 = ctx.r3.u64 | 54784;
	// stb r27,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r27.u8);
	// sth r28,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r28.u16);
	// bl 0x82130528
	ctx.lr = 0x826C5BF8;
	sub_82130528(ctx, base);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lhz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// ori r10,r8,65535
	ctx.r10.u64 = ctx.r8.u64 | 65535;
	// stb r30,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r30.u8);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// add r6,r9,r10
	ctx.r6.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r11,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r11.u32);
	// clrlwi r8,r6,16
	ctx.r8.u64 = ctx.r6.u32 & 0xFFFF;
	// sth r9,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r9.u16);
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826c5c4c
	if (cr6.eq) goto loc_826C5C4C;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
loc_826C5C2C:
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r7,r9,r11
	ctx.r7.u64 = ctx.r9.u64 + r11.u64;
	// clrlwi r8,r8,16
	ctx.r8.u64 = ctx.r8.u32 & 0xFFFF;
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826c5c2c
	if (!cr6.eq) goto loc_826C5C2C;
loc_826C5C4C:
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// b 0x826c5c58
	goto loc_826C5C58;
loc_826C5C54:
	// mr r31,r27
	r31.u64 = r27.u64;
loc_826C5C58:
	// stw r31,20(r29)
	PPC_STORE_U32(r29.u32 + 20, r31.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826C5C64;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5c88
	if (cr6.eq) goto loc_826C5C88;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// addi r9,r10,-8424
	ctx.r9.s64 = ctx.r10.s64 + -8424;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x826c5c8c
	goto loc_826C5C8C;
loc_826C5C88:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_826C5C8C:
	// stw r11,52(r29)
	PPC_STORE_U32(r29.u32 + 52, r11.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826C5C98;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5cbc
	if (cr6.eq) goto loc_826C5CBC;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r30,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r30.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r26,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r26.u32);
	// addi r9,r10,-8400
	ctx.r9.s64 = ctx.r10.s64 + -8400;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x826c5cc0
	goto loc_826C5CC0;
loc_826C5CBC:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_826C5CC0:
	// stw r11,56(r29)
	PPC_STORE_U32(r29.u32 + 56, r11.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826C5CCC;
	sub_82130528(ctx, base);
	// li r31,4
	r31.s64 = 4;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5cf4
	if (cr6.eq) goto loc_826C5CF4;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r26,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r26.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r31.u32);
	// addi r9,r10,-8376
	ctx.r9.s64 = ctx.r10.s64 + -8376;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x826c5cf8
	goto loc_826C5CF8;
loc_826C5CF4:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_826C5CF8:
	// stw r11,60(r29)
	PPC_STORE_U32(r29.u32 + 60, r11.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826C5D04;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5d30
	if (cr6.eq) goto loc_826C5D30;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,8
	ctx.r10.s64 = 8;
	// addi r9,r11,-8352
	ctx.r9.s64 = r11.s64 + -8352;
	// li r8,3
	ctx.r8.s64 = 3;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// b 0x826c5d34
	goto loc_826C5D34;
loc_826C5D30:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_826C5D34:
	// stw r11,64(r29)
	PPC_STORE_U32(r29.u32 + 64, r11.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826C5D40;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5d68
	if (cr6.eq) goto loc_826C5D68;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// stw r31,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r31.u32);
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r11,-8328
	ctx.r9.s64 = r11.s64 + -8328;
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// b 0x826c5d6c
	goto loc_826C5D6C;
loc_826C5D68:
	// mr r11,r27
	r11.u64 = r27.u64;
loc_826C5D6C:
	// stw r11,68(r29)
	PPC_STORE_U32(r29.u32 + 68, r11.u32);
	// li r3,12
	ctx.r3.s64 = 12;
	// bl 0x82130528
	ctx.lr = 0x826C5D78;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5da0
	if (cr6.eq) goto loc_826C5DA0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,5
	ctx.r10.s64 = 5;
	// addi r9,r11,-8304
	ctx.r9.s64 = r11.s64 + -8304;
	// li r8,32
	ctx.r8.s64 = 32;
	// stw r10,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r8.u32);
loc_826C5DA0:
	// stw r27,72(r29)
	PPC_STORE_U32(r29.u32 + 72, r27.u32);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c4af8
	ctx.lr = 0x826C5DAC;
	sub_826C4AF8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826C5AF0) {
	__imp__sub_826C5AF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5DB8) {
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
	ctx.lr = 0x826C5DC0;
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// mr r28,r6
	r28.u64 = ctx.r6.u64;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r11,r11,r29
	r11.u64 = PPC_LOAD_U32(r11.u32 + r29.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826c5e84
	if (!cr6.gt) goto loc_826C5E84;
	// mr r25,r11
	r25.u64 = r11.u64;
	// lis r11,0
	r11.s64 = 0;
	// ori r27,r11,65535
	r27.u64 = r11.u64 | 65535;
loc_826C5DF8:
	// lwz r30,0(r31)
	r30.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,128
	ctx.r5.s64 = 128;
	// add r4,r30,r29
	ctx.r4.u64 = r30.u64 + r29.u64;
	// bl 0x823da950
	ctx.lr = 0x826C5E0C;
	sub_823DA950(ctx, base);
	// addi r11,r30,128
	r11.s64 = r30.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// bl 0x826c5850
	ctx.lr = 0x826C5E1C;
	sub_826C5850(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// bne cr6,0x826c5e6c
	if (!cr6.eq) goto loc_826C5E6C;
	// lwz r11,20(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 20);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// add r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 + r27.u64;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// sth r9,6(r11)
	PPC_STORE_U16(r11.u32 + 6, ctx.r9.u16);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// beq cr6,0x826c5e54
	if (cr6.eq) goto loc_826C5E54;
	// bl 0x826c7b90
	ctx.lr = 0x826C5E4C;
	sub_826C7B90(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// b 0x826c5e58
	goto loc_826C5E58;
loc_826C5E54:
	// li r30,0
	r30.s64 = 0;
loc_826C5E58:
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r30,72
	ctx.r3.s64 = r30.s64 + 72;
	// bl 0x823db670
	ctx.lr = 0x826C5E68;
	sub_823DB670(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826C5E6C:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// bl 0x826c7530
	ctx.lr = 0x826C5E7C;
	sub_826C7530(ctx, base);
	// addic. r25,r25,-1
	xer.ca = r25.u32 > 0;
	r25.s64 = r25.s64 + -1;
	cr0.compare<int32_t>(r25.s32, 0, xer);
	// bne 0x826c5df8
	if (!cr0.eq) goto loc_826C5DF8;
loc_826C5E84:
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826c4388
	ctx.lr = 0x826C5E8C;
	sub_826C4388(ctx, base);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_826C5DB8) {
	__imp__sub_826C5DB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5E94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C5E94) {
	__imp__sub_826C5E94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5E98) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r4,652(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 652);
	// bl 0x826c58e8
	ctx.lr = 0x826C5EBC;
	sub_826C58E8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c5ed8
	if (cr6.eq) goto loc_826C5ED8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r30,72
	ctx.r4.s64 = r30.s64 + 72;
	// addi r3,r11,-8056
	ctx.r3.s64 = r11.s64 + -8056;
	// bl 0x82130000
	ctx.lr = 0x826C5ED4;
	sub_82130000(ctx, base);
	// b 0x826c5f20
	goto loc_826C5F20;
loc_826C5ED8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826ed200
	ctx.lr = 0x826C5EE0;
	sub_826ED200(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826c68d8
	ctx.lr = 0x826C5EEC;
	sub_826C68D8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// bl 0x826c3da8
	ctx.lr = 0x826C5EF8;
	sub_826C3DA8(ctx, base);
	// addi r11,r31,28
	r11.s64 = r31.s64 + 28;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// rotlwi r9,r11,2
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 2);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// sth r8,32(r31)
	PPC_STORE_U16(r31.u32 + 32, ctx.r8.u16);
	// stwx r30,r9,r10
	PPC_STORE_U32(ctx.r9.u32 + ctx.r10.u32, r30.u32);
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r6,r11,-1
	ctx.r6.s64 = r11.s64 + -1;
	// stw r6,696(r30)
	PPC_STORE_U32(r30.u32 + 696, ctx.r6.u32);
loc_826C5F20:
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

PPC_WEAK_FUNC(sub_826C5E98) {
	__imp__sub_826C5E98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5F38) {
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
	// bl 0x826c5850
	ctx.lr = 0x826C5F58;
	sub_826C5850(ctx, base);
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

PPC_WEAK_FUNC(sub_826C5F38) {
	__imp__sub_826C5F38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5F74) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C5F74) {
	__imp__sub_826C5F74(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C5F78) {
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
	// lwz r10,-10004(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c5fe0
	if (cr6.eq) goto loc_826C5FE0;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// rlwinm r11,r8,3,0,28
	r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// addi r10,r11,28
	ctx.r10.s64 = r11.s64 + 28;
	// lhz r11,32(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826c5fc4
	if (!cr6.gt) goto loc_826C5FC4;
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
loc_826C5FC4:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// stw r9,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r9.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826C5FE0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-7952
	ctx.r3.s64 = r11.s64 + -7952;
	// bl 0x82130000
	ctx.lr = 0x826C5FEC;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_826C5F78) {
	__imp__sub_826C5F78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C600C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C600C) {
	__imp__sub_826C600C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6010) {
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
	ctx.lr = 0x826C6018;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r9,r28,28
	ctx.r9.s64 = r28.s64 + 28;
	// addi r10,r11,-8064
	ctx.r10.s64 = r11.s64 + -8064;
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r10,0(r28)
	PPC_STORE_U32(r28.u32 + 0, ctx.r10.u32);
loc_826C6034:
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
	// beq cr6,0x826c606c
	if (cr6.eq) goto loc_826C606C;
	// subf r6,r11,r8
	ctx.r6.s64 = ctx.r8.s64 - r11.s64;
loc_826C6058:
	// lwz r4,0(r10)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r4,r6,r10
	PPC_STORE_U32(ctx.r6.u32 + ctx.r10.u32, ctx.r4.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826c6058
	if (!cr6.eq) goto loc_826C6058;
loc_826C606C:
	// subf r11,r8,r11
	r11.s64 = r11.s64 - ctx.r8.s64;
	// lhz r10,0(r7)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r7.u32 + 0);
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
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
	// bne 0x826c6034
	if (!cr0.eq) goto loc_826C6034;
	// lwz r31,20(r28)
	r31.u64 = PPC_LOAD_U32(r28.u32 + 20);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c60d0
	if (cr6.eq) goto loc_826C60D0;
	// lbz r11,16(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c60b0
	if (cr6.eq) goto loc_826C60B0;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826C60B0;
	sub_82130588(ctx, base);
loc_826C60B0:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// sth r29,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r29.u16);
	// sth r29,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r29.u16);
	// stw r29,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r29.u32);
	// stb r29,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r29.u8);
	// bl 0x82130588
	ctx.lr = 0x826C60CC;
	sub_82130588(ctx, base);
	// stw r29,20(r28)
	PPC_STORE_U32(r28.u32 + 20, r29.u32);
loc_826C60D0:
	// addi r31,r28,52
	r31.s64 = r28.s64 + 52;
	// li r30,6
	r30.s64 = 6;
loc_826C60D8:
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c60f8
	if (cr6.eq) goto loc_826C60F8;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C60F8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826C60F8:
	// stw r29,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r29.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// bne 0x826c60d8
	if (!cr0.eq) goto loc_826C60D8;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x826c4ff8
	ctx.lr = 0x826C6110;
	sub_826C4FF8(ctx, base);
	// addi r31,r28,52
	r31.s64 = r28.s64 + 52;
	// li r30,2
	r30.s64 = 2;
loc_826C6118:
	// addi r31,r31,-8
	r31.s64 = r31.s64 + -8;
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6130
	if (cr6.eq) goto loc_826C6130;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826C6130;
	sub_82130588(ctx, base);
loc_826C6130:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// bge 0x826c6118
	if (!cr0.lt) goto loc_826C6118;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// addi r10,r11,-21856
	ctx.r10.s64 = r11.s64 + -21856;
	// stw r10,4(r28)
	PPC_STORE_U32(r28.u32 + 4, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826C614C;
	sub_821D2028(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C6010) {
	__imp__sub_826C6010(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6154) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C6154) {
	__imp__sub_826C6154(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6158) {
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
	// bl 0x826c5728
	ctx.lr = 0x826C6170;
	sub_826C5728(ctx, base);
	// lwz r31,24(r31)
	r31.u64 = PPC_LOAD_U32(r31.u32 + 24);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c61ac
	if (cr6.eq) goto loc_826C61AC;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c61a4
	if (cr6.eq) goto loc_826C61A4;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x82130588
	ctx.lr = 0x826C6190;
	sub_82130588(ctx, base);
	// lwz r11,16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c61a4
	if (cr6.eq) goto loc_826C61A4;
	// addi r3,r11,-4
	ctx.r3.s64 = r11.s64 + -4;
	// bl 0x82130588
	ctx.lr = 0x826C61A4;
	sub_82130588(ctx, base);
loc_826C61A4:
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82130588
	ctx.lr = 0x826C61AC;
	sub_82130588(ctx, base);
loc_826C61AC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C6158) {
	__imp__sub_826C6158(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C61C0) {
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
	ctx.lr = 0x826C61C8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// lwz r11,20(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 20);
	// lwz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// lhz r10,6(r11)
	ctx.r10.u64 = PPC_LOAD_U16(r11.u32 + 6);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// addis r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 65536;
	// lwz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// sth r9,6(r11)
	PPC_STORE_U16(r11.u32 + 6, ctx.r9.u16);
	// stw r8,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r8.u32);
	// beq cr6,0x826c6208
	if (cr6.eq) goto loc_826C6208;
	// bl 0x826c7b90
	ctx.lr = 0x826C6200;
	sub_826C7B90(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// b 0x826c620c
	goto loc_826C620C;
loc_826C6208:
	// li r31,0
	r31.s64 = 0;
loc_826C620C:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lwz r30,2828(r11)
	r30.u64 = PPC_LOAD_U32(r11.u32 + 2828);
	// beq cr6,0x826c6238
	if (cr6.eq) goto loc_826C6238;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C6230;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// b 0x826c6240
	goto loc_826C6240;
loc_826C6238:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r6,-27224(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + -27224);
loc_826C6240:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r5,r11,5276
	ctx.r5.s64 = r11.s64 + 5276;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x821c04b0
	ctx.lr = 0x826C625C;
	sub_821C04B0(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c5e98
	ctx.lr = 0x826C6268;
	sub_826C5E98(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C61C0) {
	__imp__sub_826C61C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6270) {
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
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,24376
	ctx.r4.s64 = r11.s64 + 24376;
	// addi r3,r10,-7744
	ctx.r3.s64 = ctx.r10.s64 + -7744;
	// bl 0x82554798
	ctx.lr = 0x826C6290;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,22512
	ctx.r4.s64 = ctx.r9.s64 + 22512;
	// addi r3,r8,-7784
	ctx.r3.s64 = ctx.r8.s64 + -7784;
	// bl 0x82554798
	ctx.lr = 0x826C62A4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,22544
	ctx.r4.s64 = ctx.r7.s64 + 22544;
	// addi r3,r6,-7828
	ctx.r3.s64 = ctx.r6.s64 + -7828;
	// bl 0x82554798
	ctx.lr = 0x826C62B8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,24440
	ctx.r4.s64 = ctx.r5.s64 + 24440;
	// addi r3,r3,-7860
	ctx.r3.s64 = ctx.r3.s64 + -7860;
	// bl 0x82554798
	ctx.lr = 0x826C62CC;
	sub_82554798(ctx, base);
	// bl 0x826c82b0
	ctx.lr = 0x826C62D0;
	sub_826C82B0(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C6270) {
	__imp__sub_826C6270(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C62E0) {
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
	// bl 0x826c6010
	ctx.lr = 0x826C6300;
	sub_826C6010(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6318
	if (cr6.eq) goto loc_826C6318;
	// bl 0x82130588
	ctx.lr = 0x826C6314;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826C6318:
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

PPC_WEAK_FUNC(sub_826C62E0) {
	__imp__sub_826C62E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6330) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
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
	ctx.lr = 0x826C6338;
	// stwu r1,-896(r1)
	ea = -896 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32131
	r11.s64 = -2105737216;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r29,r11,30576
	r29.s64 = r11.s64 + 30576;
	// mr r18,r3
	r18.u64 = ctx.r3.u64;
	// addi r4,r10,-16884
	ctx.r4.s64 = ctx.r10.s64 + -16884;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x826C6358;
	sub_821CA540(ctx, base);
	// lis r30,-32129
	r30.s64 = -2105606144;
	// lis r31,-32255
	r31.s64 = -2113863680;
	// lis r3,-32255
	ctx.r3.s64 = -2113863680;
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// lis r5,-32255
	ctx.r5.s64 = -2113863680;
	// lis r6,-32251
	ctx.r6.s64 = -2113601536;
	// lis r7,-32244
	ctx.r7.s64 = -2113142784;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r19,r30,-28304
	r19.s64 = r30.s64 + -28304;
	// li r17,0
	r17.s64 = 0;
	// addi r25,r31,-30140
	r25.s64 = r31.s64 + -30140;
	// addi r28,r3,-29628
	r28.s64 = ctx.r3.s64 + -29628;
	// addi r27,r4,9848
	r27.s64 = ctx.r4.s64 + 9848;
	// addi r26,r5,-29624
	r26.s64 = ctx.r5.s64 + -29624;
	// addi r30,r6,-4872
	r30.s64 = ctx.r6.s64 + -4872;
	// addi r24,r7,-7680
	r24.s64 = ctx.r7.s64 + -7680;
	// addi r23,r8,-7692
	r23.s64 = ctx.r8.s64 + -7692;
	// addi r22,r9,-7704
	r22.s64 = ctx.r9.s64 + -7704;
	// addi r21,r10,-32764
	r21.s64 = ctx.r10.s64 + -32764;
	// addi r20,r11,-7716
	r20.s64 = r11.s64 + -7716;
loc_826C63B4:
	// mr r5,r20
	ctx.r5.u64 = r20.u64;
	// mr r6,r17
	ctx.r6.u64 = r17.u64;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x82137a08
	ctx.lr = 0x826C63C8;
	sub_82137A08(ctx, base);
	// mr r5,r21
	ctx.r5.u64 = r21.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x821ca6a8
	ctx.lr = 0x826C63E0;
	sub_821CA6A8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c6514
	if (cr6.eq) goto loc_826C6514;
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821ca540
	ctx.lr = 0x826C63F8;
	sub_821CA540(ctx, base);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d1cd0
	ctx.lr = 0x826C6400;
	sub_821D1CD0(ctx, base);
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cf7b8
	ctx.lr = 0x826C6410;
	sub_821CF7B8(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cff40
	ctx.lr = 0x826C6420;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c645c
	if (cr6.eq) goto loc_826C645C;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0490
	ctx.lr = 0x826C6438;
	sub_821D0490(ctx, base);
	// lwz r11,4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// and r11,r11,r3
	r11.u64 = r11.u64 & ctx.r3.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c6488
	if (!cr6.eq) goto loc_826C6488;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x826C6450;
	sub_821BE610(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826C6458;
	sub_821C9A90(ctx, base);
	// b 0x826c6510
	goto loc_826C6510;
loc_826C645C:
	// cmpwi cr6,r17,1
	cr6.compare<int32_t>(r17.s32, 1, xer);
	// bne cr6,0x826c6488
	if (!cr6.eq) goto loc_826C6488;
	// lwz r11,4(r19)
	r11.u64 = PPC_LOAD_U32(r19.u32 + 4);
	// rlwinm r11,r11,0,29,29
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c6488
	if (!cr6.eq) goto loc_826C6488;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x826C647C;
	sub_821BE610(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826C6484;
	sub_821C9A90(ctx, base);
	// b 0x826c6510
	goto loc_826C6510;
loc_826C6488:
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cff40
	ctx.lr = 0x826C6498;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6500
	if (cr6.eq) goto loc_826C6500;
loc_826C64A4:
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x826C64B0;
	sub_821D0898(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfe20
	ctx.lr = 0x826C64BC;
	sub_821CFE20(ctx, base);
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cfaa8
	ctx.lr = 0x826C64CC;
	sub_821CFAA8(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x826c61c0
	ctx.lr = 0x826C64D8;
	sub_826C61C0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821d0898
	ctx.lr = 0x826C64E4;
	sub_821D0898(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x821cff40
	ctx.lr = 0x826C64F4;
	sub_821CFF40(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c64a4
	if (!cr6.eq) goto loc_826C64A4;
loc_826C6500:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826C6508;
	sub_821C9A90(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x821be610
	ctx.lr = 0x826C6510;
	sub_821BE610(ctx, base);
loc_826C6510:
	// stw r25,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, r25.u32);
loc_826C6514:
	// addi r17,r17,1
	r17.s64 = r17.s64 + 1;
	// cmpwi cr6,r17,5
	cr6.compare<int32_t>(r17.s32, 5, xer);
	// blt cr6,0x826c63b4
	if (cr6.lt) goto loc_826C63B4;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x821c9a90
	ctx.lr = 0x826C6528;
	sub_821C9A90(ctx, base);
	// lhz r11,32(r18)
	r11.u64 = PPC_LOAD_U16(r18.u32 + 32);
	// li r31,0
	r31.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c655c
	if (cr6.eq) goto loc_826C655C;
	// li r30,0
	r30.s64 = 0;
loc_826C653C:
	// lwz r11,28(r18)
	r11.u64 = PPC_LOAD_U32(r18.u32 + 28);
	// lwzx r3,r30,r11
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + r11.u32);
	// bl 0x826c6b38
	ctx.lr = 0x826C6548;
	sub_826C6B38(ctx, base);
	// lhz r10,32(r18)
	ctx.r10.u64 = PPC_LOAD_U16(r18.u32 + 32);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r31,r10
	cr6.compare<int32_t>(r31.s32, ctx.r10.s32, xer);
	// blt cr6,0x826c653c
	if (cr6.lt) goto loc_826C653C;
loc_826C655C:
	// lis r11,-32111
	r11.s64 = -2104426496;
	// addi r10,r11,-27256
	ctx.r10.s64 = r11.s64 + -27256;
	// lwz r11,4(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6578
	if (cr6.eq) goto loc_826C6578;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x826c40d0
	ctx.lr = 0x826C6578;
	sub_826C40D0(ctx, base);
loc_826C6578:
	// addi r1,r1,896
	ctx.r1.s64 = ctx.r1.s64 + 896;
	// b 0x823d921c
	return;
}

PPC_WEAK_FUNC(sub_826C6330) {
	__imp__sub_826C6330(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6580) {
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
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826C659C;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c65bc
	if (cr6.eq) goto loc_826C65BC;
	// li r11,0
	r11.s64 = 0;
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r11.u32);
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, r11.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
	// stw r11,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r11.u32);
	// b 0x826c65c0
	goto loc_826C65C0;
loc_826C65BC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C65C0:
	// stw r3,24(r31)
	PPC_STORE_U32(r31.u32 + 24, ctx.r3.u32);
	// li r4,160
	ctx.r4.s64 = 160;
	// bl 0x826c5970
	ctx.lr = 0x826C65CC;
	sub_826C5970(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6330
	ctx.lr = 0x826C65D4;
	sub_826C6330(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C6580) {
	__imp__sub_826C6580(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C65E8) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,-1
	r11.s64 = ctx.r4.s64 + -1;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bgt cr6,0x826c671c
	if (cr6.gt) goto loc_826C671C;
	// lis r12,-32148
	r12.s64 = -2106851328;
	// addi r12,r12,26144
	r12.s64 = r12.s64 + 26144;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,26376(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 26376);
	// lwz r19,26160(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 26160);
	// lwz r19,26236(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 26236);
	// lwz r19,26296(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + 26296);
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r11,-7660
	ctx.r3.s64 = r11.s64 + -7660;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r10,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// bl 0x82663230
	ctx.lr = 0x826C6648;
	sub_82663230(ctx, base);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c6664
	if (cr6.eq) goto loc_826C6664;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c72d8
	ctx.lr = 0x826C6658;
	sub_826C72D8(ctx, base);
	// lwz r11,80(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r11,r3
	cr6.compare<int32_t>(r11.s32, ctx.r3.s32, xer);
	// beq cr6,0x826c671c
	if (cr6.eq) goto loc_826C671C;
loc_826C6664:
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c66a0
	if (cr6.eq) goto loc_826C66A0;
	// lbz r11,684(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 684);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c66a0
	if (!cr6.eq) goto loc_826C66A0;
	// lbz r11,685(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 685);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c671c
	if (cr6.eq) goto loc_826C671C;
loc_826C66A0:
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c66f0
	if (cr6.eq) goto loc_826C66F0;
	// lbz r11,685(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 685);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c66f0
	if (!cr6.eq) goto loc_826C66F0;
	// lbz r11,691(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 691);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c66e0
	if (cr6.eq) goto loc_826C66E0;
	// lbz r11,690(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 690);
	// b 0x826c66e4
	goto loc_826C66E4;
loc_826C66E0:
	// li r11,0
	r11.s64 = 0;
loc_826C66E4:
	// clrlwi r11,r11,24
	r11.u64 = r11.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c671c
	if (!cr6.eq) goto loc_826C671C;
loc_826C66F0:
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
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c66a0
	if (cr6.eq) goto loc_826C66A0;
	// lbz r11,685(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 685);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c66f0
	if (!cr6.eq) goto loc_826C66F0;
loc_826C671C:
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

PPC_WEAK_FUNC(sub_826C65E8) {
	__imp__sub_826C65E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6734) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C6734) {
	__imp__sub_826C6734(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6738) {
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
	ctx.lr = 0x826C6740;
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r26,r4
	r26.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// mr r24,r6
	r24.u64 = ctx.r6.u64;
	// mr r27,r7
	r27.u64 = ctx.r7.u64;
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// li r28,0
	r28.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c67f0
	if (cr6.eq) goto loc_826C67F0;
	// li r30,0
	r30.s64 = 0;
loc_826C676C:
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r10,r11,r30
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r9,656(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 656);
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// and r7,r8,r26
	ctx.r7.u64 = ctx.r8.u64 & r26.u64;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x826c67dc
	if (cr6.eq) goto loc_826C67DC;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// rotlwi r5,r10,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c65e8
	ctx.lr = 0x826C6798;
	sub_826C65E8(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c67dc
	if (cr6.eq) goto loc_826C67DC;
	// lwz r11,28(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// lwzx r11,r11,r30
	r11.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// addi r3,r11,456
	ctx.r3.s64 = r11.s64 + 456;
	// bl 0x8238e818
	ctx.lr = 0x826C67B4;
	sub_8238E818(ctx, base);
	// cmpw cr6,r27,r3
	cr6.compare<int32_t>(r27.s32, ctx.r3.s32, xer);
	// beq cr6,0x826c67c4
	if (cr6.eq) goto loc_826C67C4;
	// cmpwi cr6,r27,6
	cr6.compare<int32_t>(r27.s32, 6, xer);
	// bne cr6,0x826c67dc
	if (!cr6.eq) goto loc_826C67DC;
loc_826C67C4:
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r29,28(r31)
	r29.u64 = PPC_LOAD_U32(r31.u32 + 28);
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// bl 0x8262e420
	ctx.lr = 0x826C67D4;
	sub_8262E420(ctx, base);
	// lwzx r11,r29,r30
	r11.u64 = PPC_LOAD_U32(r29.u32 + r30.u32);
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r11.u32);
loc_826C67DC:
	// lhz r11,32(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 32);
	// addi r28,r28,1
	r28.s64 = r28.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// blt cr6,0x826c676c
	if (cr6.lt) goto loc_826C676C;
loc_826C67F0:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_826C6738) {
	__imp__sub_826C6738(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C67F8) {
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
	ctx.lr = 0x826C6800;
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
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmplw cr6,r30,r11
	cr6.compare<uint32_t>(r30.u32, r11.u32, xer);
	// beq cr6,0x826c6898
	if (cr6.eq) goto loc_826C6898;
loc_826C681C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C6834;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c6854
	if (cr6.eq) goto loc_826C6854;
	// lwz r11,656(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r11
	cr6.compare<uint32_t>(ctx.r3.u32, r11.u32, xer);
	// bne cr6,0x826c681c
	if (!cr6.eq) goto loc_826C681C;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826C6854:
	// lwz r3,656(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c6878
	if (cr6.eq) goto loc_826C6878;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 16);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C6878;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826C6878:
	// stw r30,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r30.u32);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C6898;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826C6898:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826C67F8) {
	__imp__sub_826C67F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C68A0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c68b4
	if (cr6.eq) goto loc_826C68B4;
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// blr 
	return;
loc_826C68B4:
	// li r3,-1
	ctx.r3.s64 = -1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C68A0) {
	__imp__sub_826C68A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C68BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C68BC) {
	__imp__sub_826C68BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C68C0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// subf r9,r10,r11
	ctx.r9.s64 = r11.s64 - ctx.r10.s64;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r3,r8,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C68C0) {
	__imp__sub_826C68C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C68D8) {
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
	// addi r3,r4,72
	ctx.r3.s64 = ctx.r4.s64 + 72;
	// stw r4,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r4.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x821c9790
	ctx.lr = 0x826C68FC;
	sub_821C9790(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C68D8) {
	__imp__sub_826C68D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6914) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C6914) {
	__imp__sub_826C6914(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6918) {
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
	ctx.lr = 0x826C6920;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r5,0
	cr6.compare<int32_t>(ctx.r5.s32, 0, xer);
	// ble cr6,0x826c695c
	if (!cr6.gt) goto loc_826C695C;
	// mr r31,r29
	r31.u64 = r29.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
loc_826C6938:
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
	ctx.lr = 0x826C6950;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,144
	r31.s64 = r31.s64 + 144;
	// bne 0x826c6938
	if (!cr0.eq) goto loc_826C6938;
loc_826C695C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x82130588
	ctx.lr = 0x826C6964;
	sub_82130588(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826C6918) {
	__imp__sub_826C6918(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C696C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C696C) {
	__imp__sub_826C696C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6970) {
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
	ctx.lr = 0x826C6978;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// rlwinm r11,r30,3,0,28
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x826C6990;
	sub_82130528(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826c69bc
	if (!cr6.gt) goto loc_826C69BC;
	// mr r31,r29
	r31.u64 = r29.u64;
loc_826C69A0:
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c69b0
	if (cr6.eq) goto loc_826C69B0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826cca30
	ctx.lr = 0x826C69B0;
	sub_826CCA30(ctx, base);
loc_826C69B0:
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,144
	r31.s64 = r31.s64 + 144;
	// bne 0x826c69a0
	if (!cr0.eq) goto loc_826C69A0;
loc_826C69BC:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826C6970) {
	__imp__sub_826C6970(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C69C8) {
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
	ctx.lr = 0x826C69D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// addi r4,r31,72
	ctx.r4.s64 = r31.s64 + 72;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// add r3,r11,r29
	ctx.r3.u64 = r11.u64 + r29.u64;
	// bl 0x823da950
	ctx.lr = 0x826C69F4;
	sub_823DA950(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,128
	ctx.r10.s64 = r11.s64 + 128;
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lbz r9,696(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 696);
	// stbx r9,r10,r29
	PPC_STORE_U8(ctx.r10.u32 + r29.u32, ctx.r9.u8);
	// lbz r8,697(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 697);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,698(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 698);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,699(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 699);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lbz r5,700(r31)
	ctx.r5.u64 = PPC_LOAD_U8(r31.u32 + 700);
	// stbx r5,r10,r29
	PPC_STORE_U8(ctx.r10.u32 + r29.u32, ctx.r5.u8);
	// lbz r4,701(r31)
	ctx.r4.u64 = PPC_LOAD_U8(r31.u32 + 701);
	// stb r4,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r4.u8);
	// lbz r3,702(r31)
	ctx.r3.u64 = PPC_LOAD_U8(r31.u32 + 702);
	// stb r3,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r3.u8);
	// lbz r10,703(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 703);
	// stb r10,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r10.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// add r11,r10,r29
	r11.u64 = ctx.r10.u64 + r29.u64;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lbz r9,704(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 704);
	// stbx r9,r10,r29
	PPC_STORE_U8(ctx.r10.u32 + r29.u32, ctx.r9.u8);
	// lbz r8,705(r31)
	ctx.r8.u64 = PPC_LOAD_U8(r31.u32 + 705);
	// stb r8,1(r11)
	PPC_STORE_U8(r11.u32 + 1, ctx.r8.u8);
	// lbz r7,706(r31)
	ctx.r7.u64 = PPC_LOAD_U8(r31.u32 + 706);
	// stb r7,2(r11)
	PPC_STORE_U8(r11.u32 + 2, ctx.r7.u8);
	// lbz r6,707(r31)
	ctx.r6.u64 = PPC_LOAD_U8(r31.u32 + 707);
	// stb r6,3(r11)
	PPC_STORE_U8(r11.u32 + 3, ctx.r6.u8);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// lwz r5,656(r31)
	ctx.r5.u64 = PPC_LOAD_U32(r31.u32 + 656);
	// lwz r4,4(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// stwx r4,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, ctx.r4.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// stw r10,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r10.u32);
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// stwx r11,r10,r29
	PPC_STORE_U32(ctx.r10.u32 + r29.u32, r11.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r10,4
	ctx.r3.s64 = ctx.r10.s64 + 4;
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
	// ble cr6,0x826c6aec
	if (!cr6.gt) goto loc_826C6AEC;
	// li r27,0
	r27.s64 = 0;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_826C6ACC:
	// lwz r11,708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r3,r11,r27
	ctx.r3.u64 = r11.u64 + r27.u64;
	// bl 0x826cc3f8
	ctx.lr = 0x826C6AE0;
	sub_826CC3F8(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,144
	r27.s64 = r27.s64 + 144;
	// bne 0x826c6acc
	if (!cr0.eq) goto loc_826C6ACC;
loc_826C6AEC:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lhz r28,720(r31)
	r28.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// stwx r28,r11,r29
	PPC_STORE_U32(r11.u32 + r29.u32, r28.u32);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r11,0(r30)
	PPC_STORE_U32(r30.u32 + 0, r11.u32);
	// ble cr6,0x826c6b30
	if (!cr6.gt) goto loc_826C6B30;
	// li r27,0
	r27.s64 = 0;
loc_826C6B10:
	// lwz r11,716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 716);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// add r3,r27,r11
	ctx.r3.u64 = r27.u64 + r11.u64;
	// bl 0x826cc3f8
	ctx.lr = 0x826C6B24;
	sub_826CC3F8(ctx, base);
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r27,r27,144
	r27.s64 = r27.s64 + 144;
	// bne 0x826c6b10
	if (!cr0.eq) goto loc_826C6B10;
loc_826C6B30:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826C69C8) {
	__imp__sub_826C69C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6B38) {
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
	ctx.lr = 0x826C6B40;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6b7c
	if (cr6.eq) goto loc_826C6B7C;
	// li r30,0
	r30.s64 = 0;
loc_826C6B5C:
	// lwz r11,708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x826cc238
	ctx.lr = 0x826C6B68;
	sub_826CC238(ctx, base);
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c6b5c
	if (cr6.lt) goto loc_826C6B5C;
loc_826C6B7C:
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6bb0
	if (cr6.eq) goto loc_826C6BB0;
	// li r30,0
	r30.s64 = 0;
loc_826C6B90:
	// lwz r11,716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 716);
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x826cc238
	ctx.lr = 0x826C6B9C;
	sub_826CC238(ctx, base);
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c6b90
	if (cr6.lt) goto loc_826C6B90;
loc_826C6BB0:
	// lhz r11,728(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 728);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6bf0
	if (cr6.eq) goto loc_826C6BF0;
	// li r30,0
	r30.s64 = 0;
loc_826C6BC4:
	// lwz r11,724(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 724);
	// lwzx r3,r11,r30
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + r30.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826C6BDC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lhz r8,728(r31)
	ctx.r8.u64 = PPC_LOAD_U16(r31.u32 + 728);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,4
	r30.s64 = r30.s64 + 4;
	// cmpw cr6,r29,r8
	cr6.compare<int32_t>(r29.s32, ctx.r8.s32, xer);
	// blt cr6,0x826c6bc4
	if (cr6.lt) goto loc_826C6BC4;
loc_826C6BF0:
	// lhz r11,736(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 736);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6c24
	if (cr6.eq) goto loc_826C6C24;
	// li r11,0
	r11.s64 = 0;
loc_826C6C04:
	// lwz r9,732(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 732);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addi r11,r11,4
	r11.s64 = r11.s64 + 4;
	// stw r31,36(r8)
	PPC_STORE_U32(ctx.r8.u32 + 36, r31.u32);
	// lhz r7,736(r31)
	ctx.r7.u64 = PPC_LOAD_U16(r31.u32 + 736);
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x826c6c04
	if (cr6.lt) goto loc_826C6C04;
loc_826C6C24:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826C6C34;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x826c67f8
	ctx.lr = 0x826C6C44;
	sub_826C67F8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826C6B38) {
	__imp__sub_826C6B38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6C4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C6C4C) {
	__imp__sub_826C6C4C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6C50) {
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
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lwz r11,704(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 704);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826c6c90
	if (cr6.eq) goto loc_826C6C90;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10004);
	// li r4,2
	ctx.r4.s64 = 2;
	// bl 0x826c4058
	ctx.lr = 0x826C6C88;
	sub_826C4058(ctx, base);
	// li r11,-1
	r11.s64 = -1;
	// stw r11,704(r31)
	PPC_STORE_U32(r31.u32 + 704, r11.u32);
loc_826C6C90:
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// bne cr6,0x826c6cac
	if (!cr6.eq) goto loc_826C6CAC;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// lwz r3,-10004(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10004);
	// li r4,1
	ctx.r4.s64 = 1;
	// bl 0x826c3f20
	ctx.lr = 0x826C6CAC;
	sub_826C3F20(ctx, base);
loc_826C6CAC:
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

PPC_WEAK_FUNC(sub_826C6C50) {
	__imp__sub_826C6C50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C6CC4) {
	__imp__sub_826C6CC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6CC8) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lwz r11,680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c6d24
	if (!cr6.eq) goto loc_826C6D24;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r7,r31,72
	ctx.r7.s64 = r31.s64 + 72;
	// addi r5,r11,10372
	ctx.r5.s64 = r11.s64 + 10372;
	// addi r6,r31,40
	ctx.r6.s64 = r31.s64 + 40;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826C6D04;
	sub_82137A08(ctx, base);
	// li r8,1500
	ctx.r8.s64 = 1500;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82727908
	ctx.lr = 0x826C6D20;
	sub_82727908(ctx, base);
	// stw r3,680(r31)
	PPC_STORE_U32(r31.u32 + 680, ctx.r3.u32);
loc_826C6D24:
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

PPC_WEAK_FUNC(sub_826C6CC8) {
	__imp__sub_826C6CC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6D38) {
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
	// lbz r11,692(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 692);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c6db8
	if (!cr6.eq) goto loc_826C6DB8;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c6d88
	if (!cr6.eq) goto loc_826C6D88;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-7052
	ctx.r5.s64 = r11.s64 + -7052;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x8268b960
	ctx.lr = 0x826C6D84;
	sub_8268B960(ctx, base);
	// stw r3,660(r31)
	PPC_STORE_U32(r31.u32 + 660, ctx.r3.u32);
loc_826C6D88:
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c6db0
	if (!cr6.eq) goto loc_826C6DB0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// li r6,10
	ctx.r6.s64 = 10;
	// addi r5,r11,-7076
	ctx.r5.s64 = r11.s64 + -7076;
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x8268b960
	ctx.lr = 0x826C6DAC;
	sub_8268B960(ctx, base);
	// stw r3,664(r31)
	PPC_STORE_U32(r31.u32 + 664, ctx.r3.u32);
loc_826C6DB0:
	// li r11,1
	r11.s64 = 1;
	// stb r11,692(r31)
	PPC_STORE_U8(r31.u32 + 692, r11.u8);
loc_826C6DB8:
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

PPC_WEAK_FUNC(sub_826C6D38) {
	__imp__sub_826C6D38(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6DD0) {
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
	ctx.lr = 0x826C6DD8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,736(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 736);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6e48
	if (cr6.eq) goto loc_826C6E48;
	// li r31,0
	r31.s64 = 0;
loc_826C6DF8:
	// lwz r11,732(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 732);
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r3,r11,104
	ctx.r3.s64 = r11.s64 + 104;
	// bl 0x826cd4b8
	ctx.lr = 0x826C6E08;
	sub_826CD4B8(ctx, base);
	// lwz r10,732(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 732);
	// lwzx r11,r10,r31
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,136(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c6e34
	if (!cr6.eq) goto loc_826C6E34;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// beq cr6,0x826c6e2c
	if (cr6.eq) goto loc_826C6E2C;
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// bne cr6,0x826c6e34
	if (!cr6.eq) goto loc_826C6E34;
loc_826C6E2C:
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826d3868
	ctx.lr = 0x826C6E34;
	sub_826D3868(ctx, base);
loc_826C6E34:
	// lhz r11,736(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 736);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c6df8
	if (cr6.lt) goto loc_826C6DF8;
loc_826C6E48:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C6DD0) {
	__imp__sub_826C6DD0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6E50) {
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
	ctx.lr = 0x826C6E58;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lbz r11,692(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 692);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6eb8
	if (cr6.eq) goto loc_826C6EB8;
	// lwz r11,660(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 660);
	// li r29,0
	r29.s64 = 0;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c6e94
	if (!cr6.eq) goto loc_826C6E94;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x8268b6d0
	ctx.lr = 0x826C6E90;
	sub_8268B6D0(ctx, base);
	// stw r29,660(r31)
	PPC_STORE_U32(r31.u32 + 660, r29.u32);
loc_826C6E94:
	// lwz r11,664(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 664);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c6eb4
	if (!cr6.eq) goto loc_826C6EB4;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// addi r4,r31,4
	ctx.r4.s64 = r31.s64 + 4;
	// bl 0x8268b6d0
	ctx.lr = 0x826C6EB0;
	sub_8268B6D0(ctx, base);
	// stw r29,664(r31)
	PPC_STORE_U32(r31.u32 + 664, r29.u32);
loc_826C6EB4:
	// stb r29,692(r31)
	PPC_STORE_U8(r31.u32 + 692, r29.u8);
loc_826C6EB8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826C6E50) {
	__imp__sub_826C6E50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6EC0) {
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
	ctx.lr = 0x826C6EC8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,736(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 736);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6f38
	if (cr6.eq) goto loc_826C6F38;
	// li r31,0
	r31.s64 = 0;
loc_826C6EE8:
	// lwz r11,732(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 732);
	// lwzx r11,r11,r31
	r11.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// addi r3,r11,104
	ctx.r3.s64 = r11.s64 + 104;
	// bl 0x826cd4b8
	ctx.lr = 0x826C6EF8;
	sub_826CD4B8(ctx, base);
	// lwz r10,732(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 732);
	// lwzx r11,r10,r31
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + r31.u32);
	// lwz r9,136(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 136);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c6f24
	if (cr6.eq) goto loc_826C6F24;
	// cmpwi cr6,r3,6
	cr6.compare<int32_t>(ctx.r3.s32, 6, xer);
	// beq cr6,0x826c6f24
	if (cr6.eq) goto loc_826C6F24;
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// bne cr6,0x826c6f24
	if (!cr6.eq) goto loc_826C6F24;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x826d38c0
	ctx.lr = 0x826C6F24;
	sub_826D38C0(ctx, base);
loc_826C6F24:
	// lhz r11,736(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 736);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c6ee8
	if (cr6.lt) goto loc_826C6EE8;
loc_826C6F38:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C6EC0) {
	__imp__sub_826C6EC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6F40) {
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
	ctx.lr = 0x826C6F48;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r29,0
	r29.s64 = 0;
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6f84
	if (cr6.eq) goto loc_826C6F84;
	// li r30,0
	r30.s64 = 0;
loc_826C6F64:
	// lwz r11,708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826cc180
	ctx.lr = 0x826C6F70;
	sub_826CC180(ctx, base);
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c6f64
	if (cr6.lt) goto loc_826C6F64;
loc_826C6F84:
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// li r29,0
	r29.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c6fb8
	if (cr6.eq) goto loc_826C6FB8;
	// li r30,0
	r30.s64 = 0;
loc_826C6F98:
	// lwz r11,716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 716);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826cc180
	ctx.lr = 0x826C6FA4;
	sub_826CC180(ctx, base);
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c6f98
	if (cr6.lt) goto loc_826C6F98;
loc_826C6FB8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826C6F40) {
	__imp__sub_826C6F40(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C6FC0) {
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
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c7000
	if (cr6.eq) goto loc_826C7000;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826C6FF0;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x826c67f8
	ctx.lr = 0x826C7000;
	sub_826C67F8(ctx, base);
loc_826C7000:
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

PPC_WEAK_FUNC(sub_826C6FC0) {
	__imp__sub_826C6FC0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7018) {
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
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c70ac
	if (cr6.eq) goto loc_826C70AC;
	// bl 0x826c6f40
	ctx.lr = 0x826C7040;
	sub_826C6F40(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826C7050;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// bl 0x826c67f8
	ctx.lr = 0x826C7060;
	sub_826C67F8(ctx, base);
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lwz r11,-10020(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10020);
	// lwz r9,360(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 360);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826c70ac
	if (cr6.eq) goto loc_826C70AC;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r6,r31,72
	ctx.r6.s64 = r31.s64 + 72;
	// addi r5,r11,-7032
	ctx.r5.s64 = r11.s64 + -7032;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826C708C;
	sub_82137A08(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,0
	ctx.r3.s64 = 0;
	// lfs f1,11368(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 11368);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82234d88
	ctx.lr = 0x826C70AC;
	sub_82234D88(ctx, base);
loc_826C70AC:
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

PPC_WEAK_FUNC(sub_826C7018) {
	__imp__sub_826C7018(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C70C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C70C4) {
	__imp__sub_826C70C4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C70C8) {
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
	ctx.lr = 0x826C70D0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lbz r11,684(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 684);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c7114
	if (!cr6.eq) goto loc_826C7114;
	// lbz r11,685(r29)
	r11.u64 = PPC_LOAD_U8(r29.u32 + 685);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c7114
	if (!cr6.eq) goto loc_826C7114;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32252
	ctx.r10.s64 = -2113667072;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r4,r9,-6988
	ctx.r4.s64 = ctx.r9.s64 + -6988;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lfs f1,3732(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 3732);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x82208800
	ctx.lr = 0x826C7114;
	sub_82208800(ctx, base);
loc_826C7114:
	// lhz r11,728(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 728);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c7150
	if (cr6.eq) goto loc_826C7150;
	// li r31,0
	r31.s64 = 0;
	// lis r28,-32121
	r28.s64 = -2105081856;
loc_826C712C:
	// lwz r11,724(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 724);
	// lwz r3,18504(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 18504);
	// lwzx r4,r11,r31
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + r31.u32);
	// bl 0x826b5cf0
	ctx.lr = 0x826C713C;
	sub_826B5CF0(ctx, base);
	// lhz r10,728(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 728);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpw cr6,r30,r10
	cr6.compare<int32_t>(r30.s32, ctx.r10.s32, xer);
	// blt cr6,0x826c712c
	if (cr6.lt) goto loc_826C712C;
loc_826C7150:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// addi r4,r10,-7008
	ctx.r4.s64 = ctx.r10.s64 + -7008;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826C7168;
	sub_8268B770(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C70C8) {
	__imp__sub_826C70C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7170) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lhz r9,712(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 712);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826c719c
	if (!cr6.gt) goto loc_826C719C;
	// lwz r11,708(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 708);
loc_826C7184:
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x826c71d0
	if (cr6.eq) goto loc_826C71D0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826c7184
	if (cr6.lt) goto loc_826C7184;
loc_826C719C:
	// lhz r9,720(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 720);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826c71c8
	if (!cr6.gt) goto loc_826C71C8;
	// lwz r11,716(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 716);
loc_826C71B0:
	// cmplw cr6,r4,r11
	cr6.compare<uint32_t>(ctx.r4.u32, r11.u32, xer);
	// beq cr6,0x826c71d0
	if (cr6.eq) goto loc_826C71D0;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,144
	r11.s64 = r11.s64 + 144;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// blt cr6,0x826c71b0
	if (cr6.lt) goto loc_826C71B0;
loc_826C71C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826C71D0:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C7170) {
	__imp__sub_826C7170(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C71D8) {
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
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// mr r11,r4
	r11.u64 = ctx.r4.u64;
	// lwz r10,656(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 656);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x826c7240
	if (!cr6.eq) goto loc_826C7240;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826c7240
	if (cr6.eq) goto loc_826C7240;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// addi r3,r8,-4
	ctx.r3.s64 = ctx.r8.s64 + -4;
	// bl 0x826c7170
	ctx.lr = 0x826C720C;
	sub_826C7170(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c7274
	if (cr6.eq) goto loc_826C7274;
	// lbz r11,140(r5)
	r11.u64 = PPC_LOAD_U8(ctx.r5.u32 + 140);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c7274
	if (cr6.eq) goto loc_826C7274;
	// li r11,1
	r11.s64 = 1;
	// stb r11,686(r8)
	PPC_STORE_U8(ctx.r8.u32 + 686, r11.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C7240:
	// lwz r10,660(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 660);
	// cmplw cr6,r11,r10
	cr6.compare<uint32_t>(r11.u32, ctx.r10.u32, xer);
	// bne cr6,0x826c7270
	if (!cr6.eq) goto loc_826C7270;
	// lwz r11,652(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 652);
	// addi r4,r8,-4
	ctx.r4.s64 = ctx.r8.s64 + -4;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c7270
	if (cr6.eq) goto loc_826C7270;
	// lwz r3,656(r4)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r4.u32 + 656);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C7270;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826C7270:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C7274:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C71D8) {
	__imp__sub_826C71D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7284) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7284) {
	__imp__sub_826C7284(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7288) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,708(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 708);
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C7288) {
	__imp__sub_826C7288(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C72A0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r11,716(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 716);
	// add r10,r4,r10
	ctx.r10.u64 = ctx.r4.u64 + ctx.r10.u64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r3,r11,r10
	ctx.r3.u64 = r11.u64 + ctx.r10.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C72A0) {
	__imp__sub_826C72A0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C72B8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,724(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 724);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C72B8) {
	__imp__sub_826C72B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C72C8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,744(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 744);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C72C8) {
	__imp__sub_826C72C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C72D8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,656(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 656);
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// blt cr6,0x826c7350
	if (cr6.lt) goto loc_826C7350;
	// cmpwi cr6,r11,3
	cr6.compare<int32_t>(r11.s32, 3, xer);
	// bgt cr6,0x826c7350
	if (cr6.gt) goto loc_826C7350;
	// lhz r8,720(r3)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r3.u32 + 720);
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// ble cr6,0x826c7350
	if (!cr6.gt) goto loc_826C7350;
	// lwz r7,716(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 716);
	// addi r10,r7,117
	ctx.r10.s64 = ctx.r7.s64 + 117;
loc_826C7308:
	// lbz r9,-1(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + -1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c7340
	if (!cr6.eq) goto loc_826C7340;
	// lbz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826c7330
	if (!cr6.eq) goto loc_826C7330;
	// lbz r9,1(r10)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq cr6,0x826c7334
	if (cr6.eq) goto loc_826C7334;
loc_826C7330:
	// li r9,1
	ctx.r9.s64 = 1;
loc_826C7334:
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c7358
	if (cr6.eq) goto loc_826C7358;
loc_826C7340:
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,144
	ctx.r10.s64 = ctx.r10.s64 + 144;
	// cmpw cr6,r11,r8
	cr6.compare<int32_t>(r11.s32, ctx.r8.s32, xer);
	// blt cr6,0x826c7308
	if (cr6.lt) goto loc_826C7308;
loc_826C7350:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_826C7358:
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r11,r7
	ctx.r10.u64 = r11.u64 + ctx.r7.u64;
	// lwz r3,104(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + 104);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C72D8) {
	__imp__sub_826C72D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7370) {
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
	ctx.lr = 0x826C7378;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r28,0
	r28.s64 = 0;
	// mr r29,r28
	r29.u64 = r28.u64;
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c73b8
	if (cr6.eq) goto loc_826C73B8;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_826C7398:
	// lwz r11,708(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// add r3,r11,r30
	ctx.r3.u64 = r11.u64 + r30.u64;
	// bl 0x826cc1f8
	ctx.lr = 0x826C73A4;
	sub_826CC1F8(ctx, base);
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c7398
	if (cr6.lt) goto loc_826C7398;
loc_826C73B8:
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// mr r29,r28
	r29.u64 = r28.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c73ec
	if (cr6.eq) goto loc_826C73EC;
	// mr r30,r28
	r30.u64 = r28.u64;
loc_826C73CC:
	// lwz r11,716(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 716);
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x826cc1f8
	ctx.lr = 0x826C73D8;
	sub_826CC1F8(ctx, base);
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// cmpw cr6,r29,r11
	cr6.compare<int32_t>(r29.s32, r11.s32, xer);
	// blt cr6,0x826c73cc
	if (cr6.lt) goto loc_826C73CC;
loc_826C73EC:
	// stb r28,690(r31)
	PPC_STORE_U8(r31.u32 + 690, r28.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C7370) {
	__imp__sub_826C7370(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C73F8) {
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
	// lhz r11,748(r3)
	r11.u64 = PPC_LOAD_U16(ctx.r3.u32 + 748);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826c7458
	if (cr6.eq) goto loc_826C7458;
	// lwz r9,740(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 740);
	// twllei r11,0
	// lwz r8,744(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 744);
	// divw r7,r9,r11
	ctx.r7.s32 = ctx.r9.s32 / r11.s32;
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// mullw r6,r7,r11
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(r11.s32);
	// subf r5,r6,r9
	ctx.r5.s64 = ctx.r9.s64 - ctx.r6.s64;
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r5,740(r3)
	PPC_STORE_U32(ctx.r3.u32 + 740, ctx.r5.u32);
	// andc r9,r11,r4
	ctx.r9.u64 = r11.u64 & ~ctx.r4.u64;
	// twlgei r9,-1
	// lwzx r11,r10,r8
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C7458:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r4,r3,72
	ctx.r4.s64 = ctx.r3.s64 + 72;
	// addi r3,r11,-6948
	ctx.r3.s64 = r11.s64 + -6948;
	// bl 0x82130000
	ctx.lr = 0x826C7468;
	sub_82130000(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r3,r10,-6968
	ctx.r3.s64 = ctx.r10.s64 + -6968;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C73F8) {
	__imp__sub_826C73F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7480) {
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
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lhz r11,4(r30)
	r11.u64 = PPC_LOAD_U16(r30.u32 + 4);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r9,r11
	ctx.r9.u64 = r11.u64;
	// cmplw cr6,r10,r9
	cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, xer);
	// beq cr6,0x826c74dc
	if (cr6.eq) goto loc_826C74DC;
	// clrlwi r10,r11,16
	ctx.r10.u64 = r11.u32 & 0xFFFF;
	// sth r11,4(r31)
	PPC_STORE_U16(r31.u32 + 4, r11.u16);
	// sth r11,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r11.u16);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c74d4
	if (cr6.eq) goto loc_826C74D4;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826C74CC;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// b 0x826c74dc
	goto loc_826C74DC;
loc_826C74D4:
	// li r11,0
	r11.s64 = 0;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
loc_826C74DC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c7514
	if (cr6.eq) goto loc_826C7514;
	// li r11,0
	r11.s64 = 0;
loc_826C74EC:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// clrlwi r11,r8,16
	r11.u64 = ctx.r8.u32 & 0xFFFF;
	// lwzx r6,r10,r9
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// stwx r6,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r6.u32);
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r11,r5
	cr6.compare<uint32_t>(r11.u32, ctx.r5.u32, xer);
	// blt cr6,0x826c74ec
	if (cr6.lt) goto loc_826C74EC;
loc_826C7514:
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

PPC_WEAK_FUNC(sub_826C7480) {
	__imp__sub_826C7480(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C752C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C752C) {
	__imp__sub_826C752C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7530) {
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
	ctx.lr = 0x826C7538;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// mr r25,r4
	r25.u64 = ctx.r4.u64;
	// mr r29,r5
	r29.u64 = ctx.r5.u64;
	// li r30,0
	r30.s64 = 0;
	// addi r31,r24,696
	r31.s64 = r24.s64 + 696;
	// lis r22,-32121
	r22.s64 = -2105081856;
loc_826C7554:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// add r10,r11,r25
	ctx.r10.u64 = r11.u64 + r25.u64;
	// lbzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + r25.u32);
	// stb r9,0(r31)
	PPC_STORE_U8(r31.u32 + 0, ctx.r9.u8);
	// lbz r8,1(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 1);
	// stb r8,1(r31)
	PPC_STORE_U8(r31.u32 + 1, ctx.r8.u8);
	// lbz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r10.u32 + 2);
	// stb r7,2(r31)
	PPC_STORE_U8(r31.u32 + 2, ctx.r7.u8);
	// lbz r6,3(r10)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r10.u32 + 3);
	// stb r6,3(r31)
	PPC_STORE_U8(r31.u32 + 3, ctx.r6.u8);
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r5,r11,4
	ctx.r5.s64 = r11.s64 + 4;
	// stw r5,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r5.u32);
	// lwz r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x826c75ac
	if (cr6.eq) goto loc_826C75AC;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// beq cr6,0x826c75ac
	if (cr6.eq) goto loc_826C75AC;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// lwz r3,-10004(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10004);
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x826c3f68
	ctx.lr = 0x826C75AC;
	sub_826C3F68(ctx, base);
loc_826C75AC:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,4
	r31.s64 = r31.s64 + 4;
	// cmpwi cr6,r30,3
	cr6.compare<int32_t>(r30.s32, 3, xer);
	// blt cr6,0x826c7554
	if (cr6.lt) goto loc_826C7554;
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r11,r10,4
	r11.s64 = ctx.r10.s64 + 4;
	// addi r9,r11,4
	ctx.r9.s64 = r11.s64 + 4;
	// lwzx r23,r10,r25
	r23.u64 = PPC_LOAD_U32(ctx.r10.u32 + r25.u32);
	// stw r11,0(r29)
	PPC_STORE_U32(r29.u32 + 0, r11.u32);
	// lwzx r31,r11,r25
	r31.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// stw r9,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826c7640
	if (cr6.eq) goto loc_826C7640;
	// lhz r11,712(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 712);
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// beq cr6,0x826c7614
	if (cr6.eq) goto loc_826C7614;
	// lhz r11,714(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 714);
	// addi r30,r24,708
	r30.s64 = r24.s64 + 708;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c7610
	if (!cr6.eq) goto loc_826C7610;
	// sth r31,6(r30)
	PPC_STORE_U16(r30.u32 + 6, r31.u16);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c6970
	ctx.lr = 0x826C760C;
	sub_826C6970(ctx, base);
	// stw r3,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r3.u32);
loc_826C7610:
	// sth r31,4(r30)
	PPC_STORE_U16(r30.u32 + 4, r31.u16);
loc_826C7614:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826c7640
	if (!cr6.gt) goto loc_826C7640;
	// li r30,0
	r30.s64 = 0;
loc_826C7620:
	// lwz r11,708(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 708);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x826ccc50
	ctx.lr = 0x826C7634;
	sub_826CCC50(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// bne 0x826c7620
	if (!cr0.eq) goto loc_826C7620;
loc_826C7640:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r10,r11,4
	ctx.r10.s64 = r11.s64 + 4;
	// lwzx r31,r11,r25
	r31.u64 = PPC_LOAD_U32(r11.u32 + r25.u32);
	// stw r10,0(r29)
	PPC_STORE_U32(r29.u32 + 0, ctx.r10.u32);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// beq cr6,0x826c76ec
	if (cr6.eq) goto loc_826C76EC;
	// lhz r11,720(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 720);
	// cmpw cr6,r11,r31
	cr6.compare<int32_t>(r11.s32, r31.s32, xer);
	// beq cr6,0x826c76c0
	if (cr6.eq) goto loc_826C76C0;
	// lhz r11,722(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 722);
	// addi r26,r24,716
	r26.s64 = r24.s64 + 716;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c76bc
	if (!cr6.eq) goto loc_826C76BC;
	// sth r31,6(r26)
	PPC_STORE_U16(r26.u32 + 6, r31.u16);
	// rlwinm r11,r31,3,0,28
	r11.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r31,r11
	ctx.r9.u64 = r31.u64 + r11.u64;
	// rlwinm r3,r9,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x826C7688;
	sub_82130528(ctx, base);
	// mr r27,r3
	r27.u64 = ctx.r3.u64;
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826c76b8
	if (!cr6.gt) goto loc_826C76B8;
	// mr r30,r27
	r30.u64 = r27.u64;
	// mr r28,r31
	r28.u64 = r31.u64;
loc_826C769C:
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c76ac
	if (cr6.eq) goto loc_826C76AC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cca30
	ctx.lr = 0x826C76AC;
	sub_826CCA30(ctx, base);
loc_826C76AC:
	// addic. r28,r28,-1
	xer.ca = r28.u32 > 0;
	r28.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r28.s32, 0, xer);
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// bne 0x826c769c
	if (!cr0.eq) goto loc_826C769C;
loc_826C76B8:
	// stw r27,0(r26)
	PPC_STORE_U32(r26.u32 + 0, r27.u32);
loc_826C76BC:
	// sth r31,4(r26)
	PPC_STORE_U16(r26.u32 + 4, r31.u16);
loc_826C76C0:
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826c76ec
	if (!cr6.gt) goto loc_826C76EC;
	// li r30,0
	r30.s64 = 0;
loc_826C76CC:
	// lwz r11,716(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 716);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// add r3,r30,r11
	ctx.r3.u64 = r30.u64 + r11.u64;
	// bl 0x826ccc50
	ctx.lr = 0x826C76E0;
	sub_826CCC50(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r30,r30,144
	r30.s64 = r30.s64 + 144;
	// bne 0x826c76cc
	if (!cr0.eq) goto loc_826C76CC;
loc_826C76EC:
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// lwz r3,-10004(r22)
	ctx.r3.u64 = PPC_LOAD_U32(r22.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826C76F8;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r24
	ctx.r3.u64 = r24.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// bl 0x826c67f8
	ctx.lr = 0x826C7708;
	sub_826C67F8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_826C7530) {
	__imp__sub_826C7530(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7710) {
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
	// addi r3,r31,488
	ctx.r3.s64 = r31.s64 + 488;
	// bl 0x826cd4b8
	ctx.lr = 0x826C7734;
	sub_826CD4B8(ctx, base);
	// cmpwi cr6,r3,-1
	cr6.compare<int32_t>(ctx.r3.s32, -1, xer);
	// beq cr6,0x826c77ec
	if (cr6.eq) goto loc_826C77EC;
	// cmpw cr6,r30,r3
	cr6.compare<int32_t>(r30.s32, ctx.r3.s32, xer);
	// blt cr6,0x826c7794
	if (cr6.lt) goto loc_826C7794;
	// cmpwi cr6,r30,5
	cr6.compare<int32_t>(r30.s32, 5, xer);
	// beq cr6,0x826c7794
	if (cr6.eq) goto loc_826C7794;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6c50
	ctx.lr = 0x826C7754;
	sub_826C6C50(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6cc8
	ctx.lr = 0x826C775C;
	sub_826C6CC8(ctx, base);
	// lbz r11,684(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 684);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c7780
	if (cr6.eq) goto loc_826C7780;
	// lbz r10,685(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 685);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c7780
	if (!cr6.eq) goto loc_826C7780;
	// clrlwi r11,r11,25
	r11.u64 = r11.u32 & 0x7F;
	// stb r11,684(r31)
	PPC_STORE_U8(r31.u32 + 684, r11.u8);
loc_826C7780:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r11,-10236(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10236);
	// lwz r3,48(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// bl 0x8220a0b8
	ctx.lr = 0x826C7790;
	sub_8220A0B8(ctx, base);
	// b 0x826c77ec
	goto loc_826C77EC;
loc_826C7794:
	// lwz r11,700(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 700);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826c77bc
	if (cr6.eq) goto loc_826C77BC;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c4058
	ctx.lr = 0x826C77B4;
	sub_826C4058(ctx, base);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r10,700(r31)
	PPC_STORE_U32(r31.u32 + 700, ctx.r10.u32);
loc_826C77BC:
	// lwz r11,680(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c77d0
	if (cr6.eq) goto loc_826C77D0;
	// li r11,0
	r11.s64 = 0;
	// stw r11,680(r31)
	PPC_STORE_U32(r31.u32 + 680, r11.u32);
loc_826C77D0:
	// lbz r11,684(r31)
	r11.u64 = PPC_LOAD_U8(r31.u32 + 684);
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c77ec
	if (!cr6.eq) goto loc_826C77EC;
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwimi r11,r10,7,0,24
	r11.u64 = (__builtin_rotateleft32(ctx.r10.u32, 7) & 0xFFFFFF80) | (r11.u64 & 0xFFFFFFFF0000007F);
	// stb r11,684(r31)
	PPC_STORE_U8(r31.u32 + 684, r11.u8);
loc_826C77EC:
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

PPC_WEAK_FUNC(sub_826C7710) {
	__imp__sub_826C7710(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7804) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7804) {
	__imp__sub_826C7804(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7808) {
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
	// beq cr6,0x826c7850
	if (cr6.eq) goto loc_826C7850;
	// lwz r11,656(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 656);
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
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
loc_826C7850:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6880
	ctx.r3.s64 = r11.s64 + -6880;
	// bl 0x82130000
	ctx.lr = 0x826C785C;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_826C7808) {
	__imp__sub_826C7808(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C787C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C787C) {
	__imp__sub_826C787C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7880) {
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
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// beq cr6,0x826c78d8
	if (cr6.eq) goto loc_826C78D8;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826C78C4;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r5,r30,24
	ctx.r5.u64 = r30.u32 & 0xFF;
	// bl 0x826c67f8
	ctx.lr = 0x826C78D4;
	sub_826C67F8(ctx, base);
	// b 0x826c78e4
	goto loc_826C78E4;
loc_826C78D8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6792
	ctx.r3.s64 = r11.s64 + -6792;
	// bl 0x82130000
	ctx.lr = 0x826C78E4;
	sub_82130000(ctx, base);
loc_826C78E4:
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

PPC_WEAK_FUNC(sub_826C7880) {
	__imp__sub_826C7880(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C78FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C78FC) {
	__imp__sub_826C78FC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7900) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,8(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r7,r8,1
	ctx.r7.u64 = ctx.r8.u64 ^ 1;
	// clrlwi r4,r7,24
	ctx.r4.u64 = ctx.r7.u32 & 0xFF;
	// b 0x826c7018
	sub_826C7018(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826C7900) {
	__imp__sub_826C7900(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7920) {
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
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r31,0(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// rlwinm r8,r9,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// xori r30,r8,1
	r30.u64 = ctx.r8.u64 ^ 1;
	// beq cr6,0x826c7980
	if (cr6.eq) goto loc_826C7980;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x826c6f40
	ctx.lr = 0x826C795C;
	sub_826C6F40(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c3d98
	ctx.lr = 0x826C796C;
	sub_826C3D98(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// clrlwi r5,r30,24
	ctx.r5.u64 = r30.u32 & 0xFF;
	// bl 0x826c67f8
	ctx.lr = 0x826C797C;
	sub_826C67F8(ctx, base);
	// b 0x826c798c
	goto loc_826C798C;
loc_826C7980:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6720
	ctx.r3.s64 = r11.s64 + -6720;
	// bl 0x82130000
	ctx.lr = 0x826C798C;
	sub_82130000(ctx, base);
loc_826C798C:
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

PPC_WEAK_FUNC(sub_826C7920) {
	__imp__sub_826C7920(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C79A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C79A4) {
	__imp__sub_826C79A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C79A8) {
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
	// beq cr6,0x826c79bc
	if (cr6.eq) goto loc_826C79BC;
	// b 0x826c6f40
	sub_826C6F40(ctx, base);
	return;
loc_826C79BC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6648
	ctx.r3.s64 = r11.s64 + -6648;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826C79A8) {
	__imp__sub_826C79A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C79C8) {
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
	// beq cr6,0x826c79f8
	if (cr6.eq) goto loc_826C79F8;
	// lbz r9,684(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 684);
	// rlwimi r9,r10,7,0,24
	ctx.r9.u64 = (__builtin_rotateleft32(ctx.r10.u32, 7) & 0xFFFFFF80) | (ctx.r9.u64 & 0xFFFFFFFF0000007F);
	// stb r9,684(r11)
	PPC_STORE_U8(r11.u32 + 684, ctx.r9.u8);
	// blr 
	return;
loc_826C79F8:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6576
	ctx.r3.s64 = r11.s64 + -6576;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826C79C8) {
	__imp__sub_826C79C8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7A04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7A04) {
	__imp__sub_826C7A04(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7A08) {
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
	// beq cr6,0x826c7a50
	if (cr6.eq) goto loc_826C7A50;
	// addi r3,r11,456
	ctx.r3.s64 = r11.s64 + 456;
	// bl 0x8238e818
	ctx.lr = 0x826C7A34;
	sub_8238E818(ctx, base);
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
loc_826C7A50:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6512
	ctx.r3.s64 = r11.s64 + -6512;
	// bl 0x82130000
	ctx.lr = 0x826C7A5C;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_826C7A08) {
	__imp__sub_826C7A08(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7A7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7A7C) {
	__imp__sub_826C7A7C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7A80) {
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
	// beq cr6,0x826c7aac
	if (cr6.eq) goto loc_826C7AAC;
	// addi r11,r11,520
	r11.s64 = r11.s64 + 520;
	// b 0x826c7abc
	goto loc_826C7ABC;
loc_826C7AAC:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6424
	ctx.r3.s64 = r11.s64 + -6424;
	// bl 0x82130000
	ctx.lr = 0x826C7AB8;
	sub_82130000(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_826C7ABC:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
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

PPC_WEAK_FUNC(sub_826C7A80) {
	__imp__sub_826C7A80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7AD8) {
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
	// beq cr6,0x826c7b04
	if (cr6.eq) goto loc_826C7B04;
	// addi r11,r11,72
	r11.s64 = r11.s64 + 72;
	// b 0x826c7b14
	goto loc_826C7B14;
loc_826C7B04:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6344
	ctx.r3.s64 = r11.s64 + -6344;
	// bl 0x82130000
	ctx.lr = 0x826C7B10;
	sub_82130000(ctx, base);
	// li r11,0
	r11.s64 = 0;
loc_826C7B14:
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
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

PPC_WEAK_FUNC(sub_826C7AD8) {
	__imp__sub_826C7AD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7B30) {
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
	// bne cr6,0x826c7b74
	if (!cr6.eq) goto loc_826C7B74;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x826c7b6c
	if (cr6.eq) goto loc_826C7B6C;
	// bl 0x826c6970
	ctx.lr = 0x826C7B68;
	sub_826C6970(ctx, base);
	// b 0x826c7b70
	goto loc_826C7B70;
loc_826C7B6C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C7B70:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826C7B74:
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

PPC_WEAK_FUNC(sub_826C7B30) {
	__imp__sub_826C7B30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7B90) {
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
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r9,r11,-28924
	ctx.r9.s64 = r11.s64 + -28924;
	// addi r8,r10,-21868
	ctx.r8.s64 = ctx.r10.s64 + -21868;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r11,r31,4
	r11.s64 = r31.s64 + 4;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// lis r7,-32251
	ctx.r7.s64 = -2113601536;
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r7,-4872
	ctx.r4.s64 = ctx.r7.s64 + -4872;
	// addi r3,r11,4
	ctx.r3.s64 = r11.s64 + 4;
	// bl 0x823db670
	ctx.lr = 0x826C7BD4;
	sub_823DB670(ctx, base);
	// li r9,1
	ctx.r9.s64 = 1;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// stb r9,687(r31)
	PPC_STORE_U8(r31.u32 + 687, ctx.r9.u8);
	// lis r5,-32244
	ctx.r5.s64 = -2113142784;
	// stb r9,689(r31)
	PPC_STORE_U8(r31.u32 + 689, ctx.r9.u8);
	// li r11,0
	r11.s64 = 0;
	// stb r9,691(r31)
	PPC_STORE_U8(r31.u32 + 691, ctx.r9.u8);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r3,r5,-6116
	ctx.r3.s64 = ctx.r5.s64 + -6116;
	// stw r11,656(r31)
	PPC_STORE_U32(r31.u32 + 656, r11.u32);
	// addi r4,r6,-6104
	ctx.r4.s64 = ctx.r6.s64 + -6104;
	// stw r10,648(r31)
	PPC_STORE_U32(r31.u32 + 648, ctx.r10.u32);
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stw r11,660(r31)
	PPC_STORE_U32(r31.u32 + 660, r11.u32);
	// stw r4,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r4.u32);
	// stw r11,664(r31)
	PPC_STORE_U32(r31.u32 + 664, r11.u32);
	// stw r11,668(r31)
	PPC_STORE_U32(r31.u32 + 668, r11.u32);
	// stw r11,676(r31)
	PPC_STORE_U32(r31.u32 + 676, r11.u32);
	// stw r11,680(r31)
	PPC_STORE_U32(r31.u32 + 680, r11.u32);
	// stb r11,685(r31)
	PPC_STORE_U8(r31.u32 + 685, r11.u8);
	// stb r11,686(r31)
	PPC_STORE_U8(r31.u32 + 686, r11.u8);
	// stb r11,688(r31)
	PPC_STORE_U8(r31.u32 + 688, r11.u8);
	// stb r11,690(r31)
	PPC_STORE_U8(r31.u32 + 690, r11.u8);
	// stb r11,692(r31)
	PPC_STORE_U8(r31.u32 + 692, r11.u8);
	// stb r11,693(r31)
	PPC_STORE_U8(r31.u32 + 693, r11.u8);
	// lbz r9,684(r31)
	ctx.r9.u64 = PPC_LOAD_U8(r31.u32 + 684);
	// ori r8,r9,128
	ctx.r8.u64 = ctx.r9.u64 | 128;
	// stb r8,684(r31)
	PPC_STORE_U8(r31.u32 + 684, ctx.r8.u8);
	// stw r11,708(r31)
	PPC_STORE_U32(r31.u32 + 708, r11.u32);
	// sth r11,712(r31)
	PPC_STORE_U16(r31.u32 + 712, r11.u16);
	// sth r11,714(r31)
	PPC_STORE_U16(r31.u32 + 714, r11.u16);
	// stw r11,716(r31)
	PPC_STORE_U32(r31.u32 + 716, r11.u32);
	// sth r11,720(r31)
	PPC_STORE_U16(r31.u32 + 720, r11.u16);
	// sth r11,722(r31)
	PPC_STORE_U16(r31.u32 + 722, r11.u16);
	// stw r11,724(r31)
	PPC_STORE_U32(r31.u32 + 724, r11.u32);
	// sth r11,728(r31)
	PPC_STORE_U16(r31.u32 + 728, r11.u16);
	// sth r11,730(r31)
	PPC_STORE_U16(r31.u32 + 730, r11.u16);
	// stw r11,732(r31)
	PPC_STORE_U32(r31.u32 + 732, r11.u32);
	// sth r11,736(r31)
	PPC_STORE_U16(r31.u32 + 736, r11.u16);
	// sth r11,738(r31)
	PPC_STORE_U16(r31.u32 + 738, r11.u16);
	// stw r11,740(r31)
	PPC_STORE_U32(r31.u32 + 740, r11.u32);
	// stw r11,744(r31)
	PPC_STORE_U32(r31.u32 + 744, r11.u32);
	// sth r11,748(r31)
	PPC_STORE_U16(r31.u32 + 748, r11.u16);
	// sth r11,750(r31)
	PPC_STORE_U16(r31.u32 + 750, r11.u16);
	// stb r11,40(r31)
	PPC_STORE_U8(r31.u32 + 40, r11.u8);
	// stb r11,72(r31)
	PPC_STORE_U8(r31.u32 + 72, r11.u8);
	// stb r11,200(r31)
	PPC_STORE_U8(r31.u32 + 200, r11.u8);
	// stb r11,328(r31)
	PPC_STORE_U8(r31.u32 + 328, r11.u8);
	// stb r11,520(r31)
	PPC_STORE_U8(r31.u32 + 520, r11.u8);
	// stb r11,456(r31)
	PPC_STORE_U8(r31.u32 + 456, r11.u8);
	// stb r11,488(r31)
	PPC_STORE_U8(r31.u32 + 488, r11.u8);
	// stw r10,696(r31)
	PPC_STORE_U32(r31.u32 + 696, ctx.r10.u32);
	// stw r10,700(r31)
	PPC_STORE_U32(r31.u32 + 700, ctx.r10.u32);
	// stw r10,704(r31)
	PPC_STORE_U32(r31.u32 + 704, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C7B90) {
	__imp__sub_826C7B90(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7CC4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7CC4) {
	__imp__sub_826C7CC4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7CC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lwz r3,-27224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27224);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C7CC8) {
	__imp__sub_826C7CC8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7CD4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7CD4) {
	__imp__sub_826C7CD4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7CD8) {
	PPC_FUNC_PROLOGUE();
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// b 0x826c85f0
	sub_826C85F0(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826C7CD8) {
	__imp__sub_826C7CD8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7CE0) {
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
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c7d38
	if (cr6.eq) goto loc_826C7D38;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,708(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 708);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826C7D38:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6272
	ctx.r3.s64 = r11.s64 + -6272;
	// bl 0x82130000
	ctx.lr = 0x826C7D44;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_826C7CE0) {
	__imp__sub_826C7CE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7D64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7D64) {
	__imp__sub_826C7D64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7D68) {
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
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c7dc0
	if (cr6.eq) goto loc_826C7DC0;
	// lwz r11,4(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// lwz r10,716(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 716);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// stw r11,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826C7DC0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6192
	ctx.r3.s64 = r11.s64 + -6192;
	// bl 0x82130000
	ctx.lr = 0x826C7DCC;
	sub_82130000(ctx, base);
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

PPC_WEAK_FUNC(sub_826C7D68) {
	__imp__sub_826C7D68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7DEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7DEC) {
	__imp__sub_826C7DEC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7DF0) {
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
	// beq cr6,0x826c7e10
	if (cr6.eq) goto loc_826C7E10;
	// lwz r4,4(r11)
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r3,r10,520
	ctx.r3.s64 = ctx.r10.s64 + 520;
	// b 0x823db670
	sub_823DB670(ctx, base);
	return;
loc_826C7E10:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r3,r11,-6096
	ctx.r3.s64 = r11.s64 + -6096;
	// b 0x82130000
	sub_82130000(ctx, base);
	return;
}

PPC_WEAK_FUNC(sub_826C7DF0) {
	__imp__sub_826C7DF0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7E1C) {
	__imp__sub_826C7E1C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7E20) {
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
	// li r3,752
	ctx.r3.s64 = 752;
	// bl 0x82130528
	ctx.lr = 0x826C7E34;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c7e50
	if (cr6.eq) goto loc_826C7E50;
	// bl 0x826c7b90
	ctx.lr = 0x826C7E40;
	sub_826C7B90(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C7E50:
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

PPC_WEAK_FUNC(sub_826C7E20) {
	__imp__sub_826C7E20(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7E64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7E64) {
	__imp__sub_826C7E64(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7E68) {
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
	ctx.lr = 0x826C7E70;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// addi r8,r30,4
	ctx.r8.s64 = r30.s64 + 4;
	// bne cr6,0x826c7e8c
	if (!cr6.eq) goto loc_826C7E8C;
	// li r8,0
	ctx.r8.s64 = 0;
loc_826C7E8C:
	// addi r9,r31,4
	ctx.r9.s64 = r31.s64 + 4;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r11,r9,4
	r11.s64 = ctx.r9.s64 + 4;
	// subf r9,r9,r8
	ctx.r9.s64 = ctx.r8.s64 - ctx.r9.s64;
loc_826C7E9C:
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x826c7e9c
	if (!cr0.eq) goto loc_826C7E9C;
	// addi r11,r31,40
	r11.s64 = r31.s64 + 40;
	// subf r9,r31,r30
	ctx.r9.s64 = r30.s64 - r31.s64;
	// li r10,64
	ctx.r10.s64 = 64;
loc_826C7EBC:
	// lbzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r9.u32 + r11.u32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stb r8,0(r11)
	PPC_STORE_U8(r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// bne 0x826c7ebc
	if (!cr0.eq) goto loc_826C7EBC;
	// lwz r11,104(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 104);
	// addi r28,r30,124
	r28.s64 = r30.s64 + 124;
	// addi r29,r31,124
	r29.s64 = r31.s64 + 124;
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// stw r11,104(r31)
	PPC_STORE_U32(r31.u32 + 104, r11.u32);
	// lwz r10,108(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 108);
	// stw r10,108(r31)
	PPC_STORE_U32(r31.u32 + 108, ctx.r10.u32);
	// lwz r9,112(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 112);
	// stw r9,112(r31)
	PPC_STORE_U32(r31.u32 + 112, ctx.r9.u32);
	// lbz r8,116(r30)
	ctx.r8.u64 = PPC_LOAD_U8(r30.u32 + 116);
	// stb r8,116(r31)
	PPC_STORE_U8(r31.u32 + 116, ctx.r8.u8);
	// lbz r7,117(r30)
	ctx.r7.u64 = PPC_LOAD_U8(r30.u32 + 117);
	// stb r7,117(r31)
	PPC_STORE_U8(r31.u32 + 117, ctx.r7.u8);
	// lbz r6,118(r30)
	ctx.r6.u64 = PPC_LOAD_U8(r30.u32 + 118);
	// stb r6,118(r31)
	PPC_STORE_U8(r31.u32 + 118, ctx.r6.u8);
	// lbz r5,119(r30)
	ctx.r5.u64 = PPC_LOAD_U8(r30.u32 + 119);
	// stb r5,119(r31)
	PPC_STORE_U8(r31.u32 + 119, ctx.r5.u8);
	// lbz r4,120(r30)
	ctx.r4.u64 = PPC_LOAD_U8(r30.u32 + 120);
	// stb r4,120(r31)
	PPC_STORE_U8(r31.u32 + 120, ctx.r4.u8);
	// beq cr6,0x826c7f50
	if (cr6.eq) goto loc_826C7F50;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x826c7f44
	if (cr6.eq) goto loc_826C7F44;
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c7f44
	if (cr6.eq) goto loc_826C7F44;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826C7F44;
	sub_82130588(ctx, base);
loc_826C7F44:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c7480
	ctx.lr = 0x826C7F50;
	sub_826C7480(ctx, base);
loc_826C7F50:
	// addi r28,r30,132
	r28.s64 = r30.s64 + 132;
	// addi r29,r31,132
	r29.s64 = r31.s64 + 132;
	// cmplw cr6,r29,r28
	cr6.compare<uint32_t>(r29.u32, r28.u32, xer);
	// beq cr6,0x826c7f90
	if (cr6.eq) goto loc_826C7F90;
	// lhz r11,4(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// beq cr6,0x826c7f84
	if (cr6.eq) goto loc_826C7F84;
	// lhz r11,6(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c7f84
	if (cr6.eq) goto loc_826C7F84;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826C7F84;
	sub_82130588(ctx, base);
loc_826C7F84:
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c7480
	ctx.lr = 0x826C7F90;
	sub_826C7480(ctx, base);
loc_826C7F90:
	// lbz r11,140(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 140);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,140(r31)
	PPC_STORE_U8(r31.u32 + 140, r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C7E68) {
	__imp__sub_826C7E68(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C7FA4) {
	__imp__sub_826C7FA4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C7FA8) {
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
	// addi r31,r11,-27224
	r31.s64 = r11.s64 + -27224;
	// lwz r11,-27224(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -27224);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c8294
	if (!cr6.eq) goto loc_826C8294;
	// li r3,64
	ctx.r3.s64 = 64;
	// bl 0x82130528
	ctx.lr = 0x826C7FD8;
	sub_82130528(ctx, base);
	// li r30,0
	r30.s64 = 0;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c7fec
	if (cr6.eq) goto loc_826C7FEC;
	// bl 0x821d5408
	ctx.lr = 0x826C7FE8;
	sub_821D5408(ctx, base);
	// b 0x826c7ff0
	goto loc_826C7FF0;
loc_826C7FEC:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826C7FF0:
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// lis r11,-32208
	r11.s64 = -2110783488;
	// stw r30,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r30.u32);
	// addi r7,r10,-6020
	ctx.r7.s64 = ctx.r10.s64 + -6020;
	// stw r30,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r30.u32);
	// addi r9,r11,1040
	ctx.r9.s64 = r11.s64 + 1040;
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r7,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r7.u32);
	// li r5,752
	ctx.r5.s64 = 752;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r8,-32148
	ctx.r8.s64 = -2106851328;
	// stw r5,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r5.u32);
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// addi r4,r8,32288
	ctx.r4.s64 = ctx.r8.s64 + 32288;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// ld r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// stw r4,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r5,r10,-25836
	ctx.r5.s64 = ctx.r10.s64 + -25836;
	// ld r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// std r7,32(r11)
	PPC_STORE_U64(r11.u32 + 32, ctx.r7.u64);
	// addi r9,r3,-25860
	ctx.r9.s64 = ctx.r3.s64 + -25860;
	// addi r4,r8,-25788
	ctx.r4.s64 = ctx.r8.s64 + -25788;
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r10,72
	ctx.r10.s64 = 72;
	// std r6,40(r11)
	PPC_STORE_U64(r11.u32 + 40, ctx.r6.u64);
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// li r11,40
	r11.s64 = 40;
	// addi r6,r3,-25812
	ctx.r6.s64 = ctx.r3.s64 + -25812;
	// addi r5,r8,-25764
	ctx.r5.s64 = ctx.r8.s64 + -25764;
	// stw r11,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, r11.u32);
	// li r11,328
	r11.s64 = 328;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r9,200
	ctx.r9.s64 = 200;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,520
	ctx.r10.s64 = 520;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,-25716
	ctx.r4.s64 = ctx.r7.s64 + -25716;
	// addi r6,r3,-25740
	ctx.r6.s64 = ctx.r3.s64 + -25740;
	// addi r5,r8,-25692
	ctx.r5.s64 = ctx.r8.s64 + -25692;
	// li r11,488
	r11.s64 = 488;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r9,456
	ctx.r9.s64 = 456;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,685
	ctx.r10.s64 = 685;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,-25644
	ctx.r4.s64 = ctx.r7.s64 + -25644;
	// addi r6,r3,-25668
	ctx.r6.s64 = ctx.r3.s64 + -25668;
	// addi r5,r8,-25620
	ctx.r5.s64 = ctx.r8.s64 + -25620;
	// li r11,687
	r11.s64 = 687;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r9,686
	ctx.r9.s64 = 686;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,688
	ctx.r10.s64 = 688;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// lis r8,-32125
	ctx.r8.s64 = -2105344000;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// addi r4,r7,-25572
	ctx.r4.s64 = ctx.r7.s64 + -25572;
	// addi r6,r3,-25596
	ctx.r6.s64 = ctx.r3.s64 + -25596;
	// addi r5,r8,-25548
	ctx.r5.s64 = ctx.r8.s64 + -25548;
	// li r11,693
	r11.s64 = 693;
	// lis r7,-32125
	ctx.r7.s64 = -2105344000;
	// li r9,689
	ctx.r9.s64 = 689;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// li r10,691
	ctx.r10.s64 = 691;
	// addi r4,r7,-25524
	ctx.r4.s64 = ctx.r7.s64 + -25524;
	// stw r9,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r9.u32);
	// li r11,676
	r11.s64 = 676;
	// stw r10,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r10.u32);
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lis r3,-32125
	ctx.r3.s64 = -2105344000;
	// stw r11,8(r4)
	PPC_STORE_U32(ctx.r4.u32 + 8, r11.u32);
	// lwz r11,-27208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27208);
	// li r10,708
	ctx.r10.s64 = 708;
	// addi r9,r3,-25236
	ctx.r9.s64 = ctx.r3.s64 + -25236;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,8(r9)
	PPC_STORE_U32(ctx.r9.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826c815c
	if (!cr6.eq) goto loc_826C815C;
	// bl 0x826ccec0
	ctx.lr = 0x826C8158;
	sub_826CCEC0(ctx, base);
	// lwz r11,-27208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27208);
loc_826C815C:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// addi r8,r10,-25500
	ctx.r8.s64 = ctx.r10.s64 + -25500;
	// addi r7,r9,-25188
	ctx.r7.s64 = ctx.r9.s64 + -25188;
	// li r10,716
	ctx.r10.s64 = 716;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826c8188
	if (!cr6.eq) goto loc_826C8188;
	// bl 0x826ccec0
	ctx.lr = 0x826C8184;
	sub_826CCEC0(ctx, base);
	// lwz r11,-27208(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27208);
loc_826C8188:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r8,r10,-25464
	ctx.r8.s64 = ctx.r10.s64 + -25464;
	// addi r7,r9,-25140
	ctx.r7.s64 = ctx.r9.s64 + -25140;
	// li r10,724
	ctx.r10.s64 = 724;
	// lwz r9,-27564(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -27564);
	// stw r11,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, r11.u32);
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// stw r10,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r10.u32);
	// bne cr6,0x826c81bc
	if (!cr6.eq) goto loc_826C81BC;
	// bl 0x826b7f00
	ctx.lr = 0x826C81B8;
	sub_826B7F00(ctx, base);
	// lwz r9,-27564(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -27564);
loc_826C81BC:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r8,r11,-25428
	ctx.r8.s64 = r11.s64 + -25428;
	// addi r7,r10,-25092
	ctx.r7.s64 = ctx.r10.s64 + -25092;
	// li r11,732
	r11.s64 = 732;
	// lwz r10,-27168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -27168);
	// stw r9,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r9.u32);
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r11,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, r11.u32);
	// bne cr6,0x826c81f0
	if (!cr6.eq) goto loc_826C81F0;
	// bl 0x826d3f08
	ctx.lr = 0x826C81EC;
	sub_826D3F08(ctx, base);
	// lwz r10,-27168(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + -27168);
loc_826C81F0:
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r9,-32125
	ctx.r9.s64 = -2105344000;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// addi r8,r11,-25392
	ctx.r8.s64 = r11.s64 + -25392;
	// addi r7,r9,-25044
	ctx.r7.s64 = ctx.r9.s64 + -25044;
	// li r9,744
	ctx.r9.s64 = 744;
	// lwz r11,-27156(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27156);
	// stw r10,20(r8)
	PPC_STORE_U32(ctx.r8.u32 + 20, ctx.r10.u32);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r9,8(r7)
	PPC_STORE_U32(ctx.r7.u32 + 8, ctx.r9.u32);
	// bne cr6,0x826c8224
	if (!cr6.eq) goto loc_826C8224;
	// bl 0x826d3c18
	ctx.lr = 0x826C8220;
	sub_826D3C18(ctx, base);
	// lwz r11,-27156(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -27156);
loc_826C8224:
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r9,r10,-25356
	ctx.r9.s64 = ctx.r10.s64 + -25356;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, r11.u32);
	// bl 0x821d4458
	ctx.lr = 0x826C8240;
	sub_821D4458(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x821d4100
	ctx.lr = 0x826C8250;
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
	ctx.lr = 0x826C826C;
	sub_821D41D0(ctx, base);
	// lis r6,-32125
	ctx.r6.s64 = -2105344000;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r4,r6,-25320
	ctx.r4.s64 = ctx.r6.s64 + -25320;
	// bl 0x821d4b00
	ctx.lr = 0x826C827C;
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
	ctx.lr = 0x826C8294;
	sub_821C0548(ctx, base);
loc_826C8294:
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

PPC_WEAK_FUNC(sub_826C7FA8) {
	__imp__sub_826C7FA8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C82AC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C82AC) {
	__imp__sub_826C82AC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C82B0) {
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
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,30728
	ctx.r4.s64 = r11.s64 + 30728;
	// addi r3,r10,-5772
	ctx.r3.s64 = ctx.r10.s64 + -5772;
	// bl 0x82554798
	ctx.lr = 0x826C82D0;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,30848
	ctx.r4.s64 = ctx.r9.s64 + 30848;
	// addi r3,r8,-5796
	ctx.r3.s64 = ctx.r8.s64 + -5796;
	// bl 0x82554798
	ctx.lr = 0x826C82E4;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,30976
	ctx.r4.s64 = ctx.r7.s64 + 30976;
	// addi r3,r6,-5812
	ctx.r3.s64 = ctx.r6.s64 + -5812;
	// bl 0x82554798
	ctx.lr = 0x826C82F8;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,31008
	ctx.r4.s64 = ctx.r5.s64 + 31008;
	// addi r3,r3,-5828
	ctx.r3.s64 = ctx.r3.s64 + -5828;
	// bl 0x82554798
	ctx.lr = 0x826C830C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,31144
	ctx.r4.s64 = r11.s64 + 31144;
	// addi r3,r10,-5844
	ctx.r3.s64 = ctx.r10.s64 + -5844;
	// bl 0x82554798
	ctx.lr = 0x826C8320;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,31176
	ctx.r4.s64 = ctx.r9.s64 + 31176;
	// addi r3,r8,-5860
	ctx.r3.s64 = ctx.r8.s64 + -5860;
	// bl 0x82554798
	ctx.lr = 0x826C8334;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,31968
	ctx.r4.s64 = ctx.r7.s64 + 31968;
	// addi r3,r6,-5888
	ctx.r3.s64 = ctx.r6.s64 + -5888;
	// bl 0x82554798
	ctx.lr = 0x826C8348;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,32104
	ctx.r4.s64 = ctx.r5.s64 + 32104;
	// addi r3,r3,-5912
	ctx.r3.s64 = ctx.r3.s64 + -5912;
	// bl 0x82554798
	ctx.lr = 0x826C835C;
	sub_82554798(ctx, base);
	// lis r11,-32148
	r11.s64 = -2106851328;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r11,31240
	ctx.r4.s64 = r11.s64 + 31240;
	// addi r3,r10,-5936
	ctx.r3.s64 = ctx.r10.s64 + -5936;
	// bl 0x82554798
	ctx.lr = 0x826C8370;
	sub_82554798(ctx, base);
	// lis r9,-32148
	ctx.r9.s64 = -2106851328;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r4,r9,31360
	ctx.r4.s64 = ctx.r9.s64 + 31360;
	// addi r3,r8,-5964
	ctx.r3.s64 = ctx.r8.s64 + -5964;
	// bl 0x82554798
	ctx.lr = 0x826C8384;
	sub_82554798(ctx, base);
	// lis r7,-32148
	ctx.r7.s64 = -2106851328;
	// lis r6,-32244
	ctx.r6.s64 = -2113142784;
	// addi r4,r7,32240
	ctx.r4.s64 = ctx.r7.s64 + 32240;
	// addi r3,r6,-5992
	ctx.r3.s64 = ctx.r6.s64 + -5992;
	// bl 0x82554798
	ctx.lr = 0x826C8398;
	sub_82554798(ctx, base);
	// lis r5,-32148
	ctx.r5.s64 = -2106851328;
	// lis r3,-32244
	ctx.r3.s64 = -2113142784;
	// addi r4,r5,31448
	ctx.r4.s64 = ctx.r5.s64 + 31448;
	// addi r3,r3,-6008
	ctx.r3.s64 = ctx.r3.s64 + -6008;
	// bl 0x82554798
	ctx.lr = 0x826C83AC;
	sub_82554798(ctx, base);
	// bl 0x826cd0c8
	ctx.lr = 0x826C83B0;
	sub_826CD0C8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C82B0) {
	__imp__sub_826C82B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C83C0) {
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
	ctx.lr = 0x826C83C8;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// mr r27,r4
	r27.u64 = ctx.r4.u64;
	// mr r31,r30
	r31.u64 = r30.u64;
	// lhz r11,4(r29)
	r11.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// rotlwi r9,r11,3
	ctx.r9.u64 = __builtin_rotateleft32(r11.u32, 3);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,4,0,27
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r28,r11,r10
	r28.u64 = r11.u64 + ctx.r10.u64;
	// cmplw cr6,r30,r28
	cr6.compare<uint32_t>(r30.u32, r28.u32, xer);
	// beq cr6,0x826c8418
	if (cr6.eq) goto loc_826C8418;
	// subf r26,r30,r27
	r26.s64 = r27.s64 - r30.s64;
loc_826C8400:
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// add r3,r26,r31
	ctx.r3.u64 = r26.u64 + r31.u64;
	// bl 0x826c7e68
	ctx.lr = 0x826C840C;
	sub_826C7E68(ctx, base);
	// addi r31,r31,144
	r31.s64 = r31.s64 + 144;
	// cmplw cr6,r31,r28
	cr6.compare<uint32_t>(r31.u32, r28.u32, xer);
	// bne cr6,0x826c8400
	if (!cr6.eq) goto loc_826C8400;
loc_826C8418:
	// subf r11,r27,r30
	r11.s64 = r30.s64 - r27.s64;
	// lhz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U16(r29.u32 + 4);
	// li r9,144
	ctx.r9.s64 = 144;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// divw r8,r11,r9
	ctx.r8.s32 = r11.s32 / ctx.r9.s32;
	// subf r7,r8,r10
	ctx.r7.s64 = ctx.r10.s64 - ctx.r8.s64;
	// sth r7,4(r29)
	PPC_STORE_U16(r29.u32 + 4, ctx.r7.u16);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826C83C0) {
	__imp__sub_826C83C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C843C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C843C) {
	__imp__sub_826C843C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8440) {
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
	ctx.lr = 0x826C8448;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r9,r11,-6104
	ctx.r9.s64 = r11.s64 + -6104;
	// addi r8,r10,-6116
	ctx.r8.s64 = ctx.r10.s64 + -6116;
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// addi r29,r31,708
	r29.s64 = r31.s64 + 708;
	// stw r8,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r8.u32);
	// addi r26,r31,4
	r26.s64 = r31.s64 + 4;
	// lwz r4,708(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 708);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lhz r11,712(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 712);
	// rotlwi r10,r11,3
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 3);
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r4
	ctx.r5.u64 = r11.u64 + ctx.r4.u64;
	// bl 0x826c83c0
	ctx.lr = 0x826C8490;
	sub_826C83C0(ctx, base);
	// lhz r11,720(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 720);
	// lwz r4,716(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 716);
	// addi r30,r31,716
	r30.s64 = r31.s64 + 716;
	// rotlwi r10,r11,3
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 3);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// add r6,r11,r10
	ctx.r6.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r11,r6,4,0,27
	r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// add r5,r11,r4
	ctx.r5.u64 = r11.u64 + ctx.r4.u64;
	// bl 0x826c83c0
	ctx.lr = 0x826C84B4;
	sub_826C83C0(ctx, base);
	// lhz r5,728(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 728);
	// lwz r9,724(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 724);
	// addi r28,r31,724
	r28.s64 = r31.s64 + 724;
	// rotlwi r11,r5,2
	r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826c84ec
	if (cr6.eq) goto loc_826C84EC;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826C84D8:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826c84d8
	if (!cr6.eq) goto loc_826C84D8;
loc_826C84EC:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r28)
	ctx.r10.u64 = PPC_LOAD_U16(r28.u32 + 4);
	// addi r27,r31,732
	r27.s64 = r31.s64 + 732;
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r28)
	PPC_STORE_U16(r28.u32 + 4, ctx.r8.u16);
	// lwz r9,732(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 732);
	// lhz r6,736(r31)
	ctx.r6.u64 = PPC_LOAD_U16(r31.u32 + 736);
	// rotlwi r11,r6,2
	r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// cmplw cr6,r11,r11
	cr6.compare<uint32_t>(r11.u32, r11.u32, xer);
	// beq cr6,0x826c8538
	if (cr6.eq) goto loc_826C8538;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - r11.s64;
loc_826C8524:
	// lwz r7,0(r10)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stwx r7,r8,r10
	PPC_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r7.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r10,r11
	cr6.compare<uint32_t>(ctx.r10.u32, r11.u32, xer);
	// bne cr6,0x826c8524
	if (!cr6.eq) goto loc_826C8524;
loc_826C8538:
	// subf r11,r9,r11
	r11.s64 = r11.s64 - ctx.r9.s64;
	// lhz r10,4(r27)
	ctx.r10.u64 = PPC_LOAD_U16(r27.u32 + 4);
	// srawi r9,r11,2
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3) != 0);
	ctx.r9.s64 = r11.s32 >> 2;
	// subf r8,r9,r10
	ctx.r8.s64 = ctx.r10.s64 - ctx.r9.s64;
	// sth r8,4(r27)
	PPC_STORE_U16(r27.u32 + 4, ctx.r8.u16);
	// lwz r3,680(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 680);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c8564
	if (cr6.eq) goto loc_826C8564;
	// bl 0x821f8480
	ctx.lr = 0x826C855C;
	sub_821F8480(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r11,680(r31)
	PPC_STORE_U32(r31.u32 + 680, r11.u32);
loc_826C8564:
	// lhz r11,750(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 750);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c8578
	if (cr6.eq) goto loc_826C8578;
	// lwz r3,744(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 744);
	// bl 0x82130588
	ctx.lr = 0x826C8578;
	sub_82130588(ctx, base);
loc_826C8578:
	// lhz r11,6(r27)
	r11.u64 = PPC_LOAD_U16(r27.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c858c
	if (cr6.eq) goto loc_826C858C;
	// lwz r3,0(r27)
	ctx.r3.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826C858C;
	sub_82130588(ctx, base);
loc_826C858C:
	// lhz r11,6(r28)
	r11.u64 = PPC_LOAD_U16(r28.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c85a0
	if (cr6.eq) goto loc_826C85A0;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 0);
	// bl 0x82130588
	ctx.lr = 0x826C85A0;
	sub_82130588(ctx, base);
loc_826C85A0:
	// lhz r5,6(r30)
	ctx.r5.u64 = PPC_LOAD_U16(r30.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826c85b8
	if (cr6.eq) goto loc_826C85B8;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x826c6918
	ctx.lr = 0x826C85B8;
	sub_826C6918(ctx, base);
loc_826C85B8:
	// lhz r5,6(r29)
	ctx.r5.u64 = PPC_LOAD_U16(r29.u32 + 6);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826c85d0
	if (cr6.eq) goto loc_826C85D0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x826c6918
	ctx.lr = 0x826C85D0;
	sub_826C6918(ctx, base);
loc_826C85D0:
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// addi r10,r11,-21868
	ctx.r10.s64 = r11.s64 + -21868;
	// stw r10,0(r26)
	PPC_STORE_U32(r26.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826C85E4;
	sub_821D2028(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d9240
	return;
}

PPC_WEAK_FUNC(sub_826C8440) {
	__imp__sub_826C8440(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C85EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C85EC) {
	__imp__sub_826C85EC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C85F0) {
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
	// bl 0x826c8440
	ctx.lr = 0x826C8610;
	sub_826C8440(ctx, base);
	// clrlwi r11,r30,31
	r11.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c8628
	if (cr6.eq) goto loc_826C8628;
	// bl 0x82130588
	ctx.lr = 0x826C8624;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826C8628:
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

PPC_WEAK_FUNC(sub_826C85F0) {
	__imp__sub_826C85F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8640) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// subfic r3,r11,1
	xer.ca = r11.u32 <= 1;
	ctx.r3.s64 = 1 - r11.s64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8640) {
	__imp__sub_826C8640(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C864C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C864C) {
	__imp__sub_826C864C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8650) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32125
	ctx.r10.s64 = -2105344000;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r8,r11,-14604
	ctx.r8.s64 = r11.s64 + -14604;
	// addi r7,r10,-24968
	ctx.r7.s64 = ctx.r10.s64 + -24968;
	// addi r6,r9,-5040
	ctx.r6.s64 = ctx.r9.s64 + -5040;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r5,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// stb r4,16(r3)
	PPC_STORE_U8(ctx.r3.u32 + 16, ctx.r4.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8650) {
	__imp__sub_826C8650(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8688) {
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
	ctx.lr = 0x826C8690;
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
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C86AC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826C86C4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r29,r3
	cr6.compare<int32_t>(r29.s32, ctx.r3.s32, xer);
	// bne cr6,0x826c8714
	if (!cr6.eq) goto loc_826C8714;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r11,8(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826c86fc
	if (!cr6.eq) goto loc_826C86FC;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r9,8(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// cmpwi cr6,r9,2
	cr6.compare<int32_t>(ctx.r9.s32, 2, xer);
	// bne cr6,0x826c86fc
	if (!cr6.eq) goto loc_826C86FC;
	// lwz r10,32(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 32);
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// ble cr6,0x826c8708
	if (!cr6.gt) goto loc_826C8708;
loc_826C86FC:
	// li r3,-1
	ctx.r3.s64 = -1;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826C8708:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
loc_826C8714:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C8728;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826C8740;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpw cr6,r31,r3
	cr6.compare<int32_t>(r31.s32, ctx.r3.s32, xer);
	// li r3,-1
	ctx.r3.s64 = -1;
	// bgt cr6,0x826c8750
	if (cr6.gt) goto loc_826C8750;
	// li r3,1
	ctx.r3.s64 = 1;
loc_826C8750:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826C8688) {
	__imp__sub_826C8688(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8758) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826C8780;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x826c87a4
	if (cr6.gt) goto loc_826C87A4;
	// lis r11,32767
	r11.s64 = 2147418112;
	// ori r11,r11,65535
	r11.u64 = r11.u64 | 65535;
	// subfic r3,r11,1
	xer.ca = r11.u32 <= 1;
	ctx.r3.s64 = 1 - r11.s64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C87A4:
	// subfic r3,r3,1
	xer.ca = ctx.r3.u32 <= 1;
	ctx.r3.s64 = 1 - ctx.r3.s64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8758) {
	__imp__sub_826C8758(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C87B8) {
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
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
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
	ctx.lr = 0x826C87E8;
	sub_823DEDD8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c8804
	if (cr6.eq) goto loc_826C8804;
	// bl 0x822a5df8
	ctx.lr = 0x826C87F4;
	sub_822A5DF8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826C8804:
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

PPC_WEAK_FUNC(sub_826C87B8) {
	__imp__sub_826C87B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8818) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r10,3080(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3080);
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r11,0
	r11.s64 = 0;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826c886c
	if (!cr6.gt) goto loc_826C886C;
	// addi r9,r4,16
	ctx.r9.s64 = ctx.r4.s64 + 16;
loc_826C8830:
	// lwz r7,0(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x826c8850
	if (cr6.eq) goto loc_826C8850;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// blt cr6,0x826c8830
	if (cr6.lt) goto loc_826C8830;
	// b 0x826c886c
	goto loc_826C886C;
loc_826C8850:
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// addi r9,r11,172
	ctx.r9.s64 = r11.s64 + 172;
	// lwz r8,172(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 172);
	// stw r10,172(r11)
	PPC_STORE_U32(r11.u32 + 172, ctx.r10.u32);
loc_826C886C:
	// lwz r11,3080(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3080);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// blelr cr6
	if (!cr6.gt) return;
	// addi r11,r4,172
	r11.s64 = ctx.r4.s64 + 172;
loc_826C8880:
	// lwz r10,-156(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + -156);
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// beq cr6,0x826c88a0
	if (cr6.eq) goto loc_826C88A0;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// ble cr6,0x826c88a0
	if (!cr6.gt) goto loc_826C88A0;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
loc_826C88A0:
	// lwz r10,3080(r4)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r4.u32 + 3080);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,192
	r11.s64 = r11.s64 + 192;
	// cmpw cr6,r9,r10
	cr6.compare<int32_t>(ctx.r9.s32, ctx.r10.s32, xer);
	// blt cr6,0x826c8880
	if (cr6.lt) goto loc_826C8880;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8818) {
	__imp__sub_826C8818(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C88B8) {
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
	// rlwinm r3,r31,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x826C88D4;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826c8918
	if (!cr6.gt) goto loc_826C8918;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r10,r10,-5056
	ctx.r10.s64 = ctx.r10.s64 + -5056;
loc_826C88F4:
	// addic. r6,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r6.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq 0x826c890c
	if (cr0.eq) goto loc_826C890C;
	// stw r10,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r10.u32);
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_826C890C:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x826c88f4
	if (!cr0.eq) goto loc_826C88F4;
loc_826C8918:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C88B8) {
	__imp__sub_826C88B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C892C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C892C) {
	__imp__sub_826C892C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8930) {
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
	// rlwinm r3,r31,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(r31.u32 | (r31.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x82130528
	ctx.lr = 0x826C894C;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826c8990
	if (!cr6.gt) goto loc_826C8990;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r10,r10,-5104
	ctx.r10.s64 = ctx.r10.s64 + -5104;
loc_826C896C:
	// addic. r6,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r6.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq 0x826c8984
	if (cr0.eq) goto loc_826C8984;
	// stw r10,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r10.u32);
	// stw r7,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r7.u32);
	// stw r8,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r8.u32);
	// stw r9,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r9.u32);
loc_826C8984:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,16
	r11.s64 = r11.s64 + 16;
	// bne 0x826c896c
	if (!cr0.eq) goto loc_826C896C;
loc_826C8990:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8930) {
	__imp__sub_826C8930(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C89A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C89A4) {
	__imp__sub_826C89A4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C89A8) {
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
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x826C89CC;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826c8a18
	if (!cr6.gt) goto loc_826C8A18;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r9,r9,-5088
	ctx.r9.s64 = ctx.r9.s64 + -5088;
loc_826C89EC:
	// addic. r6,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r6.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq 0x826c8a0c
	if (cr0.eq) goto loc_826C8A0C;
	// stw r9,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r9.u32);
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_826C8A0C:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// bne 0x826c89ec
	if (!cr0.eq) goto loc_826C89EC;
loc_826C8A18:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C89A8) {
	__imp__sub_826C89A8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8A2C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C8A2C) {
	__imp__sub_826C8A2C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8A30) {
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
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bl 0x82130528
	ctx.lr = 0x826C8A54;
	sub_82130528(ctx, base);
	// cmpwi cr6,r31,0
	cr6.compare<int32_t>(r31.s32, 0, xer);
	// ble cr6,0x826c8aa0
	if (!cr6.gt) goto loc_826C8AA0;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r8,2
	ctx.r8.s64 = 2;
	// addi r9,r9,-5072
	ctx.r9.s64 = ctx.r9.s64 + -5072;
loc_826C8A74:
	// addic. r6,r11,-8
	xer.ca = r11.u32 > 7;
	ctx.r6.s64 = r11.s64 + -8;
	cr0.compare<int32_t>(ctx.r6.s32, 0, xer);
	// beq 0x826c8a94
	if (cr0.eq) goto loc_826C8A94;
	// stw r9,-8(r11)
	PPC_STORE_U32(r11.u32 + -8, ctx.r9.u32);
	// stw r10,-4(r11)
	PPC_STORE_U32(r11.u32 + -4, ctx.r10.u32);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stw r8,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r8.u32);
	// stw r10,8(r11)
	PPC_STORE_U32(r11.u32 + 8, ctx.r10.u32);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
loc_826C8A94:
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// addi r11,r11,24
	r11.s64 = r11.s64 + 24;
	// bne 0x826c8a74
	if (!cr0.eq) goto loc_826C8A74;
loc_826C8AA0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8A30) {
	__imp__sub_826C8A30(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C8AB4) {
	__imp__sub_826C8AB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8AB8) {
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
	// addi r9,r11,-5120
	ctx.r9.s64 = r11.s64 + -5120;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// beq cr6,0x826c8aec
	if (cr6.eq) goto loc_826C8AEC;
	// bl 0x82130588
	ctx.lr = 0x826C8AE8;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826C8AEC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8AB8) {
	__imp__sub_826C8AB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8B00) {
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
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,-10020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// addi r3,r11,340
	ctx.r3.s64 = r11.s64 + 340;
	// bl 0x8268c6d8
	ctx.lr = 0x826C8B24;
	sub_8268C6D8(ctx, base);
	// lwz r11,-10020(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -10020);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r11,340
	ctx.r3.s64 = r11.s64 + 340;
	// bl 0x8268ee10
	ctx.lr = 0x826C8B3C;
	sub_8268EE10(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8B00) {
	__imp__sub_826C8B00(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8B50) {
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
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,56(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 56);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826C8B88;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r8,32767
	ctx.r8.s64 = 2147418112;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// ori r7,r8,65535
	ctx.r7.u64 = ctx.r8.u64 | 65535;
	// cmpw cr6,r4,r7
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r7.s32, xer);
	// beq cr6,0x826c8bb0
	if (cr6.eq) goto loc_826C8BB0;
	// cmpwi cr6,r4,-1
	cr6.compare<int32_t>(ctx.r4.s32, -1, xer);
	// beq cr6,0x826c8bb0
	if (cr6.eq) goto loc_826C8BB0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8223de50
	ctx.lr = 0x826C8BAC;
	sub_8223DE50(ctx, base);
	// b 0x826c8c3c
	goto loc_826C8C3C;
loc_826C8BB0:
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
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
	ctx.lr = 0x826C8BD4;
	sub_823DEDD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82387a18
	ctx.lr = 0x826C8BDC;
	sub_82387A18(ctx, base);
	// clrlwi r8,r3,24
	ctx.r8.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// beq cr6,0x826c8c18
	if (cr6.eq) goto loc_826C8C18;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c8c18
	if (cr6.eq) goto loc_826C8C18;
	// lwz r3,1220(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 1220);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// beq cr6,0x826c8c18
	if (cr6.eq) goto loc_826C8C18;
	// li r4,5
	ctx.r4.s64 = 5;
	// bl 0x822577d0
	ctx.lr = 0x826C8C04;
	sub_822577D0(ctx, base);
	// cmplwi cr6,r3,1
	cr6.compare<uint32_t>(ctx.r3.u32, 1, xer);
	// bne cr6,0x826c8c18
	if (!cr6.eq) goto loc_826C8C18;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2064
	ctx.r4.s64 = ctx.r10.s64 + 2064;
	// b 0x826c8c20
	goto loc_826C8C20;
loc_826C8C18:
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r4,r10,2352
	ctx.r4.s64 = ctx.r10.s64 + 2352;
loc_826C8C20:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// bl 0x82218310
	ctx.lr = 0x826C8C2C;
	sub_82218310(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r5,128
	ctx.r5.s64 = 128;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823db670
	ctx.lr = 0x826C8C3C;
	sub_823DB670(ctx, base);
loc_826C8C3C:
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

PPC_WEAK_FUNC(sub_826C8B50) {
	__imp__sub_826C8B50(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8C54) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C8C54) {
	__imp__sub_826C8C54(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8C58) {
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
	ctx.lr = 0x826C8C60;
	// stwu r1,-1280(r1)
	ea = -1280 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lwz r11,4(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826C8C84;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// addi r28,r11,-12204
	r28.s64 = r11.s64 + -12204;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r6,r8,-5020
	ctx.r6.s64 = ctx.r8.s64 + -5020;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826C8CAC;
	sub_82137A08(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388580
	ctx.lr = 0x826C8CB4;
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
	ctx.lr = 0x826C8CC8;
	sub_82270170(ctx, base);
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// bl 0x824e70e0
	ctx.lr = 0x826C8CD0;
	sub_824E70E0(ctx, base);
	// clrlwi r5,r3,24
	ctx.r5.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// bne cr6,0x826c8d0c
	if (!cr6.eq) goto loc_826C8D0C;
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// bne cr6,0x826c8d0c
	if (!cr6.eq) goto loc_826C8D0C;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// addi r31,r11,-10244
	r31.s64 = r11.s64 + -10244;
	// addi r4,r10,24616
	ctx.r4.s64 = ctx.r10.s64 + 24616;
	// lwz r27,-10244(r11)
	r27.u64 = PPC_LOAD_U32(r11.u32 + -10244);
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82218310
	ctx.lr = 0x826C8D00;
	sub_82218310(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// b 0x826c8d2c
	goto loc_826C8D2C;
loc_826C8D0C:
	// li r5,1024
	ctx.r5.s64 = 1024;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// bl 0x823db670
	ctx.lr = 0x826C8D1C;
	sub_823DB670(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r31,r11,-10244
	r31.s64 = r11.s64 + -10244;
	// lwz r3,-10244(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10244);
loc_826C8D2C:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x822183b0
	ctx.lr = 0x826C8D34;
	sub_822183B0(ctx, base);
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C8D4C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// addi r6,r9,-5032
	ctx.r6.s64 = ctx.r9.s64 + -5032;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826C8D68;
	sub_82137A08(ctx, base);
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,0(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// bl 0x822183b0
	ctx.lr = 0x826C8D78;
	sub_822183B0(ctx, base);
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// b 0x823d9244
	return;
}

PPC_WEAK_FUNC(sub_826C8C58) {
	__imp__sub_826C8C58(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8D80) {
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
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lwz r10,4(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C8DA4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmpwi cr6,r6,100
	cr6.compare<int32_t>(ctx.r6.s32, 100, xer);
	// ble cr6,0x826c8dd0
	if (!cr6.gt) goto loc_826C8DD0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x8223de50
	ctx.lr = 0x826C8DBC;
	sub_8223DE50(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_826C8DD0:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r5,r11,32684
	ctx.r5.s64 = r11.s64 + 32684;
	// bl 0x82137a08
	ctx.lr = 0x826C8DE0;
	sub_82137A08(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826C8D80) {
	__imp__sub_826C8D80(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8DF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C8DF4) {
	__imp__sub_826C8DF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8DF8) {
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
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c8eb4
	if (cr6.eq) goto loc_826C8EB4;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826c8eb4
	if (cr6.eq) goto loc_826C8EB4;
	// addic. r31,r5,8
	xer.ca = ctx.r5.u32 > 4294967287;
	r31.s64 = ctx.r5.s64 + 8;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x826c8eb4
	if (cr0.eq) goto loc_826C8EB4;
	// lwz r11,3144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c8eb4
	if (!cr6.eq) goto loc_826C8EB4;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// bl 0x82256150
	ctx.lr = 0x826C8E38;
	sub_82256150(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8223de50
	ctx.lr = 0x826C8E44;
	sub_8223DE50(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,25364
	ctx.r4.s64 = r11.s64 + 25364;
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826C8E5C;
	sub_822183B0(ctx, base);
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a8a88
	ctx.lr = 0x826C8E64;
	sub_822A8A88(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c8e9c
	if (!cr6.eq) goto loc_826C8E9C;
	// lis r11,32767
	r11.s64 = 2147418112;
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r10,r11,65535
	ctx.r10.u64 = r11.u64 | 65535;
	// cmpw cr6,r4,r10
	cr6.compare<int32_t>(ctx.r4.s32, ctx.r10.s32, xer);
	// beq cr6,0x826c8e9c
	if (cr6.eq) goto loc_826C8E9C;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8223de50
	ctx.lr = 0x826C8E8C;
	sub_8223DE50(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r11,25328
	ctx.r4.s64 = r11.s64 + 25328;
	// b 0x826c8eac
	goto loc_826C8EAC;
loc_826C8E9C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r5,r11,-5008
	ctx.r5.s64 = r11.s64 + -5008;
	// addi r4,r10,25328
	ctx.r4.s64 = ctx.r10.s64 + 25328;
loc_826C8EAC:
	// lwz r3,-10244(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826C8EB4;
	sub_822183B0(ctx, base);
loc_826C8EB4:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
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

PPC_WEAK_FUNC(sub_826C8DF8) {
	__imp__sub_826C8DF8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C8ECC) {
	__imp__sub_826C8ECC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C8ED0) {
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
	ctx.lr = 0x826C8ED8;
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826c90ac
	if (cr6.eq) goto loc_826C90AC;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826c90ac
	if (cr6.eq) goto loc_826C90AC;
	// addic. r29,r28,8
	xer.ca = r28.u32 > 4294967287;
	r29.s64 = r28.s64 + 8;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x826c90ac
	if (cr0.eq) goto loc_826C90AC;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x82256150
	ctx.lr = 0x826C8F00;
	sub_82256150(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// bl 0x8223de50
	ctx.lr = 0x826C8F10;
	sub_8223DE50(ctx, base);
	// lis r31,-32121
	r31.s64 = -2105081856;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,25364
	ctx.r4.s64 = r11.s64 + 25364;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826C8F28;
	sub_822183B0(ctx, base);
	// lwz r3,8(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// bl 0x822a8a88
	ctx.lr = 0x826C8F30;
	sub_822A8A88(ctx, base);
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// bne cr6,0x826c8fc0
	if (!cr6.eq) goto loc_826C8FC0;
	// lbz r11,3773(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 3773);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826c8fc0
	if (cr6.eq) goto loc_826C8FC0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,40(r29)
	ctx.r4.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// bl 0x8223de50
	ctx.lr = 0x826C8F54;
	sub_8223DE50(ctx, base);
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r11,25328
	ctx.r4.s64 = r11.s64 + 25328;
	// bl 0x822183b0
	ctx.lr = 0x826C8F68;
	sub_822183B0(ctx, base);
	// lwz r10,40(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// subf r4,r30,r10
	ctx.r4.s64 = ctx.r10.s64 - r30.s64;
	// bl 0x8223de50
	ctx.lr = 0x826C8F78;
	sub_8223DE50(ctx, base);
	// lwz r9,40(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 40);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// subf. r8,r30,r9
	ctx.r8.s64 = ctx.r9.s64 - r30.s64;
	cr0.compare<int32_t>(ctx.r8.s32, 0, xer);
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// ble 0x826c8fa8
	if (!cr0.gt) goto loc_826C8FA8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r5,r11,-4988
	ctx.r5.s64 = r11.s64 + -4988;
	// bl 0x82137a08
	ctx.lr = 0x826C8F9C;
	sub_82137A08(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,-14284
	ctx.r4.s64 = r11.s64 + -14284;
	// b 0x826c9004
	goto loc_826C9004;
loc_826C8FA8:
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r5,r11,9572
	ctx.r5.s64 = r11.s64 + 9572;
	// bl 0x82137a08
	ctx.lr = 0x826C8FB4;
	sub_82137A08(ctx, base);
	// lis r11,-32247
	r11.s64 = -2113339392;
	// addi r4,r11,-14284
	ctx.r4.s64 = r11.s64 + -14284;
	// b 0x826c9004
	goto loc_826C9004;
loc_826C8FC0:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,8
	ctx.r5.s64 = 8;
	// addi r4,r11,-5008
	ctx.r4.s64 = r11.s64 + -5008;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db670
	ctx.lr = 0x826C8FD4;
	sub_823DB670(ctx, base);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// addi r4,r10,25328
	ctx.r4.s64 = ctx.r10.s64 + 25328;
	// bl 0x822183b0
	ctx.lr = 0x826C8FE8;
	sub_822183B0(ctx, base);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r9,3998
	ctx.r4.s64 = ctx.r9.s64 + 3998;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db670
	ctx.lr = 0x826C8FFC;
	sub_823DB670(ctx, base);
	// lis r8,-32247
	ctx.r8.s64 = -2113339392;
	// addi r4,r8,-14284
	ctx.r4.s64 = ctx.r8.s64 + -14284;
loc_826C9004:
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r3,-10244(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826C9010;
	sub_822183B0(ctx, base);
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r11,r11,-16
	r11.s64 = r11.s64 + -16;
	// bne cr6,0x826c902c
	if (!cr6.eq) goto loc_826C902C;
	// li r11,0
	r11.s64 = 0;
loc_826C902C:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,4120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4120);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,7444(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826c9048
	if (!cr6.gt) goto loc_826C9048;
	// fmr f11,f0
	ctx.f11.f64 = f0.f64;
	// b 0x826c904c
	goto loc_826C904C;
loc_826C9048:
	// fmr f11,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f13.f64;
loc_826C904C:
	// lfs f13,4112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// ble cr6,0x826c9060
	if (!cr6.gt) goto loc_826C9060;
	// fmr f12,f0
	ctx.f12.f64 = f0.f64;
	// b 0x826c9064
	goto loc_826C9064;
loc_826C9060:
	// fmr f12,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f13.f64;
loc_826C9064:
	// lfs f13,4116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4116);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	cr6.compare(ctx.f13.f64, f0.f64);
	// bgt cr6,0x826c9074
	if (cr6.gt) goto loc_826C9074;
	// fmr f0,f13
	f0.f64 = ctx.f13.f64;
loc_826C9074:
	// fadds f12,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(f0.f64 + ctx.f12.f64));
	// lis r11,-32256
	r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// addi r3,r9,-5004
	ctx.r3.s64 = ctx.r9.s64 + -5004;
	// lfs f0,32688(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 32688);
	f0.f64 = double(temp.f32);
	// lfs f13,31016(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 31016);
	ctx.f13.f64 = double(temp.f32);
	// fadds f11,f12,f11
	ctx.f11.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fmuls f10,f11,f0
	ctx.f10.f64 = double(float(ctx.f11.f64 * f0.f64));
	// fmuls f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 * ctx.f13.f64));
	// fctiwz f8,f9
	ctx.f8.s64 = (ctx.f9.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f8,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f8.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82218838
	ctx.lr = 0x826C90AC;
	sub_82218838(ctx, base);
loc_826C90AC:
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C8ED0) {
	__imp__sub_826C8ED0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C90B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C90B4) {
	__imp__sub_826C90B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C90B8) {
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
	PPCRegister f0{};
	PPCRegister f31{};
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f8
	ctx.lr = 0x826C90C0;
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826c934c
	if (cr6.eq) goto loc_826C934C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c934c
	if (cr6.eq) goto loc_826C934C;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// addi r3,r11,-29360
	ctx.r3.s64 = r11.s64 + -29360;
	// bl 0x821fa230
	ctx.lr = 0x826C90EC;
	sub_821FA230(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r4,r10,-17032
	ctx.r4.s64 = ctx.r10.s64 + -17032;
	// bl 0x8268e5b8
	ctx.lr = 0x826C90F8;
	sub_8268E5B8(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268daf8
	ctx.lr = 0x826C9104;
	sub_8268DAF8(ctx, base);
	// addic. r31,r28,-1
	xer.ca = r28.u32 > 0;
	r31.s64 = r28.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// ble 0x826c911c
	if (!cr0.gt) goto loc_826C911C;
loc_826C910C:
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268db80
	ctx.lr = 0x826C9114;
	sub_8268DB80(ctx, base);
	// addic. r31,r31,-1
	xer.ca = r31.u32 > 0;
	r31.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// bne 0x826c910c
	if (!cr0.eq) goto loc_826C910C;
loc_826C911C:
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r5,3100(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 3100);
	// li r6,20
	ctx.r6.s64 = 20;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,18508(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 18508);
	// bl 0x826b96c8
	ctx.lr = 0x826C9134;
	sub_826B96C8(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	f31.f64 = ctx.f1.f64;
	// bl 0x8268db80
	ctx.lr = 0x826C9140;
	sub_8268DB80(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// blt cr6,0x826c91c8
	if (cr6.lt) goto loc_826C91C8;
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
	// bge cr6,0x826c91cc
	if (!cr6.lt) goto loc_826C91CC;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,128
	ctx.r5.s64 = 128;
	// addi r4,r11,-4920
	ctx.r4.s64 = r11.s64 + -4920;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db670
	ctx.lr = 0x826C9168;
	sub_823DB670(ctx, base);
	// cmpwi cr6,r28,0
	cr6.compare<int32_t>(r28.s32, 0, xer);
	// bne cr6,0x826c9188
	if (!cr6.eq) goto loc_826C9188;
	// lis r10,-32121
	ctx.r10.s64 = -2105081856;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r31,r11,-14304
	r31.s64 = r11.s64 + -14304;
	// lwz r3,-10244(r10)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + -10244);
	// b 0x826c9314
	goto loc_826C9314;
loc_826C9188:
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bl 0x8238f1e8
	ctx.lr = 0x826C9194;
	sub_8238F1E8(ctx, base);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// mulli r7,r3,104
	ctx.r7.s64 = ctx.r3.s64 * 104;
	// lfs f0,17032(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 17032);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lwz r11,-12120(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -12120);
	// lis r8,-32121
	ctx.r8.s64 = -2105081856;
	// lwzx r31,r7,r11
	r31.u64 = PPC_LOAD_U32(ctx.r7.u32 + r11.u32);
	// lwz r3,-10244(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + -10244);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x826c9314
	goto loc_826C9314;
loc_826C91C8:
	// cmpwi cr6,r28,2
	cr6.compare<int32_t>(r28.s32, 2, xer);
loc_826C91CC:
	// lwz r11,200(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 200);
	// lwz r3,52(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 52);
	// bne cr6,0x826c9224
	if (!cr6.eq) goto loc_826C9224;
	// bl 0x8238f1e8
	ctx.lr = 0x826C91DC;
	sub_8238F1E8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r9,r3,104
	ctx.r9.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12120);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addi r4,r8,-4936
	ctx.r4.s64 = ctx.r8.s64 + -4936;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db670
	ctx.lr = 0x826C9200;
	sub_823DB670(ctx, base);
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lfs f0,-6172(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -6172);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lwz r3,-10244(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10244);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x826c9314
	goto loc_826C9314;
loc_826C9224:
	// cmpwi cr6,r28,3
	cr6.compare<int32_t>(r28.s32, 3, xer);
	// bne cr6,0x826c9278
	if (!cr6.eq) goto loc_826C9278;
	// bl 0x8238f1e8
	ctx.lr = 0x826C9230;
	sub_8238F1E8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r9,r3,104
	ctx.r9.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12120);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addi r4,r8,-4952
	ctx.r4.s64 = ctx.r8.s64 + -4952;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db670
	ctx.lr = 0x826C9254;
	sub_823DB670(ctx, base);
	// lis r7,-32256
	ctx.r7.s64 = -2113929216;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lfs f0,31308(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + 31308);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lwz r3,-10244(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10244);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x826c9314
	goto loc_826C9314;
loc_826C9278:
	// cmpwi cr6,r28,4
	cr6.compare<int32_t>(r28.s32, 4, xer);
	// bne cr6,0x826c92cc
	if (!cr6.eq) goto loc_826C92CC;
	// bl 0x8238f1e8
	ctx.lr = 0x826C9284;
	sub_8238F1E8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r9,r3,104
	ctx.r9.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12120);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addi r4,r8,-4968
	ctx.r4.s64 = ctx.r8.s64 + -4968;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db670
	ctx.lr = 0x826C92A8;
	sub_823DB670(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lfs f0,-29232(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -29232);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lwz r3,-10244(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10244);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// b 0x826c9314
	goto loc_826C9314;
loc_826C92CC:
	// bl 0x8238f1e8
	ctx.lr = 0x826C92D0;
	sub_8238F1E8(ctx, base);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// mulli r9,r3,104
	ctx.r9.s64 = ctx.r3.s64 * 104;
	// lwz r11,-12120(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + -12120);
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r5,128
	ctx.r5.s64 = 128;
	// lwzx r31,r9,r11
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// addi r4,r8,-4984
	ctx.r4.s64 = ctx.r8.s64 + -4984;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823db670
	ctx.lr = 0x826C92F4;
	sub_823DB670(ctx, base);
	// lis r7,-32255
	ctx.r7.s64 = -2113863680;
	// lis r5,-32121
	ctx.r5.s64 = -2105081856;
	// lfs f0,-332(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r7.u32 + -332);
	f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	f0.f64 = double(float(f31.f64 * f0.f64));
	// lwz r3,-10244(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + -10244);
	// fctiwz f13,f0
	ctx.f13.s64 = (f0.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&f0.f64));
	// stfd f13,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
loc_826C9314:
	// li r6,1
	ctx.r6.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82218788
	ctx.lr = 0x826C9320;
	sub_82218788(ctx, base);
	// li r11,5
	r11.s64 = 5;
	// stw r31,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, r31.u32);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, r11.u32);
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// lwz r9,0(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addi r4,r10,-27360
	ctx.r4.s64 = ctx.r10.s64 + -27360;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwz r8,200(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 200);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826C934C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
loc_826C934C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826C90B8) {
	__imp__sub_826C90B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C9358) {
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
	PPCRegister f25{};
	PPCRegister f26{};
	PPCRegister f27{};
	PPCRegister f28{};
	PPCRegister f29{};
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
	// bl 0x823d91e0
	ctx.lr = 0x826C9360;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823db9cc
	ctx.lr = 0x826C9368;
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// bl 0x82387a18
	ctx.lr = 0x826C9374;
	sub_82387A18(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826c98d4
	if (!cr6.eq) goto loc_826C98D4;
	// lwz r7,3088(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 3088);
	// li r22,-1
	r22.s64 = -1;
	// addi r27,r30,8
	r27.s64 = r30.s64 + 8;
	// mr r28,r22
	r28.u64 = r22.u64;
	// li r8,1000
	ctx.r8.s64 = 1000;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x826c975c
	if (!cr6.gt) goto loc_826C975C;
	// lis r11,32767
	r11.s64 = 2147418112;
	// addi r9,r27,40
	ctx.r9.s64 = r27.s64 + 40;
	// ori r23,r11,65535
	r23.u64 = r11.u64 | 65535;
loc_826C93AC:
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// beq cr6,0x826c93e0
	if (cr6.eq) goto loc_826C93E0;
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826c93e0
	if (cr6.eq) goto loc_826C93E0;
	// lwz r11,-24(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -24);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826c93f4
	if (cr6.eq) goto loc_826C93F4;
	// lwz r11,132(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 132);
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// ble cr6,0x826c93e0
	if (!cr6.gt) goto loc_826C93E0;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_826C93E0:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x826c93ac
	if (cr6.lt) goto loc_826C93AC;
	// b 0x826c93f8
	goto loc_826C93F8;
loc_826C93F4:
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
loc_826C93F8:
	// cmpwi cr6,r28,-1
	cr6.compare<int32_t>(r28.s32, -1, xer);
	// beq cr6,0x826c975c
	if (cr6.eq) goto loc_826C975C;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x823eaef8
	ctx.lr = 0x826C9408;
	sub_823EAEF8(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// bl 0x82640ad8
	ctx.lr = 0x826C9410;
	sub_82640AD8(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x822561a0
	ctx.lr = 0x826C9420;
	sub_822561A0(ctx, base);
	// lwz r11,3116(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3116);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,1
	cr6.compare<int32_t>(r11.s32, 1, xer);
	// bge cr6,0x826c9438
	if (!cr6.lt) goto loc_826C9438;
	// li r8,1
	ctx.r8.s64 = 1;
	// b 0x826c9448
	goto loc_826C9448;
loc_826C9438:
	// cmpwi cr6,r11,100
	cr6.compare<int32_t>(r11.s32, 100, xer);
	// li r8,100
	ctx.r8.s64 = 100;
	// bgt cr6,0x826c9448
	if (cr6.gt) goto loc_826C9448;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
loc_826C9448:
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,4(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// li r7,64
	ctx.r7.s64 = 64;
	// add r9,r28,r11
	ctx.r9.u64 = r28.u64 + r11.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// rlwinm r11,r9,6,0,25
	r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// li r25,192
	r25.s64 = 192;
	// add r26,r11,r27
	r26.u64 = r11.u64 + r27.u64;
	// lvx128 v63,r10,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r5
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r5.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r11,r31,-1
	xer.ca = r31.u32 > 0;
	r11.s64 = r31.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// lfs f26,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f26.f64 = double(temp.f32);
	// lfs f25,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	f25.f64 = double(temp.f32);
	// lwz r4,8(r26)
	ctx.r4.u64 = PPC_LOAD_U32(r26.u32 + 8);
	// lfs f27,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	f27.f64 = double(temp.f32);
	// lvx128 v62,r4,r25
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r4.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,104(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,100(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f27
	ctx.f11.f64 = double(float(ctx.f12.f64 - f27.f64));
	// fsubs f10,f0,f26
	ctx.f10.f64 = double(float(f0.f64 - f26.f64));
	// fmuls f9,f11,f11
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fsubs f8,f13,f25
	ctx.f8.f64 = double(float(ctx.f13.f64 - f25.f64));
	// fmadds f7,f10,f10,f9
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fmadds f6,f8,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fsqrts f0,f6
	f0.f64 = double(float(sqrt(ctx.f6.f64)));
	// ble 0x826c950c
	if (!cr0.gt) goto loc_826C950C;
	// rotlwi r9,r10,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// addi r11,r9,436
	r11.s64 = ctx.r9.s64 + 436;
loc_826C94C8:
	// lfs f13,-368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -368);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f10,-364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -364);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,-372(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -372);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// addi r11,r11,368
	r11.s64 = r11.s64 + 368;
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fadds f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 + f0.f64));
	// bne 0x826c94c8
	if (!cr0.eq) goto loc_826C94C8;
loc_826C950C:
	// extsw r11,r8
	r11.s64 = ctx.r8.s32;
	// lwz r10,3080(r27)
	ctx.r10.u64 = PPC_LOAD_U32(r27.u32 + 3080);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// std r11,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// li r30,0
	r30.s64 = 0;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f29,3796(r9)
	temp.u32 = PPC_LOAD_U32(ctx.r9.u32 + 3796);
	f29.f64 = double(temp.f32);
	// fmr f31,f29
	f31.f64 = f29.f64;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// fmuls f30,f11,f0
	f30.f64 = double(float(ctx.f11.f64 * f0.f64));
	// ble cr6,0x826c98d4
	if (!cr6.gt) goto loc_826C98D4;
	// lis r11,-32256
	r11.s64 = -2113929216;
	// addi r31,r27,32
	r31.s64 = r27.s64 + 32;
	// lfs f28,7444(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 7444);
	f28.f64 = double(temp.f32);
loc_826C954C:
	// cmpw cr6,r30,r28
	cr6.compare<int32_t>(r30.s32, r28.s32, xer);
	// beq cr6,0x826c9738
	if (cr6.eq) goto loc_826C9738;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// cmpw cr6,r11,r23
	cr6.compare<int32_t>(r11.s32, r23.s32, xer);
	// bne cr6,0x826c9738
	if (!cr6.eq) goto loc_826C9738;
	// lwz r11,-16(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + -16);
	// cmpwi cr6,r11,2
	cr6.compare<int32_t>(r11.s32, 2, xer);
	// bne cr6,0x826c9734
	if (!cr6.eq) goto loc_826C9734;
	// lwz r3,-24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24);
	// bl 0x822a8338
	ctx.lr = 0x826C9574;
	sub_822A8338(ctx, base);
	// cmpwi cr6,r3,1
	cr6.compare<int32_t>(ctx.r3.s32, 1, xer);
	// beq cr6,0x826c9734
	if (cr6.eq) goto loc_826C9734;
	// lwz r11,140(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 140);
	// lwz r10,172(r26)
	ctx.r10.u64 = PPC_LOAD_U32(r26.u32 + 172);
	// cmpw cr6,r11,r10
	cr6.compare<int32_t>(r11.s32, ctx.r10.s32, xer);
	// ble cr6,0x826c9738
	if (!cr6.gt) goto loc_826C9738;
	// lwz r10,-24(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + -24);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// lwz r8,48(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 48);
	// ble cr6,0x826c969c
	if (!cr6.gt) goto loc_826C969C;
	// addi r11,r1,112
	r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r24
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((r24.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r10,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	ctx.r10.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// stvx128 v61,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	f0.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,116(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f12,f27
	ctx.f11.f64 = double(float(ctx.f12.f64 - f27.f64));
	// fsubs f10,f0,f26
	ctx.f10.f64 = double(float(f0.f64 - f26.f64));
	// fmuls f9,f11,f11
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fsubs f8,f13,f25
	ctx.f8.f64 = double(float(ctx.f13.f64 - f25.f64));
	// fmadds f7,f10,f10,f9
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f9.f64));
	// fmadds f6,f8,f8,f7
	ctx.f6.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f7.f64));
	// fsqrts f0,f6
	f0.f64 = double(float(sqrt(ctx.f6.f64)));
	// ble 0x826c9630
	if (!cr0.gt) goto loc_826C9630;
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// rotlwi r10,r9,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// addi r11,r11,436
	r11.s64 = r11.s64 + 436;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_826C95EC:
	// lfs f13,-368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(r11.u32 + -368);
	ctx.f13.f64 = double(temp.f32);
	// addic. r10,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(ctx.r10.s32, 0, xer);
	// lfs f12,0(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f11,f13,f12
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f10,-364(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -364);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 4);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f10,f9
	ctx.f8.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f7,-372(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -372);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,-4(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -4);
	ctx.f6.f64 = double(temp.f32);
	// addi r11,r11,368
	r11.s64 = r11.s64 + 368;
	// fsubs f5,f7,f6
	ctx.f5.f64 = double(float(ctx.f7.f64 - ctx.f6.f64));
	// fmuls f4,f11,f11
	ctx.f4.f64 = double(float(ctx.f11.f64 * ctx.f11.f64));
	// fmadds f3,f8,f8,f4
	ctx.f3.f64 = double(float(ctx.f8.f64 * ctx.f8.f64 + ctx.f4.f64));
	// fmadds f2,f5,f5,f3
	ctx.f2.f64 = double(float(ctx.f5.f64 * ctx.f5.f64 + ctx.f3.f64));
	// fsqrts f1,f2
	ctx.f1.f64 = double(float(sqrt(ctx.f2.f64)));
	// fadds f0,f1,f0
	f0.f64 = double(float(ctx.f1.f64 + f0.f64));
	// bne 0x826c95ec
	if (!cr0.eq) goto loc_826C95EC;
loc_826C9630:
	// lwz r11,4(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 4);
	// mulli r9,r9,368
	ctx.r9.s64 = ctx.r9.s64 * 368;
	// lwz r10,28(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// lwz r8,4(r31)
	ctx.r8.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// lfs f13,68(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,72(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 72);
	ctx.f12.f64 = double(temp.f32);
	// add r11,r9,r11
	r11.u64 = ctx.r9.u64 + r11.u64;
	// lfs f11,64(r10)
	temp.u32 = PPC_LOAD_U32(ctx.r10.u32 + 64);
	ctx.f11.f64 = double(temp.f32);
	// addi r10,r8,1
	ctx.r10.s64 = ctx.r8.s64 + 1;
	// addi r9,r11,-304
	ctx.r9.s64 = r11.s64 + -304;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// lfs f10,-300(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -300);
	ctx.f10.f64 = double(temp.f32);
	// std r9,80(r1)
	PPC_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// fsubs f9,f10,f13
	ctx.f9.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// lfs f8,-296(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -296);
	ctx.f8.f64 = double(temp.f32);
	// fsubs f7,f8,f12
	ctx.f7.f64 = double(float(ctx.f8.f64 - ctx.f12.f64));
	// lfs f6,-304(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + -304);
	ctx.f6.f64 = double(temp.f32);
	// lfd f5,80(r1)
	ctx.f5.u64 = PPC_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// fmuls f3,f9,f9
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f9.f64));
	// fsubs f2,f6,f11
	ctx.f2.f64 = double(float(ctx.f6.f64 - ctx.f11.f64));
	// frsp f1,f4
	ctx.f1.f64 = double(float(ctx.f4.f64));
	// fmadds f13,f7,f7,f3
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f7.f64 + ctx.f3.f64));
	// fmuls f31,f1,f0
	f31.f64 = double(float(ctx.f1.f64 * f0.f64));
	// fmadds f12,f2,f2,f13
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f2.f64 + ctx.f13.f64));
	// fsqrts f0,f12
	f0.f64 = double(float(sqrt(ctx.f12.f64)));
	// b 0x826c96e0
	goto loc_826C96E0;
loc_826C969C:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r10,r25
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r10.u32 + r25.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,28(r8)
	r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 28);
	// stvx128 v60,r0,r9
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f7,136(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	ctx.f7.f64 = double(temp.f32);
	// lfs f0,68(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 68);
	f0.f64 = double(temp.f32);
	// lfs f9,132(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f9.f64 = double(temp.f32);
	// fsubs f8,f9,f0
	ctx.f8.f64 = double(float(ctx.f9.f64 - f0.f64));
	// lfs f13,72(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 72);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f5,f8,f8
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fsubs f6,f7,f13
	ctx.f6.f64 = double(float(ctx.f7.f64 - ctx.f13.f64));
	// lfs f12,64(r11)
	temp.u32 = PPC_LOAD_U32(r11.u32 + 64);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,128(r1)
	temp.u32 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 - ctx.f12.f64));
	// fmadds f4,f6,f6,f5
	ctx.f4.f64 = double(float(ctx.f6.f64 * ctx.f6.f64 + ctx.f5.f64));
	// fmadds f3,f10,f10,f4
	ctx.f3.f64 = double(float(ctx.f10.f64 * ctx.f10.f64 + ctx.f4.f64));
	// fsqrts f0,f3
	f0.f64 = double(float(sqrt(ctx.f3.f64)));
loc_826C96E0:
	// fadds f13,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(f0.f64 + f31.f64));
	// fcmpu cr6,f13,f30
	cr6.compare(ctx.f13.f64, f30.f64);
	// ble cr6,0x826c96f4
	if (!cr6.gt) goto loc_826C96F4;
	// fmr f31,f29
	f31.f64 = f29.f64;
	// fmr f0,f29
	f0.f64 = f29.f64;
loc_826C96F4:
	// lwz r11,40(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + 40);
	// fadds f0,f0,f31
	ctx.fpscr.disableFlushMode();
	f0.f64 = double(float(f0.f64 + f31.f64));
	// extsw r10,r11
	ctx.r10.s64 = r11.s32;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// fdivs f11,f0,f30
	ctx.f11.f64 = double(float(f0.f64 / f30.f64));
	// fsubs f9,f28,f11
	ctx.f9.f64 = double(float(f28.f64 - ctx.f11.f64));
	// lfd f13,88(r1)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f10,f12
	ctx.f10.f64 = double(float(ctx.f12.f64));
	// fmuls f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 * ctx.f10.f64));
	// fctiwz f7,f8
	ctx.f7.s64 = (ctx.f8.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f7.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + r11.u64;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// b 0x826c9738
	goto loc_826C9738;
loc_826C9734:
	// stw r22,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r22.u32);
loc_826C9738:
	// lwz r11,3080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3080);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826c954c
	if (cr6.lt) goto loc_826C954C;
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba18
	ctx.lr = 0x826C9758;
	// b 0x823d9230
	return;
loc_826C975C:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// ble cr6,0x826c979c
	if (!cr6.gt) goto loc_826C979C;
	// addi r9,r27,172
	ctx.r9.s64 = r27.s64 + 172;
loc_826C976C:
	// lwz r11,-156(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826c978c
	if (cr6.eq) goto loc_826C978C;
	// lwz r11,0(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r8,r11
	cr6.compare<int32_t>(ctx.r8.s32, r11.s32, xer);
	// ble cr6,0x826c978c
	if (!cr6.gt) goto loc_826C978C;
	// mr r8,r11
	ctx.r8.u64 = r11.u64;
	// mr r28,r10
	r28.u64 = ctx.r10.u64;
loc_826C978C:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// cmpw cr6,r10,r7
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, xer);
	// blt cr6,0x826c976c
	if (cr6.lt) goto loc_826C976C;
loc_826C979C:
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826c9814
	if (cr6.eq) goto loc_826C9814;
	// lis r11,-32120
	r11.s64 = -2105016320;
	// lwz r3,-27856(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -27856);
	// bl 0x8238ec00
	ctx.lr = 0x826C97B4;
	sub_8238EC00(ctx, base);
	// rlwinm r10,r28,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,0(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 0);
	// lwz r8,44(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// add r9,r28,r10
	ctx.r9.u64 = r28.u64 + ctx.r10.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r9,6,0,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0xFFFFFFC0;
	// add r7,r11,r10
	ctx.r7.u64 = r11.u64 + ctx.r10.u64;
	// add r31,r9,r27
	r31.u64 = ctx.r9.u64 + r27.u64;
	// rlwinm r11,r7,5,0,26
	r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// add r30,r11,r8
	r30.u64 = r11.u64 + ctx.r8.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a9120
	ctx.lr = 0x826C97E4;
	sub_822A9120(ctx, base);
	// lis r6,-32256
	ctx.r6.s64 = -2113929216;
	// lwz r5,136(r30)
	ctx.r5.u64 = PPC_LOAD_U32(r30.u32 + 136);
	// lis r4,-32244
	ctx.r4.s64 = -2113142784;
	// lfs f0,7444(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r6.u32 + 7444);
	f0.f64 = double(temp.f32);
	// fsubs f13,f0,f1
	ctx.f13.f64 = double(float(f0.f64 - ctx.f1.f64));
	// lfs f0,-4904(r4)
	temp.u32 = PPC_LOAD_U32(ctx.r4.u32 + -4904);
	f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * f0.f64));
	// fctiwz f11,f12
	ctx.f11.s64 = (ctx.f12.f64 > double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f11,96(r1)
	PPC_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// subf r11,r3,r5
	r11.s64 = ctx.r5.s64 - ctx.r3.s64;
	// stw r11,40(r31)
	PPC_STORE_U32(r31.u32 + 40, r11.u32);
loc_826C9814:
	// lwz r11,3080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3080);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826c98d4
	if (!cr6.gt) goto loc_826C98D4;
	// lis r11,1
	r11.s64 = 65536;
	// lis r10,23772
	ctx.r10.s64 = 1557921792;
	// lis r8,4194
	ctx.r8.s64 = 274857984;
	// addi r9,r27,172
	ctx.r9.s64 = r27.s64 + 172;
	// ori r5,r11,27768
	ctx.r5.u64 = r11.u64 | 27768;
	// lis r4,-32121
	ctx.r4.s64 = -2105081856;
	// ori r6,r10,64167
	ctx.r6.u64 = ctx.r10.u64 | 64167;
	// ori r7,r8,19923
	ctx.r7.u64 = ctx.r8.u64 | 19923;
loc_826C9844:
	// cmpw cr6,r3,r28
	cr6.compare<int32_t>(ctx.r3.s32, r28.s32, xer);
	// beq cr6,0x826c98c0
	if (cr6.eq) goto loc_826C98C0;
	// lwz r11,-156(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826c98c0
	if (cr6.eq) goto loc_826C98C0;
	// lwz r11,-10020(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + -10020);
	// add r31,r11,r5
	r31.u64 = r11.u64 + ctx.r5.u64;
	// rlwinm r11,r28,1,0,30
	r11.u64 = __builtin_rotateleft64(r28.u32 | (r28.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r28,r11
	r11.u64 = r28.u64 + r11.u64;
	// lwz r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r8,r11,6,0,25
	ctx.r8.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// mulld r10,r10,r6
	ctx.r10.s64 = ctx.r10.s64 * ctx.r6.s64;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// add r8,r8,r27
	ctx.r8.u64 = ctx.r8.u64 + r27.u64;
	// rldicl r30,r11,32,32
	r30.u64 = __builtin_rotateleft64(r11.u64, 32) & 0xFFFFFFFF;
	// clrlwi r29,r11,1
	r29.u64 = r11.u32 & 0x7FFFFFFF;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// mulhw r11,r29,r7
	r11.s64 = (int64_t(r29.s32) * int64_t(ctx.r7.s32)) >> 32;
	// srawi r10,r11,6
	xer.ca = (r11.s32 < 0) & ((r11.u32 & 0x3F) != 0);
	ctx.r10.s64 = r11.s32 >> 6;
	// rlwinm r11,r10,1,31,31
	r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// lwz r10,40(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// lwz r31,0(r9)
	r31.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mulli r8,r11,1000
	ctx.r8.s64 = r11.s64 * 1000;
	// subf r11,r8,r29
	r11.s64 = r29.s64 - ctx.r8.s64;
	// mulli r8,r31,6000
	ctx.r8.s64 = r31.s64 * 6000;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r11,r11,r8
	r11.u64 = r11.u64 + ctx.r8.u64;
	// stw r11,-132(r9)
	PPC_STORE_U32(ctx.r9.u32 + -132, r11.u32);
loc_826C98C0:
	// lwz r11,3080(r27)
	r11.u64 = PPC_LOAD_U32(r27.u32 + 3080);
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r9,r9,192
	ctx.r9.s64 = ctx.r9.s64 + 192;
	// cmpw cr6,r3,r11
	cr6.compare<int32_t>(ctx.r3.s32, r11.s32, xer);
	// blt cr6,0x826c9844
	if (cr6.lt) goto loc_826C9844;
loc_826C98D4:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// addi r12,r1,-88
	r12.s64 = ctx.r1.s64 + -88;
	// bl 0x823dba18
	ctx.lr = 0x826C98E0;
	// b 0x823d9230
	return;
}

PPC_WEAK_FUNC(sub_826C9358) {
	__imp__sub_826C9358(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C98E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C98E4) {
	__imp__sub_826C98E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C98E8) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x826C98F0;
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
	// bne cr6,0x826c99ac
	if (!cr6.eq) goto loc_826C99AC;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x826c88b8
	ctx.lr = 0x826C9918;
	sub_826C88B8(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c9968
	if (cr6.eq) goto loc_826C9968;
	// li r9,0
	ctx.r9.s64 = 0;
loc_826C992C:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// blt cr6,0x826c992c
	if (cr6.lt) goto loc_826C992C;
loc_826C9968:
	// lhz r29,4(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x826c99a0
	if (!cr6.gt) goto loc_826C99A0;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_826C997C:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C9994;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x826c997c
	if (!cr0.eq) goto loc_826C997C;
loc_826C99A0:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x826C99A8;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_826C99AC:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,4
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 4);
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

PPC_WEAK_FUNC(sub_826C98E8) {
	__imp__sub_826C98E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C99CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C99CC) {
	__imp__sub_826C99CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C99D0) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91f4
	ctx.lr = 0x826C99D8;
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
	// bne cr6,0x826c9a94
	if (!cr6.eq) goto loc_826C9A94;
	// add r11,r11,r4
	r11.u64 = r11.u64 + ctx.r4.u64;
	// clrlwi r4,r11,16
	ctx.r4.u64 = r11.u32 & 0xFFFF;
	// sth r4,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r4.u16);
	// bl 0x826c8930
	ctx.lr = 0x826C9A00;
	sub_826C8930(ctx, base);
	// lhz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r10,0
	cr6.compare<uint32_t>(ctx.r10.u32, 0, xer);
	// beq cr6,0x826c9a50
	if (cr6.eq) goto loc_826C9A50;
	// li r9,0
	ctx.r9.s64 = 0;
loc_826C9A14:
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rlwinm r10,r9,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// add r11,r10,r11
	r11.u64 = ctx.r10.u64 + r11.u64;
	// add r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 + r28.u64;
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 8);
	// stw r7,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// lwz r6,12(r11)
	ctx.r6.u64 = PPC_LOAD_U32(r11.u32 + 12);
	// stw r6,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r6.u32);
	// lhz r5,4(r31)
	ctx.r5.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// cmplw cr6,r9,r5
	cr6.compare<uint32_t>(ctx.r9.u32, ctx.r5.u32, xer);
	// blt cr6,0x826c9a14
	if (cr6.lt) goto loc_826C9A14;
loc_826C9A50:
	// lhz r29,4(r31)
	r29.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// cmpwi cr6,r29,0
	cr6.compare<int32_t>(r29.s32, 0, xer);
	// ble cr6,0x826c9a88
	if (!cr6.gt) goto loc_826C9A88;
	// mr r30,r27
	r30.u64 = r27.u64;
loc_826C9A64:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C9A7C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r29,r29,-1
	xer.ca = r29.u32 > 0;
	r29.s64 = r29.s64 + -1;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// addi r30,r30,16
	r30.s64 = r30.s64 + 16;
	// bne 0x826c9a64
	if (!cr0.eq) goto loc_826C9A64;
loc_826C9A88:
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// bl 0x82130588
	ctx.lr = 0x826C9A90;
	sub_82130588(ctx, base);
	// stw r28,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r28.u32);
loc_826C9A94:
	// lhz r11,4(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 4);
	// lwz r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// rotlwi r10,r11,4
	ctx.r10.u64 = __builtin_rotateleft32(r11.u32, 4);
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

PPC_WEAK_FUNC(sub_826C99D0) {
	__imp__sub_826C99D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C9AB4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826C9AB4) {
	__imp__sub_826C9AB4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C9AB8) {
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
	// bne cr6,0x826c9afc
	if (!cr6.eq) goto loc_826C9AFC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x826c9af4
	if (cr6.eq) goto loc_826C9AF4;
	// bl 0x826c89a8
	ctx.lr = 0x826C9AF0;
	sub_826C89A8(ctx, base);
	// b 0x826c9af8
	goto loc_826C9AF8;
loc_826C9AF4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C9AF8:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826C9AFC:
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

PPC_WEAK_FUNC(sub_826C9AB8) {
	__imp__sub_826C9AB8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C9B18) {
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
	// bne cr6,0x826c9b5c
	if (!cr6.eq) goto loc_826C9B5C;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// sth r30,6(r31)
	PPC_STORE_U16(r31.u32 + 6, r30.u16);
	// beq cr6,0x826c9b54
	if (cr6.eq) goto loc_826C9B54;
	// bl 0x826c8a30
	ctx.lr = 0x826C9B50;
	sub_826C8A30(ctx, base);
	// b 0x826c9b58
	goto loc_826C9B58;
loc_826C9B54:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826C9B58:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826C9B5C:
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

PPC_WEAK_FUNC(sub_826C9B18) {
	__imp__sub_826C9B18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C9B78) {
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
	ctx.lr = 0x826C9B80;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x826c9f80
	if (cr6.eq) goto loc_826C9F80;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826c9f80
	if (cr6.eq) goto loc_826C9F80;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,27160
	ctx.r4.s64 = r11.s64 + 27160;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268da78
	ctx.lr = 0x826C9BB0;
	sub_8268DA78(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268daf8
	ctx.lr = 0x826C9BBC;
	sub_8268DAF8(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r3,r10,-4804
	ctx.r3.s64 = ctx.r10.s64 + -4804;
	// bl 0x82130000
	ctx.lr = 0x826C9BC8;
	sub_82130000(ctx, base);
	// bl 0x82387a18
	ctx.lr = 0x826C9BCC;
	sub_82387A18(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826c9d3c
	if (cr6.eq) goto loc_826C9D3C;
	// lwz r3,3092(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + 3092);
	// bl 0x8238eb20
	ctx.lr = 0x826C9BE0;
	sub_8238EB20(ctx, base);
	// cmpwi cr6,r3,2
	cr6.compare<int32_t>(ctx.r3.s32, 2, xer);
	// bne cr6,0x826c9d3c
	if (!cr6.eq) goto loc_826C9D3C;
	// li r24,0
	r24.s64 = 0;
	// lwz r11,3092(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3092);
	// li r10,5
	ctx.r10.s64 = 5;
	// mr r26,r24
	r26.u64 = r24.u64;
	// sth r24,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r24.u16);
	// sth r24,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r24.u16);
	// cmpwi cr6,r11,13
	cr6.compare<int32_t>(r11.s32, 13, xer);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bne cr6,0x826c9c1c
	if (!cr6.eq) goto loc_826C9C1C;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// addi r9,r11,27976
	ctx.r9.s64 = r11.s64 + 27976;
	// b 0x826c9c24
	goto loc_826C9C24;
loc_826C9C1C:
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r9,r11,-4820
	ctx.r9.s64 = r11.s64 + -4820;
loc_826C9C24:
	// stw r9,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r9.u32);
	// mr r30,r24
	r30.u64 = r24.u64;
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826c9c74
	if (!cr6.gt) goto loc_826C9C74;
	// addi r31,r28,16
	r31.s64 = r28.s64 + 16;
loc_826C9C3C:
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r27,0(r31)
	r27.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r29,r31,-8
	r29.s64 = r31.s64 + -8;
	// bl 0x826c98e8
	ctx.lr = 0x826C9C50;
	sub_826C98E8(ctx, base);
	// stw r30,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r30.u32);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// stw r27,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r27.u32);
	// addi r31,r31,192
	r31.s64 = r31.s64 + 192;
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826c9c3c
	if (cr6.lt) goto loc_826C9C3C;
	// lwz r26,80(r1)
	r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_826C9C74:
	// lhz r27,84(r1)
	r27.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// bge cr6,0x826c9c84
	if (!cr6.lt) goto loc_826C9C84;
loc_826C9C84:
	// lis r11,-32147
	r11.s64 = -2106785792;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r6,r11,-31096
	ctx.r6.s64 = r11.s64 + -31096;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x823dcf08
	ctx.lr = 0x826C9C98;
	sub_823DCF08(ctx, base);
	// mr r30,r24
	r30.u64 = r24.u64;
	// cmpwi cr6,r27,0
	cr6.compare<int32_t>(r27.s32, 0, xer);
	// ble cr6,0x826c9d1c
	if (!cr6.gt) goto loc_826C9D1C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r26
	r29.u64 = r26.u64;
	// li r22,22
	r22.s64 = 22;
	// li r24,1
	r24.s64 = 1;
	// addi r28,r11,20276
	r28.s64 = r11.s64 + 20276;
loc_826C9CB8:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268db80
	ctx.lr = 0x826C9CC0;
	sub_8268DB80(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826c9d1c
	if (cr6.eq) goto loc_826C9D1C;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c8c58
	ctx.lr = 0x826C9CD8;
	sub_826C8C58(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = r28.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x826C9CE8;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c9d0c
	if (cr6.eq) goto loc_826C9D0C;
	// lwz r11,12(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 12);
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r24.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c9d08
	if (!cr6.eq) goto loc_826C9D08;
	// stw r22,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r22.u32);
	// b 0x826c9d0c
	goto loc_826C9D0C;
loc_826C9D08:
	// stw r24,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r24.u32);
loc_826C9D0C:
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,16
	r29.s64 = r29.s64 + 16;
	// cmpw cr6,r30,r27
	cr6.compare<int32_t>(r30.s32, r27.s32, xer);
	// blt cr6,0x826c9cb8
	if (cr6.lt) goto loc_826C9CB8;
loc_826C9D1C:
	// lhz r5,86(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826c9f80
	if (cr6.eq) goto loc_826C9F80;
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826da2f8
	ctx.lr = 0x826C9D34;
	sub_826DA2F8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
loc_826C9D3C:
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r24,0
	r24.s64 = 0;
	// addi r10,r11,27976
	ctx.r10.s64 = r11.s64 + 27976;
	// li r9,5
	ctx.r9.s64 = 5;
	// sth r24,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r24.u16);
	// mr r23,r24
	r23.u64 = r24.u64;
	// stw r10,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r10.u32);
	// stw r9,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r9.u32);
	// mr r31,r24
	r31.u64 = r24.u64;
	// lwz r8,3080(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// cmpwi cr6,r8,0
	cr6.compare<int32_t>(ctx.r8.s32, 0, xer);
	// sth r24,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r24.u16);
	// stw r23,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r23.u32);
	// ble cr6,0x826c9e10
	if (!cr6.gt) goto loc_826C9E10;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r30,r28,16
	r30.s64 = r28.s64 + 16;
	// addi r27,r11,-4844
	r27.s64 = r11.s64 + -4844;
loc_826C9D80:
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r26,0(r30)
	r26.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r29,r30,-8
	r29.s64 = r30.s64 + -8;
	// bl 0x826c99d0
	ctx.lr = 0x826C9D94;
	sub_826C99D0(ctx, base);
	// stw r31,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, r31.u32);
	// stw r26,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, r26.u32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r29,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r29.u32);
	// lwz r3,-8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,56(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 56);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826C9DB8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// cmpwi cr6,r3,0
	cr6.compare<int32_t>(ctx.r3.s32, 0, xer);
	// bgt cr6,0x826c9dc8
	if (cr6.gt) goto loc_826C9DC8;
	// lis r3,32767
	ctx.r3.s64 = 2147418112;
	// ori r3,r3,65535
	ctx.r3.u64 = ctx.r3.u64 | 65535;
loc_826C9DC8:
	// lwz r11,0(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// subfic r29,r3,1
	xer.ca = ctx.r3.u32 <= 1;
	r29.s64 = 1 - ctx.r3.s64;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// mtctr r9
	ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826C9DE4;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r29
	ctx.r6.u64 = r29.u64;
	// bl 0x82130000
	ctx.lr = 0x826C9DF8;
	sub_82130000(ctx, base);
	// lwz r8,3080(r28)
	ctx.r8.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// cmpw cr6,r31,r8
	cr6.compare<int32_t>(r31.s32, ctx.r8.s32, xer);
	// blt cr6,0x826c9d80
	if (cr6.lt) goto loc_826C9D80;
	// lwz r23,80(r1)
	r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
loc_826C9E10:
	// lhz r25,84(r1)
	r25.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// bge cr6,0x826c9e20
	if (!cr6.lt) goto loc_826C9E20;
loc_826C9E20:
	// lis r11,-32147
	r11.s64 = -2106785792;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r6,r11,-31096
	ctx.r6.s64 = r11.s64 + -31096;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x823dcf08
	ctx.lr = 0x826C9E34;
	sub_823DCF08(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r3,r10,-4860
	ctx.r3.s64 = ctx.r10.s64 + -4860;
	// bl 0x82130000
	ctx.lr = 0x826C9E40;
	sub_82130000(ctx, base);
	// mr r29,r24
	r29.u64 = r24.u64;
	// cmpwi cr6,r25,0
	cr6.compare<int32_t>(r25.s32, 0, xer);
	// ble cr6,0x826c9f3c
	if (!cr6.gt) goto loc_826C9F3C;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r31,r23,4
	r31.s64 = r23.s64 + 4;
	// li r22,22
	r22.s64 = 22;
	// li r24,1
	r24.s64 = 1;
	// addi r27,r11,-4900
	r27.s64 = r11.s64 + -4900;
	// addi r26,r10,20276
	r26.s64 = ctx.r10.s64 + 20276;
loc_826C9E68:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268db80
	ctx.lr = 0x826C9E70;
	sub_8268DB80(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826c9f3c
	if (cr6.eq) goto loc_826C9F3C;
	// addi r30,r31,-4
	r30.s64 = r31.s64 + -4;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c8c58
	ctx.lr = 0x826C9E8C;
	sub_826C8C58(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r10,r11
	ctx.r10.u64 = r11.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r9,0(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,56(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 56);
	// lwz r20,0(r10)
	r20.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r8
	ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826C9EB0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r7,-4(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + -4);
	// mr r19,r3
	r19.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r6,4(r7)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// mtctr r6
	ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x826C9EC8;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r5,0(r20)
	ctx.r5.u64 = PPC_LOAD_U32(r20.u32 + 0);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r3,r20
	ctx.r3.u64 = r20.u64;
	// lwz r4,36(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 36);
	// mtctr r4
	ctr.u64 = ctx.r4.u64;
	// bctrl 
	ctx.lr = 0x826C9EE0;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r27
	ctx.r3.u64 = r27.u64;
	// mr r6,r30
	ctx.r6.u64 = r30.u64;
	// mr r7,r19
	ctx.r7.u64 = r19.u64;
	// bl 0x82130000
	ctx.lr = 0x826C9EF8;
	sub_82130000(ctx, base);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8268da78
	ctx.lr = 0x826C9F08;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826c9f2c
	if (cr6.eq) goto loc_826C9F2C;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r24,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r24.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826c9f28
	if (!cr6.eq) goto loc_826C9F28;
	// stw r22,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r22.u32);
	// b 0x826c9f2c
	goto loc_826C9F2C;
loc_826C9F28:
	// stw r24,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r24.u32);
loc_826C9F2C:
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// cmpw cr6,r29,r25
	cr6.compare<int32_t>(r29.s32, r25.s32, xer);
	// blt cr6,0x826c9e68
	if (cr6.lt) goto loc_826C9E68;
loc_826C9F3C:
	// lhz r30,86(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826c9f80
	if (cr6.eq) goto loc_826C9F80;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826c9f78
	if (!cr6.gt) goto loc_826C9F78;
	// mr r31,r23
	r31.u64 = r23.u64;
loc_826C9F54:
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
	ctx.lr = 0x826C9F6C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,16
	r31.s64 = r31.s64 + 16;
	// bne 0x826c9f54
	if (!cr0.eq) goto loc_826C9F54;
loc_826C9F78:
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x82130588
	ctx.lr = 0x826C9F80;
	sub_82130588(ctx, base);
loc_826C9F80:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_826C9B78) {
	__imp__sub_826C9B78(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826C9F88) {
	PPC_FUNC_PROLOGUE();
	PPCRegister ctr{};
	PPCXERRegister xer{};
	PPCCRRegister cr0{};
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
	ctx.lr = 0x826C9F90;
	// stwu r1,-1424(r1)
	ea = -1424 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r18,r4
	r18.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r18,0
	cr6.compare<uint32_t>(r18.u32, 0, xer);
	// beq cr6,0x826ca1e0
	if (cr6.eq) goto loc_826CA1E0;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826ca1e0
	if (cr6.eq) goto loc_826CA1E0;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8268daf8
	ctx.lr = 0x826C9FB4;
	sub_8268DAF8(ctx, base);
	// li r26,0
	r26.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,3080(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// stw r26,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r26.u32);
	// sth r26,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r26.u16);
	// sth r26,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r26.u16);
	// bl 0x826c9ab8
	ctx.lr = 0x826C9FD0;
	sub_826C9AB8(ctx, base);
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r26
	r29.u64 = r26.u64;
	// addi r19,r11,-12204
	r19.s64 = r11.s64 + -12204;
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// lwz r16,80(r1)
	r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826ca060
	if (!cr6.gt) goto loc_826CA060;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r30,r28,172
	r30.s64 = r28.s64 + 172;
	// addi r31,r16,4
	r31.s64 = r16.s64 + 4;
	// addi r27,r11,-4752
	r27.s64 = r11.s64 + -4752;
loc_826C9FFC:
	// addi r11,r30,-164
	r11.s64 = r30.s64 + -164;
	// stw r29,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r29.u32);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// li r4,32
	ctx.r4.s64 = 32;
	// lwz r9,-156(r30)
	ctx.r9.u64 = PPC_LOAD_U32(r30.u32 + -156);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// bl 0x82137a08
	ctx.lr = 0x826CA030;
	sub_82137A08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA040;
	sub_8268DA78(ctx, base);
	// lwz r8,4(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r29,r29,1
	r29.s64 = r29.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// stw r8,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r8.u32);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// lwz r7,3080(r28)
	ctx.r7.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// cmpw cr6,r29,r7
	cr6.compare<int32_t>(r29.s32, ctx.r7.s32, xer);
	// blt cr6,0x826c9ffc
	if (cr6.lt) goto loc_826C9FFC;
loc_826CA060:
	// lhz r21,84(r1)
	r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// bge cr6,0x826ca070
	if (!cr6.lt) goto loc_826CA070;
loc_826CA070:
	// lis r11,-32147
	r11.s64 = -2106785792;
	// li r5,24
	ctx.r5.s64 = 24;
	// addi r6,r11,-31096
	ctx.r6.s64 = r11.s64 + -31096;
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x823dcf08
	ctx.lr = 0x826CA084;
	sub_823DCF08(ctx, base);
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,-4764
	ctx.r4.s64 = ctx.r10.s64 + -4764;
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA098;
	sub_8268DA78(ctx, base);
	// lwz r20,4(r3)
	r20.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r29,r26
	r29.u64 = r26.u64;
	// cmpwi cr6,r21,0
	cr6.compare<int32_t>(r21.s32, 0, xer);
	// ble cr6,0x826ca19c
	if (!cr6.gt) goto loc_826CA19C;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r30,r16,20
	r30.s64 = r16.s64 + 20;
	// li r27,1
	r27.s64 = 1;
	// lis r24,-32121
	r24.s64 = -2105081856;
	// li r17,22
	r17.s64 = 22;
	// addi r26,r8,-4776
	r26.s64 = ctx.r8.s64 + -4776;
	// addi r25,r9,-4784
	r25.s64 = ctx.r9.s64 + -4784;
	// addi r23,r10,20276
	r23.s64 = ctx.r10.s64 + 20276;
	// addi r22,r11,-27360
	r22.s64 = r11.s64 + -27360;
loc_826CA0D8:
	// mr r3,r18
	ctx.r3.u64 = r18.u64;
	// bl 0x8268db80
	ctx.lr = 0x826CA0E0;
	sub_8268DB80(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826ca19c
	if (cr6.eq) goto loc_826CA19C;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// addi r3,r30,-20
	ctx.r3.s64 = r30.s64 + -20;
	// bl 0x826c8c58
	ctx.lr = 0x826CA0F8;
	sub_826C8C58(ctx, base);
	// mr r4,r22
	ctx.r4.u64 = r22.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA108;
	sub_8268DA78(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// addi r31,r29,1
	r31.s64 = r29.s64 + 1;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r28
	ctx.r3.u64 = r28.u64;
	// stw r31,4(r11)
	PPC_STORE_U32(r11.u32 + 4, r31.u32);
	// stw r27,0(r11)
	PPC_STORE_U32(r11.u32 + 0, r27.u32);
	// bl 0x8268da78
	ctx.lr = 0x826CA128;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ca14c
	if (cr6.eq) goto loc_826CA14C;
	// lwz r11,-8(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -8);
	// stw r27,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r27.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826ca148
	if (!cr6.eq) goto loc_826CA148;
	// stw r17,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r17.u32);
	// b 0x826ca14c
	goto loc_826CA14C;
loc_826CA148:
	// stw r27,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r27.u32);
loc_826CA14C:
	// mr r5,r25
	ctx.r5.u64 = r25.u64;
	// lwz r6,0(r30)
	ctx.r6.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// mr r7,r20
	ctx.r7.u64 = r20.u64;
	// li r4,1024
	ctx.r4.s64 = 1024;
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x82137a08
	ctx.lr = 0x826CA164;
	sub_82137A08(ctx, base);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// mr r5,r19
	ctx.r5.u64 = r19.u64;
	// mr r7,r29
	ctx.r7.u64 = r29.u64;
	// li r4,128
	ctx.r4.s64 = 128;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82137a08
	ctx.lr = 0x826CA17C;
	sub_82137A08(ctx, base);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// lwz r3,-10244(r24)
	ctx.r3.u64 = PPC_LOAD_U32(r24.u32 + -10244);
	// bl 0x822183b0
	ctx.lr = 0x826CA18C;
	sub_822183B0(ctx, base);
	// mr r29,r31
	r29.u64 = r31.u64;
	// addi r30,r30,24
	r30.s64 = r30.s64 + 24;
	// cmpw cr6,r31,r21
	cr6.compare<int32_t>(r31.s32, r21.s32, xer);
	// blt cr6,0x826ca0d8
	if (cr6.lt) goto loc_826CA0D8;
loc_826CA19C:
	// lhz r30,86(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826ca1e0
	if (cr6.eq) goto loc_826CA1E0;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826ca1d8
	if (!cr6.gt) goto loc_826CA1D8;
	// mr r31,r16
	r31.u64 = r16.u64;
loc_826CA1B4:
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
	ctx.lr = 0x826CA1CC;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x826ca1b4
	if (!cr0.eq) goto loc_826CA1B4;
loc_826CA1D8:
	// mr r3,r16
	ctx.r3.u64 = r16.u64;
	// bl 0x82130588
	ctx.lr = 0x826CA1E0;
	sub_82130588(ctx, base);
loc_826CA1E0:
	// addi r1,r1,1424
	ctx.r1.s64 = ctx.r1.s64 + 1424;
	// b 0x823d9218
	return;
}

PPC_WEAK_FUNC(sub_826C9F88) {
	__imp__sub_826C9F88(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CA1E8) {
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
	ctx.lr = 0x826CA1F0;
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r21,r4
	r21.u64 = ctx.r4.u64;
	// mr r28,r5
	r28.u64 = ctx.r5.u64;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x826ca458
	if (cr6.eq) goto loc_826CA458;
	// cmplwi cr6,r28,0
	cr6.compare<uint32_t>(r28.u32, 0, xer);
	// beq cr6,0x826ca458
	if (cr6.eq) goto loc_826CA458;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268daf8
	ctx.lr = 0x826CA214;
	sub_8268DAF8(ctx, base);
	// li r20,0
	r20.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,3080(r28)
	ctx.r4.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// stw r20,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r20.u32);
	// sth r20,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, r20.u16);
	// sth r20,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, r20.u16);
	// bl 0x826c9b18
	ctx.lr = 0x826CA230;
	sub_826C9B18(ctx, base);
	// lwz r11,3080(r28)
	r11.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// lis r23,-32121
	r23.s64 = -2105081856;
	// mr r30,r20
	r30.u64 = r20.u64;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// lwz r19,80(r1)
	r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// ble cr6,0x826ca2f0
	if (!cr6.gt) goto loc_826CA2F0;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// addi r29,r28,172
	r29.s64 = r28.s64 + 172;
	// addi r31,r19,4
	r31.s64 = r19.s64 + 4;
	// addi r27,r10,-12204
	r27.s64 = ctx.r10.s64 + -12204;
	// addi r26,r11,-4740
	r26.s64 = r11.s64 + -4740;
loc_826CA260:
	// addi r11,r29,-164
	r11.s64 = r29.s64 + -164;
	// stw r30,4(r31)
	PPC_STORE_U32(r31.u32 + 4, r30.u32);
	// stw r11,0(r31)
	PPC_STORE_U32(r31.u32 + 0, r11.u32);
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// addic. r11,r10,-1
	xer.ca = ctx.r10.u32 > 0;
	r11.s64 = ctx.r10.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x826ca280
	if (!cr0.lt) goto loc_826CA280;
	// mr r11,r20
	r11.u64 = r20.u64;
	// b 0x826ca28c
	goto loc_826CA28C;
loc_826CA280:
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// ble cr6,0x826ca28c
	if (!cr6.gt) goto loc_826CA28C;
	// li r11,16
	r11.s64 = 16;
loc_826CA28C:
	// addi r10,r11,93
	ctx.r10.s64 = r11.s64 + 93;
	// lwz r11,-10020(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10020);
	// mr r6,r26
	ctx.r6.u64 = r26.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r27
	ctx.r5.u64 = r27.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r4,32
	ctx.r4.s64 = 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r8,r9,r11
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// stw r8,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r8.u32);
	// lwz r11,-156(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -156);
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
	// bl 0x82137a08
	ctx.lr = 0x826CA2C0;
	sub_82137A08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA2D0;
	sub_8268DA78(ctx, base);
	// lwz r10,4(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// stw r10,16(r31)
	PPC_STORE_U32(r31.u32 + 16, ctx.r10.u32);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// lwz r9,3080(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// cmpw cr6,r30,r9
	cr6.compare<int32_t>(r30.s32, ctx.r9.s32, xer);
	// blt cr6,0x826ca260
	if (cr6.lt) goto loc_826CA260;
loc_826CA2F0:
	// lhz r26,84(r1)
	r26.u64 = PPC_LOAD_U16(ctx.r1.u32 + 84);
	// mr r4,r26
	ctx.r4.u64 = r26.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// bge cr6,0x826ca300
	if (!cr6.lt) goto loc_826CA300;
loc_826CA300:
	// lis r11,-32147
	r11.s64 = -2106785792;
	// li r5,24
	ctx.r5.s64 = 24;
	// addi r6,r11,-31096
	ctx.r6.s64 = r11.s64 + -31096;
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x823dcf08
	ctx.lr = 0x826CA314;
	sub_823DCF08(ctx, base);
	// mr r30,r20
	r30.u64 = r20.u64;
	// cmpwi cr6,r26,0
	cr6.compare<int32_t>(r26.s32, 0, xer);
	// ble cr6,0x826ca414
	if (!cr6.gt) goto loc_826CA414;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r31,r19,4
	r31.s64 = r19.s64 + 4;
	// li r22,22
	r22.s64 = 22;
	// li r28,1
	r28.s64 = 1;
	// addi r27,r9,-19612
	r27.s64 = ctx.r9.s64 + -19612;
	// addi r25,r10,2824
	r25.s64 = ctx.r10.s64 + 2824;
	// addi r24,r11,20276
	r24.s64 = r11.s64 + 20276;
loc_826CA344:
	// mr r3,r21
	ctx.r3.u64 = r21.u64;
	// bl 0x8268db80
	ctx.lr = 0x826CA34C;
	sub_8268DB80(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826ca414
	if (cr6.eq) goto loc_826CA414;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// addi r3,r31,-4
	ctx.r3.s64 = r31.s64 + -4;
	// bl 0x826c8c58
	ctx.lr = 0x826CA364;
	sub_826C8C58(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA374;
	sub_8268DA78(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826ca398
	if (cr6.eq) goto loc_826CA398;
	// lwz r11,8(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826ca394
	if (!cr6.eq) goto loc_826CA394;
	// stw r22,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r22.u32);
	// b 0x826ca398
	goto loc_826CA398;
loc_826CA394:
	// stw r28,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, r28.u32);
loc_826CA398:
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA3A8;
	sub_8268DA78(ctx, base);
	// lwz r11,0(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,164(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 164);
	// addic. r11,r9,-1
	xer.ca = ctx.r9.u32 > 0;
	r11.s64 = ctx.r9.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x826ca3c4
	if (!cr0.lt) goto loc_826CA3C4;
	// mr r11,r20
	r11.u64 = r20.u64;
	// b 0x826ca3d0
	goto loc_826CA3D0;
loc_826CA3C4:
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// ble cr6,0x826ca3d0
	if (!cr6.gt) goto loc_826CA3D0;
	// li r11,16
	r11.s64 = 16;
loc_826CA3D0:
	// addi r9,r11,93
	ctx.r9.s64 = r11.s64 + 93;
	// lwz r11,-10020(r23)
	r11.u64 = PPC_LOAD_U32(r23.u32 + -10020);
	// mr r4,r27
	ctx.r4.u64 = r27.u64;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// lwzx r7,r8,r11
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + r11.u32);
	// stw r28,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, r28.u32);
	// stw r7,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r7.u32);
	// bl 0x8268da78
	ctx.lr = 0x826CA3F8;
	sub_8268DA78(ctx, base);
	// lwz r6,16(r31)
	ctx.r6.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// stw r28,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r28.u32);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// cmpw cr6,r30,r26
	cr6.compare<int32_t>(r30.s32, r26.s32, xer);
	// stw r6,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r6.u32);
	// blt cr6,0x826ca344
	if (cr6.lt) goto loc_826CA344;
loc_826CA414:
	// lhz r30,86(r1)
	r30.u64 = PPC_LOAD_U16(ctx.r1.u32 + 86);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826ca458
	if (cr6.eq) goto loc_826CA458;
	// cmpwi cr6,r30,0
	cr6.compare<int32_t>(r30.s32, 0, xer);
	// ble cr6,0x826ca450
	if (!cr6.gt) goto loc_826CA450;
	// mr r31,r19
	r31.u64 = r19.u64;
loc_826CA42C:
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
	ctx.lr = 0x826CA444;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// addic. r30,r30,-1
	xer.ca = r30.u32 > 0;
	r30.s64 = r30.s64 + -1;
	cr0.compare<int32_t>(r30.s32, 0, xer);
	// addi r31,r31,24
	r31.s64 = r31.s64 + 24;
	// bne 0x826ca42c
	if (!cr0.eq) goto loc_826CA42C;
loc_826CA450:
	// mr r3,r19
	ctx.r3.u64 = r19.u64;
	// bl 0x82130588
	ctx.lr = 0x826CA458;
	sub_82130588(ctx, base);
loc_826CA458:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_826CA1E8) {
	__imp__sub_826CA1E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CA460) {
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
	ctx.lr = 0x826CA468;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32111
	r26.s64 = -2104426496;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,8988
	ctx.r4.s64 = r11.s64 + 8988;
	// lwz r3,-24180(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -24180);
	// bl 0x822c7030
	ctx.lr = 0x826CA488;
	sub_822C7030(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r25,-32256
	r25.s64 = -2113929216;
	// li r29,0
	r29.s64 = 0;
	// li r27,2
	r27.s64 = 2;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r29,88(r31)
	PPC_STORE_U32(r31.u32 + 88, r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lhz r11,3992(r25)
	r11.u64 = PPC_LOAD_U16(r25.u32 + 3992);
	// addi r4,r10,9000
	ctx.r4.s64 = ctx.r10.s64 + 9000;
	// sth r11,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r11.u16);
	// addi r30,r31,92
	r30.s64 = r31.s64 + 92;
	// stw r27,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r27.u32);
	// lwz r3,-24180(r26)
	ctx.r3.u64 = PPC_LOAD_U32(r26.u32 + -24180);
	// bl 0x822c7030
	ctx.lr = 0x826CA4C0;
	sub_822C7030(ctx, base);
	// stw r29,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, r29.u32);
	// lhz r9,3992(r25)
	ctx.r9.u64 = PPC_LOAD_U16(r25.u32 + 3992);
	// mr r11,r29
	r11.u64 = r29.u64;
	// sth r9,92(r3)
	PPC_STORE_U16(ctx.r3.u32 + 92, ctx.r9.u16);
	// addi r10,r3,92
	ctx.r10.s64 = ctx.r3.s64 + 92;
	// stw r27,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, r27.u32);
	// lwz r9,3080(r28)
	ctx.r9.u64 = PPC_LOAD_U32(r28.u32 + 3080);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// ble cr6,0x826ca504
	if (!cr6.gt) goto loc_826CA504;
	// addi r8,r28,16
	ctx.r8.s64 = r28.s64 + 16;
loc_826CA4E8:
	// lwz r7,0(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// cmpwi cr6,r7,0
	cr6.compare<int32_t>(ctx.r7.s32, 0, xer);
	// beq cr6,0x826ca524
	if (cr6.eq) goto loc_826CA524;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r8,r8,192
	ctx.r8.s64 = ctx.r8.s64 + 192;
	// cmpw cr6,r11,r9
	cr6.compare<int32_t>(r11.s32, ctx.r9.s32, xer);
	// blt cr6,0x826ca4e8
	if (cr6.lt) goto loc_826CA4E8;
loc_826CA504:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r9,88(r3)
	PPC_STORE_U32(ctx.r3.u32 + 88, ctx.r9.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, r11.u16);
	// stw r27,156(r3)
	PPC_STORE_U32(ctx.r3.u32 + 156, r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
loc_826CA524:
	// cmpwi cr6,r11,-1
	cr6.compare<int32_t>(r11.s32, -1, xer);
	// beq cr6,0x826ca504
	if (cr6.eq) goto loc_826CA504;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	r11.u64 = r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r9,r11,r28
	ctx.r9.u64 = r11.u64 + r28.u64;
	// lwz r8,172(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 172);
	// cmpwi cr6,r8,1
	cr6.compare<int32_t>(ctx.r8.s32, 1, xer);
	// bne cr6,0x826ca504
	if (!cr6.eq) goto loc_826CA504;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,0(r30)
	PPC_STORE_U16(r30.u32 + 0, r11.u16);
	// stw r27,156(r31)
	PPC_STORE_U32(r31.u32 + 156, r27.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x823d923c
	return;
}

PPC_WEAK_FUNC(sub_826CA460) {
	__imp__sub_826CA460(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CA568) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x826CA570;
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r28,-32111
	r28.s64 = -2104426496;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r25,r5
	r25.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,8988
	ctx.r4.s64 = r11.s64 + 8988;
	// lwz r3,-24180(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -24180);
	// bl 0x822c7030
	ctx.lr = 0x826CA594;
	sub_822C7030(ctx, base);
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// lis r24,-32256
	r24.s64 = -2113929216;
	// li r30,0
	r30.s64 = 0;
	// li r21,2
	r21.s64 = 2;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// stw r30,88(r29)
	PPC_STORE_U32(r29.u32 + 88, r30.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lhz r11,3992(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 3992);
	// addi r4,r10,9000
	ctx.r4.s64 = ctx.r10.s64 + 9000;
	// sth r11,92(r29)
	PPC_STORE_U16(r29.u32 + 92, r11.u16);
	// addi r27,r29,92
	r27.s64 = r29.s64 + 92;
	// stw r21,156(r29)
	PPC_STORE_U32(r29.u32 + 156, r21.u32);
	// lwz r3,-24180(r28)
	ctx.r3.u64 = PPC_LOAD_U32(r28.u32 + -24180);
	// bl 0x822c7030
	ctx.lr = 0x826CA5CC;
	sub_822C7030(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// stw r30,88(r28)
	PPC_STORE_U32(r28.u32 + 88, r30.u32);
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// lhz r11,3992(r24)
	r11.u64 = PPC_LOAD_U16(r24.u32 + 3992);
	// addi r26,r28,92
	r26.s64 = r28.s64 + 92;
	// sth r11,92(r28)
	PPC_STORE_U16(r28.u32 + 92, r11.u16);
	// stw r21,156(r28)
	PPC_STORE_U32(r28.u32 + 156, r21.u32);
	// beq cr6,0x826ca6d0
	if (cr6.eq) goto loc_826CA6D0;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x826ca6d0
	if (cr6.eq) goto loc_826CA6D0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-4764
	ctx.r4.s64 = r11.s64 + -4764;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA608;
	sub_8268DA78(ctx, base);
	// lwz r10,3080(r25)
	ctx.r10.u64 = PPC_LOAD_U32(r25.u32 + 3080);
	// lwz r22,4(r3)
	r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r20,r30
	r20.u64 = r30.u64;
	// li r19,1
	r19.s64 = 1;
	// cmpwi cr6,r10,0
	cr6.compare<int32_t>(ctx.r10.s32, 0, xer);
	// ble cr6,0x826ca67c
	if (!cr6.gt) goto loc_826CA67C;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r24,r11,-12204
	r24.s64 = r11.s64 + -12204;
	// addi r23,r10,-4752
	r23.s64 = ctx.r10.s64 + -4752;
loc_826CA630:
	// mr r6,r23
	ctx.r6.u64 = r23.u64;
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826CA648;
	sub_82137A08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA658;
	sub_8268DA78(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r11,r22
	cr6.compare<int32_t>(r11.s32, r22.s32, xer);
	// bge cr6,0x826ca678
	if (!cr6.lt) goto loc_826CA678;
	// lwz r11,3080(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + 3080);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826ca630
	if (cr6.lt) goto loc_826CA630;
	// b 0x826ca67c
	goto loc_826CA67C;
loc_826CA678:
	// mr r20,r19
	r20.u64 = r19.u64;
loc_826CA67C:
	// clrlwi r11,r20,24
	r11.u64 = r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ca6d0
	if (cr6.eq) goto loc_826CA6D0;
	// rlwinm r11,r30,1,0,30
	r11.u64 = __builtin_rotateleft64(r30.u32 | (r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	r11.u64 = r30.u64 + r11.u64;
	// rlwinm r11,r11,6,0,25
	r11.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 6) & 0xFFFFFFC0;
	// add r10,r11,r25
	ctx.r10.u64 = r11.u64 + r25.u64;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// lwz r9,16(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 16);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826ca6c0
	if (!cr6.eq) goto loc_826CA6C0;
	// stw r19,88(r29)
	PPC_STORE_U32(r29.u32 + 88, r19.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,0(r27)
	PPC_STORE_U16(r27.u32 + 0, r11.u16);
	// stw r21,156(r29)
	PPC_STORE_U32(r29.u32 + 156, r21.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
loc_826CA6C0:
	// stw r19,88(r28)
	PPC_STORE_U32(r28.u32 + 88, r19.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,0(r26)
	PPC_STORE_U16(r26.u32 + 0, r11.u16);
	// stw r21,156(r28)
	PPC_STORE_U32(r28.u32 + 156, r21.u32);
loc_826CA6D0:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x823d9224
	return;
}

PPC_WEAK_FUNC(sub_826CA568) {
	__imp__sub_826CA568(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CA6D8) {
	PPC_FUNC_PROLOGUE();
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
	ctx.lr = 0x826CA6E0;
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// mr r21,r5
	r21.u64 = ctx.r5.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826ca8d8
	if (cr6.eq) goto loc_826CA8D8;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x826ca8d8
	if (cr6.eq) goto loc_826CA8D8;
	// lis r25,-32111
	r25.s64 = -2104426496;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,8988
	ctx.r4.s64 = r11.s64 + 8988;
	// lwz r3,-24180(r25)
	ctx.r3.u64 = PPC_LOAD_U32(r25.u32 + -24180);
	// bl 0x822c7138
	ctx.lr = 0x826CA714;
	sub_822C7138(ctx, base);
	// lwz r11,-24180(r25)
	r11.u64 = PPC_LOAD_U32(r25.u32 + -24180);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r4,r10,9000
	ctx.r4.s64 = ctx.r10.s64 + 9000;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822c7138
	ctx.lr = 0x826CA730;
	sub_822C7138(ctx, base);
	// lis r9,-32247
	ctx.r9.s64 = -2113339392;
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// addi r4,r9,5596
	ctx.r4.s64 = ctx.r9.s64 + 5596;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA748;
	sub_8268DA78(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32247
	ctx.r7.s64 = -2113339392;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,5584
	ctx.r4.s64 = ctx.r7.s64 + 5584;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// lwz r30,4(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x8268da78
	ctx.lr = 0x826CA764;
	sub_8268DA78(ctx, base);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r5,r30,1
	ctx.r5.s64 = r30.s64 + 1;
	// cmpw cr6,r5,r6
	cr6.compare<int32_t>(ctx.r5.s32, ctx.r6.s32, xer);
	// blt cr6,0x826ca8d8
	if (cr6.lt) goto loc_826CA8D8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-4696
	ctx.r4.s64 = r11.s64 + -4696;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA788;
	sub_8268DA78(ctx, base);
	// lwz r10,3080(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 3080);
	// li r22,1
	r22.s64 = 1;
	// lwz r27,4(r3)
	r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r10,1
	cr6.compare<int32_t>(ctx.r10.s32, 1, xer);
	// mr r24,r22
	r24.u64 = r22.u64;
	// mr r30,r22
	r30.u64 = r22.u64;
	// ble cr6,0x826ca804
	if (!cr6.gt) goto loc_826CA804;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r29,r11,-12204
	r29.s64 = r11.s64 + -12204;
	// addi r28,r10,-4740
	r28.s64 = ctx.r10.s64 + -4740;
loc_826CA7B4:
	// mr r6,r28
	ctx.r6.u64 = r28.u64;
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r7,r30
	ctx.r7.u64 = r30.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826CA7CC;
	sub_82137A08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CA7DC;
	sub_8268DA78(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r27,r11
	cr6.compare<int32_t>(r27.s32, r11.s32, xer);
	// bge cr6,0x826ca7ec
	if (!cr6.lt) goto loc_826CA7EC;
	// addi r24,r24,1
	r24.s64 = r24.s64 + 1;
loc_826CA7EC:
	// lwz r11,3080(r21)
	r11.u64 = PPC_LOAD_U32(r21.u32 + 3080);
	// addi r30,r30,1
	r30.s64 = r30.s64 + 1;
	// cmpw cr6,r30,r11
	cr6.compare<int32_t>(r30.s32, r11.s32, xer);
	// blt cr6,0x826ca7b4
	if (cr6.lt) goto loc_826CA7B4;
	// cmpwi cr6,r24,1
	cr6.compare<int32_t>(r24.s32, 1, xer);
	// bne cr6,0x826ca8c0
	if (!cr6.eq) goto loc_826CA8C0;
loc_826CA804:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r22,88(r26)
	PPC_STORE_U32(r26.u32 + 88, r22.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// li r9,2
	ctx.r9.s64 = 2;
	// addi r31,r10,-21500
	r31.s64 = ctx.r10.s64 + -21500;
	// lis r8,-32245
	ctx.r8.s64 = -2113208320;
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// li r5,64
	ctx.r5.s64 = 64;
	// sth r11,92(r26)
	PPC_STORE_U16(r26.u32 + 92, r11.u16);
	// addi r4,r8,-17848
	ctx.r4.s64 = ctx.r8.s64 + -17848;
	// stw r9,156(r26)
	PPC_STORE_U32(r26.u32 + 156, ctx.r9.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// lwz r30,-24180(r25)
	r30.u64 = PPC_LOAD_U32(r25.u32 + -24180);
	// bl 0x823db670
	ctx.lr = 0x826CA840;
	sub_823DB670(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r4,10248(r30)
	ctx.r4.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// bl 0x821fd7c0
	ctx.lr = 0x826CA854;
	sub_821FD7C0(ctx, base);
	// li r11,0
	r11.s64 = 0;
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, r31.u32);
	// stb r11,180(r1)
	PPC_STORE_U8(ctx.r1.u32 + 180, r11.u8);
	// stw r11,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, r11.u32);
	// lwz r7,10248(r30)
	ctx.r7.u64 = PPC_LOAD_U32(r30.u32 + 10248);
	// stw r31,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, r31.u32);
	// stw r7,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r7.u32);
	// lwz r11,324(r1)
	r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 324);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826ca8d8
	if (cr6.eq) goto loc_826CA8D8;
	// addi r31,r11,92
	r31.s64 = r11.s64 + 92;
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-12296
	ctx.r4.s64 = r11.s64 + -12296;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826CA898;
	sub_8268B770(ctx, base);
	// lwz r10,3100(r21)
	ctx.r10.u64 = PPC_LOAD_U32(r21.u32 + 3100);
	// cmpwi cr6,r10,2
	cr6.compare<int32_t>(ctx.r10.s32, 2, xer);
	// bne cr6,0x826ca8d8
	if (!cr6.eq) goto loc_826CA8D8;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lwz r3,-10224(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -10224);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r11,-4724
	ctx.r4.s64 = r11.s64 + -4724;
	// bl 0x8268b770
	ctx.lr = 0x826CA8B8;
	sub_8268B770(ctx, base);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d922c
	return;
loc_826CA8C0:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// stw r22,88(r23)
	PPC_STORE_U32(r23.u32 + 88, r22.u32);
	// li r10,2
	ctx.r10.s64 = 2;
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,92(r23)
	PPC_STORE_U16(r23.u32 + 92, r11.u16);
	// stw r10,156(r23)
	PPC_STORE_U32(r23.u32 + 156, ctx.r10.u32);
loc_826CA8D8:
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_826CA6D8) {
	__imp__sub_826CA6D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CA8E0) {
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
	ctx.lr = 0x826CA8E8;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826ca9cc
	if (cr6.eq) goto loc_826CA9CC;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826ca9cc
	if (cr6.eq) goto loc_826CA9CC;
	// addic. r31,r30,8
	xer.ca = r30.u32 > 4294967287;
	r31.s64 = r30.s64 + 8;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x826ca9cc
	if (cr0.eq) goto loc_826CA9CC;
	// lwz r11,3144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826ca9cc
	if (!cr6.eq) goto loc_826CA9CC;
	// lis r29,-32111
	r29.s64 = -2104426496;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,8988
	ctx.r4.s64 = r11.s64 + 8988;
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x822c7138
	ctx.lr = 0x826CA92C;
	sub_822C7138(ctx, base);
	// lwz r11,-24180(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r4,r10,9000
	ctx.r4.s64 = ctx.r10.s64 + 9000;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822c7138
	ctx.lr = 0x826CA948;
	sub_822C7138(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// lwz r3,8(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 8);
	// bl 0x822a8a88
	ctx.lr = 0x826CA954;
	sub_822A8A88(ctx, base);
	// clrlwi r9,r3,24
	ctx.r9.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// bne cr6,0x826ca9cc
	if (!cr6.eq) goto loc_826CA9CC;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x82256150
	ctx.lr = 0x826CA968;
	sub_82256150(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// lwz r9,40(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// divw r11,r3,r10
	r11.s32 = ctx.r3.s32 / ctx.r10.s32;
	// divw r10,r9,r10
	ctx.r10.s32 = ctx.r9.s32 / ctx.r10.s32;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r9
	ctx.r7.u64 = r11.u64 + ctx.r9.u64;
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r5,r7,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// subf. r3,r4,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r4.s64;
	cr0.compare<int32_t>(ctx.r3.s32, 0, xer);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// blt 0x826ca9bc
	if (cr0.lt) goto loc_826CA9BC;
	// stw r10,88(r29)
	PPC_STORE_U32(r29.u32 + 88, ctx.r10.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,92(r29)
	PPC_STORE_U16(r29.u32 + 92, r11.u16);
	// stw r9,156(r29)
	PPC_STORE_U32(r29.u32 + 156, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826CA9BC:
	// stw r10,88(r28)
	PPC_STORE_U32(r28.u32 + 88, ctx.r10.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,92(r28)
	PPC_STORE_U16(r28.u32 + 92, r11.u16);
	// stw r9,156(r28)
	PPC_STORE_U32(r28.u32 + 156, ctx.r9.u32);
loc_826CA9CC:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CA8E0) {
	__imp__sub_826CA8E0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CA9D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CA9D4) {
	__imp__sub_826CA9D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CA9D8) {
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
	ctx.lr = 0x826CA9E0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826caad4
	if (cr6.eq) goto loc_826CAAD4;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826caad4
	if (cr6.eq) goto loc_826CAAD4;
	// lis r30,-32111
	r30.s64 = -2104426496;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,8988
	ctx.r4.s64 = r11.s64 + 8988;
	// lwz r3,-24180(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// bl 0x822c7138
	ctx.lr = 0x826CAA10;
	sub_822C7138(ctx, base);
	// lwz r11,-24180(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -24180);
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// addi r4,r10,9000
	ctx.r4.s64 = ctx.r10.s64 + 9000;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = r11.u64;
	// bl 0x822c7138
	ctx.lr = 0x826CAA2C;
	sub_822C7138(ctx, base);
	// lis r9,-32121
	ctx.r9.s64 = -2105081856;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// li r4,109
	ctx.r4.s64 = 109;
	// lwz r11,-10236(r9)
	r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + -10236);
	// lwz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// addis r3,r8,1
	ctx.r3.s64 = ctx.r8.s64 + 65536;
	// addi r3,r3,16256
	ctx.r3.s64 = ctx.r3.s64 + 16256;
	// bl 0x82641cb0
	ctx.lr = 0x826CAA4C;
	sub_82641CB0(ctx, base);
	// mr r28,r3
	r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82256150
	ctx.lr = 0x826CAA58;
	sub_82256150(ctx, base);
	// li r10,10
	ctx.r10.s64 = 10;
	// lwz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U32(r31.u32 + 48);
	// divw r11,r3,r10
	r11.s32 = ctx.r3.s32 / ctx.r10.s32;
	// divw r10,r7,r10
	ctx.r10.s32 = ctx.r7.s32 / ctx.r10.s32;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r9
	ctx.r6.u64 = r11.u64 + ctx.r9.u64;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// subf. r11,r3,r4
	r11.s64 = ctx.r4.s64 - ctx.r3.s64;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// blt 0x826caab8
	if (cr0.lt) goto loc_826CAAB8;
	// lbz r11,2396(r28)
	r11.u64 = PPC_LOAD_U8(r28.u32 + 2396);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826caab8
	if (!cr6.eq) goto loc_826CAAB8;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,88(r30)
	PPC_STORE_U32(r30.u32 + 88, ctx.r10.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,92(r30)
	PPC_STORE_U16(r30.u32 + 92, r11.u16);
	// stw r9,156(r30)
	PPC_STORE_U32(r30.u32 + 156, ctx.r9.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
loc_826CAAB8:
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,88(r29)
	PPC_STORE_U32(r29.u32 + 88, ctx.r10.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,92(r29)
	PPC_STORE_U16(r29.u32 + 92, r11.u16);
	// stw r9,156(r29)
	PPC_STORE_U32(r29.u32 + 156, ctx.r9.u32);
loc_826CAAD4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CA9D8) {
	__imp__sub_826CA9D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CAADC) {
	__imp__sub_826CAADC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAAE0) {
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
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cab7c
	if (cr6.eq) goto loc_826CAB7C;
	// cmplwi cr6,r5,0
	cr6.compare<uint32_t>(ctx.r5.u32, 0, xer);
	// beq cr6,0x826cab7c
	if (cr6.eq) goto loc_826CAB7C;
	// lis r11,-32111
	r11.s64 = -2104426496;
	// lis r10,-32246
	ctx.r10.s64 = -2113273856;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,8988
	ctx.r4.s64 = ctx.r10.s64 + 8988;
	// lwz r3,-24180(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -24180);
	// bl 0x822c7138
	ctx.lr = 0x826CAB20;
	sub_822C7138(ctx, base);
	// lis r9,-32244
	ctx.r9.s64 = -2113142784;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// addi r4,r9,-17032
	ctx.r4.s64 = ctx.r9.s64 + -17032;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CAB38;
	sub_8268DA78(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// lis r7,-32245
	ctx.r7.s64 = -2113208320;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r7,-20892
	ctx.r4.s64 = ctx.r7.s64 + -20892;
	// lwz r30,4(r8)
	r30.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// bl 0x8268da78
	ctx.lr = 0x826CAB54;
	sub_8268DA78(ctx, base);
	// lwz r6,4(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r30,r6
	cr6.compare<int32_t>(r30.s32, ctx.r6.s32, xer);
	// blt cr6,0x826cab7c
	if (cr6.lt) goto loc_826CAB7C;
	// lis r11,-32255
	r11.s64 = -2113863680;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r10,88(r31)
	PPC_STORE_U32(r31.u32 + 88, ctx.r10.u32);
	// lhz r11,23424(r11)
	r11.u64 = PPC_LOAD_U16(r11.u32 + 23424);
	// sth r11,92(r31)
	PPC_STORE_U16(r31.u32 + 92, r11.u16);
	// stw r9,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r9.u32);
loc_826CAB7C:
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

PPC_WEAK_FUNC(sub_826CAAE0) {
	__imp__sub_826CAAE0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAB94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CAB94) {
	__imp__sub_826CAB94(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAB98) {
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
	ctx.lr = 0x826CABA0;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r5
	r30.u64 = ctx.r5.u64;
	// bl 0x82256058
	ctx.lr = 0x826CABAC;
	sub_82256058(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cac3c
	if (cr6.eq) goto loc_826CAC3C;
	// bl 0x82256058
	ctx.lr = 0x826CABB8;
	sub_82256058(ctx, base);
	// addi r11,r3,8
	r11.s64 = ctx.r3.s64 + 8;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cac3c
	if (cr6.eq) goto loc_826CAC3C;
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
	ctx.lr = 0x826CABE4;
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
	ctx.lr = 0x826CABF8;
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
	// lwz r3,-24180(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + -24180);
	// bl 0x821fd980
	ctx.lr = 0x826CAC14;
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
	ctx.lr = 0x826CAC34;
	sub_823DC018(ctx, base);
	// li r5,3
	ctx.r5.s64 = 3;
	// stw r5,156(r31)
	PPC_STORE_U32(r31.u32 + 156, ctx.r5.u32);
loc_826CAC3C:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CAB98) {
	__imp__sub_826CAB98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAC48) {
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
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// beq cr6,0x826cac84
	if (cr6.eq) goto loc_826CAC84;
	// lwz r11,0(r4)
	r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// lwz r10,336(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 336);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CAC78;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x82255cf8
	ctx.lr = 0x826CAC84;
	sub_82255CF8(ctx, base);
loc_826CAC84:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// ld r31,-16(r1)
	r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CAC48) {
	__imp__sub_826CAC48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAC98) {
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
	ctx.lr = 0x826CACA0;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// bl 0x82256058
	ctx.lr = 0x826CACB0;
	sub_82256058(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	cr6.compare<uint32_t>(ctx.r4.u32, 0, xer);
	// addi r31,r4,8
	r31.s64 = ctx.r4.s64 + 8;
	// bne cr6,0x826cacc4
	if (!cr6.eq) goto loc_826CACC4;
	// li r31,0
	r31.s64 = 0;
loc_826CACC4:
	// cmplwi cr6,r29,0
	cr6.compare<uint32_t>(r29.u32, 0, xer);
	// beq cr6,0x826cad40
	if (cr6.eq) goto loc_826CAD40;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826cad40
	if (cr6.eq) goto loc_826CAD40;
	// lwz r11,3144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826cad40
	if (!cr6.eq) goto loc_826CAD40;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c9358
	ctx.lr = 0x826CACE8;
	sub_826C9358(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826ca460
	ctx.lr = 0x826CACF4;
	sub_826CA460(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826c9b78
	ctx.lr = 0x826CAD04;
	sub_826C9B78(ctx, base);
	// lis r30,-32121
	r30.s64 = -2105081856;
	// lis r11,1
	r11.s64 = 65536;
	// li r4,43
	ctx.r4.s64 = 43;
	// ori r31,r11,16256
	r31.u64 = r11.u64 | 16256;
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// lwz r10,48(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r10,r31
	ctx.r3.u64 = ctx.r10.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826CAD24;
	sub_82641CB0(ctx, base);
	// bl 0x826757d0
	ctx.lr = 0x826CAD28;
	sub_826757D0(ctx, base);
	// lwz r11,-10236(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -10236);
	// li r4,44
	ctx.r4.s64 = 44;
	// lwz r9,48(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 48);
	// add r3,r9,r31
	ctx.r3.u64 = ctx.r9.u64 + r31.u64;
	// bl 0x82641cb0
	ctx.lr = 0x826CAD3C;
	sub_82641CB0(ctx, base);
	// bl 0x826757d0
	ctx.lr = 0x826CAD40;
	sub_826757D0(ctx, base);
loc_826CAD40:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CAC98) {
	__imp__sub_826CAC98(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAD48) {
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91e8
	ctx.lr = 0x826CAD50;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r26,r3
	r26.u64 = ctx.r3.u64;
	// addi r3,r11,5700
	ctx.r3.s64 = r11.s64 + 5700;
	// bl 0x821fa230
	ctx.lr = 0x826CAD64;
	sub_821FA230(ctx, base);
	// mr r25,r3
	r25.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x826CAD6C;
	sub_82256058(ctx, base);
	// mr r24,r3
	r24.u64 = ctx.r3.u64;
	// cmplwi cr6,r25,0
	cr6.compare<uint32_t>(r25.u32, 0, xer);
	// beq cr6,0x826caf0c
	if (cr6.eq) goto loc_826CAF0C;
	// cmplwi cr6,r24,0
	cr6.compare<uint32_t>(r24.u32, 0, xer);
	// beq cr6,0x826caf0c
	if (cr6.eq) goto loc_826CAF0C;
	// addic. r29,r24,8
	xer.ca = r24.u32 > 4294967287;
	r29.s64 = r24.s64 + 8;
	cr0.compare<int32_t>(r29.s32, 0, xer);
	// beq 0x826caf0c
	if (cr0.eq) goto loc_826CAF0C;
	// lwz r11,3144(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826caf0c
	if (!cr6.eq) goto loc_826CAF0C;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// li r27,-1
	r27.s64 = -1;
	// addi r4,r10,-9136
	ctx.r4.s64 = ctx.r10.s64 + -9136;
	// addi r28,r11,1
	r28.s64 = r11.s64 + 1;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x826CADB4;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cae24
	if (cr6.eq) goto loc_826CAE24;
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826cae24
	if (cr6.eq) goto loc_826CAE24;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// addi r4,r11,2516
	ctx.r4.s64 = r11.s64 + 2516;
	// bl 0x8220eea8
	ctx.lr = 0x826CADD8;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cae24
	if (cr6.eq) goto loc_826CAE24;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r3,92
	ctx.r10.s64 = ctx.r3.s64 + 92;
	// addi r11,r11,-4180
	r11.s64 = r11.s64 + -4180;
loc_826CADEC:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826cae10
	if (cr6.eq) goto loc_826CAE10;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826cadec
	if (cr6.eq) goto loc_826CADEC;
loc_826CAE10:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826cae24
	if (!cr6.eq) goto loc_826CAE24;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826c8818
	ctx.lr = 0x826CAE24;
	sub_826C8818(ctx, base);
loc_826CAE24:
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826cae8c
	if (!cr6.gt) goto loc_826CAE8C;
	// addi r30,r29,172
	r30.s64 = r29.s64 + 172;
loc_826CAE38:
	// lwz r11,-156(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + -156);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826cae64
	if (!cr6.eq) goto loc_826CAE64;
	// lwz r3,-164(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + -164);
	// bl 0x822a8a88
	ctx.lr = 0x826CAE4C;
	sub_822A8A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cae64
	if (cr6.eq) goto loc_826CAE64;
	// mr r4,r29
	ctx.r4.u64 = r29.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826c8818
	ctx.lr = 0x826CAE64;
	sub_826C8818(ctx, base);
loc_826CAE64:
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// cmpw cr6,r11,r28
	cr6.compare<int32_t>(r11.s32, r28.s32, xer);
	// bge cr6,0x826cae78
	if (!cr6.lt) goto loc_826CAE78;
	// mr r27,r31
	r27.u64 = r31.u64;
	// mr r28,r11
	r28.u64 = r11.u64;
loc_826CAE78:
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// addi r30,r30,192
	r30.s64 = r30.s64 + 192;
	// cmpw cr6,r31,r11
	cr6.compare<int32_t>(r31.s32, r11.s32, xer);
	// blt cr6,0x826cae38
	if (cr6.lt) goto loc_826CAE38;
loc_826CAE8C:
	// lwz r11,3080(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 3080);
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// cmpw cr6,r28,r11
	cr6.compare<int32_t>(r28.s32, r11.s32, xer);
	// beq cr6,0x826caee0
	if (cr6.eq) goto loc_826CAEE0;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// addi r6,r11,-4752
	ctx.r6.s64 = r11.s64 + -4752;
	// addi r5,r10,-12204
	ctx.r5.s64 = ctx.r10.s64 + -12204;
	// mr r7,r27
	ctx.r7.u64 = r27.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82137a08
	ctx.lr = 0x826CAEBC;
	sub_82137A08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r25
	ctx.r3.u64 = r25.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CAECC;
	sub_8268DA78(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r9,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
loc_826CAEE0:
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826c9358
	ctx.lr = 0x826CAEEC;
	sub_826C9358(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826ca568
	ctx.lr = 0x826CAEFC;
	sub_826CA568(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = r29.u64;
	// mr r4,r25
	ctx.r4.u64 = r25.u64;
	// mr r3,r26
	ctx.r3.u64 = r26.u64;
	// bl 0x826c9f88
	ctx.lr = 0x826CAF0C;
	sub_826C9F88(ctx, base);
loc_826CAF0C:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x823d9238
	return;
}

PPC_WEAK_FUNC(sub_826CAD48) {
	__imp__sub_826CAD48(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CAF14) {
	__imp__sub_826CAF14(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CAF18) {
	PPC_FUNC_PROLOGUE();
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
	uint32_t ea{};
	// mflr r12
	r12.u64 = ctx.lr;
	// bl 0x823d91dc
	ctx.lr = 0x826CAF20;
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32247
	r11.s64 = -2113339392;
	// mr r22,r3
	r22.u64 = ctx.r3.u64;
	// addi r3,r11,5616
	ctx.r3.s64 = r11.s64 + 5616;
	// bl 0x821fa230
	ctx.lr = 0x826CAF34;
	sub_821FA230(ctx, base);
	// mr r23,r3
	r23.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x826CAF3C;
	sub_82256058(ctx, base);
	// mr r21,r3
	r21.u64 = ctx.r3.u64;
	// cmplwi cr6,r23,0
	cr6.compare<uint32_t>(r23.u32, 0, xer);
	// beq cr6,0x826cb0e8
	if (cr6.eq) goto loc_826CB0E8;
	// cmplwi cr6,r21,0
	cr6.compare<uint32_t>(r21.u32, 0, xer);
	// beq cr6,0x826cb0e8
	if (cr6.eq) goto loc_826CB0E8;
	// addic. r24,r21,8
	xer.ca = r21.u32 > 4294967287;
	r24.s64 = r21.s64 + 8;
	cr0.compare<int32_t>(r24.s32, 0, xer);
	// beq 0x826cb0e8
	if (cr0.eq) goto loc_826CB0E8;
	// lwz r11,3144(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 3144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826cb0e8
	if (!cr6.eq) goto loc_826CB0E8;
	// lis r31,-32111
	r31.s64 = -2104426496;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// addi r4,r11,-9136
	ctx.r4.s64 = r11.s64 + -9136;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// bl 0x8220eea8
	ctx.lr = 0x826CAF78;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cafe8
	if (cr6.eq) goto loc_826CAFE8;
	// lwz r11,88(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 88);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// beq cr6,0x826cafe8
	if (cr6.eq) goto loc_826CAFE8;
	// lis r11,-32246
	r11.s64 = -2113273856;
	// lwz r3,-24180(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + -24180);
	// addi r4,r11,2516
	ctx.r4.s64 = r11.s64 + 2516;
	// bl 0x8220eea8
	ctx.lr = 0x826CAF9C;
	sub_8220EEA8(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cafe8
	if (cr6.eq) goto loc_826CAFE8;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// addi r10,r3,92
	ctx.r10.s64 = ctx.r3.s64 + 92;
	// addi r11,r11,-4180
	r11.s64 = r11.s64 + -4180;
loc_826CAFB0:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(r11.u32 + 0);
	// lbz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// subf r9,r8,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r8.s64;
	// beq cr6,0x826cafd4
	if (cr6.eq) goto loc_826CAFD4;
	// addi r11,r11,1
	r11.s64 = r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// beq cr6,0x826cafb0
	if (cr6.eq) goto loc_826CAFB0;
loc_826CAFD4:
	// cmpwi cr6,r9,0
	cr6.compare<int32_t>(ctx.r9.s32, 0, xer);
	// bne cr6,0x826cafe8
	if (!cr6.eq) goto loc_826CAFE8;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826c8818
	ctx.lr = 0x826CAFE8;
	sub_826C8818(ctx, base);
loc_826CAFE8:
	// lwz r11,3080(r24)
	r11.u64 = PPC_LOAD_U32(r24.u32 + 3080);
	// li r31,0
	r31.s64 = 0;
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// ble cr6,0x826cb0bc
	if (!cr6.gt) goto loc_826CB0BC;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// lis r10,-32244
	ctx.r10.s64 = -2113142784;
	// addi r29,r24,8
	r29.s64 = r24.s64 + 8;
	// lis r26,-32121
	r26.s64 = -2105081856;
	// li r25,1
	r25.s64 = 1;
	// addi r28,r11,-12204
	r28.s64 = r11.s64 + -12204;
	// addi r27,r10,-4740
	r27.s64 = ctx.r10.s64 + -4740;
loc_826CB014:
	// lwz r11,8(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 8);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826cb040
	if (!cr6.eq) goto loc_826CB040;
	// lwz r3,0(r29)
	ctx.r3.u64 = PPC_LOAD_U32(r29.u32 + 0);
	// bl 0x822a8a88
	ctx.lr = 0x826CB028;
	sub_822A8A88(ctx, base);
	// clrlwi r11,r3,24
	r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beq cr6,0x826cb040
	if (cr6.eq) goto loc_826CB040;
	// mr r4,r24
	ctx.r4.u64 = r24.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826c8818
	ctx.lr = 0x826CB040;
	sub_826C8818(ctx, base);
loc_826CB040:
	// lwz r11,164(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 164);
	// addic. r11,r11,-1
	xer.ca = r11.u32 > 0;
	r11.s64 = r11.s64 + -1;
	cr0.compare<int32_t>(r11.s32, 0, xer);
	// bge 0x826cb054
	if (!cr0.lt) goto loc_826CB054;
	// li r11,0
	r11.s64 = 0;
	// b 0x826cb060
	goto loc_826CB060;
loc_826CB054:
	// cmpwi cr6,r11,16
	cr6.compare<int32_t>(r11.s32, 16, xer);
	// ble cr6,0x826cb060
	if (!cr6.gt) goto loc_826CB060;
	// li r11,16
	r11.s64 = 16;
loc_826CB060:
	// addi r10,r11,93
	ctx.r10.s64 = r11.s64 + 93;
	// lwz r11,-10020(r26)
	r11.u64 = PPC_LOAD_U32(r26.u32 + -10020);
	// mr r6,r27
	ctx.r6.u64 = r27.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r5,r28
	ctx.r5.u64 = r28.u64;
	// mr r7,r31
	ctx.r7.u64 = r31.u64;
	// li r4,16
	ctx.r4.s64 = 16;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r30,r9,r11
	r30.u64 = PPC_LOAD_U32(ctx.r9.u32 + r11.u32);
	// bl 0x82137a08
	ctx.lr = 0x826CB088;
	sub_82137A08(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r23
	ctx.r3.u64 = r23.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CB098;
	sub_8268DA78(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r31,r31,1
	r31.s64 = r31.s64 + 1;
	// stw r25,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, r25.u32);
	// add r8,r11,r30
	ctx.r8.u64 = r11.u64 + r30.u64;
	// addi r29,r29,192
	r29.s64 = r29.s64 + 192;
	// stw r8,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// lwz r7,3080(r24)
	ctx.r7.u64 = PPC_LOAD_U32(r24.u32 + 3080);
	// cmpw cr6,r31,r7
	cr6.compare<int32_t>(r31.s32, ctx.r7.s32, xer);
	// blt cr6,0x826cb014
	if (cr6.lt) goto loc_826CB014;
loc_826CB0BC:
	// mr r4,r21
	ctx.r4.u64 = r21.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826c9358
	ctx.lr = 0x826CB0C8;
	sub_826C9358(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826ca6d8
	ctx.lr = 0x826CB0D8;
	sub_826CA6D8(ctx, base);
	// mr r5,r24
	ctx.r5.u64 = r24.u64;
	// mr r4,r23
	ctx.r4.u64 = r23.u64;
	// mr r3,r22
	ctx.r3.u64 = r22.u64;
	// bl 0x826ca1e8
	ctx.lr = 0x826CB0E8;
	sub_826CA1E8(ctx, base);
loc_826CB0E8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x823d922c
	return;
}

PPC_WEAK_FUNC(sub_826CAF18) {
	__imp__sub_826CAF18(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB0F0) {
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
	ctx.lr = 0x826CB0F8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32253
	r11.s64 = -2113732608;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r11,764
	ctx.r3.s64 = r11.s64 + 764;
	// bl 0x821fa230
	ctx.lr = 0x826CB10C;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x826CB114;
	sub_82256058(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826cb148
	if (cr6.eq) goto loc_826CB148;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cb148
	if (cr6.eq) goto loc_826CB148;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826ca8e0
	ctx.lr = 0x826CB138;
	sub_826CA8E0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c8df8
	ctx.lr = 0x826CB148;
	sub_826C8DF8(ctx, base);
loc_826CB148:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CB0F0) {
	__imp__sub_826CB0F0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB150) {
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
	ctx.lr = 0x826CB158;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32254
	r11.s64 = -2113798144;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r11,-12140
	ctx.r3.s64 = r11.s64 + -12140;
	// bl 0x821fa230
	ctx.lr = 0x826CB16C;
	sub_821FA230(ctx, base);
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x826CB174;
	sub_82256058(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	cr6.compare<uint32_t>(r31.u32, 0, xer);
	// beq cr6,0x826cb1a8
	if (cr6.eq) goto loc_826CB1A8;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cb1a8
	if (cr6.eq) goto loc_826CB1A8;
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826ca9d8
	ctx.lr = 0x826CB198;
	sub_826CA9D8(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = r30.u64;
	// mr r4,r31
	ctx.r4.u64 = r31.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c8ed0
	ctx.lr = 0x826CB1A8;
	sub_826C8ED0(ctx, base);
loc_826CB1A8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CB150) {
	__imp__sub_826CB150(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB1B0) {
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
	ctx.lr = 0x826CB1B8;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32245
	r11.s64 = -2113208320;
	// mr r29,r3
	r29.u64 = ctx.r3.u64;
	// addi r3,r11,-29360
	ctx.r3.s64 = r11.s64 + -29360;
	// bl 0x821fa230
	ctx.lr = 0x826CB1CC;
	sub_821FA230(ctx, base);
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// bl 0x82256058
	ctx.lr = 0x826CB1D4;
	sub_82256058(ctx, base);
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cb254
	if (cr6.eq) goto loc_826CB254;
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cb254
	if (cr6.eq) goto loc_826CB254;
	// addic. r31,r3,8
	xer.ca = ctx.r3.u32 > 4294967287;
	r31.s64 = ctx.r3.s64 + 8;
	cr0.compare<int32_t>(r31.s32, 0, xer);
	// beq 0x826cb234
	if (cr0.eq) goto loc_826CB234;
	// lwz r11,3144(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 3144);
	// cmpwi cr6,r11,0
	cr6.compare<int32_t>(r11.s32, 0, xer);
	// bne cr6,0x826cb234
	if (!cr6.eq) goto loc_826CB234;
	// lis r11,32767
	r11.s64 = 2147418112;
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(r31.u32 + 40);
	// ori r9,r11,65535
	ctx.r9.u64 = r11.u64 | 65535;
	// cmpw cr6,r10,r9
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, xer);
	// beq cr6,0x826cb234
	if (cr6.eq) goto loc_826CB234;
	// lis r11,-32244
	r11.s64 = -2113142784;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r11,-17032
	ctx.r4.s64 = r11.s64 + -17032;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x8268da78
	ctx.lr = 0x826CB220;
	sub_8268DA78(ctx, base);
	// lwz r11,4(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,1
	ctx.r9.s64 = r11.s64 + 1;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// stw r9,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
loc_826CB234:
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826caae0
	ctx.lr = 0x826CB244;
	sub_826CAAE0(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r4,r30
	ctx.r4.u64 = r30.u64;
	// mr r3,r29
	ctx.r3.u64 = r29.u64;
	// bl 0x826c90b8
	ctx.lr = 0x826CB254;
	sub_826C90B8(ctx, base);
loc_826CB254:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CB1B0) {
	__imp__sub_826CB1B0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB25C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB25C) {
	__imp__sub_826CB25C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB260) {
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
	ctx.lr = 0x826CB268;
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r5
	r31.u64 = ctx.r5.u64;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// mr r29,r4
	r29.u64 = ctx.r4.u64;
	// lhz r11,2(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 2);
	// extsh r11,r11
	r11.s64 = r11.s16;
	// cmplwi cr6,r11,10
	cr6.compare<uint32_t>(r11.u32, 10, xer);
	// bgt cr6,0x826cb460
	if (cr6.gt) goto loc_826CB460;
	// lis r12,-32147
	r12.s64 = -2106785792;
	// addi r12,r12,-19808
	r12.s64 = r12.s64 + -19808;
	// rlwinm r0,r11,2,0,29
	r0.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	r0.u64 = PPC_LOAD_U32(r12.u32 + r0.u32);
	// mtctr r0
	ctr.u64 = r0.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	return;
	// lwz r19,-19764(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19764);
	// lwz r19,-19712(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19712);
	// lwz r19,-19692(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19692);
	// lwz r19,-19672(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19672);
	// lwz r19,-19652(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19652);
	// lwz r19,-19632(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19632);
	// lwz r19,-19612(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19612);
	// lwz r19,-19528(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19528);
	// lwz r19,-19452(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19452);
	// lwz r19,-19372(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19372);
	// lwz r19,-19404(r12)
	r19.u64 = PPC_LOAD_U32(r12.u32 + -19404);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826CB2D8;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r8,r10
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// bl 0x826cac98
	ctx.lr = 0x826CB2F4;
	sub_826CAC98(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cad48
	ctx.lr = 0x826CB308;
	sub_826CAD48(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826caf18
	ctx.lr = 0x826CB31C;
	sub_826CAF18(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cb0f0
	ctx.lr = 0x826CB330;
	sub_826CB0F0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cb150
	ctx.lr = 0x826CB344;
	sub_826CB150(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// bl 0x826cb1b0
	ctx.lr = 0x826CB358;
	sub_826CB1B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826CB370;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// lwz r10,76(r29)
	ctx.r10.u64 = PPC_LOAD_U32(r29.u32 + 76);
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
	ctx.lr = 0x826CB390;
	sub_8268C9F0(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r6,76(r29)
	ctx.r6.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r4,4(r7)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r11,r4,2,0,29
	r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r6
	ctx.r4.u64 = PPC_LOAD_U32(r11.u32 + ctx.r6.u32);
	// bl 0x826cab98
	ctx.lr = 0x826CB3B0;
	sub_826CAB98(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826CB3C4;
	sub_8268C9F0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r31,4(r11)
	r31.u64 = PPC_LOAD_U32(r11.u32 + 4);
	// bl 0x8268c9f0
	ctx.lr = 0x826CB3D8;
	sub_8268C9F0(ctx, base);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,76(r29)
	ctx.r9.u64 = PPC_LOAD_U32(r29.u32 + 76);
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r8,4(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r7,r9
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// bl 0x826cac48
	ctx.lr = 0x826CB3F8;
	sub_826CAC48(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826CB410;
	sub_8268C9F0(ctx, base);
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lbz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// ori r8,r10,27786
	ctx.r8.u64 = ctx.r10.u64 | 27786;
	// lwz r11,-10020(r11)
	r11.u64 = PPC_LOAD_U32(r11.u32 + -10020);
	// stbx r9,r11,r8
	PPC_STORE_U8(r11.u32 + ctx.r8.u32, ctx.r9.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x8268c9f0
	ctx.lr = 0x826CB440;
	sub_8268C9F0(ctx, base);
	// lbz r11,4(r3)
	r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// stb r11,16(r30)
	PPC_STORE_U8(r30.u32 + 16, r11.u8);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
	// lis r11,-32121
	r11.s64 = -2105081856;
	// lwz r3,-10004(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10004);
	// bl 0x826c4520
	ctx.lr = 0x826CB460;
	sub_826C4520(ctx, base);
loc_826CB460:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x823d924c
	return;
}

PPC_WEAK_FUNC(sub_826CB260) {
	__imp__sub_826CB260(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB46C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB46C) {
	__imp__sub_826CB46C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB470) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cb4a0
	if (cr6.eq) goto loc_826CB4A0;
	// bl 0x822a8108
	ctx.lr = 0x826CB48C;
	sub_822A8108(ctx, base);
	// addi r3,r3,48
	ctx.r3.s64 = ctx.r3.s64 + 48;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826CB4A0:
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

PPC_WEAK_FUNC(sub_826CB470) {
	__imp__sub_826CB470(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB4B4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB4B4) {
	__imp__sub_826CB4B4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB4B8) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addi r3,r11,336
	ctx.r3.s64 = r11.s64 + 336;
	// bnelr cr6
	if (!cr6.eq) return;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CB4B8) {
	__imp__sub_826CB4B8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB4D0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	PPCRegister r12{};
	PPCRegister r30{};
	PPCRegister r31{};
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// lwz r3,16(r31)
	ctx.r3.u64 = PPC_LOAD_U32(r31.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cb518
	if (cr6.eq) goto loc_826CB518;
	// bl 0x822a8108
	ctx.lr = 0x826CB4FC;
	sub_822A8108(ctx, base);
	// li r11,48
	r11.s64 = 48;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r30
	simde_mm_store_si128((simde__m128i*)(base + ((r30.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U8(r31.u32 + 8);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// b 0x826cb51c
	goto loc_826CB51C;
loc_826CB518:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826CB51C:
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

PPC_WEAK_FUNC(sub_826CB4D0) {
	__imp__sub_826CB4D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB534) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB534) {
	__imp__sub_826CB534(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB538) {
	PPC_FUNC_PROLOGUE();
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
	// lwz r3,16(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 16);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cb5a0
	if (cr6.eq) goto loc_826CB5A0;
	// bl 0x822a8108
	ctx.lr = 0x826CB564;
	sub_822A8108(ctx, base);
	// li r9,16
	ctx.r9.s64 = 16;
	// lvx128 v63,r0,r3
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,32
	ctx.r10.s64 = 32;
	// stvx128 v63,r0,r31
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,48
	r11.s64 = 48;
	// lvx128 v62,r3,r9
	simde_mm_store_si128((simde__m128i*)v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r9
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r9.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r3,r10
	simde_mm_store_si128((simde__m128i*)v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r31,r10
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r3,r11
	simde_mm_store_si128((simde__m128i*)v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r31,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r31.u32 + r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r11,8(r30)
	r11.u64 = PPC_LOAD_U8(r30.u32 + 8);
	// cntlzw r10,r11
	ctx.r10.u64 = r11.u32 == 0 ? 32 : __builtin_clz(r11.u32);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x826cb5a4
	goto loc_826CB5A4;
loc_826CB5A0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_826CB5A4:
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

PPC_WEAK_FUNC(sub_826CB538) {
	__imp__sub_826CB538(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB5BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB5BC) {
	__imp__sub_826CB5BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB5C0) {
	PPC_FUNC_PROLOGUE();
	PPCXERRegister xer{};
	PPCCRRegister cr6{};
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// beqlr cr6
	if (cr6.eq) return;
	// stb r4,466(r11)
	PPC_STORE_U8(r11.u32 + 466, ctx.r4.u8);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CB5C0) {
	__imp__sub_826CB5C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB5D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB5D4) {
	__imp__sub_826CB5D4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB5D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	// lwz r11,16(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r3,140(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 140);
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CB5D8) {
	__imp__sub_826CB5D8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB5E4) {
	__imp__sub_826CB5E4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB5E8) {
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
	// addi r10,r11,-4372
	ctx.r10.s64 = r11.s64 + -4372;
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// bl 0x821d2028
	ctx.lr = 0x826CB614;
	sub_821D2028(ctx, base);
	// clrlwi r9,r30,31
	ctx.r9.u64 = r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// cmplwi cr6,r9,0
	cr6.compare<uint32_t>(ctx.r9.u32, 0, xer);
	// beq cr6,0x826cb62c
	if (cr6.eq) goto loc_826CB62C;
	// bl 0x82130588
	ctx.lr = 0x826CB628;
	sub_82130588(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
loc_826CB62C:
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

PPC_WEAK_FUNC(sub_826CB5E8) {
	__imp__sub_826CB5E8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB644) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB644) {
	__imp__sub_826CB644(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB648) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// li r11,16
	r11.s64 = 16;
	// lvx128 v63,r3,r11
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + r11.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r3,r9,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CB648) {
	__imp__sub_826CB648(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB664) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB664) {
	__imp__sub_826CB664(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB668) {
	PPC_FUNC_PROLOGUE();
	PPCRegister r11{};
	PPCVRegister v63{};
	// lis r11,-32130
	r11.s64 = -2105671680;
	// li r9,16
	ctx.r9.s64 = 16;
	// addi r8,r11,-31280
	ctx.r8.s64 = r11.s64 + -31280;
	// li r10,16
	ctx.r10.s64 = 16;
	// li r7,32
	ctx.r7.s64 = 32;
	// li r6,32
	ctx.r6.s64 = 32;
	// li r5,48
	ctx.r5.s64 = 48;
	// lvx128 v63,r0,r8
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r4,48
	r11.s64 = ctx.r4.s64 + 48;
	// stvx128 v63,r0,r4
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r8,r9
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r9.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r4,r10
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r10.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r8,r7
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r7.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r4,r6
	simde_mm_store_si128((simde__m128i*)(base + ((ctx.r4.u32 + ctx.r6.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r8,r5
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r8.u32 + ctx.r5.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r3,r10
	simde_mm_store_si128((simde__m128i*)v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)(base + ((ctx.r3.u32 + ctx.r10.u32) & ~0xF))), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	simde_mm_store_si128((simde__m128i*)(base + ((r11.u32) & ~0xF)), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r3.u32 + 8);
	// cntlzw r3,r4
	ctx.r3.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// rlwinm r3,r3,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 27) & 0x1;
	// blr 
	return;
}

PPC_WEAK_FUNC(sub_826CB668) {
	__imp__sub_826CB668(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB6C0) {
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
	// beq cr6,0x826cb72c
	if (cr6.eq) goto loc_826CB72C;
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
	// beq cr6,0x826cb72c
	if (cr6.eq) goto loc_826CB72C;
loc_826CB70C:
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r8,0(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r10,r8
	cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, xer);
	// beq cr6,0x826cb744
	if (cr6.eq) goto loc_826CB744;
	// lwz r8,8(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// addi r11,r9,8
	r11.s64 = ctx.r9.s64 + 8;
	// cmplwi cr6,r8,0
	cr6.compare<uint32_t>(ctx.r8.u32, 0, xer);
	// bne cr6,0x826cb70c
	if (!cr6.eq) goto loc_826CB70C;
loc_826CB72C:
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
loc_826CB744:
	// lwz r3,0(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// lwz r10,8(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// stw r10,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r10.u32);
	// bl 0x82130588
	ctx.lr = 0x826CB754;
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

PPC_WEAK_FUNC(sub_826CB6C0) {
	__imp__sub_826CB6C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB77C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB77C) {
	__imp__sub_826CB77C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB780) {
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
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// bl 0x826bde70
	ctx.lr = 0x826CB79C;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cb7b8
	if (cr6.eq) goto loc_826CB7B8;
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = r12.u64;
	// blr 
	return;
loc_826CB7B8:
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

PPC_WEAK_FUNC(sub_826CB780) {
	__imp__sub_826CB780(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB7CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB7CC) {
	__imp__sub_826CB7CC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB7D0) {
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
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,20
	ctx.r9.s64 = 20;
	// clrlwi r11,r4,16
	r11.u64 = ctx.r4.u32 & 0xFFFF;
	// sth r4,4(r31)
	PPC_STORE_U16(r31.u32 + 4, ctx.r4.u16);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// stw r10,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r10.u32);
	// sth r10,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r10.u16);
	// stw r9,8(r31)
	PPC_STORE_U32(r31.u32 + 8, ctx.r9.u32);
	// stw r10,12(r31)
	PPC_STORE_U32(r31.u32 + 12, ctx.r10.u32);
	// stb r10,16(r31)
	PPC_STORE_U8(r31.u32 + 16, ctx.r10.u8);
	// beq cr6,0x826cb824
	if (cr6.eq) goto loc_826CB824;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r10
	r11.u64 = r11.u64 + ctx.r10.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(r11.u32 | (r11.u64 << 32), 2) & 0xFFFFFFFC;
	// bl 0x82130528
	ctx.lr = 0x826CB820;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826CB824:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x826CB834;
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

PPC_WEAK_FUNC(sub_826CB7D0) {
	__imp__sub_826CB7D0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB84C) {
	__imp__sub_826CB84C(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB850) {
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
	// mr r30,r4
	r30.u64 = ctx.r4.u64;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r30,0
	cr6.compare<uint32_t>(r30.u32, 0, xer);
	// beq cr6,0x826cb8a4
	if (cr6.eq) goto loc_826CB8A4;
	// lwz r11,0(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// mtctr r10
	ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826CB88C;
	PPC_CALL_INDIRECT_FUNC(ctr.u32);
	// lwz r9,12(r31)
	ctx.r9.u64 = PPC_LOAD_U32(r31.u32 + 12);
	// stw r9,0(r30)
	PPC_STORE_U32(r30.u32 + 0, ctx.r9.u32);
	// lhz r11,6(r31)
	r11.u64 = PPC_LOAD_U16(r31.u32 + 6);
	// addi r8,r11,1
	ctx.r8.s64 = r11.s64 + 1;
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// sth r8,6(r31)
	PPC_STORE_U16(r31.u32 + 6, ctx.r8.u16);
loc_826CB8A4:
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

PPC_WEAK_FUNC(sub_826CB850) {
	__imp__sub_826CB850(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB8BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB8BC) {
	__imp__sub_826CB8BC(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB8C0) {
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
	// li r9,32
	ctx.r9.s64 = 32;
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
	// beq cr6,0x826cb90c
	if (cr6.eq) goto loc_826CB90C;
	// rlwinm r3,r10,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// bl 0x82130528
	ctx.lr = 0x826CB908;
	sub_82130528(ctx, base);
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
loc_826CB90C:
	// li r11,1
	r11.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// stb r11,16(r31)
	PPC_STORE_U8(r31.u32 + 16, r11.u8);
	// bl 0x821f10e0
	ctx.lr = 0x826CB91C;
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

PPC_WEAK_FUNC(sub_826CB8C0) {
	__imp__sub_826CB8C0(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB934) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB934) {
	__imp__sub_826CB934(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB938) {
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
	// li r30,0
	r30.s64 = 0;
	// li r3,20
	ctx.r3.s64 = 20;
	// sth r30,18(r31)
	PPC_STORE_U16(r31.u32 + 18, r30.u16);
	// sth r30,16(r31)
	PPC_STORE_U16(r31.u32 + 16, r30.u16);
	// stw r30,12(r31)
	PPC_STORE_U32(r31.u32 + 12, r30.u32);
	// stb r30,23(r31)
	PPC_STORE_U8(r31.u32 + 23, r30.u8);
	// stw r30,24(r31)
	PPC_STORE_U32(r31.u32 + 24, r30.u32);
	// bl 0x82130528
	ctx.lr = 0x826CB970;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cb984
	if (cr6.eq) goto loc_826CB984;
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x826cb7d0
	ctx.lr = 0x826CB980;
	sub_826CB7D0(ctx, base);
	// b 0x826cb988
	goto loc_826CB988;
loc_826CB984:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826CB988:
	// stw r3,0(r31)
	PPC_STORE_U32(r31.u32 + 0, ctx.r3.u32);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826CB994;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cb9a8
	if (cr6.eq) goto loc_826CB9A8;
	// li r4,116
	ctx.r4.s64 = 116;
	// bl 0x826cb7d0
	ctx.lr = 0x826CB9A4;
	sub_826CB7D0(ctx, base);
	// b 0x826cb9ac
	goto loc_826CB9AC;
loc_826CB9A8:
	// mr r3,r30
	ctx.r3.u64 = r30.u64;
loc_826CB9AC:
	// stw r3,4(r31)
	PPC_STORE_U32(r31.u32 + 4, ctx.r3.u32);
	// li r3,20
	ctx.r3.s64 = 20;
	// bl 0x82130528
	ctx.lr = 0x826CB9B8;
	sub_82130528(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cb9d0
	if (cr6.eq) goto loc_826CB9D0;
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x826cb8c0
	ctx.lr = 0x826CB9C8;
	sub_826CB8C0(ctx, base);
	// mr r11,r3
	r11.u64 = ctx.r3.u64;
	// b 0x826cb9d4
	goto loc_826CB9D4;
loc_826CB9D0:
	// mr r11,r30
	r11.u64 = r30.u64;
loc_826CB9D4:
	// stw r11,8(r31)
	PPC_STORE_U32(r31.u32 + 8, r11.u32);
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

PPC_WEAK_FUNC(sub_826CB938) {
	__imp__sub_826CB938(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB9F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CB9F4) {
	__imp__sub_826CB9F4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CB9F8) {
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
	// mr r31,r4
	r31.u64 = ctx.r4.u64;
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// mr r5,r31
	ctx.r5.u64 = r31.u64;
	// addi r4,r10,-20072
	ctx.r4.s64 = ctx.r10.s64 + -20072;
	// mr r30,r3
	r30.u64 = ctx.r3.u64;
	// lwz r3,-10224(r11)
	ctx.r3.u64 = PPC_LOAD_U32(r11.u32 + -10224);
	// bl 0x8268b770
	ctx.lr = 0x826CBA2C;
	sub_8268B770(ctx, base);
	// lwz r11,4(r31)
	r11.u64 = PPC_LOAD_U32(r31.u32 + 4);
	// cmplwi cr6,r11,1
	cr6.compare<uint32_t>(r11.u32, 1, xer);
	// blt cr6,0x826cbab0
	if (cr6.lt) goto loc_826CBAB0;
	// beq cr6,0x826cba74
	if (cr6.eq) goto loc_826CBA74;
	// cmplwi cr6,r11,3
	cr6.compare<uint32_t>(r11.u32, 3, xer);
	// bge cr6,0x826cbadc
	if (!cr6.lt) goto loc_826CBADC;
	// lis r11,-32125
	r11.s64 = -2105344000;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r6,r11,-24712
	ctx.r6.s64 = r11.s64 + -24712;
	// addi r5,r10,23928
	ctx.r5.s64 = ctx.r10.s64 + 23928;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x826CBA64;
	sub_823DEDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,8(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 8);
	// bl 0x826cb850
	ctx.lr = 0x826CBA70;
	sub_826CB850(ctx, base);
	// b 0x826cbadc
	goto loc_826CBADC;
loc_826CBA74:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r6,r11,23956
	ctx.r6.s64 = r11.s64 + 23956;
	// addi r5,r10,23928
	ctx.r5.s64 = ctx.r10.s64 + 23928;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x826CBA94;
	sub_823DEDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 4);
	// bl 0x826cb850
	ctx.lr = 0x826CBAA0;
	sub_826CB850(ctx, base);
	// lwz r11,24(r30)
	r11.u64 = PPC_LOAD_U32(r30.u32 + 24);
	// addi r9,r11,-1
	ctx.r9.s64 = r11.s64 + -1;
	// stw r9,24(r30)
	PPC_STORE_U32(r30.u32 + 24, ctx.r9.u32);
	// b 0x826cbadc
	goto loc_826CBADC;
loc_826CBAB0:
	// lis r11,-32126
	r11.s64 = -2105409536;
	// lis r10,-32126
	ctx.r10.s64 = -2105409536;
	// addi r6,r11,23896
	ctx.r6.s64 = r11.s64 + 23896;
	// addi r5,r10,23928
	ctx.r5.s64 = ctx.r10.s64 + 23928;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = r31.u64;
	// bl 0x823dedd8
	ctx.lr = 0x826CBAD0;
	sub_823DEDD8(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,0(r30)
	ctx.r3.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// bl 0x826cb850
	ctx.lr = 0x826CBADC;
	sub_826CB850(ctx, base);
loc_826CBADC:
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

PPC_WEAK_FUNC(sub_826CB9F8) {
	__imp__sub_826CB9F8(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBAF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

PPC_WEAK_FUNC(sub_826CBAF4) {
	__imp__sub_826CBAF4(ctx, base);
}

PPC_FUNC_IMPL(__imp__sub_826CBAF8) {
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
	ctx.lr = 0x826CBB00;
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	r31.u64 = ctx.r3.u64;
	// lis r29,-32112
	r29.s64 = -2104492032;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r31.u32);
	// mr r28,r4
	r28.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r30,24996(r29)
	r30.u64 = PPC_LOAD_U32(r29.u32 + 24996);
	// addi r3,r30,12
	ctx.r3.s64 = r30.s64 + 12;
	// bl 0x826bde70
	ctx.lr = 0x826CBB24;
	sub_826BDE70(ctx, base);
	// cmplwi cr6,r3,0
	cr6.compare<uint32_t>(ctx.r3.u32, 0, xer);
	// beq cr6,0x826cbb38
	if (cr6.eq) goto loc_826CBB38;
	// lwz r11,0(r3)
	r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// bne cr6,0x826cbbb4
	if (!cr6.eq) goto loc_826CBBB4;
loc_826CBB38:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(r30.u32 + 0);
	// lwz r11,12(r10)
	r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// cmplwi cr6,r11,0
	cr6.compare<uint32_t>(r11.u32, 0, xer);
	// addis r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 65536;
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(r11.u32 + 0);
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// sth r8,6(r10)
	PPC_STORE_U16(ctx.r10.u32 + 6, ctx.r8.u16);
	// stw r7,12(r10)
	PPC_STORE_U32(ctx.r10.u32 + 12, ctx.r7.u32);
	// beq cr6,0x826cbb8c
	if (cr6.eq) goto loc_826CBB8C;
	// lis r8,-32244
	ctx.r8.s64 = -2113142784;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r7,r8,-4348
	ctx.r7.s64 = ctx.r8.s64 + -4348;
	// stw r10,4(r11)
	PPC_STORE_U32(r11.u32 + 4, ctx.r10.u32);
	// stb r9,8(r11)
	PPC_STORE_U8(r11.u32 + 8, ctx.r9.u8);
	// stw r7,0(r11)
	PPC_STORE_U32(r11.u32 + 0, ctx.r7.u32);
	// stb r9,9(r11)
	PPC_STORE_U8(r11.u32 + 9, ctx.r9.u8);
	// stw r10,12(r11)
	PPC_STORE_U32(r11.u32 + 12, ctx.r10.u32);
	// stw r10,16(r11)
	PPC_STORE_U32(r11.u32 + 16, ctx.r10.u32);
	// b 0x826cbb90
	goto loc_826CBB90;
loc_826CBB8C:
	// li r11,0
	r11.s64 = 0;
loc_826CBB90:
	// stw r28,16(r11)
	PPC_STORE_U32(r11.u32 + 16, r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r31,12(r11)
	PPC_STORE_U32(r11.u32 + 12, r31.u32);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, r11.u32);
	// stw r31,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, r31.u32);
	// lwz r11,24996(r29)
	r11.u64 = PPC_LOAD_U32(r29.u32 + 24996);
	// addi r3,r11,12
	ctx.r3.s64 = r11.s64 + 12;
	// bl 0x82389998
	ctx.lr = 0x826CBBB4;
	sub_82389998(ctx, base);
loc_826CBBB4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x823d9248
	return;
}

PPC_WEAK_FUNC(sub_826CBAF8) {
	__imp__sub_826CBAF8(ctx, base);
}

